	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080686b4
FUN_080686b4: @ 0x080686B4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #1
	beq _0806871E
	cmp r4, #1
	bgt _080686C8
	cmp r4, #0
	beq _080686CE
	b _08068776
_080686C8:
	cmp r4, #2
	beq _08068750
	b _08068776
_080686CE:
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0xb9
	strb r4, [r0]
	subs r0, #0x45
	ldr r1, _08068744 @ =0x0836609C
	bl SetDDP
	adds r4, r5, #0
	adds r4, #0xbc
	ldr r3, [r4]
	cmp r3, #0
	beq _08068718
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
	ldr r1, _08068748 @ =gVFXFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
_08068718:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806871E:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, _0806874C @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	movs r1, #0xe0
	lsls r1, r1, #7
	cmp r0, r1
	bhs _08068776
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08068776
	.align 2, 0
_08068744: .4byte sCollisions
_08068748: .4byte gVFXFnTable
_0806874C: .4byte pZero2
_08068750:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, _0806877C @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	movs r1, #0xe0
	lsls r1, r1, #7
	cmp r0, r1
	blo _08068776
	movs r1, #0
	movs r0, #3
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_08068776:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806877C: .4byte pZero2

