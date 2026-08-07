#include "collision.h"
#include "global.h"
#include "physics.h"
#include "vfx.h"
#include "solid.h"
#include "overworld.h"
#include "stagerun.h"
#include "zero.h"

s32 PushoutToUp1(s32 x, s32 y);

static void Solid47_Init(struct Solid* p);
static void Solid47_Update(struct Solid* p);
static void Solid47_Die(struct Solid* p);

// clang-format off
const SolidRoutine gAnatreCubeRoutine = {
    [ENTITY_INIT] =      Solid47_Init,
    [ENTITY_UPDATE] =    Solid47_Update,
    [ENTITY_DIE] =       Solid47_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on


static const struct Collision sCollisions[2];
static const struct Rect sSize;
struct Solid* FUN_080deb10(Coords32* c) {
  struct Solid* p = (struct Solid*)AllocEntityLast(gSolidHeaderPtr);
  if (p != NULL) {
    INIT_SOLID_ROUTINE(p, SOLID_ANATRE_CUBE);
    (p->s).work[0] = 0;
    (p->s).unk_coord.y = (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
  }
  return p;
}

struct Solid* FUN_080deb6c(u8 r0, Coords32* c) {
  struct Solid* p = (struct Solid*)AllocEntityLast(gSolidHeaderPtr);
  if (p != NULL) {
    INIT_SOLID_ROUTINE(p, SOLID_ANATRE_CUBE);
    (p->s).work[0] = 1;
    (p->s).work[1] = r0;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
  }
  return p;
}

// --------------------------------------------

static void FUN_080dec04(struct Solid* p);
void FUN_080def4c(struct Solid* p);

static void Solid47_Init(struct Solid* p) {
  static const SolidFunc sInitializers[2] = {
      FUN_080dec04,
      FUN_080def4c,
  };
  (sInitializers[(p->s).work[0]])(p);
}

// --------------------------------------------

void FUN_080dec48(struct Solid* p);
void FUN_080defa8(struct Solid* p);

static void Solid47_Update(struct Solid* p) {
  static const SolidFunc sUpdates[2] = {
      FUN_080dec48,
      FUN_080defa8,
  };
  (sUpdates[(p->s).work[0]])(p);
}

// --------------------------------------------

static void Solid47_Die(struct Solid* p) {
  // nop
  return;
}

// --------------------------------------------

static void FUN_080dec04(struct Solid* p) {
  (p->s).flags |= FLIPABLE;
  (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y) - (PIXEL(32) - 1);
  (&(p->s).d)->x = (&(p->s).d)->y = 0;
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
}

void FUN_080dec48(struct Solid* p) {
  struct Coord c;
  register s32 nm asm("r0");
  register s32 z6 asm("r6");
  z6 = (p->s).mode[1];
  switch (z6) {
    case 0: {
      struct Coord* pc;
      register struct Body* b asm("r4");
      {
        register struct Camera* cam asm("r0");
        cam = &gStageRun.vm.camera;
        pc = &(p->s).coord;
        if (Camera_GetDistance(cam, pc) > (0xb0 << 6)) {
          break;
        }
      }
      {
        u8 fl = (p->s).flags;
        u32 f = 1;
        f |= fl;
        (p->s).flags = f;
      }
      InitNonAffineMotion(&p->s);
      SetMotion(&p->s, 0xe0 << 7);
      (p->s).renderPrio = 0x1d;
      {
        register u32 f asm("r0");
        register u32 m asm("r1");
        f = (p->s).flags;
        m = 4;
        f |= m;
        (p->s).flags = f;
      }
      b = &p->body;
      InitBody(b, &sCollisions[0], pc, 0);
      b->parent = (struct Entity*)p;
      b->fn = (BodyFunc)z6;
      {
        register u32 f2 asm("r0");
        register u32 m asm("r1");
        m = (p->s).flags2;
        f2 = 0xEF;
        f2 &= m;
        (p->s).invincibleID = (p->s).uniqueID;
        m = 8;
        f2 |= m;
        (p->s).flags2 = f2;
      }
      (p->s).size = &sSize;
      (p->s).physicsAttr = 0x2001;
      (p->s).mode[1]++;
      FALLTHROUGH;
    }
    case 1: {
      register u32* st asm("r4");
      UpdateEntityAnim(&p->s);
      {
        register u32* q asm("r0");
        register u32 v asm("r1");
        register u32 m asm("r2");
        q = (u32*)((u8*)p + 0x8c);
        v = *q;
        m = 0x80 << 10;
        v &= m;
        st = q;
        if (v == 0) {
          goto offscreen;
        }
      }
      {
        register s32 zx asm("r1");
        register s32 cx asm("r2");
        register s32 t asm("r0");
        register s32 k asm("r3");
        zx = (s32)pZero2;
        cx = (p->s).coord.x;
        k = 0x80 << 5;
        t = cx + k;
        zx = ((struct Zero*)zx)->s.coord.x;
        if (zx > t) {
          k = -0x2000;
          t = cx + k;
          (p->s).d.x = t;
          *(s32*)((u8*)p + 0x64) = 0xFFFFF001;
          (p->s).work[2] = 0;
          nm = 2;
          asm volatile("");
          goto setmode;
        }
        k = -0x1000;
        t = cx + k;
        if (zx >= t) {
          goto offscreen;
        }
        {
          register s32 k2 asm("r1");
          k2 = 0x80 << 6;
          t = cx + k2;
          (p->s).d.x = t;
        }
        *(s32*)((u8*)p + 0x64) = 0xFFF;
        (p->s).work[2] = 0;
        nm = 2;
        goto setmode;
      }
    offscreen:
      asm volatile("");
      if (Camera_GetDistance(&gStageRun.vm.camera, &(p->s).coord) <= (0xb0 << 6)) {
        break;
      }
      {
        register u32 f asm("r0");
        register u32 z asm("r2");
        {
          register u32 fl asm("r1");
          fl = (p->s).flags;
          f = 0xFE;
          f &= fl;
          z = 0;
          (p->s).flags = f;
        }
        *st = z;
        {
          register u8* a asm("r0");
          a = (u8*)p + 0x90;
          asm volatile("str %0, [%1]" ::"l"(z), "l"(a) : "memory");
          a += 4;
          asm("" : "+r"(a));
          asm volatile("strb %0, [%1]" ::"l"(z), "l"(a) : "memory");
        }
        {
          register u32 fl asm("r1");
          fl = (p->s).flags;
          f = 0xFB;
          f &= fl;
          (p->s).flags = f;
        }
        {
          register u32 fl asm("r1");
          fl = (p->s).flags2;
          f = 0xF7;
          f &= fl;
          (p->s).flags2 = f;
        }
        (p->s).mode[1] = z;
      }
      break;
    }
    case 2: {
      register u32* rng asm("r6");
      register u32 K asm("r7");
      register u32 h asm("r4");
      UpdateEntityAnim(&p->s);
      {
        register s32 t asm("r0");
        register s32 v asm("r1");
        if (*(s32*)((u8*)p + 0x64) < 0) {
          t = (p->s).coord.x;
          v = (t << 3) - t;
          t = (p->s).d.x;
          t = v + t;
        } else {
          t = (p->s).coord.x;
          v = (t << 3) - t;
          t = (p->s).d.x;
          v = v + t;
          t = v + 7;
        }
        if (t < 0) {
          t += 7;
        }
        t >>= 3;
        (p->s).coord.x = t;
      }
      {
        register s32 x asm("r0");
        register s32 y asm("r1");
        register s32 k asm("r2");
        {
          register s32 o asm("r1");
          x = *(volatile s32*)&(p->s).coord.x;
          o = *(s32*)((u8*)p + 0x64);
          x += o;
        }
        y = (p->s).coord.y;
        k = 0xf8 << 5;
        y += k;
        if (PushoutToUp1(x, y) != 0) {
          register s32 v asm("r0");
          if (*(s32*)((u8*)p + 0x64) < 0) {
            register s32 k3 asm("r3");
            v = (p->s).coord.x;
            k3 = 0x80 << 4;
            v += k3;
            asm volatile("");
          } else {
            v = (p->s).coord.x;
          }
          {
            register s32 m asm("r1");
            m = 0x7FFFF000;
            v &= m;
            (p->s).d.x = v;
            (p->s).coord.x = v;
          }
        }
      }
      {
        register u32 w asm("r1");
        register u32 t asm("r0");
        w = (p->s).work[2] + 1;
        (p->s).work[2] = w;
        rng = &RNG_0202f388;
        t = *rng;
        K = 0x343FD;
        t = K * t;
        {
          register u32 C asm("r2");
          C = 0x269EC3;
          t += C;
        }
        t <<= 1;
        h = t >> 1;
        *rng = h;
        t >>= 0x11;
        w <<= 24;
        w >>= 27;
        w += 1;
        if (t % w == 0) {
          register u32 v asm("r1");
          v = h;
          v = K * v;
          {
            register u32 C asm("r3");
            C = 0x269EC3;
            v += C;
          }
          v <<= 1;
          {
            register u32 hh asm("r0");
            hh = v >> 1;
            *rng = hh;
          }
          v >>= 0x11;
          {
            register u32 m asm("r0");
            m = 0x1f;
            v &= m;
          }
          v -= 0x10;
          v <<= 8;
          c.x = (p->s).coord.x + v;
          {
            register s32 y asm("r1");
            register s32 k asm("r2");
            y = (p->s).coord.y;
            k = 0x90 << 6;
            y += k;
            c.y = y;
          }
          if (PushoutToUp1(c.x, c.y) != 0) {
            CreateSmoke(3, &c);
          }
        }
      }
      if ((p->s).d.x != (p->s).coord.x) {
        break;
      }
      {
        register s32 x asm("r0");
        register s32 y asm("r1");
        register s32 k asm("r2");
        x = (p->s).d.x + 0xFFF;
        y = (p->s).coord.y;
        k = 0x84 << 6;
        y += k;
        if (PushoutToUp1(x, y) != 0) {
          goto zeroreset;
        }
      }
      {
        register s32 x asm("r0");
        register s32 y asm("r1");
        register s32 k asm("r2");
        x = (p->s).coord.x + -0xFFF;
        y = (p->s).coord.y;
        k = 0x84 << 6;
        y += k;
        nm = PushoutToUp1(x, y);
        if (nm != 0) {
          goto zeroreset;
        }
      }
      (p->s).d.y = nm;
      nm = 3;
      asm volatile("");
      goto setmode;
    zeroreset:
      nm = 0;
      goto reset;
    }
    case 3: {
      register s32 hit asm("r4");
      register s32 k asm("r6");
      UpdateEntityAnim(&p->s);
      {
        register s32 v asm("r1");
        v = (p->s).d.y;
        if (v <= 0x6FF) {
          register s32 t asm("r0");
          t = v;
          t += 0x40;
          (p->s).d.y = t;
        }
      }
      {
        register s32 y asm("r1");
        register s32 x asm("r0");
        {
          register s32 dv asm("r0");
          y = (p->s).coord.y;
          dv = (p->s).d.y;
          y += dv;
          (p->s).coord.y = y;
        }
        hit = 0;
        x = (p->s).coord.x + 0xFFF;
        k = 0x84 << 6;
        y += k;
        if (PushoutToUp1(x, y) != 0) {
          hit = FUN_08009f6c((p->s).coord.x + 0xFFF, (p->s).coord.y);
        }
      }
      {
        register s32 x asm("r0");
        register s32 y asm("r1");
        register s32 kk asm("r2");
        x = (p->s).coord.x;
        kk = -0xFFF;
        x += kk;
        y = (p->s).coord.y;
        y += k;
        if (PushoutToUp1(x, y) != 0) {
          hit = FUN_08009f6c((p->s).coord.x + -0xFFF, (p->s).coord.y);
        }
      }
      if (hit == 0) {
        break;
      }
      PlaySound(0x41);
      AppendQuake(2, &(p->s).coord);
      {
        register s32 kk asm("r1");
        register s32 v asm("r0");
        kk = -0x1FFF;
        v = hit + kk;
        (p->s).coord.y = v;
      }
      nm = 0;
      (p->s).d.y = nm;
    reset:
      (p->s).d.x = nm;
      nm = 1;
    setmode:
      (p->s).mode[1] = nm;
      break;
    }
  }
}

void FUN_080def4c(struct Solid* p) {
  {
    register u8 fv asm("r1");
    u8 t = (p->s).flags;
    fv = FLIPABLE;
    fv |= t;
    (p->s).flags = fv;
  }
  if ((p->s).work[1] != 4) {
    (p->s).unk_coord.x = 0x7002;
    (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y);
  } else {
    (p->s).unk_coord.x = 0x7006;
    (p->s).coord.x = FUN_0800a22c((p->s).coord.x, (p->s).coord.y);
  }
  (p->s).d.y = 0;
  (p->s).d.x = 0;
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
}

void FUN_080defa8(struct Solid* p) {
  register s32 z asm("r6");
  struct Coord* cp;
  register s32* st asm("r4");
  z = (p->s).mode[1];
  switch (z) {
    case 0: {
      register struct Body* b asm("r4");
      {
        register struct Camera* cam asm("r0");
        cam = &gStageRun.vm.camera;
        asm("" : "+r"(cam));
        cp = &(p->s).coord;
        if (Camera_GetDistance(cam, cp) > (u32)(0x80 << 5)) {
          break;
        }
      }
      {
        register s32 g asm("r1");
        register s32 k asm("r0");
        g = (p->s).flags;
        asm("" : "+r"(g));
        k = 1;
        k |= g;
        (p->s).flags = k;
      }
      InitNonAffineMotion(&p->s);
      {
        register s32 mv asm("r1");
        register u8* gw asm("r3");
        register s32 i asm("r2");
        mv = (p->s).unk_coord.x;
        gw = (u8*)&gOverworld;
        {
          register s32 w1 asm("r0");
          w1 = (p->s).work[1];
          i = 3;
          i &= w1;
          w1 = ((u32)w1) >> 2;
          w1 += 4;
          w1 <<= 2;
          asm volatile("add %0, %0, %1" : "+l"(i) : "l"(w1));
          w1 = 0x0002D028;
          gw += w1;
          i += (s32)gw;
          w1 = *(u8*)i;
          w1 <<= 1;
          mv += w1;
        }
        SetMotion(&p->s, mv);
      }
      {
        register s32 g2 asm("r1");
        register s32 k2 asm("r0");
        g2 = (p->s).flags;
        asm("" : "+r"(g2));
        k2 = 4;
        k2 |= g2;
        (p->s).flags = k2;
      }
      b = &p->body;
      ((void (*)(struct Body*, const struct Collision*, struct Coord*, s32))InitBody)(b, (const struct Collision*)0x08371804, cp, 0);
      b->parent = (struct Entity*)p;
      b->fn = (BodyFunc)z;
      {
        register u8 h asm("r1");
        register u8 g3 asm("r0");
        h = (p->s).flags2;
        asm("" : "+r"(h));
        g3 = 0xEF;
        g3 &= h;
        (p->s).flags2 = g3;
      }
      *((u8*)p + 0x1d) = *((u8*)p + 0x1c);
      (p->s).mode[1]++;
      FALLTHROUGH;
    }
    case 1: {
      register u8* gwp asm("r2");
      register u8* fp asm("r1");
      register s32 v asm("r0");
      UpdateEntityAnim(&p->s);
      {
        register s32* a0 asm("r0");
        register s32 v0 asm("r1");
        register s32 k0 asm("r2");
        a0 = (s32*)((u8*)p + 0x8c);
        v0 = *a0;
        k0 = 4;
        v0 &= k0;
        st = a0;
        if (v0 != 0) {
          goto on;
        }
      }
      if (PushoutToUp1((p->s).coord.x + -0x400, (p->s).coord.y) != 0) {
        goto on;
      }
      if ((p->s).work[1] == 4) {
        goto off;
      }
      if (PushoutToUp1((p->s).coord.x + (0x80 << 3), (p->s).coord.y) == 0) {
        goto off;
      }
    on:
      gwp = (u8*)&gOverworld;
      {
        register s32 i asm("r1");
        register s32 w1 asm("r0");
        w1 = (p->s).work[1];
        i = 3;
        i &= w1;
        w1 = ((u32)w1) >> 2;
        w1 += 4;
        w1 <<= 2;
        asm volatile("add %0, %0, %1" : "+l"(i) : "l"(w1));
        w1 = 0x0002D028;
        w1 += (s32)gwp;
        asm volatile("add %0, %0, %1" : "+l"(i) : "l"(w1));
        fp = (u8*)i;
      }
      v = 1;
      goto setflag;
    off:
      gwp = (u8*)&gOverworld;
      {
        register s32 i2 asm("r1");
        register s32 w2 asm("r0");
        w2 = (p->s).work[1];
        i2 = 3;
        i2 &= w2;
        w2 = ((u32)w2) >> 2;
        w2 += 4;
        w2 <<= 2;
        asm volatile("add %0, %0, %1" : "+l"(i2) : "l"(w2));
        w2 = 0x0002D028;
        w2 += (s32)gwp;
        asm volatile("add %0, %0, %1" : "+l"(i2) : "l"(w2));
        fp = (u8*)i2;
      }
      v = 0;
    setflag:
      *fp = v;
      {
        register s32 i3 asm("r1");
        register s32 w3 asm("r0");
        w3 = (p->s).work[1];
        i3 = 3;
        i3 &= w3;
        w3 = ((u32)w3) >> 2;
        w3 += 4;
        w3 <<= 2;
        asm volatile("add %0, %0, %1" : "+l"(i3) : "l"(w3));
        w3 = 0x0002D028;
        w3 += (s32)gwp;
        asm volatile("add %0, %0, %1" : "+l"(i3) : "l"(w3));
        if (*(u8*)i3 != 0) {
          register s32 mo asm("r2");
          register s32 base asm("r0");
          register s32 t asm("r1");
          {
            register s32 t8 asm("r0");
            t8 = *((u8*)p + 0x1e);
            mo = t8 << 8;
          }
          {
            register u8* mp asm("r0");
            mp = (u8*)p + 0x70;
            mo |= *mp;
          }
          base = (p->s).unk_coord.x;
          t = base + 1;
          if (mo == t) {
            goto done;
          }
          base += 2;
          if (mo == base) {
            goto done;
          }
          SetMotion(&p->s, t);
        } else {
          register s32 mo2 asm("r2");
          register s32 t2 asm("r1");
          {
            register s32 t8 asm("r0");
            t8 = *((u8*)p + 0x1e);
            mo2 = t8 << 8;
          }
          {
            register u8* mp2 asm("r0");
            mp2 = (u8*)p + 0x70;
            mo2 |= *mp2;
          }
          t2 = (p->s).unk_coord.x;
          if (mo2 == t2) {
            goto done;
          }
          t2 += 3;
          if (mo2 == t2) {
            goto done;
          }
          SetMotion(&p->s, t2);
        }
      }
    done:
      if (Camera_GetDistance(&gStageRun.vm.camera, &(p->s).coord) > (u32)(0x80 << 5)) {
        register s32 zz asm("r2");
        {
          register u8 h2 asm("r1");
          register u8 g4 asm("r0");
          h2 = (p->s).flags;
          asm("" : "+r"(h2));
          g4 = 0xFE;
          g4 &= h2;
          zz = 0;
          (p->s).flags = g4;
        }
        *st = zz;
        {
          register u8* a asm("r0");
          a = (u8*)p + 0x90;
          asm volatile("str %0, [%1]" ::"l"(zz), "l"(a) : "memory");
          a += 4;
          asm("" : "+r"(a));
          *a = zz;
        }
        {
          register u8 h3 asm("r1");
          register u8 g5 asm("r0");
          h3 = (p->s).flags;
          asm("" : "+r"(h3));
          g5 = 0xFB;
          g5 &= h3;
          (p->s).flags = g5;
        }
        (p->s).mode[1] = zz;
      }
      break;
    }
  }
}

static const struct Collision sCollisions[2] = {
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 0,
      LAYER(RECOIL_PUSHABLE),
      hitzone : 0xFF,
      remaining : 0,
      range : {PIXEL(0), PIXEL(16), PIXEL(32), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(4)},
    },
};

static const struct Rect sSize = {PIXEL(0), PIXEL(16), PIXEL(32), PIXEL(32)};
