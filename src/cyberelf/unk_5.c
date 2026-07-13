#include "cyberelf.h"
#include "entity.h"
#include "global.h"
#include "score.h"
#include "vfx.h"
#include "zero.h"

struct CyberElf5 {
  OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  struct Zero* player;  // 0xB4
  u8 unk_b8[12];        // 0xB8
};
static_assert(sizeof(struct CyberElf5) == sizeof(struct Elf));

static void Elf5_Init(struct CyberElf5* p);
static void Elf5_Update(struct CyberElf5* p);
static void Elf5_Die(struct CyberElf5* p);

// clang-format off
const ElfRoutine gElf5Routine = {
    [ENTITY_INIT] =      (void*)Elf5_Init,
    [ENTITY_UPDATE] =    (void*)Elf5_Update,
    [ENTITY_DIE] =       (void*)Elf5_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteElf,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* CreateElf5(struct Zero* player, u8 breed, u8 availability, u8 _) {
  struct CyberElf5* p = (struct CyberElf5*)AllocEntityLast(gElfHeaderPtr);
  if (p != NULL) {
    INIT_ELF_ROUTINE(p, 5);
    p->player = player;
    (p->s).work[0] = breed, (p->s).work[1] = availability;
  }
  return (struct Entity*)p;
}

// --------------------------------------------

static void Elf5_Init(struct CyberElf5* p) {
  struct Zero* z = p->player;
  struct Rect r = gZeroRanges[z->posture];
  gPause = TRUE;
  SET_ELF_ROUTINE(p, ENTITY_UPDATE);
  EnableSpriteAnimation_Normal(p);
  ResetDynamicMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(DM144_CYBERELF_NURSE, 0));
  (p->s).spr.xflip = FALSE, (p->s).spr.oam.xflip = FALSE;
  (p->s).flags &= ~X_FLIP;
  (p->s).spr.oam.priority = 0;
  (p->s).coord.x = (z->s).coord.x + r.x;
  (p->s).coord.y = (z->s).coord.y + r.y;
  Elf5_Update(p);
}

static void Elf5_Update(struct CyberElf5* p) {
  UpdateSpriteAnimation(p);
  SET_ELF_ROUTINE(p, ENTITY_DIE);
  Elf5_Die(p);
}

// 0x080e35a8
static void Elf5_Die(struct CyberElf5* p) {
  u8** flags;
  struct Zero_b4* b4;
  struct Zero* z = p->player;
  gPause = FALSE;
  flags = &gElfAvailability;
  b4 = &(z->unk_b4);
  (*flags)[z->unk_121] |= ELF_AVABILITY_USED;
  (b4->status).fusions += 3;
  if ((gScore.total)->fusionCount < 99) (gScore.total)->fusionCount++;
  FUN_080bfce8(&(p->s).coord, 0);
  (p->s).flags &= ~DISPLAY;
  SET_ELF_ROUTINE(p, ENTITY_EXIT);
}
