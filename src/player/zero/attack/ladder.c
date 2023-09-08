#include "global.h"
#include "motion.h"
#include "overworld.h"
#include "sound.h"
#include "weapon.h"
#include "zero.h"

static void zero_ladder_08030ecc(struct Zero* z);
static void zero_ladder_08030ee0(struct Zero* z);
static void nop_08030f54(struct Zero* z);

void ZeroAttack_Ladder(struct Zero* z) {
  static ZeroFunc const sZeroLadderAttackRoutine[] = {
      zero_ladder_08030ecc,
      zero_ladder_08030ee0,
      nop_08030f54,
      zeroLadderAtk,
  };
  (sZeroLadderAttackRoutine[(z->unk_b4).attackMode[0]])(z);
}

static void zero_ladder_08030ecc(struct Zero* z) {
  (z->unk_b4).attackMode[0] = 1;
  zero_ladder_08030ee0(z);
}

NAKED static void zero_ladder_08030ee0(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	movs r0, #0x94\n\
	lsls r0, r0, #1\n\
	adds r1, r4, r0\n\
	adds r0, r4, #0\n\
	bl IsAttackOK\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
	cmp r3, #0\n\
	beq _08030F18\n\
	ldr r2, _08030F14 @ =0x0000012B\n\
	adds r1, r4, r2\n\
	movs r0, #0xff\n\
	strb r0, [r1]\n\
	adds r1, r4, #0\n\
	adds r1, #0xec\n\
	movs r2, #0\n\
	movs r0, #3\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	adds r0, #0xed\n\
	strb r2, [r0]\n\
	b _08030F3A\n\
	.align 2, 0\n\
_08030F14: .4byte 0x0000012B\n\
_08030F18:\n\
	ldr r0, _08030F44 @ =0x0000012B\n\
	adds r2, r4, r0\n\
	ldrb r1, [r2]\n\
	adds r0, r1, #0\n\
	cmp r0, #0xff\n\
	beq _08030F48\n\
	movs r2, #0x94\n\
	lsls r2, r2, #1\n\
	adds r0, r4, r2\n\
	strb r1, [r0]\n\
	adds r1, r4, #0\n\
	adds r1, #0xec\n\
	movs r0, #3\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	adds r0, #0xed\n\
	strb r3, [r0]\n\
_08030F3A:\n\
	adds r0, r4, #0\n\
	bl zeroLadderAtk\n\
	b _08030F4E\n\
	.align 2, 0\n\
_08030F44: .4byte 0x0000012B\n\
_08030F48:\n\
	movs r0, #0xff\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
_08030F4E:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void nop_08030f54(struct Zero* z) { return; }

static void onBuster(struct Zero* z);
static void onSaber(struct Zero* z);
static void onRod(struct Zero* z);
static void onShield(struct Zero* z);

void zeroLadderAtk(struct Zero* z) {
  static ZeroFunc const weapon[] = {
      onBuster,
      onSaber,
      onRod,
      onShield,
  };
  (weapon[z->usingWeapon])(z);
}

// --------------------------------------------

static void buster_0(struct Zero* z);
static void buster_1(struct Zero* z);
static void buster_2(struct Zero* z);
static void buster_3(struct Zero* z);

static void onBuster(struct Zero* z) {
  static ZeroFunc const seq[] = {
      buster_0,
      buster_1,
      buster_2,
      buster_3,
  };
  (seq[(z->unk_b4).attackMode[1]])(z);
}

// 0x08030f94
NAKED static void buster_0(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	ldr r7, [r4, #0x58]\n\
	ldrb r0, [r4, #0xa]\n\
	lsrs r5, r0, #4\n\
	movs r6, #1\n\
	ands r5, r6\n\
	movs r0, #0x86\n\
	lsls r0, r0, #2\n\
	adds r3, r4, r0\n\
	ldr r0, [r3]\n\
	movs r1, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08030FC8\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r6, [r0]\n\
	adds r2, r4, #0\n\
	adds r2, #0x4a\n\
	ldrb r0, [r2]\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	ldrb r0, [r4, #0xa]\n\
	orrs r1, r0\n\
	strb r1, [r4, #0xa]\n\
_08030FC8:\n\
	ldr r0, [r3]\n\
	movs r1, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08030FEE\n\
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
_08030FEE:\n\
	ldr r1, _0803102C @ =0xFFFFE500\n\
	ldr r2, _08031030 @ =0xFFFFEF00\n\
	ldrb r3, [r4, #0xa]\n\
	lsrs r3, r3, #4\n\
	ands r3, r6\n\
	adds r0, r4, #0\n\
	bl CreateBuster\n\
	cmp r0, #0\n\
	bne _08031048\n\
	adds r1, r5, #0\n\
	ands r1, r6\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r3, r4, #0\n\
	adds r3, #0x4a\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	ands r5, r6\n\
	cmp r5, #0\n\
	beq _08031034\n\
	ldrb r0, [r4, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _0803103A\n\
	.align 2, 0\n\
_0803102C: .4byte 0xFFFFE500\n\
_08031030: .4byte 0xFFFFEF00\n\
_08031034:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_0803103A:\n\
	strb r0, [r4, #0xa]\n\
	str r7, [r4, #0x58]\n\
	adds r1, r4, #0\n\
	adds r1, #0xec\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	b _08031064\n\
_08031048:\n\
	ldr r1, _0803106C @ =0x00000D01\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldr r0, _08031070 @ =0x00000129\n\
	adds r1, r4, r0\n\
	movs r0, #2\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	adds r0, #0xed\n\
	strb r6, [r0]\n\
	adds r0, r4, #0\n\
	bl buster_1\n\
_08031064:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0803106C: .4byte 0x00000D01\n\
_08031070: .4byte 0x00000129\n\
 .syntax divided\n");
};

static void buster_1(struct Zero* z) {
  u8* ct;
  motion_t m, expected;
  struct Zero_b4* b4 = &(z->unk_b4);

  (z->restriction).move = TRUE;
  if ((b4->status).mainWeapon == WEAPON_BUSTER) {
    (z->restriction).mainCharge = TRUE;
  } else {
    (z->restriction).subCharge = TRUE;
  }

  m = MOTION_VALUE(z);
  expected = MOTION(DM013_ZERO_BUSTER_LADDER, 0x01);
  ct = &z->atkCooltime;
  if (m != expected) {
    GotoMotion(&z->s, expected, 0, *ct);
  }

  *ct = (z->s).motion.duration;
  if ((z->s).motion.duration < 2) {
    GotoMotion(&z->s, expected, 1, 4);
    (z->unk_b4).attackMode[1] = 2;
  }
}

static void buster_2(struct Zero* z) {
  u8* ct;
  motion_t m, expected;
  struct Zero_b4* b4 = &(z->unk_b4);

  (z->restriction).move = TRUE;
  if ((b4->status).mainWeapon == WEAPON_BUSTER) {
    (z->restriction).mainCharge = TRUE;
  } else {
    (z->restriction).subCharge = TRUE;
  }

  m = MOTION_VALUE(z);
  expected = MOTION(DM013_ZERO_BUSTER_LADDER, 0x01);
  ct = &z->atkCooltime;
  if (m != expected) {
    GotoMotion(&z->s, expected, 1, *ct);
  }

  *ct = (z->s).motion.duration;
  if ((z->s).motion.duration < 2) {
    GotoMotion(&z->s, expected, 2, 16);
    z->atkCooltime = 16;
    (z->unk_b4).attackMode[1] = 3;
  }
}

// 0x08031170
NAKED static void buster_3(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	movs r0, #0x92\n\
	lsls r0, r0, #1\n\
	adds r2, r4, r0\n\
	ldrb r0, [r2]\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	ldrb r1, [r4, #0x1e]\n\
	lsls r1, r1, #8\n\
	adds r0, r4, #0\n\
	adds r0, #0x70\n\
	ldrb r0, [r0]\n\
	orrs r0, r1\n\
	ldr r1, _080311CC @ =0x00000D01\n\
	cmp r0, r1\n\
	beq _080311A2\n\
	ldr r2, _080311D0 @ =0x00000129\n\
	adds r0, r4, r2\n\
	ldrb r3, [r0]\n\
	adds r0, r4, #0\n\
	movs r2, #2\n\
	bl GotoMotion\n\
_080311A2:\n\
	ldr r0, _080311D0 @ =0x00000129\n\
	adds r1, r4, r0\n\
	ldrb r0, [r1]\n\
	subs r0, #1\n\
	strb r0, [r1]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _0803120C\n\
	adds r0, r4, #0\n\
	adds r0, #0xec\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0\n\
	bne _080311E8\n\
	ldrb r0, [r4, #0xf]\n\
	cmp r0, #2\n\
	bne _080311D8\n\
	ldr r1, _080311D4 @ =0x00000702\n\
	b _080311F0\n\
	.align 2, 0\n\
_080311CC: .4byte 0x00000D01\n\
_080311D0: .4byte 0x00000129\n\
_080311D4: .4byte 0x00000702\n\
_080311D8:\n\
	ldr r1, _080311E4 @ =0x00000701\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	b _0803120C\n\
	.align 2, 0\n\
_080311E4: .4byte 0x00000701\n\
_080311E8:\n\
	ldrb r0, [r4, #0xf]\n\
	cmp r0, #3\n\
	bne _08031200\n\
	ldr r1, _080311FC @ =0x00000705\n\
_080311F0:\n\
	adds r0, r4, #0\n\
	movs r2, #1\n\
	movs r3, #1\n\
	bl GotoMotion\n\
	b _0803120C\n\
	.align 2, 0\n\
_080311FC: .4byte 0x00000705\n\
_08031200:\n\
	ldr r1, _08031238 @ =0x00000704\n\
	adds r0, r4, #0\n\
	movs r2, #4\n\
	movs r3, #1\n\
	bl GotoMotion\n\
_0803120C:\n\
	movs r2, #0x94\n\
	lsls r2, r2, #1\n\
	adds r1, r4, r2\n\
	adds r0, r4, #0\n\
	bl IsAttackOK\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _08031232\n\
	adds r0, r4, #0\n\
	adds r0, #0xec\n\
	movs r2, #0\n\
	movs r1, #3\n\
	strb r1, [r0]\n\
	adds r0, #1\n\
	strb r2, [r0]\n\
	adds r0, r4, #0\n\
	bl zeroLadderAtk\n\
_08031232:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08031238: .4byte 0x00000704\n\
 .syntax divided\n");
}

// --------------------------------------------

static void handle_saber_input(struct Zero* z);
static void ladder_saber(struct Zero* z);
static void charge_saber(struct Zero* z);

static void onSaber(struct Zero* z) {
  static ZeroFunc const seq[] = {
      handle_saber_input,
      ladder_saber,
      charge_saber,
  };

  struct Zero_b4* b4 = &(z->unk_b4);

  if ((z->restriction).b6) {
    (z->unk_b4).attackMode[1] = 2;
  }

  (z->restriction).shield = TRUE;
  (z->restriction).move = TRUE;
  if ((b4->status).mainWeapon == WEAPON_SABER) {
    (z->restriction).mainCharge = TRUE;
  } else {
    (z->restriction).subCharge = TRUE;
  }
  (seq[(z->unk_b4).attackMode[1]])(z);
}

// 0x08031298
WIP static void handle_saber_input(struct Zero* z) {
#if MODERN
  u8 charge;
  struct Zero_b4* b4 = &(z->unk_b4);
  const zero_input_t input = z->zeroInput;

  if (input & DPAD_RIGHT) {
    (z->s).spr.xflip = TRUE;
    (z->s).spr.oam.xflip = TRUE;
    (z->s).flags |= X_FLIP;
  }
  if (input & DPAD_LEFT) {
    (z->s).spr.xflip = FALSE;
    (z->s).spr.oam.xflip = FALSE;
    (z->s).flags &= ~X_FLIP;
  }

  if ((b4->status).mainWeapon == WEAPON_SABER) {
    charge = GetWeaponCharge(z, FALSE);
  } else {
    charge = GetWeaponCharge(z, TRUE);
  }
  if (z->ultimateCommand_22c[1] == 3) {
    bool8 xflip = (z->ultimateCommand_22c[2]) & 1;
    (z->s).spr.xflip = xflip;
    (z->s).spr.oam.xflip = xflip;
    if (xflip) {
      (z->s).flags |= X_FLIP;
    } else {
      (z->s).flags &= ~X_FLIP;
    }
    charge = FULL_CHARGE;
  }

  if (charge == FULL_CHARGE) {
    (z->unk_b4).attackMode[1] = 2;
    (z->unk_b4).attackMode[2] = 0;
    charge_saber(z);
  } else {
    (z->unk_b4).attackMode[1] = 1;
    (z->unk_b4).attackMode[2] = 0;
    ladder_saber(z);
  }
#else
  INCCODE("asm/wip/ladderSaber_08031298.inc");
#endif
}

// 0x803139c
static void ladder_saber(struct Zero* z) {
  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM029_ZERO_SABER_LADDER, 0x00));
    (z->unk_b4).attackMode[2]++;
    return;
  }

  KeepMotion(z, MOTION(DM029_ZERO_SABER_LADDER, 0x00));
  if ((z->unk_b4).attackMode[2] == 1) {
    if ((z->s).motion.duration > 1) {
      return;
    }
    CreateWeaponSaber(z, SABER_LADDER);
    (z->unk_b4).attackMode[2]++;
    return;
  }

  if ((z->s).motion.state == MOTION_END) {
    (z->unk_b4).attackMode[0] = 0;
    if ((z->s).mode[2] == 0) {
      if ((z->s).mode[3] == 2) {
        GotoMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x02), 1, 1);
      } else {
        SetMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x01));
      }
    } else {
      if ((z->s).mode[3] == 3) {
        GotoMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x05), 1, 1);
      } else {
        GotoMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x04), 4, 1);
      }
    }
  }
}

// 0x0803144c
static void charge_saber(struct Zero* z) {
  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM029_ZERO_SABER_LADDER, 0x01));
    CreateWeaponSaber(z, SABER_CHARGE_LADDER);
    (z->unk_b4).attackMode[2]++;
  } else {
    if (z->restriction.b6) {
      GotoMotion(&z->s, MOTION(DM029_ZERO_SABER_LADDER, 0x01), z->motionCmdIdx, z->motionDuration);
    } else {
      KeepMotion(z, MOTION(DM029_ZERO_SABER_LADDER, 0x01));
    }
  }

  if ((z->s).motion.state == MOTION_END) {
    (z->unk_b4).attackMode[0] = 0;

    if ((z->s).mode[2] == 0) {
      if ((z->s).mode[3] == 2) {
        GotoMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x02), 1, 1);
      } else {
        SetMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x01));
      }
    } else {
      if ((z->s).mode[3] == 3) {
        GotoMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x05), 1, 1);
      } else {
        GotoMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x04), 4, 1);
      }
    }

    return;
  }

  z->chargeSaber = 4;
}

