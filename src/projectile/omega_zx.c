#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "camera.h"
#include "physics.h"
#include "physics.h"
#include "stagerun.h"
#include "zero.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 unk_b4[16];         // 0xB4
} OmegaZXProjectile;
static_assert(sizeof(OmegaZXProjectile) == sizeof(Projectile));

void OmegaZXProjectile_Init(OmegaZXProjectile* p);
void OmegaZXProjectile_Update(OmegaZXProjectile* p);
void OmegaZXProjectile_Die(OmegaZXProjectile* p);

// clang-format off
const ProjectileRoutine gOmegaZXProjectileRoutine = {
    [ENTITY_INIT] =      (void*)OmegaZXProjectile_Init,
    [ENTITY_UPDATE] =    (void*)OmegaZXProjectile_Update,
    [ENTITY_DIE] =       (void*)OmegaZXProjectile_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

Projectile* FUN_080afe84(Entity* parent, Coords32* c, u8 n) {
  Projectile* p = (Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 41);
    p->work[0] = 0, p->work[1] = n;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->unk_28 = parent;
  }
  return p;
}

Projectile* FUN_080afedc(Entity* parent, Coords32* c, u8 n) {
  Projectile* p = (Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 41);
    p->work[0] = n;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->unk_28 = parent;
  }
  return p;
}

Projectile* FUN_080aff34(Entity* parent, Coords32* c) {
  Projectile* p = (Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 41);
    p->work[0] = 4;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->unk_28 = parent;
  }
  return p;
}

Projectile* FUN_080aff88(Entity* parent, Coords32* c, u8 n) {
  Projectile* p = (Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 41);
    p->work[0] = 5, p->work[1] = n;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->unk_28 = parent;
  }
  return p;
}

INCASM("asm/projectile/omega_zx_a.inc");

