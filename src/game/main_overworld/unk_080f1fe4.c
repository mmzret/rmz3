#include "game.h"
#include "global.h"

NAKED void OverworldLoop_080f1fe4(struct GameState *p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #3]\n\
	cmp r0, #3\n\
	beq _080F2084\n\
	cmp r0, #3\n\
	bgt _080F2000\n\
	cmp r0, #1\n\
	beq _080F2026\n\
	cmp r0, #1\n\
	bgt _080F203E\n\
	cmp r0, #0\n\
	beq _080F201A\n\
	b _080F2012\n\
_080F2000:\n\
	cmp r0, #0x77\n\
	beq _080F20B8\n\
	cmp r0, #0x77\n\
	bgt _080F200E\n\
	cmp r0, #4\n\
	beq _080F2094\n\
	b _080F2012\n\
_080F200E:\n\
	cmp r0, #0x7c\n\
	beq _080F20D0\n\
_080F2012:\n\
	adds r0, r4, #0\n\
	bl OverworldLoop_ManageSaveData\n\
	b _080F20E6\n\
_080F201A:\n\
	ldr r0, _080F2064 @ =0x00001301\n\
	bl PrintOptionMessage2\n\
	ldrb r0, [r4, #3]\n\
	adds r0, #1\n\
	strb r0, [r4, #3]\n\
_080F2026:\n\
	ldr r0, _080F2068 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F2032\n\
	cmp r0, #4\n\
	bne _080F20E6\n\
_080F2032:\n\
	ldr r0, _080F206C @ =0x00001302\n\
	bl PrintOptionMessage1\n\
	ldrb r0, [r4, #3]\n\
	adds r0, #1\n\
	strb r0, [r4, #3]\n\
_080F203E:\n\
	ldr r0, _080F2068 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F204A\n\
	cmp r0, #4\n\
	bne _080F20E6\n\
_080F204A:\n\
	adds r0, r4, #0\n\
	bl handleWrapTwoChoice\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080F20E6\n\
	lsls r0, r1, #0x10\n\
	asrs r1, r0, #0x10\n\
	cmp r1, #0\n\
	ble _080F2070\n\
	movs r0, #0x70\n\
	b _080F20E4\n\
	.align 2, 0\n\
_080F2064: .4byte 0x00001301\n\
_080F2068: .4byte gTextWindow+8\n\
_080F206C: .4byte 0x00001302\n\
_080F2070:\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	cmp r1, r0\n\
	bne _080F207C\n\
	movs r0, #0x7c\n\
	b _080F20E4\n\
_080F207C:\n\
	movs r0, #4\n\
	bl PlaySound\n\
	b _080F20E6\n\
_080F2084:\n\
	ldr r0, _080F20A8 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F2090\n\
	cmp r0, #4\n\
	bne _080F20E6\n\
_080F2090:\n\
	movs r0, #4\n\
	strb r0, [r4, #3]\n\
_080F2094:\n\
	ldr r2, _080F20A8 @ =gTextWindow+8\n\
	ldrh r0, [r2, #2]\n\
	cmp r0, #0\n\
	beq _080F20AC\n\
	ldrh r1, [r2]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	b _080F20E6\n\
	.align 2, 0\n\
_080F20A8: .4byte gTextWindow+8\n\
_080F20AC:\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r0, r4, #0\n\
	bl SetGameMode\n\
	b _080F20E6\n\
_080F20B8:\n\
	ldr r0, _080F20C8 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F20C4\n\
	cmp r0, #4\n\
	bne _080F20E6\n\
_080F20C4:\n\
	ldr r0, _080F20CC @ =0x00001303\n\
	b _080F20DE\n\
	.align 2, 0\n\
_080F20C8: .4byte gTextWindow+8\n\
_080F20CC: .4byte 0x00001303\n\
_080F20D0:\n\
	ldr r0, _080F20EC @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F20DC\n\
	cmp r0, #4\n\
	bne _080F20E6\n\
_080F20DC:\n\
	ldr r0, _080F20F0 @ =0x00001304\n\
_080F20DE:\n\
	bl PrintOptionMessage2\n\
	movs r0, #3\n\
_080F20E4:\n\
	strb r0, [r4, #3]\n\
_080F20E6:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F20EC: .4byte gTextWindow+8\n\
_080F20F0: .4byte 0x00001304\n\
 .syntax divided\n");
}
