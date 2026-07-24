	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08068f08
FUN_08068f08: @ 0x08068F08
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	cmp r0, #0
	bne _08068F5C
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08068F5C
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	ldr r2, _08068F64 @ =0x083661EC
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r0, [r0]
	cmp r0, #0
	bne _08068F5C
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0x20
	bne _08068F5C
	adds r1, r4, #0
	adds r1, #0xc0
	ldrb r0, [r1]
	cmp r0, #0
	bne _08068F5C
	movs r0, #0x64
	strb r0, [r1]
_08068F5C:
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08068F64: .4byte 0x083661EC

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


