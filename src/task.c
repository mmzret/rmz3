#include "task.h"

#include "entity.h"
#include "global.h"
#include "overworld.h"
#include "sprite.h"
#include "story.h"

void ResetTaskManager(struct TaskManager *tm) {
  CpuFastFill(0, tm->buffer, TASK_LENGTH * 4);
  { vu32 _; }
  tm->tasks = &tm->buffer;
  tm->pivot = NULL;
  tm->_ = NULL;
}

void SetTaskPivot(struct TaskManager *tm, struct Pivot *pivot) {
  tm->pivot = pivot;
  return;
}

#if MODERN == 0
static void unused_08004e58(struct TaskManager *tm, void *r1) {
  tm->_ = r1;
  return;
}
#endif

void PrependTask(struct TaskManager *tm, struct Task *task) {
  task->next = (*tm->tasks)[0];
  (*tm->tasks)[0] = task;
}

static void unused_08004e74(struct TaskManager *tm, struct Task *task, s16 row) {
  struct Task *cur = (*tm->tasks)[row * 32];
  task->next = cur;
  (*tm->tasks)[row * 32] = task;
}

/*
Tasks
        Col0  Col1 .. Col30  Col31
Row 0    t0    t1
Row 1
Row 2
Row 3

tn は タスク1つではなくタスクのリンクリスト (t0なら t0 -> t0' -> t0'' -> ...)
*/
void AppendTask(struct TaskManager *tm, struct Task *task, s16 row, s16 col) {
  struct Task *cur = (&((*tm->tasks)[row * 32]))[col];
  task->next = cur;
  (&((*tm->tasks)[row * 32]))[col] = task;
}

void RunAllTasks(struct TaskManager *tm) {
  s32 i;
  struct Task **list;
  struct DrawPivot c;

  if (tm->pivot != NULL) {
    CreateDrawPivot(&c, tm->pivot, tm->_);
    list = (struct Task **)(*tm->tasks);

    for (i = 0; i < TASK_LENGTH; i++) {
      struct Task *task = list[0];
      list = &list[1];
      for (; task != NULL; task = task->next) {
        (task->fn)(task, &c);
      }
    }
  }
}

void ClearTaskBuffer(struct TaskManager *tm) {
  struct Task *(*heap)[TASK_LENGTH] = Malloc(TASK_LENGTH * 4);

  tm->tasks = heap;
  if (heap == NULL) {
    tm->tasks = &tm->buffer;
  }

  {
    const u32 fill = 0;
    void *dst = *tm->tasks;
    CpuFastFill(fill, dst, TASK_LENGTH * 4);
    { vu32 _; }
  }
}
