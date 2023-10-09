#include "boss.h"
#include "collision.h"
#include "entity.h"
#include "global.h"

void Childre_Init(struct Boss* p);
void Childre_Main(struct Boss* p);
void Childre_Die(struct Boss* p);

// clang-format off
const BossRoutine gChildreRoutine = {
    [ENTITY_INIT] =      Childre_Init,
    [ENTITY_UPDATE] =    Childre_Main,
    [ENTITY_DIE] =       Childre_Die,
    [ENTITY_DISAPPEAR] = DeleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

NAKED void childre_08040428(struct Boss* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov ip, r0\n\
	ldr r0, _0804044C @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r1, [r0, #0x54]\n\
	mov r2, ip\n\
	ldr r0, [r2, #0x54]\n\
	subs r3, r1, r0\n\
	cmp r3, #0\n\
	bge _0804043E\n\
	rsbs r3, r3, #0\n\
_0804043E:\n\
	mov r4, ip\n\
	adds r4, #0xc5\n\
	ldr r6, _08040450 @ =RNG_0202f388\n\
	mov r5, ip\n\
	adds r5, #0xc4\n\
	ldr r7, _08040454 @ =u8_ARRAY_0836205c\n\
	b _0804045E\n\
	.align 2, 0\n\
_0804044C: .4byte pZero2\n\
_08040450: .4byte RNG_0202f388\n\
_08040454: .4byte u8_ARRAY_0836205c\n\
_08040458:\n\
	ldrb r0, [r4]\n\
	cmp r0, #1\n\
	bls _080404B4\n\
_0804045E:\n\
	ldr r1, [r6]\n\
	ldr r0, _08040484 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _08040488 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r6]\n\
	lsrs r1, r0, #0x11\n\
	movs r0, #0xf\n\
	ands r1, r0\n\
	adds r2, r1, #0\n\
	ldr r0, _0804048C @ =0x00004FFF\n\
	cmp r3, r0\n\
	bgt _08040494\n\
	ldr r0, _08040490 @ =u8_ARRAY_ARRAY_0836202c\n\
	adds r0, r1, r0\n\
	b _080404AC\n\
	.align 2, 0\n\
_08040484: .4byte 0x000343FD\n\
_08040488: .4byte 0x00269EC3\n\
_0804048C: .4byte 0x00004FFF\n\
_08040490: .4byte u8_ARRAY_ARRAY_0836202c\n\
_08040494:\n\
	ldr r0, _080404A0 @ =0x00008FFF\n\
	cmp r3, r0\n\
	bgt _080404A8\n\
	ldr r0, _080404A4 @ =u8_ARRAY_ARRAY_0836202c+16\n\
	adds r0, r1, r0\n\
	b _080404AC\n\
	.align 2, 0\n\
_080404A0: .4byte 0x00008FFF\n\
_080404A4: .4byte u8_ARRAY_ARRAY_0836202c+16\n\
_080404A8:\n\
	ldr r0, _080404C0 @ =u8_ARRAY_ARRAY_0836202c+32\n\
	adds r0, r2, r0\n\
_080404AC:\n\
	ldrb r1, [r0]\n\
	ldrb r0, [r5]\n\
	cmp r0, r1\n\
	beq _08040458\n\
_080404B4:\n\
	ldrb r0, [r5]\n\
	cmp r0, r1\n\
	bne _080404C4\n\
	ldrb r0, [r4]\n\
	adds r0, #1\n\
	b _080404C8\n\
	.align 2, 0\n\
_080404C0: .4byte u8_ARRAY_ARRAY_0836202c+32\n\
_080404C4:\n\
	movs r0, #0\n\
	strb r1, [r5]\n\
_080404C8:\n\
	strb r0, [r4]\n\
	adds r0, r1, r7\n\
	ldrb r0, [r0]\n\
	mov r2, ip\n\
	strb r0, [r2, #0xd]\n\
	cmp r1, #1\n\
	bhi _080404D8\n\
	strb r1, [r2, #0x12]\n\
_080404D8:\n\
	movs r0, #0\n\
	mov r1, ip\n\
	strb r0, [r1, #0xe]\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

INCASM("asm/boss/childre.inc");

// --------------------------------------------

void childreNeutral(struct Boss* p);
void nop_08040788(struct Boss* p);

// clang-format off
const BossFunc sChildreUpdates1[19] = {
    childreNeutral,
    nop_08040788,
    childreNeutral,
    childreNeutral,
    childreNeutral,
    childreNeutral,
    childreNeutral,
    childreNeutral,
    childreNeutral,
    childreNeutral,
    childreNeutral,
    childreNeutral,
    childreNeutral,
    childreNeutral,
    childreNeutral,
    childreNeutral,
    nop_08040788,
    nop_08040788,
    nop_08040788,
};
// clang-format on
// --------------------------------------------

void childreMode0(struct Boss* p);
void childreMode1(struct Boss* p);
void childreMode2(struct Boss* p);
void childreMode3(struct Boss* p);
void childreStartRising(struct Boss* p);
void childreRising(struct Boss* p);
void childreMode6(struct Boss* p);
void childreMode7(struct Boss* p);
void childreMode8(struct Boss* p);
void childreStartScrewIce(struct Boss* p);
void childreMaybeMiddleScrewIce(struct Boss* p);
void childreScrewIce(struct Boss* p);
void childreMissile(struct Boss* p);
void childreStartEarShot(struct Boss* p);
void childreEarShot(struct Boss* p);
void childreEndEarShot(struct Boss* p);
void childreMode16(struct Boss* p);
void childreStun(struct Boss* p);
void childreMode18(struct Boss* p);

// clang-format off
const BossFunc sChildreUpdates2[19] = {
    childreMode0,
    childreMode1,
    childreMode2,
    childreMode3,
    childreStartRising,
    childreRising,
    childreMode6,
    childreMode7,
    childreMode8,
    childreStartScrewIce,
    childreMaybeMiddleScrewIce,
    childreScrewIce,
    childreMissile,
    childreStartEarShot,
    childreEarShot,
    childreEndEarShot,
    childreMode16,
    childreStun,
    childreMode18,
};
// clang-format on

// --------------------------------------------

void childre_08042140(struct Boss* p);
void childre_08042224(struct Boss* p);

const BossFunc sChildreDeathSeq[2] = {
    childre_08042140,
    childre_08042224,
};

const struct Collision sChildreCollisions[16] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x00,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
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
      range : {0x0000, -0x0D00, 0x1400, 0x1A00},
    },
    [2] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x08,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, -0x0D00, 0x1400, 0x1A00},
    },
    [3] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
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
      range : {0x0000, 0x0000, 0x1300, 0x1500},
    },
    [4] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x08,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0000, 0x1300, 0x1500},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 4,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {0x0000, -0x1200, 0x1000, 0x3800},
    },
    [6] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x08,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, -0x2600, 0x1200, 0x1800},
    },
    [7] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
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
      range : {0x0000, -0x1200, 0x1000, 0x3800},
    },
    [8] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x08,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, -0x2600, 0x1200, 0x1800},
    },
    [9] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
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
      range : {0x0000, -0x0D00, 0x1400, 0x1A00},
    },
    [10] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
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
      range : {-0x1000, -0x0E00, 0x3000, 0x0E00},
    },
    [11] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x08,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, -0x0D00, 0x1400, 0x1A00},
    },
    [12] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
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
      range : {0x0000, -0x0D00, 0x1400, 0x1A00},
    },
    [13] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
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
      range : {-0x2200, -0x0B00, 0x5200, 0x0E00},
    },
    [14] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
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
      range : {-0x0E00, -0x0C00, 0x2B00, 0x2200},
    },
    [15] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x08,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, -0x0D00, 0x1400, 0x1A00},
    },
};

const u8 u8_ARRAY_ARRAY_0836202c[3][16] = {
    {0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3},
    {0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3},
    {0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3},
};

const u8 u8_ARRAY_0836205c[4] = {2, 2, 12, 13};
const u8 u8_ARRAY_08362060[4] = {1, 16, 0, 0};

const struct Coord Coord_08362064 = {0, -0x1000};

const s16 s16_0836206c = 0x2601;

// clang-format off
const motion_t sChildreMotions[6] = {
    MOTION(DM164_CHILDRE, 0x10),
    MOTION(DM164_CHILDRE, 0x11),
    MOTION(DM164_CHILDRE, 0x11),
    MOTION(DM164_CHILDRE, 0x11),
    MOTION(DM164_CHILDRE, 0x11),
    MOTION(DM164_CHILDRE, 0x12),
};
// clang-format on

const struct Coord Coord_0836207c = {0x200, 0xFFFFE800};
const struct Coord Coord_08362084 = {0x600, 0xFFFFE700};
