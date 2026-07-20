#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "story.h"

static void Projectile16_Init(Object* p);
static void Projectile16_Update(Object* p);
static void Projectile16_Die(Object* p);

// clang-format off
const ProjectileRoutine gProjectile16Routine = {
    [ENTITY_INIT] =      (void*)Projectile16_Init,
    [ENTITY_UPDATE] =    (void*)Projectile16_Update,
    [ENTITY_DIE] =       (void*)Projectile16_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* FUN_080a244c(Coords32* c1, Coords32* c2, bool8 isDirRight) {
  struct Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 16);
    p->work[0] = isDirRight;
    (p->coord).x = c1->x, (p->coord).y = c1->y;
    (p->unk_coord).x = c2->x, (p->unk_coord).y = c2->y;
  }
  return p;
}

// --------------------------------------------

static const struct Collision sCollisions[];

static void Projectile16_Init(Object* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  INIT_BODY(p, &sCollisions[0], 2, NULL);
  if (p->work[0] == 0) {
    SET_XFLIP(p, FALSE);
  } else {
    SET_XFLIP(p, TRUE);
  }
  p->work[2] = 0xFF;
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 0, p->mode[2] = 0, p->mode[3] = 0;
  Projectile16_Update((void*)p);
}

void FUN_080a25f8(struct Projectile* p);
void FUN_080a2710(struct Projectile* p);

static void Projectile16_Update(Object* p) {
  // 0x0836b350
  static const ProjectileFunc sUpdates[2] = {
      (void*)FUN_080a25f8,
      (void*)FUN_080a2710,
  };

  if (IS_METTAUR) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  (sUpdates[p->mode[1]])((void*)p);
}

static void Projectile16_Die(Object* p) {
  p->flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

INCASM("asm/projectile/unk_16.inc");

// --------------------------------------------

// 0x0836B358
static const struct Collision sCollisions[3] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(12), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(12), PIXEL(12)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(8), PIXEL(24), PIXEL(24)},
    },
};
