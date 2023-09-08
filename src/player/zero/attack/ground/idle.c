#include "global.h"
#include "motion.h"
#include "overworld.h"
#include "sound.h"
#include "weapon.h"
#include "zero.h"

static void zeroTryAttack(struct Zero* z);
static void _zeroTryAttack(struct Zero* z);
static void nop_0802d094(struct Zero* z);

static void onBuster(struct Zero* z);

void ZeroAttackGround_Idle(struct Zero* z) {
  static ZeroFunc const gZeroAttackRoutine[] = {
      zeroTryAttack,
      _zeroTryAttack,
      nop_0802d094,
      zeroAttack,
  };
  (gZeroAttackRoutine[(z->unk_b4).attackMode[0]])(z);
}

static void zeroTryAttack(struct Zero* z) {
  (z->unk_b4).attackMode[0] = 1;
  _zeroTryAttack(z);
}

WIP static void _zeroTryAttack(struct Zero* z) {
#if MODERN
  bool8 ok = IsAttackOK(z, &z->usingWeapon);
  if (ok) {
    z->forceWeapon = 0xFF;
  } else {
    if (z->forceWeapon == 0xFF) {
      return;
    }
    z->usingWeapon = z->forceWeapon;
  }
  (z->unk_b4).attackMode[0] = 3;
  (z->unk_b4).attackMode[1] = 0;
  zeroAttack(z);
#else
  INCCODE("asm/wip/TryAttackGroundIdle.inc");
#endif
}

static void nop_0802d094(struct Zero* z) { return; };

