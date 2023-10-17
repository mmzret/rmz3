#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/deathlock.inc");

void Deathlock_Init(struct Enemy* p);
void Deathlock_Update(struct Enemy* p);
void Deathlock_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gDeathlockRoutine = {
    [ENTITY_INIT] =      Deathlock_Init,
    [ENTITY_UPDATE] =    Deathlock_Update,
    [ENTITY_DIE] =       Deathlock_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_0808d6f8(struct Enemy* p);
void FUN_0808d76c(struct Enemy* p);
void FUN_0808d6f4(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[8] = {
    FUN_0808d6f8,
    FUN_0808d76c,
    FUN_0808d76c,
    FUN_0808d6f4,
    FUN_0808d76c,
    FUN_0808d6f4,
    FUN_0808d6f4,
    FUN_0808d6f4,
};
// clang-format on

void FUN_0808d78c(struct Enemy* p);
void FUN_0808d898(struct Enemy* p);
void FUN_0808da24(struct Enemy* p);
void FUN_0808db64(struct Enemy* p);
void FUN_0808dd7c(struct Enemy* p);
void FUN_0808deb8(struct Enemy* p);
void FUN_0808e01c(struct Enemy* p);
void FUN_0808e18c(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[8] = {
    FUN_0808d78c,
    FUN_0808d898,
    FUN_0808da24,
    FUN_0808db64,
    FUN_0808dd7c,
    FUN_0808deb8,
    FUN_0808e01c,
    FUN_0808e18c,
};
// clang-format on

// --------------------------------------------

void FUN_0808e228(struct Enemy* p);
void maybeKillDeathlock(struct Enemy* p);
void FUN_0808e358(struct Enemy* p);

static const EnemyFunc sDeads[4] = {
    FUN_0808e228,
    maybeKillDeathlock,
    FUN_0808e358,
    FUN_0808e01c,
};

// --------------------------------------------

static const struct Collision sCollisions[15] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : 8,
      remaining : 1,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(1), -PIXEL(14), PIXEL(34), PIXEL(33)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(1), -PIXEL(14), PIXEL(34), PIXEL(33)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(9), -PIXEL(24), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(1), -PIXEL(8), PIXEL(34), PIXEL(19)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : 8,
      remaining : 1,
      range : {PIXEL(9), -PIXEL(24), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(1), -PIXEL(8), PIXEL(34), PIXEL(19)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(1), -PIXEL(8), PIXEL(34), PIXEL(19)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(1), -PIXEL(8), PIXEL(34), PIXEL(19)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(4), -PIXEL(8), PIXEL(34), PIXEL(19)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(4), -PIXEL(8), PIXEL(34), PIXEL(19)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(8), -PIXEL(8), PIXEL(19), PIXEL(19)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(8), -PIXEL(8), PIXEL(19), PIXEL(19)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(1), -PIXEL(14), PIXEL(34), PIXEL(33)},
    },
};

// clang-format off
static const motion_t sMotions1[6] = {
    MOTION(SM116_DEATHLOCK, 1),
    MOTION(SM116_DEATHLOCK, 4),
    MOTION(SM116_DEATHLOCK, 5),
    MOTION(SM116_DEATHLOCK, 6),
    MOTION(SM116_DEATHLOCK, 7),
    MOTION(SM116_DEATHLOCK, 8),
};
// clang-format on

static const u8 sCollisionIdxs1[6] = {2, 4, 8, 10, 10, 12};

static const struct Coord sElementCoord = {PIXEL(0), -PIXEL(12)};

static const u8 sCollisionIdxs2[6] = {3, 6, 9, 11, 11, 13};

static const motion_t sMotions2[4] = {
    MOTION(SM116_DEATHLOCK, 17),
    MOTION(SM116_DEATHLOCK, 18),
    MOTION(SM116_DEATHLOCK, 19),
    MOTION(SM116_DEATHLOCK, 14),
};
