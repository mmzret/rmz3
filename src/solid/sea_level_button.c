#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"
#include "story.h"

static const struct Collision sCollisions[2];
static const struct Rect sSizes[2];

static void SeaLevelButton_Init(struct Solid* p);
static void SeaLevelButton_Update(struct Solid* p);
static void SeaLevelButton_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSeaLevelButtonRoutine = {
    [ENTITY_INIT] =      SeaLevelButton_Init,
    [ENTITY_UPDATE] =    SeaLevelButton_Update,
    [ENTITY_DIE] =       SeaLevelButton_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

struct Solid* CreateSeaLevelButton(u8 idx, struct Coord* c) {
  struct Solid* p = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 30;
    INIT_SOLID_ROUTINE(p, SOLID_SEA_LV_BTN);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
    (p->s).work[0] = idx;
  }
  return p;
}

// --------------------------------------------

static void SeaLevelButton_Init(struct Solid* p) {
  struct Coord* velocity;
  (p->s).flags |= FLIPABLE;
  (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y);
  velocity = &(p->s).d;
  velocity->x = velocity->y = 0;
  if (IS_MISSION) {
    INIT_BODY(p, &sCollisions[0], 0, NULL);
    SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  } else {
    SET_SOLID_ROUTINE(p, ENTITY_DIE);
  }
}

// --------------------------------------------

