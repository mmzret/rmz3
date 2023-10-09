	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateSharksealX
CreateSharksealX: @ 0x08070028
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _0807007C @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08070074
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _08070080 @ =gEnemyFnTable
	movs r0, #0xf
	strb r0, [r3, #9]
	ldr r0, [r1, #0x3c]
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
_08070074:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0807007C: .4byte gZakoHeaderPtr
_08070080: .4byte gEnemyFnTable

	thumb_func_start SharksealX_Init
SharksealX_Init: @ 0x08070084
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
	ldr r0, _080700D0 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x16]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080700DC
	ldr r0, _080700D4 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _080700DC
	movs r0, #4
	orrs r2, r0
	strb r2, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080700D8 @ =0x08366A44
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xa
	b _080700F4
	.align 2, 0
_080700D0: .4byte gSystemSavedataManager
_080700D4: .4byte gCurStory
_080700D8: .4byte 0x08366A44
_080700DC:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08070148 @ =0x08366A44
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
_080700F4:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _0807014C @ =FUN_080711d8
	str r0, [r4, #0x24]
	ldr r0, _08070150 @ =gOverworld
	ldr r1, _08070154 @ =0x0002C00C
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, [r6, #0x58]
	cmp r1, r0
	ble _0807015C
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _08070158 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
	b _080701C8
	.align 2, 0
_08070148: .4byte 0x08366A44
_0807014C: .4byte FUN_080711d8
_08070150: .4byte gOverworld
_08070154: .4byte 0x0002C00C
_08070158: .4byte gEnemyFnTable
_0807015C:
	adds r1, r6, #0
	adds r1, #0xb4
	ldr r0, [r6, #0x54]
	str r0, [r1]
	adds r2, r6, #0
	adds r2, #0x5c
	movs r4, #0
	str r4, [r2, #4]
	str r4, [r6, #0x5c]
	adds r0, r6, #0
	adds r0, #0xc0
	str r4, [r0]
	subs r0, #3
	strb r4, [r0]
	ldr r0, [r6, #0x54]
	str r0, [r1]
	ldr r0, [r6, #0x58]
	str r0, [r6, #0x68]
	str r4, [r2, #4]
	str r4, [r6, #0x5c]
	adds r0, r6, #0
	adds r0, #0xbc
	strb r4, [r0]
	adds r0, r6, #0
	bl isFrozen
	cmp r0, #0
	beq _080701A4
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
_080701A4:
	adds r0, r6, #0
	adds r0, #0xbf
	strb r4, [r0]
	ldr r1, _080701D0 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r1, [r6, #0xd]
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xf]
	adds r0, r6, #0
	bl SharksealX_Update
_080701C8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080701D0: .4byte gEnemyFnTable

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
	bl isFrozen
	cmp r0, #0
	beq _08070244
	ldrb r1, [r4, #0xd]
	adds r0, r4, #0
	adds r0, #0xbe
	strb r1, [r0]
	b _080702C0
	.align 2, 0
_08070240: .4byte 0x08366A04
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
	bl UpdateMotionGraphic
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
_080702C8: .4byte 0x08366A24

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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	ldr r2, _080705BC @ =gMission
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
_080705BC: .4byte gMission
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
	ldr r2, _08070668 @ =gMission
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
_08070668: .4byte gMission
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
	ldr r2, _080707C4 @ =gMission
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
_080707C4: .4byte gMission
_080707C8: .4byte 0x0000270E
_080707CC: .4byte gEnemyFnTable

	thumb_func_start FUN_080707d0
FUN_080707d0: @ 0x080707D0
	movs r0, #1
	bx lr

	thumb_func_start nop_080707d4
nop_080707d4: @ 0x080707D4
	bx lr
	.align 2, 0

	thumb_func_start FUN_080707d8
FUN_080707d8: @ 0x080707D8
	movs r0, #1
	bx lr

	thumb_func_start sharksealxMode1
sharksealxMode1: @ 0x080707DC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #0
	beq _080707EC
	cmp r4, #1
	beq _08070872
	b _080708CE
_080707EC:
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r5, #0
	bl SetMotion
	ldr r0, _0807080C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	ble _08070810
	adds r0, r5, #0
	adds r0, #0xbc
	strb r4, [r0]
	b _08070818
	.align 2, 0
_0807080C: .4byte pZero2
_08070810:
	adds r1, r5, #0
	adds r1, #0xbc
	movs r0, #1
	strb r0, [r1]
_08070818:
	adds r0, r5, #0
	adds r0, #0xbc
	ldrb r2, [r0]
	cmp r2, #0
	beq _0807082A
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08070830
_0807082A:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_08070830:
	strb r0, [r5, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r5, #0
	adds r0, #0x4c
	movs r4, #0
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080708A8 @ =0x08366A44
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xb8
	str r4, [r0]
	strb r4, [r5, #0x12]
	ldr r0, [r5, #0x58]
	str r0, [r5, #0x60]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08070872:
	ldrb r0, [r5, #0x12]
	adds r0, #2
	strb r0, [r5, #0x12]
	ldr r1, _080708AC @ =gSineTable
	ldrb r0, [r5, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #3
	ldr r0, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl forceWaterLanding
	adds r0, r5, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #0
	bne _080708B4
	ldr r0, _080708B0 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r0, #0x54]
	b _080708BC
	.align 2, 0
_080708A8: .4byte 0x08366A44
_080708AC: .4byte gSineTable
_080708B0: .4byte pZero2
_080708B4:
	ldr r0, _080708D4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r5, #0x54]
_080708BC:
	subs r1, r1, r0
	ldr r0, _080708D8 @ =0x00007FFF
	cmp r1, r0
	bgt _080708CE
	movs r1, #0
	str r1, [r5, #0x60]
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_080708CE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080708D4: .4byte pZero2
_080708D8: .4byte 0x00007FFF

	thumb_func_start FUN_080708dc
FUN_080708dc: @ 0x080708DC
	movs r0, #1
	bx lr

	thumb_func_start sharksealxMode2
sharksealxMode2: @ 0x080708E0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080708F0
	cmp r5, #1
	beq _0807094E
	b _0807098A
_080708F0:
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807091C @ =0x08366A44
	bl SetDDP
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r2, [r0]
	cmp r2, #0
	beq _08070920
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08070926
	.align 2, 0
_0807091C: .4byte 0x08366A44
_08070920:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08070926:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807094E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x60]
	adds r0, #0x20
	str r0, [r4, #0x60]
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	ble _08070964
	str r1, [r4, #0x60]
_08070964:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl forceWaterLanding
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08070982
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807098A
_08070982:
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0807098A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08070990
FUN_08070990: @ 0x08070990
	movs r0, #1
	bx lr

	thumb_func_start sharksealxMode3
sharksealxMode3: @ 0x08070994
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #5
	bls _080709A0
	b _08070C5A
_080709A0:
	lsls r0, r0, #2
	ldr r1, _080709AC @ =_080709B0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080709AC: .4byte _080709B0
_080709B0: @ jump table
	.4byte _080709C8 @ case 0
	.4byte _08070A22 @ case 1
	.4byte _08070B0C @ case 2
	.4byte _08070B16 @ case 3
	.4byte _08070B74 @ case 4
	.4byte _08070B94 @ case 5
_080709C8:
	movs r0, #0
	str r0, [r5, #0x60]
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080709F4 @ =0x08366A44
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xbc
	ldrb r2, [r0]
	cmp r2, #0
	beq _080709F8
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080709FE
	.align 2, 0
_080709F4: .4byte 0x08366A44
_080709F8:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080709FE:
	strb r0, [r5, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08070A22:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _08070A4C @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	ldr r1, _08070A50 @ =0xFFFFEC00
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	cmp r1, r0
	ble _08070A54
	ldr r0, [r5, #0x60]
	cmp r0, #0
	bge _08070A42
	movs r0, #0
	str r0, [r5, #0x60]
_08070A42:
	ldr r2, [r5, #0x60]
	movs r1, #0x80
	lsls r1, r1, #1
	b _08070A62
	.align 2, 0
_08070A4C: .4byte pZero2
_08070A50: .4byte 0xFFFFEC00
_08070A54:
	ldr r0, [r5, #0x60]
	cmp r0, #0
	ble _08070A5E
	movs r0, #0
	str r0, [r5, #0x60]
_08070A5E:
	ldr r2, [r5, #0x60]
	ldr r1, _08070A90 @ =0xFFFFFF00
_08070A62:
	subs r1, r1, r2
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x60]
	ldr r0, [r5, #0x58]
	subs r0, r0, r2
	str r0, [r5, #0x58]
	adds r0, r5, #0
	adds r0, #0xbc
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	bne _08070A98
	ldr r0, [r5, #0x5c]
	ldr r1, _08070A94 @ =0xFFFFFE00
	adds r0, r0, r1
	str r0, [r5, #0x5c]
	cmp r0, r1
	bge _08070AA8
	b _08070AA6
	.align 2, 0
_08070A90: .4byte 0xFFFFFF00
_08070A94: .4byte 0xFFFFFE00
_08070A98:
	ldr r0, [r5, #0x5c]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r0, r1
	str r0, [r5, #0x5c]
	cmp r0, r1
	ble _08070AA8
_08070AA6:
	str r1, [r5, #0x5c]
_08070AA8:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r4, r5, #0
	adds r4, #0xb8
	ldr r0, [r4]
	adds r0, r0, r1
	str r0, [r4]
	adds r0, r5, #0
	bl forceWaterLanding
	ldrb r0, [r6]
	cmp r0, #0
	bne _08070AD8
	ldr r0, _08070AD4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	ble _08070AEA
	b _08070AE4
	.align 2, 0
_08070AD4: .4byte pZero2
_08070AD8:
	ldr r0, _08070B08 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	bge _08070AEA
_08070AE4:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08070AEA:
	ldr r4, [r4]
	cmp r4, #0
	bge _08070AF2
	rsbs r4, r4, #0
_08070AF2:
	movs r0, #0x90
	lsls r0, r0, #9
	cmp r4, r0
	bgt _08070AFC
	b _08070C5A
_08070AFC:
	movs r1, #0
	movs r0, #4
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
	b _08070C5A
	.align 2, 0
_08070B08: .4byte pZero2
_08070B0C:
	movs r0, #0x18
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08070B16:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r1, [r5, #0x60]
	rsbs r0, r1, #0
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r3, r1, r0
	str r3, [r5, #0x60]
	ldr r1, [r5, #0x5c]
	rsbs r2, r1, #0
	movs r0, #0xb
	muls r0, r2, r0
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, _08070B6C @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	ldr r1, _08070B70 @ =0xFFFFEC00
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	subs r0, r1, r3
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl forceWaterLanding
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08070B62
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08070C5A
_08070B62:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08070C5A
	.align 2, 0
_08070B6C: .4byte pZero2
_08070B70: .4byte 0xFFFFEC00
_08070B74:
	ldr r1, _08070BF4 @ =0x00001801
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08070BF8 @ =0x08366A74
	bl SetDDP
	movs r0, #0xc
	strb r0, [r5, #0x12]
	movs r0, #2
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08070B94:
	ldr r1, [r5, #0x60]
	rsbs r0, r1, #0
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r3, r1, r0
	str r3, [r5, #0x60]
	ldr r1, [r5, #0x5c]
	rsbs r2, r1, #0
	movs r0, #0xb
	muls r0, r2, r0
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, _08070BFC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	ldr r1, _08070C00 @ =0xFFFFEC00
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	subs r0, r1, r3
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl forceWaterLanding
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08070BDA
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08070C54
_08070BDA:
	movs r0, #0xc
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _08070C54
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _08070C04
	strb r0, [r5, #0xe]
	b _08070C5A
	.align 2, 0
_08070BF4: .4byte 0x00001801
_08070BF8: .4byte 0x08366A74
_08070BFC: .4byte pZero2
_08070C00: .4byte 0xFFFFEC00
_08070C04:
	adds r0, r5, #0
	adds r0, #0xbc
	ldrb r1, [r0]
	movs r2, #1
	eors r1, r2
	strb r1, [r0]
	ldrb r2, [r0]
	cmp r2, #0
	beq _08070C1E
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08070C24
_08070C1E:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_08070C24:
	strb r0, [r5, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08070C60 @ =0x08366A44
	bl SetDDP
	ldr r1, _08070C64 @ =0x00001806
	adds r0, r5, #0
	bl SetMotion
_08070C54:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_08070C5A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08070C60: .4byte 0x08366A44
_08070C64: .4byte 0x00001806

	thumb_func_start FUN_08070c68
FUN_08070c68: @ 0x08070C68
	movs r0, #1
	bx lr

	thumb_func_start sharksealxMode4
sharksealxMode4: @ 0x08070C6C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xa
	bls _08070C78
	b _08070F2C
_08070C78:
	lsls r0, r0, #2
	ldr r1, _08070C84 @ =_08070C88
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08070C84: .4byte _08070C88
_08070C88: @ jump table
	.4byte _08070CB4 @ case 0
	.4byte _08070D1E @ case 1
	.4byte _08070D6C @ case 2
	.4byte _08070DA4 @ case 3
	.4byte _08070DC4 @ case 4
	.4byte _08070F2C @ case 5
	.4byte _08070F2C @ case 6
	.4byte _08070F2C @ case 7
	.4byte _08070F2C @ case 8
	.4byte _08070F2C @ case 9
	.4byte _08070E5C @ case 10
_08070CB4:
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08070CF0 @ =0x08366A44
	bl SetDDP
	movs r2, #0
	str r2, [r4, #0x60]
	str r2, [r4, #0x5c]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r1, [r0]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	bge _08070CF4
	movs r0, #0x20
	rsbs r0, r0, #0
	str r0, [r4, #0x64]
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #1
	bne _08070D0A
	strb r0, [r4, #0xf]
	b _08070D0C
	.align 2, 0
_08070CF0: .4byte 0x08366A44
_08070CF4:
	str r2, [r4, #0x5c]
	movs r0, #0x20
	str r0, [r4, #0x64]
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #0
	bne _08070D0A
	movs r0, #1
	strb r0, [r4, #0xf]
	b _08070D0C
_08070D0A:
	strb r2, [r4, #0xf]
_08070D0C:
	ldr r0, [r4, #0x58]
	str r0, [r4, #0x60]
	movs r1, #0
	movs r0, #0x28
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08070D1E:
	ldr r1, _08070D60 @ =gSineTable
	ldrb r2, [r4, #0x13]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r2, #4
	strb r2, [r4, #0x13]
	ldr r0, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl forceWaterLanding
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08070D52
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08070D52
	b _08070F2C
_08070D52:
	ldrb r0, [r4, #0xf]
	cmp r0, #1
	bne _08070D64
	ldrb r0, [r4, #0xe]
	adds r0, #2
	strb r0, [r4, #0xe]
	b _08070F2C
	.align 2, 0
_08070D60: .4byte gSineTable
_08070D64:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08070F2C
_08070D6C:
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r2, [r0]
	cmp r2, #0
	beq _08070D7E
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08070D84
_08070D7E:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08070D84:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	b _08070DEE
_08070DA4:
	ldr r1, _08070DF4 @ =0x00001801
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08070DF8 @ =0x08366A74
	bl SetDDP
	movs r0, #0xc
	strb r0, [r4, #0x12]
	movs r0, #2
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08070DC4:
	adds r0, r4, #0
	bl forceWaterLanding
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08070DDA
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08070E4C
_08070DDA:
	movs r0, #0xc
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _08070E4C
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08070DFC
_08070DEE:
	movs r0, #0xa
	strb r0, [r4, #0xe]
	b _08070F2C
	.align 2, 0
_08070DF4: .4byte 0x00001801
_08070DF8: .4byte 0x08366A74
_08070DFC:
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r1, [r0]
	movs r2, #1
	eors r1, r2
	strb r1, [r0]
	ldrb r2, [r0]
	cmp r2, #0
	beq _08070E16
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08070E1C
_08070E16:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08070E1C:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08070E54 @ =0x08366A44
	bl SetDDP
	ldr r1, _08070E58 @ =0x00001806
	adds r0, r4, #0
	bl SetMotion
_08070E4C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08070F2C
	.align 2, 0
_08070E54: .4byte 0x08366A44
_08070E58: .4byte 0x00001806
_08070E5C:
	ldr r1, [r4, #0x5c]
	ldr r0, [r4, #0x64]
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r1, r0
	bgt _08070E72
	ldr r0, _08070E88 @ =0xFFFFFE00
	cmp r1, r0
	bge _08070E74
_08070E72:
	str r0, [r4, #0x5c]
_08070E74:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x68]
	cmp r1, r0
	ble _08070E90
	ldr r2, _08070E8C @ =0xFFFFFF00
	b _08070E94
	.align 2, 0
_08070E88: .4byte 0xFFFFFE00
_08070E8C: .4byte 0xFFFFFF00
_08070E90:
	movs r2, #0x80
	lsls r2, r2, #1
_08070E94:
	adds r0, r1, r2
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl forceWaterLanding
	ldr r2, [r4, #0x5c]
	cmp r2, #0
	bge _08070EA6
	rsbs r2, r2, #0
_08070EA6:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r1, [r4, #0x54]
	ldr r6, [r0]
	subs r5, r1, r6
	adds r7, r0, #0
	adds r3, r1, #0
	cmp r5, #0
	ble _08070EBE
	cmp r5, r2
	ble _08070EC4
	b _08070ECA
_08070EBE:
	subs r0, r6, r3
	cmp r0, r2
	bgt _08070ECA
_08070EC4:
	movs r1, #0
	movs r0, #1
	b _08070F22
_08070ECA:
	ldr r1, [r7]
	subs r2, r3, r1
	cmp r2, #0
	ble _08070EDC
	movs r0, #0xa0
	lsls r0, r0, #8
	cmp r2, r0
	ble _08070EE6
	b _08070F26
_08070EDC:
	subs r1, r1, r3
	movs r0, #0xa0
	lsls r0, r0, #8
	cmp r1, r0
	bgt _08070F26
_08070EE6:
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #0
	bne _08070F00
	ldr r0, _08070EFC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	subs r1, r3, r0
	b _08070F08
	.align 2, 0
_08070EFC: .4byte pZero2
_08070F00:
	ldr r0, _08070F34 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	subs r1, r0, r3
_08070F08:
	ldr r0, _08070F38 @ =0x00007FFF
	cmp r1, r0
	bgt _08070F26
	adds r2, r4, #0
	adds r2, #0xb8
	ldr r0, [r7]
	subs r1, r3, r0
	cmp r1, #0
	bgt _08070F1C
	subs r1, r0, r3
_08070F1C:
	str r1, [r2]
	movs r1, #0
	movs r0, #2
_08070F22:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08070F26:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08070F2C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08070F34: .4byte pZero2
_08070F38: .4byte 0x00007FFF

	thumb_func_start FUN_08070f3c
FUN_08070f3c: @ 0x08070F3C
	movs r0, #1
	bx lr

	thumb_func_start sharksealxMode5
sharksealxMode5: @ 0x08070F40
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _08070F5A
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08070F84 @ =0x08366AA4
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08070F5A:
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08070F7C
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08070F88 @ =0x08366A44
	bl SetDDP
	movs r1, #0
	str r1, [r5]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08070F7C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08070F84: .4byte 0x08366AA4
_08070F88: .4byte 0x08366A44

	thumb_func_start FUN_08070f8c
FUN_08070f8c: @ 0x08070F8C
	movs r0, #1
	bx lr

	thumb_func_start nop_08070f90
nop_08070f90: @ 0x08070F90
	bx lr
	.align 2, 0

	thumb_func_start FUN_08070f94
FUN_08070f94: @ 0x08070F94
	movs r0, #1
	bx lr

	thumb_func_start sharksealxMode7
sharksealxMode7: @ 0x08070F98
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08070FA8
	cmp r5, #1
	beq _08070FBA
	b _08071004
_08070FA8:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08070FF4 @ =0x08366AA4
	bl SetDDP
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08070FBA:
	ldr r0, [r4, #0x60]
	adds r0, #0x10
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08070FCA
	str r1, [r4, #0x60]
_08070FCA:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08070FFC
	movs r0, #0
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	ldr r1, _08070FF8 @ =0xFFFFF000
	b _08071000
	.align 2, 0
_08070FF4: .4byte 0x08366AA4
_08070FF8: .4byte 0xFFFFF000
_08070FFC:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
_08071000:
	adds r0, r0, r1
	str r0, [r4, #0x58]
_08071004:
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08071026
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807102C @ =0x08366A44
	bl SetDDP
	movs r1, #0
	str r1, [r5]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08071026:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807102C: .4byte 0x08366A44

	thumb_func_start sharksealx_08071030
sharksealx_08071030: @ 0x08071030
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r6, [r5]
	cmp r6, #0
	beq _08071048
	b _080711C2
_08071048:
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08071056
	b _080711C2
_08071056:
	movs r0, #0x97
	adds r0, r0, r4
	mov r8, r0
	ldrb r1, [r0]
	movs r7, #0xf0
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0x20
	beq _0807106A
	b _08071194
_0807106A:
	ldr r5, [r4, #0x58]
	ldr r4, [r4, #0x54]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	bl CreateBubble
	ldr r1, _08071188 @ =RNG_0202f388
	mov sl, r1
	ldr r0, [r1]
	ldr r2, _0807118C @ =0x000343FD
	mov sb, r2
	mov r3, sb
	muls r3, r0, r3
	adds r0, r3, #0
	ldr r6, _08071190 @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	movs r2, #0xf
	mov r8, r2
	ands r0, r2
	subs r0, #8
	lsls r0, r0, #8
	adds r0, r0, r4
	adds r4, r0, #0
	mov r3, sb
	muls r3, r1, r3
	adds r1, r3, #0
	adds r1, r1, r6
	lsls r1, r1, #1
	lsrs r2, r1, #1
	mov r3, sl
	str r2, [r3]
	lsrs r1, r1, #0x11
	mov r2, r8
	ands r1, r2
	subs r1, #8
	lsls r1, r1, #8
	adds r1, r1, r5
	adds r5, r1, #0
	movs r2, #1
	bl CreateBubble
	mov r3, sl
	ldr r0, [r3]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	mov r2, r8
	ands r0, r2
	subs r0, #8
	lsls r0, r0, #8
	adds r0, r0, r4
	adds r4, r0, #0
	mov r3, sb
	muls r3, r1, r3
	adds r1, r3, #0
	adds r1, r1, r6
	lsls r1, r1, #1
	lsrs r2, r1, #1
	mov r3, sl
	str r2, [r3]
	lsrs r1, r1, #0x11
	mov r2, r8
	ands r1, r2
	subs r1, #8
	lsls r1, r1, #8
	adds r1, r1, r5
	adds r5, r1, #0
	movs r2, #1
	bl CreateBubble
	mov r3, sl
	ldr r0, [r3]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	mov r2, r8
	ands r0, r2
	subs r0, #8
	lsls r0, r0, #8
	adds r0, r0, r4
	adds r4, r0, #0
	mov r3, sb
	muls r3, r1, r3
	adds r1, r3, #0
	adds r1, r1, r6
	lsls r1, r1, #1
	lsrs r2, r1, #1
	mov r3, sl
	str r2, [r3]
	lsrs r1, r1, #0x11
	mov r2, r8
	ands r1, r2
	subs r1, #8
	lsls r1, r1, #8
	adds r1, r1, r5
	adds r5, r1, #0
	movs r2, #0
	bl CreateBubble
	mov r3, sl
	ldr r0, [r3]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	mov r2, r8
	ands r0, r2
	subs r0, #8
	lsls r0, r0, #8
	adds r0, r0, r4
	mov r3, sb
	muls r3, r1, r3
	adds r1, r3, #0
	adds r1, r1, r6
	lsls r1, r1, #1
	lsrs r2, r1, #1
	mov r3, sl
	str r2, [r3]
	lsrs r1, r1, #0x11
	mov r2, r8
	ands r1, r2
	subs r1, #8
	lsls r1, r1, #8
	adds r1, r1, r5
	movs r2, #0
	bl CreateBubble
	b _080711C2
	.align 2, 0
_08071188: .4byte RNG_0202f388
_0807118C: .4byte 0x000343FD
_08071190: .4byte 0x00269EC3
_08071194:
	ldr r2, _080711B4 @ =0x08366ABC
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r5]
	cmp r0, #0
	beq _080711C2
	mov r3, r8
	ldrb r0, [r3]
	adds r2, r7, #0
	ands r2, r0
	cmp r2, #0x10
	bne _080711B8
	movs r0, #5
	b _080711BE
	.align 2, 0
_080711B4: .4byte 0x08366ABC
_080711B8:
	cmp r2, #0x30
	bne _080711C2
	movs r0, #7
_080711BE:
	strb r0, [r4, #0xd]
	strb r6, [r4, #0xe]
_080711C2:
	movs r0, #1
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start nop_080711d4
nop_080711d4: @ 0x080711D4
	movs r0, #1
	bx lr

	thumb_func_start FUN_080711d8
FUN_080711d8: @ 0x080711D8
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, [r2, #0xc]
	ldr r0, [r0, #4]
	ldrb r0, [r0, #4]
	cmp r0, #3
	beq _080711F0
	cmp r0, #0xe
	beq _080711F0
	cmp r0, #0xf
	bne _0807121A
_080711F0:
	ldr r2, [r2, #0x2c]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0807121A
	ldr r1, [r2, #0x54]
	ldr r0, [r3]
	cmp r1, r0
	bge _08071212
	adds r1, r2, #0
	adds r1, #0xbf
	movs r0, #0xff
	b _08071218
_08071212:
	adds r1, r2, #0
	adds r1, #0xbf
	movs r0, #0xfe
_08071218:
	strb r0, [r1]
_0807121A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start forceWaterLanding
forceWaterLanding: @ 0x08071220
	push {lr}
	adds r3, r0, #0
	ldr r1, _08071238 @ =gOverworld
	ldr r2, _0807123C @ =0x0002C00C
	adds r1, r1, r2
	ldr r2, [r1]
	ldr r1, [r3, #0x58]
	cmp r2, r1
	ble _08071234
	str r2, [r3, #0x58]
_08071234:
	pop {r1}
	bx r1
	.align 2, 0
_08071238: .4byte gOverworld
_0807123C: .4byte 0x0002C00C
