#include "collision.h"
#include "global.h"
#include "weapon.h"

// Saber wave by cyberelf, Cottus

struct SaberWave_b4 {
  struct SaberWave* saber;  // projectile -> saber (if saber, this is null)
  struct Zero* z;
  u8 props[4];
  u8 element;
  u8 atk;
  u8 flags;
  bool8 unk;
  u8 unk_c4[40];
};

// Weapon union
struct SaberWave {
  struct Entity s;
  struct Body body;
  struct SaberWave_b4 unk_b4;
};

const struct Collision sWeapon5Collisions[16] = {
    [0] = {
      kind : DDP,
      layer : 0,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x03,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {0x1000, 0x0000, 0x2000, 0x0800},
    },
    [1] = {
      kind : DRP,
      layer : 0,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x1000, 0x0000, 0x2000, 0x0800},
    },
    [2] = {
      kind : DDP,
      layer : 0,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x03,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {0x0F00, 0x0000, 0x1E00, 0x0800},
    },
    [3] = {
      kind : DRP,
      layer : 0,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0F00, 0x0000, 0x1E00, 0x0800},
    },
    [4] = {
      kind : DDP,
      layer : 0,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x03,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {0x0E00, 0x0000, 0x1C00, 0x0C00},
    },
    [5] = {
      kind : DRP,
      layer : 0,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0E00, 0x0000, 0x1C00, 0x0C00},
    },
    [6] = {
      kind : DDP,
      layer : 0,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x03,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {0x0D00, 0x0000, 0x1A00, 0x1000},
    },
    [7] = {
      kind : DRP,
      layer : 0,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0D00, 0x0000, 0x1A00, 0x1000},
    },
    [8] = {
      kind : DDP,
      layer : 0,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x03,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {0x0C00, 0x0000, 0x1800, 0x1400},
    },
    [9] = {
      kind : DRP,
      layer : 0,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0C00, 0x0000, 0x1800, 0x1400},
    },
    [10] = {
      kind : DDP,
      layer : 0,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x03,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {0x0B00, 0x0000, 0x1600, 0x1800},
    },
    [11] = {
      kind : DRP,
      layer : 0,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0B00, 0x0000, 0x1600, 0x1800},
    },
    [12] = {
      kind : DDP,
      layer : 0,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x03,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {0x0A00, 0x0000, 0x1400, 0x1C00},
    },
    [13] = {
      kind : DRP,
      layer : 0,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0A00, 0x0000, 0x1400, 0x1C00},
    },
    [14] = {
      kind : DDP,
      layer : 0,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x03,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {0x0700, 0x0000, 0x1000, 0x2000},
    },
    [15] = {
      kind : DRP,
      layer : 0,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0700, 0x0000, 0x1000, 0x2000},
    },
};

void Weapon5_Init(struct Weapon* w);
void Weapon5_Update(struct Weapon* w);
void Weapon5_Die(struct Weapon* w);

// clang-format off
const WeaponRoutine gSaberWaveRoutine = {
    [ENTITY_INIT] =      Weapon5_Init,
    [ENTITY_MAIN] =      Weapon5_Update,
    [ENTITY_DIE] =       Weapon5_Die,
    [ENTITY_DISAPPEAR] = DeleteWeapon,
    [ENTITY_EXIT] =      (WeaponFunc)DeleteEntity,    
};
// clang-format on

struct Weapon* CreateSaberWave(struct Zero* z, struct Weapon* saber, bool8 isProjectile) {
  struct SaberWave* w = (struct SaberWave*)AllocEntityFirst(gWeaponHeaderPtr);
  if (w != NULL) {
    struct SaberWave_b4* b4;

    if ((z->unk_b4).mainCopy == WEAPON_SABER) {
      INIT_WEAPON_ROUTINE(w, WEAPON_MOVE_SABER_WAVE);
      (w->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (w->s).taskCol = 16;
      (w->s).tileNum = gWeaponTileNum[0];
      (w->s).palID = gWeaponPalIDs[0];
    } else {
      INIT_WEAPON_ROUTINE(w, WEAPON_MOVE_SABER_WAVE);
      (w->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (w->s).taskCol = 16;
      (w->s).tileNum = gWeaponTileNum[1];
      (w->s).palID = gWeaponPalIDs[1];
    }
    b4 = &w->unk_b4;
    b4->saber = (struct SaberWave*)saber;
    b4->z = z;
    (w->s).work[0] = isProjectile;
    (w->s).work[1] = 0;
    if (!isProjectile) {
      CreateSaberWave(z, (struct Weapon*)w, TRUE);
    }
  }
  return (struct Weapon*)w;
}

INCASM("asm/weapon/saber_wave.inc");
