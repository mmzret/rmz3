#include "collision.h"
#include "global.h"
#include "projectile.h"

// CopyX (Elec Shot + Ice Shot)

void CreateVFX53(Entity* e, u8 n);

static void Projectile27_Init(Projectile* p);
static void Projectile27_Update(Projectile* p);
static void Projectile27_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile27Routine = {
    [ENTITY_INIT] =      (void*)Projectile27_Init,
    [ENTITY_UPDATE] =    (void*)Projectile27_Update,
    [ENTITY_DIE] =       (void*)Projectile27_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void FUN_080a9048(Entity* e, u8 param_2, u8 param_3) {
  Projectile* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 27);
    p->work[0] = param_2, p->work[1] = param_3;
    p->unk_28 = (void*)e;
    (p->coord) = e->coord;
  }
}

void FUN_080a90a0(Entity* e, u8 param_2, u8 param_3) {
  Projectile* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 27);
    p->work[0] = param_2, p->work[1] = param_3;
    p->unk_28 = (void*)e;
    (p->coord) = e->coord;
  }
}

// --------------------------------------------

void FUN_080a9158(Projectile* p);
void FUN_080a9250(Projectile* p);
void FUN_080a946c(Projectile* p);
void FUN_080a9604(Projectile* p);
void FUN_080a96f8(Projectile* p);
void FUN_080a9920(Projectile* p);
void FUN_080a9a30(Projectile* p);

static void Projectile27_Init(Projectile* p) {
  // clang-format off
  static const ProjectileFunc sInitializers[7] = {
      (void*)FUN_080a9158,
      (void*)FUN_080a9250,
      (void*)FUN_080a946c,
      (void*)FUN_080a9604,
      (void*)FUN_080a96f8,
      (void*)FUN_080a9920,
      (void*)FUN_080a9a30,
  }; // 0x0836c0d0
  // clang-format on
  (sInitializers[p->work[0]])((void*)p);
}

void FUN_080a9358(Projectile* p);
void FUN_080a953c(Projectile* p);
void FUN_080a9810(Projectile* p);
void FUN_080a99d4(Projectile* p);
static void FUN_080a9a74(Projectile* p);

static void Projectile27_Update(Projectile* p) {
  // clang-format off
  static const ProjectileFunc sUpdates[7] = {
      (void*)FUN_080a9358,
      (void*)FUN_080a9358,
      (void*)FUN_080a953c,
      (void*)FUN_080a9810,
      (void*)FUN_080a9810,
      (void*)FUN_080a99d4,
      (void*)FUN_080a9a74,
  }; // 0x0836c0ec
  // clang-format on
  (sUpdates[p->work[0]])((void*)p);
}

static void Projectile27_Die(Projectile* p) {
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/projectile/copy_x_shot_elecice.inc");

static void FUN_080a9a74(Projectile* p) {
  UpdateSpriteAnimation(p);
  CreateVFX53((void*)p, p->work[1]);
  SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
}

// --------------------------------------------

// 0x0836C108
static const struct Collision sCollisions[10] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 4,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(8), -PIXEL(8), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 4,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(8), -PIXEL(8), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 4,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 4,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
};
