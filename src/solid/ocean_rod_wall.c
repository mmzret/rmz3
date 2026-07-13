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
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

static void Solid53_Init(struct Solid* p) {
  if (GetMetatileAttr((p->s).coord.x, (p->s).coord.y) == 0) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  INIT_BODY(p, &sCollision, 0, NULL);
  (&(p->s).d)->x = (&(p->s).d)->y = 0;
  (p->s).coord.x += PIXEL(8);
  (p->s).coord.y += PIXEL(8);
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  Solid53_Update(p);
}

static void Solid53_Update(struct Solid* p) {
  if ((p->body).status & BODY_STATUS_WHITE) {
    if ((p->body).status & BODY_STATUS_RECOILED) {
      EXIT_BODY(p);
      (p->s).flags |= DISPLAY;
      (p->s).flags |= FLIPABLE;
      EnableSpriteAnimation_Normal(p);
      SetSpriteAnimation(p, MOTION(SM182_UNK, 1));
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
