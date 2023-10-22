#include "collision.h"
#include "global.h"
#include "projectile.h"

void Projectile16_Init(struct Projectile* p);
void Projectile16_Update(struct Projectile* p);
void Projectile16_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile16Routine = {
    [ENTITY_INIT] =      Projectile16_Init,
    [ENTITY_UPDATE] =    Projectile16_Update,
    [ENTITY_DIE] =       Projectile16_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

void FUN_080a25f8(struct Projectile* p);
void FUN_080a2710(struct Projectile* p);

static const ProjectileFunc PTR_ARRAY_0836b350[2] = {
    FUN_080a25f8,
    FUN_080a2710,
};

static const struct Collision sCollisions[3] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(12), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(12), PIXEL(12)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(8), PIXEL(24), PIXEL(24)},
    },
};
