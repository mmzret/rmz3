#ifndef GUARD_RMZ3_ELEMENT_H
#define GUARD_RMZ3_ELEMENT_H

#include "gba/types.h"

struct VFX;
struct Entity;
struct Coord;

struct UnkElement {
  u8 unk_0;
  u8 unk_1;
  u8 unk_2;
};

extern struct UnkElement wElement;

void setWramElement(u8 elementID);
struct VFX* ApplyElementEffect(u8 idx, struct Entity* p, const struct Coord* c);

#endif  // GUARD_RMZ3_ELEMENT_H
