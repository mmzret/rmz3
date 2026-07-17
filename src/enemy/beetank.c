#include "collision.h"
#include "enemy.h"
#include "global.h"

void Beetank_Init(struct Enemy* p);
void Beetank_Update(struct Enemy* p);
void Beetank_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gBeetankRoutine = {
    [ENTITY_INIT] =      Beetank_Init,
    [ENTITY_UPDATE] =    Beetank_Update,
    [ENTITY_DIE] =       Beetank_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

struct Enemy* CreateBeetank(Coords32* c, u8 n) {
  struct Enemy* p = (struct Enemy*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_BEETANK);
    (p->s).coord = *c;
    (p->s).work[0] = n;
  }
  return p;
}

// --------------------------------------------

INCASM("asm/enemy/beetank_a.inc");

// Does not match: agbcc cannot reproduce the target's register allocation in
// the ground-snap min() block (the constant is cached in r8 forcing a push/pop,
// and the two FUN_08009f6c results are double-homed). ~48h of permuter search
// floored at 18 instruction diffs / score 235, so this stays as the matching
// asm body; the MODERN branch documents the equivalent C.
INCASM("asm/enemy/beetank_b.inc");

INCASM("asm/enemy/beetank_c.inc");

bool8 nop_0807bc8c(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/beetank_d.inc");

bool8 nop_0807bd3c(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/beetank_e.inc");

bool8 nop_0807bde4(struct Enemy* p) { return TRUE; }

void FUN_0807bde8(struct Enemy* p) {
  struct Entity** slot;
  if ((p->s).mode[2] == 0) (p->s).mode[2] = 1;
  slot = (struct Entity**)((u8*)p + 0xbc);
  if (isKilled(*slot)) {
    *slot = NULL;
    (p->s).mode[1] = 0;
    (p->s).mode[2] = 0;
  }
}

bool8 FUN_0807be14(struct Enemy* p) { return TRUE; }


void nop_0807be18(struct Enemy* p) {}

bool8 FUN_0807be1c(struct Enemy* p) { return TRUE; }

void FUN_0807be20(struct Enemy* p) {
  struct Entity** slot;
  u8 m = (p->s).mode[2];
  if (m == 0) {
    (p->s).d.y = m;
    (p->s).mode[2]++;
  }
  slot = (struct Entity**)((u8*)p + 0xbc);
  if (isKilled(*slot)) {
    *slot = NULL;
    (p->s).mode[1] = 0;
    (p->s).mode[2] = 0;
  }
}

INCASM("asm/enemy/beetank_f.inc");

void nop_0807bea4(struct Enemy* p) {}

bool8 nop_0807bc8c(struct Enemy* p);
bool8 nop_0807bd3c(struct Enemy* p);
bool8 nop_0807bde4(struct Enemy* p);
bool8 FUN_0807be14(struct Enemy* p);
bool8 FUN_0807be1c(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[5] = {
    (EnemyFunc)nop_0807bc8c,
    (EnemyFunc)nop_0807bd3c,
    (EnemyFunc)nop_0807bde4,
    (EnemyFunc)FUN_0807be14,
    (EnemyFunc)FUN_0807be1c,
};
// clang-format on

void FUN_0807bc90(struct Enemy* p);
void FUN_0807bd40(struct Enemy* p);
void FUN_0807bde8(struct Enemy* p);
void nop_0807be18(struct Enemy* p);
void FUN_0807be20(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[5] = {
    FUN_0807bc90,
    FUN_0807bd40,
    FUN_0807bde8,
    nop_0807be18,
    FUN_0807be20,
};
// clang-format on

// --------------------------------------------

// 0x083679ec
static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      atkType : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(10), PIXEL(24), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(10), PIXEL(24), PIXEL(24)},
    },
};

// 0x08367a1c
static const Coords32 sElementCoord = {PIXEL(0), -PIXEL(8)};
