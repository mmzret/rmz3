#include "boss.h"
#include "collision.h"
#include "global.h"

INCASM("asm/boss/phantom.inc");

void Phantom_Init(struct Boss* p);
void Phantom_Update(struct Boss* p);
void Phantom_Die(struct Boss* p);

// clang-format off
const BossRoutine gPhantomBossRoutine = {
    [ENTITY_INIT] =      Phantom_Init,
    [ENTITY_UPDATE] =    Phantom_Update,
    [ENTITY_DIE] =       Phantom_Die,
    [ENTITY_DISAPPEAR] = DeleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

// clang-format off
const motion_t motion_t_ARRAY_08365214[21] = {
    MOTION(DM188_PHANTOM, 0x00),
    MOTION(DM188_PHANTOM, 0x0B),
    MOTION(DM188_PHANTOM, 0x0D),
    MOTION(DM188_PHANTOM, 0x03),
    MOTION(DM188_PHANTOM, 0x0A),
    MOTION(DM188_PHANTOM, 0x11),
    MOTION(DM188_PHANTOM, 0x12),
    MOTION(DM188_PHANTOM, 0x0C),
    MOTION(DM188_PHANTOM, 0x06),
    MOTION(DM188_PHANTOM, 0x04),
    MOTION(DM188_PHANTOM, 0x05),
    MOTION(DM188_PHANTOM, 0x07),
    MOTION(DM188_PHANTOM, 0x08),
    MOTION(DM188_PHANTOM, 0x09),
    MOTION(DM188_PHANTOM, 0x01),
    MOTION(DM188_PHANTOM, 0x02),
    MOTION(DM188_PHANTOM, 0x10),
    MOTION(DM188_PHANTOM, 0x0E),
    MOTION(DM188_PHANTOM, 0x0F),
    MOTION(DM188_PHANTOM, 0x13),
    MOTION(DM188_PHANTOM, 0x14),
};
// clang-format on

static const s32 s32_ARRAY_08365240[32] = {
    0x00000000, 0x00000040, 0x000000C0, 0x00000180, 0x00000280, 0x000003C0, 0x00000540, 0x00000700, 0x00000900, 0x00000B40, 0x00000DC0, 0x00001080, 0x00001380, 0x000016C0, 0x00001A40, 0x00001E00, 0x00002200, 0x00002640, 0x00002AC0, 0x00002F80, 0x00003480, 0x000039C0, 0x00003F40, 0x00004500, 0x00004B00, 0x00005140, 0x000057C0, 0x00005E80, 0x00006580, 0x00006CC0, 0x00007440, 0x00007C00,
};

static const struct Collision sCollisions[14] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 5,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(14), PIXEL(16), PIXEL(28)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(14), PIXEL(16), PIXEL(28)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 5,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 5,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(16), -PIXEL(9), PIXEL(48), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 5,
      remaining : 0,
      range : {-PIXEL(5), -PIXEL(12), PIXEL(26), PIXEL(24)},
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
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
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
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
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
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
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
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0,
      hitzone : 5,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(19), PIXEL(16), PIXEL(38)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 5,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(19), PIXEL(16), PIXEL(38)},
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
      hitzone : 5,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(19), PIXEL(16), PIXEL(38)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(19), PIXEL(16), PIXEL(38)},
    },
};

// --------------------------------------------

void phantom_08060668(struct Boss* p);

static const BossFunc sDeads[1] = {
    phantom_08060668,
};

// --------------------------------------------

void callPhantomBossModeTable(struct Boss* p);

static const BossFunc PTR_ARRAY_08365414[1] = {
    callPhantomBossModeTable,
};

void phantom_0805efa4(struct Boss* p);
void phantom_0805f0a0(struct Boss* p);
void FUN_0805f3d0(struct Boss* p);
void FUN_0805f54c(struct Boss* p);
void FUN_0805fa10(struct Boss* p);
void phantom_08060244(struct Boss* p);
void FUN_080603b8(struct Boss* p);

