	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreatePantheonBomber
CreatePantheonBomber: @ 0x08085D0C
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _08085D64 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08085D5A
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08085D68 @ =gEnemyFnTable
	movs r1, #0x2c
	strb r1, [r3, #9]
	adds r0, #0xb0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	strb r4, [r3, #0x10]
_08085D5A:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08085D64: .4byte gZakoHeaderPtr
_08085D68: .4byte gEnemyFnTable

	thumb_func_start PantheonBomber_Init
PantheonBomber_Init: @ 0x08085D6C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r3, #0
	adds r2, r0, #0
	orrs r2, r1
	movs r0, #2
	orrs r2, r0
	orrs r2, r3
	strb r2, [r6, #0xa]
	ldr r0, _08085DB8 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x12]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08085DC4
	ldr r0, _08085DBC @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08085DC4
	movs r0, #4
	orrs r2, r0
	strb r2, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08085DC0 @ =0x08368534
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xc
	b _08085DDC
	.align 2, 0
_08085DB8: .4byte gSystemSavedataManager
_08085DBC: .4byte gCurStory
_08085DC0: .4byte 0x08368534
_08085DC4:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08085E5C @ =0x08368534
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #8
_08085DDC:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _08085E60 @ =FUN_0808665c
	str r0, [r4, #0x24]
	adds r1, r6, #0
	adds r1, #0xb4
	ldr r0, [r6, #0x54]
	str r0, [r1]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	str r0, [r6, #0x5c]
	str r1, [r6, #0x60]
	adds r0, r6, #0
	adds r0, #0xb8
	movs r4, #0
	strb r4, [r0]
	adds r0, #4
	str r4, [r0]
	subs r0, #3
	strb r4, [r0]
	ldr r0, [r6, #0x54]
	ldr r1, _08085E64 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r1, _08085E68 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r4, [r6, #0xd]
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xf]
	adds r0, r6, #0
	bl isFrozen
	cmp r0, #0
	beq _08085E4A
	ldr r1, _08085E6C @ =0x00006903
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
_08085E4A:
	adds r0, r6, #0
	adds r0, #0xba
	strb r4, [r0]
	adds r0, r6, #0
	bl PantheonBomber_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08085E5C: .4byte 0x08368534
_08085E60: .4byte FUN_0808665c
_08085E64: .4byte 0xFFFFF800
_08085E68: .4byte gEnemyFnTable
_08085E6C: .4byte 0x00006903

	thumb_func_start PantheonBomber_Update
PantheonBomber_Update: @ 0x08085E70
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r6, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r6, r0
	cmp r6, #0
	beq _08085EA0
	ldr r1, _08085E9C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl PantheonBomber_Die
	b _08085F10
	.align 2, 0
_08085E9C: .4byte gEnemyFnTable
_08085EA0:
	ldr r1, _08085EE8 @ =0x08368504
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl pBomber_08086628
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	cmp r0, #0
	bne _08085ED0
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	bne _08085F10
	ldr r0, [r5]
	cmp r0, #0
	beq _08085F00
_08085ED0:
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08085EF0
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08085EEC @ =0x0836854C
	bl SetDDP
	str r6, [r5]
	b _08085F10
	.align 2, 0
_08085EE8: .4byte 0x08368504
_08085EEC: .4byte 0x0836854C
_08085EF0:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08085EFC @ =0x08368564
	bl SetDDP
	b _08085F10
	.align 2, 0
_08085EFC: .4byte 0x08368564
_08085F00:
	ldr r0, _08085F18 @ =0x0836851C
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_08085F10:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08085F18: .4byte 0x0836851C

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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	ldr r2, _080861B4 @ =gMission
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
_080861B4: .4byte gMission
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
	ldr r2, _08086260 @ =gMission
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
_08086260: .4byte gMission
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
	ldr r2, _0808632C @ =gMission
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
_0808632C: .4byte gMission
_08086330: .4byte 0x0000270E
_08086334: .4byte gEnemyFnTable

	thumb_func_start nop_08086338
nop_08086338: @ 0x08086338
	movs r0, #1
	bx lr

	thumb_func_start pantheon_bomber_0808633c
pantheon_bomber_0808633c: @ 0x0808633C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0808634C
	cmp r5, #1
	beq _08086372
	b _08086390
_0808634C:
	ldr r1, _08086398 @ =0x00006904
	adds r0, r4, #0
	movs r2, #2
	movs r3, #1
	bl GotoMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808639C @ =0x08368534
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0xb9
	strb r5, [r0]
	movs r0, #0x30
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08086372:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08086388
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08086390
_08086388:
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08086390:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08086398: .4byte 0x00006904
_0808639C: .4byte 0x08368534

	thumb_func_start nop_080863a0
nop_080863a0: @ 0x080863A0
	movs r0, #1
	bx lr

	thumb_func_start pantheon_bomber_080863a4
pantheon_bomber_080863a4: @ 0x080863A4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080863B4
	cmp r5, #1
	beq _080863CC
	b _08086402
_080863B4:
	ldr r1, _08086408 @ =0x00006904
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0xb9
	strb r5, [r0]
	movs r0, #0x20
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080863CC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x70]
	ldr r1, _0808640C @ =0x00FFFF00
	ands r0, r1
	movs r1, #0x81
	lsls r1, r1, #9
	cmp r0, r1
	bne _080863EA
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08086410 @ =0x08368534
	bl SetDDP
_080863EA:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080863FA
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08086402
_080863FA:
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08086402:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08086408: .4byte 0x00006904
_0808640C: .4byte 0x00FFFF00
_08086410: .4byte 0x08368534

	thumb_func_start nop_08086414
nop_08086414: @ 0x08086414
	movs r0, #1
	bx lr

	thumb_func_start pantheon_bomber_08086418
pantheon_bomber_08086418: @ 0x08086418
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xa
	bls _08086426
	b _080865C8
_08086426:
	lsls r0, r0, #2
	ldr r1, _08086430 @ =_08086434
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08086430: .4byte _08086434
_08086434: @ jump table
	.4byte _08086460 @ case 0
	.4byte _08086480 @ case 1
	.4byte _080864BC @ case 2
	.4byte _0808659E @ case 3
	.4byte _080864D2 @ case 4
	.4byte _080864E4 @ case 5
	.4byte _08086550 @ case 6
	.4byte _0808659E @ case 7
	.4byte _08086554 @ case 8
	.4byte _0808659E @ case 9
	.4byte _080865C0 @ case 10
_08086460:
	ldr r1, _080864AC @ =0x00006903
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0xb9
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080864B0 @ =0x08368534
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08086480:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x70]
	ldr r1, _080864B4 @ =0x00FFFF00
	ands r0, r1
	movs r1, #0x81
	lsls r1, r1, #9
	cmp r0, r1
	bne _0808649E
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080864B8 @ =0x0836854C
	bl SetDDP
_0808649E:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080864AA
	b _080865C8
_080864AA:
	b _080865B4
	.align 2, 0
_080864AC: .4byte 0x00006903
_080864B0: .4byte 0x08368534
_080864B4: .4byte 0x00FFFF00
_080864B8: .4byte 0x0836854C
_080864BC:
	movs r1, #0xd2
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0xb9
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x10
	b _08086596
_080864D2:
	ldr r1, _08086538 @ =0x00006905
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080864E4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bne _0808649E
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0808649E
	ldr r0, [r4, #0x54]
	ldr r1, _0808653C @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08086540 @ =0xFFFFF200
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r3, _08086544 @ =RNG_0202f388
	ldr r1, [r3]
	ldr r0, _08086548 @ =0x000343FD
	adds r2, r1, #0
	muls r2, r0, r2
	ldr r0, _0808654C @ =0x00269EC3
	adds r2, r2, r0
	lsls r2, r2, #1
	lsrs r0, r2, #1
	str r0, [r3]
	lsrs r2, r2, #0x11
	movs r0, #1
	ands r2, r0
	mov r0, sp
	mov r1, sp
	bl createPantheonBomb
	movs r0, #1
	strb r0, [r4, #0x12]
	b _0808649E
	.align 2, 0
_08086538: .4byte 0x00006905
_0808653C: .4byte 0xFFFFF800
_08086540: .4byte 0xFFFFF200
_08086544: .4byte RNG_0202f388
_08086548: .4byte 0x000343FD
_0808654C: .4byte 0x00269EC3
_08086550:
	movs r0, #0x12
	b _08086596
_08086554:
	ldr r2, _0808657C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08086580 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08086584 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0808658C
	ldr r1, _08086588 @ =0x00006901
	adds r0, r4, #0
	bl SetMotion
	b _08086594
	.align 2, 0
_0808657C: .4byte RNG_0202f388
_08086580: .4byte 0x000343FD
_08086584: .4byte 0x00269EC3
_08086588: .4byte 0x00006901
_0808658C:
	ldr r1, _080865BC @ =0x00006902
	adds r0, r4, #0
	bl SetMotion
_08086594:
	movs r0, #0x40
_08086596:
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808659E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080865B4
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080865C8
_080865B4:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080865C8
	.align 2, 0
_080865BC: .4byte 0x00006902
_080865C0:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080865C8:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start nop_080865d0
nop_080865d0: @ 0x080865D0
	movs r0, #1
	bx lr

	thumb_func_start FUN_080865d4
FUN_080865d4: @ 0x080865D4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _080865EE
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080865F4 @ =0x08368564
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080865EE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080865F4: .4byte 0x08368564

	thumb_func_start nop_080865f8
nop_080865f8: @ 0x080865F8
	movs r0, #1
	bx lr

	thumb_func_start nop_080865fc
nop_080865fc: @ 0x080865FC
	bx lr
	.align 2, 0

	thumb_func_start nop_08086600
nop_08086600: @ 0x08086600
	movs r0, #1
	bx lr

	thumb_func_start FUN_08086604
FUN_08086604: @ 0x08086604
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0808661E
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08086624 @ =0x08368564
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808661E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08086624: .4byte 0x08368564

	thumb_func_start pBomber_08086628
pBomber_08086628: @ 0x08086628
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r3, #0
	adds r4, #0xbc
	ldr r0, [r4]
	cmp r0, #0
	bne _08086650
	adds r0, r3, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08086650
	ldr r2, _08086658 @ =0x083685AC
	movs r0, #0
	adds r1, r3, #0
	bl ApplyElementEffect
	str r0, [r4]
_08086650:
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08086658: .4byte 0x083685AC

	thumb_func_start FUN_0808665c
FUN_0808665c: @ 0x0808665C
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, [r2, #0xc]
	ldr r0, [r0, #4]
	ldrb r0, [r0, #4]
	cmp r0, #3
	beq _08086674
	cmp r0, #0xe
	beq _08086674
	cmp r0, #0xf
	bne _0808669E
_08086674:
	ldr r2, [r2, #0x2c]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0808669E
	ldr r1, [r2, #0x54]
	ldr r0, [r3]
	cmp r1, r0
	bge _08086696
	adds r1, r2, #0
	adds r1, #0xba
	movs r0, #0xff
	b _0808669C
_08086696:
	adds r1, r2, #0
	adds r1, #0xba
	movs r0, #0xfe
_0808669C:
	strb r0, [r1]
_0808669E:
	pop {r0}
	bx r0
	.align 2, 0
