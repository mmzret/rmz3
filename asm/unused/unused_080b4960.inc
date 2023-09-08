	push {r4, r5, r6, lr}
	adds r6, r1, #0
	lsls r2, r2, #0x18
	cmp r2, #0
	beq _080B4970
	movs r1, #0x80
	lsls r1, r1, #6
	b _080B4972
_080B4970:
	ldr r1, _080B4990 @ =0xFFFFE000
_080B4972:
	adds r4, r0, r1
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_08009f6c
	adds r5, r0, #0
	subs r1, r5, r6
	cmp r1, #0
	bge _080B4986
	rsbs r1, r1, #0
_080B4986:
	movs r0, #0xf0
	lsls r0, r0, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B4990: .4byte 0xFFFFE000
