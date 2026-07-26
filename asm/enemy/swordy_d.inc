	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807c4b8
FUN_0807c4b8: @ 0x0807C4B8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0807C4C8
	cmp r0, #1
	beq _0807C4D0
	b _0807C514
_0807C4C8:
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807C4D0:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807C4E0
	str r1, [r4, #0x60]
_0807C4E0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807C50C
	movs r0, #0
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	ldr r1, _0807C508 @ =0xFFFFF000
	b _0807C510
	.align 2, 0
_0807C508: .4byte 0xFFFFF000
_0807C50C:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
_0807C510:
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0807C514:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0807C52A
	movs r0, #0
	str r0, [r5]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0807C52A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0807c530
FUN_0807c530: @ 0x0807C530
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xbc
	ldr r5, [r6]
	cmp r5, #0
	bne _0807C57A
	adds r0, #0x8c
	ldr r0, [r0]
	movs r7, #1
	ands r0, r7
	cmp r0, #0
	beq _0807C57A
	ldr r2, _0807C56C @ =sElementCoord
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _0807C57A
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _0807C570
	strb r7, [r4, #0xd]
	b _0807C578
	.align 2, 0
_0807C56C: .4byte sElementCoord
_0807C570:
	cmp r1, #0x30
	bne _0807C57A
	movs r0, #3
	strb r0, [r4, #0xd]
_0807C578:
	strb r5, [r4, #0xe]
_0807C57A:
	movs r0, #1
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

