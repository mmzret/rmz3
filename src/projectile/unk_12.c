#include "collision.h"
#include "global.h"
#include "projectile.h"

void Projectile12_Init(struct Projectile* p);
void Projectile12_Update(struct Projectile* p);
void Projectile12_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile12Routine = {
    [ENTITY_INIT] =      Projectile12_Init,
    [ENTITY_UPDATE] =    Projectile12_Update,
    [ENTITY_DIE] =       Projectile12_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_0809f640(struct Projectile* p);
void FUN_0809f64c(struct Projectile* p);

static const ProjectileFunc sUpdates1[2] = {
    FUN_0809f640,
    FUN_0809f64c,
};

// --------------------------------------------

void FUN_0809f7c8(struct Projectile* p);
void FUN_0809f7d4(struct Projectile* p);

static const ProjectileFunc sUpdates2[2] = {
    FUN_0809f7c8,
    FUN_0809f7d4,
};

// --------------------------------------------

static const ProjectileFunc* const sUpdates[2] = {
    sUpdates1,
    sUpdates2,
};

// --------------------------------------------

static const struct Collision sCollisions[4] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      atkType : 0x00,
      element : ELEMENT_THUNDER,
      nature : BODY_NATURE_B7,
      comboLv : 0,
      remaining : 0,
      layer : 0x00000002,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      atkType : 0x00,
      element : ELEMENT_THUNDER,
      nature : BODY_NATURE_B7,
      comboLv : 0,
      remaining : 2,
      layer : 0x00000002,
      range : {0x0000, 0x0000, 0x0A00, 0x0A00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      atkType : 0x00,
      element : ELEMENT_THUNDER,
      nature : BODY_NATURE_B7,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000002,
      range : {0x0A00, 0x0000, 0x0A00, 0x0A00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      atkType : 0x00,
      element : ELEMENT_THUNDER,
      nature : BODY_NATURE_B7,
      comboLv : 0,
      remaining : 0,
      layer : 0x00000002,
      range : {0x1400, 0x0000, 0x0A00, 0x0A00},
    },
};
