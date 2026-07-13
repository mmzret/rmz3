#include "gfx.h"
#include "global.h"
#include "overworld.h"
#include "renderer.h"
#include "system.h"

#define SCREEN_LEFT(coord_x) (((coord_x >> 8) + -120) << 8)  // Screen center -> Screen left
#define SCREEN_TOP(coord_y) (((coord_y >> 8) + -80) << 8)    // Screen center -> Screen top

static inline void* getchunk(const MetatileMapSelfRelPtr* h) {
  u32 offset = h->chunks;
  u32 ptr = (u32)((void*)h);
  return (void*)(offset + ptr);
}

static const struct Stage* UpdateStageTileset(Coords32* lefttop);
static void LoadTerrainLayerAllChunks(const struct Stage* p, const struct ChunkMap* map);
static void RenderTask_Overworld(struct Overworld* ow, struct DrawPivot* dp);
static void UpdateStageLayer(struct StageLayer* l, const struct Stage* s, Coords32* c);
static u32 FUN_080094f0(s32 x, s32 y);
static void ResetStageLayer(s32 n, const struct Stage* s);

void ResetTerrainMapTemplate(struct TerrainMapTemplate* tmpl, metatile_attr_t* attr, Metatile* tiles, Chunk* chunks, const struct ChunkMap* map);

// clang-format off
static const struct Stage* const gStageLandscape[STAGE_COUNT] = { // 0x0833a2e8
    [STAGE_NONE] =            &gStage0Landscape,
    [STAGE_SPACE_CRAFT] =     &gSpacecraftLandscape,
    [STAGE_VOLCANO] =         &gVolcanoLandscape,
    [STAGE_OCEAN] =           &gOceanLandscape,
    [STAGE_REPAIR_FACTORY] =  &gRepairFactoryLandscape,
    [STAGE_OLD_RESIDENTIAL] = &gOldResidentialLandscape,
    [STAGE_MISSILE_FACTORY] = &gMissileFactoryLandscape,
    [STAGE_TWILIGHT_DESERT] = &gTwilightDesertLandscape,
    [STAGE_ANATRE_FOREST] =   &gAnatreForestLandscape,
    [STAGE_ICE_BASE] =        &gFrostlineIceBaseLandscape,
    [STAGE_AREA_X2] =         &gAreaX2Landscape,
    [STAGE_E_FACILITY] =      &gEnergyFacilityLandscape,
    [STAGE_SNOWY_PLAINS] =    &gSnowyPlainsLandscape,
    [STAGE_SUNKEN_LIBRARY] =  &gSunkenLibraryLandscape, 
    [STAGE_GIANT_ELEVATOR] =  &gGiantElevatorLandscape, 
    [STAGE_SUB_ARCADIA] =     &gSubArcadiaLandscape, 
    [STAGE_WEILS_LABO] =      &gWeilLaboLandscape, 
    [STAGE_BASE] =            &gResistanceBaseLandscape,
};
// clang-format on

/*
    Overworld(ow) manager
        Generate overworld(terrain), manage BG, etc...
*/

// ステージのロードに関係
NON_MATCH void ResetLandscape(s32 stageID, Coords32* viewport) {
#if MODERN
  s16 i;
  const struct Stage* stage;
  Coords32* vp;

  vp = &gOverworld.terrain.viewport;
  vp->x = viewport->x;
  vp->y = viewport->y;

  stage = gStageLandscape[stageID];
  stageID = stage->id;
  gVideoRegBuffer.dispcnt &= ~(DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON);
  SetTaskCallback(&gOverworld.r.node, RenderTask_Overworld);
  gOverworld.r.ptr = &gOverworld;
  gOverworld.terrain.reload_graphic = FALSE;
  gOverworld.terrain.id = stageID | (1 << 7);

  {
    const MetatileMapSelfRelPtr* srptr;
    Metatile* tiles;
    metatile_attr_t* attrs;
    Chunk* chunks;

    srptr = &gStageTerrains[stageID];
    tiles = (void*)srptr + srptr->tiles;
    chunks = (void*)srptr + srptr->chunks;
    attrs = (void*)srptr + srptr->attrs;
    ResetTerrainMapTemplate(&gOverworld.terrain.hdr, attrs, tiles, chunks, stage->maps[STAGE_LAYER_TERRAIN]);
  }
  gOverworld.terrain.tilesets[0] = -1;
  gOverworld.terrain.tilesets[1] = -1;
  gOverworld.terrain.conveyor[0] = (stage->conveyor)[0];
  gOverworld.terrain.conveyor[1] = (stage->conveyor)[1];
  LoadTerrainLayerAllChunks(stage, stage->maps[STAGE_LAYER_TERRAIN]);

  for (i = 0; i < 3; i++) {
    ResetStageLayer(i, stage);
  }

  gOverworld.sea = 0x7FFFFFFF;
  gOverworld.unused_2c010 = 0x7FFFFFFF;
  gOverworld.range.left = 0;
  gOverworld.range.top = 0;
  gOverworld.range.right = MAX_X;
  gOverworld.range.bottom = MAX_Y;
  gOverworld.terrain.objectLen = 0;
  gOverworld.terrain.objectLenPrev = 0;

  for (i = 0; i < 4; i++) {
    gOverworld.state[i] = 0;
  }
#else
  INCCODE("asm/wip/ResetLandscape.inc");
#endif
}

