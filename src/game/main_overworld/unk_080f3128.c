#include "game.h"
#include "global.h"

NAKED void OverworldLoop_Save_080f3128(struct GameState *p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #3]\n\
	cmp r0, #3\n\
	beq _080F31C8\n\
	cmp r0, #3\n\
	bgt _080F3144\n\
	cmp r0, #1\n\
	beq _080F316A\n\
	cmp r0, #1\n\
	bgt _080F3182\n\
	cmp r0, #0\n\
	beq _080F315E\n\
	b _080F3156\n\
_080F3144:\n\
	cmp r0, #0x77\n\
	beq _080F31FC\n\
	cmp r0, #0x77\n\
	bgt _080F3152\n\
	cmp r0, #4\n\
	beq _080F31D8\n\
	b _080F3156\n\
_080F3152:\n\
	cmp r0, #0x7c\n\
	beq _080F3214\n\
_080F3156:\n\
	adds r0, r4, #0\n\
	bl OverworldLoop_ManageSaveData\n\
	b _080F322A\n\
_080F315E:\n\
	ldr r0, _080F31A8 @ =0x00001339\n\
	bl PrintOptionMessage2\n\
	ldrb r0, [r4, #3]\n\
	adds r0, #1\n\
	strb r0, [r4, #3]\n\
_080F316A:\n\
	ldr r0, _080F31AC @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F3176\n\
	cmp r0, #4\n\
	bne _080F322A\n\
_080F3176:\n\
	ldr r0, _080F31B0 @ =0x00001302\n\
	bl PrintOptionMessage1\n\
	ldrb r0, [r4, #3]\n\
	adds r0, #1\n\
	strb r0, [r4, #3]\n\
_080F3182:\n\
	ldr r0, _080F31AC @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F318E\n\
	cmp r0, #4\n\
	bne _080F322A\n\
_080F318E:\n\
	adds r0, r4, #0\n\
	bl handleWrapTwoChoice\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080F322A\n\
	lsls r0, r1, #0x10\n\
	asrs r1, r0, #0x10\n\
	cmp r1, #0\n\
	ble _080F31B4\n\
	movs r0, #0x70\n\
	b _080F3228\n\
	.align 2, 0\n\
_080F31A8: .4byte 0x00001339\n\
_080F31AC: .4byte gTextWindow+8\n\
_080F31B0: .4byte 0x00001302\n\
_080F31B4:\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	cmp r1, r0\n\
	bne _080F31C0\n\
	movs r0, #0x7c\n\
	b _080F3228\n\
_080F31C0:\n\
	movs r0, #4\n\
	bl PlaySound\n\
	b _080F322A\n\
_080F31C8:\n\
	ldr r0, _080F31EC @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F31D4\n\
	cmp r0, #4\n\
	bne _080F322A\n\
_080F31D4:\n\
	movs r0, #4\n\
	strb r0, [r4, #3]\n\
_080F31D8:\n\
	ldr r2, _080F31EC @ =gTextWindow+8\n\
	ldrh r0, [r2, #2]\n\
	cmp r0, #0\n\
	beq _080F31F0\n\
	ldrh r1, [r2]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	b _080F322A\n\
	.align 2, 0\n\
_080F31EC: .4byte gTextWindow+8\n\
_080F31F0:\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r0, r4, #0\n\
	bl SetGameMode\n\
	b _080F322A\n\
_080F31FC:\n\
	ldr r0, _080F320C @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F3208\n\
	cmp r0, #4\n\
	bne _080F322A\n\
_080F3208:\n\
	ldr r0, _080F3210 @ =0x0000133A\n\
	b _080F3222\n\
	.align 2, 0\n\
_080F320C: .4byte gTextWindow+8\n\
_080F3210: .4byte 0x0000133A\n\
_080F3214:\n\
	ldr r0, _080F3230 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F3220\n\
	cmp r0, #4\n\
	bne _080F322A\n\
_080F3220:\n\
	ldr r0, _080F3234 @ =0x0000133B\n\
_080F3222:\n\
	bl PrintOptionMessage2\n\
	movs r0, #3\n\
_080F3228:\n\
	strb r0, [r4, #3]\n\
_080F322A:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F3230: .4byte gTextWindow+8\n\
_080F3234: .4byte 0x0000133B\n\
 .syntax divided\n");
}
