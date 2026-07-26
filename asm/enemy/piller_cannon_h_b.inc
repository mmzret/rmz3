	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start PillerCannon_OnCollision
PillerCannon_OnCollision: @ 0x08068F68
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0xc]
	ldr r3, [r0, #4]
	ldr r2, [r4, #0x2c]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2, #0x5c]
	str r1, [r2, #0x60]
	ldr r0, [r3, #4]
	ldr r1, _08068FAC @ =0x000200FF
	ands r0, r1
	subs r1, #0xfd
	cmp r0, r1
	bne _08068FA4
	ldr r2, [r4, #0x2c]
	adds r0, r2, #0
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #0
	beq _08068FA4
	ldr r1, _08068FB0 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
_08068FA4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08068FAC: .4byte 0x000200FF
_08068FB0: .4byte gEnemyFnTable
