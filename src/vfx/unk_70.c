#include "entity.h"
#include "global.h"
#include "physics.h"
#include "vfx.h"
#include "stagerun.h"

static void VFX70_Init(struct Entity* p);
static void VFX70_Update(struct Entity* p);
static void VFX70_Die(struct Entity* p);

// clang-format off
const VFXRoutine gGhost70Routine = {
    [ENTITY_INIT] =      (void*)VFX70_Init,
    [ENTITY_UPDATE] =    (void*)VFX70_Update,
    [ENTITY_DIE] =       (void*)VFX70_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct VFX* FUN_080c5628(u8 r0, u8 r1, s32 x, s32 y) {
  struct VFX* p = (struct VFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_070);
    (p->s).work[0] = r0, (p->s).work[1] = r1;
    (p->s).coord.x = x, (p->s).coord.y = y;
    (p->s).d.x = 0, (p->s).d.y = 0;
  }
  return p;
}

struct VFX* FUN_080c5684(u8 r0, u8 r1, s32 x, s32 y, s32 dx, s32 dy) {
  struct VFX* p = (struct VFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_070);
    (p->s).work[0] = r0, (p->s).work[1] = r1;
    (p->s).coord.x = x, (p->s).coord.y = y;
    (p->s).d.x = dx, (p->s).d.y = dy;
  }
  return p;
}

// --------------------------------------------

static void _VFX70_Init(struct Entity* p);

static void VFX70_Init(struct Entity* p) {
  // clang-format off
  static EntityFunc const sInitializers[] = {
      _VFX70_Init,
      _VFX70_Init,
      _VFX70_Init,
      _VFX70_Init,
      _VFX70_Init,
      _VFX70_Init,
  };
  // clang-format on
  (sInitializers[p->work[0]])(p);
}

static void FUN_080c5764(struct Entity* p);
void FUN_080c57a4(struct VFX* p);
void FUN_080c5860(struct VFX* p);
void FUN_080c598c(struct VFX* p);
void FUN_080c5b30(struct VFX* p);
void FUN_080c5c64(struct VFX* p);

static void VFX70_Update(struct Entity* p) {
  // clang-format off
  static const VFXFunc sUpdates[6] = {
    (void*)FUN_080c5764,
    (void*)FUN_080c57a4,
    (void*)FUN_080c5860,
    (void*)FUN_080c598c,
    (void*)FUN_080c5b30,
    (void*)FUN_080c5c64,
  }; // 0x0836f73c
  // clang-format on
  (sUpdates[p->work[0]])((void*)p);
}

static void _VFX70_Die(struct Entity* p);

static void VFX70_Die(struct Entity* p) {
  // clang-format off
  static const EntityFunc sDeinitializers[] = {
    _VFX70_Die,
    _VFX70_Die,
    _VFX70_Die,
    _VFX70_Die,
    _VFX70_Die,
    _VFX70_Die,
  };
  // clang-format on
  (sDeinitializers[p->work[0]])(p);
}

// --------------------------------------------

// 0x080c572c
static void _VFX70_Init(struct Entity* p) {
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  EnableSpriteAnimation_Normal(p);
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  VFX70_Update(p);
}

// 0x080c5764
static void FUN_080c5764(struct Entity* p) {
  SET_VFX_ROUTINE(p, ENTITY_DIE);
  VFX70_Die(p);
}

// 0x080c5784
static void _VFX70_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

void FUN_080c57a4(struct VFX* p) {
  struct Coord c;
  switch ((p->s).mode[1]) {
    case 0:
      if ((p->s).work[1] == 0) {
        SetMotion(&p->s, 0x10);
      } else {
        SetMotion(&p->s, (p->s).work[1] | 0xBA00);
      }
      (p->s).work[2] = 0;
      (p->s).mode[1]++;
      FALLTHROUGH;
    case 1: {
      s32 x;
      s32 y;
      s32 w;
      UpdateEntityAnim(&p->s);
      if ((p->s).d.y <= 0x6FF) {
        (p->s).d.y += 0x2A;
      }
      y = (p->s).coord.y + (p->s).d.y;
      (p->s).coord.y = y;
      x = (p->s).coord.x + (p->s).d.x;
      (p->s).coord.x = x;
      w = (p->s).work[2] + 1;
      (p->s).work[2] = w;
      if ((u8)w > 0x3C) {
        if (PushoutToUp1(x, y) != 0) {
          if ((p->s).work[1] != 0) {
            c.x = (p->s).coord.x;
            c.y = (p->s).coord.y;
            CreateSmoke(3, &c);
          }
          (p->s).flags &= ~DISPLAY;
          SET_VFX_ROUTINE(p, ENTITY_DIE);
        }
      }
      break;
    }
  }
}

