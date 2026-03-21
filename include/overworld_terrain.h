#ifndef GUARD_RMZ3_OW_MANAGER_H
#define GUARD_RMZ3_OW_MANAGER_H

#include "boss.h"
#include "chunk.h"
#include "gfx.h"
#include "global.h"
#include "metatile.h"
#include "overworld_layer.h"
#include "overworld_layer_gfx.h"
#include "solid.h"

#define USE_BG1 0x12
#define USE_BG2 0x24
#define USE_BG3 0x38

#define W_TERRAIN_V2 gOverworld.terrain

#define HAZARD(n) (&gOverworld.terrain.objects[n])

// マップデータ(2KB単位)を置くブロック -> 0x0600_0000 + (0x800)*n
#define BGMAP_BLOCK(n) (n << 8)

typedef void (*StageFunc)(struct Coord*);

/*
  例: 0x0863c638
  チャンクID から メタタイルID と　そのメタタイル属性 を取得するために必要な情報 (へのアクセスに必要なメモリオフセット)
*/
struct TerrainHeader {
  s32 tiles;    // Metatileの配列 e.g. 0x086ee6b0
  s32 attrs;    // metatile_attr_t の配列
  s32 screens;  // Screenの配列
};

// ROMが保持しているステージの静的な情報
struct Stage {
  u32 id;               // ステージID
  const StageFunc* fn;  // ステージ自体に割り当てられたルーチン
  const struct TerrainHeader* terrainHdr;
  const struct ChunkMap* maps[STAGE_LAYER_NUM];  // ステージ全体でチャンクをどう配置するかのデータ (ステージレイヤ3枚分)
  u32 bgIdx[STAGE_LAYER_NUM];                    // ステージレイヤが実際のGBAのどのBGレイヤに割り当てられるか  bit4-8がbgcntのn(BGnか), そしてbit0-4 は (1 << n) したもの
  u32 prio[STAGE_LAYER_NUM];                     // BG Priority for layer
  u32 screenBase[STAGE_LAYER_NUM];               // 各ステージレイヤのBGマップデータの配置先アドレス
  struct Coord scrollPower[STAGE_LAYER_NUM];
  struct Coord scroll[STAGE_LAYER_NUM];  // レイヤに常に加算されるスクロール値(ピクセル単位) つまりxに16を加えるとレイヤが16pxずれる(あくまでずれるのはレイヤの見た目で地形はずれない)
  const tileset_ofs_t* tilesetOffset;    // tilesetOffset[n] >> 4 が
  const StageLayerRoutine* bgFns;        // ステージレイヤに割り当てられるルーチンのテーブル, 全部のステージレイヤのルーチンがまとまっており、 ステージレイヤの種類,現在のチャンク から どのルーチンを割り当てるかが決まる
  const u16* behavior;                   // 現在の座標から bgFns のインデックスを得るためのテーブル
  s32 conveyor[2];                       // Overworld.conveyor
};

// ステージのROMデータ
struct TerrainROMPointer {
  metatile_attr_t* attrs;
  Metatile* tiles;
  Screen* screens;             // TerrainHeader.screens
  const struct ChunkMap* map;  // ステージレイヤ0(STAGE_LAYER_TERRAIN)の ChunkMap = sChunkMap1
};  // 16 bytes

// 物理判定を持つEntity (グランドキャノンや旧居住区の燃やせる木, アイスボンの氷など)
// Objectに改名してもいいかも (GBAのスプライトをObjectって呼ぶこともあってややこしいと思って Hazard にした)
struct Hazard {
  u16 id;
  metatile_attr_t attr;
  u16 w;
  u16 h;
  struct Coord start;
  struct Coord unk_10;
};  // 24 bytes
static_assert(sizeof(struct Hazard) == 24);

// 地形レイヤのMetatileのマップデータ (ステージ全体分)
struct MetatileMap {
  u16 width16;  // ステージ全体の横幅(メタタイル単位)
  u16 _;

  /*
    0..width16:           MetaCoord is 0 (y= 0px)
    width16..width16*2:     MetaCoord is 1 (y=16px)
    width16*2..width16*3:   MetaCoord is 2 (y=32px)
    ...
    width16*10..width16*11: MetaCoord is 10 (y=160px)
    ...

    so, map is metatile_id_t map[89100/width16][width16]
  */
  metatile_id_t map[89100];
  u32 unused;
};

//
struct Terrain {
  struct TerrainROMPointer hdr;  // 0x020023b8, 現在のステージの地形ROMデータ
  struct Coord viewport;         // 現在写っているの画面中央の座標
  u16 id;                        // ステージID (Bit7(0x80)は、initRBaseとかの初期化関数が実行されていないことを示す)

