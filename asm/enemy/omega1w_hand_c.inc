	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0806ae94
FUN_0806ae94: @ 0x0806AE94
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0806AEA4
	cmp r0, #1
	beq _0806AEC6
	b _0806AED4
_0806AEA4:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x58]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806AEC6:
	adds r0, r4, #0
	bl UpdateEntityAnim
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806AED4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0806aedc
FUN_0806aedc: @ 0x0806AEDC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0806AEEC
	cmp r0, #1
	beq _0806AF0C
	b _0806AF1A
_0806AEEC:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x58]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r1, _0806AF20 @ =0x00000901
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806AF0C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806AF1A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806AF20: .4byte 0x00000901

	thumb_func_start FUN_0806af24
FUN_0806af24: @ 0x0806AF24
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #5
	bne _0806AF38
	movs r1, #0
	movs r0, #4
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0806AF38:
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0806af40
FUN_0806af40: @ 0x0806AF40
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0806AF50
	cmp r5, #1
	beq _0806AF9A
	b _0806AFCE
_0806AF50:
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0x1c]
	strb r0, [r4, #0x1d]
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806AFD4 @ =sCollisions
	bl SetDDP
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806AF9A:
	ldrb r0, [r4, #0x12]
	adds r0, #2
	strb r0, [r4, #0x12]
	ldr r1, _0806AFD8 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r3, [r0, r1]
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r2, [r4, #0x28]
	ldr r0, [r0]
	ldr r1, [r2, #0x58]
	adds r0, r0, r1
	adds r0, r0, r3
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r2, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateEntityAnim
_0806AFCE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806AFD4: .4byte sCollisions
_0806AFD8: .4byte gSineTable

	thumb_func_start FUN_0806afdc
FUN_0806afdc: @ 0x0806AFDC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0806AFEC
	cmp r5, #1
	beq _0806B04C
	b _0806B082
_0806AFEC:
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0x1c]
	strb r0, [r4, #0x1d]
	ldr r1, _0806B088 @ =0x00000901
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4d
	strb r5, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806B08C @ =0x08366478
	bl SetDDP
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806B04C:
	ldrb r0, [r4, #0x12]
	adds r0, #2
	strb r0, [r4, #0x12]
	ldr r1, _0806B090 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r2, [r0, r1]
	lsls r2, r2, #1
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r3, [r4, #0x28]
	ldr r0, [r0]
	ldr r1, [r3, #0x58]
	adds r0, r0, r1
	adds r0, r0, r2
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r3, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateEntityAnim
_0806B082:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806B088: .4byte 0x00000901
_0806B08C: .4byte sCollisions+(24*3)
_0806B090: .4byte gSineTable
