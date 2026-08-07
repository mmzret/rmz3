#include "boss/copy_x.h"
#include "collision.h"
#include "gfx.h"
#include "global.h"
#include "metatile.h"
#include "projectile.h"
#include "trig.h"
#include "stagerun.h"

void FUN_080aa15c(struct Sprite* spr, struct DrawPivot* dp);

// コピーXのチャージショット + レイジングエクスチャージ(ﾓｳﾕﾙｻﾝ!)
typedef struct {
  COLLISION_OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  Coords32 c_b4;  // 0xB4
  u8 unk_bc[8];   // 0xBC
} Projectile28;
static_assert(sizeof(Projectile28) == sizeof(Projectile));

// Entity.work[0]
enum {
  PJ28_0_UNK = 0,
  PJ28_1_UNK = 1,
  PJ28_2_RAGING_EX_CHARGE = 2,  // レイジングエクスチャージ(ﾓｳﾕﾙｻﾝ!)
  PJ28_3_UNUSED = 3,            // 使われてなさそう, 2のレイジングエクスチャージと似たような処理っぽい
};

void FUN_080a90a0(struct Entity* e, u8 param_2, u8 param_3);

static void Projectile28_Init(Projectile28* p);
static void Projectile28_Update(Projectile28* p);
static void Projectile28_Die(Projectile28* p);

// clang-format off
const ProjectileRoutine gProjectile28Routine = {
    [ENTITY_INIT] =      (void*)Projectile28_Init,
    [ENTITY_UPDATE] =    (void*)Projectile28_Update,
    [ENTITY_DIE] =       (void*)Projectile28_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

// 0x080a9aa0
void CreateProjectile28(struct Entity* e, u8 kind, u8 unusedval) {
  struct Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 28);
    p->work[0] = kind, p->work[1] = unusedval;
    p->unk_28 = (void*)e;
    p->coord = e->coord;
  }
}

// --------------------------------------------

static void FUN_080a9b90(Projectile28* p);
static void FUN_080a9d88(Projectile28* p);
static void Projectile28_Init_RagingEXCharge(Projectile28* p);
void FUN_080aa08c(Projectile28* p);

static void Projectile28_Init(Projectile28* p) {
  static void (*const PTR_ARRAY_0836c20c[4])(Projectile28*) = {
      FUN_080a9b90,
      FUN_080a9d88,
      Projectile28_Init_RagingEXCharge,
      FUN_080aa08c,
  };  // 0x0836c20c
  (PTR_ARRAY_0836c20c[p->work[0]])(p);
}

static void FUN_080a9c88(Projectile28* p);
static void FUN_080a9dcc(Projectile28* p);
void FUN_080a9ef8(Projectile28* p);
void FUN_080aa120(Projectile28* p);

static void Projectile28_Update(Projectile28* p) {
  static void (*const PTR_ARRAY_0836c21c[4])(Projectile28*) = {
      FUN_080a9c88,
      FUN_080a9dcc,
      FUN_080a9ef8,
      FUN_080aa120,
  };  // 0x0836c21c
  (PTR_ARRAY_0836c21c[p->work[0]])(p);
}

static void Projectile28_Die(Projectile28* p) {
  if (p->work[0] >= PJ28_2_RAGING_EX_CHARGE) {
    gWindowRegBuffer.dispcnt &= ~DISPCNT_WIN1_ON;
    gWindowRegBuffer.winin[2] |= 0xFE;
    gPaletteManager.buf[0] = RGB_BLACK;
  }
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static const struct Collision sCollisions[];

static void FUN_080a9b90(Projectile28* p) {
  struct Entity* q = p->unk_28;
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM095_COPYX_CHARGE, 0));
  SET_XFLIP(p, (q->flags & X_FLIP) != 0);
  if (p->flags & X_FLIP) {
    p->coord.x += PIXEL(31);
    p->d.x = PIXEL(1) / 2;
    p->work[2] = 0x7F;
  } else {
    p->coord.x -= PIXEL(31);
    p->d.x = -PIXEL(1) / 2;
    p->work[2] = 0x0;
  }
  p->coord.y -= PIXEL(24);
  p->d.y = 0;
  p->work[3] = 0;
  INIT_BODY(p, &sCollisions[0], 64, NULL);
  (p->c_b4).x = p->coord.x, (p->c_b4).y = p->coord.y;
  p->mode[2] = 1;
  Projectile28_Update((void*)p);
}

