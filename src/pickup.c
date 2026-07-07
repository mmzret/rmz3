#include "pickup.h"

#include "entity.h"
#include "global.h"

extern const PickupRoutine gPickupItemRoutine;
extern const PickupRoutine gPickupDiskRoutine;

// 0x08371a10
const PickupRoutine* const gPickupFnTable[2] = {
    &gPickupItemRoutine,
    &gPickupDiskRoutine,
};

void InitPickupHeader(struct EntityHeader* h, Pickup* p, s16 len) {
  s16 i;

  InitEntityHeader(h, ENTITY_ITEM, (void*)p, sizeof(Pickup), len);
  for (i = 0; i < len; i++) {
    p[i].uniqueID = gEntityIDGenerator + i;
  }
  gEntityIDGenerator += len;
  gPickupHeaderPtr = h;
}

void DeletePickup(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_ITEM_ROUTINE(p, ENTITY_EXIT);
}
