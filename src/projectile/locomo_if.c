#include "collision.h"
#include "global.h"
#include "projectile.h"

// LocomoIF

static const ProjectileFunc sUpdates1[];
static const ProjectileFunc sUpdates2[];
static const struct Collision sCollisions[4];
static const u8 u8_ARRAY_0836bec4[2];

void FUN_080a7c60(s32 x, s32 y, u8 a2) {
  struct Projectile* p = (struct Projectile*)AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 23);
    (p->s).work[0] = 0;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    (p->s).work[2] = a2;
  }
}

void FUN_080a7cb0(s32 x, s32 y, u8 a2) {
  struct Projectile* p = (struct Projectile*)AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 23);
    (p->s).work[0] = 1;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    (p->s).work[2] = a2;
  }
}

void FUN_080a7d00(struct Enemy* p) {}

void Projectile23_Init(struct Projectile* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = u8_ARRAY_0836bec4[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  INIT_BODY(p, sCollisions, 1, (void*)FUN_080a7d00);
  Projectile23_Update(p);
}

void Projectile23_Update(struct Projectile* p) {
  (sUpdates1[(p->s).mode[1]])(p);
  (sUpdates2[(p->s).mode[1]])(p);
}

void Projectile23_Die(struct Projectile* p) {
  EXIT_BODY(p);
  CreateSmoke(3, &(p->s).coord);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

void FUN_080a7de8(struct Projectile* p) {}


void FUN_080a7dec(struct Projectile* p) {
  if ((p->body).status & BODY_STATUS_BINDING) {
    (p->s).mode[1] = 2;
    (p->s).mode[2] = 0;
  }
}

INCASM("asm/projectile/locomo_if_a.inc");

void Projectile23_Init(struct Projectile* p);
void Projectile23_Update(struct Projectile* p);
void Projectile23_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile23Routine = {
    [ENTITY_INIT] =      Projectile23_Init,
    [ENTITY_UPDATE] =    Projectile23_Update,
    [ENTITY_DIE] =       Projectile23_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080a7dec(struct Projectile* p);
void FUN_080a7de8(struct Projectile* p);
void FUN_080a7e0c(struct Projectile* p);

static const ProjectileFunc sUpdates1[] = {
    FUN_080a7dec,
    FUN_080a7de8,
    FUN_080a7e0c,
};

void FUN_080a7e9c(struct Projectile* p);
void FUN_080a7f70(struct Projectile* p);
void FUN_080a8080(struct Projectile* p);

static const ProjectileFunc sUpdates2[] = {
    FUN_080a7e9c,
    FUN_080a7f70,
    FUN_080a8080,
};

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
