#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "vfx.h"

static const struct Collision sCollisions[4];
static const u8 u8_ARRAY_0836bec4[2];

// LocomoIF
static void Projectile23_Init(Projectile* p);
static void Projectile23_Update(Projectile* p);
static void Projectile23_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile23Routine = {
    [ENTITY_INIT] =      (void*)Projectile23_Init,
    [ENTITY_UPDATE] =    (void*)Projectile23_Update,
    [ENTITY_DIE] =       (void*)Projectile23_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void FUN_080a7c60(s32 x, s32 y, u8 a2) {
  Entity* p = AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 23);
    p->work[0] = 0;
    (p->coord).x = x, (p->coord).y = y;
    p->work[2] = a2;
  }
}

void FUN_080a7cb0(s32 x, s32 y, u8 a2) {
  Entity* p = AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 23);
    p->work[0] = 1;
    (p->coord).x = x, (p->coord).y = y;
    p->work[2] = a2;
  }
}

static void Projectile23_OnCollision(struct Body* body, Coords32* c1, Coords32* c2) {}

static void Projectile23_Init(Projectile* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = u8_ARRAY_0836bec4[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  INIT_BODY(p, sCollisions, 1, Projectile23_OnCollision);
  Projectile23_Update(p);
}

static void FUN_080a7dec(Projectile* p);
static void FUN_080a7de8(Projectile* p);
void FUN_080a7e0c(Projectile* p);

void FUN_080a7e9c(Projectile* p);
void FUN_080a7f70(Projectile* p);
void FUN_080a8080(Projectile* p);

static void Projectile23_Update(Projectile* p) {
  static const ProjectileFunc sUpdates1[3] = {
      FUN_080a7dec,
      FUN_080a7de8,
      FUN_080a7e0c,
  };
  static const ProjectileFunc sUpdates2[3] = {
      FUN_080a7e9c,
      FUN_080a7f70,
      FUN_080a8080,
  };
  (sUpdates1[p->mode[1]])(p);
  (sUpdates2[p->mode[1]])(p);
}

static void Projectile23_Die(Projectile* p) {
  EXIT_BODY(p);
  CreateSmoke(3, &p->coord);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

static void FUN_080a7de8(Projectile* p) {}

static void FUN_080a7dec(Projectile* p) {
  if ((p->body).status & BODY_STATUS_BINDING) {
    p->mode[1] = 2, p->mode[2] = 0;
  }
}

INCASM("asm/projectile/locomo_if_a.inc");

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
