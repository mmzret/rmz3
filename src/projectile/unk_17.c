#include "collision.h"
#include "global.h"
#include "projectile.h"

void Projectile17_Init(struct Projectile* p);
void Projectile17_Update(struct Projectile* p);
void Projectile17_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile17Routine = {
    [ENTITY_INIT] =      Projectile17_Init,
    [ENTITY_UPDATE] =    Projectile17_Update,
    [ENTITY_DIE] =       Projectile17_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

void FUN_080a2adc(struct Projectile* p);
void FUN_080a2d9c(struct Projectile* p);
void FUN_080a2dec(struct Projectile* p);

static const ProjectileFunc PTR_ARRAY_0836b3b4[3] = {
    FUN_080a2adc,
    FUN_080a2d9c,
    FUN_080a2dec,
};

static const struct Collision sCollisions[] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(10)},
    },
};
