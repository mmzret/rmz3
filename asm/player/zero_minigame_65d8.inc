	.include "asm/macros.inc"

	.syntax unified
	
	.text

	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r0, [r3, #0x28]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq _080365E8
	b _080366EE
_080365E8:
	ldr r2, _08036608 @ =gJoypad
	ldrh r1, [r2, #4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803663A
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08036610
	ldr r4, _0803660C @ =0x00000287
	adds r1, r3, r4
	movs r0, #2
	strb r0, [r1]
	b _08036632
	.align 2, 0
_08036608: .4byte gJoypad
_0803660C: .4byte 0x00000287
_08036610:
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0803662C
	ldr r5, _08036628 @ =0x00000287
	adds r1, r3, r5
	movs r0, #4
	strb r0, [r1]
	b _08036632
	.align 2, 0
_08036628: .4byte 0x00000287
_0803662C:
	ldr r4, _0803666C @ =0x00000287
	adds r0, r3, r4
	strb r1, [r0]
_08036632:
	movs r1, #0
	movs r0, #3
	strb r0, [r3, #0xd]
	strb r1, [r3, #0xe]
_0803663A:
	ldr r5, _08036670 @ =0x0000027D
	adds r4, r3, r5
	ldrb r0, [r4]
	cmp r0, #1
	bne _08036694
	ldrh r2, [r2]
	movs r0, #2
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _080366EE
	subs r5, #1
	adds r0, r3, r5
	strb r1, [r0]
	strb r1, [r4]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _08036674
	ldr r0, _0803666C @ =0x00000287
	adds r1, r3, r0
	movs r0, #7
	b _080366C0
	.align 2, 0
_0803666C: .4byte 0x00000287
_08036670: .4byte 0x0000027D
_08036674:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _08036688
	ldr r2, _08036684 @ =0x00000287
	adds r1, r3, r2
	movs r0, #8
	b _080366C0
	.align 2, 0
_08036684: .4byte 0x00000287
_08036688:
	ldr r4, _08036690 @ =0x00000287
	adds r1, r3, r4
	movs r0, #6
	b _080366C0
	.align 2, 0
_08036690: .4byte 0x00000287
_08036694:
	movs r5, #0x9f
	lsls r5, r5, #2
	adds r1, r3, r5
	ldrb r0, [r1]
	cmp r0, #0xa
	bls _080366EE
	ldrh r2, [r2]
	movs r0, #2
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _080366EE
	strb r0, [r1]
	strb r0, [r4]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _080366C8
	ldr r0, _080366C4 @ =0x00000287
	adds r1, r3, r0
	movs r0, #2
_080366C0:
	strb r0, [r1]
	b _080366E6
	.align 2, 0
_080366C4: .4byte 0x00000287
_080366C8:
	movs r0, #0x80
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080366E0
	ldr r2, _080366DC @ =0x00000287
	adds r1, r3, r2
	movs r0, #4
	b _080366C0
	.align 2, 0
_080366DC: .4byte 0x00000287
_080366E0:
	ldr r4, _080366F8 @ =0x00000287
	adds r0, r3, r4
	strb r1, [r0]
_080366E6:
	movs r1, #0
	movs r0, #3
	strb r0, [r3, #0xd]
	strb r1, [r3, #0xe]
_080366EE:
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080366F8: .4byte 0x00000287
