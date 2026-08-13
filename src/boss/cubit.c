#include "boss.h"
#include "collision.h"
#include "global.h"
#include "motion.h"
#include "physics.h"
#include "script.h"
#include "sound.h"
#include "stagerun.h"

struct Projectile* createFlameRain1(struct Entity* e, struct Coord* c, s32 n);
struct Projectile* createFlameRain2(struct Entity* e, struct Coord* c, s32 n);

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

INCASM("asm/boss/cubit_f.inc");

bool8 FUN_08053724(Cubit* p) { return TRUE; }

INCASM("asm/boss/cubit_g.inc");

bool8 FUN_08053a08(Cubit* p) { return TRUE; }

INCASM("asm/boss/cubit_h.inc");

bool8 FUN_08053d08(Cubit* p) { return TRUE; }

void cubitEX(Cubit* p0) {
  Cubit* p = p0;
  u32 mv;
  switch (p->mode[2]) {
    case 0: {
      s32 cx;
      s32 tl;
      {
        s32* t = (s32*)((u8*)p + 0xd8);
        tl = *t;
        cx = p->coord.x;
        if (cx > tl) {
          t += 2;
          asm("" : "+r"(t));
          if (cx > tl + (*t >> 1)) {
            tl = *(s32*)((u8*)p + 0xdc);
          }
        } else {
          if (cx < tl - (*(s32*)((u8*)p + 0xe0) >> 1)) {
            tl = *(s32*)((u8*)p + 0xd4);
          }
        }
      }
      {
        s32 cy = p->coord.y;
        s32 ty = cy + -0x3200;
        p->work[2] = 0x18;
        p->d.x = (tl - cx) / 0x18;
        {
          s32 k5 = 0xA2 << 7;
          asm("" : "+r"(k5));
          p->d.y = -((k5 - (ty - cy)) / 0x18);
        }
        p->work[2] = 0x17;
      }
      SetSpriteAnimation(p, MOTION(0xB0, 0x15));
      goto tail66;
    }
    case 2: {
      u32 z;
      {
        u8* c8 = (u8*)p + 0xc8;
        z = 0;
        *c8 = 1;
      }
      PlaySound(0xCA);
      SetSpriteAnimation(p, MOTION(0xB0, 0x16));
      SetDDP(&p->body, &sCollisions[1]);
      p->work[3] = z;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 3: {
      s32 vy = p->d.y + 0x48;
      p->d.y = vy;
      {
        s32 cx = p->coord.x;
        cx += p->d.x;
        p->coord.x = cx;
      }
      {
        s32 cy = p->coord.y;
        p->coord.y = cy + vy;
      }
      if (p->work[3] == 0) {
        if (vy > 0) {
          p->work[3] = 1;
          SetSpriteAnimation(p, MOTION(0xB0, 0x17));
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      {
        u32 w = p->work[2];
        if (w != 0) {
          w--;
          p->work[2] = w;
          if ((w << 24) != 0) {
            break;
          }
        }
      }
      p->mode[2]++;
      break;
    }
    case 4: {
      s32 tx = *(s32*)((u8*)p + 0xd8);
      s32 fy;
      u32 z;
      fy = FUN_08009f6c(p->coord.x, p->coord.y);
      z = 0;
      p->work[2] = 0x28;
      {
        s32 cx4 = p->coord.x;
        tx -= cx4;
        p->d.x = tx / 0x28;
      }
      {
        s32 k5 = 0xE1 << 8;
        asm("" : "+r"(k5));
        fy -= p->coord.y;
        p->d.y = -((k5 - fy) / 0x28);
      }
      p->work[2] = 0x27;
      EnableSpriteAnimation_Affine(p);
      SetSpriteTableDynamic(p);
      SetSpriteAnimation(p, MOTION(0xB0, 0x18));
      p->unk_coord.x = z;
      p->unk_coord.y = 0xA4;
      {
        register u8* t asm("r0");
        t = (u8*)p + 0x24;
        *t = z;
        t += 0x2c;
        {
          u16 k1 = 0x80 << 1;
          asm("" : "+r"(k1));
          *(u16*)t = k1;
          t += 2;
          asm("" : "+r"(t));
          *(u16*)t = k1;
        }
      }
      goto tail66;
    }
    case 6: {
      s32 vd = p->d.x;
      if (vd > 0) {
        *((u8*)p + 0x4c) = 1;
        {
          register u8* oa asm("r2");
          register u32 k asm("r1");
          oa = (u8*)p + 0x4a;
          {
            u32 ov = *oa;
            asm("" : "+r"(ov));
            k = 0x10;
            ov |= k;
            *oa = ov;
          }
          k |= p->flags;
          p->flags = k;
        }
      } else if (vd < 0) {
        u8* a4c = (u8*)p + 0x4c;
        u32 z = 0;
        *a4c = z;
        {
          u8* oa = (u8*)p + 0x4a;
          s32 ov = *oa;
          s32 m11 = z - 0x11;
          m11 &= ov;
          *oa = m11;
        }
        p->flags &= 0xEF;
      }
      PlaySound(0xCA);
      SetSpriteAnimation(p, MOTION(0xB0, 0x19));
      SetDDP(&p->body, (const struct Collision*)0x8363A20);
      p->coord.y += -0x2800;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 7: {
      {
        s32 vy = p->d.y + 0x48;
        p->d.y = vy;
        {
          s32 cx = p->coord.x;
          cx += p->d.x;
          p->coord.x = cx;
        }
        {
          s32 cy = p->coord.y;
          p->coord.y = cy + vy;
        }
      }
      {
        register u8* stp asm("r5");
        u32 st7 = p->motion.state;
        stp = (u8*)p + 0x70;
        if (st7 == 3) {
        if (((p->motionID << 8) | *stp) == MOTION(0xB0, 0x19)) {
          u32 xf = ((p->flags >> 4) ^ 1) & 1;
          u32 xf2;
          (p->spr).xflip = xf;
          xf2 = ((p->flags >> 4) ^ 1) & 1;
          {
            register u8* oa asm("r4");
            u32 sh4;
            s32 ov;
            s32 m11;
            oa = (u8*)p + 0x4a;
            sh4 = xf2 << 4;
            ov = *oa;
            m11 = -0x11;
            m11 &= ov;
            m11 |= sh4;
            *oa = m11;
          }
          if (xf2 != 0) {
            p->flags |= 0x10;
          } else {
            p->flags &= 0xEF;
          }
          {
            register s32 t asm("r1");
            register u32 m asm("r0");
            {
              register s32 v0 asm("r0");
              v0 = p->unk_coord.x;
              t = v0 >> 4;
            }
            m = 0xFF;
            t &= m;
            if (t <= 0x7F) {
              m = 0xFE;
            }
            p->unk_coord.x = m - t;
            p->unk_coord.x = *(volatile s32*)&p->unk_coord.x << 4;
          }
          SetSpriteAnimation(p, MOTION(0xB0, 0x1F));
        } else {
          u32 xf = ((p->flags >> 4) ^ 1) & 1;
          u32 xf2;
          (p->spr).xflip = xf;
          xf2 = ((p->flags >> 4) ^ 1) & 1;
          {
            register u8* oa asm("r4");
            u32 sh4;
            s32 ov;
            s32 m11;
            oa = (u8*)p + 0x4a;
            sh4 = xf2 << 4;
            ov = *oa;
            m11 = -0x11;
            m11 &= ov;
            m11 |= sh4;
            *oa = m11;
          }
          if (xf2 != 0) {
            p->flags |= 0x10;
          } else {
            p->flags &= 0xEF;
          }
          {
            register s32 t asm("r1");
            register u32 m asm("r0");
            {
              register s32 v0 asm("r0");
              v0 = p->unk_coord.x;
              t = v0 >> 4;
            }
            m = 0xFF;
            t &= m;
            if (t <= 0x7F) {
              m = 0xFE;
            }
            p->unk_coord.x = m - t;
            p->unk_coord.x = *(volatile s32*)&p->unk_coord.x << 4;
          }
          SetSpriteAnimation(p, MOTION(0xB0, 0x19));
        }
        }
      UpdateEntityAnim((struct Entity*)p);
      {
        register s32 v asm("r0");
        if (p->d.x > 0) {
          if (((p->motionID << 8) | *stp) == MOTION(0xB0, 0x19)) {
            {
              register s32 ax asm("r0");
              register s32 ay asm("r1");
              ax = p->unk_coord.x;
              ay = p->unk_coord.y;
              v = ax - ay;
            }
            asm("" : "+r"(v));
          } else {
            {
              register s32 ax asm("r0");
              register s32 ay asm("r1");
              ax = p->unk_coord.x;
              ay = p->unk_coord.y;
              v = ax + ay;
            }
          }
        } else {
          if (((p->motionID << 8) | *stp) == MOTION(0xB0, 0x19)) {
            {
              register s32 ax asm("r0");
              register s32 ay asm("r1");
              ax = p->unk_coord.x;
              ay = p->unk_coord.y;
              v = ax - ay;
            }
          } else {
            {
              register s32 ax asm("r0");
              register s32 ay asm("r1");
              ax = p->unk_coord.x;
              ay = p->unk_coord.y;
              v = ax + ay;
            }
          }
        }
        p->unk_coord.x = v;
      }
      }
      p->angle = *(volatile s32*)&p->unk_coord.x >> 4;
      {
        u32 w = p->work[2];
        if (w != 0) {
          w--;
          p->work[2] = w;
          if ((w << 24) != 0) {
            break;
          }
        }
      }
      p->mode[2]++;
      break;
    }
    case 8: {
      u32 z;
      {
        register u8* t asm("r0");
        t = (u8*)p + 0xc8;
        z = 0;
        *t = z;
        t -= 0xa4;
        asm("" : "+r"(t));
        *t = z;
        t += 0x2c;
        asm("" : "+r"(t));
        {
          u16 k1 = 0x80 << 1;
          *(u16*)t = k1;
          t += 2;
          asm("" : "+r"(t));
          *(u16*)t = k1;
        }
      }
      SetSpriteAnimation(p, MOTION(0xB0, 0x1A));
      SetDDP(&p->body, &sCollisions[1]);
      p->coord.y = FUN_08009f6c(p->coord.x, p->coord.y + -0x3C00);
      goto tail66;
    }
    case 10:
      EnableSpriteAnimation_Normal(p);
      SetSpriteTableDynamic(p);
      mv = MOTION(0xB0, 0x1B);
      goto setm;
    case 12:
      p->work[2] = 2;
      p->mode[2]++;
      FALLTHROUGH;
    case 13: {
      UpdateEntityAnim((struct Entity*)p);
      {
        u32 w = p->work[2];
        if (w != 0) {
          w--;
          p->work[2] = w;
          if ((w << 24) != 0) {
            break;
          }
        }
      }
      p->mode[2]++;
      break;
    }
    case 14:
      SetSpriteAnimation(p, MOTION(0xB0, 0x0A));
      SetDDP(&p->body, &sCollisions[1]);
      p->work[2] = 8;
      PlaySound(0xD0);
      p->mode[2]++;
      FALLTHROUGH;
    case 15:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
      {
        u32 w = p->work[2];
        if (w != 0) {
          w--;
          p->work[2] = w;
          if ((w << 24) != 0) {
            break;
          }
        }
      }
      p->mode[2]++;
      break;
    case 16: {
      struct Coord c;
      s32 i;
      SetSpriteAnimation(p, MOTION(0xB0, 0x0B));
      SetDDP(&p->body, &sCollisions[1]);
      c.x = p->coord.x;
      c.y = p->coord.y + -0x4200;
      for (i = 0; i <= 3; i++) {
        createFlameRain1((struct Entity*)p, &c, i);
      }
      goto tail66;
    }
    case 20:
      SetSpriteAnimation(p, MOTION(0xB0, 0x02));
      p->work[2] = 0x14;
      p->mode[2]++;
      FALLTHROUGH;
    case 21: {
      UpdateEntityAnim((struct Entity*)p);
      {
        u32 w = p->work[2];
        if (w != 0) {
          w--;
          p->work[2] = w;
          if ((w << 24) != 0) {
            break;
          }
        }
      }
      p->mode[2]++;
      break;
    }
    case 22: {
      struct Coord c2;
      s32 i;
      SetSpriteAnimation(p, MOTION(0xB0, 0x0B));
      SetDDP(&p->body, &sCollisions[1]);
      c2.x = p->coord.x;
      c2.y = p->coord.y + -0x4200;
      for (i = 0; i <= 1; i++) {
        createFlameRain2((struct Entity*)p, &c2, i);
      }
      goto tail66;
    }
    case 18:
    case 24:
      mv = MOTION(0xB0, 0x0C);
    setm:
      SetSpriteAnimation(p, mv);
      SetDDP(&p->body, &sCollisions[1]);
    tail66:
      p->mode[2]++;
      FALLTHROUGH;
    case 1:
    case 5:
    case 9:
    case 11:
    case 17:
    case 19:
    case 23:
    case 25:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
      p->mode[2]++;
      break;
    case 26:
      SetSpriteAnimation(p, MOTION(0xB0, 0x02));
      p->work[2] = 0x3C;
      p->mode[2]++;
      FALLTHROUGH;
    case 27: {
      UpdateEntityAnim((struct Entity*)p);
      {
        u32 w = p->work[2];
        if (w != 0) {
          w--;
          p->work[2] = w;
          if ((w << 24) != 0) {
            break;
          }
        }
      }
      {
        u32 z = 0;
        p->mode[1] = 3;
        p->mode[2] = z;
      }
      break;
    }
  }
}

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
