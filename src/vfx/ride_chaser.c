#include "global.h"
#include "vfx.h"

static void RideChaser_Init(struct VFX* vfx);
static void RideChaser_Update(struct VFX* vfx);
static void RideChaser_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gRideChaserRoutine = {
    [ENTITY_INIT] =      RideChaser_Init,
    [ENTITY_MAIN] =      RideChaser_Update,
    [ENTITY_DIE] =       RideChaser_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct VFX* CreateRideChaser(struct Zero* z) {
  struct VFX* vfx = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
  if (vfx != NULL) {
    (vfx->s).taskCol = 1;
    INIT_VFX_ROUTINE(vfx, VFX_RIDE_CHASER);
    (vfx->s).tileNum = 0;
    (vfx->s).palID = 6;
    (vfx->s).unk_28 = &z->s;
    (vfx->s).coord.x = (z->s).coord.x - PIXEL(72);
    (vfx->s).coord.y = (z->s).coord.y - PIXEL(40);
  }

  return vfx;
}

static void RideChaser_Init(struct VFX* vfx) {
  InitNonAffineMotion(&vfx->s);
  ResetDynamicMotion(&vfx->s);
  (vfx->s).flags |= DISPLAY;
  (vfx->s).flags |= FLIPABLE;
  SetMotion(&vfx->s, MOTION(DM200_RIDE_CHASER, 0));
  UpdateMotionGraphic(&vfx->s);
  SET_VFX_ROUTINE(vfx, ENTITY_MAIN);
  RideChaser_Update(vfx);
}

static void RideChaser_Update(struct VFX* vfx) {
  struct Zero* z = (struct Zero*)(vfx->s).unk_28;
  (vfx->s).coord.x = (z->s).coord.x - PIXEL(72);
  (vfx->s).coord.y = (z->s).coord.y - PIXEL(40);
}

static void RideChaser_Die(struct VFX* vfx) {
  (vfx->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(vfx, ENTITY_EXIT);
}
