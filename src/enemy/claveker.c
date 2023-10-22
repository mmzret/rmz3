#include "collision.h"
#include "enemy.h"
#include "global.h"

void Claveker_Init(struct Enemy* p);
void Claveker_Update(struct Enemy* p);
void Claveker_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gClavekerRoutine = {
    [ENTITY_INIT] =      Claveker_Init,
    [ENTITY_UPDATE] =    Claveker_Update,
    [ENTITY_DIE] =       Claveker_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

struct Enemy* CreateClaveker(struct Coord* c, u8 n) {
  struct Enemy* p = (struct Enemy*)AllocEntityFirst(gZakoHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 24;
    INIT_ZAKO_ROUTINE(p, ENEMY_CLAVEKER);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).coord = *c;
    (p->s).work[0] = n;
  }
  return p;
}

INCASM("asm/enemy/claveker.inc");

// --------------------------------------------

void FUN_0808eb20(struct Enemy* p);
void FUN_0808ebb0(struct Enemy* p);
void FUN_0808effc(struct Enemy* p);
void FUN_0808f158(struct Enemy* p);
void FUN_0808f198(struct Enemy* p);
void FUN_0808f1a0(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[6] = {
    FUN_0808eb20,
    FUN_0808ebb0,
    FUN_0808effc,
    FUN_0808f158,
    FUN_0808f198,
    FUN_0808f1a0,
};
// clang-format on

void FUN_0808eb24(struct Enemy* p);
void FUN_0808ebb4(struct Enemy* p);
void FUN_0808f000(struct Enemy* p);
void FUN_0808f15c(struct Enemy* p);
void FUN_0808f19c(struct Enemy* p);
void FUN_0808f1a4(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[6] = {
    FUN_0808eb24,
    FUN_0808ebb4,
    FUN_0808f000,
    FUN_0808f15c,
    FUN_0808f19c,
    FUN_0808f1a4,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(11), PIXEL(30), PIXEL(22)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(11), PIXEL(30), PIXEL(22)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(11), PIXEL(30), PIXEL(22)},
    },
};

static const struct Coord sElementCoord = {PIXEL(0), PIXEL(12)};
