#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "overworld.h"
#include "element.h"

bool32 FUN_0807cb50(struct Enemy* p);

void Puffy_Init(struct Enemy* p);
void Puffy_Update(struct Enemy* p);
void Puffy_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gPuffyRoutine = {
    [ENTITY_INIT] =      (void*)Puffy_Init,
    [ENTITY_UPDATE] =    (void*)Puffy_Update,
    [ENTITY_DIE] =       (void*)Puffy_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on


static const EnemyFunc PTR_ARRAY_08367aec[4];
static const EnemyFunc PTR_ARRAY_08367afc[4];
static const Coords32 sElementCoord;
struct Entity* CreatePuffy(Coords32* c, u8 kind) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_PUFFY);
    p->coord = *c;
    p->work[0] = kind;
  }
  return p;
}

// --------------------------------------------

static const struct Collision sCollisions[];

INCASM("asm/enemy/puffy_a.inc");

void Puffy_Update(struct Enemy* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    Puffy_Die(p);
  } else {
    (PTR_ARRAY_08367aec[(p->s).mode[1]])(p);
    FUN_0807cb50(p);
    if (IsFrozen(&p->s)) {
      u8 m = (p->s).mode[1];
      *(u8*)((u8*)p + 0xba) = m;
    } else {
      (PTR_ARRAY_08367afc[(p->s).mode[1]])(p);
    }
  }
}

INCASM("asm/enemy/puffy_b.inc");

bool8 nop_0807c968(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/puffy_c.inc");

bool8 nop_0807ca98(struct Enemy* p) { return TRUE; }

void FUN_0807ca9c(struct Enemy* p) {
  struct Entity** slot;
  if ((p->s).mode[2] == 0) (p->s).mode[2] = 1;
  slot = (struct Entity**)((u8*)p + 0xbc);
  if (isKilled(*slot)) {
    *slot = NULL;
    (p->s).mode[1] = 0;
    (p->s).mode[2] = 0;
  }
}

bool8 nop_0807cac8(struct Enemy* p) { return TRUE; }

void nop_0807cacc(struct Enemy* p) {}

bool8 nop_0807cad0(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/puffy_d.inc");

bool32 FUN_0807cb50(struct Enemy* p) {
  struct Entity** slot = (struct Entity**)((u8*)p + 0xBC);
  struct Entity* e = *slot;
  if (e == NULL && ((p->body).status & BODY_STATUS_WHITE)) {
    struct Entity* n = ApplyElementEffect(0, (Object*)p, &sElementCoord);
    *slot = n;
    if (n != NULL) {
      u8 b = *((u8*)p + 0x97) & 0xF0;
      if (b == 0x10) {
        // e is provably NULL here; stored through it to keep the register
        (p->s).mode[1] = 1, (p->s).mode[2] = (u32)e;
      } else if (b == 0x30) {
        (p->s).mode[1] = 3, (p->s).mode[2] = (u32)e;
      }
    }
  }
  return TRUE;
}

void FUN_0807cba4(struct Body* body) {
  struct Enemy* parent = (struct Enemy*)body->parent;
  if ((*(u32*)((u8*)parent + 0x8c) & 0x200) && (gCollisionManager.sweep & 2)) {
    *(u8*)((u8*)parent + 0xc0) = 0;
  }
}

int dragInSea(struct Entity* p) {
  s32 sea = gOverworld.sea;
  if (sea > p->coord.y) {
    p->coord.y = sea;
  }
}

bool8 nop_0807c968(struct Enemy* p);
bool8 nop_0807ca98(struct Enemy* p);
bool8 nop_0807cac8(struct Enemy* p);
bool8 nop_0807cad0(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_08367aec[4] = {
    (EnemyFunc)nop_0807c968,
    (EnemyFunc)nop_0807ca98,
    (EnemyFunc)nop_0807cac8,
    (EnemyFunc)nop_0807cad0,
};

void FUN_0807c96c(struct Enemy* p);
void FUN_0807ca9c(struct Enemy* p);
void nop_0807cacc(struct Enemy* p);
void FUN_0807cad4(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_08367afc[4] = {
    FUN_0807c96c,
    FUN_0807ca9c,
    nop_0807cacc,
    FUN_0807cad4,
};

// --------------------------------------------

// 0x08367b0c
static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      atkType : 0x00,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(6), PIXEL(28), PIXEL(28)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(6), PIXEL(28), PIXEL(28)},
    },
};

// 0x08367b3c
static const Coords32 sElementCoord = {PIXEL(0), PIXEL(0)};
