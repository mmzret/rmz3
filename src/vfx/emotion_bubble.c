#include "entity.h"
#include "vfx.h"
#include "global.h"

/*
  !などの吹き出し
*/

static const motion_t sMotions[3];

static void EmotionBubble_Init(struct VFX* p);
static void EmotionBubble_Update(struct VFX* p);
static void EmotionBubble_Die(struct VFX* p);

// clang-format off
const VFXRoutine gEmotionBubbleRoutine = {
    [ENTITY_INIT] =      EmotionBubble_Init,
    [ENTITY_MAIN] =      EmotionBubble_Update,
    [ENTITY_DIE] =       EmotionBubble_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

static struct VFX* unused_CreateGhost15(u8 n, struct Coord* c) {
  struct VFX* g = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
  if (g != NULL) {
    (g->s).taskCol = 1;
    INIT_VFX_ROUTINE(g, VFX_EMOTION_BUBBLE);
    (g->s).tileNum = 0;
    (g->s).palID = 0;
    ((g->s).coord).x = c->x;
    ((g->s).coord).y = c->y;
    (g->s).work[0] = 0;
    InitNonAffineMotion(&g->s);
    SetMotion(&g->s, sMotions[n]);
  }
  return g;
}

WIP struct VFX* CreateEmotionBubble(u8 kind, struct Coord* target, struct Coord* c) {
#if MODERN
  struct VFX* g = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
  if (g != NULL) {
    bool8 xflip;
    (g->s).taskCol = 1;
    INIT_VFX_ROUTINE(g, VFX_EMOTION_BUBBLE);
    (g->s).tileNum = 0;
    (g->s).palID = 0;
    (g->s).unk_28 = (struct Entity*)target;
    ((g->s).unk_coord).x = c->x;
    ((g->s).unk_coord).y = c->y;
    (g->s).work[0] = 1;
    InitNonAffineMotion(&g->s);
    SetMotion(&g->s, sMotions[kind]);
    xflip = (c->x < 0);
    if (xflip) {
      (g->s).flags |= X_FLIP;
    } else {
      (g->s).flags &= ~X_FLIP;
    }
    (g->s).spr.xflip = xflip;
    (g->s).spr.oam.xflip = xflip;
  }
  return g;
#else
  INCCODE("asm/wip/CreateEmotionBubble.inc");
#endif
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void EmotionBubble_Init(struct VFX* p) {
  (p->s).flags |= DISPLAY;
  (p->s).spr.oam.priority = 0;
  (p->s).work[2] = SECOND;
  SET_VFX_ROUTINE(p, ENTITY_MAIN);
  EmotionBubble_Update(p);
}

static void EmotionBubble_Update(struct VFX* p) {
  UpdateMotionGraphic(&p->s);
  if ((p->s).work[0] != 0) {
    struct Coord* from = (struct Coord*)(p->s).unk_28;
    (p->s).coord.x = from->x + (p->s).unk_coord.x;
    (p->s).coord.y = from->y + (p->s).unk_coord.y;
  }
  if (--(p->s).work[2] == 0) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
  }
}

static void EmotionBubble_Die(struct VFX* p) {
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// ------------------------------------------------------------------------------------------------------------------------------------

static const motion_t sMotions[3] = {
    MOTION(SM003_EMOTION_BUBBLE, 0),
    MOTION(SM003_EMOTION_BUBBLE, 1),
    MOTION(SM003_EMOTION_BUBBLE, 2),
};
