#include "collision.h"
#include "global.h"
#include "projectile.h"

// CopyX (Fire Shot)

void Projectile26_Init(Projectile* p);
void Projectile26_Update(Projectile* p);
void Projectile26_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile26Routine = {
    [ENTITY_INIT] =      (void*)Projectile26_Init,
    [ENTITY_UPDATE] =    (void*)Projectile26_Update,
    [ENTITY_DIE] =       (void*)Projectile26_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void FUN_080a88a4(Entity* q, u8 param_2, u8 param_3) {
  Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 26);
    p->work[0] = param_2, p->work[1] = param_3;
    p->unk_28 = (void*)q;
    (p->coord) = q->coord;
  }
}

INCASM("asm/projectile/copy_x_shot_fire.inc");

void FUN_080a8a38(Projectile* p);
void FUN_080a8b50(Projectile* p);
void FUN_080a8c74(Projectile* p);
void FUN_080a8d70(Projectile* p);
void FUN_080a8e64(Projectile* p);

// clang-format off
static const ProjectileFunc PTR_ARRAY_0836c01c[6] = {
    FUN_080a8a38,
    FUN_080a8b50,
    FUN_080a8c74,
    FUN_080a8c74,
    FUN_080a8d70,
    FUN_080a8e64,
};
// clang-format on

void FUN_080a8f14(Projectile* p);
void FUN_080a8fa8(Projectile* p);
void FUN_080a8ff0(Projectile* p);

// clang-format off
static const ProjectileFunc PTR_ARRAY_0836c034[6] = {
    FUN_080a8f14,
    FUN_080a8f14,
    FUN_080a8f14,
    FUN_080a8f14,
    FUN_080a8fa8,
    FUN_080a8ff0,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[4] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
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
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
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
};

static const s16 s16_ARRAY_0836c0ac[8] = {
    -PIXEL(1), PIXEL(1), -PIXEL(2), PIXEL(2), -PIXEL(3), PIXEL(3), -PIXEL(4), PIXEL(4),
};