NAKED static void SeaLevelButton_Update(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	adds r7, r0, #0\n\
	ldrb r0, [r7, #0xd]\n\
	cmp r0, #0\n\
	beq _080DFFAC\n\
	cmp r0, #1\n\
	beq _080E007E\n\
	adds r5, r7, #0\n\
	adds r5, #0x8c\n\
	b _080E0166\n\
_080DFFAC:\n\
	ldr r0, _080E00C4 @ =gStageRun+232\n\
	adds r1, r7, #0\n\
	adds r1, #0x54\n\
	bl CalcFromCamera\n\
	movs r1, #0x80\n\
	lsls r1, r1, #5\n\
	adds r5, r7, #0\n\
	adds r5, #0x8c\n\
	cmp r0, r1\n\
	bls _080DFFC4\n\
	b _080E0166\n\
_080DFFC4:\n\
	ldr r1, _080E00C8 @ =gCurStory\n\
	ldr r0, _080E00CC @ =u16_ARRAY_083719b4\n\
	mov sl, r0\n\
	ldrb r0, [r7, #0x10]\n\
	lsls r0, r0, #1\n\
	add r0, sl\n\
	ldrh r2, [r0]\n\
	lsrs r0, r2, #3\n\
	adds r1, #4\n\
	mov r8, r1\n\
	add r0, r8\n\
	ldrb r1, [r0]\n\
	movs r0, #7\n\
	mov sb, r0\n\
	ands r0, r2\n\
	asrs r1, r0\n\
	movs r6, #1\n\
	ands r1, r6\n\
	strb r1, [r7, #0x12]\n\
	ldr r4, _080E00D0 @ =0x00000E24\n\
	ldr r1, _080E00D4 @ =gStaticMotionGraphics\n\
	adds r0, r4, r1\n\
	ldr r1, _080E00D8 @ =wStaticGraphicTilenums\n\
	movs r5, #0xb5\n\
	lsls r5, r5, #1\n\
	adds r1, r1, r5\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	ldr r0, _080E00DC @ =gStaticMotionGraphics+12\n\
	adds r4, r4, r0\n\
	ldr r0, _080E00E0 @ =wStaticMotionPalIDs\n\
	adds r0, r0, r5\n\
	ldrh r1, [r0]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	ldrb r0, [r7, #0xa]\n\
	movs r4, #0\n\
	orrs r0, r6\n\
	strb r0, [r7, #0xa]\n\
	adds r0, r7, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r0, [r7, #0x12]\n\
	movs r1, #0xb5\n\
	lsls r1, r1, #8\n\
	cmp r0, #0\n\
	beq _080E0042\n\
	adds r1, #1\n\
_080E0042:\n\
	adds r0, r7, #0\n\
	bl SetMotion\n\
	ldrb r0, [r7, #0xb]\n\
	movs r1, #8\n\
	orrs r0, r1\n\
	strb r0, [r7, #0xb]\n\
	ldrb r0, [r7, #0x10]\n\
	lsls r0, r0, #1\n\
	add r0, sl\n\
	ldrh r2, [r0]\n\
	lsrs r0, r2, #3\n\
	add r0, r8\n\
	ldrb r1, [r0]\n\
	mov r0, sb\n\
	ands r0, r2\n\
	asrs r1, r0\n\
	movs r0, #1\n\
	ands r1, r0\n\
	lsls r1, r1, #3\n\
	ldr r0, _080E00E4 @ =sSizes\n\
	adds r1, r1, r0\n\
	str r1, [r7, #0x30]\n\
	movs r1, #0\n\
	ldr r0, _080E00E8 @ =0x00002001\n\
	strh r0, [r7, #0x26]\n\
	strb r1, [r7, #0x13]\n\
	ldrb r0, [r7, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r7, #0xd]\n\
_080E007E:\n\
	adds r0, r7, #0\n\
	bl UpdateMotionGraphic\n\
	adds r1, r7, #0\n\
	adds r1, #0x8c\n\
	ldr r2, [r1]\n\
	movs r0, #4\n\
	ands r2, r0\n\
	adds r5, r1, #0\n\
	cmp r2, #0\n\
	beq _080E00EC\n\
	ldrb r0, [r7, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r7, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldr r6, _080E00C8 @ =gCurStory\n\
	ldr r4, _080E00CC @ =u16_ARRAY_083719b4\n\
	cmp r0, #0x1d\n\
	bls _080E00F2\n\
	ldrb r0, [r7, #0x10]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r4\n\
	ldrh r3, [r0]\n\
	lsrs r2, r3, #3\n\
	adds r0, r6, #4\n\
	adds r2, r2, r0\n\
	movs r1, #7\n\
	ands r1, r3\n\
	movs r0, #1\n\
	lsls r0, r1\n\
	ldrb r1, [r2]\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	b _080E00F2\n\
	.align 2, 0\n\
_080E00C4: .4byte gStageRun+232\n\
_080E00C8: .4byte gCurStory\n\
_080E00CC: .4byte u16_ARRAY_083719b4\n\
_080E00D0: .4byte 0x00000E24\n\
_080E00D4: .4byte gStaticMotionGraphics\n\
_080E00D8: .4byte wStaticGraphicTilenums\n\
_080E00DC: .4byte gStaticMotionGraphics+12\n\
_080E00E0: .4byte wStaticMotionPalIDs\n\
_080E00E4: .4byte sSizes\n\
_080E00E8: .4byte 0x00002001\n\
_080E00EC:\n\
	strb r2, [r7, #0x13]\n\
	ldr r6, _080E01CC @ =gCurStory\n\
	ldr r4, _080E01D0 @ =u16_ARRAY_083719b4\n\
_080E00F2:\n\
	ldrb r0, [r7, #0x10]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r4\n\
	ldrh r2, [r0]\n\
	lsrs r0, r2, #3\n\
	adds r1, r6, #4\n\
	adds r0, r0, r1\n\
	ldrb r1, [r0]\n\
	movs r0, #7\n\
	ands r0, r2\n\
	asrs r1, r0\n\
	movs r2, #1\n\
	ands r1, r2\n\
	adds r4, r7, #0\n\
	adds r4, #0x54\n\
	cmp r1, #0\n\
	beq _080E0142\n\
	ldrb r0, [r7, #0x12]\n\
	cmp r0, #0\n\
	bne _080E0142\n\
	strb r2, [r7, #0x12]\n\
	movs r0, #4\n\
	adds r1, r4, #0\n\
	bl AppendQuake\n\
	movs r0, #0x91\n\
	bl PlaySound\n\
	ldr r1, _080E01D4 @ =0x0000B501\n\
	adds r0, r7, #0\n\
	bl SetMotion\n\
	ldrb r1, [r7, #0xb]\n\
	movs r0, #8\n\
	orrs r0, r1\n\
	strb r0, [r7, #0xb]\n\
	ldr r0, _080E01D8 @ =0x083719AC\n\
	str r0, [r7, #0x30]\n\
	ldr r0, _080E01DC @ =0x00002001\n\
	strh r0, [r7, #0x26]\n\
_080E0142:\n\
	ldr r0, _080E01E0 @ =gStageRun+232\n\
	adds r1, r4, #0\n\
	bl CalcFromCamera\n\
	movs r1, #0x80\n\
	lsls r1, r1, #5\n\
	cmp r0, r1\n\
	bls _080E0166\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r2, #0\n\
	strb r0, [r7, #0xa]\n\
	ldrb r1, [r7, #0xb]\n\
	movs r0, #0xf7\n\
	ands r0, r1\n\
	strb r0, [r7, #0xb]\n\
	strb r2, [r7, #0xd]\n\
_080E0166:\n\
	ldr r0, [r5]\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080E01BE\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0\n\
	strb r0, [r7, #0xa]\n\
	str r1, [r5]\n\
	adds r0, r7, #0\n\
	adds r0, #0x90\n\
	str r1, [r0]\n\
	adds r0, #4\n\
	strb r1, [r0]\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r7, #0xa]\n\
	ldrb r1, [r7, #0xb]\n\
	movs r0, #0xf7\n\
	ands r0, r1\n\
	strb r0, [r7, #0xb]\n\
	adds r1, r7, #0\n\
	adds r1, #0x54\n\
	movs r0, #1\n\
	bl CreateSmoke\n\
	movs r0, #0x31\n\
	bl PlaySound\n\
	ldr r1, _080E01E4 @ =gSolidFnTable\n\
	ldrb r0, [r7, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r7, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r7, #0x14]\n\
	adds r0, r7, #0\n\
	bl SeaLevelButton_Die\n\
_080E01BE:\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E01CC: .4byte gCurStory\n\
_080E01D0: .4byte u16_ARRAY_083719b4\n\
_080E01D4: .4byte 0x0000B501\n\
_080E01D8: .4byte sSizes+8\n\
_080E01DC: .4byte 0x00002001\n\
_080E01E0: .4byte gStageRun+232\n\
_080E01E4: .4byte gSolidFnTable\n\
 .syntax divided\n");
}

// --------------------------------------------

static void SeaLevelButton_Die(struct Solid* p) {
  switch ((p->s).mode[1]) {
    case 0: {
      if (CalcFromCamera(&gStageRun.vm.camera, &(p->s).coord) > PIXEL(16)) {
        return;
      }
      LOAD_STATIC_GRAPHIC(SM181_SEA_LEVEL_BUTTON);
      (p->s).flags |= DISPLAY;
      InitNonAffineMotion(&p->s);
      SetMotion(&p->s, MOTION(SM181_SEA_LEVEL_BUTTON, 2));
      (p->s).flags2 |= ENTITY_HAZARD;
      (p->s).size = &sSizes[1];
      (p->s).hazardAttr = (METATILE_CONVEYOR1 | METATILE_GROUND);
      (p->s).mode[1]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateMotionGraphic(&p->s);
      if (CalcFromCamera(&gStageRun.vm.camera, &(p->s).coord) > PIXEL(16)) {
        (p->s).flags &= ~DISPLAY;
        (p->s).flags2 &= ~ENTITY_HAZARD;
        (p->s).mode[1] = 0;
      }
      break;
    }
  }
}

// --------------------------------------------

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x0800, 0x1E00, 0x0600},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      priorityLayer : 0xFFCEF7BD,
      range : {0x0000, 0x0000, 0x4000, 0x4000},
    },
};

static const struct Rect sSizes[2] = {
    {0, 0, 0x2000, 0x1400},
    {0, 0x400, 0x2000, 0x1400},
};

const u16 u16_ARRAY_083719b4[4] = {0x29, 0x2A, 0x2B, 0x2C};
