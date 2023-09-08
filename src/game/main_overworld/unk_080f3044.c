#include "game.h"
#include "global.h"

NAKED void OverworldLoop_080f3044(struct GameState *p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #3]\n\
	cmp r0, #0xb\n\
	bhi _080F308C\n\
	lsls r0, r0, #2\n\
	ldr r1, _080F3058 @ =_080F305C\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080F3058: .4byte _080F305C\n\
_080F305C: @ jump table\n\
	.4byte _080F3094 @ case 0\n\
	.4byte _080F308C @ case 1\n\
	.4byte _080F309E @ case 2\n\
	.4byte _080F30D0 @ case 3\n\
	.4byte _080F30E2 @ case 4\n\
	.4byte _080F308C @ case 5\n\
	.4byte _080F308C @ case 6\n\
	.4byte _080F308C @ case 7\n\
	.4byte _080F308C @ case 8\n\
	.4byte _080F308C @ case 9\n\
	.4byte _080F308C @ case 10\n\
	.4byte _080F3104 @ case 11\n\
_080F308C:\n\
	adds r0, r4, #0\n\
	bl OverworldLoop_CmdRoomTalk\n\
	b _080F311A\n\
_080F3094:\n\
	ldr r0, _080F30C4 @ =0x0000130E\n\
	bl PrintOptionMessage1\n\
	movs r0, #2\n\
	strb r0, [r4, #3]\n\
_080F309E:\n\
	ldr r0, _080F30C8 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F30AA\n\
	cmp r0, #4\n\
	bne _080F311A\n\
_080F30AA:\n\
	adds r0, r4, #0\n\
	bl handleWrapTwoChoice\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080F311A\n\
	lsls r0, r1, #0x10\n\
	cmp r0, #0\n\
	ble _080F30CC\n\
	movs r0, #0x12\n\
	b _080F3118\n\
	.align 2, 0\n\
_080F30C4: .4byte 0x0000130E\n\
_080F30C8: .4byte gTextWindow+8\n\
_080F30CC:\n\
	movs r0, #0xb\n\
	b _080F3118\n\
_080F30D0:\n\
	ldr r0, _080F30F4 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F30DC\n\
	cmp r0, #4\n\
	bne _080F311A\n\
_080F30DC:\n\
	ldrb r0, [r4, #3]\n\
	adds r0, #1\n\
	strb r0, [r4, #3]\n\
_080F30E2:\n\
	ldr r2, _080F30F4 @ =gTextWindow+8\n\
	ldrh r0, [r2, #2]\n\
	cmp r0, #0\n\
	beq _080F30F8\n\
	ldrh r1, [r2]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	b _080F311A\n\
	.align 2, 0\n\
_080F30F4: .4byte gTextWindow+8\n\
_080F30F8:\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r0, r4, #0\n\
	bl SetGameMode\n\
	b _080F311A\n\
_080F3104:\n\
	ldr r0, _080F3120 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F3110\n\
	cmp r0, #4\n\
	bne _080F311A\n\
_080F3110:\n\
	ldr r0, _080F3124 @ =0x0000130F\n\
	bl PrintOptionMessage2\n\
	movs r0, #3\n\
_080F3118:\n\
	strb r0, [r4, #3]\n\
_080F311A:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F3120: .4byte gTextWindow+8\n\
_080F3124: .4byte 0x0000130F\n\
 .syntax divided\n");
}
