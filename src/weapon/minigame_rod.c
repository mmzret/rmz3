#include "collision.h"
#include "global.h"
#include "weapon.h"

// 多分ゼロのミニゲームの武器

static void Weapon16_Init(struct Weapon* w);
static void Weapon16_Update(struct Weapon* w);
void Weapon16_Die(struct Weapon* w);

// clang-format off
const WeaponRoutine gMinigameRodRoutine = {
    [ENTITY_INIT] =      Weapon16_Init,
    [ENTITY_MAIN] =      Weapon16_Update,
    [ENTITY_DIE] =       Weapon16_Die,
    [ENTITY_DISAPPEAR] = DeleteWeapon,
    [ENTITY_EXIT] =      (WeaponFunc)DeleteEntity,    
};
// clang-format on

struct Weapon* CreateWeaponMinigameRod(struct Entity* p, u8 r1, u8 r2) {
  struct Weapon* w = (struct Weapon*)AllocEntityFirst(gWeaponHeaderPtr);
  if (w != NULL) {
    INIT_WEAPON_ROUTINE(w, WEAPON_MOVE_MINIGAME_ROD);
    (w->s).flags2 &= ~ENTITY_FLAGS2_B6;
    (w->s).taskCol = 16;
    (w->s).tileNum = gWeaponTileNum[0];
    (w->s).palID = gWeaponPalIDs[0];
    (w->s).work[0] = r2;
    (w->s).work[1] = r1;
    (w->s).unk_28 = p;
  }
  return w;
}

