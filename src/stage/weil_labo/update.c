#include "global.h"
#include "overworld.h"

NAKED s16 WeilLabo_MissionUpdate(struct StageRun* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	mov r8, r0\n\
	ldr r7, [r0, #0x20]\n\
	movs r6, #0xbe\n\
	lsls r6, r6, #1\n\
	add r6, r8\n\
	ldrb r0, [r6]\n\
	cmp r0, #0\n\
	beq _0802067A\n\
	b _080209BC\n\
_0802067A:\n\
	ldr r4, _080206E8 @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	strh r0, [r4, #8]\n\
	ldr r2, _080206EC @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	ldrb r5, [r4, #2]\n\
	cmp r5, #0\n\
	bne _080206F8\n\
	movs r0, #0\n\
	adds r4, #0x10\n\
	mov sb, r4\n\
	ldr r7, _080206F0 @ =gStageScriptList\n\
	ldr r6, _080206F4 @ =u16_ARRAY_0834cfc4\n\
	adds r5, r2, #4\n\
_080206A0:\n\
	lsls r2, r0, #0x10\n\
	asrs r2, r2, #0x10\n\
	lsls r0, r2, #1\n\
	adds r0, r0, r6\n\
	ldrh r1, [r0]\n\
	lsrs r3, r1, #3\n\
	adds r3, r3, r5\n\
	movs r0, #7\n\
	ands r0, r1\n\
	movs r4, #1\n\
	adds r1, r4, #0\n\
	lsls r1, r0\n\
	ldrb r0, [r3]\n\
	bics r0, r1\n\
	strb r0, [r3]\n\
	adds r2, #1\n\
	lsls r2, r2, #0x10\n\
	lsrs r0, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	cmp r2, #7\n\
	ble _080206A0\n\
	ldr r0, [r7, #0x40]\n\
	ldr r1, [r0]\n\
	mov r0, sb\n\
	bl SetScript\n\
	movs r0, #1\n\
	bl setStageCheckpoint\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	add r0, r8\n\
	strb r4, [r0]\n\
	bl _0802153A\n\
	.align 2, 0\n\
_080206E8: .4byte gStageRun\n\
_080206EC: .4byte gCurStory\n\
_080206F0: .4byte gStageScriptList\n\
_080206F4: .4byte u16_ARRAY_0834cfc4\n\
_080206F8:\n\
	cmp r5, #1\n\
	bne _08020710\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0802070C @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #4]\n\
	bl SetScript\n\
	b _080209C0\n\
	.align 2, 0\n\
_0802070C: .4byte gStageScriptList\n\
_08020710:\n\
	cmp r5, #2\n\
	bne _08020724\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020720 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #8]\n\
	b _0802076C\n\
	.align 2, 0\n\
_08020720: .4byte gStageScriptList\n\
_08020724:\n\
	cmp r5, #3\n\
	bne _08020744\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020740 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0xc]\n\
	bl SetScript\n\
	movs r0, #4\n\
	strb r0, [r6]\n\
	bl _0802153A\n\
	.align 2, 0\n\
_08020740: .4byte gStageScriptList\n\
_08020744:\n\
	cmp r5, #4\n\
	bne _08020780\n\
	movs r0, #0xaa\n\
	lsls r0, r0, #1\n\
	adds r1, r4, r0\n\
	movs r0, #1\n\
	str r0, [r1]\n\
	ldrh r0, [r4, #0xa]\n\
	lsrs r0, r0, #8\n\
	ldr r1, _08020778 @ =0x0000017D\n\
	add r1, r8\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r2, _0802077C @ =gStageScriptList\n\
	ldrb r1, [r1]\n\
	ldr r2, [r2, #0x40]\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r2\n\
	ldr r1, [r1, #0x10]\n\
_0802076C:\n\
	bl SetScript\n\
	strb r5, [r6]\n\
	bl _0802153A\n\
	.align 2, 0\n\
_08020778: .4byte 0x0000017D\n\
_0802077C: .4byte gStageScriptList\n\
_08020780:\n\
	cmp r5, #5\n\
	bne _080207A0\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0802079C @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x34]\n\
	bl SetScript\n\
	movs r0, #7\n\
	strb r0, [r6]\n\
	bl _0802153A\n\
	.align 2, 0\n\
_0802079C: .4byte gStageScriptList\n\
_080207A0:\n\
	cmp r5, #6\n\
	bne _080207B4\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _080207B0 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x38]\n\
	b _080207DC\n\
	.align 2, 0\n\
_080207B0: .4byte gStageScriptList\n\
_080207B4:\n\
	cmp r5, #7\n\
	bne _080207F0\n\
	movs r2, #0xaa\n\
	lsls r2, r2, #1\n\
	adds r1, r4, r2\n\
	movs r0, #1\n\
	str r0, [r1]\n\
	ldrh r0, [r4, #0xa]\n\
	lsrs r0, r0, #8\n\
	ldr r1, _080207E8 @ =0x0000017D\n\
	add r1, r8\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r2, _080207EC @ =gStageScriptList\n\
	ldrb r1, [r1]\n\
	ldr r2, [r2, #0x40]\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r2\n\
	ldr r1, [r1, #0x1c]\n\
_080207DC:\n\
	bl SetScript\n\
	movs r0, #9\n\
	strb r0, [r6]\n\
	bl _0802153A\n\
	.align 2, 0\n\
_080207E8: .4byte 0x0000017D\n\
_080207EC: .4byte gStageScriptList\n\
_080207F0:\n\
	cmp r5, #8\n\
	bne _08020810\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0802080C @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x60]\n\
	bl SetScript\n\
	movs r0, #0xc\n\
	strb r0, [r6]\n\
	bl _0802153A\n\
	.align 2, 0\n\
_0802080C: .4byte gStageScriptList\n\
_08020810:\n\
	ldrb r0, [r4, #2]\n\
	cmp r0, #9\n\
	bne _0802082C\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020828 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x64]\n\
	bl SetScript\n\
	bl FUN_08021164\n\
	.align 2, 0\n\
_08020828: .4byte gStageScriptList\n\
_0802082C:\n\
	cmp r0, #0xa\n\
	bne _08020860\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0802085C @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x70]\n\
	bl SetScript\n\
	ldrh r1, [r4, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	strh r0, [r4, #0xa]\n\
	movs r0, #9\n\
	bl setStageCheckpoint\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	add r1, r8\n\
	movs r0, #0xf\n\
	strb r0, [r1]\n\
	bl _0802153A\n\
	.align 2, 0\n\
_0802085C: .4byte gStageScriptList\n\
_08020860:\n\
	cmp r0, #0xb\n\
	bne _08020894\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020890 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x7c]\n\
	bl SetScript\n\
	ldrh r1, [r4, #0xa]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strh r0, [r4, #0xa]\n\
	movs r0, #9\n\
	bl setStageCheckpoint\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	add r1, r8\n\
	movs r0, #0x11\n\
	strb r0, [r1]\n\
	bl _0802153A\n\
	.align 2, 0\n\
_08020890: .4byte gStageScriptList\n\
_08020894:\n\
	cmp r0, #0xc\n\
	bne _080208C8\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _080208C4 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	adds r1, #0x88\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
	ldrh r1, [r4, #0xa]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strh r0, [r4, #0xa]\n\
	movs r0, #9\n\
	bl setStageCheckpoint\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	add r1, r8\n\
	movs r0, #0x13\n\
	strb r0, [r1]\n\
	bl _0802153A\n\
	.align 2, 0\n\
_080208C4: .4byte gStageScriptList\n\
_080208C8:\n\
	cmp r0, #0xd\n\
	bne _08020914\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strh r0, [r4, #8]\n\
	ldr r1, _08020908 @ =gStageEntityManager\n\
	ldr r3, _0802090C @ =0x0000020E\n\
	adds r1, r1, r3\n\
	ldrh r2, [r1]\n\
	movs r0, #1\n\
	orrs r0, r2\n\
	strh r0, [r1]\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020910 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	adds r1, #0x98\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
	movs r0, #0xe\n\
	bl setStageCheckpoint\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	add r1, r8\n\
	movs r0, #0x17\n\
	strb r0, [r1]\n\
	bl _0802153A\n\
	.align 2, 0\n\
_08020908: .4byte gStageEntityManager\n\
_0802090C: .4byte 0x0000020E\n\
_08020910: .4byte gStageScriptList\n\
_08020914:\n\
	cmp r0, #0xe\n\
	bne _0802097C\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x40\n\
	orrs r0, r1\n\
	strh r0, [r4, #8]\n\
	ldr r0, _08020968 @ =gIntrManager\n\
	ldr r2, _0802096C @ =0x00000165\n\
	adds r1, r0, r2\n\
	ldrb r0, [r1]\n\
	movs r0, #2\n\
	strb r0, [r1]\n\
	bl text_080e9730\n\
	ldr r2, _08020970 @ =gVideoRegBuffer\n\
	ldrh r1, [r2]\n\
	ldr r0, _08020974 @ =0x0000F0FF\n\
	ands r0, r1\n\
	movs r3, #0x80\n\
	lsls r3, r3, #1\n\
	adds r1, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020978 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	adds r1, #0x9c\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
	movs r0, #0xf\n\
	bl setStageCheckpoint\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	add r1, r8\n\
	movs r0, #0x18\n\
	strb r0, [r1]\n\
	bl _0802153A\n\
	.align 2, 0\n\
_08020968: .4byte gIntrManager\n\
_0802096C: .4byte 0x00000165\n\
_08020970: .4byte gVideoRegBuffer\n\
_08020974: .4byte 0x0000F0FF\n\
_08020978: .4byte gStageScriptList\n\
_0802097C:\n\
	cmp r0, #0xf\n\
	beq _08020984\n\
	bl _0802153A\n\
_08020984:\n\
	ldr r0, _080209AC @ =gIntrManager\n\
	ldr r2, _080209B0 @ =0x00000165\n\
	adds r1, r0, r2\n\
	ldrb r0, [r1]\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldrh r1, [r4, #8]\n\
	ldr r0, _080209B4 @ =0x0000FFBF\n\
	ands r0, r1\n\
	ldr r1, _080209B8 @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r4, #8]\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	add r1, r8\n\
	movs r0, #0x19\n\
	strb r0, [r1]\n\
	bl _0802153A\n\
	.align 2, 0\n\
_080209AC: .4byte gIntrManager\n\
_080209B0: .4byte 0x00000165\n\
_080209B4: .4byte 0x0000FFBF\n\
_080209B8: .4byte 0x0000FFFE\n\
_080209BC:\n\
	cmp r0, #1\n\
	bne _080209CE\n\
_080209C0:\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	movs r0, #2\n\
	strb r0, [r6]\n\
	bl _0802153A\n\
_080209CE:\n\
	cmp r0, #2\n\
	bne _080209FC\n\
	ldr r1, [r7, #0x54]\n\
	ldr r0, _080209F4 @ =0x000A4FFF\n\
	cmp r1, r0\n\
	ble _080209FC\n\
	ldr r2, _080209F8 @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	movs r0, #3\n\
	bl setStageCheckpoint\n\
	movs r0, #3\n\
	strb r0, [r6]\n\
	bl _0802153A\n\
	.align 2, 0\n\
_080209F4: .4byte 0x000A4FFF\n\
_080209F8: .4byte gCollisionManager\n\
_080209FC:\n\
	movs r4, #0xbe\n\
	lsls r4, r4, #1\n\
	add r4, r8\n\
	ldrb r0, [r4]\n\
	cmp r0, #3\n\
	bne _08020A58\n\
	ldr r1, [r7, #0x54]\n\
	ldr r0, _08020A48 @ =0x000B3FFF\n\
	cmp r1, r0\n\
	ble _08020A58\n\
	ldr r2, _08020A4C @ =gStageRun\n\
	ldrh r0, [r2, #0x14]\n\
	movs r3, #1\n\
	ands r3, r0\n\
	cmp r3, #0\n\
	bne _08020A58\n\
	ldr r0, _08020A50 @ =gCollisionManager\n\
	strb r3, [r0, #1]\n\
	movs r0, #0xa6\n\
	lsls r0, r0, #1\n\
	adds r1, r2, r0\n\
	movs r0, #0xd0\n\
	lsls r0, r0, #9\n\
	str r0, [r1]\n\
	movs r0, #0xa8\n\
	lsls r0, r0, #1\n\
	adds r1, r2, r0\n\
	movs r0, #0xa8\n\
	lsls r0, r0, #0xa\n\
	str r0, [r1]\n\
	movs r0, #0\n\
	strh r3, [r2, #0xa]\n\
	ldr r1, _08020A54 @ =0x0000017D\n\
	add r1, r8\n\
	strb r0, [r1]\n\
	movs r0, #4\n\
	bl _08021538\n\
	.align 2, 0\n\
_08020A48: .4byte 0x000B3FFF\n\
_08020A4C: .4byte gStageRun\n\
_08020A50: .4byte gCollisionManager\n\
_08020A54: .4byte 0x0000017D\n\
_08020A58:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	add r1, r8\n\
	mov sb, r1\n\
	ldrb r0, [r1]\n\
	cmp r0, #4\n\
	beq _08020A68\n\
	b _08020D0C\n\
_08020A68:\n\
	ldr r6, _08020AF8 @ =gStageRun\n\
	ldrh r3, [r6, #8]\n\
	movs r0, #0x10\n\
	ands r0, r3\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	cmp r5, #0\n\
	beq _08020B18\n\
	ldr r1, _08020AFC @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x80\n\
	orrs r0, r2\n\
	strb r0, [r1]\n\
	ldrb r2, [r1, #1]\n\
	movs r0, #2\n\
	orrs r0, r2\n\
	strb r0, [r1, #1]\n\
	ldr r1, _08020B00 @ =0x0000FFFD\n\
	ands r1, r3\n\
	ldr r0, _08020B04 @ =0x0000FFEF\n\
	ands r1, r0\n\
	ldrb r2, [r6, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r2\n\
	strb r0, [r6, #0x12]\n\
	movs r0, #1\n\
	orrs r1, r0\n\
	strh r1, [r6, #8]\n\
	ldr r5, _08020B08 @ =gCurStory\n\
	ldr r1, _08020B0C @ =u16_ARRAY_0834cfc4\n\
	ldr r4, _08020B10 @ =0x0000017D\n\
	add r4, r8\n\
	ldrb r0, [r4]\n\
	subs r0, #1\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r3, [r0]\n\
	lsrs r2, r3, #3\n\
	adds r0, r5, #4\n\
	adds r2, r2, r0\n\
	movs r1, #7\n\
	ands r1, r3\n\
	movs r0, #1\n\
	lsls r0, r1\n\
	ldrb r1, [r2]\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	movs r0, #0xa\n\
	strb r0, [r4]\n\
	adds r0, r6, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020B14 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x10]\n\
	bl SetScript\n\
	ldrb r1, [r5, #7]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	cmp r0, #0xf\n\
	beq _08020AE6\n\
	bl _0802153A\n\
_08020AE6:\n\
	ldrb r0, [r5, #4]\n\
	movs r1, #0xfb\n\
	ands r1, r0\n\
	strb r1, [r5, #4]\n\
	movs r0, #5\n\
	mov r2, sb\n\
	strb r0, [r2]\n\
	bl _0802153A\n\
	.align 2, 0\n\
_08020AF8: .4byte gStageRun\n\
_08020AFC: .4byte gCollisionManager\n\
_08020B00: .4byte 0x0000FFFD\n\
_08020B04: .4byte 0x0000FFEF\n\
_08020B08: .4byte gCurStory\n\
_08020B0C: .4byte u16_ARRAY_0834cfc4\n\
_08020B10: .4byte 0x0000017D\n\
_08020B14: .4byte gStageScriptList\n\
_08020B18:\n\
	ldr r4, _08020B50 @ =0x0000017D\n\
	add r4, r8\n\
	ldrb r0, [r4]\n\
	cmp r0, #0xa\n\
	bne _08020B36\n\
	ldr r0, _08020B54 @ =gCollisionManager\n\
	ldrb r2, [r0]\n\
	movs r1, #0x7f\n\
	ands r1, r2\n\
	strb r1, [r0]\n\
	strb r5, [r0, #1]\n\
	movs r0, #3\n\
	bl setStageCheckpoint\n\
	strb r5, [r4]\n\
_08020B36:\n\
	ldrb r0, [r4]\n\
	cmp r0, #0\n\
	beq _08020B58\n\
	ldrb r0, [r6, #2]\n\
	cmp r0, #4\n\
	beq _08020B46\n\
	bl _0802153A\n\
_08020B46:\n\
	movs r0, #3\n\
	bl setStageCheckpoint\n\
	bl _0802153A\n\
	.align 2, 0\n\
_08020B50: .4byte 0x0000017D\n\
_08020B54: .4byte gCollisionManager\n\
_08020B58:\n\
	ldr r0, _08020B8C @ =0x00031FFF\n\
	ldr r2, [r7, #0x58]\n\
	cmp r2, r0\n\
	bgt _08020B64\n\
	bl _0802153A\n\
_08020B64:\n\
	ldr r0, _08020B90 @ =0x0001DFFF\n\
	ldr r1, [r7, #0x54]\n\
	cmp r1, r0\n\
	bgt _08020BD8\n\
	ldr r0, _08020B94 @ =0x00045FFF\n\
	cmp r2, r0\n\
	bgt _08020BD8\n\
	ldrh r1, [r6, #0xa]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08020B9C\n\
	adds r0, r6, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020B98 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x14]\n\
	bl SetScript\n\
	b _08020BAA\n\
	.align 2, 0\n\
_08020B8C: .4byte 0x00031FFF\n\
_08020B90: .4byte 0x0001DFFF\n\
_08020B94: .4byte 0x00045FFF\n\
_08020B98: .4byte gStageScriptList\n\
_08020B9C:\n\
	adds r0, r6, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020BCC @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x18]\n\
	bl SetScript\n\
_08020BAA:\n\
	ldr r0, _08020BD0 @ =0x0000017D\n\
	add r0, r8\n\
	movs r2, #1\n\
	strb r2, [r0]\n\
	ldr r3, _08020BD4 @ =gStageRun\n\
	ldrb r0, [r3, #0xa]\n\
	movs r1, #1\n\
_08020BB8:\n\
	orrs r0, r1\n\
	lsls r2, r2, #8\n\
	orrs r0, r2\n\
	strh r0, [r3, #0xa]\n\
	movs r0, #4\n\
	bl setStageCheckpoint\n\
	bl _0802153A\n\
	.align 2, 0\n\
_08020BCC: .4byte gStageScriptList\n\
_08020BD0: .4byte 0x0000017D\n\
_08020BD4: .4byte gStageRun\n\
_08020BD8:\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #9\n\
	cmp r1, r0\n\
	ble _08020C9C\n\
	movs r0, #0x8c\n\
	lsls r0, r0, #0xb\n\
	cmp r2, r0\n\
	ble _08020C3C\n\
	ldr r2, _08020C04 @ =gStageRun\n\
	ldrh r1, [r2, #0xa]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08020C0C\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020C08 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x1c]\n\
	bl SetScript\n\
	b _08020C1A\n\
	.align 2, 0\n\
_08020C04: .4byte gStageRun\n\
_08020C08: .4byte gStageScriptList\n\
_08020C0C:\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020C30 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x20]\n\
	bl SetScript\n\
_08020C1A:\n\
	ldr r0, _08020C34 @ =0x0000017D\n\
	add r0, r8\n\
	movs r2, #2\n\
	strb r2, [r0]\n\
	ldr r3, _08020C38 @ =gStageRun\n\
	ldrh r1, [r3, #0xa]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	movs r1, #2\n\
	b _08020BB8\n\
	.align 2, 0\n\
_08020C30: .4byte gStageScriptList\n\
_08020C34: .4byte 0x0000017D\n\
_08020C38: .4byte gStageRun\n\
_08020C3C:\n\
	ldr r0, _08020C60 @ =0x00045FFF\n\
	cmp r2, r0\n\
	bgt _08020C9C\n\
	ldr r2, _08020C64 @ =gStageRun\n\
	ldrh r1, [r2, #0xa]\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08020C6C\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020C68 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x24]\n\
	bl SetScript\n\
	b _08020C7A\n\
	.align 2, 0\n\
_08020C60: .4byte 0x00045FFF\n\
_08020C64: .4byte gStageRun\n\
_08020C68: .4byte gStageScriptList\n\
_08020C6C:\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020C90 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x28]\n\
	bl SetScript\n\
_08020C7A:\n\
	ldr r0, _08020C94 @ =0x0000017D\n\
	add r0, r8\n\
	movs r2, #3\n\
	strb r2, [r0]\n\
	ldr r3, _08020C98 @ =gStageRun\n\
	ldrh r1, [r3, #0xa]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	movs r1, #4\n\
	b _08020BB8\n\
	.align 2, 0\n\
_08020C90: .4byte gStageScriptList\n\
_08020C94: .4byte 0x0000017D\n\
_08020C98: .4byte gStageRun\n\
_08020C9C:\n\
	ldr r0, _08020CD0 @ =0x0001DFFF\n\
	cmp r1, r0\n\
	ble _08020CA6\n\
	bl _0802153A\n\
_08020CA6:\n\
	movs r0, #0x8c\n\
	lsls r0, r0, #0xb\n\
	cmp r2, r0\n\
	bgt _08020CB2\n\
	bl _0802153A\n\
_08020CB2:\n\
	ldr r2, _08020CD4 @ =gStageRun\n\
	ldrh r1, [r2, #0xa]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08020CDC\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020CD8 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x2c]\n\
	bl SetScript\n\
	b _08020CEA\n\
	.align 2, 0\n\
_08020CD0: .4byte 0x0001DFFF\n\
_08020CD4: .4byte gStageRun\n\
_08020CD8: .4byte gStageScriptList\n\
_08020CDC:\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020D00 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x30]\n\
	bl SetScript\n\
_08020CEA:\n\
	ldr r0, _08020D04 @ =0x0000017D\n\
	add r0, r8\n\
	movs r2, #4\n\
	strb r2, [r0]\n\
	ldr r3, _08020D08 @ =gStageRun\n\
	ldrh r1, [r3, #0xa]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	movs r1, #8\n\
	b _08020BB8\n\
	.align 2, 0\n\
_08020D00: .4byte gStageScriptList\n\
_08020D04: .4byte 0x0000017D\n\
_08020D08: .4byte gStageRun\n\
_08020D0C:\n\
	cmp r0, #5\n\
	bne _08020D2C\n\
	ldr r1, _08020D28 @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x7f\n\
	ands r0, r2\n\
	movs r2, #0\n\
	strb r0, [r1]\n\
	strb r2, [r1, #1]\n\
	movs r0, #5\n\
	bl setStageCheckpoint\n\
	movs r0, #6\n\
	b _080210AA\n\
	.align 2, 0\n\
_08020D28: .4byte gCollisionManager\n\
_08020D2C:\n\
	cmp r0, #6\n\
	bne _08020D64\n\
	ldr r1, [r7, #0x54]\n\
	movs r0, #0xc3\n\
	lsls r0, r0, #0xc\n\
	cmp r1, r0\n\
	ble _08020D64\n\
	ldr r2, _08020D5C @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	movs r4, #0\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	movs r0, #5\n\
	bl setStageCheckpoint\n\
	ldr r1, _08020D60 @ =0x0202FFAC\n\
	str r4, [r1]\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #0xe\n\
	str r0, [r1, #4]\n\
	movs r0, #7\n\
	b _080210DE\n\
	.align 2, 0\n\
_08020D5C: .4byte gCurStory\n\
_08020D60: .4byte 0x0202FFAC\n\
_08020D64:\n\
	movs r4, #0xbe\n\
	lsls r4, r4, #1\n\
	add r4, r8\n\
	ldrb r0, [r4]\n\
	cmp r0, #7\n\
	bne _08020D98\n\
	ldr r1, [r7, #0x54]\n\
	ldr r0, _08020D90 @ =0x00158FFF\n\
	cmp r1, r0\n\
	ble _08020D98\n\
	ldr r2, _08020D94 @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	movs r0, #6\n\
	bl setStageCheckpoint\n\
	movs r0, #8\n\
	bl _08021538\n\
	.align 2, 0\n\
_08020D90: .4byte 0x00158FFF\n\
_08020D94: .4byte gCollisionManager\n\
_08020D98:\n\
	movs r4, #0xbe\n\
	lsls r4, r4, #1\n\
	add r4, r8\n\
	ldrb r0, [r4]\n\
	cmp r0, #8\n\
	bne _08020DF0\n\
	ldr r1, [r7, #0x54]\n\
	movs r0, #0xb4\n\
	lsls r0, r0, #0xd\n\
	cmp r1, r0\n\
	ble _08020DF0\n\
	ldr r2, _08020DE4 @ =gStageRun\n\
	ldrh r0, [r2, #0x14]\n\
	movs r3, #1\n\
	ands r3, r0\n\
	cmp r3, #0\n\
	bne _08020DF0\n\
	ldr r0, _08020DE8 @ =gCollisionManager\n\
	strb r3, [r0, #1]\n\
	movs r0, #0xa6\n\
	lsls r0, r0, #1\n\
	adds r1, r2, r0\n\
	movs r0, #0x80\n\
	lsls r0, r0, #9\n\
	str r0, [r1]\n\
	movs r0, #0xa8\n\
	lsls r0, r0, #1\n\
	adds r1, r2, r0\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0xa\n\
	str r0, [r1]\n\
	movs r0, #0\n\
	strh r3, [r2, #0xa]\n\
	ldr r1, _08020DEC @ =0x0000017D\n\
	add r1, r8\n\
	strb r0, [r1]\n\
	movs r0, #9\n\
	b _08021538\n\
	.align 2, 0\n\
_08020DE4: .4byte gStageRun\n\
_08020DE8: .4byte gCollisionManager\n\
_08020DEC: .4byte 0x0000017D\n\
_08020DF0:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	add r1, r8\n\
	mov sb, r1\n\
	ldrb r0, [r1]\n\
	cmp r0, #9\n\
	beq _08020E00\n\
	b _08021090\n\
_08020E00:\n\
	ldr r6, _08020E8C @ =gStageRun\n\
	ldrh r3, [r6, #8]\n\
	movs r0, #0x10\n\
	ands r0, r3\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	cmp r5, #0\n\
	beq _08020EAC\n\
	ldr r1, _08020E90 @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x80\n\
	orrs r0, r2\n\
	strb r0, [r1]\n\
	ldrb r2, [r1, #1]\n\
	movs r0, #2\n\
	orrs r0, r2\n\
	strb r0, [r1, #1]\n\
	ldr r1, _08020E94 @ =0x0000FFFD\n\
	ands r1, r3\n\
	ldr r0, _08020E98 @ =0x0000FFEF\n\
	ands r1, r0\n\
	ldrb r2, [r6, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r2\n\
	strb r0, [r6, #0x12]\n\
	movs r0, #1\n\
	orrs r1, r0\n\
	strh r1, [r6, #8]\n\
	ldr r5, _08020E9C @ =gCurStory\n\
	ldr r1, _08020EA0 @ =u16_ARRAY_0834cfc4\n\
	ldr r4, _08020EA4 @ =0x0000017D\n\
	add r4, r8\n\
	ldrb r0, [r4]\n\
	subs r0, #1\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r3, [r0]\n\
	lsrs r2, r3, #3\n\
	adds r0, r5, #4\n\
	adds r2, r2, r0\n\
	movs r1, #7\n\
	ands r1, r3\n\
	movs r0, #1\n\
	lsls r0, r1\n\
	ldrb r1, [r2]\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	movs r7, #0xa\n\
	strb r7, [r4]\n\
	adds r0, r6, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020EA8 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x3c]\n\
	bl SetScript\n\
	ldrb r1, [r5, #7]\n\
	movs r0, #0xf0\n\
	ands r0, r1\n\
	cmp r0, #0xf0\n\
	beq _08020E7C\n\
	b _0802153A\n\
_08020E7C:\n\
	ldrb r1, [r5, #4]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r5, #4]\n\
	mov r2, sb\n\
	strb r7, [r2]\n\
	b _0802153A\n\
	.align 2, 0\n\
_08020E8C: .4byte gStageRun\n\
_08020E90: .4byte gCollisionManager\n\
_08020E94: .4byte 0x0000FFFD\n\
_08020E98: .4byte 0x0000FFEF\n\
_08020E9C: .4byte gCurStory\n\
_08020EA0: .4byte u16_ARRAY_0834cfc4\n\
_08020EA4: .4byte 0x0000017D\n\
_08020EA8: .4byte gStageScriptList\n\
_08020EAC:\n\
	ldr r4, _08020EE0 @ =0x0000017D\n\
	add r4, r8\n\
	ldrb r0, [r4]\n\
	cmp r0, #0xa\n\
	bne _08020ECA\n\
	ldr r0, _08020EE4 @ =gCollisionManager\n\
	ldrb r2, [r0]\n\
	movs r1, #0x7f\n\
	ands r1, r2\n\
	strb r1, [r0]\n\
	strb r5, [r0, #1]\n\
	movs r0, #6\n\
	bl setStageCheckpoint\n\
	strb r5, [r4]\n\
_08020ECA:\n\
	ldrb r0, [r4]\n\
	cmp r0, #0\n\
	beq _08020EE8\n\
	ldrb r0, [r6, #2]\n\
	cmp r0, #7\n\
	beq _08020ED8\n\
	b _0802153A\n\
_08020ED8:\n\
	movs r0, #6\n\
	bl setStageCheckpoint\n\
	b _0802153A\n\
	.align 2, 0\n\
_08020EE0: .4byte 0x0000017D\n\
_08020EE4: .4byte gCollisionManager\n\
_08020EE8:\n\
	ldr r0, _08020F1C @ =0x00027FFF\n\
	ldr r2, [r7, #0x58]\n\
	cmp r2, r0\n\
	bgt _08020EF2\n\
	b _0802153A\n\
_08020EF2:\n\
	ldr r0, _08020F20 @ =0x00077FFF\n\
	ldr r1, [r7, #0x54]\n\
	cmp r1, r0\n\
	bgt _08020F64\n\
	ldr r0, _08020F24 @ =0x00045FFF\n\
	cmp r2, r0\n\
	bgt _08020F64\n\
	ldrh r1, [r6, #0xa]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08020F2C\n\
	adds r0, r6, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020F28 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x40]\n\
	bl SetScript\n\
	b _08020F3A\n\
	.align 2, 0\n\
_08020F1C: .4byte 0x00027FFF\n\
_08020F20: .4byte 0x00077FFF\n\
_08020F24: .4byte 0x00045FFF\n\
_08020F28: .4byte gStageScriptList\n\
_08020F2C:\n\
	adds r0, r6, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020F58 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x44]\n\
	bl SetScript\n\
_08020F3A:\n\
	ldr r0, _08020F5C @ =0x0000017D\n\
	add r0, r8\n\
	movs r2, #5\n\
	strb r2, [r0]\n\
	ldr r3, _08020F60 @ =gStageRun\n\
	ldrb r0, [r3, #0xa]\n\
	movs r1, #1\n\
_08020F48:\n\
	orrs r0, r1\n\
	lsls r2, r2, #8\n\
	orrs r0, r2\n\
	strh r0, [r3, #0xa]\n\
	movs r0, #7\n\
	bl setStageCheckpoint\n\
	b _0802153A\n\
	.align 2, 0\n\
_08020F58: .4byte gStageScriptList\n\
_08020F5C: .4byte 0x0000017D\n\
_08020F60: .4byte gStageRun\n\
_08020F64:\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #0xb\n\
	cmp r1, r0\n\
	ble _08020FC4\n\
	movs r0, #0x8c\n\
	lsls r0, r0, #0xb\n\
	cmp r2, r0\n\
	ble _08020FC4\n\
	ldr r2, _08020F90 @ =gStageRun\n\
	ldrh r1, [r2, #0xa]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08020F98\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020F94 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x48]\n\
	bl SetScript\n\
	b _08020FA6\n\
	.align 2, 0\n\
_08020F90: .4byte gStageRun\n\
_08020F94: .4byte gStageScriptList\n\
_08020F98:\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020FB8 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x4c]\n\
	bl SetScript\n\
_08020FA6:\n\
	ldr r0, _08020FBC @ =0x0000017D\n\
	add r0, r8\n\
	movs r2, #6\n\
	strb r2, [r0]\n\
	ldr r3, _08020FC0 @ =gStageRun\n\
	ldrb r0, [r3, #0xa]\n\
	movs r1, #2\n\
	b _08020F48\n\
	.align 2, 0\n\
_08020FB8: .4byte gStageScriptList\n\
_08020FBC: .4byte 0x0000017D\n\
_08020FC0: .4byte gStageRun\n\
_08020FC4:\n\
	ldr r0, _08020FF0 @ =0x00077FFF\n\
	cmp r1, r0\n\
	bgt _08021028\n\
	movs r0, #0x8c\n\
	lsls r0, r0, #0xb\n\
	cmp r2, r0\n\
	ble _08021028\n\
	ldr r2, _08020FF4 @ =gStageRun\n\
	ldrh r1, [r2, #0xa]\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08020FFC\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08020FF8 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x50]\n\
	bl SetScript\n\
	b _0802100A\n\
	.align 2, 0\n\
_08020FF0: .4byte 0x00077FFF\n\
_08020FF4: .4byte gStageRun\n\
_08020FF8: .4byte gStageScriptList\n\
_08020FFC:\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0802101C @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x54]\n\
	bl SetScript\n\
_0802100A:\n\
	ldr r0, _08021020 @ =0x0000017D\n\
	add r0, r8\n\
	movs r2, #7\n\
	strb r2, [r0]\n\
	ldr r3, _08021024 @ =gStageRun\n\
	ldrb r0, [r3, #0xa]\n\
	movs r1, #4\n\
	b _08020F48\n\
	.align 2, 0\n\
_0802101C: .4byte gStageScriptList\n\
_08021020: .4byte 0x0000017D\n\
_08021024: .4byte gStageRun\n\
_08021028:\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #0xb\n\
	cmp r1, r0\n\
	bgt _08021032\n\
	b _0802153A\n\
_08021032:\n\
	ldr r0, _08021058 @ =0x00045FFF\n\
	cmp r2, r0\n\
	ble _0802103A\n\
	b _0802153A\n\
_0802103A:\n\
	ldr r2, _0802105C @ =gStageRun\n\
	ldrh r1, [r2, #0xa]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08021064\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08021060 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x58]\n\
	bl SetScript\n\
	b _08021072\n\
	.align 2, 0\n\
_08021058: .4byte 0x00045FFF\n\
_0802105C: .4byte gStageRun\n\
_08021060: .4byte gStageScriptList\n\
_08021064:\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08021084 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x5c]\n\
	bl SetScript\n\
_08021072:\n\
	ldr r0, _08021088 @ =0x0000017D\n\
	add r0, r8\n\
	movs r2, #8\n\
	strb r2, [r0]\n\
	ldr r3, _0802108C @ =gStageRun\n\
	ldrb r0, [r3, #0xa]\n\
	movs r1, #8\n\
	b _08020F48\n\
	.align 2, 0\n\
_08021084: .4byte gStageScriptList\n\
_08021088: .4byte 0x0000017D\n\
_0802108C: .4byte gStageRun\n\
_08021090:\n\
	cmp r0, #0xa\n\
	bne _080210B4\n\
	ldr r1, _080210B0 @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x7f\n\
	ands r0, r2\n\
	movs r2, #0\n\
	strb r0, [r1]\n\
	strb r2, [r1, #1]\n\
	movs r0, #8\n\
	bl setStageCheckpoint\n\
	movs r0, #0xb\n\
_080210AA:\n\
	mov r3, sb\n\
	strb r0, [r3]\n\
	b _0802153A\n\
	.align 2, 0\n\
_080210B0: .4byte gCollisionManager\n\
_080210B4:\n\
	cmp r0, #0xb\n\
	bne _080210F0\n\
	ldr r1, [r7, #0x54]\n\
	ldr r0, _080210E4 @ =0x00177000\n\
	cmp r1, r0\n\
	ble _080210F0\n\
	ldr r2, _080210E8 @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	movs r4, #0\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	movs r0, #8\n\
	bl setStageCheckpoint\n\
	ldr r1, _080210EC @ =0x0202FFAC\n\
	str r4, [r1]\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #0xe\n\
	str r0, [r1, #4]\n\
	movs r0, #0xc\n\
_080210DE:\n\
	mov r1, sb\n\
	strb r0, [r1]\n\
	b _0802153A\n\
	.align 2, 0\n\
_080210E4: .4byte 0x00177000\n\
_080210E8: .4byte gCurStory\n\
_080210EC: .4byte 0x0202FFAC\n\
_080210F0:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	add r0, r8\n\
	ldrb r0, [r0]\n\
	cmp r0, #0xc\n\
	bne _08021180\n\
	ldr r1, [r7, #0x54]\n\
	ldr r0, _08021170 @ =0x001B1FFF\n\
	cmp r1, r0\n\
	ble _08021120\n\
	ldr r0, _08021174 @ =gStageRun\n\
	movs r2, #0xb4\n\
	lsls r2, r2, #1\n\
	adds r5, r0, r2\n\
	ldr r0, [r5]\n\
	movs r4, #1\n\
	rsbs r4, r4, #0\n\
	cmp r0, r4\n\
	beq _08021120\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r4, [r5]\n\
_08021120:\n\
	ldr r1, [r7, #0x54]\n\
	ldr r0, _08021178 @ =0x001B3FFF\n\
	cmp r1, r0\n\
	bgt _0802112A\n\
	b _0802153A\n\
_0802112A:\n\
	ldr r2, _0802117C @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	ldr r0, _08021174 @ =gStageRun\n\
	movs r3, #0xb4\n\
	lsls r3, r3, #1\n\
	adds r4, r0, r3\n\
	ldr r0, [r4]\n\
	cmp r0, #0xa1\n\
	beq _0802115E\n\
	movs r5, #1\n\
	rsbs r5, r5, #0\n\
	cmp r0, r5\n\
	beq _08021154\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r5, [r4]\n\
_08021154:\n\
	movs r0, #0xa1\n\
	bl playBGM\n\
	movs r0, #0xa1\n\
	str r0, [r4]\n\
_0802115E:\n\
	ldr r1, _08021174 @ =gStageRun\n\
	movs r0, #0\n\
	strh r0, [r1, #0xa]\n\
FUN_08021164:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	add r1, r8\n\
	movs r0, #0xd\n\
	strb r0, [r1]\n\
	b _0802153A\n\
	.align 2, 0\n\
_08021170: .4byte 0x001B1FFF\n\
_08021174: .4byte gStageRun\n\
_08021178: .4byte 0x001B3FFF\n\
_0802117C: .4byte gCollisionManager\n\
_08021180:\n\
	cmp r0, #0xd\n\
	bne _080211E4\n\
	ldr r1, [r7, #0x54]\n\
	ldr r0, _080211B0 @ =0x001C1FFF\n\
	cmp r1, r0\n\
	ble _080211E4\n\
	ldr r1, _080211B4 @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r2, _080211B8 @ =gStageRun\n\
	ldrh r1, [r2, #0xa]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080211C0\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _080211BC @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x68]\n\
	bl SetScript\n\
	b _080211CE\n\
	.align 2, 0\n\
_080211B0: .4byte 0x001C1FFF\n\
_080211B4: .4byte gCollisionManager\n\
_080211B8: .4byte gStageRun\n\
_080211BC: .4byte gStageScriptList\n\
_080211C0:\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _080211E0 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x6c]\n\
	bl SetScript\n\
_080211CE:\n\
	movs r0, #0xa\n\
	bl setStageCheckpoint\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	add r1, r8\n\
	movs r0, #0xe\n\
	strb r0, [r1]\n\
	b _0802153A\n\
	.align 2, 0\n\
_080211E0: .4byte gStageScriptList\n\
_080211E4:\n\
	movs r4, #0xbe\n\
	lsls r4, r4, #1\n\
	add r4, r8\n\
	ldrb r0, [r4]\n\
	cmp r0, #0xe\n\
	bne _08021208\n\
	ldr r2, _08021204 @ =gStageRun\n\
	ldrh r1, [r2, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	strh r0, [r2, #0xa]\n\
	movs r0, #9\n\
	bl setStageCheckpoint\n\
	movs r0, #0xf\n\
	b _08021538\n\
	.align 2, 0\n\
_08021204: .4byte gStageRun\n\
_08021208:\n\
	cmp r0, #0xf\n\
	bne _0802129C\n\
	ldr r2, _08021248 @ =gCurStory\n\
	ldrb r1, [r2, #8]\n\
	movs r0, #0xbf\n\
	ands r0, r1\n\
	strb r0, [r2, #8]\n\
	ldr r3, _0802124C @ =gStageRun\n\
	ldrh r1, [r3, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08021224\n\
	b _0802153A\n\
_08021224:\n\
	ldr r2, _08021250 @ =gCollisionManager\n\
	ldrb r0, [r2]\n\
	movs r1, #0x80\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	ldrh r1, [r3, #0xa]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08021258\n\
	adds r0, r3, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08021254 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x74]\n\
	bl SetScript\n\
	b _08021266\n\
	.align 2, 0\n\
_08021248: .4byte gCurStory\n\
_0802124C: .4byte gStageRun\n\
_08021250: .4byte gCollisionManager\n\
_08021254: .4byte gStageScriptList\n\
_08021258:\n\
	adds r0, r3, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08021290 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	ldr r1, [r1, #0x78]\n\
	bl SetScript\n\
_08021266:\n\
	ldr r2, _08021294 @ =gStageRun\n\
	ldrh r0, [r2, #8]\n\
	ldr r1, _08021298 @ =0x0000FFEF\n\
	ands r1, r0\n\
	ldrb r3, [r2, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r3\n\
	strb r0, [r2, #0x12]\n\
	movs r0, #1\n\
	orrs r1, r0\n\
	strh r1, [r2, #8]\n\
	movs r0, #0xb\n\
	bl setStageCheckpoint2\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	add r1, r8\n\
	movs r0, #0x10\n\
	strb r0, [r1]\n\
	b _0802153A\n\
	.align 2, 0\n\
_08021290: .4byte gStageScriptList\n\
_08021294: .4byte gStageRun\n\
_08021298: .4byte 0x0000FFEF\n\
_0802129C:\n\
	cmp r0, #0x10\n\
	bne _080212C8\n\
	ldr r2, _080212C0 @ =gCollisionManager\n\
	ldrb r1, [r2]\n\
	movs r0, #0x7f\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldr r2, _080212C4 @ =gStageRun\n\
	ldrh r1, [r2, #0xa]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strh r0, [r2, #0xa]\n\
	movs r0, #9\n\
	bl setStageCheckpoint\n\
	movs r0, #0x11\n\
	b _08021538\n\
	.align 2, 0\n\
_080212C0: .4byte gCollisionManager\n\
_080212C4: .4byte gStageRun\n\
_080212C8:\n\
	cmp r0, #0x11\n\
	bne _0802135C\n\
	ldr r3, _08021308 @ =gStageRun\n\
	ldrh r1, [r3, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802135C\n\
	ldr r2, _0802130C @ =gCurStory\n\
	ldrb r1, [r2, #8]\n\
	movs r0, #0xbf\n\
	ands r0, r1\n\
	strb r0, [r2, #8]\n\
	ldr r2, _08021310 @ =gCollisionManager\n\
	ldrb r1, [r2]\n\
	movs r0, #0x80\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	ldrh r1, [r3, #0xa]\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08021318\n\
	adds r0, r3, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08021314 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	adds r1, #0x80\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
	b _08021328\n\
	.align 2, 0\n\
_08021308: .4byte gStageRun\n\
_0802130C: .4byte gCurStory\n\
_08021310: .4byte gCollisionManager\n\
_08021314: .4byte gStageScriptList\n\
_08021318:\n\
	adds r0, r3, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08021350 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	adds r1, #0x84\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
_08021328:\n\
	ldr r2, _08021354 @ =gStageRun\n\
	ldrh r0, [r2, #8]\n\
	ldr r1, _08021358 @ =0x0000FFEF\n\
	ands r1, r0\n\
	ldrb r3, [r2, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r3\n\
	strb r0, [r2, #0x12]\n\
	movs r0, #1\n\
	orrs r1, r0\n\
	strh r1, [r2, #8]\n\
	movs r0, #0xc\n\
	bl setStageCheckpoint2\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	add r1, r8\n\
	movs r0, #0x12\n\
	strb r0, [r1]\n\
	b _0802153A\n\
	.align 2, 0\n\
_08021350: .4byte gStageScriptList\n\
_08021354: .4byte gStageRun\n\
_08021358: .4byte 0x0000FFEF\n\
_0802135C:\n\
	movs r5, #0xbe\n\
	lsls r5, r5, #1\n\
	add r5, r8\n\
	ldrb r0, [r5]\n\
	cmp r0, #0x12\n\
	bne _08021390\n\
	ldr r2, _08021388 @ =gCollisionManager\n\
	ldrb r1, [r2]\n\
	movs r0, #0x7f\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldr r2, _0802138C @ =gStageRun\n\
	ldrh r1, [r2, #0xa]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strh r0, [r2, #0xa]\n\
	movs r0, #9\n\
	bl setStageCheckpoint\n\
	movs r0, #0x13\n\
	strb r0, [r5]\n\
	b _0802153A\n\
	.align 2, 0\n\
_08021388: .4byte gCollisionManager\n\
_0802138C: .4byte gStageRun\n\
_08021390:\n\
	cmp r0, #0x13\n\
	bne _080213F0\n\
	ldr r4, _080213E0 @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080213F0\n\
	ldr r1, _080213E4 @ =gCollisionManager\n\
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
	ldr r1, _080213E8 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	adds r1, #0x8c\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r1, _080213EC @ =0x0000FFEF\n\
	ands r1, r0\n\
	ldrb r2, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r2\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #4\n\
	orrs r1, r0\n\
	movs r0, #1\n\
	orrs r1, r0\n\
	strh r1, [r4, #8]\n\
	movs r0, #0x14\n\
	strb r0, [r5]\n\
	b _0802153A\n\
	.align 2, 0\n\
_080213E0: .4byte gStageRun\n\
_080213E4: .4byte gCollisionManager\n\
_080213E8: .4byte gStageScriptList\n\
_080213EC: .4byte 0x0000FFEF\n\
_080213F0:\n\
	movs r5, #0xbe\n\
	lsls r5, r5, #1\n\
	add r5, r8\n\
	ldrb r0, [r5]\n\
	cmp r0, #0x14\n\
	bne _08021430\n\
	ldr r1, _08021424 @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x7f\n\
	ands r0, r2\n\
	movs r2, #0\n\
	strb r0, [r1]\n\
	strb r2, [r1, #1]\n\
	ldr r0, _08021428 @ =gStageRun+16\n\
	ldr r1, _0802142C @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	adds r1, #0x90\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
	movs r0, #0xd\n\
	bl setStageCheckpoint\n\
	movs r0, #0x15\n\
	strb r0, [r5]\n\
	b _0802153A\n\
	.align 2, 0\n\
_08021424: .4byte gCollisionManager\n\
_08021428: .4byte gStageRun+16\n\
_0802142C: .4byte gStageScriptList\n\
_08021430:\n\
	cmp r0, #0x15\n\
	bne _0802147C\n\
	ldr r4, _08021470 @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802147C\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08021474 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	adds r1, #0x94\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r1, _08021478 @ =0x0000FFEF\n\
	ands r1, r0\n\
	ldrb r2, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r2\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #4\n\
	orrs r1, r0\n\
	movs r0, #1\n\
	orrs r1, r0\n\
	strh r1, [r4, #8]\n\
	movs r0, #0x16\n\
	strb r0, [r5]\n\
	b _0802153A\n\
	.align 2, 0\n\
_08021470: .4byte gStageRun\n\
_08021474: .4byte gStageScriptList\n\
_08021478: .4byte 0x0000FFEF\n\
_0802147C:\n\
	movs r4, #0xbe\n\
	lsls r4, r4, #1\n\
	add r4, r8\n\
	ldrb r0, [r4]\n\
	cmp r0, #0x16\n\
	bne _080214C0\n\
	ldr r1, _080214B0 @ =gStageEntityManager\n\
	ldr r0, _080214B4 @ =0x0000020E\n\
	adds r1, r1, r0\n\
	ldrh r2, [r1]\n\
	movs r0, #1\n\
	orrs r0, r2\n\
	strh r0, [r1]\n\
	ldr r0, _080214B8 @ =gStageRun+16\n\
	ldr r1, _080214BC @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	adds r1, #0x98\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
	movs r0, #0xe\n\
	bl setStageCheckpoint\n\
	movs r0, #0x17\n\
	b _08021538\n\
	.align 2, 0\n\
_080214B0: .4byte gStageEntityManager\n\
_080214B4: .4byte 0x0000020E\n\
_080214B8: .4byte gStageRun+16\n\
_080214BC: .4byte gStageScriptList\n\
_080214C0:\n\
	cmp r0, #0x17\n\
	bne _08021518\n\
	ldr r0, _08021500 @ =gIntrManager\n\
	ldr r2, _08021504 @ =0x00000165\n\
	adds r1, r0, r2\n\
	ldrb r0, [r1]\n\
	movs r0, #2\n\
	strb r0, [r1]\n\
	bl text_080e9730\n\
	ldr r2, _08021508 @ =gVideoRegBuffer\n\
	ldrh r1, [r2]\n\
	ldr r0, _0802150C @ =0x0000F0FF\n\
	ands r0, r1\n\
	movs r3, #0x80\n\
	lsls r3, r3, #1\n\
	adds r1, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r0, _08021510 @ =gStageRun+16\n\
	ldr r1, _08021514 @ =gStageScriptList\n\
	ldr r1, [r1, #0x40]\n\
	adds r1, #0x9c\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
	movs r0, #0xf\n\
	bl setStageCheckpoint\n\
	movs r0, #0x18\n\
	b _08021538\n\
	.align 2, 0\n\
_08021500: .4byte gIntrManager\n\
_08021504: .4byte 0x00000165\n\
_08021508: .4byte gVideoRegBuffer\n\
_0802150C: .4byte 0x0000F0FF\n\
_08021510: .4byte gStageRun+16\n\
_08021514: .4byte gStageScriptList\n\
_08021518:\n\
	cmp r0, #0x18\n\
	bne _0802153A\n\
	ldr r0, _08021548 @ =gIntrManager\n\
	ldr r2, _0802154C @ =0x00000165\n\
	adds r1, r0, r2\n\
	ldrb r0, [r1]\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldr r2, _08021550 @ =gStageRun\n\
	ldrh r1, [r2, #8]\n\
	ldr r0, _08021554 @ =0x0000FFBF\n\
	ands r0, r1\n\
	ldr r1, _08021558 @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r2, #8]\n\
	movs r0, #0x19\n\
_08021538:\n\
	strb r0, [r4]\n\
_0802153A:\n\
	movs r0, #0\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_08021548: .4byte gIntrManager\n\
_0802154C: .4byte 0x00000165\n\
_08021550: .4byte gStageRun\n\
_08021554: .4byte 0x0000FFBF\n\
_08021558: .4byte 0x0000FFFE\n\
 .syntax divided\n");
}
