#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "zero.h"
#include "story.h"
#include "score.h"
#include "physics.h"
#include "projectile.h"
#include "vfx.h"


typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 buffer[12];         // 0xB4
  void* enti_c0;         // 0xC0, Entity*
} Petatria;
static_assert(sizeof(Petatria) == sizeof(struct Enemy));

void Petatria_Update(Petatria* p);
struct Entity* FUN_080c4914(Coords32* c, u8 kind, motion_t m, u32 val);

void nop_0809127c(Petatria* p);
void FUN_0809118c(Petatria* p, struct Coord* c);
bool8 FUN_080902a8(Petatria* p);
bool8 FUN_080906ec(Petatria* p);
bool8 FUN_08090b20(Petatria* p);
bool8 FUN_08090c60(Petatria* p);
bool8 FUN_08090da4(Petatria* p);
bool8 FUN_08090edc(Petatria* p);
bool8 FUN_08091068(Petatria* p);
bool8 FUN_08091150(Petatria* p);
bool8 FUN_08091168(Petatria* p);
bool8 FUN_08091170(Petatria* p);
void FUN_08091154(Petatria* p);
void FUN_0809116c(Petatria* p);
void FUN_08091174(Petatria* p);


static const struct Collision sCollisions[12];
Petatria* Unused_CreatePetatria(Coords32* c, u8 mode) {
  Petatria* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_PETATRIA);
    p->coord = *c;
    p->work[0] = mode;
  }
  return p;
}

void Petatria_Init(Petatria* p) {
  register s32 z asm("r3");
  register s32 z2 asm("r2");
  register s32 m asm("r5");
  register struct Body* body asm("r4");
  const struct Collision* col;
  InitNonAffineMotion((struct Entity*)p);
  {
    register s32 fl asm("r1");
    register s32 acc asm("r0");
    fl = p->flags;
    acc = DISPLAY;
    z = 0;
    asm volatile("" : "+l"(z));
    z2 = 0;
    acc |= fl;
    fl = FLIPABLE;
    acc |= fl;
    p->flags = acc;
  }
  {
    register void* fp asm("r1");
    register u8* b0 asm("r0");
    fp = (void*)nop_0809127c;
    b0 = (u8*)p + 0x74;
    *(void**)(b0 + 0x24) = fp;
    b0 += 0x4c;
    *(s32*)b0 = z2;
    b0 -= 7;
    *b0 = z2;
  }
  if (p->work[0] == 2) {
    register s32 cx asm("r2");
    register s32 px asm("r0");
    px = (pZero2->s).coord.x;
    cx = p->coord.x;
    if (cx > px) {
      px = -0xCC;
    } else {
      px = 0xCC;
    }
    p->d.x = px;
    p->coord.y = FUN_08009f6c(cx, p->coord.y);
    {
      register u8* pb8 asm("r0");
      register s32 zz asm("r2");
      pb8 = (u8*)p + 0xb8;
      zz = 0;
      *pb8 = zz;
      SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
      p->mode[1] = zz;
      p->mode[2] = zz;
      p->mode[3] = zz;
    }
  } else {
    register s32 nx asm("r0");
    register s32 off asm("r1");
    if (p->work[0] == 0) {
      *((u8*)p + 0xb8) = 1;
      nx = FUN_0800a22c(p->coord.x + -0xA00, p->coord.y);
      off = -0x2000;
    } else {
      register s32 one asm("r2");
      register u8* oa asm("r3");
      register s32 bit asm("r2");
      register s32 ov asm("r1");
      register s32 m12 asm("r0");
      *((u8*)p + 0xb8) = z2;
      one = 1;
      p->flags = 0x10 | p->flags;
      *((u8*)p + 0x4c) = one;
      oa = (u8*)p + 0x4a;
      bit = 0x10;
      ov = *oa;
      m12 = 0x11;
      m12 = -m12;
      m12 &= ov;
      m12 |= bit;
      *oa = m12;
      nx = FUN_0800a31c(p->coord.x + 0xA00, p->coord.y);
      off = 0x2000;
    }
    p->coord.x = nx + off;
    {
      register struct Entity* zp asm("r0");
      register s32 cy asm("r1");
      register s32 py asm("r0");
      zp = &pZero2->s;
      cy = p->coord.y;
      py = zp->coord.y;
      if (cy > py) {
        py = -0xCC;
      } else {
        py = 0xCC;
      }
      p->d.y = py;
    }
    {
      register s32 one2 asm("r1");
      register s32 zz2 asm("r0");
      SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
      one2 = 1;
      zz2 = 0;
      p->mode[1] = one2;
      p->mode[2] = zz2;
      p->mode[3] = zz2;
    }
  }
  m = IsFrozen((struct Entity*)p);
  if (m != 0) {
    if (p->work[0] == 2) {
      {
        register s32 fl2 asm("r1");
        register s32 c4 asm("r0");
        fl2 = p->flags;
        c4 = COLLIDABLE;
        m = 0;
        c4 |= fl2;
        p->flags = c4;
      }
      body = &p->body;
      col = (const struct Collision*)0x08369608;
    } else {
      {
        register s32 fl2 asm("r1");
        register s32 c4 asm("r0");
        fl2 = p->flags;
        c4 = COLLIDABLE;
        m = 0;
        c4 |= fl2;
        p->flags = c4;
      }
      body = &p->body;
      col = (const struct Collision*)0x08369638;
    }
    InitBody(body, col, &p->coord, 6);
    body->parent = (void*)p;
    body->fn = (void*)m;
    if (p->work[0] == 2) {
      SetMotion((struct Entity*)p, 0xfc << 7);
    } else {
      SetMotion((struct Entity*)p, 0x7E06);
    }
    UpdateEntityAnim((struct Entity*)p);
  } else {
    if (p->work[0] == 2) {
      p->flags |= COLLIDABLE;
      body = &p->body;
      col = (const struct Collision*)0x08369608;
    } else {
      p->flags |= COLLIDABLE;
      body = &p->body;
      col = (const struct Collision*)0x08369638;
    }
    InitBody(body, col, &p->coord, 6);
    body->parent = (void*)p;
    body->fn = (void*)m;
  }
  Petatria_Update(p);
}

