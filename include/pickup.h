#ifndef GUARD_RMZ3_MAP_ITEM_H
#define GUARD_RMZ3_MAP_ITEM_H

#include "collision.h"
#include "constants/constants.h"
#include "entity.h"
#include "types.h"

#define SET_ITEM_ROUTINE(item, routine)           \
  {                                               \
    u32 tbl, id;                                  \
    PickupFunc **r;                               \
    tbl = (u32)gPickupFnTable;                    \
    id = (((item)->s).id) << 2;                   \
    r = (PickupFunc **)(tbl + id);                \
                                                  \
    *(u32 *)((item)->s).mode = routine;           \
    ((item)->s).onUpdate = (void *)(*r)[routine]; \
  }

#define INIT_ITEM_ROUTINE(item, itemID)               \
  {                                                   \
    u32 tbl;                                          \
    PickupFunc **r;                                   \
    tbl = (u32)gPickupFnTable;                        \
    ((item)->s).id = itemID;                          \
                                                      \
    r = (PickupFunc **)(tbl + (itemID << 2));         \
    ((item)->s).onUpdate = (void *)(*r)[ENTITY_INIT]; \
  }

extern const PickupRoutine *const gPickupFnTable[2];

extern const PickupRoutine gPickupItemRoutine;
extern const PickupRoutine gPickupDiskRoutine;

void DeletePickup(struct Pickup *p);

struct Pickup *CreatePickupItem(u8 itemID, struct Coord *c, u8 param_3);
struct Pickup *CreateMapDisk(u8 diskNo, struct Coord *c, u8 r2);

#endif  // GUARD_RMZ3_MAP_ITEM_H
