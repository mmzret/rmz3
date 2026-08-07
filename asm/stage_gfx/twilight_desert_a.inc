	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start desert_0800fb88
desert_0800fb88: @ 0x0800FB88
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0x24
	bls _0800FB94
	b _0800FF84
_0800FB94:
	lsls r0, r0, #2
	ldr r1, _0800FBA0 @ =_0800FBA4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0800FBA0: .4byte _0800FBA4
_0800FBA4: @ jump table
	.4byte _0800FC38 @ case 0
	.4byte _0800FC70 @ case 1
	.4byte _0800FC88 @ case 2
	.4byte _0800FCE0 @ case 3
	.4byte _0800FD0C @ case 4
	.4byte _0800FCE0 @ case 5
	.4byte _0800FD0C @ case 6
	.4byte _0800FD34 @ case 7
	.4byte _0800FD84 @ case 8
	.4byte _0800FCE0 @ case 9
	.4byte _0800FD0C @ case 10
	.4byte _0800FCE0 @ case 11
	.4byte _0800FD0C @ case 12
	.4byte _0800FDAC @ case 13
	.4byte _0800FCE0 @ case 14
	.4byte _0800FD0C @ case 15
	.4byte _0800FCE0 @ case 16
	.4byte _0800FD0C @ case 17
	.4byte _0800FDE0 @ case 18
	.4byte _0800FE30 @ case 19
	.4byte _0800FCE0 @ case 20
	.4byte _0800FD0C @ case 21
	.4byte _0800FCE0 @ case 22
	.4byte _0800FD0C @ case 23
	.4byte _0800FE58 @ case 24
	.4byte _0800FCE0 @ case 25
	.4byte _0800FD0C @ case 26
	.4byte _0800FCE0 @ case 27
	.4byte _0800FD0C @ case 28
	.4byte _0800FE8C @ case 29
	.4byte _0800FED8 @ case 30
	.4byte _0800FCE0 @ case 31
	.4byte _0800FD0C @ case 32
	.4byte _0800FCE0 @ case 33
	.4byte _0800FD0C @ case 34
	.4byte _0800FF18 @ case 35
	.4byte _0800FF3E @ case 36
