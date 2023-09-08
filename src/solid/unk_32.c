#include "collision.h"
#include "entity.h"
#include "global.h"
#include "solid.h"

static const struct Collision sSolid32Collision;
static const struct Rect sSize;

INCASM("asm/solid/unk_32.inc");

void Solid32_Init(struct Solid* p);
void Solid32_Update(struct Solid* p);
void Solid32_Die(struct Solid* p);
void Solid32_Disappear(struct Solid* p);

// clang-format off
const SolidRoutine gSolid32Routine = {
    [ENTITY_INIT] =      Solid32_Init,
    [ENTITY_MAIN] =      Solid32_Update,
    [ENTITY_DIE] =       Solid32_Die,
    [ENTITY_DISAPPEAR] = Solid32_Disappear,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

static const struct Collision sSolid32Collision = {
  kind : DRP,
  layer : 1,
  special : 0,
  damage : 0,
  unk_04 : 0xFF,
  element : 0xFF,
  nature : 0xFF,
  comboLv : 0xFF,
  hitzone : 0xFF,
  hardness : 0x00,
  unk_0a : 0x00,
  remaining : 0,
  unk_0c : 0xFFFDEF7B,
  range : {0x0000, -0x1000, 0x1000, 0x2000},
};

static const struct Rect sSize = {0, 0xF000, 0x1000, 0x2000};
const struct Coord Coord_083714bc = {0, 0xFFFFF000};
