	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08065104
FUN_08065104: @ 0x08065104
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _08065122
	movs r1, #0x98
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08065122:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, _08065184 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	movs r1, #0xa
	ldrsh r0, [r0, r1]
	cmp r0, #6
	ble _0806518C
	movs r6, #0
	ldr r0, _08065188 @ =pZero2
	ldr r5, [r0]
	ldr r3, [r5, #0x54]
	ldr r2, [r4, #0x54]
	cmp r3, r2
	bgt _08065144
	movs r6, #1
_08065144:
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r6, r0
	beq _0806518C
	subs r0, r3, r2
	movs r1, #0xdc
	lsls r1, r1, #7
	adds r0, r0, r1
	movs r1, #0xdc
	lsls r1, r1, #8
	cmp r0, r1
	bhi _0806518C
	ldr r0, [r5, #0x58]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	movs r1, #0xa0
	lsls r1, r1, #7
	adds r0, r0, r1
	movs r1, #0xa0
	lsls r1, r1, #8
	cmp r0, r1
	bhi _0806518C
	ldrb r0, [r4, #0xd]
	movs r1, #0
	strb r0, [r4, #0xf]
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _080651B8
	.align 2, 0
_08065184: .4byte gProjectileHeaderPtr
_08065188: .4byte pZero2
_0806518C:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080651B8
	movs r0, #6
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
	movs r2, #0
	adds r1, r4, #0
	adds r1, #0xbd
	ldrb r0, [r1]
	cmp r0, #0
	bne _080651B0
	movs r2, #1
_080651B0:
	strb r2, [r1]
	adds r0, r4, #0
	bl FUN_08064e7c
_080651B8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
