#ifndef GUARD_RMZ3_WIDGET_H
#define GUARD_RMZ3_WIDGET_H

#include "entity/entity.h"
#include "types.h"

extern struct Widget gWidgets[64];

struct EntityHeader;
extern struct EntityHeader* gWidgetHeaderPtr;

typedef void (*WidgetFunc)(struct Widget*);
typedef WidgetFunc WidgetRoutine[5];
extern const WidgetRoutine* const gWidgetFnTable[14];

// --------------------------------------------

#define INIT_WIDGET_ROUTINE(entity, entityID) INIT_RENDER_ENTITY(16, gWidgetFnTable, entity, entityID)
#define SET_WIDGET_ROUTINE(entity, modeID) SET_ENTITY_ROUTINE(gWidgetFnTable, entity, modeID)

// --------------------------------------------

struct GameState;

void DeleteWidget(struct Entity* w);
struct Widget* CreateElfIcon(struct GameState* g);
struct Widget* CreateElfMenuItem(struct GameState* g, u8 row, u8 r2);

#endif  // GUARD_RMZ3_WIDGET_H
