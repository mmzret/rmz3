#include "collision.h"
#include "element.h"
#include "enemy.h"
#include "global.h"
#include "physics.h"
#include "story.h"
#include "vfx.h"
#include "zero.h"
#include "stagerun.h"

void FUN_08070000(struct Body* body, struct Coord* r1, struct Coord* r2);
s32 FUN_0800a22c(s32 x, s32 y);
s32 FUN_0800a05c(s32 x, s32 y);
s32 FUN_0800a31c(s32 x, s32 y);
s32 FUN_0800a22c(s32 x, s32 y);

typedef struct {
  COLLISION_OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  u8 unk_b4[8];         // 0xB4
  struct Entity* elfx;  // 0xBC, Element Effect
  u8 unk_c0[2];         // 0xC0
  u8 unk_c2;
  u8 unk_c3;
} TopGabyoall;
static_assert(sizeof(TopGabyoall) == sizeof(struct Enemy));

static const struct Collision sCollisions[];
static const Coords32 sElementCoords[];

static void Enemy14_Init(struct Enemy* p);
static void Enemy14_Update(TopGabyoall* p);
void Enemy14_Die(TopGabyoall* p);

// clang-format off
const EnemyRoutine gTopGabyoallRoutine = {
    [ENTITY_INIT] =      (void*)Enemy14_Init,
    [ENTITY_UPDATE] =    (void*)Enemy14_Update,
    [ENTITY_DIE] =       (void*)Enemy14_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* CreateTopGabyoall(Coords32* c, u8 r1, u8 r2) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_TOP_GABYOALL);
    p->work[0] = r1;
    p->work[1] = r2;
    p->coord = *c;
    return p;
  } else {
    return NULL;
  }
}

// --------------------------------------------

void FUN_0806f5d0(TopGabyoall* p);
void FUN_0806f6cc(TopGabyoall* p);
void FUN_0806f7dc(TopGabyoall* p);
void FUN_0806f89c(TopGabyoall* p);

static void Enemy14_Init(struct Enemy* p) {
  static const EnemyFunc sInitializers[4] = {
      (EnemyFunc)FUN_0806f5d0,
      (EnemyFunc)FUN_0806f6cc,
      (EnemyFunc)FUN_0806f7dc,
      (EnemyFunc)FUN_0806f89c,
  };
  (sInitializers[(p->s).work[0]])((void*)p);
}

void FUN_0806f964(TopGabyoall* p);
void FUN_0806fb08(TopGabyoall* p);
void FUN_0806fc78(TopGabyoall* p);
void FUN_0806fe38(TopGabyoall* p);

static const EntityFunc sUpdates[4] = {
    (void*)FUN_0806f964,
    (void*)FUN_0806fb08,
    (void*)FUN_0806fc78,
    (void*)FUN_0806fe38,
};  // 0x08366960

static void Enemy14_Update(TopGabyoall* p) {
  if (p->work[1] == 2) {
    if ((pZero2 != NULL) && ((pZero2->input).raw & INPUT_DISABLED)) {
      return;
    }
  } else if (FLAG(gCurStory.s.gameflags, METTAUR_ENABLED)) {
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  if (p->unk_c2) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    return;
  }

  if ((MOTION_VALUE(p) != MOTION(SM021_TOP_GABYOALL, 3)) && ((p->body).status & BODY_STATUS_WHITE)) {
    if (p->elfx == NULL) {
      p->elfx = (void*)ApplyElementEffect(0, (Object*)p, &sElementCoords[p->work[0]]);
      if (p->elfx != NULL) {
        SetDDP(&p->body, &sCollisions[1 + (p->work[0] & 2)]);
      }
    }
  }

  if (p->elfx != NULL) {
    SetSpriteAnimation(p, MOTION(SM021_TOP_GABYOALL, 0));
    UpdateSpriteAnimation(p);
    if (IsDead(p->elfx)) {
      p->elfx = NULL;
      SetDDP(&p->body, &sCollisions[p->work[0] & 2]);
      p->mode[1] = 0, p->mode[2] = 0;
    }
    return;
  }

  if (!IsFrozen(p)) (sUpdates[p->work[0]])((void*)p);
}

