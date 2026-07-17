#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "score.h"

void HellBouncer_Init(struct Enemy* p);
void HellBouncer_Update(struct Enemy* p);
void HellBouncer_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gHellBouncerRoutine = {
    [ENTITY_INIT] =      (void*)HellBouncer_Init,
    [ENTITY_UPDATE] =    (void*)HellBouncer_Update,
    [ENTITY_DIE] =       (void*)HellBouncer_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* createHellBouncer(struct Entity* q, Coords32* c, u8 r2, u8 idx) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_HELL_BOUNCER);
    p->coord = *c;
    p->work[0] = r2, p->work[1] = idx;
    p->unk_28 = q;
  }
  return p;
}

void TryDropZakoDisk(struct Enemy* p, struct Coord* c);

INCASM("asm/enemy/hell_bouncer_a.inc");

void HellBouncer_Die(struct Enemy* p) {
  if (gScore.enemyCount <= 0x270E) {
    gScore.enemyCount++;
  }
  TryDropZakoDisk(p, &(p->s).coord);
  (p->s).flags &= ~DISPLAY;
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
}

bool8 FUN_0807e5f0(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/hell_bouncer_b.inc");

bool8 FUN_0807ead8(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/hell_bouncer_c.inc");

bool8 FUN_0807f644(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/hell_bouncer_d.inc");

bool8 FUN_0807e5f0(struct Enemy* p);
bool8 FUN_0807ead8(struct Enemy* p);
bool8 FUN_0807f644(struct Enemy* p);

static const EnemyFunc sUpdates1[3] = {
    (EnemyFunc)FUN_0807e5f0,
    (EnemyFunc)FUN_0807ead8,
    (EnemyFunc)FUN_0807f644,
};

void FUN_0807e5f4(struct Enemy* p);
void FUN_0807eadc(struct Enemy* p);
void FUN_0807f648(struct Enemy* p);

static const EnemyFunc sUpdates2[3] = {
    (void*)FUN_0807e5f4,
    (void*)FUN_0807eadc,
    (void*)FUN_0807f648,
};

void nop_0807fd1c(struct Body* body, Coords32* c1, Coords32* c2) {}

// 0x08367D98
static const struct Collision sCollisions[9] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(5), -PIXEL(17), PIXEL(58), PIXEL(36)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {-PIXEL(26), -PIXEL(16), PIXEL(20), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(5), -PIXEL(36), PIXEL(37), PIXEL(56)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {-PIXEL(24), -PIXEL(69), PIXEL(22), PIXEL(23)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(5), -PIXEL(33), PIXEL(61), PIXEL(36)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {-PIXEL(22), -PIXEL(27), PIXEL(22), PIXEL(23)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(5), -PIXEL(17), PIXEL(55), PIXEL(23)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {-PIXEL(5), -PIXEL(17), PIXEL(55), PIXEL(23)},
    },
};
