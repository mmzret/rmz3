	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080affe4
FUN_080affe4: @ 0x080AFFE4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	ldr r0, _080B0040 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080B0038
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080B0044 @ =gProjectileFnTable
	movs r1, #0x29
	strb r1, [r3, #9]
	adds r0, #0xa4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #6
	strb r0, [r3, #0x10]
	strb r5, [r3, #0x11]
	adds r0, r3, #0
	adds r0, #0xbc
	strh r6, [r0]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	str r7, [r3, #0x28]
_080B0038:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080B0040: .4byte gProjectileHeaderPtr
_080B0044: .4byte gProjectileFnTable

	thumb_func_start FUN_080b0048
FUN_080b0048: @ 0x080B0048
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _080B0094 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080B008C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080B0098 @ =gProjectileFnTable
	movs r1, #0x29
	strb r1, [r3, #9]
	adds r0, #0xa4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #7
	strb r0, [r3, #0x10]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	str r5, [r3, #0x28]
_080B008C:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080B0094: .4byte gProjectileHeaderPtr
_080B0098: .4byte gProjectileFnTable

	thumb_func_start FUN_080b009c
FUN_080b009c: @ 0x080B009C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080B00DC @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080B00D2
	adds r0, #0x25
	movs r3, #0
	movs r2, #8
	strb r2, [r0]
	ldr r0, _080B00E0 @ =gProjectileFnTable
	movs r1, #0x29
	strb r1, [r4, #9]
	adds r0, #0xa4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r3, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r2, [r4, #0x10]
	str r5, [r4, #0x28]
_080B00D2:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080B00DC: .4byte gProjectileHeaderPtr
_080B00E0: .4byte gProjectileFnTable

	thumb_func_start OmegaZXProjectile_Init
OmegaZXProjectile_Init: @ 0x080B00E4
	push {lr}
	ldr r2, _080B0110 @ =gProjectileFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #1
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #4]
	str r1, [r0, #0x14]
	ldrb r1, [r0, #0x10]
	movs r2, #0
	strb r1, [r0, #0xd]
	strb r2, [r0, #0xe]
	strb r2, [r0, #0xf]
	movs r1, #0xff
	strb r1, [r0, #0x12]
	bl OmegaZXProjectile_Update
	pop {r0}
	bx r0
	.align 2, 0
_080B0110: .4byte gProjectileFnTable

	thumb_func_start OmegaZXProjectile_Update
OmegaZXProjectile_Update: @ 0x080B0114
	push {lr}
	ldr r2, _080B0128 @ =0x0836D468
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080B0128: .4byte 0x0836D468

	thumb_func_start OmegaZXProjectile_Die
OmegaZXProjectile_Die: @ 0x080B012C
	adds r2, r0, #0
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _080B0164 @ =gProjectileFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r2, #0x14]
	bx lr
	.align 2, 0
_080B0164: .4byte gProjectileFnTable

	thumb_func_start FUN_080b0168
FUN_080b0168: @ 0x080B0168
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B019C
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	ldr r1, _080B0198 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _080B0206
	.align 2, 0
_080B0198: .4byte gProjectileFnTable
_080B019C:
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	beq _080B01A8
	cmp r6, #1
	beq _080B01F8
	b _080B0206
_080B01A8:
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	bl ResetDynamicMotion
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #0
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B020C @ =0x0836D624
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #2
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	movs r1, #0xb8
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	str r6, [r5, #0x60]
	ldr r0, _080B0210 @ =0xFFFFFB00
	str r0, [r5, #0x5c]
	movs r0, #0x78
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080B01F8:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateMotionGraphic
_080B0206:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B020C: .4byte 0x0836D624
_080B0210: .4byte 0xFFFFFB00

	thumb_func_start FUN_080b0214
FUN_080b0214: @ 0x080B0214
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bhi _080B02BE
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _080B0268
	cmp r5, #1
	bgt _080B0230
	cmp r5, #0
	beq _080B0236
	b _080B02D0
_080B0230:
	cmp r5, #2
	beq _080B0282
	b _080B02D0
_080B0236:
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldrb r1, [r4, #0xa]
	movs r0, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x11
	strb r0, [r1]
	strb r5, [r4, #0x12]
	movs r1, #0xb9
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080B0268:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #5
	beq _080B02D0
	b _080B02B6
_080B0282:
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0x12]
	adds r0, r1, #0
	adds r0, #0xff
	strb r0, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B02A8
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080B02AE
_080B02A8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080B02AE:
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _080B02D0
_080B02B6:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
_080B02BE:
	ldr r1, _080B02D8 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080B02D0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B02D8: .4byte gProjectileFnTable

	thumb_func_start FUN_080b02dc
FUN_080b02dc: @ 0x080B02DC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080B0300
	ldr r1, _080B02FC @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080B0368
	.align 2, 0
_080B02FC: .4byte gProjectileFnTable
_080B0300:
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080B030C
	cmp r5, #1
	beq _080B0334
	b _080B0368
_080B030C:
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldrb r1, [r4, #0xa]
	movs r0, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	strb r5, [r4, #0x12]
	ldr r1, _080B034C @ =0x0000B902
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080B0334:
	ldrb r1, [r4, #0x12]
	adds r0, r1, #1
	strb r0, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B0350
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080B0356
	.align 2, 0
_080B034C: .4byte 0x0000B902
_080B0350:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080B0356:
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x28]
	ldr r1, [r0, #0x54]
	str r1, [r4, #0x54]
	ldr r0, [r0, #0x58]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080B0368:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start omega2_080b0370
omega2_080b0370: @ 0x080B0370
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #9
	bhi _080B0388
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080B0388
	movs r0, #0xa
	strb r0, [r7, #0xe]
_080B0388:
	ldrb r0, [r7, #0xe]
	cmp r0, #0x10
	bls _080B0390
	b _080B07BA
_080B0390:
	lsls r0, r0, #2
	ldr r1, _080B039C @ =_080B03A0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080B039C: .4byte _080B03A0
_080B03A0: @ jump table
	.4byte _080B03E4 @ case 0
	.4byte _080B0460 @ case 1
	.4byte _080B055C @ case 2
	.4byte _080B05E4 @ case 3
	.4byte _080B06A4 @ case 4
	.4byte _080B07BA @ case 5
	.4byte _080B07BA @ case 6
	.4byte _080B07BA @ case 7
	.4byte _080B07BA @ case 8
	.4byte _080B07BA @ case 9
	.4byte _080B06FC @ case 10
	.4byte _080B0706 @ case 11
	.4byte _080B07BA @ case 12
	.4byte _080B07BA @ case 13
	.4byte _080B07BA @ case 14
	.4byte _080B0754 @ case 15
	.4byte _080B0776 @ case 16
_080B03E4:
	adds r0, r7, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldrb r1, [r7, #0xa]
	movs r0, #2
	movs r6, #0
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _080B04C4 @ =0x0836D63C
	adds r5, r7, #0
	adds r5, #0x54
	adds r0, r4, #0
	adds r2, r5, #0
	movs r3, #2
	bl InitBody
	str r7, [r4, #0x2c]
	str r6, [r4, #0x24]
	adds r1, r7, #0
	adds r1, #0x25
	movs r0, #0x11
	strb r0, [r1]
	ldr r1, _080B04C8 @ =0x0000B901
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #2
	bl FUN_080afedc
	movs r0, #0x99
	lsls r0, r0, #1
	bl PlaySound
	ldr r2, [r7, #0x28]
	ldr r0, [r2, #0x54]
	ldr r1, [r7, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x64]
	str r0, [r7, #0x54]
	ldr r0, [r2, #0x58]
	ldr r1, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x68]
	str r0, [r7, #0x58]
	movs r0, #0xff
	strb r0, [r7, #0x12]
	movs r0, #1
	strb r0, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080B0460:
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	beq _080B0500
	subs r0, #1
	strb r0, [r7, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B0500
	ldr r0, _080B04CC @ =pZero2
	ldr r1, [r0]
	ldr r2, [r1, #0x54]
	ldr r0, [r7, #0x54]
	subs r2, r2, r0
	str r2, [sp]
	ldr r0, [r7, #0x58]
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r0, r0, r3
	ldr r1, [r1, #0x58]
	subs r1, r1, r0
	str r1, [sp, #4]
	cmp r2, #0
	bne _080B0492
	cmp r1, #0
	beq _080B04D0
_080B0492:
	ldr r1, [sp]
	adds r0, r1, #0
	muls r0, r1, r0
	ldr r2, [sp, #4]
	adds r1, r2, #0
	muls r1, r2, r1
	adds r0, r0, r1
	bl Sqrt
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r3, [sp]
	lsls r0, r3, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [sp]
	ldr r1, [sp, #4]
	lsls r0, r1, #8
	adds r1, r4, #0
	bl __divsi3
	b _080B04D6
	.align 2, 0
_080B04C4: .4byte 0x0836D63C
_080B04C8: .4byte 0x0000B901
_080B04CC: .4byte pZero2
_080B04D0:
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [sp]
_080B04D6:
	str r0, [sp, #4]
	ldr r2, [sp]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #6
	asrs r0, r0, #8
	str r0, [r7, #0x5c]
	ldr r3, [sp, #4]
	cmp r3, #0
	bge _080B04F0
	lsls r0, r3, #1
	adds r0, r0, r3
	b _080B04F6
_080B04F0:
	ldr r1, [sp, #4]
	lsls r0, r1, #2
	adds r0, r0, r1
_080B04F6:
	lsls r0, r0, #6
	asrs r0, r0, #8
	str r0, [r7, #0x60]
	movs r0, #0x18
	strb r0, [r7, #0x13]
_080B0500:
	ldr r0, _080B0540 @ =pZero2
	ldr r0, [r0]
	ldrb r1, [r0, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B0512
	movs r0, #0x18
	strb r0, [r7, #0x13]
_080B0512:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080B0544
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _080B07BA
	.align 2, 0
_080B0540: .4byte pZero2
_080B0544:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080B0556
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080B0556
	b _080B07BA
_080B0556:
	movs r0, #0xa
	strb r0, [r7, #0xe]
	b _080B07BA
_080B055C:
	movs r6, #0
	ldr r1, [r7, #0x64]
	ldr r0, [r7, #0x54]
	subs r1, r1, r0
	adds r4, r1, #0
	ldr r2, [r7, #0x68]
	ldr r0, [r7, #0x58]
	subs r2, r2, r0
	adds r5, r2, #0
	cmp r1, #0
	bne _080B0576
	cmp r2, #0
	beq _080B059E
_080B0576:
	adds r0, r4, #0
	muls r0, r4, r0
	adds r1, r5, #0
	muls r1, r5, r1
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r0, r4, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	lsls r0, r5, #8
	adds r1, r6, #0
	bl __divsi3
	adds r5, r0, #0
	b _080B05A2
_080B059E:
	movs r4, #0x80
	lsls r4, r4, #1
_080B05A2:
	lsls r0, r4, #8
	asrs r0, r0, #8
	str r0, [r7, #0x5c]
	lsls r0, r5, #8
	asrs r0, r0, #8
	str r0, [r7, #0x60]
	str r6, [r7, #0x64]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r7, #0x68]
	adds r3, r7, #0
	adds r3, #0xb4
	ldr r0, _080B063C @ =pZero2
	ldr r2, [r0]
	ldr r0, [r2, #0x54]
	ldr r1, [r7, #0x54]
	subs r0, r0, r1
	str r0, [r3]
	adds r3, #4
	ldr r0, [r2, #0x58]
	ldr r1, [r7, #0x58]
	subs r0, r0, r1
	str r0, [r3]
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _080B0640 @ =0x0836D654
	bl SetDDP
	movs r0, #0x3c
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080B05E4:
	ldr r1, [r7, #0x54]
	ldr r0, [r7, #0x5c]
	adds r3, r1, r0
	str r3, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r0, [r7, #0x60]
	adds r1, r1, r0
	str r1, [r7, #0x58]
	ldr r0, _080B0644 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r2, _080B0648 @ =0x000027FF
	adds r0, r0, r2
	cmp r1, r0
	bge _080B064C
	adds r3, r7, #0
	adds r3, #0xb4
	ldr r1, [r3]
	rsbs r0, r1, #0
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r3]
	adds r2, r7, #0
	adds r2, #0xb8
	ldr r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #5
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r2]
	ldr r0, _080B063C @ =pZero2
	ldr r4, [r0]
	ldr r0, [r7, #0x54]
	ldr r1, [r3]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r2]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	b _080B0666
	.align 2, 0
_080B063C: .4byte pZero2
_080B0640: .4byte 0x0836D654
_080B0644: .4byte gStageRun+232
_080B0648: .4byte 0x000027FF
_080B064C:
	ldr r0, _080B069C @ =pZero2
	ldr r2, [r0]
	adds r0, r7, #0
	adds r0, #0xb4
	ldr r0, [r0]
	adds r0, r3, r0
	str r0, [r2, #0x54]
	adds r1, r7, #0
	adds r1, #0xb8
	ldr r0, [r7, #0x58]
	ldr r1, [r1]
	adds r0, r0, r1
	str r0, [r2, #0x58]
_080B0666:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x64]
	ldr r1, [r7, #0x68]
	subs r0, r0, r1
	str r0, [r7, #0x64]
	cmp r0, #0
	bgt _080B0688
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _080B06A0 @ =0x0836D66C
	bl SetDDP
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080B0688:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080B06E2
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080B069A
	b _080B07BA
_080B069A:
	b _080B06E2
	.align 2, 0
_080B069C: .4byte pZero2
_080B06A0: .4byte 0x0836D66C
_080B06A4:
	adds r3, r7, #0
	adds r3, #0xb4
	ldr r1, [r3]
	rsbs r0, r1, #0
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r3]
	adds r2, r7, #0
	adds r2, #0xb8
	ldr r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #5
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r2]
	ldr r0, _080B06F8 @ =pZero2
	ldr r4, [r0]
	ldr r0, [r7, #0x54]
	ldr r1, [r3]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r2]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
_080B06E2:
	adds r0, r7, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080B07BA
	movs r0, #0xf
	strb r0, [r7, #0xe]
	b _080B07BA
	.align 2, 0
_080B06F8: .4byte pZero2
_080B06FC:
	movs r0, #0x1a
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080B0706:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080B0732
	movs r0, #2
	strb r0, [r7, #0xe]
	b _080B07BA
_080B0732:
	ldr r0, _080B0750 @ =gStageRun+232
	adds r1, r7, #0
	adds r1, #0x54
	bl CalcFromCamera
	cmp r0, #0
	beq _080B07BA
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080B07A8
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	b _080B07A4
	.align 2, 0
_080B0750: .4byte gStageRun+232
_080B0754:
	adds r0, r7, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	movs r0, #0x1e
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080B0776:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080B0786
	subs r0, #1
	strb r0, [r7, #0x12]
_080B0786:
	ldrb r1, [r7, #0x12]
	movs r0, #1
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _080B079A
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080B07A0
_080B079A:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080B07A0:
	strb r0, [r7, #0xa]
	lsls r0, r2, #0x18
_080B07A4:
	cmp r0, #0
	bne _080B07BA
_080B07A8:
	ldr r1, _080B07C4 @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080B07BA:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B07C4: .4byte gProjectileFnTable

	thumb_func_start omega2_080b07c8
omega2_080b07c8: @ 0x080B07C8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0x15
	bls _080B07D4
	b _080B0BA4
_080B07D4:
	lsls r0, r0, #2
	ldr r1, _080B07E0 @ =_080B07E4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080B07E0: .4byte _080B07E4
_080B07E4: @ jump table
	.4byte _080B083C @ case 0
	.4byte _080B089C @ case 1
	.4byte _080B09B0 @ case 2
	.4byte _080B09E4 @ case 3
	.4byte _080B0B92 @ case 4
	.4byte _080B0BA4 @ case 5
	.4byte _080B0BA4 @ case 6
	.4byte _080B0BA4 @ case 7
	.4byte _080B0BA4 @ case 8
	.4byte _080B0BA4 @ case 9
	.4byte _080B0AB8 @ case 10
	.4byte _080B0AC8 @ case 11
	.4byte _080B0BA4 @ case 12
	.4byte _080B0BA4 @ case 13
	.4byte _080B0BA4 @ case 14
	.4byte _080B0BA4 @ case 15
	.4byte _080B0BA4 @ case 16
	.4byte _080B0BA4 @ case 17
	.4byte _080B0BA4 @ case 18
	.4byte _080B0BA4 @ case 19
	.4byte _080B0B34 @ case 20
	.4byte _080B0B5E @ case 21
_080B083C:
	adds r0, r6, #0
	bl InitNonAffineMotion
	adds r0, r6, #0
	bl ResetDynamicMotion
	ldrb r1, [r6, #0xa]
	movs r0, #2
	movs r5, #0
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080B08B8 @ =0x0836D69C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #2
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #7
	strb r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	ldr r0, _080B08BC @ =0x00000133
	bl PlaySound
	str r5, [r6, #0x64]
	ldr r0, _080B08C0 @ =0xFFFFFD00
	str r0, [r6, #0x5c]
	movs r0, #0xff
	strb r0, [r6, #0x12]
	strb r5, [r6, #0x13]
	strb r5, [r6, #0x11]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080B089C:
	movs r4, #0
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r5, #1
	ands r0, r5
	cmp r0, #0
	beq _080B08C4
	movs r0, #0xa
	strb r0, [r6, #0xe]
	b _080B0BA4
	.align 2, 0
_080B08B8: .4byte 0x0836D69C
_080B08BC: .4byte 0x00000133
_080B08C0: .4byte 0xFFFFFD00
_080B08C4:
	ldr r2, _080B08DC @ =pZero2
	ldr r3, [r2]
	ldrb r1, [r3, #0xa]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _080B08E0
	strb r4, [r6, #0xf]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _080B099C
	.align 2, 0
_080B08DC: .4byte pZero2
_080B08E0:
	ldr r0, [r6, #0x54]
	ldr r1, [r3, #0x54]
	subs r3, r0, r1
	adds r4, r0, #0
	cmp r3, #0
	ble _080B08F6
	movs r0, #0x80
	lsls r0, r0, #5
	cmp r3, r0
	bgt _080B0900
	b _080B0952
_080B08F6:
	subs r1, r1, r4
	movs r0, #0x80
	lsls r0, r0, #5
	cmp r1, r0
	ble _080B0952
_080B0900:
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	bne _080B0952
	ldr r0, [r2]
	ldr r0, [r0, #0x54]
	cmp r4, r0
	ble _080B0940
	ldr r1, _080B0938 @ =0xFFFFFD00
	adds r0, r4, r1
	str r0, [r6, #0x54]
	ldr r2, _080B093C @ =0xFFFFF500
	adds r0, r4, r2
	ldr r1, [r6, #0x58]
	bl PushoutToRight1
	adds r2, r0, #0
	cmp r2, #0
	beq _080B0948
	ldr r0, [r6, #0x54]
	adds r0, r0, r2
	str r0, [r6, #0x54]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	movs r0, #1
	strb r0, [r6, #0xf]
	b _080B0948
	.align 2, 0
_080B0938: .4byte 0xFFFFFD00
_080B093C: .4byte 0xFFFFF500
_080B0940:
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r4, r1
	str r0, [r6, #0x54]
_080B0948:
	movs r4, #0xc0
	lsls r4, r4, #2
	movs r0, #0
	str r0, [r6, #0x68]
	b _080B099A
_080B0952:
	movs r0, #1
	strb r0, [r6, #0x13]
	ldr r1, [r6, #0x58]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r1, r2
	str r0, [r6, #0x58]
	movs r0, #0xa0
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r4, #0
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	beq _080B0984
	ldr r0, [r6, #0x58]
	adds r0, r0, r2
	str r0, [r6, #0x58]
	movs r0, #0
	strb r0, [r6, #0xf]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _080B0996
_080B0984:
	ldr r0, [r6, #0x68]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r0, r1
	str r0, [r6, #0x68]
	ldr r1, _080B09A8 @ =0x00002FFF
	cmp r0, r1
	ble _080B0996
	strb r2, [r6, #0x13]
_080B0996:
	movs r4, #0x80
	lsls r4, r4, #2
_080B099A:
	str r4, [r6, #0x5c]
_080B099C:
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x64]
	ldr r1, _080B09AC @ =0x00000EFF
	b _080B0B10
	.align 2, 0
_080B09A8: .4byte 0x00002FFF
_080B09AC: .4byte 0x00000EFF
_080B09B0:
	ldr r0, _080B09CC @ =pZero2
	ldr r2, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B09DA
	ldr r1, [r6, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	ble _080B09D4
	ldr r0, _080B09D0 @ =0xFFFFFD00
	b _080B09D8
	.align 2, 0
_080B09CC: .4byte pZero2
_080B09D0: .4byte 0xFFFFFD00
_080B09D4:
	movs r0, #0xc0
	lsls r0, r0, #2
_080B09D8:
	str r0, [r6, #0x5c]
_080B09DA:
	movs r0, #0x3c
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080B09E4:
	movs r5, #0
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, _080B0A08 @ =pZero2
	ldr r0, [r0]
	ldrb r1, [r0, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B0A0C
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
_080B0A02:
	movs r5, #0xc0
	lsls r5, r5, #2
	b _080B0A74
	.align 2, 0
_080B0A08: .4byte pZero2
_080B0A0C:
	ldr r1, [r6, #0x5c]
	cmp r1, #0
	bge _080B0A34
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r2, _080B0A30 @ =0xFFFFF800
	adds r0, r0, r2
	ldr r1, [r6, #0x58]
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	beq _080B0A02
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	b _080B0A68
	.align 2, 0
_080B0A30: .4byte 0xFFFFF800
_080B0A34:
	ldrb r0, [r6, #0xf]
	cmp r0, #0
	bne _080B0A64
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, _080B0A60 @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	ldr r0, [r6, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r0, r2
	cmp r1, r0
	beq _080B0A02
	ldrb r0, [r6, #0xf]
	adds r0, #1
	strb r0, [r6, #0xf]
	b _080B0A02
	.align 2, 0
_080B0A60: .4byte 0xFFFFF800
_080B0A64:
	cmp r0, #1
	bne _080B0A74
_080B0A68:
	ldr r0, [r6, #0x58]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r5, r1, #0
_080B0A74:
	ldr r0, _080B0AB0 @ =gStageRun+232
	adds r4, r6, #0
	adds r4, #0x54
	adds r1, r4, #0
	bl CalcFromCamera
	cmp r0, #0
	beq _080B0A9A
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _080B0A94
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B0A9A
_080B0A94:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080B0A9A:
	ldr r0, [r6, #0x64]
	adds r0, r0, r5
	str r0, [r6, #0x64]
	ldr r1, _080B0AB4 @ =0x00000EFF
	cmp r0, r1
	bgt _080B0AA8
	b _080B0BA4
_080B0AA8:
	ldrb r2, [r6, #0x11]
	adds r0, r6, #0
	adds r1, r4, #0
	b _080B0B1C
	.align 2, 0
_080B0AB0: .4byte gStageRun+232
_080B0AB4: .4byte 0x00000EFF
_080B0AB8:
	ldr r0, [r6, #0x58]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x68]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080B0AC8:
	ldr r2, [r6, #0x58]
	ldr r0, _080B0B2C @ =0xFFFFFC00
	adds r1, r2, r0
	ldr r3, [r6, #0x68]
	subs r1, r3, r1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r6, #0x58]
	cmp r2, r3
	ble _080B0AE6
	movs r0, #1
	strb r0, [r6, #0xe]
_080B0AE6:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _080B0B04
	ldr r0, [r6, #0x58]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	movs r0, #2
	strb r0, [r6, #0xe]
_080B0B04:
	ldr r0, [r6, #0x64]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r0, r1
	str r0, [r6, #0x64]
	ldr r1, _080B0B30 @ =0x00000FFF
_080B0B10:
	cmp r0, r1
	ble _080B0BA4
	adds r1, r6, #0
	adds r1, #0x54
	ldrb r2, [r6, #0x11]
	adds r0, r6, #0
_080B0B1C:
	bl FUN_080aff88
	movs r0, #0
	str r0, [r6, #0x64]
	ldrb r0, [r6, #0x11]
	adds r0, #1
	strb r0, [r6, #0x11]
	b _080B0BA4
	.align 2, 0
_080B0B2C: .4byte 0xFFFFFC00
_080B0B30: .4byte 0x00000FFF
_080B0B34:
	adds r0, r6, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	movs r0, #0x1e
	strb r0, [r6, #0x12]
	ldr r1, _080B0B70 @ =0x0000BA01
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080B0B5E:
	ldrb r1, [r6, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B0B74
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080B0B7A
	.align 2, 0
_080B0B70: .4byte 0x0000BA01
_080B0B74:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080B0B7A:
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _080B0B92
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B0BA4
_080B0B92:
	ldr r1, _080B0BAC @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
_080B0BA4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B0BAC: .4byte gProjectileFnTable

	thumb_func_start FUN_080b0bb0
FUN_080b0bb0: @ 0x080B0BB0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #9
	bhi _080B0BE0
	ldr r6, [r5, #0x28]
	ldrb r0, [r6, #0xc]
	cmp r0, #1
	bhi _080B0BDC
	ldrb r0, [r5, #0x11]
	movs r1, #6
	bl __umodsi3
	adds r4, r0, #0
	ldrb r0, [r6, #0x11]
	movs r1, #6
	bl __umodsi3
	lsls r4, r4, #0x18
	lsls r0, r0, #0x18
	cmp r4, r0
	bne _080B0BE0
_080B0BDC:
	movs r0, #0xa
	strb r0, [r5, #0xe]
_080B0BE0:
	ldrb r6, [r5, #0xe]
	cmp r6, #1
	beq _080B0C40
	cmp r6, #1
	bgt _080B0BF0
	cmp r6, #0
	beq _080B0BFA
	b _080B0C98
_080B0BF0:
	cmp r6, #0xa
	beq _080B0C50
	cmp r6, #0xb
	beq _080B0C76
	b _080B0C98
_080B0BFA:
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	bl ResetDynamicMotion
	ldrb r1, [r5, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B0C48 @ =0x0836D6CC
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #2
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	strb r6, [r5, #0x12]
	ldr r1, _080B0C4C @ =0x0000BA02
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080B0C40:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _080B0C98
	.align 2, 0
_080B0C48: .4byte 0x0836D6CC
_080B0C4C: .4byte 0x0000BA02
_080B0C50:
	adds r0, r5, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080B0CA0 @ =0x0000BA03
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080B0C76:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080B0C98
	ldr r1, _080B0CA4 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_080B0C98:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B0CA0: .4byte 0x0000BA03
_080B0CA4: .4byte gProjectileFnTable

	thumb_func_start omega2_080b0ca8
omega2_080b0ca8: @ 0x080B0CA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #9
	bhi _080B0CC8
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080B0CC8
	movs r0, #0xa
	strb r0, [r7, #0xe]
_080B0CC8:
	ldr r2, _080B0CF4 @ =pZero2
	ldr r0, [r2]
	ldrb r1, [r0, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B0CE0
	ldrb r0, [r7, #0xe]
	cmp r0, #0x13
	bhi _080B0CE0
	movs r0, #0x14
	strb r0, [r7, #0xe]
_080B0CE0:
	ldrb r0, [r7, #0xe]
	cmp r0, #0x14
	bls _080B0CE8
	b _080B109C
_080B0CE8:
	lsls r0, r0, #2
	ldr r1, _080B0CF8 @ =_080B0CFC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080B0CF4: .4byte pZero2
_080B0CF8: .4byte _080B0CFC
_080B0CFC: @ jump table
	.4byte _080B0D50 @ case 0
	.4byte _080B0D7E @ case 1
	.4byte _080B0DA4 @ case 2
	.4byte _080B0FBC @ case 3
	.4byte _080B109C @ case 4
	.4byte _080B109C @ case 5
	.4byte _080B109C @ case 6
	.4byte _080B109C @ case 7
	.4byte _080B109C @ case 8
	.4byte _080B109C @ case 9
	.4byte _080B1080 @ case 10
	.4byte _080B109C @ case 11
	.4byte _080B109C @ case 12
	.4byte _080B109C @ case 13
	.4byte _080B109C @ case 14
	.4byte _080B109C @ case 15
	.4byte _080B109C @ case 16
	.4byte _080B109C @ case 17
	.4byte _080B109C @ case 18
	.4byte _080B109C @ case 19
	.4byte _080B1080 @ case 20
_080B0D50:
	adds r0, r7, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldrb r1, [r7, #0xa]
	movs r0, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0xbc
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x24
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080B0D7E:
	ldr r0, [r7, #0x28]
	ldr r1, [r0, #0x54]
	str r1, [r7, #0x54]
	ldr r0, [r0, #0x58]
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _080B0D96
	b _080B0F6A
_080B0D96:
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080B0DA2
	b _080B109C
_080B0DA2:
	b _080B0F6A
_080B0DA4:
	movs r6, #0
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [r7, #0x28]
	ldr r0, [r0, #0x64]
	str r0, [sp]
	ldrb r1, [r7, #0x11]
	cmp r1, #0
	bne _080B0DD4
	ldr r1, _080B0DD0 @ =0xFFFFBC00
	adds r0, r0, r1
	str r0, [sp]
	movs r0, #0x13
	rsbs r0, r0, #0
	str r0, [r7, #0x5c]
	subs r0, #4
	str r0, [r7, #0x60]
	movs r6, #2
	b _080B0E04
	.align 2, 0
_080B0DD0: .4byte 0xFFFFBC00
_080B0DD4:
	cmp r1, #1
	bne _080B0DF0
	ldr r2, _080B0DEC @ =0xFFFF8C00
	adds r0, r0, r2
	str r0, [sp]
	movs r0, #3
	rsbs r0, r0, #0
	str r0, [r7, #0x5c]
	subs r0, #0x1f
	str r0, [r7, #0x60]
	movs r6, #3
	b _080B0E04
	.align 2, 0
_080B0DEC: .4byte 0xFFFF8C00
_080B0DF0:
	cmp r1, #2
	bne _080B0E04
	ldr r4, _080B0F74 @ =0xFFFF5C00
	adds r0, r0, r4
	str r0, [sp]
	movs r0, #0x23
	str r0, [r7, #0x5c]
	subs r0, #0x50
	str r0, [r7, #0x60]
	movs r6, #4
_080B0E04:
	ldr r0, [r7, #0x5c]
	lsls r0, r0, #8
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x60]
	lsls r0, r0, #8
	str r0, [r7, #0x60]
	adds r0, r7, #0
	mov r1, sp
	bl FUN_080b0048
	adds r0, r7, #0
	adds r0, #0xbc
	ldrh r1, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x9a
	lsls r0, r0, #1
	bl PlaySound
	ldr r0, _080B0F78 @ =pZero2
	ldr r0, [r0]
	ldrb r1, [r0, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B0E6A
	ldr r0, [r7, #0x28]
	bl CreateGhost84
	str r0, [r7, #0x2c]
	cmp r0, #0
	beq _080B0E4E
	str r7, [r0, #0x2c]
_080B0E4E:
	ldr r2, _080B0F7C @ =gWindowRegBuffer
	ldrb r1, [r2, #0xe]
	movs r0, #0xe1
	ands r0, r1
	movs r3, #0
	movs r1, #0x1f
	orrs r0, r1
	strb r0, [r2, #0xe]
	ldr r1, _080B0F80 @ =gPaletteManager
	ldr r4, _080B0F84 @ =0x0000FFFF
	adds r0, r4, #0
	strh r0, [r1]
	strh r3, [r2, #6]
	strh r3, [r2, #0xa]
_080B0E6A:
	ldr r5, _080B0F88 @ =gStageRun+232
	ldr r4, [r5, #0x3c]
	ldr r1, _080B0F8C @ =0x00003FFF
	adds r0, r4, r1
	str r0, [sp, #4]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r7, #0x64]
	str r1, [r7, #0x68]
	ldr r0, _080B0F78 @ =pZero2
	ldr r0, [r0]
	ldrb r1, [r0, #0xa]
	movs r0, #1
	ands r0, r1
	ldr r2, [r7, #0x60]
	str r2, [sp, #8]
	ldr r1, [r7, #0x58]
	mov ip, r1
	cmp r0, #0
	beq _080B0EBC
	ldr r3, _080B0F7C @ =gWindowRegBuffer
	ldr r1, [r7, #0x68]
	movs r0, #0xa0
	lsls r0, r0, #7
	adds r1, r1, r0
	subs r1, r1, r4
	asrs r1, r1, #8
	movs r2, #0xff
	ands r1, r2
	add r0, ip
	subs r0, r0, r4
	ldr r2, [sp, #8]
	adds r0, r0, r2
	asrs r0, r0, #8
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r3, #0xa]
	ldrh r1, [r3]
	ldr r0, _080B0F90 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r3]
_080B0EBC:
	ldr r1, _080B0F94 @ =0x020302DC
	ldr r4, [r7, #0x54]
	ldr r3, _080B0F98 @ =0xFFFF8801
	adds r4, r4, r3
	ldr r2, [r5, #0x38]
	subs r4, r4, r2
	ldr r0, [r7, #0x5c]
	adds r4, r4, r0
	asrs r0, r4, #8
	subs r0, #0x10
	mov sl, r0
	str r0, [r1]
	ldr r0, _080B0F9C @ =0x020302C4
	mov r8, r0
	ldr r0, _080B0FA0 @ =0x020302D4
	mov r1, sl
	str r1, [r0]
	mov r0, r8
	str r1, [r0]
	ldr r1, _080B0FA4 @ =0x020302CC
	movs r0, #0
	str r0, [r1]
	ldr r0, [r7, #0x64]
	adds r0, r0, r3
	subs r0, r0, r2
	subs r4, r4, r0
	lsls r1, r6, #8
	adds r0, r4, r1
	ldr r2, _080B0FA8 @ =0x020302E4
	str r0, [r2]
	subs r4, r4, r1
	ldr r1, _080B0FAC @ =0x020302C8
	str r4, [r1]
	ldr r2, [r7, #0x68]
	movs r1, #0xa0
	lsls r1, r1, #7
	adds r2, r2, r1
	ldr r3, [r5, #0x3c]
	subs r2, r2, r3
	asrs r2, r2, #8
	mov sb, r2
	add r1, ip
	subs r1, r1, r3
	ldr r2, [sp, #8]
	adds r1, r1, r2
	asrs r6, r1, #8
	mov r1, sb
	subs r5, r1, r6
	adds r1, r5, #0
	bl __divsi3
	mov r8, r0
	ldr r2, _080B0FA8 @ =0x020302E4
	str r0, [r2]
	adds r0, r4, #0
	adds r1, r5, #0
	bl __divsi3
	adds r2, r0, #0
	ldr r4, _080B0FAC @ =0x020302C8
	str r2, [r4]
	ldr r0, _080B0FB0 @ =0x020302D0
	str r6, [r0]
	ldr r0, _080B0FB4 @ =0x020302D8
	mov r1, sb
	str r1, [r0]
	ldr r0, [r7, #0x2c]
	cmp r0, #0
	beq _080B0F66
	mov r4, sl
	str r4, [r0, #0x74]
	ldr r0, [r7, #0x2c]
	str r6, [r0, #0x78]
	ldr r1, [r7, #0x2c]
	ldr r0, _080B0FB8 @ =0x020302C0
	ldr r0, [r0]
	str r0, [r1, #0x7c]
	ldr r0, [r7, #0x2c]
	adds r0, #0x80
	mov r1, sb
	str r1, [r0]
	ldr r0, [r7, #0x2c]
	mov r4, r8
	str r4, [r0, #0x5c]
	str r2, [r0, #0x64]
_080B0F66:
	movs r0, #0x14
	strb r0, [r7, #0x12]
_080B0F6A:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _080B109C
	.align 2, 0
_080B0F74: .4byte 0xFFFF5C00
_080B0F78: .4byte pZero2
_080B0F7C: .4byte gWindowRegBuffer
_080B0F80: .4byte gPaletteManager
_080B0F84: .4byte 0x0000FFFF
_080B0F88: .4byte gStageRun+232
_080B0F8C: .4byte 0x00003FFF
_080B0F90: .4byte 0x0000BFFF
_080B0F94: .4byte 0x020302DC
_080B0F98: .4byte 0xFFFF8801
_080B0F9C: .4byte 0x020302C4
_080B0FA0: .4byte 0x020302D4
_080B0FA4: .4byte 0x020302CC
_080B0FA8: .4byte 0x020302E4
_080B0FAC: .4byte 0x020302C8
_080B0FB0: .4byte 0x020302D0
_080B0FB4: .4byte 0x020302D8
_080B0FB8: .4byte 0x020302C0
_080B0FBC:
	ldr r1, [r7, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r7, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r7, #0x58]
	ldr r0, [r2]
	ldrb r1, [r0, #0xa]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080B1014
	ldr r1, _080B0FF4 @ =gPaletteManager
	ldr r2, _080B0FF8 @ =0x0000FFFF
	adds r0, r2, #0
	strh r0, [r1]
	ldrb r1, [r7, #0x12]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080B1004
	ldr r2, _080B0FFC @ =gWindowRegBuffer
	ldrh r1, [r2]
	ldr r0, _080B1000 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
	b _080B1014
	.align 2, 0
_080B0FF4: .4byte gPaletteManager
_080B0FF8: .4byte 0x0000FFFF
_080B0FFC: .4byte gWindowRegBuffer
_080B1000: .4byte 0x0000BFFF
_080B1004:
	ldr r0, _080B1064 @ =gWindowRegBuffer
	ldrh r2, [r0]
	movs r4, #0x80
	lsls r4, r4, #7
	adds r1, r4, #0
	orrs r1, r2
	strh r1, [r0]
	strb r3, [r0, #0xd]
_080B1014:
	ldr r1, [r7, #0x2c]
	cmp r1, #0
	beq _080B1048
	ldr r0, _080B1068 @ =0x020302DC
	ldr r0, [r0]
	str r0, [r1, #0x74]
	ldr r1, [r7, #0x2c]
	ldr r0, _080B106C @ =0x020302D0
	ldr r0, [r0]
	str r0, [r1, #0x78]
	ldr r1, [r7, #0x2c]
	ldr r0, _080B1070 @ =0x020302C0
	ldr r0, [r0]
	str r0, [r1, #0x7c]
	ldr r0, [r7, #0x2c]
	adds r0, #0x80
	ldr r1, _080B1074 @ =0x020302D8
	ldr r1, [r1]
	str r1, [r0]
	ldr r1, [r7, #0x2c]
	ldr r0, _080B1078 @ =0x020302E4
	ldr r0, [r0]
	str r0, [r1, #0x5c]
	ldr r0, _080B107C @ =0x020302C8
	ldr r0, [r0]
	str r0, [r1, #0x64]
_080B1048:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080B105E
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B109C
_080B105E:
	movs r0, #0xa
	strb r0, [r7, #0xe]
	b _080B109C
	.align 2, 0
_080B1064: .4byte gWindowRegBuffer
_080B1068: .4byte 0x020302DC
_080B106C: .4byte 0x020302D0
_080B1070: .4byte 0x020302C0
_080B1074: .4byte 0x020302D8
_080B1078: .4byte 0x020302E4
_080B107C: .4byte 0x020302C8
_080B1080:
	ldr r2, _080B10AC @ =gWindowRegBuffer
	ldrh r1, [r2]
	ldr r0, _080B10B0 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _080B10B4 @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080B109C:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B10AC: .4byte gWindowRegBuffer
_080B10B0: .4byte 0x0000BFFF
_080B10B4: .4byte gProjectileFnTable

	thumb_func_start FUN_080b10b8
FUN_080b10b8: @ 0x080B10B8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xe]
	cmp r6, #1
	beq _080B1124
	cmp r6, #1
	bgt _080B10CC
	cmp r6, #0
	beq _080B10D2
	b _080B1162
_080B10CC:
	cmp r6, #0xa
	beq _080B1150
	b _080B1162
_080B10D2:
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	bl ResetDynamicMotion
	ldrb r1, [r5, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B1140 @ =0x0836D6E4
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #2
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080B1144 @ =0x0000BB06
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x14
	strb r0, [r5, #0x12]
	ldr r0, _080B1148 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r1, _080B114C @ =0x00003FFF
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080B1124:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080B113A
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B1162
_080B113A:
	movs r0, #0xa
	strb r0, [r5, #0xe]
	b _080B1162
	.align 2, 0
_080B1140: .4byte 0x0836D6E4
_080B1144: .4byte 0x0000BB06
_080B1148: .4byte gStageRun+232
_080B114C: .4byte 0x00003FFF
_080B1150:
	ldr r1, _080B1168 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_080B1162:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B1168: .4byte gProjectileFnTable

	thumb_func_start FUN_080b116c
FUN_080b116c: @ 0x080B116C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _080B11EA
	cmp r0, #4
	beq _080B11EA
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	beq _080B1188
	cmp r6, #1
	beq _080B11B4
	b _080B1220
_080B1188:
	ldrb r1, [r5, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B1228 @ =0x0836D48C
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldrb r1, [r5, #0xa]
	movs r0, #2
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080B11B4:
	ldr r2, [r5, #0x2c]
	ldr r0, [r2, #0x54]
	ldr r1, [r2, #0x58]
	str r0, [r5, #0x54]
	str r1, [r5, #0x58]
	ldr r0, _080B122C @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	str r0, [r5, #0x54]
	adds r2, #0xbc
	ldr r1, [r2]
	asrs r1, r1, #9
	adds r0, r5, #0
	adds r0, #0x74
	movs r2, #0x10
	subs r2, r2, r1
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _080B1228 @ =0x0836D48C
	adds r1, r1, r2
	bl SetDDP
	ldr r0, [r5, #0x2c]
	ldrb r0, [r0, #0xe]
	cmp r0, #9
	bls _080B1220
_080B11EA:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080B1230 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_080B1220:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B1228: .4byte 0x0836D48C
_080B122C: .4byte pZero2
_080B1230: .4byte gProjectileFnTable
