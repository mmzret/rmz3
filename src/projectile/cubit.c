#include "collision.h"
#include "global.h"
#include "projectile.h"

void CubitProjectile_Init(struct Projectile* p);
void CubitProjectile_Update(struct Projectile* p);
void CubitProjectile_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gCubitProjectileRoutine = {
    [ENTITY_INIT] =      CubitProjectile_Init,
    [ENTITY_UPDATE] =    CubitProjectile_Update,
    [ENTITY_DIE] =       CubitProjectile_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

// ./tools/dumper/bin.ts baserom.gba 0x0836bb74 0x0836c974 data/projectile.bin
INCBIN("data/projectile.bin");
