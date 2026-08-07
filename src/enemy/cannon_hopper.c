#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "physics.h"
#include "vfx.h"
#include "story.h"
#include "score.h"
#include "zero.h"

void CannonHopper_Update(struct Enemy* p);

void FUN_080c6e70(struct Entity* e, struct Coord* c);


struct Entity* CreateLemon(struct Coord* c, s32 spd, s32 ang);
static const struct Collision sCollisions[14];
static const EnemyFunc sDeads[4];
static const u8 u8_ARRAY_0836a424[14];
s32 FUN_08096fb0(struct Enemy* pp) {
  register struct Enemy* p asm("r3");
  register s32 v asm("r4");
  register u32 fl asm("r2");
  p = pp;
  {
    register s32 t asm("r1");
    t = (p->s).coord.x;
    (p->s).unk_coord.x = t;
    t = (p->s).coord.y;
    (p->s).unk_coord.y = t;
  }
  {
    register u32* w asm("r2");
    register u32 zz asm("r1");
    w = (u32*)((u8*)p + 0xc0);
    zz = 0;
    *w = zz;
  }
  {
    register s32 k asm("r1");
    k = -0x200;
    (p->s).d.x = k;
    asm volatile("add %0, %1, #0" : "=&l"(v) : "l"(k));
  }
  fl = (p->s).flags;
  if (({ register u32 m_ asm("r1"); m_ = 0x10; m_ &= fl; m_; }) != 0) {
    v = 0x200;
  }
  (p->s).d.x = v;
  {
    register s32 k asm("r1");
    k = -0x400;
    (p->s).d.y = k;
    asm volatile("add %0, %1, #0" : "=&l"(v) : "l"(k));
  }
  if (({ register u32 m_ asm("r1"); m_ = 0x20; m_ &= fl; m_; }) != 0) {
    v = 0x400;
  }
  (p->s).d.y = v;
  asm volatile("" :: "r"(fl));
}

void FUN_08096ffc(struct Enemy* p, s32 a, s32 b) {
  s32 hit = 0;
  if (b != 0) {
    s32 uy = (p->s).unk_coord.y + b;
    s32 x3, y2, m;
    register s32 f asm("r4");
    register s32 r asm("r2");
    u32 fl;
    (p->s).unk_coord.y = uy;
    {
      s32 t2_ = 0;
      if ((p->s).d.y > 0) {
        t2_ = 1;
      }
      asm("" : "=r"(f) : "0"(t2_));
    }
    x3 = (p->s).unk_coord.x + -0x700;
    y2 = uy;
    {
      u32 fv;
      u32 k20 = 0x20;
      asm("" : "=r"(fv) : "0"((p->s).flags));
      asm("" : "+r"(k20));
      fl = (u8)(k20 & fv);
    }
    m = -0x2F00;
    if (!fl) goto melse1;
    m = 0x2F00;
    asm("" : "+r"(fl));
    if (fl) {
      s32 acc = m;
      asm("" : "+r"(acc));
      acc *= f;
      y2 += acc;
    } else {
    melse1:
      y2 += (1 ^ f) * m;
    }
    if (f != 0) {
      r = PushoutToUp1(x3, y2 + -0x100);
      if (r < 0) {
        s32 t2 = (p->s).unk_coord.y + 0x100;
        (p->s).unk_coord.y = t2 + r;
        hit |= 1;
      }
    } else {
      r = PushoutToDown1(x3, y2 + 0x100);
      if (r > 0) {
        s32 t2 = (p->s).unk_coord.y + -0x100;
        (p->s).unk_coord.y = t2 + r;
        hit |= 1;
      }
    }
    {
      s32 t2_ = 0;
      if ((p->s).d.y > 0) {
        t2_ = 1;
      }
      asm("" : "=r"(f) : "0"(t2_));
    }
    x3 = (p->s).unk_coord.x + 0x700;
    y2 = (p->s).unk_coord.y;
    {
      u32 fv;
      u32 k20 = 0x20;
      asm("" : "=r"(fv) : "0"((p->s).flags));
      asm("" : "+r"(k20));
      fl = (u8)(k20 & fv);
    }
    m = -0x2F00;
    if (!fl) goto melse2;
    m = 0x2F00;
    asm("" : "+r"(fl));
    if (fl) {
      s32 acc = m;
      asm("" : "+r"(acc));
      acc *= f;
      y2 += acc;
    } else {
    melse2:
      y2 += (1 ^ f) * m;
    }
    if (f != 0) {
      r = PushoutToUp1(x3, y2 + -0x100);
      if (r < 0) {
        s32 t2 = (p->s).unk_coord.y + 0x100;
        (p->s).unk_coord.y = t2 + r;
        hit |= 1;
      }
    } else {
      r = PushoutToDown1(x3, y2 + 0x100);
      if (r > 0) {
        s32 t2 = (p->s).unk_coord.y + -0x100;
        (p->s).unk_coord.y = t2 + r;
        hit |= 1;
      }
    }
  }
  if (a != 0) {
    s32 ux = (p->s).unk_coord.x + a;
    s32 x3, y2;
    register s32 f asm("r4");
    register s32 r asm("r3");
    s32 fl2;
    (p->s).unk_coord.x = ux;
    {
      s32 t2_ = 0;
      if ((p->s).d.x > 0) {
        t2_ = 1;
      }
      asm("" : "=r"(f) : "0"(t2_));
    }
    x3 = ux + -0x700;
    x3 += f * 0xE00;
    y2 = (p->s).unk_coord.y + -0x200;
    if (f != 0) {
      r = PushoutToLeft1(x3, y2);
      if (r < 0) {
        (p->s).unk_coord.x += r;
        hit = (u8)(hit | 2);
      }
    } else {
      r = PushoutToRight1(x3, y2);
      if (r > 0) {
        (p->s).unk_coord.x += r;
        hit = (u8)(hit | 2);
      }
    }
    {
      s32 t2_ = 0;
      if ((p->s).d.x > 0) {
        t2_ = 1;
      }
      asm("" : "=r"(f) : "0"(t2_));
    }
    x3 = (p->s).unk_coord.x;
    x3 += -0x700;
    x3 += f * 0xE00;
    y2 = (p->s).unk_coord.y;
    fl2 = (p->s).flags & 0x20;
    if (fl2 != 0) {
      y2 += 0x2D00;
    } else {
      y2 += -0x2D00;
    }
    if (f != 0) {
      r = PushoutToLeft1(x3, y2);
      if (r < 0) {
        (p->s).unk_coord.x += r;
        hit = (u8)(hit | 2);
      }
    } else {
      r = PushoutToRight1(x3, y2);
      if (r > 0) {
        (p->s).unk_coord.x += r;
        hit = (u8)(hit | 2);
      }
    }
  }
  if ((hit & 1) == 0 && (p->s).d.x != 0 && (p->s).d.y != 0) {
    s32* cnt = (s32*)((u8*)p + 0xc0);
    *cnt = *cnt + 1;
  } else {
    (p->s).d.x = 0;
    (p->s).d.y = 0;
  }
  if (hit & 2) {
    (p->s).d.x = -(p->s).d.x;
  }
}

