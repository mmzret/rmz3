#include "collision.h"
#include "enemy.h"
#include "global.h"

// ReactorCoreに関連

void Enemy61_Init(struct Enemy* p);
void Enemy61_Update(struct Enemy* p);
void Enemy61_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gEnemy61Routine = {
    [ENTITY_INIT] =      (void*)Enemy61_Init,
    [ENTITY_UPDATE] =    (void*)Enemy61_Update,
    [ENTITY_DIE] =       (void*)Enemy61_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void FUN_080935b4(struct Entity* q, u8 idx, u8 val) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_61);
    p->work[0] = 0;
    (p->coord).x = (q->coord).x;
    (p->coord).y = (FUN_08009f6c((q->coord).x, (q->coord).y) - PIXEL(16 * (u32)val)) - PIXEL(28);
    p->work[2] = idx;
    p->unk_28 = (void*)q;
  }
}

// 0x0809362C
static void onCollision(struct Body* body UNUSED, Coords32* c1 UNUSED, Coords32* c2 UNUSED) {}

static const EnemyFunc sUpdates1[1];
static const EnemyFunc sUpdates2[1];

INCASM("asm/enemy/unk_61_a.inc");

void Enemy61_Update(struct Enemy* p) {
  if (((struct Entity*)(p->s).unk_28)->mode[0] > 1) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
  } else {
    (sUpdates1[(p->s).mode[1]])(p);
    (sUpdates2[(p->s).mode[1]])(p);
  }
}

void Enemy61_Die(struct Enemy* p) {
  struct Entity* parent = (p->s).unk_28;
  switch ((p->s).mode[2]) {
    case 0:
      EXIT_BODY(p);
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      if (parent->mode[0] > 2) {
        SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
      }
      break;
  }
}

void FUN_08093754(struct Enemy* p) {}

INCASM("asm/enemy/unk_61_b.inc");

void FUN_08093754(struct Enemy* p);

static const EnemyFunc sUpdates1[1] = {
    FUN_08093754,
};

void FUN_08093758(struct Enemy* p);

static const EnemyFunc sUpdates2[1] = {
    FUN_08093758,
};

// --------------------------------------------

static const struct Collision sCollisions[7] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(36), PIXEL(0), PIXEL(18), PIXEL(23)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(36), PIXEL(0), PIXEL(18), PIXEL(23)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(36), PIXEL(0), PIXEL(18), PIXEL(23)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-PIXEL(36), PIXEL(0), PIXEL(18), PIXEL(23)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(36), PIXEL(0), PIXEL(18), PIXEL(23)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(36), PIXEL(0), PIXEL(18), PIXEL(23)},
    },
};

static const s8 s8_ARRAY_08369de8[24] = {
    -3, -3, -2, -2, -1, -1, 0, 0, 1, 1, 2, 2, 2, 2, 1, 1, 0, 0, -1, -1, -2, -2, -3, -3,
};

static const u8 sInitModes[4] = {0, 0, 0, 0};
