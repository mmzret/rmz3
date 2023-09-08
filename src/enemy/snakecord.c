#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/snakecord.inc");

void Snakecord_Init(struct Enemy* p);
void Snakecord_Update(struct Enemy* p);
void Snakecord_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gSnakecordRoutine = {
    [ENTITY_INIT] =      Snakecord_Init,
    [ENTITY_MAIN] =      Snakecord_Update,
    [ENTITY_DIE] =       Snakecord_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080746c0(struct Enemy* p);
void FUN_08074618(struct Enemy* p);
void FUN_08074618(struct Enemy* p);
void FUN_0807472c(struct Enemy* p);
void FUN_0807461c(struct Enemy* p);
void FUN_0807465c(struct Enemy* p);

// clang-format off
static const EnemyFunc PTR_ARRAY_08366e30[12] = {
    FUN_080746c0,
    FUN_08074618,
    FUN_08074618,
    FUN_0807472c,
    FUN_0807472c,
    FUN_0807472c,
    FUN_0807472c,
    FUN_0807461c,
    FUN_0807461c,
    FUN_0807465c,
    FUN_08074618,
    FUN_0807472c,
};
// clang-format on

// --------------------------------------------

void snakecord_08074754(struct Enemy* p);
void FUN_080748a8(struct Enemy* p);
void FUN_0807484c(struct Enemy* p);
void FUN_08074ac0(struct Enemy* p);
void FUN_08074bac(struct Enemy* p);
void FUN_08074cb4(struct Enemy* p);
void FUN_08074d18(struct Enemy* p);
void FUN_08074d90(struct Enemy* p);
void FUN_08074e90(struct Enemy* p);
void FUN_08074f34(struct Enemy* p);
void FUN_08075154(struct Enemy* p);
void FUN_08074fcc(struct Enemy* p);

// clang-format off
const EnemyFunc PTR_ARRAY_08366e60[12] = {
    snakecord_08074754,
    FUN_080748a8,
    FUN_0807484c,
    FUN_08074ac0,
    FUN_08074bac,
    FUN_08074cb4,
    FUN_08074d18,
    FUN_08074d90,
    FUN_08074e90,
    FUN_08074f34,
    FUN_08075154,
    FUN_08074fcc,
};
// clang-format on

// --------------------------------------------

void MaybeKillSnakecord(struct Enemy* p);
void FUN_080750f8(struct Enemy* p);
void FUN_08075154(struct Enemy* p);

const EnemyFunc PTR_ARRAY_08366e90[3] = {
    MaybeKillSnakecord,
    FUN_080750f8,
    FUN_08075154,
};

// --------------------------------------------

static const struct Collision sCollisions[] = {
    {
      kind : DRP,
      layer : LAYER_ENEMY,
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
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      layer : LAYER_ENEMY,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-PIXEL(4), PIXEL(0), PIXEL(8), PIXEL(8)},
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
      hitzone : 2,
      hardness : 8,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-PIXEL(4), PIXEL(0), PIXEL(8), PIXEL(8)},
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
      hitzone : 255,
      hardness : 8,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(16)},
    },
    {
      kind : DDP,
      layer : LAYER_ENEMY,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-PIXEL(2), -PIXEL(26), PIXEL(11), PIXEL(10)},
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
      hitzone : 2,
      hardness : 8,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-PIXEL(2), -PIXEL(26), PIXEL(11), PIXEL(10)},
    },
    {
      kind : DDP,
      layer : LAYER_ENEMY,
      special : 0,
      damage : 1,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x21,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-PIXEL(2), -PIXEL(8), PIXEL(11), PIXEL(10)},
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
      hitzone : 2,
      hardness : 8,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-PIXEL(2), -PIXEL(8), PIXEL(11), PIXEL(10)},
    },
    {
      kind : DDP,
      layer : LAYER_ENEMY,
      special : 0,
      damage : 1,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x21,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {-PIXEL(5), -PIXEL(16), PIXEL(64), PIXEL(64)},
    },
    {
      kind : DDP,
      layer : LAYER_ENEMY,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-PIXEL(2), -PIXEL(11), PIXEL(11), PIXEL(10)},
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
      hitzone : 2,
      hardness : 8,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-PIXEL(2), -PIXEL(11), PIXEL(11), PIXEL(10)},
    },
    {
      kind : DDP,
      layer : LAYER_ENEMY,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-PIXEL(2), -PIXEL(3), PIXEL(11), PIXEL(10)},
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
      hitzone : 2,
      hardness : 8,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-PIXEL(2), -PIXEL(3), PIXEL(11), PIXEL(10)},
    },
    {
      kind : DDP,
      layer : LAYER_UNK2,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {-PIXEL(2), -PIXEL(26), PIXEL(11), PIXEL(10)},
    },
};

// --------------------------------------------

static const u8 u8_ARRAY_08366fec[13] = {
    4, 4, 4, 4, 4, 4, 9, 9, 11, 11, 11, 11, 11,
};

static const struct Coord sElementCoords[2] = {
    {PIXEL(0), -PIXEL(24)},
    {PIXEL(0), -PIXEL(16)},
};

static const u8 sInitModes[4] = {1, 2, 0, 0};
