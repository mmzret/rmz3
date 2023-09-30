#include "blink.h"
#include "gfx.h"
#include "global.h"
#include "overworld.h"

static const u8 u8_ARRAY_0833b200[6];

static void initSpaceCraft(struct Coord* _ UNUSED) {
  gOverworld.unk_1c8.work[0] = 0;
  gOverworld.unk_1c8.work[2] = 0;
  gOverworld.work.spacecraft.omega = NULL;
  gOverworld.work.spacecraft.omegaCoord.x = PIXEL(4080);
  gOverworld.work.spacecraft.omegaCoord.y = PIXEL(288);
  gOverworld.unk_1c8.work[1] = 0;
  gOverworld.work.spacecraft.unk_00e = 0;
  if (!IS_MISSION) {
    LoadScreenIntoMetatileMap(16, 1, 48);
  }
}

static void updateSpaceCraft(struct Coord* _ UNUSED) {
  if ((gOverworld.unk_1c8.tilesets[0] >> 8 == STAGE_SPACE_CRAFT) && ((gOverworld.unk_1c8.tilesets[0] & 0xFF) == 0)) {
    if ((gOverworld.work.spacecraft.unk_00e & (1 << 0)) == 0) {
      gOverworld.work.spacecraft.unk_00e |= 1;
      LoadBlink(5, 0);
    }
    UpdateBlinkMotionState(5);
  } else if (gOverworld.work.spacecraft.unk_00e & 1) {
    gOverworld.work.spacecraft.unk_00e ^= 1;
    ClearBlink(5);
  }

  if ((gOverworld.unk_1c8.tilesets[1] >> 8 == STAGE_SPACE_CRAFT) && ((gOverworld.unk_1c8.tilesets[1] & 0xFF) == 2)) {
    if ((gOverworld.work.spacecraft.unk_00e & (1 << 1)) == 0) {
      gOverworld.work.spacecraft.unk_00e |= (1 << 1);
      LoadBlink(9, 0);
    }
    UpdateBlinkMotionState(9);
  } else if (gOverworld.work.spacecraft.unk_00e & (1 << 1)) {
    gOverworld.work.spacecraft.unk_00e ^= (1 << 1);
    ClearBlink(9);
  }

  if ((gOverworld.unk_1c8.tilesets[0] >> 8 == STAGE_SPACE_CRAFT) && ((gOverworld.unk_1c8.tilesets[0] & 0xFF) == 3)) {
    if ((gOverworld.work.spacecraft.unk_00e & (1 << 2)) == 0) {
      gOverworld.work.spacecraft.unk_00e |= (1 << 2);
      LoadBlink(6, 0);
      LoadBlink(8, 0);
    }
    UpdateBlinkMotionState(6);
    UpdateBlinkMotionState(8);
  } else if (gOverworld.work.spacecraft.unk_00e & (1 << 2)) {
    gOverworld.work.spacecraft.unk_00e ^= (1 << 2);
    ClearBlink(6);
    ClearBlink(8);
  }

  if ((gOverworld.unk_1c8.tilesets[1] >> 8 == STAGE_SPACE_CRAFT) && ((gOverworld.unk_1c8.tilesets[1] & 0xFF) == 4)) {
    if ((gOverworld.work.spacecraft.unk_00e & (1 << 3)) == 0) {
      gOverworld.work.spacecraft.unk_00e |= (1 << 3);
      LoadBlink(7, 0);
      LoadBlink(10, 0);
    }
    UpdateBlinkMotionState(7);
    UpdateBlinkMotionState(10);
  } else if (gOverworld.work.spacecraft.unk_00e & (1 << 3)) {
    gOverworld.work.spacecraft.unk_00e ^= (1 << 3);
    ClearBlink(7);
    ClearBlink(10);
  }
}

static void nop_0800b434(struct Coord* _ UNUSED) { return; }

static void exitSpaceCraft(struct Coord* _ UNUSED) {
  ClearBlink(5);
  ClearBlink(6);
  ClearBlink(7);
  ClearBlink(8);
  ClearBlink(9);
  ClearBlink(10);
}

static void LayerUpdate_SpaceCraft_2(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    const u16 n = (l->bgIdx << 16) >> 20;
    BGCNT16(n) = (l->prio | l->screenBase) | 0x44;
    *(u32*)gVideoRegBuffer.bgofs[n] = 0;
    (l->work).spacecraft.frameCounter = 0;
    CpuFastCopy(BGMAP(40), (void*)(VRAM + SCREEN_BASE_16(n)), 2048);
    l->phase++;
  }
  (l->work).spacecraft.frameCounter++;
}

