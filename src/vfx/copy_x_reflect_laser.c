#include "global.h"
#include "vfx.h"

// CopyX Reflect Laser Particle

static void VFX56_Init(struct Entity* p);
static void VFX56_Update(struct Entity* p);
static void VFX56_Die(struct Entity* p);

// clang-format off
const VFXRoutine gVFX56Routine = {
    [ENTITY_INIT] =      (void*)VFX56_Init,
    [ENTITY_UPDATE] =    (void*)VFX56_Update,
    [ENTITY_DIE] =       (void*)VFX56_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void CreateVFX56(struct Entity* e, u8 kind1, u8 kind2) {
  struct Entity* p = (struct Entity*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_COPYX_REFLECTLASER);
    p->unk_28 = (void*)e;
    p->work[0] = kind1, p->work[1] = kind2;
  }
}

// --------------------------------------------

void FUN_080c15d4(struct VFX* p);
void FUN_080c161c(struct VFX* p);
void FUN_080c16fc(struct VFX* p);

static void VFX56_Init(struct Entity* p) {
  static const EntityFunc sInitializers[3] = {
      (void*)FUN_080c15d4,
      (void*)FUN_080c161c,
      (void*)FUN_080c16fc,
  };  // 0x0836f22c

  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM096_COPYX_REFLECT_LASER, 1));
  (sInitializers[p->work[0]])((void*)p);
}

void FUN_080c17e8(struct VFX* p);
void FUN_080c182c(struct VFX* p);
void FUN_080c188c(struct VFX* p);

static void VFX56_Update(struct Entity* p) {
  static const EntityFunc sUpdates[3] = {
      (void*)FUN_080c17e8,
      (void*)FUN_080c182c,
      (void*)FUN_080c188c,
  };  // 0x0836f238
  (sUpdates[p->work[0]])((void*)p);
}

static void VFX56_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

void FUN_080c15d4(struct VFX* vfx0) {
  register struct VFX* vfx asm("ip");
  register u32 z asm("r2");
  register struct Entity* q asm("r3");
  vfx = vfx0;
  asm("" : "+r"(vfx));
  q = (vfx0->s).unk_28;
  z = 0;
  {
    u32 f = (vfx0->s).flags;
    u32 v = 0xEF;
    v &= f;
    (vfx->s).flags = v;
  }
  ((vfx->s).spr).xflip = z;
  {
    register u8* oa asm("r4");
    s32 m;
    s32 ov;
    oa = (u8*)vfx + 0x4a;
    ov = *oa;
    m = -0x11;
    m &= ov;
    *oa = m;
  }
  (vfx->s).renderPrio = 9;
  {
    s32 x = q->coord.x;
    s32 y = q->coord.y;
    {
      register struct VFX* w asm("r3");
      w = vfx;
      (w->s).coord.x = x;
      (w->s).coord.y = y;
      (w->s).work[2] = z;
    }
  }
  VFX56_Update(&vfx->s);
}

INCASM("asm/vfx/copy_x_reflect_laser_a.inc");
