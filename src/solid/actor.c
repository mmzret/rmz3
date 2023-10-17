#include "collision.h"
#include "entity.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"
#include "vfx.h"
#include "zero.h"

/*
  Actor:
  Solid.id が 21 の Entity は 基本的にフィールドスクリプト(Script)によって生成される、スクリプトの登場人物のようなもの
  どの種類のActorかは Solid.s.work[0] に格納される (constants/solid.h の ACTOR_XXXX を参照)
*/

static void Actor_Init(struct Solid* p);
void Actor_Update(struct Solid* p);
void Actor_Die(struct Solid* p);

// clang-format off
const SolidRoutine gScriptActorRoutine = {
    [ENTITY_INIT] =      Actor_Init,
    [ENTITY_UPDATE] =    Actor_Update,
    [ENTITY_DIE] =       Actor_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

struct Solid* CreateScriptActor(struct Solid* e, u8 kind) {
  struct Solid* p = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 30;
    INIT_SOLID_ROUTINE(p, SOLID_SCRIPT_ACTOR);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).work[0] = kind;
    (p->s).coord.x = (e->s).coord.x;
    (p->s).coord.y = (e->s).coord.y;
    (p->s).unk_28 = &e->s;
  }
  return p;
}

u16 FUN_080d08d0(struct Boss* babyelf, motion_t m) { return FUN_080d0934(&babyelf->s, m, ((babyelf->s).flags2 >> 2) & 1); }

// --------------------------------------------

static const SolidFunc sActorUpdate[ACTOR_COUNT];
static const SolidFunc sActorDeinitalizer[ACTOR_COUNT];

// --------------------------------------------

static void initStaticActor(struct Solid* p);
static void initDynamicActor(struct Solid* p);
static void loadNeutralZeroColor(struct Solid* p);
static void initActor8(struct Solid* p);
void initActor21(struct Solid* p);
void initActor23(struct Solid* p);
void initActor28(struct Solid* p);
void initActor32(struct Solid* p);

static void Actor_Init(struct Solid* p) {
  // clang-format off
  static SolidFunc const sInitializers[] = {
      [0] =  initStaticActor,
      [ACTOR_ZERO_WALK] =  loadNeutralZeroColor,
      [ACTOR_CIEL_WALK] =  initDynamicActor,
      [3] =  initStaticActor,
      [4] =  initDynamicActor,
      [5] =  initStaticActor,
      [6] =  initDynamicActor,
      [7] =  initStaticActor,
      [8] =  initActor8,
      [9] =  initStaticActor,
      [10] = initStaticActor,
      [11] = initDynamicActor,
      [12] = initDynamicActor,
      [13] = initStaticActor,
      [14] = initDynamicActor,
      [15] = initStaticActor,
      [16] = initStaticActor,
      [17] = initStaticActor,
      [18] = initDynamicActor,
      [19] = initDynamicActor,
      [20] = initDynamicActor,
      [21] = initActor21,
      [22] = initStaticActor,
      [23] = initActor23,
      [24] = initStaticActor,
      [25] = initStaticActor,
      [26] = initStaticActor,
      [27] = initDynamicActor,
      [28] = initActor28,
      [29] = initStaticActor,
      [30] = initStaticActor,
      [31] = initStaticActor,
      [32] = initActor32,
      [33] = initDynamicActor,
      [34] = initStaticActor,
      [35] = initDynamicActor,
      [36] = initStaticActor,
      [37] = initStaticActor,
      [38] = initStaticActor,
      [39] = initDynamicActor,
      [40] = initDynamicActor,
      [41] = initStaticActor,
      [42] = initDynamicActor,
      [43] = initDynamicActor,
      [44] = initStaticActor,
      [45] = initDynamicActor,
      [46] = initStaticActor,
      [47] = initDynamicActor,
      [48] = initDynamicActor,
      [49] = initDynamicActor,
      [50] = initDynamicActor,
      [51] = initDynamicActor,
      [52] = initStaticActor,
      [53] = initStaticActor,
      [54] = initStaticActor,
      [55] = initStaticActor,
      [56] = initDynamicActor,
      [57] = initStaticActor,
      [58] = initStaticActor,
      [59] = initStaticActor,
      [60] = initDynamicActor,
      [61] = initDynamicActor,
      [62] = initDynamicActor,
      [63] = initStaticActor,
      [64] = initStaticActor,
      [65] = initStaticActor,
  };
  // clang-format on
  (sInitializers[(p->s).work[0]])(p);
  return;
}

// --------------------------------------------

