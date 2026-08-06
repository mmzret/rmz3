#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "stagerun.h"

NON_MATCH void FUN_080b2178(struct Body* body);
NON_MATCH void FUN_080b21c0(struct Body* body);
struct Entity* CreateSmoke(u8 kind, struct Coord* c);
s32 PushoutToUp1(s32 x, s32 y);
void FUN_080b2204(struct Body* body);

// Minigame?

void FUN_080b1a48(Projectile* p);
void FUN_080b1b28(Projectile* p);
void FUN_080b1b40(Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile45Routine = {
    [ENTITY_INIT] =      (void*)FUN_080b1a48,
    [ENTITY_UPDATE] =    (void*)FUN_080b1b28,
    [ENTITY_DIE] =       (void*)FUN_080b1b40,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// 0x080b18d4

static const struct Collision Collision_ARRAY_0836d7dc[8];
static const ProjectileFunc PTR_ARRAY_0836d7cc[4];
Entity* FUN_080b18d4(Coords32* c1, Coords32* c2, u8 element) {
  Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 45);
    p->work[0] = 0, p->work[1] = element;
    (p->coord).x = c1->x, (p->coord).y = c1->y;
    (p->unk_coord).x = c2->x, (p->unk_coord).y = c2->y;
  }
  return p;
}

// 0x080B1934
Entity* FUN_080b1934(void* q, Coords32* c, u8 kind) {
  Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 45);
    p->work[0] = 1, p->work[1] = kind;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->unk_28 = q;
  }
  return p;
}

// 0x080B1990
Entity* FUN_080b1990(void* q, Coords32* c, u8 kind) {
  Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 45);
    p->work[0] = 2, p->work[1] = kind;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->unk_28 = q;
  }
  return p;
}

// 0x080B19EC
Entity* FUN_080b19ec(void* q, Coords32* c, u8 kind) {
  Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 45);
    p->work[0] = 3, p->work[1] = kind;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->unk_28 = q;
  }
  return p;
}

void FUN_080b1a48(Projectile* p) {
  register u8 fv asm("r1");
  register s32 w asm("r5");
  InitNonAffineMotion((struct Entity*)p);
  {
    register u8 f0 asm("r0");
    f0 = p->flags;
    fv = DISPLAY;
    fv |= f0;
    f0 = FLIPABLE;
    fv |= f0;
    p->flags = fv;
  }
  w = p->work[0];
  if (w == 0) {
    register s32 one asm("r2");
    {
      register u8 k asm("r0");
      k = 0xEF;
      fv &= k;
      p->flags = fv;
    }
    one = 1;
    {
      register u8* a asm("r0");
      register u8* b asm("r3");
      register s32 v asm("r1");
      register s32 m asm("r0");
      a = (u8*)p + 0x4c;
      *a = w;
      b = (u8*)p + 0x4a;
      v = *b;
      m = 0x11;
      m = -m;
      m &= v;
      *b = m;
    }
    {
      u32 tbl = (u32)gProjectileFnTable;
      EntityFunc** rt = (EntityFunc**)(tbl + ((p->id) << 2));
      *(u32*)(p->mode) = one;
      p->onUpdate = (void*)((*rt)[1]);
    }
    p->mode[1] = w;
    p->mode[2] = w;
    p->mode[3] = w;
  } else if (w == 1) {
    register s32 z asm("r2");
    z = 0;
    {
      register u8 k asm("r0");
      k = 0xEF;
      fv &= k;
      p->flags = fv;
    }
    {
      register u8* a asm("r0");
      register u8* b asm("r3");
      register s32 v asm("r1");
      register s32 m asm("r0");
      a = (u8*)p + 0x4c;
      *a = z;
      b = (u8*)p + 0x4a;
      v = *b;
      m = 0x11;
      m = -m;
      m &= v;
      *b = m;
    }
    {
      u32 tbl = (u32)gProjectileFnTable;
      EntityFunc** rt = (EntityFunc**)(tbl + ((p->id) << 2));
      *(u32*)(p->mode) = w;
      p->onUpdate = (void*)((*rt)[1]);
    }
    p->mode[1] = w;
    p->mode[2] = z;
    p->mode[3] = z;
  } else {
    register s32 z asm("r2");
    register s32 one asm("r3");
    if (w != 2) {
      asm("" : "+r"(w));
      if (w != 3) {
        goto tail;
      }
    }
    z = 0;
    {
      register u8 k asm("r0");
      k = 0xEF;
      fv &= k;
      p->flags = fv;
    }
    one = 1;
    {
      register u8* a asm("r0");
      register u8* b;
      register s32 v asm("r1");
      register s32 m asm("r0");
      a = (u8*)p + 0x4c;
      *a = z;
      b = (u8*)p + 0x4a;
      v = *b;
      m = 0x11;
      m = -m;
      m &= v;
      *b = m;
    }
    {
      u32 tbl = (u32)gProjectileFnTable;
      EntityFunc** rt = (EntityFunc**)(tbl + ((p->id) << 2));
      *(u32*)(p->mode) = one;
      p->onUpdate = (void*)((*rt)[1]);
    }
    p->mode[1] = w;
    p->mode[2] = z;
    p->mode[3] = z;
  }
tail:
  p->work[2] = 0xFF;
  *((u8*)p + 0xbc) = 0;
  FUN_080b1b28(p);
}

