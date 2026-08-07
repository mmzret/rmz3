#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "score.h"

void nop_0807fd1c(struct Body* body, Coords32* c1, Coords32* c2);
struct Entity* FUN_080becf8(struct Coord* c, u8 kind, motion_t m, u32 n);

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
// clang-format on


static const EnemyFunc sUpdates1[3];
static const EnemyFunc sUpdates2[3];
struct Entity* createHellBouncer(struct Entity* q, Coords32* c, u8 r2, u8 idx) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_HELL_BOUNCER);
    p->coord = *c;
    p->work[0] = r2, p->work[1] = idx;
    p->unk_28 = q;
  }
  return p;
}

void HellBouncer_Init(struct Enemy* p) {
  register struct Body* b asm("r4");
  register s32 z5 asm("r5");
  s32 z7;
  s32 k10;
  struct Entity* q;
  InitNonAffineMotion(&p->s);
  ResetDynamicMotion(&p->s);
  {
    register s32 f asm("r0");
    register u8 fl asm("r1");
    register s32 k asm("r1");
    fl = (p->s).flags;
    f = 0xFE;
    f &= fl;
    z5 = 0;
    asm("" : "+r"(z5));
    k = 2;
    f |= k;
    z7 = 0;
    asm("" : "+r"(z7));
    k = 4;
    f |= k;
    (p->s).flags = f;
  }
  b = &p->body;
  ((void (*)(struct Body*, const struct Collision*, struct Coord*, s32))InitBody)(b, (const struct Collision*)0x08367D98, &(p->s).coord, 0x40);
  b->parent = (struct Entity*)p;
  b->fn = (BodyFunc)z5;
  asm volatile("" ::: "memory");
  *(s32*)((u8*)p + 0xb4) = 0x40;
  b->fn = (BodyFunc)nop_0807fd1c;
  {
    register u8 f2 asm("r0");
    f2 = (p->s).flags2;
    k10 = 0x10;
    f2 |= k10;
    (p->s).flags2 = f2;
  }
  q = (p->s).unk_28;
  (p->s).invincibleID = q->uniqueID;
  {
    register s32 w asm("r3");
    w = (p->s).work[0];
    if (w == 1) {
      register s32 xf asm("r2");
      register s32 t0 asm("r0");
      t0 = q->flags;
      xf = t0 >> 4;
      xf &= w;
      if (xf != 0) {
        register u8 f3 asm("r0");
        f3 = (p->s).flags;
        f3 |= k10;
        (p->s).flags = f3;
      } else {
        register u8 h asm("r1");
        register u8 g asm("r0");
        h = (p->s).flags;
        asm("" : "+r"(h));
        g = 0xEF;
        g &= h;
        (p->s).flags = g;
      }
      {
        register s32 v asm("r1");
        register u8* oa asm("r3");
        s32 sh4, ov, m11;
        v = 1;
        v &= xf;
        *((u8*)p + 0x4c) = v;
        oa = (u8*)p + 0x4a;
        sh4 = v << 4;
        ov = *oa;
        m11 = -0x11;
        m11 &= ov;
        m11 |= sh4;
        *oa = m11;
      }
    }
  }
  {
    register s32 zz asm("r2");
    u8* a;
    zz = 0;
    (p->s).d.y = zz;
    (p->s).d.x = zz;
    a = (u8*)p + 0xbc;
    *(u32*)a = zz;
    asm("" : "+r"(a));
    a -= 3;
    asm("" : "+r"(a));
    *a = zz;
    {
      u8 w1 = (p->s).work[1];
      asm("" : "+r"(a));
      a -= 1;
      asm("" : "+r"(a));
      *a = w1;
    }
    asm("" : "+r"(a));
    a += 3;
    asm("" : "+r"(a));
    *a = zz;
    asm("" : "+r"(a));
    a += 6;
    asm("" : "+r"(a));
    *a = zz;
    asm("" : "+r"(a));
    a += 1;
    asm("" : "+r"(a));
    *a = zz;
    {
      register s32 w0 asm("r3");
      w0 = (p->s).work[0];
      if (w0 == 1) {
        register u32 tbl asm("r1");
        EntityFunc** rt;
        tbl = (u32)gEnemyFnTable;
        asm("" : "+r"(tbl));
        rt = (EntityFunc**)((((p->s).id) << 2) + tbl);
        *(u32*)((p->s).mode) = w0;
        (p->s).onUpdate = (void*)(*rt)[1];
        *((u8*)p + 0xd) = zz;
        asm volatile("");
      } else {
        SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
        (p->s).mode[1] = 2;
      }
    }
    (p->s).mode[2] = zz;
    (p->s).mode[3] = zz;
  }
  if (IsFrozen(&p->s)) {
    SetMotion(&p->s, MOTION(0xAB, 0x1B));
    UpdateEntityAnim(&p->s);
  }
  HellBouncer_Update(p);
  asm volatile("" ::"l"(z5), "l"(z7));
}

