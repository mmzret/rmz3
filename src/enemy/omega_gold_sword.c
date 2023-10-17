#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/omega_gold_sword.inc");

void OmegaGoldSword_Init(struct Enemy* p);
void OmegaGoldSword_Update(struct Enemy* p);
void OmegaGoldSword_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gOmegaGoldSwordRoutine = {
    [ENTITY_INIT] =      OmegaGoldSword_Init,
    [ENTITY_UPDATE] =    OmegaGoldSword_Update,
    [ENTITY_DIE] =       OmegaGoldSword_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

bool8 FUN_0808bb84(struct Enemy* p);
bool8 FUN_0808bbe4(struct Enemy* p);
bool8 FUN_0808bd00(struct Enemy* p);
bool8 FUN_0808bd8c(struct Enemy* p);
bool8 FUN_0808c330(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[5] = {
    (EnemyFunc)FUN_0808bb84,
    (EnemyFunc)FUN_0808bbe4,
    (EnemyFunc)FUN_0808bd00,
    (EnemyFunc)FUN_0808bd8c,
    (EnemyFunc)FUN_0808c330,
};
// clang-format on

void FUN_0808bb88(struct Enemy* p);
void FUN_0808bbe8(struct Enemy* p);
void FUN_0808bd1c(struct Enemy* p);
void FUN_0808bd90(struct Enemy* p);
void FUN_0808c334(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[5] = {
    FUN_0808bb88,
    FUN_0808bbe8,
    FUN_0808bd1c,
    FUN_0808bd90,
    FUN_0808c334,
};
// clang-format on

// --------------------------------------------

void FUN_0808b938(struct Enemy* p);
void FUN_0808bb58(struct Enemy* p);

static const EnemyFunc sDeads[2] = {
    FUN_0808b938,
    FUN_0808bb58,
};

// --------------------------------------------

static const struct Collision sCollisions[6] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(65), PIXEL(24), PIXEL(43)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 4,
      layer : 0x00000001,
      range : {PIXEL(5), -PIXEL(50), PIXEL(44), PIXEL(38)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(39), PIXEL(43), PIXEL(15)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(16), PIXEL(14), PIXEL(98)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 5,
      hardness : METAL,
      remaining : 1,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(39), PIXEL(39), PIXEL(15)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 5,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(16), PIXEL(10), PIXEL(98)},
    },
};

static const struct Coord Coord_ARRAY_08368e54[4] = {
    {PIXEL(0), -PIXEL(107)},
    {PIXEL(0), -PIXEL(76)},
    {PIXEL(0), -PIXEL(48)},
    {PIXEL(0), -PIXEL(24)},
};

// clang-format off
static const motion_t motion_t_ARRAY_08368e74[12] = {
    MOTION(SM101_OMEGA_WHITE_SWORD, 0x0C),
    MOTION(SM101_OMEGA_WHITE_SWORD, 0x0D),
    MOTION(SM101_OMEGA_WHITE_SWORD, 0x0D),
    MOTION(SM101_OMEGA_WHITE_SWORD, 0x08),
    MOTION(SM101_OMEGA_WHITE_SWORD, 0x09),
    MOTION(SM101_OMEGA_WHITE_SWORD, 0x0A),
    MOTION(SM101_OMEGA_WHITE_SWORD, 0x0B),
    MOTION(SM101_OMEGA_WHITE_SWORD, 0x08),
    MOTION(SM101_OMEGA_WHITE_SWORD, 0x09),
    MOTION(SM101_OMEGA_WHITE_SWORD, 0x0B),
    MOTION(SM101_OMEGA_WHITE_SWORD, 0x0A),
    MOTION(SM101_OMEGA_WHITE_SWORD, 0x08),
};
// clang-format on

static const struct Coord Coord_ARRAY_08368e8c[4] = {
    {-PIXEL(23), -PIXEL(110)},
    {-PIXEL(2), -PIXEL(91)},
    {PIXEL(16), -PIXEL(73)},
    {PIXEL(34), -PIXEL(53)},
};

// clang-format off
static const motion_t motion_t_ARRAY_08368eac[12] = {
    MOTION(SM101_OMEGA_WHITE_SWORD, 0x0C),
    MOTION(SM101_OMEGA_WHITE_SWORD, 0x0D),
    MOTION(SM101_OMEGA_WHITE_SWORD, 0x0D),
    MOTION(SM101_OMEGA_WHITE_SWORD, 0x08),
    MOTION(SM101_OMEGA_WHITE_SWORD, 0x09),
    MOTION(SM101_OMEGA_WHITE_SWORD, 0x0A),
    MOTION(SM101_OMEGA_WHITE_SWORD, 0x0B),
    MOTION(SM101_OMEGA_WHITE_SWORD, 0x08),
    MOTION(SM101_OMEGA_WHITE_SWORD, 0x09),
    MOTION(SM101_OMEGA_WHITE_SWORD, 0x0B),
    MOTION(SM101_OMEGA_WHITE_SWORD, 0x0A),
    MOTION(SM101_OMEGA_WHITE_SWORD, 0x08),
};
// clang-format on

// clang-format off
static const struct Coord Coord_ARRAY_08368ec4[6] = {
    {PIXEL(0), -PIXEL(89)},
    {PIXEL(12), -PIXEL(75)},
    {PIXEL(27), -PIXEL(61)},
    {PIXEL(41), -PIXEL(47)},
    {PIXEL(30), -PIXEL(38)},
    {PIXEL(35), -PIXEL(76)},
};
// clang-format on
