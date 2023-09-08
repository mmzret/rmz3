#include "collision.h"
#include "entity.h"
#include "global.h"
#include "solid.h"

static void Solid25_Init(struct Solid* p);
void Solid25_Update(struct Solid* p);
void Solid25_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid25Routine = {
    [ENTITY_INIT] =      Solid25_Init,
    [ENTITY_MAIN] =      Solid25_Update,
    [ENTITY_DIE] =       Solid25_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

static void Solid25_Init(struct Solid* p) {
  static const struct Rect size = {0, 0x1800, 0x2000, 0x3000};

  (p->s).flags |= DISPLAY;
  InitNonAffineMotion(&p->s);
  (p->s).flags |= FLIPABLE;
  (p->s).flags2 |= ENTITY_HAZARD;
  (p->s).size = (struct Rect*)&size;
  (p->s).hazardAttr = 0x2001;
  (p->s).coord.x += PIXEL(8);
  (p->s).unk_coord.y = (p->s).coord.y - PIXEL(8);
  if ((p->s).work[1] == 0) {
    SetMotion(&p->s, MOTION(0x7c, 0x01));
  } else {
    SetMotion(&p->s, MOTION(0x7d, 0x00));
  }
  SET_SOLID_ROUTINE(p, ENTITY_MAIN);
  Solid25_Update(p);
}

INCASM("asm/solid/unk_25.inc");
