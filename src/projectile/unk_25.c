#include "collision.h"
#include "global.h"
#include "projectile.h"

void Projectile25_Init(struct Projectile* p);
void Projectile25_Update(struct Projectile* p);
void Projectile25_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile25Routine = {
    [ENTITY_INIT] =      Projectile25_Init,
    [ENTITY_UPDATE] =    Projectile25_Update,
    [ENTITY_DIE] =       Projectile25_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080a84c4(struct Projectile* p);
void FUN_080a85a0(struct Projectile* p);
void FUN_080a8684(struct Projectile* p);
void FUN_080a8794(struct Projectile* p);

static const ProjectileFunc PTR_ARRAY_0836bf68[4] = {
    FUN_080a84c4,
    FUN_080a85a0,
    FUN_080a8684,
    FUN_080a8794,
};

// --------------------------------------------

static const struct Collision sCollisions[6] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(8)},
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
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 6,
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
};
