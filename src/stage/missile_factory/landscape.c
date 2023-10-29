#include "blink.h"
#include "global.h"
#include "overworld.h"
#include "story.h"

#define HEIGHT 14
#define WIDTH 32

static const struct MetatileShift sMetatileShift;

static void initMissileFactory(struct Coord* _ UNUSED);
static void FUN_0800e460(struct Coord* c);
static void FUN_0800e6f8(struct Coord* _ UNUSED);
static void exitMissileFactory(struct Coord* _ UNUSED);

static const StageFunc sStageRoutine[4] = {
    initMissileFactory,
    FUN_0800e460,
    FUN_0800e6f8,
    exitMissileFactory,
};

static void initMissileFactory(struct Coord* _ UNUSED) {
  gOverworld.state[0] = 0;
  gOverworld.work.missileFactory.unk_000 = 0;
  gOverworld.work.missileFactory.unk_001 = 0;
  gOverworld.work.missileFactory.unk_002 = 0;
  gOverworld.work.missileFactory.unk_003 = 0;
  gOverworld.work.missileFactory.unk_008 = 0;
  gOverworld.work.missileFactory.unk_004 = 0;
  gOverworld.work.missileFactory.unk_010 = 0;
  gOverworld.work.missileFactory.unk_014.x = 0x1c2000;
  gOverworld.work.missileFactory.unk_014.y = 0x12000;
  gOverworld.state[2] = 0;
  ShiftMetatile(0xFF, 100, &sMetatileShift);
}

