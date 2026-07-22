#include "collision.h"
#include "enemy.h"
#include "global.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 buffer[16];         // 0xB4
} PantheonFist;
static_assert(sizeof(PantheonFist) == sizeof(struct Enemy));

INCASM("asm/enemy/pantheon_fist.inc");

void PantheonFist_Init(PantheonFist* p);
void PantheonFist_Update(PantheonFist* p);
void PantheonFist_Die(PantheonFist* p);

// clang-format off
const EnemyRoutine gPantheonFistRoutine = {
    [ENTITY_INIT] =      (void*)PantheonFist_Init,
    [ENTITY_UPDATE] =    (void*)PantheonFist_Update,
    [ENTITY_DIE] =       (void*)PantheonFist_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080953ac(PantheonFist* p);
void FUN_080953b0(PantheonFist* p);
void FUN_080953d0(PantheonFist* p);

// clang-format off
static void (*const sUpdates1[9])(PantheonFist*) = {
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

void FUN_0809542c(PantheonFist* p);
void FUN_080954a4(PantheonFist* p);
void FUN_08095578(PantheonFist* p);
void FUN_08095664(PantheonFist* p);
void FUN_08095778(PantheonFist* p);
void FUN_080957d4(PantheonFist* p);
void FUN_08095914(PantheonFist* p);
void FUN_0809596c(PantheonFist* p);
void FUN_08095ac4(PantheonFist* p);

// clang-format off
static void (*const sUpdates2[9])(PantheonFist*) = {
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

void FUN_08095b70(PantheonFist* p);
void FUN_08095c20(PantheonFist* p);
void FUN_0809596c(PantheonFist* p);

static void (*const sDeads[3])(PantheonFist*) = {
    FUN_08095b70,
    FUN_08095c20,
    FUN_0809596c,
};

// --------------------------------------------

// 0x08369fd4
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

static const Coords32 sElementCoord = {PIXEL(0), -PIXEL(8)};
static const u8 sInitModes[2] = {2, 0};

// 0x0836a06e
static const motion_t sMotions[4] = {
    MOTION(SM212_PANTHEON_FIST, 9),
    MOTION(SM212_PANTHEON_FIST, 10),
    MOTION(SM212_PANTHEON_FIST, 11),
    MOTION(SM212_PANTHEON_FIST, 7),
};
