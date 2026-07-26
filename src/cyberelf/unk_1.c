#include "cyberelf.h"
#include "entity.h"
#include "global.h"
#include "zero.h"

bool8 FUN_080e1578(struct Coord* c1, struct Coord* c2, struct Coord* c3, u8* param_4, s16 param_5);

struct Zero;

struct CyberElf1 {
  COLLISION_OBJECT_HDR;  // 0x00
  struct Zero* player;   // 0xB4
  u8 unk_b8;             // 0xB8
  u8 unk_b9;             // 0xB9
  Coords32 coord_bc;     // 0xBC
};
static_assert(sizeof(struct CyberElf1) == sizeof(CyberElf));

static void Elf1_Init(struct CyberElf1* p);
void Elf1_Update(struct CyberElf1* p);
void Elf1_Die(struct CyberElf1* p);

// clang-format off
const ElfRoutine gElf1Routine = {
    [ENTITY_INIT] =      (void*)Elf1_Init,
    [ENTITY_UPDATE] =    (void*)Elf1_Update,
    [ENTITY_DIE] =       (void*)Elf1_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteElf,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

struct Entity* CreateElf1(struct Zero* player, u8 breed, u8 availability, u8 _) {
  struct CyberElf1* p = AllocEntityLast(gElfHeaderPtr);
  if (p != NULL) {
    INIT_ELF_ROUTINE(p, 1);
    p->player = player;
    p->work[0] = breed, p->work[1] = availability;
  }
  return (struct Entity*)p;
}

// --------------------------------------------

static void Elf1_Init(struct CyberElf1* p) {
  struct Zero* z = p->player;
  struct Rect r = gZeroRanges[z->posture];
  gPause = TRUE;
  EnableSpriteAnimation_Normal(p);
  SetSpriteTableDynamic(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteAnimation(p, GetElfMotion(0));
  p->spr.xflip = FALSE;
  p->spr.oam.xflip = FALSE;
  p->flags &= ~X_FLIP;
  p->coord.x = (z->s).coord.x + r.x;
  p->coord.y = (z->s).coord.y + r.y;
  (&p->coord_bc)->x = 0;
  (&p->coord_bc)->y = 0;
  p->unk_b8 = 0;
  p->unk_b9 = 32;
  SET_ELF_ROUTINE(p, ENTITY_UPDATE);
  Elf1_Update((struct CyberElf1*)p);
}

INCASM("asm/cyberelf/unk_1_a.inc");

void FUN_080e2310(CyberElf* p) {
  struct Coord c;
  struct Zero* z = *(struct Zero**)&p->buffer[0];
  c.x = (z->s).coord.x;
  c.y = (z->s).coord.y;
  if (FUN_080e1578((struct Coord*)&p->buffer[8], &p->unk_coord, &c, &p->buffer[6], 0xA0)) {
    p->mode[1]++;
  }
}

INCASM("asm/cyberelf/unk_1_b.inc");

void FUN_080e2310(CyberElf* p);
void FUN_080e234c(CyberElf* p);
void FUN_080e23a4(CyberElf* p);
void FUN_080e23fc(CyberElf* p);
void FUN_080e2414(CyberElf* p);
void FUN_080e244c(CyberElf* p);

// clang-format off
const CyberElfFunc sElf1Updates[6] = {
    FUN_080e2310,
    FUN_080e234c,
    FUN_080e23a4,
    FUN_080e23fc,
    FUN_080e2414,
    FUN_080e244c,
}; // 0x08371ca0
// clang-format on
