	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080bc058
FUN_080bc058: @ 0x080BC058
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _080BC0A8 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080BC0A0
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BC0AC @ =gVFXFnTable
	movs r1, #0x24
	strb r1, [r3, #9]
	adds r0, #0x90
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
	str r6, [r3, #0x28]
_080BC0A0:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080BC0A8: .4byte gVFXHeaderPtr
_080BC0AC: .4byte gVFXFnTable

	thumb_func_start volteel_080bc0b0
volteel_080bc0b0: @ 0x080BC0B0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	ldr r0, _080BC100 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080BC0F6
	adds r0, #0x25
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r0, _080BC104 @ =gVFXFnTable
	movs r1, #0x24
	strb r1, [r4, #9]
	adds r0, #0x90
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
	str r7, [r4, #0x28]
_080BC0F6:
	adds r0, r4, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080BC100: .4byte gVFXHeaderPtr
_080BC104: .4byte gVFXFnTable

	thumb_func_start VFX36_Init
VFX36_Init: @ 0x080BC108
	push {r4, r5, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r0, [r4, #0xa]
	movs r1, #1
	movs r5, #0
	orrs r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r4, #0xa]
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldrb r2, [r4, #0x10]
	cmp r2, #0
	bne _080BC14A
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r0, #0x80
	b _080BC170
_080BC14A:
	movs r2, #1
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	movs r0, #0x80
	rsbs r0, r0, #0
_080BC170:
	str r0, [r4, #0x5c]
	movs r2, #0
	str r2, [r4, #0x60]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _080BC19C
	movs r0, #0xff
	strb r0, [r4, #0x12]
	ldr r1, _080BC198 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r1, [r4, #0xd]
	b _080BC1B4
	.align 2, 0
_080BC198: .4byte gVFXFnTable
_080BC19C:
	movs r0, #0xff
	strb r0, [r4, #0x12]
	ldr r1, _080BC1C4 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r2, [r4, #0xd]
_080BC1B4:
	strb r2, [r4, #0xe]
	strb r2, [r4, #0xf]
	adds r0, r4, #0
	bl VFX36_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BC1C4: .4byte gVFXFnTable

	thumb_func_start VFX36_Update
VFX36_Update: @ 0x080BC1C8
	push {lr}
	ldr r2, _080BC1DC @ =0x0836EDB8
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080BC1DC: .4byte 0x0836EDB8

	thumb_func_start VFX36_Die
VFX36_Die: @ 0x080BC1E0
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080BC1FC @ =gVFXFnTable
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
_080BC1FC: .4byte gVFXFnTable

	thumb_func_start FUN_080bc200
FUN_080bc200: @ 0x080BC200
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080BC220
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	b _080BC442
_080BC220:
	ldrb r0, [r4, #0xe]
	cmp r0, #7
	bls _080BC228
	b _080BC454
_080BC228:
	lsls r0, r0, #2
	ldr r1, _080BC234 @ =_080BC238
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080BC234: .4byte _080BC238
_080BC238: @ jump table
	.4byte _080BC258 @ case 0
	.4byte _080BC326 @ case 1
	.4byte _080BC340 @ case 2
	.4byte _080BC3E0 @ case 3
	.4byte _080BC37C @ case 4
	.4byte _080BC3E0 @ case 5
	.4byte _080BC3FE @ case 6
	.4byte _080BC432 @ case 7
_080BC258:
	adds r2, r4, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	ldrb r5, [r4, #0x10]
	cmp r5, #0
	bne _080BC290
	ldr r1, _080BC28C @ =0x0000A605
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4d
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	b _080BC2B6
	.align 2, 0
_080BC28C: .4byte 0x0000A605
_080BC290:
	cmp r5, #1
	bne _080BC2C0
	ldr r1, _080BC2BC @ =0x0000A602
	adds r0, r4, #0
	bl SetMotion
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
_080BC2B6:
	ands r0, r1
	strb r0, [r2]
	b _080BC31A
	.align 2, 0
_080BC2BC: .4byte 0x0000A602
_080BC2C0:
	cmp r5, #2
	bne _080BC2F0
	ldr r1, _080BC2EC @ =0x0000A605
	adds r0, r4, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4d
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x20
	ldrb r1, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	b _080BC314
	.align 2, 0
_080BC2EC: .4byte 0x0000A605
_080BC2F0:
	ldr r1, _080BC33C @ =0x0000A602
	adds r0, r4, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
_080BC314:
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_080BC31A:
	movs r0, #0
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BC326:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080BC338
	b _080BC454
_080BC338:
	b _080BC3F6
	.align 2, 0
_080BC33C: .4byte 0x0000A602
_080BC340:
	movs r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _080BC35C
	cmp r0, #1
	bne _080BC358
	ldr r1, _080BC354 @ =0x0000A603
	b _080BC35E
	.align 2, 0
_080BC354: .4byte 0x0000A603
_080BC358:
	cmp r0, #2
	bne _080BC36C
_080BC35C:
	ldr r1, _080BC368 @ =0x0000A606
_080BC35E:
	adds r0, r4, #0
	bl SetMotion
	b _080BC3DA
	.align 2, 0
_080BC368: .4byte 0x0000A606
_080BC36C:
	ldr r1, _080BC378 @ =0x0000A603
	adds r0, r4, #0
	bl SetMotion
	b _080BC3DA
	.align 2, 0
_080BC378: .4byte 0x0000A603
_080BC37C:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080BC38A
	str r0, [sp]
	movs r0, #0x80
	lsls r0, r0, #6
	b _080BC3B0
_080BC38A:
	cmp r0, #1
	bne _080BC398
	ldr r0, _080BC394 @ =0xFFFFE000
	b _080BC3AC
	.align 2, 0
_080BC394: .4byte 0xFFFFE000
_080BC398:
	cmp r0, #2
	bne _080BC3A8
	movs r0, #0
	str r0, [sp]
	ldr r0, _080BC3A4 @ =0xFFFFE000
	b _080BC3B0
	.align 2, 0
_080BC3A4: .4byte 0xFFFFE000
_080BC3A8:
	movs r0, #0x80
	lsls r0, r0, #6
_080BC3AC:
	str r0, [sp]
	movs r0, #0
_080BC3B0:
	str r0, [sp, #4]
	ldr r0, [r4, #0x54]
	ldr r1, [sp]
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, [sp, #4]
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r0, [r4, #0x28]
	mov r1, sp
	bl FUN_0809f48c
	movs r0, #0x7e
	bl PlaySound
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r0, #0xa
	strb r0, [r4, #0x12]
_080BC3DA:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BC3E0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080BC3F6
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BC454
_080BC3F6:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080BC454
_080BC3FE:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _080BC414
	cmp r0, #1
	bne _080BC410
	ldr r1, _080BC40C @ =0x0000A604
	b _080BC416
	.align 2, 0
_080BC40C: .4byte 0x0000A604
_080BC410:
	cmp r0, #2
	bne _080BC424
_080BC414:
	ldr r1, _080BC420 @ =0x0000A607
_080BC416:
	adds r0, r4, #0
	bl SetMotion
	b _080BC42C
	.align 2, 0
_080BC420: .4byte 0x0000A607
_080BC424:
	ldr r1, _080BC45C @ =0x0000A604
	adds r0, r4, #0
	bl SetMotion
_080BC42C:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BC432:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080BC454
_080BC442:
	ldr r1, _080BC460 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080BC454:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BC45C: .4byte 0x0000A604
_080BC460: .4byte gVFXFnTable

	thumb_func_start FUN_080bc464
FUN_080bc464: @ 0x080BC464
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _080BC4BE
	cmp r5, #1
	bgt _080BC478
	cmp r5, #0
	beq _080BC47E
	b _080BC534
_080BC478:
	cmp r5, #2
	beq _080BC506
	b _080BC534
_080BC47E:
	ldr r1, _080BC49C @ =0x0000A505
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080BC4A0
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #4
	b _080BC4A6
	.align 2, 0
_080BC49C: .4byte 0x0000A505
_080BC4A0:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	ldr r2, _080BC4F8 @ =0xFFFFF400
_080BC4A6:
	adds r0, r0, r2
	str r0, [r4, #0x64]
	movs r0, #0x80
	str r0, [r4, #0x60]
	ldr r0, [r1, #0x58]
	movs r1, #0xc0
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #0x68]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BC4BE:
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	ldrb r1, [r0, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080BC4FC
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	b _080BC534
	.align 2, 0
_080BC4F8: .4byte 0xFFFFF400
_080BC4FC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	b _080BC534
_080BC506:
	ldr r0, [r4, #0x28]
	ldr r0, [r0, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080BC534
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _080BC53C @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080BC534:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BC53C: .4byte gVFXFnTable
