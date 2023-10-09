#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/gallisni.inc");

void Gallisni_Init(struct Enemy* p);
void Gallisni_Update(struct Enemy* p);
void Gallisni_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gGallisniRoutine = {
    [ENTITY_INIT] =      Gallisni_Init,
    [ENTITY_UPDATE] =    Gallisni_Update,
    [ENTITY_DIE] =       Gallisni_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_080873a0(struct Enemy* p);
void nop_0808737c(struct Enemy* p);
void FUN_08087380(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[8] = {
    FUN_080873a0,
    nop_0808737c,
    nop_0808737c,
    FUN_08087380,
    FUN_08087380,
    FUN_08087380,
    FUN_08087380,
    nop_0808737c,
};
// clang-format on

void FUN_080873fc(struct Enemy* p);
void FUN_08087434(struct Enemy* p);
void FUN_080874ac(struct Enemy* p);
void FUN_08087518(struct Enemy* p);
void FUN_080875c8(struct Enemy* p);
void FUN_0808772c(struct Enemy* p);
void FUN_0808778c(struct Enemy* p);
void FUN_08087ab0(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[8] = {
    FUN_080873fc,
    FUN_08087434,
    FUN_080874ac,
    FUN_08087518,
    FUN_080875c8,
    FUN_0808772c,
    FUN_0808778c,
    FUN_08087ab0,
};
// clang-format on

void FUN_080878f0(struct Enemy* p);
void FUN_08087988(struct Enemy* p);
void FUN_08087ab0(struct Enemy* p);

static const EnemyFunc sDeads[3] = {
    FUN_080878f0,
    FUN_08087988,
    FUN_08087ab0,
};

// --------------------------------------------

static const struct Collision sCollisions[5] = {
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
      damage : 255,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(30), PIXEL(14), PIXEL(58)},
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
      range : {PIXEL(2), PIXEL(0), PIXEL(26), PIXEL(26)},
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
      range : {PIXEL(2), PIXEL(0), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DDP,
      faction : FACTION_UNK2,
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
      range : {PIXEL(2), PIXEL(0), PIXEL(26), PIXEL(26)},
    },
};

static const struct Coord sElementCoord = {PIXEL(0), PIXEL(0)};
static const u8 sInitModes[2] = {1, 3};

static const motion_t sMotions[4] = {
    MOTION(103, 8),
    MOTION(103, 9),
    MOTION(103, 10),
    MOTION(103, 6),
};
