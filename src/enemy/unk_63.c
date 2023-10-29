#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/unk_63.inc");

void Enemy63_Init(struct Enemy* p);
void Enemy63_Update(struct Enemy* p);
void Enemy63_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gEnemy63Routine = {
    [ENTITY_INIT] =      Enemy63_Init,
    [ENTITY_UPDATE] =    Enemy63_Update,
    [ENTITY_DIE] =       Enemy63_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void nop_08094bcc(struct Enemy* p);
void FUN_08094bd0(struct Enemy* p);
void FUN_08094bf0(struct Enemy* p);

static const EnemyFunc sUpdates1[4] = {
    nop_08094bcc,
    FUN_08094bd0,
    nop_08094bcc,
    FUN_08094bf0,
};

void FUN_08094c80(struct Enemy* p);
void FUN_08094d48(struct Enemy* p);
void FUN_08094e0c(struct Enemy* p);
void FUN_08094ea0(struct Enemy* p);

static const EnemyFunc sUpdates2[4] = {
    FUN_08094c80,
    FUN_08094d48,
    FUN_08094e0c,
    FUN_08094ea0,
};

// --------------------------------------------

static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      unk_0a : 0x41,
      remaining : 0,
      layer : 1,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(10)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      unk_0a : 0x41,
      remaining : 0,
      layer : 1,
      range : {PIXEL(0), PIXEL(0), PIXEL(64), PIXEL(64)},
    },
};

static const struct Coord16 Coord16_ARRAY_08369f44[4] = {
    {-0x0180, 0x0000},
    {0x0180, 0x0000},
    {0x0000, -0x0180},
    {0x0000, 0x0180},
};

static const u8 sInitModes[6] = {
    0, 0, 0, 0, 1, 2,
};

static const s8 s8_ARRAY_ARRAY_08369f5a[4][2] = {
    {8, 0},
    {-8, 0},
    {0, 8},
    {0, -8},
};

static const motion_t sMotions[4] = {
    MOTION(SM088_LOCOMO_IF_ICE, 1),
    MOTION(SM088_LOCOMO_IF_ICE, 2),
    MOTION(SM088_LOCOMO_IF_ICE, 3),
    MOTION(SM088_LOCOMO_IF_ICE, 4),
};
