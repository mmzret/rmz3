	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807cba4
FUN_0807cba4: @ 0x0807CBA4
	push {lr}
	ldr r2, [r0, #0x2c]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0807CBCC
	ldr r0, _0807CBD0 @ =gCollisionManager
	ldrb r1, [r0, #1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0807CBCC
	adds r1, r2, #0
	adds r1, #0xc0
	movs r0, #0
	strb r0, [r1]
_0807CBCC:
	pop {r0}
	bx r0
	.align 2, 0
_0807CBD0: .4byte gCollisionManager

	thumb_func_start dragInSea
dragInSea: @ 0x0807CBD4
	push {lr}
	adds r3, r0, #0
	ldr r1, _0807CBEC @ =gOverworld
	ldr r2, _0807CBF0 @ =0x0002C00C
	adds r1, r1, r2
	ldr r2, [r1]
	ldr r1, [r3, #0x58]
	cmp r2, r1
	ble _0807CBE8
	str r2, [r3, #0x58]
_0807CBE8:
	pop {r1}
	bx r1
	.align 2, 0
_0807CBEC: .4byte gOverworld
_0807CBF0: .4byte 0x0002C00C

