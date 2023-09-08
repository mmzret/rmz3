	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080128bc
FUN_080128bc: @ 0x080128BC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	bne _080128EA
	movs r2, #0
	movs r3, #0
_080128CC:
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #2
	adds r0, r0, r6
	str r3, [r0, #0x68]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #5
	ble _080128CC
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _0801291C
_080128EA:
	movs r2, #0
_080128EC:
	lsls r0, r2, #0x10
	asrs r5, r0, #0x10
	lsls r0, r5, #2
	adds r4, r0, r6
	ldr r0, [r4, #0x68]
	cmp r0, #0
	bne _08012910
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r0, [sp]
	movs r0, #0xc5
	lsls r0, r0, #0xd
	movs r1, #0xbc
	lsls r1, r1, #9
	movs r3, #0
	bl CreateStructuralSteel
	str r0, [r4, #0x68]
_08012910:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _080128EC
_0801291C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08012924
FUN_08012924: @ 0x08012924
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0
	movs r5, #0
	ldr r7, _08012984 @ =gSolidFnTable
_0801292E:
	lsls r0, r1, #0x10
	asrs r4, r0, #0x10
	lsls r0, r4, #2
	adds r3, r0, r6
	ldr r2, [r3, #0x68]
	cmp r2, #0
	beq _08012970
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldrb r1, [r2, #9]
	lsls r1, r1, #2
	adds r1, r1, r7
	movs r0, #3
	str r0, [r2, #0xc]
	ldr r0, [r1]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
	str r5, [r3, #0x68]
_08012970:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _0801292E
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08012984: .4byte gSolidFnTable

	thumb_func_start FUN_08012988
FUN_08012988: @ 0x08012988
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	bne _080129B6
	movs r3, #0
	movs r2, #0
_08012998:
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #2
	adds r0, r0, r6
	str r2, [r0, #0x68]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #3
	ble _08012998
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _080129F2
_080129B6:
	movs r3, #0
	movs r7, #1
_080129BA:
	lsls r2, r3, #0x10
	asrs r4, r2, #0x10
	lsls r0, r4, #2
	adds r5, r0, r6
	ldr r0, [r5, #0x68]
	cmp r0, #0
	bne _080129E6
	lsls r1, r4, #1
	adds r1, r1, r4
	adds r1, #0x13
	lsls r1, r1, #4
	adds r1, #8
	lsls r1, r1, #8
	asrs r2, r2, #0x11
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ands r3, r7
	str r7, [sp]
	ldr r0, _080129FC @ =0x00272000
	bl CreateStructuralSteel
	str r0, [r5, #0x68]
_080129E6:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _080129BA
_080129F2:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080129FC: .4byte 0x00272000

	thumb_func_start FUN_08012a00
FUN_08012a00: @ 0x08012A00
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0
	movs r5, #0
	ldr r7, _08012A60 @ =gSolidFnTable
_08012A0A:
	lsls r0, r1, #0x10
	asrs r4, r0, #0x10
	lsls r0, r4, #2
	adds r3, r0, r6
	ldr r2, [r3, #0x68]
	cmp r2, #0
	beq _08012A4C
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldrb r1, [r2, #9]
	lsls r1, r1, #2
	adds r1, r1, r7
	movs r0, #3
	str r0, [r2, #0xc]
	ldr r0, [r1]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
	str r5, [r3, #0x68]
_08012A4C:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08012A0A
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08012A60: .4byte gSolidFnTable

	thumb_func_start FUN_08012a64
FUN_08012a64: @ 0x08012A64
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4]
	asrs r0, r0, #8
	str r0, [sp]
	ldr r0, [r4, #4]
	asrs r0, r0, #8
	str r0, [sp, #4]
	ldr r0, _08012AB8 @ =gOverworld
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0xb
	bne _08012AD0
	mov r0, sp
	bl FUN_08012518
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #6
	beq _08012AD0
	ldr r0, _08012ABC @ =gCurStory
	adds r0, #0x54
	ldrb r0, [r0]
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08012AD0
	cmp r2, #2
	bne _08012AC4
	ldr r1, [r4]
	movs r0, #0x87
	lsls r0, r0, #0xc
	cmp r1, r0
	ble _08012AC4
	ldr r0, _08012AC0 @ =0x083427B4
	b _08012AD2
	.align 2, 0
_08012AB8: .4byte gOverworld
_08012ABC: .4byte gCurStory
_08012AC0: .4byte 0x083427B4
_08012AC4:
	lsls r0, r2, #3
	ldr r1, _08012ACC @ =0x08342784
	adds r0, r0, r1
	b _08012AD2
	.align 2, 0
_08012ACC: .4byte 0x08342784
_08012AD0:
	movs r0, #0
_08012AD2:
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