static void ActorDummy_Update(struct Solid* p);
static void Actor1_Update(struct Solid* p);
static void Actor2_Update(struct Solid* p);
static void Actor3_Update(struct Solid* p);
static void Actor4_Update(struct Solid* p);
static void Actor5_Update(struct Solid* p);
static void Actor6_Update(struct Solid* p);
static void Actor7_Update(struct Solid* p);
void Actor8_Update(struct Solid* p);
void ActorCrashedPantheon_Update(struct Solid* p);
void Actor10_Update(struct Solid* p);
void ActorLeviathan11_Update(struct Solid* p);
void ActorFefnir12_Update(struct Solid* p);
void Actor13_Update(struct Solid* p);
void ActorSaveSelectCiel_Update(struct Solid* p);
void Actor15_Update(struct Solid* p);
void ActorOperator_Update(struct Solid* p);
void Actor17_Update(struct Solid* p);
void Actor18_Update(struct Solid* p);
void Actor19_Update(struct Solid* p);
void Actor20_Update(struct Solid* p);
void Actor21_Update(struct Solid* p);
void Actor22_Update(struct Solid* p);
void Actor23_Update(struct Solid* p);
void Actor24_Update(struct Solid* p);
void Actor25_Update(struct Solid* p);
void Actor26_Update(struct Solid* p);
void Actor27_Update(struct Solid* p);
void Actor28_Update(struct Solid* p);
void Actor29_Update(struct Solid* p);
void Actor30_Update(struct Solid* p);
void Actor31_Update(struct Solid* p);
void Actor32_Update(struct Solid* p);
void Actor33_Update(struct Solid* p);
void Actor34_Update(struct Solid* p);
void Actor35_Update(struct Solid* p);
void Actor36_Update(struct Solid* p);
void Actor37_Update(struct Solid* p);
void Actor38_Update(struct Solid* p);
void Actor39_Update(struct Solid* p);
void ActorOmegaZero40_Update(struct Solid* p);
void Actor41_Update(struct Solid* p);
void ActorLastHarpuia_Update(struct Solid* p);
void ActorLastFefnir_Update(struct Solid* p);
void ActorLastFefnirFireball_Update(struct Solid* p);
void ActorLastLeviathan_Update(struct Solid* p);
void ActorLastX_Update(struct Solid* p);
void Actor47_Update(struct Solid* p);
void Actor48_Update(struct Solid* p);
void FUN_080d5c5c(struct Solid* p);
void FUN_080d5d20(struct Solid* p);
void FUN_080d5e08(struct Solid* p);
void omega1_080d5fc8(struct Solid* p);
void FUN_080d6504(struct Solid* p);
void FUN_080d6814(struct Solid* p);
void FUN_080d6afc(struct Solid* p);
void FUN_080d6c80(struct Solid* p);
void FUN_080d6fa0(struct Solid* p);
void FUN_080d724c(struct Solid* p);
void FUN_080d740c(struct Solid* p);
void FUN_080d751c(struct Solid* p);
void FUN_080d7638(struct Solid* p);
void Actor62_Update(struct Solid* p);
void Actor63_Update(struct Solid* p);
void Actor64_Update(struct Solid* p);
void Actor65_Update(struct Solid* p);

void Actor_Update(struct Solid* p) {
  // clang-format off
  static SolidFunc const sUpdates[] = {
      [0] =  ActorDummy_Update,
      [ACTOR_ZERO_WALK] =  Actor1_Update,
      [ACTOR_CIEL_WALK] =  Actor2_Update,
      [3] =  Actor3_Update,
      [4] =  Actor4_Update,
      [5] =  Actor5_Update,
      [6] =  Actor6_Update,
      [7] =  Actor7_Update,
      [8] =  Actor8_Update,
      [9] =  ActorCrashedPantheon_Update,
      [10] = Actor10_Update,
      [11] = ActorLeviathan11_Update,
      [12] = ActorFefnir12_Update,
      [13] = Actor13_Update,
      [14] = ActorSaveSelectCiel_Update,
      [15] = Actor15_Update,
      [16] = ActorOperator_Update,
      [17] = Actor17_Update,
      [18] = Actor18_Update,
      [19] = Actor19_Update,
      [20] = Actor20_Update,
      [21] = Actor21_Update,
      [22] = Actor22_Update,
      [23] = Actor23_Update,
      [24] = Actor24_Update,
      [25] = Actor25_Update,
      [26] = Actor26_Update,
      [27] = Actor27_Update,
      [28] = Actor28_Update,
      [29] = Actor29_Update,
      [30] = Actor30_Update,
      [31] = Actor31_Update,
      [32] = Actor32_Update,
      [33] = Actor33_Update,
      [34] = Actor34_Update,
      [35] = Actor35_Update,
      [36] = Actor36_Update,
      [37] = Actor37_Update,
      [38] = Actor38_Update,
      [39] = Actor39_Update,
      [40] = ActorOmegaZero40_Update,
      [41] = Actor41_Update,
      [42] = ActorLastHarpuia_Update,
      [43] = ActorLastFefnir_Update,
      [44] = ActorLastFefnirFireball_Update,
      [45] = ActorLastLeviathan_Update,
      [46] = ActorLastX_Update,
      [47] = Actor47_Update,
      [48] = Actor48_Update,
      [49] = FUN_080d5c5c,
      [50] = FUN_080d5d20,
      [51] = FUN_080d5e08,
      [52] = omega1_080d5fc8,
      [53] = FUN_080d6504,
      [54] = FUN_080d6814,
      [55] = FUN_080d6afc,
      [56] = FUN_080d6c80,
      [57] = FUN_080d6fa0,
      [58] = FUN_080d724c,
      [59] = FUN_080d740c,
      [60] = FUN_080d751c,
      [61] = FUN_080d7638,
      [62] = Actor62_Update,
      [63] = Actor63_Update,
      [64] = Actor64_Update,
      [65] = Actor65_Update,
  };
  // clang-format on
  (sUpdates[(p->s).work[0]])(p);
  return;
}

// --------------------------------------------

static void deleteActor(struct Solid* p);

