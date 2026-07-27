#include "collision.h"
#include "global.h"
#include "projectile.h"

INCASM("asm/projectile/unk_44_a.inc");

void FUN_080b17d8(Projectile* p) {
}

INCASM("asm/projectile/unk_44_b.inc");

void FUN_080b16f4(Projectile* p);
void FUN_080b1764(Projectile* p);
void FUN_080b1798(Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile44Routine = {
    [ENTITY_INIT] =      (void*)FUN_080b16f4,
    [ENTITY_UPDATE] =    (void*)FUN_080b1764,
    [ENTITY_DIE] =       (void*)FUN_080b1798,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void FUN_080b17d8(Projectile* p);
void FUN_080b17dc(Projectile* p);

// clang-format off
static const ProjectileFunc PTR_ARRAY_0836d794[2] = {
    FUN_080b17d8,
    FUN_080b17dc,
};
// clang-format on

static const struct Collision Collision_0836d79c = {
  kind : DDP,
  faction : FACTION_ENEMY,
  damage : 4,
  remaining : 0,
  layer : 0x00000001,
  range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(13)},
};

static const u8 u8_ARRAY_0836d7b4[4] = {0, 0, 0, 0};
