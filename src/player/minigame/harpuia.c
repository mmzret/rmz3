#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "physics.h"
#include "zero.h"

NON_MATCH void harpuia_08035684(struct Zero* z);

struct Enemy* FUN_0809af20(struct Zero* z, Coords32* c, u8 n);

static const struct Collision sCollisions[7];

static void Harpuia_Init(struct Zero* z);
void Harpuia_Update(struct Zero* z);
void Harpuia_Die(struct Zero* z);

// clang-format off
const ZeroRoutine gHarpuiaRoutine = {
  [ENTITY_INIT] =       (void*)Harpuia_Init,
  [ENTITY_UPDATE] =     (void*)Harpuia_Update,
  [ENTITY_DIE]  =       (void*)Harpuia_Die,
  [ENTITY_DISAPPEAR] =  (void*)RemovePlayer,
  [ENTITY_EXIT] =       (void*)DeleteEntity,
};
// clang-format on


const ZeroFunc sHarpuiaUpdates1[5];
const ZeroFunc sHarpuiaUpdates2[5];
struct Entity* CreatePlayerHarpuia(void* q, Coords32* c, u8 n) {
  struct Entity* p = AllocPlayer();
  if (p != NULL) {
    p->renderPrio = 16;
    INIT_PLAYER_ROUTINE(p, PLAYER_MINIGAME_HARPUIA);
    p->coord = *c;
    p->work[0] = n;
    p->unk_28 = q;
  }
  return p;
}

static void Harpuia_Init(struct Zero* z) {
  Coords32 c, *d, *uc;
  s32 x, y;

  EnableSpriteAnimation_Normal(z);
  SetSpriteTableDynamic(z);
  (z->s).flags |= DISPLAY;
  (z->s).flags |= FLIPABLE;

  (z->s).spr.xflip = TRUE;
  (z->s).spr.oam.xflip = TRUE;
  (z->s).flags |= X_FLIP;
  INIT_BODY(z, &sCollisions[0], 32, NULL);
  (z->s).coord.y = FUN_0800a05c((z->s).coord.x, (z->s).coord.y);
  SET_PLAYER_ROUTINE(z, ENTITY_UPDATE);
  (z->s).mode[1] = 0;
  (z->s).mode[2] = 0;
  (z->s).mode[3] = 0;

  c = (z->s).coord;
  (z->mg).harpuia.enemy = FUN_0809af20(z, &c, 0);
  (z->mg).harpuia.unk_a = 0;
  (z->mg).harpuia.x = (z->s).coord.x;
  (z->mg).harpuia.y = (z->s).coord.y;
  (z->mg).harpuia.unk_8 = 0;
  (z->mg).harpuia.unk_9 = 0;

  d = &(z->s).d;
  d->x = d->y = 0;
  uc = &(z->s).unk_coord;
  uc->x = uc->y = 0;

  (z->mg).harpuia.unk_b = 0;

  Harpuia_Update(z);
}

