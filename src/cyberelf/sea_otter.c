#include "cyberelf.h"
#include "entity.h"
#include "global.h"

INCASM("asm/cyberelf/todo.inc");

void SeaOtterElf_Init(struct Elf* p);
void SeaOtterElf_Update(struct Elf* p);
void SeaOtterElf_Die(struct Elf* p);

// clang-format off
const ElfRoutine gSeaOtterElfRoutine = {
    [ENTITY_INIT] =      SeaOtterElf_Init,
    [ENTITY_MAIN] =      SeaOtterElf_Update,
    [ENTITY_DIE] =       SeaOtterElf_Die,
    [ENTITY_DISAPPEAR] = DeleteElf,
    [ENTITY_EXIT] =      (ElfFunc)DeleteEntity,
};
// clang-format on

void FUN_080e4a3c(struct Elf* p);
void FUN_080e4a88(struct Elf* p);
void FUN_080e4ae8(struct Elf* p);
void FUN_080e4b58(struct Elf* p);

static const ElfFunc sUpdates[4] = {
    FUN_080e4a3c,
    FUN_080e4a88,
    FUN_080e4ae8,
    FUN_080e4b58,
};
