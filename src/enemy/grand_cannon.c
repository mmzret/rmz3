#include "collision.h"
#include "element.h"
#include "enemy.h"
#include "global.h"
#include "mod.h"
#include "story.h"
#include "vfx.h"
#include "score.h"
#include "stagerun.h"
#include "zero.h"

struct Entity* CreateGrandCannonBomb(struct Coord* c, s32 v, u8 ang);
void FUN_080b7f70(struct Entity* p, struct Coord* c, const motion_t* m, s32 n);

typedef struct {
  COLLISION_OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  struct GrandCannonProps {
    Entity* elfx;  // 0xB4, ElementEffect
    u8 unk_004;
    u8 unk_005;
    u16 unk_006;
    bool8 is_right;
    u8 unk_009;
    u8 unk_00a;
    u8 unk_00b;
    u8 unk_00c[4];
  } props;
} GrandCannon;
static_assert(sizeof(GrandCannon) == sizeof(struct Enemy));

static const struct Collision sCollisions[3];
static const struct Rect sSize;
static const motion_t sMotions[4];
static const Coords32 sElementCoord;
static const u8 sInitModes[2];

static void GrandCannon_Init(GrandCannon* p);
NON_MATCH static void GrandCannon_Update(GrandCannon* p);
static void GrandCannon_Die(GrandCannon* p);
static void GrandCannon_Dissappear(GrandCannon* p);

// clang-format off
const EnemyRoutine gGrandCannonRoutine = {
    [ENTITY_INIT] =      (void*)GrandCannon_Init,
    [ENTITY_UPDATE] =    (void*)GrandCannon_Update,
    [ENTITY_DIE] =       (void*)GrandCannon_Die,
    [ENTITY_DISAPPEAR] = (void*)GrandCannon_Dissappear,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// グランドキャノンの砲台の方を生成

void FUN_080b2b40(u8 kind, struct Coord* c, s32 v, u8 n);
void FUN_080b834c(struct Entity* e, struct Coord* c, struct Coord* dc, s32 y, motion_t* motions, u8 frame);
static void CreateGrandCannonBattery(GrandCannon* turret) {
  GrandCannon* p = AllocEntityFirst(gEnemyHeaderPtr);
  if (p != NULL) {
    p->unk_28 = (void*)turret;
    INIT_ENEMY_ROUTINE(p, ENEMY_GRAND_CANNON);
    p->work[0] = GRAND_CANNON_BATTERY;
    p->flags2 |= WHITE_PAINTABLE;
    p->invincibleID = turret->uniqueID;
  }
}

static void GrandCannon_OnCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  if (body->hitboxFlags & BODY_STATUS_WHITE) {
    Entity* q = (body->enemy)->parent;
    GrandCannon* p = (GrandCannon*)body->parent;
    if (q->kind == ENTITY_PROJECTILE && q->id == 3) {
      SET_ENEMY_ROUTINE(p, ENTITY_DIE);
      p->mode[1] = 0;
    }
  }
}

static bool8 tryKillGrandCannon(GrandCannon* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    if ((p->body).status & BODY_STATUS_SLASHED) {
      p->mode[1] = 1;
    } else {
      p->mode[1] = 0;
    }
    GrandCannon_Die(p);
    return TRUE;
  }
  return FALSE;
}

static void nop_0806937c(GrandCannon* p);
static void grandcannon_08069380(GrandCannon* p);

static void (*const sUpdates1[4])(GrandCannon*) = {
    nop_0806937c,
    nop_0806937c,
    nop_0806937c,
    grandcannon_08069380,
};

static void grandCannon_080693b4(GrandCannon* p);
void grandcannonMoveTurret(GrandCannon* p);
void grandcannonBombShot(GrandCannon* p);
void grandcannon_08069608(GrandCannon* p);

static void (*const sUpdates2[4])(GrandCannon*) = {
    grandCannon_080693b4,
    grandcannonMoveTurret,
    grandcannonBombShot,
    grandcannon_08069608,
};

static bool8 FUN_08069098(GrandCannon* p) {
  if ((p->props).elfx == NULL) {
    switch (p->mode[3]) {
      case 0: {
        if (IsFrozen(p)) {
          (sUpdates1[p->mode[1]])(p);
          (sUpdates2[p->mode[1]])(p);
          p->mode[3]++;
          UpdateSpriteAnimation(p);
          return TRUE;
        }
        break;
      }
      case 1: {
        if (IsFrozen(p)) return TRUE;
        p->mode[3] = 0;
        break;
      }
    }
  }
  return FALSE;
}

