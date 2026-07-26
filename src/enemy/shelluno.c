#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "overworld.h"

struct Enemy* CreateShelluno(struct Coord* c, u8 mode) {
  struct Enemy* p = (struct Enemy*)AllocEntityFirst(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_SHELLUNO);
    (p->s).coord = *c;
    (p->s).work[0] = mode;
  }
  return p;
}

static const EnemyFunc sUpdates1[6];
static const EnemyFunc sUpdates2[6];
static const struct Collision sCollisions[6];

INCASM("asm/enemy/shelluno_a.inc");

extern const EnemyFunc sUpdates1[6];
extern const EnemyFunc sUpdates2[6];
s32 FUN_0807a3e8(struct Enemy* p);
void FUN_0807a244(struct Enemy* p);
void Shelluno_Die(struct Enemy* p);

void Shelluno_Update(struct Enemy* p) {
  u8 m;
  s32 sea;
  if (!((p->body).status & BODY_STATUS_DEAD)) {
    if (FUN_0807a3e8(p)) {
      goto alive;
    }
  }
  SET_ENEMY_ROUTINE(p, ENTITY_DIE);
  Shelluno_Die(p);
  return;

alive:
  (sUpdates1[(p->s).mode[1]])(p);
  FUN_0807a244(p);
  m = (p->s).mode[1];
  if (m == 2) goto water;
  if (m == 4) goto water;
  if (IsFrozen(&p->s)) {
    p->buffer[4] = (p->s).mode[1];
    return;
  }
water:
  sea = gOverworld.sea;
  if (sea > (p->s).coord.y - 0x400) {
    u8* fl = (u8*)((u8*)p + 0xc2);
    if (*fl == 0) {
      (p->s).d.y = 0;
    }
    *fl = 1;
    (p->s).d.y += 0x20;
    if ((p->s).d.y > 0x700) {
      (p->s).d.y = 0x700;
    }
    (p->s).coord.y += (p->s).d.y;
    return;
  } else {
    u8* fl = (u8*)((u8*)p + 0xc2);
    if (*fl == 1) {
      (p->s).mode[1] = 0;
      (p->s).mode[2] = 0;
    }
    *fl = 0;
    (sUpdates2[(p->s).mode[1]])(p);
  }
}

INCASM("asm/enemy/shelluno_b.inc");

bool8 nop_0807939c(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/shelluno_c.inc");

bool8 FUN_080795b8(struct Enemy* p) {
  if (gOverworld.sea > (p->s).coord.y - 0xc00) {
    u8* t = (u8*)((u8*)p + 0xc1);
    s32 zero = 0;
    *t = 0x3c;
    (p->s).d.y = zero;
    (p->s).mode[1] = zero;
    (p->s).mode[2] = zero;
  }
  return TRUE;
}

INCASM("asm/enemy/shelluno_d.inc");

bool8 FUN_0807a018(struct Enemy* p) { return TRUE; }

void FUN_0807a01c(struct Enemy* p) {
  struct Entity** slot;
  if ((p->s).mode[2] == 0) {
    SetDDP(&p->body, &sCollisions[3]);
    (p->s).mode[2]++;
  }
  slot = (struct Entity**)((u8*)p + 0xbc);
  if (isKilled(*slot)) {
    SetDDP(&p->body, &sCollisions[2]);
    *slot = NULL;
    (p->s).mode[1] = 0;
    (p->s).mode[2] = 0;
  }
}

bool8 FUN_0807a064(struct Enemy* p) { return TRUE; }


void FUN_0807a068(struct Enemy* p) {}

bool8 FUN_0807a06c(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/shelluno_e.inc");

bool8 FUN_0807a0fc(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/shelluno_f.inc");

s32 FUN_0807a3e8(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/shelluno_g.inc");

void Shelluno_Init(struct Enemy* p);
void Shelluno_Update(struct Enemy* p);
void Shelluno_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gShellunoRoutine = {
    [ENTITY_INIT] =      Shelluno_Init,
    [ENTITY_UPDATE] =    Shelluno_Update,
    [ENTITY_DIE] =       Shelluno_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

bool8 nop_0807939c(struct Enemy* p);
bool8 FUN_080795b8(struct Enemy* p);
bool8 FUN_0807a018(struct Enemy* p);
bool8 FUN_0807a064(struct Enemy* p);
bool8 FUN_0807a06c(struct Enemy* p);
bool8 FUN_0807a0fc(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[6] = {
    (EnemyFunc)nop_0807939c,
    (EnemyFunc)FUN_080795b8,
    (EnemyFunc)FUN_0807a018,
    (EnemyFunc)FUN_0807a064,
    (EnemyFunc)FUN_0807a06c,
    (EnemyFunc)FUN_0807a0fc,
};
// clang-format on

void shelluno_080793a0(struct Enemy* p);
void FUN_080795f0(struct Enemy* p);
void FUN_0807a01c(struct Enemy* p);
void FUN_0807a068(struct Enemy* p);
void shelluno_0807a070(struct Enemy* p);
void shelluno_0807a100(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[6] = {
    shelluno_080793a0,
    FUN_080795f0,
    FUN_0807a01c,
    FUN_0807a068,
    shelluno_0807a070,
    shelluno_0807a100,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[6] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(7), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(7), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(7), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(7), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(10), PIXEL(18), PIXEL(25)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(10), PIXEL(18), PIXEL(25)},
    },
};

static const Coords32 sElementCoord = {PIXEL(0), -PIXEL(9)};
