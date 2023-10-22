#include "collision.h"
#include "global.h"
#include "projectile.h"

void PantheonAquaModProjectile_Init(struct Projectile* p);
void PantheonAquaModProjectile_Update(struct Projectile* p);
void PantheonAquaModProjectile_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gPantheonAquaModProjectileRoutine = {
    [ENTITY_INIT] =      PantheonAquaModProjectile_Init,
    [ENTITY_UPDATE] =    PantheonAquaModProjectile_Update,
    [ENTITY_DIE] =       PantheonAquaModProjectile_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

void FUN_080a5cf8(struct Projectile* p);

static const ProjectileFunc PTR_ARRAY_0836bb00[3] = {
    FUN_080a5cf8,
    FUN_080a5cf8,
    FUN_080a5cf8,
};

void FUN_080a5cfc(struct Projectile* p);
void FUN_080a5e00(struct Projectile* p);
void FUN_080a5e64(struct Projectile* p);

static const ProjectileFunc PTR_ARRAY_0836bb0c[3] = {
    FUN_080a5cfc,
    FUN_080a5e00,
    FUN_080a5e64,
};

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 1,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 1,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(24)},
    },
};

static const u8 sInitModes[2] = {0, 0};

// clang-format off
static const motion_t sMotions[10] = {
    MOTION(SM078_PANTHEON_AQUA_MOD_PROJECTILE, 4),
    MOTION(SM078_PANTHEON_AQUA_MOD_PROJECTILE, 6),
    MOTION(SM078_PANTHEON_AQUA_MOD_PROJECTILE, 8),
    MOTION(SM078_PANTHEON_AQUA_MOD_PROJECTILE, 6),
    MOTION(SM078_PANTHEON_AQUA_MOD_PROJECTILE, 4),
    MOTION(SM078_PANTHEON_AQUA_MOD_PROJECTILE, 5),
    MOTION(SM078_PANTHEON_AQUA_MOD_PROJECTILE, 7),
    MOTION(SM078_PANTHEON_AQUA_MOD_PROJECTILE, 9),
    MOTION(SM078_PANTHEON_AQUA_MOD_PROJECTILE, 7),
    MOTION(SM078_PANTHEON_AQUA_MOD_PROJECTILE, 5),
};
// clang-format on