// --------------------------------------------

static void handle_rod_input(struct Zero* z);
static void FUN_08031698(struct Zero* z);
static void fail_ladder_rod(struct Zero* z);
static void charge_rod(struct Zero* z);

// TODO: Move into onRod
// clang-format off
static const ZeroFunc rodRoutine[] = {
    handle_rod_input,
    FUN_08031698,
    fail_ladder_rod,
    fail_ladder_rod,
    fail_ladder_rod,
    fail_ladder_rod,
    fail_ladder_rod,
    charge_rod,
    fail_ladder_rod,
    fail_ladder_rod,
    fail_ladder_rod,
};
// clang-format on

// 0x0803152c
NON_MATCH static void onRod(struct Zero* z) {
#if MODERN
  struct Zero_b4* b4 = &(z->unk_b4);

  if ((b4->status).mainWeapon == WEAPON_ROD) {
    (z->restriction).mainCharge = TRUE;
  } else {
    (z->restriction).subCharge = TRUE;
  }
  (z->restriction).move = TRUE;

  (rodRoutine[(z->unk_b4).attackMode[1]])(z);
#else
  INCCODE("asm/wip/onRod_ladder.inc");
#endif
}

// 0x08031578
WIP static void handle_rod_input(struct Zero* z) {
#if MODERN
  u8 charge;
  struct Zero_b4* b4 = &(z->unk_b4);
  const zero_input_t input = z->zeroInput;

  if (input & DPAD_RIGHT) {
    (z->s).spr.xflip = TRUE;
    (z->s).spr.oam.xflip = TRUE;
    (z->s).flags |= X_FLIP;
  }
  if (input & DPAD_LEFT) {
    (z->s).spr.xflip = FALSE;
    (z->s).spr.oam.xflip = FALSE;
    (z->s).flags &= ~X_FLIP;
  }

  if ((b4->status).mainWeapon == WEAPON_ROD) {
    charge = GetWeaponCharge(z, FALSE);
  } else {
    charge = GetWeaponCharge(z, TRUE);
  }

  z->unk_rod_133 = 0;

  if (z->ultimateCommand_224[1] == 3) {
    bool8 xflip = (z->ultimateCommand_224[2]) & 1;
    (z->s).spr.xflip = xflip;
    (z->s).spr.oam.xflip = xflip;
    if (xflip) {
      (z->s).flags |= X_FLIP;
    } else {
      (z->s).flags &= ~X_FLIP;
    }
    charge_rod(z);
    return;
  }

  if (charge == FULL_CHARGE) {
    (z->unk_b4).attackMode[1] = 7;
    (z->unk_b4).attackMode[2] = 0;
    charge_rod(z);
  } else {
    (z->unk_b4).attackMode[1] = 1;
    (z->unk_b4).attackMode[2] = 0;
    FUN_08031698(z);
  }
#else
  INCCODE("asm/wip/handle_rod_input_ladder.inc");
#endif
}