void FUN_080c5860(struct VFX* p) {
  switch ((p->s).mode[1]) {
    case 0: {
      register s32 spd asm("r4");
      register const s16* tb asm("r6");
      register s32 ang asm("r5");
      InitScalerotMotion2(&p->s);
      SetMotion(&p->s, 6);
      spd = (p->s).d.x;
      (p->s).coord.y -= spd << 7;
      tb = gSineTable;
      ang = (p->s).work[1];
      asm("" : "+r"(ang));
      {
        register s32 sv asm("r0");
        sv = tb[(u8)(ang + 0x40)];
        sv = spd * sv;
        (p->s).unk_coord.x = sv / 6;
      }
      {
        register s32 v asm("r2");
        register s32 t asm("r0");
        register u32 rnd asm("r1");
        register u32 acc asm("r0");
        u32 rv;
        t = tb[(p->s).work[1]];
        asm volatile("add %0, %1, #0" : "=&l"(v) : "l"(t));
        v = spd * v;
        v >>= 7;
        rnd = RNG_0202f388;
        acc = 0x343FD;
        acc *= rnd;
        acc += 0x269EC3;
        rv = acc << 1;
        asm("" : "+r"(rv));
        RNG_0202f388 = rv >> 1;
        v += (rv << 5) >> 0x16;
        v += -0x1FF;
        (p->s).unk_coord.y = v;
      }
      if ((s8)ang < 0) {
        goto neg;
      }
      {
        register u8* a asm("r1");
        register s32 vv asm("r0");
        a = (u8*)p + 0x25;
        vv = 0x10;
        *a = vv;
        goto stored;
      }
    neg : {
      register u8* a2 asm("r1");
      register s32 vv2 asm("r0");
      a2 = (u8*)p + 0x25;
      vv2 = 0x20;
      *a2 = vv2;
    }
    stored:
      (p->s).work[2] = 0x2D;
      (p->s).mode[1]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 ux, uy, t;
      UpdateEntityAnim(&p->s);
      (p->s).coord.x += (p->s).unk_coord.x;
      (p->s).coord.y += (p->s).unk_coord.y;
      ux = (p->s).unk_coord.x;
      (p->s).unk_coord.x = ((ux << 3) - ux) >> 3;
      uy = (p->s).unk_coord.y;
      (p->s).unk_coord.y = ((uy << 3) - uy) >> 3;
      {
        register u32 w asm("r0");
        w = (p->s).work[2];
        if (w <= 0x1F) {
          register u16* h asm("r1");
          w <<= 3;
          h = (u16*)((u8*)p + 0x50);
          *h = w;
          w = (p->s).work[2] << 3;
          asm("" : "+r"(h));
          h++;
          asm("" : "+r"(h));
          *h = w;
        }
      }
      t = (p->s).work[2] - 1;
      (p->s).work[2] = t;
      if ((u8)t <= 0xE) {
        if ((t & 2) != 0) {
          (p->s).flags |= 1;
        } else {
          (p->s).flags &= 0xFE;
        }
      }
      if ((p->s).work[2] == 0) {
        SET_VFX_ROUTINE(p, ENTITY_DIE);
      }
      break;
    }
  }
}

INCASM("asm/vfx/unk_70_a.inc");

