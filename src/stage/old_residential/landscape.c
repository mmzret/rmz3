#include "entity.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"

#define WIDTH 32
#define HEIGHT 18

static const u8 u8_ARRAY_0833dfac[9][2];
static const u8 u8_ARRAY_0833dfbe[14][2];

static void initOldLifeSpace(struct Coord* _ UNUSED);
static void oldLifeSpace_0800dbc4(struct Coord* _ UNUSED);
static void FUN_0800dc6c(struct Coord* _ UNUSED);
static void exitOldLifeSpace(struct Coord* _ UNUSED);

static const StageFunc sStageRoutine[4] = {
    initOldLifeSpace,
    oldLifeSpace_0800dbc4,
    FUN_0800dc6c,
    exitOldLifeSpace,
};

static void initOldLifeSpace(struct Coord* _ UNUSED) {
  gOverworld.work.oldLifeSpace.leaf = NULL;
  gOverworld.work.oldLifeSpace.unk_004[0] = 0;
  gOverworld.work.oldLifeSpace.unk_008 = 0;
  gOverworld.work.oldLifeSpace.unk_00a = 0;
  gOverworld.work.oldLifeSpace.unk_00c = 0;
  gOverworld.work.oldLifeSpace.unk_010 = 0;
  gOverworld.work.oldLifeSpace.unk_012 = 0;
}

static void oldLifeSpace_0800dbc4(struct Coord* _ UNUSED) {
  if (gOverworld.work.oldLifeSpace.leaf == NULL) {
    gOverworld.work.oldLifeSpace.leaf = CreateLeafBurn(0);
  }

  if ((gOverworld.unk_1c8.tilesets[0] >> 8 == STAGE_OLD_RESIDENTIAL) && ((gOverworld.unk_1c8.tilesets[0] & 0xFF) == 0)) {
    gOverworld.work.oldLifeSpace.unk_008++;
    if (gOverworld.work.oldLifeSpace.unk_008 == 132) {
      gOverworld.work.oldLifeSpace.unk_008 = 0;
      gOverworld.work.oldLifeSpace.unk_00a = 0;
    }

    gOverworld.work.oldLifeSpace.unk_00c++;
    if (gOverworld.work.oldLifeSpace.unk_00c == 48) {
      gOverworld.work.oldLifeSpace.unk_00c = 0;
    }

    gOverworld.work.oldLifeSpace.unk_00c++;
    if (gOverworld.work.oldLifeSpace.unk_00c == 60) {
      gOverworld.work.oldLifeSpace.unk_00c = 0;
    }

    gOverworld.work.oldLifeSpace.unk_010++;
    if (gOverworld.work.oldLifeSpace.unk_010 == 183) {
      gOverworld.work.oldLifeSpace.unk_010 = 0;
      gOverworld.work.oldLifeSpace.unk_012 = 0;
    }
  }
}

static void FUN_0800dc6c(struct Coord* _ UNUSED) {
  if ((gOverworld.unk_1c8.tilesets[0] >> 8 == STAGE_OLD_RESIDENTIAL) && ((gOverworld.unk_1c8.tilesets[0] & 0xFF) == 0)) {
    while (gOverworld.work.oldLifeSpace.unk_008 >= u8_ARRAY_0833dfac[gOverworld.work.oldLifeSpace.unk_00a][1]) {
      gOverworld.work.oldLifeSpace.unk_00a++;
    }

    RequestGraphicTransfer(&(TILESETS(18, 42)[u8_ARRAY_0833dfac[gOverworld.work.oldLifeSpace.unk_00a][0]]).g, (void*)0x4000);
    LoadPalette(&(TILESETS(18, 42)[u8_ARRAY_0833dfac[gOverworld.work.oldLifeSpace.unk_00a][0]]).pal, 0);

    RequestGraphicTransfer(&(TILESETS(18, 47)[gOverworld.work.oldLifeSpace.unk_00c / 12]).g, (void*)0x4000);
    LoadPalette(&(TILESETS(18, 47)[gOverworld.work.oldLifeSpace.unk_00c / 12]).pal, 0);

    RequestGraphicTransfer(&(TILESETS(18, 51)[gOverworld.work.oldLifeSpace.unk_00c / 12]).g, (void*)0x4000);
    LoadPalette(&(TILESETS(18, 51)[gOverworld.work.oldLifeSpace.unk_00c / 12]).pal, 0);

    while (gOverworld.work.oldLifeSpace.unk_010 >= u8_ARRAY_0833dfbe[gOverworld.work.oldLifeSpace.unk_012][1]) {
      gOverworld.work.oldLifeSpace.unk_012++;
    }
    RequestGraphicTransfer(&(TILESETS(18, 56)[u8_ARRAY_0833dfbe[gOverworld.work.oldLifeSpace.unk_012][0]]).g, (void*)0x4000);
    LoadPalette(&(TILESETS(18, 56)[u8_ARRAY_0833dfbe[gOverworld.work.oldLifeSpace.unk_012][0]]).pal, 0);
  }
}

