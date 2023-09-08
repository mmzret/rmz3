#include "blink.h"
#include "global.h"
#include "overworld.h"

static void initAreaX2(struct Coord* _ UNUSED);
static void FUN_080115b8(struct Coord* _ UNUSED);
static void nop_0801179c(struct Coord* _ UNUSED);
static void exitAreaX2(struct Coord* _ UNUSED);

static const StageFunc sStageRoutine[4] = {
    initAreaX2,
    FUN_080115b8,
    nop_0801179c,
    exitAreaX2,
};

static void initAreaX2(struct Coord* _ UNUSED) {
  gOverworld.work.areaX2.unk_008 = 0;
  gOverworld.work.areaX2.unk_000 = 0;
  gOverworld.work.areaX2.unk_002 = 0;
  gOverworld.unk_1c8.work[0] = 0;
  gOverworld.work.areaX2.unk_004[0] = 0;
  gOverworld.work.areaX2.unk_004[1] = 0;
  LoadBlink(0x22, 0);
  LoadBlink(0x23, 0);
  LoadBlink(0x24, 0);
  LoadBlink(0x25, 0);
  LoadBlink(0x8f, 0);
  LoadBlink(0x90, 0);
}

static void FUN_080115b8(struct Coord* _ UNUSED) {
  gOverworld.work.areaX2.unk_008++;
  gOverworld.work.areaX2.unk_002++;

  if ((TILESET_ID(1) == STAGE_AREA_X2) && (TILESET_IDX(1) == 1)) {
    if ((gOverworld.work.areaX2.unk_000 & (1 << 0)) == 0) {
      gOverworld.work.areaX2.unk_000 |= (1 << 0);
      LoadBlink(32, 0);
      LoadBlink(33, 0);
      LoadBlink(38, 0);
      LoadBlink(39, 0);
      LoadBlink(40, 0);
      LoadBlink(142, 0);
    }
    GetBlinkMotionState(32);
    GetBlinkMotionState(33);
    GetBlinkMotionState(38);
    GetBlinkMotionState(39);
    GetBlinkMotionState(40);
    GetBlinkMotionState(142);

  } else if ((gOverworld.work.areaX2.unk_000 & (1 << 0))) {
    gOverworld.work.areaX2.unk_000 ^= (1 << 0);
    ClearBlink(32);
    ClearBlink(33);
    ClearBlink(38);
    ClearBlink(39);
    ClearBlink(40);
    ClearBlink(142);
  }

  if ((TILESET_ID(1) == STAGE_AREA_X2) && (TILESET_IDX(1) == 2)) {
    if ((gOverworld.work.areaX2.unk_000 & (1 << 1)) == 0) {
      gOverworld.work.areaX2.unk_000 |= (1 << 1);
      LoadBlink(147, 0);
    }
    GetBlinkMotionState(147);

  } else if ((gOverworld.work.areaX2.unk_000 & (1 << 1))) {
    gOverworld.work.areaX2.unk_000 ^= (1 << 1);
    ClearBlink(147);
  }

  if ((TILESET_ID(1) == STAGE_AREA_X2) && (TILESET_IDX(1) == 3)) {
    if ((gOverworld.work.areaX2.unk_000 & (1 << 2)) == 0) {
      gOverworld.work.areaX2.unk_000 |= (1 << 2);
      LoadBlink(145, 0);
      LoadBlink(146, 0);
    }
    GetBlinkMotionState(145);
    GetBlinkMotionState(146);

  } else if ((gOverworld.work.areaX2.unk_000 & (1 << 2))) {
    gOverworld.work.areaX2.unk_000 ^= (1 << 2);
    ClearBlink(145);
    ClearBlink(146);
  }

  GetBlinkMotionState(34);
  GetBlinkMotionState(35);
  GetBlinkMotionState(36);
  GetBlinkMotionState(37);
  GetBlinkMotionState(143);
  GetBlinkMotionState(144);
}

static void nop_0801179c(struct Coord* _ UNUSED) {
  // Nop
  return;
}

