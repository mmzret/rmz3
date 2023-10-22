#include "collision.h"
#include "global.h"
#include "projectile.h"

void Projectile20_Init(struct Projectile* p);
void Projectile20_Update(struct Projectile* p);
void Projectile20_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile20Routine = {
    [ENTITY_INIT] =      Projectile20_Init,
    [ENTITY_UPDATE] =    Projectile20_Update,
    [ENTITY_DIE] =       Projectile20_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

void FUN_080a5144(struct Projectile* p);

// clang-format off
static const ProjectileFunc PTR_ARRAY_0836ba50[10] = {
    FUN_080a5144,
    FUN_080a5144,
    FUN_080a5144,
    FUN_080a5144,
    FUN_080a5144,
    FUN_080a5144,
    FUN_080a5144,
    FUN_080a5144,
    FUN_080a5144,
    FUN_080a5144,
};
// clang-format on

void FUN_080a5148(struct Projectile* p);
void FUN_080a51b4(struct Projectile* p);
void FUN_080a5290(struct Projectile* p);
void FUN_080a53e8(struct Projectile* p);
void FUN_080a54f8(struct Projectile* p);
void FUN_080a569c(struct Projectile* p);
void FUN_080a57ac(struct Projectile* p);
void FUN_080a598c(struct Projectile* p);
void FUN_080a5ac0(struct Projectile* p);
void FUN_080a5b28(struct Projectile* p);

// clang-format off
static const ProjectileFunc PTR_ARRAY_0836ba78[10] = {
    FUN_080a5148,
    FUN_080a51b4,
    FUN_080a5290,
    FUN_080a53e8,
    FUN_080a54f8,
    FUN_080a569c,
    FUN_080a57ac,
    FUN_080a598c,
    FUN_080a5ac0,
    FUN_080a5b28,
};
// clang-format on

static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      nature : BODY_NATURE_B2,
      remaining : 0,
      layer : 1,
      range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      nature : BODY_NATURE_B2,
      remaining : 0,
      layer : 1,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(46)},
    },
};

static const u8 sInitModes[4] = {0, 0, 0, 0};
