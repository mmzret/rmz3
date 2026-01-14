#include "blink.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"

static void initOcean(struct Coord* _ UNUSED);
static void ocean_0800cbe8(struct Coord* _ UNUSED);
static void ocean_0800cfac(struct Coord* _ UNUSED);
static void exitOcean(struct Coord* _ UNUSED);

static const s32 sOceanSeaLevels[5];
static const struct Coord sSeaLevelButtonCoords[4];

static const StageFunc sStageRoutine[4] = {
    initOcean,
    ocean_0800cbe8,
    ocean_0800cfac,
    exitOcean,
};

NAKED static void initOcean(struct Coord* _ UNUSED) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	ldr r5, _0800CB8C @ =gOverworld\n\
	ldr r1, _0800CB90 @ =0x0002D028\n\
	adds r0, r5, r1\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	ldr r2, _0800CB94 @ =0x0002D029\n\
	adds r0, r5, r2\n\
	strb r1, [r0]\n\
	adds r2, #1\n\
	adds r0, r5, r2\n\
	strb r1, [r0]\n\
	ldr r0, _0800CB98 @ =gCurStory\n\
	ldrb r6, [r0, #9]\n\
	lsls r3, r6, #0x18\n\
	lsrs r0, r3, #0x19\n\
	movs r1, #1\n\
	adds r2, r1, #0\n\
	bics r2, r0\n\
	lsrs r4, r3, #0x1a\n\
	adds r0, r1, #0\n\
	bics r0, r4\n\
	adds r2, r2, r0\n\
	lsrs r3, r3, #0x1b\n\
	bics r1, r3\n\
	adds r2, r2, r1\n\
	movs r0, #0x10\n\
	ands r0, r6\n\
	cmp r0, #0\n\
	bne _0800CB9C\n\
	adds r0, r2, #1\n\
	b _0800CB9E\n\
	.align 2, 0\n\
_0800CB8C: .4byte gOverworld\n\
_0800CB90: .4byte 0x0002D028\n\
_0800CB94: .4byte 0x0002D029\n\
_0800CB98: .4byte gCurStory\n\
_0800CB9C:\n\
	adds r0, r2, #0\n\
_0800CB9E:\n\
	ldr r1, _0800CBD8 @ =0x0002C00C\n\
	adds r2, r5, r1\n\
	ldr r1, _0800CBDC @ =sOceanSeaLevels\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	str r0, [r2]\n\
	movs r0, #0\n\
_0800CBAE:\n\
	lsls r4, r0, #0x18\n\
	lsrs r0, r4, #0x18\n\
	asrs r4, r4, #0x18\n\
	lsls r1, r4, #3\n\
	ldr r2, _0800CBE0 @ =sSeaLevelButtonCoords\n\
	adds r1, r1, r2\n\
	bl CreateSeaLevelButton\n\
	lsls r1, r4, #2\n\
	ldr r2, _0800CBE4 @ =0x0202F22C\n\
	adds r1, r1, r2\n\
	str r0, [r1]\n\
	adds r4, #1\n\
	lsls r4, r4, #0x18\n\
	lsrs r0, r4, #0x18\n\
	asrs r4, r4, #0x18\n\
	cmp r4, #3\n\
	ble _0800CBAE\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0800CBD8: .4byte 0x0002C00C\n\
_0800CBDC: .4byte sOceanSeaLevels\n\
_0800CBE0: .4byte sSeaLevelButtonCoords\n\
_0800CBE4: .4byte 0x0202F22C\n\
 .syntax divided\n");
}

NAKED static void ocean_0800cbe8(struct Coord* _ UNUSED) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	ldr r2, _0800CC34 @ =gOverworld\n\
	ldr r1, _0800CC38 @ =0x000007D4\n\
	adds r0, r2, r1\n\
	ldrh r1, [r0]\n\
	lsrs r0, r1, #8\n\
	cmp r0, #3\n\
	bne _0800CC40\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0800CC40\n\
	ldr r0, _0800CC3C @ =0x0002D028\n\
	adds r2, r2, r0\n\
	ldrb r1, [r2]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0800CC24\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	movs r0, #0xe5\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0xe6\n\
	movs r1, #0\n\
	bl LoadBlink\n\
_0800CC24:\n\
	movs r0, #0xe5\n\
	bl UpdateBlinkMotionState\n\
	movs r0, #0xe6\n\
	bl UpdateBlinkMotionState\n\
	b _0800CC62\n\
	.align 2, 0\n\
