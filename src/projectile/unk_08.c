#include "collision.h"
#include "global.h"
#include "projectile.h"

void Projectile8_Init(struct Projectile* p);
void Projectile8_Update(struct Projectile* p);
void Projectile8_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile8Routine = {
    [ENTITY_INIT] =      Projectile8_Init,
    [ENTITY_UPDATE] =    Projectile8_Update,
    [ENTITY_DIE] =       Projectile8_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

static const struct Collision sCollision[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, -0x0C00, 0x1A00, 0x1C00},
    },
};
