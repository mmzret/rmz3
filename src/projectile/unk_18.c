#include "collision.h"
#include "global.h"
#include "projectile.h"

static const struct Collision sCollisions[4];
static const u8 sInitModes[4];

void Projectile18_Init(struct Projectile* p);
void Projectile18_Update(struct Projectile* p);
void Projectile18_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile18Routine = {
    [ENTITY_INIT] =      Projectile18_Init,
    [ENTITY_UPDATE] =    Projectile18_Update,
    [ENTITY_DIE] =       Projectile18_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080a3090(struct Projectile* p);
void FUN_080a308c(struct Projectile* p);

// clang-format off
static const ProjectileFunc PTR_ARRAY_0836b434[5] = {
    FUN_080a3090,
    FUN_080a3090,
    FUN_080a3090,
    FUN_080a308c,
    FUN_080a308c,
};
// clang-format on

void FUN_080a3094(struct Projectile* p);
void FUN_080a31c0(struct Projectile* p);
void FUN_080a3298(struct Projectile* p);
void FUN_080a3418(struct Projectile* p);
void FUN_080a34a0(struct Projectile* p);

// clang-format off
static const ProjectileFunc PTR_ARRAY_0836b448[5] = {
    FUN_080a3094,
    FUN_080a31c0,
    FUN_080a3298,
    FUN_080a3418,
    FUN_080a34a0,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[4] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(5), -PIXEL(8), PIXEL(8), PIXEL(21)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(6), -PIXEL(3), PIXEL(8), PIXEL(9)},
    },
};

static const u8 sInitModes[4] = {0, 3, 4, 0};
