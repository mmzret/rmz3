#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "story.h"
#include "vfx.h"

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

void FUN_0807acd0(struct Enemy* p);
// clang-format on

void CreateHeavyCannonBall(s32 x, s32 y, u8 kind) {
  struct Entity* p = AllocEntityFirst(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_HEAVY_CANNON_BALL);
    p->work[0] = 0, p->work[2] = kind;
    (p->coord).x = x, (p->coord).y = y;
  }
}

static const EnemyFunc PTR_ARRAY_08367774[2];
static const EnemyFunc PTR_ARRAY_0836777c[2];
static const struct Collision sCollisions[3];
static const u8 sInitModes[2];
static const motion_t sMotions[3];

void FUN_0807aae8(struct Body* body, struct Coord* r1, struct Coord* r2) {
  struct Enemy* atk = (struct Enemy*)((body->enemy)->parent);
  struct Enemy* self = (struct Enemy*)body->parent;
  if (body->hitboxFlags & 1) {
    self->buffer[0] = ((atk->s).coord.x - (self->s).coord.x) > 0 ? 1 : 0;
  }
  if (body->hitboxFlags & 4) {
    if ((atk->body).hp == 0) {
      (self->s).work[2] = 0xff;
    }
  }
}

static bool8 FUN_0807ab30(struct Enemy* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    HeavyCannon_Die(p);
    return TRUE;
  }
  return FALSE;
}

void HeavyCannon_Init(struct Enemy* p) {
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = sInitModes[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  INIT_BODY(p, sCollisions, 10, FUN_0807aae8);
  (p->s).renderPrio = 30;
  HeavyCannon_Update(p);
}

static const EnemyFunc PTR_ARRAY_08367774[2];
static const EnemyFunc PTR_ARRAY_0836777c[2];
static const motion_t sMotions[3];

void FUN_080b7f70(struct Enemy* p, struct Coord* c, motion_t* m, s32 n);

void HeavyCannon_Update(struct Enemy* p) {
  if (gCurStory.s.gameflags[4] & 0x40) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
  } else if (!FUN_0807ab30(p)) {
    PTR_ARRAY_08367774[(p->s).mode[1]](p);
    PTR_ARRAY_0836777c[(p->s).mode[1]](p);
  }
}

void HeavyCannon_Die(struct Enemy* p) {
  struct Coord c;
  EXIT_BODY(p);
  (p->s).flags &= ~DISPLAY;
  c.x = (p->s).coord.x;
  c.y = (p->s).coord.y;
  CreateSmoke(1, &c);
  PlaySound(0x2a);
  FUN_080b7f70(p, &c, (motion_t*)sMotions, 3);
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
}

void FUN_0807acd0(struct Enemy* p) {}

INCASM("asm/enemy/heavy_cannon_ball_a.inc");

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
