#include "collision.h"
#include "element.h"
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

INCASM("asm/enemy/swordy.inc");

static const Coords32 sElementCoord;

bool32 FUN_0807c530(struct Enemy* p) {
  struct Entity** slot = (struct Entity**)((u8*)p + 0xBC);
  struct Entity* e = *slot;
  if (e == NULL && ((p->body).status & BODY_STATUS_WHITE)) {
    struct Entity* n = ApplyElementEffect(0, (void*)p, &sElementCoord);
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

void FUN_0807c230(struct Enemy* p);
void FUN_0807c47c(struct Enemy* p);
void FUN_0807c4ac(struct Enemy* p);
void FUN_0807c4b4(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_08367a38[4] = {
    FUN_0807c230,
    FUN_0807c47c,
    FUN_0807c4ac,
    FUN_0807c4b4,
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
