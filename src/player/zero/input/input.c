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

NAKED void HandlePlayerInput_Air(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r4, r0, #0\n\
	adds r5, r4, #0\n\
	adds r5, #0xb4\n\
	ldr r1, _08029DF4 @ =0x00000119\n\
	adds r0, r4, r1\n\
	ldrb r7, [r0]\n\
	cmp r7, #0\n\
	beq _08029DF8\n\
	movs r1, #0\n\
	movs r0, #5\n\
	b _08029F0C\n\
	.align 2, 0\n\
_08029DF4: .4byte 0x00000119\n\
_08029DF8:\n\
	ldrh r1, [r4, #0xe]\n\
	ldr r0, _08029E6C @ =0x00000202\n\
	cmp r1, r0\n\
	bne _08029E02\n\
	b _08029F60\n\
_08029E02:\n\
	movs r2, #0x86\n\
	lsls r2, r2, #2\n\
	adds r1, r4, r2\n\
	ldr r0, [r1]\n\
	movs r6, #1\n\
	ands r0, r6\n\
	mov r8, r1\n\
	cmp r0, #0\n\
	beq _08029EEC\n\
	ldrb r0, [r4, #0xf]\n\
	cmp r0, #2\n\
	bhi _08029EEC\n\
	ldr r1, _08029E70 @ =0x00000147\n\
	adds r0, r4, r1\n\
	ldrb r1, [r0]\n\
	lsls r1, r1, #3\n\
	ldr r0, _08029E74 @ =gZeroRanges\n\
	adds r1, r1, r0\n\
	adds r0, r4, #0\n\
	movs r2, #0\n\
	bl zero_08026970\n\
	lsls r0, r0, #0x18\n\
	lsrs r1, r0, #0x18\n\
	cmp r1, #0\n\
	beq _08029E8C\n\
	ldr r0, [r5, #0x40]\n\
	cmp r0, #0\n\
	beq _08029E40\n\
	strb r6, [r0, #0x11]\n\
	str r7, [r5, #0x40]\n\
_08029E40:\n\
	subs r1, #1\n\
	movs r0, #1\n\
	ands r1, r0\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r5, r4, #0\n\
	adds r5, #0x4a\n\
	lsls r3, r1, #4\n\
	ldrb r2, [r5]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r3\n\
	strb r0, [r5]\n\
	cmp r1, #0\n\
	beq _08029E78\n\
	ldrb r0, [r4, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _08029E7E\n\
	.align 2, 0\n\
_08029E6C: .4byte 0x00000202\n\
_08029E70: .4byte 0x00000147\n\
_08029E74: .4byte gZeroRanges\n\
_08029E78:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_08029E7E:\n\
	strb r0, [r4, #0xa]\n\
	movs r0, #0\n\
	movs r1, #1\n\
	strb r1, [r4, #0xd]\n\
	strb r0, [r4, #0xe]\n\
	movs r0, #2\n\
	b _08029EDC\n\
_08029E8C:\n\
	ldrb r0, [r5, #0x11]\n\
	cmp r0, #1\n\
	beq _08029E96\n\
	cmp r0, #7\n\
	bne _08029EAA\n\
_08029E96:\n\
	movs r2, #0x8e\n\
	lsls r2, r2, #1\n\
	adds r0, r4, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _08029EAA\n\
	strb r6, [r4, #0xd]\n\
	strb r1, [r4, #0xe]\n\
	strb r1, [r4, #0xf]\n\
	b _08029EDE\n\
_08029EAA:\n\
	adds r2, r4, #0\n\
	adds r2, #0xb4\n\
	ldr r1, _08029EE8 @ =0x00000216\n\
	adds r0, r4, r1\n\
	ldrh r1, [r0]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08029EEC\n\
	ldrb r0, [r2, #0x11]\n\
	cmp r0, #2\n\
	beq _08029EC8\n\
	cmp r0, #7\n\
	bne _08029EEC\n\
_08029EC8:\n\
	movs r0, #0x8d\n\
	lsls r0, r0, #1\n\
	adds r2, r4, r0\n\
	ldrb r1, [r2]\n\
	cmp r1, #0\n\
	bne _08029EEC\n\
	movs r0, #1\n\
	strb r0, [r2]\n\
	strb r0, [r4, #0xd]\n\
	strb r1, [r4, #0xe]\n\
_08029EDC:\n\
	strb r0, [r4, #0xf]\n\
_08029EDE:\n\
	adds r0, r4, #0\n\
	bl zero_08032724\n\
	b _08029F60\n\
	.align 2, 0\n\
_08029EE8: .4byte 0x00000216\n\
_08029EEC:\n\
	mov r1, r8\n\
	ldr r0, [r1]\n\
	movs r1, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08029F18\n\
	ldr r1, _08029F14 @ =gZeroRanges\n\
	adds r0, r4, #0\n\
	movs r2, #0\n\
	bl TryLadderUp\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _08029F18\n\
	movs r1, #0\n\
	movs r0, #3\n\
_08029F0C:\n\
	strb r0, [r4, #0xd]\n\
	strb r1, [r4, #0xe]\n\
	strb r1, [r4, #0xf]\n\
	b _08029F60\n\
	.align 2, 0\n\
_08029F14: .4byte gZeroRanges\n\
_08029F18:\n\
	ldrb r5, [r4, #0xe]\n\
	cmp r5, #1\n\
	bne _08029F3C\n\
	ldrb r0, [r4, #0xf]\n\
	subs r0, #3\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bls _08029F60\n\
	mov r2, r8\n\
	ldr r0, [r2]\n\
	movs r1, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08029F60\n\
	strb r1, [r4, #0xe]\n\
	strb r0, [r4, #0xf]\n\
	b _08029F60\n\
_08029F3C:\n\
	cmp r5, #2\n\
	bne _08029F60\n\
	ldr r1, _08029F6C @ =0x00000147\n\
	adds r0, r4, r1\n\
	ldrb r1, [r0]\n\
	lsls r1, r1, #3\n\
	ldr r0, _08029F70 @ =gZeroRanges\n\
	adds r1, r1, r0\n\
	adds r0, r4, #0\n\
	movs r2, #0\n\
	bl CanWallSlide\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _08029F60\n\
	movs r0, #0\n\
	strb r5, [r4, #0xd]\n\
	strb r0, [r4, #0xe]\n\
_08029F60:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08029F6C: .4byte 0x00000147\n\
_08029F70: .4byte gZeroRanges\n\
 .syntax divided\n");
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