void UpdateStageLandscape(Coords32* viewport) {
  const struct Stage* s;
  s32 i;
  Coords32 lefttop;
  Coords32* vp = &gOverworld.terrain.viewport;
  vp->x = viewport->x;
  vp->y = viewport->y;
  lefttop.x = SCREEN_LEFT(viewport->x);
  lefttop.y = SCREEN_TOP(viewport->y);
  s = UpdateStageTileset(&lefttop);

  // If bit7 is set, do initialization
  if (gOverworld.terrain.id != s->id) {
    gOverworld.terrain.id = s->id;
    ((s->fn)[0])(&lefttop);  // sStageRoutine[0], e.g. initResistanceBase
  }
  ((s->fn)[1])(&lefttop);  // sStageRoutine[1], e.g. 0x08016154

  for (i = 0; i < 3; i++) {
    struct StageLayer* l = &gOverworld.layer[i];
    UpdateStageLayer(l, s, &lefttop);
    if (l->fn[LAYER_UPDATE] != NULL) (l->fn[LAYER_UPDATE])(l, s);  // LayerUpdate_Volcano_2 (0x0800c604)
  }
}

void DrawOverworld(Renderer* r) {
  Renderer_PrependTask(r, &gOverworld.r.node);  // -> RenderTask_Overworld
}

void SaveDispRegister(void) {
  gOverworld.terrain.enabledBg = (gVideoRegBuffer.dispcnt & 0xF00) >> 8;
  gOverworld.terrain.savedBgCnt[0] = BGCNT16(1);
  gOverworld.terrain.savedBgCnt[1] = BGCNT16(2);
  gOverworld.terrain.savedBgCnt[2] = BGCNT16(3);
}

// RestoreBackground で使う
static inline void RestoreTileset(s32 slot) {
  ColorGraphic* g;
  const tileset_t t = gOverworld.terrain.tilesets[slot];
  const u8 id = t >> 8;
  if (id != 0xFF) {
    const u8 subID = t;
    if (subID != 0xFF) {
      const u32* ptr = &gStageTilesetOffsets[id];
      g = SELF_REL_PTR(ptr);
      g += subID;
      LoadGraphic(&g->g, BG_CHAR_OFFSET(1));
      g = SELF_REL_PTR(ptr);
      g += subID;
      LoadPalette(&g->pal, 0);
    }
  }
}

// メニューやイベントからOverworldに戻ってきたときに呼び出されてる
// 0x08008c88
NON_MATCH void RestoreBackground(void) {
#if MODERN
  gVideoRegBuffer.dispcnt &= ~(DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON);

  RestoreTileset(0);
  RestoreTileset(1);

  {
    s32 i;
    for (i = 0; i < 3; i++) {
      struct StageLayer* l = &gOverworld.layer[i];
      l->prevViewportLeftTopPixel.x += 0x2000;
      l->prevViewportLeftTopPixel.y += 0x2000;
      l->scrollCopy.x += 0x2000;
      l->scrollCopy.y += 0x2000;
    }
  }

  gVideoRegBuffer.dispcnt &= ~DISPCNT_BG_ALL_ON;
  gVideoRegBuffer.dispcnt |= (gOverworld.terrain.enabledBg << 8);
  BGCNT16(1) = gOverworld.terrain.savedBgCnt[0];
  BGCNT16(2) = gOverworld.terrain.savedBgCnt[1];
  BGCNT16(3) = gOverworld.terrain.savedBgCnt[2];
  gOverworld.terrain.reload_graphic = TRUE;
#else
  INCCODE("asm/wip/RestoreBackground.inc");
#endif
}

