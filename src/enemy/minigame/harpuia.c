#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "vfx.h"
#include "zero.h"

struct VFX* CreateGhost82_2(struct Coord* c, u8 n, u16 r2, s32 y);

void FUN_0809b4dc(struct Enemy* p);

INCASM("asm/enemy/minigame_harpuia_a.inc");

void FUN_0809b4dc(struct Enemy* p0) {
  register struct Enemy* p asm("r5");
  register u32 st asm("r2");
  p = p0;
  st = (p->body).status;
  if (st & 0x200) {
    u8* b6 = (u8*)p + 0xb6;
    u8* b4;
    if (*b6 != 0) {
      struct Entity* sc = (p->s).unk_28;
      s32 k = *(s16*)((u8*)sc + 4);
      b4 = (u8*)p + 0xb4;
      if (k != 2) {
        *(u16*)((u8*)sc + 0x38) = (*b6 << 1) + *(u16*)((u8*)sc + 0x38);
        PlaySound(0x137);
      }
    } else {
      u8* t0 = (u8*)p + 0xb4;
      u32 kv = *t0;
      b4 = t0;
      if (kv == 1) {
        struct Entity* sc = (p->s).unk_28;
        if (*(s16*)((u8*)sc + 4) != 2) {
          *(u16*)((u8*)sc + 0x38) += 5;
          PlaySound(0x137);
        }
      } else {
        struct Entity* sc = (p->s).unk_28;
        if (*(s16*)((u8*)sc + 4) != 2) {
          *(u16*)((u8*)sc + 0x38) += 1;
          PlaySound(0x137);
        }
      }
    }
    CreateSmoke(1, &(p->s).coord);
    PlaySound(0x2A);
    {
      u32 n = RANDOM(RNG_0202f388) & 3;
      struct Coord c;
      c.x = (p->s).coord.x;
      c.y = (p->s).coord.y;
      CreateGhost82_2(&c, *b4 + 1, 0x4707, n);
      CreateGhost82_2(&c, *b4 + 1, 0x4708, n);
      CreateGhost82_2(&c, *b4 + 1, 0x4709, n);
    }
    SET_ENEMY_ROUTINE(p, 2);
    return;
  }
  {
    u8* b5;
    {
      u8* t = (u8*)p + 0xb5;
      u32 v = *t;
      b5 = t;
      if (v == 0) {
        u32 one = 1;
        st &= one;
        if (st != 0) {
          if ((p->s).unk_2c != NULL) {
            *b5 = one;
            (p->s).mode[2] = 0xA;
          }
        }
      }
    }
    switch ((p->s).mode[2]) {
      case 0: {
        (p->s).unk_2c = NULL;
        *b5 = 0;
        {
          u8* t = (u8*)p + 0xb6;
          *t = 0;
          t += 1;
          *t = 0;
        }
        SetMotion(&p->s, MOTION(0x47, 0x03));
        if ((pZero2->s).coord.x > (p->s).coord.x) {
          register u32 one asm("r2");
          one = 1;
          (p->s).flags |= 0x10;
          *((u8*)p + 0x4c) = one;
          {
            register u8* oa asm("r3");
            register s32 k asm("r2");
            oa = (u8*)p + 0x4a;
            k = 0x10;
            {
              s32 ov = *oa;
              s32 m11 = -0x11;
              m11 &= ov;
              m11 |= k;
              *oa = m11;
            }
          }
        } else {
          (p->s).flags &= 0xEF;
          *((u8*)p + 0x4c) = 0;
          {
            u8* oa2 = (u8*)p + 0x4a;
            s32 ov2 = *oa2;
            s32 m12 = -0x11;
            m12 &= ov2;
            *oa2 = m12;
          }
        }
        (p->s).work[2] = 0x1E;
        (p->s).mode[2]++;
        FALLTHROUGH;
      }
      case 1: {
        {
          s32 d = (p->s).unk_coord.x;
          s32 cx = (p->s).coord.x;
          d -= cx;
          (p->s).coord.x = cx + ((d * 24) >> 8);
        }
        {
          s32 d2 = (p->s).unk_coord.y;
          s32 cy = (p->s).coord.y;
          d2 -= cy;
          (p->s).coord.y = cy + ((d2 * 24) >> 8);
        }
        UpdateEntityAnim(&p->s);
        {
          u32 t = (p->s).work[2] - 1;
          (p->s).work[2] = t;
          if ((t << 24) == 0) {
            (p->s).mode[2]++;
          }
        }
        break;
      }
      case 2:
        (p->s).work[2] = 0x30;
        (p->s).mode[2]++;
        FALLTHROUGH;
      case 3: {
        {
          s32 d = (p->s).unk_coord.x;
          s32 cx = (p->s).coord.x;
          d -= cx;
          (p->s).coord.x = cx + ((d * 24) >> 8);
        }
        {
          s32 d2 = (p->s).unk_coord.y;
          s32 cy = (p->s).coord.y;
          d2 -= cy;
          (p->s).coord.y = cy + ((d2 * 24) >> 8);
        }
        UpdateEntityAnim(&p->s);
        {
          u32 t = (p->s).work[2] - 1;
          (p->s).work[2] = t;
          if ((t << 24) == 0) {
            (p->s).mode[2] = 5;
          }
        }
        break;
      }
      case 5: {
        s32 dx;
        s32 dy;
        u32 spd;
        (p->s).unk_2c = NULL;
        *b5 = 0;
        SetMotion(&p->s, MOTION(0x47, 0x03));
        {
          struct Zero* z = pZero2;
          dx = (p->s).coord.x - (z->s).coord.x;
          (p->s).unk_coord.x = dx;
          dy = (p->s).coord.y;
          dy += 0x80 << 5;
          dy -= (z->s).coord.y;
          (p->s).unk_coord.y = dy;
        }
        spd = ((u32)(Sqrt((dx >> 2) * (dx >> 2) + (dy >> 2) * (dy >> 2)) << 16)) >> 14;
        if (spd != 0) {
          (p->s).unk_coord.x = ((p->s).unk_coord.x << 8) / (s32)spd;
          (p->s).unk_coord.y = ((p->s).unk_coord.y << 8) / (s32)spd;
        } else {
          if (((pZero2->s).flags & 0x10) == 0) {
            (p->s).unk_coord.x = -0x100;
          } else {
            (p->s).unk_coord.x = 0x80 << 1;
          }
          (p->s).unk_coord.y = spd;
        }
        (p->s).d.x = -((p->s).unk_coord.x * 640) >> 8;
        (p->s).d.y = -((p->s).unk_coord.y * 640) >> 8;
        PlaySound(0x108);
        (p->s).work[2] = 0xB4;
        (p->s).mode[2]++;
        FALLTHROUGH;
      }
      case 6: {
        {
          s32 cx = (p->s).coord.x;
          cx += (p->s).d.x;
          (p->s).coord.x = cx;
        }
        {
          s32 cy = (p->s).coord.y;
          cy += (p->s).d.y;
          (p->s).coord.y = cy;
        }
        UpdateEntityAnim(&p->s);
        {
          u32 t = (p->s).work[2] - 1;
          (p->s).work[2] = t;
          if ((t << 24) != 0) {
            break;
          }
        }
        SET_ENEMY_ROUTINE(p, 2);
        break;
      }
      case 10: {
        s32 dx;
        s32 dy;
        u32 spd;
        {
          struct Zero* z = pZero2;
          dx = (p->s).coord.x - (z->s).coord.x;
          (p->s).unk_coord.x = dx;
          dy = (p->s).coord.y;
          dy += 0x80 << 5;
          dy -= (z->s).coord.y;
          (p->s).unk_coord.y = dy;
        }
        spd = ((u32)(Sqrt((dx >> 2) * (dx >> 2) + (dy >> 2) * (dy >> 2)) << 16)) >> 14;
        if (spd != 0) {
          (p->s).unk_coord.x = ((p->s).unk_coord.x << 8) / (s32)spd;
          (p->s).unk_coord.y = ((p->s).unk_coord.y << 8) / (s32)spd;
        } else {
          if (((pZero2->s).flags & 0x10) == 0) {
            (p->s).unk_coord.x = -0x100;
          } else {
            (p->s).unk_coord.x = 0x80 << 1;
          }
          (p->s).unk_coord.y = spd;
        }
        (p->s).d.x = ((p->s).unk_coord.x * 7 << 8) >> 8;
        (p->s).d.y = ((p->s).unk_coord.y * 7 << 8) >> 8;
        SetMotion(&p->s, MOTION(0x47, 0x03));
        SetDDP(&p->body, (const struct Collision*)0x836A800);
        (p->s).work[2] = 0x1E;
        (p->s).mode[2]++;
        FALLTHROUGH;
      }
      case 11: {
        s32 vx;
        s32 vy;
        {
          s32 cx = (p->s).coord.x;
          vx = (p->s).d.x;
          (p->s).coord.x = cx + vx;
        }
        {
          s32 cy = (p->s).coord.y;
          vy = (p->s).d.y;
          (p->s).coord.y = cy + vy;
        }
        (p->s).d.x = vx + ((-vx * 24) >> 8);
        (p->s).d.y = vy + ((-vy * 24) >> 8);
        UpdateEntityAnim(&p->s);
        {
          u32 t = (p->s).work[2] - 1;
          (p->s).work[2] = t;
          if ((t << 24) != 0) {
            break;
          }
        }
        {
          struct Entity* sc = (p->s).unk_28;
          if (*(s16*)((u8*)sc + 4) != 2) {
            *(u16*)((u8*)sc + 0x38) += 5;
            PlaySound(0x137);
          }
        }
        CreateSmoke(1, &(p->s).coord);
        PlaySound(0x2A);
        SET_ENEMY_ROUTINE(p, 2);
        break;
      }
    }
  }
}

