	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start rocinolle_080da294
rocinolle_080da294: @ 0x080DA294
	push {r4, lr}
	ldr r2, _080DA2B8 @ =gCurStory
	ldrb r1, [r2, #6]
	movs r4, #1
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080DA2E4
	ldrb r0, [r2, #0x18]
	cmp r0, #1
	bhi _080DA2BC
	movs r0, #2
	strb r0, [r2, #0x18]
	movs r0, #0x97
	lsls r0, r0, #2
	b _080DA316
	.align 2, 0
_080DA2B8: .4byte gCurStory
_080DA2BC:
	ldr r0, _080DA2D4 @ =gStageDiskManager
	ldr r0, [r0]
	ldrb r1, [r0, #0xa]
	movs r0, #0xf
	ands r0, r1
	lsrs r0, r0, #3
	ands r0, r4
	cmp r0, #0
	beq _080DA2DC
	ldr r0, _080DA2D8 @ =0x0000025E
	b _080DA316
	.align 2, 0
_080DA2D4: .4byte gStageDiskManager
_080DA2D8: .4byte 0x0000025E
_080DA2DC:
	ldr r0, _080DA2E0 @ =0x0000025D
	b _080DA316
	.align 2, 0
_080DA2E0: .4byte 0x0000025D
_080DA2E4:
	ldrb r0, [r2, #0x18]
	cmp r0, #0
	bne _080DA2F4
	strb r3, [r2, #0x18]
	ldr r0, _080DA2F0 @ =0x00000259
	b _080DA316
	.align 2, 0
_080DA2F0: .4byte 0x00000259
_080DA2F4:
	ldr r0, _080DA30C @ =gStageDiskManager
	ldr r0, [r0]
	adds r0, #0x29
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsrs r0, r0, #2
	ands r0, r4
	cmp r0, #0
	bne _080DA314
	ldr r0, _080DA310 @ =0x0000025A
	b _080DA316
	.align 2, 0
_080DA30C: .4byte gStageDiskManager
_080DA310: .4byte 0x0000025A
_080DA314:
	ldr r0, _080DA31C @ =0x0000025B
_080DA316:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080DA31C: .4byte 0x0000025B