/*
  エスケープ時やステージクリア時に実行される
  ベースからステージへの転送では実行されない(ベースで死ぬと実行されるが)
*/
/**
 * @brief sStageRoutine[3] と 各ステージレイヤの LAYER_EXIT を呼び出す
 * @note 0x08008d9c
 */
void ExitStageLandscape(void) {
  s32 i;

  const Coords32* vp = &gOverworld.terrain.viewport;
  Coords32 lt = {SCREEN_LEFT(vp->x), SCREEN_TOP(vp->y)};
  const u16 id = gOverworld.terrain.id & 0x7F;
  const struct Stage* s = gStageLandscape[id];
  ((s->fn)[3])(&lt);  // sStageRoutine[3], e.g. exitVolcano

  for (i = 0; i < STAGE_LAYER_NUM; i++) {
    struct StageLayer* l = &gOverworld.layer[i];
    if (l->fn[LAYER_EXIT] != NULL) (l->fn[LAYER_EXIT])(l, s);  // e.g. LayerExit_Volcano_7
  }
  gVideoRegBuffer.dispcnt &= ~(DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON);
}

// 0x08008E10
static s16 Unused_GetMetatileID(s32 x, s32 y) {
  const s32 mx = METACOORD(x);
  const s32 my = METACOORD(y);
  // Chunk0..127 の範囲 に収まっているかチェック
  if ((mx < 0) || (mx >= ((DISPLAY_WIDTH * 127) / 16)) || (my < 0) || (my >= ((DISPLAY_HEIGHT * 127) / 16))) {
    return -1;  // 範囲外
  }
  return gOverworld.terrain.tilemap[MAP_OFFSET(gOverworld.terrain.tilemap, mx, my)];
}

/*
  (x, y)のタイルブロックのBlockAttrを取得する
*/
metatile_attr_t GetMetatileAttr(s32 x, s32 y) {
  const s32 mx = METACOORD(x);
  const s32 my = METACOORD(y);
  // Chunk0..127 の範囲 に収まっているかチェック
  if ((mx < 0) || (mx >= ((DISPLAY_WIDTH * 127) / 16)) || (my < 0) || (my >= ((DISPLAY_HEIGHT * 127) / 16))) {
    return MTATTR_B11 | MTATTR_B9 | SHAPE_BLOCK;  // 範囲外
  }
  return MAP_ATTR(&gOverworld.terrain, mx, my);
}

/*
  与えられたCoord に対応する　 sScreenBehavior のエントリの上位4bitが0xF なら TRUE, そうでなければ FALSE を返す
    - 奈落(落下死地帯)
    - 壁の中
    - シュリンポリンの潜伏空間
    - etc...
*/
bool8 IsVoidSpace(s32 x, s32 y) { return ((u8)FUN_080094f0(x, y)) == 0xF0; }

/*
  ゼロが3Dドアの有効範囲にいるかをチェックするのに使用
  c->x = (x & 0xFFFFF000) - x
  c->y = (y & 0xFFFFF000) - y
*/
void FUN_08008eb8(s32 x, s32 y, Coords32* c) {
  s32 mx = METACOORD(x);
  s32 my = METACOORD(y);
  c->x = COORD(mx) - x;
  c->y = COORD(my) - y;
}

// 0x08008ed0
// カメラの位置に関係
void CalcCameraDelta(Coords32* c, Coords32* d) {
  d->x = d->y = 0;
  {
    u8 a = FUN_080094f0(c->x, c->y);
    {
      u32 b = FUN_080094f0(c->x - PIXEL(120), c->y) - 1;
      if ((u8)(a - b) > 2) {
        d->x += PIXEL(120) - (c->x % PIXEL(120));
      }
    }
    {
      u32 b = FUN_080094f0(c->x + PIXEL(120), c->y) - 1;
      if ((u8)(a - b) > 2) {
        d->x -= c->x % PIXEL(120);
      }
    }

    if (a < 14) {
      {
        u32 b = FUN_080094f0(c->x, c->y - PIXEL(80)) - 1;
        if ((u8)(a - b) > 2) {
          d->y += PIXEL(80) - (c->y % PIXEL(80));
        }
      }
      {
        u32 b = FUN_080094f0(c->x, c->y + PIXEL(80)) - 1;
        if ((u8)(a - b) > 2) {
          d->y -= c->y % PIXEL(80);
        }
      }
    } else if (a == 14) {
      d->y = PIXEL(240) - (c->y % PIXEL(160));
    } else {
      d->y = -PIXEL(80) - (c->y % PIXEL(160));
    }
  }
}

