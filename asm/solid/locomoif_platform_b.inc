	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080ce7a4
FUN_080ce7a4: @ 0x080CE7A4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080CE7B4
	cmp r5, #1
	beq _080CE7CE
	b _080CE7FE
_080CE7B4:
	ldr r0, _080CE804 @ =0x0000010B
	bl PlaySound
	ldr r1, _080CE808 @ =0x00005501
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x40
	strb r0, [r4, #0x12]
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CE7CE:
	ldr r1, [r4, #0x5c]
	adds r1, #4
	str r1, [r4, #0x5c]
	adds r2, r4, #0
	adds r2, #0xb4
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	bl FUN_080ce538
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CE7FE
	movs r0, #2
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_080CE7FE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CE804: .4byte 0x0000010B
_080CE808: .4byte 0x00005501

	thumb_func_start FUN_080ce80c
FUN_080ce80c: @ 0x080CE80C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080CE81E
	cmp r0, #1
	beq _080CE828
	b _080CE862
_080CE81E:
	movs r0, #0x40
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CE828:
	ldr r1, [r4, #0x5c]
	subs r1, #4
	str r1, [r4, #0x5c]
	adds r2, r4, #0
	adds r2, #0xb4
	ldrh r0, [r2]
	adds r0, r0, r1
	movs r5, #0
	strh r0, [r2]
	adds r0, r4, #0
	bl FUN_080ce538
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CE862
	ldr r0, _080CE868 @ =0x0000010B
	bl StopSound
	adds r0, r6, #0
	adds r0, #0xbd
	strb r5, [r0]
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_080CE862:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CE868: .4byte 0x0000010B
