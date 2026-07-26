	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start GlacierleAtkArm_Die
GlacierleAtkArm_Die: @ 0x08082984
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	blt _08082A12
	cmp r0, #1
	ble _08082998
	cmp r0, #2
	beq _08082A00
	b _08082A12
_08082998:
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	beq _080829A4
	cmp r0, #1
	beq _080829AC
	b _08082A12
_080829A4:
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080829AC:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080829BC
	str r1, [r4, #0x60]
_080829BC:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08082A12
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080829E8
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	b _08082A00
_080829E8:
	adds r0, r4, #0
	adds r0, #0xb6
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08082A00
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
_08082A00:
	ldr r1, _08082A18 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_08082A12:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08082A18: .4byte gEnemyFnTable

