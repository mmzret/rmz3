#include "collision.h"
#include "entity.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"

static const struct Collision sCollision;

static void Solid34_Init(struct Solid* p);
void Solid34_Update(struct Solid* p);
static void Solid34_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid34Routine = {
    [ENTITY_INIT] =      Solid34_Init,
    [ENTITY_UPDATE] =    Solid34_Update,
    [ENTITY_DIE] =       Solid34_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

static void Solid34_Init(struct Solid* p) {
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  InitNonAffineMotion(&p->s);
  INIT_BODY(p, &sCollision, 0, NULL);
  (p->s).coord.y = FUN_0800a134((p->s).coord.x, (p->s).coord.y);
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  Solid34_Update(p);
}

INCASM("asm/solid/unk_34.inc");

static void Solid34_Die(struct Solid* p) { return; }

static const struct Collision sCollision = {
  kind : DRP,
  faction : FACTION_ENEMY,
  special : 0,
  damage : 0,
  unk_04 : 0xFF,
  element : 0xFF,
  nature : 0xFF,
  comboLv : 0xFF,
  hitzone : 0x01,
  hardness : 0x01,
  unk_0a : 0x00,
  remaining : 0,
  unk_0c : 0xFFFFFFFF,
  range : {0x0000, 0x0800, 0x2000, 0x1000},
};