void Harpuia_Update(struct Zero* z) {
  register struct MinigameState* mg asm("r5");
  u32* st;

  mg = (struct MinigameState*)(z->s).unk_28;
  if (mg->unk_04 != 2) {
    register s32* xp asm("r2");
    register s32 k asm("r6");
    s32 nx;
    s32 lim;
    nx = (z->s).coord.x + mg->unk_34;
    (z->s).coord.x = nx;
    k = 0x27c;
    asm("" : "+l"(k));
    xp = (s32*)((u8*)z + k);
    lim = *xp + *(s32*)&mg->unk_30;
    if (nx != lim) {
      s32 t, d, nx2, lim2, a;
      k = -0x800;
      asm("" : "+l"(k));
      t = nx + k;
      asm("" : : "l"(k));
      d = lim - t;
      nx2 = nx + (((d * 3) << 2) >> 8);
      (z->s).coord.x = nx2;
      a = *xp;
      lim2 = a + *(s32*)&mg->unk_30;
      asm("" : : "l"(a));
      if (nx2 >= lim2) {
        (z->s).coord.x = lim2;
      }
    }
  }

  {
    register s32 c6 asm("r6");
    register s32 o1 asm("r1");
    struct MinigameState* m1;
    s32 e;
    o1 = 0x27c;
    asm("" : "+l"(o1));
    e = (s32)((u8*)z + o1);
    asm("" : : "l"(o1));
    m1 = (struct MinigameState*)(z->s).unk_28;
    e = *(s32*)e;
    e += *(s32*)&m1->unk_30;
    c6 = -0x6400;
    asm("" : "+l"(c6));
    e += c6;
    if ((z->s).coord.x < e) {
      goto dead;
    }
  }

  if (((struct MinigameState*)(z->s).unk_28)->unk_04 != 2) {
    sHarpuiaUpdates1[(z->s).mode[1]](z);
    sHarpuiaUpdates2[(z->s).mode[1]](z);
    harpuia_08035684(z);
  } else if (((struct MinigameState*)(z->s).unk_28)->unk_0c == 0) {
    sHarpuiaUpdates1[(z->s).mode[1]](z);
    sHarpuiaUpdates2[(z->s).mode[1]](z);
  }

  {
    u32* q = (u32*)((u8*)z + 0x8c);
    u32 f = *q & 4;
    asm volatile("add %0, %1, #0" : "=&l"(st) : "l"(q));
    if (f != 0) {
      struct MinigameState* m2 = (struct MinigameState*)(z->s).unk_28;
      if (m2->unk_04 != 2) {
        *(u16*)m2->unk_38 = *(u16*)m2->unk_38 + 1;
        PlaySound(0x137);
      }
    }
  }
  if ((*st & 1) != 0) {
    struct MinigameState* m2 = (struct MinigameState*)(z->s).unk_28;
    if (m2->unk_0c == 0) {
      goto tick;
    }
    m2->unk_0c--;
    PlaySound(0xf8);
    PlaySound(4);
    {
      register s32 o6 asm("r6");
      u8* q6;
      o6 = 0x287;
      asm("" : "+l"(o6));
      q6 = (u8*)z + o6;
      asm("" : : "l"(o6));
      *q6 = 0x5a;
    }
    {
      struct MinigameState* m3 = (struct MinigameState*)(z->s).unk_28;
      u8 n = m3->unk_0c;
      if (n != 0) {
        goto after;
      }
      (z->s).mode[1] = 4;
      (z->s).mode[2] = n;
    }
  }
  if (((struct MinigameState*)(z->s).unk_28)->unk_0c != 0) {
    goto after;
  }
tick : {
  u8* t = &(z->mg).harpuia.unk_b;
  if (*t != 0) {
    *t = *t - 1;
  }
  if (*t != 1) {
    goto after;
  }
  {
    s32 zr = 0;
    *st = zr;
    *(s32*)((u8*)z + 0x90) = zr;
    *((u8*)z + 0x94) = zr;
  }
  (z->s).flags &= 0xfb;
}
after:
  ((z->mg).harpuia.enemy->s).coord.x = (z->s).coord.x;
  ((z->mg).harpuia.enemy->s).coord.y = (z->s).coord.y;
  if (((z->mg).harpuia.enemy->s).unk_2c != NULL) {
    (((z->mg).harpuia.enemy->s).unk_2c)->coord.x = (z->s).coord.x;
    (((z->mg).harpuia.enemy->s).unk_2c)->coord.y = (z->s).coord.y;
  }
  {
    register s32 c2 asm("r2");
    register s32 hi asm("r1");
    s32 y;
    y = (z->s).coord.y;
    c2 = -0x6400;
    asm("" : "+l"(c2));
    y += c2;
    hi = 0x14000;
    asm("" : "+l"(hi));
    if (y <= hi) {
      return;
    }
  }
dead:
  PlaySound(0xf8);
  PlaySound(4);
  ((struct MinigameState*)(z->s).unk_28)->unk_0c = 0;
  SET_PLAYER_ROUTINE(z, 2);
  (z->s).mode[1] = 0;
  (z->s).mode[2] = 0;
  (z->s).mode[3] = 0;
}

