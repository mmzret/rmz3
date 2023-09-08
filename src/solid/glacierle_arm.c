#include "collision.h"
#include "entity.h"
#include "global.h"
#include "solid.h"

INCASM("asm/solid/glacierle_arm.inc");

// ------------------------------------------------------------------------------------------------------------------------------------

void GlacierleArm_Init(struct Solid* p);
void GlacierleArm_Update(struct Solid* p);
void GlacierleArm_Die(struct Solid* p);

// clang-format off
const SolidRoutine gGlacierleArmRoutine = {
    [ENTITY_INIT] =      GlacierleArm_Init,
    [ENTITY_MAIN] =      GlacierleArm_Update,
    [ENTITY_DIE] =       GlacierleArm_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void nop_080ceb28(struct Solid* p);
void FUN_080ceb2c(struct Solid* p);
void FUN_080cec74(struct Solid* p);

const SolidFunc sGlacierleArmUpdates1[2] = {
    nop_080ceb28,
    nop_080ceb28,
};

const SolidFunc sGlacierleArmUpdates2[2] = {
    FUN_080ceb2c,
    FUN_080cec74,
};

// --------------------------------------------

const struct Collision sGlacierleArmCollisions[21] = {
    [0] = {
      kind : DRP,
      layer : 1,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [1] = {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {0x0000, 0x0500, 0x1000, 0x0800},
    },
    [2] = {
      kind : DRP,
      layer : 1,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x04,
      hardness : HARDNESS_B3,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0500, 0x1000, 0x0800},
    },
    [3] = {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {0x0000, 0x0500, 0x1000, 0x0B00},
    },
    [4] = {
      kind : DRP,
      layer : 1,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x04,
      hardness : HARDNESS_B3,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0500, 0x1000, 0x0B00},
    },
    [5] = {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {0x0000, 0x0400, 0x1000, 0x0800},
    },
    [6] = {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {0x0000, 0x0A00, 0x0800, 0x0800},
    },
    [7] = {
      kind : DRP,
      layer : 1,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x04,
      hardness : HARDNESS_B3,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0400, 0x1000, 0x0800},
    },
    [8] = {
      kind : DRP,
      layer : 1,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x04,
      hardness : HARDNESS_B3,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0A00, 0x0800, 0x0800},
    },
    [9] = {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {0x0000, 0x0400, 0x1000, 0x0800},
    },
    [10] = {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {0x0000, 0x0C00, 0x0800, 0x0900},
    },
    [11] = {
      kind : DRP,
      layer : 1,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x04,
      hardness : HARDNESS_B3,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0400, 0x1000, 0x0800},
    },
    [12] = {
      kind : DRP,
      layer : 1,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x04,
      hardness : HARDNESS_B3,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0C00, 0x0800, 0x0900},
    },
    [13] = {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {0x0000, 0x0400, 0x1000, 0x0800},
    },
    [14] = {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {0x0000, 0x0F00, 0x0800, 0x0E00},
    },
    [15] = {
      kind : DRP,
      layer : 1,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x04,
      hardness : HARDNESS_B3,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0400, 0x1000, 0x0800},
    },
    [16] = {
      kind : DRP,
      layer : 1,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x04,
      hardness : HARDNESS_B3,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0F00, 0x0800, 0x0E00},
    },
    [17] = {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {0x0000, 0x0400, 0x1000, 0x0800},
    },
    [18] = {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {0x0000, 0x1300, 0x0800, 0x1600},
    },
    [19] = {
      kind : DRP,
      layer : 1,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x04,
      hardness : HARDNESS_B3,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0400, 0x1000, 0x0800},
    },
    [20] = {
      kind : DRP,
      layer : 1,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x04,
      hardness : HARDNESS_B3,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x1300, 0x0800, 0x1600},
    },
};

// --------------------------------------------

const u8 u8_ARRAY_08370538[2] = {0, 0};
const u8 u8_ARRAY_0837053a[10] = {0, 1, 2, 2, 2, 3, 3, 3, 4, 4};
const u8 sGlacierleArmCollisionIdx[10] = {0, 1, 1, 1, 3, 5, 9, 13, 17, 17};

// --------------------------------------------

// clang-format off
const motion_t sGlacierleArmMotions[10] = {
    MOTION(0x5A, 0x00),
    MOTION(0x5A, 0x00),
    MOTION(0x5A, 0x01),
    MOTION(0x5A, 0x02),
    MOTION(0x5A, 0x03),
    MOTION(0x5A, 0x04),
    MOTION(0x5A, 0x05),
    MOTION(0x5A, 0x06),
    MOTION(0x5A, 0x07),
    MOTION(0x5A, 0x07),
};
// clang-format on