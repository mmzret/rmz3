	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start lamplort_0806cc04
lamplort_0806cc04: @ 0x0806CC04
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0806CC82
	cmp r0, #1
	bgt _0806CC18
	cmp r0, #0
	beq _0806CC20
	b _0806CD40
_0806CC18:
	cmp r0, #2
	bne _0806CC1E
	b _0806CD38
_0806CC1E:
	b _0806CD40
_0806CC20:
	ldr r1, _0806CC44 @ =0x00001902
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806CC48 @ =0x08366608
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r2, [r0]
	cmp r2, #0
	beq _0806CC4C
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0806CC52
	.align 2, 0
_0806CC44: .4byte 0x00001902
_0806CC48: .4byte sCollisions+(5*24)
_0806CC4C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0806CC52:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	movs r3, #0
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	strb r3, [r4, #0x13]
	movs r0, #8
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806CC82:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0806CC92
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806CD30
_0806CC92:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #2
	bls _0806CCA8
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0806CCE6
_0806CCA8:
	movs r0, #8
	strb r0, [r4, #0x12]
	cmp r1, #2
	bne _0806CCC0
	ldr r0, _0806CCD4 @ =Action_ARRAY_080ff004
	ldrb r1, [r4, #0x13]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	adds r0, r4, #0
	bl SetMotion
_0806CCC0:
	ldrb r0, [r4, #0x13]
	cmp r0, #1
	bne _0806CCDC
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806CCD8 @ =0x08366608
	bl SetDDP
	b _0806CCE6
	.align 2, 0
_0806CCD4: .4byte Action_ARRAY_080ff004
_0806CCD8: .4byte sCollisions+(5*24)
_0806CCDC:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806CD08 @ =sCollisions
	bl SetDDP
_0806CCE6:
	ldrb r0, [r4, #0x13]
	cmp r0, #1
	bne _0806CD30
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r1, [r0]
	movs r2, #1
	eors r1, r2
	strb r1, [r0]
	ldrb r2, [r0]
	cmp r2, #0
	beq _0806CD0C
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0806CD12
	.align 2, 0
_0806CD08: .4byte sCollisions
_0806CD0C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0806CD12:
	strb r0, [r4, #0xa]
	movs r1, #1
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
_0806CD30:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _0806CD40
_0806CD38:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806CD40:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