void Harpuia_Die(struct Zero* z) {
  (z->s).flags &= ~DISPLAY;
  (z->s).flags &= ~FLIPABLE;
  EXIT_BODY(z);
  SET_PLAYER_ROUTINE(z, ENTITY_DISAPPEAR);
}

bool8 FUN_0803532c(struct Zero* z) { return TRUE; }

void FUN_08035330(struct Zero* z) {
  switch ((z->s).mode[2]) {
    case 0:
      SetMotion(&z->s, MOTION(0xBE, 0x21));
      (z->s).work[2] = 0x3c;
      (z->s).mode[2]++;
      // fallthrough
    case 1:
      UpdateEntityAnim(&z->s);
      if ((z->s).work[2] == 0 || --(z->s).work[2] == 0) {
        (z->s).mode[1] = 1;
        (z->s).mode[2] = 0;
      }
      break;
  }
}

bool8 FUN_0803537c(struct Zero* z) {
  if (((struct MinigameState*)(z->s).unk_28)->unk_04 == 1 && (gJoypad[0].pressed & B_BUTTON)) {
    (z->s).mode[1] = 3;
    (z->s).mode[2] = 0;
  }
  return TRUE;
}

void FUN_080353a8(struct Zero* z) {
  switch ((z->s).mode[2]) {
    case 0:
      SetMotion(&z->s, MOTION(0xBE, 0x21));
      SetDDP(&z->body, &sCollisions[0]);
      (z->s).mode[2]++;
      // fallthrough
    case 1:
      UpdateEntityAnim(&z->s);
      break;
  }
}

bool8 FUN_080353e4(struct Zero* z) {
  if ((z->s).mode[2] > 1 && (gJoypad[0].pressed & B_BUTTON)) {
    (z->s).mode[1] = 3;
    (z->s).mode[2] = 0;
  }
  return TRUE;
}

void FUN_0803540c(struct Zero* z) {
  switch ((z->s).mode[2]) {
    case 0:
      SetMotion(&z->s, MOTION(0xBE, 0x21));
      (z->s).work[2] = 0xa;
      (z->s).mode[2]++;
      // fallthrough
    case 1:
      UpdateEntityAnim(&z->s);
      if (*(u8*)((u8*)z + 0x73) == 3) {
        (z->s).work[2] = 0xa;
        (z->s).mode[2]++;
      } else if ((z->s).work[2] == 0 || --(z->s).work[2] == 0) {
        (z->s).mode[2]++;
      }
      break;
    case 2:
      UpdateEntityAnim(&z->s);
      if (*(u8*)((u8*)z + 0x73) == 3) {
        (z->s).work[2] = 0xa;
        (z->s).mode[2]++;
      }
      break;
    case 3:
      UpdateEntityAnim(&z->s);
      if ((z->s).work[2] == 0 || --(z->s).work[2] == 0) {
        (z->s).mode[1] = 1;
        (z->s).mode[2] = 0;
      }
      break;
  }
}

bool8 FUN_080354a4(struct Zero* z) {
  if ((z->s).mode[2] == 1 && *(s8*)((u8*)z + 0x71) > 3 && (gJoypad[0].pressed & B_BUTTON)) {
    (z->s).mode[3] = (z->s).mode[2];
  }
  return TRUE;
}

void harpuia_080354d4(struct Zero* z) {
  switch ((z->s).mode[2]) {
    case 0:
      SetMotion(&z->s, MOTION(0xBE, 0x22));
      SetDDP(&z->body, &sCollisions[1]);
      PlaySound(0xf9);
      *(u8*)((u8*)z + 0xf) = 0;
      (z->s).mode[2]++;
      // fallthrough
    case 1:
      UpdateEntityAnim(&z->s);
      if ((*(u32*)((u8*)z + 0x70) & 0x00FFFF00) == 0x00010500) {
        SetDDP(&z->body, &sCollisions[0]);
      }
      if (*(u8*)((u8*)z + 0x73) == 3) {
        if (*(u8*)((u8*)z + 0xf) == 1) {
          (z->s).mode[2]++;
        } else {
          (z->s).mode[1] = 1;
          (z->s).mode[2] = 0;
        }
      }
      break;
    case 2:
      SetMotion(&z->s, MOTION(0xBE, 0x23));
      SetDDP(&z->body, &sCollisions[1]);
      PlaySound(0xf9);
      (z->s).mode[2]++;
      // fallthrough
    case 3:
      UpdateEntityAnim(&z->s);
      if ((*(u32*)((u8*)z + 0x70) & 0x00FFFF00) == 0x00010400) {
        SetDDP(&z->body, &sCollisions[0]);
      }
      if (*(u8*)((u8*)z + 0x73) == 3) {
        (z->s).mode[1] = 1;
        (z->s).mode[2] = 0;
      }
      break;
  }
}