static void FUN_080a9c88(Projectile28* p) {
  UpdateSpriteAnimation(p);
  if (p->flags & X_FLIP) {
    (p->coord).x = (p->c_b4).x + COS(p->work[2]) * 11;
    (p->coord).y = (p->c_b4).y + SIN(p->work[2]) * 22;
    p->work[2] += 16;
    p->d.x += 8;
    if (p->d.x > PIXEL(2)) p->d.x = PIXEL(2);
  } else {
    (p->coord).x = (p->c_b4).x + COS(p->work[2]) * 11;
    (p->coord).y = (p->c_b4).y + SIN(p->work[2]) * 22;
    p->work[2] -= 16;
    p->d.x -= 8;
    if (p->d.x < -PIXEL(2)) p->d.x = -PIXEL(2);
  }
  if (((p->work[3]++) & 3) == 0) FUN_080a90a0((void*)p, 6, 0);
  (p->c_b4).x += p->d.x;
  if (FUN_080098a4((p->coord).x, (p->coord).y)) {
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  }
}

static void FUN_080a9d88(Projectile28* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  EnableSpriteAnimation_Normal(p);
  (p->flags) |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM095_COPYX_CHARGE, 1));
  p->mode[2] = 1;
  Projectile28_Update(p);
}

static void FUN_080a9dcc(Projectile28* p) {
  BossCopyX* q = (BossCopyX*)(p->unk_28);
  p->coord = q->coord;
  SET_XFLIP(p, (q->flags & X_FLIP) != 0);
  if (q->unk_c6) {
    if (p->mode[2] != 0) SetSpriteAnimation(p, MOTION(SM095_COPYX_CHARGE, 1));
    p->flags |= DISPLAY;
    p->mode[2] = 0;
  } else {
    p->flags &= ~DISPLAY;
    p->mode[2] = 1;
  }
  UpdateSpriteAnimation(p);
  if (q->mode[0] >= ENTITY_DIE) SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
}

void FUN_080a9fe4(struct Sprite* s, struct DrawPivot* dp);

// 0x080a9e74
static void Projectile28_Init_RagingEXCharge(Projectile28* p) {
  struct Entity* q = p->unk_28;
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  SetTaskCallback((void*)&p->spr, FUN_080a9fe4);
  (p->spr).sprites = (void*)p;
  p->flags &= ~USE_COMMON_OAM_RENDERER;
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  p->coord = q->coord;
  gWindowRegBuffer.dispcnt |= DISPCNT_WIN1_ON;
  gWindowRegBuffer.winin[1] = WININ_WIN0_CLR | WININ_WIN0_OBJ | WININ_WIN0_BG0;
  gWindowRegBuffer.winin[2] |= WINOUT_WIN01_BG3 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG1;
  (*(u16*)(&gPaletteManager.buf[0])) = RGB_WHITE;  // NOTE: gPaletteManager.buf[0] = RGB_WHITE; だとコンパイル結果が一致しなかった
  p->work[2] = p->work[3] = 0;
  Projectile28_Update(p);
}

void FUN_080a9ef8(Projectile28* p) {
  register s32 ms asm("r1");
  register s32 m asm("r6");
  {
    register s32 t0 asm("r0");
    register u16 raw asm("r1");
    raw = gStageRun.missionStatus;
    t0 = 8;
    t0 &= raw;
    asm("" : "+r"(t0));
    t0 <<= 16;
    ms = (u32)t0 >> 16;
  }
  if (ms != 0) {
    SET_PROJECTILE_ROUTINE(p, 2);
    Projectile28_Die((Projectile28*)p);
    return;
  }
  m = p->mode[1];
  switch (m) {
    case 0: {
      s32 t = p->work[3] + 4;
      p->work[3] = t;
      if ((u8)t <= 0x1F) {
        break;
      }
      p->mode[1]++;
      p->work[2] = 0x78;
      p->flags |= 4;
      {
        struct Body* body = &p->body;
        InitBody(body, &sCollisions[2], &p->coord, 1);
        body->parent = (struct Entity*)p;
        body->fn = (void*)m;
      }
      break;
    }
    case 1: {
      s32 t = p->work[2] - 1;
      p->work[2] = t;
      if ((u8)t != 0xFF) {
        break;
      }
      p->mode[1]++;
      {
        u8* a = (u8*)p + 0x8c;
        *(u32*)a = ms;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *(u32*)a = ms;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *a = ms;
      }
      {
        register u8 g asm("r0");
        register u8 h asm("r1");
        h = p->flags;
        asm("" : "+r"(h));
        g = 0xFB;
        g &= h;
        p->flags = g;
      }
      break;
    }
    case 2: {
      s32 t = p->work[3] - 4;
      p->work[3] = t;
      if ((t << 24) != 0) {
        break;
      }
      {
        u32 tbl = (u32)gProjectileFnTable;
        EntityFunc** rt = (EntityFunc**)(tbl + ((p->id) << 2));
        *(u32*)(p->mode) = m;
        p->onUpdate = (void*)((*rt)[2]);
      }
      Projectile28_Die((Projectile28*)p);
      break;
    }
  }
  p->mode[3]++;
}

