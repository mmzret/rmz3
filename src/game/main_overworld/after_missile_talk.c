#include "game.h"
#include "global.h"

NAKED void OverworldLoop_AfterMissileTalk(struct GameState *p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #3]\n\
	cmp r0, #3\n\
	beq _080F2DD4\n\
	cmp r0, #3\n\
	bgt _080F2D50\n\
	cmp r0, #1\n\
	beq _080F2D76\n\
	cmp r0, #1\n\
	bgt _080F2D8E\n\
	cmp r0, #0\n\
	beq _080F2D6A\n\
	b _080F2D62\n\
_080F2D50:\n\
	cmp r0, #0x77\n\
	beq _080F2E08\n\
	cmp r0, #0x77\n\
	bgt _080F2D5E\n\
	cmp r0, #4\n\
	beq _080F2DE4\n\
	b _080F2D62\n\
_080F2D5E:\n\
	cmp r0, #0x7c\n\
	beq _080F2E20\n\
_080F2D62:\n\
	adds r0, r4, #0\n\
	bl OverworldLoop_ManageSaveData\n\
	b _080F2E36\n\
_080F2D6A:\n\
	ldr r0, _080F2DB4 @ =0x00001326\n\
	bl PrintOptionMessage2\n\
	ldrb r0, [r4, #3]\n\
	adds r0, #1\n\
	strb r0, [r4, #3]\n\
_080F2D76:\n\
	ldr r0, _080F2DB8 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F2D82\n\
	cmp r0, #4\n\
	bne _080F2E36\n\
_080F2D82:\n\
	ldr r0, _080F2DBC @ =0x00001302\n\
	bl PrintOptionMessage1\n\
	ldrb r0, [r4, #3]\n\
	adds r0, #1\n\
	strb r0, [r4, #3]\n\
_080F2D8E:\n\
	ldr r0, _080F2DB8 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F2D9A\n\
	cmp r0, #4\n\
	bne _080F2E36\n\
_080F2D9A:\n\
	adds r0, r4, #0\n\
	bl handleWrapTwoChoice\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080F2E36\n\
	lsls r0, r1, #0x10\n\
	asrs r1, r0, #0x10\n\
	cmp r1, #0\n\
	ble _080F2DC0\n\
	movs r0, #0x70\n\
	b _080F2E34\n\
	.align 2, 0\n\
_080F2DB4: .4byte 0x00001326\n\
_080F2DB8: .4byte gTextWindow+8\n\
_080F2DBC: .4byte 0x00001302\n\
_080F2DC0:\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	cmp r1, r0\n\
	bne _080F2DCC\n\
	movs r0, #0x7c\n\
	b _080F2E34\n\
_080F2DCC:\n\
	movs r0, #4\n\
	bl PlaySound\n\
	b _080F2E36\n\
_080F2DD4:\n\
	ldr r0, _080F2DF8 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F2DE0\n\
	cmp r0, #4\n\
	bne _080F2E36\n\
_080F2DE0:\n\
	movs r0, #4\n\
	strb r0, [r4, #3]\n\
_080F2DE4:\n\
	ldr r2, _080F2DF8 @ =gTextWindow+8\n\
	ldrh r0, [r2, #2]\n\
	cmp r0, #0\n\
	beq _080F2DFC\n\
	ldrh r1, [r2]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	b _080F2E36\n\
	.align 2, 0\n\
_080F2DF8: .4byte gTextWindow+8\n\
_080F2DFC:\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r0, r4, #0\n\
	bl SetGameMode\n\
	b _080F2E36\n\
_080F2E08:\n\
	ldr r0, _080F2E18 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F2E14\n\
	cmp r0, #4\n\
	bne _080F2E36\n\
_080F2E14:\n\
	ldr r0, _080F2E1C @ =0x00001327\n\
	b _080F2E2E\n\
	.align 2, 0\n\
_080F2E18: .4byte gTextWindow+8\n\
_080F2E1C: .4byte 0x00001327\n\
_080F2E20:\n\
	ldr r0, _080F2E3C @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F2E2C\n\
	cmp r0, #4\n\
	bne _080F2E36\n\
_080F2E2C:\n\
	ldr r0, _080F2E40 @ =0x00001328\n\
_080F2E2E:\n\
	bl PrintOptionMessage2\n\
	movs r0, #3\n\
_080F2E34:\n\
	strb r0, [r4, #3]\n\
_080F2E36:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F2E3C: .4byte gTextWindow+8\n\
_080F2E40: .4byte 0x00001328\n\
 .syntax divided\n");
}
