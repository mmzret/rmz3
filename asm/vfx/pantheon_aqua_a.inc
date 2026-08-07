	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080bb3d4
FUN_080bb3d4: @ 0x080BB3D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BB400
	ldr r1, _080BB3FC @ =gVFXFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	b _080BB5BE
	.align 2, 0
_080BB3FC: .4byte gVFXFnTable
_080BB400:
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	bne _080BB408
	b _080BB51E
_080BB408:
	cmp r0, #1
	bgt _080BB412
	cmp r0, #0
	beq _080BB41A
	b _080BB5BE
_080BB412:
	cmp r0, #2
	bne _080BB418
	b _080BB54C
_080BB418:
	b _080BB5BE
_080BB41A:
	ldr r7, _080BB484 @ =RNG_0202f388
	ldr r0, [r7]
	ldr r1, _080BB488 @ =0x000343FD
	mov r8, r1
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r5, _080BB48C @ =0x00269EC3
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r4, r0, #1
	str r4, [r7]
	lsrs r0, r0, #0x11
	movs r1, #0xc
	bl __umodsi3
	adds r0, #0x14
	strb r0, [r6, #0x12]
	mov r0, r8
	muls r0, r4, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r7]
	lsrs r0, r0, #0x11
	movs r1, #0xc
	bl __umodsi3
	strb r0, [r6, #0x13]
	ldr r1, _080BB490 @ =0x0000270C
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x80
	ldrh r0, [r0]
	cmp r0, #0
	bne _080BB494
	ldr r0, [r7]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r7]
	lsrs r0, r0, #0x11
	movs r1, #0x7f
	ands r0, r1
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r0, r1
	b _080BB4AE
	.align 2, 0
_080BB484: .4byte RNG_0202f388
_080BB488: .4byte 0x000343FD
_080BB48C: .4byte 0x00269EC3
_080BB490: .4byte 0x0000270C
_080BB494:
	ldr r0, [r7]
	mov r1, r8
	muls r1, r0, r1
	ldr r0, _080BB4D4 @ =0x00269EC3
	adds r1, r1, r0
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r7]
	lsrs r1, r1, #0x11
	movs r0, #0x7f
	ands r1, r0
	ldr r0, _080BB4D8 @ =0xFFFFFE40
	subs r0, r0, r1
_080BB4AE:
	str r0, [r6, #0x5c]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _080BB4E4
	ldr r2, _080BB4DC @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080BB4E0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080BB4D4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xff
	ands r0, r1
	adds r0, #0x20
	b _080BB502
	.align 2, 0
_080BB4D4: .4byte 0x00269EC3
_080BB4D8: .4byte 0xFFFFFE40
_080BB4DC: .4byte RNG_0202f388
_080BB4E0: .4byte 0x000343FD
_080BB4E4:
	ldr r2, _080BB540 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080BB544 @ =0x000343FD
	muls r1, r0, r1
	ldr r0, _080BB548 @ =0x00269EC3
	adds r1, r1, r0
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r2]
	lsrs r1, r1, #0x11
	movs r0, #0xff
	ands r1, r0
	movs r0, #0x20
	rsbs r0, r0, #0
	subs r0, r0, r1
_080BB502:
	str r0, [r6, #0x68]
	adds r0, r6, #0
	bl UpdateEntityAnim
	movs r0, #0
	str r0, [r6, #0x60]
	strb r0, [r6, #0x13]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6, #0xa]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080BB51E:
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	beq _080BB52E
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BB5BE
_080BB52E:
	ldrb r0, [r6, #0xa]
	movs r1, #1
	orrs r1, r0
	strb r1, [r6, #0xa]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _080BB5BE
	.align 2, 0
_080BB540: .4byte RNG_0202f388
_080BB544: .4byte 0x000343FD
_080BB548: .4byte 0x00269EC3
_080BB54C:
	ldrb r0, [r6, #0x13]
	adds r0, #1
	strb r0, [r6, #0x13]
	ldr r2, [r6, #0x7c]
	movs r1, #0xc0
	lsls r1, r1, #1
	subs r1, r1, r2
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r6, #0x7c]
	adds r0, r6, #0
	adds r0, #0x50
	strh r2, [r0]
	ldr r0, [r6, #0x7c]
	adds r1, r6, #0
	adds r1, #0x52
	strh r0, [r1]
	ldr r2, _080BB5C8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080BB5CC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080BB5D0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	adds r1, r6, #0
	adds r1, #0x24
	strb r0, [r1]
	ldr r0, [r6, #0x68]
	ldr r3, [r6, #0x60]
	subs r0, r0, r3
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r3, r3, r0
	str r3, [r6, #0x60]
	ldr r2, [r6, #0x5c]
	rsbs r1, r2, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r6, #0x5c]
	ldr r0, [r6, #0x58]
	adds r0, r0, r3
	str r0, [r6, #0x58]
	ldr r0, [r6, #0x54]
	adds r0, r0, r2
	str r0, [r6, #0x54]
	adds r0, r6, #0
	bl UpdateEntityAnim
_080BB5BE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BB5C8: .4byte RNG_0202f388
_080BB5CC: .4byte 0x000343FD
_080BB5D0: .4byte 0x00269EC3
