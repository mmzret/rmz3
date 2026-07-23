#include "boss.h"
#include "collision.h"
#include "entity.h"
#include "global.h"
#include "overworld.h"
#include "palette_animation.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 unk_b4[27];         // 0xB4
  u8 unk_cf;             // 0xCF
  u8 unk_d0;             // 0xD0
  u8 unk_d1[19];         // 0xD1
} BabyElf;
static_assert(sizeof(BabyElf) == sizeof(Boss));

void BabyElf_Init(BabyElf* p);
void BabyElf_Update(BabyElf* p);
void BabyElf_Die(BabyElf* p);

// clang-format off
const BossRoutine gBabyElfRoutine = {
    [ENTITY_INIT] =      (void*)BabyElf_Init,
    [ENTITY_UPDATE] =    (void*)BabyElf_Update,
    [ENTITY_DIE] =       (void*)BabyElf_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteBoss,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static void FUN_08045b68(BabyElf* p) {
  if (p->work[0] == 0) {
    switch (p->unk_d0) {
      case 0: {
        if (p->unk_cf) {
          StartPaletteAnimation(25, 0x320);
          StepPaletteAnimation(25);
          p->unk_d0++;
        }
        break;
      }
      case 1: {
        StepPaletteAnimation(25);
        if (!p->unk_cf) {
          RemovePaletteAnimation(25);
          p->unk_d0 = 0;
        }
        break;
      }
    }
  }
}

INCASM("asm/boss/baby_elf.inc");

void nop_08046150(BabyElf* p);

// clang-format off
static void (*const sUpdates1[19])(BabyElf*) = {
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
}; // 0x083625BC
// clang-format on

void babyelf_08046154(BabyElf* p);
void babyelf_0804662c(BabyElf* p);
void babyelf_080467c4(BabyElf* p);
void babyelf_08046a7c(BabyElf* p);
void FUN_08046ccc(BabyElf* p);
void babyelf_08046e5c(BabyElf* p);
void babyelf_08047184(BabyElf* p);
void babyelf_08047338(BabyElf* p);
void babyelf_080475a0(BabyElf* p);
void babyelf_080477b8(BabyElf* p);
void FUN_080478b8(BabyElf* p);
void babyelf_080479d4(BabyElf* p);
void babyelf_08047c70(BabyElf* p);
void babyelf_08047e30(BabyElf* p);
void FUN_08047f84(BabyElf* p);
void FUN_08048190(BabyElf* p);
void FUN_0804839c(BabyElf* p);
void FUN_08048548(BabyElf* p);
void FUN_0804874c(BabyElf* p);

// clang-format off
static void (*const sUpdates2[19])(BabyElf*) = {
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
}; // 0x08362608
// clang-format on

void FUN_08048788(BabyElf* p);
void FUN_080488cc(BabyElf* p);

static void (*const sDeinitializers[2])(BabyElf*) = {
    FUN_08048788,
    FUN_080488cc,
};  // 0x08362654

// --------------------------------------------

// 0x0836265C
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

// 0x083626d4
const u8 u8_ARRAY_083626d4[64] = {
    1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 5, 5, 5, 5, 1, 1, 2, 2, 3, 3, 5, 5, 7, 7, 7, 7, 7, 7, 7, 7, 1, 1, 1, 2, 2, 2, 12, 12, 12, 3, 3, 3, 13, 13, 13, 13, 1, 2, 12, 12, 3, 3, 13, 13, 7, 7, 7, 7, 7, 7, 7, 7,
};

// 0x08362714
static const u8 sInitModes[4] = {0, 0, 0, 0};
