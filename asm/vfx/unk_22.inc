	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080b7b38
FUN_080b7b38: @ 0x080B7B38
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080B7B84 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080B7B7A
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080B7B88 @ =gVFXFnTable
	movs r0, #0x16
	strb r0, [r3, #9]
	ldr r0, [r1, #0x58]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r5, [r3, #0x10]
	strb r0, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
_080B7B7A:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080B7B84: .4byte gVFXHeaderPtr
_080B7B88: .4byte gVFXFnTable

	thumb_func_start FUN_080b7b8c
FUN_080b7b8c: @ 0x080B7B8C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	mov r8, r3
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	ldr r0, _080B7BEC @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080B7BE0
	adds r0, #0x25
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r1, _080B7BF0 @ =gVFXFnTable
	movs r0, #0x16
	strb r0, [r4, #9]
	ldr r0, [r1, #0x58]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r3, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r6, [r4, #0x10]
	strb r2, [r4, #0x11]
	ldr r0, [r5]
	str r0, [r4, #0x54]
	ldr r0, [r5, #4]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0x74
	strh r7, [r0]
	mov r0, r8
	str r0, [r4, #0x78]
_080B7BE0:
	adds r0, r4, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080B7BEC: .4byte gVFXHeaderPtr
_080B7BF0: .4byte gVFXFnTable

	thumb_func_start Ghost22_Init
Ghost22_Init: @ 0x080B7BF4
	push {r4, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r3, #0
	adds r2, r0, #0
	orrs r2, r1
	movs r0, #2
	orrs r2, r0
	orrs r2, r3
	strb r2, [r4, #0xa]
	ldrb r1, [r4, #0x10]
	cmp r1, #0
	bne _080B7C30
	movs r0, #0xef
	ands r2, r0
	strb r2, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _080B7C50
_080B7C30:
	movs r1, #1
	movs r0, #0x10
	orrs r2, r0
	strb r2, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_080B7C50:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080B7C5C
	movs r0, #0x80
	rsbs r0, r0, #0
	b _080B7C5E
_080B7C5C:
	movs r0, #0x80
_080B7C5E:
	str r0, [r4, #0x5c]
	movs r3, #0
	str r3, [r4, #0x60]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _080B7C88
	movs r0, #0xff
	strb r0, [r4, #0x12]
	ldr r1, _080B7C84 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r1, [r4, #0xd]
	b _080B7CBA
	.align 2, 0
_080B7C84: .4byte gVFXFnTable
_080B7C88:
	ldr r2, _080B7CCC @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080B7CD0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080B7CD4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #7
	ands r0, r1
	adds r0, #0x7f
	strb r0, [r4, #0x12]
	ldr r1, _080B7CD8 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	movs r0, #2
	strb r0, [r4, #0xd]
_080B7CBA:
	strb r3, [r4, #0xe]
	strb r3, [r4, #0xf]
	adds r0, r4, #0
	bl Ghost22_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B7CCC: .4byte RNG_0202f388
_080B7CD0: .4byte 0x000343FD
_080B7CD4: .4byte 0x00269EC3
_080B7CD8: .4byte gVFXFnTable

	thumb_func_start Ghost22_Update
Ghost22_Update: @ 0x080B7CDC
	push {lr}
	adds r2, r0, #0
	ldr r0, _080B7D08 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080B7D10
	ldr r1, _080B7D0C @ =gVFXFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	adds r0, r2, #0
	bl Ghost22_Die
	b _080B7D20
	.align 2, 0
_080B7D08: .4byte gCurStory
_080B7D0C: .4byte gVFXFnTable
_080B7D10:
	ldr r0, _080B7D24 @ =0x0836E9E4
	ldrb r1, [r2, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_080B7D20:
	pop {r0}
	bx r0
	.align 2, 0
_080B7D24: .4byte 0x0836E9E4

	thumb_func_start Ghost22_Die
Ghost22_Die: @ 0x080B7D28
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080B7D44 @ =gVFXFnTable
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
_080B7D44: .4byte gVFXFnTable

	thumb_func_start nop_080b7d48
nop_080b7d48: @ 0x080B7D48
	bx lr
	.align 2, 0

	thumb_func_start FUN_080b7d4c
FUN_080b7d4c: @ 0x080B7D4C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B7DE4
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	ldr r2, _080B7DCC @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080B7DD0 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080B7DD4 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	str r0, [sp, #4]
	ldrb r1, [r6, #0x10]
	ldr r2, _080B7DD8 @ =0x00001804
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080b7b8c
	ldrb r1, [r6, #0x10]
	ldr r5, _080B7DDC @ =0x00001805
	mov r0, sp
	adds r2, r5, #0
	adds r3, r4, #0
	bl FUN_080b7b8c
	ldrb r1, [r6, #0x10]
	mov r0, sp
	adds r2, r5, #0
	adds r3, r4, #0
	bl FUN_080b7b8c
	movs r0, #0x31
	bl PlaySound
	ldr r1, _080B7DE0 @ =gVFXFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	b _080B7E2C
	.align 2, 0
_080B7DCC: .4byte RNG_0202f388
_080B7DD0: .4byte 0x000343FD
_080B7DD4: .4byte 0x00269EC3
_080B7DD8: .4byte 0x00001804
_080B7DDC: .4byte 0x00001805
_080B7DE0: .4byte gVFXFnTable
_080B7DE4:
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _080B7DF0
	cmp r0, #1
	beq _080B7E06
	b _080B7E2C
_080B7DF0:
	movs r0, #0x32
	strb r0, [r6, #0x12]
	ldr r0, _080B7E34 @ =0xFFFFFF00
	str r0, [r6, #0x60]
	ldr r1, _080B7E38 @ =0x00001802
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080B7E06:
	ldr r0, [r6, #0x60]
	adds r0, #0x10
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080B7E16
	str r1, [r6, #0x60]
_080B7E16:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	adds r0, r6, #0
	bl UpdateMotionGraphic
_080B7E2C:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B7E34: .4byte 0xFFFFFF00
_080B7E38: .4byte 0x00001802

	thumb_func_start FUN_080b7e3c
FUN_080b7e3c: @ 0x080B7E3C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080B7E72
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080B7E94
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080B7E94
	ldr r0, [r7, #0x60]
	cmp r0, #0
	ble _080B7E94
_080B7E72:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	ldr r1, _080B7E90 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	b _080B7F62
	.align 2, 0
_080B7E90: .4byte gVFXFnTable
_080B7E94:
	ldrb r0, [r7, #0xe]
	mov sb, r0
	cmp r0, #0
	beq _080B7EA2
	cmp r0, #1
	beq _080B7F0C
	b _080B7F62
_080B7EA2:
	ldr r4, _080B7F24 @ =0x0836EA50
	movs r1, #0x74
	adds r1, r1, r7
	mov r8, r1
	ldrh r0, [r1]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xe
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r2, [r7, #0x78]
	lsls r2, r2, #3
	adds r2, r2, r0
	ldr r3, _080B7F28 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r6, _080B7F2C @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r5, _080B7F30 @ =0x00269EC3
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r4, r1, #1
	str r4, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x1f
	ands r1, r0
	ldr r0, [r2, #4]
	adds r0, r0, r1
	str r0, [r7, #0x60]
	adds r1, r4, #0
	muls r1, r6, r1
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x3f
	ands r1, r0
	ldr r0, [r2]
	subs r0, r0, r1
	str r0, [r7, #0x5c]
	mov r0, r8
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	mov r1, sb
	strb r1, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080B7F0C:
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	movs r1, #0xff
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080B7F34
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080B7F3A
	.align 2, 0
_080B7F24: .4byte 0x0836EA50
_080B7F28: .4byte RNG_0202f388
_080B7F2C: .4byte 0x000343FD
_080B7F30: .4byte 0x00269EC3
_080B7F34:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080B7F3A:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x60]
	adds r0, #0x10
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080B7F4C
	str r1, [r7, #0x60]
_080B7F4C:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	bl UpdateMotionGraphic
_080B7F62:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
