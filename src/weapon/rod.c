#include "collision.h"
#include "global.h"
#include "motion.h"
#include "overworld.h"
#include "score.h"
#include "sound.h"
#include "weapon.h"
#include "zero.h"

struct RecoilRod {
  OBJECT_HDR;
  // props (56bytes, offset: 0xB4..)
  struct RecoilRodProps {
    Player* z;      // 0xB4
    u8 element;     // 0xB8
    u8 atk;         // 0xB9
    u8 unk_06;      // 0xBA
    u8 comboLv;     // 0xBB
    u8 unk_08;      // 0xBC
    u8 unk_09;      // 0xBD
    u8 unk_0a;      // 0xBE
    u8 unk_0b;      // 0xBF
    u8 unk_0c[8];   // 0xC0
    u8 unk_c8[36];  // 0xC8
  } props;
};
static_assert(sizeof(struct RecoilRod) == sizeof(struct Weapon));

static void Rod_OnCollision(struct Body* body, Coords32* r1, Coords32* r2);

static const u8 gRodElement[4];

struct Weapon* CreateWeaponRod(struct Zero* z) {
  struct RecoilRod* p;
  u8 element;

  KillAllWeapons(DeleteSaber);
  p = AllocEntityLast(gWeaponHeaderPtr);
  if (p != NULL) {
    if ((z->unk_b4).mainCopy == WEAPON_ROD) {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_RECOIL_ROD);
      (p->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (p->s).renderPrio = 16;
      (p->s).tileNum = gWeaponTileNum[0], (p->s).palID = gWeaponPalIDs[0];
      element = gRodElement[((&z->unk_b4)->status).element];
      SetWeaponElement(0, element);
    } else {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_RECOIL_ROD);
      (p->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (p->s).renderPrio = 16;
      (p->s).tileNum = gWeaponTileNum[1], (p->s).palID = gWeaponPalIDs[1];
      element = gRodElement[((&z->unk_b4)->status).element];
      SetWeaponElement(1, element);
    }
    (p->props).z = z;
    (p->s).work[0] = z->rodID, (p->s).work[1] = 0;
  }
  return (void*)p;
}

// clang-format off
// 0x08360430
static const motion_t sMotions[22] = {
    MOTION(DM117_ROD_FORWARD_1000, 0),
    MOTION(DM117_ROD_FORWARD_1000, 1),
    MOTION(DM118_ROD_DIAGONAL_UP, 0),
    MOTION(DM118_ROD_DIAGONAL_UP, 1),
    MOTION(DM119_ROD_DIAGONAL_DOWN, 0),
    MOTION(DM119_ROD_DIAGONAL_DOWN, 1),
    MOTION(DM120_ROD_FORWARD, 0),
    MOTION(DM121_ROD_DIAGONAL_UP, 0),
    MOTION(DM122_ROD_DIAGONAL_DOWN, 0),
    MOTION(DM123_UNK, 0),
    MOTION(DM124_UNK, 0),
    MOTION(DM125_UNK, 0),
    MOTION(DM126_UNK, 0),
    MOTION(DM127_UNK, 0),
    MOTION(DM128_UNK, 0),
    MOTION(DM129_UNK, 0),
    MOTION(DM130_UNK, 0),
    MOTION(DM131_UNK, 0),
    MOTION(DM132_UNK, 0),
    MOTION(DM127_UNK, 1),
    MOTION(DM130_UNK, 1),
    MOTION(DM117_ROD_FORWARD_1000, 2),
};
// clang-format on

// 0x0836045c
static const u8 gRodElement[4] = {0, 1, 2, 3};

static const u8 u8_ARRAY_08360460[12] = {
    0, 1, 2, 0, 1, 2, 3, 0, 2, 2, 0, 0,
};

