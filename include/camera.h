#ifndef GUARD_RMZ3_CAMERA_H
#define GUARD_RMZ3_CAMERA_H

#include "common.h"
#include "entity.h"
#include "gba/types.h"

struct TaskManager;
struct Camera;

typedef void (*CameraFunc)(struct Camera*);

// カメラの初期設定 08022418 で利用
struct CameraTemplate {
  u8 mode;
  u8 chaseMode;
  u8 unk_02;
  u8 unk_03;
  struct Coord camera;
  struct Coord forceScrollSpeed;
  s16 unk_left;
  s16 unk_right;
  s16 unk_top;
  s16 unk_bottom;
  s32 left;
  s32 right;
  s32 top;
  s32 bottom;
};

struct Camera {
  struct Pivot pivot;
  const struct CameraTemplate* template;
  struct TaskManager* taskManager;
  CameraFunc callback;  // 毎フレーム呼び出される
  s8 mode;
  u8 chaseMode;  // .target に .coord を近づける挙動モード
  s16 unk_1a;
  bool8 unk_1c;
  u16 ALIGNED(4) unk_20;
  s16 unk_22;
  u8 unk_24[4];
  struct Coord base;              // カメラの始点 画面の振動で利用
  struct Coord target;            // .coordがあるべき位置 .flagsによって、ここに.coordを徐々に近づけたり、一気にここに.coordがワープするよう設定する
  struct Coord viewport;          // 現在の画面中央
  struct Coord forceScrollSpeed;  // 強制スクロールの速度
  struct Coord* zero;
  s32 unk_left;
  s32 unk_right;
  s32 unk_top;
  s32 unk_bottom;
  s32 left;    // cameraMode 4以上の時の境界
  s32 right;   // cameraMode 4以上の時の境界
  s32 top;     // cameraMode 4以上の時の境界
  s32 bottom;  // cameraMode 4以上の時の境界
};

void RunCameraCallback(struct Camera* p);
void RunAllDrawTasks(struct Camera* p);
void quake_0801a604(struct Camera* p);
void ResetCamera(struct Camera* camera, const struct CameraTemplate* template, struct TaskManager* tm);

#endif  // GUARD_RMZ3_CAMERA_H
