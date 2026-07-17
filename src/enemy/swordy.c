#include "collision.h"
#include "enemy.h"
#include "global.h"

void Swordy_Init(struct Enemy* p);
void Swordy_Update(struct Enemy* p);
void Swordy_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gSwordyRoutine = {
    [ENTITY_INIT] =      (void*)Swordy_Init,
    [ENTITY_UPDATE] =    (void*)Swordy_Update,
    [ENTITY_DIE] =       (void*)Swordy_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* CreateSwordy(Coords32* c, u8 n) {
  struct Entity* p = (struct Entity*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_SWORDY);
    p->coord = *c;
    p->work[0] = n;
  }
  return p;
}

// --------------------------------------------

static const EnemyFunc PTR_ARRAY_08367a38[4];
static const EnemyFunc PTR_ARRAY_08367a48[4];

INCASM("asm/enemy/swordy_a.inc");

extern const EnemyFunc PTR_ARRAY_08367a38[4];
extern const EnemyFunc PTR_ARRAY_08367a48[4];
void FUN_0807c530(struct Enemy* p);
void Swordy_Die(struct Enemy* p);

void Swordy_Update(struct Enemy* p) {
  struct Entity** slot;
  struct Entity* e;
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    Swordy_Die(p);
    return;
  }
  (PTR_ARRAY_08367a38[(p->s).mode[1]])(p);
  FUN_0807c530(p);
  if (IsFrozen(&p->s)) {
    slot = (struct Entity**)((u8*)p + 0xbc);
    e = *slot;
    if (e != NULL) {
      return;
    }
    p->buffer[6] = (p->s).mode[1];
    (p->s).mode[1] = (s32)e;
    (p->s).mode[2] = (s32)e;
    if (isKilled(*slot)) {
      *slot = e;
    }
    return;
  }
  (PTR_ARRAY_08367a48[(p->s).mode[1]])(p);
}

INCASM("asm/enemy/swordy_b.inc");

bool8 FUN_0807c230(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/swordy_c.inc");

bool8 FUN_0807c47c(struct Enemy* p) { return TRUE; }

void FUN_0807c480(struct Enemy* p) {
  struct Entity** slot;
  if ((p->s).mode[2] == 0) (p->s).mode[2] = 1;
  slot = (struct Entity**)((u8*)p + 0xbc);
  if (isKilled(*slot)) {
    *slot = NULL;
    (p->s).mode[1] = 0;
    (p->s).mode[2] = 0;
  }
}

bool8 FUN_0807c4ac(struct Enemy* p) { return TRUE; }


void nop_0807c4b0(struct Enemy* p) {}

bool8 FUN_0807c4b4(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/swordy_d.inc");

bool8 FUN_0807c230(struct Enemy* p);
bool8 FUN_0807c47c(struct Enemy* p);
bool8 FUN_0807c4ac(struct Enemy* p);
bool8 FUN_0807c4b4(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_08367a38[4] = {
    (EnemyFunc)FUN_0807c230,
    (EnemyFunc)FUN_0807c47c,
    (EnemyFunc)FUN_0807c4ac,
    (EnemyFunc)FUN_0807c4b4,
};

void FUN_0807c234(struct Enemy* p);
void FUN_0807c480(struct Enemy* p);
void nop_0807c4b0(struct Enemy* p);
void FUN_0807c4b8(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_08367a48[4] = {
    FUN_0807c234,
    FUN_0807c480,
    nop_0807c4b0,
    FUN_0807c4b8,
};

// --------------------------------------------

// 0x08367a58
static const struct Collision sCollisions[5] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(13), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(13), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(13), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(24), -PIXEL(14), PIXEL(28), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(13), PIXEL(20), PIXEL(20)},
    },
};

// 0x08367ad0
static const Coords32 sElementCoord = {PIXEL(0), -PIXEL(12)};
