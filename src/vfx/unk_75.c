#include "entity.h"
#include "global.h"
#include "vfx.h"
#include "vfx/unk_common.h"
#include "stagerun.h"

// Cattatank の残骸?

static void Ghost75_Init(struct Entity* p);
static void Ghost75_Update(struct Entity* p);
static void Ghost75_Die(struct Entity* p);

// clang-format off
const VFXRoutine gGhost75Routine = {
    [ENTITY_INIT] =      (void*)Ghost75_Init,
    [ENTITY_UPDATE] =    (void*)Ghost75_Update,
    [ENTITY_DIE] =       (void*)Ghost75_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* FUN_080c7518(Coords32* c, u8 n) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_075);
    p->work[0] = n, p->work[1] = 0;
    p->coord.x = c->x, p->coord.y = c->y;
  }
  return p;
}

struct Entity* FUN_080c7570(Coords32* c, u8 n, motion_t m, u32 val) {
  VFXUnkCommon* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_075);
    p->work[0] = n, p->work[1] = 1;
    p->coord.x = c->x, p->coord.y = c->y;
    p->m_74 = m;
    p->unk_78 = val;
  }
  return (void*)p;
}

// --------------------------------------------

static void Ghost75_Init(struct Entity* p) {
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
    p->work[2] = 96 + (RANDOM(RNG_0202f388) & 7);
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 2, p->mode[2] = 0, p->mode[3] = 0;
  }
  Ghost75_Update((void*)p);
}

static void nop_080c76fc(void* _ UNUSED);
void FUN_080c7700(struct VFX* p);
void FUN_080c77f0(struct VFX* p);

static void Ghost75_Update(struct Entity* p) {
  static const VFXFunc sUpdates[3] = {
      (void*)nop_080c76fc,
      (void*)FUN_080c7700,
      (void*)FUN_080c77f0,
  };
  (sUpdates[(p->mode)[1]])((void*)p);
}

static void Ghost75_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void nop_080c76fc(void* _ UNUSED) {}