void FUN_080a9fe4(struct Sprite* s, struct DrawPivot* dp) {
  register struct Coord* lt asm("r3");
  register struct Entity* q asm("r2");
  register s32 x asm("r5");
  register s32 y asm("r4");
  register u32 lo asm("r6");
  lt = &dp->lefttop;
  q = (struct Entity*)s->sprites;
  if (q->mode[0] <= 1) {
    register u16* pal asm("r1");
    register s32 c asm("r3");
    u8 w;
    u32 d;
    s32 sd;
    {
      register s32 a asm("r0");
      register s32 b asm("r1");
      a = (q->coord).x;
      b = (dp->lefttop).x;
      a = a - b;
      x = a >> 8;
    }
    {
      register s32 a asm("r0");
      register s32 b asm("r1");
      a = (q->coord).y;
      b = lt->y;
      a = a - b;
      y = (a >> 8) + 2;
    }
    if ((q->mode[3] & 3) > 1) {
      pal = (u16*)&gPaletteManager;
      c = 0x7FFF;
    } else {
      pal = (u16*)&gPaletteManager;
      c = 0x7C00;
    }
    {
      register s32 cv asm("r0");
      asm volatile("add %0, %1, #0" : "=&l"(cv) : "l"(c));
      *pal = cv;
    }
    w = q->work[3];
    d = (u32)(x - w) << 16;
    x = (u32)((w + x) << 16) >> 16;
    lo = d >> 16;
    sd = (s32)d >> 16;
    if (sd < 0) {
      lo = 0;
    } else if (sd > 0xF0) {
      lo = 0xF0;
    }
    {
      s32 sh = (s32)(x << 16) >> 16;
      if (sh < 0) {
        x = 0;
      } else if (sh > 0xF0) {
        x = 0xF0;
      }
    }
    if (y < 0) {
      y = 0;
    } else if (y > 0xA0) {
      y = 0xA0;
    }
    {
      register struct WramWindowRegister* wb asm("r2");
      register s32 m3 asm("r3");
      register s32 hv asm("r1");
      register s32 mask asm("r0");
      register s32 lv asm("r0");
      wb = &gWindowRegBuffer;
      m3 = 0xFF;
      hv = (s32)(x << 16) >> 16;
      mask = 0xFF;
      hv &= mask;
      lv = (s32)(lo << 16) >> 8;
      hv |= lv;
      wb->winH.half[1] = hv;
      y &= m3;
      wb->winV.half[1] = y;
    }
  }
}

void FUN_080aa08c(Projectile28* p) {
  struct Entity* q = p->unk_28;
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  SetTaskCallback((struct RenderNode*)&p->spr, FUN_080aa15c);
  p->spr.sprites = (struct MetaspriteHeader*)p;
  {
    u8 f = p->flags & ~8;
    f |= DISPLAY;
    f |= FLIPABLE;
    p->flags = f;
  }
  {
    s32 x = (q->coord).x;
    s32 y = (q->coord).y;
    p->coord.x = x;
    p->coord.y = y;
  }
  {
    register u16 d asm("r2") = gWindowRegBuffer.dispcnt;
    register u16 r asm("r0");
    register u16 k asm("r3");
    register s32 v asm("r3");
    k = 0x4000;
    r = k;
    v = 0;
    r |= d;
    gWindowRegBuffer.dispcnt = r;
    gWindowRegBuffer.winin[1] = 0x31;
    gWindowRegBuffer.winin[2] |= 0xE;
    (*(u16*)(&gPaletteManager.buf[0])) = 0x7FFF;
    *(s32*)((u8*)p + 0xb4) = *(vs32*)&p->coord.x;
    *(s32*)((u8*)p + 0xb8) = *(vs32*)&p->coord.y;
    p->work[3] = v;
    p->work[2] = v;
  }
  Projectile28_Update((Projectile28*)p);
}

