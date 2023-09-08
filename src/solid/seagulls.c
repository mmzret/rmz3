#include "entity.h"
#include "global.h"
#include "solid.h"
#include "syssav.h"

static void Seagulls_Init(struct Solid* p);
static void Seagulls_Update(struct Solid* p);
static void Seagulls_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSeagullsRoutine = {
    [ENTITY_INIT] =      Seagulls_Init,
    [ENTITY_MAIN] =      Seagulls_Update,
    [ENTITY_DIE] =       Seagulls_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

struct Solid* CreateSeagulls(struct Solid* friend, u8 t, u8 param_3) {
  struct Solid* p = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 30;
    INIT_SOLID_ROUTINE(p, SOLID_SEAGULLS);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= ENTITY_FLAGS2_B4;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).unk_28 = &friend->s;
    (p->s).coord = (friend->s).coord;
    (p->s).work[0] = t;
    (p->s).work[1] = param_3;
  }
  return p;
}

void FUN_080dcd20(struct Solid* p);
void FUN_080dcdac(struct Solid* p);
void FUN_080dced4(struct Solid* p);

static void Seagulls_Init(struct Solid* p) {
  switch ((p->s).work[0]) {
    case 0: {
      FUN_080dcd20(p);
      break;
    }
    case 1: {
      FUN_080dcdac(p);
      break;
    }
    case 2: {
      FUN_080dced4(p);
      break;
    }
  }
}

void FUN_080dd02c(struct Solid* p);
void FUN_080dd11c(struct Solid* p);
void FUN_080dd364(struct Solid* p);

static void Seagulls_Update(struct Solid* p) {
  switch ((p->s).work[0]) {
    case 0: {
      FUN_080dd02c(p);
      break;
    }
    case 1: {
      FUN_080dd11c(p);
      break;
    }
    case 2: {
      FUN_080dd364(p);
      break;
    }
  }
}

void FUN_080dd400(struct Solid* p);
void FUN_080dd418(struct Solid* p);
void FUN_080dd430(struct Solid* p);

static void Seagulls_Die(struct Solid* p) {
  switch ((p->s).work[0]) {
    case 0: {
      FUN_080dd400(p);
      break;
    }
    case 1: {
      FUN_080dd418(p);
      break;
    }
    case 2: {
      FUN_080dd430(p);
      break;
    }
  }
}

INCASM("asm/solid/seagulls.inc");
