#include "collision.h"
#include "entity.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"
#include "zero.h"

static const struct Collision sCollisions[2];
static const struct Rect sSize;

static void Solid33_Init(struct Solid* p);
static void Solid33_Update(struct Solid* p);
static void Solid33_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid33Routine = {
    [ENTITY_INIT] =      Solid33_Init,
    [ENTITY_MAIN] =      Solid33_Update,
    [ENTITY_DIE] =       Solid33_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

static void Solid33_Init(struct Solid* p) {
  struct Body* body;
  struct Coord* d;

  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  InitNonAffineMotion(&p->s);
  SetMotion(&p->s, MOTION(0x7D, 0x00));
  UpdateMotionGraphic(&p->s);
  (p->s).flags |= COLLIDABLE;

  body = &p->body;
  InitBody(body, sCollisions, &(p->s).coord, 0);
  body->parent = (struct CollidableEntity*)p;
  body->fn = NULL;

  (p->s).flags2 |= ENTITY_HAZARD;
  (p->s).size = &sSize;
  (p->s).hazardAttr = 0x2001;

  d = &(p->s).d;
  d->y = 0;
  (p->s).d.x = 0;
  (p->s).coord.x += PIXEL(8);
  SET_SOLID_ROUTINE(p, ENTITY_MAIN);
  Solid33_Update(p);
}

static void Solid33_Update(struct Solid* p) {
  s32 y = SEA - PIXEL(10);
  if (((p->body).status & BODY_STATUS_B2) && ((p->s).coord.y + PIXEL(8) > (pZero2->s).coord.y)) {
    y = SEA - PIXEL(8);
  }
  (p->s).coord.y = (((p->s).coord.y * 7) + y) >> 3;
}

static void Solid33_Die(struct Solid* p) { return; }

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 255,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {0x0000, 0x0800, 0x4200, 0x1200},
    },
    {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 2,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {0x0000, 0x2400, 0x3C00, 0x0800},
    },
};

static const struct Rect sSize = {0, 0x800, 0x4000, 0x1000};
