	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start grandcannonMoveTurret
grandcannonMoveTurret: @ 0x08069408
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x28]
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0806941A
	cmp r0, #1
	beq _08069450
	b _08069544
_0806941A:
	adds r0, r5, #0
	bl InitRotatableMotion
	ldr r1, _080694B8 @ =0x00000703
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x78
	strb r0, [r5, #0x12]
	ldr r1, [r4, #0x54]
	str r1, [r5, #0x54]
	ldr r0, [r4, #0x58]
	ldr r2, _080694BC @ =0xFFFFFA00
	adds r0, r0, r2
	str r0, [r5, #0x58]
	ldr r0, _080694C0 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	subs r0, r0, r1
	str r0, [r5, #0x64]
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #0x40
	strb r0, [r1]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08069450:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	bne _08069544
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	bne _08069544
	ldr r1, [r4, #0x54]
	str r1, [r5, #0x54]
	ldr r0, [r4, #0x58]
	ldr r3, _080694BC @ =0xFFFFFA00
	adds r0, r0, r3
	str r0, [r5, #0x58]
	ldr r0, _080694C0 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	subs r2, r0, r1
	ldr r1, [r5, #0x64]
	subs r2, r2, r1
	adds r0, r2, #0
	cmp r2, #0
	bge _0806948A
	adds r0, #0xf
_0806948A:
	asrs r2, r0, #4
	adds r2, r1, r2
	str r2, [r5, #0x64]
	ldr r3, _080694C4 @ =gSineTable
	adds r4, r5, #0
	adds r4, #0xb8
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #3
	adds r2, r2, r0
	adds r1, #4
	strb r1, [r4]
	cmp r2, #0
	ble _080694F4
	ldr r0, _080694C8 @ =0x00000FFF
	cmp r2, r0
	bgt _080694CC
	movs r2, #0x80
	lsls r2, r2, #5
	b _080694D6
	.align 2, 0
_080694B8: .4byte 0x00000703
_080694BC: .4byte 0xFFFFFA00
_080694C0: .4byte pZero2
_080694C4: .4byte gSineTable
_080694C8: .4byte 0x00000FFF
_080694CC:
	movs r0, #0xf0
	lsls r0, r0, #7
	cmp r2, r0
	ble _080694D6
	adds r2, r0, #0
_080694D6:
	ldr r0, _080694F0 @ =0xFFFFF000
	adds r2, r2, r0
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	movs r1, #0xd0
	lsls r1, r1, #7
	bl __divsi3
	movs r1, #0x40
	subs r2, r1, r0
	b _08069518
	.align 2, 0
_080694F0: .4byte 0xFFFFF000
_080694F4:
	ldr r0, _0806954C @ =0xFFFFF000
	cmp r2, r0
	bgt _08069500
	ldr r0, _08069550 @ =0xFFFF8800
	cmp r2, r0
	bge _08069502
_08069500:
	adds r2, r0, #0
_08069502:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r2, r2, r3
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	ldr r1, _08069554 @ =0xFFFF9800
	bl __divsi3
	adds r2, r0, #0
	adds r2, #0x40
_08069518:
	rsbs r0, r2, #0
	subs r0, #0x80
	adds r1, r5, #0
	adds r1, #0x24
	strb r0, [r1]
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _08069544
	ldr r0, _08069558 @ =gStageRun+232
	adds r1, #0x30
	bl Camera_GetDistance
	ldr r1, _0806955C @ =0x00000FFF
	cmp r0, r1
	bhi _08069544
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r4, [r5, #0xe]
_08069544:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806954C: .4byte 0xFFFFF000
_08069550: .4byte 0xFFFF8800
_08069554: .4byte 0xFFFF9800
_08069558: .4byte gStageRun+232
_0806955C: .4byte 0x00000FFF

	thumb_func_start grandcannonBombShot
grandcannonBombShot: @ 0x08069560
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _08069572
	cmp r0, #1
	beq _080695DC
	b _080695F6
_08069572:
	movs r0, #0x2d
	bl PlaySound
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r0, [r0]
	adds r0, #0x80
	lsls r0, r0, #0x18
	ldr r2, [r5, #0x54]
	str r2, [sp]
	ldr r3, _08069600 @ =gSineTable
	lsrs r4, r0, #0x18
	movs r1, #0x80
	lsls r1, r1, #0x17
	adds r0, r0, r1
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r6, #0
	ldrsh r1, [r0, r6]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	str r0, [sp]
	ldr r2, [r5, #0x58]
	str r2, [sp, #4]
	lsls r0, r4, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	str r0, [sp, #4]
	movs r0, #0x2d
	bl PlaySound
	movs r1, #0xa0
	lsls r1, r1, #3
	mov r0, sp
	adds r2, r4, #0
	bl CreateGrandCannonBomb
	movs r0, #4
	strb r0, [r5, #0x12]
	ldr r1, _08069604 @ =0x00000704
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080695DC:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080695F6
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_080695F6:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08069600: .4byte gSineTable
_08069604: .4byte 0x00000704

