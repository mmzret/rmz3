	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start babyelf_08046a7c
babyelf_08046a7c: @ 0x08046A7C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _08046AFC
	cmp r5, #1
	bgt _08046A90
	cmp r5, #0
	beq _08046A9C
	b _08046CBE
_08046A90:
	cmp r5, #2
	beq _08046B58
	cmp r5, #3
	bne _08046A9A
	b _08046C3E
_08046A9A:
	b _08046CBE
_08046A9C:
	adds r6, r4, #0
	adds r6, #0xc6
	ldrb r0, [r6]
	cmp r0, #0
	beq _08046AAC
	bl RemovePaletteAnimation
	strb r5, [r6]
_08046AAC:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _08046AD0
	adds r0, r4, #0
	bl _GetEntityPaletteID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x15
	bl StartPaletteAnimation
	movs r0, #0x15
	b _08046AEC
_08046AD0:
	adds r0, r4, #0
	bl _GetEntityPaletteID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r3, #0
	orrs r1, r0
	movs r0, #0x10
	bl StartPaletteAnimation
	movs r0, #0x10
_08046AEC:
	strb r0, [r6]
	adds r1, r4, #0
	adds r1, #0xc4
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08046AFC:
	adds r2, r4, #0
	adds r2, #0xc4
	adds r3, r4, #0
	adds r3, #0xc7
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _08046B50 @ =0x0000FFFD
	adds r0, r0, r1
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _08046B54 @ =0x0000FF7F
	cmp r1, r0
	bhi _08046B26
	ldrb r0, [r3]
	cmp r0, #0
	beq _08046B30
_08046B26:
	cmp r1, #0x80
	bls _08046B36
	ldrb r0, [r3]
	cmp r0, #1
	bne _08046B36
_08046B30:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08046B36:
	adds r0, r4, #0
	bl babyelf_08045c84
	adds r0, r4, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	bl StepPaletteAnimation
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _08046CBE
	.align 2, 0
