#include "entity.h"
#include "global.h"
#include "solid.h"

// 改造カードで出現する猫

static void Cat_Init(struct Solid* p);
static void Cat_Update(struct Solid* p);
static void Cat_Die(struct Solid* p);

// clang-format off
const SolidRoutine gCatRoutine = {
    [ENTITY_INIT] =      Cat_Init,
    [ENTITY_MAIN] =      Cat_Update,
    [ENTITY_DIE] =       Cat_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080dd4fc(struct Solid* p);
void FUN_080dd5e0(struct Solid* p);

static void Cat_Init(struct Solid* p) {
  u8 enabled;
  if ((p->s).work[0] == 0) {
    enabled = gSystemSavedataManager.mods[3] & (1 << 3);
  } else {
    enabled = gSystemSavedataManager.mods[5] & (1 << 7);
  }
  if (!enabled) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    (p->body).status = 0;
    (p->body).prevStatus = 0;
    (p->body).invincibleTime = 0;
    (p->s).flags &= ~COLLIDABLE;
    SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  if ((p->s).work[0] == 0) {
    FUN_080dd4fc(p);
  } else {
    FUN_080dd5e0(p);
  }
}

// --------------------------------------------

void FUN_080dd69c(struct Solid* p);
void FUN_080dd894(struct Solid* p);

static void Cat_Update(struct Solid* p) {
  if ((p->s).work[0] == 0) {
    FUN_080dd69c(p);
  } else {
    FUN_080dd894(p);
  }
}

// --------------------------------------------

static void Cat_Die(struct Solid* p) { SET_SOLID_ROUTINE(p, ENTITY_EXIT); }

// --------------------------------------------

INCASM("asm/solid/cat.inc");
