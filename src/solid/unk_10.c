#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"
#include "zero.h"

// 多分、旧居住区の乗ると落下する足場

static const struct Rect sSize;

static const struct Collision sCollisions1[2];
static const struct Collision sCollisions2[2];

static const s32 s32_ARRAY_08370170[8];
static const s32 s32_ARRAY_08370190[8];

static void Solid10_Init(struct Solid* p);
static void Solid10_Update(struct Solid* p);
static void Solid10_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid10Routine = {
    [ENTITY_INIT] =      Solid10_Init,
    [ENTITY_UPDATE] =    Solid10_Update,
    [ENTITY_DIE] =       Solid10_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

static void Solid10_Init(struct Solid* p) {
  struct Coord* velocity;

  if (GetMetatileAttr((p->s).coord.x, (p->s).coord.y) == 0) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    (p->body).status = 0;
    (p->body).prevStatus = 0;
    (p->body).invincibleTime = 0;
    (p->s).flags &= ~COLLIDABLE;
    SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  INIT_BODY(p, &sCollisions1[0], 0, NULL);
  velocity = &(p->s).d;
  velocity->x = velocity->y = 0;
  (p->s).coord.x += PIXEL(8);
  (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y) + 1;
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  Solid10_Update(p);
}

// --------------------------------------------

static void Solid10_Update(struct Solid* p) {
  if ((p->body).status & BODY_STATUS_B2) {
    struct Zero_b4* b4 = &pZero2->unk_b4;
    if ((b4->status).body != BODY_CHIP_LIGHT) {
      INIT_BODY(p, &sCollisions2[0], 0, NULL);
      (p->s).flags |= DISPLAY;
      (p->s).flags |= FLIPABLE;
      InitNonAffineMotion(&p->s);
      SetMotion(&p->s, MOTION(SM068_OLD_RESIDENTIAL_FALL_ROCK, 0) | (p->s).work[0]);
      SET_SOLID_ROUTINE(p, ENTITY_DIE);
      Solid10_Die(p);
    }
  }
}

NAKED static void Solid10_Die(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #8\n\
	adds r5, r0, #0\n\
	ldrb r0, [r5, #0xd]\n\
	cmp r0, #1\n\
	beq _080CD974\n\
	cmp r0, #1\n\
	bgt _080CD92E\n\
	cmp r0, #0\n\
	beq _080CD93A\n\
	b _080CDB26\n\
_080CD92E:\n\
	cmp r0, #2\n\
	beq _080CDA06\n\
	cmp r0, #3\n\
	bne _080CD938\n\
	b _080CDA8C\n\
_080CD938:\n\
	b _080CDB26\n\
_080CD93A:\n\
	adds r0, r5, #0\n\
	adds r0, #0x54\n\
	bl FUN_0800e308\n\
	ldrb r1, [r5, #0xb]\n\
	movs r0, #8\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xb]\n\
	ldr r0, _080CD9C0 @ =0x08370168\n\
	str r0, [r5, #0x30]\n\
	ldr r0, _080CD9C4 @ =0x00002001\n\
	strh r0, [r5, #0x26]\n\
	adds r0, r5, #0\n\
	adds r0, #0x64\n\
	str r0, [r5, #0x40]\n\
	ldr r4, _080CD9C8 @ =0x0000011D\n\
	adds r0, r4, #0\n\
	bl isSoundPlaying\n\
	cmp r0, #0\n\
	bne _080CD96A\n\
	adds r0, r4, #0\n\
	bl PlaySound\n\
_080CD96A:\n\
	movs r0, #0\n\
	strb r0, [r5, #0x12]\n\
	ldrb r0, [r5, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xd]\n\
_080CD974:\n\
	adds r0, r5, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, _080CD9CC @ =s32_ARRAY_08370170\n\
	ldrb r2, [r5, #0x12]\n\
	movs r1, #7\n\
	ands r1, r2\n\
	lsls r1, r1, #2\n\
	adds r0, r1, r0\n\
	ldr r0, [r0]\n\
	lsls r0, r0, #8\n\
	ldr r3, [r5, #0x54]\n\
	adds r0, r3, r0\n\
	str r0, [r5, #0x64]\n\
	ldr r0, _080CD9D0 @ =s32_ARRAY_08370190\n\
	adds r1, r1, r0\n\
	ldr r0, [r1]\n\
	lsls r0, r0, #8\n\
	ldr r1, [r5, #0x58]\n\
	adds r0, r1, r0\n\
	str r0, [r5, #0x68]\n\
	adds r2, #1\n\
	strb r2, [r5, #0x12]\n\
	movs r0, #3\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _080CD9F0\n\
	ldrb r0, [r5, #0x12]\n\
	lsls r0, r0, #8\n\
	adds r0, r1, r0\n\
	str r0, [sp, #4]\n\
	movs r0, #4\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	beq _080CD9D4\n\
	movs r1, #0x88\n\
	lsls r1, r1, #5\n\
	b _080CD9D6\n\
	.align 2, 0\n\
_080CD9C0: .4byte sSize\n\
_080CD9C4: .4byte 0x00002001\n\
_080CD9C8: .4byte 0x0000011D\n\
_080CD9CC: .4byte s32_ARRAY_08370170\n\
_080CD9D0: .4byte s32_ARRAY_08370190\n\
_080CD9D4:\n\
	ldr r1, _080CDAA8 @ =0xFFFFEF00\n\
_080CD9D6:\n\
	adds r0, r3, r1\n\
	str r0, [sp]\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #4]\n\
	bl GetMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080CD9F0\n\
	movs r0, #3\n\
	mov r1, sp\n\
	bl CreateSmoke\n\
_080CD9F0:\n\
	ldrb r0, [r5, #0x12]\n\
	cmp r0, #0x2c\n\
	bhi _080CD9F8\n\
	b _080CDB26\n\
_080CD9F8:\n\
	ldr r0, [r5, #0x54]\n\
	str r0, [r5, #0x64]\n\
	ldr r0, [r5, #0x58]\n\
	str r0, [r5, #0x68]\n\
	ldrb r0, [r5, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xd]\n\
_080CDA06:\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, _080CDAAC @ =0xFFFFF800\n\
	adds r4, r0, r1\n\
	str r4, [sp]\n\
	ldr r0, [r5, #0x58]\n\
	movs r7, #0x80\n\
	lsls r7, r7, #5\n\
	adds r3, r0, r7\n\
	str r3, [sp, #4]\n\
	adds r2, r5, #0\n\
	adds r2, #0x8c\n\
	ldr r0, [r2]\n\
	movs r1, #4\n\
	ands r0, r1\n\
	adds r6, r2, #0\n\
	cmp r0, #0\n\
	bne _080CDA42\n\
	adds r0, r4, #0\n\
	adds r1, r3, #0\n\
	bl PushoutToUp2\n\
	cmp r0, #0\n\
	bne _080CDA42\n\
	ldr r0, [sp]\n\
	adds r0, r0, r7\n\
	ldr r1, [sp, #4]\n\
	bl PushoutToUp2\n\
	cmp r0, #0\n\
	beq _080CDA8C\n\
_080CDA42:\n\
	movs r4, #0\n\
	str r4, [r6]\n\
	adds r0, r5, #0\n\
	adds r0, #0x90\n\
	str r4, [r0]\n\
	adds r0, #4\n\
	strb r4, [r0]\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldrb r1, [r5, #0xb]\n\
	movs r0, #0xf7\n\
	ands r0, r1\n\
	strb r0, [r5, #0xb]\n\
	ldr r1, _080CDAB0 @ =0x00004403\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	str r4, [r5, #0x60]\n\
	adds r1, r5, #0\n\
	adds r1, #0x54\n\
	movs r0, #2\n\
	bl AppendQuake\n\
	strb r4, [r5, #0x13]\n\
	movs r0, #0x41\n\
	bl isSoundPlaying\n\
	cmp r0, #0\n\
	bne _080CDA86\n\
	movs r0, #0x41\n\
	bl PlaySound\n\
_080CDA86:\n\
	ldrb r0, [r5, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xd]\n\
_080CDA8C:\n\
	ldrb r0, [r5, #0xd]\n\
	cmp r0, #3\n\
	bne _080CDABC\n\
	ldrb r1, [r5, #0x13]\n\
	adds r0, r1, #1\n\
	strb r0, [r5, #0x13]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080CDAB4\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	b _080CDABA\n\
	.align 2, 0\n\
_080CDAA8: .4byte 0xFFFFEF00\n\
_080CDAAC: .4byte 0xFFFFF800\n\
_080CDAB0: .4byte 0x00004403\n\
_080CDAB4:\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #1\n\
	orrs r0, r1\n\
_080CDABA:\n\
	strb r0, [r5, #0xa]\n\
_080CDABC:\n\
	adds r0, r5, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r1, [r5, #0x60]\n\
	ldr r0, _080CDB30 @ =0x000006FF\n\
	cmp r1, r0\n\
	bgt _080CDAD0\n\
	adds r0, r1, #0\n\
	adds r0, #0x20\n\
	str r0, [r5, #0x60]\n\
_080CDAD0:\n\
	ldr r0, [r5, #0x58]\n\
	ldr r1, [r5, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x58]\n\
	str r0, [r5, #0x68]\n\
	ldr r0, _080CDB34 @ =gStageRun+232\n\
	adds r1, r5, #0\n\
	adds r1, #0x54\n\
	bl CalcFromCamera\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #6\n\
	cmp r0, r1\n\
	bls _080CDB26\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0\n\
	strb r0, [r5, #0xa]\n\
	adds r0, r5, #0\n\
	adds r0, #0x8c\n\
	str r1, [r0]\n\
	adds r0, #4\n\
	str r1, [r0]\n\
	adds r0, #4\n\
	strb r1, [r0]\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldrb r1, [r5, #0xb]\n\
	movs r0, #0xf7\n\
	ands r0, r1\n\
	strb r0, [r5, #0xb]\n\
	ldr r1, _080CDB38 @ =gSolidFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #4\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0x10]\n\
	str r0, [r5, #0x14]\n\
_080CDB26:\n\
	add sp, #8\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080CDB30: .4byte 0x000006FF\n\
_080CDB34: .4byte gStageRun+232\n\
_080CDB38: .4byte gSolidFnTable\n\
 .syntax divided\n");
}

// --------------------------------------------

static const struct Collision sCollisions1[2] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 255,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {0x0000, 0x0500, 0x2200, 0x0C00},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 255,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0000, 0x0000, 0x0000},
    },
};

static const struct Collision sCollisions2[2] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 1,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {0x0000, 0x1000, 0x0800, 0x1200},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 1,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0000, 0x0000, 0x0000},
    },
};

// --------------------------------------------

static const struct Rect sSize = {
    PIXEL(0),
    PIXEL(8),
    PIXEL(32),
    PIXEL(16),
};

// --------------------------------------------

static const s32 s32_ARRAY_08370170[8] = {
    -1, 0, 1, 0, -1, 0, 1, 0,
};

static const s32 s32_ARRAY_08370190[8] = {
    -1, 1, 0, -1, 1, -1, 0, 1,
};
