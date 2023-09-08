#include "boss.h"
#include "collision.h"
#include "entity.h"
#include "global.h"

static void Megamilpa_Init(struct Boss* p);
void Megamilpa_Update(struct Boss* p);
void Megamilpa_Die(struct Boss* p);

// clang-format off
const BossRoutine gMegamilpaRoutine = {
    [ENTITY_INIT] =      Megamilpa_Init,
    [ENTITY_MAIN] =      Megamilpa_Update,
    [ENTITY_DIE] =       Megamilpa_Die,
    [ENTITY_DISAPPEAR] = deleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

NAKED static void Megamilpa_Init(struct Boss* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r6, r0, #0\n\
	ldr r1, _0803D254 @ =gBossFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r6, #0x14]\n\
	ldr r1, _0803D258 @ =u8_ARRAY_08361ab8\n\
	ldrb r0, [r6, #0x10]\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	movs r5, #0\n\
	strb r0, [r6, #0xd]\n\
	ldrb r0, [r6, #0xa]\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r0, r6, #0\n\
	bl InitNonAffineMotion\n\
	adds r0, r6, #0\n\
	bl ResetDynamicMotion\n\
	adds r4, r6, #0\n\
	adds r4, #0xb4\n\
	ldr r0, [r6, #0x54]\n\
	asrs r0, r0, #8\n\
	str r0, [r4]\n\
	movs r1, #0xf0\n\
	bl __divsi3\n\
	lsls r1, r0, #4\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #0xc\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #7\n\
	adds r1, r1, r0\n\
	str r1, [r4]\n\
	ldr r0, [r6, #0x54]\n\
	ldr r1, [r6, #0x58]\n\
	bl FUN_08009f6c\n\
	adds r1, r6, #0\n\
	adds r1, #0xb8\n\
	ldr r2, _0803D25C @ =0xFFFFFC00\n\
	adds r0, r0, r2\n\
	str r0, [r1]\n\
	ldr r0, [r4]\n\
	str r0, [r6, #0x54]\n\
	ldr r0, [r1]\n\
	str r0, [r6, #0x58]\n\
	adds r0, r6, #0\n\
	adds r0, #0xc0\n\
	str r5, [r0]\n\
	adds r1, #5\n\
	movs r0, #0xff\n\
	strb r0, [r1]\n\
	adds r0, r6, #0\n\
	adds r0, #0xbc\n\
	strb r5, [r0]\n\
	ldrb r0, [r6, #0x10]\n\
	cmp r0, #0\n\
	bne _0803D2A0\n\
	movs r4, #0\n\
_0803D224:\n\
	cmp r4, #5\n\
	beq _0803D234\n\
	lsls r0, r4, #0x18\n\
	lsrs r0, r0, #0x18\n\
	bl CreateMegamilpaNode\n\
	adds r0, #0xb4\n\
	str r6, [r0]\n\
_0803D234:\n\
	adds r4, #1\n\
	cmp r4, #0xa\n\
	ble _0803D224\n\
	ldr r0, _0803D260 @ =gSystemSavedataManager\n\
	ldrb r1, [r0, #0x16]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0803D268\n\
	ldr r1, _0803D264 @ =gMegamilpaCoreHitbox\n\
	adds r0, r6, #0\n\
	movs r2, #0x50\n\
	bl resetBossData\n\
	b _0803D272\n\
	.align 2, 0\n\
_0803D254: .4byte gBossFnTable\n\
_0803D258: .4byte u8_ARRAY_08361ab8\n\
_0803D25C: .4byte 0xFFFFFC00\n\
_0803D260: .4byte gSystemSavedataManager\n\
_0803D264: .4byte gMegamilpaCoreHitbox\n\
_0803D268:\n\
	ldr r1, _0803D2AC @ =gMegamilpaCoreHitbox\n\
	adds r0, r6, #0\n\
	movs r2, #0x40\n\
	bl resetBossData\n\
_0803D272:\n\
	ldr r0, _0803D2B0 @ =0x085D795C\n\
	ldr r1, _0803D2B4 @ =wStaticGraphicTilenums\n\
	ldrh r1, [r1, #0xa]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	ldr r0, _0803D2B8 @ =0x085D7968\n\
	ldr r1, _0803D2BC @ =wStaticMotionPalIDs\n\
	ldrh r1, [r1, #0xa]\n\
	ldrb r2, [r0, #7]\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	bl LoadPalette\n\
_0803D2A0:\n\
	adds r0, r6, #0\n\
	bl Megamilpa_Update\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0803D2AC: .4byte gMegamilpaCoreHitbox\n\
_0803D2B0: .4byte 0x085D795C\n\
_0803D2B4: .4byte wStaticGraphicTilenums\n\
_0803D2B8: .4byte 0x085D7968\n\
_0803D2BC: .4byte wStaticMotionPalIDs\n\
 .syntax divided\n");
}

INCASM("asm/boss/megamilpa.inc");

// --------------------------------------------

void nop_0803d6a0(struct Boss* p);

// clang-format off
const BossFunc gMegamilpaModeTable1[6] = {
    nop_0803d6a0, 
    nop_0803d6a0, 
    nop_0803d6a0, 
    nop_0803d6a0, 
    nop_0803d6a0, 
    nop_0803d6a0,
};
// clang-format on

// clang-format off
const BossFunc gMegamilpaModeTable2[6] = {
    (BossFunc)0x0803D6A5, 
    (BossFunc)0x0803D6FD, 
    (BossFunc)0x0803D7A1, 
    (BossFunc)0x0803D845, 
    (BossFunc)0x0803DBA1, 
    (BossFunc)0x0803DC35,
};
// clang-format on

const struct Collision Collision_ARRAY_ARRAY_083619c8[3][3] = {
    // 0
    {
        {
          kind : DDP,
          layer : 1,
          special : 2,
          damage : 4,
          unk_04 : 0,
          element : 0,
          nature : 0,
          comboLv : 0,
          hitzone : 0,
          hardness : 0,
          unk_0a : 0,
          remaining : 2,
          unk_0c : 1,
          range : {0x0, 0x0, 0x1400, 0x1400},
        },
        {
          kind : DRP,
          layer : 1,
          special : 2,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 5,
          hardness : 0,
          unk_0a : 0,
          remaining : 1,
          unk_0c : 0,
          range : {0xF800, 0x0, 0xB00, 0x1400},
        },
        {
          kind : DRP,
          layer : 1,
          special : 2,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 5,
          hardness : 0,
          unk_0a : 0,
          remaining : 0,
          unk_0c : 0xFFFFFFFF,
          range : {0x400, 0x0, 0xF00, 0x1400},
        },
    },

    // 1
    {
        {
          kind : DDP,
          layer : 1,
          special : 2,
          damage : 4,
          unk_04 : 0,
          element : 0,
          nature : 0,
          comboLv : 0,
          hitzone : 0,
          hardness : 0,
          unk_0a : 0,
          remaining : 2,
          unk_0c : 1,
          range : {0x0, 0x0, 0x1400, 0x1400},
        },
        {
          kind : DRP,
          layer : 1,
          special : 2,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 5,
          hardness : 0,
          unk_0a : 0,
          remaining : 1,
          unk_0c : 0,
          range : {0x0, 0x800, 0x1400, 0xB00},
        },
        {
          kind : DRP,
          layer : 1,
          special : 2,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 5,
          hardness : METAL,
          unk_0a : 0,
          remaining : 0,
          unk_0c : 0xFFFFFFFF,
          range : {0x0, 0xFC00, 0x1400, 0xF00},
        },
    },

    // 2
    {
        {
          kind : DDP,
          layer : 1,
          special : 2,
          damage : 4,
          unk_04 : 0,
          element : 0,
          nature : 0,
          comboLv : 0,
          hitzone : 0,
          hardness : 0,
          unk_0a : 0,
          remaining : 2,
          unk_0c : 1,
          range : {0x0, 0x0, 0x1400, 0x1400},
        },
        {
          kind : DRP,
          layer : 1,
          special : 2,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 5,
          hardness : 0,
          unk_0a : 0,
          remaining : 1,
          unk_0c : 0,
          range : {0x800, 0x0, 0xB00, 0x1400},
        },
        {
          kind : DRP,
          layer : 1,
          special : 2,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 5,
          hardness : METAL,
          unk_0a : 0,
          remaining : 0,
          unk_0c : 0xFFFFFFFF,
          range : {0xFC00, 0x0, 0xF00, 0x1400},
        },
    },
};

const struct Collision gMegamilpaCoreHitbox = {
  kind : DRP,
  layer : 1,
  special : 2,
  damage : 0,
  unk_04 : 0xFF,
  element : 0xFF,
  nature : 0xFF,
  comboLv : 0xFF,
  hitzone : 0,
  hardness : 0,
  unk_0a : 0,
  remaining : 0,
  unk_0c : 0,
  range : {0x400, 0x0, 0x800, 0x1000},
};

const u8 u8_ARRAY_08361ab8[4] = {0, 0, 0, 0};

const s32 s32_ARRAY_08361abc[2] = {0x4800, 0x3000};

const u8 u8_ARRAY_08361ac4[2] = {2, 4};

const motion_t gMegamilpaMotions[5] = {
    MOTION(0xA0, 0x0C), MOTION(0xA0, 0x0D), MOTION(0xA0, 0x0E), MOTION(0xA0, 0x0F), MOTION(0xA0, 0x10),
};

const u8 u8_ARRAY_08361ad0[5] = {0, 0, 3, 6, 6};  // 083619c8 のidx
