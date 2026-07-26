#include "collision.h"
#include "global.h"
#include "projectile.h"

// Minigame?

void FUN_080b1a48(Projectile* p);
void FUN_080b1b28(Projectile* p);
void FUN_080b1b40(Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile45Routine = {
    [ENTITY_INIT] =      (void*)FUN_080b1a48,
    [ENTITY_UPDATE] =    (void*)FUN_080b1b28,
    [ENTITY_DIE] =       (void*)FUN_080b1b40,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// 0x080b18d4
Entity* FUN_080b18d4(Coords32* c1, Coords32* c2, u8 element) {
  Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 45);
    p->work[0] = 0, p->work[1] = element;
    (p->coord).x = c1->x, (p->coord).y = c1->y;
    (p->unk_coord).x = c2->x, (p->unk_coord).y = c2->y;
  }
  return p;
}

// 0x080B1934
Entity* FUN_080b1934(void* q, Coords32* c, u8 kind) {
  Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 45);
    p->work[0] = 1, p->work[1] = kind;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->unk_28 = q;
  }
  return p;
}

// 0x080B1990
Entity* FUN_080b1990(void* q, Coords32* c, u8 kind) {
  Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 45);
    p->work[0] = 2, p->work[1] = kind;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->unk_28 = q;
  }
  return p;
}

// 0x080B19EC
Entity* FUN_080b19ec(void* q, Coords32* c, u8 kind) {
  Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 45);
    p->work[0] = 3, p->work[1] = kind;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->unk_28 = q;
  }
  return p;
}

static const ProjectileFunc PTR_ARRAY_0836d7cc[4];

INCASM("asm/projectile/unk_45_a.inc");

void FUN_080b1b28(Projectile* p) {
  (PTR_ARRAY_0836d7cc[p->mode[1]])((void*)p);
}

void FUN_080b1b40(Projectile* p) {
  p->flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/projectile/unk_45_b.inc");

void FUN_080b2204(struct Body* body) {
  Object* parent = (Object*)body->parent;
  if ((body->enemy->processing)->faction == 0) {
    *(u8*)((u8*)parent + 0xbc) = 1;
  }
}

void FUN_080b1b7c(Projectile* p);
void FUN_080b1cbc(Projectile* p);
void FUN_080b1f00(Projectile* p);
void FUN_080b2044(Projectile* p);

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
