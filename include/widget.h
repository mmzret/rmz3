#ifndef GUARD_RMZ3_WIDGET_H
#define GUARD_RMZ3_WIDGET_H

#include "entity.h"
#include "entity/widget.h"
#include "types.h"

#define INIT_WIDGET_ROUTINE(entity, entityID) INIT_ENTITY_ROUTINE(gWidgetFnTable, entity, entityID)
#define SET_WIDGET_ROUTINE(entity, modeID) SET_ENTITY_ROUTINE(gWidgetFnTable, entity, modeID)

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
