#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/tile_cannon.inc");

void TileCannon_Init(struct Enemy* p);
void TileCannon_Update(struct Enemy* p);
void TileCannon_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gTileCannonRoutine = {
    [ENTITY_INIT] =      TileCannon_Init,
    [ENTITY_UPDATE] =    TileCannon_Update,
    [ENTITY_DIE] =       TileCannon_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_08078480(struct Enemy* p);
void FUN_0807847c(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[9] = {
    FUN_08078480,
    FUN_0807847c,
    FUN_0807847c,
    FUN_0807847c,
    FUN_0807847c,
    FUN_0807847c,
    FUN_0807847c,
    FUN_0807847c,
    FUN_0807847c,
};
// clang-format on

void FUN_080784b4(struct Enemy* p);
void FUN_080784d8(struct Enemy* p);
void FUN_08078550(struct Enemy* p);
void FUN_080785bc(struct Enemy* p);
void FUN_08078624(struct Enemy* p);
void FUN_08078664(struct Enemy* p);
void FUN_0807874c(struct Enemy* p);
void FUN_0807884c(struct Enemy* p);
void FUN_08078908(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[9] = {
    FUN_080784b4,
    FUN_080784d8,
    FUN_08078550,
    FUN_080785bc,
    FUN_08078624,
    FUN_08078664,
    FUN_0807874c,
    FUN_0807884c,
    FUN_08078908,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[9] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP2,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      hardness : METAL,
      remaining : 1,
      range : {PIXEL(1), PIXEL(0), PIXEL(10), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(8), PIXEL(0), PIXEL(13), PIXEL(17)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {-PIXEL(8), PIXEL(0), PIXEL(13), PIXEL(17)},
    },
    {
      kind : DRP2,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 255,
      hardness : METAL,
      remaining : 1,
      range : {PIXEL(10), PIXEL(0), PIXEL(10), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(1), PIXEL(0), PIXEL(13), PIXEL(17)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {-PIXEL(1), PIXEL(0), PIXEL(13), PIXEL(17)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
};

static const struct Coord sElementCoord = {PIXEL(0), PIXEL(0)};

static const u8 sInitModes[3] = {1, 1, 4};

static const motion_t sMotions[3] = {
    MOTION(SM047_TILE_CANNON, 9),
    MOTION(SM047_TILE_CANNON, 10),
    MOTION(SM047_TILE_CANNON, 11),
};

static const u8 u8_ARRAY_0836754a[6] = {
    0, 0, 0, 1, 4, 4,
};

static const u8 u8_ARRAY_08367550[6] = {
    4, 4, 1, 0, 0, 0,
};
