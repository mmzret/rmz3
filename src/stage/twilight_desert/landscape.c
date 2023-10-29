#include "blink.h"
#include "gfx.h"
#include "global.h"
#include "overworld.h"
#include "story.h"

static void initTwilightDesert(struct Coord* _ UNUSED);
static void FUN_0800f8dc(struct Coord* c);
static void nop_0800f9bc(struct Coord* _ UNUSED);
static void exitTwilightDesert(struct Coord* _ UNUSED);

static const StageFunc sStageRoutine[4] = {
    initTwilightDesert,
    FUN_0800f8dc,
    nop_0800f9bc,
    exitTwilightDesert,
};

static void initTwilightDesert(struct Coord* _ UNUSED) {
  gOverworld.work.twilightDesert.unk_004 = 0;
  gOverworld.work.twilightDesert.unk_001 = 0;
  LoadBlink(131, 0);
  LoadBlink(132, 0);
}

static void FUN_0800f8dc(struct Coord* c) {
  if (gOverworld.work.twilightDesert.unk_004 != 0) {
    if (!FLAG(gCurStory.s.gameflags, TIME_ELF_ENABLED) && !isSoundPlaying(SE_UNK_102)) {
      PlaySound(SE_UNK_102);
    }
    if ((gOverworld.work.twilightDesert.unk_004 != 0) && !FLAG(gCurStory.s.gameflags, TIME_ELF_ENABLED)) {
      goto _SKIP;
    }
  }
  if (isSoundPlaying(SE_UNK_102)) {
    stopSound(SE_UNK_102);
  }

_SKIP:
  if (c->x < 0x1fe001) {
    if (((c->x - 0x7a000U < 0x7b001) || (c->x - 0xff000U < 0x2f001)) || (c->x - 0x185000U < 0x2e001)) {
      if (!isSoundPlaying(SE_UNK_c6)) {
        PlaySound(SE_UNK_c6);
      }
      SetStageNoiseVolume(SE_UNK_c6);
    } else {
      if (isSoundPlaying(SE_UNK_c6)) {
        stopSound(SE_UNK_c6);
      }
    }
  }
  UpdateBlinkMotionState(131);
  UpdateBlinkMotionState(132);
}

static void nop_0800f9bc(struct Coord* _ UNUSED) { return; }

static void exitTwilightDesert(struct Coord* _ UNUSED) {
  ClearBlink(131);
  ClearBlink(132);
}

// ------------------------------------------------------------------------------------------------------------------------------------

void desert_0800f9d4(struct StageLayer* l, const struct Stage* stage);
void FUN_0800fa34(struct StageLayer* l, const struct Stage* stage);
void desert_0800fb88(struct StageLayer* l, const struct Stage* stage);
void desert_0800ff98(struct StageLayer* l, const struct Stage* stage);
void FUN_08010044(struct StageLayer* l, const struct Stage* stage);
void FUN_08010120(struct StageLayer* l, const struct Stage* stage);
void FUN_08010148(struct StageLayer* l, const struct Stage* stage);

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
      [LAYER_UPDATE] = desert_0800f9d4,
      [LAYER_DRAW]   = FUN_0800fa34,
      [LAYER_EXIT]   = NULL,
    },
    [3] = {
      [LAYER_UPDATE] = desert_0800fb88,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
    [4] = {
      [LAYER_UPDATE] = desert_0800ff98,
      [LAYER_DRAW]   = FUN_08010044,
      [LAYER_EXIT]   = FUN_08010120,
    },
    [5] = {
      [LAYER_UPDATE] = FUN_08010148,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
};
// clang-format on

INCASM("asm/stage_gfx/twilight_desert.inc");

extern const struct ScreenMap sScreenMap1;
INCBIN_STATIC(sScreenMap1, "data/stage/twilight_desert/layer1.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x0833ee94 0x0833f018 ./data/stage/twilight_desert/layer1.bin

extern const struct ScreenMap sScreenMap2;
INCBIN_STATIC(sScreenMap2, "data/stage/twilight_desert/layer2.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x0833f018 0x0833f19c ./data/stage/twilight_desert/layer2.bin

extern const struct ScreenMap sScreenMap3;
INCBIN_STATIC(sScreenMap3, "data/stage/twilight_desert/layer3.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x0833f19c 0x0833f320 ./data/stage/twilight_desert/layer3.bin

extern const tileset_ofs_t sTilesetOffset[];
INCBIN_STATIC(sTilesetOffset, "data/stage/twilight_desert/tileset_offset.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x0833f320 0x0833f4a4 ./data/stage/twilight_desert/tileset_offset.bin

extern const u16 sScreenBehavior[];
INCBIN_STATIC(sScreenBehavior, "data/stage/twilight_desert/screen_behavior.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x0833f4a4 0x0833f7ac ./data/stage/twilight_desert/screen_behavior.bin

const struct Stage gTwilightDesertLandscape = {
  id : STAGE_TWILIGHT_DESERT,
  fn : sStageRoutine,
  terrainHdr : &gStageTerrains[STAGE_TWILIGHT_DESERT],
  maps : {&sScreenMap1, &sScreenMap2, &sScreenMap3},
  bgIdx : {USE_BG2, USE_BG1, USE_BG3},
  prio : {2, 1, 3},
  screenBase : {BGMAP_BLOCK(2), BGMAP_BLOCK(4), BGMAP_BLOCK(6)},
  scrollPower : {{0x100, 0x100}, {0x100, 0x100}, {0x100, 0x100}},
  scroll : {{0, 0}, {0, 0}, {0, 0}},
  tilesetOffset : sTilesetOffset,
  bgFns : sLayerRoutine,
  behavior : sScreenBehavior,
  unk_78 : {-0x100, 0x100},
};
