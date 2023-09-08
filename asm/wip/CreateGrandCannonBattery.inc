	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08069004 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _08068FFC
	str r4, [r3, #0x28]
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _08069008 @ =gEnemyFnTable
	movs r0, #6
	strb r0, [r3, #9]
	ldr r0, [r1, #0x18]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r2, [r3, #0xb]
	movs r1, #0x10
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	movs r0, #1
	strb r0, [r3, #0x10]
	orrs r1, r2
	strb r1, [r3, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r3, #0x1d]
_08068FFC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08069004: .4byte gZakoHeaderPtr
_08069008: .4byte gEnemyFnTable