void zeroAttack(struct Zero* z) {
  static ZeroFunc const gZeroWeaponRoutine[] = {
      onBuster,
      onSaber_GroundIdle,
      recoilAttack,
      shieldAttack,
  };
  (gZeroWeaponRoutine[z->usingWeapon])(z);
  return;
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void buster_0(struct Zero* z);
static void buster_1(struct Zero* z);
static void buster_2(struct Zero* z);
static void buster_3(struct Zero* z);

// 0x0802d0b8
static void onBuster(struct Zero* z) {
  static ZeroFunc const seq[] = {
      buster_0,
      buster_1,
      buster_2,
      buster_3,
  };
  (seq[(z->unk_b4).attackMode[1]])(z);
  return;
}

static void buster_0(struct Zero* z) {
  struct Weapon* w = CreateBuster(z, -PIXEL(30), -PIXEL(21), ((z->s).flags >> 4) & 1);
  if (w == NULL) {
    (z->unk_b4).attackMode[0] = 0;
  } else {
    if ((z->unk_b4).prevMode == 1) {
      SetMotion(&z->s, MOTION(DM011_ZERO_BUSTER_AIR, 0x03));
      z->atkCooltime = 2;
    } else {
      SetMotion(&z->s, MOTION(DM008_ZERO_BUSTER, 0x01));
    }

    (z->unk_b4).attackMode[1] = 1;
    buster_1(z);
  }
}

static void buster_1(struct Zero* z) {
  motion_t m;
  struct Zero_b4* b4 = &(z->unk_b4);

  if ((b4->status).mainWeapon == WEAPON_BUSTER) {
    (z->restriction).mainCharge = TRUE;
  } else {
    (z->restriction).subCharge = TRUE;
  }

  m = MOTION_VALUE(z);
  if (m == MOTION(DM011_ZERO_BUSTER_AIR, 0x03)) {
    z->atkCooltime--;

    if (z->atkCooltime == 0xFF) {
      (z->unk_b4).attackMode[1] = 2;
      z->atkCooltime = 4;
      GotoMotion(&z->s, MOTION(DM008_ZERO_BUSTER, 0x01), 1, 4);
    }
  } else {
    motion_t busterMotion = MOTION(DM008_ZERO_BUSTER, 0x01);
    u8* ct = &z->atkCooltime;
    if (m != busterMotion) {
      GotoMotion(&z->s, MOTION(DM008_ZERO_BUSTER, 0x01), 0, *ct);
    }

    z->atkCooltime = (z->s).motion.duration;
    if ((z->s).motion.duration < 2) {
      GotoMotion(&z->s, MOTION(DM008_ZERO_BUSTER, 0x01), 1, 4);
      (z->unk_b4).attackMode[1] = 2;
    }
  }
}

static void buster_2(struct Zero* z) {
  motion_t m;
  struct Zero_b4* b4 = &(z->unk_b4);

  if ((b4->status).mainWeapon == WEAPON_BUSTER) {
    (z->restriction).mainCharge = TRUE;
  } else {
    (z->restriction).subCharge = TRUE;
  }

  m = MOTION_VALUE(z);
  if (m == MOTION(DM011_ZERO_BUSTER_AIR, 0x04)) {
    z->atkCooltime--;

    if (z->atkCooltime == 0xFF) {
      (z->unk_b4).attackMode[1] = 3;
      z->atkCooltime = 16;
      GotoMotion(&z->s, MOTION(DM008_ZERO_BUSTER, 0x01), 2, 16);
    }
  } else {
    if (m != MOTION(DM008_ZERO_BUSTER, 0x01)) {
      if ((z->unk_b4).prevMode == 1) {
        SetMotion(&z->s, MOTION(DM011_ZERO_BUSTER_AIR, 0x04));
        return;
      }
      GotoMotion(&z->s, MOTION(DM008_ZERO_BUSTER, 0x01), 1, z->atkCooltime);
    }

    z->atkCooltime = (z->s).motion.duration;
    if ((z->s).motion.duration < 2) {
      GotoMotion(&z->s, MOTION(DM008_ZERO_BUSTER, 0x01), 2, 16);
      z->atkCooltime = 16;
      (z->unk_b4).attackMode[1] = 3;
    }
  }
}

static void buster_3(struct Zero* z) {
  bool8 ok;

  motion_t m = MOTION_VALUE(z);
  if (m != MOTION(DM008_ZERO_BUSTER, 0x01)) {
    if ((z->unk_b4).prevMode == 1) {
      SetMotion(&z->s, MOTION(DM011_ZERO_BUSTER_AIR, 0x04));
    } else {
      GotoMotion(&z->s, MOTION(DM008_ZERO_BUSTER, 0x01), 2, z->atkCooltime);
    }
  }

  z->atkCooltime--;
  if (z->atkCooltime == 0xFF) {
    (z->unk_b4).attackMode[0] = 0;
    SetMotion(&z->s, GetDefaultMotion(z));
  }

  ok = IsAttackOK(z, &z->usingWeapon);
  if (ok) {
    (z->unk_b4).attackMode[0] = 3;
    (z->unk_b4).attackMode[1] = 0;
    zeroAttack(z);
  }
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void handle_saber_input(struct Zero* z);
static void triple_slash_1st(struct Zero* z);
static void triple_slash_2nd(struct Zero* z);
static void triple_slash_3rd(struct Zero* z);
static void slash_up(struct Zero* z);
static void throw_blade(struct Zero* z);
static void split_heavens(struct Zero* z);
static void saber_8(struct Zero* z);

// 0x0802d374
void onSaber_GroundIdle(struct Zero* z) {
  // clang-format off
  static ZeroFunc const gZeroSaberRoutine[] = {
      handle_saber_input,
			triple_slash_1st,
			triple_slash_2nd,
			triple_slash_3rd,
			charge_saber_ground,
			slash_up,
			throw_blade,
			split_heavens,
			saber_8,
  };
  // clang-format on

  struct Zero_b4* b4 = &(z->unk_b4);

  if ((z->restriction).b6) {
    (z->unk_b4).attackMode[1] = 4;
  }

  (z->restriction).move = TRUE;
  (z->restriction).shield = TRUE;
  if ((b4->status).mainWeapon == WEAPON_SABER) {
    (z->restriction).mainCharge = TRUE;
  } else {
    (z->restriction).subCharge = TRUE;
  }
  (gZeroSaberRoutine[(z->unk_b4).attackMode[1]])(z);
}

// 0x0802d3d0
WIP static void handle_saber_input(struct Zero* z) {
#if MODERN
  u8 charge;
  struct Zero_b4* b4 = &(z->unk_b4);

  z->tripleSlashCounter = 0;

  if ((b4->status).mainWeapon == WEAPON_SABER) {
    charge = GetWeaponCharge(z, FALSE);
  } else {
    charge = GetWeaponCharge(z, TRUE);
  }

  if (z->ultimateCommand_22c[1] == 3) {
    charge = FULL_CHARGE;
  }

  if (charge == FULL_CHARGE) {
    (z->unk_b4).attackMode[1] = 4;
    (z->unk_b4).attackMode[2] = 0;
    charge_saber_ground(z);
    return;
  }

  if (((b4->status).exSkill & (1 << EXSKILL_ID_SPLIT)) && (z->zeroInput & DPAD_UP)) {
    (z->unk_b4).attackMode[1] = 7;
    (z->unk_b4).attackMode[2] = 0;
    split_heavens(z);
    return;
  }

  if (((b4->status).exSkill & (1 << EXSKILL_ID_THROW)) && (z->zeroInput & DPAD_DOWN)) {
    (z->unk_b4).attackMode[1] = 6;
    (z->unk_b4).attackMode[2] = 0;
    throw_blade(z);
    return;
  }

  (z->unk_b4).attackMode[1] = 1;
  (z->unk_b4).attackMode[2] = 0;
  triple_slash_1st(z);
#else
  INCCODE("asm/wip/handle_saber_input_idle.inc");
#endif
}

// 0x0802d4a8
static void triple_slash_1st(struct Zero* z) {
  weapon_t w[4];
  struct Zero_b4* b4;

  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM014_ZERO_SABER_TRIPLE1, 0x00));
    z->tripleSlashCounter = 0;
    (z->unk_b4).attackMode[2]++;
  } else {
    if (((z->unk_b4).attackMode[2] == 1) && ((z->s).motion.duration < 2)) {
      CreateWeaponSaber(z, 0);
      (z->unk_b4).attackMode[2]++;
    }
    if ((z->unk_b4).attackMode[2] > 1) {
      (z->restriction).move = TRUE;
    }
    if ((IsAttackOK(z, w)) && (w[0] == WEAPON_SABER)) {
      z->tripleSlashCounter++;
    }
    KeepMotion(z, MOTION(DM014_ZERO_SABER_TRIPLE1, 0x00));
  }

  b4 = &(z->unk_b4);
  if ((((b4->status).menuZeroColor != 1) && ((z->s).motion.cmdIdx >= 4)) && (z->tripleSlashCounter > 0)) {
    (z->unk_b4).attackMode[1] = 2;
    (z->unk_b4).attackMode[2] = 0;
    triple_slash_2nd(z);
    return;
  }

  if ((z->s).motion.state == MOTION_END) {
    (z->unk_b4).attackMode[0] = 0;
    SetMotion(&z->s, GetDefaultMotion(z));
  }
}

