#include "entity.h"
#include "global.h"
#include "overworld.h"
#include "vfx.h"

// 土埃などの汎用エフェクト

/*
work[0]:
  00: ゼロがダッシュした時に出る土埃(大)
  01: ゼロがダッシュした時に出る土埃(小)
  02: 壁ずりの土煙
  03: チャージセイバーで発生する煙
  04: チャージセイバーで発生する石ころ大
  05: チャージセイバーで発生する石ころ小
  06: バスターが弾かれた時のエフェクト(弾の種類は関係ない)
  07: ゼロが壁ジャンプした時の土埃
  08: ???
  09: 01 の水中版
  10: 02 の水中版
*/

static void Ghost5_Init(struct Entity* p);
static void Ghost5_Update(struct Entity* p);
static void Ghost5_Die(struct Entity* p);

// clang-format off
const VFXRoutine gParticleRoutine = {
    [ENTITY_INIT] =      (VFXFunc)Ghost5_Init,
    [ENTITY_UPDATE] =    (VFXFunc)Ghost5_Update,
    [ENTITY_DIE] =       (VFXFunc)Ghost5_Die,
    [ENTITY_DISAPPEAR] = (VFXFunc)DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

void CreateParticle(Coords32* c, u8 kind, bool8 isRight) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_PARTICLE);
    p->work[0] = kind, p->work[1] = 0;
    p->coord = *c;
    SET_XFLIP(p, isRight);
  }
}

// 0x080b3820
// チャージセイバーで発生するエフェクトをまとめて生成
void oz_080b3820(Coords32* base, bool8 isRight) {
  Coords32 c;
  if (isRight) {
    c.x = base->x + PIXEL(34);
  } else {
    c.x = base->x - PIXEL(34);
  }
  c.y = base->y;
  CreateParticle(&c, 3, 0);        // 煙1
  CreateParticle(&c, 3, 1);        // 煙2
  CreateParticle(&c, 4, isRight);  // 石ころ大1
  CreateParticle(&c, 4, isRight);  // 石ころ大2
  CreateParticle(&c, 5, isRight);  // 石ころ小1
  CreateParticle(&c, 5, isRight);  // 石ころ小2
}

void FUN_080b388c(Coords32* zc, bool8 isRight) {
  Coords32 c;
  if (isRight) {
    c.x = zc->x + PIXEL(16);
  } else {
    c.x = zc->x - PIXEL(16);
  }
  c.y = zc->y + PIXEL(3);
  if (FUN_080098a4(c.x, c.y) != 0) {
    CreateParticle(&c, 7, isRight);
  }
}

void CreateDashDust(Coords32* c, bool8 isRight) {
  if (c->y > gOverworld.sea) {
    CreateParticle(c, 9, isRight);
  } else {
    CreateParticle(c, 1, isRight);
  }
}

// 壁ずりの土煙
void CreateWallDust(Coords32* c, bool8 isRight) {
  if (c->y > gOverworld.sea) {
    CreateParticle(c, 10, isRight);
  } else {
    CreateParticle(c, 2, isRight);
  }
}

// --------------------------------------------

static void initDashDust(struct VFX* p);
static void FUN_080b39dc(struct VFX* p);
static void FUN_080b3a3c(struct VFX* p);
static void FUN_080b3b20(struct VFX* p);
static void FUN_080b3b8c(struct VFX* p);
static void FUN_080b3c40(struct VFX* p);
static void initRicochet(struct VFX* p);
static void initWallDust(struct VFX* p);
static void FUN_080b3e08(struct VFX* p);
static void FUN_080b3e4c(struct VFX* p);
static void FUN_080b3ee0(struct Entity* p);

static void Ghost5_Init(struct Entity* p) {
  // clang-format off
  static VFXFunc const sInitializers[] = {
      [0]  = (VFXFunc)initDashDust,
      [1]  = (VFXFunc)FUN_080b39dc,
      [2]  = (VFXFunc)FUN_080b3a3c,
      [3]  = (VFXFunc)FUN_080b3b20,
      [4]  = (VFXFunc)FUN_080b3b8c,
      [5]  = (VFXFunc)FUN_080b3c40,
      [6]  = (VFXFunc)initRicochet,
      [7]  = (VFXFunc)initWallDust,
      [8]  = (VFXFunc)FUN_080b3e08,
      [9]  = (VFXFunc)FUN_080b3e4c,
      [10] = (VFXFunc)FUN_080b3ee0,
  };
  // clang-format on

  (sInitializers[p->work[0]])((void*)p);
}

// --------------------------------------------

