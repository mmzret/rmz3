#include "global.h"
#include "motion.h"
#include "overworld.h"
#include "sound.h"
#include "weapon.h"
#include "zero.h"

enum ZeroLadder {
  LADDER_UP,
  LADDER_DOWN,
};

// ------------------------------------------------------------------------------------------------------------------------------------

static void inIdle(struct Zero* z);
static void inWalk(struct Zero* z);
static void inDash(struct Zero* z);

void HandlePlayerInput_Ground(struct Zero* z) {
  static ZeroFunc const gZeroMode0Actions1[] = {
      inIdle,
      inWalk,
      inDash,
  };
  (gZeroMode0Actions1[(z->s).mode[2]])(z);
}

// --------------------------------------------

/*
  0x08029ac4
  プレイヤーのボタンを見て:
    - ダッシュを開始
    - ドアを開ける
    - 会話を始める
    - etc
  と色々な処理への分岐を担う
*/
WIP static void inIdle(struct Zero* z) {
#if MODERN
  u32 status;
  zero_input_t key;
  struct Zero_b4* b4;

  if (z->isAreaChange) {
    (z->s).mode[1] = ZERO_DOOR_2D;
    (z->s).mode[2] = 0;
    (z->s).mode[3] = 0;
    return;
  }

  if ((z->restriction).move) return;

  status = (z->body).status;
  key = z->zeroInput;
  if ((status & BODY_STATUS_DOOR) && ((key & (DPAD_RIGHT | DPAD_LEFT | ZERO_INPUT_PRESS_DPAD_UP)) == ZERO_INPUT_PRESS_DPAD_UP)) {
    (z->s).mode[1] = ZERO_DOOR_3D;
    (z->s).mode[3] = (z->s).mode[2] = 0;
    return;
  }

  if ((status & BODY_STATUS_CHAT) && (key & ZERO_INPUT_PRESS_DPAD_UP)) {
    (z->s).mode[1] = ZERO_TALK;
    (z->s).mode[2] = 0;
    (z->s).mode[3] = 0;
    return;
  }

  if ((status & BODY_STATUS_TELEPORTAL) && (key & ZERO_INPUT_PRESS_DPAD_UP)) {
    (z->s).mode[1] = ZERO_TELEPORT;
    (z->s).mode[2] = 0;
    (z->s).mode[3] = 1;
    return;
  }

  b4 = &(z->unk_b4);
  if (key & ZERO_INPUT_PRESS_JUMP) {
    if ((key & DPAD_DOWN) && (IsOnSoftPlatform(z, gZeroRanges, 0) != 0)) {
      z->unk_b4.softPlatform = TRUE;
      b4->softPlatformY = (z->s).coord.y + PIXEL(13);
      (z->s).mode[1] = ZERO_AIR;
      (z->s).mode[2] = 2;
      (z->s).mode[3] = 0;
      return;
    }

    (z->s).mode[1] = ZERO_AIR;
    (z->s).mode[2] = 0;
    (z->s).mode[3] = 0;
    return;
  }

  if ((!(z->restriction).dash) && (key & ZERO_INPUT_PRESS_DASH) && TryGroundDash(z, &gZeroRanges[1], 0)) {
    (z->s).mode[2] = GROUND_DASH;
    (z->s).mode[3] = 0;
    return;
  }

  if (key & (DPAD_RIGHT | DPAD_LEFT)) {
    (z->s).mode[2] = GROUND_WALK;
    (z->s).mode[3] = 0;
    return;
  }

  if (z->unk_12e != 0xFF) {
    return;
  }

  if ((key & DPAD_DOWN) && (TryLadderDown(z, gZeroRanges, FALSE) == 2)) {
    (z->s).mode[1] = ZERO_LADDER;
    (z->s).mode[2] = LADDER_DOWN;
    (z->s).mode[3] = 0;
    return;
  }

  if ((key & DPAD_UP) && (TryLadderUp(z, gZeroRanges, FALSE) != 0)) {
    (z->s).mode[1] = ZERO_LADDER;
    (z->s).mode[2] = LADDER_UP;
    (z->s).mode[3] = 0;
  }
#else
  INCCODE("asm/wip/inIdle.inc");
#endif
}

// --------------------------------------------

