#include "collision.h"
#include "entity.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"
#include "vfx.h"
#include "vfx/after_image.h"
#include "zero.h"

const Coords32 Coord_08370e08;
struct Entity* CreateVFX39(struct Coord* c, u8 r1, u8 r2);
static const struct Collision sCollisions_08370B58[11];
static const struct Collision sCollisions_08370C68[16];

/*
  Actor:
  Solid.id が 21 の Entity は 基本的にスクリプト(GameCommand*)によって生成される、スクリプトの登場人物のようなもの
  どの種類のActorかは Solid.s.work[0] に格納される (constants/entity/solid.h の ACTOR_XXXX を参照)
*/

static void Actor_Init(struct Solid* p);
void Actor_Update(struct Solid* p);
void Actor_Die(struct Solid* p);

// clang-format off
const SolidRoutine gScriptActorRoutine = {
    [ENTITY_INIT] =      (void*)Actor_Init,
    [ENTITY_UPDATE] =    (void*)Actor_Update,
    [ENTITY_DIE] =       (void*)Actor_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

struct Solid* CreateScriptActor(struct Solid* e, u8 kind) {
  struct Solid* p = (struct Solid*)AllocEntityLast(gSolidHeaderPtr);
  if (p != NULL) {
    INIT_SOLID_ROUTINE(p, SOLID_SCRIPT_ACTOR);
    (p->s).work[0] = kind;
    (p->s).coord.x = (e->s).coord.x;
    (p->s).coord.y = (e->s).coord.y;
    (p->s).unk_28 = &e->s;
  }
  return p;
}

u16 FUN_080d08d0(struct Boss* babyelf, motion_t m) { return FUN_080d0934((void*)babyelf, m, (babyelf->flags2 >> 2) & 1); }

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
  (sInitializers[(p->s).work[0]])((void*)p);
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
  (sUpdates[(p->s).work[0]])((void*)p);
  return;
}

// --------------------------------------------

static void deleteActor(struct Solid* p);

