#include "camera.h"

#include "global.h"
#include "overworld.h"
#include "sprite.h"

static void focus(struct Camera* camera, u8 r1);

void ResetCamera(struct Camera* camera, const struct CameraTemplate* template, struct TaskManager* tm) {
  camera->template = template;
  camera->taskManager = tm;
  (camera->viewport).x = 0;
  (camera->viewport).y = 0;
  ResetPivot(&camera->pivot, &camera->viewport, 0, 0);
  (camera->pivot).offset = &camera->base;
  camera->chaseMode = 0;
  camera->unk_22 = 0;
  LoadCameraTemplate(camera, template);
  focus(camera, 8);
}

void RunCameraCallback(struct Camera* camera) {
  camera->callback(camera);
  return;
}

void quake_0801a604(struct Camera* camera) {
  CalcQuake(&camera->viewport, &camera->base);
  quake_0801acdc(&camera->viewport);
}

void RunAllDrawTasks(struct Camera* camera) {
  struct TaskManager* tm = camera->taskManager;
  if (camera->mode != 0) {
    SetTaskPivot(tm, &camera->pivot);
    RunAllTasks(tm);
  }
}

// --------------------------------------------

static void CameraMode0Callback(struct Camera* _);
static void CameraMode1Callback_ForceScroll(struct Camera* camera);
static void CameraMode2Callback(struct Camera* camera);
static void CameraMode3Callback(struct Camera* camera);
static void CameraMode4Callback(struct Camera* camera);
static void CameraMode7Callback(struct Camera* camera);

void SetCameraMode(struct Camera* camera, u32 mode) {
  // clang-format off
  static const CameraFunc sUpdates[8] = {
      [0] = CameraMode0Callback,
      [1] = CameraMode1Callback_ForceScroll,
      [2] = CameraMode2Callback,
      [3] = CameraMode3Callback,
      [4] = CameraMode4Callback,
      [5] = CameraMode4Callback,
      [6] = CameraMode4Callback,
      [7] = CameraMode7Callback,
  };
  // clang-format on
  camera->mode = mode;
  *(u32*)&camera->unk_1c = 0;
  camera->unk_20 = 0;
  camera->unk_1a = 0;
  camera->callback = sUpdates[mode];
}

void LoadCameraTemplate(struct Camera* camera, const struct CameraTemplate* t) {
  if (t == NULL) {
    SetCameraMode(camera, 0);
    camera->zero = NULL;
    camera->chaseMode = 0;
    camera->unk_22 = 0;
    (camera->target).x = 0;
    (camera->target).y = 0;
    return;
  }

  SetCameraMode(camera, t->mode);
  camera->chaseMode = t->chaseMode;
  camera->unk_22 = 0;
  camera->zero = NULL;
  if (t->mode == 1) {
    (camera->target).x = (t->camera).x;
    (camera->target).y = (t->camera).y;
  }
  (camera->forceScrollSpeed).x = (t->forceScrollSpeed).x;
  (camera->forceScrollSpeed).y = (t->forceScrollSpeed).y;
  camera->unk_left = t->unk_left;
  camera->unk_right = t->unk_right;
  camera->unk_top = t->unk_top;
  camera->unk_bottom = t->unk_bottom;
  camera->left = t->left;
  camera->right = t->right;
  camera->top = t->top;
  camera->bottom = t->bottom;
}