u32 FUN_08097224(struct Enemy* p, s32 a, s32 b) {
  s32 hit = 0;
  if (b != 0) {
    s32 uy = (p->s).coord.y + b;
    s32 x3, y2, m;
    register s32 f asm("r5");
    register s32 r asm("r2");
    u32 fl;
    (p->s).coord.y = uy;
    {
      s32 t2_ = 0;
      if ((p->s).d.y > 0) {
        t2_ = 1;
      }
      asm("" : "=r"(f) : "0"(t2_));
    }
    x3 = (p->s).coord.x + -0x700;
    y2 = uy;
    {
      u32 fv;
      u32 k20 = 0x20;
      asm("" : "=r"(fv) : "0"((p->s).flags));
      asm("" : "+r"(k20));
      fl = (u8)(k20 & fv);
    }
    m = -0x2F00;
    if (!fl) goto melse1;
    m = 0x2F00;
    asm("" : "+r"(fl));
    if (fl) {
      s32 acc = m;
      asm("" : "+r"(acc));
      acc *= f;
      y2 += acc;
    } else {
    melse1:
      y2 += (1 ^ f) * m;
    }
    if (f != 0) {
      r = PushoutToUp1(x3, y2 + -0x100);
      if (r < 0) {
        s32 t2 = (p->s).coord.y + 0x100;
        (p->s).coord.y = t2 + r;
        hit |= 1;
      }
    } else {
      r = PushoutToDown1(x3, y2 + 0x100);
      if (r > 0) {
        s32 t2 = (p->s).coord.y + -0x100;
        (p->s).coord.y = t2 + r;
        hit |= 1;
      }
    }
    {
      s32 t2_ = 0;
      if ((p->s).d.y > 0) {
        t2_ = 1;
      }
      asm("" : "=r"(f) : "0"(t2_));
    }
    x3 = (p->s).coord.x + 0x700;
    y2 = (p->s).coord.y;
    {
      u32 fv;
      u32 k20 = 0x20;
      asm("" : "=r"(fv) : "0"((p->s).flags));
      asm("" : "+r"(k20));
      fl = (u8)(k20 & fv);
    }
    m = -0x2F00;
    if (!fl) goto melse2;
    m = 0x2F00;
    asm("" : "+r"(fl));
    if (fl) {
      s32 acc = m;
      asm("" : "+r"(acc));
      acc *= f;
      y2 += acc;
    } else {
    melse2:
      y2 += (1 ^ f) * m;
    }
    if (f != 0) {
      r = PushoutToUp1(x3, y2 + -0x100);
      if (r < 0) {
        s32 t2 = (p->s).coord.y + 0x100;
        (p->s).coord.y = t2 + r;
        hit |= 1;
      }
    } else {
      r = PushoutToDown1(x3, y2 + 0x100);
      if (r > 0) {
        s32 t2 = (p->s).coord.y + -0x100;
        (p->s).coord.y = t2 + r;
        hit |= 1;
      }
    }
  }
  if (a != 0) {
    s32 ux = (p->s).coord.x + a;
    s32 x3, y2;
    register s32 f asm("r5");
    register s32 r asm("r3");
    s32 fl2;
    s32 cy;
    (p->s).coord.x = ux;
    {
      s32 t2_ = 0;
      if ((p->s).d.x > 0) {
        t2_ = 1;
      }
      asm("" : "=r"(f) : "0"(t2_));
    }
    x3 = ux + -0x700;
    x3 += f * 0xE00;
    cy = (p->s).coord.y;
    y2 = cy + -0x200;
    fl2 = (p->s).flags & 0x20;
    if (fl2 != 0) {
      y2 = cy + 0x200;
    }
    if (f != 0) {
      r = PushoutToLeft1(x3, y2);
      if (r < 0) {
        (p->s).coord.x += r;
        hit = (u8)(hit | 2);
      }
    } else {
      r = PushoutToRight1(x3, y2);
      if (r > 0) {
        (p->s).coord.x += r;
        hit = (u8)(hit | 2);
      }
    }
    {
      s32 t2_ = 0;
      if ((p->s).d.x > 0) {
        t2_ = 1;
      }
      asm("" : "=r"(f) : "0"(t2_));
    }
    x3 = (p->s).coord.x;
    x3 += -0x700;
    x3 += f * 0xE00;
    y2 = (p->s).coord.y;
    fl2 = (p->s).flags & 0x20;
    if (fl2 != 0) {
      y2 += 0x2D00;
    } else {
      y2 += -0x2D00;
    }
    if (f != 0) {
      r = PushoutToLeft1(x3, y2);
      if (r < 0) {
        (p->s).coord.x += r;
        hit = (u8)(hit | 2);
      }
    } else {
      r = PushoutToRight1(x3, y2);
      if (r > 0) {
        (p->s).coord.x += r;
        hit = (u8)(hit | 2);
      }
    }
  }
  return hit;
}

