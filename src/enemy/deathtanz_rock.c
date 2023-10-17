#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/deathtanz_rock.inc");

void DeathtanzRock_Init(struct Enemy* p);
void DeathtanzRock_Update(struct Enemy* p);
void DeathtanzRock_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gDeathtanzRockRoutine = {
    [ENTITY_INIT] =      DeathtanzRock_Init,
    [ENTITY_UPDATE] =    DeathtanzRock_Update,
    [ENTITY_DIE] =       DeathtanzRock_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void nop_0807a6f8(struct Enemy* p);

static const EnemyFunc sUpdates1[3] = {
    nop_0807a6f8,
    nop_0807a6f8,
    nop_0807a6f8,
};

void FUN_0807a6fc(struct Enemy* p);
void FUN_0807a89c(struct Enemy* p);
void FUN_0807a97c(struct Enemy* p);

static const EnemyFunc sUpdates2[3] = {
    FUN_0807a6fc,
    FUN_0807a89c,
    FUN_0807a97c,
};

// --------------------------------------------

void FUN_0807aa34(struct Enemy* p);

static const EnemyFunc sDeads[1] = {
    FUN_0807aa34,
};

// --------------------------------------------

static const struct Collision sCollisions[9] = {
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
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(18), PIXEL(32), PIXEL(44)},
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
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(18), PIXEL(32), PIXEL(44)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(16), PIXEL(32), PIXEL(32)},
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
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(32), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(10), PIXEL(32), PIXEL(24)},
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
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(10), PIXEL(32), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(16)},
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
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(16)},
    },
};

static const s16 s16_ARRAY_0836773c[3] = {
    -0xC00,
    -0x1800,
    -0x2000,
};

static const u8 sInitModes[2] = {0, 1};
static const u8 u8_ARRAY_08367744[4] = {0, 5, 3, 1};

static const motion_t sMotions1[3] = {
    MOTION(SM054_DEATHTANZ_ROCK, 2),
    MOTION(SM054_DEATHTANZ_ROCK, 1),
    MOTION(SM054_DEATHTANZ_ROCK, 0),
};

static const s16 s16_ARRAY_0836774e[3] = {
    -0xC00,
    -0x1800,
    -0x2000,
};

static const u16 u16_ARRAY_08367754[3] = {104, 128, 152};

static const motion_t sMotions2[3] = {
    MOTION(SM054_DEATHTANZ_ROCK, 4),
    MOTION(SM054_DEATHTANZ_ROCK, 5),
    MOTION(SM054_DEATHTANZ_ROCK, 5),
};
