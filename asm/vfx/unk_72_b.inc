	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
_080C6DB8: .4byte motion_t_ARRAY_0836f85a
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
	bl UpdateEntityAnim
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
