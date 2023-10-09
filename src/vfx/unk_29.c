#include "global.h"
#include "solid.h"
#include "vfx.h"

s16 FUN_080cb528(struct CollidableEntity *p);

static void Ghost29_Init(struct VFX *vfx);
static void Ghost29_Update(struct VFX *vfx);
static void Ghost29_Die(struct VFX *vfx);

// clang-format off
const VFXRoutine gGhost29Routine = {
    [ENTITY_INIT] =      Ghost29_Init,
    [ENTITY_UPDATE] =    Ghost29_Update,
    [ENTITY_DIE] =       Ghost29_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

static void Ghost29_Init(struct VFX *vfx) {
  (vfx->s).flags |= FLIPABLE;
  FUN_080cb4c0((struct Solid *)vfx);
  SET_VFX_ROUTINE(vfx, ENTITY_UPDATE);
  Ghost29_Update(vfx);
}

static void Ghost29_Update(struct VFX *vfx) {
  s16 ok = FUN_080cb528((struct CollidableEntity *)vfx);
  if (!ok) {
    (vfx->s).flags &= ~DISPLAY;
    (vfx->s).flags &= ~FLIPABLE;
    SET_VFX_ROUTINE(vfx, ENTITY_DISAPPEAR);
  }
}

static void Ghost29_Die(struct VFX *vfx) {
  // nop
}
