#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/unk_60.inc");

void Enemy60_Init(struct Enemy* p);
void Enemy60_Update(struct Enemy* p);
void Enemy60_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gEnemy60Routine = {
    [ENTITY_INIT] =      Enemy60_Init,
    [ENTITY_UPDATE] =    Enemy60_Update,
    [ENTITY_DIE] =       Enemy60_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_08092980(struct Enemy* p);
void FUN_080929c8(struct Enemy* p);
void FUN_080929e8(struct Enemy* p);
void FUN_0809357c(struct Enemy* p);

static const EnemyFunc sUpdates1[4] = {
    FUN_08092980,
    FUN_080929c8,
    FUN_080929e8,
    FUN_0809357c,
};

void FUN_08092a60(struct Enemy* p);
void FUN_08092aac(struct Enemy* p);
void FUN_08092acc(struct Enemy* p);

static const EnemyFunc sUpdates2[4] = {
    FUN_08092a60,
    FUN_08092aac,
    FUN_08092acc,
    FUN_0809357c,
};

void FUN_08092b54(struct Enemy* p);
void FUN_08092ba0(struct Enemy* p);
void FUN_08092bc0(struct Enemy* p);
void FUN_08092c5c(struct Enemy* p);
void FUN_08092f18(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates3[8] = {
    FUN_08092b54,
    FUN_08092ba0,
    FUN_08092bc0,
    FUN_08092c5c,
    FUN_0809357c,
    FUN_0809357c,
    FUN_0809357c,
    FUN_08092f18,
};
// clang-format on

static const EnemyFunc* const sUpdates[3] = {
    sUpdates1,
    sUpdates2,
    sUpdates3,
};

// --------------------------------------------

void FUN_08092664(struct Enemy* p);
void FUN_08092918(struct Enemy* p);

static const EnemyFunc sDeads[2] = {
    FUN_08092664,
    FUN_08092918,
};

// --------------------------------------------

static const struct Collision sCollisions[24] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(1), PIXEL(24), PIXEL(43)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(39), PIXEL(6), PIXEL(44), PIXEL(48)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(39), PIXEL(6), PIXEL(44), PIXEL(48)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(28), PIXEL(14), PIXEL(35), PIXEL(42)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(28), PIXEL(14), PIXEL(35), PIXEL(42)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(37), -PIXEL(32), PIXEL(48), PIXEL(65)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(37), -PIXEL(32), PIXEL(48), PIXEL(65)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(30)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(28)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(26)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(22)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(12)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(10)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(6)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(4)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(2)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(1)},
    },
};

// clang-format off
static const struct Coord sPixelCoords[11] = {
    {-25, -45},
    {-49, -22},
    {-64, 7},
    {-49, 36},
    {-25, 59},
    {0, -48},
    {38, -18},
    {38, 18},
    {0, 54},
    {-38, 18},
    {-38, -18},
};
// clang-format on
