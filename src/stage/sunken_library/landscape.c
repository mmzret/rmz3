#include "blink.h"
#include "global.h"
#include "overworld.h"

#define STAGE (gOverworld.work.sunkenLib)

static void initSunkenLib(struct Coord* _ UNUSED);
static void updateSunkenLib(struct Coord* _ UNUSED);
static void FUN_080136a0(struct Coord* _ UNUSED);
static void exitSunkenLibrary(struct Coord* _ UNUSED);

static const StageFunc sGfxRoutine[4] = {
    initSunkenLib,
    updateSunkenLib,
    FUN_080136a0,
    exitSunkenLibrary,
};

static void initSunkenLib(struct Coord* _ UNUSED) {
  gOverworld.unk_1c8.work[0] = 0;
  STAGE.unk_000 = 0;
  STAGE.unk_001 = 0;
  STAGE.unk_002 = 0;
  STAGE.theta = 0;
  STAGE.rng = 0;
  SEA = PIXEL(568);
  LoadBlink(150, 0);
}

WIP static void updateSunkenLib(struct Coord* _ UNUSED) {
#if MODERN
  if ((TILESET_ID(0) == STAGE_SUNKEN_LIBRARY) && (TILESET_IDX(0) == 4)) {
    if ((STAGE.unk_000 & (1 << 0)) == 0) {
      STAGE.unk_000 |= (1 << 0);
      LoadBlink(148, 0);
      LoadBlink(149, 0);
    }
    UpdateBlinkMotionState(148);
    UpdateBlinkMotionState(149);

  } else if ((STAGE.unk_000 & (1 << 0))) {
    STAGE.unk_000 ^= (1 << 0);
    ClearBlink(148);
    ClearBlink(149);
  }

  if ((TILESET_ID(1) == STAGE_SUNKEN_LIBRARY) && (TILESET_IDX(1) == 5)) {
    if ((STAGE.unk_000 & (1 << 1)) == 0) {
      STAGE.unk_000 |= (1 << 1);
      LoadBlink(153, 0);
    }
    UpdateBlinkMotionState(153);

  } else if ((STAGE.unk_000 & (1 << 1))) {
    STAGE.unk_000 ^= (1 << 1);
    ClearBlink(153);
  }

  UpdateBlinkMotionState(150);

  if (STAGE.unk_001 == 0) {
    if (STAGE.unk_002 == 0) {
      STAGE.rng = LCG(STAGE.rng);
      STAGE.unk_002 = ((STAGE.rng >> 16) & 1) + 1;
      STAGE.unk_001 = 8;
    } else {
      STAGE.unk_002 = 0;
      STAGE.rng = LCG(STAGE.rng);
      STAGE.unk_001 = (((STAGE.rng >> 16) % 58) & 0xF8) + 7;
    }
  }

  STAGE.unk_001--;
  STAGE.theta++;
  SEA = gSineTable[STAGE.theta] * 24 + PIXEL(568);
  gBlendRegBuffer.bldalpha = 0xC04;
#else
  INCCODE("asm/wip/updateSunkenLib.inc");
#endif
}

WIP static void FUN_080136a0(struct Coord* _ UNUSED) {
#if MODERN
  if ((TILESET_ID(0) == STAGE_SUNKEN_LIBRARY) && (TILESET_IDX(0) == 4)) {
    if (STAGE.unk_002 != 0) {
      RequestGraphicTransfer(&(TILESETS(18, 72)[(STAGE.unk_002 << 1) + (STAGE.unk_001 >> 2)]).g, (void*)0x4000);
      LoadPalette(&(TILESETS(18, 72)[(STAGE.unk_002 << 1) + (STAGE.unk_001 >> 2)]).pal, 0);
    } else {
      RequestGraphicTransfer(&(TILESETS(18, 72)[(STAGE.unk_001 >> 2) & 1]).g, (void*)0x4000);
      LoadPalette(&(TILESETS(18, 72)[(STAGE.unk_001 >> 2) & 1]).pal, 0);
    }
  }
#else
  INCCODE("asm/wip/FUN_080136a0.inc");
#endif
}

