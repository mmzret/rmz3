#include "cyberelf.h"
#include "entity.h"
#include "global.h"

struct CyberElf7 {
  COLLISION_OBJECT_HDR;  // 0x00
  struct Zero* player;   // 0xB4
  u8 unk_b8[12];         // 0xB8
};
static_assert(sizeof(struct CyberElf7) == sizeof(CyberElf));

void Elf7_Init(CyberElf* p);
void Elf7_Update(CyberElf* p);
void Elf7_Die(CyberElf* p);

// clang-format off
const ElfRoutine gElf7Routine = {
    [ENTITY_INIT] =      (void*)Elf7_Init,
    [ENTITY_UPDATE] =    (void*)Elf7_Update,
    [ENTITY_DIE] =       (void*)Elf7_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteElf,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* CreateElf7(struct Zero* z, u8 breed, u8 availability, u8 _) {
  struct CyberElf7* p = AllocEntityLast(gElfHeaderPtr);
  if (p != NULL) {
    INIT_ELF_ROUTINE(p, 7);
    p->player = z;
    p->work[0] = breed, p->work[1] = availability;
  }
  return (struct Entity*)p;
}

INCASM("asm/cyberelf/unk_7.inc");

void FUN_080e3f24(CyberElf* p);
void FUN_080e3f54(CyberElf* p);
void FUN_080e3f70(CyberElf* p);

static const CyberElfFunc sUpdates[3] = {
    FUN_080e3f24,
    FUN_080e3f54,
    FUN_080e3f70,
};  // 0x08371d88

// 0x08371d94
const u8 u8_ARRAY_08371d94[3] = {0, 1, 2};
