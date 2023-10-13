#include "sram.h"

#include "global.h"
#include "syssav.h"

static const struct SaveHeader sDummySaveHeader = {
  INTI : 0x20202020,
};

static const u8 sINTI[] = "INTI";

void clear0x02001ee0(void) {
  gSramState.unk_00 = 0;
  *((u16*)&gSramState.status) = 0;
}

void UpdateSram(void) {
  struct SramState* s = &gSramState;
  (gSramRoutine[s->status])(s);
  return;
}

/**
 * @return TRUE: ok, FALSE: broken or none
 */
bool32 CheckSavedataCorrect(u8 saveIdx, s32 length) {
  struct SaveHeader h;
  u16 remaining;

  h = sDummySaveHeader;

  if (saveIdx > SAVE_DATA_NUM) {
    return FALSE;
  }

  for (remaining = SRAM_RETRY_MAX; remaining != 0; remaining--) {
    ReadSram(SRAM_START + (2730 * saveIdx), (u8*)&h, sizeof(struct SaveHeader));
    if ((h.INTI == *(u32*)sINTI) && (h.size == length) && (h.unk_c == 11) && (h.idx == saveIdx)) {
      return TRUE;
    }

    ReadSram(SRAM_START + (2730 * (6 + saveIdx)), (u8*)&h, sizeof(struct SaveHeader));
    if ((h.INTI == *(u32*)sINTI) && (h.size == length) && (h.unk_c == 11) && (h.idx == saveIdx)) {
      return TRUE;
    }
  }

  return FALSE;
}

s32 WriteSramINTI(u8 saveIdx) {
  bool32 ok1, ok2;
  vu32 dummy = 0;

  if (saveIdx > SAVE_DATA_NUM) {
    return -1;
  }
  ok1 = WriteSramEx((const u8*)&dummy, SRAM_START + (2730 * saveIdx), 4);
  ok2 = WriteSramEx((const u8*)&dummy, SRAM_START + (2730 * (saveIdx + 6)), 4);
  return ok1 | ok2;
}

s32 sram_08003330(u8 saveIdx, u8* start, u32 bytesize) {
  if (saveIdx > SLOT_SYSTEM) {
    return -1;
  }
  if (gSramState.unk_00 != 0) {
    return -1;
  }
  if (bytesize > SLOT_SIZE) {
    return -1;
  }
  gSramState.slot = saveIdx;
  gSramState.start = start;
  gSramState.length = bytesize;
  gSramState.unk_1c = 0;
  gSramState.unk_00 = 2;
  *((u16*)&gSramState.status) = 1;
  return 0;
}

s32 sram_08003378(u8 saveIdx, u8* start, u32 bytesize) {
  if (saveIdx > SLOT_SYSTEM) {
    return -1;
  }
  if (gSramState.unk_00 != 0) {
    return -1;
  }
  if (!CheckSavedataCorrect(saveIdx, bytesize)) {
    return -1;
  }
  if (bytesize > SLOT_SIZE) {
    return -1;
  }
  gSramState.slot = saveIdx;
  gSramState.start = start;
  gSramState.length = bytesize;
  gSramState.health = 0;
  gSramState.unk_00 = 1;
  *((u16*)&gSramState.status) = 2;
  return 0;
}

void nop_080033d4(struct SramState* _ UNUSED) { return; }

