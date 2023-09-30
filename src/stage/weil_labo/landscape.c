#include "blink.h"
#include "global.h"
#include "overworld.h"

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
  gOverworld.work.weilLabo.unk_000 = 0;
  gOverworld.unk_1c8.work[2] = 0;
  gOverworld.unk_1c8.work[3] = 0;
  gOverworld.unk_1c8.work[0] = 0;
  gOverworld.unk_1c8.work[1] = 0;
  gOverworld.work.weilLabo.unk_00c = 0;
  gOverworld.work.weilLabo.unk_010.x = 0x1dd000;
  gOverworld.work.weilLabo.unk_010.y = 0x55000;
  gOverworld.work.weilLabo.unk_018 = 0;
  gOverworld.work.weilLabo.unk_01c = 0;
  gOverworld.work.weilLabo.unk_020 = 0;
  gOverworld.work.weilLabo.unk_024.x = 0x1dd000;
  gOverworld.work.weilLabo.unk_024.y = 0x55000;
  gOverworld.work.weilLabo.unk_02c.x = 0x1dd000;
  gOverworld.work.weilLabo.unk_02c.y = 0x55000;
  gOverworld.work.weilLabo.unk_008 = 0;
}

static void FUN_08015010(struct Coord* _ UNUSED) {
  if ((gOverworld.unk_1c8.tilesets[0] >> 8 == STAGE_WEILS_LABO) && ((gOverworld.unk_1c8.tilesets[0] & 0xFF) == 0) && (gOverworld.unk_1c8.work[0] == 0)) {
    if ((gOverworld.work.weilLabo.unk_000 & (1 << 0)) == 0) {
      gOverworld.work.weilLabo.unk_000 |= (1 << 0);
      LoadBlink(259, 0);
      LoadBlink(260, 0);
      LoadBlink(261, 0);
      LoadBlink(262, 0);
    }
    UpdateBlinkMotionState(259);
    UpdateBlinkMotionState(260);
    UpdateBlinkMotionState(261);
    UpdateBlinkMotionState(262);
  } else if (gOverworld.work.weilLabo.unk_000 & (1 << 0)) {
    gOverworld.work.weilLabo.unk_000 ^= (1 << 0);
    ClearBlink(259);
    ClearBlink(260);
    ClearBlink(261);
    ClearBlink(262);
  }

  if ((gOverworld.unk_1c8.tilesets[1] >> 8 == STAGE_WEILS_LABO) && ((gOverworld.unk_1c8.tilesets[1] & 0xFF) == 1)) {
    if ((gOverworld.work.weilLabo.unk_000 & (1 << 1)) == 0) {
      gOverworld.work.weilLabo.unk_000 |= (1 << 1);
      LoadBlink(263, 0);
      LoadBlink(264, 0);
      LoadBlink(265, 0);
      LoadBlink(266, 0);
    }
    UpdateBlinkMotionState(263);
    UpdateBlinkMotionState(264);
    UpdateBlinkMotionState(265);
    UpdateBlinkMotionState(266);
  } else if (gOverworld.work.weilLabo.unk_000 & (1 << 1)) {
    gOverworld.work.weilLabo.unk_000 ^= (1 << 1);
    ClearBlink(263);
    ClearBlink(264);
    ClearBlink(265);
    ClearBlink(266);
  }

  if ((gOverworld.unk_1c8.tilesets[1] >> 8 == STAGE_WEILS_LABO) && ((gOverworld.unk_1c8.tilesets[1] & 0xFF) == 3) && (gOverworld.unk_1c8.work[0] == 0)) {
    if ((gOverworld.work.weilLabo.unk_000 & (1 << 2)) == 0) {
      gOverworld.work.weilLabo.unk_000 |= (1 << 2);
      LoadBlink(267, 0);
      LoadBlink(268, 0);
    }
    UpdateBlinkMotionState(267);
    UpdateBlinkMotionState(268);
  } else if (gOverworld.work.weilLabo.unk_000 & (1 << 2)) {
    gOverworld.work.weilLabo.unk_000 ^= (1 << 2);
    ClearBlink(267);
    ClearBlink(268);
  }

  gOverworld.work.weilLabo.unk_008++;
}

static void nop_08015244(struct Coord* _ UNUSED) { return; }

static void exitWeilLabo(struct Coord* _ UNUSED) {
  ClearBlink(0x103);
  ClearBlink(0x104);
  ClearBlink(0x105);
  ClearBlink(0x106);
  ClearBlink(0x107);
  ClearBlink(0x108);
  ClearBlink(0x109);
  ClearBlink(0x10a);
  ClearBlink(0x10b);
  ClearBlink(0x10c);
  ClearBlink(0x10d);
  ClearBlink(0x10e);
}

// ------------------------------------------------------------------------------------------------------------------------------------

void FUN_080152bc(struct StageLayer* l, const struct Stage* stage);
void FUN_0801534c(struct StageLayer* l, const struct Stage* stage);
void FUN_08015378(struct StageLayer* l, const struct Stage* stage);
void FUN_08015390(struct StageLayer* l, const struct Stage* stage);
void FUN_080153cc(struct StageLayer* l, const struct Stage* stage);
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
      [LAYER_UPDATE] = FUN_080152bc,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = FUN_0801534c,
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

INCASM("asm/stage_gfx/weil_labo.inc");

// ------------------------------------------------------------------------------------------------------------------------------------

extern const struct ScreenLayout sScreenMap1;
INCBIN_STATIC(sScreenMap1, "data/stage/weil_labo/layer1.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08346ab0 0x08346c14 ./data/stage/weil_labo/layer1.bin

extern const struct ScreenLayout sScreenMap2;
INCBIN_STATIC(sScreenMap2, "data/stage/weil_labo/layer2.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08346c14 0x08346d58 ./data/stage/weil_labo/layer2.bin

extern const struct ScreenLayout sScreenMap3;
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
