#include "global.h"
#include "motion.h"
#include "overworld.h"
#include "sound.h"
#include "vfx.h"
#include "weapon.h"
#include "zero.h"

enum ZeroAirKind {
  NORMAL_JUMP,
  DOUBLE_JUMP,
  WALL_JUMP,
  ROD_JUMP,
  SPLIT_HEAVENS_JUMP,
};

s16 getZeroJumpingPower(struct Zero* z);
s16 getZeroRisingDy(struct Zero* z);
void CreateDashDust(struct Coord* c, bool8 isRight);
void FUN_080b388c(struct Coord* zc, bool8 isRight);

s16 FUN_08032bac(struct Zero* z);
s16 GetRodJumpPower(struct Zero* z);
s16 FUN_08032c04(struct Zero* z);
s16 FUN_08032c30(struct Zero* z);
s16 GetSplitHeavenSpeed(struct Zero* z);

// ------------------------------------------------------------------------------------------------------------------------------------

static void zeroIdle_0802a30c(struct Zero* z);
static void zeroStartWalk(struct Zero* z);
static void zeroDash_0802a688(struct Zero* z);

/*
  - ヘッドチップ、オートリカバリーの回復処理
  - 他にも処理あり
*/
void zeroNeutral2(struct Zero* z) {
  static ZeroFunc const gZeroMode0Actions2[] = {
      zeroIdle_0802a30c,  // idle
      zeroStartWalk,      // walk
      zeroDash_0802a688,  // dash
  };

  u8* n;
  metatile_attr_t attr;
  s16 hp;
  u8 maxHP;
  u8 prevMode;
  struct Zero_b4* b4;

  if (((((z->s).mode[2] == 0) && (b4 = &(z->unk_b4), prevMode = b4->prevMode, prevMode == 0)) && (hp = (z->body).hp, hp < GetMaxHP(z))) && (b4->status.head == AUTO_RECOVER)) {
    u8 attackMode = (z->unk_b4).attackMode[0];
    u8* idleFrame = &z->idleFrame;
    if (attackMode == 3) {
      *idleFrame = 0;
    }

    if ((z->last & INPUT_DISABLED) == 0) {
      *idleFrame += 1;
    }

    if ((*(u16*)&(b4->status.body) == 0x502)) {
      if (*idleFrame <= 96) {
        goto NO_RECOVER;
      }
    } else if (*idleFrame <= 192) {
      goto NO_RECOVER;
    }

    gLifeRecoverAmount += 4;
    *idleFrame = prevMode;
  } else {
    z->idleFrame = 0;
  }

NO_RECOVER:
  (z->s).d.y = 0;
  z->airJumpped = FALSE;
  z->isGround = TRUE;
  (gZeroMode0Actions2[(z->s).mode[2]])(z);

  if ((((gOverworld.unk_1c8.id & 0x7F) == STAGE_TWILIGHT_DESERT) && (hp = FUN_080101a8(), hp != 0)) || (z->unk_234 != 0)) {
    zero_08026f90(z, gZeroRanges);
  }

  (z->s).coord.x += (z->s).d.x;
  n = &z->posture;

  PushoutWallX(z, &gZeroRanges[*n], 0);
  PushoutWallX(z, &gZeroRanges[*n], 1);
  PushoutByFloor1(z, &gZeroRanges[*n], 0);

  attr = PushoutByFloor2(z, &gZeroRanges[*n], FALSE);
  if (attr == 0) {
    if ((z->s).mode[2] == 1) {
      s16 tmp;
      s32 dx;
      if ((z->s).flags & X_FLIP) {
        tmp = CalcDx(z);
        dx = tmp;
      } else {
        tmp = CalcDx(z);
        dx = -tmp;
      }
      (z->s).d.x = dx;
    }
    (z->s).mode[1] = ZERO_AIR;
    (z->s).mode[2] = 2;
    (z->s).mode[3] = 0;
  }
}

// --------------------------------------------

static void zeroIdleStep0(struct Zero* z);
static void zeroIdleStep1(struct Zero* z);

static void zeroIdle_0802a30c(struct Zero* z) {
  static ZeroFunc const gZeroIdleSeq[] = {
      zeroIdleStep0,
      zeroIdleStep1,
  };
  (gZeroIdleSeq[(z->s).mode[3]])(z);
}

static void zeroIdleStep0(struct Zero* z) {
  struct Zero_b4* b4;
  if ((z->prevPosture == DASH) || (z->prevPosture == (DASH | SHADOW))) {
    SetMotion(&z->s, MOTION(DM003_ZERO_DASH, 0x01));
  } else {
    SetMotion(&z->s, GetDefaultMotion(z));
  }

  b4 = &(z->unk_b4);
  if (b4->shadow != NULL) {
    b4->shadow->work[1] = 1;
    b4->shadow = NULL;
  }

  (z->s).mode[3] = 1;
  zeroIdleStep1(z);
}

/*
  - 体力を見て瀕死モーションにする or 解除する 処理
  - 滑る処理
*/
static void zeroIdleStep1(struct Zero* z) {
  bool8 sliped;
  bool8 isIdle = TRUE;
  motion_t m = MOTION_VALUE(z);
  if (m == MOTION(DM003_ZERO_DASH, 0x01)) {
    if ((z->s).motion.state == MOTION_END) {
      m = GetDefaultMotion(z);
      SetMotion(&z->s, m);
    } else {
      isIdle = FALSE;
    }
  }

  if (isIdle) {
    bool8* dying = &(z->unk_b4.status).dying;
    if (*dying) {
      if ((z->body).hp > 7) {
        motion_t m;
        *dying = FALSE;
        m = GetDefaultMotion(z);
        SetMotion(&z->s, m);
      }
    } else {
      if ((z->body).hp < 3) {
        motion_t m;
        *dying = TRUE;
        m = GetDefaultMotion(z);
        SetMotion(&z->s, m);
      }
    }
  }

  sliped = z->slip;
  if (sliped) {
    s32 dx = (z->s).d.x;
    if (dx >= 1) {
      (z->s).d.x = dx - 16;
      if ((z->s).d.x > -1) {
        return;
      }
    } else {
      if (dx > -1) {
        return;
      }
      (z->s).d.x = dx + 16;
      if ((z->s).d.x < 1) {
        return;
      }
    }
    sliped = FALSE;
  }
  (z->s).d.x = sliped;
}

// --------------------------------------------

static void zeroStartWalk0(struct Zero* z);
static void zeroStartWalk1(struct Zero* z);
static void zeroStartWalk2(struct Zero* z);

static void zeroStartWalk(struct Zero* z) {
  static ZeroFunc const gZeroWalkSeq[] = {
      zeroStartWalk0,
      zeroStartWalk1,
      zeroStartWalk2,
  };
  (gZeroWalkSeq[(z->s).mode[3]])(z);
}

static void zeroStartWalk0(struct Zero* z) {
  struct Zero_b4* b4 = &(z->unk_b4);
  if (b4->shadow != NULL) {
    b4->shadow->work[1] = 1;
    b4->shadow = NULL;
  }

  if ((z->s).d.x == 0) {
    SetMotion(&z->s, MOTION(DM002_ZERO_RUN, 0x00));
    (z->s).mode[3] = 1;
    zeroStartWalk1(z);
  } else {
    GotoMotion(&z->s, MOTION(DM002_ZERO_RUN, 0x00), 1, 4);
    (z->s).mode[3] = 2;
    zeroStartWalk2(z);
  }
}

static void zeroStartWalk1(struct Zero* z) {
  motion_t m = MOTION_VALUE(z);
  if ((m != MOTION(DM002_ZERO_RUN, 0x00)) || ((z->s).motion.duration < 2)) {
    (z->s).mode[3] = 2;
  }

  if (z->zeroInput & ZERO_INPUT_DPAD_LEFT) {
    (z->s).spr.xflip = FALSE;
    (z->s).spr.oam.xflip = FALSE;
    (z->s).flags &= ~X_FLIP;

    if (z->slip) {
      (z->s).d.x -= 0x20;
      if ((z->s).d.x >= -CalcMaxWalkSpeed(z)) {
        return;
      }
      (z->s).d.x = -CalcMaxWalkSpeed(z);
    } else {
      (z->s).d.x = -CalcMaxWalkSpeed(z);
    }

  } else if (z->zeroInput & ZERO_INPUT_DPAD_RIGHT) {
    (z->s).spr.xflip = TRUE;
    (z->s).spr.oam.xflip = TRUE;
    (z->s).flags |= X_FLIP;

    if (z->slip) {
      (z->s).d.x += 0x20;
      if ((z->s).d.x <= CalcMaxWalkSpeed(z)) {
        return;
      }
    }
    (z->s).d.x = CalcMaxWalkSpeed(z);
  }
}

static void zeroStartWalk2(struct Zero* z) {
  s8 cmdIdx;
  if (z->zeroInput & DPAD_LEFT) {
    (z->s).spr.xflip = FALSE;
    (z->s).spr.oam.xflip = FALSE;
    (z->s).flags &= ~X_FLIP;
    if (z->slip) {
      (z->s).d.x -= 0x20;
      if ((z->s).d.x < -CalcDx(z)) {
        (z->s).d.x = -CalcDx(z);
      }
    } else {
      (z->s).d.x = -CalcDx(z);
    }
  } else if (z->zeroInput & DPAD_RIGHT) {
    (z->s).spr.xflip = TRUE;
    (z->s).spr.oam.xflip = TRUE;
    (z->s).flags |= X_FLIP;
    if (z->slip) {
      (z->s).d.x += 0x20;
      if ((z->s).d.x > CalcDx(z)) {
        (z->s).d.x = CalcDx(z);
      }
    } else {
      (z->s).d.x = CalcDx(z);
    }
  }

  cmdIdx = (z->s).motion.cmdIdx;
  if (((cmdIdx == 3) || (cmdIdx == 8)) && ((z->s).motion.duration < 2)) {
    PlaySound(SE_WALK);
  }
}

// --------------------------------------------

static void zero_dash_step0(struct Zero* z);
static void zero_dash_step1(struct Zero* z);

static void zeroDash_0802a688(struct Zero* z) {
  static ZeroFunc const gZeroDashSeq[] = {
      zero_dash_step0,
      zero_dash_step1,
  };
  gZeroDashSeq[(z->s).mode[3]](z);
}

static void zero_dash_step0(struct Zero* z) {
  struct Zero_b4* b4 = &(z->unk_b4);
  if (z->zeroInput & ZERO_INPUT_PRESS_DASH) {
    u8 foot;

    b4->dashTimer = 28;
    z->dashDustTimer = 0;
    SetMotion(&z->s, MOTION(DM003_ZERO_DASH, 0x00));
    CreateParticle(&(z->s).coord, 0, ((z->s).flags >> 4) & 1);

    if (b4->shadow == NULL) {
      struct VFX* g = CreateAfterImages(&z->s);
      b4->shadow = &g->s;
    }

    if (((z->last & INPUT_DISABLED) == 0) && ((foot = (b4->status).foot, foot == FOOT_CHIP_SHADOW || (foot == FOOT_CHIP_ULTIMA)))) {
      const u8 color = GetZeroColor(z);
      LoadShadowDashPalette(z, color);
      z->posture = 3;
    }

    PlaySound(SE_DASH_1);
  }

  (z->s).mode[3] = 1;
  zero_dash_step1(z);
}

