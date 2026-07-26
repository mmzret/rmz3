	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08015c5c
FUN_08015c5c: @ 0x08015C5C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r0, [r6, #0x5c]
	lsls r4, r0, #0x10
	lsrs r7, r4, #0x10
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	beq _08015C86
	cmp r0, #1
	bgt _08015CD0
	cmp r0, #0
	bne _08015CD0
	ldr r0, _08015CD8 @ =gOverworld
	ldr r1, _08015CDC @ =0x0002D024
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08015CD0
	movs r0, #1
	strb r0, [r6, #0xe]
_08015C86:
	lsrs r4, r4, #0x14
	lsls r2, r4, #1
	ldr r3, _08015CE0 @ =gVideoRegBuffer+4
	adds r2, r2, r3
	ldr r1, [r6, #0x64]
	ldr r5, _08015CE4 @ =0x00004046
	adds r0, r5, #0
	orrs r1, r0
	strh r1, [r2]
	lsls r4, r4, #2
	adds r3, #8
	adds r4, r4, r3
	movs r5, #0
	str r5, [r4]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r1, r0
	lsls r1, r1, #3
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	str r5, [sp, #4]
	ldr r2, _08015CE8 @ =0x01000400
	add r0, sp, #4
	bl CpuFastSet
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08015CEC @ =gBgMapOffsets
	str r5, [sp]
	movs r2, #0x4b
	movs r3, #0
	bl LoadBgMap
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08015CD0:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08015CD8: .4byte gOverworld
_08015CDC: .4byte 0x0002D024
_08015CE0: .4byte gVideoRegBuffer+4
_08015CE4: .4byte 0x00004046
_08015CE8: .4byte 0x01000400
_08015CEC: .4byte gBgMapOffsets

	thumb_func_start FUN_08015cf0
FUN_08015cf0: @ 0x08015CF0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	lsls r6, r0, #0x10
	lsrs r0, r6, #0x10
	mov r8, r0
	ldr r7, _08015D18 @ =gOverworld
	ldr r2, _08015D1C @ =0x0002D024
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08015D20
	adds r0, r5, #0
	bl DrawGeneralStageLayer
	b _08015E24
	.align 2, 0
_08015D18: .4byte gOverworld
_08015D1C: .4byte 0x0002D024
_08015D20:
	ldr r3, _08015DF0 @ =0x0002C002
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _08015D60
	movs r4, #0
	lsrs r0, r6, #0x14
	lsls r0, r0, #1
	ldr r1, _08015DF4 @ =gVideoRegBuffer+4
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf8
	lsls r1, r1, #5
	ands r1, r0
	lsls r1, r1, #3
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	str r4, [sp, #4]
	ldr r2, _08015DF8 @ =0x01000400
	add r0, sp, #4
	bl CpuFastSet
	mov r1, r8
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08015DFC @ =gBgMapOffsets
	str r4, [sp]
	movs r2, #0x4b
	movs r3, #0
	bl LoadBgMap
_08015D60:
	adds r3, r7, #0
	ldr r2, _08015E00 @ =0x0002D040
	adds r0, r3, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _08015D82
	ldr r0, _08015E04 @ =0x0002D054
	adds r1, r3, r0
	adds r2, #8
	adds r0, r3, r2
	ldr r2, [r0]
	ldr r0, [r2]
	str r0, [r1]
	ldr r0, _08015E08 @ =0x0002D058
	adds r1, r3, r0
	ldr r0, [r2, #4]
	str r0, [r1]
_08015D82:
	lsrs r2, r6, #0x14
	lsls r2, r2, #2
	ldr r4, _08015E0C @ =gVideoRegBuffer+12
	adds r3, r2, r4
	ldr r1, [r5, #0x34]
	ldr r6, _08015E04 @ =0x0002D054
	adds r0, r7, r6
	ldr r0, [r0]
	asrs r0, r0, #8
	subs r1, r1, r0
	adds r1, #0xe0
	ldr r0, [r5, #0x2c]
	asrs r0, r0, #8
	adds r1, r1, r0
	strh r1, [r3]
	adds r0, r4, #2
	adds r2, r2, r0
	ldr r1, [r5, #0x38]
	ldr r3, _08015E08 @ =0x0002D058
	adds r0, r7, r3
	ldr r0, [r0]
	ldr r6, _08015E10 @ =0xFFFB0000
	adds r0, r0, r6
	asrs r0, r0, #8
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r0, r0, r3
	subs r1, r1, r0
	ldr r0, [r5, #0x30]
	asrs r0, r0, #8
	adds r0, #0x70
	adds r1, r1, r0
	lsls r0, r1, #0x10
	lsrs r3, r0, #0x10
	strh r1, [r2]
	ldr r6, _08015E14 @ =0x0002D025
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _08015E18
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xa0
	rsbs r1, r1, #0
	cmp r0, r1
	ble _08015E18
	adds r0, r4, #0
	subs r0, #0xc
	mov r2, r8
	lsls r1, r2, #8
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	b _08015E24
	.align 2, 0
_08015DF0: .4byte 0x0002C002
_08015DF4: .4byte gVideoRegBuffer+4
_08015DF8: .4byte 0x01000400
_08015DFC: .4byte gBgMapOffsets
_08015E00: .4byte 0x0002D040
_08015E04: .4byte 0x0002D054
_08015E08: .4byte 0x0002D058
_08015E0C: .4byte gVideoRegBuffer+12
_08015E10: .4byte 0xFFFB0000
_08015E14: .4byte 0x0002D025
_08015E18:
	ldr r2, _08015E30 @ =gVideoRegBuffer
	mov r3, r8
	lsls r1, r3, #8
	ldrh r0, [r2]
	bics r0, r1
	strh r0, [r2]
_08015E24:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08015E30: .4byte gVideoRegBuffer

	thumb_func_start weillabo_08015e34
weillabo_08015e34: @ 0x08015E34
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	ldr r5, _08015EE0 @ =gOverworld
	cmp r0, #0
	bne _08015E72
	ldr r0, [r6, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08015EE4 @ =gVideoRegBuffer+4
	movs r3, #0
	adds r1, r6, #0
	adds r1, #0xc
_08015E4E:
	str r3, [r1, #0x68]
	subs r1, #4
	cmp r1, r6
	bge _08015E4E
	lsrs r2, r0, #4
	lsls r2, r2, #1
	adds r2, r2, r4
	ldrh r1, [r2]
	ldr r0, _08015EE8 @ =0x0000FFFC
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0
	strh r0, [r6, #0x10]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08015E72:
	ldr r1, _08015EEC @ =0x0002D026
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08015F04
	ldrh r0, [r6, #0x10]
	adds r0, #1
	strh r0, [r6, #0x10]
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x68
_08015E88:
	ldr r0, [r4]
	cmp r0, #0
	bne _08015E98
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	bl FUN_080d8f7c
	str r0, [r4]
_08015E98:
	adds r4, #4
	adds r5, #1
	cmp r5, #3
	ble _08015E88
	movs r4, #0x92
	lsls r4, r4, #1
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	bne _08015EB4
	adds r0, r4, #0
	bl PlaySound
_08015EB4:
	ldrh r1, [r6, #0x10]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08015F64
	ldr r2, _08015EF0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08015EF4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08015EF8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r3
	cmp r0, #0
	beq _08015F64
	ldr r1, _08015EFC @ =gBlendRegBuffer
	ldr r0, _08015F00 @ =0x00000C0A
	b _08015F68
	.align 2, 0
_08015EE0: .4byte gOverworld
_08015EE4: .4byte gVideoRegBuffer+4
_08015EE8: .4byte 0x0000FFFC
_08015EEC: .4byte 0x0002D026
_08015EF0: .4byte RNG_0202f388
_08015EF4: .4byte 0x000343FD
_08015EF8: .4byte 0x00269EC3
_08015EFC: .4byte gBlendRegBuffer
_08015F00: .4byte 0x00000C0A
_08015F04:
	movs r4, #0
	ldr r7, _08015F70 @ =gSolidFnTable
	adds r3, r6, #0
	adds r3, #0x68
	movs r5, #3
_08015F0E:
	ldr r2, [r3]
	cmp r2, #0
	beq _08015F48
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
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
	str r4, [r3]
_08015F48:
	adds r3, #4
	subs r5, #1
	cmp r5, #0
	bge _08015F0E
	movs r4, #0x92
	lsls r4, r4, #1
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	beq _08015F64
	adds r0, r4, #0
	bl StopSound
_08015F64:
	ldr r1, _08015F74 @ =gBlendRegBuffer
	ldr r0, _08015F78 @ =0x00000C04
_08015F68:
	strh r0, [r1, #2]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08015F70: .4byte gSolidFnTable
_08015F74: .4byte gBlendRegBuffer
_08015F78: .4byte 0x00000C04

	thumb_func_start FUN_08015f7c
FUN_08015f7c: @ 0x08015F7C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	mov r8, r1
	ldr r0, _08015FB0 @ =gOverworld
	ldr r1, _08015FB4 @ =0x0002D026
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08015FC4
	ldr r4, _08015FB8 @ =gStageTilesetOffsets+(18*4)
	ldr r0, [r4]
	ldr r1, _08015FBC @ =0x08705268
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl RequestGraphicTransfer
	ldr r0, [r4]
	ldr r1, _08015FC0 @ =0x08705274
	adds r0, r0, r1
	movs r1, #0
	bl LoadPalette
	b _08015FFE
	.align 2, 0
_08015FB0: .4byte gOverworld
_08015FB4: .4byte 0x0002D026
_08015FB8: .4byte gStageTilesetOffsets+(18*4)
_08015FBC: .4byte 0x08705268
_08015FC0: .4byte 0x08705274
_08015FC4:
	ldr r6, _08016010 @ =gStageTilesetOffsets+(18*4)
	ldrh r0, [r7, #0x10]
	lsrs r0, r0, #2
	movs r5, #3
	ands r0, r5
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _08016014 @ =0x0870527C
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl RequestGraphicTransfer
	ldrh r0, [r7, #0x10]
	lsrs r0, r0, #2
	ands r0, r5
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl LoadPalette
_08015FFE:
	adds r0, r7, #0
	mov r1, r8
	bl DrawGeneralStageLayer
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08016010: .4byte gStageTilesetOffsets+(18*4)
_08016014: .4byte 0x0870527C

	thumb_func_start FUN_08016018
FUN_08016018: @ 0x08016018
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r6, _0801607C @ =gSolidFnTable
	adds r3, r0, #0
	movs r4, #3
_08016022:
	ldr r2, [r3, #0x68]
	cmp r2, #0
	beq _0801605A
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
	adds r1, r1, r6
	movs r0, #3
	str r0, [r2, #0xc]
	ldr r0, [r1]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
_0801605A:
	adds r3, #4
	subs r4, #1
	cmp r4, #0
	bge _08016022
	movs r4, #0x92
	lsls r4, r4, #1
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	beq _08016076
	adds r0, r4, #0
	bl StopSound
_08016076:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801607C: .4byte gSolidFnTable

	thumb_func_start FUN_08016080
FUN_08016080: @ 0x08016080
	ldr r1, _0801608C @ =gOverworld
	ldr r2, _08016090 @ =0x0002D034
	adds r1, r1, r2
	str r0, [r1]
	bx lr
	.align 2, 0
_0801608C: .4byte gOverworld
_08016090: .4byte 0x0002D034

