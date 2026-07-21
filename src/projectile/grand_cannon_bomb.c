#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "story.h"
#include "vfx.h"

static const struct Collision sCollision;

static void GrandCannonBomb_Init(struct ProjectileV2* p);
static void GrandCannonBomb_Update(struct ProjectileV2* p);
static void GrandCannonBomb_Die(struct ProjectileV2* p);

// clang-format off
const ProjectileRoutine gGrandCannonBombRoutine = {
    [ENTITY_INIT] =      (void*)GrandCannonBomb_Init,
    [ENTITY_UPDATE] =    (void*)GrandCannonBomb_Update,
    [ENTITY_DIE] =       (void*)GrandCannonBomb_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void CreateGrandCannonBomb(Coords32* c, s32 amplitude, u8 angle) {
  struct ProjectileV2* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 3);
    (p->coord).x = c->x;
    (p->coord).y = c->y;
    (p->d).x = Cos(angle, amplitude);
    (p->d).y = Sin(angle, amplitude);
  }
}

// --------------------------------------------

static void GrandCannonBomb_Init(struct ProjectileV2* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 0;
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  INIT_BODY(p, &sCollision, 1, NULL);
  GrandCannonBomb_Update(p);
}

static void _parabolaGrandcannonBomb(struct ProjectileV2* p);  // グランドキャノンの砲弾が放物線を描いて飛ぶ処理

static void GrandCannonBomb_Update(struct ProjectileV2* p) {
  static const ProjectileFunc sUpdates[1] = {
      (void*)_parabolaGrandcannonBomb,
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

static void GrandCannonBomb_Die(struct ProjectileV2* p) {
  EXIT_BODY(p);
  CreateSmoke(3, &p->coord);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void _parabolaGrandcannonBomb(struct ProjectileV2* p) {
  switch (p->mode[2]) {
    case 0: {
      SetSpriteAnimation(p, MOTION(SM007_GRAND_CANNON, 8));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      (p->coord).x += p->d.x;
      (p->coord).y += p->d.y;
      p->d.y += PIXEL(1) / 4;
      if (p->d.y > PIXEL(7)) p->d.y = PIXEL(7);
      if (FUN_080098a4((p->coord).x, (p->coord).y) || ((p->body).status & 4)) {
        SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
      }
      break;
    }
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
