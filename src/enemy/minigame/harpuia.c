#include "collision.h"
#include "enemy.h"
#include "global.h"


static const EnemyFunc sUpdates1[6];
static const EnemyFunc sUpdates2[6];
struct Enemy* FUN_0809af20(struct Entity* e, struct Coord* c, u8 a2) {
  struct Enemy* p = (struct Enemy*)AllocEntityFirst(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_HARPUIA_MG);
    (p->s).coord = *c;
    (p->s).work[0] = 0;
    (p->s).work[1] = a2;
    (p->s).unk_28 = e;
  }
  return p;
}

struct Enemy* FUN_0809af88(struct Entity* e, struct Coord* c, u8 a2) {
  struct Enemy* p = (struct Enemy*)AllocEntityFirst(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_HARPUIA_MG);
    (p->s).coord = *c;
    (p->s).work[0] = 1;
    (p->s).work[1] = a2;
    (p->s).unk_28 = e;
  }
  return p;
}

struct Enemy* FUN_0809aff0(struct Entity* e, struct Coord* c, u8 a2, u8 a3) {
  struct Enemy* p = (struct Enemy*)AllocEntityFirst(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_HARPUIA_MG);
    (p->s).coord = *c;
    (p->s).work[0] = 2;
    (p->s).work[1] = a2;
    p->buffer[0] = a3;
    (p->s).unk_28 = e;
  }
  return p;
}

struct Enemy* FUN_0809b064(struct Entity* e, struct Coord* c, u8 a2, u8 a3) {
  struct Enemy* p = (struct Enemy*)AllocEntityFirst(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_HARPUIA_MG);
    (p->s).coord = *c;
    (p->s).work[0] = 3;
    (p->s).work[1] = a2;
    p->buffer[0] = a3;
    (p->s).unk_28 = e;
  }
  return p;
}

INCASM("asm/enemy/minigame_harpuia_a.inc");

void HarpuiaMinigameEnemy_Update(struct Enemy* p) {
  (sUpdates1[(p->s).mode[1]])(p);
  (sUpdates2[(p->s).mode[1]])(p);
}

void HarpuiaMinigameEnemy_Die(struct Enemy* p) {
  (p->s).flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
  (p->s).mode[1] = 0;
  (p->s).mode[2] = 0;
  (p->s).mode[3] = 0;
}

bool8 FUN_0809b350(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/minigame_harpuia_b.inc");

bool8 FUN_0809b408(struct Enemy* p) { return TRUE; }

void FUN_0809b40c(struct Enemy* p) {}

bool8 FUN_0809b410(struct Enemy* p) { return TRUE; }

void FUN_0809b414(struct Enemy* p) {}

bool8 FUN_0809b418(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/minigame_harpuia_c.inc");

bool8 FUN_0809b4d8(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/minigame_harpuia_d.inc");

bool8 FUN_0809b950(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/minigame_harpuia_e.inc");

void HarpuiaMinigameEnemy_Init(struct Enemy* p);
void HarpuiaMinigameEnemy_Update(struct Enemy* p);
void HarpuiaMinigameEnemy_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gHarpuiaMinigameEnemyRoutine = {
    [ENTITY_INIT] =      HarpuiaMinigameEnemy_Init,
    [ENTITY_UPDATE] =    HarpuiaMinigameEnemy_Update,
    [ENTITY_DIE] =       HarpuiaMinigameEnemy_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

bool8 FUN_0809b350(struct Enemy* p);
bool8 FUN_0809b408(struct Enemy* p);
bool8 FUN_0809b410(struct Enemy* p);
bool8 FUN_0809b418(struct Enemy* p);
bool8 FUN_0809b4d8(struct Enemy* p);
bool8 FUN_0809b950(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[6] = {
    FUN_0809b350,
    FUN_0809b408,
    FUN_0809b410,
    FUN_0809b418,
    FUN_0809b4d8,
    FUN_0809b950,
};
// clang-format on

void FUN_0809b354(struct Enemy* p);
void FUN_0809b40c(struct Enemy* p);
void FUN_0809b414(struct Enemy* p);
void FUN_0809b41c(struct Enemy* p);
void FUN_0809b4dc(struct Enemy* p);
void FUN_0809b954(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[6] = {
    FUN_0809b354,
    FUN_0809b40c,
    FUN_0809b414,
    FUN_0809b41c,
    FUN_0809b4dc,
    FUN_0809b954,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[5] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      damage : 8,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
};
