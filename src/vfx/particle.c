#include "entity.h"
#include "global.h"
#include "overworld.h"
#include "vfx.h"

/*
work[0]:
  00: ゼロがダッシュした時に出る土埃(2種類あってでかい土埃)
  06: バスターが弾かれた時のエフェクト(弾の種類は関係ない)
  07: ゼロが壁ジャンプした時の土埃
  10:
*/

static void Ghost5_Init(struct VFX* p);
static void Ghost5_Update(struct VFX* p);
static void Ghost5_Die(struct VFX* p);

// clang-format off
const VFXRoutine gParticleRoutine = {
    [ENTITY_INIT] =      Ghost5_Init,
    [ENTITY_UPDATE] =    Ghost5_Update,
    [ENTITY_DIE] =       Ghost5_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

NON_MATCH void CreateParticle(struct Coord* c, u8 kind, bool8 isRight) {
#if MODERN
  struct VFX* p = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 1;
    INIT_VFX_ROUTINE(p, VFX_PARTICLE);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).work[0] = kind;
    (p->s).work[1] = 0;
    (p->s).coord = *c;
    if (isRight) {
      (p->s).flags |= X_FLIP;
    } else {
      (p->s).flags &= ~X_FLIP;
    }
    (p->s).spr.oam.xflip = (p->s).spr.xflip = isRight;
  }
#else
  INCCODE("asm/wip/CreateParticle.inc");
#endif
}

void oz_080b3820(struct Coord* omegaCoord, bool8 isRight) {
  struct Coord c;
  if (isRight) {
    c.x = omegaCoord->x + PIXEL(34);
  } else {
    c.x = omegaCoord->x - PIXEL(34);
  }
  c.y = omegaCoord->y;
  CreateParticle(&c, 3, 0);
  CreateParticle(&c, 3, 1);
  CreateParticle(&c, 4, isRight);
  CreateParticle(&c, 4, isRight);
  CreateParticle(&c, 5, isRight);
  CreateParticle(&c, 5, isRight);
}

void FUN_080b388c(struct Coord* zc, bool8 isRight) {
  struct Coord c;
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

void CreateDashDust(struct Coord* c, bool8 isRight) {
  if (c->y > SEA) {
    CreateParticle(c, 9, isRight);
  } else {
    CreateParticle(c, 1, isRight);
  }
}

// 壁ずりの土煙
void CreateWallDust(struct Coord* c, bool8 isRight) {
  if (c->y > SEA) {
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
void initWallDust(struct VFX* p);
void FUN_080b3e08(struct VFX* p);
void FUN_080b3e4c(struct VFX* p);
void FUN_080b3ee0(struct VFX* p);

static void Ghost5_Init(struct VFX* p) {
  // clang-format off
  static VFXFunc const sInitializers[] = {
      initDashDust,
      FUN_080b39dc,
      FUN_080b3a3c,
      FUN_080b3b20,
      FUN_080b3b8c,
      FUN_080b3c40,
      initRicochet,
      initWallDust,
      FUN_080b3e08,
      FUN_080b3e4c,
      FUN_080b3ee0,
  };
  // clang-format on

  (sInitializers[(p->s).work[0]])(p);
}

// --------------------------------------------

void updateDashDust(struct VFX* p);
void FUN_080b3fe8(struct VFX* p);
void FUN_080b403c(struct VFX* p);
void FUN_080b4090(struct VFX* p);
void FUN_080b4198(struct VFX* p);
void FUN_080b4104(struct VFX* p);

static void Ghost5_Update(struct VFX* p) {
  // clang-format off
  static VFXFunc const sUpdates[] = {
      updateDashDust,
      FUN_080b3fe8,
      FUN_080b403c,
      updateDashDust,
      FUN_080b4090,
      FUN_080b4090,
      updateDashDust,
      FUN_080b4198,
      updateDashDust,
      FUN_080b4104,
      FUN_080b4104,
  };
  // clang-format on

  (sUpdates[(p->s).work[0]])(p);
}

// --------------------------------------------

static void Ghost5_Die(struct VFX* p) {
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void initDashDust(struct VFX* p) {
  InitScalerotMotion1(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetMotion(&p->s, MOTION(SM000_BATTLE_EFFECT, 0x0B));
  (p->s).spr.mag.x = 0x200;
  (p->s).spr.mag.y = 0x200;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Ghost5_Update(p);
}

static void FUN_080b39dc(struct VFX* p) {
  InitNonAffineMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetMotion(&p->s, MOTION(SM000_BATTLE_EFFECT, 0x11));
  if ((p->s).flags & X_FLIP) {
    (p->s).coord.x -= PIXEL(20);
  } else {
    (p->s).coord.x += PIXEL(20);
  }
  (p->s).work[2] = 0;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Ghost5_Update(p);
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

  RNG_0202f388 = LCG(RNG_0202f388);
  (p->s).coord.x += PIXEL(((RNG_0202f388 >> 16) & 4) - 2);
  InitNonAffineMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetMotion(&p->s, MOTION(SM000_BATTLE_EFFECT, 0x11));
  (p->s).work[2] = 0;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Ghost5_Update(p);
}

static void FUN_080b3b20(struct VFX* p) {
  InitScalerotMotion1(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetMotion(&p->s, MOTION(SM000_BATTLE_EFFECT, 0x0B));
  (p->s).spr.mag.x = 0x110;
  (p->s).spr.mag.y = 0x110;
  if ((p->s).flags & X_FLIP) {
    (p->s).coord.x -= PIXEL(7);
  } else {
    (p->s).coord.x += PIXEL(7);
  }
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Ghost5_Update(p);
}

static void FUN_080b3b8c(struct VFX* p) {
  InitNonAffineMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetMotion(&p->s, MOTION(SM000_BATTLE_EFFECT, 0x0F));

  if ((p->s).flags & X_FLIP) {
    RNG_0202f388 = LCG(RNG_0202f388);
    (p->s).d.x = (RNG_0202f388 >> 16) & 0x1FF;
  } else {
    RNG_0202f388 = LCG(RNG_0202f388);
    (p->s).d.x = -((RNG_0202f388 >> 16) & 0x1FF);
  }

  RNG_0202f388 = LCG(RNG_0202f388);
  (p->s).d.y = (((RNG_0202f388 >> 16) & 0xF) + 0xD) * -0x40;

  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Ghost5_Update(p);
}

static void FUN_080b3c40(struct VFX* p) {
  InitNonAffineMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetMotion(&p->s, MOTION(SM000_BATTLE_EFFECT, 0x10));

  if ((p->s).flags & X_FLIP) {
    RNG_0202f388 = LCG(RNG_0202f388);
    (p->s).d.x = (RNG_0202f388 >> 16) & 0x1FF;
  } else {
    RNG_0202f388 = LCG(RNG_0202f388);
    (p->s).d.x = -((RNG_0202f388 >> 16) & 0x1FF);
  }

  RNG_0202f388 = LCG(RNG_0202f388);
  (p->s).d.y = (((RNG_0202f388 >> 16) & 0xF) + 0xA) * -0x40;

  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Ghost5_Update(p);
}

static void initRicochet(struct VFX* p) {
  InitNonAffineMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetMotion(&p->s, MOTION(SM000_BATTLE_EFFECT, 0x09));
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Ghost5_Update(p);
}

INCASM("asm/vfx/fx.inc");
