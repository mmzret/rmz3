#include "entity.h"
#include "vfx.h"
#include "global.h"

static void Ghost70_Init(struct VFX* p);
void Ghost70_Update(struct VFX* p);
void Ghost70_Die(struct VFX* p);

// clang-format off
const VFXRoutine gGhost70Routine = {
    [ENTITY_INIT] =      Ghost70_Init,
    [ENTITY_UPDATE] =    Ghost70_Update,
    [ENTITY_DIE] =       Ghost70_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct VFX* FUN_080c5628(u8 r0, u8 r1, s32 x, s32 y) {
  struct VFX* p = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 1;
    INIT_VFX_ROUTINE(p, VFX_UNK_070);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).work[0] = r0;
    (p->s).work[1] = r1;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    (p->s).d.x = 0;
    (p->s).d.y = 0;
  }
  return p;
}

struct VFX* FUN_080c5684(u8 r0, u8 r1, s32 x, s32 y, s32 dx, s32 dy) {
  struct VFX* p = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 1;
    INIT_VFX_ROUTINE(p, VFX_UNK_070);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).work[0] = r0;
    (p->s).work[1] = r1;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    (p->s).d.x = dx;
    (p->s).d.y = dy;
  }
  return p;
}

// --------------------------------------------

void FUN_080c572c(struct VFX* p);

static void Ghost70_Init(struct VFX* p) {
  // clang-format off
  static VFXFunc const sInitializers[] = {
      FUN_080c572c,
      FUN_080c572c,
      FUN_080c572c,
      FUN_080c572c,
      FUN_080c572c,
      FUN_080c572c,
  };
  // clang-format on
  (sInitializers[(p->s).work[0]])(p);
}

INCASM("asm/vfx/unk_70.inc");

// --------------------------------------------

void FUN_080c5764(struct VFX* p);
void FUN_080c57a4(struct VFX* p);
void FUN_080c5860(struct VFX* p);
void FUN_080c598c(struct VFX* p);
void FUN_080c5b30(struct VFX* p);
void FUN_080c5c64(struct VFX* p);

// clang-format off
const VFXFunc sGhost70Updates[6] = {
  FUN_080c5764,
  FUN_080c57a4,
  FUN_080c5860,
  FUN_080c598c,
  FUN_080c5b30,
  FUN_080c5c64,
};
// clang-format on

// --------------------------------------------

void FUN_080c5784(struct VFX* p);

// clang-format off
const VFXFunc sGhost70Deinitializers[6] = {
  FUN_080c5784,
  FUN_080c5784,
  FUN_080c5784,
  FUN_080c5784,
  FUN_080c5784,
  FUN_080c5784,
};
// clang-format on
