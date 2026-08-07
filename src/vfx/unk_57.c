#include "global.h"
#include "vfx.h"

// 砕け散る氷(大きめ)

static void VFX57_Init(struct Entity* p);
static void VFX57_Update(struct Entity* p);
static void VFX57_Die(struct Entity* p);

// clang-format off
const VFXRoutine gVFX57Routine = {
    [ENTITY_INIT] =      (void*)VFX57_Init,
    [ENTITY_UPDATE] =    (void*)VFX57_Update,
    [ENTITY_DIE] =       (void*)VFX57_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void CreateVFX57(Coords32* c, u8 kind1, u8 kind2, s16 dx, s16 dy) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_057);
    p->work[0] = kind1, p->work[1] = kind2;
    (p->d).x = dx, (p->d).y = dy;
    p->coord = *c;
  }
}

// --------------------------------------------

void FUN_080c19b4(struct Entity* p);
void FUN_080c1a3c(struct Entity* p);

static void VFX57_Init(struct Entity* p) {
  if (p->work[0] == 0) {
    FUN_080c19b4(p);
  } else {
    FUN_080c1a3c(p);
  }
}

void FUN_080c1aec(struct Entity* p);
void FUN_080c1b34(struct Entity* p);

static void VFX57_Update(struct Entity* p) {
  if (p->work[0] == 0) {
    FUN_080c1aec(p);
  } else {
    FUN_080c1b34(p);
  }
}

static void VFX57_Die(struct Entity* p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }

void FUN_080c19b4(struct Entity* p) {
  s32 xf;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  InitNonAffineMotion((struct Entity*)p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetMotion((struct Entity*)p, p->work[1] | MOTION(0x63, 0x00));
  xf = 0;
  if (p->d.x > 0) {
    xf = 1;
  }
  SET_XFLIP(p, xf);
  VFX57_Update(p);
}

void FUN_080c1a3c(struct Entity* p) {
  register s32 v asm("r2");
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  InitNonAffineMotion((struct Entity*)p);
  {
    register u8 fv asm("r0");
    register s32 z asm("r5");
    u8 t = p->flags;
    fv = DISPLAY;
    z = 0;
    asm volatile("" ::"r"(z));
    fv |= t;
    fv |= FLIPABLE;
    p->flags = fv;
  }
  SetMotion((struct Entity*)p, MOTION(0x62, 0x03) + p->work[1]);
  if (p->work[1] != 1) {
    register s32 t asm("r1");
    t = 0;
    if (p->d.x > 0) {
      t = 1;
    }
    v = t;
    if (v != 0) {
      p->flags |= X_FLIP;
    } else {
      p->flags &= ~X_FLIP;
    }
  } else {
    register s32 t asm("r1");
    t = 0;
    if (p->d.x <= 0) {
      t = 1;
    }
    v = t;
    if (v != 0) {
      p->flags |= X_FLIP;
    } else {
      p->flags &= ~X_FLIP;
    }
  }
  {
    register s32 xf asm("r1");
    u8* oa;
    s32 sh4, ov, m11;
    xf = v;
    p->spr.xflip = xf;
    oa = (u8*)p + 0x4a;
    sh4 = xf << 4;
    ov = *oa;
    m11 = -0x11;
    m11 &= ov;
    m11 |= sh4;
    *oa = m11;
    {
      s32 wz = 0;
      asm("" : "+r"(wz) : "r"(oa));
      p->work[2] = wz;
    }
  }
  PlaySound(0x3f);
  VFX57_Update(p);
}

void FUN_080c1aec(struct Entity* p) {
  UpdateEntityAnim((struct Entity*)p);
  p->coord.x += p->d.x;
  p->coord.y += p->d.y;
  if (p->motion.state == ANIM_NEXT_GOTO) {
    p->flags &= ~DISPLAY;
    SET_VFX_ROUTINE(p, ENTITY_DIE);
  }
}

void FUN_080c1b34(struct Entity* p) {
  UpdateEntityAnim((struct Entity*)p);
  p->coord.x += p->d.x;
  p->coord.y += p->d.y;
  p->d.y += 0x40;
  if (p->work[2]++ & 1) {
    p->flags &= ~DISPLAY;
  } else {
    p->flags |= DISPLAY;
  }
  if (FUN_080098a4(p->coord.x, p->coord.y)) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
  }
}
