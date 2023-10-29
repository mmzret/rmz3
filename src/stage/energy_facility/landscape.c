#include "blink.h"
#include "global.h"
#include "overworld.h"
#include "story.h"

static void initEFacility(struct Coord* _ UNUSED);
static void FUN_08011dd8(struct Coord* _ UNUSED);
static void FUN_08012148(struct Coord* _ UNUSED);
static void FUN_080124ec(struct Coord* _ UNUSED);

static const StageFunc sStageRoutine[4] = {
    initEFacility,
    FUN_08011dd8,
    FUN_08012148,
    FUN_080124ec,
};

static void initEFacility(struct Coord* _ UNUSED) {
  gCurStory.unk_54 |= (1 << 6);
  gOverworld.work.energyFacility.unk_000[0] = 0;
  gOverworld.work.energyFacility.unk_00c[0] = 0;
  gOverworld.work.energyFacility.unk_00e = 0;
  gOverworld.work.energyFacility.unk_00c[1] = 0;
  gOverworld.work.energyFacility.unk_014 = 0;
  gOverworld.work.energyFacility.unk_010[0] = 0;
  gOverworld.work.energyFacility.unk_010[1] = 0;
  gOverworld.work.energyFacility.unk_016 = 0;
  gOverworld.work.energyFacility.unk_012[0] = 0;
  gOverworld.work.energyFacility.unk_012[1] = 0;
  gOverworld.state[0] = 0;
  gOverworld.work.energyFacility.unk_004 = 0;
  gOverworld.work.energyFacility.unk_008 = 0;
}

