#include "collision.h"
#include "enemy.h"
#include "global.h"

// ブリザック・スタグロフ関連？

typedef struct {
  COLLISION_OBJECT_HDR;   // 0x00
  u8 unk_b4[8];           // 0xB4
  motion_t spriteAnimID;  // 0xBC
  u8 unk_be[6];           // 0xBE
} Enemy42;
static_assert(sizeof(Enemy42) == sizeof(struct Enemy));

static void Enemy42_Init(Enemy42* p);
static void Enemy42_Update(Enemy42* p);
static void Enemy42_Die(Enemy42* p);

// clang-format off
const EnemyRoutine gEnemy42Routine = {
    [ENTITY_INIT] =      (void*)Enemy42_Init,
    [ENTITY_UPDATE] =    (void*)Enemy42_Update,
    [ENTITY_DIE] =       (void*)Enemy42_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* CreateEnemy42(struct Entity* e, u8 type, u8 param_3) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_42);
    p->work[0] = type, p->work[1] = param_3;
    p->unk_28 = e;
    p->coord = *(&e->coord);
    return p;
  } else {
    return NULL;
  }
}

// --------------------------------------------

static void FUN_08084e7c(Enemy42* p);
static void FUN_08084f18(Enemy42* p);
static void FUN_08084fb4(Enemy42* p);

static void Enemy42_Init(Enemy42* p) {
  static void (*const sInitializers[3])(Enemy42*) = {
      FUN_08084e7c,
      FUN_08084f18,
      FUN_08084fb4,
  };
  (sInitializers[(p->work)[0]])((void*)p);
}

void FUN_08085060(Enemy42* p);
void FUN_08085124(Enemy42* p);
void FUN_080852f4(Enemy42* p);

static void Enemy42_Update(Enemy42* p) {
  static void (*const sUpdates[3])(Enemy42*) = {
      FUN_08085060,
      FUN_08085124,
      FUN_080852f4,
  };
  (sUpdates[(p->work)[0]])((void*)p);
}

void FUN_0808534c(Enemy42* p);
void FUN_0808537c(Enemy42* p);
static void FUN_08085578(Enemy42* p);

static void Enemy42_Die(Enemy42* p) {
  static void (*const sDeads[3])(Enemy42*) = {
      FUN_0808534c,
      FUN_0808537c,
      FUN_08085578,
  };
  (sDeads[(p->work)[0]])((void*)p);
}

// --------------------------------------------

static void FUN_08084e7c(Enemy42* p) {
  struct Entity* q = p->unk_28;
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteAnimation(p, p->spriteAnimID);
  p->flags2 |= WHITE_PAINTABLE;
  p->invincibleID = q->uniqueID;
  SET_XFLIP(p, (q->flags & X_FLIP) != 0);
  p->coord = q->coord;
  p->renderPrio = 23;
  p->mode[2] = 1;
  Enemy42_Update(p);
}

static void FUN_08084f18(Enemy42* p) {
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  EnableSpriteAnimation_Normal(p);
  p->flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM098_BLIZZACK_ICE, 9));
  SET_XFLIP(p, p->work[1]);
  (p->coord).x = (p->flags & X_FLIP) ? FUN_0800a22c((p->coord).x, (p->coord).y) : FUN_0800a31c((p->coord).x, (p->coord).y);
  p->work[2] = 0, p->work[3] = 0;
  (p->d).y = 0;
  Enemy42_Update(p);
}

static void FUN_08084fb4(Enemy42* p) {
  struct Entity* q = p->unk_28;
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  EnableSpriteAnimation_Normal(p);
  SetSpriteTableDynamic(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(DM180_BLIZZACK, 13));
  SET_XFLIP(p, p->work[1]);
  p->flags2 |= WHITE_PAINTABLE;
  p->invincibleID = q->uniqueID;
  if (p->flags & X_FLIP) {
    (p->d).x = -PIXEL(1) / 2;
    (p->unk_coord).x = 2;
  } else {
    (p->d).x = PIXEL(1) / 2;
    (p->unk_coord).x = -2;
  }
  p->work[2] = 0;
  Enemy42_Update(p);
}

INCASM("asm/enemy/unk_42_a.inc");

void FUN_080852f4(Enemy42* p) {
  UpdateEntityAnim((struct Entity*)p);
  if (p->mode[3] == 0) {
    p->coord.x += p->d.x;
    p->d.x += p->unk_coord.x;
    if (p->work[2]++ > 0x40) {
      p->mode[3]++;
      p->work[2] = 0;
    }
  } else {
    if ((p->unk_28)->mode[3] > 3) {
      SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
    }
  }
}

void FUN_0808534c(Enemy42* p) {
  EXIT_BODY(p);
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/enemy/unk_42_b.inc");

static void FUN_08085578(Enemy42* p) { SET_ENEMY_ROUTINE(p, ENTITY_EXIT); }

// --------------------------------------------

static const struct Collision sCollisions[6] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(4), -PIXEL(30), PIXEL(8), PIXEL(60)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 4,
      LAYER(0xFFFFFFFF),
      hitzone : 4,
      remaining : 0,
      range : {PIXEL(4), -PIXEL(30), PIXEL(8), PIXEL(60)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(8), -PIXEL(29), PIXEL(16), PIXEL(62)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 4,
      LAYER(0xFFFFFFFF),
      hitzone : 4,
      remaining : 0,
      range : {PIXEL(8), -PIXEL(29), PIXEL(16), PIXEL(62)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(11), -PIXEL(28), PIXEL(22), PIXEL(64)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 4,
      LAYER(0xFFFFFFFF),
      hitzone : 4,
      remaining : 0,
      range : {PIXEL(11), -PIXEL(28), PIXEL(22), PIXEL(64)},
    },
};
