#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "vfx.h"

static const struct Collision sCollisions[4];

void Projectile18_Init(Projectile* p);
void Projectile18_Update(Projectile* p);
void Projectile18_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile18Routine = {
    [ENTITY_INIT] =      (void*)Projectile18_Init,
    [ENTITY_UPDATE] =    (void*)Projectile18_Update,
    [ENTITY_DIE] =       (void*)Projectile18_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void FUN_080a2ea0(void) {
  s32 i;
  for (i = 0; i < 5; i++) {
    Projectile* p = AllocEntityFirst(gProjectileHeaderPtr);
    if (p != NULL) {
      INIT_PROJECTILE_ROUTINE(p, 18);
      p->work[0] = 2;
    }
  }
}

void FUN_080a2ee8(s32 x, s32 y) {
  Projectile* p = AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 18);
    p->work[0] = 1;
    (p->coord).x = x, (p->coord).y = y;
  }
}

void FUN_080a2f34(s32 x, s32 y) {
  s32 i;
  for (i = 0; i < 2; i++) {
    Projectile* p = AllocEntityFirst(gProjectileHeaderPtr);
    if (p != NULL) {
      INIT_PROJECTILE_ROUTINE(p, 18);
      p->work[0] = 0;
      (p->coord).x = x - PIXEL(28) + (PIXEL(56) * i);
      (p->coord).y = y + PIXEL(8);
      p->work[2] = i;
    }
  }
}

void Projectile18_OnCollision(struct Body* _, Coords32* c1, Coords32* c2) {}

static const u8 sProjectile18_InitModes[4];

void Projectile18_Init(Projectile* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sProjectile18_InitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  INIT_BODY(p, sCollisions, 1, Projectile18_OnCollision);
  Projectile18_Update(p);
}

void FUN_080a3090(Projectile* p);
void FUN_080a308c(Projectile* p);

void FUN_080a3094(Projectile* p);
void FUN_080a31c0(Projectile* p);
void FUN_080a3298(Projectile* p);
void FUN_080a3418(Projectile* p);
void FUN_080a34a0(Projectile* p);

void Projectile18_Update(Projectile* p) {
  // clang-format off
  static const ProjectileFunc PTR_ARRAY_0836b434[5] = {
      (void*)FUN_080a3090,
      (void*)FUN_080a3090,
      (void*)FUN_080a3090,
      (void*)FUN_080a308c,
      (void*)FUN_080a308c,
  };
  // clang-format on
  // clang-format off
  static const ProjectileFunc PTR_ARRAY_0836b448[5] = {
      (void*)FUN_080a3094,
      (void*)FUN_080a31c0,
      (void*)FUN_080a3298,
      (void*)FUN_080a3418,
      (void*)FUN_080a34a0,
  };
  // clang-format on
  (PTR_ARRAY_0836b434[p->mode[1]])((void*)p);
  (PTR_ARRAY_0836b448[p->mode[1]])((void*)p);
}

void Projectile18_Die(Projectile* p) {
  EXIT_BODY(p);
  CreateSmoke(3, &p->coord);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

void FUN_080a308c(Projectile* p) {}

void FUN_080a3090(Projectile* p) {}

INCASM("asm/projectile/unk_18_c.inc");

// --------------------------------------------

static const struct Collision sCollisions[4] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(5), -PIXEL(8), PIXEL(8), PIXEL(21)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(6), -PIXEL(3), PIXEL(8), PIXEL(9)},
    },
};

static const u8 sProjectile18_InitModes[4] = {0, 3, 4, 0};
