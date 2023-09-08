#ifndef GUARD_RMZ3_TASK_H
#define GUARD_RMZ3_TASK_H

#include "common.h"
#include "constants/constants.h"
#include "types.h"

// RunAllTasks
struct Task {
  struct Task *next;
  void (*fn)(struct Task *, struct DrawPivot *);
};

struct TaskManager {
  struct Task *buffer[TASK_LENGTH];    // タスク用のメモリ領域？
  struct Task *(*tasks)[TASK_LENGTH];  // e.g. 0x03000380 (-> [02002200, 03007874])
  struct Pivot *pivot;                 // &camera->pivot
  void *_;                             // Unused
};

void ResetTaskManager(struct TaskManager *tm);
void SetTaskPivot(struct TaskManager *tm, struct Pivot *pivot);
void PrependTask(struct TaskManager *tm, struct Task *task);
void AppendTask(struct TaskManager *tm, struct Task *task, s16 prio, s16 x);
void ClearTaskBuffer(struct TaskManager *tm);
void RunAllTasks(struct TaskManager *tm);

void SetTaskCallback(struct Task *t, void *cb);

#endif  // GUARD_RMZ3_TASK_H