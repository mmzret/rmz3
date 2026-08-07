#include "global.h"
#include "palette_animation.h"
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

void FUN_080c123c(struct VFX* p) {
  struct Entity* q = (p->s).unk_28;
  s32 t;
  s16 v;
  SetMotion(&p->s, MOTION(0x61, 0x00));
  UpdateEntityAnim(&p->s);
  t = (q->flags >> 4) & 1;
  if (t) {
    (p->s).flags |= X_FLIP;
  } else {
    (p->s).flags &= ~X_FLIP;
  }
  v = t;
  (p->s).spr.xflip = v;
  (p->s).spr.oam.xflip = v;
  *((u8*)&(p->s).spr.oam + 5) |= 0xC;
  {
    s32 x = q->coord.x;
    s32 y = q->coord.y;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
  }
  StartPaletteAnimation(0x61, 0x300);
  (p->s).work[2] = 0;
}

void FUN_080c12b0(struct VFX* p) {
  struct Entity* q = (p->s).unk_28;
  s32 t;
  s16 v;
  SetMotion(&p->s, MOTION(0x61, 0x01));
  UpdateEntityAnim(&p->s);
  t = (q->flags >> 4) & 1;
  if (t) {
    (p->s).flags |= X_FLIP;
  } else {
    (p->s).flags &= ~X_FLIP;
  }
  v = t;
  (p->s).spr.xflip = v;
  (p->s).spr.oam.xflip = v;
  *((u8*)&(p->s).spr.oam + 5) |= 0xC;
  {
    s32 x = q->coord.x;
    s32 y = q->coord.y;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
  }
  StartPaletteAnimation(0x61, 0x300);
  (p->s).work[2] = 0;
}

void FUN_080c1328(struct VFX* p) {
  if ((p->s).mode[2] == 0) {
    if ((u8)--(p->s).work[2] == 0xFF) {
      (p->s).flags |= DISPLAY;
      UpdateEntityAnim(&p->s);
      StartPaletteAnimation(0x65, 0x280);
      StartPaletteAnimation(0x60, 0x300);
      StepPaletteAnimation(0x65);
      StepPaletteAnimation(0x60);
      PlaySound(0x11A);
      (p->s).mode[2]++;
    }
  } else {
    UpdateEntityAnim(&p->s);
    StepPaletteAnimation(0x65);
    StepPaletteAnimation(0x60);
    if ((p->s).motion.state == 3) {
      RemovePaletteAnimation(0x65);
      RemovePaletteAnimation(0x60);
      SET_VFX_ROUTINE(p, ENTITY_DIE);
      VFX55_Die((struct Entity*)p);
    }
  }
}

void FUN_080c13c8(struct VFX* p) {
  struct Entity* q = (p->s).unk_28;
  UpdateEntityAnim(&p->s);
  StepPaletteAnimation(0x61);
  {
    s32 w = (p->s).work[2] + 1;
    (p->s).work[2] = w;
    if (w & 1) {
      (p->s).flags |= DISPLAY;
    } else {
      (p->s).flags &= ~DISPLAY;
    }
  }
  if ((p->s).motion.state == 3 ||
      ((q->motionID << 8) | q->motion.id) != MOTION(0xb3, 0x1b)) {
    RemovePaletteAnimation(0x61);
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    VFX55_Die((struct Entity*)p);
  }
}

void FUN_080c143c(struct VFX* p) {
  struct Entity* q = (p->s).unk_28;
  s32 one;
  UpdateEntityAnim(&p->s);
  StepPaletteAnimation(0x61);
  {
    s32 xf = (q->flags >> 4) & 1;
    s32 v;
    if (xf != 0) {
      (p->s).flags |= X_FLIP;
    } else {
      (p->s).flags &= 0xEF;
    }
    one = 1;
    v = one & xf;
    ((p->s).spr).xflip = v;
    {
      register u8* oa asm("ip");
      u8* oa0;
      u32 k;
      s32 sh4, ov, m11;
      k = 0x4a;
      asm("" : "+r"(k));
      oa0 = (u8*)(k + (u32)p);
      asm volatile("mov %0, %1" : "=r"(oa) : "r"(oa0));
      sh4 = v << 4;
      ov = *oa0;
      m11 = -0x11;
      m11 &= ov;
      m11 |= sh4;
      *oa = m11;
    }
  }
  (p->s).coord = q->coord;
  {
    s32 w = (p->s).work[2] + 1;
    (p->s).work[2] = w;
    if ((w & one) != 0) {
      (p->s).flags |= DISPLAY;
    } else {
      (p->s).flags &= 0xFE;
    }
  }
  if ((p->s).motion.state == 3 || (((u16)q->motionID << 8) | q->motion.id) != 0xB31C) {
    RemovePaletteAnimation(0x61);
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    VFX55_Die((struct Entity*)p);
  }
}
