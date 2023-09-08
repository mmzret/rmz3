	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start createCubit
createCubit: @ 0x080525B0
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _08052604 @ =gBossHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080525FC
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _08052608 @ =gBossFnTable
	movs r0, #0xd
	strb r0, [r3, #9]
	ldr r0, [r1, #0x34]
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
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	strb r4, [r3, #0x10]
_080525FC:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08052604: .4byte gBossHeaderPtr
_08052608: .4byte gBossFnTable

	thumb_func_start Cubit_Init
Cubit_Init: @ 0x0805260C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	bl InitNonAffineMotion
	adds r0, r6, #0
	bl ResetDynamicMotion
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r7, #0
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r7, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080526FC @ =0x083639D8
	adds r0, r6, #0
	movs r2, #0x40
	bl resetBossData
	ldr r1, _08052700 @ =FUN_08054530
	adds r0, r6, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	adds r0, #0x40
	strb r7, [r0]
	adds r1, r6, #0
	adds r1, #0xb5
	movs r0, #0xff
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xc0
	str r7, [r0]
	subs r0, #9
	strb r7, [r0]
	adds r0, #0x11
	strb r7, [r0]
	adds r0, #4
	str r7, [r0]
	ldr r1, [r6, #0x58]
	ldr r0, _08052704 @ =0xFFFFC000
	adds r1, r1, r0
	ldr r0, [r6, #0x54]
	bl FUN_08009f6c
	adds r4, r0, #0
	str r4, [r6, #0x58]
	adds r1, r6, #0
	adds r1, #0xb8
	ldr r2, _08052708 @ =0xFFFF8400
	adds r0, r4, r2
	str r0, [r1]
	ldr r0, [r6, #0x54]
	ldr r1, _0805270C @ =0xFFFF8C00
	adds r4, r4, r1
	adds r1, r4, #0
	bl FUN_0800a22c
	adds r5, r0, #0
	ldr r0, [r6, #0x54]
	adds r1, r4, #0
	bl FUN_0800a31c
	adds r4, r0, #0
	adds r0, r6, #0
	adds r0, #0xbc
	str r4, [r0]
	subs r5, r5, r4
	adds r0, r5, #0
	movs r1, #3
	bl __divsi3
	adds r2, r6, #0
	adds r2, #0xd4
	asrs r1, r0, #1
	adds r4, r4, r1
	str r4, [r2]
	adds r2, #4
	adds r1, r4, r0
	str r1, [r2]
	adds r2, #4
	lsls r1, r0, #1
	adds r4, r4, r1
	str r4, [r2]
	adds r1, r6, #0
	adds r1, #0xe0
	str r0, [r1]
	adds r0, r6, #0
	adds r0, #0xca
	strb r7, [r0]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _08052714
	ldr r1, _08052710 @ =gBossFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r7, [r6, #0xd]
	b _0805272A
	.align 2, 0
_080526FC: .4byte 0x083639D8
_08052700: .4byte FUN_08054530
_08052704: .4byte 0xFFFFC000
_08052708: .4byte 0xFFFF8400
_0805270C: .4byte 0xFFFF8C00
_08052710: .4byte gBossFnTable
_08052714:
	ldr r1, _08052740 @ =gBossFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #3
	strb r0, [r6, #0xd]
_0805272A:
	strb r7, [r6, #0xe]
	strb r7, [r6, #0xf]
	movs r0, #0
	strb r0, [r6, #0x11]
	adds r0, r6, #0
	bl Cubit_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08052740: .4byte gBossFnTable

	thumb_func_start Cubit_Update
Cubit_Update: @ 0x08052744
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x8c
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08052764
	adds r0, r4, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _080527AE
_08052764:
	ldr r0, _0805279C @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080527AE
	ldr r1, _080527A0 @ =gBossFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r0, #0xd2
	bl PlaySound
	ldr r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r1, r0
	cmp r1, #0
	beq _080527A4
	movs r0, #1
	strb r0, [r4, #0xf]
	b _080527A6
	.align 2, 0
_0805279C: .4byte gStageRun
_080527A0: .4byte gBossFnTable
_080527A4:
	strb r1, [r4, #0xf]
_080527A6:
	adds r0, r4, #0
	bl Cubit_Die
	b _080527D4
_080527AE:
	ldr r1, _080527DC @ =0x08363970
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080527E0 @ =0x083639A0
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl cubit_080544c0
_080527D4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080527DC: .4byte 0x08363970
_080527E0: .4byte 0x083639A0

	thumb_func_start Cubit_Die
Cubit_Die: @ 0x080527E4
	push {lr}
	ldr r2, _080527F8 @ =0x083639D0
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080527F8: .4byte 0x083639D0

	thumb_func_start cubitDeath0
cubitDeath0: @ 0x080527FC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	beq _08052892
	cmp r0, #1
	bgt _08052810
	cmp r0, #0
	beq _08052816
	b _080528C0
_08052810:
	cmp r0, #2
	beq _080528B8
	b _080528C0
_08052816:
	ldr r3, _080528AC @ =gStageRun
	ldrh r2, [r3, #8]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r2
	cmp r0, #0
	beq _08052838
	ldrb r1, [r3, #0x12]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _08052838
	ldr r0, _080528B0 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_08052838:
	adds r0, r6, #0
	bl InitNonAffineMotion
	adds r0, r6, #0
	bl ResetDynamicMotion
	adds r0, r6, #0
	adds r0, #0x24
	movs r4, #0
	strb r4, [r0]
	adds r1, r6, #0
	adds r1, #0x50
	movs r5, #0
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	ldr r1, _080528B4 @ =0x0000B01E
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x5c
	str r4, [r0, #4]
	str r4, [r6, #0x5c]
	movs r0, #1
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08052892:
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _080528C0
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080528C0
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _080528C0
	.align 2, 0
_080528AC: .4byte gStageRun
_080528B0: .4byte 0x0000FFFE
_080528B4: .4byte 0x0000B01E
_080528B8:
	movs r1, #0
	movs r0, #1
	strb r0, [r6, #0xd]
	strb r1, [r6, #0xe]
_080528C0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start cubitDeath1
cubitDeath1: @ 0x080528C8
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0x19
	bls _080528D6
	b _08052B3C
_080528D6:
	lsls r0, r0, #2
	ldr r1, _080528E0 @ =_080528E4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080528E0: .4byte _080528E4
_080528E4: @ jump table
	.4byte _0805294C @ case 0
	.4byte _080529BA @ case 1
	.4byte _080529CC @ case 2
	.4byte _08052A3E @ case 3
	.4byte _08052A70 @ case 4
	.4byte _08052B3C @ case 5
	.4byte _08052B3C @ case 6
	.4byte _08052B3C @ case 7
	.4byte _08052B3C @ case 8
	.4byte _08052B3C @ case 9
	.4byte _080529BA @ case 10
	.4byte _08052A86 @ case 11
	.4byte _08052B3C @ case 12
	.4byte _08052B3C @ case 13
	.4byte _08052B3C @ case 14
	.4byte _08052B3C @ case 15
	.4byte _08052B3C @ case 16
	.4byte _08052B3C @ case 17
	.4byte _08052B3C @ case 18
	.4byte _08052B3C @ case 19
	.4byte _08052A98 @ case 20
	.4byte _08052AA2 @ case 21
	.4byte _08052AB0 @ case 22
	.4byte _08052AF8 @ case 23
	.4byte _08052B10 @ case 24
	.4byte _08052B24 @ case 25
_0805294C:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x50
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	ldr r1, _080529C4 @ =0x0000B01E
	adds r0, r4, #0
	bl SetMotion
	adds r2, r4, #0
	adds r2, #0x8c
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08052986
	adds r0, r4, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _08052998
_08052986:
	ldr r0, _080529C8 @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08052998
	ldrb r0, [r4, #0xf]
	cmp r0, #1
	beq _0805299A
_08052998:
	movs r0, #0xa
_0805299A:
	strb r0, [r4, #0xe]
	movs r1, #0
	str r1, [r2]
	adds r0, r4, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r2, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x5c
	str r1, [r0, #4]
	str r1, [r4, #0x5c]
_080529BA:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08052B04
	.align 2, 0
_080529C4: .4byte 0x0000B01E
_080529C8: .4byte gStageRun
_080529CC:
	movs r0, #0
	str r0, [r4, #0x60]
	ldr r2, [r4, #0x54]
	str r2, [sp]
	ldr r3, [r4, #0x58]
	str r3, [sp, #4]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080529E4
	str r2, [sp]
_080529E4:
	ldr r1, _08052A04 @ =0xFFFFDF00
	adds r0, r3, r1
	str r0, [sp, #4]
	ldrb r0, [r4, #0x11]
	cmp r0, #0xff
	beq _08052A12
	cmp r0, #0xfe
	bne _08052A08
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
	b _08052A36
	.align 2, 0
_08052A04: .4byte 0xFFFFDF00
_08052A08:
	ldr r0, _08052A24 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	cmp r0, r2
	ble _08052A28
_08052A12:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #1
	bl FUN_080b2b40
	b _08052A36
	.align 2, 0
_08052A24: .4byte pZero2
_08052A28:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
_08052A36:
	movs r0, #0x2f
	bl PlaySound
	b _08052B04
_08052A3E:
	adds r1, r4, #0
	adds r1, #0x54
	ldr r2, _08052A68 @ =0x0000B01C
	ldrb r3, [r4, #0xa]
	lsrs r3, r3, #4
	movs r0, #1
	ands r3, r0
	adds r0, r4, #0
	bl FUN_0809c3b4
	ldr r1, _08052A6C @ =0x0000B01D
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r0, #0x44
	strb r0, [r4, #0x12]
	b _08052B04
	.align 2, 0
_08052A68: .4byte 0x0000B01C
_08052A6C: .4byte 0x0000B01D
_08052A70:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08052A86
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08052B3C
_08052A86:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08052B3C
	movs r0, #0x14
	strb r0, [r4, #0xe]
	b _08052B3C
_08052A98:
	movs r0, #0x50
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08052AA2:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08052B3C
	b _08052B04
_08052AB0:
	ldrb r0, [r4, #0xf]
	cmp r0, #1
	bne _08052AD0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08052AC8
	ldr r1, _08052AC4 @ =0x08363A88
	b _08052AE6
	.align 2, 0
_08052AC4: .4byte 0x08363A88
_08052AC8:
	ldr r1, _08052ACC @ =0x08363A90
	b _08052AE6
	.align 2, 0
_08052ACC: .4byte 0x08363A90
_08052AD0:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08052AE4
	ldr r1, _08052AE0 @ =0x08363A78
	b _08052AE6
	.align 2, 0
_08052AE0: .4byte 0x08363A78
_08052AE4:
	ldr r1, _08052B0C @ =0x08363A80
_08052AE6:
	adds r0, r4, #0
	bl CreateBossExplosion
	adds r1, r4, #0
	adds r1, #0xc0
	str r0, [r1]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08052AF8:
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r0, [r0]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _08052B3C
_08052B04:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08052B3C
	.align 2, 0
_08052B0C: .4byte 0x08363A80
_08052B10:
	movs r0, #0x30
	strb r0, [r4, #0x12]
	ldr r2, _08052B44 @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08052B24:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08052B34
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08052B3C
_08052B34:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
_08052B3C:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08052B44: .4byte gStageRun

	thumb_func_start FUN_08052b48
FUN_08052b48: @ 0x08052B48
	movs r0, #1
	bx lr

	thumb_func_start cubitMode0
cubitMode0: @ 0x08052B4C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08052B5C
	cmp r0, #1
	beq _08052B72
	b _08052B8C
_08052B5C:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08052B94 @ =0x0000B002
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08052B72:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08052B8C
	movs r0, #0
	strb r2, [r4, #0xd]
	strb r0, [r4, #0xe]
_08052B8C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08052B94: .4byte 0x0000B002

	thumb_func_start FUN_08052b98
FUN_08052b98: @ 0x08052B98
	movs r0, #1
	bx lr

	thumb_func_start cubitMode1
cubitMode1: @ 0x08052B9C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bhi _08052C2A
	lsls r0, r0, #2
	ldr r1, _08052BB0 @ =_08052BB4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08052BB0: .4byte _08052BB4
_08052BB4: @ jump table
	.4byte _08052BCC @ case 0
	.4byte _08052C00 @ case 1
	.4byte _08052BE0 @ case 2
	.4byte _08052BF2 @ case 3
	.4byte _08052C00 @ case 4
	.4byte _08052C1C @ case 5
_08052BCC:
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	movs r0, #0xc9
	bl PlaySound
	ldr r1, _08052BDC @ =0x0000B007
	b _08052BF4
	.align 2, 0
_08052BDC: .4byte 0x0000B007
_08052BE0:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08052C10
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08052C2A
	b _08052C10
_08052BF2:
	ldr r1, _08052C18 @ =0x0000B009
_08052BF4:
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08052C00:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08052C2A
_08052C10:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08052C2A
	.align 2, 0
_08052C18: .4byte 0x0000B009
_08052C1C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08052C2A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08052c30
FUN_08052c30: @ 0x08052C30
	movs r0, #1
	bx lr

	thumb_func_start cubitMode2
cubitMode2: @ 0x08052C34
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08052C44
	cmp r0, #1
	beq _08052C52
	b _08052C6A
_08052C44:
	ldr r1, _08052C70 @ =0x0000B002
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08052C52:
	ldr r0, _08052C74 @ =gStageRun
	ldrb r0, [r0, #0x12]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _08052C64
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08052C64:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08052C6A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08052C70: .4byte 0x0000B002
_08052C74: .4byte gStageRun

	thumb_func_start FUN_08052c78
FUN_08052c78: @ 0x08052C78
	movs r0, #1
	bx lr

	thumb_func_start cubitNeutral
cubitNeutral: @ 0x08052C7C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _08052C90
	cmp r0, #1
	beq _08052D00
	b _08052EEC
_08052C90:
	adds r0, r6, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08052CB8
	ldr r1, _08052CB0 @ =0x0000B001
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08052CB4 @ =0x083639F0
	bl SetDDP
	b _08052CCA
	.align 2, 0
_08052CB0: .4byte 0x0000B001
_08052CB4: .4byte 0x083639F0
_08052CB8:
	ldr r1, _08052CDC @ =0x0000B002
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08052CE0 @ =0x083639F0
	bl SetDDP
_08052CCA:
	ldrb r0, [r6, #0xf]
	cmp r0, #0xff
	bne _08052CE4
	movs r0, #1
	strb r0, [r6, #0x12]
	movs r0, #0x7f
	strb r0, [r6, #0xf]
	b _08052CE8
	.align 2, 0
_08052CDC: .4byte 0x0000B002
_08052CE0: .4byte 0x083639F0
_08052CE4:
	movs r0, #0x10
	strb r0, [r6, #0x12]
_08052CE8:
	movs r0, #0
	strb r0, [r6, #0x13]
	adds r1, r6, #0
	adds r1, #0x5c
	str r0, [r1, #4]
	str r0, [r6, #0x5c]
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x58]
	str r0, [r6, #0x68]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08052D00:
	adds r0, r6, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08052D30
	adds r0, r6, #0
	bl cubit_08054688
	ldrb r0, [r6, #0x13]
	adds r0, #4
	strb r0, [r6, #0x13]
	ldr r1, _08052D2C @ =gSineTable
	ldrb r0, [r6, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #2
	ldr r0, [r6, #0x68]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	b _08052D36
	.align 2, 0
_08052D2C: .4byte gSineTable
_08052D30:
	adds r0, r6, #0
	bl cubit_08054688
_08052D36:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	bne _08052D44
	b _08052EEC
_08052D44:
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08052D50
	b _08052EEC
_08052D50:
	ldrb r0, [r6, #0xf]
	cmp r0, #0x7f
	bne _08052D90
	ldr r2, _08052D84 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08052D88 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08052D8C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r2, r0, #0x11
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	bne _08052D90
	movs r1, #6
	strb r1, [r6, #0xd]
	strb r2, [r6, #0xe]
	adds r7, r6, #0
	adds r7, #0xb5
	movs r2, #0xb6
	adds r2, r2, r6
	mov r8, r2
	b _08052EE0
	.align 2, 0
_08052D84: .4byte RNG_0202f388
_08052D88: .4byte 0x000343FD
_08052D8C: .4byte 0x00269EC3
_08052D90:
	adds r0, r6, #0
	adds r0, #0xb5
	adds r1, r6, #0
	adds r1, #0xb6
	movs r3, #0
	ldrsb r3, [r0, r3]
	movs r2, #0
	ldrsb r2, [r1, r2]
	adds r7, r0, #0
	mov r8, r1
	cmp r3, r2
	bne _08052E68
	ldr r0, _08052DFC @ =gMission
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _08052E10
	adds r0, r6, #0
	bl cubit_08054674
	adds r3, r0, #0
	ldr r2, _08052E00 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08052E04 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08052E08 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _08052E0C @ =0x080FEF5A
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r1, [r4]
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r1, r0
	bne _08052EDA
	adds r0, r6, #0
	movs r2, #1
	bl cubit_080545cc
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b _08052EDA
	.align 2, 0
_08052DFC: .4byte gMission
_08052E00: .4byte RNG_0202f388
_08052E04: .4byte 0x000343FD
_08052E08: .4byte 0x00269EC3
_08052E0C: .4byte 0x080FEF5A
_08052E10:
	adds r0, r6, #0
	bl cubit_08054674
	adds r3, r0, #0
	ldr r2, _08052E58 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08052E5C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08052E60 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _08052E64 @ =0x080FEF38
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r1, [r4]
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r1, r0
	bne _08052EDA
	adds r0, r6, #0
	movs r2, #0
	bl cubit_080545cc
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b _08052EDA
	.align 2, 0
_08052E58: .4byte RNG_0202f388
_08052E5C: .4byte 0x000343FD
_08052E60: .4byte 0x00269EC3
_08052E64: .4byte 0x080FEF38
_08052E68:
	ldr r0, _08052E94 @ =gMission
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _08052EA8
	adds r0, r6, #0
	bl cubit_08054674
	adds r3, r0, #0
	ldr r2, _08052E98 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08052E9C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08052EA0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _08052EA4 @ =0x080FEF5A
	b _08052EC6
	.align 2, 0
_08052E94: .4byte gMission
_08052E98: .4byte RNG_0202f388
_08052E9C: .4byte 0x000343FD
_08052EA0: .4byte 0x00269EC3
_08052EA4: .4byte 0x080FEF5A
_08052EA8:
	adds r0, r6, #0
	bl cubit_08054674
	adds r3, r0, #0
	ldr r2, _08052EF8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08052EFC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08052F00 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _08052F04 @ =0x080FEF38
_08052EC6:
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r1, [r4]
_08052EDA:
	movs r0, #0
	strb r1, [r6, #0xd]
	strb r0, [r6, #0xe]
_08052EE0:
	movs r0, #0
	strb r0, [r6, #0xf]
	ldrb r0, [r7]
	mov r2, r8
	strb r0, [r2]
	strb r1, [r7]
_08052EEC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08052EF8: .4byte RNG_0202f388
_08052EFC: .4byte 0x000343FD
_08052F00: .4byte 0x00269EC3
_08052F04: .4byte 0x080FEF38

	thumb_func_start FUN_08052f08
FUN_08052f08: @ 0x08052F08
	movs r0, #1
	bx lr

	thumb_func_start cubitMode4
cubitMode4: @ 0x08052F0C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0xb
	bls _08052F18
	b _080533AE
_08052F18:
	lsls r0, r0, #2
	ldr r1, _08052F24 @ =_08052F28
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08052F24: .4byte _08052F28
_08052F28: @ jump table
	.4byte _08052F58 @ case 0
	.4byte _08052FCC @ case 1
	.4byte _08052FEC @ case 2
	.4byte _08053010 @ case 3
	.4byte _08053068 @ case 4
	.4byte _08053114 @ case 5
	.4byte _08053130 @ case 6
	.4byte _0805319A @ case 7
	.4byte _08053308 @ case 8
	.4byte _0805334E @ case 9
	.4byte _08053374 @ case 10
	.4byte _08053398 @ case 11
_08052F58:
	adds r3, r6, #0
	adds r3, #0xca
	movs r0, #1
	strb r0, [r3]
	adds r0, r6, #0
	adds r0, #0xd8
	ldr r2, [r6, #0x54]
	ldr r1, [r0]
	adds r4, r0, #0
	cmp r2, r1
	ble _08052F7E
	adds r0, #8
	ldr r0, [r0]
	asrs r0, r0, #1
	adds r0, r1, r0
	cmp r2, r0
	ble _08052F90
	movs r0, #2
	b _08052F8E
_08052F7E:
	adds r0, r6, #0
	adds r0, #0xe0
	ldr r0, [r0]
	asrs r0, r0, #1
	subs r0, r1, r0
	cmp r2, r0
	bge _08052F90
	movs r0, #0
_08052F8E:
	strb r0, [r3]
_08052F90:
	ldr r0, [r4]
	ldr r5, [r6, #0x58]
	ldr r1, _08052FE4 @ =0xFFFFCE00
	adds r4, r5, r1
	movs r1, #0x18
	strb r1, [r6, #0x12]
	ldr r1, [r6, #0x54]
	subs r0, r0, r1
	movs r1, #0x18
	bl __divsi3
	str r0, [r6, #0x5c]
	movs r0, #0xa2
	lsls r0, r0, #7
	subs r4, r4, r5
	subs r0, r0, r4
	movs r1, #0x18
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r6, #0x60]
	movs r0, #0x17
	strb r0, [r6, #0x12]
	ldr r1, _08052FE8 @ =0x0000B015
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08052FCC:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08052FDE
	b _080533AE
_08052FDE:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _080533AC
	.align 2, 0
_08052FE4: .4byte 0xFFFFCE00
_08052FE8: .4byte 0x0000B015
_08052FEC:
	adds r1, r6, #0
	adds r1, #0xc8
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0805305C @ =0x0000B016
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08053060 @ =0x083639F0
	bl SetDDP
	strb r4, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08053010:
	ldr r0, [r6, #0x60]
	adds r2, r0, #0
	adds r2, #0x48
	str r2, [r6, #0x60]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	adds r0, r0, r2
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	bne _0805303C
	cmp r2, #0
	ble _0805303C
	movs r0, #1
	strb r0, [r6, #0x13]
	ldr r1, _08053064 @ =0x0000B017
	adds r0, r6, #0
	bl SetMotion
_0805303C:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _08053054
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08053054
	b _080533AE
_08053054:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _080533AC
	.align 2, 0
_0805305C: .4byte 0x0000B016
_08053060: .4byte 0x083639F0
_08053064: .4byte 0x0000B017
_08053068:
	movs r7, #0
	adds r0, r6, #0
	adds r0, #0xca
	ldrb r0, [r0]
	cmp r0, #0
	bne _0805307A
	adds r0, r6, #0
	adds r0, #0xdc
	b _080530A0
_0805307A:
	cmp r0, #1
	bne _08053098
	ldr r0, _08053094 @ =pZero2
	ldr r0, [r0]
	adds r1, r6, #0
	adds r1, #0xd8
	ldr r2, [r0, #0x54]
	ldr r0, [r1]
	cmp r2, r0
	ble _0805309C
	adds r0, r6, #0
	adds r0, #0xdc
	b _080530A0
	.align 2, 0
_08053094: .4byte pZero2
_08053098:
	cmp r0, #2
	bne _080530A2
_0805309C:
	adds r0, r6, #0
	adds r0, #0xd4
_080530A0:
	ldr r7, [r0]
_080530A2:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r4, r0, #0
	movs r5, #0
	movs r0, #0x28
	strb r0, [r6, #0x12]
	adds r0, r6, #0
	bl InitScalerotMotion1
	adds r0, r6, #0
	bl ResetDynamicMotion
	ldr r1, _0805312C @ =0x0000B018
	adds r0, r6, #0
	bl SetMotion
	str r5, [r6, #0x64]
	movs r0, #0x52
	str r0, [r6, #0x68]
	adds r0, r6, #0
	adds r0, #0x24
	strb r5, [r0]
	adds r0, #0x2c
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	ldr r0, [r6, #0x54]
	subs r0, r7, r0
	ldrb r1, [r6, #0x12]
	bl __divsi3
	str r0, [r6, #0x5c]
	ldrb r1, [r6, #0x12]
	adds r0, r1, #1
	asrs r0, r0, #1
	adds r2, r0, #0
	muls r2, r1, r2
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #3
	ldr r2, [r6, #0x58]
	subs r4, r4, r2
	subs r0, r0, r4
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r6, #0x60]
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08053114:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08053126
	b _080533AE
_08053126:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _080533AC
	.align 2, 0
_0805312C: .4byte 0x0000B018
_08053130:
	ldr r0, [r6, #0x5c]
	cmp r0, #0
	ble _08053152
	adds r1, r6, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r6, #0xa]
	orrs r1, r0
	strb r1, [r6, #0xa]
	b _0805316E
_08053152:
	adds r1, r6, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
_0805316E:
	movs r0, #0xca
	bl PlaySound
	ldr r1, _08053200 @ =0x0000B019
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08053204 @ =0x08363A20
	bl SetDDP
	ldr r0, [r6, #0x58]
	ldr r2, _08053208 @ =0xFFFFD800
	adds r0, r0, r2
	str r0, [r6, #0x58]
	ldr r1, _0805320C @ =wElement
	movs r0, #4
	strb r0, [r1, #2]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0805319A:
	ldr r2, [r6, #0x60]
	adds r2, #0x48
	str r2, [r6, #0x60]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	adds r0, r0, r2
	str r0, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	adds r5, r6, #0
	adds r5, #0x70
	cmp r0, #3
	bne _0805329E
	ldrb r0, [r6, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _08053200 @ =0x0000B019
	cmp r0, r1
	bne _08053240
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r6, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	adds r4, r6, #0
	adds r4, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r4]
	cmp r1, #0
	beq _08053210
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08053216
	.align 2, 0
_08053200: .4byte 0x0000B019
_08053204: .4byte 0x08363A20
_08053208: .4byte 0xFFFFD800
_0805320C: .4byte wElement
_08053210:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_08053216:
	strb r0, [r6, #0xa]
	ldr r0, [r6, #0x64]
	asrs r1, r0, #4
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0x7f
	bgt _08053226
	movs r0, #0xfe
_08053226:
	subs r0, r0, r1
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x64]
	lsls r0, r0, #4
	str r0, [r6, #0x64]
	ldr r1, _0805323C @ =0x0000B01F
	adds r0, r6, #0
	bl SetMotion
	b _0805329E
	.align 2, 0
_0805323C: .4byte 0x0000B01F
_08053240:
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r6, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	adds r4, r6, #0
	adds r4, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r4]
	cmp r1, #0
	beq _08053276
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805327C
_08053276:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805327C:
	strb r0, [r6, #0xa]
	ldr r0, [r6, #0x64]
	asrs r1, r0, #4
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0x7f
	bgt _0805328C
	movs r0, #0xfe
_0805328C:
	subs r0, r0, r1
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x64]
	lsls r0, r0, #4
	str r0, [r6, #0x64]
	ldr r1, _080532C0 @ =0x0000B019
	adds r0, r6, #0
	bl SetMotion
_0805329E:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x5c]
	cmp r0, #0
	ble _080532C4
	ldrb r0, [r6, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080532C0 @ =0x0000B019
	cmp r0, r1
	bne _080532E0
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	subs r0, r0, r1
	b _080532E6
	.align 2, 0
_080532C0: .4byte 0x0000B019
_080532C4:
	ldrb r0, [r6, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080532DC @ =0x0000B019
	cmp r0, r1
	bne _080532E0
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	subs r0, r0, r1
	b _080532E6
	.align 2, 0
_080532DC: .4byte 0x0000B019
_080532E0:
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	adds r0, r0, r1
_080532E6:
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x64]
	asrs r0, r0, #4
	adds r1, r6, #0
	adds r1, #0x24
	strb r0, [r1]
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _08053302
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080533AE
_08053302:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _080533AC
_08053308:
	adds r0, r6, #0
	adds r0, #0xc8
	movs r2, #0
	strb r2, [r0]
	ldr r1, _08053364 @ =wElement
	movs r0, #4
	strb r0, [r1, #2]
	adds r0, r6, #0
	adds r0, #0x24
	strb r2, [r0]
	adds r0, #0x2c
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	ldr r1, _08053368 @ =0x0000B01A
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0805336C @ =0x083639F0
	bl SetDDP
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	ldr r2, _08053370 @ =0xFFFFC400
	adds r1, r1, r2
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0805334E:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080533AE
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _080533AC
	.align 2, 0
_08053364: .4byte wElement
_08053368: .4byte 0x0000B01A
_0805336C: .4byte 0x083639F0
_08053370: .4byte 0xFFFFC400
_08053374:
	adds r0, r6, #0
	bl InitNonAffineMotion
	adds r0, r6, #0
	bl ResetDynamicMotion
	ldr r1, _080533B4 @ =0x0000B01B
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _080533B8 @ =0x083639F0
	bl SetDDP
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08053398:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _080533AE
	movs r0, #0
	strb r1, [r6, #0xd]
_080533AC:
	strb r0, [r6, #0xe]
_080533AE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080533B4: .4byte 0x0000B01B
_080533B8: .4byte 0x083639F0

	thumb_func_start FUN_080533bc
FUN_080533bc: @ 0x080533BC
	movs r0, #1
	bx lr

	thumb_func_start cubitMode5
cubitMode5: @ 0x080533C0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080533E6
	cmp r0, #1
	bgt _080533D4
	cmp r0, #0
	beq _080533DE
	b _08053450
_080533D4:
	cmp r0, #2
	beq _0805341A
	cmp r0, #3
	beq _0805343A
	b _08053450
_080533DE:
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080533E6:
	ldr r2, [r4, #0x60]
	adds r2, #0x40
	str r2, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _08053450
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0805344E
_0805341A:
	ldr r1, _08053458 @ =0x0000B014
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805345C @ =0x083639F0
	bl SetDDP
	adds r1, r4, #0
	adds r1, #0xc8
	movs r0, #0
	strb r0, [r1]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805343A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _08053450
	movs r0, #0
	strb r1, [r4, #0xd]
_0805344E:
	strb r0, [r4, #0xe]
_08053450:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08053458: .4byte 0x0000B014
_0805345C: .4byte 0x083639F0

	thumb_func_start nop_08053460
nop_08053460: @ 0x08053460
	movs r0, #1
	bx lr

	thumb_func_start cubitMode6
cubitMode6: @ 0x08053464
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #8
	bls _08053470
	b _0805371C
_08053470:
	lsls r0, r0, #2
	ldr r1, _0805347C @ =_08053480
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0805347C: .4byte _08053480
_08053480: @ jump table
	.4byte _080534A4 @ case 0
	.4byte _080534E4 @ case 1
	.4byte _08053500 @ case 2
	.4byte _08053564 @ case 3
	.4byte _080535B8 @ case 4
	.4byte _08053600 @ case 5
	.4byte _08053634 @ case 6
	.4byte _080536F0 @ case 7
	.4byte _08053714 @ case 8
_080534A4:
	adds r0, r5, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	cmp r0, #0
	beq _080534CC
	ldr r1, _080534C4 @ =0x0000B010
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080534C8 @ =0x083639F0
	bl SetDDP
	b _080534DE
	.align 2, 0
_080534C4: .4byte 0x0000B010
_080534C8: .4byte 0x083639F0
_080534CC:
	ldr r1, _080534F8 @ =0x0000B00D
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080534FC @ =0x083639F0
	bl SetDDP
_080534DE:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080534E4:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080534F6
	b _0805371C
_080534F6:
	b _08053706
	.align 2, 0
_080534F8: .4byte 0x0000B00D
_080534FC: .4byte 0x083639F0
_08053500:
	adds r0, r5, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08053518
	ldr r1, _08053514 @ =0x0000B011
	adds r0, r5, #0
	bl SetMotion
	b _08053520
	.align 2, 0
_08053514: .4byte 0x0000B011
_08053518:
	ldr r1, _080535A4 @ =0x0000B00E
	adds r0, r5, #0
	bl SetMotion
_08053520:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080535A8 @ =0x083639D8
	bl SetDDP
	movs r0, #0x41
	strb r0, [r5, #0x12]
	ldr r2, _080535AC @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080535B0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080535B4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #5
	bl __umodsi3
	strb r0, [r5, #0x13]
	ldrb r1, [r5, #0x13]
	adds r0, r5, #0
	bl FUN_080a5f00
	adds r1, r5, #0
	adds r1, #0xcc
	str r0, [r1]
	movs r0, #0xcd
	bl PlaySound
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08053564:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _0805358A
	cmp r0, #3
	beq _0805358A
	cmp r0, #5
	beq _0805358A
	cmp r0, #7
	beq _0805358A
	cmp r0, #8
	beq _0805358A
	b _080536F6
_0805358A:
	adds r0, r5, #0
	adds r0, #0x72
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _0805359A
	b _080536F6
_0805359A:
	movs r0, #0xcb
	bl PlaySound
	b _080536F6
	.align 2, 0
_080535A4: .4byte 0x0000B00E
_080535A8: .4byte 0x083639D8
_080535AC: .4byte RNG_0202f388
_080535B0: .4byte 0x000343FD
_080535B4: .4byte 0x00269EC3
_080535B8:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r4, #0
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0805362C @ =0x083639D8
	bl SetDDP
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r2, _08053630 @ =0x080FEF88
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #3
	adds r0, r0, r2
	ldr r1, [r1]
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0xb8
	ldrb r1, [r5, #0x13]
	lsls r1, r1, #3
	adds r2, #4
	adds r1, r1, r2
	ldr r0, [r0]
	ldr r1, [r1]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	strb r4, [r5, #0x13]
	movs r0, #0x14
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08053600:
	adds r0, r5, #0
	adds r0, #0xcc
	ldr r1, [r0]
	ldrb r1, [r1, #0xe]
	adds r4, r0, #0
	cmp r1, #6
	bls _08053622
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	bne _08053622
	movs r0, #1
	strb r0, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0805362C @ =0x083639D8
	bl SetDDP
_08053622:
	ldr r0, [r4]
	ldrb r0, [r0, #0xe]
	cmp r0, #9
	bls _0805371C
	b _08053706
	.align 2, 0
_0805362C: .4byte 0x083639D8
_08053630: .4byte 0x080FEF88
_08053634:
	adds r1, r5, #0
	adds r1, #0xcc
	movs r0, #0
	str r0, [r1]
	ldrb r0, [r5, #0xa]
	movs r3, #1
	movs r6, #0
	adds r2, r3, #0
	orrs r2, r0
	strb r2, [r5, #0xa]
	ldr r0, _08053690 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	ble _08053694
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	bne _080536D6
	lsrs r0, r2, #4
	eors r0, r3
	ands r0, r3
	adds r1, r5, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #4
	eors r1, r3
	ands r1, r3
	adds r4, r5, #0
	adds r4, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r4]
	cmp r1, #0
	beq _080536CE
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080536D4
	.align 2, 0
_08053690: .4byte pZero2
_08053694:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _080536D6
	lsrs r0, r2, #4
	eors r0, r3
	ands r0, r3
	adds r1, r5, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #4
	eors r1, r3
	ands r1, r3
	adds r4, r5, #0
	adds r4, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r4]
	cmp r1, #0
	beq _080536CE
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080536D4
_080536CE:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080536D4:
	strb r0, [r5, #0xa]
_080536D6:
	adds r1, r5, #0
	adds r1, #0xc8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08053710 @ =0x0000B011
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x34
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080536F0:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_080536F6:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08053706
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805371C
_08053706:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0805371C
	.align 2, 0
_08053710: .4byte 0x0000B011
_08053714:
	movs r1, #0
	movs r0, #3
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0805371C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08053724
FUN_08053724: @ 0x08053724
	movs r0, #1
	bx lr

	thumb_func_start cubitMode7
cubitMode7: @ 0x08053728
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0x15
	bls _08053734
	b _08053A00
_08053734:
	lsls r0, r0, #2
	ldr r1, _08053740 @ =_08053744
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08053740: .4byte _08053744
_08053744: @ jump table
	.4byte _0805379C @ case 0
	.4byte _080537C8 @ case 1
	.4byte _080537D6 @ case 2
	.4byte _08053832 @ case 3
	.4byte _08053878 @ case 4
	.4byte _08053886 @ case 5
	.4byte _080538A0 @ case 6
	.4byte _080538C6 @ case 7
	.4byte _08053940 @ case 8
	.4byte _0805394E @ case 9
	.4byte _08053968 @ case 10
	.4byte _08053886 @ case 11
	.4byte _0805398C @ case 12
	.4byte _0805399E @ case 13
	.4byte _080539C0 @ case 14
	.4byte _08053886 @ case 15
	.4byte _080539C8 @ case 16
	.4byte _08053886 @ case 17
	.4byte _080539DC @ case 18
	.4byte _08053886 @ case 19
	.4byte _080539E4 @ case 20
	.4byte _080539F8 @ case 21
_0805379C:
	adds r0, r4, #0
	adds r0, #0xd8
	ldr r1, [r4, #0x54]
	ldr r0, [r0]
	cmp r1, r0
	ble _080537B6
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080537B4
	b _080539F0
_080537B4:
	b _080537C2
_080537B6:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080537C2
	b _080539F0
_080537C2:
	movs r0, #3
	strb r0, [r4, #0xe]
	b _08053A00
_080537C8:
	ldr r1, _08053824 @ =0x0000B003
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080537D6:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080537E8
	b _08053A00
_080537E8:
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r3, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, ip
	strb r0, [r2]
	cmp r1, #0
	beq _08053828
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805382E
	.align 2, 0
_08053824: .4byte 0x0000B003
_08053828:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805382E:
	strb r0, [r4, #0xa]
	b _080539F0
_08053832:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08053854
	ldr r0, [r4, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08053850 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToLeft1
	b _08053864
	.align 2, 0
_08053850: .4byte 0xFFFFF800
_08053854:
	ldr r0, [r4, #0x54]
	ldr r1, _08053870 @ =0xFFFFE400
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08053874 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToRight1
_08053864:
	cmp r0, #0
	bne _0805386A
	b _080539F0
_0805386A:
	movs r0, #0xa
	strb r0, [r4, #0xe]
	b _08053A00
	.align 2, 0
_08053870: .4byte 0xFFFFE400
_08053874: .4byte 0xFFFFF800
_08053878:
	ldr r1, _0805389C @ =0x0000B004
_0805387A:
	adds r0, r4, #0
	bl SetMotion
_08053880:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08053886:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08053898
	b _08053A00
_08053898:
	b _080539F0
	.align 2, 0
_0805389C: .4byte 0x0000B004
_080538A0:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080538B0
	movs r0, #0xc0
	lsls r0, r0, #2
	b _080538B2
_080538B0:
	ldr r0, _080538F4 @ =0xFFFFFD00
_080538B2:
	str r0, [r4, #0x5c]
	ldr r0, _080538F8 @ =0xFFFFFE00
	str r0, [r4, #0x60]
	ldr r1, _080538FC @ =0x0000B005
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080538C6:
	ldr r1, [r4, #0x60]
	adds r1, #0x40
	str r1, [r4, #0x60]
	ldr r2, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r2, r2, r0
	str r2, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r3, r0, r1
	str r3, [r4, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08053904
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r2, r1
	ldr r2, _08053900 @ =0xFFFFF800
	adds r1, r3, r2
	bl PushoutToLeft1
	b _08053910
	.align 2, 0
_080538F4: .4byte 0xFFFFFD00
_080538F8: .4byte 0xFFFFFE00
_080538FC: .4byte 0x0000B005
_08053900: .4byte 0xFFFFF800
_08053904:
	ldr r1, _08053938 @ =0xFFFFE800
	adds r0, r2, r1
	ldr r2, _0805393C @ =0xFFFFF800
	adds r1, r3, r2
	bl PushoutToRight1
_08053910:
	adds r1, r0, #0
	cmp r1, #0
	beq _0805391C
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0805391C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _08053A00
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	b _080539F0
	.align 2, 0
_08053938: .4byte 0xFFFFE800
_0805393C: .4byte 0xFFFFF800
_08053940:
	ldr r1, _08053964 @ =0x0000B006
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805394E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08053A00
	strb r0, [r4, #0xe]
	b _08053A00
	.align 2, 0
_08053964: .4byte 0x0000B006
_08053968:
	ldr r1, _08053988 @ =0x0000B00D
	adds r0, r4, #0
	bl SetMotion
	movs r0, #9
	strb r0, [r4, #0x12]
	movs r0, #4
	strb r0, [r4, #0x13]
	movs r0, #0xcd
	bl PlaySound
	adds r0, r4, #0
	bl FUN_080a5fc4
	b _08053880
	.align 2, 0
_08053988: .4byte 0x0000B00D
_0805398C:
	ldr r1, _080539BC @ =0x0000B00E
	adds r0, r4, #0
	bl SetMotion
	movs r0, #7
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805399E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080539B4
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08053A00
_080539B4:
	movs r0, #9
	strb r0, [r4, #0x12]
	b _080539F0
	.align 2, 0
_080539BC: .4byte 0x0000B00E
_080539C0:
	ldr r1, _080539C4 @ =0x0000B007
	b _0805387A
	.align 2, 0
_080539C4: .4byte 0x0000B007
_080539C8:
	ldr r1, _080539D8 @ =0x0000B008
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	b _08053880
	.align 2, 0
_080539D8: .4byte 0x0000B008
_080539DC:
	ldr r1, _080539E0 @ =0x0000B009
	b _0805387A
	.align 2, 0
_080539E0: .4byte 0x0000B009
_080539E4:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080539F0
	movs r0, #0xe
	strb r0, [r4, #0xe]
	b _08053A00
_080539F0:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08053A00
_080539F8:
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08053A00:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08053a08
FUN_08053a08: @ 0x08053A08
	movs r0, #1
	bx lr

	thumb_func_start cubitMode8
cubitMode8: @ 0x08053A0C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xe
	bls _08053A18
	b _08053CFC
_08053A18:
	lsls r0, r0, #2
	ldr r1, _08053A24 @ =_08053A28
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08053A24: .4byte _08053A28
_08053A28: @ jump table
	.4byte _08053A64 @ case 0
	.4byte _08053A9A @ case 1
	.4byte _08053AA8 @ case 2
	.4byte _08053B02 @ case 3
	.4byte _08053B48 @ case 4
	.4byte _08053B56 @ case 5
	.4byte _08053B70 @ case 6
	.4byte _08053B98 @ case 7
	.4byte _08053C24 @ case 8
	.4byte _08053C5C @ case 9
	.4byte _08053C84 @ case 10
	.4byte _08053C9C @ case 11
	.4byte _08053CAE @ case 12
	.4byte _08053CCC @ case 13
	.4byte _08053CDE @ case 14
_08053A64:
	ldr r0, _08053A84 @ =pZero2
	ldr r0, [r0]
	adds r1, r4, #0
	adds r1, #0xd8
	ldr r2, [r0, #0x54]
	ldr r0, [r1]
	cmp r2, r0
	ble _08053A88
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08053A80
	b _08053CC0
_08053A80:
	b _08053A94
	.align 2, 0
_08053A84: .4byte pZero2
_08053A88:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08053A94
	b _08053CC0
_08053A94:
	movs r0, #3
	strb r0, [r4, #0xe]
	b _08053CFC
_08053A9A:
	ldr r1, _08053AF4 @ =0x0000B003
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08053AA8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08053ABA
	b _08053CFC
_08053ABA:
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r3, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, ip
	strb r0, [r2]
	cmp r1, #0
	beq _08053AF8
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08053AFE
	.align 2, 0
_08053AF4: .4byte 0x0000B003
_08053AF8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08053AFE:
	strb r0, [r4, #0xa]
	b _08053CC0
_08053B02:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08053B24
	ldr r0, [r4, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08053B20 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToLeft1
	b _08053B34
	.align 2, 0
_08053B20: .4byte 0xFFFFF800
_08053B24:
	ldr r0, [r4, #0x54]
	ldr r1, _08053B40 @ =0xFFFFE400
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08053B44 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToRight1
_08053B34:
	cmp r0, #0
	bne _08053B3A
	b _08053CC0
_08053B3A:
	movs r0, #9
	strb r0, [r4, #0xe]
	b _08053CFC
	.align 2, 0
_08053B40: .4byte 0xFFFFE400
_08053B44: .4byte 0xFFFFF800
_08053B48:
	ldr r1, _08053B6C @ =0x0000B004
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08053B56:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08053B68
	b _08053CFC
_08053B68:
	b _08053CC0
	.align 2, 0
_08053B6C: .4byte 0x0000B004
_08053B70:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08053B7E
	movs r0, #0x40
	b _08053B82
_08053B7E:
	movs r0, #0x40
	rsbs r0, r0, #0
_08053B82:
	str r0, [r4, #0x64]
	movs r0, #0
	str r0, [r4, #0x5c]
	str r0, [r4, #0x60]
	ldr r1, _08053BBC @ =0x0000B005
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08053B98:
	ldr r0, [r4, #0x5c]
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	cmp r0, #0
	bge _08053BA6
	rsbs r0, r0, #0
_08053BA6:
	movs r2, #0x80
	lsls r2, r2, #3
	cmp r0, r2
	ble _08053BC4
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08053BC0
	str r2, [r4, #0x5c]
	b _08053BC4
	.align 2, 0
_08053BBC: .4byte 0x0000B005
_08053BC0:
	ldr r0, _08053BF8 @ =0xFFFFFC00
	str r0, [r4, #0x5c]
_08053BC4:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08053C00
	ldr r0, [r4, #0x54]
	movs r1, #0x90
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08053BFC @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToLeft1
	b _08053C10
	.align 2, 0
_08053BF8: .4byte 0xFFFFFC00
_08053BFC: .4byte 0xFFFFF800
_08053C00:
	ldr r0, [r4, #0x54]
	ldr r1, _08053C1C @ =0xFFFFDC00
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08053C20 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToRight1
_08053C10:
	cmp r0, #0
	beq _08053CFC
	movs r0, #0x14
	strb r0, [r4, #0x12]
	b _08053CC0
	.align 2, 0
_08053C1C: .4byte 0xFFFFDC00
_08053C20: .4byte 0xFFFFF800
_08053C24:
	ldr r1, [r4, #0x5c]
	rsbs r0, r1, #0
	lsls r0, r0, #6
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08053CC0
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08053CFC
	b _08053CC0
_08053C5C:
	ldr r1, _08053C98 @ =0x0000B00D
	adds r0, r4, #0
	bl SetMotion
	movs r0, #9
	strb r0, [r4, #0x12]
	movs r0, #4
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	bl cubit_080a6078
	adds r1, r4, #0
	adds r1, #0xcc
	str r0, [r1]
	movs r0, #0xcd
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08053C84:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08053CFC
	b _08053CC0
	.align 2, 0
_08053C98: .4byte 0x0000B00D
_08053C9C:
	ldr r1, _08053CC8 @ =0x0000B00E
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08053CAE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0xcc
	ldr r0, [r0]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _08053CFC
_08053CC0:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08053CFC
	.align 2, 0
_08053CC8: .4byte 0x0000B00E
_08053CCC:
	ldr r1, _08053D04 @ =0x0000B001
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0xe
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08053CDE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08053CF4
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08053CFC
_08053CF4:
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08053CFC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08053D04: .4byte 0x0000B001

	thumb_func_start FUN_08053d08
FUN_08053d08: @ 0x08053D08
	movs r0, #1
	bx lr

	thumb_func_start cubitEX
cubitEX: @ 0x08053D0C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #0x1b
	bls _08053D1A
	b _080542BC
_08053D1A:
	lsls r0, r0, #2
	ldr r1, _08053D24 @ =_08053D28
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08053D24: .4byte _08053D28
_08053D28: @ jump table
	.4byte _08053D98 @ case 0
	.4byte _0805426C @ case 1
	.4byte _08053E08 @ case 2
	.4byte _08053E32 @ case 3
	.4byte _08053E88 @ case 4
	.4byte _0805426C @ case 5
	.4byte _08053EF8 @ case 6
	.4byte _08053F60 @ case 7
	.4byte _080540CC @ case 8
	.4byte _0805426C @ case 9
	.4byte _08054114 @ case 10
	.4byte _0805426C @ case 11
	.4byte _08054128 @ case 12
	.4byte _08054132 @ case 13
	.4byte _0805414E @ case 14
	.4byte _08054170 @ case 15
	.4byte _080541A0 @ case 16
	.4byte _0805426C @ case 17
	.4byte _08054254 @ case 18
	.4byte _0805426C @ case 19
	.4byte _080541E0 @ case 20
	.4byte _080541F2 @ case 21
	.4byte _08054210 @ case 22
	.4byte _0805426C @ case 23
	.4byte _08054254 @ case 24
	.4byte _0805426C @ case 25
	.4byte _0805428C @ case 26
	.4byte _0805429E @ case 27
_08053D98:
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, [r0]
	ldr r2, [r7, #0x54]
	cmp r2, r1
	ble _08053DB6
	adds r0, #8
	ldr r0, [r0]
	asrs r0, r0, #1
	adds r0, r1, r0
	cmp r2, r0
	ble _08053DCA
	adds r0, r7, #0
	adds r0, #0xdc
	b _08053DC8
_08053DB6:
	adds r0, r7, #0
	adds r0, #0xe0
	ldr r0, [r0]
	asrs r0, r0, #1
	subs r0, r1, r0
	cmp r2, r0
	bge _08053DCA
	adds r0, r7, #0
	adds r0, #0xd4
_08053DC8:
	ldr r1, [r0]
_08053DCA:
	ldr r5, [r7, #0x58]
	ldr r0, _08053E00 @ =0xFFFFCE00
	adds r4, r5, r0
	movs r0, #0x18
	strb r0, [r7, #0x12]
	subs r0, r1, r2
	movs r1, #0x18
	bl __divsi3
	str r0, [r7, #0x5c]
	movs r0, #0xa2
	lsls r0, r0, #7
	subs r4, r4, r5
	subs r0, r0, r4
	movs r1, #0x18
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r7, #0x60]
	movs r0, #0x17
	strb r0, [r7, #0x12]
	ldr r1, _08053E04 @ =0x0000B015
	adds r0, r7, #0
	bl SetMotion
	b _08054266
	.align 2, 0
_08053E00: .4byte 0xFFFFCE00
_08053E04: .4byte 0x0000B015
_08053E08:
	adds r1, r7, #0
	adds r1, #0xc8
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xca
	bl PlaySound
	ldr r1, _08053E7C @ =0x0000B016
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _08053E80 @ =0x083639F0
	bl SetDDP
	strb r4, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08053E32:
	ldr r0, [r7, #0x60]
	adds r2, r0, #0
	adds r2, #0x48
	str r2, [r7, #0x60]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	adds r0, r0, r2
	str r0, [r7, #0x58]
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	bne _08053E5E
	cmp r2, #0
	ble _08053E5E
	movs r0, #1
	strb r0, [r7, #0x13]
	ldr r1, _08053E84 @ =0x0000B017
	adds r0, r7, #0
	bl SetMotion
_08053E5E:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _08053E6C
	b _0805427C
_08053E6C:
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08053E78
	b _080542BC
_08053E78:
	b _0805427C
	.align 2, 0
_08053E7C: .4byte 0x0000B016
_08053E80: .4byte 0x083639F0
_08053E84: .4byte 0x0000B017
_08053E88:
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r4, [r0]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	adds r5, r0, #0
	movs r6, #0
	movs r0, #0x28
	strb r0, [r7, #0x12]
	ldr r0, [r7, #0x54]
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0x28
	bl __divsi3
	str r0, [r7, #0x5c]
	movs r0, #0xe1
	lsls r0, r0, #8
	ldr r1, [r7, #0x58]
	subs r5, r5, r1
	subs r0, r0, r5
	movs r1, #0x28
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r7, #0x60]
	movs r0, #0x27
	strb r0, [r7, #0x12]
	adds r0, r7, #0
	bl InitScalerotMotion1
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldr r1, _08053EF4 @ =0x0000B018
	adds r0, r7, #0
	bl SetMotion
	str r6, [r7, #0x64]
	movs r0, #0xa4
	str r0, [r7, #0x68]
	adds r0, r7, #0
	adds r0, #0x24
	strb r6, [r0]
	adds r0, #0x2c
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	b _08054266
	.align 2, 0
_08053EF4: .4byte 0x0000B018
_08053EF8:
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	ble _08053F1A
	adds r1, r7, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r7, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r7, #0xa]
	orrs r1, r0
	strb r1, [r7, #0xa]
	b _08053F3A
_08053F1A:
	cmp r0, #0
	bge _08053F3A
	adds r1, r7, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r7, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r7, #0xa]
_08053F3A:
	movs r0, #0xca
	bl PlaySound
	ldr r1, _08053FC8 @ =0x0000B019
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _08053FCC @ =0x08363A20
	bl SetDDP
	ldr r0, [r7, #0x58]
	ldr r1, _08053FD0 @ =0xFFFFD800
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08053F60:
	ldr r2, [r7, #0x60]
	adds r2, #0x48
	str r2, [r7, #0x60]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	adds r0, r0, r2
	str r0, [r7, #0x58]
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	adds r5, r7, #0
	adds r5, #0x70
	cmp r0, #3
	bne _08054062
	ldrb r0, [r7, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _08053FC8 @ =0x0000B019
	cmp r0, r1
	bne _08054004
	ldrb r0, [r7, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r7, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	adds r4, r7, #0
	adds r4, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r4]
	cmp r1, #0
	beq _08053FD4
	ldrb r0, [r7, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08053FDA
	.align 2, 0
_08053FC8: .4byte 0x0000B019
_08053FCC: .4byte 0x08363A20
_08053FD0: .4byte 0xFFFFD800
_08053FD4:
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
_08053FDA:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x64]
	asrs r1, r0, #4
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0x7f
	bgt _08053FEA
	movs r0, #0xfe
_08053FEA:
	subs r0, r0, r1
	str r0, [r7, #0x64]
	ldr r0, [r7, #0x64]
	lsls r0, r0, #4
	str r0, [r7, #0x64]
	ldr r1, _08054000 @ =0x0000B01F
	adds r0, r7, #0
	bl SetMotion
	b _08054062
	.align 2, 0
_08054000: .4byte 0x0000B01F
_08054004:
	ldrb r0, [r7, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r7, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	adds r4, r7, #0
	adds r4, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r4]
	cmp r1, #0
	beq _0805403A
	ldrb r0, [r7, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08054040
_0805403A:
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
_08054040:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x64]
	asrs r1, r0, #4
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0x7f
	bgt _08054050
	movs r0, #0xfe
_08054050:
	subs r0, r0, r1
	str r0, [r7, #0x64]
	ldr r0, [r7, #0x64]
	lsls r0, r0, #4
	str r0, [r7, #0x64]
	ldr r1, _08054084 @ =0x0000B019
	adds r0, r7, #0
	bl SetMotion
_08054062:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	ble _08054088
	ldrb r0, [r7, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _08054084 @ =0x0000B019
	cmp r0, r1
	bne _080540A4
	ldr r0, [r7, #0x64]
	ldr r1, [r7, #0x68]
	subs r0, r0, r1
	b _080540AA
	.align 2, 0
_08054084: .4byte 0x0000B019
_08054088:
	ldrb r0, [r7, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080540A0 @ =0x0000B019
	cmp r0, r1
	bne _080540A4
	ldr r0, [r7, #0x64]
	ldr r1, [r7, #0x68]
	subs r0, r0, r1
	b _080540AA
	.align 2, 0
_080540A0: .4byte 0x0000B019
_080540A4:
	ldr r0, [r7, #0x64]
	ldr r1, [r7, #0x68]
	adds r0, r0, r1
_080540AA:
	str r0, [r7, #0x64]
	ldr r0, [r7, #0x64]
	asrs r0, r0, #4
	adds r1, r7, #0
	adds r1, #0x24
	strb r0, [r1]
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _080540BE
	b _0805427C
_080540BE:
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080540CA
	b _080542BC
_080540CA:
	b _0805427C
_080540CC:
	adds r0, r7, #0
	adds r0, #0xc8
	movs r1, #0
	strb r1, [r0]
	subs r0, #0xa4
	strb r1, [r0]
	adds r0, #0x2c
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	ldr r1, _08054108 @ =0x0000B01A
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _0805410C @ =0x083639F0
	bl SetDDP
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r2, _08054110 @ =0xFFFFC400
	adds r1, r1, r2
	bl FUN_08009f6c
	str r0, [r7, #0x58]
	b _08054266
	.align 2, 0
_08054108: .4byte 0x0000B01A
_0805410C: .4byte 0x083639F0
_08054110: .4byte 0xFFFFC400
_08054114:
	adds r0, r7, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldr r1, _08054124 @ =0x0000B01B
	b _08054256
	.align 2, 0
_08054124: .4byte 0x0000B01B
_08054128:
	movs r0, #2
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08054132:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _08054140
	b _0805427C
_08054140:
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0805414C
	b _080542BC
_0805414C:
	b _0805427C
_0805414E:
	ldr r1, _08054198 @ =0x0000B00A
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _0805419C @ =0x083639F0
	bl SetDDP
	movs r0, #8
	strb r0, [r7, #0x12]
	movs r0, #0xd0
	bl PlaySound
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08054170:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08054182
	b _080542BC
_08054182:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _0805427C
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08054194
	b _080542BC
_08054194:
	b _0805427C
	.align 2, 0
_08054198: .4byte 0x0000B00A
_0805419C: .4byte 0x083639F0
_080541A0:
	ldr r1, _080541D4 @ =0x0000B00B
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _080541D8 @ =0x083639F0
	bl SetDDP
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	ldr r1, _080541DC @ =0xFFFFBE00
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r4, #0
_080541C0:
	adds r0, r7, #0
	mov r1, sp
	adds r2, r4, #0
	bl createFlameRain1
	adds r4, #1
	cmp r4, #3
	ble _080541C0
	b _08054266
	.align 2, 0
_080541D4: .4byte 0x0000B00B
_080541D8: .4byte 0x083639F0
_080541DC: .4byte 0xFFFFBE00
_080541E0:
	ldr r1, _0805420C @ =0x0000B002
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x14
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080541F2:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _0805427C
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080542BC
	b _0805427C
	.align 2, 0
_0805420C: .4byte 0x0000B002
_08054210:
	ldr r1, _08054248 @ =0x0000B00B
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _0805424C @ =0x083639F0
	bl SetDDP
	ldr r0, [r7, #0x54]
	str r0, [sp, #8]
	ldr r0, [r7, #0x58]
	ldr r2, _08054250 @ =0xFFFFBE00
	adds r0, r0, r2
	add r1, sp, #8
	str r0, [r1, #4]
	movs r4, #0
	adds r5, r1, #0
_08054234:
	adds r0, r7, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl createFlameRain2
	adds r4, #1
	cmp r4, #1
	ble _08054234
	b _08054266
	.align 2, 0
_08054248: .4byte 0x0000B00B
_0805424C: .4byte 0x083639F0
_08054250: .4byte 0xFFFFBE00
_08054254:
	ldr r1, _08054284 @ =0x0000B00C
_08054256:
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _08054288 @ =0x083639F0
	bl SetDDP
_08054266:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0805426C:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080542BC
_0805427C:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _080542BC
	.align 2, 0
_08054284: .4byte 0x0000B00C
_08054288: .4byte 0x083639F0
_0805428C:
	ldr r1, _080542C4 @ =0x0000B002
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x3c
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0805429E:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080542B4
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080542BC
_080542B4:
	movs r1, #0
	movs r0, #3
	strb r0, [r7, #0xd]
	strb r1, [r7, #0xe]
_080542BC:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080542C4: .4byte 0x0000B002

	thumb_func_start FUN_080542c8
FUN_080542c8: @ 0x080542C8
	movs r0, #1
	bx lr

	thumb_func_start cubitMode10
cubitMode10: @ 0x080542CC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080542DC
	cmp r5, #1
	beq _0805430E
	b _08054314
_080542DC:
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	adds r0, r4, #0
	adds r0, #0x24
	strb r5, [r0]
	adds r0, #0x2c
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	movs r0, #0xd1
	bl PlaySound
	ldr r1, _08054338 @ =0x0000B01E
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805430E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08054314:
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08054330
	movs r0, #0
	str r0, [r5]
	movs r1, #3
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
	movs r0, #0xff
	strb r0, [r4, #0xf]
_08054330:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08054338: .4byte 0x0000B01E

	thumb_func_start FUN_0805433c
FUN_0805433c: @ 0x0805433C
	movs r0, #1
	bx lr

	thumb_func_start cubitKnockBackDamage
cubitKnockBackDamage: @ 0x08054340
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08054350
	cmp r5, #1
	beq _080543F4
	b _080544AE
_08054350:
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	adds r0, r4, #0
	adds r0, #0x24
	strb r5, [r0]
	adds r0, #0x2c
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	movs r0, #0xd1
	bl PlaySound
	ldr r1, _080543A8 @ =0x0000B01E
	adds r0, r4, #0
	bl SetMotion
	ldr r0, _080543AC @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _080543B4
	ldr r0, _080543B0 @ =0xFFFFFE00
	str r0, [r4, #0x5c]
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _080543D6
	.align 2, 0
_080543A8: .4byte 0x0000B01E
_080543AC: .4byte pZero2
_080543B0: .4byte 0xFFFFFE00
_080543B4:
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r4, #0x5c]
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080543D6:
	strb r0, [r4, #0xa]
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r2, #0
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0xc0
	str r2, [r0]
	movs r0, #0x28
	strb r0, [r4, #0x12]
	strb r2, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080543F4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x5c]
	rsbs r1, r0, #0
	lsls r1, r1, #3
	asrs r1, r1, #8
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08054416
	str r1, [r4, #0x60]
_08054416:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r2, r1, r0
	str r2, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	ble _08054444
	movs r1, #0xe0
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r3, _080544B4 @ =0xFFFFF400
	adds r1, r2, r3
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	beq _08054444
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_08054444:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _08054466
	ldr r0, [r4, #0x54]
	ldr r1, _080544B8 @ =0xFFFFE400
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _080544B4 @ =0xFFFFF400
	adds r1, r1, r2
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	beq _08054466
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_08054466:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r5, _080544BC @ =0xFFFFFC00
	adds r1, r1, r5
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _08054482
	movs r0, #1
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_08054482:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0805448C
	subs r0, #1
	strb r0, [r4, #0x12]
_0805448C:
	ldrh r1, [r4, #0x12]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bne _080544AE
	ldr r0, [r4, #0x58]
	adds r0, r0, r5
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xc8
	movs r1, #0
	strb r1, [r0]
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	movs r0, #0xff
	strb r0, [r4, #0xf]
_080544AE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080544B4: .4byte 0xFFFFF400
_080544B8: .4byte 0xFFFFE400
_080544BC: .4byte 0xFFFFFC00

	thumb_func_start cubit_080544c0
cubit_080544c0: @ 0x080544C0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r0, [r5]
	cmp r0, #0
	bne _08054522
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08054522
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	ldr r1, _08054500 @ =0x0000B019
	cmp r0, r1
	bne _08054508
	ldrb r0, [r4, #0xd]
	cmp r0, #4
	bne _08054514
	ldrb r0, [r4, #0xe]
	cmp r0, #6
	beq _08054514
	ldr r2, _08054504 @ =0x08363A70
	b _0805450A
	.align 2, 0
_08054500: .4byte 0x0000B019
_08054504: .4byte 0x08363A70
_08054508:
	ldr r2, _0805452C @ =0x08363A68
_0805450A:
	movs r0, #0x16
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r5]
_08054514:
	adds r1, r4, #0
	adds r1, #0xc0
	ldr r0, [r1]
	cmp r0, #0
	beq _08054522
	movs r0, #0
	str r0, [r1]
_08054522:
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0805452C: .4byte 0x08363A68

	thumb_func_start FUN_08054530
FUN_08054530: @ 0x08054530
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, [r3, #0xc]
	ldr r2, [r0, #4]
	ldrb r0, [r2, #4]
	cmp r0, #3
	beq _08054546
	cmp r0, #0xe
	beq _08054546
	cmp r0, #0xf
	bne _08054588
_08054546:
	ldr r2, [r3, #0x2c]
	ldr r0, [r3, #0xc]
	ldr r4, [r0, #0x2c]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08054568
	adds r0, r2, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _08054588
_08054568:
	ldr r0, _08054580 @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08054588
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _08054584
	movs r0, #0xff
	b _08054586
	.align 2, 0
_08054580: .4byte gStageRun
_08054584:
	movs r0, #0xfe
_08054586:
	strb r0, [r2, #0x11]
_08054588:
	ldr r0, [r3, #0xc]
	ldr r2, [r0, #4]
	ldr r1, [r3, #4]
	ldrb r0, [r1]
	cmp r0, #2
	beq _080545C0
	ldr r1, [r1, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080545C0
	ldr r0, [r2, #4]
	ldr r1, _080545C8 @ =0x000200FF
	ands r0, r1
	subs r1, #0xfd
	cmp r0, r1
	bne _080545C0
	ldr r2, [r3, #0x2c]
	ldrb r0, [r2, #0xd]
	subs r0, #0xa
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080545C0
	movs r1, #0
	movs r0, #0xb
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_080545C0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080545C8: .4byte 0x000200FF

	thumb_func_start cubit_080545cc
cubit_080545cc: @ 0x080545CC
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	adds r3, #0xc8
	ldrb r1, [r3]
	cmp r1, #0
	beq _08054614
	cmp r2, #1
	bne _080545F8
	movs r2, #0
	ldr r5, _080545F4 @ =0x08363AA0
	adds r3, r5, #0
_080545E4:
	ldrh r1, [r3]
	cmp r1, r4
	beq _08054646
	adds r3, #2
	adds r2, #1
	cmp r2, #2
	ble _080545E4
	b _0805466A
	.align 2, 0
_080545F4: .4byte 0x08363AA0
_080545F8:
	movs r2, #0
	ldr r5, _08054610 @ =0x08363AA0
	adds r3, r5, #0
_080545FE:
	ldrh r1, [r3]
	cmp r1, r4
	beq _08054646
	adds r3, #2
	adds r2, #1
	cmp r2, #2
	ble _080545FE
	b _0805466A
	.align 2, 0
_08054610: .4byte 0x08363AA0
_08054614:
	cmp r2, #1
	bne _08054656
	movs r2, #0
	ldr r5, _08054638 @ =0x08363A98
	adds r3, r5, #0
_0805461E:
	ldrh r1, [r3]
	cmp r1, r4
	bne _0805463C
	adds r1, r2, #1
	adds r0, r1, #0
	cmp r1, #0
	bge _0805462E
	adds r0, r2, #4
_0805462E:
	asrs r0, r0, #2
	lsls r0, r0, #2
	subs r0, r1, r0
	b _0805464E
	.align 2, 0
_08054638: .4byte 0x08363A98
_0805463C:
	adds r3, #2
	adds r2, #1
	cmp r2, #3
	ble _0805461E
	b _0805466A
_08054646:
	adds r0, r2, #1
	movs r1, #3
	bl __modsi3
_0805464E:
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	b _0805466A
_08054656:
	movs r2, #0
	ldr r5, _08054670 @ =0x08363A98
	adds r3, r5, #0
_0805465C:
	ldrh r1, [r3]
	cmp r1, r4
	beq _08054646
	adds r3, #2
	adds r2, #1
	cmp r2, #3
	ble _0805465C
_0805466A:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08054670: .4byte 0x08363A98

	thumb_func_start cubit_08054674
cubit_08054674: @ 0x08054674
	push {lr}
	adds r0, #0xc8
	ldrb r0, [r0]
	cmp r0, #0
	bne _08054682
	movs r0, #0
	b _08054684
_08054682:
	movs r0, #1
_08054684:
	pop {r1}
	bx r1

	thumb_func_start cubit_08054688
cubit_08054688: @ 0x08054688
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x1e]
	lsls r0, r0, #8
	adds r1, r2, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	ldr r3, _080546CC @ =0x0000B003
	cmp r0, r3
	bne _08054710
	adds r0, r2, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08054746
	ldrb r1, [r2, #0xa]
	movs r3, #0x10
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080546D0
	adds r1, r2, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	subs r1, #2
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	ldrb r0, [r2, #0xa]
	orrs r0, r3
	b _080546EA
	.align 2, 0
_080546CC: .4byte 0x0000B003
_080546D0:
	adds r1, r2, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r3, r2, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r2, #0xa]
	movs r0, #0xef
	ands r0, r1
_080546EA:
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08054700
	ldr r1, _080546FC @ =0x0000B001
	b _08054702
	.align 2, 0
_080546FC: .4byte 0x0000B001
_08054700:
	ldr r1, _0805470C @ =0x0000B002
_08054702:
	adds r0, r2, #0
	bl SetMotion
	b _08054746
	.align 2, 0
_0805470C: .4byte 0x0000B002
_08054710:
	ldr r0, _08054730 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	ble _08054734
	ldrb r1, [r2, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08054746
	adds r0, r2, #0
	adds r1, r3, #0
	bl SetMotion
	b _08054746
	.align 2, 0
_08054730: .4byte pZero2
_08054734:
	ldrb r1, [r2, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08054746
	adds r0, r2, #0
	adds r1, r3, #0
	bl SetMotion
_08054746:
	pop {r0}
	bx r0
	.align 2, 0
