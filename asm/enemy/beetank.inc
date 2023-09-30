	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateBeetank
CreateBeetank: @ 0x0807B860
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _0807B8B4 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0807B8AC
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0807B8B8 @ =gEnemyFnTable
	movs r0, #0x1e
	strb r0, [r3, #9]
	ldr r0, [r1, #0x78]
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
_0807B8AC:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0807B8B4: .4byte gZakoHeaderPtr
_0807B8B8: .4byte gEnemyFnTable

	thumb_func_start Beetank_Init
Beetank_Init: @ 0x0807B8BC
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r2, #0
	movs r1, #0xef
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
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	ldr r4, _0807B924 @ =0xFFFFF400
	adds r1, r1, r4
	bl PushoutToLeft1
	adds r5, r0, #0
	str r5, [sp]
	ldr r0, [r6, #0x54]
	ldr r2, _0807B928 @ =0xFFFFF000
	adds r0, r0, r2
	ldr r1, [r6, #0x58]
	adds r1, r1, r4
	bl PushoutToRight1
	str r0, [sp, #4]
	cmp r5, #0
	beq _0807B92C
	cmp r0, #0
	bne _0807B938
	ldr r0, [r6, #0x54]
	ldr r1, [sp]
	adds r0, r0, r1
	b _0807B936
	.align 2, 0
_0807B924: .4byte 0xFFFFF400
_0807B928: .4byte 0xFFFFF000
_0807B92C:
	cmp r0, #0
	beq _0807B938
	ldr r0, [r6, #0x54]
	ldr r2, [sp, #4]
	adds r0, r0, r2
_0807B936:
	str r0, [r6, #0x54]
_0807B938:
	ldr r0, [r6, #0x54]
	ldr r1, _0807B968 @ =0xFFFFF000
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	ldr r4, _0807B96C @ =0xFFFFFA00
	adds r1, r1, r4
	bl FUN_08009f6c
	adds r5, r0, #0
	str r5, [sp]
	ldr r0, [r6, #0x54]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r0, r2
	ldr r1, [r6, #0x58]
	adds r1, r1, r4
	bl FUN_08009f6c
	str r0, [sp, #4]
	ldr r1, [sp]
	cmp r1, r0
	bge _0807B970
	str r5, [r6, #0x58]
	b _0807B972
	.align 2, 0
_0807B968: .4byte 0xFFFFF000
_0807B96C: .4byte 0xFFFFFA00
_0807B970:
	str r0, [r6, #0x58]
_0807B972:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0807B9E4 @ =0x083679EC
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
	bl InitBody
	str r6, [r4, #0x2c]
	ldr r0, _0807B9E8 @ =nop_0807bea4
	str r0, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0x5c
	str r5, [r0, #4]
	str r5, [r6, #0x5c]
	adds r0, #0x60
	str r5, [r0]
	subs r0, #4
	strb r5, [r0]
	ldr r1, _0807B9EC @ =gEnemyFnTable
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
	beq _0807B9D6
	movs r1, #0xf8
	lsls r1, r1, #6
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
_0807B9D6:
	adds r0, r6, #0
	bl Beetank_Update
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807B9E4: .4byte 0x083679EC
_0807B9E8: .4byte nop_0807bea4
_0807B9EC: .4byte gEnemyFnTable

	thumb_func_start Beetank_Update
Beetank_Update: @ 0x0807B9F0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0807BA24
	ldr r1, _0807BA20 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl Beetank_Die
	b _0807BADA
	.align 2, 0
_0807BA20: .4byte gEnemyFnTable
_0807BA24:
	ldr r1, _0807BAA4 @ =0x083679C4
	ldrb r0, [r5, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_0807be50
	ldr r0, [r5, #0x54]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _0807BAA8 @ =0xFFFFFC00
	adds r1, r1, r2
	bl PushoutToLeft1
	adds r6, r0, #0
	cmp r0, #0
	beq _0807BA58
	ldr r0, [r5, #0x54]
	adds r0, r0, r6
	str r0, [r5, #0x54]
_0807BA58:
	ldr r0, [r5, #0x54]
	ldr r1, _0807BAA8 @ =0xFFFFFC00
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _0807BAA8 @ =0xFFFFFC00
	adds r1, r1, r2
	bl PushoutToRight1
	adds r6, r0, #0
	cmp r0, #0
	beq _0807BA74
	ldr r0, [r5, #0x54]
	adds r0, r0, r6
	str r0, [r5, #0x54]
_0807BA74:
	ldr r0, [r5, #0x54]
	ldr r1, _0807BAAC @ =0xFFFFF000
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _0807BAB0 @ =0xFFFFFA00
	mov r8, r2
	add r1, r8
	bl FUN_08009f6c
	adds r4, r0, #0
	adds r6, r4, #0
	ldr r0, [r5, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	add r1, r8
	bl FUN_08009f6c
	adds r7, r0, #0
	cmp r6, r7
	bge _0807BAB4
	str r4, [r5, #0x58]
	b _0807BAB6
	.align 2, 0
_0807BAA4: .4byte 0x083679C4
_0807BAA8: .4byte 0xFFFFFC00
_0807BAAC: .4byte 0xFFFFF000
_0807BAB0: .4byte 0xFFFFFA00
_0807BAB4:
	str r0, [r5, #0x58]
_0807BAB6:
	adds r0, r5, #0
	bl isFrozen
	cmp r0, #0
	beq _0807BACA
	ldrb r1, [r5, #0xd]
	adds r0, r5, #0
	adds r0, #0xba
	strb r1, [r0]
	b _0807BADA
_0807BACA:
	ldr r0, _0807BAE4 @ =0x083679D8
	ldrb r1, [r5, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
_0807BADA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807BAE4: .4byte 0x083679D8

	thumb_func_start Beetank_Die
Beetank_Die: @ 0x0807BAE8
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _0807BB1C @ =gStageRun
	ldr r0, [r0, #0x30]
	cmp r0, #0
	beq _0807BB28
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #5
	adds r1, r5, #0
	bl TryDropItem
	movs r0, #0
	bl PlaySound
	ldr r2, _0807BB20 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0807BB24 @ =0x0000270E
	cmp r1, r0
	bhi _0807BB16
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0807BB16:
	adds r0, r4, #0
	adds r1, r5, #0
	b _0807BC5A
	.align 2, 0
_0807BB1C: .4byte gStageRun
_0807BB20: .4byte gMission
_0807BB24: .4byte 0x0000270E
_0807BB28:
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _0807BB30
	b _0807BC78
_0807BB30:
	lsls r0, r0, #2
	ldr r1, _0807BB3C @ =_0807BB40
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807BB3C: .4byte _0807BB40
_0807BB40: @ jump table
	.4byte _0807BB54 @ case 0
	.4byte _0807BBAA @ case 1
	.4byte _0807BBE4 @ case 2
	.4byte _0807BBF4 @ case 3
	.4byte _0807BC30 @ case 4
_0807BB54:
	ldr r1, _0807BBCC @ =0x00003E02
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r2, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x5c
	str r1, [r0, #4]
	str r1, [r4, #0x5c]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0807BBD0 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r0, #1
	ands r1, r0
	mov r0, sp
	bl createGhost44
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #5
	bl TryDropItem
	movs r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807BBAA:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	movs r1, #0xff
	ands r0, r1
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0807BBD4
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0807BBDA
	.align 2, 0
_0807BBCC: .4byte 0x00003E02
_0807BBD0: .4byte 0xFFFFF800
_0807BBD4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0807BBDA:
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0807BC78
	b _0807BC28
_0807BBE4:
	adds r0, r4, #0
	bl PaintEntityWhite
	movs r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807BBF4:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	movs r1, #0xff
	ands r0, r1
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0807BC0E
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0807BC14
_0807BC0E:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0807BC14:
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0807BC78
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x3c
	strb r0, [r4, #0x12]
_0807BC28:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0807BC78
_0807BC30:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0807BC40
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807BC78
_0807BC40:
	movs r0, #0
	bl PlaySound
	ldr r2, _0807BC80 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0807BC84 @ =0x0000270E
	cmp r1, r0
	bhi _0807BC54
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0807BC54:
	adds r1, r4, #0
	adds r1, #0x54
	adds r0, r4, #0
_0807BC5A:
	bl TryDropZakoDisk
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0807BC88 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_0807BC78:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807BC80: .4byte gMission
_0807BC84: .4byte 0x0000270E
_0807BC88: .4byte gEnemyFnTable

	thumb_func_start nop_0807bc8c
nop_0807bc8c: @ 0x0807BC8C
	movs r0, #1
	bx lr

	thumb_func_start FUN_0807bc90
FUN_0807bc90: @ 0x0807BC90
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0807BCA0
	cmp r0, #1
	beq _0807BCB4
	b _0807BD36
_0807BCA0:
	movs r1, #0xf8
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x78
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807BCB4:
	ldr r0, _0807BCDC @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0807BCE0
	ldrb r2, [r4, #0xa]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	bne _0807BD18
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0807BCFA
	movs r0, #0x10
	orrs r0, r2
	b _0807BCFE
	.align 2, 0
_0807BCDC: .4byte pZero2
_0807BCE0:
	ldrb r2, [r4, #0xa]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0807BD18
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0807BCFA
	movs r0, #0x10
	orrs r0, r2
	b _0807BCFE
_0807BCFA:
	movs r0, #0xef
	ands r0, r2
_0807BCFE:
	strb r0, [r4, #0xa]
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
_0807BD18:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0807BD2E
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807BD36
_0807BD2E:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0807BD36:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start nop_0807bd3c
nop_0807bd3c: @ 0x0807BD3C
	movs r0, #1
	bx lr

	thumb_func_start FUN_0807bd40
FUN_0807bd40: @ 0x0807BD40
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0807BD6E
	cmp r0, #1
	bgt _0807BD56
	cmp r0, #0
	beq _0807BD5C
	b _0807BDDA
_0807BD56:
	cmp r0, #2
	beq _0807BDC4
	b _0807BDDA
_0807BD5C:
	movs r0, #4
	strb r0, [r4, #0x12]
	ldr r1, _0807BD98 @ =0x00003E01
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807BD6E:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0807BD7E
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807BDC4
_0807BD7E:
	ldr r3, [r4, #0x54]
	str r3, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0807BD9C @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0807BDA0
	ldr r2, _0807BD9C @ =0xFFFFF000
	b _0807BDA4
	.align 2, 0
_0807BD98: .4byte 0x00003E01
_0807BD9C: .4byte 0xFFFFF000
_0807BDA0:
	movs r2, #0x80
	lsls r2, r2, #5
_0807BDA4:
	adds r0, r3, r2
	str r0, [sp]
	lsls r2, r1, #0x18
	lsrs r2, r2, #0x1c
	movs r0, #1
	ands r2, r0
	mov r0, sp
	mov r1, sp
	bl FUN_080a244c
	movs r0, #0x2d
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807BDC4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0807BDDA
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0807BDDA:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start nop_0807bde4
nop_0807bde4: @ 0x0807BDE4
	movs r0, #1
	bx lr

	thumb_func_start FUN_0807bde8
FUN_0807bde8: @ 0x0807BDE8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0807BDF6
	movs r0, #1
	strb r0, [r4, #0xe]
_0807BDF6:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0807BE0C
	movs r0, #0
	str r0, [r5]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0807BE0C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807be14
FUN_0807be14: @ 0x0807BE14
	movs r0, #1
	bx lr

	thumb_func_start nop_0807be18
nop_0807be18: @ 0x0807BE18
	bx lr
	.align 2, 0

	thumb_func_start FUN_0807be1c
FUN_0807be1c: @ 0x0807BE1C
	movs r0, #1
	bx lr

	thumb_func_start FUN_0807be20
FUN_0807be20: @ 0x0807BE20
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0807BE32
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807BE32:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0807BE48
	movs r0, #0
	str r0, [r5]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0807BE48:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807be50
FUN_0807be50: @ 0x0807BE50
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xbc
	ldr r5, [r6]
	cmp r5, #0
	bne _0807BE9A
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0807BE9A
	ldr r2, _0807BE8C @ =0x08367A1C
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _0807BE9A
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _0807BE90
	movs r0, #2
	b _0807BE96
	.align 2, 0
_0807BE8C: .4byte 0x08367A1C
_0807BE90:
	cmp r1, #0x30
	bne _0807BE9A
	movs r0, #4
_0807BE96:
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
_0807BE9A:
	movs r0, #1
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start nop_0807bea4
nop_0807bea4: @ 0x0807BEA4
	bx lr
	.align 2, 0