static void exitAreaX2(struct Coord* _ UNUSED) {
  ClearBlink(32);
  ClearBlink(33);
  ClearBlink(34);
  ClearBlink(35);
  ClearBlink(36);
  ClearBlink(37);
  ClearBlink(38);
  ClearBlink(39);
  ClearBlink(40);
  ClearBlink(142);
  ClearBlink(143);
  ClearBlink(144);
  ClearBlink(145);
  ClearBlink(146);
  ClearBlink(147);
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void LayerUpdate_2(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerDraw_2(struct StageLayer* l, const struct Stage* stage);
static void LayerExit_2(struct StageLayer* l UNUSED, const struct Stage* _ UNUSED);
static void LayerUpdate_3(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerDraw_3(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerUpdate_4(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerUpdate_5(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerUpdate_6(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerExit_6(struct StageLayer* l UNUSED, const struct Stage* _ UNUSED);

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
      [LAYER_DRAW]   = LayerDraw_2,
      [LAYER_EXIT]   = LayerExit_2,
    },
    [3] = {
      [LAYER_UPDATE] = LayerUpdate_3,
      [LAYER_DRAW]   = LayerDraw_3,
      [LAYER_EXIT]   = NULL,
    },
    [4] = {
      [LAYER_UPDATE] = LayerUpdate_4,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
    [5] = {
      [LAYER_UPDATE] = LayerUpdate_5,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
    [6] = {
      [LAYER_UPDATE] = LayerUpdate_6,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = LayerExit_6,
    },
};
// clang-format on

static void LayerUpdate_2(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    gBlendRegBuffer.bldclt = 0x2844;
    l->phase++;
  }
}

WIP static void LayerDraw_2(struct StageLayer* l, const struct Stage* stage) {
#if MODERN
  u16 eva;
  u32 n = (gOverworld.work.areaX2.unk_002 & 0xFF);
  if (n < 64) {
    eva = 0;
  } else if (n < 128) {
    eva = (n - 64) >> 2;
  } else if (n < 192) {
    eva = 16;
  } else {
    eva = 16 - ((n - 192) >> 2);
  }
  gBlendRegBuffer.bldalpha = (eva & 0x1F) | ((16 - eva) << 8);
  DrawGeneralStageLayer(l, stage);
#else
  INCCODE("asm/wip/LayerDraw_2_AreaX2.inc")
#endif
}

static void LayerExit_2(struct StageLayer* l UNUSED, const struct Stage* _ UNUSED) {
  gBlendRegBuffer.bldclt = 0;
  return;
}

static void LayerUpdate_3(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    const u16 n = l->bgIdx;
    BGCNT16(n >> 4) = l->prio | l->screenBase | 0x44;
    *(u32*)gVideoRegBuffer.bgofs[n >> 4] = 0;
    CpuFastCopy(BGMAP(66), (void*)(VRAM + SCREEN_BASE_16(n >> 4)), 2048);
    l->unk_10 = 0;
    l->phase++;
  }
  l->unk_10++;
}

NAKED static void LayerDraw_3(struct StageLayer* l, const struct Stage* _ UNUSED) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	mov r8, r0\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #2\n\
	bl Malloc\n\
	mov sl, r0\n\
	cmp r0, #0\n\
	bne _08011914\n\
	b _08011A62\n\
_08011914:\n\
	ldr r2, _08011A70 @ =gIntrManager\n\
	movs r1, #0xba\n\
	lsls r1, r1, #1\n\
	adds r0, r2, r1\n\
	mov r3, sl\n\
	str r3, [r0]\n\
	movs r0, #0xbc\n\
	lsls r0, r0, #1\n\
	adds r1, r2, r0\n\
	ldr r0, _08011A74 @ =0x0400001C\n\
	str r0, [r1]\n\
	movs r3, #0xbe\n\
	lsls r3, r3, #1\n\
	adds r1, r2, r3\n\
	ldr r0, _08011A78 @ =0xA6600001\n\
	str r0, [r1]\n\
	mov r0, r8\n\
	ldrh r1, [r0, #0x10]\n\
	ldr r0, [r0, #0x34]\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0xd\n\
	lsrs r7, r0, #0x10\n\
	mov r1, r8\n\
	ldr r0, [r1, #0x38]\n\
	ldr r2, _08011A7C @ =0xFFFFFAB0\n\
	adds r1, r0, r2\n\
	lsls r1, r1, #0xe\n\
	lsrs r6, r1, #0x10\n\
	ldr r3, _08011A80 @ =0xFFFFFBF0\n\
	adds r0, r0, r3\n\
	movs r1, #7\n\
	bl __divsi3\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	mov sb, r1\n\
	asrs r5, r0, #0x10\n\
	lsls r0, r6, #0x10\n\
	asrs r0, r0, #0x10\n\
	subs r0, r5, r0\n\
	adds r0, #0x94\n\
	lsls r0, r0, #8\n\
	movs r1, #0x94\n\
	bl __divsi3\n\
	ldr r2, _08011A84 @ =0xFFFFFF00\n\
	adds r6, r0, r2\n\
	movs r4, #0x9f\n\
	adds r0, r5, #0\n\
	adds r0, #0x9f\n\
	cmp r0, #0x87\n\
	ble _080119A4\n\
	adds r3, r0, #0\n\
	subs r0, #0x88\n\
	movs r2, #0x9f\n\
	lsls r2, r2, #2\n\
	add r2, sl\n\
	adds r1, r0, #0\n\
	muls r1, r6, r1\n\
_0801198A:\n\
	asrs r0, r1, #8\n\
	subs r0, r5, r0\n\
	lsls r0, r0, #0x10\n\
	orrs r0, r7\n\
	str r0, [r2]\n\
	subs r3, #1\n\
	subs r1, r1, r6\n\
	subs r2, #4\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	blt _080119A4\n\
	cmp r3, #0x87\n\
	bgt _0801198A\n\
_080119A4:\n\
	mov r3, r8\n\
	ldrh r1, [r3, #0x10]\n\
	ldr r0, [r3, #0x34]\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0xc\n\
	lsrs r7, r0, #0x10\n\
	mov r6, sb\n\
	ldr r0, [r3, #0x38]\n\
	ldr r1, _08011A88 @ =0xFFFFFC40\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0xd\n\
	lsrs r2, r0, #0x10\n\
	mov sb, r2\n\
	asrs r5, r0, #0x10\n\
	lsls r0, r6, #0x10\n\
	asrs r0, r0, #0x10\n\
	subs r0, r5, r0\n\
	adds r0, #0x18\n\
	lsls r0, r0, #8\n\
	movs r1, #0x18\n\
	bl __divsi3\n\
	ldr r3, _08011A84 @ =0xFFFFFF00\n\
	adds r6, r0, r3\n\
	cmp r4, #0\n\
	blt _08011A08\n\
	adds r0, r4, r5\n\
	cmp r0, #0x75\n\
	ble _08011A08\n\
	adds r3, r0, #0\n\
	adds r0, r4, #0\n\
	subs r0, #0x76\n\
	adds r0, r0, r5\n\
	lsls r1, r4, #2\n\
	add r1, sl\n\
	adds r2, r0, #0\n\
	muls r2, r6, r2\n\
_080119EE:\n\
	asrs r0, r2, #8\n\
	subs r0, r5, r0\n\
	lsls r0, r0, #0x10\n\
	orrs r0, r7\n\
	str r0, [r1]\n\
	subs r3, #1\n\
	subs r2, r2, r6\n\
	subs r1, #4\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	blt _08011A08\n\
	cmp r3, #0x75\n\
	bgt _080119EE\n\
_08011A08:\n\
	mov r0, r8\n\
	ldrh r1, [r0, #0x10]\n\
	ldr r0, [r0, #0x34]\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0xb\n\
	lsrs r7, r0, #0x10\n\
	mov r6, sb\n\
	cmp r4, #0\n\
	blt _08011A40\n\
	lsls r0, r6, #0x10\n\
	asrs r2, r0, #0x10\n\
	adds r0, r4, r2\n\
	cmp r0, #0x6f\n\
	ble _08011A40\n\
	lsls r0, r4, #2\n\
	mov r3, sl\n\
	adds r1, r0, r3\n\
	adds r3, r2, #0\n\
	lsls r2, r3, #0x10\n\
	orrs r2, r7\n\
_08011A30:\n\
	str r2, [r1]\n\
	subs r1, #4\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	blt _08011A40\n\
	adds r0, r4, r3\n\
	cmp r0, #0x6f\n\
	bgt _08011A30\n\
_08011A40:\n\
	mov r1, r8\n\
	ldr r0, [r1, #0x34]\n\
	ldr r2, _08011A8C @ =0xFFFFF100\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #0xd\n\
	lsrs r7, r0, #0x10\n\
	cmp r4, #0\n\
	blt _08011A62\n\
	lsls r1, r6, #0x10\n\
	orrs r1, r7\n\
	lsls r0, r4, #2\n\
	add r0, sl\n\
_08011A58:\n\
	str r1, [r0]\n\
	subs r0, #4\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	bge _08011A58\n\
_08011A62:\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08011A70: .4byte gIntrManager\n\
_08011A74: .4byte 0x0400001C\n\
_08011A78: .4byte 0xA6600001\n\
_08011A7C: .4byte 0xFFFFFAB0\n\
_08011A80: .4byte 0xFFFFFBF0\n\
_08011A84: .4byte 0xFFFFFF00\n\
_08011A88: .4byte 0xFFFFFC40\n\
_08011A8C: .4byte 0xFFFFF100\n\
 .syntax divided\n");
}

static void LayerUpdate_4(struct StageLayer* l, const struct Stage* _ UNUSED) {
  const u16 n = l->bgIdx;
  switch (l->phase) {
    case 0: {
      BGCNT16(n >> 4) &= 0xFFFC;
      BGCNT16(n >> 4) |= 3;
      l->phase++;
      FALLTHROUGH;
    }
    case 1: {
      if (gOverworld.unk_1c8.work[0] == 3) {
        LoadScreenIntoMetatileMap(17, 1, 60);
        LoadScreenIntoMetatileMap(18, 1, 61);
        LoadScreenIntoMetatileMap(17, 2, 76);
        LoadScreenIntoMetatileMap(18, 2, 77);
        l->phase = 4;
        break;
      }
      if (gOverworld.unk_1c8.work[0] == 0) {
        break;
      }

      gOverworld.work.areaX2.unk_004[0] = 1;
      l->phase++;
      FALLTHROUGH;
    }
    case 2: {
      if (gOverworld.work.areaX2.unk_004[0] == 0) {
        LoadScreenIntoMetatileMap(17, 1, 60);
        LoadScreenIntoMetatileMap(18, 1, 61);
        LoadScreenIntoMetatileMap(17, 2, 76);
        LoadScreenIntoMetatileMap(18, 2, 77);
        gOverworld.work.areaX2.unk_004[0] = 1;
        l->phase++;
      }
      break;
    }
    case 3: {
      if (gOverworld.unk_1c8.work[0] == 2) {
        gOverworld.work.areaX2.unk_004[1] = 1;
        l->phase++;
      }
      break;
    }
  }
}

static void LayerUpdate_5(struct StageLayer* l, const struct Stage* _ UNUSED) {
  switch (l->phase) {
    case 0: {
      if (gOverworld.unk_1c8.work[0] == 3) {
        (l->scroll).y = -180;
        l->phase = 2;
        return;
      }
      if (gOverworld.work.areaX2.unk_004[1] == 0) {
        return;
      }
      PlaySound(SE_UNK_e0);
      l->unk_10 = 0;
      l->phase++;
      FALLTHROUGH;
    }
    case 1: {
      l->unk_10++;
      (l->scroll).y = -l->unk_10;
      if (l->unk_10 >= 180) {
        stopSound(SE_UNK_e0);
        l->phase++;
      }
      break;
    }
  }
}

NAKED static void LayerUpdate_6(struct StageLayer* l, const struct Stage* _ UNUSED) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r5, r0, #0\n\
	ldr r0, [r5, #0x5c]\n\
	lsls r0, r0, #0x10\n\
	lsrs r3, r0, #0x10\n\
	ldrb r0, [r5, #0xe]\n\
	cmp r0, #4\n\
	bls _08011C1A\n\
	b _08011D48\n\
_08011C1A:\n\
	lsls r0, r0, #2\n\
	ldr r1, _08011C24 @ =_08011C28\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_08011C24: .4byte _08011C28\n\
_08011C28: @ jump table\n\
	.4byte _08011C3C @ case 0\n\
	.4byte _08011C62 @ case 1\n\
	.4byte _08011CC0 @ case 2\n\
	.4byte _08011CFC @ case 3\n\
	.4byte _08011D38 @ case 4\n\
_08011C3C:\n\
	lsrs r2, r3, #4\n\
	lsls r2, r2, #1\n\
	ldr r0, _08011C94 @ =gVideoRegBuffer+4\n\
	adds r2, r2, r0\n\
	ldrh r1, [r2]\n\
	ldr r0, _08011C98 @ =0x0000FFFC\n\
	ands r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r1, _08011C9C @ =gBlendRegBuffer\n\
	ldr r0, _08011CA0 @ =0x00003748\n\
	strh r0, [r1]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #5\n\
	strh r0, [r1, #2]\n\
	ldrb r0, [r5, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xe]\n\
_08011C62:\n\
	ldr r1, _08011CA4 @ =gOverworld\n\
	ldr r2, _08011CA8 @ =0x0002D024\n\
	adds r0, r1, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _08011CAC\n\
	movs r1, #0\n\
	str r1, [r5, #0x44]\n\
	str r1, [r5, #0x48]\n\
	movs r0, #0xf0\n\
	str r0, [r5, #0x4c]\n\
	ldr r0, _08011C9C @ =gBlendRegBuffer\n\
	strh r1, [r0]\n\
	lsrs r2, r3, #4\n\
	lsls r2, r2, #1\n\
	ldr r0, _08011C94 @ =gVideoRegBuffer+4\n\
	adds r2, r2, r0\n\
	ldrh r1, [r2]\n\
	ldr r0, _08011C98 @ =0x0000FFFC\n\
	ands r0, r1\n\
	movs r1, #3\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #5\n\
	b _08011D46\n\
	.align 2, 0\n\
_08011C94: .4byte gVideoRegBuffer+4\n\
_08011C98: .4byte 0x0000FFFC\n\
_08011C9C: .4byte gBlendRegBuffer\n\
_08011CA0: .4byte 0x00003748\n\
_08011CA4: .4byte gOverworld\n\
_08011CA8: .4byte 0x0002D024\n\
_08011CAC:\n\
	ldr r2, _08011CF0 @ =0x0002D02C\n\
	adds r0, r1, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _08011D48\n\
	movs r0, #0\n\
	strh r0, [r5, #0x10]\n\
	ldrb r0, [r5, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xe]\n\
_08011CC0:\n\
	ldrh r1, [r5, #0x10]\n\
	adds r1, #1\n\
	strh r1, [r5, #0x10]\n\
	ldr r4, _08011CF4 @ =gBlendRegBuffer\n\
	lsls r1, r1, #0x10\n\
	lsrs r3, r1, #0x10\n\
	lsrs r1, r1, #0x12\n\
	movs r0, #0x1f\n\
	adds r2, r1, #0\n\
	ands r2, r0\n\
	movs r0, #0x10\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #8\n\
	orrs r2, r0\n\
	strh r2, [r4, #2]\n\
	cmp r3, #0x3f\n\
	bls _08011D48\n\
	ldr r0, _08011CF8 @ =gOverworld\n\
	ldr r1, _08011CF0 @ =0x0002D02C\n\
	adds r0, r0, r1\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	b _08011D42\n\
	.align 2, 0\n\
_08011CF0: .4byte 0x0002D02C\n\
_08011CF4: .4byte gBlendRegBuffer\n\
_08011CF8: .4byte gOverworld\n\
_08011CFC:\n\
	ldr r0, _08011D24 @ =gOverworld\n\
	ldr r2, _08011D28 @ =0x0002D02C\n\
	adds r0, r0, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _08011D48\n\
	ldr r1, _08011D2C @ =gBlendRegBuffer\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	lsrs r2, r3, #4\n\
	lsls r2, r2, #1\n\
	ldr r0, _08011D30 @ =gVideoRegBuffer+4\n\
	adds r2, r2, r0\n\
	ldrh r1, [r2]\n\
	ldr r0, _08011D34 @ =0x0000FFFC\n\
	ands r0, r1\n\
	movs r1, #3\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	b _08011D42\n\
	.align 2, 0\n\
_08011D24: .4byte gOverworld\n\
_08011D28: .4byte 0x0002D02C\n\
_08011D2C: .4byte gBlendRegBuffer\n\
_08011D30: .4byte gVideoRegBuffer+4\n\
_08011D34: .4byte 0x0000FFFC\n\
_08011D38:\n\
	movs r0, #0\n\
	str r0, [r5, #0x44]\n\
	str r0, [r5, #0x48]\n\
	movs r0, #0xf0\n\
	str r0, [r5, #0x4c]\n\
_08011D42:\n\
	ldrb r0, [r5, #0xe]\n\
	adds r0, #1\n\
_08011D46:\n\
	strb r0, [r5, #0xe]\n\
_08011D48:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
 .syntax divided\n");
}

static void LayerExit_6(struct StageLayer* l UNUSED, const struct Stage* _ UNUSED) {
  gBlendRegBuffer.bldclt = 0;
  return;
}

// ------------------------------------------------------------------------------------------------------------------------------------

extern const struct ScreenLayout sScreenMap1;
INCBIN_STATIC(sScreenMap1, "data/stage/area_x2/layer1.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08340ff0 0x08341234 ./data/stage/area_x2/layer1.bin

extern const struct ScreenLayout sScreenMap2;
INCBIN_STATIC(sScreenMap2, "data/stage/area_x2/layer2.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08341234 0x08341478 ./data/stage/area_x2/layer2.bin

extern const struct ScreenLayout sScreenMap3;
INCBIN_STATIC(sScreenMap3, "data/stage/area_x2/layer3.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08341478 0x083416bc ./data/stage/area_x2/layer3.bin

extern const tileset_ofs_t sTilesetOffset[];
INCBIN_STATIC(sTilesetOffset, "data/stage/area_x2/tileset_offset.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x083416bc 0x08341900 ./data/stage/area_x2/tileset_offset.bin

extern const u16 sScreenBehavior[];
INCBIN_STATIC(sScreenBehavior, "data/stage/area_x2/screen_behavior.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08341900 0x08341d88 ./data/stage/area_x2/screen_behavior.bin

const struct Stage gAreaX2Landscape = {
  id : STAGE_AREA_X2,
  fn : sStageRoutine,
  terrainHdr : &gStageTerrains[STAGE_AREA_X2],
  maps : {&sScreenMap1, &sScreenMap2, &sScreenMap3},
  bgIdx : {USE_BG1, USE_BG2, USE_BG3},
  prio : {2, 3, 3},
  screenBase : {BGMAP_BLOCK(2), BGMAP_BLOCK(4), BGMAP_BLOCK(6)},
  scrollPower : {{0x100, 0x100}, {0x100, 0x100}, {0x100, 0x100}},
  scroll : {{0, 0}, {0, 0}, {0, 0}},
  tilesetOffset : sTilesetOffset,
  bgFns : sLayerRoutine,
  behavior : sScreenBehavior,
  unk_78 : {0x0, 0x0},
};
