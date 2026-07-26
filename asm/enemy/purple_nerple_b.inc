	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08075c40
FUN_08075c40: @ 0x08075C40
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, _08075CB8 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08075CB0
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _08075CBC @ =gEnemyFnTable
	movs r0, #0x16
	strb r0, [r3, #9]
	ldr r0, [r1, #0x58]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	movs r0, #2
	strb r0, [r3, #0x10]
	ldr r2, _08075CC0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08075CC4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08075CC8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	strb r0, [r3, #0x11]
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
	str r6, [r3, #0x5c]
	str r7, [r3, #0x60]
	adds r0, r3, #0
	adds r0, #0xb9
	strb r1, [r0]
_08075CB0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08075CB8: .4byte gEnemyHeaderPtr
_08075CBC: .4byte gEnemyFnTable
_08075CC0: .4byte RNG_0202f388
_08075CC4: .4byte 0x000343FD
_08075CC8: .4byte 0x00269EC3
