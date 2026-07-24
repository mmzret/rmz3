	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start createPantheonFistInElevator
createPantheonFistInElevator: @ 0x08094F40
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _08094FA0 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _08094F96
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08094FA4 @ =gEnemyFnTable
	movs r1, #0x40
	strb r1, [r3, #9]
	adds r1, #0xc0
	adds r0, r0, r1
	ldr r0, [r0]
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
	movs r0, #1
	strb r0, [r3, #0x10]
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
	adds r0, r3, #0
	adds r0, #0xb9
	strb r4, [r0]
_08094F96:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08094FA0: .4byte gEnemyHeaderPtr
_08094FA4: .4byte gEnemyFnTable
