#include "collision.h"
#include "enemy.h"
#include "global.h"

void HeavyCannon_Init(struct Enemy* p);
void HeavyCannon_Update(struct Enemy* p);
void HeavyCannon_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gHeavyCannonBallRoutine = {
    [ENTITY_INIT] =      (void*)HeavyCannon_Init,
    [ENTITY_UPDATE] =    (void*)HeavyCannon_Update,
    [ENTITY_DIE] =       (void*)HeavyCannon_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void CreateHeavyCannonBall(s32 x, s32 y, u8 kind) {
  struct Entity* p = AllocEntityFirst(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_HEAVY_CANNON_BALL);
    p->work[0] = 0, p->work[2] = kind;
    (p->coord).x = x, (p->coord).y = y;
  }
}

INCASM("asm/enemy/heavy_cannon_ball_a.inc");

void FUN_0807acd0(struct Enemy* p) {
}

INCASM("asm/enemy/heavy_cannon_ball_b.inc");

void FUN_0807acd0(struct Enemy* p);
void FUN_0807acd0(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_08367774[2] = {
    (void*)FUN_0807acd0,
    (void*)FUN_0807acd0,
};

void FUN_0807acd4(struct Enemy* p);
void FUN_0807b008(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_0836777c[2] = {
    (void*)FUN_0807acd4,
    (void*)FUN_0807b008,
};

// --------------------------------------------

// 0x08367784
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

// 0x083677CC
static const u8 sInitModes[2] = {0, 0};

static const motion_t sMotions[3] = {
    MOTION(SM056_HEAVY_CANNON, 5),
    MOTION(SM056_HEAVY_CANNON, 5),
    MOTION(SM056_HEAVY_CANNON, 5),
};
