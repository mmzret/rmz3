#include "global.h"
#include "vfx.h"

// ベビーエルフ関連

void VFX37_Init(struct VFX* vfx);
void VFX37_Update(struct VFX* vfx);
void VFX37_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX37Routine = {
    [ENTITY_INIT] =      (void*)VFX37_Init,
    [ENTITY_UPDATE] =    (void*)VFX37_Update,
    [ENTITY_DIE] =       (void*)VFX37_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080bc540(s32 x1, s32 y1, s32 x2, s32 y2) {
  struct Entity* p = AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_037);
    p->work[0] = 0;
    (p->coord).x = x1, (p->coord).y = y1;
    (p->d).x = x2, (p->d).y = y2;
  }
}

void FUN_080bc594(s32 x1, s32 y1, s32 x2, s32 y2, u8 n) {
  struct Entity* p = AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_037);
    p->work[0] = 1;
    (p->coord).x = x1, (p->coord).y = y1;
    (p->d).x = x2, (p->d).y = y2;
    p->work[2] = n;
  }
}

void FUN_080bc5fc(struct Entity* e, u8 n) {
  s32 i;
  for (i = 0; i < 6; i++) {
    struct Entity* p = AllocEntityFirst(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_UNK_037);
      p->work[0] = 2;
      p->unk_28 = e;
      p->work[2] = i;
      p->work[3] = n + i;
    }
  }
}

void FUN_080bc660(s32 x, s32 y) {
  struct Entity* p = AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_037);
    p->work[0] = 3;
    (p->coord).x = x, (p->coord).y = y;
  }
}

static const u8 u8_ARRAY_0836edf0[7];

INCASM("asm/vfx/unk_37_a.inc");

void FUN_080bc758(s32 x, s32 y) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_037);
    p->work[0] = 5;
    p->coord.x = x;
    p->coord.y = y;
  }
}

INCASM("asm/vfx/unk_37_b.inc");

extern const u8 u8_ARRAY_0836edf0[7];

void VFX37_Init(struct VFX* vfx) {
  SET_VFX_ROUTINE(vfx, ENTITY_UPDATE);
  (vfx->s).mode[1] = u8_ARRAY_0836edf0[(vfx->s).work[0]];
  (vfx->s).flags |= FLIPABLE;
  (vfx->s).flags |= DISPLAY;
  EnableSpriteAnimation_Normal(vfx);
  VFX37_Update(vfx);
}

extern const VFXFunc PTR_ARRAY_0836edd4[7];

void VFX37_Update(struct VFX* vfx) {
  (PTR_ARRAY_0836edd4[(vfx->s).mode[1]])(vfx);
}


void VFX37_Die(struct VFX* vfx) {
  SET_VFX_ROUTINE(vfx, ENTITY_EXIT);
}

INCASM("asm/vfx/unk_37_c.inc");

// --------------------------------------------

void FUN_080bc8c0(struct VFX* vfx);
void FUN_080bc974(struct VFX* vfx);
void FUN_080bca5c(struct VFX* vfx);
void FUN_080bcb6c(struct VFX* vfx);
void FUN_080bcc94(struct VFX* vfx);
void FUN_080bcd9c(struct VFX* vfx);
void FUN_080bce48(struct VFX* vfx);

// clang-format off
const VFXFunc PTR_ARRAY_0836edd4[7] = {
    FUN_080bc8c0,
    FUN_080bc974,
    FUN_080bca5c,
    FUN_080bcb6c,
    FUN_080bcc94,
    FUN_080bcd9c,
    FUN_080bce48,
};
// clang-format on

static const u8 u8_ARRAY_0836edf0[7] = {0, 1, 2, 3, 4, 5, 6};

const motion_t motion_t_ARRAY_0836edf8[3] = {
    MOTION(SM050_CREA_PREA, 0),
    MOTION(SM050_CREA_PREA, 1),
    MOTION(SM050_CREA_PREA, 2),
};

const s16 s16_ARRAY_0836edfe[6] = {
    0x00C0, 0x0080, 0x0010, -0x0080, -0x00C0, -0x0100,
};

const motion_t motion_t_ARRAY_0836ee0a[3] = {
    MOTION(SM050_CREA_PREA, 0),
    MOTION(SM050_CREA_PREA, 1),
    MOTION(SM050_CREA_PREA, 2),
};