void Actor_Die(struct Solid* p) {
  // clang-format off
  static SolidFunc const sDeinitalizer[] = {
      [0] =  deleteActor,
      [ACTOR_ZERO_WALK] =  deleteActor,
      [ACTOR_CIEL_WALK] =  deleteActor,
      [3] =  deleteActor,
      [4] =  deleteActor,
      [5] =  deleteActor,
      [6] =  deleteActor,
      [7] =  deleteActor,
      [8] =  deleteActor,
      [9] =  deleteActor,
      [10] = deleteActor,
      [11] = deleteActor,
      [12] = deleteActor,
      [13] = deleteActor,
      [14] = deleteActor,
      [15] = deleteActor,
      [16] = deleteActor,
      [17] = deleteActor,
      [18] = deleteActor,
      [19] = deleteActor,
      [20] = deleteActor,
      [21] = deleteActor,
      [22] = deleteActor,
      [23] = deleteActor,
      [24] = deleteActor,
      [25] = deleteActor,
      [26] = deleteActor,
      [27] = deleteActor,
      [28] = deleteActor,
      [29] = deleteActor,
      [30] = deleteActor,
      [31] = deleteActor,
      [32] = deleteActor,
      [33] = deleteActor,
      [34] = deleteActor,
      [35] = deleteActor,
      [36] = deleteActor,
      [37] = deleteActor,
      [38] = deleteActor,
      [39] = deleteActor,
      [40] = deleteActor,
      [41] = deleteActor,
      [42] = deleteActor,
      [43] = deleteActor,
      [44] = deleteActor,
      [45] = deleteActor,
      [46] = deleteActor,
      [47] = deleteActor,
      [48] = deleteActor,
      [49] = deleteActor,
      [50] = deleteActor,
      [51] = deleteActor,
      [52] = deleteActor,
      [53] = deleteActor,
      [54] = deleteActor,
      [55] = deleteActor,
      [56] = deleteActor,
      [57] = deleteActor,
      [58] = deleteActor,
      [59] = deleteActor,
      [60] = deleteActor,
      [61] = deleteActor,
      [62] = deleteActor,
      [63] = deleteActor,
      [64] = deleteActor,
      [65] = deleteActor,
  };
  // clang-format on
  (sDeinitalizer[(p->s).work[0]])(p);
}

// --------------------------------------------

// ピシュンと音を立ててキャラクターを転送させる処理？(帰還)
u16 FUN_080d0934(struct Entity* p, motion_t m, u8 r2) {
  switch (p->mode[3]) {
    case 0: {
      p->work[2] = 30;
      p->mode[3]++;
    }
    case 1: {
      UpdateMotionGraphic(p);
      if (p->work[2] & 1) {
        PaintEntityWhite(p);
      } else {
        UpdateEntityPaletteID(p);
      }
      p->work[2]--;
      if (p->work[2] == 0) {
        p->work[2] = 8;
        p->mode[3]++;
      }
      break;
    }
    case 2: {
      InitScalerotMotion1(p);
      if (r2 != 0) {
        ResetDynamicMotion(p);
      }
      SetMotion(p, m);
      p->mode[3]++;
    }
    case 3: {
      UpdateMotionGraphic(p);
      PaintEntityWhite(p);
      (p->spr).mag.x = p->work[2] * -4 + 0x120;
      (p->spr).mag.y = p->work[2] * 4 + 0xe0;
      if (--p->work[2] != 0) {
        return 0;
      }
      p->work[2] = 4;
      p->mode[3]++;
      break;
    }
    case 4: {
      UpdateMotionGraphic(p);
      PaintEntityWhite(p);
      (p->spr).mag.x = p->work[2] * 0x40 + 0x20;
      (p->spr).mag.y = p->work[2] * -0x20 + 0x160;
      if (--p->work[2] != 0) {
        return 0;
      }
      (p->d).y = -0xc00;
      PlaySound(SE_TENSOU_BACK);
      p->mode[3]++;
      break;
    }
    case 5: {
      UpdateMotionGraphic(p);
      PaintEntityWhite(p);
      (p->spr).mag.x = 0x20;
      (p->d).y -= 0x40;
      (p->coord).y += (p->d).y * 2;
      if (0x3000 < CalcFromCamera(&gStageRun.vm.camera, &p->coord)) {
        p->flags &= ~DISPLAY;
        p->mode[3] = 0;
        return 1;
      }
      break;
    }
  }

  return 0;
}

// ピシュンと音を立ててキャラクターを転送させる処理？(召喚)
WIP u16 FUN_080d0aa0(struct Entity* p, motion_t m, u8 r2) {
#if MODERN
  switch (p->mode[3]) {
    case 0: {
      InitScalerotMotion1(p);
      if (r2 != 0) {
        ResetDynamicMotion(p);
      }
      SetMotion(p, m);
      (p->spr).mag.x = 0x20;
      (p->spr).mag.y = 0x200;
      PaintEntityWhite(p);
      (p->unk_coord).y = FUN_08009f6c((p->coord).x, (p->coord).y);
      (p->coord).y = gStageRun.vm.camera.viewport.y - PIXEL(96);
      p->mode[3]++;
    }
    case 1: {
      UpdateMotionGraphic(p);
      (p->coord).y += 0x1c00;
      if ((p->coord).y <= (p->unk_coord).y) {
        return 0;
      }
      (p->coord).y = (p->unk_coord).y;
      PlaySound(SE_TENSOU_BACK);
      p->work[2] = 1;
      p->mode[3]++;
      break;
    }
    case 2: {
      UpdateMotionGraphic(p);
      (p->spr).mag.x = p->work[2] * 0x40 + 0x20;
      (p->spr).mag.y = p->work[2] * -0x20 + 0x160;
      if (++p->work[2] < 5) {
        return 0;
      }
      p->work[2] = 1;
      p->mode[3]++;
      break;
    }
    case 3: {
      UpdateMotionGraphic(p);
      (p->spr).mag.x = p->work[2] * -4 + 0x120;
      (p->spr).mag.y = p->work[2] * 4 + 0xe0;
      if (++p->work[2] < 9) {
        return 0;
      }
      p->mode[3]++;
      break;
    }
    case 4: {
      InitNonAffineMotion(p);
      if (r2 != 0) {
        ResetDynamicMotion(p);
      }
      SetMotion(p, m);
      p->work[2] = 30;
      p->mode[3]++;
    }
    case 5: {
      UpdateMotionGraphic(p);
      if (p->work[2] & 1) {
        UpdateEntityPaletteID(p);
      } else {
        PaintEntityWhite(p);
      }
      if (--p->work[2] == 0) {
        p->mode[3] = 0;
        return 1;
      }
    }
  }
  return 0;
#else
  INCCODE("asm/wip/FUN_080d0aa0.inc");
#endif
}

// --------------------------------------------

static void initStaticActor(struct Solid* p) {
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  InitNonAffineMotion(&p->s);
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  Actor_Update(p);
}

