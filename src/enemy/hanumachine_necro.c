#include "enemy.h"
#include "global.h"

static void HanumachineNecro_Init(struct Enemy* p);
static void HanumachineNecro_Update(struct Enemy* p);
static void HanumachineNecro_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gHanumachineNecroRoutine = {
    [ENTITY_INIT] =      HanumachineNecro_Init,
    [ENTITY_UPDATE] =    HanumachineNecro_Update,
    [ENTITY_DIE] =       HanumachineNecro_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

struct Enemy* CreateEnemy50(struct Boss* hanu) {
  struct Enemy* p = (struct Enemy*)AllocEntityFirst(gZakoHeaderPtr);
  if (p != NULL) {
    bool8 xflip;

    (p->s).taskCol = 24;
    INIT_ZAKO_ROUTINE(p, ENEMY_HANUMACHINE_NECRO);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).coord = (hanu->s).coord;
    (p->s).unk_28 = &hanu->s;
    xflip = (((hanu->s).flags >> 4) & 1) != 0;
    if (xflip) {
      (p->s).flags |= X_FLIP;
    } else {
      (p->s).flags &= ~X_FLIP;
    }
    {
      register bool8 tmp asm("r1") = xflip;
      (p->s).spr.oam.xflip = (p->s).spr.xflip = tmp;
      (p->s).work[0] = 0;
      (p->s).work[1] = 0;
    }
    return p;
  } else {
    return NULL;
  }
}

// --------------------------------------------

static void HanumachineNecro_Init(struct Enemy* p) {
  struct Boss* hanu;

  hanu = (struct Boss*)(p->s).unk_28;
  InitNonAffineMotion(&p->s);
  ResetDynamicMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetMotion(&p->s, MOTION(DM181_HANUMACHINE, 4));
  (p->s).flags2 |= WHITE_PAINTABLE;
  (p->s).invincibleID = (hanu->s).uniqueID;
  if ((p->s).flags & X_FLIP) {
    (p->s).d.x = -(PIXEL(1) / 4);
    (p->s).unk_coord.x = 1;
  } else {
    (p->s).d.x = PIXEL(1) / 4;
    (p->s).unk_coord.x = -1;
  }
  (p->s).work[2] = 0;
  SET_ZAKO_ROUTINE(p, ENTITY_UPDATE);
  HanumachineNecro_Update(p);
}

NAKED static void HanumachineNecro_Update(struct Enemy* p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r2, [r4, #0xf]\n\
	adds r3, r2, #0\n\
	cmp r3, #0\n\
	bne _0808A810\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r4, #0x64]\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x5c]\n\
	ldrb r0, [r4, #0x12]\n\
	adds r1, r0, #1\n\
	strb r1, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0x40\n\
	bls _0808A82A\n\
	adds r0, r2, #1\n\
	strb r0, [r4, #0xf]\n\
	strb r3, [r4, #0x12]\n\
	b _0808A82A\n\
_0808A810:\n\
	ldr r0, [r4, #0x28]\n\
	ldrb r0, [r0, #0xd]\n\
	cmp r0, #2\n\
	bls _0808A82A\n\
	ldr r1, _0808A830 @ =gEnemyFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
_0808A82A:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0808A830: .4byte gEnemyFnTable\n\
 .syntax divided\n");
}

static void HanumachineNecro_Die(struct Enemy* p) {
  (p->s).flags &= ~DISPLAY;
  SET_ZAKO_ROUTINE(p, ENTITY_EXIT);
}
