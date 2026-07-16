#include "boss.h"
#include "collision.h"
#include "global.h"

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
  struct Boss* p = AllocEntityLast(gBossHeaderPtr);
  if (p != NULL) {
    INIT_BOSS_ROUTINE(p, BOSS_CUBIT);
    p->coord = *c;
    p->work[0] = n;
  }
  return p;
}

INCASM("asm/boss/cubit.inc");

// --------------------------------------------

void FUN_08052b48(struct Boss* p);
void FUN_08052b98(struct Boss* p);
void FUN_08052c30(struct Boss* p);
void FUN_08052c78(struct Boss* p);
void FUN_08052f08(struct Boss* p);
void FUN_080533bc(struct Boss* p);
void nop_08053460(struct Boss* p);
void FUN_08053724(struct Boss* p);
void FUN_08053a08(struct Boss* p);
void FUN_08053d08(struct Boss* p);
void FUN_080542c8(struct Boss* p);
void FUN_0805433c(struct Boss* p);

// clang-format off
static const BossFunc sUpdates1[12] = {
    FUN_08052b48,
    FUN_08052b98,
    FUN_08052c30,
    FUN_08052c78,
    FUN_08052f08,
    FUN_080533bc,
    nop_08053460,
    FUN_08053724,
    FUN_08053a08,
    FUN_08053d08,
    FUN_080542c8,
    FUN_0805433c,
};
// clang-format on

void cubitMode0(struct Boss* p);
void cubitMode1(struct Boss* p);
void cubitMode2(struct Boss* p);
void cubitNeutral(struct Boss* p);
void cubitMode4(struct Boss* p);
void cubitMode5(struct Boss* p);
void cubitMode6(struct Boss* p);
void cubitMode7(struct Boss* p);
void cubitMode8(struct Boss* p);
void cubitEX(struct Boss* p);
void cubitMode10(struct Boss* p);
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
