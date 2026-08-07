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


static const s32* const PTR_ARRAY_0836ed24[6];
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
NON_MATCH static void FUN_080bac5c(PAquaVFX* p);
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

NON_MATCH void FUN_080bade8(PAquaVFX* p);
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

NON_MATCH void FUN_080bade8(PAquaVFX* p) {
#if MODERN
  struct Coord c;
  struct Coord c2;
  struct Coord c3;
  s32 t = p->work[2] - 1;
  p->work[2] = t;
  if ((t << 24) == 0) {
    u32 a, v, k;
    CreateSmoke(2, &p->coord);
    a = RNG_0202f388;
    v = (a * 0x343FD + 0x269EC3) << 1;
    RNG_0202f388 = v >> 1;
    k = (v >> 0x11) & 3;
    c.x = p->coord.x;
    c.y = p->coord.y;
    FUN_080ba81c(&c, p->work[0], 0x2710, k);
    FUN_080ba81c(&c, p->work[0], 0x2711, k);
    FUN_080ba81c(&c, p->work[0], 0x2712, k);
    FUN_080ba81c(&c, p->work[0], 0x2713, k);
    FUN_080ba81c(&c, p->work[0], 0x2714, k);
    FUN_080ba81c(&c, p->work[0], 0x2715, k);
    PlaySound(0x31);
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    return;
  }
  {
    u32 gr = FUN_080098a4(p->coord.x, p->coord.y);
    if (gr != 0 && !(gr & 0x8000)) {
      u32 a, v, k;
      CreateSmoke(2, &p->coord);
      PlaySound(0x31);
      a = RNG_0202f388;
      v = (a * 0x343FD + 0x269EC3) << 1;
      RNG_0202f388 = v >> 1;
      k = (v >> 0x11) & 3;
      c2.x = p->coord.x;
      c2.y = p->coord.y;
      FUN_080ba81c(&c2, p->work[0], 0x2710, k);
      FUN_080ba81c(&c2, p->work[0], 0x2711, k);
      FUN_080ba81c(&c2, p->work[0], 0x2712, k);
      FUN_080ba81c(&c2, p->work[0], 0x2713, k);
      FUN_080ba81c(&c2, p->work[0], 0x2714, k);
      FUN_080ba81c(&c2, p->work[0], 0x2715, k);
      SET_VFX_ROUTINE(p, ENTITY_DIE);
      return;
    }
  }
  switch (p->mode[2]) {
    case 0:
      p->work[2] = 0x3C;
      p->d.y = 0;
      p->work[3] = 0;
      SetMotion((struct Entity*)p, 0x270A);
      p->mode[2]++;
      FALLTHROUGH;
    case 1: {
      s32 g = p->d.y + 8;
      p->d.y = g;
      if (g > 0x700) {
        p->d.y = 0x700;
      }
      if ((p->work[2] % 0x14 << 24) == 0) {
        u32 a1, v1, s1, r1v, v2;
        struct Coord* p3;
        c3.x = p->coord.x;
        *(volatile s32*)&c3.y = p->coord.y;
        a1 = RNG_0202f388;
        v1 = (a1 * 0x343FD + 0x269EC3) << 1;
        s1 = v1 >> 1;
        r1v = (v1 >> 0x11) & 0x7FF;
        p3 = &c3;
        p3->y = *(volatile s32*)&p3->y - r1v;
        {
          s32 cx = *(volatile s32*)&c3.x + -0x400;
          v2 = (s1 * 0x343FD + 0x269EC3) << 1;
          RNG_0202f388 = v2 >> 1;
          c3.x = cx + ((v2 >> 0x11) & 0x7FF);
        }
        FUN_080ba9f4(p3, 0);
        FUN_080ba9f4(p3, 1);
      }
      p->coord.y += p->d.y;
      p->coord.x += p->d.x;
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
#else
  INCCODE("asm/vfx/unk_32_ade8.inc");
#endif
}

void FUN_080bb048(PAquaVFX* p) {
  {
    s32 t = p->work[2] - 1;
    p->work[2] = t;
    if ((t << 24) == 0) {
      goto smoke;
    }
  }
  {
    u16 a = FUN_080098a4(p->coord.x, p->coord.y);
    if (a != 0) {
      if (!(a & 0x8000)) {
        if (p->d.y > 0) {
        smoke:
          CreateSmoke(2, &p->coord);
          SET_VFX_ROUTINE(p, ENTITY_DIE);
          return;
        }
      }
    }
  }
  {
    register u32 m9 asm("r9");
    m9 = p->mode[2];
    switch (m9) {
      case 0: {
        const s32* const* t4 = PTR_ARRAY_0836ed24;
        register u16* mo8 asm("r8");
        register const s32* row asm("r0");
        register const s32* ent asm("r2");
        u32 mv0;
        {
          register u8* a1 asm("r1");
          u32 av = 0x74;
          asm("" : "+r"(av));
          av += (u32)p;
          a1 = (u8*)av;
          asm("" : "+r"(a1));
          mo8 = (u16*)a1;
          mv0 = *(u16*)a1;
        }
        {
          register u32 six asm("r1");
          u32 md;
          six = 6;
          asm("" : "+r"(six));
          md = mv0 % six;
          row = t4[(u16)md];
        }
        {
          register u32 offb asm("r2");
          offb = *(s32*)((u8*)p + 0x78) << 3;
          offb += (u32)row;
          ent = (const s32*)offb;
        }
        {
          register u32* rp asm("r3");
          register u32 A3 asm("r6");
          register u32 C3 asm("r5");
          register u32 seed2 asm("r4");
          u32 sd;
          u32 r0v;
          u32 r2v;
          rp = &RNG_0202f388;
          sd = *rp;
          asm("" : "+r"(sd));
          A3 = 0x343FD;
          asm("" : "+r"(A3));
          r0v = sd * A3;
          C3 = 0x269EC3;
          asm("" : "+r"(C3));
          r0v += C3;
          r0v <<= 1;
          seed2 = r0v >> 1;
          *rp = seed2;
          p->d.y = ent[1] + ((r0v >> 0x11) & 0x1F);
          r2v = seed2 * A3;
          r2v += C3;
          r2v <<= 1;
          *rp = r2v >> 1;
          p->d.x = ent[0] - ((r2v >> 0x11) & 0x3F);
        }
        SetMotion((struct Entity*)p, *mo8);
        asm("" : "+r"(m9));
        {
          register s32 w1 asm("r1");
          w1 = m9;
          p->work[3] = w1;
        }
        p->mode[2]++;
      }
        /* fallthrough */
      case 1: {
        register u32 one asm("r1");
        s32 t3 = p->work[3] + 1;
        u32 tf;
        s32 v2;
        p->work[3] = t3;
        tf = t3 & 0xFF;
        one = 1;
        if (tf & one) {
          register s32 vf asm("r0");
          vf = p->flags;
          vf |= one;
          v2 = vf;
        } else {
          register u8 lf3 asm("r1");
          register s32 vv3 asm("r0");
          lf3 = p->flags;
          vv3 = 0xFE;
          vv3 &= lf3;
          v2 = vv3;
        }
        p->flags = v2;
        p->d.y += 0x10;
        if (p->d.y > 0x700) {
          p->d.y = 0x700;
        }
        p->coord.y += p->d.y;
        p->coord.x += p->d.x;
        UpdateEntityAnim((struct Entity*)p);
        break;
      }
    }
  }
}

void FUN_080bb17c(PAquaVFX* p) {
  if ((u8)--p->work[2] == 0) {
    SET_VFX_ROUTINE(p, 2);
    return;
  }
  switch (p->mode[2]) {
    case 0:
      if (p->work[0] == 0) {
        p->work[2] = RANDOM(RNG_0202f388) % 10 + 0x1a;
        SetMotion((struct Entity*)p, 0x270C);
      } else {
        p->work[2] = (RANDOM(RNG_0202f388) & 7) + 0x14;
        SetMotion((struct Entity*)p, 0x270D);
        p->renderPrio = 0x19;
      }
      p->work[3] = 0;
      p->mode[2]++;
      FALLTHROUGH;
    case 1: {
      s32 sc, dx, dy;
      if ((++p->work[3] & 0xff) & 1) {
        p->flags |= 1;
      } else {
        p->flags &= ~1;
      }
      sc = *(s32*)((u8*)p + 0x7c);
      sc += ((0x180 - sc) * 40) >> 8;
      *(s32*)((u8*)p + 0x7c) = sc;
      *(u16*)((u8*)p + 0x50) = sc;
      asm("" ::: "memory");
      {
        s32 t = *(s32*)((u8*)p + 0x7c);
        u16* h = (u16*)((u8*)p + 0x52);
        *h = t;
      }
      {
        register u32 rv asm("r0");
        register u8* q asm("r1");
        rv = RANDOM(RNG_0202f388);
        asm("" : "+r"(rv));
        q = (u8*)p + 0x24;
        *q = rv;
      }
      dx = p->d.x;
      dx += ((-dx) * 18) >> 8;
      p->d.x = dx;
      dy = p->d.y;
      dy += ((-dy) * 18) >> 8;
      p->d.y = dy;
      p->coord.y += dy;
      p->coord.x += dx;
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

void FUN_080bb2d8(PAquaVFX* p) {
  if ((u8)--p->work[2] == 0) {
    SET_VFX_ROUTINE(p, 2);
    return;
  }
  switch (p->mode[2]) {
    case 0:
      p->work[2] = (RANDOM(RNG_0202f388) & 7) + 0xa;
      if (p->work[0] == 0) {
        SetMotion((struct Entity*)p, 0x270C);
      } else {
        SetMotion((struct Entity*)p, 0x270D);
        p->renderPrio = 0x19;
      }
      p->d.y = 0;
      p->d.x = 0;
      p->work[3] = 0;
      p->mode[2]++;
      FALLTHROUGH;
    case 1: {
      s32 sc, dy;
      if ((++p->work[3] & 0xff) & 1) {
        p->flags |= 1;
      } else {
        p->flags &= ~1;
      }
      sc = *(s32*)((u8*)p + 0x7c);
      sc += ((0x180 - sc) * 40) >> 8;
      *(s32*)((u8*)p + 0x7c) = sc;
      *(u16*)((u8*)p + 0x50) = sc;
      asm("" ::: "memory");
      {
        s32 t = *(s32*)((u8*)p + 0x7c);
        u16* h = (u16*)((u8*)p + 0x52);
        *h = t;
      }
      dy = p->d.y;
      dy += ((-0x100 - dy) * 16) >> 8;
      p->d.y = dy;
      p->coord.y += dy;
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

INCASM("asm/vfx/pantheon_aqua_a.inc");

void FUN_080bb5d4(PAquaVFX* p) {
  if ((u8)--p->work[2] == 0) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    return;
  }
  switch (p->mode[2]) {
    case 0: {
      p->work[2] = RANDOM(RNG_0202f388) % 6 + 0x12;
      SetMotion((struct Entity*)p, MOTION(0x27, 0x0C));
      p->work[3] = 0;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 dy;
      s32 w3 = p->work[3] + 1;
      p->work[3] = w3;
      {
        u32 kf;
        u32 one;
        kf = 0xFF;
        w3 &= kf;
        one = 1;
        w3 &= one;
        if (w3 != 0) {
          p->flags |= one;
        } else {
          u8 t = p->flags;
          u8 fv = 0xFE;
          fv &= t;
          asm volatile("" ::"r"(t));
          p->flags = fv;
        }
      }
      dy = p->d.y;
      dy += ((-0x100 - dy) << 4) >> 8;
      p->d.y = dy;
      p->coord.y += dy;
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

void FUN_080bb68c(PAquaVFX* p) {
  if ((u8)--p->work[2] == 0) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    return;
  }
  switch (p->mode[2]) {
    case 0: {
      u32 z;
      p->work[2] = RANDOM(RNG_0202f388) % 6 + 0x1E;
      if (p->work[0] == 0) {
        SetMotion((struct Entity*)p, MOTION(0x27, 0x0E));
      } else {
        SetMotion((struct Entity*)p, MOTION(0x27, 0x0F));
      }
      {
        u32 t = RNG_0202f388 * 0x343FD + 0x269EC3;
        t <<= 1;
        RNG_0202f388 = t >> 1;
        p->unk_coord.x = (s32)((t << 6) >> 23) - 0x100;
      }
      z = 0;
      p->d.y = z;
      p->d.x = z;
      p->work[3] = z;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 dy;
      s32 dx;
      s32 w3 = p->work[3] + 1;
      p->work[3] = w3;
      {
        u32 kf;
        u32 one;
        kf = 0xFF;
        w3 &= kf;
        one = 1;
        w3 &= one;
        if (w3 != 0) {
          p->flags |= one;
        } else {
          u8 t = p->flags;
          u8 fv = 0xFE;
          fv &= t;
          asm volatile("" ::"r"(t));
          p->flags = fv;
        }
      }
      {
        s32 g = p->mag_7c;
        s32 d = 0x180 - g;
        g += (d * 5 << 3) >> 8;
        p->mag_7c = g;
        (p->spr).mag.x = g;
        (p->spr).mag.y = p->mag_7c;
      }
      dy = p->d.y;
      dy += ((-0x100 - dy) << 4) >> 8;
      p->d.y = dy;
      {
        s32 ux = p->unk_coord.x;
        dx = p->d.x;
        dx += ((ux - dx) << 4) >> 8;
      }
      p->d.x = dx;
      p->coord.y += dy;
      p->coord.x += dx;
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

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
