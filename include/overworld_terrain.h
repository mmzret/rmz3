#ifndef GUARD_RMZ3_OW_MANAGER_H
#define GUARD_RMZ3_OW_MANAGER_H

#include "boss.h"
#include "gfx.h"
#include "global.h"
#include "solid.h"

#define USE_BG1 0x12
#define USE_BG2 0x24
#define USE_BG3 0x38

enum LayerRoutine {
  LAYER_UPDATE,
  LAYER_DRAW,
  LAYER_EXIT,
};

#define HAZARD_LENGTH (gOverworld.unk_1c8.hazardLength)
#define HAZARD(n) (&gOverworld.unk_1c8.hazards[n])

// マップデータ(2KB単位)を置くブロック -> 0x0600_0000 + (0x800)*n
#define BGMAP_BLOCK(n) (n << 8)

// 8x8タイルが2x2枚集まった論理タイル(16x16px)
typedef u16 Metatile[4];

typedef void (*StageFunc)(struct Coord *);

struct StageLayer;
struct Stage;
typedef void (*StageBgFunc)(struct StageLayer *, const struct Stage *);
typedef StageBgFunc StageLayerRoutine[3];  // [update1, update2, exit], LayerRoutine

// Metatile(のID)を 15x10ブロック集めて画面全体のグラフィックを表すようにしたもの
typedef metatile_id_t Screen[15 * 10];

/*
  MetatileのTileMapである、Overworld.map(0x020029e4)に Screen をどう配置するかのデータ
*/
struct ScreenLayout {
  u8 realWidth;
  u8 skip;    // そのステージでのSKIP値を格納する
  u8 width;   // ステージの横幅が画面何枚分か
  u8 height;  // ステージの縦幅が画面何枚分か
};

/*
  例: 0x0863c638
  Terrain構成要素のオフセットを示したもの
*/
struct TerrainHeader {
  s32 tiles;    // Metatileの配列 e.g. 0x086ee6b0
  s32 attrs;    // metatile_attr_t の配列
  s32 screens;  // Screenの配列
};

// ROMが保持しているステージの静的な情報
struct Stage {
  u32 id;  // ステージID
  const StageFunc *fn;
  const struct TerrainHeader *terrainHdr;
  const struct ScreenLayout *maps[3];
  u32 bgIdx[3];
  u32 prio[3];  // BG Priority for layer
  u32 screenBase[3];
  struct Coord scrollPower[3];
  struct Coord scroll[3];              // レイヤに常に加算されるスクロール値(ピクセル単位) つまりxに16を加えるとレイヤが16pxずれる(あくまでずれるのはレイヤの見た目で地形はずれない)
  const tileset_ofs_t *tilesetOffset;  // tilesetOffset[n] >> 4 が
  const StageLayerRoutine *bgFns;
  const u16 *behavior;
  struct Coord unk_78;  // Overworld.unk_2c004
};

struct MetatileShift {
  s16 x;      // メタタイル単位
  s16 y;      // メタタイル単位
  s16 block;  // 動かすメタタイルの数
  s16 row;
};

// e.g. 0833ccf0
struct MetatilePatch {
  u16 w;  // パッチの横のメタタイル数
  u16 h;  // パッチの縦のメタタイル数

  /*
    この後に
    metatile_id_t patchs[w*h];
    が続いている
  */
};

// StageLayer構造体のうち、純粋なグラフィック部分に関係するもの
struct LayerGraphic {
  struct Coord c;
  u16 bgofs[2];        // BGOFS(x, y) 参照: 08006dac
  Metatile *tiledata;  // 02002240, 020022c8, e.g. 086f9fec
  Screen *screens;
  const struct ScreenLayout *map;
};  // 24 bytes

// ステージ中のBG(BG1 or BG2 or BG3)の挙動
struct StageLayer {
  StageLayerRoutine fn;

  // 0: BG1, 1: BG2, 2: BG3
  u16 n;

