#include "collision.h"
#include "global.h"
#include "overworld_terrain.h"
#include "projectile.h"

// Sonic boom from Childre ship

static void FUN_080b27f8(Projectile* p);
static void FUN_080b2884(Projectile* p);
static void FUN_080b28f0(Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile47Routine = {
    [ENTITY_INIT] =      (void*)FUN_080b27f8,
    [ENTITY_UPDATE] =    (void*)FUN_080b2884,
    [ENTITY_DIE] =       (void*)FUN_080b28f0,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// 0x080b2794
Entity* CreateChildreShipSonicBoom(Coords32* c, u8 updown) {
  Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 47);
    (p->coord).x = c->x, (p->coord).y = c->y;
    (p->d).x = 0;
    if (updown) {
      (p->d).y = PIXEL(3);  // 下向き
    } else {
      (p->d).y = -PIXEL(3);  // 上向き
    }
  }
  return p;
}

// --------------------------------------------

static void FUN_080b27f8(Projectile* p) {
  static const struct Collision sCollision = {
    kind : DDP,
    faction : FACTION_NEUTRAL,
    damage : 4,
    nature : ELEMENT_ENCHANTABLE,
    layer : 0x00000002,
    range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(8)},
  };

  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  INIT_BODY(p, &sCollision, 0, NULL);
  SetSpriteAnimation(p, MOTION(SM183_CHILDRE_SHIP_SONIC_WAVE, 0));
  if (p->d.y < 0) SET_YFLIP(p, TRUE);  // 上向き
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  FUN_080b2884(p);
}

static void FUN_080b2884(Projectile* p) {
  UpdateSpriteAnimation(p);

  // outside of sea
  if ((p->coord.y < gOverworld.sea) || (p->coord.y > PIXEL(1040))) {
    EXIT_BODY(p);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
    return;
  }

  p->coord.x += p->d.x;
  p->coord.y += p->d.y;
}

static void FUN_080b28f0(Projectile* p) {
  p->flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}
