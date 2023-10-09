	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreatePantheonAqua
CreatePantheonAqua: @ 0x08071C88
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _08071CDC @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08071CD4
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _08071CE0 @ =gEnemyFnTable
	movs r0, #0x12
	strb r0, [r3, #9]
	ldr r0, [r1, #0x48]
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
_08071CD4:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08071CDC: .4byte gZakoHeaderPtr
_08071CE0: .4byte gEnemyFnTable

	thumb_func_start PantheonAqua_Init
PantheonAqua_Init: @ 0x08071CE4
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
	ldr r0, _08071D30 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x11]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08071D3C
	ldr r0, _08071D34 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08071D3C
	movs r0, #4
	orrs r2, r0
	strb r2, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08071D38 @ =0x08366C10
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x10
	b _08071D54
	.align 2, 0
_08071D30: .4byte gSystemSavedataManager
_08071D34: .4byte gCurStory
_08071D38: .4byte 0x08366C10
_08071D3C:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08071DA4 @ =0x08366C10
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xc
_08071D54:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _08071DA8 @ =gOverworld
	ldr r1, _08071DAC @ =0x0002C00C
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, [r6, #0x58]
	cmp r1, r0
	ble _08071DB4
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
	ldr r1, _08071DB0 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
	b _08071E68
	.align 2, 0
_08071DA4: .4byte 0x08366C10
_08071DA8: .4byte gOverworld
_08071DAC: .4byte 0x0002C00C
_08071DB0: .4byte gEnemyFnTable
_08071DB4:
	ldrb r2, [r6, #0x10]
	cmp r2, #0
	bne _08071DD8
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
	b _08071DFA
_08071DD8:
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
_08071DFA:
	ldr r0, _08071E70 @ =FUN_0807336c
	str r0, [r4, #0x24]
	movs r4, #0
	str r4, [r6, #0x60]
	str r4, [r6, #0x5c]
	adds r0, r6, #0
	adds r0, #0x64
	str r4, [r0, #4]
	str r4, [r6, #0x64]
	adds r0, #0x58
	str r4, [r0]
	subs r0, #3
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	subs r0, #2
	strb r4, [r0]
	ldr r1, _08071E74 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r4, [r6, #0xd]
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xf]
	adds r1, r6, #0
	adds r1, #0xb4
	ldr r0, [r6, #0x54]
	str r0, [r1]
	adds r1, #0xc
	ldr r0, [r6, #0x58]
	str r0, [r1]
	adds r0, r6, #0
	bl isFrozen
	cmp r0, #0
	beq _08071E5C
	movs r1, #0x9c
	lsls r1, r1, #6
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
_08071E5C:
	adds r0, r6, #0
	adds r0, #0xbb
	strb r4, [r0]
	adds r0, r6, #0
	bl PantheonAqua_Update
_08071E68:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08071E70: .4byte FUN_0807336c
_08071E74: .4byte gEnemyFnTable

	thumb_func_start PantheonAqua_Update
PantheonAqua_Update: @ 0x08071E78
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08071E94
	adds r0, r4, #0
	bl FUN_08073368
	cmp r0, #0
	bne _08071EB4
_08071E94:
	ldr r1, _08071EB0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl PantheonAqua_Die
	b _08071F90
	.align 2, 0
_08071EB0: .4byte gEnemyFnTable
_08071EB4:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r1, [r4, #0x54]
	ldr r0, [r0]
	subs r2, r1, r0
	cmp r2, #0
	ble _08071ECC
	movs r0, #0x94
	lsls r0, r0, #8
	cmp r2, r0
	bgt _08071ED6
	b _08071EE4
_08071ECC:
	subs r1, r0, r1
	movs r0, #0x94
	lsls r0, r0, #8
	cmp r1, r0
	ble _08071EE4
_08071ED6:
	ldrb r0, [r4, #0xd]
	cmp r0, #3
	beq _08071EE4
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08071EE4:
	ldr r0, _08071F5C @ =0x08366BD0
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080731c4
	ldrb r0, [r4, #0xd]
	cmp r0, #4
	beq _08071F0E
	cmp r0, #6
	beq _08071F0E
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	bne _08071F90
_08071F0E:
	ldr r0, _08071F60 @ =gOverworld
	ldr r1, _08071F64 @ =0x0002C00C
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, [r4, #0x58]
	ldr r2, _08071F68 @ =0xFFFFE200
	adds r0, r0, r2
	cmp r1, r0
	ble _08071F6C
	adds r6, r4, #0
	adds r6, #0xb8
	ldrb r5, [r6]
	cmp r5, #0
	bne _08071F3C
	movs r1, #0x9c
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	str r5, [r4, #0x60]
_08071F3C:
	movs r0, #1
	strb r0, [r6]
	ldr r0, [r4, #0x60]
	adds r0, #0x20
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08071F50
	str r1, [r4, #0x60]
_08071F50:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	b _08071F90
	.align 2, 0
_08071F5C: .4byte 0x08366BD0
_08071F60: .4byte gOverworld
_08071F64: .4byte 0x0002C00C
_08071F68: .4byte 0xFFFFE200
_08071F6C:
	adds r1, r4, #0
	adds r1, #0xb8
	ldrb r0, [r1]
	cmp r0, #1
	bne _08071F7C
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_08071F7C:
	movs r0, #0
	strb r0, [r1]
	ldr r1, _08071F98 @ =0x08366BF0
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_08071F90:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08071F98: .4byte 0x08366BF0

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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	ldr r2, _080723B8 @ =gMission
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
_080723B8: .4byte gMission
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
	ldr r2, _080724AC @ =gMission
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
_080724AC: .4byte gMission
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
	bl UpdateMotionGraphic
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
	ldr r2, _0807269C @ =gMission
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
_0807269C: .4byte gMission
_080726A0: .4byte 0x0000270E
_080726A4: .4byte gEnemyFnTable

	thumb_func_start nop_080726a8
nop_080726a8: @ 0x080726A8
	movs r0, #1
	bx lr

	thumb_func_start FUN_080726ac
FUN_080726ac: @ 0x080726AC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080726D0
	cmp r0, #1
	bgt _080726C0
	cmp r0, #0
	beq _080726C6
	b _080727F8
_080726C0:
	cmp r0, #2
	beq _080726EE
	b _080727F8
_080726C6:
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080726D0:
	movs r1, #0x9c
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08072748 @ =0x08366C10
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080726EE:
	ldr r2, [r4, #0x5c]
	rsbs r0, r2, #0
	movs r3, #0xb
	muls r0, r3, r0
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r1, [r4, #0x60]
	rsbs r0, r1, #0
	muls r0, r3, r0
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl FUN_08073610
	ldr r0, _0807274C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	ble _08072750
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _08072772
	.align 2, 0
_08072748: .4byte 0x08366C10
_0807274C: .4byte pZero2
_08072750:
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_08072772:
	ldrb r0, [r4, #0x13]
	adds r1, r0, #1
	strb r1, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x1c
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08072790
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080733b4
_08072790:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r1, r4, #0
	adds r1, #0xba
	ldrb r0, [r1]
	cmp r0, #0
	bne _080727AA
	adds r0, r4, #0
	bl FUN_080735ac
	adds r5, r0, #0
	b _080727B0
_080727AA:
	subs r0, #1
	strb r0, [r1]
	movs r5, #0
_080727B0:
	cmp r5, #2
	bne _080727BC
	movs r0, #0
	strb r5, [r4, #0xd]
	strb r0, [r4, #0xe]
	b _080727DE
_080727BC:
	cmp r5, #1
	bne _080727D4
	adds r0, r4, #0
	bl FUN_08073500
	adds r2, r4, #0
	adds r2, #0xb9
	movs r1, #0
	strb r0, [r2]
	strb r5, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _080727DE
_080727D4:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080727E4
	subs r0, #1
	strb r0, [r4, #0x12]
_080727DE:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _080727F8
_080727E4:
	adds r0, r4, #0
	bl FUN_08073500
	adds r2, r4, #0
	adds r2, #0xb9
	movs r1, #0
	strb r0, [r2]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080727F8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08072800
FUN_08072800: @ 0x08072800
	movs r0, #1
	bx lr

	thumb_func_start FUN_08072804
FUN_08072804: @ 0x08072804
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r4, [r7, #0xe]
	cmp r4, #0
	beq _08072814
	cmp r4, #1
	beq _08072900
	b _080729E2
_08072814:
	ldr r1, _08072880 @ =0x00002701
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x40
	strb r0, [r7, #0x12]
	strb r4, [r7, #0x13]
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _08072884 @ =0x08366C10
	bl SetDDP
	ldr r0, _08072888 @ =pZero2
	ldr r1, [r0]
	ldr r2, [r1, #0x54]
	ldr r0, [r7, #0x54]
	subs r2, r2, r0
	adds r5, r2, #0
	ldr r0, [r7, #0x58]
	ldr r3, _0807288C @ =0xFFFFFA00
	adds r0, r0, r3
	ldr r1, [r1, #0x58]
	subs r1, r1, r0
	adds r6, r1, #0
	cmp r2, #0
	bne _0807284C
	cmp r1, #0
	beq _08072890
_0807284C:
	asrs r0, r5, #2
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	asrs r1, r6, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0xe
	lsls r0, r5, #8
	adds r1, r4, #0
	bl __divsi3
	adds r5, r0, #0
	lsls r0, r6, #8
	adds r1, r4, #0
	bl __divsi3
	adds r6, r0, #0
	b _08072894
	.align 2, 0
_08072880: .4byte 0x00002701
_08072884: .4byte 0x08366C10
_08072888: .4byte pZero2
_0807288C: .4byte 0xFFFFFA00
_08072890:
	movs r5, #0x80
	lsls r5, r5, #1
_08072894:
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #6
	asrs r0, r0, #8
	str r0, [r7, #0x64]
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #6
	asrs r0, r0, #8
	str r0, [r7, #0x68]
	ldr r0, _080728D4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r7, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	ble _080728D8
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
	b _080728FA
	.align 2, 0
_080728D4: .4byte pZero2
_080728D8:
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
_080728FA:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08072900:
	ldr r0, [r7, #0x64]
	ldr r2, [r7, #0x5c]
	subs r0, r0, r2
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r7, #0x5c]
	ldr r0, [r7, #0x68]
	ldr r1, [r7, #0x60]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x60]
	ldr r0, [r7, #0x54]
	adds r0, r0, r2
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl FUN_08073610
	ldrb r0, [r7, #0x13]
	adds r1, r0, #1
	strb r1, [r7, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0xc
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807294C
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080733b4
_0807294C:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r1, r7, #0
	adds r1, #0xba
	ldrb r0, [r1]
	cmp r0, #0
	beq _08072966
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080729CC
_08072966:
	adds r0, r7, #0
	bl FUN_080735ac
	cmp r0, #2
	bne _080729CC
	ldr r0, _0807299C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r7, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	ble _080729A0
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
	b _080729C2
	.align 2, 0
_0807299C: .4byte pZero2
_080729A0:
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
_080729C2:
	movs r1, #0
	movs r0, #2
	strb r0, [r7, #0xd]
	strb r1, [r7, #0xe]
	b _080729D6
_080729CC:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080729DC
	subs r0, #1
	strb r0, [r7, #0x12]
_080729D6:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _080729E2
_080729DC:
	movs r0, #0
	strb r0, [r7, #0xd]
	strb r0, [r7, #0xe]
_080729E2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080729e8
FUN_080729e8: @ 0x080729E8
	movs r0, #1
	bx lr

	thumb_func_start FUN_080729ec
FUN_080729ec: @ 0x080729EC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #0xb
	bls _08072A02
	b _08072E30
_08072A02:
	lsls r0, r0, #2
	ldr r1, _08072A0C @ =_08072A10
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08072A0C: .4byte _08072A10
_08072A10: @ jump table
	.4byte _08072A40 @ case 0
	.4byte _08072A5C @ case 1
	.4byte _08072B00 @ case 2
	.4byte _08072B12 @ case 3
	.4byte _08072B60 @ case 4
	.4byte _08072D06 @ case 5
	.4byte _08072B70 @ case 6
	.4byte _08072B8C @ case 7
	.4byte _08072BDC @ case 8
	.4byte _08072D06 @ case 9
	.4byte _08072D54 @ case 10
	.4byte _08072D70 @ case 11
_08072A40:
	ldr r1, _08072A80 @ =0x00002702
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _08072A84 @ =0x08366C10
	bl SetDDP
	movs r0, #0
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08072A5C:
	ldrb r1, [r7, #0x12]
	adds r1, #1
	strb r1, [r7, #0x12]
	lsls r1, r1, #0x18
	movs r0, #0xc0
	lsls r0, r0, #0x12
	ands r0, r1
	cmp r0, #0
	beq _08072A70
	b _08072D06
_08072A70:
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08072A8C
	ldr r0, _08072A88 @ =0xFFFFF000
	b _08072A90
	.align 2, 0
_08072A80: .4byte 0x00002702
_08072A84: .4byte 0x08366C10
_08072A88: .4byte 0xFFFFF000
_08072A8C:
	movs r0, #0x80
	lsls r0, r0, #5
_08072A90:
	str r0, [sp]
	ldr r1, [r7, #0x54]
	ldr r0, [sp]
	adds r1, r1, r0
	ldr r4, [r7, #0x58]
	ldr r0, _08072AF0 @ =0xFFFFF000
	adds r4, r4, r0
	ldr r2, _08072AF4 @ =RNG_0202f388
	mov r8, r2
	ldr r0, [r2]
	ldr r3, _08072AF8 @ =0x000343FD
	muls r0, r3, r0
	ldr r2, _08072AFC @ =0x00269EC3
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r6, r0, #1
	lsrs r0, r0, #0x11
	movs r5, #7
	ands r0, r5
	subs r0, #3
	lsls r0, r0, #8
	adds r0, r0, r1
	str r0, [sp]
	adds r0, r6, #0
	muls r0, r3, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	ands r0, r5
	subs r0, #3
	lsls r0, r0, #8
	adds r0, r0, r4
	str r0, [sp, #4]
	muls r1, r3, r1
	adds r1, r1, r2
	lsls r1, r1, #1
	lsrs r0, r1, #1
	mov r2, r8
	str r0, [r2]
	lsrs r1, r1, #0x11
	movs r0, #1
	ands r1, r0
	mov r0, sp
	bl FUN_080ba8e8
	b _08072D06
	.align 2, 0
_08072AF0: .4byte 0xFFFFF000
_08072AF4: .4byte RNG_0202f388
_08072AF8: .4byte 0x000343FD
_08072AFC: .4byte 0x00269EC3
_08072B00:
	ldr r1, _08072B5C @ =0x00002703
	adds r0, r7, #0
	bl SetMotion
	movs r0, #8
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08072B12:
	ldr r2, [r7, #0x5c]
	rsbs r0, r2, #0
	movs r3, #0xb
	muls r0, r3, r0
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r7, #0x5c]
	ldr r1, [r7, #0x60]
	rsbs r0, r1, #0
	muls r0, r3, r0
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x60]
	ldr r0, [r7, #0x54]
	adds r0, r0, r2
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl FUN_08073610
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _08072B4C
	b _08072D42
_08072B4C:
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08072B58
	b _08072E30
_08072B58:
	b _08072D42
	.align 2, 0
_08072B5C: .4byte 0x00002703
_08072B60:
	ldr r1, _08072B6C @ =0x00002704
	adds r0, r7, #0
	bl SetMotion
	b _08072D00
	.align 2, 0
_08072B6C: .4byte 0x00002704
_08072B70:
	ldr r1, _08072BD4 @ =0x00002705
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _08072BD8 @ =0x08366C40
	bl SetDDP
	movs r0, #0x10
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08072B8C:
	ldr r2, [r7, #0x5c]
	rsbs r0, r2, #0
	movs r3, #0xb
	muls r0, r3, r0
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r7, #0x5c]
	ldr r1, [r7, #0x60]
	rsbs r0, r1, #0
	muls r0, r3, r0
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x60]
	ldr r0, [r7, #0x54]
	adds r0, r0, r2
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl FUN_08073610
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _08072BC6
	b _08072D42
_08072BC6:
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08072BD2
	b _08072E30
_08072BD2:
	b _08072D42
	.align 2, 0
_08072BD4: .4byte 0x00002705
_08072BD8: .4byte 0x08366C40
_08072BDC:
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08072BF0
	ldr r0, _08072BEC @ =0xFFFFE200
	b _08072BF4
	.align 2, 0
_08072BEC: .4byte 0xFFFFE200
_08072BF0:
	movs r0, #0xf0
	lsls r0, r0, #5
_08072BF4:
	str r0, [sp, #8]
	ldr r0, _08072C78 @ =0xFFFFE300
	add r4, sp, #8
	str r0, [r4, #4]
	ldr r0, [r7, #0x54]
	ldr r1, [sp, #8]
	adds r0, r0, r1
	str r0, [sp, #8]
	ldr r0, [r7, #0x58]
	ldr r1, [r4, #4]
	adds r0, r0, r1
	str r0, [r4, #4]
	adds r0, r7, #0
	bl FUN_08073610
	ldr r1, _08072C7C @ =0x00002706
	adds r0, r7, #0
	bl SetMotion
	ldrb r2, [r7, #0xa]
	lsrs r2, r2, #4
	movs r0, #1
	ands r2, r0
	adds r0, r4, #0
	adds r1, r4, #0
	bl CreateProjectile2
	movs r0, #0x63
	bl PlaySound
	movs r5, #0
	ldr r6, _08072C80 @ =RNG_0202f388
	mov sl, r4
	ldr r0, _08072C84 @ =0x000343FD
	mov sb, r0
_08072C3A:
	movs r0, #3
	ands r0, r5
	cmp r0, #0
	bne _08072CFA
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	mov r8, r1
	cmp r0, #0
	bne _08072C90
	ldr r4, [r7, #0x54]
	ldr r1, _08072C88 @ =0xFFFFD000
	adds r4, r4, r1
	str r4, [sp, #8]
	ldr r0, [r6]
	mov r2, sb
	muls r2, r0, r2
	adds r0, r2, #0
	ldr r1, _08072C8C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	movs r1, #0xc
	bl __umodsi3
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r4, r4, r0
	b _08072CBA
	.align 2, 0
_08072C78: .4byte 0xFFFFE300
_08072C7C: .4byte 0x00002706
_08072C80: .4byte RNG_0202f388
_08072C84: .4byte 0x000343FD
_08072C88: .4byte 0xFFFFD000
_08072C8C: .4byte 0x00269EC3
_08072C90:
	ldr r4, [r7, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #6
	adds r4, r4, r2
	str r4, [sp, #8]
	ldr r0, [r6]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r2, _08072D4C @ =0x00269EC3
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	movs r1, #0xc
	bl __umodsi3
	adds r0, r0, r5
	lsls r0, r0, #8
	subs r4, r4, r0
_08072CBA:
	str r4, [sp, #8]
	ldr r2, [r7, #0x58]
	ldr r0, _08072D50 @ =0xFFFFE300
	adds r2, r2, r0
	ldr r0, [r6]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r1, _08072D4C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	movs r1, #3
	ands r0, r1
	subs r0, #1
	lsls r0, r0, #8
	adds r2, r2, r0
	mov r0, sl
	str r2, [r0, #4]
	movs r0, #1
	adds r1, r5, #0
	ands r1, r0
	mov r0, r8
	lsls r2, r0, #0x18
	lsrs r2, r2, #0x1c
	movs r0, #1
	ands r2, r0
	mov r0, sl
	bl FUN_080ba940
_08072CFA:
	adds r5, #1
	cmp r5, #7
	ble _08072C3A
_08072D00:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08072D06:
	ldr r2, [r7, #0x5c]
	rsbs r0, r2, #0
	movs r3, #0xb
	muls r0, r3, r0
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r7, #0x5c]
	ldr r1, [r7, #0x60]
	rsbs r0, r1, #0
	muls r0, r3, r0
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x60]
	ldr r0, [r7, #0x54]
	adds r0, r0, r2
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl FUN_08073610
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08072E30
_08072D42:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _08072E30
	.align 2, 0
_08072D4C: .4byte 0x00269EC3
_08072D50: .4byte 0xFFFFE300
_08072D54:
	ldr r1, _08072DE8 @ =0x00002707
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _08072DEC @ =0x08366C10
	bl SetDDP
	movs r0, #0x1e
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08072D70:
	ldr r2, [r7, #0x5c]
	rsbs r0, r2, #0
	movs r3, #0xb
	muls r0, r3, r0
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r7, #0x5c]
	ldr r1, [r7, #0x60]
	rsbs r0, r1, #0
	muls r0, r3, r0
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x60]
	ldr r0, [r7, #0x54]
	adds r0, r0, r2
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl FUN_08073610
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08072E30
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _08072DBC
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08072E30
_08072DBC:
	ldr r0, _08072DF0 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r7, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	ble _08072DF4
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
	b _08072E16
	.align 2, 0
_08072DE8: .4byte 0x00002707
_08072DEC: .4byte 0x08366C10
_08072DF0: .4byte pZero2
_08072DF4:
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
_08072E16:
	adds r0, r7, #0
	bl FUN_08073500
	adds r2, r7, #0
	adds r2, #0xb9
	movs r1, #0
	strb r0, [r2]
	adds r2, #1
	movs r0, #0x1e
	strb r0, [r2]
	movs r0, #1
	strb r0, [r7, #0xd]
	strb r1, [r7, #0xe]
_08072E30:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08072e40
FUN_08072e40: @ 0x08072E40
	movs r0, #1
	bx lr

	thumb_func_start FUN_08072e44
FUN_08072e44: @ 0x08072E44
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r6, [r4, #0xe]
	cmp r6, #0
	beq _08072E54
	cmp r6, #1
	beq _08072F1A
	b _08072FA0
_08072E54:
	adds r7, r4, #0
	adds r7, #0xb4
	ldr r0, [r7]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	str r0, [r4, #0x5c]
	adds r1, r4, #0
	adds r1, #0xc0
	ldr r1, [r1]
	ldr r2, [r4, #0x58]
	subs r1, r1, r2
	str r1, [r4, #0x60]
	asrs r0, r0, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r1, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0xe
	cmp r5, #0
	beq _08072EA2
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x60]
_08072EA2:
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #7
	asrs r0, r0, #8
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x60]
	lsls r0, r0, #7
	asrs r0, r0, #8
	str r0, [r4, #0x68]
	ldr r1, [r4, #0x54]
	ldr r0, [r7]
	cmp r1, r0
	ble _08072ED8
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _08072EFA
_08072ED8:
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_08072EFA:
	ldr r1, _08072F84 @ =0x00002701
	adds r0, r4, #0
	bl SetMotion
	movs r1, #0
	movs r0, #0xf0
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08072F88 @ =0x08366C10
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08072F1A:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl FUN_08073610
	ldrb r0, [r4, #0x13]
	adds r1, r0, #1
	strb r1, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0xc
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08072F4E
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080733b4
_08072F4E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08072F64
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08072F6C
_08072F64:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08072F6C:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r1, [r4, #0x54]
	ldr r0, [r0]
	subs r2, r1, r0
	cmp r2, #0
	ble _08072F90
	ldr r0, _08072F8C @ =0x00004FFF
	cmp r2, r0
	ble _08072F98
	b _08072FA0
	.align 2, 0
_08072F84: .4byte 0x00002701
_08072F88: .4byte 0x08366C10
_08072F8C: .4byte 0x00004FFF
_08072F90:
	subs r1, r0, r1
	ldr r0, _08072FA8 @ =0x00004FFF
	cmp r1, r0
	bgt _08072FA0
_08072F98:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08072FA0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08072FA8: .4byte 0x00004FFF

	thumb_func_start FUN_08072fac
FUN_08072fac: @ 0x08072FAC
	movs r0, #1
	bx lr

	thumb_func_start FUN_08072fb0
FUN_08072fb0: @ 0x08072FB0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _08072FCA
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08072FF0 @ =0x08366C28
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08072FCA:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08072FEA
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08072FF4 @ =0x08366C10
	bl SetDDP
	movs r0, #0
	str r0, [r5]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_08072FEA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08072FF0: .4byte 0x08366C28
_08072FF4: .4byte 0x08366C10

	thumb_func_start FUN_08072ff8
FUN_08072ff8: @ 0x08072FF8
	movs r0, #1
	bx lr

	thumb_func_start FUN_08072ffc
FUN_08072ffc: @ 0x08072FFC
	bx lr
	.align 2, 0

	thumb_func_start FUN_08073000
FUN_08073000: @ 0x08073000
	movs r0, #1
	bx lr

	thumb_func_start FUN_08073004
FUN_08073004: @ 0x08073004
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08073014
	cmp r5, #1
	beq _08073026
	b _080730A0
_08073014:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807306C @ =0x08366C28
	bl SetDDP
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08073026:
	ldr r0, [r4, #0x60]
	adds r0, #0x10
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #2
	cmp r0, r1
	ble _08073036
	str r1, [r4, #0x60]
_08073036:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08073098
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	ldr r1, [r4, #0x58]
	subs r0, r1, r0
	cmp r0, #0
	ble _08073074
	ldr r0, [r4, #0x54]
	bl FUN_08009f6c
	ldr r1, [r4, #0x58]
	subs r1, r1, r0
	ldr r0, _08073070 @ =0x000006FF
	cmp r1, r0
	ble _08073084
	b _080730A0
	.align 2, 0
_0807306C: .4byte 0x08366C28
_08073070: .4byte 0x000006FF
_08073074:
	ldr r0, [r4, #0x54]
	bl FUN_08009f6c
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	ldr r1, _08073094 @ =0x000006FF
	cmp r0, r1
	bgt _080730A0
_08073084:
	movs r0, #0
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	b _0807309E
	.align 2, 0
_08073094: .4byte 0x000006FF
_08073098:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
_0807309E:
	str r0, [r4, #0x58]
_080730A0:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _080730C0
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080730C8 @ =0x08366C10
	bl SetDDP
	movs r0, #0
	str r0, [r5]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_080730C0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080730C8: .4byte 0x08366C10

	thumb_func_start FUN_080730cc
FUN_080730cc: @ 0x080730CC
	movs r0, #1
	bx lr

	thumb_func_start FUN_080730d0
FUN_080730d0: @ 0x080730D0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080730E0
	cmp r0, #1
	beq _08073128
	b _080731BC
_080730E0:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08073108 @ =0x08366CA0
	bl SetDDP
	ldr r0, _0807310C @ =pZero2
	ldr r0, [r0]
	ldrb r0, [r0, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	strb r0, [r4, #0xf]
	cmp r0, #0
	bne _08073114
	ldr r0, _08073110 @ =0xFFFFFD80
	str r0, [r4, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #1
	b _0807311C
	.align 2, 0
_08073108: .4byte 0x08366CA0
_0807310C: .4byte pZero2
_08073110: .4byte 0xFFFFFD80
_08073114:
	movs r0, #0xa0
	lsls r0, r0, #2
	str r0, [r4, #0x5c]
	ldr r0, _0807315C @ =0xFFFFFF00
_0807311C:
	str r0, [r4, #0x64]
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08073128:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	movs r1, #0xf0
	lsls r1, r1, #0xc
	ands r1, r0
	lsrs r1, r1, #0x10
	cmp r1, #1
	bne _08073164
	ldr r1, _08073160 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080731BC
	.align 2, 0
_0807315C: .4byte 0xFFFFFF00
_08073160: .4byte gEnemyFnTable
_08073164:
	ldr r0, [r4, #0x54]
	ldr r3, [r4, #0x5c]
	adds r0, r0, r3
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	ldr r2, [r4, #0x64]
	subs r2, r2, r3
	lsls r2, r2, #3
	asrs r2, r2, #8
	adds r3, r3, r2
	str r3, [r4, #0x5c]
	ldr r2, _080731AC @ =0xFFFFE000
	adds r1, r1, r2
	bl FUN_08009f6c
	adds r1, r0, #0
	ldr r0, [r4, #0x58]
	subs r0, r1, r0
	cmp r0, #0x40
	bgt _08073194
	str r1, [r4, #0x58]
_08073194:
	adds r0, r4, #0
	bl FUN_08073610
	ldrb r1, [r4, #0xf]
	cmp r1, #0
	bne _080731B0
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	blt _080731BC
	strb r1, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _080731BC
	.align 2, 0
_080731AC: .4byte 0xFFFFE000
_080731B0:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bgt _080731BC
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_080731BC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080731c4
FUN_080731c4: @ 0x080731C4
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
	beq _080731DC
	b _08073356
_080731DC:
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080731EA
	b _08073356
_080731EA:
	movs r0, #0x97
	adds r0, r0, r4
	mov r8, r0
	ldrb r1, [r0]
	movs r7, #0xf0
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0x20
	beq _080731FE
	b _08073328
_080731FE:
	ldr r5, [r4, #0x58]
	ldr r4, [r4, #0x54]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	bl CreateBubble
	ldr r1, _0807331C @ =RNG_0202f388
	mov sl, r1
	ldr r0, [r1]
	ldr r2, _08073320 @ =0x000343FD
	mov sb, r2
	mov r3, sb
	muls r3, r0, r3
	adds r0, r3, #0
	ldr r6, _08073324 @ =0x00269EC3
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
	b _08073356
	.align 2, 0
_0807331C: .4byte RNG_0202f388
_08073320: .4byte 0x000343FD
_08073324: .4byte 0x00269EC3
_08073328:
	ldr r2, _08073348 @ =0x08366CE8
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r5]
	cmp r0, #0
	beq _08073356
	mov r3, r8
	ldrb r0, [r3]
	adds r2, r7, #0
	ands r2, r0
	cmp r2, #0x10
	bne _0807334C
	movs r0, #4
	b _08073352
	.align 2, 0
_08073348: .4byte 0x08366CE8
_0807334C:
	cmp r2, #0x30
	bne _08073356
	movs r0, #6
_08073352:
	strb r0, [r4, #0xd]
	strb r6, [r4, #0xe]
_08073356:
	movs r0, #1
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08073368
FUN_08073368: @ 0x08073368
	movs r0, #1
	bx lr

	thumb_func_start FUN_0807336c
FUN_0807336c: @ 0x0807336C
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, [r2, #0xc]
	ldr r0, [r0, #4]
	ldrb r0, [r0, #4]
	cmp r0, #3
	beq _08073384
	cmp r0, #0xe
	beq _08073384
	cmp r0, #0xf
	bne _080733AE
_08073384:
	ldr r2, [r2, #0x2c]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080733AE
	ldr r1, [r2, #0x54]
	ldr r0, [r3]
	cmp r1, r0
	bge _080733A6
	adds r1, r2, #0
	adds r1, #0xbb
	movs r0, #0xff
	b _080733AC
_080733A6:
	adds r1, r2, #0
	adds r1, #0xbb
	movs r0, #0xfe
_080733AC:
	strb r0, [r1]
_080733AE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080733b4
FUN_080733b4: @ 0x080733B4
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080733F8
	movs r0, #0x98
	lsls r0, r0, #5
	str r0, [sp]
	ldr r2, _080733EC @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080733F0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080733F4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x1f
	ands r0, r1
	movs r1, #0xb4
	lsls r1, r1, #1
	adds r0, r0, r1
	b _08073418
	.align 2, 0
_080733EC: .4byte RNG_0202f388
_080733F0: .4byte 0x000343FD
_080733F4: .4byte 0x00269EC3
_080733F8:
	ldr r0, _0807344C @ =0xFFFFED00
	str r0, [sp]
	ldr r2, _08073450 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08073454 @ =0x000343FD
	muls r1, r0, r1
	ldr r0, _08073458 @ =0x00269EC3
	adds r1, r1, r0
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r2]
	lsrs r1, r1, #0x11
	movs r0, #0x1f
	ands r1, r0
	ldr r0, _0807345C @ =0xFFFFFE98
	subs r0, r0, r1
_08073418:
	str r0, [sp, #8]
	ldr r0, [r5, #0x54]
	ldr r1, [sp]
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _08073460 @ =0xFFFFE800
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #0xb4
	lsls r0, r0, #1
	add r4, sp, #8
	str r0, [r4, #4]
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0
	bl FUN_080ba888
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08073468
	ldr r0, _08073464 @ =0xFFFFFC00
	b _0807346C
	.align 2, 0
_0807344C: .4byte 0xFFFFED00
_08073450: .4byte RNG_0202f388
_08073454: .4byte 0x000343FD
_08073458: .4byte 0x00269EC3
_0807345C: .4byte 0xFFFFFE98
_08073460: .4byte 0xFFFFE800
_08073464: .4byte 0xFFFFFC00
_08073468:
	movs r0, #0x80
	lsls r0, r0, #3
_0807346C:
	str r0, [sp]
	ldr r0, [sp]
	ldr r1, [r5, #0x54]
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _080734A8 @ =0xFFFFE800
	adds r0, r0, r1
	str r0, [sp, #4]
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080734B8
	ldr r2, _080734AC @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080734B0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080734B4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x1f
	ands r0, r1
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r0, r1
	b _080734D4
	.align 2, 0
_080734A8: .4byte 0xFFFFE800
_080734AC: .4byte RNG_0202f388
_080734B0: .4byte 0x000343FD
_080734B4: .4byte 0x00269EC3
_080734B8:
	ldr r2, _080734F0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080734F4 @ =0x000343FD
	muls r1, r0, r1
	ldr r0, _080734F8 @ =0x00269EC3
	adds r1, r1, r0
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r2]
	lsrs r1, r1, #0x11
	movs r0, #0x1f
	ands r1, r0
	ldr r0, _080734FC @ =0xFFFFFEB8
	subs r0, r0, r1
_080734D4:
	str r0, [sp, #8]
	movs r0, #0xc4
	lsls r0, r0, #1
	str r0, [r4, #4]
	mov r0, sp
	adds r1, r4, #0
	movs r2, #1
	bl FUN_080ba888
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080734F0: .4byte RNG_0202f388
_080734F4: .4byte 0x000343FD
_080734F8: .4byte 0x00269EC3
_080734FC: .4byte 0xFFFFFEB8

	thumb_func_start FUN_08073500
FUN_08073500: @ 0x08073500
	push {r4, r5, r6, lr}
	ldr r1, _08073574 @ =pZero2
	ldr r3, [r1]
	ldr r2, [r3, #0x54]
	ldr r1, [r0, #0x54]
	subs r4, r2, r1
	ldr r0, [r0, #0x58]
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r3, #0x58]
	subs r5, r1, r0
	asrs r0, r4, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r5, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #0xe
	cmp r6, #0
	beq _0807354A
	lsls r0, r4, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	lsls r0, r5, #8
	adds r1, r6, #0
	bl __divsi3
	adds r5, r0, #0
_0807354A:
	cmp r4, #0
	ble _08073578
	adds r0, r5, #0
	cmp r0, #0
	bge _08073556
	rsbs r0, r0, #0
_08073556:
	cmp r0, #0xec
	bgt _08073584
	adds r1, r5, #0
	cmp r1, #0
	bge _08073562
	rsbs r1, r1, #0
_08073562:
	movs r0, #2
	cmp r1, #0x60
	ble _080735A4
	movs r0, #1
	cmp r5, #0
	ble _080735A4
	movs r0, #3
	b _080735A4
	.align 2, 0
_08073574: .4byte pZero2
_08073578:
	adds r0, r5, #0
	cmp r0, #0
	bge _08073580
	rsbs r0, r0, #0
_08073580:
	cmp r0, #0xec
	ble _0807358E
_08073584:
	movs r0, #0
	cmp r5, #0
	ble _080735A4
	movs r0, #4
	b _080735A4
_0807358E:
	adds r1, r5, #0
	cmp r1, #0
	bge _08073596
	rsbs r1, r1, #0
_08073596:
	movs r0, #6
	cmp r1, #0x60
	ble _080735A4
	movs r0, #7
	cmp r5, #0
	ble _080735A4
	movs r0, #5
_080735A4:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080735ac
FUN_080735ac: @ 0x080735AC
	push {lr}
	ldr r1, _080735EC @ =pZero2
	ldr r1, [r1]
	ldr r2, [r0, #0x58]
	ldr r0, [r1, #0x58]
	subs r2, r2, r0
	cmp r2, #0
	bge _080735BE
	rsbs r2, r2, #0
_080735BE:
	ldr r0, _080735F0 @ =0x00001FFF
	cmp r2, r0
	bgt _08073608
	ldr r2, _080735F4 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080735F8 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080735FC @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xf
	ands r0, r1
	ldr r1, _08073600 @ =0x080FF00C
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _08073604
	movs r0, #2
	b _0807360A
	.align 2, 0
_080735EC: .4byte pZero2
_080735F0: .4byte 0x00001FFF
_080735F4: .4byte RNG_0202f388
_080735F8: .4byte 0x000343FD
_080735FC: .4byte 0x00269EC3
_08073600: .4byte 0x080FF00C
_08073604:
	movs r0, #1
	b _0807360A
_08073608:
	movs r0, #0
_0807360A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08073610
FUN_08073610: @ 0x08073610
	push {r4, lr}
	adds r3, r0, #0
	ldr r1, _0807363C @ =gOverworld
	ldr r2, _08073640 @ =0x0002C00C
	adds r1, r1, r2
	ldr r2, [r1]
	ldr r1, _08073644 @ =gStageRun+232
	ldr r1, [r1, #0x3c]
	ldr r4, _08073648 @ =0x00004FFF
	adds r1, r1, r4
	cmp r2, r1
	bge _08073650
	ldr r1, [r3, #0x58]
	ldr r4, _0807364C @ =0xFFFFDA00
	adds r1, r1, r4
	cmp r2, r1
	ble _0807365A
	movs r4, #0x98
	lsls r4, r4, #6
	adds r1, r2, r4
	b _08073658
	.align 2, 0
_0807363C: .4byte gOverworld
_08073640: .4byte 0x0002C00C
_08073644: .4byte gStageRun+232
_08073648: .4byte 0x00004FFF
_0807364C: .4byte 0xFFFFDA00
_08073650:
	ldr r1, [r3, #0x58]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
_08073658:
	str r1, [r3, #0x58]
_0807365A:
	pop {r4}
	pop {r1}
	bx r1
