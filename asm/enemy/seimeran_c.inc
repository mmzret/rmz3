	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0808f934
FUN_0808f934: @ 0x0808F934
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _0808F96A
	cmp r0, #1
	bgt _0808F948
	cmp r0, #0
	beq _0808F952
	b _0808FA16
_0808F948:
	cmp r0, #2
	beq _0808F98C
	cmp r0, #3
	beq _0808F9FE
	b _0808FA16
_0808F952:
	ldr r0, _0808F984 @ =0x00000103
	bl PlaySound
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldr r1, _0808F988 @ =0x00007702
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808F96A:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808FA16
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0808FA16
	.align 2, 0
_0808F984: .4byte 0x00000103
_0808F988: .4byte 0x00007702
_0808F98C:
	adds r6, r5, #0
	adds r6, #0xb8
	ldr r0, [r6]
	cmp r0, #0
	bne _0808F9D0
	adds r7, r5, #0
	adds r7, #0xbc
	ldr r0, [r7]
	cmp r0, #0
	bne _0808F9D0
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _0808F9D0
	ldr r1, [r5, #0x54]
	ldr r2, [r5, #0x58]
	ldr r4, _0808F9CC @ =0xFFFFE400
	adds r2, r2, r4
	adds r0, r5, #0
	movs r3, #0
	bl CreateClone
	str r0, [r6]
	ldr r1, [r5, #0x54]
	ldr r2, [r5, #0x58]
	adds r2, r2, r4
	adds r0, r5, #0
	movs r3, #1
	bl CreateClone
	str r0, [r7]
	b _0808F9F0
	.align 2, 0
_0808F9CC: .4byte 0xFFFFE400
_0808F9D0:
	movs r0, #0x2d
	bl PlaySound
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r4, _0808FA1C @ =0xFFFFE400
	adds r1, r1, r4
	movs r2, #0
	bl FUN_0808f2e4
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	adds r1, r1, r4
	movs r2, #1
	bl FUN_0808f2e4
_0808F9F0:
	ldr r1, _0808FA20 @ =0x00007703
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808F9FE:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808FA16
	movs r1, #0
	movs r0, #4
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0808FA16:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808FA1C: .4byte 0xFFFFE400
_0808FA20: .4byte 0x00007703

