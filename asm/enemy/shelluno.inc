	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateShelluno
CreateShelluno: @ 0x080789A0
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _080789F4 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080789EC
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _080789F8 @ =gEnemyFnTable
	movs r0, #0x1a
	strb r0, [r3, #9]
	ldr r0, [r1, #0x68]
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
_080789EC:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080789F4: .4byte gZakoHeaderPtr
_080789F8: .4byte gEnemyFnTable

	thumb_func_start Shelluno_Init
Shelluno_Init: @ 0x080789FC
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
	ldr r0, _08078A48 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x15]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08078A54
	ldr r0, _08078A4C @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08078A54
	movs r0, #4
	orrs r2, r0
	strb r2, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08078A50 @ =0x0836759C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #9
	b _08078A6C
	.align 2, 0
_08078A48: .4byte gSystemSavedataManager
_08078A4C: .4byte gCurStory
_08078A50: .4byte 0x0836759C
_08078A54:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08078A98 @ =0x0836759C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #5
_08078A6C:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldrb r2, [r6, #0x10]
	cmp r2, #0
	bne _08078A9C
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _08078ABE
	.align 2, 0
_08078A98: .4byte 0x0836759C
_08078A9C:
	movs r2, #1
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_08078ABE:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a05c
	str r0, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0xb9
	movs r5, #0
	strb r5, [r0]
	ldr r0, _08078B38 @ =FUN_0807a3ec
	str r0, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0x5c
	str r5, [r0, #4]
	str r5, [r6, #0x5c]
	adds r0, #8
	str r5, [r0, #4]
	str r5, [r6, #0x64]
	adds r0, #0x58
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	ldr r1, _08078B3C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r5, [r6, #0xd]
	strb r5, [r6, #0xe]
	strb r5, [r6, #0xf]
	adds r0, r6, #0
	bl isFrozen
	cmp r0, #0
	beq _08078B24
	movs r1, #0xd4
	lsls r1, r1, #6
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
_08078B24:
	adds r0, r6, #0
	adds r0, #0xba
	strb r5, [r0]
	adds r0, r6, #0
	bl Shelluno_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08078B38: .4byte FUN_0807a3ec
_08078B3C: .4byte gEnemyFnTable

	thumb_func_start Shelluno_Update
Shelluno_Update: @ 0x08078B40
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08078B5C
	adds r0, r4, #0
	bl FUN_0807a3e8
	cmp r0, #0
	bne _08078B7C
_08078B5C:
	ldr r1, _08078B78 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Shelluno_Die
	b _08078C20
	.align 2, 0
_08078B78: .4byte gEnemyFnTable
_08078B7C:
	ldr r0, _08078BB0 @ =0x0836756C
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_0807a244
	ldrb r0, [r4, #0xd]
	cmp r0, #2
	beq _08078BB4
	cmp r0, #4
	beq _08078BB4
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _08078BB4
	ldrb r1, [r4, #0xd]
	adds r0, r4, #0
	adds r0, #0xb8
	strb r1, [r0]
	b _08078C20
	.align 2, 0
_08078BB0: .4byte 0x0836756C
_08078BB4:
	ldr r0, _08078BF0 @ =gOverworld
	ldr r1, _08078BF4 @ =0x0002C00C
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, [r4, #0x58]
	ldr r2, _08078BF8 @ =0xFFFFFC00
	adds r0, r0, r2
	cmp r1, r0
	ble _08078BFC
	adds r1, r4, #0
	adds r1, #0xc2
	ldrb r0, [r1]
	cmp r0, #0
	bne _08078BD2
	str r0, [r4, #0x60]
_08078BD2:
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r4, #0x60]
	adds r0, #0x20
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08078BE6
	str r1, [r4, #0x60]
_08078BE6:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	b _08078C20
	.align 2, 0
_08078BF0: .4byte gOverworld
_08078BF4: .4byte 0x0002C00C
_08078BF8: .4byte 0xFFFFFC00
_08078BFC:
	adds r1, r4, #0
	adds r1, #0xc2
	ldrb r0, [r1]
	cmp r0, #1
	bne _08078C0C
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_08078C0C:
	movs r0, #0
	strb r0, [r1]
	ldr r1, _08078C28 @ =0x08367584
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_08078C20:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08078C28: .4byte 0x08367584

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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	ldr r2, _08079094 @ =gMission
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
_08079094: .4byte gMission
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
	ldr r2, _0807914C @ =gMission
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
_0807914C: .4byte gMission
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
	bl UpdateMotionGraphic
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
	ldr r2, _08079390 @ =gMission
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
_08079390: .4byte gMission
_08079394: .4byte 0x0000270E
_08079398: .4byte gEnemyFnTable

	thumb_func_start nop_0807939c
nop_0807939c: @ 0x0807939C
	movs r0, #1
	bx lr

	thumb_func_start shelluno_080793a0
shelluno_080793a0: @ 0x080793A0
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #0
	beq _080793B2
	cmp r4, #1
	beq _080793D8
	b _080795B0
_080793B2:
	adds r0, r5, #0
	adds r0, #0xc0
	strb r4, [r0]
	subs r0, #7
	strb r4, [r0]
	movs r1, #0xd4
	lsls r1, r1, #6
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807941C @ =0x0836759C
	bl SetDDP
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080793D8:
	ldr r0, [r5, #0x5c]
	rsbs r1, r0, #0
	lsls r1, r1, #4
	asrs r1, r1, #8
	adds r0, r0, r1
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	adds r0, #0x10
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080793F4
	str r1, [r5, #0x60]
_080793F4:
	ldr r2, [r5, #0x54]
	ldr r3, [r5, #0x5c]
	adds r2, r2, r3
	str r2, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r4, r2, #0
	ldr r1, _08079420 @ =0xFFFFF400
	adds r6, r0, r1
	cmp r3, #0
	bge _08079424
	adds r4, r4, r1
	adds r0, r4, #0
	adds r1, r6, #0
	bl PushoutToRight2
	b _08079432
	.align 2, 0
_0807941C: .4byte 0x0836759C
_08079420: .4byte 0xFFFFF400
_08079424:
	movs r3, #0xc0
	lsls r3, r3, #4
	adds r4, r4, r3
	adds r0, r4, #0
	adds r1, r6, #0
	bl PushoutToLeft2
_08079432:
	adds r1, r0, #0
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r6, [r5, #0x58]
	adds r4, r0, #0
	adds r1, r6, #0
	bl PushoutToUp2
	str r0, [sp]
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r4, r1
	adds r1, r6, #0
	bl PushoutToUp2
	str r0, [sp, #4]
	ldr r3, _08079484 @ =0xFFFFF400
	adds r0, r4, r3
	adds r1, r6, #0
	bl PushoutToUp2
	adds r1, r0, #0
	str r1, [sp, #8]
	ldr r0, [sp]
	cmp r0, #0
	bne _08079472
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _08079472
	cmp r1, #0
	beq _0807949C
_08079472:
	ldr r2, [sp]
	ldr r0, [sp, #4]
	cmp r2, r0
	bge _08079488
	ldr r1, [sp, #8]
	cmp r2, r1
	bge _08079490
	adds r1, r2, #0
	b _08079490
	.align 2, 0
_08079484: .4byte 0xFFFFF400
_08079488:
	ldr r1, [sp, #8]
	cmp r0, r1
	bge _08079490
	adds r1, r0, #0
_08079490:
	movs r0, #0
	str r0, [r5, #0x5c]
	str r0, [r5, #0x60]
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
_0807949C:
	adds r0, r5, #0
	bl FUN_0807a46c
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r2, r5, #0
	adds r2, #0xc1
	ldrb r0, [r2]
	cmp r0, #0
	beq _080794BE
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080794BE
	b _080795B0
_080794BE:
	ldr r0, _080794EC @ =gOverworld
	ldr r1, _080794F0 @ =0x0002C00C
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r3, _080794F4 @ =0xFFFFF400
	adds r1, r1, r3
	ldr r0, [r0]
	cmp r0, r1
	bge _080795AC
	ldr r0, _080794F8 @ =pZero2
	ldr r1, [r0]
	ldr r2, [r1, #0x54]
	ldr r3, [r5, #0x54]
	adds r4, r0, #0
	cmp r3, r2
	bge _080794FC
	ldrb r1, [r1, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08079514
	movs r1, #0
	b _0807950E
	.align 2, 0
_080794EC: .4byte gOverworld
_080794F0: .4byte 0x0002C00C
_080794F4: .4byte 0xFFFFF400
_080794F8: .4byte pZero2
_080794FC:
	cmp r3, r2
	ble _08079514
	ldrb r1, [r1, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08079514
_0807950E:
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_08079514:
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	bne _080795B0
	ldr r0, [r4]
	ldr r0, [r0, #0x54]
	subs r1, r0, r3
	cmp r1, #0
	ble _08079530
	ldr r0, _0807952C @ =0x00004FFF
	cmp r1, r0
	ble _08079538
	b _08079570
	.align 2, 0
_0807952C: .4byte 0x00004FFF
_08079530:
	subs r1, r3, r0
	ldr r0, _08079560 @ =0x00004FFF
	cmp r1, r0
	bgt _08079570
_08079538:
	ldr r2, _08079564 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08079568 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0807956C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x64
	bl __umodsi3
	adds r2, r0, #0
	cmp r2, #0
	bne _080795B0
	adds r0, r5, #0
	adds r0, #0xc0
	movs r1, #0x3c
	b _08079596
	.align 2, 0
_08079560: .4byte 0x00004FFF
_08079564: .4byte RNG_0202f388
_08079568: .4byte 0x000343FD
_0807956C: .4byte 0x00269EC3
_08079570:
	ldr r2, _080795A0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080795A4 @ =0x000343FD
	muls r0, r1, r0
	ldr r3, _080795A8 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xc8
	bl __umodsi3
	adds r2, r0, #0
	cmp r2, #0
	bne _080795B0
	adds r0, r5, #0
	adds r0, #0xc0
	movs r1, #0x32
_08079596:
	strb r1, [r0]
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r2, [r5, #0xe]
	b _080795B0
	.align 2, 0
_080795A0: .4byte RNG_0202f388
_080795A4: .4byte 0x000343FD
_080795A8: .4byte 0x00269EC3
_080795AC:
	movs r0, #0x3c
	strb r0, [r2]
_080795B0:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080795b8
FUN_080795b8: @ 0x080795B8
	push {lr}
	adds r2, r0, #0
	ldr r0, _080795E4 @ =gOverworld
	ldr r1, _080795E8 @ =0x0002C00C
	adds r0, r0, r1
	ldr r1, [r2, #0x58]
	ldr r3, _080795EC @ =0xFFFFF400
	adds r1, r1, r3
	ldr r0, [r0]
	cmp r0, r1
	ble _080795DE
	adds r3, r2, #0
	adds r3, #0xc1
	movs r1, #0
	movs r0, #0x3c
	strb r0, [r3]
	str r1, [r2, #0x60]
	strb r1, [r2, #0xd]
	strb r1, [r2, #0xe]
_080795DE:
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
_080795E4: .4byte gOverworld
_080795E8: .4byte 0x0002C00C
_080795EC: .4byte 0xFFFFF400

	thumb_func_start FUN_080795f0
FUN_080795f0: @ 0x080795F0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #4
	bls _08079606
	bl _0807A004
_08079606:
	lsls r0, r0, #2
	ldr r1, _08079610 @ =_08079614
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08079610: .4byte _08079614
_08079614: @ jump table
	.4byte _08079628 @ case 0
	.4byte _0807965E @ case 1
	.4byte _080796D8 @ case 2
	.4byte _08079D58 @ case 3
	.4byte _08079D7C @ case 4
_08079628:
	adds r1, r7, #0
	adds r1, #0xb9
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _080796C8 @ =0x083675CC
	bl SetDDP
	str r4, [r7, #0x5c]
	str r4, [r7, #0x60]
	ldr r0, [r7, #0x58]
	ldr r1, _080796CC @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r7, #0x68]
	movs r0, #8
	strb r0, [r7, #0x12]
	movs r0, #0x14
	strb r0, [r7, #0x13]
	ldr r1, _080796D0 @ =0x00003501
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0807965E:
	ldr r0, [r7, #0x68]
	ldr r1, [r7, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x58]
	ldr r0, [r7, #0x54]
	ldr r2, _080796D4 @ =0xFFFFE800
	adds r1, r1, r2
	bl PushoutToDown2
	adds r1, r0, #0
	cmp r1, #0
	beq _08079682
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
_08079682:
	adds r0, r7, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _080796A2
	cmp r0, #1
	bne _080796A8
	adds r0, r7, #0
	adds r0, #0x72
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bgt _080796A8
_080796A2:
	adds r0, r7, #0
	bl UpdateMotionGraphic
_080796A8:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _080796B2
	bl _0807A004
_080796B2:
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080796C0
	bl _0807A004
_080796C0:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	bl _0807A002
	.align 2, 0
_080796C8: .4byte 0x083675CC
_080796CC: .4byte 0xFFFFF000
_080796D0: .4byte 0x00003501
_080796D4: .4byte 0xFFFFE800
_080796D8:
	ldr r0, _08079724 @ =pZero2
	ldr r1, [r0]
	ldr r2, [r1, #0x54]
	ldr r0, [r7, #0x54]
	subs r2, r2, r0
	adds r5, r2, #0
	ldr r0, [r7, #0x58]
	ldr r3, _08079728 @ =0xFFFFF000
	adds r0, r0, r3
	ldr r1, [r1, #0x58]
	subs r1, r1, r0
	adds r6, r1, #0
	cmp r2, #0
	bne _080796F8
	cmp r1, #0
	beq _0807972C
_080796F8:
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r6, #0
	muls r1, r6, r1
	adds r0, r0, r1
	bl Sqrt
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r0, r5, #8
	adds r1, r4, #0
	bl __divsi3
	adds r5, r0, #0
	lsls r0, r6, #8
	adds r1, r4, #0
	bl __divsi3
	adds r6, r0, #0
	b _08079730
	.align 2, 0
_08079724: .4byte pZero2
_08079728: .4byte 0xFFFFF000
_0807972C:
	movs r5, #0x80
	lsls r5, r5, #1
_08079730:
	lsls r0, r5, #9
	asrs r3, r0, #8
	str r3, [r7, #0x64]
	lsls r0, r6, #9
	asrs r2, r0, #8
	str r2, [r7, #0x68]
	adds r0, r7, #0
	adds r0, #0xb9
	ldrb r1, [r0]
	mov sb, r0
	cmp r1, #1
	bne _080797B6
	ldr r1, [r7, #0x5c]
	subs r0, r3, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x5c]
	ldr r1, [r7, #0x60]
	subs r0, r2, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r5, r1, r0
	str r5, [r7, #0x60]
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	ldrb r4, [r7, #0x12]
	adds r0, r4, #0
	movs r1, #0x14
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08079784
	adds r0, r4, #0
	movs r1, #0x1e
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08079790
_08079784:
	ldr r1, _0807978C @ =0xFFFFFEE0
	adds r0, r5, r1
	str r0, [r7, #0x60]
	b _080797D2
	.align 2, 0
_0807978C: .4byte 0xFFFFFEE0
_08079790:
	adds r0, r4, #0
	movs r1, #0x46
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080797AC
	adds r0, r4, #0
	movs r1, #0x5a
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080797D2
_080797AC:
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r5, r2
	str r0, [r7, #0x60]
	b _080797D2
_080797B6:
	ldr r0, [r7, #0x5c]
	rsbs r1, r0, #0
	lsls r1, r1, #4
	asrs r1, r1, #8
	adds r0, r0, r1
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x60]
	adds r0, #0x10
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080797D2
	str r1, [r7, #0x60]
_080797D2:
	ldr r0, [r7, #0x58]
	ldr r3, _080797E8 @ =0xFFFFF400
	adds r4, r0, r3
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	cmp r1, #0
	bge _080797EC
	adds r1, r0, r3
	b _080797F2
	.align 2, 0
_080797E8: .4byte 0xFFFFF400
_080797EC:
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r0, r2
_080797F2:
	adds r0, r1, #0
	adds r1, r4, #0
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	movs r1, #0xf0
	lsls r1, r1, #0xc
	ands r1, r0
	lsrs r1, r1, #0x10
	cmp r1, #1
	bne _08079890
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	bge _08079820
	ldr r0, [r7, #0x54]
	ldr r3, _0807981C @ =0xFFFFF400
	adds r0, r0, r3
	adds r1, r4, #0
	bl PushoutToRight2
	b _0807982E
	.align 2, 0
_0807981C: .4byte 0xFFFFF400
_08079820:
	ldr r0, [r7, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r1, r4, #0
	bl PushoutToLeft2
_0807982E:
	adds r1, r0, #0
	cmp r1, #0
	beq _0807983A
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x54]
_0807983A:
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	bge _08079870
	ldr r2, _08079864 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08079868 @ =0x000343FD
	muls r0, r1, r0
	ldr r3, _0807986C @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x60
	bl __umodsi3
	movs r1, #0xc0
	lsls r1, r1, #1
	subs r1, r1, r0
	str r1, [r7, #0x5c]
	b _08079890
	.align 2, 0
_08079864: .4byte RNG_0202f388
_08079868: .4byte 0x000343FD
_0807986C: .4byte 0x00269EC3
_08079870:
	ldr r2, _080798E8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080798EC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080798F0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x60
	bl __umodsi3
	ldr r2, _080798F4 @ =0xFFFFFE80
	adds r0, r0, r2
	str r0, [r7, #0x5c]
_08079890:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r4, _080798F8 @ =0xFFFFF800
	adds r1, r1, r4
	bl FUN_0800a05c
	str r0, [sp]
	ldr r0, [r7, #0x54]
	movs r3, #0xc0
	lsls r3, r3, #4
	adds r0, r0, r3
	ldr r1, [r7, #0x58]
	adds r1, r1, r4
	bl FUN_0800a05c
	str r0, [sp, #4]
	ldr r0, [r7, #0x54]
	ldr r1, _080798FC @ =0xFFFFF400
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	adds r1, r1, r4
	bl FUN_0800a05c
	adds r1, r0, #0
	str r1, [sp, #8]
	movs r2, #0
	ldr r0, [sp]
	cmp r0, #0
	bne _080798D4
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _080798D4
	cmp r1, #0
	beq _08079908
_080798D4:
	ldr r1, [sp]
	ldr r0, [sp, #4]
	cmp r1, r0
	bge _08079900
	ldr r2, [sp, #8]
	cmp r1, r2
	bge _08079908
	adds r2, r1, #0
	b _08079908
	.align 2, 0
_080798E8: .4byte RNG_0202f388
_080798EC: .4byte 0x000343FD
_080798F0: .4byte 0x00269EC3
_080798F4: .4byte 0xFFFFFE80
_080798F8: .4byte 0xFFFFF800
_080798FC: .4byte 0xFFFFF400
_08079900:
	ldr r2, [sp, #8]
	cmp r0, r2
	bge _08079908
	adds r2, r0, #0
_08079908:
	ldr r0, [r7, #0x58]
	subs r0, r2, r0
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08079934
	ldr r0, [r7, #0x60]
	cmp r0, r1
	ble _0807991C
	str r1, [r7, #0x60]
_0807991C:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r3, _08079930 @ =0xFFFFF400
	adds r1, r2, r3
	cmp r0, r1
	ble _0807993A
	str r1, [r7, #0x58]
	b _0807993A
	.align 2, 0
_08079930: .4byte 0xFFFFF400
_08079934:
	ldr r1, _0807998C @ =0xFFFFF400
	adds r0, r2, r1
	str r0, [r7, #0x58]
_0807993A:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r6, _08079990 @ =0xFFFFE800
	adds r1, r1, r6
	bl PushoutToDown2
	adds r4, r0, #0
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	subs r1, #0x10
	bl PushoutToUp2
	adds r5, r0, #0
	cmp r4, #0
	bne _0807995C
	cmp r5, #0
	beq _080799B4
_0807995C:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r2, _08079994 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_0800a05c
	adds r5, r0, #0
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	adds r1, r1, r6
	bl FUN_0800a134
	adds r4, r0, #0
	ldr r0, [r7, #0x58]
	subs r1, r0, r4
	cmp r1, #0
	bgt _08079980
	subs r1, r4, r0
_08079980:
	subs r2, r0, r5
	cmp r2, #0
	ble _08079998
	cmp r1, r2
	blt _0807999E
	b _080799A8
	.align 2, 0
_0807998C: .4byte 0xFFFFF400
_08079990: .4byte 0xFFFFE800
_08079994: .4byte 0xFFFFF800
_08079998:
	subs r0, r5, r0
	cmp r1, r0
	bge _080799A8
_0807999E:
	movs r3, #0xc0
	lsls r3, r3, #5
	adds r0, r4, r3
	str r0, [r7, #0x58]
	b _080799B4
_080799A8:
	ldr r0, _08079A14 @ =0xFFFFF400
	adds r1, r5, r0
	ldr r0, [r7, #0x58]
	cmp r0, r1
	ble _080799B4
	str r1, [r7, #0x58]
_080799B4:
	ldr r0, [r7, #0x54]
	movs r6, #0xc0
	lsls r6, r6, #4
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	ldr r2, _08079A18 @ =0xFFFFE800
	mov r8, r2
	add r1, r8
	bl PushoutToDown2
	adds r4, r0, #0
	ldr r0, [r7, #0x54]
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	subs r1, #0x10
	bl PushoutToUp2
	adds r5, r0, #0
	cmp r4, #0
	bne _080799E0
	cmp r5, #0
	beq _08079A3C
_080799E0:
	ldr r0, [r7, #0x54]
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	ldr r3, _08079A1C @ =0xFFFFF800
	adds r1, r1, r3
	bl FUN_0800a05c
	adds r5, r0, #0
	ldr r0, [r7, #0x54]
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	add r1, r8
	bl FUN_0800a134
	adds r4, r0, #0
	ldr r0, [r7, #0x58]
	subs r1, r0, r4
	cmp r1, #0
	bgt _08079A08
	subs r1, r4, r0
_08079A08:
	subs r2, r0, r5
	cmp r2, #0
	ble _08079A20
	cmp r1, r2
	blt _08079A26
	b _08079A30
	.align 2, 0
_08079A14: .4byte 0xFFFFF400
_08079A18: .4byte 0xFFFFE800
_08079A1C: .4byte 0xFFFFF800
_08079A20:
	subs r0, r5, r0
	cmp r1, r0
	bge _08079A30
_08079A26:
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r4, r1
	str r0, [r7, #0x58]
	b _08079A3C
_08079A30:
	ldr r2, _08079A9C @ =0xFFFFF400
	adds r1, r5, r2
	ldr r0, [r7, #0x58]
	cmp r0, r1
	ble _08079A3C
	str r1, [r7, #0x58]
_08079A3C:
	ldr r0, [r7, #0x54]
	ldr r6, _08079A9C @ =0xFFFFF400
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	ldr r3, _08079AA0 @ =0xFFFFE800
	mov r8, r3
	add r1, r8
	bl PushoutToDown2
	adds r4, r0, #0
	ldr r0, [r7, #0x54]
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	subs r1, #0x10
	bl PushoutToUp2
	adds r5, r0, #0
	cmp r4, #0
	bne _08079A66
	cmp r5, #0
	beq _08079AC4
_08079A66:
	ldr r0, [r7, #0x54]
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	ldr r2, _08079AA4 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_0800a05c
	adds r5, r0, #0
	ldr r0, [r7, #0x54]
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	add r1, r8
	bl FUN_0800a134
	adds r4, r0, #0
	ldr r0, [r7, #0x58]
	subs r1, r0, r4
	cmp r1, #0
	bgt _08079A8E
	subs r1, r4, r0
_08079A8E:
	subs r2, r0, r5
	cmp r2, #0
	ble _08079AA8
	cmp r1, r2
	blt _08079AAE
	b _08079AB8
	.align 2, 0
_08079A9C: .4byte 0xFFFFF400
_08079AA0: .4byte 0xFFFFE800
_08079AA4: .4byte 0xFFFFF800
_08079AA8:
	subs r0, r5, r0
	cmp r1, r0
	bge _08079AB8
_08079AAE:
	movs r3, #0xc0
	lsls r3, r3, #5
	adds r0, r4, r3
	str r0, [r7, #0x58]
	b _08079AC4
_08079AB8:
	ldr r0, _08079AD4 @ =0xFFFFF400
	adds r1, r5, r0
	ldr r0, [r7, #0x58]
	cmp r0, r1
	ble _08079AC4
	str r1, [r7, #0x58]
_08079AC4:
	ldr r4, [r7, #0x58]
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	bge _08079AD8
	ldr r0, [r7, #0x54]
	ldr r2, _08079AD4 @ =0xFFFFF400
	adds r1, r0, r2
	b _08079AE0
	.align 2, 0
_08079AD4: .4byte 0xFFFFF400
_08079AD8:
	ldr r0, [r7, #0x54]
	movs r3, #0xc0
	lsls r3, r3, #4
	adds r1, r0, r3
_08079AE0:
	adds r0, r1, #0
	adds r1, r4, #0
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	movs r1, #0xf0
	lsls r1, r1, #0xc
	ands r1, r0
	lsrs r1, r1, #0x10
	cmp r1, #1
	bne _08079B2A
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	bge _08079B10
	ldr r0, [r7, #0x54]
	ldr r1, _08079B0C @ =0xFFFFF400
	adds r0, r0, r1
	adds r1, r4, #0
	bl PushoutToRight2
	b _08079B1E
	.align 2, 0
_08079B0C: .4byte 0xFFFFF400
_08079B10:
	ldr r0, [r7, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r1, r4, #0
	bl PushoutToLeft2
_08079B1E:
	adds r1, r0, #0
	cmp r1, #0
	beq _08079B2A
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x54]
_08079B2A:
	ldr r1, _08079B58 @ =pZero2
	ldr r0, [r1]
	ldr r2, [r7, #0x54]
	ldr r0, [r0, #0x54]
	adds r4, r1, #0
	cmp r2, r0
	ble _08079B5C
	movs r2, #0
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r7, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _08079B7E
	.align 2, 0
_08079B58: .4byte pZero2
_08079B5C:
	movs r2, #1
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_08079B7E:
	mov r3, sb
	ldrb r0, [r3]
	cmp r0, #0
	bne _08079BF0
	ldrb r0, [r7, #0x13]
	subs r0, #1
	strb r0, [r7, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08079C54
	movs r0, #1
	strb r0, [r3]
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _08079BB8 @ =0x083675CC
	bl SetDDP
	ldr r0, _08079BBC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r7, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	ble _08079BC4
	ldr r0, _08079BC0 @ =0x00003BFF
	cmp r2, r0
	ble _08079BCC
	b _08079BE0
	.align 2, 0
_08079BB8: .4byte 0x083675CC
_08079BBC: .4byte pZero2
_08079BC0: .4byte 0x00003BFF
_08079BC4:
	subs r1, r1, r0
	ldr r0, _08079BD8 @ =0x00003BFF
	cmp r1, r0
	bgt _08079BE0
_08079BCC:
	ldr r1, _08079BDC @ =0x00003501
	adds r0, r7, #0
	bl SetMotion
	b _08079C54
	.align 2, 0
_08079BD8: .4byte 0x00003BFF
_08079BDC: .4byte 0x00003501
_08079BE0:
	ldr r1, _08079BEC @ =0x0000350A
	adds r0, r7, #0
	bl SetMotion
	b _08079C54
	.align 2, 0
_08079BEC: .4byte 0x0000350A
_08079BF0:
	cmp r0, #1
	beq _08079BF6
	b _08079CF0
_08079BF6:
	ldrb r3, [r7, #0x1e]
	lsls r1, r3, #8
	adds r2, r7, #0
	adds r2, #0x70
	ldrb r0, [r2]
	orrs r1, r0
	ldr r0, _08079C5C @ =0x00003501
	cmp r1, r0
	bne _08079C28
	adds r0, r7, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _08079C54
	cmp r0, #1
	bne _08079C28
	adds r0, r7, #0
	adds r0, #0x72
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	ble _08079C54
_08079C28:
	lsls r0, r3, #8
	ldrb r1, [r2]
	orrs r0, r1
	ldr r1, _08079C60 @ =0x0000350A
	cmp r0, r1
	bne _08079C64
	adds r0, r7, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _08079C54
	cmp r0, #1
	bne _08079C64
	adds r0, r7, #0
	adds r0, #0x72
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08079C64
_08079C54:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	b _08079CF6
	.align 2, 0
_08079C5C: .4byte 0x00003501
_08079C60: .4byte 0x0000350A
_08079C64:
	ldr r0, [r4]
	ldr r0, [r0, #0x54]
	ldr r1, [r7, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	ble _08079C7C
	ldr r0, _08079C78 @ =0x00003BFF
	cmp r2, r0
	ble _08079C84
	b _08079CBC
	.align 2, 0
_08079C78: .4byte 0x00003BFF
_08079C7C:
	subs r1, r1, r0
	ldr r0, _08079CAC @ =0x00003BFF
	cmp r1, r0
	bgt _08079CBC
_08079C84:
	ldr r2, _08079CB0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08079CB4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08079CB8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x12
	bl __umodsi3
	cmp r0, #0
	bne _08079CF6
	mov r2, sb
	strb r0, [r2]
	movs r0, #0xe
	strb r0, [r7, #0x13]
	b _08079CF6
	.align 2, 0
_08079CAC: .4byte 0x00003BFF
_08079CB0: .4byte RNG_0202f388
_08079CB4: .4byte 0x000343FD
_08079CB8: .4byte 0x00269EC3
_08079CBC:
	ldr r2, _08079CE4 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08079CE8 @ =0x000343FD
	muls r0, r1, r0
	ldr r3, _08079CEC @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r1, r0, #0x11
	movs r0, #7
	ands r1, r0
	cmp r1, #0
	bne _08079CF6
	mov r0, sb
	strb r1, [r0]
	movs r0, #0xb
	strb r0, [r7, #0x13]
	b _08079CF6
	.align 2, 0
_08079CE4: .4byte RNG_0202f388
_08079CE8: .4byte 0x000343FD
_08079CEC: .4byte 0x00269EC3
_08079CF0:
	adds r0, r7, #0
	bl UpdateMotionGraphic
_08079CF6:
	adds r0, r7, #0
	bl FUN_0807a46c
	adds r1, r7, #0
	adds r1, #0xc0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08079D12
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08079D12
	b _0807A004
_08079D12:
	ldr r0, _08079D38 @ =pZero2
	ldr r0, [r0]
	ldr r2, [r7, #0x54]
	ldr r1, [r0, #0x54]
	cmp r2, r1
	bge _08079D3C
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _08079D2E
	b _0807A004
_08079D2E:
	str r0, [r7, #0x60]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	b _0807A002
	.align 2, 0
_08079D38: .4byte pZero2
_08079D3C:
	cmp r2, r1
	bgt _08079D42
	b _0807A004
_08079D42:
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08079D4E
	b _0807A004
_08079D4E:
	movs r0, #0
	str r0, [r7, #0x60]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	b _0807A002
_08079D58:
	adds r1, r7, #0
	adds r1, #0xb9
	movs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _08079DC0 @ =0x083675CC
	bl SetDDP
	movs r0, #0x10
	strb r0, [r7, #0x12]
	ldr r1, _08079DC4 @ =0x00003501
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08079D7C:
	ldr r0, [r7, #0x5c]
	rsbs r1, r0, #0
	lsls r1, r1, #4
	asrs r1, r1, #8
	adds r0, r0, r1
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x60]
	adds r0, #0x10
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08079D98
	str r1, [r7, #0x60]
_08079D98:
	ldr r2, [r7, #0x54]
	ldr r3, [r7, #0x5c]
	adds r2, r2, r3
	str r2, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r4, r2, #0
	ldr r1, _08079DC8 @ =0xFFFFF400
	adds r5, r0, r1
	cmp r3, #0
	bge _08079DCC
	adds r4, r4, r1
	adds r0, r4, #0
	adds r1, r5, #0
	bl PushoutToRight2
	b _08079DDA
	.align 2, 0
_08079DC0: .4byte 0x083675CC
_08079DC4: .4byte 0x00003501
_08079DC8: .4byte 0xFFFFF400
_08079DCC:
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r4, r4, r2
	adds r0, r4, #0
	adds r1, r5, #0
	bl PushoutToLeft2
_08079DDA:
	adds r1, r0, #0
	cmp r1, #0
	beq _08079DE6
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x54]
_08079DE6:
	ldr r5, [r7, #0x58]
	ldr r4, [r7, #0x54]
	adds r0, r4, #0
	adds r1, r5, #0
	bl PushoutToUp2
	str r0, [sp]
	movs r3, #0xc0
	lsls r3, r3, #4
	adds r0, r4, r3
	adds r1, r5, #0
	bl PushoutToUp2
	str r0, [sp, #4]
	ldr r1, _08079E34 @ =0xFFFFF400
	adds r0, r4, r1
	adds r1, r5, #0
	bl PushoutToUp2
	adds r1, r0, #0
	str r1, [sp, #8]
	ldr r0, [sp]
	cmp r0, #0
	bne _08079E20
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _08079E20
	cmp r1, #0
	beq _08079E4C
_08079E20:
	ldr r2, [sp]
	ldr r0, [sp, #4]
	cmp r2, r0
	bge _08079E38
	ldr r1, [sp, #8]
	cmp r2, r1
	bge _08079E40
	adds r1, r2, #0
	b _08079E40
	.align 2, 0
_08079E34: .4byte 0xFFFFF400
_08079E38:
	ldr r1, [sp, #8]
	cmp r0, r1
	bge _08079E40
	adds r1, r0, #0
_08079E40:
	movs r0, #0
	str r0, [r7, #0x5c]
	str r0, [r7, #0x60]
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
_08079E4C:
	adds r0, r7, #0
	bl FUN_0807a46c
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r6, _08079EA4 @ =0xFFFFE800
	adds r1, r1, r6
	bl PushoutToDown2
	adds r4, r0, #0
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	subs r1, #0x10
	bl PushoutToUp2
	adds r5, r0, #0
	cmp r4, #0
	bne _08079E74
	cmp r5, #0
	beq _08079EC8
_08079E74:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r2, _08079EA8 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_0800a05c
	adds r5, r0, #0
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	adds r1, r1, r6
	bl FUN_0800a134
	adds r4, r0, #0
	ldr r0, [r7, #0x58]
	subs r1, r0, r4
	cmp r1, #0
	bgt _08079E98
	subs r1, r4, r0
_08079E98:
	subs r2, r0, r5
	cmp r2, #0
	ble _08079EAC
	cmp r1, r2
	blt _08079EB2
	b _08079EBC
	.align 2, 0
_08079EA4: .4byte 0xFFFFE800
_08079EA8: .4byte 0xFFFFF800
_08079EAC:
	subs r0, r5, r0
	cmp r1, r0
	bge _08079EBC
_08079EB2:
	movs r3, #0xc0
	lsls r3, r3, #5
	adds r0, r4, r3
	str r0, [r7, #0x58]
	b _08079EC8
_08079EBC:
	ldr r0, _08079F28 @ =0xFFFFF400
	adds r1, r5, r0
	ldr r0, [r7, #0x58]
	cmp r0, r1
	ble _08079EC8
	str r1, [r7, #0x58]
_08079EC8:
	ldr r0, [r7, #0x54]
	movs r6, #0xc0
	lsls r6, r6, #4
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	ldr r2, _08079F2C @ =0xFFFFE800
	mov r8, r2
	add r1, r8
	bl PushoutToDown2
	adds r4, r0, #0
	ldr r0, [r7, #0x54]
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	subs r1, #0x10
	bl PushoutToUp2
	adds r5, r0, #0
	cmp r4, #0
	bne _08079EF4
	cmp r5, #0
	beq _08079F50
_08079EF4:
	ldr r0, [r7, #0x54]
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	ldr r3, _08079F30 @ =0xFFFFF800
	adds r1, r1, r3
	bl FUN_0800a05c
	adds r5, r0, #0
	ldr r0, [r7, #0x54]
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	add r1, r8
	bl FUN_0800a134
	adds r4, r0, #0
	ldr r0, [r7, #0x58]
	subs r1, r0, r4
	cmp r1, #0
	bgt _08079F1C
	subs r1, r4, r0
_08079F1C:
	subs r2, r0, r5
	cmp r2, #0
	ble _08079F34
	cmp r1, r2
	blt _08079F3A
	b _08079F44
	.align 2, 0
_08079F28: .4byte 0xFFFFF400
_08079F2C: .4byte 0xFFFFE800
_08079F30: .4byte 0xFFFFF800
_08079F34:
	subs r0, r5, r0
	cmp r1, r0
	bge _08079F44
_08079F3A:
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r4, r1
	str r0, [r7, #0x58]
	b _08079F50
_08079F44:
	ldr r2, _08079FB0 @ =0xFFFFF400
	adds r1, r5, r2
	ldr r0, [r7, #0x58]
	cmp r0, r1
	ble _08079F50
	str r1, [r7, #0x58]
_08079F50:
	ldr r0, [r7, #0x54]
	ldr r6, _08079FB0 @ =0xFFFFF400
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	ldr r3, _08079FB4 @ =0xFFFFE800
	mov r8, r3
	add r1, r8
	bl PushoutToDown2
	adds r4, r0, #0
	ldr r0, [r7, #0x54]
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	subs r1, #0x10
	bl PushoutToUp2
	adds r5, r0, #0
	cmp r4, #0
	bne _08079F7A
	cmp r5, #0
	beq _08079FD8
_08079F7A:
	ldr r0, [r7, #0x54]
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	ldr r2, _08079FB8 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_0800a05c
	adds r5, r0, #0
	ldr r0, [r7, #0x54]
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	add r1, r8
	bl FUN_0800a134
	adds r4, r0, #0
	ldr r0, [r7, #0x58]
	subs r1, r0, r4
	cmp r1, #0
	bgt _08079FA2
	subs r1, r4, r0
_08079FA2:
	subs r2, r0, r5
	cmp r2, #0
	ble _08079FBC
	cmp r1, r2
	blt _08079FC2
	b _08079FCC
	.align 2, 0
_08079FB0: .4byte 0xFFFFF400
_08079FB4: .4byte 0xFFFFE800
_08079FB8: .4byte 0xFFFFF800
_08079FBC:
	subs r0, r5, r0
	cmp r1, r0
	bge _08079FCC
_08079FC2:
	movs r3, #0xc0
	lsls r3, r3, #5
	adds r0, r4, r3
	str r0, [r7, #0x58]
	b _08079FD8
_08079FCC:
	ldr r0, _0807A014 @ =0xFFFFF400
	adds r1, r5, r0
	ldr r0, [r7, #0x58]
	cmp r0, r1
	ble _08079FD8
	str r1, [r7, #0x58]
_08079FD8:
	adds r0, r7, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08079FEC
	adds r0, r7, #0
	bl UpdateMotionGraphic
_08079FEC:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _0807A004
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _0807A004
	str r0, [r7, #0x60]
	strb r0, [r7, #0xd]
_0807A002:
	strb r0, [r7, #0xe]
_0807A004:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807A014: .4byte 0xFFFFF400

	thumb_func_start FUN_0807a018
FUN_0807a018: @ 0x0807A018
	movs r0, #1
	bx lr

	thumb_func_start FUN_0807a01c
FUN_0807a01c: @ 0x0807A01C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0807A036
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807A05C @ =0x083675E4
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807A036:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0807A056
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807A060 @ =0x083675CC
	bl SetDDP
	movs r0, #0
	str r0, [r5]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0807A056:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807A05C: .4byte 0x083675E4
_0807A060: .4byte 0x083675CC

	thumb_func_start FUN_0807a064
FUN_0807a064: @ 0x0807A064
	movs r0, #1
	bx lr

	thumb_func_start FUN_0807a068
FUN_0807a068: @ 0x0807A068
	bx lr
	.align 2, 0

	thumb_func_start FUN_0807a06c
FUN_0807a06c: @ 0x0807A06C
	movs r0, #1
	bx lr

	thumb_func_start shelluno_0807a070
shelluno_0807a070: @ 0x0807A070
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0807A080
	cmp r5, #1
	beq _0807A092
	b _0807A0D0
_0807A080:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807A0C4 @ =0x083675E4
	bl SetDDP
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807A092:
	ldr r0, [r4, #0x60]
	adds r0, #0x10
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807A0A2
	str r1, [r4, #0x60]
_0807A0A2:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807A0C8
	movs r0, #0
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_0800a05c
	b _0807A0CE
	.align 2, 0
_0807A0C4: .4byte 0x083675E4
_0807A0C8:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
_0807A0CE:
	str r0, [r4, #0x58]
_0807A0D0:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0807A0F0
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807A0F8 @ =0x083675CC
	bl SetDDP
	movs r0, #0
	str r0, [r5]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0807A0F0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807A0F8: .4byte 0x083675CC

	thumb_func_start FUN_0807a0fc
FUN_0807a0fc: @ 0x0807A0FC
	movs r0, #1
	bx lr

	thumb_func_start shelluno_0807a100
shelluno_0807a100: @ 0x0807A100
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0807A110
	cmp r0, #1
	beq _0807A170
	b _0807A23A
_0807A110:
	adds r1, r5, #0
	adds r1, #0xb9
	movs r4, #1
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x20
	strb r0, [r5, #0x12]
	ldr r1, _0807A14C @ =0x00003509
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807A150 @ =0x083675FC
	bl SetDDP
	ldr r0, _0807A154 @ =pZero2
	ldr r0, [r0]
	ldrb r0, [r0, #0xa]
	lsrs r0, r0, #4
	ands r0, r4
	strb r0, [r5, #0xf]
	cmp r0, #0
	bne _0807A15C
	ldr r0, _0807A158 @ =0xFFFFFD80
	str r0, [r5, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #1
	b _0807A164
	.align 2, 0
_0807A14C: .4byte 0x00003509
_0807A150: .4byte 0x083675FC
_0807A154: .4byte pZero2
_0807A158: .4byte 0xFFFFFD80
_0807A15C:
	movs r0, #0xa0
	lsls r0, r0, #2
	str r0, [r5, #0x5c]
	ldr r0, _0807A1A8 @ =0xFFFFFF00
_0807A164:
	str r0, [r5, #0x64]
	movs r0, #0
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807A170:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x60]
	adds r1, r1, r2
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0807A1B0
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0807A1B0
	ldr r1, _0807A1AC @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _0807A23A
	.align 2, 0
_0807A1A8: .4byte 0xFFFFFF00
_0807A1AC: .4byte gEnemyFnTable
_0807A1B0:
	ldr r0, [r5, #0x54]
	ldr r3, [r5, #0x5c]
	adds r0, r0, r3
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x60]
	adds r1, r1, r2
	str r1, [r5, #0x58]
	ldr r2, [r5, #0x64]
	subs r2, r2, r3
	lsls r2, r2, #3
	asrs r2, r2, #8
	adds r3, r3, r2
	str r3, [r5, #0x5c]
	ldr r2, _0807A1F8 @ =0xFFFFE000
	adds r1, r1, r2
	bl FUN_0800a05c
	adds r1, r0, #0
	ldr r0, [r5, #0x58]
	subs r0, r1, r0
	cmp r0, #0x40
	bgt _0807A1E0
	str r1, [r5, #0x58]
_0807A1E0:
	adds r0, r5, #0
	bl FUN_0807a46c
	ldrb r1, [r5, #0xf]
	cmp r1, #0
	bne _0807A1FC
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	blt _0807A208
	strb r1, [r5, #0xd]
	strb r1, [r5, #0xe]
	b _0807A208
	.align 2, 0
_0807A1F8: .4byte 0xFFFFE000
_0807A1FC:
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	bgt _0807A208
	movs r0, #0
	strb r0, [r5, #0xd]
	strb r0, [r5, #0xe]
_0807A208:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0807A234
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _0807A234
	adds r1, r5, #0
	adds r1, #0xb9
	strb r0, [r1]
	movs r1, #0xd4
	lsls r1, r1, #6
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807A240 @ =0x0836759C
	bl SetDDP
_0807A234:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_0807A23A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807A240: .4byte 0x0836759C

	thumb_func_start FUN_0807a244
FUN_0807a244: @ 0x0807A244
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r6, [r5]
	cmp r6, #0
	beq _0807A25C
	b _0807A3D6
_0807A25C:
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0807A26A
	b _0807A3D6
_0807A26A:
	movs r0, #0x97
	adds r0, r0, r4
	mov r8, r0
	ldrb r1, [r0]
	movs r7, #0xf0
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0x20
	beq _0807A27E
	b _0807A3A8
_0807A27E:
	ldr r5, [r4, #0x58]
	ldr r4, [r4, #0x54]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	bl CreateBubble
	ldr r1, _0807A39C @ =RNG_0202f388
	mov sl, r1
	ldr r0, [r1]
	ldr r2, _0807A3A0 @ =0x000343FD
	mov sb, r2
	mov r3, sb
	muls r3, r0, r3
	adds r0, r3, #0
	ldr r6, _0807A3A4 @ =0x00269EC3
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
	b _0807A3D6
	.align 2, 0
_0807A39C: .4byte RNG_0202f388
_0807A3A0: .4byte 0x000343FD
_0807A3A4: .4byte 0x00269EC3
_0807A3A8:
	ldr r2, _0807A3C8 @ =0x0836762C
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r5]
	cmp r0, #0
	beq _0807A3D6
	mov r3, r8
	ldrb r0, [r3]
	adds r2, r7, #0
	ands r2, r0
	cmp r2, #0x10
	bne _0807A3CC
	movs r0, #2
	b _0807A3D2
	.align 2, 0
_0807A3C8: .4byte 0x0836762C
_0807A3CC:
	cmp r2, #0x30
	bne _0807A3D6
	movs r0, #4
_0807A3D2:
	strb r0, [r4, #0xd]
	strb r6, [r4, #0xe]
_0807A3D6:
	movs r0, #1
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0807a3e8
FUN_0807a3e8: @ 0x0807A3E8
	movs r0, #1
	bx lr

	thumb_func_start FUN_0807a3ec
FUN_0807a3ec: @ 0x0807A3EC
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	ldr r0, [r3, #0xc]
	ldr r4, [r0, #4]
	ldrb r0, [r4, #4]
	cmp r0, #3
	beq _0807A404
	cmp r0, #0xe
	beq _0807A404
	cmp r0, #0xf
	bne _0807A42E
_0807A404:
	ldr r2, [r3, #0x2c]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0807A42E
	ldr r1, [r2, #0x54]
	ldr r0, [r5]
	cmp r1, r0
	bge _0807A426
	adds r1, r2, #0
	adds r1, #0xba
	movs r0, #0xff
	b _0807A42C
_0807A426:
	adds r1, r2, #0
	adds r1, #0xba
	movs r0, #0xfe
_0807A42C:
	strb r0, [r1]
_0807A42E:
	ldr r0, [r4, #4]
	ldr r1, _0807A464 @ =0x000200FF
	ands r0, r1
	subs r1, #0xfd
	cmp r0, r1
	bne _0807A45E
	ldr r2, [r3, #0x2c]
	ldrb r0, [r2, #0xd]
	cmp r0, #5
	beq _0807A45E
	adds r0, r2, #0
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807A45E
	ldr r1, _0807A468 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
_0807A45E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807A464: .4byte 0x000200FF
_0807A468: .4byte gEnemyFnTable

	thumb_func_start FUN_0807a46c
FUN_0807a46c: @ 0x0807A46C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _0807A4D8 @ =gOverworld
	ldr r2, _0807A4DC @ =0x0002C00C
	adds r1, r1, r2
	ldr r5, [r1]
	ldr r2, [r4, #0x58]
	ldr r3, _0807A4E0 @ =0xFFFFF400
	adds r1, r2, r3
	cmp r5, r1
	ble _0807A4D0
	ldr r0, [r4, #0x54]
	adds r1, r2, #0
	bl FUN_0800a05c
	ldr r1, [r4, #0x58]
	cmp r0, r1
	beq _0807A4A0
	adds r1, r4, #0
	adds r1, #0xc1
	movs r0, #0x1e
	strb r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r5, r1
	str r0, [r4, #0x58]
_0807A4A0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_0800a05c
	adds r1, r0, #0
	ldr r2, [r4, #0x58]
	cmp r1, r2
	beq _0807A4D0
	ldr r1, [r4, #0x5c]
	cmp r1, #0
	beq _0807A4D0
	ldr r1, _0807A4E4 @ =pZero2
	ldr r1, [r1]
	ldr r1, [r1, #0x58]
	cmp r1, r2
	bge _0807A4D0
	adds r2, r4, #0
	adds r2, #0xc1
	movs r1, #0x1e
	strb r1, [r2]
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r5, r2
	str r1, [r4, #0x58]
_0807A4D0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0807A4D8: .4byte gOverworld
_0807A4DC: .4byte 0x0002C00C
_0807A4E0: .4byte 0xFFFFF400
_0807A4E4: .4byte pZero2
