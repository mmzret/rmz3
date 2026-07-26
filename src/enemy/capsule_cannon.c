#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "element.h"

bool8 FUN_08085c4c(struct Enemy* p);

void CapsuleCannon_Init(struct Enemy* p);
void CapsuleCannon_Update(struct Enemy* p);
void CapsuleCannon_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gCapsuleCannonRoutine = {
    [ENTITY_INIT] =      CapsuleCannon_Init,
    [ENTITY_UPDATE] =    CapsuleCannon_Update,
    [ENTITY_DIE] =       CapsuleCannon_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on


static const struct Collision sCollisions[4];
static const Coords32 sElementCoord;
static const EnemyFunc sUpdates1[6];
static const EnemyFunc sUpdates2[6];
struct Enemy* CreateCapsuleCannon(Coords32* c, u8 n) {
  struct Enemy* p = (struct Enemy*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_CAPSULE_CANNON);
    (p->s).coord = *c;
    (p->s).work[0] = n;
  }
  return p;
}

INCASM("asm/enemy/capsule_cannon_a.inc");

void CapsuleCannon_Update(struct Enemy* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    CapsuleCannon_Die(p);
    return;
  }
  (sUpdates1[(p->s).mode[1]])(p);
  FUN_08085c4c(p);
  if (*(struct Entity**)((u8*)p + 0xbc) == NULL) {
    if (IsFrozen(&p->s)) {
      return;
    }
    if (*(struct Entity**)((u8*)p + 0xbc) == NULL) {
      goto dispatch2;
    }
  }
  if (isKilled(*(struct Entity**)((u8*)p + 0xbc))) {
    if ((p->s).mode[1] == 2) {
      SetDDP(&p->body, &sCollisions[2]);
    } else {
      SetDDP(&p->body, &sCollisions[0]);
    }
    *(struct Entity**)((u8*)p + 0xbc) = NULL;
  }
  return;

dispatch2:
  (sUpdates2[(p->s).mode[1]])(p);
}

INCASM("asm/enemy/capsule_cannon_b.inc");

bool8 FUN_08085a08(struct Enemy* p) { return TRUE; }

void nop_08085a0c(struct Enemy* p) {}

bool8 FUN_08085a10(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/capsule_cannon_c.inc");

bool8 FUN_08085a9c(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/capsule_cannon_d.inc");

bool8 FUN_08085c14(struct Enemy* p) { return TRUE; }

void FUN_08085c18(struct Enemy* p) {
  if ((p->s).mode[2] == 0) {
    (p->s).mode[2] = 1;
  }
}

bool8 FUN_08085c2c(struct Enemy* p) { return TRUE; }

void FUN_08085c30(struct Enemy* p) {}

bool8 FUN_08085c34(struct Enemy* p) { return TRUE; }

void FUN_08085c38(struct Enemy* p) {
  if ((p->s).mode[2] == 0) {
    (p->s).mode[2] = 1;
  }
}

bool8 FUN_08085c4c(struct Enemy* p) {
  struct Entity** slot = (struct Entity**)&p->buffer[8];
  u8 attr;

  if (*slot == NULL && ((p->body).status & 1)) {
    if ((p->s).flags & X_FLIP) {
      *slot = ApplyElementEffect(0, (Object*)p, &sElementCoord);
    } else {
      *slot = ApplyElementEffect(0, (Object*)p, &sElementCoord);
    }
    if (*(struct VFX**)&p->buffer[8] != NULL) {
      attr = *(u8*)((u8*)p + 0x97) & 0xf0;
      if (attr == 0x10) {
        SetDDP(&p->body, &sCollisions[3]);
      } else if (attr == 0x30) {
        SetDDP(&p->body, &sCollisions[3]);
      }
    }
  }
  return TRUE;
}

INCASM("asm/enemy/capsule_cannon_e.inc");

bool8 FUN_08085a08(struct Enemy* p);
bool8 FUN_08085a10(struct Enemy* p);
bool8 FUN_08085a9c(struct Enemy* p);
bool8 FUN_08085c14(struct Enemy* p);
bool8 FUN_08085c2c(struct Enemy* p);
bool8 FUN_08085c34(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[6] = {
    (EnemyFunc)FUN_08085a08,
    (EnemyFunc)FUN_08085a10,
    (EnemyFunc)FUN_08085a9c,
    (EnemyFunc)FUN_08085c14,
    (EnemyFunc)FUN_08085c2c,
    (EnemyFunc)FUN_08085c34,
};
// clang-format on

void nop_08085a0c(struct Enemy* p);
void FUN_08085a14(struct Enemy* p);
void FUN_08085aa0(struct Enemy* p);
void FUN_08085c18(struct Enemy* p);
void FUN_08085c30(struct Enemy* p);
void FUN_08085c38(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[6] = {
    nop_08085a0c,
    FUN_08085a14,
    FUN_08085aa0,
    FUN_08085c18,
    FUN_08085c30,
    FUN_08085c38,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[4] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(7), PIXEL(0), PIXEL(17), PIXEL(29)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {-PIXEL(7), PIXEL(0), PIXEL(17), PIXEL(29)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(7), PIXEL(0), PIXEL(17), PIXEL(29)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {-PIXEL(7), PIXEL(0), PIXEL(17), PIXEL(29)},
    },
};

static const Coords32 sElementCoord = {-PIXEL(8), PIXEL(0)};
