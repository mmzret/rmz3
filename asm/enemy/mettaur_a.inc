	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08088bc8
FUN_08088bc8: @ 0x08088BC8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	cmp r2, #0
	beq _08088C06
	ldr r0, [r4, #0x58]
	adds r1, r0, r2
	str r1, [r4, #0x58]
	cmp r2, #0
	bge _08088BF4
	ldr r0, [r4, #0x54]
	ldr r2, _08088BF0 @ =0xFFFFF000
	adds r1, r1, r2
	bl PushoutToDown1
	adds r2, r0, #0
	cmp r2, #0
	ble _08088C06
	b _08088C00
	.align 2, 0
_08088BF0: .4byte 0xFFFFF000
_08088BF4:
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	bge _08088C06
_08088C00:
	ldr r1, [r4, #0x58]
	adds r1, r1, r2
	str r1, [r4, #0x58]
_08088C06:
	cmp r5, #0
	beq _08088C42
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	str r0, [r4, #0x54]
	cmp r5, #0
	bge _08088C2C
	ldr r1, [r4, #0x58]
	ldr r2, _08088C28 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToRight1
	adds r2, r0, #0
	cmp r2, #0
	ble _08088C42
	b _08088C3C
	.align 2, 0
_08088C28: .4byte 0xFFFFF800
_08088C2C:
	ldr r1, [r4, #0x58]
	ldr r2, _08088C48 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToLeft1
	adds r2, r0, #0
	cmp r2, #0
	bge _08088C42
_08088C3C:
	ldr r1, [r4, #0x54]
	adds r1, r1, r2
	str r1, [r4, #0x54]
_08088C42:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08088C48: .4byte 0xFFFFF800

	thumb_func_start FUN_08088c4c
FUN_08088c4c: @ 0x08088C4C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	movs r7, #0
	adds r6, r4, #0
	adds r6, #0xc2
	ldrb r0, [r6]
	cmp r0, #0
	bne _08088CBC
	cmp r1, #0
	beq _08088C8C
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	ble _08088C7A
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	bge _08088C8C
	b _08088C86
_08088C7A:
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	ble _08088C8C
_08088C86:
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_08088C8C:
	cmp r5, #0
	beq _08088CD4
	ldr r0, [r4, #0x58]
	adds r1, r0, r5
	str r1, [r4, #0x58]
	cmp r5, #0
	ble _08088CA8
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _08088CD4
	b _08088CB4
_08088CA8:
	ldr r0, [r4, #0x54]
	bl PushoutToDown1
	adds r1, r0, #0
	cmp r1, #0
	ble _08088CD4
_08088CB4:
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	b _08088CD4
_08088CBC:
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	adds r1, r1, r5
	str r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08088CD4
	strb r7, [r6]
_08088CD4:
	ldr r0, _08088CF4 @ =gOverworld
	ldr r1, _08088CF8 @ =0x0002C00C
	adds r0, r0, r1
	ldr r0, [r0]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r0, r2
	ldr r0, [r4, #0x58]
	cmp r0, r1
	bge _08088CEC
	str r1, [r4, #0x58]
	movs r7, #1
_08088CEC:
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08088CF4: .4byte gOverworld
_08088CF8: .4byte 0x0002C00C

	thumb_func_start FUN_08088cfc
FUN_08088cfc: @ 0x08088CFC
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	mov r2, sp
	mov r1, sp
	movs r0, #0
	strb r0, [r1, #1]
	strb r0, [r2]
	ldr r2, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r3, _08088D50 @ =0xFFFFF000
	adds r1, r0, r3
	adds r0, r2, #0
	bl PushoutToDown1
	cmp r0, #0
	ble _08088D24
	mov r1, sp
	movs r0, #1
	strb r0, [r1]
_08088D24:
	ldr r2, [r4, #0x54]
	ldr r0, [r4, #0x58]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r0, r3
	adds r0, r2, #0
	bl PushoutToUp1
	cmp r0, #0
	bge _08088D3E
	mov r1, sp
	movs r0, #1
	strb r0, [r1, #1]
_08088D3E:
	mov r0, sp
	mov r1, sp
	ldrb r0, [r0]
	ldrb r1, [r1, #1]
	ands r0, r1
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08088D50: .4byte 0xFFFFF000

	thumb_func_start FUN_08088d54
FUN_08088d54: @ 0x08088D54
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08088D80 @ =0xFFFFEC00
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	adds r0, r4, #0
	mov r1, sp
	bl CreateVFX62
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08088D80: .4byte 0xFFFFEC00

	thumb_func_start MettaurSwim_Init
MettaurSwim_Init: @ 0x08088D84
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x10]
	cmp r0, #2
	bne _08088DE8
	ldr r0, _08088DDC @ =gOverworld
	ldr r1, _08088DE0 @ =0x0002C00C
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	cmp r1, r0
	bge _08088DE8
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _08088DE4 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	b _08088F6E
	.align 2, 0
_08088DDC: .4byte gOverworld
_08088DE0: .4byte 0x0002C00C
_08088DE4: .4byte gEnemyFnTable
_08088DE8:
	ldr r1, _08088E50 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r6, #1
	str r6, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _08088E54 @ =0x08368948
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _08088E58 @ =0x08368814
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #2
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _08088E5C @ =FUN_08089218
	str r0, [r4, #0x24]
	adds r1, r5, #0
	adds r1, #0xb8
	ldr r0, [r5, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r5, #0x58]
	str r0, [r1]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _08088E60
	adds r0, r5, #0
	adds r0, #0xc2
	strb r6, [r0]
	b _08088E66
	.align 2, 0
_08088E50: .4byte gEnemyFnTable
_08088E54: .4byte sInitModes
_08088E58: .4byte sCollisions
_08088E5C: .4byte FUN_08089218
_08088E60:
	adds r1, r5, #0
	adds r1, #0xc2
	strb r0, [r1]
_08088E66:
	ldrb r0, [r5, #0x10]
	cmp r0, #4
	beq _08088ECE
	adds r0, r5, #0
	bl InitNonAffineMotion
	movs r2, #0
	ldr r0, _08088E90 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _08088E84
	movs r2, #1
_08088E84:
	cmp r2, #0
	beq _08088E94
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08088E9A
	.align 2, 0
_08088E90: .4byte pZero2
_08088E94:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_08088E9A:
	strb r0, [r5, #0xa]
	movs r3, #1
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r4, r5, #0
	adds r4, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	ldrb r0, [r5, #0xa]
	orrs r3, r0
	strb r3, [r5, #0xa]
	ldr r1, _08088F74 @ =0x0836894E
	ldrb r0, [r5, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl SetMotion
_08088ECE:
	ldrb r0, [r5, #0x10]
	cmp r0, #1
	bne _08088F16
	ldr r0, _08088F78 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _08088F16
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08088F7C @ =gEnemyFnTable
	movs r1, #0x30
	strb r1, [r3, #9]
	adds r0, #0xc0
	ldr r0, [r0]
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
	movs r0, #4
	strb r0, [r3, #0x10]
	str r5, [r3, #0x28]
_08088F16:
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	beq _08088F20
	cmp r0, #3
	bne _08088F3E
_08088F20:
	ldr r1, [r5, #0x58]
	ldr r0, _08088F80 @ =0x000007FF
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08088F3E
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
_08088F3E:
	adds r0, r5, #0
	bl IsFrozen
	cmp r0, #0
	beq _08088F68
	ldr r1, _08088F84 @ =sInitializers
	ldrb r0, [r5, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	ldr r1, _08088F88 @ =sUpdates
	ldrb r0, [r5, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
_08088F68:
	adds r0, r5, #0
	bl MettaurSwim_Update
_08088F6E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08088F74: .4byte sMotions
_08088F78: .4byte gEnemyHeaderPtr
_08088F7C: .4byte gEnemyFnTable
_08088F80: .4byte 0x000007FF
_08088F84: .4byte sInitializers
_08088F88: .4byte sUpdates

	thumb_func_start MettaurSwim_Update
MettaurSwim_Update: @ 0x08088F8C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r7, [r4, #0x28]
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _08088FA0
	cmp r0, #3
	bne _08088FDC
_08088FA0:
	ldr r0, _08088FD4 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
	movs r1, #0x80
	lsls r1, r1, #8
	cmp r0, r1
	bhi _08088FF4
	adds r0, r4, #0
	bl FUN_08088cfc
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08088FDC
	ldr r1, _08088FD8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	strb r1, [r4, #0xd]
	b _08089128
	.align 2, 0
_08088FD4: .4byte gStageRun+232
_08088FD8: .4byte gEnemyFnTable
_08088FDC:
	ldrb r3, [r4, #0x10]
	cmp r3, #4
	beq _08088FE4
	b _080890E8
_08088FE4:
	ldrb r0, [r7, #0xc]
	cmp r0, #2
	bhi _08088FF4
	cmp r0, #1
	bls _08089030
	adds r0, r7, #0
	bl FUN_08088d54
_08088FF4:
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
	ldr r1, _0808902C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080891E8
	.align 2, 0
_0808902C: .4byte gEnemyFnTable
_08089030:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	ands r1, r2
	adds r6, r0, #0
	cmp r1, #0
	beq _08089130
	adds r0, r7, #0
	bl FUN_08088d54
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	str r2, [r6]
	adds r0, r4, #0
	adds r0, #0x90
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, _080890C8 @ =gEnemyFnTable
	mov r8, r0
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	add r0, r8
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	ldr r5, [r7, #0x54]
	ldr r6, [r7, #0x58]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #1
	bl FUN_08088bc8
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r7, #0
	movs r1, #0
	bl FUN_08088bc8
	orrs r4, r0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r5, [r7, #0x54]
	str r6, [r7, #0x58]
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _080890CC
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	add r0, r8
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl MettaurSwim_Die
	b _080891E8
	.align 2, 0
_080890C8: .4byte gEnemyFnTable
_080890CC:
	ldr r1, _080890E4 @ =0x0000DD07
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	bl UpdateEntityAnim
	movs r0, #8
	strb r0, [r7, #0xd]
	strb r4, [r7, #0xe]
	b _080891E8
	.align 2, 0
_080890E4: .4byte 0x0000DD07
_080890E8:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	ands r1, r2
	adds r6, r0, #0
	cmp r1, #0
	beq _08089130
	ldr r1, _08089120 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	ldr r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ands r0, r1
	cmp r0, #0
	beq _08089124
	cmp r3, #2
	beq _08089124
	movs r0, #1
	b _08089126
	.align 2, 0
_08089120: .4byte gEnemyFnTable
_08089124:
	movs r0, #0
_08089126:
	strb r0, [r4, #0xd]
_08089128:
	adds r0, r4, #0
	bl MettaurSwim_Die
	b _080891E8
_08089130:
	ldrb r0, [r4, #0xd]
	cmp r0, #0xc
	beq _080891C8
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _08089150
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _0808914A
	movs r0, #1
	strb r0, [r4, #0xf]
_0808914A:
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _080891C8
_08089150:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _0808915A
	cmp r0, #3
	bne _08089192
_0808915A:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r5, #0x80
	lsls r5, r5, #3
	adds r1, r1, r5
	bl FUN_0800a40c
	adds r1, r0, #0
	cmp r1, #0
	beq _08089176
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08088bc8
_08089176:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	adds r1, r1, r5
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0808919C
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	b _0808919C
_08089192:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08088c4c
_0808919C:
	ldrb r0, [r4, #0xf]
	cmp r0, #1
	bne _080891AC
	adds r0, r4, #0
	bl UpdateEntityAnim
	movs r0, #2
	strb r0, [r4, #0xf]
_080891AC:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	bne _080891B8
	strb r0, [r4, #0xf]
_080891B8:
	ldr r0, [r6]
	ldr r1, _080891F4 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _080891E8
	ldrb r0, [r4, #0x10]
	cmp r0, #2
	beq _080891E8
_080891C8:
	ldr r1, _080891F8 @ =sInitializers
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080891FC @ =sUpdates
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080891E8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080891F4: .4byte 0x00020001
_080891F8: .4byte sInitializers
_080891FC: .4byte sUpdates

	thumb_func_start MettaurSwim_Die
MettaurSwim_Die: @ 0x08089200
	push {lr}
	ldr r2, _08089214 @ =sDeads
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_08089214: .4byte sDeads

	thumb_func_start FUN_08089218
FUN_08089218: @ 0x08089218
	push {lr}
	ldr r3, [r0, #0x2c]
	ldr r1, [r0, #0xc]
	ldr r2, [r1, #0x2c]
	ldr r0, [r0, #0x14]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _08089248
	ldrh r1, [r2, #8]
	ldr r0, _0808925C @ =0x00001206
	cmp r1, r0
	bne _08089248
	ldr r1, _08089260 @ =gEnemyFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r3, #0x14]
	movs r0, #0
	strb r0, [r3, #0xd]
_08089248:
	adds r2, r3, #0
	adds r2, #0xb4
	ldr r0, _08089264 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r3, #0x54]
	subs r0, r0, r1
	str r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_0808925C: .4byte 0x00001206
_08089260: .4byte gEnemyFnTable
_08089264: .4byte pZero2
