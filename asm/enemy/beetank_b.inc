	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Beetank_Update
Beetank_Update: @ 0x0807B9F0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0807BA24
	ldr r1, _0807BA20 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl Beetank_Die
	b _0807BADA
	.align 2, 0
_0807BA20: .4byte gEnemyFnTable
_0807BA24:
	ldr r1, _0807BAA4 @ =sUpdates1
	ldrb r0, [r5, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_0807be50
	ldr r0, [r5, #0x54]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _0807BAA8 @ =0xFFFFFC00
	adds r1, r1, r2
	bl PushoutToLeft1
	adds r6, r0, #0
	cmp r0, #0
	beq _0807BA58
	ldr r0, [r5, #0x54]
	adds r0, r0, r6
	str r0, [r5, #0x54]
_0807BA58:
	ldr r0, [r5, #0x54]
	ldr r1, _0807BAA8 @ =0xFFFFFC00
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _0807BAA8 @ =0xFFFFFC00
	adds r1, r1, r2
	bl PushoutToRight1
	adds r6, r0, #0
	cmp r0, #0
	beq _0807BA74
	ldr r0, [r5, #0x54]
	adds r0, r0, r6
	str r0, [r5, #0x54]
_0807BA74:
	ldr r0, [r5, #0x54]
	ldr r1, _0807BAAC @ =0xFFFFF000
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _0807BAB0 @ =0xFFFFFA00
	mov r8, r2
	add r1, r8
	bl FUN_08009f6c
	adds r4, r0, #0
	adds r6, r4, #0
	ldr r0, [r5, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	add r1, r8
	bl FUN_08009f6c
	adds r7, r0, #0
	cmp r6, r7
	bge _0807BAB4
	str r4, [r5, #0x58]
	b _0807BAB6
	.align 2, 0
_0807BAA4: .4byte sUpdates1
_0807BAA8: .4byte 0xFFFFFC00
_0807BAAC: .4byte 0xFFFFF000
_0807BAB0: .4byte 0xFFFFFA00
_0807BAB4:
	str r0, [r5, #0x58]
_0807BAB6:
	adds r0, r5, #0
	bl IsFrozen
	cmp r0, #0
	beq _0807BACA
	ldrb r1, [r5, #0xd]
	adds r0, r5, #0
	adds r0, #0xba
	strb r1, [r0]
	b _0807BADA
_0807BACA:
	ldr r0, _0807BAE4 @ =sUpdates2
	ldrb r1, [r5, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
_0807BADA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807BAE4: .4byte sUpdates2

