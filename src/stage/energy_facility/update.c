#include "global.h"
#include "overworld.h"

NAKED s16 EnergyFacility_MissionUpdate(struct StageRun* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r6, r0, #0\n\
	ldr r7, [r6, #0x20]\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r5, r6, r0\n\
	ldrb r0, [r5]\n\
	cmp r0, #0\n\
	beq _0801E330\n\
	b _0801E440\n\
_0801E330:\n\
	ldr r2, _0801E370 @ =gStageRun\n\
	ldrh r0, [r2, #8]\n\
	movs r7, #1\n\
	orrs r0, r7\n\
	strh r0, [r2, #8]\n\
	ldr r6, _0801E374 @ =gCurStory\n\
	ldrb r1, [r6, #4]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r6, #4]\n\
	ldrb r4, [r2, #2]\n\
	cmp r4, #0\n\
	bne _0801E37C\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801E378 @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	ldrb r1, [r2]\n\
	movs r0, #0xc0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	movs r0, #1\n\
	bl setStageCheckpoint\n\
	strb r7, [r5]\n\
	b _0801E8AC\n\
	.align 2, 0\n\
_0801E370: .4byte gStageRun\n\
_0801E374: .4byte gCurStory\n\
_0801E378: .4byte gStageScriptList\n\
_0801E37C:\n\
	cmp r4, #1\n\
	bne _0801E3A8\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801E3A4 @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1, #4]\n\
	bl SetScript\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	ldrb r1, [r2]\n\
	movs r0, #0xc0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	movs r0, #2\n\
	b _0801E8AA\n\
	.align 2, 0\n\
_0801E3A4: .4byte gStageScriptList\n\
_0801E3A8:\n\
	cmp r4, #2\n\
	bne _0801E3D0\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801E3CC @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1, #8]\n\
	bl SetScript\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	ldrb r1, [r2]\n\
	movs r0, #0xc0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	strb r4, [r5]\n\
	b _0801E8AC\n\
	.align 2, 0\n\
_0801E3CC: .4byte gStageScriptList\n\
_0801E3D0:\n\
	cmp r4, #3\n\
	bne _0801E3EC\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801E3E8 @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1, #0x14]\n\
	bl SetScript\n\
	movs r0, #6\n\
	b _0801E8AA\n\
	.align 2, 0\n\
_0801E3E8: .4byte gStageScriptList\n\
_0801E3EC:\n\
	cmp r4, #4\n\
	bne _0801E408\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801E404 @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1, #0x20]\n\
	bl SetScript\n\
	movs r0, #0xa\n\
	b _0801E8AA\n\
	.align 2, 0\n\
_0801E404: .4byte gStageScriptList\n\
_0801E408:\n\
	cmp r4, #5\n\
	bne _0801E424\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801E420 @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1, #0x2c]\n\
	bl SetScript\n\
	movs r0, #0x10\n\
	b _0801E8AA\n\
	.align 2, 0\n\
_0801E420: .4byte gStageScriptList\n\
_0801E424:\n\
	cmp r4, #6\n\
	beq _0801E42A\n\
	b _0801E8AC\n\
_0801E42A:\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801E43C @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1, #0x38]\n\
	bl SetScript\n\
	movs r0, #0x11\n\
	b _0801E8AA\n\
	.align 2, 0\n\
_0801E43C: .4byte gStageScriptList\n\
_0801E440:\n\
	cmp r0, #1\n\
	bne _0801E44E\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	movs r0, #2\n\
	b _0801E8AA\n\
_0801E44E:\n\
	cmp r0, #2\n\
	bne _0801E484\n\
	ldr r1, [r7, #0x54]\n\
	ldr r0, _0801E474 @ =0x000E13FF\n\
	cmp r1, r0\n\
	ble _0801E484\n\
	ldr r0, _0801E478 @ =gStageRun+16\n\
	ldr r1, _0801E47C @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1, #0xc]\n\
	bl SetScript\n\
	ldr r2, _0801E480 @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	movs r0, #3\n\
	b _0801E8AA\n\
	.align 2, 0\n\
_0801E474: .4byte 0x000E13FF\n\
_0801E478: .4byte gStageRun+16\n\
_0801E47C: .4byte gStageScriptList\n\
_0801E480: .4byte gCurStory\n\
_0801E484:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r5, r6, r1\n\
	ldrb r0, [r5]\n\
	cmp r0, #3\n\
	bne _0801E4F4\n\
	ldr r4, _0801E4E0 @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801E4F4\n\
	ldr r1, _0801E4E4 @ =gCollisionManager\n\
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
	ldr r1, _0801E4E8 @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1, #0x10]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r2, _0801E4EC @ =0x0000FFEF\n\
	ands r2, r0\n\
	ldrb r1, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0x12]\n\
	ldr r3, _0801E4F0 @ =gCurStory\n\
	ldrb r1, [r3, #4]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r3, #4]\n\
	movs r0, #1\n\
	orrs r2, r0\n\
	strh r2, [r4, #8]\n\
	movs r0, #4\n\
	b _0801E8AA\n\
	.align 2, 0\n\
_0801E4E0: .4byte gStageRun\n\
_0801E4E4: .4byte gCollisionManager\n\
_0801E4E8: .4byte gStageScriptList\n\
_0801E4EC: .4byte 0x0000FFEF\n\
_0801E4F0: .4byte gCurStory\n\
_0801E4F4:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r4, r6, r0\n\
	ldrb r0, [r4]\n\
	cmp r0, #4\n\
	bne _0801E518\n\
	ldr r1, _0801E514 @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x7f\n\
	ands r0, r2\n\
	movs r2, #0\n\
	strb r0, [r1]\n\
	strb r2, [r1, #1]\n\
	movs r0, #5\n\
	strb r0, [r4]\n\
	b _0801E8AC\n\
	.align 2, 0\n\
_0801E514: .4byte gCollisionManager\n\
_0801E518:\n\
	cmp r0, #5\n\
	bne _0801E548\n\
	ldr r0, _0801E53C @ =gStageRun+288\n\
	ldr r1, [r0]\n\
	ldr r0, _0801E540 @ =0x000F77FF\n\
	cmp r1, r0\n\
	ble _0801E548\n\
	ldr r2, _0801E544 @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	movs r0, #1\n\
	bl DeleteScriptEntity\n\
	movs r0, #6\n\
	strb r0, [r4]\n\
	b _0801E8AC\n\
	.align 2, 0\n\
_0801E53C: .4byte gStageRun+288\n\
_0801E540: .4byte 0x000F77FF\n\
_0801E544: .4byte gCurStory\n\
_0801E548:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r4, r6, r1\n\
	ldrb r0, [r4]\n\
	cmp r0, #6\n\
	bne _0801E590\n\
	ldr r1, [r7, #0x54]\n\
	ldr r0, _0801E580 @ =0x001593FF\n\
	cmp r1, r0\n\
	ble _0801E590\n\
	ldr r0, _0801E584 @ =gStageRun+16\n\
	ldr r1, _0801E588 @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1, #0x18]\n\
	bl SetScript\n\
	movs r0, #3\n\
	bl setStageCheckpoint\n\
	ldr r2, _0801E58C @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	movs r0, #7\n\
	strb r0, [r4]\n\
	b _0801E8AC\n\
	.align 2, 0\n\
_0801E580: .4byte 0x001593FF\n\
_0801E584: .4byte gStageRun+16\n\
_0801E588: .4byte gStageScriptList\n\
_0801E58C: .4byte gCurStory\n\
_0801E590:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r5, r6, r0\n\
	ldrb r0, [r5]\n\
	cmp r0, #7\n\
	bne _0801E600\n\
	ldr r4, _0801E5EC @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801E600\n\
	ldr r1, _0801E5F0 @ =gCollisionManager\n\
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
	ldr r1, _0801E5F4 @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1, #0x1c]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r2, _0801E5F8 @ =0x0000FFEF\n\
	ands r2, r0\n\
	ldrb r1, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0x12]\n\
	ldr r3, _0801E5FC @ =gCurStory\n\
	ldrb r1, [r3, #4]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r3, #4]\n\
	movs r0, #1\n\
	orrs r2, r0\n\
	strh r2, [r4, #8]\n\
	movs r0, #8\n\
	b _0801E8AA\n\
	.align 2, 0\n\
_0801E5EC: .4byte gStageRun\n\
_0801E5F0: .4byte gCollisionManager\n\
_0801E5F4: .4byte gStageScriptList\n\
_0801E5F8: .4byte 0x0000FFEF\n\
_0801E5FC: .4byte gCurStory\n\
_0801E600:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r4, r6, r1\n\
	ldrb r0, [r4]\n\
	cmp r0, #8\n\
	bne _0801E624\n\
	ldr r1, _0801E620 @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x7f\n\
	ands r0, r2\n\
	movs r2, #0\n\
	strb r0, [r1]\n\
	strb r2, [r1, #1]\n\
	movs r0, #9\n\
	strb r0, [r4]\n\
	b _0801E8AC\n\
	.align 2, 0\n\
_0801E620: .4byte gCollisionManager\n\
_0801E624:\n\
	cmp r0, #9\n\
	bne _0801E65C\n\
	ldr r0, _0801E650 @ =gStageRun+288\n\
	ldr r1, [r0]\n\
	ldr r0, _0801E654 @ =0x0016F7FF\n\
	cmp r1, r0\n\
	ble _0801E65C\n\
	movs r0, #4\n\
	bl setStageCheckpoint\n\
	ldr r2, _0801E658 @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	movs r0, #1\n\
	bl DeleteScriptEntity\n\
	movs r0, #0xa\n\
	strb r0, [r4]\n\
	b _0801E8AC\n\
	.align 2, 0\n\
_0801E650: .4byte gStageRun+288\n\
_0801E654: .4byte 0x0016F7FF\n\
_0801E658: .4byte gCurStory\n\
_0801E65C:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r4, r6, r0\n\
	ldrb r0, [r4]\n\
	cmp r0, #0xa\n\
	bne _0801E69C\n\
	ldr r1, [r7, #0x54]\n\
	ldr r0, _0801E68C @ =0x0020D3FF\n\
	cmp r1, r0\n\
	ble _0801E69C\n\
	ldr r0, _0801E690 @ =gStageRun+16\n\
	ldr r1, _0801E694 @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1, #0x24]\n\
	bl SetScript\n\
	ldr r2, _0801E698 @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	movs r0, #0xb\n\
	strb r0, [r4]\n\
	b _0801E8AC\n\
	.align 2, 0\n\
_0801E68C: .4byte 0x0020D3FF\n\
_0801E690: .4byte gStageRun+16\n\
_0801E694: .4byte gStageScriptList\n\
_0801E698: .4byte gCurStory\n\
_0801E69C:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r5, r6, r1\n\
	ldrb r0, [r5]\n\
	cmp r0, #0xb\n\
	bne _0801E70C\n\
	ldr r4, _0801E6F8 @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801E70C\n\
	ldr r1, _0801E6FC @ =gCollisionManager\n\
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
	ldr r1, _0801E700 @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1, #0x28]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r2, _0801E704 @ =0x0000FFEF\n\
	ands r2, r0\n\
	ldrb r1, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0x12]\n\
	ldr r3, _0801E708 @ =gCurStory\n\
	ldrb r1, [r3, #4]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r3, #4]\n\
	movs r0, #1\n\
	orrs r2, r0\n\
	strh r2, [r4, #8]\n\
	movs r0, #0xc\n\
	b _0801E8AA\n\
	.align 2, 0\n\
_0801E6F8: .4byte gStageRun\n\
_0801E6FC: .4byte gCollisionManager\n\
_0801E700: .4byte gStageScriptList\n\
_0801E704: .4byte 0x0000FFEF\n\
_0801E708: .4byte gCurStory\n\
_0801E70C:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r4, r6, r0\n\
	ldrb r0, [r4]\n\
	cmp r0, #0xc\n\
	bne _0801E730\n\
	ldr r1, _0801E72C @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x7f\n\
	ands r0, r2\n\
	movs r2, #0\n\
	strb r0, [r1]\n\
	strb r2, [r1, #1]\n\
	movs r0, #0xd\n\
	strb r0, [r4]\n\
	b _0801E8AC\n\
	.align 2, 0\n\
_0801E72C: .4byte gCollisionManager\n\
_0801E730:\n\
	cmp r0, #0xd\n\
	bne _0801E760\n\
	ldr r0, _0801E754 @ =gStageRun+288\n\
	ldr r1, [r0]\n\
	ldr r0, _0801E758 @ =0x002237FF\n\
	cmp r1, r0\n\
	ble _0801E760\n\
	ldr r2, _0801E75C @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	movs r0, #1\n\
	bl DeleteScriptEntity\n\
	movs r0, #0xe\n\
	strb r0, [r4]\n\
	b _0801E8AC\n\
	.align 2, 0\n\
_0801E754: .4byte gStageRun+288\n\
_0801E758: .4byte 0x002237FF\n\
_0801E75C: .4byte gCurStory\n\
_0801E760:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r4, r6, r1\n\
	ldrb r0, [r4]\n\
	cmp r0, #0xe\n\
	bne _0801E7EC\n\
	ldr r1, [r7, #0x54]\n\
	ldr r0, _0801E7DC @ =0x002B0FFF\n\
	cmp r1, r0\n\
	ble _0801E790\n\
	ldr r0, _0801E7E0 @ =gStageRun\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #1\n\
	adds r5, r0, r1\n\
	ldr r0, [r5]\n\
	movs r4, #1\n\
	rsbs r4, r4, #0\n\
	cmp r0, r4\n\
	beq _0801E790\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r4, [r5]\n\
_0801E790:\n\
	ldr r1, [r7, #0x54]\n\
	ldr r0, _0801E7E4 @ =0x002B2FFF\n\
	cmp r1, r0\n\
	bgt _0801E79A\n\
	b _0801E8AC\n\
_0801E79A:\n\
	ldr r2, _0801E7E8 @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	ldr r0, _0801E7E0 @ =gStageRun\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #1\n\
	adds r4, r0, r1\n\
	ldr r0, [r4]\n\
	cmp r0, #0xa1\n\
	beq _0801E7CE\n\
	movs r5, #1\n\
	rsbs r5, r5, #0\n\
	cmp r0, r5\n\
	beq _0801E7C4\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r5, [r4]\n\
_0801E7C4:\n\
	movs r0, #0xa1\n\
	bl playBGM\n\
	movs r0, #0xa1\n\
	str r0, [r4]\n\
_0801E7CE:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r6, r0\n\
	movs r0, #0xf\n\
	strb r0, [r1]\n\
	b _0801E8AC\n\
	.align 2, 0\n\
_0801E7DC: .4byte 0x002B0FFF\n\
_0801E7E0: .4byte gStageRun\n\
_0801E7E4: .4byte 0x002B2FFF\n\
_0801E7E8: .4byte gCollisionManager\n\
_0801E7EC:\n\
	cmp r0, #0xf\n\
	bne _0801E818\n\
	ldr r1, [r7, #0x54]\n\
	ldr r0, _0801E808 @ =0x002C0FFF\n\
	cmp r1, r0\n\
	ble _0801E818\n\
	ldr r1, _0801E80C @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r0, _0801E810 @ =gStageRun+16\n\
	ldr r1, _0801E814 @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1, #0x30]\n\
	b _0801E834\n\
	.align 2, 0\n\
_0801E808: .4byte 0x002C0FFF\n\
_0801E80C: .4byte gCollisionManager\n\
_0801E810: .4byte gStageRun+16\n\
_0801E814: .4byte gStageScriptList\n\
_0801E818:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r4, r6, r1\n\
	ldrb r0, [r4]\n\
	cmp r0, #0x10\n\
	bne _0801E850\n\
	ldr r1, [r7, #0x54]\n\
	ldr r0, _0801E844 @ =0x002C0FFF\n\
	cmp r1, r0\n\
	ble _0801E850\n\
	ldr r0, _0801E848 @ =gStageRun+16\n\
	ldr r1, _0801E84C @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1, #0x34]\n\
_0801E834:\n\
	bl SetScript\n\
	movs r0, #6\n\
	bl setStageCheckpoint\n\
	movs r0, #0x11\n\
	strb r0, [r4]\n\
	b _0801E8AC\n\
	.align 2, 0\n\
_0801E844: .4byte 0x002C0FFF\n\
_0801E848: .4byte gStageRun+16\n\
_0801E84C: .4byte gStageScriptList\n\
_0801E850:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r5, r6, r0\n\
	ldrb r0, [r5]\n\
	cmp r0, #0x11\n\
	bne _0801E866\n\
	movs r0, #5\n\
	bl setStageCheckpoint\n\
	movs r0, #0x12\n\
	b _0801E8AA\n\
_0801E866:\n\
	cmp r0, #0x12\n\
	bne _0801E8AC\n\
	ldr r4, _0801E8B4 @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801E8AC\n\
	ldr r1, _0801E8B8 @ =gCollisionManager\n\
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
	ldr r1, _0801E8BC @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1, #0x3c]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r1, _0801E8C0 @ =0x0000FFEF\n\
	ands r1, r0\n\
	ldrb r2, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r2\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #4\n\
	orrs r1, r0\n\
	strh r1, [r4, #8]\n\
_0801E8AA:\n\
	strb r0, [r5]\n\
_0801E8AC:\n\
	movs r0, #0\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0801E8B4: .4byte gStageRun\n\
_0801E8B8: .4byte gCollisionManager\n\
_0801E8BC: .4byte gStageScriptList\n\
_0801E8C0: .4byte 0x0000FFEF\n\
 .syntax divided\n");
}

NAKED s16 EnergyFacility_FreeUpdate(struct StageRun* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r2, r0, #0\n\
	ldr r3, [r2, #0x20]\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r5, r2, r0\n\
	ldrb r0, [r5]\n\
	cmp r0, #0\n\
	bne _0801E980\n\
	ldr r2, _0801E914 @ =gStageRun\n\
	ldrh r0, [r2, #8]\n\
	movs r7, #1\n\
	orrs r0, r7\n\
	strh r0, [r2, #8]\n\
	ldr r6, _0801E918 @ =gCurStory\n\
	ldrb r1, [r6, #4]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r6, #4]\n\
	ldrb r4, [r2, #2]\n\
	cmp r4, #0\n\
	bne _0801E920\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801E91C @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1, #0x40]\n\
	bl SetScript\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	ldrb r1, [r2]\n\
	movs r0, #0xc0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	movs r0, #1\n\
	bl setStageCheckpoint\n\
	strb r7, [r5]\n\
	b _0801ECF4\n\
	.align 2, 0\n\
_0801E914: .4byte gStageRun\n\
_0801E918: .4byte gCurStory\n\
_0801E91C: .4byte gStageScriptList\n\
_0801E920:\n\
	cmp r4, #2\n\
	bne _0801E948\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801E944 @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1, #8]\n\
	bl SetScript\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	ldrb r1, [r2]\n\
	movs r0, #0xc0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	strb r4, [r5]\n\
	b _0801ECF4\n\
	.align 2, 0\n\
_0801E944: .4byte gStageScriptList\n\
_0801E948:\n\
	cmp r4, #3\n\
	bne _0801E964\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801E960 @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1, #0x14]\n\
	bl SetScript\n\
	movs r0, #6\n\
	b _0801ECF2\n\
	.align 2, 0\n\
_0801E960: .4byte gStageScriptList\n\
_0801E964:\n\
	cmp r4, #4\n\
	beq _0801E96A\n\
	b _0801ECF4\n\
_0801E96A:\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801E97C @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1, #0x20]\n\
	bl SetScript\n\
	movs r0, #0xa\n\
	b _0801ECF2\n\
	.align 2, 0\n\
_0801E97C: .4byte gStageScriptList\n\
_0801E980:\n\
	cmp r0, #1\n\
	bne _0801E98E\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	movs r0, #2\n\
	b _0801ECF2\n\
_0801E98E:\n\
	cmp r0, #2\n\
	bne _0801E9C4\n\
	ldr r1, [r3, #0x54]\n\
	ldr r0, _0801E9B4 @ =0x000E13FF\n\
	cmp r1, r0\n\
	ble _0801E9C4\n\
	ldr r0, _0801E9B8 @ =gStageRun+16\n\
	ldr r1, _0801E9BC @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1, #0xc]\n\
	bl SetScript\n\
	ldr r2, _0801E9C0 @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	movs r0, #3\n\
	b _0801ECF2\n\
	.align 2, 0\n\
_0801E9B4: .4byte 0x000E13FF\n\
_0801E9B8: .4byte gStageRun+16\n\
_0801E9BC: .4byte gStageScriptList\n\
_0801E9C0: .4byte gCurStory\n\
_0801E9C4:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r5, r2, r0\n\
	ldrb r0, [r5]\n\
	cmp r0, #3\n\
	bne _0801EA34\n\
	ldr r4, _0801EA20 @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801EA34\n\
	ldr r1, _0801EA24 @ =gCollisionManager\n\
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
	ldr r1, _0801EA28 @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1, #0x10]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r2, _0801EA2C @ =0x0000FFEF\n\
	ands r2, r0\n\
	ldrb r1, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0x12]\n\
	ldr r3, _0801EA30 @ =gCurStory\n\
	ldrb r1, [r3, #4]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r3, #4]\n\
	movs r0, #1\n\
	orrs r2, r0\n\
	strh r2, [r4, #8]\n\
	movs r0, #4\n\
	b _0801ECF2\n\
	.align 2, 0\n\
_0801EA20: .4byte gStageRun\n\
_0801EA24: .4byte gCollisionManager\n\
_0801EA28: .4byte gStageScriptList\n\
_0801EA2C: .4byte 0x0000FFEF\n\
_0801EA30: .4byte gCurStory\n\
_0801EA34:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r4, r2, r0\n\
	ldrb r0, [r4]\n\
	cmp r0, #4\n\
	bne _0801EA58\n\
	ldr r1, _0801EA54 @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x7f\n\
	ands r0, r2\n\
	movs r2, #0\n\
	strb r0, [r1]\n\
	strb r2, [r1, #1]\n\
	movs r0, #5\n\
	strb r0, [r4]\n\
	b _0801ECF4\n\
	.align 2, 0\n\
_0801EA54: .4byte gCollisionManager\n\
_0801EA58:\n\
	cmp r0, #5\n\
	bne _0801EA88\n\
	ldr r0, _0801EA7C @ =gStageRun+288\n\
	ldr r1, [r0]\n\
	ldr r0, _0801EA80 @ =0x000F77FF\n\
	cmp r1, r0\n\
	ble _0801EA88\n\
	ldr r2, _0801EA84 @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	movs r0, #1\n\
	bl DeleteScriptEntity\n\
	movs r0, #6\n\
	strb r0, [r4]\n\
	b _0801ECF4\n\
	.align 2, 0\n\
_0801EA7C: .4byte gStageRun+288\n\
_0801EA80: .4byte 0x000F77FF\n\
_0801EA84: .4byte gCurStory\n\
_0801EA88:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r4, r2, r0\n\
	ldrb r0, [r4]\n\
	cmp r0, #6\n\
	bne _0801EAD0\n\
	ldr r1, [r3, #0x54]\n\
	ldr r0, _0801EAC0 @ =0x001593FF\n\
	cmp r1, r0\n\
	ble _0801EAD0\n\
	ldr r0, _0801EAC4 @ =gStageRun+16\n\
	ldr r1, _0801EAC8 @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1, #0x18]\n\
	bl SetScript\n\
	movs r0, #3\n\
	bl setStageCheckpoint\n\
	ldr r2, _0801EACC @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	movs r0, #7\n\
	strb r0, [r4]\n\
	b _0801ECF4\n\
	.align 2, 0\n\
_0801EAC0: .4byte 0x001593FF\n\
_0801EAC4: .4byte gStageRun+16\n\
_0801EAC8: .4byte gStageScriptList\n\
_0801EACC: .4byte gCurStory\n\
_0801EAD0:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r5, r2, r0\n\
	ldrb r0, [r5]\n\
	cmp r0, #7\n\
	bne _0801EB40\n\
	ldr r4, _0801EB2C @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801EB40\n\
	ldr r1, _0801EB30 @ =gCollisionManager\n\
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
	ldr r1, _0801EB34 @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1, #0x1c]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r2, _0801EB38 @ =0x0000FFEF\n\
	ands r2, r0\n\
	ldrb r1, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0x12]\n\
	ldr r3, _0801EB3C @ =gCurStory\n\
	ldrb r1, [r3, #4]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r3, #4]\n\
	movs r0, #1\n\
	orrs r2, r0\n\
	strh r2, [r4, #8]\n\
	movs r0, #8\n\
	b _0801ECF2\n\
	.align 2, 0\n\
_0801EB2C: .4byte gStageRun\n\
_0801EB30: .4byte gCollisionManager\n\
_0801EB34: .4byte gStageScriptList\n\
_0801EB38: .4byte 0x0000FFEF\n\
_0801EB3C: .4byte gCurStory\n\
_0801EB40:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r4, r2, r0\n\
	ldrb r0, [r4]\n\
	cmp r0, #8\n\
	bne _0801EB64\n\
	ldr r1, _0801EB60 @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x7f\n\
	ands r0, r2\n\
	movs r2, #0\n\
	strb r0, [r1]\n\
	strb r2, [r1, #1]\n\
	movs r0, #9\n\
	strb r0, [r4]\n\
	b _0801ECF4\n\
	.align 2, 0\n\
_0801EB60: .4byte gCollisionManager\n\
_0801EB64:\n\
	cmp r0, #9\n\
	bne _0801EB9C\n\
	ldr r0, _0801EB90 @ =gStageRun+288\n\
	ldr r1, [r0]\n\
	ldr r0, _0801EB94 @ =0x0016F7FF\n\
	cmp r1, r0\n\
	ble _0801EB9C\n\
	movs r0, #4\n\
	bl setStageCheckpoint\n\
	ldr r2, _0801EB98 @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	movs r0, #1\n\
	bl DeleteScriptEntity\n\
	movs r0, #0xa\n\
	strb r0, [r4]\n\
	b _0801ECF4\n\
	.align 2, 0\n\
_0801EB90: .4byte gStageRun+288\n\
_0801EB94: .4byte 0x0016F7FF\n\
_0801EB98: .4byte gCurStory\n\
_0801EB9C:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r4, r2, r0\n\
	ldrb r0, [r4]\n\
	cmp r0, #0xa\n\
	bne _0801EBDC\n\
	ldr r1, [r3, #0x54]\n\
	ldr r0, _0801EBCC @ =0x0020D3FF\n\
	cmp r1, r0\n\
	ble _0801EBDC\n\
	ldr r0, _0801EBD0 @ =gStageRun+16\n\
	ldr r1, _0801EBD4 @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1, #0x24]\n\
	bl SetScript\n\
	ldr r2, _0801EBD8 @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	movs r0, #0xb\n\
	strb r0, [r4]\n\
	b _0801ECF4\n\
	.align 2, 0\n\
_0801EBCC: .4byte 0x0020D3FF\n\
_0801EBD0: .4byte gStageRun+16\n\
_0801EBD4: .4byte gStageScriptList\n\
_0801EBD8: .4byte gCurStory\n\
_0801EBDC:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r5, r2, r0\n\
	ldrb r0, [r5]\n\
	cmp r0, #0xb\n\
	bne _0801EC4C\n\
	ldr r4, _0801EC38 @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801EC4C\n\
	ldr r1, _0801EC3C @ =gCollisionManager\n\
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
	ldr r1, _0801EC40 @ =gStageScriptList\n\
	ldr r1, [r1, #0x2c]\n\
	ldr r1, [r1, #0x28]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r2, _0801EC44 @ =0x0000FFEF\n\
	ands r2, r0\n\
	ldrb r1, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0x12]\n\
	ldr r3, _0801EC48 @ =gCurStory\n\
	ldrb r1, [r3, #4]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r3, #4]\n\
	movs r0, #1\n\
	orrs r2, r0\n\
	strh r2, [r4, #8]\n\
	movs r0, #0xc\n\
	b _0801ECF2\n\
	.align 2, 0\n\
_0801EC38: .4byte gStageRun\n\
_0801EC3C: .4byte gCollisionManager\n\
_0801EC40: .4byte gStageScriptList\n\
_0801EC44: .4byte 0x0000FFEF\n\
_0801EC48: .4byte gCurStory\n\
_0801EC4C:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r4, r2, r0\n\
	ldrb r0, [r4]\n\
	cmp r0, #0xc\n\
	bne _0801EC70\n\
	ldr r1, _0801EC6C @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x7f\n\
	ands r0, r2\n\
	movs r2, #0\n\
	strb r0, [r1]\n\
	strb r2, [r1, #1]\n\
	movs r0, #0xd\n\
	strb r0, [r4]\n\
	b _0801ECF4\n\
	.align 2, 0\n\
_0801EC6C: .4byte gCollisionManager\n\
_0801EC70:\n\
	cmp r0, #0xd\n\
	bne _0801ECA0\n\
	ldr r0, _0801EC94 @ =gStageRun+288\n\
	ldr r1, [r0]\n\
	ldr r0, _0801EC98 @ =0x002237FF\n\
	cmp r1, r0\n\
	ble _0801ECA0\n\
	ldr r2, _0801EC9C @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	movs r0, #1\n\
	bl DeleteScriptEntity\n\
	movs r0, #0xe\n\
	strb r0, [r4]\n\
	b _0801ECF4\n\
	.align 2, 0\n\
_0801EC94: .4byte gStageRun+288\n\
_0801EC98: .4byte 0x002237FF\n\
_0801EC9C: .4byte gCurStory\n\
_0801ECA0:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r5, r2, r0\n\
	ldrb r0, [r5]\n\
	cmp r0, #0xe\n\
	bne _0801ECCC\n\
	ldr r1, [r3, #0x54]\n\
	ldr r0, _0801ECC4 @ =0x002B0FFF\n\
	cmp r1, r0\n\
	ble _0801ECF4\n\
	ldr r2, _0801ECC8 @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	movs r0, #0xf\n\
	b _0801ECF2\n\
	.align 2, 0\n\
_0801ECC4: .4byte 0x002B0FFF\n\
_0801ECC8: .4byte gCollisionManager\n\
_0801ECCC:\n\
	cmp r0, #0xf\n\
	bne _0801ECF4\n\
	ldr r1, [r3, #0x54]\n\
	ldr r0, _0801ECFC @ =0x002C0FFF\n\
	cmp r1, r0\n\
	ble _0801ECF4\n\
	ldr r4, _0801ED00 @ =gStageRun+16\n\
	ldr r0, _0801ED04 @ =gStageScriptList\n\
	ldr r0, [r0, #0x2c]\n\
	ldr r1, [r0, #0x44]\n\
	adds r0, r4, #0\n\
	bl SetScript\n\
	subs r4, #0x10\n\
	ldrh r1, [r4, #8]\n\
	ldr r0, _0801ED08 @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r4, #8]\n\
	movs r0, #0x11\n\
_0801ECF2:\n\
	strb r0, [r5]\n\
_0801ECF4:\n\
	movs r0, #0\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0801ECFC: .4byte 0x002C0FFF\n\
_0801ED00: .4byte gStageRun+16\n\
_0801ED04: .4byte gStageScriptList\n\
_0801ED08: .4byte 0x0000FFFE\n\
 .syntax divided\n");
}