void FUN_080b1b28(Projectile* p) {
  (PTR_ARRAY_0836d7cc[p->mode[1]])(p);
}

void FUN_080b1b40(Projectile* p) {
  p->flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

void FUN_080b1b7c(Projectile* p) {
  if (*(u8*)((u8*)p + 0xbc) != 0) {
    (p->body).status = 0;
    (p->body).prevStatus = 0;
    (p->body).invincibleTime = 0;
    p->flags &= ~COLLIDABLE;
    goto die;
  }
  if (!((p->body).status & 4)) {
    s32 t = p->work[2] - 1;
    p->work[2] = t;
    if ((t << 24) == 0) {
    die:
      SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
      return;
    }
  }
  {
  register s32 m asm("r6");
  m = p->mode[2];
  switch (m) {
    case 0: {
      register struct Body* b asm("r4");
      b = NULL;
      p->work[2] = 0x3C;
      InitNonAffineMotion((struct Entity*)p);
      p->angle = m;
      (p->spr).mag.x = 0x100;
      (p->spr).mag.y = 0x100;
      if (p->work[1] == 0) {
        p->flags |= COLLIDABLE;
        b = &p->body;
        InitBody(b, &Collision_ARRAY_0836d7dc[0], &p->coord, 1);
        b->parent = (void*)p;
        b->fn = (void*)m;
        SetMotion((struct Entity*)p, 0x5B00);
      } else if (p->work[1] == 1) {
        p->flags |= COLLIDABLE;
        b = &p->body;
        InitBody(b, &Collision_ARRAY_0836d7dc[1], &p->coord, 1);
        b->parent = (void*)p;
        b->fn = (void*)m;
        SetMotion((struct Entity*)p, 0x5C00);
      } else {
        b = &p->body;
        if (p->work[1] == 2) {
          p->flags |= COLLIDABLE;
          InitBody(b, &Collision_ARRAY_0836d7dc[2], &p->coord, 1);
          b->parent = (void*)p;
          b->fn = (void*)m;
          SetMotion((struct Entity*)p, 0x5F00);
        }
      }
      b->fn = (void*)FUN_080b2178;
      {
        register s32 dz asm("r0");
        dz = 0;
        asm("" : "+r"(dz));
        p->d.y = dz;
      }
      p->d.x = 0x500;
      p->mode[2]++;
    }
      /* fallthrough */
    case 1:
      p->coord.x += p->d.x;
      UpdateEntityAnim((struct Entity*)p);
      break;
  }
  }
}

void FUN_080b1cbc(Projectile* p) {
  register s32 z asm("r6");
  struct Coord c;
  u8* pb = (u8*)p + 0xbc;
  z = *pb;
  if (z != 0) {
    {
      register u8* a asm("r0");
      register s32 z1 asm("r1");
      a = pb - 0x30;
      z1 = 0;
      asm volatile("str %0, [%1]" ::"l"(z1), "l"(a) : "memory");
      a += 4;
      asm("" : "+r"(a));
      asm volatile("str %0, [%1]" ::"l"(z1), "l"(a) : "memory");
      a += 4;
      asm("" : "+r"(a));
      *a = z1;
    }
    p->flags &= ~COLLIDABLE;
    {
      s32 cx = p->coord.x;
      s32 cy = p->coord.y;
      s32 k;
      c.x = cx;
      c.y = cy;
      k = 0x80 << 4;
      *(volatile s32*)&c.x = *(volatile s32*)&c.x + k;
      *(volatile s32*)&c.y = *(volatile s32*)&c.y + k;
    }
    {
      struct Entity* q = p->unk_28;
      if (*(s16*)((u8*)q + 4) != 2) {
        *(s32*)((u8*)q + 0x1c) += 1;
        PlaySound(0x137);
      }
    }
    PlaySound(0x2a);
    CreateSmoke(1, &c);
    goto exit;
  }
  {
    s32 t = p->work[2] - 1;
    p->work[2] = t;
    if ((t << 24) == 0) {
      goto dec;
    }
  }
  switch (p->mode[2]) {
    case 0: {
      register struct Body* b asm("r4");
      InitNonAffineMotion((struct Entity*)p);
      {
        register u8* a asm("r0");
        register s32 mg asm("r1");
        a = (u8*)p + 0x24;
        *a = z;
        a += 0x2c;
        asm("" : "+r"(a));
        mg = 0x80 << 1;
        *(u16*)a = mg;
        a += 2;
        asm("" : "+r"(a));
        *(u16*)a = mg;
      }
      if (p->work[1] == 0) {
        p->flags |= COLLIDABLE;
        b = &p->body;
        InitBody(b, (const struct Collision*)0x0836D824, &p->coord, 1);
        b->parent = (void*)p;
        b->fn = (void*)z;
        SetMotion((struct Entity*)p, 0x0E08);
      } else if (p->work[1] == 1) {
        p->flags |= COLLIDABLE;
        b = &p->body;
        InitBody(b, (const struct Collision*)0x0836D83C, &p->coord, 1);
        b->parent = (void*)p;
        b->fn = (void*)z;
        SetMotion((struct Entity*)p, 0x0E07);
      } else {
        b = &p->body;
        if (p->work[1] == 2) {
          p->flags |= COLLIDABLE;
          InitBody(b, (const struct Collision*)0x0836D854, &p->coord, 1);
          b->parent = (void*)p;
          b->fn = (void*)z;
          SetMotion((struct Entity*)p, 0x0E09);
        }
      }
      b->fn = (void*)FUN_080b21c0;
      {
        register s32 dz asm("r0");
        dz = 0;
        p->d.y = dz;
        dz -= 0xa8;
        p->d.x = dz;
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 r;
      p->d.y += 0x10;
      if (p->d.y > 0x700) {
        p->d.y = 0x700;
      }
      p->coord.y += p->d.y;
      UpdateEntityAnim((struct Entity*)p);
      r = PushoutToUp1(p->coord.x - 0x800, p->coord.y + (0xb0 << 4));
      if (r == 0) {
        break;
      }
      p->coord.y += r;
      goto adv;
    }
    case 2:
      p->coord.x += p->d.x;
      UpdateEntityAnim((struct Entity*)p);
      if (FUN_08009f6c(p->coord.x + (0xc0 << 4), p->coord.y - 0x1000) ==
          p->coord.y + (0xb0 << 4)) {
        break;
      }
      p->d.y = z;
      p->d.x = -0x80;
      p->work[3] = 0x28;
    adv:
      p->mode[2]++;
      break;
    case 3:
      p->d.y += 0x20;
      if (p->d.y > 0x700) {
        p->d.y = 0x700;
      }
      p->coord.y += p->d.y;
      p->coord.x += p->d.x;
      UpdateEntityAnim((struct Entity*)p);
      if (p->work[3] != 0) {
        s32 t = p->work[3] - 1;
        p->work[3] = t;
        if ((t << 24) != 0) {
          break;
        }
      }
    dec: {
      struct Entity* q = p->unk_28;
      if (q->mode[0] != 0) {
        q->mode[0]--;
      }
    }
    exit:
      SET_PROJECTILE_ROUTINE(p, 2);
      break;
  }
}

void FUN_080b1f00(Projectile* p) {
  if (*(s16*)((u8*)p->unk_28 + 4) == 2) {
    p->work[2] = 0xFF;
  }
  if ((u8)--p->work[2] == 0) {
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
    return;
  }
  switch (p->mode[2]) {
    case 0: {
      s32 y;
      InitNonAffineMotion((struct Entity*)p);
      y = FUN_08009f6c(p->coord.x, p->coord.y);
      p->coord.y = y;
      if (y <= 0x117FF) {
        goto die;
      }
      if (y > 0x13BFF) {
        goto land;
      }
      {
        FUN_0800a31c(p->coord.x, y - 0x800);
        FUN_0800a22c(p->coord.x, p->coord.y - 0x800);
        if (FUN_08009f6c(p->coord.x - 0x2000, p->coord.y - 0x800) > 0x13C00) {
          goto die;
        }
        if (FUN_08009f6c(p->coord.x + 0x2000, p->coord.y - 0x800) <= 0x13C00) {
          goto land;
        }
      }
    die:
      SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
      p->flags &= ~DISPLAY;
      return;
    land : {
      s32 z;
      p->renderPrio = 0x12;
      z = 0;
      p->flags |= COLLIDABLE;
      {
        struct Body* body = &p->body;
        InitBody(body, &Collision_ARRAY_0836d7dc[6], &p->coord, 1);
        body->parent = (struct Entity*)p;
        body->fn = (void*)z;
      }
      SetMotion((struct Entity*)p, MOTION(0xF3, 0x00));
      p->work[2] = 0xB4;
      p->mode[2]++;
    }
      FALLTHROUGH;
    }
    case 1:
      if ((p->unk_28)->mode[1] == 1) {
        p->coord.x += -0x3C000;
      }
      UpdateEntityAnim((struct Entity*)p);
      Camera_GetDistance(&gStageRun.vm.camera, &p->coord);
      break;
  }
}

void FUN_080b2044(Projectile* p) {
  register s32 z6 asm("r6");
  if (*(s16*)((u8*)p->unk_28 + 4) == 2) {
    p->work[2] = 0xFF;
  }
  {
    s32 t = p->work[2] - 1;
    z6 = 0;
    p->work[2] = t;
    if ((t << 24) == 0) {
      SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
      return;
    }
  }
  if (*((u8*)p + 0xbc) == 1 && p->mode[2] != 2) {
    register s32 z4 asm("r4");
    struct Entity* e = p->unk_28;
    u16* cnt = (u16*)((u8*)e + 0xe);
    s32 c1 = *cnt + 1;
    z4 = 0;
    *cnt = c1;
    PlaySound(0x137);
    p->flags &= 0xFE;
    (p->body).status = z6;
    (p->body).prevStatus = z6;
    (p->body).invincibleTime = z4;
    p->flags &= ~COLLIDABLE;
    p->work[2] = 0x10;
    p->mode[2] = 2;
  }
  switch (p->mode[2]) {
    case 0: {
      struct Body* body;
      InitNonAffineMotion((struct Entity*)p);
      p->flags |= COLLIDABLE;
      body = &p->body;
      InitBody(body, &Collision_ARRAY_0836d7dc[7], &p->coord, 1);
      body->parent = (struct Entity*)p;
      body->fn = (BodyFunc)FUN_080b2204;
      SetMotion((struct Entity*)p, 0xAA04);
      p->work[2] = 0xB4;
      p->mode[2]++;
    }
      /* fallthrough */
    case 1:
      if ((p->unk_28)->mode[1] == 1) {
        p->coord.x += -0x3C000;
      }
      UpdateEntityAnim((struct Entity*)p);
      {
        struct Camera* cam = &gStageRun.vm.camera;
        Camera_GetDistance(cam, &p->coord);
      }
      break;
    case 2:
      {
        register s32 wv asm("r0");
        register s32 c3 asm("r1");
        wv = p->work[2];
        c3 = 3;
        wv &= c3;
        if (wv == 0) {
          PlaySound(0x22);
        }
      }
      if ((p->unk_28)->mode[1] == 1) {
        p->coord.x += -0x3C000;
      }
      break;
  }
}

NON_MATCH void FUN_080b2178(struct Body* body) {
#if MODERN
  u8 win = 0;
  struct Entity* parent = body->parent;
  struct CollidableEntity* other = (body->enemy)->parent;
  u32 a;
  if (((struct Entity*)parent)->work[1] == 0 && ((struct Entity*)other)->work[1] == 2) {
    win = 1;
  }
  a = ((struct Entity*)parent)->work[1];
  if (a == 1 && ((struct Entity*)other)->work[1] == 0) {
    win = 1;
  }
  if (a == 2 && ((struct Entity*)other)->work[1] == 1) {
    win = 1;
  }
  *(u8*)((u8*)parent + 0xbc) = 1;
  if (win == 1) {
    *(u8*)((u8*)parent + 0xbc) = win;
  }
#else
  INCCODE("asm/projectile/unk_45_2178.inc");
#endif
}

NON_MATCH void FUN_080b21c0(struct Body* body) {
#if MODERN
  u8 win = 0;
  struct Entity* parent = body->parent;
  struct CollidableEntity* other = (body->enemy)->parent;
  u32 a;
  if (((struct Entity*)other)->work[1] == 0 && ((struct Entity*)parent)->work[1] == 2) {
    win = 1;
  }
  a = ((struct Entity*)other)->work[1];
  if (a == 1 && ((struct Entity*)parent)->work[1] == 0) {
    win = 1;
  }
  if (a == 2 && ((struct Entity*)parent)->work[1] == 1) {
    win = 1;
  }
  if (win == 1) {
    *(u8*)((u8*)parent + 0xbc) = win;
  }
#else
  INCCODE("asm/projectile/unk_45_21c0.inc");
#endif
}

void FUN_080b2204(struct Body* body) {
  struct Entity* parent = body->parent;
  if ((body->enemy->processing)->faction == 0) {
    *(u8*)((u8*)parent + 0xbc) = 1;
  }
}

void FUN_080b1b7c(Projectile* p);
void FUN_080b1cbc(Projectile* p);
void FUN_080b1f00(Projectile* p);
void FUN_080b2044(Projectile* p);

// clang-format off
static const ProjectileFunc PTR_ARRAY_0836d7cc[4] = {
    FUN_080b1b7c,
    FUN_080b1cbc,
    FUN_080b1f00,
    FUN_080b2044,
};
// clang-format on

static const struct Collision Collision_ARRAY_0836d7dc[8] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      damage : 2,
      element : ELEMENT_FLAME,
      remaining : 0,
      layer : 0x00000004,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      damage : 2,
      element : ELEMENT_THUNDER,
      remaining : 0,
      layer : 0x00000002,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      damage : 2,
      element : ELEMENT_ICE,
      remaining : 0,
      layer : 0x00000008,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      layer : 0x000A5294,
      range : {PIXEL(8), PIXEL(8), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      layer : 0x0046318C,
      range : {PIXEL(8), PIXEL(8), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      layer : 0x004C6318,
      range : {PIXEL(8), PIXEL(8), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(28), PIXEL(44)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      damage : 255,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
};
