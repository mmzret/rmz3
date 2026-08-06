#include "collision.h"
#include "global.h"
#include "physics.h"
#include "projectile.h"
#include "vfx.h"
#include "trig.h"
#include "zero.h"

NAKED void FUN_080a4fa4(struct Projectile* p);
void FUN_080a4fa4(struct Projectile* p);
void FUN_080a4f3c(struct Projectile* p);
void FUN_080a4f3c(struct Projectile* p);
void FUN_080a4fa4(struct Projectile* p);

void FUN_080bf438(s32 x, s32 y, u8 kind);

static void Projectile20_Init(Projectile* p);
static void Projectile20_Update(Projectile* p);
static void Projectile20_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile20Routine = {
    [ENTITY_INIT] =      (void*)Projectile20_Init,
    [ENTITY_UPDATE] =    (void*)Projectile20_Update,
    [ENTITY_DIE] =       (void*)Projectile20_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void FUN_080a4ef8(Entity* e) {
  Projectile* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 20);
    p->work[0] = 0;
    p->unk_28 = (void*)e;
  }
}

void FUN_080a4f3c(struct Projectile* p) {
  s32 i;
  for (i = 0; i < 4; i++) {
    register s32 x asm("r4");
    s32 y;
    x = (p->coord).x - PIXEL(16);
    x += (RANDOM(RNG_0202f388) & 0x1FFF);
    y = FUN_08009f6c(x, (p->coord).y);
    if (((y - (p->coord).y) >= -PIXEL(24)) && ((y - (p->coord).y) < PIXEL(24))) {
      FUN_080bf438(x, y, 1);
    }
  }
}

