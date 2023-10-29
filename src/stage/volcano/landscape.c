#include "blink.h"
#include "gfx.h"
#include "global.h"
#include "mission.h"
#include "overworld.h"
#include "solid.h"

#define STAGE (gOverworld.work.volcano)

static const struct Coord sLavaRiverPlatformCoords[2][6];

struct Solid* CreateVolcanoCoffin(u8 n, s32 x, s32 y);

static const u8 u8_ARRAY_ARRAY_0833bf1c[18][2];
static void initVolcano(struct Coord* _ UNUSED);
static void volcano_0800be3c(struct Coord* c);
static void volcano_0800c394(struct Coord* _ UNUSED);
static void exitVolcano(struct Coord* _ UNUSED);

static const StageFunc sStageRoutine[4] = {
    initVolcano,
    volcano_0800be3c,
    volcano_0800c394,
    exitVolcano,
};

static void initVolcano(struct Coord* _ UNUSED) {
  STAGE.unk_000 = 0;
  STAGE.unk_004 = 0;
  STAGE.coffins[0] = NULL;
  STAGE.coffins[1] = NULL;
}

static void volcano_0800be3c(struct Coord* c) {
  if ((TILESET_ID(0) == STAGE_VOLCANO) && (TILESET_IDX(0) == 0)) {
    if ((STAGE.unk_000 & (1 << 0)) == 0) {
      STAGE.unk_000 |= 1;
      LoadBlink(49, 0);
      LoadBlink(50, 0);
      STAGE.unk_001 = 0;
    }
    UpdateBlinkMotionState(49);
    UpdateBlinkMotionState(50);
    STAGE.unk_001++;
    if (STAGE.unk_001 == 45) {
      STAGE.unk_001 = 0;
    }
  } else if (STAGE.unk_000 & 1) {
    STAGE.unk_000 ^= 1;
    ClearBlink(49);
    ClearBlink(50);
  }

  if ((TILESET_ID(1) == STAGE_VOLCANO) && (TILESET_IDX(1) == 1)) {
    if ((STAGE.unk_000 & (1 << 1)) == 0) {
      STAGE.unk_000 |= (1 << 1);
      LoadBlink(60, 0);
    }
    UpdateBlinkMotionState(60);
  } else if (STAGE.unk_000 & (1 << 1)) {
    STAGE.unk_000 ^= (1 << 1);
    ClearBlink(60);
  }

  if ((TILESET_ID(1) == STAGE_VOLCANO) && (TILESET_IDX(1) == 2)) {
    if ((STAGE.unk_000 & (1 << 2)) == 0) {
      STAGE.unk_000 |= (1 << 2);
      LoadBlink(51, 0);
      LoadBlink(52, 0);
      STAGE.unk_002 = 0;
    }
    UpdateBlinkMotionState(51);
    UpdateBlinkMotionState(52);
    STAGE.unk_002++;
    if (STAGE.unk_002 == 16) {
      STAGE.unk_002 = 0;
    }
  } else if (STAGE.unk_000 & (1 << 2)) {
    STAGE.unk_000 ^= (1 << 2);
    ClearBlink(51);
    ClearBlink(52);
  }

  if ((TILESET_ID(0) == STAGE_VOLCANO) && (TILESET_IDX(0) == 3)) {
    if ((STAGE.unk_000 & (1 << 3)) == 0) {
      STAGE.unk_000 |= (1 << 3);
      LoadBlink(50, 0);
      LoadBlink(53, 0);
      LoadBlink(54, 0);
      LoadBlink(55, 0);
      LoadBlink(56, 0);
      LoadBlink(57, 0);
      STAGE.unk_001 = 0;
    }
    UpdateBlinkMotionState(50);
    UpdateBlinkMotionState(53);
    UpdateBlinkMotionState(54);
    UpdateBlinkMotionState(55);
    UpdateBlinkMotionState(56);
    UpdateBlinkMotionState(57);
    STAGE.unk_001++;
    if (STAGE.unk_001 == 45) {
      STAGE.unk_001 = 0;
    }
  } else if (STAGE.unk_000 & (1 << 3)) {
    STAGE.unk_000 ^= (1 << 3);
    ClearBlink(50);
    ClearBlink(53);
    ClearBlink(54);
    ClearBlink(55);
    ClearBlink(56);
    ClearBlink(57);
  }

  if ((TILESET_ID(1) == STAGE_VOLCANO) && (TILESET_IDX(1) == 4)) {
    if ((STAGE.unk_000 & (1 << 4)) == 0) {
      STAGE.unk_000 |= (1 << 4);
      LoadBlink(58, 0);
      STAGE.unk_002 = 0;
      STAGE.unk_003 = 0;
    }
    UpdateBlinkMotionState(58);
    STAGE.unk_002++;
    if (STAGE.unk_002 == 45) {
      STAGE.unk_002 = 0;
    }
    STAGE.unk_003++;
    if (STAGE.unk_003 == 16) {
      STAGE.unk_003 = 0;
    }
  } else if (STAGE.unk_000 & (1 << 4)) {
    STAGE.unk_000 ^= (1 << 4);
    ClearBlink(58);
  }

  if ((TILESET_ID(0) == STAGE_VOLCANO) && (TILESET_IDX(0) == 5)) {
    if ((STAGE.unk_000 & (1 << 5)) == 0) {
      STAGE.unk_000 |= (1 << 5);
      LoadBlink(53, 0);
      LoadBlink(54, 0);
      LoadBlink(56, 0);
      LoadBlink(57, 0);
      STAGE.unk_001 = 0;
    }
    UpdateBlinkMotionState(53);
    UpdateBlinkMotionState(54);
    UpdateBlinkMotionState(56);
    UpdateBlinkMotionState(57);
    STAGE.unk_001++;
    if (STAGE.unk_001 == 32) {
      STAGE.unk_001 = 0;
    }
  } else if (STAGE.unk_000 & (1 << 5)) {
    STAGE.unk_000 ^= (1 << 5);
    ClearBlink(53);
    ClearBlink(54);
    ClearBlink(56);
    ClearBlink(57);
  }

  if ((TILESET_ID(0) == STAGE_VOLCANO) && (TILESET_IDX(0) == 6)) {
    if ((STAGE.unk_000 & (1 << 6)) == 0) {
      STAGE.unk_000 |= (1 << 6);
      LoadBlink(59, 0);
    }
    UpdateBlinkMotionState(59);
  } else if (STAGE.unk_000 & (1 << 6)) {
    STAGE.unk_000 ^= (1 << 6);
    ClearBlink(59);
  }

  if (c->x - 0x1E0000U < PIXEL(3600)) {
    if (STAGE.coffins[0] == NULL) {
      STAGE.coffins[0] = CreateVolcanoCoffin(0, PIXEL(7992), PIXEL(448));
    }
    if (STAGE.coffins[1] == NULL) {
      STAGE.coffins[1] = CreateVolcanoCoffin(1, PIXEL(8376), PIXEL(592));
    }
  } else {
    struct Solid* p;
    if (p = STAGE.coffins[0], p != NULL) {
      (p->s).flags &= ~DISPLAY;
      (p->s).flags &= ~FLIPABLE;
      (p->body).status = 0;
      (p->body).prevStatus = 0;
      (p->body).invincibleTime = 0;
      (p->s).flags &= ~COLLIDABLE;
      SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
      STAGE.coffins[0] = NULL;
    }
    if (p = STAGE.coffins[1], p != NULL) {
      (p->s).flags &= ~DISPLAY;
      (p->s).flags &= ~FLIPABLE;
      (p->body).status = 0;
      (p->body).prevStatus = 0;
      (p->body).invincibleTime = 0;
      (p->s).flags &= ~COLLIDABLE;
      SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
      STAGE.coffins[1] = NULL;
    }
  }

  STAGE.unk_004++;
}

