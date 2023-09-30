#include "entity.h"
#include "global.h"
#include "vfx.h"

// レジスタンスベースに振ってくる雪1つ1つ

static void Snow_Init(struct VFX *p);
static void Snow_Update(struct VFX *p);
static void Snow_Die(struct VFX *p);

// clang-format off
const VFXRoutine gSnowRoutine = {
    [ENTITY_INIT] =      Snow_Init,
    [ENTITY_MAIN] =      Snow_Update,
    [ENTITY_DIE] =       Snow_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void CreateSnow(struct Coord *c, u32 n) {
  struct VFX *g = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (g != NULL) {
    (g->s).taskCol = 1;
    INIT_VFX_ROUTINE(g, VFX_UNK_080);
    (g->s).tileNum = 0;
    (g->s).palID = 0;
    (g->s).coord = *c;
    (g->props).snow.unk_0 = n;
    (g->s).work[0] = 0;
    (g->s).work[1] = 0;
  }
}

// --------------------------------------------

NAKED static void Snow_Init(struct VFX *p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r5, r0, #0\n\
	ldr r1, _080C91F4 @ =gVFXFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	adds r0, r5, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r0, [r5, #0xa]\n\
	movs r4, #1\n\
	movs r6, #0\n\
	orrs r0, r4\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	movs r1, #0xb3\n\
	lsls r1, r1, #8\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	adds r0, r5, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r2, _080C91F8 @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _080C91FC @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _080C9200 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r2, r0, #0x11\n\
	ands r2, r4\n\
	cmp r2, #0\n\
	beq _080C9204\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _080C920A\n\
	.align 2, 0\n\
_080C91F4: .4byte gVFXFnTable\n\
_080C91F8: .4byte RNG_0202f388\n\
_080C91FC: .4byte 0x000343FD\n\
_080C9200: .4byte 0x00269EC3\n\
_080C9204:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080C920A:\n\
	strb r0, [r5, #0xa]\n\
	movs r4, #1\n\
	adds r1, r2, #0\n\
	adds r0, r5, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r3, r5, #0\n\
	adds r3, #0x4a\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	ldr r2, _080C924C @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _080C9250 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _080C9254 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r2, r0, #0x11\n\
	ands r2, r4\n\
	adds r4, r3, #0\n\
	cmp r2, #0\n\
	beq _080C9258\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #0x20\n\
	orrs r0, r1\n\
	b _080C925E\n\
	.align 2, 0\n\
_080C924C: .4byte RNG_0202f388\n\
_080C9250: .4byte 0x000343FD\n\
_080C9254: .4byte 0x00269EC3\n\
_080C9258:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xdf\n\
	ands r0, r1\n\
_080C925E:\n\
	strb r0, [r5, #0xa]\n\
	adds r1, r2, #0\n\
	adds r2, r5, #0\n\
	adds r2, #0x4d\n\
	movs r3, #0\n\
	strb r1, [r2]\n\
	lsls r1, r1, #5\n\
	ldrb r2, [r4]\n\
	movs r0, #0x21\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r4]\n\
	str r3, [r5, #0x5c]\n\
	movs r0, #0x80\n\
	str r0, [r5, #0x60]\n\
	ldr r0, [r5, #0x54]\n\
	str r0, [r5, #0x64]\n\
	strb r3, [r5, #0x12]\n\
	adds r0, r5, #0\n\
	bl Snow_Update\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

// --------------------------------------------

NON_MATCH static void Snow_Update(struct VFX *p) {
#if MODERN
  UpdateMotionGraphic(&p->s);
  (p->s).coord.y += (p->s).d.y;
  (p->s).coord.x = gSineTable[(p->s).work[2]] * 8;
  (p->s).coord.x += (p->s).unk_coord.x;
  (p->s).coord.x += (p->s).d.x;
  (p->s).work[2] += 3;

  RNG_0202f388 = LCG(RNG_0202f388);
  (p->s).d.x += 0x100 - (RNG_0202f388 >> 16);
  if ((p->props).snow.unk_0-- == 0) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    Snow_Die(p);
  }
#else
  INCCODE("asm/wip/Snow_Update.inc");
#endif
}

// --------------------------------------------

static void Snow_Die(struct VFX *p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }
