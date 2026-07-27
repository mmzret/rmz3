	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08075aa8
FUN_08075aa8: @ 0x08075AA8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r6, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r5, #0x80
	lsls r5, r5, #2
	adds r1, r1, r5
	bl FUN_0800a40c
	adds r2, r0, #0
	cmp r2, #0
	beq _08075B12
	cmp r2, #0
	bge _08075AF0
	ldr r0, [r4, #0x54]
	adds r1, r0, #0
	subs r1, #0x80
	str r1, [r4, #0x54]
	ldr r1, _08075AEC @ =0xFFFFFD80
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	adds r1, r1, r5
	bl GetMetatileAttr
	movs r1, #0x80
	lsls r1, r1, #3
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	rsbs r1, r1, #0
	lsrs r6, r1, #0x1f
	b _08075B2C
	.align 2, 0
_08075AEC: .4byte 0xFFFFFD80
_08075AF0:
	ldr r1, [r4, #0x54]
	adds r0, r1, #0
	adds r0, #0x80
	str r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r0, r1, r2
	ldr r1, [r4, #0x58]
	adds r1, r1, r5
	bl GetMetatileAttr
	movs r1, #0x80
	lsls r1, r1, #3
	ands r1, r0
	cmp r1, #0
	beq _08075B2C
	b _08075B68
_08075B12:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	bl GetMetatileAttr
	movs r1, #0x80
	lsls r1, r1, #3
	ands r1, r0
	cmp r1, #0
	beq _08075B2C
	movs r6, #1
_08075B2C:
	cmp r6, #0
	bne _08075B68
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0xc0
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08075B6E
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r3, [r4, #0x58]
	subs r2, r2, r3
	ldr r0, _08075B60 @ =0x000003FF
	adds r1, r2, r0
	ldr r0, _08075B64 @ =0x000007FE
	cmp r1, r0
	bhi _08075B6E
	adds r0, r3, r2
	b _08075B6C
	.align 2, 0
_08075B60: .4byte 0x000003FF
_08075B64: .4byte 0x000007FE
_08075B68:
	ldr r0, [r4, #0x58]
	adds r0, #0x80
_08075B6C:
	str r0, [r4, #0x58]
_08075B6E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08075b74
FUN_08075b74: @ 0x08075B74
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _08075BC8 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08075BC2
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _08075BCC @ =gEnemyFnTable
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
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	movs r0, #1
	strb r0, [r3, #0x10]
	str r5, [r3, #0x28]
	adds r0, r3, #0
	adds r0, #0xb9
	strb r4, [r0]
_08075BC2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08075BC8: .4byte gEnemyHeaderPtr
_08075BCC: .4byte gEnemyFnTable

	thumb_func_start FUN_08075bd0
FUN_08075bd0: @ 0x08075BD0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r4, #0
	movs r6, #0
	ldr r7, _08075C38 @ =gEnemyFnTable
_08075BDE:
	ldr r0, _08075C3C @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r2, r0, #0
	cmp r2, #0
	beq _08075C26
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #0x18
	strb r0, [r1]
	movs r0, #0x16
	strb r0, [r2, #9]
	ldr r0, [r7, #0x58]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	strh r6, [r2, #0x20]
	adds r0, r2, #0
	adds r0, #0x22
	strb r6, [r0]
	ldrb r0, [r2, #0xb]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #0xb]
	ldrb r0, [r2, #0x1c]
	strb r0, [r2, #0x1d]
	movs r0, #2
	strb r0, [r2, #0x10]
	strb r4, [r2, #0x11]
	ldr r0, [r5, #0x54]
	str r0, [r2, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r2, #0x58]
	adds r0, r2, #0
	adds r0, #0xb9
	strb r6, [r0]
_08075C26:
	adds r4, #1
	cmp r4, #1
	ble _08075BDE
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08075C38: .4byte gEnemyFnTable
_08075C3C: .4byte gEnemyHeaderPtr

	thumb_func_start FUN_08075c40
FUN_08075c40: @ 0x08075C40
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, _08075CB8 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08075CB0
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _08075CBC @ =gEnemyFnTable
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
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	movs r0, #2
	strb r0, [r3, #0x10]
	ldr r2, _08075CC0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08075CC4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08075CC8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	strb r0, [r3, #0x11]
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
	str r6, [r3, #0x5c]
	str r7, [r3, #0x60]
	adds r0, r3, #0
	adds r0, #0xb9
	strb r1, [r0]
_08075CB0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08075CB8: .4byte gEnemyHeaderPtr
_08075CBC: .4byte gEnemyFnTable
_08075CC0: .4byte RNG_0202f388
_08075CC4: .4byte 0x000343FD
_08075CC8: .4byte 0x00269EC3

	thumb_func_start summonPurpleNerple
summonPurpleNerple: @ 0x08075CCC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _08075D2C @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08075D26
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _08075D30 @ =gEnemyFnTable
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
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	movs r0, #3
	strb r0, [r3, #0x10]
	str r5, [r3, #0x54]
	ldr r0, _08075D34 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r1, _08075D38 @ =0xFFFF9000
	adds r0, r0, r1
	str r0, [r3, #0x58]
	str r4, [r3, #0x28]
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r4, #0x54]
	str r0, [r1]
_08075D26:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08075D2C: .4byte gEnemyHeaderPtr
_08075D30: .4byte gEnemyFnTable
_08075D34: .4byte gStageRun+232
_08075D38: .4byte 0xFFFF9000
