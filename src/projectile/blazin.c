#include "collision.h"
#include "global.h"
#include "projectile.h"

// Blazin tail?

static const struct Collision sCollisions[14];

void Projectile9_Init(struct Projectile* p);
void Projectile9_Update(struct Projectile* p);
void Projectile9_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gBlazinProjectileRoutine = {
    [ENTITY_INIT] =      Projectile9_Init,
    [ENTITY_UPDATE] =    Projectile9_Update,
    [ENTITY_DIE] =       Projectile9_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_0809e7b4(struct Projectile* p);
void FUN_0809e7c0(struct Projectile* p);
void FUN_0809e9b8(struct Projectile* p);
void FUN_0809e9c4(struct Projectile* p);
void FUN_0809eadc(struct Projectile* p);
void FUN_0809eae8(struct Projectile* p);
void FUN_0809ec18(struct Projectile* p);
void FUN_0809ec24(struct Projectile* p);
void FUN_0809edfc(struct Projectile* p);
void FUN_0809ee08(struct Projectile* p);

// clang-format off
static const ProjectileFunc PTR_ARRAY_ARRAY_0836ad24[5][2] = {
    {FUN_0809e7b4, FUN_0809e7c0},
    {FUN_0809e9b8, FUN_0809e9c4},
    {FUN_0809eadc, FUN_0809eae8},
    {FUN_0809ec18, FUN_0809ec24},
    {FUN_0809edfc, FUN_0809ee08},
};
// clang-format on

// clang-format off
static const ProjectileFunc* const PTR_ARRAY_0836ad4c[5] = {
    PTR_ARRAY_ARRAY_0836ad24[0],
    PTR_ARRAY_ARRAY_0836ad24[1],
    PTR_ARRAY_ARRAY_0836ad24[2],
    PTR_ARRAY_ARRAY_0836ad24[3],
    PTR_ARRAY_ARRAY_0836ad24[4],
};
// clang-format on

static const struct Collision sCollisions[14] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {0x0100, -0x0400, 0x1A00, 0x0E00},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 1,
      range : {0x0100, -0x0400, 0x1A00, 0x0E00},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      comboLv : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0100, -0x0400, 0x1A00, 0x0E00},
    },
    [3] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      element : ELEMENT_FLAME,
      comboLv : 0x00,
      remaining : 0,
      layer : 0x00000004,
      range : {0x0000, 0x0000, 0x0A00, 0x0A00},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      element : ELEMENT_FLAME,
      comboLv : 0x00,
      remaining : 0,
      layer : 0x00000004,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      element : ELEMENT_FLAME,
      comboLv : 0x00,
      remaining : 0,
      layer : 0x00000004,
      range : {0x0000, -0x0700, 0x0A00, 0x1700},
    },
    [6] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      element : ELEMENT_FLAME,
      comboLv : 0,
      remaining : 2,
      layer : 0x00000004,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [7] = {
      kind : DRP2,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 1,
      layer : 0xFFFFFFFF,
      range : {0x0000, 0x0000, 0x0C00, 0x0C00},
    },
    [8] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0C00, 0x0C00},
    },
    [9] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      element : ELEMENT_FLAME,
      comboLv : 0,
      remaining : 2,
      layer : 0x00000004,
      range : {0x0000, 0x0000, 0x1100, 0x1100},
    },
    [10] = {
      kind : DRP2,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 1,
      layer : 0xFFFFFFFF,
      range : {0x0000, 0x0000, 0x1600, 0x1600},
    },
    [11] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      range : {0x0000, 0x0000, 0x1600, 0x1600},
    },
    [12] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 1,
      layer : 0xFFFFFFFF,
      range : {0x0000, 0x0000, 0x1A00, 0x1400},
    },
    [13] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1A00, 0x1400},
    },
};
