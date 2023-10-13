#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/generator_cannon.inc");

void GeneratorCannon_Init(struct Enemy* p);
void GeneratorCannon_Update(struct Enemy* p);
void GeneratorCannon_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gGeneratorCannonRoutine = {
    [ENTITY_INIT] =      GeneratorCannon_Init,
    [ENTITY_UPDATE] =    GeneratorCannon_Update,
    [ENTITY_DIE] =       GeneratorCannon_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_0808c760(struct Enemy* p);
void FUN_0808c764(struct Enemy* p);
void FUN_0808c784(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[8] = {
    FUN_0808c784,
    FUN_0808c760,
    FUN_0808c760,
    FUN_0808c760,
    FUN_0808c760,
    FUN_0808c764,
    FUN_0808c764,
    FUN_0808c760,
};
// clang-format on

void generatorcannon_0808c7e0(struct Enemy* p);
void generatorcannon_0808c868(struct Enemy* p);
void generatorcannon_0808c8d4(struct Enemy* p);
void generatorcannon_0808c970(struct Enemy* p);
void generatorcannon_0808ca28(struct Enemy* p);
void generatorcannon_0808cad8(struct Enemy* p);
void generatorcannon_0808cc08(struct Enemy* p);
void generatorcannon_0808cd60(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[8] = {
    generatorcannon_0808c7e0,
    generatorcannon_0808c868,
    generatorcannon_0808c8d4,
    generatorcannon_0808c970,
    generatorcannon_0808ca28,
    generatorcannon_0808cad8,
    generatorcannon_0808cc08,
    generatorcannon_0808cd60,
};
// clang-format on

// --------------------------------------------

void FUN_0808ce4c(struct Enemy* p);
void FUN_0808cefc(struct Enemy* p);
void FUN_0808cf94(struct Enemy* p);

static const EnemyFunc sDeads[4] = {
    FUN_0808ce4c,
    FUN_0808cefc,
    FUN_0808cf94,
    generatorcannon_0808cd60,
};

// --------------------------------------------

static const struct Collision sCollisions[18] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 0,
      hardness : 8,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(21), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : 8,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), PIXEL(0), PIXEL(21), PIXEL(12)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {-PIXEL(16), -PIXEL(37), PIXEL(17), PIXEL(17)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {PIXEL(16), -PIXEL(37), PIXEL(17), PIXEL(17)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(12), PIXEL(66), PIXEL(40)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : 8,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(13), PIXEL(66), PIXEL(34)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {-PIXEL(19), -PIXEL(35), PIXEL(13), PIXEL(11)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {PIXEL(19), -PIXEL(35), PIXEL(13), PIXEL(11)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(12), PIXEL(66), PIXEL(40)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : 8,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(13), PIXEL(66), PIXEL(34)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(12), PIXEL(66), PIXEL(40)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : 8,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(13), PIXEL(66), PIXEL(34)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(36), PIXEL(51), PIXEL(11)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(40), PIXEL(23), PIXEL(19)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(12), PIXEL(66), PIXEL(40)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : 8,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(13), PIXEL(66), PIXEL(34)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(21), PIXEL(12)},
    },
};

static const struct Coord sElementCoord = {PIXEL(0), PIXEL(0)};

static const u8 sInitModes[4] = {1, 5, 0, 0};

static const struct Rect sSize = {PIXEL(0), -PIXEL(13), PIXEL(60), PIXEL(36)};

static const u8 sCollisionIdxs1[4] = {3, 7, 11, 11};
static const u8 sCollisionIdxs2[4] = {11, 7, 3, 0};

// clang-format off
static const motion_t sMotions[7] = {
    MOTION(SM113_GENERATOR_CANNON, 3),
    MOTION(SM113_GENERATOR_CANNON, 4),
    MOTION(SM113_GENERATOR_CANNON, 5),
    MOTION(SM113_GENERATOR_CANNON, 3),
    MOTION(SM113_GENERATOR_CANNON, 4),
    MOTION(SM113_GENERATOR_CANNON, 5),
    MOTION(SM114_KEATON, 3),
};
// clang-format on