void Actor_Die(struct Solid* p) {
  // clang-format off
  static const SolidFunc sDeinitalizer[] = {
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
  (sDeinitalizer[(p->s).work[0]])((void*)p);
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
      UpdateSpriteAnimation(p);
      if (p->work[2] & 1) {
        PaintEntityWhite((struct Entity*)p);
      } else {
        UpdateEntityPaletteID((struct Entity*)p);
      }
      p->work[2]--;
      if (p->work[2] == 0) {
        p->work[2] = 8;
        p->mode[3]++;
      }
      break;
    }
    case 2: {
      EnableSpriteAnimation_Affine(p);
      if (r2 != 0) {
        SetSpriteTableDynamic(p);
      }
      SetSpriteAnimation(p, m);
      p->mode[3]++;
    }
    case 3: {
      UpdateSpriteAnimation(p);
      PaintEntityWhite((struct Entity*)p);
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
      UpdateSpriteAnimation(p);
      PaintEntityWhite((struct Entity*)p);
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
      UpdateSpriteAnimation(p);
      PaintEntityWhite((struct Entity*)p);
      (p->spr).mag.x = 0x20;
      (p->d).y -= 0x40;
      (p->coord).y += (p->d).y * 2;
      if (0x3000 < Camera_GetDistance(&gStageRun.vm.camera, &p->coord)) {
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
NON_MATCH u16 FUN_080d0aa0(struct Entity* p, motion_t m, u8 r2) {
#if MODERN
  switch (p->mode[3]) {
    case 0: {
      EnableSpriteAnimation_Affine(p);
      if (r2 != 0) {
        SetSpriteTableDynamic(p);
      }
      SetSpriteAnimation(p, m);
      (p->spr).mag.x = 0x20;
      (p->spr).mag.y = 0x200;
      PaintEntityWhite((struct Entity*)p);
      (p->unk_coord).y = FUN_08009f6c((p->coord).x, (p->coord).y);
      (p->coord).y = gStageRun.vm.camera.viewport.y - PIXEL(96);
      p->mode[3]++;
    }
    case 1: {
      UpdateSpriteAnimation(p);
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
      UpdateSpriteAnimation(p);
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
      UpdateSpriteAnimation(p);
      (p->spr).mag.x = p->work[2] * -4 + 0x120;
      (p->spr).mag.y = p->work[2] * 4 + 0xe0;
      if (++p->work[2] < 9) {
        return 0;
      }
      p->mode[3]++;
      break;
    }
    case 4: {
      EnableSpriteAnimation_Normal(p);
      if (r2 != 0) {
        SetSpriteTableDynamic(p);
      }
      SetSpriteAnimation(p, m);
      p->work[2] = 30;
      p->mode[3]++;
    }
    case 5: {
      UpdateSpriteAnimation(p);
      if (p->work[2] & 1) {
        UpdateEntityPaletteID((struct Entity*)p);
      } else {
        PaintEntityWhite((struct Entity*)p);
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
  EnableSpriteAnimation_Normal(p);
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  Actor_Update(p);
}

static void initDynamicActor(struct Solid* p) {
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  EnableSpriteAnimation_Normal(p);
  SetSpriteTableDynamic(p);
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
  EXIT_BODY(p);
  (p->s).flags2 &= ~ENTI_PHYSICS;
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

static void Actor1_Update(struct Solid* p) {
  switch ((p->s).mode[1]) {
    case 0: {
      (p->s).renderPrio = 0x10;
      (p->s).coord.y = FUN_08009f6c((p->s).coord.x + PIXEL(240), (p->s).coord.y);
      (p->s).unk_2c = NULL;
      (p->s).renderPrio = 0x10;
      SetSpriteAnimation(p, MOTION(DM196_ZERO_WALK, 0));
      (p->s).mode[1]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      (p->s).coord.x += 0x50;
      if ((p->s).scriptEntity->flags & 1) {
        if ((p->s).motion.state == 4) {
          SetSpriteAnimation(p, MOTION(DM051_ZERO_UNK, 3));
          (p->s).work[2] = 0x10;
          (p->s).mode[1]++;
        }
      }
      break;
    }
    case 2: {
      UpdateSpriteAnimation(p);
      (p->s).work[2]--;
      if ((p->s).work[2] == 0) {
        SET_XFLIP(p, 0);
        (p->s).mode[1]++;
      }
      break;
    }
    case 3: {
      UpdateSpriteAnimation(p);
      if ((p->s).scriptEntity->flags & (1 << 1)) {
        SetSpriteAnimation(p, MOTION(DM051_ZERO_UNK, 1));
        (p->s).mode[1]++;
      }
      break;
    }
    case 4: {
      UpdateSpriteAnimation(p);
      if (IsSpriteAnimEnd(p)) {
        (p->s).work[2] = 8;
        (p->s).mode[1]++;
      }
      break;
    }
    case 5: {
      UpdateSpriteAnimation(p);
      (p->s).work[2]--;
      if ((p->s).work[2] == 0) {
        bool8 isRight = 1;
        SET_XFLIP(p, isRight);
        SetSpriteAnimation(p, MOTION(DM003_ZERO_DASH, 0));
        CreateParticle(&(p->s).coord, 0, ((p->s).flags >> 4) & isRight);
        PlaySound(SE_DASH_1);
        (p->s).work[2] = 0x20;
        (p->s).mode[1]++;
      }
      break;
    }
    case 6: {
      UpdateSpriteAnimation(p);
      if ((p->s).work[2] != 0) {
        (p->s).work[2]--;
        if ((p->s).unk_2c == NULL) {
          (p->s).unk_2c = CreateAfterImages(&p->s);
        }
      } else if ((p->s).unk_2c != NULL) {
        (p->s).unk_2c->work[1] = 1;
      }
      (p->s).coord.x += 0x380;
      break;
    }
  }
}

// --------------------------------------------

static void Actor2_Update(struct Solid* p) {
  switch ((p->s).mode[1]) {
    case 0: {
      (p->s).coord.y = FUN_08009f6c((p->s).coord.x + 0xF000, (p->s).coord.y);
      SetSpriteAnimation(p, MOTION(DM194_CIEL, 15));
      (p->s).mode[1]++;
      FALLTHROUGH
    }
    case 1: {
      UpdateSpriteAnimation(p);
      (p->s).coord.x += 0x50;
      if (((p->s).scriptEntity->flags & (1 << 0)) && ((p->s).motion.state == ANIM_NEXT_GOTO)) {
        SetSpriteAnimation(p, MOTION(DM194_CIEL, 17));
        (p->s).mode[1]++;
      }
      break;
    }
    case 2: {
      UpdateSpriteAnimation(p);
      if (!((p->s).scriptEntity->flags & (1 << 1))) {
        return;
      }
      SetSpriteAnimation(p, MOTION(DM194_CIEL, 19));
      (p->s).mode[1]++;
      break;
    }
    case 3: {
      UpdateSpriteAnimation(p);
      if (!((p->s).scriptEntity->flags & (1 << 2))) {
        return;
      }
      SetSpriteAnimation(p, MOTION(DM194_CIEL, 17));
      (p->s).mode[1]++;
      break;
    }
    case 4: {
      UpdateSpriteAnimation(p);
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
      SetSpriteAnimation(p, MOTION(SM130_PROLOGUE_RESISTANCE, 2));
      (p->s).mode[1]++;
      FALLTHROUGH
    }
    case 1: {
      UpdateSpriteAnimation(p);
      (p->s).coord.x += 0x50;
      if ((p->s).motion.state != ANIM_NEXT_GOTO) {
        return;
      }
      if (((p->s).scriptEntity->flags & 1) == 0) {
        return;
      }
      SetSpriteAnimation(p, MOTION(SM130_PROLOGUE_RESISTANCE, 0));
      (p->s).mode[1]++;
      break;
    }
    case 2: {
      UpdateSpriteAnimation(p);
      if (((p->s).scriptEntity->flags & 2) == 0) {
        return;
      }
      LOAD_STATIC_GRAPHIC(SM130_PROLOGUE_RESISTANCE);
      (p->s).mode[1]++;
      break;
    }
    case 3: {
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

static void Actor4_Update(struct Solid* p) {
  switch ((p->s).mode[1]) {
    case 0: {
      (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y);
      SetSpriteAnimation(p, MOTION(DM194_CIEL, 16));
      (p->s).mode[1]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      if ((p->s).scriptEntity->flags & 1) {
        SetSpriteAnimation(p, MOTION(DM194_CIEL, 20));
        (p->s).mode[1]++;
      }
      break;
    }
    case 2: {
      UpdateSpriteAnimation(p);
      if ((p->s).scriptEntity->flags & 2) {
        SetSpriteAnimation(p, MOTION(DM194_CIEL, 17));
        (p->s).work[2] = 8;
        (p->s).mode[1]++;
      }
      break;
    }
    case 3: {
      SET_XFLIP(p, 0);
      UpdateSpriteAnimation(p);
      (p->s).work[2]--;
      if ((p->s).work[2] == 0) {
        SetSpriteAnimation(p, MOTION(DM194_CIEL, 18));
        (p->s).mode[1]++;
      }
      break;
    }
    case 4: {
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

static void Actor5_Update(struct Solid* p) {
  switch ((p->s).mode[1]) {
    case 0: {
      (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y);
      if ((p->s).work[1] == 0) {
        LOAD_STATIC_GRAPHIC(SM140_RESISTANCE_MOB);
      }
      SetSpriteAnimation(p, MOTION(SM140_RESISTANCE_MOB, 5));
      (p->s).mode[1]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      if ((p->s).scriptEntity->flags & (1 << 0)) {
        SetSpriteAnimation(p, MOTION(SM140_RESISTANCE_MOB, 6));
        (p->s).work[2] = 45;
        (p->s).mode[1]++;
      }
      if ((p->s).scriptEntity->flags & (1 << 1)) {
        SetSpriteAnimation(p, MOTION(SM140_RESISTANCE_MOB, 7));
        (p->s).work[2] = 14;
        (p->s).mode[1] = 3;
      }
      break;
    }
    case 2: {
      if ((p->s).work[2]++ > 44) {
        PlaySound(SE_UNK_59);
        (p->s).work[2] = 0;
      }
      UpdateSpriteAnimation(p);
      break;
    }
    case 3: {
      UpdateSpriteAnimation(p);
      (p->s).coord.x += 0x1C0;
      (p->s).work[2]--;
      if ((p->s).work[2] == 0) {
        SetSpriteAnimation(p, MOTION(SM140_RESISTANCE_MOB, 5));
        (p->s).work[2] = 8;
        (p->s).mode[1]++;
      }
      break;
    }
    case 4: {
      UpdateSpriteAnimation(p);
      (p->s).work[2]--;
      if ((p->s).work[2] == 0) {
        SET_XFLIP(p, FALSE);
        (p->s).work[2] = 8;
        (p->s).mode[1]++;
      }
      break;
    }
    case 5: {
      UpdateSpriteAnimation(p);
      (p->s).work[2]--;
      if ((p->s).work[2] == 0) {
        SetSpriteAnimation(p, MOTION(SM140_RESISTANCE_MOB, 6));
        (p->s).mode[1]++;
      }
      break;
    }
    case 6: {
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

static void Actor6_Update(struct Solid* p) {
  switch ((p->s).mode[1]) {
    case 0: {
      if (FUN_080d0aa0(&p->s, MOTION(DM190_HARPUIA, 0), 1) != 0) {
        (p->s).mode[1] += 2;
      }
      break;
    }
    case 2: {
      UpdateSpriteAnimation(p);
      if ((p->s).scriptEntity->flags & (1 << 0)) {
        SetSpriteAnimation(p, MOTION(DM190_HARPUIA, 28));
        (p->s).mode[1]++;
      }
      break;
    }
    case 3: {
      UpdateSpriteAnimation(p);
      if ((p->s).scriptEntity->flags & (1 << 1)) {
        SetSpriteAnimation(p, MOTION(DM190_HARPUIA, 29));
        (p->s).mode[1]++;
      }
      break;
    }
    case 4: {
      UpdateSpriteAnimation(p);
      if (IsSpriteAnimEnd(p)) {
        SetSpriteAnimation(p, MOTION(DM190_HARPUIA, 0));
        (p->s).mode[1]++;
      }
      break;
    }
    case 5: {
      UpdateSpriteAnimation(p);
      if ((p->s).scriptEntity->flags & (1 << 2)) {
        (p->s).work[2] = 30;
        (p->s).mode[1]++;
      }
      break;
    }
    case 6: {
      if (FUN_080d0934(&p->s, MOTION(DM190_HARPUIA, 0), 1) != 0) {
        (p->s).mode[1]++;
      }
      break;
    }
    case 7: {
      break;
    }
  }
}

static void Actor7_Update(struct Solid* p) {
  switch ((p->s).mode[1]) {
    case 0: {
      (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y);
      wStaticGraphicTilenums[SM019_PANTHEON_HUNTER] = 904;
      wStaticMotionPalIDs[SM019_PANTHEON_HUNTER] = 9;
      LOAD_STATIC_GRAPHIC(SM019_PANTHEON_HUNTER);
      SetSpriteAnimation(p, MOTION(SM019_PANTHEON_HUNTER, 9));
      (p->s).mode[1]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
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

INCASM("asm/solid/actor_a.inc");

void ActorFefnir12_Update(struct Solid* p) {
  struct Coord c;
  switch ((p->s).mode[1]) {
    case 0: {
      register s32 z5 asm("r5");
      register struct Body* b asm("r4");
      {
        register u16* gt asm("r0");
        register s32 t2 asm("r2");
        register s32 v1 asm("r1");
        gt = wDynamicGraphicTilenums;
        asm("" : "+r"(gt));
        t2 = 0xA1 << 1;
        gt = (u16*)((u8*)gt + t2);
        v1 = 0x34D;
        *gt = v1;
        {
          register u16* pt asm("r0");
          pt = wDynamicMotionPalIDs;
          asm("" : "+r"(pt));
          pt = (u16*)((u8*)pt + t2);
          v1 = 9;
          *pt = v1;
        }
      }
      SetMotion(&p->s, MOTION(0xA1, 0x14));
      {
        register s32 one asm("r2");
        register s32 h asm("r1");
        register s32 g asm("r0");
        one = 1;
        h = (p->s).flags;
        asm("" : "+r"(h));
        g = 0x10;
        g |= h;
        (p->s).flags = g;
        {
          register u8* xp asm("r0");
          xp = (u8*)p + 0x4c;
          z5 = 0;
          *xp = one;
        }
      }
      {
        register u8* oa asm("r3");
        register s32 k16 asm("r2");
        register s32 ov asm("r1");
        register s32 m11 asm("r0");
        oa = (u8*)p + 0x4a;
        k16 = 0x10;
        ov = *oa;
        m11 = -0x11;
        m11 &= ov;
        m11 |= k16;
        *oa = m11;
      }
      {
        register s32 h2 asm("r1");
        register s32 g2 asm("r0");
        h2 = (p->s).flags;
        asm("" : "+r"(h2));
        g2 = 4;
        g2 |= h2;
        (p->s).flags = g2;
      }
      b = &p->body;
      ((void (*)(struct Body*, const struct Collision*, struct Coord*, s32))InitBody)(b, &sCollisions_08370B58[1], &(p->s).coord, 9);
      b->parent = (struct Entity*)p;
      b->fn = (BodyFunc)z5;
      *((u8*)p + 0x94) = 0x5a;
      PlaySound(0xF4);
      {
        register struct Camera* cam asm("r0");
        cam = &gStageRun.vm.camera;
        (p->s).coord.x = cam->viewport.x + 0x87FF;
      }
      (p->s).work[2] = 0x14;
      (p->s).mode[1]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateEntityAnim(&p->s);
      (p->s).coord.x += -0x300;
      {
        s32 t9 = (p->s).work[2] - 1;
        (p->s).work[2] = t9;
        if ((t9 << 24) != 0) {
          break;
        }
      }
      (p->s).work[2] = 8;
      SetMotion(&p->s, MOTION(0xA1, 0x00));
      (p->s).mode[1]++;
      break;
    }
    case 2: {
      UpdateEntityAnim(&p->s);
      {
        s32 c2 = (p->s).coord.x;
        (p->s).coord.x = c2 + -0x200;
        if (((p->s).work[2] & 3) == 0) {
          c.x = c2 + -0xE00;
          c.y = (p->s).coord.y;
          CreateSmoke(3, &c);
          c.x = (p->s).coord.x + (0x80 << 4);
          CreateSmoke(3, &c);
        }
      }
      {
        s32 t9 = (p->s).work[2] - 1;
        (p->s).work[2] = t9;
        if ((t9 << 24) != 0) {
          break;
        }
      }
      SetMotion(&p->s, MOTION(0xA1, 0x1B));
      (p->s).d.x = 0x80 << 2;
      (p->s).work[2] = 0x20;
      (p->s).mode[1]++;
      break;
    }
    case 3: {
      UpdateEntityAnim(&p->s);
      {
        s32 v = (p->s).d.x;
        s32 nv = (v * 15) >> 4;
        s32 nc;
        (p->s).d.x = nv;
        nc = (p->s).coord.x - nv;
        (p->s).coord.x = nc;
        if (((p->s).work[2] & 7) == 0) {
          c.x = nc + -0xC00;
          c.y = (p->s).coord.y;
          CreateSmoke(3, &c);
          c.x = (p->s).coord.x + (0x80 << 4);
          CreateSmoke(3, &c);
        }
      }
      {
        s32 t9 = (p->s).work[2] - 1;
        (p->s).work[2] = t9;
        if ((t9 << 24) != 0) {
          break;
        }
      }
      (p->s).mode[1]++;
      break;
    }
    case 4:
      UpdateEntityAnim(&p->s);
      if (((p->s).scriptEntity->flags & 1) == 0) {
        break;
      }
      SetMotion(&p->s, MOTION(0xA1, 0x1C));
      (p->s).work[2] = 0x3C;
      (p->s).mode[1]++;
      break;
    case 5: {
      UpdateEntityAnim(&p->s);
      {
        s32 t9 = (p->s).work[2] - 1;
        (p->s).work[2] = t9;
        if ((t9 << 24) != 0) {
          break;
        }
      }
      SetMotion(&p->s, MOTION(0xA1, 0x09));
      {
        register s32 k2 asm("r6");
        register u16* pt5 asm("r5");
        register u32 idx asm("r4");
        {
          register u16* gb asm("r0");
          u16* gt5;
          gb = wStaticGraphicTilenums;
          asm("" : "+r"(gb));
          gt5 = (u16*)((u8*)gb + 0x42);
          k2 = 0x80 << 2;
          *gt5 = k2;
        }
        pt5 = wStaticMotionPalIDs;
        asm("" : "+r"(pt5));
        pt5 = (u16*)((u8*)pt5 + 0x42);
        *pt5 = 4;
        idx = 0xA5 << 2;
        {
          register const u8* bg asm("r1");
          const struct Graphic* g;
          bg = (const u8*)gStaticMotionGraphics;
          asm("" : "+r"(bg));
          g = (const struct Graphic*)(idx + (u32)bg);
          LoadGraphic((void*)g, (void*)(((k2 - (*(u16*)((u8*)g + 6) >> 6)) << 5) + (0x80 << 9)));
        }
        {
          register const u8* b12 asm("r0");
          b12 = (const u8*)gStaticMotionGraphics + 12;
          asm("" : "+r"(b12));
          idx += (u32)b12;
          {
            register s32 a1 asm("r1");
            a1 = ((*pt5 - ((const struct Palette*)idx)->dst) << 5) + k2;
            LoadPalette((const struct Palette*)idx, a1);
            asm volatile("" ::"r"(idx));
          }
        }
      }
      (p->s).mode[1]++;
      break;
    }
    case 6:
    case 8:
    case 10:
      UpdateEntityAnim(&p->s);
      if (((p->s).scriptEntity->flags & 2) == 0) {
        break;
      }
      SetMotion(&p->s, MOTION(0xA1, 0x0B));
      CreateScriptActor(p, 0xD);
      PlaySound(0xF5);
      AppendQuake(2, &(p->s).coord);
      (p->s).mode[1]++;
      break;
    case 7:
    case 9:
    case 11:
      UpdateEntityAnim(&p->s);
      if (*((u8*)p + 0x73) != 3) {
        break;
      }
      (p->s).mode[1]++;
      break;
    case 12:
      UpdateEntityAnim(&p->s);
      SetMotion(&p->s, MOTION(0xA1, 0x00));
      (p->s).mode[1] = 0xE;
      break;
    case 14:
      UpdateEntityAnim(&p->s);
      if (((p->body).status & 1) == 0) {
        break;
      }
      SetMotion(&p->s, MOTION(0xA1, 0x14));
      PlaySound(0xF4);
      PlaySound(0x52);
      (p->s).work[2] = 8;
      (p->s).mode[1]++;
      FALLTHROUGH;
    case 15: {
      UpdateEntityAnim(&p->s);
      {
        s32 c2 = (p->s).coord.x;
        (p->s).coord.x = c2 + -0x200;
        if (((p->s).work[2] & 3) == 0) {
          c.x = c2 + -0xE00;
          c.y = (p->s).coord.y;
          CreateSmoke(3, &c);
          c.x = (p->s).coord.x + (0x80 << 4);
          CreateSmoke(3, &c);
        }
      }
      {
        s32 t9 = (p->s).work[2] - 1;
        (p->s).work[2] = t9;
        if ((t9 << 24) != 0) {
          break;
        }
      }
      SetMotion(&p->s, MOTION(0xA1, 0x1B));
      (p->s).d.x = 0x80 << 3;
      (p->s).work[2] = 0x18;
      (p->s).mode[1]++;
      break;
    }
    case 16: {
      UpdateEntityAnim(&p->s);
      {
        s32 v = (p->s).d.x;
        s32 nv = (v * 7) >> 3;
        s32 nc;
        (p->s).d.x = nv;
        nc = (p->s).coord.x - nv;
        (p->s).coord.x = nc;
        if (((p->s).work[2] & 7) == 0) {
          c.x = nc + -0xC00;
          c.y = (p->s).coord.y;
          CreateSmoke(3, &c);
          c.x = (p->s).coord.x + (0x80 << 4);
          CreateSmoke(3, &c);
        }
      }
      {
        s32 t9 = (p->s).work[2] - 1;
        (p->s).work[2] = t9;
        if ((t9 << 24) != 0) {
          break;
        }
      }
      (p->s).mode[1]++;
      break;
    }
    case 17:
      UpdateEntityAnim(&p->s);
      if (((p->s).scriptEntity->flags & 4) == 0) {
        break;
      }
      SetMotion(&p->s, MOTION(0xA1, 0x1C));
      (p->s).mode[1]++;
      break;
    case 18:
      UpdateEntityAnim(&p->s);
      if (*((u8*)p + 0x73) != 3) {
        break;
      }
      SetMotion(&p->s, MOTION(0xA1, 0x00));
      (p->s).mode[1]++;
      break;
    case 19: {
      register s32 t asm("r0");
      t = FUN_080d0934(&p->s, MOTION(0xA1, 0x00), 1) << 16;
      if (t == 0) {
        break;
      }
    }
      (p->s).mode[1]++;
      break;
    case 13:
    case 20:
      break;
  }
}

INCASM("asm/solid/actor_b.inc");

void initActor21(struct Solid* p) {
  register u32 z asm("r4");
  register struct WramWindowRegister* w asm("r2");
  w = &gWindowRegBuffer;
  {
    register u16 d asm("r3");
    register u32 k asm("r4");
    register u32 v asm("r1");
    d = w->dispcnt;
    k = DISPCNT_WIN1_ON;
    asm("" : "+l"(k));
    v = k;
    asm("" : "+l"(v));
    z = 0;
    v |= d;
    w->dispcnt = v;
  }
  {
    u8 t = w->winin[2];
    u32 v = 0xFE;
    v |= t;
    w->winin[2] = v;
  }
  {
    register u32 one asm("r3");
    one = ENTITY_UPDATE;
    asm("" : "+l"(one));
    w->winin[1] = z;
    (p->s).work[2] = z;
    {
      u32 tbl, id;
      EntityFunc** routine_table;
      tbl = (u32)(gSolidFnTable);
      id = ((p->s).id) << 2;
      routine_table = (EntityFunc**)(tbl + id);
      *(u32*)((p->s).mode) = one;
      (p->s).onUpdate = (void*)(*routine_table)[ENTITY_UPDATE];
    }
  }
  Actor_Update(p);
}

INCASM("asm/solid/actor_c.inc");

void ActorOmegaZero40_Update(struct Solid* p0) {
  register struct Solid* p asm("r6");
  p = p0;
  switch ((p->s).mode[1]) {
    case 0:
      (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y);
      LoadZeroPalette(NULL, 8);
      (p->s).tileNum = 0x80 << 2;
      (p->s).palID = 4;
      SetMotion(&p->s, MOTION(0x3F, 0x05));
      (p->s).mode[1]++;
      FALLTHROUGH;
    case 1: {
      UpdateEntityAnim(&p->s);
      if (((p->s).scriptEntity->flags & 1) == 0) {
        break;
      }
      (p->s).unk_coord.x = (p->s).coord.x;
      (p->s).unk_coord.y = (p->s).coord.y + -0xC00;
      PlaySound(0x8D << 1);
      (p->s).unk_28 = CreateVFX39(&(p->s).unk_coord, 3, 0);
      {
        u8* t7 = (u8*)(p->s).unk_28 + 0x7c;
        u32 z = 0;
        *t7 = z;
        *((u8*)(p->s).unk_28 + 0x74) = z;
        *((u8*)(p->s).unk_28 + 0x75) = z;
        *((u8*)(p->s).unk_28 + 0x76) = z;
        *(u32*)((u8*)(p->s).unk_28 + 0x78) = z;
        (p->s).work[2] = z;
        (p->s).work[3] = z;
      }
      (p->s).mode[1]++;
      break;
    }
    case 2: {
      UpdateEntityAnim(&p->s);
      (p->s).work[3]++;
      {
        struct Entity* q = (p->s).unk_28;
        s32 sv = gSineTable[(p->s).work[2] >> 1];
        *(s32*)((u8*)q + 0x78) = sv * 24;
      }
      {
        struct Entity* q2 = *(struct Entity* volatile*)&(p->s).unk_28;
        u32 b = ((p->s).work[3] & 1) << 11;
        *(s32*)((u8*)q2 + 0x78) += b;
      }
      if (((p->s).scriptEntity->flags & 1) != 0) {
        u32 w2 = (p->s).work[2];
        if ((s8)(p->s).work[2] < 0) {
          break;
        }
        (p->s).work[2] = w2 + 3;
        break;
      }
      {
        u32 w2 = (p->s).work[2];
        if (w2 > 3) {
          (p->s).work[2] = w2 - 3;
          break;
        }
      }
      *((u8*)(p->s).unk_28 + 0x77) = 1;
      (p->s).mode[1]++;
      break;
    }
    case 3: {
      UpdateEntityAnim(&p->s);
      if (((p->s).scriptEntity->flags & 2) == 0) {
        break;
      }
      (p->s).unk_coord.x = (p->s).coord.x;
      (p->s).unk_coord.y = (p->s).coord.y + -0xC00;
      {
        u32 z;
        struct Body* body;
        (p->s).flags |= 4;
        z = 0;
        body = &p->body;
        InitBody(body, &sCollisions_08370C68[1], &(p->s).coord, 1);
        body->parent = (struct Entity*)p;
        body->fn = (void*)z;
        PlaySound(0x8D << 1);
        (p->s).unk_28 = CreateVFX39(&(p->s).unk_coord, 3, 0);
        {
          u8* t7 = (u8*)(p->s).unk_28 + 0x7c;
          *t7 = z;
        }
        *((u8*)(p->s).unk_28 + 0x74) = z;
        *((u8*)(p->s).unk_28 + 0x75) = z;
        *((u8*)(p->s).unk_28 + 0x76) = z;
        *(u32*)((u8*)(p->s).unk_28 + 0x78) = z;
        (p->s).work[2] = z;
        (p->s).work[3] = z;
      }
      (p->s).mode[1]++;
      break;
    }
    case 4: {
      UpdateEntityAnim(&p->s);
      (p->s).work[3]++;
      {
        u32 w2 = (p->s).work[2];
        if (w2 <= 0x3F) {
          (p->s).work[2] = w2 + 0x10;
        }
      }
      {
        u32 w3 = (p->s).work[3];
        register u32 k1 asm("r3");
        u32 m;
        k1 = 1;
        m = k1;
        asm("" : "+r"(m));
        m &= w3;
        if (m != 0) {
          if (w3 > 3) {
            if ((RANDOM(RNG_0202f388) & k1) != 0) {
              goto zero4;
            }
          }
          {
            struct Entity* q = (p->s).unk_28;
            s32 sv;
            asm("" : "+r"(q));
            sv = gSineTable[(p->s).work[2]];
            *(s32*)((u8*)q + 0x78) = sv << 6;
          }
        } else {
        zero4:
          *(s32*)((u8*)(p->s).unk_28 + 0x78) = 0;
        }
      }
      if ((p->s).work[3] <= 0x40) {
        break;
      }
      {
        u8* t7 = (u8*)*(struct Entity* volatile*)&(p->s).unk_28 + 0x77;
        u32 z = 0;
        u32 one = 1;
        *t7 = one;
        {
          u8* t = (u8*)p + 0x8c;
          *(u32*)t = z;
        asm("" : "+r"(t));
        t += 4;
        *(u32*)t = z;
          asm("" : "+r"(t));
          t += 4;
          *t = z;
        }
      }
      (p->s).flags &= 0xFB;
      (p->s).mode[1]++;
      break;
    }
    case 5:
      UpdateEntityAnim(&p->s);
      if (((p->s).scriptEntity->flags & 4) == 0) {
        break;
      }
      (p->s).mode[1]++;
      break;
    case 6:
      SetMotion(&p->s, MOTION(0x35, 0x01));
      (p->s).mode[1]++;
      FALLTHROUGH;
    case 7:
      UpdateEntityAnim(&p->s);
      if (*((u8*)p + 0x73) != 3) {
        break;
      }
      (p->s).mode[1]++;
      break;
    case 8:
      SetMotion(&p->s, 0);
      (p->s).work[2] = 3;
      (p->s).mode[1]++;
      FALLTHROUGH;
    case 9: {
      u32 t;
      UpdateEntityAnim(&p->s);
      t = (p->s).work[2] - 1;
      (p->s).work[2] = t;
      if ((t << 24) != 0) {
        break;
      }
      (p->s).mode[1]++;
      break;
    }
    case 10: {
      u32 z;
      struct Body* body;
      SetMotion(&p->s, 0xCC << 6);
      (p->s).flags |= 4;
      z = 0;
      body = &p->body;
      InitBody(body, &sCollisions_08370C68[2], &(p->s).coord, 1);
      body->parent = (struct Entity*)p;
      body->fn = (void*)z;
      (p->s).work[2] = z;
      (p->s).mode[1]++;
      FALLTHROUGH;
    }
    case 11: {
      UpdateEntityAnim(&p->s);
      if (MOTION_VALUE(p) != 0) {
        if (*((u8*)p + 0x73) == 3) {
          SetMotion(&p->s, 0);
        }
      }
      if ((*(u32*)((u8*)p + 0x8c) & 1) != 0) {
        u32 t = (p->s).work[2] + 1;
        (p->s).work[2] = t;
        if ((t & 1) != 0) {
          SetMotion(&p->s, 0xC4 << 6);
        } else {
          SetMotion(&p->s, 0xC8 << 6);
        }
        PlaySound(0x13B);
      }
      if (((p->s).scriptEntity->flags & 8) == 0) {
        break;
      }
      (p->s).unk_coord.x = (p->s).coord.x;
      (p->s).unk_coord.y = (p->s).coord.y + -0xC00;
      {
        u32 z;
        struct Body* body;
        (p->s).flags |= 4;
        z = 0;
        body = &p->body;
        InitBody(body, &sCollisions_08370C68[1], &(p->s).coord, 1);
        body->parent = (struct Entity*)p;
        body->fn = (void*)z;
        PlaySound(0x8D << 1);
        (p->s).unk_28 = CreateVFX39(&(p->s).unk_coord, 3, 0);
        {
          u8* t7 = (u8*)(p->s).unk_28 + 0x7c;
          *t7 = z;
        }
        *((u8*)(p->s).unk_28 + 0x74) = z;
        *((u8*)(p->s).unk_28 + 0x75) = z;
        *((u8*)(p->s).unk_28 + 0x76) = z;
        *(u32*)((u8*)(p->s).unk_28 + 0x78) = z;
        (p->s).work[2] = z;
        (p->s).work[3] = z;
      }
      (p->s).mode[1]++;
      break;
    }
    case 12: {
      UpdateEntityAnim(&p->s);
      if (MOTION_VALUE(p) != 0) {
        if (*((u8*)p + 0x73) == 3) {
          SetMotion(&p->s, 0);
        }
      }
      (p->s).work[3]++;
      {
        u32 w2 = (p->s).work[2];
        if (w2 <= 0x3F) {
          (p->s).work[2] = w2 + 0x10;
        }
      }
      {
        u32 w3 = (p->s).work[3];
        register u32 k1 asm("r3");
        u32 m;
        k1 = 1;
        m = k1;
        asm("" : "+r"(m));
        m &= w3;
        if (m != 0) {
          if (w3 > 3) {
            if ((RANDOM(RNG_0202f388) & k1) != 0) {
              goto zero12;
            }
          }
          {
            struct Entity* q = (p->s).unk_28;
            s32 sv;
            asm("" : "+r"(q));
            sv = gSineTable[(p->s).work[2]];
            *(s32*)((u8*)q + 0x78) = sv << 6;
          }
        } else {
        zero12:
          *(s32*)((u8*)(p->s).unk_28 + 0x78) = 0;
        }
      }
      if ((p->s).work[3] <= 0x40) {
        break;
      }
      {
        register u8* t7 asm("r1");
        register u32 z2 asm("r2");
        u32 z;
        u32 one12;
        t7 = (u8*)*(struct Entity* volatile*)&(p->s).unk_28 + 0x77;
        asm volatile("mov %0, #0" : "=r"(z2));
        asm volatile("" ::"r"(z2));
        z = 0;
        one12 = 1;
        *t7 = one12;
        if (((p->s).scriptEntity->flags & 0x10) == 0) {
          struct Body* body;
          u32 res = (p->s).flags;
          res |= 4;
          (p->s).flags = res;
          body = &p->body;
          InitBody(body, &sCollisions_08370C68[2], &(p->s).coord, 1);
          body->parent = (struct Entity*)p;
          body->fn = (void*)z;
          (p->s).mode[1] = 0xB;
        } else {
          struct Body* body;
          u32 res = (p->s).flags;
          res |= 4;
          (p->s).flags = res;
          body = &p->body;
          InitBody(body, &sCollisions_08370C68[3], &(p->s).coord, 1);
          body->parent = (struct Entity*)p;
          body->fn = (void*)z;
          SetMotion(&p->s, 0xD4 << 6);
          (p->s).mode[1]++;
        }
      }
      break;
    }
    case 13:
      UpdateEntityAnim(&p->s);
      if (*((u8*)p + 0x73) != 4) {
        break;
      }
      SetMotion(&p->s, MOTION(0x3F, 0x05));
      (p->s).mode[1]++;
      break;
    case 14: {
      u32 one;
      u32 v14;
      UpdateEntityAnim(&p->s);
      v14 = *(u32*)((u8*)p + 0x8c);
      one = 1;
      asm("" : "+r"(one));
      if ((v14 & one) == 0) {
        break;
      }
      SetMotion(&p->s, 0xC8 << 6);
      {
        register u8* sr3 asm("r3");
        register u32 ms asm("r2");
        u32 m14;
        sr3 = (u8*)&gStageRun;
        ms = *(u16*)(sr3 + 8);
        m14 = one;
        asm("" : "+r"(m14));
        m14 &= ms;
        if (m14 != 0) {
          u32 fb = *(sr3 + 0x12);
          u32 m15 = one;
          asm("" : "+r"(m15));
          m15 &= fb;
          if (m15 == 0) {
            u32 nm = 0xFFFE;
            nm &= ms;
            nm |= 0x10;
            *(u16*)(sr3 + 8) = nm;
          }
        }
      }
      (p->s).unk_2c = CreateBossExplosion((struct Entity*)p, (struct Coord*)&Coord_08370e08);
      (p->s).mode[1]++;
      break;
    }
    case 15:
      UpdateEntityAnim(&p->s);
      if (((p->s).unk_2c)->mode[0] <= 1) {
        break;
      }
      {
        u8* sr = (u8*)&gStageRun;
        asm("" : "+r"(sr));
        {
          u32 fl = *(sr + 0x12);
          u32 res = 2;
          res |= fl;
          *(sr + 0x12) = res;
        }
      }
      (p->s).mode[1]++;
      break;
  }
}

INCASM("asm/solid/actor_d.inc");

void ActorLastHarpuia_Update(struct Solid* p) {
  switch ((p->s).mode[1]) {
    case 0: {
      register s32 off asm("r2");
      {
        register u16* q asm("r0");
        register s32 v asm("r1");
        q = wDynamicGraphicTilenums;
        off = 0xbe << 1;
        q = (u16*)((u8*)q + off);
        v = 0xf0;
        v <<= 2;
        *q = v;
      }
      {
        register u16* q asm("r0");
        register s32 v asm("r1");
        q = wDynamicMotionPalIDs;
        q = (u16*)((u8*)q + off);
        v = 9;
        *q = v;
      }
      (p->s).mode[1]++;
      FALLTHROUGH;
    }
    case 1:
      if (((u16)FUN_080d0aa0(&p->s, MOTION(0xBE, 0x03), 1) << 16) == 0) {
        break;
      }
      SetMotion(&p->s, MOTION(0xBE, 0x14));
      (p->s).d.x = 0;
      goto bump;
    case 2:
      UpdateEntityAnim(&p->s);
      if ((p->s).d.x <= 0x3FF) {
        (p->s).d.x += 0x40;
      }
      (p->s).coord.x += (p->s).d.x;
      if (*((u8*)p + 0x73) != 3) {
        break;
      }
      SetMotion(&p->s, MOTION(0xBE, 0x15));
      goto bump;
    case 3:
      UpdateEntityAnim(&p->s);
      if ((p->s).d.x <= 0x3FF) {
        (p->s).d.x += 0x40;
      }
      (p->s).coord.x += (p->s).d.x;
      if (*((u8*)p + 0x73) != 3) {
        break;
      }
      goto bump;
    case 4:
      UpdateEntityAnim(&p->s);
      if ((p->s).d.x <= 0x3FF) {
        (p->s).d.x += 0x40;
      }
      (p->s).coord.x += (p->s).d.x;
      if ((p->s).coord.x <= 0xB1800) {
        break;
      }
      SetMotion(&p->s, MOTION(0xBE, 0x16));
      PlaySound(0xF9);
      (p->s).work[2] = 0;
      goto bump;
    case 5: {
      s32 t;
      u32 z5;
      UpdateEntityAnim(&p->s);
      t = (p->s).work[2] + 1;
      z5 = 0;
      (p->s).work[2] = t;
      if ((u8)t == 6) {
        struct Body* body;
        (p->s).flags |= COLLIDABLE;
        body = &p->body;
        InitBody(body, &sCollisions_08370C68[4], &(p->s).coord, 1);
        body->parent = (struct Entity*)p;
        body->fn = (void*)z5;
      }
      if (*((u8*)p + 0x73) != 3) {
        break;
      }
      SetMotion(&p->s, MOTION(0xBE, 0x17));
      PlaySound(0xF9);
      (p->s).work[2] = z5;
      asm volatile("");
      goto bump;
    }
    case 6: {
      s32 t;
      u32 z6;
      UpdateEntityAnim(&p->s);
      t = (p->s).work[2] + 1;
      z6 = 0;
      (p->s).work[2] = t;
      if ((u8)t == 0xA) {
        struct Body* body;
        (p->s).flags |= COLLIDABLE;
        body = &p->body;
        InitBody(body, &sCollisions_08370C68[5], &(p->s).coord, 1);
        body->parent = (struct Entity*)p;
        body->fn = (void*)z6;
      }
      if (*((u8*)p + 0x73) != 3) {
        break;
      }
      SetMotion(&p->s, MOTION(0xBE, 0x18));
      PlaySound(0xF9);
      (p->s).work[2] = z6;
      goto bump;
    }
    case 7: {
      s32 t;
      u32 z7;
      UpdateEntityAnim(&p->s);
      t = (p->s).work[2] + 1;
      z7 = 0;
      (p->s).work[2] = t;
      if ((u8)t == 0xA) {
        struct Body* body;
        (p->s).flags |= COLLIDABLE;
        body = &p->body;
        InitBody(body, &sCollisions_08370C68[6], &(p->s).coord, 1);
        body->parent = (struct Entity*)p;
        body->fn = (void*)z7;
      }
      if (*((u8*)p + 0x73) != 3) {
        break;
      }
      {
        struct Body* body;
        (p->s).flags |= COLLIDABLE;
        body = &p->body;
        InitBody(body, &sCollisions_08370C68[7], &(p->s).coord, 1);
        body->parent = (struct Entity*)p;
        body->fn = (void*)z7;
      }
      goto bump;
    }
    case 8:
      UpdateEntityAnim(&p->s);
      if ((*(u32*)((u8*)p + 0x8c) & 1) == 0) {
        break;
      }
      SetMotion(&p->s, MOTION(0xBE, 0x0C));
      PlaySound(0xF8);
      (p->s).d.x = 0x300;
      (p->s).d.y = -0x400;
      goto bump;
    case 9: {
      UpdateEntityAnim(&p->s);
      (p->s).coord.x -= (p->s).d.x;
      (p->s).coord.y += (p->s).d.y;
      (p->s).d.y += 0x20;
      if ((p->s).d.y >= -0x100) {
        (p->s).d.x = (((p->s).d.x << 4) - (p->s).d.x) >> 4;
      }
      if ((p->s).d.y < 0) {
        break;
      }
      SetMotion(&p->s, MOTION(0xBE, 0x0D));
      {
        u32 z9 = 0;
        (p->s).d.y = z9;
        (p->s).unk_coord.y = (p->s).coord.y;
        (p->s).work[2] = z9;
      }
    bump:
      (p->s).mode[1]++;
      break;
    }
    case 10: {
      s32 d0, nd;
      UpdateEntityAnim(&p->s);
      d0 = (p->s).d.x;
      nd = ((d0 << 3) - d0) >> 3;
      (p->s).d.x = nd;
      (p->s).coord.x -= nd;
      {
        s32 w = (p->s).work[2] + 1;
        (p->s).work[2] = w;
        (p->s).coord.y = (p->s).unk_coord.y + (gSineTable[(u8)(w * 2)] << 2);
      }
      break;
    }
  }
}

INCASM("asm/solid/actor_e.inc");

void FUN_080d6504(struct Solid* p) {
  struct Entity* q = *(struct Entity**)((u8*)p + 0x28);
  switch ((p->s).mode[1]) {
    case 0: {
      u16* tn = wStaticGraphicTilenums;
      register u32 z asm("r5");
      register u32 v asm("r0");
      z = 0;
      v = 0x23A;
      tn[SM009_OMEGA_HAND] = v;
      wStaticMotionPalIDs[SM009_OMEGA_HAND] = 5;
      LOAD_STATIC_GRAPHIC(SM009_OMEGA_HAND);
      InitNonAffineMotion(&p->s);
      SetMotion(&p->s, MOTION(SM009_OMEGA_HAND, 1));
      *((u8*)p + 0x25) = 0x1C;
      (p->s).work[2] = z;
      (p->s).mode[1]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateEntityAnim(&p->s);
      (p->s).work[2]++;
      (p->s).coord.x = q->coord.x + 0x1500;
      {
        s32 sv = gSineTable[(p->s).work[2]] + -0x3800;
        (p->s).coord.y = q->coord.y + sv;
      }
      {
        u8 qm = q->mode[2];
        if (qm == 1 || qm == 4) {
          (p->s).mode[1]++;
        }
      }
      break;
    }
    case 2:
    case 6: {
      u32 z2;
      if (q->mode[2] == 4) {
        PlaySound(0x52);
      }
      InitRotatableMotion(&p->s);
      SetMotion(&p->s, MOTION(SM009_OMEGA_HAND, 2));
      *((u8*)p + 0x24) = 0x28;
      z2 = 0;
      (p->s).flags &= 0xEF;
      *((u8*)p + 0x4c) = z2;
      {
        u8* oa = (u8*)p + 0x4a;
        s32 ov = *oa;
        s32 m11 = -0x11;
        m11 &= ov;
        *oa = m11;
      }
      (p->s).work[2] = 6;
      (p->s).mode[1]++;
      FALLTHROUGH;
    }
    case 3:
    case 7: {
      s32 cx, cy;
      UpdateEntityAnim(&p->s);
      cx = q->coord.x;
      (p->s).coord.x = cx + 0x500;
      cy = q->coord.y;
      (p->s).coord.y = cy + -0x4800;
      if (q->mode[2] == 4) {
        if ((p->s).work[2] == 0) {
          break;
        }
        (p->s).work[2]--;
        if ((((p->s).work[2] / 3) & 1) != 0) {
          (p->s).coord.x = cx + 0x300;
          (p->s).coord.y = cy + -0x4A00;
        }
        break;
      }
      {
        s32 w = (p->s).work[2] - 1;
        (p->s).work[2] = w;
        if ((u8)w != 0) {
          break;
        }
      }
      (p->s).mode[1]++;
      break;
    }
    case 4:
      PlaySound(0x52);
      InitRotatableMotion(&p->s);
      SetMotion(&p->s, MOTION(SM009_OMEGA_HAND, 1));
      *((u8*)p + 0x24) = 0x58;
      (p->s).work[2] = 0xC;
      (p->s).mode[1]++;
      FALLTHROUGH;
    case 5: {
      s32 cx, cy;
      UpdateEntityAnim(&p->s);
      cx = q->coord.x;
      (p->s).coord.x = cx + 0x100;
      cy = q->coord.y;
      (p->s).coord.y = cy + -0x5800;
      if ((p->s).work[2] != 0) {
        (p->s).work[2]--;
        if ((((p->s).work[2] / 3) & 1) != 0) {
          (p->s).coord.x = cx + -0x100;
          (p->s).coord.y = cy + -0x5A00;
        }
      }
      if (q->mode[2] == 2) {
        (p->s).mode[1]++;
      }
      break;
    }
    case 8: {
      u32 one;
      PlaySound(0x52);
      InitRotatableMotion(&p->s);
      SetMotion(&p->s, MOTION(SM009_OMEGA_HAND, 0));
      *((u8*)p + 0x24) = 0x20;
      one = 1;
      (p->s).flags |= 0x10;
      {
        u8* x4c = (u8*)p + 0x4c;
        register u32 z3 asm("r3");
        z3 = 0;
        *x4c = one;
        {
          register u8* oa asm("r4");
          register s32 k asm("r2");
          oa = (u8*)p + 0x4a;
          k = 0x10;
          {
            s32 ov = *oa;
            s32 m11 = -0x11;
            m11 &= ov;
            m11 |= k;
            *oa = m11;
          }
        }
        (p->s).work[2] = z3;
      }
      (p->s).mode[1]++;
      FALLTHROUGH;
    }
    case 9: {
      s32 cx, cy;
      UpdateEntityAnim(&p->s);
      cx = q->coord.x;
      (p->s).coord.x = cx + 0x2900;
      cy = q->coord.y;
      (p->s).coord.y = cy + -0x3C00;
      (p->s).work[2]++;
      if ((((p->s).work[2] / 3) & 1) != 0) {
        (p->s).coord.x = cx + 0x2800;
        (p->s).coord.y = cy + -0x3D00;
      }
      if (q->mode[2] == 3) {
        (p->s).mode[1]++;
      }
      break;
    }
    case 10: {
      u32 z4;
      u32 one4;
      PlaySound(0x52);
      InitNonAffineMotion(&p->s);
      SetMotion(&p->s, MOTION(SM009_OMEGA_HAND, 1));
      z4 = 0;
      (p->s).flags &= 0xEF;
      one4 = 1;
      *((u8*)p + 0x4c) = z4;
      {
        u8* oa = (u8*)p + 0x4a;
        s32 ov = *oa;
        s32 m11 = -0x11;
        m11 &= ov;
        *oa = m11;
      }
      UpdateEntityAnim(&p->s);
      (p->s).mode[1] = one4;
      break;
    }
  }
}

void FUN_080d6814(struct Solid* p) {
  struct Entity* q = *(struct Entity**)((u8*)p + 0x28);
  switch ((p->s).mode[1]) {
    case 0: {
      u16* tn = wStaticGraphicTilenums;
      register u32 z asm("r4");
      register u32 v asm("r0");
      z = 0;
      v = 0x23A;
      tn[SM009_OMEGA_HAND] = v;
      wStaticMotionPalIDs[SM009_OMEGA_HAND] = 5;
      InitNonAffineMotion(&p->s);
      SetMotion(&p->s, MOTION(SM009_OMEGA_HAND, 0));
      *((u8*)p + 0x49) |= 0xC;
      (p->s).work[2] = z;
      (p->s).mode[1]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateEntityAnim(&p->s);
      (p->s).coord.x = q->coord.x + -0x1300;
      {
        s32 sv = gSineTable[(p->s).work[2]] + -0x3A00;
        (p->s).coord.y = q->coord.y + sv;
      }
      {
        u8 qm = q->mode[2];
        if (qm == 1 || qm == 4) {
          (p->s).mode[1]++;
        }
      }
      break;
    }
    case 2:
    case 6: {
      u32 z2;
      InitRotatableMotion(&p->s);
      SetMotion(&p->s, MOTION(SM009_OMEGA_HAND, 0));
      *((u8*)p + 0x24) = 0x30;
      z2 = 0;
      (p->s).flags &= 0xEF;
      *((u8*)p + 0x4c) = z2;
      {
        u8* oa = (u8*)p + 0x4a;
        s32 ov = *oa;
        s32 m11 = -0x11;
        m11 &= ov;
        *oa = m11;
      }
      (p->s).work[2] = 6;
      (p->s).mode[1]++;
      FALLTHROUGH;
    }
    case 3:
    case 7: {
      s32 cx, cy;
      UpdateEntityAnim(&p->s);
      cx = q->coord.x;
      (p->s).coord.x = cx + -0x2300;
      cy = q->coord.y + -0x4A00;
      asm("" : "+r"(cy));
      (p->s).coord.y = cy;
      if (q->mode[2] == 4) {
        if ((p->s).work[2] == 0) {
          break;
        }
        (p->s).work[2]--;
        if ((((p->s).work[2] / 3) & 1) != 0) {
          (p->s).coord.x = cx + -0x2100;
          (p->s).coord.y = cy + -0x200;
        }
        break;
      }
      {
        s32 w = (p->s).work[2] - 1;
        (p->s).work[2] = w;
        if ((u8)w != 0) {
          break;
        }
      }
      (p->s).mode[1]++;
      break;
    }
    case 4: {
      u32 one;
      InitRotatableMotion(&p->s);
      SetMotion(&p->s, MOTION(SM009_OMEGA_HAND, 1));
      *((u8*)p + 0x24) = 0x58;
      one = 1;
      (p->s).flags |= 0x10;
      *((u8*)p + 0x4c) = one;
      {
        register u8* oa asm("r3");
        register s32 k asm("r2");
        oa = (u8*)p + 0x4a;
        k = 0x10;
        {
          s32 ov = *oa;
          s32 m11 = -0x11;
          m11 &= ov;
          m11 |= k;
          *oa = m11;
        }
      }
      {
        u8* g = (u8*)p + 0x49;
        s32 ov = *g;
        s32 m13 = -0xD;
        m13 &= ov;
        m13 |= 8;
        *g = m13;
      }
      *((u8*)p + 0x25) = 0x1D;
      (p->s).work[2] = 0xC;
      (p->s).mode[1]++;
      FALLTHROUGH;
    }
    case 5: {
      s32 cx, cy;
      UpdateEntityAnim(&p->s);
      cx = q->coord.x;
      (p->s).coord.x = cx + -0x700;
      cy = q->coord.y + -0x5A00;
      asm("" : "+r"(cy));
      (p->s).coord.y = cy;
      if ((p->s).work[2] != 0) {
        (p->s).work[2]--;
        if ((((p->s).work[2] / 3) & 1) != 0) {
          (p->s).coord.x = cx + -0x500;
          (p->s).coord.y = cy + -0x200;
        }
      }
      if (q->mode[2] == 2) {
        (p->s).mode[1]++;
      }
      break;
    }
    case 8: {
      u32 z3;
      InitRotatableMotion(&p->s);
      SetMotion(&p->s, MOTION(SM009_OMEGA_HAND, 0));
      *((u8*)p + 0x24) = 0x20;
      z3 = 0;
      (p->s).flags &= 0xEF;
      *((u8*)p + 0x4c) = z3;
      {
        u8* oa = (u8*)p + 0x4a;
        s32 ov = *oa;
        s32 m11 = -0x11;
        m11 &= ov;
        *oa = m11;
        oa -= 1;
        *oa |= 0xC;
      }
      (p->s).work[2] = z3;
      (p->s).mode[1]++;
      FALLTHROUGH;
    }
    case 9: {
      s32 cx, cy;
      UpdateEntityAnim(&p->s);
      cx = q->coord.x;
      (p->s).coord.x = cx + -0x1B00;
      cy = q->coord.y + -0x4400;
      asm("" : "+r"(cy));
      (p->s).coord.y = cy;
      (p->s).work[2]++;
      if ((((p->s).work[2] / 3) & 1) != 0) {
        (p->s).coord.x = cx + -0x1A00;
        (p->s).coord.y = cy + -0x100;
      }
      if (q->mode[2] == 3) {
        (p->s).mode[1]++;
      }
      break;
    }
    case 10:
      InitNonAffineMotion(&p->s);
      SetMotion(&p->s, MOTION(SM009_OMEGA_HAND, 0));
      UpdateEntityAnim(&p->s);
      (p->s).mode[1] = 0;
      break;
  }
}

INCASM("asm/solid/actor_f.inc");

// ------------------------------------------------------------------------------------------------------------------------------------

const struct Collision Collision_08370ab8 = {
  kind : DDP,
  faction : FACTION_ALLY,
  damage : 1,
  remaining : 0,
  layer : 0x00000001,
  range : {PIXEL(0), PIXEL(8), PIXEL(32), PIXEL(16)},
};

const struct Collision Collision_08370ad0 = {
  kind : DRP,
  faction : FACTION_ENEMY,
  LAYER(0xFFFFFFFF),
  hitzone : 1,
  remaining : 1,
  range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
};

// 0x08370ae8
static const struct SlashedEnemy sProloguePantheons[4] = {
    {
      m : MOTION(SM019_PANTHEON_HUNTER, 6),
      unk_02 : {0xFF, 0x11},
      c : {PIXEL(0), PIXEL(0)},
      d : {PIXEL(1) / 2, -PIXEL(5)},
      unk_coord_0c : {0x00FF, 0x01FF},
      unk_10 : {0x0000, 0x0040},
      unk_14 : {512, 512},
    },
    {
      m : MOTION(SM019_PANTHEON_HUNTER, 7),
      unk_02 : {0xFE, 0x11},
      c : {PIXEL(0), PIXEL(0)},
      d : {PIXEL(1) / 2, -PIXEL(2)},
      unk_coord_0c : {0x007F, 0x007F},
      unk_10 : {0x0000, 0x0040},
      unk_14 : {512, 512},
    },
    {
      m : MOTION(SM019_PANTHEON_HUNTER, 8),
      unk_02 : {0xFE, 0x11},
      c : {PIXEL(0), PIXEL(0)},
      d : {PIXEL(1), -PIXEL(3)},
      unk_coord_0c : {0x01FF, 0x01FF},
      unk_10 : {0x0000, 0x0040},
      unk_14 : {512, 512},
    },
    {
      m : MOTION(SM019_PANTHEON_HUNTER, 5),
      unk_02 : {0xFF, 0x04},
      c : {PIXEL(0), PIXEL(0)},
      d : {PIXEL(0), PIXEL(0)},
      unk_coord_0c : {PIXEL(0), PIXEL(0)},
      unk_10 : {0x0000, 0x0040},
      unk_14 : {2048, 512},
    },
};

// 0x08370B58
static const struct Collision sCollisions_08370B58[11] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ALLY,
      damage : 1,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(32)},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ALLY,
      damage : 1,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(120)},
    },
    [3] = {
      kind : DDP,
      faction : FACTION_ALLY,
      damage : 1,
      comboLv : 1,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(120)},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ALLY,
      damage : 1,
      comboLv : 2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(120)},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ALLY,
      damage : 1,
      comboLv : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(120)},
    },
    [6] = {
      kind : DDP,
      faction : FACTION_ALLY,
      damage : 1,
      comboLv : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(120)},
    },
    [7] = {
      kind : DDP,
      faction : FACTION_ALLY,
      damage : 1,
      comboLv : 5,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(120)},
    },
    [8] = {
      kind : DDP,
      faction : FACTION_ALLY,
      damage : 1,
      comboLv : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(120)},
    },
    [9] = {
      kind : DDP,
      faction : FACTION_ALLY,
      damage : 1,
      comboLv : 7,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(120)},
    },
    [10] = {
      kind : DDP,
      faction : FACTION_ALLY,
      damage : 1,
      comboLv : 8,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(120)},
    },
};

// 0x08370c60
const struct Rect Rect_08370c60 = {PIXEL(8), PIXEL(8), PIXEL(16), PIXEL(16)};

// 0x08370C68
static const struct Collision sCollisions_08370C68[16] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 1,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), -PIXEL(128), PIXEL(120)},
    },
    [2] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : HALFABLE,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(14), PIXEL(16), PIXEL(28)},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 1,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(24), -PIXEL(16), PIXEL(16), PIXEL(16)},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 1,
      comboLv : 1,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(24), -PIXEL(16), PIXEL(16), PIXEL(16)},
    },
    [6] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 1,
      comboLv : 2,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(24), -PIXEL(16), PIXEL(16), PIXEL(16)},
    },
    [7] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
    },
    [8] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 1,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    [9] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 1,
      comboLv : 1,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    [10] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 1,
      comboLv : 2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    [11] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 1,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(24), -PIXEL(16), PIXEL(16), PIXEL(16)},
    },
    [12] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 1,
      comboLv : 1,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(24), -PIXEL(16), PIXEL(16), PIXEL(16)},
    },
    [13] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 1,
      comboLv : 2,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(24), -PIXEL(16), PIXEL(16), PIXEL(16)},
    },
    [14] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
    },
    [15] = {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
    },
};

const s32 s32_ARRAY_08370de8[8] = {56, 32, 48, 64, 56, 48, 72, 48};

const Coords32 Coord_08370e08 = {PIXEL(0), -PIXEL(24)};

const struct Rect Rect_08370e10 = {0x0, 0x0, 0x1000, 0x2800};
