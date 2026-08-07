#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "vfx.h"
#include "physics.h"
#include "script.h"
#include "score.h"

struct Enemy60 {
  struct Entity s;
  struct Body body;
  // props (16bytes, offset: 0xB4..)
  struct Coord c;  // 0xB4
  u8 unk_bc[8];    // 0xBC
};

// OmegaZX のスプライト部分 (というか手前の X っぽい部分)

struct OmegaZX_X {
  COLLISION_OBJECT_HDR;  // 0x00
  Coords32 c;            // 0xB4
  u8 unk_bc[8];          // 0xBC
};
static_assert(sizeof(struct OmegaZX_X) == sizeof(struct Enemy));

static const struct Collision sCollisions[];

static void onCollision(struct Body* body UNUSED, Coords32* r1 UNUSED, Coords32* r2 UNUSED);

static void Enemy60_Init(struct OmegaZX_X* p);
NON_MATCH void Enemy60_Update(struct OmegaZX_X* p);
void Enemy60_Die(struct OmegaZX_X* p);

// clang-format off
const EnemyRoutine gEnemy60Routine = {
    [ENTITY_INIT] =      (void*)Enemy60_Init,
    [ENTITY_UPDATE] =    (void*)Enemy60_Update,
    [ENTITY_DIE] =       (void*)Enemy60_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------


static const EnemyFunc sDeads[2];
struct Entity* FUN_08092444(Coords32* c, u8 kind, struct Entity* boss) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_OMEGA_ZX_X);
    p->coord = *c;
    p->work[0] = kind, p->work[1] = 0;
    p->unk_28 = (void*)boss;
  }
  return p;
}

static struct Entity* unused_FUN_080924a8(struct Entity* e, u8 kind) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_OMEGA_ZX_X);
    p->work[0] = kind, p->work[1] = 1;
    p->unk_28 = (void*)e;
  }
  return p;
}

// --------------------------------------------

static void Enemy60_Init(struct OmegaZX_X* p) {
  EnableSpriteAnimation_Normal(p);
  SetSpriteTableDynamic(p);
  SET_XFLIP(p, FALSE);
  p->flags &= ~DISPLAY;
  p->flags |= FLIPABLE;
  INIT_BODY(p, sCollisions, 1, onCollision);
  (&p->d)->x = (&p->d)->y = 0;
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 0, p->mode[2] = 0, p->mode[3] = 0;
  (p->c).x = 0, (p->c).y = 0;
  {
    p->coord.y = ((p->unk_28)->coord).y;
    p->coord.x = (p->c).x + ((p->unk_28)->coord).x;
    p->flags2 |= WHITE_PAINTABLE;
    p->invincibleID = (p->unk_28)->uniqueID;
  }
  Enemy60_Update((void*)p);
}

NON_MATCH void Enemy60_Update(struct OmegaZX_X* p) {
#if MODERN
  if ((p->unk_28)->mode[0] == 4) {
    u8 m1 = 0xFE;
    u8 k2;
    u8 f;
    s32 z;
    u32* st;
    u32* pv;
    u8* iv;
    f = p->flags & m1;
    z = 0;
    p->flags = f;
    st = &(p->body).status;
    *st = z;
    pv = &(p->body).prevStatus;
    *pv = z;
    iv = &(p->body).invincibleTime;
    *iv = z;
    k2 = 0xFB;
    f = p->flags & k2;
    f &= m1;
    f &= 0xFD;
    p->flags = f;
    *st = z;
    *pv = z;
    *iv = z;
    p->flags &= k2;
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
  } else {
    (sUpdates[p->work[0]])[p->mode[1]](p);
  }
#else
  INCCODE("asm/enemy/unk_60_25b4.inc");
#endif
}

void Enemy60_Die(struct OmegaZX_X* p) {
  (sDeads[p->mode[1]])((struct Enemy*)p);
}