static void FUN_08011dd8(struct Coord* _ UNUSED) {
  if ((TILESET_ID(1) == STAGE_E_FACILITY) && (TILESET_IDX(1) == 3)) {
    if ((gOverworld.work.energyFacility.unk_000[0] & (1 << 0)) == 0) {
      gOverworld.work.energyFacility.unk_000[0] |= (1 << 0);
      LoadBlink(196, 0);
    }
    UpdateBlinkMotionState(196);

  } else if ((gOverworld.work.energyFacility.unk_000[0] & (1 << 0))) {
    gOverworld.work.energyFacility.unk_000[0] ^= (1 << 0);
    ClearBlink(196);
  }

  if ((TILESET_ID(1) == STAGE_E_FACILITY) && (TILESET_IDX(1) == 1)) {
    if ((gOverworld.work.energyFacility.unk_000[0] & (1 << 1)) == 0) {
      gOverworld.work.energyFacility.unk_000[0] |= (1 << 1);
      LoadBlink(197, 0);
    }
    UpdateBlinkMotionState(197);
    gOverworld.work.energyFacility.unk_00c[0]++;
    if (gOverworld.work.energyFacility.unk_00c[0] == 27) {
      gOverworld.work.energyFacility.unk_00c[0] = 0;
    }

  } else if ((gOverworld.work.energyFacility.unk_000[0] & (1 << 1))) {
    gOverworld.work.energyFacility.unk_000[0] ^= (1 << 1);
    ClearBlink(197);
  }

  if ((TILESET_ID(1) == STAGE_E_FACILITY) && (TILESET_IDX(1) == 4)) {
    if ((gOverworld.work.energyFacility.unk_000[0] & (1 << 2)) == 0) {
      gOverworld.work.energyFacility.unk_000[0] |= (1 << 2);
    }

    if ((gCurStory.unk_54 & (1 << 0)) && (++gOverworld.work.energyFacility.unk_010[1] == 24)) {
      gOverworld.work.energyFacility.unk_010[1] = 0;
    }
    if ((gCurStory.unk_54 & (1 << 1)) && (++gOverworld.work.energyFacility.unk_010[0] == 32)) {
      gOverworld.work.energyFacility.unk_010[0] = 0;
    }
    if (gCurStory.unk_54 & (1 << 2)) {
      gOverworld.work.energyFacility.unk_00e++;
      if (gOverworld.work.energyFacility.unk_00e == 576) {
        gOverworld.work.energyFacility.unk_00e = 0;
      }
      if (gOverworld.work.energyFacility.unk_00e == 0) {
        ClearBlink(192);
      } else if (gOverworld.work.energyFacility.unk_00e == 198) {
        LoadBlink(192, 0);
      }
      UpdateBlinkMotionState(192);
    }
    if (gCurStory.unk_54 & (1 << 3)) {
      if (gOverworld.work.energyFacility.unk_012[0] < 64) {
        gOverworld.work.energyFacility.unk_012[0]++;
      }
      gOverworld.work.energyFacility.unk_014 += gOverworld.work.energyFacility.unk_012[0];
      if (gOverworld.work.energyFacility.unk_014 > 768) {
        gOverworld.work.energyFacility.unk_014 -= 768;
      }
    }
    if (gCurStory.unk_54 & (1 << 4)) {
      if (gOverworld.work.energyFacility.unk_012[1] < 64) {
        gOverworld.work.energyFacility.unk_012[1]++;
      }
      gOverworld.work.energyFacility.unk_016 += gOverworld.work.energyFacility.unk_012[1];
      if (gOverworld.work.energyFacility.unk_016 > 512) {
        gOverworld.work.energyFacility.unk_016 -= 384;
      }
    }
    if (gCurStory.unk_54 & (1 << 5)) {
      if (gOverworld.work.energyFacility.unk_00c[1] == 0) {
        LoadBlink(193, 0);
      }
      if (gOverworld.work.energyFacility.unk_00c[1] <= 90) {
        if (gOverworld.work.energyFacility.unk_00c[1] == 90) {
          ClearBlink(193);
          LoadBlink(194, 0);
        }
        gOverworld.work.energyFacility.unk_00c[1]++;
      }
      UpdateBlinkMotionState(193);
      UpdateBlinkMotionState(194);
    }

  } else if ((gOverworld.work.energyFacility.unk_000[0] & (1 << 2))) {
    gOverworld.work.energyFacility.unk_000[0] ^= (1 << 2);
    ClearBlink(192);
    ClearBlink(193);
    ClearBlink(194);
    gOverworld.work.energyFacility.unk_00e = 0;
    gOverworld.work.energyFacility.unk_00c[1] = 0;
  }

  if (gOverworld.state[0] == 0) {
    gOverworld.work.energyFacility.unk_004++;
    if (gOverworld.work.energyFacility.unk_004 == 0xce200) {
      gOverworld.work.energyFacility.unk_004 = 0;
    }
    gOverworld.work.energyFacility.unk_008--;
    if (gOverworld.work.energyFacility.unk_008 < 0) {
      gOverworld.work.energyFacility.unk_008 = 0xce1ff;
    }
  } else {
    gOverworld.work.energyFacility.unk_004--;
    if (gOverworld.work.energyFacility.unk_004 < 0) {
      gOverworld.work.energyFacility.unk_004 = 0xce1ff;
    }
    gOverworld.work.energyFacility.unk_008++;
    if (gOverworld.work.energyFacility.unk_008 == 0xce200) {
      gOverworld.work.energyFacility.unk_008 = 0;
    }
  }
}

NAKED static void FUN_08012148(struct Coord* _ UNUSED) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	ldr r5, _08012298 @ =gOverworld\n\
	ldr r1, _0801229C @ =0x000007D6\n\
	adds r0, r5, r1\n\
	ldrh r1, [r0]\n\
	lsrs r0, r1, #8\n\
	cmp r0, #0xb\n\
	bne _080121B0\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	cmp r0, #1\n\
	bne _080121B0\n\
	ldr r6, _080122A0 @ =gStageTilesetOffsets+(18*4)\n\
	ldr r2, _080122A4 @ =0x0002D034\n\
	adds r5, r5, r2\n\
	ldrb r0, [r5]\n\
	movs r1, #9\n\
	bl __udivsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	ldr r4, _080122A8 @ =0x08704CA0\n\
	adds r1, r1, r4\n\
	ldr r0, [r6]\n\
	adds r0, r0, r1\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	bl RequestGraphicTransfer\n\
	ldrb r0, [r5]\n\
	movs r1, #9\n\
	bl __udivsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r4\n\
	ldr r0, [r6]\n\
	adds r0, r0, r1\n\
	adds r0, #0xc\n\
	movs r1, #0\n\
	bl LoadPalette\n\
