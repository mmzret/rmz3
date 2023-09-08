#include "collision.h"
#include "global.h"
#include "overworld_terrain.h"
#include "solid.h"

static const struct Collision sCollision;

static void Solid53_Init(struct Solid* p);
static void Solid53_Update(struct Solid* p);
void Solid53_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid53Routine = {
    [ENTITY_INIT] =      Solid53_Init,
    [ENTITY_MAIN] =      Solid53_Update,
    [ENTITY_DIE] =       Solid53_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

static void Solid53_Init(struct Solid* p) {
  struct Body* body;
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

  (p->s).flags |= COLLIDABLE;
  body = &p->body;
  InitBody(body, &sCollision, &(p->s).coord, 0);
  body->parent = (struct CollidableEntity*)p;
  body->fn = NULL;
  velocity = &(p->s).d;
  velocity->x = velocity->y = PIXEL(0);
  (p->s).coord.x += PIXEL(8);
  (p->s).coord.y += PIXEL(8);
  SET_SOLID_ROUTINE(p, ENTITY_MAIN);
  Solid53_Update(p);
}

static void Solid53_Update(struct Solid* p) {
  if ((p->body).status & BODY_STATUS_WHITE) {
    if ((p->body).status & BODY_STATUS_B17) {
      (p->body).status = 0;
      (p->body).prevStatus = 0;
      (p->body).invincibleTime = 0;
      (p->s).flags &= ~COLLIDABLE;
      (p->s).flags |= DISPLAY;
      (p->s).flags |= FLIPABLE;
      InitNonAffineMotion(&p->s);
      SetMotion(&p->s, MOTION(0xB6, 0x01));
      SET_SOLID_ROUTINE(p, ENTITY_DIE);
      Solid53_Die(p);
    }
  }
}

INCASM("asm/solid/unk_53.inc");

static const struct Collision sCollision = {
  kind : DRP,
  layer : LAYER_ENEMY,
  special : 0,
  damage : 0,
  unk_04 : 0x00,
  element : 0x78,
  nature : 0x00,
  comboLv : 0x00,
  hitzone : 0xFF,
  hardness : 0x00,
  unk_0a : 0x00,
  remaining : 0,
  unk_0c : 0x00000000,
  range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(32)},
};
