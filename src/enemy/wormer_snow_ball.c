#include "collision.h"
#include "enemy.h"
#include "global.h"

void FUN_0807b7c0(struct Enemy* p);

void FUN_0807b308(struct Enemy* p);

void FUN_0807b30c(struct Enemy* p);

void WormerSnowBall_Update(struct Enemy* p);

static const EnemyFunc sUpdates1[4];
static const EnemyFunc sUpdates2[4];
static const EnemyFunc sDeads[3];

INCASM("asm/enemy/wormer_snow_ball_a.inc");

void nop_0807b1dc(struct Enemy* p) {}

void WormerSnowBall_Die(struct Enemy* p);


static bool8 FUN_0807b1e0(struct Enemy* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    (p->s).mode[1] = (p->s).work[0];
    WormerSnowBall_Die(p);
    return TRUE;
  }
  return FALSE;
}

INCASM("asm/enemy/wormer_snow_ball_b.inc");

extern const EnemyFunc sUpdates1[4];
extern const EnemyFunc sUpdates2[4];

void WormerSnowBall_Update(struct Enemy* p) {
  if (!FUN_0807b1e0(p)) {
    (sUpdates1[(p->s).mode[1]])((void*)p);
    (sUpdates2[(p->s).mode[1]])((void*)p);
  }
}

void WormerSnowBall_Die(struct Enemy* p) {
  (sDeads[(p->s).mode[1]])((void*)p);
}

void FUN_0807b308(struct Enemy* p) {}


void FUN_0807b30c(struct Enemy* p) {
  if ((p->body).status & BODY_STATUS_B2) {
    (p->s).mode[1] = 2;
    (p->s).mode[2] = 0;
  }
}

INCASM("asm/enemy/wormer_snow_ball_c.inc");

void CreateIceballParticle2(s32 x, s32 y);

void FUN_0807b7c0(struct Enemy* p) {
  EXIT_BODY(p);
  CreateIceballParticle2((p->s).coord.x, (p->s).coord.y);
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/enemy/wormer_snow_ball_d.inc");

void WormerSnowBall_Init(struct Enemy* p);
void WormerSnowBall_Update(struct Enemy* p);
void WormerSnowBall_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gWormerSnowBallRoutine = {
    [ENTITY_INIT] =      (void*)WormerSnowBall_Init,
    [ENTITY_UPDATE] =    (void*)WormerSnowBall_Update,
    [ENTITY_DIE] =       (void*)WormerSnowBall_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_0807b30c(struct Enemy* p);
void FUN_0807b308(struct Enemy* p);

static const EnemyFunc sUpdates1[4] = {
    FUN_0807b30c,
    FUN_0807b30c,
    FUN_0807b308,
    FUN_0807b308,
};

void FUN_0807b328(struct Enemy* p);
void FUN_0807b408(struct Enemy* p);
void FUN_0807b494(struct Enemy* p);
void FUN_0807b5b8(struct Enemy* p);

static const EnemyFunc sUpdates2[4] = {
    FUN_0807b328,
    FUN_0807b408,
    FUN_0807b494,
    FUN_0807b5b8,
};

void FUN_0807b7c0(struct Enemy* p);
void FUN_0807b800(struct Enemy* p);

static const EnemyFunc sDeads[3] = {
    FUN_0807b7c0,
    FUN_0807b7c0,
    FUN_0807b800,
};

// --------------------------------------------

static const struct Collision sCollisions[17] = {
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
      faction : FACTION_ENEMY,
      damage : 255,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(12), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(12), PIXEL(12)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
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
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(22), PIXEL(22)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(22), PIXEL(22)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(24), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(24), PIXEL(24)},
    },
};

static const u8 sInitModes[4] = {0, 1, 3, 0};
