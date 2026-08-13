#include "boss/omega1.h"
#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "quake.h"
#include "camera.h"
#include "physics.h"
#include "stagerun.h"

struct Projectile* FUN_080ac818(struct Coord* c, s32 r1, u8 r2, struct Enemy* r3);
void FUN_080ac8e8(struct Coord* c, s32 r1, u8 r2, struct Enemy* r3);
struct Projectile* FUN_080ac950(struct Coord* c, s32 prevX, s32 prevY, struct Entity* e);
static const struct Collision sCollisions[7];

void OmegaGoldHand_Init(struct Enemy* p);
void OmegaGoldHand_Update(struct Enemy* p);
void OmegaGoldHand_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gOmegaGoldHandRoutine = {
    [ENTITY_INIT] =      (void*)OmegaGoldHand_Init,
    [ENTITY_UPDATE] =    (void*)OmegaGoldHand_Update,
    [ENTITY_DIE] =       (void*)OmegaGoldHand_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};




void FUN_08082e38(struct Enemy* p);
void FUN_08084348(struct Enemy* p);
void FUN_08083ff4(struct Enemy* p);
void FUN_08083644(struct Enemy* p);
// clang-format on

struct Entity* FUN_08082b58(Coords32* c, bool8 isLeftHand, Omega1* omega) {
  struct Entity* p = (struct Entity*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_OMEGA1G_HAND);
    p->coord = *c;
    p->work[0] = isLeftHand, p->work[1] = 0;
    p->unk_28 = (void*)omega;
  }
  return p;
}

struct Entity* FUN_08082bbc(struct Entity* q, u8 kind) {
  struct Entity* p = (struct Entity*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_OMEGA1G_HAND);
    p->work[0] = kind, p->work[1] = 1;
    p->unk_28 = q;
  }
  return p;
}

INCASM("asm/enemy/omega1g_hand_a.inc");

