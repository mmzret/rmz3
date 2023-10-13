#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/lemmingles.inc");

void Lemmingles_Init(struct Enemy* p);
void Lemmingles_Update(struct Enemy* p);
void Lemmingles_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gLemminglesRoutine = {
    [ENTITY_INIT] =      Lemmingles_Init,
    [ENTITY_UPDATE] =    Lemmingles_Update,
    [ENTITY_DIE] =       Lemmingles_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_0806e990(struct Enemy* p);
void FUN_0806e970(struct Enemy* p);
void nop_0806e96c(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[7] = {
    FUN_0806e990,
    FUN_0806e970,
    FUN_0806e970,
    FUN_0806e970,
    FUN_0806e970,
    FUN_0806e970,
    nop_0806e96c,
};
// clang-format on

void FUN_0806e9fc(struct Enemy* p);
void FUN_0806ea64(struct Enemy* p);
void FUN_0806ed08(struct Enemy* p);
void FUN_0806ee0c(struct Enemy* p);
void FUN_0806ee94(struct Enemy* p);
void FUN_0806efa4(struct Enemy* p);
void FUN_0806f07c(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[7] = {
    FUN_0806e9fc,
    FUN_0806ea64,
    FUN_0806ed08,
    FUN_0806ee0c,
    FUN_0806ee94,
    FUN_0806efa4,
    FUN_0806f07c,
};
// clang-format on

// --------------------------------------------

void FUN_0806f1dc(struct Enemy* p);
void FUN_0806f274(struct Enemy* p);
void FUN_0806f07c(struct Enemy* p);

static const EnemyFunc sDeads[3] = {
    FUN_0806f1dc,
    FUN_0806f274,
    FUN_0806f07c,
};

// --------------------------------------------

static const struct Collision sCollisions[7] = {
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
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 2,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(7), PIXEL(24), PIXEL(15)},
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
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(7), PIXEL(24), PIXEL(15)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 4,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(7), PIXEL(24), PIXEL(15)},
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
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(7), PIXEL(24), PIXEL(15)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 2,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(7), PIXEL(24), PIXEL(15)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 4,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(7), PIXEL(24), PIXEL(15)},
    },
};

static const struct Coord sElementCoord = {PIXEL(0), -PIXEL(8)};
static const u8 sInitModes[4] = {1, 1, 1, 1};

// clang-format off
static const motion_t sMotions[13] = {
    MOTION(SM029_LEMMINGLES, 1),
    MOTION(SM029_LEMMINGLES, 0),
    MOTION(SM029_LEMMINGLES, 3),
    MOTION(SM029_LEMMINGLES, 2),
    // --------------------------------------------
    MOTION(SM029_LEMMINGLES, 1),
    MOTION(SM029_LEMMINGLES, 5),
    MOTION(SM029_LEMMINGLES, 3),
    MOTION(SM029_LEMMINGLES, 11),
    // --------------------------------------------
    MOTION(SM029_LEMMINGLES, 22),
    MOTION(SM029_LEMMINGLES, 23),
    MOTION(SM029_LEMMINGLES, 24),
    // --------------------------------------------
    MOTION(SM029_LEMMINGLES, 19),
    MOTION(SM029_LEMMINGLES, 17),
};