WIP static void zero_dash_step1(struct Zero* z) {
#if MODERN
  bool8 xflip;
  if (z->posture != 3) {
    z->posture = 1;
  }

  z->dashDustTimer++;
  if (z->dashDustTimer == 3) {
    z->dashDustTimer = 0;
    CreateDashDust(&(z->s).coord, ((z->s).flags >> 4) & 1);
  }

  if (z->restriction.move) {
    return;
  }

  if (z->zeroInput & DPAD_LEFT) {
    xflip = FALSE;
  } else if (z->zeroInput & DPAD_RIGHT) {
    xflip = TRUE;
  } else {
    xflip = ((z->s).flags >> 4) & 1;
  }
  (z->s).spr.oam.xflip = (z->s).spr.xflip = xflip;
  if (xflip) {
    (z->s).flags |= X_FLIP;
  } else {
    (z->s).flags &= ~X_FLIP;
  }

  if (z->slip) {
    if (xflip) {
      (z->s).d.x += 0x20;
      if ((z->s).d.x > GetDashSpeed(z)) {
        (z->s).d.x = GetDashSpeed(z);
      }
    } else {
      (z->s).d.x -= 0x20;
      if ((z->s).d.x < -GetDashSpeed(z)) {
        (z->s).d.x = -GetDashSpeed(z);
      }
    }
  } else {
    if (xflip) {
      (z->s).d.x = GetDashSpeed(z);
    } else {
      (z->s).d.x = -GetDashSpeed(z);
    }
  }

  // Check dash end
  (z->unk_b4).dashTimer--;
  if ((z->unk_b4).dashTimer == 0xFF) {
    if (z->zeroInput & (DPAD_RIGHT | DPAD_LEFT)) {
      (z->s).mode[2] = 1;
      (z->s).mode[3] = 0;
    } else {
      (z->s).mode[2] = 0;
      (z->s).mode[3] = 0;
    }
  }
#else
  INCCODE("asm/wip/zero_dash_step1.inc");
#endif
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void initZeroJump(struct Zero* z);
static void zeroJumpRise(struct Zero* z);
static void zeroJumpFall(struct Zero* z);

/*
  (z.s)->step(0x02037c6f)
    0: Normal jump
    1: Double jump
    2: Wall jump
    3: Recoil jump
    4: 龍炎刃
*/
void zeroAir2(struct Zero* z) {
  static ZeroFunc const gZeroJumpSeq[] = {
      initZeroJump,
      zeroJumpRise,
      zeroJumpFall,
  };
  gZeroJumpSeq[(z->s).mode[2]](z);
}

WIP static void initZeroJump(struct Zero* z) {
#if MODERN
  zero_input_t* key;
  struct Zero_b4* b4;
  s32 dx;

  switch ((z->s).mode[3]) {
    case NORMAL_JUMP: {
      SetMotion(&z->s, MOTION(DM004_ZERO_AIR, 0x03));
      (z->s).d.y = -getZeroJumpingPower(z);
      if (abs((z->s).d.x) < CalcDx(z)) {
        (z->s).d.x = CalcDx(z);
      }
      (z->unk_b4).dashable = 4;
      break;
    }

    case DOUBLE_JUMP: {
      SetMotion(&z->s, MOTION(DM004_ZERO_AIR, 0x00));
      (z->s).d.y = -getZeroRisingDy(z);
      b4 = &z->unk_b4;
      if (b4->blownSpeed != 0) {
        b4->blownSpeed = 0;
        (z->s).d.x = CalcDx(z);
      }
      if (abs((z->s).d.x) < CalcDx(z)) {
        (z->s).d.x = CalcDx(z);
      }
      break;
    }

    case WALL_JUMP: {
      FUN_080b388c(&(z->s).coord, ((z->s).flags >> 4) & 1);
      key = &z->zeroInput;
      if (*key & ZERO_INPUT_DASH) {
        SetMotion(&z->s, MOTION(DM006_ZERO_WALL_AIR, 0x01));
        if ((z->s).flags & X_FLIP) {
          if (*key & DPAD_RIGHT) {
            (z->s).coord.x += PIXEL(16);
            (z->s).coord.x += (PushoutToLeft2((z->s).coord.x, (z->s).coord.y) - PIXEL(7));
          }
          (z->s).spr.xflip = FALSE;
          (z->s).spr.oam.xflip = FALSE;
          (z->s).flags &= ~X_FLIP;
          dx = -GetDashSpeed(z);
        } else {
          if (*key & DPAD_LEFT) {
            (z->s).coord.x -= PIXEL(16);
            (z->s).coord.x += (PushoutToRight2((z->s).coord.x, (z->s).coord.y) + PIXEL(7));
          }
          (z->s).spr.xflip = TRUE;
          (z->s).spr.oam.xflip = TRUE;
          (z->s).flags |= X_FLIP;
          dx = GetDashSpeed(z);
        }
        (z->s).d.x = dx;
        b4 = &z->unk_b4;
        if (b4->shadow == NULL) {
          b4->shadow = (struct Entity*)CreateAfterImages(&z->s);
        }
      } else {
        SetMotion(&z->s, MOTION(DM005_ZERO_WALL, 0x01));
        if ((z->s).flags & X_FLIP) {
          dx = -CalcDx(z);
        } else {
          dx = CalcDx(z);
        }
        (z->s).d.x = dx;
      }
      b4 = &z->unk_b4;
      (z->unk_b4).unk_111 = 7;
      (z->s).d.y = -FUN_08032bac(z);
      b4->blownSpeed = 0;
      PlaySound(SE_WALLJUMP);
      break;
    }

    case ROD_JUMP: {
      (z->s).d.y = -GetRodJumpPower(z);
      b4 = &z->unk_b4;
      (z->s).d.x = z->recoilJumpDx;
      if (abs((z->s).d.x) < CalcDx(z)) {
        (z->s).d.x = CalcDx(z);
      }
      if ((abs((z->s).d.x) >= GetDashSpeed(z)) && (b4->shadow == NULL)) {
        b4->shadow = (struct Entity*)CreateAfterImages(&z->s);
      }
      (z->unk_b4).dashable = 4;
      break;
    }

    case SPLIT_HEAVENS_JUMP: {
      b4 = &z->unk_b4;
      z->splitHeavensWait = 0;
      if ((b4->status).element == ELEMENT_FLAME) {
        (z->s).d.y = -FUN_08032c30(z);
      } else {
        (z->s).d.y = -FUN_08032c04(z);
      }
      if ((z->s).flags & X_FLIP) {
        (z->s).d.x = GetSplitHeavenSpeed(z);
      } else {
        (z->s).d.x = -GetSplitHeavenSpeed(z);
      }
      break;
    }
  }
  (z->s).mode[2] = 1;
  zeroJumpRise(z);
#else
  INCCODE("asm/wip/initZeroJump.inc");
#endif
}

// --------------------------------------------

static void zeroNormalJumpRise(struct Zero* z);
static void zeroDoubleJumpRise(struct Zero* z);
static void zeroWallJumpRise(struct Zero* z);
static void zeroRecoilJumpRise(struct Zero* z);
static void zeroRyuenjinJumpRise(struct Zero* z);

static void zeroJumpRise(struct Zero* z) {
  // clang-format off
  static ZeroFunc const gZeroJumpRise[] = {
      [NORMAL_JUMP]        = zeroNormalJumpRise,
      [DOUBLE_JUMP]        = zeroDoubleJumpRise,
      [WALL_JUMP]          = zeroWallJumpRise,
      [ROD_JUMP]           = zeroRecoilJumpRise,
      [SPLIT_HEAVENS_JUMP] = zeroRyuenjinJumpRise,
  };
  // clang-format on

  if ((((gOverworld.unk_1c8.id & 0x7F) == STAGE_TWILIGHT_DESERT) && (FUN_080101a8() > 0)) || (z->unk_234 != 0)) {
    zero_08026f90(z, gZeroRanges);
  }
  gZeroJumpRise[(z->s).mode[3]](z);
}

NON_MATCH static void zeroNormalJumpRise(struct Zero* z) {
#if MODERN
  bool8* dashable;
  metatile_attr_t attr;
  motion_t m = MOTION_VALUE(z);
  if ((m != MOTION(DM004_ZERO_AIR, 0x03)) && ((z->s).motion.state == MOTION_END)) {
    GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 0x03), 1, 4);
  }

  dashable = &(z->unk_b4).dashable;
  if (*dashable > 0) {
    (*dashable)--;
    if (z->zeroInput & ZERO_INPUT_PRESS_DASH) {
      PlaySound(SE_DASH_1);
      *dashable = 0;
      (z->s).d.x = GetDashSpeed(z);
      if ((&z->unk_b4)->shadow == NULL) {
        (&z->unk_b4)->shadow = (struct Entity*)CreateAfterImages(&z->s);
      }
    }
  }

  if ((&z->unk_b4)->blownSpeed != 0) {
    (z->s).coord.x += (&z->unk_b4)->blownSpeed;
  } else {
    if (z->zeroInput & DPAD_RIGHT) {
      (z->s).coord.x += abs((z->s).d.x);
      (z->s).spr.xflip = TRUE;
      (z->s).spr.oam.xflip = TRUE;
      (z->s).flags |= X_FLIP;
    } else if (z->zeroInput & DPAD_LEFT) {
      (z->s).coord.x -= abs((z->s).d.x);
      (z->s).spr.xflip = FALSE;
      (z->s).spr.oam.xflip = FALSE;
      (z->s).flags &= ~X_FLIP;
    }
  }

  attr = PushoutWallX(z, &gZeroRanges[z->posture], FALSE);
  if (attr != 0) {
    (&z->unk_b4)->blownSpeed = 0;
  }
  attr = PushoutWallX(z, &gZeroRanges[z->posture], TRUE);
  if (attr != 0) {
    (&z->unk_b4)->blownSpeed = 0;
  }

  (z->s).coord.y += (z->s).d.y;
  (z->s).d.y += getFallAcceleration(z);

  attr = PushoutByCeiling(z, &gZeroRanges[z->posture], FALSE);
  if (attr == 0) {
    attr = PushoutByFloor2(z, &gZeroRanges[z->posture], TRUE);
  }
  if (((z->s).d.y > 0) || (attr != 0)) {
    (z->s).mode[2] = 2;  // Fall
    (z->s).mode[3] = 0;
  }
#else
  INCCODE("asm/wip/zeroNormalJumpRise.inc");
#endif
}

static void zeroDoubleJumpRise(struct Zero* z) {
  u8* n;
  s32 tmp;
  s16 dx;
  s16 g;
  metatile_attr_t attr;
  motion_t m = MOTION_VALUE(z);
  if ((m != MOTION(DM004_ZERO_AIR, 0x00)) && ((z->s).motion.state == MOTION_END)) {
    GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 0x00), 1, 4);
  }

  if (z->zeroInput & ZERO_INPUT_DPAD_LEFT) {
    dx = -abs((z->s).d.x);
    (z->s).spr.xflip = FALSE;
    (z->s).spr.oam.xflip = FALSE;
    (z->s).flags &= ~X_FLIP;

  } else if (z->zeroInput & ZERO_INPUT_DPAD_RIGHT) {
    dx = abs((z->s).d.x);
    (z->s).spr.xflip = TRUE;
    (z->s).spr.oam.xflip = TRUE;
    (z->s).flags |= X_FLIP;

  } else {
    dx = 0;
  }

  (z->s).coord.x += dx;

  n = &z->posture;
  PushoutWallX(z, &gZeroRanges[*n], 0);
  PushoutWallX(z, &gZeroRanges[*n], 1);
  (z->s).coord.y += (z->s).d.y;

  g = getFallAcceleration(z);
  (z->s).d.y += g;

  attr = PushoutByCeiling(z, &gZeroRanges[*n], 0);
  if (attr == 0) {
    attr = PushoutByFloor2(z, &gZeroRanges[*n], 1);
  }

  if ((0 < (z->s).d.y) || (attr != 0)) {
    (z->s).mode[2] = 2;
    (z->s).mode[3] = 0;
  }
}

