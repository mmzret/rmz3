	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start IsElfBreeder
IsElfBreeder: @ 0x080E185C
	push {r4, r5, r6, lr}
	movs r4, #0
	ldr r6, _080E1894 @ =gElfBreedInfo
	ldr r0, _080E1898 @ =gUnlockedElfPtr
	ldr r5, [r0]
_080E1866:
	lsls r0, r4, #2
	adds r0, r0, r6
	ldrb r2, [r0]
	lsls r1, r2, #0x1d
	adds r3, r5, r4
	ldr r0, [r3]
	lsls r0, r0, #0x1b
	lsrs r1, r1, #0x1d
	lsrs r0, r0, #0x1e
	cmp r1, r0
	bne _080E188E
	lsls r0, r2, #0x1a
	lsrs r0, r0, #0x1d
	cmp r0, #2
	bne _080E189C
	ldrb r1, [r3]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _080E189C
_080E188E:
	movs r0, #0
	b _080E18A8
	.align 2, 0
_080E1894: .4byte gElfBreedInfo
_080E1898: .4byte gUnlockedElfPtr
_080E189C:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x49
	bls _080E1866
	movs r0, #1
_080E18A8:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start calcElfPenalty
calcElfPenalty: @ 0x080E18B0
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r2, #0
	adds r1, r5, #0
	adds r1, #0xb4
	ldrb r0, [r1, #0x1a]
	cmp r0, #2
	bne _080E18C8
	ldrh r2, [r1, #4]
	movs r0, #0
	strh r0, [r1, #4]
	b _080E1AA6
_080E18C8:
	ldr r4, _080E1AB8 @ =gUnlockedElfPtr
	ldr r3, [r4]
	ldrb r1, [r3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080E18D8
	movs r2, #5
_080E18D8:
	ldrb r1, [r3, #1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080E18E8
	adds r0, r2, #2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080E18E8:
	ldrb r1, [r3, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080E18F8
	adds r0, r2, #2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080E18F8:
	ldrb r1, [r3, #3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080E1908
	adds r0, r2, #2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080E1908:
	ldrb r1, [r3, #4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080E1918
	adds r0, r2, #2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080E1918:
	ldrb r1, [r3, #5]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080E1928
	adds r0, r2, #2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080E1928:
	ldrb r1, [r3, #6]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080E1938
	adds r0, r2, #2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080E1938:
	ldrb r1, [r3, #0x1b]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080E1948
	adds r0, r2, #5
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080E1948:
	ldrb r1, [r3, #0x1c]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080E1958
	adds r0, r2, #2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080E1958:
	ldrb r1, [r3, #0x1d]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080E1968
	adds r0, r2, #2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080E1968:
	ldr r3, [r4]
	ldrb r1, [r3, #0x1e]
	movs r0, #2
	ands r0, r1
	mov ip, r3
	cmp r0, #0
	beq _080E197C
	adds r0, r2, #2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080E197C:
	mov r0, ip
	ldrb r1, [r0, #0x1f]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080E198E
	adds r0, r2, #2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080E198E:
	mov r0, ip
	adds r0, #0x28
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080E19A2
	adds r0, r2, #5
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080E19A2:
	mov r0, ip
	adds r0, #0x29
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080E19B6
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080E19B6:
	mov r0, ip
	adds r0, #0x2a
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080E19CA
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080E19CA:
	mov r0, ip
	adds r0, #0x2b
	ldrb r1, [r0]
	movs r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080E19E0
	adds r0, r2, #2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080E19E0:
	mov r0, ip
	adds r0, #0x2c
	ldrb r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080E19F4
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080E19F4:
	mov r0, ip
	adds r0, #0x2d
	ldrb r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080E1A08
	adds r0, r2, #2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080E1A08:
	mov r0, ip
	adds r0, #0x2e
	ldrb r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080E1A1C
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080E1A1C:
	mov r0, ip
	adds r0, #0x2f
	ldrb r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080E1A30
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080E1A30:
	mov r3, ip
	adds r0, r3, #0
	adds r0, #0x30
	ldrb r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080E1A46
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080E1A46:
	adds r0, r3, #0
	adds r0, #0x31
	ldrb r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080E1A5A
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080E1A5A:
	adds r0, r3, #0
	adds r0, #0x32
	ldrb r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080E1A6E
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080E1A6E:
	adds r0, r3, #0
	adds r0, #0x33
	ldrb r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080E1A82
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080E1A82:
	mov r0, ip
	adds r0, #0x34
	ldrb r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080E1A96
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080E1A96:
	adds r0, r5, #0
	adds r0, #0xb4
	ldrh r1, [r0, #4]
	adds r1, r2, r1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	movs r1, #0
	strh r1, [r0, #4]
_080E1AA6:
	cmp r2, #0x73
	bls _080E1AAC
	movs r2, #0x73
_080E1AAC:
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080E1AB8: .4byte gUnlockedElfPtr

	thumb_func_start createElfAction
createElfAction: @ 0x080E1ABC
	push {r4, lr}
	sub sp, #8
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r1, _080E1AF4 @ =ElfActions
	mov r0, sp
	movs r2, #6
	bl memcpy
	ldr r1, _080E1AF8 @ =gSystemSavedataManager
	lsls r0, r4, #1
	add r0, sp
	ldrh r2, [r0]
	lsrs r0, r2, #3
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #7
	ands r0, r2
	asrs r1, r0
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _080E1AFC
	lsls r0, r4, #0x18
	movs r1, #0x90
	lsls r1, r1, #0x18
	b _080E1B00
	.align 2, 0
_080E1AF4: .4byte ElfActions
_080E1AF8: .4byte gSystemSavedataManager
_080E1AFC:
	lsls r0, r4, #0x18
	ldr r1, _080E1B0C @ =0x90010000
_080E1B00:
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080E1B0C: .4byte 0x90010000

	thumb_func_start FUN_080e1b10
FUN_080e1b10: @ 0x080E1B10
	push {lr}
	ldr r1, _080E1B38 @ =0x00000216
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080E1B40
	ldr r0, _080E1B3C @ =gOverworld
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0x11
	beq _080E1B40
	movs r0, #1
	b _080E1B42
	.align 2, 0
_080E1B38: .4byte 0x00000216
_080E1B3C: .4byte gOverworld
_080E1B40:
	movs r0, #0
_080E1B42:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start clearUnlockedCyberElfData
clearUnlockedCyberElfData: @ 0x080E1B48
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _080E1B78 @ =gUnlockedElfPtr
	str r4, [r0]
	movs r5, #0
	str r5, [sp]
	ldr r2, _080E1B7C @ =0x01000010
	mov r0, sp
	adds r1, r4, #0
	bl CpuFastSet
	str r5, [sp, #4]
	add r0, sp, #4
	adds r4, #0x40
	ldr r2, _080E1B80 @ =0x05000003
	adds r1, r4, #0
	bl CpuSet
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080E1B78: .4byte gUnlockedElfPtr
_080E1B7C: .4byte 0x01000010
_080E1B80: .4byte 0x05000003

	thumb_func_start clearUnlockedCyberElfDataHard
clearUnlockedCyberElfDataHard: @ 0x080E1B84
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _080E1BB4 @ =gUnlockedElfPtr
	str r4, [r0]
	movs r5, #0
	str r5, [sp]
	ldr r2, _080E1BB8 @ =0x01000010
	mov r0, sp
	adds r1, r4, #0
	bl CpuFastSet
	str r5, [sp, #4]
	add r0, sp, #4
	adds r4, #0x40
	ldr r2, _080E1BBC @ =0x05000003
	adds r1, r4, #0
	bl CpuSet
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080E1BB4: .4byte gUnlockedElfPtr
_080E1BB8: .4byte 0x01000010
_080E1BBC: .4byte 0x05000003

	thumb_func_start unlockAllElvesForUltimate
unlockAllElvesForUltimate: @ 0x080E1BC0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r6, _080E1C9C @ =gUnlockedElfPtr
	str r4, [r6]
	movs r5, #0
	str r5, [sp]
	ldr r2, _080E1CA0 @ =0x01000010
	mov r0, sp
	adds r1, r4, #0
	bl CpuFastSet
	str r5, [sp, #4]
	add r0, sp, #4
	adds r4, #0x40
	ldr r2, _080E1CA4 @ =0x05000003
	adds r1, r4, #0
	bl CpuSet
	movs r4, #0
	movs r5, #3
	movs r0, #0x19
	rsbs r0, r0, #0
	mov r8, r0
	mov sb, r0
_080E1BF8:
	ldr r2, [r6]
	adds r2, r2, r4
	ldrb r0, [r2]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	bl FUN_080e1cac
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080E1C84
	ldr r2, [r6]
	adds r2, r2, r4
	ldrb r0, [r2]
	movs r1, #2
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _080E1CA8 @ =gElfBreedInfo
	lsls r0, r4, #2
	adds r3, r0, r1
	ldrb r0, [r3]
	lsls r0, r0, #0x1d
	lsrs r0, r0, #0x1d
	cmp r0, #1
	bne _080E1C46
	ldr r0, [r6]
	adds r0, r0, r4
	ldr r1, [r0]
	lsls r1, r1, #0x1b
	lsrs r1, r1, #0x1e
	adds r1, #1
	ands r1, r5
	lsls r1, r1, #3
	ldrb r2, [r0]
	mov r7, r8
	ands r2, r7
	orrs r2, r1
	strb r2, [r0]
_080E1C46:
	ldrb r0, [r3]
	lsls r0, r0, #0x1d
	lsrs r0, r0, #0x1d
	cmp r0, #2
	bne _080E1C84
	ldr r3, [r6]
	adds r3, r3, r4
	ldr r1, [r3]
	lsls r1, r1, #0x1b
	lsrs r1, r1, #0x1e
	adds r1, #1
	ands r1, r5
	lsls r1, r1, #3
	ldrb r2, [r3]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r3, [r6]
	adds r3, r3, r4
	ldr r1, [r3]
	lsls r1, r1, #0x1b
	lsrs r1, r1, #0x1e
	adds r1, #1
	ands r1, r5
	lsls r1, r1, #3
	ldrb r2, [r3]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_080E1C84:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x49
	bls _080E1BF8
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E1C9C: .4byte gUnlockedElfPtr
_080E1CA0: .4byte 0x01000010
_080E1CA4: .4byte 0x05000003
_080E1CA8: .4byte gElfBreedInfo

	thumb_func_start FUN_080e1cac
FUN_080e1cac: @ 0x080E1CAC
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r3, r2, #0
	ldr r1, _080E1CD0 @ =gElfBreedInfo
	lsls r0, r2, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	lsrs r0, r0, #7
	cmp r0, #0
	bne _080E1CD4
	cmp r2, #5
	beq _080E1CD4
	cmp r3, #6
	beq _080E1CD4
	movs r0, #0
	b _080E1CD6
	.align 2, 0
_080E1CD0: .4byte gElfBreedInfo
_080E1CD4:
	movs r0, #1
_080E1CD6:
	pop {r1}
	bx r1
	.align 2, 0