/**
 * @brief ROM から 地形レイヤ(STAGE_LAYER_TERRAIN) を gOverworld.terrain.tilemap にロードする (1チャンクだけではなく、ステージ全体をロードする)
 * @param stage チャンクデータ(=メタタイルID)を取得するのに必要
 * @param layout 地形レイヤのチャンクマップ, 常に Stage.maps[STAGE_LAYER_TERRAIN]
 * @note データが自己相対ポインタを使っている + メタタイルマップのレイアウトがチャンクの2次元マッピング というこの世の終わりのようなデータ構造のせいで、無駄にコードが複雑になっている(まだコンパイル結果は一致しないですが、ロジックは問題ないです)
 * @note 0x08008fd0
 */
NON_MATCH static void LoadTerrainLayerAllChunks(const struct Stage* stage, const struct ChunkMap* layout) {
#if MODERN
  s16 x, y;
  u8* chunkIdList;
  metatile_id_t* dst;

  // nullチャンク (の先頭のメタタイルID) で タイルマップをクリア
  Chunk* chunks = getchunk(stage->terrainHdr);             // e.g. gWeilLabo_Chunks
  metatile_id_t nullval = chunks[layout->nullChunkID][0];  // nullチャンクの先頭のメタタイルID
  u32 fill = (((u32)nullval) << 16) | nullval;
  u16* map = gOverworld.terrain.tilemap;
  map[0] = layout->width * (DISPLAY_WIDTH / METATILE_SIZE);  // MetatileMap[0] = ステージ全体の横幅(メタタイル単位)
  CpuFastFill(fill, &map[2], sizeof(MetatileMap));           // tilemap_duty も巻き込まれているが最後に0クリアされてるので問題なし

  // チャンクマップ から チャンクID を読み取って　メタタイルマップに　チャンクIDの指すチャンクの内容(メタタイルID)をコピーしていく
  // レイアウトは MetatileMap のコメント参照
  chunkIdList = (u8*)(layout + 1);  // = 0x08346ab4
  dst = &map[2];
  for (y = 0; y < layout->height; y++) {
    for (x = 0; x < layout->width; x++) {
      u8 chunkID = chunkIdList[0];
      chunkIdList = &chunkIdList[1];

      if (chunkID == layout->nullChunkID) {
        dst = &dst[15];  // 次の(右隣の)チャンクへ
      } else {
        s16 i;
        metatile_id_t* src = chunks[chunkID];
        for (i = 0; i < (DISPLAY_HEIGHT / METATILE_SIZE); i++) {
          CopyMemory(src, dst, 15 * 2);
          src = &src[15], dst = &dst[layout->width * 15];  // 次の行へ (+16px)
        }
        dst = &dst[((layout->width * -150) + 15)];  // 1番上の行に戻して、次の(右隣の)チャンクへ
      }
    }
    chunkIdList = &chunkIdList[(layout->stride - layout->width)];  // ROM上のチャンクマップは 横幅が32の倍数になるようにパディングされているので、次の行に行くときは、パディング分も飛ばす必要がある
    // この時点での dst は MetatileMap のコメントの例だと map[150] を指している
    // これを次のチャンク行(= map[1500]) にするためには メタタイル行 で 9行分　下に移動させる必要がある
    dst = &dst[layout->width * (15 * (10 - 1))];  // 次のチャンク行へ
  }
  gOverworld.terrain.tilemap_duty = FALSE;
#else
  INCCODE("asm/wip/LoadTerrainLayerAllChunks.inc");
#endif
}

