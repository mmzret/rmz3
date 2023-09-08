#include "collision.h"
#include "enemy.h"
#include "global.h"

INCASM("asm/enemy/childre_obj.inc");

void ChildreObj_Init(struct Enemy* p);
void ChildreObj_Update(struct Enemy* p);
void ChildreObj_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gChildreObjRoutine = {
    [ENTITY_INIT] =      ChildreObj_Init,
    [ENTITY_MAIN] =      ChildreObj_Update,
    [ENTITY_DIE] =       ChildreObj_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void nop_080739a8(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_08366d04[4] = {
    nop_080739a8,
    nop_080739a8,
    nop_080739a8,
    nop_080739a8,
};

// --------------------------------------------

void FUN_080739ac(struct Enemy* p);
void FUN_08073a0c(struct Enemy* p);
void FUN_08073a74(struct Enemy* p);
void FUN_08073b28(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_08366d14[4] = {
    FUN_080739ac,
    FUN_08073a0c,
    FUN_08073a74,
    FUN_08073b28,
};

// --------------------------------------------

void FUN_08073d88(struct Enemy* p);
void FUN_08073dd8(struct Enemy* p);
void FUN_08073e18(struct Enemy* p);
void FUN_08073e60(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_08366d24[4] = {
    FUN_08073d88,
    FUN_08073dd8,
    FUN_08073e18,
    FUN_08073e60,
};

// --------------------------------------------

static const struct Collision sCollisions[2 * 4] = {
    {
      kind : DDP,
      layer : LAYER_ENEMY,
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
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      layer : LAYER_ENEMY,
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
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      layer : LAYER_ENEMY,
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
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      layer : LAYER_ENEMY,
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
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      layer : LAYER_ENEMY,
      special : 0,
      damage : 4,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      layer : LAYER_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 4,
      hardness : 8,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      layer : LAYER_ENEMY,
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
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      layer : LAYER_ENEMY,
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
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
};

// --------------------------------------------

static const u8 sInitModes[4] = {0, 1, 2, 3};

// clang-format off
static const motion_t sMotions[8] = {
    MOTION(0x24, 0x08),
    MOTION(0x24, 0x07),
    MOTION(0x24, 0x06),
    MOTION(0x24, 0x05),
    MOTION(0x24, 0x04),
    MOTION(0x24, 0x0B),
    MOTION(0x24, 0x0A),
    MOTION(0x24, 0x09),
};
// clang-format on

static const s8 s8_ARRAY_ARRAY_08366e08[8][2] = {
    {-6, 0}, {-4, 4}, {0, 6}, {4, 4}, {6, 0}, {4, -4}, {0, -6}, {-4, -4},
};

static const s32 s32_08366e18 = 0x240C;