void Enemy14_Die(TopGabyoall* p) {
  CreateSmoke(1, &p->coord);
  PlaySound(0x2a);
  p->flags &= ~DISPLAY;
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
}

void FUN_0806f5d0(TopGabyoall* p) {
  register s32 z6 asm("r6");
  s32 z7;
  InitNonAffineMotion((struct Entity*)p);
  {
    register u8 f0 asm("r1");
    register s32 d0 asm("r0");
    f0 = p->flags;
    d0 = DISPLAY;
    z6 = 0;
    z7 = 0;
    d0 |= f0;
    d0 |= FLIPABLE;
    p->flags = d0;
  }
  SetMotion((struct Entity*)p, MOTION(0x15, 0x00));
  UpdateEntityAnim((struct Entity*)p);
  {
    struct Body* body;
    p->flags |= COLLIDABLE;
    body = &p->body;
    InitBody(body, sCollisions, &p->coord, 0x100);
    body->parent = (void*)p;
    body->fn = FUN_08070000;
  }
  *(u32*)((u8*)p + 0xbc) = z7;
  if ((pZero2->s).coord.x > p->coord.x) {
    register s32 one asm("r2");
    u8* a;
    s32 msk;
    p->d.x = 0x80;
    one = 1;
    p->flags |= X_FLIP;
    (p->spr).xflip = one;
    a = (u8*)p + 0x4a;
    {
      register s32 m asm("r2");
      register u8 b asm("r1");
      m = 0x10;
      asm("" : "+r"(m));
      b = *a;
      msk = -0x11;
      msk &= b;
      msk |= m;
    }
    *a = msk;
  } else {
    u8* a;
    s32 msk;
    p->d.x = -0x80;
    p->flags &= 0xEF;
    (p->spr).xflip = z7;
    a = (u8*)p + 0x4a;
    {
      register u8 b asm("r1");
      b = *a;
      msk = -0x11;
      msk &= b;
    }
    *a = msk;
  }
  p->coord.y = FUN_08009f6c(p->coord.x, p->coord.y);
  *(s32*)((u8*)p + 0xb4) = p->coord.x;
  *(s32*)((u8*)p + 0xb8) = p->coord.y;
  {
    u8* c;
    s32 z2;
    c = (u8*)p + 0xc2;
    z2 = 0;
    *c = z2;
    p->work[2] = z2;
    SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = z2;
    p->mode[2] = 1;
  }
  asm volatile("" ::"r"(z6));
  Enemy14_Update(p);
}

void FUN_0806f6cc(TopGabyoall* p) {
  register s32 z6 asm("r6");
  s32 z7;
  u8* a;
  InitNonAffineMotion((struct Entity*)p);
  {
    register u8 f0 asm("r1");
    register s32 d0 asm("r0");
    f0 = p->flags;
    d0 = DISPLAY;
    z6 = 0;
    z7 = 0;
    d0 |= f0;
    d0 |= FLIPABLE;
    p->flags = d0;
  }
  SetMotion((struct Entity*)p, MOTION(0x15, 0x00));
  UpdateEntityAnim((struct Entity*)p);
  {
    struct Body* body;
    p->flags |= COLLIDABLE;
    body = &p->body;
    InitBody(body, sCollisions, &p->coord, 0x100);
    body->parent = (void*)p;
    body->fn = FUN_08070000;
  }
  {
    register s32 one4 asm("r4");
    one4 = 1;
    asm("" : "+r"(one4));
    p->flags |= Y_FLIP;
    (p->spr).yflip = one4;
    a = (u8*)p + 0x4a;
    {
      register s32 m asm("r2");
      register u8 b asm("r1");
      s32 msk;
      m = 0x20;
      asm("" : "+r"(m));
      b = *a;
      msk = -0x21;
      msk &= b;
      msk |= m;
      *a = msk;
    }
    *(u32*)((u8*)p + 0xbc) = z7;
    {
      s32 msk2;
      if ((pZero2->s).coord.x > p->coord.x) {
        p->d.x = 0x80;
        p->flags |= X_FLIP;
        (p->spr).xflip = one4;
        {
          register s32 m asm("r2");
          register u8 b asm("r1");
          m = 0x10;
          asm("" : "+r"(m));
          b = *a;
          msk2 = -0x11;
          msk2 &= b;
          msk2 |= m;
        }
      } else {
        p->d.x = -0x80;
        p->flags &= 0xEF;
        (p->spr).xflip = z7;
        {
          register u8 b asm("r1");
          b = *a;
          msk2 = -0x11;
          msk2 &= b;
        }
      }
      *a = msk2;
    }
  }
  p->coord.y = FUN_0800a134(p->coord.x, p->coord.y);
  *(s32*)((u8*)p + 0xb4) = p->coord.x;
  *(s32*)((u8*)p + 0xb8) = p->coord.y;
  {
    TopGabyoall* p2 = p;
    u8* c;
    s32 z2;
    asm("" : "+r"(p2));
    c = (u8*)p2 + 0xc2;
    z2 = 0;
    *c = z2;
    SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = z2;
    p->mode[2] = 1;
  }
  asm volatile("" :: "r"(z6));
  Enemy14_Update(p);
}

