#include "global.h"
#include "story.h"
#include "vfx.h"

// パンテオンアクアの出すエフェクト(泡 や やられた時の破片)
struct PAquaVFX {
  struct Entity s;
  // props (16bytes, offset: 0x74..)
  motion_t m_74;
  u32 unk_78;
  u32 mag_7c;
  u16 unk_80;
};  // 132 bytes
static_assert(sizeof(struct PAquaVFX) == sizeof(struct VFX));

static void Ghost32_Init(struct VFX* p);
static void Ghost32_Update(struct Entity* p);
static void Ghost32_Die(struct Entity* p);

// clang-format off
const VFXRoutine gGhost32Routine = {
    [ENTITY_INIT] =      (void*)Ghost32_Init,
    [ENTITY_UPDATE] =    (void*)Ghost32_Update,
    [ENTITY_DIE] =       (void*)Ghost32_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct VFX* FUN_080ba7c8(Coords32* c, u8 n) {
  struct VFX* p = (struct VFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_P_AQUA);
    (p->s).work[0] = n, (p->s).work[1] = 0;
    (p->s).coord.x = c->x, (p->s).coord.y = c->y;
  }
  return p;
}

struct Entity* FUN_080ba81c(Coords32* c, bool8 isRight, motion_t m, u32 val) {
  struct PAquaVFX* p = (struct PAquaVFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_P_AQUA);
    (p->s).work[0] = isRight, (p->s).work[1] = 1;
    (p->s).coord.x = c->x, (p->s).coord.y = c->y;
    p->m_74 = m;
    p->unk_78 = val;
  }
  return (void*)p;
}

struct VFX* FUN_080ba888(Coords32* c, Coords32* d, u8 n) {
  struct VFX* p = (struct VFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_P_AQUA);
    (p->s).work[0] = n, (p->s).work[1] = 2;
    (p->s).coord.x = c->x, (p->s).coord.y = c->y;
    (p->s).d.x = d->x;
    (p->s).d.y = d->y;
  }
  return p;
}

struct VFX* FUN_080ba8e8(Coords32* c, u8 n) {
  struct VFX* p = (struct VFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_P_AQUA);
    (p->s).work[0] = n, (p->s).work[1] = 3;
    (p->s).coord.x = c->x, (p->s).coord.y = c->y;
  }
  return p;
}

struct Entity* FUN_080ba940(Coords32* c, u8 n, u8 r2) {
  struct PAquaVFX* p = (struct PAquaVFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_P_AQUA);
    (p->s).work[0] = n, (p->s).work[1] = 4;
    p->unk_80 = r2;
    (p->s).coord.x = c->x, (p->s).coord.y = c->y;
  }
  return (void*)p;
}

struct VFX* FUN_080ba9a0(Coords32* c) {
  struct VFX* p = (struct VFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_P_AQUA);
    (p->s).work[0] = 0, (p->s).work[1] = 5;
    (p->s).coord.x = c->x, (p->s).coord.y = c->y;
  }
  return p;
}

struct VFX* FUN_080ba9f4(Coords32* c, u8 n) {
  struct VFX* p = (struct VFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_P_AQUA);
    (p->s).work[0] = n, (p->s).work[1] = 6;
    (p->s).coord.x = c->x, (p->s).coord.y = c->y;
  }
  return p;
}

struct VFX* FUN_080baa4c(Coords32* c, u8 n) {
  struct VFX* p = (struct VFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_P_AQUA);
    (p->s).work[0] = n, (p->s).work[1] = 7;
    (p->s).coord.x = c->x, (p->s).coord.y = c->y;
  }
  return p;
}

// --------------------------------------------

static void FUN_080baad8(struct Entity* p);
static void FUN_080bab54(struct Entity* p);
static void FUN_080babac(struct PAquaVFX* p);
static void FUN_080bac14(struct PAquaVFX* p);
static void FUN_080bac5c(struct PAquaVFX* p);
static void FUN_080baca4(struct PAquaVFX* p);
static void FUN_080bacec(struct PAquaVFX* p);
static void FUN_080bad34(struct PAquaVFX* p);

static void Ghost32_Init(struct VFX* p) {
  // clang-format off
  static const VFXFunc sInitializers[8] = {
      (void*)FUN_080baad8,
      (void*)FUN_080bab54,
      (void*)FUN_080babac,
      (void*)FUN_080bac14,
      (void*)FUN_080bac5c,
      (void*)FUN_080baca4,
      (void*)FUN_080bacec,
      (void*)FUN_080bad34,
  };
  // clang-format on
  (p->s).work[2] = 0xFF;
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  (sInitializers[(p->s).work[1]])(p);
  Ghost32_Update((void*)p);
}

static void FUN_080baad8(struct Entity* p) {
  EnableSpriteAnimation_Normal(p);
  if (p->work[0] == 0) {
    SET_XFLIP(p, FALSE);
    (p->d).x = PIXEL(3) / 8;  // 右
  } else {
    SET_XFLIP(p, TRUE);
    (p->d).x = -PIXEL(3) / 8;  // 左
  }
  (p->d).y = 0;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 0, p->mode[2] = 0, p->mode[3] = 0;
}

static void FUN_080bab54(struct Entity* p) {
  EnableSpriteAnimation_Normal(p);
  (p->d).x = 0, (p->d).y = 0;
  p->work[2] = (RANDOM(RNG_0202f388) & 7) + 0x7F;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 1, p->mode[2] = 0, p->mode[3] = 0;
}

