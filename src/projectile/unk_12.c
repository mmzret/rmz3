#include "collision.h"
#include "global.h"
#include "projectile.h"

// for Volteel Biblio's thunder
typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 unk_b4;             // 0xB4
  u8 unk_b5[15];         // 0xB5
} Projectile12;
static_assert(sizeof(Projectile12) == sizeof(Projectile));

static const struct Collision sCollisions[4];

static void Projectile12_Init(Projectile12* p);
static void Projectile12_Update(Projectile12* p);
static void Projectile12_Die(Projectile12* p);

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

Entity* FUN_0809f48c(struct Entity* q, Coords32* c) {
  Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 12);
    p->work[0] = 0;
    p->coord = *c;
    p->unk_28 = q;
  }
  return p;
}

Projectile* FUN_0809f4dc(struct Entity* e, Coords32* c, Coords32* d, u8 n) {
  Projectile12* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 12);
    p->work[0] = 1;
    p->d = *d;
    p->coord = *c;
    p->unk_28 = e;
    p->unk_b4 = n;
  }
  return (void*)p;
}

// --------------------------------------------

static void Projectile12_Init(Projectile12* p) {
  EnableSpriteAnimation_Affine(p);
  p->angle = 0, (p->spr).mag.x = 0x100, (p->spr).mag.y = 0x100;
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteTableDynamic(p);
  if (p->work[0] == 0) {
    INIT_BODY(p, &sCollisions[0], 1, NULL);
  } else if (p->work[0] == 1) {
    INIT_BODY(p, &sCollisions[1], 1, NULL);
  }
  p->work[2] = 0xFF;
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 1, p->mode[2] = 0, p->mode[3] = 0;
  Projectile12_Update(p);
}

static void FUN_0809f640(Projectile12* p);
void FUN_0809f64c(Projectile12* p);

void FUN_0809f7c8(Projectile12* p);
void FUN_0809f7d4(Projectile12* p);

typedef void (*Projectile12Func)(Projectile12*);

static void Projectile12_Update(Projectile12* p) {
  static const Projectile12Func sUpdates1[2] = {
      FUN_0809f640,
      FUN_0809f64c,
  };
  static const Projectile12Func sUpdates2[2] = {
      FUN_0809f7c8,
      FUN_0809f7d4,
  };
  static const Projectile12Func* const sUpdates[2] = {
      sUpdates1,
      sUpdates2,
  };
  ((sUpdates[p->work[0]])[p->mode[1]])(p);
}

// --------------------------------------------

static void Projectile12_Die(Projectile12* p) {
  p->flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void FUN_0809f640(Projectile12* p) {
  p->mode[1] = 1;
  p->mode[2] = 0;
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
