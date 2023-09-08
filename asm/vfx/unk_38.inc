	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080bcf68
FUN_080bcf68: @ 0x080BCF68
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080BCFB4 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080BCFAC
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BCFB8 @ =gVFXFnTable
	movs r1, #0x26
	strb r1, [r3, #9]
	adds r0, #0x98
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r5, [r3, #0x10]
	strb r0, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
_080BCFAC:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080BCFB4: .4byte gVFXHeaderPtr
_080BCFB8: .4byte gVFXFnTable

	thumb_func_start FUN_080bcfbc
FUN_080bcfbc: @ 0x080BCFBC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	mov r8, r3
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	ldr r0, _080BD020 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080BD012
	adds r0, #0x25
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r0, _080BD024 @ =gVFXFnTable
	movs r1, #0x26
	strb r1, [r4, #9]
	adds r0, #0x98
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r3, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r6, [r4, #0x10]
	strb r2, [r4, #0x11]
	ldr r0, [r5]
	str r0, [r4, #0x54]
	ldr r0, [r5, #4]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0x74
	strh r7, [r0]
	mov r0, r8
	str r0, [r4, #0x78]
_080BD012:
	adds r0, r4, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080BD020: .4byte gVFXHeaderPtr
_080BD024: .4byte gVFXFnTable

	thumb_func_start VFX38_Init
VFX38_Init: @ 0x080BD028
	push {r4, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r3, #0
	adds r2, r0, #0
	orrs r2, r1
	movs r0, #2
	orrs r2, r0
	orrs r2, r3
	strb r2, [r4, #0xa]
	ldrb r1, [r4, #0x10]
	cmp r1, #0
	bne _080BD064
	movs r0, #0xef
	ands r2, r0
	strb r2, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _080BD084
_080BD064:
	movs r1, #1
	movs r0, #0x10
	orrs r2, r0
	strb r2, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_080BD084:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080BD090
	movs r0, #0x80
	rsbs r0, r0, #0
	b _080BD092
_080BD090:
	movs r0, #0x80
_080BD092:
	str r0, [r4, #0x5c]
	movs r3, #0
	str r3, [r4, #0x60]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _080BD0BC
	movs r0, #0xff
	strb r0, [r4, #0x12]
	ldr r1, _080BD0B8 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r1, [r4, #0xd]
	b _080BD0EE
	.align 2, 0
_080BD0B8: .4byte gVFXFnTable
_080BD0BC:
	ldr r2, _080BD100 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080BD104 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080BD108 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #7
	ands r0, r1
	adds r0, #0x7f
	strb r0, [r4, #0x12]
	ldr r1, _080BD10C @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	movs r0, #2
	strb r0, [r4, #0xd]
_080BD0EE:
	strb r3, [r4, #0xe]
	strb r3, [r4, #0xf]
	adds r0, r4, #0
	bl VFX38_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BD100: .4byte RNG_0202f388
_080BD104: .4byte 0x000343FD
_080BD108: .4byte 0x00269EC3
_080BD10C: .4byte gVFXFnTable

	thumb_func_start VFX38_Update
VFX38_Update: @ 0x080BD110
	push {lr}
	adds r2, r0, #0
	ldr r0, _080BD13C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080BD144
	ldr r1, _080BD140 @ =gVFXFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	adds r0, r2, #0
	bl VFX38_Die
	b _080BD154
	.align 2, 0
_080BD13C: .4byte gCurStory
_080BD140: .4byte gVFXFnTable
_080BD144:
	ldr r0, _080BD158 @ =0x0836EE24
	ldrb r1, [r2, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_080BD154:
	pop {r0}
	bx r0
	.align 2, 0
_080BD158: .4byte 0x0836EE24

	thumb_func_start VFX38_Die
VFX38_Die: @ 0x080BD15C
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080BD178 @ =gVFXFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_080BD178: .4byte gVFXFnTable

	thumb_func_start nop_080bd17c
nop_080bd17c: @ 0x080BD17C
	bx lr
	.align 2, 0

	thumb_func_start FUN_080bd180
FUN_080bd180: @ 0x080BD180
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BD208
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	ldr r2, _080BD1F0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080BD1F4 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080BD1F8 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	str r0, [sp, #4]
	ldrb r1, [r5, #0x10]
	ldr r2, _080BD1FC @ =0x00003506
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080bcfbc
	ldrb r1, [r5, #0x10]
	ldr r2, _080BD200 @ =0x00003508
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080bcfbc
	movs r0, #0x31
	bl PlaySound
	ldr r1, _080BD204 @ =gVFXFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _080BD26A
	.align 2, 0
_080BD1F0: .4byte RNG_0202f388
_080BD1F4: .4byte 0x000343FD
_080BD1F8: .4byte 0x00269EC3
_080BD1FC: .4byte 0x00003506
_080BD200: .4byte 0x00003508
_080BD204: .4byte gVFXFnTable
_080BD208:
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _080BD214
	cmp r0, #1
	beq _080BD244
	b _080BD26A
_080BD214:
	movs r0, #0x28
	strb r0, [r5, #0x12]
	ldr r2, _080BD274 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080BD278 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080BD27C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x1f
	ands r0, r1
	ldr r1, _080BD280 @ =0xFFFFFE80
	adds r0, r0, r1
	str r0, [r5, #0x60]
	ldr r1, _080BD284 @ =0x00003505
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080BD244:
	ldr r0, [r5, #0x60]
	adds r0, #0x10
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080BD254
	str r1, [r5, #0x60]
_080BD254:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateMotionGraphic
_080BD26A:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BD274: .4byte RNG_0202f388
_080BD278: .4byte 0x000343FD
_080BD27C: .4byte 0x00269EC3
_080BD280: .4byte 0xFFFFFE80
_080BD284: .4byte 0x00003505

	thumb_func_start FUN_080bd288
FUN_080bd288: @ 0x080BD288
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080BD2BE
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080BD2E0
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080BD2E0
	ldr r0, [r7, #0x60]
	cmp r0, #0
	ble _080BD2E0
_080BD2BE:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	ldr r1, _080BD2DC @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	b _080BD3AE
	.align 2, 0
_080BD2DC: .4byte gVFXFnTable
_080BD2E0:
	ldrb r0, [r7, #0xe]
	mov sb, r0
	cmp r0, #0
	beq _080BD2EE
	cmp r0, #1
	beq _080BD358
	b _080BD3AE
_080BD2EE:
	ldr r4, _080BD370 @ =0x0836EE90
	movs r1, #0x74
	adds r1, r1, r7
	mov r8, r1
	ldrh r0, [r1]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xe
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r2, [r7, #0x78]
	lsls r2, r2, #3
	adds r2, r2, r0
	ldr r3, _080BD374 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r6, _080BD378 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r5, _080BD37C @ =0x00269EC3
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r4, r1, #1
	str r4, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x1f
	ands r1, r0
	ldr r0, [r2, #4]
	adds r0, r0, r1
	str r0, [r7, #0x60]
	adds r1, r4, #0
	muls r1, r6, r1
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x3f
	ands r1, r0
	ldr r0, [r2]
	subs r0, r0, r1
	str r0, [r7, #0x5c]
	mov r0, r8
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	mov r1, sb
	strb r1, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080BD358:
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	movs r1, #0xff
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080BD380
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080BD386
	.align 2, 0
_080BD370: .4byte 0x0836EE90
_080BD374: .4byte RNG_0202f388
_080BD378: .4byte 0x000343FD
_080BD37C: .4byte 0x00269EC3
_080BD380:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080BD386:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x60]
	adds r0, #0x10
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080BD398
	str r1, [r7, #0x60]
_080BD398:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	bl UpdateMotionGraphic
_080BD3AE:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