void FUN_0806f7dc(TopGabyoall* p) {
  s32 z;
  s32 one;
  struct Body* body;
  s32 x;
  InitRotatableMotion((struct Entity*)p);
  {
    register u8 fv asm("r0");
    register u8 fl asm("r1");
    fl = p->flags;
    fv = DISPLAY;
    z = 0;
    fv |= fl;
    fl = FLIPABLE;
    fv |= fl;
    p->flags = fv;
  }
  SetMotion((struct Entity*)p, 0x1500);
  UpdateEntityAnim((struct Entity*)p);
  p->flags |= COLLIDABLE;
  body = &p->body;
  InitBody(body, &sCollisions[2], &p->coord, 0x100);
  body->parent = (void*)p;
  body->fn = (void*)FUN_08070000;
  p->flags &= 0xEF;
  one = 1;
  (p->spr).xflip = z;
  {
    u8* oa = (u8*)p + 0x4a;
    s32 ov = *oa;
    s32 m11 = -0x11;
    m11 &= ov;
    *oa = m11;
  }
  p->angle = 0x40;
  *(s32*)((u8*)p + 0xbc) = z;
  p->d.y = 0x80;
  x = FUN_0800a31c(p->coord.x, p->coord.y);
  p->coord.x = x;
  *(s32*)((u8*)p + 0xb4) = x;
  *(s32*)((u8*)p + 0xb8) = p->coord.y;
  *((u8*)p + 0xc2) = z;
  {
    u32 tbl = (u32)gEnemyFnTable;
    u32 id = (p->id) << 2;
    EntityFunc** rt = (EntityFunc**)(tbl + id);
    *(u32*)(p->mode) = one;
    p->onUpdate = (void*)(*rt)[ENTITY_UPDATE];
  }
  p->mode[1] = z;
  p->mode[2] = one;
  Enemy14_Update(p);
}

void FUN_0806f89c(TopGabyoall* p) {
  s32 z;
  s32 one;
  struct Body* body;
  s32 x;
  InitRotatableMotion((struct Entity*)p);
  {
    register u8 fv asm("r0");
    register u8 fl asm("r1");
    fl = p->flags;
    fv = DISPLAY;
    z = 0;
    fv |= fl;
    fl = FLIPABLE;
    fv |= fl;
    p->flags = fv;
  }
  SetMotion((struct Entity*)p, 0x1500);
  UpdateEntityAnim((struct Entity*)p);
  p->flags |= COLLIDABLE;
  body = &p->body;
  InitBody(body, &sCollisions[2], &p->coord, 0x100);
  body->parent = (void*)p;
  body->fn = (void*)FUN_08070000;
  one = 1;
  p->flags |= 0x10;
  (p->spr).xflip = one;
  {
    u8* oa = (u8*)p + 0x4a;
    s32 sh = 0x10;
    s32 ov = *oa;
    s32 m11 = -0x11;
    m11 &= ov;
    m11 |= sh;
    *oa = m11;
  }
  p->angle = 0x40;
  *(s32*)((u8*)p + 0xbc) = z;
  p->d.y = 0x80;
  x = FUN_0800a22c(p->coord.x, p->coord.y);
  p->coord.x = x;
  *(s32*)((u8*)p + 0xb4) = x;
  *(s32*)((u8*)p + 0xb8) = p->coord.y;
  *((u8*)p + 0xc2) = z;
  p->work[2] = z;
  {
    u32 tbl = (u32)gEnemyFnTable;
    u32 id = (p->id) << 2;
    EntityFunc** rt = (EntityFunc**)(tbl + id);
    *(u32*)(p->mode) = one;
    p->onUpdate = (void*)(*rt)[ENTITY_UPDATE];
  }
  p->mode[1] = z;
  p->mode[2] = one;
  Enemy14_Update(p);
}

