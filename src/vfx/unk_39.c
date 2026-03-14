#include "global.h"
#include "vfx.h"

static void VFX39_Init(struct VFX* vfx);
static void VFX39_Update(struct VFX* vfx);
void VFX39_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX39Routine = {
    [ENTITY_INIT] =      VFX39_Init,
    [ENTITY_UPDATE] =    VFX39_Update,
    [ENTITY_DIE] =       VFX39_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct VFX* CreateVFX39(struct Coord* c, u8 r1, u8 r2) {
  struct VFX* vfx = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
  if (vfx != NULL) {
    (vfx->s).taskCol = 1;
    INIT_VFX_ROUTINE(vfx, VFX_UNK_039);
    (vfx->s).tileNum = 0;
    (vfx->s).palID = 0;
    (vfx->s).coord = *c;
    (vfx->s).work[0] = r1;
    (vfx->s).work[1] = r2;
    (vfx->props).unk39.winin1 = 0x31;
    (vfx->props).unk39.winout = 0x0E;
  }
  return vfx;
}

// --------------------------------------------

void TaskCB_080bd610(struct Sprite* s, struct DrawPivot* c);

static void VFX39_Init(struct VFX* vfx) {
  SetTaskCallback((struct Task*)&(vfx->s).spr, TaskCB_080bd610);
  (vfx->s).spr.sprites = (struct MetaspriteHeader*)vfx;
  (vfx->s).flags &= ~OAM_PRIO;
  (vfx->s).flags |= DISPLAY;
  (vfx->s).flags |= FLIPABLE;
  (vfx->props).unk39.unk_0[3] = 0;
  (vfx->s).d.y = PIXEL(0);
  SET_VFX_ROUTINE(vfx, ENTITY_UPDATE);
  VFX39_Update(vfx);
}

// --------------------------------------------

void FUN_080bd48c(struct VFX* vfx);
void FUN_080bd578(struct VFX* vfx);
void FUN_080bd578(struct VFX* vfx);
void FUN_080bd578(struct VFX* vfx);

static void VFX39_Update(struct VFX* vfx) {
  static const VFXFunc sUpdates[4] = {
      FUN_080bd48c,
      FUN_080bd578,
      FUN_080bd578,
      FUN_080bd578,
  };
  (sUpdates[(vfx->s).work[0]])(vfx);
}

// --------------------------------------------

INCASM("asm/vfx/unk_39.inc");
