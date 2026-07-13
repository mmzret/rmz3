#include "global.h"
#include "story.h"
#include "vfx.h"
#include "vfx/unk_common.h"

// Shelluno

static void VFX38_Init(struct Entity* p);
static void VFX38_Update(struct Entity* p);
static void VFX38_Die(struct Entity* p);

// clang-format off
const VFXRoutine gVFX38Routine = {
    [ENTITY_INIT] =      (void*)VFX38_Init,
    [ENTITY_UPDATE] =    (void*)VFX38_Update,
    [ENTITY_DIE] =       (void*)VFX38_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* FUN_080bcf68(Coords32* c, u8 kind) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_038);
    p->work[0] = kind, p->work[1] = 0;
    p->coord.x = c->x, p->coord.y = c->y;
  }
  return p;
}

struct Entity* FUN_080bcfbc(Coords32* c, u8 kind, motion_t m, u32 val) {
  struct VFXUnkCommon* p = (struct VFXUnkCommon*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_038);
    (p->s).work[0] = kind, (p->s).work[1] = 1;
    (p->s).coord.x = c->x, (p->s).coord.y = c->y;
    p->m_74 = m;
    p->unk_78 = val;
  }
  return (void*)p;
}

// --------------------------------------------

static void VFX38_Init(struct Entity* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  if (p->work[0] == 0) {
    SET_XFLIP(p, FALSE);
  } else {
    SET_XFLIP(p, TRUE);
  }
  if (p->work[0] == 0) {
    (p->d).x = -PIXEL(1) / 2;
  } else {
    (p->d).x = PIXEL(1) / 2;
  }
  (p->d).y = 0;

  if (p->work[1] == 0) {
    p->work[2] = 0xFF;
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 1, p->mode[2] = 0, p->mode[3] = 0;
  } else {
    p->work[2] = 127 + (RANDOM(RNG_0202f388) & 7);
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 2, p->mode[2] = 0, p->mode[3] = 0;
  }
  VFX38_Update(p);
}

static void nop_080bd17c(void* _ UNUSED);
void FUN_080bd180(struct VFX* p);
void FUN_080bd288(struct VFX* p);

static void VFX38_Update(struct Entity* p) {
  static const VFXFunc sUpdates[3] = {
      (void*)nop_080bd17c,
      (void*)FUN_080bd180,
      (void*)FUN_080bd288,
  };  // 0x0836ee24

  if (IS_METTAUR) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    VFX38_Die(p);
    return;
  }
  (sUpdates[(p->mode)[1]])((void*)p);
}

static void VFX38_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void nop_080bd17c(void* _ UNUSED) {}

INCASM("asm/vfx/unk_38.inc");

static const u8 u8_ARRAY_0836ee30[32 * 3] = {
    0x20, 0x01, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 0x50, 0xFF, 0xFF, 0xFF, 0xA0, 0xFE, 0xFF, 0xFF, 0x50, 0xFF, 0xFF, 0xFF, 0x00, 0xFE, 0xFF, 0xFF, 0x20, 0x01, 0x00, 0x00, 0xA0, 0xFE, 0xFF, 0xFF, 0x50, 0xFF, 0xFF, 0xFF, 0xA0, 0xFE, 0xFF, 0xFF, 0x50, 0xFF, 0xFF, 0xFF, 0x00, 0xFE, 0xFF, 0xFF, 0x20, 0x01, 0x00, 0x00, 0xA0, 0xFE, 0xFF, 0xFF, 0x20, 0x01, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 0x50, 0xFF, 0xFF, 0xFF, 0x00, 0xFE, 0xFF, 0xFF, 0x20, 0x01, 0x00, 0x00, 0xA0, 0xFE, 0xFF, 0xFF, 0x20, 0x01, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 0x50, 0xFF, 0xFF, 0xFF, 0xA0, 0xFE, 0xFF, 0xFF,
};

// 0x0836ee90
const u8* const PTR_ARRAY_0836ee90[3] = {
    &u8_ARRAY_0836ee30[0],
    &u8_ARRAY_0836ee30[32],
    &u8_ARRAY_0836ee30[64],
};