/*
  0x08029c60
  - (梯子とかの)床に立っている時に下ボタンが押されたら、すり抜ける処理(空中モード)
  - エリア移動フラグが立っていたら、2Dドアモードにする
*/
WIP static void inWalk(struct Zero* z) {
#if MODERN
  zero_input_t key;
  struct Zero_b4* b4 = &(z->unk_b4);

  if (z->isAreaChange) {
    (z->s).mode[1] = ZERO_DOOR_2D;
    (z->s).mode[2] = 0;
    (z->s).mode[3] = 0;
    return;
  }

  if ((z->restriction).move) return;

  key = z->zeroInput;
  if (key & ZERO_INPUT_PRESS_JUMP) {
    if ((key & DPAD_DOWN) && (IsOnSoftPlatform(z, &gZeroRanges[0], 0) != 0)) {
      z->unk_b4.softPlatform = TRUE;
      b4->softPlatformY = (z->s).coord.y + PIXEL(13);
      (z->s).mode[1] = ZERO_AIR;
      (z->s).mode[2] = 2;
      (z->s).mode[3] = 0;
      return;
    }

    (z->s).mode[1] = ZERO_AIR;
    (z->s).mode[2] = 0;
    (z->s).mode[3] = 0;
    return;
  }

  if (!(z->restriction).dash) {
    if ((key & ZERO_INPUT_PRESS_DASH) && TryGroundDash(z, &gZeroRanges[1], 0)) {
      (z->s).mode[2] = GROUND_DASH;
      (z->s).mode[3] = 0;
      return;
    }
  }

  if (!(key & (DPAD_RIGHT | DPAD_LEFT))) {
    (z->s).mode[2] = GROUND_IDLE;
    (z->s).mode[3] = 0;
  }
#else
  INCCODE("asm/wip/inWalk.inc");
#endif
}

// --------------------------------------------

static void inDash(struct Zero* z) {
  zero_input_t key;
  u8 mode;
  struct Zero_b4* b4 = &(z->unk_b4);

  if (z->isAreaChange) {
    (z->s).mode[1] = ZERO_DOOR_2D;
    (z->s).mode[2] = 0;
    (z->s).mode[3] = 0;
    return;
  }

  if ((z->restriction).move) return;

  key = z->zeroInput;
  if (key & ZERO_INPUT_PRESS_JUMP) {
    if ((key & ZERO_INPUT_DPAD_DOWN) && (IsOnSoftPlatform(z, &gZeroRanges[1], 0) != 0)) {
      z->unk_b4.softPlatform = TRUE;
      b4->softPlatformY = (z->s).coord.y + PIXEL(13);
      (z->s).mode[1] = ZERO_AIR;
      (z->s).mode[2] = 2;
      (z->s).mode[3] = 0;
      return;
    }

    (z->s).mode[1] = ZERO_AIR;
    (z->s).mode[2] = 0;
    (z->s).mode[3] = 0;
  } else {
    if (key & ZERO_INPUT_DASH) {
      return;
    }

    if ((key & (ZERO_INPUT_DPAD_RIGHT | ZERO_INPUT_DPAD_LEFT)) != 0) {
      (z->s).mode[2] = GROUND_WALK;
      (z->s).mode[3] = 0;
      return;
    }

    (z->s).mode[2] = GROUND_IDLE;
    (z->s).mode[3] = 0;
    return;
  }
}

// ------------------------------------------------------------------------------------------------------------------------------------

WIP void HandlePlayerInput_Air(struct Zero* z) {
#if MODERN
  u8 foot;
  u32 val;
  zero_input_t* key;
  bool32 ok;
  struct Zero_b4* b4 = &(z->unk_b4);

  if (z->isAreaChange) {
    (z->s).mode[1] = ZERO_DOOR_2D;
    (z->s).mode[2] = 0;
    (z->s).mode[3] = 0;
    return;
  }

  if (*((u16*)&(z->s).mode[2]) == 0x202) {
    return;
  }

  ok = z->zeroInput & ZERO_INPUT_PRESS_JUMP;
  key = &z->zeroInput;
  if (ok) {
    if ((z->s).mode[3] < 3) {
      val = zero_08026970(z, &gZeroRanges[z->posture], FALSE);
      if (val) {
        bool32 xflip;

        if (b4->shadow != NULL) {
          b4->shadow->work[1] = 1;
          b4->shadow = NULL;
        }

        xflip = (val - 1) & 1;
        (z->s).spr.oam.xflip = (z->s).spr.xflip = xflip;
        if (xflip) {
          (z->s).flags |= X_FLIP;
        } else {
          (z->s).flags &= ~X_FLIP;
        }
        (z->s).mode[1] = ZERO_AIR;
        (z->s).mode[2] = 0;
        (z->s).mode[3] = 2;
      } else if ((foot = (b4->status).foot, (foot == FOOT_CHIP_SPLASH) || (foot == FOOT_CHIP_ULTIMA)) && z->canSplashJump) {
        (z->s).mode[1] = ZERO_AIR;
        (z->s).mode[2] = 0;
        (z->s).mode[3] = 0;
      } else if (foot = ((&(z->unk_b4))->status).foot, ((z->last & INPUT_DISABLED) == 0) && ((foot == FOOT_CHIP_DOUBLE) || (foot == FOOT_CHIP_ULTIMA)) && !z->airJumpped) {
        z->airJumpped = TRUE;
        (z->s).mode[1] = ZERO_AIR;
        (z->s).mode[2] = 0;
        (z->s).mode[3] = 1;
      } else {
        goto DONE;
      }
      zero_08032724(z);
      return;
    }
  }

DONE:
  if (((*key) & DPAD_UP) && TryLadderUp(z, &gZeroRanges[0], FALSE)) {
    (z->s).mode[1] = ZERO_LADDER;
    (z->s).mode[2] = 0;
    (z->s).mode[3] = 0;
    return;
  }

  if ((z->s).mode[2] == 1) {
    if ((u8)((z->s).mode[3] - 3) >= 2) {
      if (((*key) & ZERO_INPUT_JUMP) == 0) {
        (z->s).mode[2] = 2;
        (z->s).mode[3] = 0;
      }
    }
    return;
  }

  if ((z->s).mode[2] == 2) {
    if (CanWallSlide(z, &gZeroRanges[z->posture], FALSE)) {
      (z->s).mode[1] = ZERO_WALL;
      (z->s).mode[2] = 0;
    }
  }
#else
  INCCODE("asm/wip/HandlePlayerInput_Air.inc");
#endif
}

