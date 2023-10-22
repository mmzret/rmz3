#include "collision.h"
#include "enemy.h"
#include "global.h"

void LeviathanMinigameEnemy_Init(struct Enemy* p);
void LeviathanMinigameEnemy_Update(struct Enemy* p);
void LeviathanMinigameEnemy_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gLeviathanMinigameEnemyRoutine = {
    [ENTITY_INIT] =      LeviathanMinigameEnemy_Init,
    [ENTITY_UPDATE] =    LeviathanMinigameEnemy_Update,
    [ENTITY_DIE] =       LeviathanMinigameEnemy_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void nop_0809a1ec(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[7] = {
    nop_0809a1ec,
    nop_0809a1ec,
    nop_0809a1ec,
    nop_0809a1ec,
    nop_0809a1ec,
    nop_0809a1ec,
    nop_0809a1ec,
};
// clang-format on

void FUN_0809a1f0(struct Enemy* p);
void FUN_0809a31c(struct Enemy* p);
void FUN_0809a4bc(struct Enemy* p);
void FUN_0809a5e0(struct Enemy* p);
void FUN_0809a700(struct Enemy* p);
void FUN_0809a90c(struct Enemy* p);
void FUN_0809ab28(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[7] = {
    FUN_0809a1f0,
    FUN_0809a31c,
    FUN_0809a4bc,
    FUN_0809a5e0,
    FUN_0809a700,
    FUN_0809a90c,
    FUN_0809ab28,
};
// clang-format on

// --------------------------------------------

void FUN_0809ac28(struct Enemy* p);
void FUN_0809acdc(struct Enemy* p);
void FUN_0809ad8c(struct Enemy* p);
void FUN_0809ae68(struct Enemy* p);

static const EnemyFunc sDeads[4] = {
    FUN_0809ac28,
    FUN_0809acdc,
    FUN_0809ad8c,
    FUN_0809ae68,
};

// --------------------------------------------

static const struct Collision sCollisions[6] = {
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
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(6), PIXEL(1), PIXEL(20), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(1), -PIXEL(8), PIXEL(12), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(4), PIXEL(1), PIXEL(33), PIXEL(10)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(11), PIXEL(11)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(2), -PIXEL(2), PIXEL(18), PIXEL(16)},
    },
};

static const u8 u8_ARRAY_0836a764[6] = {
    0, 1, 2, 2, 3, 3,
};

static const u8 u8_ARRAY_0836a76a[8] = {
    0, 1, 2, 3, 4, 5, 6, 0,
};

// clang-format off
static const motion_t sMotions[12] = {
    MOTION(SM024_SHARKSEAL_X, 0),
    MOTION(SM053_SHELLUNO, 1),
    MOTION(SM240_SEA_BREAM, 0),
    MOTION(SM239_ANGEL_FISH, 0),
    MOTION(SM241_CRAB, 1),
    MOTION(SM242_FISH_SCHOOL, 0),
    MOTION(SM024_SHARKSEAL_X, 4),
    MOTION(SM024_SHARKSEAL_X, 5),
    MOTION(SM024_SHARKSEAL_X, 5),
    MOTION(SM053_SHELLUNO, 6),
    MOTION(SM053_SHELLUNO, 7),
    MOTION(SM053_SHELLUNO, 8),
};


