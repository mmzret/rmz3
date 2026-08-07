	.include "asm/macros.inc"

	.syntax unified

	.text

	push {r4, r5, lr}
	adds r4, r1, #0
	cmp r2, #1
	bne _08045958
	bl FUN_080459d4
	adds r1, r0, #0
	cmp r1, #0
	beq _0804593C
	movs r2, #0
	ldr r5, _08045938 @ =0x080FEE90
	adds r3, r5, #0
_08045928:
	ldrh r1, [r3]
	cmp r1, r4
	beq _0804597C
	adds r3, #2
	adds r2, #1
	cmp r2, #2
	ble _08045928
	b _080459CC
	.align 2, 0
_08045938: .4byte 0x080FEE90
_0804593C:
	movs r2, #0
	ldr r5, _08045954 @ =0x080FEE86
	adds r3, r5, #0
_08045942:
	ldrh r1, [r3]
	cmp r1, r4
	beq _08045986
	adds r3, #2
	adds r2, #1
	cmp r2, #4
	ble _08045942
	b _080459CC
	.align 2, 0
_08045954: .4byte 0x080FEE86
_08045958:
	bl FUN_080459d4
	adds r1, r0, #0
	cmp r1, #0
	beq _0804599A
	movs r2, #0
	ldr r5, _08045978 @ =0x080FEE90
	adds r3, r5, #0
_08045968:
	ldrh r1, [r3]
	cmp r1, r4
	beq _08045990
	adds r3, #2
	adds r2, #1
	cmp r2, #2
	ble _08045968
	b _080459CC
	.align 2, 0
_08045978: .4byte 0x080FEE90
_0804597C:
	adds r0, r2, #1
	movs r1, #3
	bl __modsi3
	b _080459B6
_08045986:
	adds r0, r2, #1
	movs r1, #5
	bl __modsi3
	b _080459B6
_08045990:
	adds r0, r2, #1
	movs r1, #3
	bl __modsi3
	b _080459B6
_0804599A:
	movs r2, #0
	ldr r5, _080459C0 @ =0x080FEE86
	adds r3, r5, #0
_080459A0:
	ldrh r1, [r3]
	cmp r1, r4
	bne _080459C4
	adds r1, r2, #1
	adds r0, r1, #0
	cmp r1, #0
	bge _080459B0
	adds r0, r2, #4
_080459B0:
	asrs r0, r0, #2
	lsls r0, r0, #2
	subs r0, r1, r0
_080459B6:
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	b _080459CC
	.align 2, 0
_080459C0: .4byte 0x080FEE86
_080459C4:
	adds r3, #2
	adds r2, #1
	cmp r2, #3
	ble _080459A0
_080459CC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