static void FUN_0806910c(GrandCannon* p) {
  if ((p->props).elfx == NULL) {
    if ((p->body).status & BODY_STATUS_WHITE) {
      (p->props).elfx = ApplyElementEffect(0, (Object*)p, &sElementCoord);
      if ((p->props).elfx != NULL) {
        p->mode[1] = 3, p->mode[2] = 0;
      }
    }
  }
}

// --------------------------------------------

static void GrandCannon_Init(GrandCannon* p) {
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);

  if (p->work[0] == GRAND_CANNON_TURRET) {
    p->coord.y = FUN_08009f6c(p->coord.x, p->coord.y);
    if (FLAG(gSystemSavedata.flags, MOD_105) && !FLAG(gCurStory.s.gameflags, DEMO_PLAY)) {
      _INIT_BODY(p, sCollisions, 12);
    } else {
      _INIT_BODY(p, sCollisions, 8);
    }
    SET_BODY_INTERSECT_HANDLER(p, GrandCannon_OnCollision);
    CreateGrandCannonBattery(p);
    (p->props).elfx = NULL;
  } else {
    (p->props).unk_004 = 0;
  }

  GrandCannon_Update(p);
}

NON_MATCH static void GrandCannon_Update(GrandCannon* p) {
#if MODERN
  if (p->work[0] == GRAND_CANNON_BATTERY) {
    struct Entity* turret = p->unk_28;
    if (!IS_METTAUR) {
      if (turret->mode[0] != ENTITY_EXIT) {
        if (turret->mode[0] > ENTITY_UPDATE) {
          SET_ENEMY_ROUTINE(p, ENTITY_DIE);
          p->mode[1] = 2;
          GrandCannon_Die(p);
          return;
        }
        goto _UPDATE;
      }
    }

    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
  } else {
    if (tryKillGrandCannon(p)) {
      return;
    }
    FUN_0806910c(p);
    if (FUN_08069098(p)) {
      return;
    }
  _UPDATE:
    (sUpdates1[p->mode[1]])(p);
    (sUpdates2[p->mode[1]])(p);
  }
#else
  INCCODE("asm/wip/GrandCannon_Update.inc");
#endif
}

void explodeGrandCannon(GrandCannon* p);
void slashGrandCannon(GrandCannon* p);
void FUN_080697bc(GrandCannon* p);

static void GrandCannon_Die(GrandCannon* p) {
  static void (*const sDeads[3])(GrandCannon*) = {
      explodeGrandCannon,
      slashGrandCannon,
      FUN_080697bc,
  };
  if (FLAG(gCurStory.s.gameflags, METTAUR_ENABLED)) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (sDeads[p->mode[1]])(p);
}

static void GrandCannon_Dissappear(GrandCannon* p) {
  p->flags2 &= ~ENTI_PHYSICS;
  DeleteEnemy((Entity*)p);
}

// --------------------------------------------

static void nop_0806937c(GrandCannon* p) { return; }

static void grandcannon_08069380(GrandCannon* p) {
  struct Entity* elfx = (p->props).elfx;
  if (elfx == NULL || IsDead(elfx)) {
    (p->props).elfx = NULL;
    SetDDP(&p->body, sCollisions);
    p->mode[1] = 0, p->mode[2] = 0;
  }
}

