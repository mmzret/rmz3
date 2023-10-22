#include "collision.h"
#include "enemy.h"
#include "global.h"

void HarpuiaMinigameEnemy_Init(struct Enemy* p);
void HarpuiaMinigameEnemy_Update(struct Enemy* p);
void HarpuiaMinigameEnemy_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gHarpuiaMinigameEnemyRoutine = {
    [ENTITY_INIT] =      HarpuiaMinigameEnemy_Init,
    [ENTITY_UPDATE] =    HarpuiaMinigameEnemy_Update,
    [ENTITY_DIE] =       HarpuiaMinigameEnemy_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_0809b350(struct Enemy* p);
void FUN_0809b408(struct Enemy* p);
void FUN_0809b410(struct Enemy* p);
void FUN_0809b418(struct Enemy* p);
void FUN_0809b4d8(struct Enemy* p);
void FUN_0809b950(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[6] = {
    FUN_0809b350,
    FUN_0809b408,
    FUN_0809b410,
    FUN_0809b418,
    FUN_0809b4d8,
    FUN_0809b950,
};
// clang-format on

void FUN_0809b354(struct Enemy* p);
void FUN_0809b40c(struct Enemy* p);
void FUN_0809b414(struct Enemy* p);
void FUN_0809b41c(struct Enemy* p);
void FUN_0809b4dc(struct Enemy* p);
void FUN_0809b954(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[6] = {
    FUN_0809b354,
    FUN_0809b40c,
    FUN_0809b414,
    FUN_0809b41c,
    FUN_0809b4dc,
    FUN_0809b954,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[5] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      damage : 8,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
};
