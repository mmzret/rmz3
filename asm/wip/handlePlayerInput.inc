	push {r4, lr}
	mov ip, r0
	movs r2, #0x3f
	ldr r4, _08028FCC @ =gStageRun
	movs r3, #0xca
	lsls r3, r3, #1
	add r3, ip
	movs r1, #0x84
	lsls r1, r1, #2
	add r1, ip
_08028F9C:
	ldrh r0, [r1]
	strh r0, [r1, #2]
	subs r1, #2
	subs r2, #1
	cmp r2, #0
	bne _08028F9C
	ldrh r2, [r4, #4]
	ldr r0, _08028FD0 @ =0x00000FFF
	ands r0, r2
	strh r0, [r3]
	ldr r3, _08028FD4 @ =0x00000216
	add r3, ip
	ldrh r0, [r3]
	eors r0, r2
	ands r0, r2
	movs r1, #0x85
	lsls r1, r1, #2
	add r1, ip
	strh r0, [r1]
	strh r2, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08028FCC: .4byte gStageRun
_08028FD0: .4byte 0x00000FFF
_08028FD4: .4byte 0x00000216
