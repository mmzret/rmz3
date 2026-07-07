#ifndef GUARD_RMZ3_RENDERER_H
#define GUARD_RMZ3_RENDERER_H

#include "common.h"
#include "constants/constants.h"
#include "gba/gba.h"
#include "types.h"

// 描画に順番を設定するための描画タスク管理

#define TASK_LENGTH 128

// 任意の型のポインタ + そのポインタ+pivot で呼び出すコールバック
typedef struct RenderNode {
  struct RenderNode* next; /* 同じ優先度を持つ次のタスクへのポインタ */
  void (*fn)(struct RenderNode*, struct DrawPivot*);
} RenderNode;  // 8 bytes

typedef struct {
  RenderNode node;  // 0x00
  void* ptr;        // 0x08, 任意のポインタ
  u8 buf[20];       // 0x0C, 汎用
} RenderData;
static_assert(sizeof(RenderData) == 32);

typedef RenderNode* DrawQueue[4][32];

typedef struct Renderer {
  DrawQueue slow_buffer;  // タスク用のメモリ領域(IWRAMに余裕がない場合はここを使う)
  DrawQueue* tasks;       // 現在の DrawQueue へのポインタ
  struct Pivot* pivot;    // &camera->pivot
  void* _;                // Unused
} Renderer;
static_assert(sizeof(Renderer) == 524);

void Renderer_Init(Renderer* r);
void Renderer_SetPivot(Renderer* r, struct Pivot* pivot);
void Renderer_PrependTask(Renderer* r, RenderNode* task);
void Renderer_SendTask(Renderer* r, RenderNode* task, s16 prio, s16 x);
void Renderer_Clear(Renderer* r);
void Renderer_Flush(Renderer* r);

void SetTaskCallback(RenderNode* t, void* cb);

#endif  // GUARD_RMZ3_RENDERER_H
