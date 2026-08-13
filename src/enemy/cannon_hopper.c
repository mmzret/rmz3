#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "vfx.h"
#include "physics.h"
#include "physics.h"
#include "physics.h"
#include "physics.h"
#include "score.h"

struct Entity* FUN_080b2b40(u8 kind, struct Coord* c, s32 r2, u8 r3);
struct VFX* FUN_080c6e24(struct Entity* e);

void FUN_08098110(struct Enemy* p);

INCASM("asm/enemy/cannon_hopper_a.inc");

void FUN_08098110(struct Enemy* p) {
  struct Coord c;
  s32 r;
  switch ((p->s).mode[2]) {
    case 0: {
      s32 dy = 0;
      u32 fl, sh, nf, f2;
      switch (*((u8*)p + 0xbe)) {
        default:
          break;
        case 1:
          dy = -0x1200;
          if ((p->s).flags & 0x20) {
            dy = 0x1200;
          }
          break;
        case 2:
          dy = -0x1800;
          if ((p->s).flags & 0x20) {
            dy = 0x1800;
          }
          break;
        case 3:
          dy = -0x2300;
          fl = (p->s).flags;
          {
            u32 t20 = 0x20;
            t20 &= fl;
            if (t20 != 0) {
              dy = 0x2300;
            }
          }
          sh = fl >> 5;
          nf = 1;
          nf &= ~sh;
          if (nf == 0) {
            goto Ldf;
          }
          f2 = 0x20 | fl;
          asm volatile("");
          goto Lst;
        case 4:
          dy = -0x2B00;
          fl = (p->s).flags;
          {
            u32 t20 = 0x20;
            t20 &= fl;
            if (t20 != 0) {
              dy = 0x2B00;
            }
          }
          sh = fl >> 5;
          nf = 1;
          nf &= ~sh;
          if (nf != 0) {
            f2 = 0x20 | fl;
            goto Lst;
          }
          FALLTHROUGH;
        Ldf:
          f2 = 0xDF & fl;
        Lst:
          (p->s).flags = f2;
          {
            u8* oa;
            u32 nv = nf;
            asm("" : "+r"(nv));
            *((u8*)p + 0x4d) = nv;
            oa = (u8*)p + 0x4a;
            {
              s32 ov, m21;
              nv <<= 5;
              ov = *oa;
              m21 = -0x21;
              m21 &= ov;
              m21 |= nv;
              *oa = m21;
            }
          }
          break;
      }
      (p->s).coord.y += dy;
      if ((u16)FUN_080098a4((p->s).coord.x, (p->s).coord.y) != 0) {
        s32 dn;
        r = PushoutToUp1((p->s).coord.x, (p->s).coord.y);
        dn = PushoutToDown1((p->s).coord.x, (p->s).coord.y);
        if (r > 0) {
          (p->s).coord.y += dn;
        } else if (dn < 0) {
          (p->s).coord.y += r;
        } else if (-r < dn) {
          (p->s).coord.y += r;
        } else {
          (p->s).coord.y += dn;
        }
      }
      SetMotion(&p->s, 0xDC07);
      c.x = (p->s).coord.x;
      c.y = (p->s).coord.y + -0x1000;
      {
        s32 xf = 0;
        if (*(s32*)((u8*)p + 0xb4) > 0) {
          xf = 1;
        }
        {
          u32 one = 1;
          u32 n2 = xf;
          asm("" : "+r"(n2));
          n2 ^= one;
          if (n2 != 0) {
            (p->s).flags |= 0x10;
          } else {
            (p->s).flags &= 0xEF;
          }
          {
            u32 nv2 = n2;
            u8* x4c;
            u32 z7;
            asm("" : "+r"(nv2));
            x4c = (u8*)p + 0x4c;
            z7 = 0;
            *x4c = nv2;
            {
              u8* oa = (u8*)p + 0x4a;
              s32 ov, m11;
              nv2 <<= 4;
              ov = *oa;
              m11 = -0x11;
              m11 &= ov;
              m11 |= nv2;
              *oa = m11;
            }
            FUN_080b2b40(0, &c, 0x200, xf);
            {
              s32 t100 = 0x100;
              (p->s).d.x = t100 - (xf << 9);
            }
            (p->s).d.y = (p->s).d.y >> 1;
            FUN_080c6e24(&p->s);
            (p->s).d.x = ((p->s).d.x * 0xB4) / 256;
            (p->s).d.y = ((p->s).d.y * 0xB4) / 256;
            {
              u8* q = (u8*)p + 0x8c;
              *(s32*)q = z7;
              asm("" : "+r"(q));
              q += 4;
              *(s32*)q = z7;
              asm("" : "+r"(q));
              q += 4;
              *q = z7;
            }
          }
        }
      }
      (p->s).flags &= 0xFB;
      (p->s).work[2] = 0x14;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      (p->s).coord.y += (p->s).d.y;
      r = PushoutToUp1((p->s).coord.x, (p->s).coord.y);
      if (r < 0) {
        (p->s).coord.y += r;
      }
      (p->s).coord.x += (p->s).d.x;
      if ((p->s).d.x > 0) {
        r = PushoutToLeft1((p->s).coord.x, (p->s).coord.y);
        if (r < 0) {
          (p->s).coord.x += r;
        }
      } else {
        r = PushoutToRight1((p->s).coord.x, (p->s).coord.y);
        if (r > 0) {
          (p->s).coord.x += r;
        }
      }
      (p->s).d.x = ((p->s).d.x * 225) / 256;
      {
        s32 dy2 = (p->s).d.y;
        if (dy2 != 0 || ((p->s).flags & 0x20)) {
          s32 nd = dy2 + 0x40;
          (p->s).d.y = nd;
          if (nd > 0x700) {
            (p->s).d.y = 0x700;
          }
        }
      }
      {
        s32 w = (p->s).work[2] - 1;
        (p->s).work[2] = w;
        if ((u8)w == 0) {
          struct Coord* cp;
          (p->s).flags &= 0xFE;
          c.x = (p->s).coord.x;
          c.y = (p->s).coord.y + -0x1000;
          CreateSmoke(1, &c);
          PlaySound(0x2A);
          cp = &(p->s).coord;
          TryDropItem(1, cp);
          if (gScore.enemyCount <= 0x270E) {
            gScore.enemyCount++;
          }
          DropEnemyDisk(p, cp);
          (p->s).mode[2]++;
        }
      }
      UpdateEntityAnim(&p->s);
      break;
    }
    case 2:
      (p->s).flags &= 0xFE;
      if ((p->s).work[2] != 0) {
        (p->s).work[2]--;
        break;
      }
      SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
      break;
  }
}

INCASM("asm/enemy/cannon_hopper_b.inc");

void CannonHopper_Init(struct Enemy* p);
void CannonHopper_Update(struct Enemy* p);
void CannonHopper_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gCannonHopperRoutine = {
    [ENTITY_INIT] =      (void*)CannonHopper_Init,
    [ENTITY_UPDATE] =    (void*)CannonHopper_Update,
    [ENTITY_DIE] =       (void*)CannonHopper_Die,
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
