	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08071470
FUN_08071470: @ 0x08071470
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r4, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, [sp, #0x18]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _080714E0 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r2, r0, #0
	cmp r2, #0
	beq _080714FA
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #0
	mov ip, r0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _080714E4 @ =gEnemyFnTable
	movs r0, #0x11
	strb r0, [r2, #9]
	ldr r0, [r1, #0x44]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	movs r3, #0
	mov r1, ip
	strh r1, [r2, #0x20]
	adds r0, r2, #0
	adds r0, #0x22
	strb r3, [r0]
	ldrb r1, [r2, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r2, #0xb]
	ldrb r0, [r2, #0x1c]
	strb r0, [r2, #0x1d]
	strb r3, [r2, #0x10]
	strb r5, [r2, #0x11]
	str r6, [r2, #0x54]
	str r7, [r2, #0x58]
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _080714E8
	mov r0, ip
	str r0, [r2, #0x2c]
	adds r1, r2, #0
	adds r1, #0xb8
	movs r0, #1
	strb r0, [r1]
	b _080714F2
	.align 2, 0
_080714E0: .4byte gZakoHeaderPtr
_080714E4: .4byte gEnemyFnTable
_080714E8:
	str r4, [r2, #0x2c]
	adds r0, r2, #0
	adds r0, #0xb8
	strb r3, [r0]
	str r2, [r4, #0x2c]
_080714F2:
	adds r0, r2, #0
	adds r0, #0xb4
	mov r1, r8
	str r1, [r0]
_080714FA:
	adds r0, r2, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08071508
FUN_08071508: @ 0x08071508
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r0, _08071560 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _08071558
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _08071564 @ =gEnemyFnTable
	movs r0, #0x11
	strb r0, [r3, #9]
	ldr r0, [r1, #0x44]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	movs r0, #1
	strb r0, [r3, #0x10]
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
	adds r0, r3, #0
	adds r0, #0xb4
	str r6, [r0]
_08071558:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08071560: .4byte gZakoHeaderPtr
_08071564: .4byte gEnemyFnTable

	thumb_func_start nop_08071568
nop_08071568: @ 0x08071568
	bx lr
	.align 2, 0

	thumb_func_start FUN_0807156c
FUN_0807156c: @ 0x0807156C
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08071582
	movs r0, #0
	b _080715A0
_08071582:
	ldr r1, _080715A4 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldrb r0, [r2, #0x10]
	strb r0, [r2, #0xd]
	adds r0, r2, #0
	bl CarryArm_Die
	movs r0, #1
_080715A0:
	pop {r1}
	bx r1
	.align 2, 0
_080715A4: .4byte gEnemyFnTable

	thumb_func_start CarryArm_Init
CarryArm_Init: @ 0x080715A8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _08071614 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _08071618 @ =0x08366BB0
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r6, #0
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r0, [r5, #0x10]
	cmp r0, #1
	bne _08071620
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0807161C @ =0x08366B98
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #2
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	str r6, [r5, #0x28]
	str r6, [r5, #0x2c]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
	b _08071640
	.align 2, 0
_08071614: .4byte gEnemyFnTable
_08071618: .4byte 0x08366BB0
_0807161C: .4byte 0x08366B98
_08071620:
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0807164C @ =0x08366B80
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #2
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _08071650 @ =nop_08071568
	str r0, [r4, #0x24]
_08071640:
	adds r0, r5, #0
	bl CarryArm_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807164C: .4byte 0x08366B80
_08071650: .4byte nop_08071568

	thumb_func_start CarryArm_Update
CarryArm_Update: @ 0x08071654
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0807156c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08071682
	ldr r1, _08071688 @ =0x08366B48
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0807168C @ =0x08366B60
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_08071682:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08071688: .4byte 0x08366B48
_0807168C: .4byte 0x08366B60

	thumb_func_start CarryArm_Die
CarryArm_Die: @ 0x08071690
	push {lr}
	ldr r2, _080716A4 @ =0x08366B78
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080716A4: .4byte 0x08366B78

	thumb_func_start FUN_080716a8
FUN_080716a8: @ 0x080716A8
	bx lr
	.align 2, 0

	thumb_func_start FUN_080716ac
FUN_080716ac: @ 0x080716AC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080716BC
	cmp r0, #1
	beq _0807173C
	b _0807176C
_080716BC:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x17
	strb r0, [r1]
	movs r2, #0xc0
	lsls r2, r2, #6
	ldrb r1, [r4, #0x11]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0xd
	subs r2, r2, r0
	str r2, [r4, #0x5c]
	cmp r2, #0
	bge _080716DA
	adds r2, #0xf
_080716DA:
	asrs r2, r2, #4
	str r2, [r4, #0x5c]
	movs r1, #0x20
	rsbs r1, r1, #0
	str r1, [r4, #0x68]
	movs r0, #0x80
	lsls r0, r0, #1
	lsls r1, r1, #3
	subs r0, r0, r1
	str r0, [r4, #0x60]
	movs r1, #0
	cmp r2, #0
	ble _080716F6
	movs r1, #1
_080716F6:
	adds r2, r1, #0
	cmp r2, #0
	beq _08071704
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0807170A
_08071704:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0807170A:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
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
	movs r0, #0x10
	strb r0, [r4, #0x12]
	ldr r1, _08071774 @ =0x00002201
	adds r0, r4, #0
	movs r2, #6
	movs r3, #3
	bl GotoMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807173C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x60]
	ldr r0, [r4, #0x68]
	adds r1, r1, r0
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08071766
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08071766:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0807176C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08071774: .4byte 0x00002201

	thumb_func_start FUN_08071778
FUN_08071778: @ 0x08071778
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r4, [r3, #0x2c]
	cmp r4, #0
	beq _0807178C
	ldrb r0, [r4, #0xc]
	cmp r0, #1
	bls _0807178C
	movs r4, #0
	str r4, [r3, #0x2c]
_0807178C:
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	beq _08071798
	cmp r0, #1
	beq _080717BE
	b _08071882
_08071798:
	strb r0, [r3, #0x12]
	ldr r2, _08071808 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0807180C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08071810 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #6
	adds r0, #0x20
	strb r0, [r3, #0x13]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_080717BE:
	ldr r5, _08071814 @ =gSineTable
	ldrb r2, [r3, #0x12]
	lsls r0, r2, #0x19
	movs r1, #0x80
	lsls r1, r1, #0x17
	adds r0, r0, r1
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #2
	str r1, [r3, #0x5c]
	ldrb r0, [r3, #0x11]
	cmp r0, #1
	bne _080717E0
	rsbs r0, r1, #0
	str r0, [r3, #0x5c]
_080717E0:
	lsls r0, r2, #0x19
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	str r0, [r3, #0x60]
	movs r1, #0
	ldr r0, [r3, #0x5c]
	cmp r0, #0
	ble _080717F8
	movs r1, #1
_080717F8:
	adds r2, r1, #0
	cmp r2, #0
	beq _08071818
	ldrb r1, [r3, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0807181E
	.align 2, 0
_08071808: .4byte RNG_0202f388
_0807180C: .4byte 0x000343FD
_08071810: .4byte 0x00269EC3
_08071814: .4byte gSineTable
_08071818:
	ldrb r1, [r3, #0xa]
	movs r0, #0xef
	ands r0, r1
_0807181E:
	strb r0, [r3, #0xa]
	adds r1, r2, #0
	adds r0, r3, #0
	adds r0, #0x4c
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r3
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	ldr r0, [r3, #0x54]
	ldr r1, [r3, #0x5c]
	adds r0, r0, r1
	str r0, [r3, #0x54]
	ldr r0, [r3, #0x58]
	ldr r1, [r3, #0x60]
	adds r0, r0, r1
	str r0, [r3, #0x58]
	ldrb r0, [r3, #0x12]
	adds r0, #1
	strb r0, [r3, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r3, #0x13]
	cmp r0, r1
	blo _0807187C
	adds r0, r3, #0
	adds r0, #0xb8
	ldrb r1, [r0]
	cmp r1, #0
	bne _0807186C
	cmp r4, #0
	bne _08071876
_0807186C:
	movs r0, #5
	strb r0, [r3, #0xd]
	movs r0, #0
	strb r0, [r3, #0xe]
	b _0807187C
_08071876:
	movs r0, #2
	strb r0, [r3, #0xd]
	strb r1, [r3, #0xe]
_0807187C:
	adds r0, r3, #0
	bl UpdateMotionGraphic
_08071882:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08071888
FUN_08071888: @ 0x08071888
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x2c]
	cmp r6, #0
	beq _080718A8
	ldrb r0, [r6, #0xc]
	cmp r0, #1
	bls _080718A8
	movs r6, #0
	str r6, [r5, #0x2c]
	movs r0, #5
	strb r0, [r5, #0xd]
	strb r6, [r5, #0xe]
	adds r0, r5, #0
	bl FUN_08071b88
_080718A8:
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _080718B4
	cmp r0, #1
	beq _0807192C
	b _0807195C
_080718B4:
	ldr r0, [r6, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	str r0, [r5, #0x5c]
	movs r1, #0x28
	bl __divsi3
	adds r4, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0x20
	rsbs r0, r0, #0
	str r0, [r5, #0x68]
	ldr r0, [r6, #0x58]
	ldr r1, _080718FC @ =0xFFFFDE00
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	subs r0, r0, r1
	str r0, [r5, #0x60]
	movs r1, #0x28
	bl __divsi3
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r0, r1
	str r0, [r5, #0x60]
	movs r1, #0
	cmp r4, #0
	ble _080718EE
	movs r1, #1
_080718EE:
	adds r2, r1, #0
	cmp r2, #0
	beq _08071900
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08071906
	.align 2, 0
_080718FC: .4byte 0xFFFFDE00
_08071900:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_08071906:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r0, #0x28
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807192C:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x60]
	ldr r0, [r5, #0x68]
	adds r1, r1, r0
	str r1, [r5, #0x60]
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08071956
	movs r0, #4
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_08071956:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_0807195C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08071964
FUN_08071964: @ 0x08071964
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x2c]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _08071974
	movs r0, #0
	str r0, [r4, #0x2c]
_08071974:
	ldr r5, [r4, #0x28]
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _08071982
	movs r0, #0
	str r0, [r4, #0x28]
	movs r5, #0
_08071982:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r7, [r0]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08071994
	cmp r0, #1
	beq _080719AA
	b _08071A20
_08071994:
	strb r0, [r4, #0x12]
	strb r0, [r4, #0x13]
	str r0, [r4, #0x60]
	movs r1, #0x8c
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080719AA:
	cmp r5, #0
	bne _08071A10
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080719BE
	str r1, [r4, #0x60]
_080719BE:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r6, r0, #0
	cmp r6, #0
	bge _080719EC
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _080719E2
	movs r0, #0x91
	bl PlaySound
	movs r0, #1
	strb r0, [r4, #0x12]
_080719E2:
	str r5, [r4, #0x60]
	ldr r0, [r4, #0x58]
	adds r0, r0, r6
	str r0, [r4, #0x58]
	b _08071A1A
_080719EC:
	strb r5, [r4, #0x12]
	adds r0, r7, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	bne _08071A1A
	ldrb r0, [r4, #0x13]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08071A08
	ldr r0, [r7, #0x20]
	adds r0, #4
	str r0, [r7, #0x20]
_08071A08:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	b _08071A1A
_08071A10:
	movs r1, #0
	strb r1, [r4, #0x12]
	movs r0, #4
	strb r0, [r4, #0x13]
	str r1, [r4, #0x60]
_08071A1A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08071A20:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08071a28
FUN_08071a28: @ 0x08071A28
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r5, [r4, #0x2c]
	cmp r5, #0
	beq _08071A78
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _08071A78
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08071A74 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _08071B6A
	.align 2, 0
_08071A74: .4byte gEnemyFnTable
_08071A78:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08071A84
	cmp r0, #1
	beq _08071ABE
	b _08071B6A
_08071A84:
	movs r0, #0x34
	bl PlaySound
	cmp r5, #0
	beq _08071AB8
	ldr r0, [r5, #0x28]
	cmp r0, #0
	bne _08071AB4
	ldr r0, [r5, #0x58]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	ldr r1, _08071AB0 @ =0x000027FF
	cmp r0, r1
	bgt _08071AB4
	str r4, [r5, #0x28]
	movs r1, #0x88
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	b _08071AB8
	.align 2, 0
_08071AB0: .4byte 0x000027FF
_08071AB4:
	movs r5, #0
	str r5, [r4, #0x2c]
_08071AB8:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08071ABE:
	ldr r0, [r4, #0x58]
	ldr r1, _08071B74 @ =0xFFFFFEC0
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r1, [r4, #0x54]
	ldr r0, _08071B78 @ =0x00267FFF
	cmp r1, r0
	bgt _08071AD2
	adds r0, #1
	str r0, [r4, #0x54]
_08071AD2:
	ldr r0, [r4, #0x54]
	ldr r1, _08071B7C @ =0x00275000
	cmp r0, r1
	ble _08071ADC
	str r1, [r4, #0x54]
_08071ADC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	cmp r5, #0
	beq _08071AF4
	ldr r0, [r4, #0x54]
	str r0, [r5, #0x54]
	ldr r0, [r4, #0x58]
	movs r1, #0x88
	lsls r1, r1, #6
	adds r0, r0, r1
	str r0, [r5, #0x58]
_08071AF4:
	ldr r1, [r4, #0x58]
	ldr r0, _08071B80 @ =0x00019FFF
	cmp r1, r0
	bgt _08071B6A
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	mov r8, r0
	ands r0, r1
	movs r2, #0
	movs r6, #0xfd
	ands r0, r6
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r7, #0xfb
	adds r0, r7, #0
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08071B84 @ =gEnemyFnTable
	mov ip, r1
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	add r0, ip
	movs r3, #3
	str r3, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	cmp r5, #0
	beq _08071B6A
	ldrb r1, [r5, #0xa]
	mov r0, r8
	ands r0, r1
	ands r0, r6
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	adds r0, r7, #0
	ands r0, r1
	strb r0, [r5, #0xa]
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	add r0, ip
	str r3, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_08071B6A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08071B74: .4byte 0xFFFFFEC0
_08071B78: .4byte 0x00267FFF
_08071B7C: .4byte 0x00275000
_08071B80: .4byte 0x00019FFF
_08071B84: .4byte gEnemyFnTable

	thumb_func_start FUN_08071b88
FUN_08071b88: @ 0x08071B88
	push {lr}
	adds r3, r0, #0
	ldr r2, [r3, #0x60]
	subs r2, #0x10
	str r2, [r3, #0x60]
	ldr r0, [r3, #0x54]
	ldr r1, [r3, #0x5c]
	adds r0, r0, r1
	str r0, [r3, #0x54]
	ldr r0, [r3, #0x58]
	adds r0, r0, r2
	str r0, [r3, #0x58]
	ldr r1, _08071BE8 @ =0x00019FFF
	cmp r0, r1
	bgt _08071BDC
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _08071BEC @ =gEnemyFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
_08071BDC:
	adds r0, r3, #0
	bl UpdateMotionGraphic
	pop {r0}
	bx r0
	.align 2, 0
_08071BE8: .4byte 0x00019FFF
_08071BEC: .4byte gEnemyFnTable

	thumb_func_start FUN_08071bf0
FUN_08071bf0: @ 0x08071BF0
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08071C64 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _08071C68 @ =0x08366BB2
	adds r0, r4, #0
	mov r1, sp
	movs r3, #4
	bl FUN_080b7f70
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	bne _08071C48
	ldr r0, [r1, #0x20]
	adds r0, #5
	str r0, [r1, #0x20]
_08071C48:
	ldr r1, _08071C6C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08071C64: .4byte 0xFFFFF000
_08071C68: .4byte 0x08366BB2
_08071C6C: .4byte gEnemyFnTable

	thumb_func_start FUN_08071c70
FUN_08071c70: @ 0x08071C70
	ldr r2, _08071C84 @ =gEnemyFnTable
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
_08071C84: .4byte gEnemyFnTable
