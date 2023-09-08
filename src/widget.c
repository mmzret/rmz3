#include "widget.h"

#include "entity.h"
#include "global.h"

// clang-format off
const WidgetRoutine *const gWidgetFnTable[14] = {
  [0]  = &gMenuWeaponIconRoutine,
  [1]  = &gMenuComp1Routine,
  [2]  = &gMenuComp2Routine,
  [3]  = &gSubtankIconRoutine,
  [4]  = &gMenuHPRoutine,
  [5]  = &gArmorIconsRoutine,
  [6]  = &gExIconRoutine,
  [7]  = &gElfMenuItemRoutine,
  [8]  = &gMenuCursorRoutine,
  [9]  = &gWidget9Routine,
  [10] = &gDiskIconRoutine,
  [11] = &gElfIconRoutine,
  [12] = &gDiskModalBorderRoutine,
  [13] = &gMenuComp13Routine,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

void InitWidgetHeader(struct EntityHeader *h, struct Widget *w, s16 len) {
  s16 i;

  InitEntityHeader(h, ENTITY_WIDGET, &w->s, sizeof(struct Widget), len);
  for (i = 0; i < len; i++) {
    w[i].s.uniqueID = gEntityIDGenerator + i;
  }
  gEntityIDGenerator += len;
  gWidgetHeaderPtr = h;
}

void DeleteWidget(struct Widget *w) {
  (w->s).flags &= ~DISPLAY;
  SET_WIDGET_ROUTINE(w, ENTITY_EXIT);
}
