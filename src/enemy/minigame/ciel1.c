#include "collision.h"
#include "enemy.h"
#include "global.h"

void CielMinigameEnemy_Update(struct Enemy* p);

NON_MATCH s32 FUN_0809c110(struct Enemy* p);

struct Enemy* FUN_0809bdd4(struct Entity* e, u8 a1, u8 a2) {
  struct Enemy* p = (struct Enemy*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_CIEL_MG_1);
    (p->s).unk_28 = e;
    (p->s).work[0] = a1;
    (p->s).work[1] = a2;
  }
  return p;
}

void CielMinigameEnemy_Init(struct Enemy* p) {
  struct Entity* q = (p->s).unk_28;
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  InitNonAffineMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetMotion(&p->s, MOTION(0xE9, 0x00));
  UpdateEntityAnim(&p->s);
  ForceEntityPalette(&p->s, (p->s).work[1] + 5);
  SET_XFLIP(p, 0);
  (p->s).coord.x = PIXEL((p->s).work[0] * 32 + 0x18);
  (p->s).coord.y = 0;
  (p->s).d.y = *(vu16*)((u8*)q + 0xE10);
  (p->s).d.x = *(vu16*)((u8*)q + 0xE10);
  (p->s).work[3] = 0;
  CielMinigameEnemy_Update(p);
}

NON_MATCH void CielMinigameEnemy_Update(struct Enemy* p) {
#if MODERN
  struct Entity* q = (p->s).unk_28;
  u8* sv = (u8*)p + 0xb4;
  *(s32*)sv = (p->s).coord.x;
  asm("" : "+r"(sv));
  sv += 4;
  asm("" : "+r"(sv));
  *(s32*)sv = (p->s).coord.y;
  switch ((p->s).mode[1]) {
    case 0:
      (p->s).coord.y += 0x80;
      if ((p->s).coord.y > 0x6FF) {
        (p->s).coord.y = 0x700;
        (p->s).work[2] = 0x3C;
        (p->s).mode[1]++;
      }
      break;
    case 1: {
      s32 t = (p->s).work[2];
      t--;
      (p->s).work[2] = t;
      if ((u8)t == 0xFF) {
        (p->s).work[2] = 0x14;
        (p->s).mode[1]++;
      }
      break;
    }
    case 2: {
      s32 t;
      (p->s).coord.y += 0x20;
      t = (p->s).work[2];
      t--;
      (p->s).work[2] = t;
      if ((u8)t == 0xFF) {
        (p->s).mode[1]++;
      }
      break;
    }
    case 3: {
      s32 t0 = (p->s).coord.y;
      s32 dy = (p->s).d.y;
      s32 ny = t0 + dy;
      register s32 dy2 asm("r3");
      u8 res;
      u8* mg;
      (p->s).coord.y = ny;
      mg = (u8*)q + 0xDCC;
      if (mg[4] <= ({ asm("" : "=r"(dy2) : "0"(dy)); 3u; })) {
        if (gJoypad[0].input & 0x100) {
          (p->s).coord.y = ny + dy2;
        }
        asm volatile("" :: "r"(dy2));
        if (gJoypad[0].input & 0x200) {
          (p->s).coord.y = (p->s).coord.y + dy;
        }
      }
      res = FUN_0809c110(p);
      if (res != 0) {
        if (res == 1) {
          *(s32*)((u8*)p + 0xc0) = (p->s).coord.x + 0x2000;
          (p->s).d.x = (p->s).d.y;
        } else {
          *(s32*)((u8*)p + 0xc0) = (p->s).coord.x + -0x2000;
          (p->s).d.x = -(p->s).d.y;
        }
        (p->s).mode[1]++;
      }
      break;
    }
    case 4: {
      s32 t0 = (p->s).coord.x;
      s32 dx = (p->s).d.x;
      s32 nx = t0 + dx;
      register s32 dx2 asm("r2");
      u8* mg;
      u8* bp;
      u8* e04;
      s32* lim;
      (p->s).coord.x = nx;
      mg = (u8*)q + 0xDCC;
      if (mg[4] <= ({ dx2 = dx; asm volatile("" :: "r"(dx)); 3u; })) {
        if (gJoypad[0].input & 0x100) {
          (p->s).coord.x = nx + dx2;
        }
        if (gJoypad[0].input & 0x200) {
          (p->s).coord.x = (p->s).coord.x + dx2;
        }
      }
      if (dx2 > 0) {
        lim = (s32*)((u8*)p + 0xc0);
        if ((p->s).coord.x > *lim) {
          bp = (u8*)p + 0xbc;
          e04 = (u8*)q + 0xE04;
          asm volatile("");
          goto hitshared;
        }
      } else {
        lim = (s32*)((u8*)p + 0xc0);
        if ((p->s).coord.x < *lim) {
          bp = (u8*)p + 0xbc;
          e04 = (u8*)q + 0xE04;
        hitshared:
          (*(e04 + *bp))--;
          (p->s).coord.x = *lim;
          (p->s).mode[1] = 3;
        }
      }
      break;
    }
  }
  if ((p->s).coord.y > 0x8000) {
    u8* mg = (u8*)q + 0xDCC;
    if (mg[4] <= 3) {
      s32 v = (p->s).coord.x >> 8;
      s32 t = v - 0x18;
      register s32 col asm("r0") = t;
      s32 colf;
      if (t < 0) {
        col = v + 7;
      }
      asm volatile("" :: "r"(t));
      colf = col >> 5;
      if ((u8)colf == (p->s).work[1]) {
        u8* cnt = (u8*)q + 0xDE9;
        cnt[colf]++;
        if (mg[4] <= 3) {
          s32 sc = *(s32*)(mg + 8) + 0xA;
          *(s32*)(mg + 8) = sc;
          if ((u32)sc > 0x1869F) {
            *(s32*)(mg + 8) = 0x1869F;
          }
        }
      } else {
        (*((u8*)q + 0xE13))++;
      }
    }
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
  }
#else
  INCCODE("asm/enemy/minigame_ciel1_bec8.inc");
#endif
}

