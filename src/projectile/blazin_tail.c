#include "collision.h"
#include "global.h"
#include "projectile.h"

void BlazinTail_Init(struct Projectile* p);
void BlazinTail_Update(struct Projectile* p);
void BlazinTail_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gBlazinTailRoutine = {
    [ENTITY_INIT] =      BlazinTail_Init,
    [ENTITY_MAIN] =      BlazinTail_Update,
    [ENTITY_DIE] =       BlazinTail_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_0809f140(struct Projectile* p);

static const ProjectileFunc sUpdates[1] = {
    FUN_0809f140,
};

// --------------------------------------------

static const struct Collision sCollisions[2] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x07,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {0x1600, -0x1200, 0x1600, 0x1000},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x07,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x1600, -0x1200, 0x1600, 0x1000},
    },
};
