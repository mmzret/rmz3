	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start phantom_08060668
phantom_08060668: @ 0x08060668
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #6
	bls _08060674
	b _08060794
_08060674:
	lsls r0, r0, #2
	ldr r1, _08060680 @ =_08060684
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08060680: .4byte _08060684
_08060684: @ jump table
	.4byte _080606A0 @ case 0
	.4byte _080606F2 @ case 1
	.4byte _0806072C @ case 2
	.4byte _0806073A @ case 3
	.4byte _08060758 @ case 4
	.4byte _08060762 @ case 5
	.4byte _08060794 @ case 6
_080606A0:
	ldrb r0, [r5, #0xa]
	movs r1, #1
	orrs r1, r0
	strb r1, [r5, #0xa]
	ldr r3, _08060720 @ =gStageRun
	ldrh r2, [r3, #8]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r2
	cmp r0, #0
	beq _080606CA
	ldrb r1, [r3, #0x12]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _080606CA
	ldr r0, _08060724 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_080606CA:
	adds r0, r5, #0
	adds r0, #0x8c
	movs r4, #0
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _08060728 @ =0x0000BC0E
	adds r0, r5, #0
	bl SetMotion
	str r4, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080606F2:
	ldr r1, [r5, #0x60]
	adds r1, #0x40
	str r1, [r5, #0x60]
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	movs r0, #0xe0
	lsls r0, r0, #3
	cmp r1, r0
	ble _08060708
	str r0, [r5, #0x60]
_08060708:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _0806074C
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	b _08060746
	.align 2, 0
_08060720: .4byte gStageRun
_08060724: .4byte 0x0000FFFE
_08060728: .4byte 0x0000BC0E
_0806072C:
	ldr r1, _08060754 @ =0x0000BC13
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806073A:
	ldr r0, [r5, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0806074C
_08060746:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806074C:
	adds r0, r5, #0
	bl UpdateEntityAnim
	b _08060794
	.align 2, 0
_08060754: .4byte 0x0000BC13
_08060758:
	movs r0, #0xa
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08060762:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08060794
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r2, _0806079C @ =gStageRun
	ldrb r0, [r2, #0x12]
	movs r1, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
	movs r0, #0x88
	lsls r0, r0, #1
	bl PlaySound
	adds r0, r5, #0
	bl FUN_0805ecc8
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08060794:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806079C: .4byte gStageRun
