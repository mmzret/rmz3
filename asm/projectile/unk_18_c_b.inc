	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a34a0
FUN_080a34a0: @ 0x080A34A0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080A34BC @ =pZero2
	ldr r3, [r0]
	ldrb r1, [r3, #0xc]
	adds r4, r0, #0
	cmp r1, #1
	bls _080A34C0
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	b _080A360C
	.align 2, 0
_080A34BC: .4byte pZero2
_080A34C0:
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _080A3530
	cmp r0, #1
	bgt _080A34D0
	cmp r0, #0
	beq _080A34DA
	b _080A363A
_080A34D0:
	cmp r0, #2
	beq _080A35AC
	cmp r0, #3
	beq _080A35C6
	b _080A363A
_080A34DA:
	movs r0, #0x8c
	lsls r0, r0, #2
	adds r1, r3, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0x10
	str r0, [r5, #0x5c]
	movs r0, #0x80
	strb r0, [r5, #0x13]
	ldr r4, _080A3594 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r3, _080A3598 @ =0x000343FD
	muls r0, r3, r0
	ldr r2, _080A359C @ =0x00269EC3
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsls r0, r0, #3
	lsrs r0, r0, #0x14
	ldr r6, _080A35A0 @ =0xFFFFF800
	adds r0, r0, r6
	str r0, [r5, #0x64]
	adds r0, r1, #0
	muls r0, r3, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #5
	bl __umodsi3
	rsbs r0, r0, #0
	str r0, [r5, #0x68]
	ldr r1, _080A35A4 @ =0x00004608
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A3530:
	ldr r4, _080A35A8 @ =pZero2
	ldr r0, [r4]
	bl CountButtonMashing
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, [r5, #0x5c]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldrb r0, [r5, #0x13]
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A3570
	cmp r1, #0
	blt _080A3570
	ldr r2, [r4]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080A3570
	adds r0, r2, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _080A3576
_080A3570:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A3576:
	ldr r0, _080A35A8 @ =pZero2
	ldr r2, [r0]
	ldr r0, [r2, #0x54]
	ldr r1, [r5, #0x64]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r2, #0x58]
	ldr r1, [r5, #0x68]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	b _080A363A
	.align 2, 0
_080A3594: .4byte RNG_0202f388
_080A3598: .4byte 0x000343FD
_080A359C: .4byte 0x00269EC3
_080A35A0: .4byte 0xFFFFF800
_080A35A4: .4byte 0x00004608
_080A35A8: .4byte pZero2
_080A35AC:
	movs r6, #0x8c
	lsls r6, r6, #2
	adds r1, r3, r6
	ldrb r0, [r1]
	subs r0, #1
	movs r2, #0
	strb r0, [r1]
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	strb r2, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A35C6:
	ldr r2, [r4]
	ldr r0, [r2, #0x54]
	ldr r1, [r5, #0x64]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r2, #0x58]
	ldr r1, [r5, #0x68]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r1, [r5, #0x12]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080A35F0
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080A35F6
_080A35F0:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080A35F6:
	strb r0, [r5, #0xa]
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080A363A
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080A360C:
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
	ldr r1, _080A3640 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_080A363A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A3640: .4byte gProjectileFnTable