// 0x0800911c
// (s->x, s->y) から 横 s->width, 縦 s->height のメタタイルを (x16, y16) にコピーする
void ShiftMetatile(s32 x16, s32 y16, const MetatileShift* s) {
  s32 i;
  const u8 id = gOverworld.terrain.id & 0x7F;
  const struct Stage* stage = gStageLandscape[id];
  u16* dst = &gOverworld.terrain.tilemap[2];
  u16* src = &gOverworld.terrain.tilemap[2];

  // 1番下の行から上にコピーしていく
  u32 w = (u32)((stage->maps[0])->width) * 15;  // ステージの横幅(メタタイル単位)
  dst = &dst[TILEMAP_OFFSET(w, x16, y16 + s->height)];
  src = &src[TILEMAP_OFFSET(w, s->x, s->y + s->height)];
  for (i = 0; i < s->height; i++) {
    dst -= w, src -= w;  // 上の行へ (-16px)
    CopyMemory(src, dst, s->width << 1);
  }
  gOverworld.terrain.tilemap_duty = TRUE;
}

/**
 * @brief ステージのメタタイルマップ (x16, y16) から (x16 + patch->w, y16 + patch->h) の内容を変更する
 * @param x16 変更先のx座標(16px単位)
 * @param y16 変更先のy座標(16px単位)
 * @param patch 変更内容の (struct MetatilePatch) のポインタ, コンパイル内容的に u16* だと思われる
 * @note 0x080091b0
 */
NON_MATCH void PatchMetatileMap(s32 x16, s32 y16, const u16* patch) {
#if MODERN
  s16 i;
  const u8 id = gOverworld.terrain.id & 0x7F;
  const struct Stage* stage = gStageLandscape[id];
  u16* dst = &gOverworld.terrain.tilemap[2];

  s16 col = *patch++ << 1;  // bytesize
  u16 row = *patch++;

  u32 w = ((stage->maps[0])->width) * 15;  // ステージの横幅(メタタイル単位)
  dst += TILEMAP_OFFSET(w, x16, y16);

  for (i = 0; i < row; i++) {
    CopyMemory((u16*)patch, dst, col);
    patch += col >> 1, dst += w;  // 次の行へ (+16px)
  }
  gOverworld.terrain.tilemap_duty = TRUE;
#else
  INCCODE("asm/wip/PatchMetatileMap.inc");
#endif
}

/**
 * @brief chunkID で指定したチャンクで chunkX, chunkY を上書きする
 * @param chunkID 08649444 とかの Chunk[] の idx
 * @note ステージ全体の読み込みは LoadTerrainLayerAllChunks で行い、 LoadChunk はステージ全体の読み込みが終わった後に、チャンクを上書きするために呼び出される
 * @note 0x08009250
 */
void LoadChunk(s32 chunkX, s32 chunkY, u16 chunkID) {
  s16 i;
  u32 chunkW, w;
  const u8 id = gOverworld.terrain.id & 0x7F;
  const struct Stage* stage = gStageLandscape[id];
  u16* dst = &gOverworld.terrain.tilemap[2];

  u16* src = (u16*)getchunk(stage->terrainHdr);
  src += chunkID * (15 * 10);

  chunkW = (u32)((stage->maps[0])->width);   // ステージの横幅(チャンク単位)
  w = chunkW * 15;                           // ステージの横幅(メタタイル単位)
  dst += (w * chunkY) * 10 + (chunkX * 15);  // つまり、 dst += TILEMAP_OFFSET(w, chunkX * 15, chunkY * 10);

  for (i = 0; i < 10; i++) {  // 1チャンク = 高さ160px = メタタイル10行分
    CopyMemory(src, dst, 15 * 2);
    dst += chunkW * 15, src += 15;  // 次の行へ (+16px)
  }

  gOverworld.terrain.tilemap_duty = TRUE;
}

// これより上は ステージの地形データ(terrain)に関係
// -------------------------------------------- ここでファイルを分けた方がよさそう --------------------------------------------
// ここ以降は StageLayer に関係 (STAGE_LAYER_TERRAIN も扱うが、 STAGE_LAYER_1, STAGE_LAYER_2 と同じように扱うだけで地形データとしては扱ってない)

/**
 * @brief Reset gOverworld.layer[n]
 * @param n このステージレイヤのタイプ(0: 地形データ, 1: 水面や草など(=前景?), 2: 雲などの背景)
 * @note 0x080092e0
 */