// 0x08031698
NAKED static void FUN_08031698(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	movs r0, #0x93\n\
	lsls r0, r0, #1\n\
	adds r1, r4, r0\n\
	movs r0, #0xa\n\
	strb r0, [r1]\n\
	adds r5, r4, #0\n\
	adds r5, #0xee\n\
	ldrb r0, [r5]\n\
	cmp r0, #0\n\
	bne _080316C8\n\
	movs r1, #0x94\n\
	lsls r1, r1, #6\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r0, r4, #0\n\
	bl CreateWeaponRod\n\
	ldrb r0, [r5]\n\
	adds r0, #1\n\
	strb r0, [r5]\n\
	b _08031796\n\
_080316C8:\n\
	movs r5, #0x94\n\
	lsls r5, r5, #6\n\
	adds r0, r4, #0\n\
	adds r1, r5, #0\n\
	bl KeepMotion\n\
	ldrb r0, [r4, #0x1e]\n\
	lsls r0, r0, #8\n\
	adds r1, r4, #0\n\
	adds r1, #0x70\n\
	ldrb r1, [r1]\n\
	orrs r1, r0\n\
	cmp r1, r5\n\
	beq _080316FA\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #1\n\
	adds r0, r4, r1\n\
	ldrb r2, [r0]\n\
	adds r1, #1\n\
	adds r0, r4, r1\n\
	ldrb r3, [r0]\n\
	adds r0, r4, #0\n\
	adds r1, r5, #0\n\
	bl GotoMotion\n\
_080316FA:\n\
	adds r0, r4, #0\n\
	adds r0, #0x71\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #5\n\
	ble _08031732\n\
	movs r0, #0x94\n\
	lsls r0, r0, #1\n\
	adds r1, r4, r0\n\
	adds r0, r4, #0\n\
	bl IsAttackOK\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _08031732\n\
	adds r0, r4, #0\n\
	adds r0, #0xec\n\
	movs r1, #3\n\
	strb r1, [r0]\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	bl zeroLadderAtk\n\
	b _08031796\n\
_08031732:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _08031796\n\
	adds r0, r4, #0\n\
	adds r0, #0xec\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0\n\
	bne _08031768\n\
	ldrb r0, [r4, #0xf]\n\
	cmp r0, #2\n\
	bne _08031758\n\
	ldr r1, _08031754 @ =0x00000702\n\
	b _08031770\n\
	.align 2, 0\n\
_08031754: .4byte 0x00000702\n\
_08031758:\n\
	ldr r1, _08031764 @ =0x00000701\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	b _0803178C\n\
	.align 2, 0\n\
_08031764: .4byte 0x00000701\n\
_08031768:\n\
	ldrb r0, [r4, #0xf]\n\
	cmp r0, #3\n\
	bne _08031780\n\
	ldr r1, _0803177C @ =0x00000705\n\
_08031770:\n\
	adds r0, r4, #0\n\
	movs r2, #1\n\
	movs r3, #1\n\
	bl GotoMotion\n\
	b _0803178C\n\
	.align 2, 0\n\
_0803177C: .4byte 0x00000705\n\
_08031780:\n\
	ldr r1, _0803179C @ =0x00000704\n\
	adds r0, r4, #0\n\
	movs r2, #4\n\
	movs r3, #1\n\
	bl GotoMotion\n\
_0803178C:\n\
	movs r0, #0x93\n\
	lsls r0, r0, #1\n\
	adds r1, r4, r0\n\
	movs r0, #0xff\n\
	strb r0, [r1]\n\
_08031796:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0803179C: .4byte 0x00000704\n\
   .syntax divided\n");
}

static void fail_ladder_rod(struct Zero* z) {
  (z->unk_b4).attackMode[0] = 0;
  if ((z->s).mode[2] == 0) {
    if ((z->s).mode[3] == 2) {
      GotoMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x02), 1, 1);
    } else {
      SetMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x01));
    }
  } else {
    if ((z->s).mode[3] == 3) {
      GotoMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x05), 1, 1);
    } else {
      GotoMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x04), 4, 1);
    }
  }
}

