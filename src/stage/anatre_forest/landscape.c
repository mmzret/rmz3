#include "blink.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"

static void initAnatreForest(struct Coord* _ UNUSED);
static void FUN_080101f0(struct Coord* _ UNUSED);
static void FUN_08010444(struct Coord* _ UNUSED);
static void FUN_080104d4(struct Coord* _ UNUSED);

static const StageFunc sStageRoutine[4] = {
    initAnatreForest,
    FUN_080101f0,
    FUN_08010444,
    FUN_080104d4,
};

static void initAnatreForest(struct Coord* _ UNUSED) {
  gOverworld.work.anatreForest.leaf = NULL;
  gOverworld.work.anatreForest.unk_004 = 0;
  gOverworld.work.anatreForest.unk_008 = 0;
  gOverworld.work.anatreForest.unk_00c = 0;
  gOverworld.work.anatreForest.unk_00d = 0;
}

static void FUN_080101f0(struct Coord* _ UNUSED) {
  if (gOverworld.work.anatreForest.leaf == NULL) {
    gOverworld.work.anatreForest.leaf = CreateLeafBurn(1);
  }

  if ((gOverworld.unk_1c8.tilesets[0] >> 8 == STAGE_ANATRE_FOREST) && ((gOverworld.unk_1c8.tilesets[0] & 0xFF) == 0)) {
    if ((gOverworld.work.anatreForest.unk_00c & 1) == 0) {
      gOverworld.work.anatreForest.unk_00c |= 1;
      LoadBlink(218, 0);
      LoadBlink(219, 0);
      LoadBlink(220, 0);
    }
    UpdateBlinkMotionState(218);
    UpdateBlinkMotionState(219);
    UpdateBlinkMotionState(220);

  } else if ((gOverworld.work.anatreForest.unk_00c & 1)) {
    gOverworld.work.anatreForest.unk_00c ^= 1;
    ClearBlink(218);
    ClearBlink(219);
    ClearBlink(220);
  }

  if ((gOverworld.unk_1c8.tilesets[1] >> 8 == STAGE_ANATRE_FOREST) && ((gOverworld.unk_1c8.tilesets[1] & 0xFF) == 1)) {
    if ((gOverworld.work.anatreForest.unk_00c & (1 << 1)) == 0) {
      gOverworld.work.anatreForest.unk_00c |= (1 << 1);
      LoadBlink(221, 0);
    }
    UpdateBlinkMotionState(221);

  } else if ((gOverworld.work.anatreForest.unk_00c & (1 << 1))) {
    gOverworld.work.anatreForest.unk_00c ^= (1 << 1);
    ClearBlink(221);
  }

  if ((gOverworld.unk_1c8.tilesets[0] >> 8 == STAGE_ANATRE_FOREST) && ((gOverworld.unk_1c8.tilesets[0] & 0xFF) == 2)) {
    if ((gOverworld.work.anatreForest.unk_00c & (1 << 2)) == 0) {
      gOverworld.work.anatreForest.unk_00c |= (1 << 2);
      LoadBlink(222, 0);
      LoadBlink(223, 0);
      LoadBlink(224, 0);
      LoadBlink(225, 0);
      LoadBlink(226, 0);
    }
    UpdateBlinkMotionState(222);
    UpdateBlinkMotionState(223);
    UpdateBlinkMotionState(224);
    UpdateBlinkMotionState(225);
    UpdateBlinkMotionState(226);
    gOverworld.work.anatreForest.unk_00d++;
    if (gOverworld.work.anatreForest.unk_00d == 190) {
      gOverworld.work.anatreForest.unk_00d = 0;
    }

  } else if ((gOverworld.work.anatreForest.unk_00c & (1 << 2))) {
    gOverworld.work.anatreForest.unk_00c ^= (1 << 2);
    ClearBlink(222);
    ClearBlink(223);
    ClearBlink(224);
    ClearBlink(225);
    ClearBlink(226);
  }

  if ((gOverworld.unk_1c8.tilesets[1] >> 8 == STAGE_ANATRE_FOREST) && ((gOverworld.unk_1c8.tilesets[1] & 0xFF) == 3)) {
    if ((gOverworld.work.anatreForest.unk_00c & (1 << 3)) == 0) {
      gOverworld.work.anatreForest.unk_00c |= (1 << 3);
      LoadBlink(227, 0);
      LoadBlink(228, 0);
    }
    UpdateBlinkMotionState(227);
    UpdateBlinkMotionState(228);

  } else if ((gOverworld.work.anatreForest.unk_00c & (1 << 3))) {
    gOverworld.work.anatreForest.unk_00c ^= (1 << 3);
    ClearBlink(227);
    ClearBlink(228);
  }
}