NON_MATCH void ResetStageLayer(s32 n, const struct Stage* p) {
#if MODERN
  const MetatileMapSelfRelPtr* srptr;
  PixelCoords* lefttop;
  Metatile* tiles;
  Chunk* chunks;

  srptr = p->terrainHdr;

  (&gOverworld.layer[n])->type = n;
  (&gOverworld.layer[n])->unk_0f = 0;
  (&gOverworld.layer[n])->phase = 0;
  (&gOverworld.layer[n])->unk_10 = (&gOverworld.layer[n])->unk_12 = 0;
  lefttop = &(&gOverworld.layer[n])->viewportLeftTopPixel;
  (&gOverworld.layer[n])->prevViewportLeftTopPixel.x = (&gOverworld.layer[n])->prevViewportLeftTopPixel.y = -0x7fffffff;
  (&gOverworld.layer[n])->viewportLeftTopPixel.x = (&gOverworld.layer[n])->viewportLeftTopPixel.y = -0x7fffffff;
  (&gOverworld.layer[n])->scrollCopy.x = (&gOverworld.layer[n])->scrollCopy.y = -0x7fffffff;
  (&gOverworld.layer[n])->fn[0] = NULL;
  (&gOverworld.layer[n])->fn[1] = (void*)1;
  (&gOverworld.layer[n])->fn[2] = NULL;
  tiles = (Metatile*)(PTR_U32(&srptr->tiles) + srptr->tiles);
  chunks = (Chunk*)(PTR_U32(&srptr->tiles) + srptr->chunks);

  // ResetLayerGraphic の dst だけ違うけど、　dst は ResetLayerGraphic で使われないのでこの分岐は全く意味ない
  if (n == STAGE_LAYER_TERRAIN) {
    // dst に gOverworld.bgmap
    ResetLayerGraphic(&gOverworld.layer[STAGE_LAYER_TERRAIN].gfx, lefttop, gOverworld.bgmap, tiles, chunks, p->maps[STAGE_LAYER_TERRAIN]);
  } else {
    // dst に SCREEN_ADDR(n)
    ResetLayerGraphic(&gOverworld.layer[n].gfx, lefttop, SCREEN_ADDR(n), tiles, chunks, p->maps[n]);
  }
#else
  INCCODE("asm/wip/ResetStageLayer.inc");
#endif
}

static void unused_080093a0(s32 n) {
  struct StageLayer* l = &gOverworld.layer[n];
  l->fn[LAYER_UPDATE] = NULL;
  l->fn[LAYER_DRAW] = NULL;
}

// ステージレイヤ を GBAのBGマップ形式で描画する関数
// RenderTask_Overworld から呼び出される
void DrawGeneralStageLayer(struct StageLayer* l, const struct Stage* _) {
  PixelCoords c;
  PixelCoords prev_c;
  s32 dx, dy;
  struct LayerGraphic* g = &l->gfx;
  c.x = (((l->viewportLeftTopPixel).x * (l->scrollPower).x) >> 8) + (l->scroll).x;
  c.y = (((l->viewportLeftTopPixel).y * (l->scrollPower).y) >> 8) + (l->scroll).y;

  prev_c.x = (((l->prevViewportLeftTopPixel).x * (l->scrollPower).x) >> 8) + (l->scrollCopy).x;
  prev_c.y = (((l->prevViewportLeftTopPixel).y * (l->scrollPower).y) >> 8) + (l->scrollCopy).y;

  dx = c.x - prev_c.x + 15;
  dy = c.y - prev_c.y + 15;
  c.x += ((l->drawPivotOffset).x >> 8);
  c.y += ((l->drawPivotOffset).y >> 8);

  // STAGE_LAYER_TERRAIN は .tilemap から描画範囲を切り出して (GBAのBGマップ形式に変換して) .bgmap に書き込む(VRAMへの書き込みは別の関数で行う)
  // 他のステージレイヤは 実VRAMに直接描画する (大丈夫?)
  if (l->type != STAGE_LAYER_TERRAIN) {
    if (((u32)dx >= 31) || ((u32)dy >= 31)) {
      FUN_08005a70(g, &c, SCREEN_ADDR(l->bgIdx >> 4));
    } else {
      FUN_080050b0(g, &c, SCREEN_ADDR(l->bgIdx >> 4));
    }
  } else {
    if ((((u32)dx >= 31) || ((u32)dy >= 31)) || gOverworld.terrain.tilemap_duty) {
      FUN_08006a10(g, &c, (u32*)gOverworld.bgmap, gOverworld.terrain.tilemap);
    } else {
      FUN_08006bb4(g, &c, (u32*)gOverworld.bgmap, gOverworld.terrain.tilemap);
    }
    gOverworld.terrain.tilemap_duty = FALSE;
  }
  UpdateBGOFS(g, BGOFS(l->bgIdx >> 4));
}

