#include "widget/cursor_square.h"

#include "game.h"
#include "global.h"
#include "motion.h"
#include "widget.h"

// エレメントチップ や ExSkill を選択する際の以下の形をしたカーソル
// ┌    ┐
//
// └    ┘

static void MenuComp2_Init(struct SquareCursorWidget* p);
static void MenuComp2_Update(struct SquareCursorWidget* p);
static void MenuComp2_Die(struct Entity* p);

// clang-format off
const WidgetRoutine gSquareCursorRoutine = {
    [ENTITY_INIT] =      (void*)MenuComp2_Init,
    [ENTITY_UPDATE] =    (void*)MenuComp2_Update,
    [ENTITY_DIE] =       (void*)MenuComp2_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteWidget,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

/**
 * @param big EXスキル選択　のような大きい四角なら TRUE, エレメントチップ選択のような小さい四角なら FALSE
 * @note 0x080e6420
 */
struct Entity* CreateSquareCursor(struct GameState* g, bool8 big, u8 r2) {
  struct Entity* p = AllocEntityLast(gWidgetHeaderPtr);
  if (p != NULL) {
    INIT_WIDGET_ROUTINE(p, 2);
    p->unk_28 = (void*)g;
    p->work[0] = big, p->work[1] = r2;
  }
  return p;
}

// --------------------------------------------

static void MenuComp2_Init(struct SquareCursorWidget* p) {
  static const motion_t sMotions[2] = {
      MOTION(SM014_CHIPICON, 11),
      MOTION(SM014_CHIPICON, 24),
  };  // 0x08372044

  SET_WIDGET_ROUTINE(p, ENTITY_UPDATE);
  InitNonAffineMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteAnimation(p, sMotions[(p->s).work[0]]);
  (p->s).spr.xflip = FALSE, (p->s).spr.oam.xflip = FALSE;
  (p->s).flags &= ~X_FLIP;
  (p->s).spr.oam.priority = 0;
  p->dead = FALSE;
  MenuComp2_Update((void*)p);
}

static void MenuComp2_Update(struct SquareCursorWidget* p) {
  UpdateSpriteAnimation(p);
  if (p->dead) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    SET_WIDGET_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (p->s).coord.x = p->px * PIXEL(1);
  (p->s).coord.y = p->py * PIXEL(1);
  if ((p->s).work[0] == 0) {
    BgOfs* bg1ofs = (BgOfs*)gVideoRegBuffer.bgofs[1];
    if (bg1ofs->x > 256) (p->s).coord.x += PIXEL(512);
  }
}

static void MenuComp2_Die(struct Entity* p) { SET_WIDGET_ROUTINE(p, ENTITY_EXIT); }