void CielMinigameEnemy_Die(struct Enemy* p) {
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
}

NON_MATCH s32 FUN_0809c110(struct Enemy* p0) {
#if MODERN

  register struct Enemy* p asm("ip");
  const u8* base6;
  const u8* base5;
  u32 o5;
  struct Entity* q;
  s32 x8;
  u8 k;
  u8 i;
  u32 o6;
  p = p0;
  q = (p->s).unk_28;
  x8 = (p->s).coord.x >> 8;
  k = (x8 - 0x18) / 32;
  i = 0;
  base6 = (const u8*)u8_ARRAY_ARRAY_0836a85c;
  o6 = k * 6;
  base5 = (const u8*)u8_ARRAY_ARRAY_0836a87a;
  o5 = k * 5;
  do {
    const u8* e = base6 + i + o6;
    if (*e == 0xFF) {
      break;
    }
    {
      u8 v = *e;
      s32 yy = ((v >> 1) << 12) + 0x2800;
      if (*(u16*)((u8*)q + 0xdf0 + v * 2) != 0xFF && *(s32*)((u8*)p + 0xb8) < yy && (p->s).coord.y >= yy) {
        *(u8*)((u8*)p + 0xbc) = v;
        (*((u8*)q + 0xE04 + *(u8*)((u8*)p + 0xbc)))++;
        (p->s).coord.y = yy;
        return base5[i + o5];
      }
    }
    i++;
  } while (i <= 5);
  return 0;
#else
  INCCODE("asm/enemy/minigame_ciel1_c110.inc");
#endif
}

void CielMinigameEnemy_Init(struct Enemy* p);
NON_MATCH void CielMinigameEnemy_Update(struct Enemy* p);
void CielMinigameEnemy_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gCielMinigameEnemy1Routine = {
    [ENTITY_INIT] =      CielMinigameEnemy_Init,
    [ENTITY_UPDATE] =    CielMinigameEnemy_Update,
    [ENTITY_DIE] =       CielMinigameEnemy_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// clang-format off
static const u8 u8_ARRAY_ARRAY_0836a85c[5][6] = {
    {0x00, 0x04, 0x08, 0xFF, 0x00, 0x00},
    {0x00, 0x02, 0x04, 0x06, 0x08, 0xFF},
    {0x01, 0x02, 0x05, 0x06, 0x09, 0xFF},
    {0x01, 0x03, 0x05, 0x07, 0x09, 0xFF},
    {0x03, 0x07, 0xFF, 0x00, 0x00, 0x00},
};
// clang-format on

// clang-format off
static const u8 u8_ARRAY_ARRAY_0836a87a[5][5] = {
    {1, 1, 1, 0, 0},
    {2, 1, 2, 1, 2},
    {1, 2, 1, 2, 1},
    {2, 1, 2, 1, 2},
    {2, 2, 0, 0, 0},
};
// clang-format on