void FUN_08082e38(struct Enemy* p0) {
  register struct Enemy* p asm("r5");
  p = p0;
  switch ((p->s).mode[2]) {
    case 0: {
      register u32 six asm("r6");
      six = (p->s).work[0];
      if (six == 1) {
        register s32 z4 asm("r4");
        {
          register u8 fl asm("r1");
          register s32 g asm("r0");
          fl = (p->s).flags;
          g = 1;
          g |= fl;
          z4 = 0;
          fl = 0xEF;
          g &= fl;
          (p->s).flags = g;
        }
        *((u8*)p + 0x4c) = z4;
        {
          register u8* oa asm("r2");
          register u8 ov asm("r1");
          register s32 m asm("r0");
          oa = (u8*)p + 0x4a;
          ov = *oa;
          m = 0x11;
          m = -m;
          m &= ov;
          *oa = m;
          {
            register u8 fl2 asm("r1");
            register u8 g2 asm("r0");
            fl2 = (p->s).flags;
            asm("" : "+r"(fl2));
            g2 = 0xDF;
            g2 &= fl2;
            (p->s).flags = g2;
          }
          *((u8*)p + 0x4d) = z4;
          {
            register u8 ov2 asm("r1");
            register s32 m2 asm("r0");
            ov2 = *oa;
            m2 = 0x21;
            m2 = -m2;
            m2 &= ov2;
            *oa = m2;
          }
        }
        *((u8*)p + 0x24) = z4;
        SetMotion(&p->s, 0x0901);
        (p->s).d.y = z4;
        (p->s).mode[3] = six;
        (p->s).mode[2] = six;
      } else {
        register s32 z2 asm("r2");
        {
          register u8 fl asm("r1");
          register s32 g asm("r0");
          fl = (p->s).flags;
          g = 1;
          g |= fl;
          z2 = 0;
          fl = 0xEF;
          g &= fl;
          (p->s).flags = g;
        }
        *((u8*)p + 0x4c) = z2;
        {
          register u8* oa asm("r3");
          register u8 ov asm("r1");
          register s32 m asm("r0");
          oa = (u8*)p + 0x4a;
          ov = *oa;
          m = 0x11;
          m = -m;
          m &= ov;
          *oa = m;
          {
            register u8 fl2 asm("r1");
            register u8 g2 asm("r0");
            fl2 = (p->s).flags;
            asm("" : "+r"(fl2));
            g2 = 0xDF;
            g2 &= fl2;
            (p->s).flags = g2;
          }
          *((u8*)p + 0x4d) = z2;
          {
            register u8 ov2 asm("r1");
            register s32 m2 asm("r0");
            ov2 = *oa;
            m2 = 0x21;
            m2 = -m2;
            m2 &= ov2;
            *oa = m2;
          }
        }
        *((u8*)p + 0x24) = z2;
        {
          struct Entity* q = *(struct Entity**)((u8*)(p->s).unk_28 + 0xc8);
          if (*((u8*)q + 0xc0) == 1) {
            (p->s).coord = q->coord;
            (p->s).coord.y += -0x3200;
          } else if (*((u8*)p + 0xc0) == 0) {
            (p->s).coord = q->coord;
            (p->s).coord.y += -0x2200;
            (p->s).coord.x += -0x1E00;
          }
        }
        SetMotion(&p->s, 0x90 << 4);
        (p->s).mode[2] = 0x14;
      }
      UpdateEntityAnim(&p->s);
      EXIT_BODY(p);
      (p->s).d.x = 0;
      (p->s).d.y = 0;
      (p->s).work[2] = 0x14;
      break;
    }
    case 1:
      (p->s).work[2] = 0x14;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 2:
    case 11: {
      s32 dy = (p->s).d.y + 4;
      (p->s).d.y = dy;
      if (dy > 0xE0 << 3) {
        (p->s).d.y = 0xE0 << 3;
      }
      (p->s).coord.y += (p->s).d.y;
      {
        s32 t = (p->s).work[2] - 1;
        (p->s).work[2] = t;
        if ((t << 24) != 0) {
          break;
        }
      }
      (p->s).mode[2]++;
      break;
    }
    case 3: {
      if ((p->s).work[0] != 1) {
        UpdateEntityAnim(&p->s);
        break;
      }
      {
        s32 dy = (p->s).d.y + 0x20;
        (p->s).d.y = dy;
        if (dy > 0xE0 << 3) {
          (p->s).d.y = 0xE0 << 3;
        }
      }
      {
        s32 ny = (p->s).coord.y + (p->s).d.y;
        s32 r;
        (p->s).coord.y = ny;
        r = PushoutToUp1((p->s).coord.x, ny + (0xC0 << 5));
        if (r == 0) {
          UpdateEntityAnim(&p->s);
          break;
        }
        (p->s).coord.y += r;
      }
      (p->s).d.y = -0x120;
      AppendQuake(4, &(p->s).coord);
      PlaySound(0x91);
      (p->s).work[3] = 0xA;
      *((u8*)p + 0x24) = 0xA;
      (p->s).mode[2] = 0x1E;
      UpdateEntityAnim(&p->s);
      break;
    }
    case 10:
      (p->s).work[2] = 0xC;
      (p->s).mode[2]++;
      {
        s32 dy = (p->s).d.y + 4;
        (p->s).d.y = dy;
        if (dy > 0xE0 << 3) {
          (p->s).d.y = 0xE0 << 3;
        }
      }
      (p->s).coord.y += (p->s).d.y;
      {
        s32 t = (p->s).work[2] - 1;
        (p->s).work[2] = t;
        if ((t << 24) != 0) {
          break;
        }
      }
      (p->s).mode[2]++;
      break;
    case 12:
      UpdateEntityAnim(&p->s);
      if (*((u8*)p + 0x73) != 3) {
        break;
      }
      {
        s32 t12 = (p->s).work[2] - 1;
        (p->s).work[2] = t12;
        if ((t12 << 24) != 0) {
          break;
        }
      }
      (p->s).mode[2]++;
      break;
    case 13: {
      struct Entity* q3 = *(struct Entity**)((u8*)(p->s).unk_28 + 0xc8);
      (p->s).coord = q3->coord;
      (p->s).coord.x += -0x2E00;
      (p->s).coord.y += -0x1000;
      SetMotion(&p->s, 0x90 << 4);
      UpdateEntityAnim(&p->s);
      (p->s).mode[2] = 0x14;
      break;
    }
    case 15: {
      UpdateEntityAnim(&p->s);
      if (*((u8*)p + 0x73) != 3) {
        break;
      }
      {
        u32 w2 = (p->s).work[2];
        if (w2 != 0) {
          w2--;
          (p->s).work[2] = w2;
          if ((w2 << 24) != 0) {
            break;
          }
        }
      }
      {
        register u32 w3 asm("r1");
        w3 = (p->s).work[3];
        if (w3 <= 0xFB) {
          register u32 t3 asm("r0");
          t3 = w3 + 3;
          (p->s).work[3] = t3;
        } else {
          u32 t15 = 0xFF;
          t15 |= w3;
          (p->s).work[3] = t15;
          (p->s).mode[2]++;
        }
      }
      {
        register u32 w3b asm("r1");
        register u8* a24 asm("r0");
        w3b = (p->s).work[3];
        a24 = (u8*)p + 0x24;
        *a24 = w3b;
      }
      break;
    }
    case 16: {
      register s32 z2b asm("r2");
      SetMotion(&p->s, 0x90 << 4);
      z2b = 0;
      {
        register u8 fl asm("r1");
        register u8 g asm("r0");
        fl = (p->s).flags;
        asm("" : "+r"(fl));
        g = 0xEF;
        g &= fl;
        (p->s).flags = g;
      }
      *((u8*)p + 0x4c) = z2b;
      {
        register u8* oa asm("r2");
        register u8 ov asm("r1");
        register s32 m asm("r0");
        oa = (u8*)p + 0x4a;
        ov = *oa;
        m = 0x11;
        m = -m;
        m &= ov;
        *oa = m;
      }
      (p->s).work[2] = 0xA;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 17:
      UpdateEntityAnim(&p->s);
      {
        u32 w2 = (p->s).work[2];
        if (w2 != 0) {
          w2--;
          (p->s).work[2] = w2;
          if ((w2 << 24) == 0) {
            goto set14;
          }
          break;
        }
      }
    set14:
      (p->s).mode[2] = 0x14;
      break;
    case 20:
      (p->s).work[2] = 0xC;
      asm volatile("" ::"r"(p));
      asm volatile("" ::"r"(p));
      asm volatile("" ::"r"(p));
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 21: {
      s32 t = (p->s).work[2] - 1;
      (p->s).work[2] = t;
      if ((t << 24) != 0) {
        break;
      }
      (p->s).mode[2]++;
      break;
    }
    case 22: {
      UpdateEntityAnim(&p->s);
      if ((p->s).work[0] != 0) {
        UpdateEntityAnim(&p->s);
        break;
      }
      {
        s32 dy = (p->s).d.y + 0x10;
        (p->s).d.y = dy;
        if (dy > 0xE0 << 3) {
          (p->s).d.y = 0xE0 << 3;
        }
      }
      {
        s32 ny = (p->s).coord.y + (p->s).d.y;
        s32 r;
        (p->s).coord.y = ny;
        r = PushoutToUp1((p->s).coord.x, ny + (0xC0 << 5));
        if (r == 0) {
          UpdateEntityAnim(&p->s);
          break;
        }
        (p->s).coord.y += r;
      }
      (p->s).d.y = -0x1C0;
      AppendQuake(4, &(p->s).coord);
      PlaySound(0x91);
      (p->s).work[3] = 0xF3;
      *((u8*)p + 0x24) = 0xF3;
      (p->s).mode[2] = 0x1E;
      UpdateEntityAnim(&p->s);
      break;
    }
    case 30: {
      (p->s).work[2]++;
      {
        s32 dy = (p->s).d.y + 0xC;
        (p->s).d.y = dy;
        if (dy > 0xE0 << 3) {
          (p->s).d.y = 0xE0 << 3;
        }
      }
      (p->s).coord.y += (p->s).d.y;
      if ((p->s).work[0] == 0) {
        if ((u8)((p->s).work[2] % 3) == 0) {
          (p->s).work[3]--;
        }
      } else {
        if ((u8)((p->s).work[2] % 3) == 0) {
          (p->s).work[3]++;
        }
      }
      {
        register u32 w3c asm("r1");
        register u8* a24b asm("r0");
        w3c = (p->s).work[3];
        a24b = (u8*)p + 0x24;
        *a24b = w3c;
      }
      if (Camera_GetDistance(&gStageRun.vm.camera, &(p->s).coord) > (u32)(0x80 << 7)) {
        (p->s).mode[1] = 1;
        (p->s).mode[2] = 0;
      }
      break;
    }
  }
}

INCASM("asm/enemy/omega1g_hand_b.inc");

void FUN_08083644(struct Enemy* p0) {
  register struct Enemy* p asm("r5");
  struct Coord c;
  p = p0;
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).unk_coord.y = ((p->s).unk_28)->unk_coord.y;
      (p->s).d.y = 0;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1: {
      s32 d0;
      s32 lim;
      s32 ny;
      UpdateEntityAnim(&p->s);
      d0 = (p->s).d.y - 0x40;
      (p->s).d.y = d0;
      if (d0 < -0x300) {
        (p->s).d.y = -0x300;
      }
      ny = (p->s).coord.y + (p->s).d.y;
      (p->s).coord.y = ny;
      lim = (p->s).unk_coord.y + -0x7A00;
      if (ny >= lim) {
        break;
      }
      (p->s).coord.y = lim;
      (p->s).work[2] = 0x14;
      goto bump;
    }
    case 2: {
      s32 t0 = (p->s).work[2];
      if (t0 == 0) {
        break;
      }
      t0--;
      (p->s).work[2] = t0;
      if ((t0 << 24) != 0) {
        break;
      }
      asm volatile("" ::"r"(p));
      goto bump;
    }
    case 3:
      SetDDP(&p->body, &sCollisions[1]);
      (p->s).mode[3] = 4;
      (p->s).work[2] = 0x40;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 4: {
      u32 one;
      SetMotion(&p->s, MOTION(0x09, 0x02));
      one = 1;
      (p->s).flags |= 0x10;
      {
        u8* x4c = (u8*)p + 0x4c;
        register u32 z3 asm("r4");
        z3 = 0;
        *x4c = one;
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
          u8* a = (u8*)p + 0x24;
          *a = z3;
          SetDDP((struct Body*)(a + 0x50), &sCollisions[5]);
          *(s32*)((u8*)p + 0xbc) = z3;
        }
      }
      (p->s).d.x = -0x200;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 5: {
      s32* b;
      {
        s32* a0 = (s32*)((u8*)p + 0xbc);
        s32 d0 = *a0;
        s32 lim0 = -0x7800;
        b = a0;
        asm("" : "+r"(b));
        if (d0 < lim0) {
          (p->s).d.x -= 0x40;
          if ((p->s).d.x < -0x80) {
            (p->s).d.x = -0x80;
          }
        }
      }
      *b += (p->s).d.x;
      (p->s).coord.x = *b + ((p->s).unk_28)->coord.x + -0x1300;
      UpdateEntityAnim(&p->s);
      if (*b < -0x8000) {
        if ((u8)--(p->s).mode[3] != 0) {
          (p->s).mode[2] = 6;
          break;
        }
        (p->s).mode[2] = 0x14;
        break;
      }
      {
        s32 tw = (p->s).work[2];
        if (tw == 0) {
          break;
        }
        tw--;
        (p->s).work[2] = tw;
        if ((tw << 24) != 0) {
          break;
        }
      }
      (p->s).mode[2] = 0xA;
      break;
    }
    case 6:
      SetMotion(&p->s, MOTION(0x09, 0x02));
      SetDDP(&p->body, &sCollisions[5]);
      *(s32*)((u8*)p + 0xbc) = -0x8000;
      (p->s).d.x = 0x200;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 7: {
      s32 kv;
      s32 hb;
      {
        s32* a0 = (s32*)((u8*)p + 0xbc);
        s32 d0 = *a0;
        s32 lim1 = -0x800;
        kv = (s32)a0;
        asm("" : "+r"(kv));
        if (d0 > lim1) {
          (p->s).d.x += 0x40;
          if ((p->s).d.x > 0x80) {
            (p->s).d.x = 0x80;
          }
        }
      }
      *(s32*)kv += (p->s).d.x;
      {
        s32 t0 = *(s32*)kv + ((p->s).unk_28)->coord.x;
        kv = -0x1300;
        (p->s).coord.x = t0 + kv;
      }
      hb = kv;
      UpdateEntityAnim(&p->s);
      if ((p->s).coord.x > ((p->s).unk_28)->coord.x + hb) {
        if ((u8)--(p->s).mode[3] != 0) {
          (p->s).mode[2] = 4;
          break;
        }
        (p->s).mode[2] = 0x14;
        break;
      }
      {
        s32 tw2 = (p->s).work[2];
        if (tw2 == 0) {
          break;
        }
        tw2--;
        (p->s).work[2] = tw2;
        if ((tw2 << 24) != 0) {
          break;
        }
      }
      (p->s).mode[2] = 0xA;
      break;
    }
    case 10:
      (p->s).work[2] = 0x1E;
      if ((p->s).mode[3] & 1) {
        c.x = (p->s).coord.x + 0x600;
      } else {
        c.x = (p->s).coord.x + -0x600;
      }
      c.y = (p->s).coord.y + 0xE00;
      PlaySound(0x12D);
      FUN_080ac818(&c, 0xFA << 1, 7, p);
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 11: {
      s32 t1 = (p->s).work[2];
      if (t1 == 0) {
        break;
      }
      t1--;
      (p->s).work[2] = t1;
      if ((t1 << 24) != 0) {
        break;
      }
      goto bump;
    }
    case 12:
      (p->s).work[2] = 0x40;
      if ((p->s).mode[3] & 1) {
        (p->s).mode[2] = 7;
      } else {
        (p->s).mode[2] = 5;
      }
      break;
    case 20: {
      SetMotion(&p->s, MOTION(0x09, 0x00));
      {
        u8* a2 = (u8*)p + 0x24;
        register u32 z asm("r4");
        z = 0;
        *a2 = z;
        SetDDP((struct Body*)(a2 + 0x50), &sCollisions[1]);
        (p->s).coord.x = ((p->s).unk_28)->coord.x + -0x1300;
        (p->s).d.y = z;
      }
      (p->s).work[2] = 0x28;
      goto bump;
    }
    case 21: {
      s32 t2 = (p->s).work[2];
      u32 z2;
      if (t2 == 0) {
        break;
      }
      t2--;
      (p->s).work[2] = t2;
      z2 = (u8)t2;
      if (z2 != 0) {
        break;
      }
      SetDDP(&p->body, &sCollisions[0]);
      (p->s).flags &= 0xEF;
      *((u8*)p + 0x4c) = z2;
      {
        u8* oa = (u8*)p + 0x4a;
        s32 ov = *oa;
        s32 m11 = -0x11;
        m11 &= ov;
        *oa = m11;
      }
      goto bump;
    }
    case 22: {
      s32 lim2;
      s32 ny2;
      UpdateEntityAnim(&p->s);
      (p->s).d.y += 0x80;
      if ((p->s).d.y > 0x300) {
        (p->s).d.y = 0x300;
      }
      ny2 = (p->s).coord.y + (p->s).d.y;
      (p->s).coord.y = ny2;
      lim2 = ((p->s).unk_28)->coord.y + -0x3A00;
      if (ny2 <= lim2) {
        break;
      }
      (p->s).coord.y = lim2;
    bump:
      (p->s).mode[2]++;
      break;
    }
    case 23:
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 24:
      (p->s).coord.y = ((p->s).unk_28)->coord.y + -0x3A00;
      UpdateEntityAnim(&p->s);
      if (((p->s).unk_28)->mode[1] != 5) {
        (p->s).mode[1] = 2;
        (p->s).mode[2] = 0;
      }
      break;
  }
}