NAKED static void charge_rod(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	movs r0, #0x93\n\
	lsls r0, r0, #1\n\
	adds r1, r4, r0\n\
	movs r0, #0x12\n\
	strb r0, [r1]\n\
	adds r5, r4, #0\n\
	adds r5, #0xee\n\
	ldrb r0, [r5]\n\
	cmp r0, #0\n\
	bne _0803182C\n\
	movs r1, #0xf8\n\
	lsls r1, r1, #6\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r0, r4, #0\n\
	bl CreateWeaponRod\n\
	ldrb r0, [r5]\n\
	adds r0, #1\n\
	strb r0, [r5]\n\
	b _080318C2\n\
_0803182C:\n\
	movs r5, #0xf8\n\
	lsls r5, r5, #6\n\
	adds r0, r4, #0\n\
	adds r1, r5, #0\n\
	bl KeepMotion\n\
	ldrb r0, [r4, #0x1e]\n\
	lsls r0, r0, #8\n\
	adds r1, r4, #0\n\
	adds r1, #0x70\n\
	ldrb r1, [r1]\n\
	orrs r1, r0\n\
	cmp r1, r5\n\
	beq _0803185E\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #1\n\
	adds r0, r4, r1\n\
	ldrb r2, [r0]\n\
	adds r1, #1\n\
	adds r0, r4, r1\n\
	ldrb r3, [r0]\n\
	adds r0, r4, #0\n\
	adds r1, r5, #0\n\
	bl GotoMotion\n\
_0803185E:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _080318C2\n\
	adds r0, r4, #0\n\
	adds r0, #0xec\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0\n\
	bne _08031894\n\
	ldrb r0, [r4, #0xf]\n\
	cmp r0, #2\n\
	bne _08031884\n\
	ldr r1, _08031880 @ =0x00000702\n\
	b _0803189C\n\
	.align 2, 0\n\
_08031880: .4byte 0x00000702\n\
_08031884:\n\
	ldr r1, _08031890 @ =0x00000701\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	b _080318B8\n\
	.align 2, 0\n\
_08031890: .4byte 0x00000701\n\
_08031894:\n\
	ldrb r0, [r4, #0xf]\n\
	cmp r0, #3\n\
	bne _080318AC\n\
	ldr r1, _080318A8 @ =0x00000705\n\
_0803189C:\n\
	adds r0, r4, #0\n\
	movs r2, #1\n\
	movs r3, #1\n\
	bl GotoMotion\n\
	b _080318B8\n\
	.align 2, 0\n\
_080318A8: .4byte 0x00000705\n\
_080318AC:\n\
	ldr r1, _080318C8 @ =0x00000704\n\
	adds r0, r4, #0\n\
	movs r2, #4\n\
	movs r3, #1\n\
	bl GotoMotion\n\
_080318B8:\n\
	movs r0, #0x93\n\
	lsls r0, r0, #1\n\
	adds r1, r4, r0\n\
	movs r0, #0xff\n\
	strb r0, [r1]\n\
_080318C2:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080318C8: .4byte 0x00000704\n\
 .syntax divided\n");
}

// --------------------------------------------

static void handle_shield_input(struct Zero* z);
static void FUN_08031c94(struct Zero* z);
static void FUN_08031d1c(struct Zero* z);
static void FUN_08031ddc(struct Zero* z);
static void FUN_08031eac(struct Zero* z);
static void FUN_08031f7c(struct Zero* z);

// clang-format off
static const ZeroFunc gZeroShieldLadderRoutine[6] = {
    handle_shield_input,
    FUN_08031c94,
    FUN_08031d1c,
    FUN_08031ddc,
    FUN_08031eac,
    FUN_08031f7c,
};
// clang-format on

// 0x080318cc
NAKED static void onShield(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	adds r1, r4, #0\n\
	adds r1, #0xb4\n\
	ldrb r0, [r1, #0xc]\n\
	cmp r0, #3\n\
	beq _08031938\n\
	ldrb r0, [r1, #0xd]\n\
	cmp r0, #3\n\
	beq _08031938\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0\n\
	bne _08031904\n\
	ldrb r0, [r4, #0xf]\n\
	cmp r0, #2\n\
	bne _080318F4\n\
	ldr r1, _080318F0 @ =0x00000702\n\
	b _0803190C\n\
	.align 2, 0\n\
_080318F0: .4byte 0x00000702\n\
_080318F4:\n\
	ldr r1, _08031900 @ =0x00000701\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	b _08031928\n\
	.align 2, 0\n\
_08031900: .4byte 0x00000701\n\
_08031904:\n\
	ldrb r0, [r4, #0xf]\n\
	cmp r0, #3\n\
	bne _0803191C\n\
	ldr r1, _08031918 @ =0x00000705\n\
_0803190C:\n\
	adds r0, r4, #0\n\
	movs r2, #1\n\
	movs r3, #1\n\
	bl GotoMotion\n\
	b _08031928\n\
	.align 2, 0\n\
_08031918: .4byte 0x00000705\n\
_0803191C:\n\
	ldr r1, _08031934 @ =0x00000704\n\
	adds r0, r4, #0\n\
	movs r2, #4\n\
	movs r3, #1\n\
	bl GotoMotion\n\
_08031928:\n\
	adds r1, r4, #0\n\
	adds r1, #0xec\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	b _080319AE\n\
	.align 2, 0\n\
_08031934: .4byte 0x00000704\n\
_08031938:\n\
	movs r0, #0x92\n\
	lsls r0, r0, #1\n\
	adds r2, r4, r0\n\
	ldrb r0, [r2]\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	movs r0, #0x86\n\
	lsls r0, r0, #2\n\
	adds r3, r4, r0\n\
	ldr r0, [r3]\n\
	movs r1, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08031974\n\
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
_08031974:\n\
	ldr r0, [r3]\n\
	movs r1, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0803199A\n\
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
_0803199A:\n\
	ldr r0, _080319B4 @ =gZeroShieldLadderRoutine\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	ldrb r1, [r1]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	ldr r1, [r1]\n\
	adds r0, r4, #0\n\
	bl _call_via_r1\n\
_080319AE:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080319B4: .4byte gZeroShieldLadderRoutine\n\
   .syntax divided\n");
}

// 0x080319b8
NAKED static void handle_shield_input(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r5, r0, #0\n\
	movs r6, #0\n\
	adds r0, #0xb4\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #3\n\
	bne _08031AA8\n\
	adds r0, r5, #0\n\
	movs r1, #0\n\
	bl GetWeaponCharge\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
	movs r0, #0x86\n\
	lsls r0, r0, #2\n\
	adds r2, r5, r0\n\
	ldr r0, [r2]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #6\n\
	ands r0, r1\n\
	adds r7, r2, #0\n\
	cmp r0, #0\n\
	bne _08031AC8\n\
	ldr r1, _08031A30 @ =0x00000225\n\
	adds r0, r5, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _08031A42\n\
	ldr r0, _08031A34 @ =0x00000226\n\
	adds r4, r5, r0\n\
	ldrb r1, [r4]\n\
	movs r2, #1\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	adds r1, r5, #0\n\
	adds r1, #0x4c\n\
	strb r0, [r1]\n\
	ldrb r0, [r4]\n\
	movs r1, #0x4a\n\
	adds r1, r1, r5\n\
	mov ip, r1\n\
	adds r1, r2, #0\n\
	ands r1, r0\n\
	lsls r1, r1, #4\n\
	mov r0, ip\n\
	ldrb r3, [r0]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r3\n\
	orrs r0, r1\n\
	mov r1, ip\n\
	strb r0, [r1]\n\
	ldrb r0, [r4]\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	beq _08031A38\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _08031A3E\n\
	.align 2, 0\n\
_08031A30: .4byte 0x00000225\n\
_08031A34: .4byte 0x00000226\n\
_08031A38:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_08031A3E:\n\
	strb r0, [r5, #0xa]\n\
	movs r3, #2\n\
_08031A42:\n\
	adds r0, r5, #0\n\
	adds r0, #0xb4\n\
	ldrh r1, [r0, #0x12]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08031A54\n\
	b _08031B98\n\
_08031A54:\n\
	ldr r1, _08031AA0 @ =0x0000022D\n\
	adds r0, r5, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	beq _08031A60\n\
	b _08031B98\n\
_08031A60:\n\
	ldr r0, _08031AA4 @ =0x0000022E\n\
	adds r4, r5, r0\n\
	ldrb r1, [r4]\n\
	movs r2, #1\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	adds r1, r5, #0\n\
	adds r1, #0x4c\n\
	strb r0, [r1]\n\
	ldrb r0, [r4]\n\
	movs r1, #0x4a\n\
	adds r1, r1, r5\n\
	mov ip, r1\n\
	adds r1, r2, #0\n\
	ands r1, r0\n\
	lsls r1, r1, #4\n\
	mov r0, ip\n\
	ldrb r3, [r0]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r3\n\
	orrs r0, r1\n\
	mov r1, ip\n\
	strb r0, [r1]\n\
	ldrb r0, [r4]\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	beq _08031B8C\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _08031B92\n\
	.align 2, 0\n\
_08031AA0: .4byte 0x0000022D\n\
_08031AA4: .4byte 0x0000022E\n\
_08031AA8:\n\
	adds r0, r5, #0\n\
	movs r1, #1\n\
	bl GetWeaponCharge\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
	movs r0, #0x86\n\
	lsls r0, r0, #2\n\
	adds r2, r5, r0\n\
	ldr r0, [r2]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #8\n\
	ands r0, r1\n\
	adds r7, r2, #0\n\
	cmp r0, #0\n\
	beq _08031ACC\n\
_08031AC8:\n\
	movs r3, #0\n\
	b _08031B98\n\
_08031ACC:\n\
	ldr r1, _08031B18 @ =0x00000225\n\
	adds r0, r5, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _08031B2A\n\
	ldr r0, _08031B1C @ =0x00000226\n\
	adds r4, r5, r0\n\
	ldrb r1, [r4]\n\
	movs r2, #1\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	adds r1, r5, #0\n\
	adds r1, #0x4c\n\
	strb r0, [r1]\n\
	ldrb r0, [r4]\n\
	movs r1, #0x4a\n\
	adds r1, r1, r5\n\
	mov ip, r1\n\
	adds r1, r2, #0\n\
	ands r1, r0\n\
	lsls r1, r1, #4\n\
	mov r0, ip\n\
	ldrb r3, [r0]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r3\n\
	orrs r0, r1\n\
	mov r1, ip\n\
	strb r0, [r1]\n\
	ldrb r0, [r4]\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	beq _08031B20\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _08031B26\n\
	.align 2, 0\n\
_08031B18: .4byte 0x00000225\n\
_08031B1C: .4byte 0x00000226\n\
_08031B20:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_08031B26:\n\
	strb r0, [r5, #0xa]\n\
	movs r3, #2\n\
_08031B2A:\n\
	adds r0, r5, #0\n\
	adds r0, #0xb4\n\
	ldrh r1, [r0, #0x12]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08031B98\n\
	ldr r1, _08031B84 @ =0x0000022D\n\
	adds r0, r5, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _08031B98\n\
	ldr r0, _08031B88 @ =0x0000022E\n\
	adds r4, r5, r0\n\
	ldrb r1, [r4]\n\
	movs r2, #1\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	adds r1, r5, #0\n\
	adds r1, #0x4c\n\
	strb r0, [r1]\n\
	ldrb r0, [r4]\n\
	movs r1, #0x4a\n\
	adds r1, r1, r5\n\
	mov ip, r1\n\
	adds r1, r2, #0\n\
	ands r1, r0\n\
	lsls r1, r1, #4\n\
	mov r0, ip\n\
	ldrb r3, [r0]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r3\n\
	orrs r0, r1\n\
	mov r1, ip\n\
	strb r0, [r1]\n\
	ldrb r0, [r4]\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	beq _08031B8C\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _08031B92\n\
	.align 2, 0\n\
_08031B84: .4byte 0x0000022D\n\
_08031B88: .4byte 0x0000022E\n\
_08031B8C:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_08031B92:\n\
	strb r0, [r5, #0xa]\n\
	movs r3, #2\n\
	movs r6, #1\n\
_08031B98:\n\
	cmp r3, #2\n\
	bne _08031C10\n\
	adds r2, r5, #0\n\
	adds r2, #0xb4\n\
	ldrh r1, [r2, #0x12]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08031BD2\n\
	ldr r0, [r7]\n\
	movs r1, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08031BBA\n\
	cmp r6, #0\n\
	beq _08031BD2\n\
_08031BBA:\n\
	adds r2, r5, #0\n\
	adds r2, #0xed\n\
	movs r1, #0\n\
	movs r0, #5\n\
	strb r0, [r2]\n\
	adds r0, r5, #0\n\
	adds r0, #0xee\n\
	strb r1, [r0]\n\
	adds r0, r5, #0\n\
	bl FUN_08031f7c\n\
	b _08031C88\n\
_08031BD2:\n\
	ldrh r1, [r2, #0x12]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #3\n\
	ands r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x1a\n\
	cmp r2, #0\n\
	beq _08031BFA\n\
	adds r2, r5, #0\n\
	adds r2, #0xed\n\
	movs r1, #0\n\
	movs r0, #4\n\
	strb r0, [r2]\n\
	adds r0, r5, #0\n\
	adds r0, #0xee\n\
	strb r1, [r0]\n\
	adds r0, r5, #0\n\
	bl FUN_08031eac\n\
	b _08031C88\n\
_08031BFA:\n\
	adds r1, r5, #0\n\
	adds r1, #0xed\n\
	movs r0, #3\n\
	strb r0, [r1]\n\
	adds r0, r5, #0\n\
	adds r0, #0xee\n\
	strb r2, [r0]\n\
	adds r0, r5, #0\n\
	bl FUN_08031ddc\n\
	b _08031C88\n\
_08031C10:\n\
	adds r0, r5, #0\n\
	movs r1, #0\n\
	bl IsAttackOK\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #2\n\
	bne _08031C38\n\
	adds r2, r5, #0\n\
	adds r2, #0xed\n\
	movs r1, #0\n\
	movs r0, #1\n\
	strb r0, [r2]\n\
	adds r0, r5, #0\n\
	adds r0, #0xee\n\
	strb r1, [r0]\n\
	adds r0, r5, #0\n\
	bl FUN_08031c94\n\
	b _08031C88\n\
_08031C38:\n\
	ldrb r0, [r5, #0xe]\n\
	cmp r0, #0\n\
	bne _08031C5C\n\
	ldrb r0, [r5, #0xf]\n\
	cmp r0, #2\n\
	bne _08031C4C\n\
	ldr r1, _08031C48 @ =0x00000702\n\
	b _08031C64\n\
	.align 2, 0\n\
_08031C48: .4byte 0x00000702\n\
_08031C4C:\n\
	ldr r1, _08031C58 @ =0x00000701\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	b _08031C80\n\
	.align 2, 0\n\
_08031C58: .4byte 0x00000701\n\
_08031C5C:\n\
	ldrb r0, [r5, #0xf]\n\
	cmp r0, #3\n\
	bne _08031C74\n\
	ldr r1, _08031C70 @ =0x00000705\n\
_08031C64:\n\
	adds r0, r5, #0\n\
	movs r2, #1\n\
	movs r3, #1\n\
	bl GotoMotion\n\
	b _08031C80\n\
	.align 2, 0\n\
_08031C70: .4byte 0x00000705\n\
_08031C74:\n\
	ldr r1, _08031C90 @ =0x00000704\n\
	adds r0, r5, #0\n\
	movs r2, #4\n\
	movs r3, #1\n\
	bl GotoMotion\n\
_08031C80:\n\
	adds r1, r5, #0\n\
	adds r1, #0xec\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
_08031C88:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08031C90: .4byte 0x00000704\n\
 .syntax divided\n");
}

static void FUN_08031c94(struct Zero* z) {
  motion_t m;
  bool8 ok;
  z->unk_12e = 4;

  m = MOTION_VALUE(z);
  if (m != MOTION(DM047_ZERO_SHIELD_LADDER, 0x00)) {
    SetMotion(&z->s, MOTION(DM047_ZERO_SHIELD_LADDER, 0x00));
  }

  if ((z->unk_b4).attackMode[2] == 0) {
    CreateWeaponShieldGuard(z, 4);
    (z->unk_b4).attackMode[2]++;
    return;
  }

  ok = IsAttackOK(z, &z->usingWeapon);
  if (ok == TRUE) {
    (z->unk_b4).attackMode[0] = 3;
    (z->unk_b4).attackMode[1] = 0;
    zeroLadderAtk(z);
    return;
  }
  if (ok != 2) {
    (z->unk_b4).attackMode[1] = 2;
    (z->unk_b4).attackMode[2] = 0;
    FUN_08031d1c(z);
  }
}

static void FUN_08031d1c(struct Zero* z) {
  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM047_ZERO_SHIELD_LADDER, 0x02));
    (z->unk_b4).attackMode[2]++;
  }
  z->restriction.shield = TRUE;

  if (IsAttackOK(z, &z->usingWeapon)) {
    (z->unk_b4).attackMode[0] = 3;
    (z->unk_b4).attackMode[1] = 0;
    zeroLadderAtk(z);
    return;
  }

  if ((z->s).motion.state == MOTION_END) {
    if ((z->s).mode[2] == 0) {
      if ((z->s).mode[3] == 2) {
        GotoMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x02), 1, 1);
      } else {
        SetMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x01));
      }
    } else {
      if ((z->s).mode[3] == 3) {
        GotoMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x05), 1, 1);
      } else {
        GotoMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x04), 4, 1);
      }
    }
    (z->unk_b4).attackMode[0] = 0;
  }
}

static void FUN_08031ddc(struct Zero* z) {
  motion_t m;
  z->unk_127 = 3;

  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM048_ZERO_SHIELD_THROW_LADDER, 0x00));
    CreateWeaponShieldFly(z, 0);
    (z->unk_b4).attackMode[2]++;
  }
  KeepMotion(z, MOTION(DM048_ZERO_SHIELD_THROW_LADDER, 0x00));

  m = MOTION_VALUE(z);
  if (m != MOTION(DM048_ZERO_SHIELD_THROW_LADDER, 0x00)) {
    GotoMotion(&z->s, MOTION(DM048_ZERO_SHIELD_THROW_LADDER, 0x00), z->motionCmdIdx, z->motionDuration);
  }

  if ((z->s).motion.state == MOTION_END) {
    z->unk_127 = 0xFF;
    if ((z->s).mode[2] == 0) {
      if ((z->s).mode[3] == 2) {
        GotoMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x02), 1, 1);
      } else {
        SetMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x01));
      }
    } else {
      if ((z->s).mode[3] == 3) {
        GotoMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x05), 1, 1);
      } else {
        GotoMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x04), 4, 1);
      }
    }
    (z->unk_b4).attackMode[0] = 0;
  }
}

