#include "cyberelf.h"
#include "entity.h"
#include "global.h"

void Elf6_Init(struct Elf* p);
void Elf6_Update(struct Elf* p);
void Elf6_Die(struct Elf* p);

// clang-format off
const ElfRoutine gElf6Routine = {
    [ENTITY_INIT] =      Elf6_Init,
    [ENTITY_MAIN] =      Elf6_Update,
    [ENTITY_DIE] =       Elf6_Die,
    [ENTITY_DISAPPEAR] = DeleteElf,
    [ENTITY_EXIT] =      (ElfFunc)DeleteEntity,
};
// clang-format on

struct Elf* CreateElf6(struct Zero* z, u8 breed, u8 availability, u8 _) {
  struct Elf* p = (struct Elf*)AllocEntityFirst(gElfHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 16;
    INIT_ELF_ROUTINE(p, 6);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    *(struct Zero**)(&p->work[0]) = z;
    (p->s).work[0] = breed;
    (p->s).work[1] = availability;
  }
  return p;
}

INCASM("asm/cyberelf/unk_6.inc");

const u16 u16_ARRAY_08371d5c[7] = {
    0x0027, 0x0025, 0x0026, 0x0021, 0x0023, 0x0022, 0x0028,
};

const u8 sFusionPenalties[7] = {
    5, 0, 1, 5, 1, 5, 1,
};
