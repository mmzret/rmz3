#include "collision.h"
#include "enemy.h"
#include "global.h"

void Cattatank_Init(struct Enemy* p);
void Cattatank_Update(struct Enemy* p);
void Cattatank_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gCattatankRoutine = {
    [ENTITY_INIT] =      Cattatank_Init,
    [ENTITY_UPDATE] =    Cattatank_Update,
    [ENTITY_DIE] =       Cattatank_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void nop_08099090(struct Enemy* p);
void nop_080990d4(struct Enemy* p);
void nop_0809925c(struct Enemy* p);
void nop_080994e8(struct Enemy* p);
void nop_0809973c(struct Enemy* p);
void nop_08099950(struct Enemy* p);
void nop_08099a94(struct Enemy* p);
void nop_08099ce0(struct Enemy* p);
void nop_08099d7c(struct Enemy* p);
void nop_08099d84(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[10] = {
    nop_08099090,
    nop_080990d4,
    nop_0809925c,
    nop_080994e8,
    nop_0809973c,
    nop_08099950,
    nop_08099a94,
    nop_08099ce0,
    nop_08099d7c,
    nop_08099d84,
};
// clang-format on

void cattatank_08099094(struct Enemy* p);
void FUN_080990d8(struct Enemy* p);
void FUN_08099260(struct Enemy* p);
void FUN_080994ec(struct Enemy* p);
void FUN_08099740(struct Enemy* p);
void FUN_08099954(struct Enemy* p);
void FUN_08099a98(struct Enemy* p);
void FUN_08099ce4(struct Enemy* p);
void nop_08099d80(struct Enemy* p);
void FUN_08099d88(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[10] = {
    cattatank_08099094,
    FUN_080990d8,
    FUN_08099260,
    FUN_080994ec,
    FUN_08099740,
    FUN_08099954,
    FUN_08099a98,
    FUN_08099ce4,
    nop_08099d80,
    FUN_08099d88,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[18] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(11), PIXEL(30), PIXEL(22)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 1,
      priorityLayer : 0xFFFFFFFF,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DRP2,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 255,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(12), -PIXEL(21), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 4,
      remaining : 0,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(16), -PIXEL(21), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 4,
      remaining : 0,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(37), -PIXEL(21), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 4,
      remaining : 0,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(49), -PIXEL(21), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 4,
      remaining : 0,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
};

static const struct Coord sElementCoords[1] = {
    {PIXEL(0), -PIXEL(18)},
};