static void FUN_08031eac(struct Zero* z) {
  motion_t m;
  z->unk_127 = 3;

  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM048_ZERO_SHIELD_THROW_LADDER, 0x00));
    CreateWeaponShieldFly(z, 1);
    (z->unk_b4).attackMode[2]++;
  }
  KeepMotion(z, MOTION(DM048_ZERO_SHIELD_THROW_LADDER, 0x00));

  m = MOTION_VALUE(z);
  if (m != MOTION(DM048_ZERO_SHIELD_THROW_LADDER, 0x00)) {
    GotoMotion(&z->s, MOTION(DM048_ZERO_SHIELD_THROW_LADDER, 0x00), z->motionCmdIdx, z->motionDuration);
  }

  if ((z->s).motion.state == MOTION_END) {
    z->unk_127 = 0xFF;
    if ((z->s).mode[2] == 0) {
      if ((z->s).mode[3] == 2) {
        GotoMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x02), 1, 1);
      } else {
        SetMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x01));
      }
    } else {
      if ((z->s).mode[3] == 3) {
        GotoMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x05), 1, 1);
      } else {
        GotoMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x04), 4, 1);
      }
    }
    (z->unk_b4).attackMode[0] = 0;
  }
}

static void FUN_08031f7c(struct Zero* z) {
  motion_t m;
  z->unk_127 = 3;

  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM048_ZERO_SHIELD_THROW_LADDER, 0x00));
    CreateWeaponShieldFly(z, 2);
    (z->unk_b4).attackMode[2]++;
  }
  KeepMotion(z, MOTION(DM048_ZERO_SHIELD_THROW_LADDER, 0x00));

  m = MOTION_VALUE(z);
  if (m != MOTION(DM048_ZERO_SHIELD_THROW_LADDER, 0x00)) {
    GotoMotion(&z->s, MOTION(DM048_ZERO_SHIELD_THROW_LADDER, 0x00), z->motionCmdIdx, z->motionDuration);
  }

  if ((z->s).motion.state == MOTION_END) {
    z->unk_127 = 0xFF;
    if ((z->s).mode[2] == 0) {
      if ((z->s).mode[3] == 2) {
        GotoMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x02), 1, 1);
      } else {
        SetMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x01));
      }
    } else {
      if ((z->s).mode[3] == 3) {
        GotoMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x05), 1, 1);
      } else {
        GotoMotion(&z->s, MOTION(DM007_ZERO_LADDER, 0x04), 4, 1);
      }
    }
    (z->unk_b4).attackMode[0] = 0;
  }
}
