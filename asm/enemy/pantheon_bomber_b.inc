	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start PantheonBomber_Die
PantheonBomber_Die: @ 0x08085F1C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldr r0, _08085F68 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08085F70
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _08085F6C @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _08086306
	.align 2, 0
_08085F68: .4byte gCurStory
_08085F6C: .4byte gEnemyFnTable
_08085F70:
	ldrb r0, [r7, #0xe]
	cmp r0, #0xb
	bls _08085F78
	b _08086308
_08085F78:
	lsls r0, r0, #2
	ldr r1, _08085F84 @ =_08085F88
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08085F84: .4byte _08085F88
_08085F88: @ jump table
	.4byte _08085FB8 @ case 0
	.4byte _080860DC @ case 1
	.4byte _08086008 @ case 2
	.4byte _0808601C @ case 3
	.4byte _080860E8 @ case 4
	.4byte _08086308 @ case 5
	.4byte _08086308 @ case 6
	.4byte _08086308 @ case 7
	.4byte _08086308 @ case 8
	.4byte _08086308 @ case 9
	.4byte _080860DC @ case 10
	.4byte _08086268 @ case 11
_08085FB8:
	ldr r1, _08085FE0 @ =0x00006906
	adds r0, r7, #0
	bl SetMotion
	adds r1, r7, #0
	adds r1, #0x8c
	ldr r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	adds r3, r1, #0
	cmp r0, #0
	beq _08085FE4
	movs r0, #0x80
	lsls r0, r0, #9
	ands r2, r0
	cmp r2, #0
	beq _08085FE4
	movs r0, #1
	b _08085FE6
	.align 2, 0
_08085FE0: .4byte 0x00006906
_08085FE4:
	movs r0, #0xa
_08085FE6:
	strb r0, [r7, #0xe]
	movs r1, #0
	str r1, [r3]
	adds r0, r7, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r2, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x5c
	str r1, [r0, #4]
	str r1, [r7, #0x5c]
	b _080860DC
_08086008:
	adds r0, r7, #0
	bl UpdateEntityAnim
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0808601A
	b _08086308
_0808601A:
	b _080860DC
_0808601C:
	ldr r1, _08086060 @ =0x00006906
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	bl UpdateEntityAnim
	movs r0, #0
	strb r0, [r7, #0x13]
	str r0, [r7, #0x60]
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	adds r4, r7, #0
	adds r4, #0xb8
	ldrb r1, [r4]
	mov r0, sp
	bl FUN_080c26e8
	ldrb r0, [r4]
	cmp r0, #0
	bne _08086068
	ldr r0, [sp]
	ldr r1, _08086064 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #0x80
	b _0808607C
	.align 2, 0
_08086060: .4byte 0x00006906
_08086064: .4byte 0xFFFFF800
_08086068:
	ldr r0, [sp]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #0x80
	rsbs r0, r0, #0
_0808607C:
	str r0, [r7, #0x5c]
	adds r0, r7, #0
	adds r0, #0xba
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _080860A8
	cmp r0, #0xfe
	bne _0808609C
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
	b _080860CA
_0808609C:
	ldr r0, _080860B8 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r7, #0x54]
	cmp r1, r0
	ble _080860BC
_080860A8:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #1
	bl FUN_080b2b40
	b _080860CA
	.align 2, 0
_080860B8: .4byte pZero2
_080860BC:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
_080860CA:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #4
	bl TryDropItem
	ldr r0, _080860E4 @ =0xFFFFFE80
	str r0, [r7, #0x60]
	movs r0, #0x32
	strb r0, [r7, #0x12]
_080860DC:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _08086308
	.align 2, 0
_080860E4: .4byte 0xFFFFFE80
_080860E8:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x60]
	adds r0, #0x20
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080860FE
	str r1, [r7, #0x60]
_080860FE:
	ldr r1, [r7, #0x58]
	ldr r0, [r7, #0x60]
	adds r1, r1, r0
	str r1, [r7, #0x58]
	ldr r2, [r7, #0x5c]
	rsbs r0, r2, #0
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r7, #0x5c]
	ldr r0, [r7, #0x54]
	adds r0, r0, r2
	str r0, [r7, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080861BC
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r2, _0808619C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080861A0 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080861A4 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp, #8]
	ldr r0, [r7, #0x58]
	add r6, sp, #8
	str r0, [r6, #4]
	adds r5, r7, #0
	adds r5, #0xb8
	ldrb r1, [r5]
	ldr r2, _080861A8 @ =0x00006908
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c273c
	ldrb r1, [r5]
	ldr r2, _080861AC @ =0x00006909
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c273c
	ldrb r1, [r5]
	ldr r2, _080861B0 @ =0x0000690A
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c273c
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _080861B4 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _080861B8 @ =0x0000270E
	cmp r1, r0
	bhi _08086192
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08086192:
	adds r1, r7, #0
	adds r1, #0x54
	adds r0, r7, #0
	b _080862EA
	.align 2, 0
_0808619C: .4byte RNG_0202f388
_080861A0: .4byte 0x000343FD
_080861A4: .4byte 0x00269EC3
_080861A8: .4byte 0x00006908
_080861AC: .4byte 0x00006909
_080861B0: .4byte 0x0000690A
_080861B4: .4byte gScore
_080861B8: .4byte 0x0000270E
_080861BC:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _080861C4
	b _08086308
_080861C4:
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080861D0
	b _08086308
_080861D0:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r2, _08086248 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0808624C @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r1, _08086250 @ =0x00269EC3
	adds r4, r4, r1
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp, #0x10]
	ldr r0, [r7, #0x58]
	add r6, sp, #0x10
	str r0, [r6, #4]
	adds r5, r7, #0
	adds r5, #0xb8
	ldrb r1, [r5]
	ldr r2, _08086254 @ =0x00006908
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c273c
	ldrb r1, [r5]
	ldr r2, _08086258 @ =0x00006909
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c273c
	ldrb r1, [r5]
	ldr r2, _0808625C @ =0x0000690A
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c273c
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _08086260 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _08086264 @ =0x0000270E
	cmp r1, r0
	bhi _08086240
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08086240:
	adds r1, r7, #0
	adds r1, #0x54
	adds r0, r7, #0
	b _080862EA
	.align 2, 0
_08086248: .4byte RNG_0202f388
_0808624C: .4byte 0x000343FD
_08086250: .4byte 0x00269EC3
_08086254: .4byte 0x00006908
_08086258: .4byte 0x00006909
_0808625C: .4byte 0x0000690A
_08086260: .4byte gScore
_08086264: .4byte 0x0000270E
_08086268:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	movs r0, #0x54
	adds r0, r0, r7
	mov r8, r0
	movs r0, #4
	mov r1, r8
	bl TryDropItem
	ldr r2, _08086314 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08086318 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r1, _0808631C @ =0x00269EC3
	adds r4, r4, r1
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp, #0x18]
	ldr r0, [r7, #0x58]
	add r6, sp, #0x18
	str r0, [r6, #4]
	adds r5, r7, #0
	adds r5, #0xb8
	ldrb r1, [r5]
	ldr r2, _08086320 @ =0x00006908
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c273c
	ldrb r1, [r5]
	ldr r2, _08086324 @ =0x00006909
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c273c
	ldrb r1, [r5]
	ldr r2, _08086328 @ =0x0000690A
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c273c
	ldr r2, _0808632C @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _08086330 @ =0x0000270E
	cmp r1, r0
	bhi _080862E6
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_080862E6:
	adds r0, r7, #0
	mov r1, r8
_080862EA:
	bl TryDropZakoDisk
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _08086334 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
_08086306:
	str r0, [r7, #0x14]
_08086308:
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08086314: .4byte RNG_0202f388
_08086318: .4byte 0x000343FD
_0808631C: .4byte 0x00269EC3
_08086320: .4byte 0x00006908
_08086324: .4byte 0x00006909
_08086328: .4byte 0x0000690A
_0808632C: .4byte gScore
_08086330: .4byte 0x0000270E
_08086334: .4byte gEnemyFnTable

