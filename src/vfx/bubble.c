#include "global.h"
#include "vfx.h"

/*
  Bubble in the water
*/

static void Bubble_Init(struct VFX* vfx);
static void Bubble_Update(struct VFX* vfx);
static void Bubble_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gBubbleRoutine = {
    [ENTITY_INIT] =      Bubble_Init,
    [ENTITY_UPDATE] =    Bubble_Update,
    [ENTITY_DIE] =       Bubble_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void CreateBubble(s32 x, s32 y, u8 kind) {
  struct VFX* g = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
  if (g != NULL) {
    (g->s).taskCol = 1;
    INIT_VFX_ROUTINE(g, VFX_BUBBLE);
    (g->s).tileNum = 0;
    (g->s).palID = 0;
    (g->s).work[0] = kind;
    ((g->s).coord).x = x;
    ((g->s).coord).y = y;
  }
}

// --------------------------------------------

void FUN_080b2e50(struct VFX* p);
void FUN_080b2ef0(struct VFX* p);
void FUN_080b2f7c(struct VFX* p);
void FUN_080b3024(struct VFX* p);

static void Bubble_Init(struct VFX* p) {
  static const VFXFunc sInitializers[] = {
      FUN_080b2e50,
      FUN_080b2ef0,
      FUN_080b2f7c,
      FUN_080b3024,
  };
  (sInitializers[(p->s).work[0]])(p);
}

// --------------------------------------------

void FUN_080b30b4(struct VFX* p);
void FUN_080b3144(struct VFX* p);
void FUN_080b31d8(struct VFX* p);
void FUN_080b3278(struct VFX* p);

static void Bubble_Update(struct VFX* p) {
  static const VFXFunc sUpdates[] = {
      FUN_080b30b4,
      FUN_080b3144,
      FUN_080b31d8,
      FUN_080b3278,
  };
  if ((p->props).bubble.unk_4 != 0) {
    if ((p->props).bubble.unk_4-- < 32) {
      if ((p->props).bubble.unk_4 & 1) {
        (p->s).flags |= DISPLAY;
      } else {
        (p->s).flags &= ~DISPLAY;
      }
    }
  } else {
    SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (sUpdates[(p->s).work[0]])(p);
}

static void Bubble_Die(struct VFX* p) {
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/vfx/bubble.inc");
