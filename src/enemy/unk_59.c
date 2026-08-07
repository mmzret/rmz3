#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "physics.h"
#include "vfx.h"
#include "stagerun.h"
#include "zero.h"

// ファントムの出すオブジェクト?
typedef struct {
  COLLISION_OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  s32 x_b4;       // 0xB4
  u8 unk_b8[12];  // 0xB8
} Enemy59;
static_assert(sizeof(Enemy59) == sizeof(struct Enemy));

void FUN_080c4c2c(s32 x, s32 y, s32 amplitude, u8 theta);
void CreateGhost18(Coords32* c, u8 kind, bool8 xflip, u8 r3);

static void Enemy59_Init(Enemy59* p);
void Enemy59_Update(Enemy59* p);
void Enemy59_Die(Enemy59* p);

// clang-format off
const EnemyRoutine gEnemy59Routine = {
    [ENTITY_INIT] =      (void*)Enemy59_Init,
    [ENTITY_UPDATE] =    (void*)Enemy59_Update,
    [ENTITY_DIE] =       (void*)Enemy59_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on


static const EnemyFunc sDeads[4];
void FUN_08091280(Enemy59* p) {
  s32 x, y, amplitude;
  u8 theta;
  x = (p->coord).x + PIXEL((RANDOM(RNG_0202f388) & 0x1F) - 16);
  y = (p->coord).y - PIXEL(-RANDOM(RNG_0202f388) % 48);
  amplitude = 0x100;
  theta = 0x80 | (RANDOM(RNG_0202f388) & 0x7F);
  FUN_080c4c2c(x, y, amplitude, theta);
}

void FUN_0809130c(Entity* e, u8 idx) {
  Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_59);
    (p->coord).x = (e->coord).x, (p->coord).y = (e->coord).y;
    if (idx < 4) {
      s32 x = (idx - 2) * PIXEL(48) + PIXEL(24);
      (p->unk_coord).x = (e->coord).x + x;
    }
    if (idx > 4) {
      s32 x = (idx - 7) * PIXEL(48) + PIXEL(24);
      (p->coord).x = (e->coord).x + x;
    }
    p->unk_28 = e;
    EnableSpriteAnimation_Normal(p);
    SetSpriteTableDynamic(p);
    (p->spr).sprites = (*(void**)&e->kind);
    {
      u8 palID = *((u8*)e + 0x15);
      (p->spr).oam.paletteNum = palID >> 4;
    }
    p->work[0] = idx;
  }
}

// 0x080913C0
void FUN_080913c0(Enemy59* q, u8 kind) {
  Enemy59* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_59);
    (p->coord).x = (q->coord).x;
    (p->coord).y = (q->coord).y;
    p->work[0] = kind;
    p->work[3] = q->x_b4 > 0;
  }
}

/**
 * @note まきびし?
 * @note 0x0809142C
 */
void FUN_0809142c(Entity* q, u8 kind) {
  Enemy59* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_59);
    (p->coord).x = (q->coord).x;
    (p->coord).y = (q->coord).y - PIXEL(10);
    p->work[0] = 12;
    p->work[2] = kind;
    p->unk_28 = q;
  }
}

static const struct Collision sCollisions[];
static const u8 u8_ARRAY_08369a14[];
void FUN_08091790(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED);

static void Enemy59_Init(Enemy59* p) {
  if (p->work[0] == 12) {
    SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
    p->flags |= FLIPABLE;
    p->flags |= DISPLAY;
    INIT_BODY(p, sCollisions, 6, FUN_08091790);
    p->mode[1] = u8_ARRAY_08369a14[p->work[0]];
    Enemy59_Update(p);
    return;
  }
  if (p->work[0] > 8) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    p->flags |= FLIPABLE;
    p->flags |= DISPLAY;
    p->mode[1] = u8_ARRAY_08369a14[p->work[0]];
    Enemy59_Die(p);
    return;
  }

  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  INIT_BODY(p, sCollisions, 1, FUN_08091790);
  p->mode[1] = u8_ARRAY_08369a14[p->work[0]];
  Enemy59_Update(p);
}

INCASM("asm/enemy/unk_59_a.inc");

void Enemy59_Die(Enemy59* p) {
  (sDeads[p->mode[1]])((void*)p);
}

