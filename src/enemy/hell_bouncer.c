#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/hell_bouncer.inc");

void HellBouncer_Init(struct Enemy* p);
void HellBouncer_Update(struct Enemy* p);
void HellBouncer_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gHellBouncerRoutine = {
    [ENTITY_INIT] =      HellBouncer_Init,
    [ENTITY_UPDATE] =    HellBouncer_Update,
    [ENTITY_DIE] =       HellBouncer_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_0807e5f0(struct Enemy* p);
void FUN_0807ead8(struct Enemy* p);
void FUN_0807f644(struct Enemy* p);

static const EnemyFunc sUpdates1[3] = {
    FUN_0807e5f0,
    FUN_0807ead8,
    FUN_0807f644,
};

void FUN_0807e5f4(struct Enemy* p);
void FUN_0807eadc(struct Enemy* p);
void FUN_0807f648(struct Enemy* p);

static const EnemyFunc sUpdates2[3] = {
    FUN_0807e5f4,
    FUN_0807eadc,
    FUN_0807f648,
};

static const struct Collision sCollisions[9] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(5), -PIXEL(17), PIXEL(58), PIXEL(36)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {-PIXEL(26), -PIXEL(16), PIXEL(20), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(5), -PIXEL(36), PIXEL(37), PIXEL(56)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {-PIXEL(24), -PIXEL(69), PIXEL(22), PIXEL(23)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(5), -PIXEL(33), PIXEL(61), PIXEL(36)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {-PIXEL(22), -PIXEL(27), PIXEL(22), PIXEL(23)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(5), -PIXEL(17), PIXEL(55), PIXEL(23)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {-PIXEL(5), -PIXEL(17), PIXEL(55), PIXEL(23)},
    },
};
