#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/unk_61.inc");

void Enemy61_Init(struct Enemy* p);
void Enemy61_Update(struct Enemy* p);
void Enemy61_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gEnemy61Routine = {
    [ENTITY_INIT] =      Enemy61_Init,
    [ENTITY_UPDATE] =    Enemy61_Update,
    [ENTITY_DIE] =       Enemy61_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_08093754(struct Enemy* p);

static const EnemyFunc sUpdates1[1] = {
    FUN_08093754,
};

void FUN_08093758(struct Enemy* p);

static const EnemyFunc sUpdates2[1] = {
    FUN_08093758,
};

// --------------------------------------------

static const struct Collision sCollisions[7] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(36), PIXEL(0), PIXEL(18), PIXEL(23)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(36), PIXEL(0), PIXEL(18), PIXEL(23)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(36), PIXEL(0), PIXEL(18), PIXEL(23)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-PIXEL(36), PIXEL(0), PIXEL(18), PIXEL(23)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(36), PIXEL(0), PIXEL(18), PIXEL(23)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(36), PIXEL(0), PIXEL(18), PIXEL(23)},
    },
};

static const s8 s8_ARRAY_08369de8[24] = {
    -3, -3, -2, -2, -1, -1, 0, 0, 1, 1, 2, 2, 2, 2, 1, 1, 0, 0, -1, -1, -2, -2, -3, -3,
};

static const u8 sInitModes[4] = {0, 0, 0, 0};
