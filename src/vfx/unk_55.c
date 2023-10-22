#include "global.h"
#include "vfx.h"

static void VFX55_Init(struct VFX* vfx);
static void VFX55_Update(struct VFX* vfx);
static void VFX55_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX55Routine = {
    [ENTITY_INIT] =      VFX55_Init,
    [ENTITY_UPDATE] =    VFX55_Update,
    [ENTITY_DIE] =       VFX55_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct VFX* CreateVFX55(struct Boss* p, u8 r1, u8 r2) {
  struct VFX* vfx = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
  if (vfx != NULL) {
    (vfx->s).taskCol = 1;
    INIT_VFX_ROUTINE(vfx, VFX_UNK_055);
    (vfx->s).tileNum = 0;
    (vfx->s).palID = 0;
    (vfx->s).unk_28 = &p->s;
    (vfx->s).work[0] = r1;
    (vfx->s).work[1] = r2;
  }
  return vfx;
}

// --------------------------------------------

static void FUN_080c11e0(struct VFX* vfx);
void FUN_080c123c(struct VFX* vfx);
void FUN_080c12b0(struct VFX* vfx);

static void VFX55_Init(struct VFX* vfx) {
  static const VFXFunc sInitializers[3] = {
      FUN_080c11e0,
      FUN_080c123c,
      FUN_080c12b0,
  };

  SET_VFX_ROUTINE(vfx, ENTITY_UPDATE);
  InitNonAffineMotion(&vfx->s);
  (vfx->s).flags |= DISPLAY;
  (vfx->s).flags |= FLIPABLE;
  (sInitializers[(vfx->s).work[0]])(vfx);
  VFX55_Update(vfx);
}

// --------------------------------------------

void FUN_080c1328(struct VFX* vfx);
void FUN_080c13c8(struct VFX* vfx);
void FUN_080c143c(struct VFX* vfx);

static void VFX55_Update(struct VFX* vfx) {
  static const VFXFunc sUpdates[3] = {
      FUN_080c1328,
      FUN_080c13c8,
      FUN_080c143c,
  };
  (sUpdates[(vfx->s).work[0]])(vfx);
}

// --------------------------------------------

static void VFX55_Die(struct VFX* vfx) {
  (vfx->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(vfx, ENTITY_EXIT);
}

// --------------------------------------------

static void FUN_080c11e0(struct VFX* vfx) {
  struct Boss* copyx;
#if MODERN
  bool8 xflip;
#else
  register bool8 xflip asm("r2");
#endif

  copyx = (struct Boss*)(vfx->s).unk_28;
  (vfx->s).flags &= ~DISPLAY;
  SetMotion(&vfx->s, MOTION(SM097_COPYX_UNK, 2));
  UpdateMotionGraphic(&vfx->s);

  xflip = FALSE;
  (vfx->s).flags &= ~X_FLIP;
  (vfx->s).spr.xflip = xflip;
  (vfx->s).spr.oam.xflip = xflip;
  (vfx->s).spr.oam.priority = 3;
  (vfx->s).coord = (copyx->s).coord;
  (vfx->s).work[2] = 42;
}

INCASM("asm/vfx/unk_55.inc");