NAKED static void FUN_08010444(struct Coord* _ UNUSED) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	ldr r2, _080104BC @ =gOverworld\n\
	ldr r1, _080104C0 @ =0x000007D4\n\
	adds r0, r2, r1\n\
	ldrh r1, [r0]\n\
	lsrs r0, r1, #8\n\
	cmp r0, #8\n\
	bne _080104B6\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	cmp r0, #2\n\
	bne _080104B6\n\
	movs r4, #0\n\
	ldr r1, _080104C4 @ =0x0002D035\n\
	adds r0, r2, r1\n\
	ldr r1, _080104C8 @ =0x08340128\n\
	ldrb r0, [r0]\n\
	ldrb r2, [r1]\n\
	cmp r0, r2\n\
	bls _08010480\n\
	adds r3, r1, #0\n\
	adds r2, r0, #0\n\
_08010470:\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r4, r0, #0x10\n\
	lsls r0, r4, #1\n\
	adds r0, r0, r3\n\
	ldrb r0, [r0]\n\
	cmp r2, r0\n\
	bhi _08010470\n\
_08010480:\n\
	ldr r6, _080104CC @ =gStageTilesetOffsets+(18*4)\n\
	lsls r4, r4, #1\n\
	adds r0, r1, #1\n\
	adds r4, r4, r0\n\
	ldrb r0, [r4]\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	ldr r5, _080104D0 @ =0x08705150\n\
	adds r1, r1, r5\n\
	ldr r0, [r6]\n\
	adds r0, r0, r1\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	bl RequestGraphicTransfer\n\
	ldrb r0, [r4]\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r5\n\
	ldr r0, [r6]\n\
	adds r0, r0, r1\n\
	adds r0, #0xc\n\
	movs r1, #0\n\
	bl LoadPalette\n\
_080104B6:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080104BC: .4byte gOverworld\n\
_080104C0: .4byte 0x000007D4\n\
_080104C4: .4byte 0x0002D035\n\
_080104C8: .4byte 0x08340128\n\
_080104CC: .4byte gStageTilesetOffsets+(18*4)\n\
_080104D0: .4byte 0x08705150\n\
 .syntax divided\n");
}

