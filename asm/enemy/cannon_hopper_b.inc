	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08098110
FUN_08098110: @ 0x08098110
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	bne _0809811E
	b _080982FA
_0809811E:
	cmp r0, #1
	bgt _08098128
	cmp r0, #0
	beq _08098130
	b _08098406
_08098128:
	cmp r0, #2
	bne _0809812E
	b _080983E0
_0809812E:
	b _08098406
_08098130:
	movs r4, #0
	adds r0, r5, #0
	adds r0, #0xbe
	ldrb r0, [r0]
	cmp r0, #2
	beq _08098170
	cmp r0, #2
	bgt _08098146
	cmp r0, #1
	beq _08098154
	b _0809814E
_08098146:
	cmp r0, #3
	beq _0809818C
	cmp r0, #4
	beq _080981B0
_0809814E:
	adds r6, r5, #0
	adds r6, #0x4a
	b _080981F6
_08098154:
	ldr r4, _0809816C @ =0xFFFFEE00
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	adds r6, r5, #0
	adds r6, #0x4a
	cmp r0, #0
	beq _080981F6
	movs r4, #0x90
	lsls r4, r4, #5
	b _080981F6
	.align 2, 0
_0809816C: .4byte 0xFFFFEE00
_08098170:
	ldr r4, _08098188 @ =0xFFFFE800
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	adds r6, r5, #0
	adds r6, #0x4a
	cmp r0, #0
	beq _080981F6
	movs r4, #0xc0
	lsls r4, r4, #5
	b _080981F6
	.align 2, 0
_08098188: .4byte 0xFFFFE800
_0809818C:
	ldr r4, _080981AC @ =0xFFFFDD00
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0809819C
	movs r4, #0x8c
	lsls r4, r4, #6
_0809819C:
	lsrs r0, r1, #5
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _080981D4
	movs r0, #0x20
	orrs r0, r1
	b _080981D8
	.align 2, 0
_080981AC: .4byte 0xFFFFDD00
_080981B0:
	ldr r4, _080981D0 @ =0xFFFFD500
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080981C0
	movs r4, #0xac
	lsls r4, r4, #6
_080981C0:
	lsrs r0, r1, #5
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _080981D4
	movs r0, #0x20
	orrs r0, r1
	b _080981D8
	.align 2, 0
_080981D0: .4byte 0xFFFFD500
_080981D4:
	movs r0, #0xdf
	ands r0, r1
_080981D8:
	strb r0, [r5, #0xa]
	adds r0, r2, #0
	adds r1, r5, #0
	adds r1, #0x4d
	strb r0, [r1]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r0, r0, #5
	ldrb r2, [r3]
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3]
	adds r6, r3, #0
_080981F6:
	ldr r1, [r5, #0x58]
	adds r1, r1, r4
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0809823C
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl PushoutToUp1
	adds r4, r0, #0
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl PushoutToDown1
	adds r1, r0, #0
	cmp r4, #0
	bgt _08098236
	cmp r1, #0
	bge _0809822A
	ldr r0, [r5, #0x58]
	adds r0, r0, r4
	b _0809823A
_0809822A:
	rsbs r0, r4, #0
	cmp r0, r1
	bge _08098236
	ldr r0, [r5, #0x58]
	adds r0, r0, r4
	b _0809823A
_08098236:
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
_0809823A:
	str r0, [r5, #0x58]
_0809823C:
	ldr r1, _08098270 @ =0x0000DC07
	adds r0, r5, #0
	bl SetMotion
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _08098274 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r4, #0
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _0809825E
	movs r4, #1
_0809825E:
	movs r0, #1
	adds r2, r4, #0
	eors r2, r0
	cmp r2, #0
	beq _08098278
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0809827E
	.align 2, 0
_08098270: .4byte 0x0000DC07
_08098274: .4byte 0xFFFFF000
_08098278:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809827E:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	movs r7, #0
	strb r1, [r0]
	lsls r1, r1, #4
	ldrb r2, [r6]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r6]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	adds r3, r4, #0
	bl FUN_080b2b40
	movs r0, #0x80
	lsls r0, r0, #1
	lsls r4, r4, #9
	subs r0, r0, r4
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	asrs r0, r0, #1
	str r0, [r5, #0x60]
	adds r0, r5, #0
	bl FUN_080c6e24
	ldr r0, [r5, #0x5c]
	movs r1, #0xb4
	muls r0, r1, r0
	cmp r0, #0
	bge _080982C8
	adds r0, #0xff
_080982C8:
	asrs r0, r0, #8
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	muls r0, r1, r0
	cmp r0, #0
	bge _080982D6
	adds r0, #0xff
_080982D6:
	asrs r0, r0, #8
	str r0, [r5, #0x60]
	adds r0, r5, #0
	adds r0, #0x8c
	str r7, [r0]
	adds r0, #4
	str r7, [r0]
	adds r0, #4
	strb r7, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	movs r0, #0x14
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080982FA:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	bl PushoutToUp1
	adds r4, r0, #0
	cmp r4, #0
	bge _08098314
	ldr r0, [r5, #0x58]
	adds r0, r0, r4
	str r0, [r5, #0x58]
_08098314:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	cmp r1, #0
	ble _0809832E
	ldr r1, [r5, #0x58]
	bl PushoutToLeft1
	adds r4, r0, #0
	cmp r4, #0
	bge _08098340
	b _0809833A
_0809832E:
	ldr r1, [r5, #0x58]
	bl PushoutToRight1
	adds r4, r0, #0
	cmp r4, #0
	ble _08098340
_0809833A:
	ldr r0, [r5, #0x54]
	adds r0, r0, r4
	str r0, [r5, #0x54]
_08098340:
	ldr r1, [r5, #0x5c]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #5
	adds r0, r0, r1
	cmp r0, #0
	bge _08098350
	adds r0, #0xff
_08098350:
	asrs r0, r0, #8
	str r0, [r5, #0x5c]
	ldr r2, [r5, #0x60]
	cmp r2, #0
	bne _08098364
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08098374
_08098364:
	adds r0, r2, #0
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08098374
	str r1, [r5, #0x60]
_08098374:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080983CA
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _080983D4 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	adds r4, r5, #0
	adds r4, #0x54
	movs r0, #1
	adds r1, r4, #0
	bl TryDropItem
	ldr r2, _080983D8 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _080983DC @ =0x0000270E
	cmp r1, r0
	bhi _080983BC
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_080983BC:
	adds r0, r5, #0
	adds r1, r4, #0
	bl TryDropZakoDisk
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080983CA:
	adds r0, r5, #0
	bl UpdateEntityAnim
	b _08098406
	.align 2, 0
_080983D4: .4byte 0xFFFFF000
_080983D8: .4byte gScore
_080983DC: .4byte 0x0000270E
_080983E0:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080983F4
	subs r0, #1
	strb r0, [r5, #0x12]
	b _08098406
_080983F4:
	ldr r1, _08098410 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
_08098406:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08098410: .4byte gEnemyFnTable