void FUN_08091790(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  Enemy59* atk = (Enemy59*)(body->enemy->parent);
  Enemy59* self = (Enemy59*)(body->parent);
  if (self->work[0] == 0xc) {
    if ((body->hitboxFlags & 8) &&
        (s8)atk->kind == 2 &&
        atk->mode[1] == 1 &&
        (u8)(atk->mode[2] - 1) <= 1 &&
        atk->id == 0x15 &&
        ((*(u32*)&self->mode[0]) & 0xffff00) == 0x30800) {
      *(s32*)((u8*)self + 0xb4) = atk->coord.x - self->coord.x;
      self->mode[1] = 9;
      self->mode[2] = 0;
    }
  } else {
    *(s32*)((u8*)self + 0xb4) = pZero2->s.coord.x - self->coord.x;
  }
}

void FUN_08091810(Enemy59* p) {}

void FUN_08091814(Enemy59* p) {
  struct Entity* q = p->unk_28;
  register u32* w asm("r5");
  s32 z;
  {
    register struct Sprite* ps asm("r0");
    register struct Sprite* qs asm("r2");
    register u8 m asm("r1");
    ps = (struct Sprite*)((u8*)p + 0x34);
    qs = (struct Sprite*)((u8*)q + 0x34);
    m = p->mode[2];
    switch (m) {
      case 0:
        {
          register struct MetaspriteHeader* sp asm("r1");
          register struct Coord* co asm("r2");
          sp = qs->sprites;
          co = &p->coord;
          InitNonAffineSprite(ps, sp, co);
        }
        p->mode[2]++;
        break;
      case 1:
        break;
      default:
        return;
    }
  }
  {
    register u32* c4 asm("r0");
    c4 = (u32*)((u8*)q + 0xc4);
    {
      register s32 fv asm("r1");
      fv = *c4;
      fv &= 8;
      asm volatile("add %0, %1, #0" : "=&l"(w) : "l"(c4));
      if (fv != 0) {
        SetDDP(&p->body, (const struct Collision*)0x08369864);
      }
    }
  }
  {
    register s32 t asm("r2");
    {
      register s32 t0 asm("r0");
      t0 = p->work[2];
      asm volatile("add %0, %1, #0" : "=&l"(t) : "l"(t0));
    }
    if (t == 0) {
      register u8 fl asm("r1");
      register u8 g asm("r0");
      fl = p->flags;
      asm("" : "+r"(fl));
      g = 1;
      g |= fl;
      p->flags = g;
    } else {
      register u8 fl2 asm("r1");
      register u8 g2 asm("r0");
      fl2 = p->flags;
      asm("" : "+r"(fl2));
      g2 = 0xFE;
      g2 &= fl2;
      p->flags = g2;
    }
    {
      register s32 n asm("r0");
      n = t + 1;
      z = 0;
      p->work[2] = n;
      n <<= 24;
      n = (u32)n >> 24;
      if (n == 3) {
        p->work[2] = z;
      }
    }
  }
  {
    register u32* w3 asm("r3");
    w3 = w;
    if (*w3 & 1) {
      {
        register u8 h asm("r1");
        register u8 g3 asm("r0");
        h = p->flags;
        asm("" : "+r"(h));
        g3 = 0xFE;
        g3 &= h;
        h = 0xFD;
        g3 &= h;
        p->flags = g3;
      }
      {
        u8* a = (u8*)p + 0x8c;
        *(u32*)a = z;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *(u32*)a = z;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *a = z;
      }
      p->flags &= 0xFB;
      SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
    }
    if (*w3 & 2) {
      p->mode[1] = 3;
      p->mode[2] = z;
    }
  }
  {
    register s32 k asm("r1");
    register s32 v asm("r0");
    v = *w;
    k = 4;
    v &= k;
    if (v != 0) {
      p->mode[1] = k;
      p->mode[2] = z;
    }
  }
}