// .viewport を .target に近づける
WIP static void focus(struct Camera* camera, u8 chaseMode) {
#if MODERN
  switch (chaseMode) {
    case 0: {
      break;
    }
    case 1: {
      s32 delta = (camera->target).x - (camera->viewport).x;
      if (delta > 0) {
        (camera->viewport).x += (delta + 31) >> 5;
      } else {
        (camera->viewport).x += (delta - 31) >> 5;
      }
      delta = (camera->target).y - (camera->viewport).y;
      if (delta > 0) {
        (camera->viewport).y += (delta + 31) >> 5;
      } else {
        (camera->viewport).y += (delta - 31) >> 5;
      }
      return;
    }
    case 2: {
      if (camera->unk_22 < 0x3FF) {
        camera->unk_22++;
        {
          s32 x = (0x400 - camera->unk_22) * ((camera->viewport).x >> 2) + camera->unk_22 * ((camera->target).x >> 2);
          if (x < 0) {
            x += 0xFF;
          }
          (camera->viewport).x = (x >> 8);
        }
        {
          s32 y = (0x400 - camera->unk_22) * ((camera->viewport).y >> 2) + camera->unk_22 * ((camera->target).y >> 2);
          if (y < 0) {
            y += 0xFF;
          }
          (camera->viewport).y = (y >> 8);
        }
        if (((camera->viewport).x - (camera->target).x) <= 0x80) {
          (camera->viewport).x = (camera->target).x;
        }
        if (((camera->viewport).y - (camera->target).y) <= 0x80) {
          (camera->viewport).y = (camera->target).y;
        }
        return;
      }
      break;
    }
    case 4: {
      if (camera->unk_22 < 0xFF) {
        camera->unk_22++;
        {
          s32 x = ((0x100 - camera->unk_22) * (camera->viewport).x) + (camera->unk_22 * (camera->target).x);
          if (x < 0) {
            x += 0xFF;
          }
          (camera->viewport).x = (x >> 8);
        }
        {
          s32 y = ((0x100 - camera->unk_22) * (camera->viewport).y) + (camera->unk_22 * (camera->target).y);
          if (y < 0) {
            y += 0xFF;
          }
          (camera->viewport).y = (y >> 8);
        }
        if (((camera->viewport).x - (camera->target).x) <= 0x80) {
          (camera->viewport).x = (camera->target).x;
        }
        if (((camera->viewport).y - (camera->target).y) <= 0x80) {
          (camera->viewport).y = (camera->target).y;
        }
        return;
      }
      break;
    }
    default: {
      camera->chaseMode &= 0xF7;
      break;
    }
  }
  (camera->viewport).x = (camera->target).x;
  (camera->viewport).y = (camera->target).y;
#else
  INCCODE("asm/wip/camera_0801a6d0.inc");
#endif
}

/**
 * @retval 0 c is in Camera(Screen)
 * @retval カメラからの距離(x方向の距離とy方向の距離の長い方)
 */
u32 CalcFromCamera(struct Camera* camera, struct Coord* c) {
  s32 dx, dy;

  dx = (camera->viewport).x - c->x;
  if (dx < 0) {
    dx = -PIXEL(DISPLAY_WIDTH / 2) - dx;
  } else {
    dx = dx - PIXEL(DISPLAY_WIDTH / 2);
  }
  if (dx < 0) dx = 0;

  dy = (camera->viewport).y - c->y;
  if (dy < 0) {
    dy = -PIXEL(DISPLAY_HEIGHT / 2) - dy;
  } else {
    dy = dy - PIXEL(DISPLAY_HEIGHT / 2);
  }
  if (dy < 0) dy = 0;

  if (dx < dy) {
    return dy;
  }
  return dx;
}

static void CameraMode0Callback(struct Camera* _) { return; }

static void CameraMode1Callback_ForceScroll(struct Camera* camera) {
  if (camera->unk_1c == FALSE) {
    camera->unk_22 = 0;
    camera->unk_1c++;
  }
  (camera->target).x += (camera->forceScrollSpeed).x;
  (camera->target).y += (camera->forceScrollSpeed).y;
  focus(camera, camera->chaseMode);
}

static void CameraMode2Callback(struct Camera* camera) {
  s32 left, top;
  if (camera->unk_1c == FALSE) {
    camera->unk_22 = 0;
    camera->unk_1c++;
  }
  left = camera->unk_left + camera->unk_right;
  camera->unk_left = left;

  top = camera->unk_top + camera->unk_bottom;
  camera->unk_top = top;

  if (camera->zero != NULL) {
    (camera->target).x = camera->zero->x + left;
    (camera->target).y = camera->zero->y + top;
  }
  focus(camera, camera->chaseMode);
}