static void volcano_0800c394(struct Coord* _ UNUSED) {
  if ((TILESET_ID(0) == STAGE_VOLCANO) && (TILESET_IDX(0) == 0)) {
    RequestGraphicTransfer(&(TILESETS(18, 0)[STAGE.unk_001 / 9]).g, (void*)0x4000);
    LoadPalette(&(TILESETS(18, 0)[STAGE.unk_001 / 9]).pal, 0);
  }

  if ((TILESET_ID(1) == STAGE_VOLCANO) && (TILESET_IDX(1) == 2)) {
    RequestGraphicTransfer(&(TILESETS(18, 5)[STAGE.unk_002 / 4]).g, (void*)0x4000);
    LoadPalette(&(TILESETS(18, 5)[STAGE.unk_002 / 4]).pal, 0);
  }

  if ((TILESET_ID(0) == STAGE_VOLCANO) && (TILESET_IDX(0) == 3)) {
    RequestGraphicTransfer(&(TILESETS(18, 0)[STAGE.unk_001 / 9]).g, (void*)0x4000);
    LoadPalette(&(TILESETS(18, 0)[STAGE.unk_001 / 9]).pal, 0);
  }

  if ((TILESET_ID(1) == STAGE_VOLCANO) && (TILESET_IDX(1) == 4)) {
    RequestGraphicTransfer(&(TILESETS(18, 9)[STAGE.unk_002 / 9]).g, (void*)0x4000);
    LoadPalette(&(TILESETS(18, 9)[STAGE.unk_002 / 9]).pal, 0);

    RequestGraphicTransfer(&(TILESETS(18, 14)[STAGE.unk_003 / 4]).g, (void*)0x4000);
    LoadPalette(&(TILESETS(18, 14)[STAGE.unk_003 / 4]).pal, 0);
  }

  if ((TILESET_ID(0) == STAGE_VOLCANO) && (TILESET_IDX(0) == 5)) {
    RequestGraphicTransfer(&(TILESETS(18, 25)[STAGE.unk_001 / 8]).g, (void*)0x4000);
    LoadPalette(&(TILESETS(18, 25)[STAGE.unk_001 / 8]).pal, 0);
  }
}

