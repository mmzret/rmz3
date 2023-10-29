#include "blink.h"
#include "global.h"
#include "overworld.h"

#define STAGE (gOverworld.work.weilLabo)

static void initWeilLabo(struct Coord* _ UNUSED);
static void FUN_08015010(struct Coord* _ UNUSED);
static void nop_08015244(struct Coord* _ UNUSED);
static void exitWeilLabo(struct Coord* _ UNUSED);

static const StageFunc sStageRoutine[4] = {
    initWeilLabo,
    FUN_08015010,
    nop_08015244,
    exitWeilLabo,
};

static void initWeilLabo(struct Coord* _ UNUSED) {
  STAGE.unk_000 = 0;
  gOverworld.state[2] = 0;
  gOverworld.state[3] = 0;
  gOverworld.state[0] = 0;
  gOverworld.state[1] = 0;
  STAGE.unk_00c = 0;
  STAGE.unk_010.x = PIXEL(7632);
  STAGE.unk_010.y = PIXEL(1360);
  STAGE.unk_018 = 0;
  STAGE.unk_01c = 0;
  STAGE.unk_020 = 0;
  STAGE.unk_024.x = PIXEL(7632);
  STAGE.unk_024.y = PIXEL(1360);
  STAGE.unk_02c.x = PIXEL(7632);
  STAGE.unk_02c.y = PIXEL(1360);
  STAGE.unk_008 = 0;
}

static void FUN_08015010(struct Coord* _ UNUSED) {
  if ((TILESET_ID(0) == STAGE_WEILS_LABO) && (TILESET_IDX(0) == 0) && (gOverworld.state[0] == 0)) {
    if ((STAGE.unk_000 & (1 << 0)) == 0) {
      STAGE.unk_000 |= (1 << 0);
      LoadBlink(259, 0);
      LoadBlink(260, 0);
      LoadBlink(261, 0);
      LoadBlink(262, 0);
    }
    UpdateBlinkMotionState(259);
    UpdateBlinkMotionState(260);
    UpdateBlinkMotionState(261);
    UpdateBlinkMotionState(262);
  } else if (STAGE.unk_000 & (1 << 0)) {
    STAGE.unk_000 ^= (1 << 0);
    ClearBlink(259);
    ClearBlink(260);
    ClearBlink(261);
    ClearBlink(262);
  }

  if ((TILESET_ID(1) == STAGE_WEILS_LABO) && (TILESET_IDX(1) == 1)) {
    if ((STAGE.unk_000 & (1 << 1)) == 0) {
      STAGE.unk_000 |= (1 << 1);
      LoadBlink(263, 0);
      LoadBlink(264, 0);
      LoadBlink(265, 0);
      LoadBlink(266, 0);
    }
    UpdateBlinkMotionState(263);
    UpdateBlinkMotionState(264);
    UpdateBlinkMotionState(265);
    UpdateBlinkMotionState(266);
  } else if (STAGE.unk_000 & (1 << 1)) {
    STAGE.unk_000 ^= (1 << 1);
    ClearBlink(263);
    ClearBlink(264);
    ClearBlink(265);
    ClearBlink(266);
  }

  if ((TILESET_ID(1) == STAGE_WEILS_LABO) && (TILESET_IDX(1) == 3) && (gOverworld.state[0] == 0)) {
    if ((STAGE.unk_000 & (1 << 2)) == 0) {
      STAGE.unk_000 |= (1 << 2);
      LoadBlink(267, 0);
      LoadBlink(268, 0);
    }
    UpdateBlinkMotionState(267);
    UpdateBlinkMotionState(268);
  } else if (STAGE.unk_000 & (1 << 2)) {
    STAGE.unk_000 ^= (1 << 2);
    ClearBlink(267);
    ClearBlink(268);
  }

  STAGE.unk_008++;
}

static void nop_08015244(struct Coord* _ UNUSED) { return; }

