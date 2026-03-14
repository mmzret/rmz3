#include "collision.h"
#include "global.h"
#include "projectile.h"

void Projectile28_Init(struct Projectile* p);
void Projectile28_Update(struct Projectile* p);
void Projectile28_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile28Routine = {
    [ENTITY_INIT] =      Projectile28_Init,
    [ENTITY_UPDATE] =    Projectile28_Update,
    [ENTITY_DIE] =       Projectile28_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080a9b90(struct Projectile* p);
void FUN_080a9d88(struct Projectile* p);
void FUN_080a9e74(struct Projectile* p);
void FUN_080aa08c(struct Projectile* p);

static const ProjectileFunc PTR_ARRAY_0836c20c[4] = {
    FUN_080a9b90,
    FUN_080a9d88,
    FUN_080a9e74,
    FUN_080aa08c,
};

// --------------------------------------------

void FUN_080a9c88(struct Projectile* p);
void FUN_080a9dcc(struct Projectile* p);
void FUN_080a9ef8(struct Projectile* p);
void FUN_080aa120(struct Projectile* p);

static const ProjectileFunc PTR_ARRAY_0836c21c[4] = {
    FUN_080a9c88,
    FUN_080a9dcc,
    FUN_080a9ef8,
    FUN_080aa120,
};

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
      nature : 0x04,
      hitzone : 1,
      hardness : METAL,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(127), PIXEL(64), -PIXEL(1)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 4,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(127), PIXEL(64), -PIXEL(1)},
    },
};