static void exitVolcano(struct Coord* _ UNUSED) {
  ClearBlink(49);
  ClearBlink(50);
  ClearBlink(51);
  ClearBlink(52);
  ClearBlink(53);
  ClearBlink(54);
  ClearBlink(55);
  ClearBlink(56);
  ClearBlink(57);
  ClearBlink(58);
  ClearBlink(59);
  ClearBlink(60);
}

static void LayerUpdate_Volcano_2(struct StageLayer* l, const struct Stage* stage);
static void LayerUpdate_Volcano_3(struct StageLayer* l, const struct Stage* stage);
static void LayerUpdate_Volcano_4(struct StageLayer* l, const struct Stage* stage);
static void LayerUpdate_VolcanoEruption(struct StageLayer* l, const struct Stage* stage);
static void LayerDraw_Volcano_5(struct StageLayer* l, const struct Stage* stage);
static void LayerUpdate_Volcano_6(struct StageLayer* l, const struct Stage* stage);
static void LayerDraw_Volcano_6(struct StageLayer* l, const struct Stage* stage);
static void LayerUpdate_LavaRiver1(struct StageLayer* l, const struct Stage* stage);
static void LayerExit_Volcano_7(struct StageLayer* l, const struct Stage* _);
static void LayerUpdate_LavaRiver2(struct StageLayer* l, const struct Stage* _);
static void LayerExit_Volcano_8(struct StageLayer* l, const struct Stage* _);

