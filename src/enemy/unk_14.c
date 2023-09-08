#include "collision.h"
#include "enemy.h"
#include "global.h"

// Maybe TopGabyoall

INCASM("asm/enemy/unk_14.inc");

void Enemy14_Init(struct Enemy* p);
void Enemy14_Update(struct Enemy* p);
void Enemy14_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gEnemy14Routine = {
    [ENTITY_INIT] =      Enemy14_Init,
    [ENTITY_MAIN] =      Enemy14_Update,
    [ENTITY_DIE] =       Enemy14_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_0806f5d0(struct Enemy* p);
void FUN_0806f6cc(struct Enemy* p);
void FUN_0806f7dc(struct Enemy* p);
void FUN_0806f89c(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_08366950[4] = {
    FUN_0806f5d0,
    FUN_0806f6cc,
    FUN_0806f7dc,
    FUN_0806f89c,
};

// --------------------------------------------

void FUN_0806f964(struct Enemy* p);
void FUN_0806fb08(struct Enemy* p);
void FUN_0806fc78(struct Enemy* p);
void FUN_0806fe38(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_08366960[4] = {
    FUN_0806f964,
    FUN_0806fb08,
    FUN_0806fc78,
    FUN_0806fe38,
};

// --------------------------------------------

static const struct Collision sCollisions[] = {
    {
      kind : DDP,
      layer : LAYER_ENEMY,
      special : 0,
      damage : 2,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(8), PIXEL(24), PIXEL(12)},
    },
    {
      kind : DRP,
      layer : LAYER_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : 2,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(8), PIXEL(24), PIXEL(12)},
    },
    {
      kind : DDP,
      layer : LAYER_ENEMY,
      special : 0,
      damage : 2,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(8), PIXEL(12), PIXEL(24)},
    },
    {
      kind : DRP,
      layer : LAYER_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : 2,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(8), PIXEL(12), PIXEL(24)},
    },
};

static const struct Coord sElementCoords[4] = {
    {0x00000000, -0x00000800},
    {0x00000000, -0x00000800},
    {0x00000000, -0x00000800},
    {0x00000000, 0x00000800},
};