NAKED void FUN_080a4fa4(struct Projectile* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r3, r0, #0\n\
	ldr r5, [r3, #0x28]\n\
	adds r0, #0xb4\n\
	ldrh r4, [r0]\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080A4FBE\n\
	rsbs r0, r4, #0\n\
	lsls r0, r0, #0x10\n\
	lsrs r4, r0, #0x10\n\
_080A4FBE:\n\
	ldr r6, [r5, #0x54]\n\
	str r6, [r3, #0x54]\n\
	ldr r2, _080A4FF8 @ =gSineTable\n\
	lsrs r0, r4, #8\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	movs r7, #0\n\
	ldrsh r1, [r0, r7]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0xb\n\
	rsbs r0, r0, #0\n\
	adds r7, r2, #0\n\
	lsrs r2, r4, #8\n\
	cmp r0, #0\n\
	bge _080A4FE0\n\
	adds r0, #0xff\n\
_080A4FE0:\n\
	asrs r0, r0, #8\n\
	adds r0, r6, r0\n\
	str r0, [r3, #0x54]\n\
	ldr r1, _080A4FFC @ =0xFFFFC000\n\
	adds r0, r4, r1\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	blt _080A5000\n\
	adds r1, r3, #0\n\
	adds r1, #0x25\n\
	movs r0, #0x17\n\
	b _080A5006\n\
	.align 2, 0\n\
_080A4FF8: .4byte gSineTable\n\
_080A4FFC: .4byte 0xFFFFC000\n\
_080A5000:\n\
	adds r1, r3, #0\n\
	adds r1, #0x25\n\
	movs r0, #0x19\n\
_080A5006:\n\
	strb r0, [r1]\n\
	ldr r1, [r5, #0x58]\n\
	str r1, [r3, #0x58]\n\
	adds r0, r3, #0\n\
	adds r0, #0xb8\n\
	ldr r0, [r0]\n\
	asrs r0, r0, #8\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r7\n\
	movs r4, #0\n\
	ldrsh r0, [r0, r4]\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	str r1, [r3, #0x58]\n\
	adds r0, r2, #0\n\
	adds r0, #0x40\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r7\n\
	movs r7, #0\n\
	ldrsh r0, [r0, r7]\n\
	lsls r0, r0, #0xa\n\
	rsbs r0, r0, #0\n\
	cmp r0, #0\n\
	bge _080A503C\n\
	adds r0, #0xff\n\
_080A503C:\n\
	asrs r0, r0, #8\n\
	adds r0, r1, r0\n\
	str r0, [r3, #0x58]\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

// 0x080a5048
static void onCollision(struct Body* body UNUSED, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {}

// --------------------------------------------

static const struct Collision sCollisions[];
static const u8 sInitModes[];

static void Projectile20_Init(Projectile* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  INIT_BODY(p, &sCollisions[0], 1, onCollision);
  Projectile20_Update(p);
}

static void FUN_080a5144(Projectile* _ UNUSED);
void FUN_080a5148(Projectile* p);
void FUN_080a51b4(Projectile* p);
void FUN_080a5290(Projectile* p);
void FUN_080a53e8(Projectile* p);
void FUN_080a54f8(Projectile* p);
void FUN_080a569c(Projectile* p);
void FUN_080a57ac(Projectile* p);
void FUN_080a598c(Projectile* p);
void FUN_080a5ac0(Projectile* p);
void FUN_080a5b28(Projectile* p);

static void Projectile20_Update(Projectile* p) {
  // clang-format off
  static const ProjectileFunc sUpdates1[10] = {
    FUN_080a5144,
    FUN_080a5144,
    FUN_080a5144,
    FUN_080a5144,
    FUN_080a5144,
    FUN_080a5144,
    FUN_080a5144,
    FUN_080a5144,
    FUN_080a5144,
    FUN_080a5144,
  }; // 0x0836ba50
  // clang-format on
  // clang-format off
  static const ProjectileFunc sUpdates2[10] = {
      FUN_080a5148,
      FUN_080a51b4,
      FUN_080a5290,
      FUN_080a53e8,
      FUN_080a54f8,
      FUN_080a569c,
      FUN_080a57ac,
      FUN_080a598c,
      FUN_080a5ac0,
      FUN_080a5b28,
  }; // 0x0836ba78
  // clang-format on

  Entity* q = (Entity*)p->unk_28;
  if ((q->mode[0] >= ENTITY_DIE) && (p->mode[1] != 7)) {
    p->mode[1] = 7, p->mode[2] = 0;
  }
  (sUpdates1[p->mode[1]])(p);
  (sUpdates2[p->mode[1]])(p);
}

static void Projectile20_Die(Projectile* p) {
  EXIT_BODY(p);
  CreateSmoke(3, &p->coord);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void FUN_080a5144(Projectile* _ UNUSED) {}

void FUN_080a5148(Projectile* p) {
  s32 m = p->mode[2];
  switch (m) {
    case 0:
      *(s32*)((u8*)p + 0xb4) = m;
      *(s32*)((u8*)p + 0xb8) = 0x2000;
      p->renderPrio = 0x19;
      SetMotion((struct Entity*)p, MOTION(0x49, 0x00));
      p->work[2] = m;
      p->mode[2]++;
      FALLTHROUGH;
    case 1: {
      s32* q = (s32*)((u8*)p + 0xb4);
      s32 v = *q + 0x100;
      *q = v;
      if (v > 0x3FFF) {
        s32 z = 0;
        p->mode[1] = 1;
        p->mode[2] = z;
      }
      FUN_080a4fa4(p);
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

void FUN_080a51b4(Projectile* p) {
  struct Entity* q = p->unk_28;
  switch (p->mode[2]) {
    case 0: {
      register s32 xf asm("r2");
      SetDDP(&p->body, (const struct Collision*)0x0836BAD0);
      InitNonAffineMotion((struct Entity*)p);
      {
        register s32 qf asm("r0");
        register s32 one asm("r0");
        qf = q->flags;
        xf = qf >> 4;
        one = 1;
        xf &= one;
      }
      if (xf != 0) {
        p->flags |= X_FLIP;
      } else {
        p->flags &= ~X_FLIP;
      }
      {
        register s32 v asm("r1");
        u8* oa;
        s32 sh4, ov, m11;
        asm volatile("add %0, %1, #0" : "=&l"(v) : "l"(xf));
        (p->spr).xflip = v;
        oa = (u8*)p + 0x4a;
        sh4 = v << 4;
        ov = *oa;
        m11 = -0x11;
        m11 &= ov;
        *oa = m11 | sh4;
      }
      SetMotion((struct Entity*)p, 0x4900);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      u32* w;
      u8 z;
      *(s32*)((u8*)p + 0xb8) += 0x200;
      FUN_080a4fa4(p);
      UpdateEntityAnim((struct Entity*)p);
      {
        u8* tc = (u8*)p + 0x25;
        z = 0;
        *tc = 0x17;
      }
      w = (u32*)((u8*)q + 0xc0);
      if (*w & 2) {
        p->mode[1] = 2;
        p->mode[2] = z;
      }
      if (*w & 8) {
        p->mode[1] = 5;
        p->mode[2] = z;
      }
      if (*w & 0x20) {
        p->mode[1] = 7;
        p->mode[2] = z;
      }
      if (*w & 0x80) {
        p->mode[1] = 9;
        p->mode[2] = z;
      }
      break;
    }
  }
}

void FUN_080a5290(Projectile* p) {
  struct Entity* q = p->unk_28;
  switch (p->mode[2]) {
    case 0: {
      register s32 xf asm("r2");
      register s32 z asm("r4");
      SetDDP(&p->body, &sCollisions[1]);
      {
        u8* tc = (u8*)p + 0x25;
        *tc = 0x17;
      }
      InitRotatableMotion((struct Entity*)p);
      {
        register s32 qf asm("r0");
        register s32 one asm("r0");
        qf = q->flags;
        xf = qf >> 4;
        one = 1;
        xf &= one;
      }
      if (xf != 0) {
        register s32 g asm("r0");
        register s32 k asm("r1");
        g = p->flags;
        asm("" : "+r"(g));
        k = 0x10;
        g |= k;
        p->flags = g;
      } else {
        p->flags &= ~X_FLIP;
      }
      {
        register s32 v asm("r1");
        register u8* xp asm("r0");
        u8* oa;
        s32 sh4, ov, m11;
        asm volatile("add %0, %1, #0" : "=&l"(v) : "l"(xf));
        xp = (u8*)p + 0x4c;
        z = 0;
        *xp = v;
        oa = (u8*)p + 0x4a;
        sh4 = v << 4;
        ov = *oa;
        m11 = -0x11;
        m11 &= ov;
        *oa = m11 | sh4;
      }
      SetMotion((struct Entity*)p, 0x4901);
      p->work[2] = z;
      p->work[3] = 0x10;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      register s32 dx asm("r6");
      register s32 dy asm("r5");
      register s32 cx asm("r4");
      register s32 cy asm("r8");
      s32 sp;
      if ((u8)--p->work[3] == 0) {
        p->mode[2]++;
      }
      {
        register s32 t asm("r0");
        t = (q->coord).x;
        cx = p->coord.x;
        dx = t - cx;
        t = (q->coord).y;
        {
          register s32 u asm("r1");
          u = p->coord.y;
          cy = u;
          dy = t - u;
        }
      }
      {
        register s32 num asm("r0");
        num = dx << 8;
        sp = 0xe0 << 1;
        cx += num / sp;
        p->coord.x = cx;
        num = dy << 8;
        p->coord.y = (num / sp) + cy;
      }
      {
        register s32 a asm("r0");
        a = p->work[2];
        a += 0x10;
        p->work[2] = a;
        {
          register u8* ap asm("r1");
          ap = (u8*)p + 0x24;
          *ap = a;
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
    case 2: {
      register s32 dx asm("r6");
      register s32 dy asm("r5");
      register s32 a asm("r2");
      {
        register s32 zx asm("r0");
        register s32 t asm("r1");
        zx = (pZero2->s).coord.x;
        t = p->coord.x;
        dx = zx - t;
        t = p->coord.y;
        dy = FUN_08009f6c(zx, t);
        t = p->coord.y;
        dy -= t;
      }
      {
        register s32 t asm("r0");
        t = ArcTan2(dx >> 8, dy >> 8) >> 8;
        asm("" : "+r"(t));
        a = t;
      }
      a += 0x40;
      p->work[2] = a;
      if ((p->flags & X_FLIP) != 0) {
        register s32 n asm("r0");
        n = -a;
        p->work[2] = n;
      }
      {
        register s32 av asm("r1");
        register u8* ap asm("r0");
        av = p->work[2];
        ap = (u8*)p + 0x24;
        *ap = av;
      }
      p->work[3] = 20;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 3: {
      register s32 r asm("r1");
      {
        register s32 t asm("r0");
        t = p->work[3];
        t -= 1;
        p->work[3] = t;
        r = (u8)t;
      }
      if (r == 0) {
        p->mode[1] = 3;
        p->mode[2] = r;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

void FUN_080a53e8(Projectile* p) {
  struct Entity* q = p->unk_28;
  s32 md = p->mode[2];
  switch (md) {
    case 0: {
      u8 a;
      u8 b;
      SetDDP(&p->body, &sCollisions[1]);
      SetMotion((struct Entity*)p, MOTION(0x49, 0x01));
      a = p->work[2];
      if (p->flags & X_FLIP) {
        a = -a;
      }
      b = a - 0x40;
      p->d.x = (COS(b) * 0x2C0) / 256;
      p->d.y = (SIN(b) * 0x2C0) / 256;
      p->mode[2]++;
      /* fallthrough */
    }
    case 1:
      p->coord.x += p->d.x;
      p->coord.y += p->d.y;
      if (PushoutToUp1(p->coord.x, p->coord.y + 0x1000) < 0) {
        p->mode[2]++;
      }
      {
        s32 t = p->work[2] + 0x10;
        p->work[2] = t;
        p->angle = t;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    case 2:
      p->work[3] = 0x3C;
      p->mode[2]++;
      /* fallthrough */
    case 3:
      {
        s32 t = p->work[2] + 0x10;
        p->work[2] = t;
        p->angle = t;
      }
      UpdateEntityAnim((struct Entity*)p);
      if (*(u32*)((u8*)q + 0xc0) & 4) {
        p->mode[1] = 4;
        p->mode[2] = 0;
      }
      break;
  }
}

void FUN_080a54f8(Projectile* p) {
  register struct Entity* e asm("r5");
  e = p->unk_28;
  switch (p->mode[2]) {
    case 0: {
      register s32 k asm("r6");
      s32 arg;
      s32 dxv;
      SetDDP(&p->body, (const struct Collision*)0x0836BAB8);
      {
        u32 fv = *(u32*)((u8*)e + 0xc0);
        k = 0x10;
        if ((fv & k) != 0) {
        register s32 dy asm("r3");
        register u32 t asm("r3");
        register s32 ex asm("r5");
        register s32 v asm("r2");
        {
          register s32 py asm("r3");
          register s32 ey asm("r0");
          py = p->coord.y;
          ey = e->coord.y;
          dy = py - ey;
        }
        {
          s32 dq = dy;
          if (dy < 0) {
            dq = dy + 7;
          }
          dq >>= 3;
          t = (u16)Sqrt(dq);
        }
        p->d.y = -(s32)(t << 4);
        p->unk_coord.y = k;
        p->work[3] = t;
        ex = e->coord.x;
        {
          s32 v0 = ex - 0x1800;
          u32 tf;
          u32 fl;
          p->d.x = v0;
          asm volatile("add %0, %1, #0" : "=&l"(v) : "l"(v0));
          fl = p->flags;
          asm volatile("add %0, %1, #0" : "=&l"(tf) : "l"(k));
          tf &= fl;
          if (tf != 0) {
            v = ex + (0xc0 << 5);
          }
        }
        {
          register s32 cxx asm("r0");
          cxx = p->coord.x;
          asm volatile("sub %0, %1, %0" : "+l"(cxx) : "l"(v));
          p->d.x = cxx;
          dxv = cxx;
        }
        arg = t;
      } else {
        register s32 dy asm("r3");
        register u32 t asm("r3");
        register s32 bx asm("r2");
        register s32 v asm("r3");
        {
          register s32 py asm("r3");
          register s32 ey asm("r0");
          py = p->coord.y;
          ey = e->coord.y;
          dy = py - ey;
        }
        {
          s32 dq = dy;
          if (dy < 0) {
            dq = dy + 7;
          }
          dq >>= 3;
          t = (u16)Sqrt(dq);
        }
        p->d.y = -(s32)(t << 4);
        p->unk_coord.y = k;
        p->work[3] = t;
        bx = *(s32*)((u8*)e + 0xb8);
        asm volatile("" : : "l"(e));
        {
          s32 v0 = bx - 0x4C00;
          u32 tf;
          u32 fl;
          p->d.x = v0;
          asm volatile("add %0, %1, #0" : "=&l"(v) : "l"(v0));
          fl = p->flags;
          asm volatile("add %0, %1, #0" : "=&l"(tf) : "l"(k));
          tf &= fl;
          if (tf != 0) {
            v = bx + (0x98 << 7);
          }
        }
        {
          register s32 cxx asm("r0");
          cxx = p->coord.x;
          asm volatile("sub %0, %1, %0" : "+l"(cxx) : "l"(v));
          p->d.x = cxx;
          dxv = cxx;
        }
        arg = p->work[3];
      }
      }
      p->d.x = dxv / arg;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 t = p->work[3] - 1;
      s32 w2;
      p->work[3] = t;
      if ((t << 24) == 0) {
        p->mode[2]++;
      }
      w2 = p->work[2] + 0x10;
      p->work[2] = w2;
      p->angle = w2;
      p->coord.x += p->d.x;
      p->coord.y += p->d.y;
      p->d.y += p->unk_coord.y;
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
    case 2: {
      register s32 d asm("r3");
      {
        register s32* q asm("r1");
        register s32 val asm("r0");
        q = (s32*)((u8*)p + 0xb8);
        val = 0;
        *q = val;
        q = (s32*)((u8*)q - 4);
        val = 0x80 << 7;
        *q = val;
      }
      {
        register s32 dyv asm("r0");
        register s32 kk asm("r1");
        dyv = p->work[2] << 8;
        p->d.y = dyv;
        kk = 0x80 << 10;
        d = kk - dyv;
      }
      {
        register s32 dq2 asm("r0");
        asm volatile("add %0, %1, #0" : "=&l"(dq2) : "l"(d));
        if (d < 0) {
          dq2 += 63;
        }
        dq2 >>= 6;
        p->d.x = (u32)((u32)Sqrt(dq2) << 16) >> 9;
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 3: {
      s32 v;
      p->d.y += p->d.x;
      v = p->d.x - 0x80;
      p->d.x = v;
      if (v < 0) {
        register s32 c asm("r1");
        register u32* f asm("r2");
        u32 fv;
        c = 0;
        p->d.y = c;
        p->mode[1] = 1;
        p->mode[2] = c;
        f = (u32*)((u8*)e + 0xc0);
        asm volatile("" : : "l"(e));
        fv = *f;
        c -= 5;
        fv &= c;
        c -= 12;
        fv &= c;
        *f = fv;
      }
      p->angle = p->d.y >> 8;
      FUN_080a4fa4(p);
      p->renderPrio = 23;
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

void FUN_080a569c(Projectile* p) {
  struct Entity* q = p->unk_28;
  s32 md = p->mode[2];
  switch (md) {
    case 0: {
      u8 on;
      SetDDP(&p->body, &sCollisions[2]);
      p->renderPrio = 0x17;
      InitRotatableMotion((struct Entity*)p);
      on = (q->flags >> 4) & 1;
      SET_XFLIP(p, on);
      SetMotion((struct Entity*)p, MOTION(0x49, 0x01));
      p->work[2] = 0;
      p->work[3] = 0x10;
      p->mode[2]++;
      /* fallthrough */
    }
    case 1: {
      s32 t = p->work[3] - 1;
      p->work[3] = t;
      if ((t << 24) == 0) {
        p->mode[2]++;
      }
      {
        s32 dx;
        s32 px;
        s32 dy;
        s32 py;
        dx = q->coord.x;
        px = p->coord.x;
        dx -= px;
        dy = q->coord.y;
        py = p->coord.y;
        dy -= py;
        p->coord.x = px + dx / 6;
        p->coord.y = py + dy / 6;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
    case 2:
      p->work[2] = 0;
      p->work[3] = 0;
      p->mode[2]++;
      /* fallthrough */
    case 3: {
      s32 t = p->work[3] + 1;
      p->work[3] = t;
      if ((u8)t > 0x13) {
        p->mode[1] = 6;
        p->mode[2] = 0;
      }
      if (p->work[3] > 0x10) {
        p->work[2] += 0x10;
      } else {
        p->work[2] += p->work[3];
      }
      p->angle = p->work[2];
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

void FUN_080a57ac(Projectile* p) {
  struct Entity* q = p->unk_28;
  s32 a, b, dy, v;

  switch (p->mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[1]);
      p->d.y = 0x2C0;
      p->mode[2]++;
      /* fallthrough */
    case 1:
      p->coord.y += p->d.y;
      if (p->d.y > 0) {
        a = PushoutToUp1(p->coord.x - 0x1000, p->coord.y + 0x1000);
        b = PushoutToUp1(p->coord.x + 0x1000, p->coord.y + 0x1000);
        if (a != 0 || b != 0) {
          p->mode[2]++;
        }
      } else {
        if (p->flags & X_FLIP) {
          a = PushoutToLeft1(p->coord.x + 0x1000, p->coord.y + 0x1000);
        } else {
          a = PushoutToRight1(p->coord.x - 0x1000, p->coord.y + 0x1000);
        }
        if (a == 0) {
          p->mode[2]++;
        }
      }
      p->work[2] += 0x10;
      p->angle = p->work[2];
      UpdateEntityAnim((struct Entity*)p);
      break;
    case 2:
      p->d.x = -0x2C0;
      v = p->d.x;
      if (p->flags & X_FLIP) {
        v = 0x2C0;
      }
      p->d.x = v;
      p->mode[2]++;
      /* fallthrough */
    case 3:
      p->coord.x += p->d.x;
      if (p->flags & X_FLIP) {
        a = FUN_08009f6c(p->coord.x + 0x1000, p->coord.y + 0x1000);
        b = FUN_08009f6c(p->coord.x - 0x1000, p->coord.y + 0x1000);
      } else {
        a = FUN_08009f6c(p->coord.x - 0x1000, p->coord.y + 0x1000);
        b = FUN_08009f6c(p->coord.x + 0x1000, p->coord.y + 0x1000);
      }
      dy = a - p->coord.y;
      if (dy < -0x1800) {
        p->d.y = -0x2C0;
        p->mode[2] = 1;
      } else if (dy > 0x1800 && b - p->coord.y > 0x1800) {
        p->d.y = 0x2C0;
        p->mode[2] = 1;
      } else {
        a = FUN_08009f6c(p->coord.x, p->coord.y + 0x1000);
        if (a - p->coord.y <= 0x17FF) {
          p->coord.y = a - 0x1000;
        }
      }
      p->work[2] += 0x10;
      p->angle = p->work[2];
      UpdateEntityAnim((struct Entity*)p);
      break;
  }
  v = p->coord.x - *(s32*)((u8*)q + 0xb8);
  if ((v < -0x5800 && !(p->flags & X_FLIP)) || (v > 0x5800 && (p->flags & X_FLIP))) {
    p->mode[1] = 4;
    p->mode[2] = 0;
  }
}

void FUN_080a598c(Projectile* p) {
  struct Entity* e = p->unk_28;
  switch (p->mode[2]) {
    case 0: {
      u32 xf;
      u8 z;
      SetDDP(&p->body, &sCollisions[1]);
      InitRotatableMotion((struct Entity*)p);
      xf = (e->flags >> 4) & 1;
      if (xf != 0) {
        p->flags |= 0x10;
      } else {
        p->flags &= 0xEF;
      }
      {
        u32 xf2;
        asm volatile("add %0, %1, #0" : "=&l"(xf2) : "l"(xf));
        (p->spr).xflip = xf2;
        z = 0;
        xf = xf2;
      }
      {
        u8* oa = (u8*)p + 0x4a;
        u32 sh4 = xf << 4;
        s32 ov = *oa;
        s32 m11 = -0x11;
        m11 &= ov;
        m11 |= sh4;
        *oa = m11;
      }
      SetMotion((struct Entity*)p, MOTION(0x49, 0x01));
      p->renderPrio = 0x17;
      p->work[2] = z;
      p->work[3] = z;
      p->d.y = z;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 a;
      s32 dy;
      {
        s32 w2 = p->work[2] + 1;
        p->work[2] = w2;
        a = p->work[3] + w2;
      }
      p->work[3] = a;
      p->angle = a;
      dy = p->d.y + 0x40;
      p->d.y = dy;
      p->coord.y += dy;
      if (PushoutToUp1(p->coord.x, p->coord.y) < 0) {
        FUN_080a4f3c(p);
        p->mode[2]++;
      }
      break;
    }
    case 2: {
      u8 k;
      u8 z2;
      SetDDP(&p->body, &sCollisions[0]);
      {
        register u8 t asm("r1");
        u8 fv;
        t = p->flags;
        k = 0xFE;
        fv = k;
        fv &= t;
        asm volatile("" ::"r"(t));
        z2 = 0;
        p->flags = fv;
      }
      if (*(u32*)((u8*)e + 0xc0) & 0x40) {
        p->mode[1] = 8;
        p->mode[2] = z2;
      }
      if (e->mode[0] > 1) {
        register u8 t asm("r1");
        u8 fv;
        t = p->flags;
        fv = k;
        fv &= t;
        asm volatile("" ::"r"(t));
        fv &= 0xFD;
        p->flags = fv;
        (p->body).status = z2;
        (p->body).prevStatus = z2;
        (p->body).invincibleTime = z2;
        p->flags &= ~COLLIDABLE;
        SET_PROJECTILE_ROUTINE(p, ENTITY_DISAPPEAR);
      }
      break;
    }
  }
}

void FUN_080a5ac0(Projectile* p) {
  switch (p->mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[1]);
      FUN_080a4f3c(p);
      p->flags |= DISPLAY;
      p->mode[2]++;
      /* fallthrough */
    case 1: {
      u8 t;
      p->coord.y -= p->d.y;
      p->d.y -= 0x40;
      p->work[3] -= p->work[2];
      t = --p->work[2];
      if (t == 0) {
        p->mode[1] = 1;
        p->mode[2] = t;
      }
      p->angle = p->work[3];
      break;
    }
  }
}

void FUN_080a5b28(Projectile* p) {
  struct Entity* q = p->unk_28;
  s32* r;
  switch (p->mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[2]);
      p->d.x = ((u32)((u16)Sqrt(0x400)) << 16) >> 11;
      *(s32*)((u8*)p + 0xb4) = 0x4000;
      p->mode[2]++;
    case 1:
      r = (s32*)((u8*)p + 0xb4);
      *r += p->d.x;
      if (*r > 0x30000) {
        p->d.x -= 0x20;
      }
      if (p->d.x <= 0) {
        s32* w = (s32*)((u8*)q + 0xc0);
        *w &= ~0x80;
        *r = 0x4000;
        p->mode[1] = 1;
        p->mode[2] = 1;
      }
      FUN_080a4fa4(p);
      UpdateEntityAnim((struct Entity*)p);
      break;
  }
}

// --------------------------------------------

// 0x0836BAA0
static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      nature : BODY_NATURE_B2,
      remaining : 0,
      layer : 1,
      range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      nature : BODY_NATURE_B2,
      remaining : 0,
      layer : 1,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(46)},
    },
};

static const u8 sInitModes[4] = {0, 0, 0, 0};
