#include "collision.h"
#include "entity.h"
#include "global.h"
#include "physics.h"
#include "minigame.h"
#include "zero.h"

static const struct Collision sCollisions[3];
static const u8 sInitModes[4];

static void Leviathan_Init(Player* p);
static void Leviathan_Update(Player* p);
static void Leviathan_Die(struct Entity* p);

// clang-format off
const ZeroRoutine gLeviathanRoutine = {
  [ENTITY_INIT] =       (void*)Leviathan_Init,
  [ENTITY_UPDATE] =     (void*)Leviathan_Update,
  [ENTITY_DIE]  =       (void*)Leviathan_Die,
  [ENTITY_DISAPPEAR] =  (void*)RemovePlayer,
  [ENTITY_EXIT] =       (void*)DeleteEntity,
};
// clang-format on

bool8 FUN_08035e48(struct Entity* p) {
  if ((p->d).x >= 1) {
    (p->d).x -= 4;
    if ((p->d).x < 0) return TRUE;
  } else {
    (p->d).x += 4;
    if ((p->d).x > 0) return TRUE;
  }
  return FALSE;
}

void FUN_08035e6c(struct Zero* p) {
  s32 dx, x, y;
  x = (p->s).unk_coord.x;
  y = (p->s).unk_coord.y;
  if (x > y) {
    dx = (y - x) * 12;
    if (dx < 0) {
      dx += 0xFF;
    }
    (p->s).unk_coord.x += (dx >> 8);
    if ((p->s).unk_coord.x < y) {
      (p->s).unk_coord.x = y;
    }
  }
}

struct Entity* CreatePlayerLeviathan(void* q, s32 x, s32 y) {
  struct Entity* p = AllocPlayer();
  if (p != NULL) {
    p->renderPrio = 16;
    INIT_PLAYER_ROUTINE(p, PLAYER_MINIGAME_LEVIATHAN);
    p->work[0] = 0;
    p->coord.x = x, p->coord.y = y;
    p->unk_28 = q;
  }
  return p;
}

static void onCollision(struct Body* body UNUSED, Coords32* r1 UNUSED, Coords32* r2 UNUSED) { return; }

static void Leviathan_Init(Player* p) {
  SET_PLAYER_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = sInitModes[(p->s).work[0]];

  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  SetSpriteTableDynamic(p);
  (p->s).spr.xflip = TRUE;
  (p->s).spr.oam.xflip = TRUE;
  (p->s).flags |= X_FLIP;
  INIT_BODY(p, &sCollisions[0], 6, onCollision);
  (p->mg).leviathan.x = (p->s).coord.x;
  (p->s).unk_coord.y = (p->s).coord.y;
  (p->s).work[3] = 0;
  (p->s).d.x = 0, (p->s).d.y = 0;
  Leviathan_Update(p);
}

static void leviathanMode0Pre(struct Entity* p);
static void leviathanMode1Pre(struct Entity* p);
static void nop_08036044(void* _ UNUSED);

void leviathanMode0(struct Zero* z);
void leviathanMode1(struct Zero* z);
void leviathanMode2(struct Zero* z);

static void Leviathan_Update(Player* p) {
  static const ZeroFunc sUpdates1[3] = {
      (void*)leviathanMode0Pre,
      (void*)leviathanMode1Pre,
      (void*)nop_08036044,
  };  // 0x0835ec00
  static const ZeroFunc sUpdates2[3] = {
      (void*)leviathanMode0,
      (void*)leviathanMode1,
      (void*)leviathanMode2,
  };  // 0x0835ec0c

  struct MinigameState* s = (struct MinigameState*)(p->s).unk_28;
  if (s->unk_31 == 0) {
    (sUpdates1[(p->s).mode[1]])(p);
    (sUpdates2[(p->s).mode[1]])(p);
  }

  {
    s32 min_x, max_x;
    min_x = (p->mg).leviathan.x - PIXEL(108);
    if ((p->s).coord.x <= min_x) {
      (p->s).coord.x = min_x, (p->s).d.x = 0;
    }
    max_x = (p->mg).leviathan.x + PIXEL(108);
    if ((p->s).coord.x >= max_x) {
      (p->s).coord.x = max_x, (p->s).d.x = 0;
    }
  }
}