bool8 FUN_08097428(struct Enemy* p) {
  u8 hit[2];
  register s32 y asm("r4");
  register s32 x0 asm("r2");
  {
    register u8* q2 asm("r2");
    register u8* q1 asm("r1");
    q2 = hit;
    asm("" : "+r"(q2));
    q1 = hit;
    asm("" : "+r"(q1));
    q1[1] = 0;
    q2[0] = 0;
  }
  {
    register s32 cx asm("r0");
    register s32 kk asm("r1");
    cx = (p->s).coord.x;
    kk = -0x700;
    x0 = cx + kk;
  }
  y = (p->s).coord.y;
  if (((p->s).flags & 0x20) != 0) {
    register s32 k1 asm("r0");
    k1 = 0xB8 << 6;
    y += k1;
    asm volatile("" ::: "cc");
  } else {
    register s32 k2 asm("r1");
    k2 = -0x2E00;
    y = y + k2;
    asm volatile("" : "+r"(y));
  }
  if (PushoutToDown1(x0, y) > 0) {
    hit[0] = 1;
  }
  {
    register s32 xm asm("r2");
    xm = (p->s).coord.x;
    asm("" : "+r"(xm));
    if (PushoutToDown1(xm, y) > 0) {
      hit[0] = 1;
    }
  }
  {
    register s32 xp asm("r2");
    register s32 cx2 asm("r0");
    register s32 kp asm("r1");
    cx2 = (p->s).coord.x;
    kp = 0xE0 << 3;
    xp = cx2 + kp;
    asm("" : "+r"(xp));
    if (PushoutToDown1(xp, y) > 0) {
      hit[0] = 1;
    }
  }
  {
    register s32 cx asm("r0");
    register s32 kk asm("r1");
    cx = (p->s).coord.x;
    kk = -0x700;
    x0 = cx + kk;
  }
  y = (p->s).coord.y;
  if (((p->s).flags & 0x20) != 0) {
    register s32 k3 asm("r0");
    k3 = 0x80 << 1;
    y += k3;
    asm volatile("" ::: "cc");
  } else {
    register s32 k4 asm("r1");
    k4 = -0x100;
    y = y + k4;
    asm volatile("" : "+r"(y));
  }
  if (PushoutToUp1(x0, y) < 0) {
    hit[1] = 1;
  }
  {
    register s32 xm asm("r2");
    xm = (p->s).coord.x;
    asm("" : "+r"(xm));
    if (PushoutToUp1(xm, y) < 0) {
      hit[1] = 1;
    }
  }
  {
    register s32 xp asm("r2");
    register s32 cx2 asm("r0");
    register s32 kp asm("r1");
    cx2 = (p->s).coord.x;
    kp = 0xE0 << 3;
    xp = cx2 + kp;
    asm("" : "+r"(xp));
    if (PushoutToUp1(xp, y) < 0) {
      hit[1] = 1;
    }
  }
  {
    register u8* r0p asm("r0");
    register u8* r1p asm("r1");
    r0p = hit;
    asm("" : "+r"(r0p));
    r1p = hit;
    asm("" : "+r"(r1p));
    {
      register s32 v0 asm("r0");
      register s32 v1 asm("r1");
      v0 = *r0p;
      v1 = r1p[1];
      v0 &= v1;
      return v0;
    }
  }
}

void CannonHopper_Init(struct Enemy* p) {
  register s32 z6 asm("r6");
  s32 f;
  {
    u32 tbl = (u32)gEnemyFnTable;
    u32 id = ((p->s).id) << 2;
    EntityFunc** rt = (EntityFunc**)(tbl + id);
    *(u32*)((p->s).mode) = 1;
    (p->s).onUpdate = (void*)((*rt)[1]);
  }
  {
    register const u8* tbl asm("r1");
    register u32 idx asm("r0");
    register const u8* e2 asm("r0");
    tbl = (const u8*)0x0836A418;
    asm volatile("" : "+r"(tbl));
    idx = (p->s).work[0];
    asm volatile("add %0, %1, %2" : "=l"(e2) : "l"(idx), "l"(tbl));
    (p->s).mode[1] = *e2;
  }
  (p->s).flags |= FLIPABLE;
  InitNonAffineMotion(&p->s);
  {
    register u8 fv asm("r0");
    register s32 k asm("r1");
    fv = (p->s).flags;
    k = 1;
    z6 = 0;
    asm volatile("" : "+r"(z6));
    fv |= k;
    k = 4;
    fv |= k;
    (p->s).flags = fv;
  }
  {
    struct Body* body = &p->body;
    InitBody(body, (const struct Collision*)0x0836A288, &(p->s).coord, 8);
    body->parent = (struct Entity*)p;
    body->fn = (BodyFunc)0x080978C9;
  }
  SetMotion(&p->s, 0xDC00);
  (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y) + 0x100;
  f = 0;
  if ((pZero2->s).coord.x - (p->s).coord.x > 0) {
    f = 1;
  }
  if (f != 0) {
    (p->s).flags |= X_FLIP;
  } else {
    (p->s).flags &= ~X_FLIP;
  }
  {
    s32 v;
    s32 z3;
    u8* oa;
    s32 sh4, ov, m11;
    asm volatile("add %0, %1, #0" : "=&l"(v) : "l"(f));
    {
      u8* xa = (u8*)p + 0x4c;
      z3 = 0;
      *xa = v;
    }
    oa = (u8*)p + 0x4a;
    sh4 = v << 4;
    ov = *oa;
    m11 = -0x11;
    m11 &= ov;
    *oa = m11 | sh4;
    *(s32*)((u8*)p + 0xb8) = z3;
    (p->s).unk_28 = (struct Entity*)(p->s).coord.x;
    *((u8*)p + 0xbf) = z3;
  }
  asm volatile("" ::"r"(z6));
  CannonHopper_Update(p);
}

INCASM("asm/enemy/cannon_hopper_a.inc");

void CannonHopper_Die(struct Enemy* p) {
  if (gCurStory.s.gameflags[4] & 0x40) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
  } else {
    (sDeads[(p->s).mode[1]])(p);
  }
}

void FUN_080978c8(struct Enemy* p) {
  struct Enemy* parent = (struct Enemy*)(p->s).unk_2c;
  *(s32*)((u8*)parent + 0xb4) = pZero2->s.coord.x - (parent->s).coord.x;
}

void FUN_080978e0(struct Enemy* p) {}

void FUN_080978e4(struct Enemy* p) {
  if (((p->body).status & 0x00020001) == 0x00020001) {
    (p->s).mode[1] = 5;
    (p->s).mode[2] = 0;
  }
}

void FUN_08097904(struct Enemy* p) {
  if (((p->body).status & 0x00020001) == 0x00020001) {
    (p->s).mode[1] = 5;
    (p->s).mode[2] = 0;
  }
}

