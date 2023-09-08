#include "mapitem.h"

#include "entity.h"
#include "global.h"

// 0x08371a10
const MapItemRoutine *const gMapItemFnTable[2] = {
    &gMapItemRoutine,
    &gMapDiskRoutine,
};

void InitMapItemHeader(struct EntityHeader *h, struct MapItem *p, s16 len) {
  s16 i;

  InitEntityHeader(h, ENTITY_ITEM, &p->s, sizeof(struct MapItem), len);
  for (i = 0; i < len; i++) {
    p[i].s.uniqueID = gEntityIDGenerator + i;
  }
  gEntityIDGenerator += len;
  gMapItemHeaderPtr = h;
}

void DeleteMapItem(struct MapItem *p) {
  (p->s).flags &= ~DISPLAY;
  SET_ITEM_ROUTINE(p, ENTITY_EXIT);
}
