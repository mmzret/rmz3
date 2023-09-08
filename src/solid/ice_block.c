#include "collision.h"
#include "entity.h"
#include "global.h"
#include "solid.h"

INCASM("asm/solid/ice_block.inc");

// 壊れた宇宙船の屋内とかで上から落ちてくる氷ブロック

void IceBlock_Init(struct Solid* p);
void IceBlock_Update(struct Solid* p);
void IceBlock_Die(struct Solid* p);
void IceBlock_Disappear(struct Solid* p);

// clang-format off
const SolidRoutine gIceBlockRoutine = {
    [ENTITY_INIT] =      IceBlock_Init,
    [ENTITY_MAIN] =      IceBlock_Update,
    [ENTITY_DIE] =       IceBlock_Die,
    [ENTITY_DISAPPEAR] = IceBlock_Disappear,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

const struct Collision sIceBlockCollisions[2] = {
    {
      kind : DDP,
      layer : 0,
      special : 0,
      damage : 254,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {0x0000, -0x0C00, 0x1400, 0x1C00},
    },
    {
      kind : DRP,
      layer : 1,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x04,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, -0x0C00, 0x2800, 0x1C00},
    },
};

static const struct Rect sIceBlockSize = {0x0000, -0x0C00, 0x2000, 0x2000};
