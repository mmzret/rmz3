#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"
#include "zero.h"

// 多分アナトレーの森でスイッチで動く壁

static void Solid16_Init(struct Solid* p);
static void Solid16_Update(struct Solid* p);
static void Solid16_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid16Routine = {
    [ENTITY_INIT] =      Solid16_Init,
    [ENTITY_UPDATE] =    Solid16_Update,
    [ENTITY_DIE] =       Solid16_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

struct Solid* FUN_080cedc0(u8 n) {
  struct Solid* p = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 30;
    INIT_SOLID_ROUTINE(p, SOLID_UNK_016);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).work[0] = n;
    (p->s).work[1] = 0;
  }
  return p;
}

void FUN_080cee14(u8 n, s32 x, s32 y) {
  struct Solid* p = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 30;
    INIT_SOLID_ROUTINE(p, SOLID_UNK_016);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).coord.x = x + PIXEL(24);
    (p->s).coord.y = y;
    (p->s).work[0] = n;
    (p->s).work[1] = 1;
    (p->s).flags |= DISPLAY;
    InitNonAffineMotion(&p->s);
    SetMotion(&p->s, MOTION(SM112_ANATRE_CUBE, 15));
    UpdateMotionGraphic(&p->s);
    AppendQuake(5, &(p->s).coord);
  }
}

// --------------------------------------------

static void FUN_080cefb4(struct Body* body, struct Coord* c1, struct Coord* c2);

static void Solid16_Init(struct Solid* p) {
  static const struct Collision sCollision = {
    kind : DRP,
    faction : FACTION_ENEMY,
    damage : 0,
    LAYER(RECOIL_PUSHABLE),
    hitzone : 0xFF,
    remaining : 0,
    range : {PIXEL(0), PIXEL(0), -PIXEL(1), -PIXEL(96)},
  };

  (p->s).flags |= FLIPABLE;
  if ((p->s).work[1] == 0) {
    INIT_BODY(p, &sCollision, 0, FUN_080cefb4);
    (p->s).flags2 &= ~WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
    Solid16_Update(p);
  } else {
    SET_SOLID_ROUTINE(p, ENTITY_DIE);
    Solid16_Die(p);
  }
}

static void Solid16_Update(struct Solid* p) {
  struct Entity* player = &pZero2->s;
  (p->s).coord.x = (player->coord).x;
  (p->s).coord.y = (player->coord).y;
}

static void Solid16_Die(struct Solid* p) {
  switch ((p->s).mode[1]) {
    case 0: {
      struct Coord* d = &(p->s).d;
      d->x = d->y = 0;
      (p->s).mode[1]++;
      break;
    }
    case 1: {
      s32 y;
      UpdateMotionGraphic(&p->s);
      if ((p->s).d.y < PIXEL(7)) {
        (p->s).d.y += PIXEL(1) / 8;
      }
      y = (p->s).coord.y + (p->s).d.y;
      (p->s).coord.y = y;
      (p->s).unk_coord.y = y;
      if (CalcFromCamera(&gStageRun.vm.camera, &(p->s).coord) > PIXEL(48)) {
        (p->s).flags &= ~DISPLAY;
        SET_SOLID_ROUTINE(p, ENTITY_EXIT);
      }
      break;
    }
  }
}

// --------------------------------------------

NAKED static void FUN_080cefb4(struct Body* body, struct Coord* c1, struct Coord* c2) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	mov sb, r0\n\
	ldr r2, [r0, #0xc]\n\
	ldr r4, [r2, #4]\n\
	ldr r5, [r2, #8]\n\
	adds r6, r4, #0\n\
	adds r6, #0x10\n\
	ldr r3, [r5]\n\
	ldr r0, _080CEFEC @ =0xFFE3E000\n\
	adds r1, r3, r0\n\
	ldr r0, _080CEFF0 @ =0x0000EFFF\n\
	cmp r1, r0\n\
	bls _080CF08A\n\
	ldr r0, [r2, #0x2c]\n\
	ldrb r1, [r0, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080CEFF4\n\
	movs r1, #0x10\n\
	ldrsh r0, [r4, r1]\n\
	adds r7, r3, r0\n\
	b _080CEFFA\n\
	.align 2, 0\n\
_080CEFEC: .4byte 0xFFE3E000\n\
_080CEFF0: .4byte 0x0000EFFF\n\
_080CEFF4:\n\
	movs r1, #0x10\n\
	ldrsh r0, [r4, r1]\n\
	subs r7, r3, r0\n\
_080CEFFA:\n\
	movs r0, #2\n\
	ldrsh r1, [r6, r0]\n\
	ldr r0, [r5, #4]\n\
	adds r5, r0, r1\n\
	ldrh r0, [r6, #4]\n\
	lsrs r0, r0, #1\n\
	mov sl, r0\n\
	ldrh r0, [r6, #6]\n\
	lsrs r0, r0, #1\n\
	mov r8, r0\n\
	adds r0, r7, #0\n\
	adds r1, r5, #0\n\
	bl FUN_08010d70\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080CF020\n\
	adds r0, r7, #0\n\
	b _080CF074\n\
_080CF020:\n\
	mov r1, sl\n\
	adds r4, r7, r1\n\
	mov r0, r8\n\
	adds r6, r5, r0\n\
	adds r0, r4, #0\n\
	adds r1, r6, #0\n\
	bl FUN_08010d70\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080CF05A\n\
	mov r1, r8\n\
	subs r5, r5, r1\n\
	adds r0, r4, #0\n\
	adds r1, r5, #0\n\
	bl FUN_08010d70\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080CF072\n\
	mov r0, sl\n\
	subs r4, r7, r0\n\
	adds r0, r4, #0\n\
	adds r1, r6, #0\n\
	bl FUN_08010d70\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080CF064\n\
_080CF05A:\n\
	adds r0, r4, #0\n\
	adds r1, r6, #0\n\
	bl FUN_08010dd8\n\
	b _080CF08A\n\
_080CF064:\n\
	adds r0, r4, #0\n\
	adds r1, r5, #0\n\
	bl FUN_08010d70\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080CF07C\n\
_080CF072:\n\
	adds r0, r4, #0\n\
_080CF074:\n\
	adds r1, r5, #0\n\
	bl FUN_08010dd8\n\
	b _080CF08A\n\
_080CF07C:\n\
	mov r1, sb\n\
	ldr r0, [r1, #0x18]\n\
	movs r1, #2\n\
	rsbs r1, r1, #0\n\
	ands r0, r1\n\
	mov r1, sb\n\
	str r0, [r1, #0x18]\n\
_080CF08A:\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}
