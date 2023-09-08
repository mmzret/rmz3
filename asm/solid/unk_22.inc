	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080d7e5c
FUN_080d7e5c: @ 0x080D7E5C
	push {r4, r5, lr}
	ldr r3, [r0, #0x2c]
	ldr r0, [r0, #0xc]
	ldr r4, [r0, #0x2c]
	movs r2, #8
	ldrsb r2, [r4, r2]
	cmp r2, #0
	bne _080D7EAA
	ldr r1, [r3, #0x58]
	ldr r0, [r4, #0x58]
	cmp r1, r0
	ble _080D7E84
	ldrb r1, [r3, #0x10]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _080D7EAA
	strb r5, [r3, #0xd]
	b _080D7E92
_080D7E84:
	ldrb r1, [r3, #0x10]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D7EAA
	movs r0, #2
	strb r0, [r3, #0xd]
_080D7E92:
	strb r2, [r3, #0xe]
	ldr r0, _080D7EB0 @ =0x00000119
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _080D7EB4 @ =gStageRun
	ldrh r1, [r2, #0x14]
	orrs r0, r1
	strh r0, [r2, #0x14]
	adds r0, r3, #0
	adds r0, #0xb4
	str r4, [r0]
_080D7EAA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D7EB0: .4byte 0x00000119
_080D7EB4: .4byte gStageRun

	thumb_func_start FUN_080d7eb8
FUN_080d7eb8: @ 0x080D7EB8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _080D7EC8
	cmp r0, #1
	beq _080D7EF8
	b _080D7EFE
_080D7EC8:
	movs r1, #0xf0
	lsls r1, r1, #7
	adds r0, r5, #0
	bl SetMotion
	ldrb r1, [r5, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080D7F04 @ =sCollisions
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _080D7F08 @ =FUN_080d7e5c
	str r0, [r4, #0x24]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080D7EF8:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_080D7EFE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D7F04: .4byte sCollisions
_080D7F08: .4byte FUN_080d7e5c

	thumb_func_start openStageDoor_080d7f0c
openStageDoor_080d7f0c: @ 0x080D7F0C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _080D7F18
	b _080D8074
_080D7F18:
	lsls r0, r0, #2
	ldr r1, _080D7F24 @ =_080D7F28
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D7F24: .4byte _080D7F28
_080D7F28: @ jump table
	.4byte _080D7F3C @ case 0
	.4byte _080D7F98 @ case 1
	.4byte _080D7FA4 @ case 2
	.4byte _080D7FCC @ case 3
	.4byte _080D803C @ case 4
_080D7F3C:
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r1, [r4, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r4, #0xb]
	ldr r1, _080D7F90 @ =0x00007802
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r4, #0x54]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r0, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r0, r3
	str r0, [r1, #4]
	ldr r2, _080D7F94 @ =gCollisionManager
	ldrb r1, [r2, #1]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #1]
	movs r0, #0x40
	b _080D8024
	.align 2, 0
_080D7F90: .4byte 0x00007802
_080D7F94: .4byte gCollisionManager
_080D7F98:
	ldr r1, _080D7FC8 @ =gCollisionManager
	movs r0, #0
	strb r0, [r1, #1]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080D7FA4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0x1c
	bne _080D7FB6
	movs r0, #0x9c
	bl PlaySound
_080D7FB6:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D8074
	movs r0, #0x40
	b _080D8024
	.align 2, 0
_080D7FC8: .4byte gCollisionManager
_080D7FCC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r2, r4, #0
	adds r2, #0xb4
	ldr r1, [r2]
	ldr r0, [r1, #0x58]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r0, r3
	str r0, [r1, #0x58]
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r5, [r2]
	ldr r0, [r1]
	ldr r2, [r5, #0x54]
	subs r6, r0, r2
	cmp r6, r3
	ble _080D7FF6
	adds r0, r2, r3
	b _080D7FFE
_080D7FF6:
	ldr r0, _080D8030 @ =0xFFFFFF00
	cmp r6, r0
	bge _080D8000
	adds r0, r2, r0
_080D7FFE:
	str r0, [r5, #0x54]
_080D8000:
	ldrb r2, [r4, #0x12]
	cmp r2, #0x20
	bne _080D800A
	ldr r0, _080D8034 @ =gStageRun+232
	str r1, [r0, #0x48]
_080D800A:
	subs r0, r2, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D8074
	movs r0, #0x9d
	bl PlaySound
	ldr r1, _080D8038 @ =0x00007803
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x20
_080D8024:
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080D8074
	.align 2, 0
_080D8030: .4byte 0xFFFFFF00
_080D8034: .4byte gStageRun+232
_080D8038: .4byte 0x00007803
_080D803C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D8074
	ldr r1, _080D807C @ =gStageRun
	ldrh r2, [r1, #0x14]
	ldr r0, _080D8080 @ =0x0000FFFE
	ands r0, r2
	movs r2, #0
	strh r0, [r1, #0x14]
	adds r1, #0xe8
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r3, [r0]
	adds r0, r3, #0
	adds r0, #0x54
	str r0, [r1, #0x48]
	ldr r1, _080D8084 @ =0x00000119
	adds r0, r3, r1
	strb r2, [r0]
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
_080D8074:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D807C: .4byte gStageRun
_080D8080: .4byte 0x0000FFFE
_080D8084: .4byte 0x00000119

	thumb_func_start FUN_080d8088
FUN_080d8088: @ 0x080D8088
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _080D8094
	b _080D81F8
_080D8094:
	lsls r0, r0, #2
	ldr r1, _080D80A0 @ =_080D80A4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D80A0: .4byte _080D80A4
_080D80A4: @ jump table
	.4byte _080D80B8 @ case 0
	.4byte _080D8118 @ case 1
	.4byte _080D8124 @ case 2
	.4byte _080D814C @ case 3
	.4byte _080D81C0 @ case 4
_080D80B8:
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r1, [r4, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r4, #0xb]
	ldr r1, _080D810C @ =0x00007802
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r4, #0x54]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r0, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	ldr r5, _080D8110 @ =0xFFFFC000
	adds r0, r0, r5
	str r0, [r1, #4]
	ldr r2, _080D8114 @ =gCollisionManager
	ldrb r1, [r2, #1]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #1]
	movs r0, #0x40
	b _080D81AA
	.align 2, 0
_080D810C: .4byte 0x00007802
_080D8110: .4byte 0xFFFFC000
_080D8114: .4byte gCollisionManager
_080D8118:
	ldr r1, _080D8148 @ =gCollisionManager
	movs r0, #0
	strb r0, [r1, #1]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080D8124:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0x1c
	bne _080D8136
	movs r0, #0x9c
	bl PlaySound
_080D8136:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D81F8
	movs r0, #0x40
	b _080D81AA
	.align 2, 0
_080D8148: .4byte gCollisionManager
_080D814C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r2, r4, #0
	adds r2, #0xb4
	ldr r1, [r2]
	ldr r0, [r1, #0x58]
	ldr r6, _080D8178 @ =0xFFFFFF00
	adds r0, r0, r6
	str r0, [r1, #0x58]
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r2, [r2]
	ldr r0, [r1]
	ldr r3, [r2, #0x54]
	subs r5, r0, r3
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r5, r0
	ble _080D817C
	adds r0, r3, r0
	b _080D8184
	.align 2, 0
_080D8178: .4byte 0xFFFFFF00
_080D817C:
	cmp r5, r6
	bge _080D8186
	ldr r5, _080D81B4 @ =0xFFFFFF00
	adds r0, r3, r5
_080D8184:
	str r0, [r2, #0x54]
_080D8186:
	ldrb r2, [r4, #0x12]
	cmp r2, #0x20
	bne _080D8190
	ldr r0, _080D81B8 @ =gStageRun+232
	str r1, [r0, #0x48]
_080D8190:
	subs r0, r2, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D81F8
	movs r0, #0x9d
	bl PlaySound
	ldr r1, _080D81BC @ =0x00007803
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x20
_080D81AA:
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080D81F8
	.align 2, 0
_080D81B4: .4byte 0xFFFFFF00
_080D81B8: .4byte gStageRun+232
_080D81BC: .4byte 0x00007803
_080D81C0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D81F8
	ldr r1, _080D8200 @ =gStageRun
	ldrh r2, [r1, #0x14]
	ldr r0, _080D8204 @ =0x0000FFFE
	ands r0, r2
	movs r2, #0
	strh r0, [r1, #0x14]
	adds r1, #0xe8
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r3, [r0]
	adds r0, r3, #0
	adds r0, #0x54
	str r0, [r1, #0x48]
	ldr r1, _080D8208 @ =0x00000119
	adds r0, r3, r1
	strb r2, [r0]
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
_080D81F8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D8200: .4byte gStageRun
_080D8204: .4byte 0x0000FFFE
_080D8208: .4byte 0x00000119

	thumb_func_start FUN_080d820c
FUN_080d820c: @ 0x080D820C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080D822A
	cmp r0, #1
	bgt _080D8220
	cmp r0, #0
	beq _080D8226
	b _080D8252
_080D8220:
	cmp r0, #2
	beq _080D824C
	b _080D8252
_080D8226:
	movs r0, #1
	strb r0, [r4, #0xe]
_080D822A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D8252
	movs r1, #0xf0
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080D8252
_080D824C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080D8252:
	pop {r4}
	pop {r0}
	bx r0
