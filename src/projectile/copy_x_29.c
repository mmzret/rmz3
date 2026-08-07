#include "collision.h"
#include "global.h"
#include "projectile.h"

void CreateVFX56(struct Entity* e, u8 kind1, u8 kind2);

// CopyX (Reflect Laser?)

NON_MATCH void Projectile29_Init(Projectile* p);
void Projectile29_Update(Projectile* p);
static void Projectile29_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile29Routine = {
    [ENTITY_INIT] =      (void*)Projectile29_Init,
    [ENTITY_UPDATE] =    (void*)Projectile29_Update,
    [ENTITY_DIE] =       (void*)Projectile29_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void copyx_080aa24c(Entity* q, u8 kind1, u8 kind2) {
  Projectile* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 29);
    p->unk_28 = q;
    p->work[0] = kind1, p->work[1] = kind2;
  }
}

NON_MATCH void Projectile29_Init(Projectile* p) {
#if MODERN
  struct Entity* pa = p->unk_28;
  u32 xf;
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  InitNonAffineMotion((struct Entity*)p);
  p->flags |= 3;
  SetMotion((struct Entity*)p, 0x6000);
  xf = ((pa->flags) >> 4) & 1;
  if (xf) {
    p->flags |= 0x10;
  } else {
    p->flags &= 0xEF;
  }
  (p->spr).xflip = xf;
  *((u8*)p + 0x4a) = (*((u8*)p + 0x4a) & ~0x11) | (xf << 4);
  p->flags |= 4;
  {
    struct Body* body = &p->body;
    InitBody(body, sCollisions, &p->coord, 0x40);
    body->parent = (struct Entity*)p;
    body->fn = NULL;
  }
  *((u8*)p + 0x49) = (*((u8*)p + 0x49) & ~0xD) | 4;
  if (p->work[0] == 0) {
    if (p->flags & 0x10) {
      p->coord.x = (pa->coord).x + 0x1500;
      p->d.x = 0x500;
    } else {
      p->coord.x = (pa->coord).x - 0x1500;
      p->d.x = -0x500;
    }
    p->coord.y = (pa->coord).y - 0x1700;
    p->d.y = 0;
  } else {
    u8* ang = (u8*)p + 0xc0;
    if (p->flags & 0x10) {
      p->coord.x = (pa->coord).x + 0x1100;
      *ang = 0x20;
    } else {
      p->coord.x = (pa->coord).x - 0x1100;
      *ang = 0x60;
    }
    p->coord.y = (pa->coord).y - 0xE00;
    p->d.x = gSineTable[(u8)(*ang + 0x40)] * 5;
    p->d.y = gSineTable[*ang] * 5;
  }
  p->work[2] = 0x14;
  p->work[3] = 0;
  Projectile29_Update(p);
#else
  INCCODE("asm/projectile/unk_29_init.inc");
#endif
}