static void FUN_080babac(struct PAquaVFX* p) {
  EnableSpriteAnimation_Affine(p);
  p->mag_7c = 0x100;
  (p->s).spr.mag.x = 0x100;
  (p->s).spr.mag.y = p->mag_7c;
  (p->s).angle = RANDOM(RNG_0202f388);
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = 2, (p->s).mode[2] = 0, (p->s).mode[3] = 0;
}

static void FUN_080bac14(struct PAquaVFX* p) {
  EnableSpriteAnimation_Affine(p);
  p->mag_7c = 0x100;
  (p->s).spr.mag.x = 0x100;
  (p->s).spr.mag.y = p->mag_7c;
  (p->s).angle = 0;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = 3, (p->s).mode[2] = 0, (p->s).mode[3] = 0;
}

NON_MATCH static void FUN_080bac5c(struct PAquaVFX* p) {
#if MODERN
  EnableSpriteAnimation_Affine(p);
  p->mag_7c = 0x100;
  (p->s).spr.mag.x = 0x100;
  (p->s).spr.mag.y = p->mag_7c;
  (p->s).angle = 0;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = 4, (p->s).mode[2] = 0, (p->s).mode[3] = 0;  // なんかここのレジスタ割り当てが合わない, SET_VFX_ROUTINE が間違ってる...?
#else
  INCCODE("asm/wip/FUN_080bac5c.inc");
#endif
}

static void FUN_080baca4(struct PAquaVFX* p) {
  EnableSpriteAnimation_Affine(p);
  p->mag_7c = 0x100;
  (p->s).spr.mag.x = 0x100;
  (p->s).spr.mag.y = p->mag_7c;
  (p->s).angle = 0;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = 5, (p->s).mode[2] = 0, (p->s).mode[3] = 0;
}

static void FUN_080bacec(struct PAquaVFX* p) {
  EnableSpriteAnimation_Normal(p);
  p->mag_7c = 0x100;
  (p->s).spr.mag.x = 0x100;
  (p->s).spr.mag.y = p->mag_7c;
  (p->s).angle = 0;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = 6, (p->s).mode[2] = 0, (p->s).mode[3] = 0;
}

static void FUN_080bad34(struct PAquaVFX* p) {
  EnableSpriteAnimation_Normal(p);
  p->mag_7c = 0x100;
  (p->s).spr.mag.x = 0x100;
  (p->s).spr.mag.y = p->mag_7c;
  (p->s).angle = 0;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = 7, (p->s).mode[2] = 0, (p->s).mode[3] = 0;
}

void FUN_080bade8(struct VFX* p);
void FUN_080bb048(struct VFX* p);
void FUN_080bb17c(struct VFX* p);
void FUN_080bb2d8(struct VFX* p);
void FUN_080bb3d4(struct VFX* p);
void FUN_080bb5d4(struct VFX* p);
void FUN_080bb68c(struct VFX* p);
static void FUN_080bb7c4(struct Entity* p);

static void Ghost32_Update(struct Entity* p) {
  // clang-format off
  static const EntityFunc sUpdates[8] = {
      (void*)FUN_080bade8,
      (void*)FUN_080bb048,
      (void*)FUN_080bb17c,
      (void*)FUN_080bb2d8,
      (void*)FUN_080bb3d4,
      (void*)FUN_080bb5d4,
      (void*)FUN_080bb68c,
      (void*)FUN_080bb7c4,
  }; // 0x0836ec44
  // clang-format on
  if (FLAG(gCurStory.s.gameflags, METTAUR_ENABLED)) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    Ghost32_Die(p);
    return;
  }
  (sUpdates[p->mode[1]])(p);
}

static void Ghost32_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/vfx/pantheon_aqua.inc");

static void FUN_080bb7c4(struct Entity* p) {
  if (--p->work[2] == 0) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    return;
  }

  switch (p->mode[2]) {
    case 0: {
      SetSpriteAnimation(p, MOTION(SM039_PANTHEON_AQUA, 12));
      p->work[3] = 0;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      p->work[3]++;
      (p->coord).y += (p->d).y;
      (p->coord).x += (p->d).x;
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

// --------------------------------------------

const s32 s32_ARRAY_ARRAY_0836ec64[6][8] = {
    {0x00000120, -0x00000200, -0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120, -0x00000160}, {-0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, 0x00000120, -0x00000200}, {-0x000000B0, -0x00000200, 0x00000120, -0x00000160, 0x00000120, -0x00000200, -0x000000B0, -0x00000160}, {-0x00000060, -0x00000160, 0x00000060, -0x00000200, 0x000000A0, -0x00000160, -0x000000A0, -0x00000200}, {-0x000000A0, -0x00000160, 0x00000060, -0x00000200, -0x00000060, -0x00000160, 0x000000A0, -0x00000200}, {0x000000A0, -0x00000200, -0x000000A0, -0x00000160, 0x00000060, -0x00000200, -0x00000060, -0x00000160},
};

// 0x0836ed24
static const s32* const PTR_ARRAY_0836ed24[6] = {
    s32_ARRAY_ARRAY_0836ec64[0], s32_ARRAY_ARRAY_0836ec64[1], s32_ARRAY_ARRAY_0836ec64[2], s32_ARRAY_ARRAY_0836ec64[3], s32_ARRAY_ARRAY_0836ec64[4], s32_ARRAY_ARRAY_0836ec64[5],
};
