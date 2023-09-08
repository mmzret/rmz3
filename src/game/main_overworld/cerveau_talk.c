#include "game.h"
#include "global.h"

NAKED void OverworldLoop_CerveauTalk(struct GameState* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #3]\n\
	cmp r0, #6\n\
	bhi _080F1DE0\n\
	lsls r0, r0, #2\n\
	ldr r1, _080F1DC0 @ =_080F1DC4\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080F1DC0: .4byte _080F1DC4\n\
_080F1DC4: @ jump table\n\
	.4byte _080F1E3C @ case 0\n\
	.4byte _080F1E4C @ case 1\n\
	.4byte _080F1F4A @ case 2\n\
	.4byte _080F1F64 @ case 3\n\
	.4byte _080F1F8E @ case 4\n\
	.4byte _080F1FB0 @ case 5\n\
	.4byte _080F1FC8 @ case 6\n\
_080F1DE0:\n\
	ldr r2, _080F1E24 @ =gTextWindow+8\n\
	ldrh r1, [r2, #2]\n\
	cmp r1, #0\n\
	beq _080F1DEE\n\
	cmp r1, #4\n\
	beq _080F1DEE\n\
	b _080F1FDA\n\
_080F1DEE:\n\
	movs r3, #0x16\n\
	ldrsh r0, [r2, r3]\n\
	cmp r0, #9\n\
	bne _080F1E38\n\
	cmp r1, #0\n\
	beq _080F1DFC\n\
	b _080F1F6C\n\
_080F1DFC:\n\
	ldr r2, _080F1E28 @ =gTextPrinter\n\
	ldr r0, _080F1E2C @ =0x00000594\n\
	adds r2, r2, r0\n\
	ldr r0, _080F1E30 @ =StringOfsTable\n\
	movs r1, #0xdf\n\
	lsls r1, r1, #3\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	ldr r1, _080F1E34 @ =gStringData\n\
	adds r0, r0, r1\n\
	str r0, [r2]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	movs r1, #0x5a\n\
	bl PrintTextWindow\n\
	movs r0, #0x5b\n\
	bl getDiskInStageRun\n\
	b _080F1FDA\n\
	.align 2, 0\n\
_080F1E24: .4byte gTextWindow+8\n\
_080F1E28: .4byte gTextPrinter\n\
_080F1E2C: .4byte 0x00000594\n\
_080F1E30: .4byte StringOfsTable\n\
_080F1E34: .4byte gStringData\n\
_080F1E38:\n\
	movs r0, #0\n\
	strb r0, [r4, #3]\n\
_080F1E3C:\n\
	movs r0, #0x66\n\
	bl PrintOptionMessage1\n\
	movs r0, #0\n\
	strh r0, [r4, #0xa]\n\
	ldrb r0, [r4, #3]\n\
	adds r0, #1\n\
	strb r0, [r4, #3]\n\
_080F1E4C:\n\
	ldr r0, _080F1E78 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F1E5A\n\
	cmp r0, #4\n\
	beq _080F1E5A\n\
	b _080F1FDA\n\
_080F1E5A:\n\
	adds r0, r4, #0\n\
	bl handleWrapTwoChoice\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080F1E6A\n\
	b _080F1FDA\n\
_080F1E6A:\n\
	lsls r0, r1, #0x10\n\
	asrs r1, r0, #0x10\n\
	cmp r1, #0\n\
	ble _080F1E7C\n\
	movs r0, #3\n\
	b _080F1FD8\n\
	.align 2, 0\n\
_080F1E78: .4byte gTextWindow+8\n\
_080F1E7C:\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	cmp r1, r0\n\
	bne _080F1F40\n\
	ldr r5, _080F1E9C @ =gCurStory\n\
	ldrb r1, [r5, #5]\n\
	movs r6, #4\n\
	adds r0, r6, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F1EA4\n\
	ldr r0, _080F1EA0 @ =0x00000207\n\
	bl PrintOptionMessage2\n\
	b _080F1FD6\n\
	.align 2, 0\n\
_080F1E9C: .4byte gCurStory\n\
_080F1EA0: .4byte 0x00000207\n\
_080F1EA4:\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F1EF4\n\
	ldrb r0, [r5, #0xd]\n\
	cmp r0, #0\n\
	bne _080F1ED4\n\
	movs r0, #0x82\n\
	lsls r0, r0, #2\n\
	bl PrintOptionMessage2\n\
	ldr r0, _080F1ED0 @ =gStageDiskManager\n\
	ldr r0, [r0]\n\
	ldrb r1, [r0, #0x16]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	lsrs r0, r0, #3\n\
	cmp r0, #0\n\
	bne _080F1EDE\n\
	movs r0, #1\n\
	strb r0, [r5, #0xd]\n\
	b _080F1FD6\n\
	.align 2, 0\n\
_080F1ED0: .4byte gStageDiskManager\n\
_080F1ED4:\n\
	cmp r0, #1\n\
	bne _080F1EE8\n\
	ldr r0, _080F1EE4 @ =0x00000209\n\
	bl PrintOptionMessage2\n\
_080F1EDE:\n\
	movs r0, #2\n\
	strb r0, [r5, #0xd]\n\
	b _080F1FD6\n\
	.align 2, 0\n\
_080F1EE4: .4byte 0x00000209\n\
_080F1EE8:\n\
	ldr r0, _080F1EF0 @ =0x0000020E\n\
	bl PrintOptionMessage2\n\
	b _080F1FD6\n\
	.align 2, 0\n\
_080F1EF0: .4byte 0x0000020E\n\
_080F1EF4:\n\
	ldrb r1, [r5, #6]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F1F20\n\
	ldrb r0, [r5, #0xd]\n\
	cmp r0, #2\n\
	bhi _080F1F14\n\
	ldr r0, _080F1F10 @ =0x0000020A\n\
	bl PrintOptionMessage2\n\
	movs r0, #3\n\
	strb r0, [r5, #0xd]\n\
	b _080F1FD6\n\
	.align 2, 0\n\
_080F1F10: .4byte 0x0000020A\n\
_080F1F14:\n\
	ldr r0, _080F1F1C @ =0x0000020B\n\
	bl PrintOptionMessage2\n\
	b _080F1FD6\n\
	.align 2, 0\n\
_080F1F1C: .4byte 0x0000020B\n\
_080F1F20:\n\
	ldrb r0, [r5, #0xd]\n\
	cmp r0, #3\n\
	bhi _080F1F32\n\
	movs r0, #0x83\n\
	lsls r0, r0, #2\n\
	bl PrintOptionMessage2\n\
	strb r6, [r5, #0xd]\n\
	b _080F1FD6\n\
_080F1F32:\n\
	ldr r0, _080F1F3C @ =0x0000020D\n\
	bl PrintOptionMessage2\n\
	b _080F1FD6\n\
	.align 2, 0\n\
_080F1F3C: .4byte 0x0000020D\n\
_080F1F40:\n\
	movs r0, #3\n\
	bl PlaySound\n\
	movs r0, #2\n\
	b _080F1FD8\n\
_080F1F4A:\n\
	ldr r2, _080F1F60 @ =gTextWindow+8\n\
	ldrh r0, [r2, #2]\n\
	cmp r0, #0\n\
	bne _080F1F6C\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r0, r4, #0\n\
	bl SetGameMode\n\
	b _080F1FDA\n\
	.align 2, 0\n\
_080F1F60: .4byte gTextWindow+8\n\
_080F1F64:\n\
	ldr r2, _080F1F78 @ =gTextWindow+8\n\
	ldrh r0, [r2, #2]\n\
	cmp r0, #0\n\
	beq _080F1F7C\n\
_080F1F6C:\n\
	ldrh r1, [r2]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	b _080F1FDA\n\
	.align 2, 0\n\
_080F1F78: .4byte gTextWindow+8\n\
_080F1F7C:\n\
	ldr r0, _080F1FAC @ =gStageRun\n\
	movs r3, #0xaa\n\
	lsls r3, r3, #1\n\
	adds r0, r0, r3\n\
	movs r1, #2\n\
	str r1, [r0]\n\
	ldrb r0, [r4, #3]\n\
	adds r0, #1\n\
	strb r0, [r4, #3]\n\
_080F1F8E:\n\
	ldr r0, _080F1FAC @ =gStageRun\n\
	movs r1, #0xaa\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	cmp r0, #0\n\
	bne _080F1FDA\n\
	adds r0, r4, #0\n\
	bl SaveGraphicState\n\
	adds r0, r4, #0\n\
	movs r1, #2\n\
	bl SetGameMode\n\
	b _080F1FDA\n\
	.align 2, 0\n\
_080F1FAC: .4byte gStageRun\n\
_080F1FB0:\n\
	adds r0, r4, #0\n\
	bl RestoreGraphicState\n\
	ldr r0, _080F1FE0 @ =gStageRun\n\
	movs r3, #0xaa\n\
	lsls r3, r3, #1\n\
	adds r0, r0, r3\n\
	movs r1, #1\n\
	str r1, [r0]\n\
	ldrb r0, [r4, #3]\n\
	adds r0, #1\n\
	strb r0, [r4, #3]\n\
_080F1FC8:\n\
	ldr r0, _080F1FE0 @ =gStageRun\n\
	movs r1, #0xaa\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	cmp r0, #0\n\
	bne _080F1FDA\n\
_080F1FD6:\n\
	movs r0, #0xff\n\
_080F1FD8:\n\
	strb r0, [r4, #3]\n\
_080F1FDA:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F1FE0: .4byte gStageRun\n\
 .syntax divided\n");
}
