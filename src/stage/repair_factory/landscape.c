#include "blink.h"
#include "gfx.h"
#include "global.h"
#include "mission.h"
#include "overworld.h"

#define STAGE (gOverworld.work.repairFactory)

static void initRepairFactory(struct Coord* _ UNUSED);
static void repairFactory_0800d6b4(struct Coord* c);
static void repairFactory_0800d8c0(struct Coord* _ UNUSED);
static void exitRepairFactory(struct Coord* _ UNUSED);

static const StageFunc sStageRoutine[4] = {
    initRepairFactory,
    repairFactory_0800d6b4,
    repairFactory_0800d8c0,
    exitRepairFactory,
};

static void initRepairFactory(struct Coord* _ UNUSED) {
  gOverworld.state[0] = 0;
  STAGE.unk_000 = 0;
  STAGE.unk_001 = 0;
  STAGE.unk_002 = 0;
  LoadBlink(0x2B, 0);
  LoadBlink(0x2C, 0);
}

static void repairFactory_0800d6b4(struct Coord* c) {
  if ((TILESET_ID(1) == STAGE_REPAIR_FACTORY) && (TILESET_IDX(1) == 1)) {
    if ((STAGE.unk_000 & (1 << 0)) == 0) {
      STAGE.unk_000 |= (1 << 0);
      LoadBlink(45, 0);
    }
    UpdateBlinkMotionState(45);

  } else if (STAGE.unk_000 & (1 << 0)) {
    STAGE.unk_000 ^= (1 << 0);
    ClearBlink(45);
  }

  if ((TILESET_ID(1) == STAGE_REPAIR_FACTORY) && (TILESET_IDX(1) == 4)) {
    if ((STAGE.unk_000 & (1 << 1)) == 0) {
      STAGE.unk_000 |= (1 << 1);
      LoadBlink(46, 0);
      LoadBlink(47, 0);
      LoadBlink(48, 0);
    }
    UpdateBlinkMotionState(46);
    UpdateBlinkMotionState(47);
    UpdateBlinkMotionState(48);

  } else if (STAGE.unk_000 & (1 << 1)) {
    STAGE.unk_000 ^= (1 << 1);
    ClearBlink(46);
    ClearBlink(47);
    ClearBlink(48);
  }

  UpdateBlinkMotionState(43);
  UpdateBlinkMotionState(44);

  if (gOverworld.state[0] == 0) {
    gOverworld.unk_2c004.x = -0x155;
    gOverworld.unk_2c004.y = 0x155;
    STAGE.unk_001++;
    if (STAGE.unk_001 == 6) {
      STAGE.unk_001 = gOverworld.state[0];
    }
  } else {
    gOverworld.unk_2c004.x = 0x155;
    gOverworld.unk_2c004.y = -0x155;
    STAGE.unk_001--;
    if (STAGE.unk_001 < 0) {
      STAGE.unk_001 = 5;
    }
  }

  STAGE.unk_002++;
  if (STAGE.unk_002 == 45) {
    STAGE.unk_002 = 0;
  }

  if ((c->x - 0x10D001U < 0x5AFFF) || ((c->x < 0x1E000 && (c->y < 0x14000)))) {
    if (!isSoundPlaying(SE_UNK_10b)) {
      PlaySound(SE_UNK_10b);
    }
    SetStageNoiseVolume(SE_UNK_10b);
  } else {
    if (isSoundPlaying(SE_UNK_10b)) {
      stopSound(SE_UNK_10b);
    }
  }
}

static void repairFactory_0800d8c0(struct Coord* _ UNUSED) {
  RequestGraphicTransfer(&(TILESETS(18, 33)[(STAGE.unk_001 << 1) / 3]).g, (void*)0x4000);
  LoadPalette(&(TILESETS(18, 33)[(STAGE.unk_001 << 1) / 3]).pal, 0);

  RequestGraphicTransfer(&(TILESETS(18, 37)[STAGE.unk_002 / 9]).g, (void*)0x4000);
  LoadPalette(&(TILESETS(18, 37)[STAGE.unk_002 / 9]).pal, 0);

  if ((TILESET_ID(1) == STAGE_REPAIR_FACTORY) && (TILESET_IDX(1) == 4)) {
    if ((gMission.unk_00)->missionDones & (1 << STAGE_MISSILE_FACTORY)) {
      RequestGraphicTransfer(&(TILESETS(18, 0)[92]).g, (void*)0x4000);
      LoadPalette(&(TILESETS(18, 0)[92]).pal, 0);
    }
  }
}

