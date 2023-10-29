#include "global.h"
#include "overworld.h"
#include "solid.h"

#define STAGE (gOverworld.work.oldResidential)

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
  STAGE.leaf = NULL;
  STAGE.unk_004[0] = 0;
  STAGE.unk_008 = 0;
  STAGE.unk_00a = 0;
  STAGE.unk_00c = 0;
  STAGE.unk_010 = 0;
  STAGE.unk_012 = 0;
}

static void oldLifeSpace_0800dbc4(struct Coord* _ UNUSED) {
  if (STAGE.leaf == NULL) {
    STAGE.leaf = CreateLeafBurn(0);
  }

  if ((TILESET_ID(0) == STAGE_OLD_RESIDENTIAL) && (TILESET_IDX(0) == 0)) {
    STAGE.unk_008++;
    if (STAGE.unk_008 == 132) {
      STAGE.unk_008 = 0;
      STAGE.unk_00a = 0;
    }

    STAGE.unk_00c++;
    if (STAGE.unk_00c == 48) {
      STAGE.unk_00c = 0;
    }

    STAGE.unk_00c++;
    if (STAGE.unk_00c == 60) {
      STAGE.unk_00c = 0;
    }

    STAGE.unk_010++;
    if (STAGE.unk_010 == 183) {
      STAGE.unk_010 = 0;
      STAGE.unk_012 = 0;
    }
  }
}

static void FUN_0800dc6c(struct Coord* _ UNUSED) {
  if ((TILESET_ID(0) == STAGE_OLD_RESIDENTIAL) && (TILESET_IDX(0) == 0)) {
    while (STAGE.unk_008 >= u8_ARRAY_0833dfac[STAGE.unk_00a][1]) {
      STAGE.unk_00a++;
    }

    RequestGraphicTransfer(&(TILESETS(18, 42)[u8_ARRAY_0833dfac[STAGE.unk_00a][0]]).g, (void*)0x4000);
    LoadPalette(&(TILESETS(18, 42)[u8_ARRAY_0833dfac[STAGE.unk_00a][0]]).pal, 0);

    RequestGraphicTransfer(&(TILESETS(18, 47)[STAGE.unk_00c / 12]).g, (void*)0x4000);
    LoadPalette(&(TILESETS(18, 47)[STAGE.unk_00c / 12]).pal, 0);

    RequestGraphicTransfer(&(TILESETS(18, 51)[STAGE.unk_00c / 12]).g, (void*)0x4000);
    LoadPalette(&(TILESETS(18, 51)[STAGE.unk_00c / 12]).pal, 0);

    while (STAGE.unk_010 >= u8_ARRAY_0833dfbe[STAGE.unk_012][1]) {
      STAGE.unk_012++;
    }
    RequestGraphicTransfer(&(TILESETS(18, 56)[u8_ARRAY_0833dfbe[STAGE.unk_012][0]]).g, (void*)0x4000);
    LoadPalette(&(TILESETS(18, 56)[u8_ARRAY_0833dfbe[STAGE.unk_012][0]]).pal, 0);
  }
}

