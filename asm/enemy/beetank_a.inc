	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Beetank_Init
Beetank_Init: @ 0x0807B8BC
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r2, #0
	movs r1, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	ldr r4, _0807B924 @ =0xFFFFF400
	adds r1, r1, r4
	bl PushoutToLeft1
	adds r5, r0, #0
	str r5, [sp]
	ldr r0, [r6, #0x54]
	ldr r2, _0807B928 @ =0xFFFFF000
	adds r0, r0, r2
	ldr r1, [r6, #0x58]
	adds r1, r1, r4
	bl PushoutToRight1
	str r0, [sp, #4]
	cmp r5, #0
	beq _0807B92C
	cmp r0, #0
	bne _0807B938
	ldr r0, [r6, #0x54]
	ldr r1, [sp]
	adds r0, r0, r1
	b _0807B936
	.align 2, 0
_0807B924: .4byte 0xFFFFF400
_0807B928: .4byte 0xFFFFF000
_0807B92C:
	cmp r0, #0
	beq _0807B938
	ldr r0, [r6, #0x54]
	ldr r2, [sp, #4]
	adds r0, r0, r2
_0807B936:
	str r0, [r6, #0x54]
_0807B938:
	ldr r0, [r6, #0x54]
	ldr r1, _0807B968 @ =0xFFFFF000
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	ldr r4, _0807B96C @ =0xFFFFFA00
	adds r1, r1, r4
	bl FUN_08009f6c
	adds r5, r0, #0
	str r5, [sp]
	ldr r0, [r6, #0x54]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r0, r2
	ldr r1, [r6, #0x58]
	adds r1, r1, r4
	bl FUN_08009f6c
	str r0, [sp, #4]
	ldr r1, [sp]
	cmp r1, r0
	bge _0807B970
	str r5, [r6, #0x58]
	b _0807B972
	.align 2, 0
_0807B968: .4byte 0xFFFFF000
_0807B96C: .4byte 0xFFFFFA00
_0807B970:
	str r0, [r6, #0x58]
_0807B972:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0807B9E4 @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
	bl InitBody
	str r6, [r4, #0x2c]
	ldr r0, _0807B9E8 @ =nop_0807bea4
	str r0, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0x5c
	str r5, [r0, #4]
	str r5, [r6, #0x5c]
	adds r0, #0x60
	str r5, [r0]
	subs r0, #4
	strb r5, [r0]
	ldr r1, _0807B9EC @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r5, [r6, #0xd]
	strb r5, [r6, #0xe]
	strb r5, [r6, #0xf]
	adds r0, r6, #0
	bl IsFrozen
	cmp r0, #0
	beq _0807B9D6
	movs r1, #0xf8
	lsls r1, r1, #6
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateEntityAnim
_0807B9D6:
	adds r0, r6, #0
	bl Beetank_Update
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807B9E4: .4byte sCollisions
_0807B9E8: .4byte nop_0807bea4
_0807B9EC: .4byte gEnemyFnTable

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

	thumb_func_start Beetank_Die
Beetank_Die: @ 0x0807BAE8
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _0807BB1C @ =gStageRun
	ldr r0, [r0, #0x30]
	cmp r0, #0
	beq _0807BB28
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #5
	adds r1, r5, #0
	bl TryDropItem
	movs r0, #0
	bl PlaySound
	ldr r2, _0807BB20 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _0807BB24 @ =0x0000270E
	cmp r1, r0
	bhi _0807BB16
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0807BB16:
	adds r0, r4, #0
	adds r1, r5, #0
	b _0807BC5A
	.align 2, 0
_0807BB1C: .4byte gStageRun
_0807BB20: .4byte gScore
_0807BB24: .4byte 0x0000270E
_0807BB28:
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _0807BB30
	b _0807BC78
_0807BB30:
	lsls r0, r0, #2
	ldr r1, _0807BB3C @ =_0807BB40
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807BB3C: .4byte _0807BB40
_0807BB40: @ jump table
	.4byte _0807BB54 @ case 0
	.4byte _0807BBAA @ case 1
	.4byte _0807BBE4 @ case 2
	.4byte _0807BBF4 @ case 3
	.4byte _0807BC30 @ case 4
_0807BB54:
	ldr r1, _0807BBCC @ =0x00003E02
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r2, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x5c
	str r1, [r0, #4]
	str r1, [r4, #0x5c]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0807BBD0 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r0, #1
	ands r1, r0
	mov r0, sp
	bl createGhost44
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #5
	bl TryDropItem
	movs r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807BBAA:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	movs r1, #0xff
	ands r0, r1
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0807BBD4
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0807BBDA
	.align 2, 0
_0807BBCC: .4byte 0x00003E02
_0807BBD0: .4byte 0xFFFFF800
_0807BBD4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0807BBDA:
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0807BC78
	b _0807BC28
_0807BBE4:
	adds r0, r4, #0
	bl PaintEntityWhite
	movs r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807BBF4:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	movs r1, #0xff
	ands r0, r1
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0807BC0E
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0807BC14
_0807BC0E:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0807BC14:
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0807BC78
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x3c
	strb r0, [r4, #0x12]
_0807BC28:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0807BC78
_0807BC30:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0807BC40
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807BC78
_0807BC40:
	movs r0, #0
	bl PlaySound
	ldr r2, _0807BC80 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _0807BC84 @ =0x0000270E
	cmp r1, r0
	bhi _0807BC54
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0807BC54:
	adds r1, r4, #0
	adds r1, #0x54
	adds r0, r4, #0
_0807BC5A:
	bl TryDropZakoDisk
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0807BC88 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_0807BC78:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807BC80: .4byte gScore
_0807BC84: .4byte 0x0000270E
_0807BC88: .4byte gEnemyFnTable