// 0x0802d59c
WIP static void triple_slash_2nd(struct Zero* z) {
#if MODERN
  weapon_t w[4];

  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM015_ZERO_SABER_TRIPLE2, 0x00));
    CreateWeaponSaber(z, SABER_TRIPLE_2);
    (z->unk_b4).attackMode[2]++;
  } else {
    if (IsAttackOK(z, w) && (w[0] == WEAPON_SABER)) {
      z->tripleSlashCounter++;
    }
    KeepMotion(z, MOTION(DM015_ZERO_SABER_TRIPLE2, 0x00));
  }

  if (((z->s).motion.cmdIdx >= 4) && (z->tripleSlashCounter > 1)) {
    zero_input_t* input = &z->zeroInput;
    if ((*input & DPAD_UP) && isElfUsed_2(z, ELF_LIZETUS)) {
      (z->unk_b4).attackMode[1] = 5;
      (z->unk_b4).attackMode[2] = 0;
      slash_up(z);

    } else if ((*input & DPAD_DOWN) && isElfUsed_2(z, ELF_COTTUS)) {
      (z->unk_b4).attackMode[1] = 6;
      (z->unk_b4).attackMode[2] = 0;
      throw_blade(z);

    } else {
      (z->unk_b4).attackMode[1] = 3;
      (z->unk_b4).attackMode[2] = 0;
      triple_slash_3rd(z);
    }
  }

  if ((z->s).motion.state == MOTION_END) {
    (z->unk_b4).attackMode[0] = 0;
    SetMotion(&z->s, GetDefaultMotion(z));
  }
#else
  INCCODE("asm/wip/idle_saber_2.inc");
#endif
}

// 0x0802d6b4
static void triple_slash_3rd(struct Zero* z) {
  weapon_t w[4];

  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM016_ZERO_SABER_TRIPLE3, 0x00));
    CreateWeaponSaber(z, SABER_TRIPLE_3);
    (z->unk_b4).attackMode[2]++;
  } else {
    if (IsAttackOK(z, w) && (w[0] == WEAPON_SABER)) {
      z->tripleSlashCounter++;
    }
    KeepMotion(z, MOTION(DM016_ZERO_SABER_TRIPLE3, 0x00));
  }

  if ((z->s).motion.cmdIdx >= 6) {
    struct Zero_b4* b4 = &z->unk_b4;
    if (z->tripleSlashCounter >= 2) {
      if ((z->zeroInput & DPAD_UP) && ((b4->status).exSkill & (1 << EXSKILL_ID_SPLIT))) {
        if (((b4->status).head == HEAD_CHIP_NONE) && ((b4->status).body == BODY_CHIP_LIGHT) && ((b4->status).foot == FOOT_CHIP_QUICK)) {
          (z->s).mode[1] = ZERO_AIR;
          (z->s).mode[2] = 0;
          (z->s).mode[3] = 4;
          (z->unk_b4).attackMode[1] = 5;
          (z->unk_b4).attackMode[2] = 0;
          return;
        }
      }
    }
  }
  if ((z->s).motion.state == MOTION_END) {
    (z->unk_b4).attackMode[0] = 0;
    SetMotion(&z->s, GetDefaultMotion(z));
  }
}

