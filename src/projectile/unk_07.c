#include "collision.h"
#include "global.h"
#include "projectile.h"

INCASM("asm/projectile/projectile.inc");

void Projectile7_Init(struct Projectile* p);
void Projectile7_Update(struct Projectile* p);
void Projectile7_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile7Routine = {
    [ENTITY_INIT] =      Projectile7_Init,
    [ENTITY_UPDATE] =    Projectile7_Update,
    [ENTITY_DIE] =       Projectile7_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

static const struct Collision sCollision[2] = {
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x2000, 0x2000},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 3,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      range : {0x0000, 0x0000, 0x2000, 0x2000},
    },
};
