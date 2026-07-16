	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08060e14
FUN_08060e14: @ 0x08060E14
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldrb r1, [r7, #0xe]
	cmp r1, #1
	beq _08060E4A
	cmp r1, #1
	bgt _08060E30
	cmp r1, #0
	beq _08060E38
	b _08060F7C
_08060E30:
	cmp r1, #2
	bne _08060E36
	b _08060F48
_08060E36:
	b _08060F7C
_08060E38:
	strb r1, [r7, #0x13]
	movs r0, #0xb6
	strb r0, [r7, #0x12]
	str r1, [r7, #0x68]
	movs r0, #0xc
	strb r0, [r7, #0xf]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08060E4A:
	movs r0, #0xa7
	bl StepPaletteAnimation
	movs r0, #0xa8
	bl StepPaletteAnimation
	movs r0, #0xa9
	bl StepPaletteAnimation
	movs r0, #0xaa
	bl StepPaletteAnimation
	ldr r0, [r7, #0x68]
	adds r0, #8
	str r0, [r7, #0x68]
	movs r1, #0xa0
	lsls r1, r1, #1
	cmp r0, r1
	ble _08060E72
	str r1, [r7, #0x68]
_08060E72:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x68]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x60]
	ldrb r0, [r7, #0x13]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08060EEC
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r5, [sp, #4]
	movs r0, #0xc8
	lsls r0, r0, #6
	adds r5, r5, r0
	str r5, [sp, #4]
	ldr r4, _08060F3C @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _08060F40 @ =0x000343FD
	mov sb, r1
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r1, _08060F44 @ =0x00269EC3
	mov r8, r1
	add r0, r8
	lsls r0, r0, #1
	lsrs r6, r0, #1
	str r6, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0xaa
	bl __umodsi3
	subs r0, #0x55
	lsls r0, r0, #8
	ldr r1, [sp]
	adds r0, r0, r1
	str r0, [sp]
	mov r0, sb
	muls r0, r6, r0
	add r0, r8
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x96
	bl __umodsi3
	subs r0, #0x5f
	lsls r0, r0, #8
	adds r0, r0, r5
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
_08060EEC:
	ldrb r0, [r7, #0x13]
	ldrb r1, [r7, #0xf]
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08060F1E
	ldr r2, _08060F3C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08060F40 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08060F44 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #6
	bl __umodsi3
	adds r0, #8
	strb r0, [r7, #0xf]
	movs r0, #0x2a
	bl PlaySound
_08060F1E:
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _08060F34
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08060F7C
_08060F34:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _08060F7C
	.align 2, 0
_08060F3C: .4byte RNG_0202f388
_08060F40: .4byte 0x000343FD
_08060F44: .4byte 0x00269EC3
_08060F48:
	movs r0, #0xa7
	bl RemovePaletteAnimation
	movs r0, #0xa8
	bl RemovePaletteAnimation
	movs r0, #0xa9
	bl RemovePaletteAnimation
	movs r0, #0xaa
	bl RemovePaletteAnimation
	ldr r2, _08060F8C @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	movs r3, #0
	orrs r0, r1
	strb r0, [r2, #0x12]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r0, _08060F90 @ =gOverworld
	ldr r1, _08060F94 @ =0x0002D025
	adds r0, r0, r1
	strb r3, [r0]
_08060F7C:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08060F8C: .4byte gStageRun
_08060F90: .4byte gOverworld
_08060F94: .4byte 0x0002D025