NON_MATCH void FUN_080918ec(Enemy59* p) {
#if MODERN
  s32 m = p->mode[2];
  s32 t;
  switch (m) {
    case 0: {
      s32 f = 0;
      if (p->unk_coord.x - p->coord.x > 0) {
        f = 1;
      }
      SetDDP(&p->body, &sCollisions[2]);
      p->d.x = (f << 9) - 0x100;
      p->work[2] = m;
      p->mode[2]++;
    }
      /* fallthrough */
    case 1: {
      s32 x;
      s32 tx;
      s32 d;
      t = p->work[2];
      if (t == 0) {
        p->flags |= DISPLAY;
      } else {
        p->flags &= ~DISPLAY;
      }
      p->work[2] = t + 1;
      if ((u8)(t + 1) == 4) {
        p->work[2] = 0;
      }
      x = p->coord.x + p->d.x;
      p->coord.x = x;
      tx = p->unk_coord.x;
      d = tx - x;
      if (d >= 0) {
        if (d > 0xFF) {
          break;
        }
      } else {
        if (x - tx > 0xFF) {
          break;
        }
      }
      p->coord.x = tx;
      p->mode[1] = 0;
      p->mode[2] = 0;
      break;
    }
  }
#else
  INCCODE("asm/enemy/unk_59_18ec.inc");
#endif
}

NON_MATCH void FUN_08091980(Enemy59* p) {
#if MODERN
  u8 fv;
  u8 one;
  switch (p->mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[0]);
      p->work[2] = 0x1B;
      p->mode[2]++;
      FALLTHROUGH;
    case 1:
      p->work[2]--;
      if ((u8)p->work[2] != 0) {
        break;
      }
      p->mode[2]++;
      break;
    case 2:
      p->work[2] = 0xF;
      p->mode[2]++;
      FALLTHROUGH;
    case 3:
      p->work[2]--;
      if ((u8)(p->work[2] % 3) == 2) {
        goto clr;
      }
      fv = p->flags | DISPLAY;
      goto store;
    case 4:
      p->work[2] = 0xF;
      p->mode[2]++;
      FALLTHROUGH;
    case 5:
      p->work[2]--;
      one = 1;
      if ((one & p->work[2]) != 0) {
        fv = p->flags | one;
      } else {
      clr : {
        u8 t = p->flags;
        fv = 0xFE;
        fv &= t;
        asm volatile("" ::"r"(t));
      }
      }
    store:
      p->flags = fv;
      if (p->work[2] != 0) {
        break;
      }
      p->mode[2]++;
      break;
    case 6:
      p->work[2] = 0xF;
      p->mode[2]++;
      FALLTHROUGH;
    case 7: {
      u8 w;
      p->work[2]--;
      if ((u8)(p->work[2] % 3) == 2) {
        fv = p->flags | DISPLAY;
      } else {
        u8 t = p->flags;
        fv = 0xFE;
        fv &= t;
        asm volatile("" ::"r"(t));
      }
      p->flags = fv;
      w = p->work[2];
      if (w == 0) {
        u8 t2 = p->flags;
        u8 g = 0xFE;
        g &= t2;
        asm volatile("" ::"r"(t2));
        g &= 0xFD;
        p->flags = g;
        (p->body).status = w;
        (p->body).prevStatus = w;
        (p->body).invincibleTime = w;
        p->flags &= ~COLLIDABLE;
        SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
      }
      break;
    }
  }
#else
  INCCODE("asm/enemy/unk_59_91980.inc");
#endif
}

void FUN_08091ab0(Enemy59* p) {
  struct Entity* q = p->unk_28;
  struct Sprite* ps = &p->spr;
  struct Sprite* qs = &(q->spr);
  switch (p->mode[2]) {
    case 0:
      InitNonAffineSprite(ps, qs->sprites, &p->coord);
      SetDDP(&p->body, &sCollisions[2]);
      p->mode[2]++;
      FALLTHROUGH;
    case 1: {
      s32 z;
      u8 w2;
      u8 w2_0 = p->work[2];
      asm volatile("add %0, %1, #0" : "=&l"(w2) : "l"(w2_0));
      if (w2 == 0) {
        p->flags |= DISPLAY;
      } else {
        p->flags &= ~DISPLAY;
      }
      {
        s32 n = w2 + 1;
        z = 0;
        p->work[2] = n;
        if ((u8)n == 4) {
          p->work[2] = z;
        }
      }
      p->coord.y = q->coord.y;
      if (*(u32*)((u8*)q + 0xc4) & 1) {
        {
          register u8 f asm("r0");
          register u8 t asm("r1");
          register u8 k2 asm("r1");
          t = p->flags;
          f = 0xFE;
          f &= t;
          asm volatile("" ::"r"(t));
          k2 = 0xFD;
          f &= k2;
          p->flags = f;
        }
        *(u32*)((u8*)p + 0x8c) = z;
        *(u32*)((u8*)p + 0x90) = z;
        *(u8*)((u8*)p + 0x94) = z;
        p->flags &= ~COLLIDABLE;
        SET_ENEMY_ROUTINE(p, 3);
      }
      break;
    }
  }
}

