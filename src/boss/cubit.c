#include "boss.h"
#include "collision.h"
#include "global.h"
#include "motion.h"
#include "physics.h"
#include "script.h"
#include "sound.h"
#include "stagerun.h"
#include "zero.h"

extern const struct Coord Coord_ARRAY_080fef88[5];
struct Projectile* FUN_080a5f00(struct Entity* e, u8 a1);

typedef struct {
  COLLISION_OBJECT_HDR;    // 0x00
  u8 unk_b4[12];           // 0xB4
  struct Entity* enti_c0;  // 0xC0
  u8 unk_c4[4];            // 0xC4
  u8 unk_c8;               // 0xC8
  u8 unk_c9[27];           // 0xC9
} Cubit;
static_assert(sizeof(Cubit) == sizeof(Boss));

static const struct Collision sCollisions[];

void Cubit_Init(Cubit* p);
void Cubit_Update(Cubit* p);
void Cubit_Die(Cubit* p);

// clang-format off
const BossRoutine gCubitRoutine = {
    [ENTITY_INIT] =      (void*)Cubit_Init,
    [ENTITY_UPDATE] =    (void*)Cubit_Update,
    [ENTITY_DIE] =       (void*)Cubit_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteBoss,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

Cubit* Unused_CreateCubit(Coords32* c, u8 n) {
  Cubit* p = (Cubit*)AllocEntityLast(gBossHeaderPtr);
  if (p != NULL) {
    INIT_BOSS_ROUTINE(p, BOSS_CUBIT);
    p->coord = *c;
    p->work[0] = n;
  }
  return p;
}

INCASM("asm/boss/cubit_a.inc");

static const BossFunc sUpdates1[12];
static const BossFunc sUpdates2[12];
static const BossFunc sDeads[2];
void cubit_080544c0(Cubit* p);

void Cubit_Update(Cubit* p) {
  if (!((p->body).status & BODY_STATUS_DEAD)) {
    if ((p->body).hp != 0) {
      goto alive;
    }
  }
  if (gStageRun.missionStatus & MISSION_PLAYER_DEAD) {
    goto alive;
  }
  SET_BOSS_ROUTINE(p, ENTITY_DIE);
  PlaySound(SE_CUBIT_DEATH);
  if ((p->body).status & BODY_STATUS_SLASHED) {
    p->mode[3] = 1;
  } else {
    p->mode[3] = 0;
  }
  Cubit_Die(p);
  return;

alive:
  (sUpdates1[p->mode[1]])((void*)p);
  (sUpdates2[p->mode[1]])((void*)p);
  cubit_080544c0(p);
}

void Cubit_Die(Cubit* p) { (sDeads[p->mode[1]])((void*)p); }

INCASM("asm/boss/cubit_b.inc");

bool8 FUN_08052b48(Cubit* p) { return TRUE; }

void cubitMode0(Cubit* p) {
  switch (p->mode[2]) {
    case 0: {
      p->flags |= DISPLAY;
      SetSpriteAnimation(p, MOTION(DM176_CUBIT, 2));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      if ((p->scriptEntity)->flags & (1 << 0)) {
        p->mode[1] = 1, p->mode[2] = 0;
      }
      break;
    }
  }
}

bool8 FUN_08052b98(Cubit* p) { return TRUE; }

INCASM("asm/boss/cubit_c.inc");

bool8 FUN_08052c30(Cubit* p) { return TRUE; }

void cubitMode2(Cubit* p) {
  switch (p->mode[2]) {
    case 0: {
      SetSpriteAnimation(p, MOTION(DM176_CUBIT, 2));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      if (!(gStageRun.vm.active & VM_ACTIVE)) {
        p->mode[1] = 3, p->mode[2] = 0;
      }
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

bool8 FUN_08052c78(Cubit* p) { return TRUE; }

INCASM("asm/boss/cubit_d.inc");

bool8 FUN_08052f08(Cubit* p) { return TRUE; }

INCASM("asm/boss/cubit_e.inc");

bool8 FUN_080533bc(Cubit* p) { return TRUE; }

void cubitMode5(Cubit* p) {
  switch (p->mode[2]) {
    case 0:
      (p->d).y = 0;
      p->mode[2]++;
      FALLTHROUGH;
    case 1: {
      s32 push;
      (p->d).y += PIXEL(1) / 4;
      (p->coord).x += (p->d).x;
      (p->coord).y += (p->d).y;
      UpdateSpriteAnimation(p);
      push = PushoutToUp1((p->coord).x, (p->coord).y);
      if (push != 0) {
        (p->coord).y += push;
        p->mode[2]++;
      }
      break;
    }
    case 2:
      SetSpriteAnimation(p, MOTION(DM176_CUBIT, 20));
      SetDDP(&p->body, &sCollisions[1]);
      p->unk_c8 = 0;
      p->mode[2]++;
      FALLTHROUGH;
    case 3:
      UpdateSpriteAnimation(p);
      if (IsSpriteAnimEnd(p)) {
        p->mode[1] = 3, p->mode[2] = 0;
      }
      break;
  }
}

bool8 nop_08053460(Cubit* p) { return TRUE; }

void cubitMode6(Cubit* p) {
  switch (p->mode[2]) {
    case 0:
      if (*((u8*)p + 0xc8) != 0) {
        SetSpriteAnimation(p, MOTION(0xB0, 0x10));
        SetDDP(&p->body, &sCollisions[1]);
        asm volatile("@m0a");
      } else {
        SetSpriteAnimation(p, MOTION(0xB0, 0x0D));
        SetDDP(&p->body, &sCollisions[1]);
      }
      p->mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
      goto inc;
    case 2:
      if (*((u8*)p + 0xc8) != 0) {
        SetSpriteAnimation(p, MOTION(0xB0, 0x11));
      } else {
        SetSpriteAnimation(p, MOTION(0xB0, 0x0E));
      }
      SetDDP(&p->body, &sCollisions[0]);
      p->work[2] = 0x41;
      p->work[3] = RANDOM(RNG_0202f388) % 5;
      *(struct Projectile**)((u8*)p + 0xcc) = FUN_080a5f00((struct Entity*)p, p->work[3]);
      PlaySound(0xCD);
      p->mode[2]++;
      FALLTHROUGH;
    case 3: {
      s32 ci;
      UpdateEntityAnim((struct Entity*)p);
      ci = p->motion.cmdIdx;
      if (ci == 1 || ci == 3 || ci == 5 || ci == 7 || ci == 8) {
        if (p->motion.duration == 1) {
          PlaySound(0xCB);
        }
      }
      goto tick;
    }
    case 4: {
      u32 z;
      p->flags &= ~DISPLAY;
      z = 0;
      SetDDP(&p->body, &sCollisions[0]);
      p->coord.x = *(s32*)((u8*)p + 0xbc) + Coord_ARRAY_080fef88[p->work[3]].x;
      p->coord.y = *(s32*)((u8*)p + 0xb8) + Coord_ARRAY_080fef88[p->work[3]].y;
      p->work[3] = z;
      p->work[2] = 0x14;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 5: {
      struct Projectile** q;
      if ((*(struct Projectile**)((u8*)p + 0xcc))->mode[2] > 6 && p->work[3] == 0) {
        p->work[3] = 1;
        SetDDP(&p->body, &sCollisions[0]);
      }
      q = (struct Projectile**)((u8*)p + 0xcc);
      if ((*q)->mode[2] <= 9) {
        break;
      }
      goto inc;
    }
    case 6: {
      register u32 fl asm("r0");
      register u32 one asm("r3");
      register u32 v asm("r2");
      {
        register u32 z2 asm("r6");
        *(struct Projectile**)((u8*)p + 0xcc) = NULL;
        fl = p->flags;
        one = 1;
        z2 = 0;
        asm volatile("" ::"l"(z2));
      }
      v = one;
      asm volatile("" : "+l"(v));
      v |= fl;
      p->flags = v;
      if ((pZero2->s).coord.x > p->coord.x) {
        if ((v & 0x10) == 0) {
        register u32 vv asm("r0");
        register u32 v2 asm("r1");
        u8* xp;
        register u8* oa asm("r4");
        s32 m;
        vv = (v >> 4) ^ one;
        asm("and %0, %0, %1" : "+l"(vv) : "l"(one));
        xp = (u8*)p + 0x4c;
        *xp = vv;
        v2 = (p->flags >> 4) ^ one;
        asm("and %0, %0, %1" : "+l"(v2) : "l"(one));
        oa = (u8*)p + 0x4a;
        {
          s32 sh = v2 << 4;
          s32 ov = *oa;
          m = -0x11;
          m &= ov;
          m |= sh;
          *oa = m;
        }
        if (v2 != 0) {
          p->flags |= 0x10;
        } else {
          p->flags &= 0xEF;
        }
        }
      } else {
        if ((v & 0x10) != 0) {
        register u32 vv asm("r0");
        register u32 v2 asm("r1");
        u8* xp;
        register u8* oa asm("r4");
        s32 m;
        vv = (v >> 4) ^ one;
        asm("and %0, %0, %1" : "+l"(vv) : "l"(one));
        xp = (u8*)p + 0x4c;
        *xp = vv;
        v2 = (p->flags >> 4) ^ one;
        asm("and %0, %0, %1" : "+l"(v2) : "l"(one));
        oa = (u8*)p + 0x4a;
        {
          s32 sh = v2 << 4;
          s32 ov = *oa;
          m = -0x11;
          m &= ov;
          m |= sh;
          *oa = m;
        }
        if (v2 != 0) {
          p->flags |= 0x10;
        } else {
          p->flags &= 0xEF;
        }
        }
      }
      *((u8*)p + 0xc8) = 1;
      SetSpriteAnimation(p, MOTION(0xB0, 0x11));
      p->work[2] = 0x34;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 7:
      UpdateEntityAnim((struct Entity*)p);
    tick : {
      u32 w = p->work[2];
      if (w != 0) {
        w--;
        p->work[2] = w;
        if ((w << 24) != 0) {
          break;
        }
      }
    }
    inc:
      p->mode[2]++;
      break;
    case 8: {
      u8 z3 = 0;
      p->mode[1] = 3;
      p->mode[2] = z3;
      break;
    }
  }
}

bool8 FUN_08053724(Cubit* p) { return TRUE; }

INCASM("asm/boss/cubit_g.inc");

bool8 FUN_08053a08(Cubit* p) { return TRUE; }

INCASM("asm/boss/cubit_h.inc");

bool8 FUN_08053d08(Cubit* p) { return TRUE; }

INCASM("asm/boss/cubit_i.inc");

bool8 FUN_080542c8(Cubit* p) { return TRUE; }

void cubitMode10(Cubit* p) {
  switch (p->mode[2]) {
    case 0: {
      EnableSpriteAnimation_Normal(p);
      SetSpriteTableDynamic(p);
      p->angle = 0;
      (p->spr).mag.x = 0x100;
      (p->spr).mag.y = 0x100;
      PlaySound(0xd1);
      SetSpriteAnimation(p, MOTION(DM176_CUBIT, 30));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      break;
    }
  }
  if (isKilled(p->enti_c0)) {
    p->enti_c0 = NULL;
    p->mode[1] = 3, p->mode[2] = 0, p->mode[3] = 0xFF;
  }
}

bool8 FUN_0805433c(Cubit* p) { return TRUE; }

INCASM("asm/boss/cubit_j.inc");

bool8 cubit_08054674(Cubit* p) {
  if (p->unk_c8 != 0) {
    return TRUE;
  }
  return FALSE;
}

INCASM("asm/boss/cubit_k.inc");

// --------------------------------------------

// clang-format off
static const BossFunc sUpdates1[12] = {
    (BossFunc)FUN_08052b48,
    (BossFunc)FUN_08052b98,
    (BossFunc)FUN_08052c30,
    (BossFunc)FUN_08052c78,
    (BossFunc)FUN_08052f08,
    (BossFunc)FUN_080533bc,
    (BossFunc)nop_08053460,
    (BossFunc)FUN_08053724,
    (BossFunc)FUN_08053a08,
    (BossFunc)FUN_08053d08,
    (BossFunc)FUN_080542c8,
    (BossFunc)FUN_0805433c,
};
// clang-format on

void cubitMode1(Cubit* p);
void cubitNeutral(Cubit* p);
void cubitMode4(Cubit* p);
void cubitMode6(Cubit* p);
void cubitMode7(Cubit* p);
void cubitMode8(Cubit* p);
void cubitEX(Cubit* p);
void cubitKnockBackDamage(Cubit* p);

// clang-format off
static const BossFunc sUpdates2[12] = {
    (void*)cubitMode0,
    (void*)cubitMode1,
    (void*)cubitMode2,
    (void*)cubitNeutral,
    (void*)cubitMode4,
    (void*)cubitMode5,
    (void*)cubitMode6,
    (void*)cubitMode7,
    (void*)cubitMode8,
    (void*)cubitEX,
    (void*)cubitMode10,
    (void*)cubitKnockBackDamage,
};
// clang-format on

// --------------------------------------------

void cubitDeath0(Cubit* p);
void cubitDeath1(Cubit* p);

static const BossFunc sDeads[2] = {
    (void*)cubitDeath0,
    (void*)cubitDeath1,
};

// --------------------------------------------

// 0x083639d8
static const struct Collision sCollisions[6] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 7,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(18), PIXEL(36), PIXEL(38)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(23), PIXEL(26), PIXEL(48)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 7,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(23), PIXEL(26), PIXEL(48)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(13), PIXEL(26), PIXEL(48)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 7,
      remaining : 0,
      range : {PIXEL(0), PIXEL(13), PIXEL(26), PIXEL(48)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(30), PIXEL(40), PIXEL(60)},
    },
};

static const Coords32 sElementCoords[2] = {
    {PIXEL(0), -PIXEL(24)},
    {PIXEL(0), PIXEL(10)},
};

static const Coords32 sExplosionCoords[4] = {
    {PIXEL(6), -PIXEL(33)},
    {PIXEL(6), -PIXEL(33)},
    {PIXEL(10), -PIXEL(33)},
    {PIXEL(10), -PIXEL(33)},
};

// 0x08363a98
static const u16 u16_ARRAY_ARRAY_08363a98[2][4] = {
    {4, 6, 7, 9},
    {5, 6, 8, 0},
};