// clang-format off
static const StageLayerRoutine sLayerRoutine[9] = {
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
      [LAYER_UPDATE] = LayerUpdate_Volcano_2,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
    [3] = {
      [LAYER_UPDATE] = LayerUpdate_Volcano_3,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
    [4] = {
      [LAYER_UPDATE] = LayerUpdate_Volcano_4,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
    [5] = {
      [LAYER_UPDATE] = LayerUpdate_VolcanoEruption,
      [LAYER_DRAW]   = LayerDraw_Volcano_5,
      [LAYER_EXIT]   = NULL,
    },
    [6] = {
      [LAYER_UPDATE] = LayerUpdate_Volcano_6,
      [LAYER_DRAW]   = LayerDraw_Volcano_6,
      [LAYER_EXIT]   = NULL,
    },
    [7] = {
      [LAYER_UPDATE] = LayerUpdate_LavaRiver1,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = LayerExit_Volcano_7,
    },
    [8] = {
      [LAYER_UPDATE] = LayerUpdate_LavaRiver2,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = LayerExit_Volcano_8,
    },
};
// clang-format on

static void LayerUpdate_Volcano_2(struct StageLayer* l, const struct Stage* stage) {
  if (l->phase == 0) {
    (l->scrollPower).x = 0x80;
    (l->scrollPower).y = 0x80;
    (l->scroll).x = 0xc6c;
    (l->scroll).y = 0xc0;
    l->phase++;
  }
}

static void LayerUpdate_Volcano_3(struct StageLayer* l, const struct Stage* stage) {
  if (l->phase == 0) {
    (l->scrollPower).x = 0x80;
    (l->scrollPower).y = 0x80;
    (l->scroll).x = 0x12c0;
    (l->scroll).y = 0xc0;
    l->phase++;
  }
}

static void LayerUpdate_Volcano_4(struct StageLayer* l, const struct Stage* stage) {
  if (l->phase == 0) {
    BGCNT16((l->bgIdx << 16) >> 20) = (BGCNT16((l->bgIdx << 16) >> 20) & 0xFFFC) | 3;
    (l->scrollPower).x = 0x40;
    (l->scrollPower).y = 0x40;
    (l->scroll).x = 0xcc;
    if (!((gMission.unk_00)->missionDones & MISSILE_FACTORY)) {
      (l->scroll).y = 0x168;
    } else {
      (l->scroll).y = 0x348;
    }
    l->phase++;
  }
}

struct Enemy* CreateVolcanoBomb(s32 x, s32 y);

WIP static void LayerUpdate_VolcanoEruption(struct StageLayer* l, const struct Stage* stage) {
#if MODERN
  u16 i;
  u16 dispcnt;
  switch (l->phase) {
    case 0: {
      BGCNT16((l->bgIdx << 16) >> 20) = (BGCNT16((l->bgIdx << 16) >> 20) & 0xFFFC) | 2;
      (l->scrollPower).x = 0xc0;
      (l->scrollPower).y = 0xc0;
      (l->scroll).x = 0x168;
      (l->scroll).y = 0x78;
      l->unk_10 = 0;
      l->unk_12 = 0;
      l->phase++;
      FALLTHROUGH;
    }
    case 1: {
      if (((l->viewportCenterPixel).x - 0x508U <= 0xDB) || ((l->viewportCenterPixel).x - 0x6A0U <= 0xDB)) {
        PlaySound(SE_ERUPTION);
        AppendQuake(8, &gStageRun.vm.camera.viewport);
        l->phase++;
      }
      break;
    }
    case 2: {
      s32 j;
      u8 arr[7];
      l->unk_10++;
      if (l->unk_10 == 48) {
        for (i = 0; i < 7; i++) {
          arr[i] = i;
        }
        for (j = 0; j < 16; j++) {
          u8 a, b, temp;
          RNG_0202f388 = LCG(RNG_0202f388);
          a = (RNG_0202f388 >> 16) % 7;
          RNG_0202f388 = LCG(RNG_0202f388);
          b = (RNG_0202f388 >> 16) % 7;
          SWAP(arr[a], arr[b], temp);
        }
        for (i = 0; i < 3; i++) {
          (l->work).volcano.eruptionX[i] = PIXEL((l->viewportCenterPixel).x + (arr[i] * 32) + 24);
        }
        CreateVolcanoBomb((l->work).volcano.eruptionX[0], PIXEL((l->viewportCenterPixel).y));
      } else if (l->unk_10 == 64) {
        CreateVolcanoBomb((l->work).volcano.eruptionX[1], PIXEL((l->viewportCenterPixel).y));
      } else if (l->unk_10 == 80) {
        CreateVolcanoBomb((l->work).volcano.eruptionX[2], PIXEL((l->viewportCenterPixel).y));
      }

      if (l->unk_10 == 160) {
        l->unk_10 = 0;
        l->unk_12 = 0;
        l->phase--;
      }
      break;
    }
  }
  dispcnt = l->bgIdx << 8;
  if ((l->viewportCenterPixel).x < 1088) {
    gVideoRegBuffer.dispcnt &= ~dispcnt;
  } else {
    gVideoRegBuffer.dispcnt |= dispcnt;
  }
#else
  INCCODE("asm/wip/LayerUpdate_VolcanoEruption.inc");
#endif
}

static void LayerDraw_Volcano_5(struct StageLayer* l, const struct Stage* stage) {
  for (; l->unk_10 >= u8_ARRAY_ARRAY_0833bf1c[l->unk_12][1]; l->unk_12++) {
  }

  RequestGraphicTransfer(&(TILESETS(18, 18)[u8_ARRAY_ARRAY_0833bf1c[l->unk_12][0]]).g, (void*)0x4000);
  LoadPalette(&(TILESETS(18, 18)[u8_ARRAY_ARRAY_0833bf1c[l->unk_12][0]]).pal, 0);
  DrawGeneralStageLayer(l, stage);
}

static void LayerUpdate_Volcano_6(struct StageLayer* l, const struct Stage* stage) {
  const u16 n = l->bgIdx;

  if (l->phase == 0) {
    u32 FILL_VALUE;
    void* dst;
    BGCNT16(n >> 4) = l->screenBase | 0x8047;

    FILL_VALUE = 0x40404040;
    dst = (void*)(VRAM + SCREEN_BASE_16(n >> 4));
    CpuFastFill(FILL_VALUE, dst, 4096);

    l->unk_10 = 0;
    l->phase++;
  }
  if (++l->unk_10 == 48) {
    l->unk_10 = 0;
  }

  { vu32 _; }
}

static void LayerDraw_Volcano_6(struct StageLayer* l, const struct Stage* stage) {
  const u16 n = l->bgIdx;
  const s32 idx = l->unk_10 / 6;
  LoadBgMap(n, gBgMapOffsets, 47 + idx, 7, 2 + ((l->unk_10 & 1) << 5));

  ((struct BgOfs*)gVideoRegBuffer.bgofs[n >> 4])->x = (l->viewportCenterPixel).x + 0xd300;
  gVideoRegBuffer.bgofs[n >> 4][1] = (l->viewportCenterPixel).y - 0x140 + ((l->unk_10 & 1) << 8);
}

static void LayerUpdate_LavaRiver1(struct StageLayer* l, const struct Stage* _ UNUSED) {
  u16 n;

  if (l->phase == 0) {
    LoadBlink(61, 0x300);
    l->unk_10 = 0;
    l->phase++;
  }

  l->unk_10++;
  if (l->unk_10 == 48 * 3) {
    l->unk_10 = 0;
  }

  n = l->unk_10 % 48;
  if (n == 0) {
    if (l->unk_10 < 48) {
      CreateLavaRiverPlatform(sLavaRiverPlatformCoords[0][0].x, sLavaRiverPlatformCoords[0][0].y);
      CreateLavaRiverPlatform(sLavaRiverPlatformCoords[0][3].x, sLavaRiverPlatformCoords[0][3].y);

    } else if (l->unk_10 < 48 * 2) {
      CreateLavaRiverPlatform(sLavaRiverPlatformCoords[0][1].x, sLavaRiverPlatformCoords[0][1].y);
      CreateLavaRiverPlatform(sLavaRiverPlatformCoords[0][4].x, sLavaRiverPlatformCoords[0][4].y);

    } else {
      CreateLavaRiverPlatform(sLavaRiverPlatformCoords[0][2].x, sLavaRiverPlatformCoords[0][2].y);
      CreateLavaRiverPlatform(sLavaRiverPlatformCoords[0][5].x, sLavaRiverPlatformCoords[0][5].y);
    }
  }

  UpdateBlinkMotionState(61);
}

static void LayerExit_Volcano_7(struct StageLayer* l, const struct Stage* _) {
  ClearBlink(61);
  return;
}

static void LayerUpdate_LavaRiver2(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    LoadBlink(61, 0x300);
    l->unk_10 = 0;
    l->unk_12 = 0;
    l->phase++;
  }

  l->unk_10++;
  if (l->unk_10 == 48 * 3) {
    l->unk_10 = 0;
  }

  if (l->unk_10 == 0) {
    const struct Coord* coords = sLavaRiverPlatformCoords[1];
    CreateLavaRiverPlatform(coords[0].x, coords[0].y);
    CreateLavaRiverPlatform(coords[1].x, coords[1].y);
    CreateLavaRiverPlatform(coords[2].x, coords[2].y);
  }

  l->unk_12++;
  if (l->unk_12 == 48 * 2) {
    l->unk_12 = 0;
  }

  if (l->unk_12 == 0) {
    const struct Coord* coords = sLavaRiverPlatformCoords[1];
    CreateLavaRiverPlatform(coords[4].x, coords[5].y);
  }
  if (l->unk_12 == 48) {
    const struct Coord* coords = sLavaRiverPlatformCoords[1];
    CreateLavaRiverPlatform(coords[3].x, coords[5].y);
    CreateLavaRiverPlatform(coords[5].x, coords[5].y);
  }

  UpdateBlinkMotionState(61);
}

static void LayerExit_Volcano_8(struct StageLayer* l, const struct Stage* _) {
  ClearBlink(61);
  return;
}

// ------------------------------------------------------------------------------------------------------------------------------------

#include "../../../data/stage/volcano/layer.h"
//
#include "../../../data/stage/volcano/landscape.h"

// clang-format off
static const u8 u8_ARRAY_ARRAY_0833bf1c[18][2] = {
  { 0, 1 },
  { 1, 7 },
  { 2, 11 },
  { 3, 15 },
  { 4, 19 },
  { 2, 23 },
  { 3, 27 },
  { 4, 31 },
  { 2, 35 },
  { 3, 39 },
  { 4, 43 },
  { 2, 47 },
  { 3, 51 },
  { 4, 55 },
  { 5, 64 },
  { 6, 73 },
  { 0, 160 },
  { 0, 0 },
};
// clang-format on

// clang-format off
static const struct Coord sLavaRiverPlatformCoords[2][6] = {
    {
        {PIXEL(6424),  PIXEL(272)},
        {PIXEL(6552),  PIXEL(272)},
        {PIXEL(6680),  PIXEL(272)},
        {PIXEL(6808),  PIXEL(272)},
        {PIXEL(6936),  PIXEL(272)},
        {PIXEL(7064),  PIXEL(272)},
    },
    {
        {PIXEL(9816),  PIXEL(272)},
        {PIXEL(9976),  PIXEL(272)},
        {PIXEL(10136), PIXEL(272)},
        {PIXEL(10296), PIXEL(272)},
        {PIXEL(10456), PIXEL(272)},
        {PIXEL(10616), PIXEL(272)},
    },
};
// clang-format on

#undef STAGE