void FUN_08097924(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      register s32 nx asm("r1");
      register u8 nf asm("r0");
      register u8 fv asm("r2");
      *((u8*)p + 0xbe) = 0;
      FUN_08096fb0(p);
      SetMotion(&p->s, MOTION(0xDC, 0));
      SetDDP(&p->body, &sCollisions[0]);
      (p->s).work[2] = 0x18;
      if ((p->s).work[0] == 1) {
        s32 a = *(s32*)((u8*)p + 0x28);
        s32 b = (p->s).coord.x;
        s32 d = a - b;
        if (d < 0) {
          goto nega;
        }
        {
          s32 k = 0x80 << 9;
          if (d > k) {
            goto flipa;
          }
        }
        goto done;
      nega : {
        s32 d2 = b - a;
        s32 k2 = 0x80 << 9;
        if (d2 <= k2) {
          goto done;
        }
      }
      flipa:;
      {
        register s32 t asm("r0");
        fv = (p->s).flags;
        t = fv >> 4;
        nx = 1;
        nx &= ~t;
        if (nx == 0) {
          goto clear;
        }
        nf = 0x10;
        nf |= fv;
        asm volatile("" ::: "cc");
        goto stor;
      }
      } else {
        s32 a = *(s32*)((u8*)p + 0x28);
        s32 b = (p->s).coord.x;
        s32 d = a - b;
        if (d < 0) {
          goto negb;
        }
        {
          s32 k = 0x80 << 7;
          if (d > k) {
            goto flipb;
          }
        }
        goto done;
      negb : {
        s32 d2 = b - a;
        s32 k2 = 0x80 << 7;
        if (d2 <= k2) {
          goto done;
        }
      }
      flipb:;
      {
        register s32 t asm("r0");
        fv = (p->s).flags;
        t = fv >> 4;
        nx = 1;
        nx &= ~t;
        if (nx == 0) {
          goto clear;
        }
        nf = 0x10;
        nf |= fv;
        asm volatile("" ::: "memory");
        goto stor;
      }
      }
    clear:
      nf = 0xEF;
      nf &= fv;
    stor:
      (p->s).flags = nf;
      {
        register u8* a2 asm("r0");
        register u8* b2 asm("r3");
        s32 sh;
        u8 ov;
        s32 m;
        a2 = (u8*)p + 0x4c;
        *a2 = nx;
        b2 = (u8*)p + 0x4a;
        sh = nx << 4;
        ov = *b2;
        m = -0x11;
        m &= ov;
        m |= sh;
        *b2 = m;
      }
    done:
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      register s32 t0 asm("r0");
      register s32 t1 asm("r1");
      FUN_08096ffc(p, (p->s).d.x, (p->s).d.y);
      t0 = (p->s).work[2];
      t0 -= 1;
      (p->s).work[2] = t0;
      t0 <<= 24;
      t1 = (u32)t0 >> 24;
      if (t1 == 0) {
        (p->s).mode[1] = 4;
        (p->s).mode[2] = t1;
      }
      UpdateEntityAnim(&p->s);
      break;
    }
  }
}

void cannonHopper_08097a14(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      register s32 fl asm("r1");
      register s32 v asm("r2");
      SetMotion(&p->s, MOTION(0xDC, 0x01));
      (p->s).work[2] = 0x15;
      {
        register s32 k asm("r0");
        register s32 t asm("r0");
        k = -0x200;
        (p->s).d.x = k;
        asm volatile("add %0, %1, #0" : "=&l"(v) : "l"(k));
        fl = (p->s).flags;
        t = 0x10;
        t &= fl;
        if (t != 0) {
          v = 0x200;
        }
      }
      (p->s).d.x = v;
      {
        register s32 k2 asm("r0");
        register s32 t2 asm("r0");
        k2 = -0x400;
        (p->s).d.y = k2;
        asm volatile("add %0, %1, #0" : "=&l"(v) : "l"(k2));
        t2 = 0x20;
        t2 &= fl;
        if (t2 != 0) {
          v = 0x400;
        }
      }
      (p->s).d.y = v;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      if ((p->s).work[2] != 0) {
        s32 t = (p->s).work[2] - 1;
        (p->s).work[2] = t;
        t <<= 24;
        if (t == 0) {
          SetDDP(&p->body, (const struct Collision*)0x0836A2B8);
        }
        break;
      }
      {
        register s32 r asm("r1");
        r = FUN_08097224(p, (p->s).d.x, (p->s).d.y);
        r &= 2;
        if (r != 0) {
          register u8 fv asm("r2");
          register s32 xf asm("r1");
          register u8 g asm("r0");
          fv = (p->s).flags;
          {
            register s32 sh asm("r0");
            sh = fv >> 4;
            xf = 1;
            asm volatile("bic %0, %1" : "+l"(xf) : "l"(sh));
          }
          if (xf != 0) {
            g = 0x10;
            g |= fv;
          } else {
            g = 0xEF;
            g &= fv;
          }
          (p->s).flags = g;
          *((u8*)p + 0x4c) = xf;
          {
            register u8* oa asm("r3");
            s32 sh4, ov, m11;
            oa = (u8*)p + 0x4a;
            sh4 = xf << 4;
            ov = *oa;
            m11 = -0x11;
            m11 &= ov;
            *oa = m11 | sh4;
          }
          (p->s).d.x = -(p->s).d.x;
        }
      }
      {
        register s32* c0 asm("r1");
        register s32 n asm("r0");
        c0 = (s32*)((u8*)p + 0xc0);
        n = *c0;
        n--;
        *c0 = n;
        if (n <= 9) {
          (p->s).mode[1] = 2;
          (p->s).mode[2] = 0;
        }
      }
      break;
    default:
      return;
  }
  UpdateEntityAnim(&p->s);
}

