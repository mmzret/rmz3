#include "collision.h"
#include "entity.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"

static const struct Collision sCollision;

static void Solid11_Init(struct Solid* p);
void Solid11_Update(struct Solid* p);
void Solid11_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid11Routine = {
    [ENTITY_INIT] =      Solid11_Init,
    [ENTITY_MAIN] =      Solid11_Update,
    [ENTITY_DIE] =       Solid11_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

static void Solid11_Init(struct Solid* p) {
  struct Body* body;
  struct Coord* velocity;

  const metatile_attr_t attr = GetMetatileAttr((p->s).coord.x, (p->s).coord.y);
  if (attr == 0) {
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
  velocity->x = velocity->y = 0;
  (p->s).coord.x += PIXEL(8);
  (p->s).coord.y += PIXEL(8);
  SET_SOLID_ROUTINE(p, ENTITY_MAIN);
  Solid11_Update(p);
}

INCASM("asm/solid/unk_11.inc");

// --------------------------------------------

static const struct Collision sCollision = {
  kind : DRP,
  layer : 1,
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
  range : {0x0000, 0x0000, 0x2000, 0x2000},
};
