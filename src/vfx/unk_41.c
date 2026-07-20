#include "global.h"
#include "vfx.h"
#include "vfx/unk_common.h"

// ヘルバットシルトのレーザーに関係?

static void VFX41_Init(struct Entity* p);
static void VFX41_Update(struct Entity* p);
static void VFX41_Die(struct Entity* p);

// clang-format off
const VFXRoutine gVFX41Routine = {
    [ENTITY_INIT] =      (void*)VFX41_Init,
    [ENTITY_UPDATE] =    (void*)VFX41_Update,
    [ENTITY_DIE] =       (void*)VFX41_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* FUN_080bdd74(struct Entity* e, Coords32* c, u8 kind) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_041);
    p->work[0] = kind, p->work[1] = 0;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->unk_28 = (void*)e;
  }
  return p;
}

struct Entity* FUN_080bddcc(Coords32* c, u8 kind, motion_t m, u32 val) {
  VFXUnkCommon* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_041);
    p->work[0] = kind, p->work[1] = 1;
    p->coord.x = c->x, p->coord.y = c->y;
    p->m_74 = m;
    p->unk_78 = val;
  }
  return (void*)p;
}

struct Entity* createHellbatElectricBeam(struct Entity* e, Coords32* c, u8 kind, u8 param_4) {
  VFXUnkCommon* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_041);
    p->work[0] = kind;
    p->unk_7c = param_4;
    p->work[1] = 2;
    p->coord.x = c->x, p->coord.y = c->y;
    p->unk_28 = (void*)e;
  }
  return (void*)p;
}

struct Entity* FUN_080bde9c(struct Entity* e, Coords32* c, u8 kind, u8 param_4) {
  VFXUnkCommon* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_041);
    p->work[0] = kind;
    p->unk_7c = param_4;
    p->work[1] = 3;
    p->coord.x = c->x, p->coord.y = c->y;
    p->unk_28 = (void*)e;
  }
  return (void*)p;
}

// --------------------------------------------

static void VFX41_Init(struct Entity* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteTableDynamic(p);
  if (p->work[0] == 0) {
    SET_XFLIP(p, FALSE);
    (p->d).x = PIXEL(1) / 2;
  } else {
    SET_XFLIP(p, TRUE);
    (p->d).x = -PIXEL(1) / 2;
  }
  (p->d).y = 0;

  if (p->work[1] == 0) {
    p->work[2] = 0xFF;
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 1, p->mode[2] = 0, p->mode[3] = 0;
  } else if (p->work[1] == 1) {
    p->work[2] = 0xFF;
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 0, p->mode[2] = 0, p->mode[3] = 0;
  } else if (p->work[1] == 2) {
    p->work[2] = 0xFF;
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 2, p->mode[2] = 0, p->mode[3] = 0;
  } else if (p->work[1] == 3) {
    p->work[2] = 0xFF;
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 3, p->mode[2] = 0, p->mode[3] = 0;
  }
  VFX41_Update((void*)p);
}

void FUN_080be020(struct VFX* p);
void FUN_080be154(struct VFX* p);
void FUN_080be230(struct VFX* p);
void FUN_080be330(struct VFX* p);

static void VFX41_Update(struct Entity* p) {
  static const VFXFunc sUpdates[4] = {
      (void*)FUN_080be020,
      (void*)FUN_080be154,
      (void*)FUN_080be230,
      (void*)FUN_080be330,
  };  // 0x0836eef8
  (sUpdates[(p->mode)[1]])((void*)p);
}

static void VFX41_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

INCASM("asm/vfx/unk_41.inc");

// --------------------------------------------

static const s32 s32_ARRAY_ARRAY_0836ef08[8 * 3] = {
    0x00000120, -0x00000200, -0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, -0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, 0x00000120, -0x00000200, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, 0x00000120, -0x00000200, -0x000000B0, -0x00000160,
};

static const s32* const PTR_ARRAY_0836ef68[3] = {
    &s32_ARRAY_ARRAY_0836ef08[0],
    &s32_ARRAY_ARRAY_0836ef08[8],
    &s32_ARRAY_ARRAY_0836ef08[16],
};

static const motion_t motion_t_ARRAY_0836ef74[3] = {
    MOTION(DM169_HELLBAT_LASER, 9),
    MOTION(DM169_HELLBAT_LASER, 8),
    MOTION(DM169_HELLBAT_LASER, 7),
};

static const motion_t motion_t_ARRAY_0836ef7a[3] = {
    MOTION(DM169_HELLBAT_LASER, 13),
    MOTION(DM169_HELLBAT_LASER, 12),
    MOTION(DM169_HELLBAT_LASER, 11),
};
