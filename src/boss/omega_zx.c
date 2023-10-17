#include "boss.h"
#include "collision.h"
#include "global.h"

// I call Omega Second Form "Omega ZX" because his shoulder pads look like Zero and X.

struct OmegaZXProjectileTemplate {
  motion_t motions[2];
  u8 unk_4;
  u8 _;
} PACKED;

INCASM("asm/boss/omega_zx.inc");

void OmegaZX_Init(struct Boss* p);
void OmegaZX_Update(struct Boss* p);
void OmegaZX_Die(struct Boss* p);
void OmegaZX_Disappear(struct Boss* p);

// clang-format off
const BossRoutine gOmegaZXRoutine = {
    [ENTITY_INIT] =      OmegaZX_Init,
    [ENTITY_UPDATE] =    OmegaZX_Update,
    [ENTITY_DIE] =       OmegaZX_Die,
    [ENTITY_DISAPPEAR] = OmegaZX_Disappear,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

void FUN_08060f98(struct Boss* p);
void FUN_08060fd8(struct Boss* p);
void FUN_08061064(struct Boss* p);
void FUN_080610a8(struct Boss* p);
void FUN_08061230(struct Boss* p);
void FUN_080612d4(struct Boss* p);
void FUN_080613b8(struct Boss* p);
void FUN_080614a4(struct Boss* p);
void FUN_080615d8(struct Boss* p);

// clang-format off
static const BossFunc sUpdates1[9] = {
    FUN_08060f98,
    FUN_08060fd8,
    FUN_08061064,
    FUN_080610a8,
    FUN_08061230,
    FUN_080612d4,
    FUN_080613b8,
    FUN_080614a4,
    FUN_080615d8,
};
// clang-format on

void FUN_08060f9c(struct Boss* p);
void FUN_08060fdc(struct Boss* p);
void FUN_08061068(struct Boss* p);
void Boss22Neutral(struct Boss* p);
void FUN_08061234(struct Boss* p);
void FUN_080612d8(struct Boss* p);
void FUN_080613bc(struct Boss* p);
void FUN_080614a8(struct Boss* p);
void FUN_080615dc(struct Boss* p);

// clang-format off
static const BossFunc sUpdates2[9] = {
    FUN_08060f9c,
    FUN_08060fdc,
    FUN_08061068,
    Boss22Neutral,
    FUN_08061234,
    FUN_080612d8,
    FUN_080613bc,
    FUN_080614a8,
    FUN_080615dc,
};
// clang-format on

// --------------------------------------------

void FUN_08060d60(struct Boss* p);
void FUN_08060e14(struct Boss* p);

static const BossFunc sDeads[2] = {
    FUN_08060d60,
    FUN_08060e14,
};

// --------------------------------------------

static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 0,
      hardness : 1,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(3), PIXEL(24), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      atkType : 0x00,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(33), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(33), PIXEL(16), PIXEL(16)},
    },
};

static const struct OmegaZXProjectileTemplate sOmegaZXProjectileTemplates[18] = {
    [0] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 0), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 1)},
      unk_4 : 0,
    },
    [1] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 2), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 3)},
      unk_4 : 1,
    },
    [2] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 4), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 5)},
      unk_4 : 2,
    },
    [3] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 0), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 1)},
      unk_4 : 0,
    },
    [4] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 4), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 5)},
      unk_4 : 2,
    },
    [5] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 2), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 3)},
      unk_4 : 1,
    },
    [6] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 2), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 3)},
      unk_4 : 1,
    },
    [7] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 0), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 1)},
      unk_4 : 0,
    },
    [8] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 4), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 5)},
      unk_4 : 2,
    },
    [9] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 2), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 3)},
      unk_4 : 1,
    },
    [10] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 4), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 5)},
      unk_4 : 2,
    },
    [11] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 0), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 1)},
      unk_4 : 0,
    },
    [12] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 4), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 5)},
      unk_4 : 2,
    },
    [13] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 0), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 1)},
      unk_4 : 0,
    },
    [14] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 2), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 3)},
      unk_4 : 1,
    },
    [15] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 4), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 5)},
      unk_4 : 2,
    },
    [16] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 2), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 3)},
      unk_4 : 1,
    },
    [17] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 0), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 1)},
      unk_4 : 0,
    },
};
