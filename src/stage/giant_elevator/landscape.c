#include "blink.h"
#include "global.h"
#include "overworld.h"
#include "story.h"

void FUN_08014b04();

static void initGiantElevator(struct Coord* _ UNUSED);
static void gelevator_08013e88(struct Coord* _ UNUSED);
static void gelevator_08014038(struct Coord* _ UNUSED);
static void nop_080140a4(struct Coord* _ UNUSED);

static const StageFunc sStageRoutine[4] = {
    initGiantElevator,
    gelevator_08013e88,
    gelevator_08014038,
    nop_080140a4,
};

static void initGiantElevator(struct Coord* _ UNUSED) {
  gOverworld.state[0] = 0;
  gOverworld.state[1] = 0;
  gOverworld.work.giantElevator.unk_000[0] = 0;
  gOverworld.work.giantElevator.unk_004 = 0;
  gOverworld.work.giantElevator.unk_006 = 0;
  if (FLAG(gCurStory.s.gameflags, FLAG_49)) {
    FUN_08014b04();
  }
}

static void gelevator_08013e88(struct Coord* _ UNUSED) {
  if ((TILESET_ID(0) == STAGE_GIANT_ELEVATOR) && (TILESET_IDX(0) == 0)) {
    if ((gOverworld.work.giantElevator.unk_000[0] & (1 << 0)) == 0) {
      gOverworld.work.giantElevator.unk_000[0] |= (1 << 0);
      LoadBlink(216, 0);
    }
    UpdateBlinkMotionState(216);

  } else if ((gOverworld.work.giantElevator.unk_000[0] & (1 << 0))) {
    gOverworld.work.giantElevator.unk_000[0] ^= (1 << 0);
    ClearBlink(216);
  }

  if ((TILESET_ID(1) == STAGE_GIANT_ELEVATOR) && (TILESET_IDX(1) == 1)) {
    if ((gOverworld.work.giantElevator.unk_000[0] & (1 << 1)) == 0) {
      gOverworld.work.giantElevator.unk_000[0] |= (1 << 1);
      LoadBlink(215, 0);
    }
    UpdateBlinkMotionState(215);

  } else if ((gOverworld.work.giantElevator.unk_000[0] & (1 << 1))) {
    gOverworld.work.giantElevator.unk_000[0] ^= (1 << 1);
    ClearBlink(215);
  }

  if ((TILESET_ID(1) == STAGE_GIANT_ELEVATOR) && (TILESET_IDX(1) == 2)) {
    if ((gOverworld.work.giantElevator.unk_000[0] & (1 << 2)) == 0) {
      gOverworld.work.giantElevator.unk_000[0] |= (1 << 2);
      LoadBlink(217, 0);
      gOverworld.work.giantElevator.unk_006 = 0;
    }
    UpdateBlinkMotionState(217);
    if (gOverworld.state[0] >= 11) {
      if (gOverworld.work.giantElevator.unk_004 != 0) {
        gOverworld.work.giantElevator.unk_004 -= 2;
      }
    } else if (gOverworld.state[0] > 1) {
      if (gOverworld.work.giantElevator.unk_004 < 256) {
        gOverworld.work.giantElevator.unk_004 += 2;
      } else if (gOverworld.state[0] == 2) {
        gOverworld.state[0]++;
      }
    }
    gOverworld.work.giantElevator.unk_006 += gOverworld.work.giantElevator.unk_004;
    if (gOverworld.work.giantElevator.unk_006 >= 2560) {
      gOverworld.work.giantElevator.unk_006 = 0;
    }

  } else if ((gOverworld.work.giantElevator.unk_000[0] & (1 << 2))) {
    gOverworld.work.giantElevator.unk_000[0] ^= (1 << 2);
    ClearBlink(217);
  }
}

static void gelevator_08014038(struct Coord* _ UNUSED) {
  if ((TILESET_ID(1) == STAGE_GIANT_ELEVATOR) && (TILESET_IDX(1) == 2)) {
    RequestGraphicTransfer(&(TILESETS(18, 153)[gOverworld.work.giantElevator.unk_006 >> 9]).g, (void*)0x4000);
    LoadPalette(&(TILESETS(18, 153)[gOverworld.work.giantElevator.unk_006 >> 9]).pal, 0);
  }
}

