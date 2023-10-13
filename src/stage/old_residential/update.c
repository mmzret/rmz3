#include "global.h"
#include "overworld.h"

NAKED s16 OldResidential_MissionUpdate(struct StageRun* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r7, r0, #0\n\
	ldr r5, [r7, #0x20]\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r6, r7, r0\n\
	ldrb r0, [r6]\n\
	cmp r0, #0\n\
	beq _0801C958\n\
	b _0801CAB4\n\
_0801C958:\n\
	ldr r3, _0801C994 @ =gStageRun\n\
	ldrh r1, [r3, #8]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	strh r0, [r3, #8]\n\
	ldr r2, _0801C998 @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	orrs r1, r0\n\
	strb r1, [r2, #4]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801C9A0\n\
	adds r0, r3, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801C99C @ =gStageScriptList\n\
	ldr r1, [r1, #0x14]\n\
	ldr r1, [r1, #0x3c]\n\
	bl SetScript\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #1\n\
	adds r1, r7, r0\n\
	movs r0, #0xe1\n\
	lsls r0, r0, #3\n\
	str r0, [r1]\n\
	movs r0, #0x14\n\
	strb r0, [r6]\n\
	b _0801CE88\n\
	.align 2, 0\n\
_0801C994: .4byte gStageRun\n\
_0801C998: .4byte gCurStory\n\
_0801C99C: .4byte gStageScriptList\n\
_0801C9A0:\n\
	ldrb r4, [r3, #2]\n\
	cmp r4, #0\n\
	bne _0801C9E8\n\
	movs r0, #0x20\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	bne _0801C9C4\n\
	adds r0, r3, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801C9C0 @ =gStageScriptList\n\
	ldr r1, [r1, #0x14]\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
	b _0801C9D2\n\
	.align 2, 0\n\
_0801C9C0: .4byte gStageScriptList\n\
_0801C9C4:\n\
	adds r0, r3, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801C9E4 @ =gStageScriptList\n\
	ldr r1, [r1, #0x14]\n\
	ldr r1, [r1, #0x40]\n\
	bl SetScript\n\
_0801C9D2:\n\
	movs r0, #1\n\
	bl setStageCheckpoint\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r7, r0\n\
	movs r0, #1\n\
	b _0801CE86\n\
	.align 2, 0\n\
_0801C9E4: .4byte gStageScriptList\n\
_0801C9E8:\n\
	cmp r4, #1\n\
	bne _0801CA00\n\
	adds r0, r3, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801C9FC @ =gStageScriptList\n\
	ldr r1, [r1, #0x14]\n\
	ldr r1, [r1, #4]\n\
	bl SetScript\n\
	b _0801CAB8\n\
	.align 2, 0\n\
_0801C9FC: .4byte gStageScriptList\n\
_0801CA00:\n\
	cmp r4, #2\n\
	bne _0801CA14\n\
	adds r0, r3, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801CA10 @ =gStageScriptList\n\
	ldr r1, [r1, #0x14]\n\
	ldr r1, [r1, #8]\n\
	b _0801CA3A\n\
	.align 2, 0\n\
_0801CA10: .4byte gStageScriptList\n\
_0801CA14:\n\
	cmp r4, #3\n\
	bne _0801CA2C\n\
	adds r0, r3, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801CA28 @ =gStageScriptList\n\
	ldr r1, [r1, #0x14]\n\
	ldr r1, [r1, #0x10]\n\
	bl SetScript\n\
	b _0801CB10\n\
	.align 2, 0\n\
_0801CA28: .4byte gStageScriptList\n\
_0801CA2C:\n\
	cmp r4, #4\n\
	bne _0801CA48\n\
	adds r0, r3, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801CA44 @ =gStageScriptList\n\
	ldr r1, [r1, #0x14]\n\
	ldr r1, [r1, #0x14]\n\
_0801CA3A:\n\
	bl SetScript\n\
	strb r4, [r6]\n\
	b _0801CE88\n\
	.align 2, 0\n\
_0801CA44: .4byte gStageScriptList\n\
_0801CA48:\n\
	cmp r4, #5\n\
	bne _0801CA60\n\
	adds r0, r3, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801CA5C @ =gStageScriptList\n\
	ldr r1, [r1, #0x14]\n\
	ldr r1, [r1, #0x20]\n\
	bl SetScript\n\
	b _0801CBE2\n\
	.align 2, 0\n\
_0801CA5C: .4byte gStageScriptList\n\
_0801CA60:\n\
	cmp r4, #6\n\
	bne _0801CA7C\n\
	adds r0, r3, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801CA78 @ =gStageScriptList\n\
	ldr r1, [r1, #0x14]\n\
	ldr r1, [r1, #0x24]\n\
	bl SetScript\n\
	movs r0, #9\n\
	strb r0, [r6]\n\
	b _0801CE88\n\
	.align 2, 0\n\
_0801CA78: .4byte gStageScriptList\n\
_0801CA7C:\n\
	cmp r4, #7\n\
	bne _0801CA94\n\
	adds r0, r3, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801CA90 @ =gStageScriptList\n\
	ldr r1, [r1, #0x14]\n\
	ldr r1, [r1, #0x30]\n\
	bl SetScript\n\
	b _0801CD40\n\
	.align 2, 0\n\
_0801CA90: .4byte gStageScriptList\n\
_0801CA94:\n\
	cmp r4, #8\n\
	beq _0801CA9A\n\
	b _0801CE88\n\
_0801CA9A:\n\
	ldrh r1, [r3, #8]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	ldr r1, _0801CAB0 @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r3, #8]\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r7, r0\n\
	movs r0, #0xd\n\
	b _0801CE86\n\
	.align 2, 0\n\
_0801CAB0: .4byte 0x0000FFFE\n\
_0801CAB4:\n\
	cmp r0, #1\n\
	bne _0801CAC4\n\
_0801CAB8:\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	movs r0, #2\n\
	strb r0, [r6]\n\
	b _0801CE88\n\
_0801CAC4:\n\
	cmp r0, #2\n\
	bne _0801CB1C\n\
	ldr r1, [r5, #0x54]\n\
	ldr r0, _0801CAFC @ =0x000C2FFF\n\
	cmp r1, r0\n\
	ble _0801CB1C\n\
	ldr r1, [r5, #0x58]\n\
	ldr r0, _0801CB00 @ =0x00013FFF\n\
	cmp r1, r0\n\
	bgt _0801CB1C\n\
	ldr r0, _0801CB04 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0801CB10\n\
	ldr r0, _0801CB08 @ =gStageRun+16\n\
	ldr r1, _0801CB0C @ =gStageScriptList\n\
	ldr r1, [r1, #0x14]\n\
	ldr r1, [r1, #0xc]\n\
	bl SetScript\n\
	movs r0, #3\n\
	bl setStageCheckpoint\n\
	movs r0, #3\n\
	strb r0, [r6]\n\
	b _0801CE88\n\
	.align 2, 0\n\
_0801CAFC: .4byte 0x000C2FFF\n\
_0801CB00: .4byte 0x00013FFF\n\
_0801CB04: .4byte gCurStory\n\
_0801CB08: .4byte gStageRun+16\n\
_0801CB0C: .4byte gStageScriptList\n\
_0801CB10:\n\
	movs r0, #4\n\
	bl setStageCheckpoint\n\
	movs r0, #4\n\
	strb r0, [r6]\n\
	b _0801CE88\n\
_0801CB1C:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r4, r7, r1\n\
	ldrb r0, [r4]\n\
	cmp r0, #3\n\
	bne _0801CB34\n\
	movs r0, #4\n\
	bl setStageCheckpoint\n\
	movs r0, #4\n\
	strb r0, [r4]\n\
	b _0801CE88\n\
_0801CB34:\n\
	cmp r0, #4\n\
	bne _0801CB60\n\
	ldr r1, [r5, #0x54]\n\
	ldr r0, _0801CB54 @ =0x0011DFFF\n\
	cmp r1, r0\n\
	ble _0801CB60\n\
	ldr r0, _0801CB58 @ =gStageRun+16\n\
	ldr r1, _0801CB5C @ =gStageScriptList\n\
	ldr r1, [r1, #0x14]\n\
	ldr r1, [r1, #0x18]\n\
	bl SetScript\n\
	movs r0, #5\n\
	strb r0, [r4]\n\
	b _0801CE88\n\
	.align 2, 0\n\
_0801CB54: .4byte 0x0011DFFF\n\
_0801CB58: .4byte gStageRun+16\n\
_0801CB5C: .4byte gStageScriptList\n\
_0801CB60:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r6, r7, r0\n\
	ldrb r0, [r6]\n\
	cmp r0, #5\n\
	bne _0801CBC8\n\
	ldr r4, _0801CBB8 @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801CBC8\n\
	ldr r1, _0801CBBC @ =gCollisionManager\n\
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
	ldr r1, _0801CBC0 @ =gStageScriptList\n\
	ldr r1, [r1, #0x14]\n\
	ldr r1, [r1, #0x1c]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r1, _0801CBC4 @ =0x0000FFEF\n\
	ands r1, r0\n\
	ldrb r2, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r2\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #1\n\
	orrs r1, r0\n\
	strh r1, [r4, #8]\n\
	movs r0, #5\n\
	bl setStageCheckpoint\n\
	movs r0, #6\n\
	strb r0, [r6]\n\
	b _0801CE88\n\
	.align 2, 0\n\
_0801CBB8: .4byte gStageRun\n\
_0801CBBC: .4byte gCollisionManager\n\
_0801CBC0: .4byte gStageScriptList\n\
_0801CBC4: .4byte 0x0000FFEF\n\
_0801CBC8:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r6, r7, r1\n\
	ldrb r0, [r6]\n\
	cmp r0, #6\n\
	bne _0801CBEC\n\
	ldr r1, _0801CBE8 @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x7f\n\
	ands r0, r2\n\
	movs r2, #0\n\
	strb r0, [r1]\n\
	strb r2, [r1, #1]\n\
_0801CBE2:\n\
	movs r0, #7\n\
	strb r0, [r6]\n\
	b _0801CE88\n\
	.align 2, 0\n\
_0801CBE8: .4byte gCollisionManager\n\
_0801CBEC:\n\
	cmp r0, #7\n\
	bne _0801CC98\n\
	ldr r1, [r5, #0x54]\n\
	ldr r0, _0801CC24 @ =0x001C0FFF\n\
	cmp r1, r0\n\
	ble _0801CC44\n\
	ldr r4, _0801CC28 @ =gCurStory\n\
	ldrb r3, [r4, #4]\n\
	movs r0, #0x20\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	bne _0801CC30\n\
	ldr r0, _0801CC2C @ =gStageRun\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #1\n\
	adds r6, r0, r1\n\
	ldr r0, [r6]\n\
	movs r4, #1\n\
	rsbs r4, r4, #0\n\
	cmp r0, r4\n\
	beq _0801CC44\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r4, [r6]\n\
	b _0801CC44\n\
	.align 2, 0\n\
_0801CC24: .4byte 0x001C0FFF\n\
_0801CC28: .4byte gCurStory\n\
_0801CC2C: .4byte gStageRun\n\
_0801CC30:\n\
	ldr r2, _0801CC8C @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	movs r0, #0xfb\n\
	ands r0, r3\n\
	strb r0, [r4, #4]\n\
	movs r0, #8\n\
	strb r0, [r6]\n\
_0801CC44:\n\
	ldr r1, [r5, #0x54]\n\
	ldr r0, _0801CC90 @ =0x001C2FFF\n\
	cmp r1, r0\n\
	bgt _0801CC4E\n\
	b _0801CE88\n\
_0801CC4E:\n\
	ldr r2, _0801CC8C @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	ldr r0, _0801CC94 @ =gStageRun\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #1\n\
	adds r4, r0, r1\n\
	ldr r0, [r4]\n\
	cmp r0, #0xa1\n\
	beq _0801CC82\n\
	movs r5, #1\n\
	rsbs r5, r5, #0\n\
	cmp r0, r5\n\
	beq _0801CC78\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r5, [r4]\n\
_0801CC78:\n\
	movs r0, #0xa1\n\
	bl playBGM\n\
	movs r0, #0xa1\n\
	str r0, [r4]\n\
_0801CC82:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r7, r0\n\
	movs r0, #8\n\
	b _0801CE86\n\
	.align 2, 0\n\
_0801CC8C: .4byte gCollisionManager\n\
_0801CC90: .4byte 0x001C2FFF\n\
_0801CC94: .4byte gStageRun\n\
_0801CC98:\n\
	cmp r0, #8\n\
	bne _0801CD1C\n\
	ldr r0, _0801CCC4 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
	cmp r2, #0\n\
	bne _0801CCD8\n\
	ldr r1, [r5, #0x54]\n\
	ldr r0, _0801CCC8 @ =0x001CEFFF\n\
	cmp r1, r0\n\
	bgt _0801CCB6\n\
	b _0801CE88\n\
_0801CCB6:\n\
	ldr r0, _0801CCCC @ =gCollisionManager\n\
	strb r2, [r0, #1]\n\
	ldr r0, _0801CCD0 @ =gStageRun+16\n\
	ldr r1, _0801CCD4 @ =gStageScriptList\n\
	ldr r1, [r1, #0x14]\n\
	ldr r1, [r1, #0x28]\n\
	b _0801CD36\n\
	.align 2, 0\n\
_0801CCC4: .4byte gCurStory\n\
_0801CCC8: .4byte 0x001CEFFF\n\
_0801CCCC: .4byte gCollisionManager\n\
_0801CCD0: .4byte gStageRun+16\n\
_0801CCD4: .4byte gStageScriptList\n\
_0801CCD8:\n\
	ldr r1, [r5, #0x54]\n\
	ldr r0, _0801CD08 @ =0x001D0FFF\n\
	cmp r1, r0\n\
	bgt _0801CCE2\n\
	b _0801CE88\n\
_0801CCE2:\n\
	ldr r1, _0801CD0C @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r4, _0801CD10 @ =gStageRun+16\n\
	ldr r0, _0801CD14 @ =gStageScriptList\n\
	ldr r0, [r0, #0x14]\n\
	ldr r1, [r0, #0x44]\n\
	adds r0, r4, #0\n\
	bl SetScript\n\
	subs r4, #0x10\n\
	ldrh r1, [r4, #8]\n\
	ldr r0, _0801CD18 @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r4, #8]\n\
	movs r0, #0xd\n\
	strb r0, [r6]\n\
	b _0801CE88\n\
	.align 2, 0\n\
_0801CD08: .4byte 0x001D0FFF\n\
_0801CD0C: .4byte gCollisionManager\n\
_0801CD10: .4byte gStageRun+16\n\
_0801CD14: .4byte gStageScriptList\n\
_0801CD18: .4byte 0x0000FFFE\n\
_0801CD1C:\n\
	cmp r0, #9\n\
	bne _0801CD58\n\
	ldr r1, [r5, #0x54]\n\
	ldr r0, _0801CD48 @ =0x001D0FFF\n\
	cmp r1, r0\n\
	ble _0801CD58\n\
	ldr r1, _0801CD4C @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r0, _0801CD50 @ =gStageRun+16\n\
	ldr r1, _0801CD54 @ =gStageScriptList\n\
	ldr r1, [r1, #0x14]\n\
	ldr r1, [r1, #0x2c]\n\
_0801CD36:\n\
	bl SetScript\n\
	movs r0, #7\n\
	bl setStageCheckpoint\n\
_0801CD40:\n\
	movs r0, #0xa\n\
	strb r0, [r6]\n\
	b _0801CE88\n\
	.align 2, 0\n\
_0801CD48: .4byte 0x001D0FFF\n\
_0801CD4C: .4byte gCollisionManager\n\
_0801CD50: .4byte gStageRun+16\n\
_0801CD54: .4byte gStageScriptList\n\
_0801CD58:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r5, r7, r1\n\
	ldrb r0, [r5]\n\
	cmp r0, #0xa\n\
	bne _0801CD70\n\
	movs r0, #6\n\
	bl setStageCheckpoint\n\
	movs r0, #0xb\n\
	strb r0, [r5]\n\
	b _0801CE88\n\
_0801CD70:\n\
	cmp r0, #0xb\n\
	bne _0801CDCC\n\
	ldr r4, _0801CDBC @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801CDCC\n\
	ldr r1, _0801CDC0 @ =gCollisionManager\n\
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
	ldr r1, _0801CDC4 @ =gStageScriptList\n\
	ldr r1, [r1, #0x14]\n\
	ldr r1, [r1, #0x34]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r1, _0801CDC8 @ =0x0000FFEF\n\
	ands r1, r0\n\
	ldrb r2, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r2\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #1\n\
	orrs r1, r0\n\
	strh r1, [r4, #8]\n\
	movs r0, #0xc\n\
	strb r0, [r5]\n\
	b _0801CE88\n\
	.align 2, 0\n\
_0801CDBC: .4byte gStageRun\n\
_0801CDC0: .4byte gCollisionManager\n\
_0801CDC4: .4byte gStageScriptList\n\
_0801CDC8: .4byte 0x0000FFEF\n\
_0801CDCC:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r7\n\
	mov r8, r0\n\
	ldrb r0, [r0]\n\
	cmp r0, #0xc\n\
	bne _0801CE20\n\
	ldr r1, _0801CE10 @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x7f\n\
	ands r0, r2\n\
	movs r2, #0\n\
	strb r0, [r1]\n\
	strb r2, [r1, #1]\n\
	ldr r4, _0801CE14 @ =gStageRun+16\n\
	ldr r0, _0801CE18 @ =gStageScriptList\n\
	ldr r0, [r0, #0x14]\n\
	ldr r1, [r0, #0x38]\n\
	adds r0, r4, #0\n\
	bl SetScript\n\
	movs r0, #8\n\
	bl setStageCheckpoint\n\
	subs r4, #0x10\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	ldr r1, _0801CE1C @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r4, #8]\n\
	movs r0, #0xd\n\
	b _0801CE84\n\
	.align 2, 0\n\
_0801CE10: .4byte gCollisionManager\n\
_0801CE14: .4byte gStageRun+16\n\
_0801CE18: .4byte gStageScriptList\n\
_0801CE1C: .4byte 0x0000FFFE\n\
_0801CE20:\n\
	cmp r0, #0x14\n\
	bne _0801CE64\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #1\n\
	adds r1, r7, r0\n\
	ldr r0, [r1]\n\
	cmp r0, #0\n\
	beq _0801CE36\n\
	subs r0, #1\n\
	str r0, [r1]\n\
	b _0801CE88\n\
_0801CE36:\n\
	ldr r4, _0801CE60 @ =gStageRun\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #1\n\
	adds r6, r4, r1\n\
	ldr r0, [r6]\n\
	movs r5, #1\n\
	rsbs r5, r5, #0\n\
	cmp r0, r5\n\
	beq _0801CE52\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r5, [r6]\n\
_0801CE52:\n\
	movs r1, #0xaa\n\
	lsls r1, r1, #1\n\
	adds r0, r4, r1\n\
	movs r1, #2\n\
	str r1, [r0]\n\
	movs r0, #0x15\n\
	b _0801CE84\n\
	.align 2, 0\n\
_0801CE60: .4byte gStageRun\n\
_0801CE64:\n\
	cmp r0, #0x15\n\
	bne _0801CE88\n\
	ldr r2, _0801CE94 @ =gStageRun\n\
	movs r1, #0xaa\n\
	lsls r1, r1, #1\n\
	adds r0, r2, r1\n\
	ldr r0, [r0]\n\
	cmp r0, #0\n\
	bne _0801CE88\n\
	ldrh r1, [r2, #8]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	ldr r1, _0801CE98 @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r2, #8]\n\
	movs r0, #0x16\n\
_0801CE84:\n\
	mov r1, r8\n\
_0801CE86:\n\
	strb r0, [r1]\n\
_0801CE88:\n\
	movs r0, #0\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0801CE94: .4byte gStageRun\n\
_0801CE98: .4byte 0x0000FFFE\n\
 .syntax divided\n");
}

s16 OldResidential_FreeUpdate(struct StageRun* p) { return OldResidential_MissionUpdate(p); }
