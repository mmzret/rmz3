#include "blink.h"
#include "global.h"
#include "overworld.h"

static void FUN_08014b28(struct Coord* _ UNUSED);
static void subAracadia_08014b48(struct Coord* _ UNUSED);
static void nop_08014e78(struct Coord* _ UNUSED);
static void FUN_08014e7c(struct Coord* _ UNUSED);

static const StageFunc sStageRoutine[4] = {
    FUN_08014b28,
    subAracadia_08014b48,
    nop_08014e78,
    FUN_08014e7c,
};

static void FUN_08014b28(struct Coord* _ UNUSED) {
  gOverworld.work.raw[0] = 0;
  gOverworld.work.raw[1] = 0;
}

static void subAracadia_08014b48(struct Coord* _ UNUSED) {
  if ((gOverworld.unk_1c8.tilesets[0] >> 8 == STAGE_SUB_ARCADIA) && ((gOverworld.unk_1c8.tilesets[0] & 0xFF) == 0)) {
    if ((gOverworld.work.subArcadia.unk_000 & (1 << 0)) == 0) {
      gOverworld.work.subArcadia.unk_000 |= (1 << 0);
      LoadBlink(124, 0);
      LoadBlink(125, 0);
      LoadBlink(126, 0);
      LoadBlink(130, 0);
      LoadBlink(166, 0);
    }
    UpdateBlinkMotionState(124);
    UpdateBlinkMotionState(125);
    UpdateBlinkMotionState(126);
    UpdateBlinkMotionState(130);
    UpdateBlinkMotionState(166);

  } else if (gOverworld.work.subArcadia.unk_000 & (1 << 0)) {
    gOverworld.work.subArcadia.unk_000 ^= (1 << 0);
    ClearBlink(124);
    ClearBlink(125);
    ClearBlink(126);
    ClearBlink(130);
    ClearBlink(166);
  }

  if ((gOverworld.unk_1c8.tilesets[1] >> 8 == STAGE_SUB_ARCADIA) && ((gOverworld.unk_1c8.tilesets[1] & 0xFF) == 1)) {
    if ((gOverworld.work.subArcadia.unk_000 & (1 << 1)) == 0) {
      gOverworld.work.subArcadia.unk_000 |= (1 << 1);
      LoadBlink(127, 0);
      LoadBlink(128, 0);
      LoadBlink(129, 0);
    }
    UpdateBlinkMotionState(127);
    UpdateBlinkMotionState(128);
    UpdateBlinkMotionState(129);

  } else if (gOverworld.work.subArcadia.unk_000 & (1 << 1)) {
    gOverworld.work.subArcadia.unk_000 ^= (1 << 1);
    ClearBlink(127);
    ClearBlink(128);
    ClearBlink(129);
  }

  if ((gOverworld.unk_1c8.tilesets[0] >> 8 == STAGE_SUB_ARCADIA) && ((gOverworld.unk_1c8.tilesets[0] & 0xFF) == 2)) {
    if ((gOverworld.work.subArcadia.unk_000 & (1 << 2)) == 0) {
      gOverworld.work.subArcadia.unk_000 |= (1 << 2);
      LoadBlink(161, 0);
      LoadBlink(162, 0);
      LoadBlink(163, 0);
      LoadBlink(164, 0);
      LoadBlink(165, 0);
    }
    UpdateBlinkMotionState(161);
    UpdateBlinkMotionState(162);
    UpdateBlinkMotionState(163);
    UpdateBlinkMotionState(164);
    UpdateBlinkMotionState(165);

  } else if (gOverworld.work.subArcadia.unk_000 & (1 << 2)) {
    gOverworld.work.subArcadia.unk_000 ^= (1 << 2);
    ClearBlink(161);
    ClearBlink(162);
    ClearBlink(163);
    ClearBlink(164);
    ClearBlink(165);
  }

  if ((gOverworld.unk_1c8.tilesets[1] >> 8 == STAGE_SUB_ARCADIA) && ((gOverworld.unk_1c8.tilesets[1] & 0xFF) == 3)) {
    if ((gOverworld.work.subArcadia.unk_000 & (1 << 3)) == 0) {
      gOverworld.work.subArcadia.unk_000 |= (1 << 3);
      LoadBlink(154, 0);
      LoadBlink(155, 0);
      LoadBlink(156, 0);
      LoadBlink(157, 0);
      LoadBlink(158, 0);
      LoadBlink(159, 0);
      LoadBlink(160, 0);
    }
    UpdateBlinkMotionState(154);
    UpdateBlinkMotionState(155);
    UpdateBlinkMotionState(156);
    UpdateBlinkMotionState(157);
    UpdateBlinkMotionState(158);
    UpdateBlinkMotionState(159);
    UpdateBlinkMotionState(160);

  } else if (gOverworld.work.subArcadia.unk_000 & (1 << 3)) {
    gOverworld.work.subArcadia.unk_000 ^= (1 << 3);
    ClearBlink(154);
    ClearBlink(155);
    ClearBlink(156);
    ClearBlink(157);
    ClearBlink(158);
    ClearBlink(159);
    ClearBlink(160);
  }

  if (gOverworld.work.subArcadia.unk_001 == 0) {
    if (FLAG(gCurStory.s.gameflags, IN_CYBERSPACE)) {
      gOverworld.work.subArcadia.unk_001 = 1;
      LoadScreenIntoMetatileMap(1, 6, 78);
    }
    if (gOverworld.work.subArcadia.unk_001 == 0) {
      return;
    }
  }

  if (!FLAG(gCurStory.s.gameflags, IN_CYBERSPACE)) {
    gOverworld.work.subArcadia.unk_001 = 1;
    LoadScreenIntoMetatileMap(1, 6, 23);
  }
}