INCASM("asm/enemy/minigame_harpuia_b.inc");

void HarpuiaMinigameEnemy_Init(struct Enemy* p);
void HarpuiaMinigameEnemy_Update(struct Enemy* p);
void HarpuiaMinigameEnemy_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gHarpuiaMinigameEnemyRoutine = {
    [ENTITY_INIT] =      (void*)HarpuiaMinigameEnemy_Init,
    [ENTITY_UPDATE] =    (void*)HarpuiaMinigameEnemy_Update,
    [ENTITY_DIE] =       (void*)HarpuiaMinigameEnemy_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_0809b350(struct Enemy* p);
void FUN_0809b408(struct Enemy* p);
void FUN_0809b410(struct Enemy* p);
void FUN_0809b418(struct Enemy* p);
void FUN_0809b4d8(struct Enemy* p);
void FUN_0809b950(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[6] = {
    FUN_0809b350,
    FUN_0809b408,
    FUN_0809b410,
    FUN_0809b418,
    FUN_0809b4d8,
    FUN_0809b950,
};
// clang-format on

void FUN_0809b354(struct Enemy* p);
void FUN_0809b40c(struct Enemy* p);
void FUN_0809b414(struct Enemy* p);
void FUN_0809b41c(struct Enemy* p);
void FUN_0809b4dc(struct Enemy* p);
void FUN_0809b954(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[6] = {
    FUN_0809b354,
    FUN_0809b40c,
    FUN_0809b414,
    FUN_0809b41c,
    FUN_0809b4dc,
    FUN_0809b954,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[5] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      damage : 8,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
};
