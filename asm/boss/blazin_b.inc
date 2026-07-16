	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start blazinNeutral
blazinNeutral: @ 0x0803EFC8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	beq _0803F062
	cmp r0, #1
	bgt _0803EFE2
	cmp r0, #0
	beq _0803EFE8
	b _0803F262
_0803EFE2:
	cmp r0, #2
	beq _0803F0AA
	b _0803F262
_0803EFE8:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	ldr r1, [r6, #0x58]
	cmp r1, r0
	bne _0803F00C
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r0, [r0]
	movs r2, #0xa2
	lsls r2, r2, #8
	adds r1, r2, #0
	orrs r1, r0
	adds r0, r6, #0
	bl SetMotion
	b _0803F028
_0803F00C:
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #1
	ldr r2, _0803F050 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	movs r2, #1
	movs r3, #0
	bl GotoMotion
_0803F028:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0803F054 @ =gBlazinCollisions+(24*1)
	bl SetDDP
	movs r1, #0
	str r1, [r6, #0x60]
	str r1, [r6, #0x5c]
	adds r0, r6, #0
	adds r0, #0x64
	str r1, [r0, #4]
	str r1, [r6, #0x64]
	ldrb r0, [r6, #0xf]
	cmp r0, #0xff
	bne _0803F058
	movs r0, #1
	strb r0, [r6, #0x13]
	strb r1, [r6, #0xf]
	b _0803F05C
	.align 2, 0
_0803F050: .4byte 0xFFFFA200
_0803F054: .4byte gBlazinCollisions+(24*1)
_0803F058:
	movs r0, #0x24
	strb r0, [r6, #0x13]
_0803F05C:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803F062:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r0, [r6, #0x68]
	adds r0, #0x40
	str r0, [r6, #0x68]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0803F07C
	str r1, [r6, #0x68]
_0803F07C:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x68]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	cmp r0, r2
	ble _0803F0A2
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r0, [r0]
	movs r2, #0xa2
	lsls r2, r2, #8
	adds r1, r2, #0
	orrs r1, r0
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803F0A2:
	adds r0, r6, #0
	bl UpdateEntityAnim
	b _0803F262
_0803F0AA:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r4, r0, #0
	adds r0, r6, #0
	bl setBlazinDirection
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x68]
	adds r0, #0x40
	str r0, [r6, #0x68]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0803F0D0
	str r1, [r6, #0x68]
_0803F0D0:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x68]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	cmp r0, r4
	ble _0803F0DE
	str r4, [r6, #0x58]
_0803F0DE:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	ldr r1, [r6, #0x58]
	cmp r1, r0
	beq _0803F0EE
	b _0803F262
_0803F0EE:
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	bne _0803F0F6
	b _0803F262
_0803F0F6:
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	beq _0803F104
	b _0803F262
_0803F104:
	adds r0, r6, #0
	adds r0, #0xb5
	adds r1, r6, #0
	adds r1, #0xb6
	movs r3, #0
	ldrsb r3, [r0, r3]
	movs r2, #0
	ldrsb r2, [r1, r2]
	mov r8, r0
	mov sb, r1
	cmp r3, r2
	bne _0803F1E0
	ldr r0, _0803F170 @ =gScore
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _0803F184
	adds r0, r6, #0
	bl howFarBlazin
	adds r3, r0, #0
	ldr r2, _0803F174 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0803F178 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0803F17C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _0803F180 @ =BlazinEXModes
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r1, [r4]
	mov r2, r8
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r1, r0
	bne _0803F252
	adds r0, r6, #0
	movs r2, #1
	bl blazin_080402fc
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b _0803F252
	.align 2, 0
_0803F170: .4byte gScore
_0803F174: .4byte RNG_0202f388
_0803F178: .4byte 0x000343FD
_0803F17C: .4byte 0x00269EC3
_0803F180: .4byte BlazinEXModes
_0803F184:
	adds r0, r6, #0
	bl howFarBlazin
	adds r3, r0, #0
	ldr r2, _0803F1D0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0803F1D4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0803F1D8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _0803F1DC @ =BlazinModes
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r1, [r4]
	mov r2, r8
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r1, r0
	bne _0803F252
	adds r0, r6, #0
	movs r2, #0
	bl blazin_080402fc
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b _0803F252
	.align 2, 0
_0803F1D0: .4byte RNG_0202f388
_0803F1D4: .4byte 0x000343FD
_0803F1D8: .4byte 0x00269EC3
_0803F1DC: .4byte BlazinModes
_0803F1E0:
	ldr r0, _0803F20C @ =gScore
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _0803F220
	adds r0, r6, #0
	bl howFarBlazin
	adds r3, r0, #0
	ldr r2, _0803F210 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0803F214 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0803F218 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _0803F21C @ =BlazinEXModes
	b _0803F23E
	.align 2, 0
_0803F20C: .4byte gScore
_0803F210: .4byte RNG_0202f388
_0803F214: .4byte 0x000343FD
_0803F218: .4byte 0x00269EC3
_0803F21C: .4byte BlazinEXModes
_0803F220:
	adds r0, r6, #0
	bl howFarBlazin
	adds r3, r0, #0
	ldr r2, _0803F270 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0803F274 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0803F278 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _0803F27C @ =BlazinModes
_0803F23E:
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r1, [r4]
_0803F252:
	strb r1, [r6, #0xd]
	strb r7, [r6, #0xe]
	mov r2, r8
	ldrb r0, [r2]
	mov r2, sb
	strb r0, [r2]
	mov r0, r8
	strb r1, [r0]
_0803F262:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803F270: .4byte RNG_0202f388
_0803F274: .4byte 0x000343FD
_0803F278: .4byte 0x00269EC3
_0803F27C: .4byte BlazinModes

