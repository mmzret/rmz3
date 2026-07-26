	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08089eb0
FUN_08089eb0: @ 0x08089EB0
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r2, [r5, #0xe]
	cmp r2, #0
	beq _08089EC2
	cmp r2, #1
	beq _08089F40
	b _08089F52
_08089EC2:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
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
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _08089F04 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	ldrb r0, [r5, #0x10]
	cmp r0, #2
	bne _08089F08
	movs r0, #0x31
	bl PlaySound
	b _08089F0E
	.align 2, 0
_08089F04: .4byte 0xFFFFF800
_08089F08:
	movs r0, #0x2a
	bl PlaySound
_08089F0E:
	ldr r2, _08089F38 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _08089F3C @ =0x0000270E
	cmp r1, r0
	bhi _08089F1C
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08089F1C:
	adds r4, r5, #0
	adds r4, #0x54
	adds r0, r5, #0
	adds r1, r4, #0
	bl TryDropZakoDisk
	movs r0, #4
	adds r1, r4, #0
	bl TryDropItem
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08089F52
	.align 2, 0
_08089F38: .4byte gScore
_08089F3C: .4byte 0x0000270E
_08089F40:
	ldr r1, _08089F5C @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
_08089F52:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08089F5C: .4byte gEnemyFnTable

	thumb_func_start FUN_08089f60
FUN_08089f60: @ 0x08089F60
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _08089F70
	cmp r0, #1
	beq _0808A002
	b _0808A05E
_08089F70:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08089FE4 @ =0x083688A4
	bl SetDDP
	ldr r1, _08089FE8 @ =0x0000DD02
	adds r0, r5, #0
	bl SetMotion
	ldr r0, _08089FEC @ =pZero2
	ldr r2, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r3, _08089FF0 @ =0xFFFFE800
	adds r0, r0, r3
	ldr r2, [r2, #0x58]
	subs r0, r0, r2
	str r0, [r5, #0x60]
	asrs r1, r1, #8
	adds r6, r1, #0
	muls r6, r1, r6
	asrs r0, r0, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r6, r6, r0
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #8
	cmp r6, #0
	beq _08089FF4
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #1
	str r1, [r5, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	str r1, [r5, #0x60]
	b _08089FFC
	.align 2, 0
_08089FE4: .4byte sCollisions+(6*24)
_08089FE8: .4byte 0x0000DD02
_08089FEC: .4byte pZero2
_08089FF0: .4byte 0xFFFFE800
_08089FF4:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r5, #0x5c]
	str r6, [r5, #0x60]
_08089FFC:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808A002:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808A020
	str r1, [r5, #0x60]
_0808A020:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0808A042
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0808A05E
_0808A042:
	movs r0, #0
	strb r0, [r5, #0xe]
	adds r0, r5, #0
	bl FUN_08089eb0
	ldr r1, _0808A064 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
_0808A05E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808A064: .4byte gEnemyFnTable


