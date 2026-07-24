	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c466c
FUN_080c466c: @ 0x080C466C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C46E8
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _080C46D0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C46D4 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080C46D8 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	str r0, [sp, #4]
	ldrb r1, [r6, #0x10]
	ldr r2, _080C46DC @ =0x00007507
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080c44a8
	ldrb r1, [r6, #0x10]
	ldr r2, _080C46E0 @ =0x00007508
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080c44a8
	ldrb r1, [r6, #0x10]
	ldr r2, _080C46E4 @ =0x00007509
	mov r0, sp
	b _080C4754
	.align 2, 0
_080C46D0: .4byte RNG_0202f388
_080C46D4: .4byte 0x000343FD
_080C46D8: .4byte 0x00269EC3
_080C46DC: .4byte 0x00007507
_080C46E0: .4byte 0x00007508
_080C46E4: .4byte 0x00007509
_080C46E8:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080C478C
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080C478C
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _080C4770 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C4774 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080C4778 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r6, #0x54]
	str r0, [sp, #8]
	ldr r0, [r6, #0x58]
	add r5, sp, #8
	str r0, [r5, #4]
	ldrb r1, [r6, #0x10]
	ldr r2, _080C477C @ =0x00007507
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080c44a8
	ldrb r1, [r6, #0x10]
	ldr r2, _080C4780 @ =0x00007508
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080c44a8
	ldrb r1, [r6, #0x10]
	ldr r2, _080C4784 @ =0x00007509
	adds r0, r5, #0
_080C4754:
	adds r3, r4, #0
	bl FUN_080c44a8
	ldr r1, _080C4788 @ =gVFXFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	b _080C47D2
	.align 2, 0
_080C4770: .4byte RNG_0202f388
_080C4774: .4byte 0x000343FD
_080C4778: .4byte 0x00269EC3
_080C477C: .4byte 0x00007507
_080C4780: .4byte 0x00007508
_080C4784: .4byte 0x00007509
_080C4788: .4byte gVFXFnTable
_080C478C:
	ldrb r1, [r6, #0xe]
	cmp r1, #0
	beq _080C4798
	cmp r1, #1
	beq _080C47AC
	b _080C47D2
_080C4798:
	movs r0, #0x3c
	strb r0, [r6, #0x12]
	str r1, [r6, #0x60]
	ldr r1, _080C47DC @ =0x00007506
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080C47AC:
	ldr r0, [r6, #0x60]
	adds r0, #0x20
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C47BC
	str r1, [r6, #0x60]
_080C47BC:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	adds r0, r6, #0
	bl UpdateEntityAnim
_080C47D2:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C47DC: .4byte 0x00007506
