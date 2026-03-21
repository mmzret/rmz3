#ifndef GUARD_RMZ3_OW_LAYER_H
#define GUARD_RMZ3_OW_LAYER_H

#include "chunk.h"
#include "metatile.h"
#include "overworld_layer_gfx.h"

// StageLayer.type
#define STAGE_LAYER_TERRAIN 0  // 地形レイヤ (足場や坂道などの物理的な地形データを持つメインのステージレイヤ)
#define STAGE_LAYER_1 1        // 物理的な地形データを持たない装飾用レイヤ, 旧居住区の ツタやキノコ, 水面　など
#define STAGE_LAYER_2 2        // 物理的な地形データを持たない装飾用レイヤ, STAGE_LAYER_1 と用途を区別しているかは不明
#define STAGE_LAYER_NUM 3

enum LayerRoutine {
  LAYER_UPDATE,
  LAYER_DRAW,
  LAYER_EXIT,
};

struct StageLayer;
struct Stage;

typedef void (*StageBgFunc)(struct StageLayer*, const struct Stage*);
typedef StageBgFunc StageLayerRoutine[3];  // [update1, update2, exit], LayerRoutine

// ステージレイヤ
struct StageLayer {
  StageLayerRoutine fn;
  u16 type;  // このステージレイヤのタイプ(0: 地形データ, 1,2: 水面や草, 雲などの見栄えのための汎用レイヤ?)

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

  u32 bgIdx;  // このステージレイヤが、実際のGBAのどのBGレイヤに割り当てられるか  bit4-8がbgcntのn(BGnか), そしてbit0-4 は (1 << n) したもの
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

void DrawGeneralStageLayer(struct StageLayer* p, const struct Stage* _);

#endif  // GUARD_RMZ3_OW_LAYER_H
