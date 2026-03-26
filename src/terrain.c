#include "gfx.h"
#include "global.h"
#include "overworld.h"
#include "system.h"
#include "task.h"

static const struct Stage* UpdateStageTileset(struct Coord* c);
static void loadStageLandscape(const struct Stage* p, const struct ChunkMap* map);
static void TaskCB_UpdateOwGraphic(struct Overworld* ow, struct DrawPivot* tc);
static void UpdateStageLayer(struct StageLayer* l, const struct Stage* s, struct Coord* c);
static u8 FUN_080094f0(s32 x, s32 y);
static void ResetStageLayer(s32 n, const struct Stage* s);

void ResetTerrain(struct TerrainROMPointer* terrain, metatile_attr_t* attr, Metatile* tiles, Screen* m, const struct ChunkMap* map);

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
WIP void ResetLandscape(s32 stageID, struct Coord* viewport) {
#if MODERN
  s16 i;
  const struct Stage* stage;
  struct Coord* vp;

  vp = &W_TERRAIN_V2.viewport;
  vp->x = viewport->x;
  vp->y = viewport->y;

  stage = gStageLandscape[stageID];
  stageID = stage->id;
  gVideoRegBuffer.dispcnt &= ~(DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON);
  SetTaskCallback(&gOverworld.task, TaskCB_UpdateOwGraphic);
  gOverworld.p = &gOverworld.task;
  gOverworld.terrain.reload_graphic = FALSE;
  W_TERRAIN_V2.id = stageID | (1 << 7);

  {
    const struct TerrainHeader* hdr;
    Metatile* tiles;
    metatile_attr_t* attrs;
    Screen* screens;

    hdr = &gStageTerrains[stageID];
    tiles = (Metatile*)((void*)hdr + hdr->tiles);
    screens = (Screen*)((void*)hdr + hdr->screens);
    attrs = (metatile_attr_t*)((void*)hdr + hdr->attrs);
    ResetTerrain(&gOverworld.terrain.hdr, attrs, tiles, screens, stage->maps[0]);
  }
  W_TERRAIN_V2.tilesets[0] = -1;
  W_TERRAIN_V2.tilesets[1] = -1;
  W_TERRAIN_V2.conveyor[0] = (stage->conveyor)[0];
  W_TERRAIN_V2.conveyor[1] = (stage->conveyor)[1];
  loadStageLandscape(stage, stage->maps[0]);

  for (i = 0; i < 3; i++) {
    ResetStageLayer(i, stage);
  }

  gOverworld.sea = 0x7FFFFFFF;
  gOverworld.unused_2c010 = 0x7FFFFFFF;
  gOverworld.range.left = 0;
  gOverworld.range.top = 0;
  gOverworld.range.right = MAX_X;
  gOverworld.range.bottom = MAX_Y;
  W_TERRAIN_V2.objectLen = 0;
  W_TERRAIN_V2.objectLenPrev = 0;

  for (i = 0; i < 4; i++) {
    gOverworld.state[i] = 0;
  }
#else
  INCCODE("asm/wip/ResetLandscape.inc");
#endif
}

/*
基本的に毎フレーム実行

中でstage関数リスト(例: 083472e8)の idx 0,1を呼び出している

さらに、02002220,020022a8,02002330 の指す関数(stage関数リストのどれか？)を呼び出している

引数のcoordはゼロのいる座標ではなく、現在の視界(だいたいゼロの座標と一致するが)
*/
void UpdateStageLandscape(struct Coord* viewport) {
  const struct Stage* s;
  s32 i;
  struct Coord lefttop;
  struct Coord* vp = &W_TERRAIN_V2.viewport;
  vp->x = viewport->x;
  vp->y = viewport->y;
  lefttop.x = SCREEN_LEFT(viewport->x);
  lefttop.y = SCREEN_TOP(viewport->y);
  s = UpdateStageTileset(&lefttop);

  // If bit7 is set, do initialization
  if (W_TERRAIN_V2.id != s->id) {
    W_TERRAIN_V2.id = s->id;
    ((s->fn)[0])(&lefttop);  // e.g. initRBase
  }

  ((s->fn)[1])(&lefttop);  // e.g. 0x08016154

  for (i = 0; i < 3; i++) {
    struct StageLayer* l = &gOverworld.layer[i];
    UpdateStageLayer(l, s, &lefttop);
    if (l->fn[LAYER_UPDATE] != NULL) {
      (l->fn[LAYER_UPDATE])(l, s);
    }
  }
}

