#include "global.h"
#include "vfx.h"

struct VFX39 {
  struct Entity s;
  // props (16bytes, offset: 0x74..)
  u8 unk_74[4];
  u8 unk_78[4];
  u8 winin1;
  u8 winout;
  u32 pad_80;
};
static_assert(sizeof(struct VFX39) == sizeof(struct VFX));

static void VFX39_Init(struct VFX39* p);
static void VFX39_Update(struct VFX* vfx);
void VFX39_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX39Routine = {
    [ENTITY_INIT] =       (VFXFunc)VFX39_Init,
    [ENTITY_UPDATE] =     (VFXFunc)VFX39_Update,
    [ENTITY_DIE] =        (VFXFunc)VFX39_Die,
    [ENTITY_DISAPPEAR] =  (VFXFunc)DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// 0x080bd3bc
struct Entity* CreateVFX39(Coords32* c, u8 r1, u8 r2) {
  struct VFX39* p = (struct VFX39*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_039);
    (p->s).coord = *c;
    (p->s).work[0] = r1;
    (p->s).work[1] = r2;
    p->winin1 = 0x31;
    p->winout = 0x0E;
  }
  return (void*)p;
}

// --------------------------------------------

void TaskCB_080bd610(struct Sprite* s, struct DrawPivot* c);

static void VFX39_Init(struct VFX39* p) {
  SetTaskCallback((void*)&(p->s).spr, TaskCB_080bd610);
  (p->s).spr.sprites = (struct MetaspriteHeader*)p;
  (p->s).flags &= ~USE_COMMON_OAM_RENDERER;
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  p->unk_74[3] = 0;
  (p->s).d.y = PIXEL(0);
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  VFX39_Update((void*)p);
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
