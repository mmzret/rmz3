#include "collision.h"
#include "global.h"
#include "projectile.h"

INCASM("asm/projectile/projectile2.inc");

void FUN_080aedf0(struct Projectile* p);
void FUN_080aee54(struct Projectile* p);
void FUN_080aeec0(struct Projectile* p);

// clang-format off
const ProjectileRoutine gClavekerYellowBallsRoutine = {
    [ENTITY_INIT] =      FUN_080aedf0,
    [ENTITY_UPDATE] =    FUN_080aee54,
    [ENTITY_DIE] =       FUN_080aeec0,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

void FUN_080aeefc(struct Projectile* p);

static const ProjectileFunc sUpdates[1] = {
    FUN_080aeefc,
};

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      atkType : 0x00,
      nature : BODY_NATURE_B7,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
};
