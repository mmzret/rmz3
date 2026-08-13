#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "physics.h"
#include "physics.h"

static const s32 s32_ARRAY_08369728[16];
static const s32 s32_ARRAY_083697b0[6];
static const s32 s32_ARRAY_083697c8[6];
static const struct Collision sCollisions[12];
static const motion_t sMotions2[6];

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 buffer[12];         // 0xB4
  void* enti_c0;         // 0xC0, Entity*
} Petatria;
static_assert(sizeof(Petatria) == sizeof(struct Enemy));

Petatria* Unused_CreatePetatria(Coords32* c, u8 mode) {
  Petatria* p = (Petatria*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_PETATRIA);
    p->coord = *c;
    p->work[0] = mode;
  }
  return p;
}

INCASM("asm/enemy/petatria_a.inc");

static const EnemyFunc sUpdates1[10];
static const EnemyFunc sUpdates2[10];
bool8 FUN_08091188(Petatria* p);
void Petatria_Die(Petatria* p);

void Petatria_Update(Petatria* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    Petatria_Die(p);
    return;
  }
  (sUpdates1[p->mode[1]])((void*)p);
  FUN_08091188((Petatria*)p);
  if (IsFrozen(p)) {
    return;
  }
  if (p->enti_c0 != NULL) {
    if (!isKilled(p->enti_c0)) {
      return;
    }
    p->enti_c0 = NULL;
  }
  (sUpdates2[p->mode[1]])((void*)p);
}

INCASM("asm/enemy/petatria_b.inc");

bool8 FUN_080902a8(Petatria* p) {
  if ((p->body).status & BODY_STATUS_B3) {
    p->mode[1] = 4, p->mode[2] = 0;
  }
  return TRUE;
}

INCASM("asm/enemy/petatria_c.inc");

bool8 FUN_080906ec(Petatria* p) {
  if ((p->body).status & BODY_STATUS_B3) {
    p->mode[1] = 5, p->mode[2] = 0;
  }
  return TRUE;
}