// clang-format off
static const BossFunc PTR_ARRAY_08365418[7] = {
    phantom_0805efa4,
    phantom_0805f0a0,
    FUN_0805f3d0,
    FUN_0805f54c,
    FUN_0805fa10,
    phantom_08060244,
    FUN_080603b8,
};
// clang-format on

void FUN_0805efbc(struct Boss* p);
void FUN_0805f004(struct Boss* p);

static const BossFunc PTR_ARRAY_08365434[2] = {
    FUN_0805efbc,
    FUN_0805f004,
};

void FUN_0805f0f4(struct Boss* p);
void FUN_0805f180(struct Boss* p);
void FUN_0805f26c(struct Boss* p);
void FUN_0805f338(struct Boss* p);

static const BossFunc PTR_ARRAY_0836543c[4] = {
    FUN_0805f0f4,
    FUN_0805f180,
    FUN_0805f26c,
    FUN_0805f338,
};

void phantom_0805f198(struct Boss* p);
void FUN_0805f214(struct Boss* p);

static const BossFunc PTR_ARRAY_0836544c[2] = {
    phantom_0805f198,
    FUN_0805f214,
};

void FUN_0805f284(struct Boss* p);
void FUN_0805f2e0(struct Boss* p);

static const BossFunc PTR_ARRAY_08365454[2] = {
    FUN_0805f284,
    FUN_0805f2e0,
};

void FUN_0805f350(struct Boss* p);
void FUN_0805f394(struct Boss* p);

static const BossFunc PTR_ARRAY_0836545c[2] = {
    FUN_0805f350,
    FUN_0805f394,
};

void FUN_0805f3e8(struct Boss* p);
void FUN_0805f444(struct Boss* p);
void FUN_0805f464(struct Boss* p);
void FUN_0805f488(struct Boss* p);
void FUN_0805f4a4(struct Boss* p);
void FUN_0805f52c(struct Boss* p);

// clang-format off
static const BossFunc PTR_ARRAY_08365464[6] = {
    FUN_0805f3e8,
    FUN_0805f444,
    FUN_0805f464,
    FUN_0805f488,
    FUN_0805f4a4,
    FUN_0805f52c,
};
// clang-format on

void FUN_0805f564(struct Boss* p);
void FUN_0805f6b0(struct Boss* p);
void FUN_0805f738(struct Boss* p);
void FUN_0805f76c(struct Boss* p);
void FUN_0805f820(struct Boss* p);
void FUN_0805f934(struct Boss* p);

// clang-format off
static const BossFunc PTR_ARRAY_0836547c[6] = {
    FUN_0805f564,
    FUN_0805f6b0,
    FUN_0805f738,
    FUN_0805f76c,
    FUN_0805f820,
    FUN_0805f934,
};
// clang-format on

void FUN_0805f57c(struct Boss* p);
void FUN_0805f5a8(struct Boss* p);
void FUN_0805f630(struct Boss* p);
void FUN_0805f660(struct Boss* p);
void FUN_0805f690(struct Boss* p);

// clang-format off
static const BossFunc PTR_ARRAY_08365494[5] = {
    FUN_0805f57c,
    FUN_0805f5a8,
    FUN_0805f630,
    FUN_0805f660,
    FUN_0805f690,
};
// clang-format on

void FUN_0805f6c8(struct Boss* p);
void FUN_0805f6e0(struct Boss* p);
void FUN_0805f6fc(struct Boss* p);
void FUN_0805f71c(struct Boss* p);

static const BossFunc PTR_ARRAY_083654a8[4] = {
    FUN_0805f6c8,
    FUN_0805f6e0,
    FUN_0805f6fc,
    FUN_0805f71c,
};

void FUN_0805f784(struct Boss* p);
void FUN_0805f794(struct Boss* p);
void FUN_0805f7d0(struct Boss* p);

static const BossFunc PTR_ARRAY_083654b8[3] = {
    FUN_0805f784,
    FUN_0805f794,
    FUN_0805f7d0,
};

void FUN_0805f838(struct Boss* p);
void FUN_0805f85c(struct Boss* p);
void FUN_0805f870(struct Boss* p);
void FUN_0805f8c4(struct Boss* p);
void nop_0805f930(struct Boss* p);

