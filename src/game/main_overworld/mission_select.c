#include "game.h"
#include "global.h"

NAKED void OverworldLoop_MissionSelect(struct GameState *p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #3]\n\
	cmp r0, #0xb\n\
	bhi _080F213C\n\
	lsls r0, r0, #2\n\
	ldr r1, _080F2108 @ =_080F210C\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080F2108: .4byte _080F210C\n\
_080F210C: @ jump table\n\
	.4byte _080F2144 @ case 0\n\
	.4byte _080F2150 @ case 1\n\
	.4byte _080F2168 @ case 2\n\
	.4byte _080F219C @ case 3\n\
	.4byte _080F21AE @ case 4\n\
	.4byte _080F213C @ case 5\n\
	.4byte _080F213C @ case 6\n\
	.4byte _080F213C @ case 7\n\
	.4byte _080F213C @ case 8\n\
	.4byte _080F213C @ case 9\n\
	.4byte _080F213C @ case 10\n\
	.4byte _080F21D0 @ case 11\n\
_080F213C:\n\
	adds r0, r4, #0\n\
	bl OverworldLoop_CmdRoomTalk\n\
	b _080F21E6\n\
_080F2144:\n\
	ldr r0, _080F218C @ =0x0000130D\n\
	bl PrintOptionMessage2\n\
	ldrb r0, [r4, #3]\n\
	adds r0, #1\n\
	strb r0, [r4, #3]\n\
_080F2150:\n\
	ldr r0, _080F2190 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F215C\n\
	cmp r0, #4\n\
	bne _080F21E6\n\
_080F215C:\n\
	ldr r0, _080F2194 @ =0x0000130E\n\
	bl PrintOptionMessage1\n\
	ldrb r0, [r4, #3]\n\
	adds r0, #1\n\
	strb r0, [r4, #3]\n\
_080F2168:\n\
	ldr r0, _080F2190 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F2174\n\
	cmp r0, #4\n\
	bne _080F21E6\n\
_080F2174:\n\
	adds r0, r4, #0\n\
	bl handleWrapTwoChoice\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080F21E6\n\
	lsls r0, r1, #0x10\n\
	cmp r0, #0\n\
	ble _080F2198\n\
	movs r0, #0x12\n\
	b _080F21E4\n\
	.align 2, 0\n\
_080F218C: .4byte 0x0000130D\n\
_080F2190: .4byte gTextWindow+8\n\
_080F2194: .4byte 0x0000130E\n\
_080F2198:\n\
	movs r0, #0xb\n\
	b _080F21E4\n\
_080F219C:\n\
	ldr r0, _080F21C0 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F21A8\n\
	cmp r0, #4\n\
	bne _080F21E6\n\
_080F21A8:\n\
	ldrb r0, [r4, #3]\n\
	adds r0, #1\n\
	strb r0, [r4, #3]\n\
_080F21AE:\n\
	ldr r2, _080F21C0 @ =gTextWindow+8\n\
	ldrh r0, [r2, #2]\n\
	cmp r0, #0\n\
	beq _080F21C4\n\
	ldrh r1, [r2]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	b _080F21E6\n\
	.align 2, 0\n\
_080F21C0: .4byte gTextWindow+8\n\
_080F21C4:\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r0, r4, #0\n\
	bl SetGameMode\n\
	b _080F21E6\n\
_080F21D0:\n\
	ldr r0, _080F21EC @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F21DC\n\
	cmp r0, #4\n\
	bne _080F21E6\n\
_080F21DC:\n\
	ldr r0, _080F21F0 @ =0x0000130F\n\
	bl PrintOptionMessage2\n\
	movs r0, #3\n\
_080F21E4:\n\
	strb r0, [r4, #3]\n\
_080F21E6:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F21EC: .4byte gTextWindow+8\n\
_080F21F0: .4byte 0x0000130F\n\
 .syntax divided\n");
}
