	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a7e0c
FUN_080a7e0c:
	.byte 0x30, 0xB5, 0x82, 0xB0
	.byte 0x04, 0x1C, 0x25, 0x1C, 0x8C, 0x35, 0x28, 0x68, 0x80, 0x21, 0x09, 0x01, 0x08, 0x40, 0x00, 0x28
	.byte 0x07, 0xD0, 0x1A, 0x48, 0x00, 0x68, 0x8C, 0x30, 0x00, 0x68, 0x01, 0x21, 0x08, 0x40, 0x00, 0x28
	.byte 0x28, 0xD0, 0x60, 0x6D, 0x00, 0x90, 0xA0, 0x6D, 0x15, 0x49, 0x40, 0x18, 0x01, 0x90, 0x15, 0x4A
	.byte 0x20, 0x1C, 0x69, 0x46, 0x04, 0x23, 0x10, 0xF0, 0xD9, 0xF8, 0x3F, 0x20, 0x5C, 0xF7, 0xA8, 0xFB
	.byte 0xA1, 0x7A, 0xFE, 0x20, 0x08, 0x40, 0x00, 0x22, 0xFD, 0x21, 0x08, 0x40, 0xA0, 0x72, 0x2A, 0x60
	.byte 0x20, 0x1C, 0x90, 0x30, 0x02, 0x60, 0x04, 0x30, 0x02, 0x70, 0xA1, 0x7A, 0xFB, 0x20, 0x08, 0x40
	.byte 0xA0, 0x72, 0x09, 0x49, 0x60, 0x7A, 0x80, 0x00, 0x40, 0x18, 0x03, 0x21, 0xE1, 0x60, 0x00, 0x68
	.byte 0xC0, 0x68, 0x60, 0x61, 0x02, 0xB0, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x40, 0xF3, 0x02, 0x02
	.byte 0x00, 0xF0, 0xFF, 0xFF, 0xC6, 0xBE, 0x36, 0x08
  .4byte gProjectileFnTable

	thumb_func_start FUN_080a7e9c
FUN_080a7e9c: @ 0x080A7E9C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080A7EAC
	cmp r0, #1
	beq _080A7EDA
	b _080A7F62
_080A7EAC:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A7EF4 @ =0x0836BE64
	bl SetDDP
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _080A7EF8 @ =0xFFFFFEC0
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	movs r0, #0x80
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	movs r1, #0xae
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A7EDA:
	ldr r0, _080A7EFC @ =pZero2
	ldr r0, [r0]
	adds r0, #0x94
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A7F04
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A7F00 @ =0x0836BEAC
	bl SetDDP
	b _080A7F0E
	.align 2, 0
_080A7EF4: .4byte 0x0836BE64
_080A7EF8: .4byte 0xFFFFFEC0
_080A7EFC: .4byte pZero2
_080A7F00: .4byte 0x0836BEAC
_080A7F04:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A7F68 @ =0x0836BE64
	bl SetDDP
_080A7F0E:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r3, [r0]
	cmp r3, #3
	bne _080A7F62
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A7F6C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r3, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080A7F62:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A7F68: .4byte 0x0836BE64
_080A7F6C: .4byte gProjectileFnTable

	thumb_func_start FUN_080a7f70
FUN_080a7f70: @ 0x080A7F70
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080A7FBE
	cmp r0, #1
	bgt _080A7F84
	cmp r0, #0
	beq _080A7F8E
	b _080A8072
_080A7F84:
	cmp r0, #2
	beq _080A7FF4
	cmp r0, #3
	beq _080A802E
	b _080A8072
_080A7F8E:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A7FEC @ =0x0836BE7C
	bl SetDDP
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #6
	ldr r1, _080A7FF0 @ =0xFFFFFEE0
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	movs r0, #0xe0
	str r0, [r4, #0x60]
	movs r0, #0x40
	strb r0, [r4, #0x12]
	movs r1, #0xac
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A7FBE:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	subs r1, #2
	str r1, [r4, #0x60]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A8072
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080A8072
	.align 2, 0
_080A7FEC: .4byte 0x0836BE7C
_080A7FF0: .4byte 0xFFFFFEE0
_080A7FF4:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	subs r1, #2
	str r1, [r4, #0x60]
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
	ldr r1, _080A8078 @ =0x00005601
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A802E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r3, [r0]
	cmp r3, #3
	bne _080A8072
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A807C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r3, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080A8072:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A8078: .4byte 0x00005601
_080A807C: .4byte gProjectileFnTable

	thumb_func_start FUN_080a8080
FUN_080a8080: @ 0x080A8080
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #0
	beq _080A8090
	cmp r4, #1
	beq _080A80B2
	b _080A8110
_080A8090:
	movs r0, #0x40
	bl PlaySound
	strb r4, [r5, #0x12]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080A80EC @ =0x0836BE94
	bl SetDDP
	movs r1, #0xb0
	lsls r1, r1, #7
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A80B2:
	ldr r2, _080A80F0 @ =pZero2
	ldr r0, [r2]
	ldr r1, _080A80F4 @ =0x00000143
	adds r3, r0, r1
	ldrb r1, [r3]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	movs r4, #1
	orrs r0, r4
	strb r0, [r3]
	ldr r0, [r2]
	ldr r1, _080A80F4 @ =0x00000143
	adds r3, r0, r1
	ldrb r1, [r3]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r3]
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A80F8
	ldrb r0, [r5, #0xa]
	orrs r0, r4
	b _080A80FE
	.align 2, 0
_080A80EC: .4byte 0x0836BE94
_080A80F0: .4byte pZero2
_080A80F4: .4byte 0x00000143
_080A80F8:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080A80FE:
	strb r0, [r5, #0xa]
	ldr r0, [r2]
	ldr r1, [r0, #0x54]
	str r1, [r5, #0x54]
	ldr r0, [r0, #0x58]
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
_080A8110:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