_080121B0:\n\
	ldr r3, _08012298 @ =gOverworld\n\
	mov sb, r3\n\
	ldr r0, _0801229C @ =0x000007D6\n\
	add r0, sb\n\
	ldrh r1, [r0]\n\
	lsrs r0, r1, #8\n\
	cmp r0, #0xb\n\
	beq _080121C2\n\
	b _080124AE\n\
_080121C2:\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	cmp r0, #4\n\
	beq _080121CC\n\
	b _080124AE\n\
_080121CC:\n\
	ldr r0, _080122AC @ =gCurStory\n\
	adds r7, r0, #0\n\
	adds r7, #0x54\n\
	ldrb r1, [r7]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08012224\n\
	ldr r6, _080122A0 @ =gStageTilesetOffsets+(18*4)\n\
	ldr r5, _080122B0 @ =0x0002D039\n\
	add r5, sb\n\
	ldrb r0, [r5]\n\
	movs r1, #3\n\
	bl __udivsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	ldr r4, _080122B4 @ =0x08704E08\n\
	adds r1, r1, r4\n\
	ldr r0, [r6]\n\
	adds r0, r0, r1\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	bl RequestGraphicTransfer\n\
	ldrb r0, [r5]\n\
	movs r1, #3\n\
	bl __udivsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r4\n\
	ldr r0, [r6]\n\
	adds r0, r0, r1\n\
	adds r0, #0xc\n\
	movs r1, #0\n\
	bl LoadPalette\n\
_08012224:\n\
	ldrb r1, [r7]\n\
	movs r0, #2\n\
	mov sl, r0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08012232\n\
	b _0801239C\n\
_08012232:\n\
	ldr r6, _080122A0 @ =gStageTilesetOffsets+(18*4)\n\
	ldr r5, _080122B8 @ =0x0002D038\n\
	add r5, sb\n\
	ldrb r0, [r5]\n\
	lsrs r0, r0, #3\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	ldr r4, _080122BC @ =0x08704DB8\n\
	adds r1, r1, r4\n\
	ldr r0, [r6]\n\
	adds r0, r0, r1\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	mov r8, r1\n\
	bl RequestGraphicTransfer\n\
	ldrb r0, [r5]\n\
	lsrs r0, r0, #3\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r4\n\
	ldr r0, [r6]\n\
	adds r0, r0, r1\n\
	adds r0, #0xc\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	ldrb r1, [r7]\n\
	mov r0, sl\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08012278\n\
	b _0801239C\n\
_08012278:\n\
	ldr r7, _080122C0 @ =0x0002D036\n\
	add r7, sb\n\
	ldrh r1, [r7]\n\
	cmp r1, #0xb3\n\
	bhi _080122CC\n\
	ldr r0, [r6]\n\
	ldr r2, _080122C4 @ =0x08704C3C\n\
	adds r0, r0, r2\n\
	mov r1, r8\n\
	bl RequestGraphicTransfer\n\
	ldr r0, [r6]\n\
	ldr r3, _080122C8 @ =0x08704C48\n\
	adds r0, r0, r3\n\
	b _08012372\n\
	.align 2, 0\n\
