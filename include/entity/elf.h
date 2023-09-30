#ifndef GUARD_RMZ3_ENTITY_CYBERELF_H
#define GUARD_RMZ3_ENTITY_CYBERELF_H

#include "entity/entity.h"
#include "types.h"

struct FollowerProps {
  struct Zero* player;
  cyberelf_t id;
  u8 unk_05[7];
  u8 unk_0c;
  bool8 isSatelite1;
};

struct Elf {
  struct Entity s;
  struct Body body;
  union {
    u8 raw[16];
    struct FollowerProps follower;
  } props;  // general purpose buffer
};          // 196 bytes

typedef void (*ElfFunc)(struct Elf*);
typedef ElfFunc ElfRoutine[5];

#endif  // GUARD_RMZ3_ENTITY_CYBERELF_H
