	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c6a1c
FUN_080c6a1c: @ 0x080C6A1C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r6, [r5, #0x28]
	movs r0, #0x54
	adds r0, r0, r6
	mov r8, r0
	ldrb r4, [r6, #0xa]
	lsrs r4, r4, #4
	movs r0, #1
	ands r4, r0
	ldrb r1, [r5, #0xa]
	movs r7, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldr r1, _080C6A58 @ =0x0000DB0A
	adds r0, r5, #0
	bl SetMotion
	cmp r4, #0
	beq _080C6A5C
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080C6A62
	.align 2, 0
_080C6A58: .4byte 0x0000DB0A
_080C6A5C:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080C6A62:
	strb r0, [r5, #0xa]
	movs r7, #1
	adds r1, r7, #0
	ands r1, r4
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
	mov r1, r8
	ldr r0, [r1]
	str r0, [r5, #0x54]
	ldr r0, [r1, #4]
	str r0, [r5, #0x58]
	ldr r1, [r6, #0x5c]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #5
	cmp r0, #0
	bge _080C6A9A
	adds r0, #0xff
_080C6A9A:
	asrs r0, r0, #8
	str r0, [r5, #0x5c]
	ldr r0, [r6, #0x60]
	str r0, [r5, #0x60]
	movs r1, #0
	ldrb r0, [r6, #0xf]
	cmp r0, #1
	bne _080C6AAC
	movs r1, #1
_080C6AAC:
	strb r1, [r5, #0x13]
	movs r0, #0x16
	strb r0, [r5, #0x12]
	ldr r1, _080C6AD4 @ =gVFXFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r7, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl Ghost72_Update
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C6AD4: .4byte gVFXFnTable

	thumb_func_start FUN_080c6ad8
FUN_080c6ad8: @ 0x080C6AD8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	movs r0, #0xe6
	muls r0, r1, r0
	cmp r0, #0
	bge _080C6AEE
	adds r0, #0xff
_080C6AEE:
	asrs r0, r0, #8
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _080C6B08
	ldr r0, [r5, #0x60]
	adds r0, #0x20
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C6B08
	str r1, [r5, #0x60]
_080C6B08:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _080C6B2E
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080C6B40
	movs r0, #0
	strb r0, [r5, #0x12]
	b _080C6B40
_080C6B2E:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	ldr r0, [r5, #0x58]
	cmp r0, r1
	ble _080C6B40
	str r1, [r5, #0x58]
_080C6B40:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _080C6B6C
	ldr r0, [r5, #0x28]
	adds r4, r5, #0
	adds r4, #0x54
	adds r1, r4, #0
	bl FUN_080c68cc
	movs r0, #1
	adds r1, r4, #0
	bl CreateSmoke
	ldr r1, _080C6B74 @ =gVFXFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_080C6B6C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C6B74: .4byte gVFXFnTable

	thumb_func_start FUN_080c6b78
FUN_080c6b78: @ 0x080C6B78
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xa]
	lsrs r4, r0, #4
	movs r0, #1
	ands r4, r0
	ldrb r5, [r7, #0x11]
	ldrb r1, [r7, #0xa]
	movs r6, #0
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	bl InitNonAffineMotion
	adds r2, r4, #0
	cmp r4, #0
	beq _080C6BA8
	ldrb r0, [r7, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080C6BAE
_080C6BA8:
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
_080C6BAE:
	strb r0, [r7, #0xa]
	movs r0, #1
	mov r8, r0
	mov r1, r8
	ands r1, r2
	adds r0, r7, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, _080C6C40 @ =0x0836F854
	lsls r0, r5, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	cmp r4, #0
	beq _080C6BE6
	movs r0, #2
	subs r5, r0, r5
_080C6BE6:
	subs r1, r5, #1
	lsls r1, r1, #8
	ldr r6, _080C6C44 @ =RNG_0202f388
	ldr r0, [r6]
	ldr r5, _080C6C48 @ =0x000343FD
	muls r0, r5, r0
	ldr r3, _080C6C4C @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsrs r0, r0, #0x11
	ldr r4, _080C6C50 @ =0x000001FF
	ands r0, r4
	adds r1, r1, r0
	ldr r0, _080C6C54 @ =0xFFFFFF00
	adds r1, r1, r0
	str r1, [r7, #0x5c]
	adds r0, r2, #0
	muls r0, r5, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	ands r0, r4
	ldr r1, _080C6C58 @ =0xFFFFFE00
	subs r1, r1, r0
	str r1, [r7, #0x60]
	ldr r1, _080C6C5C @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	mov r1, r8
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl Ghost72_Update
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C6C40: .4byte 0x0836F854
_080C6C44: .4byte RNG_0202f388
_080C6C48: .4byte 0x000343FD
_080C6C4C: .4byte 0x00269EC3
_080C6C50: .4byte 0x000001FF
_080C6C54: .4byte 0xFFFFFF00
_080C6C58: .4byte 0xFFFFFE00
_080C6C5C: .4byte gVFXFnTable

	thumb_func_start FUN_080c6c60
FUN_080c6c60: @ 0x080C6C60
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080C6C92
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _080C6C98
_080C6C92:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080C6C98:
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080C6CC4
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	ldr r1, _080C6CCC @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080C6CC4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C6CCC: .4byte gVFXFnTable

	thumb_func_start FUN_080c6cd0
FUN_080c6cd0: @ 0x080C6CD0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	adds r7, r0, #0
	adds r7, #0x54
	ldrb r4, [r0, #0xa]
	lsrs r4, r4, #4
	movs r0, #1
	ands r4, r0
	ldrb r0, [r5, #0x11]
	mov r8, r0
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r6, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	cmp r4, #0
	beq _080C6D06
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080C6D0C
_080C6D06:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080C6D0C:
	strb r0, [r5, #0xa]
	movs r6, #1
	adds r1, r6, #0
	ands r1, r4
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
	ldr r1, _080C6DB8 @ =0x0836F85A
	mov r2, r8
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl SetMotion
	ldr r0, [r7]
	str r0, [r5, #0x54]
	ldr r0, [r7, #4]
	str r0, [r5, #0x58]
	ldrb r1, [r5, #0x12]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	movs r2, #0xc0
	lsls r2, r2, #1
	subs r2, r2, r0
	str r2, [r5, #0x5c]
	ldrb r1, [r5, #0x11]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r0, r1
	muls r0, r2, r0
	cmp r0, #0
	bge _080C6D6A
	adds r0, #0xff
_080C6D6A:
	asrs r0, r0, #8
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0x11]
	movs r2, #1
	eors r2, r0
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #6
	ldr r0, _080C6DBC @ =0xFFFFFE00
	subs r0, r0, r1
	str r0, [r5, #0x60]
	adds r2, #2
	adds r3, r5, #0
	adds r3, #0x49
	movs r0, #3
	ands r2, r0
	lsls r2, r2, #2
	ldrb r1, [r3]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldr r1, _080C6DC0 @ =gVFXFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r6, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl Ghost72_Update
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C6DB8: .4byte 0x0836F85A
_080C6DBC: .4byte 0xFFFFFE00
_080C6DC0: .4byte gVFXFnTable

	thumb_func_start FUN_080c6dc4
FUN_080c6dc4: @ 0x080C6DC4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080C6E18
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	ldrb r0, [r4, #0x11]
	cmp r0, #1
	bne _080C6E06
	movs r0, #0x2a
	bl PlaySound
_080C6E06:
	ldr r1, _080C6E20 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080C6E18:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C6E20: .4byte gVFXFnTable

