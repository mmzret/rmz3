#include "collision.h"
#include "enemy.h"
#include "global.h"

static const struct Collision sCollisions[2];
static const EnemyFunc sUpdates[4];

void Flopper_onCollision(struct Body *body, struct Coord *r1 UNUSED, struct Coord *r2 UNUSED);

static void Flopper_Init(struct Enemy *p);
static void Flopper_Update(struct Enemy *p);
void Flopper_Die(struct Enemy *p);

// clang-format off
const EnemyRoutine gFlopperRoutine = {
    [ENTITY_INIT] =      Flopper_Init,
    [ENTITY_UPDATE] =    Flopper_Update,
    [ENTITY_DIE] =       Flopper_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

static void Flopper_Init(struct Enemy *p) {
  SET_ZAKO_ROUTINE(p, ENTITY_UPDATE);
  p->props.flopper.c.x = (p->s).coord.x;
  p->props.flopper.c.y = (p->s).coord.y;
  INIT_BODY(p, &sCollisions[0], 1, Flopper_onCollision);
  (p->s).flags |= FLIPABLE;
  (p->s).mode[1] = (p->s).work[0];
  InitNonAffineMotion(&p->s);
  (p->s).flags |= DISPLAY;
  SetMotion(&p->s, MOTION(SM022_FLOPPER, 0x00));
  Flopper_Update(p);
}

static void Flopper_Update(struct Enemy *p) {
  if ((p->body).status & (BODY_STATUS_DEAD | BODY_STATUS_B2)) {
    SET_ZAKO_ROUTINE(p, ENTITY_DIE);
    (p->s).work[2] = 0;
    (p->body).status = 0;
    (p->body).prevStatus = 0;
    (p->body).invincibleTime = 0;
    (p->s).flags &= ~COLLIDABLE;
    (p->s).flags &= ~DISPLAY;
    p->props.flopper.unk_08 = 0;
    (p->s).work[2] = 0;
    Flopper_Die(p);
    return;
  }

  if ((p->s).mode[3] == 0) {
    if (isFrozen(p)) {
      (p->s).mode[3] = 1;
    }
  }

  if ((p->s).mode[3] != 0) {
    if ((p->s).mode[3] == 1) {
      UpdateMotionGraphic(&p->s);
      (p->s).mode[3] = 2;
    }
    if (!isFrozen(p)) {
      (p->s).mode[3] = 0;
    }
    return;
  }
  (sUpdates[(p->s).mode[1]])(p);
}

INCASM("asm/enemy/flopper.inc");

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x01,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {0x0000, 0x0000, 0x1000, 0x1000},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x01,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0000, 0x1000, 0x1000},
    },
};

void FUN_0806bfdc(struct Enemy *p);
void FUN_0806c04c(struct Enemy *p);
void FUN_0806c0bc(struct Enemy *p);
void FUN_0806c150(struct Enemy *p);

static const EnemyFunc sUpdates[4] = {
    FUN_0806bfdc,
    FUN_0806c04c,
    FUN_0806c0bc,
    FUN_0806c150,
};
