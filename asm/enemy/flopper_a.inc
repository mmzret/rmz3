	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Flopper_Die
Flopper_Die: @ 0x0806BF38
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x54
	movs r0, #4
	adds r1, r6, #0
	bl AppendQuake
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	str r0, [sp, #4]
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r2, [r5]
	ldrb r0, [r5]
	cmp r0, #0
	bne _0806BF74
	movs r1, #0xc0
	lsls r1, r1, #1
	lsrs r2, r2, #3
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r0, sp
	bl CreateProjectile7
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
_0806BF74:
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #4
	cmp r0, r1
	bne _0806BFC4
	ldrb r0, [r4, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r4, #0xa]
	movs r0, #0x35
	bl PlaySound
	movs r0, #0
	adds r1, r6, #0
	bl TryDropItem
	ldr r2, _0806BFCC @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _0806BFD0 @ =0x0000270E
	cmp r1, r0
	bhi _0806BFAA
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0806BFAA:
	adds r0, r4, #0
	adds r1, r6, #0
	bl TryDropZakoDisk
	ldr r1, _0806BFD4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_0806BFC4:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806BFCC: .4byte gScore
_0806BFD0: .4byte 0x0000270E
_0806BFD4: .4byte gEnemyFnTable
