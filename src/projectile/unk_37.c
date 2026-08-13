#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "vfx.h"
#include "physics.h"
#include "zero.h"

// キャリビーG の ミサイル + そのミサイルを撃つ部分

void Projectile37_Init(Projectile* p);
void Projectile37_Update(Projectile* p);
void Projectile37_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile37Routine = {
    [ENTITY_INIT] =      (void*)Projectile37_Init,
    [ENTITY_UPDATE] =    (void*)Projectile37_Update,
    [ENTITY_DIE] =       (void*)Projectile37_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static Entity* unused_FUN_080ada80(void* e, u8 kind) {
  Entity* p = (Entity*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 37);
    p->work[0] = kind, p->work[1] = 1;
    p->unk_28 = e;
  }
  return p;
}

Entity* FUN_080adad0(Coords32* c, u8 kind) {
  Entity* p = (Entity*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 37);
    p->work[0] = kind, p->work[1] = 0;
    (p->coord).x = c->x, (p->coord).y = c->y;
  }
  return p;
}

INCASM("asm/projectile/unk_37_a.inc");

void FUN_080adc84(Projectile* p0) {
  register struct Projectile* p asm("r4");
  register u32* st5 asm("r5");
  u32 st;
  p = p0;
  st5 = (u32*)((u8*)p + 0x8c);
  st = *st5;
  {
    u32 hit = st & 0x200;
    if (hit != 0) {
      u32 z = 0;
      *st5 = z;
      *(u32*)((u8*)p + 0x90) = z;
      *((u8*)p + 0x94) = z;
      p->flags &= 0xFB;
      PlaySound(0x35);
      asm volatile("@k1");
      goto die;
    }
    if ((st & 4) != 0) {
      *st5 = hit;
      *(u32*)((u8*)p + 0x90) = hit;
      *((u8*)p + 0x94) = hit;
      p->flags &= 0xFB;
      PlaySound(0x35);
      goto die;
    }
  }
  {
    u32 t0 = p->work[2] - 1;
    u32 t;
    p->work[2] = t0;
    t = (u8)t0;
    if (t != 0) {
      t = (u16)FUN_080098a4(p->coord.x, p->coord.y);
      if (t == 0) {
        goto sw;
      }
      {
        u32 msk = 0x8000;
        msk &= t;
        t = (u16)msk;
      }
      if (t != 0) {
        goto sw;
      }
    }
    *st5 = t;
    *(u32*)((u8*)p + 0x90) = t;
    *((u8*)p + 0x94) = t;
    p->flags &= 0xFB;
  }
die:
  CreateSmoke(2, &p->coord);
  SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  return;
sw:
  switch (p->mode[2]) {
    case 0: {
      register u32 z2 asm("r2");
      SetMotion((struct Entity*)p, 0x6F08);
      z2 = 0;
      p->flags &= 0xEF;
      *((u8*)p + 0x4c) = z2;
      {
        u8* oa = (u8*)p + 0x4a;
        s32 ov = *oa;
        s32 m11 = -0x11;
        m11 &= ov;
        *oa = m11;
      }
      p->d.y = z2;
      p->work[2] = 0xFF;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      {
        s32 vy = p->d.y + 0x40;
        p->d.y = vy;
        {
          s32 lim = 0xE0 << 2;
          if (vy > lim) {
            p->d.y = lim;
          }
        }
      }
      {
        s32 ny = p->coord.y + p->d.y;
        s32 r;
        p->coord.y = ny;
        r = PushoutToUp1(p->coord.x, ny + (0xC0 << 5));
        if (r != 0) {
          p->coord.y += r;
          p->mode[2]++;
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
    case 2:
      PlaySound(0x64);
      p->d.x = 0x20;
      p->work[3] = 0xC;
      p->mode[2]++;
      FALLTHROUGH;
    case 3: {
      {
        s32 vy = p->d.y - 0x80;
        p->d.y = vy;
        if (vy < 0) {
          p->d.y = 0;
        }
      }
      {
        s32 cy = p->coord.y;
        p->coord.y = cy + p->d.y;
      }
      {
        s32 cx = p->coord.x;
        p->coord.x = cx + p->d.x;
      }
      UpdateEntityAnim((struct Entity*)p);
      if ((u8)(p->work[3] % 3) == 0) {
        struct Coord c;
        c = p->coord;
        c.y += 0x80 << 3;
        CreateSmoke(3, &c);
      }
      {
        u32 w3 = p->work[3] - 1;
        p->work[3] = w3;
        if ((w3 << 24) != 0) {
          break;
        }
      }
      p->unk_coord.x = p->d.x;
      p->unk_coord.y = p->d.y;
      p->mode[2]++;
      break;
    }
    case 4: {
      u32 spd;
      s32 m64;
      s32 m68;
      s32 vy2;
      {
        u32 z3 = 0;
        p->flags &= 0xEF;
        *((u8*)p + 0x4c) = z3;
      }
      {
        u8* oa = (u8*)p + 0x4a;
        s32 ov = *oa;
        s32 m11 = -0x11;
        m11 &= ov;
        *oa = m11;
      }
      p->work[3] = 0xD;
      {
        struct Zero* z2 = pZero2;
        s32 dx = (z2->s).coord.x - p->coord.x;
        s32 dy;
        p->d.x = dx;
        {
          s32 t2 = p->coord.y + (0x80 << 5);
          dy = (z2->s).coord.y - t2;
        }
        p->d.y = dy;
        {
          s32 dx4 = dx >> 2;
          s32 dy4;
          spd = ((u32)(Sqrt(({ s32 q0 = dx4 * dx4; asm("" : "+r"(q0)); dy4 = dy >> 2; q0; }) + dy4 * dy4) << 16)) >> 14;
        }
      }
      if (spd != 0) {
        p->d.x = (p->d.x << 8) / (s32)spd;
        p->d.y = (p->d.y << 8) / (s32)spd;
      }
      m64 = (p->d.x << 9) >> 8;
      p->unk_coord.x = m64;
      vy2 = p->d.y;
      m68 = (vy2 << 9) >> 8;
      p->unk_coord.y = m68;
      {
        u16 mot;
        if (m64 > 0) {
          if (m68 > 0) {
            if (vy2 <= 0x5E) {
              mot = 0x6F06;
              asm("" : "+l"(mot));
            } else if (vy2 <= 0xEA) {
              mot = 0x6F05;
              asm("" : "+l"(mot));
            } else {
              mot = 0x6F04;
              asm("" : "+l"(mot));
            }
          } else {
            if (vy2 > -0x5F) {
              mot = 0x6F06;
              asm("" : "+l"(mot));
            } else if (vy2 > -0xEB) {
              mot = 0x6F07;
              asm("" : "+l"(mot));
            } else {
              mot = 0xDE << 7;
              asm("" : "+l"(mot));
            }
          }
        } else {
          if (m68 > 0) {
            if (vy2 <= 0x5E) {
              mot = 0x6F02;
              asm("" : "+l"(mot));
            } else if (vy2 <= 0xEA) {
              mot = 0x6F03;
              asm("" : "+l"(mot));
            } else {
              mot = 0x6F04;
              asm("" : "+l"(mot));
            }
          } else {
            if (vy2 > -0x5F) {
              mot = 0x6F02;
              asm("" : "+l"(mot));
            } else if (vy2 > -0xEB) {
              mot = 0x6F01;
              asm("" : "+l"(mot));
            } else {
              goto t1_6f00;
            }
          }
        }
        SetMotion((struct Entity*)p, mot);
            goto tdone1;
            t1_6f00:
            mot = 0xDE << 7;
            asm("" : "+l"(mot));
            SetMotion((struct Entity*)p, mot);
            tdone1:;
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 5: {
      {
        u32 w3 = p->work[3];
        if (w3 != 0) {
          u32 t3 = w3 - 1;
          p->work[3] = t3;
          if ((t3 << 24) != 0) {
            goto move;
          }
          if (((pZero2->s).flags & 1) == 0) {
            p->work[3] = 0xD;
          }
          if (p->work[3] != 0) {
            goto move;
          }
        }
      }
      {
        struct Zero* z3 = pZero2;
        u32 spd;
        if (((z3->s).flags & 1) == 0) {
          goto move;
        }
        p->work[3] = 0xD;
        {
          s32 dx = (z3->s).coord.x - p->coord.x;
          s32 dy;
          p->d.x = dx;
          {
            s32 t2 = p->coord.y + (0x80 << 5);
            dy = (z3->s).coord.y - t2;
          }
          p->d.y = dy;
          {
            s32 dx4 = dx >> 2;
            s32 dy4;
            spd = ((u32)(Sqrt(({ s32 q0 = dx4 * dx4; asm("" : "+r"(q0)); dy4 = dy >> 2; q0; }) + dy4 * dy4) << 16)) >> 14;
          }
        }
        if (spd != 0) {
          p->d.x = (p->d.x << 8) / (s32)spd;
          p->d.y = (p->d.y << 8) / (s32)spd;
        }
        {
          s32 m64;
          s32 m68;
          s32 vy3;
          register s32 tx8 asm("r0");
          register s32 ty8 asm("r1");
          s32 nux;
          s32 nuy;
          {
            tx8 = (p->d.x << 9) >> 8;
            m64 = tx8;
            asm volatile("" :: "l"(m64));
            vy3 = p->d.y;
            ty8 = (vy3 << 9) >> 8;
            m68 = ty8;
            asm volatile("" :: "l"(spd));
            nux = ((p->unk_coord.x << 6) >> 8) + ((({ s32 tq = (tx8 << 1) + m64; asm("" : "+l"(tq)); tq; }) << 6) >> 8);
            p->unk_coord.x = nux;
          }
          nuy = ((p->unk_coord.y << 6) >> 8) + ((({ s32 uq = (ty8 << 1) + m68; asm("" : "+l"(uq)); uq; }) << 6) >> 8);
          p->unk_coord.y = nuy;
          {
            u16 mot;
            if (nux > 0) {
              if (nuy > 0) {
                if (vy3 <= 0x5E) {
                  mot = 0x6F06;
                  asm("" : "+l"(mot));
                } else if (vy3 <= 0xEA) {
                  mot = 0x6F05;
                  asm("" : "+l"(mot));
                } else {
                  mot = 0x6F04;
                  asm("" : "+l"(mot));
                }
              } else {
                if (vy3 > -0x5F) {
                  mot = 0x6F06;
                  asm("" : "+l"(mot));
                } else if (vy3 > -0xEB) {
                  mot = 0x6F07;
                  asm("" : "+l"(mot));
                } else {
                  mot = 0xDE << 7;
                  asm("" : "+l"(mot));
                }
              }
            } else {
              if (nuy > 0) {
                if (vy3 <= 0x5E) {
                  mot = 0x6F02;
                  asm("" : "+l"(mot));
                } else if (vy3 <= 0xEA) {
                  mot = 0x6F03;
                  asm("" : "+l"(mot));
                } else {
                  mot = 0x6F04;
                  asm("" : "+l"(mot));
                }
              } else {
                if (vy3 > -0x5F) {
                  mot = 0x6F02;
                  asm("" : "+l"(mot));
                } else if (vy3 > -0xEB) {
                  mot = 0x6F01;
                  asm("" : "+l"(mot));
                } else {
                  goto t2_6f00;
                }
              }
            }
            SetMotion((struct Entity*)p, mot);
            goto tdone2;
            t2_6f00:
            mot = 0xDE << 7;
            asm("" : "+l"(mot));
            SetMotion((struct Entity*)p, mot);
            tdone2:;
            asm volatile("" :: "l"(m68), "l"(m64));
          }
        }
      }
    move:
      if ((u8)(p->work[3] % 6) == 0) {
        struct Coord c2;
        c2 = p->coord;
        c2.y += 0x80 << 3;
        CreateSmoke(3, &c2);
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
      break;
    }
  }
}

INCASM("asm/projectile/unk_37_b.inc");

// --------------------------------------------

void FUN_080adc84(Projectile* p);
void FUN_080ae140(Projectile* p);

static const ProjectileFunc sUpdates[2] = {
    FUN_080adc84,
    FUN_080ae140,
};

// --------------------------------------------

static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(7), PIXEL(22), PIXEL(19)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      nature : 0x80,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(10)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(10)},
    },
};
