#ifndef GUARD_RMZ3_ENTITY_CYBERELF_H
#define GUARD_RMZ3_ENTITY_CYBERELF_H

#include "entity/entity.h"

struct Elf {
  struct Entity s;
  struct Body body;
  u8 work[16];  // general purpose buffer
};              // 196 bytes

typedef void (*ElfFunc)(struct Elf *);
typedef ElfFunc ElfRoutine[5];

#endif  // GUARD_RMZ3_ENTITY_CYBERELF_H