static void exitOldLifeSpace(struct Coord* _ UNUSED) {
  struct Solid* leaf = STAGE.leaf;
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

static void LayerUpdate_2(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerDraw_2(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerUpdate_3(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerUpdate_4(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerUpdate_5(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerUpdate_6(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerDraw_6(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerUpdate_7(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerUpdate_8(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerUpdate_9(struct StageLayer* l, const struct Stage* _ UNUSED);

// clang-format off
static const StageLayerRoutine sLayerRoutine[10] = {
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
      [LAYER_DRAW]   = LayerDraw_2,
      [LAYER_EXIT]   = NULL,
    },
    [3] = {
      [LAYER_UPDATE] = LayerUpdate_3,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
    [4] = {
      [LAYER_UPDATE] = LayerUpdate_4,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
    [5] = {
      [LAYER_UPDATE] = LayerUpdate_5,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
    [6] = {
      [LAYER_UPDATE] = LayerUpdate_6,
      [LAYER_DRAW]   = LayerDraw_6,
      [LAYER_EXIT]   = NULL,
    },
    [7] = {
      [LAYER_UPDATE] = LayerUpdate_7,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
    [8] = {
      [LAYER_UPDATE] = LayerUpdate_8,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
    [9] = {
      [LAYER_UPDATE] = LayerUpdate_9,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = NULL,
    },
};
// clang-format on

static void LayerUpdate_2(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    BGCNT16((l->bgIdx << 16) >> 20) = (BGCNT16((l->bgIdx << 16) >> 20) & 0xFFFC) | 1;
    l->phase++;
  }
}

static void LayerDraw_2(struct StageLayer* l, const struct Stage* _ UNUSED) {
  s32 x, y;
  u32 dx, dy;
  struct Coord c;
  struct LayerGraphic* g;

  g = &l->gfx;

  x = (l->viewportCenterPixel).x;
  y = (l->viewportCenterPixel).y;

  dx = (u32)(x - (l->prevViewportCenterPixel).x) + 15;
  dy = (u32)(y - (l->prevViewportCenterPixel).y) + 15;

  y += 160 * 10;

  c.x = COORD_TO_PIXEL((l->drawPivotOffset).x) + x;
  c.y = COORD_TO_PIXEL((l->drawPivotOffset).y) + y;

  if ((dx >= 31) || (dy >= 31) || (STAGE.unk_004[0] != 0)) {
    FUN_08006ae0(g, &c, (u32*)(VRAM + SCREEN_BASE_16(l->bgIdx >> 4)), &gOverworld.tilemap);
  } else {
    FUN_08006bb4(g, &c, (u32*)(VRAM + SCREEN_BASE_16(l->bgIdx >> 4)), &gOverworld.tilemap);
  }

  STAGE.unk_004[0] = 0;
  UpdateBGOFS(g, BGOFS(l->bgIdx >> 4));
}

static void LayerUpdate_3(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    const u16 n = l->bgIdx;
    BGCNT16(n >> 4) = (BGCNT16(n >> 4) & 0xFFFC) | 2;
    (l->scrollPower).x = 0x100;
    (l->scrollPower).y = 0x80;
    (l->scroll).x = 0;
    (l->scroll).y = 480;
    l->phase++;
  }
}

static void LayerUpdate_4(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    const u16 n = l->bgIdx;
    BGCNT16(n >> 4) = (BGCNT16(n >> 4) & 0xFFFC) | 2;
    (l->scrollPower).x = 0x100;
    (l->scrollPower).y = 0x0;
    (l->scroll).x = 0;
    (l->scroll).y = 160;
    l->phase++;
  }
}

static void LayerUpdate_5(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    const u16 n = l->bgIdx;
    BGCNT16(n >> 4) = (BGCNT16(n >> 4) & 0xFFFC) | 2;
    l->phase++;
  }

  if ((l->viewportCenterPixel).x < 960) {
    (l->scrollPower).x = 0x40;
    (l->scrollPower).y = 0x100;
    (l->scroll).x = 180;
    (l->scroll).y = 0;
  } else if ((l->viewportCenterPixel).y >= 321) {
    (l->scrollPower).x = 0x40;
    (l->scrollPower).y = 0x40;
    (l->scroll).x = 1260;
    (l->scroll).y = 360;
  } else if ((l->viewportCenterPixel).x < 1920) {
    (l->scrollPower).x = 0x40;
    (l->scrollPower).y = 0x40;
    (l->scroll).x = 1260;
    (l->scroll).y = 120;
  } else {
    (l->scrollPower).x = 0xc0;
    (l->scrollPower).y = 0xc0;
    (l->scroll).x = 540;
    (l->scroll).y = 40;
  }
}

static void LayerUpdate_6(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    const u16 n = l->bgIdx;
    BGCNT16(n >> 4) = l->screenBase | 0x47;
    LoadBgMap(n, gBgMapOffsets, 55, 0, 0);
    l->phase++;
  }
}

// 0x0800e114
NAKED static void LayerDraw_6(struct StageLayer* l, const struct Stage* _ UNUSED) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	ldr r2, [r0, #0x5c]\n\
	lsls r2, r2, #0x10\n\
	lsrs r7, r2, #0x10\n\
	ldr r1, [r0, #0x38]\n\
	ldr r3, _0800E188 @ =0xFFFFFC40\n\
	adds r1, r1, r3\n\
	asrs r5, r1, #2\n\
	lsrs r2, r2, #0x14\n\
	lsls r2, r2, #2\n\
	ldr r1, _0800E18C @ =gVideoRegBuffer+12\n\
	adds r3, r2, r1\n\
	ldr r0, [r0, #0x34]\n\
	asrs r0, r0, #2\n\
	strh r0, [r3]\n\
	adds r1, #2\n\
	adds r2, r2, r1\n\
	strh r5, [r2]\n\
	cmp r5, #0x57\n\
	bgt _0800E1E8\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #2\n\
	bl Malloc\n\
	adds r4, r0, #0\n\
	cmp r4, #0\n\
	beq _0800E1E8\n\
	ldr r2, _0800E190 @ =gIntrManager\n\
	movs r1, #0xba\n\
	lsls r1, r1, #1\n\
	adds r0, r2, r1\n\
	str r4, [r0]\n\
	movs r3, #0xbc\n\
	lsls r3, r3, #1\n\
	adds r1, r2, r3\n\
	ldr r0, _0800E194 @ =0x0400001C\n\
	str r0, [r1]\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r2, r0\n\
	ldr r0, _0800E198 @ =0xA6600001\n\
	str r0, [r1]\n\
	cmp r5, #0\n\
	ble _0800E19C\n\
	movs r3, #0\n\
	movs r0, #0x58\n\
	subs r0, r0, r5\n\
	cmp r3, r0\n\
	bge _0800E1AE\n\
	lsls r2, r5, #0x10\n\
	adds r1, r4, #0\n\
	adds r3, r0, #0\n\
_0800E17C:\n\
	stm r1!, {r2}\n\
	subs r3, #1\n\
	cmp r3, #0\n\
	bne _0800E17C\n\
	adds r3, r0, #0\n\
	b _0800E1AE\n\
	.align 2, 0\n\
_0800E188: .4byte 0xFFFFFC40\n\
_0800E18C: .4byte gVideoRegBuffer+12\n\
_0800E190: .4byte gIntrManager\n\
_0800E194: .4byte 0x0400001C\n\
_0800E198: .4byte 0xA6600001\n\
_0800E19C:\n\
	movs r1, #0\n\
	movs r2, #0xae\n\
	lsls r2, r2, #1\n\
	adds r0, r4, r2\n\
_0800E1A4:\n\
	str r1, [r0]\n\
	subs r0, #4\n\
	cmp r0, r4\n\
	bge _0800E1A4\n\
	movs r3, #0x58\n\
_0800E1AE:\n\
	adds r0, r5, r3\n\
	cmp r0, #0x57\n\
	bgt _0800E1CE\n\
	lsls r0, r3, #0x10\n\
	movs r1, #0xb0\n\
	lsls r1, r1, #0xf\n\
	subs r1, r1, r0\n\
	lsls r0, r3, #2\n\
	adds r2, r0, r4\n\
	ldr r6, _0800E1F0 @ =0xFFFF0000\n\
_0800E1C2:\n\
	stm r2!, {r1}\n\
	adds r1, r1, r6\n\
	adds r3, #1\n\
	adds r0, r5, r3\n\
	cmp r0, #0x57\n\
	ble _0800E1C2\n\
_0800E1CE:\n\
	cmp r3, #0x9f\n\
	bgt _0800E1E8\n\
	lsrs r0, r7, #4\n\
	lsls r0, r0, #2\n\
	ldr r1, _0800E1F4 @ =gVideoRegBuffer+12\n\
	adds r2, r0, r1\n\
	lsls r0, r3, #2\n\
	adds r1, r0, r4\n\
_0800E1DE:\n\
	ldr r0, [r2]\n\
	stm r1!, {r0}\n\
	adds r3, #1\n\
	cmp r3, #0x9f\n\
	ble _0800E1DE\n\
_0800E1E8:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0800E1F0: .4byte 0xFFFF0000\n\
_0800E1F4: .4byte gVideoRegBuffer+12\n\
 .syntax divided\n");
}

static void LayerUpdate_7(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    const u16 n = l->bgIdx;
    BGCNT16(n >> 4) = (BGCNT16(n >> 4) & 0xFFFC) | 1;
    l->phase++;
  }
}

static void LayerUpdate_8(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    (l->scrollPower).x = 0;
    (l->scrollPower).y = 0;
    (l->scroll).x = 3120;
    (l->scroll).y = 160;
    l->phase++;
  }
}

static void LayerUpdate_9(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    const u16 n = l->bgIdx;
    BGCNT16(n >> 4) = (BGCNT16(n >> 4) & 0xFFFC) | 2;
    l->phase++;
  }
}

NAKED metatile_attr_t FUN_0800e284(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	adds r3, r1, #0\n\
	ldr r0, _0800E294 @ =0x0004FFFF\n\
	cmp r3, r0\n\
	ble _0800E298\n\
	movs r0, #0\n\
	b _0800E2B8\n\
	.align 2, 0\n\
_0800E294: .4byte 0x0004FFFF\n\
_0800E298:\n\
	ldr r2, _0800E2C0 @ =gOverworld\n\
	movs r0, #0xfc\n\
	lsls r0, r0, #3\n\
	adds r2, r2, r0\n\
	ldrh r1, [r2]\n\
	movs r5, #0xc8\n\
	lsls r5, r5, #0xb\n\
	adds r0, r3, r5\n\
	asrs r0, r0, #0xc\n\
	muls r0, r1, r0\n\
	asrs r1, r4, #0xc\n\
	adds r0, r0, r1\n\
	adds r0, #2\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	ldrh r0, [r0]\n\
_0800E2B8:\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0800E2C0: .4byte gOverworld\n\
 .syntax divided\n");
}

static const struct MetatilePatch2x1 ALIGNED(2) sMetatilePatch2x1_0833dfda;

void FUN_0800e2c4(s32 x, s32 y) {
  bool16 val;
  s32 mx, my;

  if (y < PIXEL(1280)) {
    val = gOverworld.unk_2c000;
    mx = METACOORD(x);
    my = METACOORD(y + PIXEL(1600));
    PatchMetatileMap(mx, my, (struct MetatilePatch*)&sMetatilePatch2x1_0833dfda);
    gOverworld.unk_2c000 = val;
    STAGE.unk_004[0] = 1;
  }
}

INCASM("asm/stage_gfx/old_residential.inc");

static const struct MetatilePatch2x2 ALIGNED(2) sDefaultMetatilePatch2x2;
static const struct Coord sMetatilePatch2x2Coords[12];
static const struct MetatilePatch2x2 sMetatilePatch2x2s[12];

void FUN_0800e370(struct Coord* c) {
  s16 i;
  s32 x, y;

  x = METACOORD(c->x - PIXEL(16));
  y = METACOORD(c->y);

  for (i = 0; i < 12; i++) {
    if ((x == sMetatilePatch2x2Coords[i].x) && (y == sMetatilePatch2x2Coords[i].y)) {
      PatchMetatileMap(x, y, (struct MetatilePatch*)&sMetatilePatch2x2s[i]);
      return;
    }
  }

  PatchMetatileMap(x, y, (struct MetatilePatch*)&sDefaultMetatilePatch2x2);
}

// ------------------------------------------------------------------------------------------------------------------------------------

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

static const struct MetatilePatch2x1 ALIGNED(2) sMetatilePatch2x1_0833dfda = {
  size : {w : 1, h : 1},
  data : {0, 0},  // 2nd element is padding
};

// --------------------------------------------

const struct MetatilePatch ALIGNED(2) MetatilePatch_0833dfe2 = {w : 2, h : 1};
const metatile_id_t MetatilePatchData_0833dfe2[2] = {0x2B1, 0x2B2};

const struct MetatilePatch ALIGNED(2) MetatilePatch_0833dfea = {w : 2, h : 1};
const metatile_id_t MetatilePatchData_0833dfea[2] = {0x264, 0x272};

const struct MetatilePatch ALIGNED(2) MetatilePatch_0833dff2 = {w : 2, h : 1};
const metatile_id_t MetatilePatchData_0833dff2[2] = {0x273, 0x274};

static const struct MetatilePatch2x1 ALIGNED(2) sMetatilePatch2x1_0833dffa = {
  size : {w : 2, h : 1},
  data : {781, 781},
};

const struct MetatilePatch ALIGNED(2) MetatilePatch_0833e002 = {w : 2, h : 1};
const metatile_id_t MetatilePatchData_0833e002[2] = {0x13B, 0x11E};

const struct MetatilePatch ALIGNED(2) MetatilePatch_0833e00a = {w : 2, h : 1};
const metatile_id_t MetatilePatchData_0833e00a[2] = {0x11F, 0x30A};

static const struct MetatilePatch2x1 ALIGNED(2) sMetatilePatch2x1_0833e012 = {
  size : {w : 2, h : 1},
  data : {781, 315},
};

static const struct MetatilePatch2x1 ALIGNED(2) sMetatilePatch2x1_0833e01a = {
  size : {w : 2, h : 1},
  data : {286, 287},
};

static const struct MetatilePatch2x1 ALIGNED(2) sMetatilePatch2x1_0833e022 = {
  size : {w : 2, h : 1},
  data : {778, 778},
};

static const struct MetatilePatch2x1 ALIGNED(2) sMetatilePatch2x1_0833e02a = {
  size : {w : 2, h : 1},
  data : {689, 690},
};

static const struct MetatilePatch2x1 ALIGNED(2) sMetatilePatch2x1_0833e032 = {
  size : {w : 2, h : 1},
  data : {612, 626},
};

static const struct MetatilePatch2x2 ALIGNED(2) sDefaultMetatilePatch2x2 = {
  size : {w : 2, h : 2},
  data : {0, 0, 0, 0},
};

// clang-format off
static const struct Coord sMetatilePatch2x2Coords[12] = {
    {109, 27},
    {115, 27},
    {120, 15},
    {126, 15},
    {125, 39},
    {125, 41},
    {125, 43},
    {125, 45},
    {144, 77},
    {367, 33},
    {369, 33},
    {371, 33},
};
// clang-format on

static const struct MetatilePatch2x2 sMetatilePatch2x2s[12] = {
    [0] = {
      size : {w : 2, h : 2},
      data : {272, 1344, 256, 1348},
    },
    [1] = {
      size : {w : 2, h : 2},
      data : {197, 197, 181, 181},
    },
    [2] = {
      size : {w : 2, h : 2},
      data : {236, 237, 252, 253},
    },
    [3] = {
      size : {w : 2, h : 2},
      data : {236, 237, 252, 253},
    },
    [4] = {
      size : {w : 2, h : 2},
      data : {1296, 1219, 1344, 197},
    },
    [5] = {
      size : {w : 2, h : 2},
      data : {1344, 197, 1344, 197},
    },
    [6] = {
      size : {w : 2, h : 2},
      data : {1344, 197, 1344, 197},
    },
    [7] = {
      size : {w : 2, h : 2},
      data : {1344, 197, 1344, 197},
    },
    [8] = {
      size : {w : 2, h : 2},
      data : {315, 286, 315, 286},
    },
    [9] = {
      size : {w : 2, h : 2},
      data : {1376, 870, 1376, 870},
    },
    [10] = {
      size : {w : 2, h : 2},
      data : {869, 870, 869, 870},
    },
    [11] = {
      size : {w : 2, h : 2},
      data : {869, 870, 869, 870},
    },
};

#undef STAGE
