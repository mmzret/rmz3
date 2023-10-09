#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/carry_arm.inc");

void CarryArm_Init(struct Enemy* p);
void CarryArm_Update(struct Enemy* p);
void CarryArm_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gCarryArmRoutine = {
    [ENTITY_INIT] =      CarryArm_Init,
    [ENTITY_UPDATE] =    CarryArm_Update,
    [ENTITY_DIE] =       CarryArm_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_080716a8(struct Enemy* p);

// clang-format off
const EnemyFunc PTR_ARRAY_08366b48[6] = {
    FUN_080716a8,
    FUN_080716a8,
    FUN_080716a8,
    FUN_080716a8,
    FUN_080716a8,
    FUN_080716a8,
};
// clang-format on

void FUN_080716ac(struct Enemy* p);
void FUN_08071778(struct Enemy* p);
void FUN_08071888(struct Enemy* p);
void FUN_08071964(struct Enemy* p);
void FUN_08071a28(struct Enemy* p);
void FUN_08071b88(struct Enemy* p);

// clang-format off
const EnemyFunc PTR_ARRAY_08366b60[6] = {
    FUN_080716ac,
    FUN_08071778,
    FUN_08071888,
    FUN_08071964,
    FUN_08071a28,
    FUN_08071b88,
};
// clang-format on

void FUN_08071bf0(struct Enemy* p);
void FUN_08071c70(struct Enemy* p);

const EnemyFunc PTR_ARRAY_08366b78[2] = {
    FUN_08071bf0,
    FUN_08071c70,
};

// --------------------------------------------

static const struct Collision sCollisions[] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : 8,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(32)},
    },
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
      hardness : 8,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(32)},
    },
};

const u8 u8_ARRAY_08366bb0[2] = {0, 3};

static const motion_t sMotions[4] = {
    MOTION(SM034_CARRYARM, 0x02),
    MOTION(SM034_CARRYARM, 0x03),
    MOTION(SM034_CARRYARM, 0x04),
    MOTION(SM034_CARRYARM, 0x05),
};
