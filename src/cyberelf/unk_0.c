#include "cyberelf.h"
#include "entity.h"
#include "global.h"
#include "zero.h"

void Elf0_Init(struct Elf* p);
void Elf0_Update(struct Elf* p);
void Elf0_Die(struct Elf* p);

// clang-format off
const ElfRoutine gElf0Routine = {
    [ENTITY_INIT] =      Elf0_Init,
    [ENTITY_UPDATE] =    Elf0_Update,
    [ENTITY_DIE] =       Elf0_Die,
    [ENTITY_DISAPPEAR] = DeleteElf,
    [ENTITY_EXIT] =      (ElfFunc)DeleteEntity,
};
// clang-format on

struct Elf* CreateElf0(struct Zero* z, u8 breed, u8 availability, u8 _) {
  struct Elf* p = (struct Elf*)AllocEntityFirst(gElfHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 16;
    INIT_ELF_ROUTINE(p, 0);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    *(struct Zero**)(&(p->props.raw[8])) = z;
    (p->s).work[0] = breed;
    (p->s).work[1] = availability;
  }
  return p;
}

INCASM("asm/cyberelf/unk_0.inc");

// --------------------------------------------

void FUN_080e1ef8(struct Elf* p);
void FUN_080e1fb8(struct Elf* p);
void FUN_080e1fe8(struct Elf* p);

const ElfFunc gElf0Updates[3] = {
    FUN_080e1ef8,
    FUN_080e1fb8,
    FUN_080e1fe8,
};