void FUN_0806f964(TopGabyoall* p) {
  register s32 z asm("r1");
  switch (p->mode[1]) {
    case 0:
      if (p->mode[2] == 0) {
        SetMotion((struct Entity*)p, 0xa8 << 5);
        if (p->d.x > 0) {
          p->d.x = 0x80;
        } else {
          p->d.x = -0x80;
        }
        p->mode[2]++;
      }
      if ((p->coord.y >> 8) != ((pZero2->s).coord.y >> 8)) {
        break;
      }
      z = 0;
      {
        register s32 one asm("r0");
        one = 1;
        asm volatile("strb %0, [%1, #0xd]" ::"l"(one), "l"(p) : "memory");
      }
      goto zmode;
    case 1:
      if (p->mode[2] == 0) {
        SetMotion((struct Entity*)p, 0x1501);
        if (p->d.x > 0) {
          p->d.x = 0xa0 << 2;
        } else {
          p->d.x = -0x280;
        }
        p->mode[2]++;
      }
      if ((p->coord.y >> 8) == ((pZero2->s).coord.y >> 8)) {
        break;
      }
      {
        register s32 z2 asm("r0");
        z2 = 0;
        p->mode[1] = z2;
        p->mode[2] = z2;
      }
      break;
    case 2: {
      register s32 t asm("r0");
      if (p->mode[2] == 0) {
        SetMotion((struct Entity*)p, 0x1503);
        p->work[2] = 0x40;
        p->mode[2]++;
      }
      t = p->work[2];
      t -= 1;
      z = 0;
      p->work[2] = t;
      if ((u8)t != 0xff) {
        break;
      }
      asm volatile("strb %0, [%1, #0xd]" ::"l"(z), "l"(p) : "memory");
    zmode:
      p->mode[2] = z;
      break;
    }
  }
  UpdateEntityAnim((struct Entity*)p);
  if (p->mode[1] == 2) {
    return;
  }
  {
    register s32 nx asm("r2");
    register s32 g asm("r0");
    register s32 cy asm("r1");
    {
      register s32 cx asm("r0");
      register s32 dx0 asm("r1");
      cx = p->coord.x;
      dx0 = p->d.x;
      nx = cx + dx0;
    }
    p->coord.x = nx;
    if (p->work[1] == 2) {
      cy = FUN_0800a05c(nx, p->coord.y);
      p->coord.y = cy;
      if (p->d.x > 0) {
        g = FUN_0800a05c(p->coord.x + (0xa0 << 4), cy);
      } else {
        register s32 k2 asm("r2");
        register s32 xx asm("r0");
        xx = p->coord.x;
        k2 = -0xa00;
        asm volatile("add %0, %0, %1" : "+l"(xx) : "l"(k2));
        g = FUN_0800a05c(xx, cy);
      }
    } else {
      register s32 k3 asm("r2");
      register s32 x3 asm("r0");
      cy = FUN_08009f6c(nx, p->coord.y);
      p->coord.y = cy;
      if (p->d.x > 0) {
        x3 = p->coord.x;
        k3 = 0xa0 << 4;
      } else {
        x3 = p->coord.x;
        k3 = -0xa00;
      }
      x3 += k3;
      g = FUN_08009f6c(x3, cy);
    }
    {
      register s32 d asm("r1");
      d = p->coord.y;
      d -= g;
      if (d < 0) {
        d = -d;
      }
      {
        register s32 lim asm("r0");
        lim = 0x80 << 4;
        if (d > lim) {
          register s32 nv asm("r0");
          nv = -p->d.x;
          p->d.x = nv;
          return;
        }
      }
    }
    if (p->work[1] != 1) {
      return;
    }
    {
      register s32 dx asm("r2");
      register s32 v asm("r0");
      dx = p->d.x;
      if (dx > 0) {
        register s32 w asm("r1");
        v = *(s32*)((u8*)p + 0xb4);
        w = p->coord.x;
        v -= w;
        if (v >= -0x3000) {
          return;
        }
        goto neg;
      } else {
        register s32 w2 asm("r1");
        v = *(s32*)((u8*)p + 0xb4);
        w2 = p->coord.x;
        v -= w2;
        if (v <= (0xc0 << 6)) {
          return;
        }
      neg:
        v = -dx;
      }
      p->d.x = v;
    }
  }
}