static const EnemyFunc sUpdates1[10];
static const EnemyFunc sUpdates2[10];
bool8 FUN_08091188(Petatria* p);
void Petatria_Die(Petatria* p);

void Petatria_Update(Petatria* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    Petatria_Die(p);
    return;
  }
  (sUpdates1[p->mode[1]])((void*)p);
  FUN_08091188((void*)p);
  if (IsFrozen(p)) {
    return;
  }
  if (p->enti_c0 != NULL) {
    if (!isKilled(p->enti_c0)) {
      return;
    }
    p->enti_c0 = NULL;
  }
  (sUpdates2[p->mode[1]])((void*)p);
}

void Petatria_Die(Petatria* p) {
  if (gCurStory.s.gameflags[4] & 0x40) {
    u32 z2;
    {
      u32 fl = p->flags & 0xFE;
      z2 = 0;
      fl &= 0xFD;
      p->flags = fl;
    }
    {
      u8* w = (u8*)p + 0x8c;
      *(u32*)w = z2;
      asm("" : "+r"(w));
      w += 4;
      *(u32*)w = z2;
      asm("" : "+r"(w));
      w += 4;
      asm("" : "+r"(w));
      *(u8*)w = z2;
    }
    p->flags &= 0xFB;
    {
      u32 tbl = (u32)gEnemyFnTable;
      u32 id = (p->id) << 2;
      EntityFunc** rt = (EntityFunc**)(tbl + id);
      *(u32*)(p->mode) = 3;
      p->onUpdate = (void*)((*rt)[3]);
    }
    return;
  }
  {
    s32 m = p->mode[2];
    switch (m) {
      case 0:
        p->mode[2] = 0xA;
        {
          u8* w = (u8*)p + 0x8c;
          *(u32*)w = m;
          asm("" : "+r"(w));
          w += 4;
          *(u32*)w = m;
          asm("" : "+r"(w));
          w += 4;
          asm("" : "+r"(w));
          *(u8*)w = m;
        }
        p->flags &= 0xFB;
        p->d.y = m;
        p->d.x = m;
        // fallthrough
      case 1:
      case 10:
        p->mode[2]++;
        break;
      case 11: {
        struct Coord c;
        struct Coord c2;
        struct Coord* cp;
        u32 r;
        c.x = p->coord.x;
        c.y = p->coord.y;
        CreateSmoke(1, &c);
        PlaySound(0x2A);
        cp = &p->coord;
        TryDropItem(4, cp);
        r = RANDOM(RNG_0202f388) & 3;
        c2.x = p->coord.x;
        c2.y = p->coord.y + -0xC00;
        FUN_080c4914(&c2, (p->flags >> 4) & 1, 0x7E1A, r);
        FUN_080c4914(&c2, (p->flags >> 4) & 1, 0x7E1B, r);
        FUN_080c4914(&c2, (p->flags >> 4) & 1, 0x7E1C, r);
        if (gScore.enemyCount <= 0x270E) {
          gScore.enemyCount++;
        }
        TryDropZakoDisk((struct Entity*)p, cp);
        p->flags &= 0xFE;
        {
          u32 tbl = (u32)gEnemyFnTable;
          u32 id = (p->id) << 2;
          EntityFunc** rt = (EntityFunc**)(tbl + id);
          *(u32*)(p->mode) = 4;
          p->onUpdate = (void*)((*rt)[4]);
        }
        break;
      }
    }
  }
}