void FUN_0809070c(Petatria* p0) {
  register Petatria* p asm("r4");
  p = p0;
  switch (p->mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[2]);
      p->work[3] = 0;
      p->unk_coord.y = p->coord.y;
      SetMotion((struct Entity*)p, 0x7E06);
      p->mode[2]++;
      FALLTHROUGH;
    case 1:
      if (p->d.y > 0) {
        p->mode[2] = 2;
      } else {
        p->mode[2] = 0x14;
      }
      UpdateEntityAnim((struct Entity*)p);
      FALLTHROUGH;
    case 2: {
      register u8* b9 asm("r5");
      {
        register u32 st asm("r0");
        st = p->motion.state;
        b9 = (u8*)p + 0xb9;
        if (st == 3) {
          u32 w3 = p->work[3];
          if (w3 != 0) {
            w3 = w3 - 1;
          } else {
            (*b9)++;
            w3 = 5;
          }
          p->work[3] = w3;
          {
            register const u8* tbs asm("r1");
            tbs = (const u8*)s32_ARRAY_083697b0;
            asm("" : "+r"(tbs));
            p->unk_coord.y -= *(const s32*)((p->work[3] << 2) + (u32)tbs);
          }
          {
            register const u8* tbm asm("r1");
            tbm = (const u8*)sMotions2;
            asm("" : "+r"(tbm));
            SetMotion((struct Entity*)p, *(const motion_t*)((p->work[3] << 1) + (u32)tbm));
          }
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      p->coord.y = p->unk_coord.y;
      if (*b9 > 3) {
        register s32 z6 asm("r6");
        register const u8* tb asm("r3");
        z6 = 0;
        *b9 = z6;
        tb = (const u8*)s32_ARRAY_08369728;
        asm("" : "+r"(tb));
        if (*(const s32*)(((RANDOM(RNG_0202f388) & 0xF) << 2) + (u32)tb) != 0) {
          p->mode[1] = 3;
          p->mode[2] = z6;
        }
      }
      if (p->mode[1] == 3) {
        break;
      }
      {
        s32 r = PushoutToUp1(p->coord.x, p->coord.y);
        if (r != 0) {
          p->coord.y += r;
          p->mode[2]++;
        }
      }
      {
        register u32 pb8 asm("r5");
        pb8 = *((u8*)p + 0xb8);
        if (pb8 == 1) {
          {
            register s32 g1 asm("r1");
            s32 rv = FUN_0800a22c(p->coord.x, p->coord.y);
            asm("add %0, %1, #0" : "=r"(g1) : "r"(rv));
            if (g1 == p->coord.x + (0x80 << 6)) {
              break;
            }
          }
          p->d.y = -0xCC;
          p->mode[2] = pb8;
          break;
        }
      }
      {
        register s32 g2 asm("r1");
        s32 rv2 = FUN_0800a31c(p->coord.x, p->coord.y);
        asm("add  %0, %1, #0" : "=r"(g2) : "r"(rv2));
        if (g2 == p->coord.x + -0x2000) {
          break;
        }
      }
      p->d.y = -0xCC;
      p->mode[2] = 1;
      break;
    }
    case 3: {
      register u32 mv asm("r1");
      {
        register u32 mid asm("r0");
        mid = p->motionID;
        mv = mid << 8;
      }
      {
        register u32 st asm("r0");
        st = p->motion.id;
        mv |= st;
      }
      if (mv + -0x7E06 <= 1 || mv == 0x7E0B) {
        p->mode[2]++;
        break;
      }
      if (p->motion.state != 3) {
        UpdateEntityAnim((struct Entity*)p);
        break;
      }
      if (*((u8*)p + 0xb8) == 1) {
        u32 w3 = p->work[3];
        if (w3 != 0) {
          w3 = w3 - 1;
          p->work[3] = w3;
        } else {
          goto five3;
        }
      } else {
        u32 w3b = p->work[3];
        if (w3b != 0) {
          w3b = w3b - 1;
          p->work[3] = w3b;
        } else {
        five3:
          w3b = 5;
          p->work[3] = w3b;
        }
      }
      {
        register const u8* tbm0 asm("r0");
        register u32 i21 asm("r1");
        tbm0 = (const u8*)sMotions2;
        i21 = p->work[3];
        SetMotion((struct Entity*)p, *(const motion_t*)((i21 << 1) + (u32)tbm0));
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
    case 4:
      SetMotion((struct Entity*)p, 0x7E0D);
      p->mode[2]++;
      FALLTHROUGH;
    case 5:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
      if (*((u8*)p + 0xb8) == 1) {
        p->d.x = -0xCC;
      } else {
        p->d.x = 0xCC;
      }
      p->mode[1] = 0;
      p->mode[2] = 0;
      break;
    case 20: {
      register u8* b9 asm("r5");
      {
        register u32 st asm("r0");
        st = p->motion.state;
        b9 = (u8*)p + 0xb9;
        if (st == 3) {
          u32 w3 = p->work[3] + 1;
          p->work[3] = w3;
          if ((u8)w3 > 5) {
            (*b9)++;
            p->work[3] = 0;
          }
          {
            register const u8* tba asm("r1");
            tba = (const u8*)s32_ARRAY_083697c8;
            asm("" : "+r"(tba));
            p->unk_coord.y += *(const s32*)((p->work[3] << 2) + (u32)tba);
          }
          {
            register const u8* tbm asm("r1");
            tbm = (const u8*)sMotions2;
            asm("" : "+r"(tbm));
            SetMotion((struct Entity*)p, *(const motion_t*)((p->work[3] << 1) + (u32)tbm));
          }
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      p->coord.y = p->unk_coord.y;
      if (*b9 > 3) {
        register s32 z6 asm("r6");
        register const u8* tb asm("r3");
        z6 = 0;
        *b9 = z6;
        tb = (const u8*)s32_ARRAY_08369728;
        asm("" : "+r"(tb));
        if (*(const s32*)(((RANDOM(RNG_0202f388) & 0xF) << 2) + (u32)tb) != 0) {
          p->mode[1] = 3;
          p->mode[2] = z6;
        }
      }
      if (p->mode[1] == 3) {
        break;
      }
      {
        register s32 r20 asm("r1");
        s32 rv0 = PushoutToDown1(p->coord.x, p->coord.y + -0x6000);
        asm("add   %0, %1, #0" : "=r"(r20) : "r"(rv0));
        if (r20 != 0) {
          p->d.y = 0xCC;
          p->mode[2] = 1;
        }
      }
      {
        register u32 pb8 asm("r5");
        pb8 = *((u8*)p + 0xb8);
        if (pb8 == 1) {
          {
            register s32 g1 asm("r1");
            s32 rv = FUN_0800a22c(p->coord.x, p->coord.y + -0x3000);
            asm("add %0, %1, #0" : "=r"(g1) : "r"(rv));
            if (g1 == p->coord.x + (0x80 << 6)) {
              break;
            }
          }
          p->d.y = 0xCC;
          p->mode[2] = pb8;
          break;
        }
      }
      {
        register s32 g2 asm("r1");
        s32 rv2 = FUN_0800a31c(p->coord.x, p->coord.y + -0x3000);
        asm("add  %0, %1, #0" : "=r"(g2) : "r"(rv2));
        if (g2 == p->coord.x + -0x2000) {
          break;
        }
      }
      p->d.y = 0xCC;
      p->mode[2] = 1;
      break;
    }
    case 21: {
      register u32 mv asm("r1");
      {
        register u32 mid asm("r0");
        mid = p->motionID;
        mv = mid << 8;
      }
      {
        register u32 st asm("r0");
        st = p->motion.id;
        mv |= st;
      }
      if (mv + -0x7E06 <= 1 || mv == 0x7E0B) {
        p->mode[2]++;
        break;
      }
      if (p->motion.state != 3) {
        UpdateEntityAnim((struct Entity*)p);
        break;
      }
      asm volatile("" ::"r"(*((u8*)p + 0xb8)));
      {
        u32 w3 = p->work[3] + 1;
        p->work[3] = w3;
        if ((u8)w3 > 5) {
          p->work[3] = 0;
        }
      }
      {
        register const u8* tbm0 asm("r0");
        register u32 i21 asm("r1");
        tbm0 = (const u8*)sMotions2;
        i21 = p->work[3];
        SetMotion((struct Entity*)p, *(const motion_t*)((i21 << 1) + (u32)tbm0));
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
    case 22:
      SetMotion((struct Entity*)p, 0x7E0D);
      p->mode[2]++;
      FALLTHROUGH;
    case 23:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
      if (*((u8*)p + 0xb8) == 1) {
        p->d.x = -0xCC;
      } else {
        p->d.x = 0xCC;
      }
      p->mode[1] = 0;
      p->mode[2] = 0;
      break;
  }
}

bool8 FUN_08090b20(Petatria* p) { return TRUE; }

INCASM("asm/enemy/petatria_e.inc");

bool8 FUN_08090c60(Petatria* p) { return TRUE; }

INCASM("asm/enemy/petatria_f.inc");

bool8 FUN_08090da4(Petatria* p) { return TRUE; }

INCASM("asm/enemy/petatria_g.inc");

bool8 FUN_08090edc(Petatria* p) { return TRUE; }

INCASM("asm/enemy/petatria_h.inc");

bool8 FUN_08091068(Petatria* p) { return TRUE; }

INCASM("asm/enemy/petatria_i.inc");

bool8 FUN_08091150(Petatria* p) { return TRUE; }

void FUN_08091154(Petatria* p) {
  if (p->mode[2] == 0) p->mode[2] = 1;
}

bool8 FUN_08091168(Petatria* p) { return TRUE; }

void FUN_0809116c(Petatria* p) {}

bool8 FUN_08091170(Petatria* p) { return TRUE; }

void FUN_08091174(Petatria* p) {
  if (p->mode[2] == 0) p->mode[2] = 1;
}

bool8 FUN_08091188(Petatria* p) { return TRUE; }

INCASM("asm/enemy/petatria_j.inc");

void nop_0809127c(Petatria* p) {}

void Petatria_Init(Petatria* p);
void Petatria_Update(Petatria* p);
void Petatria_Die(Petatria* p);

// clang-format off
const EnemyRoutine gPetatriaRoutine = {
    [ENTITY_INIT] =      (void*)Petatria_Init,
    [ENTITY_UPDATE] =    (void*)Petatria_Update,
    [ENTITY_DIE] =       (void*)Petatria_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// clang-format off
static const EnemyFunc sUpdates1[10] = {
    (EnemyFunc)FUN_080902a8,
    (EnemyFunc)FUN_080906ec,
    (EnemyFunc)FUN_08090b20,
    (EnemyFunc)FUN_08090c60,
    (EnemyFunc)FUN_08090da4,
    (EnemyFunc)FUN_08090edc,
    (EnemyFunc)FUN_08091068,
    (EnemyFunc)FUN_08091150,
    (EnemyFunc)FUN_08091168,
    (EnemyFunc)FUN_08091170,
};
// clang-format on

void FUN_080902c8(Petatria* p);
void FUN_0809070c(Petatria* p);
void FUN_08090b24(Petatria* p);
void FUN_08090c64(Petatria* p);
void FUN_08090da8(Petatria* p);
void FUN_08090ee0(Petatria* p);
void FUN_0809106c(Petatria* p);

// clang-format off
static const EnemyFunc sUpdates2[10] = {
    (EnemyFunc)FUN_080902c8,
    (EnemyFunc)FUN_0809070c,
    (EnemyFunc)FUN_08090b24,
    (EnemyFunc)FUN_08090c64,
    (EnemyFunc)FUN_08090da8,
    (EnemyFunc)FUN_08090ee0,
    (EnemyFunc)FUN_0809106c,
    (void*)FUN_08091154,
    (EnemyFunc)FUN_0809116c,
    (void*)FUN_08091174,
};
// clang-format on

// --------------------------------------------

// 0x08369608
static const struct Collision sCollisions[12] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(16), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(16), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(17), -PIXEL(25), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(17), -PIXEL(25), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(16), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 1,
      range : {PIXEL(0), -PIXEL(29), PIXEL(10), PIXEL(10)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(10), PIXEL(26), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(17), -PIXEL(25), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 1,
      range : {PIXEL(3), -PIXEL(25), PIXEL(10), PIXEL(10)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(22), -PIXEL(25), PIXEL(14), PIXEL(26)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(16), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(16), PIXEL(26), PIXEL(26)},
    },
};

static const s32 s32_ARRAY_08369728[16] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

// clang-format off
// 0x08369768
static const motion_t sMotions1[6] = {
    MOTION(SM126_PETATRIA, 0),
    MOTION(SM126_PETATRIA, 1),
    MOTION(SM126_PETATRIA, 2),
    MOTION(SM126_PETATRIA, 3),
    MOTION(SM126_PETATRIA, 4),
    MOTION(SM126_PETATRIA, 5),
};
// clang-format on

static const s32 s32_ARRAY_08369774[6] = {
    PIXEL(1), PIXEL(2), PIXEL(5), PIXEL(5), PIXEL(2), PIXEL(1),
};
static const s32 s32_ARRAY_0836978c[6] = {
    PIXEL(1), PIXEL(1), PIXEL(2), PIXEL(5), PIXEL(5), PIXEL(2),
};

// clang-format off
static const motion_t sMotions2[6] = {
    MOTION(SM126_PETATRIA, 6),
    MOTION(SM126_PETATRIA, 7),
    MOTION(SM126_PETATRIA, 8),
    MOTION(SM126_PETATRIA, 9),
    MOTION(SM126_PETATRIA, 10),
    MOTION(SM126_PETATRIA, 11),
};
// clang-format on

static const s32 s32_ARRAY_083697b0[6] = {
    -PIXEL(1), -PIXEL(2), -PIXEL(5), -PIXEL(5), -PIXEL(2), -PIXEL(1),
};
static const s32 s32_ARRAY_083697c8[6] = {
    -PIXEL(1), -PIXEL(1), -PIXEL(2), -PIXEL(5), -PIXEL(5), -PIXEL(2),
};
