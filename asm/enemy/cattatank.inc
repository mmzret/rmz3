	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08098838
FUN_08098838: @ 0x08098838
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _08098894 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809888C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08098898 @ =gEnemyFnTable
	movs r1, #0x43
	strb r1, [r3, #9]
	adds r1, #0xc9
	adds r0, r0, r1
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
	movs r0, #1
	strb r0, [r3, #0x11]
_0809888C:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08098894: .4byte gZakoHeaderPtr
_08098898: .4byte gEnemyFnTable

	thumb_func_start Cattatank_Init
Cattatank_Init: @ 0x0809889C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #0
	mov r8, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08098910 @ =0x0836A4D8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #8
	bl InitBody
	str r6, [r4, #0x2c]
	ldr r0, _08098914 @ =FUN_08099eb4
	str r0, [r4, #0x24]
	adds r7, r6, #0
	adds r7, #0xb8
	strb r5, [r7]
	adds r0, r6, #0
	adds r0, #0xbc
	str r5, [r0]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _08098918
	movs r5, #1
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	subs r4, #0x28
	strb r5, [r4]
	adds r2, r6, #0
	adds r2, #0x4a
	movs r3, #0x10
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r3
	strb r0, [r2]
	strb r5, [r7]
	adds r3, r2, #0
	b _0809893A
	.align 2, 0
_08098910: .4byte 0x0836A4D8
_08098914: .4byte FUN_08099eb4
_08098918:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r3, r6, #0
	adds r3, #0x4c
	strb r5, [r3]
	adds r1, r6, #0
	adds r1, #0x4a
	ldrb r2, [r1]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1]
	strb r5, [r7]
	adds r4, r3, #0
	adds r3, r1, #0
_0809893A:
	ldrb r5, [r6, #0x11]
	cmp r5, #1
	bne _080989A4
	ldr r0, _08098968 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r6, #0x54]
	cmp r1, r0
	bge _0809896C
	movs r2, #0
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	strb r2, [r4]
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	strb r2, [r7]
	b _08098986
	.align 2, 0
_08098968: .4byte pZero2
_0809896C:
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	strb r5, [r4]
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	strb r5, [r7]
_08098986:
	ldr r1, _080989A0 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #0
	strb r0, [r6, #0xd]
	b _080989BA
	.align 2, 0
_080989A0: .4byte gEnemyFnTable
_080989A4:
	ldr r1, _08098A00 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #0
	strb r1, [r6, #0xd]
_080989BA:
	strb r0, [r6, #0xe]
	strb r0, [r6, #0xf]
	movs r4, #0
	str r4, [r6, #0x60]
	str r4, [r6, #0x5c]
	adds r0, r6, #0
	adds r0, #0xbb
	strb r4, [r0]
	str r4, [r6, #0x5c]
	adds r0, r6, #0
	bl isFrozen
	cmp r0, #0
	beq _080989E4
	ldr r1, _08098A04 @ =0x0000D503
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
_080989E4:
	adds r0, r6, #0
	adds r0, #0xc0
	strb r4, [r0]
	subs r0, #6
	strb r4, [r0]
	adds r0, r6, #0
	bl Cattatank_Update
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08098A00: .4byte gEnemyFnTable
_08098A04: .4byte 0x0000D503

	thumb_func_start Cattatank_Update
Cattatank_Update: @ 0x08098A08
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08098A4C
	ldrb r0, [r4, #0xd]
	cmp r0, #6
	bne _08098A2A
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _08098AD0
_08098A2A:
	movs r0, #0
	strb r0, [r4, #0xf]
	ldr r1, _08098A48 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Cattatank_Die
	b _08098B10
	.align 2, 0
_08098A48: .4byte gEnemyFnTable
_08098A4C:
	ldr r6, _08098ABC @ =gStageRun+232
	adds r5, r4, #0
	adds r5, #0x54
	adds r0, r6, #0
	adds r1, r5, #0
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #6
	cmp r0, r1
	bls _08098AD0
	ldr r1, [r6, #0x3c]
	ldr r0, _08098AC0 @ =0x00004FFF
	adds r1, r1, r0
	ldr r0, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r0, r2
	cmp r1, r0
	bge _08098AD0
	ldrb r0, [r4, #0x11]
	cmp r0, #1
	bne _08098AD0
	strb r0, [r4, #0xf]
	movs r0, #0x2a
	bl PlaySound
	movs r0, #1
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _08098AC4 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08098AC8 @ =0x0000270E
	cmp r1, r0
	bhi _08098A98
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08098A98:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08098ACC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	b _08098B10
	.align 2, 0
_08098ABC: .4byte gStageRun+232
_08098AC0: .4byte 0x00004FFF
_08098AC4: .4byte gMission
_08098AC8: .4byte 0x0000270E
_08098ACC: .4byte gEnemyFnTable
_08098AD0:
	ldr r1, _08098B18 @ =0x0836A470
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl cattatank_08099e20
	ldrb r1, [r4, #0xd]
	subs r0, r1, #6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08098B00
	cmp r1, #9
	beq _08098B00
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	bne _08098B10
_08098B00:
	ldr r0, _08098B1C @ =0x0836A498
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_08098B10:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08098B18: .4byte 0x0836A470
_08098B1C: .4byte 0x0836A498

	thumb_func_start Cattatank_Die
Cattatank_Die: @ 0x08098B20
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	ldr r0, _08098B78 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08098B80
	ldrb r0, [r6, #0x11]
	cmp r0, #1
	beq _08098B80
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
	ldr r1, _08098B7C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _0809906E
	.align 2, 0
_08098B78: .4byte gCurStory
_08098B7C: .4byte gEnemyFnTable
_08098B80:
	ldr r5, _08098C44 @ =gStageRun+232
	adds r4, r6, #0
	adds r4, #0x54
	adds r0, r5, #0
	adds r1, r4, #0
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #6
	mov sb, r4
	cmp r0, r1
	bls _08098C78
	ldr r1, [r5, #0x3c]
	ldr r0, _08098C48 @ =0x00004FFF
	adds r1, r1, r0
	ldr r2, [r6, #0x58]
	movs r3, #0x80
	lsls r3, r3, #6
	mov sl, r3
	adds r0, r2, r3
	cmp r1, r0
	bge _08098C78
	ldr r0, [r6, #0x54]
	str r0, [sp]
	str r2, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	movs r0, #1
	mov r1, sb
	bl TryDropItem
	ldrb r0, [r6, #0xf]
	cmp r0, #0
	beq _08098BD0
	b _08099040
_08098BD0:
	ldr r2, _08098C4C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08098C50 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08098C54 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r7, r0, #0x11
	movs r0, #3
	ands r7, r0
	ldr r0, [r6, #0x54]
	str r0, [sp, #8]
	ldr r0, [r6, #0x58]
	add r5, sp, #8
	str r0, [r5, #4]
	movs r3, #0xb8
	adds r3, r3, r6
	mov r8, r3
	ldrb r1, [r3]
	ldr r2, _08098C58 @ =0x0000D50F
	adds r0, r5, #0
	adds r3, r7, #0
	bl FUN_080c7570
	mov r0, r8
	ldrb r1, [r0]
	ldr r4, _08098C5C @ =0x0000D50E
	adds r0, r5, #0
	adds r2, r4, #0
	adds r3, r7, #0
	bl FUN_080c7570
	mov r3, r8
	ldrb r1, [r3]
	ldr r2, _08098C60 @ =0x0000D510
	adds r0, r5, #0
	adds r3, r7, #0
	bl FUN_080c7570
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r5, #0
	adds r2, r4, #0
	adds r3, r7, #0
	bl FUN_080c7570
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08098C68
	ldr r0, [r6, #0x54]
	ldr r1, _08098C64 @ =0xFFFFE000
	adds r0, r0, r1
	str r0, [sp, #8]
	b _08098FF0
	.align 2, 0
_08098C44: .4byte gStageRun+232
_08098C48: .4byte 0x00004FFF
_08098C4C: .4byte RNG_0202f388
_08098C50: .4byte 0x000343FD
_08098C54: .4byte 0x00269EC3
_08098C58: .4byte 0x0000D50F
_08098C5C: .4byte 0x0000D50E
_08098C60: .4byte 0x0000D510
_08098C64: .4byte 0xFFFFE000
_08098C68:
	ldr r0, [r6, #0x54]
	add r0, sl
	str r0, [sp, #8]
	ldr r0, [r6, #0x58]
	str r0, [r5, #4]
	mov r0, r8
	ldrb r1, [r0]
	b _08099036
_08098C78:
	ldrb r0, [r6, #0xe]
	cmp r0, #0xb
	bls _08098C80
	b _08099070
_08098C80:
	lsls r0, r0, #2
	ldr r1, _08098C8C @ =_08098C90
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08098C8C: .4byte _08098C90
_08098C90: @ jump table
	.4byte _08098CC0 @ case 0
	.4byte _08098E24 @ case 1
	.4byte _08098D08 @ case 2
	.4byte _08098D1C @ case 3
	.4byte _08098E44 @ case 4
	.4byte _08099070 @ case 5
	.4byte _08099070 @ case 6
	.4byte _08099070 @ case 7
	.4byte _08099070 @ case 8
	.4byte _08099070 @ case 9
	.4byte _08098E24 @ case 10
	.4byte _08098F20 @ case 11
_08098CC0:
	ldr r1, _08098CE8 @ =0x0000D505
	adds r0, r6, #0
	bl SetMotion
	adds r1, r6, #0
	adds r1, #0x8c
	ldr r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	adds r3, r1, #0
	cmp r0, #0
	beq _08098CEC
	movs r0, #0x80
	lsls r0, r0, #9
	ands r2, r0
	cmp r2, #0
	beq _08098CEC
	movs r0, #1
	b _08098CEE
	.align 2, 0
_08098CE8: .4byte 0x0000D505
_08098CEC:
	movs r0, #0xa
_08098CEE:
	strb r0, [r6, #0xe]
	movs r1, #0
	str r1, [r3]
	adds r0, r6, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	b _08098E24
_08098D08:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08098D1A
	b _08099070
_08098D1A:
	b _08098E24
_08098D1C:
	ldr r1, _08098D68 @ =0x0000D505
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
	movs r0, #0
	strb r0, [r6, #0x13]
	str r0, [r6, #0x60]
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	str r0, [sp, #4]
	ldrb r0, [r6, #0xf]
	adds r7, r6, #0
	adds r7, #0xb8
	cmp r0, #0
	bne _08098D4A
	ldrb r1, [r7]
	mov r0, sp
	bl FUN_080c7518
_08098D4A:
	ldrb r0, [r7]
	cmp r0, #0
	bne _08098D70
	ldr r0, [sp]
	ldr r1, _08098D6C @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r0, r0, r3
	str r0, [sp, #4]
	movs r0, #0x80
	b _08098D84
	.align 2, 0
_08098D68: .4byte 0x0000D505
_08098D6C: .4byte 0xFFFFF800
_08098D70:
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
_08098D84:
	str r0, [r6, #0x5c]
	adds r0, r6, #0
	adds r0, #0xba
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _08098DB0
	cmp r0, #0xfe
	bne _08098DA4
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
	b _08098DD2
_08098DA4:
	ldr r0, _08098DC0 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r6, #0x54]
	cmp r1, r0
	ble _08098DC4
_08098DB0:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #1
	bl FUN_080b2b40
	b _08098DD2
	.align 2, 0
_08098DC0: .4byte pZero2
_08098DC4:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
_08098DD2:
	movs r0, #1
	mov r1, sb
	bl TryDropItem
	ldrb r0, [r6, #0xf]
	cmp r0, #0
	bne _08098E1C
	ldr r2, _08098E2C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08098E30 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _08098E34 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r6, #0x54]
	str r0, [sp, #0x10]
	ldr r0, [r6, #0x58]
	add r5, sp, #0x10
	str r0, [r5, #4]
	ldrb r1, [r7]
	ldr r2, _08098E38 @ =0x0000D50F
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080c7570
	ldrb r1, [r7]
	ldr r2, _08098E3C @ =0x0000D510
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080c7570
_08098E1C:
	ldr r0, _08098E40 @ =0xFFFFFE00
	str r0, [r6, #0x60]
	movs r0, #0x1e
	strb r0, [r6, #0x12]
_08098E24:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _08099070
	.align 2, 0
_08098E2C: .4byte RNG_0202f388
_08098E30: .4byte 0x000343FD
_08098E34: .4byte 0x00269EC3
_08098E38: .4byte 0x0000D50F
_08098E3C: .4byte 0x0000D510
_08098E40: .4byte 0xFFFFFE00
_08098E44:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x60]
	adds r0, #0x20
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08098E5A
	str r1, [r6, #0x60]
_08098E5A:
	ldr r1, [r6, #0x58]
	ldr r0, [r6, #0x60]
	adds r1, r1, r0
	str r1, [r6, #0x58]
	ldr r2, [r6, #0x5c]
	rsbs r0, r2, #0
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r6, #0x5c]
	ldr r0, [r6, #0x54]
	adds r0, r0, r2
	str r0, [r6, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08098ED8
	ldr r0, [r6, #0x60]
	cmp r0, #0
	ble _08098ED8
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r0, [r0]
	bl isKilled
	cmp r0, #0
	beq _08098ED8
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _08098F14 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08098F18 @ =0x0000270E
	cmp r1, r0
	bhi _08098EB6
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08098EB6:
	adds r0, r6, #0
	mov r1, sb
	bl TryDropZakoDisk
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _08098F1C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r6, #0x14]
_08098ED8:
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _08098EEA
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08098EEA
	b _08099070
_08098EEA:
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r0, [r0]
	bl isKilled
	cmp r0, #0
	bne _08098EFA
	b _08099070
_08098EFA:
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	b _08099040
	.align 2, 0
_08098F14: .4byte gMission
_08098F18: .4byte 0x0000270E
_08098F1C: .4byte gEnemyFnTable
_08098F20:
	ldr r0, [r6, #0x60]
	adds r0, #0x20
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08098F30
	str r1, [r6, #0x60]
_08098F30:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r1, [r6, #0x5c]
	rsbs r0, r1, #0
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r6, #0x5c]
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r0, [r0]
	bl isKilled
	cmp r0, #0
	bne _08098F5A
	b _08099070
_08098F5A:
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	movs r0, #1
	mov r1, sb
	bl TryDropItem
	ldrb r0, [r6, #0xf]
	cmp r0, #0
	bne _08099040
	ldr r2, _08099004 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08099008 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0809900C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r7, r0, #0x11
	movs r0, #3
	ands r7, r0
	ldr r0, [r6, #0x54]
	str r0, [sp, #0x18]
	ldr r0, [r6, #0x58]
	add r5, sp, #0x18
	str r0, [r5, #4]
	movs r3, #0xb8
	adds r3, r3, r6
	mov r8, r3
	ldrb r1, [r3]
	ldr r2, _08099010 @ =0x0000D50F
	adds r0, r5, #0
	adds r3, r7, #0
	bl FUN_080c7570
	mov r0, r8
	ldrb r1, [r0]
	ldr r4, _08099014 @ =0x0000D50E
	adds r0, r5, #0
	adds r2, r4, #0
	adds r3, r7, #0
	bl FUN_080c7570
	mov r3, r8
	ldrb r1, [r3]
	ldr r2, _08099018 @ =0x0000D510
	adds r0, r5, #0
	adds r3, r7, #0
	bl FUN_080c7570
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r5, #0
	adds r2, r4, #0
	adds r3, r7, #0
	bl FUN_080c7570
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08099024
	ldr r0, [r6, #0x54]
	ldr r1, _0809901C @ =0xFFFFE000
	adds r0, r0, r1
	str r0, [sp, #0x18]
_08098FF0:
	ldr r0, [r6, #0x58]
	str r0, [r5, #4]
	mov r3, r8
	ldrb r1, [r3]
	ldr r2, _08099020 @ =0x0000D50D
	adds r0, r5, #0
	adds r3, r7, #0
	bl FUN_080c7570
	b _08099040
	.align 2, 0
_08099004: .4byte RNG_0202f388
_08099008: .4byte 0x000343FD
_0809900C: .4byte 0x00269EC3
_08099010: .4byte 0x0000D50F
_08099014: .4byte 0x0000D50E
_08099018: .4byte 0x0000D510
_0809901C: .4byte 0xFFFFE000
_08099020: .4byte 0x0000D50D
_08099024:
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r0, r1
	str r0, [sp, #0x18]
	ldr r0, [r6, #0x58]
	str r0, [r5, #4]
	mov r3, r8
	ldrb r1, [r3]
_08099036:
	ldr r2, _08099080 @ =0x0000D50D
	adds r0, r5, #0
	adds r3, r7, #0
	bl FUN_080c7570
_08099040:
	ldr r2, _08099084 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08099088 @ =0x0000270E
	cmp r1, r0
	bhi _0809904E
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0809904E:
	adds r0, r6, #0
	mov r1, sb
	bl TryDropZakoDisk
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _0809908C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
_0809906E:
	str r0, [r6, #0x14]
_08099070:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08099080: .4byte 0x0000D50D
_08099084: .4byte gMission
_08099088: .4byte 0x0000270E
_0809908C: .4byte gEnemyFnTable

	thumb_func_start nop_08099090
nop_08099090: @ 0x08099090
	movs r0, #1
	bx lr

	thumb_func_start cattatank_08099094
cattatank_08099094: @ 0x08099094
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #0
	beq _080990A4
	cmp r0, #1
	beq _080990B6
	b _080990CE
_080990A4:
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r2, #0xa]
	movs r0, #0x32
	strb r0, [r2, #0x12]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_080990B6:
	ldrb r0, [r2, #0x12]
	cmp r0, #0
	beq _080990C6
	subs r0, #1
	strb r0, [r2, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080990CE
_080990C6:
	movs r1, #0
	movs r0, #1
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_080990CE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start nop_080990d4
nop_080990d4: @ 0x080990D4
	movs r0, #1
	bx lr

	thumb_func_start FUN_080990d8
FUN_080990d8: @ 0x080990D8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _080990E4
	b _08099256
_080990E4:
	lsls r0, r0, #2
	ldr r1, _080990F0 @ =_080990F4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080990F0: .4byte _080990F4
_080990F4: @ jump table
	.4byte _0809910C @ case 0
	.4byte _080991A0 @ case 1
	.4byte _080991F2 @ case 2
	.4byte _0809920A @ case 3
	.4byte _08099228 @ case 4
	.4byte _0809923C @ case 5
_0809910C:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809915C @ =0x0000D503
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099160 @ =0x0836A4D8
	bl SetDDP
	ldr r0, _08099164 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	bge _08099168
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xb8
	strb r2, [r0]
	b _08099194
	.align 2, 0
_0809915C: .4byte 0x0000D503
_08099160: .4byte 0x0836A4D8
_08099164: .4byte pZero2
_08099168:
	movs r3, #1
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	movs r2, #0x10
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xb8
	strb r3, [r0]
_08099194:
	ldr r0, [r4, #0x5c]
	asrs r0, r0, #1
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080991A0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080991B6
	str r1, [r4, #0x60]
_080991B6:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r2, r1, r0
	str r2, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	ble _080991D4
	ldr r1, _080991D0 @ =0xFFFFF800
	b _080991D8
	.align 2, 0
_080991D0: .4byte 0xFFFFF800
_080991D4:
	movs r1, #0x80
	lsls r1, r1, #4
_080991D8:
	adds r0, r0, r1
	adds r1, r2, #0
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _08099256
	movs r0, #0
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	b _0809921A
_080991F2:
	adds r1, r4, #0
	adds r1, #0xbb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, _08099224 @ =0x0000D504
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809920A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08099256
_0809921A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08099256
	.align 2, 0
_08099224: .4byte 0x0000D504
_08099228:
	movs r1, #0xd5
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x14
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809923C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08099256
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099256:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start nop_0809925c
nop_0809925c: @ 0x0809925C
	movs r0, #1
	bx lr

	thumb_func_start FUN_08099260
FUN_08099260: @ 0x08099260
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xd
	bls _0809926C
	b _080994E2
_0809926C:
	lsls r0, r0, #2
	ldr r1, _08099278 @ =_0809927C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08099278: .4byte _0809927C
_0809927C: @ jump table
	.4byte _080992B4 @ case 0
	.4byte _080992EE @ case 1
	.4byte _080994E2 @ case 2
	.4byte _080994E2 @ case 3
	.4byte _080994E2 @ case 4
	.4byte _080994E2 @ case 5
	.4byte _080994E2 @ case 6
	.4byte _080994E2 @ case 7
	.4byte _080994E2 @ case 8
	.4byte _080994E2 @ case 9
	.4byte _0809944C @ case 10
	.4byte _0809945A @ case 11
	.4byte _08099474 @ case 12
	.4byte _080994CE @ case 13
_080992B4:
	ldr r1, _080992DC @ =0x0000D501
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080992E0 @ =0x0836A4D8
	bl SetDDP
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080992E4
	movs r0, #0xc0
	rsbs r0, r0, #0
	b _080992E6
	.align 2, 0
_080992DC: .4byte 0x0000D501
_080992E0: .4byte 0x0836A4D8
_080992E4:
	movs r0, #0xc0
_080992E6:
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080992EE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	ble _0809930E
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	b _08099318
_0809930E:
	ldr r2, _08099354 @ =0xFFFFF600
	adds r0, r0, r2
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
_08099318:
	adds r2, r0, #0
	cmp r2, #0
	beq _08099324
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
_08099324:
	ldrb r0, [r4, #0x11]
	adds r6, r0, #0
	cmp r6, #1
	bne _08099360
	adds r0, r4, #0
	adds r0, #0xbb
	ldrb r0, [r0]
	ldr r2, [r4, #0x54]
	ldr r5, [r4, #0x5c]
	ldr r3, [r4, #0x58]
	cmp r0, #1
	bls _0809938E
	ldr r0, _08099358 @ =pZero2
	ldr r1, [r0]
	ldr r0, [r1, #0x58]
	cmp r3, r0
	blt _0809938E
	cmp r5, #0
	ble _0809935C
	ldr r0, [r1, #0x54]
	cmp r0, r2
	bge _0809938E
	b _0809938A
	.align 2, 0
_08099354: .4byte 0xFFFFF600
_08099358: .4byte pZero2
_0809935C:
	ldr r0, [r1, #0x54]
	b _08099386
_08099360:
	ldr r5, [r4, #0x5c]
	cmp r5, #0
	ble _0809937C
	ldr r0, _08099378 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r2, [r4, #0x54]
	ldr r3, [r4, #0x58]
	cmp r0, r2
	bge _0809938E
	b _0809938A
	.align 2, 0
_08099378: .4byte pZero2
_0809937C:
	ldr r0, _080993BC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r2, [r4, #0x54]
	ldr r3, [r4, #0x58]
_08099386:
	cmp r0, r2
	ble _0809938E
_0809938A:
	movs r0, #0xa
	strb r0, [r4, #0xe]
_0809938E:
	ldrb r0, [r4, #0xe]
	cmp r0, #0xa
	beq _080993EC
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _080993C0
	adds r0, r4, #0
	adds r0, #0xbb
	ldrb r0, [r0]
	cmp r0, #1
	bls _080993EC
	ldr r0, _080993BC @ =pZero2
	ldr r1, [r0]
	ldr r0, [r1, #0x58]
	cmp r3, r0
	blt _080993EC
	ldr r0, [r1, #0x54]
	subs r1, r0, r2
	cmp r1, #0
	bgt _080993CC
	b _080993DC
	.align 2, 0
_080993BC: .4byte pZero2
_080993C0:
	ldr r0, _080993D4 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	subs r1, r0, r2
	cmp r1, #0
	ble _080993DC
_080993CC:
	ldr r0, _080993D8 @ =0x00003BFF
	cmp r1, r0
	ble _080993E4
	b _080993EC
	.align 2, 0
_080993D4: .4byte pZero2
_080993D8: .4byte 0x00003BFF
_080993DC:
	subs r1, r2, r0
	ldr r0, _0809940C @ =0x00003BFF
	cmp r1, r0
	bgt _080993EC
_080993E4:
	movs r1, #0
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080993EC:
	cmp r5, #0
	ble _08099414
	ldr r1, _08099410 @ =0xFFFFF600
	adds r0, r2, r1
	adds r1, r3, #0
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r1, [r4, #0x58]
	cmp r2, r1
	beq _080994E2
	ldr r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #4
	b _0809942C
	.align 2, 0
_0809940C: .4byte 0x00003BFF
_08099410: .4byte 0xFFFFF600
_08099414:
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r2, r1
	adds r1, r3, #0
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r1, [r4, #0x58]
	cmp r2, r1
	beq _080994E2
	ldr r0, [r4, #0x54]
	ldr r2, _08099448 @ =0xFFFFF600
_0809942C:
	adds r0, r0, r2
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r0, [r4, #0x58]
	cmp r2, r0
	beq _080994E2
	movs r1, #0
	str r1, [r4, #0x60]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _080994E2
	.align 2, 0
_08099448: .4byte 0xFFFFF600
_0809944C:
	ldr r1, _08099470 @ =0x0000D511
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809945A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080994E2
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _080994E0
	.align 2, 0
_08099470: .4byte 0x0000D511
_08099474:
	ldr r1, _080994A8 @ =0x0000D512
	adds r0, r4, #0
	bl SetMotion
	ldrb r2, [r4, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r2
	cmp r0, #0
	bne _080994AC
	movs r1, #1
	movs r0, #0x10
	orrs r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r3
	b _080994C6
	.align 2, 0
_080994A8: .4byte 0x0000D512
_080994AC:
	movs r1, #0
	movs r0, #0xef
	ands r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
_080994C6:
	strb r0, [r2]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080994CE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080994E2
	movs r0, #0
_080994E0:
	strb r0, [r4, #0xe]
_080994E2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start nop_080994e8
nop_080994e8: @ 0x080994E8
	movs r0, #1
	bx lr

	thumb_func_start FUN_080994ec
FUN_080994ec: @ 0x080994EC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xd
	bls _080994F8
	b _08099736
_080994F8:
	lsls r0, r0, #2
	ldr r1, _08099504 @ =_08099508
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08099504: .4byte _08099508
_08099508: @ jump table
	.4byte _08099540 @ case 0
	.4byte _0809954A @ case 1
	.4byte _08099584 @ case 2
	.4byte _08099670 @ case 3
	.4byte _08099684 @ case 4
	.4byte _08099736 @ case 5
	.4byte _08099736 @ case 6
	.4byte _08099736 @ case 7
	.4byte _08099736 @ case 8
	.4byte _08099736 @ case 9
	.4byte _080996A0 @ case 10
	.4byte _080996AE @ case 11
	.4byte _080996C8 @ case 12
	.4byte _08099722 @ case 13
_08099540:
	movs r0, #0
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809954A:
	ldr r1, _0809956C @ =0x0000D502
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099570 @ =0x0836A4D8
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08099574
	movs r0, #0x80
	lsls r0, r0, #1
	b _08099576
	.align 2, 0
_0809956C: .4byte 0x0000D502
_08099570: .4byte 0x0836A4D8
_08099574:
	ldr r0, _080995B0 @ =0xFFFFFF00
_08099576:
	str r0, [r4, #0x5c]
	movs r0, #0
	str r0, [r4, #0x60]
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099584:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r2, r0, r1
	str r2, [r4, #0x54]
	ldr r0, [r4, #0x64]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r0, r3
	str r0, [r4, #0x64]
	cmp r1, #0
	ble _080995B4
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	b _080995BE
	.align 2, 0
_080995B0: .4byte 0xFFFFFF00
_080995B4:
	ldr r3, _080995DC @ =0xFFFFF600
	adds r0, r2, r3
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
_080995BE:
	adds r1, r0, #0
	cmp r1, #0
	beq _080995CA
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_080995CA:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080995E0
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	b _080995E6
	.align 2, 0
_080995DC: .4byte 0xFFFFF600
_080995E0:
	ldr r0, [r4, #0x54]
	ldr r3, _08099628 @ =0xFFFFF600
	adds r0, r0, r3
_080995E6:
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	ldr r0, [r4, #0x58]
	cmp r1, r0
	beq _080995FC
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
	str r0, [r4, #0x54]
_080995FC:
	ldrb r0, [r4, #0x11]
	cmp r0, #1
	bne _08099634
	adds r0, r4, #0
	adds r0, #0xbb
	ldrb r0, [r0]
	cmp r0, #1
	bls _0809965C
	ldr r0, _0809962C @ =pZero2
	ldr r2, [r0]
	ldr r1, [r4, #0x58]
	ldr r0, [r2, #0x58]
	cmp r1, r0
	blt _0809965C
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _08099630
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0809965C
	b _08099658
	.align 2, 0
_08099628: .4byte 0xFFFFF600
_0809962C: .4byte pZero2
_08099630:
	ldr r1, [r2, #0x54]
	b _08099652
_08099634:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0809964C
	ldr r0, _08099648 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0809965C
	b _08099658
	.align 2, 0
_08099648: .4byte pZero2
_0809964C:
	ldr r0, _0809966C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
_08099652:
	ldr r0, [r4, #0x54]
	cmp r1, r0
	bge _0809965C
_08099658:
	movs r0, #0xa
	strb r0, [r4, #0xe]
_0809965C:
	ldr r1, [r4, #0x64]
	movs r0, #0xc0
	lsls r0, r0, #5
	cmp r1, r0
	ble _08099736
	movs r0, #3
	b _08099734
	.align 2, 0
_0809966C: .4byte pZero2
_08099670:
	movs r1, #0xd5
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099684:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08099736
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _08099736
_080996A0:
	ldr r1, _080996C4 @ =0x0000D511
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080996AE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08099736
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08099734
	.align 2, 0
_080996C4: .4byte 0x0000D511
_080996C8:
	ldr r1, _080996FC @ =0x0000D512
	adds r0, r4, #0
	bl SetMotion
	ldrb r2, [r4, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r2
	cmp r0, #0
	bne _08099700
	movs r1, #1
	movs r0, #0x10
	orrs r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r3
	b _0809971A
	.align 2, 0
_080996FC: .4byte 0x0000D512
_08099700:
	movs r1, #0
	movs r0, #0xef
	ands r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
_0809971A:
	strb r0, [r2]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099722:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08099736
	movs r0, #1
_08099734:
	strb r0, [r4, #0xe]
_08099736:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start nop_0809973c
nop_0809973c: @ 0x0809973C
	movs r0, #1
	bx lr

	thumb_func_start FUN_08099740
FUN_08099740: @ 0x08099740
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #6
	bls _0809974C
	b _08099948
_0809974C:
	lsls r0, r0, #2
	ldr r1, _08099758 @ =_0809975C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08099758: .4byte _0809975C
_0809975C: @ jump table
	.4byte _08099778 @ case 0
	.4byte _08099794 @ case 1
	.4byte _080997A4 @ case 2
	.4byte _080997C4 @ case 3
	.4byte _08099858 @ case 4
	.4byte _08099878 @ case 5
	.4byte _0809990C @ case 6
_08099778:
	ldr r1, _0809979C @ =0x0000D507
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080997A0 @ =0x0836A4D8
	bl SetDDP
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099794:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080998E6
	.align 2, 0
_0809979C: .4byte 0x0000D507
_080997A0: .4byte 0x0836A4D8
_080997A4:
	ldr r1, _08099844 @ =0x0000D508
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099848 @ =0x0836A520
	bl SetDDP
	movs r1, #0
	movs r0, #0x32
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080997C4:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080997E4
	adds r0, r4, #0
	adds r0, #0x90
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080997E4
	movs r0, #0x52
	bl PlaySound
_080997E4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r5, r0, #0
	cmp r1, #4
	bne _0809980C
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _0809980C
	adds r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809984C @ =0x0836A568
	bl SetDDP
_0809980C:
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #5
	bne _08099828
	ldrb r0, [r4, #0x13]
	cmp r0, #1
	bne _08099828
	adds r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099850 @ =0x0836A5B0
	bl SetDDP
_08099828:
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #6
	bne _080998DC
	ldrb r0, [r4, #0x13]
	cmp r0, #2
	bne _080998DC
	adds r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099854 @ =0x0836A5F8
	b _080998D8
	.align 2, 0
_08099844: .4byte 0x0000D508
_08099848: .4byte 0x0836A520
_0809984C: .4byte 0x0836A568
_08099850: .4byte 0x0836A5B0
_08099854: .4byte 0x0836A5F8
_08099858:
	ldr r1, _080998FC @ =0x0000D509
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099900 @ =0x0836A5B0
	bl SetDDP
	movs r1, #0
	movs r0, #8
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099878:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08099898
	adds r0, r4, #0
	adds r0, #0x90
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08099898
	movs r0, #0x52
	bl PlaySound
_08099898:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r5, r0, #0
	cmp r1, #1
	bne _080998C0
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _080998C0
	adds r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099904 @ =0x0836A568
	bl SetDDP
_080998C0:
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #2
	bne _080998DC
	ldrb r0, [r4, #0x13]
	cmp r0, #1
	bne _080998DC
	adds r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099908 @ =0x0836A520
_080998D8:
	bl SetDDP
_080998DC:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08099948
_080998E6:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08099948
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08099948
	.align 2, 0
_080998FC: .4byte 0x0000D509
_08099900: .4byte 0x0836A5B0
_08099904: .4byte 0x0836A568
_08099908: .4byte 0x0836A520
_0809990C:
	ldr r0, _08099924 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	ble _0809992C
	ldr r0, _08099928 @ =0x000039FF
	cmp r2, r0
	ble _08099934
	b _08099940
	.align 2, 0
_08099924: .4byte pZero2
_08099928: .4byte 0x000039FF
_0809992C:
	subs r1, r1, r0
	ldr r0, _0809993C @ =0x000039FF
	cmp r1, r0
	bgt _08099940
_08099934:
	movs r1, #0
	movs r0, #3
	b _08099944
	.align 2, 0
_0809993C: .4byte 0x000039FF
_08099940:
	movs r1, #0
	movs r0, #2
_08099944:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099948:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start nop_08099950
nop_08099950: @ 0x08099950
	movs r0, #1
	bx lr

	thumb_func_start FUN_08099954
FUN_08099954: @ 0x08099954
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08099964
	cmp r0, #1
	beq _080999A4
	b _08099A88
_08099964:
	ldr r1, _0809998C @ =0x0000D50C
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099990 @ =0x0836A4D8
	bl SetDDP
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldr r0, _08099994 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	bge _08099998
	movs r0, #0x60
	b _0809999C
	.align 2, 0
_0809998C: .4byte 0x0000D50C
_08099990: .4byte 0x0836A4D8
_08099994: .4byte pZero2
_08099998:
	movs r0, #0x60
	rsbs r0, r0, #0
_0809999C:
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080999A4:
	ldr r1, [r4, #0x5c]
	rsbs r0, r1, #0
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080999C6
	str r1, [r4, #0x60]
_080999C6:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r1, r0, r1
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080999E0
	ldr r0, [r4, #0x54]
	ldr r2, _080999DC @ =0xFFFFF600
	b _080999E6
	.align 2, 0
_080999DC: .4byte 0xFFFFF600
_080999E0:
	ldr r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #4
_080999E6:
	adds r0, r0, r2
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	beq _08099A06
	adds r3, r4, #0
	adds r3, #0xbb
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #0
	strb r0, [r3]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	str r1, [r4, #0x60]
_08099A06:
	ldrb r3, [r4, #0xa]
	movs r5, #0x10
	adds r0, r5, #0
	ands r0, r3
	cmp r0, #0
	bne _08099A40
	ldr r0, _08099A3C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08099A6E
	movs r2, #1
	movs r0, #0x10
	orrs r0, r3
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r5
	b _08099A66
	.align 2, 0
_08099A3C: .4byte pZero2
_08099A40:
	ldr r0, _08099A90 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	bge _08099A6E
	movs r2, #0
	movs r0, #0xef
	ands r0, r3
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
_08099A66:
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xb8
	strb r2, [r0]
_08099A6E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08099A88
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099A88:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08099A90: .4byte pZero2

	thumb_func_start nop_08099a94
nop_08099a94: @ 0x08099A94
	movs r0, #1
	bx lr

	thumb_func_start FUN_08099a98
FUN_08099a98: @ 0x08099A98
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08099B08
	cmp r0, #1
	bgt _08099AAC
	cmp r0, #0
	beq _08099AB8
	b _08099CDA
_08099AAC:
	cmp r0, #2
	beq _08099BA6
	cmp r0, #3
	bne _08099AB6
	b _08099BB4
_08099AB6:
	b _08099CDA
_08099AB8:
	ldr r1, _08099AE0 @ =0x0000D50A
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099AE4 @ =0x0836A640
	bl SetDDP
	ldr r0, _08099AE8 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08099AF0
	ldr r0, _08099AEC @ =0xFFFFFA00
	str r0, [r4, #0x5c]
	movs r0, #0xc0
	rsbs r0, r0, #0
	b _08099AF8
	.align 2, 0
_08099AE0: .4byte 0x0000D50A
_08099AE4: .4byte 0x0836A640
_08099AE8: .4byte pZero2
_08099AEC: .4byte 0xFFFFFA00
_08099AF0:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r4, #0x5c]
	movs r0, #0xc0
_08099AF8:
	str r0, [r4, #0x64]
	movs r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x1a
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099B08:
	ldr r1, [r4, #0x64]
	ldr r2, [r4, #0x5c]
	subs r1, r1, r2
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08099B30
	str r1, [r4, #0x60]
_08099B30:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	movs r5, #0
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08099B52
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099B52:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _08099B64
	ldr r0, [r4, #0x54]
	ldr r1, _08099B60 @ =0xFFFFF600
	adds r0, r0, r1
	b _08099B6C
	.align 2, 0
_08099B60: .4byte 0xFFFFF600
_08099B64:
	ldr r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r0, r0, r2
_08099B6C:
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	beq _08099B8A
	adds r1, r4, #0
	adds r1, #0xbb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	str r5, [r4, #0x60]
_08099B8A:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	bne _08099B9A
	b _08099CDA
_08099B9A:
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #0
	strb r0, [r1]
	str r0, [r5]
	b _08099CDA
_08099BA6:
	ldr r1, _08099BF0 @ =0x0000D50B
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099BB4:
	ldr r1, [r4, #0x64]
	ldr r2, [r4, #0x5c]
	subs r1, r1, r2
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08099BDC
	str r1, [r4, #0x60]
_08099BDC:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r1, r0, r1
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _08099BF8
	ldr r0, [r4, #0x54]
	ldr r2, _08099BF4 @ =0xFFFFF600
	b _08099BFE
	.align 2, 0
_08099BF0: .4byte 0x0000D50B
_08099BF4: .4byte 0xFFFFF600
_08099BF8:
	ldr r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #4
_08099BFE:
	adds r0, r0, r2
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	beq _08099C1E
	adds r3, r4, #0
	adds r3, #0xbb
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #0
	strb r0, [r3]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	str r1, [r4, #0x60]
_08099C1E:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08099C36
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #0
	strb r0, [r1]
	str r0, [r5]
_08099C36:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08099CDA
	ldr r1, [r5]
	cmp r1, #0
	beq _08099CAC
	adds r0, r4, #0
	adds r0, #0xc0
	ldrb r2, [r0]
	cmp r2, #1
	bne _08099C6C
	subs r0, #0x1c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bgt _08099C66
	movs r0, #0
	strb r0, [r4, #0xf]
	b _08099CBA
_08099C66:
	movs r1, #0
	movs r0, #7
	b _08099CD6
_08099C6C:
	cmp r2, #2
	bne _08099C96
	adds r0, r4, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bgt _08099C90
	movs r0, #0
	strb r0, [r4, #0xf]
	ldr r1, _08099C8C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	b _08099CC6
	.align 2, 0
_08099C8C: .4byte gEnemyFnTable
_08099C90:
	movs r1, #0
	movs r0, #9
	b _08099CD6
_08099C96:
	adds r0, r4, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #1
	bgt _08099CA8
	movs r0, #0
	strb r0, [r4, #0xf]
	b _08099CBA
_08099CA8:
	movs r1, #0
	b _08099CD4
_08099CAC:
	adds r0, r4, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #1
	bgt _08099CD4
	strb r1, [r4, #0xf]
_08099CBA:
	ldr r1, _08099CD0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
_08099CC6:
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _08099CDA
	.align 2, 0
_08099CD0: .4byte gEnemyFnTable
_08099CD4:
	movs r0, #1
_08099CD6:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099CDA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start nop_08099ce0
nop_08099ce0: @ 0x08099CE0
	movs r0, #1
	bx lr

	thumb_func_start FUN_08099ce4
FUN_08099ce4: @ 0x08099CE4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08099CF4
	cmp r5, #1
	beq _08099D08
	b _08099D4E
_08099CF4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099D74 @ =0x0836A550
	bl SetDDP
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099D08:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08099D18
	str r1, [r4, #0x60]
_08099D18:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r2, _08099D78 @ =0xFFFFF600
	adds r0, r0, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bne _08099D44
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _08099D4E
_08099D44:
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r0, #0
	str r0, [r4, #0x60]
_08099D4E:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08099D6C
	adds r0, r4, #0
	adds r0, #0xc0
	movs r1, #0
	strb r1, [r0]
	str r1, [r5]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099D6C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08099D74: .4byte 0x0836A550
_08099D78: .4byte 0xFFFFF600

	thumb_func_start nop_08099d7c
nop_08099d7c: @ 0x08099D7C
	movs r0, #1
	bx lr

	thumb_func_start nop_08099d80
nop_08099d80: @ 0x08099D80
	bx lr
	.align 2, 0

	thumb_func_start nop_08099d84
nop_08099d84: @ 0x08099D84
	movs r0, #1
	bx lr

	thumb_func_start FUN_08099d88
FUN_08099d88: @ 0x08099D88
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08099D98
	cmp r5, #1
	beq _08099DAC
	b _08099DF2
_08099D98:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099E18 @ =0x0836A550
	bl SetDDP
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099DAC:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08099DBC
	str r1, [r4, #0x60]
_08099DBC:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r2, _08099E1C @ =0xFFFFF600
	adds r0, r0, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bne _08099DE8
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _08099DF2
_08099DE8:
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r0, #0
	str r0, [r4, #0x60]
_08099DF2:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08099E10
	adds r0, r4, #0
	adds r0, #0xc0
	movs r1, #0
	strb r1, [r0]
	str r1, [r5]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099E10:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08099E18: .4byte 0x0836A550
_08099E1C: .4byte 0xFFFFF600

	thumb_func_start cattatank_08099e20
cattatank_08099e20: @ 0x08099E20
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xbc
	ldr r5, [r6]
	cmp r5, #0
	bne _08099EAA
	adds r0, #0x8c
	ldr r0, [r0]
	movs r7, #1
	ands r0, r7
	cmp r0, #0
	beq _08099EAA
	ldr r2, _08099E6C @ =0x0836A670
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	adds r1, r0, #0
	str r1, [r6]
	ldrb r0, [r4, #0xd]
	cmp r0, #6
	beq _08099E84
	cmp r1, #0
	beq _08099EAA
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _08099E70
	adds r0, r4, #0
	adds r0, #0xc0
	strb r7, [r0]
	movs r0, #7
	b _08099E7E
	.align 2, 0
_08099E6C: .4byte 0x0836A670
_08099E70:
	cmp r1, #0x30
	bne _08099EAA
	adds r0, r4, #0
	adds r0, #0xc0
	movs r1, #2
	strb r1, [r0]
	movs r0, #9
_08099E7E:
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	b _08099EAA
_08099E84:
	cmp r1, #0
	beq _08099EAA
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _08099E9E
	adds r0, r4, #0
	adds r0, #0xc0
	strb r7, [r0]
	b _08099EAA
_08099E9E:
	cmp r1, #0x30
	bne _08099EAA
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #2
	strb r0, [r1]
_08099EAA:
	movs r0, #1
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08099eb4
FUN_08099eb4: @ 0x08099EB4
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r5, r1, #0
	ldr r0, [r2, #0xc]
	ldr r3, [r0, #4]
	ldrb r0, [r3, #4]
	cmp r0, #3
	beq _08099ECC
	cmp r0, #0xe
	beq _08099ECC
	cmp r0, #0xf
	bne _08099EF6
_08099ECC:
	ldr r4, [r2, #0x2c]
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08099EF6
	ldr r1, [r4, #0x54]
	ldr r0, [r5]
	cmp r1, r0
	bge _08099EEE
	adds r1, r4, #0
	adds r1, #0xba
	movs r0, #0xff
	b _08099EF4
_08099EEE:
	adds r1, r4, #0
	adds r1, #0xba
	movs r0, #0xfe
_08099EF4:
	strb r0, [r1]
_08099EF6:
	ldr r0, [r3, #4]
	ldr r1, _08099F28 @ =0x000200FF
	ands r0, r1
	subs r1, #0xfd
	cmp r0, r1
	bne _08099F2C
	ldr r4, [r2, #0x2c]
	ldrb r0, [r4, #0xd]
	cmp r0, #6
	beq _08099F4E
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08099F20
	adds r0, r4, #0
	bl isFrozen
_08099F20:
	movs r1, #0
	movs r0, #6
	b _08099F4A
	.align 2, 0
_08099F28: .4byte 0x000200FF
_08099F2C:
	ldr r4, [r2, #0x2c]
	ldr r0, [r2, #4]
	ldrb r0, [r0]
	cmp r0, #2
	bne _08099F4E
	ldrb r0, [r3, #6]
	cmp r0, #0x40
	beq _08099F4E
	adds r0, r4, #0
	bl isFrozen
	adds r1, r0, #0
	cmp r1, #0
	bne _08099F4E
	movs r0, #5
_08099F4A:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099F4E:
	pop {r4, r5}
	pop {r0}
	bx r0