void DrawOverworld(struct TaskManager* tm) {
  PrependTask(tm, &gOverworld.task);  // -> TaskCB_UpdateOwGraphic
  return;
}

void SaveDispRegister(void) {
  gOverworld.terrain.enabledBg = (gVideoRegBuffer.dispcnt & 0xF00) >> 8;
  gOverworld.terrain.savedBgCnt[0] = gVideoRegBuffer.bgcnt[1];
  gOverworld.terrain.savedBgCnt[1] = gVideoRegBuffer.bgcnt[2];
  gOverworld.terrain.savedBgCnt[2] = gVideoRegBuffer.bgcnt[3];
}

// メニューやイベントからOverworldに戻ってきたときに呼び出されてる
WIP void RestoreBackground(void) {
#if MODERN
  s32 i;
  tileset_t t;
  struct ColorGraphic* g;
  const u32* tilesets;
  gVideoRegBuffer.dispcnt &= ~(DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON);

  t = W_TERRAIN_V2.tilesets[0];
  if (((t >> 8) != 0xFF) && (((u8)t) != 0xFF)) {
    tilesets = &gStageTilesetOffsets[(t >> 8)];
    g = (struct ColorGraphic*)((u32)(void*)tilesets + *tilesets) + (u8)t;
    LoadGraphic(&g->g, (void*)0x4000);

    tilesets = &gStageTilesetOffsets[(t >> 8)];
    g = (struct ColorGraphic*)((u32)(void*)tilesets + *tilesets) + (u8)t;
    LoadPalette(&g->pal, 0);
  }

  t = W_TERRAIN_V2.tilesets[1];
  if (((t >> 8) != 0xFF) && (((u8)t) != 0xFF)) {
    tilesets = &gStageTilesetOffsets[(t >> 8)];
    g = (struct ColorGraphic*)((u32)(void*)tilesets + *tilesets) + (u8)t;
    LoadGraphic(&g->g, (void*)0x4000);

    tilesets = &gStageTilesetOffsets[(t >> 8)];
    g = (struct ColorGraphic*)((u32)(void*)tilesets + *tilesets) + (u8)t;
    LoadPalette(&g->pal, 0);
  }

  for (i = 0; i < 3; i++) {
    struct StageLayer* l = &gOverworld.layer[i];
    l->prevViewportCenterPixel.x += 0x2000;
    l->prevViewportCenterPixel.y += 0x2000;
    l->scrollCopy.x += 0x2000;
    l->scrollCopy.y += 0x2000;
  }

  gVideoRegBuffer.dispcnt &= ~DISPCNT_BG_ALL_ON;
  gVideoRegBuffer.dispcnt |= (gOverworld.terrain.enabledBg << 8);
  gVideoRegBuffer.bgcnt[1] = gOverworld.terrain.savedBgCnt[0];
  gVideoRegBuffer.bgcnt[2] = gOverworld.terrain.savedBgCnt[1];
  gVideoRegBuffer.bgcnt[3] = gOverworld.terrain.savedBgCnt[2];
  gOverworld.terrain.reload_graphic = TRUE;
#else
  INCCODE("asm/wip/RestoreBackground.inc");
#endif
}

