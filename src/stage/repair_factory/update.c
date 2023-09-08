#include "global.h"
#include "overworld.h"

/*
checkpoint (0202fe62):
  00: ステージ読み込み中
  01: ブリーフィング
  02: スタートポイント

StageEventPhase (0202ffdc):
  00:
  01:
*/
NAKED s16 RepairFactory_MissionUpdate(struct StageRun* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r7, r0, #0\n\
	ldr r6, [r7, #0x20]\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r5, r7, r0\n\
	ldrb r0, [r5]\n\
	cmp r0, #0\n\
	beq _0801C3E8\n\
	b _0801C534\n\
_0801C3E8:\n\
	ldr r2, _0801C424 @ =gStageRun\n\
	ldrh r1, [r2, #8]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	strh r0, [r2, #8]\n\
	ldr r3, _0801C428 @ =gCurStory\n\
	ldrb r0, [r3, #4]\n\
	movs r6, #0xfb\n\
	ands r6, r0\n\
	strb r6, [r3, #4]\n\
	movs r0, #0x40\n\
	ands r0, r6\n\
	cmp r0, #0\n\
	beq _0801C430\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801C42C @ =gStageScriptList\n\
	ldr r1, [r1, #0x10]\n\
	ldr r1, [r1, #0x30]\n\
	bl SetScript\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #1\n\
	adds r1, r7, r0\n\
	movs r0, #0xe1\n\
	lsls r0, r0, #3\n\
	str r0, [r1]\n\
	movs r0, #0x14\n\
	strb r0, [r5]\n\
	b _0801C91E\n\
	.align 2, 0\n\
_0801C424: .4byte gStageRun\n\
_0801C428: .4byte gCurStory\n\
_0801C42C: .4byte gStageScriptList\n\
_0801C430:\n\
	ldrb r4, [r2, #2]\n\
	cmp r4, #0\n\
	bne _0801C490\n\
	ldrb r1, [r3, #9]\n\
	movs r0, #0xdf\n\
	ands r0, r1\n\
	movs r1, #0xbf\n\
	ands r0, r1\n\
	movs r1, #0x7f\n\
	ands r0, r1\n\
	strb r0, [r3, #9]\n\
	ldrb r1, [r3, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r3, #0xa]\n\
	movs r0, #0x20\n\
	ands r0, r6\n\
	cmp r0, #0\n\
	bne _0801C46C\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801C468 @ =gStageScriptList\n\
	ldr r1, [r1, #0x10]\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
	b _0801C47A\n\
	.align 2, 0\n\
_0801C468: .4byte gStageScriptList\n\
_0801C46C:\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801C48C @ =gStageScriptList\n\
	ldr r1, [r1, #0x10]\n\
	ldr r1, [r1, #0x34]\n\
	bl SetScript\n\
_0801C47A:\n\
	movs r0, #1\n\
	bl setStageCheckpoint\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r7, r0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	b _0801C91E\n\
	.align 2, 0\n\
_0801C48C: .4byte gStageScriptList\n\
_0801C490:\n\
	cmp r4, #1\n\
	bne _0801C4A8\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801C4A4 @ =gStageScriptList\n\
	ldr r1, [r1, #0x10]\n\
	ldr r1, [r1, #4]\n\
	bl SetScript\n\
	b _0801C538\n\
	.align 2, 0\n\
_0801C4A4: .4byte gStageScriptList\n\
_0801C4A8:\n\
	cmp r4, #2\n\
	bne _0801C4C4\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801C4C0 @ =gStageScriptList\n\
	ldr r1, [r1, #0x10]\n\
	ldr r1, [r1, #8]\n\
	bl SetScript\n\
	strb r4, [r5]\n\
	b _0801C91E\n\
	.align 2, 0\n\
_0801C4C0: .4byte gStageScriptList\n\
_0801C4C4:\n\
	cmp r4, #3\n\
	bne _0801C4DC\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801C4D8 @ =gStageScriptList\n\
	ldr r1, [r1, #0x10]\n\
	ldr r1, [r1, #0xc]\n\
	bl SetScript\n\
	b _0801C53E\n\
	.align 2, 0\n\
_0801C4D8: .4byte gStageScriptList\n\
_0801C4DC:\n\
	cmp r4, #4\n\
	bne _0801C4F8\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801C4F4 @ =gStageScriptList\n\
	ldr r1, [r1, #0x10]\n\
	ldr r1, [r1, #0x18]\n\
	bl SetScript\n\
	movs r0, #6\n\
	strb r0, [r5]\n\
	b _0801C91E\n\
	.align 2, 0\n\
_0801C4F4: .4byte gStageScriptList\n\
_0801C4F8:\n\
	cmp r4, #5\n\
	bne _0801C514\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801C510 @ =gStageScriptList\n\
	ldr r1, [r1, #0x10]\n\
	ldr r1, [r1, #0x1c]\n\
	bl SetScript\n\
	movs r0, #8\n\
	strb r0, [r5]\n\
	b _0801C91E\n\
	.align 2, 0\n\
_0801C510: .4byte gStageScriptList\n\
_0801C514:\n\
	cmp r4, #6\n\
	beq _0801C51A\n\
	b _0801C91E\n\
_0801C51A:\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801C530 @ =gStageScriptList\n\
	ldr r1, [r1, #0x10]\n\
	ldr r1, [r1, #0x28]\n\
	bl SetScript\n\
	movs r0, #9\n\
	strb r0, [r5]\n\
	b _0801C91E\n\
	.align 2, 0\n\
_0801C530: .4byte gStageScriptList\n\
_0801C534:\n\
	cmp r0, #1\n\
	bne _0801C544\n\
_0801C538:\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
_0801C53E:\n\
	movs r0, #2\n\
	strb r0, [r5]\n\
	b _0801C91E\n\
_0801C544:\n\
	cmp r0, #2\n\
	bne _0801C584\n\
	ldr r1, [r6, #0x54]\n\
	ldr r0, _0801C574 @ =0x000F0FFF\n\
	cmp r1, r0\n\
	ble _0801C584\n\
	ldr r0, _0801C578 @ =gStageRun+16\n\
	ldr r1, _0801C57C @ =gStageScriptList\n\
	ldr r1, [r1, #0x10]\n\
	ldr r1, [r1, #0x10]\n\
	bl SetScript\n\
	movs r0, #3\n\
	bl setStageCheckpoint\n\
	ldr r2, _0801C580 @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	movs r0, #3\n\
	strb r0, [r5]\n\
	b _0801C91E\n\
	.align 2, 0\n\
_0801C574: .4byte 0x000F0FFF\n\
_0801C578: .4byte gStageRun+16\n\
_0801C57C: .4byte gStageScriptList\n\
_0801C580: .4byte gCurStory\n\
_0801C584:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r5, r7, r1\n\
	ldrb r0, [r5]\n\
	cmp r0, #3\n\
	bne _0801C5F4\n\
	ldr r4, _0801C5E0 @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801C5F4\n\
	ldr r1, _0801C5E4 @ =gCollisionManager\n\
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
	ldr r1, _0801C5E8 @ =gStageScriptList\n\
	ldr r1, [r1, #0x10]\n\
	ldr r1, [r1, #0x14]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r2, _0801C5EC @ =0x0000FFEF\n\
	ands r2, r0\n\
	ldrb r1, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0x12]\n\
	ldr r3, _0801C5F0 @ =gCurStory\n\
	ldrb r1, [r3, #4]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r3, #4]\n\
	movs r0, #1\n\
	orrs r2, r0\n\
	strh r2, [r4, #8]\n\
	movs r0, #4\n\
	strb r0, [r5]\n\
	b _0801C91E\n\
	.align 2, 0\n\
_0801C5E0: .4byte gStageRun\n\
_0801C5E4: .4byte gCollisionManager\n\
_0801C5E8: .4byte gStageScriptList\n\
_0801C5EC: .4byte 0x0000FFEF\n\
_0801C5F0: .4byte gCurStory\n\
_0801C5F4:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r4, r7, r0\n\
	ldrb r0, [r4]\n\
	cmp r0, #4\n\
	bne _0801C618\n\
	ldr r1, _0801C614 @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x7f\n\
	ands r0, r2\n\
	movs r2, #0\n\
	strb r0, [r1]\n\
	strb r2, [r1, #1]\n\
	movs r0, #5\n\
	strb r0, [r4]\n\
	b _0801C91E\n\
	.align 2, 0\n\
_0801C614: .4byte gCollisionManager\n\
_0801C618:\n\
	cmp r0, #5\n\
	bne _0801C644\n\
	ldr r1, [r6, #0x54]\n\
	ldr r0, _0801C63C @ =0x000FFFFF\n\
	cmp r1, r0\n\
	ble _0801C644\n\
	movs r0, #4\n\
	bl setStageCheckpoint\n\
	ldr r2, _0801C640 @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	movs r0, #6\n\
	strb r0, [r4]\n\
	b _0801C91E\n\
	.align 2, 0\n\
_0801C63C: .4byte 0x000FFFFF\n\
_0801C640: .4byte gCurStory\n\
_0801C644:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r3, r7, r1\n\
	ldrb r0, [r3]\n\
	cmp r0, #6\n\
	bne _0801C6F4\n\
	ldr r1, [r6, #0x54]\n\
	ldr r0, _0801C684 @ =0x001A2FFF\n\
	cmp r1, r0\n\
	ble _0801C69E\n\
	ldr r0, _0801C688 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0801C690\n\
	ldr r0, _0801C68C @ =gStageRun\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #1\n\
	adds r5, r0, r1\n\
	ldr r0, [r5]\n\
	movs r4, #1\n\
	rsbs r4, r4, #0\n\
	cmp r0, r4\n\
	beq _0801C69E\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r4, [r5]\n\
	b _0801C69E\n\
	.align 2, 0\n\
_0801C684: .4byte 0x001A2FFF\n\
_0801C688: .4byte gCurStory\n\
_0801C68C: .4byte gStageRun\n\
_0801C690:\n\
	ldr r2, _0801C6E8 @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	movs r0, #7\n\
	strb r0, [r3]\n\
_0801C69E:\n\
	ldr r1, [r6, #0x54]\n\
	ldr r0, _0801C6EC @ =0x001A4FFF\n\
	cmp r1, r0\n\
	bgt _0801C6A8\n\
	b _0801C91E\n\
_0801C6A8:\n\
	ldr r2, _0801C6E8 @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	ldr r0, _0801C6F0 @ =gStageRun\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #1\n\
	adds r4, r0, r1\n\
	ldr r0, [r4]\n\
	cmp r0, #0xa1\n\
	beq _0801C6DC\n\
	movs r5, #1\n\
	rsbs r5, r5, #0\n\
	cmp r0, r5\n\
	beq _0801C6D2\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r5, [r4]\n\
_0801C6D2:\n\
	movs r0, #0xa1\n\
	bl playBGM\n\
	movs r0, #0xa1\n\
	str r0, [r4]\n\
_0801C6DC:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r7, r0\n\
	movs r0, #7\n\
	strb r0, [r1]\n\
	b _0801C91E\n\
	.align 2, 0\n\
_0801C6E8: .4byte gCollisionManager\n\
_0801C6EC: .4byte 0x001A4FFF\n\
_0801C6F0: .4byte gStageRun\n\
_0801C6F4:\n\
	cmp r0, #7\n\
	bne _0801C76C\n\
	ldr r1, [r6, #0x54]\n\
	ldr r0, _0801C720 @ =0x001B2FFF\n\
	cmp r1, r0\n\
	ble _0801C76C\n\
	ldr r1, _0801C724 @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r0, _0801C728 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0801C734\n\
	ldr r0, _0801C72C @ =gStageRun+16\n\
	ldr r1, _0801C730 @ =gStageScriptList\n\
	ldr r1, [r1, #0x10]\n\
	ldr r1, [r1, #0x20]\n\
	bl SetScript\n\
	b _0801C74C\n\
	.align 2, 0\n\
_0801C720: .4byte 0x001B2FFF\n\
_0801C724: .4byte gCollisionManager\n\
_0801C728: .4byte gCurStory\n\
_0801C72C: .4byte gStageRun+16\n\
_0801C730: .4byte gStageScriptList\n\
_0801C734:\n\
	ldr r4, _0801C760 @ =gStageRun+16\n\
	ldr r0, _0801C764 @ =gStageScriptList\n\
	ldr r0, [r0, #0x10]\n\
	ldr r1, [r0, #0x38]\n\
	adds r0, r4, #0\n\
	bl SetScript\n\
	subs r4, #0x10\n\
	ldrh r1, [r4, #8]\n\
	ldr r0, _0801C768 @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r4, #8]\n\
_0801C74C:\n\
	movs r0, #6\n\
	bl setStageCheckpoint\n\
_0801C752:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r7, r0\n\
	movs r0, #9\n\
	strb r0, [r1]\n\
	b _0801C91E\n\
	.align 2, 0\n\
_0801C760: .4byte gStageRun+16\n\
_0801C764: .4byte gStageScriptList\n\
_0801C768: .4byte 0x0000FFFE\n\
_0801C76C:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r4, r7, r1\n\
	ldrb r0, [r4]\n\
	cmp r0, #8\n\
	bne _0801C7B0\n\
	ldr r1, [r6, #0x54]\n\
	ldr r0, _0801C7A0 @ =0x001B2FFF\n\
	cmp r1, r0\n\
	ble _0801C7B0\n\
	ldr r1, _0801C7A4 @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r0, _0801C7A8 @ =gStageRun+16\n\
	ldr r1, _0801C7AC @ =gStageScriptList\n\
	ldr r1, [r1, #0x10]\n\
	ldr r1, [r1, #0x24]\n\
	bl SetScript\n\
	movs r0, #6\n\
	bl setStageCheckpoint\n\
	movs r0, #9\n\
	strb r0, [r4]\n\
	b _0801C91E\n\
	.align 2, 0\n\
_0801C7A0: .4byte 0x001B2FFF\n\
_0801C7A4: .4byte gCollisionManager\n\
_0801C7A8: .4byte gStageRun+16\n\
_0801C7AC: .4byte gStageScriptList\n\
_0801C7B0:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r4, r7, r0\n\
	ldrb r0, [r4]\n\
	cmp r0, #9\n\
	bne _0801C7C8\n\
	movs r0, #5\n\
	bl setStageCheckpoint\n\
	movs r0, #0xa\n\
	strb r0, [r4]\n\
	b _0801C91E\n\
_0801C7C8:\n\
	cmp r0, #0xa\n\
	bne _0801C8B0\n\
	ldr r0, _0801C814 @ =gStageRun\n\
	ldrh r1, [r0, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801C8B0\n\
	ldr r4, _0801C818 @ =gCurStory\n\
	ldrb r5, [r4, #9]\n\
	lsls r2, r5, #0x18\n\
	lsrs r0, r2, #0x1d\n\
	movs r3, #1\n\
	adds r1, r3, #0\n\
	bics r1, r0\n\
	lsrs r2, r2, #0x1e\n\
	adds r0, r3, #0\n\
	bics r0, r2\n\
	adds r2, r1, r0\n\
	ldrb r0, [r4, #0xa]\n\
	bics r3, r0\n\
	ldr r1, _0801C81C @ =gMission\n\
	movs r6, #7\n\
	ldrsb r6, [r1, r6]\n\
	movs r0, #0x80\n\
	ands r0, r5\n\
	adds r5, r4, #0\n\
	adds r4, r1, #0\n\
	cmp r0, #0\n\
	bne _0801C820\n\
	adds r1, r3, #1\n\
	adds r1, r2, r1\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	subs r0, r6, r0\n\
	cmp r0, #0\n\
	bgt _0801C82C\n\
	b _0801C864\n\
	.align 2, 0\n\
_0801C814: .4byte gStageRun\n\
_0801C818: .4byte gCurStory\n\
_0801C81C: .4byte gMission\n\
_0801C820:\n\
	adds r1, r2, r3\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	subs r0, r6, r0\n\
	cmp r0, #0\n\
	ble _0801C864\n\
_0801C82C:\n\
	adds r6, r4, #0\n\
	ldrb r4, [r5, #9]\n\
	lsls r2, r4, #0x18\n\
	lsrs r0, r2, #0x1d\n\
	movs r3, #1\n\
	adds r1, r3, #0\n\
	bics r1, r0\n\
	lsrs r2, r2, #0x1e\n\
	adds r0, r3, #0\n\
	bics r0, r2\n\
	adds r2, r1, r0\n\
	ldrb r0, [r5, #0xa]\n\
	bics r3, r0\n\
	movs r5, #7\n\
	ldrsb r5, [r6, r5]\n\
	movs r0, #0x80\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	bne _0801C858\n\
	adds r1, r3, #1\n\
	adds r1, r2, r1\n\
	b _0801C85A\n\
_0801C858:\n\
	adds r1, r2, r3\n\
_0801C85A:\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	subs r0, r5, r0\n\
	strb r0, [r6, #7]\n\
	b _0801C868\n\
_0801C864:\n\
	movs r0, #0\n\
	strb r0, [r4, #7]\n\
_0801C868:\n\
	ldr r1, _0801C8A0 @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x80\n\
	orrs r0, r2\n\
	strb r0, [r1]\n\
	ldrb r2, [r1, #1]\n\
	movs r0, #2\n\
	orrs r0, r2\n\
	strb r0, [r1, #1]\n\
	ldr r4, _0801C8A4 @ =gStageRun+16\n\
	ldr r0, _0801C8A8 @ =gStageScriptList\n\
	ldr r0, [r0, #0x10]\n\
	ldr r1, [r0, #0x2c]\n\
	adds r0, r4, #0\n\
	bl SetScript\n\
	subs r4, #0x10\n\
	ldrh r0, [r4, #8]\n\
	ldr r1, _0801C8AC @ =0x0000FFEF\n\
	ands r1, r0\n\
	ldrb r2, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r2\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #4\n\
	orrs r1, r0\n\
	strh r1, [r4, #8]\n\
	b _0801C752\n\
	.align 2, 0\n\
_0801C8A0: .4byte gCollisionManager\n\
_0801C8A4: .4byte gStageRun+16\n\
_0801C8A8: .4byte gStageScriptList\n\
_0801C8AC: .4byte 0x0000FFEF\n\
_0801C8B0:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r6, r7, r1\n\
	ldrb r0, [r6]\n\
	cmp r0, #0x14\n\
	bne _0801C8FC\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #1\n\
	adds r1, r7, r0\n\
	ldr r0, [r1]\n\
	cmp r0, #0\n\
	beq _0801C8CE\n\
	subs r0, #1\n\
	str r0, [r1]\n\
	b _0801C91E\n\
_0801C8CE:\n\
	ldr r4, _0801C8F8 @ =gStageRun\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #1\n\
	adds r7, r4, r1\n\
	ldr r0, [r7]\n\
	movs r5, #1\n\
	rsbs r5, r5, #0\n\
	cmp r0, r5\n\
	beq _0801C8EA\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r5, [r7]\n\
_0801C8EA:\n\
	movs r1, #0xaa\n\
	lsls r1, r1, #1\n\
	adds r0, r4, r1\n\
	movs r1, #2\n\
	str r1, [r0]\n\
	movs r0, #0x15\n\
	b _0801C91C\n\
	.align 2, 0\n\
_0801C8F8: .4byte gStageRun\n\
_0801C8FC:\n\
	cmp r0, #0x15\n\
	bne _0801C91E\n\
	ldr r2, _0801C928 @ =gStageRun\n\
	movs r1, #0xaa\n\
	lsls r1, r1, #1\n\
	adds r0, r2, r1\n\
	ldr r0, [r0]\n\
	cmp r0, #0\n\
	bne _0801C91E\n\
	ldrh r1, [r2, #8]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	ldr r1, _0801C92C @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r2, #8]\n\
	movs r0, #0x16\n\
_0801C91C:\n\
	strb r0, [r6]\n\
_0801C91E:\n\
	movs r0, #0\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0801C928: .4byte gStageRun\n\
_0801C92C: .4byte 0x0000FFFE\n\
 .syntax divided\n");
}

s16 RepairFactory_FreeUpdate(struct StageRun* p) { return RepairFactory_MissionUpdate(p); }