static void Leviathan_Die(struct Entity* p) { SET_PLAYER_ROUTINE(p, ENTITY_EXIT); }

// --------------------------------------------

// 0x08035FF8
static void leviathanMode0Pre(struct Entity* p) {
  struct MinigameState* s = (struct MinigameState*)p->unk_28;
  if (s->unk_10 & 0x30) {
    p->mode[1] = 1, p->mode[2] = 0;
  }
  if (s->unk_12 & (1 << 1)) {
    p->mode[1] = 2, p->mode[2] = 0;
  }
}

// 0x08036028
static void leviathanMode1Pre(struct Entity* p) {
  struct MinigameState* s = (struct MinigameState*)p->unk_28;
  if (s->unk_12 & (1 << 1)) {
    p->mode[1] = 2, p->mode[2] = 0;
  }
}

static void nop_08036044(void* _ UNUSED) {}

void leviathanMode0(struct Zero* p) {
  u8 m = (p->s).mode[2];
  switch (m) {
    case 0:
      SetDDP(&p->body, &sCollisions[0]);
      (p->s).unk_coord.x = (p->s).coord.y;
      (p->s).work[2] = m;
      SetMotion(&p->s, MOTION(0xBD, 0x04));
      (p->s).mode[2]++;
    case 1: {
      s32 base;
      FUN_08035e6c(p);
      base = (p->s).unk_coord.x;
      (p->s).coord.y = base;
      (p->s).coord.y = base + ((gSineTable[(p->s).work[2]] * 5) << 7) / 256;
      (p->s).work[2] += 2;
      if (FUN_08035e48(&p->s)) {
        (p->s).d.x = 0;
      }
      (p->s).coord.x += (p->s).d.x;
      UpdateEntityAnim(&p->s);
      break;
    }
  }
}

void leviathanMode1(struct Zero* p) {
  struct Entity* e = (p->s).unk_28;
  switch ((p->s).mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[0]);
      SetMotion(&p->s, 0xBD02);
      (p->s).mode[2]++;
      /* fallthrough */
    case 1: {
      register s32 mv asm("r5");
      FUN_08035e6c(p);
      (p->s).coord.y = (p->s).unk_coord.x;
      mv = 0;
      {
      register u16 in asm("r1");
      in = *(u16*)((u8*)e + 0x10);
      if (in & 0x20) {
        (p->s).d.x -= 0x10;
        if ((p->s).d.x < -0x300) {
          (p->s).d.x = -0x300;
        }
        {
          u8* a;
          u8 b;
          u8* xa;
          register s32 z asm("r0");
          mv = 1;
          xa = (u8*)p + 0x4c;
          z = 0;
          asm("" : "+r"(z));
          *xa = z;
          a = (u8*)p + 0x4a;
          b = *a;
          z -= 0x11;
          z &= b;
          *a = z;
          (p->s).flags &= 0xEF;
        }
      } else if (in & 0x10) {
        (p->s).d.x += 0x10;
        if ((p->s).d.x > 0x300) {
          (p->s).d.x = 0x300;
        }
        mv = 1;
        ((p->s).spr).xflip = mv;
        {
          register s32 v0 asm("r0");
          register u32 ten asm("r1");
          u8* a = (u8*)p + 0x4a;
          v0 = *a;
          ten = 0x10;
          v0 |= ten;
          *a = v0;
          {
            register u8 fl asm("r0");
            fl = (p->s).flags;
            ten |= fl;
            (p->s).flags = ten;
          }
        }
      }
      }
      if (((FUN_08035e48(&p->s) << 24) != 0) && mv == 0) {
        (p->s).d.x = mv;
        (p->s).mode[2]++;
      }
      (p->s).coord.x += (p->s).d.x;
      UpdateEntityAnim(&p->s);
      break;
    }
    case 2:
      SetMotion(&p->s, 0xBD01);
      (p->s).mode[2]++;
      /* fallthrough */
    case 3: {
      u32 m;
      FUN_08035e6c(p);
      (p->s).coord.y = (p->s).unk_coord.x;
      UpdateEntityAnim(&p->s);
      {
        u16 iv = *(u16*)((u8*)e + 0x10);
        m = 0x30;
        m &= iv;
      }
      if (m != 0) {
        (p->s).mode[2] = 0;
      } else if ((p->s).motion.state == 3) {
        (p->s).mode[1] = m;
        (p->s).mode[2] = m;
      }
      break;
    }
  }
}

