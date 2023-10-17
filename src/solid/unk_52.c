#include "collision.h"
#include "global.h"
#include "solid.h"

static const struct Collision sCollision;

INCASM("asm/solid/unk_52.inc");

void Solid52_Init(struct Solid* p);
void Solid52_Update(struct Solid* p);
void Solid52_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid52Routine = {
    [ENTITY_INIT] =      Solid52_Init,
    [ENTITY_UPDATE] =    Solid52_Update,
    [ENTITY_DIE] =       Solid52_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

static const struct Collision sCollision = {
  kind : DRP,
  faction : FACTION_ENEMY,
  damage : 0,
  LAYER(0xFFFFFFFF),
  hitzone : 1,
  hardness : METAL,
  remaining : 0,
  layer : 0xFFFFFFFF,
  range : {PIXEL(0), PIXEL(8), PIXEL(32), PIXEL(16)},
};
