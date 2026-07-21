	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start createPantheonZombie
createPantheonZombie: @ 0x0807FD20
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	ldr r0, _0807FD7C @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r4, r0, #0
	cmp r4, #0
	beq _0807FD76
	adds r1, r5, #0
	adds r1, #0xcb
	ldrb r0, [r1]
	adds r0, #1
	movs r3, #0
	strb r0, [r1]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0807FD80 @ =gEnemyFnTable
	movs r1, #0x25
	strb r1, [r4, #9]
	adds r0, #0x94
	ldr r0, [r0]
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
	str r5, [r4, #0x28]
	str r6, [r4, #0x54]
	str r7, [r4, #0x58]
_0807FD76:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807FD7C: .4byte gEnemyHeaderPtr
_0807FD80: .4byte gEnemyFnTable

