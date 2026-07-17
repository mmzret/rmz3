#include "entity.h"
#include "global.h"
#include "mod.h"
#include "solid.h"
#include "syssav.h"

typedef struct {
  COLLISION_OBJECT_HDR;
  s32 unk_b4_x;   // 0xB4
  u8 unk_b8[12];  // 0xB8
} Seagulls;
static_assert(sizeof(Seagulls) == sizeof(struct Solid));

static void Seagulls_Init(Seagulls* p);
static void Seagulls_Update(Seagulls* p);
static void Seagulls_Die(Seagulls* p);

// clang-format off
const SolidRoutine gSeagullsRoutine = {
    [ENTITY_INIT] =      (void*)Seagulls_Init,
    [ENTITY_UPDATE] =    (void*)Seagulls_Update,
    [ENTITY_DIE] =       (void*)Seagulls_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* CreateSeagulls(struct Entity* q, u8 t, u8 param_3) {
  struct Entity* p = AllocEntityLast(gSolidHeaderPtr);
  if (p != NULL) {
    INIT_SOLID_ROUTINE(p, SOLID_SEAGULLS);
    p->unk_28 = (void*)q;
    p->coord = q->coord;
    p->work[0] = t, p->work[1] = param_3;
  }
  return p;
}

static void FUN_080dcd20(Seagulls* p);
void FUN_080dcdac(Seagulls* p);
void FUN_080dced4(Seagulls* p);

static void Seagulls_Init(Seagulls* p) {
  switch (p->work[0]) {
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

void FUN_080dd02c(Seagulls* p);
void FUN_080dd11c(Seagulls* p);
void FUN_080dd364(Seagulls* p);

static void Seagulls_Update(Seagulls* p) {
  switch (p->work[0]) {
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

void FUN_080dd400(Seagulls* p);
void FUN_080dd418(Seagulls* p);
void FUN_080dd430(Seagulls* p);

static void Seagulls_Die(Seagulls* p) {
  switch (p->work[0]) {
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

// --------------------------------------------

static void FUN_080dcd20(Seagulls* p) {
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  if (!FLAG(gSystemSavedata.flags, MOD_SEAGULLS)) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  p->unk_2c = (void*)CreateSeagulls((void*)p, 1, 0);
  p->unk_b4_x = p->coord.x;
  p->work[2] = 0, p->work[3] = 0;
  Seagulls_Update(p);
}

INCASM("asm/solid/seagulls_a.inc");

void FUN_080dd400(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}


void FUN_080dd418(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}


void FUN_080dd430(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}
