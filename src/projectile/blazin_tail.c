#include "collision.h"
#include "global.h"
#include "projectile.h"

void BlazinTail_Init(struct Projectile* p);
void BlazinTail_Update(struct Projectile* p);
void BlazinTail_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gBlazinTailRoutine = {
    [ENTITY_INIT] =      BlazinTail_Init,
    [ENTITY_UPDATE] =    BlazinTail_Update,
    [ENTITY_DIE] =       BlazinTail_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_0809f140(struct Projectile* p);

static const ProjectileFunc sUpdates[1] = {
    FUN_0809f140,
};

// --------------------------------------------

static const struct Collision sCollisions[2] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 7,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {0x1600, -0x1200, 0x1600, 0x1000},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x07,
      remaining : 0,
      range : {0x1600, -0x1200, 0x1600, 0x1000},
    },
};
