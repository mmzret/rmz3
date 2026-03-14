#include "collision.h"
#include "global.h"
#include "projectile.h"

void Projectile37_Init(struct Projectile* p);
void Projectile37_Update(struct Projectile* p);
void Projectile37_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile37Routine = {
    [ENTITY_INIT] =      Projectile37_Init,
    [ENTITY_UPDATE] =    Projectile37_Update,
    [ENTITY_DIE] =       Projectile37_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080adc84(struct Projectile* p);
void FUN_080ae140(struct Projectile* p);

static const ProjectileFunc sUpdates[2] = {
    FUN_080adc84,
    FUN_080ae140,
};

// --------------------------------------------

static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(7), PIXEL(22), PIXEL(19)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      nature : 0x80,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(10)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(10)},
    },
};