void FUN_0806fb08(TopGabyoall* p) {
  register s32 dy asm("r5");
  {
    register s32 t asm("r1");
    register s32 k asm("r0");
    t = p->coord.y;
    k = 0xa0 << 6;
    t += k;
    {
      register s32 zy asm("r0");
      zy = (pZero2->s).coord.y;
      dy = t - zy;
    }
  }
  switch (p->mode[1]) {
    case 0: {
      register s32 a asm("r1");
      if (p->mode[2] == 0) {
        register s32 v asm("r0");
        SetMotion((struct Entity*)p, 0xa8 << 5);
        if (p->d.x > 0) {
          v = 0x80;
        } else {
          v = 0x80;
          v = -v;
        }
        p->d.x = v;
        p->mode[2]++;
      }
      a = dy;
      if (dy < 0) {
        a = -dy;
      }
      if (a > 0x3FF) {
        break;
      }
      {
        register s32 zr asm("r1");
        zr = 0;
        p->mode[1] = 1;
        p->mode[2] = zr;
      }
      break;
    }
    case 1: {
      register s32 a2 asm("r1");
      if (p->mode[2] == 0) {
        register s32 v2 asm("r0");
        SetMotion((struct Entity*)p, 0x1501);
        if (p->d.x > 0) {
          v2 = 0xa0 << 2;
        } else {
          v2 = 0xFFFFFD80;
        }
        p->d.x = v2;
        p->mode[2]++;
      }
      a2 = dy;
      if (dy < 0) {
        a2 = -dy;
      }
      if (a2 <= 0x3FF) {
        break;
      }
      {
        register s32 zr2 asm("r0");
        zr2 = 0;
        p->mode[1] = zr2;
        p->mode[2] = zr2;
      }
      break;
    }
    case 2: {
      register s32 t2 asm("r0");
      register s32 zr3 asm("r1");
      if (p->mode[2] == 0) {
        SetMotion((struct Entity*)p, 0x1503);
        p->work[2] = 0x40;
        p->mode[2]++;
      }
      t2 = p->work[2] - 1;
      zr3 = 0;
      p->work[2] = t2;
      if ((u32)(t2 << 24) >> 24 != 0xff) {
        break;
      }
      p->mode[1] = zr3;
      p->mode[2] = zr3;
      break;
    }
  }
  UpdateEntityAnim((struct Entity*)p);
  if (p->mode[1] == 2) {
    return;
  }
  {
    register s32 x asm("r0");
    register s32 dx asm("r1");
    x = p->coord.x;
    dx = p->d.x;
    x += dx;
    p->coord.x = x;
    if (dx > 0) {
      dx = 0xa0 << 4;
    } else {
      dx = 0xFFFFF600;
    }
    x += dx;
    x = FUN_0800a134(x, p->coord.y);
    {
      register s32 cy asm("r1");
      cy = p->coord.y;
      dy = cy - x;
      asm("" : "+r"(dy));
    }
  }
  {
    register s32 nv asm("r0");
    {
      register s32 a3 asm("r1");
      register s32 lim asm("r0");
      a3 = dy;
      if (a3 < 0) {
        a3 = -a3;
      }
      lim = 0x80 << 4;
      if (a3 > lim) {
        nv = -p->d.x;
        goto store;
      }
    }
    if (p->work[1] != 1) {
      return;
    }
    {
      register s32 dv asm("r2");
      register s32 d asm("r0");
      dv = p->d.x;
      if (dv > 0) {
        register s32 lim2 asm("r1");
        {
          register s32 cx2 asm("r1");
          d = *(s32*)((u8*)p + 0xb4);
          cx2 = p->coord.x;
          d -= cx2;
        }
        lim2 = 0xFFFFD000;
        if (d >= lim2) {
          return;
        }
      } else {
        register s32 lim3 asm("r1");
        {
          register s32 cx2 asm("r1");
          d = *(s32*)((u8*)p + 0xb4);
          cx2 = p->coord.x;
          d -= cx2;
        }
        lim3 = 0xc0 << 6;
        if (d <= lim3) {
          return;
        }
      }
      nv = -dv;
    }
  store:
    p->d.x = nv;
  }
}

