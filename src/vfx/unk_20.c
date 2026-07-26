#include "entity.h"
#include "global.h"
#include "story.h"
#include "vfx.h"
#include "vfx/unk_common.h"

static void Ghost20_Init(struct Entity* p);
static void Ghost20_Update(struct Entity* p);
static void Ghost20_Die(struct Entity* p);

// clang-format off
const VFXRoutine gGhost20Routine = {
    [ENTITY_INIT] =      (void*)Ghost20_Init,
    [ENTITY_UPDATE] =    (void*)Ghost20_Update,
    [ENTITY_DIE] =       (void*)Ghost20_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct Entity* CreateGhost20(Coords32* c, u8 n) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_020);
    p->work[0] = n, p->work[1] = 0;
    p->coord.x = c->x, p->coord.y = c->y;
  }
  return p;
}

struct Entity* FUN_080b721c(Coords32* c, u8 kind, motion_t m, u32 val) {
  VFXUnkCommon* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_020);
    p->work[0] = kind, p->work[1] = 1;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->m_74 = m;
    p->unk_78 = val;
  }
  return (void*)p;
}

// --------------------------------------------

static void Ghost20_Init(struct Entity* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  if (p->work[0] == 0) {
    SET_XFLIP(p, FALSE);
    (p->d).x = -PIXEL(3) / 4;
  } else {
    SET_XFLIP(p, TRUE);
    (p->d).x = PIXEL(3) / 4;
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
  Ghost20_Update((void*)p);
}

static void FUN_080b73d0(void* _ UNUSED);
void FUN_080b73d4(struct VFX* p);
void FUN_080b754c(struct VFX* p);

static void Ghost20_Update(struct Entity* p) {
  static const VFXFunc sUpdates[3] = {
      (void*)FUN_080b73d0,
      (void*)FUN_080b73d4,
      (void*)FUN_080b754c,
  };  // 0x0836e8cc

  if (IS_METTAUR) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    Ghost20_Die(p);
    return;
  }
  (sUpdates[(p->mode)[1]])((void*)p);
}

static void Ghost20_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void FUN_080b73d0(void* _ UNUSED) {}

INCASM("asm/vfx/unk_20.inc");

extern const s32* const PTR_s32_ARRAY_0836e938[3];

void FUN_080b754c(struct VFX* p) {
  VFXUnkCommon* w = (void*)p;
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
        const s32* const* tbl = PTR_s32_ARRAY_0836e938;
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

const s32 s32_ARRAY_0836e8d8[8 * 3] = {
    0x00000120, -0x00000200, -0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, -0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, 0x00000120, -0x00000200, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, 0x00000120, -0x00000200, -0x000000B0, -0x00000160,
};

// 0x0836E938
const s32* const PTR_s32_ARRAY_0836e938[3] = {
    &s32_ARRAY_0836e8d8[0],
    &s32_ARRAY_0836e8d8[8],
    &s32_ARRAY_0836e8d8[16],
};