/**
 * @brief カメラに関係
 * @return 0x0F: 不正な座標, 0xF0: sScreenBehavior のエントリの上位4bitが0xFの場合、　 0x00..0x0E: sScreenBehavior のエントリの上位4bit
 * @note 0x080094f0
 */
static u32 FUN_080094f0(s32 x, s32 y) {
  const u16* arr;
  u32 chunkX, chunkY;
  u16 result;
  const struct Stage* s;
  // Chunk0..127 の範囲 に収まっているかチェック
  if ((x < 0) || (y < 0)) return 0x0F;
  if ((x >= COORD(0x771)) || (y >= COORD(0x4F6))) return 0x0F;

  s = gStageLandscape[gOverworld.terrain.id & 0x7F];
  chunkX = gScreenX[METACOORD(x)];
  chunkY = gScreenY[METACOORD(y)];
  arr = s->behavior;
  result = (arr[(chunkY << arr[0]) + chunkX + 4]) >> 12;
  if (result == 0xF) {
    return 0xF0;
  }
  return result;
}

// 引数(lefttop)は画面左上の座標
// 0x0800956C
NON_MATCH static const struct Stage* UpdateStageTileset(Coords32* lefttop) {
#if MODERN
  tileset_ofs_t tileset;
  const u16 stageID = gOverworld.terrain.id & 0x7F;
  const struct Stage* stage = gStageLandscape[stageID];
  const u32 chunkX = gScreenX[METACOORD(lefttop->x)];
  const u32 chunkY = gScreenY[METACOORD(lefttop->y)];

  const u8* arr = stage->tilesetOffset;
  if (chunkX >= arr[2]) return stage;
  if (chunkY >= arr[3]) return stage;

  tileset = arr[(chunkY << arr[0]) + chunkX + 4];

  // インライン関数に分離できる?
  // Tileset 0
  {
    const ColorGraphic* g;
    if ((gOverworld.terrain.tilesets[0] >> 8) == stageID) {
      if ((gOverworld.terrain.tilesets[0] & 0xFF) == HI_NIBBLE(tileset)) {
        goto SKIP;
      }
    } else if (HI_NIBBLE(tileset) == 0xFF) {
      goto SKIP;
    }
    g = (const ColorGraphic*)SELF_REL_PTR(&gStageTilesetOffsets[stageID]) + HI_NIBBLE(tileset);
    RequestGraphicTransfer((void*)&g->g, (void*)0x4000);
    LoadPalette((void*)&g->pal, 0);
    gOverworld.terrain.tilesets[0] = (stageID << 8) | HI_NIBBLE(tileset);
  }

SKIP:
  // Tileset 1
  {
    const ColorGraphic* g;
    if ((gOverworld.terrain.tilesets[1] >> 8) == stageID) {
      if ((gOverworld.terrain.tilesets[1] & 0xFF) == LO_NIBBLE(tileset)) {
        return stage;
      }
    } else if (LO_NIBBLE(tileset) == 0xFF) {
      return stage;
    }
    g = (const ColorGraphic*)SELF_REL_PTR(&gStageTilesetOffsets[stageID]) + LO_NIBBLE(tileset);
    RequestGraphicTransfer((void*)&g->g, (void*)0x4000);
    LoadPalette((void*)&g->pal, 0);
    gOverworld.terrain.tilesets[1] = (stageID << 8) | LO_NIBBLE(tileset);
  }

  return stage;
#else
  INCCODE("asm/wip/UpdateStageTileset.inc");
#endif
}

/**
 * @brief sStageRoutine[2]　の実行 と 各ステージレイヤのVRAMへの描画　をする
 * @details LAYER_DRAW によって STAGE_LAYER_TERRAIN は gOverworld.bgmap に、 STAGE_LAYER_1, STAGE_LAYER_2 は 実VRAMに描画される。 (gOverworld.bgmap は 最後のRequestBgMapTransfer で VRAMに転送される)
 * @note 0x080096B8
 */
