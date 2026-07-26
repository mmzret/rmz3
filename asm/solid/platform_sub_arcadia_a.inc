	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080cf250
FUN_080cf250: @ 0x080CF250
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080CF260
	cmp r0, #1
	beq _080CF292
	b _080CF35C
_080CF260:
	ldr r1, _080CF364 @ =0x0837060C
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	ldr r1, _080CF368 @ =0x08370628
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #2
	adds r1, #2
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CF292:
	ldr r5, _080CF36C @ =0x0000FFFF
	ldrh r0, [r4, #0x12]
	cmp r0, #1
	bne _080CF2C0
	ldr r1, _080CF364 @ =0x0837060C
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x71
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, #1
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	adds r0, r4, #0
	bl GotoMotion
_080CF2C0:
	ldrh r0, [r4, #0x12]
	ands r5, r0
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r5, r0
	bne _080CF2F2
	ldr r1, _080CF370 @ =0x08370614
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x71
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, #1
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	adds r0, r4, #0
	bl GotoMotion
_080CF2F2:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r5, _080CF374 @ =0x08370638
	ldrb r2, [r4, #0x10]
	lsls r2, r2, #3
	adds r0, r2, r5
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	adds r1, r5, #2
	adds r2, r2, r1
	movs r1, #0
	ldrsh r2, [r2, r1]
	ldr r1, [r4, #0x58]
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080CF354
	ldrb r2, [r4, #0x10]
	lsls r2, r2, #3
	adds r0, r5, #4
	adds r0, r2, r0
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	adds r1, r5, #6
	adds r2, r2, r1
	movs r1, #0
	ldrsh r2, [r2, r1]
	ldr r1, [r4, #0x58]
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CF35C
_080CF354:
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080CF35C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CF364: .4byte 0x0837060C
_080CF368: .4byte 0x08370628
_080CF36C: .4byte 0x0000FFFF
_080CF370: .4byte 0x08370614
_080CF374: .4byte 0x08370638

	thumb_func_start FUN_080cf378
FUN_080cf378: @ 0x080CF378
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080CF388
	cmp r0, #1
	beq _080CF38C
	b _080CF414
_080CF388:
	movs r0, #1
	strb r0, [r4, #0xe]
_080CF38C:
	ldr r5, _080CF41C @ =0x0000FFFF
	ldrh r0, [r4, #0x12]
	cmp r0, #1
	bne _080CF3BA
	ldr r1, _080CF420 @ =0x0837060C
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x71
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, #1
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	adds r0, r4, #0
	bl GotoMotion
_080CF3BA:
	ldrh r0, [r4, #0x12]
	ands r5, r0
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r5, r0
	bne _080CF3EC
	ldr r1, _080CF424 @ =0x08370614
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x71
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, #1
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	adds r0, r4, #0
	bl GotoMotion
_080CF3EC:
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	subs r1, r1, r0
	str r1, [r4, #0x54]
	ldr r2, [r4, #0x58]
	ldr r0, [r4, #0x60]
	subs r2, r2, r0
	str r2, [r4, #0x58]
	ldr r0, [r4, #0x64]
	cmp r1, r0
	bne _080CF40E
	ldr r0, [r4, #0x68]
	cmp r2, r0
	bne _080CF40E
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_080CF40E:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080CF414:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CF41C: .4byte 0x0000FFFF
_080CF420: .4byte 0x0837060C
_080CF424: .4byte 0x08370614

