#ifndef GUARD_RMZ3_CYBERELF_H
#define GUARD_RMZ3_CYBERELF_H

#include "entity.h"
#include "types.h"

// --------------------------------------------

#define ELF_AVABILITY_UNLOCKED (1 << 0)
#define ELF_AVABILITY_USED (1 << 1)
#define ELF_AVABILITY_SATELITE (1 << 2)
#define ELF_AVABILITY_GROWUP1 (1 << 3)
#define ELF_AVABILITY_GROWUP2 (1 << 4)

extern u8* gElfAvailability;  // 多分常に GameState.save.elf

// --------------------------------------------

typedef void (*ElfFunc)(CyberElf*);
typedef ElfFunc ElfRoutine[5];
extern const ElfRoutine* const gElfFnTable[13];

typedef void (*CyberElfFunc)(CyberElf*);

#define INIT_ELF_ROUTINE(entity, entityID) INIT_RENDER_ENTITY(16, gElfFnTable, entity, entityID)
#define SET_ELF_ROUTINE(entity, modeID) SET_ENTITY_ROUTINE(gElfFnTable, entity, modeID)

// --------------------------------------------

struct ElfBreedInfo {
  u8 unk_0;
  u8 unk_1;
  u8 unk_2;
  u8 unk_3;
};
extern const struct ElfBreedInfo gElfBreedInfo[CYBERELF_LENGTH];

// --------------------------------------------

void DeleteElf(struct Entity* p);
void clearUnlockedCyberElfData(u8* p);
void clearUnlockedCyberElfDataHard(u8* p);
void unlockAllElvesForUltimate(u8* p);

void CreateSateliteElf(struct Zero* z, cyberelf_t id, bool8 isSatelite2);
motion_t GetElfMotion(u8 category);

struct Entity* CreateElf0(struct Zero* z, u8 breed, u8 availability, u8 _);
struct Entity* CreateNurseBElf(struct Zero* z, u8 breed, u8 availability, u8 satelite_slot);
CyberElf* CreateNurseEElf(struct Zero* z, u8 r1, u8 r2, u8 isSatelite2);
struct Entity* CreateFollowerElf(struct Zero* z, u8 breed, u8 availability, bool8 isSatelite1);
CyberElf* CreateSeaotterElf(struct Zero* z, u8 breed, u8 availability, u8 _);
// ...
CyberElf* CreateBirdElf(struct Zero* z, u8 r1, u8 r2, u8 isSatelite2);

#endif  // GUARD_RMZ3_CYBERELF_H