WIP static void zeroWallJumpRise(struct Zero* z) {
#if MODERN
  s16 dx;
  struct Zero_b4* b4;
  metatile_attr_t attr;

  // Dash jump from wall
  motion_t m = MOTION_VALUE(z);
  if ((m == MOTION(DM005_ZERO_WALL, 0x01)) && ((z->s).motion.cmdIdx == 0) && (z->zeroInput & ZERO_INPUT_DASH)) {
    struct Zero_b4* b4;
    GotoMotion(&z->s, MOTION(DM006_ZERO_WALL_AIR, 0x01), 1, 4);
    if ((z->s).flags & X_FLIP) {
      (z->s).spr.xflip = FALSE;
      (z->s).spr.oam.xflip = FALSE;
      (z->s).d.x = -GetDashSpeed(z);
    } else {
      (z->s).spr.xflip = TRUE;
      (z->s).spr.oam.xflip = TRUE;
      (z->s).d.x = GetDashSpeed(z);
    }
    b4 = &(z->unk_b4);
    if (b4->shadow == NULL) {
      b4->shadow = (struct Entity*)CreateAfterImages(&z->s);
    }
  }

  if ((z->unk_b4).unk_111 != 0) {
    (z->unk_b4).unk_111--;
    dx = (z->s).d.x;
  } else {
    u8 flags = (z->s).flags;

    if (z->zeroInput & DPAD_LEFT) {
      dx = -abs((z->s).d.x);
      (z->s).spr.xflip = FALSE;
      (z->s).spr.oam.xflip = FALSE;
      (z->s).flags &= ~X_FLIP;

    } else if (z->zeroInput & DPAD_RIGHT) {
      dx = abs((z->s).d.x);
      (z->s).spr.xflip = TRUE;
      (z->s).spr.oam.xflip = TRUE;
      (z->s).flags |= X_FLIP;
    }

    b4 = &(z->unk_b4);
    if (b4->shadow == NULL) {
      if (((flags >> 4) & 1) != (((z->s).flags >> 4) & 1)) {
        SetMotion(&z->s, MOTION(DM005_ZERO_WALL, 0x02));
        (z->s).mode[3] = 0;
      }

    } else if (dx != (z->s).d.x) {
      SetMotion(&z->s, MOTION(DM006_ZERO_WALL_AIR, 0x02));
      (z->s).mode[3] = 0;
    }
  }
  (z->s).coord.x += dx;

  b4 = &(z->unk_b4);
  if (PushoutWallX(z, &gZeroRanges[z->posture], FALSE) != 0) {
    b4->blownSpeed = 0;
  }
  if (PushoutWallX(z, &gZeroRanges[z->posture], TRUE) != 0) {
    b4->blownSpeed = 0;
  }
  (z->s).coord.y += (z->s).d.y;
  (z->s).d.y += getFallAcceleration(z);
  attr = PushoutByCeiling(z, &gZeroRanges[z->posture], FALSE);
  if (attr == 0) {
    attr = PushoutByFloor2(z, &gZeroRanges[z->posture], TRUE);
  }
  if (((z->s).d.y > 0) || (attr != 0)) {
    (z->s).mode[2] = 2;
    (z->s).mode[3] = 0;
  }
#else
  INCCODE("asm/wip/zeroWallJumpRise.inc");
#endif
}

static void zeroRecoilJumpRise(struct Zero* z) {
  s16 dx;
  metatile_attr_t attr;
  struct Zero_b4* b4 = &(z->unk_b4);

  if (b4->blownSpeed != 0) {
    dx = b4->blownSpeed;

  } else if (z->zeroInput & DPAD_LEFT) {
    dx = -abs((z->s).d.x);
    (z->s).spr.xflip = FALSE;
    (z->s).spr.oam.xflip = FALSE;
    (z->s).flags &= ~X_FLIP;

  } else if (z->zeroInput & DPAD_RIGHT) {
    dx = abs((z->s).d.x);
    (z->s).spr.xflip = TRUE;
    (z->s).spr.oam.xflip = TRUE;
    (z->s).flags |= X_FLIP;

  } else {
    dx = 0;
  }
  (z->s).coord.x += dx;

  PushoutWallX(z, &gZeroRanges[z->posture], 0);
  PushoutWallX(z, &gZeroRanges[z->posture], 1);
  (z->s).coord.y += (z->s).d.y;
  (z->s).d.y += getFallAcceleration(z);

  attr = PushoutByCeiling(z, &gZeroRanges[z->posture], 0);
  if ((0 < (z->s).d.y) || (attr != 0)) {
    (z->s).mode[2] = 2;
    (z->s).mode[3] = 0;
  }
}

static void zeroRyuenjinJumpRise(struct Zero* z) {
  bool8 bVar2;
  metatile_attr_t attr;
  struct Zero_b4* b4 = &(z->unk_b4);

  (z->s).coord.x += (z->s).d.x;
  PushoutWallX(z, &gZeroRanges[z->posture], 0);
  PushoutWallX(z, &gZeroRanges[z->posture], 1);
  (z->s).coord.y += (z->s).d.y;
  (z->s).d.y += getFallAcceleration(z);

  bVar2 = FALSE;
  if (z->splitHeavensWait < 8) {
    z->splitHeavensWait++;
  } else {
    zero_input_t key, mask;
    if ((b4->status).mainWeapon == WEAPON_SABER) {
      key = z->zeroInput;
      mask = ZERO_INPUT_MAIN_WEAPON;
    } else {
      key = z->zeroInput;
      mask = ZERO_INPUT_SUB_WEAPON;
    }
    if ((key & mask) == 0) {
      bVar2 = TRUE;
    }
  }

  attr = PushoutByCeiling(z, &gZeroRanges[z->posture], 0);
  if (((0 < (z->s).d.y) || (attr != 0)) || (bVar2)) {
    (z->s).mode[2] = 2;
    (z->s).mode[3] = 0;
    (z->s).d.x = CalcDx(z);
  }
}

// --------------------------------------------

static void zeroJumpFallStep0(struct Zero* z);
static void zeroJumpFallStep1(struct Zero* z);
static void zeroJumpFallStep2(struct Zero* z);

static void zeroJumpFall(struct Zero* z) {
  static ZeroFunc const gZeroJumpFallSeq[] = {
      zeroJumpFallStep0,
      zeroJumpFallStep1,
      zeroJumpFallStep2,
  };

  if ((((gOverworld.unk_1c8.id & 0x7F) == STAGE_TWILIGHT_DESERT) && (FUN_080101a8() > 0)) || (z->unk_234 != 0)) {
    zero_08026f90(z, gZeroRanges);
  }
  gZeroJumpFallSeq[(z->s).mode[3]](z);
}

static void zeroJumpFallStep0(struct Zero* z) {
  s32 old, dx;
  if (z->airJumpped == 0) {
    motion_t m = MOTION_VALUE(z);
    if (m != MOTION(DM004_ZERO_AIR, 0x04)) {
      SetMotion(&z->s, MOTION(DM004_ZERO_AIR, 0x04));
    }
  } else {
    SetMotion(&z->s, MOTION(DM004_ZERO_AIR, 0x01));
  }

  old = (z->s).d.x;
  if ((old == 0) && (dx = CalcDx(z), old < dx)) {
    dx = CalcDx(z);
    (z->s).d.x = dx;
  }

  (z->s).d.y = 0;
  (z->s).mode[3] = 1;
  zeroJumpFallStep1(z);
}

static void zeroJumpFallStep1(struct Zero* z) {
  s16 dx, dy;

  if ((&z->unk_b4)->blownSpeed != 0) {
    dx = (&z->unk_b4)->blownSpeed;

  } else if (z->zeroInput & DPAD_LEFT) {
    dx = -abs((z->s).d.x);
    (z->s).spr.xflip = FALSE;
    (z->s).spr.oam.xflip = FALSE;
    (z->s).flags &= ~X_FLIP;

  } else if (z->zeroInput & DPAD_RIGHT) {
    dx = abs((z->s).d.x);
    (z->s).spr.xflip = TRUE;
    (z->s).spr.oam.xflip = TRUE;
    (z->s).flags |= X_FLIP;

  } else {
    dx = 0;
  }
  (z->s).coord.x += dx;

  PushoutWallX(z, &gZeroRanges[z->posture], 0);
  PushoutWallX(z, &gZeroRanges[z->posture], 1);
  (z->s).coord.y += (z->s).d.y;
  PushoutByCeiling(z, &gZeroRanges[z->posture], 0);

  // landing
  if (((!z->unk_b4.softPlatform) && (PushoutByFloor1(z, &gZeroRanges[z->posture], 1) != 0)) && (PushoutByFloor2(z, &gZeroRanges[z->posture], 0) != 0)) {
    (z->s).mode[1] = ZERO_GROUND;
    (z->s).mode[2] = 0;
    (z->s).mode[3] = 0;
    (z->s).d.x = dx;
    PlaySound(SE_WALK);
    return;
  }

  (z->s).d.y += getFallAcceleration(z);

  dy = calcMaxFallSpeed(z);
  if ((z->s).d.y <= dy) return;
  dy = calcMaxFallSpeed(z);
  (z->s).d.y = dy;
}