const struct Collision gRodCollisions[123] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      comboLv : 1,
      remaining : 1,
      layer : 0x00000400,
      range : {-0x1800, -0x0E00, 0x3F00, 0x0800},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x1800, -0x0E00, 0x3F00, 0x0800},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000400,
      range : {-0x2000, -0x0E00, 0x2800, 0x0800},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x2000, -0x0E00, 0x2800, 0x0800},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000400,
      range : {-0x1C00, -0x0E00, 0x1F00, 0x0800},
    },
    [5] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x1C00, -0x0E00, 0x1F00, 0x0800},
    },
    [6] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000400,
      range : {-0x1900, -0x0E00, 0x1400, 0x0800},
    },
    [7] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x1900, -0x0E00, 0x1400, 0x0800},
    },
    [8] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 9,
      layer : 0x00000400,
      range : {-0x0800, -0x0F00, 0x0800, 0x0800},
    },
    [9] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 8,
      range : {-0x0800, -0x0F00, 0x0800, 0x0800},
    },
    [10] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 7,
      layer : 0x00000400,
      range : {-0x2800, -0x2F00, 0x0800, 0x0800},
    },
    [11] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 6,
      range : {-0x2800, -0x2F00, 0x0800, 0x0800},
    },
    [12] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 5,
      layer : 0x00000400,
      range : {-0x2000, -0x2700, 0x0800, 0x0800},
    },
    [13] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 4,
      range : {-0x2000, -0x2700, 0x0800, 0x0800},
    },
    [14] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 3,
      layer : 0x00000400,
      range : {-0x1000, -0x1700, 0x0800, 0x0800},
    },
    [15] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 2,
      range : {-0x1000, -0x1700, 0x0800, 0x0800},
    },
    [16] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000400,
      range : {-0x1800, -0x1F00, 0x0800, 0x0800},
    },
    [17] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x1800, -0x1F00, 0x0800, 0x0800},
    },
    [18] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 9,
      layer : 0x00000400,
      range : {-0x0800, -0x0F00, 0x0800, 0x0800},
    },
    [19] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 8,
      range : {-0x0800, -0x0F00, 0x0800, 0x0800},
    },
    [20] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 7,
      layer : 0x00000400,
      range : {-0x2800, 0x1000, 0x0800, 0x0800},
    },
    [21] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 6,
      range : {-0x2800, 0x1000, 0x0800, 0x0800},
    },
    [22] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      comboLv : 1,
      remaining : 5,
      layer : 0x00000400,
      range : {-0x2000, 0x0800, 0x0800, 0x0800},
    },
    [23] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 4,
      range : {-0x2000, 0x0800, 0x0800, 0x0800},
    },
    [24] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 3,
      layer : 0x00000400,
      range : {-0x1000, -0x0800, 0x0800, 0x0800},
    },
    [25] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 2,
      range : {-0x1000, -0x0800, 0x0800, 0x0800},
    },
    [26] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000400,
      range : {-0x1800, 0x0000, 0x0800, 0x0800},
    },
    [27] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x1800, 0x0000, 0x0800, 0x0800},
    },
    [28] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000400,
      range : {-0x1600, -0x1100, 0x4000, 0x0800},
    },
    [29] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x1600, -0x1100, 0x4000, 0x0800},
    },
    [30] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000400,
      range : {-0x2000, -0x1100, 0x2800, 0x0800},
    },
    [31] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x2000, -0x1100, 0x2800, 0x0800},
    },
    [32] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000400,
      range : {-0x1A00, -0x1100, 0x1F00, 0x0800},
    },
    [33] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x1A00, -0x1100, 0x1F00, 0x0800},
    },
    [34] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000400,
      range : {-0x1700, -0x1000, 0x1400, 0x0800},
    },
    [35] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x1700, -0x1000, 0x1400, 0x0800},
    },
    [36] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 9,
      layer : 0x00000400,
      range : {-0x0800, -0x1300, 0x0800, 0x0800},
    },
    [37] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 8,
      range : {-0x0800, -0x1300, 0x0800, 0x0800},
    },
    [38] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 7,
      layer : 0x00000400,
      range : {-0x2800, -0x3300, 0x0800, 0x0800},
    },
    [39] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 6,
      range : {-0x2800, -0x3300, 0x0800, 0x0800},
    },
    [40] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 5,
      layer : 0x00000400,
      range : {-0x2000, -0x2B00, 0x0800, 0x0800},
    },
    [41] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 4,
      range : {-0x2000, -0x2B00, 0x0800, 0x0800},
    },
    [42] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 3,
      layer : 0x00000400,
      range : {-0x1000, -0x1B00, 0x0800, 0x0800},
    },
    [43] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 2,
      range : {-0x1000, -0x1B00, 0x0800, 0x0800},
    },
    [44] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000400,
      range : {-0x1800, -0x2300, 0x0800, 0x0800},
    },
    [45] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x1800, -0x2300, 0x0800, 0x0800},
    },
    [46] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 9,
      layer : 0x00000400,
      range : {-0x0800, -0x1100, 0x0800, 0x0800},
    },
    [47] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 8,
      range : {-0x0800, -0x1100, 0x0800, 0x0800},
    },
    [48] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 7,
      layer : 0x00000400,
      range : {-0x2800, 0x0E00, 0x0800, 0x0800},
    },
    [49] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 6,
      range : {-0x2800, 0x0E00, 0x0800, 0x0800},
    },
    [50] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 5,
      layer : 0x00000400,
      range : {-0x2000, 0x0600, 0x0800, 0x0800},
    },
    [51] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 4,
      range : {-0x2000, 0x0600, 0x0800, 0x0800},
    },
    [52] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 3,
      layer : 0x00000400,
      range : {-0x1000, -0x0A00, 0x0800, 0x0800},
    },
    [53] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 2,
      range : {-0x1000, -0x0A00, 0x0800, 0x0800},
    },
    [54] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000400,
      range : {-0x1800, -0x0200, 0x0800, 0x0800},
    },
    [55] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x1800, -0x0200, 0x0800, 0x0800},
    },
    [56] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000400,
      range : {0x1B00, -0x0B00, 0x3600, 0x0800},
    },
    [57] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x1B00, -0x0B00, 0x3600, 0x0800},
    },
    [58] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000400,
      range : {0x1800, -0x0E00, 0x3F00, 0x0800},
    },
    [59] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x1800, -0x0E00, 0x3F00, 0x0800},
    },
    [60] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000400,
      range : {0x1B00, -0x0B00, 0x1F00, 0x0800},
    },
    [61] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x1B00, -0x0B00, 0x1F00, 0x0800},
    },
    [62] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000400,
      range : {0x1700, -0x0B00, 0x1400, 0x0800},
    },
    [63] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x1700, -0x0B00, 0x1400, 0x0800},
    },
    [64] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000400,
      range : {-0x1600, -0x0B00, 0x3F00, 0x0800},
    },
    [65] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x1600, -0x0B00, 0x3F00, 0x0800},
    },
    [66] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000400,
      range : {-0x1E00, -0x0B00, 0x2800, 0x0800},
    },
    [67] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x1E00, -0x0B00, 0x2800, 0x0800},
    },
    [68] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000400,
      range : {-0x1A00, -0x0B00, 0x1F00, 0x0800},
    },
    [69] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x1A00, -0x0B00, 0x1F00, 0x0800},
    },
    [70] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000400,
      range : {-0x1700, -0x0B00, 0x1400, 0x0800},
    },
    [71] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x1700, -0x0B00, 0x1400, 0x0800},
    },
    [72] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 12,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x22,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000800,
      range : {-0x1700, -0x0E00, 0x2200, 0x0900},
    },
    [73] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x1700, -0x0E00, 0x2200, 0x0900},
    },
    [74] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 12,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x22,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 3,
      layer : 0x00000800,
      range : {-0x2700, -0x0F00, 0x1400, 0x2C00},
    },
    [75] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 2,
      range : {-0x2700, -0x0F00, 0x1400, 0x2C00},
    },
    [76] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 12,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x22,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000800,
      range : {-0x2C00, -0x0E00, 0x3800, 0x0D00},
    },
    [77] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x2C00, -0x0E00, 0x3800, 0x0D00},
    },
    [78] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 12,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x22,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000800,
      range : {-0x0A00, -0x2500, 0x0900, 0x2200},
    },
    [79] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x0A00, -0x2500, 0x0900, 0x2200},
    },
    [80] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 12,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x22,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 3,
      layer : 0x00000800,
      range : {-0x0A00, -0x3300, 0x2C00, 0x1400},
    },
    [81] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 2,
      range : {-0x0A00, -0x3300, 0x2C00, 0x1400},
    },
    [82] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 12,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x22,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000800,
      range : {-0x0A00, -0x3900, 0x0D00, 0x3800},
    },
    [83] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x0A00, -0x3900, 0x0D00, 0x3800},
    },
    [84] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 12,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x22,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000800,
      range : {0x0400, -0x0A00, 0x0800, 0x2700},
    },
    [85] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0400, -0x0A00, 0x0800, 0x2700},
    },
    [86] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 12,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x22,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 3,
      layer : 0x00000800,
      range : {0x0300, 0x0700, 0x2200, 0x0E00},
    },
    [87] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 2,
      range : {0x0300, 0x0700, 0x2200, 0x0E00},
    },
    [88] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 12,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x22,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000800,
      range : {0x0400, 0x0D00, 0x0E00, 0x3500},
    },
    [89] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0400, 0x0D00, 0x0E00, 0x3500},
    },
    [90] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 12,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x22,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000800,
      range : {-0x1600, -0x1100, 0x2200, 0x0900},
    },
    [91] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x1600, -0x1100, 0x2200, 0x0900},
    },
    [92] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 12,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x22,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 3,
      layer : 0x00000800,
      range : {-0x2600, -0x1200, 0x1400, 0x2C00},
    },
    [93] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 2,
      range : {-0x2600, -0x1200, 0x1400, 0x2C00},
    },
    [94] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 12,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x22,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000800,
      range : {-0x2B00, -0x1100, 0x3800, 0x0D00},
    },
    [95] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x2B00, -0x1100, 0x3800, 0x0D00},
    },
    [96] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 12,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x22,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000800,
      range : {-0x0900, -0x2500, 0x0900, 0x2200},
    },
    [97] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x0900, -0x2500, 0x0900, 0x2200},
    },
    [98] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 12,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x22,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 3,
      layer : 0x00000800,
      range : {-0x0900, -0x3300, 0x2C00, 0x1400},
    },
    [99] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 2,
      range : {-0x0900, -0x3300, 0x2C00, 0x1400},
    },
    [100] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 12,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x22,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000800,
      range : {-0x0900, -0x3900, 0x0D00, 0x3800},
    },
    [101] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x0900, -0x3900, 0x0D00, 0x3800},
    },
    [102] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 12,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x22,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000800,
      range : {0x0400, -0x0C00, 0x0800, 0x2700},
    },
    [103] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0400, -0x0C00, 0x0800, 0x2700},
    },
    [104] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 12,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x22,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 3,
      layer : 0x00000800,
      range : {0x0300, 0x0500, 0x2200, 0x0E00},
    },
    [105] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 2,
      range : {0x0300, 0x0500, 0x2200, 0x0E00},
    },
    [106] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 12,
      atkType : ATK_ROD,
      element : 0x00,
      nature : (BODY_NATURE_RECOIL | ELEMENT_ENCHANTABLE),
      comboLv : 1,
      remaining : 1,
      layer : 0x00000800,
      range : {0x0400, 0x0B00, 0x0E00, 0x3500},
    },
    [107] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0400, 0x0B00, 0x0E00, 0x3500},
    },
    [108] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 12,
      atkType : ATK_ROD,
      nature : (BODY_NATURE_RECOIL | ELEMENT_ENCHANTABLE),
      comboLv : 1,
      remaining : 1,
      layer : 0x00000800,
      range : {0x1100, -0x0D00, 0x2100, 0x0A00},
    },
    [109] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x1100, -0x0D00, 0x2100, 0x0A00},
    },
    [110] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 12,
      atkType : ATK_ROD,
      nature : (BODY_NATURE_RECOIL | ELEMENT_ENCHANTABLE),
      comboLv : 1,
      remaining : 3,
      layer : 0x00000800,
      range : {0x2000, -0x0E00, 0x1400, 0x2C00},
    },
    [111] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 2,
      range : {0x2000, -0x0E00, 0x1400, 0x2C00},
    },
    [112] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 12,
      atkType : ATK_ROD,
      nature : (BODY_NATURE_RECOIL | ELEMENT_ENCHANTABLE),
      comboLv : 1,
      remaining : 1,
      layer : 0x00000800,
      range : {0x2600, -0x0D00, 0x3800, 0x0D00},
    },
    [113] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x2600, -0x0D00, 0x3800, 0x0D00},
    },
    [114] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 12,
      atkType : ATK_ROD,
      nature : (BODY_NATURE_RECOIL | ELEMENT_ENCHANTABLE),
      comboLv : 1,
      remaining : 1,
      layer : 0x00000800,
      range : {-0x0E00, -0x0B00, 0x2200, 0x0900},
    },
    [115] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x0E00, -0x0B00, 0x2200, 0x0900},
    },
    [116] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 12,
      atkType : ATK_ROD,
      nature : (BODY_NATURE_RECOIL | ELEMENT_ENCHANTABLE),
      comboLv : 1,
      remaining : 3,
      layer : 0x00000800,
      range : {-0x1E00, -0x0C00, 0x1400, 0x2C00},
    },
    [117] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 2,
      range : {-0x1E00, -0x0C00, 0x1400, 0x2C00},
    },
    [118] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 12,
      atkType : ATK_ROD,
      nature : (BODY_NATURE_RECOIL | ELEMENT_ENCHANTABLE),
      comboLv : 1,
      remaining : 1,
      layer : 0x00000800,
      range : {-0x2300, -0x0B00, 0x3800, 0x0D00},
    },
    [119] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x2300, -0x0B00, 0x3800, 0x0D00},
    },
    [120] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 12,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x04,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000400,
      range : {-0x2200, -0x1300, 0x4600, 0x2100},
    },
    [121] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x2200, -0x1300, 0x4600, 0x2100},
    },
    [122] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : ATK_SABER,
      comboLv : 0x00,
      remaining : 0,
      layer : 0x00000020,
      range : {0x0000, 0x0000, 0x0000, 0x0000},
    },
};

