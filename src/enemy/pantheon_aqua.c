#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/pantheon_aqua.inc");

void PantheonAqua_Init(struct Enemy* p);
void PantheonAqua_Update(struct Enemy* p);
void PantheonAqua_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gPantheonAquaRoutine = {
    [ENTITY_INIT] =      PantheonAqua_Init,
    [ENTITY_UPDATE] =    PantheonAqua_Update,
    [ENTITY_DIE] =       PantheonAqua_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void nop_080726a8(struct Enemy* p);
void FUN_08072800(struct Enemy* p);
void FUN_080729e8(struct Enemy* p);
void FUN_08072e40(struct Enemy* p);
void FUN_08072fac(struct Enemy* p);
void FUN_08072ff8(struct Enemy* p);
void FUN_08073000(struct Enemy* p);
void FUN_080730cc(struct Enemy* p);

// clang-format off
const EnemyFunc PTR_ARRAY_08366bd0[8] = {
    nop_080726a8,
    FUN_08072800,
    FUN_080729e8,
    FUN_08072e40,
    FUN_08072fac,
    FUN_08072ff8,
    FUN_08073000,
    FUN_080730cc,
};
// clang-format on

void FUN_080726ac(struct Enemy* p);
void FUN_08072804(struct Enemy* p);
void FUN_080729ec(struct Enemy* p);
void FUN_08072e44(struct Enemy* p);
void FUN_08072fb0(struct Enemy* p);
void FUN_08072ffc(struct Enemy* p);
void FUN_08073004(struct Enemy* p);
void FUN_080730d0(struct Enemy* p);

// clang-format off
const EnemyFunc PTR_ARRAY_08366bf0[8] = {
    FUN_080726ac,
    FUN_08072804,
    FUN_080729ec,
    FUN_08072e44,
    FUN_08072fb0,
    FUN_08072ffc,
    FUN_08073004,
    FUN_080730d0,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(21), PIXEL(28), PIXEL(36)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(22), PIXEL(30), PIXEL(38)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(21), PIXEL(28), PIXEL(36)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 2,
      range : {PIXEL(0), -PIXEL(22), PIXEL(30), PIXEL(38)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(21), -PIXEL(29), PIXEL(19), PIXEL(9)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {-PIXEL(21), -PIXEL(29), PIXEL(19), PIXEL(9)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(21), PIXEL(28), PIXEL(36)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(22), PIXEL(30), PIXEL(38)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(22), PIXEL(30), PIXEL(38)},
    },
};

static const struct Coord sElementCoord = {PIXEL(0), -PIXEL(23)};
