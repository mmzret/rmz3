#include "cyberelf.h"
#include "entity.h"
#include "global.h"

INCASM("asm/cyberelf/unk_5.inc");

void Elf5_Init(struct Elf* p);
void Elf5_Update(struct Elf* p);
void Elf5_Die(struct Elf* p);

// clang-format off
const ElfRoutine gElf5Routine = {
    [ENTITY_INIT] =      Elf5_Init,
    [ENTITY_UPDATE] =    Elf5_Update,
    [ENTITY_DIE] =       Elf5_Die,
    [ENTITY_DISAPPEAR] = DeleteElf,
    [ENTITY_EXIT] =      (ElfFunc)DeleteEntity,
};
// clang-format on
