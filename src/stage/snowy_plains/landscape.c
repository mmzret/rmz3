#include "global.h"
#include "overworld.h"

extern const struct Coord gSnowyPlainMetatileShift1;
extern const struct Coord gSnowyPlainMetatileShift2;

static void initSnowyPlains(struct Coord* _ UNUSED);
static void nop_08012b18(struct Coord* _ UNUSED);
static void nop_08012b1c(struct Coord* _ UNUSED);
static void nop_08012b20(struct Coord* _ UNUSED);

static const StageFunc sStageRoutine[4] = {
    initSnowyPlains,
    nop_08012b18,
    nop_08012b1c,
    nop_08012b20,
};

static void initSnowyPlains(struct Coord* _ UNUSED) {
  struct Coord shift1, shift2;
  shift1 = gSnowyPlainMetatileShift1;
  shift2 = gSnowyPlainMetatileShift2;
  ShiftMetatile(0, 0x51, (struct MetatileShift*)&shift1);
  ShiftMetatile(0xf0, 0x6f, (struct MetatileShift*)&shift2);
}

static void nop_08012b18(struct Coord* _ UNUSED) { return; }

static void nop_08012b1c(struct Coord* _ UNUSED) { return; }

static void nop_08012b20(struct Coord* _ UNUSED) { return; }

// ------------------------------------------------------------------------------------------------------------------------------------

static void LayerUpdate_2(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerUpdate_3(struct StageLayer* l, const struct Stage* _ UNUSED);
void snowyPlains_08012b9c(struct StageLayer* l, const struct Stage* stage);
void FUN_08012bfc(struct StageLayer* l, const struct Stage* stage);
void snowyPlains_08012fec(struct StageLayer* l, const struct Stage* stage);
void FUN_0801304c(struct StageLayer* l, const struct Stage* stage);
void snowyplains_0801320c(struct StageLayer* l, const struct Stage* stage);
void snowyplains_0801326c(struct StageLayer* l, const struct Stage* stage);
void snowyplains_080133b4(struct StageLayer* l, const struct Stage* stage);

// clang-format off
static const StageLayerRoutine sLayerRoutine[8] = {
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
      [LAYER_UPDATE] = snowyPlains_08012b9c,
      [LAYER_DRAW]   = FUN_08012bfc,
      [LAYER_EXIT]   = NULL,
    },
    [5] = {
      [LAYER_UPDATE] = snowyPlains_08012fec,
      [LAYER_DRAW]   = FUN_0801304c,
      [LAYER_EXIT]   = NULL,
    },
    [6] = {
      [LAYER_UPDATE] = snowyplains_0801320c,
      [LAYER_DRAW]   = snowyplains_0801326c,
      [LAYER_EXIT]   = NULL,
    },
    [7] = {
      [LAYER_UPDATE] = snowyplains_080133b4,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
};
// clang-format on

static void LayerUpdate_2(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    const u16 n = l->bgIdx;
    BGCNT16(n >> 4) = (BGCNT16(n >> 4) & 0xFFFC) | 3;
    l->phase++;
  }
}

static void LayerUpdate_3(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    const u16 n = l->bgIdx;
    BGCNT16(n >> 4) = (BGCNT16(n >> 4) & 0xFFFC) | 3;
    (l->scrollPower).x = 0x60;
    (l->scrollPower).y = 0x60;
    (l->scroll).x = 0x96;
    (l->scroll).y = 0x64;
    l->phase++;
  }
}

INCASM("asm/stage_gfx/snowy_plains.inc");

// ------------------------------------------------------------------------------------------------------------------------------------

extern const struct ScreenMap sScreenMap1;
INCBIN_STATIC(sScreenMap1, "data/stage/snowy_plains/layer1.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x083428b8 0x08342abc ./data/stage/snowy_plains/layer1.bin

extern const struct ScreenMap sScreenMap2;
INCBIN_STATIC(sScreenMap2, "data/stage/snowy_plains/layer2.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08342abc 0x08342ec0 ./data/stage/snowy_plains/layer2.bin

extern const struct ScreenMap sScreenMap3;
INCBIN_STATIC(sScreenMap3, "data/stage/snowy_plains/layer3.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08342ec0 0x083432c4 ./data/stage/snowy_plains/layer3.bin

extern const tileset_ofs_t sTilesetOffset[];
INCBIN_STATIC(sTilesetOffset, "data/stage/snowy_plains/tileset_offset.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x083432c4 0x083436c8 ./data/stage/snowy_plains/tileset_offset.bin

extern const u16 sScreenBehavior[];
INCBIN_STATIC(sScreenBehavior, "data/stage/snowy_plains/screen_behavior.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x083436c8 0x08343ed0 ./data/stage/snowy_plains/screen_behavior.bin

const struct Stage gSnowyPlainsLandscape = {
  id : STAGE_SNOWY_PLAINS,
  fn : sStageRoutine,
  terrainHdr : &gStageTerrains[STAGE_SNOWY_PLAINS],
  maps : {&sScreenMap1, &sScreenMap2, &sScreenMap3},
  bgIdx : {USE_BG2, USE_BG1, USE_BG3},
  prio : {2, 1, 3},
  screenBase : {BGMAP_BLOCK(2), BGMAP_BLOCK(4), BGMAP_BLOCK(6)},
  scrollPower : {{0x100, 0x100}, {0x100, 0x100}, {0x100, 0x100}},
  scroll : {{0, 0}, {0, 0}, {0, 0}},
  tilesetOffset : sTilesetOffset,
  bgFns : sLayerRoutine,
  behavior : sScreenBehavior,
  unk_78 : {0x0, 0x0},
};

const struct MetatilePatch MetatilePatch_08343f50 = {w : 2, h : 1};
const metatile_id_t MetatilePatchData_08343f50[2] = {0x0, 0x0};

const struct MetatilePatch MetatilePatch_08343f58 = {w : 2, h : 1};
const metatile_id_t MetatilePatchData_08343f58[2] = {0x0, 0x217};

const struct MetatilePatch MetatilePatch_08343f60 = {w : 2, h : 1};
const metatile_id_t MetatilePatchData_08343f60[2] = {0x1D2, 0x1D3};

const struct MetatilePatch MetatilePatch_08343f68 = {w : 2, h : 1};
const metatile_id_t MetatilePatchData_08343f68[2] = {0x217, 0x0};
