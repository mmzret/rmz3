	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start doOmega1BallLaser1
doOmega1BallLaser1: @ 0x0809D600
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0809D630
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	ldr r1, _0809D62C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _0809D678
	.align 2, 0
_0809D62C: .4byte gProjectileFnTable
_0809D630:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809D63C
	cmp r0, #1
	beq _0809D64A
	b _0809D65E
_0809D63C:
	ldr r1, _0809D680 @ =0x00000A06
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809D64A:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	ldr r1, _0809D684 @ =0xFFFF9A00
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0809D65E:
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	cmp r0, #0
	beq _0809D670
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _0809D678
_0809D670:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0809D678:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809D680: .4byte 0x00000A06
_0809D684: .4byte 0xFFFF9A00

	thumb_func_start doOmega1BallLaser2
doOmega1BallLaser2: @ 0x0809D688
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _0809D6A0
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809D6C4
_0809D6A0:
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	ldr r1, _0809D6C0 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _0809D790
	.align 2, 0
_0809D6C0: .4byte gProjectileFnTable
_0809D6C4:
	ldrb r2, [r5, #0xe]
	cmp r2, #0
	beq _0809D6D0
	cmp r2, #1
	beq _0809D73A
	b _0809D790
_0809D6D0:
	adds r4, r5, #0
	adds r4, #0xb8
	ldr r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	lsrs r0, r0, #8
	str r0, [r4]
	strb r2, [r5, #0x13]
	ldr r1, _0809D798 @ =0x00000A07
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0809D79C @ =sCollisions+24
	bl SetDDP
	ldr r3, _0809D7A0 @ =gSineTable
	adds r2, r5, #0
	adds r2, #0xb4
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, [r4]
	muls r0, r1, r0
	lsrs r0, r0, #8
	rsbs r0, r0, #0
	str r0, [r5, #0x5c]
	ldrb r0, [r2]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4]
	muls r0, r1, r0
	lsrs r0, r0, #8
	str r0, [r5, #0x60]
	adds r1, r5, #0
	adds r1, #0xb5
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #1
	bl PlaySound
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809D73A:
	ldrb r0, [r5, #0x13]
	adds r1, r0, #1
	strb r1, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0809D756
	adds r0, r5, #0
	adds r0, #0x54
	movs r1, #0
	bl FUN_080b9184
_0809D756:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x60]
	adds r1, r1, r2
	str r1, [r5, #0x58]
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	beq _0809D78A
	adds r1, r5, #0
	adds r1, #0xb5
	ldrb r0, [r1]
	cmp r0, #0
	beq _0809D78A
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r5, #0x58]
	adds r0, r0, r2
	str r0, [r5, #0x58]
	ldr r0, [r5, #0x60]
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
_0809D78A:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_0809D790:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809D798: .4byte 0x00000A07
_0809D79C: .4byte sCollisions+24
_0809D7A0: .4byte gSineTable

	thumb_func_start doOmega1Hoopshot
doOmega1Hoopshot: @ 0x0809D7A4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809D7CC
	ldr r1, _0809D7C8 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _0809D88C
	.align 2, 0
_0809D7C8: .4byte gProjectileFnTable
_0809D7CC:
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0809D7D8
	cmp r0, #1
	beq _0809D836
	b _0809D88C
_0809D7D8:
	strb r0, [r5, #0x13]
	ldr r1, _0809D894 @ =0x00000A07
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0809D898 @ =sCollisions+24
	bl SetDDP
	adds r4, r5, #0
	adds r4, #0xb8
	ldr r3, _0809D89C @ =gSineTable
	adds r2, r5, #0
	adds r2, #0xb4
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, [r4]
	muls r0, r1, r0
	lsrs r0, r0, #8
	rsbs r0, r0, #0
	str r0, [r5, #0x5c]
	ldrb r0, [r2]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4]
	muls r0, r1, r0
	lsrs r0, r0, #8
	str r0, [r5, #0x60]
	adds r1, r5, #0
	adds r1, #0xb5
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #1
	bl PlaySound
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809D836:
	ldrb r0, [r5, #0x13]
	adds r1, r0, #1
	strb r1, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0809D852
	adds r0, r5, #0
	adds r0, #0x54
	movs r1, #0
	bl FUN_080b9184
_0809D852:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x60]
	adds r1, r1, r2
	str r1, [r5, #0x58]
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	beq _0809D886
	adds r1, r5, #0
	adds r1, #0xb5
	ldrb r0, [r1]
	cmp r0, #0
	beq _0809D886
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r5, #0x58]
	adds r0, r0, r2
	str r0, [r5, #0x58]
	ldr r0, [r5, #0x60]
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
_0809D886:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_0809D88C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809D894: .4byte 0x00000A07
_0809D898: .4byte sCollisions+24
_0809D89C: .4byte gSineTable