// ------------------------------------------------------------------------------------------------------------------------------------

WIP void HandlePlayerInput_Wall(struct Zero* z) {
#if MODERN
  motion_t m;
  u8 state;

  if (z->isAreaChange) {
    (z->s).mode[1] = ZERO_DOOR_2D;
    (z->s).mode[2] = 0;
    (z->s).mode[3] = 0;
    return;
  }

  if (z->zeroInput & ZERO_INPUT_PRESS_JUMP) {
    PushoutWallX(z, &gZeroRanges[z->posture], 0);
    (z->s).mode[1] = ZERO_AIR;
    (z->s).mode[2] = 0;
    (z->s).mode[3] = 2;
    zero_08032724(z);
    return;
  }

  state = IsZeroAgainstWall(z, &gZeroRanges[2], 0);
  if (state && IsForwardPressed(z, &gZeroRanges[2], 0)) {
    return;
  }

  if (state == 1) {
    if ((z->s).flags & X_FLIP) {
      (z->s).coord.x += PIXEL(8);
    } else {
      (z->s).coord.x -= PIXEL(8);
    }
    PushoutWallX(z, &gZeroRanges[0], 0);
  }

  // sprite face is reversed in Wall slide
  m = MOTION_VALUE(z);
  if (m == MOTION(DM005_ZERO_WALL, 0x0)) {
    if ((z->s).motion.cmdIdx < 3) {
      goto _DONE;
    }
  }

  (z->s).spr.oam.xflip = (z->s).spr.xflip = (((z->s).flags >> X_FLIP) ^ 1) & 1;
  if ((z->s).spr.oam.xflip) {
    (z->s).flags |= X_FLIP;
  } else {
    (z->s).flags &= ~X_FLIP;
  }

_DONE:
  (z->s).mode[1] = ZERO_AIR;
  (z->s).mode[2] = 2;
  (z->s).mode[3] = 0;
#else
  INCCODE("asm/wip/HandlePlayerInput_Wall.inc");
#endif
}

// ------------------------------------------------------------------------------------------------------------------------------------

void HandlePlayerInput_Ladder(struct Zero* z) {
  struct Zero_b4* b4 = &(z->unk_b4);

  const zero_input_t key = z->zeroInput;
  if ((key & (ZERO_INPUT_PRESS_JUMP | ZERO_INPUT_DPAD_UP)) == ZERO_INPUT_PRESS_JUMP) {
    if (((z->s).mode[2] == 1) && ((z->s).mode[3] < 2)) {
      b4->softPlatform = TRUE;
      b4->softPlatformY = (z->s).coord.y + PIXEL(13);
    }
    (z->s).mode[1] = ZERO_AIR;
    (z->s).mode[2] = 2;
    (z->s).mode[3] = 0;

  } else {
    bool8 cannotMove = (*(s8*)&z->restriction) & 1;
    if (!cannotMove) {
      if ((z->s).mode[2] == 0) {
        if ((key & ZERO_INPUT_DPAD_DOWN) == 0) {
          return;
        }
        if ((z->s).mode[3] != 1) {
          return;
        }
        (z->s).mode[2] = 1;
      } else {
        if ((key & ZERO_INPUT_DPAD_UP) == 0) {
          return;
        }
        if ((z->s).mode[3] != 2) {
          return;
        }
        (z->s).mode[2] = cannotMove;
      }
      (z->s).mode[3] = cannotMove;
    }
  }
}

// ------------------------------------------------------------------------------------------------------------------------------------

void HandlePlayerInput_Damaged(struct Zero* z) { return; }

// ------------------------------------------------------------------------------------------------------------------------------------

void HandlePlayerInput_Door2D(struct Zero* z) { return; }

// ------------------------------------------------------------------------------------------------------------------------------------

void HandlePlayerInput_Door3D(struct Zero* z) { return; }

// ------------------------------------------------------------------------------------------------------------------------------------

void HandlePlayerInput_Mode7(struct Zero* z) { return; }

// ------------------------------------------------------------------------------------------------------------------------------------

void HandlePlayerInput_Float(struct Zero* z) { return; }

// ------------------------------------------------------------------------------------------------------------------------------------

void HandlePlayerInput_Talk(struct Zero* z) { return; }

// ------------------------------------------------------------------------------------------------------------------------------------

void HandlePlayerInput_Teleport(struct Zero* z) { return; }

// ------------------------------------------------------------------------------------------------------------------------------------

void HandlePlayerInput_Cyber(struct Zero* z) { return; }
