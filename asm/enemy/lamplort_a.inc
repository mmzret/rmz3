	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Lamplort_Die
Lamplort_Die: @ 0x0806C448
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldr r0, _0806C494 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0806C49C
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _0806C498 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _0806C7DA
	.align 2, 0
_0806C494: .4byte gCurStory
_0806C498: .4byte gEnemyFnTable
_0806C49C:
	ldrb r0, [r7, #0xe]
	cmp r0, #0xb
	bls _0806C4A4
	b _0806C7DC
_0806C4A4:
	lsls r0, r0, #2
	ldr r1, _0806C4B0 @ =_0806C4B4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806C4B0: .4byte _0806C4B4
_0806C4B4: @ jump table
	.4byte _0806C4E4 @ case 0
	.4byte _0806C5D0 @ case 1
	.4byte _0806C534 @ case 2
	.4byte _0806C548 @ case 3
	.4byte _0806C5D8 @ case 4
	.4byte _0806C7DC @ case 5
	.4byte _0806C7DC @ case 6
	.4byte _0806C7DC @ case 7
	.4byte _0806C7DC @ case 8
	.4byte _0806C7DC @ case 9
	.4byte _0806C5D0 @ case 10
	.4byte _0806C738 @ case 11
_0806C4E4:
	ldr r1, _0806C50C @ =0x0000190A
	adds r0, r7, #0
	bl SetMotion
	adds r1, r7, #0
	adds r1, #0x8c
	ldr r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	adds r3, r1, #0
	cmp r0, #0
	beq _0806C510
	movs r0, #0x80
	lsls r0, r0, #9
	ands r2, r0
	cmp r2, #0
	beq _0806C510
	movs r0, #1
	b _0806C512
	.align 2, 0
_0806C50C: .4byte 0x0000190A
_0806C510:
	movs r0, #0xa
_0806C512:
	strb r0, [r7, #0xe]
	movs r1, #0
	str r1, [r3]
	adds r0, r7, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r2, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x5c
	str r1, [r0, #4]
	str r1, [r7, #0x5c]
	b _0806C5D0
_0806C534:
	adds r0, r7, #0
	bl UpdateEntityAnim
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0806C546
	b _0806C7DC
_0806C546:
	b _0806C5D0
_0806C548:
	ldr r1, _0806C590 @ =0x0000190A
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	bl UpdateEntityAnim
	movs r0, #0
	strb r0, [r7, #0x13]
	str r0, [r7, #0x60]
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r0, #0xbc
	ldrb r1, [r0]
	mov r0, sp
	bl FUN_080b9e68
	adds r0, r7, #0
	adds r0, #0xbb
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _0806C5A0
	cmp r0, #0xfe
	bne _0806C594
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
	b _0806C5C2
	.align 2, 0
_0806C590: .4byte 0x0000190A
_0806C594:
	ldr r0, _0806C5B0 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r7, #0x54]
	cmp r1, r0
	ble _0806C5B4
_0806C5A0:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #1
	bl FUN_080b2b40
	b _0806C5C2
	.align 2, 0
_0806C5B0: .4byte pZero2
_0806C5B4:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
_0806C5C2:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #3
	bl TryDropItem
	movs r0, #0x24
	strb r0, [r7, #0x12]
_0806C5D0:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _0806C7DC
_0806C5D8:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0806C68C
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	ldr r1, _0806C668 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r2, _0806C66C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0806C670 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _0806C674 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp, #8]
	ldr r0, [r7, #0x58]
	add r6, sp, #8
	str r0, [r6, #4]
	adds r5, r7, #0
	adds r5, #0xbc
	ldrb r1, [r5]
	ldr r2, _0806C678 @ =0x0000190C
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080b9ebc
	ldrb r1, [r5]
	ldr r2, _0806C67C @ =0x0000190D
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080b9ebc
	ldrb r1, [r5]
	ldr r2, _0806C680 @ =0x0000190E
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080b9ebc
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _0806C684 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _0806C688 @ =0x0000270E
	cmp r1, r0
	bhi _0806C660
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0806C660:
	adds r1, r7, #0
	adds r1, #0x54
	adds r0, r7, #0
	b _0806C7BE
	.align 2, 0
_0806C668: .4byte 0xFFFFF800
_0806C66C: .4byte RNG_0202f388
_0806C670: .4byte 0x000343FD
_0806C674: .4byte 0x00269EC3
_0806C678: .4byte 0x0000190C
_0806C67C: .4byte 0x0000190D
_0806C680: .4byte 0x0000190E
_0806C684: .4byte gScore
_0806C688: .4byte 0x0000270E
_0806C68C:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _0806C694
	b _0806C7DC
_0806C694:
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0806C6A0
	b _0806C7DC
_0806C6A0:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r2, _0806C718 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0806C71C @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r1, _0806C720 @ =0x00269EC3
	adds r4, r4, r1
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp, #0x10]
	ldr r0, [r7, #0x58]
	add r6, sp, #0x10
	str r0, [r6, #4]
	adds r5, r7, #0
	adds r5, #0xbc
	ldrb r1, [r5]
	ldr r2, _0806C724 @ =0x0000190C
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080b9ebc
	ldrb r1, [r5]
	ldr r2, _0806C728 @ =0x0000190D
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080b9ebc
	ldrb r1, [r5]
	ldr r2, _0806C72C @ =0x0000190E
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080b9ebc
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _0806C730 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _0806C734 @ =0x0000270E
	cmp r1, r0
	bhi _0806C710
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0806C710:
	adds r1, r7, #0
	adds r1, #0x54
	adds r0, r7, #0
	b _0806C7BE
	.align 2, 0
_0806C718: .4byte RNG_0202f388
_0806C71C: .4byte 0x000343FD
_0806C720: .4byte 0x00269EC3
_0806C724: .4byte 0x0000190C
_0806C728: .4byte 0x0000190D
_0806C72C: .4byte 0x0000190E
_0806C730: .4byte gScore
_0806C734: .4byte 0x0000270E
_0806C738:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	ldr r1, _0806C7E8 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	movs r0, #0x54
	adds r0, r0, r7
	mov r8, r0
	movs r0, #3
	mov r1, r8
	bl TryDropItem
	ldr r2, _0806C7EC @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0806C7F0 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r1, _0806C7F4 @ =0x00269EC3
	adds r4, r4, r1
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp, #0x18]
	ldr r0, [r7, #0x58]
	add r6, sp, #0x18
	str r0, [r6, #4]
	adds r5, r7, #0
	adds r5, #0xbc
	ldrb r1, [r5]
	ldr r2, _0806C7F8 @ =0x0000190C
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080b9ebc
	ldrb r1, [r5]
	ldr r2, _0806C7FC @ =0x0000190D
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080b9ebc
	ldrb r1, [r5]
	ldr r2, _0806C800 @ =0x0000190E
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080b9ebc
	ldr r2, _0806C804 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _0806C808 @ =0x0000270E
	cmp r1, r0
	bhi _0806C7BA
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0806C7BA:
	adds r0, r7, #0
	mov r1, r8
_0806C7BE:
	bl TryDropZakoDisk
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _0806C80C @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
_0806C7DA:
	str r0, [r7, #0x14]
_0806C7DC:
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806C7E8: .4byte 0xFFFFF800
_0806C7EC: .4byte RNG_0202f388
_0806C7F0: .4byte 0x000343FD
_0806C7F4: .4byte 0x00269EC3
_0806C7F8: .4byte 0x0000190C
_0806C7FC: .4byte 0x0000190D
_0806C800: .4byte 0x0000190E
_0806C804: .4byte gScore
_0806C808: .4byte 0x0000270E
_0806C80C: .4byte gEnemyFnTable

