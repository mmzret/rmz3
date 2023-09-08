#include "cyberelf.h"
#include "entity.h"
#include "global.h"

static const ElfFunc sUpdates[2];

void BirdElf_Init(struct Elf* p);
void BirdElf_Update(struct Elf* p);
void BirdElf_Die(struct Elf* p);

// clang-format off
const ElfRoutine gBirdElfRoutine = {
    [ENTITY_INIT] =      BirdElf_Init,
    [ENTITY_MAIN] =      BirdElf_Update,
    [ENTITY_DIE] =       BirdElf_Die,
    [ENTITY_DISAPPEAR] = DeleteElf,
    [ENTITY_EXIT] =      (ElfFunc)DeleteEntity,
};
// clang-format on

void FUN_080e5b74(struct Elf* p);
void FUN_080e5d68(struct Elf* p);

static const ElfFunc sUpdates[2] = {
    FUN_080e5b74,
    FUN_080e5d68,
};