static void exitSunkenLibrary(struct Coord* _ UNUSED) {
  SEA = PIXEL(10240);
  ClearBlink(148);
  ClearBlink(149);
  ClearBlink(150);
  ClearBlink(151);
  ClearBlink(152);
  ClearBlink(153);
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void LayerUpdate_2(struct StageLayer* l, const struct Stage* _ UNUSED);
void FUN_08013898(struct StageLayer* l, const struct Stage* stage);
void FUN_08013908(struct StageLayer* l, const struct Stage* stage);
void sunkenlib_08013930(struct StageLayer* l, const struct Stage* stage);
void FUN_08013a98(struct StageLayer* l, const struct Stage* stage);
void FUN_08013b10(struct StageLayer* l, const struct Stage* stage);
void sunkenlib_08013b6c(struct StageLayer* l, const struct Stage* stage);
void FUN_08013bdc(struct StageLayer* l, const struct Stage* stage);
void sunkenLib_08013c0c(struct StageLayer* l, const struct Stage* stage);
void FUN_08013d38(struct StageLayer* l, const struct Stage* stage);
void FUN_08013dd4(struct StageLayer* l, const struct Stage* stage);

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
      [LAYER_UPDATE] = LayerUpdate_2,
      [LAYER_DRAW]   = FUN_08013898,
      [LAYER_EXIT]   = FUN_08013908,
    },
    [3] = {
      [LAYER_UPDATE] = sunkenlib_08013930,
      [LAYER_DRAW]   = FUN_08013a98,
      [LAYER_EXIT]   = FUN_08013b10,
    },
    [4] = {
      [LAYER_UPDATE] = sunkenlib_08013b6c,
      [LAYER_DRAW]   = FUN_08013bdc,
      [LAYER_EXIT]   = NULL,
    },
    [5] = {
      [LAYER_UPDATE] = sunkenLib_08013c0c,
      [LAYER_DRAW]   = FUN_08013d38,
      [LAYER_EXIT]   = FUN_08013dd4,
    },
};
// clang-format on

static void LayerUpdate_2(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    const u16 n = l->bgIdx;
    BGCNT16(n >> 4) = l->prio | l->screenBase | 0x8044;
    *(u32*)gVideoRegBuffer.bgofs[n >> 4] = 0;
    CpuFastCopy(BGMAP(67), (void*)(VRAM + SCREEN_BASE_16(n >> 4)), 2048);
    CpuFastCopy(BGMAP(68), (void*)(VRAM + 0x800 + SCREEN_BASE_16(n >> 4)), 2048);
    gBlendRegBuffer.bldclt = 0x3B44;
    gBlendRegBuffer.bldalpha = 0xC04;
    gWindowRegBuffer.dispcnt |= 0x4000;
    gWindowRegBuffer.unk_0c[1] = 0xF3;
    gWindowRegBuffer.unk_0c[2] |= 0xE;
    *((u16*)&gWindowRegBuffer.winH + 1) = 0xFF;
    l->unk_10 = 0;
    l->phase++;
  }
}

INCASM("asm/stage_gfx/sunken_library.inc");

// ------------------------------------------------------------------------------------------------------------------------------------

extern const struct ScreenLayout sScreenMap1;
INCBIN_STATIC(sScreenMap1, "data/stage/sunken_library/layer1.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08343fc8 0x083440ec ./data/stage/sunken_library/layer1.bin

extern const struct ScreenLayout sScreenMap2;
INCBIN_STATIC(sScreenMap2, "data/stage/sunken_library/layer2.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x083440ec 0x08344210 ./data/stage/sunken_library/layer2.bin

extern const struct ScreenLayout sScreenMap3;
INCBIN_STATIC(sScreenMap3, "data/stage/sunken_library/layer3.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08344210 0x08344334 ./data/stage/sunken_library/layer3.bin

extern const tileset_ofs_t sTilesetOffset[];
INCBIN_STATIC(sTilesetOffset, "data/stage/sunken_library/tileset_offset.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08344334 0x08344458 ./data/stage/sunken_library/tileset_offset.bin

extern const u16 sScreenBehavior[];
INCBIN_STATIC(sScreenBehavior, "data/stage/sunken_library/screen_behavior.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x08344458 0x083446a0 ./data/stage/sunken_library/screen_behavior.bin

const struct Stage gSunkenLibraryLandscape = {
  id : STAGE_SUNKEN_LIBRARY,
  fn : sGfxRoutine,
  terrainHdr : &gStageTerrains[STAGE_SUNKEN_LIBRARY],
  maps : {&sScreenMap1, &sScreenMap2, &sScreenMap3},
  bgIdx : {USE_BG1, USE_BG2, USE_BG3},
  prio : {2, 0, 3},
  screenBase : {BGMAP_BLOCK(2), BGMAP_BLOCK(4), BGMAP_BLOCK(6)},
  scrollPower : {{0x100, 0x100}, {0x100, 0x100}, {0x100, 0x100}},
  scroll : {{0, 0}, {0, 0}, {0, 0}},
  tilesetOffset : sTilesetOffset,
  bgFns : sLayerRoutine,
  behavior : sScreenBehavior,
  unk_78 : {0x0, 0x0},
};
