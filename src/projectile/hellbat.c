#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "physics.h"
#include "physics.h"
#include "physics.h"
#include "stagerun.h"

struct VFX* FUN_080bde9c(struct Entity* e, struct Coord* c, u8 a2, u8 a3);

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 unk_b4;             // 0xB4
  u8 unk_b5;             // 0xB5
  u8 unk_b6;             // 0xB6
  u8 unk_b7;             // 0xB7
  u8 unk_b8[4];          // 0xB8
  u32 unk_bc;            // 0xBC
  u8 unk_c0[4];          // 0xC0
} HellbatProjectile;
static_assert(sizeof(HellbatProjectile) == sizeof(Projectile));

// Entity.work[0]
enum {
  HELLBAT_PROJ_BAT = 0,
  HELLBAT_PROJ_ECHO_WAVE,
  HELLBAT_PROJ_UNK2,
  HELLBAT_PROJ_UNK3,
  HELLBAT_PROJ_UNK4,
};

static const struct Collision sCollisions[9];

static void Projectile15_Init(HellbatProjectile* p);
static void Projectile15_Update(HellbatProjectile* p);
static void Projectile15_Die(HellbatProjectile* p);

// clang-format off
const ProjectileRoutine gHellbatProjectileRoutine = {
    [ENTITY_INIT] =      (void*)Projectile15_Init,
    [ENTITY_UPDATE] =    (void*)Projectile15_Update,
    [ENTITY_DIE] =       (void*)Projectile15_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

typedef void (*HellbatProjectileFunc)(HellbatProjectile*);

HellbatProjectile* createBat(Entity* hellbat, Coords32* c, u8 a2, u8 a3) {
  HellbatProjectile* p = (HellbatProjectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 15);
    p->work[0] = 0;
    p->unk_b5 = a2;
    p->unk_b6 = a3;
    p->coord = *c;
    p->unk_28 = hellbat;
  }
  return p;
}

HellbatProjectile* createEchoWave(Entity* hellbat, Coords32* c, u8 a2) {
  HellbatProjectile* p = (HellbatProjectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 15);
    p->work[0] = 1;
    p->unk_b5 = a2;
    p->coord = *c;
    p->unk_28 = hellbat;
  }
  return p;
}

HellbatProjectile* FUN_080a14dc(Entity* hellbat, Coords32* c, u8 a2) {
  HellbatProjectile* p = (HellbatProjectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 15);
    p->work[0] = 2;
    p->unk_b5 = a2;
    p->coord = *c;
    p->unk_28 = hellbat;
  }
  return p;
}

HellbatProjectile* FUN_080a1538(Entity* hellbat, Coords32* c, u8 a2) {
  HellbatProjectile* p = (HellbatProjectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 15);
    p->work[0] = 3;
    p->unk_b5 = a2;
    p->coord = *c;
    p->unk_28 = hellbat;
  }
  return p;
}

HellbatProjectile* FUN_080a1594(Entity* hellbat, Coords32* c, u8 a2) {
  HellbatProjectile* p = (HellbatProjectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 15);
    p->work[0] = 4;
    p->unk_b5 = a2;
    p->coord = *c;
    p->unk_28 = hellbat;
  }
  return p;
}

