	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08086ff0
FUN_08086ff0: @ 0x08086FF0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r2, r0, #0
	ldr r0, [r2, #0xc]
	ldr r0, [r0, #0x2c]
	ldr r1, [r2, #0x2c]
	mov r8, r1
	ldrh r1, [r0, #8]
	ldr r0, _080870A0 @ =0x00002E03
	cmp r1, r0
	beq _08087094
	mov r1, r8
	ldrb r0, [r1, #0x10]
	cmp r0, #0
	bne _08087094
	ldr r0, [r2, #0x14]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08087094
	mov r4, r8
	adds r4, #0xb8
	ldrb r0, [r4]
	mov sb, r0
	cmp r0, #0
	bne _08087094
	ldr r7, _080870A4 @ =gStageRun+232
	mov r1, r8
	adds r1, #0x54
	adds r0, r7, #0
	bl Camera_GetDistance
	ldr r1, _080870A8 @ =0x000007FF
	cmp r0, r1
	bhi _08087094
	movs r0, #0xff
	strb r0, [r4]
	ldr r0, [r7, #0x38]
	ldr r6, _080870AC @ =0x00008BFF
	adds r0, r0, r6
	ldr r1, [r7, #0x3c]
	ldr r4, _080870B0 @ =0xFFFF9C00
	adds r1, r1, r4
	movs r2, #0
	bl CreateGallisni
	ldr r0, [r7, #0x38]
	ldr r5, _080870B4 @ =0xFFFF7400
	adds r0, r0, r5
	ldr r1, [r7, #0x3c]
	adds r1, r1, r4
	movs r2, #1
	bl CreateGallisni
	ldr r0, [r7, #0x38]
	adds r0, r0, r6
	ldr r1, [r7, #0x3c]
	ldr r4, _080870B8 @ =0x000063FF
	adds r1, r1, r4
	movs r2, #2
	bl CreateGallisni
	ldr r0, [r7, #0x38]
	adds r0, r0, r5
	ldr r1, [r7, #0x3c]
	adds r1, r1, r4
	movs r2, #3
	bl CreateGallisni
	movs r0, #0xa3
	lsls r0, r0, #1
	bl PlaySound
	movs r0, #2
	mov r1, r8
	strb r0, [r1, #0xd]
	mov r0, sb
	strb r0, [r1, #0xe]
	movs r0, #0x40
	strb r0, [r1, #0x12]
_08087094:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080870A0: .4byte 0x00002E03
_080870A4: .4byte gStageRun+232
_080870A8: .4byte 0x000007FF
_080870AC: .4byte 0x00008BFF
_080870B0: .4byte 0xFFFF9C00
_080870B4: .4byte 0xFFFF7400
_080870B8: .4byte 0x000063FF