NAKED void saveSram(struct SramState* s) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #0x10\n\
	adds r4, r0, #0\n\
	movs r5, #0x82\n\
	lsls r5, r5, #4\n\
	ldrb r1, [r4, #3]\n\
	cmp r1, #1\n\
	beq _08003408\n\
	cmp r1, #1\n\
	bgt _080033F2\n\
	cmp r1, #0\n\
	beq _080033FE\n\
	b _08003526\n\
_080033F2:\n\
	cmp r1, #2\n\
	beq _080034A0\n\
	cmp r1, #3\n\
	bne _080033FC\n\
	b _08003500\n\
_080033FC:\n\
	b _08003526\n\
_080033FE:\n\
	movs r0, #3\n\
	strh r0, [r4, #4]\n\
	strh r1, [r4, #6]\n\
	movs r0, #1\n\
	strb r0, [r4, #3]\n\
_08003408:\n\
	ldr r0, [r4, #8]\n\
	str r0, [r4, #0xc]\n\
	ldrh r1, [r4, #6]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	ldrb r1, [r4, #1]\n\
	adds r0, r0, r1\n\
	ldr r1, _08003484 @ =0x00000AAA\n\
	muls r0, r1, r0\n\
	movs r2, #0xe0\n\
	lsls r2, r2, #0x14\n\
	adds r0, r0, r2\n\
	str r0, [r4, #0x10]\n\
	ldr r0, [r4, #0x14]\n\
	str r0, [r4, #0x18]\n\
	adds r5, r0, #0\n\
	ldr r0, _08003488 @ =sINTI\n\
	ldr r0, [r0]\n\
	str r0, [sp]\n\
	movs r0, #0\n\
	str r0, [sp, #4]\n\
	adds r3, r5, #0\n\
	ldrb r6, [r4, #1]\n\
	cmp r5, #0\n\
	beq _08003450\n\
_0800343C:\n\
	ldr r0, [r4, #0xc]\n\
	ldrb r2, [r0]\n\
	ldr r1, [sp, #4]\n\
	adds r1, r1, r2\n\
	str r1, [sp, #4]\n\
	adds r0, #1\n\
	str r0, [r4, #0xc]\n\
	subs r5, #1\n\
	cmp r5, #0\n\
	bne _0800343C\n\
_08003450:\n\
	str r3, [sp, #8]\n\
	mov r1, sp\n\
	movs r0, #0xb\n\
	strb r0, [r1, #0xc]\n\
	movs r0, #6\n\
	strb r0, [r1, #0xd]\n\
	mov r0, sp\n\
	strb r6, [r0, #0xe]\n\
	movs r0, #1\n\
	strb r0, [r1, #0xf]\n\
	ldr r1, [r4, #0x10]\n\
	mov r0, sp\n\
	movs r2, #0x10\n\
	bl WriteSramEx\n\
	cmp r0, #0\n\
	beq _08003490\n\
	ldrh r0, [r4, #4]\n\
	subs r0, #1\n\
	strh r0, [r4, #4]\n\
	ldr r1, _0800348C @ =0x0000FFFF\n\
	adds r2, r1, #0\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _08003526\n\
	b _080034D4\n\
	.align 2, 0\n\
_08003484: .4byte 0x00000AAA\n\
_08003488: .4byte sINTI\n\
_0800348C: .4byte 0x0000FFFF\n\
_08003490:\n\
	ldr r0, [r4, #8]\n\
	str r0, [r4, #0xc]\n\
	ldr r0, [r4, #0x10]\n\
	adds r0, #0x10\n\
	str r0, [r4, #0x10]\n\
	movs r0, #2\n\
	strb r0, [r4, #3]\n\
	b _08003526\n\
_080034A0:\n\
	ldr r0, [r4, #0x18]\n\
	cmp r0, r5\n\
	bhi _080034AC\n\
	adds r5, r0, #0\n\
	movs r0, #3\n\
	strb r0, [r4, #3]\n\
_080034AC:\n\
	ldr r0, [r4, #0xc]\n\
	ldr r1, [r4, #0x10]\n\
	adds r2, r5, #0\n\
	bl WriteSramEx\n\
	cmp r0, #0\n\
	beq _080034E8\n\
	ldrh r0, [r4, #4]\n\
	subs r0, #1\n\
	strh r0, [r4, #4]\n\
	ldr r1, _080034D0 @ =0x0000FFFF\n\
	adds r2, r1, #0\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080034D4\n\
	movs r0, #1\n\
	strb r0, [r4, #3]\n\
	b _08003526\n\
	.align 2, 0\n\
_080034D0: .4byte 0x0000FFFF\n\
_080034D4:\n\
	ldr r0, _080034E4 @ =gSramState\n\
	ldrh r1, [r0, #0x1c]\n\
	orrs r1, r2\n\
	strh r1, [r0, #0x1c]\n\
	movs r0, #3\n\
	strb r0, [r4, #3]\n\
	b _08003526\n\
	.align 2, 0\n\
_080034E4: .4byte gSramState\n\
_080034E8:\n\
	ldr r0, [r4, #0xc]\n\
	movs r1, #0x82\n\
	lsls r1, r1, #4\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0xc]\n\
	ldr r0, [r4, #0x10]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x10]\n\
	ldr r0, [r4, #0x18]\n\
	subs r0, r0, r5\n\
	str r0, [r4, #0x18]\n\
	b _08003526\n\
_08003500:\n\
	ldrh r0, [r4, #6]\n\
	cmp r0, #0\n\
	bne _08003512\n\
	strh r1, [r4, #4]\n\
	movs r1, #1\n\
	movs r0, #1\n\
	strh r0, [r4, #6]\n\
	strb r1, [r4, #3]\n\
	b _08003526\n\
_08003512:\n\
	ldr r1, _08003530 @ =gSramState\n\
	movs r2, #0x1c\n\
	ldrsh r0, [r1, r2]\n\
	cmp r0, #0\n\
	bne _08003520\n\
	movs r0, #1\n\
	strh r0, [r1, #0x1c]\n\
_08003520:\n\
	movs r0, #0\n\
	strb r0, [r4]\n\
	strh r0, [r4, #2]\n\
_08003526:\n\
	add sp, #0x10\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08003530: .4byte gSramState\n\
   .syntax divided\n");
}

NAKED void loadSram(struct SramState* s) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r5, r0, #0\n\
	ldrb r1, [r5, #3]\n\
	cmp r1, #1\n\
	beq _0800355C\n\
	cmp r1, #1\n\
	bgt _08003548\n\
	cmp r1, #0\n\
	beq _08003552\n\
	b _0800368E\n\
_08003548:\n\
	cmp r1, #2\n\
	beq _080035D0\n\
	cmp r1, #3\n\
	beq _08003602\n\
	b _0800368E\n\
_08003552:\n\
	movs r0, #3\n\
	strh r0, [r5, #4]\n\
	strh r1, [r5, #6]\n\
	movs r0, #1\n\
	strb r0, [r5, #3]\n\
_0800355C:\n\
	ldr r0, [r5, #8]\n\
	str r0, [r5, #0xc]\n\
	ldr r0, [r5, #0x14]\n\
	str r0, [r5, #0x18]\n\
	ldrh r1, [r5, #6]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	ldrb r1, [r5, #1]\n\
	adds r0, r0, r1\n\
	ldr r1, _080035B0 @ =0x00000AAA\n\
	muls r0, r1, r0\n\
	movs r2, #0xe0\n\
	lsls r2, r2, #0x14\n\
	adds r0, r0, r2\n\
	str r0, [r5, #0x10]\n\
	ldr r4, _080035B4 @ =0x02000010\n\
	adds r1, r4, #0\n\
	movs r2, #0x10\n\
	bl ReadSram\n\
	ldr r0, _080035B8 @ =sINTI\n\
	ldr r1, [r4]\n\
	ldr r0, [r0]\n\
	cmp r1, r0\n\
	beq _080035C4\n\
	ldrh r0, [r5, #4]\n\
	subs r0, #1\n\
	strh r0, [r5, #4]\n\
	ldr r1, _080035BC @ =0x0000FFFF\n\
	adds r2, r1, #0\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _0800368E\n\
	ldr r0, _080035C0 @ =gSramState\n\
	ldrh r1, [r0, #0x1e]\n\
	orrs r1, r2\n\
	strh r1, [r0, #0x1e]\n\
	movs r0, #3\n\
	strb r0, [r5, #3]\n\
	b _0800368E\n\
	.align 2, 0\n\
_080035B0: .4byte 0x00000AAA\n\
_080035B4: .4byte 0x02000010\n\
_080035B8: .4byte sINTI\n\
_080035BC: .4byte 0x0000FFFF\n\
_080035C0: .4byte gSramState\n\
_080035C4:\n\
	ldr r0, [r5, #0x10]\n\
	adds r0, #0x10\n\
	str r0, [r5, #0x10]\n\
	movs r0, #2\n\
	strb r0, [r5, #3]\n\
	b _0800368E\n\
_080035D0:\n\
	movs r4, #0x82\n\
	lsls r4, r4, #4\n\
	ldr r0, [r5, #0x18]\n\
	cmp r0, r4\n\
	bhi _080035E0\n\
	adds r4, r0, #0\n\
	movs r0, #3\n\
	strb r0, [r5, #3]\n\
_080035E0:\n\
	ldr r0, [r5, #0x10]\n\
	ldr r1, [r5, #0xc]\n\
	adds r2, r4, #0\n\
	bl ReadSram\n\
	ldr r0, [r5, #0xc]\n\
	movs r1, #0x82\n\
	lsls r1, r1, #4\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0xc]\n\
	ldr r0, [r5, #0x10]\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x10]\n\
	ldr r0, [r5, #0x18]\n\
	subs r0, r0, r4\n\
	str r0, [r5, #0x18]\n\
	b _0800368E\n\
_08003602:\n\
	ldr r0, _0800364C @ =gSramState\n\
	movs r2, #0x1e\n\
	ldrsh r1, [r0, r2]\n\
	adds r6, r0, #0\n\
	cmp r1, #0\n\
	bne _08003666\n\
	ldr r0, [r5, #8]\n\
	str r0, [r5, #0xc]\n\
	ldr r4, [r5, #0x14]\n\
	ldr r7, _08003650 @ =0x02000010\n\
	cmp r4, #0\n\
	beq _08003630\n\
	adds r3, r7, #0\n\
_0800361C:\n\
	ldr r0, [r5, #0xc]\n\
	ldrb r2, [r0]\n\
	ldr r1, [r3, #4]\n\
	subs r1, r1, r2\n\
	str r1, [r3, #4]\n\
	adds r0, #1\n\
	str r0, [r5, #0xc]\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	bne _0800361C\n\
_08003630:\n\
	ldr r0, [r7, #4]\n\
	cmp r0, #0\n\
	beq _0800365E\n\
	ldrh r0, [r5, #4]\n\
	subs r0, #1\n\
	strh r0, [r5, #4]\n\
	ldr r2, _08003654 @ =0x0000FFFF\n\
	adds r1, r2, #0\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _08003658\n\
	movs r0, #1\n\
	strb r0, [r5, #3]\n\
	b _0800368E\n\
	.align 2, 0\n\
_0800364C: .4byte gSramState\n\
_08003650: .4byte 0x02000010\n\
_08003654: .4byte 0x0000FFFF\n\
_08003658:\n\
	ldrh r0, [r6, #0x1e]\n\
	orrs r0, r1\n\
	strh r0, [r6, #0x1e]\n\
_0800365E:\n\
	movs r1, #0x1e\n\
	ldrsh r0, [r6, r1]\n\
	cmp r0, #0\n\
	beq _08003684\n\
_08003666:\n\
	ldrh r0, [r5, #6]\n\
	cmp r0, #0\n\
	bne _0800367C\n\
	strh r0, [r6, #0x1e]\n\
	movs r0, #3\n\
	strh r0, [r5, #4]\n\
	movs r1, #1\n\
	movs r0, #1\n\
	strh r0, [r5, #6]\n\
	strb r1, [r5, #3]\n\
	b _0800368E\n\
_0800367C:\n\
	movs r2, #0x1e\n\
	ldrsh r0, [r6, r2]\n\
	cmp r0, #0\n\
	bne _08003688\n\
_08003684:\n\
	movs r0, #1\n\
	strh r0, [r6, #0x1e]\n\
_08003688:\n\
	movs r0, #0\n\
	strb r0, [r5]\n\
	strh r0, [r5, #2]\n\
_0800368E:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}
