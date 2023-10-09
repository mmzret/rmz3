#include "collision.h"
#include "global.h"
#include "solid.h"

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
      special : 0,
      damage : 4,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {0x0000, 0x0000, 0x3800, 0x3800},
    },
    {
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
      range : {0x0000, 0x0000, 0x4000, 0x4000},
    },
};

const s32 s32_ARRAY_08371a00[4] = {
    0xBA800,
    0x125800,
    0x219800,
    0x260800,
};
