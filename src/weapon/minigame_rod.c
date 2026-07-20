#include "collision.h"
#include "global.h"
#include "weapon.h"

// 多分ゼロのミニゲームの武器

static void Weapon16_Init(Weapon* p);
static void Weapon16_Update(Weapon* p);
static void Weapon16_Die(Object* p);

// clang-format off
const WeaponRoutine gMinigameRodRoutine = {
    [ENTITY_INIT] =      (void*)Weapon16_Init,
    [ENTITY_UPDATE] =    (void*)Weapon16_Update,
    [ENTITY_DIE] =       (void*)Weapon16_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteWeapon,
    [ENTITY_EXIT] =      (void*)DeleteEntity,    
};
// clang-format on

Weapon* CreateWeaponMinigameRod(struct Entity* q, u8 r1, u8 r2) {
  Weapon* p = AllocEntityLast(gWeaponHeaderPtr);
  if (p != NULL) {
    INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_MINIGAME_ROD);
    p->flags2 &= ~ENTITY_FLAGS2_B6;
    p->renderPrio = 16;
    p->tileNum = gWeaponTileNum[0], p->palID = gWeaponPalIDs[0];
    p->work[0] = r2, p->work[1] = r1;
    p->unk_28 = q;
  }
  return p;
}

NAKED static void Weapon16_Init(Weapon* w) {
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

static void _Weapon16_Update(Weapon* p);

static void Weapon16_Update(Weapon* p) {
  static const WeaponFunc sUpdates[1] = {
      _Weapon16_Update,
  };
  (sUpdates[p->mode[1]])(p);
}

static void Weapon16_Die(Object* p) {
  p->flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_WEAPON_ROUTINE(p, ENTITY_EXIT);
}

// 0x0803CF84
NAKED static void _Weapon16_Update(Weapon* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r5, r0, #0\n\
	ldrb r4, [r5, #0xe]\n\
	cmp r4, #0\n\
	beq _0803CF94\n\
	cmp r4, #1\n\
	beq _0803CFC2\n\
	b _0803D086\n\
_0803CF94:\n\
	ldr r1, _0803CFE8 @ =gWeapon16Motions\n\
	ldrb r0, [r5, #0x11]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	adds r0, r5, #0\n\
	adds r0, #0x8c\n\
	str r4, [r0]\n\
	adds r0, #4\n\
	str r4, [r0]\n\
	adds r0, #4\n\
	strb r4, [r0]\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	strb r4, [r5, #0x12]\n\
	ldrb r0, [r5, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xe]\n\
_0803CFC2:\n\
	ldr r1, [r5, #0x28]\n\
	ldr r0, [r1, #0x54]\n\
	str r0, [r5, #0x54]\n\
	ldr r0, [r1, #0x58]\n\
	str r0, [r5, #0x58]\n\
	adds r0, r5, #0\n\
	bl UpdateEntityAnim\n\
	ldrb r0, [r5, #0x11]\n\
	cmp r0, #5\n\
	bhi _0803CFEC\n\
	adds r0, r5, #0\n\
	adds r0, #0x71\n\
	movs r1, #0\n\
	ldrsb r1, [r0, r1]\n\
	adds r7, r0, #0\n\
	cmp r1, #1\n\
	bne _0803D02C\n\
	b _0803CFFA\n\
	.align 2, 0\n\
_0803CFE8: .4byte gWeapon16Motions\n\
_0803CFEC:\n\
	adds r0, r5, #0\n\
	adds r0, #0x71\n\
	movs r1, #0\n\
	ldrsb r1, [r0, r1]\n\
	adds r7, r0, #0\n\
	cmp r1, #2\n\
	bne _0803D02C\n\
_0803CFFA:\n\
	ldrb r0, [r5, #0x12]\n\
	adds r6, r0, #0\n\
	cmp r6, #0\n\
	bne _0803D02C\n\
	adds r0, #1\n\
	strb r0, [r5, #0x12]\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r4, r5, #0\n\
	adds r4, #0x74\n\
	ldr r1, _0803D03C @ =gWeapon16Hitboxes\n\
	ldrb r0, [r5, #0x11]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	adds r2, r5, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #1\n\
	bl InitBody\n\
	str r5, [r4, #0x2c]\n\
	str r6, [r4, #0x24]\n\
_0803D02C:\n\
	ldrb r0, [r5, #0x11]\n\
	cmp r0, #5\n\
	bhi _0803D040\n\
	movs r0, #0\n\
	ldrsb r0, [r7, r0]\n\
	cmp r0, #4\n\
	bne _0803D06A\n\
	b _0803D048\n\
	.align 2, 0\n\
_0803D03C: .4byte gWeapon16Hitboxes\n\
_0803D040:\n\
	movs r0, #0\n\
	ldrsb r0, [r7, r0]\n\
	cmp r0, #5\n\
	bne _0803D06A\n\
_0803D048:\n\
	ldrb r0, [r5, #0x12]\n\
	cmp r0, #1\n\
	bne _0803D06A\n\
	adds r0, #1\n\
	movs r1, #0\n\
	strb r0, [r5, #0x12]\n\
	adds r0, r5, #0\n\
	adds r0, #0x8c\n\
	str r1, [r0]\n\
	adds r0, #4\n\
	str r1, [r0]\n\
	adds r0, #4\n\
	strb r1, [r0]\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
_0803D06A:\n\
	adds r0, r5, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0803D086\n\
	ldr r1, _0803D08C @ =gWeaponFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r5, #0x14]\n\
_0803D086:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0803D08C: .4byte gWeaponFnTable\n\
 .syntax divided\n");
}

// 0x08361780
const struct Collision gWeapon16Collisions[15] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000400,
      range : {-0x1A00, -0x0D00, 0x3800, 0x0D00},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 3,
      layer : 0x00000400,
      range : {-0x2900, -0x2F00, 0x1000, 0x1000},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000400,
      range : {-0x1D00, -0x2500, 0x1000, 0x1000},
    },
    [3] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000400,
      range : {-0x1200, -0x1900, 0x1000, 0x1000},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000400,
      range : {-0x0700, -0x0E00, 0x1000, 0x1000},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 3,
      layer : 0x00000400,
      range : {-0x2900, 0x0F00, 0x1000, 0x1000},
    },
    [6] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000400,
      range : {-0x1E00, 0x0500, 0x1000, 0x1000},
    },
    [7] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000400,
      range : {-0x1300, -0x0700, 0x1000, 0x1000},
    },
    [8] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_ROD,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000400,
      range : {-0x0800, -0x1200, 0x1000, 0x1000},
    },
    [9] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_ROD,
      element : 0x00,
      nature : ELEMENT_ENCHANTABLE,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000800,
      range : {-0x2500, -0x0E00, 0x5000, 0x1500},
    },
    [10] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_ROD,
      element : 0x00,
      nature : ELEMENT_ENCHANTABLE,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000800,
      range : {-0x2700, -0x0E00, 0x1300, 0x3200},
    },
    [11] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_ROD,
      element : 0x00,
      nature : ELEMENT_ENCHANTABLE,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000800,
      range : {-0x0B00, -0x3400, 0x1500, 0x5000},
    },
    [12] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_ROD,
      element : 0x00,
      nature : ELEMENT_ENCHANTABLE,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000800,
      range : {-0x0B00, -0x3400, 0x2A00, 0x1600},
    },
    [13] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_ROD,
      element : 0x00,
      nature : ELEMENT_ENCHANTABLE,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000800,
      range : {0x0400, 0x1000, 0x1500, 0x4600},
    },
    [14] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_ROD,
      element : 0x00,
      nature : ELEMENT_ENCHANTABLE,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000800,
      range : {0x0300, 0x0700, 0x2A00, 0x1600},
    },
};

// clang-format off
const motion_t gWeapon16Motions[9] = {
    MOTION(DM117_ROD_FORWARD_1000, 0),
    MOTION(DM117_ROD_FORWARD_1000, 1),
    MOTION(DM118_ROD_DIAGONAL_UP, 0),
    MOTION(DM118_ROD_DIAGONAL_UP, 1),
    MOTION(DM119_ROD_DIAGONAL_DOWN, 0),
    MOTION(DM119_ROD_DIAGONAL_DOWN, 1),
    MOTION(DM125_UNK, 0),
    MOTION(DM126_UNK, 0),
    MOTION(DM127_UNK, 1),
}; // 0x083618e8
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
}; // 0x083618fc
// clang-format on
