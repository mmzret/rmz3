#include "collision.h"
#include "global.h"
#include "story.h"
#include "projectile.h"

INCASM("asm/projectile/pantheon_bomber_a.inc");

static const ProjectileFunc sUpdates[2];
void PantheonBombProjectile_Die(Projectile* p);

void PantheonBombProjectile_Update(Projectile* p) {
  if (IS_METTAUR) {
    p->flags &= ~DISPLAY;
    EXIT_BODY(p);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
    PantheonBombProjectile_Die(p);
    return;
  }
  (sUpdates[p->mode[1]])(p);
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
