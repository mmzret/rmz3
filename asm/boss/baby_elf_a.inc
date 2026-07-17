	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08045b68
FUN_08045b68: @ 0x08045B68
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _08045BBC
	adds r5, r4, #0
	adds r5, #0xd0
	ldrb r0, [r5]
	cmp r0, #0
	beq _08045B82
	cmp r0, #1
	beq _08045BA4
	b _08045BBC
_08045B82:
	adds r0, r4, #0
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #0
	beq _08045BBC
	movs r1, #0xc8
	lsls r1, r1, #2
	movs r0, #0x19
	bl StartPaletteAnimation
	movs r0, #0x19
	bl StepPaletteAnimation
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _08045BBC
_08045BA4:
	movs r0, #0x19
	bl StepPaletteAnimation
	adds r0, r4, #0
	adds r0, #0xcf
	ldrb r4, [r0]
	cmp r4, #0
	bne _08045BBC
	movs r0, #0x19
	bl RemovePaletteAnimation
	strb r4, [r5]
_08045BBC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start babyelf_08045bc4
babyelf_08045bc4: @ 0x08045BC4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov ip, r0
	ldr r0, [r0, #0x2c]
	mov sb, r0
	movs r7, #0
	mov r0, ip
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x2f
	bgt _08045BE2
	movs r7, #1
_08045BE2:
	mov r2, ip
	ldrb r0, [r2, #0x11]
	lsls r0, r0, #1
	adds r7, r7, r0
	mov r4, ip
	adds r4, #0xcd
	ldr r6, _08045BFC @ =RNG_0202f388
	mov r5, ip
	adds r5, #0xcc
	ldr r0, _08045C00 @ =u8_ARRAY_083626d4
	mov r8, r0
	b _08045C0A
	.align 2, 0
_08045BFC: .4byte RNG_0202f388
_08045C00: .4byte u8_ARRAY_083626d4
_08045C04:
	ldrb r0, [r4]
	cmp r0, #1
	bls _08045C2E
_08045C0A:
	ldr r1, [r6]
	ldr r0, _08045C40 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08045C44 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r3, r0, #0x11
	movs r0, #0xf
	ands r3, r0
	lsls r2, r7, #4
	adds r0, r3, r2
	add r0, r8
	ldrb r1, [r5]
	ldrb r0, [r0]
	cmp r1, r0
	beq _08045C04
_08045C2E:
	adds r0, r3, r2
	add r0, r8
	ldrb r1, [r0]
	ldrb r0, [r5]
	cmp r0, r1
	bne _08045C48
	ldrb r0, [r4]
	adds r0, #1
	b _08045C4C
	.align 2, 0
_08045C40: .4byte 0x000343FD
_08045C44: .4byte 0x00269EC3
_08045C48:
	movs r0, #0
	strb r1, [r5]
_08045C4C:
	strb r0, [r4]
	adds r0, r3, r2
	add r0, r8
	ldrb r1, [r0]
	cmp r1, #1
	beq _08045C78
	mov r2, ip
	strb r1, [r2, #0xd]
	ldrb r0, [r0]
	cmp r0, #5
	bne _08045C6A
	movs r0, #6
	mov r1, sb
	strb r0, [r1, #0xd]
	b _08045C6E
_08045C6A:
	mov r2, sb
	strb r0, [r2, #0xd]
_08045C6E:
	movs r0, #0
	mov r1, ip
	strb r0, [r1, #0xe]
	mov r2, sb
	strb r0, [r2, #0xe]
_08045C78:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start babyelf_08045c84
babyelf_08045c84: @ 0x08045C84
	push {r4, r5, lr}
	mov ip, r0
	adds r0, #0xbc
	ldr r1, [r0]
	mov r0, ip
	str r1, [r0, #0x54]
	adds r0, #0xc0
	ldr r4, [r0]
	mov r2, ip
	str r4, [r2, #0x58]
	adds r0, #4
	ldrh r3, [r0]
	ldr r0, _08045CD4 @ =0x000001FF
	ands r3, r0
	cmp r3, #0xff
	bgt _08045CE0
	ldr r2, _08045CD8 @ =gSineTable
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r5, #0
	ldrsh r0, [r0, r5]
	lsls r0, r0, #4
	adds r0, r1, r0
	mov r1, ip
	str r0, [r1, #0x54]
	ldr r5, _08045CDC @ =0xFFFFF000
	adds r1, r4, r5
	mov r0, ip
	str r1, [r0, #0x58]
	adds r0, r3, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #4
	adds r1, r1, r0
	b _08045D14
	.align 2, 0
_08045CD4: .4byte 0x000001FF
_08045CD8: .4byte gSineTable
_08045CDC: .4byte 0xFFFFF000
_08045CE0:
	ldr r0, _08045D20 @ =0xFFFFFF00
	adds r3, r3, r0
	ldr r2, _08045D24 @ =gSineTable
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r5, #0
	ldrsh r0, [r0, r5]
	lsls r0, r0, #4
	adds r0, r1, r0
	mov r1, ip
	str r0, [r1, #0x54]
	movs r5, #0x80
	lsls r5, r5, #5
	adds r1, r4, r5
	mov r0, ip
	str r1, [r0, #0x58]
	adds r0, r3, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #4
	subs r1, r1, r0
_08045D14:
	mov r5, ip
	str r1, [r5, #0x58]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08045D20: .4byte 0xFFFFFF00
_08045D24: .4byte gSineTable

