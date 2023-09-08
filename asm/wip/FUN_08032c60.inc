	push {lr}
	ldr r2, _08032C74 @ =0x0000011D
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _08032C78
	movs r0, #0x80
	lsls r0, r0, #1
	b _08032C80
	.align 2, 0
_08032C74: .4byte 0x0000011D
_08032C78:
	ldrb r1, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	subs r0, r0, r1
_08032C80:
	pop {r1}
	bx r1
