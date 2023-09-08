	push {r4, r5, lr}
	sub sp, #4
	mov r1, sp
	movs r3, #0x80
	lsls r3, r3, #0x13
	ldrh r0, [r3]
	strh r0, [r1]
	ldr r5, _0800435C @ =gOamManager+1024
	ldr r4, [r5]
	mov r2, sp
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08004360 @ =0x0000EFFF
	ands r0, r1
	strh r0, [r2]
	mov r1, sp
	ldr r0, [r5, #4]
	ldrh r1, [r1]
	orrs r0, r1
	strh r0, [r2]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r3]
	ldr r0, _08004364 @ =0xFFFFFC00
	adds r2, r5, r0
	cmp r4, r5
	bhs _0800433C
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r1, #0
_08004334:
	strh r0, [r4]
	adds r4, #8
	cmp r4, r5
	blo _08004334
_0800433C:
	ldr r1, _08004368 @ =0x040000D4
	str r2, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _0800436C @ =0x84000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r2, r1
	str r2, [r0]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800435C: .4byte gOamManager+1024
_08004360: .4byte 0x0000EFFF
_08004364: .4byte 0xFFFFFC00
_08004368: .4byte 0x040000D4
_0800436C: .4byte 0x84000100
