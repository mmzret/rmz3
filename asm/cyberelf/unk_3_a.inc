	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Elf3_Update
Elf3_Update: @ 0x080E2A58
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r2, [r3, #0x2c]
	ldr r0, [r3, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _080E2A72
	adds r5, r2, #0
	adds r5, #0xa4
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bne _080E2A90
_080E2A72:
	ldr r1, _080E2A8C @ =gElfFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r3, #0x14]
	adds r0, r3, #0
	bl Elf3_Die
	b _080E2AC4
	.align 2, 0
_080E2A8C: .4byte gElfFnTable
_080E2A90:
	ldr r0, [r2, #0x54]
	ldr r1, [r2, #0x58]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r4, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r4, r0
	cmp r4, #0
	bne _080E2AC4
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	beq _080E2AC4
	ldrb r0, [r3, #0x12]
	cmp r0, #0
	beq _080E2AC4
	ldr r2, _080E2ACC @ =gLifeRecoverAmount
	adds r1, r0, #0
	lsls r1, r1, #2
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r2]
	strb r4, [r3, #0x12]
_080E2AC4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080E2ACC: .4byte gLifeRecoverAmount

