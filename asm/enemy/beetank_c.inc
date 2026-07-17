	.include "asm/macros.inc"

	.syntax unified
	
	.text

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

