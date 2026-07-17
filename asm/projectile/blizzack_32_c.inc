	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080ab190
FUN_080ab190: @ 0x080AB190
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	ldr r1, _080AB210 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r2, #0
	mov r8, r2
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080AB214 @ =0x00006201
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _080AB218 @ =0x0836C45C
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #6
	bl InitBody
	str r4, [r5, #0x2c]
	mov r0, r8
	str r0, [r5, #0x24]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #9
	strb r0, [r1]
	movs r0, #0x30
	strb r0, [r4, #0x12]
	adds r6, #0xc6
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	adds r0, r4, #0
	bl Projectile32_Update
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AB210: .4byte gProjectileFnTable
_080AB214: .4byte 0x00006201
_080AB218: .4byte 0x0836C45C

	thumb_func_start FUN_080ab21c
FUN_080ab21c: @ 0x080AB21C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	mov r8, r0
	adds r7, r5, #0
	adds r7, #0x8c
	ldr r6, [r7]
	movs r1, #0x80
	lsls r1, r1, #2
	mov sb, r1
	ands r6, r1
	cmp r6, #0
	bne _080AB2DA
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r4, [r5, #0xd]
	cmp r4, #1
	beq _080AB2C4
	cmp r4, #1
	bgt _080AB252
	cmp r4, #0
	beq _080AB258
	b _080AB39A
_080AB252:
	cmp r4, #2
	beq _080AB300
	b _080AB39A
_080AB258:
	ldr r0, [r7]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080AB298
	adds r0, r5, #0
	adds r0, #0x84
	ldr r0, [r0]
	ldr r4, [r0, #0x2c]
	adds r0, r5, #0
	bl FUN_080aae34
	str r0, [r5, #0x2c]
	mov r1, r8
	adds r1, #0xc5
	movs r0, #1
	strb r0, [r1]
	movs r0, #2
	strb r0, [r5, #0xd]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [r5, #0x54]
	ldr r0, [r4, #0x58]
	str r0, [r5, #0x58]
	movs r0, #0x40
	bl PlaySound
	b _080AB39A
_080AB298:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080AB39A
	movs r0, #1
	strb r0, [r5, #0xd]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080AB2C0 @ =0x0836C48C
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xbc
	mov r1, sb
	strh r1, [r0]
	b _080AB39A
	.align 2, 0
_080AB2C0: .4byte 0x0836C48C
_080AB2C4:
	adds r0, r5, #0
	adds r0, #0xbc
	ldrh r1, [r0]
	subs r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _080AB39A
_080AB2DA:
	movs r0, #0x3f
	bl PlaySound
	ldr r1, _080AB2FC @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl FUN_080ab3ac
	b _080AB39A
	.align 2, 0
_080AB2FC: .4byte gProjectileFnTable
_080AB300:
	ldr r2, [r7]
	movs r0, #0x80
	lsls r0, r0, #4
	ands r2, r0
	cmp r2, #0
	beq _080AB370
	adds r0, r5, #0
	adds r0, #0x84
	ldr r0, [r0]
	ldr r4, [r0, #0x2c]
	movs r0, #8
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne _080AB354
	ldr r0, _080AB36C @ =0x00000143
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, [r4, #0x58]
	add r1, sb
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_08009f6c
	ldr r1, [r4, #0x58]
	cmp r0, r1
	bge _080AB33E
	ldr r0, [r4, #0x54]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
_080AB33E:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r5, #0x54]
	str r1, [r5, #0x58]
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080AB39A
_080AB354:
	str r6, [r7]
	adds r0, r5, #0
	adds r0, #0x90
	str r6, [r0]
	adds r0, #4
	strb r6, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	b _080AB39A
	.align 2, 0
_080AB36C: .4byte 0x00000143
_080AB370:
	movs r1, #1
	strb r1, [r5, #0x11]
	ldr r0, [r5, #0x2c]
	strb r1, [r0, #0x11]
	mov r0, r8
	adds r0, #0xc5
	strb r2, [r0]
	movs r0, #0x3f
	bl PlaySound
	ldr r1, _080AB3A8 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r4, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl FUN_080ab3ac
_080AB39A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AB3A8: .4byte gProjectileFnTable

	thumb_func_start FUN_080ab3ac
FUN_080ab3ac: @ 0x080AB3AC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, [r7, #0x28]
	str r0, [sp, #4]
	ldrb r0, [r7, #0x11]
	cmp r0, #0
	beq _080AB3C6
	b _080AB4F2
_080AB3C6:
	movs r1, #0x54
	adds r1, r1, r7
	mov sl, r1
	ldr r4, _080AB53C @ =RNG_0202f388
	ldr r0, [r4]
	ldr r6, _080AB540 @ =0x000343FD
	muls r0, r6, r0
	ldr r5, _080AB544 @ =0x00269EC3
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	ldr r1, _080AB548 @ =0x000003FF
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
	mov sb, r1
	mov r1, sb
	ands r3, r1
	adds r3, #0x80
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	ldr r1, _080AB548 @ =0x000003FF
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
	ldr r1, _080AB548 @ =0x000003FF
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
	mov r1, sb
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
	ldr r1, _080AB548 @ =0x000003FF
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
	ldr r1, _080AB548 @ =0x000003FF
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
_080AB4F2:
	ldr r2, [sp, #4]
	adds r2, #0xc6
	ldrb r0, [r2]
	subs r0, #1
	movs r1, #0
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080AB54C @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r7, #0x14]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AB53C: .4byte RNG_0202f388
_080AB540: .4byte 0x000343FD
_080AB544: .4byte 0x00269EC3
_080AB548: .4byte 0x000003FF
_080AB54C: .4byte gProjectileFnTable

	thumb_func_start FUN_080ab550
FUN_080ab550: @ 0x080AB550
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x28]
	ldr r2, _080AB598 @ =gVideoRegBuffer
	ldrh r1, [r2]
	movs r3, #0x90
	lsls r3, r3, #6
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	adds r0, r5, #0
	adds r0, #0x34
	ldr r1, _080AB59C @ =FUN_080ac1e4
	bl SetTaskCallback
	str r5, [r5, #0x3c]
	ldrb r0, [r5, #0xa]
	movs r2, #0xf7
	ands r2, r0
	movs r0, #1
	movs r3, #0
	orrs r2, r0
	movs r0, #2
	orrs r2, r0
	orrs r2, r3
	strb r2, [r5, #0xa]
	ldrb r0, [r4, #0xa]
	lsrs r1, r0, #4
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080AB5A0
	movs r0, #0x10
	orrs r2, r0
	b _080AB5A4
	.align 2, 0
_080AB598: .4byte gVideoRegBuffer
_080AB59C: .4byte FUN_080ac1e4
_080AB5A0:
	movs r0, #0xef
	ands r2, r0
_080AB5A4:
	strb r2, [r5, #0xa]
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
	ldr r1, _080AB5FC @ =gBlendRegBuffer
	ldr r0, _080AB600 @ =0x00003F44
	strh r0, [r1]
	ldr r0, _080AB604 @ =0x00001008
	strh r0, [r1, #2]
	ldr r1, _080AB608 @ =gWindowRegBuffer
	ldrh r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	orrs r0, r2
	strh r0, [r1]
	movs r0, #0xff
	strb r0, [r1, #0xd]
	ldrb r2, [r1, #0xe]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r1, #0xe]
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080AB60C
	ldr r0, [r5, #0x54]
	movs r1, #0xf0
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r5, #0x54]
	movs r0, #2
	rsbs r0, r0, #0
	b _080AB616
	.align 2, 0
_080AB5FC: .4byte gBlendRegBuffer
_080AB600: .4byte 0x00003F44
_080AB604: .4byte 0x00001008
_080AB608: .4byte gWindowRegBuffer
_080AB60C:
	ldr r0, [r5, #0x54]
	ldr r3, _080AB65C @ =0xFFFFE200
	adds r0, r0, r3
	str r0, [r5, #0x54]
	movs r0, #2
_080AB616:
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r1, _080AB660 @ =0xFFFFDA00
	adds r0, r0, r1
	str r0, [r5, #0x58]
	movs r1, #0
	movs r0, #0xb4
	strb r0, [r5, #0x12]
	strb r1, [r5, #0x13]
	movs r0, #0x44
	bl PlaySound
	adds r1, r5, #0
	adds r1, #0xc0
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080aada0
	ldr r1, _080AB664 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl Projectile32_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AB65C: .4byte 0xFFFFE200
_080AB660: .4byte 0xFFFFDA00
_080AB664: .4byte gProjectileFnTable

	thumb_func_start FUN_080ab668
FUN_080ab668: @ 0x080AB668
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldr r1, [r4, #0x5c]
	ldrb r0, [r4, #0x13]
	adds r0, r0, r1
	strb r0, [r4, #0x13]
	ldrb r1, [r4, #0x12]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _080AB6D4
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	adds r3, r1, #0
	cmp r0, #0
	beq _080AB696
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	b _080AB69A
_080AB696:
	ldr r0, [r4, #0x54]
	ldr r1, _080AB710 @ =0xFFFFF000
_080AB69A:
	adds r0, r0, r1
	str r0, [sp]
	ldr r2, _080AB714 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080AB718 @ =0x000343FD
	muls r1, r0, r1
	ldr r0, _080AB71C @ =0x00269EC3
	adds r1, r1, r0
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r2]
	lsrs r1, r1, #0x11
	movs r0, #0x3f
	ands r1, r0
	lsls r1, r1, #8
	ldr r0, [r4, #0x58]
	subs r0, r0, r1
	movs r1, #0xf8
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [sp, #4]
	lsls r1, r3, #0x18
	lsrs r1, r1, #0x1c
	movs r0, #1
	ands r1, r0
	mov r0, sp
	adds r2, r4, #0
	bl FUN_080aad0c
_080AB6D4:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _080AB6EE
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bhi _080AB6EE
	ldrb r0, [r5, #0xd]
	cmp r0, #0x13
	bne _080AB706
_080AB6EE:
	ldr r1, _080AB720 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Projectile32_Die
_080AB706:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AB710: .4byte 0xFFFFF000
_080AB714: .4byte RNG_0202f388
_080AB718: .4byte 0x000343FD
_080AB71C: .4byte 0x00269EC3
_080AB720: .4byte gProjectileFnTable

	thumb_func_start FUN_080ab724
FUN_080ab724: @ 0x080AB724
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _080AB770 @ =gVideoRegBuffer
	ldrh r1, [r2]
	ldr r0, _080AB774 @ =0x0000DBFF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _080AB778 @ =gWindowRegBuffer
	ldrh r2, [r1]
	ldr r0, _080AB77C @ =0x0000BFFF
	ands r0, r2
	strh r0, [r1]
	ldrb r2, [r1, #0xe]
	movs r0, #0xfe
	orrs r0, r2
	strb r0, [r1, #0xe]
	adds r0, r4, #0
	adds r0, #0xc0
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl StopSound
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080AB780 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AB770: .4byte gVideoRegBuffer
_080AB774: .4byte 0x0000DBFF
_080AB778: .4byte gWindowRegBuffer
_080AB77C: .4byte 0x0000BFFF
_080AB780: .4byte gProjectileFnTable

	thumb_func_start FUN_080ab784
FUN_080ab784: @ 0x080AB784
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x28]
	ldr r2, _080AB7CC @ =gVideoRegBuffer
	ldrh r1, [r2]
	movs r3, #0x90
	lsls r3, r3, #6
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	adds r0, r5, #0
	adds r0, #0x34
	ldr r1, _080AB7D0 @ =FUN_080ac1e4
	bl SetTaskCallback
	str r5, [r5, #0x3c]
	ldrb r0, [r5, #0xa]
	movs r2, #0xf7
	ands r2, r0
	movs r0, #1
	movs r3, #0
	orrs r2, r0
	movs r0, #2
	orrs r2, r0
	orrs r2, r3
	strb r2, [r5, #0xa]
	ldrb r0, [r4, #0xa]
	lsrs r1, r0, #4
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080AB7D4
	movs r0, #0x10
	orrs r2, r0
	b _080AB7D8
	.align 2, 0
_080AB7CC: .4byte gVideoRegBuffer
_080AB7D0: .4byte FUN_080ac1e4
_080AB7D4:
	movs r0, #0xef
	ands r2, r0
_080AB7D8:
	strb r2, [r5, #0xa]
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
	ldr r1, _080AB830 @ =gBlendRegBuffer
	ldr r0, _080AB834 @ =0x00003F44
	strh r0, [r1]
	ldr r0, _080AB838 @ =0x00001008
	strh r0, [r1, #2]
	ldr r1, _080AB83C @ =gWindowRegBuffer
	ldrh r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	orrs r0, r2
	strh r0, [r1]
	movs r0, #0xff
	strb r0, [r1, #0xd]
	ldrb r2, [r1, #0xe]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r1, #0xe]
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080AB840
	ldr r0, [r5, #0x54]
	movs r1, #0xf0
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r5, #0x54]
	movs r0, #3
	rsbs r0, r0, #0
	b _080AB84A
	.align 2, 0
_080AB830: .4byte gBlendRegBuffer
_080AB834: .4byte 0x00003F44
_080AB838: .4byte 0x00001008
_080AB83C: .4byte gWindowRegBuffer
_080AB840:
	ldr r0, [r5, #0x54]
	ldr r3, _080AB8B4 @ =0xFFFFE200
	adds r0, r0, r3
	str r0, [r5, #0x54]
	movs r0, #3
_080AB84A:
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r1, _080AB8B4 @ =0xFFFFE200
	adds r0, r0, r1
	str r0, [r5, #0x58]
	movs r1, #0
	movs r0, #0xb4
	strb r0, [r5, #0x12]
	strb r1, [r5, #0x13]
	adds r4, r5, #0
	adds r4, #0xc0
	ldr r0, _080AB8B8 @ =0x0000FFFF
	strh r0, [r4]
	movs r0, #0x44
	bl PlaySound
	strh r0, [r4]
	ldr r2, _080AB8BC @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080AB8C0 @ =0x000343FD
	muls r0, r1, r0
	ldr r3, _080AB8C4 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #3
	bl __umodsi3
	adds r1, r5, #0
	adds r1, #0xc2
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080aada0
	ldr r1, _080AB8C8 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl Projectile32_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AB8B4: .4byte 0xFFFFE200
_080AB8B8: .4byte 0x0000FFFF
_080AB8BC: .4byte RNG_0202f388
_080AB8C0: .4byte 0x000343FD
_080AB8C4: .4byte 0x00269EC3
_080AB8C8: .4byte gProjectileFnTable

	thumb_func_start FUN_080ab8cc
FUN_080ab8cc: @ 0x080AB8CC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r7, [r5, #0x28]
	bl UpdateEntityAnim
	ldr r1, [r5, #0x5c]
	ldrb r0, [r5, #0x13]
	adds r0, r0, r1
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0x12]
	movs r1, #0x18
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080AB948
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	adds r6, r1, #0
	cmp r0, #0
	beq _080AB902
	ldr r0, [r5, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	b _080AB906
_080AB902:
	ldr r0, [r5, #0x54]
	ldr r1, _080AB984 @ =0xFFFFF000
_080AB906:
	adds r0, r0, r1
	str r0, [sp]
	ldr r4, _080AB988 @ =0x0836C57C
	ldrb r0, [r5, #0x12]
	movs r1, #0x18
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	adds r1, r5, #0
	adds r1, #0xc2
	ldrb r2, [r1]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r0, r0, r4
	ldr r1, [r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080AB948
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [sp, #4]
	lsls r1, r6, #0x18
	lsrs r1, r1, #0x1c
	movs r0, #1
	ands r1, r0
	mov r0, sp
	adds r2, r5, #0
	bl FUN_080aac7c
_080AB948:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _080AB962
	ldrb r0, [r7, #0xc]
	cmp r0, #1
	bhi _080AB962
	ldrb r0, [r7, #0xd]
	cmp r0, #0x13
	bne _080AB97A
_080AB962:
	ldr r1, _080AB98C @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl Projectile32_Die
_080AB97A:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AB984: .4byte 0xFFFFF000
_080AB988: .4byte 0x0836C57C
_080AB98C: .4byte gProjectileFnTable

	thumb_func_start FUN_080ab990
FUN_080ab990: @ 0x080AB990
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _080AB9DC @ =gVideoRegBuffer
	ldrh r1, [r2]
	ldr r0, _080AB9E0 @ =0x0000DBFF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _080AB9E4 @ =gWindowRegBuffer
	ldrh r2, [r1]
	ldr r0, _080AB9E8 @ =0x0000BFFF
	ands r0, r2
	strh r0, [r1]
	ldrb r2, [r1, #0xe]
	movs r0, #0xfe
	orrs r0, r2
	strb r0, [r1, #0xe]
	adds r0, r4, #0
	adds r0, #0xc0
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl StopSound
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080AB9EC @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AB9DC: .4byte gVideoRegBuffer
_080AB9E0: .4byte 0x0000DBFF
_080AB9E4: .4byte gWindowRegBuffer
_080AB9E8: .4byte 0x0000BFFF
_080AB9EC: .4byte gProjectileFnTable

	thumb_func_start FUN_080ab9f0
FUN_080ab9f0: @ 0x080AB9F0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r6, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080ABA54 @ =0x00006202
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _080ABA58 @ =0x0836C4EC
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #0x40
	bl InitBody
	str r4, [r5, #0x2c]
	str r6, [r5, #0x24]
	movs r0, #0xa0
	str r0, [r4, #0x5c]
	ldr r1, _080ABA5C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Projectile32_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080ABA54: .4byte 0x00006202
_080ABA58: .4byte 0x0836C4EC
_080ABA5C: .4byte gProjectileFnTable

	thumb_func_start FUN_080aba60
FUN_080aba60: @ 0x080ABA60
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	bl UpdateEntityAnim
	ldrb r1, [r4, #0xd]
	cmp r1, #0
	bne _080ABAA6
	ldr r0, [r4, #0x5c]
	adds r0, #0x10
	str r0, [r4, #0x5c]
	movs r2, #0xa0
	lsls r2, r2, #2
	cmp r0, r2
	ble _080ABA80
	str r2, [r4, #0x5c]
_080ABA80:
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080ABAE0
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	b _080ABAE0
_080ABAA6:
	ldrb r1, [r4, #0x12]
	movs r0, #3
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #1
	bls _080ABABA
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080ABAC0
_080ABABA:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
_080ABAC0:
	strb r0, [r4, #0xa]
	adds r0, r2, #1
	strb r0, [r4, #0x12]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bls _080ABAE0
	ldr r1, _080ABAF4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080ABAE0:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080ABAF8
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	b _080ABAFE
	.align 2, 0
_080ABAF4: .4byte gProjectileFnTable
_080ABAF8:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
_080ABAFE:
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080ABB20
	ldr r1, _080ABB28 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080ABB20:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080ABB28: .4byte gProjectileFnTable

