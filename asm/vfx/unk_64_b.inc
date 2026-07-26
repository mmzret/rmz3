	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c3f74
FUN_080c3f74: @ 0x080C3F74
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C3F86
	cmp r0, #1
	beq _080C3F98
	b _080C3FC8
_080C3F86:
	ldr r1, _080C3FF4 @ =0x0000800A
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0xe
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C3F98:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C3FC8
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C3FF8 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080C3FC8:
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080C3FEC
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C3FF8 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080C3FEC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C3FF4: .4byte 0x0000800A
_080C3FF8: .4byte gVFXFnTable

	thumb_func_start FUN_080c3ffc
FUN_080c3ffc: @ 0x080C3FFC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C400C
	cmp r0, #1
	beq _080C401A
	b _080C406A
_080C400C:
	adds r0, r4, #0
	movs r1, #8
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C401A:
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	ble _080C403C
	adds r0, r4, #0
	bl _GetEntityPaletteID
	adds r1, r0, #0
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl _ForceEntityPalette
_080C403C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _080C406A
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C4070 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080C406A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C4070: .4byte gVFXFnTable

	thumb_func_start FUN_080c4074
FUN_080c4074: @ 0x080C4074
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C4084
	cmp r0, #1
	beq _080C4092
	b _080C40E2
_080C4084:
	adds r0, r4, #0
	movs r1, #0x12
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C4092:
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	ble _080C40B4
	adds r0, r4, #0
	bl _GetEntityPaletteID
	adds r1, r0, #0
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl _ForceEntityPalette
_080C40B4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _080C40E2
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C40E8 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080C40E2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C40E8: .4byte gVFXFnTable