// clang-format off
const struct Collision* const PTR_ARRAY_08360ff4[6] = {
    &gRodCollisions[122],
    &gRodCollisions[0],
    &gRodCollisions[2],
    &gRodCollisions[4],
    &gRodCollisions[6],
    &gRodCollisions[122],
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_0836100c[6] = {
    &gRodCollisions[122],
    &gRodCollisions[8],
    &gRodCollisions[10],
    &gRodCollisions[12],
    &gRodCollisions[14],
    &gRodCollisions[122],
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_08361024[6] = {
    &gRodCollisions[122],
    &gRodCollisions[18],
    &gRodCollisions[20],
    &gRodCollisions[22],
    &gRodCollisions[24],
    &gRodCollisions[122],
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_0836103c[6] = {
    &gRodCollisions[122],
    &gRodCollisions[28],
    &gRodCollisions[30],
    &gRodCollisions[32],
    &gRodCollisions[34],
    &gRodCollisions[122],
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_08361054[6] = {
    &gRodCollisions[122],
    &gRodCollisions[36],
    &gRodCollisions[38],
    &gRodCollisions[40],
    &gRodCollisions[42],
    &gRodCollisions[122],
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_0836106c[6] = {
    &gRodCollisions[122],
    &gRodCollisions[46],
    &gRodCollisions[48],
    &gRodCollisions[50],
    &gRodCollisions[52],
    &gRodCollisions[122],
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_08361084[6] = {
    &gRodCollisions[122],
    &gRodCollisions[56],
    &gRodCollisions[58],
    &gRodCollisions[60],
    &gRodCollisions[62],
    &gRodCollisions[122],
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_0836109c[6] = {
    &gRodCollisions[122],
    &gRodCollisions[64],
    &gRodCollisions[66],
    &gRodCollisions[68],
    &gRodCollisions[70],
    &gRodCollisions[122],
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_083610b4[9] = {
    &gRodCollisions[122],
    &gRodCollisions[72],
    &gRodCollisions[76],
    &gRodCollisions[74],
    &gRodCollisions[74],
    &gRodCollisions[72],
    &gRodCollisions[72],
    &gRodCollisions[122],
    &gRodCollisions[122],
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_083610d8[9] = {
    &gRodCollisions[122],
    &gRodCollisions[78],
    &gRodCollisions[82],
    &gRodCollisions[80],
    &gRodCollisions[80],
    &gRodCollisions[78],
    &gRodCollisions[78],
    &gRodCollisions[122],
    &gRodCollisions[122],
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_083610fc[9] = {
    &gRodCollisions[122],
    &gRodCollisions[84],
    &gRodCollisions[88],
    &gRodCollisions[86],
    &gRodCollisions[86],
    &gRodCollisions[84],
    &gRodCollisions[84],
    &gRodCollisions[122],
    &gRodCollisions[122],
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_08361120[9] = {
    &gRodCollisions[122],
    &gRodCollisions[90],
    &gRodCollisions[94],
    &gRodCollisions[92],
    &gRodCollisions[92],
    &gRodCollisions[90],
    &gRodCollisions[90],
    &gRodCollisions[122],
    &gRodCollisions[122],
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_08361144[9] = {
    &gRodCollisions[122],
    &gRodCollisions[96],
    &gRodCollisions[100],
    &gRodCollisions[98],
    &gRodCollisions[98],
    &gRodCollisions[96],
    &gRodCollisions[96],
    &gRodCollisions[122],
    &gRodCollisions[122],
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_08361168[9] = {
    &gRodCollisions[122],
    &gRodCollisions[102],
    &gRodCollisions[106],
    &gRodCollisions[104],
    &gRodCollisions[104],
    &gRodCollisions[102],
    &gRodCollisions[102],
    &gRodCollisions[122],
    &gRodCollisions[122],
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_0836118c[9] = {
    &gRodCollisions[122],
    &gRodCollisions[108],
    &gRodCollisions[112],
    &gRodCollisions[110],
    &gRodCollisions[110],
    &gRodCollisions[108],
    &gRodCollisions[108],
    &gRodCollisions[122],
    &gRodCollisions[122],
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_083611b0[9] = {
    &gRodCollisions[122],
    &gRodCollisions[114],
    &gRodCollisions[118],
    &gRodCollisions[116],
    &gRodCollisions[116],
    &gRodCollisions[114],
    &gRodCollisions[114],
    &gRodCollisions[122],
    &gRodCollisions[122],
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_083611d4[8] = {
    &gRodCollisions[120],
    &gRodCollisions[120],
    &gRodCollisions[120],
    &gRodCollisions[120],
    &gRodCollisions[120],
    &gRodCollisions[120],
    &gRodCollisions[120],
    &gRodCollisions[120],
};
// clang-format on

// clang-format off
// 0x083611f4
const struct Collision *const *const gRodHitboxes[22] = {
    PTR_ARRAY_08360ff4,
    PTR_ARRAY_08360ff4,
    PTR_ARRAY_0836100c,
    PTR_ARRAY_0836100c,
    PTR_ARRAY_08361024,
    PTR_ARRAY_08361024,
    PTR_ARRAY_0836103c,
    PTR_ARRAY_08361054,
    PTR_ARRAY_0836106c,
    PTR_ARRAY_08361084,
    PTR_ARRAY_0836109c,
    PTR_ARRAY_083610b4,
    PTR_ARRAY_083610d8,
    PTR_ARRAY_083610fc,
    PTR_ARRAY_08361120,
    PTR_ARRAY_08361144,
    PTR_ARRAY_08361168,
    PTR_ARRAY_0836118c,
    PTR_ARRAY_083611b0,
    PTR_ARRAY_083610fc,
    PTR_ARRAY_08361168,
    PTR_ARRAY_083611d4,
};
// clang-format on

static void Rod_Init(struct RecoilRod* p);
void Rod_Update(struct Weapon* p);
static void Rod_Die(struct Entity* p);

// clang-format off
const WeaponRoutine gRodRoutine = {
    [ENTITY_INIT] =      (void*)Rod_Init,
    [ENTITY_UPDATE] =    (void*)Rod_Update,
    [ENTITY_DIE] =       (void*)Rod_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteWeapon,
    [ENTITY_EXIT] =      (void*)DeleteEntity,    
};
// clang-format on

const u8 u8_ARRAY_08361260[12] = {
    1, 2, 2, 3, 3, 4, 4, 4, 4, 0, 0, 0,
};

static void Rod_Init(struct RecoilRod* p) {
  const struct Collision* collisions;
  struct Zero* z = (&p->props)->z;

  SET_WEAPON_ROUTINE(p, ENTITY_UPDATE);
  EnableSpriteAnimation_Normal(p);
  ResetDynamicMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteAnimation(p, sMotions[(p->s).work[0]]);

  collisions = gRodHitboxes[(p->s).work[0]][0];
  _INIT_BODY(p, collisions, 1);

  if ((p->s).work[0] == 21) {
    PlaySound(SE_THOUSAND);
  } else if ((p->s).work[0] < 11) {
    PlaySound(SE_RECOIL_ROD);
  } else {
    PlaySound(SE_CHARGE_RECOIL);
  }

  {
    (&p->props)->comboLv = 1;
    if (gRodHitboxes[(p->s).work[0]][1]->nature & ELEMENT_ENCHANTABLE) {
      (&p->props)->element = gRodElement[((&z->unk_b4)->status).element];
      (&p->props)->atk = 8;
    } else {
      (&p->props)->element = gRodElement[0];
      (&p->props)->atk = 8;
      if (sMotions[(p->s).work[0]] & 1) (&p->props)->comboLv = 2;
    }
    if ((p->s).work[0] == 21) (&p->props)->atk = 6;
    (&p->props)->atk += CalcRodBonus(z);
  }

  {
#if MODERN
    struct Body* body;
#else
    register struct Body* body asm("r4");
#endif
    if ((&p->props)->comboLv != 0) {
      body = &p->body;
      InitWeaponBody(body, collisions, (&p->props)->atk, (&p->props)->element, -1, (&p->props)->comboLv);
    } else {
      body = &p->body;
      InitWeaponBody(body, collisions, (&p->props)->atk, (&p->props)->element, -1, -1);
    }
    (&p->props)->unk_06 = 0;
    if ((((&z->unk_b4)->status).exSkill & (1 << EXSKILL_ID_SOUL)) && ((p->s).work[0] == 12 || (p->s).work[0] == 15)) {
      if (((&z->unk_b4)->status).element == ELEMENT_FLAME) {
        (&p->props)->unk_06 = 1;
      } else {
        (&p->props)->unk_06 = 2;
      }
    }
    (&p->props)->unk_08 = 1;
    body->fn = Rod_OnCollision;
  }
  Rod_Update((void*)p);
}

INCASM("asm/weapon/rod.inc");

static void Rod_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_WEAPON_ROUTINE(p, ENTITY_EXIT);
}

struct Entity* CreateWeapon13(struct Zero* z, u8 n);

// 0x08039960
static void Rod_OnCollision(struct Body* body, Coords32* r1, Coords32* r2) {
  struct RecoilRod* p = (struct RecoilRod*)body->parent;
  Object* q = (Object*)body->enemy->parent;
  Player* z = (p->props).z;
  if (body->hitboxFlags & BODY_STATUS_B2) {
    IncWeaponUseCount(WEAPON_ROD);

    if (body->hitboxFlags & BODY_STATUS_B2) {
      if (((p->s).work[0] >= 11) && ((p->s).work[0] < 21)) {
        p = (struct RecoilRod*)body->parent;
        CreateWeapon13((p->props).z, u8_ARRAY_08360460[(p->s).work[0] - 11]);
      }
      if (((p->s).work[0] == 13) && ((p->s).coord.y < (q->s).coord.y)) {
        (p->s).work[0] = 19;
        z->unk_135 = 1;
      }
      if (((p->s).work[0] == 16) && ((p->s).coord.y < (q->s).coord.y)) {
        (p->s).work[0] = 20;
        z->unk_135 = 1;
      }
    }
  }
}
