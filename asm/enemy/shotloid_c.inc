	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Shotloid_Init
Shotloid_Init: @ 0x08093C2C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x10]
	cmp r0, #2
	bne _08093C3E
	movs r0, #0
	strb r0, [r5, #0x10]
	movs r0, #1
	b _08093C40
_08093C3E:
	movs r0, #0
_08093C40:
	strb r0, [r5, #0x11]
	ldr r1, _08093CC0 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _08093CC4 @ =0x08369EBC
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r7, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r6, [r5, #0x10]
	cmp r6, #0
	bne _08093D12
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _08093CC8 @ =0x08369E6C
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _08093CCC @ =nop_08093af8
	str r0, [r4, #0x24]
	adds r0, r5, #0
	adds r0, #0xb4
	str r6, [r0]
	adds r0, #4
	str r6, [r0]
	movs r2, #0
	ldr r0, _08093CD0 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _08093CB2
	movs r2, #1
_08093CB2:
	cmp r2, #0
	beq _08093CD4
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08093CDA
	.align 2, 0
_08093CC0: .4byte gEnemyFnTable
_08093CC4: .4byte 0x08369EBC
_08093CC8: .4byte 0x08369E6C
_08093CCC: .4byte nop_08093af8
_08093CD0: .4byte pZero2
_08093CD4:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_08093CDA:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r5, #0
	bl FUN_08093994
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	beq _08093D0A
	adds r1, r5, #0
	adds r1, #0xbc
	movs r0, #0
	b _08093D10
_08093D0A:
	adds r1, r5, #0
	adds r1, #0xbc
	movs r0, #3
_08093D10:
	strb r0, [r1]
_08093D12:
	adds r0, r5, #0
	bl Shotloid_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
