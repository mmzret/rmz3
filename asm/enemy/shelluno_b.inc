	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Shelluno_Die
Shelluno_Die: @ 0x08078C2C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r7, r0, #0
	ldr r0, _08078C7C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08078C84
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
	ldr r1, _08078C80 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _08079362
	.align 2, 0
_08078C7C: .4byte gCurStory
_08078C80: .4byte gEnemyFnTable
_08078C84:
	ldrb r0, [r7, #0xe]
	cmp r0, #0xd
	bls _08078C8C
	b _08079364
_08078C8C:
	lsls r0, r0, #2
	ldr r1, _08078C98 @ =_08078C9C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08078C98: .4byte _08078C9C
_08078C9C: @ jump table
	.4byte _08078CD4 @ case 0
	.4byte _08078D22 @ case 1
	.4byte _08078D2A @ case 2
	.4byte _08078E54 @ case 3
	.4byte _08078F44 @ case 4
	.4byte _08079364 @ case 5
	.4byte _08079364 @ case 6
	.4byte _08079364 @ case 7
	.4byte _08079364 @ case 8
	.4byte _08079364 @ case 9
	.4byte _08078D22 @ case 10
	.4byte _08079154 @ case 11
	.4byte _08079162 @ case 12
	.4byte _08079220 @ case 13
_08078CD4:
	ldr r1, _08078CFC @ =0x00003504
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
	beq _08078D00
	movs r0, #0x80
	lsls r0, r0, #9
	ands r2, r0
	cmp r2, #0
	beq _08078D00
	movs r0, #1
	b _08078D02
	.align 2, 0
_08078CFC: .4byte 0x00003504
_08078D00:
	movs r0, #0xa
_08078D02:
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
_08078D22:
	adds r0, r7, #0
	bl UpdateEntityAnim
	b _08078F22
_08078D2A:
	movs r0, #0
	str r0, [r7, #0x60]
	ldr r2, [r7, #0x54]
	str r2, [sp]
	ldr r3, [r7, #0x58]
	str r3, [sp, #4]
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08078D54
	ldr r1, _08078D50 @ =0xFFFFF800
	adds r0, r2, r1
	str r0, [sp]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r3, r1
	b _08078D5E
	.align 2, 0
_08078D50: .4byte 0xFFFFF800
_08078D54:
	movs r0, #0x80
	lsls r0, r0, #4
	adds r1, r2, r0
	str r1, [sp]
	adds r0, r3, r0
_08078D5E:
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r0, #0xba
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _08078D88
	cmp r0, #0xfe
	bne _08078D7E
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
	b _08078DAA
_08078D7E:
	ldr r0, _08078D98 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	cmp r0, r2
	ble _08078D9C
_08078D88:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #1
	bl FUN_080b2b40
	b _08078DAA
	.align 2, 0
_08078D98: .4byte pZero2
_08078D9C:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
_08078DAA:
	ldr r1, [sp, #4]
	ldr r3, _08078E44 @ =0xFFFFF800
	adds r1, r1, r3
	str r1, [sp, #4]
	ldr r0, [sp]
	movs r2, #1
	bl CreateBubble
	ldr r3, _08078E48 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r6, _08078E4C @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r4, _08078E50 @ =0x00269EC3
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
	str r3, [sp, #0x24]
	bl CreateBubble
	ldr r3, [sp, #0x24]
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
	movs r0, #2
	bl TryDropItem
	movs r0, #1
	b _08078F20
	.align 2, 0
_08078E44: .4byte 0xFFFFF800
_08078E48: .4byte RNG_0202f388
_08078E4C: .4byte 0x000343FD
_08078E50: .4byte 0x00269EC3
_08078E54:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, _08078F2C @ =RNG_0202f388
	mov r8, r0
	ldr r0, [r0]
	ldr r6, _08078F30 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r3, _08078F34 @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r5, r1, #1
	lsrs r1, r1, #0x11
	ldr r4, _08078F38 @ =0x000007FF
	ands r1, r4
	ldr r0, [sp, #4]
	subs r0, r0, r1
	str r0, [sp, #4]
	ldr r2, [sp]
	ldr r1, _08078F3C @ =0xFFFFFC00
	adds r2, r2, r1
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
	ldr r0, [r7, #0x60]
	adds r0, #0x10
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08078EA8
	str r1, [r7, #0x60]
_08078EA8:
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
	beq _08078EE2
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08078EE2
	adds r0, r1, #0
	adds r1, r2, #0
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08078EE2
	b _08079364
_08078EE2:
	adds r0, r7, #0
	adds r0, #0x54
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	ands r1, r2
	bl FUN_080bcf68
	adds r0, r7, #0
	bl InitScalerotMotion1
	ldr r1, _08078F40 @ =0x00003504
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
_08078F20:
	strb r0, [r7, #0x12]
_08078F22:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _08079364
	.align 2, 0
_08078F2C: .4byte RNG_0202f388
_08078F30: .4byte 0x000343FD
_08078F34: .4byte 0x00269EC3
_08078F38: .4byte 0x000007FF
_08078F3C: .4byte 0xFFFFFC00
_08078F40: .4byte 0x00003504
_08078F44:
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
	bne _08078F6C
	ldrb r0, [r7, #0xf]
	subs r0, #1
	strb r0, [r7, #0xf]
	adds r1, r7, #0
	adds r1, #0x24
	strb r0, [r1]
_08078F6C:
	ldrb r0, [r7, #0x13]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08078FBE
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r3, _08079074 @ =RNG_0202f388
	mov r8, r3
	ldr r0, [r3]
	ldr r6, _08079078 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r3, _0807907C @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r5, r1, #1
	lsrs r1, r1, #0x11
	ldr r4, _08079080 @ =0x000007FF
	ands r1, r4
	ldr r0, [sp, #4]
	subs r0, r0, r1
	str r0, [sp, #4]
	ldr r2, [sp]
	ldr r0, _08079084 @ =0xFFFFFC00
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
_08078FBE:
	ldr r0, [r7, #0x60]
	adds r0, #4
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08078FCE
	str r1, [r7, #0x60]
_08078FCE:
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
	beq _0807909C
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r2, _08079074 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08079078 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _0807907C @ =0x00269EC3
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
	add r6, sp, #8
	str r0, [r6, #4]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	movs r5, #1
	ands r1, r5
	ldr r2, _08079088 @ =0x00003506
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080bcfbc
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	ldr r2, _0807908C @ =0x00003507
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080bcfbc
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	ldr r2, _08079090 @ =0x00003508
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080bcfbc
	movs r0, #0x31
	bl PlaySound
	ldr r2, _08079094 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _08079098 @ =0x0000270E
	cmp r1, r0
	bhi _0807906C
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0807906C:
	adds r1, r7, #0
	adds r1, #0x54
	adds r0, r7, #0
	b _08079346
	.align 2, 0
_08079074: .4byte RNG_0202f388
_08079078: .4byte 0x000343FD
_0807907C: .4byte 0x00269EC3
_08079080: .4byte 0x000007FF
_08079084: .4byte 0xFFFFFC00
_08079088: .4byte 0x00003506
_0807908C: .4byte 0x00003507
_08079090: .4byte 0x00003508
_08079094: .4byte gScore
_08079098: .4byte 0x0000270E
_0807909C:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _080790A4
	b _08079364
_080790A4:
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080790B0
	b _08079364
_080790B0:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r2, _08079134 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08079138 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r3, _0807913C @ =0x00269EC3
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
	add r6, sp, #0x10
	str r0, [r6, #4]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	movs r5, #1
	ands r1, r5
	ldr r2, _08079140 @ =0x00003506
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080bcfbc
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	ldr r2, _08079144 @ =0x00003507
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080bcfbc
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	ldr r2, _08079148 @ =0x00003508
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080bcfbc
	movs r0, #0x31
	bl PlaySound
	ldr r2, _0807914C @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _08079150 @ =0x0000270E
	cmp r1, r0
	bhi _0807912A
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0807912A:
	adds r1, r7, #0
	adds r1, #0x54
	adds r0, r7, #0
	b _08079346
	.align 2, 0
_08079134: .4byte RNG_0202f388
_08079138: .4byte 0x000343FD
_0807913C: .4byte 0x00269EC3
_08079140: .4byte 0x00003506
_08079144: .4byte 0x00003507
_08079148: .4byte 0x00003508
_0807914C: .4byte gScore
_08079150: .4byte 0x0000270E
_08079154:
	movs r0, #0
	str r0, [r7, #0x60]
	movs r0, #1
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08079162:
	ldrb r1, [r7, #0x12]
	movs r0, #1
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	beq _08079176
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	b _0807917C
_08079176:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0807917C:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x60]
	adds r0, #4
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807918E
	str r1, [r7, #0x60]
_0807918E:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldrb r0, [r7, #0x12]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080791E8
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r1, _0807920C @ =RNG_0202f388
	mov r8, r1
	ldr r0, [r1]
	ldr r6, _08079210 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r3, _08079214 @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r5, r1, #1
	lsrs r1, r1, #0x11
	ldr r4, _08079218 @ =0x000007FF
	ands r1, r4
	ldr r0, [sp, #4]
	subs r0, r0, r1
	str r0, [sp, #4]
	ldr r2, [sp]
	ldr r0, _0807921C @ =0xFFFFFC00
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
_080791E8:
	mov r1, sb
	lsls r0, r1, #0x18
	cmp r0, #0
	beq _080791FC
	mov r0, sb
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08079202
_080791FC:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08079202:
	adds r0, r7, #0
	bl UpdateEntityAnim
	b _08079364
	.align 2, 0
_0807920C: .4byte RNG_0202f388
_08079210: .4byte 0x000343FD
_08079214: .4byte 0x00269EC3
_08079218: .4byte 0x000007FF
_0807921C: .4byte 0xFFFFFC00
_08079220:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x31
	bl PlaySound
	adds r3, r7, #0
	adds r3, #0x54
	str r3, [sp, #0x20]
	movs r0, #2
	adds r1, r3, #0
	bl TryDropItem
	ldr r0, _08079374 @ =RNG_0202f388
	mov r8, r0
	ldr r0, [r0]
	ldr r1, _08079378 @ =0x000343FD
	mov sl, r1
	mov r4, sl
	muls r4, r0, r4
	ldr r3, _0807937C @ =0x00269EC3
	mov sb, r3
	add r4, sb
	lsls r4, r4, #1
	lsrs r0, r4, #1
	mov r1, r8
	str r0, [r1]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp, #0x18]
	ldr r0, [r7, #0x58]
	add r6, sp, #0x18
	str r0, [r6, #4]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	movs r5, #1
	ands r1, r5
	ldr r2, _08079380 @ =0x00003506
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080bcfbc
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	ldr r2, _08079384 @ =0x00003507
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080bcfbc
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	ldr r2, _08079388 @ =0x00003508
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080bcfbc
	ldr r1, [sp, #4]
	ldr r3, _0807938C @ =0xFFFFF800
	adds r1, r1, r3
	str r1, [sp, #4]
	ldr r0, [sp]
	movs r2, #1
	bl CreateBubble
	mov r1, r8
	ldr r0, [r1]
	mov r1, sl
	muls r1, r0, r1
	add r1, sb
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
	mov r3, sl
	muls r3, r2, r3
	adds r2, r3, #0
	add r2, sb
	lsls r2, r2, #1
	lsrs r1, r2, #1
	mov r3, r8
	str r1, [r3]
	lsrs r2, r2, #0x11
	ands r2, r4
	subs r2, #8
	lsls r2, r2, #8
	ldr r1, [sp, #4]
	adds r1, r1, r2
	str r1, [sp, #4]
	movs r2, #1
	bl CreateBubble
	mov r1, r8
	ldr r0, [r1]
	mov r1, sl
	muls r1, r0, r1
	add r1, sb
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsrs r1, r1, #0x11
	ands r1, r4
	subs r1, #8
	lsls r1, r1, #8
	ldr r0, [sp]
	adds r0, r0, r1
	str r0, [sp]
	mov r3, sl
	muls r3, r2, r3
	adds r2, r3, #0
	add r2, sb
	lsls r2, r2, #1
	lsrs r1, r2, #1
	mov r3, r8
	str r1, [r3]
	lsrs r2, r2, #0x11
	ands r2, r4
	subs r2, #8
	lsls r2, r2, #8
	ldr r1, [sp, #4]
	adds r1, r1, r2
	str r1, [sp, #4]
	movs r2, #0
	bl CreateBubble
	ldr r2, _08079390 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _08079394 @ =0x0000270E
	cmp r1, r0
	bhi _08079342
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08079342:
	adds r0, r7, #0
	ldr r1, [sp, #0x20]
_08079346:
	bl TryDropZakoDisk
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _08079398 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
_08079362:
	str r0, [r7, #0x14]
_08079364:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08079374: .4byte RNG_0202f388
_08079378: .4byte 0x000343FD
_0807937C: .4byte 0x00269EC3
_08079380: .4byte 0x00003506
_08079384: .4byte 0x00003507
_08079388: .4byte 0x00003508
_0807938C: .4byte 0xFFFFF800
_08079390: .4byte gScore
_08079394: .4byte 0x0000270E
_08079398: .4byte gEnemyFnTable