_08012298: .4byte gOverworld\n\
_0801229C: .4byte 0x000007D6\n\
_080122A0: .4byte gStageTilesetOffsets+(18*4)\n\
_080122A4: .4byte 0x0002D034\n\
_080122A8: .4byte 0x08704CA0\n\
_080122AC: .4byte gCurStory\n\
_080122B0: .4byte 0x0002D039\n\
_080122B4: .4byte 0x08704E08\n\
_080122B8: .4byte 0x0002D038\n\
_080122BC: .4byte 0x08704DB8\n\
_080122C0: .4byte 0x0002D036\n\
_080122C4: .4byte 0x08704C3C\n\
_080122C8: .4byte 0x08704C48\n\
_080122CC:\n\
	cmp r1, #0xc5\n\
	bhi _08012308\n\
	ldrh r0, [r7]\n\
	subs r0, #0xb4\n\
	movs r1, #6\n\
	bl __divsi3\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	ldr r4, _08012304 @ =0x08704C50\n\
	adds r1, r1, r4\n\
	ldr r0, [r6]\n\
	adds r0, r0, r1\n\
	mov r1, r8\n\
	bl RequestGraphicTransfer\n\
	ldrh r0, [r7]\n\
	subs r0, #0xb4\n\
	movs r1, #6\n\
	bl __divsi3\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r4\n\
	b _0801236C\n\
	.align 2, 0\n\
_08012304: .4byte 0x08704C50\n\
_08012308:\n\
	ldr r0, _08012324 @ =0x00000179\n\
	cmp r1, r0\n\
	bhi _08012330\n\
	ldr r0, [r6]\n\
	ldr r1, _08012328 @ =0x08704C8C\n\
	adds r0, r0, r1\n\
	mov r1, r8\n\
	bl RequestGraphicTransfer\n\
	ldr r0, [r6]\n\
	ldr r2, _0801232C @ =0x08704C98\n\
	adds r0, r0, r2\n\
	b _08012372\n\
	.align 2, 0\n\
_08012324: .4byte 0x00000179\n\
_08012328: .4byte 0x08704C8C\n\
_0801232C: .4byte 0x08704C98\n\
_08012330:\n\
	ldr r0, _0801237C @ =0x0000018B\n\
	cmp r1, r0\n\
	bhi _08012384\n\
	ldrh r0, [r7]\n\
	ldr r5, _08012380 @ =0xFFFFFE86\n\
	adds r0, r0, r5\n\
	movs r1, #6\n\
	bl __divsi3\n\
	movs r4, #0x60\n\
	subs r0, r4, r0\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r6\n\
	ldr r0, [r6]\n\
	adds r0, r0, r1\n\
	mov r1, r8\n\
	bl RequestGraphicTransfer\n\
	ldrh r0, [r7]\n\
	adds r0, r0, r5\n\
	movs r1, #6\n\
	bl __divsi3\n\
	subs r4, r4, r0\n\
	lsls r1, r4, #2\n\
	adds r1, r1, r4\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r6\n\
_0801236C:\n\
	ldr r0, [r6]\n\
	adds r0, r0, r1\n\
	adds r0, #0xc\n\
_08012372:\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	b _0801239C\n\
	.align 2, 0\n\
_0801237C: .4byte 0x0000018B\n\
_08012380: .4byte 0xFFFFFE86\n\
_08012384:\n\
	ldr r0, [r6]\n\
	ldr r3, _080124BC @ =0x08704C3C\n\
	adds r0, r0, r3\n\
	mov r1, r8\n\
	bl RequestGraphicTransfer\n\
	ldr r0, [r6]\n\
	ldr r1, _080124C0 @ =0x08704C48\n\
	adds r0, r0, r1\n\
	movs r1, #0\n\
	bl LoadPalette\n\
