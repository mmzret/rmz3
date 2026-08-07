	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Elf7_Update
Elf7_Update: @ 0x080E3B4C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r0, #0xb4
	ldr r4, [r0]
	ldr r1, _080E3BA0 @ =gZeroRanges
	ldr r2, _080E3BA4 @ =0x00000147
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r5, [r0]
	ldr r6, [r0, #4]
	adds r0, r7, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080E3B8A
	adds r0, r4, #0
	adds r0, #0xa4
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _080E3BAC
_080E3B8A:
	ldr r1, _080E3BA8 @ =gElfFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	b _080E3D08
	.align 2, 0
_080E3BA0: .4byte gZeroRanges
_080E3BA4: .4byte 0x00000147
_080E3BA8: .4byte gElfFnTable
_080E3BAC:
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	asrs r1, r5, #0x10
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r1, _080E3C40 @ =0x08371D88
	ldrb r0, [r7, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	adds r0, r7, #0
	adds r0, #0xc0
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _080E3C44 @ =gSineTable
	adds r0, r2, #0
	adds r0, #0x82
	movs r4, #0
	ldrsh r0, [r0, r4]
	mov r1, r8
	muls r1, r0, r1
	asrs r1, r1, #8
	mov r0, r8
	subs r1, r0, r1
	movs r3, #2
	ldrsh r0, [r2, r3]
	mov r4, r8
	muls r4, r0, r4
	adds r0, r4, #0
	asrs r0, r0, #8
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r5, r1, r0
	cmp r5, #0
	beq _080E3C4C
	ldr r0, _080E3C48 @ =0x000FFFFF
	cmp r5, r0
	bgt _080E3C4C
	movs r4, #0x80
	lsls r4, r4, #0xd
	adds r0, r4, #0
	adds r1, r5, #0
	bl __divsi3
	adds r6, r0, #0
	adds r0, r4, #0
	adds r1, r5, #0
	bl __modsi3
	cmp r0, #0
	beq _080E3C2A
	adds r6, #1
_080E3C2A:
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	adds r1, r7, #0
	adds r1, #0xb8
	lsrs r0, r0, #0x10
	ldrb r4, [r1]
	adds r2, r0, r4
	b _080E3C54
	.align 2, 0
_080E3C40: .4byte sUpdates
_080E3C44: .4byte gSineTable
_080E3C48: .4byte 0x000FFFFF
_080E3C4C:
	adds r1, r7, #0
	adds r1, #0xb8
	ldrb r0, [r1]
	adds r2, r0, #1
_080E3C54:
	movs r3, #0xff
	ands r2, r3
	strb r2, [r1]
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0
	bne _080E3C6A
	movs r1, #1
_080E3C6A:
	ldr r6, _080E3D14 @ =gSineTable
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r6
	movs r4, #0
	ldrsh r0, [r0, r4]
	mov r4, r8
	muls r4, r0, r4
	adds r0, r4, #0
	asrs r0, r0, #8
	muls r1, r0, r1
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r3
	movs r1, #0x10
	cmp r0, #0x7f
	ble _080E3C94
	movs r1, #0x11
_080E3C94:
	adds r0, r7, #0
	adds r0, #0x25
	strb r1, [r0]
	adds r5, r7, #0
	adds r5, #0xbb
	ldrb r0, [r5]
	adds r4, r0, #1
	adds r0, r4, #0
	movs r1, #0x1c
	bl __modsi3
	adds r4, r0, #0
	strb r4, [r5]
	lsls r0, r4, #8
	movs r1, #0x1c
	bl __divsi3
	adds r4, r0, #0
	movs r2, #0xa0
	lsls r2, r2, #4
	ldr r0, _080E3D18 @ =0x000012FF
	cmp r8, r0
	bgt _080E3CD4
	ldr r0, _080E3D1C @ =0xFFFFF400
	add r0, r8
	muls r2, r0, r2
	movs r1, #0xe0
	lsls r1, r1, #3
	adds r0, r2, #0
	bl __divsi3
	adds r2, r0, #0
_080E3CD4:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	asrs r2, r0, #8
	ldr r0, [r7, #0x58]
	subs r0, r0, r2
	str r0, [r7, #0x58]
	adds r4, r7, #0
	adds r4, #0xb9
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E3D08
	adds r0, r7, #0
	adds r0, #0x54
	movs r1, #0
	bl FUN_080bfc94
	movs r0, #0x20
	strb r0, [r4]
_080E3D08:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E3D14: .4byte gSineTable
_080E3D18: .4byte 0x000012FF
_080E3D1C: .4byte 0xFFFFF400
