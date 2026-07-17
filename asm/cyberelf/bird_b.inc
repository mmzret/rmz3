	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080e5b74
FUN_080e5b74: @ 0x080E5B74
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r0, #0xb4
	ldr r7, [r0]
	ldrb r2, [r5, #0xe]
	cmp r2, #0
	bne _080E5B9A
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r5, #0x5c]
	adds r0, r2, #1
	strb r0, [r5, #0xe]
_080E5B9A:
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080E5BD2
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080E5BC6
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r0, [r3]
	movs r1, #0xd8
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r7, #0x54]
	subs r6, r1, r0
	adds r2, r5, #0
	adds r2, #0xbc
	ldr r0, [r2]
	movs r1, #0x98
	lsls r1, r1, #5
	b _080E5C10
_080E5BC6:
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r0, [r3]
	movs r2, #0xd0
	lsls r2, r2, #4
	b _080E5C00
_080E5BD2:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080E5BF8
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r0, [r3]
	ldr r2, _080E5BF4 @ =0xFFFFE500
	adds r0, r0, r2
	ldr r1, [r7, #0x54]
	subs r6, r1, r0
	adds r2, r5, #0
	adds r2, #0xbc
	ldr r0, [r2]
	movs r1, #0x98
	lsls r1, r1, #5
	b _080E5C10
	.align 2, 0
_080E5BF4: .4byte 0xFFFFE500
_080E5BF8:
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r0, [r3]
	ldr r2, _080E5C58 @ =0xFFFFF300
_080E5C00:
	adds r0, r0, r2
	ldr r1, [r7, #0x54]
	subs r6, r1, r0
	adds r2, r5, #0
	adds r2, #0xbc
	ldr r0, [r2]
	movs r1, #0xa4
	lsls r1, r1, #6
_080E5C10:
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	subs r4, r1, r0
	mov r8, r3
	mov sb, r2
	adds r0, r6, #0
	adds r1, r4, #0
	bl CalcAngle
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r1, r6, #0
	cmp r6, #0
	bge _080E5C2E
	rsbs r1, r6, #0
_080E5C2E:
	adds r0, r4, #0
	cmp r4, #0
	bge _080E5C36
	rsbs r0, r4, #0
_080E5C36:
	cmp r1, r0
	ble _080E5C60
	adds r1, r6, #0
	cmp r1, #0
	bge _080E5C42
	rsbs r1, r1, #0
_080E5C42:
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	ble _080E5C84
	ldr r1, [r5, #0x5c]
	ldr r0, _080E5C5C @ =0x000005FF
	cmp r1, r0
	bgt _080E5C96
	adds r0, r1, #0
	adds r0, #0x80
	b _080E5C94
	.align 2, 0
_080E5C58: .4byte 0xFFFFF300
_080E5C5C: .4byte 0x000005FF
_080E5C60:
	adds r1, r4, #0
	cmp r1, #0
	bge _080E5C68
	rsbs r1, r1, #0
_080E5C68:
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	ble _080E5C84
	ldr r1, [r5, #0x5c]
	ldr r0, _080E5C80 @ =0x000005FF
	cmp r1, r0
	bgt _080E5C96
	adds r0, r1, #0
	adds r0, #0x80
	b _080E5C94
	.align 2, 0
_080E5C80: .4byte 0x000005FF
_080E5C84:
	ldr r0, [r5, #0x5c]
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	ble _080E5C90
	str r1, [r5, #0x5c]
_080E5C90:
	ldr r0, [r5, #0x5c]
	subs r0, #0x20
_080E5C94:
	str r0, [r5, #0x5c]
_080E5C96:
	ldr r0, [r5, #0x5c]
	cmp r0, #0xbf
	bgt _080E5CA0
	movs r0, #0xc0
	str r0, [r5, #0x5c]
_080E5CA0:
	mov r6, r8
	ldr r3, _080E5D1C @ =gSineTable
	mov ip, r3
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	add r0, ip
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, [r5, #0x5c]
	muls r1, r0, r1
	asrs r1, r1, #8
	ldr r0, [r6]
	adds r0, r0, r1
	str r0, [r6]
	mov r4, sb
	lsls r0, r2, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r5, #0x5c]
	muls r1, r0, r1
	asrs r1, r1, #8
	ldr r0, [r4]
	adds r0, r0, r1
	str r0, [r4]
	adds r1, r5, #0
	adds r1, #0xc0
	ldrb r2, [r1]
	adds r3, r2, #1
	adds r0, r3, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r3, r0
	strb r0, [r1]
	ldrb r3, [r1]
	lsls r2, r3, #3
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080E5D20
	movs r0, #0x3f
	subs r0, r0, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	add r0, ip
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r1, r1, #2
	ldr r0, [r6]
	subs r0, r0, r1
	str r0, [r5, #0x54]
	mvns r0, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #2
	ldr r0, [r4]
	subs r0, r0, r1
	b _080E5D4A
	.align 2, 0
_080E5D1C: .4byte gSineTable
_080E5D20:
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #2
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	lsls r0, r3, #0x1b
	lsrs r0, r0, #0x17
	add r0, ip
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r1, r1, #2
	mov r2, sb
	ldr r0, [r2]
	adds r0, r0, r1
_080E5D4A:
	str r0, [r5, #0x58]
	ldrb r0, [r7, #0xd]
	cmp r0, #8
	bne _080E5D5C
	ldrb r0, [r5, #0xd]
	adds r0, #1
	movs r1, #0
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_080E5D5C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080e5d68
FUN_080e5d68: @ 0x080E5D68
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	mov sb, r0
	ldrb r1, [r7, #0xe]
	cmp r1, #0
	bne _080E5D8A
	adds r0, r7, #0
	adds r0, #0xc0
	strb r1, [r0]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080E5D8A:
	adds r6, r7, #0
	adds r6, #0xb8
	mov r1, sb
	ldr r0, [r1, #0x54]
	str r0, [r6]
	movs r2, #0xbc
	adds r2, r2, r7
	mov r8, r2
	ldr r0, [r1, #0x58]
	ldr r1, _080E5E18 @ =0xFFFFE000
	adds r0, r0, r1
	str r0, [r2]
	adds r4, r7, #0
	adds r4, #0xc0
	ldrb r0, [r4]
	adds r0, #1
	movs r1, #0x30
	bl __modsi3
	adds r5, r0, #0
	strb r5, [r4]
	movs r1, #0x30
	bl __modsi3
	lsls r0, r0, #8
	movs r1, #0x30
	bl __divsi3
	ldr r4, _080E5E1C @ =gSineTable
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #3
	ldr r0, [r6]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r5, #0
	movs r1, #0x18
	bl __modsi3
	lsls r0, r0, #8
	movs r1, #0x18
	bl __divsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #3
	mov r2, r8
	ldr r0, [r2]
	subs r0, r0, r1
	str r0, [r7, #0x58]
	movs r0, #0x90
	lsls r0, r0, #1
	add r0, sb
	ldrb r1, [r0]
	cmp r1, #0x3b
	bhi _080E5E28
	movs r0, #3
	ands r0, r1
	cmp r0, #1
	bhi _080E5E20
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080E5E26
	.align 2, 0
_080E5E18: .4byte 0xFFFFE000
_080E5E1C: .4byte gSineTable
_080E5E20:
	ldrb r0, [r7, #0xa]
	movs r1, #1
	orrs r0, r1
_080E5E26:
	strb r0, [r7, #0xa]
_080E5E28:
	mov r1, sb
	ldrb r0, [r1, #0xd]
	cmp r0, #8
	beq _080E5E36
	movs r0, #0
	strb r0, [r7, #0xd]
	strb r0, [r7, #0xe]
_080E5E36:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

