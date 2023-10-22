#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/shotloid.inc");

void Shotloid_Init(struct Enemy* p);
void Shotloid_Update(struct Enemy* p);
void Shotloid_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gShotloidRoutine = {
    [ENTITY_INIT] =      Shotloid_Init,
    [ENTITY_UPDATE] =    Shotloid_Update,
    [ENTITY_DIE] =       Shotloid_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_08093e04(struct Enemy* p);
void FUN_08093de0(struct Enemy* p);
void FUN_08093de4(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[9] = {
    FUN_08093e04,
    FUN_08093de4,
    FUN_08093de4,
    FUN_08093de4,
    FUN_08093de4,
    FUN_08093de4,
    FUN_08093de0,
    FUN_08093de0,
    FUN_08093de4,
};
// clang-format on

void FUN_08093e60(struct Enemy* p);
void FUN_08093ee4(struct Enemy* p);
void FUN_08093fe0(struct Enemy* p);
void FUN_08094110(struct Enemy* p);
void FUN_08094178(struct Enemy* p);
void FUN_08094224(struct Enemy* p);
void FUN_08094320(struct Enemy* p);
void FUN_08094534(struct Enemy* p);
void FUN_0809468c(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[9] = {
    FUN_08093e60,
    FUN_08093ee4,
    FUN_08093fe0,
    FUN_08094110,
    FUN_08094178,
    FUN_08094224,
    FUN_08094320,
    FUN_08094534,
    FUN_0809468c,
};
// clang-format on

// --------------------------------------------

void FUN_080947c4(struct Enemy* p);
void FUN_08094874(struct Enemy* p);

static const EnemyFunc sDeads[3] = {
    FUN_080947c4,
    FUN_08094874,
    FUN_08094534,
};

// --------------------------------------------

static const struct Collision sCollisions[3] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(12), PIXEL(23), PIXEL(23)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(12), PIXEL(23), PIXEL(23)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(12), PIXEL(23), PIXEL(23)},
    },
};

static const struct Coord sElementCoord = {PIXEL(0), -PIXEL(10)};
static const u8 sInitModes[2] = {5, 6};

// clang-format off
static const motion_t sMotions[5] = {
    MOTION(SM142_SHOTLOID, 13),
    MOTION(SM142_SHOTLOID, 14),
    MOTION(SM142_SHOTLOID, 15),
    MOTION(SM142_SHOTLOID, 16),
    MOTION(SM142_SHOTLOID, 11),
};
// clang-format on