static void StepAnimation(struct Entity* p);
static void FUN_080b3fe8(struct Entity* p);
static void FUN_080b403c(struct Entity* p);
static void FUN_080b4090(struct Entity* p);
static void FUN_080b4198(struct Entity* p);
static void FUN_080b4104(struct Entity* p);

static void Ghost5_Update(struct Entity* p) {
  // clang-format off
  static VFXFunc const sUpdates[] = {
      [0]  = (VFXFunc)StepAnimation,
      [1]  = (VFXFunc)FUN_080b3fe8,
      [2]  = (VFXFunc)FUN_080b403c,
      [3]  = (VFXFunc)StepAnimation,
      [4]  = (VFXFunc)FUN_080b4090,
      [5]  = (VFXFunc)FUN_080b4090,
      [6]  = (VFXFunc)StepAnimation,
      [7]  = (VFXFunc)FUN_080b4198,
      [8]  = (VFXFunc)StepAnimation,
      [9]  = (VFXFunc)FUN_080b4104,
      [10] = (VFXFunc)FUN_080b4104,
  };
  // clang-format on

  (sUpdates[p->work[0]])((void*)p);
}

// --------------------------------------------

static void Ghost5_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void initDashDust(struct VFX* p) {
  EnableSpriteAnimation_Affine(p);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM000_BATTLE_EFFECT, 11));
  (p->s).spr.mag.x = 0x200;
  (p->s).spr.mag.y = 0x200;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Ghost5_Update((void*)p);
}

static void FUN_080b39dc(struct VFX* p) {
  EnableSpriteAnimation_Normal(p);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM000_BATTLE_EFFECT, 17));
  if ((p->s).flags & X_FLIP) {
    (p->s).coord.x -= PIXEL(20);
  } else {
    (p->s).coord.x += PIXEL(20);
  }
  (p->s).work[2] = 0;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Ghost5_Update((void*)p);
}

static void FUN_080b3a3c(struct VFX* p) {
  metatile_attr_t attr;
  if ((p->s).flags & X_FLIP) {
    (p->s).coord.x += PIXEL(15);
  } else {
    (p->s).coord.x -= PIXEL(15);
  }

  attr = FUN_080098a4((p->s).coord.x, (p->s).coord.y);
  if ((attr & 0xF) == 0) {
    (p->s).coord.y -= PIXEL(18);
    attr = FUN_080098a4((p->s).coord.x, (p->s).coord.y);
    if ((attr & 0xF) == 0) {
      (p->s).flags &= ~DISPLAY;
      (p->s).flags &= ~FLIPABLE;
      SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
      return;
    }
  }

  (p->s).coord.x += PIXEL((RANDOM(RNG_0202f388) & 4) - 2);
  EnableSpriteAnimation_Normal(p);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM000_BATTLE_EFFECT, 17));
  (p->s).work[2] = 0;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Ghost5_Update((void*)p);
}

static void FUN_080b3b20(struct VFX* p) {
  EnableSpriteAnimation_Affine(p);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM000_BATTLE_EFFECT, 11));
  (p->s).spr.mag.x = 0x110;
  (p->s).spr.mag.y = 0x110;
  if ((p->s).flags & X_FLIP) {
    (p->s).coord.x -= PIXEL(7);
  } else {
    (p->s).coord.x += PIXEL(7);
  }
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Ghost5_Update((void*)p);
}

static void FUN_080b3b8c(struct VFX* p) {
  EnableSpriteAnimation_Normal(p);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM000_BATTLE_EFFECT, 15));

  if ((p->s).flags & X_FLIP) {
    (p->s).d.x = RANDOM(RNG_0202f388) & 0x1FF;
  } else {
    (p->s).d.x = -(RANDOM(RNG_0202f388) & 0x1FF);
  }
  (p->s).d.y = ((RANDOM(RNG_0202f388) & 0xF) + 0xD) * -0x40;

  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Ghost5_Update((void*)p);
}

static void FUN_080b3c40(struct VFX* p) {
  EnableSpriteAnimation_Normal(p);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM000_BATTLE_EFFECT, 16));

  if ((p->s).flags & X_FLIP) {
    (p->s).d.x = RANDOM(RNG_0202f388) & 0x1FF;
  } else {
    (p->s).d.x = -(RANDOM(RNG_0202f388) & 0x1FF);
  }
  (p->s).d.y = ((RANDOM(RNG_0202f388) & 0xF) + 0xA) * -0x40;

  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Ghost5_Update((void*)p);
}

static void initRicochet(struct VFX* p) {
  EnableSpriteAnimation_Normal(p);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM000_BATTLE_EFFECT, 9));
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Ghost5_Update((void*)p);
}