void HellBouncer_Update(struct Enemy* p) {
  register s32* st asm("r4");
  register s32* a asm("r0");
  *((u8*)p + 0xbb) = 0;
  {
    register u32* wp asm("r3");
    struct Entity* q;
    wp = gWhitePaintFlags;
    asm("" : "+r"(wp));
    q = (p->s).unk_28;
    if (wp[q->invincibleID >> 5] & (1 << (q->invincibleID & 0x1F))) {
      PaintEntityWhite(&p->s);
    } else {
      UpdateEntityPaletteID(&p->s);
    }
  }
  if (*((u8*)(p->s).unk_28 + 0x94) != 0) {
    *((u8*)p + 0x94) = 0x80;
  } else {
    register u8* ip asm("r2");
    register s32 v asm("r1");
    register s32 m asm("r0");
    ip = (u8*)p + 0x94;
    v = *ip;
    m = 0x7f;
    m &= v;
    *ip = m;
  }
  {
    register s32 v0 asm("r1");
    register s32 one asm("r2");
    a = (s32*)((u8*)p + 0x8c);
    v0 = *a;
    one = 1;
    v0 &= one;
    st = a;
    if (v0 == 0) {
      goto nohit;
    }
  }
  {
    register u8* hp asm("r2");
    register s32 v asm("r1");
    s32 d;
    hp = (u8*)p + 0xb4;
    a = (s32*)((u8*)a + 0x18);
    asm("" : "+r"(a));
    v = *(s16*)a;
    d = *(s32*)hp;
    d -= v;
    hp += 7;
    asm("" : "+r"(hp));
    *hp = d;
    {
      struct Entity* q = (p->s).unk_28;
      if (*((u8*)q + 0x94) == 0) {
        CalcPutitedSpikeDamage((struct Body*)((u8*)q + 0x74), *hp);
      }
    }
  }
nohit:
  {
    register u8* c2 asm("r2");
    register s32 cv asm("r0");
    c2 = (u8*)p + 0xc2;
    cv = *c2;
    if (cv == 0) {
      if (*st & 4) {
        *c2 = 0x3c;
        PlaySound(0x52);
      }
    } else {
      cv -= 1;
      *c2 = cv;
    }
  }
  if (((p->s).unk_28)->mode[0] > 1) {
    register u32 r asm("r4");
    register u8* kp asm("r5");
    struct Coord c;
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    r = RANDOM(RNG_0202f388) & 3;
    c.x = (p->s).coord.x;
    c.y = (p->s).coord.y;
    kp = (u8*)p + 0xb8;
    FUN_080becf8(&c, *kp, 0xAB28, r);
    FUN_080becf8(&c, *kp, 0xAB29, r);
    FUN_080becf8(&c, *kp, 0xAB2A, r);
    FUN_080becf8(&c, *kp, 0xAB2B, r);
    HellBouncer_Die(p);
  } else {
    sUpdates1[(p->s).mode[1]](p);
    if (IsFrozen(&p->s)) {
      register s32 mv asm("r1");
      register u8* dp asm("r0");
      mv = (p->s).mode[1];
      dp = (u8*)p + 0xba;
      *dp = mv;
    } else {
      sUpdates2[(p->s).mode[1]](p);
      *(s32*)((u8*)p + 0xb4) = *(s16*)((u8*)p + 0xa4);
    }
  }
}

void HellBouncer_Die(struct Enemy* p) {
  if (gScore.enemyCount <= 0x270E) {
    gScore.enemyCount++;
  }
  TryDropZakoDisk((struct Entity*)p, &(p->s).coord);
  (p->s).flags &= ~DISPLAY;
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
}

bool8 FUN_0807e5f0(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/hell_bouncer_a.inc");

bool8 FUN_0807ead8(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/hell_bouncer_b.inc");

bool8 FUN_0807f644(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/hell_bouncer_c.inc");

bool8 FUN_0807e5f0(struct Enemy* p);
bool8 FUN_0807ead8(struct Enemy* p);
bool8 FUN_0807f644(struct Enemy* p);

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
