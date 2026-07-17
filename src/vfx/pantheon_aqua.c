#include "global.h"
#include "story.h"
#include "vfx.h"

// パンテオンアクアの出すエフェクト(泡 や やられた時の破片)
typedef struct {
  ENTITY_HDR;     // 0x00
  ENTITY_SPRITE;  // 0x28
  motion_t m_74;  // 0x74
  u32 unk_78;     // 0x78
  u32 mag_7c;     // 0x7C
  u16 unk_80;     // 0x80
} PAquaVFX;       // 132 bytes
static_assert(sizeof(PAquaVFX) == sizeof(struct VFX));

static void Ghost32_Init(PAquaVFX* p);
static void Ghost32_Update(PAquaVFX* p);
static void Ghost32_Die(PAquaVFX* p);

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
  struct VFX* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_P_AQUA);
    (p->s).work[0] = n, (p->s).work[1] = 0;
    (p->s).coord.x = c->x, (p->s).coord.y = c->y;
  }
  return p;
}

struct Entity* FUN_080ba81c(Coords32* c, bool8 isRight, motion_t m, u32 val) {
  PAquaVFX* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_P_AQUA);
    p->work[0] = isRight, p->work[1] = 1;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->m_74 = m, p->unk_78 = val;
  }
  return (void*)p;
}

struct VFX* FUN_080ba888(Coords32* c, Coords32* d, u8 n) {
  struct VFX* p = AllocEntityLast(gVFXHeaderPtr);
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
  struct VFX* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_P_AQUA);
    (p->s).work[0] = n, (p->s).work[1] = 3;
    (p->s).coord.x = c->x, (p->s).coord.y = c->y;
  }
  return p;
}

struct Entity* FUN_080ba940(Coords32* c, u8 n, u8 r2) {
  PAquaVFX* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_P_AQUA);
    p->work[0] = n, p->work[1] = 4;
    p->unk_80 = r2;
    (p->coord).x = c->x, (p->coord).y = c->y;
  }
  return (void*)p;
}

struct VFX* FUN_080ba9a0(Coords32* c) {
  struct VFX* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_P_AQUA);
    (p->s).work[0] = 0, (p->s).work[1] = 5;
    (p->s).coord.x = c->x, (p->s).coord.y = c->y;
  }
  return p;
}

struct VFX* FUN_080ba9f4(Coords32* c, u8 n) {
  struct VFX* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_P_AQUA);
    (p->s).work[0] = n, (p->s).work[1] = 6;
    (p->s).coord.x = c->x, (p->s).coord.y = c->y;
  }
  return p;
}

struct VFX* FUN_080baa4c(Coords32* c, u8 n) {
  struct VFX* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_P_AQUA);
    (p->s).work[0] = n, (p->s).work[1] = 7;
    (p->s).coord.x = c->x, (p->s).coord.y = c->y;
  }
  return p;
}

// --------------------------------------------

static void FUN_080baad8(PAquaVFX* p);
static void FUN_080bab54(PAquaVFX* p);
static void FUN_080babac(PAquaVFX* p);
static void FUN_080bac14(PAquaVFX* p);
static void FUN_080bac5c(PAquaVFX* p);
static void FUN_080baca4(PAquaVFX* p);
static void FUN_080bacec(PAquaVFX* p);
static void FUN_080bad34(PAquaVFX* p);

static void Ghost32_Init(PAquaVFX* p) {
  // clang-format off
  static void (*const sInitializers[8])(PAquaVFX*) = {
      FUN_080baad8,
      FUN_080bab54,
      FUN_080babac,
      FUN_080bac14,
      FUN_080bac5c,
      FUN_080baca4,
      FUN_080bacec,
      FUN_080bad34,
  };
  // clang-format on
  p->work[2] = 0xFF;
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  (sInitializers[p->work[1]])(p);
  Ghost32_Update(p);
}