  u8 phase;  // StageLayerの状態を表す
  u8 unk_0f;
  u16 unk_10;
  u16 unk_12;
  struct LayerGraphic gfx;
  struct Coord drawPivotOffset;          // 画面の振動時に0以外になってた
  struct Coord viewportCenterPixel;      // 現在の画面中央のワールド座標(ピクセル単位)
  struct Coord prevViewportCenterPixel;  // 1フレーム?前の.viewportCenterPixel
  struct Coord scrollPower;              // ゼロが1px動く時に、画面がどれくらいスクロールするか(256で1px動くと1pxスクロール,つまり1倍, 512で1px動くと2pxスクロール,つまり2倍)
  struct Coord scroll;
  struct Coord scrollCopy;
  u32 bgIdx;  // bit4-8がbgcntのn(BGnか), そしてbit0-4 は (1 << n) したもの
  u32 prio;   // BGCNTn の bit0-1　部分でもある
  u32 screenBase;

  // ステージによる
  union {
    u8 raw[32];
    struct {
      u8 frameCounter;  // 例: 壊れた宇宙船で背景の雲の流れと連動
      u8 _[3];
      u8 unk_6c[28];
    } resistanceBase;
    struct {
      u32 frameCounter;  // 例: 壊れた宇宙船で背景の雲の流れと連動
      u8 unk_6c[28];
    } spacecraft;
    struct {
      s32 eruptionX[3];
      u8 unk_74[20];
    } volcano;
    struct {
      s32 scrollTimer;
      struct Coord c;
      u8 unk_74[20];
    } missile;
  } work;

  // ステージによる？
};  // 136 bytes

struct Terrain {
  metatile_attr_t *attrs;
  Metatile *tiles;
  Screen *screens;
  const struct ScreenLayout *map;
};  // 16 bytes

// ゼロが通り抜けできないもの
struct Hazard {
  s16 id;
  metatile_attr_t attr;
  s16 w;
  s16 h;
  struct Coord start;
  struct Coord unk_10;
};  // 24 bytes

struct MetatileMap {
  u32 width : 16;
  u32 pad : 16;
  metatile_id_t map[89102];
};

struct Overworld_1c8 {
  struct Coord viewport;  // 現在写っているの画面中央の座標
  u16 id;                 // ステージID (Bit7(0x80)は、initRBaseとかの初期化関数が実行されていないことを示す)

  // Hazard ゼロが通り抜けできないもの
  u8 hazardLength;
  u8 hazardActive;
  struct Hazard hazards[32];
  struct Hazard nextBlockings[32];
  // Hazard

  tileset_t tilesets[2];
  u16 enabledBg;  // DISPCNTの bit8..11 つまり BGn有効フラグ
  struct BgCnt savedBgCnt[3];

  /*
    Metatileのマップデータ
    u16 width (現在のステージのピクセル単位の長さ)
    u16 pad
    u16 map[89102]
  */
  metatile_id_t tilemap[2 + 89102];  // =MetatileMap
  u16 unk_2c000;
  u16 unk_2c002;
  struct Coord unk_2c004;
  s32 sea;  // 海面のY座標
  s32 unk_2c010;

  /*
      見えない壁(左 -> 上 -> 右 -> 下)
      0だと存在しない
      例:
        左: レジスタンスベースの4階左
        右: レジスタンスベースの1階の港
  */
  s32 disableArea[4];
  u16 bgmap[2048];  // bit10セットでX反転するので実際のマップデータと同じなのは確認済み

  /*
    汎用データ領域
      壊れた宇宙船
        0:    雪を降らすか
        1..3: ???
  */
  u8 work[4];
};

