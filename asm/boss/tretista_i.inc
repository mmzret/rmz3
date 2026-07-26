	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start tretistaBreathGas
tretistaBreathGas: @ 0x0804F5C4
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #7
	bls _0804F5D2
	b _0804F7CE
_0804F5D2:
	lsls r0, r0, #2
	ldr r1, _0804F5DC @ =_0804F5E0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804F5DC: .4byte _0804F5E0
_0804F5E0: @ jump table
	.4byte _0804F600 @ case 0
	.4byte _0804F626 @ case 1
	.4byte _0804F658 @ case 2
	.4byte _0804F682 @ case 3
	.4byte _0804F744 @ case 4
	.4byte _0804F762 @ case 5
	.4byte _0804F77A @ case 6
	.4byte _0804F7A4 @ case 7
_0804F600:
	movs r1, #0xb8
	lsls r1, r1, #2
	movs r0, #0x4c
	bl StartPaletteAnimation
	ldr r1, _0804F650 @ =0x0000AB1C
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804F654 @ =sCollisions+(24*1)
	bl SetDDP
	movs r0, #0xa
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F626:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804F638
	b _0804F7CE
_0804F638:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0804F640
	b _0804F794
_0804F640:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804F64C
	b _0804F7CE
_0804F64C:
	b _0804F794
	.align 2, 0
_0804F650: .4byte 0x0000AB1C
_0804F654: .4byte sCollisions+(24*1)
_0804F658:
	ldr r1, _0804F730 @ =0x0000AB1E
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804F734 @ =0x08363458
	bl SetDDP
	movs r0, #0xd9
	bl PlaySound
	movs r1, #0
	movs r0, #2
	strb r0, [r5, #0x12]
	movs r0, #3
	strb r0, [r5, #0x13]
	strb r1, [r5, #0xf]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F682:
	movs r0, #0x4c
	bl StepPaletteAnimation
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0xf]
	adds r0, #1
	strb r0, [r5, #0xf]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804F6E2
	ldrb r0, [r5, #0xf]
	subs r0, #1
	movs r1, #0x50
	bl __modsi3
	cmp r0, #0
	bne _0804F6E2
	ldr r0, [r5, #0x54]
	ldr r1, _0804F738 @ =0xFFFFD000
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _0804F73C @ =0xFFFFC000
	adds r0, r0, r1
	str r0, [sp, #4]
	adds r0, r5, #0
	mov r1, sp
	movs r2, #0
	bl createTretistaBreathGas
	ldr r0, [r5, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	str r0, [sp]
	adds r0, r5, #0
	mov r1, sp
	movs r2, #1
	bl createTretistaBreathGas
	movs r0, #0xda
	bl PlaySound
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
_0804F6E2:
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _0804F724
	ldrb r0, [r5, #0xf]
	subs r0, #1
	movs r1, #0x3c
	bl __modsi3
	cmp r0, #0
	bne _0804F724
	ldr r0, [r5, #0x54]
	str r0, [sp, #8]
	ldr r0, [r5, #0x58]
	ldr r1, _0804F740 @ =0xFFFFD600
	adds r0, r0, r1
	add r4, sp, #8
	str r0, [r4, #4]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #2
	bl createTretistaBreathGas
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #3
	bl createTretistaBreathGas
	movs r0, #0xda
	bl PlaySound
	ldrb r0, [r5, #0x13]
	subs r0, #1
	strb r0, [r5, #0x13]
_0804F724:
	ldrh r0, [r5, #0x12]
	cmp r0, #0
	bne _0804F7CE
	movs r0, #0x14
	b _0804F792
	.align 2, 0
_0804F730: .4byte 0x0000AB1E
_0804F734: .4byte 0x08363458
_0804F738: .4byte 0xFFFFD000
_0804F73C: .4byte 0xFFFFC000
_0804F740: .4byte 0xFFFFD600
_0804F744:
	movs r0, #0x4c
	bl StepPaletteAnimation
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804F794
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804F7CE
	b _0804F794
_0804F762:
	ldr r1, _0804F79C @ =0x0000AB1F
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804F7A0 @ =sCollisions+(24*1)
	bl SetDDP
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F77A:
	movs r0, #0x4c
	bl StepPaletteAnimation
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804F7CE
	movs r0, #0x32
_0804F792:
	strb r0, [r5, #0x12]
_0804F794:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0804F7CE
	.align 2, 0
_0804F79C: .4byte 0x0000AB1F
_0804F7A0: .4byte sCollisions+(24*1)
_0804F7A4:
	movs r0, #0x4c
	bl StepPaletteAnimation
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804F7C0
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804F7CE
_0804F7C0:
	movs r0, #0x4c
	bl RemovePaletteAnimation
	movs r1, #0
	movs r0, #3
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0804F7CE:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
