	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08078108
FUN_08078108: @ 0x08078108
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08078168 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r4, r0, #0
	cmp r4, #0
	beq _08078160
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0807816C @ =gEnemyFnTable
	movs r0, #0x19
	strb r0, [r4, #9]
	ldr r0, [r1, #0x64]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r2, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r4, #0xb]
	movs r2, #0x10
	orrs r1, r2
	orrs r1, r3
	strb r1, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	movs r0, #2
	strb r0, [r4, #0x10]
	ldr r0, [r5, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r4, #0x58]
	str r5, [r4, #0x28]
	orrs r1, r2
	strb r1, [r4, #0xb]
	ldrb r0, [r5, #0x1c]
	strb r0, [r4, #0x1d]
_08078160:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08078168: .4byte gEnemyHeaderPtr
_0807816C: .4byte gEnemyFnTable