void FUN_08092664(struct OmegaZX_X* p) {
  switch (p->mode[2]) {
    case 0: {
      register u8 z asm("r3");
      z = p->work[0];
      if (z == 0) {
        register u8* oa asm("r2");
        register s32 one asm("r4");
        {
          u8 fl = p->flags;
          u32 f = 1;
          f |= fl;
          {
            u32 m = 0xEF;
            f &= m;
            p->flags = f;
          }
        }
        one = 1;
        {
          u8* q = (u8*)p + 0x4c;
          *q = z;
        }
        oa = (u8*)p + 0x4a;
        {
          s32 ov = *oa;
          s32 m11 = -0x11;
          m11 &= ov;
          *oa = m11;
        }
        {
          u8 fl = p->flags;
          u32 f = 0xDF;
          f &= fl;
          p->flags = f;
        }
        {
          u8* q = (u8*)p + 0x4d;
          *q = z;
        }
        {
          s32 ov = *oa;
          s32 m21 = -0x21;
          m21 &= ov;
          *oa = m21;
        }
        {
          u8* q = (u8*)p + 0x24;
          *q = z;
        }
        SetMotion((struct Entity*)p, 0xB601);
        p->mode[2] = one;
      } else {
        register u8 z asm("r2");
        register u8* oa asm("r3");
        {
          u8 fl = p->flags;
          u32 f = 1;
          f |= fl;
          z = 0;
          {
            u32 m = 0xEF;
            f &= m;
            p->flags = f;
          }
        }
        {
          u8* q = (u8*)p + 0x4c;
          *q = z;
        }
        oa = (u8*)p + 0x4a;
        {
          s32 ov = *oa;
          s32 m11 = -0x11;
          m11 &= ov;
          *oa = m11;
        }
        {
          u8 fl = p->flags;
          u32 f = 0xDF;
          f &= fl;
          p->flags = f;
        }
        {
          u8* q = (u8*)p + 0x4d;
          *q = z;
        }
        {
          s32 ov = *oa;
          s32 m21 = -0x21;
          m21 &= ov;
          *oa = m21;
        }
        {
          u8* q = (u8*)p + 0x24;
          *q = z;
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      {
        register u8* a asm("r0");
        register s32 zz asm("r1");
        a = (u8*)p + 0x8c;
        zz = 0;
        asm volatile("str %0, [%1]" ::"l"(zz), "l"(a) : "memory");
        a += 4;
        asm("" : "+r"(a));
        asm volatile("str %0, [%1]" ::"l"(zz), "l"(a) : "memory");
        a += 4;
        asm("" : "+r"(a));
        asm volatile("strb %0, [%1]" ::"l"(zz), "l"(a) : "memory");
        {
          register u8 fl asm("r2");
          u32 f;
          fl = p->flags;
          f = 0xFB;
          f &= fl;
          p->flags = f;
        }
        p->d.x = zz;
        p->d.y = zz;
      }
      p->work[2] = 0x14;
      break;
    }
    case 1:
      if (p->work[0] == 0) {
        struct Entity* e = p->unk_28;
        s32 cy = p->coord.y;
        s32 k = 0xe0 << 6;
        s32 base = cy + k;
        s32 d = (e->coord).y - base;
        p->coord.y = cy + (((d * 2 + d) << 3) >> 8);
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    case 10:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        s32 t = p->work[2] - 1;
        p->work[2] = t;
        if ((t << 24) == 0) {
          p->mode[2]++;
        }
      }
      break;
    case 11:
      p->coord.x += -0x2E00;
      p->coord.y += -0x5000;
      SetMotion((struct Entity*)p, 0xB601);
      UpdateEntityAnim((struct Entity*)p);
      goto set14;
    case 15:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
      if (p->work[2] != 0) {
        s32 t = p->work[2] - 1;
        p->work[2] = t;
        if ((t << 24) != 0) {
          break;
        }
      }
      {
        register u32 w asm("r1");
        w = p->work[3];
        asm("" : "+l"(w));
        if (w <= 0xFB) {
          register s32 n asm("r0");
          n = w + 3;
          p->work[3] = n;
        } else {
          register u32 v asm("r0");
          v = 0xFF;
          v |= w;
          p->work[3] = v;
          p->mode[2]++;
        }
      }
      {
        register u8 w asm("r1");
        register u8* q asm("r0");
        w = p->work[3];
        q = (u8*)p + 0x24;
        *q = w;
      }
      break;
    case 16: {
      register u8 z asm("r2");
      register u8* oa asm("r2");
      SetMotion((struct Entity*)p, 0xb6 << 8);
      z = 0;
      {
        u8 fl = p->flags;
        u32 f = 0xEF;
        f &= fl;
        p->flags = f;
      }
      {
        u8* q = (u8*)p + 0x4c;
        *q = z;
      }
      oa = (u8*)p + 0x4a;
      {
        s32 ov = *oa;
        s32 m11 = -0x11;
        m11 &= ov;
        *oa = m11;
      }
      p->work[2] = 0xa;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 17:
      UpdateEntityAnim((struct Entity*)p);
      if (p->work[2] != 0) {
        s32 t = p->work[2] - 1;
        p->work[2] = t;
        if ((t << 24) != 0) {
          break;
        }
      }
    set14:
      p->mode[2] = 0x14;
      break;
    case 20:
      UpdateEntityAnim((struct Entity*)p);
      if (p->work[0] == 1) {
        struct Entity* e = p->unk_28;
        {
          s32 cx = p->coord.x;
          s32 k = 0x98 << 5;
          s32 base = cx + k;
          s32 d = (e->coord).x - base;
          p->coord.x = cx + (((d * 2 + d) << 3) >> 8);
        }
        {
          s32 cy = p->coord.y;
          s32 k = 0xe8 << 6;
          s32 base = cy + k;
          s32 d = (e->coord).y - base;
          p->coord.y = cy + (((d * 2 + d) << 3) >> 8);
        }
      }
      break;
    case 30: {
      u8 z = 0;
      p->mode[1] = 1;
      p->mode[2] = z;
      break;
    }
  }
}

void FUN_08092918(struct OmegaZX_X* p) {
  struct Coord c;
  if (p->mode[2] == 0) {
    c.x = p->coord.x;
    c.y = p->coord.y;
    CreateSmoke(1, &c);
    PlaySound(0x2a);
    if (gScore.enemyCount <= 0x270e) {
      gScore.enemyCount++;
    }
    TryDropZakoDisk((struct Entity*)p, &p->coord);
    p->flags &= ~DISPLAY;
    SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
  }
}

void FUN_08092980(struct OmegaZX_X* p) {
  switch (p->mode[2]) {
    case 0:
      p->mode[2] = 1;
      // fallthrough
    case 1:
      if (p->unk_28->scriptEntity->flags & 1) {
        p->flags |= DISPLAY;
        SetMotion((struct Entity*)p, 0xb600);
        UpdateEntityAnim((struct Entity*)p);
        p->mode[1] = 1;
        p->mode[2] = 0;
      }
      break;
  }
}

void FUN_080929c8(struct OmegaZX_X* p) {
  switch (p->mode[2]) {
    case 0:
      p->mode[2] = 1;
      // fallthrough
    case 1:
      p->mode[1] = 2;
      p->mode[2] = 0;
      break;
  }
}

void FUN_080929e8(struct OmegaZX_X* p) {
  switch (p->mode[2]) {
    case 0:
      SetMotion((struct Entity*)p, 0xb600);
      SET_XFLIP(p, FALSE);
      SetDDP(&p->body, &sCollisions[3]);
      p->d.y = 0;
      p->d.x = 0;
      p->work[2] = 0;
      p->mode[2]++;
      // fallthrough
    case 1:
      p->coord.y = (p->c).y + ((p->unk_28)->coord).y;
      p->coord.x = (p->c).x + ((p->unk_28)->coord).x;
      UpdateEntityAnim((struct Entity*)p);
      break;
  }
}

void FUN_08092a60(struct OmegaZX_X* p) {
  switch (p->mode[2]) {
    case 0:
      p->mode[2] = 1;
      // fallthrough
    case 1:
      if (p->unk_28->scriptEntity->flags & 1) {
        p->flags |= DISPLAY;
        SetMotion((struct Entity*)p, 0xb601);
        UpdateEntityAnim((struct Entity*)p);
        p->mode[1] = 1;
        p->mode[2] = 0;
      }
      break;
  }
}

void FUN_08092aac(struct OmegaZX_X* p) {
  switch (p->mode[2]) {
    case 0:
      p->mode[2] = 1;
      // fallthrough
    case 1:
      p->mode[1] = 2;
      p->mode[2] = 0;
      break;
  }
}

void FUN_08092acc(struct OmegaZX_X* p) {
  switch (p->mode[2]) {
    case 0:
      SetMotion((struct Entity*)p, 0xb601);
      SET_XFLIP(p, FALSE);
      SetDDP(&p->body, &sCollisions[5]);
      p->d.y = 0;
      p->d.x = 0;
      p->work[2] = 0;
      p->mode[2]++;
      // fallthrough
    case 1:
      p->work[2] += 2;
      p->coord.y += (((p->c).y + ((p->unk_28)->coord).y - p->coord.y) << 4) >> 8;
      p->coord.x = (p->c).x + ((p->unk_28)->coord).x;
      UpdateEntityAnim((struct Entity*)p);
      break;
  }
}

void FUN_08092b54(struct OmegaZX_X* p) {
  switch (p->mode[2]) {
    case 0:
      p->mode[2] = 1;
      // fallthrough
    case 1:
      if ((p->unk_28->scriptEntity)->flags & 1) {
        p->flags |= DISPLAY;
        SetMotion((struct Entity*)p, 0xb602);
        UpdateEntityAnim((struct Entity*)p);
        p->mode[1] = 1;
        p->mode[2] = 0;
      }
      break;
  }
}

void FUN_08092ba0(struct OmegaZX_X* p) {
  switch (p->mode[2]) {
    case 0:
      p->mode[2] = 1;
      // fallthrough
    case 1:
      p->mode[1] = 2;
      p->mode[2] = 0;
      break;
  }
}

void FUN_08092bc0(struct OmegaZX_X* p) {
  s32 m = p->mode[2];
  switch (m) {
    case 0: {
      register u8 fv asm("r0");
      register u8 t asm("r1");
      SetMotion((struct Entity*)p, MOTION(0xB6, 0x02));
      t = p->flags;
      fv = 0xEF;
      fv &= t;
      p->flags = fv;
      asm volatile("" ::"r"(t));
      p->spr.xflip = m;
      {
        u8* oa = (u8*)p + 0x4a;
        s32 ov = *oa;
        s32 m11 = -0x11;
        m11 &= ov;
        *oa = m11;
      }
      SetDDP(&p->body, &sCollisions[1]);
      p->d.y = m;
      p->d.x = m;
      p->work[2] = m;
      *(s32*)&p->unk_2c = m;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      p->coord.y = *(s32*)((u8*)p + 0xb8) + (p->unk_28)->coord.y;
      p->coord.x = *(s32*)((u8*)p + 0xb4) + (p->unk_28)->coord.x;
      UpdateEntityAnim((struct Entity*)p);
      switch ((p->unk_28)->mode[1]) {
        case 4: {
          s32 z = 0;
          *(s32*)&p->unk_2c = z;
          p->mode[1] = 3;
          p->mode[2] = z;
          break;
        }
        case 8: {
          s32 z = 0;
          *(s32*)&p->unk_2c = z;
          p->mode[1] = 7;
          p->mode[2] = z;
          break;
        }
      }
      break;
    }
  }
}

INCASM("asm/enemy/omega_zx_x_a.inc");

void FUN_08092980(struct OmegaZX_X* p);
void FUN_080929c8(struct OmegaZX_X* p);
void FUN_080929e8(struct OmegaZX_X* p);
static void FUN_0809357c(struct OmegaZX_X* p);

static const EnemyFunc sUpdates1[4] = {
    (void*)FUN_08092980,
    (void*)FUN_080929c8,
    (void*)FUN_080929e8,
    (void*)FUN_0809357c,
};

void FUN_08092a60(struct OmegaZX_X* p);
void FUN_08092aac(struct OmegaZX_X* p);
void FUN_08092acc(struct OmegaZX_X* p);

static const EnemyFunc sUpdates2[4] = {
    (void*)FUN_08092a60,
    (void*)FUN_08092aac,
    (void*)FUN_08092acc,
    (void*)FUN_0809357c,
};

void FUN_08092b54(struct OmegaZX_X* p);
void FUN_08092ba0(struct OmegaZX_X* p);
void FUN_08092bc0(struct OmegaZX_X* p);
void FUN_08092c5c(struct Enemy* p);
void FUN_08092f18(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates3[8] = {
    (void*)FUN_08092b54,
    (void*)FUN_08092ba0,
    (void*)FUN_08092bc0,
    (void*)FUN_08092c5c,
    (void*)FUN_0809357c,
    (void*)FUN_0809357c,
    (void*)FUN_0809357c,
    (void*)FUN_08092f18,
};
// clang-format on

static const EnemyFunc* const sUpdates[3] = {
    (void*)sUpdates1,
    (void*)sUpdates2,
    (void*)sUpdates3,
};

void FUN_08092664(struct OmegaZX_X* p);
void FUN_08092918(struct OmegaZX_X* p);

static const EnemyFunc sDeads[2] = {
    (void*)FUN_08092664,
    (void*)FUN_08092918,
};

// --------------------------------------------

// 0x08093578
static void onCollision(struct Body* body UNUSED, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {}

static void FUN_0809357c(struct OmegaZX_X* p) {
  switch (p->mode[2]) {
    case 0: {
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      p->coord.y = (p->c).y + ((p->unk_28)->coord).y;
      p->coord.x = (p->c).x + ((p->unk_28)->coord).x;
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

// --------------------------------------------

// 0x08369a8c
static const struct Collision sCollisions[24] = {
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
      range : {PIXEL(39), PIXEL(6), PIXEL(44), PIXEL(48)},
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
      range : {PIXEL(39), PIXEL(6), PIXEL(44), PIXEL(48)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(28), PIXEL(14), PIXEL(35), PIXEL(42)},
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
      range : {PIXEL(28), PIXEL(14), PIXEL(35), PIXEL(42)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(37), -PIXEL(32), PIXEL(48), PIXEL(65)},
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
      range : {PIXEL(37), -PIXEL(32), PIXEL(48), PIXEL(65)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(30)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(28)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(26)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(22)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(12)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(10)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(6)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(4)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(2)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(1)},
    },
};

// clang-format off
static const Coords32 sPixelCoords[11] = {
    {-25, -45},
    {-49, -22},
    {-64, 7},
    {-49, 36},
    {-25, 59},
    {0, -48},
    {38, -18},
    {38, 18},
    {0, 54},
    {-38, 18},
    {-38, -18},
};
// clang-format on
