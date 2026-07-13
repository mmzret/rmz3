#include "global.h"
#include "metatile.h"
#include "vfx.h"

// コピーXのアイスショットのパーティクル

static void VFX53_Init(struct Entity* p);
static void VFX53_Update(struct Entity* p);
static void VFX53_Die(struct Entity* p);

// clang-format off
const VFXRoutine gVFX53Routine = {
    [ENTITY_INIT] =      (VFXFunc)VFX53_Init,
    [ENTITY_UPDATE] =    (VFXFunc)VFX53_Update,
    [ENTITY_DIE] =       (VFXFunc)VFX53_Die,
    [ENTITY_DISAPPEAR] = (VFXFunc)DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void CreateVFX53(struct Entity* e, u8 n) {
  if (gVFXHeaderPtr->remaining > 23) {
    struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_UNK_053);
      p->work[0] = n;
      p->work[1] = 0;
      p->unk_28 = (void*)e;
      *(&p->coord) = *(&e->coord);
    }
  }
}

static void VFX53_Init(struct Entity* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM092_COPYX_ELEC_ICE_SHOT, 4));
  p->work[2] = 32;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 0;
  VFX53_Update((void*)p);
}

static void VFX53_Update(struct Entity* p) {
  UpdateSpriteAnimation(p);
  p->work[2]--;
  if ((p->work[2] & 3) >= 2) {  // 2フレームごとに点滅
    p->flags |= DISPLAY;
  } else {
    p->flags &= ~DISPLAY;
  }
  if (p->work[0] != 0) {
    (p->coord).y += PIXEL(1);
    if (FUN_080098a4((p->coord).x, (p->coord).y)) {
      SET_VFX_ROUTINE(p, ENTITY_DIE);
      return;
    }
  }
  if (p->work[2] == 0) SET_VFX_ROUTINE(p, ENTITY_DIE);
}

static void VFX53_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}
