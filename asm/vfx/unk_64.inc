	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c3cbc
FUN_080c3cbc: @ 0x080C3CBC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x34
	ldr r6, [r4, #0x28]
	adds r7, r6, #0
	adds r7, #0x34
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C3CD6
	cmp r0, #1
	beq _080C3CDE
	b _080C3D78
_080C3CD6:
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C3CDE:
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
	movs r2, #0x9c
	lsls r2, r2, #1
	ldr r1, _080C3D80 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _080C3D0A
	adds r0, #0xf
_080C3D0A:
	asrs r0, r0, #4
	adds r2, r0, r2
	ldrb r1, [r4, #0x13]
	lsls r1, r1, #4
	movs r0, #0x88
	lsls r0, r0, #1
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r0, r1
	cmp r1, #0
	bge _080C3D22
	adds r1, #0xff
_080C3D22:
	asrs r1, r1, #8
	adds r0, r4, #0
	adds r0, #0x50
	strh r1, [r0]
	ldrb r1, [r4, #0x13]
	lsls r1, r1, #4
	movs r0, #0x80
	lsls r0, r0, #1
	subs r0, r0, r1
	muls r0, r2, r0
	cmp r0, #0
	bge _080C3D3C
	adds r0, #0xff
_080C3D3C:
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
	ldrb r0, [r6, #0xc]
	cmp r0, #1
	bls _080C3D78
	movs r0, #1
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_080C3D78:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3D80: .4byte gSineTable

	thumb_func_start FUN_080c3d84
FUN_080c3d84: @ 0x080C3D84
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x34
	ldr r7, [r5, #0x28]
	movs r0, #0x34
	adds r0, r0, r7
	mov sb, r0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _080C3DA6
	cmp r0, #1
	beq _080C3DC8
	b _080C3E7E
_080C3DA6:
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	ldr r0, _080C3E8C @ =gSineTable
	adds r0, #0x78
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _080C3DB8
	adds r0, #0x1f
_080C3DB8:
	asrs r0, r0, #5
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080C3DC8:
	ldr r0, [r5, #0x5c]
	movs r1, #0x80
	lsls r1, r1, #1
	mov r8, r1
	subs r4, r1, r0
	cmp r4, #0
	bge _080C3DD8
	adds r4, #0xf
_080C3DD8:
	asrs r4, r4, #4
	adds r4, r0, r4
	str r4, [r5, #0x5c]
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0x13]
	movs r1, #3
	bl __umodsi3
	strb r0, [r5, #0x13]
	ldrb r1, [r5, #0x13]
	lsls r1, r1, #4
	movs r0, #0x88
	lsls r0, r0, #1
	subs r0, r0, r1
	adds r1, r4, #0
	muls r1, r0, r1
	cmp r1, #0
	bge _080C3E02
	adds r1, #0xff
_080C3E02:
	asrs r1, r1, #8
	adds r0, r5, #0
	adds r0, #0x50
	strh r1, [r0]
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #4
	mov r1, r8
	subs r0, r1, r0
	ldr r1, [r5, #0x5c]
	muls r0, r1, r0
	cmp r0, #0
	bge _080C3E1C
	adds r0, #0xff
_080C3E1C:
	asrs r0, r0, #8
	adds r2, r5, #0
	adds r2, #0x52
	strh r0, [r2]
	mov r1, sb
	ldr r0, [r1, #8]
	str r0, [r6, #8]
	ldrb r0, [r1, #0x1a]
	strb r0, [r6, #0x1a]
	ldrb r0, [r7, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	ands r0, r2
	strb r0, [r6, #0x18]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r2
	lsls r1, r1, #4
	ldrb r2, [r6, #0x16]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r6, #0x16]
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080C3E60
	ldr r1, [r5, #0x5c]
	ldr r0, _080C3E90 @ =0x0000010F
	cmp r1, r0
	bgt _080C3E7E
_080C3E60:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080C3E94 @ =gVFXFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_080C3E7E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3E8C: .4byte gSineTable
_080C3E90: .4byte 0x0000010F
_080C3E94: .4byte gVFXFnTable

	thumb_func_start FUN_080c3e98
FUN_080c3e98: @ 0x080C3E98
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C3EAA
	cmp r0, #1
	beq _080C3EBE
	b _080C3EEE
_080C3EAA:
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0xe
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C3EBE:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C3EEE
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C3F18 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080C3EEE:
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080C3F12
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C3F18 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080C3F12:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C3F18: .4byte gVFXFnTable

	thumb_func_start FUN_080c3f1c
FUN_080c3f1c: @ 0x080C3F1C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C3F2C
	cmp r0, #1
	beq _080C3F3A
	b _080C3F66
_080C3F2C:
	ldr r1, _080C3F6C @ =0x00008004
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C3F3A:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r2, [r0]
	cmp r2, #3
	bne _080C3F66
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C3F70 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080C3F66:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C3F6C: .4byte 0x00008004
_080C3F70: .4byte gVFXFnTable

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
