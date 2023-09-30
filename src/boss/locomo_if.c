#include "boss.h"
#include "collision.h"
#include "global.h"

INCASM("asm/boss/locomo_if.inc");

void LocomoIF_Init(struct Boss* p);
void LocomoIF_Update(struct Boss* p);
void LocomoIF_Die(struct Boss* p);

// clang-format off
const BossRoutine gLocomoIFRoutine = {
    [ENTITY_INIT] =      LocomoIF_Init,
    [ENTITY_MAIN] =      LocomoIF_Update,
    [ENTITY_DIE] =       LocomoIF_Die,
    [ENTITY_DISAPPEAR] = DeleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void nop_08054ad8(struct Boss* p);

// clang-format off
static const BossFunc sUpdates1[7] = {
    nop_08054ad8,
    nop_08054ad8,
    nop_08054ad8,
    nop_08054ad8,
    nop_08054ad8,
    nop_08054ad8,
    nop_08054ad8,
};
// clang-format on

void FUN_08054adc(struct Boss* p);
void FUN_08054b20(struct Boss* p);
void FUN_08054b98(struct Boss* p);
void FUN_08054cac(struct Boss* p);
void FUN_08054e94(struct Boss* p);
void locomoIF_08054f18(struct Boss* p);
void FUN_08054fcc(struct Boss* p);

// clang-format off
static const BossFunc sUpdates2[7] = {
    FUN_08054adc,
    FUN_08054b20,
    FUN_08054b98,
    FUN_08054cac,
    FUN_08054e94,
    locomoIF_08054f18,
    FUN_08054fcc,
};
// clang-format on

// --------------------------------------------

void locomoIF_080550ec(struct Boss* p);

static const BossFunc sDeads[1] = {
    locomoIF_080550ec,
};

// --------------------------------------------

static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 0,
      hardness : HARDNESS_B3,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {PIXEL(0), PIXEL(9), PIXEL(60), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 5,
      hardness : HARDNESS_B3,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), PIXEL(0), PIXEL(12), PIXEL(12)},
    },
};

static const u8 sInitModes[2] = {1, 0};
static const struct Coord sElementCoord = {0, 0};

static const motion_t sMotions[3] = {
    MOTION(0x54, 0x9),
    MOTION(0x54, 0xA),
    MOTION(0x54, 0xA),
};
