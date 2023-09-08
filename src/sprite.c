#include "sprite.h"

#include "entity.h"
#include "global.h"
#include "overworld.h"
#include "story.h"
#include "task.h"

void ResetPivot(struct Pivot *pivot, struct Coord *c, u32 _, void *nullVal) {
  static const struct Coord offset = {0x0, 0x0};
  pivot->coord = c;
  pivot->offset = (struct Coord *)&offset;
  pivot->_ = nullVal;
}

static const s16 s16_ARRAY_08338cd4[12] = {
    0x0400, 0x0800, 0x1000, 0x2000, 0x0800, 0x1000, 0x1000, 0x2000, 0x0400, 0x0400, 0x0800, 0x1000,
};

static const s16 s16_ARRAY_08338cec[36] = {
    0x0400, 0x0800, 0x1000, 0x2000, 0x0400, 0x0400, 0x0800, 0x1000, 0x0800, 0x1000, 0x1000, 0x2000, 0x0001, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFC00, 0xF000, 0x1800, 0x2000, 0x0001, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFC00, 0xF000, 0x1800, 0x2000,
};

#if MODERN == 0
static void unused_080046ac(u16 *param_1) {
  s16 val1;
  s16 val2;
  param_1[0] = 0;
  param_1[1] = 0;

  val1 = 0x280;
  param_1[2] = val1;
  val2 = 0x1c0;
  param_1[3] = val2;
  param_1[4] = (val1 >> 1);
  param_1[5] = (val2 >> 1);
}
#endif

#if MODERN == 0
NAKED static void unused_080046c8(void) { INCCODE("asm/unused/unused_080046c8.inc"); }
#endif

void CreateDrawPivot(struct DrawPivot *dp, struct Pivot *p, void *_ UNUSED) {
  if (p != NULL) {
    (dp->coord).x = p->coord->x;
    (dp->coord).y = p->coord->y;

    (dp->lefttop).x = PIXEL((p->coord->x >> 8) + (p->offset->x >> 8) - 120);
    (dp->lefttop).y = PIXEL((p->coord->y >> 8) + (p->offset->y >> 8) - 80);

    (dp->offset).x = p->offset->x;
    (dp->offset).y = p->offset->y;
    return;
  }

  (dp->coord).x = (dp->coord).y = 0;
  (dp->lefttop).x = (dp->lefttop).y = 0;
  (dp->offset).x = (dp->offset).y = 0;
}

void SetTaskCallback(struct Task *t, void *cb) {
  t->fn = cb;
  return;
}

// Unused
static void clearTaskCallback(struct Sprite *s) {
  s->fn = NULL;
  return;
}

void FUN_08004730(struct Sprite *s) {
  s->p = NULL;
  return;
}

#if MODERN == 0
static void unused_08004738(u32 *a, u32 *b) {
  *b = *a;
  *a = (u32)b;
}
#endif

#if MODERN == 0
void unused_08004740(u32 *a, u32 b, u32 *c) {
  *c = *a;
  *a = b;
}
#endif

void InitNonAffineSprite(struct Sprite *s, struct MetaspriteHeader *sprites, struct Coord *c) {
  // Clear 8..32 bytes
  u32 src = 0;
  u32 *dest = (u32 *)&s->sprites;
  CpuFastFill(src, dest, 0);
  CpuFill32(src, dest, 24);

  SetTaskCallback((struct Task *)s, TaskCB_DrawNoAffineSprite);
  (s->oam).mosaic = 1;
  (s->oam).priority = 2;
  s->sprites = sprites;
  s->c = c;
}

void InitRotatableSprite(struct Sprite *s, struct MetaspriteHeader *sprites, struct Coord *c) {
  // Clear 8..32 bytes
  u32 src = 0;
  u32 *dest = (u32 *)&s->sprites;
  CpuFastFill(src, dest, 0);
  CpuFill32(src, dest, 24);

  SetTaskCallback((struct Task *)s, TaskCB_DrawRotatableSprite);
  (s->oam).mosaic = 1;
  (s->oam).priority = 2;
  s->sprites = sprites;
  s->c = c;
  (s->oam).affineMode = ST_OAM_AFFINE_DOUBLE;
}