static void grandCannon_080693b4(GrandCannon* p) {
  switch (p->mode[2]) {
    case 0: {
      SetDDP(&p->body, &sCollisions[1]);
      p->flags2 |= ENTI_PHYSICS;
      p->size = &sSize;
      p->physicsAttr = MTATTR_SLIP | SHAPE_BLOCK;
      SetSpriteAnimation(p, MOTION(SM007_GRAND_CANNON, 0));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

void grandcannonMoveTurret(GrandCannon* p) {
  register struct Entity* q asm("r4");
  q = p->unk_28;
  switch (p->mode[2]) {
    case 0: {
      s32 qx;
      InitRotatableMotion((struct Entity*)p);
      SetMotion((struct Entity*)p, 0x0703);
      p->work[2] = 0x78;
      qx = (q->coord).x;
      p->coord.x = qx;
      p->coord.y = (q->coord).y - 0x600;
      p->unk_coord.x = (pZero2->s).coord.x - qx;
      p->angle = 0x40;
      p->mode[2]++;
    }
      // fallthrough
    case 1: {
      UpdateEntityAnim((struct Entity*)p);
      if (*(s32*)((u8*)q + 0xb4) != 0) {
        break;
      }
      if (IsFrozen(q)) {
        break;
      }
      {
        register s32 qx asm("r1");
        register s32 d2 asm("r2");
        register s32 acc asm("r1");
        register u8* cb asm("r4");
        register s32 ang asm("r2");
        register s32 zx asm("r0");
        s32 v;
        qx = (q->coord).x;
        p->coord.x = qx;
        p->coord.y = (q->coord).y - 0x600;
        zx = (pZero2->s).coord.x;
        d2 = zx - qx;
        acc = p->unk_coord.x;
        d2 = d2 - acc;
        {
          s32 t = d2;
          asm("" : "+r"(t));
          if (d2 < 0) {
            t += 15;
          }
          d2 = t >> 4;
        }
        d2 = acc + d2;
        p->unk_coord.x = d2;
        {
          const s16* st = gSineTable;
          u8 i;
          cb = (u8*)p + 0xb8;
          i = *cb;
          v = d2 + (st[i] << 3);
          *cb = i + 4;
        }
        if (v > 0) {
          register s32 c40 asm("r1");
          if (v <= 0xFFF) {
            v = 0x1000;
          } else if (v > 0x7800) {
            v = 0x7800;
          }
          v -= 0x1000;
          {
            s32 dq = (v * 40) / 0x6800;
            c40 = 0x40;
            ang = c40 - dq;
          }
        } else {
          if (v > -0x1000) {
            v = -0x1000;
          } else if (v < -0x7800) {
            v = -0x7800;
          }
          v += 0x1000;
          ang = (v * 40) / -0x6800 + 0x40;
        }
        {
          register s32 na asm("r0");
          u8* aa;
          na = -ang;
          na -= 0x80;
          aa = (u8*)p + 0x24;
          *aa = na;
          {
            s32 t2 = (u8)--p->work[2];
            if (t2 == 0) {
              if (Camera_GetDistance(&gStageRun.vm.camera, (struct Coord*)(aa + 0x30)) <= 0xFFF) {
                p->mode[1] = 2;
                p->mode[2] = t2;
              }
            }
          }
        }
      }
      break;
    }
  }
}

void grandcannonBombShot(GrandCannon* p) {
  struct Coord c;
  switch (p->mode[2]) {
    case 0: {
      u8 ang;
      s32 x;
      s32 y;
      PlaySound(0x2D);
      ang = *(u8*)((u8*)p + 0x24) + 0x80;
      x = p->coord.x;
      c.x = x;
      c.x = gSineTable[(u8)(ang + 0x40)] * 28 + x;
      y = p->coord.y;
      c.y = y;
      c.y = gSineTable[ang] * 28 + y;
      PlaySound(0x2D);
      CreateGrandCannonBomb(&c, 0x500, ang);
      p->work[2] = 4;
      SetMotion((struct Entity*)p, MOTION(0x07, 0x04));
      p->mode[2]++;
    }
    case 1: {
      s32 d;
      u8 t;
      UpdateEntityAnim((struct Entity*)p);
      d = p->work[2] - 1;
      p->work[2] = d;
      t = d;
      if (t == 0) {
        p->mode[1] = 1;
        p->mode[2] = t;
      }
      break;
    }
  }
}

void grandcannon_08069608(GrandCannon* p) {
  if (p->mode[2] == 0) {
    SetDDP(&p->body, &sCollisions[2]);
    p->mode[2]++;
  }
}

void explodeGrandCannon(GrandCannon* p) {
  struct Coord c;
  struct Coord* co;
  {
    register u8 f asm("r0");
    register u8 t asm("r1");
    register u8 k2 asm("r1");
    u8* q = (u8*)p + 0x8c;
    s32 z;
    asm("" : "+r"(q));
    z = 0;
    *(s32*)q = z;
    asm("" : "+r"(q));
    q += 4;
    asm("" : "+r"(q));
    *(s32*)q = z;
    asm("" : "+r"(q));
    q += 4;
    asm("" : "+r"(q));
    *q = z;
    t = p->flags;
    f = 0xFB;
    f &= t;
    asm volatile("" ::"r"(t));
    k2 = 0xFE;
    f &= k2;
    p->flags = f;
  }
  c.x = p->coord.x;
  c.y = p->coord.y - 0x1000;
  CreateSmoke(1, &c);
  PlaySound(0x2a);
  FUN_080b7f70((struct Entity*)p, &c, sMotions, 3);
  co = &p->coord;
  TryDropItem(3, co);
  if (gScore.enemyCount <= 0x270E) {
    gScore.enemyCount++;
  }
  TryDropZakoDisk((struct Entity*)p, co);
  SET_ENEMY_ROUTINE(p, 4);
  {
    register u8 f2 asm("r0");
    register u8 t2 asm("r1");
    t2 = p->flags2;
    f2 = 0xF7;
    f2 &= t2;
    asm volatile("" ::"r"(t2));
    p->flags2 = f2;
  }
}

void slashGrandCannon(GrandCannon* p) {
  switch (p->mode[2]) {
    case 0: {
      register s32 f asm("r6");
      register s32 z4 asm("r4");
      register s32 xf2 asm("r2");
      struct Coord c;
      {
        register s32 t3 asm("r3");
        t3 = 0;
        if ((pZero2->s).coord.x - p->coord.x > 0) {
          t3 = 1;
        }
        f = t3;
        asm("" : "+r"(f));
        xf2 = f;
        asm("" : "+r"(xf2));
      }
      {
        register u8 nf asm("r0");
        if (f != 0) {
          register u8 kk asm("r1");
          kk = p->flags;
          nf = 0x10;
          nf |= kk;
        } else {
          register u8 fl asm("r1");
          fl = p->flags;
          asm("" : "+r"(fl));
          nf = 0xEF;
          nf &= fl;
        }
        p->flags = nf;
      }
      {
        register s32 x asm("r1");
        register u8* a asm("r0");
        register u8* b asm("r3");
        s32 sh;
        u8 ov;
        s32 m;
        x = xf2;
        a = (u8*)p + 0x4c;
        z4 = 0;
        *a = x;
        b = (u8*)p + 0x4a;
        sh = x << 4;
        ov = *b;
        m = -0x11;
        m &= ov;
        m |= sh;
        *b = m;
      }
      p->coord.x -= f << 8;
      SetMotion((struct Entity*)p, MOTION(0x07, 1));
      {
        u8* a = (u8*)p + 0x8c;
        *(s32*)a = z4;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *(s32*)a = z4;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *a = z4;
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
      c.x = p->coord.x;
      c.y = p->coord.y;
      ((void (*)(s32, struct Coord*, s32, s32))FUN_080b2b40)(0, &c, 0x80 << 2, f);
      {
        register s32 k60 asm("r1");
        k60 = 0x60;
        c.x = k60 - (((f << 1) + f) << 6);
        c.y = 0x40;
      }
      ((void (*)(struct Entity*, struct Coord*, struct Coord*, s32, motion_t*, s32))FUN_080b834c)((struct Entity*)p, &p->coord, &c, 0, (motion_t*)&sMotions[3], 0x18);
      p->work[2] = 0x18;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      if ((u8)--p->work[2] == 0) {
        explodeGrandCannon(p);
      }
      break;
  }
}

void FUN_080697bc(GrandCannon* p) {
  struct Entity* e = (struct Entity*)p->unk_28;
  if (e->mode[0] == 4) {
    register u8* q asm("r0");
    u8 fl;
    u32 z;
    fl = p->flags & 0xFE;
    z = 0;
    fl &= 0xFD;
    p->flags = fl;
    q = (u8*)p + 0x8c;
    *(u32*)q = z;
    asm volatile("add %0, #4" : "+r"(q));
    *(u32*)q = z;
    asm volatile("add %0, #4" : "+r"(q));
    *q = z;
    p->flags &= 0xFB;
    SET_ENEMY_ROUTINE(p, 3);
  }
}

// --------------------------------------------

// 0x08366260
static const struct Collision sCollisions[3] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0400, 0x0000, 0x0800, 0x1000},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x0900, 0x1C00, 0x1600},
    },
    [2] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x04,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, -0x0800, 0x1C00, 0x1800},
    },
};

// 0x083662a8
static const Coords32 sElementCoord = {PIXEL(0), 0xFFFFF000};

// 0x083662b0
static const u8 sInitModes[2] = {0, 1};

// 0x083662b4
static const struct Rect sSize = {PIXEL(0), PIXEL(0), PIXEL(24), PIXEL(38)};

// 0x083662bc
static const motion_t sMotions[4] = {
    MOTION(SM007_GRAND_CANNON, 5),
    MOTION(SM007_GRAND_CANNON, 6),
    MOTION(SM007_GRAND_CANNON, 7),
    MOTION(SM007_GRAND_CANNON, 2),
};
