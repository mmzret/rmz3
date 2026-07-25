#include "zero.h"
#include "motion.h"
#include "global.h"
#include "story.h"
#include "vfx.h"

static void Ghost33_Init(struct Entity* p);
static void Ghost33_Update(struct Entity* p);
static void Ghost33_Die(struct Entity* p);

// clang-format off
const VFXRoutine gGhost33Routine = {
    [ENTITY_INIT] =      (void*)Ghost33_Init,
    [ENTITY_UPDATE] =    (void*)Ghost33_Update,
    [ENTITY_DIE] =       (void*)Ghost33_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* FUN_080bb830(struct Entity* e) {
  struct Entity* p = AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_033);
    p->work[0] = 0;
    p->unk_28 = (void*)e;
  }
}

struct Entity* FUN_080bb878(struct Entity* e) {
  struct Entity* p = AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_033);
    p->work[0] = 1;
    p->unk_28 = (void*)e;
  }
}

struct Entity* FUN_080bb8c0(struct Entity* e) {
  struct Entity* p = AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_033);
    p->work[0] = 2;
    p->unk_28 = (void*)e;
  }
}

void FUN_080bb908(s32 x, s32 y) {
  s32 i;
  for (i = 0; i < 3; i++) {
    struct Entity* p = AllocEntityFirst(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_UNK_033);
      p->work[0] = 3, p->work[1] = i;
      p->coord.x = x, p->coord.y = y;
    }
  }
}

// --------------------------------------------

static const u8 sInitModes[];

static void Ghost33_Init(struct Entity* p) {
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  Ghost33_Update(p);
}

void FUN_080bba18(struct VFX* p);
void FUN_080bba8c(struct VFX* p);
void FUN_080bbb30(struct VFX* p);
void FUN_080bbbd4(struct VFX* p);

static void Ghost33_Update(struct Entity* p) {
  static const VFXFunc sUpdates[4] = {
      (void*)FUN_080bba18,
      (void*)FUN_080bba8c,
      (void*)FUN_080bbb30,
      (void*)FUN_080bbbd4,
  };

  if (IS_METTAUR) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (sUpdates[(p->mode)[1]])((void*)p);
}

static void Ghost33_Die(struct Entity* p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }

// --------------------------------------------

void FUN_080bba18(struct VFX* p) {
  if (((p->s).unk_28)->mode[0] > 1) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
  } else {
    switch ((p->s).mode[2]) {
      case 0:
        SetMotion(&p->s, MOTION(0x28, 0x0d));
        (p->s).mode[2]++;
        // fallthrough
      case 1:
        (p->s).coord.x = (pZero2->s).coord.x;
        (p->s).coord.y = (pZero2->s).coord.y - 0x1000;
        UpdateMotionGraphic(&p->s);
        break;
    }
  }
}

INCASM("asm/vfx/unk_33_a.inc");

// --------------------------------------------

static const u8 sInitModes[4] = {0, 1, 2, 3};

// 0x0836ed64
static const motion_t sMotions[3] = {
    MOTION(SM040_SNAKECORD, 1),
    MOTION(SM040_SNAKECORD, 0),
    MOTION(SM040_SNAKECORD, 0),
};
