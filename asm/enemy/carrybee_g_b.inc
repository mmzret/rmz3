	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0808af7c
FUN_0808af7c: @ 0x0808AF7C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, _0808AF9C @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r2, _0808AFA0 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r1]
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0808AFA4
	cmp r5, #1
	beq _0808AFD4
	b _0808AFF8
	.align 2, 0
_0808AF9C: .4byte gStageRun+232
_0808AFA0: .4byte 0xFFFFC000
_0808AFA4:
	adds r0, r4, #0
	adds r0, #0xb8
	str r5, [r0]
	ldr r0, _0808B000 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	str r0, [r4, #0x64]
	movs r0, #0x8c
	lsls r0, r0, #7
	str r0, [r4, #0x5c]
	movs r1, #0xdc
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808B004 @ =0x08368C6C
	bl SetDDP
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808AFD4:
	ldr r0, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r0, r2
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r1, r0
	ble _0808AFF2
	str r1, [r4, #0x68]
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808AFF2:
	adds r0, r4, #0
	bl UpdateEntityAnim
_0808AFF8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808B000: .4byte pZero2
_0808B004: .4byte 0x08368C6C
