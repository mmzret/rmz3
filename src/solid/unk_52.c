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
    [ENTITY_MAIN] =      Solid52_Update,
    [ENTITY_DIE] =       Solid52_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

static const struct Collision sCollision = {
  kind : DRP,
  layer : 1,
  special : 0,
  damage : 0,
  unk_04 : 0xFF,
  element : 0xFF,
  nature : 0xFF,
  comboLv : 0xFF,
  hitzone : 1,
  hardness : METAL,
  unk_0a : 0x00,
  remaining : 0,
  unk_0c : 0xFFFFFFFF,
  range : {PIXEL(0), PIXEL(8), PIXEL(32), PIXEL(16)},
};