// 着地処理 or 落下速度の更新
static void zeroJumpFallStep2(struct Zero* z) {
  s16 g, dy;
  const u8* n = &z->posture;
  PushoutWallX(z, &gZeroRanges[*n], 0);
  PushoutWallX(z, &gZeroRanges[*n], 1);
  (z->s).coord.y += (z->s).d.y;
  PushoutByCeiling(z, &gZeroRanges[*n], 0);

  // landing
  if (((!z->unk_b4.softPlatform) && (PushoutByFloor1(z, &gZeroRanges[*n], 1) != 0)) && (PushoutByFloor2(z, &gZeroRanges[*n], 0) != 0)) {
    (z->s).mode[1] = ZERO_GROUND;
    (z->s).mode[2] = 0;
    (z->s).mode[3] = 0;
    z->unk_b4.attackMode[1] = 8;
    z->unk_b4.attackMode[2] = 0;
    (z->s).d.x = 0;
    (z->restriction).shield = FALSE;
    PlaySound(SE_WALK);
    return;
  }

  g = getFallAcceleration(z);
  (z->s).d.y += g;

  dy = calcMaxFallSpeed(z);
  if ((z->s).d.y <= dy) return;
  dy = calcMaxFallSpeed(z);
  (z->s).d.y = dy;
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void zeroWallSeq0(struct Zero* z);
static void zeroWallSeq1(struct Zero* z);

void zeroWall2(struct Zero* z) {
  static ZeroFunc const gZeroWallSeq[] = {
      zeroWallSeq0,
      zeroWallSeq1,
  };
  z->airJumpped = 0;
  gZeroWallSeq[(z->s).mode[2]](z);
}

static void zeroWallSeq0(struct Zero* z) {
  struct Zero_b4* b4;

  SetMotion(&z->s, MOTION(DM005_ZERO_WALL, 0x00));
  b4 = &(z->unk_b4);
  if (b4->shadow != NULL) {
    b4->shadow->work[1] = 1;
    b4->shadow = NULL;
  }
  (z->s).d.x = 0;
  (z->s).d.y = 0;
  b4->wallDustTimer = 8;
  (z->s).mode[2] = 1;
  zeroWallSeq1(z);
}

// 壁ずり、壁ジャンプ関連
WIP static void zeroWallSeq1(struct Zero* z) {
#if MODERN
  metatile_attr_t attr;

  z->posture = 2;
  attr = GetWallMetatileAttr(z, &gZeroRanges[z->posture], FALSE);
  if (attr & METATILE_SPIKE) {
    InstantlyKilling(z);
    zeroDamaged(z);
    return;
  }

  if (z->zeroInput & DPAD_RIGHT) {
    (z->s).coord.x += PIXEL(1);
  }
  if (z->zeroInput & DPAD_LEFT) {
    (z->s).coord.x -= PIXEL(1);
  }
  PushoutWallX(z, &gZeroRanges[z->posture], FALSE);
  (z->s).d.y = getWallFallSpeed(z);
  (z->s).coord.y += (z->s).d.y;

  if ((z->s).d.y == 0) {
    (z->unk_b4).wallDustTimer = 0;
    if ((MOTION_VALUE(z) == MOTION(DM005_ZERO_WALL, 0)) && ((z->s).motion.cmdIdx > 3)) {
      GotoMotion(&z->s, MOTION(DM005_ZERO_WALL, 0), 5, 2);
    }
  } else {
    if (--(z->unk_b4).wallDustTimer == 0xFF) {
      (z->unk_b4).wallDustTimer = 4;
      CreateWallDust(&(z->s).coord, ((z->s).flags >> 4) & 1);
      PlaySound(SE_DASH_2);
    };
  }

  // Check landing
  if ((PushoutByFloor1(z, &gZeroRanges[z->posture], TRUE) != 0) && (PushoutByFloor2(z, &gZeroRanges[z->posture], FALSE) != 0)) {
    (z->s).mode[1] = ZERO_GROUND;
    (z->s).mode[2] = 0;  // idle
    (z->s).mode[3] = 0;
    PlaySound(SE_WALK);
  }
#else
  INCCODE("asm/wip/zeroWallSeq1.inc");
#endif
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void zeroLadderUp(struct Zero* z);
static void zeroLadderDown(struct Zero* z);

void zeroLadder2(struct Zero* z) {
  static ZeroFunc const gZeroLadderUpDown[] = {
      zeroLadderUp,
      zeroLadderDown,
  };
  z->airJumpped = 0;
  (gZeroLadderUpDown[(z->s).mode[2]])(z);
}

// --------------------------------------------

static void zeroLadderUpStep0(struct Zero* z);
static void zeroLadderUpStep1(struct Zero* z);
static void zeroLadderUpStep2(struct Zero* z);

static void zeroLadderUp(struct Zero* z) {
  // はしご登る処理シーケンス (0 -> 1 -> 2 -> 0 -> 1 -> 2 -> ...)
  static ZeroFunc const gZeroLadderUpSeq[] = {
      zeroLadderUpStep0,
      zeroLadderUpStep1,
      zeroLadderUpStep2,
  };
  (gZeroLadderUpSeq[(z->s).mode[3]])(z);
  return;
}

static void zeroLadderUpStep0(struct Zero* z) {
  struct Zero_b4* b4;

  if ((z->unk_b4).prevMode == 0) {
    SetMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x00));
  } else {
    SetMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x01));
  }

  b4 = &(z->unk_b4);
  if (b4->shadow != NULL) {
    b4->shadow->work[1] = 1;
    b4->shadow = NULL;
  }
  (z->s).coord.x = ((z->s).coord.x & 0xFFFFF000) + PIXEL(8);
  (z->s).d.x = 0;
  (z->s).mode[3] = 1;
  zeroLadderUpStep1(z);
}

static void zeroLadderUpStep1(struct Zero* z) {
  motion_t m;
  metatile_attr_t attr;

  if (IsElfUsed(z, ELF_MAYA)) {
    (z->s).d.y = -0x280;
  } else {
    (z->s).d.y = -0x200;
  }

  m = MOTION_VALUE(z);
  if (m == MOTION(DM007_ZERO_LADDER, 0x00)) {
    if ((z->s).motion.state == MOTION_END) {
      SetMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x01));
    }
  } else if (!z->restriction.move) {
    if (z->zeroInput & ZERO_INPUT_PRESS_DPAD_UP) {
      GotoMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x01), (z->s).motion.cmdIdx, 1);
    }

    if (z->zeroInput & DPAD_UP) {
      (z->s).coord.y += (z->s).d.y;
      if (PushoutByCeilingOnLadder(z, &gZeroRanges[z->posture], TRUE) != 0) {
        GotoMotion(&z->s, MOTION_VALUE(z), (z->s).motion.cmdIdx, (z->s).motion.duration + 1);
        (z->s).coord.y -= (z->s).d.y;
      } else {
        if (ladder_08026bb0(z, &gZeroRanges[z->posture], TRUE) == 3) {
          (z->s).mode[3] = 2;
          zeroLadderUpStep2(z);
        } else {
          if ((z->s).motion.cmdIdx == 2 || (z->s).motion.cmdIdx == 5) {
            if ((z->s).motion.duration < 2) {
              PlaySound(SE_LADDER);
            }
          }
        }
      }
    } else {
      GotoMotion(&z->s, MOTION_VALUE(z), (z->s).motion.cmdIdx, (z->s).motion.duration + 1);
    }
  }
}

static void zeroLadderUpStep2(struct Zero* z) {
  if ((z->restriction).move) {
    (z->s).mode[1] = 0;
    (z->s).mode[2] = 0;
    (z->s).mode[3] = 0;
    PlaySound(SE_WALK);
  } else {
    motion_t m = MOTION_VALUE(z);
    if (m != MOTION(DM007_ZERO_LADDER, 0x02)) {
      SetMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x02));
      (z->s).coord.y = ((z->s).coord.y & 0xFFFFF000U) - 1;
    }

    if ((z->s).motion.state == MOTION_END) {
      (z->s).mode[1] = 0;
      (z->s).mode[2] = 0;
      (z->s).mode[3] = 0;
    }
  }
}

// --------------------------------------------

static void zeroLadderDownStep0(struct Zero* z);
static void zeroLadderDownStep1(struct Zero* z);
static void zeroLadderDownStep2(struct Zero* z);
static void zeroLadderDownStep3(struct Zero* z);

static void zeroLadderDown(struct Zero* z) {
  // はしご降りる処理シーケンス (0 -> (1) -> 2 -> 3 -> 0 -> (1) -> 2 -> ...)
  static ZeroFunc const gZeroLadderDownSeq[] = {
      zeroLadderDownStep0,
      zeroLadderDownStep1,
      zeroLadderDownStep2,
      zeroLadderDownStep3,
  };
  (gZeroLadderDownSeq[(z->s).mode[3]])(z);
  return;
}

static void zeroLadderDownStep0(struct Zero* z) {
  struct Zero_b4* b4;

  if ((z->unk_b4).prevMode == 0) {
    SetMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x03));
    (z->s).mode[3] = 1;
  } else {
    SetMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x04));
    (z->s).mode[3] = 2;
  }

  b4 = &(z->unk_b4);
  if (b4->shadow != NULL) {
    b4->shadow->work[1] = 1;
    b4->shadow = NULL;
  }
  (z->s).coord.x = ((z->s).coord.x & 0xFFFFF000) + 0x800;
  (z->s).d.x = 0;

  if ((z->s).mode[3] == 1) {
    zeroLadderDownStep1(z);
  } else {
    zeroLadderDownStep2(z);
  }
}

static void zeroLadderDownStep1(struct Zero* z) {
  motion_t m = MOTION_VALUE(z);
  if (m == MOTION(DM007_ZERO_LADDER, 0x03)) {
    if ((z->s).motion.state != MOTION_END) {
      return;
    }
    SetMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x04));
  }
  (z->s).coord.y = (z->s).coord.y + COORD(1);
  (z->s).mode[3] = 2;
}

static void zeroLadderDownStep2(struct Zero* z) {
  if (IsElfUsed(z, ELF_MAYA)) {
    (z->s).d.y = 0x280;
  } else {
    (z->s).d.y = 0x200;
  }
  if ((z->restriction).move) return;

  if (z->zeroInput & ZERO_INPUT_PRESS_DPAD_DOWN) {
    GotoMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x04), (z->s).motion.cmdIdx, 1);
  }

  if (z->zeroInput & ZERO_INPUT_DPAD_DOWN) {
    u8 val;

    (z->s).coord.y += (z->s).d.y;
    val = TryContinueLadderDown(z, &gZeroRanges[z->posture], 1);
    if (val == 0) {
      (z->s).mode[1] = ZERO_AIR;
      (z->s).mode[2] = 2;
      (z->s).mode[3] = 0;

    } else if (val == 3) {
      (z->s).mode[3] = 3;
      zeroLadderDownStep3(z);

    } else {
      s8 cmdIdx = (z->s).motion.cmdIdx;
      if (((cmdIdx == 1) || (cmdIdx == 4)) && ((z->s).motion.duration < 2)) {
        PlaySound(SE_LADDER);
      }
    }

  } else {
    motion_t m = MOTION_VALUE(z);
    GotoMotion(&z->s, m, (z->s).motion.cmdIdx, (z->s).motion.duration + 1);
  }
}

static void zeroLadderDownStep3(struct Zero* z) {
  if (!(z->restriction).move) {
    motion_t m = MOTION_VALUE(z);
    if (m != MOTION(DM007_ZERO_LADDER, 0x05)) {
      SetMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x05));
      (z->s).coord.y = ((z->s).coord.y & 0xfffff000) + 0xfff;
      PushoutByFloor1(z, &gZeroRanges[z->posture], 1);
    }

    if ((z->s).motion.state == MOTION_END) {
      (z->s).mode[1] = ZERO_GROUND;
      (z->s).mode[2] = 0;
      (z->s).mode[3] = 0;
    }
  }
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void zero_stun_0802bc04(struct Zero* z);
static void zeroStun(struct Zero* z);
static void zeroKilled(struct Zero* z);

void zeroDamaged(struct Zero* z) {
  /*
      Knockback(Stun): 0 -> 1
      Death:           0 -> 2
  */
  static ZeroFunc const gZeroDamagedSeq[] = {
      zero_stun_0802bc04,
      zeroStun,
      zeroKilled,
  };
  (gZeroDamagedSeq[(z->s).mode[2]])(z);
}

static void zero_stun_0802bc04(struct Zero* z) {
  struct Zero_b4* b4 = &(z->unk_b4);
  if (b4->shadow != NULL) {
    b4->shadow->work[1] = 1;
    b4->shadow = NULL;
  }

  z->saberAction = 0xFF;
  z->rodID = 0xFF;
  z->unk_12e = 0xFF;
  z->unk_127 = 0xFF;
  if (((z->body).status & BODY_STATUS_DEAD) || ((z->body).hp == 0)) {
    (z->s).mode[2] = 2;
    (z->s).mode[3] = 0;
    b4->attackMode[0] = 0;
    zeroKilled(z);
    return;
  }

  (z->s).mode[2] = 1;
  (z->s).mode[3] = 0;
  b4->attackMode[0] = 0;
  zeroStun(z);
}

static void zeroInitKnockBack(struct Zero* z);
static void zeroAirKnockBack(struct Zero* z);

