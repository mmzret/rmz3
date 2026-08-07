	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start icebonDeath0
icebonDeath0: @ 0x080CA2AC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	ldrb r1, [r6, #0xb]
	movs r0, #0xf7
	ands r0, r1
	movs r1, #0
	strb r0, [r6, #0xb]
	adds r0, r6, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r2, [r6, #0x58]
	ldr r0, _080CA368 @ =0xFFFFF100
	adds r1, r2, r0
	ldr r0, _080CA36C @ =gOverworld
	ldr r3, _080CA370 @ =0x0002C00C
	adds r0, r0, r3
	ldr r0, [r0]
	cmp r1, r0
	bgt _080CA2F2
	b _080CA408
_080CA2F2:
	movs r0, #0x54
	adds r0, r0, r6
	mov sl, r0
	ldr r7, _080CA374 @ =RNG_0202f388
	ldr r1, _080CA378 @ =0x000343FD
	mov r8, r1
	movs r3, #4
	mov sb, r3
_080CA302:
	ldr r0, [r7]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r3, _080CA37C @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r2, r0, #1
	str r2, [r7]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080CA388
	mov r0, r8
	muls r0, r2, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r7]
	lsrs r0, r0, #0x11
	movs r1, #0xe0
	lsls r1, r1, #5
	bl __umodsi3
	ldr r1, _080CA380 @ =0xFFFFF200
	adds r0, r0, r1
	ldr r4, [r6, #0x54]
	adds r4, r4, r0
	mov r0, r8
	muls r0, r5, r0
	ldr r3, _080CA37C @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r7]
	lsrs r0, r0, #0x11
	movs r1, #0xf0
	lsls r1, r1, #5
	bl __umodsi3
	ldr r1, _080CA384 @ =0xFFFFE200
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	adds r1, r1, r0
	adds r0, r4, #0
	movs r2, #0
	bl CreateBubble
	b _080CA3D0
	.align 2, 0
_080CA368: .4byte 0xFFFFF100
_080CA36C: .4byte gOverworld
_080CA370: .4byte 0x0002C00C
_080CA374: .4byte RNG_0202f388
_080CA378: .4byte 0x000343FD
_080CA37C: .4byte 0x00269EC3
_080CA380: .4byte 0xFFFFF200
_080CA384: .4byte 0xFFFFE200
_080CA388:
	mov r0, r8
	muls r0, r2, r0
	ldr r3, _080CA3F8 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r7]
	lsrs r0, r0, #0x11
	movs r1, #0xe0
	lsls r1, r1, #5
	bl __umodsi3
	ldr r1, _080CA3FC @ =0xFFFFF200
	adds r0, r0, r1
	ldr r4, [r6, #0x54]
	adds r4, r4, r0
	mov r0, r8
	muls r0, r5, r0
	ldr r3, _080CA3F8 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r7]
	lsrs r0, r0, #0x11
	movs r1, #0xf0
	lsls r1, r1, #5
	bl __umodsi3
	ldr r1, _080CA400 @ =0xFFFFE200
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	adds r1, r1, r0
	adds r0, r4, #0
	movs r2, #1
	bl CreateBubble
_080CA3D0:
	movs r3, #1
	rsbs r3, r3, #0
	add sb, r3
	mov r0, sb
	cmp r0, #0
	bge _080CA302
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	ldr r1, _080CA404 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x31
	bl PlaySound
	b _080CA426
	.align 2, 0
_080CA3F8: .4byte 0x00269EC3
_080CA3FC: .4byte 0xFFFFF200
_080CA400: .4byte 0xFFFFE200
_080CA404: .4byte 0xFFFFF000
_080CA408:
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r3, _080CA474 @ =0xFFFFF000
	adds r0, r2, r3
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	movs r0, #0x54
	adds r0, r0, r6
	mov sl, r0
_080CA426:
	ldr r2, _080CA478 @ =motion_t_ARRAY_0836fc92
	adds r0, r6, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b81a0
	mov r1, sl
	movs r0, #3
	bl TryDropItem
	ldr r2, _080CA47C @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _080CA480 @ =0x0000270E
	cmp r1, r0
	bhi _080CA448
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_080CA448:
	adds r0, r6, #0
	mov r1, sl
	bl TryDropZakoDisk
	ldr r1, _080CA484 @ =gSolidFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r6, #0x14]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CA474: .4byte 0xFFFFF000
_080CA478: .4byte motion_t_ARRAY_0836fc92
_080CA47C: .4byte gScore
_080CA480: .4byte 0x0000270E
_080CA484: .4byte gSolidFnTable