bool8 FUN_080902a8(Petatria* p) {
  if ((p->body).status & BODY_STATUS_B3) {
    p->mode[1] = 4, p->mode[2] = 0;
  }
  return TRUE;
}

INCASM("asm/enemy/petatria_c.inc");

bool8 FUN_080906ec(Petatria* p) {
  if ((p->body).status & BODY_STATUS_B3) {
    p->mode[1] = 5, p->mode[2] = 0;
  }
  return TRUE;
}

INCASM("asm/enemy/petatria_d.inc");

bool8 FUN_08090b20(Petatria* p) { return TRUE; }

void FUN_08090b24(Petatria* p) {
  struct Coord c;
  switch (p->mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[4]);
      SetMotion((struct Entity*)p, 0x7E0E);
      p->mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
      p->work[2] = 0x1E;
      p->mode[2]++;
      break;
    case 2: {
      s32 t;
      UpdateEntityAnim((struct Entity*)p);
      t = p->work[2] - 1;
      p->work[2] = t;
      if ((u8)t != 0) {
        break;
      }
      p->mode[2]++;
      break;
    }
    case 3:
      SetMotion((struct Entity*)p, 0x7E0F);
      c.x = p->coord.x;
      c.y = p->coord.y - 0x1C00;
      FUN_0809118c(p, &c);
      PlaySound(0x2C);
      p->mode[2]++;
      FALLTHROUGH;
    case 4:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
      p->mode[2]++;
      break;
    case 5:
      SetMotion((struct Entity*)p, 0x7E10);
      p->work[2] = 0x28;
      p->mode[2]++;
      FALLTHROUGH;
    case 6: {
      s32 t = p->work[2] - 1;
      p->work[2] = t;
      if ((u8)t == 0) {
        p->mode[2]++;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
    case 7:
      SetMotion((struct Entity*)p, 0x7E11);
      p->mode[2]++;
      FALLTHROUGH;
    case 8:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
      p->mode[1] = 0;
      p->mode[2] = 0;
      break;
  }
}

bool8 FUN_08090c60(Petatria* p) { return TRUE; }

void FUN_08090c64(Petatria* p) {
  struct Coord c;
  switch (p->mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[7]);
      SetMotion((struct Entity*)p, 0x7E12);
      p->mode[2]++;
      /* fallthrough */
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
      p->work[2] = 0x1E;
      goto adv;
    case 3:
      SetMotion((struct Entity*)p, 0x7E13);
      if (*(u8*)((u8*)p + 0xb8) == 1) {
        c.x = p->coord.x + 0x400;
      } else {
        c.x = p->coord.x - 0x400;
      }
      c.y = p->coord.y - 0x1900;
      FUN_0809118c(p, &c);
      PlaySound(0x2c);
      p->mode[2]++;
      /* fallthrough */
    case 4:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
    adv:
      p->mode[2]++;
      break;
    case 5:
      SetMotion((struct Entity*)p, 0x7E14);
      p->work[2] = 0x28;
      p->mode[2]++;
      /* fallthrough */
    case 2:
    case 6: {
      s32 t = p->work[2] - 1;
      p->work[2] = t;
      if ((t << 24) == 0) {
        p->mode[2]++;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
    case 7:
      SetMotion((struct Entity*)p, 0x7E15);
      p->mode[2]++;
      /* fallthrough */
    case 8:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        p->mode[1] = 1;
        p->mode[2] = 0;
      }
      break;
  }
}

bool8 FUN_08090da4(Petatria* p) { return TRUE; }

void FUN_08090da8(Petatria* p) {
  switch (p->mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[11]);
      p->work[2] = 4;
      p->mode[2]++;
      /* fallthrough */
    case 1: {
      s32 t = p->work[2] - 1;
      p->work[2] = t;
      if ((t << 24) != 0) {
        break;
      }
      p->mode[2]++;
      break;
    }
    case 2:
      SetDDP(&p->body, &sCollisions[10]);
      SetMotion((struct Entity*)p, 0x7E16);
      p->work[2] = 0x60;
      p->mode[2]++;
      /* fallthrough */
    case 3:
      p->work[2]--;
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
      if (p->work[2] != 0) {
        break;
      }
      p->mode[2]++;
      break;
    case 4:
      SetMotion((struct Entity*)p, 0x7E18);
      p->work[2] = (u32)RANDOM(RNG_0202f388) % 0x14 + 0xA;
      p->mode[2]++;
      /* fallthrough */
    case 5: {
      s32 t;
      UpdateEntityAnim((struct Entity*)p);
      t = p->work[2] - 1;
      p->work[2] = t;
      if ((t << 24) != 0) {
        break;
      }
      p->mode[2]++;
      break;
    }
    case 6:
      SetMotion((struct Entity*)p, 0x7E19);
      p->mode[2]++;
      /* fallthrough */
    case 7: {
      u8 z;
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
      z = 0;
      p->mode[1] = z;
      p->mode[2] = z;
      break;
    }
  }
}

