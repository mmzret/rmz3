#include "cyberelf.h"
#include "entity.h"
#include "global.h"

struct Zero;

void Elf1_Init(struct Elf* p);
void Elf1_Update(struct Elf* p);
void Elf1_Die(struct Elf* p);

// clang-format off
const ElfRoutine gElf1Routine = {
    [ENTITY_INIT] =      Elf1_Init,
    [ENTITY_UPDATE] =    Elf1_Update,
    [ENTITY_DIE] =       Elf1_Die,
    [ENTITY_DISAPPEAR] = DeleteElf,
    [ENTITY_EXIT] =      (ElfFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

struct Elf* CreateElf1(struct Zero* p, u8 breed, u8 availability, u8 _) {
  struct Elf* e = (struct Elf*)AllocEntityFirst(gElfHeaderPtr);
  if (e != NULL) {
    (e->s).taskCol = 16;
    INIT_ELF_ROUTINE(e, 1);
    (e->s).tileNum = 0;
    (e->s).palID = 0;
    *(struct Zero**)(&(e->props.raw[0])) = p;
    (e->s).work[0] = breed;
    (e->s).work[1] = availability;
  }
  return e;
}

INCASM("asm/cyberelf/unk_1.inc");

// --------------------------------------------

void FUN_080e2310(struct Elf* p);
void FUN_080e234c(struct Elf* p);
void FUN_080e23a4(struct Elf* p);
void FUN_080e23fc(struct Elf* p);
void FUN_080e2414(struct Elf* p);
void FUN_080e244c(struct Elf* p);

// clang-format off
const ElfFunc sElf1Updates[6] = {
    FUN_080e2310,
    FUN_080e234c,
    FUN_080e23a4,
    FUN_080e23fc,
    FUN_080e2414,
    FUN_080e244c,
};
// clang-format on
