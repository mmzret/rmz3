#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/crossbyne.inc");

void Crossbyne_Init(struct Enemy* p);
void Crossbyne_Update(struct Enemy* p);
void Crossbyne_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gCrossbyneRoutine = {
    [ENTITY_INIT] =      Crossbyne_Init,
    [ENTITY_MAIN] =      Crossbyne_Update,
    [ENTITY_DIE] =       Crossbyne_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_0807cf5c(struct Enemy* p);
void FUN_0807cf60(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[7] = {
    FUN_0807cf60,
    FUN_0807cf5c,
    FUN_0807cf5c,
    FUN_0807cf5c,
    FUN_0807cf5c,
    FUN_0807cf5c,
    FUN_0807cf5c,
};
// clang-format on

void FUN_0807cf88(struct Enemy* p);
void FUN_0807cfac(struct Enemy* p);
void FUN_0807d000(struct Enemy* p);
void crossbyne_0807d080(struct Enemy* p);
void FUN_0807d0f0(struct Enemy* p);
void FUN_0807d178(struct Enemy* p);
void FUN_0807d2b8(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[7] = {
    FUN_0807cf88,
    FUN_0807cfac,
    FUN_0807d000,
    crossbyne_0807d080,
    FUN_0807d0f0,
    FUN_0807d178,
    FUN_0807d2b8,
};
// clang-format on

void MaybeKillCrossbyne(struct Enemy* p);
void FUN_0807d478(struct Enemy* p);
void FUN_0807d5c4(struct Enemy* p);

static const EnemyFunc sDeads[3] = {
    MaybeKillCrossbyne,
    FUN_0807d478,
    FUN_0807d5c4,
};

// --------------------------------------------

static const struct Collision sCollisions[5] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
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
      faction : FACTION_ENEMY,
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
      range : {PIXEL(0), PIXEL(0), PIXEL(28), PIXEL(28)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : 8,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), PIXEL(0), PIXEL(28), PIXEL(28)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
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
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : 8,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
};

static const struct Coord16 Coord16_ARRAY_08367c14[4] = {
    {-PIXEL(14), PIXEL(0)},
    {PIXEL(14), PIXEL(0)},
    {PIXEL(0), -PIXEL(14)},
    {PIXEL(0), PIXEL(14)},
};

static const struct Coord16 Coord16_ARRAY_08367c24[4] = {
    {-PIXEL(9), -PIXEL(9)},
    {PIXEL(9), -PIXEL(9)},
    {-PIXEL(9), PIXEL(9)},
    {PIXEL(9), PIXEL(9)},
};

static const struct Coord sElementCoord = {PIXEL(0), PIXEL(0)};
static const u8 sInitModes[4] = {1, 1, 5, 6};

// clang-format off
static const motion_t sMotions[19] = {
    MOTION(SM067_CROSSBYNE, 0x00),
    MOTION(SM067_CROSSBYNE, 0x01),
    MOTION(SM067_CROSSBYNE, 0x04),
    MOTION(SM067_CROSSBYNE, 0x05),
    MOTION(SM067_CROSSBYNE, 0x10),
    MOTION(SM067_CROSSBYNE, 0x11),
    MOTION(SM067_CROSSBYNE, 0x02),
    MOTION(SM067_CROSSBYNE, 0x03),
    MOTION(SM067_CROSSBYNE, 0x15),
    MOTION(SM067_CROSSBYNE, 0x16),
    MOTION(SM067_CROSSBYNE, 0x17),
    MOTION(SM067_CROSSBYNE, 0x09),
    MOTION(SM067_CROSSBYNE, 0x07),
    MOTION(SM067_CROSSBYNE, 0x0D),
    MOTION(SM067_CROSSBYNE, 0x0B),
    MOTION(SM067_CROSSBYNE, 0x08),
    MOTION(SM067_CROSSBYNE, 0x06),
    MOTION(SM067_CROSSBYNE, 0x0C),
    MOTION(SM067_CROSSBYNE, 0x0A),
};
// clang-format on
