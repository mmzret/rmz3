#include "motion.h"
#include "entity.h"
#include "global.h"
#include "mod.h"
#include "solid.h"

// 改造カードで出現する猫

static void Cat_Init(struct Solid* p);
static void Cat_Update(struct Solid* p);
static void Cat_Die(struct Solid* p);

// clang-format off
const SolidRoutine gCatRoutine = {
    [ENTITY_INIT] =      Cat_Init,
    [ENTITY_UPDATE] =    Cat_Update,
    [ENTITY_DIE] =       Cat_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080dd4fc(struct Solid* p);
void FUN_080dd5e0(struct Solid* p);

static void Cat_Init(struct Solid* p) {
  u8 enabled;
  if ((p->s).work[0] == 0) {
    enabled = FLAG(gSystemSavedata.flags, MOD_ORANGE_CAT);
  } else {
    enabled = FLAG(gSystemSavedata.flags, MOD_TABBY_CAT);
  }
  if (!enabled) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
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

INCASM("asm/solid/cat_a.inc");

void FUN_080dd894(struct Solid* p) {
  UpdateMotionGraphic(&p->s);
  if ((p->s).mode[1] != 0) {
    (p->s).work[2]--;
    if ((p->s).work[2] == 0xFF) {
      SetMotion(&p->s, MOTION(0xd9, 0x00));
      (p->s).mode[1] = 0;
    }
  } else if ((p->s).motion.state == 3) {
    (p->s).work[2] = (RANDOM(RNG_0202f388) & 0x7F) + 0x40;
    (p->s).mode[1]++;
  }
}