bool8 FUN_08090edc(Petatria* p) { return TRUE; }

void FUN_08090ee0(Petatria* p) {
  switch (p->mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[11]);
      p->work[2] = 4;
      p->mode[2]++;
      // fallthrough
    case 1: {
      s32 t = p->work[2] - 1;
      p->work[2] = t;
      if ((t << 24) != 0) {
        break;
      }
      p->mode[2]++;
      break;
    }
    case 2: {
      s32 v;
      SetDDP(&p->body, &sCollisions[10]);
      SetMotion((struct Entity*)p, 0x7E17);
      p->work[2] = 0x60;
      if (*((u8*)p + 0xb8) == 1) {
        s32 c = 0xCC;
        asm("" : "+r"(c));
        v = -c;
        goto vs;
      }
      v = 0xCC;
    vs:
      p->d.x = v;
      p->d.y = 0;
      p->mode[2]++;
    }
      // fallthrough
    case 3: {
      s32 push;
      p->d.y += 0x40;
      if (p->d.y > 0x700) {
        p->d.y = 0x700;
      }
      p->coord.y += p->d.y;
      UpdateEntityAnim((struct Entity*)p);
      push = PushoutToUp1(p->coord.x, p->coord.y);
      if (push == 0) {
        break;
      }
      p->coord.y += push;
      p->mode[2]++;
      break;
    }
    case 4:
      p->work[2]--;
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
      if (p->work[2] != 0) {
        break;
      }
      p->mode[2]++;
      break;
    case 5:
      SetMotion((struct Entity*)p, 0x7E18);
      p->work[2] = (RANDOM(RNG_0202f388) % 0x14) + 0xA;
      p->mode[2]++;
      // fallthrough
    case 6: {
      s32 t;
      UpdateEntityAnim((struct Entity*)p);
      t = p->work[2] - 1;
      p->work[2] = t;
      if ((t << 24) != 0) {
        break;
      }
      p->mode[2]++;
      break;
    }
    case 7:
      SetMotion((struct Entity*)p, 0x7E19);
      p->mode[2]++;
      // fallthrough
    case 8:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        p->mode[1] = 0;
        p->mode[2] = 0;
      }
      break;
  }
}

