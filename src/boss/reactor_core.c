#include "boss.h"
#include "collision.h"
#include "global.h"

// エネルギー再生施設の炉心(スイッチ押し込み部屋)

INCASM("asm/boss/reactor_core.inc");

void ReactorCore_Init(struct Boss* p);
void ReactorCore_Update(struct Boss* p);
void ReactorCore_Die(struct Boss* p);
void ReactorCore_Disappear(struct Boss* p);

// clang-format off
const BossRoutine gReactorCoreRoutine = {
    [ENTITY_INIT] =      ReactorCore_Init,
    [ENTITY_UPDATE] =    ReactorCore_Update,
    [ENTITY_DIE] =       ReactorCore_Die,
    [ENTITY_DISAPPEAR] = ReactorCore_Disappear,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void nop_08061a74(struct Boss* p);

static const BossFunc sUpdates1[2] = {
    nop_08061a74,
    nop_08061a74,
};

void FUN_08061a78(struct Boss* p);
void FUN_08061aa4(struct Boss* p);

static const BossFunc sUpdates2[2] = {
    FUN_08061a78,
    FUN_08061aa4,
};

// --------------------------------------------

void FUN_08061adc(struct Boss* p);

static const BossFunc sDeads[1] = {
    FUN_08061adc,
};

// --------------------------------------------

static const struct Collision sCollisions[1] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      atkType : 0x00,
      comboLv : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(48), PIXEL(32)},
    },
};

static const struct Rect sSize = {PIXEL(0), PIXEL(0), PIXEL(48), PIXEL(26)};
static const u8 sInitModes[4] = {0, 0, 0, 0};