void leviathanMode2(struct Zero* p) {
  register struct Entity* e asm("r6");
  s32 mv;
  register s32 md asm("r0");
  e = (p->s).unk_28;
  md = (p->s).mode[2];
  switch (md) {
    case 0:
      *((u8*)e + 0x35) = md;
      SetMotion(&p->s, 0xBD17);
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateEntityAnim(&p->s);
      if ((s8)*((u8*)p + 0x71) != 2) {
        break;
      }
      (p->s).mode[2]++;
      break;
    case 2:
      PlaySound(0xF7);
      SetDDP(&p->body, (const struct Collision*)0x0835EC30);
      (p->s).d.y = 0x80 << 2;
      SetMotion(&p->s, 0xBD19);
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 3: {
      register s32 r asm("r2");
      if ((*(s32*)((u8*)p + 0x8c) & 4) != 0) {
        (p->s).d.x = (p->s).d.x / 2;
      }
      {
        register s32 dy asm("r0");
        register s32 lim asm("r1");
        dy = (p->s).d.y + 0x10;
        (p->s).d.y = dy;
        lim = 0xc0 << 2;
        if (dy > lim) {
          (p->s).d.y = lim;
        }
      }
      {
        register s32 ny asm("r1");
        register s32 k asm("r2");
        {
          register s32 dv asm("r0");
          ny = (p->s).coord.y;
          dv = (p->s).d.y;
          ny += dv;
        }
        (p->s).coord.y = ny;
        {
          register s32 xx asm("r0");
          xx = (p->s).coord.x;
          k = 0x8c << 6;
          ny += k;
          r = PushoutToUp2(xx, ny);
        }
      }
      {
        register s32 in asm("r1");
        {
          register s32 t2 asm("r0");
          in = *(u16*)((u8*)e + 0x10);
          t2 = 2;
          t2 &= in;
          t2 <<= 16;
          in = (u32)t2 >> 16;
        }
        if (in == 0) {
          (p->s).unk_coord.x = (p->s).coord.y;
          (p->s).mode[1] = in;
          (p->s).mode[2] = in;
          return;
        }
      }
      if (r < 0) {
        register s32 v asm("r0");
        register s32 w asm("r1");
        w = (p->s).d.x;
        v = w << 1;
        v += w;
        v <<= 5;
        v = v / 256;
        (p->s).d.x = v;
        {
          s32 ny2 = (p->s).coord.y + r;
          (p->s).coord.y = ny2;
          (p->s).unk_coord.x = ny2;
        }
        (p->s).mode[1] = 0;
        (p->s).mode[2] = 0;
      }
      UpdateEntityAnim(&p->s);
      break;
    }
  }
  mv = 0;
  {
    register s32 in asm("r1");
    in = *(u16*)((u8*)e + 0x10);
    if ((in & 0x20) != 0) {
      register s32 lim asm("r1");
      s32 v = (p->s).d.x - 0x10;
      (p->s).d.x = v;
      lim = 0xFFFFFD00;
      if (v < lim) {
        (p->s).d.x = lim;
      }
      mv = 1;
    } else if ((in & 0x10) != 0) {
      register s32 lim2 asm("r1");
      s32 v = (p->s).d.x + 0x10;
      (p->s).d.x = v;
      lim2 = 0xc0 << 2;
      if (v > lim2) {
        (p->s).d.x = lim2;
      }
      mv = 1;
    }
  }
  if (((FUN_08035e48(&p->s) << 24) != 0) && mv == 0) {
    (p->s).d.x = mv;
  }
  (p->s).coord.x += (p->s).d.x;
}

// --------------------------------------------

static const struct Collision sCollisions[3] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 1,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0A00, 0x1600, 0x0C00, 0x0900},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 1,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {-0x0A00, 0x1F00, 0x0800, 0x1B00},
    },
};

static const u8 sInitModes[4] = {0, 0, 0, 0};