/*
  処理内容:
    1. stageFuncの配列(例: 0833b208) の idx=3の関数を実行
    2. 02002220 の3要素について、 fn_08 が null じゃないなら fn_08 を実行

  エスケープ時やステージクリア時に実行される
  ベースからステージへの転送では実行されない(ベースで死ぬと実行されるが)
*/
void ExitStageLandscape(void) {
  const struct Stage* s;
  s32 i;
  struct Coord c;
  const struct Coord* screenCoord = &W_TERRAIN_V2.viewport;
  u16 id;
  c.x = SCREEN_LEFT(screenCoord->x);
  c.y = SCREEN_TOP(screenCoord->y);
  id = W_TERRAIN_V2.id & 0x7F;
  s = gStageLandscape[id];
  ((s->fn)[3])(&c);

  for (i = 0; i < 3; i++) {
    struct StageLayer* layer = &gOverworld.layer[i];
    if (layer->fn[LAYER_EXIT] != NULL) {
      (layer->fn[LAYER_EXIT])(layer, s);
    }
  }
  gVideoRegBuffer.dispcnt &= ~(DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON);
}

#if MODERN == 0
NAKED static u16 getMetatileID(s32 x, s32 y) { INCCODE("asm/unused/getMetatileID.inc"); }  // (x, y)のタイルブロックのIDを入手する
#endif

/*
  (x, y)のタイルブロックのBlockAttrを取得する
*/
metatile_attr_t GetMetatileAttr(s32 x, s32 y) {
  s32 idx;
  struct Terrain* terrain;
  const s32 mx = METACOORD(x);
  const s32 my = METACOORD(y);
  if (((u32)mx > 0x770) || (my < 0) || (my > 0x4F5)) {
    return 0x0A01;
  }

  terrain = &gOverworld.terrain;
  idx = (my * terrain->tilemap[0]) + mx + 2;
  return (terrain->hdr).attrs[terrain->tilemap[idx]];
}

/*
  与えられたCoordが 虚無空間(Void Space)かどうか
    - 奈落(落下死地帯)
    - 壁の中
    - シュリンポリンの潜伏空間
    - etc...
*/
bool8 IsVoidSpace(s32 x, s32 y) { return FUN_080094f0(x, y) == 0xF0; }

/*
  ゼロが3Dドアの有効範囲にいるかをチェックするのに使用
  c->x = (x & 0xFFFFF000) - x
  c->y = (y & 0xFFFFF000) - y
*/
void FUN_08008eb8(s32 x, s32 y, struct Coord* c) {
  s32 mx = METACOORD(x);
  s32 my = METACOORD(y);
  c->x = COORD(mx) - x;
  c->y = COORD(my) - y;
}

// カメラの位置に関係
WIP void CalcCameraDelta(struct Coord* c, struct Coord* d) {
#if MODERN
  u32 a, b;
  d->x = d->y = 0;
  a = FUN_080094f0(c->x, c->y);

  b = FUN_080094f0(c->x - (SCREEN_WIDTH / 2), c->y) - 1;
  if (2 < (u8)(a - b)) {
    d->x += (SCREEN_WIDTH / 2) - (c->x % (SCREEN_WIDTH / 2));
  }
  b = FUN_080094f0(c->x + (SCREEN_WIDTH / 2), c->y) - 1;
  if (2 < (u8)(a - b)) {
    d->x -= (c->x % (SCREEN_WIDTH / 2));
  }

  if (a < 14) {
    b = FUN_080094f0(c->x, c->y - (SCREEN_HEIGHT / 2)) - 1;
    if (2 < (u8)(a - b)) {
      d->y += (SCREEN_HEIGHT / 2) - (c->y % (SCREEN_HEIGHT / 2));
    }
    b = FUN_080094f0(c->x, c->y + (SCREEN_HEIGHT / 2)) - 1;
    if (2 < (u8)(a - b)) {
      d->y -= (c->y % (SCREEN_HEIGHT / 2));
    }

  } else if (a == 14) {
    d->y = 0xF000 - (c->y % SCREEN_HEIGHT);

  } else {
    d->y = -(SCREEN_HEIGHT / 2) - (c->y % SCREEN_HEIGHT);
  }
#else
  INCCODE("asm/wip/CalcCameraDelta.inc");
#endif
}

