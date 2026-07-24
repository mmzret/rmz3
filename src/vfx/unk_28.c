#include "entity.h"
#include "global.h"
#include "story.h"
#include "vfx.h"
#include "vfx/unk_common.h"

static void Ghost28_Init(struct VFX* p);
static void Ghost28_Update(struct VFX* p);
static void Ghost28_Die(struct VFX* p);

// clang-format off
const VFXRoutine gGhost28Routine = {
    [ENTITY_INIT] =      (VFXFunc)Ghost28_Init,
    [ENTITY_UPDATE] =    (VFXFunc)Ghost28_Update,
    [ENTITY_DIE] =       (VFXFunc)Ghost28_Die,
    [ENTITY_DISAPPEAR] = (VFXFunc)DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct Entity* FUN_080b9e68(Coords32* c, u8 n) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, 28);
    p->work[0] = n, p->work[1] = 0;
    (p->coord).x = c->x;
    (p->coord).y = c->y;
  }
  return p;
}

struct Entity* FUN_080b9ebc(Coords32* c, u8 n, motion_t m, s32 val) {
  VFXUnkCommon* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, 28);
    p->work[0] = n, p->work[1] = 1;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->m_74 = m, p->unk_78 = val;
  }
  return (void*)p;
}

static void Ghost28_Init(struct VFX* p) {
  EnableSpriteAnimation_Normal(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  if ((p->s).work[0] == 0) {
    SET_XFLIP(p, FALSE);
  } else {
    SET_XFLIP(p, TRUE);
  }
  if ((p->s).work[0] == 0) {
    (p->s).d.x = -PIXEL(3) / 4;
  } else {
    (p->s).d.x = PIXEL(3) / 4;
  }
  (p->s).d.y = 0;

  if ((p->s).work[1] == 0) {
    (p->s).work[2] = 0xFF;
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    (p->s).mode[1] = 1, (p->s).mode[2] = 0, (p->s).mode[3] = 0;
  } else {
    (p->s).work[2] = 127 + (RANDOM(RNG_0202f388) & 7);
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    (p->s).mode[1] = 2, (p->s).mode[2] = 0, (p->s).mode[3] = 0;
  }
  Ghost28_Update(p);
}

// --------------------------------------------

static void nop_080ba078(void* _ UNUSED);
void FUN_080ba07c(struct VFX* p);
void FUN_080ba16c(struct VFX* p);

static void Ghost28_Update(struct VFX* p) {
  static const VFXFunc sUpdates[] = {
      (VFXFunc)nop_080ba078,
      (VFXFunc)FUN_080ba07c,
      (VFXFunc)FUN_080ba16c,
  };
  if (IS_METTAUR) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    Ghost28_Die(p);
    return;
  }
  (sUpdates[(p->s).mode[1]])(p);
}

static void Ghost28_Die(struct VFX* p) {
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

static void nop_080ba078(void* _ UNUSED) { return; }

INCASM("asm/vfx/unk_28.inc");

static const s32 s32_ARRAY_ARRAY_0836eb4c[3][8] = {
    {0x00000120, -0x00000260, -0x000000B0, -0x000001A0, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0},
    {-0x000000B0, -0x000001A0, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, 0x00000120, -0x00000260},
    {-0x000000B0, -0x00000260, 0x00000120, -0x000001A0, 0x00000120, -0x00000260, -0x000000B0, -0x000001A0},
};

// 0x0836EBAC
static const s32* const PTR_ARRAY_0836ebac[3] = {
    s32_ARRAY_ARRAY_0836eb4c[0],
    s32_ARRAY_ARRAY_0836eb4c[1],
    s32_ARRAY_ARRAY_0836eb4c[2],
};
