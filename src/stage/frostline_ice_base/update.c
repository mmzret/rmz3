#include "global.h"
#include "overworld.h"

NAKED s16 IceBase_MissionUpdate(struct StageRun* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r7, r0, #0\n\
	ldr r6, [r7, #0x20]\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r5, r7, r0\n\
	ldrb r0, [r5]\n\
	cmp r0, #0\n\
	bne _0801DCF4\n\
	ldr r2, _0801DC3C @ =gStageRun\n\
	ldrh r1, [r2, #8]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	strh r0, [r2, #8]\n\
	ldrb r4, [r2, #2]\n\
	cmp r4, #0\n\
	bne _0801DC6C\n\
	ldr r0, _0801DC40 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0801DC48\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801DC44 @ =gStageScriptList\n\
	ldr r1, [r1, #0x24]\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
	b _0801DC56\n\
	.align 2, 0\n\
_0801DC3C: .4byte gStageRun\n\
_0801DC40: .4byte gCurStory\n\
_0801DC44: .4byte gStageScriptList\n\
_0801DC48:\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801DC68 @ =gStageScriptList\n\
	ldr r1, [r1, #0x24]\n\
	ldr r1, [r1, #0x24]\n\
	bl SetScript\n\
_0801DC56:\n\
	movs r0, #1\n\
	bl setStageCheckpoint\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r7, r0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	b _0801DF22\n\
	.align 2, 0\n\
_0801DC68: .4byte gStageScriptList\n\
_0801DC6C:\n\
	cmp r4, #1\n\
	bne _0801DC8C\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801DC88 @ =gStageScriptList\n\
	ldr r1, [r1, #0x24]\n\
	ldr r1, [r1, #4]\n\
	bl SetScript\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	movs r0, #2\n\
	b _0801DF20\n\
	.align 2, 0\n\
_0801DC88: .4byte gStageScriptList\n\
_0801DC8C:\n\
	cmp r4, #2\n\
	bne _0801DCA0\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801DC9C @ =gStageScriptList\n\
	ldr r1, [r1, #0x24]\n\
	ldr r1, [r1, #8]\n\
	b _0801DCAE\n\
	.align 2, 0\n\
_0801DC9C: .4byte gStageScriptList\n\
_0801DCA0:\n\
	cmp r4, #3\n\
	bne _0801DCBC\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801DCB8 @ =gStageScriptList\n\
	ldr r1, [r1, #0x24]\n\
	ldr r1, [r1, #0xc]\n\
_0801DCAE:\n\
	bl SetScript\n\
	strb r4, [r5]\n\
	b _0801DF22\n\
	.align 2, 0\n\
_0801DCB8: .4byte gStageScriptList\n\
_0801DCBC:\n\
	cmp r4, #4\n\
	bne _0801DCD8\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801DCD4 @ =gStageScriptList\n\
	ldr r1, [r1, #0x24]\n\
	ldr r1, [r1, #0x10]\n\
	bl SetScript\n\
	movs r0, #5\n\
	b _0801DF20\n\
	.align 2, 0\n\
_0801DCD4: .4byte gStageScriptList\n\
_0801DCD8:\n\
	cmp r4, #5\n\
	beq _0801DCDE\n\
	b _0801DF22\n\
_0801DCDE:\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801DCF0 @ =gStageScriptList\n\
	ldr r1, [r1, #0x24]\n\
	ldr r1, [r1, #0x1c]\n\
	bl SetScript\n\
	movs r0, #6\n\
	b _0801DF20\n\
	.align 2, 0\n\
_0801DCF0: .4byte gStageScriptList\n\
_0801DCF4:\n\
	cmp r0, #1\n\
	bne _0801DD02\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	movs r0, #2\n\
	b _0801DF20\n\
_0801DD02:\n\
	cmp r0, #2\n\
	bne _0801DD1C\n\
	ldr r1, [r6, #0x54]\n\
	ldr r0, _0801DD18 @ =0x00176FFF\n\
	cmp r1, r0\n\
	ble _0801DD1C\n\
	movs r0, #3\n\
	bl setStageCheckpoint\n\
	movs r0, #3\n\
	b _0801DF20\n\
	.align 2, 0\n\
_0801DD18: .4byte 0x00176FFF\n\
_0801DD1C:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r4, r7, r1\n\
	ldrb r0, [r4]\n\
	cmp r0, #3\n\
	bne _0801DE00\n\
	ldr r1, [r6, #0x58]\n\
	ldr r0, _0801DD64 @ =0x0001DFFF\n\
	cmp r1, r0\n\
	bgt _0801DE00\n\
	ldr r1, [r6, #0x54]\n\
	ldr r0, _0801DD68 @ =0x001FCFFF\n\
	cmp r1, r0\n\
	ble _0801DD94\n\
	ldr r0, _0801DD6C @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0801DD74\n\
	ldr r0, _0801DD70 @ =gStageRun\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #1\n\
	adds r5, r0, r1\n\
	ldr r0, [r5]\n\
	movs r4, #1\n\
	rsbs r4, r4, #0\n\
	cmp r0, r4\n\
	beq _0801DD94\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r4, [r5]\n\
	b _0801DD94\n\
	.align 2, 0\n\
_0801DD64: .4byte 0x0001DFFF\n\
_0801DD68: .4byte 0x001FCFFF\n\
_0801DD6C: .4byte gCurStory\n\
_0801DD70: .4byte gStageRun\n\
_0801DD74:\n\
	ldr r0, _0801DDF0 @ =gStageEntityManager\n\
	movs r1, #0x87\n\
	lsls r1, r1, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #9\n\
	bl FUN_080186c8\n\
	ldr r2, _0801DDF4 @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	movs r0, #4\n\
	strb r0, [r4]\n\
_0801DD94:\n\
	ldr r1, [r6, #0x54]\n\
	ldr r0, _0801DDF8 @ =0x001FEFFF\n\
	cmp r1, r0\n\
	bgt _0801DD9E\n\
	b _0801DF22\n\
_0801DD9E:\n\
	ldr r0, _0801DDF0 @ =gStageEntityManager\n\
	movs r1, #0x87\n\
	lsls r1, r1, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #9\n\
	bl FUN_080186c8\n\
	ldr r2, _0801DDF4 @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	ldr r0, _0801DDFC @ =gStageRun\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #1\n\
	adds r4, r0, r1\n\
	ldr r0, [r4]\n\
	cmp r0, #0xa1\n\
	beq _0801DDE4\n\
	movs r5, #1\n\
	rsbs r5, r5, #0\n\
	cmp r0, r5\n\
	beq _0801DDDA\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r5, [r4]\n\
_0801DDDA:\n\
	movs r0, #0xa1\n\
	bl playBGM\n\
	movs r0, #0xa1\n\
	str r0, [r4]\n\
_0801DDE4:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r7, r0\n\
	movs r0, #4\n\
	strb r0, [r1]\n\
	b _0801DF22\n\
	.align 2, 0\n\
_0801DDF0: .4byte gStageEntityManager\n\
_0801DDF4: .4byte gCollisionManager\n\
_0801DDF8: .4byte 0x001FEFFF\n\
_0801DDFC: .4byte gStageRun\n\
_0801DE00:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r0, r7, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #4\n\
	bne _0801DE80\n\
	ldr r1, [r6, #0x54]\n\
	ldr r0, _0801DE34 @ =0x0020CFFF\n\
	cmp r1, r0\n\
	ble _0801DE80\n\
	ldr r1, _0801DE38 @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r0, _0801DE3C @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0801DE48\n\
	ldr r0, _0801DE40 @ =gStageRun+16\n\
	ldr r1, _0801DE44 @ =gStageScriptList\n\
	ldr r1, [r1, #0x24]\n\
	ldr r1, [r1, #0x14]\n\
	bl SetScript\n\
	b _0801DE60\n\
	.align 2, 0\n\
_0801DE34: .4byte 0x0020CFFF\n\
_0801DE38: .4byte gCollisionManager\n\
_0801DE3C: .4byte gCurStory\n\
_0801DE40: .4byte gStageRun+16\n\
_0801DE44: .4byte gStageScriptList\n\
_0801DE48:\n\
	ldr r4, _0801DE74 @ =gStageRun+16\n\
	ldr r0, _0801DE78 @ =gStageScriptList\n\
	ldr r0, [r0, #0x24]\n\
	ldr r1, [r0, #0x28]\n\
	adds r0, r4, #0\n\
	bl SetScript\n\
	subs r4, #0x10\n\
	ldrh r1, [r4, #8]\n\
	ldr r0, _0801DE7C @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r4, #8]\n\
_0801DE60:\n\
	movs r0, #5\n\
	bl setStageCheckpoint\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r7, r0\n\
	movs r0, #6\n\
	strb r0, [r1]\n\
	b _0801DF22\n\
	.align 2, 0\n\
_0801DE74: .4byte gStageRun+16\n\
_0801DE78: .4byte gStageScriptList\n\
_0801DE7C: .4byte 0x0000FFFE\n\
_0801DE80:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r4, r7, r1\n\
	ldrb r0, [r4]\n\
	cmp r0, #5\n\
	bne _0801DEC4\n\
	ldr r1, [r6, #0x54]\n\
	ldr r0, _0801DEB4 @ =0x0020CFFF\n\
	cmp r1, r0\n\
	ble _0801DEC4\n\
	ldr r1, _0801DEB8 @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r0, _0801DEBC @ =gStageRun+16\n\
	ldr r1, _0801DEC0 @ =gStageScriptList\n\
	ldr r1, [r1, #0x24]\n\
	ldr r1, [r1, #0x18]\n\
	bl SetScript\n\
	movs r0, #5\n\
	bl setStageCheckpoint\n\
	movs r0, #6\n\
	strb r0, [r4]\n\
	b _0801DF22\n\
	.align 2, 0\n\
_0801DEB4: .4byte 0x0020CFFF\n\
_0801DEB8: .4byte gCollisionManager\n\
_0801DEBC: .4byte gStageRun+16\n\
_0801DEC0: .4byte gStageScriptList\n\
_0801DEC4:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r5, r7, r0\n\
	ldrb r0, [r5]\n\
	cmp r0, #6\n\
	bne _0801DEDA\n\
	movs r0, #4\n\
	bl setStageCheckpoint\n\
	movs r0, #7\n\
	b _0801DF20\n\
_0801DEDA:\n\
	cmp r0, #7\n\
	bne _0801DF22\n\
	ldr r4, _0801DF2C @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801DF22\n\
	ldr r1, _0801DF30 @ =gCollisionManager\n\
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
	ldr r1, _0801DF34 @ =gStageScriptList\n\
	ldr r1, [r1, #0x24]\n\
	ldr r1, [r1, #0x20]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r1, _0801DF38 @ =0x0000FFEF\n\
	ands r1, r0\n\
	ldrb r2, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r2\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #4\n\
	orrs r1, r0\n\
	strh r1, [r4, #8]\n\
	movs r0, #8\n\
_0801DF20:\n\
	strb r0, [r5]\n\
_0801DF22:\n\
	movs r0, #0\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0801DF2C: .4byte gStageRun\n\
_0801DF30: .4byte gCollisionManager\n\
_0801DF34: .4byte gStageScriptList\n\
_0801DF38: .4byte 0x0000FFEF\n\
 .syntax divided\n");
}

s16 IceBase_FreeUpdate(struct StageRun* p) { return IceBase_MissionUpdate(p); }
