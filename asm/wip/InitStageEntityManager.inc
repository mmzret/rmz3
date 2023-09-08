	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r4, _08017C38 @ =gStageEntityManager
	movs r2, #0x83
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r2, #0
	movs r3, #0
	strh r1, [r0]
	ldr r1, _08017C3C @ =0x0000020E
	adds r0, r4, r1
	strh r3, [r0]
	adds r1, #2
	adds r0, r4, r1
	strb r5, [r0]
	movs r0, #0x89
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #1
	strh r0, [r1]
	movs r0, #0x87
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, _08017C40 @ =0x80000001
	str r0, [r1]
	movs r0, #0x88
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, _08017C44 @ =0x7FFFFFFF
	str r0, [r1]
	ldr r0, _08017C48 @ =0x00000211
	adds r1, r4, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _08017C4C @ =0x00000226
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #2
	adds r0, r4, r1
	strh r3, [r0]
	subs r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	bl ReleaseAllStageEntities
	movs r1, #1
	rsbs r1, r1, #0
	adds r3, r4, #0
	adds r0, r3, #0
	adds r0, #0x80
_08017C0A:
	str r1, [r0]
	subs r0, #4
	cmp r0, r4
	bge _08017C0A
	movs r0, #0x85
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, _08017C50 @ =sStageEntityTemplate
	lsls r1, r5, #2
	adds r0, r1, r0
	ldr r0, [r0]
	str r0, [r2]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, _08017C54 @ =sStageEntityTemplateCoord
	adds r1, r1, r0
	ldr r0, [r1]
	str r0, [r2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08017C38: .4byte gStageEntityManager
_08017C3C: .4byte 0x0000020E
_08017C40: .4byte 0x80000001
_08017C44: .4byte 0x7FFFFFFF
_08017C48: .4byte 0x00000211
_08017C4C: .4byte 0x00000226
_08017C50: .4byte sStageEntityTemplate
_08017C54: .4byte sStageEntityTemplateCoord
