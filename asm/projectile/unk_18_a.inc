	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a2ea0
FUN_080a2ea0: @ 0x080A2EA0
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r6, _080A2EE0 @ =gProjectileFnTable
	movs r4, #4
_080A2EA8:
	ldr r0, _080A2EE4 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r1, r0, #0
	cmp r1, #0
	beq _080A2ED4
	adds r2, r1, #0
	adds r2, #0x25
	movs r0, #8
	strb r0, [r2]
	movs r0, #0x12
	strb r0, [r1, #9]
	ldr r0, [r6, #0x48]
	ldr r0, [r0]
	str r0, [r1, #0x14]
	strh r5, [r1, #0x20]
	adds r0, r1, #0
	adds r0, #0x22
	strb r5, [r0]
	movs r0, #2
	strb r0, [r1, #0x10]
_080A2ED4:
	subs r4, #1
	cmp r4, #0
	bge _080A2EA8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A2EE0: .4byte gProjectileFnTable
_080A2EE4: .4byte gProjectileHeaderPtr