_0800CC34: .4byte gOverworld\n\
_0800CC38: .4byte 0x000007D4\n\
_0800CC3C: .4byte 0x0002D028\n\
_0800CC40:\n\
	ldr r0, _0800CCC8 @ =gOverworld\n\
	ldr r1, _0800CCCC @ =0x0002D028\n\
	adds r2, r0, r1\n\
	ldrb r1, [r2]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0800CC62\n\
	movs r0, #1\n\
	eors r0, r1\n\
	strb r0, [r2]\n\
	movs r0, #0xe5\n\
	bl ClearBlink\n\
	movs r0, #0xe6\n\
	bl ClearBlink\n\
_0800CC62:\n\
	ldr r2, _0800CCC8 @ =gOverworld\n\
	ldr r1, _0800CCD0 @ =0x000007D6\n\
	adds r0, r2, r1\n\
	ldrh r1, [r0]\n\
	lsrs r0, r1, #8\n\
	cmp r0, #3\n\
	bne _0800CCD4\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	cmp r0, #1\n\
	bne _0800CCD4\n\
	ldr r0, _0800CCCC @ =0x0002D028\n\
	adds r2, r2, r0\n\
	ldrb r1, [r2]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0800CCAC\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	movs r0, #0xe7\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0xe8\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0xe9\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0xea\n\
	movs r1, #0\n\
	bl LoadBlink\n\
_0800CCAC:\n\
	movs r0, #0xe7\n\
	bl UpdateBlinkMotionState\n\
	movs r0, #0xe8\n\
	bl UpdateBlinkMotionState\n\
	movs r0, #0xe9\n\
	bl UpdateBlinkMotionState\n\
	movs r0, #0xea\n\
	bl UpdateBlinkMotionState\n\
	b _0800CD02\n\
	.align 2, 0\n\
_0800CCC8: .4byte gOverworld\n\
_0800CCCC: .4byte 0x0002D028\n\
_0800CCD0: .4byte 0x000007D6\n\
_0800CCD4:\n\
	ldr r0, _0800CD78 @ =gOverworld\n\
	ldr r1, _0800CD7C @ =0x0002D028\n\
	adds r2, r0, r1\n\
	ldrb r1, [r2]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0800CD02\n\
	movs r0, #2\n\
	eors r0, r1\n\
	strb r0, [r2]\n\
	movs r0, #0xe7\n\
	bl ClearBlink\n\
	movs r0, #0xe8\n\
	bl ClearBlink\n\
	movs r0, #0xe9\n\
	bl ClearBlink\n\
	movs r0, #0xea\n\
	bl ClearBlink\n\
_0800CD02:\n\
	ldr r5, _0800CD78 @ =gOverworld\n\
	ldr r2, _0800CD80 @ =0x000007D4\n\
	adds r0, r5, r2\n\
	ldrh r1, [r0]\n\
	lsrs r0, r1, #8\n\
	cmp r0, #3\n\
	bne _0800CD8C\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	cmp r0, #2\n\
	bne _0800CD8C\n\
	ldr r0, _0800CD7C @ =0x0002D028\n\
	adds r2, r5, r0\n\
	ldrb r1, [r2]\n\
	movs r0, #4\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #0\n\
	bne _0800CD44\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	movs r0, #0xeb\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	ldr r1, _0800CD84 @ =0x0002D029\n\
	adds r0, r5, r1\n\
	strb r4, [r0]\n\
	ldr r2, _0800CD88 @ =0x0002D02A\n\
	adds r0, r5, r2\n\
	strb r4, [r0]\n\
_0800CD44:\n\
	movs r0, #0xeb\n\
	bl UpdateBlinkMotionState\n\
	ldr r0, _0800CD84 @ =0x0002D029\n\
	adds r1, r5, r0\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	movs r2, #0\n\
	strb r0, [r1]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0x40\n\
	bne _0800CD60\n\
	strb r2, [r1]\n\
_0800CD60:\n\
	ldr r0, _0800CD88 @ =0x0002D02A\n\
	adds r1, r5, r0\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #9\n\
	bne _0800CDA8\n\
	strb r2, [r1]\n\
	b _0800CDA8\n\
	.align 2, 0\n\
_0800CD78: .4byte gOverworld\n\
_0800CD7C: .4byte 0x0002D028\n\
_0800CD80: .4byte 0x000007D4\n\
_0800CD84: .4byte 0x0002D029\n\
_0800CD88: .4byte 0x0002D02A\n\
_0800CD8C:\n\
	ldr r0, _0800CE0C @ =gOverworld\n\
	ldr r1, _0800CE10 @ =0x0002D028\n\
	adds r2, r0, r1\n\
	ldrb r1, [r2]\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0800CDA8\n\
	movs r0, #4\n\
	eors r0, r1\n\
	strb r0, [r2]\n\
	movs r0, #0xeb\n\
	bl ClearBlink\n\
