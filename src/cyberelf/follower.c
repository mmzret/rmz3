#include "cyberelf.h"
#include "entity.h"
#include "global.h"

INCASM("asm/cyberelf/follower.inc");

void FollowerElf_Init(struct Elf* p);
void FollowerElf_Update(struct Elf* p);
void FollowerElf_Die(struct Elf* p);

// clang-format off
const ElfRoutine gFollowerElfRoutine = {
    [ENTITY_INIT] =      FollowerElf_Init,
    [ENTITY_MAIN] =      FollowerElf_Update,
    [ENTITY_DIE] =       FollowerElf_Die,
    [ENTITY_DISAPPEAR] = DeleteElf,
    [ENTITY_EXIT] =      (ElfFunc)DeleteEntity,
};
// clang-format on
