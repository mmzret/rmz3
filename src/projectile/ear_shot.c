#include "collision.h"
#include "global.h"
#include "projectile.h"

void EarShot_Init(struct Projectile* p);
void EarShot_Update(struct Projectile* p);
void EarShot_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gEarShotRoutine = {
    [ENTITY_INIT] =      EarShot_Init,
    [ENTITY_MAIN] =      EarShot_Update,
    [ENTITY_DIE] =       EarShot_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

void nop_0809f3d0(struct Projectile* p);

static const ProjectileFunc sUpdates1[1] = {
    nop_0809f3d0,
};

void FUN_0809f3d4(struct Projectile* p);

static const ProjectileFunc sUpdates2[1] = {
    FUN_0809f3d4,
};

static const struct Collision sCollisions[4] = {
    {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 4,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {0x1200, 0x0000, 0x2600, 0x0C00},
    },
    {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 5,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {0x2400, 0x0000, 0x4200, 0x0C00},
    },
    {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 5,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {0x3E00, -0x0B00, 0x2400, 0x0A00},
    },
    {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 5,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {0x3E00, 0x0B00, 0x2400, 0x0A00},
    },
};

static const u8 sInitModes[4] = {0, 0, 0, 0};