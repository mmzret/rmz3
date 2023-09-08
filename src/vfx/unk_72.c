#include "global.h"
#include "story.h"
#include "vfx.h"

static void Ghost72_Init(struct VFX *p);
void Ghost72_Update(struct VFX *p);
void Ghost72_Die(struct VFX *p);

// clang-format off
const VFXRoutine gGhost72Routine = {
    [ENTITY_INIT] =      Ghost72_Init,
    [ENTITY_MAIN] =      Ghost72_Update,
    [ENTITY_DIE] =       Ghost72_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct VFX *FUN_080c6880(struct Entity *e) {
  struct VFX *p = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 1;
    INIT_VFX_ROUTINE(p, VFX_UNK_072);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).work[0] = 0;
    (p->s).unk_28 = e;
  }
  return p;
}

void FUN_080c68cc(struct Entity *e, struct Coord *c) {
  s32 i;
  for (i = 0; i < 3; i++) {
    struct VFX *p = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
    if (p != NULL) {
      (p->s).taskCol = 1;
      INIT_VFX_ROUTINE(p, VFX_UNK_072);
      (p->s).tileNum = 0;
      (p->s).palID = 0;
      (p->s).work[0] = 1;
      (p->s).work[1] = i;
      (p->s).unk_28 = e;
      (p->s).coord.x = c->x;
      (p->s).coord.y = c->y;
    }
  }
}

void FUN_080c6934(struct Entity *e, u8 n) {
  s32 i;
  for (i = 0; i < 2; i++) {
    struct VFX *p = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
    if (p != NULL) {
      (p->s).taskCol = 1;
      INIT_VFX_ROUTINE(p, VFX_UNK_072);
      (p->s).tileNum = 0;
      (p->s).palID = 0;
      (p->s).work[0] = 2;
      (p->s).work[1] = i;
      (p->s).work[2] = n;
      (p->s).unk_28 = e;
    }
  }
}

// --------------------------------------------

void FUN_080c6a1c(struct VFX *p);
void FUN_080c6b78(struct VFX *p);
void FUN_080c6cd0(struct VFX *p);

static void Ghost72_Init(struct VFX *p) {
  static const VFXFunc sInitializers[3] = {
      FUN_080c6a1c,
      FUN_080c6b78,
      FUN_080c6cd0,
  };
  (sInitializers[(p->s).work[0]])(p);
}

// --------------------------------------------

void FUN_080c6ad8(struct VFX *p);
void FUN_080c6c60(struct VFX *p);
void FUN_080c6dc4(struct VFX *p);

void Ghost72_Update(struct VFX *p) {
  static const VFXFunc sUpdates[3] = {
      FUN_080c6ad8,
      FUN_080c6c60,
      FUN_080c6dc4,
  };
  if (gCurStory.s.elfFlags & METTAUR_ENABLED) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (sUpdates[(p->s).work[0]])(p);
}

// --------------------------------------------

void Ghost72_Die(struct VFX *p) {
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/vfx/unk_72.inc");

// --------------------------------------------

const motion_t motion_t_ARRAY_0836f854[3] = {
    MOTION(0xDB, 0x0B),
    MOTION(0xDB, 0x0B),
    MOTION(0xDB, 0x0C),
};

const motion_t motion_t_ARRAY_0836f85a[2] = {
    MOTION(0xDB, 0x06),
    MOTION(0xDB, 0x07),
};
