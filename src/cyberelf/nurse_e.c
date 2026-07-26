#include "entity/macros.h"
#include "zero.h"
#include "cyberelf.h"
#include "entity.h"
#include "global.h"

// コロップ、ソロップ(つまり、画面上を飛行するエルフ？)

struct CyberElfNurseE {
  COLLISION_OBJECT_HDR;  // 0x00
  struct Zero* player;   // 0xB4
  u8 unk_b8[12];         // 0xB8
};

CyberElf* CreateNurseEElf(struct Zero* z, u8 r1, u8 r2, u8 isSatelite2) {
  struct CyberElfNurseE* p = (struct CyberElfNurseE*)AllocEntityFirst(gElfHeaderPtr);
  if (p != NULL) {
    INIT_ELF_ROUTINE(p, 4);
    p->player = z;
    p->work[0] = r1, p->work[1] = r2, p->work[2] = isSatelite2;
    if (isSatelite2 == 0) {
      p->work[3] = SATELITE_1;
    } else {
      p->work[3] = SATELITE_2;
    }
  }
  return (CyberElf*)p;
}

INCASM("asm/cyberelf/nurse_e_a.inc");

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
