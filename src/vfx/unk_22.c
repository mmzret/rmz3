#include "entity.h"
#include "global.h"
#include "story.h"
#include "vfx.h"
#include "vfx/unk_common.h"

static const VFXFunc sUpdates[3];

static void VFX22_Init(struct Entity* p);
static void Ghost22_Update(struct Entity* p);
static void Ghost22_Die(struct Entity* p);

// clang-format off
const VFXRoutine gGhost22Routine = {
    [ENTITY_INIT] =      (void*)VFX22_Init,
    [ENTITY_UPDATE] =    (void*)Ghost22_Update,
    [ENTITY_DIE] =       (void*)Ghost22_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on


const s32* const PTR_ARRAY_0836ea50[3];
struct Entity* FUN_080b7b38(Coords32* c, u8 kind) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_022);
    p->work[0] = kind, p->work[1] = 0;
    p->coord.x = c->x, p->coord.y = c->y;
  }
  return p;
}

struct Entity* FUN_080b7b8c(Coords32* c, u8 kind, motion_t m, u32 val) {
  VFXUnkCommon* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_022);
    p->work[0] = kind, p->work[1] = 1;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->m_74 = m, p->unk_78 = val;
  }
  return (void*)p;
}

// --------------------------------------------

static void VFX22_Init(struct Entity* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  if (p->work[0] == 0) {
    SET_XFLIP(p, FALSE);
  } else {
    SET_XFLIP(p, TRUE);
  }
  if (p->work[0] == 0) {
    (p->d).x = -PIXEL(1) / 2;
  } else {
    (p->d).x = PIXEL(1) / 2;
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
  Ghost22_Update((void*)p);
}

static void nop_080b7d48(void* _ UNUSED);
void FUN_080b7d4c(struct VFX* p);
void FUN_080b7e3c(struct VFX* p);

static void Ghost22_Update(struct Entity* p) {
  static const VFXFunc sUpdates[3] = {
      (void*)nop_080b7d48,
      (void*)FUN_080b7d4c,
      (void*)FUN_080b7e3c,
  };

  if (IS_METTAUR) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    Ghost22_Die(p);
    return;
  }
  (sUpdates[(p->mode)[1]])((void*)p);
}

static void Ghost22_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void nop_080b7d48(void* _ UNUSED) {}

void FUN_080b7d4c(struct VFX* p) {
  s32 t = (p->s).work[2] - 1;
  (p->s).work[2] = t;
  t <<= 24;
  if (t == 0) {
    register s32 r asm("r4");
    struct Coord c;
    CreateSmoke(2, &(p->s).coord);
    {
      register u32 rv asm("r1");
      register u32 ka asm("r0");
      rv = RNG_0202f388;
      ka = 0x343FD;
      asm volatile("add %0, %1, #0" : "=&l"(r) : "l"(rv));
      r *= ka;
      ka = 0x269EC3;
      r += ka;
      r <<= 1;
      RNG_0202f388 = (u32)r >> 1;
      r = (u32)r >> 0x11;
      ka = 3;
      r &= ka;
    }
    c.x = (p->s).coord.x;
    c.y = (p->s).coord.y;
    {
      register u8 w0 asm("r1");
      register s32 m4 asm("r2");
      register struct Coord* cp asm("r0");
      w0 = (p->s).work[0];
      m4 = 0x1804;
      cp = &c;
      ((struct VFX* (*)(struct Coord*, s32, s32, s32))FUN_080b7b8c)(cp, w0, m4, r);
    }
    {
      register s32 m5 asm("r5");
      {
        register u8 w1 asm("r1");
        register s32 m2 asm("r2");
        register struct Coord* cp1 asm("r0");
        w1 = (p->s).work[0];
        m5 = 0x1805;
        cp1 = &c;
        asm volatile("add %0, %1, #0" : "=&l"(m2) : "l"(m5));
        ((struct VFX* (*)(struct Coord*, s32, s32, s32))FUN_080b7b8c)(cp1, w1, m2, r);
      }
      {
        register u8 w2 asm("r1");
        register s32 m3 asm("r2");
        register struct Coord* cp2 asm("r0");
        w2 = (p->s).work[0];
        cp2 = &c;
        asm volatile("add %0, %1, #0" : "=&l"(m3) : "l"(m5));
        ((struct VFX* (*)(struct Coord*, s32, s32, s32))FUN_080b7b8c)(cp2, w2, m3, r);
      }
    }
    PlaySound(0x31);
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    return;
  }
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).work[2] = 0x32;
      (p->s).d.y = -0x100;
      SetMotion(&p->s, MOTION(0x18, 0x02));
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      (p->s).d.y += 0x10;
      if ((p->s).d.y > 0x700) {
        (p->s).d.y = 0x700;
      }
      (p->s).coord.y += (p->s).d.y;
      (p->s).coord.x += (p->s).d.x;
      UpdateEntityAnim(&p->s);
      break;
  }
}

