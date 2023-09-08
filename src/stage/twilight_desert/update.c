#include "global.h"
#include "overworld.h"

NAKED s16 TwilightDesert_MissionUpdate(struct StageRun* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r6, r0, #0\n\
	ldr r2, [r6, #0x20]\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r5, r6, r0\n\
	ldrb r0, [r5]\n\
	cmp r0, #0\n\
	beq _0801D520\n\
	b _0801D60C\n\
_0801D520:\n\
	ldr r2, _0801D54C @ =gStageRun\n\
	ldrh r1, [r2, #8]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	strh r0, [r2, #8]\n\
	ldrb r4, [r2, #2]\n\
	cmp r4, #0\n\
	bne _0801D57C\n\
	ldr r0, _0801D550 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0801D558\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801D554 @ =gStageScriptList\n\
	ldr r1, [r1, #0x1c]\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
	b _0801D566\n\
	.align 2, 0\n\
_0801D54C: .4byte gStageRun\n\
_0801D550: .4byte gCurStory\n\
_0801D554: .4byte gStageScriptList\n\
_0801D558:\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801D578 @ =gStageScriptList\n\
	ldr r1, [r1, #0x1c]\n\
	ldr r1, [r1, #0x2c]\n\
	bl SetScript\n\
_0801D566:\n\
	movs r0, #1\n\
	bl setStageCheckpoint\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r6, r0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	b _0801D85A\n\
	.align 2, 0\n\
_0801D578: .4byte gStageScriptList\n\
_0801D57C:\n\
	cmp r4, #1\n\
	bne _0801D59C\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801D598 @ =gStageScriptList\n\
	ldr r1, [r1, #0x1c]\n\
	ldr r1, [r1, #4]\n\
	bl SetScript\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	movs r0, #2\n\
	b _0801D858\n\
	.align 2, 0\n\
_0801D598: .4byte gStageScriptList\n\
_0801D59C:\n\
	cmp r4, #2\n\
	bne _0801D5B8\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801D5B4 @ =gStageScriptList\n\
	ldr r1, [r1, #0x1c]\n\
	ldr r1, [r1, #8]\n\
	bl SetScript\n\
	strb r4, [r5]\n\
	b _0801D85A\n\
	.align 2, 0\n\
_0801D5B4: .4byte gStageScriptList\n\
_0801D5B8:\n\
	cmp r4, #3\n\
	bne _0801D5D4\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801D5D0 @ =gStageScriptList\n\
	ldr r1, [r1, #0x1c]\n\
	ldr r1, [r1, #0x14]\n\
	bl SetScript\n\
	movs r0, #6\n\
	b _0801D858\n\
	.align 2, 0\n\
_0801D5D0: .4byte gStageScriptList\n\
_0801D5D4:\n\
	cmp r4, #4\n\
	bne _0801D5F0\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801D5EC @ =gStageScriptList\n\
	ldr r1, [r1, #0x1c]\n\
	ldr r1, [r1, #0x18]\n\
	bl SetScript\n\
	movs r0, #8\n\
	b _0801D858\n\
	.align 2, 0\n\
_0801D5EC: .4byte gStageScriptList\n\
_0801D5F0:\n\
	cmp r4, #5\n\
	beq _0801D5F6\n\
	b _0801D85A\n\
_0801D5F6:\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801D608 @ =gStageScriptList\n\
	ldr r1, [r1, #0x1c]\n\
	ldr r1, [r1, #0x24]\n\
	bl SetScript\n\
	movs r0, #0xa\n\
	b _0801D858\n\
	.align 2, 0\n\
_0801D608: .4byte gStageScriptList\n\
_0801D60C:\n\
	cmp r0, #1\n\
	bne _0801D61A\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	movs r0, #2\n\
	b _0801D858\n\
_0801D61A:\n\
	cmp r0, #2\n\
	bne _0801D63C\n\
	ldr r1, [r2, #0x54]\n\
	ldr r0, _0801D634 @ =0x0010FFFF\n\
	cmp r1, r0\n\
	ble _0801D63C\n\
	ldr r2, _0801D638 @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	movs r0, #3\n\
	b _0801D858\n\
	.align 2, 0\n\
_0801D634: .4byte 0x0010FFFF\n\
_0801D638: .4byte gCollisionManager\n\
_0801D63C:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r5, r6, r1\n\
	ldrb r0, [r5]\n\
	cmp r0, #3\n\
	bne _0801D66C\n\
	ldr r1, _0801D660 @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r0, _0801D664 @ =gStageRun+16\n\
	ldr r1, _0801D668 @ =gStageScriptList\n\
	ldr r1, [r1, #0x1c]\n\
	ldr r1, [r1, #0xc]\n\
	bl SetScript\n\
	movs r0, #4\n\
	b _0801D858\n\
	.align 2, 0\n\
_0801D660: .4byte gCollisionManager\n\
_0801D664: .4byte gStageRun+16\n\
_0801D668: .4byte gStageScriptList\n\
_0801D66C:\n\
	cmp r0, #4\n\
	bne _0801D6C4\n\
	ldr r4, _0801D6B4 @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801D6C4\n\
	ldr r1, _0801D6B8 @ =gCollisionManager\n\
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
	ldr r1, _0801D6BC @ =gStageScriptList\n\
	ldr r1, [r1, #0x1c]\n\
	ldr r1, [r1, #0x10]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r1, _0801D6C0 @ =0x0000FFEF\n\
	ands r1, r0\n\
	ldrb r2, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r2\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #1\n\
	orrs r1, r0\n\
	strh r1, [r4, #8]\n\
	movs r0, #5\n\
	b _0801D858\n\
	.align 2, 0\n\
_0801D6B4: .4byte gStageRun\n\
_0801D6B8: .4byte gCollisionManager\n\
_0801D6BC: .4byte gStageScriptList\n\
_0801D6C0: .4byte 0x0000FFEF\n\
_0801D6C4:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r5, r6, r0\n\
	ldrb r0, [r5]\n\
	cmp r0, #5\n\
	bne _0801D6EC\n\
	ldr r1, _0801D6E8 @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x7f\n\
	ands r0, r2\n\
	movs r2, #0\n\
	strb r0, [r1]\n\
	strb r2, [r1, #1]\n\
	movs r0, #3\n\
	bl setStageCheckpoint\n\
	movs r0, #6\n\
	b _0801D858\n\
	.align 2, 0\n\
_0801D6E8: .4byte gCollisionManager\n\
_0801D6EC:\n\
	cmp r0, #6\n\
	bne _0801D730\n\
	ldr r1, [r2, #0x54]\n\
	ldr r0, _0801D724 @ =0x0021BFFF\n\
	cmp r1, r0\n\
	bgt _0801D6FA\n\
	b _0801D85A\n\
_0801D6FA:\n\
	ldr r0, _0801D728 @ =gStageRun\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #1\n\
	adds r6, r0, r1\n\
	ldr r0, [r6]\n\
	movs r4, #1\n\
	rsbs r4, r4, #0\n\
	cmp r0, r4\n\
	beq _0801D716\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r4, [r6]\n\
_0801D716:\n\
	ldr r2, _0801D72C @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	movs r0, #7\n\
	b _0801D858\n\
	.align 2, 0\n\
_0801D724: .4byte 0x0021BFFF\n\
_0801D728: .4byte gStageRun\n\
_0801D72C: .4byte gCollisionManager\n\
_0801D730:\n\
	cmp r0, #7\n\
	bne _0801D794\n\
	ldr r1, _0801D75C @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r0, _0801D760 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0801D76C\n\
	ldr r0, _0801D764 @ =gStageRun+16\n\
	ldr r1, _0801D768 @ =gStageScriptList\n\
	ldr r1, [r1, #0x1c]\n\
	ldr r1, [r1, #0x1c]\n\
	bl SetScript\n\
	movs r0, #5\n\
	bl setStageCheckpoint\n\
	movs r0, #0xa\n\
	b _0801D858\n\
	.align 2, 0\n\
_0801D75C: .4byte gCollisionManager\n\
_0801D760: .4byte gCurStory\n\
_0801D764: .4byte gStageRun+16\n\
_0801D768: .4byte gStageScriptList\n\
_0801D76C:\n\
	ldr r4, _0801D788 @ =gStageRun+16\n\
	ldr r0, _0801D78C @ =gStageScriptList\n\
	ldr r0, [r0, #0x1c]\n\
	ldr r1, [r0, #0x30]\n\
	adds r0, r4, #0\n\
	bl SetScript\n\
	subs r4, #0x10\n\
	ldrh r1, [r4, #8]\n\
	ldr r0, _0801D790 @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r4, #8]\n\
	b _0801D856\n\
	.align 2, 0\n\
_0801D788: .4byte gStageRun+16\n\
_0801D78C: .4byte gStageScriptList\n\
_0801D790: .4byte 0x0000FFFE\n\
_0801D794:\n\
	cmp r0, #8\n\
	bne _0801D7D8\n\
	ldr r1, [r2, #0x54]\n\
	ldr r0, _0801D7CC @ =0x0021BFFF\n\
	cmp r1, r0\n\
	ble _0801D85A\n\
	ldr r0, _0801D7D0 @ =gStageRun\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #1\n\
	adds r6, r0, r1\n\
	ldr r0, [r6]\n\
	movs r4, #1\n\
	rsbs r4, r4, #0\n\
	cmp r0, r4\n\
	beq _0801D7BC\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r4, [r6]\n\
_0801D7BC:\n\
	ldr r2, _0801D7D4 @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	movs r0, #9\n\
	b _0801D858\n\
	.align 2, 0\n\
_0801D7CC: .4byte 0x0021BFFF\n\
_0801D7D0: .4byte gStageRun\n\
_0801D7D4: .4byte gCollisionManager\n\
_0801D7D8:\n\
	cmp r0, #9\n\
	bne _0801D804\n\
	ldr r1, _0801D7F8 @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r0, _0801D7FC @ =gStageRun+16\n\
	ldr r1, _0801D800 @ =gStageScriptList\n\
	ldr r1, [r1, #0x1c]\n\
	ldr r1, [r1, #0x20]\n\
	bl SetScript\n\
	movs r0, #5\n\
	bl setStageCheckpoint\n\
	movs r0, #0xa\n\
	b _0801D858\n\
	.align 2, 0\n\
_0801D7F8: .4byte gCollisionManager\n\
_0801D7FC: .4byte gStageRun+16\n\
_0801D800: .4byte gStageScriptList\n\
_0801D804:\n\
	cmp r0, #0xa\n\
	bne _0801D812\n\
	movs r0, #4\n\
	bl setStageCheckpoint\n\
	movs r0, #0xb\n\
	b _0801D858\n\
_0801D812:\n\
	cmp r0, #0xb\n\
	bne _0801D85A\n\
	ldr r4, _0801D864 @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801D85A\n\
	ldr r1, _0801D868 @ =gCollisionManager\n\
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
	ldr r1, _0801D86C @ =gStageScriptList\n\
	ldr r1, [r1, #0x1c]\n\
	ldr r1, [r1, #0x28]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r1, _0801D870 @ =0x0000FFEF\n\
	ands r1, r0\n\
	ldrb r2, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r2\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #4\n\
	orrs r1, r0\n\
	strh r1, [r4, #8]\n\
_0801D856:\n\
	movs r0, #0xc\n\
_0801D858:\n\
	strb r0, [r5]\n\
_0801D85A:\n\
	movs r0, #0\n\
	pop {r4, r5, r6}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0801D864: .4byte gStageRun\n\
_0801D868: .4byte gCollisionManager\n\
_0801D86C: .4byte gStageScriptList\n\
_0801D870: .4byte 0x0000FFEF\n\
	 .syntax divided\n");
}

s16 TwilightDesert_FreeUpdate(struct StageRun* p) { return TwilightDesert_MissionUpdate(p); }
