	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0804ff5c
FUN_0804ff5c: @ 0x0804FF5C
	push {r4, lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x1e]
	lsls r1, r0, #8
	adds r0, r2, #0
	adds r0, #0x70
	ldrb r0, [r0]
	orrs r1, r0
	ldr r4, _0804FFA0 @ =0x0000AB0B
	cmp r1, r4
	bne _0804FFAC
	ldr r0, [r2, #0x70]
	ldr r1, _0804FFA4 @ =0x00FFFF00
	ands r0, r1
	ldr r1, _0804FFA8 @ =0x00010300
	cmp r0, r1
	bne _08050008
	ldrb r1, [r2, #0xa]
	movs r3, #0x10
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804FFEC
	adds r1, r2, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	subs r1, #2
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	ldrb r0, [r2, #0xa]
	orrs r0, r3
	b _08050006
	.align 2, 0
_0804FFA0: .4byte 0x0000AB0B
_0804FFA4: .4byte 0x00FFFF00
_0804FFA8: .4byte 0x00010300
_0804FFAC:
	ldr r3, _0804FFE4 @ =0x0000AB05
	cmp r1, r3
	bne _08050034
	ldr r0, [r2, #0x70]
	ldr r1, _0804FFE8 @ =0x00FFFF00
	ands r0, r1
	movs r1, #0x81
	lsls r1, r1, #9
	cmp r0, r1
	bne _08050008
	ldrb r1, [r2, #0xa]
	movs r3, #0x10
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804FFEC
	adds r1, r2, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	subs r1, #2
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	ldrb r0, [r2, #0xa]
	orrs r0, r3
	b _08050006
	.align 2, 0
_0804FFE4: .4byte 0x0000AB05
_0804FFE8: .4byte 0x00FFFF00
_0804FFEC:
	adds r1, r2, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r3, r2, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r2, #0xa]
	movs r0, #0xef
	ands r0, r1
_08050006:
	strb r0, [r2, #0xa]
_08050008:
	adds r0, r2, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805008A
	adds r0, r2, #0
	adds r0, #0xd8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08050024
	ldr r1, _08050020 @ =0x0000AB09
	b _08050026
	.align 2, 0
_08050020: .4byte 0x0000AB09
_08050024:
	ldr r1, _08050030 @ =0x0000AB03
_08050026:
	adds r0, r2, #0
	bl SetMotion
	b _0805008A
	.align 2, 0
_08050030: .4byte 0x0000AB03
_08050034:
	ldr r0, _08050060 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	ble _08050064
	ldrb r1, [r2, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0805008A
	adds r0, r2, #0
	adds r0, #0xd8
	ldrb r0, [r0]
	cmp r0, #0
	bne _08050078
	adds r0, r2, #0
	adds r1, r3, #0
	bl SetMotion
	b _0805008A
	.align 2, 0
_08050060: .4byte pZero2
_08050064:
	ldrb r1, [r2, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805008A
	adds r0, r2, #0
	adds r0, #0xd8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08050082
_08050078:
	adds r0, r2, #0
	adds r1, r4, #0
	bl SetMotion
	b _0805008A
_08050082:
	adds r0, r2, #0
	adds r1, r3, #0
	bl SetMotion
_0805008A:
	pop {r4}
	pop {r0}
	bx r0
