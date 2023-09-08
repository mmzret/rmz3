	push {r4, r5, r6, r7, lr}
	ldr r6, _08002278 @ =gProcessManager
	ldr r0, _0800227C @ =0x00001350
	adds r5, r6, r0
	ldr r1, _08002280 @ =0x00001304
	adds r7, r6, r1
_08002200:
	movs r0, #0
	str r0, [r5]
	ldr r2, _08002284 @ =0x00001308
	adds r4, r6, r2
_08002208:
	ldrb r1, [r4]
	movs r0, #9
	ands r0, r1
	cmp r0, #0
	bne _08002252
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08002232
	ldrh r1, [r4, #2]
	movs r2, #2
	ldrsh r0, [r4, r2]
	cmp r0, #0
	beq _0800222E
	subs r0, r1, #1
	strh r0, [r4, #2]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08002232
_0800222E:
	movs r0, #2
	strb r0, [r4]
_08002232:
	ldrb r0, [r4]
	cmp r0, #2
	bne _08002252
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08002246
	ldr r0, [r5]
	ldr r1, [r4, #4]
	bl ResetProcess
_08002246:
	ldr r1, [r4, #4]
	ldr r2, [r4, #8]
	adds r0, r4, #0
	ldr r3, _08002288 @ =0x02000000
	bl CallProcess
_08002252:
	ldr r0, [r5]
	adds r0, #1
	str r0, [r5]
	adds r4, #0x18
	cmp r0, #2
	bls _08002208
	movs r1, #0x98
	lsls r1, r1, #5
	adds r0, r6, r1
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	ldr r0, [r7]
	cmp r0, #0
	bne _08002200
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08002278: .4byte gProcessManager
_0800227C: .4byte 0x00001350
_08002280: .4byte 0x00001304
_08002284: .4byte 0x00001308
_08002288: .4byte 0x02000000
