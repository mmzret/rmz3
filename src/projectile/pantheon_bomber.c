#include "collision.h"
#include "global.h"
#include "projectile.h"

struct Projectile* createPantheonBomb(struct Coord* c1, struct Coord* c2, u8 a2) {
  struct Projectile* p = (struct Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 35);
    p->work[0] = a2;
    p->work[1] = 0;
    p->coord.x = c1->x;
    p->coord.y = c1->y;
    p->unk_coord.x = c2->x;
    p->unk_coord.y = c2->y;
  }
  return p;
}

struct Projectile* createPantheonBombBlast(struct Coord* c, u8 a1) {
  struct Projectile* p = (struct Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 35);
    p->work[0] = a1;
    p->work[1] = 1;
    p->coord.x = c->x;
    p->coord.y = c->y;
  }
  return p;
}

INCASM("asm/projectile/pantheon_bomber_a.inc");

void PantheonBombProjectile_Die(Projectile* p) {
  p->flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/projectile/pantheon_bomber_b.inc");

void PantheonBombProjectile_Init(Projectile* p);
void PantheonBombProjectile_Update(Projectile* p);
void PantheonBombProjectile_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gPantheonBombProjectileRoutine = {
    [ENTITY_INIT] =      (void*)PantheonBombProjectile_Init,
    [ENTITY_UPDATE] =    (void*)PantheonBombProjectile_Update,
    [ENTITY_DIE] =       (void*)PantheonBombProjectile_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void _pantheonBombAI(Projectile* p);
void pantheonBombBlastAI(Projectile* p);

static const ProjectileFunc sUpdates[2] = {
    _pantheonBombAI,
    pantheonBombBlastAI,
};

// --------------------------------------------

static const struct Collision sCollisions[4] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      nature : 0x80,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(14), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(14), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(28), PIXEL(28)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
};
