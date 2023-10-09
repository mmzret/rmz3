#include "cyberelf.h"
#include "entity.h"
#include "global.h"

INCASM("asm/cyberelf/nurse_b.inc");

// ------------------------------------------------------------------------------------------------------------------------------------

void NurseB_Init(struct Elf* p);
void NurseB_Update(struct Elf* p);
void NurseB_Die(struct Elf* p);

// clang-format off
const ElfRoutine gNurseBRoutine = {
    [ENTITY_INIT] =      NurseB_Init,
    [ENTITY_UPDATE] =    NurseB_Update,
    [ENTITY_DIE] =       NurseB_Die,
    [ENTITY_DISAPPEAR] = DeleteElf,
    [ENTITY_EXIT] =      (ElfFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080e284c(struct Elf* p);
void FUN_080e28a8(struct Elf* p);
void FUN_080e2920(struct Elf* p);
void FUN_080e28a8(struct Elf* p);

const ElfFunc sNurseBUpdates[4] = {
    FUN_080e284c,
    FUN_080e28a8,
    FUN_080e2920,
    FUN_080e28a8,
};
