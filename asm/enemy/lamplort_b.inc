	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0806c8cc
FUN_0806c8cc: @ 0x0806C8CC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0806C8DC
	cmp r5, #1
	beq _0806C966
	b _0806C9B4
_0806C8DC:
	ldr r1, _0806C918 @ =0x00001904
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806C91C @ =sCollisions
	bl SetDDP
	ldr r1, [r4, #0x2c]
	adds r1, #0xb4
	ldr r0, [r1]
	movs r6, #1
	orrs r0, r6
	str r0, [r1]
	strb r5, [r4, #0x12]
	ldr r0, _0806C920 @ =0x0000011F
	bl PlaySound
	ldr r0, _0806C924 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bls _0806C928
	strb r5, [r4, #0x13]
	b _0806C92A
	.align 2, 0
_0806C918: .4byte 0x00001904
_0806C91C: .4byte sCollisions
_0806C920: .4byte 0x0000011F
_0806C924: .4byte gStageRun+232
_0806C928:
	strb r6, [r4, #0x13]
_0806C92A:
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r2, [r0]
	cmp r2, #0
	beq _0806C93C
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0806C942
_0806C93C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0806C942:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806C966:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _0806C988
	ldr r0, _0806C984 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bhi _0806C99E
	movs r0, #1
	b _0806C99C
	.align 2, 0
_0806C984: .4byte gStageRun+232
_0806C988:
	ldr r0, _0806C9BC @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bls _0806C99E
	movs r0, #0
_0806C99C:
	strb r0, [r4, #0x13]
_0806C99E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _0806C9B4
	movs r0, #0
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
_0806C9B4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806C9BC: .4byte gStageRun+232

