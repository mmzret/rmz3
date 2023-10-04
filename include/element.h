#ifndef GUARD_RMZ3_ELEMENT_H
#define GUARD_RMZ3_ELEMENT_H

#include "entity.h"
#include "gba/types.h"

struct UnkElement {
  u8 unk_0;
  u8 unk_1;
  u8 unk_2;
};

extern struct UnkElement wElement;

void FUN_080250b8(void);
void FUN_080251a8(void);
void setWramElement(u8 elementID);
struct VFX *ApplyElementEffect(u8 idx, struct Entity *p, const struct Coord *c);

#endif  // GUARD_RMZ3_ELEMENT_H