void cannonHopper_08097af8(struct Enemy* p) {
  register struct Body* bd asm("r5");
  u8* mp;
  u8 m2 = (p->s).mode[2];

  switch (m2) {
    case 0:
      *((u8*)p + 0xbe) = m2;
      SetMotion(&p->s, MOTION(0xDC, 0x02));
      (p->s).work[2] = m2;
      (p->s).work[3] = m2;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      break;
    default:
      return;
  }

  if ((p->s).work[3] > 8) {
    struct Body* b2 = &p->body;
    SetDDP(b2, (const struct Collision*)0x0836A348);
    *((u8*)p + 0xbe) = 4;
    mp = (u8*)p + 0xbe;
    asm volatile("add %0, %1, #0" : "=&l"(bd) : "l"(b2));
  } else {
    u8 v;
    bd = &p->body;
    SetDDP(bd, (const struct Collision*)0x0836A288 + u8_ARRAY_0836a424[(p->s).work[3]] * 2);
    v = u8_ARRAY_0836a424[(p->s).work[3]];
    *((u8*)p + 0xbe) = v;
    mp = (u8*)p + 0xbe;
    asm volatile("");
  }
  (p->s).work[3]++;
  {
    u32 one;
    u8 r = FUN_08097224(p, (p->s).d.x, (p->s).d.y);
    one = 1;
    if (r & one) {
      (p->s).d.x = 0;
      (p->s).d.y = 0;
      (p->s).work[2] = one;
    }
    if (r & 2) {
      register u32 fv asm("r2");
      u32 sh;
      fv = (p->s).flags;
      sh = fv >> 4;
      one &= ~sh;
      if (one) {
        u32 t = X_FLIP;
        t |= fv;
        (p->s).flags = t;
      } else {
        u32 t = 0xEF;
        t &= fv;
        (p->s).flags = t;
      }
      (p->s).spr.xflip = one;
      {
        register u8* oa asm("r3");
        register s32 ov asm("r2");
        s32 sh4, m11;
        oa = (u8*)p + 0x4a;
        sh4 = one << 4;
        ov = *oa;
        m11 = -0x11;
        m11 &= ov;
        *oa = m11 | sh4;
      }
      (p->s).d.x = -(p->s).d.x;
    }
  }
  if ((p->s).work[2] != 0 && (p->s).motion.state == 3) {
    u32 fl, flt, m, tst;
    (p->s).mode[1] = 0;
    (p->s).mode[2] = 0;
    flt = (p->s).flags;
    m = Y_FLIP;
    asm("" : "+l"(m));
    tst = flt & m;
    asm volatile("add %0, %1, #0" : "=&l"(fl) : "l"(flt));
    if (tst) {
      (p->s).coord.y += 0x2F00;
    } else {
      (p->s).coord.y -= 0x2F00;
    }
    {
      u32 sh = (fl << 24) >> 29;
      u32 yf = 1;
      yf &= ~sh;
      if (yf) {
        u32 t = Y_FLIP;
        t |= fl;
        (p->s).flags = t;
      } else {
        u32 t = 0xDF;
        t &= fl;
        (p->s).flags = t;
      }
      (p->s).spr.yflip = yf & 1;
      (p->s).spr.oam.yflip = yf;
    }
    SetDDP(bd, (const struct Collision*)0x0836A288);
    SetMotion(&p->s, MOTION(0xDC, 0x00));
    *mp = 0;
    UpdateEntityAnim(&p->s);
  } else {
    s32 v;
    if ((p->s).flags & Y_FLIP) {
      v = FUN_08009f6c((p->s).coord.x, (p->s).coord.y);
      v -= (p->s).coord.y;
    } else {
      v = FUN_0800a134((p->s).coord.x, (p->s).coord.y);
      v = (p->s).coord.y - v;
    }
    if (v <= 0x1FFF) {
      (p->s).d.x = (p->s).d.x * 240 / 256;
      (p->s).d.y = (p->s).d.y * 240 / 256;
    }
    UpdateEntityAnim(&p->s);
  }
}

void FUN_08097cc8(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SetMotion(&p->s, MOTION(0xdc, 3));
      (p->s).work[2] = 0xc;
      (p->s).mode[2]++;
      // fallthrough
    case 1:
      (p->s).work[2]--;
      if ((p->s).work[2] == 0) {
        (p->s).mode[1] = 1;
        (p->s).mode[2] = 0;
      }
      UpdateEntityAnim(&p->s);
      break;
  }
}

void cannonHopper_08097d10(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      u32 sgn;
      s32 dz;
      u8 dir = ((p->s).flags >> 4) & 1;
      *((u8*)p + 0xbd) = dir;
      dz = (pZero2->s).coord.x - (p->s).coord.x;
      sgn = (u32)dz >> 0x1f;
      if (sgn != 0) {
        u32 t = (p->s).flags;
        t |= 0x10;
        (p->s).flags = t;
      } else {
        u32 f0 = (p->s).flags;
        u32 t = 0xef;
        t &= f0;
        (p->s).flags = t;
      }
      {
        register u32 v asm("r1");
        register u8* oa asm("r4");
        u8* xf;
        s32 z3;
        s32 sh4;
        s32 ov;
        s32 m11;
        v = sgn;
        xf = (u8*)p + 0x4c;
        z3 = 0;
        *xf = v;
        oa = (u8*)p + 0x4a;
        sh4 = v << 4;
        ov = *oa;
        m11 = -0x11;
        m11 &= ov;
        *oa = m11 | sh4;
        (p->s).work[3] = z3;
      }
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      register u32 m asm("r0");
      register u32 m2 asm("r1");
      m = 0xDC14;
      asm volatile("add %0, %1, #0" : "=&l"(m2) : "l"(m));
      m2 += (p->s).work[3];
      SetMotion(&p->s, (u16)m2);
      (p->s).work[2] = 0xc;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 2: {
      s32 t0;
      u8 t;
      FUN_08096ffc(p, (p->s).d.x, (p->s).d.y);
      t0 = (p->s).work[2] - 1;
      (p->s).work[2] = t0;
      t = t0;
      if (t == 0xb && (p->s).work[3] != 0) {
        struct Coord c;
        register u32 ang asm("r4");
        u32 xf;
        u32 yf;
        register s32 idx asm("r2");
        u32 fl;
        u32 m10;
        u32 m20;
        const u8* tb = (const u8*)0x0836A42D;
        register u32 w3 asm("r1");
        asm volatile("" : "+l"(tb));
        w3 = (p->s).work[3];
        asm volatile("" : "+l"(w3));
        idx = w3 - 1;
        ang = *(const u8*)(idx + (u32)tb);
        fl = (p->s).flags;
        m10 = 0x10;
        m10 &= fl;
        m10 <<= 24;
        asm volatile("" : "+l"(m10));
        xf = m10 >> 24;
        if (xf != 0) {
          u32 a2 = 0x80;
          a2 -= ang;
          a2 <<= 24;
          asm volatile("" : "+l"(a2));
          ang = a2 >> 24;
        }
        m20 = 0x20;
        m20 &= fl;
        m20 <<= 24;
        asm volatile("" : "+l"(m20));
        yf = m20 >> 24;
        if (yf != 0) {
          u32 a3 = 0xff;
          a3 -= ang;
          a3 <<= 24;
          asm volatile("" : "+l"(a3));
          ang = a3 >> 24;
        }
        {
          register s32 sh asm("r3");
          const s32* tx;
          s32 bx = (p->s).coord.x;
          s32 v0;
          s32 vx;
          c.x = bx;
          {
            const s32* bx0 = (const s32*)0x0836A434;
            asm volatile("" : "+l"(bx0));
            sh = idx << 2;
            tx = (const s32*)(sh + (u32)bx0);
          }
          v0 = *tx + bx;
          c.x = v0;
          vx = v0;
          if (xf != 0) {
            vx -= *tx * 2;
          }
          c.x = vx;
          {
            const s32* ty;
            s32 by = (p->s).coord.y;
            s32 w0;
            register s32 vy asm("r2");
            c.y = by;
            ty = (const s32*)(sh + 0x0836A448);
            w0 = *ty + by;
            c.y = w0;
            asm volatile("add %0, %1, #0" : "=&l"(vy) : "l"(w0));
            if (yf != 0) {
              vy -= *ty * 2;
            }
            c.y = vy;
          }
        }
        PlaySound(0x2c);
        ((void (*)(struct Coord*, s32, s32))CreateLemon)(&c, 0xa0 << 2, ang);
      }
      if ((p->s).work[2] == 0) {
        s32 n0 = (p->s).work[3] + 1;
        u8 n;
        (p->s).work[3] = n0;
        n = n0;
        if (n == 6) {
          (p->s).mode[2] = 3;
        } else {
          (p->s).mode[2] = 1;
        }
      }
      UpdateEntityAnim(&p->s);
      break;
    }
    case 3:
      SetMotion(&p->s, MOTION(0xDC, 0x00));
      (p->s).work[2] = 0x18;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 4: {
      s32 t;
      FUN_08096ffc(p, (p->s).d.x, (p->s).d.y);
      t = (p->s).work[2] - 1;
      (p->s).work[2] = t;
      if ((t << 24) != 0) {
        goto upd;
      }
      {
        register u32 d asm("r2");
        u32 one;
        register u8* xf asm("r4");
        register u8* oa asm("r3");
        u32 v;
        s32 sh4;
        s32 ov;
        s32 m11;
        d = *((u8*)p + 0xbd);
        if (d != 0) {
          u32 t2 = (p->s).flags;
          t2 |= 0x10;
          (p->s).flags = t2;
        } else {
          u32 f0 = (p->s).flags;
          u32 t2 = 0xef;
          t2 &= f0;
          (p->s).flags = t2;
        }
        one = 1;
        asm volatile("" : "+l"(one));
        {
          u32 vv = one;
          vv &= d;
          v = vv;
        }
        xf = (u8*)p + 0x4c;
        *xf = v;
        oa = (u8*)p + 0x4a;
        sh4 = v << 4;
        ov = *oa;
        m11 = -0x11;
        m11 &= ov;
        *oa = m11 | sh4;
        {
          register u8* oa2 asm("r6");
          s32 c0;
          c0 = *(s32*)((u8*)p + 0xc0);
          asm volatile("add %0, %1, #0" : "=&l"(oa2) : "l"(oa));
          if (c0 <= 0x4f) {
            s32 z0;
            (p->s).mode[1] = 3;
            z0 = 0;
            asm volatile("" : "+l"(z0));
            (p->s).mode[2] = z0;
          } else {
            register u32 f2 asm("r2");
            register u32 nv asm("r1");
            s32 z3;
            f2 = (p->s).flags;
            nv = one;
            nv &= ~(f2 >> 4);
            if (nv != 0) {
              u32 t3 = 0x10;
              t3 |= f2;
              (p->s).flags = t3;
            } else {
              u32 t3 = 0xef;
              t3 &= f2;
              (p->s).flags = t3;
            }
            z3 = 0;
            asm volatile("" : "+l"(z3));
            *xf = nv;
            {
              s32 ov2;
              s32 m2;
              nv <<= 4;
              ov2 = *oa2;
              m2 = -0x11;
              m2 &= ov2;
              *oa2 = m2 | nv;
            }
            (p->s).mode[1] = z3;
            (p->s).mode[2] = z3;
          }
        }
      }
    upd:
      UpdateEntityAnim(&p->s);
      break;
    }
  }
}