void charge_saber_ground(struct Zero* z) {
  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM020_ZERO_SABER_CHARGE, 0x00));
    CreateWeaponSaber(z, SABER_CHARGE);
    (z->unk_b4).attackMode[2]++;

  } else {
    if ((z->restriction).b6) {
      GotoMotion(&z->s, MOTION(DM020_ZERO_SABER_CHARGE, 0x00), z->motionCmdIdx, z->motionDuration);
    } else {
      KeepMotion(z, MOTION(DM020_ZERO_SABER_CHARGE, 0x00));
    }
  }

  if ((z->s).motion.state == MOTION_END) {
    (z->unk_b4).attackMode[0] = 0;
    SetMotion(&z->s, GetDefaultMotion(z));
    return;
  }

  z->chargeSaber = 1;
}

NAKED static void slash_up(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	adds r5, r4, #0\n\
	adds r5, #0xee\n\
	ldrb r0, [r5]\n\
	cmp r0, #0\n\
	bne _0802D84E\n\
	movs r1, #0x88\n\
	lsls r1, r1, #5\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	b _0802D874\n\
_0802D84E:\n\
	movs r1, #0x88\n\
	lsls r1, r1, #5\n\
	adds r0, r4, #0\n\
	bl KeepMotion\n\
	ldrb r0, [r5]\n\
	cmp r0, #1\n\
	bne _0802D87A\n\
	adds r0, r4, #0\n\
	adds r0, #0x72\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bgt _0802D87A\n\
	adds r0, r4, #0\n\
	movs r1, #0xc\n\
	bl CreateWeaponSaber\n\
_0802D874:\n\
	ldrb r0, [r5]\n\
	adds r0, #1\n\
	strb r0, [r5]\n\
_0802D87A:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0802D89E\n\
	adds r1, r4, #0\n\
	adds r1, #0xec\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	bl GetDefaultMotion\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
_0802D89E:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

NAKED static void throw_blade(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	adds r5, r4, #0\n\
	adds r5, #0xee\n\
	ldrb r0, [r5]\n\
	cmp r0, #0\n\
	bne _0802D8BE\n\
	movs r1, #0x98\n\
	lsls r1, r1, #5\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	b _0802D8E4\n\
_0802D8BE:\n\
	movs r1, #0x98\n\
	lsls r1, r1, #5\n\
	adds r0, r4, #0\n\
	bl KeepMotion\n\
	ldrb r0, [r5]\n\
	cmp r0, #1\n\
	bne _0802D8EA\n\
	adds r0, r4, #0\n\
	adds r0, #0x72\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bgt _0802D8EA\n\
	adds r0, r4, #0\n\
	movs r1, #0xd\n\
	bl CreateWeaponSaber\n\
_0802D8E4:\n\
	ldrb r0, [r5]\n\
	adds r0, #1\n\
	strb r0, [r5]\n\
_0802D8EA:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0802D90E\n\
	adds r1, r4, #0\n\
	adds r1, #0xec\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	bl GetDefaultMotion\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
_0802D90E:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void split_heavens(struct Zero* z) {
  struct Zero_b4* b4 = &(z->unk_b4);

  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM018_ZERO_SABER_TENRETSUJIN, 0x00));
    (z->unk_b4).attackMode[2]++;

  } else {
    KeepMotion(z, MOTION(DM018_ZERO_SABER_TENRETSUJIN, 0x00));
    if (((z->unk_b4).attackMode[2] == 1) && ((z->s).motion.duration < 2)) {
      if ((b4->status).element == ELEMENT_FLAME) {
        CreateWeaponSaber(z, SABER_TENRETUJIN_FIRE);
      } else {
        CreateWeaponSaber(z, SABER_TENRETUJIN);
      }
      (z->unk_b4).attackMode[2]++;
    }
  }

  if ((z->s).motion.state == MOTION_END) {
    (z->s).mode[1] = ZERO_AIR;
    (z->s).mode[2] = 0;
    (z->s).mode[3] = 4;
    (z->unk_b4).attackMode[1] = 5;
    (z->unk_b4).attackMode[2] = 0;
  }
}

static void saber_8(struct Zero* z) {
  motion_t m;
  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM027_ZERO_SABER_SMASH, 0x01));
    (z->unk_b4).attackMode[2]++;
  }

  KeepMotion(z, MOTION(DM027_ZERO_SABER_SMASH, 0x01));
  m = MOTION_VALUE(z);
  if (m != MOTION(DM027_ZERO_SABER_SMASH, 0x01)) {
    GotoMotion(&z->s, MOTION(DM027_ZERO_SABER_SMASH, 0x01), z->motionCmdIdx, z->motionDuration);
  }

  if ((z->s).motion.state == MOTION_END) {
    (z->unk_b4).attackMode[0] = 0;
    SetMotion(&z->s, GetDefaultMotion(z));
  }
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void handle_rod_input(struct Zero* z);
static void rod_horizontal0(struct Zero* z);
static void rod_horizontal1(struct Zero* z);
static void rod_up0(struct Zero* z);
static void rod_up1(struct Zero* z);
static void rod_down0(struct Zero* z);
static void rod_down1(struct Zero* z);
static void rod_charge_down(struct Zero* z);
static void rod_charge_up(struct Zero* z);
static void rod_charge_horizontal(struct Zero* z);
static void nop_0802dd84(struct Zero* _);
static void rod_1000slash(struct Zero* z);