/*
  ステージの ブロックマップ=地形データ を読み込む関数
  例:
    r0 = 0x08347268
    r1 = 0x08346ab0
*/
WIP static void loadStageLandscape(const struct Stage* p, const struct ChunkMap* layout) {
#if MODERN
  u16 x, y;
  u8* screenIdxs;
  metatile_id_t* dst;
  Screen* screens = (Screen*)(PTR_U32(&(p->terrainHdr)->tiles) + (p->terrainHdr)->screens);
  metatile_id_t nullMetatile = screens[layout->skip][0];
  u32 fill = (((u32)nullMetatile) << 16) | nullMetatile;
  u16* map = gOverworld.terrain.tilemap;
  map[0] = layout->width * 15;
  CpuFastFill(fill, &map[2], sizeof(MetatileMap));  // tilemap_duty も巻き込まれているが最後に0クリアされてるので問題なし

  screenIdxs = (u8*)(layout + 1);
  dst = &map[2];
  for (y = 0; y < layout->height; y++) {
    for (x = 0; x < layout->width; x++) {
      u8 screenIdx = screenIdxs[0];
      screenIdxs = &screenIdxs[1];

      if (screenIdx == layout->skip) {
        dst = &dst[15];
      } else {
        metatile_id_t* src = screens[screenIdx];
        for (s16 i = 0; i < 10; i++) {
          CopyMemory(src, dst, 30);
          src = &src[15];
          dst = &dst[layout->width * 15];
        }
        dst = &dst[((layout->width * -150) + 15)];
      }
    }
    screenIdxs = &screenIdxs[(layout->realWidth - layout->width)];
    dst = &dst[layout->width * 135];
  }
  gOverworld.terrain.tilemap_duty = FALSE;
#else
  INCCODE("asm/wip/loadStageLandscape.inc");
#endif
}

// (s.x, s.row+s.y) -> (x, s.row+y) にメタタイルをずらす
WIP void ShiftMetatile(s32 x, s32 y, const struct MetatileShift* s) {
#if MODERN
  s32 i;
  u8 id = W_TERRAIN_V2.id & 0x7F;
  const struct Stage* stage = gStageLandscape[id];
  u16* map = &gOverworld.terrain.tilemap[2];
  u32 w = (u32)((stage->maps[0])->width) * 15;
  u16* dst = &map[((s->row + y) * w) + x];
  u16* src = &map[((s->row + s->y) * w) + s->x];
  for (i = 0; i < s->row; i++) {
    dst -= w;
    src -= w;
    CopyMemory(src, dst, s->block << 1);
  }
  gOverworld.terrain.tilemap_duty = TRUE;
#else
  INCCODE("asm/wip/ShiftMetatile.inc");
#endif
}

/*
  ステージのメタタイルマップ (x16, y16)から(x16+p.w, y16+p.h) の内容を変更する
*/
WIP void PatchMetatileMap(u32 x16, u32 y16, struct MetatilePatch* p) {
#if MODERN
  s16 i;
  u8 id = W_TERRAIN_V2.id & 0x7F;
  const struct Stage* stage = gStageLandscape[id];
  u16* map = &gOverworld.terrain.tilemap[2];

  u32 rowsize = (u32)p->w * 2;  // bytesize
  u32 row = (u32)p->h;
  u8* src = ((u8*)p) + sizeof(struct MetatilePatch);

  u32 w16 = stage->maps[0]->width * 15;
  u8* dst = (u8*)&map[(y16 * w16) + x16];

  for (i = 0; i < row; i++) {
    CopyMemory(src, dst, rowsize);
    src = &src[rowsize];
    dst = &dst[w16 * 2];
  }
  gOverworld.terrain.tilemap_duty = TRUE;
#else
  INCCODE("asm/wip/PatchMetatileMap.inc");
#endif
}

/**
 * @brief Screen構造体を gOverworld.tilemap にロードする
 * @param chunkID 08649444 とかの Screen[] の idx
 * @note 0x08009250
 */
