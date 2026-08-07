#include "collision.h"
#include "global.h"
#include "projectile.h"

void CreateVFX57(struct Coord* c, u8 a1, u8 a2, s16 dx, s16 dy);

// Blizzack のつらら飛ばし?(Blizzack関連なのは確定)

void Projectile31_Init(Projectile* p);
void Projectile31_Update(Projectile* p);
static void Projectile31_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile31Routine = {
    [ENTITY_INIT] =      (void*)Projectile31_Init,
    [ENTITY_UPDATE] =    (void*)Projectile31_Update,
    [ENTITY_DIE] =       (void*)Projectile31_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

// 0x080aa7a8

static const s32 s32_ARRAY_0836c35c[4];
static const s32 s32_ARRAY_0836c36c[8];
static const s32 s32_ARRAY_0836c38c[8];
static const struct Collision sCollisions[2];
Entity* CreateProjectile31(Entity* q, u8 kind1, u8 kind2) {
  Projectile* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 31);
    p->work[0] = kind1, p->work[1] = kind2;
    p->unk_28 = (void*)q;
    (p->coord) = q->coord;
    return (void*)p;
  }
  return NULL;
}

void Projectile31_Init(Projectile* p) {
  register s32 z5 asm("r5");
  struct Entity* e = p->unk_28;
  InitRotatableMotion((struct Entity*)p);
  {
    register u8 f0 asm("r1");
    register s32 d0 asm("r0");
    f0 = p->flags;
    d0 = DISPLAY;
    asm("" : "+r"(d0));
    z5 = 0;
    d0 |= f0;
    {
      register s32 c2 asm("r1");
      c2 = FLIPABLE;
      d0 |= c2;
    }
    p->flags = d0;
  }
  SetMotion((struct Entity*)p, 0x640F);
  p->flags |= COLLIDABLE;
  {
    struct Body* body = &p->body;
    InitBody(body, sCollisions, &p->coord, 0x40);
    body->parent = (struct Entity*)p;
    body->fn = (BodyFunc)z5;
  }
  {
    register u8 f1 asm("r1");
    register s32 m0 asm("r0");
    f1 = p->flags;
    m0 = 0xEF;
    m0 &= f1;
    p->flags = m0;
  }
  (p->spr).xflip = z5;
  {
    u8* a = (u8*)p + 0x4a;
    register u8 b asm("r1");
    s32 msk;
    b = *a;
    msk = -0x11;
    msk &= b;
    *a = msk;
  }
  p->coord = e->coord;
  {
    s32 dx;
    if (e->flags & 0x10) {
      p->coord.x = e->coord.x + s32_ARRAY_0836c35c[p->work[1] & 3];
      dx = s32_ARRAY_0836c36c[p->work[1]];
    } else {
      p->coord.x = e->coord.x - s32_ARRAY_0836c35c[p->work[1] & 3];
      dx = -s32_ARRAY_0836c36c[p->work[1]];
    }
    p->d.x = dx;
  }
  {
    register s32 wk asm("r2");
    s32 dy;
    wk = *(volatile u8*)&p->work[1];
    asm("" : "+r"(wk));
    p->coord.y = e->coord.y - 0x3000;
    dy = s32_ARRAY_0836c38c[wk];
    asm volatile("" :: "r"(wk));
    p->d.y = dy;
    {
      s32 an = ((u16)ArcTan2(*(volatile s32*)&p->d.x, dy) + 0x4000) >> 8;
      p->work[3] = an;
      p->angle = an;
    }
  }
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  Projectile31_Update(p);
}

void Projectile31_Update(Projectile* p) {
  UpdateEntityAnim((struct Entity*)p);
  {
    s32 an = ((u16)ArcTan2(p->d.x, p->d.y) + 0x4000) >> 8;
    p->work[3] = an;
    p->angle = an;
  }
  p->coord.x += p->d.x;
  p->coord.y += p->d.y;
  p->d.y += 0x40;
  if (FUN_080098a4(p->coord.x, p->coord.y) != 0) {
    CreateVFX57(&p->coord, 1, 1, (RANDOM(RNG_0202f388) & 0xFF) | 0x100,
                -((RANDOM(RNG_0202f388) & 0x3FF) + 0x100));
    CreateVFX57(&p->coord, 1, 3, -((RANDOM(RNG_0202f388) & 0xFF) + 0x100),
                -((RANDOM(RNG_0202f388) & 0x3FF) + 0x100));
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  }
}

static void Projectile31_Die(Projectile* p) {
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
};

// --------------------------------------------

static const s32 s32_ARRAY_0836c35c[4] = {PIXEL(8), PIXEL(8), PIXEL(32), PIXEL(32)};

static const s32 s32_ARRAY_0836c36c[8] = {
    0x140, 0x180, 0x200, 0x280, 0xA0, 0xC0, 0x100, 0x140,
};

static const s32 s32_ARRAY_0836c38c[8] = {
    -0x600, -0x500, -0x400, -0x300, -0xC00, -0xA00, -0x800, -0x600,
};
