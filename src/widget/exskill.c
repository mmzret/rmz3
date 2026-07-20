#include "game.h"
#include "global.h"
#include "widget.h"

#define KIND ((w->s).work[0])

static const motion_t sExIconMotions[12];

static void ExIcon_Init(struct Widget* w);
static void ExIcon_Update(struct Widget* w);
static void ExIcon_Die(struct Widget* w);

// clang-format off
const WidgetRoutine gExIconRoutine = {
    [ENTITY_INIT] =      (void*)ExIcon_Init,
    [ENTITY_UPDATE] =    (void*)ExIcon_Update,
    [ENTITY_DIE] =       (void*)ExIcon_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteWidget,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

struct Entity* CreateExSkillIcon(struct GameState* g, u8 kind) {
  struct Entity* p = AllocEntityLast(gWidgetHeaderPtr);
  if (p != NULL) {
    INIT_WIDGET_ROUTINE(p, 6);
    p->unk_28 = (void*)g;
    p->work[0] = kind, p->work[1] = 0;
  }
  return p;
}

NON_MATCH static void ExIcon_Init(struct Widget* w) {
#if MODERN
  SET_WIDGET_ROUTINE(w, ENTITY_UPDATE);
  (w->s).flags |= DISPLAY;
  (w->s).flags |= FLIPABLE;
  (w->s).spr.xflip = FALSE;
  (w->s).spr.oam.xflip = FALSE;
  (w->s).flags &= ~X_FLIP;
  (w->s).coord.x = (u32)(KIND & 3) * PIXEL(24) + PIXEL(16) + PIXEL(256);  // ここの += PIXEL(16)+PIXEL(256) のアセンブリが合わない
  (w->s).coord.y = (u32)(KIND >> 2) * PIXEL(24) + PIXEL(28);
  ExIcon_Update(w);
#else
  INCCODE("asm/wip/ExIcon_Init.inc");
#endif
}

static void ExIcon_Update(struct Widget* w) {
  u8 n;
  struct GameState* g = (struct GameState*)(w->s).unk_28;
  struct Zero* z = g->z2;

  if ((&((g->sceneState).menu).exskill)->inactive) {
    (w->s).flags &= ~DISPLAY;
    (w->s).flags &= ~FLIPABLE;
    SET_WIDGET_ROUTINE(w, ENTITY_DISAPPEAR);
    return;
  }

  if (((&z->unk_b4)->status.exSkill & (1 << KIND)) >> KIND) {
    (w->s).palID = 0;
    EnableSpriteAnimation_Normal(w);
    SetSpriteAnimation(w, sExIconMotions[KIND]);
  } else {
    (w->s).palID = 1;
    EnableSpriteAnimation_Normal(w);
    SetSpriteAnimation(w, sExIconMotions[KIND]);
  }
  UpdateSpriteAnimation(w);
}

static void ExIcon_Die(struct Widget* w) {
  SET_WIDGET_ROUTINE(w, ENTITY_EXIT);
  return;
}

// ------------------------------------------------------------------------------------------------------------------------------------

// clang-format off
static const motion_t sExIconMotions[12] = {
    MOTION(SM069_EXSKILL_ICON, 5),
    MOTION(SM069_EXSKILL_ICON, 4),
    MOTION(SM069_EXSKILL_ICON, 6),
    MOTION(SM069_EXSKILL_ICON, 7),
    MOTION(SM069_EXSKILL_ICON, 3),
    MOTION(SM069_EXSKILL_ICON, 0),
    MOTION(SM069_EXSKILL_ICON, 1),
    MOTION(SM069_EXSKILL_ICON, 2),
    MOTION(SM069_EXSKILL_ICON, 8),
    MOTION(SM069_EXSKILL_ICON, 9),
    MOTION(SM069_EXSKILL_ICON, 11),
    MOTION(SM069_EXSKILL_ICON, 10),
};
// clang-format on

#undef KIND
