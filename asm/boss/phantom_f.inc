	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0805f870
FUN_0805f870: @ 0x0805F870
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0805F89C @ =gStageRun+232
	ldr r0, [r5, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #7
	adds r0, r0, r2
	ldr r1, [r1, #0x3c]
	subs r1, r1, r0
	ldr r0, _0805F8A0 @ =0xFFFFD000
	cmp r1, r0
	bge _0805F8A4
	movs r4, #0
	movs r0, #3
	strb r0, [r5, #0xf]
	adds r0, r5, #0
	movs r1, #0xa
	bl FUN_080607a0
	strb r4, [r5, #0x12]
	b _0805F8B8
	.align 2, 0
_0805F89C: .4byte gStageRun+232
_0805F8A0: .4byte 0xFFFFD000
_0805F8A4:
	ldr r0, _0805F8C0 @ =0xFFFFE000
	cmp r1, r0
	ble _0805F8B8
	movs r0, #5
	strh r0, [r5, #0xe]
	movs r0, #0
	str r0, [r5, #0x2c]
	adds r0, r5, #0
	bl FUN_0805f934
_0805F8B8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805F8C0: .4byte 0xFFFFE000

	thumb_func_start FUN_0805f8c4
FUN_0805f8c4: @ 0x0805F8C4
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bne _0805F91A
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	str r0, [sp, #4]
	movs r0, #0xfc
	bl PlaySound
	movs r4, #0xf0
	lsls r4, r4, #2
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0x10
	movs r3, #1
	bl FUN_080afbfc
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0x30
	movs r3, #1
	bl FUN_080afbfc
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0x50
	movs r3, #1
	bl FUN_080afbfc
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0x70
	movs r3, #1
	bl FUN_080afbfc
_0805F91A:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805F928
	movs r0, #2
	strb r0, [r5, #0xf]
_0805F928:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