_0800CDA8:\n\
	ldr r2, _0800CE0C @ =gOverworld\n\
	ldr r1, _0800CE14 @ =0x000007D4\n\
	adds r0, r2, r1\n\
	ldrh r1, [r0]\n\
	lsrs r0, r1, #8\n\
	cmp r0, #3\n\
	bne _0800CE18\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	cmp r0, #3\n\
	bne _0800CE18\n\
	ldr r0, _0800CE10 @ =0x0002D028\n\
	adds r2, r2, r0\n\
	ldrb r1, [r2]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0800CDF2\n\
	movs r0, #8\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	movs r0, #0xec\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0xed\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0xee\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0xef\n\
	movs r1, #0\n\
	bl LoadBlink\n\
_0800CDF2:\n\
	movs r0, #0xec\n\
	bl UpdateBlinkMotionState\n\
	movs r0, #0xed\n\
	bl UpdateBlinkMotionState\n\
	movs r0, #0xee\n\
	bl UpdateBlinkMotionState\n\
	movs r0, #0xef\n\
	bl UpdateBlinkMotionState\n\
	b _0800CE46\n\
	.align 2, 0\n\
_0800CE0C: .4byte gOverworld\n\
_0800CE10: .4byte 0x0002D028\n\
_0800CE14: .4byte 0x000007D4\n\
_0800CE18:\n\
	ldr r0, _0800CF80 @ =gOverworld\n\
	ldr r1, _0800CF84 @ =0x0002D028\n\
	adds r2, r0, r1\n\
	ldrb r1, [r2]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0800CE46\n\
	movs r0, #8\n\
	eors r0, r1\n\
	strb r0, [r2]\n\
	movs r0, #0xec\n\
	bl ClearBlink\n\
	movs r0, #0xed\n\
	bl ClearBlink\n\
	movs r0, #0xee\n\
	bl ClearBlink\n\
	movs r0, #0xef\n\
	bl ClearBlink\n\