static void initWallDust(struct VFX* p) {
  EnableSpriteAnimation_Normal(p);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;

  RANDOM(RNG_0202f388);
  SetSpriteAnimation(p, MOTION(SM000_BATTLE_EFFECT, 27));
  RANDOM(RNG_0202f388);

  SET_YFLIP(p, FALSE);
  {
    (p->s).coord.x += PIXEL((RANDOM(RNG_0202f388) & 3) - 2);
    (p->s).coord.y += PIXEL((RANDOM(RNG_0202f388) & 7) - 4);
  }
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Ghost5_Update((void*)p);
}

static void FUN_080b3e08(struct VFX* p) {
  EnableSpriteAnimation_Normal(p);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM000_BATTLE_EFFECT, 5));
  (p->s).work[2] = 4;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Ghost5_Update((void*)p);
}

static void FUN_080b3e4c(struct VFX* p) {
  EnableSpriteAnimation_Normal(p);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM000_BATTLE_EFFECT, 13));

  (p->s).work[2] = 60 + (RANDOM(RNG_0202f388) & 7);
  (p->s).coord.x += PIXEL((RANDOM(RNG_0202f388) & 3) - 2);
  (p->s).d.y = ((PIXEL(1) * 3) / 4) + (RANDOM(RNG_0202f388) & 0x3F);

  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Ghost5_Update((void*)p);
}

static void FUN_080b3ee0(struct Entity* p) {
  metatile_attr_t attr;

  if (p->flags & X_FLIP) {
    (p->coord).x += PIXEL(15);
  } else {
    (p->coord).x -= PIXEL(15);
  }

  attr = FUN_080098a4((p->coord).x, (p->coord).y);
  if ((attr & 0xF) == 0) {
    (p->coord).y -= PIXEL(18);
    attr = FUN_080098a4((p->coord).x, (p->coord).y);
    if ((attr & 0xF) == 0) {
      p->flags &= ~DISPLAY;
      p->flags &= ~FLIPABLE;
      SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
      return;
    }
  }

  p->work[2] = 60 + (RANDOM(RNG_0202f388) & 7);
  (p->coord).x += PIXEL((RANDOM(RNG_0202f388) & 3) - 2);
  (p->d).y = ((PIXEL(1) * 3) / 4) + (RANDOM(RNG_0202f388) & 0x3F);

  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM000_BATTLE_EFFECT, 13));
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Ghost5_Update((void*)p);
}

// --------------------------------------------

// 0x080b3fe8
static void FUN_080b3fe8(struct Entity* p) {
  UpdateSpriteAnimation(p);
  if ((p->work[2]++) & 1) {
    p->flags &= ~DISPLAY;
  } else {
    p->flags |= DISPLAY;
  }
  (p->coord).y -= (PIXEL(1) * 3) / 4;
  if (IsSpriteAnimEnd(p)) SET_VFX_ROUTINE(p, ENTITY_DIE);
}

// 0x080b403c
static void FUN_080b403c(struct Entity* p) {
  UpdateSpriteAnimation(p);
  if ((p->work[2]++) & 1) {
    p->flags &= ~DISPLAY;
  } else {
    p->flags |= DISPLAY;
  }
  (p->coord).y -= (PIXEL(1) * 3) / 4;
  if (IsSpriteAnimEnd(p)) SET_VFX_ROUTINE(p, ENTITY_DIE);
}

// 0x080b4090
static void FUN_080b4090(struct Entity* p) {
  UpdateSpriteAnimation(p);
  (p->coord).x += (p->d).x;
  (p->coord).y += (p->d).y;
  (p->d).y += PIXEL(1) / 4;
  if (FUN_080098a4((p->coord).x, (p->coord).y)) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
  }
}

// 0x080b40d4
static void StepAnimation(struct Entity* p) {
  UpdateSpriteAnimation(p);
  if (IsSpriteAnimEnd(p)) SET_VFX_ROUTINE(p, ENTITY_DIE);
}

static void FUN_080b4104(struct Entity* p) {
  u32 idx;
  s32 y;
  UpdateSpriteAnimation(p);
  if (p->work[2] < 30) {
    if (p->work[2] & 1) {
      p->flags &= ~DISPLAY;
    } else {
      p->flags |= DISPLAY;
    }
  }

  (p->coord).x += COS((idx = p->work[2]) * 16) >> 2;
  (p->coord).y -= (p->d).y;

  y = (p->coord).y - PIXEL(8);

  p->work[2] = idx - 1;

  if ((p->work[2] == 0xFF) || (gOverworld.sea > y)) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
  }
}

static void FUN_080b4198(struct Entity* p) {
  UpdateSpriteAnimation(p);
  if ((--p->work[2]) == 0xFF) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
  }
}
