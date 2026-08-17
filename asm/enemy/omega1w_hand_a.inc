	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0806a8fc
FUN_0806a8fc: @ 0x0806A8FC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r3, [r4, #0xe]
	cmp r3, #1
	beq _0806A9DE
	cmp r3, #1
	bgt _0806A910
	cmp r3, #0
	beq _0806A91E
	b _0806AA4C
_0806A910:
	cmp r3, #2
	bne _0806A916
	b _0806AA2C
_0806A916:
	cmp r3, #3
	bne _0806A91C
	b _0806AA44
_0806A91C:
	b _0806AA4C
_0806A91E:
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _0806A970
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4d
	strb r3, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x24
	strb r3, [r0]
	ldr r1, _0806A96C @ =0x00000901
	adds r0, r4, #0
	bl SetMotion
	b _0806A9B8
	.align 2, 0
_0806A96C: .4byte 0x00000901
_0806A970:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4d
	strb r3, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x24
	strb r3, [r0]
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r4, #0
	bl SetMotion
_0806A9B8:
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r2, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r4, #0xa]
	str r1, [r4, #0x5c]
	str r1, [r4, #0x60]
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806A9DE:
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _0806A9F2
	ldr r1, [r4, #0x28]
	ldr r2, [r4, #0x58]
	movs r3, #0xe0
	lsls r3, r3, #6
	adds r0, r2, r3
	ldr r1, [r1, #0x58]
	b _0806AA16
_0806A9F2:
	ldr r3, [r4, #0x28]
	ldr r2, [r4, #0x54]
	movs r1, #0x98
	lsls r1, r1, #5
	adds r0, r2, r1
	ldr r1, [r3, #0x54]
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x54]
	ldr r2, [r4, #0x58]
	movs r1, #0xe8
	lsls r1, r1, #6
	adds r0, r2, r1
	ldr r1, [r3, #0x58]
_0806AA16:
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _0806AA4C
_0806AA2C:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0806AA4C
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806AA4C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0806AA4C
_0806AA44:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806AA4C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0806aa54
FUN_0806aa54: @ 0x0806AA54
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0806AA90
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0806AA98 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_0806AA90:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806AA98: .4byte gEnemyFnTable

	thumb_func_start FUN_0806aa9c
FUN_0806aa9c: @ 0x0806AA9C
	movs r0, #1
	bx lr
