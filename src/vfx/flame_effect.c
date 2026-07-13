#include "entity.h"
#include "global.h"
#include "vfx.h"
#include "vfx/element_effect.h"

static void FlameEffect_Init(struct Entity* p);
static void FlameEffect_Update(struct VFX* p);
static void FlameEffect_Die(struct Entity* p);

// clang-format off
const VFXRoutine gFlameEffectRoutine = {
    [ENTITY_INIT] =      (void*)FlameEffect_Init,
    [ENTITY_UPDATE] =    (void*)FlameEffect_Update,
    [ENTITY_DIE] =       (void*)FlameEffect_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct ElementEffect* CreateFlameEffect(struct Entity* e, Coords32* c, u8 r2) {
  struct ElementEffect* p = (struct ElementEffect*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_FLAME_EFFECT);
    (p->s).unk_28 = e;
    (p->c).x = c->x, (p->c).y = c->y;
    (p->s).work[2] = r2;
    *((u8*)&(p->c).y) = r2;
  }
  return p;
}

static void FlameEffect_Init(struct Entity* p) {
  struct Entity* q = p->unk_28;
  EnableSpriteAnimation_Normal(p);
  if (q->flags & USE_COMMON_OAM_RENDERER) (p->spr).oam.priority = (q->spr).oam.priority;
  p->renderPrio = 0;
  ForceEntityPalette(p, 14);
  SET_XFLIP(p, (RANDOM(RNG_0202f388) & 1));
  SetSpriteAnimation(p, MOTION(SM027_FLAME_EFFECT, 7));
  p->flags |= DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  FlameEffect_Update((void*)p);
}

NAKED static void FlameEffect_Update(struct VFX* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	ldr r5, [r4, #0x28]\n\
	ldrb r0, [r5, #0xc]\n\
	cmp r0, #1\n\
	bls _080B4E90\n\
	ldrb r1, [r4, #0x12]\n\
	cmp r1, #0xf\n\
	bls _080B4E90\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	strb r0, [r4, #0x12]\n\
_080B4E90:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r2, r0, #1\n\
	strb r2, [r4, #0x12]\n\
	ldr r0, _080B4ED4 @ =gElFxManager\n\
	ldr r0, [r0]\n\
	ldr r1, _080B4ED8 @ =0x00FF00FF\n\
	ands r0, r1\n\
	cmp r0, #2\n\
	bne _080B4EE6\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrb r0, [r0]\n\
	lsls r1, r0, #0x18\n\
	lsls r0, r2, #0x18\n\
	lsrs r3, r0, #0x18\n\
	lsrs r0, r1, #0x19\n\
	cmp r3, r0\n\
	bhi _080B4ECA\n\
	lsrs r0, r1, #0x1a\n\
	cmp r3, r0\n\
	bls _080B4EC2\n\
	movs r0, #1\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _080B4ECA\n\
_080B4EC2:\n\
	movs r0, #3\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	bne _080B4EDC\n\
_080B4ECA:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	b _080B4F08\n\
	.align 2, 0\n\
_080B4ED4: .4byte gElFxManager\n\
_080B4ED8: .4byte 0x00FF00FF\n\
_080B4EDC:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	b _080B4F08\n\
_080B4EE6:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080B4F04 @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	b _080B4FF4\n\
	.align 2, 0\n\
_080B4F04: .4byte gVFXFnTable\n\
_080B4F08:\n\
	ldrb r3, [r5, #0xa]\n\
	movs r0, #0x40\n\
	ands r0, r3\n\
	mov ip, r3\n\
	cmp r0, #0\n\
	beq _080B4F94\n\
	adds r0, r5, #0\n\
	adds r0, #0x24\n\
	ldrb r1, [r0]\n\
	ldr r2, _080B4F4C @ =gSineTable\n\
	movs r0, #0xff\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r2\n\
	movs r6, #0\n\
	ldrsh r7, [r0, r6]\n\
	movs r0, #0x3f\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r2\n\
	movs r1, #0\n\
	ldrsh r6, [r0, r1]\n\
	movs r0, #0x30\n\
	ands r0, r3\n\
	lsrs r0, r0, #4\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080B4F50\n\
	ldr r0, [r4, #0x74]\n\
	rsbs r3, r0, #0\n\
	b _080B4F52\n\
	.align 2, 0\n\
_080B4F4C: .4byte gSineTable\n\
_080B4F50:\n\
	ldr r3, [r4, #0x74]\n\
_080B4F52:\n\
	movs r0, #0x30\n\
	mov r1, ip\n\
	ands r0, r1\n\
	lsrs r0, r0, #4\n\
	movs r1, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080B4F68\n\
	ldr r0, [r4, #0x78]\n\
	rsbs r2, r0, #0\n\
	b _080B4F6A\n\
_080B4F68:\n\
	ldr r2, [r4, #0x78]\n\
_080B4F6A:\n\
	adds r0, r6, #0\n\
	muls r0, r3, r0\n\
	asrs r0, r0, #8\n\
	ldr r1, [r5, #0x54]\n\
	adds r1, r1, r0\n\
	adds r0, r7, #0\n\
	muls r0, r2, r0\n\
	asrs r0, r0, #8\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x54]\n\
	adds r0, r7, #0\n\
	muls r0, r3, r0\n\
	asrs r0, r0, #8\n\
	ldr r1, [r5, #0x58]\n\
	subs r1, r1, r0\n\
	adds r0, r6, #0\n\
	muls r0, r2, r0\n\
	asrs r0, r0, #8\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x58]\n\
	b _080B4FD2\n\
_080B4F94:\n\
	movs r0, #0x30\n\
	ands r0, r3\n\
	lsrs r0, r0, #4\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080B4FAA\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r4, #0x74]\n\
	subs r0, r0, r1\n\
	b _080B4FB0\n\
_080B4FAA:\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r4, #0x74]\n\
	adds r0, r0, r1\n\
_080B4FB0:\n\
	str r0, [r4, #0x54]\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #0x30\n\
	ands r1, r0\n\
	lsrs r1, r1, #4\n\
	movs r0, #2\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _080B4FCA\n\
	ldr r0, [r5, #0x58]\n\
	ldr r1, [r4, #0x78]\n\
	subs r0, r0, r1\n\
	b _080B4FD0\n\
_080B4FCA:\n\
	ldr r0, [r5, #0x58]\n\
	ldr r1, [r4, #0x78]\n\
	adds r0, r0, r1\n\
_080B4FD0:\n\
	str r0, [r4, #0x58]\n\
_080B4FD2:\n\
	adds r0, r4, #0\n\
	bl UpdateEntityAnim\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0\n\
	beq _080B4FE4\n\
	ldrb r0, [r5, #0xc]\n\
	cmp r0, #2\n\
	bls _080B4FF6\n\
_080B4FE4:\n\
	ldr r1, _080B4FFC @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
_080B4FF4:\n\
	str r0, [r4, #0x14]\n\
_080B4FF6:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B4FFC: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

static void FlameEffect_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}
