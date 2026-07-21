	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start PantheonAqua_Die
PantheonAqua_Die: @ 0x08071F9C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldr r0, _08071FEC @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08071FF4
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
	ldr r1, _08071FF0 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _08072668
	.align 2, 0
_08071FEC: .4byte gCurStory
_08071FF0: .4byte gEnemyFnTable
_08071FF4:
	ldrb r0, [r7, #0xe]
	cmp r0, #0xd
	bls _08071FFC
	b _0807266A
_08071FFC:
	lsls r0, r0, #2
	ldr r1, _08072008 @ =_0807200C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08072008: .4byte _0807200C
_0807200C: @ jump table
	.4byte _08072044 @ case 0
	.4byte _08072092 @ case 1
	.4byte _0807209A @ case 2
	.4byte _0807210C @ case 3
	.4byte _08072214 @ case 4
	.4byte _0807266A @ case 5
	.4byte _0807266A @ case 6
	.4byte _0807266A @ case 7
	.4byte _0807266A @ case 8
	.4byte _0807266A @ case 9
	.4byte _08072092 @ case 10
	.4byte _080724B4 @ case 11
	.4byte _080724C2 @ case 12
	.4byte _08072590 @ case 13
_08072044:
	ldr r1, _0807206C @ =0x00002708
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
	beq _08072070
	movs r0, #0x80
	lsls r0, r0, #9
	ands r2, r0
	cmp r2, #0
	beq _08072070
	movs r0, #1
	b _08072072
	.align 2, 0
_0807206C: .4byte 0x00002708
_08072070:
	movs r0, #0xa
_08072072:
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
_08072092:
	adds r0, r7, #0
	bl UpdateEntityAnim
	b _080721F2
_0807209A:
	movs r0, #0
	str r0, [r7, #0x60]
	ldr r2, [r7, #0x54]
	str r2, [sp]
	ldr r3, [r7, #0x58]
	str r3, [sp, #4]
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r3, r1
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r0, #0xbb
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _080720DC
	cmp r0, #0xfe
	bne _080720D2
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
	b _080720FE
_080720D2:
	ldr r0, _080720EC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	cmp r0, r2
	ble _080720F0
_080720DC:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #1
	bl FUN_080b2b40
	b _080720FE
	.align 2, 0
_080720EC: .4byte pZero2
_080720F0:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
_080720FE:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #4
	bl TryDropItem
	movs r0, #1
	b _080721F0
_0807210C:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r3, _080721FC @ =RNG_0202f388
	mov r8, r3
	ldr r0, [r3]
	ldr r6, _08072200 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r3, _08072204 @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r5, r1, #1
	lsrs r1, r1, #0x11
	ldr r4, _08072208 @ =0x000007FF
	ands r1, r4
	ldr r0, [sp, #4]
	subs r0, r0, r1
	str r0, [sp, #4]
	ldr r2, [sp]
	ldr r0, _0807220C @ =0xFFFFFC00
	adds r2, r2, r0
	adds r0, r5, #0
	muls r0, r6, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r3, r8
	str r1, [r3]
	lsrs r0, r0, #0x11
	ands r0, r4
	adds r2, r2, r0
	str r2, [sp]
	mov r0, sp
	movs r1, #0
	bl FUN_080ba9f4
	mov r0, sp
	movs r1, #1
	bl FUN_080ba9f4
	mov r0, sp
	movs r1, #1
	bl FUN_080ba9f4
	ldr r0, [r7, #0x60]
	adds r0, #0x10
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08072178
	str r1, [r7, #0x60]
_08072178:
	ldr r1, [r7, #0x58]
	ldr r0, [r7, #0x60]
	adds r2, r1, r0
	str r2, [r7, #0x58]
	ldr r1, [r7, #0x5c]
	rsbs r0, r1, #0
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x5c]
	ldr r0, [r7, #0x54]
	adds r1, r0, r1
	str r1, [r7, #0x54]
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080721B2
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080721B2
	adds r0, r1, #0
	adds r1, r2, #0
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080721B2
	b _0807266A
_080721B2:
	adds r0, r7, #0
	adds r0, #0x54
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	ands r1, r2
	bl FUN_080ba7c8
	adds r0, r7, #0
	bl InitScalerotMotion1
	ldr r1, _08072210 @ =0x00002709
	adds r0, r7, #0
	bl SetMotion
	adds r1, r7, #0
	adds r1, #0x50
	movs r2, #0
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	strb r2, [r7, #0xf]
	adds r0, r7, #0
	adds r0, #0x24
	strb r2, [r0]
	adds r0, r7, #0
	bl UpdateEntityAnim
	movs r0, #0x44
_080721F0:
	strb r0, [r7, #0x12]
_080721F2:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _0807266A
	.align 2, 0
_080721FC: .4byte RNG_0202f388
_08072200: .4byte 0x000343FD
_08072204: .4byte 0x00269EC3
_08072208: .4byte 0x000007FF
_0807220C: .4byte 0xFFFFFC00
_08072210: .4byte 0x00002709
_08072214:
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	movs r1, #3
	mov sb, r1
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807223C
	ldrb r0, [r7, #0xf]
	subs r0, #1
	strb r0, [r7, #0xf]
	adds r1, r7, #0
	adds r1, #0x24
	strb r0, [r1]
_0807223C:
	ldrb r0, [r7, #0x13]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080722A6
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r3, _0807238C @ =RNG_0202f388
	mov r8, r3
	ldr r0, [r3]
	ldr r6, _08072390 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r3, _08072394 @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r5, r1, #1
	lsrs r1, r1, #0x11
	ldr r4, _08072398 @ =0x000007FF
	ands r1, r4
	ldr r0, [sp, #4]
	subs r0, r0, r1
	str r0, [sp, #4]
	ldr r2, [sp]
	ldr r0, _0807239C @ =0xFFFFFC00
	adds r2, r2, r0
	adds r0, r5, #0
	muls r0, r6, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r3, r8
	str r1, [r3]
	lsrs r0, r0, #0x11
	ands r0, r4
	adds r2, r2, r0
	str r2, [sp]
	mov r0, sp
	movs r1, #0
	bl FUN_080ba9f4
	mov r0, sp
	movs r1, #1
	bl FUN_080ba9f4
	mov r0, sp
	movs r1, #1
	bl FUN_080ba9f4
_080722A6:
	ldr r0, [r7, #0x60]
	adds r0, #4
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080722B6
	str r1, [r7, #0x60]
_080722B6:
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
	beq _080723C0
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r2, _0807238C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08072390 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _08072394 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	mov r1, sb
	ands r4, r1
	ldr r0, [r7, #0x54]
	str r0, [sp, #8]
	ldr r0, [r7, #0x58]
	add r5, sp, #8
	str r0, [r5, #4]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	movs r6, #1
	ands r1, r6
	ldr r2, _080723A0 @ =0x00002710
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r6
	ldr r2, _080723A4 @ =0x00002711
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r6
	ldr r2, _080723A8 @ =0x00002712
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r6
	ldr r2, _080723AC @ =0x00002713
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r6
	ldr r2, _080723B0 @ =0x00002714
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r6
	ldr r2, _080723B4 @ =0x00002715
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	movs r0, #0x31
	bl PlaySound
	ldr r2, _080723B8 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _080723BC @ =0x0000270E
	cmp r1, r0
	bhi _08072384
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08072384:
	adds r1, r7, #0
	adds r1, #0x54
	adds r0, r7, #0
	b _0807264C
	.align 2, 0
_0807238C: .4byte RNG_0202f388
_08072390: .4byte 0x000343FD
_08072394: .4byte 0x00269EC3
_08072398: .4byte 0x000007FF
_0807239C: .4byte 0xFFFFFC00
_080723A0: .4byte 0x00002710
_080723A4: .4byte 0x00002711
_080723A8: .4byte 0x00002712
_080723AC: .4byte 0x00002713
_080723B0: .4byte 0x00002714
_080723B4: .4byte 0x00002715
_080723B8: .4byte gScore
_080723BC: .4byte 0x0000270E
_080723C0:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _080723C8
	b _0807266A
_080723C8:
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080723D4
	b _0807266A
_080723D4:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r2, _08072488 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0807248C @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r3, _08072490 @ =0x00269EC3
	adds r4, r4, r3
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	mov r0, sb
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp, #0x10]
	ldr r0, [r7, #0x58]
	add r5, sp, #0x10
	str r0, [r5, #4]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	movs r6, #1
	ands r1, r6
	ldr r2, _08072494 @ =0x00002710
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r6
	ldr r2, _08072498 @ =0x00002711
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r6
	ldr r2, _0807249C @ =0x00002712
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r6
	ldr r2, _080724A0 @ =0x00002713
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r6
	ldr r2, _080724A4 @ =0x00002714
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r6
	ldr r2, _080724A8 @ =0x00002715
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	movs r0, #0x31
	bl PlaySound
	ldr r2, _080724AC @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _080724B0 @ =0x0000270E
	cmp r1, r0
	bhi _0807247E
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0807247E:
	adds r1, r7, #0
	adds r1, #0x54
	adds r0, r7, #0
	b _0807264C
	.align 2, 0
_08072488: .4byte RNG_0202f388
_0807248C: .4byte 0x000343FD
_08072490: .4byte 0x00269EC3
_08072494: .4byte 0x00002710
_08072498: .4byte 0x00002711
_0807249C: .4byte 0x00002712
_080724A0: .4byte 0x00002713
_080724A4: .4byte 0x00002714
_080724A8: .4byte 0x00002715
_080724AC: .4byte gScore
_080724B0: .4byte 0x0000270E
_080724B4:
	movs r0, #0
	str r0, [r7, #0x60]
	movs r0, #0x32
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080724C2:
	ldrb r1, [r7, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080724D4
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080724DA
_080724D4:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080724DA:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x60]
	adds r0, #4
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080724EC
	str r1, [r7, #0x60]
_080724EC:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldrb r0, [r7, #0x12]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807255E
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r1, _0807257C @ =RNG_0202f388
	mov r8, r1
	ldr r0, [r1]
	ldr r6, _08072580 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r3, _08072584 @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r5, r1, #1
	lsrs r1, r1, #0x11
	ldr r4, _08072588 @ =0x000007FF
	ands r1, r4
	ldr r0, [sp, #4]
	subs r0, r0, r1
	str r0, [sp, #4]
	ldr r2, [sp]
	ldr r0, _0807258C @ =0xFFFFFC00
	adds r2, r2, r0
	adds r0, r5, #0
	muls r0, r6, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r3, r8
	str r1, [r3]
	lsrs r0, r0, #0x11
	ands r0, r4
	adds r2, r2, r0
	str r2, [sp]
	mov r0, sp
	movs r1, #0
	bl FUN_080ba9f4
	mov r0, sp
	movs r1, #1
	bl FUN_080ba9f4
	mov r0, sp
	movs r1, #1
	bl FUN_080ba9f4
_0807255E:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _0807256E
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08072574
_0807256E:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08072574:
	adds r0, r7, #0
	bl UpdateEntityAnim
	b _0807266A
	.align 2, 0
_0807257C: .4byte RNG_0202f388
_08072580: .4byte 0x000343FD
_08072584: .4byte 0x00269EC3
_08072588: .4byte 0x000007FF
_0807258C: .4byte 0xFFFFFC00
_08072590:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x31
	bl PlaySound
	movs r0, #0x54
	adds r0, r0, r7
	mov r8, r0
	movs r0, #4
	mov r1, r8
	bl TryDropItem
	ldr r2, _08072678 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0807267C @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r1, _08072680 @ =0x00269EC3
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
	add r5, sp, #0x18
	str r0, [r5, #4]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	movs r6, #1
	ands r1, r6
	ldr r2, _08072684 @ =0x00002710
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r6
	ldr r2, _08072688 @ =0x00002711
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r6
	ldr r2, _0807268C @ =0x00002712
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r6
	ldr r2, _08072690 @ =0x00002713
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r6
	ldr r2, _08072694 @ =0x00002714
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r6
	ldr r2, _08072698 @ =0x00002715
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldr r2, _0807269C @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _080726A0 @ =0x0000270E
	cmp r1, r0
	bhi _08072648
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08072648:
	adds r0, r7, #0
	mov r1, r8
_0807264C:
	bl TryDropZakoDisk
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080726A4 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
_08072668:
	str r0, [r7, #0x14]
_0807266A:
	add sp, #0x20
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08072678: .4byte RNG_0202f388
_0807267C: .4byte 0x000343FD
_08072680: .4byte 0x00269EC3
_08072684: .4byte 0x00002710
_08072688: .4byte 0x00002711
_0807268C: .4byte 0x00002712
_08072690: .4byte 0x00002713
_08072694: .4byte 0x00002714
_08072698: .4byte 0x00002715
_0807269C: .4byte gScore
_080726A0: .4byte 0x0000270E
_080726A4: .4byte gEnemyFnTable

