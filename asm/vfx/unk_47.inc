	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080bf390
FUN_080bf390: @ 0x080BF390
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x2c]
	ldr r0, _080BF3D0 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080BF3CA
	adds r0, #0x25
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r0, _080BF3D4 @ =gVFXFnTable
	movs r1, #0x2f
	strb r1, [r4, #9]
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r3, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r2, [r4, #0x10]
	str r5, [r4, #0x28]
	str r6, [r4, #0x2c]
_080BF3CA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BF3D0: .4byte gVFXHeaderPtr
_080BF3D4: .4byte gVFXFnTable

	thumb_func_start FUN_080bf3d8
FUN_080bf3d8: @ 0x080BF3D8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r6, #0
	movs r4, #0
	movs r5, #0
	ldr r0, _080BF430 @ =0x0836D9BC
	mov r8, r0
_080BF3EA:
	ldr r0, _080BF434 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r1, r0, #0
	cmp r1, #0
	beq _080BF41E
	adds r2, r1, #0
	adds r2, #0x25
	movs r0, #1
	strb r0, [r2]
	movs r0, #0x2f
	strb r0, [r1, #9]
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0]
	str r0, [r1, #0x14]
	strh r5, [r1, #0x20]
	adds r0, r1, #0
	adds r0, #0x22
	strb r5, [r0]
	strb r5, [r1, #0x10]
	strb r4, [r1, #0x12]
	str r7, [r1, #0x28]
	str r6, [r1, #0x2c]
	adds r6, r1, #0
_080BF41E:
	adds r4, #1
	cmp r4, #1
	ble _080BF3EA
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BF430: .4byte 0x0836D9BC
_080BF434: .4byte gVFXHeaderPtr

	thumb_func_start FUN_080bf438
FUN_080bf438: @ 0x080BF438
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _080BF484 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080BF47C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BF488 @ =gVFXFnTable
	movs r1, #0x2f
	strb r1, [r3, #9]
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #2
	strb r0, [r3, #0x10]
	strb r4, [r3, #0x12]
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
_080BF47C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BF484: .4byte gVFXHeaderPtr
_080BF488: .4byte gVFXFnTable

	thumb_func_start FUN_080bf48c
FUN_080bf48c: @ 0x080BF48C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	movs r4, #0
	movs r7, #0
	ldr r1, _080BF514 @ =0x0836D9BC
	mov sl, r1
	ldr r1, _080BF518 @ =0xFFFFF800
	adds r5, r0, r1
	ldr r6, _080BF51C @ =RNG_0202f388
_080BF4AC:
	ldr r0, _080BF520 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r2, r0, #0
	cmp r2, #0
	beq _080BF4FE
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x2f
	strb r0, [r2, #9]
	mov r1, sl
	ldr r0, [r1]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	strh r7, [r2, #0x20]
	adds r0, r2, #0
	adds r0, #0x22
	strb r7, [r0]
	movs r0, #3
	strb r0, [r2, #0x10]
	strb r4, [r2, #0x12]
	mov r0, r8
	strb r0, [r2, #0x13]
	str r5, [r2, #0x54]
	ldr r1, [r6]
	ldr r0, _080BF524 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080BF528 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsls r0, r0, #3
	lsrs r0, r0, #0x14
	adds r0, r5, r0
	str r0, [r2, #0x54]
	mov r0, sb
	str r0, [r2, #0x58]
_080BF4FE:
	adds r4, #1
	cmp r4, #2
	ble _080BF4AC
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BF514: .4byte 0x0836D9BC
_080BF518: .4byte 0xFFFFF800
_080BF51C: .4byte RNG_0202f388
_080BF520: .4byte gVFXHeaderPtr
_080BF524: .4byte 0x000343FD
_080BF528: .4byte 0x00269EC3

	thumb_func_start FUN_080bf52c
FUN_080bf52c: @ 0x080BF52C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r1
	movs r4, #0
	movs r7, #0
	ldr r1, _080BF5A4 @ =0x0836D9BC
	mov sb, r1
	ldr r1, _080BF5A8 @ =0xFFFFF800
	adds r5, r0, r1
	ldr r6, _080BF5AC @ =RNG_0202f388
_080BF544:
	ldr r0, _080BF5B0 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r2, r0, #0
	cmp r2, #0
	beq _080BF592
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x2f
	strb r0, [r2, #9]
	mov r1, sb
	ldr r0, [r1]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	strh r7, [r2, #0x20]
	adds r0, r2, #0
	adds r0, #0x22
	strb r7, [r0]
	movs r0, #4
	strb r0, [r2, #0x10]
	strb r4, [r2, #0x12]
	str r5, [r2, #0x54]
	ldr r1, [r6]
	ldr r0, _080BF5B4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080BF5B8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsls r0, r0, #3
	lsrs r0, r0, #0x14
	adds r0, r5, r0
	str r0, [r2, #0x54]
	mov r0, r8
	str r0, [r2, #0x58]
_080BF592:
	adds r4, #1
	cmp r4, #5
	ble _080BF544
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BF5A4: .4byte 0x0836D9BC
_080BF5A8: .4byte 0xFFFFF800
_080BF5AC: .4byte RNG_0202f388
_080BF5B0: .4byte gVFXHeaderPtr
_080BF5B4: .4byte 0x000343FD
_080BF5B8: .4byte 0x00269EC3

	thumb_func_start VFX47_Init
VFX47_Init: @ 0x080BF5BC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BF5FC @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080BF600 @ =0x0836F10C
	ldrb r0, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4, #0xd]
	ldrb r0, [r4, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl VFX47_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BF5FC: .4byte gVFXFnTable
_080BF600: .4byte 0x0836F10C

	thumb_func_start VFX47_Update
VFX47_Update: @ 0x080BF604
	push {lr}
	ldr r2, _080BF618 @ =0x0836F0F4
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080BF618: .4byte 0x0836F0F4

	thumb_func_start VFX47_Die
VFX47_Die: @ 0x080BF61C
	ldr r2, _080BF630 @ =gVFXFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_080BF630: .4byte gVFXFnTable

	thumb_func_start FUN_080bf634
FUN_080bf634: @ 0x080BF634
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080BF646
	cmp r0, #1
	beq _080BF696
	b _080BF6CC
_080BF646:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080BF664
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x1a
	strb r0, [r1]
	ldr r1, _080BF660 @ =0x00004B01
	adds r0, r4, #0
	bl SetMotion
	b _080BF690
	.align 2, 0
_080BF660: .4byte 0x00004B01
_080BF664:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x16
	strb r0, [r1]
	movs r1, #0x96
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x46
	bl LoadBlink
_080BF690:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BF696:
	ldr r1, [r5, #0x54]
	ldr r0, _080BF6D4 @ =0xFFFFFD00
	adds r1, r1, r0
	ldrb r2, [r4, #0x12]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #9
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r4, #0x58]
	adds r0, r5, #0
	adds r0, #0xc0
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080BF6C0
	movs r0, #0
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
_080BF6C0:
	movs r0, #0x46
	bl GetBlinkMotionState
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080BF6CC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BF6D4: .4byte 0xFFFFFD00

	thumb_func_start FUN_080bf6d8
FUN_080bf6d8: @ 0x080BF6D8
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, [r4, #0x2c]
	ldrb r0, [r4, #0xe]
	cmp r0, #9
	bls _080BF6E6
	b _080BF886
_080BF6E6:
	lsls r0, r0, #2
	ldr r1, _080BF6F0 @ =_080BF6F4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080BF6F0: .4byte _080BF6F4
_080BF6F4: @ jump table
	.4byte _080BF71C @ case 0
	.4byte _080BF75E @ case 1
	.4byte _080BF78C @ case 2
	.4byte _080BF79E @ case 3
	.4byte _080BF7B0 @ case 4
	.4byte _080BF7BA @ case 5
	.4byte _080BF7D8 @ case 6
	.4byte _080BF7EE @ case 7
	.4byte _080BF83A @ case 8
	.4byte _080BF844 @ case 9
_080BF71C:
	movs r0, #0x80
	bl PlaySound
	movs r0, #0x46
	bl ClearBlink
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x47
	bl LoadBlink
	ldr r1, [r4, #0x54]
	ldr r0, _080BF788 @ =0xFFFFF600
	adds r1, r1, r0
	ldrb r2, [r4, #0x12]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #0xa
	adds r1, r1, r0
	str r1, [r4, #0x54]
	movs r0, #6
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BF75E:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BF770
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BF770:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080BF82C
	ldrb r0, [r4, #0x13]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080BF82C
	adds r0, r4, #0
	bl FUN_080bf390
	b _080BF82C
	.align 2, 0
_080BF788: .4byte 0xFFFFF600
_080BF78C:
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #7
	subs r0, #0x40
	str r0, [r4, #0x5c]
	movs r0, #0x30
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BF79E:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080BF812
	ldrb r0, [r4, #0x13]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080BF812
	b _080BF80C
_080BF7B0:
	movs r0, #0x50
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BF7BA:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080BF7D0
	ldrb r0, [r4, #0x13]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080BF7D0
	adds r0, r4, #0
	bl FUN_080bf390
_080BF7D0:
	ldr r0, [r4, #0x58]
	subs r0, #0xc0
	str r0, [r4, #0x58]
	b _080BF81A
_080BF7D8:
	movs r1, #0x75
	ldrb r2, [r4, #0x12]
	movs r0, #0xea
	muls r0, r2, r0
	subs r1, r1, r0
	str r1, [r4, #0x5c]
	movs r0, #0x30
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BF7EE:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080BF812
	ldrb r0, [r4, #0x13]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080BF812
	ldr r0, [r4, #0x54]
	ldr r1, [r3, #0x54]
	subs r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	ble _080BF812
_080BF80C:
	adds r0, r4, #0
	bl FUN_080bf390
_080BF812:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_080BF81A:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BF82C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BF82C:
	movs r0, #0x47
	bl GetBlinkMotionState
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080BF886
_080BF83A:
	movs r0, #0x50
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BF844:
	movs r0, #0x47
	bl GetBlinkMotionState
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x58]
	subs r0, #0xc0
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BF886
	movs r0, #0x47
	bl ClearBlink
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080BF88C @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080BF886:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BF88C: .4byte gVFXFnTable

	thumb_func_start FUN_080bf890
FUN_080bf890: @ 0x080BF890
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, [r7, #0x28]
	str r0, [sp]
	ldr r1, [r7, #0x2c]
	mov sl, r1
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _080BF8B2
	cmp r0, #1
	beq _080BF960
	b _080BF9FA
_080BF8B2:
	str r0, [r7, #0x64]
	ldr r0, _080BF900 @ =0xFFFFE800
	mov sb, r0
	str r0, [r7, #0x68]
	ldr r4, _080BF904 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _080BF908 @ =0x000343FD
	mov r8, r1
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r6, _080BF90C @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #6
	bl __umodsi3
	add r0, sb
	str r0, [r7, #0x68]
	mov r0, r8
	muls r0, r5, r0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	adds r6, r4, #0
	cmp r0, #0
	beq _080BF910
	adds r1, r7, #0
	adds r1, #0x25
	movs r0, #0x17
	b _080BF916
	.align 2, 0
_080BF900: .4byte 0xFFFFE800
_080BF904: .4byte RNG_0202f388
_080BF908: .4byte 0x000343FD
_080BF90C: .4byte 0x00269EC3
_080BF910:
	adds r1, r7, #0
	adds r1, #0x25
	movs r0, #0x19
_080BF916:
	strb r0, [r1]
	ldr r0, [r6]
	ldr r4, _080BF974 @ =0x000343FD
	adds r2, r0, #0
	muls r2, r4, r2
	ldr r3, _080BF978 @ =0x00269EC3
	adds r2, r2, r3
	lsls r2, r2, #1
	lsrs r1, r2, #1
	lsrs r2, r2, #0x11
	movs r0, #1
	ands r2, r0
	strb r2, [r7, #0x13]
	ldr r5, _080BF97C @ =0xFFFFFE00
	adds r0, r1, #0
	muls r0, r4, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsls r0, r0, #6
	lsrs r0, r0, #0x17
	subs r0, r5, r0
	str r0, [r7, #0x5c]
	cmp r2, #0
	beq _080BF94E
	rsbs r0, r0, #0
	str r0, [r7, #0x5c]
_080BF94E:
	movs r0, #0
	strb r0, [r7, #0x12]
	ldr r1, _080BF980 @ =0x00004B04
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080BF960:
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080BF984
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080BF98A
	.align 2, 0
_080BF974: .4byte 0x000343FD
_080BF978: .4byte 0x00269EC3
_080BF97C: .4byte 0xFFFFFE00
_080BF980: .4byte 0x00004B04
_080BF984:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080BF98A:
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	bne _080BF9BA
	ldr r0, [r7, #0x64]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x64]
	ldr r1, [sp]
	ldr r2, [r1, #0x54]
	adds r2, r2, r0
	str r2, [r7, #0x54]
	ldr r0, [r1, #0x58]
	ldr r1, [r7, #0x68]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	mov r1, sl
	ldr r0, [r1, #0x54]
	cmp r2, r0
	bge _080BF9FA
	b _080BF9DA
_080BF9BA:
	ldr r0, [r7, #0x64]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x64]
	mov r1, sl
	ldr r2, [r1, #0x54]
	adds r2, r2, r0
	str r2, [r7, #0x54]
	ldr r0, [r1, #0x58]
	ldr r1, [r7, #0x68]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r1, [sp]
	ldr r0, [r1, #0x54]
	cmp r2, r0
	ble _080BF9FA
_080BF9DA:
	str r0, [r7, #0x54]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080BFA0C @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r7, #0x14]
_080BF9FA:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BFA0C: .4byte gVFXFnTable

	thumb_func_start FUN_080bfa10
FUN_080bfa10: @ 0x080BFA10
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080BFA20
	cmp r0, #1
	beq _080BFA44
	b _080BFA70
_080BFA20:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080BFA34
	ldr r1, _080BFA30 @ =0x00004A01
	adds r0, r4, #0
	bl SetMotion
	b _080BFA3E
	.align 2, 0
_080BFA30: .4byte 0x00004A01
_080BFA34:
	movs r1, #0x94
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
_080BFA3E:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BFA44:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r2, [r0]
	cmp r2, #3
	bne _080BFA70
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080BFA78 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080BFA70:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BFA78: .4byte gVFXFnTable

	thumb_func_start FUN_080bfa7c
FUN_080bfa7c: @ 0x080BFA7C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080BFA8C
	cmp r5, #1
	beq _080BFADC
	b _080BFB4A
_080BFA8C:
	adds r2, r4, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _080BFAB4 @ =0x0836F112
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _080BFAB8
	str r5, [r4, #0x60]
	b _080BFAD6
	.align 2, 0
_080BFAB4: .4byte 0x0836F112
_080BFAB8:
	ldr r2, _080BFB18 @ =0xFFFFFB80
	ldr r3, _080BFB1C @ =RNG_0202f388
	ldr r1, [r3]
	ldr r0, _080BFB20 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080BFB24 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsrs r0, r0, #0x11
	movs r1, #0xff
	ands r0, r1
	subs r2, r2, r0
	str r2, [r4, #0x60]
_080BFAD6:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BFADC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080BFAF2
	str r1, [r4, #0x60]
_080BFAF2:
	ldr r0, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r0, r2
	str r1, [r4, #0x58]
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _080BFB28
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080BFB4A
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #1
	bl FUN_080bf438
	b _080BFB2C
	.align 2, 0
_080BFB18: .4byte 0xFFFFFB80
_080BFB1C: .4byte RNG_0202f388
_080BFB20: .4byte 0x000343FD
_080BFB24: .4byte 0x00269EC3
_080BFB28:
	cmp r2, #0
	ble _080BFB4A
_080BFB2C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080BFB50 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080BFB4A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BFB50: .4byte gVFXFnTable

	thumb_func_start FUN_080bfb54
FUN_080bfb54: @ 0x080BFB54
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r6, [r7, #0xe]
	cmp r6, #0
	beq _080BFB64
	cmp r6, #1
	beq _080BFBEA
	b _080BFC88
_080BFB64:
	adds r0, r7, #0
	bl InitRotatableMotion
	ldr r0, _080BFC00 @ =0x00004C05
	adds r1, r0, #0
	ldrb r2, [r7, #0x12]
	adds r1, r1, r2
	adds r0, r7, #0
	bl SetMotion
	ldrb r1, [r7, #0x12]
	lsls r1, r1, #7
	ldr r0, _080BFC04 @ =0xFFFFFE00
	adds r1, r1, r0
	ldr r2, _080BFC08 @ =RNG_0202f388
	mov ip, r2
	ldr r0, [r2]
	ldr r3, _080BFC0C @ =0x000343FD
	muls r0, r3, r0
	ldr r2, _080BFC10 @ =0x00269EC3
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r4, r0, #1
	lsrs r0, r0, #0x11
	movs r5, #0xff
	ands r0, r5
	adds r1, r1, r0
	str r1, [r7, #0x5c]
	ldr r1, _080BFC14 @ =0xFFFFFC80
	adds r0, r4, #0
	muls r0, r3, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r4, r0, #1
	lsrs r0, r0, #0x11
	ands r0, r5
	subs r1, r1, r0
	str r1, [r7, #0x60]
	strb r6, [r7, #0x13]
	adds r0, r4, #0
	muls r0, r3, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r2, ip
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #3
	bl __umodsi3
	adds r4, r0, #0
	adds r4, #1
	str r4, [r7, #0x64]
	ldrb r0, [r7, #0x12]
	movs r1, #3
	bl __udivsi3
	movs r1, #1
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	muls r0, r4, r0
	subs r4, r4, r0
	str r4, [r7, #0x64]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080BFBEA:
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080BFC18
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080BFC1E
	.align 2, 0
_080BFC00: .4byte 0x00004C05
_080BFC04: .4byte 0xFFFFFE00
_080BFC08: .4byte RNG_0202f388
_080BFC0C: .4byte 0x000343FD
_080BFC10: .4byte 0x00269EC3
_080BFC14: .4byte 0xFFFFFC80
_080BFC18:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080BFC1E:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x60]
	adds r0, #0x40
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080BFC38
	str r1, [r7, #0x60]
_080BFC38:
	ldr r1, [r7, #0x58]
	ldr r0, [r7, #0x60]
	adds r1, r1, r0
	str r1, [r7, #0x58]
	ldr r0, [r7, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080BFC74
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	movs r2, #1
	bl FUN_080bf438
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080BFC90 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r7, #0x14]
_080BFC74:
	ldr r0, [r7, #0x64]
	ldrb r1, [r7, #0x13]
	adds r1, r1, r0
	strb r1, [r7, #0x13]
	adds r0, r7, #0
	adds r0, #0x24
	strb r1, [r0]
	adds r0, r7, #0
	bl UpdateMotionGraphic
_080BFC88:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BFC90: .4byte gVFXFnTable
