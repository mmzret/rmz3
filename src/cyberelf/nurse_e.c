#include "cyberelf.h"
#include "entity.h"
#include "global.h"
#include "vfx.h"

// コロップ、ソロップ(つまり、画面上を飛行するエルフ？)

INCASM("asm/cyberelf/nurse_e_a.inc");

void NurseE_Die(CyberElf* p) {
  FUN_080bfce8(&p->coord, 0);
  p->flags &= ~DISPLAY;
  SET_ELF_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/cyberelf/nurse_e_b.inc");

void NurseE_Init(CyberElf* p);
void NurseE_Update(CyberElf* p);
void NurseE_Die(CyberElf* p);

// clang-format off
const ElfRoutine gNurseERoutine = {
    [ENTITY_INIT] =      (void*)NurseE_Init,
    [ENTITY_UPDATE] =    (void*)NurseE_Update,
    [ENTITY_DIE] =       (void*)NurseE_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteElf,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on
