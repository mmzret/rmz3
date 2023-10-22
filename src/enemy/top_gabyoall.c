#include "collision.h"
#include "enemy.h"
#include "global.h"

void Enemy14_Init(struct Enemy* p);
void Enemy14_Update(struct Enemy* p);
void Enemy14_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gTopGabyoallRoutine = {
    [ENTITY_INIT] =      Enemy14_Init,
    [ENTITY_UPDATE] =    Enemy14_Update,
    [ENTITY_DIE] =       Enemy14_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

struct Enemy* CreateTopGabyoall(struct Coord* c, u8 r1, u8 r2) {
  struct Enemy* p = (struct Enemy*)AllocEntityFirst(gZakoHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 24;
    INIT_ZAKO_ROUTINE(p, ENEMY_TOP_GABYOALL);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).work[0] = r1;
    (p->s).work[1] = r2;
    (p->s).coord = *c;
    return p;
  } else {
    return NULL;
  }
}

INCASM("asm/enemy/unk_14.inc");

void FUN_0806f5d0(struct Enemy* p);
void FUN_0806f6cc(struct Enemy* p);
void FUN_0806f7dc(struct Enemy* p);
void FUN_0806f89c(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_08366950[4] = {
    FUN_0806f5d0,
    FUN_0806f6cc,
    FUN_0806f7dc,
    FUN_0806f89c,
};

// --------------------------------------------

void FUN_0806f964(struct Enemy* p);
void FUN_0806fb08(struct Enemy* p);
void FUN_0806fc78(struct Enemy* p);
void FUN_0806fe38(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_08366960[4] = {
    FUN_0806f964,
    FUN_0806fb08,
    FUN_0806fc78,
    FUN_0806fe38,
};

// --------------------------------------------

static const struct Collision sCollisions[] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(8), PIXEL(24), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : NO_DAMAGE,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(8), PIXEL(24), PIXEL(12)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(8), PIXEL(12), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : NO_DAMAGE,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(8), PIXEL(12), PIXEL(24)},
    },
};

static const struct Coord sElementCoords[4] = {
    {0x00000000, -0x00000800},
    {0x00000000, -0x00000800},
    {0x00000000, -0x00000800},
    {0x00000000, 0x00000800},
};
