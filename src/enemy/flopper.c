#include "motion.h"
#include "trig.h"
#include "collision.h"
#include "enemy.h"
#include "global.h"

struct FlopperObject {
  COLLISION_OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  Coords32 c;  // 0xB4
  u32 unk_08;
  u8 unk_0c[4];
};
static_assert(sizeof(struct FlopperObject) == sizeof(struct Enemy));

static const struct Collision sCollisions[2];
static const EnemyFunc sUpdates[4];

void Flopper_onCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED);

static void Flopper_Init(struct FlopperObject* p);
static void Flopper_Update(struct FlopperObject* p);
void Flopper_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gFlopperRoutine = {
    [ENTITY_INIT] =      (EnemyFunc)Flopper_Init,
    [ENTITY_UPDATE] =    (EnemyFunc)Flopper_Update,
    [ENTITY_DIE] =       (EnemyFunc)Flopper_Die,
    [ENTITY_DISAPPEAR] = (EnemyFunc)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

static void Flopper_Init(struct FlopperObject* p) {
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  (p->c).x = p->coord.x;
  (p->c).y = p->coord.y;
  INIT_BODY(p, &sCollisions[0], 1, Flopper_onCollision);
  p->flags |= FLIPABLE;
  p->mode[1] = p->work[0];
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  SetSpriteAnimation(p, MOTION(SM022_FLOPPER, 0));
  Flopper_Update(p);
}

static void Flopper_Update(struct FlopperObject* p) {
  if ((p->body).status & (BODY_STATUS_DEAD | BODY_STATUS_B2)) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    p->work[2] = 0;
    EXIT_BODY(p);
    p->flags &= ~DISPLAY;
    p->unk_08 = 0;
    p->work[2] = 0;
    Flopper_Die((void*)p);
    return;
  }

  if (p->mode[3] == 0 && IsFrozen(p)) p->mode[3] = 1;
  if (p->mode[3] != 0) {
    if (p->mode[3] == 1) {
      UpdateSpriteAnimation(p);
      p->mode[3] = 2;
    }
    if (!IsFrozen(p)) p->mode[3] = 0;
    return;
  }
  (sUpdates[p->mode[1]])((void*)p);
}

INCASM("asm/enemy/flopper_a.inc");

void FUN_0806bfdc(struct FlopperObject* p) {
  switch (p->mode[2]) {
    case 0:
      p->unk_08 = 0;
      SetMotion((struct Entity*)p, MOTION(0x16, 0x00));
      p->mode[2]++;
      // fallthrough
    case 1:
      p->coord.y = (p->c).y;
      p->coord.y += SIN(p->unk_08 >> 8) * 45;
      p->unk_08 = (p->unk_08 + 0x200) & 0xFFFF;
      UpdateEntityAnim((struct Entity*)p);
      break;
  }
}

void FUN_0806c04c(struct FlopperObject* p) {
  switch (p->mode[2]) {
    case 0:
      p->unk_08 = 0;
      SetMotion((struct Entity*)p, MOTION(0x16, 0x00));
      p->mode[2]++;
      // fallthrough
    case 1:
      p->coord.x = (p->c).x;
      p->coord.x += SIN(p->unk_08 >> 8) * 45;
      p->unk_08 = (p->unk_08 + 0x200) & 0xFFFF;
      UpdateEntityAnim((struct Entity*)p);
      break;
  }
}

INCASM("asm/enemy/flopper_b.inc");

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      hitzone : 0x01,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1000, 0x1000},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 3,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {0x0000, 0x0000, 0x1000, 0x1000},
    },
};

void FUN_0806bfdc(struct FlopperObject* p);
void FUN_0806c04c(struct FlopperObject* p);
void FUN_0806c0bc(struct Enemy* p);
void FUN_0806c150(struct Enemy* p);

static const EnemyFunc sUpdates[4] = {
    (EnemyFunc)FUN_0806bfdc,
    (EnemyFunc)FUN_0806c04c,
    FUN_0806c0bc,
    FUN_0806c150,
};
