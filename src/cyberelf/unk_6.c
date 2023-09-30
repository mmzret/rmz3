#include "cyberelf.h"
#include "global.h"

static const u16 u16_ARRAY_08371d5c[7];
static const u8 sFusionPenalties[7];

static void Elf6_Init(struct Elf* e);
static void Elf6_Update(struct Elf* e);
static void Elf6_Die(struct Elf* e);

// clang-format off
const ElfRoutine gElf6Routine = {
    [ENTITY_INIT] =      Elf6_Init,
    [ENTITY_MAIN] =      Elf6_Update,
    [ENTITY_DIE] =       Elf6_Die,
    [ENTITY_DISAPPEAR] = DeleteElf,
    [ENTITY_EXIT] =      (ElfFunc)DeleteEntity,
};
// clang-format on

struct Elf* CreateElf6(struct Zero* z, u8 breed, u8 availability, u8 _) {
  struct Elf* p = (struct Elf*)AllocEntityFirst(gElfHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 16;
    INIT_ELF_ROUTINE(p, 6);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    *(struct Zero**)(&(p->props.raw[0])) = z;
    (p->s).work[0] = breed;
    (p->s).work[1] = availability;
  }
  return p;
}

NAKED static void Elf6_Init(struct Elf* e) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r6, r0, #0\n\
	adds r0, #0xb4\n\
	ldr r5, [r0]\n\
	ldr r0, _080E36F4 @ =gPause\n\
	movs r4, #1\n\
	strb r4, [r0]\n\
	ldr r1, _080E36F8 @ =gElfFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r6, #0x14]\n\
	adds r0, r6, #0\n\
	bl InitNonAffineMotion\n\
	adds r0, r6, #0\n\
	bl ResetDynamicMotion\n\
	ldrb r0, [r6, #0xa]\n\
	movs r7, #0\n\
	orrs r0, r4\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	movs r0, #2\n\
	bl createElfAction\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	ldrb r0, [r5, #0xa]\n\
	lsrs r0, r0, #4\n\
	ands r0, r4\n\
	adds r1, r6, #0\n\
	adds r1, #0x4c\n\
	strb r0, [r1]\n\
	ldrb r1, [r5, #0xa]\n\
	lsrs r1, r1, #4\n\
	ands r1, r4\n\
	adds r4, r6, #0\n\
	adds r4, #0x4a\n\
	lsls r3, r1, #4\n\
	ldrb r2, [r4]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r3\n\
	strb r0, [r4]\n\
	cmp r1, #0\n\
	beq _080E36FC\n\
	ldrb r0, [r6, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _080E3702\n\
	.align 2, 0\n\
_080E36F4: .4byte gPause\n\
_080E36F8: .4byte gElfFnTable\n\
_080E36FC:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080E3702:\n\
	strb r0, [r6, #0xa]\n\
	adds r2, r6, #0\n\
	adds r2, #0x49\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	adds r0, r6, #0\n\
	adds r0, #0xbc\n\
	movs r1, #0\n\
	str r1, [r0]\n\
	subs r0, #4\n\
	strb r1, [r0]\n\
	adds r1, r6, #0\n\
	adds r1, #0xb9\n\
	movs r0, #0x20\n\
	strb r0, [r1]\n\
	adds r1, #1\n\
	movs r0, #0x90\n\
	lsls r0, r0, #1\n\
	strh r0, [r1]\n\
	adds r0, r6, #0\n\
	bl Elf6_Update\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

NAKED static void Elf6_Update(struct Elf* e) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r5, r0, #0\n\
	adds r0, #0xb4\n\
	ldr r4, [r0]\n\
	ldr r1, _080E378C @ =gZeroRanges\n\
	ldr r2, _080E3790 @ =0x00000147\n\
	adds r0, r4, r2\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #3\n\
	adds r0, r0, r1\n\
	ldr r6, [r0]\n\
	ldr r7, [r0, #4]\n\
	adds r0, r5, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	ldr r0, [r0]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080E3776\n\
	adds r0, r4, #0\n\
	adds r0, #0xa4\n\
	movs r1, #0\n\
	ldrsh r0, [r0, r1]\n\
	cmp r0, #0\n\
	bne _080E3798\n\
_080E3776:\n\
	ldr r1, _080E3794 @ =gElfFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r5, #0x14]\n\
	b _080E3888\n\
	.align 2, 0\n\
_080E378C: .4byte gZeroRanges\n\
_080E3790: .4byte 0x00000147\n\
_080E3794: .4byte gElfFnTable\n\
_080E3798:\n\
	lsls r1, r6, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldr r0, [r4, #0x54]\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x54]\n\
	asrs r1, r6, #0x10\n\
	ldr r0, [r4, #0x58]\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x58]\n\
	adds r1, r5, #0\n\
	adds r1, #0xbc\n\
	ldr r0, [r1]\n\
	adds r6, r0, #0\n\
	adds r6, #0x60\n\
	str r6, [r1]\n\
	adds r4, r5, #0\n\
	adds r4, #0xb8\n\
	ldrb r0, [r4]\n\
	adds r3, r0, #1\n\
	adds r0, r3, #0\n\
	movs r1, #0x30\n\
	bl __modsi3\n\
	adds r3, r0, #0\n\
	strb r3, [r4]\n\
	lsls r0, r3, #8\n\
	movs r1, #0x30\n\
	bl __divsi3\n\
	adds r3, r0, #0\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	movs r1, #1\n\
	rsbs r1, r1, #0\n\
	cmp r0, #0\n\
	beq _080E37E4\n\
	movs r1, #1\n\
_080E37E4:\n\
	ldr r2, _080E3890 @ =gSineTable\n\
	adds r0, r3, #0\n\
	adds r0, #0x40\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r2\n\
	movs r4, #0\n\
	ldrsh r0, [r0, r4]\n\
	muls r0, r6, r0\n\
	asrs r0, r0, #8\n\
	muls r1, r0, r1\n\
	ldr r0, [r5, #0x54]\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x54]\n\
	lsls r0, r3, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r2\n\
	movs r1, #0\n\
	ldrsh r0, [r0, r1]\n\
	adds r1, r6, #0\n\
	muls r1, r0, r1\n\
	asrs r1, r1, #8\n\
	ldr r0, [r5, #0x58]\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x58]\n\
	adds r1, r5, #0\n\
	adds r1, #0xba\n\
	ldrh r0, [r1]\n\
	subs r4, r0, #1\n\
	strh r4, [r1]\n\
	adds r6, r5, #0\n\
	adds r6, #0xb9\n\
	ldrb r0, [r6]\n\
	subs r0, #1\n\
	strb r0, [r6]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _080E3840\n\
	adds r0, r5, #0\n\
	adds r0, #0x54\n\
	movs r1, #0\n\
	bl FUN_080bfc94\n\
	movs r0, #0x20\n\
	strb r0, [r6]\n\
_080E3840:\n\
	cmp r4, #0\n\
	bne _080E3856\n\
	ldr r1, _080E3894 @ =gElfFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r5, #0x14]\n\
_080E3856:\n\
	cmp r4, #0xef\n\
	bhi _080E3888\n\
	movs r0, #0xf0\n\
	subs r4, r0, r4\n\
	lsls r0, r4, #4\n\
	subs r1, r0, r4\n\
	adds r0, r1, #0\n\
	movs r1, #0xf0\n\
	bl __udivsi3\n\
	adds r1, r0, #0\n\
	movs r0, #0xf\n\
	ands r4, r0\n\
	lsrs r4, r4, #2\n\
	cmp r4, #1\n\
	bne _080E3878\n\
	adds r1, #1\n\
_080E3878:\n\
	ldr r2, _080E3898 @ =wMOSAIC\n\
	movs r0, #0xf\n\
	ands r1, r0\n\
	lsls r0, r1, #4\n\
	orrs r0, r1\n\
	lsls r1, r0, #8\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
_080E3888:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E3890: .4byte gSineTable\n\
_080E3894: .4byte gElfFnTable\n\
_080E3898: .4byte wMOSAIC\n\
 .syntax divided\n");
}

NAKED static void Elf6_Die(struct Elf* e) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	adds r0, #0xb4\n\
	ldr r5, [r0]\n\
	ldrb r3, [r4, #0xd]\n\
	adds r2, r3, #0\n\
	cmp r2, #0\n\
	beq _080E38AE\n\
	b _080E39A8\n\
_080E38AE:\n\
	subs r0, #0x60\n\
	movs r1, #0\n\
	bl FUN_080bfce8\n\
	ldr r1, _080E394C @ =gUnlockedElfPtr\n\
	adds r3, r5, #0\n\
	adds r3, #0xb4\n\
	ldr r2, _080E3950 @ =0x00000121\n\
	adds r0, r5, r2\n\
	ldrb r0, [r0]\n\
	ldr r1, [r1]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1]\n\
	movs r2, #2\n\
	orrs r0, r2\n\
	strb r0, [r1]\n\
	ldr r1, _080E3954 @ =sFusionPenalties\n\
	ldrb r0, [r4, #0x10]\n\
	adds r1, r0, r1\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	beq _080E38E2\n\
	ldrh r0, [r3, #4]\n\
	ldrb r1, [r1]\n\
	adds r0, r0, r1\n\
	strh r0, [r3, #4]\n\
_080E38E2:\n\
	ldr r1, _080E3958 @ =gMission\n\
	ldr r0, [r1]\n\
	adds r2, r0, #0\n\
	adds r2, #0x4c\n\
	ldrb r0, [r2]\n\
	adds r6, r1, #0\n\
	cmp r0, #0x62\n\
	bhi _080E38F6\n\
	adds r0, #1\n\
	strb r0, [r2]\n\
_080E38F6:\n\
	ldr r1, _080E395C @ =u16_ARRAY_08371d5c\n\
	ldrb r0, [r4, #0x10]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r3, [r0]\n\
	ldr r0, _080E3960 @ =gCurStory\n\
	lsrs r2, r3, #3\n\
	adds r0, #4\n\
	adds r2, r2, r0\n\
	movs r1, #7\n\
	ands r1, r3\n\
	movs r0, #1\n\
	lsls r0, r1\n\
	ldrb r1, [r2]\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	cmp r3, #0x27\n\
	bne _080E392C\n\
	ldr r1, _080E3964 @ =gGameState+25200\n\
	ldrb r0, [r1, #4]\n\
	movs r2, #0x80\n\
	orrs r0, r2\n\
	strb r0, [r1, #4]\n\
	adds r1, #0x54\n\
	ldrb r0, [r1, #4]\n\
	orrs r0, r2\n\
	strb r0, [r1, #4]\n\
_080E392C:\n\
	cmp r3, #0x23\n\
	bne _080E3982\n\
	ldr r5, _080E3968 @ =0x0202F33C\n\
	ldrh r2, [r5]\n\
	ldr r1, _080E396C @ =0x00007FFF\n\
	adds r0, r1, #0\n\
	ands r0, r2\n\
	movs r7, #0xe1\n\
	lsls r7, r7, #3\n\
	adds r0, r0, r7\n\
	cmp r0, r1\n\
	ble _080E3974\n\
	ldr r1, _080E3970 @ =0x0000FFFF\n\
	adds r0, r1, #0\n\
	b _080E3980\n\
	.align 2, 0\n\
_080E394C: .4byte gUnlockedElfPtr\n\
_080E3950: .4byte 0x00000121\n\
_080E3954: .4byte sFusionPenalties\n\
_080E3958: .4byte gMission\n\
_080E395C: .4byte u16_ARRAY_08371d5c\n\
_080E3960: .4byte gCurStory\n\
_080E3964: .4byte gGameState+25200\n\
_080E3968: .4byte 0x0202F33C\n\
_080E396C: .4byte 0x00007FFF\n\
_080E3970: .4byte 0x0000FFFF\n\
_080E3974:\n\
	movs r7, #0xe1\n\
	lsls r7, r7, #3\n\
	adds r0, r2, r7\n\
	ldr r2, _080E39A0 @ =0xFFFF8000\n\
	adds r1, r2, #0\n\
	orrs r0, r1\n\
_080E3980:\n\
	strh r0, [r5]\n\
_080E3982:\n\
	cmp r3, #0x28\n\
	bne _080E398C\n\
	ldr r1, [r6]\n\
	movs r0, #5\n\
	strb r0, [r1, #1]\n\
_080E398C:\n\
	ldr r1, _080E39A4 @ =gPause\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	adds r1, r4, #0\n\
	adds r1, #0xc0\n\
	movs r0, #4\n\
	strb r0, [r1]\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
	b _080E39B6\n\
	.align 2, 0\n\
_080E39A0: .4byte 0xFFFF8000\n\
_080E39A4: .4byte gPause\n\
_080E39A8:\n\
	adds r1, r4, #0\n\
	adds r1, #0xc0\n\
	cmp r2, #1\n\
	bne _080E39B8\n\
	ldr r0, _080E39FC @ =gPause\n\
	strb r2, [r0]\n\
	adds r0, r3, #1\n\
_080E39B6:\n\
	strb r0, [r4, #0xd]\n\
_080E39B8:\n\
	ldrb r0, [r1]\n\
	subs r2, r0, #1\n\
	strb r2, [r1]\n\
	cmp r2, #0\n\
	bne _080E39E0\n\
	ldr r0, _080E39FC @ =gPause\n\
	strb r2, [r0]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080E3A00 @ =gElfFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #4\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0x10]\n\
	str r0, [r4, #0x14]\n\
_080E39E0:\n\
	lsls r0, r2, #4\n\
	subs r0, r0, r2\n\
	lsrs r0, r0, #2\n\
	ldr r2, _080E3A04 @ =wMOSAIC\n\
	movs r1, #0xf\n\
	ands r0, r1\n\
	lsls r1, r0, #4\n\
	orrs r1, r0\n\
	lsls r0, r1, #8\n\
	orrs r1, r0\n\
	strh r1, [r2]\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E39FC: .4byte gPause\n\
_080E3A00: .4byte gElfFnTable\n\
_080E3A04: .4byte wMOSAIC\n\
 .syntax divided\n");
}

static const u16 u16_ARRAY_08371d5c[7] = {
    0x0027, 0x0025, 0x0026, 0x0021, 0x0023, 0x0022, 0x0028,
};

static const u8 sFusionPenalties[7] = {
    5, 0, 1, 5, 1, 5, 1,
};