void omega2_080b0370(OmegaZXProjectile* p0) {
  OmegaZXProjectile* p = p0;
  s32 vv[2];
  register s32 z asm("r6");
  if (p->mode[2] <= 9) {
    if ((p->unk_28)->mode[0] > 1) {
      p->mode[2] = 0xA;
    }
  }
  switch (p->mode[2]) {
    case 0: {
      EnableSpriteAnimation_Normal(p);
      SetSpriteTableDynamic(p);
      {
        u32 va = p->flags;
        u32 fv = 2;
        z = 0;
        fv |= va;
        fv |= 1;
        fv |= 4;
        p->flags = fv;
      }
      {
        struct Body* b = &p->body;
        const struct Collision* col = (const struct Collision*)0x0836D63C;
        struct Coord* c = &p->coord;
        InitBody(b, col, c, 2);
        b->parent = (struct Entity*)p;
        b->fn = (BodyFunc)z;
        *((u8*)p + 0x25) = 0x11;
        SetSpriteAnimation(p, 0xB901);
        FUN_080afedc((struct Entity*)p, c, 2);
      }
      PlaySound(0x99 << 1);
      {
        struct Entity* e = p->unk_28;
        s32 sx = e->coord.x + p->coord.x;
        s32 sy;
        p->unk_coord.x = sx;
        p->coord.x = sx;
        sy = e->coord.y + p->coord.y;
        p->unk_coord.y = sy;
        p->coord.y = sy;
      }
      p->work[2] = 0xFF;
      {
        u32 o1;
        asm("mov %0, #1" : "=r"(o1));
        p->work[3] = o1;
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      u32 w3 = p->work[3];
      if (w3 != 0) {
        w3--;
        p->work[3] = w3;
        if ((w3 << 24) == 0) {
          struct Zero* zz = pZero2;
          register s32 t asm("r0");
          vv[0] = (zz->s).coord.x - p->coord.x;
          {
            s32 py = p->coord.y + (0xA0 << 3);
            vv[1] = (zz->s).coord.y - py;
          }
          if (vv[0] != 0 || vv[1] != 0) {
            register s32 acc asm("r0");
            s32 d4;
            asm volatile("" ::: "memory");
            {
              register s32 q0 asm("r1");
              q0 = vv[0];
              acc = q0 * q0;
            }
            asm("" : "+r"(acc));
            {
              register s32 q1 asm("r2");
              register s32 sq asm("r1");
              q1 = vv[1];
              sq = q1 * q1;
              acc += sq;
            }
            d4 = Sqrt(acc);
            {
              register s32 l0 asm("r3");
              l0 = vv[0];
              vv[0] = (l0 << 8) / d4;
            }
            {
              register s32 l1 asm("r1");
              l1 = vv[1];
              t = (l1 << 8) / d4;
            }
          } else {
            t = 0x80 << 1;
            vv[0] = t;
          }
          vv[1] = t;
          asm volatile("" ::: "memory");
          {
            register s32 l2 asm("r2");
            l2 = vv[0];
            p->d.x = ((l2 * 5) << 6) >> 8;
          }
          {
            s32 m;
            register s32 sv asm("r3");
            sv = vv[1];
            if (sv < 0) {
              m = sv * 3;
            } else {
              register s32 pv asm("r1");
              pv = *(volatile s32*)&vv[1];
              m = pv * 5;
            }
            p->d.y = (m << 6) >> 8;
          }
          p->work[3] = 0x18;
        }
      }
      if (!((pZero2->s).flags & 1)) {
        p->work[3] = 0x18;
      }
      p->coord.x += p->d.x;
      p->coord.y += p->d.y;
      UpdateEntityAnim((struct Entity*)p);
      if ((p->body).status & 0x800) {
        p->mode[2]++;
        break;
      }
      {
        u32 w2a = p->work[2];
        if (w2a != 0) {
          w2a--;
          p->work[2] = w2a;
          if ((w2a << 24) != 0) {
            break;
          }
        }
      }
      p->mode[2] = 0xA;
      break;
    }
    case 2: {
      s32 dx4;
      s32 dy5;
      z = 0;
      {
        register s32 t1 asm("r1");
        register s32 t2 asm("r2");
        t1 = p->unk_coord.x;
        t1 -= p->coord.x;
        asm("" : "+r"(t1));
        dx4 = t1;
        t2 = p->unk_coord.y;
        t2 -= p->coord.y;
        asm("" : "+r"(t2));
        dy5 = t2;
        if (t1 != 0 || t2 != 0) {
          z = Sqrt(dx4 * dx4 + dy5 * dy5);
          dx4 = (dx4 << 8) / z;
          dy5 = (dy5 << 8) / z;
        } else {
          dx4 = 0x80 << 1;
        }
      }
      p->d.x = (dx4 << 8) >> 8;
      p->d.y = (dy5 << 8) >> 8;
      p->unk_coord.x = z;
      p->unk_coord.y = 0x80 << 1;
      {
        register s32* w asm("r3");
        register struct Zero* zz asm("r2");
        w = (s32*)((u8*)p + 0xb4);
        zz = pZero2;
        *w = (zz->s).coord.x - p->coord.x;
        asm("" : "+r"(w));
        w++;
        *w = (zz->s).coord.y - p->coord.y;
        asm volatile("" ::"r"(w));
      }
      SetDDP(&p->body, (const struct Collision*)0x0836D654);
      p->work[2] = 0x3C;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 3: {
      s32 nx3;
      {
        s32 ny;
        struct Camera* cam3;
        nx3 = p->coord.x + p->d.x;
        p->coord.x = nx3;
        ny = p->coord.y + p->d.y;
        p->coord.y = ny;
        cam3 = &gStageRun.vm.camera;
        if (ny < cam3->viewport.y + 0x27FF) {
          s32* w = (s32*)((u8*)p + 0xb4);
          s32 v = *w;
          v += ((-v) << 4) >> 8;
          *w = v;
          {
            s32* w2 = (s32*)((u8*)p + 0xb8);
            s32 u = *w2;
            u += (((0x80 << 5) - u) << 4) >> 8;
            *w2 = u;
            {
              struct Zero* zz = pZero2;
              (zz->s).coord.x = p->coord.x + *w;
              (zz->s).coord.y = p->coord.y + *w2;
            }
          }
        } else {
          struct Zero* zz2 = pZero2;
          (zz2->s).coord.x = nx3 + *(s32*)((u8*)p + 0xb4);
          {
            s32* w2p = (s32*)((u8*)p + 0xb8);
            (zz2->s).coord.y = p->coord.y + *w2p;
          }
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      {
        s32 rem = p->unk_coord.x - p->unk_coord.y;
        p->unk_coord.x = rem;
        if (rem <= 0) {
          SetDDP(&p->body, (const struct Collision*)0x0836D66C);
          p->mode[2]++;
        }
      }
      {
        u32 w2c = p->work[2];
        if (w2c != 0) {
          w2c--;
          p->work[2] = w2c;
          if ((w2c << 24) != 0) {
            break;
          }
        }
      }
      goto tail4;
    }
    case 4: {
      s32* w = (s32*)((u8*)p + 0xb4);
      s32 v = *w;
      v += ((-v) << 4) >> 8;
      *w = v;
      {
        s32* w2 = (s32*)((u8*)p + 0xb8);
        s32 u = *w2;
        u += (((0x80 << 5) - u) << 4) >> 8;
        *w2 = u;
        {
          struct Zero* zz = pZero2;
          (zz->s).coord.x = p->coord.x + *w;
          (zz->s).coord.y = p->coord.y + *w2;
        }
      }
      UpdateEntityAnim((struct Entity*)p);
    tail4:
      if (!((p->body).status & 0x800)) {
        p->mode[2] = 0xF;
      }
      break;
    }
    case 10:
      p->work[2] = 0x1A;
      p->mode[2]++;
      FALLTHROUGH;
    case 11: {
      p->coord.x += p->d.x;
      p->coord.y += p->d.y;
      UpdateEntityAnim((struct Entity*)p);
      if ((p->body).status & 0x800) {
        p->mode[2] = 2;
        break;
      }
      {
        struct Camera* cam = &gStageRun.vm.camera;
        if (Camera_GetDistance(cam, &p->coord) == 0) {
          break;
        }
      }
      {
        u32 w2b = p->work[2];
        if (w2b == 0) {
          goto die;
        }
        w2b--;
        p->work[2] = w2b;
        if ((w2b << 24) != 0) {
          break;
        }
      }
      goto die;
    }
    case 15:
      EXIT_BODY(p);
      p->work[2] = 0x1E;
      p->mode[2]++;
      FALLTHROUGH;
    case 16: {
      register u32 fl asm("r0");
      u32 w2v;
      UpdateEntityAnim((struct Entity*)p);
      {
        u32 td = p->work[2];
        if (td != 0) {
          td--;
          p->work[2] = td;
        }
      }
      {
        u32 lv = p->work[2];
        s32 t1 = 1;
        t1 &= lv;
        w2v = lv;
        asm("" : "+r"(w2v));
        if (t1 != 0) {
          u32 va2 = p->flags;
          fl = 1;
          fl |= va2;
        } else {
          u32 vb2 = p->flags;
          fl = 0xFE;
          fl &= vb2;
        }
        p->flags = fl;
        if ((w2v << 24) != 0) {
          break;
        }
      }
    die:
      SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
      break;
    }
  }
}

void omega2_080b07c8(OmegaZXProjectile* p0) {
  register OmegaZXProjectile* p asm("r6");
  register s32 nx asm("r0");
  register s32 lim asm("r1");
  struct Coord* cc;
  u32 z;
  p = p0;
  switch (p->mode[2]) {
    case 0: {
      InitNonAffineMotion((struct Entity*)p);
      ResetDynamicMotion((struct Entity*)p);
      {
        u32 va = p->flags;
        u32 fv = 2;
        asm volatile("mov %0, #0" : "=r"(z));
        fv |= va;
        fv |= 1;
        fv |= 4;
        p->flags = fv;
      }
      {
        struct Body* body = &p->body;
        InitBody(body, (const struct Collision*)0x0836D69C, &p->coord, 2);
        body->parent = (struct Entity*)p;
        body->fn = (BodyFunc)z;
      }
      *((u8*)p + 0x25) = 7;
      SetMotion((struct Entity*)p, 0xBA00);
      PlaySound(0x133);
      p->unk_coord.x = z;
      p->d.x = -0x300;
      p->work[2] = 0xFF;
      p->work[3] = z;
      p->work[1] = z;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      u32 k4;
      register u32 one asm("r5");
      asm volatile("mov %0, #0" : "=r"(k4));
      UpdateEntityAnim((struct Entity*)p);
      {
        u32 s0 = (p->body).status;
        one = 1;
        if (s0 & one) {
          p->mode[2] = 0xA;
          break;
        }
      }
      {
        register struct Zero** pz asm("r2");
        register struct Zero* zz asm("r3");
        u32 fv0;
        pz = &pZero2;
        zz = *pz;
        fv0 = (zz->s).flags;
        {
          register u32 t0 asm("r0");
          asm("add %0, %1, #0" : "=r"(t0) : "r"(one));
          t0 &= fv0;
          if (t0 == 0) {
            p->mode[3] = k4;
            p->mode[2]++;
            goto vel1;
          }
        }
        {
          register s32 cx asm("r4");
          register s32 dx asm("r3");
          s32 cx0;
          s32 zzx;
          cx0 = p->coord.x;
          zzx = (zz->s).coord.x;
          dx = cx0 - zzx;
          cx = cx0;
          asm volatile("" ::"r"(cx0));
          if (dx > 0) {
            if (dx > 0x1000) {
              goto far1;
            }
            goto near1;
          }
          if (zzx - cx > 0x1000) {
          far1:
            if (p->work[3] == 0) {
              struct Zero* z4 = *(struct Zero* volatile*)pz;
              if (cx > (z4->s).coord.x) {
                register s32 r asm("r2");
                p->coord.x = cx + -0x300;
                r = PushoutToRight1(cx + -0xB00, p->coord.y);
                if (r != 0) {
                  p->coord.x += r;
                  p->mode[2]++;
                  p->mode[3] = 1;
                }
              } else {
                s32 c3 = 0xC0 << 2;
                p->coord.x = cx + c3;
                asm volatile("" ::"r"(cx));
              }
              k4 = 0xC0 << 2;
              p->unk_coord.y = 0;
              goto setdx1;
            }
          }
        near1:
          {
            s32 oy;
            s32 r2;
            p->work[3] = 1;
            oy = p->coord.y;
            p->coord.y = oy + 0x200;
            r2 = PushoutToUp1(cx, oy + 0xA00);
            if (r2 != 0) {
              p->coord.y += r2;
              p->mode[3] = 0;
              p->mode[2]++;
            } else {
              s32 n68 = p->unk_coord.y + 0x200;
              p->unk_coord.y = n68;
              if (n68 > 0x2FFF) {
                p->work[3] = r2;
              }
            }
          }
          k4 = 0x80 << 2;
        setdx1:
          p->d.x = k4;
        }
      }
    vel1:
      nx = p->unk_coord.x;
      nx += p->d.x;
      p->unk_coord.x = nx;
      lim = 0xEFF;
      goto chk;
    }
    case 2: {
      struct Zero* z2 = pZero2;
      if ((z2->s).flags & 1) {
        if (p->coord.x > (z2->s).coord.x) {
          p->d.x = -0x300;
        } else {
          p->d.x = 0xC0 << 2;
        }
      }
      p->work[2] = 0x3C;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 3: {
      register u32 k5 asm("r5");
      asm volatile("mov %0, #0" : "=r"(k5));
      UpdateEntityAnim((struct Entity*)p);
      if (!((pZero2->s).flags & 1)) {
        p->coord.x += p->d.x;
      k5set:
        k5 = 0xC0 << 2;
        goto joined3;
      }
      {
        s32 dv = p->d.x;
        if (dv < 0) {
          s32 r3;
          p->coord.x += dv;
          r3 = PushoutToRight1(p->coord.x + -0x800, p->coord.y);
          if (r3 == 0) {
            goto k5set;
          }
          p->coord.x += r3;
          goto lift3;
        }
        {
          u32 m3 = p->mode[3];
          if (m3 == 0) {
            s32 rv;
            p->coord.x += dv;
            rv = FUN_08009f6c(p->coord.x + -0x800, p->coord.y);
            {
              register s32 yy asm("r1");
              asm("add %0, %1, #0" : "=r"(yy) : "r"(rv));
              if (yy == p->coord.y + (0x80 << 4)) {
                goto k5set;
              }
            }
            p->mode[3]++;
            goto k5set;
          }
          if (m3 != 1) {
            goto joined3;
          }
        }
      lift3:
        {
          s32 cy3 = p->coord.y;
          register s32 t3 asm("r1");
          t3 = 0x80 << 2;
          asm("" : "+r"(t3));
          p->coord.y = cy3 + t3;
          k5 = t3;
        }
      }
    joined3:
      {
        struct Camera* cam = &gStageRun.vm.camera;
        cc = &p->coord;
        if (Camera_GetDistance(cam, cc) != 0) {
        u32 w2 = p->work[2];
        if (w2 != 0) {
          w2--;
          p->work[2] = w2;
          if ((w2 << 24) != 0) {
            goto vel3;
          }
        }
        p->mode[2]++;
        }
      }
    vel3:
      {
        s32 n5 = p->unk_coord.x + k5;
        p->unk_coord.x = n5;
        if (n5 > 0xEFF) {
          FUN_080aff88((struct Entity*)p, cc, p->work[1]);
          p->unk_coord.x = 0;
          p->work[1]++;
        }
      }
      break;
    }
    case 10:
      p->unk_coord.y = p->coord.y + (0x80 << 5);
      p->mode[2]++;
      FALLTHROUGH;
    case 11: {
      s32 cy2 = p->coord.y;
      s32 base;
      s32 u68;
      s32 t;
      s32 r4;
      base = cy2 + -0x400;
      u68 = p->unk_coord.y;
      t = u68 - base;
      cy2 += (t * 3 * 8) >> 8;
      p->coord.y = cy2;
      if (cy2 > u68) {
        p->mode[2] = 1;
      }
      r4 = PushoutToUp1(p->coord.x, p->coord.y + (0x80 << 4));
      if (r4 != 0) {
        p->coord.y += r4;
        p->mode[2] = 2;
      }
      nx = p->unk_coord.x + (0xC0 << 2);
      p->unk_coord.x = nx;
      lim = 0xFFF;
    chk:
      if (nx > lim) {
        FUN_080aff88((struct Entity*)p, &p->coord, p->work[1]);
        p->unk_coord.x = 0;
        p->work[1]++;
      }
      break;
    }
    case 20:
      EXIT_BODY(p);
      p->work[2] = 0x1E;
      SetMotion((struct Entity*)p, 0xBA01);
      p->mode[2]++;
      FALLTHROUGH;
    case 21: {
      register u32 fl asm("r0");
      u32 w1 = p->work[2];
      s32 t1 = 1;
      t1 &= w1;
      if (t1 != 0) {
        u32 va2 = p->flags;
        fl = 1;
        fl |= va2;
      } else {
        u32 vb2 = p->flags;
        fl = 0xFE;
        fl &= vb2;
      }
      p->flags = fl;
      UpdateEntityAnim((struct Entity*)p);
      {
        s32 t2 = p->work[2];
        if (t2 != 0) {
          t2--;
          p->work[2] = t2;
          if ((t2 << 24) != 0) {
            break;
          }
        }
      }
      FALLTHROUGH;
    }
    case 4:
      SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
      break;
  }
}

INCASM("asm/projectile/omega_zx_b.inc");

void FUN_080b0168(OmegaZXProjectile* p);
void FUN_080b0214(OmegaZXProjectile* p);
void FUN_080b02dc(OmegaZXProjectile* p);
void omega2_080b0370(OmegaZXProjectile* p);
void omega2_080b07c8(OmegaZXProjectile* p);
void FUN_080b0bb0(OmegaZXProjectile* p);
void omega2_080b0ca8(OmegaZXProjectile* p);
void FUN_080b10b8(OmegaZXProjectile* p);
void FUN_080b116c(OmegaZXProjectile* p);

// clang-format off
static void (*const sUpdates[9])(OmegaZXProjectile*) = {
    FUN_080b0168,
    FUN_080b0214,
    FUN_080b02dc,
    omega2_080b0370,
    omega2_080b07c8,
    FUN_080b0bb0,
    omega2_080b0ca8,
    FUN_080b10b8,
    FUN_080b116c,
};
// clang-format on

static const struct Collision sCollisions[26] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(30)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(28)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(26)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(22)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(12)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(10)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(6)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(4)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(2)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(8), PIXEL(8), PIXEL(1)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      nature : BODY_NATURE_B7,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(34), PIXEL(34)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 255,
      unk_0a : 0x21,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(30), PIXEL(30)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 255,
      unk_0a : 0x21,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(48), PIXEL(48)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      unk_0a : 0x21,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(48), PIXEL(48)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(35), -PIXEL(86), PIXEL(40), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      nature : BODY_NATURE_B7,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      nature : BODY_NATURE_B7,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 5,
      nature : BODY_NATURE_B7,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(6), PIXEL(50), PIXEL(27)},
    },
};
