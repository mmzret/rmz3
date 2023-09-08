  push {r4, r5, lr}
	ldr r0, _0800450C @ =0x0000000F
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _08004504
	ldr r5, _08004510 @ =gMPlayTable
	adds r4, r0, #0
_080044F0:
	ldr r0, [r5]
	ldr r1, _08004514 @ =0x0000FFFF
	movs r2, #0x80
	lsls r2, r2, #1
	bl m4aMPlayVolumeControl
	adds r5, #0xc
	subs r4, #1
	cmp r4, #0
	bne _080044F0
_08004504:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800450C: .4byte 0x0000000F
_08004510: .4byte gMPlayTable
_08004514: .4byte 0x0000FFFF
