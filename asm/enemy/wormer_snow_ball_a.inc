	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807b0d0
FUN_0807b0d0: @ 0x0807B0D0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _0807B11C @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _0807B116
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0807B120 @ =gEnemyFnTable
	movs r0, #0x1d
	strb r0, [r4, #9]
	ldr r0, [r1, #0x74]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	strb r2, [r4, #0x10]
	str r5, [r4, #0x54]
	str r6, [r4, #0x58]
_0807B116:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807B11C: .4byte gEnemyHeaderPtr
_0807B120: .4byte gEnemyFnTable
