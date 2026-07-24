	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