static void zeroStun(struct Zero* z) {
  /*
    Ground : 0 -> 1
    Air:     0 -> 2
  */
  static ZeroFunc const gZeroStunSeq[] = {
      zeroInitKnockBack,
      zeroKnockBack,
      zeroAirKnockBack,
  };

  s32 old, dx;
  (gZeroStunSeq[(z->s).mode[3]])(z);

  if ((z->s).motion.state == MOTION_END) {
    if ((z->s).mode[3] == 2) {
      GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 0x04), 2, 1);
      (z->s).mode[1] = ZERO_AIR;
      (z->s).mode[2] = 2;
      (z->s).mode[3] = 1;

      old = abs((z->s).d.x);
      if (dx = CalcDx(z), old < dx) {
        dx = CalcDx(z);
        (z->s).d.x = dx;
      }
    } else {
      SetMotion(&z->s, GetDefaultMotion(z));
      (z->s).mode[1] = ZERO_GROUND;
      (z->s).mode[2] = 0;
      (z->s).mode[3] = 1;
      (z->s).d.x = 0;
    }
  }
}

static void FUN_0802c088(struct Zero* z);
static void explodeZero(struct Zero* z);
static void FUN_0802c138(struct Zero* z);

// マグマなどの即死も含む
static void zeroKilled(struct Zero* z) {
  // 0 -> 1 -> 2(explode) -> 3
  static ZeroFunc const gZeroDeadSeq[] = {
      FUN_0802c010,
      FUN_0802c088,
      explodeZero,
      FUN_0802c138,
  };
  (gZeroDeadSeq[(z->s).mode[3]])(z);
  return;
}

WIP static void zeroInitKnockBack(struct Zero* z) {
#if MODERN
  struct Zero_b4* b4;
  bool8 xflip;

  (z->s).mode[3] = 1;
  PlaySound(SE_ZERO_STUN);

  xflip = (((z->s).flags >> 4) & 1);
  if (xflip != z->isRightDir) {
    SetMotion(&z->s, MOTION(DM050_ZERO_STUN, 0x00));
  } else {
    SetMotion(&z->s, MOTION(DM049_ZERO_STUN, 0x00));
  }

  b4 = &(z->unk_b4);
  if (((b4->status).body == BODY_CHIP_ABSORBER) || (IsElfUsed(z, ELF_GAMBUL))) {
    if (z->blown) {
      z->blown = FALSE;
      if (z->isRightDir) {
        (z->s).d.x = -PIXEL(1);
      } else {
        (z->s).d.x = PIXEL(1);
      }
    } else {
      (z->s).d.x = 0;
    }

  } else {
    if (z->blown) {
      z->blown = FALSE;
      if (z->isRightDir) {
        (z->s).d.x = -PIXEL(4);
      } else {
        (z->s).d.x = PIXEL(4);
      }
      b4->blownSpeed = (z->s).d.x;
      (z->s).d.y = -0x440;
      (z->s).mode[3] = 2;
      zeroAirKnockBack(z);
      return;
    }

    if ((b4->status).body == BODY_CHIP_LIGHT) {
      if (z->isRightDir) {
        (z->s).d.x = -PIXEL(2);
      } else {
        (z->s).d.x = PIXEL(2);
      }
    } else {
      if (z->isRightDir) {
        (z->s).d.x = -PIXEL(1);
      } else {
        (z->s).d.x = PIXEL(1);
      }
    }
  }

  (z->s).d.y = 0;

  if (z->isGround) {
    (z->s).mode[3] = 1;
    zeroKnockBack(z);
  } else {
    (z->s).mode[3] = 2;
    zeroAirKnockBack(z);
  }
#else
  INCCODE("asm/wip/zeroInitKnockBack.inc");
#endif
}

void zeroKnockBack(struct Zero* z) {
  u8* n;
  s16 hp;
  metatile_attr_t attr;
  struct Zero_b4* b4 = &(z->unk_b4);

  b4->blownSpeed = 0;
  (z->s).d.y = 0;
  z->isGround = TRUE;

  if ((((gOverworld.unk_1c8.id & 0x7F) == STAGE_TWILIGHT_DESERT) && (hp = FUN_080101a8(), hp != 0)) || (z->unk_234 != 0)) {
    zero_08026f90(z, gZeroRanges);
  }

  (z->s).coord.x += (z->s).d.x;

  n = &z->posture;

  PushoutWallX(z, &gZeroRanges[*n], 0);
  PushoutWallX(z, &gZeroRanges[*n], 1);
  PushoutByFloor1(z, &gZeroRanges[*n], 0);

  attr = PushoutByFloor2(z, &gZeroRanges[*n], 0);
  if (attr == 0) {
    (z->s).mode[3] = 2;
  }
}

static void zeroAirKnockBack(struct Zero* z) {
  struct Zero_b4* b4;
  s16 hp;
  if ((((gOverworld.unk_1c8.id & 0x7F) == STAGE_TWILIGHT_DESERT) && (hp = FUN_080101a8(), hp != 0)) || (z->unk_234 != 0)) {
    zero_08026f90(z, gZeroRanges);
  }
  (z->s).coord.x += (z->s).d.x;

  b4 = &(z->unk_b4);
  if (PushoutWallX(z, &gZeroRanges[z->posture], 0) != 0) {
    b4->blownSpeed = 0;
  }
  if (PushoutWallX(z, &gZeroRanges[z->posture], 1) != 0) {
    b4->blownSpeed = 0;
  }
  (z->s).coord.y += (z->s).d.y;
  PushoutByCeiling(z, &gZeroRanges[z->posture], 0);

  // landing
  if (((!(z->unk_b4).softPlatform) && (PushoutByFloor1(z, &gZeroRanges[z->posture], 1) != 0)) && (PushoutByFloor2(z, &gZeroRanges[z->posture], 0) != 0)) {
    (z->s).mode[3] = 1;
    return;
  }

  (z->s).d.y += getFallAcceleration(z);
  if ((z->s).d.y > calcMaxFallSpeed(z)) {
    (z->s).d.y = calcMaxFallSpeed(z);
  }
}

void FUN_0802c010(struct Zero* z) {
  bool8 xflip;

  gStageRun.missionStatus &= ~MISSION_STAY;
  gStageRun.missionStatus |= MISSION_FAIL;
  (z->body).status = 0;
  (z->body).prevStatus = 0;
  (z->body).invincibleTime = 0;
  (z->s).flags &= ~COLLIDABLE;
  PlaySound(SE_ZERO_STUN);

  xflip = (((z->s).flags & X_FLIP) != 0);
  if (xflip != z->isRightDir) {
    SetMotion(&z->s, MOTION(DM050_ZERO_STUN, 0x00));
  } else {
    SetMotion(&z->s, MOTION(DM049_ZERO_STUN, 0x00));
  }

  (z->s).mode[3] = 1;
  FUN_0802c088(z);
}

static void FUN_0802c088(struct Zero* z) {
  if ((z->s).motion.cmdIdx != 0) {
    (z->s).flags &= ~DISPLAY;
    z->poseFixed = TRUE;
    REQUEST_STATIC_GRAPHIC(235);
    (z->s).mode[3] = 2;
  }
}

// ティウンティウン
static void explodeZero(struct Zero* z) {
  z->poseFixed = TRUE;
  PlaySound(SE_ZERO_DEATH);
  CreateFirework((z->s).coord.x, (z->s).coord.y - COORD(1), TRUE);
  (z->s).mode[3] = 3;
}

static void FUN_0802c138(struct Zero* z) {
  z->poseFixed = TRUE;
  return;
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void door2D_0(struct Zero* z);
static void door2D_1(struct Zero* z);

void zeroDoor2D(struct Zero* z) {
  static ZeroFunc const seq[] = {
      door2D_0,
      door2D_1,
  };
  z->posture = 4;
  (seq[(z->s).mode[2]])(z);
}

static void door2D_0(struct Zero* z) {
  struct Zero_b4* b4;
  struct Coord* velocity;

  if (z->unk_b4.prevMode == 0) {
    SetMotion(&z->s, MOTION(DM002_ZERO_RUN, 0x00));  // Ground
  } else {
    GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 0x04), 2, 1);  // Air
  }

  b4 = &(z->unk_b4);
  if (b4->shadow != NULL) {
    b4->shadow->work[1] = 1;
    b4->shadow = NULL;
  }

  z->unk_b4.attackMode[0] = 0;
  z->saberAction = 0xFF;
  z->rodID = 0xFF;
  z->unk_12e = 0xFF;
  z->unk_127 = 0xFF;

  velocity = &(z->s).d;
  velocity->y = 0;
  velocity->x = 0;

  (z->s).mode[2] = 1;
  door2D_1(z);
}

