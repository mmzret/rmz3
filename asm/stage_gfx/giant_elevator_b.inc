	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start giantElevator_08014a64
giantElevator_08014a64: @ 0x08014A64
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	bne _08014AAA
	lsrs r2, r0, #0x14
	lsls r3, r2, #1
	ldr r4, _08014AC4 @ =gVideoRegBuffer+4
	adds r3, r3, r4
	ldr r0, [r5, #0x60]
	ldr r1, [r5, #0x64]
	orrs r0, r1
	movs r1, #0x44
	orrs r0, r1
	strh r0, [r3]
	lsls r2, r2, #2
	adds r4, #8
	adds r2, r2, r4
	str r6, [r2]
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08014AC8 @ =gBgMapOffsets
	str r6, [sp]
	movs r2, #0x5c
	movs r3, #0
	bl LoadBgMap
	strh r6, [r5, #0x10]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08014AAA:
	ldr r0, _08014ACC @ =gOverworld
	ldr r1, _08014AD0 @ =0x0002D025
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08014ABC
	ldrh r0, [r5, #0x10]
	adds r0, #1
	strh r0, [r5, #0x10]
_08014ABC:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014AC4: .4byte gVideoRegBuffer+4
_08014AC8: .4byte gBgMapOffsets
_08014ACC: .4byte gOverworld
_08014AD0: .4byte 0x0002D025
