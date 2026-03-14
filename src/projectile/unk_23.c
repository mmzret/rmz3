#include "collision.h"
#include "global.h"
#include "projectile.h"

void Projectile23_Init(struct Projectile* p);
void Projectile23_Update(struct Projectile* p);
void Projectile23_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile23Routine = {
    [ENTITY_INIT] =      Projectile23_Init,
    [ENTITY_UPDATE] =    Projectile23_Update,
    [ENTITY_DIE] =       Projectile23_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080a7dec(struct Projectile* p);
void FUN_080a7de8(struct Projectile* p);
void FUN_080a7e0c(struct Projectile* p);

static const ProjectileFunc sUpdates1[] = {
    FUN_080a7dec,
    FUN_080a7de8,
    FUN_080a7e0c,
};

void FUN_080a7e9c(struct Projectile* p);
void FUN_080a7f70(struct Projectile* p);
void FUN_080a8080(struct Projectile* p);

static const ProjectileFunc sUpdates2[] = {
    FUN_080a7e9c,
    FUN_080a7f70,
    FUN_080a8080,
};

// --------------------------------------------

static const struct Collision sCollisions[4] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      unk_0a : 0x41,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(2), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(6), PIXEL(17), PIXEL(21)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      unk_0a : 0x41,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(64), PIXEL(64)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(2), PIXEL(16), PIXEL(16)},
    },
};

static const u8 u8_ARRAY_0836bec4[2] = {0, 1};

static const motion_t sMotions[4] = {
    MOTION(SM088_LOCOMO_IF_ICE, 1),
    MOTION(SM088_LOCOMO_IF_ICE, 2),
    MOTION(SM088_LOCOMO_IF_ICE, 3),
    MOTION(SM088_LOCOMO_IF_ICE, 4),
};