void Projectile29_Update(Projectile* p) {
  register struct Entity* q asm("r5");
  q = p->unk_28;
  UpdateEntityAnim((struct Entity*)p);
  if (p->mode[1] != 0) {
    if ((u8)++p->work[2] > 2) {
      CreateVFX56((struct Entity*)p, 0, 0);
      p->work[2] = 0;
    }
  }
  switch (p->mode[1]) {
    case 0:
      if ((u8)--p->work[2] == 0xff) {
        PlaySound(0x4d);
        {
          register s32 mv asm("r0");
          register s32 w0 asm("r1");
          mv = p->mode[1];
          mv += 1;
          w0 = p->work[0];
          mv += w0;
          p->mode[1] = mv;
        }
        break;
      }
      if (p->work[0] == 0) {
        register s32 mo asm("r0");
        register s32 k asm("r1");
        mo = *((u8*)q + 0x1e) << 8;
        {
          register u8* mp asm("r1");
          mp = (u8*)q + 0x70;
          k = *mp;
        }
        mo |= k;
        k = 0xB31B;
        if (mo == k) {
          break;
        }
        PlaySound(0x4d);
        goto bump;
      } else {
        register s32 mo2 asm("r0");
        register s32 k2 asm("r1");
        mo2 = *((u8*)q + 0x1e) << 8;
        {
          register u8* mp2 asm("r1");
          mp2 = (u8*)q + 0x70;
          k2 = *mp2;
        }
        mo2 |= k2;
        k2 = 0xB31C;
        if (mo2 == k2) {
          break;
        }
        PlaySound(0x4d);
        p->mode[1] += 2;
        break;
      }
    case 1: {
      register s32 dx asm("r1");
      register s32 cx asm("r0");
      cx = p->coord.x;
      dx = p->d.x;
      cx += dx;
      p->coord.x = cx;
      dx = p->coord.y;
      if ((u16)FUN_080098a4(cx, dx) == 0) {
        break;
      }
      cx = p->coord.x;
      dx = p->d.x;
      cx -= dx;
      p->coord.x = cx;
      {
        register u8* ap asm("r1");
        register s32 a asm("r0");
        if (dx < 0) {
          ap = (u8*)p + 0xc0;
          a = 0x20;
        } else {
          ap = (u8*)p + 0xc0;
          a = 0x60;
        }
        *ap = a;
        {
          register u8* ap2 asm("r3");
          register const s16* tb asm("r2");
          register s32 t asm("r0");
          register s32 sv asm("r1");
          ap2 = ap;
          tb = gSineTable;
          t = *ap2;
          t += 0x40;
          t <<= 24;
          t = ((u32)t) >> 23;
          t += (s32)tb;
          {
            register s32 zi asm("r5");
            zi = 0;
            sv = *(const s16*)(t + zi);
          }
          t = sv << 2;
          t += sv;
          p->d.x = t;
          t = *ap2;
          t <<= 1;
          t += (s32)tb;
          {
            register s32 zi2 asm("r2");
            zi2 = 0;
            sv = *(const s16*)(t + zi2);
          }
          t = sv << 2;
          t += sv;
          p->d.y = t;
        }
      }
      p->work[3]++;
    bump:
      p->mode[1]++;
      break;
    }
    case 2: {
      register s32 dx2 asm("r1");
      register s32 cx2 asm("r0");
      cx2 = p->coord.x;
      dx2 = p->d.x;
      cx2 += dx2;
      p->coord.x = cx2;
      dx2 = p->coord.y;
      if ((u16)FUN_080098a4(cx2, dx2) != 0) {
        cx2 = p->coord.x;
        dx2 = p->d.x;
        cx2 -= dx2;
        p->coord.x = cx2;
        dx2 = -dx2;
        p->d.x = dx2;
        goto hit;
      }
      {
        register s32 cy asm("r1");
        register s32 dy asm("r0");
        cy = p->coord.y;
        dy = p->d.y;
        cy += dy;
        p->coord.y = cy;
        if ((u16)FUN_080098a4(p->coord.x, cy) == 0) {
          break;
        }
        {
          register s32 cy2 asm("r0");
          register s32 dy2 asm("r1");
          cy2 = p->coord.y;
          dy2 = p->d.y;
          cy2 -= dy2;
          p->coord.y = cy2;
          dy2 = -dy2;
          p->d.y = dy2;
        }
      }
    hit:
      p->work[3]++;
      break;
    }
  }
  if (p->work[3] > 2) {
    CreateVFX56((struct Entity*)p, 1, 0);
    CreateVFX56((struct Entity*)p, 1, 0x20);
    CreateVFX56((struct Entity*)p, 1, 0x40);
    CreateVFX56((struct Entity*)p, 1, 0x60);
    CreateVFX56((struct Entity*)p, 1, 0x80);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
    Projectile29_Die(p);
  }
}

static void Projectile29_Die(Projectile* p) {
  p->flags &= ~DISPLAY;
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

// 0x0836C2A0
static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 5,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 5,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
};
