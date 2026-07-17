#include "collision.h"
#include "enemy.h"
#include "global.h"

static const EnemyFunc sUpdates[2];

struct Enemy* FUN_0809c3b4(struct Entity* e, struct Coord* c, u16 a2, u8 a3) {
  struct Enemy* p = (struct Enemy*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_72);
    (p->s).coord = *c;
    (p->s).work[0] = a3;
    (p->s).work[1] = 0;
    *(u16*)&p->buffer[0] = a2;
    (p->s).unk_28 = e;
  }
  return p;
}

struct Enemy* FUN_0809c430(struct Entity* e, struct Coord* c) {
  struct Enemy* p = (struct Enemy*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_72);
    (p->s).coord = *c;
    (p->s).work[0] = 0;
    (p->s).work[1] = 1;
    (p->s).unk_28 = e;
  }
  return p;
}

INCASM("asm/enemy/unk_72_a.inc");

void Enemy72_Update(struct Enemy* p) {
  (sUpdates[(p->s).mode[1]])(p);
}

void Enemy72_Die(struct Enemy* p) {
  (p->s).flags &= ~DISPLAY;
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/enemy/unk_72_b.inc");

void Enemy72_Init(struct Enemy* p);
void Enemy72_Update(struct Enemy* p);
void Enemy72_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gEnemy72Routine = {
    [ENTITY_INIT] =      Enemy72_Init,
    [ENTITY_UPDATE] =    Enemy72_Update,
    [ENTITY_DIE] =       Enemy72_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_0809c5bc(struct Enemy* p);
void FUN_0809c664(struct Enemy* p);

static const EnemyFunc sUpdates[2] = {
    FUN_0809c5bc,
    FUN_0809c664,
};

static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(1), -PIXEL(4), PIXEL(26), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 1,
      range : {PIXEL(1), -PIXEL(4), PIXEL(26), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(1), -PIXEL(4), PIXEL(26), PIXEL(14)},
    },
};
