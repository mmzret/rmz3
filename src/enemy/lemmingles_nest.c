#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/lemmingles_nest.inc");

void LemminglesNest_Init(struct Enemy* p);
void LemminglesNest_Update(struct Enemy* p);
void LemminglesNest_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gLemminglesNestRoutine = {
    [ENTITY_INIT] =      LemminglesNest_Init,
    [ENTITY_UPDATE] =    LemminglesNest_Update,
    [ENTITY_DIE] =       LemminglesNest_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void nop_0806e284(struct Enemy* p);

static const EnemyFunc sUpdates1[4] = {
    nop_0806e284,
    nop_0806e284,
    nop_0806e284,
    nop_0806e284,
};

// --------------------------------------------

void FUN_0806e288(struct Enemy* p);
void FUN_0806e518(struct Enemy* p);
void FUN_0806e3b0(struct Enemy* p);
void FUN_0806e4bc(struct Enemy* p);

static const EnemyFunc sUpdates2[4] = {
    FUN_0806e288,
    FUN_0806e518,
    FUN_0806e3b0,
    FUN_0806e4bc,
};

// --------------------------------------------

static const struct Collision sCollisions[3] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 2,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(12), PIXEL(24), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(12), PIXEL(24), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 0,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
};

static const u8 u8_ARRAY_0836680c[8] = {0, 0, 1, 1, 0, 0, 0, 0};
