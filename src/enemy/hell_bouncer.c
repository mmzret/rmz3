#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "zero.h"

void HellBouncer_Init(struct Enemy* p);
void HellBouncer_Update(struct Enemy* p);
void HellBouncer_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gHellBouncerRoutine = {
    [ENTITY_INIT] =      (void*)HellBouncer_Init,
    [ENTITY_UPDATE] =    (void*)HellBouncer_Update,
    [ENTITY_DIE] =       (void*)HellBouncer_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};


void FUN_0807f648(struct Enemy* p);
void FUN_0807e5f4(struct Enemy* p);
// clang-format on

struct Entity* createHellBouncer(struct Entity* q, Coords32* c, u8 r2, u8 idx) {
  struct Entity* p = (struct Entity*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_HELL_BOUNCER);
    p->coord = *c;
    p->work[0] = r2, p->work[1] = idx;
    p->unk_28 = q;
  }
  return p;
}

INCASM("asm/enemy/hell_bouncer_a.inc");

void FUN_0807e5f4(struct Enemy* p0) {
  register struct Enemy* p asm("r5");
  u32 wv;
  p = p0;
  switch ((p->s).mode[2]) {
    case 0: {
      (p->s).flags |= 1;
      SetMotion(&p->s, MOTION(0xAB, 0x1B));
      (p->s).renderPrio = 0x19;
      SetDDP(&p->body, (const struct Collision*)0x8367E40);
      {
        u32 b8 = *((u8*)p + 0xb8);
        if (b8 == 0) {
          (p->s).flags &= 0xEF;
          *((u8*)p + 0x4c) = b8;
          {
            u8* oa = (u8*)p + 0x4a;
            s32 ov = *oa;
            s32 m11 = -0x11;
            m11 &= ov;
            *oa = m11;
          }
          (p->s).d.x = -0x800;
        } else {
          u32 one = 1;
          (p->s).flags |= 0x10;
          *((u8*)p + 0x4c) = one;
          {
            register u8* oa asm("r3");
            register s32 k asm("r2");
            oa = (u8*)p + 0x4a;
            k = 0x10;
            {
              s32 ov = *oa;
              s32 m11 = -0x11;
              m11 &= ov;
              m11 |= k;
              *oa = m11;
            }
          }
          (p->s).d.x = 0x80 << 4;
        }
      }
      (p->s).d.y = -0x3A0;
      (p->s).work[2] = 0x1E;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      {
        s32 cx = (p->s).coord.x;
        cx += (p->s).d.x;
        (p->s).coord.x = cx;
      }
      {
        s32 cy = (p->s).coord.y;
        cy += (p->s).d.y;
        (p->s).coord.y = cy;
      }
      UpdateEntityAnim(&p->s);
      {
        u32 w = (p->s).work[2];
        if (w != 0) {
          w--;
          (p->s).work[2] = w;
          if ((w << 24) != 0) {
            break;
          }
        }
      }
      if (*((u8*)p + 0xb8) != 0) {
        (p->s).mode[2] = 0x14;
        break;
      }
      (p->s).mode[2]++;
      break;
    }
    case 2: {
      register s32 base asm("r0");
      register s32 off asm("r1");
      register s32 tx6 asm("r6");
      SetDDP(&p->body, (const struct Collision*)0x8367E10);
      (p->s).renderPrio = 0x17;
      {
        struct Entity* q = (p->s).unk_28;
        register u32 k3 asm("r3");
        u32 fl0;
        register u32 m0 asm("r0");
        fl0 = q->flags;
        k3 = 0x10;
        m0 = k3;
        asm("" : "+r"(m0));
        m0 &= fl0;
        if (m0 == 0) {
          u32 one = 1;
          (p->s).flags |= 0x10;
          *((u8*)p + 0x4c) = one;
          {
            u8* oa = (u8*)p + 0x4a;
            s32 ov = *oa;
            s32 m11 = -0x11;
            m11 &= ov;
            m11 |= k3;
            *oa = m11;
          }
          {
            struct Entity* q2 = (p->s).unk_28;
            (p->s).coord.x = (q2->coord).x + -0x8C00;
            base = (q2->coord).x;
            off = -0x1000;
          }
        } else {
          register u32 z asm("r2");
          z = 0;
          (p->s).flags &= 0xEF;
          *((u8*)p + 0x4c) = z;
          {
            u8* oa = (u8*)p + 0x4a;
            s32 ov = *oa;
            s32 m11 = -0x11;
            m11 &= ov;
            *oa = m11;
          }
          {
            struct Entity* q2 = (p->s).unk_28;
            (p->s).coord.x = (q2->coord).x + (0x8C << 8);
            base = (q2->coord).x;
            off = 0x80 << 5;
          }
        }
      }
      tx6 = base + off;
      {
        s32 ty = ((p->s).unk_28)->coord.y;
        register s32 kA asm("r2");
        kA = -0xA000;
        asm("" : "+r"(kA));
        (p->s).coord.y = ty + kA;
      }
      SetMotion(&p->s, MOTION(0xAC, 0x05));
      {
        u32 z4 = 0;
        (p->s).work[2] = 0x1E;
        (p->s).d.x = (tx6 - (p->s).coord.x) / 0x1E;
        {
          s32 k7 = 0xE1 << 7;
          asm("" : "+r"(k7));
          (p->s).d.y = -((k7 - (((p->s).unk_28)->coord.y - (p->s).coord.y)) / 0x1E);
        }
        (p->s).work[2] = 0x1D;
        (p->s).work[3] = z4;
      }
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 3: {
      {
        s32 vy = (p->s).d.y + 0x40;
        (p->s).d.y = vy;
        {
          s32 lim = 0xE0 << 3;
          if (vy > lim) {
            (p->s).d.y = lim;
          }
        }
      }
      {
        s32 cx = (p->s).coord.x;
        cx += (p->s).d.x;
        (p->s).coord.x = cx;
      }
      {
        s32 ny = (p->s).coord.y + (p->s).d.y;
        (p->s).coord.y = ny;
        if ((p->s).work[3] == 0) {
          struct Entity* q = (p->s).unk_28;
          s32* lp = (s32*)((u8*)q + 0xFFC70054);
          asm("" : "+r"(lp));
          if (ny > lp[1]) {
            (p->s).work[3] = 1;
            SetMotion(&p->s, MOTION(0xAC, 0x06));
          }
        }
      }
      UpdateEntityAnim(&p->s);
      {
        struct Entity* q = (p->s).unk_28;
        s32 my = (p->s).coord.y;
        s32 fy = q->coord.y;
        if (my > fy) {
          (p->s).coord.y = fy;
          (p->s).mode[2]++;
        }
      }
      break;
    }
    case 4:
      SetDDP(&p->body, (const struct Collision*)0x8367DB0);
      SetMotion(&p->s, MOTION(0xAC, 0x07));
      PlaySound(0xD3);
      (p->s).mode[2]++;
      UpdateEntityAnim(&p->s);
      if ((p->s).motion.state != 3) {
        break;
      }
      (p->s).mode[2]++;
      break;
    case 6:
      SetMotion(&p->s, MOTION(0xAC, 0x09));
      (p->s).work[2] = 0xF;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 7: {
      UpdateEntityAnim(&p->s);
      {
        u32 w = (p->s).work[2];
        if (w != 0) {
          w--;
          (p->s).work[2] = w;
          if ((w << 24) != 0) {
            break;
          }
        }
      }
      (p->s).mode[2]++;
      {
        register u32 nv asm("r1");
        u32 fl2;
        u32 v;
        fl2 = (p->s).flags;
        v = fl2 >> 4;
        nv = 1;
        nv &= ~v;
        if (nv != 0) {
          u32 res = 0x10;
          res |= fl2;
          (p->s).flags = res;
        } else {
          u32 res2 = 0xEF;
          res2 &= fl2;
          (p->s).flags = res2;
        }
        *((u8*)p + 0x4c) = nv;
        {
          register u8* oa asm("r3");
          u32 sh4;
          s32 ov;
          s32 m11;
          oa = (u8*)p + 0x4a;
          sh4 = nv << 4;
          ov = *oa;
          m11 = -0x11;
          m11 &= ov;
          m11 |= sh4;
          *oa = m11;
        }
      }
      break;
    }
    case 9:
      SetMotion(&p->s, MOTION(0xAC, 0x01));
      wv = 0x1E;
      goto tail24;
    case 20: {
      register s32 base asm("r0");
      register s32 off asm("r1");
      register s32 tx6 asm("r6");
      SetDDP(&p->body, (const struct Collision*)0x8367E10);
      (p->s).renderPrio = 0x17;
      {
        struct Entity* q = (p->s).unk_28;
        register u32 k3 asm("r3");
        u32 fl0;
        u32 m2;
        fl0 = q->flags;
        asm("" : "+r"(fl0));
        k3 = 0x10;
        {
          register u32 mm asm("r0");
          mm = k3;
          asm("" : "+r"(mm));
          mm &= fl0;
          m2 = (u8)mm;
        }
        if (m2 == 0) {
          (p->s).flags &= 0xEF;
          *((u8*)p + 0x4c) = m2;
          {
            u8* oa = (u8*)p + 0x4a;
            s32 ov = *oa;
            s32 m11 = -0x11;
            m11 &= ov;
            *oa = m11;
          }
          {
            struct Entity* q2 = (p->s).unk_28;
            (p->s).coord.x = (q2->coord).x + (0x8C << 8);
            base = (q2->coord).x;
            off = -0x3000;
          }
        } else {
          u32 one = 1;
          (p->s).flags |= 0x10;
          *((u8*)p + 0x4c) = one;
          {
            u8* oa = (u8*)p + 0x4a;
            s32 ov = *oa;
            s32 m11 = -0x11;
            m11 &= ov;
            m11 |= k3;
            *oa = m11;
          }
          {
            struct Entity* q2 = (p->s).unk_28;
            (p->s).coord.x = (q2->coord).x + -0x8C00;
            base = (q2->coord).x;
            off = 0xC0 << 6;
          }
        }
      }
      tx6 = base + off;
      {
        s32 ty = ((p->s).unk_28)->coord.y;
        register s32 kA asm("r2");
        kA = -0xA000;
        asm("" : "+r"(kA));
        (p->s).coord.y = ty + kA;
      }
      SetMotion(&p->s, MOTION(0xAC, 0x05));
      {
        u32 z4 = 0;
        (p->s).work[2] = 0x1E;
        (p->s).d.x = (tx6 - (p->s).coord.x) / 0x1E;
        {
          s32 k7 = 0xE1 << 7;
          asm("" : "+r"(k7));
          (p->s).d.y = -((k7 - (((p->s).unk_28)->coord.y - (p->s).coord.y)) / 0x1E);
        }
        (p->s).work[2] = 0x1D;
        (p->s).work[3] = z4;
      }
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 21: {
      {
        s32 vy = (p->s).d.y + 0x40;
        (p->s).d.y = vy;
        {
          s32 lim = 0xE0 << 3;
          if (vy > lim) {
            (p->s).d.y = lim;
          }
        }
      }
      {
        s32 cx = (p->s).coord.x;
        cx += (p->s).d.x;
        (p->s).coord.x = cx;
      }
      {
        s32 ny = (p->s).coord.y + (p->s).d.y;
        (p->s).coord.y = ny;
        if ((p->s).work[3] == 0) {
          struct Entity* q = (p->s).unk_28;
          s32* lp = (s32*)((u8*)q + 0xFFC70054);
          asm("" : "+r"(lp));
          if (ny > lp[1]) {
            (p->s).work[3] = 1;
            SetMotion(&p->s, MOTION(0xAC, 0x06));
          }
        }
      }
      UpdateEntityAnim(&p->s);
      {
        struct Entity* q = (p->s).unk_28;
        s32 my = (p->s).coord.y;
        s32 fy = q->coord.y;
        if (my > fy) {
          (p->s).coord.y = fy;
          (p->s).mode[2]++;
        }
      }
      break;
    }
    case 22:
      PlaySound(0xD3);
      SetDDP(&p->body, (const struct Collision*)0x8367DB0);
      SetMotion(&p->s, MOTION(0xAC, 0x07));
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 5:
    case 8:
    case 23:
      UpdateEntityAnim(&p->s);
      if ((p->s).motion.state != 3) {
        break;
      }
      (p->s).mode[2]++;
      break;
    case 24:
      SetMotion(&p->s, MOTION(0xAC, 0x01));
      wv = 2;
    tail24:
      (p->s).work[2] = wv;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 10:
    case 25: {
      UpdateEntityAnim(&p->s);
      {
        u32 w = (p->s).work[2];
        if (w != 0) {
          w--;
          (p->s).work[2] = w;
          if ((w << 24) != 0) {
            break;
          }
        }
      }
      {
        u32 z = 0;
        (p->s).mode[1] = 1;
        (p->s).mode[2] = z;
      }
      break;
    }
  }
}

INCASM("asm/enemy/hell_bouncer_b.inc");

void FUN_0807f648(struct Enemy* p0) {
  register struct Enemy* p asm("r6");
  s32 cmpa;
  s32 cmpb;
  s32 va;
  s32 vb;
  p = p0;
  if ((p->s).work[1] == 0) {
    switch ((p->s).mode[2]) {
      case 0: {
        {
          u8* c0 = (u8*)p + 0xc0;
          *c0 = 0;
        }
        {
          u32 fv = (p->s).flags;
          u32 res = 1;
          res |= fv;
          (p->s).flags = res;
        }
        SetMotion(&p->s, MOTION(0xAC, 0x08));
        (p->s).renderPrio = 0x19;
        (p->s).d.x = -0x200;
        (p->s).mode[2]++;
        FALLTHROUGH;
      }
      case 1: {
        {
          s32 cx = (p->s).coord.x;
          cx += (p->s).d.x;
          (p->s).coord.x = cx;
        }
        UpdateEntityAnim(&p->s);
        if ((p->s).motion.state == 4) {
          PlaySound(0xD3);
        }
        if ((p->s).coord.x < (p->s).unk_coord.x + (0xC0 << 7)) {
          u8* c0 = (u8*)p + 0xc0;
          *c0 = 1;
        }
        cmpb = (p->s).unk_coord.x + (0x80 << 7);
        cmpa = (p->s).coord.x;
        goto cmptail;
      }
      case 2:
        *((u8*)p + 0xb9) = 1;
        SetMotion(&p->s, MOTION(0xAC, 0x0B));
        (p->s).d.y = -0x280;
        (p->s).d.x = 0xC0 << 1;
        (p->s).mode[2]++;
        FALLTHROUGH;
      case 3:
        UpdateEntityAnim(&p->s);
        if ((p->s).motion.state != 3) {
          break;
        }
        (p->s).mode[2]++;
        break;
      case 4:
        PlaySound(0xD3);
        SetMotion(&p->s, MOTION(0xAC, 0x0C));
        (p->s).mode[2]++;
        FALLTHROUGH;
      case 5: {
        {
          s32 vy = (p->s).d.y + 0x40;
          (p->s).d.y = vy;
          {
            s32 lim = 0xE0 << 3;
            if (vy > lim) {
              (p->s).d.y = lim;
            }
          }
        }
        {
          s32 cx = (p->s).coord.x;
          cx += (p->s).d.x;
          (p->s).coord.x = cx;
        }
        {
          s32 cy = (p->s).coord.y;
          cy += (p->s).d.y;
          (p->s).coord.y = cy;
        }
        UpdateEntityAnim(&p->s);
        {
          struct Zero* z = pZero2;
          s32 my = (p->s).coord.y;
          s32 zy = (z->s).coord.y;
          if (my > zy) {
            (p->s).coord.y = zy;
            (p->s).mode[2]++;
          }
        }
        break;
      }
      case 6:
        SetMotion(&p->s, MOTION(0xAC, 0x0D));
        (p->s).mode[2]++;
        FALLTHROUGH;
      case 7:
        UpdateEntityAnim(&p->s);
        if ((p->s).motion.state != 3) {
          break;
        }
        (p->s).mode[2]++;
        break;
      case 8:
        *((u8*)p + 0xb9) = 1;
        SetMotion(&p->s, MOTION(0xAC, 0x01));
        (p->s).mode[2]++;
        FALLTHROUGH;
      case 9:
        UpdateEntityAnim(&p->s);
        if (*((u8*)p + 0xb9) != 2) {
          break;
        }
        (p->s).mode[2]++;
        break;
      case 10: {
        u32 z;
        SetMotion(&p->s, MOTION(0xAC, 0x09));
        z = 0;
        (p->s).work[2] = 0xF;
        (p->s).work[3] = z;
        (p->s).mode[2]++;
        FALLTHROUGH;
      }
      case 11: {
        UpdateEntityAnim(&p->s);
        {
          u32 w = (p->s).work[2];
          if (w != 0) {
            w--;
            (p->s).work[2] = w;
            if ((w << 24) != 0) {
              goto stchk11;
            }
          }
        }
        if ((p->s).work[3] == 0) {
          register u32 nv asm("r1");
          u32 fl2;
          nv = 1;
          (p->s).work[3] = nv;
          fl2 = (p->s).flags;
          nv &= ~(fl2 >> 4);
          if (nv != 0) {
            u32 res = 0x10;
            res |= fl2;
            (p->s).flags = res;
          } else {
            u32 res2 = 0xEF;
            res2 &= fl2;
            (p->s).flags = res2;
          }
          *((u8*)p + 0x4c) = nv;
          {
            register u8* oa asm("r3");
            u32 sh4;
            s32 ov;
            s32 m11;
            oa = (u8*)p + 0x4a;
            sh4 = nv << 4;
            ov = *oa;
            m11 = -0x11;
            m11 &= ov;
            m11 |= sh4;
            *oa = m11;
          }
        }
      stchk11:
        if ((p->s).motion.state != 3) {
          break;
        }
        (p->s).mode[2]++;
        break;
      }
      case 12:
        SetMotion(&p->s, MOTION(0xAC, 0x02));
        (p->s).mode[2]++;
        FALLTHROUGH;
      case 13:
        UpdateEntityAnim(&p->s);
        if ((p->s).motion.state != 3) {
          break;
        }
        (p->s).mode[2]++;
        break;
      case 14:
        (p->s).d.x = 0xC0 << 3;
        (p->s).d.y = -0x700;
        SetMotion(&p->s, MOTION(0xAC, 0x03));
        (p->s).mode[2]++;
        FALLTHROUGH;
      case 15: {
        {
          s32 vy = (p->s).d.y + 0x20;
          (p->s).d.y = vy;
          {
            s32 lim = 0xE0 << 3;
            if (vy > lim) {
              (p->s).d.y = lim;
            }
          }
        }
        {
          s32 cx = (p->s).coord.x;
          cx += (p->s).d.x;
          (p->s).coord.x = cx;
        }
        {
          s32 cy = (p->s).coord.y;
          cy += (p->s).d.y;
          (p->s).coord.y = cy;
        }
        UpdateEntityAnim(&p->s);
        cmpb = ((p->s).unk_28)->coord.y + -0x7800;
        goto cmptail28;
      }
      case 16: {
        (p->s).renderPrio = 0x19;
        SetMotion(&p->s, MOTION(0xAB, 0x1B));
        SetDDP(&p->body, (const struct Collision*)0x8367E40);
        (p->s).work[2] = 0x20;
        {
          u32 one = 1;
          (p->s).flags |= 0x10;
          *((u8*)p + 0x4c) = one;
          {
            register u8* oa asm("r3");
            register s32 k asm("r2");
            oa = (u8*)p + 0x4a;
            k = 0x10;
            {
              s32 ov = *oa;
              s32 m11 = -0x11;
              m11 &= ov;
              m11 |= k;
              *oa = m11;
            }
          }
        }
        {
          register struct Entity* q asm("r4");
          s32 qx;
          q = (p->s).unk_28;
          qx = q->coord.x;
          (p->s).coord.x = qx + (0xA0 << 8);
          {
            register s32 k8 asm("r3");
            s32 n;
            k8 = 0x8F << 8;
            asm("" : "+r"(k8));
            qx += k8;
            n = q->coord.x - qx;
            (p->s).d.x = n;
            (p->s).d.x = n / (p->s).work[2];
          }
          {
            register s32 kB asm("r2");
            register s32 k9 asm("r3");
            register s32 qy asm("r1");
            qy = q->coord.y;
            kB = -0xA000;
            asm("" : "+r"(kB));
            (p->s).coord.y = qy + kB;
            asm volatile("" ::"r"(kB));
            k9 = -0x7500;
            asm("" : "+r"(k9));
            vb = qy + k9;
            va = q->coord.y;
          }
        }
        goto divtail;
      }
      case 17:
        goto lastcase;
    }
  } else {
    switch ((p->s).mode[2]) {
      case 0: {
        u32 z;
        (p->s).flags &= 0xFE;
        z = 0;
        {
          u8* c0 = (u8*)p + 0xc0;
          *c0 = z;
        }
        (p->s).mode[2]++;
        FALLTHROUGH;
      }
      case 1:
        if (*((u8*)((p->s).unk_2c) + 0xc0) != 1) {
          break;
        }
        (p->s).mode[2]++;
        break;
      case 2: {
        (p->s).flags |= 1;
        SetMotion(&p->s, MOTION(0xAC, 0x05));
        (p->s).renderPrio = 0x17;
        {
          u32 one = 1;
          u32 z;
          (p->s).flags |= 0x10;
          {
            register u32 zr asm("r4");
            u8* a4c = (u8*)p + 0x4c;
            asm volatile("mov %0, #0" : "=r"(zr));
            z = zr;
            *a4c = one;
          }
          {
            register u8* oa asm("r3");
            register s32 k asm("r2");
            oa = (u8*)p + 0x4a;
            k = 0x10;
            {
              s32 ov = *oa;
              s32 m11 = -0x11;
              m11 &= ov;
              m11 |= k;
              *oa = m11;
            }
          }
          {
            s32 tx = (p->s).unk_coord.x;
            {
              register s32 kc asm("r1");
              kc = 0x84 << 8;
              asm("" : "+r"(kc));
              tx += kc;
            }
            (p->s).work[2] = 0x28;
            (p->s).d.x = (tx - (p->s).coord.x) / 0x28;
          }
          {
            s32 k5 = 0xC8 << 8;
            asm("" : "+r"(k5));
            (p->s).d.y = -((k5 - ((pZero2->s).coord.y - (p->s).coord.y)) / 0x28);
          }
          (p->s).work[3] = z;
        }
        (p->s).mode[2]++;
        FALLTHROUGH;
      }
      case 3: {
        {
          s32 vy = (p->s).d.y + 0x40;
          (p->s).d.y = vy;
          {
            s32 lim = 0xE0 << 3;
            if (vy > lim) {
              (p->s).d.y = lim;
            }
          }
        }
        {
          s32 cx = (p->s).coord.x;
          cx += (p->s).d.x;
          (p->s).coord.x = cx;
        }
        {
          s32 cy = (p->s).coord.y;
          s32 ny = cy + (p->s).d.y;
          (p->s).coord.y = ny;
          {
            u32 w3 = (p->s).work[3];
            if (w3 == 0) {
              if (ny > (pZero2->s).coord.y + -0x6000) {
                asm("" : "+r"(w3));
                (p->s).work[3] = w3 + 1;
                SetMotion(&p->s, MOTION(0xAC, 0x06));
              }
            }
          }
        }
        UpdateEntityAnim(&p->s);
        {
          u32 w = (p->s).work[2];
          if (w != 0) {
            w--;
            (p->s).work[2] = w;
            if ((w << 24) != 0) {
              break;
            }
          }
        }
        (p->s).coord.y = (pZero2->s).coord.y;
        (p->s).mode[2]++;
        break;
      }
      case 4:
        *((u8*)p + 0xb9) = 1;
        SetMotion(&p->s, MOTION(0xAC, 0x07));
        (p->s).mode[2]++;
        FALLTHROUGH;
      case 5:
        UpdateEntityAnim(&p->s);
        if ((p->s).motion.state != 3) {
          break;
        }
        (p->s).mode[2]++;
        break;
      case 6: {
        u32 z;
        PlaySound(0xD3);
        SetMotion(&p->s, MOTION(0xAC, 0x09));
        z = 0;
        (p->s).work[2] = 0xF;
        (p->s).work[3] = z;
        (p->s).mode[2]++;
        FALLTHROUGH;
      }
      case 7: {
        UpdateEntityAnim(&p->s);
        {
          u32 w = (p->s).work[2];
          if (w != 0) {
            w--;
            (p->s).work[2] = w;
            if ((w << 24) != 0) {
              goto stchk7;
            }
          }
        }
        if ((p->s).work[3] == 0) {
          register u32 nv asm("r1");
          u32 fl2;
          nv = 1;
          (p->s).work[3] = nv;
          fl2 = (p->s).flags;
          nv &= ~(fl2 >> 4);
          if (nv != 0) {
            u32 res = 0x10;
            res |= fl2;
            (p->s).flags = res;
          } else {
            u32 res2 = 0xEF;
            res2 &= fl2;
            (p->s).flags = res2;
          }
          *((u8*)p + 0x4c) = nv;
          {
            register u8* oa asm("r3");
            u32 sh4;
            s32 ov;
            s32 m11;
            oa = (u8*)p + 0x4a;
            sh4 = nv << 4;
            ov = *oa;
            m11 = -0x11;
            m11 &= ov;
            m11 |= sh4;
            *oa = m11;
          }
        }
      stchk7:
        if ((p->s).motion.state != 3) {
          break;
        }
        (p->s).mode[2]++;
        break;
      }
      case 8:
        SetMotion(&p->s, MOTION(0xAC, 0x01));
        (p->s).mode[2]++;
        FALLTHROUGH;
      case 9:
        UpdateEntityAnim(&p->s);
        if (*((u8*)p + 0xb9) != 2) {
          break;
        }
        (p->s).mode[2]++;
        break;
      case 10:
        SetMotion(&p->s, MOTION(0xAC, 0x02));
        (p->s).mode[2]++;
        FALLTHROUGH;
      case 11:
        UpdateEntityAnim(&p->s);
        if ((p->s).motion.state != 3) {
          break;
        }
        (p->s).mode[2]++;
        break;
      case 12:
        (p->s).d.x = -0x600;
        (p->s).d.y = -0x700;
        SetMotion(&p->s, MOTION(0xAC, 0x03));
        (p->s).mode[2]++;
        FALLTHROUGH;
      case 13: {
        {
          s32 vy = (p->s).d.y + 0x20;
          (p->s).d.y = vy;
          {
            s32 lim = 0xE0 << 3;
            if (vy > lim) {
              (p->s).d.y = lim;
            }
          }
        }
        {
          s32 cx = (p->s).coord.x;
          cx += (p->s).d.x;
          (p->s).coord.x = cx;
        }
        {
          s32 cy = (p->s).coord.y;
          cy += (p->s).d.y;
          (p->s).coord.y = cy;
        }
        UpdateEntityAnim(&p->s);
        cmpb = ((p->s).unk_28)->coord.y + -0x7800;
      cmptail28:
        cmpa = (p->s).coord.y;
      cmptail:
        if (cmpa >= cmpb) {
          break;
        }
        (p->s).mode[2]++;
        break;
      }
      case 14: {
        (p->s).renderPrio = 0x19;
        SetMotion(&p->s, MOTION(0xAB, 0x1B));
        SetDDP(&p->body, (const struct Collision*)0x8367E40);
        (p->s).work[2] = 0x20;
        {
          register u32 z asm("r2");
          asm volatile("mov %0, #0" : "=r"(z));
          (p->s).flags &= 0xEF;
          *((u8*)p + 0x4c) = z;
          {
            u8* oa = (u8*)p + 0x4a;
            s32 ov = *oa;
            s32 m11 = -0x11;
            m11 &= ov;
            *oa = m11;
          }
        }
        {
          register struct Entity* q asm("r5");
          register s32 kA asm("r4");
          s32 qx;
          q = (p->s).unk_28;
          qx = q->coord.x;
          kA = -0xA000;
          asm("" : "+r"(kA));
          (p->s).coord.x = qx + kA;
          {
            s32 t = qx + -0x8F00;
            s32 n = q->coord.x - t;
            (p->s).d.x = n;
            (p->s).d.x = n / (p->s).work[2];
          }
          {
            register s32 qy asm("r1");
            qy = q->coord.y;
            (p->s).coord.y = qy + kA;
            vb = qy + -0x7500;
            va = q->coord.y;
          }
        }
      divtail:
        {
          s32 t2 = va - vb;
          (p->s).d.y = t2;
          (p->s).d.y = t2 / (p->s).work[2];
        }
        (p->s).mode[2]++;
        FALLTHROUGH;
      }
      case 15:
      lastcase:
        UpdateEntityAnim(&p->s);
        {
          s32 cx = (p->s).coord.x;
          cx += (p->s).d.x;
          (p->s).coord.x = cx;
        }
        {
          s32 cy = (p->s).coord.y;
          cy += (p->s).d.y;
          (p->s).coord.y = cy;
        }
        {
          u32 w = (p->s).work[2];
          if (w != 0) {
            w--;
            (p->s).work[2] = w;
            if ((w << 24) != 0) {
              break;
            }
          }
        }
        *((u8*)p + 0xb9) = 3;
        SET_ENEMY_ROUTINE(p, 2);
        break;
    }
  }
}

void FUN_0807e5f0(struct Enemy* p);
void FUN_0807ead8(struct Enemy* p);
void FUN_0807f644(struct Enemy* p);

static const EnemyFunc sUpdates1[3] = {
    (void*)FUN_0807e5f0,
    (void*)FUN_0807ead8,
    (void*)FUN_0807f644,
};

void FUN_0807e5f4(struct Enemy* p);
void FUN_0807eadc(struct Enemy* p);
void FUN_0807f648(struct Enemy* p);

static const EnemyFunc sUpdates2[3] = {
    (void*)FUN_0807e5f4,
    (void*)FUN_0807eadc,
    (void*)FUN_0807f648,
};

void nop_0807fd1c(struct Body* body, Coords32* c1, Coords32* c2) {}

// 0x08367D98
static const struct Collision sCollisions[9] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(5), -PIXEL(17), PIXEL(58), PIXEL(36)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {-PIXEL(26), -PIXEL(16), PIXEL(20), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(5), -PIXEL(36), PIXEL(37), PIXEL(56)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {-PIXEL(24), -PIXEL(69), PIXEL(22), PIXEL(23)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(5), -PIXEL(33), PIXEL(61), PIXEL(36)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {-PIXEL(22), -PIXEL(27), PIXEL(22), PIXEL(23)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(5), -PIXEL(17), PIXEL(55), PIXEL(23)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {-PIXEL(5), -PIXEL(17), PIXEL(55), PIXEL(23)},
    },
};