static void FUN_0800e460(struct Coord* c) {
  gOverworld.work.missileFactory.unk_004++;

  if ((TILESET_ID(0) == STAGE_MISSILE_FACTORY) && (TILESET_IDX(0) == 0)) {
    if ((gOverworld.work.missileFactory.unk_000 & (1 << 0)) == 0) {
      gOverworld.work.missileFactory.unk_000 |= (1 << 0);
      LoadBlink(211, 0);
      LoadBlink(212, 0);
      gOverworld.work.missileFactory.unk_001 = 0;
    }
    UpdateBlinkMotionState(211);
    UpdateBlinkMotionState(212);
    gOverworld.work.missileFactory.unk_001++;
    if (gOverworld.work.missileFactory.unk_001 == 20) {
      gOverworld.work.missileFactory.unk_001 = 0;
    }

  } else if (gOverworld.work.missileFactory.unk_000 & (1 << 0)) {
    gOverworld.work.missileFactory.unk_000 ^= (1 << 0);
    ClearBlink(211);
    ClearBlink(212);
  }

  if ((TILESET_ID(1) == STAGE_MISSILE_FACTORY) && (TILESET_IDX(1) == 4)) {
    if ((gOverworld.work.missileFactory.unk_000 & (1 << 1)) == 0) {
      gOverworld.work.missileFactory.unk_000 |= (1 << 1);
      LoadBlink(209, 0);
    }
    UpdateBlinkMotionState(209);

  } else if (gOverworld.work.missileFactory.unk_000 & (1 << 1)) {
    gOverworld.work.missileFactory.unk_000 ^= (1 << 1);
    ClearBlink(209);
  }

  if ((TILESET_ID(0) == STAGE_MISSILE_FACTORY) && (TILESET_IDX(0) == 5)) {
    if ((gOverworld.work.missileFactory.unk_000 & (1 << 2)) == 0) {
      gOverworld.work.missileFactory.unk_000 |= (1 << 2);
      LoadBlink(210, 0);
    }
    UpdateBlinkMotionState(210);

  } else if (gOverworld.work.missileFactory.unk_000 & (1 << 2)) {
    gOverworld.work.missileFactory.unk_000 ^= (1 << 2);
    ClearBlink(210);
  }

  if ((TILESET_ID(1) == STAGE_MISSILE_FACTORY) && (TILESET_IDX(1) == 1)) {
    if (c->y >= 0x3C000) {
      gOverworld.work.missileFactory.unk_002++;
      if (gOverworld.work.missileFactory.unk_002 == 16) {
        gOverworld.work.missileFactory.unk_002 = 0;
      }
    } else {
      gOverworld.work.missileFactory.unk_002--;
      if (gOverworld.work.missileFactory.unk_002 < 0) {
        gOverworld.work.missileFactory.unk_002 = 15;
      }
    }
  }

  if ((TILESET_ID(0) == STAGE_MISSILE_FACTORY) && (TILESET_IDX(0) == 3)) {
    gOverworld.work.missileFactory.unk_003++;
    if (gOverworld.work.missileFactory.unk_003 == 32) {
      gOverworld.work.missileFactory.unk_003 = 0;
    }
  }

  if ((TILESET_ID(1) == STAGE_MISSILE_FACTORY) && (TILESET_IDX(1) == 6)) {
    gOverworld.work.missileFactory.unk_008++;
    if (gOverworld.work.missileFactory.unk_008 == 60) {
      gOverworld.work.missileFactory.unk_008 = 0;
    }
  }

  if ((c->x - 0x4B000U < 0x1E001) && (0x27FFF < c->y) && (c->y < 0x5A001)) {
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

static void FUN_0800e6f8(struct Coord* _ UNUSED) {
  if ((TILESET_ID(0) == STAGE_MISSILE_FACTORY) && (TILESET_IDX(0) == 0)) {
    RequestGraphicTransfer(&(TILESETS(18, 136)[gOverworld.work.missileFactory.unk_001 / 5]).g, (void*)0x4000);
    LoadPalette(&(TILESETS(18, 136)[gOverworld.work.missileFactory.unk_001 / 5]).pal, 0);
  }

  if ((TILESET_ID(1) == STAGE_MISSILE_FACTORY) && (TILESET_IDX(1) == 1)) {
    RequestGraphicTransfer(&(TILESETS(18, 128)[gOverworld.work.missileFactory.unk_002 >> 1]).g, (void*)0x4000);
    LoadPalette(&(TILESETS(18, 128)[gOverworld.work.missileFactory.unk_002 >> 1]).pal, 0);
  }

  if ((TILESET_ID(0) == STAGE_MISSILE_FACTORY) && (TILESET_IDX(0) == 3)) {
    RequestGraphicTransfer(&(TILESETS(18, 140)[gOverworld.work.missileFactory.unk_003 >> 2]).g, (void*)0x4000);
    LoadPalette(&(TILESETS(18, 140)[gOverworld.work.missileFactory.unk_003 >> 2]).pal, 0);
  }

  if ((TILESET_ID(1) == STAGE_MISSILE_FACTORY) && (TILESET_IDX(1) == 6)) {
    RequestGraphicTransfer(&(TILESETS(18, 148)[gOverworld.work.missileFactory.unk_008 / 12]).g, (void*)0x4000);
    LoadPalette(&(TILESETS(18, 148)[gOverworld.work.missileFactory.unk_008 / 12]).pal, 0);
  }
}

static void exitMissileFactory(struct Coord* _ UNUSED) {
  ClearBlink(207);
  ClearBlink(208);
  ClearBlink(209);
  ClearBlink(210);
  ClearBlink(211);
  ClearBlink(212);
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void LayerUpdate_2(struct StageLayer* l, const struct Stage* stage);
static void LayerUpdate_3(struct StageLayer* l, const struct Stage* stage);
static void LayerUpdate_4(struct StageLayer* l, const struct Stage* stage);
void FUN_0800ea78(struct StageLayer* l, const struct Stage* stage);
void missileFactory_0800eb38(struct StageLayer* l, const struct Stage* stage);
void FUN_0800f2c4(struct StageLayer* l, const struct Stage* stage);
void FUN_0800f2e0(struct StageLayer* l, const struct Stage* stage);
void missileFactory_0800f2ec(struct StageLayer* l, const struct Stage* stage);
void FUN_0800f54c(struct StageLayer* l, const struct Stage* stage);
void missileFactory_0800f560(struct StageLayer* l, const struct Stage* stage);
void FUN_0800f604(struct StageLayer* l, const struct Stage* stage);
void FUN_0800f68c(struct StageLayer* l, const struct Stage* stage);
void FUN_0800f6f8(struct StageLayer* l, const struct Stage* stage);
void FUN_0800f840(struct StageLayer* l, const struct Stage* stage);
void FUN_0800f874(struct StageLayer* l, const struct Stage* stage);

// clang-format off
static const StageLayerRoutine sLayerRoutine[11] = {
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
    [4] = {
      [LAYER_UPDATE] = LayerUpdate_4,
      [LAYER_DRAW]   = FUN_0800ea78,
      [LAYER_EXIT]   = NULL,
    },
    [5] = {
      [LAYER_UPDATE] = missileFactory_0800eb38,
      [LAYER_DRAW]   = FUN_0800f2c4,
      [LAYER_EXIT]   = FUN_0800f2e0,
    },
    [6] = {
      [LAYER_UPDATE] = missileFactory_0800f2ec,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = FUN_0800f54c,
    },
    [7] = {
      [LAYER_UPDATE] = missileFactory_0800f560,
      [LAYER_DRAW]   = FUN_0800f604,
      [LAYER_EXIT]   = NULL,
    },
    [8] = {
      [LAYER_UPDATE] = FUN_0800f68c,
      [LAYER_DRAW]   = FUN_0800f6f8,
      [LAYER_EXIT]   = NULL,
    },
    [9] = {
      [LAYER_UPDATE] = FUN_0800f840,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
    [10] = {
      [LAYER_UPDATE] = FUN_0800f874,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
};
// clang-format on

// 0x0800e8b8
static void LayerUpdate_2(struct StageLayer* l, const struct Stage* stage) {
  if (l->phase == 0) {
    if ((l->viewportCenterPixel).y > 1680) {
      (l->scrollPower).x = 0xc0;
      (l->scrollPower).y = 0xc0;
      (l->scroll).x = 0x3c;
      (l->scroll).y = 0x1e0;
    } else {
      if ((l->viewportCenterPixel).x < 1920) {
        (l->scrollPower).x = 0xe0;
        (l->scrollPower).y = 0xe0;
        (l->scroll).x = 0xd2;
        (l->scroll).y = 0x3c;
        if (FLAG(gCurStory.s.gameflags, FLAG_12)) {
          (l->scroll).x = 0x672;
        }
      } else {
        (l->scrollPower).x = 0x100;
        (l->scrollPower).y = 0x100;
        (l->scroll).x = 0x780;
        (l->scroll).y = 0;
      }
    }

    (l->work).missile.scrollTimer = 0;
    (l->work).missile.c.x = 0x78000;
    (l->work).missile.c.y = 0x0;
    l->phase++;
  }

  if (gOverworld.state[0] != 0) {
    (l->work).missile.scrollTimer += 4;
    if ((l->work).missile.scrollTimer > 0x700) {
      (l->work).missile.scrollTimer = 0x700;
    }
    (l->work).missile.c.x -= (l->work).missile.scrollTimer;
    (l->work).missile.c.y += (l->work).missile.scrollTimer;
    (l->scroll).x = (l->work).missile.c.x >> 8;
    (l->scroll).y = (l->work).missile.c.y >> 8;
  }
}

// 0x0800e974
static void LayerUpdate_3(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    if ((l->viewportCenterPixel).y > 1680) {
      (l->scrollPower).x = 0x80;
      (l->scrollPower).y = 0x80;
      (l->scroll).x = 0x78;
      (l->scroll).y = 0x3C0;
    } else {
      if ((l->viewportCenterPixel).x < 1920) {
        (l->scrollPower).x = 0x20;
        (l->scrollPower).y = 0x20;
        (l->scroll).x = 0x276;
        (l->scroll).y = 0x4EC;
      } else {
        (l->scrollPower).x = 0x100;
        (l->scrollPower).y = 0x0;
        (l->scroll).x = 0x0;
        (l->scroll).y = 0xA0;
      }
    }
    l->phase++;
  }
}

// 0x0800e9d4
static void LayerUpdate_4(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    const u16 n = l->bgIdx;
    BGCNT16(n >> 4) = l->prio | l->screenBase | 0x4044;
    *(u32*)gVideoRegBuffer.bgofs[n >> 4] = 0;
    CpuFastCopy(BGMAP(81), (void*)(VRAM + SCREEN_BASE_16(n >> 4)), 2048);
    CpuFastCopy(BGMAP(82), (void*)(VRAM + 0x800 + SCREEN_BASE_16(n >> 4)), 2048);
    l->unk_10 = 0;
    l->phase++;
  }
  l->unk_10 += 0x10;
}

INCASM("asm/stage_gfx/missile_factory.inc");

extern const struct ScreenMap sScreenMap1;
INCBIN_STATIC(sScreenMap1, "data/stage/missile_factory/layer1.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x0833e1cc 0x0833e390 ./data/stage/missile_factory/layer1.bin

extern const struct ScreenMap sScreenMap2;
INCBIN_STATIC(sScreenMap2, "data/stage/missile_factory/layer2.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x0833e390 0x0833e554 ./data/stage/missile_factory/layer2.bin

extern const struct ScreenMap sScreenMap3;
INCBIN_STATIC(sScreenMap3, "data/stage/missile_factory/layer3.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x0833e554 0x0833e718 ./data/stage/missile_factory/layer3.bin

extern const tileset_ofs_t sTilesetOffset[4 + (HEIGHT * WIDTH)];
INCBIN_STATIC(sTilesetOffset, "data/stage/missile_factory/tileset_offset.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x0833e718 0x0833e8dc ./data/stage/missile_factory/tileset_offset.bin

extern const u16 sScreenBehavior[4 + (HEIGHT * WIDTH)];
INCBIN_STATIC(sScreenBehavior, "data/stage/missile_factory/screen_behavior.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x0833e8dc 0x0833ec64 ./data/stage/missile_factory/screen_behavior.bin

const struct Stage gMissileFactoryLandscape = {
  id : STAGE_MISSILE_FACTORY,
  fn : sStageRoutine,
  terrainHdr : &gStageTerrains[STAGE_MISSILE_FACTORY],
  maps : {&sScreenMap1, &sScreenMap2, &sScreenMap3},
  bgIdx : {USE_BG1, USE_BG2, USE_BG3},
  prio : {2, 2, 3},
  screenBase : {BGMAP_BLOCK(2), BGMAP_BLOCK(4), BGMAP_BLOCK(6)},
  scrollPower : {{0x100, 0x100}, {0x100, 0x100}, {0x100, 0x100}},
  scroll : {{0, 0}, {0, 0}, {0, 0}},
  tilesetOffset : sTilesetOffset,
  bgFns : sLayerRoutine,
  behavior : sScreenBehavior,
  unk_78 : {-0x100, 0x100},
};

static const struct MetatileShift sMetatileShift = {x : 255, y : 20, block : 135, row : 20};  // 0x0833ece4

// ./tools/dumper/bin.ts ./baserom.gba 0x0833ecec 0x0833ee3c ./data/landscape_missile_factory.bin
INCBIN("data/landscape_missile_factory.bin");

#undef HEIGHT
#undef WIDTH
