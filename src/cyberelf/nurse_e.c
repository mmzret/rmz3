#include "cyberelf.h"
#include "entity.h"
#include "global.h"

// コロップ、ソロップ(つまり、画面上を飛行するエルフ？)

INCASM("asm/cyberelf/nurse_e.inc");

void NurseE_Init(struct Elf* p);
void NurseE_Update(struct Elf* p);
void NurseE_Die(struct Elf* p);

// clang-format off
const ElfRoutine gNurseERoutine = {
    [ENTITY_INIT] =      NurseE_Init,
    [ENTITY_MAIN] =      NurseE_Update,
    [ENTITY_DIE] =       NurseE_Die,
    [ENTITY_DISAPPEAR] = DeleteElf,
    [ENTITY_EXIT] =      (ElfFunc)DeleteEntity,
};
// clang-format on
