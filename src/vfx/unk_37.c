#include "entity/macros.h"
#include "global.h"
#include "vfx.h"
#include "trig.h"

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

void FUN_080bc6ac(struct Entity* e, s32 x, s32 y, s32 speed, u8 angle) {
  struct VFX* p = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);

  if (p != NULL) {
    INIT_VFX_ROUTINE(p, 37);
    (p->s).work[0] = 4;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    (p->s).d.x = Cos(angle, speed);
    (p->s).d.y = -Sin(angle, speed);
    (p->s).unk_28 = e;
    *((u8*)e + 0xCF) += 1;
  }
}

INCASM("asm/vfx/unk_37_a.inc");

void FUN_080bc7a4(s32 x, s32 y, s32 speed, u8 angle, u8 n) {
  struct VFX* p = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);

  if (p != NULL) {
    INIT_VFX_ROUTINE(p, 37);
    (p->s).work[0] = 6;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    (p->s).d.x = Cos(angle, speed);
    (p->s).d.y = -Sin(angle, speed);
    (p->s).work[2] = n;
  }
}

INCASM("asm/vfx/unk_37_b.inc");

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
