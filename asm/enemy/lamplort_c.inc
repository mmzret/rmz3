	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0806c9c4
FUN_0806c9c4: @ 0x0806C9C4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0806C9D4
	cmp r0, #1
	beq _0806CA50
	b _0806CAB8
_0806C9D4:
	ldr r1, _0806C9F8 @ =0x00001906
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806C9FC @ =sCollisions
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r2, [r0]
	cmp r2, #0
	beq _0806CA00
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0806CA06
	.align 2, 0
_0806C9F8: .4byte 0x00001906
_0806C9FC: .4byte sCollisions
_0806CA00:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0806CA06:
	strb r0, [r4, #0xa]
	movs r5, #1
	adds r1, r5, #0
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
	movs r0, #0xff
	strb r0, [r4, #0x12]
	ldr r0, _0806CA44 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bls _0806CA48
	movs r0, #0
	strb r0, [r4, #0x13]
	b _0806CA4A
	.align 2, 0
_0806CA44: .4byte gStageRun+232
_0806CA48:
	strb r5, [r4, #0x13]
_0806CA4A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806CA50:
	ldrb r0, [r4, #0x12]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne _0806CA60
	ldr r0, _0806CA7C @ =0x0000011F
	bl PlaySound
_0806CA60:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _0806CA84
	ldr r0, _0806CA80 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bhi _0806CA9A
	movs r0, #1
	b _0806CA98
	.align 2, 0
_0806CA7C: .4byte 0x0000011F
_0806CA80: .4byte gStageRun+232
_0806CA84:
	ldr r0, _0806CAC0 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bls _0806CA9A
	movs r0, #0
_0806CA98:
	strb r0, [r4, #0x13]
_0806CA9A:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0806CAB0
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806CAB8
_0806CAB0:
	movs r1, #0
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806CAB8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806CAC0: .4byte gStageRun+232

