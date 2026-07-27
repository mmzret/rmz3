#include "collision.h"
#include "global.h"
#include "projectile.h"

static const ProjectileFunc PTR_ARRAY_0836d794[1];
static const ProjectileFunc PTR_ARRAY_0836d798[1];

INCASM("asm/projectile/unk_44_a.inc");

void FUN_080b1764(Projectile* p) {
  (PTR_ARRAY_0836d794[p->mode[1]])((void*)p);
  (PTR_ARRAY_0836d798[p->mode[1]])((void*)p);
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

// two adjacent 1-entry tables: FUN_080b1764 loads each base from its own
// literal pool slot, which a single [2] array cannot reproduce
// clang-format off
static const ProjectileFunc PTR_ARRAY_0836d794[1] = {
    FUN_080b17d8,
};
static const ProjectileFunc PTR_ARRAY_0836d798[1] = {
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