void FUN_080aa120(Projectile28* p) {
  struct Entity* par = p->unk_28;
  p->coord = par->coord;
  p->work[3]++;
  if (par->mode[1] != 0xf) {
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
    Projectile28_Die((Projectile28*)p);
  }
}

void FUN_080aa15c(struct Sprite* spr, struct DrawPivot* dp) {
  register struct Coord* lt asm("r3");
  struct Entity* e;
  register s32 cx asm("r4");
  register s32 ay asm("r6");
  register u16 x1 asm("r5");
  register u16 x2 asm("r2");
  register u16 y1 asm("r6");
  register u16 y2 asm("r4");
  register s32 t asm("r0");
  lt = &dp->lefttop;
  e = (struct Entity*)spr->sprites;
  if (e->mode[0] > 1) {
    return;
  }
  t = e->coord.x;
  t -= dp->lefttop.x;
  asm("" : "+r"(t));
  cx = t >> 8;
  t = *(s32*)((u8*)e + 0xb8);
  t -= lt->y;
  asm("" : "+r"(t));
  t >>= 8;
  asm("" : "+r"(t));
  ay = t;
  ay -= 0x20;
  if (((e->work[3]) & 3) > 1) {
    (*(u16*)(&gPaletteManager.buf[0])) = 0x7FFF;
  } else {
    (*(u16*)(&gPaletteManager.buf[0])) = 0x3FF;
  }
  t = *(s32*)((u8*)e + 0xb4);
  t -= lt->x;
  t <<= 8;
  x1 = ((u32)t) >> 16;
  t = cx << 16;
  asm("" : "+r"(t));
  x2 = ((u32)t) >> 16;
  {
    s32 a = x1 << 16;
    s32 b = x2 << 16;
    if (a > b) {
      x1 = ((u32)b) >> 16;
      x2 = ((u32)a) >> 16;
    }
  }
  {
    s32 v = (s16)x1;
    if (v < 0) {
      x1 = 0;
    } else if (v > 0xf0) {
      x1 = 0xf0;
    }
  }
  {
    s32 v = (s16)x2;
    if (v < 0) {
      x2 = 0;
    } else if (v > 0xf0) {
      x2 = 0xf0;
    }
  }
  {
    register s32 c1 asm("r1");
    register s32 c2 asm("r0");
    c1 = ay - 8;
    asm("" : "+r"(c1));
    c1 <<= 16;
    c2 = ay + 8;
    asm("" : "+r"(c2));
    c2 <<= 16;
    y2 = ((u32)c2) >> 16;
    y1 = ((u32)c1) >> 16;
    c1 >>= 16;
    if (c1 < 0) {
      y1 = 0;
    } else if (c1 > 0xa0) {
      y1 = 0xa0;
    }
  }
  {
    s32 v = (s16)y2;
    if (v < 0) {
      y2 = 0;
    } else if (v > 0xa0) {
      y2 = 0xa0;
    }
  }
  {
    register struct WramWindowRegister* w asm("r3");
    register s32 msk asm("r2");
    w = &gWindowRegBuffer;
    {
      register s32 h asm("r1");
      register s32 sh asm("r0");
      h = (s16)x2;
      msk = 0xff;
      h &= msk;
      sh = (s16)x1 << 8;
      h |= sh;
      w->winH.half[1] = h;
    }
    {
      register s32 h2 asm("r0");
      register s32 sh2 asm("r1");
      h2 = (s16)y2;
      h2 &= msk;
      sh2 = (s16)y1 << 8;
      h2 |= sh2;
      w->winV.half[1] = h2;
    }
  }
}

// --------------------------------------------

// 0x0836c22c
static const struct Collision sCollisions[4] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 4,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      nature : 0x04,
      hitzone : 1,
      hardness : METAL,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(127), PIXEL(64), -PIXEL(1)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 4,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(127), PIXEL(64), -PIXEL(1)},
    },
};