bool8 FUN_080355c0(struct Zero* z) { return TRUE; }

void FUN_080355c4(struct Zero* z) {
  switch ((z->s).mode[2]) {
    case 0:
      SetMotion(&z->s, MOTION(0xBE, 0x21));
      *(u32*)((u8*)z + 0x8c) = 0;
      *(u32*)((u8*)z + 0x90) = 0;
      *(u8*)((u8*)z + 0x94) = 0;
      (z->s).flags &= ~COLLIDABLE;
      (z->s).d.y = 0;
      (z->s).mode[2]++;
      // fallthrough
    case 1: {
      s32 push;
      (z->s).d.y += 0x40;
      if ((z->s).d.y > 0x700) {
        (z->s).d.y = 0x700;
      }
      (z->s).coord.y += (z->s).d.y;
      if ((z->s).coord.y <= 0x12C00) {
        push = PushoutToUp2((z->s).coord.x, (z->s).coord.y);
        if (push == 0) {
          push = PushoutToUp2((z->s).coord.x + 0x1A00, (z->s).coord.y);
          if (push == 0) {
            push = PushoutToUp2((z->s).coord.x - 0x1A00, (z->s).coord.y);
          }
        }
        if (push != 0) {
          (z->s).coord.y += push;
        }
      }
      if ((z->s).coord.y - 0x6400 > 0x14000) {
        (z->s).d.y = 0;
        (z->s).flags &= ~DISPLAY;
      }
      UpdateEntityAnim(&z->s);
      break;
    }
  }
}