static void nop_08014e78(struct Coord* _ UNUSED) { return; }

static void FUN_08014e7c(struct Coord* _ UNUSED) {
  ClearBlink(0x7c);
  ClearBlink(0x7d);
  ClearBlink(0x7e);
  ClearBlink(0x7f);
  ClearBlink(0x80);
  ClearBlink(0x81);
  ClearBlink(0x82);
  ClearBlink(0x9a);
  ClearBlink(0x9b);
  ClearBlink(0x9c);
  ClearBlink(0x9d);
  ClearBlink(0x9e);
  ClearBlink(0x9f);
  ClearBlink(0xa0);
  ClearBlink(0xa1);
  ClearBlink(0xa2);
  ClearBlink(0xa3);
  ClearBlink(0xa4);
  ClearBlink(0xa5);
  ClearBlink(0xa6);
}

// ------------------------------------------------------------------------------------------------------------------------------------

void FUN_08014efc(struct StageLayer* l, const struct Stage* stage);
void FUN_08014f58(struct StageLayer* l, const struct Stage* stage);

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
      [LAYER_UPDATE] = FUN_08014efc,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
    [3] = {
      [LAYER_UPDATE] = FUN_08014f58,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
};
// clang-format on

INCASM("asm/stage_gfx/sub_arcadia.inc");

// ------------------------------------------------------------------------------------------------------------------------------------

extern const struct ScreenLayout sScreenMap1;
INCBIN_STATIC(sScreenMap1, "data/stage/sub_arcadia/layer1.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08345904 0x08345bc8 ./data/stage/sub_arcadia/layer1.bin

extern const struct ScreenLayout sScreenMap2;
INCBIN_STATIC(sScreenMap2, "data/stage/sub_arcadia/layer2.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08345bc8 0x08345e8c ./data/stage/sub_arcadia/layer2.bin

extern const struct ScreenLayout sScreenMap3;
INCBIN_STATIC(sScreenMap3, "data/stage/sub_arcadia/layer3.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08345e8c 0x08346150 ./data/stage/sub_arcadia/layer3.bin

extern const tileset_ofs_t sTilesetOffset[];
INCBIN_STATIC(sTilesetOffset, "data/stage/sub_arcadia/tileset_offset.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08346150 0x08346414 ./data/stage/sub_arcadia/tileset_offset.bin

extern const u16 sScreenBehavior[];
INCBIN_STATIC(sScreenBehavior, "data/stage/sub_arcadia/screen_behavior.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08346414 0x0834699c ./data/stage/sub_arcadia/screen_behavior.bin

const struct Stage gSubArcadiaLandscape = {
  id : STAGE_SUB_ARCADIA,
  fn : sStageRoutine,
  terrainHdr : &gStageTerrains[STAGE_SUB_ARCADIA],
  maps : {&sScreenMap1, &sScreenMap2, &sScreenMap3},
  bgIdx : {USE_BG1, USE_BG2, USE_BG3},
  prio : {2, 2, 3},
  screenBase : {BGMAP_BLOCK(2), BGMAP_BLOCK(4), BGMAP_BLOCK(6)},
  scrollPower : {{0x100, 0x100}, {0x100, 0x100}, {0x100, 0x100}},
  scroll : {{0, 0}, {0, 0}, {0, 0}},
  tilesetOffset : sTilesetOffset,
  bgFns : sLayerRoutine,
  behavior : sScreenBehavior,
  unk_78 : {0x0, 0x0},
};
