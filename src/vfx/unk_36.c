#include "global.h"
#include "vfx.h"

// volteel の尻尾と電撃

static void VFX36_Init(struct Entity* p);
static void VFX36_Update(struct Entity* p);
static void VFX36_Die(struct Entity* p);

// clang-format off
const VFXRoutine gVFX36Routine = {
    [ENTITY_INIT] =      (VFXFunc)VFX36_Init,
    [ENTITY_UPDATE] =    (VFXFunc)VFX36_Update,
    [ENTITY_DIE] =       (VFXFunc)VFX36_Die,
    [ENTITY_DISAPPEAR] = (VFXFunc)DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

struct Entity* FUN_080bc058(struct Entity* e, Coords32* c, u8 kind) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_036);
    p->work[0] = kind, p->work[1] = 0;
    p->coord.x = c->x, p->coord.y = c->y;
    p->unk_28 = e;
  }
  return p;
}

struct Entity* volteel_080bc0b0(struct Entity* e, Coords32* c, u8 kind) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_036);
    p->work[0] = kind, p->work[1] = 1;
    p->coord.x = c->x, p->coord.y = c->y;
    p->unk_28 = e;
  }
  return p;
}

// --------------------------------------------

static void VFX36_Init(struct Entity* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteTableDynamic(p);
  if (p->work[0] == 0) {
    SET_XFLIP(p, FALSE);
    (p->d).x = PIXEL(1) / 2;  // 右
  } else {
    SET_XFLIP(p, TRUE);
    (p->d).x = -PIXEL(1) / 2;  // 左
  }
  (p->d).y = 0;

  if (p->work[1] == 0) {
    p->work[2] = 0xFF;
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 1, p->mode[2] = 0, p->mode[3] = 0;
  } else {
    p->work[2] = 0xFF;
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 0, p->mode[2] = 0, p->mode[3] = 0;
  }
  VFX36_Update((void*)p);
}

void FUN_080bc200(struct VFX* vfx);
void FUN_080bc464(struct VFX* vfx);

static void VFX36_Update(struct Entity* p) {
  static const VFXFunc sUpdates[2] = {
      (VFXFunc)FUN_080bc200,
      (VFXFunc)FUN_080bc464,
  };  // 0x0836edb8
  (sUpdates[p->mode[1]])((void*)p);
}

static void VFX36_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

INCASM("asm/vfx/unk_36.inc");