void FUN_08097f3c(struct Enemy* p) {
  s32 y0, v, up, dn;
  u32 fl, m;
  struct Coord c;

  switch ((p->s).mode[2]) {
    case 0:
      switch (*((u8*)p + 0xbe)) {
        case 1:
          y0 = (p->s).coord.y;
          (p->s).coord.y = y0 - 0x1200;
          v = (p->s).coord.y;
          if ((p->s).flags & Y_FLIP) {
            v = y0 + 0x1200;
          }
          (p->s).coord.y = v;
          break;
        case 2:
          y0 = (p->s).coord.y;
          (p->s).coord.y = y0 - 0x1800;
          v = (p->s).coord.y;
          if ((p->s).flags & Y_FLIP) {
            v = y0 + 0x1800;
          }
          (p->s).coord.y = v;
          break;
        case 3:
          y0 = (p->s).coord.y;
          (p->s).coord.y = y0 - 0x2300;
          v = (p->s).coord.y;
          fl = (p->s).flags;
          asm("" : "+l"(fl));
          m = Y_FLIP;
          asm("" : "+l"(m));
          if (fl & m) {
            v = y0 + 0x2300;
          }
          (p->s).coord.y = v;
          {
            u32 sh = (fl << 24) >> 29;
            u32 yf = 1;
            yf &= ~sh;
            if (yf) {
              u32 t = Y_FLIP;
              t |= fl;
              (p->s).flags = t;
            } else {
              u32 t = 0xDF;
              t &= fl;
              (p->s).flags = t;
            }
            (p->s).spr.yflip = yf & 1;
            (p->s).spr.oam.yflip = yf;
          }
          break;
        case 4:
          y0 = (p->s).coord.y;
          (p->s).coord.y = y0 - 0x2B00;
          v = (p->s).coord.y;
          fl = (p->s).flags;
          asm("" : "+l"(fl));
          m = Y_FLIP;
          asm("" : "+l"(m));
          if (fl & m) {
            v = y0 + 0x2B00;
          }
          (p->s).coord.y = v;
          {
            u32 sh = (fl << 24) >> 29;
            u32 yf = 1;
            yf &= ~sh;
            if (yf) {
              u32 t = Y_FLIP;
              t |= fl;
              (p->s).flags = t;
            } else {
              u32 t = 0xDF;
              t &= fl;
              (p->s).flags = t;
            }
            (p->s).spr.yflip = yf & 1;
            (p->s).spr.oam.yflip = yf;
          }
          break;
      }
      (p->s).flags &= ~DISPLAY;
      (p->body).status = 0;
      (p->body).prevStatus = 0;
      (p->body).invincibleTime = 0;
      (p->s).flags &= ~COLLIDABLE;
      (p->s).mode[2]++;
      /* fallthrough */
    case 1:
      c.x = (p->s).coord.x;
      c.y = (p->s).coord.y - 0x800;
      CreateSmoke(1, &c);
      FUN_080c6e70(&p->s, &c);
      PlaySound(0x2A);
      if ((u16)FUN_080098a4((p->s).coord.x, (p->s).coord.y) != 0) {
        up = PushoutToUp1((p->s).coord.x, (p->s).coord.y);
        dn = PushoutToDown1((p->s).coord.x, (p->s).coord.y);
        if (up > 0) {
          (p->s).coord.y += dn;
        } else if (dn < 0) {
          (p->s).coord.y += up;
        } else if (-up < dn) {
          (p->s).coord.y += up;
        } else {
          (p->s).coord.y += dn;
        }
      }
      TryDropItem(1, &(p->s).coord);
      if (gScore.enemyCount <= 0x270E) {
        gScore.enemyCount++;
      }
      TryDropZakoDisk((struct Entity*)p, &(p->s).coord);
      SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
      break;
  }
}

