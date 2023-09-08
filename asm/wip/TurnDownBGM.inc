	push {r4, r5, lr}
	ldr r0, _080044D4 @ =0x0000000F
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _080044CE
	ldr r5, _080044D8 @ =gMPlayTable
	adds r4, r0, #0
_080044BC:
	ldr r0, [r5]
	ldr r1, _080044DC @ =0x0000FFFF
	movs r2, #0x60
	bl m4aMPlayVolumeControl
	adds r5, #0xc
	subs r4, #1
	cmp r4, #0
	bne _080044BC
_080044CE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080044D4: .4byte 0x0000000F
_080044D8: .4byte gMPlayTable
_080044DC: .4byte 0x0000FFFF
