#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/puffy.inc");

void Puffy_Init(struct Enemy* p);
void Puffy_Update(struct Enemy* p);
void Puffy_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gPuffyRoutine = {
    [ENTITY_INIT] =      Puffy_Init,
    [ENTITY_UPDATE] =    Puffy_Update,
    [ENTITY_DIE] =       Puffy_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void nop_0807c968(struct Enemy* p);
void nop_0807ca98(struct Enemy* p);
void nop_0807cac8(struct Enemy* p);
void nop_0807cad0(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_08367aec[4] = {
    nop_0807c968,
    nop_0807ca98,
    nop_0807cac8,
    nop_0807cad0,
};

void FUN_0807c96c(struct Enemy* p);
void FUN_0807ca9c(struct Enemy* p);
void nop_0807cacc(struct Enemy* p);
void FUN_0807cad4(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_08367afc[4] = {
    FUN_0807c96c,
    FUN_0807ca9c,
    nop_0807cacc,
    FUN_0807cad4,
};

// --------------------------------------------

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      atkType : 0x00,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(6), PIXEL(28), PIXEL(28)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(6), PIXEL(28), PIXEL(28)},
    },
};

static const struct Coord sElementCoord = {PIXEL(0), PIXEL(0)};