void FUN_08091b60(Enemy59* p) {
  struct Entity* q = p->unk_28;
  struct Sprite* ps = &p->spr;
  struct Sprite* qs = &(q->spr);
  u8 m = p->mode[2];
  switch (m) {
    case 0:
      SetDDP(&p->body, (const struct Collision*)0x08369894);
      InitScalerotSprite1(ps, qs->sprites, &p->coord);
      p->flags |= 0x40;
      p->flags2 |= 1;
      p->angle = m;
      p->work[2] = m;
      p->work[3] = 0x20;
      p->mode[2]++;
      FALLTHROUGH;
    case 1: {
      register s32 a asm("r3");
      register u32 b asm("r2");
      {
        u8 a0 = p->work[2];
        asm volatile("add %0, %1, #0" : "=&l"(a) : "l"(a0));
      }
      b = p->work[3];
      if (a == 0 && b <= 0x55) {
        p->flags |= DISPLAY;
      } else {
        p->flags &= 0xFE;
      }
      {
        s32 n;
        asm volatile("add %0, %1, #1" : "=&l"(n) : "l"(a));
        asm volatile("movs %0, #0" : "=l"(a));
        p->work[2] = n;
        if ((u8)n == (u8)((b << 24) >> 28)) {
          u32 nb;
          asm volatile("add %0, %1, #3" : "=&l"(nb) : "l"(b));
          p->work[3] = nb;
          p->work[2] = a;
        }
      }
      {
        u16 v = *(u16*)((u8*)q + 0x52);
        u16* dst = (u16*)((u8*)p + 0x52);
        *dst = v;
      }
      if (*(u32*)((u8*)q + 0xc4) & 1) {
        register u8 g asm("r0");
        register u8 h asm("r1");
        u8* aa;
        h = p->flags;
        asm("" : "+r"(h));
        g = 0xFE;
        g &= h;
        h = 0xFD;
        g &= h;
        p->flags = g;
        aa = (u8*)p + 0x8c;
        *(s32*)aa = a;
        asm("" : "+r"(aa));
        aa += 4;
        asm("" : "+r"(aa));
        *(s32*)aa = a;
        *((u8*)p + 0x94) = 0;
        p->flags &= ~4;
        SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
      }
      break;
    }
  }
}

void FUN_08091c54(Enemy59* p) {
  struct Entity* q = p->unk_28;
  struct Sprite* ps = &p->spr;
  struct Sprite* qs = &(q->spr);
  switch (p->mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[2]);
      InitScalerotSprite1(ps, qs->sprites, &p->coord);
      p->flags |= 0x40;
      p->flags2 |= 1;
      p->angle = 0;
      p->work[2] = 0;
      p->work[3] = 0x59;
      p->mode[2]++;
      FALLTHROUGH;
    case 1: {
      u8 w2;
      u8 w2_0 = p->work[2];
      asm volatile("add %0, %1, #0" : "=&l"(w2) : "l"(w2_0));
      if (w2 == 0) {
        p->flags |= DISPLAY;
      } else {
        p->flags &= 0xFE;
      }
      {
        s32 n = w2 + 1;
        u8 w3;
        p->work[2] = n;
        w3 = p->work[3];
        if ((u8)n == (w3 >> 4)) {
          p->work[2] = 0;
          p->work[3] = w3 - 3;
        }
      }
      {
        u16 v = *(u16*)((u8*)q + 0x52);
        u16* dst = (u16*)((u8*)p + 0x52);
        s32 z;
        asm volatile("movs %0, #0" : "=l"(z));
        *dst = v;
        if ((*(u32*)((u8*)q + 0xc4) & 8) != 0) {
          p->mode[1] = z;
          p->mode[2] = z;
        }
      }
      break;
    }
  }
}