INCASM("asm/enemy/cannon_hopper_b.inc");

void FUN_08098414(struct Enemy* p) {
  s32 t;
  u32 m;
  struct Coord c;

  switch ((p->s).mode[2]) {
    case 0: {
      s32 d = 0;
      u32 fl;
      switch (*((u8*)p + 0xbe)) {
        case 1:
          d = -0x1200;
          if ((p->s).flags & Y_FLIP) {
            d = 0x1200;
          }
          break;
        case 2:
          d = -0x1800;
          if ((p->s).flags & Y_FLIP) {
            d = 0x1800;
          }
          break;
        case 3:
          d = -0x2300;
          fl = (p->s).flags;
          m = Y_FLIP;
          asm("" : "+l"(m));
          if (fl & m) {
            d = 0x2300;
          }
          {
            u32 sh = fl >> 5;
            u32 yf = 1;
            yf &= ~sh;
            if (yf) {
              u32 t = Y_FLIP;
              t |= fl;
              (p->s).flags = t;
            } else {
              u32 t = 0xDF;
              t &= fl;
              (p->s).flags = t;
            }
            (p->s).spr.yflip = yf & 1;
            (p->s).spr.oam.yflip = yf;
          }
          break;
        case 4:
          d = -0x2B00;
          fl = (p->s).flags;
          m = Y_FLIP;
          asm("" : "+l"(m));
          if (fl & m) {
            d = 0x2B00;
          }
          {
            u32 sh = fl >> 5;
            u32 yf = 1;
            yf &= ~sh;
            if (yf) {
              u32 t = Y_FLIP;
              t |= fl;
              (p->s).flags = t;
            } else {
              u32 t = 0xDF;
              t &= fl;
              (p->s).flags = t;
            }
            (p->s).spr.yflip = yf & 1;
            (p->s).spr.oam.yflip = yf;
          }
          break;
      }
      FUN_08097224(p, 0, d);
      (p->body).status = 0;
      (p->body).prevStatus = 0;
      (p->body).invincibleTime = 0;
      (p->s).flags &= ~COLLIDABLE;
      {
        s32 k = 0;
        if (*(s32*)((u8*)p + 0xb4) > 0) {
          k = 1;
        }
        (p->s).d.x = 0x280 - ((k * 5) << 8);
      }
      (p->s).d.y = -0x480;
      (p->s).work[2] = 0x14;
      (p->s).mode[2]++;
    }
      /* fallthrough */
    case 1:
      (p->s).coord.x += (p->s).d.x;
      (p->s).coord.y += (p->s).d.y;
      (p->s).d.y += 0x40;
      if ((p->s).d.y > 0x700) {
        (p->s).d.y = 0x700;
      }
      UpdateEntityAnim(&p->s);
      t = (p->s).work[2] - 1;
      (p->s).work[2] = t;
      if ((t << 24) != 0) {
        if ((u16)FUN_080098a4((p->s).coord.x, (p->s).coord.y) == 0) {
          break;
        }
      }
      (p->s).flags &= ~DISPLAY;
      c.x = (p->s).coord.x;
      c.y = (p->s).coord.y + 0x100;
      CreateSmoke(1, &c);
      FUN_080c6e70(&p->s, &c);
      PlaySound(0x2A);
      TryDropItem(1, &(p->s).coord);
      if (gScore.enemyCount <= 0x270E) {
        gScore.enemyCount++;
      }
      TryDropZakoDisk((struct Entity*)p, &(p->s).coord);
      (p->s).mode[2]++;
      break;
    case 2:
      (p->s).flags &= ~DISPLAY;
      if ((p->s).work[2] != 0) {
        (p->s).work[2]--;
        break;
      }
      SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
      break;
  }
}