// gOverworld, ステージの動的な地形情報
struct Overworld {
  struct Task task;
  struct Task *p;
  u8 unk_0c[20];
  struct StageLayer layer[3];  // 背景レイヤ BG1,2,3の挙動 (BG0は入ってない)
  struct Terrain terrain;      // 現在のステージの地形データ
  struct Overworld_1c8 unk_1c8;
  // ステージごとに用途が変わる
  union {
    u8 raw[264];
    struct {
      struct Boss *omega;
      struct Coord omegaCoord;
      u8 unk_00c[2];
      u16 unk_00e;
      u8 unk_010[248];
    } spacecraft;
    struct {
      u8 unk_000;
      u8 unk_001;
      u8 unk_002;
      u8 unk_003;
      u16 unk_004;
      u16 unk_006;
      struct Solid *coffins[2];
      u8 unk_010[248];
    } volcano;
    struct {
      u8 unk_000;
      u8 unk_001;
      u8 unk_002;
      u8 unk_003;
      struct Solid *btns[4];
      u8 unk_014[244];
    } ocean;
    struct {
      u8 unk_000;
      s8 unk_001;
      u8 unk_002;
      u8 unk_003;
      u8 unk_004[260];
    } repairFactory;
    struct {
      struct Solid *leaf;
      u8 unk_004[4];
      u16 unk_008;
      u16 unk_00a;
      u16 unk_00c;
      u16 unk_00e;
      u16 unk_010;
      u16 unk_012;
      u8 unk_014[244];
    } oldLifeSpace;
    struct {
      u8 unk_000;
      u8 unk_001;
      s8 unk_002;
      u8 unk_003;
      u16 unk_004;
      u16 unk_006;
      u8 unk_008;
      u8 unk_009;
      u8 unk_00a;
      u8 unk_00b;
      u32 unk_00c;
      u32 unk_010;
      struct Coord unk_014;
      u8 unk_01c[236];
    } missileFactory;
    struct {
      u8 unk_000;
      u8 unk_001;
      u8 unk_002;
      u8 unk_003;
      u8 unk_004;
      u8 unk_005;
      u8 unk_006[258];
    } twilightDesert;
    struct {
      struct Solid *leaf;
      u8 unk_004;
      u32 unk_008;
      u8 unk_00c;
      u8 unk_00d;
      u16 unk_00e;
      u8 unk_010[248];
    } anatreForest;
    struct {
      u16 unk_000;
      u8 unk_002[262];
    } iceBase;
    struct {
      u16 unk_000;
      u16 unk_002;
      u8 unk_004[2];
      u8 unk_006[2];
      u16 unk_008;
      u8 unk_00a[254];
    } areaX2;
    struct {
      u8 unk_000[4];
      s32 unk_004;
      s32 unk_008;
      u8 unk_00c[2];
      u16 unk_00e;
      u8 unk_010[2];
      u8 unk_012[2];
      u16 unk_014;
      u16 unk_016;
      u8 unk_018[240];
    } energyFacility;
    struct {
      u8 unk_000;
      u8 unk_001;
      u8 unk_002;
      u8 unk_003;
      u32 rng;
      u16 unk_008;
      u16 theta;
      u16 unk_00c;
      u8 unk_00e[250];
    } sunkenLib;
    struct {
      u8 unk_000[4];
      u16 unk_004;
      u16 unk_006;
      u8 unk_008[256];
    } giantElevator;
    struct {
      u8 unk_000;
      u8 unk_001;
      u8 unk_002;
      u8 unk_003;
      u8 unk_004[260];
    } subArcadia;
    struct {
      u8 unk_000;
      u8 unk_001[3];
      u32 unk_004;
      u16 unk_008;
      u16 unk_00a;
      u32 unk_00c;
      struct Coord unk_010;
      u32 unk_018;
      u32 unk_01c;
      u32 unk_020;
      struct Coord unk_024;
      struct Coord unk_02c;
      u8 unk_34[212];
    } weilLabo;
    struct {
      u8 unk_000;
      u8 weather;
      u8 unk_002;
      u8 unk_003;
      u8 unk_004[260];
    } resistanceBase;
  } work;  // ステージごとに用途が変わる
};         // 184360 bytes

#define SEA (gOverworld.unk_1c8.sea)

