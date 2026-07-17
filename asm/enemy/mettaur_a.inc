	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08088bc8
FUN_08088bc8: @ 0x08088BC8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	cmp r2, #0
	beq _08088C06
	ldr r0, [r4, #0x58]
	adds r1, r0, r2
	str r1, [r4, #0x58]
	cmp r2, #0
	bge _08088BF4
	ldr r0, [r4, #0x54]
	ldr r2, _08088BF0 @ =0xFFFFF000
	adds r1, r1, r2
	bl PushoutToDown1
	adds r2, r0, #0
	cmp r2, #0
	ble _08088C06
	b _08088C00
	.align 2, 0
_08088BF0: .4byte 0xFFFFF000
_08088BF4:
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	bge _08088C06
_08088C00:
	ldr r1, [r4, #0x58]
	adds r1, r1, r2
	str r1, [r4, #0x58]
_08088C06:
	cmp r5, #0
	beq _08088C42
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	str r0, [r4, #0x54]
	cmp r5, #0
	bge _08088C2C
	ldr r1, [r4, #0x58]
	ldr r2, _08088C28 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToRight1
	adds r2, r0, #0
	cmp r2, #0
	ble _08088C42
	b _08088C3C
	.align 2, 0
_08088C28: .4byte 0xFFFFF800
_08088C2C:
	ldr r1, [r4, #0x58]
	ldr r2, _08088C48 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToLeft1
	adds r2, r0, #0
	cmp r2, #0
	bge _08088C42
_08088C3C:
	ldr r1, [r4, #0x54]
	adds r1, r1, r2
	str r1, [r4, #0x54]
_08088C42:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08088C48: .4byte 0xFFFFF800

	thumb_func_start FUN_08088c4c
FUN_08088c4c: @ 0x08088C4C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	movs r7, #0
	adds r6, r4, #0
	adds r6, #0xc2
	ldrb r0, [r6]
	cmp r0, #0
	bne _08088CBC
	cmp r1, #0
	beq _08088C8C
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	ble _08088C7A
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	bge _08088C8C
	b _08088C86
_08088C7A:
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	ble _08088C8C
_08088C86:
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_08088C8C:
	cmp r5, #0
	beq _08088CD4
	ldr r0, [r4, #0x58]
	adds r1, r0, r5
	str r1, [r4, #0x58]
	cmp r5, #0
	ble _08088CA8
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _08088CD4
	b _08088CB4
_08088CA8:
	ldr r0, [r4, #0x54]
	bl PushoutToDown1
	adds r1, r0, #0
	cmp r1, #0
	ble _08088CD4
_08088CB4:
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	b _08088CD4
_08088CBC:
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	adds r1, r1, r5
	str r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08088CD4
	strb r7, [r6]
_08088CD4:
	ldr r0, _08088CF4 @ =gOverworld
	ldr r1, _08088CF8 @ =0x0002C00C
	adds r0, r0, r1
	ldr r0, [r0]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r0, r2
	ldr r0, [r4, #0x58]
	cmp r0, r1
	bge _08088CEC
	str r1, [r4, #0x58]
	movs r7, #1
_08088CEC:
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08088CF4: .4byte gOverworld
_08088CF8: .4byte 0x0002C00C

	thumb_func_start FUN_08088cfc
FUN_08088cfc: @ 0x08088CFC
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	mov r2, sp
	mov r1, sp
	movs r0, #0
	strb r0, [r1, #1]
	strb r0, [r2]
	ldr r2, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r3, _08088D50 @ =0xFFFFF000
	adds r1, r0, r3
	adds r0, r2, #0
	bl PushoutToDown1
	cmp r0, #0
	ble _08088D24
	mov r1, sp
	movs r0, #1
	strb r0, [r1]
_08088D24:
	ldr r2, [r4, #0x54]
	ldr r0, [r4, #0x58]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r0, r3
	adds r0, r2, #0
	bl PushoutToUp1
	cmp r0, #0
	bge _08088D3E
	mov r1, sp
	movs r0, #1
	strb r0, [r1, #1]
_08088D3E:
	mov r0, sp
	mov r1, sp
	ldrb r0, [r0]
	ldrb r1, [r1, #1]
	ands r0, r1
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08088D50: .4byte 0xFFFFF000