_0800CE46:\n\
	ldr r0, _0800CF88 @ =gCurStory\n\
	ldrb r5, [r0, #9]\n\
	lsls r3, r5, #0x18\n\
	lsrs r0, r3, #0x19\n\
	movs r1, #1\n\
	adds r2, r1, #0\n\
	bics r2, r0\n\
	lsrs r4, r3, #0x1a\n\
	adds r0, r1, #0\n\
	bics r0, r4\n\
	adds r2, r2, r0\n\
	lsrs r3, r3, #0x1b\n\
	bics r1, r3\n\
	adds r1, r2, r1\n\
	movs r0, #0x10\n\
	ands r0, r5\n\
	cmp r0, #0\n\
	bne _0800CE6C\n\
	adds r1, #1\n\
_0800CE6C:\n\
	ldr r2, _0800CF80 @ =gOverworld\n\
	ldr r0, _0800CF8C @ =0x0002C00C\n\
	adds r4, r2, r0\n\
	ldr r0, _0800CF90 @ =sOceanSeaLevels\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	ldr r3, [r4]\n\
	ldr r0, [r1]\n\
	cmp r3, r0\n\
	bge _0800CE86\n\
	adds r0, r3, #0\n\
	adds r0, #0x40\n\
	str r0, [r4]\n\
_0800CE86:\n\
	ldr r0, _0800CF88 @ =gCurStory\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0800CEC6\n\
	movs r1, #0xfc\n\
	lsls r1, r1, #3\n\
	adds r2, r2, r1\n\
	ldrh r1, [r2]\n\
	movs r0, #0x34\n\
	muls r0, r1, r0\n\
	adds r0, #0xc0\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	ldrh r1, [r0]\n\
	movs r0, #0xe1\n\
	lsls r0, r0, #1\n\
	cmp r1, r0\n\
	bne _0800CEC6\n\
	ldr r4, _0800CF94 @ =MetatilePatch_0833ccf0\n\
	movs r0, #0xb6\n\
	movs r1, #0x34\n\
	adds r2, r4, #0\n\
	bl PatchMetatileMap\n\
	adds r4, #0xc\n\
	movs r0, #0xbe\n\
	movs r1, #0x34\n\
	adds r2, r4, #0\n\
	bl PatchMetatileMap\n\
_0800CEC6:\n\
	ldr r0, _0800CF88 @ =gCurStory\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0800CF0E\n\
	ldr r2, _0800CF80 @ =gOverworld\n\
	movs r0, #0xfc\n\
	lsls r0, r0, #3\n\
	adds r2, r2, r0\n\
	ldrh r1, [r2]\n\
	lsls r0, r1, #3\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #3\n\
	subs r0, r0, r1\n\
	ldr r1, _0800CF98 @ =0x00000139\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	ldrh r1, [r0]\n\
	movs r0, #0xe1\n\
	lsls r0, r0, #1\n\
	cmp r1, r0\n\
	bne _0800CF0E\n\
	subs r0, #0xa0\n\
	ldr r4, _0800CF94 @ =MetatilePatch_0833ccf0\n\
	movs r1, #0x37\n\
	adds r2, r4, #0\n\
	bl PatchMetatileMap\n\
	ldr r0, _0800CF9C @ =0x00000137\n\
	adds r4, #0xc\n\
	movs r1, #0x37\n\
	adds r2, r4, #0\n\
	bl PatchMetatileMap\n\
_0800CF0E:\n\
	ldr r0, _0800CF88 @ =gCurStory\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0800CF44\n\
	ldr r2, _0800CF80 @ =gOverworld\n\
	movs r0, #0xfc\n\
	lsls r0, r0, #3\n\
	adds r2, r2, r0\n\
	ldrh r1, [r2]\n\
	lsls r0, r1, #3\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #4\n\
	ldr r1, _0800CFA0 @ =0x0000043A\n\
	adds r0, r0, r1\n\
	adds r0, r0, r2\n\
	ldrh r1, [r0]\n\
	movs r0, #0xe1\n\
	lsls r0, r0, #1\n\
	cmp r1, r0\n\
	bne _0800CF44\n\
	adds r0, #0x59\n\
	ldr r2, _0800CFA4 @ =MetatilePatch_0833ccfc\n\
	movs r1, #0x38\n\
	bl PatchMetatileMap\n\
_0800CF44:\n\
	ldr r0, _0800CF88 @ =gCurStory\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0800CF7A\n\
	ldr r1, _0800CF80 @ =gOverworld\n\
	movs r2, #0xfc\n\
	lsls r2, r2, #3\n\
	adds r1, r1, r2\n\
	ldrh r2, [r1]\n\
	movs r0, #0x36\n\
	muls r0, r2, r0\n\
	ldr r2, _0800CFA8 @ =0x00000286\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #1\n\
	cmp r1, r0\n\
	bne _0800CF7A\n\
	adds r0, #0xc4\n\
	ldr r2, _0800CF94 @ =MetatilePatch_0833ccf0\n\
	movs r1, #0x36\n\
	bl PatchMetatileMap\n\
_0800CF7A:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0800CF80: .4byte gOverworld\n\
_0800CF84: .4byte 0x0002D028\n\
_0800CF88: .4byte gCurStory\n\
_0800CF8C: .4byte 0x0002C00C\n\
_0800CF90: .4byte sOceanSeaLevels\n\
_0800CF94: .4byte MetatilePatch_0833ccf0\n\
_0800CF98: .4byte 0x00000139\n\
_0800CF9C: .4byte 0x00000137\n\
_0800CFA0: .4byte 0x0000043A\n\
_0800CFA4: .4byte MetatilePatch_0833ccfc\n\
_0800CFA8: .4byte 0x00000286\n\
 .syntax divided\n");
}

NAKED static void ocean_0800cfac(struct Coord* _ UNUSED) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	ldr r7, _0800D054 @ =gOverworld\n\
	ldr r1, _0800D058 @ =0x000007D4\n\
	adds r0, r7, r1\n\
	ldrh r1, [r0]\n\
	lsrs r0, r1, #8\n\
	cmp r0, #3\n\
	bne _0800D04A\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	cmp r0, #2\n\
	bne _0800D04A\n\
	ldr r6, _0800D05C @ =gStageTilesetOffsets+(18*4)\n\
	ldr r0, _0800D060 @ =0x0002D029\n\
	adds r5, r7, r0\n\
	ldrb r0, [r5]\n\
	lsrs r0, r0, #3\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	ldr r4, _0800D064 @ =0x0870518C\n\
	adds r1, r1, r4\n\
	ldr r0, [r6]\n\
	adds r0, r0, r1\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	mov r8, r1\n\
	bl RequestGraphicTransfer\n\
	ldrb r0, [r5]\n\
	lsrs r0, r0, #3\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r4\n\
	ldr r0, [r6]\n\
	adds r0, r0, r1\n\
	adds r0, #0xc\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	ldr r0, _0800D068 @ =0x0002D02A\n\
	adds r5, r7, r0\n\
	movs r0, #0\n\
	ldrsb r0, [r5, r0]\n\
	movs r1, #3\n\
	bl __divsi3\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r4, #0xa0\n\
	adds r1, r1, r4\n\
	ldr r0, [r6]\n\
	adds r0, r0, r1\n\
	mov r1, r8\n\
	bl RequestGraphicTransfer\n\
	movs r0, #0\n\
	ldrsb r0, [r5, r0]\n\
	movs r1, #3\n\
	bl __divsi3\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r4\n\
	ldr r0, [r6]\n\
	adds r0, r0, r1\n\
	adds r0, #0xc\n\
	movs r1, #0\n\
	bl LoadPalette\n\
