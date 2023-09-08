#include "global.h"
#include "overworld.h"

NAKED s16 SubArcadia_MissionUpdate(struct StageRun* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #8\n\
	adds r7, r0, #0\n\
	ldr r6, [r7, #0x20]\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	mov r8, r1\n\
	adds r5, r7, r1\n\
	ldrb r4, [r5]\n\
	cmp r4, #0\n\
	beq _0802011C\n\
	b _080202BC\n\
_0802011C:\n\
	ldr r3, _0802015C @ =gStageRun\n\
	ldrh r1, [r3, #8]\n\
	movs r2, #1\n\
	mov sl, r2\n\
	movs r2, #0\n\
	mov r8, r2\n\
	mov r2, sl\n\
	orrs r1, r2\n\
	strh r1, [r3, #8]\n\
	ldr r6, _08020160 @ =gCurStory\n\
	ldrb r1, [r6, #4]\n\
	movs r2, #0xfb\n\
	ands r2, r1\n\
	movs r1, #0\n\
	mov sb, r1\n\
	strb r2, [r6, #4]\n\
	ldrb r4, [r3, #2]\n\
	cmp r4, #0\n\
	bne _08020198\n\
	movs r0, #0x20\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _08020168\n\
	adds r0, r3, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020164 @ =gStageScriptList\n\
	ldr r1, [r1, #0x3c]\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
	b _08020176\n\
	.align 2, 0\n\
_0802015C: .4byte gStageRun\n\
_08020160: .4byte gCurStory\n\
_08020164: .4byte gStageScriptList\n\
_08020168:\n\
	adds r0, r3, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020190 @ =gStageScriptList\n\
	ldr r1, [r1, #0x3c]\n\
	ldr r1, [r1, #0x3c]\n\
	bl SetScript\n\
_08020176:\n\
	movs r0, #1\n\
	bl setStageCheckpoint\n\
	ldr r1, _08020194 @ =0x0000017D\n\
	adds r2, r7, r1\n\
	movs r1, #0\n\
	strb r1, [r2]\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r2, r7, r1\n\
	movs r1, #1\n\
	strb r1, [r2]\n\
	b _0802062E\n\
	.align 2, 0\n\
_08020190: .4byte gStageScriptList\n\
_08020194: .4byte 0x0000017D\n\
_08020198:\n\
	cmp r4, #1\n\
	bne _080201C4\n\
	adds r0, r3, #0\n\
	adds r0, #0x10\n\
	ldr r1, _080201BC @ =gStageScriptList\n\
	ldr r1, [r1, #0x3c]\n\
	ldr r1, [r1, #4]\n\
	bl SetScript\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	ldr r2, _080201C0 @ =0x0000017D\n\
	adds r1, r7, r2\n\
	mov r2, r8\n\
	strb r2, [r1]\n\
	movs r1, #2\n\
	b _0802062C\n\
	.align 2, 0\n\
_080201BC: .4byte gStageScriptList\n\
_080201C0: .4byte 0x0000017D\n\
_080201C4:\n\
	cmp r4, #2\n\
	bne _080201EC\n\
	adds r0, r3, #0\n\
	adds r0, #0x10\n\
	ldr r1, _080201E4 @ =gStageScriptList\n\
	ldr r1, [r1, #0x3c]\n\
	ldr r1, [r1, #8]\n\
	bl SetScript\n\
	ldr r2, _080201E8 @ =0x0000017D\n\
	adds r1, r7, r2\n\
	mov r2, r8\n\
	strb r2, [r1]\n\
	strb r4, [r5]\n\
	b _0802062E\n\
	.align 2, 0\n\
_080201E4: .4byte gStageScriptList\n\
_080201E8: .4byte 0x0000017D\n\
_080201EC:\n\
	cmp r4, #3\n\
	bne _08020220\n\
	adds r0, r3, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020218 @ =gStageScriptList\n\
	ldr r1, [r1, #0x3c]\n\
	ldr r1, [r1, #0xc]\n\
	bl SetScript\n\
	ldrb r0, [r6, #4]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	strb r0, [r6, #4]\n\
	bl ApplyCyberSpaceColorFilter\n\
	ldr r1, _0802021C @ =0x0000017D\n\
	adds r0, r7, r1\n\
	mov r2, sl\n\
	strb r2, [r0]\n\
	movs r0, #2\n\
	strb r0, [r5]\n\
	b _0802062E\n\
	.align 2, 0\n\
_08020218: .4byte gStageScriptList\n\
_0802021C: .4byte 0x0000017D\n\
_08020220:\n\
	cmp r4, #4\n\
	bne _08020254\n\
	adds r0, r3, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0802024C @ =gStageScriptList\n\
	ldr r1, [r1, #0x3c]\n\
	ldr r1, [r1, #0x18]\n\
	bl SetScript\n\
	ldrb r0, [r6, #4]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	strb r0, [r6, #4]\n\
	bl ApplyCyberSpaceColorFilter\n\
	ldr r0, _08020250 @ =0x0000017D\n\
	adds r1, r7, r0\n\
	movs r0, #2\n\
	strb r0, [r1]\n\
	movs r0, #3\n\
	strb r0, [r5]\n\
	b _0802062E\n\
	.align 2, 0\n\
_0802024C: .4byte gStageScriptList\n\
_08020250: .4byte 0x0000017D\n\
_08020254:\n\
	cmp r4, #5\n\
	bne _08020270\n\
	adds r0, r3, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0802026C @ =gStageScriptList\n\
	ldr r1, [r1, #0x3c]\n\
	ldr r1, [r1, #0x20]\n\
	bl SetScript\n\
	movs r1, #4\n\
	b _0802062C\n\
	.align 2, 0\n\
_0802026C: .4byte gStageScriptList\n\
_08020270:\n\
	cmp r4, #6\n\
	bne _0802028C\n\
	adds r0, r3, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020288 @ =gStageScriptList\n\
	ldr r1, [r1, #0x3c]\n\
	ldr r1, [r1, #0x24]\n\
	bl SetScript\n\
	movs r1, #5\n\
	b _0802062C\n\
	.align 2, 0\n\
_08020288: .4byte gStageScriptList\n\
_0802028C:\n\
	cmp r4, #7\n\
	bne _080202A0\n\
	adds r0, r3, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0802029C @ =gStageScriptList\n\
	ldr r1, [r1, #0x3c]\n\
	ldr r1, [r1, #0x28]\n\
	b _080202B0\n\
	.align 2, 0\n\
_0802029C: .4byte gStageScriptList\n\
_080202A0:\n\
	cmp r4, #8\n\
	beq _080202A6\n\
	b _0802062E\n\
_080202A6:\n\
	adds r0, r3, #0\n\
	adds r0, #0x10\n\
	ldr r1, _080202B8 @ =gStageScriptList\n\
	ldr r1, [r1, #0x3c]\n\
	ldr r1, [r1, #0x34]\n\
_080202B0:\n\
	bl SetScript\n\
	strb r4, [r5]\n\
	b _0802062E\n\
	.align 2, 0\n\
_080202B8: .4byte gStageScriptList\n\
_080202BC:\n\
	cmp r4, #1\n\
	bne _080202CA\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	movs r1, #2\n\
	b _0802062C\n\
_080202CA:\n\
	cmp r4, #2\n\
	bne _080202F4\n\
	ldr r2, [r6, #0x54]\n\
	ldr r1, _080202E0 @ =0x00068FFF\n\
	cmp r2, r1\n\
	ble _080202E4\n\
	movs r0, #4\n\
	bl setStageCheckpoint\n\
	movs r1, #3\n\
	b _0802062C\n\
	.align 2, 0\n\
_080202E0: .4byte 0x00068FFF\n\
_080202E4:\n\
	ldr r1, _080202F0 @ =0x00059FFF\n\
	cmp r2, r1\n\
	bgt _080202EC\n\
	b _0802062E\n\
_080202EC:\n\
	movs r1, #4\n\
	b _0802062C\n\
	.align 2, 0\n\
_080202F0: .4byte 0x00059FFF\n\
_080202F4:\n\
	cmp r4, #3\n\
	beq _080202FA\n\
	b _0802045C\n\
_080202FA:\n\
	ldr r1, _08020314 @ =0x0000017D\n\
	adds r5, r7, r1\n\
	ldrb r1, [r5]\n\
	cmp r1, #0\n\
	bne _08020320\n\
	ldr r0, _08020318 @ =gStageRun+16\n\
	ldr r1, _0802031C @ =gStageScriptList\n\
	ldr r1, [r1, #0x3c]\n\
	ldr r1, [r1, #0x10]\n\
	bl SetScript\n\
	movs r1, #2\n\
	b _0802062C\n\
	.align 2, 0\n\
_08020314: .4byte 0x0000017D\n\
_08020318: .4byte gStageRun+16\n\
_0802031C: .4byte gStageScriptList\n\
_08020320:\n\
	cmp r1, #1\n\
	bne _0802033C\n\
	ldr r0, _08020334 @ =gStageRun+16\n\
	ldr r1, _08020338 @ =gStageScriptList\n\
	ldr r1, [r1, #0x3c]\n\
	ldr r1, [r1, #0x14]\n\
	bl SetScript\n\
	movs r1, #2\n\
	b _0802062C\n\
	.align 2, 0\n\
_08020334: .4byte gStageRun+16\n\
_08020338: .4byte gStageScriptList\n\
_0802033C:\n\
	cmp r1, #2\n\
	bne _0802034A\n\
	movs r0, #3\n\
	bl setStageCheckpoint\n\
	strb r4, [r5]\n\
	b _0802062E\n\
_0802034A:\n\
	cmp r1, #3\n\
	bne _080203DC\n\
	ldr r5, _080203B8 @ =gStageRun\n\
	ldrh r2, [r5, #8]\n\
	movs r1, #0x10\n\
	ands r1, r2\n\
	cmp r1, #0\n\
	bne _0802035C\n\
	b _0802062E\n\
_0802035C:\n\
	ldr r2, _080203BC @ =gCollisionManager\n\
	ldrb r0, [r2]\n\
	movs r4, #0x80\n\
	orrs r0, r4\n\
	strb r0, [r2]\n\
	ldrb r0, [r2, #1]\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	adds r0, r5, #0\n\
	adds r0, #0x10\n\
	ldr r1, _080203C0 @ =gStageScriptList\n\
	ldr r1, [r1, #0x3c]\n\
	ldr r1, [r1, #0x1c]\n\
	bl SetScript\n\
	ldrh r1, [r5, #8]\n\
	ldr r2, _080203C4 @ =0x0000FFEF\n\
	ands r2, r1\n\
	ldrb r3, [r5, #0x12]\n\
	movs r1, #0xfd\n\
	ands r1, r3\n\
	strb r1, [r5, #0x12]\n\
	movs r1, #1\n\
	movs r6, #0\n\
	orrs r2, r1\n\
	strh r2, [r5, #8]\n\
	ldr r2, _080203C8 @ =gCurStory\n\
	ldrb r1, [r2, #6]\n\
	orrs r1, r4\n\
	strb r1, [r2, #6]\n\
	ldrb r3, [r2, #4]\n\
	movs r1, #4\n\
	orrs r1, r3\n\
	strb r1, [r2, #4]\n\
	ldr r2, _080203CC @ =gMission\n\
	movs r1, #7\n\
	ldrsb r1, [r2, r1]\n\
	adds r1, #5\n\
	cmp r1, #0\n\
	ble _080203D0\n\
	ldrb r1, [r2, #7]\n\
	adds r1, #5\n\
	strb r1, [r2, #7]\n\
	b _080203D2\n\
	.align 2, 0\n\
_080203B8: .4byte gStageRun\n\
_080203BC: .4byte gCollisionManager\n\
_080203C0: .4byte gStageScriptList\n\
_080203C4: .4byte 0x0000FFEF\n\
_080203C8: .4byte gCurStory\n\
_080203CC: .4byte gMission\n\
_080203D0:\n\
	strb r6, [r2, #7]\n\
_080203D2:\n\
	ldr r1, _080203D8 @ =0x0000017D\n\
	b _08020446\n\
	.align 2, 0\n\
_080203D8: .4byte 0x0000017D\n\
_080203DC:\n\
	cmp r1, #4\n\
	bne _0802040C\n\
	ldr r0, _08020404 @ =Coord_080fecdc\n\
	ldr r1, [r0, #4]\n\
	ldr r0, [r0]\n\
	str r0, [sp]\n\
	str r1, [sp, #4]\n\
	movs r0, #0xf\n\
	mov r1, sp\n\
	bl TryDropItem\n\
	ldr r2, _08020408 @ =gCollisionManager\n\
	ldrb r3, [r2]\n\
	movs r1, #0x7f\n\
	ands r1, r3\n\
	movs r3, #0\n\
	strb r1, [r2]\n\
	strb r3, [r2, #1]\n\
	movs r1, #5\n\
	b _0802062C\n\
	.align 2, 0\n\
_08020404: .4byte Coord_080fecdc\n\
_08020408: .4byte gCollisionManager\n\
_0802040C:\n\
	cmp r1, #5\n\
	beq _08020412\n\
	b _0802062E\n\
_08020412:\n\
	ldr r1, _08020450 @ =gStageDiskManager\n\
	ldr r1, [r1]\n\
	ldrb r2, [r1, #1]\n\
	movs r1, #0xf\n\
	ands r1, r2\n\
	lsrs r1, r1, #1\n\
	movs r2, #1\n\
	ands r1, r2\n\
	cmp r1, #0\n\
	beq _08020430\n\
	ldr r3, _08020454 @ =gCurStory\n\
	ldrb r2, [r3, #4]\n\
	movs r1, #0xfb\n\
	ands r1, r2\n\
	strb r1, [r3, #4]\n\
_08020430:\n\
	ldr r2, [r6, #0x54]\n\
	ldr r1, _08020458 @ =0x0001DFFF\n\
	cmp r2, r1\n\
	bgt _0802043A\n\
	b _0802062E\n\
_0802043A:\n\
	movs r0, #5\n\
	bl setStageCheckpoint\n\
	movs r1, #6\n\
	strb r1, [r5]\n\
	mov r1, r8\n\
_08020446:\n\
	adds r2, r7, r1\n\
	movs r1, #4\n\
	strb r1, [r2]\n\
	b _0802062E\n\
	.align 2, 0\n\
_08020450: .4byte gStageDiskManager\n\
_08020454: .4byte gCurStory\n\
_08020458: .4byte 0x0001DFFF\n\
_0802045C:\n\
	cmp r4, #4\n\
	bne _08020478\n\
	ldr r2, [r6, #0x54]\n\
	ldr r1, _08020474 @ =0x00059FFF\n\
	cmp r2, r1\n\
	bgt _0802046A\n\
	b _0802062E\n\
_0802046A:\n\
	movs r0, #6\n\
	bl setStageCheckpoint\n\
	movs r1, #5\n\
	b _0802062C\n\
	.align 2, 0\n\
_08020474: .4byte 0x00059FFF\n\
_08020478:\n\
	cmp r4, #5\n\
	bne _08020520\n\
	ldr r2, [r6, #0x54]\n\
	ldr r1, _080204B0 @ =0x000D0FFF\n\
	cmp r2, r1\n\
	ble _080204CA\n\
	ldr r1, _080204B4 @ =gCurStory\n\
	ldrb r2, [r1, #4]\n\
	movs r1, #0x20\n\
	ands r1, r2\n\
	cmp r1, #0\n\
	bne _080204BC\n\
	ldr r1, _080204B8 @ =gStageRun\n\
	movs r2, #0xb4\n\
	lsls r2, r2, #1\n\
	adds r5, r1, r2\n\
	ldr r1, [r5]\n\
	movs r4, #1\n\
	rsbs r4, r4, #0\n\
	cmp r1, r4\n\
	beq _080204CA\n\
	lsls r0, r1, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r4, [r5]\n\
	b _080204CA\n\
	.align 2, 0\n\
_080204B0: .4byte 0x000D0FFF\n\
_080204B4: .4byte gCurStory\n\
_080204B8: .4byte gStageRun\n\
_080204BC:\n\
	ldr r3, _08020514 @ =gCollisionManager\n\
	ldrb r2, [r3, #1]\n\
	movs r1, #2\n\
	orrs r1, r2\n\
	strb r1, [r3, #1]\n\
	movs r1, #6\n\
	strb r1, [r5]\n\
_080204CA:\n\
	ldr r2, [r6, #0x54]\n\
	ldr r1, _08020518 @ =0x000D2FFF\n\
	cmp r2, r1\n\
	bgt _080204D4\n\
	b _0802062E\n\
_080204D4:\n\
	ldr r3, _08020514 @ =gCollisionManager\n\
	ldrb r2, [r3, #1]\n\
	movs r1, #2\n\
	orrs r1, r2\n\
	strb r1, [r3, #1]\n\
	ldr r1, _0802051C @ =gStageRun\n\
	movs r2, #0xb4\n\
	lsls r2, r2, #1\n\
	adds r4, r1, r2\n\
	ldr r1, [r4]\n\
	cmp r1, #0xa1\n\
	beq _08020508\n\
	movs r5, #1\n\
	rsbs r5, r5, #0\n\
	cmp r1, r5\n\
	beq _080204FE\n\
	lsls r0, r1, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r5, [r4]\n\
_080204FE:\n\
	movs r0, #0xa1\n\
	bl playBGM\n\
	movs r1, #0xa1\n\
	str r1, [r4]\n\
_08020508:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r2, r7, r1\n\
	movs r1, #6\n\
	strb r1, [r2]\n\
	b _0802062E\n\
	.align 2, 0\n\
_08020514: .4byte gCollisionManager\n\
_08020518: .4byte 0x000D2FFF\n\
_0802051C: .4byte gStageRun\n\
_08020520:\n\
	cmp r4, #6\n\
	bne _08020598\n\
	ldr r2, [r6, #0x54]\n\
	ldr r1, _0802054C @ =0x000E0FFF\n\
	cmp r2, r1\n\
	ble _08020598\n\
	ldr r1, _08020550 @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r0, _08020554 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08020560\n\
	ldr r0, _08020558 @ =gStageRun+16\n\
	ldr r1, _0802055C @ =gStageScriptList\n\
	ldr r1, [r1, #0x3c]\n\
	ldr r1, [r1, #0x2c]\n\
	bl SetScript\n\
	b _08020578\n\
	.align 2, 0\n\
_0802054C: .4byte 0x000E0FFF\n\
_08020550: .4byte gCollisionManager\n\
_08020554: .4byte gCurStory\n\
_08020558: .4byte gStageRun+16\n\
_0802055C: .4byte gStageScriptList\n\
_08020560:\n\
	ldr r4, _0802058C @ =gStageRun+16\n\
	ldr r0, _08020590 @ =gStageScriptList\n\
	ldr r0, [r0, #0x3c]\n\
	ldr r1, [r0, #0x40]\n\
	adds r0, r4, #0\n\
	bl SetScript\n\
	subs r4, #0x10\n\
	ldrh r1, [r4, #8]\n\
	ldr r0, _08020594 @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r4, #8]\n\
_08020578:\n\
	movs r0, #8\n\
	bl setStageCheckpoint\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r2, r7, r1\n\
	movs r1, #8\n\
	strb r1, [r2]\n\
	b _0802062E\n\
	.align 2, 0\n\
_0802058C: .4byte gStageRun+16\n\
_08020590: .4byte gStageScriptList\n\
_08020594: .4byte 0x0000FFFE\n\
_08020598:\n\
	movs r2, #0xbe\n\
	lsls r2, r2, #1\n\
	adds r4, r7, r2\n\
	ldrb r1, [r4]\n\
	cmp r1, #7\n\
	bne _080205D0\n\
	ldr r2, [r6, #0x54]\n\
	ldr r1, _080205C4 @ =0x000E0FFF\n\
	cmp r2, r1\n\
	ble _080205D0\n\
	ldr r0, _080205C8 @ =gStageRun+16\n\
	ldr r1, _080205CC @ =gStageScriptList\n\
	ldr r1, [r1, #0x3c]\n\
	ldr r1, [r1, #0x30]\n\
	bl SetScript\n\
	movs r0, #8\n\
	bl setStageCheckpoint\n\
	movs r1, #8\n\
	strb r1, [r4]\n\
	b _0802062E\n\
	.align 2, 0\n\
_080205C4: .4byte 0x000E0FFF\n\
_080205C8: .4byte gStageRun+16\n\
_080205CC: .4byte gStageScriptList\n\
_080205D0:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r5, r7, r1\n\
	ldrb r1, [r5]\n\
	cmp r1, #8\n\
	bne _080205E6\n\
	movs r0, #7\n\
	bl setStageCheckpoint\n\
	movs r1, #9\n\
	b _0802062C\n\
_080205E6:\n\
	cmp r1, #9\n\
	bne _0802062E\n\
	ldr r4, _08020640 @ =gStageRun\n\
	ldrh r2, [r4, #8]\n\
	movs r1, #0x10\n\
	ands r1, r2\n\
	cmp r1, #0\n\
	beq _0802062E\n\
	ldr r1, _08020644 @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x80\n\
	orrs r0, r2\n\
	strb r0, [r1]\n\
	ldrb r2, [r1, #1]\n\
	movs r0, #2\n\
	orrs r0, r2\n\
	strb r0, [r1, #1]\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020648 @ =gStageScriptList\n\
	ldr r1, [r1, #0x3c]\n\
	ldr r1, [r1, #0x38]\n\
	bl SetScript\n\
	ldrh r1, [r4, #8]\n\
	ldr r2, _0802064C @ =0x0000FFEF\n\
	ands r2, r1\n\
	ldrb r3, [r4, #0x12]\n\
	movs r1, #0xfd\n\
	ands r1, r3\n\
	strb r1, [r4, #0x12]\n\
	movs r1, #4\n\
	orrs r2, r1\n\
	strh r2, [r4, #8]\n\
	movs r1, #0xa\n\
_0802062C:\n\
	strb r1, [r5]\n\
_0802062E:\n\
	add sp, #8\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_08020640: .4byte gStageRun\n\
_08020644: .4byte gCollisionManager\n\
_08020648: .4byte gStageScriptList\n\
_0802064C: .4byte 0x0000FFEF\n\
 .syntax divided\n");
}

s16 SubArcadia_FreeUpdate(struct StageRun* p) { return SubArcadia_MissionUpdate(p); }