_0800FC38:
	ldr r1, _0800FC5C @ =gOverworld
	ldr r2, _0800FC60 @ =0x0002D028
	adds r0, r1, r2
	movs r2, #0
	strb r2, [r0]
	ldr r3, _0800FC64 @ =0x0002D029
	adds r0, r1, r3
	strb r2, [r0]
	ldr r5, _0800FC68 @ =0x0002D02A
	adds r1, r1, r5
	strb r2, [r1]
	ldr r1, _0800FC6C @ =gBlendRegBuffer
	movs r0, #0x80
	lsls r0, r0, #5
	strh r0, [r1, #2]
	strh r2, [r4, #0x10]
	movs r0, #2
	b _0800FF82
	.align 2, 0
_0800FC5C: .4byte gOverworld
_0800FC60: .4byte 0x0002D028
_0800FC64: .4byte 0x0002D029
_0800FC68: .4byte 0x0002D02A
_0800FC6C: .4byte gBlendRegBuffer
_0800FC70:
	movs r0, #0x24
	movs r1, #3
	movs r2, #0x26
	bl LoadChunk
	ldr r0, _0800FCA0 @ =gOverworld
	ldr r1, _0800FCA4 @ =0x0002D02A
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	strh r1, [r4, #0x10]
	strh r1, [r4, #0x12]
_0800FC88:
	ldr r2, _0800FCA0 @ =gOverworld
	ldr r3, _0800FCA8 @ =0x0002D028
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #1
	bne _0800FCAC
	ldrb r0, [r4, #0xe]
	movs r1, #3
	cmp r0, #1
	bne _0800FCCA
	movs r1, #7
	b _0800FCCA
	.align 2, 0
_0800FCA0: .4byte gOverworld
_0800FCA4: .4byte 0x0002D02A
_0800FCA8: .4byte 0x0002D028
_0800FCAC:
	cmp r0, #2
	bne _0800FCBC
	ldrb r0, [r4, #0xe]
	movs r1, #0xe
	cmp r0, #1
	bne _0800FCCA
	movs r1, #0x12
	b _0800FCCA
_0800FCBC:
	cmp r0, #3
	bne _0800FCCE
	ldrb r0, [r4, #0xe]
	movs r1, #0x19
	cmp r0, #1
	bne _0800FCCA
	movs r1, #0x1d
_0800FCCA:
	strb r1, [r4, #0xe]
	b _0800FF84
_0800FCCE:
	movs r0, #0
	movs r1, #2
	strb r1, [r4, #0xe]
	ldr r5, _0800FCDC @ =0x0002D029
	adds r1, r2, r5
	strb r0, [r1]
	b _0800FF84
	.align 2, 0
_0800FCDC: .4byte 0x0002D029
_0800FCE0:
	ldrh r1, [r4, #0x12]
	adds r1, #1
	strh r1, [r4, #0x12]
	ldr r3, _0800FD08 @ =gBlendRegBuffer
	movs r0, #0x1f
	ands r0, r1
	movs r5, #0x80
	lsls r5, r5, #5
	adds r2, r5, #0
	orrs r0, r2
	strh r0, [r3, #2]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x10
	beq _0800FD00
	b _0800FF84
_0800FD00:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0800FF82
	.align 2, 0
_0800FD08: .4byte gBlendRegBuffer
_0800FD0C:
	ldrh r1, [r4, #0x12]
	subs r1, #1
	strh r1, [r4, #0x12]
	ldr r3, _0800FD30 @ =gBlendRegBuffer
	movs r0, #0x1f
	ands r0, r1
	movs r5, #0x80
	lsls r5, r5, #5
	adds r2, r5, #0
	orrs r0, r2
	strh r0, [r3, #2]
	lsls r1, r1, #0x10
	cmp r1, #0
	beq _0800FD2A
	b _0800FF84
_0800FD2A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0800FF82
	.align 2, 0
_0800FD30: .4byte gBlendRegBuffer
_0800FD34:
	ldrh r2, [r4, #0x10]
	lsrs r2, r2, #2
	adds r2, #0x43
	movs r0, #0x24
	movs r1, #3
	bl LoadChunk
	ldrh r0, [r4, #0x10]
	adds r0, #1
	strh r0, [r4, #0x10]
	ldr r1, _0800FD74 @ =gStageRun
	movs r3, #0xaf
	lsls r3, r3, #1
	adds r2, r1, r3
	ldr r1, _0800FD78 @ =0x00008003
	strh r1, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x14
	beq _0800FD5E
	b _0800FF84
_0800FD5E:
	ldr r0, _0800FD7C @ =gOverworld
	ldr r5, _0800FD80 @ =0x0002D02A
	adds r0, r0, r5
	movs r1, #1
	strb r1, [r0]
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0800FF82
	.align 2, 0
_0800FD74: .4byte gStageRun
_0800FD78: .4byte 0x00008003
_0800FD7C: .4byte gOverworld
_0800FD80: .4byte 0x0002D02A
_0800FD84:
	ldr r1, _0800FD98 @ =gOverworld
	ldr r2, _0800FD9C @ =0x0002D028
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _0800FDA0
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0800FF82
	.align 2, 0
_0800FD98: .4byte gOverworld
_0800FD9C: .4byte 0x0002D028
_0800FDA0:
	ldr r3, _0800FDA8 @ =0x0002D029
	adds r1, r1, r3
	b _0800FF0C
	.align 2, 0
_0800FDA8: .4byte 0x0002D029
_0800FDAC:
	ldrh r2, [r4, #0x10]
	subs r2, #1
	strh r2, [r4, #0x10]
	ldr r0, _0800FDD8 @ =gStageRun
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r5, r0, r1
	ldr r0, _0800FDDC @ =0x00008003
	strh r0, [r5]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x12
	adds r2, #0x43
	movs r0, #0x24
	movs r1, #3
	bl LoadChunk
	ldrh r0, [r4, #0x10]
	cmp r0, #0
	beq _0800FDD4
	b _0800FF84
_0800FDD4:
	strh r0, [r5]
	b _0800FF80
	.align 2, 0
_0800FDD8: .4byte gStageRun
_0800FDDC: .4byte 0x00008003
_0800FDE0:
	ldrh r2, [r4, #0x10]
	lsrs r2, r2, #2
	adds r2, #0x48
	movs r0, #0x24
	movs r1, #3
	bl LoadChunk
	ldrh r0, [r4, #0x10]
	adds r0, #1
	strh r0, [r4, #0x10]
	ldr r1, _0800FE20 @ =gStageRun
	movs r3, #0xaf
	lsls r3, r3, #1
	adds r2, r1, r3
	ldr r1, _0800FE24 @ =0x00008003
	strh r1, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	beq _0800FE0A
	b _0800FF84
_0800FE0A:
	ldr r0, _0800FE28 @ =gOverworld
	ldr r5, _0800FE2C @ =0x0002D02A
	adds r0, r0, r5
	movs r1, #2
	strb r1, [r0]
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0800FF82
	.align 2, 0
_0800FE20: .4byte gStageRun
_0800FE24: .4byte 0x00008003
_0800FE28: .4byte gOverworld
_0800FE2C: .4byte 0x0002D02A
_0800FE30:
	ldr r1, _0800FE44 @ =gOverworld
	ldr r2, _0800FE48 @ =0x0002D028
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _0800FE4C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0800FF82
	.align 2, 0
_0800FE44: .4byte gOverworld
_0800FE48: .4byte 0x0002D028
_0800FE4C:
	ldr r3, _0800FE54 @ =0x0002D029
	adds r1, r1, r3
	b _0800FF0C
	.align 2, 0
_0800FE54: .4byte 0x0002D029
_0800FE58:
	ldrh r2, [r4, #0x10]
	subs r2, #1
	strh r2, [r4, #0x10]
	ldr r0, _0800FE84 @ =gStageRun
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r5, r0, r1
	ldr r0, _0800FE88 @ =0x00008003
	strh r0, [r5]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x12
	adds r2, #0x48
	movs r0, #0x24
	movs r1, #3
	bl LoadChunk
	ldrh r0, [r4, #0x10]
	cmp r0, #0
	beq _0800FE80
	b _0800FF84
_0800FE80:
	strh r0, [r5]
	b _0800FF80
	.align 2, 0
_0800FE84: .4byte gStageRun
_0800FE88: .4byte 0x00008003
_0800FE8C:
	ldr r0, _0800FECC @ =gOverworld
	ldr r2, _0800FED0 @ =0x0002D02A
	adds r3, r0, r2
	movs r0, #3
	strb r0, [r3]
	ldrh r1, [r4, #0x10]
	adds r1, #1
	strh r1, [r4, #0x10]
	ldr r6, _0800FED4 @ =gBlendRegBuffer
	movs r2, #0x1f
	ands r2, r1
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #8
	orrs r2, r0
	strh r2, [r6, #2]
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	cmp r5, #0x10
	bne _0800FF84
	movs r0, #4
	strb r0, [r3]
	movs r0, #0x24
	movs r1, #3
	movs r2, #0x4c
	bl LoadChunk
	strh r5, [r6, #2]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0800FF82
	.align 2, 0
_0800FECC: .4byte gOverworld
_0800FED0: .4byte 0x0002D02A
_0800FED4: .4byte gBlendRegBuffer
_0800FED8:
	movs r0, #0xc6
	bl isSoundPlaying
	cmp r0, #0
	bne _0800FEE8
	movs r0, #0xc6
	bl PlaySound
_0800FEE8:
	movs r0, #0xc6
	bl SetStageNoiseVolume
	ldr r1, _0800FF00 @ =gOverworld
	ldr r3, _0800FF04 @ =0x0002D028
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #3
	beq _0800FF08
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0800FF82
	.align 2, 0
_0800FF00: .4byte gOverworld
_0800FF04: .4byte 0x0002D028
_0800FF08:
	ldr r5, _0800FF14 @ =0x0002D029
	adds r1, r1, r5
_0800FF0C:
	movs r0, #0
	strb r0, [r1]
	b _0800FF84
	.align 2, 0
_0800FF14: .4byte 0x0002D029
_0800FF18:
	movs r0, #0xc6
	bl isSoundPlaying
	cmp r0, #0
	bne _0800FF28
	movs r0, #0xc6
	bl PlaySound
_0800FF28:
	movs r0, #0xc6
	bl SetStageNoiseVolume
	movs r0, #0x24
	movs r1, #3
	movs r2, #0x26
	bl LoadChunk
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0800FF3E:
	movs r0, #0xc6
	bl isSoundPlaying
	cmp r0, #0
	bne _0800FF4E
	movs r0, #0xc6
	bl PlaySound
_0800FF4E:
	movs r0, #0xc6
	bl SetStageNoiseVolume
	ldr r0, _0800FF8C @ =gOverworld
	ldr r1, _0800FF90 @ =0x0002D02A
	adds r0, r0, r1
	movs r1, #3
	strb r1, [r0]
	ldrh r1, [r4, #0x10]
	subs r1, #1
	strh r1, [r4, #0x10]
	ldr r3, _0800FF94 @ =gBlendRegBuffer
	movs r2, #0x1f
	ands r2, r1
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #8
	orrs r2, r0
	strh r2, [r3, #2]
	lsls r1, r1, #0x10
	cmp r1, #0
	bne _0800FF84
	movs r0, #0xc6
	bl StopSound
_0800FF80:
	movs r0, #1
_0800FF82:
	strb r0, [r4, #0xe]
_0800FF84:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800FF8C: .4byte gOverworld
_0800FF90: .4byte 0x0002D02A
_0800FF94: .4byte gBlendRegBuffer