_0801239C:\n\
	ldr r0, _080124C4 @ =gCurStory\n\
	adds r7, r0, #0\n\
	adds r7, #0x54\n\
	ldrb r1, [r7]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08012402\n\
	ldr r2, _080124C8 @ =gStageTilesetOffsets+(18*4)\n\
	mov r8, r2\n\
	ldr r4, _080124CC @ =gOverworld\n\
	ldr r3, _080124D0 @ =0x0002D03C\n\
	adds r4, r4, r3\n\
	ldrh r0, [r4]\n\
	movs r1, #3\n\
	bl __udivsi3\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x16\n\
	movs r6, #1\n\
	ands r0, r6\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	ldr r5, _080124D4 @ =0x08704D90\n\
	adds r1, r1, r5\n\
	mov r2, r8\n\
	ldr r0, [r2]\n\
	adds r0, r0, r1\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	bl RequestGraphicTransfer\n\
	ldrh r0, [r4]\n\
	movs r1, #3\n\
	bl __udivsi3\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x16\n\
	ands r0, r6\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r5\n\
	mov r3, r8\n\
	ldr r0, [r3]\n\
	adds r0, r0, r1\n\
	adds r0, #0xc\n\
	movs r1, #0\n\
	bl LoadPalette\n\
_08012402:\n\
	ldrb r1, [r7]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08012452\n\
	ldr r0, _080124C8 @ =gStageTilesetOffsets+(18*4)\n\
	mov r8, r0\n\
	ldr r4, _080124CC @ =gOverworld\n\
	ldr r1, _080124D8 @ =0x0002D03E\n\
	adds r4, r4, r1\n\
	ldrh r0, [r4]\n\
	lsrs r0, r0, #7\n\
	movs r6, #3\n\
	ands r0, r6\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	ldr r5, _080124DC @ =0x08704EA8\n\
	adds r1, r1, r5\n\
	mov r2, r8\n\
	ldr r0, [r2]\n\
	adds r0, r0, r1\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	bl RequestGraphicTransfer\n\
	ldrh r0, [r4]\n\
	lsrs r0, r0, #7\n\
	ands r0, r6\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r5\n\
	mov r3, r8\n\
	ldr r0, [r3]\n\
	adds r0, r0, r1\n\
	adds r0, #0xc\n\
	movs r1, #0\n\
	bl LoadPalette\n\
_08012452:\n\
	ldrb r1, [r7]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080124AE\n\
	movs r1, #0\n\
	ldr r0, _080124CC @ =gOverworld\n\
	ldr r2, _080124E0 @ =0x0002D035\n\
	adds r0, r0, r2\n\
	ldr r2, _080124E4 @ =0x0834283C\n\
	ldrb r0, [r0]\n\
	ldrb r3, [r2]\n\
	cmp r0, r3\n\
	bls _08012486\n\
	adds r3, r2, #0\n\
	adds r2, r0, #0\n\
_08012472:\n\
	lsls r0, r1, #0x18\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x11\n\
	adds r0, r0, r1\n\
	lsrs r1, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	adds r0, r0, r3\n\
	ldrb r0, [r0]\n\
	cmp r2, r0\n\
	bhi _08012472\n\
_08012486:\n\
	ldr r5, _080124C8 @ =gStageTilesetOffsets+(18*4)\n\
	lsls r0, r1, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r4, r0, #2\n\
	adds r4, r4, r0\n\
	lsls r4, r4, #2\n\
	ldr r2, _080124E8 @ =0x08704CDC\n\
	adds r4, r4, r2\n\
	ldr r0, [r5]\n\
	adds r0, r0, r4\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	bl RequestGraphicTransfer\n\
	ldr r0, [r5]\n\
	adds r0, r0, r4\n\
	adds r0, #0xc\n\
	movs r1, #0\n\
	bl LoadPalette\n\
