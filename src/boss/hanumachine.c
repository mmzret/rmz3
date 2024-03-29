#include "boss.h"
#include "collision.h"
#include "global.h"

static const struct Collision sCollisions[22];
static const struct Coord sElementCoord;

INCASM("asm/boss/hanumachine.inc");

void Hanumachine_Init(struct Boss* p);
void Hanumachine_Update(struct Boss* p);
void Hanumachine_Die(struct Boss* p);

// clang-format off
const BossRoutine gHanumachineRoutine = {
    [ENTITY_INIT] =      Hanumachine_Init,
    [ENTITY_UPDATE] =    Hanumachine_Update,
    [ENTITY_DIE] =       Hanumachine_Die,
    [ENTITY_DISAPPEAR] = DeleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void hanu_0805bcfc(struct Boss* p);
void hanu_0805bd38(struct Boss* p);
void hanu_0805bdc0(struct Boss* p);
void hanu_0805bf10(struct Boss* p);
void hanu_0805bf60(struct Boss* p);
void hanu_0805c0d0(struct Boss* p);
void hanu_0805c198(struct Boss* p);
void hanu_0805c2a4(struct Boss* p);
void hanu_0805c30c(struct Boss* p);
void FUN_0805c3cc(struct Boss* p);
void FUN_0805c404(struct Boss* p);
void hanu_0805c4a4(struct Boss* p);
void FUN_0805c580(struct Boss* p);
void hanu_0805c670(struct Boss* p);
void FUN_0805c760(struct Boss* p);
void hanu_0805c7c4(struct Boss* p);
void FUN_0805c87c(struct Boss* p);
void hanu_0805c98c(struct Boss* p);
void FUN_0805cb00(struct Boss* p);
void hanu_0805cbfc(struct Boss* p);
void hanu_0805ccc0(struct Boss* p);
void FUN_0805cdbc(struct Boss* p);
void FUN_0805ce50(struct Boss* p);
void hanu_0805cf58(struct Boss* p);
void FUN_0805cfe8(struct Boss* p);
void FUN_0805d080(struct Boss* p);
void FUN_0805d1c4(struct Boss* p);
void FUN_0805d210(struct Boss* p);
void FUN_0805d310(struct Boss* p);
void FUN_0805d3c8(struct Boss* p);

// clang-format off
static const BossFunc sUpdates1[30] = {
    hanu_0805bcfc,
    hanu_0805bd38,
    hanu_0805bdc0,
    hanu_0805bf10,
    hanu_0805bf60,
    hanu_0805c0d0,
    hanu_0805c198,
    hanu_0805c2a4,
    hanu_0805c30c,
    FUN_0805c3cc,
    FUN_0805c404,
    hanu_0805c4a4,
    FUN_0805c580,
    hanu_0805c670,
    FUN_0805c760,
    hanu_0805c7c4,
    FUN_0805c87c,
    hanu_0805c98c,
    FUN_0805cb00,
    hanu_0805cbfc,
    hanu_0805ccc0,
    FUN_0805cdbc,
    FUN_0805ce50,
    hanu_0805cf58,
    FUN_0805cfe8,
    FUN_0805d080,
    FUN_0805d1c4,
    FUN_0805d210,
    FUN_0805d310,
    FUN_0805d3c8,
};
// clang-format on

void FUN_0805bcdc(struct Boss* p);

// clang-format off
static const BossFunc sUpdates2[30] = {
    NULL,
    NULL,
    FUN_0805bcdc,
    FUN_0805bcdc,
    FUN_0805bcdc,
    NULL,
    NULL,
    FUN_0805bcdc,
    FUN_0805bcdc,
    FUN_0805bcdc,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    FUN_0805bcdc,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[22] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(13), PIXEL(19), PIXEL(31)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 7,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(13), PIXEL(19), PIXEL(31)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(2), -PIXEL(12), PIXEL(31), PIXEL(22)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 7,
      remaining : 0,
      range : {PIXEL(2), -PIXEL(12), PIXEL(31), PIXEL(22)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(4), -PIXEL(14), PIXEL(23), PIXEL(34)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 7,
      remaining : 0,
      range : {PIXEL(4), -PIXEL(14), PIXEL(23), PIXEL(34)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(2), -PIXEL(18), PIXEL(19), PIXEL(46)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 7,
      remaining : 0,
      range : {PIXEL(2), -PIXEL(18), PIXEL(19), PIXEL(46)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(1), -PIXEL(10), PIXEL(36), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 7,
      remaining : 0,
      range : {PIXEL(1), -PIXEL(10), PIXEL(36), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(42), PIXEL(42)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 7,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(0), PIXEL(42), PIXEL(42)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(2), PIXEL(22), PIXEL(26)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 7,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(2), PIXEL(22), PIXEL(26)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 4,
      layer : 0x00000001,
      range : {PIXEL(18), -PIXEL(50), PIXEL(11), PIXEL(23)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 3,
      layer : 0x00000001,
      range : {-PIXEL(40), -PIXEL(41), PIXEL(11), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(11), -PIXEL(44), PIXEL(47), PIXEL(36)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(2), -PIXEL(13), PIXEL(21), PIXEL(33)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 7,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(2), -PIXEL(13), PIXEL(21), PIXEL(33)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(10), -PIXEL(16), PIXEL(8), PIXEL(65)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(26), PIXEL(33)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 7,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(22), PIXEL(26), PIXEL(33)},
    },
};

static const struct Coord sElementCoord = {PIXEL(0), -PIXEL(14)};
