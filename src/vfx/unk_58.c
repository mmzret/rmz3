#include "motion.h"
#include "global.h"
#include "vfx.h"

// VFX75 のほぼコピペ?
// オメガ第一形態の剣の残骸?

struct VFX58 {
  struct Entity s;
  // props (16bytes, offset: 0x74..)
  u8 unk_74[12];
  motion_t m_80;
};
static_assert(sizeof(struct VFX58) == sizeof(struct VFX));

void VFX58_Init(struct VFX* p);
void VFX58_Update(struct VFX* p);
void VFX58_Die(struct VFX* p);

// clang-format off
const VFXRoutine gVFX58Routine = {
    [ENTITY_INIT] =      (void*)VFX58_Init,
    [ENTITY_UPDATE] =    (void*)VFX58_Update,
    [ENTITY_DIE] =       (void*)VFX58_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

struct Entity* FUN_080c1b98(Coords32* c, u8 n) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_058);
    p->work[0] = n;
    p->coord.x = c->x, p->coord.y = c->y;
  }
  return p;
}

// 0x080c1bec
static struct Entity* unused_FUN_080c1bec(Coords32* c, u8 n, struct Entity* e) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_058);
    p->work[0] = n;
    p->coord.x = c->x, p->coord.y = c->y;
    p->unk_28 = (void*)e;
  }
  return p;
}

static struct Entity* unused_FUN_080c1c44(Coords32* c) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_058);
    p->work[0] = 4;
    p->coord.x = c->x, p->coord.y = c->y;
  }
  return p;
}

struct Entity* FUN_080c1c94(Coords32* c, u8 n, motion_t param_3) {
  struct VFX58* p = (struct VFX58*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_058);
    (p->s).work[0] = 6;
    (p->s).coord.x = c->x, (p->s).coord.y = c->y;
    (p->s).work[1] = n;
    p->m_80 = param_3;
  }
  return (void*)p;
}

INCASM("asm/vfx/unk_58_a.inc");

void FUN_080c248c(struct VFX* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SetMotion(&p->s, *(motion_t*)&p->buffer[12]);
      (p->s).work[2] = 0x28;
      (p->s).mode[2]++;
      // fallthrough
    case 1:
      UpdateEntityAnim(&p->s);
      if ((p->s).work[2] & 1) {
        (p->s).flags |= DISPLAY;
      } else {
        (p->s).flags &= ~DISPLAY;
      }
      if ((p->s).work[2] != 0 && --(p->s).work[2] == 0) {
        SET_VFX_ROUTINE(p, ENTITY_DIE);
      }
      break;
  }
}

INCASM("asm/vfx/unk_58_b.inc");

// --------------------------------------------

void FUN_080c2124(struct VFX* p);
void FUN_080c216c(struct VFX* p);
void FUN_080c21c0(struct VFX* p);
void FUN_080c2294(struct VFX* p);
void FUN_080c2364(struct VFX* p);
void FUN_080c2390(struct VFX* p);
void FUN_080c248c(struct VFX* p);
void FUN_080c2500(struct VFX* p);
void FUN_080c25f4(struct VFX* p);

// clang-format off
static const VFXFunc sUpdates[9] = {
    (void*)FUN_080c2124,
    (void*)FUN_080c216c,
    (void*)FUN_080c21c0,
    (void*)FUN_080c2294,
    (void*)FUN_080c2364,
    (void*)FUN_080c2390,
    (void*)FUN_080c248c,
    (void*)FUN_080c2500,
    (void*)FUN_080c25f4,
};
// clang-format on

static const s32 s32_ARRAY_0836f290[8 * 3] = {
    0x000002C0, -0x00000300, -0x00000220, -0x00000260, -0x00000220, -0x00000300, 0x000002C0, -0x00000260, -0x00000100, -0x000001F0, -0x00000200, -0x00000280, 0x00000160, -0x000001F0, 0x00000260, -0x00000280, -0x000000B0, -0x00000340, 0x00000120, -0x000002A0, 0x00000120, -0x00000340, -0x000000B0, -0x000002A0,
};

// 0x0836f2f0
const s32* const PTR_s32_ARRAY_0836f2f0[3] = {
    &s32_ARRAY_0836f290[0],
    &s32_ARRAY_0836f290[8],
    &s32_ARRAY_0836f290[16],
};
