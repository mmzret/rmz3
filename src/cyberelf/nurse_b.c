#include "cyberelf.h"
#include "entity.h"
#include "global.h"
#include "zero.h"

struct CyberElfNurseB {
  COLLISION_OBJECT_HDR;  // 0x00
  struct Zero* player;   // 0xB4
  u8 unk_b8[12];         // 0xB8
};
static_assert(sizeof(struct CyberElfNurseB) == sizeof(CyberElf));

struct Entity* CreateElf3(struct Entity* nurse_b, struct Entity* z);

void NurseB_Init(CyberElf* p);
void NurseB_Update(CyberElf* p);
void NurseB_Die(CyberElf* p);

// clang-format off
const ElfRoutine gNurseBRoutine = {
    [ENTITY_INIT] =      (void*)NurseB_Init,
    [ENTITY_UPDATE] =    (void*)NurseB_Update,
    [ENTITY_DIE] =       (void*)NurseB_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteElf,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* CreateNurseBElf(struct Zero* z, u8 breed, u8 availability, u8 satelite_slot) {
  struct CyberElfNurseB* p = AllocEntityLast(gElfHeaderPtr);
  if (p != NULL) {
    INIT_ELF_ROUTINE(p, 2);
    p->player = z;
    p->work[0] = breed, p->work[1] = availability, p->work[2] = satelite_slot;
    if (satelite_slot == 0) {
      p->work[3] = ((&z->unk_b4)->status).satelites[0];
    } else {
      p->work[3] = ((&z->unk_b4)->status).satelites[1];
    }
  }
  return (struct Entity*)p;
}

INCASM("asm/cyberelf/nurse_b.inc");

// --------------------------------------------

void FUN_080e284c(CyberElf* p);
void FUN_080e28a8(CyberElf* p);
void FUN_080e2920(CyberElf* p);
void FUN_080e28a8(CyberElf* p);

const CyberElfFunc sNurseBUpdates[4] = {
    FUN_080e284c,
    FUN_080e28a8,
    FUN_080e2920,
    FUN_080e28a8,
};
