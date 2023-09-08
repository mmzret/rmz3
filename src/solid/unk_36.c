#include "collision.h"
#include "entity.h"
#include "vfx.h"
#include "global.h"
#include "solid.h"

static const struct Rect sSize;

static void Solid36_Init(struct Solid* p);
static void Solid36_Update(struct Solid* p);
static void Solid36_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid36Routine = {
    [ENTITY_INIT] =      Solid36_Init,
    [ENTITY_MAIN] =      Solid36_Update,
    [ENTITY_DIE] =       Solid36_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

static void Solid36_Init(struct Solid* p) {
  (p->s).flags |= DISPLAY;
  InitNonAffineMotion(&p->s);
  (p->s).flags |= FLIPABLE;
  (p->s).unk_coord.y = (p->s).coord.y - PIXEL(8);
  SetMotion(&p->s, MOTION(0x97, 0x01));
  SET_SOLID_ROUTINE(p, ENTITY_MAIN);
  Solid36_Update(p);
}

NAKED static void Solid36_Update(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0x10]\n\
	lsls r1, r0, #1\n\
	adds r1, r1, r0\n\
	ldr r0, _080DC6F4 @ =gOverworld\n\
	ldr r2, _080DC6F8 @ =0x0002D02C\n\
	adds r0, r0, r2\n\
	lsls r1, r1, #5\n\
	ldrh r0, [r0]\n\
	adds r1, r1, r0\n\
	lsls r0, r1, #0x10\n\
	lsrs r0, r0, #0x10\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #1\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	cmp r1, #0xbf\n\
	bhi _080DC700\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0xd\n\
	movs r1, #0xc0\n\
	bl __udivsi3\n\
	ldr r1, _080DC6FC @ =0xFFFFB000\n\
	adds r0, r0, r1\n\
	ldr r1, [r4, #0x68]\n\
	adds r1, r1, r0\n\
	b _080DC716\n\
	.align 2, 0\n\
_080DC6F4: .4byte gOverworld\n\
_080DC6F8: .4byte 0x0002D02C\n\
_080DC6FC: .4byte 0xFFFFB000\n\
_080DC700:\n\
	subs r1, #0xc0\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0xd\n\
	movs r1, #0xc0\n\
	bl __udivsi3\n\
	ldr r2, _080DC73C @ =0xFFFFB000\n\
	adds r0, r0, r2\n\
	ldr r1, [r4, #0x68]\n\
	subs r1, r1, r0\n\
_080DC716:\n\
	str r1, [r4, #0x58]\n\
	ldr r0, _080DC740 @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0x58]\n\
	ldr r1, _080DC744 @ =0xFFFFF400\n\
	adds r0, r0, r1\n\
	ldr r1, [r4, #0x58]\n\
	cmp r1, r0\n\
	ble _080DC750\n\
	ldrb r1, [r4, #0xb]\n\
	movs r0, #8\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xb]\n\
	ldr r0, _080DC748 @ =0x083715FC\n\
	str r0, [r4, #0x30]\n\
	ldr r0, _080DC74C @ =0x0000A001\n\
	strh r0, [r4, #0x26]\n\
	b _080DC758\n\
	.align 2, 0\n\
_080DC73C: .4byte 0xFFFFB000\n\
_080DC740: .4byte pZero2\n\
_080DC744: .4byte 0xFFFFF400\n\
_080DC748: .4byte sSize\n\
_080DC74C: .4byte 0x0000A001\n\
_080DC750:\n\
	ldrb r1, [r4, #0xb]\n\
	movs r0, #0xf7\n\
	ands r0, r1\n\
	strb r0, [r4, #0xb]\n\
_080DC758:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void Solid36_Die(struct Solid* p) { return; }

static const struct Rect sSize = {0, 0x800, 0x3000, 0x1000};
