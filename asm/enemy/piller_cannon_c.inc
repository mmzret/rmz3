	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08068618
FUN_08068618: @ 0x08068618
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #0
	beq _08068628
	cmp r4, #1
	beq _08068678
	b _0806869E
_08068628:
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0xb9
	strb r4, [r0]
	subs r0, #0x45
	ldr r1, _080686A4 @ =0x0836609C
	bl SetDDP
	adds r4, r5, #0
	adds r4, #0xbc
	ldr r3, [r4]
	cmp r3, #0
	beq _08068672
	ldrb r2, [r3, #0xa]
	movs r1, #0xfe
	adds r0, r1, #0
	ands r0, r2
	strb r0, [r3, #0xa]
	ldr r2, [r4]
	ldrb r0, [r2, #0xa]
	ands r1, r0
	movs r0, #0xfd
	ands r1, r0
	strb r1, [r2, #0xa]
	ldr r1, _080686A8 @ =gVFXFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
_08068672:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08068678:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, _080686AC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #7
	adds r0, r0, r1
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	movs r1, #0xc0
	lsls r1, r1, #8
	cmp r0, r1
	bhs _0806869E
	movs r1, #0
	movs r0, #3
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0806869E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080686A4: .4byte sCollisions
_080686A8: .4byte gVFXFnTable
_080686AC: .4byte pZero2

