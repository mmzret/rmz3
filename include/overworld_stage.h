#ifndef GUARD_RMZ3_OW_STAGE_H
#define GUARD_RMZ3_OW_STAGE_H

#include "chunk.h"
#include "overworld_layer.h"

// ROMが保持しているステージの静的な情報 のことを Stage (ステージ) と呼んでいるが、後で名前を変える予定

// FUN_080094f0
// (カメラに関係する値 << 12) | (Bg1のbgFnsのインデックス) | (Bg2のbgFnsのインデックス) | | (Bg3のbgFnsのインデックス)
// scroll_type:
// 0x0： 自由移動範囲
// 0x2..D： 数値の隣の値が2以上異なる場合、部屋の境界を越えない限りスクロールしない (「粘着型」スクロール方式)
// 0xE： カメラが部屋の上部にスクロールするのを防ぎますが、プレイヤーの移動や死亡は阻止しません
// 0xF： その部屋にカメラをスクロールさせず、プレイヤーが入室してもプレイヤーを死亡させない設定です
#define LAYER_CB(scroll_type, bg1, bg2, bg3) ((scroll_type << 12) | ((bg1 << 8) | (bg2 << 4) | (bg3 << 0)))

typedef void (*StageFunc)(Coords32*);

// e.g. 0x0863c638
typedef struct {
  s32 tiles;   // Metatileの配列, メタタイルID から　 GBAのタイルID を取得するのに必要,  &self + .tiles
  s32 attrs;   // metatile_attr_t の配列, メタタイルID から そのメタタイルの属性 を取得するのに必要, &self + .attrs (&.attrs + .attrs ではない)
  s32 chunks;  // Screenの配列, チャンクID から メタタイルID を取得するのに必要, &self + .chunks
} MetatileMapSelfRelPtr;

// ROMが保持しているステージの静的な情報
struct Stage {
  u32 id;                                        // 0x00, ステージID
  const StageFunc* fn;                           // 0x04, ステージ自体に割り当てられたルーチン
  const MetatileMapSelfRelPtr* terrainHdr;       // 0x08, 常に &gStageTerrains[STAGE_ID]
  const struct ChunkMap* maps[STAGE_LAYER_NUM];  // 0x0C, ステージ全体でチャンクをどう配置するかのデータ (ステージレイヤ3枚分)
  u32 bgIdx[STAGE_LAYER_NUM];                    // 0x18, ステージレイヤが実際のGBAのどのBGレイヤに割り当てられるか  bit4-8がbgcntのn(BGnか), そしてbit0-4 は (1 << n) したもの
  u32 prio[STAGE_LAYER_NUM];                     // 0x24, BG Priority for layer
  u32 screenBase[STAGE_LAYER_NUM];               // 0x30, 各ステージレイヤのBGマップデータの配置先アドレス
  Coords32 scrollPower[STAGE_LAYER_NUM];         // 0x3C
  PixelCoords scroll[STAGE_LAYER_NUM];           // 0x54, レイヤに常に加算されるスクロール値(ピクセル単位) つまりxに16を加えるとレイヤが16pxずれる(あくまでずれるのはレイヤの見た目で地形はずれない)
  const tileset_ofs_t* tilesetOffset;            // 0x6C, チャンク座標 と 読み込むタイルセット の対応表, bit0-3: gOverworld.terrain.tilesets[1], bit4-7: gOverworld.terrain.tilesets[0]
  const StageLayerRoutine* bgFns;                // 0x70, ステージレイヤに割り当てられるルーチンのテーブル, 全部のステージレイヤのルーチンがまとまっており、 ステージレイヤの種類,現在のチャンク から どのルーチンを割り当てるかが決まる
  const u16* behavior;                           // 0x74, 現在の座標から bgFns のインデックス および　カメラに関する何か を得るためのテーブル (TODO: chunkAttr とかに名前を変えたほうがいいかも?)
  s32 conveyor[2];                               // 0x78, Overworld.conveyor
};
static_assert(sizeof(struct Stage) == 128);

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

#endif  // GUARD_RMZ3_OW_STAGE_H
