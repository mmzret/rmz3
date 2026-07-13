#include "global.h"
#include "physics.h"
#include "vfx.h"

// 兵器再生工場のハンマー振り子のボールチェーン (の玉1つ分)

struct BallChain {
  struct Entity s;
  // props (16bytes, offset: 0x74..)
  u8 unk_74;
  s32 unk_78_y;
  Coords32 c;  // 0x7C
};
static_assert(sizeof(struct BallChain) == sizeof(struct VFX));

static void BallChain_Init(struct BallChain* p);
static void BallChain_Update(struct Entity* p);
static void BallChain_Die(struct Entity* p);

// clang-format off
const VFXRoutine gBallChainRoutine = {
    [ENTITY_INIT] =      (VFXFunc)BallChain_Init,
    [ENTITY_UPDATE] =    (VFXFunc)BallChain_Update,
    [ENTITY_DIE] =       (VFXFunc)BallChain_Die,
    [ENTITY_DISAPPEAR] = (VFXFunc)DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// ボールチェーンは7つの玉が繋がっているけど、1つ生成すれば、再帰的に次の玉を生成していく
struct Entity* CreateBallChain(Coords32* c, struct Entity* e, u8 n) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_BALLCHAIN);
    p->work[0] = 0;
    p->work[1] = n;
    p->unk_28 = e;
    p->coord.x = c->x;
    p->coord.y = c->y;
  }
  return p;
}

// --------------------------------------------

static void BallChain_Init(struct BallChain* p) {
  EnableSpriteAnimation_Normal(p);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  (p->s).renderPrio = 24;
  (&(p->s).d)->y = (&(p->s).d)->y = 0;  // 多分 d.x を d.y と書き間違えている
  p->unk_74 = 0;
  if ((p->s).work[1] < 7) {
    Coords32 c = (p->s).coord;
    c.y -= PIXEL(8);
    CreateBallChain(&c, (void*)p, (p->s).work[1] + 1);
  }
  (p->c).x = (p->s).coord.x;
  (p->c).y = FUN_0800a134((p->s).coord.x, (p->s).coord.y + PIXEL(8));
  p->unk_78_y = (p->s).coord.y - (p->c).y;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = 1;
  (p->s).mode[2] = 0;
  (p->s).mode[3] = 0;
  BallChain_Update((void*)p);
}

static void nop_080bbe20(void* _ UNUSED);
static void FUN_080bbe24(struct BallChain* p);

static void BallChain_Update(struct Entity* p) {
  static const VFXFunc sUpdates[2] = {
      (VFXFunc)nop_080bbe20,
      (VFXFunc)FUN_080bbe24,
  };
  (sUpdates[p->mode[1]])((void*)p);
}

static void BallChain_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void nop_080bbe20(void* _ UNUSED) {}

NAKED static void FUN_080bbe24(struct BallChain* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	ldr r0, [r4, #0x28]\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #1\n\
	bls _080BBE48\n\
	ldr r1, _080BBE44 @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	b _080BBEB6\n\
	.align 2, 0\n\
_080BBE44: .4byte gVFXFnTable\n\
_080BBE48:\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0\n\
	beq _080BBE54\n\
	cmp r0, #1\n\
	beq _080BBE62\n\
	b _080BBEB6\n\
_080BBE54:\n\
	ldr r1, _080BBEBC @ =0x00002901\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080BBE62:\n\
	ldr r0, [r4, #0x28]\n\
	adds r0, #0x24\n\
	ldrb r0, [r0]\n\
	rsbs r0, r0, #0\n\
	adds r3, r4, #0\n\
	adds r3, #0x74\n\
	strb r0, [r3]\n\
	ldr r2, _080BBEC0 @ =gSineTable\n\
	ldrb r0, [r3]\n\
	lsls r1, r0, #1\n\
	adds r1, r1, r2\n\
	movs r7, #0\n\
	ldrsh r5, [r1, r7]\n\
	adds r0, #0x40\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r2\n\
	movs r1, #0\n\
	ldrsh r6, [r0, r1]\n\
	ldr r2, [r4, #0x78]\n\
	adds r0, r2, #0\n\
	muls r0, r5, r0\n\
	asrs r0, r0, #8\n\
	ldr r1, [r4, #0x7c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	adds r0, r2, #0\n\
	muls r0, r6, r0\n\
	asrs r0, r0, #8\n\
	adds r1, r4, #0\n\
	adds r1, #0x80\n\
	ldr r1, [r1]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
	ldrb r0, [r3]\n\
	rsbs r0, r0, #0\n\
	adds r1, r4, #0\n\
	adds r1, #0x24\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	bl UpdateEntityAnim\n\
_080BBEB6:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080BBEBC: .4byte 0x00002901\n\
_080BBEC0: .4byte gSineTable\n\
 .syntax divided\n");
}
