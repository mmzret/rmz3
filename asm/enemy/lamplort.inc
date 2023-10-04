	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Lamplort_Init
Lamplort_Init: @ 0x0806C240
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r3, #0
	adds r2, r0, #0
	orrs r2, r1
	movs r0, #2
	orrs r2, r0
	orrs r2, r3
	strb r2, [r6, #0xa]
	ldr r0, _0806C290 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x15]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0806C29C
	ldr r0, _0806C294 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _0806C29C
	movs r0, #4
	orrs r2, r0
	strb r2, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0806C298 @ =0x08366590
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xc
	b _0806C2B4
	.align 2, 0
_0806C290: .4byte gSystemSavedataManager
_0806C294: .4byte gCurStory
_0806C298: .4byte 0x08366590
_0806C29C:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0806C2E0 @ =0x08366590
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #8
_0806C2B4:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _0806C2E4 @ =FUN_0806ce60
	str r0, [r4, #0x24]
	adds r1, r6, #0
	adds r1, #0xb4
	ldr r0, [r6, #0x54]
	str r0, [r1]
	movs r0, #0
	str r0, [r6, #0x60]
	str r0, [r6, #0x5c]
	ldrb r1, [r6, #0x10]
	cmp r1, #0
	bne _0806C2E8
	adds r0, r6, #0
	adds r0, #0xbc
	strb r1, [r0]
	adds r4, r0, #0
	b _0806C2F2
	.align 2, 0
_0806C2E0: .4byte 0x08366590
_0806C2E4: .4byte FUN_0806ce60
_0806C2E8:
	adds r1, r6, #0
	adds r1, #0xbc
	movs r0, #1
	strb r0, [r1]
	adds r4, r1, #0
_0806C2F2:
	ldrb r2, [r4]
	cmp r2, #0
	beq _0806C300
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0806C306
_0806C300:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_0806C306:
	strb r0, [r6, #0xa]
	movs r7, #1
	adds r1, r7, #0
	ands r1, r2
	adds r0, r6, #0
	adds r0, #0x4c
	movs r5, #0
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r6, #0
	adds r0, #0xc0
	str r5, [r0]
	strb r5, [r6, #0x12]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a05c
	str r0, [r6, #0x58]
	ldrb r2, [r4]
	adds r0, r6, #0
	mov r1, sp
	movs r3, #0
	bl CreateProjectile6
	str r0, [r6, #0x2c]
	adds r0, r6, #0
	bl isFrozen
	cmp r0, #0
	beq _0806C362
	movs r1, #0xc8
	lsls r1, r1, #5
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
_0806C362:
	adds r0, r6, #0
	adds r0, #0xbb
	strb r5, [r0]
	ldr r1, _0806C38C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r7, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r7, [r6, #0xd]
	strb r5, [r6, #0xe]
	strb r5, [r6, #0xf]
	adds r0, r6, #0
	bl Lamplort_Update
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806C38C: .4byte gEnemyFnTable

	thumb_func_start Lamplort_Update
Lamplort_Update: @ 0x0806C390
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0806C3AC
	adds r0, r4, #0
	bl FUN_0806ce5c
	cmp r0, #0
	bne _0806C3CC
_0806C3AC:
	ldr r1, _0806C3C8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Lamplort_Die
	b _0806C43C
	.align 2, 0
_0806C3C8: .4byte gEnemyFnTable
_0806C3CC:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0806C3F2
	ldr r1, [r4, #0x2c]
	adds r1, #0xb4
	ldr r0, [r1]
	movs r2, #2
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r1, [r0]
	cmp r1, #0
	bne _0806C3F2
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806C3F2:
	ldr r0, _0806C428 @ =0x08366540
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl lamplort_0806ce08
	ldrb r0, [r4, #0xd]
	cmp r0, #7
	beq _0806C42C
	cmp r0, #9
	beq _0806C42C
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0806C42C
	ldrb r1, [r4, #0xd]
	adds r0, r4, #0
	adds r0, #0xba
	strb r1, [r0]
	b _0806C43C
	.align 2, 0
_0806C428: .4byte 0x08366540
_0806C42C:
	ldr r0, _0806C444 @ =0x08366568
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_0806C43C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806C444: .4byte 0x08366568

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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	ldr r2, _0806C684 @ =gMission
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
_0806C684: .4byte gMission
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
	ldr r2, _0806C730 @ =gMission
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
_0806C730: .4byte gMission
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
	ldr r2, _0806C804 @ =gMission
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
_0806C804: .4byte gMission
_0806C808: .4byte 0x0000270E
_0806C80C: .4byte gEnemyFnTable

	thumb_func_start Lamplort_Disappear
Lamplort_Disappear: @ 0x0806C810
	push {lr}
	bl DeleteEnemy
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0806c81c
FUN_0806c81c: @ 0x0806C81C
	movs r0, #1
	bx lr

	thumb_func_start FUN_0806c820
FUN_0806c820: @ 0x0806C820
	bx lr
	.align 2, 0

	thumb_func_start FUN_0806c824
FUN_0806c824: @ 0x0806C824
	movs r0, #1
	bx lr

	thumb_func_start FUN_0806c828
FUN_0806c828: @ 0x0806C828
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0806C84C
	cmp r0, #1
	bgt _0806C83C
	cmp r0, #0
	beq _0806C842
	b _0806C8C0
_0806C83C:
	cmp r0, #2
	beq _0806C8A2
	b _0806C8C0
_0806C842:
	movs r0, #0x28
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806C84C:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806C874 @ =0x08366590
	bl SetDDP
	movs r1, #0xc8
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r2, [r0]
	cmp r2, #0
	beq _0806C878
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0806C87E
	.align 2, 0
_0806C874: .4byte 0x08366590
_0806C878:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0806C87E:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806C8A2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0806C8B8
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806C8C0
_0806C8B8:
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806C8C0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0806c8c8
FUN_0806c8c8: @ 0x0806C8C8
	movs r0, #1
	bx lr

	thumb_func_start FUN_0806c8cc
FUN_0806c8cc: @ 0x0806C8CC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0806C8DC
	cmp r5, #1
	beq _0806C966
	b _0806C9B4
_0806C8DC:
	ldr r1, _0806C918 @ =0x00001904
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806C91C @ =0x08366590
	bl SetDDP
	ldr r1, [r4, #0x2c]
	adds r1, #0xb4
	ldr r0, [r1]
	movs r6, #1
	orrs r0, r6
	str r0, [r1]
	strb r5, [r4, #0x12]
	ldr r0, _0806C920 @ =0x0000011F
	bl PlaySound
	ldr r0, _0806C924 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bls _0806C928
	strb r5, [r4, #0x13]
	b _0806C92A
	.align 2, 0
_0806C918: .4byte 0x00001904
_0806C91C: .4byte 0x08366590
_0806C920: .4byte 0x0000011F
_0806C924: .4byte gStageRun+232
_0806C928:
	strb r6, [r4, #0x13]
_0806C92A:
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r2, [r0]
	cmp r2, #0
	beq _0806C93C
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0806C942
_0806C93C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0806C942:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806C966:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _0806C988
	ldr r0, _0806C984 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bhi _0806C99E
	movs r0, #1
	b _0806C99C
	.align 2, 0
_0806C984: .4byte gStageRun+232
_0806C988:
	ldr r0, _0806C9BC @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bls _0806C99E
	movs r0, #0
_0806C99C:
	strb r0, [r4, #0x13]
_0806C99E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _0806C9B4
	movs r0, #0
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
_0806C9B4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806C9BC: .4byte gStageRun+232

	thumb_func_start FUN_0806c9c0
FUN_0806c9c0: @ 0x0806C9C0
	movs r0, #1
	bx lr

	thumb_func_start FUN_0806c9c4
FUN_0806c9c4: @ 0x0806C9C4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0806C9D4
	cmp r0, #1
	beq _0806CA50
	b _0806CAB8
_0806C9D4:
	ldr r1, _0806C9F8 @ =0x00001906
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806C9FC @ =0x08366590
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r2, [r0]
	cmp r2, #0
	beq _0806CA00
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0806CA06
	.align 2, 0
_0806C9F8: .4byte 0x00001906
_0806C9FC: .4byte 0x08366590
_0806CA00:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0806CA06:
	strb r0, [r4, #0xa]
	movs r5, #1
	adds r1, r5, #0
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r0, #0xff
	strb r0, [r4, #0x12]
	ldr r0, _0806CA44 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bls _0806CA48
	movs r0, #0
	strb r0, [r4, #0x13]
	b _0806CA4A
	.align 2, 0
_0806CA44: .4byte gStageRun+232
_0806CA48:
	strb r5, [r4, #0x13]
_0806CA4A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806CA50:
	ldrb r0, [r4, #0x12]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne _0806CA60
	ldr r0, _0806CA7C @ =0x0000011F
	bl PlaySound
_0806CA60:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _0806CA84
	ldr r0, _0806CA80 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bhi _0806CA9A
	movs r0, #1
	b _0806CA98
	.align 2, 0
_0806CA7C: .4byte 0x0000011F
_0806CA80: .4byte gStageRun+232
_0806CA84:
	ldr r0, _0806CAC0 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bls _0806CA9A
	movs r0, #0
_0806CA98:
	strb r0, [r4, #0x13]
_0806CA9A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0806CAB0
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806CAB8
_0806CAB0:
	movs r1, #0
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806CAB8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806CAC0: .4byte gStageRun+232

	thumb_func_start true_0806cac4
true_0806cac4: @ 0x0806CAC4
	movs r0, #1
	bx lr

	thumb_func_start FUN_0806cac8
FUN_0806cac8: @ 0x0806CAC8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0806CAD8
	cmp r0, #1
	beq _0806CB3A
	b _0806CB52
_0806CAD8:
	ldr r1, _0806CB08 @ =0x00001908
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806CB0C @ =0x08366590
	bl SetDDP
	ldr r1, [r4, #0x2c]
	adds r1, #0xb4
	ldr r0, [r1]
	movs r2, #2
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r2, [r0]
	cmp r2, #0
	beq _0806CB10
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0806CB16
	.align 2, 0
_0806CB08: .4byte 0x00001908
_0806CB0C: .4byte 0x08366590
_0806CB10:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0806CB16:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806CB3A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0806CB52
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806CB52:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806cb58
FUN_0806cb58: @ 0x0806CB58
	movs r0, #1
	bx lr

	thumb_func_start FUN_0806cb5c
FUN_0806cb5c: @ 0x0806CB5C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0806CB6C
	cmp r0, #1
	beq _0806CBD2
	b _0806CBFA
_0806CB6C:
	ldr r1, _0806CB90 @ =0x00001901
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806CB94 @ =0x08366590
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r2, [r0]
	cmp r2, #0
	beq _0806CB98
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0806CB9E
	.align 2, 0
_0806CB90: .4byte 0x00001901
_0806CB94: .4byte 0x08366590
_0806CB98:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0806CB9E:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, [r4, #0x2c]
	adds r1, #0xb4
	ldr r0, [r1]
	movs r2, #2
	orrs r0, r2
	str r0, [r1]
	movs r0, #8
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806CBD2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0806CBFA
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0806CBF2
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806CBFA
_0806CBF2:
	movs r1, #0
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806CBFA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806cc00
FUN_0806cc00: @ 0x0806CC00
	movs r0, #1
	bx lr

	thumb_func_start lamplort_0806cc04
lamplort_0806cc04: @ 0x0806CC04
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0806CC82
	cmp r0, #1
	bgt _0806CC18
	cmp r0, #0
	beq _0806CC20
	b _0806CD40
_0806CC18:
	cmp r0, #2
	bne _0806CC1E
	b _0806CD38
_0806CC1E:
	b _0806CD40
_0806CC20:
	ldr r1, _0806CC44 @ =0x00001902
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806CC48 @ =0x08366608
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r2, [r0]
	cmp r2, #0
	beq _0806CC4C
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0806CC52
	.align 2, 0
_0806CC44: .4byte 0x00001902
_0806CC48: .4byte 0x08366608
_0806CC4C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0806CC52:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	movs r3, #0
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	strb r3, [r4, #0x13]
	movs r0, #8
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806CC82:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0806CC92
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806CD30
_0806CC92:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #2
	bls _0806CCA8
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0806CCE6
_0806CCA8:
	movs r0, #8
	strb r0, [r4, #0x12]
	cmp r1, #2
	bne _0806CCC0
	ldr r0, _0806CCD4 @ =0x080FF004
	ldrb r1, [r4, #0x13]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	adds r0, r4, #0
	bl SetMotion
_0806CCC0:
	ldrb r0, [r4, #0x13]
	cmp r0, #1
	bne _0806CCDC
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806CCD8 @ =0x08366608
	bl SetDDP
	b _0806CCE6
	.align 2, 0
_0806CCD4: .4byte 0x080FF004
_0806CCD8: .4byte 0x08366608
_0806CCDC:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806CD08 @ =0x08366590
	bl SetDDP
_0806CCE6:
	ldrb r0, [r4, #0x13]
	cmp r0, #1
	bne _0806CD30
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r1, [r0]
	movs r2, #1
	eors r1, r2
	strb r1, [r0]
	ldrb r2, [r0]
	cmp r2, #0
	beq _0806CD0C
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0806CD12
	.align 2, 0
_0806CD08: .4byte 0x08366590
_0806CD0C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0806CD12:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0806CD30:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _0806CD40
_0806CD38:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806CD40:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start true_0806cd48
true_0806cd48: @ 0x0806CD48
	movs r0, #1
	bx lr

	thumb_func_start FUN_0806cd4c
FUN_0806cd4c: @ 0x0806CD4C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0806CD72
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806CD9C @ =0x08366638
	bl SetDDP
	ldr r1, [r4, #0x2c]
	adds r1, #0xb4
	ldr r0, [r1]
	movs r2, #2
	orrs r0, r2
	str r0, [r1]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806CD72:
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0806CD94
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806CDA0 @ =0x08366590
	bl SetDDP
	movs r1, #0
	str r1, [r5]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806CD94:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806CD9C: .4byte 0x08366638
_0806CDA0: .4byte 0x08366590

	thumb_func_start FUN_0806cda4
FUN_0806cda4: @ 0x0806CDA4
	movs r0, #1
	bx lr

	thumb_func_start FUN_0806cda8
FUN_0806cda8: @ 0x0806CDA8
	bx lr
	.align 2, 0

	thumb_func_start FUN_0806cdac
FUN_0806cdac: @ 0x0806CDAC
	movs r0, #1
	bx lr

	thumb_func_start FUN_0806cdb0
FUN_0806cdb0: @ 0x0806CDB0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _0806CDD6
	adds r0, #0x74
	ldr r1, _0806CE00 @ =0x08366638
	bl SetDDP
	ldr r1, [r4, #0x2c]
	adds r1, #0xb4
	ldr r0, [r1]
	movs r2, #2
	orrs r0, r2
	str r0, [r1]
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806CDD6:
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0806CDF8
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806CE04 @ =0x08366590
	bl SetDDP
	movs r1, #0
	str r1, [r5]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806CDF8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806CE00: .4byte 0x08366638
_0806CE04: .4byte 0x08366590

	thumb_func_start lamplort_0806ce08
lamplort_0806ce08: @ 0x0806CE08
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xc0
	ldr r5, [r6]
	cmp r5, #0
	bne _0806CE52
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0806CE52
	ldr r2, _0806CE44 @ =0x08366650
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _0806CE52
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _0806CE48
	movs r0, #7
	b _0806CE4E
	.align 2, 0
_0806CE44: .4byte 0x08366650
_0806CE48:
	cmp r1, #0x30
	bne _0806CE52
	movs r0, #9
_0806CE4E:
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
_0806CE52:
	movs r0, #1
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0806ce5c
FUN_0806ce5c: @ 0x0806CE5C
	movs r0, #1
	bx lr

	thumb_func_start FUN_0806ce60
FUN_0806ce60: @ 0x0806CE60
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	ldr r0, [r3, #0xc]
	ldr r0, [r0, #4]
	ldrb r0, [r0, #4]
	cmp r0, #3
	beq _0806CE78
	cmp r0, #0xe
	beq _0806CE78
	cmp r0, #0xf
	bne _0806CEA2
_0806CE78:
	ldr r2, [r3, #0x2c]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0806CEA2
	ldr r1, [r2, #0x54]
	ldr r0, [r4]
	cmp r1, r0
	bge _0806CE9A
	adds r1, r2, #0
	adds r1, #0xbb
	movs r0, #0xff
	b _0806CEA0
_0806CE9A:
	adds r1, r2, #0
	adds r1, #0xbb
	movs r0, #0xfe
_0806CEA0:
	strb r0, [r1]
_0806CEA2:
	ldr r0, [r3, #4]
	ldrb r0, [r0]
	cmp r0, #2
	bne _0806CF20
	ldr r0, [r3, #0xc]
	ldr r0, [r0, #4]
	ldr r0, [r0, #4]
	ldr r1, _0806CEEC @ =0x000200FF
	ands r0, r1
	subs r1, #0xfd
	cmp r0, r1
	bne _0806CF20
	ldr r2, [r3, #0x2c]
	ldrb r0, [r2, #0xd]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0806CF20
	ldrb r1, [r2, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _0806CEF4
	ldr r0, _0806CEF0 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0806CF08
	movs r0, #5
	strb r0, [r2, #0xd]
	strb r3, [r2, #0xe]
	b _0806CF08
	.align 2, 0
_0806CEEC: .4byte 0x000200FF
_0806CEF0: .4byte pZero2
_0806CEF4:
	ldr r0, _0806CF28 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	ble _0806CF08
	movs r1, #0
	movs r0, #5
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0806CF08:
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0806CF20
	adds r1, r2, #0
	adds r1, #0xa4
	movs r0, #1
	strh r0, [r1]
_0806CF20:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806CF28: .4byte pZero2