_080124AE:\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080124BC: .4byte 0x08704C3C\n\
_080124C0: .4byte 0x08704C48\n\
_080124C4: .4byte gCurStory\n\
_080124C8: .4byte gStageTilesetOffsets+(18*4)\n\
_080124CC: .4byte gOverworld\n\
_080124D0: .4byte 0x0002D03C\n\
_080124D4: .4byte 0x08704D90\n\
_080124D8: .4byte 0x0002D03E\n\
_080124DC: .4byte 0x08704EA8\n\
_080124E0: .4byte 0x0002D035\n\
_080124E4: .4byte 0x0834283C\n\
_080124E8: .4byte 0x08704CDC\n\
 .syntax divided\n");
}

static void FUN_080124ec(struct Coord* _ UNUSED) {
  ClearBlink(192);
  ClearBlink(193);
  ClearBlink(194);
  ClearBlink(196);
  ClearBlink(197);
  ClearBlink(198);
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void LayerUpdate_2(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerUpdate_3(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerDraw_3(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerUpdate_4(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerDraw_4(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerExit_4(struct StageLayer* l, const struct Stage* _ UNUSED);
void FUN_080128bc(struct StageLayer* l, const struct Stage* stage);
void FUN_08012924(struct StageLayer* l, const struct Stage* stage);
void FUN_08012988(struct StageLayer* l, const struct Stage* stage);
void FUN_08012a00(struct StageLayer* l, const struct Stage* stage);

// clang-format off
static const StageLayerRoutine sLayerRoutine[7] = {
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
      [LAYER_UPDATE] = LayerUpdate_2,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
    [3] = {
      [LAYER_UPDATE] = LayerUpdate_3,
      [LAYER_DRAW]   = LayerDraw_3,
      [LAYER_EXIT]   = NULL,
    },
    [4] = {
      [LAYER_UPDATE] = LayerUpdate_4,
      [LAYER_DRAW]   = LayerDraw_4,
      [LAYER_EXIT]   = LayerExit_4,
    },
    [5] = {
      [LAYER_UPDATE] = FUN_080128bc,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = FUN_08012924,
    },
    [6] = {
      [LAYER_UPDATE] = FUN_08012988,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = FUN_08012a00,
    },
};
// clang-format on

static u8 FUN_08012518(struct Coord* pixels) {
  if (pixels->x < 960) {
    if (pixels->y < 448) {
      return 6;
    }
    if (pixels->y < 608) {
      return 0;
    }
  }

  if (pixels->x < 1680) {
    if (pixels->y >= 288) {
      return 1;
    }
  }

  if (pixels->x < 2400) {
    return 2;
  }

  if (pixels->x < 3248) {
    return 3;
  }

  if (pixels->x < 3968) {
    return 6;
  }

  if (pixels->x < 5040) {
    if (pixels->y >= 608) {
      return 4;
    }
  }

  if (pixels->x < 5168) {
    return 5;
  }

  return 6;
}

static void LayerUpdate_2(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    const u16 n = l->bgIdx;
    BGCNT16(n >> 4) &= 0xFFFC;
    BGCNT16(n >> 4) |= 3;
    (l->scrollPower).x = 0xC0;
    l->phase++;
  }

  if ((l->viewportCenterPixel).x < 2160) {
    (l->scroll).x = 420;
  } else {
    (l->scroll).x = 600;
  }
}

static void LayerUpdate_3(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    const u16 n = l->bgIdx;
    BGCNT16(n >> 4) = l->screenBase | 0x47;
    LoadBgMap(n, gBgMapOffsets, 79, 0, 0);
    l->phase++;
  }
}

NAKED static void LayerDraw_3(struct StageLayer* l, const struct Stage* _ UNUSED) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r7, r0, #0\n\
	ldr r1, [r7, #0x5c]\n\
	lsls r1, r1, #0x10\n\
	ldr r0, [r7, #0x34]\n\
	lsls r0, r0, #0xf\n\
	lsrs r5, r0, #0x10\n\
	ldr r0, [r7, #0x38]\n\
	subs r0, #0xe0\n\
	lsls r0, r0, #0x10\n\
	lsrs r4, r0, #0x10\n\
	lsrs r1, r1, #0x14\n\
	lsls r1, r1, #2\n\
	ldr r0, _080126F8 @ =gVideoRegBuffer+12\n\
	adds r2, r1, r0\n\
	strh r5, [r2]\n\
	adds r0, #2\n\
	adds r1, r1, r0\n\
	strh r4, [r1]\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #2\n\
	bl Malloc\n\
	adds r6, r0, #0\n\
	cmp r6, #0\n\
	beq _080126F0\n\
	ldr r2, _080126FC @ =gIntrManager\n\
	movs r1, #0xba\n\
	lsls r1, r1, #1\n\
	adds r0, r2, r1\n\
	str r6, [r0]\n\
	movs r0, #0xbc\n\
	lsls r0, r0, #1\n\
	adds r1, r2, r0\n\
	ldr r0, _08012700 @ =0x04000018\n\
	str r0, [r1]\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r2, r0\n\
	ldr r0, _08012704 @ =0xA6600001\n\
	str r0, [r1]\n\
	movs r2, #0\n\
	lsls r3, r4, #0x10\n\
	asrs r0, r3, #0x10\n\
	mov ip, r3\n\
	cmp r0, #0x37\n\
	bgt _080126CE\n\
	adds r4, r5, #0\n\
	adds r5, r6, #0\n\
_080126BA:\n\
	asrs r1, r3, #0x10\n\
	adds r0, r3, #0\n\
	orrs r0, r4\n\
	stm r5!, {r0}\n\
	adds r2, #1\n\
	adds r1, r1, r2\n\
	cmp r1, #0x37\n\
	bgt _080126CE\n\
	cmp r2, #0x9f\n\
	ble _080126BA\n\
_080126CE:\n\
	cmp r2, #0x9f\n\
	bgt _080126F0\n\
	mov r4, ip\n\
	ldr r5, _08012708 @ =0x0000FFFF\n\
	lsls r0, r2, #2\n\
	adds r3, r0, r6\n\
_080126DA:\n\
	ldr r1, [r7, #0x34]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #6\n\
	asrs r0, r0, #8\n\
	ands r0, r5\n\
	orrs r0, r4\n\
	stm r3!, {r0}\n\
	adds r2, #1\n\
	cmp r2, #0x9f\n\
	ble _080126DA\n\
_080126F0:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080126F8: .4byte gVideoRegBuffer+12\n\
_080126FC: .4byte gIntrManager\n\
_08012700: .4byte 0x04000018\n\
_08012704: .4byte 0xA6600001\n\
_08012708: .4byte 0x0000FFFF\n\
 .syntax divided\n");
}

static void LayerUpdate_4(struct StageLayer* l, const struct Stage* _ UNUSED) {
  u8 bit;

  if (l->phase == 0) {
    const u16 n = l->bgIdx;
    BGCNT16(n >> 4) = l->screenBase | 0x44;
    LoadBgMap(n, gBgMapOffsets, 80, 0, 0);
    gBlendRegBuffer.bldclt = 0x3B44;
    l->unk_10 = 64;
    l->unk_12 = 0;
    l->phase++;
  }

  bit = FUN_08012518(&l->viewportCenterPixel);
  if ((gCurStory.unk_54 >> bit) & 1) {
    if (l->unk_10 < 64) {
      l->unk_10++;
    }
  } else if (32 < l->unk_10) {
    l->unk_10--;
  }
  gBlendRegBuffer.bldalpha = BLDALPHA_BLEND(0, l->unk_10 >> 2);

  if ((TILESET_ID(1) == STAGE_E_FACILITY) && (TILESET_IDX(1) == 4)) {
    if ((gCurStory.unk_54 >> bit) & 1) {
      if (!(l->unk_12 & (1 << 0))) {
        l->unk_12 |= (1 << 0);
        ClearBlink(243);
        LoadBlink(191, 0);
      }
    } else {
      if (l->unk_12 & (1 << 0)) {
        l->unk_12 &= 0xFE;
        ClearBlink(191);
        LoadBlink(243, 0);
      }
    }
  } else {
    l->unk_12 &= 0xFE;
    ClearBlink(191);
    ClearBlink(243);
  }

  if ((TILESET_ID(0) == STAGE_E_FACILITY) && (TILESET_IDX(0) == 0)) {
    if ((gCurStory.unk_54 & (1 << 1)) && !(l->unk_12 & (1 << 1))) {
      l->unk_12 |= (1 << 1);
      LoadBlink(195, 0);
    }
  } else {
    l->unk_12 &= 0xFD;
    ClearBlink(195);
  }

  UpdateBlinkMotionState(191);
  UpdateBlinkMotionState(195);
  UpdateBlinkMotionState(243);
}

static void LayerDraw_4(struct StageLayer* l, const struct Stage* _ UNUSED) {
  // nop
  return;
}

static void LayerExit_4(struct StageLayer* l, const struct Stage* _ UNUSED) {
  gBlendRegBuffer.bldclt = 0;
  ClearBlink(191);
  ClearBlink(195);
  ClearBlink(243);
}

INCASM("asm/stage_gfx/energy_facility.inc");

// ------------------------------------------------------------------------------------------------------------------------------------

extern const struct ScreenMap sScreenMap1;
INCBIN_STATIC(sScreenMap1, "data/stage/energy_facility/layer1.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08341e6c 0x08341ff0 ./data/stage/energy_facility/layer1.bin

extern const struct ScreenMap sScreenMap2;
INCBIN_STATIC(sScreenMap2, "data/stage/energy_facility/layer2.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08341ff0 0x08342174 ./data/stage/energy_facility/layer2.bin

extern const struct ScreenMap sScreenMap3;
INCBIN_STATIC(sScreenMap3, "data/stage/energy_facility/layer3.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08342174 0x083422f8 ./data/stage/energy_facility/layer3.bin

extern const tileset_ofs_t sTilesetOffset[];
INCBIN_STATIC(sTilesetOffset, "data/stage/energy_facility/tileset_offset.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x083422f8 0x0834247c ./data/stage/energy_facility/tileset_offset.bin

extern const u16 sScreenBehavior[];
INCBIN_STATIC(sScreenBehavior, "data/stage/energy_facility/screen_behavior.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x0834247c 0x08342784 ./data/stage/energy_facility/screen_behavior.bin

// clang-format off
static const struct Coord Coord_ARRAY_08342784[6] = {
    {0x24800,  0x1F800},
    {0x52800,  0x29800},
    {0x7F800,  0xB800},
    {0xBA800,  0xB800},
    {0x124800, 0x29800},
    {0x133800, 0x15800},
};
// clang-format on

static const struct Coord Coord_083427b4 = {0x8E800, 0xD800};

const struct Stage gEnergyFacilityLandscape = {
  id : STAGE_E_FACILITY,
  fn : sStageRoutine,
  terrainHdr : &gStageTerrains[STAGE_E_FACILITY],
  maps : {&sScreenMap1, &sScreenMap2, &sScreenMap3},
  bgIdx : {USE_BG1, USE_BG2, USE_BG3},
  prio : {2, 1, 1},
  screenBase : {BGMAP_BLOCK(2), BGMAP_BLOCK(4), BGMAP_BLOCK(6)},
  scrollPower : {{0x100, 0x100}, {0x100, 0x100}, {0x100, 0x100}},
  scroll : {{0, 0}, {0, 0}, {0, 0}},
  tilesetOffset : sTilesetOffset,
  bgFns : sLayerRoutine,
  behavior : sScreenBehavior,
  unk_78 : {0x0, 0x0},
};

const u8 u8_ARRAY_0834283c[9] = {
    6, 12, 18, 24, 42, 72, 78, 90, 100,
};
