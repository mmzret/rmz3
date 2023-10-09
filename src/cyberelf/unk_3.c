#include "collision.h"
#include "cyberelf.h"
#include "entity.h"
#include "global.h"

// ------------------------------------------------------------------------------------------------------------------------------------

void Elf3_Init(struct Elf *p);
void Elf3_Update(struct Elf *p);
void Elf3_Die(struct Elf *p);

// clang-format off
const ElfRoutine gElf3Routine = {
    [ENTITY_INIT] =      Elf3_Init,
    [ENTITY_UPDATE] =    Elf3_Update,
    [ENTITY_DIE] =       Elf3_Die,
    [ENTITY_DISAPPEAR] = DeleteElf,
    [ENTITY_EXIT] =      (ElfFunc)DeleteEntity,
};
// clang-format on

struct Elf *CreateElf3(struct Entity *r0, void *r1) {
  struct Elf *p = (struct Elf *)AllocEntityFirst(gElfHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 16;
    INIT_ELF_ROUTINE(p, 3);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).unk_28 = r0;
    (p->s).unk_2c = r1;
    (p->s).work[0] = 0;
    (p->s).work[1] = r0->work[1];
  }
  return p;
}

INCASM("asm/cyberelf/unk_3.inc");

const struct Collision sElf3Collisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 255,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x40,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-0x0100, -0x0E00, 0x3400, 0x3200},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x0100, -0x0E00, 0x3400, 0x3200},
    },
};