static void initDynamicActor(struct Solid* p) {
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  InitNonAffineMotion(&p->s);
  ResetDynamicMotion(&p->s);
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  Actor_Update(p);
}

// --------------------------------------------

static void ActorDummy_Update(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_DIE);
  Actor_Die(p);
}

// --------------------------------------------

static void deleteActor(struct Solid* p) {
  (p->s).flags &= ~DISPLAY;
  (p->body).status = 0;
  (p->body).prevStatus = 0;
  (p->body).invincibleTime = 0;
  (p->s).flags &= ~COLLIDABLE;
  (p->s).flags2 &= ~ENTITY_HAZARD;
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void loadNeutralZeroColor(struct Solid* p) {
  if (FLAG(gCurStory.s.gameflags, FLAG_HARD)) {
    LoadZeroPalette(&p->s, BODY_CHIP_PROTO);
  } else if (FLAG(gCurStory.s.gameflags, FLAG_ULTIMATE)) {
    LoadZeroPalette(&p->s, BODY_CHIP_ULTIMA);
  } else {
    LoadZeroPalette(&p->s, BODY_CHIP_NONE);
  }
  initDynamicActor(p);
}

// --------------------------------------------

NAKED static void Actor1_Update(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r6, r0, #0\n\
	ldrb r0, [r6, #0xd]\n\
	cmp r0, #6\n\
	bls _080D0D50\n\
	b _080D0EDC\n\
_080D0D50:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080D0D5C @ =_080D0D60\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080D0D5C: .4byte _080D0D60\n\
_080D0D60: @ jump table\n\
	.4byte _080D0D7C @ case 0\n\
	.4byte _080D0DAA @ case 1\n\
	.4byte _080D0DE0 @ case 2\n\
	.4byte _080D0E12 @ case 3\n\
	.4byte _080D0E34 @ case 4\n\
	.4byte _080D0E48 @ case 5\n\
	.4byte _080D0EA8 @ case 6\n\
_080D0D7C:\n\
	adds r7, r6, #0\n\
	adds r7, #0x25\n\
	movs r5, #0\n\
	movs r4, #0x10\n\
	strb r4, [r7]\n\
	ldr r0, [r6, #0x54]\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #8\n\
	adds r0, r0, r1\n\
	ldr r1, [r6, #0x58]\n\
	bl FUN_08009f6c\n\
	str r0, [r6, #0x58]\n\
	str r5, [r6, #0x2c]\n\
	strb r4, [r7]\n\
	movs r1, #0xc4\n\
	lsls r1, r1, #8\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	ldrb r0, [r6, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r6, #0xd]\n\
_080D0DAA:\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, [r6, #0x54]\n\
	adds r0, #0x50\n\
	str r0, [r6, #0x54]\n\
	ldr r0, [r6, #0x18]\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080D0DC4\n\
	b _080D0EDC\n\
_080D0DC4:\n\
	adds r0, r6, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #4\n\
	beq _080D0DD0\n\
	b _080D0EDC\n\
_080D0DD0:\n\
	ldr r1, _080D0DDC @ =0x00003303\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	movs r0, #0x10\n\
	b _080D0E9E\n\
	.align 2, 0\n\
_080D0DDC: .4byte 0x00003303\n\
_080D0DE0:\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r6, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r6, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
	cmp r2, #0\n\
	bne _080D0EDC\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r0, r6, #0\n\
	adds r0, #0x4c\n\
	strb r2, [r0]\n\
	adds r2, r6, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	b _080D0EA0\n\
_080D0E12:\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, [r6, #0x18]\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080D0EDC\n\
	ldr r1, _080D0E30 @ =0x00003301\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	b _080D0EA0\n\
	.align 2, 0\n\
_080D0E30: .4byte 0x00003301\n\
_080D0E34:\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r6, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _080D0EDC\n\
	movs r0, #8\n\
	b _080D0E9E\n\
_080D0E48:\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r6, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r6, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _080D0EDC\n\
	movs r4, #1\n\
	ldrb r0, [r6, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r0, r6, #0\n\
	adds r0, #0x4c\n\
	strb r4, [r0]\n\
	adds r3, r6, #0\n\
	adds r3, #0x4a\n\
	movs r2, #0x10\n\
	ldrb r1, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	orrs r0, r2\n\
	strb r0, [r3]\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #2\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	adds r0, r6, #0\n\
	adds r0, #0x54\n\
	ldrb r2, [r6, #0xa]\n\
	lsrs r2, r2, #4\n\
	ands r2, r4\n\
	movs r1, #0\n\
	bl CreateParticle\n\
	movs r0, #8\n\
	bl PlaySound\n\
	movs r0, #0x20\n\
_080D0E9E:\n\
	strb r0, [r6, #0x12]\n\
_080D0EA0:\n\
	ldrb r0, [r6, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r6, #0xd]\n\
	b _080D0EDC\n\
_080D0EA8:\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r6, #0x12]\n\
	cmp r0, #0\n\
	beq _080D0EC8\n\
	subs r0, #1\n\
	strb r0, [r6, #0x12]\n\
	ldr r0, [r6, #0x2c]\n\
	cmp r0, #0\n\
	bne _080D0ED2\n\
	adds r0, r6, #0\n\
	bl CreateAfterImages\n\
	str r0, [r6, #0x2c]\n\
	b _080D0ED2\n\
_080D0EC8:\n\
	ldr r1, [r6, #0x2c]\n\
	cmp r1, #0\n\
	beq _080D0ED2\n\
	movs r0, #1\n\
	strb r0, [r1, #0x11]\n\
_080D0ED2:\n\
	ldr r0, [r6, #0x54]\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #2\n\
	adds r0, r0, r1\n\
	str r0, [r6, #0x54]\n\
_080D0EDC:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

// --------------------------------------------

static void Actor2_Update(struct Solid* p) {
  switch ((p->s).mode[1]) {
    case 0: {
      (p->s).coord.y = FUN_08009f6c((p->s).coord.x + 0xF000, (p->s).coord.y);
      SetMotion(&p->s, MOTION(DM194_CIEL, 15));
      (p->s).mode[1]++;
      FALLTHROUGH
    }
    case 1: {
      UpdateMotionGraphic(&p->s);
      (p->s).coord.x += 0x50;
      if (((p->s).scriptEntity->flags & (1 << 0)) && ((p->s).motion.state == MOTION_NEXT)) {
        SetMotion(&p->s, MOTION(DM194_CIEL, 17));
        (p->s).mode[1]++;
      }
      break;
    }

    case 2: {
      UpdateMotionGraphic(&p->s);
      if (((p->s).scriptEntity->flags & (1 << 1)) == 0) {
        return;
      }
      SetMotion(&p->s, MOTION(DM194_CIEL, 19));
      (p->s).mode[1]++;
      break;
    }

    case 3: {
      UpdateMotionGraphic(&p->s);
      if (((p->s).scriptEntity->flags & (1 << 2)) == 0) {
        return;
      }
      SetMotion(&p->s, MOTION(DM194_CIEL, 17));
      (p->s).mode[1]++;
      break;
    }

    case 4: {
      UpdateMotionGraphic(&p->s);
      break;
    }
  }
}

// --------------------------------------------

static void Actor3_Update(struct Solid* p) {
  switch ((p->s).mode[1]) {
    case 0: {
      (p->s).coord.y = FUN_08009f6c((p->s).coord.x + PIXEL(240), (p->s).coord.y);
      if ((p->s).work[1] == 0) {
        LOAD_STATIC_GRAPHIC(SM130_PROLOGUE_RESISTANCE);
      }
      SetMotion(&p->s, MOTION(SM130_PROLOGUE_RESISTANCE, 2));
      (p->s).mode[1]++;
      FALLTHROUGH
    }
    case 1: {
      UpdateMotionGraphic(&p->s);
      (p->s).coord.x += 0x50;
      if ((p->s).motion.state != MOTION_NEXT) {
        return;
      }
      if (((p->s).scriptEntity->flags & 1) == 0) {
        return;
      }
      SetMotion(&p->s, MOTION(SM130_PROLOGUE_RESISTANCE, 0));
      (p->s).mode[1]++;
      break;
    }
    case 2: {
      UpdateMotionGraphic(&p->s);
      if (((p->s).scriptEntity->flags & 2) == 0) {
        return;
      }
      LOAD_STATIC_GRAPHIC(SM130_PROLOGUE_RESISTANCE);
      (p->s).mode[1]++;
      break;
    }
    case 3: {
      UpdateMotionGraphic(&p->s);
      break;
    }
  }
}

NAKED static void Actor4_Update(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xd]\n\
	cmp r0, #4\n\
	bhi _080D11BA\n\
	lsls r0, r0, #2\n\
	ldr r1, _080D10FC @ =_080D1100\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080D10FC: .4byte _080D1100\n\
_080D1100: @ jump table\n\
	.4byte _080D1114 @ case 0\n\
	.4byte _080D112C @ case 1\n\
	.4byte _080D114C @ case 2\n\
	.4byte _080D1170 @ case 3\n\
	.4byte _080D11B4 @ case 4\n\
_080D1114:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	bl FUN_08009f6c\n\
	str r0, [r4, #0x58]\n\
	ldr r1, _080D1144 @ =0x0000C210\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xd]\n\
_080D112C:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, [r4, #0x18]\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080D11BA\n\
	ldr r1, _080D1148 @ =0x0000C214\n\
	b _080D11A2\n\
	.align 2, 0\n\
_080D1144: .4byte 0x0000C210\n\
_080D1148: .4byte 0x0000C214\n\
_080D114C:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, [r4, #0x18]\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080D11BA\n\
	ldr r1, _080D116C @ =0x0000C211\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	movs r0, #8\n\
	strb r0, [r4, #0x12]\n\
	b _080D11A8\n\
	.align 2, 0\n\
_080D116C: .4byte 0x0000C211\n\
_080D1170:\n\
	movs r2, #0\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r2, [r0]\n\
	adds r2, r4, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _080D11BA\n\
	ldr r1, _080D11B0 @ =0x0000C212\n\
_080D11A2:\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
_080D11A8:\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xd]\n\
	b _080D11BA\n\
	.align 2, 0\n\
_080D11B0: .4byte 0x0000C212\n\
_080D11B4:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
_080D11BA:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

NAKED static void Actor5_Update(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r6, r0, #0\n\
	ldrb r0, [r6, #0xd]\n\
	cmp r0, #6\n\
	bls _080D11CC\n\
	b _080D1366\n\
_080D11CC:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080D11D8 @ =_080D11DC\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080D11D8: .4byte _080D11DC\n\
_080D11DC: @ jump table\n\
	.4byte _080D11F8 @ case 0\n\
	.4byte _080D1256 @ case 1\n\
	.4byte _080D12B4 @ case 2\n\
	.4byte _080D12D4 @ case 3\n\
	.4byte _080D1304 @ case 4\n\
	.4byte _080D133A @ case 5\n\
	.4byte _080D1360 @ case 6\n\
_080D11F8:\n\
	ldr r0, [r6, #0x54]\n\
	ldr r1, [r6, #0x58]\n\
	bl FUN_08009f6c\n\
	str r0, [r6, #0x58]\n\
	ldrb r0, [r6, #0x11]\n\
	cmp r0, #0\n\
	bne _080D1248\n\
	movs r4, #0xaf\n\
	lsls r4, r4, #4\n\
	ldr r1, _080D1298 @ =gStaticMotionGraphics\n\
	adds r0, r4, r1\n\
	ldr r1, _080D129C @ =wStaticGraphicTilenums\n\
	movs r5, #0x8c\n\
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
	ldr r0, _080D12A0 @ =gStaticMotionGraphics+12\n\
	adds r4, r4, r0\n\
	ldr r0, _080D12A4 @ =wStaticMotionPalIDs\n\
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
_080D1248:\n\
	ldr r1, _080D12A8 @ =0x00008C05\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	ldrb r0, [r6, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r6, #0xd]\n\
_080D1256:\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, [r6, #0x18]\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080D127A\n\
	ldr r1, _080D12AC @ =0x00008C06\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	movs r0, #0x2d\n\
	strb r0, [r6, #0x12]\n\
	ldrb r0, [r6, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r6, #0xd]\n\
_080D127A:\n\
	ldr r0, [r6, #0x18]\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080D1366\n\
	ldr r1, _080D12B0 @ =0x00008C07\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	movs r0, #0xe\n\
	strb r0, [r6, #0x12]\n\
	movs r0, #3\n\
	strb r0, [r6, #0xd]\n\
	b _080D1366\n\
	.align 2, 0\n\
_080D1298: .4byte gStaticMotionGraphics\n\
_080D129C: .4byte wStaticGraphicTilenums\n\
_080D12A0: .4byte gStaticMotionGraphics+12\n\
_080D12A4: .4byte wStaticMotionPalIDs\n\
_080D12A8: .4byte 0x00008C05\n\
_080D12AC: .4byte 0x00008C06\n\
_080D12B0: .4byte 0x00008C07\n\
_080D12B4:\n\
	ldrb r0, [r6, #0x12]\n\
	adds r1, r0, #1\n\
	strb r1, [r6, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0x2c\n\
	bls _080D12CC\n\
	movs r0, #0x59\n\
	bl PlaySound\n\
	movs r0, #0\n\
	strb r0, [r6, #0x12]\n\
_080D12CC:\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
	b _080D1366\n\
_080D12D4:\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, [r6, #0x54]\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	str r0, [r6, #0x54]\n\
	ldrb r0, [r6, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r6, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _080D1366\n\
	ldr r1, _080D1300 @ =0x00008C05\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	movs r0, #8\n\
	strb r0, [r6, #0x12]\n\
	b _080D1354\n\
	.align 2, 0\n\
_080D1300: .4byte 0x00008C05\n\
_080D1304:\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r6, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r6, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
	cmp r2, #0\n\
	bne _080D1366\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r0, r6, #0\n\
	adds r0, #0x4c\n\
	strb r2, [r0]\n\
	adds r2, r6, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	movs r0, #8\n\
	strb r0, [r6, #0x12]\n\
	b _080D1354\n\
_080D133A:\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r6, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r6, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _080D1366\n\
	ldr r1, _080D135C @ =0x00008C06\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
_080D1354:\n\
	ldrb r0, [r6, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r6, #0xd]\n\
	b _080D1366\n\
	.align 2, 0\n\
_080D135C: .4byte 0x00008C06\n\
_080D1360:\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
_080D1366:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

NAKED static void Actor6_Update(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xd]\n\
	cmp r0, #7\n\
	bhi _080D1448\n\
	lsls r0, r0, #2\n\
	ldr r1, _080D1380 @ =_080D1384\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080D1380: .4byte _080D1384\n\
_080D1384: @ jump table\n\
	.4byte _080D13A4 @ case 0\n\
	.4byte _080D1448 @ case 1\n\
	.4byte _080D13BC @ case 2\n\
	.4byte _080D13DC @ case 3\n\
	.4byte _080D13FC @ case 4\n\
	.4byte _080D1418 @ case 5\n\
	.4byte _080D1430 @ case 6\n\
	.4byte _080D1448 @ case 7\n\
_080D13A4:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #8\n\
	adds r0, r4, #0\n\
	movs r2, #1\n\
	bl FUN_080d0aa0\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080D1448\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #2\n\
	b _080D1446\n\
_080D13BC:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, [r4, #0x18]\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080D1448\n\
	ldr r1, _080D13D8 @ =0x0000BE1C\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	b _080D1442\n\
	.align 2, 0\n\
_080D13D8: .4byte 0x0000BE1C\n\
_080D13DC:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, [r4, #0x18]\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080D1448\n\
	ldr r1, _080D13F8 @ =0x0000BE1D\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	b _080D1442\n\
	.align 2, 0\n\
_080D13F8: .4byte 0x0000BE1D\n\
_080D13FC:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _080D1448\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #8\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	b _080D1442\n\
_080D1418:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, [r4, #0x18]\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080D1448\n\
	movs r0, #0x1e\n\
	strb r0, [r4, #0x12]\n\
	b _080D1442\n\
_080D1430:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #8\n\
	adds r0, r4, #0\n\
	movs r2, #1\n\
	bl FUN_080d0934\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080D1448\n\
_080D1442:\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
_080D1446:\n\
	strb r0, [r4, #0xd]\n\
_080D1448:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void Actor7_Update(struct Solid* p) {
  switch ((p->s).mode[1]) {
    case 0: {
      (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y);
      wStaticGraphicTilenums[19] = 0x388;
      wStaticMotionPalIDs[19] = 9;
      LOAD_STATIC_GRAPHIC(SM019_PANTHEON_HUNTER);
      SetMotion(&p->s, MOTION(SM019_PANTHEON_HUNTER, 9));
      (p->s).mode[1]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateMotionGraphic(&p->s);
      (p->s).coord.x += PIXEL(1);
      break;
    }
  }
}

// --------------------------------------------

NAKED static void initActor8(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	adds r6, r0, #0\n\
	ldr r5, [r6, #0x54]\n\
	asrs r0, r5, #0xc\n\
	movs r1, #0xf\n\
	bl __modsi3\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	mov sb, r0\n\
	ldr r4, [r6, #0x58]\n\
	asrs r0, r4, #0xc\n\
	movs r1, #0xa\n\
	bl __modsi3\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	mov r8, r0\n\
	adds r0, r5, #0\n\
	adds r1, r4, #0\n\
	bl GetMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	cmp r2, #0\n\
	bne _080D1558\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r0, r6, #0\n\
	adds r0, #0x8c\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r6, #0xa]\n\
	ldr r1, _080D1554 @ =gSolidFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r6, #0x14]\n\
	b _080D172E\n\
	.align 2, 0\n\
_080D1554: .4byte gSolidFnTable\n\
_080D1558:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	ldr r0, [r6, #0x54]\n\
	str r0, [r6, #0x64]\n\
	ldr r0, [r6, #0x58]\n\
	str r0, [r6, #0x68]\n\
	movs r4, #0xba\n\
	ldr r0, _080D1630 @ =wStaticGraphicTilenums\n\
	lsls r1, r4, #1\n\
	adds r0, r0, r1\n\
	movs r2, #0xbf\n\
	lsls r2, r2, #2\n\
	strh r2, [r0]\n\
	ldr r0, _080D1634 @ =wStaticMotionPalIDs\n\
	adds r7, r0, r1\n\
	movs r0, #6\n\
	strh r0, [r7]\n\
	mov r1, r8\n\
	lsls r0, r1, #0x10\n\
	asrs r5, r0, #0x10\n\
	cmp r5, #1\n\
	bne _080D15C2\n\
	lsls r4, r4, #4\n\
	movs r0, #0xba\n\
	lsls r0, r0, #2\n\
	adds r4, r4, r0\n\
	ldr r1, _080D1638 @ =gStaticMotionGraphics\n\
	adds r0, r4, r1\n\
	ldrh r1, [r0, #6]\n\
	lsrs r1, r1, #6\n\
	subs r1, r2, r1\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	ldr r0, _080D163C @ =gStaticMotionGraphics+12\n\
	adds r4, r4, r0\n\
	ldrh r1, [r7]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
_080D15C2:\n\
	cmp r5, #0\n\
	bne _080D1680\n\
	ldrb r0, [r6, #0xa]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _080D1640 @ =Collision_08370ab8\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #0\n\
	bl InitBody\n\
	str r6, [r4, #0x2c]\n\
	str r5, [r4, #0x24]\n\
	adds r0, r6, #0\n\
	bl InitNonAffineMotion\n\
	movs r0, #0\n\
	strb r0, [r6, #0x11]\n\
	mov r1, sb\n\
	lsls r0, r1, #0x10\n\
	asrs r4, r0, #0x10\n\
	adds r0, r4, #0\n\
	subs r0, #0xf\n\
	lsls r0, r0, #6\n\
	str r0, [r6, #0x60]\n\
	lsls r0, r4, #4\n\
	adds r0, r0, r4\n\
	movs r1, #7\n\
	bl __modsi3\n\
	movs r1, #3\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #7\n\
	str r1, [r6, #0x5c]\n\
	ldr r2, _080D1644 @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _080D1648 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _080D164C @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #0x7f\n\
	ands r0, r1\n\
	strb r0, [r6, #0x12]\n\
	cmp r4, #0xd\n\
	ble _080D1654\n\
	ldr r1, _080D1650 @ =0x0000BA02\n\
	b _080D165A\n\
	.align 2, 0\n\
_080D1630: .4byte wStaticGraphicTilenums\n\
_080D1634: .4byte wStaticMotionPalIDs\n\
_080D1638: .4byte gStaticMotionGraphics\n\
_080D163C: .4byte gStaticMotionGraphics+12\n\
_080D1640: .4byte Collision_08370ab8\n\
_080D1644: .4byte RNG_0202f388\n\
_080D1648: .4byte 0x000343FD\n\
_080D164C: .4byte 0x00269EC3\n\
_080D1650: .4byte 0x0000BA02\n\
_080D1654:\n\
	cmp r4, #0xb\n\
	ble _080D1668\n\
	ldr r1, _080D1664 @ =0x0000BA01\n\
_080D165A:\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	b _080D1672\n\
	.align 2, 0\n\
_080D1664: .4byte 0x0000BA01\n\
_080D1668:\n\
	movs r1, #0xba\n\
	lsls r1, r1, #8\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
_080D1672:\n\
	ldr r0, [r6, #0x58]\n\
	ldr r2, _080D167C @ =0xFFFFF100\n\
	adds r0, r0, r2\n\
	b _080D1708\n\
	.align 2, 0\n\
_080D167C: .4byte 0xFFFFF100\n\
_080D1680:\n\
	adds r0, r6, #0\n\
	bl InitRotatableMotion\n\
	movs r0, #1\n\
	strb r0, [r6, #0x11]\n\
	ldr r0, _080D16C0 @ =0xFFFFFF00\n\
	str r0, [r6, #0x60]\n\
	movs r0, #3\n\
	mov r1, r8\n\
	ands r0, r1\n\
	subs r0, #1\n\
	strb r0, [r6, #0x12]\n\
	cmp r5, #2\n\
	bgt _080D16C8\n\
	ldr r1, _080D16C4 @ =0x0000BA06\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	movs r0, #2\n\
	strb r0, [r6, #0x11]\n\
	lsls r0, r5, #4\n\
	adds r0, r0, r5\n\
	movs r1, #3\n\
	bl __modsi3\n\
	movs r1, #4\n\
	rsbs r1, r1, #0\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #8\n\
	str r1, [r6, #0x5c]\n\
	b _080D16F8\n\
	.align 2, 0\n\
_080D16C0: .4byte 0xFFFFFF00\n\
_080D16C4: .4byte 0x0000BA06\n\
_080D16C8:\n\
	lsls r0, r5, #4\n\
	adds r0, r0, r5\n\
	movs r1, #3\n\
	bl __modsi3\n\
	movs r1, #3\n\
	rsbs r1, r1, #0\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #8\n\
	str r1, [r6, #0x5c]\n\
	cmp r5, #7\n\
	ble _080D16F0\n\
	ldr r1, _080D16EC @ =0x0000BA08\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	b _080D16F8\n\
	.align 2, 0\n\
_080D16EC: .4byte 0x0000BA08\n\
_080D16F0:\n\
	ldr r1, _080D173C @ =0x0000BA07\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
_080D16F8:\n\
	ldr r0, [r6, #0x54]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #4\n\
	adds r0, r0, r2\n\
	str r0, [r6, #0x54]\n\
	ldr r0, [r6, #0x58]\n\
	ldr r1, _080D1740 @ =0xFFFFF800\n\
	adds r0, r0, r1\n\
_080D1708:\n\
	str r0, [r6, #0x58]\n\
	movs r0, #0xa\n\
	mov r2, r8\n\
	subs r0, r0, r2\n\
	adds r1, r6, #0\n\
	adds r1, #0x25\n\
	strb r0, [r1]\n\
	ldr r1, _080D1744 @ =gSolidFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r6, #0x14]\n\
	adds r0, r6, #0\n\
	bl Actor_Update\n\
_080D172E:\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080D173C: .4byte 0x0000BA07\n\
_080D1740: .4byte 0xFFFFF800\n\
_080D1744: .4byte gSolidFnTable\n\
 .syntax divided\n");
}

INCASM("asm/solid/actor.inc");

// ------------------------------------------------------------------------------------------------------------------------------------

const struct Collision Collision_08370ab8 = {
  kind : DDP,
  faction : FACTION_ALLY,
  special : 0,
  damage : 1,
  atkType : 0x00,
  element : 0x00,
  nature : 0x00,
  comboLv : 0x00,
  hitzone : 0x00,
  hardness : 0x00,
  remaining : 0,
  layer : 0x00000001,
  range : {0x0000, 0x0800, 0x2000, 0x1000},
};

const struct Collision Collision_08370ad0 = {
  kind : DRP,
  faction : FACTION_ENEMY,
  damage : 0,
  atkType : 0xFF,
  element : 0xFF,
  nature : 0xFF,
  comboLv : 0xFF,
  hitzone : 0x01,
  remaining : 1,
  range : {0x0000, -0x1000, 0x1000, 0x2000},
};

const struct SlashedEnemy SlashedEnemy_08370ae8 = {
  m : MOTION(SM019_PANTHEON_HUNTER, 0x06),
  unk_02 : {0xFF, 0x11},
  c : {0, 0},
  d : {0x80, 0xFB00},
  unk_coord_0c : {0xFF, 0x1FF},
  unk_10 : {0, 0x40},
  unk_14 : {0x200, 0x200},
};

const u8 SlashedEnemy_08370b04[sizeof(struct SlashedEnemy)] = {
    0x07, 0x13, 0xFE, 0x11, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0xFE, 0x7F, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00,
};

const u8 SlashedEnemy_ARRAY_08370b20[2 * sizeof(struct SlashedEnemy)] = {
    0x08, 0x13, 0xFE, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0xFD, 0xFF, 0x01, 0xFF, 0x01, 0x00, 0x00, 0x40, 0x00, 0x00, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x05, 0x13, 0xFF, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x08, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00,
};

const struct Collision Collision_ARRAY_08370b58[11] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 1,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x2000, 0x2000},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {0x0000, -0x1000, 0x1000, 0x2000},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 1,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x2000, 0x7800},
    },
    [3] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 1,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x2000, 0x7800},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 1,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x02,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x2000, 0x7800},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 1,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x03,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x2000, 0x7800},
    },
    [6] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 1,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x04,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x2000, 0x7800},
    },
    [7] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 1,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x05,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x2000, 0x7800},
    },
    [8] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 1,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x06,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x2000, 0x7800},
    },
    [9] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 1,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x07,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x2000, 0x7800},
    },
    [10] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 1,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x08,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x2000, 0x7800},
    },
};

const struct Rect Rect_08370c60 = {PIXEL(8), PIXEL(8), PIXEL(16), PIXEL(16)};

const struct Collision Collision_ARRAY_08370c68[16] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {0x0000, -0x1000, 0x1000, 0x2000},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 1,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, -0x8000, 0x7800},
    },
    [2] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {0x0000, -0x1000, 0x1000, 0x2000},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {0x0000, -0x0E00, 0x1000, 0x1C00},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 1,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {-0x1800, -0x1000, 0x1000, 0x1000},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 1,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {-0x1800, -0x1000, 0x1000, 0x1000},
    },
    [6] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 1,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x02,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {-0x1800, -0x1000, 0x1000, 0x1000},
    },
    [7] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {0x0000, -0x1000, 0x1000, 0x2000},
    },
    [8] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 1,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1000, 0x1000},
    },
    [9] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 1,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1000, 0x1000},
    },
    [10] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 1,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x02,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1000, 0x1000},
    },
    [11] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 1,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {-0x1800, -0x1000, 0x1000, 0x1000},
    },
    [12] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 1,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x01,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {-0x1800, -0x1000, 0x1000, 0x1000},
    },
    [13] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 1,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x02,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {-0x1800, -0x1000, 0x1000, 0x1000},
    },
    [14] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {0x0000, -0x1000, 0x1000, 0x2000},
    },
    [15] = {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {0x0000, -0x1000, 0x1000, 0x2000},
    },
};

const s32 s32_ARRAY_08370de8[8] = {
    0x00000038, 0x00000020, 0x00000030, 0x00000040, 0x00000038, 0x00000030, 0x00000048, 0x00000030,
};

const struct Coord Coord_08370e08 = {PIXEL(0), -PIXEL(24)};

const struct Rect Rect_08370e10 = {0x0, 0x0, 0x1000, 0x2800};