static void exitOldLifeSpace(struct Coord* _ UNUSED) {
  struct Solid* leaf = gOverworld.work.oldLifeSpace.leaf;
  if (leaf != NULL) {
    (leaf->s).flags &= ~DISPLAY;
    (leaf->s).flags &= ~FLIPABLE;
    (leaf->body).status = 0;
    (leaf->body).prevStatus = 0;
    (leaf->body).invincibleTime = 0;
    (leaf->s).flags &= ~COLLIDABLE;
    SET_SOLID_ROUTINE(leaf, ENTITY_DISAPPEAR);
  }
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void FUN_0800de98(struct StageLayer* l, const struct Stage* _ UNUSED);
void FUN_0800decc(struct StageLayer* l, const struct Stage* stage);
void FUN_0800dfa4(struct StageLayer* l, const struct Stage* stage);
void FUN_0800dfec(struct StageLayer* l, const struct Stage* stage);
void FUN_0800e030(struct StageLayer* l, const struct Stage* stage);
void FUN_0800e0cc(struct StageLayer* l, const struct Stage* stage);
void ctrlOLSBG3Scroll(struct StageLayer* l, const struct Stage* stage);
void FUN_0800e1f8(struct StageLayer* l, const struct Stage* stage);
void FUN_0800e22c(struct StageLayer* l, const struct Stage* stage);
void FUN_0800e250(struct StageLayer* l, const struct Stage* stage);

// clang-format off
static const StageLayerRoutine sLayerRoutine[10] = {
    [0] = {NULL, NULL, NULL},
    [1] = {NULL, DrawGeneralStageLayer, NULL},
    [2] = {FUN_0800de98, FUN_0800decc, NULL},
    [3] = {FUN_0800dfa4, DrawGeneralStageLayer, NULL},
    [4] = {FUN_0800dfec, DrawGeneralStageLayer, NULL},
    [5] = {FUN_0800e030, DrawGeneralStageLayer, NULL},
    [6] = {FUN_0800e0cc, ctrlOLSBG3Scroll, NULL},
    [7] = {FUN_0800e1f8, DrawGeneralStageLayer, NULL},
    [8] = {FUN_0800e22c, DrawGeneralStageLayer, NULL},
    [9] = {FUN_0800e250, DrawGeneralStageLayer, NULL},
};
// clang-format on

static void FUN_0800de98(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    BGCNT16((l->bgIdx << 16) >> 20) = (BGCNT16((l->bgIdx << 16) >> 20) & 0xFFFC) | 1;
    l->phase++;
  }
}

INCASM("asm/stage_gfx/old_residential.inc");

#include "../../../data/stage/old_residential/layer.h"
//
#include "../../../data/stage/old_residential/landscape.h"

// clang-format off
static const u8 u8_ARRAY_0833dfac[9][2] = {
    {0, 6},
    {1, 12},
    {2, 18}, 
    {3, 30}, 
    {4, 60}, 
    {3, 63}, 
    {2, 66}, 
    {1, 69}, 
    {0, 132},
};
// clang-format on

// clang-format off
static const u8 u8_ARRAY_0833dfbe[14][2] = {
    { 0, 3 },
    { 1, 6 },
    { 0, 9 },
    { 1, 69 },
    { 0, 72 },
    { 1, 75 },
    { 0, 78 },
    { 1, 81 },
    { 0, 84 },
    { 1, 87 },
    { 0, 90 },
    { 1, 93 },
    { 0, 96 },
    { 1, 183 },
};
// clang-format on

// --------------------------------------------

const struct MetatilePatch ALIGNED(2) MetatilePatch_0833dfda = {w : 1, h : 1};
const metatile_id_t MetatilePatchData_0833dfda[2] = {0, 0};  // 2nd element is padding

// --------------------------------------------

const struct MetatilePatch ALIGNED(2) MetatilePatch_0833dfe2 = {w : 2, h : 1};
const metatile_id_t MetatilePatchData_0833dfe2[2] = {0x2B1, 0x2B2};

const struct MetatilePatch ALIGNED(2) MetatilePatch_0833dfea = {w : 2, h : 1};
const metatile_id_t MetatilePatchData_0833dfea[2] = {0x264, 0x272};

const struct MetatilePatch ALIGNED(2) MetatilePatch_0833dff2 = {w : 2, h : 1};
const metatile_id_t MetatilePatchData_0833dff2[2] = {0x273, 0x274};

const struct MetatilePatch ALIGNED(2) MetatilePatch_0833dffa = {w : 2, h : 1};
const metatile_id_t MetatilePatchData_0833dffa[2] = {0x30D, 0x30D};

const struct MetatilePatch ALIGNED(2) MetatilePatch_0833e002 = {w : 2, h : 1};
const metatile_id_t MetatilePatchData_0833e002[2] = {0x13B, 0x11E};

const struct MetatilePatch ALIGNED(2) MetatilePatch_0833e00a = {w : 2, h : 1};
const metatile_id_t MetatilePatchData_0833e00a[2] = {0x11F, 0x30A};

// ./tools/dumper/bin.ts ./baserom.gba 0x0833e012 0x0833e138 ./data/landscape_old_residential.bin
INCBIN("data/landscape_old_residential.bin");

#undef WIDTH
#undef HEIGHT
