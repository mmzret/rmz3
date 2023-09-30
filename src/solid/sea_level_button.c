#include "collision.h"
#include "global.h"
#include "solid.h"

static const struct Collision sCollisions[2];
static const struct Rect sSizes[2];

INCASM("asm/solid/sea_level_button.inc");

void SeaLevelButton_Init(struct Solid* p);
void SeaLevelButton_Update(struct Solid* p);
void SeaLevelButton_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSeaLevelButtonRoutine = {
    [ENTITY_INIT] =      SeaLevelButton_Init,
    [ENTITY_MAIN] =      SeaLevelButton_Update,
    [ENTITY_DIE] =       SeaLevelButton_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
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
      range : {0x0000, -0x0800, 0x1E00, 0x0600},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x01,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFCEF7BD,
      range : {0x0000, 0x0000, 0x4000, 0x4000},
    },
};

static const struct Rect sSizes[2] = {
    {0, 0, 0x2000, 0x1400},
    {0, 0x400, 0x2000, 0x1400},
};

const u16 u16_ARRAY_083719b4[4] = {0x29, 0x2A, 0x2B, 0x2C};
