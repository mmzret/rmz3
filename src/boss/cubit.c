#include "boss.h"
#include "collision.h"
#include "global.h"
#include "motion.h"
#include "physics.h"
#include "script.h"
#include "sound.h"
#include "stagerun.h"

static const struct Collision sCollisions[];

void Cubit_Init(struct Boss* p);
void Cubit_Update(struct Boss* p);
void Cubit_Die(struct Boss* p);

// clang-format off
const BossRoutine gCubitRoutine = {
    [ENTITY_INIT] =      (void*)Cubit_Init,
    [ENTITY_UPDATE] =    (void*)Cubit_Update,
    [ENTITY_DIE] =       (void*)Cubit_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteBoss,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Boss* CreateCubit(Coords32* c, u8 n) {
  struct Boss* p = (struct Boss*)AllocEntityLast(gBossHeaderPtr);
  if (p != NULL) {
    INIT_BOSS_ROUTINE(p, BOSS_CUBIT);
    (p->s).coord = *c;
    (p->s).work[0] = n;
  }
  return p;
}

INCASM("asm/boss/cubit_a.inc");

static const BossFunc sUpdates1[12];
static const BossFunc sUpdates2[12];
static const BossFunc sDeads[2];
void cubit_080544c0(struct Boss* p);

void Cubit_Update(struct Boss* p) {
  if (!((p->body).status & BODY_STATUS_DEAD)) {
    if (*(s16*)((u8*)p + 0xa4) != 0) {
      goto alive;
    }
  }
  if (gStageRun.missionStatus & MISSION_PLAYER_DEAD) {
    goto alive;
  }
  SET_BOSS_ROUTINE(p, ENTITY_DIE);
  PlaySound(0xd2);
  if ((p->body).status & BODY_STATUS_SLASHED) {
    (p->s).mode[3] = 1;
  } else {
    (p->s).mode[3] = 0;
  }
  Cubit_Die(p);
  return;

alive:
  (sUpdates1[(p->s).mode[1]])(p);
  (sUpdates2[(p->s).mode[1]])(p);
  cubit_080544c0(p);
}

void Cubit_Die(struct Boss* p) { (sDeads[(p->s).mode[1]])(p); }

INCASM("asm/boss/cubit_b.inc");

bool8 FUN_08052b48(struct Boss* p) { return TRUE; }

void cubitMode0(struct Boss* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).flags |= 1;
      SetSpriteAnimation(p, MOTION(0xb0, 2));
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(p);
      if ((p->s).scriptEntity->flags & 1) {
        (p->s).mode[1] = 1, (p->s).mode[2] = 0;
      }
      break;
  }
}

bool8 FUN_08052b98(struct Boss* p) { return TRUE; }

INCASM("asm/boss/cubit_c.inc");

bool8 FUN_08052c30(struct Boss* p) { return TRUE; }

void cubitMode2(struct Boss* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SetSpriteAnimation(p, MOTION(0xb0, 2));
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      if (!(gStageRun.vm.active & VM_ACTIVE)) {
        (p->s).mode[1] = 3, (p->s).mode[2] = 0;
      }
      UpdateSpriteAnimation(p);
      break;
  }
}

bool8 FUN_08052c78(struct Boss* p) { return TRUE; }

INCASM("asm/boss/cubit_d.inc");

bool8 FUN_08052f08(struct Boss* p) { return TRUE; }

INCASM("asm/boss/cubit_e.inc");

bool8 FUN_080533bc(struct Boss* p) { return TRUE; }

void cubitMode5(struct Boss* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).d.y = 0;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1: {
      s32 push;
      (p->s).d.y += 0x40;
      (p->s).coord.x += (p->s).d.x;
      (p->s).coord.y += (p->s).d.y;
      UpdateSpriteAnimation(p);
      push = PushoutToUp1((p->s).coord.x, (p->s).coord.y);
      if (push != 0) {
        (p->s).coord.y += push;
        (p->s).mode[2]++;
      }
      break;
    }
    case 2:
      SetSpriteAnimation(p, 0xb014);
      SetDDP(&p->body, &sCollisions[1]);
      *(u8*)((u8*)p + 0xc8) = 0;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 3:
      UpdateSpriteAnimation(p);
      if ((p->s).motion.state == 3) {
        (p->s).mode[1] = 3, (p->s).mode[2] = 0;
      }
      break;
  }
}

bool8 nop_08053460(struct Boss* p) { return TRUE; }

INCASM("asm/boss/cubit_f.inc");

bool8 FUN_08053724(struct Boss* p) { return TRUE; }

INCASM("asm/boss/cubit_g.inc");

bool8 FUN_08053a08(struct Boss* p) { return TRUE; }

INCASM("asm/boss/cubit_h.inc");

bool8 FUN_08053d08(struct Boss* p) { return TRUE; }

INCASM("asm/boss/cubit_i.inc");

bool8 FUN_080542c8(struct Boss* p) { return TRUE; }

void cubitMode10(struct Boss* p) {
  switch ((p->s).mode[2]) {
    case 0:
      InitNonAffineMotion(&p->s);
      ResetDynamicMotion(&p->s);
      (p->s).angle = 0;
      (p->s).spr.mag.x = 0x100;
      (p->s).spr.mag.y = 0x100;
      PlaySound(0xd1);
      SetSpriteAnimation(p, MOTION(0xb0, 0x1e));
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(p);
  }
  if (isKilled(*(struct Entity**)((u8*)p + 0xc0))) {
    *(struct Entity**)((u8*)p + 0xc0) = NULL;
    (p->s).mode[1] = 3;
    (p->s).mode[2] = 0;
    (p->s).mode[3] = 0xff;
  }
}

bool8 FUN_0805433c(struct Boss* p) { return TRUE; }

INCASM("asm/boss/cubit_j.inc");

bool8 cubit_08054674(struct Boss* p) {
  if (*(u8*)((u8*)p + 0xc8) != 0) {
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

void cubitMode1(struct Boss* p);
void cubitNeutral(struct Boss* p);
void cubitMode4(struct Boss* p);
void cubitMode6(struct Boss* p);
void cubitMode7(struct Boss* p);
void cubitMode8(struct Boss* p);
void cubitEX(struct Boss* p);
void cubitKnockBackDamage(struct Boss* p);

// clang-format off
static const BossFunc sUpdates2[12] = {
    cubitMode0,
    cubitMode1,
    cubitMode2,
    cubitNeutral,
    cubitMode4,
    cubitMode5,
    cubitMode6,
    cubitMode7,
    cubitMode8,
    cubitEX,
    cubitMode10,
    cubitKnockBackDamage,
};
// clang-format on

// --------------------------------------------

void cubitDeath0(struct Boss* p);
void cubitDeath1(struct Boss* p);

static const BossFunc sDeads[2] = {
    cubitDeath0,
    cubitDeath1,
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