bool8 FUN_08091068(Petatria* p) { return TRUE; }

void FUN_0809106c(Petatria* p) {
  register s32 m2 asm("r6");
  m2 = p->mode[2];
  switch (m2) {
    case 0: {
      register s32 len asm("r5");
      s32 dx;
      s32 dy;
      dx = p->unk_coord.x - p->coord.x;
      p->d.x = dx;
      dy = p->unk_coord.y - p->coord.y;
      p->d.y = dy;
      dx >>= 2;
      {
        s32 a = dx * dx;
        s32 b;
        dy >>= 2;
        b = dy * dy;
        len = (u32)Sqrt(a + b) << 2;
      }
      if (len != 0) {
        p->d.x = (p->d.x << 8) / len;
        p->d.y = (p->d.y << 8) / len;
      }
      p->d.x = (p->d.x << 9) >> 8;
      p->d.y = (p->d.y << 9) >> 8;
      *(s32*)((u8*)p + 0xb4) = len;
      if (p->d.x > 0) {
        register s32 one asm("r2");
        register u8* a4c asm("r0");
        register u8* a4a asm("r3");
        register s32 k10 asm("r2");
        register u8 ov asm("r1");
        register s32 m asm("r0");
        one = 1;
        {
          register u8 fl asm("r1");
          register u8 g asm("r0");
          fl = p->flags;
          g = 0x10;
          g |= fl;
          p->flags = g;
        }
        a4c = (u8*)p + 0x4c;
        *a4c = one;
        a4a = (u8*)p + 0x4a;
        k10 = 0x10;
        ov = *a4a;
        m = 0x11;
        m = -m;
        m &= ov;
        m |= k10;
        *a4a = m;
      } else {
        register u8* b4c asm("r0");
        register u8* b4a asm("r2");
        register u8 ov2 asm("r1");
        register s32 m2b asm("r0");
        {
          register u8 fl2 asm("r1");
          register u8 g2 asm("r0");
          fl2 = p->flags;
          asm("" : "+r"(fl2));
          g2 = 0xEF;
          g2 &= fl2;
          p->flags = g2;
        }
        b4c = (u8*)p + 0x4c;
        *b4c = m2;
        b4a = (u8*)p + 0x4a;
        ov2 = *b4a;
        m2b = 0x11;
        m2b = -m2b;
        m2b &= ov2;
        *b4a = m2b;
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32* q;
      p->coord.x += p->d.x;
      p->coord.y += p->d.y;
      UpdateEntityAnim((struct Entity*)p);
      q = (s32*)((u8*)p + 0xb4);
      *q += -0x200;
      break;
    }
  }
}

bool8 FUN_08091150(Petatria* p) { return TRUE; }

void FUN_08091154(Petatria* p) {
  if (p->mode[2] == 0) p->mode[2] = 1;
}

bool8 FUN_08091168(Petatria* p) { return TRUE; }

void FUN_0809116c(Petatria* p) {}

bool8 FUN_08091170(Petatria* p) { return TRUE; }

void FUN_08091174(Petatria* p) {
  if (p->mode[2] == 0) p->mode[2] = 1;
}

bool8 FUN_08091188(Petatria* p) { return TRUE; }

void FUN_0809118c(Petatria* p, struct Coord* c) {
  register s32 dx asm("r4");
  register s32 dy asm("r5");
  register s32 len asm("r6");
  register s32 ang asm("r2");
  register struct Zero* z asm("r2");
  register struct Projectile* q asm("r1");
  z = pZero2;
  {
    register s32 t0 asm("r0");
    register s32 t1 asm("r1");
    t1 = (z->s).coord.x;
    t0 = c->x;
    dx = t1 - t0;
    t0 = c->y;
    t1 = 0x80 << 5;
    t0 = t0 + t1;
    t1 = (z->s).coord.y;
    dy = t1 - t0;
  }
  {
    register s32 sx asm("r0");
    register s32 sy asm("r1");
    register s32 px asm("r2");
    register s32 py asm("r3");
    sx = dx >> 2;
    px = sx * sx;
    asm("" : "+r"(px));
    sx = px;
    asm("" : "+r"(sx));
    sy = dy >> 2;
    py = sy * sy;
    asm("" : "+r"(py));
    sy = py;
    asm("" : "+r"(sy));
    sx = sx + sy;
    len = (u32)Sqrt(sx) << 2;
  }
  if (len != 0) {
    dx = (dx << 8) / len;
    dy = (dy << 8) / len;
  }
  {
  s32 a;
  if (dx > 0) {
    if (dy > 0) {
      register const s16* tb asm("r0");
      register s32 idx asm("r1");
      register const s16* e asm("r1");
      u16 sv;
      tb = gSineTable;
      asm("" : "+r"(tb));
      idx = ((u8)dy) * 2;
      asm volatile("add %0, %1, %2" : "=l"(e) : "l"(idx), "l"(tb));
      sv = *(const u16*)e;
      if (*e > 0) {
        a = 0x7E - sv;
        goto trunc;
      }
      a = sv;
      a = a + 0x7E;
      asm volatile("" : "+r"(a));
      goto trunc;
    }
    {
      register const s16* tb asm("r0");
      register s32 idx asm("r1");
      register const s16* e asm("r1");
      u16 sv;
      tb = gSineTable;
      asm("" : "+r"(tb));
      idx = ((u8)dy) * 2;
      asm volatile("add %0, %1, %2" : "=l"(e) : "l"(idx), "l"(tb));
      sv = *(const u16*)e;
      if (*e > 0) {
        a = sv;
        a += 0x7F;
        goto trunc;
      }
      a = -sv;
      a = a + 0x7F;
      asm volatile("" : "+r"(a));
      goto trunc;
    }
  }
  if (dy <= 0) {
    goto last;
  }
  {
    register const s16* tb2 asm("r0");
    register s32 idx2 asm("r1");
    register const s16* e2 asm("r1");
    tb2 = gSineTable;
    asm("" : "+r"(tb2));
    idx2 = ((u8)(dy + 0x40)) * 2;
    asm volatile("add %0, %1, %2" : "=l"(e2) : "l"(idx2), "l"(tb2));
    a = -*(const u8*)e2;
  trunc:
    a <<= 24;
    ang = (u32)a >> 24;
    goto done;
  }
last : {
    register const s16* tb3 asm("r1");
    register s32 idx3 asm("r0");
    register const s16* e3 asm("r0");
    tb3 = gSineTable;
    asm("" : "+r"(tb3));
    idx3 = ((u8)(dy + 0x40)) * 2;
    asm volatile("add %0, %1, %2" : "=l"(e3) : "l"(idx3), "l"(tb3));
    ang = *(const u8*)e3;
  }
done:;
  }
  q = ((Projectile * (*)(Coords32*, s32, s32)) CreateLemon)(c, 0x80 << 2, ang);
  asm("" : "+r"(q));
  if (q != NULL) {
    register s32 t asm("r0");
    t = dx << 9;
    t >>= 8;
    q->d.x = t;
    t = dy << 9;
    t >>= 8;
    q->d.y = t;
  }
}

void nop_0809127c(Petatria* p) {}

void Petatria_Init(Petatria* p);
void Petatria_Update(Petatria* p);
void Petatria_Die(Petatria* p);

// clang-format off
const EnemyRoutine gPetatriaRoutine = {
    [ENTITY_INIT] =      (void*)Petatria_Init,
    [ENTITY_UPDATE] =    (void*)Petatria_Update,
    [ENTITY_DIE] =       (void*)Petatria_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// clang-format off
static const EnemyFunc sUpdates1[10] = {
    (EnemyFunc)FUN_080902a8,
    (EnemyFunc)FUN_080906ec,
    (EnemyFunc)FUN_08090b20,
    (EnemyFunc)FUN_08090c60,
    (EnemyFunc)FUN_08090da4,
    (EnemyFunc)FUN_08090edc,
    (EnemyFunc)FUN_08091068,
    (EnemyFunc)FUN_08091150,
    (EnemyFunc)FUN_08091168,
    (EnemyFunc)FUN_08091170,
};
// clang-format on

void FUN_080902c8(Petatria* p);
void FUN_0809070c(Petatria* p);
void FUN_08090b24(Petatria* p);
void FUN_08090c64(Petatria* p);
void FUN_08090da8(Petatria* p);
void FUN_08090ee0(Petatria* p);
void FUN_0809106c(Petatria* p);

// clang-format off
static const EnemyFunc sUpdates2[10] = {
    (EnemyFunc)FUN_080902c8,
    (EnemyFunc)FUN_0809070c,
    (EnemyFunc)FUN_08090b24,
    (EnemyFunc)FUN_08090c64,
    (EnemyFunc)FUN_08090da8,
    (EnemyFunc)FUN_08090ee0,
    (EnemyFunc)FUN_0809106c,
    (void*)FUN_08091154,
    (EnemyFunc)FUN_0809116c,
    (void*)FUN_08091174,
};
// clang-format on

// --------------------------------------------

// 0x08369608
static const struct Collision sCollisions[12] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(16), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(16), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(17), -PIXEL(25), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(17), -PIXEL(25), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(16), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 1,
      range : {PIXEL(0), -PIXEL(29), PIXEL(10), PIXEL(10)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(10), PIXEL(26), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(17), -PIXEL(25), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 1,
      range : {PIXEL(3), -PIXEL(25), PIXEL(10), PIXEL(10)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(22), -PIXEL(25), PIXEL(14), PIXEL(26)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(16), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(16), PIXEL(26), PIXEL(26)},
    },
};

static const s32 s32_ARRAY_08369728[16] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

// clang-format off
// 0x08369768
static const motion_t sMotions1[6] = {
    MOTION(SM126_PETATRIA, 0),
    MOTION(SM126_PETATRIA, 1),
    MOTION(SM126_PETATRIA, 2),
    MOTION(SM126_PETATRIA, 3),
    MOTION(SM126_PETATRIA, 4),
    MOTION(SM126_PETATRIA, 5),
};
// clang-format on

static const s32 s32_ARRAY_08369774[6] = {
    PIXEL(1), PIXEL(2), PIXEL(5), PIXEL(5), PIXEL(2), PIXEL(1),
};
static const s32 s32_ARRAY_0836978c[6] = {
    PIXEL(1), PIXEL(1), PIXEL(2), PIXEL(5), PIXEL(5), PIXEL(2),
};

// clang-format off
static const motion_t sMotions2[6] = {
    MOTION(SM126_PETATRIA, 6),
    MOTION(SM126_PETATRIA, 7),
    MOTION(SM126_PETATRIA, 8),
    MOTION(SM126_PETATRIA, 9),
    MOTION(SM126_PETATRIA, 10),
    MOTION(SM126_PETATRIA, 11),
};
// clang-format on

static const s32 s32_ARRAY_083697b0[6] = {
    -PIXEL(1), -PIXEL(2), -PIXEL(5), -PIXEL(5), -PIXEL(2), -PIXEL(1),
};
static const s32 s32_ARRAY_083697c8[6] = {
    -PIXEL(1), -PIXEL(1), -PIXEL(2), -PIXEL(5), -PIXEL(5), -PIXEL(2),
};
