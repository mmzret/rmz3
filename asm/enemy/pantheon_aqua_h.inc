	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080730d0
FUN_080730d0: @ 0x080730D0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080730E0
	cmp r0, #1
	beq _08073128
	b _080731BC
_080730E0:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08073108 @ =0x08366CA0
	bl SetDDP
	ldr r0, _0807310C @ =pZero2
	ldr r0, [r0]
	ldrb r0, [r0, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	strb r0, [r4, #0xf]
	cmp r0, #0
	bne _08073114
	ldr r0, _08073110 @ =0xFFFFFD80
	str r0, [r4, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #1
	b _0807311C
	.align 2, 0
_08073108: .4byte sCollisions+(6*24)
_0807310C: .4byte pZero2
_08073110: .4byte 0xFFFFFD80
_08073114:
	movs r0, #0xa0
	lsls r0, r0, #2
	str r0, [r4, #0x5c]
	ldr r0, _0807315C @ =0xFFFFFF00
_0807311C:
	str r0, [r4, #0x64]
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08073128:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	movs r1, #0xf0
	lsls r1, r1, #0xc
	ands r1, r0
	lsrs r1, r1, #0x10
	cmp r1, #1
	bne _08073164
	ldr r1, _08073160 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080731BC
	.align 2, 0
_0807315C: .4byte 0xFFFFFF00
_08073160: .4byte gEnemyFnTable
_08073164:
	ldr r0, [r4, #0x54]
	ldr r3, [r4, #0x5c]
	adds r0, r0, r3
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	ldr r2, [r4, #0x64]
	subs r2, r2, r3
	lsls r2, r2, #3
	asrs r2, r2, #8
	adds r3, r3, r2
	str r3, [r4, #0x5c]
	ldr r2, _080731AC @ =0xFFFFE000
	adds r1, r1, r2
	bl FUN_08009f6c
	adds r1, r0, #0
	ldr r0, [r4, #0x58]
	subs r0, r1, r0
	cmp r0, #0x40
	bgt _08073194
	str r1, [r4, #0x58]
_08073194:
	adds r0, r4, #0
	bl FUN_08073610
	ldrb r1, [r4, #0xf]
	cmp r1, #0
	bne _080731B0
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	blt _080731BC
	strb r1, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _080731BC
	.align 2, 0
_080731AC: .4byte 0xFFFFE000
_080731B0:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bgt _080731BC
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_080731BC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080731c4
FUN_080731c4: @ 0x080731C4
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
	beq _080731DC
	b _08073356
_080731DC:
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080731EA
	b _08073356
_080731EA:
	movs r0, #0x97
	adds r0, r0, r4
	mov r8, r0
	ldrb r1, [r0]
	movs r7, #0xf0
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0x20
	beq _080731FE
	b _08073328
_080731FE:
	ldr r5, [r4, #0x58]
	ldr r4, [r4, #0x54]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	bl CreateBubble
	ldr r1, _0807331C @ =RNG_0202f388
	mov sl, r1
	ldr r0, [r1]
	ldr r2, _08073320 @ =0x000343FD
	mov sb, r2
	mov r3, sb
	muls r3, r0, r3
	adds r0, r3, #0
	ldr r6, _08073324 @ =0x00269EC3
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
	b _08073356
	.align 2, 0
_0807331C: .4byte RNG_0202f388
_08073320: .4byte 0x000343FD
_08073324: .4byte 0x00269EC3
_08073328:
	ldr r2, _08073348 @ =sElementCoord
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r5]
	cmp r0, #0
	beq _08073356
	mov r3, r8
	ldrb r0, [r3]
	adds r2, r7, #0
	ands r2, r0
	cmp r2, #0x10
	bne _0807334C
	movs r0, #4
	b _08073352
	.align 2, 0
_08073348: .4byte sElementCoord
_0807334C:
	cmp r2, #0x30
	bne _08073356
	movs r0, #6
_08073352:
	strb r0, [r4, #0xd]
	strb r6, [r4, #0xe]
_08073356:
	movs r0, #1
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

