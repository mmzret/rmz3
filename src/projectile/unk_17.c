#include "collision.h"
#include "global.h"
#include "projectile.h"

void Projectile17_Init(Projectile* p);
void Projectile17_Update(Projectile* p);
void Projectile17_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile17Routine = {
    [ENTITY_INIT] =      (void*)Projectile17_Init,
    [ENTITY_UPDATE] =    (void*)Projectile17_Update,
    [ENTITY_DIE] =       (void*)Projectile17_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static Entity* FUN_080a2790(Coords32* c, bool8 kind) {
  Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 17);
    p->work[0] = kind;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->work[1] = 1;
  }
  return p;
}

static Entity* FUN_080a27e4(Coords32* c, bool8 kind) {
  Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 17);
    p->work[0] = kind;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->work[1] = 2;
  }
  return p;
}

Entity* FUN_080a2838(Entity* e, Coords32* c1, Coords32* c2, bool8 isDirRight) {
  Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 17);
    p->work[0] = isDirRight;
    (p->coord).x = c1->x, (p->coord).y = c1->y;
    (p->unk_coord).x = c2->x, (p->unk_coord).y = c2->y;
    p->work[1] = 0;
    p->unk_28 = (void*)e;
  }
  return p;
}

// --------------------------------------------

INCASM("asm/projectile/unk_17_a.inc");

void Projectile17_Die(struct Projectile* p) {
  (p->s).flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/projectile/unk_17_b.inc");

void FUN_080a2d9c(struct Projectile* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SetSpriteAnimation(p, MOTION(0x42, 4));
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(p);
      if ((p->s).motion.state == 3) {
        SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
      }
      break;
  }
}

void FUN_080a2dec(struct Projectile* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SetSpriteAnimation(p, 0x4202);
      (p->s).work[2] = 0x14;
      (p->s).d.y = 0x40;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      (p->s).coord.y -= (p->s).d.y;
      UpdateSpriteAnimation(p);
      if ((p->s).work[2] == 0 || --(p->s).work[2] == 0) {
        (p->s).mode[2]++;
      }
      break;
    case 2:
      SetSpriteAnimation(p, 0x4203);
      (p->s).work[2] = 0x14;
      (p->s).d.y = 0x20;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 3:
      (p->s).coord.y -= (p->s).d.y;
      UpdateSpriteAnimation(p);
      if ((p->s).work[2] == 0 || --(p->s).work[2] == 0) {
        SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
      }
      break;
  }
}

// --------------------------------------------

void FUN_080a2adc(Projectile* p);
void FUN_080a2d9c(Projectile* p);
void FUN_080a2dec(Projectile* p);

// 0x0836B3B4
static const ProjectileFunc PTR_ARRAY_0836b3b4[3] = {
    FUN_080a2adc,
    FUN_080a2d9c,
    FUN_080a2dec,
};

// 0x0836B3C0
static const struct Collision sCollisions[] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(10)},
    },
};
