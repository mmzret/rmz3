	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080cdd64
FUN_080cdd64: @ 0x080CDD64
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r0, [r7, #0x2c]
	mov sb, r0
	adds r0, r7, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x24
	ands r0, r1
	cmp r0, #0
	bne _080CDD90
	mov r0, sb
	adds r0, #0x8c
	ldr r0, [r0]
	ands r0, r1
	adds r1, r7, #0
	adds r1, #0xbc
	cmp r0, #0
	beq _080CDD98
_080CDD90:
	adds r1, r7, #0
	adds r1, #0xbc
	movs r0, #1
	strb r0, [r1]
_080CDD98:
	ldr r2, [r7, #0x54]
	mov r0, sb
	ldr r3, [r0, #0x54]
	subs r2, r2, r3
	ldr r0, _080CDE0C @ =0xFFFFE800
	adds r2, r2, r0
	ldrb r0, [r1]
	ldr r4, [r7, #0x54]
	cmp r0, #0
	bne _080CDDD6
	ldr r0, _080CDE10 @ =0x00001DFF
	cmp r2, r0
	bgt _080CDE24
	ldr r0, _080CDE14 @ =pZero2
	ldr r2, [r0]
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r3, r1
	ldr r1, [r2, #0x54]
	cmp r1, r0
	blt _080CDE24
	ldr r3, _080CDE18 @ =0xFFFFF400
	adds r0, r4, r3
	cmp r1, r0
	bgt _080CDE24
	ldr r0, [r7, #0x58]
	ldr r1, _080CDE1C @ =0xFFFFE200
	adds r0, r0, r1
	ldr r1, [r2, #0x58]
	cmp r1, r0
	ble _080CDE24
_080CDDD6:
	ldr r0, _080CDE14 @ =pZero2
	ldr r1, [r0]
	adds r0, r7, #0
	adds r0, #0xb8
	ldr r0, [r0]
	str r0, [r1, #0x54]
	adds r0, r7, #0
	adds r0, #0x74
	ldr r5, _080CDE20 @ =0x08370220
	adds r1, r5, #0
	bl SetDDP
	ldrb r1, [r7, #0xb]
	movs r4, #0xf7
	adds r0, r4, #0
	ands r0, r1
	strb r0, [r7, #0xb]
	mov r0, sb
	adds r0, #0x74
	adds r1, r5, #0
	bl SetDDP
	mov r3, sb
	ldrb r0, [r3, #0xb]
	ands r4, r0
	strb r4, [r3, #0xb]
	b _080CDE56
	.align 2, 0
_080CDE0C: .4byte 0xFFFFE800
_080CDE10: .4byte 0x00001DFF
_080CDE14: .4byte pZero2
_080CDE18: .4byte 0xFFFFF400
_080CDE1C: .4byte 0xFFFFE200
_080CDE20: .4byte 0x08370220
_080CDE24:
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _080CDE64 @ =0x08370208
	mov r8, r1
	bl SetDDP
	ldrb r0, [r7, #0xb]
	movs r4, #8
	orrs r0, r4
	strb r0, [r7, #0xb]
	ldr r6, _080CDE68 @ =0x08370238
	str r6, [r7, #0x30]
	movs r5, #1
	strh r5, [r7, #0x26]
	mov r0, sb
	adds r0, #0x74
	mov r1, r8
	bl SetDDP
	mov r3, sb
	ldrb r0, [r3, #0xb]
	orrs r4, r0
	strb r4, [r3, #0xb]
	str r6, [r3, #0x30]
	strh r5, [r3, #0x26]
_080CDE56:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CDE64: .4byte 0x08370208
_080CDE68: .4byte 0x08370238

