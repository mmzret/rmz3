#ifndef GUARD_RMZ3_MAP_ITEM_H
#define GUARD_RMZ3_MAP_ITEM_H

#include "entity.h"
#include "types.h"

#define INIT_ITEM_ROUTINE(entity, entityID) INIT_ENTITY_ROUTINE(gPickupFnTable, entity, entityID)
#define SET_ITEM_ROUTINE(entity, modeID) SET_ENTITY_ROUTINE(gPickupFnTable, entity, modeID)

extern const PickupRoutine* const gPickupFnTable[2];

void DeletePickup(struct Pickup* p);

struct Pickup* CreatePickupItem(u8 itemID, struct Coord* c, u8 param_3);
struct Pickup* CreateMapDisk(u8 diskNo, struct Coord* c, u8 r2);

#endif  // GUARD_RMZ3_MAP_ITEM_H
