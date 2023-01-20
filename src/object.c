#include "object.h"

s32 __divsi3(s32, s32);
extern u8 EReader_21b9;

void setDDP(struct Object *, struct Hitbox *);
void FUN_08007e28(struct UnkHitbox *p1, struct UnkHitbox *p2);
void obj_08008078(struct UnkHitbox *p1, struct UnkHitbox *p2);

// 0x08007074
// pから24バイトを0クリア
static void clear24Bytes(u32 *p) {
  p[5] = 0;
  p[4] = 0;
  p[3] = 0;
  p[2] = 0;
  p[1] = 0;
  p[0] = 0;
  return;
}

void FUN_08007084(void) {
  u8 *p = (u8 *)(0x030032E0);
  p[0] = 0;  // FieldFlag_030032e0
  p[1] = 0;  // FieldFlag_030032e1
  p[2] = 0;  // PauseFrame

  clearUnkHitboxes();
  return;
}

// 030038e4 から 36バイト を0クリア
NAKED void clearUnkHitboxes(void) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	sub sp, #8\n\
	ldr r5, _080070CC @ =0x030032E0\n\
	movs r4, #0\n\
	strb r4, [r5, #3]\n\
	ldr r0, _080070D0 @ =0x00000604\n\
	adds r1, r5, r0\n\
	str r4, [sp]\n\
	ldr r2, _080070D4 @ =0x01000008\n\
	mov r0, sp\n\
	bl CpuFastSet\n\
	str r4, [sp, #4]\n\
	add r0, sp, #4\n\
	ldr r1, _080070D8 @ =0x00000624\n\
	adds r5, r5, r1\n\
	ldr r2, _080070DC @ =0x05000001\n\
	adds r1, r5, #0\n\
	bl CpuSet\n\
	add sp, #8\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080070CC: .4byte 0x030032E0\n\
_080070D0: .4byte 0x00000604\n\
_080070D4: .4byte 0x01000008\n\
_080070D8: .4byte 0x00000624\n\
_080070DC: .4byte 0x05000001\n\
   .syntax divided\n");
}

// 0x080070E0
NAKED void decrementPauseFrame(void) {
  asm(".syntax unified\n\
    push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	bl obj_08007ccc\n\
	ldr r7, _08007100 @ =0x030032E0\n\
	ldrb r0, [r7, #2]\n\
	adds r1, r0, #0\n\
	cmp r1, #0\n\
	beq _08007104\n\
	subs r0, #1\n\
	strb r0, [r7, #2]\n\
	b _080071CC\n\
	.align 2, 0\n\
_08007100: .4byte 0x030032E0\n\
_08007104:\n\
	movs r2, #0xc5\n\
	lsls r2, r2, #3\n\
	adds r0, r7, r2\n\
	str r1, [r0]\n\
	adds r2, #4\n\
	adds r0, r7, r2\n\
	str r1, [r0]\n\
	adds r2, #4\n\
	adds r0, r7, r2\n\
	str r1, [r0]\n\
	ldr r0, _080071DC @ =0x00000604\n\
	adds r0, r0, r7\n\
	mov r8, r0\n\
	ldr r0, [r0]\n\
	movs r1, #0xc4\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r7\n\
	mov sl, r1\n\
	ldr r1, [r1]\n\
	bl obj_08007d38\n\
	mov r2, r8\n\
	ldr r0, [r2]\n\
	ldr r1, _080071E0 @ =0x00000624\n\
	adds r4, r7, r1\n\
	ldr r1, [r4]\n\
	bl obj_08007d38\n\
	movs r2, #0xc1\n\
	lsls r2, r2, #3\n\
	adds r6, r7, r2\n\
	ldr r0, [r6]\n\
	ldr r1, _080071E4 @ =0x0000061C\n\
	adds r1, r1, r7\n\
	mov sb, r1\n\
	ldr r1, [r1]\n\
	bl obj_08007d38\n\
	ldr r0, [r6]\n\
	ldr r1, [r4]\n\
	bl obj_08007d38\n\
	ldr r2, _080071E8 @ =0x0000060C\n\
	adds r5, r7, r2\n\
	ldr r0, [r5]\n\
	mov r2, sl\n\
	ldr r1, [r2]\n\
	bl obj_08007d38\n\
	ldr r0, [r5]\n\
	mov r2, sb\n\
	ldr r1, [r2]\n\
	bl obj_08007d38\n\
	ldr r0, [r5]\n\
	ldr r1, [r4]\n\
	bl obj_08007d38\n\
	mov r1, r8\n\
	ldr r0, [r1]\n\
	ldr r2, _080071EC @ =0x00000614\n\
	adds r2, r2, r7\n\
	mov sb, r2\n\
	ldr r1, [r2]\n\
	bl FUN_08007db0\n\
	mov r1, r8\n\
	ldr r0, [r1]\n\
	movs r2, #0xc3\n\
	lsls r2, r2, #3\n\
	adds r4, r7, r2\n\
	ldr r1, [r4]\n\
	bl FUN_08007db0\n\
	ldr r0, [r6]\n\
	movs r1, #0xc2\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r7\n\
	mov r8, r1\n\
	ldr r1, [r1]\n\
	bl FUN_08007db0\n\
	ldr r0, [r6]\n\
	ldr r1, [r4]\n\
	bl FUN_08007db0\n\
	ldr r0, [r5]\n\
	mov r2, sb\n\
	ldr r1, [r2]\n\
	bl FUN_08007db0\n\
	ldr r0, [r5]\n\
	mov r2, r8\n\
	ldr r1, [r2]\n\
	bl FUN_08007db0\n\
	ldr r0, [r5]\n\
	ldr r1, [r4]\n\
	bl FUN_08007db0\n\
_080071CC:\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080071DC: .4byte 0x00000604\n\
_080071E0: .4byte 0x00000624\n\
_080071E4: .4byte 0x0000061C\n\
_080071E8: .4byte 0x0000060C\n\
_080071EC: .4byte 0x00000614\n\
   .syntax divided\n");
}

void resetEnemyData(struct Object *p, struct Hitbox *ddp, struct Coord *coord, u16 hp) {
  p->status = 0;
  p->unk_28 = 0;
  *(u8 *)&p->invincibleTime = 0;
  p->coord = coord;
  p->hp = hp;
  p->fn = (void *)0x0;
  p->unk_40 = 0;
  p->parent = (struct Entity *)0x0;
  *(u32 *)&p->invincibleTime = 0;

  setDDP(p, ddp);
  return;
}

void setDDP(struct Object *p, struct Hitbox *ddp) {
  p->ddp = ddp;
  p->unk_59 = 0;
  p->unk_54 = 0;
  return;
}

NAKED void hitbox_08007224(struct Object *o, struct Hitbox *ddp, u8 atk, u16 r3, u32 r4, u32 r5) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	mov ip, r0\n\
	ldr r0, [sp, #0xc]\n\
	ldr r4, [sp, #0x10]\n\
	lsls r2, r2, #0x10\n\
	lsrs r2, r2, #0x10\n\
	lsls r3, r3, #0x10\n\
	lsrs r3, r3, #0x10\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	adds r5, r0, #0\n\
	lsls r4, r4, #0x10\n\
	lsrs r4, r4, #0x10\n\
	mov r0, ip\n\
	str r1, [r0]\n\
	adds r0, #0x37\n\
	movs r1, #0\n\
	strb r2, [r0]\n\
	adds r0, #1\n\
	strb r3, [r0]\n\
	adds r0, #1\n\
	strb r5, [r0]\n\
	adds r0, #1\n\
	strb r4, [r0]\n\
	adds r0, #1\n\
	strb r1, [r0]\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	mvns r2, r2\n\
	lsrs r2, r2, #0x1f\n\
	lsls r3, r3, #0x10\n\
	cmp r3, #0\n\
	blt _0800726A\n\
	movs r0, #2\n\
	orrs r2, r0\n\
_0800726A:\n\
	lsls r0, r5, #0x10\n\
	cmp r0, #0\n\
	blt _08007274\n\
	movs r0, #4\n\
	orrs r2, r0\n\
_08007274:\n\
	lsls r0, r4, #0x10\n\
	cmp r0, #0\n\
	blt _0800727E\n\
	movs r0, #8\n\
	orrs r2, r0\n\
_0800727E:\n\
	mov r0, ip\n\
	adds r0, #0x36\n\
	strb r2, [r0]\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
      .syntax divided\n");
}

static void FUN_0800728c(struct Object *o, struct Hitbox *ddp, u8 r2) {
  o->ddp = ddp;
  o->unk_59 = r2;
  o->unk_54 = 0;
  return;
}

NAKED void hitbox_0800729c(struct Object *p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	ldr r3, [r4]\n\
	ldr r6, [r4, #8]\n\
	adds r5, r4, #0\n\
	adds r5, #0x20\n\
	ldrb r2, [r5]\n\
	movs r1, #0x7f\n\
	ands r1, r2\n\
	cmp r1, #0\n\
	beq _080072BC\n\
	movs r0, #0x80\n\
	ands r0, r2\n\
	subs r1, #1\n\
	orrs r0, r1\n\
	strb r0, [r5]\n\
_080072BC:\n\
	cmp r3, #0\n\
	beq _0800734E\n\
	ldrb r0, [r3, #3]\n\
	cmp r0, #0\n\
	bne _080072D4\n\
	ldrb r1, [r3, #8]\n\
	cmp r1, #0\n\
	bne _080072D4\n\
	ldr r0, [r4, #0x18]\n\
	str r0, [r4, #0x1c]\n\
	str r1, [r4, #0x18]\n\
	b _0800734E\n\
_080072D4:\n\
	ldr r0, _08007354 @ =0x030032E0\n\
	ldrb r1, [r0, #3]\n\
	mov ip, r0\n\
	cmp r1, #0x3f\n\
	bhi _08007346\n\
	mov r5, ip\n\
	ldr r7, _08007358 @ =0x00000604\n\
	add r7, ip\n\
_080072E4:\n\
	ldrb r1, [r5, #3]\n\
	lsls r2, r1, #1\n\
	adds r2, r2, r1\n\
	lsls r2, r2, #3\n\
	adds r0, r5, #4\n\
	adds r2, r2, r0\n\
	adds r1, #1\n\
	strb r1, [r5, #3]\n\
	str r4, [r2, #8]\n\
	str r3, [r2, #4]\n\
	movs r0, #0x10\n\
	ldrsh r1, [r3, r0]\n\
	ldr r0, [r6]\n\
	adds r0, r0, r1\n\
	str r0, [r2, #0xc]\n\
	movs r0, #0x12\n\
	ldrsh r1, [r3, r0]\n\
	ldr r0, [r6, #4]\n\
	adds r0, r0, r1\n\
	str r0, [r2, #0x10]\n\
	ldrh r0, [r3, #0x14]\n\
	strh r0, [r2, #0x14]\n\
	ldrh r0, [r3, #0x16]\n\
	strh r0, [r2, #0x16]\n\
	ldrb r1, [r3]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	ldrb r1, [r3, #1]\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r7\n\
	ldr r0, [r0]\n\
	str r0, [r2]\n\
	ldrb r1, [r3]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	ldrb r1, [r3, #1]\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r7\n\
	str r2, [r0]\n\
	ldrb r0, [r3, #0xb]\n\
	cmp r0, #0\n\
	beq _08007346\n\
	adds r3, #0x18\n\
	mov r1, ip\n\
	ldrb r0, [r1, #3]\n\
	cmp r0, #0x3f\n\
	bls _080072E4\n\
_08007346:\n\
	ldr r0, [r4, #0x18]\n\
	str r0, [r4, #0x1c]\n\
	movs r0, #0\n\
	str r0, [r4, #0x18]\n\
_0800734E:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08007354: .4byte 0x030032E0\n\
_08007358: .4byte 0x00000604\n\
            .syntax divided\n");
}

NAKED void FUN_0800735c(struct Object *p, u32 r1) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	adds r4, r0, #0\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	mov ip, r1\n\
	ldr r3, [r4]\n\
	ldr r5, [r4, #8]\n\
	adds r6, r4, #0\n\
	adds r6, #0x20\n\
	ldrb r2, [r6]\n\
	movs r1, #0x7f\n\
	ands r1, r2\n\
	cmp r1, #0\n\
	beq _08007388\n\
	movs r0, #0x80\n\
	ands r0, r2\n\
	subs r1, #1\n\
	orrs r0, r1\n\
	strb r0, [r6]\n\
_08007388:\n\
	cmp r3, #0\n\
	beq _08007456\n\
	ldrb r0, [r3, #3]\n\
	cmp r0, #0\n\
	bne _080073A0\n\
	ldrb r1, [r3, #8]\n\
	cmp r1, #0\n\
	bne _080073A0\n\
	ldr r0, [r4, #0x18]\n\
	str r0, [r4, #0x1c]\n\
	str r1, [r4, #0x18]\n\
	b _08007456\n\
_080073A0:\n\
	ldr r0, _080073E8 @ =0x030032E0\n\
	ldrb r1, [r0, #3]\n\
	mov sb, r0\n\
	cmp r1, #0x3f\n\
	bhi _0800744E\n\
	mov r6, sb\n\
	movs r0, #1\n\
	mov r1, ip\n\
	ands r1, r0\n\
	mov r8, r1\n\
	ldr r7, _080073EC @ =0x00000604\n\
	add r7, sb\n\
	movs r0, #2\n\
	mov r1, ip\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov ip, r0\n\
_080073C4:\n\
	ldrb r0, [r6, #3]\n\
	lsls r1, r0, #1\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #3\n\
	adds r2, r6, #4\n\
	adds r2, r1, r2\n\
	adds r0, #1\n\
	strb r0, [r6, #3]\n\
	str r4, [r2, #8]\n\
	str r3, [r2, #4]\n\
	mov r0, r8\n\
	cmp r0, #0\n\
	beq _080073F0\n\
	movs r0, #0x10\n\
	ldrsh r1, [r3, r0]\n\
	ldr r0, [r5]\n\
	subs r0, r0, r1\n\
	b _080073F8\n\
	.align 2, 0\n\
_080073E8: .4byte 0x030032E0\n\
_080073EC: .4byte 0x00000604\n\
_080073F0:\n\
	movs r0, #0x10\n\
	ldrsh r1, [r3, r0]\n\
	ldr r0, [r5]\n\
	adds r0, r0, r1\n\
_080073F8:\n\
	str r0, [r2, #0xc]\n\
	mov r1, ip\n\
	cmp r1, #0\n\
	beq _0800740A\n\
	movs r0, #0x12\n\
	ldrsh r1, [r3, r0]\n\
	ldr r0, [r5, #4]\n\
	subs r0, r0, r1\n\
	b _08007412\n\
_0800740A:\n\
	movs r0, #0x12\n\
	ldrsh r1, [r3, r0]\n\
	ldr r0, [r5, #4]\n\
	adds r0, r0, r1\n\
_08007412:\n\
	str r0, [r2, #0x10]\n\
	ldrh r0, [r3, #0x14]\n\
	strh r0, [r2, #0x14]\n\
	ldrh r0, [r3, #0x16]\n\
	strh r0, [r2, #0x16]\n\
	ldrb r1, [r3]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	ldrb r1, [r3, #1]\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r7\n\
	ldr r0, [r0]\n\
	str r0, [r2]\n\
	ldrb r1, [r3]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	ldrb r1, [r3, #1]\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r7\n\
	str r2, [r0]\n\
	ldrb r0, [r3, #0xb]\n\
	cmp r0, #0\n\
	beq _0800744E\n\
	adds r3, #0x18\n\
	mov r1, sb\n\
	ldrb r0, [r1, #3]\n\
	cmp r0, #0x3f\n\
	bls _080073C4\n\
_0800744E:\n\
	ldr r0, [r4, #0x18]\n\
	str r0, [r4, #0x1c]\n\
	movs r0, #0\n\
	str r0, [r4, #0x18]\n\
_08007456:\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

NAKED void FUN_08007464(struct Object *o, u32 r1, u32 r2) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #8\n\
	adds r7, r0, #0\n\
	lsls r1, r1, #0x18\n\
	lsrs r4, r1, #0x18\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	ldr r6, [r7]\n\
	ldr r0, [r7, #8]\n\
	mov ip, r0\n\
	ldr r1, _080074D4 @ =0x080FEA74\n\
	movs r0, #0xff\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r1\n\
	movs r5, #0\n\
	ldrsh r3, [r0, r5]\n\
	mov sl, r3\n\
	movs r0, #0x3f\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r1\n\
	movs r2, #0\n\
	ldrsh r1, [r0, r2]\n\
	mov r8, r1\n\
	adds r3, r7, #0\n\
	adds r3, #0x20\n\
	ldrb r2, [r3]\n\
	movs r1, #0x7f\n\
	ands r1, r2\n\
	cmp r1, #0\n\
	beq _080074BA\n\
	movs r0, #0x80\n\
	ands r0, r2\n\
	subs r1, #1\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
_080074BA:\n\
	cmp r6, #0\n\
	beq _080075A8\n\
	ldrb r0, [r6, #3]\n\
	cmp r0, #0\n\
	bne _080074D8\n\
	ldrb r1, [r6, #8]\n\
	cmp r1, #0\n\
	bne _080074D8\n\
	ldr r0, [r7, #0x18]\n\
	str r0, [r7, #0x1c]\n\
	str r1, [r7, #0x18]\n\
	b _080075A8\n\
	.align 2, 0\n\
_080074D4: .4byte 0x080FEA74\n\
_080074D8:\n\
	ldr r0, _08007540 @ =0x030032E0\n\
	ldrb r1, [r0, #3]\n\
	cmp r1, #0x3f\n\
	bhi _080075A0\n\
	adds r3, r0, #0\n\
	mov sb, r3\n\
	movs r5, #1\n\
	ands r5, r4\n\
	str r5, [sp]\n\
	movs r0, #2\n\
	ands r0, r4\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	str r0, [sp, #4]\n\
_080074F4:\n\
	mov r0, sb\n\
	ldrb r2, [r0, #3]\n\
	lsls r0, r2, #1\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #3\n\
	mov r1, sb\n\
	adds r1, #4\n\
	adds r4, r0, r1\n\
	adds r2, #1\n\
	mov r1, sb\n\
	strb r2, [r1, #3]\n\
	str r7, [r4, #8]\n\
	str r6, [r4, #4]\n\
	movs r2, #0x10\n\
	ldrsh r3, [r6, r2]\n\
	mov r1, r8\n\
	muls r1, r3, r1\n\
	asrs r1, r1, #8\n\
	movs r5, #0x12\n\
	ldrsh r2, [r6, r5]\n\
	mov r0, sl\n\
	muls r0, r2, r0\n\
	asrs r0, r0, #8\n\
	adds r5, r1, r0\n\
	mov r1, r8\n\
	muls r1, r2, r1\n\
	asrs r1, r1, #8\n\
	mov r0, sl\n\
	muls r0, r3, r0\n\
	asrs r0, r0, #8\n\
	subs r1, r1, r0\n\
	ldr r0, [sp]\n\
	cmp r0, #0\n\
	beq _08007544\n\
	mov r2, ip\n\
	ldr r0, [r2]\n\
	subs r0, r0, r5\n\
	b _0800754A\n\
	.align 2, 0\n\
_08007540: .4byte 0x030032E0\n\
_08007544:\n\
	mov r3, ip\n\
	ldr r0, [r3]\n\
	adds r0, r0, r5\n\
_0800754A:\n\
	str r0, [r4, #0xc]\n\
	ldr r5, [sp, #4]\n\
	cmp r5, #0\n\
	beq _0800755A\n\
	mov r2, ip\n\
	ldr r0, [r2, #4]\n\
	subs r0, r0, r1\n\
	b _08007560\n\
_0800755A:\n\
	mov r3, ip\n\
	ldr r0, [r3, #4]\n\
	adds r0, r0, r1\n\
_08007560:\n\
	str r0, [r4, #0x10]\n\
	ldrh r0, [r6, #0x14]\n\
	strh r0, [r4, #0x14]\n\
	ldrh r0, [r6, #0x16]\n\
	strh r0, [r4, #0x16]\n\
	ldrb r1, [r6]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	ldrb r5, [r6, #1]\n\
	adds r0, r0, r5\n\
	lsls r0, r0, #2\n\
	ldr r1, _080075B8 @ =0x030038E4\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	str r0, [r4]\n\
	ldrb r1, [r6]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	ldrb r2, [r6, #1]\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #2\n\
	ldr r3, _080075B8 @ =0x030038E4\n\
	adds r0, r0, r3\n\
	str r4, [r0]\n\
	ldrb r0, [r6, #0xb]\n\
	cmp r0, #0\n\
	beq _080075A0\n\
	adds r6, #0x18\n\
	ldr r5, _080075BC @ =0x030032E0\n\
	ldrb r0, [r5, #3]\n\
	cmp r0, #0x3f\n\
	bls _080074F4\n\
_080075A0:\n\
	ldr r0, [r7, #0x18]\n\
	str r0, [r7, #0x1c]\n\
	movs r0, #0\n\
	str r0, [r7, #0x18]\n\
_080075A8:\n\
	add sp, #8\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080075B8: .4byte 0x030038E4\n\
_080075BC: .4byte 0x030032E0\n\
      .syntax divided\n");
}

/*
  与えるダメージ量を計算する
    引数: r0 = 攻撃側, r1 = 食らう側
      例: (r0, r1) = (0x030058F8, 0x02037CD4)
    返り値: 実際のダメージ
*/
NAKED s32 calcDamage(struct Object *enemy, struct Object *self) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldr r3, [r1, #4]\n\
	adds r1, #0x3b\n\
	ldrb r2, [r3, #9]\n\
	ldrb r0, [r1]\n\
	adds r5, r0, #0\n\
	orrs r5, r2\n\
	ldr r0, _08007608 @ =0x030032E0\n\
	ldrb r1, [r0]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08007602\n\
	ldrb r0, [r3, #8]\n\
	cmp r0, #0xff\n\
	beq _08007602\n\
	movs r0, #2\n\
	ands r0, r5\n\
	cmp r0, #0\n\
	bne _08007602\n\
	ldr r2, _0800760C @ =0x08338D34\n\
	adds r0, r4, #0\n\
	adds r0, #0x38\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #2\n\
	ldrb r1, [r3, #8]\n\
	lsls r1, r1, #4\n\
	adds r0, r0, r1\n\
	adds r0, r0, r2\n\
	ldr r1, [r0]\n\
	cmp r1, #9\n\
	bne _08007610\n\
_08007602:\n\
	movs r0, #0\n\
	b _0800766E\n\
	.align 2, 0\n\
_08007608: .4byte 0x030032E0\n\
_0800760C: .4byte 0x08338D34\n\
_08007610:\n\
	adds r0, r4, #0\n\
	adds r0, #0x37\n\
	ldrb r4, [r0]\n\
	adds r0, r4, #0\n\
	muls r0, r1, r0\n\
	asrs r2, r0, #2\n\
	ldrb r1, [r3, #2]\n\
	cmp r1, #1\n\
	bne _08007640\n\
	ldr r0, _08007664 @ =0x0202FDC0\n\
	ldrb r0, [r0, #8]\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _08007632\n\
	cmp r4, #0xfe\n\
	bne _08007632\n\
	movs r2, #8\n\
_08007632:\n\
	ldr r0, _08007668 @ =0x020021B0\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08007640\n\
	asrs r2, r2, #1\n\
_08007640:\n\
	movs r0, #0x10\n\
	ands r0, r5\n\
	cmp r0, #0\n\
	beq _0800764A\n\
	lsls r2, r2, #1\n\
_0800764A:\n\
	movs r0, #4\n\
	ands r5, r0\n\
	cmp r5, #0\n\
	beq _0800765C\n\
	lsls r0, r2, #1\n\
	movs r1, #3\n\
	bl __divsi3\n\
	adds r2, r0, #0\n\
_0800765C:\n\
	cmp r2, #0\n\
	bne _0800766C\n\
	movs r0, #1\n\
	b _0800766E\n\
	.align 2, 0\n\
_08007664: .4byte 0x0202FDC0\n\
_08007668: .4byte 0x020021B0\n\
_0800766C:\n\
	adds r0, r2, #0\n\
_0800766E:\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
      .syntax divided\n");
}

NAKED void hitbox_08007674(struct Object *attacker, struct Object *defencer) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r5, r0, #0\n\
	adds r4, r1, #0\n\
	ldr r2, _08007798 @ =0x030032E0\n\
	ldrb r1, [r2]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	mov r8, r2\n\
	cmp r0, #0\n\
	beq _0800768E\n\
	b _08007B72\n\
_0800768E:\n\
	ldr r0, [r4, #4]\n\
	ldr r1, [r5, #0x3c]\n\
	ldr r2, [r0, #4]\n\
	ands r1, r2\n\
	adds r3, r0, #0\n\
	cmp r1, #0\n\
	bne _0800769E\n\
	b _08007B72\n\
_0800769E:\n\
	ldr r0, [r5, #4]\n\
	ldrb r1, [r0, #2]\n\
	adds r6, r0, #0\n\
	cmp r1, #3\n\
	bne _080076C0\n\
	ldr r0, [r5, #0x18]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x16\n\
	orrs r0, r1\n\
	str r0, [r5, #0x18]\n\
	ldr r0, [r4, #0x18]\n\
	orrs r0, r1\n\
	str r0, [r4, #0x18]\n\
	movs r0, #0xc5\n\
	lsls r0, r0, #3\n\
	add r0, r8\n\
	str r5, [r0]\n\
_080076C0:\n\
	ldrb r0, [r6, #2]\n\
	cmp r0, #4\n\
	bne _080076DC\n\
	ldr r0, [r5, #0x18]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x17\n\
	orrs r0, r1\n\
	str r0, [r5, #0x18]\n\
	ldr r0, [r4, #0x18]\n\
	orrs r0, r1\n\
	str r0, [r4, #0x18]\n\
	ldr r0, _0800779C @ =0x0000062C\n\
	add r0, r8\n\
	str r5, [r0]\n\
_080076DC:\n\
	ldrb r0, [r6, #2]\n\
	cmp r0, #5\n\
	bne _080076FA\n\
	ldr r0, [r5, #0x18]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x18\n\
	orrs r0, r1\n\
	str r0, [r5, #0x18]\n\
	ldr r0, [r4, #0x18]\n\
	orrs r0, r1\n\
	str r0, [r4, #0x18]\n\
	movs r0, #0xc6\n\
	lsls r0, r0, #3\n\
	add r0, r8\n\
	str r5, [r0]\n\
_080076FA:\n\
	mov r1, r8\n\
	ldrb r0, [r1]\n\
	ldrb r1, [r3, #1]\n\
	asrs r0, r1\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0800770C\n\
	b _08007B72\n\
_0800770C:\n\
	ldrb r7, [r6, #0xa]\n\
	movs r0, #0x21\n\
	ands r0, r7\n\
	cmp r0, #0\n\
	beq _080077D0\n\
	ldrb r1, [r3, #0xa]\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080077D0\n\
	ldr r1, [r5, #0x18]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #4\n\
	adds r0, r1, #0\n\
	ands r0, r2\n\
	mov ip, r1\n\
	cmp r0, #0\n\
	bne _080077D0\n\
	ldr r0, [r4, #0x18]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #3\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	bne _080077D0\n\
	ldr r0, [r5, #0x1c]\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _0800774C\n\
	ldr r0, [r4, #0x1c]\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	beq _080077A0\n\
_0800774C:\n\
	ldr r0, [r5, #0x10]\n\
	cmp r0, r4\n\
	bne _080077D0\n\
	ldr r0, [r4, #0x10]\n\
	cmp r0, r5\n\
	bne _080077D0\n\
	movs r0, #2\n\
	ands r0, r7\n\
	adds r1, r5, #0\n\
	adds r1, #0x21\n\
	cmp r0, #0\n\
	beq _0800776A\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	bne _0800777A\n\
_0800776A:\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	beq _080077D0\n\
	adds r0, r4, #0\n\
	adds r0, #0x21\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _080077D0\n\
_0800777A:\n\
	ldr r1, [r5, #0x14]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
	orrs r1, r0\n\
	str r1, [r5, #0x14]\n\
	ldr r2, [r4, #0x14]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #3\n\
	orrs r2, r0\n\
	str r2, [r4, #0x14]\n\
	mov r0, ip\n\
	orrs r1, r0\n\
	str r1, [r5, #0x18]\n\
	b _080077CA\n\
	.align 2, 0\n\
_08007798: .4byte 0x030032E0\n\
_0800779C: .4byte 0x0000062C\n\
_080077A0:\n\
	str r4, [r5, #0x10]\n\
	str r5, [r4, #0x10]\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xf0\n\
	ands r0, r1\n\
	lsrs r0, r0, #1\n\
	adds r1, r4, #0\n\
	adds r1, #0x21\n\
	strb r0, [r1]\n\
	adds r1, r5, #0\n\
	adds r1, #0x21\n\
	strb r0, [r1]\n\
	ldr r1, [r5, #0x14]\n\
	orrs r1, r2\n\
	str r1, [r5, #0x14]\n\
	ldr r2, [r4, #0x14]\n\
	orrs r2, r3\n\
	str r2, [r4, #0x14]\n\
	ldr r0, [r5, #0x18]\n\
	orrs r0, r1\n\
	str r0, [r5, #0x18]\n\
_080077CA:\n\
	ldr r0, [r4, #0x18]\n\
	orrs r0, r2\n\
	str r0, [r4, #0x18]\n\
_080077D0:\n\
	ldr r1, [r4, #0x18]\n\
	movs r0, #9\n\
	ands r0, r1\n\
	mov ip, r1\n\
	cmp r0, #0\n\
	beq _080077DE\n\
	b _08007B72\n\
_080077DE:\n\
	ldr r0, [r4, #4]\n\
	ldr r1, [r5, #0x3c]\n\
	ldr r2, [r0, #0xc]\n\
	ands r1, r2\n\
	adds r3, r0, #0\n\
	cmp r1, #0\n\
	bne _080077EE\n\
	b _08007940\n\
_080077EE:\n\
	ldr r0, [r5, #4]\n\
	ldrb r1, [r0, #2]\n\
	adds r6, r0, #0\n\
	cmp r1, #1\n\
	bne _08007830\n\
	ldrb r2, [r6, #4]\n\
	cmp r2, #0\n\
	beq _08007830\n\
	ldr r0, [r4, #0x1c]\n\
	movs r1, #0x18\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08007830\n\
	adds r0, r4, #0\n\
	adds r0, #0x23\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x1c\n\
	lsrs r0, r0, #0x1c\n\
	cmp r0, r2\n\
	bne _08007830\n\
	adds r0, r4, #0\n\
	adds r0, #0x22\n\
	adds r1, r5, #0\n\
	adds r1, #0x3a\n\
	ldrb r0, [r0]\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	blo _08007830\n\
	str r4, [r5, #0xc]\n\
	str r5, [r4, #0xc]\n\
	movs r0, #0x10\n\
	mov r1, ip\n\
	b _08007B6E\n\
_08007830:\n\
	ldrb r0, [r3, #8]\n\
	cmp r0, #0xff\n\
	beq _08007852\n\
	str r4, [r5, #0xc]\n\
	ldr r2, [r5, #0x14]\n\
	movs r0, #0x20\n\
	orrs r2, r0\n\
	str r2, [r5, #0x14]\n\
	ldrb r1, [r3, #9]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08007852\n\
	movs r0, #0x80\n\
	lsls r0, r0, #5\n\
	orrs r2, r0\n\
	str r2, [r5, #0x14]\n\
_08007852:\n\
	adds r0, r4, #0\n\
	adds r0, #0x20\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0800785E\n\
	b _08007A3E\n\
_0800785E:\n\
	adds r0, r5, #0\n\
	adds r0, #0x37\n\
	ldrb r0, [r0]\n\
	cmp r0, #0xff\n\
	bne _0800786A\n\
	b _08007A3E\n\
_0800786A:\n\
	str r5, [r4, #0xc]\n\
	ldr r0, [r4, #0x14]\n\
	movs r1, #8\n\
	orrs r0, r1\n\
	str r0, [r4, #0x14]\n\
	ldrb r0, [r6, #4]\n\
	movs r1, #0x23\n\
	adds r1, r1, r4\n\
	mov ip, r1\n\
	movs r3, #0xf\n\
	adds r1, r3, #0\n\
	ands r1, r0\n\
	mov r0, ip\n\
	ldrb r2, [r0]\n\
	movs r0, #0x10\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	adds r1, r5, #0\n\
	adds r1, #0x38\n\
	ldrb r1, [r1]\n\
	lsls r1, r1, #4\n\
	ands r0, r3\n\
	orrs r0, r1\n\
	mov r1, ip\n\
	strb r0, [r1]\n\
	adds r0, r5, #0\n\
	adds r0, #0x3a\n\
	ldrb r0, [r0]\n\
	adds r1, r4, #0\n\
	adds r1, #0x22\n\
	strb r0, [r1]\n\
	adds r2, r5, #0\n\
	adds r2, #0x39\n\
	ldrb r1, [r2]\n\
	movs r7, #4\n\
	adds r0, r7, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080078C4\n\
	ldr r0, [r4, #0x14]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #5\n\
	orrs r0, r1\n\
	str r0, [r4, #0x14]\n\
_080078C4:\n\
	ldrb r3, [r2]\n\
	movs r0, #1\n\
	ands r0, r3\n\
	adds r2, r3, #0\n\
	cmp r0, #0\n\
	beq _080078DA\n\
	ldr r0, [r4, #0x14]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	orrs r0, r1\n\
	str r0, [r4, #0x14]\n\
_080078DA:\n\
	movs r0, #2\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _080078EC\n\
	ldr r0, [r4, #0x14]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #8\n\
	orrs r0, r1\n\
	str r0, [r4, #0x14]\n\
_080078EC:\n\
	movs r0, #0x10\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _080078FE\n\
	ldr r0, [r4, #0x14]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #9\n\
	orrs r0, r1\n\
	str r0, [r4, #0x14]\n\
_080078FE:\n\
	movs r0, #0x20\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _08007910\n\
	ldr r0, [r4, #0x14]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0xa\n\
	orrs r0, r1\n\
	str r0, [r4, #0x14]\n\
_08007910:\n\
	movs r0, #0x40\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	beq _08007922\n\
	ldr r0, [r4, #0x14]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0xf\n\
	orrs r0, r1\n\
	str r0, [r4, #0x14]\n\
_08007922:\n\
	ldr r0, [r4, #4]\n\
	ldrb r0, [r0, #8]\n\
	cmp r0, #0xff\n\
	bne _0800792C\n\
	b _08007B62\n\
_0800792C:\n\
	ldrb r0, [r6, #4]\n\
	subs r0, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bls _0800793A\n\
	b _08007B62\n\
_0800793A:\n\
	mov r0, r8\n\
	strb r7, [r0, #2]\n\
	b _08007B62\n\
_08007940:\n\
	ldr r0, [r5, #4]\n\
	ldrb r1, [r0, #2]\n\
	adds r6, r0, #0\n\
	cmp r1, #1\n\
	bne _08007982\n\
	ldrb r2, [r6, #4]\n\
	cmp r2, #0\n\
	beq _08007982\n\
	ldr r0, [r4, #0x1c]\n\
	movs r1, #3\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08007982\n\
	adds r0, r4, #0\n\
	adds r0, #0x23\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x1c\n\
	lsrs r0, r0, #0x1c\n\
	cmp r0, r2\n\
	bne _08007982\n\
	adds r0, r4, #0\n\
	adds r0, #0x22\n\
	adds r1, r5, #0\n\
	adds r1, #0x3a\n\
	ldrb r0, [r0]\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	blo _08007982\n\
	str r4, [r5, #0xc]\n\
	str r5, [r4, #0xc]\n\
	movs r0, #2\n\
	mov r1, ip\n\
	b _08007B6E\n\
_08007982:\n\
	ldrb r0, [r3, #8]\n\
	cmp r0, #0xff\n\
	beq _080079AE\n\
	str r4, [r5, #0xc]\n\
	ldr r2, [r5, #0x14]\n\
	movs r0, #4\n\
	orrs r2, r0\n\
	str r2, [r5, #0x14]\n\
	ldrb r1, [r3, #9]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080079AE\n\
	ldr r0, [r4, #0x14]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #6\n\
	orrs r0, r1\n\
	str r0, [r4, #0x14]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #5\n\
	orrs r2, r0\n\
	str r2, [r5, #0x14]\n\
_080079AE:\n\
	ldrb r0, [r3, #2]\n\
	adds r7, r4, #0\n\
	adds r7, #0x20\n\
	cmp r0, #2\n\
	bne _080079DA\n\
	ldrb r0, [r7]\n\
	cmp r0, #0\n\
	beq _080079F0\n\
	adds r0, r4, #0\n\
	adds r0, #0x22\n\
	adds r1, r5, #0\n\
	adds r1, #0x3a\n\
	ldrb r0, [r0]\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	blo _080079DA\n\
	ldrb r0, [r6, #4]\n\
	cmp r0, #0\n\
	beq _080079DA\n\
	movs r0, #0\n\
	str r0, [r5, #0x14]\n\
	b _08007B72\n\
_080079DA:\n\
	ldrb r0, [r7]\n\
	cmp r0, #0\n\
	beq _080079F0\n\
	adds r0, r4, #0\n\
	adds r0, #0x22\n\
	adds r1, r5, #0\n\
	adds r1, #0x3a\n\
	ldrb r0, [r0]\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	bhs _080079FA\n\
_080079F0:\n\
	adds r0, r5, #0\n\
	adds r0, #0x37\n\
	ldrb r0, [r0]\n\
	cmp r0, #0xff\n\
	bne _08007A48\n\
_080079FA:\n\
	adds r2, r5, #0\n\
	adds r2, #0x39\n\
	ldrb r1, [r2]\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08007A1E\n\
	str r4, [r5, #0xc]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #5\n\
	mov r1, ip\n\
	orrs r0, r1\n\
	str r0, [r4, #0x18]\n\
	ldr r0, [r5, #0x14]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #6\n\
	orrs r0, r1\n\
	str r0, [r5, #0x14]\n\
_08007A1E:\n\
	ldrb r1, [r2]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08007A3E\n\
	str r4, [r5, #0xc]\n\
	ldr r0, [r4, #0x18]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0xf\n\
	orrs r0, r1\n\
	str r0, [r4, #0x18]\n\
	ldr r0, [r5, #0x14]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x10\n\
	orrs r0, r1\n\
	str r0, [r5, #0x14]\n\
_08007A3E:\n\
	ldr r0, [r5, #0x18]\n\
	ldr r1, [r5, #0x14]\n\
	orrs r0, r1\n\
	str r0, [r5, #0x18]\n\
	b _08007B72\n\
_08007A48:\n\
	str r5, [r4, #0xc]\n\
	ldr r0, [r4, #0x14]\n\
	movs r1, #1\n\
	mov r8, r1\n\
	orrs r0, r1\n\
	str r0, [r4, #0x14]\n\
	ldrb r0, [r6, #4]\n\
	movs r1, #0x23\n\
	adds r1, r1, r4\n\
	mov ip, r1\n\
	movs r3, #0xf\n\
	adds r1, r3, #0\n\
	ands r1, r0\n\
	mov r0, ip\n\
	ldrb r2, [r0]\n\
	movs r0, #0x10\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	adds r1, r5, #0\n\
	adds r1, #0x38\n\
	ldrb r1, [r1]\n\
	lsls r1, r1, #4\n\
	ands r0, r3\n\
	orrs r0, r1\n\
	mov r1, ip\n\
	strb r0, [r1]\n\
	adds r0, r5, #0\n\
	adds r0, #0x3a\n\
	ldrb r0, [r0]\n\
	adds r1, r4, #0\n\
	adds r1, #0x22\n\
	strb r0, [r1]\n\
	adds r2, r5, #0\n\
	adds r2, #0x39\n\
	ldrb r1, [r2]\n\
	movs r6, #4\n\
	adds r0, r6, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08007AAE\n\
	ldr r0, [r5, #0x14]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #6\n\
	orrs r0, r1\n\
	str r0, [r5, #0x14]\n\
	ldr r0, [r4, #0x14]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #5\n\
	orrs r0, r1\n\
	str r0, [r4, #0x14]\n\
_08007AAE:\n\
	ldrb r3, [r2]\n\
	mov r0, r8\n\
	ands r0, r3\n\
	adds r2, r3, #0\n\
	cmp r0, #0\n\
	beq _08007AC4\n\
	ldr r0, [r4, #0x14]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	orrs r0, r1\n\
	str r0, [r4, #0x14]\n\
_08007AC4:\n\
	movs r0, #2\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _08007AD6\n\
	ldr r0, [r4, #0x14]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #8\n\
	orrs r0, r1\n\
	str r0, [r4, #0x14]\n\
_08007AD6:\n\
	movs r0, #0x10\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _08007AE8\n\
	ldr r0, [r4, #0x14]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #9\n\
	orrs r0, r1\n\
	str r0, [r4, #0x14]\n\
_08007AE8:\n\
	movs r0, #0x20\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _08007AFA\n\
	ldr r0, [r4, #0x14]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0xa\n\
	orrs r0, r1\n\
	str r0, [r4, #0x14]\n\
_08007AFA:\n\
	movs r0, #0x40\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	beq _08007B16\n\
	ldr r0, [r5, #0x14]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x10\n\
	orrs r0, r1\n\
	str r0, [r5, #0x14]\n\
	ldr r0, [r4, #0x14]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0xf\n\
	orrs r0, r1\n\
	str r0, [r4, #0x14]\n\
_08007B16:\n\
	adds r0, r5, #0\n\
	adds r1, r4, #0\n\
	bl calcDamage\n\
	ldrh r1, [r4, #0x30]\n\
	subs r1, r1, r0\n\
	strh r1, [r4, #0x30]\n\
	lsls r1, r1, #0x10\n\
	cmp r1, #0\n\
	bgt _08007B38\n\
	movs r0, #0\n\
	strh r0, [r4, #0x30]\n\
	ldr r0, [r4, #0x14]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	orrs r0, r1\n\
	str r0, [r4, #0x14]\n\
_08007B38:\n\
	ldr r0, [r4, #4]\n\
	ldrb r0, [r0, #8]\n\
	cmp r0, #0xff\n\
	beq _08007B52\n\
	ldr r0, [r5, #4]\n\
	ldrb r0, [r0, #4]\n\
	subs r0, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bhi _08007B52\n\
	ldr r0, _08007B7C @ =0x030032E0\n\
	strb r6, [r0, #2]\n\
_08007B52:\n\
	ldr r0, [r4, #4]\n\
	ldrb r0, [r0, #2]\n\
	cmp r0, #1\n\
	beq _08007B5E\n\
	cmp r0, #2\n\
	bne _08007B62\n\
_08007B5E:\n\
	movs r0, #0x5a\n\
	strb r0, [r7]\n\
_08007B62:\n\
	ldr r0, [r5, #0x18]\n\
	ldr r1, [r5, #0x14]\n\
	orrs r0, r1\n\
	str r0, [r5, #0x18]\n\
	ldr r0, [r4, #0x18]\n\
	ldr r1, [r4, #0x14]\n\
_08007B6E:\n\
	orrs r0, r1\n\
	str r0, [r4, #0x18]\n\
_08007B72:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08007B7C: .4byte 0x030032E0\n\
 .syntax divided\n");
}

NAKED bool8 FUN_08007b80(s32 param_1, s32 param_2) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r5, r0, #0\n\
	mov ip, r1\n\
	ldr r0, [r1, #4]\n\
	mov r2, ip\n\
	adds r2, #0x3b\n\
	ldrb r1, [r0, #9]\n\
	ldrb r0, [r2]\n\
	adds r2, r0, #0\n\
	orrs r2, r1\n\
	ldr r0, _08007BA4 @ =0x030032E0\n\
	ldrb r1, [r0]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08007BA8\n\
	movs r0, #0\n\
	b _08007C2A\n\
	.align 2, 0\n\
_08007BA4: .4byte 0x030032E0\n\
_08007BA8:\n\
	movs r0, #2\n\
	ands r2, r0\n\
	lsls r0, r2, #0x18\n\
	lsrs r6, r0, #0x18\n\
	cmp r6, #0\n\
	bne _08007C28\n\
	mov r1, ip\n\
	ldrh r0, [r1, #0x30]\n\
	subs r0, #1\n\
	strh r0, [r1, #0x30]\n\
	str r5, [r1, #0xc]\n\
	ldr r0, [r1, #0x18]\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	mov r2, ip\n\
	str r0, [r2, #0x18]\n\
	ldr r0, [r5, #4]\n\
	ldrb r0, [r0, #4]\n\
	mov r4, ip\n\
	adds r4, #0x23\n\
	movs r3, #0xf\n\
	adds r1, r3, #0\n\
	ands r1, r0\n\
	ldrb r2, [r4]\n\
	movs r0, #0x10\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	adds r1, r5, #0\n\
	adds r1, #0x38\n\
	ldrb r1, [r1]\n\
	lsls r1, r1, #4\n\
	ands r0, r3\n\
	orrs r0, r1\n\
	strb r0, [r4]\n\
	adds r0, r5, #0\n\
	adds r0, #0x3a\n\
	ldrb r0, [r0]\n\
	mov r2, ip\n\
	adds r2, #0x22\n\
	strb r0, [r2]\n\
	mov r1, ip\n\
	movs r2, #0x30\n\
	ldrsh r0, [r1, r2]\n\
	cmp r0, #0\n\
	bgt _08007C12\n\
	strh r6, [r1, #0x30]\n\
	ldr r0, [r1, #0x18]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	orrs r0, r1\n\
	mov r1, ip\n\
	str r0, [r1, #0x18]\n\
_08007C12:\n\
	mov r2, ip\n\
	ldr r0, [r2, #4]\n\
	ldrb r0, [r0, #2]\n\
	cmp r0, #1\n\
	beq _08007C20\n\
	cmp r0, #2\n\
	bne _08007C28\n\
_08007C20:\n\
	mov r1, ip\n\
	adds r1, #0x20\n\
	movs r0, #0x5a\n\
	strb r0, [r1]\n\
_08007C28:\n\
	movs r0, #1\n\
_08007C2A:\n\
	pop {r4, r5, r6}\n\
	pop {r1}\n\
	bx r1\n\
     .syntax divided\n");
}

NAKED u32 obj_08007c30(struct Object *p, u32 damage) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	lsls r1, r1, #0x18\n\
	lsrs r3, r1, #0x18\n\
	ldr r0, [r4, #4]\n\
	adds r2, r4, #0\n\
	adds r2, #0x3b\n\
	ldrb r1, [r0, #9]\n\
	ldrb r0, [r2]\n\
	adds r2, r0, #0\n\
	orrs r2, r1\n\
	adds r5, r2, #0\n\
	ldr r0, _08007C64 @ =0x030032E0\n\
	ldrb r1, [r0]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08007C5E\n\
	adds r6, r4, #0\n\
	adds r6, #0x20\n\
	ldrb r0, [r6]\n\
	cmp r0, #0\n\
	beq _08007C68\n\
_08007C5E:\n\
	movs r0, #0\n\
	b _08007CC4\n\
	.align 2, 0\n\
_08007C64: .4byte 0x030032E0\n\
_08007C68:\n\
	movs r0, #0x10\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _08007C74\n\
	lsls r0, r3, #0x19\n\
	lsrs r3, r0, #0x18\n\
_08007C74:\n\
	movs r0, #4\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	beq _08007C88\n\
	lsls r0, r3, #1\n\
	movs r1, #3\n\
	bl __divsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
_08007C88:\n\
	cmp r3, #0\n\
	bne _08007C8E\n\
	movs r3, #1\n\
_08007C8E:\n\
	movs r0, #2\n\
	ands r5, r0\n\
	lsls r0, r5, #0x18\n\
	lsrs r1, r0, #0x18\n\
	cmp r1, #0\n\
	bne _08007CC2\n\
	ldrh r0, [r4, #0x30]\n\
	subs r0, r0, r3\n\
	strh r0, [r4, #0x30]\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bgt _08007CB2\n\
	strh r1, [r4, #0x30]\n\
	ldr r0, [r4, #0x14]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	orrs r0, r1\n\
	str r0, [r4, #0x14]\n\
_08007CB2:\n\
	ldr r0, [r4, #4]\n\
	ldrb r0, [r0, #2]\n\
	cmp r0, #1\n\
	beq _08007CBE\n\
	cmp r0, #2\n\
	bne _08007CC2\n\
_08007CBE:\n\
	movs r0, #0x5a\n\
	strb r0, [r6]\n\
_08007CC2:\n\
	adds r0, r3, #0\n\
_08007CC4:\n\
	pop {r4, r5, r6}\n\
	pop {r1}\n\
	bx r1\n\
     .syntax divided\n");
}

NAKED void obj_08007ccc(void) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	movs r2, #0\n\
	ldr r5, _08007D14 @ =0x030032E0\n\
	movs r0, #0xc2\n\
	lsls r0, r0, #3\n\
	adds r6, r5, r0\n\
_08007CD8:\n\
	ldrb r1, [r5, #1]\n\
	asrs r1, r2\n\
	movs r0, #1\n\
	ands r1, r0\n\
	adds r4, r2, #1\n\
	cmp r1, #0\n\
	beq _08007D2C\n\
	lsls r0, r2, #2\n\
	adds r0, r0, r6\n\
	ldr r3, [r0]\n\
	cmp r3, #0\n\
	beq _08007D2C\n\
_08007CF0:\n\
	ldr r1, [r3, #8]\n\
	adds r1, #0x23\n\
	ldrb r2, [r1]\n\
	movs r0, #0xf\n\
	ands r0, r2\n\
	strb r0, [r1]\n\
	ldr r2, [r3, #8]\n\
	movs r1, #0x30\n\
	ldrsh r0, [r2, r1]\n\
	cmp r0, #0\n\
	beq _08007D1C\n\
	movs r0, #0\n\
	strh r0, [r2, #0x30]\n\
	ldr r2, [r3, #8]\n\
	ldr r0, [r2, #0x18]\n\
	ldr r1, _08007D18 @ =0x00000201\n\
	b _08007D22\n\
	.align 2, 0\n\
_08007D14: .4byte 0x030032E0\n\
_08007D18: .4byte 0x00000201\n\
_08007D1C:\n\
	ldr r0, [r2, #0x18]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
_08007D22:\n\
	orrs r0, r1\n\
	str r0, [r2, #0x18]\n\
	ldr r3, [r3]\n\
	cmp r3, #0\n\
	bne _08007CF0\n\
_08007D2C:\n\
	adds r2, r4, #0\n\
	cmp r2, #2\n\
	ble _08007CD8\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
     .syntax divided\n");
}

/**
 * @brief Hitboxが重なっていたら 0x08007e28 を呼び出す
 * @param ap Attacker's hitbox info
 * @param dp Defender's hitbox info
 * @note 0x08007d38
 */
void obj_08007d38(struct UnkHitbox *ap, struct UnkHitbox *dp) {
  u16 uVar1;
  u16 uVar2;
  s32 x;
  s32 y;
  u32 uVar3;
  u32 uVar4;
  struct UnkHitbox *p;

  if ((ap != (struct UnkHitbox *)0x0) && (dp != (struct UnkHitbox *)0x0)) {
    do {
      x = (ap->c).x;
      y = (ap->c).y;
      uVar1 = ap->w;
      uVar2 = ap->h;
      p = dp;

      if (dp != (struct UnkHitbox *)0x0) {
        do {
          if (((ap->obj != p->obj) && (uVar3 = (u32)uVar1 + (u32)p->w, uVar4 = (u32)uVar2 + (u32)p->h,
                                       (x - (p->c).x) + (uVar3 >> 1) < uVar3)) &&
              ((y - (p->c).y) + (uVar4 >> 1) < uVar4)) {
            FUN_08007e28(ap, p);
          }
          p = p->next;
        } while (p != (struct UnkHitbox *)0x0);
      }

      ap = ap->next;
    } while (ap != (struct UnkHitbox *)0x0);
  }

  return;
}

/**
 * @brief Hitboxが重なっていたら 0x08008078 を呼び出す
 * @details 呼び出す関数が 0x08008078 に変わった以外は、 0x08007d38 と全く同じ
 * @param ap Attacker's hitbox info
 * @param dp Defender's hitbox info
 * @note 0x08007db0
 */
void FUN_08007db0(struct UnkHitbox *ap, struct UnkHitbox *dp) {
  s32 x;
  s32 y;
  u32 uVar1;
  u32 uVar2;
  struct UnkHitbox *r1_00;
  u16 h;
  u16 w;

  if ((ap != (struct UnkHitbox *)0x0) && (dp != (struct UnkHitbox *)0x0)) {
    do {
      x = (ap->c).x;
      y = (ap->c).y;
      w = ap->w;
      h = ap->h;
      r1_00 = dp;

      if (dp != (struct UnkHitbox *)0x0) {
        do {
          if (((ap->obj != r1_00->obj) && (uVar1 = (u32)w + (u32)r1_00->w, uVar2 = (u32)h + (u32)r1_00->h,
                                           (x - (r1_00->c).x) + (uVar1 >> 1) < uVar1)) &&
              ((y - (r1_00->c).y) + (uVar2 >> 1) < uVar2)) {
            obj_08008078(ap, r1_00);
          }

          r1_00 = r1_00->next;
        } while (r1_00 != (struct UnkHitbox *)0x0);
      }

      ap = ap->next;
    } while (ap != (struct UnkHitbox *)0x0);
  }

  return;
}

/**
 * @brief 関数 08007d38 でHitboxが重なっているときに呼び出される
 * @param ap Attacker's hitbox info
 * @param dp Defender's hitbox info
 */
NAKED void FUN_08007e28(struct UnkHitbox *ap, struct UnkHitbox *dp) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x10\n\
	mov sl, r0\n\
	mov sb, r1\n\
	ldr r7, [r0, #8]\n\
	ldr r0, [r1, #8]\n\
	mov r8, r0\n\
	ldr r2, _08007EE0 @ =0x030032E0\n\
	ldrb r1, [r2]\n\
	movs r3, #0x80\n\
	mov ip, r3\n\
	mov r0, ip\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08007E50\n\
	b _08008066\n\
_08007E50:\n\
	mov r4, sl\n\
	ldr r3, [r4, #4]\n\
	ldrb r0, [r3, #2]\n\
	cmp r0, #4\n\
	bne _08007E5C\n\
	b _08008066\n\
_08007E5C:\n\
	adds r4, r7, #0\n\
	adds r4, #0x36\n\
	ldrb r1, [r4]\n\
	movs r6, #4\n\
	adds r0, r6, #0\n\
	ands r0, r1\n\
	adds r5, r7, #0\n\
	adds r5, #0x39\n\
	cmp r0, #0\n\
	bne _08007E74\n\
	ldrb r0, [r3, #6]\n\
	strb r0, [r5]\n\
_08007E74:\n\
	ldrb r1, [r5]\n\
	mov r0, ip\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _08007E84\n\
	b _08008066\n\
_08007E84:\n\
	str r0, [r7, #0x14]\n\
	mov r1, r8\n\
	str r0, [r1, #0x14]\n\
	mov r3, sl\n\
	ldr r0, [r3, #4]\n\
	str r0, [r7, #4]\n\
	mov r1, sb\n\
	ldr r0, [r1, #4]\n\
	mov r3, r8\n\
	str r0, [r3, #4]\n\
	ldrb r1, [r4]\n\
	adds r0, r6, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08007EAA\n\
	mov r4, sl\n\
	ldr r0, [r4, #4]\n\
	ldrb r0, [r0, #6]\n\
	strb r0, [r5]\n\
_08007EAA:\n\
	ldr r0, [r7, #0x18]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08007EC0\n\
	movs r0, #0x80\n\
	lsls r0, r0, #8\n\
	strh r0, [r7, #0x32]\n\
	subs r0, #1\n\
	strh r0, [r7, #0x34]\n\
_08007EC0:\n\
	ldr r0, [r7, #8]\n\
	mov r3, r8\n\
	ldr r1, [r3, #8]\n\
	ldr r3, [r0]\n\
	ldr r0, [r1]\n\
	cmp r3, r0\n\
	bge _08007EE4\n\
	mov r4, sb\n\
	ldrh r1, [r4, #0x14]\n\
	ldr r0, [r4, #0xc]\n\
	subs r0, r0, r1\n\
	subs r0, r0, r3\n\
	asrs r0, r0, #8\n\
	strh r0, [r7, #0x34]\n\
	b _08007EF2\n\
	.align 2, 0\n\
_08007EE0: .4byte 0x030032E0\n\
_08007EE4:\n\
	mov r0, sb\n\
	ldrh r1, [r0, #0x14]\n\
	ldr r0, [r0, #0xc]\n\
	adds r0, r0, r1\n\
	subs r0, r0, r3\n\
	asrs r0, r0, #8\n\
	strh r0, [r7, #0x32]\n\
_08007EF2:\n\
	ldr r0, [r7, #4]\n\
	ldrb r1, [r0, #2]\n\
	adds r3, r0, #0\n\
	cmp r1, #1\n\
	bne _08007F1C\n\
	ldrb r0, [r3, #4]\n\
	cmp r0, #0\n\
	beq _08007F1C\n\
	mov r1, r8\n\
	ldr r0, [r1, #0x1c]\n\
	movs r1, #0xc0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08007F1C\n\
	mov r2, r8\n\
	str r7, [r2, #0xc]\n\
	ldr r0, [r2, #0x18]\n\
	movs r1, #0x80\n\
	orrs r0, r1\n\
	str r0, [r2, #0x18]\n\
	b _08007F70\n\
_08007F1C:\n\
	mov r4, r8\n\
	ldr r0, [r4, #4]\n\
	ldrb r1, [r0, #9]\n\
	movs r4, #1\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08007F3A\n\
	mov r1, r8\n\
	ldr r0, [r1, #0x14]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #6\n\
	orrs r0, r1\n\
	mov r1, r8\n\
	str r0, [r1, #0x14]\n\
_08007F3A:\n\
	mov r0, r8\n\
	str r7, [r0, #0xc]\n\
	ldr r0, [r0, #0x14]\n\
	movs r1, #0x40\n\
	orrs r0, r1\n\
	mov r1, r8\n\
	str r0, [r1, #0x14]\n\
	ldrb r0, [r3, #4]\n\
	subs r0, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bhi _08007F58\n\
	movs r0, #4\n\
	strb r0, [r2, #2]\n\
_08007F58:\n\
	mov r2, r8\n\
	ldr r0, [r2, #4]\n\
	ldrb r1, [r0, #9]\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08007F70\n\
	ldr r0, [r7, #0x14]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #5\n\
	orrs r0, r1\n\
	str r0, [r7, #0x14]\n\
_08007F70:\n\
	mov r3, r8\n\
	str r3, [r7, #0xc]\n\
	ldr r0, [r7, #0x14]\n\
	movs r2, #0x20\n\
	orrs r0, r2\n\
	movs r1, #0x80\n\
	lsls r1, r1, #1\n\
	orrs r0, r1\n\
	str r0, [r7, #0x14]\n\
	ldrb r0, [r5]\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	beq _08007F94\n\
	ldr r0, [r3, #0x14]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0xb\n\
	orrs r0, r1\n\
	str r0, [r3, #0x14]\n\
_08007F94:\n\
	ldr r0, [r7, #0x18]\n\
	ldr r1, [r7, #0x14]\n\
	orrs r0, r1\n\
	str r0, [r7, #0x18]\n\
	mov r4, r8\n\
	ldr r0, [r4, #0x18]\n\
	ldr r1, [r4, #0x14]\n\
	orrs r0, r1\n\
	str r0, [r4, #0x18]\n\
	ldr r0, [r7, #0x24]\n\
	cmp r0, #0\n\
	bne _08007FB2\n\
	ldr r0, [r4, #0x24]\n\
	cmp r0, #0\n\
	beq _08008066\n\
_08007FB2:\n\
	ldr r0, [r7, #0x14]\n\
	cmp r0, #0\n\
	bne _08007FBC\n\
	cmp r1, #0\n\
	beq _08008066\n\
_08007FBC:\n\
	mov r1, sl\n\
	ldr r0, [r1, #0xc]\n\
	mov r2, sb\n\
	ldr r5, [r2, #0xc]\n\
	subs r0, r0, r5\n\
	str r0, [sp]\n\
	ldr r4, [r1, #0x10]\n\
	ldr r6, [r2, #0x10]\n\
	subs r4, r4, r6\n\
	str r4, [sp, #4]\n\
	ldrh r2, [r2, #0x14]\n\
	muls r0, r2, r0\n\
	ldrh r1, [r1, #0x14]\n\
	adds r1, r1, r2\n\
	bl __divsi3\n\
	adds r5, r5, r0\n\
	str r5, [sp, #8]\n\
	mov r3, sb\n\
	ldrh r2, [r3, #0x16]\n\
	adds r0, r2, #0\n\
	muls r0, r4, r0\n\
	mov r4, sl\n\
	ldrh r1, [r4, #0x16]\n\
	adds r1, r1, r2\n\
	bl __divsi3\n\
	adds r6, r6, r0\n\
	add r5, sp, #8\n\
	str r6, [r5, #4]\n\
	ldr r0, [sp]\n\
	adds r1, r0, #0\n\
	muls r1, r0, r1\n\
	adds r0, r1, #0\n\
	ldr r1, [sp, #4]\n\
	adds r2, r1, #0\n\
	muls r2, r1, r2\n\
	adds r1, r2, #0\n\
	adds r0, r0, r1\n\
	bl Sqrt\n\
	adds r4, r0, #0\n\
	lsls r4, r4, #0x10\n\
	lsrs r4, r4, #0x10\n\
	ldr r0, [sp]\n\
	lsls r0, r0, #8\n\
	adds r1, r4, #0\n\
	bl __divsi3\n\
	str r0, [sp]\n\
	ldr r0, [sp, #4]\n\
	lsls r0, r0, #8\n\
	adds r1, r4, #0\n\
	bl __divsi3\n\
	str r0, [sp, #4]\n\
	ldr r3, [r7, #0x24]\n\
	cmp r3, #0\n\
	beq _08008042\n\
	ldr r0, [r7, #0x14]\n\
	cmp r0, #0\n\
	beq _08008042\n\
	adds r0, r7, #0\n\
	adds r1, r5, #0\n\
	mov r2, sp\n\
	bl _call_via_r3\n\
_08008042:\n\
	mov r4, r8\n\
	ldr r3, [r4, #0x24]\n\
	cmp r3, #0\n\
	beq _08008066\n\
	ldr r0, [r4, #0x14]\n\
	cmp r0, #0\n\
	beq _08008066\n\
	ldr r0, [sp]\n\
	rsbs r0, r0, #0\n\
	str r0, [sp]\n\
	ldr r0, [sp, #4]\n\
	rsbs r0, r0, #0\n\
	str r0, [sp, #4]\n\
	mov r0, r8\n\
	adds r1, r5, #0\n\
	mov r2, sp\n\
	bl _call_via_r3\n\
_08008066:\n\
	add sp, #0x10\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
     .syntax divided\n");
}

/**
 * @brief 関数 08007db0 でHitboxが重なっているときに呼び出される
 * @param ap Attacker's hitbox info
 * @param dp Defender's hitbox info
 */
NAKED void obj_08008078(struct UnkHitbox *ap, struct UnkHitbox *dp) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x10\n\
	mov r8, r0\n\
	mov sb, r1\n\
	ldr r7, [r0, #8]\n\
	ldr r0, [r1, #8]\n\
	mov sl, r0\n\
	ldr r0, [r7, #0x18]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080080C4\n\
	mov r1, sb\n\
	ldrh r5, [r1, #0x14]\n\
	ldr r4, [r1, #0xc]\n\
	subs r2, r4, r5\n\
	ldr r1, [r7, #8]\n\
	movs r3, #0x34\n\
	ldrsh r0, [r7, r3]\n\
	lsls r0, r0, #8\n\
	ldr r3, [r1]\n\
	adds r0, r3, r0\n\
	cmp r2, r0\n\
	ble _080080B4\n\
	b _080082D2\n\
_080080B4:\n\
	adds r1, r4, r5\n\
	movs r2, #0x32\n\
	ldrsh r0, [r7, r2]\n\
	lsls r0, r0, #8\n\
	adds r0, r3, r0\n\
	cmp r1, r0\n\
	bge _080080C4\n\
	b _080082D2\n\
_080080C4:\n\
	movs r0, #0\n\
	str r0, [r7, #0x14]\n\
	mov r3, sl\n\
	str r0, [r3, #0x14]\n\
	mov r1, r8\n\
	ldr r0, [r1, #4]\n\
	str r0, [r7, #4]\n\
	mov r2, sb\n\
	ldr r0, [r2, #4]\n\
	str r0, [r3, #4]\n\
	adds r2, r7, #0\n\
	adds r2, #0x36\n\
	ldrb r1, [r2]\n\
	movs r4, #1\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080080F4\n\
	mov r3, r8\n\
	ldr r0, [r3, #4]\n\
	ldrb r0, [r0, #3]\n\
	adds r1, r7, #0\n\
	adds r1, #0x37\n\
	strb r0, [r1]\n\
_080080F4:\n\
	ldrb r1, [r2]\n\
	movs r5, #2\n\
	adds r0, r5, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0800810C\n\
	mov r1, r8\n\
	ldr r0, [r1, #4]\n\
	ldrb r1, [r0, #5]\n\
	adds r0, r7, #0\n\
	adds r0, #0x38\n\
	strb r1, [r0]\n\
_0800810C:\n\
	ldrb r1, [r2]\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08008122\n\
	mov r3, r8\n\
	ldr r0, [r3, #4]\n\
	ldrb r0, [r0, #6]\n\
	adds r1, r7, #0\n\
	adds r1, #0x39\n\
	strb r0, [r1]\n\
_08008122:\n\
	ldrb r1, [r2]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08008138\n\
	mov r1, r8\n\
	ldr r0, [r1, #4]\n\
	ldrb r0, [r0, #7]\n\
	adds r1, r7, #0\n\
	adds r1, #0x3a\n\
	strb r0, [r1]\n\
_08008138:\n\
	ldrb r1, [r2]\n\
	movs r0, #6\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0800814C\n\
	mov r2, r8\n\
	ldr r0, [r2, #4]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r7, #0x3c]\n\
	b _08008204\n\
_0800814C:\n\
	mov r3, r8\n\
	ldr r1, [r3, #4]\n\
	ldrb r0, [r1, #4]\n\
	cmp r0, #3\n\
	bhi _08008188\n\
	adds r0, r7, #0\n\
	adds r0, #0x39\n\
	ldrb r3, [r0]\n\
	adds r0, r4, #0\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	bne _08008182\n\
	ldrb r1, [r1, #4]\n\
	lsls r0, r1, #2\n\
	adds r2, r0, r1\n\
	adds r0, r7, #0\n\
	adds r0, #0x38\n\
	ldrb r1, [r0]\n\
	adds r0, r5, #0\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	beq _0800817E\n\
	adds r0, r1, #1\n\
	adds r0, r2, r0\n\
	b _080081A6\n\
_0800817E:\n\
	adds r0, r2, r1\n\
	b _080081A6\n\
_08008182:\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x18\n\
	b _08008202\n\
_08008188:\n\
	cmp r0, #4\n\
	beq _080081FE\n\
	cmp r0, #7\n\
	bhi _08008196\n\
	ldrb r0, [r1, #4]\n\
	subs r0, #3\n\
	b _080081A6\n\
_08008196:\n\
	cmp r0, #0xb\n\
	bhi _080081B0\n\
	adds r1, r7, #0\n\
	adds r1, #0x38\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	beq _080081AC\n\
	adds r0, #6\n\
_080081A6:\n\
	adds r1, r4, #0\n\
	lsls r1, r0\n\
	b _08008202\n\
_080081AC:\n\
	movs r1, #0x40\n\
	b _08008202\n\
_080081B0:\n\
	cmp r0, #0xc\n\
	beq _080081F8\n\
	cmp r0, #0xd\n\
	bne _080081CC\n\
	adds r0, r7, #0\n\
	adds r0, #0x38\n\
	ldrb r0, [r0]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0xe\n\
	cmp r0, #2\n\
	bne _08008202\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0xf\n\
	b _08008202\n\
_080081CC:\n\
	cmp r0, #0xe\n\
	bne _080081E4\n\
	adds r0, r7, #0\n\
	adds r0, #0x38\n\
	ldrb r0, [r0]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #9\n\
	cmp r0, #1\n\
	bne _08008202\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0xa\n\
	b _08008202\n\
_080081E4:\n\
	adds r0, r7, #0\n\
	adds r0, #0x38\n\
	ldrb r0, [r0]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #9\n\
	cmp r0, #3\n\
	bne _08008202\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0xb\n\
	b _08008202\n\
_080081F8:\n\
	movs r1, #0x80\n\
	lsls r1, r1, #1\n\
	b _08008202\n\
_080081FE:\n\
	movs r1, #0x80\n\
	lsls r1, r1, #9\n\
_08008202:\n\
	str r1, [r7, #0x3c]\n\
_08008204:\n\
	adds r0, r7, #0\n\
	mov r1, sl\n\
	bl hitbox_08007674\n\
	ldr r0, [r7, #0x24]\n\
	cmp r0, #0\n\
	bne _0800821A\n\
	mov r1, sl\n\
	ldr r0, [r1, #0x24]\n\
	cmp r0, #0\n\
	beq _080082D2\n\
_0800821A:\n\
	ldr r0, [r7, #0x14]\n\
	cmp r0, #0\n\
	bne _08008228\n\
	mov r2, sl\n\
	ldr r0, [r2, #0x14]\n\
	cmp r0, #0\n\
	beq _080082D2\n\
_08008228:\n\
	mov r3, r8\n\
	ldr r0, [r3, #0xc]\n\
	mov r1, sb\n\
	ldr r5, [r1, #0xc]\n\
	subs r0, r0, r5\n\
	str r0, [sp]\n\
	ldr r4, [r3, #0x10]\n\
	ldr r6, [r1, #0x10]\n\
	subs r4, r4, r6\n\
	str r4, [sp, #4]\n\
	ldrh r2, [r1, #0x14]\n\
	muls r0, r2, r0\n\
	ldrh r1, [r3, #0x14]\n\
	adds r1, r1, r2\n\
	bl __divsi3\n\
	adds r5, r5, r0\n\
	str r5, [sp, #8]\n\
	mov r3, sb\n\
	ldrh r2, [r3, #0x16]\n\
	adds r0, r2, #0\n\
	muls r0, r4, r0\n\
	mov r3, r8\n\
	ldrh r1, [r3, #0x16]\n\
	adds r1, r1, r2\n\
	bl __divsi3\n\
	adds r6, r6, r0\n\
	add r5, sp, #8\n\
	str r6, [r5, #4]\n\
	ldr r0, [sp]\n\
	adds r1, r0, #0\n\
	muls r1, r0, r1\n\
	adds r0, r1, #0\n\
	ldr r1, [sp, #4]\n\
	adds r2, r1, #0\n\
	muls r2, r1, r2\n\
	adds r1, r2, #0\n\
	adds r0, r0, r1\n\
	bl Sqrt\n\
	adds r4, r0, #0\n\
	lsls r4, r4, #0x10\n\
	lsrs r4, r4, #0x10\n\
	ldr r0, [sp]\n\
	lsls r0, r0, #8\n\
	adds r1, r4, #0\n\
	bl __divsi3\n\
	str r0, [sp]\n\
	ldr r0, [sp, #4]\n\
	lsls r0, r0, #8\n\
	adds r1, r4, #0\n\
	bl __divsi3\n\
	str r0, [sp, #4]\n\
	ldr r3, [r7, #0x24]\n\
	cmp r3, #0\n\
	beq _080082AE\n\
	ldr r0, [r7, #0x14]\n\
	cmp r0, #0\n\
	beq _080082AE\n\
	adds r0, r7, #0\n\
	adds r1, r5, #0\n\
	mov r2, sp\n\
	bl _call_via_r3\n\
_080082AE:\n\
	mov r0, sl\n\
	ldr r3, [r0, #0x24]\n\
	cmp r3, #0\n\
	beq _080082D2\n\
	ldr r0, [r0, #0x14]\n\
	cmp r0, #0\n\
	beq _080082D2\n\
	ldr r0, [sp]\n\
	rsbs r0, r0, #0\n\
	str r0, [sp]\n\
	ldr r0, [sp, #4]\n\
	rsbs r0, r0, #0\n\
	str r0, [sp, #4]\n\
	mov r0, sl\n\
	adds r1, r5, #0\n\
	mov r2, sp\n\
	bl _call_via_r3\n\
_080082D2:\n\
	add sp, #0x10\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
     .syntax divided\n");
}
