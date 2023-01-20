	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start initOldLifeSpace
initOldLifeSpace: @ 0x0800DB84
	ldr r0, _0800DBB4 @ =0x02002200
	ldr r2, _0800DBB8 @ =0x0002D028
	adds r1, r0, r2
	movs r2, #0
	str r2, [r1]
	ldr r3, _0800DBBC @ =0x0002D02C
	adds r1, r0, r3
	strb r2, [r1]
	adds r3, #4
	adds r1, r0, r3
	strh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	adds r3, #4
	adds r1, r0, r3
	strh r2, [r1]
	ldr r1, _0800DBC0 @ =0x0002D03A
	adds r0, r0, r1
	strh r2, [r0]
	bx lr
	.align 2, 0
_0800DBB4: .4byte 0x02002200
_0800DBB8: .4byte 0x0002D028
_0800DBBC: .4byte 0x0002D02C
_0800DBC0: .4byte 0x0002D03A

	thumb_func_start oldLifeSpace_0800dbc4
oldLifeSpace_0800dbc4: @ 0x0800DBC4
	push {r4, r5, lr}
	ldr r5, _0800DC4C @ =0x02002200
	ldr r0, _0800DC50 @ =0x0002D028
	adds r4, r5, r0
	ldr r0, [r4]
	cmp r0, #0
	bne _0800DBDA
	movs r0, #0
	bl FUN_080cb364
	str r0, [r4]
_0800DBDA:
	ldr r1, _0800DC54 @ =0x000007D4
	adds r0, r5, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #5
	bne _0800DC46
	movs r2, #0xff
	ands r2, r1
	cmp r2, #0
	bne _0800DC46
	ldr r0, _0800DC58 @ =0x0002D030
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x84
	bne _0800DC08
	strh r2, [r1]
	ldr r1, _0800DC5C @ =0x0002D032
	adds r0, r5, r1
	strh r2, [r0]
_0800DC08:
	ldr r0, _0800DC60 @ =0x0002D034
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x30
	bne _0800DC1C
	strh r2, [r1]
_0800DC1C:
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3c
	bne _0800DC2C
	strh r2, [r1]
_0800DC2C:
	ldr r0, _0800DC64 @ =0x0002D038
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb7
	bne _0800DC46
	strh r2, [r1]
	ldr r1, _0800DC68 @ =0x0002D03A
	adds r0, r5, r1
	strh r2, [r0]
_0800DC46:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800DC4C: .4byte 0x02002200
_0800DC50: .4byte 0x0002D028
_0800DC54: .4byte 0x000007D4
_0800DC58: .4byte 0x0002D030
_0800DC5C: .4byte 0x0002D032
_0800DC60: .4byte 0x0002D034
_0800DC64: .4byte 0x0002D038
_0800DC68: .4byte 0x0002D03A

	thumb_func_start FUN_0800dc6c
FUN_0800dc6c: @ 0x0800DC6C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r3, _0800DE10 @ =0x02002200
	ldr r1, _0800DE14 @ =0x000007D4
	adds r0, r3, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #5
	beq _0800DC84
	b _0800DE04
_0800DC84:
	movs r0, #0xff
	ands r0, r1
	cmp r0, #0
	beq _0800DC8E
	b _0800DE04
_0800DC8E:
	ldr r0, _0800DE18 @ =0x0002D030
	adds r2, r3, r0
	ldr r1, _0800DE1C @ =0x0833DFAC
	adds r0, #2
	adds r5, r3, r0
	ldrh r0, [r5]
	lsls r0, r0, #1
	adds r4, r1, #1
	adds r0, r0, r4
	ldrh r3, [r2]
	adds r7, r1, #0
	ldrb r0, [r0]
	cmp r3, r0
	blo _0800DCC0
	adds r2, r5, #0
	adds r1, r4, #0
_0800DCAE:
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	ldrh r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r3, r0
	bhs _0800DCAE
