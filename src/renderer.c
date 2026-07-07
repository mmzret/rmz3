#include "renderer.h"

#include "entity.h"
#include "global.h"
#include "sprite.h"

// 0x08004e14
void Renderer_Init(Renderer* r) {
  _CpuFastFill(0, r->slow_buffer, TASK_LENGTH * 4);
  r->tasks = &r->slow_buffer;
  r->pivot = NULL;
  r->_ = NULL;
}

/**
 * @param pivot &gStageRun.vm.camera.pivot or &gGameState.unk_0db8
 * @note 0x08004e4c
 */
void Renderer_SetPivot(Renderer* r, struct Pivot* pivot) { r->pivot = pivot; }

static void unused_08004e58(Renderer* r, void* r1) { r->_ = r1; }

// 描画タスクを1番最初に実行されるようにレンダラにわたす (つまり、後続の描画タスクでどんどん上書きされていく)
// 0x08004e64
void Renderer_PrependTask(Renderer* r, RenderNode* task) {
  task->next = (*r->tasks)[0][0];
  (*r->tasks)[0][0] = task;
}

static void unused_08004e74(Renderer* r, RenderNode* task, s16 prio) {
  RenderNode* cur = (*r->tasks)[prio][0];
  task->next = cur;
  (*r->tasks)[prio][0] = task;
}

// 0x08004e8c
void Renderer_SendTask(Renderer* r, RenderNode* task, s16 prio, s16 col) {
  RenderNode* cur = (*r->tasks)[prio][col];
  task->next = cur;
  (*r->tasks)[prio][col] = task;
}

/**
 * @brief リクエストされた描画タスクをすべて実行する
 * @details .tasks[0][0] から .tasks[3][31] の順に描画タスクを呼び出す
 * @remark .tasks[i][j] に入っているのは、 DrawTask のリンクリストであることに注意
 * @note 0x08004EB0
 */
void Renderer_Flush(Renderer* r) {
  s32 i;
  RenderNode** list;
  struct DrawPivot c;

  if (r->pivot != NULL) {
    CreateDrawPivot(&c, r->pivot, r->_);

    list = (RenderNode**)(*r->tasks);
    for (i = 0; i < TASK_LENGTH; i++) {
      RenderNode* node = list[0];  // = .tasks[i / 32][i % 32]
      list = &list[1];
      while (node != NULL) {  // node -> node->next -> node->next->next -> ... -> NULL
        (node->fn)(node, &c);
        node = node->next;
      }
    }
  }
}

// レンダラのタスクバッファをクリアする (フレーム開始時に呼び出す)
// 0x08004f00
void Renderer_Clear(Renderer* r) {
  r->tasks = Malloc(TASK_LENGTH * 4);
  if (r->tasks == NULL) {  // Malloc失敗、つまり IWRAM に余裕がない場合は自前のバッファ(EWRAMなので低速)を使う
    r->tasks = &r->slow_buffer;
  }

  {
    const u32 fill = 0;
    void* dst = *r->tasks;
    _CpuFastFill(fill, dst, TASK_LENGTH * 4);
  }
}
