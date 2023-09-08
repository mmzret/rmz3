#include "collision.h"
#include "global.h"
#include "projectile.h"

void Projectile15_Init(struct Projectile* p);
void Projectile15_Update(struct Projectile* p);
void Projectile15_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gHellbatProjectileRoutine = {
    [ENTITY_INIT] =      Projectile15_Init,
    [ENTITY_MAIN] =      Projectile15_Update,
    [ENTITY_DIE] =       Projectile15_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

void FUN_080a176c(struct Projectile* p);
void FUN_080a1778(struct Projectile* p);

static const ProjectileFunc sUpdates1[2] = {
    FUN_080a176c,
    FUN_080a1778,
};

void FUN_080a1a10(struct Projectile* p);
void FUN_080a1a1c(struct Projectile* p);

static const ProjectileFunc sUpdates2[2] = {
    FUN_080a1a10,
    FUN_080a1a1c,
};

void FUN_080a1f10(struct Projectile* p);
void FUN_080a1f1c(struct Projectile* p);

static const ProjectileFunc sUpdates3[2] = {
    FUN_080a1f10,
    FUN_080a1f1c,
};

void FUN_080a2020(struct Projectile* p);
void FUN_080a202c(struct Projectile* p);

static const ProjectileFunc sUpdates4[2] = {
    FUN_080a2020,
    FUN_080a202c,
};

void FUN_080a22ec(struct Projectile* p);
void FUN_080a22f8(struct Projectile* p);

static const ProjectileFunc sUpdates5[2] = {
    FUN_080a22ec,
    FUN_080a22f8,
};

// clang-format off
static const ProjectileFunc*const sUpdates[5] = {
    sUpdates1,
    sUpdates2,
    sUpdates3,
    sUpdates4,
    sUpdates5,
};
// clang-format on

static const struct Collision sCollisions[9] = {
    {
      kind : DRP,
      layer : LAYER_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(2), PIXEL(20), PIXEL(18)},
    },
    {
      kind : DDP,
      layer : LAYER_ENEMY,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(2), PIXEL(20), PIXEL(18)},
    },
    {
      kind : DDP,
      layer : LAYER_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x01,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000002,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      layer : LAYER_ENEMY,
      special : 2,
      damage : 5,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(11), PIXEL(30)},
    },
    {
      kind : DDP,
      layer : LAYER_ENEMY,
      special : 2,
      damage : 5,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DDP,
      layer : LAYER_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(20)},
    },
    {
      kind : DDP,
      layer : LAYER_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(10)},
    },
    {
      kind : DDP,
      layer : LAYER_UNK2,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(20)},
    },
    {
      kind : DDP,
      layer : LAYER_UNK2,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(10)},
    },
};