_0800DCC0:
	ldr r6, _0800DE20 @ =0x087044F8
	ldr r1, _0800DE10 @ =0x02002200
	mov sb, r1
	ldr r5, _0800DE24 @ =0x0002D032
	add r5, sb
	ldrh r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrb r0, [r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _0800DE28 @ =0x08704840
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	movs r2, #0x80
	lsls r2, r2, #7
	mov r8, r2
	mov r1, r8
	bl appendGraphicTask
	ldrh r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrb r0, [r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
	ldr r4, _0800DE2C @ =0x0002D034
	add r4, sb
	ldrh r0, [r4]
	movs r1, #0xc
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r5, _0800DE30 @ =0x087048A4
	adds r1, r1, r5
	ldr r0, [r6]
	adds r0, r0, r1
	mov r1, r8
	bl appendGraphicTask
	ldrh r0, [r4]
	movs r1, #0xc
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r5
	ldr r0, [r6]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
	ldrh r0, [r4]
	movs r1, #0xc
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r5, #0x50
	adds r1, r1, r5
	ldr r0, [r6]
	adds r0, r0, r1
	mov r1, r8
	bl appendGraphicTask
	ldrh r0, [r4]
	movs r1, #0xc
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r5
	ldr r0, [r6]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
	ldr r2, _0800DE34 @ =0x0002D038
	add r2, sb
	ldr r1, _0800DE38 @ =0x0833DFBE
	ldr r4, _0800DE3C @ =0x0002D03A
	add r4, sb
	ldrh r0, [r4]
	lsls r0, r0, #1
	adds r1, #1
	adds r0, r0, r1
	ldrh r3, [r2]
	ldrb r0, [r0]
	cmp r3, r0
	blo _0800DDBA
	adds r2, r4, #0
_0800DDA8:
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	ldrh r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r3, r0
	bhs _0800DDA8
_0800DDBA:
	ldr r0, _0800DE20 @ =0x087044F8
	mov r8, r0
	ldr r6, _0800DE38 @ =0x0833DFBE
	ldr r4, _0800DE10 @ =0x02002200
	ldr r1, _0800DE3C @ =0x0002D03A
	adds r4, r4, r1
	ldrh r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r5, _0800DE40 @ =0x08704958
	adds r1, r1, r5
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl appendGraphicTask
	ldrh r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r5
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
_0800DE04:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800DE10: .4byte 0x02002200
_0800DE14: .4byte 0x000007D4
_0800DE18: .4byte 0x0002D030
_0800DE1C: .4byte 0x0833DFAC
_0800DE20: .4byte 0x087044F8
_0800DE24: .4byte 0x0002D032
_0800DE28: .4byte 0x08704840
_0800DE2C: .4byte 0x0002D034
_0800DE30: .4byte 0x087048A4
_0800DE34: .4byte 0x0002D038
_0800DE38: .4byte 0x0833DFBE
_0800DE3C: .4byte 0x0002D03A
_0800DE40: .4byte 0x08704958

	thumb_func_start exitOldLifeSpace
exitOldLifeSpace: @ 0x0800DE44
	push {lr}
	ldr r0, _0800DE8C @ =0x02002200
	ldr r1, _0800DE90 @ =0x0002D028
	adds r0, r0, r1
	ldr r3, [r0]
	cmp r3, #0
	beq _0800DE88
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _0800DE94 @ =0x0836FB24
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
_0800DE88:
	pop {r0}
	bx r0
	.align 2, 0
_0800DE8C: .4byte 0x02002200
_0800DE90: .4byte 0x0002D028
_0800DE94: .4byte 0x0836FB24

	thumb_func_start FUN_0800de98
FUN_0800de98: @ 0x0800DE98
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _0800DEC0
	ldr r0, [r3, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r0, r0, #1
	ldr r1, _0800DEC4 @ =0x02002144
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, _0800DEC8 @ =0x0000FFFC
	ands r1, r2
	movs r2, #1
	orrs r1, r2
	strh r1, [r0]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_0800DEC0:
	pop {r0}
	bx r0
	.align 2, 0
_0800DEC4: .4byte 0x02002144
_0800DEC8: .4byte 0x0000FFFC

	thumb_func_start FUN_0800decc
FUN_0800decc: @ 0x0800DECC
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x14
	ldr r3, [r4, #0x34]
	ldr r2, [r4, #0x38]
	ldr r1, [r4, #0x3c]
	subs r1, r3, r1
	adds r1, #0xf
	ldr r0, [r4, #0x40]
	subs r0, r2, r0
	adds r5, r0, #0
	adds r5, #0xf
	movs r0, #0xc8
	lsls r0, r0, #3
	adds r2, r2, r0
	ldr r0, [r4, #0x2c]
	asrs r0, r0, #8
	adds r0, r0, r3
	str r0, [sp]
	ldr r0, [r4, #0x30]
	asrs r0, r0, #8
	adds r0, r0, r2
	str r0, [sp, #4]
	cmp r1, #0x1e
	bhi _0800DF12
	cmp r5, #0x1e
	bhi _0800DF12
	ldr r3, _0800DF38 @ =0x02002200
	ldr r1, _0800DF3C @ =0x0002D02C
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0800DF48
_0800DF12:
	ldr r0, [r4, #0x5c]
	lsrs r0, r0, #4
	lsls r0, r0, #1
	ldr r1, _0800DF40 @ =0x02002144
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #0xf8
	lsls r2, r2, #5
	ands r2, r0
	lsls r2, r2, #3
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r2, r2, r0
	ldr r3, _0800DF44 @ =0x020029E0
	adds r0, r6, #0
	mov r1, sp
	bl FUN_08006ae0
	b _0800DF70
	.align 2, 0
_0800DF38: .4byte 0x02002200
_0800DF3C: .4byte 0x0002D02C
_0800DF40: .4byte 0x02002144
_0800DF44: .4byte 0x020029E0
_0800DF48:
	ldr r0, [r4, #0x5c]
	lsrs r0, r0, #4
	lsls r0, r0, #1
	ldr r1, _0800DF94 @ =0x02002144
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #0xf8
	lsls r2, r2, #5
	ands r2, r0
	lsls r2, r2, #3
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r2, r2, r0
	movs r0, #0xfc
	lsls r0, r0, #3
	adds r3, r3, r0
	adds r0, r6, #0
	mov r1, sp
	bl FUN_08006bb4
_0800DF70:
	ldr r0, _0800DF98 @ =0x02002200
	ldr r1, _0800DF9C @ =0x0002D02C
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r1, [r4, #0x5c]
	lsrs r1, r1, #4
	lsls r1, r1, #2
	ldr r0, _0800DFA0 @ =0x0200214C
	adds r1, r1, r0
	adds r0, r6, #0
	bl FUN_08006dac
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800DF94: .4byte 0x02002144
_0800DF98: .4byte 0x02002200
_0800DF9C: .4byte 0x0002D02C
_0800DFA0: .4byte 0x0200214C

	thumb_func_start FUN_0800dfa4
FUN_0800dfa4: @ 0x0800DFA4
	push {r4, lr}
	adds r3, r0, #0
	ldrb r4, [r3, #0xe]
	cmp r4, #0
	bne _0800DFDE
	ldr r0, [r3, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r0, r0, #1
	ldr r1, _0800DFE4 @ =0x02002144
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, _0800DFE8 @ =0x0000FFFC
	ands r1, r2
	movs r2, #2
	orrs r1, r2
	strh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r3, #0x44]
	movs r0, #0x80
	str r0, [r3, #0x48]
	str r4, [r3, #0x4c]
	movs r0, #0xf0
	lsls r0, r0, #1
	str r0, [r3, #0x50]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_0800DFDE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800DFE4: .4byte 0x02002144
_0800DFE8: .4byte 0x0000FFFC

	thumb_func_start FUN_0800dfec
FUN_0800dfec: @ 0x0800DFEC
	push {r4, lr}
	adds r3, r0, #0
	ldrb r4, [r3, #0xe]
	cmp r4, #0
	bne _0800E022
	ldr r0, [r3, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r0, r0, #1
	ldr r1, _0800E028 @ =0x02002144
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, _0800E02C @ =0x0000FFFC
	ands r1, r2
	movs r2, #2
	orrs r1, r2
	strh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r3, #0x44]
	str r4, [r3, #0x48]
	str r4, [r3, #0x4c]
	movs r0, #0xa0
	str r0, [r3, #0x50]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_0800E022:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800E028: .4byte 0x02002144
_0800E02C: .4byte 0x0000FFFC

	thumb_func_start FUN_0800e030
FUN_0800e030: @ 0x0800E030
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _0800E058
	ldr r0, [r3, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r0, r0, #1
	ldr r1, _0800E070 @ =0x02002144
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, _0800E074 @ =0x0000FFFC
	ands r1, r2
	movs r2, #2
	orrs r1, r2
	strh r1, [r0]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_0800E058:
	ldr r2, [r3, #0x34]
	ldr r0, _0800E078 @ =0x000003BF
	cmp r2, r0
	bgt _0800E07C
	movs r0, #0x40
	str r0, [r3, #0x44]
	adds r0, #0xc0
	str r0, [r3, #0x48]
	movs r0, #0xb4
	str r0, [r3, #0x4c]
	movs r0, #0
	b _0800E0C6
	.align 2, 0
_0800E070: .4byte 0x02002144
_0800E074: .4byte 0x0000FFFC
_0800E078: .4byte 0x000003BF
_0800E07C:
	ldr r1, [r3, #0x38]
	movs r0, #0xa0
	lsls r0, r0, #1
	cmp r1, r0
	ble _0800E09C
	movs r0, #0x40
	str r0, [r3, #0x44]
	str r0, [r3, #0x48]
	ldr r0, _0800E098 @ =0x000004EC
	str r0, [r3, #0x4c]
	movs r0, #0xb4
	lsls r0, r0, #1
	b _0800E0C6
	.align 2, 0
_0800E098: .4byte 0x000004EC
_0800E09C:
	ldr r0, _0800E0B0 @ =0x0000077F
	cmp r2, r0
	bgt _0800E0B8
	movs r0, #0x40
	str r0, [r3, #0x44]
	str r0, [r3, #0x48]
	ldr r0, _0800E0B4 @ =0x000004EC
	str r0, [r3, #0x4c]
	movs r0, #0x78
	b _0800E0C6
	.align 2, 0
_0800E0B0: .4byte 0x0000077F
_0800E0B4: .4byte 0x000004EC
_0800E0B8:
	movs r0, #0xc0
	str r0, [r3, #0x44]
	str r0, [r3, #0x48]
	movs r0, #0x87
	lsls r0, r0, #2
	str r0, [r3, #0x4c]
	movs r0, #0x28
_0800E0C6:
	str r0, [r3, #0x50]
	pop {r0}
	bx r0

	thumb_func_start FUN_0800e0cc
FUN_0800e0cc: @ 0x0800E0CC
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _0800E102
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x14
	lsls r3, r3, #1
	ldr r1, _0800E10C @ =0x02002144
	adds r3, r3, r1
	ldr r1, [r4, #0x64]
	movs r2, #0x47
	orrs r1, r2
	strh r1, [r3]
	lsls r0, r0, #8
	lsrs r0, r0, #0x18
	ldr r1, _0800E110 @ =0x085222A0
	str r5, [sp]
	movs r2, #0x37
	movs r3, #0
	bl loadBGMapIntoVram
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0800E102:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800E10C: .4byte 0x02002144
_0800E110: .4byte 0x085222A0

	thumb_func_start oldLifeSpace_0800e114
oldLifeSpace_0800e114: @ 0x0800E114
	push {r4, r5, r6, r7, lr}
	ldr r2, [r0, #0x5c]
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	ldr r1, [r0, #0x38]
	ldr r3, _0800E188 @ =0xFFFFFC40
	adds r1, r1, r3
	asrs r5, r1, #2
	lsrs r2, r2, #0x14
	lsls r2, r2, #2
	ldr r1, _0800E18C @ =0x0200214C
	adds r3, r2, r1
	ldr r0, [r0, #0x34]
	asrs r0, r0, #2
	strh r0, [r3]
	adds r1, #2
	adds r2, r2, r1
	strh r5, [r2]
	cmp r5, #0x57
	bgt _0800E1E8
	movs r0, #0xa0
	lsls r0, r0, #2
	bl malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _0800E1E8
	ldr r2, _0800E190 @ =0x03001590
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r2, r1
	str r4, [r0]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r2, r3
	ldr r0, _0800E194 @ =0x0400001C
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _0800E198 @ =0xA6600001
	str r0, [r1]
	cmp r5, #0
	ble _0800E19C
	movs r3, #0
	movs r0, #0x58
	subs r0, r0, r5
	cmp r3, r0
	bge _0800E1AE
	lsls r2, r5, #0x10
	adds r1, r4, #0
	adds r3, r0, #0
_0800E17C:
	stm r1!, {r2}
	subs r3, #1
	cmp r3, #0
	bne _0800E17C
	adds r3, r0, #0
	b _0800E1AE
	.align 2, 0
_0800E188: .4byte 0xFFFFFC40
_0800E18C: .4byte 0x0200214C
_0800E190: .4byte 0x03001590
_0800E194: .4byte 0x0400001C
_0800E198: .4byte 0xA6600001
_0800E19C:
	movs r1, #0
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r4, r2
_0800E1A4:
	str r1, [r0]
	subs r0, #4
	cmp r0, r4
	bge _0800E1A4
	movs r3, #0x58
_0800E1AE:
	adds r0, r5, r3
	cmp r0, #0x57
	bgt _0800E1CE
	lsls r0, r3, #0x10
	movs r1, #0xb0
	lsls r1, r1, #0xf
	subs r1, r1, r0
	lsls r0, r3, #2
	adds r2, r0, r4
	ldr r6, _0800E1F0 @ =0xFFFF0000
_0800E1C2:
	stm r2!, {r1}
	adds r1, r1, r6
	adds r3, #1
	adds r0, r5, r3
	cmp r0, #0x57
	ble _0800E1C2
_0800E1CE:
	cmp r3, #0x9f
	bgt _0800E1E8
	lsrs r0, r7, #4
	lsls r0, r0, #2
	ldr r1, _0800E1F4 @ =0x0200214C
	adds r2, r0, r1
	lsls r0, r3, #2
	adds r1, r0, r4
_0800E1DE:
	ldr r0, [r2]
	stm r1!, {r0}
	adds r3, #1
	cmp r3, #0x9f
	ble _0800E1DE
_0800E1E8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800E1F0: .4byte 0xFFFF0000
_0800E1F4: .4byte 0x0200214C

	thumb_func_start FUN_0800e1f8
FUN_0800e1f8: @ 0x0800E1F8
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _0800E220
	ldr r0, [r3, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r0, r0, #1
	ldr r1, _0800E224 @ =0x02002144
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, _0800E228 @ =0x0000FFFC
	ands r1, r2
	movs r2, #1
	orrs r1, r2
	strh r1, [r0]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_0800E220:
	pop {r0}
	bx r0
	.align 2, 0
_0800E224: .4byte 0x02002144
_0800E228: .4byte 0x0000FFFC

	thumb_func_start FUN_0800e22c
FUN_0800e22c: @ 0x0800E22C
	push {lr}
	adds r1, r0, #0
	ldrb r2, [r1, #0xe]
	adds r0, r2, #0
	cmp r0, #0
	bne _0800E24A
	str r0, [r1, #0x44]
	str r0, [r1, #0x48]
	movs r0, #0xc3
	lsls r0, r0, #4
	str r0, [r1, #0x4c]
	movs r0, #0xa0
	str r0, [r1, #0x50]
	adds r0, r2, #1
	strb r0, [r1, #0xe]
_0800E24A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800e250
FUN_0800e250: @ 0x0800E250
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _0800E278
	ldr r0, [r3, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r0, r0, #1
	ldr r1, _0800E27C @ =0x02002144
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, _0800E280 @ =0x0000FFFC
	ands r1, r2
	movs r2, #2
	orrs r1, r2
	strh r1, [r0]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_0800E278:
	pop {r0}
	bx r0
	.align 2, 0
_0800E27C: .4byte 0x02002144
_0800E280: .4byte 0x0000FFFC

	thumb_func_start FUN_0800e284
FUN_0800e284: @ 0x0800E284
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldr r0, _0800E294 @ =0x0004FFFF
	cmp r3, r0
	ble _0800E298
	movs r0, #0
	b _0800E2B8
	.align 2, 0
_0800E294: .4byte 0x0004FFFF
_0800E298:
	ldr r2, _0800E2C0 @ =0x02002200
	movs r0, #0xfc
	lsls r0, r0, #3
	adds r2, r2, r0
	ldrh r1, [r2]
	movs r5, #0xc8
	lsls r5, r5, #0xb
	adds r0, r3, r5
	asrs r0, r0, #0xc
	muls r0, r1, r0
	asrs r1, r4, #0xc
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
_0800E2B8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800E2C0: .4byte 0x02002200

	thumb_func_start FUN_0800e2c4
FUN_0800e2c4: @ 0x0800E2C4
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	ldr r0, _0800E2F8 @ =0x0004FFFF
	cmp r1, r0
	bgt _0800E2F2
	ldr r4, _0800E2FC @ =0x02002200
	movs r0, #0xb0
	lsls r0, r0, #0xa
	adds r5, r4, r0
	ldrh r6, [r5]
	asrs r0, r2, #0xc
	movs r2, #0xc8
	lsls r2, r2, #0xb
	adds r1, r1, r2
	asrs r1, r1, #0xc
	ldr r2, _0800E300 @ =0x0833DFDA
	bl patchBlockMap
	strh r6, [r5]
	ldr r0, _0800E304 @ =0x0002D02C
	adds r4, r4, r0
	movs r0, #1
	strb r0, [r4]
_0800E2F2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800E2F8: .4byte 0x0004FFFF
_0800E2FC: .4byte 0x02002200
_0800E300: .4byte 0x0833DFDA
_0800E304: .4byte 0x0002D02C

	thumb_func_start FUN_0800e308
FUN_0800e308: @ 0x0800E308
	push {lr}
	ldr r1, [r0]
	ldr r2, _0800E32C @ =0xFFFFF000
	adds r1, r1, r2
	asrs r1, r1, #0xc
	ldr r0, [r0, #4]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r0, r2
	asrs r3, r0, #0xc
	cmp r3, #0x13
	bgt _0800E334
	adds r2, r1, #0
	subs r2, #0xf8
	asrs r2, r2, #1
	lsls r2, r2, #3
	ldr r0, _0800E330 @ =0x0833DFE2
	b _0800E342
	.align 2, 0
_0800E32C: .4byte 0xFFFFF000
_0800E330: .4byte 0x0833DFE2
_0800E334:
	cmp r3, #0x38
	ble _0800E354
	adds r2, r1, #0
	subs r2, #0xf6
	asrs r2, r2, #1
	lsls r2, r2, #3
	ldr r0, _0800E350 @ =0x0833E032
_0800E342:
	adds r2, r2, r0
	adds r0, r1, #0
	adds r1, r3, #0
	bl patchBlockMap
	b _0800E368
	.align 2, 0
_0800E350: .4byte 0x0833E032
_0800E354:
	adds r2, r1, #0
	subs r2, #0xf2
	asrs r2, r2, #1
	lsls r2, r2, #3
	ldr r0, _0800E36C @ =0x0833DFFA
	adds r2, r2, r0
	adds r0, r1, #0
	adds r1, r3, #0
	bl patchBlockMap
_0800E368:
	pop {r0}
	bx r0
	.align 2, 0
_0800E36C: .4byte 0x0833DFFA

	thumb_func_start FUN_0800e370
FUN_0800e370: @ 0x0800E370
	push {r4, r5, r6, r7, lr}
	ldr r1, [r0]
	ldr r2, _0800E3B0 @ =0xFFFFF000
	adds r1, r1, r2
	asrs r5, r1, #0xc
	ldr r0, [r0, #4]
	asrs r6, r0, #0xc
	movs r1, #0
	ldr r7, _0800E3B4 @ =0x0833E048
_0800E382:
	lsls r0, r1, #0x10
	asrs r3, r0, #0x10
	lsls r2, r3, #3
	adds r1, r2, r7
	ldr r1, [r1]
	adds r4, r0, #0
	cmp r5, r1
	bne _0800E3BC
	adds r0, r7, #4
	adds r0, r2, r0
	ldr r0, [r0]
	cmp r6, r0
	bne _0800E3BC
	lsls r2, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #2
	ldr r0, _0800E3B8 @ =0x0833E0A8
	adds r2, r2, r0
	adds r0, r5, #0
	adds r1, r6, #0
	bl patchBlockMap
	b _0800E3D4
	.align 2, 0
_0800E3B0: .4byte 0xFFFFF000
_0800E3B4: .4byte 0x0833E048
_0800E3B8: .4byte 0x0833E0A8
_0800E3BC:
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r4, r1
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb
	ble _0800E382
	ldr r2, _0800E3DC @ =0x0833E03A
	adds r0, r5, #0
	adds r1, r6, #0
	bl patchBlockMap
_0800E3D4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800E3DC: .4byte 0x0833E03A