void FUN_080322dc(struct Zero* z, motion_t m, u8 r2);
void FUN_080325e8(struct Zero* z, motion_t m);

void recoilAttack(struct Zero* z) {
  // clang-format off
  static ZeroFunc const routine[] = {
      handle_rod_input,
      rod_horizontal0,
      rod_horizontal1,
      rod_up0,
      rod_up1,
      rod_down0,
      rod_down1,
      rod_charge_down,
      rod_charge_up,
      rod_charge_horizontal,
      nop_0802dd84,
      rod_1000slash,
  };
  // clang-format on

  struct Zero_b4* b4 = &(z->unk_b4);

  (z->restriction).move = TRUE;
  if ((b4->status).mainWeapon == WEAPON_ROD) {
    (z->restriction).mainCharge = TRUE;
  } else {
    (z->restriction).subCharge = TRUE;
  }
  (routine[(z->unk_b4).attackMode[1]])(z);
}

NAKED static void handle_rod_input(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	adds r0, #0xb4\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #2\n\
	bne _0802DA76\n\
	adds r0, r4, #0\n\
	movs r1, #0\n\
	b _0802DA7A\n\
_0802DA76:\n\
	adds r0, r4, #0\n\
	movs r1, #1\n\
_0802DA7A:\n\
	bl GetWeaponCharge\n\
	lsls r0, r0, #0x18\n\
	lsrs r1, r0, #0x18\n\
	ldr r2, _0802DAA4 @ =0x00000133\n\
	adds r0, r4, r2\n\
	movs r2, #0\n\
	strb r2, [r0]\n\
	ldr r3, _0802DAA8 @ =0x00000225\n\
	adds r0, r4, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0802DAAC\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #7\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r2, [r0]\n\
	b _0802DB54\n\
	.align 2, 0\n\
_0802DAA4: .4byte 0x00000133\n\
_0802DAA8: .4byte 0x00000225\n\
_0802DAAC:\n\
	ldr r3, _0802DAC8 @ =0x0000022B\n\
	adds r0, r4, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0802DACC\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #8\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r2, [r0]\n\
	b _0802DB1E\n\
	.align 2, 0\n\
_0802DAC8: .4byte 0x0000022B\n\
_0802DACC:\n\
	ldr r3, _0802DAF8 @ =0x0000022D\n\
	adds r0, r4, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0802DAFC\n\
	adds r0, r4, #0\n\
	bl CalcDx\n\
	movs r2, #0x9c\n\
	lsls r2, r2, #1\n\
	adds r1, r4, r2\n\
	movs r2, #0\n\
	strh r0, [r1]\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #9\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r2, [r0]\n\
	b _0802DB44\n\
	.align 2, 0\n\
_0802DAF8: .4byte 0x0000022D\n\
_0802DAFC:\n\
	cmp r1, #2\n\
	bne _0802DB5C\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r2, [r0]\n\
	movs r3, #0x86\n\
	lsls r3, r3, #2\n\
	adds r0, r4, r3\n\
	ldr r1, [r0]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802DB26\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #8\n\
	strb r0, [r1]\n\
_0802DB1E:\n\
	adds r0, r4, #0\n\
	bl rod_charge_up\n\
	b _0802DC1A\n\
_0802DB26:\n\
	movs r0, #0x80\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _0802DB4C\n\
	adds r0, r4, #0\n\
	bl CalcDx\n\
	movs r2, #0x9c\n\
	lsls r2, r2, #1\n\
	adds r1, r4, r2\n\
	strh r0, [r1]\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #9\n\
	strb r0, [r1]\n\
_0802DB44:\n\
	adds r0, r4, #0\n\
	bl rod_charge_horizontal\n\
	b _0802DC1A\n\
_0802DB4C:\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #7\n\
	strb r0, [r1]\n\
_0802DB54:\n\
	adds r0, r4, #0\n\
	bl rod_charge_down\n\
	b _0802DC1A\n\
_0802DB5C:\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r2, [r0]\n\
	adds r0, r4, #0\n\
	bl Is1000Slash\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _0802DB7E\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #0xb\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	bl rod_1000slash\n\
	b _0802DC1A\n\
_0802DB7E:\n\
	ldr r3, _0802DBA8 @ =0x0000013B\n\
	adds r0, r4, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0802DBD4\n\
	movs r1, #0x86\n\
	lsls r1, r1, #2\n\
	adds r0, r4, r1\n\
	ldr r1, [r0]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802DBAC\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #4\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	bl rod_up1\n\
	b _0802DC1A\n\
	.align 2, 0\n\
_0802DBA8: .4byte 0x0000013B\n\
_0802DBAC:\n\
	movs r0, #0x80\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _0802DBC4\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #6\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	bl rod_down1\n\
	b _0802DC1A\n\
_0802DBC4:\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #2\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	bl rod_horizontal1\n\
	b _0802DC1A\n\
_0802DBD4:\n\
	movs r2, #0x86\n\
	lsls r2, r2, #2\n\
	adds r0, r4, r2\n\
	ldr r1, [r0]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802DBF4\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #3\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	bl rod_up0\n\
	b _0802DC1A\n\
_0802DBF4:\n\
	movs r0, #0x80\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _0802DC0C\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #5\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	bl rod_down0\n\
	b _0802DC1A\n\
_0802DC0C:\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	bl rod_horizontal0\n\
_0802DC1A:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void rod_horizontal0(struct Zero* z) {
  if (z->rodToggle != 0) {
    (z->unk_b4).attackMode[1] = 2;
    rod_horizontal1(z);
    return;
  }
  z->rodID = 0;
  FUN_080322dc(z, MOTION(DM030_ZERO_ROD, 0x00), 0);
}

static void rod_horizontal1(struct Zero* z) {
  z->rodID = 1;
  FUN_080322dc(z, MOTION(DM030_ZERO_ROD, 0x01), 1);
}

static void rod_up0(struct Zero* z) {
  if (z->rodToggle != 0) {
    (z->unk_b4).attackMode[1] = 4;
    rod_up1(z);
    return;
  }
  z->rodID = 2;
  FUN_080322dc(z, MOTION(DM031_ZERO_ROD_UP, 0x00), 0);
}

static void rod_up1(struct Zero* z) {
  z->rodID = 3;
  FUN_080322dc(z, MOTION(DM031_ZERO_ROD_UP, 0x01), 1);
}

static void rod_down0(struct Zero* z) {
  z->rodID = 4;
  FUN_080322dc(z, MOTION(DM032_ZERO_ROD_DOWN, 0x00), 0);
}

static void rod_down1(struct Zero* z) {
  z->rodID = 5;
  FUN_080322dc(z, MOTION(DM032_ZERO_ROD_DOWN, 0x01), 1);
}

static void rod_charge_down(struct Zero* z) {
  z->rodID = 11;
  FUN_080325e8(z, MOTION(DM055_ZERO_ROD_CHARGE, 0x00));
}

static void rod_charge_up(struct Zero* z) {
  z->rodID = 12;
  FUN_080325e8(z, MOTION(DM056_ZERO_ROD_CHARGE_UP, 0x00));
}

static void rod_charge_horizontal(struct Zero* z) {
  z->rodID = 13;
  FUN_080325e8(z, MOTION(DM057_ZERO_ROD_CHARGE_DOWN, 0x00));
  if (z->unk_135 != 0) {
    (z->s).mode[1] = 1;
    (z->s).mode[2] = 0;
    (z->s).mode[3] = 3;
    (z->unk_b4).attackMode[1] = 10;
    (z->unk_b4).attackMode[2] = 0;
  }
}

static void nop_0802dd84(struct Zero* _ UNUSED) { return; }

NAKED static void rod_1000slash(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #4\n\
	adds r4, r0, #0\n\
	movs r0, #0x93\n\
	lsls r0, r0, #1\n\
	adds r1, r4, r0\n\
	movs r7, #0\n\
	movs r0, #0x15\n\
	strb r0, [r1]\n\
	movs r1, #0x92\n\
	lsls r1, r1, #1\n\
	adds r2, r4, r1\n\
	ldrb r0, [r2]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	adds r6, r4, #0\n\
	adds r6, #0xee\n\
	ldrb r0, [r6]\n\
	cmp r0, #0\n\
	bne _0802DDD8\n\
	ldr r1, _0802DDD0 @ =0x00001E02\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldr r1, _0802DDD4 @ =0x00000133\n\
	adds r0, r4, r1\n\
	strb r7, [r0]\n\
	adds r0, r4, #0\n\
	bl CreateWeaponRod\n\
	ldrb r0, [r6]\n\
	adds r0, #1\n\
	strb r0, [r6]\n\
	b _0802DE70\n\
	.align 2, 0\n\
_0802DDD0: .4byte 0x00001E02\n\
_0802DDD4: .4byte 0x00000133\n\
_0802DDD8:\n\
	ldr r5, _0802DE24 @ =0x00001E02\n\
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
	beq _0802DE08\n\
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
_0802DE08:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0802DE50\n\
	ldr r1, _0802DE28 @ =0x00000133\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0802DE2C\n\
	cmp r0, #2\n\
	bls _0802DE2C\n\
	strb r7, [r6]\n\
	b _0802DE70\n\
	.align 2, 0\n\
_0802DE24: .4byte 0x00001E02\n\
_0802DE28: .4byte 0x00000133\n\
_0802DE2C:\n\
	adds r1, r4, #0\n\
	adds r1, #0xec\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	bl GetDefaultMotion\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	movs r0, #0x93\n\
	lsls r0, r0, #1\n\
	adds r1, r4, r0\n\
	movs r0, #0xff\n\
	b _0802DE6E\n\
_0802DE50:\n\
	adds r0, r4, #0\n\
	mov r1, sp\n\
	bl IsAttackOK\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _0802DE70\n\
	mov r0, sp\n\
	ldrb r0, [r0]\n\
	cmp r0, #2\n\
	bne _0802DE70\n\
	ldr r0, _0802DE78 @ =0x00000133\n\
	adds r1, r4, r0\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
_0802DE6E:\n\
	strb r0, [r1]\n\
_0802DE70:\n\
	add sp, #4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0802DE78: .4byte 0x00000133\n\
 .syntax divided\n");
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void shield_0(struct Zero* z);
static void shield_1(struct Zero* z);
static void shield_2(struct Zero* z);

void shieldAttack(struct Zero* z) {
  // clang-format off
  static ZeroFunc const gZeroShieldRoutine[] = {
      shield_0,
      shield_1,
      shield_2,
      shield_throw,
      shield_0802e1c8,
      zero_shield_0802e268,
  };
  // clang-format on
  struct Zero_b4* b4 = &(z->unk_b4);

  if (((b4->status).mainWeapon != WEAPON_SHIELD) && ((b4->status).subWeapon != WEAPON_SHIELD)) {
    (z->unk_b4).attackMode[0] = 0;
    SetMotion(&z->s, GetDefaultMotion(z));
    return;
  }

  (z->restriction).dash = TRUE;
  (gZeroShieldRoutine[(z->unk_b4).attackMode[1]])(z);
}

NAKED static void shield_0(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	movs r7, #0\n\
	adds r5, r4, #0\n\
	adds r5, #0xb4\n\
	ldrb r0, [r5, #0xc]\n\
	cmp r0, #3\n\
	bne _0802DF0A\n\
	adds r0, r4, #0\n\
	movs r1, #0\n\
	bl GetWeaponCharge\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
	movs r0, #0x86\n\
	lsls r0, r0, #2\n\
	adds r2, r4, r0\n\
	ldr r0, [r2]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #6\n\
	ands r0, r1\n\
	adds r6, r2, #0\n\
	cmp r0, #0\n\
	bne _0802DF2A\n\
	b _0802DF2E\n\
_0802DF0A:\n\
	adds r0, r4, #0\n\
	movs r1, #1\n\
	bl GetWeaponCharge\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
	movs r0, #0x86\n\
	lsls r0, r0, #2\n\
	adds r2, r4, r0\n\
	ldr r0, [r2]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #8\n\
	ands r0, r1\n\
	adds r6, r2, #0\n\
	cmp r0, #0\n\
	beq _0802DF2E\n\
_0802DF2A:\n\
	movs r3, #0\n\
	b _0802DF54\n\
_0802DF2E:\n\
	ldr r1, _0802DF90 @ =0x00000225\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0802DF3A\n\
	movs r3, #2\n\
_0802DF3A:\n\
	ldrh r1, [r5, #0x12]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802DF54\n\
	ldr r1, _0802DF94 @ =0x0000022D\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0802DF54\n\
	movs r3, #2\n\
	movs r7, #1\n\
_0802DF54:\n\
	cmp r3, #2\n\
	bne _0802DFD6\n\
	adds r2, r4, #0\n\
	adds r2, #0xb4\n\
	ldrh r1, [r2, #0x12]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802DF98\n\
	ldr r0, [r6]\n\
	movs r1, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0802DF76\n\
	cmp r7, #0\n\
	beq _0802DF98\n\
_0802DF76:\n\
	adds r2, r4, #0\n\
	adds r2, #0xed\n\
	movs r1, #0\n\
	movs r0, #5\n\
	strb r0, [r2]\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r1, [r0]\n\
	adds r0, r4, #0\n\
	bl zero_shield_0802e268\n\
	b _0802E018\n\
	.align 2, 0\n\
_0802DF90: .4byte 0x00000225\n\
_0802DF94: .4byte 0x0000022D\n\
_0802DF98:\n\
	ldrh r1, [r2, #0x12]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #3\n\
	ands r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x1a\n\
	cmp r2, #0\n\
	beq _0802DFC0\n\
	adds r2, r4, #0\n\
	adds r2, #0xed\n\
	movs r1, #0\n\
	movs r0, #4\n\
	strb r0, [r2]\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r1, [r0]\n\
	adds r0, r4, #0\n\
	bl shield_0802e1c8\n\
	b _0802E018\n\
_0802DFC0:\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #3\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r2, [r0]\n\
	adds r0, r4, #0\n\
	bl shield_throw\n\
	b _0802E018\n\
_0802DFD6:\n\
	adds r0, r4, #0\n\
	movs r1, #0\n\
	bl IsAttackOK\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #2\n\
	bne _0802DFFE\n\
	adds r2, r4, #0\n\
	adds r2, #0xed\n\
	movs r1, #0\n\
	movs r0, #1\n\
	strb r0, [r2]\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r1, [r0]\n\
	adds r0, r4, #0\n\
	bl shield_1\n\
	b _0802E018\n\
_0802DFFE:\n\
	adds r1, r4, #0\n\
	adds r1, #0xec\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	bl GetDefaultMotion\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
_0802E018:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void shield_1(struct Zero* z) {
  motion_t m = MOTION_VALUE(z);
  if (m != MOTION(DM040_ZERO_SHIELD_GUARD, 0x00)) {
    SetMotion(&z->s, MOTION(DM040_ZERO_SHIELD_GUARD, 0x00));
  }

  z->unk_12e = 0;
  if ((z->unk_b4).attackMode[2] == 0) {
    CreateWeaponShieldGuard(z, 0);
    (z->unk_b4).attackMode[2]++;
  } else {
    u8 ok = IsAttackOK(z, &z->usingWeapon);
    if (ok == 1) {
      (z->unk_b4).attackMode[0] = 3;
      (z->unk_b4).attackMode[1] = 0;
      zeroAttack(z);
    } else if (ok != 2) {
      (z->unk_b4).attackMode[1] = 2;
      (z->unk_b4).attackMode[2] = 0;
      shield_2(z);
    }
  }
}

static void shield_2(struct Zero* z) {
  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM040_ZERO_SHIELD_GUARD, 0x02));
    (z->unk_b4).attackMode[2]++;
  }

  (z->restriction).shield = TRUE;

  if (IsAttackOK(z, &z->usingWeapon)) {
    (z->unk_b4).attackMode[0] = 3;
    (z->unk_b4).attackMode[1] = 0;
    zeroAttack(z);
    return;
  }

  if ((z->s).motion.state == MOTION_END) {
    (z->unk_b4).attackMode[0] = 0;
    SetMotion(&z->s, GetDefaultMotion(z));
  }
}

void shield_throw(struct Zero* z) {
  motion_t m;

  z->unk_127 = 0;
  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM041_ZERO_SHIELD_THROW, 0x00));
    CreateWeaponShieldFly(z, 0);
    (z->unk_b4).attackMode[2]++;
  }

  (z->restriction).move = TRUE;

  KeepMotion(z, MOTION(DM041_ZERO_SHIELD_THROW, 0x00));

  m = MOTION_VALUE(z);
  if (m != MOTION(DM041_ZERO_SHIELD_THROW, 0x00)) {
    GotoMotion(&z->s, MOTION(DM041_ZERO_SHIELD_THROW, 0x00), z->motionCmdIdx, z->motionDuration);
  }

  if ((z->s).motion.state == MOTION_END) {
    z->unk_127 = 0xFF;
    (z->unk_b4).attackMode[0] = 0;
    SetMotion(&z->s, GetDefaultMotion(z));
  }
}

void shield_0802e1c8(struct Zero* z) {
  motion_t m;

  z->unk_127 = 0;
  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM041_ZERO_SHIELD_THROW, 0x01));
    CreateWeaponShieldFly(z, 1);
    (z->unk_b4).attackMode[2]++;
  }

  (z->restriction).move = TRUE;

  KeepMotion(z, MOTION(DM041_ZERO_SHIELD_THROW, 0x01));

  m = MOTION_VALUE(z);
  if (m != MOTION(DM041_ZERO_SHIELD_THROW, 0x01)) {
    GotoMotion(&z->s, MOTION(DM041_ZERO_SHIELD_THROW, 0x01), z->motionCmdIdx, z->motionDuration);
  }

  if ((z->s).motion.state == MOTION_END) {
    z->unk_127 = 0xFF;
    (z->unk_b4).attackMode[0] = 0;
    SetMotion(&z->s, GetDefaultMotion(z));
  }
}

void zero_shield_0802e268(struct Zero* z) {
  motion_t m;

  z->unk_127 = 0;
  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM041_ZERO_SHIELD_THROW, 0x01));
    CreateWeaponShieldFly(z, 2);
    (z->unk_b4).attackMode[2]++;
  }

  (z->restriction).move = TRUE;

  KeepMotion(z, MOTION(DM041_ZERO_SHIELD_THROW, 0x01));

  m = MOTION_VALUE(z);
  if (m != MOTION(DM041_ZERO_SHIELD_THROW, 0x01)) {
    GotoMotion(&z->s, MOTION(DM041_ZERO_SHIELD_THROW, 0x01), z->motionCmdIdx, z->motionDuration);
  }

  if ((z->s).motion.state == MOTION_END) {
    z->unk_127 = 0xFF;
    (z->unk_b4).attackMode[0] = 0;
    SetMotion(&z->s, GetDefaultMotion(z));
  }
}