static void Projectile15_Init(HellbatProjectile* p) {
  p->work[2] = 0xFF;
  if (p->work[0] == HELLBAT_PROJ_BAT) {
    EnableSpriteAnimation_Normal(p);
    _INIT_BODY(p, &sCollisions[0], 4);
  } else if (p->work[0] == HELLBAT_PROJ_ECHO_WAVE) {
    EnableSpriteAnimation_Normal(p);
    p->work[2] = 0;
    p->unk_bc = 0;
    EnableSpriteAnimation_Normal(p);
    p->angle = 0, (p->spr).mag.x = 0x100, (p->spr).mag.y = 0x100;
    _INIT_BODY(p, &sCollisions[5], 1);
  } else if (p->work[0] == HELLBAT_PROJ_UNK2) {
    EnableSpriteAnimation_Normal(p);
    _INIT_BODY(p, &sCollisions[2], 1);
  } else if (p->work[0] == HELLBAT_PROJ_UNK3) {
    EnableSpriteAnimation_Affine(p);
    p->angle = 0, (p->spr).mag.x = 0x100, (p->spr).mag.y = 0x100;
    _INIT_BODY(p, &sCollisions[3], 1);
  } else if (p->work[0] == HELLBAT_PROJ_UNK4) {
    EnableSpriteAnimation_Normal(p);
    _INIT_BODY(p, &sCollisions[3], 1);
  }

  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteTableDynamic(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 1, p->mode[2] = 0, p->mode[3] = 0;
  Projectile15_Update(p);
}

static const HellbatProjectileFunc* const sUpdates[5];

static void Projectile15_Update(HellbatProjectile* p) { (sUpdates[p->work[0]][p->mode[1]])(p); }

static void Projectile15_Die(HellbatProjectile* p) {
  p->flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

static void FUN_080a176c(HellbatProjectile* p) {
  p->mode[1] = 1;
  p->mode[2] = 0;
}

INCASM("asm/projectile/hellbat_b.inc");

static void FUN_080a1a10(HellbatProjectile* p) {
  p->mode[1] = 1;
  p->mode[2] = 0;
}

void FUN_080a1a1c(HellbatProjectile* p0) {
  register HellbatProjectile* p asm("r4");
  p = p0;
  {
    s32* bc = (s32*)((u8*)p + 0xbc);
    s32 t = *bc;
    if (t > 0) {
      *bc = t - 1;
    }
  }
  if ((p->unk_28)->mode[0] > 1) {
    u8* t = (u8*)p + 0x8c;
    u32 z = 0;
    *(u32*)t = z;
    asm("" : "+r"(t));
    t += 4;
    *(u32*)t = z;
    asm("" : "+r"(t));
    t += 4;
    *t = z;
    p->flags &= 0xFB;
  }
  switch (p->mode[2]) {
    case 0: {
      u32 b5;
      p->work[2] = 0;
      p->work[3] = 0;
      p->unk_coord.x = 0;
      b5 = *((u8*)p + 0xb5);
      if (b5 == 0) {
        p->d.x = gSineTable[0xCA] * 2;
        p->d.y = gSineTable[0x0A] * 2;
        SetMotion((struct Entity*)p, MOTION(0xA9, 0x06));
        p->flags &= 0xEF;
        *((u8*)p + 0x4c) = 0;
        {
          u8* oa = (u8*)p + 0x4a;
          s32 ov = *oa;
          s32 m11 = -0x11;
          m11 &= ov;
          *oa = m11;
        }
        SetDDP(&p->body, (const struct Collision*)0x836B2DC);
      } else if (b5 == 1) {
        p->d.x = gSineTable[0xB6] * 2;
        p->d.y = gSineTable[0xF6] * 2;
        SetMotion((struct Entity*)p, MOTION(0xA9, 0x06));
        p->flags |= 0x10;
        *((u8*)p + 0x4c) = b5;
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
        SetDDP(&p->body, (const struct Collision*)0x836B2DC);
      } else if (b5 == 2) {
        p->d.x = gSineTable[0x4A] * 2;
        p->d.y = gSineTable[0x8A] * 2;
        SetMotion((struct Entity*)p, MOTION(0xA9, 0x06));
        p->flags &= 0xEF;
        *((u8*)p + 0x4c) = 0;
        {
          u8* oa = (u8*)p + 0x4a;
          s32 ov = *oa;
          s32 m11 = -0x11;
          m11 &= ov;
          *oa = m11;
        }
        SetDDP(&p->body, (const struct Collision*)0x836B2DC);
      } else if (b5 == 3) {
        u32 one;
        p->d.x = gSineTable[0x36] * 2;
        p->d.y = gSineTable[0x76] * 2;
        SetMotion((struct Entity*)p, MOTION(0xA9, 0x06));
        one = 1;
        p->flags |= 0x10;
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
        SetDDP(&p->body, (const struct Collision*)0x836B2DC);
      } else if (b5 == 4) {
        u32 one;
        p->d.x = gSineTable[0x8A] * 2;
        p->d.y = gSineTable[0xCA] * 2;
        SetMotion((struct Entity*)p, MOTION(0xA9, 0x0A));
        one = 1;
        p->flags |= 0x10;
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
        SetDDP(&p->body, (const struct Collision*)0x836B2F4);
      } else if (b5 == 5) {
        p->d.x = gSineTable[0x76] * 2;
        p->d.y = gSineTable[0xB6] * 2;
        SetMotion((struct Entity*)p, MOTION(0xA9, 0x0A));
        p->flags &= 0xEF;
        *((u8*)p + 0x4c) = 0;
        {
          u8* oa = (u8*)p + 0x4a;
          s32 ov = *oa;
          s32 m11 = -0x11;
          m11 &= ov;
          *oa = m11;
        }
        SetDDP(&p->body, (const struct Collision*)0x836B2F4);
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 sv[4];
      s32 vx;
      u32 hit = 0;
      s32 nx;
      s32 ny;
      register s32 vx5 asm("r5");
      u32 b7;
      {
        s32 c0 = p->coord.x;
        vx5 = p->d.x;
        nx = c0 + vx5;
        p->coord.x = nx;
      }
      {
        s32 c1 = p->coord.y;
        s32 vy3 = p->d.y;
        ny = c1 + vy3;
        p->coord.y = ny;
        b7 = *((u8*)p + 0xb5);
        if ((s32)b7 <= 3) {
          if (vy3 < 0) {
            sv[0] = 0;
            {
              u8* sr = (u8*)&gStageRun + 232;
              asm("" : "+r"(sr));
              if (ny < *(s32*)(sr + 0x3c) + -0x5000) {
                sv[0] = 1;
              }
            }
            sv[1] = PushoutToLeft1(p->coord.x, p->coord.y);
            sv[2] = PushoutToRight1(p->coord.x, p->coord.y);
            if (sv[1] != 0 && (vx = p->d.x) > 0) {
              p->coord.x += sv[1];
              p->d.x = -vx;
              hit = 1;
            } else if (sv[2] != 0 && (vx = p->d.x) < 0) {
              p->coord.x += sv[2];
              p->d.x = -vx;
              hit = 1;
            } else if (sv[0] != 0) {
              p->coord.y += sv[0];
              p->d.y = -p->d.y;
              hit = 1;
            }
          } else {
            sv[0] = PushoutToUp1(nx, ny);
            sv[1] = PushoutToLeft1(p->coord.x, p->coord.y);
            sv[2] = PushoutToRight1(p->coord.x, p->coord.y);
            if (sv[1] != 0 && (vx = p->d.x) > 0) {
              p->coord.x += sv[1];
              p->d.x = -vx;
              hit = 1;
            } else if (sv[2] != 0 && (vx = p->d.x) < 0) {
              p->coord.x += sv[2];
              p->d.x = -vx;
              hit = 1;
            } else if (sv[0] != 0) {
              p->coord.y += sv[0];
              p->d.y = -p->d.y;
              hit = 1;
            }
          }
        } else {
          if (vx5 > 0) {
            sv[0] = PushoutToUp1(nx, ny);
            sv[1] = 0;
            {
              u8* sr = (u8*)&gStageRun + 232;
              asm("" : "+r"(sr));
              if (p->coord.y < *(s32*)(sr + 0x3c) + -0x5000) {
                sv[1] = 1;
              }
            }
            sv[2] = PushoutToLeft1(p->coord.x, p->coord.y);
            if (sv[1] != 0 && (vx = p->d.y) < 0) {
              p->coord.y += sv[1];
              p->d.y = -vx;
              hit = 1;
            } else if (sv[2] != 0 && (vx = p->d.y) > 0) {
              p->coord.y += sv[2];
              p->d.y = -vx;
              hit = 1;
            } else if (sv[0] != 0) {
              p->coord.x += sv[0];
              p->d.x = -p->d.x;
              hit = 1;
            }
          } else {
            sv[0] = PushoutToUp1(nx, ny);
            sv[1] = 0;
            {
              u8* sr = (u8*)&gStageRun + 232;
              asm("" : "+r"(sr));
              if (p->coord.y < *(s32*)(sr + 0x3c) + -0x5000) {
                sv[1] = 1;
              }
            }
            sv[2] = PushoutToRight1(p->coord.x, p->coord.y);
            if (sv[1] != 0 && (vx = p->d.y) < 0) {
              p->coord.y += sv[1];
              p->d.y = -vx;
              hit = 1;
            } else if (sv[2] != 0 && (vx = p->d.y) > 0) {
              p->coord.y += sv[2];
              p->d.y = -vx;
              hit = 1;
            } else if (sv[0] != 0) {
              p->coord.x += sv[0];
              p->d.x = -p->d.x;
              hit = 1;
            }
          }
        }
      }
      if (hit == 1) {
        p->work[2]++;
        {
          register u32 nv asm("r1");
          u32 fl2;
          fl2 = p->flags;
          nv = (fl2 >> 4) ^ 1;
          nv &= 1;
          if (nv != 0) {
            u32 res = 0x10;
            res |= fl2;
            p->flags = res;
          } else {
            u32 res2 = 0xEF;
            res2 &= fl2;
            p->flags = res2;
          }
          *((u8*)p + 0x4c) = nv;
          {
            register u8* oa asm("r3");
            u32 sh4;
            s32 ov;
            s32 m11;
            oa = (u8*)p + 0x4a;
            sh4 = nv << 4;
            ov = *oa;
            m11 = -0x11;
            m11 &= ov;
            m11 |= sh4;
            *oa = m11;
          }
        }
      }
      if (p->work[2] > 1) {
        u8* t;
        u32 z;
        p->unk_coord.x = 0xFF;
        t = (u8*)p + 0x8c;
        z = 0;
        *(u32*)t = z;
        asm("" : "+r"(t));
        t += 4;
        *(u32*)t = z;
        asm("" : "+r"(t));
        t += 4;
        *t = z;
        p->flags &= 0xFB;
        p->mode[2]++;
      }
      {
        register u32 w3n asm("r1");
        u32 msk;
        w3n = p->work[3] + 1;
        p->work[3] = w3n;
        w3n <<= 24;
        msk = 0xE0 << 19;
        msk &= w3n;
        if (msk == 0) {
          FUN_080bde9c((struct Entity*)p, &p->coord, b7, (p->flags >> 4) & 1);
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
    case 2:
      UpdateEntityAnim((struct Entity*)p);
      {
        s32 v0 = p->unk_coord.x;
        u8* t = (u8*)p + 0x50;
        *(u16*)t = v0;
        {
          s32 v1 = *(volatile s32*)&p->unk_coord.x;
          t += 2;
          asm("" : "+r"(t));
          *(u16*)t = v1;
        }
      }
      {
        s32 v = p->unk_coord.x;
        if (v > 0) {
          p->unk_coord.x = v - 0x20;
        }
      }
      if (p->unk_coord.x <= 0x20) {
        SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
      }
      break;
  }
}

static void FUN_080a1f10(HellbatProjectile* p) {
  p->mode[1] = 1;
  p->mode[2] = 0;
}

INCASM("asm/projectile/hellbat_d.inc");

static void FUN_080a2020(HellbatProjectile* p) {
  p->mode[1] = 1;
  p->mode[2] = 0;
}

INCASM("asm/projectile/hellbat_e.inc");

static void FUN_080a22ec(HellbatProjectile* p) {
  p->mode[1] = 1;
  p->mode[2] = 0;
}

INCASM("asm/projectile/hellbat_f.inc");

static void FUN_080a176c(HellbatProjectile* p);
void FUN_080a1778(HellbatProjectile* p);

static const HellbatProjectileFunc sUpdates1[2] = {
    FUN_080a176c,
    FUN_080a1778,
};

static void FUN_080a1a10(HellbatProjectile* p);
void FUN_080a1a1c(HellbatProjectile* p);

static const HellbatProjectileFunc sUpdates2[2] = {
    FUN_080a1a10,
    FUN_080a1a1c,
};

static void FUN_080a1f10(HellbatProjectile* p);
void FUN_080a1f1c(HellbatProjectile* p);

static const HellbatProjectileFunc sUpdates3[2] = {
    FUN_080a1f10,
    FUN_080a1f1c,
};

static void FUN_080a2020(HellbatProjectile* p);
void FUN_080a202c(HellbatProjectile* p);

static const HellbatProjectileFunc sUpdates4[2] = {
    FUN_080a2020,
    FUN_080a202c,
};

static void FUN_080a22ec(HellbatProjectile* p);
void FUN_080a22f8(HellbatProjectile* p);

static const HellbatProjectileFunc sUpdates5[2] = {
    FUN_080a22ec,
    FUN_080a22f8,
};

// clang-format off
static const HellbatProjectileFunc* const sUpdates[5] = {
    sUpdates1,
    sUpdates2,
    sUpdates3,
    sUpdates4,
    sUpdates5,
};
// clang-format on

static const struct Collision sCollisions[9] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 1,
      range : {PIXEL(0), -PIXEL(2), PIXEL(20), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(2), PIXEL(20), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      element : ELEMENT_THUNDER,
      remaining : 0,
      layer : 0x00000002,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 5,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(11), PIXEL(30)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 5,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(10)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(10), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(10)},
    },
};  // 0x0836B264