INCASM("asm/enemy/omega1g_hand_c.inc");

void FUN_08083ff4(struct Enemy* p) {
  struct Coord c;
  s32* b;
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).d.y = 0;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1: {
      s32 d0;
      s32 lim;
      UpdateEntityAnim(&p->s);
      d0 = (p->s).d.y - 0x40;
      (p->s).d.y = d0;
      if (d0 < -0x300) {
        (p->s).d.y = -0x300;
      }
      (p->s).coord.y += (p->s).d.y;
      lim = ((p->s).unk_28)->coord.y + -0x7A00;
      if ((p->s).coord.y < lim) {
        (p->s).coord.y = lim;
        (p->s).work[2] = 0x14;
        goto bump;
      }
      break;
    }
    case 2:
      if ((p->s).work[2] == 0) {
        break;
      }
      if ((u8)--(p->s).work[2] != 0) {
        break;
      }
      goto bump;
    case 3:
      (p->s).mode[3] = 4;
      (p->s).work[2] = 0x40;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 4: {
      u32 one;
      SetMotion(&p->s, MOTION(SM009_OMEGA_HAND, 2));
      one = 1;
      (p->s).flags |= 0x10;
      {
        u8* x4c = (u8*)p + 0x4c;
        register u32 z3 asm("r3");
        z3 = 0;
        *x4c = one;
        {
          register u8* oa asm("r4");
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
          u8* a = (u8*)p + 0x24;
          *a = z3;
          a += 0x98;
          *(s32*)a = z3;
        }
      }
      (p->s).d.x = -0x200;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 5: {
      register s32 v0 asm("r2");
      register s32 k0 asm("r1");
      s32* a0 = (s32*)((u8*)p + 0xbc);
      v0 = *a0;
      k0 = -0x7800;
      b = a0;
      if (v0 < k0) {
        (p->s).d.x -= 0x40;
        if ((p->s).d.x < -0x80) {
          (p->s).d.x = -0x80;
        }
      }
      *b += (p->s).d.x;
      (p->s).coord.x = *b + ((p->s).unk_28)->coord.x + -0x1300;
      UpdateEntityAnim(&p->s);
      if (*b < -0x8000) {
        if ((u8)--(p->s).mode[3] != 0) {
          (p->s).mode[2] = 6;
          break;
        }
        (p->s).mode[2] = 0x14;
        break;
      }
      goto Lcd;
    }
    case 6:
      SetMotion(&p->s, MOTION(SM009_OMEGA_HAND, 2));
      *(s32*)((u8*)p + 0xbc) = -0x8000;
      (p->s).d.x = 0x200;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 7: {
      register s32 hb asm("r4");
      register s32 v1 asm("r2");
      register s32 k1 asm("r1");
      s32* a1 = (s32*)((u8*)p + 0xbc);
      v1 = *a1;
      k1 = -0x800;
      b = a1;
      if (v1 > k1) {
        (p->s).d.x += 0x40;
        if ((p->s).d.x > 0x80) {
          (p->s).d.x = 0x80;
        }
      }
      *b += (p->s).d.x;
      {
        s32 t7 = *b + ((p->s).unk_28)->coord.x;
        hb = -0x1300;
        (p->s).coord.x = t7 + hb;
      }
      UpdateEntityAnim(&p->s);
      if ((p->s).coord.x > ((p->s).unk_28)->coord.x + hb) {
        if ((u8)--(p->s).mode[3] != 0) {
          (p->s).mode[2] = 4;
          break;
        }
        (p->s).mode[2] = 0x14;
        break;
      }
    Lcd:
      if ((p->s).work[2] == 0) {
        break;
      }
      if ((u8)--(p->s).work[2] != 0) {
        break;
      }
      (p->s).mode[2] = 0xA;
      break;
    }
    case 10:
      (p->s).work[2] = 0x1E;
      if ((p->s).mode[3] & 1) {
        c.x = (p->s).coord.x + 0x600;
      } else {
        c.x = (p->s).coord.x + -0x600;
      }
      c.y = (p->s).coord.y + 0xE00;
      FUN_080ac8e8(&c, 0xA0 << 1, 7, p);
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 11:
      if ((p->s).work[2] == 0) {
        break;
      }
      if ((u8)--(p->s).work[2] != 0) {
        break;
      }
      asm volatile("");
      goto bump;
    case 12:
      (p->s).work[2] = 0x40;
      if ((p->s).mode[3] & 1) {
        (p->s).mode[2] = 7;
      } else {
        (p->s).mode[2] = 5;
      }
      break;
    case 20: {
      u32 z;
      u8* a24;
      SetMotion(&p->s, MOTION(SM009_OMEGA_HAND, 0));
      a24 = (u8*)p + 0x24;
      z = 0;
      *a24 = z;
      (p->s).coord.x = ((p->s).unk_28)->coord.x + -0x1300;
      (p->s).d.y = z;
      (p->s).work[2] = 0x28;
      goto bump;
    }
    case 21: {
      u32 z2;
      if ((p->s).work[2] == 0) {
        break;
      }
      z2 = --(p->s).work[2];
      if ((u8)z2 != 0) {
        break;
      }
      (p->s).flags &= 0xEF;
      *((u8*)p + 0x4c) = z2;
      {
        u8* oa = (u8*)p + 0x4a;
        s32 ov = *oa;
        s32 m11 = -0x11;
        m11 &= ov;
        *oa = m11;
      }
      goto bump;
    }
    case 22: {
      s32 lim2;
      UpdateEntityAnim(&p->s);
      (p->s).d.y += 0x80;
      if ((p->s).d.y > 0x300) {
        (p->s).d.y = 0x300;
      }
      (p->s).coord.y += (p->s).d.y;
      lim2 = ((p->s).unk_28)->coord.y + -0x3A00;
      if ((p->s).coord.y > lim2) {
        (p->s).coord.y = lim2;
      bump:
        (p->s).mode[2]++;
      }
      break;
    }
    case 23:
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 24: {
      u32 z4;
      u8* ac1;
      UpdateEntityAnim(&p->s);
      ac1 = &p->buffer[0xd];
      z4 = 0;
      *ac1 = z4;
      (p->s).mode[1] = 2;
      (p->s).mode[2] = z4;
      break;
    }
  }
}