WIP static void CameraMode3Callback(struct Camera* camera) {
#if MODERN
  s32 zx, zy, tmp;
  struct Coord c, d, target;
  if (camera->unk_1c == 0) {
    camera->unk_22 = 0;
    camera->unk_1c++;
  }
  zx = camera->zero->x + camera->unk_left;
  zy = camera->zero->y + camera->unk_top;

  c.x = (camera->target).x;
  c.y = (camera->target).y;

  tmp = c.x - zx;
  if (tmp > 0) {
    c.x -= tmp;
  }
  if (tmp < 0) {
    c.x -= tmp;
  }

  tmp = c.y - zy;
  if (tmp > -PIXEL(16)) {
    c.y -= (PIXEL(16) + tmp);
  }
  if (tmp < -PIXEL(24)) {
    c.y -= (PIXEL(24) + tmp);
  }

  CalcCameraDelta(&c, &d);
  if (camera->chaseMode & (1 << 4)) {
    target.x = c.x;
  } else {
    target.x = c.x + d.x;
  }
  if (camera->chaseMode & (1 << 5)) {
    target.y = c.y;
  } else {
    target.y = c.y + d.y;
  }

  if (camera->chaseMode & (1 << 3)) {
    camera->target.y = target.y;
    camera->target.x = target.x;
  } else {
    s32 x = (camera->target).x + PIXEL(4);
    if ((x < target.x) || (x = (camera->target).x - PIXEL(4), x > target.x)) {
      (camera->target).x = x;
    } else {
      (camera->target).x = target.x;
    }

    if ((camera->target).y >= target.y) {
      target.y = (camera->target).y * 7 + target.y;
    } else {
      target.y = (camera->target).y * 7 + target.y + 7;
    }
    (camera->target).y = (target.y >> 3);
  }
  focus(camera, camera->chaseMode);
#else
  INCCODE("asm/wip/CameraMode3Callback.inc");
#endif
}

