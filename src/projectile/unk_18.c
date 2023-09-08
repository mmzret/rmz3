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
    [ENTITY_MAIN] =      Projectile18_Update,
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
      layer : LAYER_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 0,
      hardness : 8,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      layer : LAYER_ENEMY,
      special : 0,
      damage : 255,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      layer : LAYER_ENEMY,
      special : 0,
      damage : 255,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {PIXEL(5), -PIXEL(8), PIXEL(8), PIXEL(21)},
    },
    {
      kind : DDP,
      layer : LAYER_ENEMY,
      special : 0,
      damage : 255,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {PIXEL(6), -PIXEL(3), PIXEL(8), PIXEL(9)},
    },
};

static const u8 sInitModes[4] = {0, 3, 4, 0};
