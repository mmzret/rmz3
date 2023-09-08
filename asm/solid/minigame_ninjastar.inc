	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start MgNinjaStar_Update
MgNinjaStar_Update: @ 0x080D925C
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x28]
	ldr r0, [r2, #8]
	ldr r0, [r0, #0x54]
	ldr r3, [r4, #0x54]
	subs r0, r0, r3
	movs r1, #0xc0
	lsls r1, r1, #8
	cmp r0, r1
	ble _080D92B0
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
	ldr r1, _080D92AC @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080D92DE
	.align 2, 0
_080D92AC: .4byte gSolidFnTable
_080D92B0:
	ldr r0, [r2, #0x14]
	adds r0, r3, r0
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x64]
	ldr r1, [r2, #0x14]
	adds r0, r0, r1
	str r0, [r4, #0x64]
	ldr r1, _080D92E4 @ =0x08371180
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080D92E8 @ =0x08371188
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080D92DE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D92E4: .4byte 0x08371180
_080D92E8: .4byte 0x08371188

	thumb_func_start MgNinjaStar_Die
MgNinjaStar_Die: @ 0x080D92EC
	ldr r2, _080D9300 @ =gSolidFnTable
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
_080D9300: .4byte gSolidFnTable

	thumb_func_start nop_080d9304
nop_080d9304: @ 0x080D9304
	bx lr
	.align 2, 0

	thumb_func_start FUN_080d9308
FUN_080d9308: @ 0x080D9308
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080D931A
	cmp r0, #1
	beq _080D932A
	b _080D9362
_080D931A:
	movs r1, #0x86
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080D932A:
	ldr r0, [r5, #8]
	ldr r1, [r4, #0x58]
	ldr r2, _080D934C @ =0xFFFFFF00
	adds r1, r1, r2
	ldr r0, [r0, #0x58]
	cmp r0, r1
	bge _080D9354
	ldrb r1, [r4, #0xb]
	movs r0, #8
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldr r0, _080D9350 @ =0x08371194
	str r0, [r4, #0x30]
	movs r0, #1
	strh r0, [r4, #0x26]
	b _080D935C
	.align 2, 0
_080D934C: .4byte 0xFFFFFF00
_080D9350: .4byte 0x08371194
_080D9354:
	ldrb r1, [r4, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r4, #0xb]
_080D935C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080D9362:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d9368
FUN_080d9368: @ 0x080D9368
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	mov r8, r0
	ldrb r1, [r5, #0xe]
	cmp r1, #0
	beq _080D9380
	cmp r1, #1
	beq _080D93C4
	b _080D944A
_080D9380:
	ldr r0, [r5, #0x54]
	str r0, [r5, #0x64]
	ldr r0, [r5, #0x58]
	str r0, [r5, #0x68]
	str r1, [r5, #0x5c]
	mov r1, r8
	movs r2, #0x2c
	ldrsh r0, [r1, r2]
	str r0, [r5, #0x60]
	movs r1, #0x86
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080D93C4:
	ldr r3, [r5, #0x64]
	str r3, [r5, #0x54]
	ldr r4, _080D9408 @ =gSineTable
	ldr r6, [r5, #0x5c]
	asrs r1, r6, #8
	adds r0, r1, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r7, #0
	ldrsh r2, [r0, r7]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #4
	adds r3, r3, r0
	str r3, [r5, #0x54]
	ldr r2, [r5, #0x68]
	str r2, [r5, #0x58]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r4
	movs r3, #0
	ldrsh r0, [r1, r3]
	lsls r0, r0, #3
	adds r2, r2, r0
	str r2, [r5, #0x58]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080D940C
	ldr r0, [r5, #0x60]
	adds r0, r6, r0
	b _080D9410
	.align 2, 0
_080D9408: .4byte gSineTable
_080D940C:
	ldr r0, [r5, #0x60]
	subs r0, r6, r0
_080D9410:
	str r0, [r5, #0x5c]
	mov r7, r8
	ldr r0, [r7, #8]
	ldr r1, [r5, #0x58]
	ldr r2, _080D9434 @ =0xFFFFFF00
	adds r1, r1, r2
	ldr r0, [r0, #0x58]
	cmp r0, r1
	bge _080D943C
	ldrb r1, [r5, #0xb]
	movs r0, #8
	orrs r0, r1
	strb r0, [r5, #0xb]
	ldr r0, _080D9438 @ =0x0837119C
	str r0, [r5, #0x30]
	movs r0, #1
	strh r0, [r5, #0x26]
	b _080D9444
	.align 2, 0
_080D9434: .4byte 0xFFFFFF00
_080D9438: .4byte 0x0837119C
_080D943C:
	ldrb r1, [r5, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r5, #0xb]
_080D9444:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_080D944A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
