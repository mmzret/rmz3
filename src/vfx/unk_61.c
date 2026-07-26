#include "global.h"
#include "vfx.h"
#include "vfx/unk_common.h"

// Mothjiro 関連

void VFX61_Init(struct VFX* vfx);
void VFX61_Update(struct VFX* vfx);
void VFX61_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX61Routine = {
    [ENTITY_INIT] =      (void*)VFX61_Init,
    [ENTITY_UPDATE] =    (void*)VFX61_Update,
    [ENTITY_DIE] =       (void*)VFX61_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

struct Entity* FUN_080c2e7c(Coords32* c, u8 kind) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_061);
    p->work[0] = kind, p->work[1] = 0;
    (p->coord).x = c->x, (p->coord).y = c->y;
  }
  return p;
}

struct Entity* FUN_080c2ed0(Coords32* c, u8 kind, motion_t m, u32 val) {
  VFXUnkCommon* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_061);
    p->work[0] = kind, p->work[1] = 1;
    p->coord.x = c->x, p->coord.y = c->y;
    p->m_74 = m;
    p->unk_78 = val;
  }
  return (void*)p;
}

struct Entity* FUN_080c2f3c(Coords32* c, u8 kind) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_061);
    p->work[0] = kind, p->work[1] = 2;
    (p->coord).x = c->x, (p->coord).y = c->y;
  }
  return p;
}

// --------------------------------------------

INCASM("asm/vfx/unk_61.inc");

static const s32* const PTR_s32_ARRAY_0836f490[3];

void FUN_080c338c(struct VFX* vfx) {
  VFXUnkCommon* w = (void*)vfx;
  u16 attr;
  w->work[2]--;
  if (w->work[2] == 0 ||
      ((attr = FUN_080098a4((w->coord).x, (w->coord).y)) != 0 &&
       !(attr & 0x8000) && (w->d).y > 0)) {
    CreateSmoke(2, &w->coord);
    SET_VFX_ROUTINE(w, ENTITY_DIE);
  } else {
    switch (w->mode[2]) {
      case 0: {
        const s32* const* tbl = PTR_s32_ARRAY_0836f490;
        motion_t* mp = &w->m_74;
        u32 base = (u32)tbl[*mp % 3];
        const s32* pair = (const s32*)(w->unk_78 * 8 + base);
        (w->d).y = pair[1] + (RANDOM(RNG_0202f388) & 0x1F);
        (w->d).x = pair[0] - (RANDOM(RNG_0202f388) & 0x3F);
        SetSpriteAnimation(w, *mp);
        w->work[3] = 0;
        w->mode[2]++;
        FALLTHROUGH;
      }
      case 1: {
        if ((u8)++w->work[3] & 1) {
          w->flags |= DISPLAY;
        } else {
          w->flags &= ~DISPLAY;
        }
        (w->d).y += 0x20;
        if ((w->d).y > 0x700) {
          (w->d).y = 0x700;
        }
        (w->coord).y += (w->d).y;
        (w->coord).x += (w->d).x;
        UpdateSpriteAnimation(w);
        break;
      }
    }
  }
}

// --------------------------------------------

void FUN_080c3108(struct VFX* vfx);
void FUN_080c3214(struct VFX* vfx);
void FUN_080c338c(struct VFX* vfx);

static const VFXFunc sUpdates[3] = {
    FUN_080c3108,
    FUN_080c3214,
    FUN_080c338c,
};

static const s32 s32_ARRAY_0836f430[8 * 3] = {
    0x00000120, -0x00000260, -0x000000B0, -0x000001A0, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, -0x000000B0, -0x000001A0, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, 0x00000120, -0x00000260, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, 0x00000120, -0x00000260, -0x000000B0, -0x000001A0,
};

static const s32* const PTR_s32_ARRAY_0836f490[3] = {
    &s32_ARRAY_0836f430[0],
    &s32_ARRAY_0836f430[8],
    &s32_ARRAY_0836f430[16],
};
