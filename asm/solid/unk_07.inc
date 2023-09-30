	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Solid7_Init
Solid7_Init: @ 0x080CC848
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r1, [r5, #0xa]
	movs r0, #2
	orrs r0, r1
	movs r1, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldr r1, _080CC880 @ =gSolidFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldrb r0, [r5, #0x10]
	cmp r0, #0xc
	bne _080CC884
	movs r0, #5
	strb r0, [r5, #0xd]
	b _080CC8D8
	.align 2, 0
_080CC880: .4byte gSolidFnTable
_080CC884:
	movs r0, #0
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080CC8E4 @ =0x0836FFAC
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _080CC8E8 @ =onCollision
	str r0, [r4, #0x24]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	ldr r1, _080CC8EC @ =0xFFFFF200
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r1, r5, #0
	adds r1, #0xb8
	str r0, [r1]
	adds r1, #8
	ldr r0, [r5, #0x54]
	str r0, [r1]
	ldrb r0, [r5, #0xb]
	movs r1, #8
	orrs r0, r1
	strb r0, [r5, #0xb]
	ldr r0, _080CC8F0 @ =0x0836FFDC
	str r0, [r5, #0x30]
	ldr r0, _080CC8F4 @ =0x00000811
	strh r0, [r5, #0x26]
	adds r0, r5, #0
	bl CreateLavaGeyserPlatform
_080CC8D8:
	adds r0, r5, #0
	bl Solid7_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CC8E4: .4byte 0x0836FFAC
_080CC8E8: .4byte onCollision
_080CC8EC: .4byte 0xFFFFF200
_080CC8F0: .4byte 0x0836FFDC
_080CC8F4: .4byte 0x00000811

	thumb_func_start Solid7_Update
Solid7_Update: @ 0x080CC8F8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080CC924 @ =0x0836FF7C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080CC928 @ =0x0836FF94
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CC924: .4byte 0x0836FF7C
_080CC928: .4byte 0x0836FF94

	thumb_func_start Solid7_Die
Solid7_Die: @ 0x080CC92C
	bx lr
	.align 2, 0

	thumb_func_start nop_080cc930
nop_080cc930: @ 0x080CC930
	bx lr
	.align 2, 0

	thumb_func_start FUN_080cc934
FUN_080cc934: @ 0x080CC934
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _080CC960
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0x30
	bne _080CC960
	movs r0, #0x40
	bl PlaySound
	movs r1, #0
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080CC960:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080cc968
FUN_080cc968: @ 0x080CC968
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080CC978
	cmp r0, #1
	beq _080CC996
	b _080CC9F2
_080CC978:
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x64]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CC9F8 @ =0x0836FFAC
	bl SetDDP
	movs r1, #0xe4
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CC996:
	ldr r0, _080CC9FC @ =gOverworld
	ldr r1, _080CCA00 @ =0x0002D02C
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrb r2, [r4, #0x10]
	movs r1, #3
	ands r2, r1
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #2
	subs r1, r1, r2
	subs r0, r0, r1
	adds r0, #1
	movs r1, #0x86
	lsls r1, r1, #1
	bl __modsi3
	adds r5, r0, #0
	cmp r5, #0xec
	ble _080CC9E2
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r2, [r0]
	ldr r0, _080CCA04 @ =0xFFFFFE00
	adds r2, r2, r0
	ldr r3, _080CCA08 @ =RNG_0202f388
	ldr r1, [r3]
	ldr r0, _080CCA0C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080CCA10 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsls r0, r0, #5
	lsrs r0, r0, #0x16
	adds r2, r2, r0
	str r2, [r4, #0x54]
_080CC9E2:
	cmp r5, #0
	bne _080CC9EC
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
_080CC9EC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080CC9F2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CC9F8: .4byte 0x0836FFAC
_080CC9FC: .4byte gOverworld
_080CCA00: .4byte 0x0002D02C
_080CCA04: .4byte 0xFFFFFE00
_080CCA08: .4byte RNG_0202f388
_080CCA0C: .4byte 0x000343FD
_080CCA10: .4byte 0x00269EC3

	thumb_func_start FUN_080cca14
FUN_080cca14: @ 0x080CCA14
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080CCA24
	cmp r5, #1
	beq _080CCA58
	b _080CCAC2
_080CCA24:
	movs r0, #0x77
	bl PlaySound
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x64]
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0x10]
	lsrs r5, r0, #2
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #0xb
	ldr r1, _080CCAC8 @ =0xFFFF4000
	adds r0, r0, r1
	str r0, [r4, #0x68]
	lsls r2, r5, #2
	movs r1, #0x18
	subs r1, r1, r2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	bl __divsi3
	str r0, [r4, #0x68]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CCA58:
	ldrb r0, [r4, #0x10]
	lsrs r5, r0, #2
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r2, [r0]
	ldr r0, _080CCACC @ =0xFFFFFE00
	adds r2, r2, r0
	ldr r3, _080CCAD0 @ =RNG_0202f388
	ldr r1, [r3]
	ldr r0, _080CCAD4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080CCAD8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsls r0, r0, #5
	lsrs r0, r0, #0x16
	adds r2, r2, r0
	str r2, [r4, #0x54]
	ldr r2, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r2, r2, r0
	str r2, [r4, #0x58]
	ldr r1, [r4, #0x68]
	adds r0, r0, r1
	str r0, [r4, #0x60]
	adds r3, r4, #0
	adds r3, #0xb8
	ldr r1, [r3]
	subs r1, r1, r2
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r2, r0, #0xb
	movs r0, #0xc0
	lsls r0, r0, #7
	subs r0, r0, r2
	cmp r1, r0
	ble _080CCABC
	ldr r0, [r4, #0x64]
	str r0, [r4, #0x54]
	ldr r0, [r3]
	ldr r1, _080CCADC @ =0xFFFFA000
	adds r0, r0, r1
	adds r0, r0, r2
	str r0, [r4, #0x58]
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080CCABC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080CCAC2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CCAC8: .4byte 0xFFFF4000
_080CCACC: .4byte 0xFFFFFE00
_080CCAD0: .4byte RNG_0202f388
_080CCAD4: .4byte 0x000343FD
_080CCAD8: .4byte 0x00269EC3
_080CCADC: .4byte 0xFFFFA000

	thumb_func_start FUN_080ccae0
FUN_080ccae0: @ 0x080CCAE0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080CCAF0
	cmp r0, #1
	beq _080CCAFE
	b _080CCB3A
_080CCAF0:
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x64]
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CCAFE:
	ldr r5, [r4, #0x64]
	ldr r0, _080CCB40 @ =0xFFFFFE00
	adds r2, r5, r0
	ldr r3, _080CCB44 @ =RNG_0202f388
	ldr r1, [r3]
	ldr r0, _080CCB48 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080CCB4C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsls r0, r0, #6
	lsrs r0, r0, #0x17
	adds r2, r2, r0
	str r2, [r4, #0x54]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080CCB34
	str r5, [r4, #0x54]
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080CCB34:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080CCB3A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CCB40: .4byte 0xFFFFFE00
_080CCB44: .4byte RNG_0202f388
_080CCB48: .4byte 0x000343FD
_080CCB4C: .4byte 0x00269EC3

	thumb_func_start FUN_080ccb50
FUN_080ccb50: @ 0x080CCB50
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080CCB60
	cmp r5, #1
	beq _080CCBAA
	b _080CCBFA
_080CCB60:
	ldrb r1, [r4, #0xb]
	movs r0, #8
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldr r0, _080CCC00 @ =0x0836FFDC
	str r0, [r4, #0x30]
	ldr r0, _080CCC04 @ =0x00000811
	strh r0, [r4, #0x26]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CCC08 @ =0x0836FFAC
	bl SetDDP
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x64]
	str r5, [r4, #0x60]
	ldrb r2, [r4, #0x10]
	lsrs r2, r2, #2
	movs r0, #0xc0
	lsls r0, r0, #8
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r2, r1, #3
	lsls r1, r1, #0xb
	subs r0, r0, r1
	str r0, [r4, #0x68]
	movs r1, #0x64
	subs r1, r1, r2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	bl __divsi3
	str r0, [r4, #0x68]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CCBAA:
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r2, [r0]
	ldr r0, _080CCC0C @ =0xFFFFFE00
	adds r2, r2, r0
	ldr r3, _080CCC10 @ =RNG_0202f388
	ldr r1, [r3]
	ldr r0, _080CCC14 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080CCC18 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsls r0, r0, #6
	lsrs r0, r0, #0x17
	adds r2, r2, r0
	str r2, [r4, #0x54]
	ldr r2, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r2, r2, r0
	str r2, [r4, #0x58]
	ldr r1, [r4, #0x68]
	adds r0, r0, r1
	str r0, [r4, #0x60]
	adds r1, r4, #0
	adds r1, #0xb8
	ldr r0, [r1]
	cmp r2, r0
	ble _080CCBF4
	ldr r0, [r4, #0x64]
	str r0, [r4, #0x54]
	ldr r0, [r1]
	str r0, [r4, #0x58]
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_080CCBF4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080CCBFA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CCC00: .4byte 0x0836FFDC
_080CCC04: .4byte 0x00000811
_080CCC08: .4byte 0x0836FFAC
_080CCC0C: .4byte 0xFFFFFE00
_080CCC10: .4byte RNG_0202f388
_080CCC14: .4byte 0x000343FD
_080CCC18: .4byte 0x00269EC3

	thumb_func_start FUN_080ccc1c
FUN_080ccc1c: @ 0x080CCC1C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080CCC2E
	cmp r0, #1
	beq _080CCC7C
	b _080CCC90
_080CCC2E:
	ldrb r1, [r4, #0xb]
	movs r0, #8
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldr r0, _080CCC98 @ =0x0836FFDC
	str r0, [r4, #0x30]
	ldr r0, _080CCC9C @ =0x00000801
	strh r0, [r4, #0x26]
	ldr r0, [r4, #0x64]
	str r0, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CCCA0 @ =0x0836FFC4
	bl SetDDP
	ldr r1, [r4, #0x54]
	ldr r2, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r3, [r0]
	subs r0, #4
	ldr r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	bl CreateLavaGeyser
	movs r1, #0xe4
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r0, #0xd8
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CCC7C:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080CCC90
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080CCC90:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CCC98: .4byte 0x0836FFDC
_080CCC9C: .4byte 0x00000801
_080CCCA0: .4byte 0x0836FFC4

	thumb_func_start FUN_080ccca4
FUN_080ccca4: @ 0x080CCCA4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080CCCEC
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080CCCE8 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080CCDDE
	.align 2, 0
_080CCCE8: .4byte gSolidFnTable
_080CCCEC:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080CCCF8
	cmp r0, #1
	beq _080CCD46
	b _080CCDDE
_080CCCF8:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x1d
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r1, #0xd8
	ldrb r0, [r4, #0x11]
	lsls r0, r0, #4
	subs r1, r1, r0
	strb r1, [r4, #0x12]
	ldrb r1, [r4, #0x11]
	cmp r1, #0
	bne _080CCD20
	ldr r1, _080CCD1C @ =0x00003901
	b _080CCD2A
	.align 2, 0
_080CCD1C: .4byte 0x00003901
_080CCD20:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080CCD38
	ldr r1, _080CCD34 @ =0x00003902
_080CCD2A:
	adds r0, r4, #0
	bl SetMotion
	b _080CCD40
	.align 2, 0
_080CCD34: .4byte 0x00003902
_080CCD38:
	ldr r1, _080CCD78 @ =0x00003903
	adds r0, r4, #0
	bl SetMotion
_080CCD40:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CCD46:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _080CCD56
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CCD5E
_080CCD56:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
_080CCD5E:
	ldrb r0, [r4, #0x12]
	adds r2, r0, #0
	cmp r2, #0xf
	bhi _080CCD84
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _080CCD7C
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080CCD82
	.align 2, 0
_080CCD78: .4byte 0x00003903
_080CCD7C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080CCD82:
	strb r0, [r4, #0xa]
_080CCD84:
	subs r0, r2, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _080CCDD8
	movs r0, #0x3f
	bl PlaySound
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl CreateVFX43
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080CCDE4 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080CCDD8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080CCDDE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CCDE4: .4byte gSolidFnTable
