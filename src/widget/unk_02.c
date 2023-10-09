#include "game.h"
#include "global.h"
#include "motion.h"
#include "widget.h"

static const motion_t motion_t_ARRAY_08372044[2];
static void MenuComp2_Update(struct Widget *w);

struct Widget *CreateMenuComp2(struct GameState *g, u8 kind, u8 r2) {
  struct Widget *w = (struct Widget *)AllocEntityFirst(gWidgetHeaderPtr);
  if (w != NULL) {
    (w->s).taskCol = 16;
    INIT_WIDGET_ROUTINE(w, 2);
    (w->s).tileNum = 0;
    (w->s).palID = 0;
    (w->s).unk_28 = (struct Entity *)g;
    (w->s).work[0] = kind;
    (w->s).work[1] = r2;
  }
  return w;
}

static void MenuComp2_Init(struct Widget *w) {
  SET_WIDGET_ROUTINE(w, ENTITY_UPDATE);
  InitNonAffineMotion(&w->s);
  (w->s).flags |= (1 << 0);
  (w->s).flags |= (1 << 1);
  SetMotion(&w->s, motion_t_ARRAY_08372044[(w->s).work[0]]);
  (w->s).spr.xflip = FALSE;
  (w->s).spr.oam.xflip = FALSE;
  (w->s).flags &= ~X_FLIP;
  (w->s).spr.oam.priority = 0;
  w->props.widget2.unk_78[0] = 0;
  MenuComp2_Update(w);
}

static void MenuComp2_Update(struct Widget *w) {
  UpdateMotionGraphic(&w->s);
  if (w->props.widget2.unk_78[0]) {
    (w->s).flags &= ~(1 << 0);
    (w->s).flags &= ~(1 << 1);
    SET_WIDGET_ROUTINE(w, ENTITY_DISAPPEAR);
    return;
  }

  (w->s).coord.x = w->props.widget2.px * 0x100;
  (w->s).coord.y = w->props.widget2.py * 0x100;
  if ((w->s).work[0] == 0) {
    const u16 *bg1ofs = gVideoRegBuffer.bgofs[1];
    if (bg1ofs[0] > 0x100) {
      (w->s).coord.x += 0x20000;
    }
  }
}

static void MenuComp2_Die(struct Widget *p) {
  SET_WIDGET_ROUTINE(p, ENTITY_EXIT);
  return;
}

// ------------------------------------------------------------------------------------------------------------------------------------

// clang-format off
const WidgetRoutine gMenuComp2Routine = {
    [ENTITY_INIT] =      MenuComp2_Init,
    [ENTITY_UPDATE] =    MenuComp2_Update,
    [ENTITY_DIE] =       MenuComp2_Die,
    [ENTITY_DISAPPEAR] = DeleteWidget,
    [ENTITY_EXIT] =      (WidgetFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

static const motion_t motion_t_ARRAY_08372044[2] = {
    MOTION(SM014_CHIPICON, 11),
    MOTION(SM014_CHIPICON, 24),
};
