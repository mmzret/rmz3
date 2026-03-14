#include "collision.h"
#include "global.h"
#include "projectile.h"

void CopyXProjectile_Init(struct Projectile* p);
void CopyXProjectile_Update(struct Projectile* p);
void CopyXProjectile_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gCopyXProjectileRoutine = {
    [ENTITY_INIT] =      CopyXProjectile_Init,
    [ENTITY_UPDATE] =    CopyXProjectile_Update,
    [ENTITY_DIE] =       CopyXProjectile_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void initCopyXSlidingSonicBoom(struct Projectile* p);
void FUN_080a82dc(struct Projectile* p);

static const ProjectileFunc sInitializers[] = {
    initCopyXSlidingSonicBoom,
    FUN_080a82dc,
};

// --------------------------------------------

void moveSlidingSonicBoom(struct Projectile* p);
void moveNovaStrikeSonicBoom(struct Projectile* p);

static const ProjectileFunc sUpdates[] = {
    moveSlidingSonicBoom,
    moveNovaStrikeSonicBoom,
};

// --------------------------------------------

static const struct Collision sCollisions[4] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      nature : 0x04,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(8), -PIXEL(8), PIXEL(24), PIXEL(16)},
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
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(12), PIXEL(0), PIXEL(24), PIXEL(32)},
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