NON_MATCH void LoadScreenIntoMetatileMap(s32 chunkX, s32 chunkY, u16 chunkID) {
#if MODERN
  s16 i;
  s32 id = (u8)W_TERRAIN_V2.id & 0x7F;
  const struct Stage* stage = gStageLandscape[id];
  metatile_id_t* tm = &gOverworld.terrain.tilemap[2];

  const struct TerrainHeader* h = stage->terrainHdr;
  const Screen* chunks = (const Screen*)(((void*)h) + h->screens);  // ここのレジスタ割り当てがうまくいかない以外は、問題なさそう
  metatile_id_t* src = (metatile_id_t*)chunks[chunkID];

  const u32 chunkW = (stage->maps[0])->width;  // チャンク単位
  const u32 w16 = chunkW * 15;                 // メタタイル単位
  metatile_id_t* dst = &tm[((w16 * chunkY) * 10) + (chunkX * 15)];

  for (i = 0; i < 10; i++) {
    CopyMemory(src, dst, 30);
    dst = &dst[chunkW * 15];
    src = &src[15];
  }

  gOverworld.terrain.tilemap_duty = TRUE;
#else
  INCCODE("asm/wip/LoadScreenIntoMetatileMap.inc");
#endif
}

/**
 * @brief Reset gOverworld.layer[n]
 * @param n このステージレイヤのタイプ(0: 地形データ, 1: 水面や草など(=前景?), 2: 雲などの背景)
 * @note 0x080092e0
 */
WIP void ResetStageLayer(s32 n, const struct Stage* p) {
#if MODERN
  const struct TerrainHeader* terrain;
  struct Coord* c;
  Metatile* tiles;
  Screen* screens;

  terrain = p->terrainHdr;

  (&gOverworld.layer[n])->type = n;
  (&gOverworld.layer[n])->unk_0f = 0;
  (&gOverworld.layer[n])->phase = 0;
  (&gOverworld.layer[n])->unk_10 = (&gOverworld.layer[n])->unk_12 = 0;
  c = &(&gOverworld.layer[n])->viewportCenterPixel;
  (&gOverworld.layer[n])->prevViewportCenterPixel.x = (&gOverworld.layer[n])->prevViewportCenterPixel.y = -0x7fffffff;
  (&gOverworld.layer[n])->viewportCenterPixel.x = (&gOverworld.layer[n])->viewportCenterPixel.y = -0x7fffffff;
  (&gOverworld.layer[n])->scrollCopy.x = (&gOverworld.layer[n])->scrollCopy.y = -0x7fffffff;
  (&gOverworld.layer[n])->fn[0] = NULL;
  (&gOverworld.layer[n])->fn[1] = (void*)1;
  (&gOverworld.layer[n])->fn[2] = NULL;
  tiles = (Metatile*)(PTR_U32(&terrain->tiles) + terrain->tiles);
  screens = (Screen*)(PTR_U32(&terrain->tiles) + terrain->screens);
  if (n == STAGE_LAYER_TERRAIN) {
    ResetLayerGraphic(&gOverworld.layer[STAGE_LAYER_TERRAIN].gfx, c, gOverworld.bgmap, tiles, screens, p->maps[STAGE_LAYER_TERRAIN]);
  } else {
    ResetLayerGraphic(&gOverworld.layer[n].gfx, c, (u16*)(VRAM + SCREEN_BASE(n)), tiles, screens, p->maps[n]);
  }
#else
  INCCODE("asm/wip/ResetStageLayer.inc");
#endif
}

#if MODERN == 0
static void unused_080093a0(s32 n) {
  struct StageLayer* layer = &gOverworld.layer[n];
  layer->fn[LAYER_UPDATE] = NULL;
  layer->fn[LAYER_DRAW] = NULL;
}
#endif

