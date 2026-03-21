#ifndef GUARD_RMZ3_OW_STAGE_H
#define GUARD_RMZ3_OW_STAGE_H

#include "chunk.h"
#include "overworld_layer.h"

// ROMが保持しているステージの静的な情報 のことを Stage (ステージ) と呼んでいるが、後で名前を変える予定

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
