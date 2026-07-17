	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08093afc
FUN_08093afc: @ 0x08093AFC
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08093B48
	ldr r1, _08093B3C @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #2
	str r4, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r1
	cmp r0, #0
	bne _08093B40
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r1
	cmp r0, #0
	beq _08093B42
	strb r4, [r2, #0xd]
	b _08093B44
	.align 2, 0
_08093B3C: .4byte gEnemyFnTable
_08093B40:
	movs r0, #1
_08093B42:
	strb r0, [r2, #0xd]
_08093B44:
	movs r0, #1
	b _08093B4A
_08093B48:
	movs r0, #0
_08093B4A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08093b50
FUN_08093b50: @ 0x08093B50
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #7
	beq _08093BD6
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r5, [r0]
	cmp r5, #0
	bne _08093BD6
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _08093B70
	cmp r0, #1
	beq _08093BB4
	b _08093BD6
_08093B70:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _08093BD6
	ldr r1, _08093BAC @ =0x08369E18
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08093BB0 @ =0x08369E3C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl UpdateEntityAnim
_08093BA6:
	movs r0, #1
	b _08093BD8
	.align 2, 0
_08093BAC: .4byte 0x08369E18
_08093BB0: .4byte 0x08369E3C
_08093BB4:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _08093BD4
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _08093BD0 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _08093BA6
	strb r5, [r4, #0xf]
	b _08093BD6
	.align 2, 0
_08093BD0: .4byte 0x00020001
_08093BD4:
	strb r0, [r4, #0xf]
_08093BD6:
	movs r0, #0
_08093BD8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08093be0
FUN_08093be0: @ 0x08093BE0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r2, [r6]
	cmp r2, #0
	bne _08093C20
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08093C20
	movs r5, #0x80
	lsls r5, r5, #0xa
	ands r5, r1
	cmp r5, #0
	beq _08093C0C
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _08093C20
_08093C0C:
	ldr r2, _08093C28 @ =0x08369EB4
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _08093C20
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_08093C20:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08093C28: .4byte 0x08369EB4

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

