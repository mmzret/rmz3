	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080abec0
FUN_080abec0: @ 0x080ABEC0
	push {r4, r5, lr}
	adds r5, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r4, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r5, #0xa]
	movs r1, #0xc4
	lsls r1, r1, #7
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, _080ABF00 @ =pZero2
	ldr r0, [r0]
	ldrb r0, [r0, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080ABF04
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080ABF0A
	.align 2, 0
_080ABF00: .4byte pZero2
_080ABF04:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080ABF0A:
	strb r0, [r5, #0xa]
	movs r4, #1
	adds r1, r4, #0
	ands r1, r2
	adds r0, r5, #0
	adds r0, #0x4c
	movs r3, #0
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r5
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	strb r3, [r5, #0x11]
	ldr r1, _080ABF50 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r4, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl Projectile32_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080ABF50: .4byte gProjectileFnTable

	thumb_func_start FUN_080abf54
FUN_080abf54: @ 0x080ABF54
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateEntityAnim
	ldrb r1, [r4, #0x12]
	adds r0, r1, #1
	strb r0, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080ABF72
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080ABF78
_080ABF72:
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
_080ABF78:
	strb r0, [r4, #0xa]
	ldr r0, _080ABFB0 @ =pZero2
	ldr r1, [r0]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	ldr r1, _080ABFB4 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _080ABFA8
	movs r0, #0x3f
	bl PlaySound
	ldr r1, _080ABFB8 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080ABFA8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ABFB0: .4byte pZero2
_080ABFB4: .4byte 0xFFFFF800
_080ABFB8: .4byte gProjectileFnTable

	thumb_func_start FUN_080abfbc
FUN_080abfbc: @ 0x080ABFBC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0x54
	adds r0, r0, r7
	mov sl, r0
	ldr r4, _080AC190 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r6, _080AC194 @ =0x000343FD
	muls r0, r6, r0
	ldr r5, _080AC198 @ =0x00269EC3
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	ldr r1, _080AC19C @ =0x000003FF
	mov sb, r1
	mov r1, sb
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #1
	mov r8, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl CreateVFX57
	ldr r0, [r4]
	adds r3, r0, #0
	muls r3, r6, r3
	adds r3, r3, r5
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	movs r1, #0x7f
	ands r3, r1
	adds r3, #0x80
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	mov r1, sb
	ands r0, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #2
	bl CreateVFX57
	ldr r0, [r4]
	adds r3, r0, #0
	muls r3, r6, r3
	adds r3, r3, r5
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	movs r1, #0xff
	ands r3, r1
	mov r1, r8
	orrs r3, r1
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	mov r1, sb
	ands r0, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #3
	bl CreateVFX57
	ldr r0, [r4]
	adds r3, r0, #0
	muls r3, r6, r3
	adds r3, r3, r5
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	movs r1, #0xff
	ands r3, r1
	mov r1, r8
	orrs r3, r1
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	mov r1, sb
	ands r0, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #1
	bl CreateVFX57
	ldr r0, [r4]
	adds r3, r0, #0
	muls r3, r6, r3
	adds r3, r3, r5
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	movs r1, #0x7f
	ands r3, r1
	adds r3, #0x80
	rsbs r3, r3, #0
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	mov r1, sb
	ands r0, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #3
	bl CreateVFX57
	ldr r0, [r4]
	adds r3, r0, #0
	muls r3, r6, r3
	adds r3, r3, r5
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	movs r1, #0xff
	ands r3, r1
	add r3, r8
	rsbs r3, r3, #0
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	mov r1, sb
	ands r0, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #1
	bl CreateVFX57
	ldr r0, [r4]
	adds r3, r0, #0
	muls r3, r6, r3
	adds r3, r3, r5
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	movs r1, #0xff
	ands r3, r1
	add r3, r8
	rsbs r3, r3, #0
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	mov r1, sb
	ands r0, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #3
	bl CreateVFX57
	ldr r1, _080AC1A0 @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r7, #0x14]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AC190: .4byte RNG_0202f388
_080AC194: .4byte 0x000343FD
_080AC198: .4byte 0x00269EC3
_080AC19C: .4byte 0x000003FF
_080AC1A0: .4byte gProjectileFnTable

	thumb_func_start FUN_080ac1a4
FUN_080ac1a4: @ 0x080AC1A4
	push {lr}
	ldr r1, [r0, #0x2c]
	ldr r0, [r0, #0xc]
	ldr r2, [r0, #0x2c]
	movs r0, #8
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bne _080AC1E0
	ldrb r0, [r1, #0x11]
	movs r3, #0xa0
	lsls r3, r3, #2
	cmp r0, #0
	bne _080AC1C2
	movs r3, #0xc0
	lsls r3, r3, #1
_080AC1C2:
	ldrb r1, [r1, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080AC1D6
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r2, r1
	str r3, [r0]
	b _080AC1E0
_080AC1D6:
	movs r0, #0xc8
	lsls r0, r0, #1
	adds r1, r2, r0
	rsbs r0, r3, #0
	str r0, [r1]
_080AC1E0:
	pop {r0}
	bx r0

	thumb_func_start FUN_080ac1e4
FUN_080ac1e4: @ 0x080AC1E4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x58
	adds r1, #8
	mov ip, r1
	ldr r5, [r0, #8]
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080AC1F6
	b _080AC36E
_080AC1F6:
	ldr r0, [r5, #0x58]
	ldr r1, [r1, #4]
	subs r0, r0, r1
	asrs r6, r0, #8
	ldrb r0, [r5, #0x12]
	cmp r0, #0x13
	bls _080AC218
	cmp r0, #0x9f
	bhi _080AC212
	adds r3, r6, #0
	subs r3, #0x28
	adds r2, r6, #0
	adds r2, #0x28
	b _080AC21E
_080AC212:
	ldrb r1, [r5, #0x12]
	movs r0, #0xb5
	subs r0, r0, r1
_080AC218:
	lsls r0, r0, #1
	subs r3, r6, r0
	adds r2, r6, r0
_080AC21E:
	cmp r3, #0x9f
	ble _080AC238
	ldr r2, _080AC230 @ =gVideoRegBuffer
	ldrh r1, [r2]
	ldr r0, _080AC234 @ =0x0000DBFF
	ands r0, r1
	strh r0, [r2]
	b _080AC36E
	.align 2, 0
_080AC230: .4byte gVideoRegBuffer
_080AC234: .4byte 0x0000DBFF
_080AC238:
	ldr r7, _080AC29C @ =gVideoRegBuffer
	ldrh r1, [r7]
	movs r4, #0x90
	lsls r4, r4, #6
	adds r0, r4, #0
	adds r4, r0, #0
	orrs r4, r1
	strh r4, [r7]
	cmp r3, #0
	bge _080AC24E
	movs r3, #0
_080AC24E:
	cmp r2, #0x9f
	ble _080AC254
	movs r2, #0x9f
_080AC254:
	ldr r1, _080AC2A0 @ =gWindowRegBuffer
	movs r0, #0xff
	ands r2, r0
	lsls r0, r3, #8
	orrs r2, r0
	strh r2, [r1, #0xa]
	mov r0, ip
	ldr r2, [r0]
	asrs r0, r2, #8
	ldrb r1, [r5, #0x13]
	adds r0, r0, r1
	strh r0, [r7, #0x14]
	movs r0, #0x28
	subs r0, r0, r6
	strh r0, [r7, #0x16]
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080AC2BA
	ldr r0, [r5, #0x54]
	subs r0, r0, r2
	asrs r1, r0, #8
	cmp r1, #0xf0
	bgt _080AC2C4
	movs r2, #0
	movs r4, #0xf0
	mov r3, sp
_080AC28C:
	adds r0, r2, #0
	muls r0, r2, r0
	asrs r0, r0, #5
	adds r0, r1, r0
	cmp r0, #0
	bge _080AC2A4
	movs r0, #0
	b _080AC2AA
	.align 2, 0
_080AC29C: .4byte gVideoRegBuffer
_080AC2A0: .4byte gWindowRegBuffer
_080AC2A4:
	cmp r0, #0xf0
	ble _080AC2AA
	movs r0, #0xf0
_080AC2AA:
	lsls r0, r0, #8
	orrs r0, r4
	strh r0, [r3]
	adds r3, #2
	adds r2, #1
	cmp r2, #0x27
	ble _080AC28C
	b _080AC2F4
_080AC2BA:
	ldr r0, [r5, #0x54]
	subs r0, r0, r2
	asrs r1, r0, #8
	cmp r1, #0
	bge _080AC2D0
_080AC2C4:
	ldr r0, _080AC2CC @ =0x0000DBFF
	ands r4, r0
	strh r4, [r7]
	b _080AC36E
	.align 2, 0
_080AC2CC: .4byte 0x0000DBFF
_080AC2D0:
	movs r2, #0
	mov r3, sp
_080AC2D4:
	adds r0, r2, #0
	muls r0, r2, r0
	asrs r0, r0, #5
	subs r0, r1, r0
	cmp r0, #0
	bge _080AC2E4
	movs r0, #0
	b _080AC2EA
_080AC2E4:
	cmp r0, #0xf0
	ble _080AC2EA
	movs r0, #0xf0
_080AC2EA:
	strh r0, [r3]
	adds r3, #2
	adds r2, #1
	cmp r2, #0x27
	ble _080AC2D4
_080AC2F4:
	movs r0, #0xa0
	lsls r0, r0, #1
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _080AC36E
	movs r0, #0
	str r0, [sp, #0x50]
	add r0, sp, #0x50
	ldr r2, _080AC378 @ =0x01000050
	adds r1, r4, #0
	bl CpuFastSet
	movs r2, #0
	adds r0, r6, #0
	cmp r0, #0
	blt _080AC330
	mov r3, sp
_080AC31A:
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r3]
	strh r1, [r0]
	adds r3, #2
	adds r2, #1
	cmp r2, #0x27
	bgt _080AC330
	subs r0, r6, r2
	cmp r0, #0
	bge _080AC31A
_080AC330:
	movs r2, #0
	adds r0, r6, #0
	ldr r5, _080AC37C @ =gIntrManager
	cmp r0, #0xf0
	bgt _080AC352
	mov r3, sp
_080AC33C:
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r3]
	strh r1, [r0]
	adds r3, #2
	adds r2, #1
	cmp r2, #0x27
	bgt _080AC352
	adds r0, r6, r2
	cmp r0, #0xf0
	ble _080AC33C
_080AC352:
	movs r2, #0xba
	lsls r2, r2, #1
	adds r0, r5, r2
	str r4, [r0]
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r5, r4
	ldr r0, _080AC380 @ =0x04000042
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, _080AC384 @ =0xA2600001
	str r0, [r1]
_080AC36E:
	add sp, #0x58
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AC378: .4byte 0x01000050
_080AC37C: .4byte gIntrManager
_080AC380: .4byte 0x04000042
_080AC384: .4byte 0xA2600001

