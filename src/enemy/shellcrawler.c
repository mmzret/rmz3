#include "collision.h"
#include "enemy.h"
#include "global.h"

void Shellcrawler_Init(struct Enemy* p);
void Shellcrawler_Update(struct Enemy* p);
void Shellcrawler_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gShellcrawlerRoutine = {
    [ENTITY_INIT] =      Shellcrawler_Init,
    [ENTITY_UPDATE] =    Shellcrawler_Update,
    [ENTITY_DIE] =       Shellcrawler_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

static const struct Collision sCollisions[16] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      nature : BODY_NATURE_B2,
      hitzone : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(10), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      priorityLayer : 0xFFFFFFDF,
      range : {PIXEL(0), -PIXEL(10), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(10), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(10), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {-PIXEL(10), -PIXEL(8), PIXEL(8), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {-PIXEL(10), -PIXEL(8), PIXEL(8), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      nature : BODY_NATURE_B2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(10), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      priorityLayer : 0xFFFFFFDF,
      range : {PIXEL(0), -PIXEL(10), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {-PIXEL(10), -PIXEL(8), PIXEL(8), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {-PIXEL(10), -PIXEL(8), PIXEL(8), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      damage : 2,
      nature : BODY_NATURE_B2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(10), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      priorityLayer : 0xFFFFFFDF,
      range : {PIXEL(0), -PIXEL(10), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(10), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(10), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      priorityLayer : 0xFFFFFFDF,
      range : {PIXEL(0), -PIXEL(10), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      priorityLayer : 0xFFFFFFDF,
      range : {PIXEL(0), -PIXEL(10), PIXEL(20), PIXEL(20)},
    },
};

void FUN_08096438(struct Enemy* p);
void FUN_08096468(struct Enemy* p);
void FUN_08096484(struct Enemy* p);
void FUN_080964bc(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[11] = {
    FUN_08096438,
    FUN_080964bc,
    FUN_08096468,
    FUN_08096484,
    FUN_08096484,
    FUN_08096468,
    FUN_08096484,
    FUN_08096484,
    FUN_08096484,
    FUN_080964bc,
    FUN_080964bc,
};
// clang-format on

void FUN_080964c0(struct Enemy* p);
void FUN_08096570(struct Enemy* p);
void FUN_0809660c(struct Enemy* p);
void FUN_0809664c(struct Enemy* p);
void FUN_080966fc(struct Enemy* p);
void FUN_0809678c(struct Enemy* p);
void FUN_08096814(struct Enemy* p);
void FUN_08096950(struct Enemy* p);
void FUN_080969d0(struct Enemy* p);
void FUN_08096a90(struct Enemy* p);
void FUN_08096eac(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[11] = {
    FUN_080964c0,
    FUN_08096570,
    FUN_0809660c,
    FUN_0809664c,
    FUN_080966fc,
    FUN_0809678c,
    FUN_08096814,
    FUN_08096950,
    FUN_080969d0,
    FUN_08096a90,
    FUN_08096eac,
};
// clang-format on

void FUN_08096b84(struct Enemy* p);
void FUN_08096c28(struct Enemy* p);
void FUN_08096d84(struct Enemy* p);
void FUN_08096eac(struct Enemy* p);

static const EnemyFunc sDeads[4] = {
    FUN_08096b84,
    FUN_08096c28,
    FUN_08096d84,
    FUN_08096eac,
};
