#include "collision.h"
#include "enemy.h"
#include "global.h"

void Swordy_Init(struct Enemy* p);
void Swordy_Update(struct Enemy* p);
void Swordy_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gSwordyRoutine = {
    [ENTITY_INIT] =      Swordy_Init,
    [ENTITY_MAIN] =      Swordy_Update,
    [ENTITY_DIE] =       Swordy_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_0807c230(struct Enemy* p);
void FUN_0807c47c(struct Enemy* p);
void FUN_0807c4ac(struct Enemy* p);
void FUN_0807c4b4(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_08367a38[4] = {
    FUN_0807c230,
    FUN_0807c47c,
    FUN_0807c4ac,
    FUN_0807c4b4,
};

void FUN_0807c234(struct Enemy* p);
void FUN_0807c480(struct Enemy* p);
void nop_0807c4b0(struct Enemy* p);
void FUN_0807c4b8(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_08367a48[4] = {
    FUN_0807c234,
    FUN_0807c480,
    nop_0807c4b0,
    FUN_0807c4b8,
};

// --------------------------------------------

static const struct Collision sCollisions[5] = {
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
      range : {PIXEL(0), -PIXEL(13), PIXEL(20), PIXEL(20)},
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
      hitzone : 3,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(13), PIXEL(20), PIXEL(20)},
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
      remaining : 2,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(13), PIXEL(20), PIXEL(20)},
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
      range : {-PIXEL(24), -PIXEL(14), PIXEL(28), PIXEL(8)},
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
      hitzone : 3,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(13), PIXEL(20), PIXEL(20)},
    },
};

static const struct Coord sElementCoord = {PIXEL(0), -PIXEL(12)};

// ./tools/dumper/bin.ts baserom.gba 0x08367ad8 0x0836a90c data/zako.bin
INCBIN("data/zako.bin");
