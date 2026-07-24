#include "gfx.h"
#include "global.h"
#include "renderer.h"
#include "vfx.h"

// Z x (残機数) の表示

static void TaskCB_080be5d0(struct Sprite* s, struct DrawPivot* c);

static void ExlifeIndicator_Init(struct Entity* p);
static void ExlifeIndicator_Update(struct VFX* vfx);
static void ExlifeIndicator_Die(struct Entity* p);

// clang-format off
const VFXRoutine gExlifeIndicatorRoutine = {
    [ENTITY_INIT] =      (VFXFunc)ExlifeIndicator_Init,
    [ENTITY_UPDATE] =    (VFXFunc)ExlifeIndicator_Update,
    [ENTITY_DIE] =       (VFXFunc)ExlifeIndicator_Die,
    [ENTITY_DISAPPEAR] = (VFXFunc)DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

Entity* CreateExlifeIndicator(u8 extraLife) {
  Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_EXLIFE_INDICATOR);
    p->work[0] = extraLife;
  }
  return p;
}

static void ExlifeIndicator_Init(struct Entity* p) {
  SetTaskCallback((void*)&p->spr, TaskCB_080be5d0);
  (p->spr).sprites = (struct MetaspriteHeader*)p;
  p->flags &= ~USE_COMMON_OAM_RENDERER;
  p->flags |= DISPLAY;
  LOAD_STATIC_GRAPHIC(SM060_EXLIFE_INDICATOR);
  (p->coord).x = PIXEL(0), (p->coord).y = PIXEL(148);
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->work[2] = 0;
  ExlifeIndicator_Update((void*)p);
}

NAKED static void ExlifeIndicator_Update(struct VFX* vfx) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r3, r0, #0\n\
	ldrb r4, [r3, #0x12]\n\
	adds r2, r4, #1\n\
	strb r2, [r3, #0x12]\n\
	lsls r0, r2, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0x20\n\
	bhi _080BE568\n\
	ldr r1, _080BE564 @ =gSineTable\n\
	lsls r0, r2, #0x19\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r1\n\
	movs r2, #0\n\
	ldrsh r1, [r0, r2]\n\
	movs r0, #0xdc\n\
	muls r0, r1, r0\n\
	b _080BE588\n\
	.align 2, 0\n\
_080BE564: .4byte gSineTable\n\
_080BE568:\n\
	cmp r0, #0x7e\n\
	bls _080BE58A\n\
	ldr r1, _080BE5A8 @ =gSineTable\n\
	lsls r0, r4, #0x19\n\
	movs r2, #0x84\n\
	lsls r2, r2, #0x17\n\
	adds r0, r0, r2\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r1\n\
	movs r2, #0\n\
	ldrsh r1, [r0, r2]\n\
	movs r0, #0xdc\n\
	muls r1, r0, r1\n\
	movs r0, #0xdc\n\
	lsls r0, r0, #9\n\
	subs r0, r0, r1\n\
_080BE588:\n\
	str r0, [r3, #0x54]\n\
_080BE58A:\n\
	ldrb r0, [r3, #0x12]\n\
	cmp r0, #0xa0\n\
	bne _080BE5A2\n\
	ldr r1, _080BE5AC @ =gVFXFnTable\n\
	ldrb r0, [r3, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r3, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r3, #0x14]\n\
_080BE5A2:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080BE5A8: .4byte gSineTable\n\
_080BE5AC: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

static void ExlifeIndicator_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

static void TaskCB_080be5d0(struct Sprite* s, struct DrawPivot* c) {
  // clang-format off
  static const motion_t sMotions[10] = {
    MOTION(SM060_EXLIFE_INDICATOR, 0), // Zx0
    MOTION(SM060_EXLIFE_INDICATOR, 1), // Zx1
    MOTION(SM060_EXLIFE_INDICATOR, 2), // Zx2
    MOTION(SM060_EXLIFE_INDICATOR, 3), // Zx3
    MOTION(SM060_EXLIFE_INDICATOR, 4), // Zx4
    MOTION(SM060_EXLIFE_INDICATOR, 5), // Zx5
    MOTION(SM060_EXLIFE_INDICATOR, 6), // Zx6
    MOTION(SM060_EXLIFE_INDICATOR, 7), // Zx7
    MOTION(SM060_EXLIFE_INDICATOR, 8), // Zx8
    MOTION(SM060_EXLIFE_INDICATOR, 9), // Zx9
  };
  // clang-format on
  struct VFX* p = (struct VFX*)s->sprites;
  Coords32 coord;
  coord.x = (p->s).coord.x - PIXEL(120);
  coord.x += (c->coord).x;
  coord.y = (p->s).coord.y - PIXEL(80);
  coord.y += (c->coord).y;
  EnableSpriteAnimation_Normal(p);
  SetSpriteAnimation(p, sMotions[(p->s).work[0]]);
  (p->s).spr.oam.priority = 0;
  UpdateSpriteAnimation(p);
  (p->s).spr.c = &coord;
  (s->fn)(s, c);
  SetTaskCallback((void*)&(p->s).spr, TaskCB_080be5d0);
  (p->s).spr.sprites = (struct MetaspriteHeader*)p;
  (p->s).flags &= ~USE_COMMON_OAM_RENDERER;
}
