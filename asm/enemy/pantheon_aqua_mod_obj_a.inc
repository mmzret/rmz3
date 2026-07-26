	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08080cbc
FUN_08080cbc: @ 0x08080CBC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r6, r1, #0
	ldr r4, [r0, #8]
	movs r5, #0xa0
	lsls r5, r5, #1
	adds r0, r5, #0
	bl Malloc
	str r0, [sp]
	cmp r0, #0
	bne _08080CDE
	b _08080E96
_08080CDE:
	movs r0, #0
	ldr r1, [sp]
	adds r2, r5, #0
	bl FillMemory
	ldr r0, [r4, #0x54]
	ldr r1, [r6, #8]
	subs r0, r0, r1
	lsls r0, r0, #8
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldr r0, [r4, #0x58]
	ldr r1, [r6, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #8
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	movs r2, #0
	adds r4, #0xb4
	str r4, [sp, #0x1c]
_08080D06:
	lsls r2, r2, #0x10
	asrs r0, r2, #0x10
	mov sb, r0
	ldr r0, [sp, #0x1c]
	add r0, sb
	ldrb r1, [r0]
	adds r1, #0x40
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	ldr r3, _08080DF0 @ =gSineTable
	adds r1, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r6, [r0]
	ldrh r5, [r1]
	mov ip, r5
	movs r0, #0
	ldrsh r3, [r1, r0]
	movs r1, #1
	mov sl, r1
	str r2, [sp, #0x20]
	cmp r3, #0
	bge _08080D3A
	ldr r2, _08080DF4 @ =0x0000FFFF
	mov sl, r2
_08080D3A:
	mov r5, sl
	str r5, [sp, #0xc]
	lsls r0, r6, #0x10
	asrs r1, r0, #0x10
	movs r0, #1
	mov r8, r0
	cmp r1, #0
	bge _08080D4E
	ldr r2, _08080DF4 @ =0x0000FFFF
	mov r8, r2
_08080D4E:
	mov r5, r8
	str r5, [sp, #0x10]
	cmp r3, #0
	bge _08080D5E
	rsbs r0, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
_08080D5E:
	cmp r1, #0
	bge _08080D68
	rsbs r0, r1, #0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
_08080D68:
	mov r1, ip
	lsls r0, r1, #0x10
	asrs r5, r0, #0x10
	lsls r1, r6, #0x10
	asrs r3, r1, #0x10
	adds r2, r0, #0
	cmp r5, r3
	ble _08080DF8
	ldr r7, [sp, #4]
	ldr r4, [sp, #8]
	movs r1, #1
	ldr r5, [sp, #0xc]
	lsls r0, r5, #0x10
	mov r5, sb
	lsls r5, r5, #3
	mov sl, r5
	asrs r0, r0, #0x10
	mov sb, r0
	mov r8, r3
	asrs r6, r2, #0x10
	ldr r2, [sp, #0x10]
	lsls r0, r2, #0x10
	asrs r5, r0, #0x10
_08080D96:
	lsls r3, r7, #0x10
	cmp r1, #0
	beq _08080DB2
	lsls r0, r4, #0x10
	asrs r0, r0, #0xf
	ldr r1, [sp]
	adds r0, r0, r1
	asrs r1, r3, #0x10
	mov r2, sl
	lsls r1, r2
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	movs r1, #0
_08080DB2:
	asrs r0, r3, #0x10
	add r0, sb
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0xef
	bhi _08080E60
	mov r3, ip
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	mov r2, r8
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov ip, r3
	asrs r0, r0, #0x10
	cmp r0, #0
	bgt _08080D96
	movs r1, #1
	adds r0, r0, r6
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	adds r0, r0, r5
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x9f
	bls _08080D96
	b _08080E60
	.align 2, 0
_08080DF0: .4byte gSineTable
_08080DF4: .4byte 0x0000FFFF
_08080DF8:
	ldr r7, [sp, #4]
	ldr r4, [sp, #8]
	mov r2, r8
	lsls r0, r2, #0x10
	mov r3, sb
	lsls r3, r3, #3
	str r3, [sp, #0x14]
	asrs r0, r0, #0x10
	str r0, [sp, #0x18]
	mov ip, r5
	asrs r1, r1, #0x10
	mov sb, r1
	mov r5, sl
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
_08080E18:
	lsls r2, r4, #0x10
	asrs r2, r2, #0x10
	lsls r3, r2, #1
	ldr r0, [sp]
	adds r3, r3, r0
	lsls r0, r7, #0x10
	asrs r5, r0, #0x10
	adds r0, r5, #0
	ldr r1, [sp, #0x14]
	lsls r0, r1
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldr r3, [sp, #0x18]
	adds r2, r2, r3
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	cmp r4, #0x9f
	bhi _08080E60
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	mov r1, ip
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bgt _08080E18
	add r0, sb
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov r2, r8
	adds r0, r5, r2
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	b _08080E18
_08080E60:
	ldr r3, [sp, #0x20]
	movs r5, #0x80
	lsls r5, r5, #9
	adds r0, r3, r5
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bgt _08080E72
	b _08080D06
_08080E72:
	movs r0, #0xa0
	ldr r1, _08080EA8 @ =gWindowRegBuffer
	strh r0, [r1, #0xa]
	ldr r2, _08080EAC @ =gIntrManager
	movs r3, #0xba
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r5, [sp]
	str r5, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _08080EB0 @ =0x04000042
	str r0, [r1]
	adds r3, #8
	adds r1, r2, r3
	ldr r0, _08080EB4 @ =0xA2600001
	str r0, [r1]
_08080E96:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080EA8: .4byte gWindowRegBuffer
_08080EAC: .4byte gIntrManager
_08080EB0: .4byte 0x04000042
_08080EB4: .4byte 0xA2600001
