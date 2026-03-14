#include "collision.h"
#include "global.h"
#include "projectile.h"

void Projectile26_Init(struct Projectile* p);
void Projectile26_Update(struct Projectile* p);
void Projectile26_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile26Routine = {
    [ENTITY_INIT] =      Projectile26_Init,
    [ENTITY_UPDATE] =    Projectile26_Update,
    [ENTITY_DIE] =       Projectile26_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080a8a38(struct Projectile* p);
void FUN_080a8b50(struct Projectile* p);
void FUN_080a8c74(struct Projectile* p);
void FUN_080a8d70(struct Projectile* p);
void FUN_080a8e64(struct Projectile* p);

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

// --------------------------------------------

void FUN_080a8f14(struct Projectile* p);
void FUN_080a8fa8(struct Projectile* p);
void FUN_080a8ff0(struct Projectile* p);

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