NAKED static void Weapon16_Init(struct Weapon* w) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	bl InitNonAffineMotion\n\
	adds r0, r4, #0\n\
	bl ResetDynamicMotion\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	movs r3, #0\n\
	adds r2, r0, #0\n\
	orrs r2, r1\n\
	movs r0, #2\n\
	orrs r2, r0\n\
	orrs r2, r3\n\
	strb r2, [r4, #0xa]\n\
	ldrb r1, [r4, #0x10]\n\
	cmp r1, #0\n\
	bne _0803CEE6\n\
	movs r0, #0xef\n\
	ands r2, r0\n\
	strb r2, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r2, r4, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	b _0803CF06\n\
_0803CEE6:\n\
	movs r1, #1\n\
	movs r0, #0x10\n\
	orrs r2, r0\n\
	strb r2, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r3, r4, #0\n\
	adds r3, #0x4a\n\
	movs r2, #0x10\n\
	ldrb r1, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	orrs r0, r2\n\
	strb r0, [r3]\n\
_0803CF06:\n\
	ldr r1, _0803CF2C @ =gWeaponFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0x14]\n\
	movs r0, #0\n\
	strb r0, [r4, #0xd]\n\
	strb r0, [r4, #0xe]\n\
	strb r0, [r4, #0xf]\n\
	adds r0, r4, #0\n\
	bl Weapon16_Update\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0803CF2C: .4byte gWeaponFnTable\n\
 .syntax divided\n");
}

void weapon_0803cf84(struct Weapon* w);

static void Weapon16_Update(struct Weapon* w) {
  static const WeaponFunc sUpdates[1] = {
      weapon_0803cf84,
  };
  (sUpdates[(w->s).mode[1]])(w);
}

INCASM("asm/weapon/minigame_rod.inc");

const struct Collision gWeapon16Collisions[15] = {
    [0] = {
      kind : DDP,
      layer : 0,
      special : 1,
      damage : 8,
      unk_04 : 0x02,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000400,
      range : {-0x1A00, -0x0D00, 0x3800, 0x0D00},
    },
    [1] = {
      kind : DDP,
      layer : 0,
      special : 1,
      damage : 8,
      unk_04 : 0x02,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000400,
      range : {-0x2900, -0x2F00, 0x1000, 0x1000},
    },
    [2] = {
      kind : DDP,
      layer : 0,
      special : 1,
      damage : 8,
      unk_04 : 0x02,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000400,
      range : {-0x1D00, -0x2500, 0x1000, 0x1000},
    },
    [3] = {
      kind : DDP,
      layer : 0,
      special : 1,
      damage : 8,
      unk_04 : 0x02,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000400,
      range : {-0x1200, -0x1900, 0x1000, 0x1000},
    },
    [4] = {
      kind : DDP,
      layer : 0,
      special : 1,
      damage : 8,
      unk_04 : 0x02,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000400,
      range : {-0x0700, -0x0E00, 0x1000, 0x1000},
    },
    [5] = {
      kind : DDP,
      layer : 0,
      special : 1,
      damage : 8,
      unk_04 : 0x02,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000400,
      range : {-0x2900, 0x0F00, 0x1000, 0x1000},
    },
    [6] = {
      kind : DDP,
      layer : 0,
      special : 1,
      damage : 8,
      unk_04 : 0x02,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000400,
      range : {-0x1E00, 0x0500, 0x1000, 0x1000},
    },
    [7] = {
      kind : DDP,
      layer : 0,
      special : 1,
      damage : 8,
      unk_04 : 0x02,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000400,
      range : {-0x1300, -0x0700, 0x1000, 0x1000},
    },
    [8] = {
      kind : DDP,
      layer : 0,
      special : 1,
      damage : 8,
      unk_04 : 0x02,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000400,
      range : {-0x0800, -0x1200, 0x1000, 0x1000},
    },
    [9] = {
      kind : DDP,
      layer : 0,
      special : 1,
      damage : 8,
      unk_04 : 0x02,
      element : 0x00,
      nature : 0x02,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000800,
      range : {-0x2500, -0x0E00, 0x5000, 0x1500},
    },
    [10] = {
      kind : DDP,
      layer : 0,
      special : 1,
      damage : 8,
      unk_04 : 0x02,
      element : 0x00,
      nature : 0x02,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000800,
      range : {-0x2700, -0x0E00, 0x1300, 0x3200},
    },
    [11] = {
      kind : DDP,
      layer : 0,
      special : 1,
      damage : 8,
      unk_04 : 0x02,
      element : 0x00,
      nature : 0x02,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000800,
      range : {-0x0B00, -0x3400, 0x1500, 0x5000},
    },
    [12] = {
      kind : DDP,
      layer : 0,
      special : 1,
      damage : 8,
      unk_04 : 0x02,
      element : 0x00,
      nature : 0x02,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000800,
      range : {-0x0B00, -0x3400, 0x2A00, 0x1600},
    },
    [13] = {
      kind : DDP,
      layer : 0,
      special : 1,
      damage : 8,
      unk_04 : 0x02,
      element : 0x00,
      nature : 0x02,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000800,
      range : {0x0400, 0x1000, 0x1500, 0x4600},
    },
    [14] = {
      kind : DDP,
      layer : 0,
      special : 1,
      damage : 8,
      unk_04 : 0x02,
      element : 0x00,
      nature : 0x02,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000800,
      range : {0x0300, 0x0700, 0x2A00, 0x1600},
    },
};

// clang-format off
const motion_t gWeapon16Motions[9] = {
    MOTION(0x75, 0x00),
    MOTION(0x75, 0x01),
    MOTION(0x76, 0x00),
    MOTION(0x76, 0x01),
    MOTION(0x77, 0x00),
    MOTION(0x77, 0x01),
    MOTION(0x7D, 0x00),
    MOTION(0x7E, 0x00),
    MOTION(0x7F, 0x01),
};
// clang-format on

// clang-format off
const struct Collision* const gWeapon16Hitboxes[9] = {
    &gWeapon16Collisions[0],
    &gWeapon16Collisions[0],
    &gWeapon16Collisions[1],
    &gWeapon16Collisions[1],
    &gWeapon16Collisions[5],
    &gWeapon16Collisions[5],
    &gWeapon16Collisions[9],
    &gWeapon16Collisions[11],
    &gWeapon16Collisions[13],
};
// clang-format on