_08046B50: .4byte 0x0000FFFD
_08046B54: .4byte 0x0000FF7F
_08046B58:
	movs r0, #0x8b
	lsls r0, r0, #1
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0xc8
	movs r6, #0
	strb r6, [r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080bc5fc
	adds r5, r4, #0
	adds r5, #0xc6
	ldrb r0, [r5]
	cmp r0, #0
	beq _08046B80
	bl RemovePaletteAnimation
	strb r6, [r5]
_08046B80:
	adds r0, r4, #0
	adds r0, #0x22
	strb r6, [r0]
	ldr r1, _08046BEC @ =0x00003301
	adds r0, r4, #0
	bl SetMotion
	ldrb r6, [r4, #0x10]
	cmp r6, #0
	bne _08046BC2
	adds r0, r4, #0
	bl _GetEntityPaletteID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x18
	bl StartPaletteAnimation
	movs r0, #0x18
	strb r0, [r5]
	bl StepPaletteAnimation
	ldrb r0, [r5]
	cmp r0, #0
	beq _08046BC2
	bl RemovePaletteAnimation
	strb r6, [r5]
_08046BC2:
	adds r0, r4, #0
	adds r0, #0xc7
	ldrb r0, [r0]
	cmp r0, #0
	bne _08046BF4
	ldr r2, _08046BF0 @ =gSineTable
	adds r0, r2, #0
	adds r0, #0xa0
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #7
	cmp r0, #0
	bge _08046BE2
	adds r0, #0xff
_08046BE2:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	movs r0, #0x20
	ldrsh r1, [r2, r0]
	b _08046C1A
	.align 2, 0
_08046BEC: .4byte 0x00003301
_08046BF0: .4byte gSineTable
_08046BF4:
	ldr r2, _08046CC4 @ =gSineTable
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #7
	cmp r0, #0
	bge _08046C0C
	adds r0, #0xff
_08046C0C:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
_08046C1A:
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #7
	cmp r0, #0
	bge _08046C26
	adds r0, #0xff
_08046C26:
	asrs r0, r0, #8
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	movs r0, #0xa
	strb r0, [r4, #0x12]
	movs r0, #0x1a
	strb r0, [r4, #0x13]
	movs r0, #0x5a
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08046C3E:
	ldr r0, [r4, #0x64]
	subs r1, r0, #1
	str r1, [r4, #0x64]
	cmp r1, #0
	bne _08046C4E
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08046C4E:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _08046CA8
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08046C78
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08046C78
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	adds r1, r4, #0
	adds r1, #0xb8
	ldr r1, [r1]
	ldr r3, _08046CC8 @ =0xFFFFB000
	adds r1, r1, r3
	bl FUN_080bc660
_08046C78:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _08046CA8
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08046CA8
	movs r5, #0
	adds r7, r4, #0
	adds r7, #0xb4
	adds r6, r4, #0
	adds r6, #0xb8
_08046C92:
	ldr r0, [r7]
	ldr r1, [r6]
	ldr r2, _08046CC8 @ =0xFFFFB000
	adds r1, r1, r2
	lsls r2, r5, #0x1d
	lsrs r2, r2, #0x18
	bl FUN_0809f8fc
	adds r5, #1
	cmp r5, #7
	ble _08046C92
_08046CA8:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
_08046CBE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08046CC4: .4byte gSineTable
_08046CC8: .4byte 0xFFFFB000

	thumb_func_start FUN_08046ccc
FUN_08046ccc: @ 0x08046CCC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #1
	beq _08046D3E
	cmp r0, #1
	bgt _08046CE4
	cmp r0, #0
	beq _08046CF0
	b _08046E50
_08046CE4:
	cmp r0, #2
	beq _08046DC0
	cmp r0, #3
	bne _08046CEE
	b _08046E22
_08046CEE:
	b _08046E50
_08046CF0:
	movs r4, #0
	adds r2, r7, #0
	adds r2, #0xb4
	ldr r1, [r7, #0x54]
	ldr r0, [r2]
	cmp r1, r0
	ble _08046D00
	movs r4, #1
_08046D00:
	adds r3, r7, #0
	adds r3, #0xc7
	strb r4, [r3]
	ldr r2, [r2]
	ldr r0, _08046DB8 @ =0xFFFF5000
	adds r2, r2, r0
	str r2, [r7, #0x54]
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #0xd
	adds r2, r2, r0
	str r2, [r7, #0x54]
	adds r0, r7, #0
	adds r0, #0xb8
	ldr r1, [r0]
	movs r2, #0xc0
	lsls r2, r2, #6
	adds r1, r1, r2
	str r1, [r7, #0x58]
	ldrb r0, [r3]
	lsls r0, r0, #0x10
	subs r1, r1, r0
	str r1, [r7, #0x58]
	movs r0, #0x3c
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08046D3E:
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r6, [r7, #0x54]
	subs r0, r0, r6
	ldr r3, _08046DBC @ =0xFFFFA800
	adds r0, r0, r3
	adds r1, r7, #0
	adds r1, #0xc7
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #2
	subs r1, r1, r2
	lsls r1, r1, #0xc
	adds r0, r0, r1
	adds r2, r7, #0
	adds r2, #0xb8
	ldr r5, [r7, #0x58]
	movs r3, #0xa0
	lsls r3, r3, #7
	adds r1, r5, r3
	ldr r4, [r2]
	subs r4, r4, r1
	movs r1, #0xc
	bl __divsi3
	mov r8, r0
	adds r0, r4, #0
	movs r1, #0xc
	bl __divsi3
	add r6, r8
	str r6, [r7, #0x54]
	adds r5, r5, r0
	str r5, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08046DAE
	adds r1, r7, #0
	adds r1, #0xc8
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08046DAE:
	adds r0, r7, #0
	bl UpdateEntityAnim
	b _08046E50
	.align 2, 0
_08046DB8: .4byte 0xFFFF5000
_08046DBC: .4byte 0xFFFFA800
_08046DC0:
	ldrb r0, [r7, #0x10]
	adds r1, r7, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r1, #0xc4
	lsls r1, r1, #6
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0x10]
	cmp r0, #0
	bne _08046DFA
	adds r0, r7, #0
	bl _GetEntityPaletteID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x16
	bl StartPaletteAnimation
	adds r1, r7, #0
	adds r1, #0xc6
	movs r0, #0x16
	b _08046E1A
_08046DFA:
	adds r0, r7, #0
	bl _GetEntityPaletteID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r3, #0
	orrs r1, r0
	movs r0, #0x11
	bl StartPaletteAnimation
	adds r1, r7, #0
	adds r1, #0xc6
	movs r0, #0x11
_08046E1A:
	strb r0, [r1]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08046E22:
	adds r4, r7, #0
	adds r4, #0xc6
	ldrb r0, [r4]
	bl StepPaletteAnimation
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _08046E4A
	ldrb r0, [r4]
	cmp r0, #0
	beq _08046E42
	bl RemovePaletteAnimation
	movs r0, #0
	strb r0, [r4]
_08046E42:
	movs r1, #0
	movs r0, #1
	strb r0, [r7, #0xd]
	strb r1, [r7, #0xe]
_08046E4A:
	adds r0, r7, #0
	bl UpdateEntityAnim
_08046E50:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
