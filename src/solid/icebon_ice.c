#include "collision.h"
#include "entity.h"
#include "global.h"
#include "solid.h"

INCASM("asm/solid/icebon_ice.inc");

// clang-format off

void IcebonIce_Init(struct Solid* p);
void IcebonIce_Update(struct Solid* p);
void FUN_080ca698(struct Solid* p);

// xx nn nn nn
const SolidRoutine gIcebonIceRoutine = {
    [ENTITY_INIT] =      IcebonIce_Init,
    [ENTITY_UPDATE] =    IcebonIce_Update,
    [ENTITY_DIE] =       FUN_080ca698,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

// clang-format off

void FUN_080ca700(struct Solid* p);
void nop_080ca6fc(struct Solid* p);
void FUN_080ca76c(struct Solid* p);

const SolidFunc sIcebonIceUpdates1[6] = {
    FUN_080ca700,
    nop_080ca6fc,
    nop_080ca6fc,
    FUN_080ca76c,
    nop_080ca6fc,
    nop_080ca6fc,
};
// clang-format on

// clang-format off

void FUN_080ca7d8(struct Solid* p);
void FUN_080ca880(struct Solid* p);
void FUN_080ca988(struct Solid* p);
void FUN_080caafc(struct Solid* p);
void FUN_080cab58(struct Solid* p);
void FUN_080cabe8(struct Solid* p);

const SolidFunc sIcebonIceUpdates2[6] = {
    FUN_080ca7d8,
    FUN_080ca880,
    FUN_080ca988,
    FUN_080caafc,
    FUN_080cab58,
    FUN_080cabe8,
};
// clang-format on

const struct Collision sIcebonIceCollisions[5] = {
    {
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
      range : {0x0000, -0x0700, 0x1C00, 0x0800},
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
      hitzone : 0x04,
      hardness : HARDNESS_B3,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0400, 0x1C00, 0x1800},
    },
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
      range : {0x0000, 0x0200, 0x1400, 0x1400},
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
      hitzone : 0x04,
      hardness : HARDNESS_B3,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0200, 0x1400, 0x1400},
    },
};

const struct Rect Rect_0836fd58 = {
    0x0000,
    -0x0300,
    0x1800,
    0x1000,
};

const u8 u8_ARRAY_0836fd60[2] = {0, 3};

const motion_t sIcebonIceMotions[4] = {
    MOTION(SM017_ICEBON_ICE, 0x06),
    MOTION(SM017_ICEBON_ICE, 0x07),
    MOTION(SM017_ICEBON_ICE, 0x08),
    MOTION(SM017_ICEBON_ICE, 0x06),
};
