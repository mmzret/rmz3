	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807cd74
FUN_0807cd74: @ 0x0807CD74
	push {lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0807CDBE
	ldr r1, _0807CDB4 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldrb r0, [r2, #0x10]
	cmp r0, #1
	bhi _0807CDB8
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r1, r0
	cmp r1, #0
	beq _0807CDB8
	movs r0, #1
	strb r0, [r2, #0xd]
	b _0807CDBA
	.align 2, 0
_0807CDB4: .4byte gEnemyFnTable
_0807CDB8:
	strb r1, [r2, #0xd]
_0807CDBA:
	movs r0, #1
	b _0807CDC0
_0807CDBE:
	movs r0, #0
_0807CDC0:
	pop {r1}
	bx r1
