#include "global.h"
#include "vfx.h"

// コピーエックスが変身する際のエフェクト?

static void VFX55_Init(struct Entity* p);
static void VFX55_Update(struct Entity* p);
static void VFX55_Die(struct Entity* p);

// clang-format off
const VFXRoutine gVFX55Routine = {
    [ENTITY_INIT] =      (void*)VFX55_Init,
    [ENTITY_UPDATE] =    (void*)VFX55_Update,
    [ENTITY_DIE] =       (void*)VFX55_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* CreateVFX55(struct Boss* e, u8 r1, u8 r2) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_055);
    p->unk_28 = (void*)e;
    p->work[0] = r1, p->work[1] = r2;
  }
  return p;
}

// --------------------------------------------

static void FUN_080c11e0(struct Entity* p);
void FUN_080c123c(struct VFX* p);
void FUN_080c12b0(struct VFX* p);

static void VFX55_Init(struct Entity* p) {
  static const EntityFunc sInitializers[3] = {
      (void*)FUN_080c11e0,
      (void*)FUN_080c123c,
      (void*)FUN_080c12b0,
  };

  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  (sInitializers[p->work[0]])(p);
  VFX55_Update(p);
}

// --------------------------------------------

void FUN_080c1328(struct VFX* p);
void FUN_080c13c8(struct VFX* p);
void FUN_080c143c(struct VFX* p);

static void VFX55_Update(struct Entity* p) {
  static const EntityFunc sUpdates[3] = {
      (void*)FUN_080c1328,
      (void*)FUN_080c13c8,
      (void*)FUN_080c143c,
  };
  (sUpdates[p->work[0]])(p);
}

// --------------------------------------------

static void VFX55_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void FUN_080c11e0(struct Entity* p) {
  struct Entity* q = p->unk_28;
  p->flags &= ~DISPLAY;
  SetSpriteAnimation(p, MOTION(SM097_COPYX_UNK, 2));
  UpdateSpriteAnimation(p);
  SET_XFLIP(p, FALSE);
  p->spr.oam.priority = 3;
  p->coord = q->coord;
  p->work[2] = 42;
}

INCASM("asm/vfx/copy_x_55.inc");
