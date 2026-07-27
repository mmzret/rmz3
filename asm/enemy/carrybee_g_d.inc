	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0808b10c
FUN_0808b10c: @ 0x0808B10C
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, _0808B134 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r2, _0808B138 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r1]
	ldrb r0, [r4, #0xe]
	cmp r0, #6
	bls _0808B128
	b _0808B2A8
_0808B128:
	lsls r0, r0, #2
	ldr r1, _0808B13C @ =_0808B140
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808B134: .4byte gStageRun+232
_0808B138: .4byte 0xFFFFC000
_0808B13C: .4byte _0808B140
_0808B140: @ jump table
	.4byte _0808B15C @ case 0
	.4byte _0808B16A @ case 1
	.4byte _0808B1B4 @ case 2
	.4byte _0808B24C @ case 3
	.4byte _0808B1BA @ case 4
	.4byte _0808B24C @ case 5
	.4byte _0808B2A0 @ case 6
_0808B15C:
	ldr r1, _0808B1AC @ =0x00006E01
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808B16A:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r4, #0x68]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x68]
	ldr r2, _0808B1B0 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r2, #4
	subs r0, r0, r2
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0808B1A8
	b _0808B2A8
_0808B1A8:
	b _0808B28E
	.align 2, 0
_0808B1AC: .4byte 0x00006E01
_0808B1B0: .4byte gSineTable
_0808B1B4:
	movs r0, #0xa
	strb r0, [r4, #0x13]
	b _0808B246
_0808B1BA:
	movs r0, #0xa
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp]
	ldr r1, _0808B1FC @ =0xFFFFF600
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	movs r2, #0xd8
	lsls r2, r2, #5
	adds r0, r0, r2
	str r0, [sp, #4]
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	cmp r0, #0
	bne _0808B200
	mov r0, sp
	movs r1, #2
	movs r2, #0
	bl CreatePantheonHunter
	str r0, [r5]
	adds r0, #0x25
	movs r1, #0x15
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0xc0
	b _0808B23A
	.align 2, 0
_0808B1FC: .4byte 0xFFFFF600
_0808B200:
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	bne _0808B21E
	mov r0, sp
	movs r1, #2
	movs r2, #0
	bl CreatePantheonHunter
	str r0, [r4, #0x2c]
	adds r0, #0x25
	movs r1, #0x15
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0xc1
	b _0808B23A
_0808B21E:
	ldr r0, [r4, #0x28]
	cmp r0, #0
	bne _0808B23E
	mov r0, sp
	movs r1, #2
	movs r2, #0
	bl CreatePantheonHunter
	str r0, [r4, #0x28]
	adds r0, #0x25
	movs r1, #0x15
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0xc2
_0808B23A:
	movs r0, #0x20
	strb r0, [r1]
_0808B23E:
	ldr r1, _0808B298 @ =0x00006E03
	adds r0, r4, #0
	bl SetMotion
_0808B246:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808B24C:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r4, #0x68]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x68]
	ldr r2, _0808B29C @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r2, #4
	subs r0, r0, r2
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _0808B28E
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808B2A8
_0808B28E:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0808B2A8
	.align 2, 0
_0808B298: .4byte 0x00006E03
_0808B29C: .4byte gSineTable
_0808B2A0:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808B2A8:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
