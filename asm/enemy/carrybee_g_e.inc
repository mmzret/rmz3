	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0808b2b4
FUN_0808b2b4: @ 0x0808B2B4
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, _0808B2DC @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r2, _0808B2E0 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r1]
	ldrb r0, [r4, #0xe]
	cmp r0, #6
	bls _0808B2D0
	b _0808B40A
_0808B2D0:
	lsls r0, r0, #2
	ldr r1, _0808B2E4 @ =_0808B2E8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808B2DC: .4byte gStageRun+232
_0808B2E0: .4byte 0xFFFFC000
_0808B2E4: .4byte _0808B2E8
_0808B2E8: @ jump table
	.4byte _0808B304 @ case 0
	.4byte _0808B312 @ case 1
	.4byte _0808B354 @ case 2
	.4byte _0808B390 @ case 3
	.4byte _0808B35A @ case 4
	.4byte _0808B390 @ case 5
	.4byte _0808B3DC @ case 6
_0808B304:
	ldr r1, _0808B34C @ =0x00006E04
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808B312:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r4, #0x68]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x68]
	ldr r2, _0808B350 @ =gSineTable
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
	bne _0808B40A
	b _0808B3CC
	.align 2, 0
_0808B34C: .4byte 0x00006E04
_0808B350: .4byte gSineTable
_0808B354:
	movs r0, #0xa
	strb r0, [r4, #0x13]
	b _0808B38A
_0808B35A:
	movs r0, #0xa
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp]
	movs r1, #0xac
	lsls r1, r1, #6
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r0, r2
	str r0, [sp, #4]
	mov r0, sp
	movs r1, #0
	bl FUN_080adad0
	ldr r1, _0808B3D4 @ =0x00006E05
	adds r0, r4, #0
	bl SetMotion
_0808B38A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808B390:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r4, #0x68]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x68]
	ldr r2, _0808B3D8 @ =gSineTable
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
	beq _0808B3CC
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808B40A
_0808B3CC:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0808B40A
	.align 2, 0
_0808B3D4: .4byte 0x00006E05
_0808B3D8: .4byte gSineTable
_0808B3DC:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r4, #0x68]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x68]
	ldr r2, _0808B414 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r2, #4
	subs r0, r0, r2
	adds r1, r1, r0
	str r1, [r4, #0x58]
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808B40A:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808B414: .4byte gSineTable
