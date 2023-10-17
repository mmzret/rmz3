#include "boss.h"
#include "collision.h"
#include "global.h"

INCASM("asm/boss/omega_gold.inc");

void OmegaGold_Init(struct Boss* p);
void OmegaGold_Update(struct Boss* p);
void OmegaGold_Die(struct Boss* p);
void OmegaGold_Disappear(struct Boss* p);

// clang-format off
const BossRoutine gOmegaGoldRoutine = {
    [ENTITY_INIT] =      OmegaGold_Init,
    [ENTITY_UPDATE] =    OmegaGold_Update,
    [ENTITY_DIE] =       OmegaGold_Die,
    [ENTITY_DISAPPEAR] = OmegaGold_Disappear,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_0805b41c(struct Boss* p);
void FUN_0805b45c(struct Boss* p);
void FUN_0805b4a4(struct Boss* p);
void changeGoldOmega1Mode(struct Boss* p);
void nop_0805b5dc(struct Boss* p);
void nop_0805b740(struct Boss* p);
void nop_0805b7ec(struct Boss* p);
void nop_0805b874(struct Boss* p);

// clang-format off
static const BossFunc sUpdates1[8] = {
    FUN_0805b41c,
    FUN_0805b45c,
    FUN_0805b4a4,
    changeGoldOmega1Mode,
    nop_0805b5dc,
    nop_0805b740,
    nop_0805b7ec,
    nop_0805b874,
};
// clang-format on

// --------------------------------------------

void goldOmega1_0805b420(struct Boss* p);
void makeGoldOmega1Mode2(struct Boss* p);
void FUN_0805b4a8(struct Boss* p);
void goldOmega1Neutral(struct Boss* p);
void goldOmega1Laser(struct Boss* p);
void FUN_0805b744(struct Boss* p);
void FUN_0805b7f0(struct Boss* p);
void FUN_0805b878(struct Boss* p);

// clang-format off
static const BossFunc sUpdates2[8] = {
    goldOmega1_0805b420,
    makeGoldOmega1Mode2,
    FUN_0805b4a8,
    goldOmega1Neutral,
    goldOmega1Laser,
    FUN_0805b744,
    FUN_0805b7f0,
    FUN_0805b878,
};
// clang-format on

// --------------------------------------------

void FUN_0805b270(struct Boss* p);
void FUN_0805b358(struct Boss* p);

static const BossFunc sDeads[2] = {
    FUN_0805b270,
    FUN_0805b358,
};

// --------------------------------------------

static const struct Collision sCollisions[8] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 0,
      hardness : 1,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(3), PIXEL(24), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(20), -PIXEL(64), PIXEL(54), -PIXEL(128)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 5,
      remaining : 1,
      range : {PIXEL(2), -PIXEL(102), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(80), PIXEL(16), PIXEL(28)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(3), PIXEL(40), PIXEL(80)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(80), PIXEL(24), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(3), PIXEL(40), PIXEL(80)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(80), PIXEL(24), PIXEL(24)},
    },
};