static void exitRepairFactory(struct Coord* _ UNUSED) {
  ClearBlink(43);
  ClearBlink(44);
  ClearBlink(45);
  ClearBlink(46);
  ClearBlink(47);
  ClearBlink(48);
  if (isSoundPlaying(SE_UNK_10b)) {
    stopSound(SE_UNK_10b);
  }
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void LayerUpdate_2(struct StageLayer* l, const struct Stage* stage);
static void LayerUpdate_3(struct StageLayer* l, const struct Stage* stage);

// clang-format off
static const StageLayerRoutine sLayerRoutine[4] = {
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
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
};
// clang-format on

static void LayerUpdate_2(struct StageLayer* l, const struct Stage* stage) {
  s32 x;

  if (l->phase == 0) {
    BGCNT16((l->bgIdx << 16) >> 20) = (BGCNT16((l->bgIdx << 16) >> 20) & 0xFFFC) | 2;
    (l->scrollPower).x = 0xC0;
    (l->scrollPower).y = 0xC0;
    l->phase++;
  }

  x = gScreenX[(l->viewportCenterPixel).x >> 4];
  if (x < 6) {
    (l->scrollPower).y = 0x100;
    (l->scroll).x = 120;
  } else if (x < 17) {
    (l->scroll).x = 960;
    (l->scroll).y = 200;
  } else if (x < 20) {
    (l->scroll).x = 1080;
    (l->scroll).y = 140;
  } else {
    (l->scroll).x = 1752;
    (l->scroll).y = 200;
  }
}

static void LayerUpdate_3(struct StageLayer* l, const struct Stage* stage) {
  s32 x = gScreenX[(l->viewportCenterPixel).x >> 4];
  if (x < 6) {
    (l->scrollPower).x = 0x40;
    (l->scrollPower).y = 0x100;
    (l->scroll).x = 360;
  } else if (x < 15) {
    (l->scroll).x = 1560;
    (l->scroll).y = 320;
  } else if (x < 17) {
    (l->scroll).x = 1920;
    (l->scroll).y = 400;
  } else if (x < 20) {
    (l->scroll).x = 2160;
    (l->scroll).y = 280;
  } else if (x < 28) {
    (l->scroll).x = 3000;
    (l->scroll).y = 400;
  } else {
    (l->scroll).x = 3504;
    (l->scroll).y = 400;
  }
}

// ------------------------------------------------------------------------------------------------------------------------------------

NAKED bool8 FUN_0800daec(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #8\n\
	adds r5, r0, #0\n\
	adds r6, r1, #0\n\
	ldr r0, _0800DB4C @ =0xFFF97000\n\
	adds r1, r5, r0\n\
	ldr r0, _0800DB50 @ =0x0001DFFF\n\
	cmp r1, r0\n\
	bhi _0800DB7A\n\
	ldr r0, _0800DB54 @ =0xFFFD8000\n\
	adds r7, r6, r0\n\
	ldr r0, _0800DB58 @ =0x00013FFF\n\
	cmp r7, r0\n\
	bhi _0800DB7A\n\
	ldr r2, _0800DB5C @ =gOverworld\n\
	movs r0, #0xfc\n\
	lsls r0, r0, #3\n\
	adds r2, r2, r0\n\
	ldrh r4, [r2]\n\
	asrs r0, r6, #0xc\n\
	adds r1, r4, #0\n\
	muls r1, r0, r1\n\
	asrs r3, r5, #0xc\n\
	adds r1, r1, r3\n\
	adds r1, #2\n\
	lsls r1, r1, #1\n\
	adds r1, r1, r2\n\
	asrs r0, r7, #0xc\n\
	muls r0, r4, r0\n\
	adds r0, r0, r3\n\
	adds r0, #2\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	ldrh r1, [r1]\n\
	ldrh r0, [r0]\n\
	cmp r1, r0\n\
	beq _0800DB7A\n\
	str r5, [sp]\n\
	str r6, [sp, #4]\n\
	ldr r0, _0800DB60 @ =0x00077FFF\n\
	cmp r5, r0\n\
	bgt _0800DB64\n\
	movs r0, #7\n\
	movs r1, #4\n\
	movs r2, #0x36\n\
	bl LoadScreenIntoMetatileMap\n\
	b _0800DB6E\n\
	.align 2, 0\n\
_0800DB4C: .4byte 0xFFF97000\n\
_0800DB50: .4byte 0x0001DFFF\n\
_0800DB54: .4byte 0xFFFD8000\n\
_0800DB58: .4byte 0x00013FFF\n\
_0800DB5C: .4byte gOverworld\n\
_0800DB60: .4byte 0x00077FFF\n\
_0800DB64:\n\
	movs r0, #8\n\
	movs r1, #4\n\
	movs r2, #0x37\n\
	bl LoadScreenIntoMetatileMap\n\
_0800DB6E:\n\
	movs r0, #8\n\
	mov r1, sp\n\
	bl AppendQuake\n\
	movs r0, #1\n\
	b _0800DB7C\n\
_0800DB7A:\n\
	movs r0, #0\n\
_0800DB7C:\n\
	add sp, #8\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

#undef STAGE

// ------------------------------------------------------------------------------------------------------------------------------------

#include "stage/repair_factory/layer.h"
//
#include "stage/repair_factory/landscape.h"