NAKED static void LayerDraw_OutsideScroll(struct StageLayer* p, const struct Stage* _ UNUSED) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0xc\n\
	adds r7, r0, #0\n\
	movs r4, #0x9f\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #2\n\
	bl Malloc\n\
	mov sl, r0\n\
	cmp r0, #0\n\
	bne _0800B4F0\n\
	b _0800B8FA\n\
_0800B4F0:\n\
	ldr r2, _0800B828 @ =gIntrManager\n\
	movs r1, #0xba\n\
	lsls r1, r1, #1\n\
	adds r0, r2, r1\n\
	mov r3, sl\n\
	str r3, [r0]\n\
	movs r0, #0xbc\n\
	lsls r0, r0, #1\n\
	adds r1, r2, r0\n\
	ldr r0, _0800B82C @ =0x0400001C\n\
	str r0, [r1]\n\
	movs r3, #0xbe\n\
	lsls r3, r3, #1\n\
	adds r1, r2, r3\n\
	ldr r0, _0800B830 @ =0xA6600001\n\
	str r0, [r1]\n\
	ldr r0, [r7, #0x34]\n\
	lsls r0, r0, #0xf\n\
	lsrs r5, r0, #0x10\n\
	ldr r0, [r7, #0x38]\n\
	ldr r1, _0800B834 @ =0xFFFFFA60\n\
	adds r0, r0, r1\n\
	asrs r0, r0, #3\n\
	adds r0, #0x13\n\
	lsls r0, r0, #0x10\n\
	asrs r2, r0, #0x10\n\
	adds r0, r2, #0\n\
	adds r0, #0x9f\n\
	cmp r0, #0x80\n\
	ble _0800B548\n\
	movs r1, #0x9f\n\
	lsls r1, r1, #2\n\
	add r1, sl\n\
	adds r3, r2, #0\n\
	lsls r2, r3, #0x10\n\
	orrs r2, r5\n\
_0800B538:\n\
	str r2, [r1]\n\
	subs r1, #4\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	blt _0800B548\n\
	adds r0, r3, r4\n\
	cmp r0, #0x80\n\
	bgt _0800B538\n\
_0800B548:\n\
	ldr r0, [r7, #0x34]\n\
	lsls r0, r0, #0xe\n\
	lsrs r5, r0, #0x10\n\
	ldr r0, [r7, #0x38]\n\
	ldr r2, _0800B834 @ =0xFFFFFA60\n\
	adds r0, r0, r2\n\
	asrs r0, r0, #4\n\
	adds r0, #0x1c\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	cmp r4, #0\n\
	blt _0800B5BC\n\
	lsls r0, r1, #0x10\n\
	asrs r2, r0, #0x10\n\
	adds r1, r2, r4\n\
	adds r6, r0, #0\n\
	cmp r1, #0x80\n\
	ble _0800B594\n\
	adds r1, r2, #0\n\
	lsls r0, r4, #0x10\n\
	rsbs r0, r0, #0\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x10\n\
	adds r3, r0, r2\n\
	lsls r2, r4, #2\n\
	add r2, sl\n\
	movs r0, #0x80\n\
	lsls r0, r0, #9\n\
	mov r8, r0\n\
_0800B582:\n\
	str r3, [r2]\n\
	add r3, r8\n\
	subs r2, #4\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	blt _0800B5BC\n\
	adds r0, r1, r4\n\
	cmp r0, #0x80\n\
	bgt _0800B582\n\
_0800B594:\n\
	cmp r4, #0\n\
	blt _0800B5BC\n\
	asrs r2, r6, #0x10\n\
	adds r0, r2, r4\n\
	cmp r0, #0x77\n\
	ble _0800B5BC\n\
	lsls r0, r4, #2\n\
	mov r3, sl\n\
	adds r1, r0, r3\n\
	adds r3, r2, #0\n\
	lsls r2, r3, #0x10\n\
	orrs r2, r5\n\
_0800B5AC:\n\
	str r2, [r1]\n\
	subs r1, #4\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	blt _0800B5BC\n\
	adds r0, r3, r4\n\
	cmp r0, #0x77\n\
	bgt _0800B5AC\n\
_0800B5BC:\n\
	ldr r0, [r7, #0x34]\n\
	lsls r0, r0, #0xd\n\
	lsrs r5, r0, #0x10\n\
	ldr r0, [r7, #0x38]\n\
	ldr r1, _0800B834 @ =0xFFFFFA60\n\
	adds r0, r0, r1\n\
	asrs r0, r0, #5\n\
	adds r0, #0x20\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	cmp r4, #0\n\
	blt _0800B62E\n\
	lsls r0, r1, #0x10\n\
	asrs r2, r0, #0x10\n\
	adds r1, r2, r4\n\
	adds r6, r0, #0\n\
	cmp r1, #0x77\n\
	ble _0800B606\n\
	adds r3, r2, #0\n\
	lsls r0, r4, #0x10\n\
	movs r1, #0xee\n\
	lsls r1, r1, #0xf\n\
	subs r1, r1, r0\n\
	lsls r2, r4, #2\n\
	add r2, sl\n\
	movs r0, #0x80\n\
	lsls r0, r0, #9\n\
	mov r8, r0\n\
_0800B5F4:\n\
	str r1, [r2]\n\
	add r1, r8\n\
	subs r2, #4\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	blt _0800B62E\n\
	adds r0, r3, r4\n\
	cmp r0, #0x77\n\
	bgt _0800B5F4\n\
_0800B606:\n\
	cmp r4, #0\n\
	blt _0800B62E\n\
	asrs r2, r6, #0x10\n\
	adds r0, r2, r4\n\
	cmp r0, #0x70\n\
	ble _0800B62E\n\
	lsls r0, r4, #2\n\
	mov r3, sl\n\
	adds r1, r0, r3\n\
	adds r3, r2, #0\n\
	lsls r2, r3, #0x10\n\
	orrs r2, r5\n\
_0800B61E:\n\
	str r2, [r1]\n\
	subs r1, #4\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	blt _0800B62E\n\
	adds r0, r3, r4\n\
	cmp r0, #0x70\n\
	bgt _0800B61E\n\
_0800B62E:\n\
	lsls r2, r4, #0x10\n\
	ldr r0, [r7, #0x68]\n\
	lsrs r0, r0, #1\n\
	ldr r1, [r7, #0x34]\n\
	asrs r1, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	ldr r0, [r7, #0x38]\n\
	ldr r1, _0800B838 @ =0xFFFFFB00\n\
	adds r0, r0, r1\n\
	asrs r0, r0, #4\n\
	adds r0, #0x18\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	movs r4, #0\n\
	lsrs r3, r2, #0x10\n\
	mov r8, r3\n\
	asrs r2, r2, #0x10\n\
	cmp r4, r2\n\
	bgt _0800B676\n\
	lsls r0, r1, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0x26\n\
	bgt _0800B676\n\
	mov r6, sl\n\
	adds r3, r0, #0\n\
	lsls r1, r3, #0x10\n\
	orrs r1, r5\n\
_0800B668:\n\
	stm r6!, {r1}\n\
	adds r4, #1\n\
	cmp r4, r2\n\
	bgt _0800B676\n\
	adds r0, r3, r4\n\
	cmp r0, #0x26\n\
	ble _0800B668\n\
_0800B676:\n\
	ldr r0, [r7, #0x68]\n\
	lsrs r0, r0, #2\n\
	ldr r1, [r7, #0x34]\n\
	asrs r1, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	ldr r0, [r7, #0x38]\n\
	ldr r1, _0800B838 @ =0xFFFFFB00\n\
	adds r0, r0, r1\n\
	asrs r0, r0, #5\n\
	adds r0, #0x18\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	mov r2, r8\n\
	lsls r0, r2, #0x10\n\
	asrs r2, r0, #0x10\n\
	str r0, [sp]\n\
	cmp r4, r2\n\
	bgt _0800B70A\n\
	lsls r0, r1, #0x10\n\
	asrs r3, r0, #0x10\n\
	adds r1, r3, r4\n\
	adds r6, r0, #0\n\
	cmp r1, #0x26\n\
	bgt _0800B6E0\n\
	mov r8, r5\n\
	lsls r0, r4, #0x10\n\
	movs r1, #0x9c\n\
	lsls r1, r1, #0xe\n\
	subs r1, r1, r0\n\
	lsls r0, r4, #2\n\
	add r0, sl\n\
	mov ip, r0\n\
	ldr r0, _0800B83C @ =0xFFFF0000\n\
	mov sb, r0\n\
	str r3, [sp, #4]\n\
_0800B6C0:\n\
	adds r0, r1, #0\n\
	mov r3, r8\n\
	orrs r0, r3\n\
	mov r3, ip\n\
	adds r3, #4\n\
	mov ip, r3\n\
	subs r3, #4\n\
	stm r3!, {r0}\n\
	add r1, sb\n\
	adds r4, #1\n\
	cmp r4, r2\n\
	bgt _0800B70A\n\
	ldr r3, [sp, #4]\n\
	adds r0, r3, r4\n\
	cmp r0, #0x26\n\
	ble _0800B6C0\n\
_0800B6E0:\n\
	ldr r0, [sp]\n\
	asrs r2, r0, #0x10\n\
	cmp r4, r2\n\
	bgt _0800B70A\n\
	asrs r1, r6, #0x10\n\
	adds r0, r1, r4\n\
	cmp r0, #0x34\n\
	bgt _0800B70A\n\
	lsls r0, r4, #2\n\
	mov r3, sl\n\
	adds r6, r0, r3\n\
	adds r3, r1, #0\n\
	lsls r1, r3, #0x10\n\
	orrs r1, r5\n\
_0800B6FC:\n\
	stm r6!, {r1}\n\
	adds r4, #1\n\
	cmp r4, r2\n\
	bgt _0800B70A\n\
	adds r0, r3, r4\n\
	cmp r0, #0x34\n\
	ble _0800B6FC\n\
_0800B70A:\n\
	ldr r0, [r7, #0x68]\n\
	lsrs r0, r0, #3\n\
	ldr r1, [r7, #0x34]\n\
	asrs r1, r1, #4\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	ldr r0, [r7, #0x38]\n\
	ldr r1, _0800B838 @ =0xFFFFFB00\n\
	adds r0, r0, r1\n\
	asrs r0, r0, #6\n\
	adds r0, #0x18\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	ldr r3, [sp]\n\
	asrs r2, r3, #0x10\n\
	cmp r4, r2\n\
	bgt _0800B79A\n\
	lsls r0, r1, #0x10\n\
	asrs r3, r0, #0x10\n\
	adds r1, r3, r4\n\
	adds r6, r0, #0\n\
	cmp r1, #0x34\n\
	bgt _0800B770\n\
	mov r8, r5\n\
	lsls r0, r4, #0x10\n\
	movs r1, #0xd4\n\
	lsls r1, r1, #0xe\n\
	subs r1, r1, r0\n\
	lsls r0, r4, #2\n\
	add r0, sl\n\
	mov ip, r0\n\
	ldr r0, _0800B83C @ =0xFFFF0000\n\
	mov sb, r0\n\
	str r3, [sp, #4]\n\
_0800B750:\n\
	adds r0, r1, #0\n\
	mov r3, r8\n\
	orrs r0, r3\n\
	mov r3, ip\n\
	adds r3, #4\n\
	mov ip, r3\n\
	subs r3, #4\n\
	stm r3!, {r0}\n\
	add r1, sb\n\
	adds r4, #1\n\
	cmp r4, r2\n\
	bgt _0800B79A\n\
	ldr r3, [sp, #4]\n\
	adds r0, r3, r4\n\
	cmp r0, #0x34\n\
	ble _0800B750\n\
_0800B770:\n\
	ldr r0, [sp]\n\
	asrs r2, r0, #0x10\n\
	cmp r4, r2\n\
	bgt _0800B79A\n\
	asrs r1, r6, #0x10\n\
	adds r0, r1, r4\n\
	cmp r0, #0x3f\n\
	bgt _0800B79A\n\
	lsls r0, r4, #2\n\
	mov r3, sl\n\
	adds r6, r0, r3\n\
	adds r3, r1, #0\n\
	lsls r1, r3, #0x10\n\
	orrs r1, r5\n\
_0800B78C:\n\
	stm r6!, {r1}\n\
	adds r4, #1\n\
	cmp r4, r2\n\
	bgt _0800B79A\n\
	adds r0, r3, r4\n\
	cmp r0, #0x3f\n\
	ble _0800B78C\n\
_0800B79A:\n\
	ldr r0, [r7, #0x68]\n\
	lsrs r0, r0, #4\n\
	ldr r1, [r7, #0x34]\n\
	asrs r1, r1, #5\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	ldr r0, [r7, #0x38]\n\
	ldr r1, _0800B838 @ =0xFFFFFB00\n\
	adds r0, r0, r1\n\
	asrs r0, r0, #7\n\
	adds r0, #0x18\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	ldr r3, [sp]\n\
	asrs r2, r3, #0x10\n\
	cmp r4, r2\n\
	bgt _0800B84A\n\
	lsls r0, r1, #0x10\n\
	asrs r1, r0, #0x10\n\
	mov r8, r1\n\
	adds r1, r1, r4\n\
	adds r6, r0, #0\n\
	cmp r1, #0x3f\n\
	bgt _0800B804\n\
	mov sb, r5\n\
	lsls r0, r4, #0x10\n\
	rsbs r0, r0, #0\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0xf\n\
	adds r3, r0, r1\n\
	lsls r0, r4, #2\n\
	add r0, sl\n\
	mov ip, r0\n\
	str r2, [sp, #8]\n\
	mov r1, r8\n\
_0800B7E2:\n\
	adds r0, r3, #0\n\
	mov r2, sb\n\
	orrs r0, r2\n\
	mov r2, ip\n\
	adds r2, #4\n\
	mov ip, r2\n\
	subs r2, #4\n\
	stm r2!, {r0}\n\
	ldr r0, _0800B83C @ =0xFFFF0000\n\
	adds r3, r3, r0\n\
	adds r4, #1\n\
	ldr r2, [sp, #8]\n\
	cmp r4, r2\n\
	bgt _0800B84A\n\
	adds r0, r1, r4\n\
	cmp r0, #0x3f\n\
	ble _0800B7E2\n\
_0800B804:\n\
	ldr r3, [sp]\n\
	asrs r2, r3, #0x10\n\
	cmp r4, r2\n\
	bgt _0800B84A\n\
	asrs r1, r6, #0x10\n\
	adds r0, r1, r4\n\
	cmp r0, #0x47\n\
	bgt _0800B84A\n\
	lsls r0, r4, #2\n\
	mov r3, sl\n\
	adds r6, r0, r3\n\
	adds r3, r1, #0\n\
	lsls r1, r3, #0x10\n\
	orrs r1, r5\n\
_0800B820:\n\
	stm r6!, {r1}\n\
	adds r4, #1\n\
	b _0800B840\n\
	.align 2, 0\n\
_0800B828: .4byte gIntrManager\n\
_0800B82C: .4byte 0x0400001C\n\
_0800B830: .4byte 0xA6600001\n\
_0800B834: .4byte 0xFFFFFA60\n\
_0800B838: .4byte 0xFFFFFB00\n\
_0800B83C: .4byte 0xFFFF0000\n\
_0800B840:\n\
	cmp r4, r2\n\
	bgt _0800B84A\n\
	adds r0, r3, r4\n\
	cmp r0, #0x47\n\
	ble _0800B820\n\
_0800B84A:\n\
	ldr r0, [r7, #0x68]\n\
	lsrs r0, r0, #5\n\
	ldr r1, [r7, #0x34]\n\
	asrs r1, r1, #6\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	ldr r0, [r7, #0x38]\n\
	ldr r7, _0800B90C @ =0xFFFFFB00\n\
	adds r0, r0, r7\n\
	asrs r0, r0, #8\n\
	adds r0, #0x18\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	ldr r0, [sp]\n\
	asrs r2, r0, #0x10\n\
	cmp r4, r2\n\
	bgt _0800B8FA\n\
	lsls r0, r1, #0x10\n\
	asrs r3, r0, #0x10\n\
	adds r1, r3, r4\n\
	adds r6, r0, #0\n\
	cmp r1, #0x47\n\
	bgt _0800B8AC\n\
	mov r8, r5\n\
	lsls r0, r4, #0x10\n\
	movs r1, #0x90\n\
	lsls r1, r1, #0xf\n\
	subs r1, r1, r0\n\
	lsls r0, r4, #2\n\
	add r0, sl\n\
	mov ip, r0\n\
	ldr r7, _0800B910 @ =0xFFFF0000\n\
	mov sb, r7\n\
_0800B88E:\n\
	adds r0, r1, #0\n\
	mov r7, r8\n\
	orrs r0, r7\n\
	mov r7, ip\n\
	adds r7, #4\n\
	mov ip, r7\n\
	subs r7, #4\n\
	stm r7!, {r0}\n\
	add r1, sb\n\
	adds r4, #1\n\
	cmp r4, r2\n\
	bgt _0800B8FA\n\
	adds r0, r3, r4\n\
	cmp r0, #0x47\n\
	ble _0800B88E\n\
_0800B8AC:\n\
	ldr r0, [sp]\n\
	asrs r7, r0, #0x10\n\
	cmp r4, r7\n\
	bgt _0800B8FA\n\
	asrs r1, r6, #0x10\n\
	adds r0, r1, r4\n\
	cmp r0, #0x53\n\
	bgt _0800B8D8\n\
	lsls r0, r4, #2\n\
	mov r2, sl\n\
	adds r6, r0, r2\n\
	adds r3, r1, #0\n\
	lsls r1, r3, #0x10\n\
	orrs r1, r5\n\
	adds r2, r7, #0\n\
_0800B8CA:\n\
	stm r6!, {r1}\n\
	adds r4, #1\n\
	cmp r4, r2\n\
	bgt _0800B8FA\n\
	adds r0, r3, r4\n\
	cmp r0, #0x53\n\
	ble _0800B8CA\n\
_0800B8D8:\n\
	ldr r3, [sp]\n\
	asrs r0, r3, #0x10\n\
	cmp r4, r0\n\
	bgt _0800B8FA\n\
	adds r2, r0, #0\n\
	lsls r0, r4, #0x10\n\
	movs r1, #0xe4\n\
	lsls r1, r1, #0xf\n\
	subs r1, r1, r0\n\
	lsls r0, r4, #2\n\
	add r0, sl\n\
	ldr r3, _0800B910 @ =0xFFFF0000\n\
_0800B8F0:\n\
	stm r0!, {r1}\n\
	adds r1, r1, r3\n\
	adds r4, #1\n\
	cmp r4, r2\n\
	ble _0800B8F0\n\
_0800B8FA:\n\
	add sp, #0xc\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0800B90C: .4byte 0xFFFFFB00\n\
_0800B910: .4byte 0xFFFF0000\n\
 .syntax divided\n");
}

// 0x0800b914
NAKED static void LayerUpdate_SpaceCraft_3(struct StageLayer* l, const struct Stage* _ UNUSED) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, #8\n\
	adds r7, r0, #0\n\
	ldr r0, [r7, #0x5c]\n\
	lsls r0, r0, #0x10\n\
	ldrb r1, [r7, #0xe]\n\
	mov r8, r1\n\
	cmp r1, #0\n\
	bne _0800B97E\n\
	lsrs r5, r0, #0x14\n\
	lsls r5, r5, #1\n\
	ldr r0, _0800B98C @ =gVideoRegBuffer+4\n\
	adds r5, r5, r0\n\
	ldr r1, [r7, #0x64]\n\
	ldr r2, _0800B990 @ =0x00004046\n\
	adds r0, r2, #0\n\
	orrs r1, r0\n\
	strh r1, [r5]\n\
	ldr r0, _0800B994 @ =gBgMapOffsets+(42*4)\n\
	ldr r0, [r0]\n\
	ldr r2, _0800B998 @ =gBgMapOffsets+(44*4)\n\
	adds r0, r0, r2\n\
	movs r4, #0xf8\n\
	lsls r4, r4, #5\n\
	ands r1, r4\n\
	lsls r1, r1, #3\n\
	movs r2, #0xc0\n\
	lsls r2, r2, #0x13\n\
	adds r1, r1, r2\n\
	movs r6, #0x80\n\
	lsls r6, r6, #2\n\
	adds r2, r6, #0\n\
	bl CpuFastSet\n\
	ldrh r0, [r5]\n\
	ands r4, r0\n\
	lsls r4, r4, #3\n\
	ldr r0, _0800B99C @ =0x06000800\n\
	adds r4, r4, r0\n\
	mov r1, r8\n\
	str r1, [sp]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x11\n\
	orrs r2, r6\n\
	mov r0, sp\n\
	adds r1, r4, #0\n\
	bl CpuFastSet\n\
	ldrb r0, [r7, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r7, #0xe]\n\
_0800B97E:\n\
	add sp, #8\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0800B98C: .4byte gVideoRegBuffer+4\n\
_0800B990: .4byte 0x00004046\n\
_0800B994: .4byte gBgMapOffsets+(42*4)\n\
_0800B998: .4byte gBgMapOffsets+(44*4)\n\
_0800B99C: .4byte 0x06000800\n\
 .syntax divided\n");
}

// オメガ(BG3)のスクロールとかを調整してオメガが正しい位置に来るようにする
WIP static void LayerDraw_FixOmegaWhiteCoord(struct StageLayer* l, const struct Stage* _ UNUSED) {
#if MODERN
  u16 dispcnt, n;
  struct Boss* omega;

  dispcnt = l->bgIdx;
  if (gOverworld.unk_1c8.work[1] != 0) {
    gVideoRegBuffer.dispcnt |= (dispcnt << 8);
  } else {
    gVideoRegBuffer.dispcnt &= ~(dispcnt << 8);
  }
  n = dispcnt >> 4;
  if (gOverworld.unk_1c8.unk_2c002 != 0) {
    vu32 _;
    CpuFastCopy(BGMAP(42), (void*)(VRAM + SCREEN_BASE_16(n)), 2048);
    CpuFastFill(0, (void*)(VRAM + 0x800 + SCREEN_BASE_16(n)), 2048);
  }
  if (omega = gOverworld.work.spacecraft.omega, omega != NULL) {
    u8 id;
    gOverworld.work.spacecraft.omegaCoord.x = (omega->s).coord.x;
    gOverworld.work.spacecraft.omegaCoord.y = (omega->s).coord.y;

    id = (omega->s).invincibleID;
    if (gWhitePaintFlags[id >> 5] & (1 << (id & 0x1F))) {
      gPaletteManager.unk_404 = 0x180;
      gPaletteManager.unk_406 = 0x20;
    }
  }
  gVideoRegBuffer.bgofs[n][0] = (l->viewportCenterPixel).x - (gOverworld.work.spacecraft.omegaCoord.x >> 8) + 48 + ((l->drawPivotOffset).x >> 8);
  gVideoRegBuffer.bgofs[n][1] = (l->viewportCenterPixel).y - (gOverworld.work.spacecraft.omegaCoord.y >> 8) + 144 + ((l->drawPivotOffset).y >> 8);
#else
  INCCODE("asm/wip/fixOmegaWhiteCoord.inc");
#endif
}

/*
雪を降らせる処理？
  ステージを歩いて宇宙船を発見するシーン
  シエルたちがネオアルカディアに襲われるシーン
で利用される
*/
static void LayerUpdate_SnowFall(struct StageLayer* l, const struct Stage* _ UNUSED) {
  u16 eva;
  const u16 n = l->bgIdx;

  // 初期化時, gOverworld.unk_1c8.work[0] が
  //   0 : 雪を降らせる(BG2を透明にしない)
  //   1 : 雪を降らせない(BG2を透明にする)
  if (l->phase == 0) {
    BGCNT16(n >> 4) = l->screenBase | 0x45;
    *(u32*)gVideoRegBuffer.bgofs[n >> 4] = 0;
    RequestBgMapTransfer(BGMAP(41), (void*)SCREEN_BASE_16(n >> 4), 2048);
    gBlendRegBuffer.bldclt = ((BLDCNT_TGT1_BG2) | (BLDCNT_TGT2_BD | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG0)) | BLDCNT_EFFECT_BLEND;
    if (gOverworld.unk_1c8.work[0] == 0) {
      gBlendRegBuffer.bldalpha = BLDALPHA_BLEND(16, 16);
    } else {
      gBlendRegBuffer.bldalpha = BLDALPHA_BLEND(0, 16);
    }
    l->unk_10 = 0;
    l->unk_12 = 0;
    l->phase++;
  }

  // gOverworld.unk_1c8.work[0] が 1 のときに、雪が降っている(BG2が完全に透明でない)ときは、徐々に透明にしていく
  if ((gOverworld.unk_1c8.work[0] != 0) && ((l->unk_10 & 0x1F) == 0) && (eva = (gBlendRegBuffer.bldalpha & 0x1F), eva != 0)) {
    gBlendRegBuffer.bldalpha = BLDALPHA_BLEND(((eva - 1) & 0x1F), 16);
  }

  l->unk_10--;
  if (++l->unk_12 == 48) {
    l->unk_12 = 0;
  }
}

static void LayerDraw_SpaceCraft_4(struct StageLayer* l, const struct Stage* _ UNUSED) {
  const u16 n = l->bgIdx;
  ((struct BgOfs*)gVideoRegBuffer.bgofs[n >> 4])->x = (l->viewportCenterPixel).x;
  gVideoRegBuffer.bgofs[n >> 4][1] = l->unk_10 >> 2;

  RequestGraphicTransfer(&(TILESETS(18, 88)[u8_ARRAY_0833b200[(l->unk_12 >> 3) % 6]]).g, (void*)0x4000);
  LoadPalette(&(TILESETS(18, 88)[u8_ARRAY_0833b200[(l->unk_12 >> 3) % 6]]).pal, 0);
}

// 0x0800bc7c
static void LayerExit_DisableBlend(struct StageLayer* l UNUSED, const struct Stage* _ UNUSED) {
  gBlendRegBuffer.bldclt = 0;
  return;
}

static void LayerUpdate_SpaceCraft_5(struct StageLayer* l, const struct Stage* _ UNUSED) {
  switch (l->phase) {
    case 0: {
      if (gOverworld.unk_1c8.work[2] == 0) {
        return;
      }
      LoadScreenIntoMetatileMap(16, 1, 52);
      l->phase++;
      FALLTHROUGH;
    }
    case 1: {
      if (gOverworld.unk_1c8.work[2] == 1) {
        return;
      }
      LoadScreenIntoMetatileMap(16, 1, 53);
      l->phase++;
      FALLTHROUGH;
    }
    case 2: {
      if (gOverworld.unk_1c8.work[2] == 2) {
        return;
      }
      LoadScreenIntoMetatileMap(16, 1, 54);
      l->phase++;
      FALLTHROUGH;
    }
    case 3: {
      if (gOverworld.unk_1c8.work[2] == 3) {
        return;
      }
      LoadScreenIntoMetatileMap(16, 1, 48);
      l->phase++;
      break;
    }
  }
}

void omegaWhite_0800bd24(struct Boss* p) { gOverworld.work.spacecraft.omega = p; }

WIP bool16 FUN_0800bd38(s32 x, s32 y) {
#if MODERN
  s16 mx = METACOORD(x) - 1;
  s16 my = METACOORD(y) - 1;
  struct MetatileMap* tm = (struct MetatileMap*)gOverworld.unk_1c8.tilemap;
  metatile_id_t id1 = tm->map[my * tm->width + mx];
  metatile_id_t id2 = tm->map[my * tm->width + mx + 120];
  u32 val = (id1 ^ id2);
  return (-val) >> 31;
#else
  INCCODE("asm/wip/FUN_0800bd38.inc");
#endif
}

NAKED void FUN_0800bd78(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #8\n\
	asrs r2, r0, #0xc\n\
	subs r2, #1\n\
	asrs r3, r1, #0xc\n\
	subs r3, #1\n\
	lsls r2, r2, #0x10\n\
	asrs r6, r2, #0x10\n\
	movs r4, #0xf0\n\
	lsls r4, r4, #0xf\n\
	adds r2, r2, r4\n\
	lsls r4, r3, #0x10\n\
	ldr r5, _0800BDCC @ =0x0000FFFF\n\
	lsrs r2, r2, #0x10\n\
	orrs r2, r4\n\
	str r2, [sp]\n\
	ldr r2, _0800BDD0 @ =0x00020002\n\
	str r2, [sp, #4]\n\
	movs r2, #0xc0\n\
	lsls r2, r2, #6\n\
	adds r1, r1, r2\n\
	bl FUN_0800bd38\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _0800BDB8\n\
	ldr r0, [sp, #4]\n\
	ands r0, r5\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #0xa\n\
	orrs r0, r1\n\
	str r0, [sp, #4]\n\
_0800BDB8:\n\
	asrs r1, r4, #0x10\n\
	adds r0, r6, #0\n\
	mov r2, sp\n\
	bl ShiftMetatile\n\
	add sp, #8\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0800BDCC: .4byte 0x0000FFFF\n\
_0800BDD0: .4byte 0x00020002\n\
 .syntax divided\n");
}

NAKED void FUN_0800bdd4(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {lr}\n\
	sub sp, #8\n\
	asrs r0, r0, #0xc\n\
	subs r0, #1\n\
	asrs r1, r1, #0xc\n\
	subs r1, #1\n\
	lsls r0, r0, #0x10\n\
	asrs r2, r0, #0x10\n\
	movs r3, #0xf0\n\
	lsls r3, r3, #0xe\n\
	adds r0, r0, r3\n\
	lsls r1, r1, #0x10\n\
	lsrs r0, r0, #0x10\n\
	orrs r0, r1\n\
	str r0, [sp]\n\
	ldr r0, _0800BE08 @ =0x00020002\n\
	str r0, [sp, #4]\n\
	asrs r1, r1, #0x10\n\
	adds r0, r2, #0\n\
	mov r2, sp\n\
	bl ShiftMetatile\n\
	add sp, #8\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0800BE08: .4byte 0x00020002\n\
 .syntax divided\n");
}

static const StageFunc sStageRoutine[4] = {
    initSpaceCraft,
    updateSpaceCraft,
    nop_0800b434,
    exitSpaceCraft,
};

// clang-format off
static const StageLayerRoutine sLayerRoutine[6] = {
    [0] = {
      [LAYER_UPDATE] = NULL,
      [LAYER_DRAW]   = NULL,
      [LAYER_EXIT]   = NULL,
    },
    [1] = {
      [LAYER_UPDATE] = NULL,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
    [2] = {
      [LAYER_UPDATE] = LayerUpdate_SpaceCraft_2,
      [LAYER_DRAW]   = LayerDraw_OutsideScroll,
      [LAYER_EXIT]   = NULL,
    },
    [3] = {
      [LAYER_UPDATE] = LayerUpdate_SpaceCraft_3,
      [LAYER_DRAW]   = LayerDraw_FixOmegaWhiteCoord,
      [LAYER_EXIT]   = NULL,
    },
    [4] = {
      [LAYER_UPDATE] = LayerUpdate_SnowFall,
      [LAYER_DRAW]   = LayerDraw_SpaceCraft_4,
      [LAYER_EXIT]   = LayerExit_DisableBlend,
    },
    [5] = {
      [LAYER_UPDATE] = LayerUpdate_SpaceCraft_5,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
};
// clang-format on

#include "../../../data/stage/spacecraft/layer.h"
// ...
#include "../../../data/stage/spacecraft/landscape.h"

static const u8 u8_ARRAY_0833b200[6] = {0, 1, 2, 3, 2, 1};
