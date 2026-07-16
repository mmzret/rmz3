	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
	movs r0, #0x44
	strb r0, [r4, #0x12]
	b _08052B04
	.align 2, 0
_08052A68: .4byte 0x0000B01C
_08052A6C: .4byte 0x0000B01D
_08052A70:
	adds r0, r4, #0
	bl UpdateEntityAnim
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

