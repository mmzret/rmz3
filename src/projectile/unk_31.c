#include "collision.h"
#include "global.h"
#include "projectile.h"

void Projectile31_Init(struct Projectile* p);
void Projectile31_Update(struct Projectile* p);
void Projectile31_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile31Routine = {
    [ENTITY_INIT] =      Projectile31_Init,
    [ENTITY_UPDATE] =    Projectile31_Update,
    [ENTITY_DIE] =       Projectile31_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
};

// --------------------------------------------

static const s32 s32_ARRAY_0836c35c[4] = {PIXEL(8), PIXEL(8), PIXEL(32), PIXEL(32)};

static const s32 s32_ARRAY_0836c36c[8] = {
    0x140, 0x180, 0x200, 0x280, 0xA0, 0xC0, 0x100, 0x140,
};

static const s32 s32_ARRAY_0836c38c[8] = {
    -0x600, -0x500, -0x400, -0x300, -0xC00, -0xA00, -0x800, -0x600,
};
