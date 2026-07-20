#include "collision.h"
#include "global.h"
#include "projectile.h"

// for Volteel Biblio's thunder

static const struct Collision sCollisions[4];

static void Projectile12_Init(struct Projectile* p);
static void Projectile12_Update(struct Projectile* p);
static void Projectile12_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile12Routine = {
    [ENTITY_INIT] =      (void*)Projectile12_Init,
    [ENTITY_UPDATE] =    (void*)Projectile12_Update,
    [ENTITY_DIE] =       (void*)Projectile12_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

struct Entity* FUN_0809f48c(struct Entity* q, Coords32* c) {
  struct Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 12);
    p->work[0] = 0;
    p->coord = *c;
    p->unk_28 = q;
  }
  return p;
}

struct Projectile* FUN_0809f4dc(struct Entity* e, Coords32* c, Coords32* d, u8 n) {
  struct Projectile* p = (struct Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 12);
    (p->s).work[0] = 1;
    (p->s).d = *d;
    (p->s).coord = *c;
    (p->s).unk_28 = e;
    p->buffer[0] = n;
  }
  return p;
}

// --------------------------------------------

static void Projectile12_Init(struct Projectile* p) {
  EnableSpriteAnimation_Affine(p);
  (p->s).angle = 0;
  (p->s).spr.mag.x = 0x100;
  (p->s).spr.mag.y = 0x100;
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteTableDynamic(p);
  if ((p->s).work[0] == 0) {
    INIT_BODY(p, &sCollisions[0], 1, NULL);
  } else if ((p->s).work[0] == 1) {
    INIT_BODY(p, &sCollisions[1], 1, NULL);
  }
  (p->s).work[2] = 0xFF;
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = 1, (p->s).mode[2] = 0, (p->s).mode[3] = 0;
  Projectile12_Update(p);
}

// --------------------------------------------

static void FUN_0809f640(struct Projectile* p);
void FUN_0809f64c(struct Projectile* p);

void FUN_0809f7c8(struct Projectile* p);
void FUN_0809f7d4(struct Projectile* p);

static void Projectile12_Update(struct Projectile* p) {
  static const ProjectileFunc sUpdates1[2] = {
      FUN_0809f640,
      FUN_0809f64c,
  };
  static const ProjectileFunc sUpdates2[2] = {
      FUN_0809f7c8,
      FUN_0809f7d4,
  };
  static const ProjectileFunc* const sUpdates[2] = {
      sUpdates1,
      sUpdates2,
  };
  ((sUpdates[(p->s).work[0]])[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void Projectile12_Die(struct Projectile* p) {
  (p->s).flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void FUN_0809f640(struct Projectile* p) {
  (p->s).mode[1] = 1;
  (p->s).mode[2] = 0;
}

INCASM("asm/projectile/unk_12.inc");

// --------------------------------------------

static const struct Collision sCollisions[4] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      element : ELEMENT_THUNDER,
      nature : BODY_NATURE_B7,
      remaining : 0,
      layer : 0x00000002,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      element : ELEMENT_THUNDER,
      nature : BODY_NATURE_B7,
      remaining : 2,
      layer : 0x00000002,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(10)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      element : ELEMENT_THUNDER,
      nature : BODY_NATURE_B7,
      remaining : 1,
      layer : 0x00000002,
      range : {PIXEL(10), PIXEL(0), PIXEL(10), PIXEL(10)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      element : ELEMENT_THUNDER,
      nature : BODY_NATURE_B7,
      remaining : 0,
      layer : 0x00000002,
      range : {PIXEL(20), PIXEL(0), PIXEL(10), PIXEL(10)},
    },
};
