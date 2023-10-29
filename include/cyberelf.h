#ifndef GUARD_RMZ3_CYBERELF_H
#define GUARD_RMZ3_CYBERELF_H

#include "entity.h"
#include "types.h"

#define ELF_AVABILITY_UNLOCKED (1 << 0)
#define ELF_AVABILITY_USED (1 << 1)
#define ELF_AVABILITY_SATELITE (1 << 2)
#define ELF_AVABILITY_GROWUP1 (1 << 3)
#define ELF_AVABILITY_GROWUP2 (1 << 4)

#define INIT_ELF_ROUTINE(elf, elfID)                 \
  {                                                  \
    u32 tbl;                                         \
    ElfFunc **r;                                     \
    tbl = (u32)gElfFnTable;                          \
    ((elf)->s).id = elfID;                           \
                                                     \
    r = (ElfFunc **)(tbl + (elfID << 2));            \
    ((elf)->s).onUpdate = (void *)(*r)[ENTITY_INIT]; \
  }

#define SET_ELF_ROUTINE(elf, routine)            \
  {                                              \
    u32 tbl, id;                                 \
    ElfFunc **r;                                 \
    tbl = (u32)gElfFnTable;                      \
    id = (((elf)->s).id) << 2;                   \
    r = (ElfFunc **)(tbl + id);                  \
                                                 \
    *(u32 *)((elf)->s).mode = routine;           \
    ((elf)->s).onUpdate = (void *)(*r)[routine]; \
  }

struct ElfBreedInfo {
  u8 unk_0;
  u8 unk_1;
  u8 unk_2;
  u8 unk_3;
};

// --------------------------------------------

extern const ElfRoutine *const gElfFnTable[13];

extern const ElfRoutine gElf0Routine;
extern const ElfRoutine gElf1Routine;
extern const ElfRoutine gNurseBRoutine;
extern const ElfRoutine gElf3Routine;
extern const ElfRoutine gNurseERoutine;
extern const ElfRoutine gElf5Routine;
extern const ElfRoutine gElf6Routine;
extern const ElfRoutine gElf7Routine;
extern const ElfRoutine gFollowerElfRoutine;
extern const ElfRoutine gSeaOtterElfRoutine;
extern const ElfRoutine gElf10Routine;
extern const ElfRoutine gElf11Routine;
extern const ElfRoutine gBirdElfRoutine;

extern const struct ElfBreedInfo gElfBreedInfo[CYBERELF_LENGTH];

// --------------------------------------------

void DeleteElf(struct Elf *p);
void clearUnlockedCyberElfData(u8 *p);
void clearUnlockedCyberElfDataHard(u8 *p);
void unlockAllElvesForUltimate(u8 *p);

void CreateSateliteElf(struct Zero *z, cyberelf_t id, bool8 isSatelite2);
motion_t GetElfMotion(u8 category);

struct Elf *CreateElf0(struct Zero *z, u8 breed, u8 availability, u8 _);
struct Elf *CreateNurseBElf(struct Zero *z, u8 r1, u8 r2, u8 isSatelite2);
struct Elf *CreateElf3(struct Entity *r0, void *r1);
struct Elf *CreateNurseEElf(struct Zero *z, u8 r1, u8 r2, u8 isSatelite2);
struct Elf *CreateFollowerElf(struct Zero *z, u8 breed, u8 availability, bool8 isSatelite1);
struct Elf *CreateSeaotterElf(struct Zero *z, u8 breed, u8 availability, u8 _);
// ...
struct Elf *CreateBirdElf(struct Zero *z, u8 r1, u8 r2, u8 isSatelite2);

#endif  // GUARD_RMZ3_CYBERELF_H
