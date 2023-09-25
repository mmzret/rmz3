#include "collision.h"
#include "enemy.h"
#include "global.h"

void Beetank_Init(struct Enemy* p);
void Beetank_Update(struct Enemy* p);
void Beetank_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gBeetankRoutine = {
    [ENTITY_INIT] =      Beetank_Init,
    [ENTITY_MAIN] =      Beetank_Update,
    [ENTITY_DIE] =       Beetank_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void nop_0807bc8c(struct Enemy* p);
void nop_0807bd3c(struct Enemy* p);
void nop_0807bde4(struct Enemy* p);
void FUN_0807be14(struct Enemy* p);
void FUN_0807be1c(struct Enemy* p);

// clang-format off
static const EnemyFunc PTR_ARRAY_083679c4[5] = {
    nop_0807bc8c,
    nop_0807bd3c,
    nop_0807bde4,
    FUN_0807be14,
    FUN_0807be1c,
};
// clang-format on

void FUN_0807bc90(struct Enemy* p);
void FUN_0807bd40(struct Enemy* p);
void FUN_0807bde8(struct Enemy* p);
void nop_0807be18(struct Enemy* p);
void FUN_0807be20(struct Enemy* p);

// clang-format off
static const EnemyFunc PTR_ARRAY_083679d8[5] = {
    FUN_0807bc90,
    FUN_0807bd40,
    FUN_0807bde8,
    nop_0807be18,
    FUN_0807be20,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      layer : LAYER_ENEMY,
      special : 0,
      damage : 2,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(10), PIXEL(24), PIXEL(24)},
    },
    {
      kind : DRP,
      layer : LAYER_ENEMY,
      special : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(10), PIXEL(24), PIXEL(24)},
    },
};

static const struct Coord sElementCoord = {PIXEL(0), -PIXEL(8)};