void FUN_080c5b30(struct VFX* p) {
  switch ((p->s).mode[1]) {
    case 0: {
      {
        u32 g0 = (u32)RANDOM(RNG_0202f388) % 5;
        SetMotion(&p->s, g0 | 0xB900);
      }
      *((u8*)p + 0x49) |= 0xC;
      {
        u32 xf = RANDOM(RNG_0202f388) & 1;
        s32 v;
        if (xf != 0) {
          register u8 lf asm("r1");
          register s32 vv asm("r0");
          lf = (p->s).flags;
          vv = 0x10;
          vv |= lf;
          v = vv;
        } else {
          register u8 lf2 asm("r1");
          register s32 vv2 asm("r0");
          lf2 = (p->s).flags;
          vv2 = 0xEF;
          vv2 &= lf2;
          v = vv2;
        }
        (p->s).flags = v;
        {
          register s32 x1 asm("r1");
          u8* a;
          u8 b;
          s32 msk;
          s32 sh;
          x1 = xf;
          asm("" : "+r"(x1));
          ((p->s).spr).xflip = x1;
          a = (u8*)p + 0x4a;
          sh = x1 << 4;
          b = *a;
          msk = -0x11;
          msk &= b;
          msk |= sh;
          *a = msk;
        }
      }
      {
        register struct Camera* cam asm("r3");
        register u32* rp asm("r6");
        register u32 A3 asm("r4");
        register u32 C3 asm("r2");
        register u32 seed2 asm("r5");
        u32 sd;
        register u32 r0v asm("r0");
        u32 r2v;
        s32 t;
        cam = &gStageRun.vm.camera;
        rp = &RNG_0202f388;
        sd = *rp;
        A3 = 0x343FD;
        asm("" : "+r"(A3));
        r0v = sd * A3;
        C3 = 0x269EC3;
        asm("" : "+r"(C3));
        r0v += C3;
        r0v <<= 1;
        seed2 = r0v >> 1;
        t = ((r0v >> 0x11) & 0xFF) << 8;
        t += -0x7800;
        (p->s).coord.x = cam->viewport.x + t;
        (p->s).coord.y = cam->viewport.y + 0x4FFF;
        r2v = seed2 * A3;
        r2v += C3;
        r2v <<= 1;
        *rp = r2v >> 1;
        *(s32*)((u8*)p + 0x60) = (((r2v >> 0x11) & 3) + 5) << 8;
      }
      (p->s).mode[1]++;
    }
      /* fallthrough */
    case 1:
      UpdateEntityAnim(&p->s);
      {
        s32 y = (p->s).coord.y - *(s32*)((u8*)p + 0x60);
        struct Camera* cam2;
        (p->s).coord.y = y;
        cam2 = &gStageRun.vm.camera;
        if (y < cam2->viewport.y + -0x6000) {
          SET_VFX_ROUTINE(p, ENTITY_DIE);
        }
      }
      break;
  }
}

void FUN_080c5c64(struct VFX* vfx) {
  s32 md = (vfx->s).mode[1];
  switch (md) {
    case 0:
      SetMotion(&vfx->s, (RANDOM(RNG_0202f388) & 3) | MOTION(0x51, 0x02));
      (vfx->s).renderPrio = 0x13;
      {
        s32 dx = (RANDOM(RNG_0202f388) % 0x1400) - 0xA00;
        (vfx->s).coord.x += dx;
      }
      (vfx->s).d.y = md;
      (vfx->s).work[2] = 0x50;
      (vfx->s).mode[1]++;
      // fallthrough
    case 1: {
      s32 t;
      s32 f;
      register s32 z asm("r2");
      s32 v = (vfx->s).d.y + 4;
      (vfx->s).d.y = v;
      (vfx->s).coord.y += v;
      t = (vfx->s).work[2] - 1;
      z = 0;
      (vfx->s).work[2] = t;
      asm volatile("" : "+r"(z));
      if ((u8)t <= 9) {
        if (t & 1) {
          register s32 fa asm("r0");
          register s32 c1 asm("r1");
          fa = (vfx->s).flags;
          c1 = DISPLAY;
          asm("" : "+r"(c1));
          fa |= c1;
          f = fa;
        } else {
          goto off;
        }
        goto store;
      }
      if ((u8)t <= 0x13) {
        if (t & 2) {
          register s32 fc asm("r0");
          register s32 c2 asm("r1");
          fc = (vfx->s).flags;
          c2 = DISPLAY;
          fc |= c2;
          f = fc;
        } else {
        off: {
            register u8 f1 asm("r1");
            register s32 fr asm("r0");
            f1 = (vfx->s).flags;
            fr = 0xFE;
            fr &= f1;
            f = fr;
          }
        }
      store:
        (vfx->s).flags = f;
      }
      UpdateEntityAnim(&vfx->s);
      if ((vfx->s).work[2] == 0) {
        register u8 f1 asm("r1");
        register s32 f2 asm("r0");
        f1 = (vfx->s).flags;
        f2 = 0xFE;
        f2 &= f1;
        {
          register s32 c2 asm("r1");
          c2 = 0xFD;
          f2 &= c2;
        }
        (vfx->s).flags = f2;
        SET_VFX_ROUTINE(vfx, ENTITY_DISAPPEAR);
      }
      break;
    }
  }
}