static void RenderTask_Overworld(struct Overworld* _, struct DrawPivot* dp) {
  s32 i;
  const u32 id = gOverworld.terrain.id & 0x7F;
  const struct Stage* s = gStageLandscape[id];
  (s->fn[2])(&dp->coord);  // e.g. sStageRoutine[2] (ほとんどの場合が nop, e.g. gelevator_08014038)

  for (i = 0; i < 3; i++) {
    struct StageLayer* l = &gOverworld.layer[i];
    (l->drawPivotOffset).x = (dp->offset).x;
    (l->drawPivotOffset).y = (dp->offset).y;
    if ((u32)l->fn[LAYER_DRAW] > 1) {  // l->fn[LAYER_DRAW] != NULL だとコンパイル結果が一致しない
      ((l->fn[LAYER_DRAW])(l, s));     // ほとんどの場合が、 DrawGeneralStageLayer (それ以外の関数でも独自処理をした後で内部で DrawGeneralStageLayer を呼び出すことが多い)
    }
  }
  RequestBgMapTransfer(gOverworld.bgmap, (void*)SCREEN_BASE(gOverworld.layer[0].bgIdx >> 4), 0x1000);
  gOverworld.terrain.reload_graphic = FALSE;
}

/**
 * @brief 引数の s と lefttop をもとに StageLayer を更新する。 また bgFns が変化したら LAYER_EXIT を呼び出す
 * @param lefttop 現在の画面"左上"の座標
 * @note 0x08009754
 */
NON_MATCH static void UpdateStageLayer(struct StageLayer* l, const struct Stage* s, Coords32* lefttop) {
#if MODERN
  u8 chunkX, chunkY;
  (l->prevViewportLeftTopPixel).x = (l->viewportLeftTopPixel).x;
  (l->prevViewportLeftTopPixel).y = (l->viewportLeftTopPixel).y;
  (l->scrollCopy).x = (l->scroll).x;
  (l->scrollCopy).y = (l->scroll).y;
  (l->viewportLeftTopPixel).x = lefttop->x >> 8;
  (l->viewportLeftTopPixel).y = lefttop->y >> 8;

  chunkX = gScreenX[METACOORD(lefttop->x)];
  chunkY = gScreenY[METACOORD(lefttop->y)];
  if ((chunkX < s->tilesetOffset[2]) && (chunkY < s->tilesetOffset[3])) {
    const u16 w = s->behavior[0];
    const StageBgFunc* fns = s->bgFns[(s->behavior[(chunkY << w) + chunkX + 4] >> ((2 - l->type) * 4)) & 0xF];

    if ((l->fn[LAYER_UPDATE] != fns[LAYER_UPDATE]) || (l->fn[LAYER_DRAW] != fns[LAYER_DRAW])) {
      if (l->fn[LAYER_EXIT] != NULL) (l->fn[LAYER_EXIT])(l, s);
      l->fn[LAYER_UPDATE] = fns[LAYER_UPDATE];
      l->fn[LAYER_DRAW] = fns[LAYER_DRAW];
      l->fn[LAYER_EXIT] = fns[LAYER_EXIT];

      l->bgIdx = s->bgIdx[l->type];
      l->prio = s->prio[l->type];
      l->screenBase = s->screenBase[l->type];

      (l->scrollPower).x = s->scrollPower[l->type].x;
      (l->scrollPower).y = s->scrollPower[l->type].y;

      (l->scroll).x = s->scroll[l->type].x;
      (l->scroll).y = s->scroll[l->type].y;

      if ((l->fn[LAYER_UPDATE] == NULL) && (l->fn[LAYER_DRAW] == NULL)) {
        gVideoRegBuffer.dispcnt &= ~(u16)(l->bgIdx << 8);
      } else {
        BGCNT16(l->bgIdx >> 4) = l->prio | l->screenBase | (BGCNT_TXT512x256 | BGCNT_WRAP | BGCNT_MOSAIC | BGCNT_CHARBASE(1));  // 0x6044
        gVideoRegBuffer.dispcnt |= (u16)(l->bgIdx << 8);
      }
      (l->prevViewportLeftTopPixel).x = (l->prevViewportLeftTopPixel).y = -0x7FFFFFFF;
      (l->scrollCopy).x = (l->scrollCopy).y = -0x7FFFFFFF;
      l->unk_0f = 0;
      l->phase = 0;
      l->unk_10 = l->unk_12 = 0;
    }
  }
#else
  INCCODE("asm/wip/UpdateStageLayer.inc");
#endif
}