// ステージレイヤ の描画関数
// TaskCB_UpdateOwGraphic から呼び出される
void DrawGeneralStageLayer(struct StageLayer* l, const struct Stage* _) {
  struct Coord c;
  struct Coord prev_c;
  s32 dx, dy;
  struct LayerGraphic* g = &l->gfx;
  c.x = (((l->viewportCenterPixel).x * (l->scrollPower).x) >> 8) + (l->scroll).x;
  c.y = (((l->viewportCenterPixel).y * (l->scrollPower).y) >> 8) + (l->scroll).y;

  prev_c.x = (((l->prevViewportCenterPixel).x * (l->scrollPower).x) >> 8) + (l->scrollCopy).x;
  prev_c.y = (((l->prevViewportCenterPixel).y * (l->scrollPower).y) >> 8) + (l->scrollCopy).y;

  dx = c.x - prev_c.x + 15;
  dy = c.y - prev_c.y + 15;
  c.x += ((l->drawPivotOffset).x >> 8);
  c.y += ((l->drawPivotOffset).y >> 8);

  // STAGE_LAYER_TERRAIN は .tilemap から描画範囲を切り出して (GBAのBGマップ形式に変換して) .bgmap に書き込む(VRAMへの書き込みは別の関数で行う)
  // 他のステージレイヤは 実VRAMに直接描画する (大丈夫?)
  if (l->type != STAGE_LAYER_TERRAIN) {
    if (((u32)dx >= 31) || ((u32)dy >= 31)) {
      FUN_08005a70(g, &c, VRAM + (u32)SCREEN_BASE_16(l->bgIdx >> 4));
    } else {
      FUN_080050b0(g, &c, VRAM + (u32)SCREEN_BASE_16(l->bgIdx >> 4));
    }
  } else {
    if ((((u32)dx >= 31) || ((u32)dy >= 31)) || gOverworld.terrain.tilemap_duty) {
      FUN_08006a10(g, &c, (u32*)gOverworld.bgmap, &gOverworld.terrain.tilemap);
    } else {
      FUN_08006bb4(g, &c, (u32*)gOverworld.bgmap, &gOverworld.terrain.tilemap);
    }
    gOverworld.terrain.tilemap_duty = FALSE;
  }
  UpdateBGOFS(g, BGOFS(l->bgIdx >> 4));
}

/**
 * @return 0..15: カメラに関する値, 0xF0: Void Space
 */
static u8 FUN_080094f0(s32 x, s32 y) {
  const u16* arr;
  u32 row, col;
  u16 result;
  const struct Stage* s;
  if (x < 0) return 0x0F;
  if (y < 0) return 0x0F;
  if (x >= COORD(0x771)) return 0x0F;
  if (y >= COORD(0x4F6)) return 0x0F;

  s = gStageLandscape[W_TERRAIN_V2.id & 0x7F];
  col = gScreenX[METACOORD(x)];
  row = gScreenY[METACOORD(y)];
  arr = s->behavior;
  result = (arr[(row << arr[0]) + col + 4]) >> 12;
  if (result == 0xF) {
    return 0xF0;
  }
  return result;
}

/*
  引数のCoord(c)は画面左上の座標
*/
WIP static const struct Stage* UpdateStageTileset(struct Coord* c) {
#if MODERN
  tileset_ofs_t tileset;
  const struct ColorGraphic* g;
  const u8 stageID = W_TERRAIN_V2.id & 0x7F;
  const struct Stage* stage = gStageLandscape[stageID];
  const u32 screenX = gScreenX[METACOORD(c->x)];
  const u32 screenY = gScreenY[METACOORD(c->y)];
  if (stage->tilesetOffset[2] <= screenX) {
    return stage;
  }
  if (stage->tilesetOffset[3] <= screenY) {
    return stage;
  }

  tileset = stage->tilesetOffset[4 + (screenY << stage->tilesetOffset[0]) + screenX];

  // Tileset 0
  if ((W_TERRAIN_V2.tilesets[0] >> 8) == stageID) {
    if ((W_TERRAIN_V2.tilesets[0] & 0xFF) == HI_NIBBLE(tileset)) {
      goto SKIP;
    }
  } else if (HI_NIBBLE(tileset) == 0xFF) {
    goto SKIP;
  }
  g = &((const struct ColorGraphic*)OFFSET_TABLE(gStageTilesetOffsets, stageID))[HI_NIBBLE(tileset)];
  RequestGraphicTransfer(&g->g, (void*)0x4000);
  LoadPalette(&g->pal, 0);
  W_TERRAIN_V2.tilesets[0] = (((u16)stageID) << 8) | HI_NIBBLE(tileset);

SKIP:
  // Tileset 1
  if ((W_TERRAIN_V2.tilesets[1] >> 8) == stageID) {
    if ((W_TERRAIN_V2.tilesets[1] & 0xFF) == LO_NIBBLE(tileset)) {
      return stage;
    }
  } else if (LO_NIBBLE(tileset) == 0xFF) {
    return stage;
  }
  g = &((const struct ColorGraphic*)OFFSET_TABLE(gStageTilesetOffsets, stageID))[LO_NIBBLE(tileset)];
  RequestGraphicTransfer(&g->g, (void*)0x4000);
  LoadPalette(&g->pal, 0);
  W_TERRAIN_V2.tilesets[1] = (((u16)stageID) << 8) | LO_NIBBLE(tileset);

  return stage;
#else
  INCCODE("asm/wip/UpdateStageTileset.inc");
#endif
}

