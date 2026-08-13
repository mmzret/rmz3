#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "physics.h"
#include "physics.h"
#include "physics.h"

void TretistaProjectile_Init(Projectile* p);
void TretistaProjectile_Update(Projectile* p);
void TretistaProjectile_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gTretistaProjectileRoutine = {
    [ENTITY_INIT] =      (void*)TretistaProjectile_Init,
    [ENTITY_UPDATE] =    (void*)TretistaProjectile_Update,
    [ENTITY_DIE] =       (void*)TretistaProjectile_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

Entity* createTretistaBreathGas(Entity* e, Coords32* c, u8 kind) {
  Entity* p = (Entity*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 19);
    p->work[0] = 0, p->work[1] = kind;
    (p->coord) = *c;
    p->unk_28 = (void*)e;
  }
  return p;
}

INCASM("asm/projectile/tretista_a.inc");

void FUN_080a38e8(Projectile* p0) {
  register struct Projectile* p asm("r4");
  p = p0;
  if ((p->unk_28)->mode[0] > 1) {
    if (p->mode[2] <= 0xB) {
      p->mode[2] = 0xC;
    }
  }
  {
    struct Entity* q2;
    u32 m1v;
    {
      struct Entity* a0 = p->unk_28;
      m1v = a0->mode[1];
      q2 = a0;
      asm("" : "+r"(q2));
    }
    if (m1v == 0xA) {
      if (p->mode[2] <= 0xB) {
        p->mode[2] = 0xC;
      }
    }
    if (q2->mode[1] != 8) {
      if (p->mode[2] <= 0xB) {
        p->mode[2] = 0xC;
      }
    }
  }
  switch (p->mode[2]) {
    case 0: {
      u32 w1 = p->work[1];
      if (w1 == 0) {
        p->work[2] = 0x28;
        {
          s32 dd = -0x3200;
          asm("" : "+r"(dd));
          p->d.x = dd / 0x28;
        }
        {
          s32 dd2 = 0xE1 << 7;
          asm(" " : "+r"(dd2));
          p->d.y = -(dd2 / 0x28);
        }
        p->work[2] = 0x27;
        p->mode[2]++;
      } else if (w1 == 1) {
        p->work[2] = 0x28;
        {
          s32 dd3 = 0xC8 << 6;
          asm("  " : "+r"(dd3));
          p->d.x = dd3 / 0x28;
        }
        {
          s32 dd4 = 0xE1 << 7;
          asm("   " : "+r"(dd4));
          p->d.y = -(dd4 / 0x28);
        }
        p->work[2] = 0x27;
        p->mode[2]++;
      } else if (w1 == 2) {
        p->d.y = 0;
        p->d.x = -0x200;
        p->mode[2] = 0xA;
      } else if (w1 == 3) {
        p->d.y = 0;
        p->d.x = 0x80 << 2;
        p->mode[2] = 0xA;
      }
      SetMotion((struct Entity*)p, 0xAE << 8);
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
    case 1: {
      register s32 k5 asm("r5");
      {
        s32 dy = p->d.y + 0x24;
        p->d.y = dy;
        p->coord.x += p->d.x;
        p->coord.y += dy;
      }
      UpdateEntityAnim((struct Entity*)p);
      {
        s32 cx1 = p->coord.x;
        s32 cy1 = p->coord.y;
        k5 = 0xC0 << 4;
        if (PushoutToUp1(cx1, cy1 + k5) == 0) {
          goto slide1;
        }
      }
      {
        if (p->d.x > 0) {
          p->d.x = 0x80 << 2;
        } else {
          p->d.x = -0x200;
        }
        p->mode[2]++;
        break;
      }
    slide1:
      {
        s32 r;
        if (p->d.x < 0) {
          s32 xx = p->coord.x;
          s32 oa = -0xC00;
          asm("" : "+r"(oa));
          xx += oa;
          {
            s32 yy2 = p->coord.y;
            s32 ob = -0xC00;
            asm(" " : "+r"(ob));
            r = PushoutToRight1(xx, yy2 + ob);
          }
        } else {
          r = PushoutToLeft1(p->coord.x + k5, p->coord.y + -0xC00);
        }
        if (r == 0) {
          break;
        }
      }
      p->d.y = 0;
      p->mode[2] = 3;
      break;
    }
    case 2: {
      p->coord.x += p->d.x;
      UpdateEntityAnim((struct Entity*)p);
      if (p->d.x < 0) {
        if (PushoutToRight1(p->coord.x + -0xC00, p->coord.y + -0xC00) == 0) {
          break;
        }
        p->mode[2]++;
        break;
      }
      if (PushoutToLeft1(p->coord.x + (0xC0 << 4), p->coord.y + -0xC00) == 0) {
        break;
      }
      p->mode[2]++;
      break;
    }
    case 3: {
      register s32 z3 asm("r3");
      register s32 z2c asm("r2");
      u32 k1 = 0x80 << 1;
      p->unk_coord.x = k1;
      {
        u16* mg = (u16*)((u8*)p + 0x50);
        z3 = 0;
        z2c = 0;
        *mg = k1;
      }
      {
        register s32 v3 asm("r0");
        register u16* a52 asm("r1");
        v3 = *(volatile s32*)&p->unk_coord.x;
        a52 = (u16*)((u8*)p + 0x52);
        *a52 = v3;
      }
      {
        u32* st8 = (u32*)((u8*)p + 0x8c);
        *st8 = z2c;
        *(u32*)((u8*)p + 0x90) = z2c;
        *((u8*)p + 0x94) = z3;
      }
      p->flags &= 0xFB;
      p->work[2] = 0x1E;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 4: {
      UpdateEntityAnim((struct Entity*)p);
      {
        s32 u = p->unk_coord.x;
        u += ((-u) << 5) >> 8;
        p->unk_coord.x = u;
      }
      {
        s32 dy4 = p->d.y + 0x24;
        s32 ny4;
        s32 r4v;
        p->d.y = dy4;
        ny4 = p->coord.y + dy4;
        p->coord.y = ny4;
        r4v = PushoutToUp1(p->coord.x, ny4 + (0xC0 << 4));
        if (r4v != 0) {
          p->coord.y += r4v;
        }
      }
      {
        register u16* mg4 asm("r1");
        s32 v0 = p->unk_coord.x;
        mg4 = (u16*)((u8*)p + 0x50);
        *mg4 = v0;
        {
          s32 v1 = *(volatile s32*)&p->unk_coord.x;
          mg4 += 1;
          asm("" : "+r"(mg4));
          *mg4 = v1;
        }
      }
      {
        u32 w2 = p->work[2];
        if (w2 != 0) {
          p->work[2] = w2 - 1;
        }
      }
      {
        register u32 fl asm("r0");
        register u32 w2v4 asm("r2");
        {
          register u32 lv asm("r1");
          s32 t1;
          lv = p->work[2];
          t1 = 1;
          t1 &= lv;
          w2v4 = lv;
          asm("" : "+r"(w2v4));
          if (t1 == 0) {
            goto blinkelse;
          }
          {
            u32 va2 = p->flags;
            fl = 1;
            fl |= va2;
          }
          asm("" ::"r"(fl), "r"(w2v4));
          goto blinkstore;
        }
      }
    }
    case 10: {
      s32 dy10 = p->d.y + 0x24;
      p->d.y = dy10;
      p->coord.y += dy10;
      UpdateEntityAnim((struct Entity*)p);
      if (PushoutToUp1(p->coord.x, p->coord.y + (0xC0 << 4)) == 0) {
        break;
      }
      p->mode[2]++;
      break;
    }
    case 11: {
      p->coord.x += p->d.x;
      UpdateEntityAnim((struct Entity*)p);
      if (p->d.x < 0) {
        if (PushoutToRight1(p->coord.x + -0xC00, p->coord.y + -0xC00) == 0) {
          break;
        }
        p->mode[2]++;
        break;
      }
      if (PushoutToLeft1(p->coord.x + (0xC0 << 4), p->coord.y + -0xC00) == 0) {
        break;
      }
      p->mode[2]++;
      break;
    }
    case 12: {
      register s32 z3b asm("r3");
      register s32 z2d asm("r2");
      u32 k1b = 0x80 << 1;
      p->unk_coord.x = k1b;
      {
        u16* mgb = (u16*)((u8*)p + 0x50);
        z3b = 0;
        z2d = 0;
        *mgb = k1b;
      }
      {
        register s32 v12 asm("r0");
        register u16* a52b asm("r1");
        v12 = *(volatile s32*)&p->unk_coord.x;
        a52b = (u16*)((u8*)p + 0x52);
        *a52b = v12;
      }
      {
        u32* st8b = (u32*)((u8*)p + 0x8c);
        *st8b = z2d;
        *(u32*)((u8*)p + 0x90) = z2d;
        *((u8*)p + 0x94) = z3b;
      }
      p->flags &= 0xFB;
      p->work[2] = 0x1E;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 13: {
      UpdateEntityAnim((struct Entity*)p);
      {
        register s32 u13 asm("r1");
        u13 = p->unk_coord.x;
        u13 += ((-u13) << 5) >> 8;
        p->unk_coord.x = u13;
        *(u16*)((u8*)p + 0x50) = u13;
      }
      {
        register s32 v13 asm("r0");
        register u16* a52c asm("r1");
        v13 = *(volatile s32*)&p->unk_coord.x;
        a52c = (u16*)((u8*)p + 0x52);
        *a52c = v13;
      }
      {
        u32 w2b = p->work[2];
        if (w2b != 0) {
          p->work[2] = w2b - 1;
        }
      }
      {
        register u32 fl2 asm("r0");
        register u32 w2c asm("r2");
        {
          register u32 lv2 asm("r1");
          s32 t1b;
          lv2 = p->work[2];
          t1b = 1;
          t1b &= lv2;
          w2c = lv2;
          asm(" " : "+r"(w2c));
          if (t1b != 0) {
            u32 va3 = p->flags;
            fl2 = 1;
            fl2 |= va3;
          } else {
          blinkelse:
            asm("" : "=r"(fl2), "=r"(w2c));
            {
              u32 vb3 = p->flags;
              fl2 = 0xFE;
              fl2 &= vb3;
            }
          }
        blinkstore:
          asm("" : "+r"(fl2), "+r"(w2c));
          p->flags = fl2;
          if (w2c != 0) {
            break;
          }
        }
      }
      SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
      break;
    }
  }
}

INCASM("asm/projectile/tretista_b.inc");

void FUN_080a4d0c(Projectile* p) {
  struct Entity* e = p->unk_28;
  if (e->mode[0] > 1) {
    goto die;
  }
  if (e->mode[1] == 0xA) {
    goto die;
  }
  switch (p->mode[2]) {
    case 0: {
      u32 xf;
      p->coord = e->coord;
      SetDDP(&p->body, (const struct Collision*)0x0836B9BC);
      SetSpriteAnimation(p, 0xAE01);
      xf = (e->flags >> 4) & 1;
      if (xf != 0) {
        p->flags |= 0x10;
      } else {
        p->flags &= 0xEF;
      }
      {
        register u32 xvf asm("r1");
        xvf = xf;
        (p->spr).xflip = xvf;
        (p->spr).oam.xflip = xvf;
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 nx;
      UpdateEntityAnim((struct Entity*)p);
      p->coord = e->coord;
      if (!((((struct Entity*)p->unk_28)->flags) & 0x10)) {
        nx = p->coord.x + -0x4000;
      } else {
        nx = p->coord.x + 0x4000;
      }
      p->coord.x = nx;
      if ((*(u32*)((u8*)p + 0xc0) & 0x100) != 0) {
        p->mode[2]++;
      }
      break;
    }
    case 2: {
      u32 xf2;
      p->coord = e->coord;
      SetSpriteAnimation(p, 0xAE02);
      SetDDP(&p->body, (const struct Collision*)0x0836B9D4);
      xf2 = (e->flags >> 4) & 1;
      if (xf2 != 0) {
        p->flags |= 0x10;
      } else {
        p->flags &= 0xEF;
      }
      {
        register u32 xv2 asm("r1");
        xv2 = xf2;
        (p->spr).xflip = xv2;
        (p->spr).oam.xflip = xv2;
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 3: {
      s32 nx2;
      UpdateEntityAnim((struct Entity*)p);
      p->coord = e->coord;
      if (!((((struct Entity*)p->unk_28)->flags) & 0x10)) {
        nx2 = p->coord.x + -0x4000;
      } else {
        nx2 = p->coord.x + 0x4000;
      }
      p->coord.x = nx2;
      if ((*(u32*)((u8*)p + 0xc0) & 0x200) != 0) {
        p->mode[2]++;
      }
      break;
    }
    case 4:
      SetDDP(&p->body, (const struct Collision*)0x0836B9A4);
      p->work[2] = 0x28;
      p->mode[2]++;
      FALLTHROUGH;
    case 5: {
      u32 w;
      UpdateEntityAnim((struct Entity*)p);
      w = p->work[2];
      if (w <= 0x1D) {
        register u32 fl asm("r0");
        s32 t1 = 1;
        t1 &= w;
        if (t1 != 0) {
          u32 va = p->flags;
          fl = 1;
          fl |= va;
        } else {
          u32 vb = p->flags;
          fl = 0xFE;
          fl &= vb;
        }
        p->flags = fl;
      }
      {
        s32 t = p->work[2];
        if (t != 0) {
          t--;
          p->work[2] = t;
          if ((t << 24) != 0) {
            break;
          }
        }
      }
    die:
      SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
      break;
    }
  }
}

void FUN_080a38e8(Projectile* p);
void FUN_080a3c58(Projectile* p);
void FUN_080a44c0(Projectile* p);
void FUN_080a4d0c(Projectile* p);

static const ProjectileFunc PTR_ARRAY_0836b4d4[4] = {
    FUN_080a38e8,
    FUN_080a3c58,
    FUN_080a44c0,
    FUN_080a4d0c,
};

static const ProjectileFunc* const PTR_ARRAY_0836b4e4[4] = {
    &PTR_ARRAY_0836b4d4[0],
    &PTR_ARRAY_0836b4d4[1],
    &PTR_ARRAY_0836b4d4[2],
    &PTR_ARRAY_0836b4d4[3],
};

// --------------------------------------------

// 0x0836B4F4
static const struct Collision sCollisions[53] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 0,
      layer : 1,
      range : {PIXEL(0), PIXEL(0), PIXEL(22), PIXEL(22)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 3,
      layer : 1,
      range : {PIXEL(8), -PIXEL(11), PIXEL(50), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 2,
      range : {PIXEL(8), -PIXEL(11), PIXEL(50), PIXEL(12)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {-PIXEL(11), PIXEL(6), PIXEL(11), PIXEL(47)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {-PIXEL(11), PIXEL(6), PIXEL(11), PIXEL(47)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 3,
      layer : 1,
      range : {PIXEL(8), PIXEL(0), PIXEL(18), PIXEL(58)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 2,
      range : {PIXEL(8), PIXEL(0), PIXEL(18), PIXEL(58)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {-PIXEL(7), PIXEL(1), PIXEL(12), PIXEL(35)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {-PIXEL(7), PIXEL(1), PIXEL(12), PIXEL(35)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 3,
      layer : 1,
      range : {-PIXEL(11), -PIXEL(9), PIXEL(13), PIXEL(49)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 2,
      range : {-PIXEL(11), -PIXEL(9), PIXEL(13), PIXEL(49)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {PIXEL(9), PIXEL(12), PIXEL(48), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(9), PIXEL(12), PIXEL(48), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 3,
      layer : 1,
      range : {PIXEL(0), PIXEL(9), PIXEL(28), PIXEL(17)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 2,
      range : {PIXEL(0), PIXEL(9), PIXEL(28), PIXEL(17)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {PIXEL(0), -PIXEL(9), PIXEL(60), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(9), PIXEL(60), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 3,
      layer : 1,
      range : {PIXEL(12), -PIXEL(9), PIXEL(13), PIXEL(49)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 2,
      range : {PIXEL(12), -PIXEL(9), PIXEL(13), PIXEL(49)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {-PIXEL(9), PIXEL(12), PIXEL(48), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {-PIXEL(9), PIXEL(12), PIXEL(48), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 3,
      layer : 1,
      range : {-PIXEL(8), PIXEL(0), PIXEL(18), PIXEL(58)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 2,
      range : {-PIXEL(8), PIXEL(0), PIXEL(18), PIXEL(58)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {PIXEL(7), PIXEL(1), PIXEL(12), PIXEL(35)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(7), PIXEL(1), PIXEL(12), PIXEL(35)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 3,
      layer : 1,
      range : {-PIXEL(9), -PIXEL(12), PIXEL(48), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 2,
      range : {-PIXEL(9), -PIXEL(12), PIXEL(48), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {PIXEL(12), PIXEL(8), PIXEL(13), PIXEL(49)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(12), PIXEL(8), PIXEL(13), PIXEL(49)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 3,
      layer : 1,
      range : {PIXEL(0), -PIXEL(9), PIXEL(28), PIXEL(17)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 2,
      range : {PIXEL(0), -PIXEL(9), PIXEL(28), PIXEL(17)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {PIXEL(0), PIXEL(9), PIXEL(60), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), PIXEL(9), PIXEL(60), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {PIXEL(0), -PIXEL(9), PIXEL(28), PIXEL(17)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 0,
      layer : 1,
      range : {PIXEL(0), PIXEL(9), PIXEL(60), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {-PIXEL(9), -PIXEL(12), PIXEL(48), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 0,
      layer : 1,
      range : {PIXEL(12), PIXEL(8), PIXEL(13), PIXEL(49)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {-PIXEL(8), PIXEL(0), PIXEL(18), PIXEL(58)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 0,
      layer : 1,
      range : {PIXEL(7), PIXEL(1), PIXEL(12), PIXEL(35)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {PIXEL(12), -PIXEL(9), PIXEL(13), PIXEL(49)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 0,
      layer : 1,
      range : {-PIXEL(9), PIXEL(12), PIXEL(48), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {PIXEL(0), PIXEL(9), PIXEL(28), PIXEL(17)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 0,
      layer : 1,
      range : {PIXEL(0), -PIXEL(9), PIXEL(60), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {-PIXEL(11), -PIXEL(9), PIXEL(13), PIXEL(49)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 0,
      layer : 1,
      range : {PIXEL(9), PIXEL(12), PIXEL(48), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {PIXEL(8), PIXEL(0), PIXEL(18), PIXEL(58)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 0,
      layer : 1,
      range : {-PIXEL(7), PIXEL(1), PIXEL(12), PIXEL(35)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 1,
      range : {PIXEL(8), -PIXEL(11), PIXEL(50), PIXEL(12)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0,
      remaining : 0,
      layer : 1,
      range : {-PIXEL(11), PIXEL(6), PIXEL(11), PIXEL(47)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      comboLv : 0,
      remaining : 0,
      layer : 1,
      range : {PIXEL(29), -PIXEL(38), PIXEL(22), PIXEL(54)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      comboLv : 0,
      remaining : 0,
      layer : 1,
      range : {-PIXEL(47), -PIXEL(34), PIXEL(90), PIXEL(26)},
    },
};

// clang-format off
static const Coords32 sCoords[10] = {
    {PIXEL(28), PIXEL(24)},
    {-PIXEL(28), -PIXEL(24)},
    {PIXEL(14), PIXEL(10)},
    {-PIXEL(14), -PIXEL(10)},
    {PIXEL(28), -PIXEL(24)},
    {-PIXEL(28), PIXEL(24)},
    {-PIXEL(14), PIXEL(10)},
    {PIXEL(14), -PIXEL(10)},
    {PIXEL(0), PIXEL(0)},
    {PIXEL(0), PIXEL(0)},
};
// clang-format on