static void exitWeilLabo(struct Coord* _ UNUSED) {
  ClearBlink(259);
  ClearBlink(260);
  ClearBlink(261);
  ClearBlink(262);
  ClearBlink(263);
  ClearBlink(264);
  ClearBlink(265);
  ClearBlink(266);
  ClearBlink(267);
  ClearBlink(268);
  ClearBlink(269);
  ClearBlink(270);
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void LayerUpdate_2(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerExit_2(struct StageLayer* l UNUSED, const struct Stage* _ UNUSED);
static void FUN_08015378(struct StageLayer* l, const struct Stage* _ UNUSED);
static void FUN_08015390(struct StageLayer* l, const struct Stage* _ UNUSED);
static void FUN_080153cc(struct StageLayer* l, const struct Stage* _ UNUSED);
void FUN_080153e8(struct StageLayer* l, const struct Stage* stage);
void FUN_08015510(struct StageLayer* l, const struct Stage* stage);
void weilLabo_08015564(struct StageLayer* l, const struct Stage* stage);
void weilLabo_08015710(struct StageLayer* l, const struct Stage* stage);
void FUN_080157b0(struct StageLayer* l, const struct Stage* stage);
void weilLabo_080158a4(struct StageLayer* l, const struct Stage* stage);
void FUN_08015c40(struct StageLayer* l, const struct Stage* stage);
void FUN_08015c5c(struct StageLayer* l, const struct Stage* stage);
void FUN_08015cf0(struct StageLayer* l, const struct Stage* stage);
void weillabo_08015e34(struct StageLayer* l, const struct Stage* stage);
void FUN_08015f7c(struct StageLayer* l, const struct Stage* stage);
void FUN_08016018(struct StageLayer* l, const struct Stage* stage);

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
      [LAYER_EXIT]   = LayerExit_2,
    },
    [3] = {
      [LAYER_UPDATE] = FUN_08015378,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
    [4] = {
      [LAYER_UPDATE] = FUN_08015390,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
    [5] = {
      [LAYER_UPDATE] = FUN_080153cc,
      [LAYER_DRAW]   = FUN_080153e8,
      [LAYER_EXIT]   = NULL,
    },
    [6] = {
      [LAYER_UPDATE] = FUN_08015510,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
    [7] = {
      [LAYER_UPDATE] = weilLabo_08015564,
      [LAYER_DRAW]   = weilLabo_08015710,
      [LAYER_EXIT]   = NULL,
    },
    [8] = {
      [LAYER_UPDATE] = FUN_080157b0,
      [LAYER_DRAW]   = weilLabo_080158a4,
      [LAYER_EXIT]   = FUN_08015c40,
    },
    [9] = {
      [LAYER_UPDATE] = FUN_08015c5c,
      [LAYER_DRAW]   = FUN_08015cf0,
      [LAYER_EXIT]   = NULL,
    },
    [10] = {
      [LAYER_UPDATE] = weillabo_08015e34,
      [LAYER_DRAW]   = FUN_08015f7c,
      [LAYER_EXIT]   = FUN_08016018,
    },
};
// clang-format on

// 0x080152bc
static void LayerUpdate_2(struct StageLayer* l, const struct Stage* _ UNUSED) {
#if MODERN == 0
  register u16 tmp asm("r1");
  register s32 sin asm("r1");
  register s32 scy asm("r0");
#else
  u16 sin;
#endif

  if (l->phase == 0) {
    const u16 n = l->bgIdx;
    BGCNT16(n >> 4) &= 0xFFFC;
    BGCNT16(n >> 4) |= 1;
    gBlendRegBuffer.bldclt = 0x3B44;
    gBlendRegBuffer.bldalpha = 0xC04;
    SEA = PIXEL(832);
    LoadBlink(234, 192);
    l->unk_10 = 0;
    l->phase++;
  }

  l->unk_10++;
#if MODERN == 0
  tmp = SIN(l->unk_10);
  sin = ((s32)tmp << 16) >> 22;
  scy = -27 - sin;
  (l->scroll).y = scy;
#else
  sin = SIN(l->unk_10);
  (l->scroll).y = -27 - (((s16)sin) >> 6);
#endif
  UpdateBlinkMotionState(234);
}

// 0x0801534c
static void LayerExit_2(struct StageLayer* l UNUSED, const struct Stage* _ UNUSED) {
  ClearBlink(234);
  gBlendRegBuffer.bldclt = 0;
  SEA = MAX_Y;
}

// 0x08015378
static void FUN_08015378(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    (l->scrollPower).x = 0;
    (l->scrollPower).y = 0;
    l->phase++;
  }
}

// 0x08015390
static void FUN_08015390(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    (l->scrollPower).x = 0xC0;
    (l->scrollPower).y = 0xC0;
    if ((l->viewportCenterPixel).x < 5760) {
      (l->scroll).x = 840;
    } else {
      (l->scroll).x = 1500;
    }
    (l->scroll).y = 40;
    l->phase++;
  }
}

static void FUN_080153cc(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    l->unk_10 = 0;
    l->phase++;
  }
  l->unk_10++;
}

INCASM("asm/stage_gfx/weil_labo.inc");

#undef STAGE

// ------------------------------------------------------------------------------------------------------------------------------------

extern const struct ScreenMap sScreenMap1;
INCBIN_STATIC(sScreenMap1, "data/stage/weil_labo/layer1.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08346ab0 0x08346c14 ./data/stage/weil_labo/layer1.bin

extern const struct ScreenMap sScreenMap2;
INCBIN_STATIC(sScreenMap2, "data/stage/weil_labo/layer2.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08346c14 0x08346d58 ./data/stage/weil_labo/layer2.bin

extern const struct ScreenMap sScreenMap3;
INCBIN_STATIC(sScreenMap3, "data/stage/weil_labo/layer3.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08346d58 0x08346e9c ./data/stage/weil_labo/layer3.bin

extern const tileset_ofs_t sTilesetOffset[];
INCBIN_STATIC(sTilesetOffset, "data/stage/weil_labo/tileset_offset.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08346e9c 0x08346fe0 ./data/stage/weil_labo/tileset_offset.bin

extern const u16 sScreenBehavior[];
INCBIN_STATIC(sScreenBehavior, "data/stage/weil_labo/screen_behavior.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08346fe0 0x08347268 ./data/stage/weil_labo/screen_behavior.bin

const struct Stage gWeilLaboLandscape = {
  id : STAGE_WEILS_LABO,
  fn : sStageRoutine,
  terrainHdr : &gStageTerrains[STAGE_WEILS_LABO],
  maps : {&sScreenMap1, &sScreenMap2, &sScreenMap3},
  bgIdx : {USE_BG1, USE_BG2, USE_BG3},
  prio : {3, 3, 3},
  screenBase : {BGMAP_BLOCK(2), BGMAP_BLOCK(4), BGMAP_BLOCK(6)},
  scrollPower : {{0x100, 0x100}, {0x100, 0x100}, {0x100, 0x100}},
  scroll : {{0, 0}, {0, 0}, {0, 0}},
  tilesetOffset : sTilesetOffset,
  bgFns : sLayerRoutine,
  behavior : sScreenBehavior,
  unk_78 : {0x0, 0x0},
};
