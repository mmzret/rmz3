#include "collision.h"
#include "global.h"
#include "projectile.h"

void TretistaProjectile_Init(struct Projectile* p);
void TretistaProjectile_Update(struct Projectile* p);
void TretistaProjectile_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gTretistaProjectileRoutine = {
    [ENTITY_INIT] =      TretistaProjectile_Init,
    [ENTITY_UPDATE] =    TretistaProjectile_Update,
    [ENTITY_DIE] =       TretistaProjectile_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

// ./tools/dumper/bin.ts baserom.gba 0x0836b4d4 0x0836c974 data/projectile.bin
INCBIN("data/projectile.bin");
