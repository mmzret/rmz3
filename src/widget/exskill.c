#include "game.h"
#include "global.h"
#include "widget.h"

#define KIND ((w->s).work[0])

static const motion_t sExIconMotions[12];

static void ExIcon_Init(struct Widget *w);
static void ExIcon_Update(struct Widget *w);
static void ExIcon_Die(struct Widget *w);

// clang-format off
const WidgetRoutine gExIconRoutine = {
    [ENTITY_INIT] =      ExIcon_Init,
    [ENTITY_MAIN] =      ExIcon_Update,
    [ENTITY_DIE] =       ExIcon_Die,
    [ENTITY_DISAPPEAR] = DeleteWidget,
    [ENTITY_EXIT] =      (WidgetFunc)DeleteEntity,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

struct Widget *CreateExSkillIcon(struct GameState *g, u8 kind) {
  struct Widget *w = (struct Widget *)AllocEntityFirst(gWidgetHeaderPtr);
  if (w != NULL) {
    (w->s).taskCol = 16;
    INIT_WIDGET_ROUTINE(w, 6);
    (w->s).tileNum = 0;
    (w->s).palID = 0;
    (w->s).unk_28 = (struct Entity *)g;
    (w->s).work[0] = kind;
    (w->s).work[1] = 0;
  }
  return w;
}

NON_MATCH static void ExIcon_Init(struct Widget *w) {
#if MODERN
  SET_WIDGET_ROUTINE(w, ENTITY_MAIN);
  (w->s).flags |= DISPLAY;
  (w->s).flags |= FLIPABLE;
  (w->s).spr.xflip = FALSE;
  (w->s).spr.oam.xflip = FALSE;
  (w->s).flags &= ~X_FLIP;
  (w->s).coord.x = (u32)(KIND & 3) * PIXEL(24) + PIXEL(16) + PIXEL(256);
  (w->s).coord.y = (u32)(KIND >> 2) * PIXEL(24) + PIXEL(28);
  ExIcon_Update(w);
#else
  INCCODE("asm/wip/ExIcon_Init.inc");
#endif
}

static void ExIcon_Update(struct Widget *w) {
  u8 n;
  struct GameState *g = (struct GameState *)(w->s).unk_28;
  struct Zero *z = g->z2;

  if ((&((g->sceneState).menu).exskill)->inactive) {
    (w->s).flags &= ~DISPLAY;
    (w->s).flags &= ~FLIPABLE;
    SET_WIDGET_ROUTINE(w, ENTITY_DISAPPEAR);
    return;
  }

  if (((&z->unk_b4)->status.exSkill & (1 << KIND)) >> KIND) {
    (w->s).palID = 0;
    InitNonAffineMotion(&w->s);
    SetMotion(&w->s, sExIconMotions[KIND]);
  } else {
    (w->s).palID = 1;
    InitNonAffineMotion(&w->s);
    SetMotion(&w->s, sExIconMotions[KIND]);
  }
  UpdateMotionGraphic(&w->s);
}

static void ExIcon_Die(struct Widget *w) {
  SET_WIDGET_ROUTINE(w, ENTITY_EXIT);
  return;
}

// ------------------------------------------------------------------------------------------------------------------------------------

// clang-format off
static const motion_t sExIconMotions[12] = {
    MOTION(0x45, 0x05),
    MOTION(0x45, 0x04),
    MOTION(0x45, 0x06),
    MOTION(0x45, 0x07),
    MOTION(0x45, 0x03),
    MOTION(0x45, 0x00),
    MOTION(0x45, 0x01),
    MOTION(0x45, 0x02),
    MOTION(0x45, 0x08),
    MOTION(0x45, 0x09),
    MOTION(0x45, 0x0B),
    MOTION(0x45, 0x0A),
};
// clang-format on

#undef KIND
