#include "global.h"
#include "vfx.h"

static void VFX49_Init(struct Entity* p);
static void VFX49_Update(struct Entity* p);
static void VFX49_Die(struct Entity* p);

// clang-format off
const VFXRoutine gVFX49Routine = {
    [ENTITY_INIT] =      (void*)VFX49_Init,
    [ENTITY_UPDATE] =    (void*)VFX49_Update,
    [ENTITY_DIE] =       (void*)VFX49_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void FUN_080c025c(s32 x, s32 y) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_049);
    p->work[0] = 0;
    p->coord.x = x, p->coord.y = y;
  }
}

void createLaserSign(struct Entity* e, s32 x, s32 y) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_049);
    p->work[0] = 1;
    p->coord.x = x, p->coord.y = y;
    p->unk_28 = (void*)e;
  }
}

void FUN_080c02f4(s32 x, s32 y) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_049);
    p->work[0] = 2;
    p->coord.x = x, p->coord.y = y;
  }
}

void FUN_080c0340(struct Entity* e) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_049);
    p->work[0] = 3;
    p->unk_28 = (void*)e;
  }
}

// --------------------------------------------

static const u8 sInitModes[];

static void VFX49_Init(struct Entity* p) {
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  VFX49_Update(p);
}

void FUN_080c0400(struct VFX* p);
void FUN_080c04d4(struct VFX* p);
void FUN_080c05a8(struct VFX* p);
void FUN_080c065c(struct VFX* p);

static void VFX49_Update(struct Entity* p) {
  static const VFXFunc sUpdates[4] = {
      (void*)FUN_080c0400,
      (void*)FUN_080c04d4,
      (void*)FUN_080c05a8,
      (void*)FUN_080c065c,
  };
  (sUpdates[p->mode[1]])((void*)p);
}

static void VFX49_Die(struct Entity* p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }

INCASM("asm/vfx/unk_49.inc");

static const u8 sInitModes[4] = {0, 1, 2, 3};
