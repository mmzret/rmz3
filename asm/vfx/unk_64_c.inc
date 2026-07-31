	.include "asm/macros.inc"

	.syntax unified
	
	.text

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

	thumb_func_start FUN_080c40ec
FUN_080c40ec: @ 0x080C40EC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C40FC
	cmp r0, #1
	beq _080C410A
	b _080C4136
_080C40FC:
	ldr r1, _080C413C @ =0x00008006
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C410A:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r2, [r0]
	cmp r2, #3
	bne _080C4136
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C4140 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080C4136:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C413C: .4byte 0x00008006
_080C4140: .4byte gVFXFnTable

	thumb_func_start FUN_080c4144
FUN_080c4144: @ 0x080C4144
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x34
	ldr r6, [r4, #0x28]
	adds r7, r6, #0
	adds r7, #0x34
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C415E
	cmp r0, #1
	beq _080C41A4
	b _080C4242
_080C415E:
	adds r0, r4, #0
	bl InitScalerotMotion1
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	adds r1, #0x2b
	movs r3, #0
	adds r0, #0xe7
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	ldrb r1, [r5, #0x15]
	movs r0, #0xf
	ands r0, r1
	movs r1, #0xd0
	orrs r0, r1
	strb r0, [r5, #0x15]
	adds r0, r6, #0
	adds r0, #0x54
	str r0, [r5, #0xc]
	ldrh r1, [r7, #0x14]
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x16
	ldrh r2, [r5, #0x14]
	ldr r0, _080C4248 @ =0xFFFFFC00
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, #0x14]
	strb r3, [r4, #0x12]
	strb r3, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C41A4:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0x13]
	movs r1, #3
	bl __umodsi3
	strb r0, [r4, #0x13]
	ldr r1, _080C424C @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsrs r0, r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _080C41D4
	adds r0, #0xff
_080C41D4:
	asrs r0, r0, #8
	adds r2, r0, #0
	adds r2, #0xf0
	ldrb r1, [r4, #0x13]
	lsls r1, r1, #4
	movs r0, #0x88
	lsls r0, r0, #1
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r0, r1
	cmp r1, #0
	bge _080C41EE
	adds r1, #0xff
_080C41EE:
	asrs r1, r1, #8
	adds r0, r4, #0
	adds r0, #0x50
	movs r3, #0
	strh r1, [r0]
	ldrb r1, [r4, #0x13]
	lsls r1, r1, #4
	movs r0, #0x80
	lsls r0, r0, #1
	subs r0, r0, r1
	muls r0, r2, r0
	cmp r0, #0
	bge _080C420A
	adds r0, #0xff
_080C420A:
	asrs r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	ldr r0, [r7, #8]
	str r0, [r5, #8]
	ldrb r0, [r7, #0x1a]
	strb r0, [r5, #0x1a]
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	ands r0, r2
	strb r0, [r5, #0x18]
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #4
	ands r1, r2
	lsls r1, r1, #4
	ldrb r2, [r5, #0x16]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, #0x16]
	ldrb r0, [r4, #0x12]
	cmp r0, #0x8f
	bls _080C4242
	strb r3, [r4, #0xd]
	strb r3, [r4, #0xe]
_080C4242:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C4248: .4byte 0xFFFFFC00
_080C424C: .4byte gSineTable