static void FUN_080baad8(PAquaVFX* p) {
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

static void FUN_080bab54(PAquaVFX* p) {
  EnableSpriteAnimation_Normal(p);
  (p->d).x = 0, (p->d).y = 0;
  p->work[2] = (RANDOM(RNG_0202f388) & 7) + 0x7F;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 1, p->mode[2] = 0, p->mode[3] = 0;
}

static void FUN_080babac(PAquaVFX* p) {
  EnableSpriteAnimation_Affine(p);
  p->mag_7c = 0x100;
  (p->spr).mag.x = 0x100;
  (p->spr).mag.y = p->mag_7c;
  p->angle = RANDOM(RNG_0202f388);
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 2, p->mode[2] = 0, p->mode[3] = 0;
}

static void FUN_080bac14(PAquaVFX* p) {
  EnableSpriteAnimation_Affine(p);
  p->mag_7c = 0x100;
  (p->spr).mag.x = 0x100;
  (p->spr).mag.y = p->mag_7c;
  p->angle = 0;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 3, p->mode[2] = 0, p->mode[3] = 0;
}

NON_MATCH static void FUN_080bac5c(PAquaVFX* p) {
#if MODERN
  EnableSpriteAnimation_Affine(p);
  p->mag_7c = 0x100;
  (p->spr).mag.x = 0x100;
  (p->spr).mag.y = p->mag_7c;
  p->angle = 0;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 4, p->mode[2] = 0, p->mode[3] = 0;  // なんかここのレジスタ割り当てが合わない, SET_VFX_ROUTINE が間違ってる...?
#else
  INCCODE("asm/wip/FUN_080bac5c.inc");
#endif
}

static void FUN_080baca4(PAquaVFX* p) {
  EnableSpriteAnimation_Affine(p);
  p->mag_7c = 0x100;
  (p->spr).mag.x = 0x100;
  (p->spr).mag.y = p->mag_7c;
  p->angle = 0;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 5, p->mode[2] = 0, p->mode[3] = 0;
}

static void FUN_080bacec(PAquaVFX* p) {
  EnableSpriteAnimation_Normal(p);
  p->mag_7c = 0x100;
  (p->spr).mag.x = 0x100;
  (p->spr).mag.y = p->mag_7c;
  p->angle = 0;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 6, p->mode[2] = 0, p->mode[3] = 0;
}

static void FUN_080bad34(PAquaVFX* p) {
  EnableSpriteAnimation_Normal(p);
  p->mag_7c = 0x100;
  (p->spr).mag.x = 0x100;
  (p->spr).mag.y = p->mag_7c;
  p->angle = 0;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 7, p->mode[2] = 0, p->mode[3] = 0;
}

void FUN_080bade8(PAquaVFX* p);
void FUN_080bb048(PAquaVFX* p);
void FUN_080bb17c(PAquaVFX* p);
void FUN_080bb2d8(PAquaVFX* p);
void FUN_080bb3d4(PAquaVFX* p);
void FUN_080bb5d4(PAquaVFX* p);
void FUN_080bb68c(PAquaVFX* p);
static void FUN_080bb7c4(PAquaVFX* p);

static void Ghost32_Update(PAquaVFX* p) {
  // clang-format off
  static void (*const sUpdates[8])(PAquaVFX*) = {
      FUN_080bade8,
      FUN_080bb048,
      FUN_080bb17c,
      FUN_080bb2d8,
      FUN_080bb3d4,
      FUN_080bb5d4,
      FUN_080bb68c,
      FUN_080bb7c4,
  }; // 0x0836ec44
  // clang-format on
  if (FLAG(gCurStory.s.gameflags, METTAUR_ENABLED)) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    Ghost32_Die(p);
    return;
  }
  (sUpdates[p->mode[1]])(p);
}

static void Ghost32_Die(PAquaVFX* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/vfx/pantheon_aqua.inc");

static void FUN_080bb7c4(PAquaVFX* p) {
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
