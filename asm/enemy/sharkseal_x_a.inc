	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start SharksealX_Update
SharksealX_Update: @ 0x080701D4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08070204
	ldr r1, _08070200 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl SharksealX_Die
	b _080702C0
	.align 2, 0
_08070200: .4byte gEnemyFnTable
_08070204:
	adds r0, r4, #0
	bl nop_080711d4
	ldr r0, _08070240 @ =0x08366A04
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl sharksealx_08071030
	ldrb r0, [r4, #0xd]
	cmp r0, #5
	beq _08070244
	cmp r0, #7
	beq _08070244
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _08070244
	ldrb r1, [r4, #0xd]
	adds r0, r4, #0
	adds r0, #0xbe
	strb r1, [r0]
	b _080702C0
	.align 2, 0
_08070240: .4byte sSharksealXUpdates1
_08070244:
	ldr r0, _08070294 @ =gOverworld
	ldr r1, _08070298 @ =0x0002C00C
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r0, r2
	cmp r1, r0
	ble _0807029C
	adds r6, r4, #0
	adds r6, #0xbd
	ldrb r5, [r6]
	cmp r5, #0
	bne _08070274
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateEntityAnim
	str r5, [r4, #0x60]
_08070274:
	movs r0, #1
	strb r0, [r6]
	ldr r0, [r4, #0x60]
	adds r0, #0x20
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08070288
	str r1, [r4, #0x60]
_08070288:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	b _080702C0
	.align 2, 0
_08070294: .4byte gOverworld
_08070298: .4byte 0x0002C00C
_0807029C:
	adds r2, r4, #0
	adds r2, #0xbd
	ldrb r1, [r2]
	cmp r1, #1
	bne _080702AC
	movs r0, #0
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
_080702AC:
	movs r0, #0
	strb r0, [r2]
	ldr r1, _080702C8 @ =0x08366A24
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080702C0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080702C8: .4byte sSharksealXUpdates2

	thumb_func_start SharksealX_Die
SharksealX_Die: @ 0x080702CC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	ldr r0, _0807031C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08070324
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
	ldr r1, _08070320 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _0807079C
	.align 2, 0
_0807031C: .4byte gCurStory
_08070320: .4byte gEnemyFnTable
_08070324:
	ldrb r0, [r7, #0xe]
	cmp r0, #0xb
	bls _0807032C
	b _0807079E
_0807032C:
	lsls r0, r0, #2
	ldr r1, _08070338 @ =_0807033C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08070338: .4byte _0807033C
_0807033C: @ jump table
	.4byte _0807036C @ case 0
	.4byte _080704DE @ case 1
	.4byte _080703BC @ case 2
	.4byte _080703D0 @ case 3
	.4byte _080704F4 @ case 4
	.4byte _0807079E @ case 5
	.4byte _0807079E @ case 6
	.4byte _0807079E @ case 7
	.4byte _0807079E @ case 8
	.4byte _0807079E @ case 9
	.4byte _080704DE @ case 10
	.4byte _08070670 @ case 11
_0807036C:
	ldr r1, _08070394 @ =0x00001803
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
	beq _08070398
	movs r0, #0x80
	lsls r0, r0, #9
	ands r2, r0
	cmp r2, #0
	beq _08070398
	movs r0, #1
	b _0807039A
	.align 2, 0
_08070394: .4byte 0x00001803
_08070398:
	movs r0, #0xa
_0807039A:
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
	b _080704DE
_080703BC:
	adds r0, r7, #0
	bl UpdateEntityAnim
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080703CE
	b _0807079E
_080703CE:
	b _080704DE
_080703D0:
	ldr r1, _08070418 @ =0x00001803
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
	adds r0, r7, #0
	adds r0, #0xbc
	ldrb r1, [r0]
	mov r0, sp
	bl FUN_080b7b38
	adds r0, r7, #0
	adds r0, #0xbf
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _08070428
	cmp r0, #0xfe
	bne _0807041C
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
	b _0807044A
	.align 2, 0
_08070418: .4byte 0x00001803
_0807041C:
	ldr r0, _08070438 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r7, #0x54]
	cmp r1, r0
	ble _0807043C
_08070428:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #1
	bl FUN_080b2b40
	b _0807044A
	.align 2, 0
_08070438: .4byte pZero2
_0807043C:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
_0807044A:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	movs r2, #1
	bl CreateBubble
	ldr r3, _080704E8 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r6, _080704EC @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r4, _080704F0 @ =0x00269EC3
	adds r1, r1, r4
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsrs r1, r1, #0x11
	movs r5, #0xf
	ands r1, r5
	subs r1, #8
	lsls r1, r1, #8
	ldr r0, [sp]
	adds r0, r0, r1
	str r0, [sp]
	muls r2, r6, r2
	adds r2, r2, r4
	lsls r2, r2, #1
	lsrs r1, r2, #1
	str r1, [r3]
	lsrs r2, r2, #0x11
	ands r2, r5
	subs r2, #8
	lsls r2, r2, #8
	ldr r1, [sp, #4]
	adds r1, r1, r2
	str r1, [sp, #4]
	movs r2, #1
	str r3, [sp, #0x20]
	bl CreateBubble
	ldr r3, [sp, #0x20]
	ldr r0, [r3]
	adds r1, r0, #0
	muls r1, r6, r1
	adds r1, r1, r4
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsrs r1, r1, #0x11
	ands r1, r5
	subs r1, #8
	lsls r1, r1, #8
	ldr r0, [sp]
	adds r0, r0, r1
	str r0, [sp]
	muls r2, r6, r2
	adds r2, r2, r4
	lsls r2, r2, #1
	lsrs r1, r2, #1
	str r1, [r3]
	lsrs r2, r2, #0x11
	ands r2, r5
	subs r2, #8
	lsls r2, r2, #8
	ldr r1, [sp, #4]
	adds r1, r1, r2
	str r1, [sp, #4]
	movs r2, #0
	bl CreateBubble
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #3
	bl TryDropItem
	movs r0, #0x3c
	strb r0, [r7, #0x12]
_080704DE:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _0807079E
	.align 2, 0
_080704E8: .4byte RNG_0202f388
_080704EC: .4byte 0x000343FD
_080704F0: .4byte 0x00269EC3
_080704F4:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x60]
	adds r0, #8
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807050A
	str r1, [r7, #0x60]
_0807050A:
	ldr r1, [r7, #0x58]
	ldr r0, [r7, #0x60]
	adds r1, r1, r0
	str r1, [r7, #0x58]
	ldr r0, [r7, #0x54]
	ldr r2, [r7, #0x5c]
	adds r0, r0, r2
	str r0, [r7, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080705C4
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	ldr r1, _080705A4 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r2, _080705A8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080705AC @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080705B0 @ =0x00269EC3
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
	add r5, sp, #8
	str r0, [r5, #4]
	adds r6, r7, #0
	adds r6, #0xbc
	ldrb r1, [r6]
	ldr r2, _080705B4 @ =0x00001804
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080b7b8c
	ldrb r1, [r6]
	ldr r0, _080705B8 @ =0x00001805
	mov r8, r0
	adds r0, r5, #0
	mov r2, r8
	adds r3, r4, #0
	bl FUN_080b7b8c
	ldrb r1, [r6]
	adds r0, r5, #0
	mov r2, r8
	adds r3, r4, #0
	bl FUN_080b7b8c
	movs r0, #0x31
	bl PlaySound
	ldr r2, _080705BC @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _080705C0 @ =0x0000270E
	cmp r1, r0
	bhi _0807059C
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0807059C:
	adds r1, r7, #0
	adds r1, #0x54
	adds r0, r7, #0
	b _08070780
	.align 2, 0
_080705A4: .4byte 0xFFFFF800
_080705A8: .4byte RNG_0202f388
_080705AC: .4byte 0x000343FD
_080705B0: .4byte 0x00269EC3
_080705B4: .4byte 0x00001804
_080705B8: .4byte 0x00001805
_080705BC: .4byte gScore
_080705C0: .4byte 0x0000270E
_080705C4:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _080705CC
	b _0807079E
_080705CC:
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080705D8
	b _0807079E
_080705D8:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x31
	bl PlaySound
	ldr r2, _08070654 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08070658 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r1, _0807065C @ =0x00269EC3
	adds r4, r4, r1
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11

	thumb_func_start FUN_08070604
FUN_08070604: @ 0x08070604
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp, #0x10]
	ldr r0, [r7, #0x58]
	add r5, sp, #0x10
	str r0, [r5, #4]
	adds r6, r7, #0
	adds r6, #0xbc
	ldrb r1, [r6]
	ldr r2, _08070660 @ =0x00001804
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080b7b8c
	ldrb r1, [r6]
	ldr r0, _08070664 @ =0x00001805
	mov r8, r0
	adds r0, r5, #0
	mov r2, r8
	adds r3, r4, #0
	bl FUN_080b7b8c
	ldrb r1, [r6]
	adds r0, r5, #0
	mov r2, r8
	adds r3, r4, #0
	bl FUN_080b7b8c
	ldr r2, _08070668 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _0807066C @ =0x0000270E
	cmp r1, r0
	bhi _0807064C
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0807064C:
	adds r1, r7, #0
	adds r1, #0x54
	adds r0, r7, #0
	b _08070780
	.align 2, 0
_08070654: .4byte RNG_0202f388
_08070658: .4byte 0x000343FD
_0807065C: .4byte 0x00269EC3
_08070660: .4byte 0x00001804
_08070664: .4byte 0x00001805
_08070668: .4byte gScore
_0807066C: .4byte 0x0000270E
_08070670:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	ldr r1, _080707AC @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x31
	bl PlaySound
	movs r0, #0x54
	adds r0, r0, r7
	mov sb, r0
	movs r0, #3
	mov r1, sb
	bl TryDropItem
	ldr r0, [sp]
	ldr r1, [sp, #4]
	movs r2, #1
	bl CreateBubble
	ldr r5, _080707B0 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r1, _080707B4 @ =0x000343FD
	mov r8, r1
	mov r1, r8
	muls r1, r0, r1
	ldr r6, _080707B8 @ =0x00269EC3
	adds r1, r1, r6
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsrs r1, r1, #0x11
	movs r4, #0xf
	ands r1, r4
	subs r1, #8
	lsls r1, r1, #8
	ldr r0, [sp]
	adds r0, r0, r1
	str r0, [sp]
	mov r1, r8
	muls r1, r2, r1
	adds r2, r1, #0
	adds r2, r2, r6
	lsls r2, r2, #1
	lsrs r1, r2, #1
	str r1, [r5]
	lsrs r2, r2, #0x11
	ands r2, r4
	subs r2, #8
	lsls r2, r2, #8
	ldr r1, [sp, #4]
	adds r1, r1, r2
	str r1, [sp, #4]
	movs r2, #1
	bl CreateBubble
	ldr r0, [r5]
	mov r1, r8
	muls r1, r0, r1
	adds r1, r1, r6
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsrs r1, r1, #0x11
	ands r1, r4
	subs r1, #8
	lsls r1, r1, #8
	ldr r0, [sp]
	adds r0, r0, r1
	str r0, [sp]
	mov r1, r8
	muls r1, r2, r1
	adds r2, r1, #0
	adds r2, r2, r6
	lsls r2, r2, #1
	lsrs r1, r2, #1
	str r1, [r5]
	lsrs r2, r2, #0x11
	ands r2, r4
	subs r2, #8
	lsls r2, r2, #8
	ldr r1, [sp, #4]
	adds r1, r1, r2
	str r1, [sp, #4]
	movs r2, #0
	bl CreateBubble
	ldr r0, [r5]
	mov r4, r8
	muls r4, r0, r4
	adds r4, r4, r6
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r5]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp, #0x18]
	ldr r0, [r7, #0x58]
	add r5, sp, #0x18
	str r0, [r5, #4]
	adds r6, r7, #0
	adds r6, #0xbc
	ldrb r1, [r6]
	ldr r2, _080707BC @ =0x00001804
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080b7b8c
	ldrb r1, [r6]
	ldr r0, _080707C0 @ =0x00001805
	mov r8, r0
	adds r0, r5, #0
	mov r2, r8
	adds r3, r4, #0
	bl FUN_080b7b8c
	ldrb r1, [r6]
	adds r0, r5, #0
	mov r2, r8
	adds r3, r4, #0
	bl FUN_080b7b8c
	ldr r2, _080707C4 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _080707C8 @ =0x0000270E
	cmp r1, r0
	bhi _0807077C
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0807077C:
	adds r0, r7, #0
	mov r1, sb
_08070780:
	bl TryDropZakoDisk
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080707CC @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
_0807079C:
	str r0, [r7, #0x14]
_0807079E:
	add sp, #0x24
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080707AC: .4byte 0xFFFFF800
_080707B0: .4byte RNG_0202f388
_080707B4: .4byte 0x000343FD
_080707B8: .4byte 0x00269EC3
_080707BC: .4byte 0x00001804
_080707C0: .4byte 0x00001805
_080707C4: .4byte gScore
_080707C8: .4byte 0x0000270E
_080707CC: .4byte gEnemyFnTable

