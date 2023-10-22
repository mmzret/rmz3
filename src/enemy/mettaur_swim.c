#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/mettaur_swim.inc");

void MettaurSwim_Init(struct Enemy* p);
void MettaurSwim_Update(struct Enemy* p);
void MettaurSwim_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gMettaurSwimRoutine = {
    [ENTITY_INIT] =      MettaurSwim_Init,
    [ENTITY_UPDATE] =    MettaurSwim_Update,
    [ENTITY_DIE] =       MettaurSwim_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

static const struct Collision sCollisions[8] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0,
      hitzone : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(6), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(6), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(8), PIXEL(16), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(8), PIXEL(16), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(24), PIXEL(16), PIXEL(6)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(24), PIXEL(16), PIXEL(6)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 2,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0,
      hitzone : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(6), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(6), PIXEL(16), PIXEL(16)},
    },
};

// --------------------------------------------

void FUN_0808926c(struct Enemy* p);
void FUN_080892a4(struct Enemy* p);
void nop_08089268(struct Enemy* p);

// clang-format off
static const EnemyFunc sInitializers[13] = {
    FUN_0808926c,
    FUN_0808926c,
    FUN_0808926c,
    FUN_0808926c,
    FUN_0808926c,
    FUN_080892a4,
    FUN_080892a4,
    nop_08089268,
    FUN_080892a4,
    nop_08089268,
    nop_08089268,
    nop_08089268,
    nop_08089268,
};
// clang-format on

// --------------------------------------------

void FUN_080892c4(struct Enemy* p);
void FUN_08089364(struct Enemy* p);
void FUN_080894a4(struct Enemy* p);
void FUN_0808959c(struct Enemy* p);
void FUN_08089694(struct Enemy* p);
void FUN_08089790(struct Enemy* p);
void FUN_080898bc(struct Enemy* p);
void FUN_08089a00(struct Enemy* p);
void FUN_08089a34(struct Enemy* p);
void FUN_08089b48(struct Enemy* p);
void FUN_08089c94(struct Enemy* p);
void FUN_08089e60(struct Enemy* p);
void FUN_08089f60(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates[13] = {
    FUN_080892c4,
    FUN_08089364,
    FUN_080894a4,
    FUN_0808959c,
    FUN_08089694,
    FUN_08089790,
    FUN_080898bc,
    FUN_08089a00,
    FUN_08089a34,
    FUN_08089b48,
    FUN_08089c94,
    FUN_08089e60,
    FUN_08089f60,
};
// clang-format on

// --------------------------------------------

void FUN_08089eb0(struct Enemy* p);
void FUN_08089f60(struct Enemy* p);
void FUN_0808a068(struct Enemy* p);

static const EnemyFunc sDeads[3] = {
    FUN_08089eb0,
    FUN_08089f60,
    FUN_0808a068,
};

// --------------------------------------------

static const u8 sInitModes[6] = {0, 6, 9, 0, 7, 0};

static const motion_t sMotions[4] = {
    MOTION(SM221_METTAUR, 0),
    MOTION(SM000_BATTLE_EFFECT, 6),
    MOTION(SM000_BATTLE_EFFECT, 9),
    MOTION(SM221_METTAUR, 0),
};
