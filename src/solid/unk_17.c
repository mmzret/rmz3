#include "collision.h"
#include "entity.h"
#include "global.h"
#include "solid.h"

INCASM("asm/solid/unk_17.inc");

// ------------------------------------------------------------------------------------------------------------------------------------

void Solid17_Init(struct Solid* p);
void Solid17_Update(struct Solid* p);
void Solid17_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid17Routine = {
    [ENTITY_INIT] =      Solid17_Init,
    [ENTITY_UPDATE] =    Solid17_Update,
    [ENTITY_DIE] =       Solid17_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void nop_080cf208(struct Solid* p);

const SolidFunc sSolid17Updates1[3] = {
    nop_080cf208,
    nop_080cf208,
    nop_080cf208,
};

// --------------------------------------------

void FUN_080cf20c(struct Solid* p);
void FUN_080cf250(struct Solid* p);
void FUN_080cf378(struct Solid* p);

const SolidFunc sSolid17Updates2[3] = {
    FUN_080cf20c,
    FUN_080cf250,
    FUN_080cf378,
};

// --------------------------------------------

const struct Collision sSolid17Collisions[3] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_NEUTRAL,
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
      range : {0x0000, 0x0C00, 0x1E00, 0x2000},
    },
    [2] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {0x0000, 0x0E00, 0x1E00, 0x1C00},
    },
};

// --------------------------------------------

// clang-format off
const motion_t sSolid17Motions[3][4] = {
    {
        MOTION(0x6C, 0x06),
        MOTION(0x6C, 0x04),
        MOTION(0x6C, 0x02),
        MOTION(0x6C, 0x08),
    },
    {
        MOTION(0x6C, 0x07),
        MOTION(0x6C, 0x05),
        MOTION(0x6C, 0x03),
        MOTION(0x6C, 0x09),
    },
    {
        MOTION(0x6C, 0x0C),
        MOTION(0x6C, 0x0B),
        MOTION(0x6C, 0x0A),
        MOTION(0x6C, 0x0D),
    },
};
// clang-format on

// --------------------------------------------

const struct Rect Rect_0837061c = {0x0, 0xE00, 0x1E00, 0x1C00};
const u8 u8_ARRAY_08370624[4] = {0, 0, 0, 0};

// clang-format off
const struct Rect Rect_ARRAY_08370628[6] = {
    { 0x0000, 0x0100, -0x0100, 0x0000 },
    { 0x0000, -0x0100, 0x0100, 0x0000 },
    { -0x0F00, 0x1C00, 0x0F00, 0x1C00 },
    { -0x0F00, 0x0000, -0x0F00, 0x1C00 },
    { -0x0F00, 0x0000, 0x0F00, 0x0000 },
    { 0x0F00, 0x0000, 0x0F00, 0x1C00 },
};
// clang-format on
