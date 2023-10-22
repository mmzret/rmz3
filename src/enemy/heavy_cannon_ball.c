#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/heavy_cannon_ball.inc");

void HeavyCannon_Init(struct Enemy* p);
void HeavyCannon_Update(struct Enemy* p);
void HeavyCannon_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gHeavyCannonBallRoutine = {
    [ENTITY_INIT] =      HeavyCannon_Init,
    [ENTITY_UPDATE] =    HeavyCannon_Update,
    [ENTITY_DIE] =       HeavyCannon_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_0807acd0(struct Enemy* p);
void FUN_0807acd0(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_08367774[2] = {
    FUN_0807acd0,
    FUN_0807acd0,
};

void FUN_0807acd4(struct Enemy* p);
void FUN_0807b008(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_0836777c[2] = {
    FUN_0807acd4,
    FUN_0807b008,
};

// --------------------------------------------

static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
};

static const u8 sInitModes[2] = {0, 0};

static const motion_t sMotions[3] = {
    MOTION(SM056_HEAVY_CANNON, 5),
    MOTION(SM056_HEAVY_CANNON, 5),
    MOTION(SM056_HEAVY_CANNON, 5),
};
