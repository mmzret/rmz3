#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/hanumachine_obj.inc");

void HanumachineObj_Init(struct Enemy* p);
void HanumachineObj_Update(struct Enemy* p);
void HanumachineObj_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gHanumachineObjRoutine = {
    [ENTITY_INIT] =      HanumachineObj_Init,
    [ENTITY_UPDATE] =    HanumachineObj_Update,
    [ENTITY_DIE] =       HanumachineObj_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_0808693c(struct Enemy* p);
void FUN_080869a0(struct Enemy* p);
void FUN_080869f4(struct Enemy* p);
void FUN_08086a50(struct Enemy* p);
void FUN_08086b6c(struct Enemy* p);
void FUN_08086cbc(struct Enemy* p);
void FUN_08086dcc(struct Enemy* p);
void FUN_08086e34(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates[8] = {
    FUN_0808693c,
    FUN_080869a0,
    FUN_080869f4,
    FUN_08086a50,
    FUN_08086b6c,
    FUN_08086cbc,
    FUN_08086dcc,
    FUN_08086e34,
};
// clang-format on

static const struct Collision sCollisions[6] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(8), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 2,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(8), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(8), PIXEL(26), PIXEL(28)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(8), PIXEL(26), PIXEL(28)},
    },
};