// clang-format off
static const BossFunc PTR_ARRAY_083654c4[5] = {
    FUN_0805f838,
    FUN_0805f85c,
    FUN_0805f870,
    FUN_0805f8c4,
    nop_0805f930,
};
// clang-format on

void FUN_0805f94c(struct Boss* p);
void FUN_0805f97c(struct Boss* p);
void FUN_0805f9a0(struct Boss* p);
void FUN_0805f9dc(struct Boss* p);
void FUN_0805f9f4(struct Boss* p);

// clang-format off
static const BossFunc PTR_ARRAY_083654d8[5] = {
    FUN_0805f94c,
    FUN_0805f97c,
    FUN_0805f9a0,
    FUN_0805f9dc,
    FUN_0805f9f4,
};
// clang-format on

void FUN_0805fa28(struct Boss* p);
void FUN_0805fa44(struct Boss* p);
void FUN_0805fc7c(struct Boss* p);
void FUN_0805fd5c(struct Boss* p);
void FUN_0805ff64(struct Boss* p);
void FUN_080600fc(struct Boss* p);

// clang-format off
static const BossFunc PTR_ARRAY_083654ec[6] = {
    FUN_0805fa28,
    FUN_0805fa44,
    FUN_0805fc7c,
    FUN_0805fd5c,
    FUN_0805ff64,
    FUN_080600fc,
};
// clang-format on

void FUN_0805fa5c(struct Boss* p);
void FUN_0805fac4(struct Boss* p);
void FUN_0805fadc(struct Boss* p);
void FUN_0805fafc(struct Boss* p);
void FUN_0805fb24(struct Boss* p);
void FUN_0805fb8c(struct Boss* p);
void FUN_0805fc1c(struct Boss* p);

// clang-format off
static const BossFunc PTR_ARRAY_08365504[7] = {
    FUN_0805fa5c,
    FUN_0805fac4,
    FUN_0805fadc,
    FUN_0805fafc,
    FUN_0805fb24,
    FUN_0805fb8c,
    FUN_0805fc1c,
};
// clang-format on

void FUN_0805fd74(struct Boss* p);
void FUN_0805fdac(struct Boss* p);
void FUN_0805feac(struct Boss* p);

static const BossFunc PTR_ARRAY_08365520[3] = {
    FUN_0805fd74,
    FUN_0805fdac,
    FUN_0805feac,
};

void FUN_0805ff7c(struct Boss* p);
void FUN_0805ffb4(struct Boss* p);
void FUN_0805ffec(struct Boss* p);
void FUN_08060040(struct Boss* p);
void FUN_080600c8(struct Boss* p);
void FUN_080600e0(struct Boss* p);

// clang-format off
static const BossFunc PTR_ARRAY_0836552c[6] = {
    FUN_0805ff7c,
    FUN_0805ffb4,
    FUN_0805ffec,
    FUN_08060040,
    FUN_080600c8,
    FUN_080600e0,
};
// clang-format on

void FUN_08060114(struct Boss* p);
void FUN_0806016c(struct Boss* p);
void FUN_0806019c(struct Boss* p);
void FUN_080601f0(struct Boss* p);
void FUN_08060208(struct Boss* p);

// clang-format off
static const BossFunc PTR_ARRAY_08365544[5] = {
    FUN_08060114,
    FUN_0806016c,
    FUN_0806019c,
    FUN_080601f0,
    FUN_08060208,
};
// clang-format on

void FUN_080603d0(struct Boss* p);
void FUN_08060410(struct Boss* p);
void FUN_080604e0(struct Boss* p);
void FUN_08060560(struct Boss* p);

static const BossFunc PTR_ARRAY_08365558[4] = {
    FUN_080603d0,
    FUN_08060410,
    FUN_080604e0,
    FUN_08060560,
};

void FUN_080afdf0(struct Boss* p);
void FUN_080afe38(struct Boss* p);

static const BossFunc PTR_ARRAY_08365568[2] = {
    FUN_080afdf0,
    FUN_080afe38,
};
