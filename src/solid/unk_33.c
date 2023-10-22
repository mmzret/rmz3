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
    [ENTITY_UPDATE] =    Solid33_Update,
    [ENTITY_DIE] =       Solid33_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

static void Solid33_Init(struct Solid* p) {
  struct Coord* d;

  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  InitNonAffineMotion(&p->s);
  SetMotion(&p->s, MOTION(0x7D, 0x00));
  UpdateMotionGraphic(&p->s);
  INIT_BODY(p, &sCollisions[0], 0, NULL);
  (p->s).flags2 |= ENTITY_HAZARD;
  (p->s).size = &sSize;
  (p->s).hazardAttr = 0x2001;

  d = &(p->s).d;
  d->y = 0;
  (p->s).d.x = 0;
  (p->s).coord.x += PIXEL(8);
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
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
      faction : FACTION_ENEMY,
      damage : 255,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0800, 0x4200, 0x1200},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x2400, 0x3C00, 0x0800},
    },
};

static const struct Rect sSize = {0, 0x800, 0x4000, 0x1000};
