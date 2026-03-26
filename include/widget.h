#ifndef GUARD_RMZ3_WIDGET_H
#define GUARD_RMZ3_WIDGET_H

#include "entity/widget.h"
#include "types.h"

#define SET_WIDGET_ROUTINE(widget, routine)      \
  {                                              \
    u32 tbl, id;                                 \
    WidgetFunc** r;                              \
    tbl = (u32)gWidgetFnTable;                   \
    id = ((widget->s).id) << 2;                  \
    r = (WidgetFunc**)(tbl + id);                \
                                                 \
    *(u32*)(widget->s).mode = routine;           \
    (widget->s).onUpdate = (void*)(*r)[routine]; \
  }

#define INIT_WIDGET_ROUTINE(widget, mcID)            \
  {                                                  \
    u32 tbl;                                         \
    WidgetFunc** r;                                  \
    tbl = (u32)gWidgetFnTable;                       \
    (widget->s).id = mcID;                           \
                                                     \
    r = (WidgetFunc**)(tbl + (mcID << 2));           \
    (widget->s).onUpdate = (void*)(*r)[ENTITY_INIT]; \
  }

// --------------------------------------------

typedef void (*WidgetFunc)(struct Widget*);
typedef WidgetFunc WidgetRoutine[5];

extern const WidgetRoutine* const gWidgetFnTable[14];

// --------------------------------------------

struct GameState;

void DeleteWidget(struct Widget* w);
struct Widget* CreateElfIcon(struct GameState* g);
struct Widget* CreateElfMenuItem(struct GameState* g, u8 row, u8 r2);

#endif  // GUARD_RMZ3_WIDGET_H
