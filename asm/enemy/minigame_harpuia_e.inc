	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0809b954
FUN_0809b954: @ 0x0809B954
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0809BA0C
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	ldr r2, _0809B9F0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0809B9F4 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _0809B9F8 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	ldr r2, _0809B9FC @ =0x00004707
	mov r0, sp
	movs r1, #0
	adds r3, r4, #0
	bl CreateGhost82_2
	adds r1, r0, #0
	ldr r0, [r7, #0x28]
	str r0, [r1, #0x28]
	ldr r2, _0809BA00 @ =0x00004708
	mov r0, sp
	movs r1, #0
	adds r3, r4, #0
	bl CreateGhost82_2
	adds r1, r0, #0
	ldr r0, [r7, #0x28]
	str r0, [r1, #0x28]
	ldr r2, _0809BA04 @ =0x00004709
	mov r0, sp
	movs r1, #0
	adds r3, r4, #0
	bl CreateGhost82_2
	adds r1, r0, #0
	ldr r0, [r7, #0x28]
	str r0, [r1, #0x28]
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _0809BA08 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl HarpuiaMinigameEnemy_Die
	b _0809BD16
	.align 2, 0
_0809B9F0: .4byte RNG_0202f388
_0809B9F4: .4byte 0x000343FD
_0809B9F8: .4byte 0x00269EC3
_0809B9FC: .4byte 0x00004707
_0809BA00: .4byte 0x00004708
_0809BA04: .4byte 0x00004709
_0809BA08: .4byte gEnemyFnTable
_0809BA0C:
	ldrb r0, [r7, #0xe]
	cmp r0, #6
	bls _0809BA14
	b _0809BD16
_0809BA14:
	lsls r0, r0, #2
	ldr r1, _0809BA20 @ =_0809BA24
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809BA20: .4byte _0809BA24
_0809BA24: @ jump table
	.4byte _0809BA40 @ case 0
	.4byte _0809BAFC @ case 1
	.4byte _0809BBD0 @ case 2
	.4byte _0809BBDA @ case 3
	.4byte _0809BD16 @ case 4
	.4byte _0809BC08 @ case 5
	.4byte _0809BCD2 @ case 6
_0809BA40:
	ldr r1, _0809BA80 @ =0x00004703
	adds r0, r7, #0
	bl SetMotion
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [r7, #0x64]
	str r1, [r7, #0x68]
	ldr r0, _0809BA84 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r7, #0x54]
	cmp r1, r0
	ble _0809BA88
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
	b _0809BAA6
	.align 2, 0
_0809BA80: .4byte 0x00004703
_0809BA84: .4byte pZero2
_0809BA88:
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
_0809BAA6:
	movs r0, #0xb
	strb r0, [r7, #0x12]
	movs r0, #4
	strb r0, [r7, #0x13]
	ldr r4, _0809BB44 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _0809BB48 @ =0x000343FD
	mov r8, r1
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	ldr r6, _0809BB4C @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x50
	bl __umodsi3
	subs r0, #0x28
	lsls r0, r0, #8
	ldr r1, [r7, #0x54]
	adds r1, r1, r0
	str r1, [r7, #0x5c]
	mov r0, r8
	muls r0, r5, r0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x50
	bl __umodsi3
	subs r0, #0x28
	lsls r0, r0, #8
	ldr r1, [r7, #0x58]
	adds r1, r1, r0
	str r1, [r7, #0x60]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0809BAFC:
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _0809BB18
	ldr r0, [r7, #0x54]
	ldr r1, _0809BB50 @ =0xFFFC4000
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x64]
	adds r0, r0, r1
	str r0, [r7, #0x64]
	ldr r0, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x5c]
_0809BB18:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _0809BB28
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809BBAC
_0809BB28:
	movs r0, #0xb
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	beq _0809BB3C
	subs r0, #1
	strb r0, [r7, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809BB54
_0809BB3C:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _0809BBC8
	.align 2, 0
_0809BB44: .4byte RNG_0202f388
_0809BB48: .4byte 0x000343FD
_0809BB4C: .4byte 0x00269EC3
_0809BB50: .4byte 0xFFFC4000
_0809BB54:
	ldr r4, _0809BBA0 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r3, _0809BBA4 @ =0x000343FD
	mov r8, r3
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r6, _0809BBA8 @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x50
	bl __umodsi3
	subs r0, #0x28
	lsls r0, r0, #8
	ldr r1, [r7, #0x64]
	adds r1, r1, r0
	str r1, [r7, #0x5c]
	mov r0, r8
	muls r0, r5, r0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x50
	bl __umodsi3
	subs r0, #0x28
	lsls r0, r0, #8
	ldr r1, [r7, #0x68]
	adds r1, r1, r0
	str r1, [r7, #0x60]
	b _0809BBC8
	.align 2, 0
_0809BBA0: .4byte RNG_0202f388
_0809BBA4: .4byte 0x000343FD
_0809BBA8: .4byte 0x00269EC3
_0809BBAC:
	ldr r0, [r7, #0x5c]
	ldr r1, [r7, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x54]
	ldr r0, [r7, #0x60]
	ldr r1, [r7, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x58]
_0809BBC8:
	adds r0, r7, #0
	bl UpdateEntityAnim
	b _0809BD16
_0809BBD0:
	movs r0, #7
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0809BBDA:
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _0809BBEA
	ldr r0, [r7, #0x54]
	ldr r2, _0809BC04 @ =0xFFFC4000
	adds r0, r0, r2
	str r0, [r7, #0x54]
_0809BBEA:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809BBFE
	b _0809BD16
_0809BBFE:
	movs r0, #5
	strb r0, [r7, #0xe]
	b _0809BD16
	.align 2, 0
_0809BC04: .4byte 0xFFFC4000
_0809BC08:
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _0809BC18
	ldr r0, [r7, #0x54]
	ldr r3, _0809BC74 @ =0xFFFC4000
	adds r0, r0, r3
	str r0, [r7, #0x54]
_0809BC18:
	ldr r1, _0809BC78 @ =0x00004703
	adds r0, r7, #0
	bl SetMotion
	ldr r5, _0809BC7C @ =pZero2
	ldr r2, [r5]
	ldr r0, [r7, #0x54]
	ldr r1, [r2, #0x54]
	subs r0, r0, r1
	str r0, [r7, #0x64]
	ldr r1, [r7, #0x58]
	movs r3, #0xd8
	lsls r3, r3, #6
	adds r1, r1, r3
	ldr r2, [r2, #0x58]
	subs r1, r1, r2
	str r1, [r7, #0x68]
	asrs r0, r0, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r1, #2
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0xe
	cmp r4, #0
	beq _0809BC80
	ldr r0, [r7, #0x64]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r7, #0x64]
	ldr r0, [r7, #0x68]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r7, #0x68]
	b _0809BC9C
	.align 2, 0
_0809BC74: .4byte 0xFFFC4000
_0809BC78: .4byte 0x00004703
_0809BC7C: .4byte pZero2
_0809BC80:
	ldr r0, [r5]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0809BC94
	ldr r0, _0809BC90 @ =0xFFFFFF00
	b _0809BC98
	.align 2, 0
_0809BC90: .4byte 0xFFFFFF00
_0809BC94:
	movs r0, #0x80
	lsls r0, r0, #1
_0809BC98:
	str r0, [r7, #0x64]
	str r4, [r7, #0x68]
_0809BC9C:
	ldr r1, [r7, #0x64]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #6
	rsbs r0, r0, #0
	asrs r0, r0, #8
	str r0, [r7, #0x5c]
	ldr r1, [r7, #0x68]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #6
	rsbs r0, r0, #0
	asrs r0, r0, #8
	str r0, [r7, #0x60]
	adds r0, r7, #0
	bl UpdateEntityAnim
	movs r0, #0x78
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _0809BD16
_0809BCD2:
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _0809BCE2
	ldr r0, [r7, #0x54]
	ldr r1, _0809BD24 @ =0xFFFC4000
	adds r0, r0, r1
	str r0, [r7, #0x54]
_0809BCE2:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809BD16
	ldr r1, _0809BD28 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_0809BD16:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809BD24: .4byte 0xFFFC4000
_0809BD28: .4byte gEnemyFnTable

	thumb_func_start FUN_0809bd2c
FUN_0809bd2c: @ 0x0809BD2C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0xc]
	ldr r3, [r2, #4]
	ldr r0, [r4, #0x2c]
	mov ip, r0
	ldr r0, [r3, #4]
	ldr r1, _0809BD58 @ =0x00FF00FF
	ands r0, r1
	ldr r1, _0809BD5C @ =0x00020002
	cmp r0, r1
	bne _0809BD60
	mov r0, ip
	adds r0, #0xb4
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809BD94
	ldr r0, [r2, #0x2c]
	mov r1, ip
	str r0, [r1, #0x2c]
	b _0809BD94
	.align 2, 0
_0809BD58: .4byte 0x00FF00FF
_0809BD5C: .4byte 0x00020002
_0809BD60:
	ldrb r0, [r3, #4]
	cmp r0, #2
	beq _0809BDCC
	ldrb r0, [r3, #1]
	cmp r0, #0
	beq _0809BD94
	mov r0, ip
	adds r0, #0xb4
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809BD8C
	mov r1, ip
	adds r1, #0xa4
	ldrh r2, [r1]
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r0, #0x10
	bgt _0809BD94
	adds r0, r2, #0
	adds r0, #8
	strh r0, [r1]
	b _0809BD94
_0809BD8C:
	mov r1, ip
	adds r1, #0xb6
	movs r0, #1
	strb r0, [r1]
_0809BD94:
	ldrb r0, [r3, #4]
	cmp r0, #2
	beq _0809BDCC
	ldrb r0, [r3, #1]
	cmp r0, #0
	beq _0809BDCC
	ldr r0, [r4, #0xc]
	ldr r3, [r0, #0x2c]
	adds r0, r3, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	cmp r0, #1
	beq _0809BDCC
	ldr r0, [r4, #4]
	ldrb r2, [r0, #1]
	cmp r2, #2
	bne _0809BDCC
	mov r1, ip
	adds r1, #0xb7
	ldrb r0, [r1]
	cmp r0, #0
	beq _0809BDC8
	adds r0, r3, #0
	adds r0, #0xb6
	strb r2, [r0]
	b _0809BDCC
_0809BDC8:
	adds r0, #1
	strb r0, [r1]
_0809BDCC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