  // 0x020023D2, 現在読み込まれている Entity　の中で物理判定を持つものの管理データ
  u8 objectLen;
  u8 objectLenPrev;
  struct Hazard objects[32];
  struct Hazard objectsPrev[32];

  tileset_t tilesets[2];

  u16 enabledBg;  // DISPCNTの bit8..11 つまり BGn有効フラグ
  struct BgCnt savedBgCnt[3];

  u16 tilemap[2 + 89100 + 2];  // 0x020029e0 .layer[STAGE_LAYER_TERRAIN]のステージ全体のMetatileのマップ, 壁との押し出し判定などで参照される (他のステージレイヤは描画用で参照しないので STAGE_LAYER_TERRAIN だけでいい)
  // struct MetatileMap tilemap;  // 0x020029e0 .layer[STAGE_LAYER_TERRAIN]のステージ全体のMetatileのマップ, 壁との押し出し判定などで参照される (他のステージレイヤは描画用で参照しないので STAGE_LAYER_TERRAIN だけでいい)

  bool16 tilemap_duty;  // 0x0202E200 tilemap がロード時以降書きかわった際にTRUEになるフラグ?

  bool16 reload_graphic;  // メニュー画面などに入って、ワールドで使っていたタイルデータやBGマップが破壊されたときに、ワールドから戻った後、それらを再ロードさせるためのフラグ

  s32 conveyor[2];  // 0x0202E204 工場のベルトコンベアや砂漠の流砂などのスピード(どちらもX方向で基本的に正負が違うだけで同じ値) Stage.conveyor
};

// gOverworld, ステージの動的な地形情報
struct Overworld {
  struct Task task;
  struct Task* p;
  u8 unk_0c[20];

  // ステージは最大3枚のレイヤ(ステージレイヤ)を持つ, layer[0] は地形データ, layer[1] は水面や草など(プレイヤーの行動によって変化しうるものがココ？), layer[2] は雲などの背景
  // NOTE: 1枚のステージレイヤは1枚のBGレイヤに対応するが、 layer[0] が BG1, layer[1] が BG2, layer[2] が BG3 とは限らない
  struct StageLayer layer[STAGE_LAYER_NUM];

  struct Terrain terrain;  // 0x020023b8, 現在のステージの地形データ

  s32 sea;  // 海面のY座標
  s32 unused_2c010;

  /*
    見えない壁(左 -> 上 -> 右 -> 下) = ステージ(世界)の範囲
    例:
      左: レジスタンスベースの4階左
      右: レジスタンスベースの1階の港
*/
  struct Area32 range;
  u16 bgmap[2048];  // .tilemap をカメラ座標 に応じて (GBAのBGマップ形式に変換して)切り出したもの

  /*
    汎用データ領域
      壊れた宇宙船
        0:    雪を降らすか
        1..3: ???
  */
  u8 state[4];

  // 0x2d028 ..
  // ステージごとに用途が変わる
  union {
    u8 raw[264];
    struct {
      struct Boss* omega;
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
      struct Solid* coffins[2];
      u8 unk_010[248];
    } volcano;
    struct {
      u8 unk_000;
      u8 unk_001;
      s8 unk_002;
      u8 unk_003;
      struct Solid* btns[4];
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
      struct Solid* leaf;
      u8 unk_004[4];
      u16 unk_008;
      u16 unk_00a;
      u16 unk_00c;
      u16 unk_00e;
      u16 unk_010;
      u16 unk_012;
      u8 unk_014[244];
    } oldResidential;
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
      struct Solid* leaf;
      u8 unk_004;
      struct Solid* unk_008;
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
};  // 184360 bytes

#define SEA (gOverworld.sea)

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

void ResetLandscape(s32 stageID, struct Coord* c);
void UpdateStageLandscape(struct Coord* c);
void DrawOverworld(struct TaskManager* p);
void SaveDispRegister(void);
void RestoreBackground(void);
void ExitStageLandscape(void);
bool8 IsVoidSpace(s32 x, s32 y);
void LoadScreenIntoMetatileMap(s32 screenX, s32 screenY, u16 screenID);
void AppendHazard(u16 id, u16 attr, const struct Coord* c, const struct Rect* size);

/**
 * @brief (x, y)がgStageのBlocking領域に含まれるかどうか
 * @param start -1固定(特に意味はない)
 * @return 0: Blockingの中ではない、 それ以外: Hazard.arrのidx(Hazard.arr[idx]の領域内)
 */
s32 isStageBlocking(s32 start, s32 x, s32 y);

#endif  // GUARD_RMZ3_OW_MANAGER_H
