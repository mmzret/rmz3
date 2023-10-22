#include "boss.h"
#include "collision.h"
#include "global.h"

INCASM("asm/boss/spearook.inc");

void Spearook_Init(struct Boss* p);
void Spearook_Update(struct Boss* p);
void Spearook_Die(struct Boss* p);

// clang-format off
const BossRoutine gSpearookRoutine = {
    [ENTITY_INIT] =      Spearook_Init,
    [ENTITY_UPDATE] =    Spearook_Update,
    [ENTITY_DIE] =       Spearook_Die,
    [ENTITY_DISAPPEAR] = DeleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_08062304(struct Boss* p);
void FUN_08062264(struct Boss* p);
void FUN_0806228c(struct Boss* p);
void FUN_08062268(struct Boss* p);

// clang-format off
static const BossFunc sUpdates1[17] = {
    FUN_08062304,
    FUN_08062264,
    FUN_0806228c,
    FUN_08062264,
    FUN_08062304,
    FUN_0806228c,
    FUN_08062264,
    FUN_08062304,
    FUN_0806228c,
    FUN_08062304,
    FUN_0806228c,
    FUN_0806228c,
    FUN_0806228c,
    FUN_0806228c,
    FUN_08062304,
    FUN_08062268,
    FUN_08062264,
};
// clang-format on

void FUN_08062338(struct Boss* p);
void FUN_080623bc(struct Boss* p);
void FUN_080624b0(struct Boss* p);
void FUN_08062588(struct Boss* p);
void FUN_0806267c(struct Boss* p);
void FUN_08062754(struct Boss* p);
void FUN_08062848(struct Boss* p);
void FUN_0806293c(struct Boss* p);
void FUN_08062a94(struct Boss* p);
void FUN_08062b70(struct Boss* p);
void FUN_08062bb4(struct Boss* p);
void FUN_08062c78(struct Boss* p);
void FUN_08062e30(struct Boss* p);
void FUN_08062fe0(struct Boss* p);
void FUN_08063074(struct Boss* p);
void nop_0806316c(struct Boss* p);
void nop_08063170(struct Boss* p);

// clang-format off
static const BossFunc sUpdates2[17] = {
    FUN_08062338,
    FUN_080623bc,
    FUN_080624b0,
    FUN_08062588,
    FUN_0806267c,
    FUN_08062754,
    FUN_08062848,
    FUN_0806293c,
    FUN_08062a94,
    FUN_08062b70,
    FUN_08062bb4,
    FUN_08062c78,
    FUN_08062e30,
    FUN_08062fe0,
    FUN_08063074,
    nop_0806316c,
    nop_08063170,
};
// clang-format on

// --------------------------------------------

void FUN_08063174(struct Boss* p);
void FUN_080632a0(struct Boss* p);
void FUN_080632f8(struct Boss* p);
void FUN_08063514(struct Boss* p);
void nop_08063510(struct Boss* p);

// clang-format off
static const BossFunc sDeads[5] = {
    FUN_08063174,
    FUN_080632a0,
    FUN_080632f8,
    FUN_08063514,
    nop_08063510,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[17] = {
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
      special : CS_BOSS,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(7), PIXEL(42), PIXEL(17)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(22), PIXEL(20), PIXEL(13)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      remaining : 5,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(46), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      remaining : 4,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(31), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(17), PIXEL(21), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 2,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(46), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 1,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(31), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(17), PIXEL(21), PIXEL(12)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      remaining : 7,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(64), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      remaining : 6,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(46), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      remaining : 5,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(31), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      remaining : 4,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(17), PIXEL(21), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 3,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(64), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 2,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(46), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 1,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(31), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(17), PIXEL(21), PIXEL(12)},
    },
};

static const u8 u8_ARRAY_0836591c[16] = {
    7, 7, 7, 7, 7, 7, 7, 7, 9, 9, 9, 9, 9, 9, 9, 9,
};

static const struct Coord sElementCoord = {PIXEL(0), -PIXEL(16)};
static const u8 sInitModes[4] = {1, 2, 3, 16};

static const u8 u8_ARRAY_08365938[16] = {
    3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 7, 7,
};
