#include "game.h"
#include "global.h"
#include "widget.h"

// 三角形のカーソル (▲, ▼, ▶)
// ▲, ▼ は　(セルヴォに話しかけて行う)ディスク解析のメニューでスクロールできることを示すために使用されている
// ▶ は　サイバーエルフのリストのカーソルとして使用されている

static void MenuCursor_Init(struct Widget* p);
static void MenuCursor_Update(struct Widget* p);
static void MenuCursor_Die(struct Widget* p);

// clang-format off
const WidgetRoutine gMenuCursorRoutine = {
    [ENTITY_INIT] =      (void*)MenuCursor_Init,
    [ENTITY_UPDATE] =    (void*)MenuCursor_Update,
    [ENTITY_DIE] =       (void*)MenuCursor_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteWidget,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

// 0x080e7564
struct Entity* CreateTriangleCursor(struct GameState* g, u8 kind) {
  struct Entity* p = AllocEntityLast(gWidgetHeaderPtr);
  if (p != NULL) {
    INIT_WIDGET_ROUTINE(p, 8);
    p->unk_28 = (void*)g;
    p->work[0] = kind, p->work[1] = 0;
  }
  return p;
}

// --------------------------------------------

static void FUN_080e76b4(struct Widget* p);
static void FUN_080e76dc(struct Widget* p);
static void FUN_080e7704(struct Widget* p);
static void FUN_080e7720(struct Widget* p);
static void FUN_080e7748(struct Widget* p);
static void FUN_080e7770(struct Widget* p);

static void MenuCursor_Init(struct Widget* p) {
  // clang-format off
  static const WidgetFunc sInitializers[6] = {
      FUN_080e76b4,
      FUN_080e76dc,
      FUN_080e7704,
      FUN_080e7720,
      FUN_080e7748,
      FUN_080e7770,
  };
  // clang-format on
  SET_WIDGET_ROUTINE(p, ENTITY_UPDATE);
  EnableSpriteAnimation_Normal(p);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  (p->s).spr.xflip = FALSE, (p->s).spr.oam.xflip = FALSE;
  (p->s).flags &= ~X_FLIP;
  (sInitializers[(p->s).work[0]])(p);
  MenuCursor_Update(p);
}

// --------------------------------------------

static void FUN_080e778c(struct Widget* w);
static void FUN_080e77c0(struct Widget* w);
static void FUN_080e77f4(struct Widget* w);
static void FUN_080e786c(struct Widget* w);
static void FUN_080e789c(struct Widget* w);
static void FUN_080e78cc(struct Widget* w);

// clang-format off
static const WidgetFunc sUpdates[6] = {
    FUN_080e778c,
    FUN_080e77c0,
    FUN_080e77f4,
    FUN_080e786c,
    FUN_080e789c,
    FUN_080e78cc,
};
// clang-format on

static void MenuCursor_Update(struct Widget* w) {
  struct GameState* g = (struct GameState*)(w->s).unk_28;
  if ((w->s).work[0] <= 2 || (w->s).work[0] == 5) {
    if (((&((g->sceneState).menu).elf)->unk_f & 0xfc) != 0) {
      goto despawn;
    }
    if (g->mode[3] != 0) {
      goto dispatch;
    }
    goto despawn;
  } else if ((&(g->sceneState).menu)->unk_0d == 0) {
    goto dispatch;
  }
despawn:
  (w->s).flags &= ~DISPLAY;
  (w->s).flags &= ~FLIPABLE;
  SET_WIDGET_ROUTINE(w, ENTITY_DISAPPEAR);
  return;
dispatch:
  sUpdates[(w->s).work[0]](w);
  UpdateSpriteAnimation(w);
}

// --------------------------------------------

static void MenuCursor_Die(struct Widget* w) { SET_WIDGET_ROUTINE(w, ENTITY_EXIT); }

// --------------------------------------------

static void FUN_080e76b4(struct Widget* w) {
  EnableSpriteAnimation_Normal(w);
  SetSpriteAnimation(w, MOTION(SM083_ELF_MENU_ICON, 10));  // ▲
  (w->s).coord.x = PIXEL(356);
  (w->s).coord.y = PIXEL(6);
}

static void FUN_080e76dc(struct Widget* w) {
  EnableSpriteAnimation_Normal(w);
  SetSpriteAnimation(w, MOTION(SM083_ELF_MENU_ICON, 12));  // ▼
  (w->s).coord.x = PIXEL(356);
  (w->s).coord.y = PIXEL(122);
}

static void FUN_080e7704(struct Widget* w) {
  EnableSpriteAnimation_Normal(w);
  SetSpriteAnimation(w, MOTION(SM083_ELF_MENU_ICON, 14));  // ▶
}

static void FUN_080e7720(struct Widget* w) {
  EnableSpriteAnimation_Normal(w);
  SetSpriteAnimation(w, MOTION(SM083_ELF_MENU_ICON, 10));  // ▲
  (w->s).coord.x = PIXEL(114);
  (w->s).coord.y = PIXEL(14);
}

static void FUN_080e7748(struct Widget* w) {
  EnableSpriteAnimation_Normal(w);
  SetSpriteAnimation(w, MOTION(SM083_ELF_MENU_ICON, 12));  // ▼
  (w->s).coord.x = PIXEL(114);
  (w->s).coord.y = PIXEL(128);
}

static void FUN_080e7770(struct Widget* w) {
  EnableSpriteAnimation_Normal(w);
  SetSpriteAnimation(w, MOTION(SM083_ELF_MENU_ICON, 14));  // ▶
}

// --------------------------------------------

static void FUN_080e778c(struct Widget* w) {
  struct GameState* g = (struct GameState*)(w->s).unk_28;
  if ((g->mode[3] == 3) && ((&((g->sceneState).menu).elf)->unk_f & (1 << 0))) {
    (w->s).flags |= DISPLAY;
  } else {
    (w->s).flags &= ~DISPLAY;
  }
}

static void FUN_080e77c0(struct Widget* w) {
  struct GameState* g = (struct GameState*)(w->s).unk_28;
  if ((g->mode[3] == 3) && ((&((g->sceneState).menu).elf)->unk_f & (1 << 1))) {
    (w->s).flags |= DISPLAY;
  } else {
    (w->s).flags &= ~DISPLAY;
  }
}

static void FUN_080e77f4(struct Widget* w) {
  struct GameState* g = (struct GameState*)(w->s).unk_28;
  if (g->mode[3] == 2) {
    (w->s).flags |= DISPLAY;
    (w->s).coord.x = PIXEL(10);
    (w->s).coord.y = PIXEL(9);
    (w->s).coord.x = ((&((g->sceneState).menu).elf)->tab * PIXEL(16)) + PIXEL(10);
  } else if (g->mode[3] == 3) {
    (w->s).flags |= DISPLAY;
    (w->s).coord.x = PIXEL(8);
    (w->s).coord.y = PIXEL(23);
    (w->s).coord.y = ((&((g->sceneState).menu).elf)->cursor * PIXEL(16)) + PIXEL(23);
  } else {
    (w->s).flags &= ~DISPLAY;
  }
  (w->s).coord.x += PIXEL(256);
}

static void FUN_080e786c(struct Widget* w) {
  struct GameState* g = (struct GameState*)(w->s).unk_28;
  if ((g->mode[2] == 0) && (&(g->sceneState).menu)->unk_0b != 0) {
    (w->s).flags |= DISPLAY;
  } else {
    (w->s).flags &= ~DISPLAY;
  }
}

static void FUN_080e789c(struct Widget* w) {
  struct GameState* g = (struct GameState*)(w->s).unk_28;
  if ((g->mode[2] == 0) && (&(g->sceneState).menu)->unk_0b != 30) {
    (w->s).flags |= DISPLAY;
  } else {
    (w->s).flags &= ~DISPLAY;
  }
}

static void FUN_080e78cc(struct Widget* w) {
  struct GameState* g = (struct GameState*)(w->s).unk_28;
  if ((&(g->sceneState).menu)->unk_4b != 2) {
    (w->s).flags &= ~DISPLAY;
    (w->s).flags &= ~FLIPABLE;
    SET_WIDGET_ROUTINE(w, ENTITY_DISAPPEAR);
    return;
  }

  if ((&(g->sceneState).menu.elf)->unk_e != 0) {
    (w->s).coord.x = PIXEL(185);
  } else {
    (w->s).coord.x = PIXEL(145);
  }
  (w->s).coord.y = PIXEL(112);
  (w->s).coord.x += PIXEL(256);
}
