#include "collision.h"
#include "global.h"
#include "projectile.h"

static void FUN_080b22c8(Projectile* p);
static void FUN_080b22e0(Projectile* p);
static void FUN_080b22f8(Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile46Routine = {
    [ENTITY_INIT] =      (void*)FUN_080b22c8,
    [ENTITY_UPDATE] =    (void*)FUN_080b22e0,
    [ENTITY_DIE] =       (void*)FUN_080b22f8,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// 0x080B221C
Entity* FUN_080b221c(void* g, u8 kind1, u8 kind2) {
  Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 46);
    p->unk_28 = g;
    p->work[0] = kind1, p->work[1] = kind2;
  }
  return p;
}

// 0x080B2270
Entity* FUN_080b2270(void* g, Entity* q, u8 kind1, u8 kind2) {
  Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 46);
    p->unk_28 = g;
    p->unk_2c = q;
    p->work[0] = kind1, p->work[1] = kind2;
  }
  return p;
}

// --------------------------------------------

static void FUN_080b2310(Projectile* p);
void FUN_080b2384(Projectile* p);
void FUN_080b2428(Projectile* p);

static void FUN_080b22c8(Projectile* p) {
  static const ProjectileFunc sInitializers[3] = {
      FUN_080b2310,
      FUN_080b2384,
      FUN_080b2428,
  };  // 0x0836d8b0
  (sInitializers[p->work[0]])(p);
}

void FUN_080b24c8(Projectile* p);
void FUN_080b258c(Projectile* p);
void FUN_080b2654(Projectile* p);

static void FUN_080b22e0(Projectile* p) {
  static const ProjectileFunc sUpdates[3] = {
      FUN_080b24c8,
      FUN_080b258c,
      FUN_080b2654,
  };  // 0x0836d8bc
  (sUpdates[p->work[0]])(p);
}

void FUN_080b274c(Projectile* p);
void FUN_080b2764(Projectile* p);
void FUN_080b277c(Projectile* p);

static void FUN_080b22f8(Projectile* p) {
  static const ProjectileFunc PTR_ARRAY_0836d8c8[3] = {
      FUN_080b274c,
      FUN_080b2764,
      FUN_080b277c,
  };  // 0x0836d8c8
  (PTR_ARRAY_0836d8c8[p->work[0]])(p);
}

// --------------------------------------------

static void FUN_080b2310(Projectile* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM234_UNK, 0));
  UpdateSpriteAnimation(p);
  SET_XFLIP(p, FALSE);
  (p->coord).x = PIXEL((p->work[1] * 32) + 24);
  (p->coord).y = PIXEL(0);
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  FUN_080b22e0(p);
}

INCASM("asm/projectile/unk_46.inc");