extern struct Overworld gOverworld;
extern const u8 gScreenY[2048];
extern const u8 gScreenX[3072];
extern const struct TerrainHeader gStageTerrains[STAGE_COUNT];

extern const struct Stage gStage0Landscape;
extern const struct Stage gSpacecraftLandscape;
extern const struct Stage gVolcanoLandscape;
extern const struct Stage gOceanLandscape;
extern const struct Stage gRepairFactoryLandscape;
extern const struct Stage gOldResidentialLandscape;
extern const struct Stage gResistanceBaseLandscape;
extern const struct Stage gMissileFactoryLandscape;
extern const struct Stage gTwilightDesertLandscape;
extern const struct Stage gAnatreForestLandscape;
extern const struct Stage gFrostlineIceBaseLandscape;
extern const struct Stage gAreaX2Landscape;
extern const struct Stage gEnergyFacilityLandscape;
extern const struct Stage gSnowyPlainsLandscape;
extern const struct Stage gSunkenLibraryLandscape;
extern const struct Stage gGiantElevatorLandscape;
extern const struct Stage gSubArcadiaLandscape;
extern const struct Stage gWeilLaboLandscape;

void ResetLandscape(s32 stageID, struct Coord *c);
void UpdateStageLandscape(struct Coord *c);
void DrawOverworld(struct TaskManager *p);
void SaveDispRegister(void);
void RestoreBackground(void);
void ExitStageLandscape(void);
metatile_attr_t GetMetatileAttr(s32 x, s32 y);
bool8 IsVoidSpace(s32 x, s32 y);
void FUN_08008eb8(s32 x, s32 y, struct Coord *c);
void CalcCameraDelta(struct Coord *c1, struct Coord *c2);
void ShiftMetatile(s32 x, s32 y, const struct MetatileShift *s);
void PatchMetatileMap(u32 x, u32 y, struct MetatilePatch *p);
void LoadScreenIntoMetatileMap(s32 screenX, s32 screenY, u16 screenID);
void ResetStageLayer(s32 n, const struct Stage *p);
void DrawGeneralStageLayer(struct StageLayer *p, const struct Stage *_);
u8 FUN_080094f0(s32 x, s32 y);
const struct Stage *UpdateStageTileset(struct Coord *c);
void UpdateStageLayer(struct StageLayer *p, const struct Stage *s, struct Coord *c);
s32 PushoutToDown2(s32 x, s32 y);
metatile_attr_t FUN_080098a4(s32 x, s32 y);
void AppendHazard(u16 id, u16 attr, const struct Coord *c, const struct Rect *size);
metatile_attr_t GetGroundMetatileAttr(s32 x, s32 y);
s32 PushoutToUp2(s32 x, s32 y);

void UpdateBGOFS(struct LayerGraphic *p, struct BgOfs *bgofs);
void ResetTerrain(struct Terrain *terrain, metatile_attr_t *attr, Metatile *tiles, Screen *m, const struct ScreenLayout *map);
void FUN_08006bb4(struct LayerGraphic *l, struct Coord *c, u32 *bgmap, struct MetatileMap *mm);
void FUN_08006a10(struct LayerGraphic *r0, struct Coord *c, u16 *map, metatile_id_t *bm);
void FUN_080050b0(struct LayerGraphic *l, struct Coord *c, u32 mapAddr);
void FUN_08005a70(struct LayerGraphic *l, struct Coord *c, u32 mapAddr);

void ResetLayerGraphic(struct LayerGraphic *p, struct Coord *c, u16 *_, Metatile *tiledata, Screen *screens, const struct ScreenLayout *map);

/**
 * @brief (x, y)がgStageのBlocking領域に含まれるかどうか
 * @param start -1固定(特に意味はない)
 * @return 0: Blockingの中ではない、 それ以外: Hazard.arrのidx(Hazard.arr[idx]の領域内)
 */
s32 isStageBlocking(s32 start, s32 x, s32 y);

#endif  // GUARD_RMZ3_OW_MANAGER_H