/**
 * @brief StageBgFunc の idx 2　を呼び出す(例: 0x08016379)
 * @note 0x080096B8
 */
static void TaskCB_UpdateOwGraphic(struct Overworld* ow, struct DrawPivot* dp) {
  s32 i;
  struct StageLayer* layer;
  const u32 id = W_TERRAIN_V2.id & 0x7F;
  const struct Stage* s = gStageLandscape[id];
  (s->fn[2])(&dp->coord);  // e.g. sResistanceBaseGfxRoutine[2] (ほとんどの場合が nop)

  for (i = 0; i < 3; i++) {
    layer = &gOverworld.layer[i];
    (layer->drawPivotOffset).x = (dp->offset).x;
    (layer->drawPivotOffset).y = (dp->offset).y;
    if (1 < (u32)layer->fn[LAYER_DRAW]) {
      ((layer->fn[LAYER_DRAW])(layer, s));  // e.g. DrawGeneralStageLayer
    }
  }
  RequestBgMapTransfer(gOverworld.bgmap, (void*)SCREEN_BASE_16(gOverworld.layer[0].bgIdx >> 4), 0x1000);
  gOverworld.terrain.reload_graphic = FALSE;
}

WIP static void UpdateStageLayer(struct StageLayer* l, const struct Stage* s, struct Coord* c) {
#if MODERN
  u8 X, Y;
  (l->prevViewportCenterPixel).x = (l->viewportCenterPixel).x;
  (l->prevViewportCenterPixel).y = (l->viewportCenterPixel).y;
  (l->scrollCopy).x = (l->scroll).x;
  (l->scrollCopy).y = (l->scroll).y;
  (l->viewportCenterPixel).x = c->x >> 8;
  (l->viewportCenterPixel).y = c->y >> 8;

  X = gScreenX[METACOORD(c->x)];
  Y = gScreenY[METACOORD(c->y)];
  if ((X < s->tilesetOffset[2]) && (Y < s->tilesetOffset[3])) {
    const u16 w = s->behavior[0];
    const StageBgFunc* fns = s->bgFns[(s->behavior[(Y << w) + X + 4] >> ((2 - l->type) * 4)) & 0xF];

    if ((l->fn[0] != fns[0]) || (l->fn[1] != fns[1])) {
      if (l->fn[LAYER_EXIT] != NULL) {
        (l->fn[LAYER_EXIT])(l, s);
      }
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

      if ((l->fn[0] == NULL) && (l->fn[1] == NULL)) {
        gVideoRegBuffer.dispcnt &= ~(u16)(l->bgIdx << 8);
      } else {
        *((u16*)&gVideoRegBuffer.bgcnt[l->bgIdx >> 4]) = l->prio | l->screenBase | 0x6044;
        gVideoRegBuffer.dispcnt |= (u16)(l->bgIdx << 8);
      }
      (l->prevViewportCenterPixel).x = (l->prevViewportCenterPixel).y = -0x7fffffff;
      (l->scrollCopy).x = (l->scrollCopy).y = -0x7fffffff;
      l->unk_0f = 0;
      l->phase = 0;
      l->unk_10 = l->unk_12 = 0;
    }
  }
#else
  INCCODE("asm/wip/UpdateStageLayer.inc");
#endif
}