void FUN_08084348(struct Enemy* p0) {
  register struct Enemy* p asm("r5");
  struct Coord c;
  p = p0;
  switch ((p->s).mode[2]) {
    case 0: {
      register u32 one asm("r3");
      register u32 z0 asm("r2");
      SetMotion(&p->s, 0x902);
      one = 1;
      (p->s).flags |= 0x10;
      *((u8*)p + 0x4c) = one;
      {
        register u8* oa asm("r4");
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
        (p->s).flags |= 0x20;
        {
          u8* x4d = (u8*)p + 0x4d;
          asm volatile("mov %0, #0" : "=r"(z0));
          *x4d = one;
        }
        {
          register s32 k2 asm("r3");
          k2 = 0x20;
          {
            s32 ov2 = *oa;
            s32 m21 = -0x21;
            m21 &= ov2;
            m21 |= k2;
            *oa = m21;
          }
        }
      }
      (p->s).work[3] = z0;
      *((u8*)p + 0x24) = z0;
      (p->s).d.y = z0;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 ny;
      s32 lim;
      {
        u32 t = (p->s).work[3];
        if (t <= 0x3F) {
          (p->s).work[3] = t + 4;
        }
      }
      {
        u32 mv = ~(p->s).work[3];
        *((u8*)p + 0x24) = mv;
      }
      UpdateEntityAnim(&p->s);
      (p->s).d.y += 0x20;
      if ((p->s).d.y > 0x300) {
        (p->s).d.y = 0x300;
      }
      ny = (p->s).coord.y + (p->s).d.y;
      (p->s).coord.y = ny;
      lim = ((p->s).unk_28)->coord.y + -0x200;
      if (ny <= lim) {
        break;
      }
      (p->s).coord.y = lim;
      (p->s).work[2] = 0x14;
      goto bump;
    }
    case 2: {
      s32 t0 = (p->s).work[2];
      if (t0 == 0) {
        break;
      }
      t0--;
      (p->s).work[2] = t0;
      if ((t0 << 24) != 0) {
        break;
      }
      asm volatile("" ::"r"(p));
      goto bump;
    }
    case 3:
      (p->s).mode[3] = 4;
      (p->s).work[2] = 0x50;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 4: {
      register u32 one asm("r2");
      SetMotion(&p->s, 0x902);
      one = 1;
      (p->s).flags |= 0x10;
      {
        u8* x4c = (u8*)p + 0x4c;
        register u32 z3 asm("r3");
        z3 = 0;
        *x4c = one;
        {
          register u8* oa asm("r4");
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
        *(s32*)((u8*)p + 0xbc) = z3;
      }
      (p->s).d.y = -0x100;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 5: {
      s32* b;
      {
        s32* a0 = (s32*)((u8*)p + 0xbc);
        s32 d0 = *a0;
        s32 lim0 = -0x2E80;
        b = a0;
        asm("" : "+r"(b));
        if (d0 < lim0) {
          (p->s).d.y += 0x40;
          if ((p->s).d.y > -0x40) {
            (p->s).d.y = -0x40;
          }
        }
      }
      *b += (p->s).d.y;
      (p->s).coord.y = *b + ((p->s).unk_28)->coord.y + -0x200;
      UpdateEntityAnim(&p->s);
      if (*b >= -0x3000) {
        goto cnt57;
      }
      if ((u8)--(p->s).mode[3] != 0) {
        (p->s).mode[2] = 6;
        break;
      }
      goto m14;
    }
    case 6:
      SetMotion(&p->s, 0x902);
      *(s32*)((u8*)p + 0xbc) = -0x3000;
      (p->s).d.y = 0x80 << 1;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 7: {
      register s32* b7 asm("r4");
      {
        register s32* a0 asm("r0");
        register s32 d0 asm("r2");
        s32 lim1;
        a0 = (s32*)((u8*)p + 0xbc);
        d0 = *a0;
        lim1 = -0x180;
        asm("add %0, %1, #0" : "=r"(b7) : "r"(a0));
        if (d0 > lim1) {
          (p->s).d.y -= 0x40;
          if ((p->s).d.y <= 0x3F) {
            (p->s).d.y = 0x40;
          }
        }
      }
      *b7 += (p->s).d.y;
      {
        register s32 k200 asm("r4");
        s32 t7 = *b7 + ((p->s).unk_28)->coord.y;
        k200 = -0x200;
        asm("" : "+r"(k200));
        (p->s).coord.y = t7 + k200;
        UpdateEntityAnim(&p->s);
        if ((p->s).coord.y <= ((p->s).unk_28)->coord.y + k200) {
          goto cnt57;
        }
      }
      if ((u8)--(p->s).mode[3] != 0) {
        (p->s).mode[2] = 4;
        break;
      }
    m14:
      (p->s).mode[2] = 0x14;
      break;
    cnt57: {
      s32 tw = (p->s).work[2];
      if (tw == 0) {
        break;
      }
      tw--;
      (p->s).work[2] = tw;
      if ((tw << 24) != 0) {
        break;
      }
      (p->s).mode[2] = 0xA;
      break;
    }
    }
    case 10:
      (p->s).work[2] = 0x3C;
      c.x = (p->s).coord.x + -0x1200;
      c.y = (p->s).coord.y;
      FUN_080ac950(&c, 0x80 << 2, 7, (struct Entity*)p);
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 11: {
      s32 t1 = (p->s).work[2];
      if (t1 == 0) {
        break;
      }
      t1--;
      (p->s).work[2] = t1;
      if ((t1 << 24) != 0) {
        break;
      }
      goto bump;
    }
    case 12:
      (p->s).work[2] = 0x40;
      if ((p->s).mode[3] & 1) {
        (p->s).mode[2] = 7;
      } else {
        (p->s).mode[2] = 5;
      }
      break;
    case 20: {
      register u32 z2 asm("r2");
      SetMotion(&p->s, 0x901);
      z2 = 0;
      (p->s).flags &= 0xEF;
      *((u8*)p + 0x4c) = z2;
      {
        register u8* oa2 asm("r3");
        oa2 = (u8*)p + 0x4a;
        {
          s32 ov3 = *oa2;
          s32 m11b = -0x11;
          m11b &= ov3;
          *oa2 = m11b;
        }
        (p->s).flags &= 0xDF;
        *((u8*)p + 0x4d) = z2;
        {
          s32 ov4 = *oa2;
          s32 m21b = -0x21;
          m21b &= ov4;
          *oa2 = m21b;
        }
      }
      *((u8*)p + 0x24) = z2;
      (p->s).coord.x = ((p->s).unk_28)->coord.x + (0xA8 << 5);
      (p->s).d.y = z2;
      (p->s).work[2] = 0x32;
      goto bump;
    }
    case 21: {
      s32 t2 = (p->s).work[2];
      if (t2 == 0) {
        break;
      }
      t2--;
      (p->s).work[2] = t2;
      if ((t2 << 24) != 0) {
        break;
      }
      asm volatile(" " ::"r"(p));
      goto bump;
    }
    case 22: {
      s32 ny2;
      s32 lim2;
      UpdateEntityAnim(&p->s);
      (p->s).d.y -= 4;
      if ((p->s).d.y < -0xA0) {
        (p->s).d.y = -0xA0;
      }
      ny2 = (p->s).coord.y + (p->s).d.y;
      (p->s).coord.y = ny2;
      lim2 = ((p->s).unk_28)->coord.y + -0x3800;
      if (ny2 >= lim2) {
        break;
      }
      (p->s).coord.y = lim2;
    bump:
      (p->s).mode[2]++;
      break;
    }
    case 23:
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 24: {
      register u32 z24 asm("r1");
      UpdateEntityAnim(&p->s);
      {
        u8* ac1 = (u8*)p + 0xc1;
        z24 = 0;
        *ac1 = z24;
      }
      (p->s).mode[1] = 2;
      (p->s).mode[2] = z24;
      break;
    }
  }
}

INCASM("asm/enemy/omega1g_hand_d.inc");

void FUN_08083284(struct Enemy* p);
void FUN_080833c8(struct Enemy* p);
void FUN_0808340c(struct Enemy* p);
void FUN_080835b4(struct Enemy* p);
void FUN_08083640(struct Enemy* p);
void FUN_08083e14(struct Enemy* p);

// clang-format off
static const EnemyFunc PTR_ARRAY_08368188[6] = {
    FUN_08083284,
    FUN_080833c8,
    FUN_0808340c,
    FUN_080835b4,
    FUN_08083640,
    FUN_08083e14,
};
// clang-format on

void FUN_08083eb0(struct Enemy* p);
void FUN_08083ff0(struct Enemy* p);
void FUN_080846fc(struct Enemy* p);

// clang-format off
static const EnemyFunc PTR_ARRAY_083681a0[6] = {
    FUN_080846fc,
    FUN_080846fc,
    FUN_08083eb0,
    FUN_080846fc,
    FUN_08083ff0,
    FUN_080846fc,
};
// clang-format on

void FUN_08083288(struct Enemy* p);
void FUN_080833cc(struct Enemy* p);
void FUN_08083428(struct Enemy* p);
void FUN_080835b8(struct Enemy* p);
void FUN_08083644(struct Enemy* p);
void FUN_08083e18(struct Enemy* p);

// clang-format off
static const EnemyFunc PTR_ARRAY_083681b8[6] = {
    FUN_08083288,
    FUN_080833cc,
    FUN_08083428,
    FUN_080835b8,
    FUN_08083644,
    FUN_08083e18,
};
// clang-format on

void FUN_08083328(struct Enemy* p);
void FUN_080833ec(struct Enemy* p);
void FUN_080834fc(struct Enemy* p);
void FUN_080835fc(struct Enemy* p);
void FUN_08083a04(struct Enemy* p);
void FUN_08083e68(struct Enemy* p);

// clang-format off
static const EnemyFunc PTR_ARRAY_083681d0[6] = {
    FUN_08083328,
    FUN_080833ec,
    FUN_080834fc,
    FUN_080835fc,
    FUN_08083a04,
    FUN_08083e68,
};
// clang-format on

void FUN_08083ec4(struct Enemy* p);
void FUN_08083ff4(struct Enemy* p);
void FUN_08084700(struct Enemy* p);

// clang-format off
static const EnemyFunc PTR_ARRAY_083681e8[6] = {
    FUN_08084700,
    FUN_08084700,
    FUN_08083ec4,
    FUN_08084700,
    FUN_08083ff4,
    FUN_08084700,
};
// clang-format on

void FUN_08083f4c(struct Enemy* p);
void FUN_08084348(struct Enemy* p);

// clang-format off
static const EnemyFunc PTR_ARRAY_08368200[6] = {
    FUN_08084700,
    FUN_08084700,
    FUN_08083f4c,
    FUN_08084700,
    FUN_08084348,
    FUN_08084700,
};
// clang-format on

void FUN_08082e38(struct Enemy* p);
void FUN_08083258(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_08368218[2] = {
    FUN_08082e38,
    FUN_08083258,
};

// --------------------------------------------

static const struct Collision sCollisions[7] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(1), PIXEL(24), PIXEL(43)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(1), PIXEL(22), PIXEL(41)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(1), PIXEL(24), PIXEL(43)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(1), PIXEL(22), PIXEL(41)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(1), PIXEL(24), PIXEL(43)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(4), PIXEL(2), PIXEL(30), PIXEL(40)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(4), PIXEL(2), PIXEL(32), PIXEL(42)},
    },
};
