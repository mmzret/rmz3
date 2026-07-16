#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "story.h"
#include "vfx.h"

static const struct Collision sCollision;

static void GrandCannonBomb_Init(struct Projectile* p);
static void GrandCannonBomb_Update(struct Projectile* p);
static void GrandCannonBomb_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gGrandCannonBombRoutine = {
    [ENTITY_INIT] =      GrandCannonBomb_Init,
    [ENTITY_UPDATE] =    GrandCannonBomb_Update,
    [ENTITY_DIE] =       GrandCannonBomb_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

void CreateGrandCannonBomb(Coords32* c, s32 amplitude, u8 angle) {
  struct Projectile* p = (struct Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 3);
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
    (p->s).d.x = Cos(angle, amplitude);
    (p->s).d.y = Sin(angle, amplitude);
  }
}

// --------------------------------------------

static void GrandCannonBomb_Init(struct Projectile* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = 0;
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  INIT_BODY(p, &sCollision, 1, NULL);
  GrandCannonBomb_Update(p);
}

// --------------------------------------------

static void _parabolaGrandcannonBomb(struct Projectile* p);  // グランドキャノンの砲弾が放物線を描いて飛ぶ処理

static void GrandCannonBomb_Update(struct Projectile* p) {
  static const ProjectileFunc sUpdates[1] = {
      _parabolaGrandcannonBomb,
  };

  if (IS_METTAUR) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (sUpdates[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void GrandCannonBomb_Die(struct Projectile* p) {
  EXIT_BODY(p);
  CreateSmoke(3, &(p->s).coord);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void _parabolaGrandcannonBomb(struct Projectile* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SetSpriteAnimation(&p->s, MOTION(7, 8));
      (p->s).mode[2]++;
      // fallthrough
    case 1:
      UpdateSpriteAnimation(p);
      (p->s).coord.x += (p->s).d.x;
      (p->s).coord.y += (p->s).d.y;
      (p->s).d.y += 0x40;
      if ((p->s).d.y > 0x700) {
        (p->s).d.y = 0x700;
      }
      if (FUN_080098a4((p->s).coord.x, (p->s).coord.y) || ((p->body).status & 4)) {
        SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
      }
      break;
  }
}

// --------------------------------------------

static const struct Collision sCollision = {
  kind : DDP,
  faction : FACTION_NEUTRAL,
  damage : 3,
  remaining : 0,
  layer : 0x00000001,
  range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
};
