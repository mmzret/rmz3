	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08061a78
FUN_08061a78: @ 0x08061A78
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08061A88
	cmp r0, #1
	beq _08061A98
	b _08061A9E
_08061A88:
	movs r1, #0x8b
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08061A98:
	adds r0, r4, #0
	bl UpdateEntityAnim
_08061A9E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08061aa4
FUN_08061aa4: @ 0x08061AA4
	push {lr}
	adds r2, r0, #0
	ldrb r1, [r2, #0xe]
	cmp r1, #0
	beq _08061AB4
	cmp r1, #1
	beq _08061AC6
	b _08061AD4
_08061AB4:
	ldr r0, [r2, #0x18]
	ldrb r1, [r0, #9]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08061AD4
	strb r3, [r2, #0xe]
	b _08061AD4
_08061AC6:
	ldr r0, _08061AD8 @ =gStageRun
	ldrb r0, [r0, #0x12]
	ands r0, r1
	cmp r0, #0
	bne _08061AD4
	strb r0, [r2, #0xd]
	strb r0, [r2, #0xe]
_08061AD4:
	pop {r0}
	bx r0
	.align 2, 0
_08061AD8: .4byte gStageRun

	thumb_func_start FUN_08061adc
FUN_08061adc: @ 0x08061ADC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08061AEC
	cmp r5, #1
	beq _08061B3C
	b _08061B58
_08061AEC:
	movs r0, #0xe0
	bl StopSound
	ldrb r1, [r4, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r4, #0xb]
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r3, _08061B60 @ =gStageRun
	ldrh r2, [r3, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _08061B32
	ldrb r1, [r3, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _08061B32
	ldr r0, _08061B64 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_08061B32:
	movs r0, #2
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08061B3C:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08061B58
	ldr r2, _08061B60 @ =gStageRun
	ldrb r0, [r2, #0x12]
	movs r1, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08061B58:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08061B60: .4byte gStageRun
_08061B64: .4byte 0x0000FFFE
