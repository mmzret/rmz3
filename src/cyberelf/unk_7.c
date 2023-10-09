#include "cyberelf.h"
#include "entity.h"
#include "global.h"

void Elf7_Init(struct Elf* p);
void Elf7_Update(struct Elf* p);
void Elf7_Die(struct Elf* p);

// clang-format off
const ElfRoutine gElf7Routine = {
    [ENTITY_INIT] =      Elf7_Init,
    [ENTITY_UPDATE] =    Elf7_Update,
    [ENTITY_DIE] =       Elf7_Die,
    [ENTITY_DISAPPEAR] = DeleteElf,
    [ENTITY_EXIT] =      (ElfFunc)DeleteEntity,
};
// clang-format on

struct Elf* CreateElf7(struct Zero* z, u8 breed, u8 availability, u8 _) {
  struct Elf* p = (struct Elf*)AllocEntityFirst(gElfHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 16;
    INIT_ELF_ROUTINE(p, 7);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    *(struct Zero**)(&(p->props.raw[0])) = z;
    (p->s).work[0] = breed;
    (p->s).work[1] = availability;
  }
  return p;
}

INCASM("asm/cyberelf/unk_7.inc");

void FUN_080e3f24(struct Elf* p);
void FUN_080e3f54(struct Elf* p);
void FUN_080e3f70(struct Elf* p);

static const ElfFunc sUpdates[3] = {
    FUN_080e3f24,
    FUN_080e3f54,
    FUN_080e3f70,
};

const u8 u8_ARRAY_08371d94[3] = {0, 1, 2};
