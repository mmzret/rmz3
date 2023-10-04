#ifndef GUARD_RMZ3_MAP_ITEM_H
#define GUARD_RMZ3_MAP_ITEM_H

#include "collision.h"
#include "constants/constants.h"
#include "entity.h"
#include "types.h"

#define SET_ITEM_ROUTINE(item, routine)           \
  {                                               \
    u32 tbl, id;                                  \
    MapItemFunc **r;                              \
    tbl = (u32)gMapItemFnTable;                   \
    id = (((item)->s).id) << 2;                   \
    r = (MapItemFunc **)(tbl + id);               \
                                                  \
    *(u32 *)((item)->s).mode = routine;           \
    ((item)->s).onUpdate = (void *)(*r)[routine]; \
  }

#define INIT_ITEM_ROUTINE(item, itemID)               \
  {                                                   \
    u32 tbl;                                          \
    MapItemFunc **r;                                  \
    tbl = (u32)gMapItemFnTable;                       \
    ((item)->s).id = itemID;                          \
                                                      \
    r = (MapItemFunc **)(tbl + (itemID << 2));        \
    ((item)->s).onUpdate = (void *)(*r)[ENTITY_INIT]; \
  }

extern const MapItemRoutine *const gMapItemFnTable[2];

extern const MapItemRoutine gMapItemRoutine;
extern const MapItemRoutine gMapDiskRoutine;

void DeleteMapItem(struct MapItem *p);

struct MapItem *CreateMapItem(u8 itemID, struct Coord *c, u8 param_3);
struct MapItem *CreateMapDisk(u8 diskNo, struct Coord *c, u8 r2);

#endif  // GUARD_RMZ3_MAP_ITEM_H