NON_MATCH void harpuia_08035684(struct Zero* p) {
#if MODERN
  {
    s32 y = (p->s).coord.y;
    register s32 r asm("r5");
    if (y > 0x12C00) {
      r = PushoutToLeft2((p->s).coord.x + 0x1A00, 0x12C00);
    } else {
      r = PushoutToLeft2((p->s).coord.x + 0x1A00, y);
    }
    if (r != 0) {
      (p->s).coord.x += r;
    }
  }
  {
    register u8* f284 asm("r3");
    f284 = (u8*)p + 0x284;
    if (*f284 == 0 && *(s16*)((u8*)(p->s).unk_28 + 4) == 1 && (gJoypad[0].pressed & 1)) {
      u8* pb = (u8*)p;
      asm("" : "+r"(pb));
      *f284 = 1;
      *(pb + 0x285) = 1;
      (p->s).d.y = -0x540;
    }
  }
  {
    u8* f284b = (u8*)p + 0x284;
    if (*f284b == 1) {
      {
        u32 h = gJoypad[0].input & 1;
        if (h == 0 && (p->s).d.y < 0) {
          u8* pb2 = (u8*)p;
          asm("" : "+r"(pb2));
          (p->s).d.y = h;
          *(pb2 + 0x285) = h;
        }
      }
      {
        u8* f285;
        u8* pb3 = (u8*)p;
        asm("" : "+r"(pb3));
        f285 = pb3 + 0x285;
        if (*f285 == 1 && (p->s).d.y > 0) {
          s32 z = 0;
          (p->s).d.y = z;
          *f285 = z;
        }
      }
      (p->s).d.y += 0x2C;
      if ((p->s).d.y > 0x700) {
        (p->s).d.y = 0x700;
      }
      {
        s32 ny = (p->s).coord.y + (p->s).d.y;
        s32* cap;
        (p->s).coord.y = ny;
        cap = (s32*)((u8*)p + 0x288);
        if (*cap != 0x7FFFFFFF && ny <= *cap) {
          s32 r2;
          s32 g;
          s32 x;
          u8* pb4;
          r2 = PushoutToUp2((p->s).coord.x + -0x1A00, (p->s).coord.y + (p->s).d.y);
          g = FUN_0800a05c((p->s).coord.x + -0x1A00, (p->s).coord.y);
          if (r2 != 0 && g <= *cap) {
            x = (p->s).coord.x + -0x1A00;
            goto snap;
          }
          r2 = PushoutToUp2((p->s).coord.x + 0x1A00, (p->s).coord.y + (p->s).d.y);
          g = FUN_0800a05c((p->s).coord.x + 0x1A00, (p->s).coord.y);
          if (r2 != 0 && g <= *(volatile s32*)((u8*)p + 0x288)) {
            x = (p->s).coord.x + 0x1A00;
            goto snap;
          }
          r2 = PushoutToUp2((p->s).coord.x, (p->s).coord.y + (p->s).d.y);
          g = FUN_0800a05c((p->s).coord.x, (p->s).coord.y);
          if (r2 != 0 && g <= *(volatile s32*)((u8*)p + 0x288)) {
            x = (p->s).coord.x;
          snap:
            (p->s).coord.y = FUN_0800a05c(x, (p->s).coord.y + -0x1000);
            pb4 = (u8*)p;
            asm("" : "+r"(pb4));
            *((u8*)p + 0x284) = 0;
            *(pb4 + 0x285) = 0;
          }
        }
      }
    } else {
      s32 g1 = FUN_0800a05c((p->s).coord.x + 0x1A00, (p->s).coord.y);
      if (g1 != (p->s).coord.y) {
        g1 = FUN_0800a05c((p->s).coord.x + -0x1A00, (p->s).coord.y);
        if (g1 != (p->s).coord.y) {
          g1 = FUN_0800a05c((p->s).coord.x, (p->s).coord.y);
          if (g1 != (p->s).coord.y) {
            s32 z2 = 0;
            u8* pb5 = (u8*)p;
            asm("" : "+r"(pb5));
            *f284b = 1;
            *(pb5 + 0x285) = 1;
            (p->s).d.y = z2;
            if (g1 > *(s32*)((u8*)p + 0x288)) {
              *(s32*)((u8*)p + 0x288) = 0x7FFFFFFF;
              *((u8*)p + 0x286) = 0x78;
            }
          }
        }
      }
    }
  }
#else
  INCCODE("asm/player/harpuia_35684.inc");
#endif
}

// --------------------------------------------

bool8 FUN_0803532c(struct Zero* z);
bool8 FUN_0803537c(struct Zero* z);
bool8 FUN_080353e4(struct Zero* z);
bool8 FUN_080354a4(struct Zero* z);
bool8 FUN_080355c0(struct Zero* z);

// clang-format off
const ZeroFunc sHarpuiaUpdates1[5] = {
    (ZeroFunc)FUN_0803532c,
    (ZeroFunc)FUN_0803537c,
    (ZeroFunc)FUN_080353e4,
    (ZeroFunc)FUN_080354a4,
    (ZeroFunc)FUN_080355c0,
};
// clang-format on

// --------------------------------------------

void FUN_08035330(struct Zero* z);
void FUN_080353a8(struct Zero* z);
void FUN_0803540c(struct Zero* z);
void harpuia_080354d4(struct Zero* z);
void FUN_080355c4(struct Zero* z);

// clang-format off
const ZeroFunc sHarpuiaUpdates2[5] = {
    FUN_08035330,
    FUN_080353a8,
    FUN_0803540c,
    harpuia_080354d4,
    FUN_080355c4,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[7] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {0x0000, -0x2400, 0x1C00, 0x3200},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 32,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x1700, -0x3800, 0x1A00, 0x3800},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 32,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0700, -0x4C00, 0x2400, 0x1700},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {0x0000, -0x2400, 0x1C00, 0x3200},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 32,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x1700, -0x3800, 0x1A00, 0x3800},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 32,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0700, -0x4C00, 0x2400, 0x1700},
    },
    [6] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {0x0000, -0x2400, 0x1C00, 0x3200},
    },
};