void FUN_080c7700(struct VFX* p) {
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
      register s32 m5 asm("r5");
      {
        register u8 w0 asm("r1");
        register s32 m2 asm("r2");
        register struct Coord* cp asm("r0");
        w0 = (p->s).work[0];
        m5 = 0xD50E;
        cp = &c;
        asm volatile("add %0, %1, #0" : "=&l"(m2) : "l"(m5));
        ((void (*)(struct Coord*, s32, s32, s32))FUN_080c7570)(cp, w0, m2, r);
      }
      {
        register u8 w1 asm("r1");
        register s32 m3 asm("r2");
        register struct Coord* cp1 asm("r0");
        w1 = (p->s).work[0];
        m3 = 0xD50D;
        cp1 = &c;
        ((void (*)(struct Coord*, s32, s32, s32))FUN_080c7570)(cp1, w1, m3, r);
      }
      {
        register u8 w2 asm("r1");
        register s32 m6 asm("r2");
        register struct Coord* cp2 asm("r0");
        w2 = (p->s).work[0];
        cp2 = &c;
        asm volatile("add %0, %1, #0" : "=&l"(m6) : "l"(m5));
        ((void (*)(struct Coord*, s32, s32, s32))FUN_080c7570)(cp2, w2, m6, r);
      }
    }
    PlaySound(0x2A);
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    return;
  }

  switch ((p->s).mode[2]) {
    case 0:
      (p->s).work[2] = 0x1E;
      (p->s).d.y = -0x180;
      SetMotion(&p->s, MOTION(0xD5, 0x06));
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

void FUN_080c77f0(struct VFX* p) {
  register s32 md asm("r9");
  {
    s32 t = (p->s).work[2] - 1;
    (p->s).work[2] = t;
    if ((u8)t == 0) {
      goto die;
    }
  }
  {
    register u32 at asm("r1");
    at = (u16)FUN_080098a4((p->s).coord.x, (p->s).coord.y);
    if (at == 0) {
      goto normal;
    }
    {
      register s32 k asm("r0");
      k = 0x80 * 256;
      k &= at;
      if (k != 0) {
        goto normal;
      }
    }
    if ((p->s).d.y <= 0) {
      goto normal;
    }
  }
die : {
  register struct Camera* cam asm("r0");
  register struct Coord* cp asm("r4");
  cam = &gStageRun.vm.camera;
  asm("" : "+r"(cam));
  cp = &(p->s).coord;
  if (Camera_GetDistance(cam, cp) <= 0x80 * 64) {
    CreateSmoke(2, cp);
    PlaySound(0x2A);
  }
  SET_VFX_ROUTINE(p, ENTITY_DIE);
  return;
}
normal:
  md = (p->s).mode[2];
  switch (md) {
    case 0: {
      register const s32** tb asm("r4");
      register u16* mp asm("r8");
      register u32 mul asm("r6");
      register u32 add asm("r5");
      register u32 s1 asm("r4");
      register u32* rp2 asm("r3");
      register const s32* q asm("r2");
      tb = (const s32**)0x0836F920;
      asm("" : "+r"(tb));
      {
        register u16* mtmp asm("r1");
        register u32 i asm("r0");
        asm volatile("mov %0, #0x74\n\tadd %0, %0, %1" : "=&l"(mtmp) : "l"(p));
        mp = mtmp;
        i = (u16)*mtmp % 3;
        i <<= 16;
        i >>= 14;
        i += (u32)tb;
        {
          register const s32* qb asm("r0");
          register s32 off asm("r2");
          qb = *(const s32**)i;
          off = *(s32*)((u8*)p + 0x78);
          off <<= 3;
          q = (const s32*)(off + (u32)qb);
        }
      }
      {
        register u32 r0v asm("r0");
        register u32 r1v asm("r1");
        register u32* rp asm("r3");
        rp = &RNG_0202f388;
        asm("" : "+r"(rp));
        rp2 = rp;
        r0v = *rp;
        mul = 0x343FD;
        asm volatile("add %0, %1, #0" : "=&l"(r1v) : "l"(r0v));
        r1v *= mul;
        add = 0x269EC3;
        r1v += add;
        r1v <<= 1;
        asm("" : "+r"(r1v));
        s1 = r1v >> 1;
        *rp = s1;
        r1v >>= 0x11;
        r0v = 0x1F;
        r1v &= r0v;
        (p->s).d.y = q[1] + r1v;
      }
      {
        register u32 r1w asm("r1");
        register u32 r0w asm("r0");
        asm volatile("add %0, %1, #0" : "=&l"(r1w) : "l"(s1));
        r1w *= mul;
        r1w += add;
        r1w <<= 1;
        asm("" : "+r"(r1w));
        *rp2 = r1w >> 1;
        r1w >>= 0x11;
        r0w = 0x3F;
        r1w &= r0w;
        (p->s).d.x = q[0] - r1w;
      }
      ((void (*)(struct Entity*, u32))SetMotion)(&p->s, *mp);
      {
        register u8 fl asm("r1");
        register s32 f asm("r0");
        fl = (p->s).flags;
        f = 1;
        f |= fl;
        (p->s).flags = f;
      }
      {
        register s32 mv asm("r1");
        mv = md;
        (p->s).work[3] = mv;
      }
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      (p->s).work[3]++;
      (p->s).d.y += 0x10;
      if ((p->s).d.y > 0xE0 * 8) {
        (p->s).d.y = 0xE0 * 8;
      }
      (p->s).coord.y += (p->s).d.y;
      (p->s).coord.x += (p->s).d.x;
      UpdateEntityAnim(&p->s);
      break;
  }
}

// --------------------------------------------

const s32 s32_ARRAY_0836f8c0[24] = {
    0x00000120, -0x00000200, -0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, -0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, 0x00000120, -0x00000200, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, 0x00000120, -0x00000200, -0x000000B0, -0x00000160,
};

const s32* const PTR_ARRAY_0836f920[3] = {
    &s32_ARRAY_0836f8c0[0],
    &s32_ARRAY_0836f8c0[8],
    &s32_ARRAY_0836f8c0[16],
};
