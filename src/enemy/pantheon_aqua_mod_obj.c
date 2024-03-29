#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/pantheon_aqua_mod_obj.inc");

void PantheonAquaModObj_Init(struct Enemy* p);
void PantheonAquaModObj_Update(struct Enemy* p);
void PantheonAquaModObj_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gPantheonAquaModObjRoutine = {
    [ENTITY_INIT] =      PantheonAquaModObj_Init,
    [ENTITY_UPDATE] =    PantheonAquaModObj_Update,
    [ENTITY_DIE] =       PantheonAquaModObj_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_08080fe8(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[10] = {
    FUN_08080fe8,
    FUN_08080fe8,
    FUN_08080fe8,
    FUN_08080fe8,
    FUN_08080fe8,
    FUN_08080fe8,
    FUN_08080fe8,
    FUN_08080fe8,
    FUN_08080fe8,
    FUN_08080fe8,
};
// clang-format on

void FUN_08080fec(struct Enemy* p);
void FUN_08081208(struct Enemy* p);
void FUN_08081438(struct Enemy* p);
void FUN_080817a8(struct Enemy* p);
void FUN_080818b8(struct Enemy* p);
void FUN_08081990(struct Enemy* p);
void FUN_08081d2c(struct Enemy* p);
void FUN_08081e00(struct Enemy* p);
void FUN_08081fc4(struct Enemy* p);
void FUN_080820b8(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[10] = {
    FUN_08080fec,
    FUN_08081208,
    FUN_08081438,
    FUN_080817a8,
    FUN_080818b8,
    FUN_08081990,
    FUN_08081d2c,
    FUN_08081e00,
    FUN_08081fc4,
    FUN_080820b8,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[10] = {
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
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      unk_0a : 0x41,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      nature : BODY_NATURE_B2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      unk_0a : 0x41,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(64), PIXEL(64)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      nature : BODY_NATURE_B2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(22), PIXEL(22)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(22), PIXEL(22)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      nature : BODY_NATURE_B2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      unk_0a : 0x41,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), -PIXEL(128), -PIXEL(128)},
    },
};

static const u8 sInitModes[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

// clang-format off
static const motion_t sMotions[8] = {
    MOTION(SM079_PANTHEON_AQUA_MOD_ROCK, 1),
    MOTION(SM079_PANTHEON_AQUA_MOD_ROCK, 2),
    MOTION(SM079_PANTHEON_AQUA_MOD_ROCK, 2),
    MOTION(SM039_PANTHEON_AQUA, 10),
    MOTION(SM039_PANTHEON_AQUA, 19),
    MOTION(SM039_PANTHEON_AQUA, 20),
    MOTION(SM039_PANTHEON_AQUA, 21),
    MOTION(SM039_PANTHEON_AQUA, 22),
};
// clang-format on

static const u8 u8_ARRAY_ARRAY_0836810a[3][3] = {
    {0x3F, 0x3F, 0x3F},
    {0x3F, 0x0A, 0x3F},
    {0x3F, 0x0A, 0x3F},
};
