#include "global.h"
#include "vfx.h"

// VFX75 のほぼコピペ?
// オメガ第一形態の剣の残骸?

struct VFX58 {
  struct Entity s;
  // props (16bytes, offset: 0x74..)
  Coords32 c;  // 0x74
  u8 unk_7c[4];
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

void FUN_080c2124(struct VFX* p) {
  (p->s).work[2]--;
  if ((p->s).work[2] == 0) {
    (p->s).work[2] = 8, (p->s).mode[1] = 1, (p->s).mode[2] = 0;
    return;
  }

  switch ((p->s).mode[2]) {
    case 0: {
      SetSpriteAnimation(&p->s, MOTION(SM010_OMEGA_RING, 8));
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(&p->s);
      break;
    }
  }
}

void FUN_080c216c(struct Entity* p) {
  if (--p->work[2] == 0) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
  } else {
    switch (p->mode[2]) {
      case 0:
        SetSpriteAnimation(p, MOTION(SM010_OMEGA_RING, 9));
        p->mode[2]++;
        FALLTHROUGH;
      case 1:
        UpdateSpriteAnimation(p);
        break;
    }
  }
}

INCASM("asm/vfx/unk_58_b.inc");

// 0x080c2294
void FUN_080c2294(struct VFX58* p) {
  if ((p->s).unk_28->mode[0] > 1 || --(p->s).work[2] == 0) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
  } else {
    struct Entity* parent;
    switch ((p->s).mode[2]) {
      case 0:
        SetSpriteAnimation(p, MOTION(SM011_OMEGA_RECOVER, 1));
        (p->s).work[3] = 0;
        (p->s).mode[2]++;
        FALLTHROUGH;
      case 1: {
        u8 t;
        Object* obj;
        parent = (p->s).unk_28;
        (p->s).coord.x = parent->coord.x + p->c.x;
        (p->s).coord.y = parent->coord.y + p->c.y;
        t = (p->s).work[3]++ & 1;
        obj = (Object*)parent;
        if (t) {
          (p->s).flags |= DISPLAY;
        } else {
          (p->s).flags &= ~DISPLAY;
        }
        if (obj->body.invincibleTime != 0 ||
            (gWhitePaintFlags[obj->invincibleID >> 5] & (1 << (obj->invincibleID & 0x1F))) ||
            (obj->body.status & BODY_STATUS_WHITE)) {
          (p->s).flags &= ~DISPLAY;
        }
        UpdateSpriteAnimation(p);
        break;
      }
    }
  }
}

INCASM("asm/vfx/unk_58_c.inc");

extern const s32* const PTR_s32_ARRAY_0836f2f0[3];

// 0x080c2500
void FUN_080c2500(struct VFX58* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      const s32* const* tbl = PTR_s32_ARRAY_0836f2f0;
      u16* mp = &p->m_80;
      u16 idx = *mp % 3;
      const s32* base = tbl[idx];
      {
        const s32* e = base + (p->s).work[1] * 2;
        RNG_0202f388 = LCG(RNG_0202f388);
        (p->s).d.y = e[1] - ((RNG_0202f388 >> 16) & 0x1F);
      }
      {
        s32 x = base[(p->s).work[1] * 2] - 0x20;
        RNG_0202f388 = LCG(RNG_0202f388);
        (p->s).d.x = x + ((RNG_0202f388 >> 16) & 0x3F);
      }
      SetSpriteAnimation(p, *mp);
      (p->s).work[2] = 0x50;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      UpdateSpriteAnimation(p);
      (p->s).d.y += 0x20;
      if ((p->s).d.y > 0x700) {
        (p->s).d.y = 0x700;
      }
      (p->s).coord.y += (p->s).d.y;
      (p->s).coord.x += (p->s).d.x;
      if ((p->s).work[2] == 0 || --(p->s).work[2] == 0) {
        SET_VFX_ROUTINE(p, ENTITY_DIE);
      }
      break;
  }
}

// 0x080c25f4
void FUN_080c25f4(struct VFX58* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      const s32* const* tbl = PTR_s32_ARRAY_0836f2f0;
      u16* mp = &p->m_80;
      u16 idx = *mp % 3;
      const s32* base = tbl[idx];
      {
        const s32* e = base + (p->s).work[1] * 2;
        RNG_0202f388 = LCG(RNG_0202f388);
        (p->s).d.y = e[1] - ((RNG_0202f388 >> 16) & 0x1F);
      }
      {
        s32 x = base[(p->s).work[1] * 2] - 0x20;
        RNG_0202f388 = LCG(RNG_0202f388);
        (p->s).d.x = x + ((RNG_0202f388 >> 16) & 0x3F);
      }
      SetSpriteAnimation(p, *mp);
      (p->s).work[2] = 0x50;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      UpdateSpriteAnimation(p);
      (p->s).d.y += 0x20;
      if ((p->s).d.y > 0x700) {
        (p->s).d.y = 0x700;
      }
      (p->s).coord.y += (p->s).d.y;
      (p->s).coord.x += (p->s).d.x;
      if ((p->s).work[2] == 0 || --(p->s).work[2] == 0) {
        SET_VFX_ROUTINE(p, ENTITY_DIE);
      }
      break;
  }
}

// --------------------------------------------

void FUN_080c2124(struct VFX* p);
void FUN_080c216c(struct Entity* p);
void FUN_080c21c0(struct VFX* p);
void FUN_080c2294(struct VFX58* p);
void FUN_080c2364(struct VFX* p);
void FUN_080c2390(struct VFX* p);
void FUN_080c248c(struct VFX* p);
void FUN_080c2500(struct VFX58* p);
void FUN_080c25f4(struct VFX58* p);

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
