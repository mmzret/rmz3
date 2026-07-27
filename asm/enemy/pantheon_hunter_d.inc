	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start phunter_08065218
phunter_08065218: @ 0x08065218
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _08065234
	movs r1, #0x98
	lsls r1, r1, #5
	bl SetMotion
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08065234:
	adds r0, r4, #0
	bl UpdateEntityAnim
	movs r2, #0
	ldr r0, _08065258 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _0806524A
	movs r2, #1
_0806524A:
	cmp r2, #0
	beq _0806525C
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08065262
	.align 2, 0
_08065258: .4byte pZero2
_0806525C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08065262:
	strb r0, [r4, #0xa]
	movs r6, #1
	adds r1, r6, #0
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r0, _080652E0 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	movs r1, #0xa
	ldrsh r0, [r0, r1]
	cmp r0, #6
	ble _080652D8
	movs r5, #0
	ldr r0, _080652E4 @ =pZero2
	ldr r3, [r0]
	ldr r2, [r3, #0x54]
	ldr r1, [r4, #0x54]
	cmp r2, r1
	bgt _0806529E
	movs r5, #1
_0806529E:
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	ands r0, r6
	cmp r5, r0
	beq _080652D8
	subs r0, r2, r1
	movs r1, #0xdc
	lsls r1, r1, #7
	adds r0, r0, r1
	movs r1, #0xdc
	lsls r1, r1, #8
	cmp r0, r1
	bhi _080652D8
	ldr r0, [r3, #0x58]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	movs r1, #0xa0
	lsls r1, r1, #7
	adds r0, r0, r1
	movs r1, #0xa0
	lsls r1, r1, #8
	cmp r0, r1
	bhi _080652D8
	ldrb r0, [r4, #0xd]
	strb r0, [r4, #0xf]
	movs r0, #7
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_080652D8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080652E0: .4byte gProjectileHeaderPtr
_080652E4: .4byte pZero2
