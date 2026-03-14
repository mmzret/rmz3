#include "collision.h"
#include "global.h"
#include "projectile.h"

void Projectile43_Init(struct Projectile* p);
void Projectile43_Update(struct Projectile* p);
void Projectile43_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile43Routine = {
    [ENTITY_INIT] =      Projectile43_Init,
    [ENTITY_UPDATE] =    Projectile43_Update,
    [ENTITY_DIE] =       Projectile43_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

void FUN_080b155c(struct Projectile* p);

// clang-format off
static const ProjectileFunc PTR_ARRAY_0836d748[1] = {
    FUN_080b155c,
};
// clang-format on

static const struct Collision sCollision[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(12), PIXEL(10)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 4,
      LAYER(0xFFFFFFFF),
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(8)},
    },
};

static const u8 u8_ARRAY_0836d77c[4] = {0, 0, 0, 0};

// --------------------------------------------

void FUN_080b16f4(struct Projectile* p);
void FUN_080b1764(struct Projectile* p);
void FUN_080b1798(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile44Routine = {
    [ENTITY_INIT] =      FUN_080b16f4,
    [ENTITY_UPDATE] =    FUN_080b1764,
    [ENTITY_DIE] =       FUN_080b1798,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

void FUN_080b17d8(struct Projectile* p);
void FUN_080b17dc(struct Projectile* p);

// clang-format off
static const ProjectileFunc PTR_ARRAY_0836d794[2] = {
    FUN_080b17d8,
    FUN_080b17dc,
};
// clang-format on

static const struct Collision Collision_0836d79c = {
  kind : DDP,
  faction : FACTION_ENEMY,
  damage : 4,
  remaining : 0,
  layer : 0x00000001,
  range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(13)},
};

static const u8 u8_ARRAY_0836d7b4[4] = {0, 0, 0, 0};

// --------------------------------------------

void FUN_080b1a48(struct Projectile* p);
void FUN_080b1b28(struct Projectile* p);
void FUN_080b1b40(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile45Routine = {
    [ENTITY_INIT] =      FUN_080b1a48,
    [ENTITY_UPDATE] =    FUN_080b1b28,
    [ENTITY_DIE] =       FUN_080b1b40,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

void FUN_080b1b7c(struct Projectile* p);
void FUN_080b1cbc(struct Projectile* p);
void FUN_080b1f00(struct Projectile* p);
void FUN_080b2044(struct Projectile* p);

// clang-format off
static const ProjectileFunc PTR_ARRAY_0836d7cc[4] = {
    FUN_080b1b7c,
    FUN_080b1cbc,
    FUN_080b1f00,
    FUN_080b2044,
};
// clang-format on

static const struct Collision Collision_ARRAY_0836d7dc[8] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      damage : 2,
      element : ELEMENT_FLAME,
      remaining : 0,
      layer : 0x00000004,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      damage : 2,
      element : ELEMENT_THUNDER,
      remaining : 0,
      layer : 0x00000002,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      damage : 2,
      element : ELEMENT_ICE,
      remaining : 0,
      layer : 0x00000008,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      layer : 0x000A5294,
      range : {PIXEL(8), PIXEL(8), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      layer : 0x0046318C,
      range : {PIXEL(8), PIXEL(8), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      layer : 0x004C6318,
      range : {PIXEL(8), PIXEL(8), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(28), PIXEL(44)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      damage : 255,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
};

// --------------------------------------------

void FUN_080b22c8(struct Projectile* p);
void FUN_080b22e0(struct Projectile* p);
void FUN_080b22f8(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile46Routine = {
    [ENTITY_INIT] =      FUN_080b22c8,
    [ENTITY_UPDATE] =    FUN_080b22e0,
    [ENTITY_DIE] =       FUN_080b22f8,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

void FUN_080b2310(struct Projectile* p);
void FUN_080b2384(struct Projectile* p);
void FUN_080b2428(struct Projectile* p);

// clang-format off
static const ProjectileFunc PTR_ARRAY_0836d8b0[3] = {
    FUN_080b2310,
    FUN_080b2384,
    FUN_080b2428,
};
// clang-format on

void FUN_080b24c8(struct Projectile* p);
void FUN_080b258c(struct Projectile* p);
void FUN_080b2654(struct Projectile* p);

// clang-format off
static const ProjectileFunc PTR_ARRAY_0836d8bc[3] = {
    FUN_080b24c8,
    FUN_080b258c,
    FUN_080b2654,
};
// clang-format on

void FUN_080b274c(struct Projectile* p);
void FUN_080b2764(struct Projectile* p);
void FUN_080b277c(struct Projectile* p);

// clang-format off
static const ProjectileFunc PTR_ARRAY_0836d8c8[3] = {
    FUN_080b274c,
    FUN_080b2764,
    FUN_080b277c,
};
// clang-format on

// --------------------------------------------

void FUN_080b27f8(struct Projectile* p);
void FUN_080b2884(struct Projectile* p);
void FUN_080b28f0(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile47Routine = {
    [ENTITY_INIT] =      FUN_080b27f8,
    [ENTITY_UPDATE] =    FUN_080b2884,
    [ENTITY_DIE] =       FUN_080b28f0,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

static const struct Collision Collision_0836d8e8 = {
  kind : DDP,
  faction : FACTION_NEUTRAL,
  damage : 4,
  nature : ELEMENT_ENCHANTABLE,
  remaining : 0,
  layer : 0x00000002,
  range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(8)},
};