static void door2D_1(struct Zero* z) {
  motion_t m;
  if (z->isAreaChange) return;  // Wait for End of areachange

  m = MOTION_VALUE(z);
  if (m == MOTION(DM002_ZERO_RUN, 0x00)) {  // Ground
    (z->s).mode[1] = ZERO_GROUND;
    (z->s).mode[2] = 0;
    (z->s).mode[3] = 0;
    (z->s).d.x = 0;
  } else {
    // Air
    (z->s).mode[1] = ZERO_AIR;
    (z->s).mode[2] = 2;
    (z->s).mode[3] = 0;
  }
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void zero_door_0802c258(struct Zero* z);
static void zero_door_0802c2a4(struct Zero* z);
static void zero_door_0802c364(struct Zero* z);

void zeroDoor3D(struct Zero* z) {
  static ZeroFunc const gZeroDoor3DSeq[] = {
      zero_door_0802c258,
      zero_door_0802c2a4,
      zero_door_0802c364,
  };
  z->posture = 5;
  (gZeroDoor3DSeq[(z->s).mode[2]])(z);
}

static void zero_door_0802c258(struct Zero* z) {
  struct Zero_b4* b4 = &(z->unk_b4);
  if (b4->shadow != NULL) {
    b4->shadow->work[1] = 1;
    b4->shadow = NULL;
  }

  z->unk_b4.attackMode[0] = 0;
  KillAllWeapons(DeleteSaber);
  z->unk_238 = 0;
  gIsUsingDoor3D = TRUE;
  (z->s).mode[2] = 2;
  (z->s).mode[3] = 0;
  zero_door_0802c364(z);
}

WIP static void zero_door_0802c2a4(struct Zero* z) {
#if MODERN
  if ((z->s).mode[3] == 0) {
    SetMotion(&z->s, MOTION(DM002_ZERO_RUN, 0x00));
    if (z->unk_238 < (z->s).coord.x) {
      (z->s).spr.oam.xflip = (z->s).spr.xflip = FALSE;
      (z->s).flags &= ~X_FLIP;
      (z->s).d.x = -PIXEL(2);
    } else {
      (z->s).spr.oam.xflip = (z->s).spr.xflip = TRUE;
      (z->s).flags |= X_FLIP;
      (z->s).d.x = PIXEL(2);
    }
    (z->s).mode[3]++;
    return;
  }

  (z->s).coord.x += (z->s).d.x;
  if ((z->s).flags & X_FLIP) {
    if ((z->s).coord.x <= z->unk_238) {
      return;
    }
  } else {
    if ((z->s).coord.x >= z->unk_238) {
      return;
    }
  }
  (z->s).coord.x = z->unk_238;
  SetMotion(&z->s, MOTION(DM054_ZERO_DOOR_3D, 0x00));
  (z->s).mode[2] = 2;
  (z->s).mode[3] = 0;
#else
  INCCODE("asm/wip/zero_door_0802c2a4.inc");
#endif
}

static void zero_door_0802c364(struct Zero* z) {
  if ((z->s).mode[3] == 0) {
    SetMotion(&z->s, MOTION(DM054_ZERO_DOOR_3D, 0x00));
    (z->s).mode[3]++;
  }
  if (gIsUsingDoor3D == FALSE) {
    s32 y = FUN_0800a05c((z->s).coord.x, (z->s).coord.y);
    (z->s).coord.y = y;
    (z->s).mode[1] = ZERO_GROUND;
    (z->s).mode[2] = 0;
    (z->s).mode[3] = 0;
    (z->s).d.x = 0;
  }
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void zeroMode7Phase0(struct Zero* z);
static void zeroMode7Phase1(struct Zero* z);
static void zeroMode7Phase2(struct Zero* z);

void zeroMode7(struct Zero* z) {
  static ZeroFunc const gZeroMode7Seq[] = {
      zeroMode7Phase0,
      zeroMode7Phase1,
      zeroMode7Phase2,
  };
  (gZeroMode7Seq[(z->s).mode[2]])(z);
}

static void zeroMode7Phase0(struct Zero* z) {
  struct Zero_b4* b4;
  metatile_attr_t attr;
  struct Coord* d;

  if ((z->unk_143.raw & 0xF) != 0) {
    if ((z->unk_143.raw & 0xF0) == 0) {
      GotoMotion(&z->s, MOTION(DM050_ZERO_STUN, 0x00), 3, 4);
    } else {
      GotoMotion(&z->s, MOTION(DM049_ZERO_STUN, 0x00), 3, 4);
    }
    z->unk_143.lo = 0;
  } else {
    bool8 flip = (((z->s).flags >> 4) & 1);
    if (flip != z->isRightDir) {
      GotoMotion(&z->s, MOTION(DM050_ZERO_STUN, 0x00), 3, 4);
    } else {
      GotoMotion(&z->s, MOTION(DM049_ZERO_STUN, 0x00), 3, 4);
    }
  }

  b4 = &(z->unk_b4);
  if (b4->shadow != NULL) {
    b4->shadow->work[1] = 1;
    b4->shadow = NULL;
  }
  (z->unk_b4).attackMode[0] = 0;
  z->saberAction = 0xFF;
  z->rodID = 0xFF;
  z->unk_12e = 0xFF;
  z->unk_127 = 0xFF;
  d = &(z->s).d;
  d->x = d->y = 0;

  attr = PushoutByFloor2(z, &gZeroRanges[z->posture], FALSE);
  if (attr == 0) {
    (z->s).mode[2] = 2;
    (z->s).mode[3] = 0;
    zeroMode7Phase2(z);
  } else {
    (z->s).mode[2] = 1;
    (z->s).mode[3] = 0;
    zeroMode7Phase1(z);
  }
}

NAKED static void zeroMode7Phase1(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r5, r0, #0\n\
	ldr r0, _0802C4FC @ =0x0000018D\n\
	adds r1, r5, r0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	adds r0, r5, #0\n\
	bl IsButtonMashed\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _0802C534\n\
	adds r1, r5, #0\n\
	adds r1, #0x95\n\
	ldrb r2, [r1]\n\
	cmp r2, r0\n\
	bhs _0802C500\n\
	movs r0, #0\n\
	b _0802C502\n\
	.align 2, 0\n\
_0802C4FC: .4byte 0x0000018D\n\
_0802C500:\n\
	subs r0, r2, r0\n\
_0802C502:\n\
	strb r0, [r1]\n\
	ldrb r0, [r5, #0x1e]\n\
	lsls r0, r0, #8\n\
	adds r1, r5, #0\n\
	adds r1, #0x70\n\
	ldrb r1, [r1]\n\
	orrs r1, r0\n\
	movs r2, #0xc8\n\
	lsls r2, r2, #6\n\
	cmp r1, r2\n\
	bne _0802C528\n\
	movs r1, #0xc4\n\
	lsls r1, r1, #6\n\
	adds r0, r5, #0\n\
	movs r2, #3\n\
	movs r3, #4\n\
	bl GotoMotion\n\
	b _0802C534\n\
_0802C528:\n\
	adds r0, r5, #0\n\
	adds r1, r2, #0\n\
	movs r2, #3\n\
	movs r3, #4\n\
	bl GotoMotion\n\
_0802C534:\n\
	ldr r0, _0802C570 @ =0x00000143\n\
	adds r1, r5, r0\n\
	ldrb r2, [r1]\n\
	movs r0, #0xf\n\
	ands r0, r2\n\
	adds r4, r1, #0\n\
	cmp r0, #0\n\
	beq _0802C59E\n\
	movs r0, #0xf0\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _0802C574\n\
	ldrb r0, [r5, #0x1e]\n\
	lsls r0, r0, #8\n\
	adds r1, r5, #0\n\
	adds r1, #0x70\n\
	ldrb r1, [r1]\n\
	orrs r1, r0\n\
	movs r2, #0xc8\n\
	lsls r2, r2, #6\n\
	cmp r1, r2\n\
	beq _0802C594\n\
	adds r0, r5, #0\n\
	adds r1, r2, #0\n\
	movs r2, #3\n\
	movs r3, #4\n\
	bl GotoMotion\n\
	b _0802C594\n\
	.align 2, 0\n\
_0802C570: .4byte 0x00000143\n\
_0802C574:\n\
	ldrb r0, [r5, #0x1e]\n\
	lsls r0, r0, #8\n\
	adds r1, r5, #0\n\
	adds r1, #0x70\n\
	ldrb r1, [r1]\n\
	orrs r1, r0\n\
	movs r2, #0xc4\n\
	lsls r2, r2, #6\n\
	cmp r1, r2\n\
	beq _0802C594\n\
	adds r0, r5, #0\n\
	adds r1, r2, #0\n\
	movs r2, #3\n\
	movs r3, #4\n\
	bl GotoMotion\n\
_0802C594:\n\
	ldrb r1, [r4]\n\
	movs r0, #0x10\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r4]\n\
_0802C59E:\n\
	adds r0, r5, #0\n\
	adds r0, #0x95\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0802C5B8\n\
	adds r0, r5, #0\n\
	adds r0, #0x8c\n\
	ldr r0, [r0]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0802C5CA\n\
_0802C5B8:\n\
	movs r0, #0\n\
	strb r0, [r5, #0xd]\n\
	strb r0, [r5, #0xe]\n\
	strb r0, [r5, #0xf]\n\
	str r0, [r5, #0x60]\n\
	adds r0, r5, #0\n\
	bl zeroNeutral2\n\
	b _0802C616\n\
_0802C5CA:\n\
	ldr r0, _0802C61C @ =0x00000147\n\
	adds r6, r5, r0\n\
	ldrb r1, [r6]\n\
	lsls r1, r1, #3\n\
	ldr r4, _0802C620 @ =gZeroRanges\n\
	adds r1, r1, r4\n\
	adds r0, r5, #0\n\
	movs r2, #0\n\
	bl PushoutWallX\n\
	ldrb r1, [r6]\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r4\n\
	adds r0, r5, #0\n\
	movs r2, #1\n\
	bl PushoutWallX\n\
	ldrb r1, [r6]\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r4\n\
	adds r0, r5, #0\n\
	movs r2, #0\n\
	bl PushoutByFloor1\n\
	ldrb r1, [r6]\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r4\n\
	adds r0, r5, #0\n\
	movs r2, #0\n\
	bl PushoutByFloor2\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	cmp r1, #0\n\
	bne _0802C616\n\
	movs r0, #2\n\
	strb r0, [r5, #0xe]\n\
	strb r1, [r5, #0xf]\n\
_0802C616:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0802C61C: .4byte 0x00000147\n\
_0802C620: .4byte gZeroRanges\n\
 .syntax divided\n");
}

NAKED static void zeroMode7Phase2(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r5, r0, #0\n\
	bl IsButtonMashed\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _0802C676\n\
	adds r1, r5, #0\n\
	adds r1, #0x95\n\
	ldrb r2, [r1]\n\
	cmp r2, r0\n\
	bhs _0802C642\n\
	movs r0, #0\n\
	b _0802C644\n\
_0802C642:\n\
	subs r0, r2, r0\n\
_0802C644:\n\
	strb r0, [r1]\n\
	ldrb r0, [r5, #0x1e]\n\
	lsls r0, r0, #8\n\
	adds r1, r5, #0\n\
	adds r1, #0x70\n\
	ldrb r1, [r1]\n\
	orrs r1, r0\n\
	movs r2, #0xc8\n\
	lsls r2, r2, #6\n\
	cmp r1, r2\n\
	bne _0802C66A\n\
	movs r1, #0xc4\n\
	lsls r1, r1, #6\n\
	adds r0, r5, #0\n\
	movs r2, #3\n\
	movs r3, #4\n\
	bl GotoMotion\n\
	b _0802C676\n\
_0802C66A:\n\
	adds r0, r5, #0\n\
	adds r1, r2, #0\n\
	movs r2, #3\n\
	movs r3, #4\n\
	bl GotoMotion\n\
_0802C676:\n\
	ldr r0, _0802C6B0 @ =0x00000143\n\
	adds r1, r5, r0\n\
	ldrb r2, [r1]\n\
	movs r0, #0xf\n\
	ands r0, r2\n\
	adds r4, r1, #0\n\
	cmp r0, #0\n\
	beq _0802C6DE\n\
	movs r0, #0xf0\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _0802C6B4\n\
	ldrb r0, [r5, #0x1e]\n\
	lsls r0, r0, #8\n\
	adds r1, r5, #0\n\
	adds r1, #0x70\n\
	ldrb r1, [r1]\n\
	orrs r1, r0\n\
	movs r2, #0xc8\n\
	lsls r2, r2, #6\n\
	cmp r1, r2\n\
	beq _0802C6D4\n\
	adds r0, r5, #0\n\
	adds r1, r2, #0\n\
	movs r2, #3\n\
	movs r3, #4\n\
	bl GotoMotion\n\
	b _0802C6D4\n\
	.align 2, 0\n\
_0802C6B0: .4byte 0x00000143\n\
_0802C6B4:\n\
	ldrb r0, [r5, #0x1e]\n\
	lsls r0, r0, #8\n\
	adds r1, r5, #0\n\
	adds r1, #0x70\n\
	ldrb r1, [r1]\n\
	orrs r1, r0\n\
	movs r2, #0xc4\n\
	lsls r2, r2, #6\n\
	cmp r1, r2\n\
	beq _0802C6D4\n\
	adds r0, r5, #0\n\
	adds r1, r2, #0\n\
	movs r2, #3\n\
	movs r3, #4\n\
	bl GotoMotion\n\
_0802C6D4:\n\
	ldrb r1, [r4]\n\
	movs r0, #0x10\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r4]\n\
_0802C6DE:\n\
	adds r0, r5, #0\n\
	adds r0, #0x95\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0802C6F8\n\
	adds r0, r5, #0\n\
	adds r0, #0x8c\n\
	ldr r0, [r0]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0802C70E\n\
_0802C6F8:\n\
	movs r0, #0\n\
	movs r1, #1\n\
	strb r1, [r5, #0xd]\n\
	movs r1, #2\n\
	strb r1, [r5, #0xe]\n\
	strb r0, [r5, #0xf]\n\
	str r0, [r5, #0x60]\n\
	adds r0, r5, #0\n\
	bl zeroAir2\n\
	b _0802C7C0\n\
_0802C70E:\n\
	ldr r4, [r5, #0x54]\n\
	ldr r1, _0802C788 @ =0x00000147\n\
	adds r6, r5, r1\n\
	ldrb r1, [r6]\n\
	lsls r1, r1, #3\n\
	ldr r7, _0802C78C @ =gZeroRanges\n\
	adds r1, r1, r7\n\
	adds r0, r5, #0\n\
	movs r2, #0\n\
	bl PushoutWallX\n\
	ldrb r1, [r6]\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r7\n\
	adds r0, r5, #0\n\
	movs r2, #1\n\
	bl PushoutWallX\n\
	ldr r0, [r5, #0x54]\n\
	cmp r4, r0\n\
	beq _0802C746\n\
	ldrb r1, [r6]\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r7\n\
	adds r0, r5, #0\n\
	movs r2, #0\n\
	bl PushoutByCeiling\n\
_0802C746:\n\
	ldr r0, [r5, #0x58]\n\
	ldr r1, [r5, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x58]\n\
	ldr r1, _0802C790 @ =0x00000113\n\
	adds r0, r5, r1\n\
	ldrb r4, [r0]\n\
	cmp r4, #0\n\
	bne _0802C794\n\
	ldrb r1, [r6]\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r7\n\
	adds r0, r5, #0\n\
	movs r2, #1\n\
	bl PushoutByFloor1\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _0802C794\n\
	ldrb r1, [r6]\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r7\n\
	adds r0, r5, #0\n\
	movs r2, #0\n\
	bl PushoutByFloor2\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _0802C794\n\
	movs r0, #1\n\
	strb r0, [r5, #0xe]\n\
	strb r4, [r5, #0xf]\n\
	b _0802C7C0\n\
	.align 2, 0\n\
_0802C788: .4byte 0x00000147\n\
_0802C78C: .4byte gZeroRanges\n\
_0802C790: .4byte 0x00000113\n\
_0802C794:\n\
	adds r0, r5, #0\n\
	bl getFallAcceleration\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	ldr r1, [r5, #0x60]\n\
	adds r1, r1, r0\n\
	str r1, [r5, #0x60]\n\
	adds r0, r5, #0\n\
	bl calcMaxFallSpeed\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	ldr r1, [r5, #0x60]\n\
	cmp r1, r0\n\
	ble _0802C7C0\n\
	adds r0, r5, #0\n\
	bl calcMaxFallSpeed\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	str r0, [r5, #0x60]\n\
_0802C7C0:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void zeroFloat0(struct Zero* z);
static void zeroFloat1(struct Zero* z);
static void zeroFloat2(struct Zero* z);

// バーエイド、バーリーフに助けられている状態
void zeroFloat(struct Zero* z) {
  static ZeroFunc const gZeroFloatSeq[] = {
      zeroFloat0,
      zeroFloat1,
      zeroFloat2,
  };

  u8 e;
  struct Zero_b4* b4 = &(z->unk_b4);
  if (((u8)((b4->status).asset.satelites[0] - ELF_BIRAID) <= 1) || (e = (b4->status).asset.satelites[1], e == ELF_BIRAID) || (e == ELF_BIRLEAF)) {
    (gZeroFloatSeq[(z->s).mode[2]])(z);
  } else {
    (z->s).mode[1] = ZERO_AIR;
    (z->s).mode[2] = 2;
    (z->s).mode[3] = 0;
    (z->s).d.y = 0;
  }
  z->blown = FALSE;
}

static void zeroFloat0(struct Zero* z) {
  struct Zero_b4* b4;

  GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 0x04), 1, 3);
  b4 = &(z->unk_b4);
  z->floatTimer = 60;
  (z->s).d.y = -PIXEL(2);
  b4->blownSpeed = 0;
  if (b4->shadow != NULL) {
    b4->shadow->work[1] = 1;
    b4->shadow = NULL;
  }
  (z->s).mode[2] = 1;
  zeroFloat1(z);
}

static void zeroFloat1(struct Zero* z) {
  (z->s).coord.y += (z->s).d.y;
  (z->s).d.x = 0;
  (z->s).d.y += 0x10;
  PushoutByCeiling(z, &gZeroRanges[z->posture], FALSE);
  if (0 < (z->s).d.y) {
    (z->s).mode[2] = 2;
    zeroFloat2(z);
  }
}

NAKED static void zeroFloat2(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r4, r0, #0\n\
	ldr r0, [r4, #0x58]\n\
	mov r8, r0\n\
	movs r1, #0x86\n\
	lsls r1, r1, #2\n\
	adds r7, r4, r1\n\
	ldr r0, [r7]\n\
	movs r1, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802C8EC\n\
	ldr r0, [r4, #0x54]\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	adds r1, r4, #0\n\
	adds r1, #0x4c\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	adds r2, r4, #0\n\
	adds r2, #0x4a\n\
	ldrb r0, [r2]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	ldrb r0, [r4, #0xa]\n\
	orrs r1, r0\n\
	strb r1, [r4, #0xa]\n\
_0802C8EC:\n\
	ldr r0, [r7]\n\
	movs r1, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802C91A\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, _0802C9CC @ =0xFFFFFE80\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	adds r1, r4, #0\n\
	adds r1, #0x4c\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	adds r2, r4, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	subs r0, #0x11\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
_0802C91A:\n\
	ldr r0, _0802C9D0 @ =0x00000147\n\
	adds r5, r4, r0\n\
	ldrb r1, [r5]\n\
	lsls r1, r1, #3\n\
	ldr r6, _0802C9D4 @ =gZeroRanges\n\
	adds r1, r1, r6\n\
	adds r0, r4, #0\n\
	movs r2, #0\n\
	bl PushoutWallX\n\
	ldrb r1, [r5]\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r6\n\
	adds r0, r4, #0\n\
	movs r2, #1\n\
	bl PushoutWallX\n\
	ldr r0, [r7]\n\
	movs r1, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802C94E\n\
	ldr r0, [r4, #0x58]\n\
	ldr r1, _0802C9CC @ =0xFFFFFE80\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
_0802C94E:\n\
	ldr r0, [r7]\n\
	movs r1, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802C962\n\
	ldr r0, [r4, #0x58]\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
_0802C962:\n\
	ldrb r1, [r5]\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r6\n\
	adds r0, r4, #0\n\
	movs r2, #0\n\
	bl PushoutByCeiling\n\
	ldrb r1, [r5]\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r6\n\
	adds r0, r4, #0\n\
	movs r2, #1\n\
	bl PushoutByFloor1\n\
	ldrb r1, [r5]\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r6\n\
	adds r0, r4, #0\n\
	movs r2, #1\n\
	bl PushoutByFloor2\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _0802C996\n\
	mov r0, r8\n\
	str r0, [r4, #0x58]\n\
_0802C996:\n\
	movs r0, #0x90\n\
	lsls r0, r0, #1\n\
	adds r1, r4, r0\n\
	ldrb r0, [r1]\n\
	subs r0, #1\n\
	movs r2, #0\n\
	strb r0, [r1]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	beq _0802C9B6\n\
	ldr r0, [r7]\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802C9C2\n\
_0802C9B6:\n\
	movs r0, #1\n\
	strb r0, [r4, #0xd]\n\
	movs r0, #2\n\
	strb r0, [r4, #0xe]\n\
	strb r2, [r4, #0xf]\n\
	str r2, [r4, #0x60]\n\
_0802C9C2:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0802C9CC: .4byte 0xFFFFFE80\n\
_0802C9D0: .4byte 0x00000147\n\
_0802C9D4: .4byte gZeroRanges\n\
 .syntax divided\n");
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void zeroTalk0(struct Zero* z);
static void zeroTalk1(struct Zero* z);

void zeroTalk(struct Zero* z) {
  static ZeroFunc const gZeroTalkSeq[] = {
      zeroTalk0,
      zeroTalk1,
  };
  z->posture = 5;
  (gZeroTalkSeq[(z->s).mode[2]])(z);
}

static void zeroTalk0(struct Zero* z) {
  struct Zero_b4* b4;

  SetMotion(&z->s, MOTION(DM051_ZERO_UNK, 0x00));

  b4 = &(z->unk_b4);
  if (b4->shadow != NULL) {
    b4->shadow->work[1] = 1;
    b4->shadow = NULL;
  }

  z->unk_b4.attackMode[0] = 0;
  gInChat = TRUE;
  (z->s).mode[2] = 1;
  (z->s).mode[3] = 0;
  zeroTalk1(z);
}

WIP static void zeroTalk1(struct Zero* z) {
#if MODERN
  struct Body* body = gCollisionManager.talkTo;  // 話し相手
  if ((body != NULL) && (body->parent != NULL)) {
    const bool8 isRight = (z->s).coord.x < ((body->parent)->s).coord.x;
    (z->s).spr.oam.xflip = (z->s).spr.xflip = isRight;
    if (isRight) {
      (z->s).flags |= X_FLIP;
    } else {
      (z->s).flags &= ~X_FLIP;
    }
  }

  if ((z->s).mode[3] == 0) {
    if (!gInChat) {
      SetMotion(&z->s, MOTION(DM051_ZERO_UNK, 0x01));
      (z->s).mode[3]++;
    }
    return;
  }

  if ((z->s).motion.state == MOTION_END) {
    (z->s).mode[1] = ZERO_GROUND;
    (z->s).mode[2] = 0;
    (z->s).mode[3] = 0;
    (z->s).d.x = 0;
  }
#else
  INCCODE("asm/wip/zeroTalk1.inc");
#endif
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void zeroTeleport0(struct Zero* z);
static void zeroTeleport1(struct Zero* z);
static void zeroTeleport2(struct Zero* z);
static void zeroTeleport3(struct Zero* z);
static void zeroTeleport4(struct Zero* z);

// 転送時の仁王立ち、転送直後のかがむ処理
void zeroTeleport(struct Zero* z) {
  // clang-format off
  static ZeroFunc const gZeroTeleportSeq[] = {
      zeroTeleport0,
      zeroTeleport1,
      zeroTeleport2,
      zeroTeleport3,
      zeroTeleport4,
  };
  // clang-format on

  (gZeroTeleportSeq[(z->s).mode[2]])(z);
  return;
}

static void zeroTeleport0(struct Zero* z) {
  struct Zero_b4* b4 = &(z->unk_b4);
  if (b4->shadow != NULL) {
    b4->shadow->work[1] = 1;
    b4->shadow = NULL;
  }

  z->unk_b4.attackMode[0] = 0;
  gInTransport = TRUE;
  (z->s).mode[2] = (z->s).mode[3];
  (z->s).mode[3] = 0;
}

NAKED static void zeroTeleport1(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	movs r7, #0\n\
	ldr r0, _0802CB98 @ =gCollisionManager\n\
	movs r1, #0xc6\n\
	lsls r1, r1, #3\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	cmp r0, #0\n\
	beq _0802CBEA\n\
	ldr r3, [r0, #0x2c]\n\
	cmp r3, #0\n\
	beq _0802CBEA\n\
	adds r5, r3, #0\n\
	ldrb r0, [r4, #0xf]\n\
	cmp r0, #0\n\
	bne _0802CBC4\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, [r5, #0x54]\n\
	cmp r1, r0\n\
	beq _0802CBF0\n\
	movs r6, #0x80\n\
	lsls r6, r6, #2\n\
	adds r0, r4, #0\n\
	adds r1, r6, #0\n\
	bl SetMotion\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, [r5, #0x54]\n\
	cmp r1, r0\n\
	ble _0802CBA0\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r7, [r0]\n\
	adds r2, r4, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r0, _0802CB9C @ =0xFFFFFE00\n\
	str r0, [r4, #0x5c]\n\
	b _0802CBBC\n\
	.align 2, 0\n\
_0802CB98: .4byte gCollisionManager\n\
_0802CB9C: .4byte 0xFFFFFE00\n\
_0802CBA0:\n\
	adds r1, r4, #0\n\
	adds r1, #0x4c\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	adds r2, r4, #0\n\
	adds r2, #0x4a\n\
	ldrb r0, [r2]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	ldrb r0, [r4, #0xa]\n\
	orrs r1, r0\n\
	strb r1, [r4, #0xa]\n\
	str r6, [r4, #0x5c]\n\
_0802CBBC:\n\
	ldrb r0, [r4, #0xf]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xf]\n\
	b _0802CBEC\n\
_0802CBC4:\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, [r4, #0x5c]\n\
	adds r2, r1, r0\n\
	str r2, [r4, #0x54]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802CBE0\n\
	ldr r0, [r5, #0x54]\n\
	cmp r2, r0\n\
	ble _0802CBEC\n\
	str r0, [r4, #0x54]\n\
	b _0802CBF0\n\
_0802CBE0:\n\
	ldr r0, [r3, #0x54]\n\
	cmp r2, r0\n\
	bge _0802CBEC\n\
	str r0, [r4, #0x54]\n\
	b _0802CBF0\n\
_0802CBEA:\n\
	movs r7, #1\n\
_0802CBEC:\n\
	cmp r7, #0\n\
	beq _0802CBF8\n\
_0802CBF0:\n\
	movs r1, #0\n\
	movs r0, #2\n\
	strb r0, [r4, #0xe]\n\
	strb r1, [r4, #0xf]\n\
_0802CBF8:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void zeroTeleport2(struct Zero* z) {
  motion_t m;
  switch ((z->s).mode[3]) {
    case 0: {
      m = MOTION(DM051_ZERO_UNK, 0x00);
      break;
    }
    case 1: {
      if ((z->s).motion.state != MOTION_NEXT) {
        return;
      }
      m = MOTION(DM052_ZERO_TELEPORT_START, 0x00);
      break;
    }
    case 2:
    default: {
      return;
    }
  }
  SetMotion(&z->s, m);
  (z->s).mode[3]++;
}

static void zeroTeleport3(struct Zero* z) {
  switch ((z->s).mode[3]) {
    case 0: {
      SetMotion(&z->s, MOTION(DM052_ZERO_TELEPORT_START, 0x01));
      (z->s).mode[3]++;
      break;
    }
    case 1: {
      if ((z->s).motion.state != MOTION_END) {
        return;
      }
      (z->s).flags &= ~DISPLAY;
      (z->s).mode[3]++;
      break;
    }
    case 2: {
      if (!gInTransport) {
        (z->s).mode[2] = 4;
        (z->s).mode[3] = 0;
      }
      break;
    }
  }
}

static void zeroTeleport4(struct Zero* z) {
  switch ((z->s).mode[3]) {
    case 0: {
      SetMotion(&z->s, MOTION(DM053_ZERO_TELEPORT_END, 0x02));
      (z->s).coord.y = FUN_0800a05c((z->s).coord.x, (z->s).coord.y);
      resetSateliteElfPosition(z);
      (z->s).mode[3]++;
      break;
    }
    case 1: {
      (z->s).flags |= DISPLAY;
      if ((z->s).motion.state != MOTION_NEXT) {
        return;
      }
      SetMotion(&z->s, MOTION(DM053_ZERO_TELEPORT_END, 0x01));
      (z->s).mode[3]++;
      break;
    }
    case 2: {
      if ((z->s).motion.state == MOTION_END) {
        (z->s).mode[1] = ZERO_GROUND;
        (z->s).mode[2] = 0;
        (z->s).mode[3] = 0;
        (z->s).d.x = 0;
      }
      break;
    }
    default: {
      break;
    }
  }
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void zeroCyberDoor0(struct Zero* z);
static void zeroCyberDoor1(struct Zero* z);
static void zeroCyberDoor2(struct Zero* z);

void zeroCyberDoor(struct Zero* z) {
  static ZeroFunc const sZeroCyberDoorSeq[] = {
      zeroCyberDoor0,
      zeroCyberDoor1,
      zeroCyberDoor2,
  };

  z->posture = 4;
  (sZeroCyberDoorSeq[(z->s).mode[2]])(z);
}

static void zeroCyberDoor0(struct Zero* z) {
  struct Zero_b4* b4 = &(z->unk_b4);
  if (b4->shadow != NULL) {
    b4->shadow->work[1] = 1;
    b4->shadow = NULL;
  }

  z->unk_b4.attackMode[0] = 0;
  (z->s).mode[2]++;
  (z->s).mode[3] = 0;
}

WIP static void zeroCyberDoor1(struct Zero* z) {
#if MODERN
  s16 n;
  switch ((z->s).mode[3]) {
    case 0: {
      SetMotion(&z->s, MOTION(DM054_ZERO_DOOR_3D, 0x01));
      break;
    }
    case 1: {
      if ((z->s).motion.state != MOTION_END) {
        return;
      }
      n = (s16)(z->unk_b4).sound;
      if (n != MUS_NONE) {
        stopSound(n);
        (z->unk_b4).sound = MUS_NONE;
      }
      (z->s).flags &= ~DISPLAY;
      break;
    }
    default: {
      return;
    }
  }
  (z->s).mode[3]++;
#else
  INCCODE("asm/wip/zeroCyberDoor1.inc");
#endif
}

NAKED static void zeroCyberDoor2(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xf]\n\
	cmp r0, #0xa\n\
	bls _0802CDC8\n\
	b _0802CFD0\n\
_0802CDC8:\n\
	lsls r0, r0, #2\n\
	ldr r1, _0802CDD4 @ =_0802CDD8\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0802CDD4: .4byte _0802CDD8\n\
_0802CDD8: @ jump table\n\
	.4byte _0802CE04 @ case 0\n\
	.4byte _0802CE64 @ case 1\n\
	.4byte _0802CE76 @ case 2\n\
	.4byte _0802CE9C @ case 3\n\
	.4byte _0802CEE8 @ case 4\n\
	.4byte _0802CF7E @ case 5\n\
	.4byte _0802CFD0 @ case 6\n\
	.4byte _0802CFD0 @ case 7\n\
	.4byte _0802CFD0 @ case 8\n\
	.4byte _0802CFD0 @ case 9\n\
	.4byte _0802CFBC @ case 10\n\
_0802CE04:\n\
	ldr r0, _0802CE58 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r1, r0, #0x18\n\
	cmp r1, #0\n\
	bne _0802CE3C\n\
	ldr r2, _0802CE5C @ =0x00000231\n\
	adds r0, r4, r2\n\
	strb r1, [r0]\n\
	adds r0, r4, #0\n\
	bl GetMaxHP\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	adds r5, r4, #0\n\
	adds r5, #0xa4\n\
	movs r2, #0\n\
	ldrsh r1, [r5, r2]\n\
	cmp r0, r1\n\
	bge _0802CE3C\n\
	adds r0, r4, #0\n\
	bl GetMaxHP\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	strh r0, [r5]\n\
_0802CE3C:\n\
	adds r0, r4, #0\n\
	bl resetSateliteElfPosition\n\
	ldr r0, _0802CE60 @ =FUN_080399fc\n\
	bl KillAllWeapons\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	movs r0, #0x14\n\
	strb r0, [r4, #0x12]\n\
	b _0802CE90\n\
	.align 2, 0\n\
_0802CE58: .4byte gCurStory\n\
_0802CE5C: .4byte 0x00000231\n\
_0802CE60: .4byte FUN_080399fc\n\
_0802CE64:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	beq _0802CE74\n\
	b _0802CFD0\n\
_0802CE74:\n\
	b _0802CE90\n\
_0802CE76:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _0802CE98 @ =0x00003402\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	bl FUN_0800a05c\n\
	str r0, [r4, #0x58]\n\
_0802CE90:\n\
	ldrb r0, [r4, #0xf]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xf]\n\
	b _0802CFD0\n\
	.align 2, 0\n\
_0802CE98: .4byte 0x00003402\n\
_0802CE9C:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	beq _0802CEA8\n\
	b _0802CFD0\n\
_0802CEA8:\n\
	movs r5, #0\n\
	strb r5, [r4, #0x12]\n\
	ldr r0, _0802CEDC @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802CEE2\n\
	adds r0, r4, #0\n\
	movs r1, #0xff\n\
	bl FUN_08032880\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _0802CEE0\n\
	movs r1, #0xd0\n\
	lsls r1, r1, #6\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	strb r5, [r4, #0x12]\n\
	strb r5, [r4, #0x13]\n\
	movs r0, #4\n\
	strb r0, [r4, #0xf]\n\
	b _0802CFD0\n\
	.align 2, 0\n\
_0802CEDC: .4byte gCurStory\n\
_0802CEE0:\n\
	strb r0, [r4, #0x12]\n\
_0802CEE2:\n\
	movs r0, #5\n\
	strb r0, [r4, #0xf]\n\
	b _0802CFD0\n\
_0802CEE8:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _0802CFD0\n\
	adds r5, r4, #0\n\
	adds r5, #0x54\n\
	ldrb r1, [r4, #0x13]\n\
	adds r0, r4, #0\n\
	bl FUN_08032880\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	ldrb r0, [r4, #0x13]\n\
	movs r6, #1\n\
	adds r2, r6, #0\n\
	ands r2, r0\n\
	adds r0, r5, #0\n\
	bl CreateCyberSpaceElf\n\
	ldrb r0, [r4, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r4, #0x13]\n\
	adds r0, r4, #0\n\
	movs r1, #0xff\n\
	bl FUN_08032880\n\
	ldrb r1, [r4, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r1, r0\n\
	bhs _0802CF4C\n\
	adds r0, r4, #0\n\
	bl FUN_08032880\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	ldrb r0, [r4, #0x13]\n\
	adds r2, r6, #0\n\
	ands r2, r0\n\
	adds r0, r5, #0\n\
	bl CreateCyberSpaceElf\n\
	ldrb r0, [r4, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r4, #0x13]\n\
_0802CF4C:\n\
	adds r0, r4, #0\n\
	movs r1, #0xff\n\
	bl FUN_08032880\n\
	ldrb r1, [r4, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r1, r0\n\
	blo _0802CF6A\n\
	ldrb r0, [r4, #0xf]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xf]\n\
	movs r0, #0x20\n\
	strb r0, [r4, #0x12]\n\
	b _0802CFD0\n\
_0802CF6A:\n\
	adds r0, r4, #0\n\
	movs r1, #0xff\n\
	bl FUN_08032880\n\
	ldrb r1, [r4, #0x13]\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x19\n\
	strb r0, [r4, #0x12]\n\
	b _0802CFD0\n\
_0802CF7E:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _0802CFD0\n\
	ldr r0, _0802CFB0 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802CFA0\n\
	ldr r0, _0802CFB4 @ =0x00000231\n\
	adds r1, r4, r0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
_0802CFA0:\n\
	ldr r1, _0802CFB8 @ =0x00003301\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	movs r0, #0xa\n\
	strb r0, [r4, #0xf]\n\
	b _0802CFD0\n\
	.align 2, 0\n\
_0802CFB0: .4byte gCurStory\n\
_0802CFB4: .4byte 0x00000231\n\
_0802CFB8: .4byte 0x00003301\n\
_0802CFBC:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0802CFD0\n\
	movs r0, #0\n\
	strb r0, [r4, #0xd]\n\
	strb r0, [r4, #0xe]\n\
	strb r0, [r4, #0xf]\n\
	str r0, [r4, #0x5c]\n\
_0802CFD0:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}
