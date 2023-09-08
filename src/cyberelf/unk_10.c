#include "cyberelf.h"
#include "entity.h"
#include "global.h"

void Elf10_Init(struct Elf* p);
void Elf10_Update(struct Elf* p);
void Elf10_Die(struct Elf* p);

// clang-format off
const ElfRoutine gElf10Routine = {
    [ENTITY_INIT] =      Elf10_Init,
    [ENTITY_MAIN] =      Elf10_Update,
    [ENTITY_DIE] =       Elf10_Die,
    [ENTITY_DISAPPEAR] = DeleteElf,
    [ENTITY_EXIT] =      (ElfFunc)DeleteEntity,
};
// clang-format on
