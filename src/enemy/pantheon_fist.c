#include "collision.h"
#include "enemy.h"
#include "global.h"

void PantheonFist_Init(struct Enemy* p);
void PantheonFist_Update(struct Enemy* p);
void PantheonFist_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gPantheonFistRoutine = {
    [ENTITY_INIT] =      PantheonFist_Init,
    [ENTITY_UPDATE] =    PantheonFist_Update,
    [ENTITY_DIE] =       PantheonFist_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080953ac(struct Enemy* p);
void FUN_080953b0(struct Enemy* p);
void FUN_080953d0(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[9] = {
    FUN_080953d0,
    FUN_080953b0,
    FUN_080953b0,
    FUN_080953b0,
    FUN_080953b0,
    FUN_080953b0,
    FUN_080953b0,
    FUN_080953ac,
    FUN_080953b0,
};
// clang-format on

void FUN_0809542c(struct Enemy* p);
void FUN_080954a4(struct Enemy* p);
void FUN_08095578(struct Enemy* p);
void FUN_08095664(struct Enemy* p);
void FUN_08095778(struct Enemy* p);
void FUN_080957d4(struct Enemy* p);
void FUN_08095914(struct Enemy* p);
void FUN_0809596c(struct Enemy* p);
void FUN_08095ac4(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[9] = {
    FUN_0809542c,
    FUN_080954a4,
    FUN_08095578,
    FUN_08095664,
    FUN_08095778,
    FUN_080957d4,
    FUN_08095914,
    FUN_0809596c,
    FUN_08095ac4,
};
// clang-format on

// --------------------------------------------

void FUN_08095b70(struct Enemy* p);
void FUN_08095c20(struct Enemy* p);
void FUN_0809596c(struct Enemy* p);

static const EnemyFunc sDeads[3] = {
    FUN_08095b70,
    FUN_08095c20,
    FUN_0809596c,
};

// --------------------------------------------

static const struct Collision sCollisions[6] = {
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
      damage : 3,
      remaining : 1,
      layer : 1,
      range : {-PIXEL(4), -PIXEL(15), PIXEL(19), PIXEL(31)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-PIXEL(4), -PIXEL(15), PIXEL(19), PIXEL(31)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      nature : BODY_NATURE_B2,
      remaining : 1,
      layer : 1,
      range : {-PIXEL(22), -PIXEL(19), PIXEL(26), PIXEL(13)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      nature : BODY_NATURE_B2,
      remaining : 0,
      layer : 1,
      range : {-PIXEL(10), -PIXEL(13), PIXEL(22), PIXEL(19)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      damage : 3,
      remaining : 0,
      layer : 1,
      range : {-PIXEL(4), -PIXEL(15), PIXEL(19), PIXEL(31)},
    },
};

static const struct Coord sElementCoord = {PIXEL(0), -PIXEL(8)};
static const u8 sInitModes[2] = {2, 0};

static const motion_t sMotions[4] = {
    MOTION(SM212_PANTHEON_FIST, 9),
    MOTION(SM212_PANTHEON_FIST, 10),
    MOTION(SM212_PANTHEON_FIST, 11),
    MOTION(SM212_PANTHEON_FIST, 7),
};
