#include "pickup.h"

#include "entity.h"
#include "global.h"

// 0x08371a10
const PickupRoutine *const gPickupFnTable[2] = {
    &gPickupItemRoutine,
    &gPickupDiskRoutine,
};

void InitPickupHeader(struct EntityHeader *h, struct Pickup *p, s16 len) {
  s16 i;

  InitEntityHeader(h, ENTITY_ITEM, &p->s, sizeof(struct Pickup), len);
  for (i = 0; i < len; i++) {
    p[i].s.uniqueID = gEntityIDGenerator + i;
  }
  gEntityIDGenerator += len;
  gPickupHeaderPtr = h;
}

void DeletePickup(struct Pickup *p) {
  (p->s).flags &= ~DISPLAY;
  SET_ITEM_ROUTINE(p, ENTITY_EXIT);
}
