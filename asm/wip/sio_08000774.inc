	push {r7, lr}
	ldr r7, _08000780 @ =0x02000D50
	str r0, [r7, #0x1c]
	strh r1, [r7, #0xa]
	strh r2, [r7, #0xe]
	pop {r7, pc}
	.align 2, 0
_08000780: .4byte 0x02000D50
