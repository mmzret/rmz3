#include "boss.h"
#include "collision.h"
#include "entity.h"
#include "global.h"
#include "overworld.h"

INCASM("asm/boss/baby_elf.inc");

void BabyElf_Init(struct Boss* p);
void BabyElf_Update(struct Boss* p);
void BabyElf_Die(struct Boss* p);

// clang-format off
const BossRoutine gBabyElfRoutine = {
    [ENTITY_INIT] =      BabyElf_Init,
    [ENTITY_UPDATE] =    BabyElf_Update,
    [ENTITY_DIE] =       BabyElf_Die,
    [ENTITY_DISAPPEAR] = DeleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

void nop_08046150(struct Boss* p);

// clang-format off
static const BossFunc sUpdates1[19] = {
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
};
// clang-format on

// --------------------------------------------

void babyelf_08046154(struct Boss* p);
void babyelf_0804662c(struct Boss* p);
void babyelf_080467c4(struct Boss* p);
void babyelf_08046a7c(struct Boss* p);
void FUN_08046ccc(struct Boss* p);
void babyelf_08046e5c(struct Boss* p);
void babyelf_08047184(struct Boss* p);
void babyelf_08047338(struct Boss* p);
void babyelf_080475a0(struct Boss* p);
void babyelf_080477b8(struct Boss* p);
void FUN_080478b8(struct Boss* p);
void babyelf_080479d4(struct Boss* p);
void babyelf_08047c70(struct Boss* p);
void babyelf_08047e30(struct Boss* p);
void FUN_08047f84(struct Boss* p);
void FUN_08048190(struct Boss* p);
void FUN_0804839c(struct Boss* p);
void FUN_08048548(struct Boss* p);
void FUN_0804874c(struct Boss* p);

// clang-format off
static const BossFunc sUpdates2[19] = {
    babyelf_08046154,
    babyelf_0804662c,
    babyelf_080467c4,
    babyelf_08046a7c,
    FUN_08046ccc,
    babyelf_08046e5c,
    babyelf_08047184,
    babyelf_08047338,
    babyelf_080475a0,
    babyelf_080477b8,
    FUN_080478b8,
    babyelf_080479d4,
    babyelf_08047c70,
    babyelf_08047e30,
    FUN_08047f84,
    FUN_08048190,
    FUN_0804839c,
    FUN_08048548,
    FUN_0804874c,
};
// clang-format on

// --------------------------------------------

void FUN_08048788(struct Boss* p);
void FUN_080488cc(struct Boss* p);

static const BossFunc sDeinitializers[2] = {
    FUN_08048788,
    FUN_080488cc,
};

// --------------------------------------------

static const struct Collision sCollisions[5] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1000, 0x1000},
    },
    [2] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0000, 0x1000, 0x1000},
    },
    [3] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1E00, 0x1E00},
    },
    [4] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0000, 0x1E00, 0x1E00},
    },
};

const u8 u8_ARRAY_083626d4[64] = {
    1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 5, 5, 5, 5, 1, 1, 2, 2, 3, 3, 5, 5, 7, 7, 7, 7, 7, 7, 7, 7, 1, 1, 1, 2, 2, 2, 12, 12, 12, 3, 3, 3, 13, 13, 13, 13, 1, 2, 12, 12, 3, 3, 13, 13, 7, 7, 7, 7, 7, 7, 7, 7,
};

static const u8 sInitModes[4] = {0, 0, 0, 0};
