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
  gOverworld.work.anatreForest.unk_008 = NULL;
  gOverworld.work.anatreForest.unk_00c = 0;
  gOverworld.work.anatreForest.unk_00d = 0;
}

static void FUN_080101f0(struct Coord* _ UNUSED) {
  if (gOverworld.work.anatreForest.leaf == NULL) {
    gOverworld.work.anatreForest.leaf = CreateLeafBurn(1);
  }

  if ((W_TERRAIN_V2.tilesets[0] >> 8 == STAGE_ANATRE_FOREST) && ((W_TERRAIN_V2.tilesets[0] & 0xFF) == 0)) {
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

  if ((W_TERRAIN_V2.tilesets[1] >> 8 == STAGE_ANATRE_FOREST) && ((W_TERRAIN_V2.tilesets[1] & 0xFF) == 1)) {
    if ((gOverworld.work.anatreForest.unk_00c & (1 << 1)) == 0) {
      gOverworld.work.anatreForest.unk_00c |= (1 << 1);
      LoadBlink(221, 0);
    }
    UpdateBlinkMotionState(221);

  } else if ((gOverworld.work.anatreForest.unk_00c & (1 << 1))) {
    gOverworld.work.anatreForest.unk_00c ^= (1 << 1);
    ClearBlink(221);
  }

  if ((W_TERRAIN_V2.tilesets[0] >> 8 == STAGE_ANATRE_FOREST) && ((W_TERRAIN_V2.tilesets[0] & 0xFF) == 2)) {
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

  if ((W_TERRAIN_V2.tilesets[1] >> 8 == STAGE_ANATRE_FOREST) && ((W_TERRAIN_V2.tilesets[1] & 0xFF) == 3)) {
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
static void LayerDraw_AnatreForest_4(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerUpdate_AnatreForest_5(struct StageLayer* l, const struct Stage* _ UNUSED);
static void LayerExit_AnatreForest_5(struct StageLayer* l, const struct Stage* _ UNUSED);
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
      [LAYER_DRAW]   = LayerDraw_AnatreForest_4,
      [LAYER_EXIT]   = NULL,
    },
    [5] = {
      [LAYER_UPDATE] = LayerUpdate_AnatreForest_5,
      [LAYER_DRAW]   = DrawGeneralStageLayer,
      [LAYER_EXIT]   = LayerExit_AnatreForest_5,
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

NAKED static void LayerDraw_AnatreForest_4(struct StageLayer* l, const struct Stage* _ UNUSED) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #8\n\
	adds r4, r0, #0\n\
	adds r6, r4, #0\n\
	adds r6, #0x14\n\
	ldr r3, [r4, #0x34]\n\
	ldr r2, [r4, #0x38]\n\
	ldr r1, [r4, #0x3c]\n\
	subs r1, r3, r1\n\
	adds r1, #0xf\n\
	ldr r0, [r4, #0x40]\n\
	subs r0, r2, r0\n\
	adds r5, r0, #0\n\
	adds r5, #0xf\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #1\n\
	adds r2, r2, r0\n\
	ldr r0, [r4, #0x2c]\n\
	asrs r0, r0, #8\n\
	adds r0, r0, r3\n\
	str r0, [sp]\n\
	ldr r0, [r4, #0x30]\n\
	asrs r0, r0, #8\n\
	adds r0, r0, r2\n\
	str r0, [sp, #4]\n\
	cmp r1, #0x1e\n\
	bhi _0801062A\n\
	cmp r5, #0x1e\n\
	bhi _0801062A\n\
	ldr r3, _08010650 @ =gOverworld\n\
	ldr r1, _08010654 @ =0x0002D02C\n\
	adds r0, r3, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _08010660\n\
_0801062A:\n\
	ldr r0, [r4, #0x5c]\n\
	lsrs r0, r0, #4\n\
	lsls r0, r0, #1\n\
	ldr r1, _08010658 @ =gVideoRegBuffer+4\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	movs r2, #0xf8\n\
	lsls r2, r2, #5\n\
	ands r2, r0\n\
	lsls r2, r2, #3\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #0x13\n\
	adds r2, r2, r0\n\
	ldr r3, _0801065C @ =0x020029E0\n\
	adds r0, r6, #0\n\
	mov r1, sp\n\
	bl FUN_08006ae0\n\
	b _08010688\n\
	.align 2, 0\n\
_08010650: .4byte gOverworld\n\
_08010654: .4byte 0x0002D02C\n\
_08010658: .4byte gVideoRegBuffer+4\n\
_0801065C: .4byte 0x020029E0\n\
_08010660:\n\
	ldr r0, [r4, #0x5c]\n\
	lsrs r0, r0, #4\n\
	lsls r0, r0, #1\n\
	ldr r1, _080106AC @ =gVideoRegBuffer+4\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	movs r2, #0xf8\n\
	lsls r2, r2, #5\n\
	ands r2, r0\n\
	lsls r2, r2, #3\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #0x13\n\
	adds r2, r2, r0\n\
	movs r0, #0xfc\n\
	lsls r0, r0, #3\n\
	adds r3, r3, r0\n\
	adds r0, r6, #0\n\
	mov r1, sp\n\
	bl FUN_08006bb4\n\
_08010688:\n\
	ldr r0, _080106B0 @ =gOverworld\n\
	ldr r1, _080106B4 @ =0x0002D02C\n\
	adds r0, r0, r1\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	ldr r1, [r4, #0x5c]\n\
	lsrs r1, r1, #4\n\
	lsls r1, r1, #2\n\
	ldr r0, _080106B8 @ =gVideoRegBuffer+12\n\
	adds r1, r1, r0\n\
	adds r0, r6, #0\n\
	bl UpdateBGOFS\n\
	add sp, #8\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080106AC: .4byte gVideoRegBuffer+4\n\
_080106B0: .4byte gOverworld\n\
_080106B4: .4byte 0x0002D02C\n\
_080106B8: .4byte gVideoRegBuffer+12\n\
 .syntax divided\n");
}

struct Solid* FUN_080cedc0(u8 n);

static void LayerUpdate_AnatreForest_5(struct StageLayer* l, const struct Stage* _ UNUSED) {
  if (gOverworld.work.anatreForest.unk_008 == NULL) {
    gOverworld.work.anatreForest.unk_008 = FUN_080cedc0(0);
  }
}

static void LayerExit_AnatreForest_5(struct StageLayer* l, const struct Stage* _ UNUSED) {
  struct Solid* p = gOverworld.work.anatreForest.unk_008;
  if (p != NULL) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    (p->body).status = 0;
    (p->body).prevStatus = 0;
    (p->body).invincibleTime = 0;
    (p->s).flags &= ~COLLIDABLE;
    SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
    gOverworld.work.anatreForest.unk_008 = NULL;
  }
}

INCASM("asm/stage_gfx/anatre_forest.inc");

extern const struct ChunkMap sChunkMap1;
INCBIN_STATIC(sChunkMap1, "data/stage/anatre_forest/layer1.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x0833f890 0x0833fa54 ./data/stage/anatre_forest/layer1.bin

extern const struct ChunkMap sChunkMap2;
INCBIN_STATIC(sChunkMap2, "data/stage/anatre_forest/layer2.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x0833fa54 0x0833fb98 ./data/stage/anatre_forest/layer2.bin

extern const struct ChunkMap sChunkMap3;
INCBIN_STATIC(sChunkMap3, "data/stage/anatre_forest/layer3.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x0833fb98 0x0833fcdc ./data/stage/anatre_forest/layer3.bin

extern const tileset_ofs_t sTilesetOffset[];
INCBIN_STATIC(sTilesetOffset, "data/stage/anatre_forest/tileset_offset.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x0833fcdc 0x0833fe20 ./data/stage/anatre_forest/tileset_offset.bin

extern const u16 sScreenBehavior[];
INCBIN_STATIC(sScreenBehavior, "data/stage/anatre_forest/screen_behavior.bin");  // ./tools/dumper/bin.ts ./baserom.gba 0x0833fe20 0x083400a8 ./data/stage/anatre_forest/screen_behavior.bin

const struct Stage gAnatreForestLandscape = {
  id : STAGE_ANATRE_FOREST,
  fn : sStageRoutine,
  terrainHdr : &gStageTerrains[STAGE_ANATRE_FOREST],
  maps : {&sChunkMap1, &sChunkMap2, &sChunkMap3},
  bgIdx : {USE_BG1, USE_BG2, USE_BG3},
  prio : {3, 3, 3},
  screenBase : {BGMAP_BLOCK(2), BGMAP_BLOCK(4), BGMAP_BLOCK(6)},
  scrollPower : {{0x100, 0x100}, {0x100, 0x100}, {0x80, 0x80}},
  scroll : {{0, 0}, {0, 0}, {120, 256}},
  tilesetOffset : sTilesetOffset,
  bgFns : sLayerRoutine,
  behavior : sScreenBehavior,
};

static const u8 u8_ARRAY_ARRAY_08340128[6][2] = {
    {160, 0}, {176, 1}, {180, 2}, {184, 0}, {251, 1}, {255, 2},
};

// clang-format off
static const struct Coord Coord_ARRAY_ARRAY_08340134[10][2] = {
    [0] = {{PIXEL(2912), PIXEL(480)}, {PIXEL(3008), PIXEL(592)}},
    [1] = {{PIXEL(3264), PIXEL(480)}, {PIXEL(3360), PIXEL(608)}},
    [2] = {{PIXEL(3600), PIXEL(512)}, {PIXEL(3696), PIXEL(640)}},
    [3] = {{PIXEL(3936), PIXEL(448)}, {PIXEL(4032), PIXEL(576)}},
    [4] = {{PIXEL(4272), PIXEL(480)}, {PIXEL(4368), PIXEL(576)}},
    [5] = {{PIXEL(4672), PIXEL(464)}, {PIXEL(4768), PIXEL(560)}},
    [6] = {{PIXEL(5072), PIXEL(496)}, {PIXEL(5168), PIXEL(592)}},
    [7] = {{PIXEL(5584), PIXEL(496)}, {PIXEL(5680), PIXEL(592)}},
    [8] = {{PIXEL(5936), PIXEL(304)}, {PIXEL(6032), PIXEL(400)}},
    [9] = {{PIXEL(6336), PIXEL(176)}, {PIXEL(6432), PIXEL(272)}},
};
// clang-format on

static const u8 u8_ARRAY_083401d4[20] = {
    0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x01, 0x00, 0x02, 0x03, 0x02, 0x03, 0x02, 0x01, 0x02, 0x02, 0x02, 0x03, 0x02, 0x01,
};

static const struct Rect Rect_ARRAY_083401e8[3] = {
    {PIXEL(48), PIXEL(56), PIXEL(96), PIXEL(112)},
    {PIXEL(48), PIXEL(64), PIXEL(96), PIXEL(128)},
    {PIXEL(48), PIXEL(48), PIXEL(96), PIXEL(96)},
};

static const struct Coord Coord_ARRAY_08340200[4] = {
    {PIXEL(3152), PIXEL(560)},
    {PIXEL(3472), PIXEL(592)},
    {PIXEL(4160), PIXEL(608)},
    {PIXEL(5968), PIXEL(576)},
};

// clang-format off
static const struct Coord Coord_ARRAY_08340220[10] = {
    {PIXEL(2872), PIXEL(560)},
    {PIXEL(3192), PIXEL(592)},
    {PIXEL(3544), PIXEL(608)},
    {PIXEL(3880), PIXEL(592)},
    {PIXEL(4256), PIXEL(600)},
    {PIXEL(4568), PIXEL(592)},
    {PIXEL(4952), PIXEL(592)},
    {PIXEL(5464), PIXEL(576)},
    {PIXEL(5928), PIXEL(448)},
    {PIXEL(6312), PIXEL(464)},
};
// clang-format on

struct MetatilePatch1x1 {
  struct MetatilePatch size;
  metatile_id_t data[1 * 1];
};

static const struct MetatilePatch1x1 MetatilePatch_08340270 = {
    .size = {1, 1},
    .data = {0},
};

struct MetatilePatch3x3 {
  struct MetatilePatch size;
  metatile_id_t data[3 * 3];
};

static const struct MetatilePatch3x3 MetatilePatch_08340278 = {
    .size = {3, 3},
    .data = {0, 0, 0, 0, 0, 0, 0, 0, 0},
};
