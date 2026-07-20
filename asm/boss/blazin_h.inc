	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start blazinMode10
blazinMode10: @ 0x0803FC74
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	beq _0803FC84
	cmp r6, #1
	beq _0803FCD4
	b _0803FD14
_0803FC84:
	adds r1, r5, #0
	adds r1, #0xd0
	ldrb r0, [r1]
	cmp r0, #1
	bne _0803FCA6
	strb r6, [r1]
	adds r4, r5, #0
	adds r4, #0xc4
	str r6, [r4]
	adds r0, r5, #0
	movs r1, #2
	bl createBlazinTail
	str r0, [r4]
	adds r0, r5, #0
	adds r0, #0xc8
	strh r6, [r0]
_0803FCA6:
	movs r0, #0x48
	bl isSoundPlaying
	cmp r0, #0
	beq _0803FCB6
	movs r0, #0x48
	bl StopSound
_0803FCB6:
	movs r0, #0x72
	bl isSoundPlaying
	cmp r0, #0
	beq _0803FCC6
	movs r0, #0x72
	bl StopSound
_0803FCC6:
	strb r6, [r5, #0x13]
	movs r0, #0x74
	bl PlaySound
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0803FCD4:
	adds r0, r5, #0
	adds r0, #0xcc
	ldr r0, [r0]
	cmp r0, #0
	beq _0803FD14
	adds r0, r5, #0
	adds r0, #0xc4
	ldr r0, [r0]
	cmp r0, #0
	bne _0803FD14
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	bne _0803FD14
	adds r0, r5, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #6
	ldr r2, _0803FD40 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	movs r2, #4
	movs r3, #0
	bl GotoMotion
	adds r0, r5, #0
	bl UpdateEntityAnim
	movs r0, #1
	strb r0, [r5, #0x13]
_0803FD14:
	adds r4, r5, #0
	adds r4, #0xc0
	ldr r0, [r4]
	bl isKilled
	cmp r0, #0
	beq _0803FD50
	adds r2, r5, #0
	adds r2, #0xcc
	ldr r1, [r2]
	cmp r1, #0
	beq _0803FD44
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bls _0803FD50
	movs r0, #0
	str r0, [r2]
	str r0, [r4]
	movs r1, #3
	strb r1, [r5, #0xd]
	strb r0, [r5, #0xe]
	b _0803FD4C
	.align 2, 0
_0803FD40: .4byte 0xFFFFA200
_0803FD44:
	str r1, [r4]
	movs r0, #3
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0803FD4C:
	movs r0, #0xff
	strb r0, [r5, #0xf]
_0803FD50:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

