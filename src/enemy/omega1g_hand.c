#include "boss/omega1.h"
#include "collision.h"
#include "enemy.h"
#include "global.h"

void OmegaGoldHand_Init(struct Enemy* p);
void OmegaGoldHand_Update(struct Enemy* p);
void OmegaGoldHand_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gOmegaGoldHandRoutine = {
    [ENTITY_INIT] =      (void*)OmegaGoldHand_Init,
    [ENTITY_UPDATE] =    (void*)OmegaGoldHand_Update,
    [ENTITY_DIE] =       (void*)OmegaGoldHand_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* FUN_08082b58(Coords32* c, bool8 isLeftHand, Omega1* omega) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_OMEGA1G_HAND);
    p->coord = *c;
    p->work[0] = isLeftHand, p->work[1] = 0;
    p->unk_28 = (void*)omega;
  }
  return p;
}

struct Entity* FUN_08082bbc(struct Entity* q, u8 kind) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_OMEGA1G_HAND);
    p->work[0] = kind, p->work[1] = 1;
    p->unk_28 = q;
  }
  return p;
}

INCASM("asm/enemy/omega1g_hand.inc");

void FUN_08083284(struct Enemy* p);
void FUN_080833c8(struct Enemy* p);
void FUN_0808340c(struct Enemy* p);
void FUN_080835b4(struct Enemy* p);
void FUN_08083640(struct Enemy* p);
void FUN_08083e14(struct Enemy* p);

// clang-format off
static const EnemyFunc PTR_ARRAY_08368188[6] = {
    FUN_08083284,
    FUN_080833c8,
    FUN_0808340c,
    FUN_080835b4,
    FUN_08083640,
    FUN_08083e14,
};
// clang-format on

void FUN_08083eb0(struct Enemy* p);
void FUN_08083ff0(struct Enemy* p);
void FUN_080846fc(struct Enemy* p);

// clang-format off
static const EnemyFunc PTR_ARRAY_083681a0[6] = {
    FUN_080846fc,
    FUN_080846fc,
    FUN_08083eb0,
    FUN_080846fc,
    FUN_08083ff0,
    FUN_080846fc,
};
// clang-format on

void FUN_08083288(struct Enemy* p);
void FUN_080833cc(struct Enemy* p);
void FUN_08083428(struct Enemy* p);
void FUN_080835b8(struct Enemy* p);
void FUN_08083644(struct Enemy* p);
void FUN_08083e18(struct Enemy* p);

// clang-format off
static const EnemyFunc PTR_ARRAY_083681b8[6] = {
    FUN_08083288,
    FUN_080833cc,
    FUN_08083428,
    FUN_080835b8,
    FUN_08083644,
    FUN_08083e18,
};
// clang-format on

void FUN_08083328(struct Enemy* p);
void FUN_080833ec(struct Enemy* p);
void FUN_080834fc(struct Enemy* p);
void FUN_080835fc(struct Enemy* p);
void FUN_08083a04(struct Enemy* p);
void FUN_08083e68(struct Enemy* p);

// clang-format off
static const EnemyFunc PTR_ARRAY_083681d0[6] = {
    FUN_08083328,
    FUN_080833ec,
    FUN_080834fc,
    FUN_080835fc,
    FUN_08083a04,
    FUN_08083e68,
};
// clang-format on

void FUN_08083ec4(struct Enemy* p);
void FUN_08083ff4(struct Enemy* p);
void FUN_08084700(struct Enemy* p);

// clang-format off
static const EnemyFunc PTR_ARRAY_083681e8[6] = {
    FUN_08084700,
    FUN_08084700,
    FUN_08083ec4,
    FUN_08084700,
    FUN_08083ff4,
    FUN_08084700,
};
// clang-format on

void FUN_08083f4c(struct Enemy* p);
void FUN_08084348(struct Enemy* p);

// clang-format off
static const EnemyFunc PTR_ARRAY_08368200[6] = {
    FUN_08084700,
    FUN_08084700,
    FUN_08083f4c,
    FUN_08084700,
    FUN_08084348,
    FUN_08084700,
};
// clang-format on

void FUN_08082e38(struct Enemy* p);
void FUN_08083258(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_08368218[2] = {
    FUN_08082e38,
    FUN_08083258,
};

// --------------------------------------------

static const struct Collision sCollisions[7] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(1), PIXEL(24), PIXEL(43)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(1), PIXEL(22), PIXEL(41)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(1), PIXEL(24), PIXEL(43)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(1), PIXEL(22), PIXEL(41)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(1), PIXEL(24), PIXEL(43)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(4), PIXEL(2), PIXEL(30), PIXEL(40)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(4), PIXEL(2), PIXEL(32), PIXEL(42)},
    },
};