void FUN_080b7e3c(struct VFX* p) {
  {
    s32 t = (p->s).work[2] - 1;
    (p->s).work[2] = t;
    if ((t << 24) == 0) {
      goto smoke;
    }
  }
  {
    u16 a = FUN_080098a4((p->s).coord.x, (p->s).coord.y);
    if (a != 0) {
      if (!(a & 0x8000)) {
        if ((p->s).d.y > 0) {
        smoke:
          CreateSmoke(2, &(p->s).coord);
          SET_VFX_ROUTINE(p, ENTITY_DIE);
          return;
        }
      }
    }
  }
  {
    register u32 m9 asm("r9");
    m9 = (p->s).mode[2];
    switch (m9) {
      case 0: {
        const s32* const* t4 = PTR_ARRAY_0836ea50;
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
          register u32 three asm("r1");
          u32 md;
          three = 3;
          asm("" : "+r"(three));
          md = mv0 % three;
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
          (p->s).d.y = ent[1] + ((r0v >> 0x11) & 0x1F);
          r2v = seed2 * A3;
          r2v += C3;
          r2v <<= 1;
          *rp = r2v >> 1;
          (p->s).d.x = ent[0] - ((r2v >> 0x11) & 0x3F);
        }
        SetMotion(&p->s, *mo8);
        asm("" : "+r"(m9));
        {
          register s32 w1 asm("r1");
          w1 = m9;
          (p->s).work[3] = w1;
        }
        (p->s).mode[2]++;
      }
        /* fallthrough */
      case 1: {
        register u32 one asm("r1");
        s32 t3 = (p->s).work[3] + 1;
        u32 tf;
        s32 v2;
        (p->s).work[3] = t3;
        tf = t3 & 0xFF;
        one = 1;
        if (tf & one) {
          register s32 vf asm("r0");
          vf = (p->s).flags;
          vf |= one;
          v2 = vf;
        } else {
          register u8 lf3 asm("r1");
          register s32 vv3 asm("r0");
          lf3 = (p->s).flags;
          vv3 = 0xFE;
          vv3 &= lf3;
          v2 = vv3;
        }
        (p->s).flags = v2;
        (p->s).d.y += 0x10;
        if ((p->s).d.y > 0x700) {
          (p->s).d.y = 0x700;
        }
        (p->s).coord.y += (p->s).d.y;
        (p->s).coord.x += (p->s).d.x;
        UpdateEntityAnim(&p->s);
        break;
      }
    }
  }
}

const s32 s32_ARRAY_0836e9f0[24] = {
    0x00000120,  -0x00000200, -0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120,  -0x00000160,  // 0
    -0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120,  -0x00000160, 0x00000120,  -0x00000200,  // 1
    -0x000000B0, -0x00000200, 0x00000120,  -0x00000160, 0x00000120,  -0x00000200, -0x000000B0, -0x00000160,  // 2
};

// 0x0836EA50
const s32* const PTR_ARRAY_0836ea50[3] = {
    &s32_ARRAY_0836e9f0[0],
    &s32_ARRAY_0836e9f0[8],
    &s32_ARRAY_0836e9f0[16],
};
