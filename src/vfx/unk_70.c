#include "entity.h"
#include "global.h"
#include "vfx.h"

static void VFX70_Init(struct Entity* p);
static void VFX70_Update(struct Entity* p);
static void VFX70_Die(struct Entity* p);

// clang-format off
const VFXRoutine gGhost70Routine = {
    [ENTITY_INIT] =      (void*)VFX70_Init,
    [ENTITY_UPDATE] =    (void*)VFX70_Update,
    [ENTITY_DIE] =       (void*)VFX70_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct VFX* FUN_080c5628(u8 r0, u8 r1, s32 x, s32 y) {
  struct VFX* p = (struct VFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_070);
    (p->s).work[0] = r0, (p->s).work[1] = r1;
    (p->s).coord.x = x, (p->s).coord.y = y;
    (p->s).d.x = 0, (p->s).d.y = 0;
  }
  return p;
}

struct VFX* FUN_080c5684(u8 r0, u8 r1, s32 x, s32 y, s32 dx, s32 dy) {
  struct VFX* p = (struct VFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_070);
    (p->s).work[0] = r0, (p->s).work[1] = r1;
    (p->s).coord.x = x, (p->s).coord.y = y;
    (p->s).d.x = dx, (p->s).d.y = dy;
  }
  return p;
}

// --------------------------------------------

static void _VFX70_Init(struct Entity* p);

static void VFX70_Init(struct Entity* p) {
  // clang-format off
  static EntityFunc const sInitializers[] = {
      _VFX70_Init,
      _VFX70_Init,
      _VFX70_Init,
      _VFX70_Init,
      _VFX70_Init,
      _VFX70_Init,
  };
  // clang-format on
  (sInitializers[p->work[0]])(p);
}

static void FUN_080c5764(struct Entity* p);
void FUN_080c57a4(struct VFX* p);
void FUN_080c5860(struct VFX* p);
void FUN_080c598c(struct VFX* p);
void FUN_080c5b30(struct VFX* p);
void FUN_080c5c64(struct VFX* p);

static void VFX70_Update(struct Entity* p) {
  // clang-format off
  static const VFXFunc sUpdates[6] = {
    (void*)FUN_080c5764,
    (void*)FUN_080c57a4,
    (void*)FUN_080c5860,
    (void*)FUN_080c598c,
    (void*)FUN_080c5b30,
    (void*)FUN_080c5c64,
  }; // 0x0836f73c
  // clang-format on
  (sUpdates[p->work[0]])((void*)p);
}

static void _VFX70_Die(struct Entity* p);

static void VFX70_Die(struct Entity* p) {
  // clang-format off
  static const EntityFunc sDeinitializers[] = {
    _VFX70_Die,
    _VFX70_Die,
    _VFX70_Die,
    _VFX70_Die,
    _VFX70_Die,
    _VFX70_Die,
  };
  // clang-format on
  (sDeinitializers[p->work[0]])(p);
}

// --------------------------------------------

// 0x080c572c
static void _VFX70_Init(struct Entity* p) {
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  EnableSpriteAnimation_Normal(p);
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  VFX70_Update(p);
}

// 0x080c5764
static void FUN_080c5764(struct Entity* p) {
  SET_VFX_ROUTINE(p, ENTITY_DIE);
  VFX70_Die(p);
}

// 0x080c5784
static void _VFX70_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/vfx/unk_70.inc");
