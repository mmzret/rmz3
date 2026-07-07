#ifndef GUARD_RMZ3_MAP_ITEM_H
#define GUARD_RMZ3_MAP_ITEM_H

#include "entity/entity.h"
#include "types.h"

extern Pickup gPickups[10];

struct EntityHeader;
extern struct EntityHeader* gPickupHeaderPtr;

typedef void (*PickupFunc)(Pickup*);
typedef PickupFunc PickupRoutine[5];
extern const PickupRoutine* const gPickupFnTable[2];

// --------------------------------------------

#define INIT_ITEM_ROUTINE(entity, entityID) INIT_OBJECT_ENTITY(1, gPickupFnTable, entity, entityID)
#define SET_ITEM_ROUTINE(entity, modeID) SET_ENTITY_ROUTINE(gPickupFnTable, entity, modeID)

// --------------------------------------------

void DeletePickup(struct Entity* p);

struct Entity* CreatePickupItem(u8 itemID, Coords32* c, u8 param_3);
struct Entity* CreateMapDisk(u8 diskNo, Coords32* c, u8 r2);

#endif  // GUARD_RMZ3_MAP_ITEM_H
