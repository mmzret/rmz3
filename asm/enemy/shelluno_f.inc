	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start shelluno_0807a100
shelluno_0807a100: @ 0x0807A100
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0807A110
	cmp r0, #1
	beq _0807A170
	b _0807A23A
_0807A110:
	adds r1, r5, #0
	adds r1, #0xb9
	movs r4, #1
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x20
	strb r0, [r5, #0x12]
	ldr r1, _0807A14C @ =0x00003509
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807A150 @ =0x083675FC
	bl SetDDP
	ldr r0, _0807A154 @ =pZero2
	ldr r0, [r0]
	ldrb r0, [r0, #0xa]
	lsrs r0, r0, #4
	ands r0, r4
	strb r0, [r5, #0xf]
	cmp r0, #0
	bne _0807A15C
	ldr r0, _0807A158 @ =0xFFFFFD80
	str r0, [r5, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #1
	b _0807A164
	.align 2, 0
_0807A14C: .4byte 0x00003509
_0807A150: .4byte 0x083675FC
_0807A154: .4byte pZero2
_0807A158: .4byte 0xFFFFFD80
_0807A15C:
	movs r0, #0xa0
	lsls r0, r0, #2
	str r0, [r5, #0x5c]
	ldr r0, _0807A1A8 @ =0xFFFFFF00
_0807A164:
	str r0, [r5, #0x64]
	movs r0, #0
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807A170:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x60]
	adds r1, r1, r2
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0807A1B0
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0807A1B0
	ldr r1, _0807A1AC @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _0807A23A
	.align 2, 0
_0807A1A8: .4byte 0xFFFFFF00
_0807A1AC: .4byte gEnemyFnTable
_0807A1B0:
	ldr r0, [r5, #0x54]
	ldr r3, [r5, #0x5c]
	adds r0, r0, r3
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x60]
	adds r1, r1, r2
	str r1, [r5, #0x58]
	ldr r2, [r5, #0x64]
	subs r2, r2, r3
	lsls r2, r2, #3
	asrs r2, r2, #8
	adds r3, r3, r2
	str r3, [r5, #0x5c]
	ldr r2, _0807A1F8 @ =0xFFFFE000
	adds r1, r1, r2
	bl FUN_0800a05c
	adds r1, r0, #0
	ldr r0, [r5, #0x58]
	subs r0, r1, r0
	cmp r0, #0x40
	bgt _0807A1E0
	str r1, [r5, #0x58]
_0807A1E0:
	adds r0, r5, #0
	bl FUN_0807a46c
	ldrb r1, [r5, #0xf]
	cmp r1, #0
	bne _0807A1FC
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	blt _0807A208
	strb r1, [r5, #0xd]
	strb r1, [r5, #0xe]
	b _0807A208
	.align 2, 0
_0807A1F8: .4byte 0xFFFFE000
_0807A1FC:
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	bgt _0807A208
	movs r0, #0
	strb r0, [r5, #0xd]
	strb r0, [r5, #0xe]
_0807A208:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0807A234
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _0807A234
	adds r1, r5, #0
	adds r1, #0xb9
	strb r0, [r1]
	movs r1, #0xd4
	lsls r1, r1, #6
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807A240 @ =0x0836759C
	bl SetDDP
_0807A234:
	adds r0, r5, #0
	bl UpdateEntityAnim
_0807A23A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807A240: .4byte 0x0836759C

	thumb_func_start FUN_0807a244
FUN_0807a244: @ 0x0807A244
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r6, [r5]
	cmp r6, #0
	beq _0807A25C
	b _0807A3D6
_0807A25C:
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0807A26A
	b _0807A3D6
_0807A26A:
	movs r0, #0x97
	adds r0, r0, r4
	mov r8, r0
	ldrb r1, [r0]
	movs r7, #0xf0
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0x20
	beq _0807A27E
	b _0807A3A8
_0807A27E:
	ldr r5, [r4, #0x58]
	ldr r4, [r4, #0x54]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	bl CreateBubble
	ldr r1, _0807A39C @ =RNG_0202f388
	mov sl, r1
	ldr r0, [r1]
	ldr r2, _0807A3A0 @ =0x000343FD
	mov sb, r2
	mov r3, sb
	muls r3, r0, r3
	adds r0, r3, #0
	ldr r6, _0807A3A4 @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	movs r2, #0xf
	mov r8, r2
	ands r0, r2
	subs r0, #8
	lsls r0, r0, #8
	adds r0, r0, r4
	adds r4, r0, #0
	mov r3, sb
	muls r3, r1, r3
	adds r1, r3, #0
	adds r1, r1, r6
	lsls r1, r1, #1
	lsrs r2, r1, #1
	mov r3, sl
	str r2, [r3]
	lsrs r1, r1, #0x11
	mov r2, r8
	ands r1, r2
	subs r1, #8
	lsls r1, r1, #8
	adds r1, r1, r5
	adds r5, r1, #0
	movs r2, #1
	bl CreateBubble
	mov r3, sl
	ldr r0, [r3]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	mov r2, r8
	ands r0, r2
	subs r0, #8
	lsls r0, r0, #8
	adds r0, r0, r4
	adds r4, r0, #0
	mov r3, sb
	muls r3, r1, r3
	adds r1, r3, #0
	adds r1, r1, r6
	lsls r1, r1, #1
	lsrs r2, r1, #1
	mov r3, sl
	str r2, [r3]
	lsrs r1, r1, #0x11
	mov r2, r8
	ands r1, r2
	subs r1, #8
	lsls r1, r1, #8
	adds r1, r1, r5
	adds r5, r1, #0
	movs r2, #1
	bl CreateBubble
	mov r3, sl
	ldr r0, [r3]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	mov r2, r8
	ands r0, r2
	subs r0, #8
	lsls r0, r0, #8
	adds r0, r0, r4
	adds r4, r0, #0
	mov r3, sb
	muls r3, r1, r3
	adds r1, r3, #0
	adds r1, r1, r6
	lsls r1, r1, #1
	lsrs r2, r1, #1
	mov r3, sl
	str r2, [r3]
	lsrs r1, r1, #0x11
	mov r2, r8
	ands r1, r2
	subs r1, #8
	lsls r1, r1, #8
	adds r1, r1, r5
	adds r5, r1, #0
	movs r2, #0
	bl CreateBubble
	mov r3, sl
	ldr r0, [r3]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	mov r2, r8
	ands r0, r2
	subs r0, #8
	lsls r0, r0, #8
	adds r0, r0, r4
	mov r3, sb
	muls r3, r1, r3
	adds r1, r3, #0
	adds r1, r1, r6
	lsls r1, r1, #1
	lsrs r2, r1, #1
	mov r3, sl
	str r2, [r3]
	lsrs r1, r1, #0x11
	mov r2, r8
	ands r1, r2
	subs r1, #8
	lsls r1, r1, #8
	adds r1, r1, r5
	movs r2, #0
	bl CreateBubble
	b _0807A3D6
	.align 2, 0
_0807A39C: .4byte RNG_0202f388
_0807A3A0: .4byte 0x000343FD
_0807A3A4: .4byte 0x00269EC3
_0807A3A8:
	ldr r2, _0807A3C8 @ =0x0836762C
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r5]
	cmp r0, #0
	beq _0807A3D6
	mov r3, r8
	ldrb r0, [r3]
	adds r2, r7, #0
	ands r2, r0
	cmp r2, #0x10
	bne _0807A3CC
	movs r0, #2
	b _0807A3D2
	.align 2, 0
_0807A3C8: .4byte 0x0836762C
_0807A3CC:
	cmp r2, #0x30
	bne _0807A3D6
	movs r0, #4
_0807A3D2:
	strb r0, [r4, #0xd]
	strb r6, [r4, #0xe]
_0807A3D6:
	movs r0, #1
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

