#include "collision.h"
#include "enemy.h"
#include "global.h"

void LemminglesNest_Init(struct Enemy* p);
void LemminglesNest_Update(struct Enemy* p);
void LemminglesNest_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gLemminglesNestRoutine = {
    [ENTITY_INIT] =      (EnemyFunc)LemminglesNest_Init,
    [ENTITY_UPDATE] =    (EnemyFunc)LemminglesNest_Update,
    [ENTITY_DIE] =       (EnemyFunc)LemminglesNest_Die,
    [ENTITY_DISAPPEAR] = (EnemyFunc)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

static void FUN_0806df3c(struct Entity* e) {
  struct Entity* p = AllocEntityFirst(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_LEMMINGLES_NEST);
    (p->coord).x = (e->coord).x, (p->coord).y = (e->coord).y;
    p->unk_28 = (void*)e;
    if (e->work[0] == 0) {
      p->work[0] = 2;
    } else {
      p->work[0] = 3;
    }
  }
}

// --------------------------------------------

void nop_0806e284(struct Enemy* p);

static const EnemyFunc sUpdates1[4] = {
    nop_0806e284,
    nop_0806e284,
    nop_0806e284,
    nop_0806e284,
};  // 0x083667A4

void FUN_0806e288(struct Enemy* p);
static void FUN_0806e518(struct Entity* p);
void FUN_0806e3b0(struct Enemy* p);
void FUN_0806e4bc(struct Enemy* p);

static const EnemyFunc sUpdates2[4] = {
    (void*)FUN_0806e288,
    (void*)FUN_0806e518,
    (void*)FUN_0806e3b0,
    (void*)FUN_0806e4bc,
};  // 0x083667B4

static bool8 FUN_0806dfa4(struct Entity* p) {
  switch (p->mode[3]) {
    case 0: {
      if (IsFrozen(p)) {
        (sUpdates1[p->mode[1]])((void*)p);
        (sUpdates2[p->mode[1]])((void*)p);
        p->mode[3]++;
        UpdateSpriteAnimation(p);
        return TRUE;
      }
      break;
    }
    case 1: {
      if (IsFrozen(p)) return TRUE;
      p->mode[3] = 0;
      break;
    }
  }
  return FALSE;
}

// --------------------------------------------

static const u8 sInitModes[];

INCASM("asm/enemy/lemmingles_nest_a.inc");

void nop_0806e284(struct Enemy* p) {
}

INCASM("asm/enemy/lemmingles_nest_b.inc");

// --------------------------------------------

static void FUN_0806e518(struct Entity* p) {
  struct Entity* q = (void*)p->unk_28;
  switch (p->mode[2]) {
    case 0: {
      p->flags2 |= WHITE_PAINTABLE;
      p->invincibleID = q->uniqueID;
      SetSpriteAnimation(p, MOTION(SM030_LEMMINGLES_NEST, 21));
      SET_XFLIP(p, p->work[0] == 3);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

// 0x083667c4
static const struct Collision sCollisions[3] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(12), PIXEL(24), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3,
      range : {PIXEL(0), -PIXEL(12), PIXEL(24), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : HARDNESS_B3,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
};

// 0x0836680c
static const u8 sInitModes[8] = {0, 0, 1, 1, 0, 0, 0, 0};
