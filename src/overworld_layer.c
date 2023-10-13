#include "global.h"
#include "overworld.h"

// ステージのグラフィック情報をbgmapとかオフセットレジスタに反映させる処理

NAKED void FUN_080050b0(struct LayerGraphic *l, struct Coord *c, u32 mapAddr) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x3c\n\
	mov r8, r0\n\
	str r1, [sp]\n\
	str r2, [sp, #4]\n\
	movs r0, #0\n\
	str r0, [sp, #0x18]\n\
	ldr r3, [r1]\n\
	movs r2, #0x10\n\
	adds r1, r3, #0\n\
	ands r1, r2\n\
	mov r7, r8\n\
	ldr r4, [r7]\n\
	adds r0, r4, #0\n\
	ands r0, r2\n\
	cmp r1, r0\n\
	beq _08005106\n\
	cmp r3, r4\n\
	ble _080050F4\n\
	movs r0, #0x88\n\
	lsls r0, r0, #1\n\
	adds r0, r3, r0\n\
	str r0, [sp, #8]\n\
	ldr r1, [sp]\n\
	ldr r0, [r1, #4]\n\
	adds r2, r0, #0\n\
	subs r2, #0x10\n\
	str r2, [sp, #0xc]\n\
	adds r4, r0, #0\n\
	b _0800510E\n\
_080050F4:\n\
	subs r3, #0x20\n\
	str r3, [sp, #8]\n\
	ldr r3, [sp]\n\
	ldr r0, [r3, #4]\n\
	adds r4, r0, #0\n\
	subs r4, #0x10\n\
	str r4, [sp, #0xc]\n\
	adds r4, r0, #0\n\
	b _0800510E\n\
_08005106:\n\
	movs r7, #1\n\
	str r7, [sp, #0x18]\n\
	ldr r0, [sp]\n\
	ldr r4, [r0, #4]\n\
_0800510E:\n\
	adds r3, r4, #0\n\
	movs r2, #0x10\n\
	adds r1, r3, #0\n\
	ands r1, r2\n\
	mov r7, r8\n\
	ldr r5, [r7, #4]\n\
	adds r0, r5, #0\n\
	ands r0, r2\n\
	cmp r1, r0\n\
	beq _08005142\n\
	cmp r3, r5\n\
	ble _08005134\n\
	ldr r1, [sp]\n\
	ldr r0, [r1]\n\
	subs r0, #0x20\n\
	str r0, [sp, #0x10]\n\
	adds r3, #0xb0\n\
	str r3, [sp, #0x14]\n\
	b _0800514A\n\
_08005134:\n\
	ldr r2, [sp]\n\
	ldr r0, [r2]\n\
	subs r0, #0x20\n\
	str r0, [sp, #0x10]\n\
	subs r4, #0x10\n\
	str r4, [sp, #0x14]\n\
	b _0800514A\n\
_08005142:\n\
	movs r0, #2\n\
	ldr r3, [sp, #0x18]\n\
	orrs r3, r0\n\
	str r3, [sp, #0x18]\n\
_0800514A:\n\
	ldr r4, [sp, #8]\n\
	cmp r4, #0\n\
	bge _08005154\n\
	movs r7, #0\n\
	str r7, [sp, #8]\n\
_08005154:\n\
	ldr r0, [sp, #0xc]\n\
	cmp r0, #0\n\
	bge _0800515E\n\
	movs r1, #0\n\
	str r1, [sp, #0xc]\n\
_0800515E:\n\
	ldr r2, [sp, #0x10]\n\
	cmp r2, #0\n\
	bge _08005168\n\
	movs r3, #0\n\
	str r3, [sp, #0x10]\n\
_08005168:\n\
	ldr r4, [sp, #0x14]\n\
	cmp r4, #0\n\
	bge _08005172\n\
	movs r7, #0\n\
	str r7, [sp, #0x14]\n\
_08005172:\n\
	movs r0, #1\n\
	ldr r1, [sp, #0x18]\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0800517E\n\
	b _0800535A\n\
_0800517E:\n\
	ldr r2, [sp, #8]\n\
	mov sl, r2\n\
	adds r0, r2, #0\n\
	movs r1, #0xf0\n\
	bl __divsi3\n\
	adds r4, r0, #0\n\
	adds r4, #4\n\
	mov r3, r8\n\
	ldr r6, [r3, #0x14]\n\
	adds r4, r6, r4\n\
	ldr r5, [sp, #0xc]\n\
	adds r0, r5, #0\n\
	movs r1, #0xa0\n\
	bl __divsi3\n\
	ldrb r1, [r6]\n\
	muls r0, r1, r0\n\
	adds r4, r4, r0\n\
	mov sb, r4\n\
	ldr r0, [sp, #8]\n\
	movs r1, #0xf0\n\
	bl __modsi3\n\
	lsls r0, r0, #0xc\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #0x1c]\n\
	adds r0, r5, #0\n\
	movs r1, #0xa0\n\
	bl __modsi3\n\
	lsls r0, r0, #0xc\n\
	ldrb r2, [r4]\n\
	lsls r1, r2, #2\n\
	adds r1, r1, r2\n\
	lsls r2, r1, #4\n\
	subs r2, r2, r1\n\
	lsls r2, r2, #2\n\
	mov r4, r8\n\
	ldr r3, [r4, #0x10]\n\
	adds r2, r3, r2\n\
	ldr r7, [sp, #0x1c]\n\
	lsls r1, r7, #0x10\n\
	asrs r1, r1, #0xf\n\
	adds r2, r2, r1\n\
	lsrs r1, r0, #0x10\n\
	str r1, [sp, #0x20]\n\
	asrs r0, r0, #0x10\n\
	lsls r1, r0, #4\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #1\n\
	adds r5, r2, r1\n\
	movs r7, #0\n\
	movs r1, #0xa\n\
	subs r1, r1, r0\n\
	str r6, [sp, #0x38]\n\
	str r3, [sp, #0x34]\n\
	cmp r7, r1\n\
	bge _08005250\n\
	mov r2, sp\n\
	ldrh r3, [r2, #0xc]\n\
	strh r3, [r2, #0x24]\n\
	ldr r0, [sp, #8]\n\
	asrs r4, r0, #3\n\
	movs r0, #0x1e\n\
	ands r4, r0\n\
	adds r0, #0xe2\n\
	mov r2, sl\n\
	ands r2, r0\n\
	lsls r2, r2, #3\n\
	mov ip, r2\n\
	mov r3, r8\n\
	ldr r3, [r3, #0xc]\n\
	mov sl, r3\n\
	adds r6, r1, #0\n\
_08005214:\n\
	lsls r2, r7, #0x10\n\
	asrs r2, r2, #0x10\n\
	lsls r0, r2, #4\n\
	mov r7, sp\n\
	ldrh r7, [r7, #0x24]\n\
	adds r0, r7, r0\n\
	ldrh r3, [r5]\n\
	lsls r3, r3, #3\n\
	add r3, sl\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0xe\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #2\n\
	ands r0, r1\n\
	adds r0, r0, r4\n\
	lsls r0, r0, #1\n\
	ldr r1, [sp, #4]\n\
	adds r0, r0, r1\n\
	add r0, ip\n\
	ldr r1, [r3]\n\
	str r1, [r0]\n\
	ldr r1, [r3, #4]\n\
	str r1, [r0, #0x40]\n\
	adds r5, #0x1e\n\
	adds r2, #1\n\
	lsls r2, r2, #0x10\n\
	lsrs r7, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	cmp r2, r6\n\
	blt _08005214\n\
_08005250:\n\
	ldr r2, [sp, #0x38]\n\
	ldrb r0, [r2]\n\
	add sb, r0\n\
	mov r3, sb\n\
	ldrb r0, [r3]\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r0, r1, #4\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r4, [sp, #0x34]\n\
	adds r0, r4, r0\n\
	ldr r1, [sp, #0x1c]\n\
	lsls r2, r1, #0x10\n\
	asrs r1, r2, #0xf\n\
	adds r5, r0, r1\n\
	lsls r3, r7, #0x10\n\
	asrs r0, r3, #0x10\n\
	str r2, [sp, #0x2c]\n\
	cmp r0, #0xc\n\
	bgt _080052E6\n\
	subs r0, #0xa\n\
	ldr r2, [sp, #0x20]\n\
	lsls r6, r2, #0x10\n\
	asrs r1, r6, #0x10\n\
	adds r0, r0, r1\n\
	cmp r0, #9\n\
	bgt _080052E6\n\
	mov r4, sp\n\
	ldrh r4, [r4, #0xc]\n\
	mov ip, r4\n\
	ldr r7, [sp, #8]\n\
	asrs r4, r7, #3\n\
	movs r0, #0x1e\n\
	ands r4, r0\n\
	adds r0, #0xe2\n\
	adds r1, r7, #0\n\
	ands r0, r1\n\
	lsls r0, r0, #3\n\
	mov sl, r0\n\
_080052A0:\n\
	asrs r3, r3, #0x10\n\
	lsls r0, r3, #4\n\
	add r0, ip\n\
	ldrh r1, [r5]\n\
	lsls r1, r1, #3\n\
	mov r7, r8\n\
	ldr r2, [r7, #0xc]\n\
	adds r2, r2, r1\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0xe\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #2\n\
	ands r0, r1\n\
	adds r0, r0, r4\n\
	lsls r0, r0, #1\n\
	ldr r1, [sp, #4]\n\
	adds r0, r0, r1\n\
	add r0, sl\n\
	ldr r1, [r2]\n\
	str r1, [r0]\n\
	ldr r1, [r2, #4]\n\
	str r1, [r0, #0x40]\n\
	adds r5, #0x1e\n\
	adds r3, #1\n\
	lsls r3, r3, #0x10\n\
	lsrs r7, r3, #0x10\n\
	lsls r3, r7, #0x10\n\
	asrs r0, r3, #0x10\n\
	cmp r0, #0xc\n\
	bgt _080052E6\n\
	subs r0, #0xa\n\
	asrs r1, r6, #0x10\n\
	adds r0, r0, r1\n\
	cmp r0, #9\n\
	ble _080052A0\n\
_080052E6:\n\
	ldr r2, [sp, #0x38]\n\
	ldrb r0, [r2]\n\
	add sb, r0\n\
	mov r3, sb\n\
	ldrb r0, [r3]\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r0, r1, #4\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r4, [sp, #0x34]\n\
	adds r0, r4, r0\n\
	ldr r2, [sp, #0x2c]\n\
	asrs r1, r2, #0xf\n\
	adds r5, r0, r1\n\
	lsls r2, r7, #0x10\n\
	asrs r0, r2, #0x10\n\
	cmp r0, #0xc\n\
	bgt _0800535A\n\
	mov r3, sp\n\
	ldrh r3, [r3, #0xc]\n\
	mov sb, r3\n\
	ldr r7, [sp, #8]\n\
	asrs r4, r7, #3\n\
	movs r0, #0x1e\n\
	ands r4, r0\n\
	adds r0, #0xe2\n\
	adds r1, r7, #0\n\
	ands r0, r1\n\
	lsls r7, r0, #3\n\
	mov r3, r8\n\
	ldr r6, [r3, #0xc]\n\
_08005326:\n\
	asrs r3, r2, #0x10\n\
	lsls r0, r3, #4\n\
	add r0, sb\n\
	ldrh r2, [r5]\n\
	lsls r2, r2, #3\n\
	adds r2, r6, r2\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0xe\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #2\n\
	ands r0, r1\n\
	adds r0, r0, r4\n\
	lsls r0, r0, #1\n\
	ldr r1, [sp, #4]\n\
	adds r0, r0, r1\n\
	adds r0, r7, r0\n\
	ldr r1, [r2]\n\
	str r1, [r0]\n\
	ldr r1, [r2, #4]\n\
	str r1, [r0, #0x40]\n\
	adds r5, #0x1e\n\
	adds r3, #1\n\
	lsls r2, r3, #0x10\n\
	asrs r0, r2, #0x10\n\
	cmp r0, #0xc\n\
	ble _08005326\n\
_0800535A:\n\
	movs r0, #2\n\
	ldr r2, [sp, #0x18]\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	beq _08005366\n\
	b _08005554\n\
_08005366:\n\
	ldr r0, [sp, #0x10]\n\
	movs r1, #0xf0\n\
	bl __divsi3\n\
	adds r4, r0, #0\n\
	adds r4, #4\n\
	mov r3, r8\n\
	ldr r5, [r3, #0x14]\n\
	adds r4, r5, r4\n\
	ldr r6, [sp, #0x14]\n\
	adds r0, r6, #0\n\
	movs r1, #0xa0\n\
	bl __divsi3\n\
	ldrb r1, [r5]\n\
	muls r0, r1, r0\n\
	adds r4, r4, r0\n\
	mov sb, r4\n\
	ldr r0, [sp, #0x10]\n\
	movs r1, #0xf0\n\
	bl __modsi3\n\
	lsls r0, r0, #0xc\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #0x1c]\n\
	adds r0, r6, #0\n\
	movs r1, #0xa0\n\
	bl __modsi3\n\
	lsls r0, r0, #0xc\n\
	ldrb r2, [r4]\n\
	lsls r1, r2, #2\n\
	adds r1, r1, r2\n\
	lsls r2, r1, #4\n\
	subs r2, r2, r1\n\
	lsls r2, r2, #2\n\
	mov r7, r8\n\
	ldr r4, [r7, #0x10]\n\
	adds r2, r4, r2\n\
	ldr r1, [sp, #0x1c]\n\
	lsls r3, r1, #0x10\n\
	asrs r3, r3, #0x10\n\
	lsls r1, r3, #1\n\
	adds r2, r2, r1\n\
	lsrs r7, r0, #0x10\n\
	str r7, [sp, #0x20]\n\
	asrs r0, r0, #0x10\n\
	lsls r1, r0, #4\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #1\n\
	adds r5, r2, r1\n\
	movs r7, #0\n\
	movs r0, #0xf\n\
	subs r1, r0, r3\n\
	str r4, [sp, #0x34]\n\
	cmp r7, r1\n\
	bge _08005436\n\
	mov r0, sp\n\
	ldrh r2, [r0, #0x10]\n\
	strh r2, [r0, #0x28]\n\
	ldr r3, [sp, #0x14]\n\
	lsls r6, r3, #2\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #2\n\
	ands r6, r0\n\
	mov r4, r8\n\
	ldr r4, [r4, #0xc]\n\
	mov ip, r4\n\
	mov sl, r1\n\
_080053F0:\n\
	lsls r3, r7, #0x10\n\
	asrs r3, r3, #0x10\n\
	lsls r2, r3, #4\n\
	mov r7, sp\n\
	ldrh r7, [r7, #0x28]\n\
	adds r2, r7, r2\n\
	ldrh r4, [r5]\n\
	lsls r4, r4, #3\n\
	add r4, ip\n\
	lsls r2, r2, #0x10\n\
	asrs r1, r2, #0x13\n\
	movs r0, #0x1e\n\
	ands r1, r0\n\
	adds r1, r6, r1\n\
	movs r7, #0x80\n\
	lsls r7, r7, #1\n\
	lsls r0, r7, #0x10\n\
	ands r0, r2\n\
	asrs r0, r0, #0x10\n\
	lsls r0, r0, #3\n\
	lsls r1, r1, #1\n\
	ldr r2, [sp, #4]\n\
	adds r1, r1, r2\n\
	adds r0, r0, r1\n\
	ldr r1, [r4]\n\
	str r1, [r0]\n\
	ldr r1, [r4, #4]\n\
	str r1, [r0, #0x40]\n\
	adds r5, #2\n\
	adds r3, #1\n\
	lsls r3, r3, #0x10\n\
	lsrs r7, r3, #0x10\n\
	asrs r3, r3, #0x10\n\
	cmp r3, sl\n\
	blt _080053F0\n\
_08005436:\n\
	movs r3, #1\n\
	add sb, r3\n\
	mov r4, sb\n\
	ldrb r1, [r4]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r1, r0, #4\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #2\n\
	ldr r0, [sp, #0x34]\n\
	adds r1, r0, r1\n\
	ldr r2, [sp, #0x20]\n\
	lsls r3, r2, #0x10\n\
	asrs r2, r3, #0x10\n\
	lsls r0, r2, #4\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #1\n\
	adds r5, r1, r0\n\
	lsls r4, r7, #0x10\n\
	asrs r0, r4, #0x10\n\
	str r3, [sp, #0x30]\n\
	cmp r0, #0x13\n\
	bgt _080054D6\n\
	subs r0, #0xf\n\
	ldr r3, [sp, #0x1c]\n\
	lsls r3, r3, #0x10\n\
	mov ip, r3\n\
	asrs r1, r3, #0x10\n\
	adds r0, r0, r1\n\
	cmp r0, #0xe\n\
	bgt _080054D6\n\
	mov r7, sp\n\
	ldrh r7, [r7, #0x10]\n\
	mov sl, r7\n\
	ldr r0, [sp, #0x14]\n\
	lsls r6, r0, #2\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #2\n\
	ands r6, r0\n\
_08005484:\n\
	asrs r4, r4, #0x10\n\
	lsls r2, r4, #4\n\
	add r2, sl\n\
	ldrh r0, [r5]\n\
	lsls r0, r0, #3\n\
	mov r1, r8\n\
	ldr r3, [r1, #0xc]\n\
	adds r3, r3, r0\n\
	lsls r2, r2, #0x10\n\
	asrs r1, r2, #0x13\n\
	movs r0, #0x1e\n\
	ands r1, r0\n\
	adds r1, r6, r1\n\
	movs r7, #0x80\n\
	lsls r7, r7, #1\n\
	lsls r0, r7, #0x10\n\
	ands r0, r2\n\
	asrs r0, r0, #0x10\n\
	lsls r0, r0, #3\n\
	lsls r1, r1, #1\n\
	ldr r2, [sp, #4]\n\
	adds r1, r1, r2\n\
	adds r0, r0, r1\n\
	ldr r1, [r3]\n\
	str r1, [r0]\n\
	ldr r1, [r3, #4]\n\
	str r1, [r0, #0x40]\n\
	adds r5, #2\n\
	adds r4, #1\n\
	lsls r4, r4, #0x10\n\
	lsrs r7, r4, #0x10\n\
	lsls r4, r7, #0x10\n\
	asrs r0, r4, #0x10\n\
	cmp r0, #0x13\n\
	bgt _080054D6\n\
	subs r0, #0xf\n\
	mov r3, ip\n\
	asrs r1, r3, #0x10\n\
	adds r0, r0, r1\n\
	cmp r0, #0xe\n\
	ble _08005484\n\
_080054D6:\n\
	mov r4, sb\n\
	ldrb r1, [r4, #1]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r1, r0, #4\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #2\n\
	ldr r0, [sp, #0x34]\n\
	adds r1, r0, r1\n\
	ldr r3, [sp, #0x30]\n\
	asrs r2, r3, #0x10\n\
	lsls r0, r2, #4\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #1\n\
	adds r5, r1, r0\n\
	lsls r2, r7, #0x10\n\
	asrs r0, r2, #0x10\n\
	cmp r0, #0x13\n\
	bgt _08005554\n\
	mov r4, sp\n\
	ldrh r4, [r4, #0x10]\n\
	mov sb, r4\n\
	ldr r7, [sp, #0x14]\n\
	lsls r6, r7, #2\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #2\n\
	ands r6, r0\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	mov sl, r0\n\
	mov r1, r8\n\
	ldr r1, [r1, #0xc]\n\
	mov ip, r1\n\
_08005518:\n\
	asrs r4, r2, #0x10\n\
	lsls r2, r4, #4\n\
	add r2, sb\n\
	ldrh r3, [r5]\n\
	lsls r3, r3, #3\n\
	add r3, ip\n\
	lsls r2, r2, #0x10\n\
	asrs r1, r2, #0x13\n\
	movs r0, #0x1e\n\
	ands r1, r0\n\
	adds r1, r6, r1\n\
	mov r7, sl\n\
	lsls r0, r7, #0x10\n\
	ands r0, r2\n\
	asrs r0, r0, #0x10\n\
	lsls r0, r0, #3\n\
	lsls r1, r1, #1\n\
	ldr r2, [sp, #4]\n\
	adds r1, r1, r2\n\
	adds r0, r0, r1\n\
	ldr r1, [r3]\n\
	str r1, [r0]\n\
	ldr r1, [r3, #4]\n\
	str r1, [r0, #0x40]\n\
	adds r5, #2\n\
	adds r4, #1\n\
	lsls r2, r4, #0x10\n\
	asrs r0, r2, #0x10\n\
	cmp r0, #0x13\n\
	ble _08005518\n\
_08005554:\n\
	ldr r4, [sp]\n\
	ldr r3, [r4]\n\
	ldr r2, _08005580 @ =0x000001FF\n\
	adds r0, r3, #0\n\
	ands r0, r2\n\
	mov r7, r8\n\
	strh r0, [r7, #8]\n\
	ldr r1, [r4, #4]\n\
	adds r0, r1, #0\n\
	ands r0, r2\n\
	strh r0, [r7, #0xa]\n\
	str r3, [r7]\n\
	str r1, [r7, #4]\n\
	add sp, #0x3c\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08005580: .4byte 0x000001FF\n\
 .syntax divided\n");
}

#if MODERN == 0
NAKED static void unused_08005584(struct LayerGraphic *r0, struct Coord *c, u32 mapAddr) { INCCODE("asm/unused/unused_08005584.inc"); }
NAKED static void unused_080055e8(struct LayerGraphic *r0, struct Coord *c, u32 mapAddr) { INCCODE("asm/unused/unused_080055e8.inc"); }
NAKED static void unused_08005674(struct LayerGraphic *r0, struct Coord *c, u32 mapAddr) { INCCODE("asm/unused/unused_08005674.inc"); }
#endif

NAKED void FUN_08005a70(struct LayerGraphic *l, struct Coord *c, u32 mapAddr) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x44\n\
	str r0, [sp]\n\
	str r1, [sp, #4]\n\
	str r2, [sp, #8]\n\
	ldr r0, [r1]\n\
	ldr r1, [r1, #4]\n\
	str r0, [sp, #0x10]\n\
	str r1, [sp, #0x14]\n\
	ldr r2, [sp, #4]\n\
	ldr r0, [r2]\n\
	subs r0, #0x20\n\
	cmp r0, #0\n\
	ble _08005A98\n\
	str r0, [sp, #0x10]\n\
	b _08005A9C\n\
_08005A98:\n\
	movs r3, #0\n\
	str r3, [sp, #0x10]\n\
_08005A9C:\n\
	ldr r1, [sp, #4]\n\
	ldr r0, [r1, #4]\n\
	subs r0, #0x10\n\
	cmp r0, #0\n\
	ble _08005AAA\n\
	str r0, [sp, #0x14]\n\
	b _08005AAE\n\
_08005AAA:\n\
	movs r2, #0\n\
	str r2, [sp, #0x14]\n\
_08005AAE:\n\
	ldr r0, [sp, #0x10]\n\
	movs r1, #0xf0\n\
	bl __divsi3\n\
	adds r4, r0, #0\n\
	adds r4, #4\n\
	ldr r3, [sp]\n\
	ldr r6, [r3, #0x14]\n\
	adds r4, r6, r4\n\
	ldr r5, [sp, #0x14]\n\
	adds r0, r5, #0\n\
	movs r1, #0xa0\n\
	bl __divsi3\n\
	ldrb r1, [r6]\n\
	muls r0, r1, r0\n\
	adds r4, r4, r0\n\
	str r4, [sp, #0xc]\n\
	ldr r0, [sp, #0x10]\n\
	movs r1, #0xf0\n\
	bl __modsi3\n\
	adds r4, r0, #0\n\
	lsls r4, r4, #0xc\n\
	lsrs r4, r4, #0x10\n\
	adds r0, r5, #0\n\
	movs r1, #0xa0\n\
	bl __modsi3\n\
	lsls r0, r0, #0xc\n\
	ldr r1, [sp, #0xc]\n\
	ldrb r2, [r1]\n\
	lsls r1, r2, #2\n\
	adds r1, r1, r2\n\
	lsls r2, r1, #4\n\
	subs r2, r2, r1\n\
	lsls r2, r2, #2\n\
	ldr r1, [sp]\n\
	ldr r3, [r1, #0x10]\n\
	adds r2, r3, r2\n\
	lsls r4, r4, #0x10\n\
	asrs r4, r4, #0x10\n\
	lsls r5, r4, #1\n\
	adds r2, r2, r5\n\
	asrs r0, r0, #0x10\n\
	lsls r1, r0, #4\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #1\n\
	adds r7, r2, r1\n\
	movs r2, #0\n\
	mov r8, r2\n\
	movs r1, #0\n\
	str r1, [sp, #0x18]\n\
	mov ip, r1\n\
	str r6, [sp, #0x40]\n\
	str r3, [sp, #0x3c]\n\
	str r0, [sp, #0x20]\n\
	movs r0, #0xa\n\
	ldr r3, [sp, #0x20]\n\
	subs r0, r0, r3\n\
	str r0, [sp, #0x24]\n\
	str r4, [sp, #0x28]\n\
	str r5, [sp, #0x1c]\n\
	movs r0, #0xf\n\
	subs r0, r0, r4\n\
	str r0, [sp, #0x2c]\n\
_08005B32:\n\
	movs r1, #0\n\
	mov r3, r8\n\
	lsls r3, r3, #0x10\n\
	str r3, [sp, #0x34]\n\
	lsls r2, r2, #0x10\n\
	str r2, [sp, #0x38]\n\
	asrs r2, r2, #0x10\n\
	mov sb, r2\n\
_08005B42:\n\
	ldr r0, [sp, #0x34]\n\
	lsrs r6, r0, #0x10\n\
	lsls r1, r1, #0x10\n\
	mov r8, r1\n\
	mov r1, sb\n\
	cmp r1, #0\n\
	bne _08005B60\n\
	lsls r0, r6, #0x10\n\
	asrs r1, r0, #0x10\n\
	adds r2, r0, #0\n\
	ldr r3, [sp, #0x24]\n\
	cmp r1, r3\n\
	blt _08005B5E\n\
	b _08005C6E\n\
_08005B5E:\n\
	b _08005B88\n\
_08005B60:\n\
	mov r0, sb\n\
	cmp r0, #1\n\
	bne _08005B7E\n\
	lsls r0, r6, #0x10\n\
	asrs r1, r0, #0x10\n\
	adds r2, r0, #0\n\
	cmp r1, #0xc\n\
	bgt _08005C6E\n\
	adds r0, r1, #0\n\
	subs r0, #0xa\n\
	ldr r1, [sp, #0x20]\n\
	adds r0, r0, r1\n\
	cmp r0, #9\n\
	bgt _08005C6E\n\
	b _08005B88\n\
_08005B7E:\n\
	lsls r0, r6, #0x10\n\
	asrs r1, r0, #0x10\n\
	adds r2, r0, #0\n\
	cmp r1, #0xc\n\
	bgt _08005C6E\n\
_08005B88:\n\
	asrs r0, r2, #0xc\n\
	ldr r2, [sp, #0x14]\n\
	adds r0, r2, r0\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	mov sl, r0\n\
	ldr r3, [sp, #0x18]\n\
	lsls r0, r3, #0x10\n\
	lsrs r1, r0, #0x10\n\
	mov ip, r1\n\
	str r0, [sp, #0x30]\n\
	mov r2, r8\n\
	cmp r2, #0\n\
	bne _08005BB0\n\
	lsls r0, r1, #0x10\n\
	asrs r0, r0, #0x10\n\
	ldr r3, [sp, #0x2c]\n\
	cmp r0, r3\n\
	bge _08005C3C\n\
	b _08005BD8\n\
_08005BB0:\n\
	mov r1, r8\n\
	asrs r0, r1, #0x10\n\
	cmp r0, #1\n\
	bne _08005BCE\n\
	mov r2, ip\n\
	lsls r0, r2, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0x13\n\
	bgt _08005C3C\n\
	subs r0, #0xf\n\
	ldr r3, [sp, #0x28]\n\
	adds r0, r0, r3\n\
	cmp r0, #0xe\n\
	bgt _08005C3C\n\
	b _08005BD8\n\
_08005BCE:\n\
	mov r1, ip\n\
	lsls r0, r1, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0x13\n\
	bgt _08005C3C\n\
_08005BD8:\n\
	mov r2, ip\n\
	lsls r4, r2, #0x10\n\
	asrs r4, r4, #0x10\n\
	lsls r2, r4, #4\n\
	ldr r3, [sp, #0x10]\n\
	adds r2, r3, r2\n\
	ldrh r0, [r7]\n\
	lsls r0, r0, #3\n\
	ldr r1, [sp]\n\
	ldr r5, [r1, #0xc]\n\
	adds r5, r5, r0\n\
	mov r0, sl\n\
	lsls r3, r0, #0x10\n\
	asrs r3, r3, #0xe\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #2\n\
	ands r3, r0\n\
	lsls r2, r2, #0x10\n\
	asrs r1, r2, #0x10\n\
	asrs r2, r2, #0x13\n\
	movs r0, #0x1e\n\
	ands r2, r0\n\
	adds r3, r3, r2\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	ands r1, r0\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	lsls r1, r1, #3\n\
	lsls r3, r3, #1\n\
	ldr r2, [sp, #8]\n\
	adds r3, r3, r2\n\
	adds r1, r1, r3\n\
	ldr r0, [r5]\n\
	str r0, [r1]\n\
	ldr r0, [r5, #4]\n\
	str r0, [r1, #0x40]\n\
	adds r7, #2\n\
	adds r4, #1\n\
	lsls r4, r4, #0x10\n\
	lsrs r4, r4, #0x10\n\
	mov ip, r4\n\
	mov r3, r8\n\
	cmp r3, #0\n\
	bne _08005BB0\n\
	lsls r0, r4, #0x10\n\
	asrs r0, r0, #0x10\n\
	ldr r1, [sp, #0x2c]\n\
	cmp r0, r1\n\
	blt _08005BD8\n\
_08005C3C:\n\
	mov r2, ip\n\
	lsls r0, r2, #0x10\n\
	asrs r0, r0, #0x10\n\
	ldr r3, [sp, #0x30]\n\
	asrs r1, r3, #0x10\n\
	subs r0, r0, r1\n\
	movs r1, #0xf\n\
	subs r0, r1, r0\n\
	lsls r0, r0, #1\n\
	adds r7, r7, r0\n\
	lsls r0, r6, #0x10\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r0, r0, r2\n\
	lsrs r6, r0, #0x10\n\
	mov r3, sb\n\
	cmp r3, #0\n\
	beq _08005C62\n\
	b _08005B60\n\
_08005C62:\n\
	lsls r0, r6, #0x10\n\
	asrs r1, r0, #0x10\n\
	adds r2, r0, #0\n\
	ldr r0, [sp, #0x24]\n\
	cmp r1, r0\n\
	blt _08005B88\n\
_08005C6E:\n\
	mov r1, ip\n\
	str r1, [sp, #0x18]\n\
	mov r3, r8\n\
	asrs r0, r3, #0x10\n\
	cmp r0, #2\n\
	beq _08005CC4\n\
	ldr r0, [sp, #0xc]\n\
	adds r0, #1\n\
	str r0, [sp, #0xc]\n\
	mov r1, sb\n\
	cmp r1, #0\n\
	bne _08005CA2\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r1, r0, #4\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #2\n\
	ldr r3, [sp, #0x3c]\n\
	adds r1, r3, r1\n\
	ldr r3, [sp, #0x20]\n\
	lsls r0, r3, #4\n\
	subs r0, r0, r3\n\
	lsls r0, r0, #1\n\
	adds r7, r1, r0\n\
	b _08005CB4\n\
_08005CA2:\n\
	ldr r1, [sp, #0xc]\n\
	ldrb r0, [r1]\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r0, r1, #4\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r3, [sp, #0x3c]\n\
	adds r7, r3, r0\n\
_08005CB4:\n\
	movs r0, #0x80\n\
	lsls r0, r0, #9\n\
	add r0, r8\n\
	lsrs r1, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #2\n\
	bgt _08005CC4\n\
	b _08005B42\n\
_08005CC4:\n\
	ldr r0, [sp, #0x38]\n\
	asrs r3, r0, #0x10\n\
	cmp r3, #2\n\
	beq _08005D02\n\
	ldr r1, [sp, #0x40]\n\
	ldrb r0, [r1]\n\
	ldr r1, [sp, #0xc]\n\
	adds r0, r1, r0\n\
	subs r0, #2\n\
	str r0, [sp, #0xc]\n\
	ldrb r0, [r0]\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r0, r1, #4\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r1, [sp, #0x3c]\n\
	adds r0, r1, r0\n\
	ldr r1, [sp, #0x1c]\n\
	adds r7, r0, r1\n\
	lsrs r2, r2, #0x10\n\
	mov r8, r2\n\
	movs r2, #0\n\
	str r2, [sp, #0x18]\n\
	adds r0, r3, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #2\n\
	bgt _08005D02\n\
	b _08005B32\n\
_08005D02:\n\
	ldr r0, [sp, #4]\n\
	ldr r3, [r0]\n\
	ldr r2, _08005D30 @ =0x000001FF\n\
	adds r0, r3, #0\n\
	ands r0, r2\n\
	ldr r1, [sp]\n\
	strh r0, [r1, #8]\n\
	ldr r0, [sp, #4]\n\
	ldr r1, [r0, #4]\n\
	adds r0, r1, #0\n\
	ands r0, r2\n\
	ldr r2, [sp]\n\
	strh r0, [r2, #0xa]\n\
	str r3, [r2]\n\
	str r1, [r2, #4]\n\
	add sp, #0x44\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08005D30: .4byte 0x000001FF\n\
 .syntax divided\n");
}

#if MODERN == 0
NAKED static void unused_08005d34(void) { INCCODE("asm/unused/unused_08005d34.inc"); }
NAKED static void unused_080061a4(void) { INCCODE("asm/unused/unused_080061a4.inc"); }
NAKED static void unused_08006474(void) { INCCODE("asm/unused/unused_08006474.inc"); }
NAKED static void unused_08006738(void) { INCCODE("asm/unused/unused_08006738.inc"); }
NAKED static void unused_080069e0(void) { INCCODE("asm/unused/unused_080069e0.inc"); }
#endif

NAKED void FUN_08006a10(struct LayerGraphic *r0, struct Coord *c, u16 *map, metatile_id_t *bm) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #8\n\
	mov sl, r0\n\
	mov sb, r1\n\
	str r2, [sp]\n\
	ldr r1, [r1]\n\
	asrs r1, r1, #4\n\
	adds r5, r1, #0\n\
	mov r2, sb\n\
	ldr r0, [r2, #4]\n\
	asrs r6, r0, #4\n\
	lsls r1, r1, #1\n\
	adds r1, #4\n\
	adds r1, r3, r1\n\
	ldrh r2, [r3]\n\
	adds r0, r2, #0\n\
	muls r0, r6, r0\n\
	lsls r0, r0, #1\n\
	adds r4, r1, r0\n\
	movs r1, #0\n\
	mov r3, sl\n\
	ldr r3, [r3, #0xc]\n\
	mov ip, r3\n\
	lsls r2, r2, #1\n\
	str r2, [sp, #4]\n\
_08006A4A:\n\
	lsls r1, r1, #0x10\n\
	asrs r0, r1, #0x10\n\
	adds r0, r0, r6\n\
	movs r2, #0xf\n\
	ands r0, r2\n\
	lsls r0, r0, #7\n\
	ldr r3, [sp]\n\
	adds r7, r3, r0\n\
	movs r0, #0\n\
	mov r8, r1\n\
_08006A5E:\n\
	lsls r3, r0, #0x10\n\
	asrs r3, r3, #0x10\n\
	adds r1, r3, r5\n\
	adds r2, r1, #0\n\
	movs r0, #0xf\n\
	ands r2, r0\n\
	lsls r2, r2, #2\n\
	adds r2, r7, r2\n\
	movs r0, #0x10\n\
	ands r1, r0\n\
	lsls r1, r1, #7\n\
	adds r2, r2, r1\n\
	ldrh r0, [r4]\n\
	lsls r0, r0, #3\n\
	add r0, ip\n\
	ldr r0, [r0]\n\
	str r0, [r2]\n\
	ldrh r0, [r4]\n\
	lsls r0, r0, #3\n\
	add r0, ip\n\
	ldr r0, [r0, #4]\n\
	str r0, [r2, #0x40]\n\
	adds r4, #2\n\
	adds r3, #1\n\
	lsls r3, r3, #0x10\n\
	lsrs r0, r3, #0x10\n\
	asrs r3, r3, #0x10\n\
	cmp r3, #0xf\n\
	ble _08006A5E\n\
	ldr r1, [sp, #4]\n\
	adds r0, r4, r1\n\
	adds r4, r0, #0\n\
	subs r4, #0x20\n\
	movs r0, #0x80\n\
	lsls r0, r0, #9\n\
	add r0, r8\n\
	lsrs r1, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0xa\n\
	ble _08006A4A\n\
	mov r2, sb\n\
	ldr r3, [r2]\n\
	ldr r2, _08006ADC @ =0x000001FF\n\
	adds r0, r3, #0\n\
	ands r0, r2\n\
	mov r1, sl\n\
	strh r0, [r1, #8]\n\
	mov r0, sb\n\
	ldr r1, [r0, #4]\n\
	adds r0, r1, #0\n\
	ands r0, r2\n\
	mov r2, sl\n\
	strh r0, [r2, #0xa]\n\
	str r3, [r2]\n\
	str r1, [r2, #4]\n\
	add sp, #8\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08006ADC: .4byte 0x000001FF\n\
 .syntax divided\n");
}

// bgmap.c　の処理を知るためにとりあえずCにしたもの、多分ロジックおかしなっとる
WIP void FUN_08006ae0(struct LayerGraphic *l, struct Coord *c, u32 *bgmap, struct MetatileMap *mm) {
#if MODERN
  s16 i;
  s32 x = c->x >> 4;
  s32 y = c->y >> 4;
  metatile_id_t *id = &mm->map[y * mm->width + x];
  for (i = 0; i < 12; i++) {
    s16 X = x + i;
    while (X < 18) {
      s32 Y = (y & 0xF) + i;
      Metatile *mt = &l->tiledata[*id];
      bgmap[(Y + (X & 0x10)) * 32 + (X & 0xF)] = *(u32 *)&((*mt)[0]);
      bgmap[(Y + (X & 0x10)) * 32 + (X & 0xF) + 16] = *(u32 *)&((*mt)[2]);
      id++;
      X++;
    }
    id += (mm->width - 18);
  }
  l->bgofs[0] = c->x & 0x1FF;
  l->bgofs[1] = c->y & 0x1FF;
  (l->c).x = c->x;
  (l->c).y = c->y;
#else
  INCCODE("asm/wip/FUN_08006ae0.inc");
#endif
}

NAKED void FUN_08006bb4(struct LayerGraphic *l, struct Coord *c, u32 *bgmap, struct MetatileMap *mm) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x14\n\
	mov r8, r0\n\
	str r1, [sp]\n\
	str r2, [sp, #4]\n\
	mov sl, r3\n\
	movs r0, #0\n\
	mov sb, r0\n\
	ldr r3, [r1]\n\
	movs r2, #0x10\n\
	adds r1, r3, #0\n\
	ands r1, r2\n\
	mov r7, r8\n\
	ldr r4, [r7]\n\
	adds r0, r4, #0\n\
	ands r0, r2\n\
	cmp r1, r0\n\
	beq _08006BF8\n\
	cmp r3, r4\n\
	ble _08006BEC\n\
	adds r0, r3, #0\n\
	adds r0, #0xf0\n\
	asrs r5, r0, #4\n\
	b _08006BEE\n\
_08006BEC:\n\
	asrs r5, r3, #4\n\
_08006BEE:\n\
	ldr r1, [sp]\n\
	ldr r0, [r1, #4]\n\
	asrs r6, r0, #4\n\
	adds r4, r0, #0\n\
	b _08006C00\n\
_08006BF8:\n\
	movs r2, #1\n\
	mov sb, r2\n\
	ldr r7, [sp]\n\
	ldr r4, [r7, #4]\n\
_08006C00:\n\
	adds r3, r4, #0\n\
	movs r2, #0x10\n\
	adds r1, r3, #0\n\
	ands r1, r2\n\
	mov r0, r8\n\
	ldr r7, [r0, #4]\n\
	adds r0, r7, #0\n\
	ands r0, r2\n\
	cmp r1, r0\n\
	beq _08006C30\n\
	cmp r3, r7\n\
	ble _08006C22\n\
	adds r0, r3, #0\n\
	adds r0, #0xa0\n\
	asrs r0, r0, #4\n\
	str r0, [sp, #0xc]\n\
	b _08006C26\n\
_08006C22:\n\
	asrs r4, r4, #4\n\
	str r4, [sp, #0xc]\n\
_08006C26:\n\
	ldr r1, [sp]\n\
	ldr r0, [r1]\n\
	asrs r0, r0, #4\n\
	str r0, [sp, #8]\n\
	b _08006C38\n\
_08006C30:\n\
	movs r0, #2\n\
	mov r2, sb\n\
	orrs r2, r0\n\
	mov sb, r2\n\
_08006C38:\n\
	movs r0, #1\n\
	mov r7, sb\n\
	ands r0, r7\n\
	cmp r0, #0\n\
	bne _08006CA8\n\
	adds r2, r5, #0\n\
	lsls r1, r2, #1\n\
	adds r1, #4\n\
	add r1, sl\n\
	mov r0, sl\n\
	ldrh r3, [r0]\n\
	adds r0, r3, #0\n\
	muls r0, r6, r0\n\
	lsls r0, r0, #1\n\
	adds r4, r1, r0\n\
	movs r0, #0xf\n\
	ands r0, r2\n\
	lsls r0, r0, #2\n\
	ldr r1, [sp, #4]\n\
	adds r0, r1, r0\n\
	movs r1, #0x10\n\
	ands r2, r1\n\
	lsls r2, r2, #7\n\
	adds r0, r0, r2\n\
	mov ip, r0\n\
	movs r0, #0\n\
	mov r2, r8\n\
	ldr r2, [r2, #0xc]\n\
	str r2, [sp, #0x10]\n\
	lsls r3, r3, #1\n\
_08006C74:\n\
	lsls r2, r0, #0x10\n\
	asrs r2, r2, #0x10\n\
	adds r0, r2, r6\n\
	movs r1, #0xf\n\
	ands r0, r1\n\
	lsls r0, r0, #7\n\
	mov r7, ip\n\
	adds r1, r7, r0\n\
	ldrh r0, [r4]\n\
	lsls r0, r0, #3\n\
	ldr r7, [sp, #0x10]\n\
	adds r0, r0, r7\n\
	ldr r0, [r0]\n\
	str r0, [r1]\n\
	ldrh r0, [r4]\n\
	lsls r0, r0, #3\n\
	adds r0, r0, r7\n\
	ldr r0, [r0, #4]\n\
	str r0, [r1, #0x40]\n\
	adds r4, r4, r3\n\
	adds r2, #1\n\
	lsls r2, r2, #0x10\n\
	lsrs r0, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	cmp r2, #0xa\n\
	ble _08006C74\n\
_08006CA8:\n\
	movs r0, #2\n\
	mov r1, sb\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	bne _08006D12\n\
	ldr r2, [sp, #8]\n\
	lsls r1, r2, #1\n\
	adds r1, #4\n\
	add r1, sl\n\
	mov r7, sl\n\
	ldrh r0, [r7]\n\
	ldr r2, [sp, #0xc]\n\
	muls r0, r2, r0\n\
	lsls r0, r0, #1\n\
	adds r4, r1, r0\n\
	movs r0, #0xf\n\
	ands r0, r2\n\
	lsls r0, r0, #7\n\
	ldr r7, [sp, #4]\n\
	adds r7, r7, r0\n\
	mov ip, r7\n\
	movs r0, #0\n\
	mov r1, r8\n\
	ldr r5, [r1, #0xc]\n\
_08006CD8:\n\
	lsls r3, r0, #0x10\n\
	asrs r3, r3, #0x10\n\
	ldr r7, [sp, #8]\n\
	adds r2, r3, r7\n\
	movs r0, #0xf\n\
	ands r0, r2\n\
	lsls r0, r0, #2\n\
	add r0, ip\n\
	movs r1, #0x10\n\
	ands r2, r1\n\
	lsls r2, r2, #7\n\
	adds r1, r0, r2\n\
	ldrh r0, [r4]\n\
	lsls r0, r0, #3\n\
	adds r0, r0, r5\n\
	ldr r0, [r0]\n\
	str r0, [r1]\n\
	ldrh r0, [r4]\n\
	lsls r0, r0, #3\n\
	adds r0, r0, r5\n\
	ldr r0, [r0, #4]\n\
	str r0, [r1, #0x40]\n\
	adds r4, #2\n\
	adds r3, #1\n\
	lsls r3, r3, #0x10\n\
	lsrs r0, r3, #0x10\n\
	asrs r3, r3, #0x10\n\
	cmp r3, #0xf\n\
	ble _08006CD8\n\
_08006D12:\n\
	ldr r0, [sp]\n\
	ldr r3, [r0]\n\
	ldr r2, _08006D40 @ =0x000001FF\n\
	adds r0, r3, #0\n\
	ands r0, r2\n\
	mov r1, r8\n\
	strh r0, [r1, #8]\n\
	ldr r7, [sp]\n\
	ldr r1, [r7, #4]\n\
	adds r0, r1, #0\n\
	ands r0, r2\n\
	mov r2, r8\n\
	strh r0, [r2, #0xa]\n\
	str r3, [r2]\n\
	str r1, [r2, #4]\n\
	add sp, #0x14\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08006D40: .4byte 0x000001FF\n\
 .syntax divided\n");
}

#if MODERN == 0
static void unused_Clear2KB(u32 *dst) {  // dstから2048バイトを0クリア
  CpuFastFill(0, dst, 2048);
  { vu32 _; }
}
#endif

#if MODERN == 0
static void unused_FastCopy(void *dst, const void *src, u32 bytesize) {  // CpuFastSetとCpuSetを組み合わせて細かい単位でも高速にコピー
  u32 n = (bytesize & 0xFFFFFFE0);
  CpuFastCopy(src, dst, n);

  if ((bytesize & 0x1F) != 0) {
    CpuCopy32(src + n, dst + n, bytesize & 0x1F);
  }
}
#endif

void UpdateBGOFS(struct LayerGraphic *l, struct BgOfs *bgofs) {
  bgofs->x = l->bgofs[0];
  bgofs->y = l->bgofs[1];
}

/*
  引数の例:
    バイル研究所のとき
      r1 = 0863c638 + (0863c638)[1]
      r2 = 0863c638 + (0863c638)[0]
      r3 = 0863c638 + (0863c638)[2]
*/
void ResetTerrain(struct Terrain *terrain, metatile_attr_t *attr, Metatile *tiles, Screen *m, const struct ScreenLayout *map) {
  terrain->attrs = attr;
  terrain->tiles = tiles;
  terrain->screens = m;
  terrain->map = map;
}

#if MODERN == 0
NAKED static u8 unused_08006dcc(void *p, struct Coord *c) { INCCODE("asm/unused/unused_08006dcc.inc"); }
NAKED static u8 unused_08006e3c(void *p, u32 unk_x, u32 unk_y) { INCCODE("asm/unused/unused_08006e3c.inc"); }  // unk_x, unk_y の単位不明(pixel?)
NAKED static u8 unused_08006ea8(void *p, u32 r1, s32 r2, s32 r3) { INCCODE("asm/unused/unused_08006ea8.inc"); }
#endif
