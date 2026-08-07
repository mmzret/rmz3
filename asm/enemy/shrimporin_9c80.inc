	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08069C90
	cmp r0, #1
	beq _08069CA2
	b _08069CF6
_08069C90:
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08069CFC @ =sCollisions+48
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08069CA2:
	adds r0, r4, #0
	bl IsFrozen
	adds r5, r0, #0
	cmp r5, #0
	bne _08069CE0
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08069CBE
	str r1, [r4, #0x60]
_08069CBE:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl PushoutToUp2
	adds r1, r0, #0
	cmp r1, #0
	bge _08069CE0
	str r5, [r4, #0x60]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_08069CE0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_08069CF6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08069CFC: .4byte sCollisions+48