void FUN_0806fc78(TopGabyoall* p) {
  register s32 z asm("r1");
  register s32 d asm("r5");
  {
    register s32 u asm("r1");
    register s32 w asm("r0");
    register struct Zero* zz asm("r0");
    zz = pZero2;
    u = p->coord.x;
    w = (zz->s).coord.x;
    d = u - w;
  }
  switch (p->mode[1]) {
    case 0:
      if (p->mode[2] == 0) {
        SetMotion((struct Entity*)p, 0xa8 << 5);
        if (p->d.y > 0) {
          p->d.y = 0x80;
        } else {
          p->d.y = -0x80;
        }
        p->mode[2]++;
      }
      z = d;
      if (d < 0) {
        z = -d;
      }
      if (z > 0xFFF) {
        break;
      }
      z = 0;
      {
        register s32 one asm("r0");
        one = 1;
        asm volatile("strb %0, [%1, #0xd]" ::"l"(one), "l"(p) : "memory");
      }
      goto zmode;
    case 1:
      if (p->mode[2] == 0) {
        SetMotion((struct Entity*)p, 0x1501);
        if (p->d.y > 0) {
          p->d.y = 0xa0 << 2;
        } else {
          p->d.y = -0x280;
        }
        p->mode[2]++;
      }
      z = d;
      if (d < 0) {
        z = -d;
      }
      if (z <= 0xFFF) {
        break;
      }
      {
        register s32 z2 asm("r0");
        z2 = 0;
        p->mode[1] = z2;
        p->mode[2] = z2;
      }
      break;
    case 2: {
      register s32 t asm("r0");
      if (p->mode[2] == 0) {
        SetMotion((struct Entity*)p, 0x1503);
        p->work[2] = 0x40;
        p->mode[2]++;
      }
      t = p->work[2];
      t -= 1;
      z = 0;
      p->work[2] = t;
      if ((u8)t != 0xff) {
        break;
      }
      asm volatile("strb %0, [%1, #0xd]" ::"l"(z), "l"(p) : "memory");
    zmode:
      p->mode[2] = z;
      break;
    }
  }
  UpdateEntityAnim((struct Entity*)p);
  if (p->mode[1] == 2) {
    return;
  }
  {
    register s32 ny asm("r2");
    register s32 g asm("r0");
    register s32 r3v asm("r3");
    d = 0;
    {
      register s32 cy asm("r0");
      register s32 dy0 asm("r1");
      cy = p->coord.y;
      dy0 = p->d.y;
      ny = cy + dy0;
      p->coord.y = ny;
      if (dy0 > 0) {
        cy = p->coord.x;
        asm volatile("mov %0, #0x80\n\tlsl %0, %0, #1" : "=&l"(dy0));
        cy += dy0;
        r3v = 0xc0 << 4;
        dy0 = ny + r3v;
        if ((u16)FUN_080098a4(cy, dy0) != 0) {
          goto big;
        }
        cy = p->coord.x;
        dy0 = p->coord.y;
        {
          register s32 k2 asm("r2");
          k2 = 0xc0 << 4;
          dy0 += k2;
        }
        goto probe2;
      }
    }
    if (p->work[1] == 2) {
      register s32 cam asm("r0");
      cam = (s32)&gStageRun.vm.camera;
      cam = *(s32*)(cam + 0x3c);
      r3v = -0x5000;
      asm("" : "+r"(r3v));
      cam += r3v;
      if (ny >= cam) {
        goto done;
      }
    big:
      d = 0x80 << 5;
      goto done;
    } else {
      register s32 xx2 asm("r0");
      register s32 k4 asm("r1");
      xx2 = p->coord.x;
      k4 = 0x80;
      asm volatile("lsl %0, %0, #1" : "+l"(k4));
      xx2 = xx2 + k4;
      r3v = -0xc00;
      k4 = ny + r3v;
      if ((u16)FUN_080098a4(xx2, k4) != 0) {
        goto big;
      }
      {
        register s32 x3 asm("r0");
        register s32 y3 asm("r1");
        register s32 k6 asm("r2");
        x3 = p->coord.x;
        y3 = p->coord.y;
        k6 = -0xc00;
        y3 += k6;
      probe2:
        g = FUN_0800a31c(x3, y3);
        {
          register s32 cx asm("r1");
          cx = p->coord.x;
          d = cx - g;
        }
      }
    }
  done:
    {
      register s32 a asm("r1");
      a = d;
      if (a < 0) {
        a = -a;
      }
      {
        register s32 lim2 asm("r0");
        lim2 = 0x80 << 4;
        if (a > lim2) {
          register s32 nv asm("r0");
          nv = -p->d.y;
          p->d.y = nv;
          return;
        }
      }
    }
    if (p->work[1] != 1) {
      return;
    }
    {
      register s32 dy asm("r2");
      register s32 v asm("r0");
      dy = p->d.y;
      if (dy > 0) {
        register s32 w2 asm("r1");
        v = *(s32*)((u8*)p + 0xb8);
        w2 = p->coord.y;
        v -= w2;
        if (v >= -0x3000) {
          return;
        }
        goto neg;
      } else {
        register s32 w3 asm("r1");
        v = *(s32*)((u8*)p + 0xb8);
        w3 = p->coord.y;
        v -= w3;
        if (v <= (0xc0 << 6)) {
          return;
        }
      neg:
        v = -dy;
      }
      p->d.y = v;
    }
  }
}