void InitScalerotSprite1(struct Sprite *s, struct MetaspriteHeader *sprites, struct Coord *c) {
  // Clear 8..32 bytes
  u32 src = 0;
  u32 *dest = (u32 *)&s->sprites;
  CpuFastFill(src, dest, 0);
  CpuFill32(src, dest, 24);

  SetTaskCallback((struct Task *)s, TaskCB_SetMetaspriteTileNum1);
  (s->oam).mosaic = 1;
  (s->oam).priority = 2;
  s->sprites = sprites;
  s->c = c;
  s->mag.x = 0x100;
  s->mag.y = 0x100;
  (s->oam).affineMode = ST_OAM_AFFINE_DOUBLE;
}

void InitScalerotSprite2(struct Sprite *s, struct MetaspriteHeader *sprites, struct Coord *c) {
  CpuFastFill(0, s, 32);
  { vu8 _; }
  SetTaskCallback((struct Task *)s, TaskCB_SetMetaspriteTileNum2);
  (s->oam).mosaic = 1;
  (s->oam).priority = 2;
  s->sprites = sprites;
  s->c = c;
  s->mag.x = 0x100;
  s->mag.y = 0x100;
  (s->oam).affineMode = ST_OAM_AFFINE_NORMAL;
}

NAKED void TaskCB_SetMetaspriteTileNum1(struct Sprite *s, struct DrawPivot *r1) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x20\n\
	str r1, [sp]\n\
	mov ip, r0\n\
	ldrb r1, [r0, #0x1a]\n\
	lsls r1, r1, #2\n\
	ldr r2, [r0, #8]\n\
	adds r1, r2, r1\n\
	ldrh r0, [r1]\n\
	adds r2, r2, r0\n\
	str r2, [sp, #4]\n\
	ldr r2, _08004AD0 @ =gOamManager\n\
	movs r3, #0x80\n\
	lsls r3, r3, #3\n\
	adds r0, r2, r3\n\
	ldr r4, [r0]\n\
	str r4, [sp, #8]\n\
	subs r0, r0, r4\n\
	lsrs r0, r0, #3\n\
	ldrb r1, [r1, #2]\n\
	cmp r0, r1\n\
	bhs _0800492E\n\
	b _08004ABE\n\
_0800492E:\n\
	str r1, [sp, #0xc]\n\
	cmp r1, #0\n\
	bne _08004936\n\
	b _08004AB2\n\
_08004936:\n\
	mov r0, ip\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [sp, #0x1c]\n\
_0800493C:\n\
	mov r2, ip\n\
	ldrb r1, [r2, #0x18]\n\
	ldrb r0, [r2, #0x19]\n\
	eors r1, r0\n\
	lsls r2, r1, #8\n\
	subs r2, r2, r1\n\
	mov r3, ip\n\
	ldrb r0, [r3, #0x1b]\n\
	eors r2, r0\n\
	adds r2, r2, r1\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	ldr r4, [sp, #4]\n\
	ldr r0, [r4]\n\
	lsls r1, r0, #0x10\n\
	lsrs r1, r1, #0x1e\n\
	lsls r1, r1, #2\n\
	lsls r0, r0, #0x12\n\
	lsrs r0, r0, #0x1e\n\
	orrs r1, r0\n\
	movs r0, #2\n\
	ldrsb r0, [r4, r0]\n\
	lsls r0, r0, #8\n\
	str r0, [sp, #0x10]\n\
	lsls r1, r1, #1\n\
	ldr r3, _08004AD4 @ =s16_ARRAY_08338cd4\n\
	adds r0, r1, r3\n\
	movs r4, #0\n\
	ldrsh r0, [r0, r4]\n\
	ldr r3, [sp, #0x10]\n\
	adds r3, r3, r0\n\
	mov sl, r3\n\
	ldr r4, [sp, #4]\n\
	movs r3, #3\n\
	ldrsb r3, [r4, r3]\n\
	lsls r3, r3, #8\n\
	ldr r0, _08004AD8 @ =s16_ARRAY_08338cec\n\
	adds r1, r1, r0\n\
	movs r4, #0\n\
	ldrsh r0, [r1, r4]\n\
	adds r0, r0, r3\n\
	mov r8, r0\n\
	mov r0, ip\n\
	ldrb r7, [r0, #0x18]\n\
	lsls r5, r7, #0x1f\n\
	asrs r5, r5, #0x1f\n\
	mov r1, sl\n\
	eors r5, r1\n\
	adds r5, r5, r7\n\
	lsls r0, r2, #1\n\
	ldr r4, _08004ADC @ =gSineTable\n\
	adds r0, r0, r4\n\
	movs r4, #0\n\
	ldrsh r1, [r0, r4]\n\
	str r1, [sp, #0x14]\n\
	muls r5, r1, r5\n\
	mov r0, ip\n\
	ldrh r0, [r0, #0x1c]\n\
	str r0, [sp, #0x18]\n\
	muls r5, r0, r5\n\
	asrs r5, r5, #8\n\
	mov r1, ip\n\
	ldrb r6, [r1, #0x19]\n\
	lsls r4, r6, #0x1f\n\
	asrs r4, r4, #0x1f\n\
	mov r0, r8\n\
	eors r4, r0\n\
	adds r4, r4, r6\n\
	adds r2, #0x40\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x17\n\
	ldr r1, _08004ADC @ =gSineTable\n\
	adds r2, r2, r1\n\
	movs r0, #0\n\
	ldrsh r2, [r2, r0]\n\
	muls r4, r2, r4\n\
	mov r1, ip\n\
	ldrh r1, [r1, #0x1e]\n\
	mov sb, r1\n\
	mov r0, sb\n\
	muls r0, r4, r0\n\
	adds r4, r0, #0\n\
	asrs r4, r4, #8\n\
	adds r5, r5, r4\n\
	asrs r5, r5, #8\n\
	mov r1, r8\n\
	subs r3, r3, r1\n\
	lsls r3, r3, #1\n\
	adds r5, r5, r3\n\
	asrs r5, r5, #8\n\
	ldr r3, [sp, #0x1c]\n\
	ldr r0, [r3, #4]\n\
	ldr r4, [sp]\n\
	ldr r1, [r4, #0xc]\n\
	subs r0, r0, r1\n\
	asrs r0, r0, #8\n\
	adds r5, r5, r0\n\
	adds r0, r5, #0\n\
	adds r0, #0x40\n\
	cmp r0, #0xdf\n\
	bhi _08004A9C\n\
	lsls r3, r7, #0x1f\n\
	asrs r3, r3, #0x1f\n\
	mov r0, sl\n\
	eors r3, r0\n\
	adds r3, r3, r7\n\
	muls r3, r2, r3\n\
	ldr r1, [sp, #0x18]\n\
	muls r3, r1, r3\n\
	asrs r3, r3, #8\n\
	lsls r4, r6, #0x1f\n\
	asrs r4, r4, #0x1f\n\
	mov r2, r8\n\
	eors r4, r2\n\
	adds r4, r4, r6\n\
	ldr r1, [sp, #0x14]\n\
	rsbs r0, r1, #0\n\
	muls r4, r0, r4\n\
	mov r2, sb\n\
	muls r2, r4, r2\n\
	adds r4, r2, #0\n\
	asrs r4, r4, #8\n\
	adds r3, r3, r4\n\
	asrs r3, r3, #8\n\
	ldr r4, [sp, #0x10]\n\
	mov r1, sl\n\
	subs r0, r4, r1\n\
	lsls r0, r0, #1\n\
	adds r3, r3, r0\n\
	asrs r3, r3, #8\n\
	ldr r2, [sp, #0x1c]\n\
	ldr r0, [r2]\n\
	ldr r4, [sp]\n\
	ldr r1, [r4, #8]\n\
	subs r0, r0, r1\n\
	asrs r0, r0, #8\n\
	adds r3, r3, r0\n\
	adds r1, r3, #0\n\
	adds r1, #0x80\n\
	ldr r0, _08004AE0 @ =0x0000016F\n\
	cmp r1, r0\n\
	bhi _08004A9C\n\
	mov r0, ip\n\
	ldr r2, [r0, #0x10]\n\
	ldr r4, [sp, #4]\n\
	ldrh r1, [r4]\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #6\n\
	ands r0, r1\n\
	lsls r4, r0, #0x12\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #8\n\
	ands r0, r1\n\
	orrs r4, r0\n\
	movs r0, #0xff\n\
	ands r5, r0\n\
	orrs r4, r5\n\
	ldr r0, _08004AE4 @ =0x000001FF\n\
	ands r3, r0\n\
	lsls r0, r3, #0x10\n\
	orrs r4, r0\n\
	orrs r2, r4\n\
	ldr r0, [sp, #8]\n\
	str r2, [r0]\n\
	mov r2, ip\n\
	ldrh r1, [r2, #0x14]\n\
	strh r1, [r0, #4]\n\
	ldr r3, [sp, #4]\n\
	ldrh r2, [r3]\n\
	ldr r0, _08004AE8 @ =0x000003FF\n\
	ands r0, r2\n\
	adds r1, r1, r0\n\
	ldr r4, [sp, #8]\n\
	strh r1, [r4, #4]\n\
	adds r4, #8\n\
	str r4, [sp, #8]\n\
_08004A9C:\n\
	ldr r0, [sp, #4]\n\
	adds r0, #4\n\
	str r0, [sp, #4]\n\
	ldr r0, [sp, #0xc]\n\
	subs r0, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	str r0, [sp, #0xc]\n\
	cmp r0, #0\n\
	beq _08004AB2\n\
	b _0800493C\n\
_08004AB2:\n\
	ldr r1, _08004AD0 @ =gOamManager\n\
	movs r2, #0x80\n\
	lsls r2, r2, #3\n\
	adds r0, r1, r2\n\
	ldr r3, [sp, #8]\n\
	str r3, [r0]\n\
_08004ABE:\n\
	add sp, #0x20\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08004AD0: .4byte gOamManager\n\
_08004AD4: .4byte s16_ARRAY_08338cd4\n\
_08004AD8: .4byte s16_ARRAY_08338cec\n\
_08004ADC: .4byte gSineTable\n\
_08004AE0: .4byte 0x0000016F\n\
_08004AE4: .4byte 0x000001FF\n\
_08004AE8: .4byte 0x000003FF\n\
 .syntax divided\n");
}

NAKED void TaskCB_SetMetaspriteTileNum2(struct Sprite *s, struct DrawPivot *r1) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x1c\n\
	str r1, [sp]\n\
	adds r7, r0, #0\n\
	ldrb r1, [r7, #0x1a]\n\
	lsls r1, r1, #2\n\
	ldr r2, [r7, #8]\n\
	adds r1, r2, r1\n\
	ldrh r0, [r1]\n\
	adds r2, r2, r0\n\
	str r2, [sp, #4]\n\
	ldr r2, _08004CB4 @ =gOamManager\n\
	movs r3, #0x80\n\
	lsls r3, r3, #3\n\
	adds r0, r2, r3\n\
	ldr r4, [r0]\n\
	str r4, [sp, #8]\n\
	subs r0, r0, r4\n\
	lsrs r0, r0, #3\n\
	ldrb r1, [r1, #2]\n\
	cmp r0, r1\n\
	bhs _08004B22\n\
	b _08004CA2\n\
_08004B22:\n\
	str r1, [sp, #0xc]\n\
	cmp r1, #0\n\
	bne _08004B2A\n\
	b _08004C96\n\
_08004B2A:\n\
	ldr r0, [r7, #0xc]\n\
	str r0, [sp, #0x18]\n\
_08004B2E:\n\
	ldrb r1, [r7, #0x18]\n\
	ldrb r0, [r7, #0x19]\n\
	eors r1, r0\n\
	lsls r2, r1, #8\n\
	subs r2, r2, r1\n\
	ldrb r0, [r7, #0x1b]\n\
	eors r2, r0\n\
	adds r2, r2, r1\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	ldr r1, [sp, #4]\n\
	ldr r0, [r1]\n\
	lsls r1, r0, #0x10\n\
	lsrs r1, r1, #0x1e\n\
	lsls r1, r1, #2\n\
	lsls r0, r0, #0x12\n\
	lsrs r0, r0, #0x1e\n\
	orrs r1, r0\n\
	ldr r3, [sp, #4]\n\
	movs r0, #2\n\
	ldrsb r0, [r3, r0]\n\
	lsls r0, r0, #8\n\
	str r0, [sp, #0x10]\n\
	lsls r1, r1, #1\n\
	ldr r4, _08004CB8 @ =s16_ARRAY_08338cd4\n\
	adds r0, r1, r4\n\
	movs r3, #0\n\
	ldrsh r0, [r0, r3]\n\
	ldr r4, [sp, #0x10]\n\
	adds r4, r4, r0\n\
	mov sb, r4\n\
	ldr r0, [sp, #4]\n\
	movs r3, #3\n\
	ldrsb r3, [r0, r3]\n\
	lsls r3, r3, #8\n\
	ldr r4, _08004CBC @ =s16_ARRAY_08338cec\n\
	adds r1, r1, r4\n\
	movs r4, #0\n\
	ldrsh r0, [r1, r4]\n\
	adds r0, r0, r3\n\
	mov ip, r0\n\
	ldrb r6, [r7, #0x18]\n\
	lsls r5, r6, #0x1f\n\
	asrs r5, r5, #0x1f\n\
	mov r0, sb\n\
	eors r5, r0\n\
	adds r5, r5, r6\n\
	lsls r0, r2, #1\n\
	ldr r1, _08004CC0 @ =gSineTable\n\
	adds r0, r0, r1\n\
	movs r1, #0\n\
	ldrsh r4, [r0, r1]\n\
	str r4, [sp, #0x14]\n\
	muls r5, r4, r5\n\
	ldrh r4, [r7, #0x1c]\n\
	mov sl, r4\n\
	mov r0, sl\n\
	muls r0, r5, r0\n\
	adds r5, r0, #0\n\
	asrs r5, r5, #8\n\
	ldrb r1, [r7, #0x19]\n\
	lsls r4, r1, #0x1f\n\
	asrs r4, r4, #0x1f\n\
	mov r0, ip\n\
	eors r4, r0\n\
	adds r4, r4, r1\n\
	adds r2, #0x40\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x17\n\
	ldr r0, _08004CC0 @ =gSineTable\n\
	adds r2, r2, r0\n\
	movs r0, #0\n\
	ldrsh r2, [r2, r0]\n\
	muls r4, r2, r4\n\
	ldrh r0, [r7, #0x1e]\n\
	mov r8, r0\n\
	mov r0, r8\n\
	muls r0, r4, r0\n\
	adds r4, r0, #0\n\
	asrs r4, r4, #8\n\
	adds r5, r5, r4\n\
	asrs r5, r5, #8\n\
	mov r4, ip\n\
	subs r3, r3, r4\n\
	adds r5, r5, r3\n\
	ldr r3, [sp, #0x18]\n\
	ldr r0, [r3, #4]\n\
	adds r5, r5, r0\n\
	ldr r4, [sp]\n\
	ldr r0, [r4, #0xc]\n\
	subs r5, r5, r0\n\
	asrs r5, r5, #8\n\
	adds r0, r5, #0\n\
	adds r0, #0x40\n\
	cmp r0, #0xdf\n\
	bhi _08004C80\n\
	lsls r3, r6, #0x1f\n\
	asrs r3, r3, #0x1f\n\
	mov r0, sb\n\
	eors r3, r0\n\
	adds r3, r3, r6\n\
	muls r3, r2, r3\n\
	mov r2, sl\n\
	muls r2, r3, r2\n\
	adds r3, r2, #0\n\
	asrs r3, r3, #8\n\
	lsls r4, r1, #0x1f\n\
	asrs r4, r4, #0x1f\n\
	mov r0, ip\n\
	eors r4, r0\n\
	adds r4, r4, r1\n\
	ldr r1, [sp, #0x14]\n\
	rsbs r0, r1, #0\n\
	muls r4, r0, r4\n\
	mov r2, r8\n\
	muls r2, r4, r2\n\
	adds r4, r2, #0\n\
	asrs r4, r4, #8\n\
	adds r3, r3, r4\n\
	asrs r3, r3, #8\n\
	ldr r4, [sp, #0x10]\n\
	mov r1, sb\n\
	subs r0, r4, r1\n\
	adds r3, r3, r0\n\
	ldr r2, [sp, #0x18]\n\
	ldr r0, [r2]\n\
	adds r3, r3, r0\n\
	ldr r4, [sp]\n\
	ldr r0, [r4, #8]\n\
	subs r3, r3, r0\n\
	asrs r3, r3, #8\n\
	adds r1, r3, #0\n\
	adds r1, #0x80\n\
	ldr r0, _08004CC4 @ =0x0000016F\n\
	cmp r1, r0\n\
	bhi _08004C80\n\
	ldr r2, [r7, #0x10]\n\
	ldr r0, [sp, #4]\n\
	ldrh r1, [r0]\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #6\n\
	ands r0, r1\n\
	lsls r4, r0, #0x12\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #8\n\
	ands r0, r1\n\
	orrs r4, r0\n\
	movs r0, #0xff\n\
	ands r5, r0\n\
	orrs r4, r5\n\
	ldr r0, _08004CC8 @ =0x000001FF\n\
	ands r3, r0\n\
	lsls r0, r3, #0x10\n\
	orrs r4, r0\n\
	orrs r2, r4\n\
	ldr r1, [sp, #8]\n\
	str r2, [r1]\n\
	ldrh r1, [r7, #0x14]\n\
	ldr r2, [sp, #8]\n\
	strh r1, [r2, #4]\n\
	ldr r3, [sp, #4]\n\
	ldrh r2, [r3]\n\
	ldr r0, _08004CCC @ =0x000003FF\n\
	ands r0, r2\n\
	adds r1, r1, r0\n\
	ldr r4, [sp, #8]\n\
	strh r1, [r4, #4]\n\
	adds r4, #8\n\
	str r4, [sp, #8]\n\
_08004C80:\n\
	ldr r0, [sp, #4]\n\
	adds r0, #4\n\
	str r0, [sp, #4]\n\
	ldr r0, [sp, #0xc]\n\
	subs r0, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	str r0, [sp, #0xc]\n\
	cmp r0, #0\n\
	beq _08004C96\n\
	b _08004B2E\n\
_08004C96:\n\
	ldr r1, _08004CB4 @ =gOamManager\n\
	movs r2, #0x80\n\
	lsls r2, r2, #3\n\
	adds r0, r1, r2\n\
	ldr r3, [sp, #8]\n\
	str r3, [r0]\n\
_08004CA2:\n\
	add sp, #0x1c\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08004CB4: .4byte gOamManager\n\
_08004CB8: .4byte s16_ARRAY_08338cd4\n\
_08004CBC: .4byte s16_ARRAY_08338cec\n\
_08004CC0: .4byte gSineTable\n\
_08004CC4: .4byte 0x0000016F\n\
_08004CC8: .4byte 0x000001FF\n\
_08004CCC: .4byte 0x000003FF\n\
 .syntax divided\n");
}

/**
 * @brief Create phantom face icon for Minigame HP
 * @param s ChipIcon sprite (0: 0x2031970, 1: 0x2031990, 2: 0x20319B0)
 * @param sprites 0x20319D0
 * @param r2 0x0000001
 * @param tilenum Tile Number for Chip icon
 * @note Called on Phantom minigame only in Zero3
 */
NAKED void createPhantomIcon(struct Sprite *s, struct MetaspriteHeader *sprites, u32 r2, u16 tilenum) { INCCODE("asm/todo/createPhantomIcon.inc"); }

// Only used in Phantom minigame
NAKED void phantom_minigame_08004d80(struct Sprite *s, s32 param_2) { INCCODE("asm/todo/phantom_minigame_08004d80.inc"); }
