#include "collision.h"
#include "global.h"
#include "projectile.h"

void Projectile34_Init(struct Projectile* p);
void Projectile34_Update(struct Projectile* p);
void Projectile34_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile34Routine = {
    [ENTITY_INIT] =      Projectile34_Init,
    [ENTITY_UPDATE] =    Projectile34_Update,
    [ENTITY_DIE] =       Projectile34_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080acb54(struct Projectile* p);
void FUN_080acbe0(struct Projectile* p);
void FUN_080accf0(struct Projectile* p);
void FUN_080acea0(struct Projectile* p);

static const ProjectileFunc sUpdates[4] = {
    FUN_080acb54,
    FUN_080acbe0,
    FUN_080accf0,
    FUN_080acea0,
};

// --------------------------------------------

static const struct Collision sCollisions[5] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 5,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(48), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 5,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(48)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      nature : 0x80,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(2), PIXEL(26), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(2), PIXEL(26), PIXEL(20)},
    },
};

static const s32 s32_ARRAY_0836c7a0[32] = {
    0x00000180, -0x00000340, -0x00000220, -0x00000260, -0x00000220, -0x00000300, 0x000002C0, -0x00000260, -0x00000180, -0x00000340, -0x00000200, -0x00000280, 0x00000160, -0x000001F0, 0x00000260, -0x00000280, 0x00000200, -0x00000440, 0x00000120, -0x000002A0, 0x00000120, -0x00000340, -0x000000B0, -0x000002A0, -0x00000200, -0x00000440, 0x00000120, -0x000002A0, 0x00000120, -0x00000340, -0x000000B0, -0x000002A0,
};

static const s32* const PTR_ARRAY_0836c820[4] = {
    &s32_ARRAY_0836c7a0[0],
    &s32_ARRAY_0836c7a0[8],
    &s32_ARRAY_0836c7a0[16],
    &s32_ARRAY_0836c7a0[24],
};
