	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080bdaf8
FUN_080bdaf8: @ 0x080BDAF8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _080BDB3C @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080BDB34
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BDB40 @ =gVFXFnTable
	movs r1, #0x28
	strb r1, [r3, #9]
	adds r0, #0xa0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
	strb r0, [r3, #0x10]
_080BDB34:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BDB3C: .4byte gVFXHeaderPtr
_080BDB40: .4byte gVFXFnTable

	thumb_func_start FUN_080bdb44
FUN_080bdb44: @ 0x080BDB44
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	adds r7, r1, #0
	movs r4, #0
	movs r6, #0
	movs r5, #1
	ldr r0, _080BDB9C @ =0x0836D9A0
	mov sb, r0
_080BDB5A:
	ldr r0, _080BDBA0 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r1, r0, #0
	cmp r1, #0
	beq _080BDB8A
	adds r0, #0x25
	strb r5, [r0]
	movs r0, #0x28
	strb r0, [r1, #9]
	mov r2, sb
	ldr r0, [r2]
	ldr r0, [r0]
	str r0, [r1, #0x14]
	strh r6, [r1, #0x20]
	adds r0, r1, #0
	adds r0, #0x22
	strb r6, [r0]
	strb r5, [r1, #0x10]
	strb r4, [r1, #0x11]
	mov r0, r8
	str r0, [r1, #0x54]
	str r7, [r1, #0x58]
_080BDB8A:
	adds r4, #1
	cmp r4, #2
	ble _080BDB5A
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BDB9C: .4byte 0x0836D9A0
_080BDBA0: .4byte gVFXHeaderPtr

	thumb_func_start VFX40_Init
VFX40_Init: @ 0x080BDBA4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BDBE4 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080BDBE8 @ =0x0836EEDC
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
	bl VFX40_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BDBE4: .4byte gVFXFnTable
_080BDBE8: .4byte 0x0836EEDC

	thumb_func_start VFX40_Update
VFX40_Update: @ 0x080BDBEC
	push {lr}
	ldr r2, _080BDC00 @ =0x0836EED4
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080BDC00: .4byte 0x0836EED4

	thumb_func_start VFX40_Die
VFX40_Die: @ 0x080BDC04
	ldr r2, _080BDC18 @ =gVFXFnTable
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
_080BDC18: .4byte gVFXFnTable

	thumb_func_start FUN_080bdc1c
FUN_080bdc1c: @ 0x080BDC1C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080BDC2C
	cmp r0, #1
	beq _080BDC3C
	b _080BDC68
_080BDC2C:
	movs r1, #0xdc
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BDC3C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r2, [r0]
	cmp r2, #3
	bne _080BDC68
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080BDC70 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080BDC68:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BDC70: .4byte gVFXFnTable

	thumb_func_start FUN_080bdc74
FUN_080bdc74: @ 0x080BDC74
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r4, [r7, #0x11]
	ldrb r6, [r7, #0xe]
	cmp r6, #0
	beq _080BDC86
	cmp r6, #1
	beq _080BDCE6
	b _080BDD6A
_080BDC86:
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldr r1, _080BDCFC @ =0x0836EEDE
	lsls r0, r4, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	subs r1, r4, #1
	lsls r1, r1, #8
	ldr r0, _080BDD00 @ =RNG_0202f388
	mov ip, r0
	ldr r0, [r0]
	ldr r5, _080BDD04 @ =0x000343FD
	muls r0, r5, r0
	ldr r3, _080BDD08 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsrs r0, r0, #0x11
	ldr r4, _080BDD0C @ =0x000001FF
	ands r0, r4
	adds r1, r1, r0
	ldr r0, _080BDD10 @ =0xFFFFFF00
	adds r1, r1, r0
	str r1, [r7, #0x5c]
	adds r0, r2, #0
	muls r0, r5, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r2, ip
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r4
	ldr r1, _080BDD14 @ =0xFFFFFE00
	subs r1, r1, r0
	str r1, [r7, #0x60]
	strb r6, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080BDCE6:
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080BDD18
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080BDD1E
	.align 2, 0
_080BDCFC: .4byte 0x0836EEDE
_080BDD00: .4byte RNG_0202f388
_080BDD04: .4byte 0x000343FD
_080BDD08: .4byte 0x00269EC3
_080BDD0C: .4byte 0x000001FF
_080BDD10: .4byte 0xFFFFFF00
_080BDD14: .4byte 0xFFFFFE00
_080BDD18:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080BDD1E:
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
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080BDD6A
	ldr r0, [r7, #0x60]
	cmp r0, #0
	ble _080BDD6A
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	ldr r1, _080BDD70 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080BDD6A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BDD70: .4byte gVFXFnTable
