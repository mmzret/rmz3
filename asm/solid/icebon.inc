	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start icebon_080ca104
icebon_080ca104: @ 0x080CA104
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080CA114
	cmp r0, #1
	beq _080CA12E
	b _080CA148
_080CA114:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CA150 @ =0x0836FC50
	bl SetDDP
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CA12E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080CA148
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080CA148:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CA150: .4byte 0x0836FC50

	thumb_func_start icebon_080ca154
icebon_080ca154: @ 0x080CA154
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _080CA194
	cmp r5, #1
	bgt _080CA16A
	cmp r5, #0
	beq _080CA174
	b _080CA290
_080CA16A:
	cmp r5, #2
	beq _080CA238
	cmp r5, #3
	beq _080CA242
	b _080CA290
_080CA174:
	movs r0, #0x83
	lsls r0, r0, #1
	bl PlaySound
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CA194:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x12]
	movs r1, #0xc
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CA1D6
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r1, _080CA218 @ =0xFFFFFC00
	adds r1, r0, r1
	str r1, [sp]
	ldr r2, _080CA21C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080CA220 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080CA224 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsls r0, r0, #4
	lsrs r0, r0, #0x15
	ldr r2, [sp]
	adds r0, r0, r2
	ldr r1, [r4, #0x58]
	ldr r2, _080CA228 @ =0xFFFFEB00
	adds r1, r1, r2
	bl createIcebonIce
_080CA1D6:
	ldrb r0, [r4, #0x12]
	cmp r0, #0x2b
	bls _080CA290
	ldr r0, [r4, #0x58]
	ldr r1, _080CA22C @ =0xFFFFCC00
	adds r0, r0, r1
	ldr r1, _080CA230 @ =gOverworld
	ldr r2, _080CA234 @ =0x0002C00C
	adds r1, r1, r2
	ldr r1, [r1]
	cmp r0, r1
	ble _080CA20E
	movs r1, #0
	ldrb r0, [r4, #0x13]
	cmp r0, #2
	bne _080CA1F8
	movs r1, #1
_080CA1F8:
	adds r0, r4, #0
	bl icebon_080ca550
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0x13]
	movs r1, #3
	bl __umodsi3
	strb r0, [r4, #0x13]
_080CA20E:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080CA290
	.align 2, 0
_080CA218: .4byte 0xFFFFFC00
_080CA21C: .4byte RNG_0202f388
_080CA220: .4byte 0x000343FD
_080CA224: .4byte 0x00269EC3
_080CA228: .4byte 0xFFFFEB00
_080CA22C: .4byte 0xFFFFCC00
_080CA230: .4byte gOverworld
_080CA234: .4byte 0x0002C00C
_080CA238:
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CA242:
	ldrb r0, [r4, #0x12]
	movs r1, #0xc
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CA278
	ldr r6, [r4, #0x54]
	ldr r0, _080CA298 @ =0xFFFFFC00
	adds r6, r6, r0
	ldr r2, _080CA29C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080CA2A0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080CA2A4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsls r0, r0, #4
	lsrs r0, r0, #0x15
	adds r0, r0, r6
	ldr r1, [r4, #0x58]
	ldr r2, _080CA2A8 @ =0xFFFFEB00
	adds r1, r1, r2
	bl createIcebonIce
_080CA278:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080CA290
	movs r0, #0xe1
	strb r0, [r4, #0x12]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080CA290:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CA298: .4byte 0xFFFFFC00
_080CA29C: .4byte RNG_0202f388
_080CA2A0: .4byte 0x000343FD
_080CA2A4: .4byte 0x00269EC3
_080CA2A8: .4byte 0xFFFFEB00

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
	ldr r2, _080CA478 @ =0x0836FC92
	adds r0, r6, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b81a0
	mov r1, sl
	movs r0, #3
	bl TryDropItem
	ldr r2, _080CA47C @ =gMission
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
_080CA478: .4byte 0x0836FC92
_080CA47C: .4byte gMission
_080CA480: .4byte 0x0000270E
_080CA484: .4byte gSolidFnTable

	thumb_func_start icebonDeath1
icebonDeath1: @ 0x080CA488
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #0
	beq _080CA49A
	cmp r4, #1
	beq _080CA51A
	b _080CA53A
_080CA49A:
	ldrb r1, [r5, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r5, #0xb]
	movs r6, #0
	ldr r0, _080CA544 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _080CA4B4
	movs r6, #1
_080CA4B4:
	ldr r1, _080CA548 @ =0x00001001
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp, #8]
	ldr r0, [r5, #0x58]
	str r0, [sp, #0xc]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	add r1, sp, #8
	adds r3, r6, #0
	bl FUN_080b2b40
	movs r0, #0x80
	lsls r1, r6, #8
	subs r0, r0, r1
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	adds r1, r5, #0
	adds r1, #0x54
	ldr r0, _080CA54C @ =0x0836FC98
	str r0, [sp]
	movs r4, #0x18
	str r4, [sp, #4]
	adds r0, r5, #0
	add r2, sp, #8
	movs r3, #0
	bl FUN_080b83d4
	strb r4, [r5, #0x12]
	ldr r0, [sp, #8]
	movs r1, #3
	bl __divsi3
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080CA51A:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CA53A
	adds r0, r5, #0
	bl icebonDeath0
_080CA53A:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CA544: .4byte pZero2
_080CA548: .4byte 0x00001001
_080CA54C: .4byte 0x0836FC98

	thumb_func_start icebon_080ca550
icebon_080ca550: @ 0x080CA550
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080CA5A8 @ =gSolidHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080CA5A2
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x1e
	strb r0, [r1]
	ldr r1, _080CA5AC @ =gSolidFnTable
	movs r0, #1
	strb r0, [r3, #9]
	ldr r0, [r1, #4]
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
	ldr r0, [r4, #0x54]
	str r0, [r3, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, _080CA5B0 @ =0xFFFFEB00
	adds r0, r0, r1
	str r0, [r3, #0x58]
	strb r5, [r3, #0x10]
	str r4, [r3, #0x28]
_080CA5A2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CA5A8: .4byte gSolidHeaderPtr
_080CA5AC: .4byte gSolidFnTable
_080CA5B0: .4byte 0xFFFFEB00