void FUN_0809860c(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      register s32 k asm("r6");
      k = 0;
      switch (*((u8*)p + 0xbe)) {
        case 1:
          k = -0x1200;
          if ((p->s).flags & Y_FLIP) {
            k = 0x90 << 5;
          }
          break;
        case 2:
          k = -0x1800;
          if ((p->s).flags & Y_FLIP) {
            k = 0xc0 << 5;
          }
          break;
        case 3: {
          u32 f;
          u32 tf;
          k = -0x2300;
          f = (p->s).flags;
          tf = Y_FLIP;
          asm volatile("" : "+l"(tf));
          tf &= f;
          if (tf) {
            k = 0x8c << 6;
          }
          {
            u32 sh = f >> 5;
            u32 yf = 1;
            yf &= ~sh;
            if (yf) {
              u32 t = Y_FLIP;
              t |= f;
              (p->s).flags = t;
            } else {
              u32 t = 0xDF;
              t &= f;
              (p->s).flags = t;
            }
            {
              register u32 v asm("r0");
              register u8* pa asm("r1");
              register u8* oa asm("r3");
              s32 sh5;
              s32 ov;
              s32 m21;
              v = yf;
              pa = (u8*)p + 0x4d;
              *pa = v;
              oa = (u8*)p + 0x4a;
              sh5 = v << 5;
              ov = *oa;
              m21 = -0x21;
              m21 &= ov;
              *oa = m21 | sh5;
            }
          }
          break;
        }
        case 4: {
          u32 f;
          u32 tf;
          k = -0x2B00;
          f = (p->s).flags;
          tf = Y_FLIP;
          asm volatile("" : "+l"(tf));
          tf &= f;
          if (tf) {
            k = 0xac << 6;
          }
          {
            u32 sh = f >> 5;
            u32 yf = 1;
            yf &= ~sh;
            if (yf) {
              u32 t = Y_FLIP;
              t |= f;
              (p->s).flags = t;
            } else {
              u32 t = 0xDF;
              t &= f;
              (p->s).flags = t;
            }
            {
              register u32 v asm("r0");
              register u8* pa asm("r1");
              register u8* oa asm("r3");
              s32 sh5;
              s32 ov;
              s32 m21;
              v = yf;
              pa = (u8*)p + 0x4d;
              *pa = v;
              oa = (u8*)p + 0x4a;
              sh5 = v << 5;
              ov = *oa;
              m21 = -0x21;
              m21 &= ov;
              *oa = m21 | sh5;
            }
          }
          break;
        }
      }
      FUN_08097224(p, 0, k);
      SetDDP(&p->body, (const struct Collision*)0x0836A3A8);
      SetMotion(&p->s, MOTION(0xDC, 0x00));
      UpdateEntityAnim(&p->s);
      {
        struct Zero* z = pZero2;
        register s32 dx asm("r1");
        register s32 dy asm("r0");
        u32 len;
        {
          register s32 zx asm("r0");
          dx = (p->s).coord.x;
          zx = (z->s).coord.x;
          asm volatile("" : "+l"(dx), "+l"(zx));
          dx -= zx;
        }
        (p->s).d.x = dx;
        dy = (p->s).coord.y + -0x1800;
        asm volatile("" : "+l"(dy));
        dy -= (z->s).coord.y;
        (p->s).d.y = dy;
        {
          register s32 sq asm("r6");
          s32 tq;
          dx >>= 8;
          sq = dx * dx;
          dy >>= 8;
          tq = dy * dy;
          asm volatile("" : "+l"(tq));
          sq += tq;
          len = ((u32)Sqrt(sq) << 16) >> 8;
        }
        if (len != 0) {
          s32 vx = ((p->s).d.x << 8) / (s32)len;
          s32 vy;
          (p->s).d.x = vx;
          vy = ((p->s).d.y << 8) / (s32)len;
          (p->s).d.x = (vx * 2 + vx) * 2;
          (p->s).d.y = (vy * 2 + vy) * 2;
        } else {
          (p->s).d.x = 0xc0 << 3;
          (p->s).d.y = len;
        }
      }
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 hit = 0;
      register s32 r asm("r6");
      s32 nx;
      s32 ny;
      s32 cx0 = (p->s).coord.x;
      s32 dx = (p->s).d.x;
      nx = cx0 + dx;
      (p->s).coord.x = nx;
      if (dx > 0) {
        r = PushoutToLeft1(nx, (p->s).coord.y);
        if (r < 0) {
          if (r <= -0x800) {
            goto ydone;
          }
          goto xhit;
        }
      } else {
        r = PushoutToRight1(nx, (p->s).coord.y);
        if ((u32)(r - 1) <= 0x7FE) {
          goto xhit;
        }
      }
      goto ydone;
    xhit:
      hit = 1;
      (p->s).coord.x += r;
    ydone:
      (p->s).d.y += 0x40;
      if ((p->s).d.y > 0x700) {
        (p->s).d.y = 0x700;
      }
      ny = (p->s).coord.y + (p->s).d.y;
      (p->s).coord.y = ny;
      if ((p->s).d.y > 0) {
        r = PushoutToUp1((p->s).coord.x, ny);
        if (r < 0) {
          if (r <= -0x800) {
            goto chk;
          }
          goto yhit;
        }
      } else {
        r = PushoutToDown1((p->s).coord.x, ny);
        if ((u32)(r - 1) <= 0x7FE) {
          goto yhit;
        }
      }
      goto chk;
    yhit:
      hit = 1;
      (p->s).coord.y += r;
    chk:
      if (hit != 0) {
        goto call;
      }
      if ((u16)FUN_080098a4((p->s).coord.x, (p->s).coord.y) != 0) {
        goto call;
      }
      if (((p->body).status & 4) == 0) {
        break;
      }
    call:
      FUN_08097f3c(p);
      break;
    }
  }
}

void CannonHopper_Init(struct Enemy* p);
void CannonHopper_Update(struct Enemy* p);
void CannonHopper_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gCannonHopperRoutine = {
    [ENTITY_INIT] =      CannonHopper_Init,
    [ENTITY_UPDATE] =    CannonHopper_Update,
    [ENTITY_DIE] =       CannonHopper_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// 0x0836A288
static const struct Collision sCollisions[14] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(6), PIXEL(24), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(9), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(14), PIXEL(14), PIXEL(28)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(14), PIXEL(14), PIXEL(28)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(24), PIXEL(32), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(24), PIXEL(32), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(34), PIXEL(32), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(34), PIXEL(32), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(40), PIXEL(24), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(40), PIXEL(24), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(9), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(9), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      damage : 2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(6), PIXEL(24), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(9), PIXEL(16), PIXEL(16)},
    },
};

void FUN_080978e4(struct Enemy* p);
void FUN_08097904(struct Enemy* p);
void FUN_080978e0(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[6] = {
    FUN_080978e4,
    FUN_08097904,
    FUN_08097904,
    FUN_080978e4,
    FUN_080978e4,
    FUN_080978e0,
};
// clang-format on

void FUN_08097924(struct Enemy* p);
void cannonHopper_08097a14(struct Enemy* p);
void cannonHopper_08097af8(struct Enemy* p);
void FUN_08097cc8(struct Enemy* p);
void cannonHopper_08097d10(struct Enemy* p);
void FUN_0809860c(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[6] = {
    FUN_08097924,
    cannonHopper_08097a14,
    cannonHopper_08097af8,
    FUN_08097cc8,
    cannonHopper_08097d10,
    FUN_0809860c,
};
// clang-format on

// --------------------------------------------

void FUN_08097f3c(struct Enemy* p);
void FUN_08098110(struct Enemy* p);
void FUN_08098414(struct Enemy* p);
void FUN_0809860c(struct Enemy* p);

static const EnemyFunc sDeads[4] = {
    FUN_08097f3c,
    FUN_08098110,
    FUN_08098414,
    FUN_0809860c,
};

// --------------------------------------------

// 0x0836A418
static const u8 sInitModes[4] = {0, 0, 0, 0};
static const Coords32 sElementCoord = {PIXEL(0), -PIXEL(19)};

// 0x0836A424
static const u8 u8_ARRAY_0836a424[14] = {
    0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x16, 0x2B, 0x40, 0x55, 0x6A,
};

// 0x0836A434
static const s32 s32_ARRAY_0836a434[10] = {
    -PIXEL(8), -PIXEL(6), PIXEL(0), PIXEL(6), PIXEL(8), -PIXEL(18), -PIXEL(18), -PIXEL(20), -PIXEL(18), -PIXEL(18),
};