_0800D04A:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0800D054: .4byte gOverworld\n\
_0800D058: .4byte 0x000007D4\n\
_0800D05C: .4byte gStageTilesetOffsets+(18*4)\n\
_0800D060: .4byte 0x0002D029\n\
_0800D064: .4byte 0x0870518C\n\
_0800D068: .4byte 0x0002D02A\n\
 .syntax divided\n");
}

static void exitOcean(struct Coord* _ UNUSED) {
  s8 i;
  ClearBlink(229);
  ClearBlink(230);
  ClearBlink(231);
  ClearBlink(232);
  ClearBlink(233);
  ClearBlink(234);
  ClearBlink(235);
  ClearBlink(236);
  ClearBlink(237);
  ClearBlink(238);
  ClearBlink(239);
  for (i = 0; i < 4; i++) {
    struct Solid* btn = (*(&gOverworld.work.ocean.btns))[i];
    (btn->s).flags &= ~DISPLAY;
    (btn->s).flags &= ~FLIPABLE;
    (btn->body).status = 0;
    (btn->body).prevStatus = 0;
    (btn->body).invincibleTime = 0;
    (btn->s).flags &= ~COLLIDABLE;
    SET_SOLID_ROUTINE(btn, ENTITY_DISAPPEAR);
  }
}

INCASM("asm/stage_gfx/ocean.inc");

void ocean_0800d110(struct StageLayer* l, const struct Stage* stage);
void FUN_0800d1c8(struct StageLayer* l, const struct Stage* stage);
void FUN_0800d264(struct StageLayer* l, const struct Stage* stage);
void ocean_0800d28c(struct StageLayer* l, const struct Stage* stage);
void ctrlOceanBG3Scroll(struct StageLayer* l, const struct Stage* stage);
void ocean_0800d488(struct StageLayer* l, const struct Stage* stage);
void setOceanBGScroll(struct StageLayer* l, const struct Stage* stage);
void ocean_0800d544(struct StageLayer* l, const struct Stage* stage);
void ocean_0800d568(struct StageLayer* l, const struct Stage* stage);

// clang-format off
static const StageLayerRoutine sLayerRoutine[7] = {
    [0] = {NULL, NULL, NULL},
    [1] = {NULL, DrawGeneralStageLayer, NULL},
    [2] = {ocean_0800d110, FUN_0800d1c8, FUN_0800d264},
    [3] = {ocean_0800d28c, ctrlOceanBG3Scroll, NULL},
    [4] = {ocean_0800d488, setOceanBGScroll, NULL},
    [5] = {ocean_0800d544, DrawGeneralStageLayer, NULL},
    [6] = {ocean_0800d568, DrawGeneralStageLayer, NULL},
};
// clang-format on

#include "stage/ocean/layer.h"

static const s32 sOceanSeaLevels[5] = {
    0x30000, 0x2C000, 0x28000, 0x24000, 0x20000,
};

const struct MetatilePatch MetatilePatch_0833ccf0 = {
  w : 1,
  h : 4,
};
const metatile_id_t MetatilePatchData_0833ccf0[4] = {0x1C1, 0x1D1, 0x1E1, 0x1F1};

const struct MetatilePatch MetatilePatch_0833ccfc = {
  w : 1,
  h : 4,
};
const metatile_id_t MetatilePatchData_0833ccfc[4] = {0x1C3, 0x1D3, 0x1E3, 0x1F3};

static const struct Coord sSeaLevelButtonCoords[4] = {
    [0] = {0xBA800, 0x37000},
    [1] = {0x125800, 0x3A000},
    [2] = {0x219800, 0x3A000},
    [3] = {0x260800, 0x38000},
};

#include "stage/ocean/landscape.h"

const struct MetatilePatch MetatilePatch_0833cda8 = {
  w : 2,
  h : 2,
};
const metatile_id_t MetatilePatchData_0833cda8[4] = {0, 0, 0, 0};