void FUN_0806fe38(TopGabyoall* p) {
  register s32 z asm("r1");
  register s32 d asm("r5");
  {
    register s32 u asm("r1");
    register s32 w asm("r0");
    register struct Zero* zz asm("r0");
    zz = pZero2;
    u = p->coord.x;
    w = (zz->s).coord.x;
    d = u - w;
  }
  switch (p->mode[1]) {
    case 0:
      if (p->mode[2] == 0) {
        SetMotion((struct Entity*)p, 0xa8 << 5);
        if (p->d.y > 0) {
          p->d.y = 0x80;
        } else {
          p->d.y = -0x80;
        }
        p->mode[2]++;
      }
      z = d;
      if (d < 0) {
        z = -d;
      }
      if (z > 0xFFF) {
        break;
      }
      z = 0;
      {
        register s32 one asm("r0");
        one = 1;
        asm volatile("strb %0, [%1, #0xd]" ::"l"(one), "l"(p) : "memory");
      }
      goto zmode;
    case 1:
      if (p->mode[2] == 0) {
        SetMotion((struct Entity*)p, 0x1501);
        if (p->d.y > 0) {
          p->d.y = 0xa0 << 2;
        } else {
          p->d.y = -0x280;
        }
        p->mode[2]++;
      }
      z = d;
      if (d < 0) {
        z = -d;
      }
      if (z <= 0xFFF) {
        break;
      }
      {
        register s32 z2 asm("r0");
        z2 = 0;
        p->mode[1] = z2;
        p->mode[2] = z2;
      }
      break;
    case 2: {
      register s32 t asm("r0");
      if (p->mode[2] == 0) {
        SetMotion((struct Entity*)p, 0x1503);
        p->work[2] = 0x40;
        p->mode[2]++;
      }
      t = p->work[2];
      t -= 1;
      z = 0;
      p->work[2] = t;
      if ((u8)t != 0xff) {
        break;
      }
      asm volatile("strb %0, [%1, #0xd]" ::"l"(z), "l"(p) : "memory");
    zmode:
      p->mode[2] = z;
      break;
    }
  }
  UpdateEntityAnim((struct Entity*)p);
  if (p->mode[1] == 2) {
    return;
  }
  {
    register s32 ny asm("r2");
    register s32 g asm("r0");
    register s32 r3v asm("r3");
    d = 0;
    {
      register s32 cy asm("r0");
      register s32 dy0 asm("r1");
      cy = p->coord.y;
      dy0 = p->d.y;
      ny = cy + dy0;
      p->coord.y = ny;
      if (dy0 > 0) {
        cy = p->coord.x;
        dy0 = -0x100;
        cy += dy0;
        r3v = 0xc0 << 4;
        dy0 = ny + r3v;
        if ((u16)FUN_080098a4(cy, dy0) != 0) {
          goto big;
        }
        cy = p->coord.x;
        dy0 = p->coord.y;
        {
          register s32 k2 asm("r2");
          k2 = 0xc0 << 4;
          dy0 += k2;
        }
        goto probe2;
      }
    }
    if (p->work[1] == 2) {
      register s32 cam asm("r0");
      cam = (s32)&gStageRun.vm.camera;
      cam = *(s32*)(cam + 0x3c);
      r3v = -0x5000;
      asm("" : "+r"(r3v));
      cam += r3v;
      if (ny >= cam) {
        goto done;
      }
    big:
      d = 0x80 << 5;
      goto done;
    } else {
      register s32 xx2 asm("r0");
      register s32 k4 asm("r1");
      xx2 = p->coord.x;
      k4 = -0x100;
      asm("" : "+r"(k4));
      xx2 = xx2 + k4;
      r3v = -0xc00;
      k4 = ny + r3v;
      if ((u16)FUN_080098a4(xx2, k4) != 0) {
        goto big;
      }
      {
        register s32 x3 asm("r0");
        register s32 y3 asm("r1");
        register s32 k6 asm("r2");
        x3 = p->coord.x;
        y3 = p->coord.y;
        k6 = -0xc00;
        y3 += k6;
      probe2:
        g = FUN_0800a22c(x3, y3);
        {
          register s32 cx asm("r1");
          cx = p->coord.x;
          d = cx - g;
        }
      }
    }
  done:
    {
      register s32 a asm("r1");
      a = d;
      if (a < 0) {
        a = -a;
      }
      {
        register s32 lim2 asm("r0");
        lim2 = 0x80 << 4;
        if (a > lim2) {
          register s32 nv asm("r0");
          nv = -p->d.y;
          p->d.y = nv;
          return;
        }
      }
    }
    if (p->work[1] != 1) {
      return;
    }
    {
      register s32 dy asm("r2");
      register s32 v asm("r0");
      dy = p->d.y;
      if (dy > 0) {
        register s32 w2 asm("r1");
        v = *(s32*)((u8*)p + 0xb8);
        w2 = p->coord.y;
        v -= w2;
        if (v >= -0x3000) {
          return;
        }
        goto neg;
      } else {
        register s32 w3 asm("r1");
        v = *(s32*)((u8*)p + 0xb8);
        w3 = p->coord.y;
        v -= w3;
        if (v <= (0xc0 << 6)) {
          return;
        }
      neg:
        v = -dy;
      }
      p->d.y = v;
    }
  }
}

// 0x08070000
void FUN_08070000(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  if (body->hitboxFlags & (BODY_STATUS_WHITE | BODY_STATUS_B3)) {
    struct Entity* p = (struct Entity*)body->parent;
    if (p->mode[1] != 2) {
      p->mode[1] = 2, p->mode[2] = 0;
    } else {
      p->work[2] = 64;
    }
  }
}

// --------------------------------------------

// 0x08366970
static const struct Collision sCollisions[4] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(8), PIXEL(24), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : NO_DAMAGE,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(8), PIXEL(24), PIXEL(12)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(8), PIXEL(12), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : NO_DAMAGE,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(8), PIXEL(12), PIXEL(24)},
    },
};

static const Coords32 sElementCoords[4] = {
    {PIXEL(0), -PIXEL(8)},
    {PIXEL(0), -PIXEL(8)},
    {PIXEL(0), -PIXEL(8)},
    {PIXEL(0), PIXEL(8)},
};
