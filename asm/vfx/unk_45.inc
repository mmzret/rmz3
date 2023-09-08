	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080bea24
FUN_080bea24: @ 0x080BEA24
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r6, r1, #0
	movs r4, #0
	movs r5, #0
	ldr r0, _080BEA78 @ =0x0836D9B4
	mov r8, r0
_080BEA36:
	ldr r0, _080BEA7C @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r1, r0, #0
	cmp r1, #0
	beq _080BEA68
	adds r2, r1, #0
	adds r2, #0x25
	movs r0, #1
	strb r0, [r2]
	movs r0, #0x2d
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
	strb r4, [r1, #0x11]
	str r7, [r1, #0x54]
	str r6, [r1, #0x58]
_080BEA68:
	adds r4, #1
	cmp r4, #1
	ble _080BEA36
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BEA78: .4byte 0x0836D9B4
_080BEA7C: .4byte gVFXHeaderPtr

	thumb_func_start FUN_080bea80
FUN_080bea80: @ 0x080BEA80
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r6, r1, #0
	movs r4, #0
	movs r5, #0
	ldr r0, _080BEAD4 @ =0x0836D9B4
	mov r8, r0
_080BEA92:
	ldr r0, _080BEAD8 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r1, r0, #0
	cmp r1, #0
	beq _080BEAC4
	adds r2, r1, #0
	adds r2, #0x25
	movs r0, #1
	strb r0, [r2]
	movs r0, #0x2d
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
	strb r4, [r1, #0x11]
	str r7, [r1, #0x54]
	str r6, [r1, #0x58]
_080BEAC4:
	adds r4, #1
	cmp r4, #3
	ble _080BEA92
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BEAD4: .4byte 0x0836D9B4
_080BEAD8: .4byte gVFXHeaderPtr

	thumb_func_start VFX45_Init
VFX45_Init: @ 0x080BEADC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BEB1C @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080BEB20 @ =0x0836EFFC
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
	bl VFX45_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BEB1C: .4byte gVFXFnTable
_080BEB20: .4byte 0x0836EFFC

	thumb_func_start VFX45_Update
VFX45_Update: @ 0x080BEB24
	push {lr}
	ldr r2, _080BEB38 @ =0x0836EFF8
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080BEB38: .4byte 0x0836EFF8

	thumb_func_start VFX45_Die
VFX45_Die: @ 0x080BEB3C
	ldr r2, _080BEB50 @ =gVFXFnTable
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
_080BEB50: .4byte gVFXFnTable

	thumb_func_start FUN_080beb54
FUN_080beb54: @ 0x080BEB54
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r4, [r7, #0x11]
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _080BEB66
	cmp r0, #1
	beq _080BEBBC
	b _080BEC2A
_080BEB66:
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080BEBD0 @ =0x0836EFFE
	lsls r0, r4, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	subs r1, r4, #1
	lsls r1, r1, #8
	ldr r6, _080BEBD4 @ =RNG_0202f388
	ldr r0, [r6]
	ldr r5, _080BEBD8 @ =0x000343FD
	muls r0, r5, r0
	ldr r4, _080BEBDC @ =0x00269EC3
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r3, r0, #1
	lsls r0, r0, #6
	lsrs r0, r0, #0x17
	adds r1, r1, r0
	ldr r2, _080BEBE0 @ =0xFFFFFF00
	adds r1, r1, r2
	str r1, [r7, #0x5c]
	adds r0, r3, #0
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	movs r1, #0xff
	ands r0, r1
	subs r2, r2, r0
	str r2, [r7, #0x60]
	movs r0, #0x20
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080BEBBC:
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080BEBE4
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080BEBEA
	.align 2, 0
_080BEBD0: .4byte 0x0836EFFE
_080BEBD4: .4byte RNG_0202f388
_080BEBD8: .4byte 0x000343FD
_080BEBDC: .4byte 0x00269EC3
_080BEBE0: .4byte 0xFFFFFF00
_080BEBE4:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080BEBEA:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r1, #0x40
	str r1, [r7, #0x60]
	adds r0, r7, #0
	bl FUN_0801779c
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _080BEC2A
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080BEC30 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r7, #0x14]
_080BEC2A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BEC30: .4byte gVFXFnTable
