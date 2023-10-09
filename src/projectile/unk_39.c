#include "collision.h"
#include "entity.h"
#include "global.h"
#include "projectile.h"

INCASM("asm/projectile/projectile2.inc");

void FUN_080aedf0(struct Projectile* p);
void FUN_080aee54(struct Projectile* p);
void FUN_080aeec0(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile39Routine = {
    [ENTITY_INIT] =      FUN_080aedf0,
    [ENTITY_UPDATE] =    FUN_080aee54,
    [ENTITY_DIE] =       FUN_080aeec0,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

// ./tools/dumper/bin.ts baserom.gba 0x0836d2e0 0x0836d900 data/projectile2.bin
INCBIN("data/projectile2.bin");
