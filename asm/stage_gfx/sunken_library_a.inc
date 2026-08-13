	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start sunkenlib_08013930
sunkenlib_08013930: @ 0x08013930
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldrb r6, [r7, #0xe]
	cmp r6, #0
	bne _080139A0
	ldr r0, [r7, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r5, r0, #1
	ldr r3, _08013A20 @ =gVideoRegBuffer+4
	adds r5, r5, r3
	ldr r1, [r7, #0x64]
	ldr r4, _08013A24 @ =0x00008045
	adds r2, r4, #0
	orrs r1, r2
	strh r1, [r5]
	lsls r0, r0, #2
	adds r3, #8
	adds r0, r0, r3
	str r6, [r0]
	ldr r0, _08013A28 @ =0x085223B4
	ldr r0, [r0]
	ldr r2, _08013A2C @ =0x085223BC
	adds r0, r0, r2
	movs r4, #0xf8
	lsls r4, r4, #5
	ands r1, r4
	lsls r1, r1, #3
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #2
	mov r8, r2
	bl CpuFastSet
	ldr r0, _08013A30 @ =0x085223B8
	ldr r0, [r0]
	ldr r1, _08013A34 @ =0x085223C0
	adds r0, r0, r1
	ldrh r1, [r5]
	ands r4, r1
	lsls r4, r4, #3
	ldr r2, _08013A38 @ =0x06000800
	adds r4, r4, r2
	adds r1, r4, #0
	mov r2, r8
	bl CpuFastSet
	str r6, [r7, #0x68]
	strh r6, [r7, #0x10]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080139A0:
	ldr r2, _08013A3C @ =gWindowRegBuffer
	ldrb r1, [r2, #0xd]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r2, #0xd]
	ldr r0, [r7, #0x68]
	cmp r0, #0
	bne _080139B6
	bl FUN_080d8f2c
	str r0, [r7, #0x68]
_080139B6:
	ldr r5, _08013A40 @ =gOverworld
	ldr r4, _08013A44 @ =0x0002C00C
	adds r0, r5, r4
	ldr r1, [r0]
	ldr r0, _08013A48 @ =0x000227FF
	cmp r1, r0
	bgt _08013A60
	ldrh r0, [r7, #0x10]
	adds r0, #1
	strh r0, [r7, #0x10]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bls _080139D6
	movs r0, #4
	strh r0, [r7, #0x10]
_080139D6:
	ldr r0, [r7, #0x68]
	bl FUN_080d8fd4
	movs r4, #0x92
	lsls r4, r4, #1
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	bne _080139F0
	adds r0, r4, #0
	bl PlaySound
_080139F0:
	ldrh r1, [r7, #0x10]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08013A7E
	ldr r0, _08013A4C @ =0x0002D02C
	adds r2, r5, r0
	ldr r1, [r2]
	ldr r0, _08013A50 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08013A54 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r3
	cmp r0, #0
	beq _08013A7E
	ldr r1, _08013A58 @ =gBlendRegBuffer
	ldr r0, _08013A5C @ =0x00000C0A
	b _08013A82
	.align 2, 0
_08013A20: .4byte gVideoRegBuffer+4
_08013A24: .4byte 0x00008045
_08013A28: .4byte 0x085223B4
_08013A2C: .4byte 0x085223BC
_08013A30: .4byte 0x085223B8
_08013A34: .4byte 0x085223C0
_08013A38: .4byte 0x06000800
_08013A3C: .4byte gWindowRegBuffer
_08013A40: .4byte gOverworld
_08013A44: .4byte 0x0002C00C
_08013A48: .4byte 0x000227FF
_08013A4C: .4byte 0x0002D02C
_08013A50: .4byte 0x000343FD
_08013A54: .4byte 0x00269EC3
_08013A58: .4byte gBlendRegBuffer
_08013A5C: .4byte 0x00000C0A
_08013A60:
	movs r0, #3
	strh r0, [r7, #0x10]
	ldr r0, [r7, #0x68]
	bl FUN_080d8fe4
	movs r4, #0x92
	lsls r4, r4, #1
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	beq _08013A7E
	adds r0, r4, #0
	bl StopSound
_08013A7E:
	ldr r1, _08013A90 @ =gBlendRegBuffer
	ldr r0, _08013A94 @ =0x00000C04
_08013A82:
	strh r0, [r1, #2]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08013A90: .4byte gBlendRegBuffer
_08013A94: .4byte 0x00000C04
