	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Solid43_Update
Solid43_Update: @ 0x080DE038
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r2, r4, #0
	adds r2, #0x8c
	ldr r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080DE11C
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r1, r0
	cmp r1, #0
	beq _080DE11C
	movs r1, #0
	str r1, [r2]
	adds r0, r4, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	movs r1, #0x9c
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	bl FUN_08014b04
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #4
	bl AppendQuake
	ldr r0, _080DE128 @ =0x0000011D
	bl PlaySound
	movs r5, #0
	movs r6, #0
	ldr r7, _080DE12C @ =0x0836FBD0
_080DE0A0:
	ldr r0, _080DE130 @ =gSolidHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r2, r0, #0
	lsls r3, r5, #0x10
	cmp r2, #0
	beq _080DE0F6
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #0x1e
	strb r0, [r1]
	movs r0, #0x2b
	strb r0, [r2, #9]
	ldr r0, [r7]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	strh r6, [r2, #0x20]
	adds r0, r2, #0
	adds r0, #0x22
	strb r6, [r0]
	ldrb r0, [r2, #0xb]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #0xb]
	ldrb r0, [r2, #0x1c]
	strb r0, [r2, #0x1d]
	movs r0, #1
	strb r0, [r2, #0x10]
	ldr r0, [r4, #0x54]
	str r0, [r2, #0x54]
	ldr r1, [r4, #0x58]
	asrs r0, r3, #0x10
	cmp r0, #0
	bne _080DE0EA
	ldr r5, _080DE134 @ =0xFFFFF000
	adds r1, r1, r5
_080DE0EA:
	str r1, [r2, #0x58]
	cmp r0, #1
	ble _080DE0F6
	lsls r0, r0, #0xc
	adds r0, r1, r0
	str r0, [r2, #0x58]
_080DE0F6:
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r3, r1
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _080DE0A0
	ldr r1, _080DE138 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Solid43_Die
_080DE11C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DE128: .4byte 0x0000011D
_080DE12C: .4byte gSolidFnTable+(4*43)
_080DE130: .4byte gSolidHeaderPtr
_080DE134: .4byte 0xFFFFF000
_080DE138: .4byte gSolidFnTable

	thumb_func_start Solid43_Die
Solid43_Die: @ 0x080DE13C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #0
	bne _080DE18A
	ldr r5, _080DE1DC @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _080DE1E0 @ =0x000343FD
	muls r0, r4, r0
	ldr r3, _080DE1E4 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsls r0, r0, #4
	lsrs r0, r0, #0x15
	ldr r1, [r6, #0x54]
	adds r1, r1, r0
	str r1, [sp]
	adds r0, r2, #0
	muls r0, r4, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsls r0, r0, #3
	lsrs r0, r0, #0x14
	ldr r1, [r6, #0x58]
	adds r1, r1, r0
	ldr r0, _080DE1E8 @ =0xFFFFF800
	adds r1, r1, r0
	str r1, [sp, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080DE18A:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r1, [r6, #0x60]
	ldr r0, _080DE1EC @ =0x000006FF
	cmp r1, r0
	bgt _080DE19E
	adds r0, r1, #0
	adds r0, #0x20
	str r0, [r6, #0x60]
_080DE19E:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	str r0, [r6, #0x68]
	ldr r0, _080DE1F0 @ =gStageRun+232
	adds r1, r6, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #6
	cmp r0, r1
	bls _080DE1D4
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080DE1F4 @ =gSolidFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r6, #0x14]
_080DE1D4:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DE1DC: .4byte RNG_0202f388
_080DE1E0: .4byte 0x000343FD
_080DE1E4: .4byte 0x00269EC3
_080DE1E8: .4byte 0xFFFFF800
_080DE1EC: .4byte 0x000006FF
_080DE1F0: .4byte gStageRun+232
_080DE1F4: .4byte gSolidFnTable
