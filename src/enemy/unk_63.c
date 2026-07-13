#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "vfx.h"
#include "zero.h"

static const s16 Coord16_ARRAY_08369f44[4][2];
static const s8 s8_ARRAY_ARRAY_08369f5a[4][2];
static const motion_t sMotions[4];

static void Enemy63_Init(struct Enemy* p);
static void Enemy63_Update(struct Entity* p);
static void Enemy63_Die(struct Entity* p);

// clang-format off
const EnemyRoutine gEnemy63Routine = {
    [ENTITY_INIT] =      (void*)Enemy63_Init,
    [ENTITY_UPDATE] =    (void*)Enemy63_Update,
    [ENTITY_DIE] =       (void*)Enemy63_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void FUN_080949d4(s32 x, s32 y, u8 kind) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_63);
    p->work[0] = 4, p->work[1] = kind;
    (p->coord).x = x, (p->coord).y = y;
    (p->d).x = Coord16_ARRAY_08369f44[kind][0];
    (p->d).y = Coord16_ARRAY_08369f44[kind][1];
    (p->unk_coord).x = PIXEL(3) / 2;
  }
}

void FUN_08094a54(s32 x, s32 y, u8 kind) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_63);
    p->work[0] = 5;
    (p->coord).x = x, (p->coord).y = y;
    (p->d).x = Coord16_ARRAY_08369f44[kind][0] / 2;
    (p->d).y = Coord16_ARRAY_08369f44[kind][1] / 2;
  }
}

// 0x08094ad8
void Enemy63_onCollision(struct Body* body, Coords32* c1, Coords32* c2) {}

// --------------------------------------------

static const u8 sInitModes[6];
static const struct Collision sCollisions[3];

static void Enemy63_Init(struct Enemy* p) {
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = sInitModes[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  INIT_BODY(p, sCollisions, 1, Enemy63_onCollision);
  if ((p->s).work[0] < 4) {
    (p->s).coord.x += PIXEL(s8_ARRAY_ARRAY_08369f5a[(p->s).work[0]][0]);
    (p->s).coord.y += PIXEL(s8_ARRAY_ARRAY_08369f5a[(p->s).work[0]][1]);
    (p->s).work[2] = 30;
  }
  Enemy63_Update((void*)p);
}

// --------------------------------------------

static void nop_08094bcc(void* _);
static void FUN_08094bd0(struct Enemy* p);
static void FUN_08094bf0(struct Enemy* p);

void FUN_08094c80(struct Enemy* p);
void FUN_08094d48(struct Enemy* p);
static void FUN_08094e0c(struct Enemy* p);
static void FUN_08094ea0(struct Enemy* p);

static void Enemy63_Update(struct Entity* p) {
  static const EntityFunc sUpdates1[4] = {
      (void*)nop_08094bcc,
      (void*)FUN_08094bd0,
      (void*)nop_08094bcc,
      (void*)FUN_08094bf0,
  };
  static const EntityFunc sUpdates2[4] = {
      (void*)FUN_08094c80,
      (void*)FUN_08094d48,
      (void*)FUN_08094e0c,
      (void*)FUN_08094ea0,
  };
  (sUpdates1[p->mode[1]])(p);
  (sUpdates2[p->mode[1]])(p);
}

static void Enemy63_Die(struct Entity* p) { SET_ENEMY_ROUTINE(p, ENTITY_EXIT); }

// --------------------------------------------

static void nop_08094bcc(void* _) {}

static void FUN_08094bd0(struct Enemy* p) {
  if ((p->body).status & BODY_STATUS_BINDING) {
    (p->s).mode[1] = 3, (p->s).mode[2] = 0;
  }
}

static void FUN_08094bf0(struct Enemy* p) {
  if (!((p->body).status & BODY_STATUS_BINDING) || ((pZero2->body).status & BODY_STATUS_WHITE)) {
    Coords32 c;
    PlaySound(SE_ICE_BREAK);
    c.x = (p->s).coord.x, c.y = (p->s).coord.y - PIXEL(16);
    FUN_080b7ffc((void*)p, &c, (motion_t*)sMotions, 4);
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
  }
}

INCASM("asm/enemy/unk_63.inc");

static void FUN_08094e0c(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      SetSpriteAnimation(p, MOTION(SM200_SMOKE, 1));
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      (p->s).coord.x += (p->s).d.x;
      (p->s).coord.y += (p->s).d.y;
      UpdateSpriteAnimation(p);
      if (IsSpriteAnimEnd(p)) (p->s).mode[2]++;
      break;
    }
    case 2: {
      (p->s).flags &= ~DISPLAY;
      (p->s).flags &= ~FLIPABLE;
      EXIT_BODY(p);
      SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
      break;
    }
  }
}

// なんかこれ用意したらコンパイル結果が一致した...
static inline void set_unk143_lo() { pZero2->unk_143_lo = 1; }
static inline void clr_unk143_hi() { pZero2->unk_143_hi = 0; }

static void FUN_08094ea0(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      (p->s).renderPrio = 15;
      PlaySound(SE_ICE_40);
      (p->s).work[2] = 0;
      SetDDP(&p->body, &sCollisions[2]);
      SetSpriteAnimation(p, MOTION(SM088_LOCOMO_IF_ICE, 0));
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      set_unk143_lo();
      clr_unk143_hi();
      (p->s).work[2]++;
      if ((p->s).work[2] & 1) {
        (p->s).flags |= DISPLAY;
      } else {
        (p->s).flags &= ~DISPLAY;
      }
      (p->s).coord.x = (pZero2->s).coord.x;
      (p->s).coord.y = (pZero2->s).coord.y;
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

// 0x08369efc
static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      unk_0a : 0x41,
      remaining : 0,
      layer : 1,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(10)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      unk_0a : 0x41,
      remaining : 0,
      layer : 1,
      range : {PIXEL(0), PIXEL(0), PIXEL(64), PIXEL(64)},
    },
};

static const s16 Coord16_ARRAY_08369f44[4][2] = {
    {-(PIXEL(3) / 2), PIXEL(0)},
    {(PIXEL(3) / 2), PIXEL(0)},
    {PIXEL(0), -(PIXEL(3) / 2)},
    {PIXEL(0), (PIXEL(3) / 2)},
};  // 0x08369f44

static const u8 sInitModes[6] = {
    0, 0, 0, 0, 1, 2,
};  // 0x08369f54

static const s8 s8_ARRAY_ARRAY_08369f5a[4][2] = {
    {8, 0},
    {-8, 0},
    {0, 8},
    {0, -8},
};  // 0x08369f5a

static const motion_t sMotions[4] = {
    MOTION(SM088_LOCOMO_IF_ICE, 1),
    MOTION(SM088_LOCOMO_IF_ICE, 2),
    MOTION(SM088_LOCOMO_IF_ICE, 3),
    MOTION(SM088_LOCOMO_IF_ICE, 4),
};  // 0x08369f62