static void FUN_080104d4(struct Coord* _ UNUSED) {
  struct Solid* leaf;
  if (leaf = gOverworld.work.anatreForest.leaf, leaf != NULL) {
    (leaf->s).flags &= ~DISPLAY;
    (leaf->s).flags &= ~FLIPABLE;
    (leaf->body).status = 0;
    (leaf->body).prevStatus = 0;
    (leaf->body).invincibleTime = 0;
    (leaf->s).flags &= ~COLLIDABLE;
    SET_SOLID_ROUTINE(leaf, ENTITY_DISAPPEAR);
  }
  ClearBlink(218);
  ClearBlink(219);
  ClearBlink(220);
  ClearBlink(221);
  ClearBlink(222);
  ClearBlink(223);
  ClearBlink(224);
  ClearBlink(225);
  ClearBlink(226);
  ClearBlink(227);
  ClearBlink(228);
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void LayerUpdate_2(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerUpdate_3(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerUpdate_4(struct StageLayer* l, const struct Stage* _ UNUSED);
void FUN_080105e4(struct StageLayer* l, const struct Stage* stage);
void anatre_080106bc(struct StageLayer* l, const struct Stage* stage);
void FUN_080106e0(struct StageLayer* l, const struct Stage* stage);
void anatre_08010738(struct StageLayer* l, const struct Stage* stage);
void FUN_08010be0(struct StageLayer* l, const struct Stage* stage);

// clang-format off
static const StageLayerRoutine sLayerRoutine[7] = {
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
      [LAYER_DRAW]   = FUN_080105e4,
      [LAYER_EXIT]   = NULL,
    },
    [5] = {
      [LAYER_UPDATE] = anatre_080106bc,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = FUN_080106e0,
    },
    [6] = {
      [LAYER_UPDATE] = anatre_08010738,
      [LAYER_DRAW]   = NULL,
      [LAYER_EXIT]   = FUN_08010be0,
    },
};
// clang-format on

static void LayerUpdate_2(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    (l->scrollPower).x = 0xC0;
    (l->scrollPower).y = 0xC0;
    (l->scroll).x = 0x74C;
    (l->scroll).y = 0x58;
    l->phase++;
  }
}

static void LayerUpdate_3(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    (l->scroll).x = 0xE98;
    (l->scroll).y = 0xA0;
    l->phase++;
  }
}

static void LayerUpdate_4(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (l->phase == 0) {
    const u16 n = l->bgIdx;
    BGCNT16(n >> 4) &= 0xFFFC;
    BGCNT16(n >> 4) |= 1;
    l->phase++;
  }
}

INCASM("asm/stage_gfx/anatre_forest.inc");

extern const struct ScreenLayout sScreenMap1;
INCBIN_STATIC(sScreenMap1, "data/stage/anatre_forest/layer1.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x0833f890 0x0833fa54 ./data/stage/anatre_forest/layer1.bin

extern const struct ScreenLayout sScreenMap2;
INCBIN_STATIC(sScreenMap2, "data/stage/anatre_forest/layer2.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x0833fa54 0x0833fb98 ./data/stage/anatre_forest/layer2.bin

extern const struct ScreenLayout sScreenMap3;
INCBIN_STATIC(sScreenMap3, "data/stage/anatre_forest/layer3.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x0833fb98 0x0833fcdc ./data/stage/anatre_forest/layer3.bin

extern const tileset_ofs_t sTilesetOffset[];
INCBIN_STATIC(sTilesetOffset, "data/stage/anatre_forest/tileset_offset.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x0833fcdc 0x0833fe20 ./data/stage/anatre_forest/tileset_offset.bin

extern const u16 sScreenBehavior[];
INCBIN_STATIC(sScreenBehavior, "data/stage/anatre_forest/screen_behavior.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x0833fe20 0x083400a8 ./data/stage/anatre_forest/screen_behavior.bin

const struct Stage gAnatreForestLandscape = {
  id : STAGE_ANATRE_FOREST,
  fn : sStageRoutine,
  terrainHdr : &gStageTerrains[STAGE_ANATRE_FOREST],
  maps : {&sScreenMap1, &sScreenMap2, &sScreenMap3},
  bgIdx : {USE_BG1, USE_BG2, USE_BG3},
  prio : {3, 3, 3},
  screenBase : {BGMAP_BLOCK(2), BGMAP_BLOCK(4), BGMAP_BLOCK(6)},
  scrollPower : {{0x100, 0x100}, {0x100, 0x100}, {0x80, 0x80}},
  scroll : {{0, 0}, {0, 0}, {120, 256}},
  tilesetOffset : sTilesetOffset,
  bgFns : sLayerRoutine,
  behavior : sScreenBehavior,
  unk_78 : {0x0, 0x0},
};

// ./tools/dumper/bin.ts ./baserom.gba 0x08340128 0x08340290 ./data/landscape_anatre_forest.bin
INCBIN("data/landscape_anatre_forest.bin");