static void nop_080140a4(struct Coord* _ UNUSED) {
  // nop
  return;
}

// ------------------------------------------------------------------------------------------------------------------------------------

void FUN_080140a8(struct StageLayer* l, const struct Stage* stage);
void giant_elevator_08014124(struct StageLayer* l, const struct Stage* stage);
void FUN_08014194(struct StageLayer* l, const struct Stage* stage);
void FUN_080141f0(struct StageLayer* l, const struct Stage* stage);
void FUN_08014258(struct StageLayer* l, const struct Stage* stage);
void gelevator_080142b4(struct StageLayer* l, const struct Stage* stage);
void gelevator_08014678(struct StageLayer* l, const struct Stage* stage);
void FUN_0801478c(struct StageLayer* l, const struct Stage* stage);
void giantElevator_08014880(struct StageLayer* l, const struct Stage* stage);
void giantElevator_080148d8(struct StageLayer* l, const struct Stage* stage);
void giantElevator_08014a34(struct StageLayer* l, const struct Stage* stage);
void giantElevator_08014a64(struct StageLayer* l, const struct Stage* stage);
void giantElevator_08014ad4(struct StageLayer* l, const struct Stage* stage);

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
      [LAYER_UPDATE] = FUN_080140a8,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
    [3] = {
      [LAYER_UPDATE] = giant_elevator_08014124,
      [LAYER_DRAW]   = FUN_08014194,
      [LAYER_EXIT]   = NULL,
    },
    [4] = {
      [LAYER_UPDATE] = FUN_080141f0,
      [LAYER_DRAW]   = FUN_08014258,
      [LAYER_EXIT]   = NULL,
    },
    [5] = {
      [LAYER_UPDATE] = gelevator_080142b4,
      [LAYER_DRAW]   = gelevator_08014678,
      [LAYER_EXIT]   = NULL,
    },
    [6] = {
      [LAYER_UPDATE] = FUN_0801478c,
      [LAYER_DRAW]   = giantElevator_08014880,
      [LAYER_EXIT]   = NULL,
    },
    [7] = {
      [LAYER_UPDATE] = giantElevator_080148d8,
      [LAYER_DRAW]   = giantElevator_08014a34,
      [LAYER_EXIT]   = NULL,
    },
    [8] = {
      [LAYER_UPDATE] = giantElevator_08014a64,
      [LAYER_DRAW]   = giantElevator_08014ad4,
      [LAYER_EXIT]   = NULL,
    },
};
// clang-format on

INCASM("asm/stage_gfx/giant_elevator.inc");

// ------------------------------------------------------------------------------------------------------------------------------------

extern const struct ScreenMap sScreenMap1;
INCBIN_STATIC(sScreenMap1, "data/stage/giant_elevator/layer1.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x0834479c 0x08344a60 ./data/stage/giant_elevator/layer1.bin

extern const struct ScreenMap sScreenMap2;
INCBIN_STATIC(sScreenMap2, "data/stage/giant_elevator/layer2.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08344a60 0x08344d24 ./data/stage/giant_elevator/layer2.bin

extern const struct ScreenMap sScreenMap3;
INCBIN_STATIC(sScreenMap3, "data/stage/giant_elevator/layer3.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08344d24 0x08344fe8 ./data/stage/giant_elevator/layer3.bin

extern const tileset_ofs_t sTilesetOffset[];
INCBIN_STATIC(sTilesetOffset, "data/stage/giant_elevator/tileset_offset.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08344fe8 0x083452ac ./data/stage/giant_elevator/tileset_offset.bin

extern const u16 sScreenBehavior[];
INCBIN_STATIC(sScreenBehavior, "data/stage/giant_elevator/screen_behavior.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x083452ac 0x08345834 ./data/stage/giant_elevator/screen_behavior.bin

const struct Stage gGiantElevatorLandscape = {
  id : STAGE_GIANT_ELEVATOR,
  fn : sStageRoutine,
  terrainHdr : &gStageTerrains[STAGE_GIANT_ELEVATOR],
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

static const struct MetatileShift sMetatileShift1 = {x : 247, y : 130, block : 8, row : 30};
static const struct MetatileShift sMetatileShift2 = {x : 179, y : 114, block : 1, row : 4};
