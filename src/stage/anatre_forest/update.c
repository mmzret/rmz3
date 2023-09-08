#include "global.h"
#include "overworld.h"

NAKED s16 AnatreForest_MissionUpdate(struct StageRun* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r6, r0, #0\n\
	ldr r4, [r6, #0x20]\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r5, r6, r0\n\
	ldrb r0, [r5]\n\
	cmp r0, #0\n\
	bne _0801D950\n\
	ldr r1, _0801D8C0 @ =gStageRun\n\
	ldrh r0, [r1, #8]\n\
	movs r6, #1\n\
	orrs r0, r6\n\
	strh r0, [r1, #8]\n\
	ldrb r4, [r1, #2]\n\
	cmp r4, #0\n\
	bne _0801D8C8\n\
	adds r0, r1, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801D8C4 @ =gStageScriptList\n\
	ldr r1, [r1, #0x20]\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
	movs r0, #1\n\
	bl setStageCheckpoint\n\
	strb r6, [r5]\n\
	b _0801DADA\n\
	.align 2, 0\n\
_0801D8C0: .4byte gStageRun\n\
_0801D8C4: .4byte gStageScriptList\n\
_0801D8C8:\n\
	cmp r4, #1\n\
	bne _0801D8E8\n\
	adds r0, r1, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801D8E4 @ =gStageScriptList\n\
	ldr r1, [r1, #0x20]\n\
	ldr r1, [r1, #4]\n\
	bl SetScript\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	movs r0, #2\n\
	b _0801DAD8\n\
	.align 2, 0\n\
_0801D8E4: .4byte gStageScriptList\n\
_0801D8E8:\n\
	cmp r4, #2\n\
	bne _0801D8FC\n\
	adds r0, r1, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801D8F8 @ =gStageScriptList\n\
	ldr r1, [r1, #0x20]\n\
	ldr r1, [r1, #8]\n\
	b _0801D90A\n\
	.align 2, 0\n\
_0801D8F8: .4byte gStageScriptList\n\
_0801D8FC:\n\
	cmp r4, #3\n\
	bne _0801D918\n\
	adds r0, r1, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801D914 @ =gStageScriptList\n\
	ldr r1, [r1, #0x20]\n\
	ldr r1, [r1, #0xc]\n\
_0801D90A:\n\
	bl SetScript\n\
	strb r4, [r5]\n\
	b _0801DADA\n\
	.align 2, 0\n\
_0801D914: .4byte gStageScriptList\n\
_0801D918:\n\
	cmp r4, #4\n\
	bne _0801D934\n\
	adds r0, r1, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801D930 @ =gStageScriptList\n\
	ldr r1, [r1, #0x20]\n\
	ldr r1, [r1, #0x10]\n\
	bl SetScript\n\
	movs r0, #5\n\
	b _0801DAD8\n\
	.align 2, 0\n\
_0801D930: .4byte gStageScriptList\n\
_0801D934:\n\
	cmp r4, #5\n\
	beq _0801D93A\n\
	b _0801DADA\n\
_0801D93A:\n\
	adds r0, r1, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801D94C @ =gStageScriptList\n\
	ldr r1, [r1, #0x20]\n\
	ldr r1, [r1, #0x1c]\n\
	bl SetScript\n\
	movs r0, #6\n\
	b _0801DAD8\n\
	.align 2, 0\n\
_0801D94C: .4byte gStageScriptList\n\
_0801D950:\n\
	cmp r0, #1\n\
	bne _0801D95E\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	movs r0, #2\n\
	b _0801DAD8\n\
_0801D95E:\n\
	cmp r0, #2\n\
	bne _0801D978\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _0801D974 @ =0x000A4FFF\n\
	cmp r1, r0\n\
	ble _0801D978\n\
	movs r0, #3\n\
	bl setStageCheckpoint\n\
	movs r0, #3\n\
	b _0801DAD8\n\
	.align 2, 0\n\
_0801D974: .4byte 0x000A4FFF\n\
_0801D978:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r5, r6, r1\n\
	ldrb r0, [r5]\n\
	cmp r0, #3\n\
	bne _0801DA04\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _0801D9F4 @ =0x001C0FFF\n\
	cmp r1, r0\n\
	ble _0801D9A8\n\
	ldr r0, _0801D9F8 @ =gStageRun\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #1\n\
	adds r7, r0, r1\n\
	ldr r0, [r7]\n\
	movs r5, #1\n\
	rsbs r5, r5, #0\n\
	cmp r0, r5\n\
	beq _0801D9A8\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r5, [r7]\n\
_0801D9A8:\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _0801D9FC @ =0x001C2FFF\n\
	cmp r1, r0\n\
	bgt _0801D9B2\n\
	b _0801DADA\n\
_0801D9B2:\n\
	ldr r2, _0801DA00 @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	ldr r0, _0801D9F8 @ =gStageRun\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #1\n\
	adds r4, r0, r1\n\
	ldr r0, [r4]\n\
	cmp r0, #0xa1\n\
	beq _0801D9E6\n\
	movs r5, #1\n\
	rsbs r5, r5, #0\n\
	cmp r0, r5\n\
	beq _0801D9DC\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r5, [r4]\n\
_0801D9DC:\n\
	movs r0, #0xa1\n\
	bl playBGM\n\
	movs r0, #0xa1\n\
	str r0, [r4]\n\
_0801D9E6:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r6, r0\n\
	movs r0, #4\n\
	strb r0, [r1]\n\
	b _0801DADA\n\
	.align 2, 0\n\
_0801D9F4: .4byte 0x001C0FFF\n\
_0801D9F8: .4byte gStageRun\n\
_0801D9FC: .4byte 0x001C2FFF\n\
_0801DA00: .4byte gCollisionManager\n\
_0801DA04:\n\
	cmp r0, #4\n\
	bne _0801DA3C\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _0801DA2C @ =0x001D0FFF\n\
	cmp r1, r0\n\
	ble _0801DA3C\n\
	ldr r1, _0801DA30 @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r0, _0801DA34 @ =gStageRun+16\n\
	ldr r1, _0801DA38 @ =gStageScriptList\n\
	ldr r1, [r1, #0x20]\n\
	ldr r1, [r1, #0x14]\n\
	bl SetScript\n\
	movs r0, #5\n\
	bl setStageCheckpoint\n\
	movs r0, #6\n\
	b _0801DAD8\n\
	.align 2, 0\n\
_0801DA2C: .4byte 0x001D0FFF\n\
_0801DA30: .4byte gCollisionManager\n\
_0801DA34: .4byte gStageRun+16\n\
_0801DA38: .4byte gStageScriptList\n\
_0801DA3C:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r5, r6, r1\n\
	ldrb r0, [r5]\n\
	cmp r0, #5\n\
	bne _0801DA7C\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _0801DA6C @ =0x001D0FFF\n\
	cmp r1, r0\n\
	ble _0801DA7C\n\
	ldr r1, _0801DA70 @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r0, _0801DA74 @ =gStageRun+16\n\
	ldr r1, _0801DA78 @ =gStageScriptList\n\
	ldr r1, [r1, #0x20]\n\
	ldr r1, [r1, #0x18]\n\
	bl SetScript\n\
	movs r0, #5\n\
	bl setStageCheckpoint\n\
	movs r0, #6\n\
	b _0801DAD8\n\
	.align 2, 0\n\
_0801DA6C: .4byte 0x001D0FFF\n\
_0801DA70: .4byte gCollisionManager\n\
_0801DA74: .4byte gStageRun+16\n\
_0801DA78: .4byte gStageScriptList\n\
_0801DA7C:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r5, r6, r0\n\
	ldrb r0, [r5]\n\
	cmp r0, #6\n\
	bne _0801DA92\n\
	movs r0, #4\n\
	bl setStageCheckpoint\n\
	movs r0, #7\n\
	b _0801DAD8\n\
_0801DA92:\n\
	cmp r0, #7\n\
	bne _0801DADA\n\
	ldr r4, _0801DAE4 @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801DADA\n\
	ldr r1, _0801DAE8 @ =gCollisionManager\n\
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
	ldr r1, _0801DAEC @ =gStageScriptList\n\
	ldr r1, [r1, #0x20]\n\
	ldr r1, [r1, #0x20]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r1, _0801DAF0 @ =0x0000FFEF\n\
	ands r1, r0\n\
	ldrb r2, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r2\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #4\n\
	orrs r1, r0\n\
	strh r1, [r4, #8]\n\
	movs r0, #8\n\
_0801DAD8:\n\
	strb r0, [r5]\n\
_0801DADA:\n\
	movs r0, #0\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0801DAE4: .4byte gStageRun\n\
_0801DAE8: .4byte gCollisionManager\n\
_0801DAEC: .4byte gStageScriptList\n\
_0801DAF0: .4byte 0x0000FFEF\n\
 .syntax divided\n");
}

NAKED s16 AnatreForest_FreeUpdate(struct StageRun* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r3, r0, #0\n\
	ldr r4, [r3, #0x20]\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r5, r3, r1\n\
	ldrb r1, [r5]\n\
	cmp r1, #0\n\
	bne _0801DB68\n\
	ldr r2, _0801DB30 @ =gStageRun\n\
	ldrh r1, [r2, #8]\n\
	movs r6, #1\n\
	orrs r1, r6\n\
	strh r1, [r2, #8]\n\
	ldrb r4, [r2, #2]\n\
	cmp r4, #0\n\
	bne _0801DB38\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801DB34 @ =gStageScriptList\n\
	ldr r1, [r1, #0x20]\n\
	ldr r1, [r1, #0x24]\n\
	bl SetScript\n\
	movs r0, #1\n\
	bl setStageCheckpoint\n\
	strb r6, [r5]\n\
	b _0801DBE4\n\
	.align 2, 0\n\
_0801DB30: .4byte gStageRun\n\
_0801DB34: .4byte gStageScriptList\n\
_0801DB38:\n\
	cmp r4, #2\n\
	bne _0801DB4C\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801DB48 @ =gStageScriptList\n\
	ldr r1, [r1, #0x20]\n\
	ldr r1, [r1, #8]\n\
	b _0801DB5A\n\
	.align 2, 0\n\
_0801DB48: .4byte gStageScriptList\n\
_0801DB4C:\n\
	cmp r4, #3\n\
	bne _0801DBE4\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801DB64 @ =gStageScriptList\n\
	ldr r1, [r1, #0x20]\n\
	ldr r1, [r1, #0xc]\n\
_0801DB5A:\n\
	bl SetScript\n\
	strb r4, [r5]\n\
	b _0801DBE4\n\
	.align 2, 0\n\
_0801DB64: .4byte gStageScriptList\n\
_0801DB68:\n\
	cmp r1, #1\n\
	bne _0801DB76\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	movs r1, #2\n\
	b _0801DBE2\n\
_0801DB76:\n\
	cmp r1, #2\n\
	bne _0801DB90\n\
	ldr r2, [r4, #0x54]\n\
	ldr r1, _0801DB8C @ =0x000A4FFF\n\
	cmp r2, r1\n\
	ble _0801DB90\n\
	movs r0, #3\n\
	bl setStageCheckpoint\n\
	movs r1, #3\n\
	b _0801DBE2\n\
	.align 2, 0\n\
_0801DB8C: .4byte 0x000A4FFF\n\
_0801DB90:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r5, r3, r1\n\
	ldrb r1, [r5]\n\
	cmp r1, #3\n\
	bne _0801DBBC\n\
	ldr r2, [r4, #0x54]\n\
	ldr r1, _0801DBB4 @ =0x001C0FFF\n\
	cmp r2, r1\n\
	ble _0801DBE4\n\
	ldr r3, _0801DBB8 @ =gCollisionManager\n\
	ldrb r2, [r3, #1]\n\
	movs r1, #2\n\
	orrs r1, r2\n\
	strb r1, [r3, #1]\n\
	movs r1, #4\n\
	b _0801DBE2\n\
	.align 2, 0\n\
_0801DBB4: .4byte 0x001C0FFF\n\
_0801DBB8: .4byte gCollisionManager\n\
_0801DBBC:\n\
	cmp r1, #4\n\
	bne _0801DBE4\n\
	ldr r2, [r4, #0x54]\n\
	ldr r1, _0801DBEC @ =0x001D0FFF\n\
	cmp r2, r1\n\
	ble _0801DBE4\n\
	ldr r4, _0801DBF0 @ =gStageRun+16\n\
	ldr r0, _0801DBF4 @ =gStageScriptList\n\
	ldr r0, [r0, #0x20]\n\
	ldr r1, [r0, #0x28]\n\
	adds r0, r4, #0\n\
	bl SetScript\n\
	subs r4, #0x10\n\
	ldrh r2, [r4, #8]\n\
	ldr r1, _0801DBF8 @ =0x0000FFFE\n\
	ands r1, r2\n\
	strh r1, [r4, #8]\n\
	movs r1, #6\n\
_0801DBE2:\n\
	strb r1, [r5]\n\
_0801DBE4:\n\
	pop {r4, r5, r6}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0801DBEC: .4byte 0x001D0FFF\n\
_0801DBF0: .4byte gStageRun+16\n\
_0801DBF4: .4byte gStageScriptList\n\
_0801DBF8: .4byte 0x0000FFFE\n\
 .syntax divided\n");
}
