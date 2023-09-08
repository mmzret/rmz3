	push {r4, r5, r6, r7}
	ldr r2, _0800067C @ =gOamManager
	ldr r3, [r0, #0x10]
	lsls r3, r3, #2
	lsrs r3, r3, #0x1b
	lsls r3, r3, #5
	adds r2, r2, r3
	strb r1, [r0, #0x1b]
	lsls r1, r1, #1
	ldrb r7, [r0, #0x18]
	ldrb r6, [r0, #0x19]
	eors r6, r7
	beq _0800055C
	rsbs r1, r1, #0
	lsls r1, r1, #0x17
	lsrs r1, r1, #0x17
_0800055C:
	ldr r3, _08000678 @ =gSineTable
	movs r4, #0x80
	adds r4, r4, r1
	lsls r4, r4, #0x17
	lsrs r4, r4, #0x17
	ldrsh r5, [r3, r4]
	ldrsh r6, [r3, r1]
	orrs r7, r7
	beq _08000572
	rsbs r5, r5, #0
	rsbs r6, r6, #0
_08000572:
	strh r5, [r2, #6]
	strh r6, [r2, #0xe]
	ldrsh r5, [r3, r4]
	ldrsh r6, [r3, r1]
	ldrb r7, [r0, #0x19]
	orrs r7, r7
	beq _08000584
	rsbs r5, r5, #0
	rsbs r6, r6, #0
_08000584:
	strh r5, [r2, #0x1e]
	rsbs r6, r6, #0
	strh r6, [r2, #0x16]
	pop {r4, r5, r6, r7}
	bx lr
