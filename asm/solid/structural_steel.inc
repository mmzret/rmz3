	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080df6d8
FUN_080df6d8: @ 0x080DF6D8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080DF6E8
	cmp r0, #1
	beq _080DF700
	b _080DF760
_080DF6E8:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x1f
	strb r0, [r1]
	movs r1, #0xde
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080DF700:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _080DF720
	ldr r0, _080DF718 @ =gOverworld
	ldr r1, _080DF71C @ =0x0002D02C
	adds r0, r0, r1
	ldr r0, [r0]
	lsls r2, r0, #8
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #0x10
	adds r2, r2, r0
	b _080DF730
	.align 2, 0
_080DF718: .4byte gOverworld
_080DF71C: .4byte 0x0002D02C
_080DF720:
	ldr r0, _080DF73C @ =gOverworld
	ldr r1, _080DF740 @ =0x0002D030
	adds r0, r0, r1
	ldr r0, [r0]
	lsls r2, r0, #8
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #0xf
	subs r2, r2, r0
_080DF730:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080DF744
	movs r1, #0xc2
	lsls r1, r1, #0xb
	b _080DF748
	.align 2, 0
_080DF73C: .4byte gOverworld
_080DF740: .4byte 0x0002D030
_080DF744:
	movs r1, #0x88
	lsls r1, r1, #0xa
_080DF748:
	adds r0, r2, #0
	bl __modsi3
	adds r2, r0, #0
	ldr r0, [r4, #0x64]
	adds r0, r2, r0
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x68]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080DF760:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080df768
FUN_080df768: @ 0x080DF768
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r7, [r5, #0x28]
	ldrb r0, [r7, #0xc]
	cmp r0, #1
	bls _080DF7B0
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
	ldr r1, _080DF7AC @ =gSolidFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	b _080DF8FA
	.align 2, 0
_080DF7AC: .4byte gSolidFnTable
_080DF7B0:
	ldrb r1, [r5, #0xe]
	cmp r1, #0
	beq _080DF7BC
	cmp r1, #1
	beq _080DF7E8
	b _080DF8FA
_080DF7BC:
	adds r0, r5, #0
	adds r0, #0xb4
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, r5, #0
	bl InitRotatableMotion
	ldr r1, _080DF834 @ =0x0000DE01
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x5c
	str r0, [r5, #0x40]
	ldr r0, [r7, #0x54]
	str r0, [r5, #0x54]
	ldr r0, [r7, #0x58]
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080DF7E8:
	ldr r0, [r7, #0x54]
	str r0, [r5, #0x5c]
	ldr r0, [r7, #0x58]
	str r0, [r5, #0x60]
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	ldr r3, _080DF838 @ =pZero2
	cmp r0, #0
	beq _080DF840
	ldr r2, [r3]
	ldr r1, [r2, #0x58]
	ldr r0, [r5, #0x58]
	cmp r1, r0
	bge _080DF840
	ldr r1, _080DF83C @ =0x0000018D
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DF840
	ldr r1, [r2, #0x54]
	ldr r0, [r7, #0x54]
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #6
	cmp r0, #0
	bge _080DF826
	adds r0, #0xff
_080DF826:
	asrs r1, r0, #8
	adds r0, r5, #0
	adds r0, #0xb4
	strh r1, [r0]
	adds r2, r0, #0
	b _080DF858
	.align 2, 0
_080DF834: .4byte 0x0000DE01
_080DF838: .4byte pZero2
_080DF83C: .4byte 0x0000018D
_080DF840:
	adds r2, r5, #0
	adds r2, #0xb4
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #5
	cmp r0, #0
	bge _080DF854
	adds r0, #0xff
_080DF854:
	asrs r0, r0, #8
	strh r0, [r2]
_080DF858:
	movs r0, #0
	ldrsh r1, [r2, r0]
	adds r6, r5, #0
	adds r6, #0xb6
	movs r2, #0
	ldrsh r0, [r6, r2]
	subs r1, r1, r0
	adds r0, r1, #0
	cmp r1, #0
	bge _080DF86E
	adds r0, #0xf
_080DF86E:
	asrs r0, r0, #4
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r6]
	movs r2, #0
	ldrsh r0, [r6, r2]
	adds r0, #0xf
	cmp r0, #0x1f
	bhi _080DF884
	movs r0, #0
	strh r0, [r6]
_080DF884:
	ldrh r0, [r6]
	lsrs r0, r0, #8
	adds r1, r5, #0
	adds r1, #0x24
	strb r0, [r1]
	ldr r0, [r7, #0x54]
	str r0, [r5, #0x54]
	ldr r1, [r3]
	ldr r2, [r7, #0x54]
	ldr r3, _080DF8E8 @ =0xFFFFD800
	adds r0, r2, r3
	ldr r1, [r1, #0x54]
	cmp r1, r0
	blt _080DF8F0
	movs r3, #0xa0
	lsls r3, r3, #6
	adds r0, r2, r3
	cmp r1, r0
	bgt _080DF8F0
	subs r1, r1, r2
	lsls r0, r1, #8
	ldr r4, _080DF8EC @ =gSineTable
	ldrh r1, [r6]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r1, #0x40
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r4
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl __divsi3
	adds r1, r0, #0
	ldr r2, [r7, #0x58]
	str r2, [r5, #0x58]
	ldrh r0, [r6]
	lsrs r0, r0, #8
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	bge _080DF8E0
	adds r0, #0xff
_080DF8E0:
	asrs r0, r0, #8
	adds r0, r2, r0
	b _080DF8F2
	.align 2, 0
_080DF8E8: .4byte 0xFFFFD800
_080DF8EC: .4byte gSineTable
_080DF8F0:
	ldr r0, [r7, #0x58]
_080DF8F2:
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
_080DF8FA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
