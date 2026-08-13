#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "zero.h"

struct VFX* FUN_080c07e4(struct Coord* c1, struct Coord* c2, u8 a2, u8 a3);
static const struct Collision sCollisions[16];
static const Coords32 sCoords[30];

INCASM("asm/projectile/cubit_a.inc");

void FUN_080a6718(Projectile* p0) {
  register struct Projectile* p asm("r4");
  u32 tv;
  p = p0;
  {
    struct Entity* q = p->unk_28;
    if (q->mode[0] > 1 || q->mode[1] == 0xB) {
      if (p->mode[2] <= 0x13) {
        p->mode[2] = 0x14;
      }
    }
  }
  switch (p->mode[2]) {
    case 0: {
      s32 g[2];
      register s32* spd8 asm("r6");
      u32 spd;
      SetDDP(&p->body, (const struct Collision*)0x836BCAC);
      spd8 = (s32*)((u8*)p + 0xb8);
      *spd8 = 0xC0 << 2;
      g[0] = FUN_0800a31c(p->coord.x, p->coord.y);
      g[1] = FUN_08009f6c(p->coord.x, p->coord.y) + -0x7C00;
      {
        register u8* b4 asm("r3");
        const u8* tb = (const u8*)0x836BD4C;
        s32 dx;
        s32 dy;
        asm("" : "+r"(tb));
        b4 = (u8*)p + 0xb4;
        dx = (*(s32*)((*b4 << 3) + (u32)tb) + g[0]) - p->coord.x;
        p->d.x = dx;
        dy = (*(s32*)((*b4 << 3) + (u32)(tb += 4)) + g[1]) - p->coord.y;
        p->d.y = dy;
        dx >>= 2;
        spd = ((u32)(Sqrt(({ s32 q0 = dx * dx; asm("" : "+r"(q0)); dy >>= 2; q0; }) + dy * dy) << 16)) >> 14;
      }
      if (spd != 0) {
        p->d.x = (p->d.x << 8) / (s32)spd;
        p->d.y = (p->d.y << 8) / (s32)spd;
      }
      p->unk_coord.x = (p->d.x * *spd8) >> 8;
      p->unk_coord.y = (p->d.y * *spd8) >> 8;
      *(s32*)((u8*)p + 0xbc) = spd;
      {
        s32 av = p->unk_coord.x;
        register u32 k asm("r0");
        if (av < 0) {
          av = -av;
        }
        if (av > 0x80 << 1) {
          if (p->unk_coord.x > 0) {
            SetMotion((struct Entity*)p, MOTION(0xB1, 0x08));
            k = 2;
          } else {
            SetMotion((struct Entity*)p, MOTION(0xB1, 0x07));
            k = 1;
          }
        } else {
          SetMotion((struct Entity*)p, MOTION(0xB1, 0x06));
          k = 0;
        }
        p->work[3] = k;
      }
      {
        u32 z9 = 0;
        asm("" : "+r"(z9));
        p->work[2] = z9;
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      {
        u32 t = p->work[2];
        asm("" : "+r"(t));
        p->work[2] = t + 1;
        if ((u8)((u8)t % 5) == 0) {
          FUN_080c07e4(&p->coord, &p->unk_coord, (p->flags >> 4) & 1, p->work[3]);
        }
      }
      {
        s32 cx = p->coord.x;
        p->coord.x = cx + p->unk_coord.x;
      }
      {
        s32 cy = p->coord.y;
        p->coord.y = cy + p->unk_coord.y;
      }
      UpdateEntityAnim((struct Entity*)p);
      {
        s32* acc = (s32*)((u8*)p + 0xbc);
        s32* spd = (s32*)((u8*)p + 0xb8);
        s32 nv = *acc - *spd;
        *acc = nv;
        if (nv > 0) {
          break;
        }
      }
      p->mode[2]++;
      break;
    }
    case 2: {
      u8* t = (u8*)(p->unk_28) + 0xb4;
      (*t)++;
      p->work[3] = 0x1E;
      SetMotion((struct Entity*)p, MOTION(0xB1, 0x06));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 3: {
      UpdateEntityAnim((struct Entity*)p);
      if (*((u8*)(p->unk_28) + 0xb4) != 5) {
        break;
      }
      {
        u32 w = p->work[3];
        if (w != 0) {
          w--;
          p->work[3] = w;
          tv = w << 24;
          goto testtail;
        }
      }
      p->mode[2]++;
      break;
    }
    case 4: {
      p->unk_coord.x = p->coord.x;
      p->unk_coord.y = p->coord.y;
      {
        u8* t = (u8*)p + 0xbc;
        u32 z = 0;
        *(s32*)t = z;
        t -= 8;
        asm("" : "+r"(t));
        if (*t == 2) {
          if (p->coord.x < (pZero2->s).coord.x) {
            p->work[3] = z;
          } else {
            p->work[3] = 1;
          }
        }
      }
      p->d.x = 0;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 5: {
      u8* b4;
      s32* acc;
      s32 nv;
      UpdateEntityAnim((struct Entity*)p);
      {
        u32 k5;
        {
          u8* t4 = (u8*)p + 0xb4;
          k5 = *t4;
          b4 = t4;
          asm volatile("" :: "r"(t4));
        }
        if (k5 == 0) {
          acc = (s32*)((u8*)p + 0xbc);
          nv = *acc + 3;
        } else if (k5 == 1) {
          acc = (s32*)((u8*)p + 0xbc);
          nv = *acc - 3;
        } else if (k5 == 3) {
          acc = (s32*)((u8*)p + 0xbc);
          nv = *acc + 3;
          asm("" : "+r"(nv));
        } else if (k5 == 4) {
          acc = (s32*)((u8*)p + 0xbc);
          nv = *acc - 3;
        } else if (p->work[3] == 0) {
          acc = (s32*)((u8*)p + 0xbc);
          nv = *acc + 3;
          asm(" " : "+r"(nv));
        } else {
          acc = (s32*)((u8*)p + 0xbc);
          nv = *acc - 3;
        }
        *acc = nv;
      }
      {
        s32* acc5;
        acc5 = acc;
        asm("" : "+r"(acc5));
        {
          const s16* tb = gSineTable;
          s32 sv = tb[(u8)*acc5];
          s32 tx5 = p->unk_coord.x + ((((sv << 2) + sv) >> 1) << 4);
          s32 sv2;
          s32 ty5;
          p->d.x = tx5;
          sv2 = tb[(u8)(*acc5 + 0x40)];
          ty5 = p->unk_coord.y + (sv2 << 6);
          p->d.y = ty5;
          {
            s32 c0 = p->coord.x;
            tx5 -= c0;
            p->coord.x = c0 + ((((tx5 << 2) + tx5) << 3) >> 8);
          }
          {
            s32 c1 = p->coord.y;
            ty5 -= c1;
            p->coord.y = c1 + ((((ty5 << 2) + ty5) << 3) >> 8);
          }
        }
        {
          u32 k6 = *b4;
          if (k6 == 0) {
            s32 v0 = *acc5;
            asm volatile("" : "+r"(v0));
            if (v0 <= 0x9F << 1) {
              break;
            }
            asm volatile("@f1");
          } else if (k6 == 1) {
            s32 v1 = *acc5;
            asm volatile(" " : "+r"(v1));
            {
              s32 th1 = -0x13F;
              asm volatile("@t1" : "+l"(th1));
              if (v1 > th1) {
                break;
              }
            }
            asm volatile("@f2");
          } else if (k6 == 3) {
            s32 v3 = *acc5;
            asm volatile("  " : "+r"(v3));
            if (v3 <= 0x9F << 1) {
              break;
            }
            asm volatile("@f3");
          } else if (k6 == 4) {
            s32 v4 = *acc5;
            asm volatile("   " : "+r"(v4));
            {
              s32 th2 = -0x13F;
              asm volatile("@t2" : "+l"(th2));
              if (v4 > th2) {
                break;
              }
            }
            asm volatile("@f4");
          } else if (p->work[3] == 0) {
            s32 v5 = *acc5;
            asm volatile("    " : "+r"(v5));
            if (v5 <= 0x9F << 1) {
              break;
            }
          } else {
            s32 v6 = *acc5;
            asm volatile("     " : "+r"(v6));
            {
              s32 th3 = -0x13F;
              asm volatile("@t3" : "+l"(th3));
              if (v6 > th3) {
                break;
              }
            }
          }
        }
      }
      p->mode[2]++;
      break;
    }
    case 6: {
      register u8* b4 asm("r6");
      s32* acc;
      s32 nv;
      UpdateEntityAnim((struct Entity*)p);
      {
        u32 k5;
        {
          u8* t4 = (u8*)p + 0xb4;
          k5 = *t4;
          b4 = t4;
          asm volatile("" :: "r"(t4));
        }
        if (k5 == 0) {
          acc = (s32*)((u8*)p + 0xbc);
          nv = *acc + 1;
        } else if (k5 == 1) {
          acc = (s32*)((u8*)p + 0xbc);
          nv = *acc - 1;
        } else if (k5 == 3) {
          acc = (s32*)((u8*)p + 0xbc);
          nv = *acc + 1;
          asm("" : "+r"(nv));
        } else if (k5 == 4) {
          acc = (s32*)((u8*)p + 0xbc);
          nv = *acc - 1;
        } else if (p->work[3] == 0) {
          acc = (s32*)((u8*)p + 0xbc);
          nv = *acc + 1;
          asm(" " : "+r"(nv));
        } else {
          acc = (s32*)((u8*)p + 0xbc);
          nv = *acc - 1;
        }
        *acc = nv;
      }
      {
        register s32* acc5 asm("r5");
        acc5 = acc;
        asm volatile("" :: "r"(acc));
        asm("" : "+r"(acc5));
        {
          s32 u0 = p->unk_coord.x;
          s32 c0 = p->coord.x;
          p->coord.x = c0 + (((u0 - c0) << 4) >> 8);
        }
        {
          s32 u1 = p->unk_coord.y;
          s32 c1 = p->coord.y;
          p->coord.y = c1 + (((u1 - c1) << 4) >> 8);
        }
        {
          u32 k6 = *b4;
          if (k6 == 0) {
            s32 v0 = *acc5;
            asm volatile("      " : "+r"(v0));
            if (v0 <= 0xBF << 1) {
              break;
            }
            asm volatile("@f7");
          } else if (k6 == 1) {
            if (*acc5 > -0x17F) {
              break;
            }
          } else if (k6 == 3) {
            s32 v3 = *acc5;
            asm volatile("        " : "+r"(v3));
            if (v3 <= 0xBF << 1) {
              break;
            }
            asm volatile("@f9");
          } else if (k6 == 4) {
            if (*acc5 > -0x17F) {
              break;
            }
          } else if (p->work[3] == 0) {
            s32 v5 = *acc5;
            asm volatile("          " : "+r"(v5));
            if (v5 <= 0xBF << 1) {
              break;
            }
          } else {
            if (*acc5 > -0x17F) {
              break;
            }
          }
        }
      }
      p->mode[2] = 0xA;
      break;
    }
    case 10: {
      s32* spd8;
      register s32 gx asm("r5");
      register s32 gy asm("r6");
      u32 spd;
      spd8 = (s32*)((u8*)p + 0xb8);
      *spd8 = 0xC0 << 2;
      gx = FUN_0800a31c(p->coord.x, p->coord.y);
      gy = FUN_08009f6c(p->coord.x, p->coord.y) + -0x7C00;
      {
        register u8* b4 asm("r3");
        const u8* tb = (const u8*)0x836BD4C;
        s32 dx;
        s32 dy;
        asm("" : "+r"(tb));
        b4 = (u8*)p + 0xb5;
        dx = (*(s32*)((*b4 << 3) + (u32)tb) + gx) - p->coord.x;
        p->d.x = dx;
        dy = (*(s32*)((*b4 << 3) + (u32)(tb += 4)) + gy) - p->coord.y;
        p->d.y = dy;
        dx >>= 2;
        spd = ((u32)(Sqrt(({ s32 q0 = dx * dx; asm("" : "+r"(q0)); dy >>= 2; q0; }) + dy * dy) << 16)) >> 14;
      }
      if (spd != 0) {
        p->d.x = (p->d.x << 8) / (s32)spd;
        p->d.y = (p->d.y << 8) / (s32)spd;
      }
      p->unk_coord.x = (p->d.x * *spd8) >> 8;
      p->unk_coord.y = (p->d.y * *spd8) >> 8;
      *(s32*)((u8*)p + 0xbc) = spd;
      {
        s32 av = p->unk_coord.x;
        register u32 k asm("r0");
        if (av < 0) {
          av = -av;
        }
        if (av > 0x80 << 1) {
          if (p->unk_coord.x > 0) {
            SetMotion((struct Entity*)p, MOTION(0xB1, 0x08));
            k = 2;
          } else {
            SetMotion((struct Entity*)p, MOTION(0xB1, 0x07));
            k = 1;
          }
        } else {
          SetMotion((struct Entity*)p, MOTION(0xB1, 0x06));
          k = 0;
        }
        p->work[3] = k;
      }
      {
        u32 z9 = 0;
        asm("" : "+r"(z9));
        p->work[2] = z9;
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 11: {
      {
        u32 t = p->work[2];
        asm("" : "+r"(t));
        p->work[2] = t + 1;
        if ((u8)((u8)t % 5) == 0) {
          FUN_080c07e4(&p->coord, &p->unk_coord, (p->flags >> 4) & 1, p->work[3]);
        }
      }
      {
        s32 cx = p->coord.x;
        p->coord.x = cx + p->unk_coord.x;
      }
      {
        s32 cy = p->coord.y;
        p->coord.y = cy + p->unk_coord.y;
      }
      UpdateEntityAnim((struct Entity*)p);
      {
        s32* acc = (s32*)((u8*)p + 0xbc);
        s32* spd = (s32*)((u8*)p + 0xb8);
        s32 nv = *acc - *spd;
        *acc = nv;
        if (nv > 0) {
          break;
        }
      }
      p->mode[2]++;
      break;
    }
    case 12: {
      u8* t = (u8*)(p->unk_28) + 0xb4;
      (*t)--;
      SetMotion((struct Entity*)p, MOTION(0xB1, 0x06));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 13:
      UpdateEntityAnim((struct Entity*)p);
      tv = *((u8*)(p->unk_28) + 0xb4);
    testtail:
      if (tv != 0) {
        break;
      }
      p->mode[2]++;
      break;
    case 14:
      p->renderPrio = 0x19;
      p->work[2] = 0x1E;
      p->mode[2]++;
      FALLTHROUGH;
    case 15:
      UpdateEntityAnim((struct Entity*)p);
      {
        u32 w = p->work[2];
        if (w != 0) {
          w--;
          p->work[2] = w;
          if ((w << 24) != 0) {
            break;
          }
        }
      }
      goto die67;
    case 20:
      SetMotion((struct Entity*)p, MOTION(0xB1, 0x02));
      p->mode[2]++;
      FALLTHROUGH;
    case 21:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
    die67:
      SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
      break;
  }
}

INCASM("asm/projectile/cubit_b.inc");

void cubit_080a6ed4(Projectile* p0) {
  register struct Projectile* p asm("r5");
  p = p0;
  if (((struct Entity*)p->unk_28)->mode[0] > 1) {
    if (p->mode[2] <= 0x13) {
      p->mode[2] = 0x14;
    }
  }
  if ((u8)--p->work[2] == 0) {
    goto die;
  }
  switch (p->mode[2]) {
    case 0: {
      u32 b6;
      u32 x1;
      *((u8*)p + 0x25) = 0x19;
      SetMotion((struct Entity*)p, 0xB100);
      b6 = *((u8*)p + 0xb6);
      {
        register u32 flr asm("r0");
        if (b6 != 0) {
          flr = p->flags | 0x10;
        } else {
          u32 t = p->flags;
          flr = 0xEF;
          flr &= t;
        }
        asm("" : "+r"(flr));
        p->flags = flr;
      }
      x1 = 1 & b6;
      (p->spr).xflip = x1;
      (p->spr).oam.xflip = x1;
      p->mode[2]++;
      asm volatile("" ::"r"(p));
      goto upd;
    }
    case 2:
      SetMotion((struct Entity*)p, 0xB101);
      p->mode[2]++;
      FALLTHROUGH;
    case 3:
      p->work[2] = 0xFF;
      UpdateEntityAnim((struct Entity*)p);
      if (*((u8*)p + 0xb5) != *((u8*)(p->unk_28) + 0xb5)) {
        break;
      }
      goto bump;
    case 4:
      SetMotion((struct Entity*)p, 0xB102);
      p->mode[2]++;
      goto upd;
    case 6: {
      s32 len;
      s32 a;
      s32 k8;
      s32 gy;
      SetMotion((struct Entity*)p, 0xB10C);
      {
        u8* a = (u8*)p + 0x25;
        k8 = 8;
        *a = k8;
        SetDDP((struct Body*)(a + 0x4F), &sCollisions[1]);
      }
      {
        {
          register s32 gx asm("r6");
          struct Entity* gp = (struct Entity*)((struct Entity*)p->unk_28)->unk_28;
          gx = gp->coord.x;
          gy = gp->coord.y;
          {
            const s32* tb = (const s32*)&sCoords[19];
            u8 f = p->flags & 0x10;
            s32 off = ((0 - f) >> 31) & k8;
            p->coord.x = *(const s32*)(off + (u32)tb) + gx;
            tb = (const s32*)((u8*)tb + 4);
            p->coord.y = *(const s32*)(off + (u32)tb) + gy;
          }
        }
        k8 = (s32)((u8*)p + 0xb8);
        *(s32*)k8 = 0xC0 << 2;
        asm volatile("" ::"r"(k8));
        asm volatile("" ::"r"(k8));
        asm volatile("" ::"r"(k8));
        {
          s32 dx = (pZero2->s).coord.x - p->coord.x;
          s32 dy;
          s32 py;
          p->d.x = dx;
          py = p->coord.y + 0x1000;
          dy = (pZero2->s).coord.y - py;
          p->d.y = dy;
          len = (u16)Sqrt((dx >> 2) * (dx >> 2) + (dy >> 2) * (dy >> 2)) << 2;
        }
      }
      if (len != 0) {
        p->d.x = (p->d.x << 8) / len;
        p->d.y = (p->d.y << 8) / len;
      }
      a = p->d.y;
      {
        s32 t = a;
        if (a < 0) {
          t = -a;
        }
        if (t > 0x80) {
          if (a > 0) {
            p->d.y = 0x80;
          } else {
            p->d.y = -0x80;
          }
          if ((p->flags & 0x10) == 0) {
            p->d.x = -0xDD;
          } else {
            p->d.x = 0xDD;
          }
          a = p->d.y;
        }
      }
      {
        struct Entity* gp2 = (struct Entity*)((struct Entity*)p->unk_28)->unk_28;
        s32 dv;
        if (!((gp2->flags) & 0x10)) {
          dv = p->d.x;
          if (dv <= 0) {
            goto skipneg;
          }
          goto neg;
        }
        dv = p->d.x;
        if (dv < 0) {
        neg:
          p->d.x = -dv;
        }
      skipneg:;
      }
      p->unk_coord.x = (p->d.x * *(s32*)k8) >> 8;
      p->unk_coord.y = (a * *(s32*)k8) >> 8;
      PlaySound(0xCE);
      p->work[2] = 0x78;
      asm volatile("" ::"r"(gy));
      goto inc7;
    }
    case 8:
      SetMotion((struct Entity*)p, 0xB10D);
      p->mode[2]++;
      FALLTHROUGH;
    case 9:
      p->coord.x += p->unk_coord.x;
      p->coord.y += p->unk_coord.y;
      UpdateEntityAnim((struct Entity*)p);
      if (((p->body).status & 0x200) == 0) {
        break;
      }
      goto bump;
    case 10: {
      s32* b8b;
      SetMotion((struct Entity*)p, 0xB10F);
      SetDDP(&p->body, &sCollisions[3]);
      if (p->d.x > 0) {
        p->d.x = 0xB5;
      } else {
        p->d.x = -0xB5;
      }
      {
        u32 rv = RNG_0202f388;
        u32 r1v = (rv * 0x343FD + 0x269EC3) << 1;
        RNG_0202f388 = r1v >> 1;
        if (((r1v >> 17) & 1) != 0) {
          p->d.y = 0xB5;
          p->flags |= 0x20;
          (p->spr).yflip = 1;
          {
            register u8* oa asm("r3");
            register u32 c20 asm("r2");
            s32 ov, m21;
            oa = (u8*)p + 0x4a;
            c20 = 0x20;
            asm("" : "+r"(c20));
            ov = *oa;
            m21 = -0x21;
            m21 &= ov;
            m21 |= c20;
            *oa = m21;
          }
        } else {
          p->d.y = -0xB5;
        }
      }
      b8b = (s32*)((u8*)p + 0xb8);
      p->unk_coord.x = (p->d.x * *b8b) >> 8;
      p->unk_coord.y = (p->d.y * *b8b) >> 8;
    inc7:
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 7:
    case 11:
      p->coord.x += p->unk_coord.x;
      p->coord.y += p->unk_coord.y;
      FALLTHROUGH;
    case 1:
    case 5:
    upd:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
      bump:
        p->mode[2]++;
      }
      break;
    case 20:
      SetMotion((struct Entity*)p, 0xB102);
      p->mode[2]++;
      FALLTHROUGH;
    case 21:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
    die:
      SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
      break;
  }
}

INCASM("asm/projectile/cubit_c.inc");

void CubitProjectile_Init(Projectile* p);
void CubitProjectile_Update(Projectile* p);
void CubitProjectile_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gCubitProjectileRoutine = {
    [ENTITY_INIT] =      (void*)CubitProjectile_Init,
    [ENTITY_UPDATE] =    (void*)CubitProjectile_Update,
    [ENTITY_DIE] =       (void*)CubitProjectile_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void cubit_080a63ac(Projectile* p);
void FUN_080a6718(Projectile* p);
void FUN_080a6d3c(Projectile* p);
void cubit_080a6ed4(Projectile* p);
void cubit_080a725c(Projectile* p);
void FUN_080a7478(Projectile* p);
void FUN_080a7a70(Projectile* p);
void FUN_080a7a7c(Projectile* p);

// clang-format off
static const ProjectileFunc PTR_ARRAY_ARRAY_0836bb74[4][2] = {
    {cubit_080a63ac, FUN_080a6718},
    {FUN_080a6d3c,   cubit_080a6ed4},
    {cubit_080a725c, FUN_080a7478},
    {FUN_080a7a70,   FUN_080a7a7c},
};
// clang-format on

static const ProjectileFunc* const sUpdates[4] = {
    PTR_ARRAY_ARRAY_0836bb74[0],
    PTR_ARRAY_ARRAY_0836bb74[1],
    PTR_ARRAY_ARRAY_0836bb74[2],
    PTR_ARRAY_ARRAY_0836bb74[3],
};

// --------------------------------------------

// 0x0836BBA4
static const struct Collision sCollisions[16] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 1,
      range : {PIXEL(3), PIXEL(0), PIXEL(14), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      element : 0x02,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000004,
      range : {PIXEL(3), PIXEL(0), PIXEL(14), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 1,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(3), PIXEL(0), PIXEL(14), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      element : 0x02,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000004,
      range : {PIXEL(3), PIXEL(0), PIXEL(14), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      element : 0x02,
      nature : 0x80,
      remaining : 4,
      layer : 0x00000004,
      range : {PIXEL(2), -PIXEL(51), PIXEL(36), PIXEL(36)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      element : 0x02,
      nature : 0x80,
      remaining : 3,
      layer : 0x00000004,
      range : {-PIXEL(11), -PIXEL(41), PIXEL(36), PIXEL(36)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      element : 0x02,
      nature : 0x80,
      remaining : 2,
      layer : 0x00000004,
      range : {PIXEL(10), -PIXEL(27), PIXEL(36), PIXEL(36)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      element : 0x02,
      nature : 0x80,
      remaining : 1,
      layer : 0x00000004,
      range : {-PIXEL(10), -PIXEL(20), PIXEL(36), PIXEL(36)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      element : 0x02,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000004,
      range : {PIXEL(0), -PIXEL(8), PIXEL(36), PIXEL(36)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      element : 0x02,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000004,
      range : {PIXEL(0), -PIXEL(9), PIXEL(30), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 5,
      element : 0x02,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000004,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 5,
      element : 0x02,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000004,
      range : {PIXEL(0), -PIXEL(6), PIXEL(16), PIXEL(22)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      element : 0x02,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000004,
      range : {PIXEL(0), -PIXEL(5), PIXEL(12), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      element : 0x02,
      nature : 0x80,
      remaining : 0,
      layer : 0x00000004,
      range : {PIXEL(0), -PIXEL(6), PIXEL(16), PIXEL(22)},
    },
};

// clang-format off
// 0x0836bd24
static const Coords32 sCoords[30] = {
    {PIXEL(0), PIXEL(0)},
    {-PIXEL(13), -PIXEL(9)},
    {PIXEL(11), -PIXEL(17)},
    {-PIXEL(12), -PIXEL(28)},
    {PIXEL(0), -PIXEL(38)},
    {PIXEL(20), PIXEL(60)},
    {PIXEL(49), PIXEL(94)},
    {PIXEL(102), PIXEL(28)},
    {PIXEL(155), PIXEL(94)},
    {PIXEL(184), PIXEL(60)},
    {-PIXEL(16), -PIXEL(10)},
    {-PIXEL(25), -PIXEL(21)},
    {-PIXEL(22), -PIXEL(34)},
    {-PIXEL(12), -PIXEL(44)},
    {PIXEL(0), -PIXEL(48)},
    {PIXEL(12), -PIXEL(44)},
    {PIXEL(22), -PIXEL(34)},
    {PIXEL(25), -PIXEL(21)},
    {PIXEL(16), -PIXEL(10)},
    {-PIXEL(26), -PIXEL(36)},
    {PIXEL(26), -PIXEL(36)},
    {-PIXEL(16), -PIXEL(10)},
    {-PIXEL(25), -PIXEL(21)},
    {-PIXEL(22), -PIXEL(34)},
    {-PIXEL(12), -PIXEL(44)},
    {PIXEL(0), -PIXEL(48)},
    {PIXEL(12), -PIXEL(44)},
    {PIXEL(22), -PIXEL(34)},
    {PIXEL(25), -PIXEL(21)},
    {PIXEL(16), -PIXEL(10)},
};
// clang-format on

static const s32 s32_ARRAY_0836be14[9] = {
    0x7B, 0x7A, 0x79, 0x3F, 0x3E, 0x3D, 0x3, 0x2, 0x1,
};
