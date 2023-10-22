#include "collision.h"
#include "global.h"
#include "projectile.h"

void Projectile42_Init(struct Projectile* p);
void Projectile42_Update(struct Projectile* p);
void Projectile42_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile42Routine = {
    [ENTITY_INIT] =      Projectile42_Init,
    [ENTITY_UPDATE] =    Projectile42_Update,
    [ENTITY_DIE] =       Projectile42_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

// ./tools/dumper/bin.ts baserom.gba 0x0836d710 0x0836d900 data/projectile2.bin
INCBIN("data/projectile2.bin");