NAKED static void CameraMode4Callback(struct Camera* camera) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #0x10\n\
	adds r7, r0, #0\n\
	ldrb r0, [r7, #0x1c]\n\
	adds r1, r0, #0\n\
	cmp r1, #0\n\
	bne _0801A9F4\n\
	strh r1, [r7, #0x22]\n\
	adds r0, #1\n\
	strb r0, [r7, #0x1c]\n\
_0801A9F4:\n\
	ldr r2, [r7, #0x48]\n\
	ldr r1, [r2]\n\
	ldr r0, [r7, #0x4c]\n\
	adds r5, r1, r0\n\
	ldr r1, [r2, #4]\n\
	ldr r0, [r7, #0x54]\n\
	adds r6, r1, r0\n\
	ldr r0, [r7, #0x30]\n\
	str r0, [sp]\n\
	ldr r1, [r7, #0x34]\n\
	str r1, [sp, #4]\n\
	subs r2, r0, r5\n\
	cmp r2, #0\n\
	ble _0801AA14\n\
	subs r0, r0, r2\n\
	str r0, [sp]\n\
_0801AA14:\n\
	cmp r2, #0\n\
	bge _0801AA1E\n\
	ldr r0, [sp]\n\
	subs r0, r0, r2\n\
	str r0, [sp]\n\
_0801AA1E:\n\
	subs r1, r1, r6\n\
	ldr r0, _0801AA58 @ =0xFFFFF000\n\
	cmp r1, r0\n\
	ble _0801AA30\n\
	ldr r0, [sp, #4]\n\
	ldr r2, _0801AA58 @ =0xFFFFF000\n\
	adds r0, r0, r2\n\
	subs r0, r0, r1\n\
	str r0, [sp, #4]\n\
_0801AA30:\n\
	ldr r0, _0801AA5C @ =0xFFFFE800\n\
	cmp r1, r0\n\
	bge _0801AA40\n\
	ldr r0, [sp, #4]\n\
	ldr r2, _0801AA5C @ =0xFFFFE800\n\
	adds r0, r0, r2\n\
	subs r0, r0, r1\n\
	str r0, [sp, #4]\n\
_0801AA40:\n\
	add r4, sp, #8\n\
	mov r0, sp\n\
	adds r1, r4, #0\n\
	bl CalcCameraDelta\n\
	ldrb r1, [r7, #0x19]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801AA60\n\
	ldr r5, [sp]\n\
	b _0801AA66\n\
	.align 2, 0\n\
_0801AA58: .4byte 0xFFFFF000\n\
_0801AA5C: .4byte 0xFFFFE800\n\
_0801AA60:\n\
	ldr r1, [sp]\n\
	ldr r0, [sp, #8]\n\
	adds r5, r1, r0\n\
_0801AA66:\n\
	ldr r0, [sp, #4]\n\
	ldr r1, [r4, #4]\n\
	adds r6, r0, r1\n\
	ldr r1, _0801AABC @ =0xFFFF8800\n\
	adds r0, r5, r1\n\
	ldr r1, [r7, #0x5c]\n\
	cmp r0, r1\n\
	bge _0801AA7C\n\
	movs r2, #0xf0\n\
	lsls r2, r2, #7\n\
	adds r5, r1, r2\n\
_0801AA7C:\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #7\n\
	adds r0, r5, r1\n\
	ldr r1, [r7, #0x60]\n\
	cmp r0, r1\n\
	ble _0801AA8C\n\
	ldr r2, _0801AABC @ =0xFFFF8800\n\
	adds r5, r1, r2\n\
_0801AA8C:\n\
	ldr r1, _0801AAC0 @ =0xFFFFB000\n\
	adds r0, r6, r1\n\
	ldr r1, [r7, #0x64]\n\
	cmp r0, r1\n\
	bge _0801AA9C\n\
	movs r2, #0xa0\n\
	lsls r2, r2, #7\n\
	adds r6, r1, r2\n\
_0801AA9C:\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #7\n\
	adds r0, r6, r1\n\
	ldr r1, [r7, #0x68]\n\
	cmp r0, r1\n\
	ble _0801AAAC\n\
	ldr r2, _0801AAC0 @ =0xFFFFB000\n\
	adds r6, r1, r2\n\
_0801AAAC:\n\
	ldrb r1, [r7, #0x19]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801AAC4\n\
	str r6, [r7, #0x34]\n\
	str r5, [r7, #0x30]\n\
	b _0801AAFE\n\
	.align 2, 0\n\
_0801AABC: .4byte 0xFFFF8800\n\
_0801AAC0: .4byte 0xFFFFB000\n\
_0801AAC4:\n\
	ldr r1, [r7, #0x30]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #3\n\
	adds r0, r1, r2\n\
	cmp r0, r5\n\
	blt _0801AAD8\n\
	ldr r2, _0801AADC @ =0xFFFFFC00\n\
	adds r0, r1, r2\n\
	cmp r0, r5\n\
	ble _0801AAE0\n\
_0801AAD8:\n\
	str r0, [r7, #0x30]\n\
	b _0801AAE2\n\
	.align 2, 0\n\
_0801AADC: .4byte 0xFFFFFC00\n\
_0801AAE0:\n\
	str r5, [r7, #0x30]\n\
_0801AAE2:\n\
	ldr r1, [r7, #0x34]\n\
	subs r0, r1, r6\n\
	cmp r0, #0\n\
	blt _0801AAF2\n\
	lsls r0, r1, #3\n\
	subs r0, r0, r1\n\
	adds r0, r0, r6\n\
	b _0801AAFA\n\
_0801AAF2:\n\
	lsls r0, r1, #3\n\
	subs r0, r0, r1\n\
	adds r0, r0, r6\n\
	adds r0, #7\n\
_0801AAFA:\n\
	asrs r0, r0, #3\n\
	str r0, [r7, #0x34]\n\
_0801AAFE:\n\
	ldrb r1, [r7, #0x19]\n\
	adds r0, r7, #0\n\
	bl focus\n\
	add sp, #0x10\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.syntax divided\n");
}

static void CameraMode7Callback(struct Camera* _) { return; }
