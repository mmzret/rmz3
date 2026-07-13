#ifndef GUARD_RMZ3_OW_LAYER_H
#define GUARD_RMZ3_OW_LAYER_H

#include "chunk.h"
#include "metatile.h"
#include "overworld_layer_gfx.h"

// ステージは最大3枚のレイヤ(ステージレイヤ)を持つ, layer[0] は地形データ, layer[1] は水面や草など(プレイヤーの行動によって変化しうるものがココ？), layer[2] は雲などの背景
// NOTE: 1枚のステージレイヤは1枚のBGレイヤに対応するが、 layer[0] が BG1, layer[1] が BG2, layer[2] が BG3 とは限らない

// StageLayer.type
#define STAGE_LAYER_TERRAIN 0  // 地形レイヤ (足場や坂道などの物理的な地形データを持つメインのステージレイヤ)
#define STAGE_LAYER_1 1        // 物理的な地形データを持たない装飾用レイヤ, 旧居住区の ツタやキノコ, 水面　など
#define STAGE_LAYER_2 2        // 物理的な地形データを持たない装飾用レイヤ, STAGE_LAYER_1 と用途を区別しているかは不明
#define STAGE_LAYER_NUM 3

enum LayerRoutine {
  LAYER_UPDATE,  // 0  UpdateStageLandscape で呼び出される
  LAYER_DRAW,    // 1, RenderTask_Overworld で呼び出される
  LAYER_EXIT,    // 2  ExitStageLandscape, UpdateStageLayer で呼び出される
};

struct StageLayer;
struct Stage;

typedef void (*StageBgFunc)(struct StageLayer*, const struct Stage*);
typedef StageBgFunc StageLayerRoutine[3];  // [update1, update2, exit], LayerRoutine

// ステージレイヤ
struct StageLayer {
  StageLayerRoutine fn;                  // 0x00
  u16 type;                              // 0x0C, このステージレイヤのタイプ(0: 地形データ, 1,2: 水面や草, 雲などの見栄えのための汎用レイヤ?)
  u8 phase;                              // 0x0E, StageLayerの状態を表す
  u8 unk_0f;                             // 0x0F
  u16 unk_10;                            // 0x10
  u16 unk_12;                            // 0x12
  struct LayerGraphic gfx;               // 0x14
  Coords32 drawPivotOffset;              // 0x2C, 画面の振動時に0以外になってた
  PixelCoords viewportLeftTopPixel;      // 0x34, 現在の画面左上のワールド座標(ピクセル単位)
  PixelCoords prevViewportLeftTopPixel;  // 0x3C, 1フレーム?前の.viewportLeftTopPixel
  Coords32 scrollPower;                  // 0x44, ゼロが1px動く時に、画面がどれくらいスクロールするか(256で1px動くと1pxスクロール,つまり1倍, 512で1px動くと2pxスクロール,つまり2倍)
  PixelCoords scroll;                    // 0x4C
  PixelCoords scrollCopy;                // 0x54
  u32 bgIdx;                             // 0x5C, このステージレイヤが、実際のGBAのどのBGレイヤに割り当てられるか  bit4-8がbgcntのn(BGnか), そしてbit0-4 は (1 << n) したもの
  u32 prio;                              // 0x60, BGCNTn の bit0-1　部分でもある
  u32 screenBase;                        // 0x64
  union {
    u8 raw[32];
    struct {
      u8 frameCounter;  // 0x68, 例: 壊れた宇宙船で背景の雲の流れと連動
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
      u8 frameCounter;  // 0x68
      u8 _[3];
      u8 unk_6c[28];
    } ocean;
    struct {
      s32 scrollTimer;
      Coords32 c;
      u8 unk_74[20];
    } missile;
  } work;  // 0x68, ステージによる

  // ステージによる？
};  // 136 bytes
static_assert(sizeof(struct StageLayer) == 136);

void DrawGeneralStageLayer(struct StageLayer* p, const struct Stage* _);

#endif  // GUARD_RMZ3_OW_LAYER_H
