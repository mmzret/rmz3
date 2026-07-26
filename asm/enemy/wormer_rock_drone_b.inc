	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080770ac
FUN_080770ac: @ 0x080770AC
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r2, _08077108 @ =0x08367252
	adds r0, r4, #0
	mov r1, sp
	movs r3, #2
	bl FUN_080b7f70
	movs r0, #0x91
	lsls r0, r0, #1
	bl PlaySound
	ldr r1, _0807710C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08077108: .4byte 0x08367252
_0807710C: .4byte gEnemyFnTable
