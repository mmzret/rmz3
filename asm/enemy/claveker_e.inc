	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0808f000
FUN_0808f000: @ 0x0808F000
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xb
	bls _0808F00E
	b _0808F14E
_0808F00E:
	lsls r0, r0, #2
	ldr r1, _0808F018 @ =_0808F01C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808F018: .4byte _0808F01C
_0808F01C: @ jump table
	.4byte _0808F04C @ case 0
	.4byte _0808F12C @ case 1
	.4byte _0808F05A @ case 2
	.4byte _0808F068 @ case 3
	.4byte _0808F080 @ case 4
	.4byte _0808F092 @ case 5
	.4byte _0808F0C4 @ case 6
	.4byte _0808F0F4 @ case 7
	.4byte _0808F102 @ case 8
	.4byte _0808F118 @ case 9
	.4byte _0808F12C @ case 10
	.4byte _0808F146 @ case 11
_0808F04C:
	movs r1, #0xea
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x14
	b _0808F124
_0808F05A:
	ldr r1, _0808F07C @ =0x00007502
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F068:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808F14E
	b _0808F13E
	.align 2, 0
_0808F07C: .4byte 0x00007502
_0808F080:
	movs r1, #0
	movs r0, #8
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xb9
	strb r1, [r0]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F092:
	ldr r1, _0808F0EC @ =0x00007503
	adds r0, r4, #0
	bl SetMotion
	movs r0, #6
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	movs r1, #0xd0
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r1, sp
	mov r2, sp
	movs r3, #0
	bl FUN_080aed8c
	ldr r0, _0808F0F0 @ =0x00000145
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F0C4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	movs r1, #0xff
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808F14E
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	ands r0, r1
	cmp r0, #0
	beq _0808F13E
	movs r0, #5
	strb r0, [r4, #0xe]
	b _0808F14E
	.align 2, 0
_0808F0EC: .4byte 0x00007503
_0808F0F0: .4byte 0x00000145
_0808F0F4:
	ldr r1, _0808F114 @ =0x00007504
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F102:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808F14E
	b _0808F13E
	.align 2, 0
_0808F114: .4byte 0x00007504
_0808F118:
	movs r1, #0xea
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x20
_0808F124:
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F12C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808F14E
_0808F13E:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0808F14E
_0808F146:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808F14E:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