NON_MATCH void FUN_08091d0c(Enemy59* p) {
#if MODERN
  switch (p->mode[2]) {
    case 0: {
      u8 w;
      SetDDP(&p->body, &sCollisions[6]);
      InitNonAffineMotion((struct Entity*)p);
      w = p->work[2];
      p->d.x = gSineTable[(u8)(w * 2 + 0x3E) + 0x40] << 2;
      p->d.y = gSineTable[(u8)(w * 2 + 0x3E)] << 2;
      SetMotion((struct Entity*)p, MOTION(0x88, 0x00));
      p->mode[2]++;
      /* fallthrough */
    }
    case 1: {
      s32 r;
      p->coord.x += p->d.x;
      p->coord.y += p->d.y;
      r = PushoutToUp1(p->coord.x, p->coord.y);
      if (r < 0) {
        p->coord.y += r;
        p->mode[1] = 7;
        p->mode[2] = 0;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
#else
  INCCODE("asm/enemy/unk_59_1d0c.inc");
#endif
}

void FUN_08091da4(Enemy59* p) {
  switch (p->mode[2]) {
    case 0:
      PlaySound(0x100);
      SetDDP(&p->body, &sCollisions[8]);
      p->d.x = (p->work[2] * 3 << 7) - 0x180;
      p->d.y = -0x400;
      SET_XFLIP(p, p->work[2] >> 1);
      SetMotion((struct Entity*)p, MOTION(0x88, 0x01));
      p->mode[2]++;
      FALLTHROUGH;
    case 1: {
      s32 dy;
      p->coord.x += p->d.x;
      dy = p->d.y + 0x40;
      p->d.y = dy;
      if (dy > 0) {
        p->mode[1] = 8;
        p->mode[2] = 0;
      }
      p->coord.y += p->d.y;
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

void FUN_08091e58(Enemy59* p) {
  struct Entity* q = p->unk_28;
  switch (p->mode[2]) {
    case 0:
      SetMotion((struct Entity*)p, MOTION(0x88, 0x02));
      p->mode[2]++;
      FALLTHROUGH;
    case 1: {
      s32 x = p->coord.x + p->d.x;
      s32 dy;
      s32 y;
      s32 r;
      p->coord.x = x;
      dy = p->d.y + 0x40;
      p->d.y = dy;
      y = p->coord.y + dy;
      p->coord.y = y;
      r = PushoutToUp1(x, y);
      if (r < 0) {
        PlaySound(0x100);
        p->coord.y += r;
        p->mode[2]++;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
    case 2:
      p->work[3] = 0xc0;
      p->mode[2]++;
      FALLTHROUGH;
    case 3: {
      s32 t = p->work[3] - 1;
      p->work[3] = t;
      if ((t << 24) != 0 && q->mode[0] <= 1) {
        break;
      }
      SET_ENEMY_ROUTINE(p, ENTITY_DIE);
      p->mode[1] = 3;
      break;
    }
  }
}

void FUN_08091f00(Enemy59* p) {
  switch (p->mode[2]) {
    case 0: {
      s32 dx;
      PlaySound(0x100);
      p->d.x = -0x300;
      dx = -0x300;
      if (*(s32*)((u8*)p + 0xb4) < 0) {
        dx = 0x300;
      }
      p->d.x = dx;
      p->d.y = -0x200;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      p->coord.x += p->d.x;
      p->coord.y += p->d.y;
      if (Camera_GetDistance(&gStageRun.vm.camera, &p->coord) > 0x4000) {
        register u8 f asm("r0");
        register u8 t asm("r1");
        register u8 k2 asm("r1");
        register s32 z asm("r2");
        u8* qq;
        t = p->flags;
        f = 0xFE;
        f &= t;
        asm volatile("" ::"r"(t));
        z = 0;
        k2 = 0xFD;
        f &= k2;
        p->flags = f;
        qq = (u8*)p + 0x8c;
        asm("" : "+r"(qq));
        *(s32*)qq = z;
        asm("" : "+r"(qq));
        qq += 4;
        asm("" : "+r"(qq));
        *(s32*)qq = z;
        asm("" : "+r"(qq));
        qq += 4;
        asm("" : "+r"(qq));
        *qq = z;
        {
          register u8 f3 asm("r0");
          register u8 t3 asm("r1");
          t3 = p->flags;
          f3 = 0xFB;
          f3 &= t3;
          p->flags = f3;
          asm volatile("" ::"r"(t3));
        }
        SET_ENEMY_ROUTINE(p, 3);
      }
      break;
  }
}

INCASM("asm/enemy/unk_59_b.inc");

NON_MATCH void FUN_080921c8(Enemy59* p) {
#if MODERN
  switch (p->mode[2]) {
    case 0: {
      InitNonAffineMotion((struct Entity*)p);
      SET_XFLIP(p, p->work[3]);
      SetMotion((struct Entity*)p, MOTION(SM019_PANTHEON_HUNTER, 3));
      p->work[2] = 18;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateEntityAnim((struct Entity*)p);
      p->work[2]--;
      if ((p->work[2] & 3) == 0) FUN_08091280((struct Entity*)p);
      if (p->work[2] == 0) p->mode[2]++;
      break;
    }
    case 2: {
      p->work[2] = 0;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 3: {
      UpdateEntityAnim((struct Entity*)p);
      if (p->work[2] == 0) PlaySound(SE_ZAKO_EXPLODE);
      p->work[2]++;
      if (p->motion.state == 3) {
        register struct Coord* c asm("r4") = &p->coord;
        CreateGhost18(c, 0, (p->flags & X_FLIP) != 0, p->work[3]);
        {
          register const struct SlashedEnemy* tmp asm("r6") = &sSlashedEnemies[3];
          u8 work3 = p->work[3];
          u8 k = X_FLIP;
          if (p->flags & k) {
            k |= work3;
          } else {
            k = work3;
          }
          CreateSlashedEnemy(c, tmp, 0, k);
        }
        SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
      }
      break;
    }
    default: {
      break;
    }
  }
#else
  INCCODE("asm/enemy/unk_59_921c8.inc");
#endif
}

// 0x083697F4
static const struct SlashedEnemy sSlashedEnemies[4] = {
    {
      m : 0x1306,
      unk_02 : {255, 17},
      c : {0x0000, 0x0000},
      d : {0x0080, -0x0500},
      unk_coord_0c : {0x00FF, 0x01FF},
      unk_10 : {0x0000, 0x0040},
      unk_14 : {512, 512},
    },
    {
      m : 0x1307,
      unk_02 : {254, 17},
      c : {0x0000, 0x0000},
      d : {0x0080, -0x0200},
      unk_coord_0c : {0x007F, 0x007F},
      unk_10 : {0x0000, 0x0040},
      unk_14 : {512, 512},
    },
    {
      m : 0x1308,
      unk_02 : {254, 17},
      c : {0x0000, 0x0000},
      d : {0x0100, -0x0300},
      unk_coord_0c : {0x01FF, 0x01FF},
      unk_10 : {0x0000, 0x0040},
      unk_14 : {512, 512},
    },
    {
      m : 0x1304,
      unk_02 : {16, 4},
      c : {0x0800, -0x1800},
      d : {-0x0080, -0x0100},
      unk_coord_0c : {0x0000, 0x0000},
      unk_10 : {0x0000, 0x0040},
      unk_14 : {512, 512},
    },
};

// 0x08369864
static const struct Collision sCollisions[14] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(1), -PIXEL(8), PIXEL(8), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(1), -PIXEL(8), PIXEL(8), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(1), -PIXEL(8), PIXEL(8), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 4,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(1), -PIXEL(8), PIXEL(8), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 5,
      layer : 0x00000001,
      range : {PIXEL(1), -PIXEL(8), PIXEL(8), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 4,
      layer : 0x00000001,
      range : {PIXEL(1), -PIXEL(2), PIXEL(22), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 3,
      range : {PIXEL(1), -PIXEL(8), PIXEL(8), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 2,
      range : {PIXEL(1), -PIXEL(2), PIXEL(22), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 255,
      hardness : 8,
      remaining : 1,
      layer : 0xFFFFFFFF,
      range : {PIXEL(1), -PIXEL(8), PIXEL(8), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 255,
      hardness : 8,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(1), -PIXEL(2), PIXEL(22), PIXEL(8)},
    },
};

// --------------------------------------------

void FUN_08091810(Enemy59* p);

// clang-format off
static const EnemyFunc sUpdates1[10] = {
    (EnemyFunc)FUN_08091810,
    (EnemyFunc)FUN_08091810,
    (EnemyFunc)FUN_08091810,
    (EnemyFunc)FUN_08091810,
    (EnemyFunc)FUN_08091810,
    (EnemyFunc)FUN_08091810,
    (EnemyFunc)FUN_08091810,
    (EnemyFunc)FUN_08091810,
    (EnemyFunc)FUN_08091810,
    (EnemyFunc)FUN_08091810,
};
// clang-format on

void FUN_08091814(Enemy59* p);
NON_MATCH void FUN_080918ec(Enemy59* p);
NON_MATCH void FUN_08091980(Enemy59* p);
void FUN_08091ab0(Enemy59* p);
void FUN_08091b60(Enemy59* p);
void FUN_08091c54(Enemy59* p);
NON_MATCH void FUN_08091d0c(Enemy59* p);
void FUN_08091da4(Enemy59* p);
void FUN_08091e58(Enemy59* p);
void FUN_08091f00(Enemy59* p);

// clang-format off
static const EnemyFunc sUpdates2[10] = {
    (EnemyFunc)FUN_08091814,
    (EnemyFunc)FUN_080918ec,
    (EnemyFunc)FUN_08091980,
    (EnemyFunc)FUN_08091ab0,
    (EnemyFunc)FUN_08091b60,
    (EnemyFunc)FUN_08091c54,
    (EnemyFunc)FUN_08091d0c,
    (EnemyFunc)FUN_08091da4,
    (EnemyFunc)FUN_08091e58,
    (EnemyFunc)FUN_08091f00,
};
// clang-format on

// --------------------------------------------

void FUN_08091fa8(Enemy59* p);
NON_MATCH void FUN_080921c8(Enemy59* p);
NON_MATCH static void FUN_080922e0(Enemy59* p);
static void FUN_080923ec(Enemy59* p);

static const EnemyFunc sDeads[4] = {
    (void*)FUN_08091fa8,
    (void*)FUN_080921c8,
    (void*)FUN_080922e0,
    (void*)FUN_080923ec,
};

NON_MATCH static void FUN_080922e0(Enemy59* p) {
#if MODERN
  switch (p->mode[2]) {
    case 0: {
      EnableSpriteAnimation_Normal(p);
      SET_XFLIP(p, p->work[3]);
      SetSpriteAnimation(p, MOTION(SM019_PANTHEON_HUNTER, 3));  // 分身のハズレ枠
      p->work[2] = 18;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      p->work[2]--;
      if ((p->work[2] & 3) == 0) FUN_08091280(p);
      if (p->work[2] == 0) p->mode[2]++;
      break;
    }

    case 2: {
      p->work[2] = 0;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 3: {
      UpdateSpriteAnimation(p);
      if (p->work[2] == 0) PlaySound(SE_ZAKO_EXPLODE);
      p->work[2]++;
      {
        register Coords32* c asm("r4") = &p->coord;
        CreateGhost18(c, 0, (p->flags & X_FLIP) != 0, p->work[3]);
        {
          register const struct SlashedEnemy* tmp asm("r6") = &sSlashedEnemies[3];
          u8 work3 = p->work[3];
          if (p->flags & X_FLIP) work3 |= p->flags & X_FLIP;
          CreateSlashedEnemy(c, tmp, 0, work3);
        }
      }
      SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
      break;
    }
    default: {
      break;
    }
  }
#else
  INCCODE("asm/wip/FUN_080922e0.inc");
#endif
}

static void FUN_080923ec(Enemy59* p) {
  Coords32 c;
  EXIT_BODY(p);
  c.x = (p->coord).x;
  c.y = (p->coord).y - PIXEL(8);
  CreateSmoke(1, &c);
  PlaySound(SE_ZAKO_EXPLODE);
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

// 0x08369a14
static const u8 u8_ARRAY_08369a14[16] = {
    1, 1, 1, 1, 2, 5, 5, 5, 5, 0, 1, 2, 6, 0, 0, 0,
};
