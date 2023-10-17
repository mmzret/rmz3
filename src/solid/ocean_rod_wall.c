#include "collision.h"
#include "global.h"
#include "overworld_terrain.h"
#include "solid.h"

// Wall that can be destroyed by Charge Recoil Rod in Ocean highway ruins.

static const struct Collision sCollision;

static void Solid53_Init(struct Solid* p);
static void Solid53_Update(struct Solid* p);
void Solid53_Die(struct Solid* p);

// clang-format off
const SolidRoutine gOceanRodWallRoutine = {
    [ENTITY_INIT] =      Solid53_Init,
    [ENTITY_UPDATE] =    Solid53_Update,
    [ENTITY_DIE] =       Solid53_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

static void Solid53_Init(struct Solid* p) {
  struct Coord* velocity;

  if (GetMetatileAttr((p->s).coord.x, (p->s).coord.y) == 0) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    (p->body).status = 0;
    (p->body).prevStatus = 0;
    (p->body).invincibleTime = 0;
    (p->s).flags &= ~COLLIDABLE;
    SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  INIT_BODY(p, &sCollision, 0, NULL);
  velocity = &(p->s).d;
  velocity->x = velocity->y = PIXEL(0);
  (p->s).coord.x += PIXEL(8);
  (p->s).coord.y += PIXEL(8);
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  Solid53_Update(p);
}

static void Solid53_Update(struct Solid* p) {
  if ((p->body).status & BODY_STATUS_WHITE) {
    if ((p->body).status & BODY_STATUS_RECOILED) {
      (p->body).status = 0;
      (p->body).prevStatus = 0;
      (p->body).invincibleTime = 0;
      (p->s).flags &= ~COLLIDABLE;
      (p->s).flags |= DISPLAY;
      (p->s).flags |= FLIPABLE;
      InitNonAffineMotion(&p->s);
      SetMotion(&p->s, MOTION(SM182_UNK, 1));
      SET_SOLID_ROUTINE(p, ENTITY_DIE);
      Solid53_Die(p);
    }
  }
}

INCASM("asm/solid/unk_53.inc");

static const struct Collision sCollision = {
  kind : DRP,
  faction : FACTION_ENEMY,
  LAYER(RECOIL_PUSHABLE),
  hitzone : 0xFF,
  remaining : 0,
  range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(32)},
};
