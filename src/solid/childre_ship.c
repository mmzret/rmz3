#include "collision.h"
#include "global.h"
#include "solid.h"

static const struct Collision sCollisions[2];
static const s32 sSonicWaveXCoords[4];

INCASM("asm/solid/childre_ship.inc");

void ChildreShip_Init(struct Solid* p);
void ChildreShip_Update(struct Solid* p);
void ChildreShip_Die(struct Solid* p);

// clang-format off
const SolidRoutine gChildreShipRoutine = {
    [ENTITY_INIT] =      ChildreShip_Init,
    [ENTITY_UPDATE] =    ChildreShip_Update,
    [ENTITY_DIE] =       ChildreShip_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(56), PIXEL(56)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(0), PIXEL(64), PIXEL(64)},
    },
};

static const s32 sSonicWaveXCoords[4] = {
    PIXEL(2984),
    PIXEL(4696),
    PIXEL(8600),
    PIXEL(9736),
};
