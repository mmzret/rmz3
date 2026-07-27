	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start menart_080da18c
menart_080da18c: @ 0x080DA18C
	push {lr}
	ldr r2, _080DA1AC @ =gCurStory
	ldrb r1, [r2, #6]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080DA1BA
	ldrb r0, [r2, #0x12]
	cmp r0, #2
	bhi _080DA1B4
	movs r0, #3
	strb r0, [r2, #0x12]
	ldr r0, _080DA1B0 @ =0x00000257
	b _080DA218
	.align 2, 0
_080DA1AC: .4byte gCurStory
_080DA1B0: .4byte 0x00000257
_080DA1B4:
	movs r0, #0x96
	lsls r0, r0, #2
	b _080DA218
_080DA1BA:
	ldrb r1, [r2, #5]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080DA1E0
	ldrb r0, [r2, #0x12]
	cmp r0, #1
	bhi _080DA1D8
	movs r0, #2
	strb r0, [r2, #0x12]
	ldr r0, _080DA1D4 @ =0x00000255
	b _080DA218
	.align 2, 0
_080DA1D4: .4byte 0x00000255
_080DA1D8:
	ldr r0, _080DA1DC @ =0x00000256
	b _080DA218
	.align 2, 0
_080DA1DC: .4byte 0x00000256
_080DA1E0:
	ldrb r0, [r2, #0x12]
	cmp r0, #0
	bne _080DA1F0
	strb r3, [r2, #0x12]
	ldr r0, _080DA1EC @ =0x00000252
	b _080DA218
	.align 2, 0
_080DA1EC: .4byte 0x00000252
_080DA1F0:
	ldr r0, _080DA20C @ =gStageDiskManager
	ldr r0, [r0]
	adds r0, #0x2b
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsrs r0, r0, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080DA214
	ldr r0, _080DA210 @ =0x00000253
	b _080DA218
	.align 2, 0
_080DA20C: .4byte gStageDiskManager
_080DA210: .4byte 0x00000253
_080DA214:
	movs r0, #0x95
	lsls r0, r0, #2
_080DA218:
	pop {r1}
	bx r1
