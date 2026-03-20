#include "collision.h"
#include "global.h"
#include "projectile.h"

// for Volteel Biblio's thunder

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

struct Projectile* FUN_0809f48c(struct Entity* e, struct Coord* c) {
  struct Projectile* p = (struct Projectile*)AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 8;
    INIT_PROJECTILE_ROUTINE(p, 12);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).work[0] = 0;
    (p->s).coord = *c;
    (p->s).unk_28 = e;
  }
  return p;
}

struct Projectile* FUN_0809f4dc(struct Entity* e, struct Coord* c, struct Coord* d, u8 n) {
  struct Projectile* p = (struct Projectile*)AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 8;
    INIT_PROJECTILE_ROUTINE(p, 12);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).work[0] = 1;
    (p->s).d = *d;
    (p->s).coord = *c;
    (p->s).unk_28 = e;
    p->work[0] = n;
  }
  return p;
}

// --------------------------------------------

INCASM("asm/projectile/projectile.inc");

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
