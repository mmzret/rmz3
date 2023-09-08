#ifndef GUARD_RMZ3_WIDGET_H
#define GUARD_RMZ3_WIDGET_H

#include "entity.h"
#include "types.h"

#define SET_WIDGET_ROUTINE(widget, routine)       \
  {                                               \
    u32 tbl, id;                                  \
    WidgetFunc **r;                               \
    tbl = (u32)gWidgetFnTable;                    \
    id = ((widget->s).id) << 2;                   \
    r = (WidgetFunc **)(tbl + id);                \
                                                  \
    *(u32 *)(widget->s).mode = routine;           \
    (widget->s).onUpdate = (void *)(*r)[routine]; \
  }

#define INIT_WIDGET_ROUTINE(widget, mcID)             \
  {                                                   \
    u32 tbl;                                          \
    WidgetFunc **r;                                   \
    tbl = (u32)gWidgetFnTable;                        \
    (widget->s).id = mcID;                            \
                                                      \
    r = (WidgetFunc **)(tbl + (mcID << 2));           \
    (widget->s).onUpdate = (void *)(*r)[ENTITY_INIT]; \
  }

// --------------------------------------------

extern const WidgetRoutine *const gWidgetFnTable[14];

extern const WidgetRoutine gMenuWeaponIconRoutine;
extern const WidgetRoutine gMenuComp1Routine;
extern const WidgetRoutine gMenuComp2Routine;
extern const WidgetRoutine gSubtankIconRoutine;
extern const WidgetRoutine gMenuHPRoutine;
extern const WidgetRoutine gArmorIconsRoutine;
extern const WidgetRoutine gExIconRoutine;
extern const WidgetRoutine gElfMenuItemRoutine;
extern const WidgetRoutine gMenuCursorRoutine;
extern const WidgetRoutine gWidget9Routine;
extern const WidgetRoutine gDiskIconRoutine;
extern const WidgetRoutine gElfIconRoutine;
extern const WidgetRoutine gDiskModalBorderRoutine;
extern const WidgetRoutine gMenuComp13Routine;

// --------------------------------------------

struct GameState;

void DeleteWidget(struct Widget *w);
struct Widget *CreateElfIcon(struct GameState *g);
struct Widget *CreateElfMenuItem(struct GameState *g, u8 row, u8 r2);

#endif  // GUARD_RMZ3_WIDGET_H
