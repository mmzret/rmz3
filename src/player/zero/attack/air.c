#include "global.h"
#include "motion.h"
#include "overworld.h"
#include "sound.h"
#include "weapon.h"
#include "zero.h"

static void air0(struct Zero* z);
static void air1(struct Zero* z);
static void nop_0802f44c(struct Zero* z);

void ZeroAttack_Air(struct Zero* z) {
  static ZeroFunc const seq[] = {
      air0,
      air1,
      nop_0802f44c,
      zeroAirAtk,
  };
  (seq[(z->unk_b4).attackMode[0]])(z);
  return;
}

static void air0(struct Zero* z) {
  (z->unk_b4).attackMode[0] = 1;
  air1(z);
}

// 0x0802f3d8
WIP static void air1(struct Zero* z) {
#if MODERN
  u8 w;
  bool8 ok = IsAttackOK(z, &z->usingWeapon);
  if (ok) {
    z->forceWeapon = 0xFF;
    (z->unk_b4).attackMode[0] = 3;
    (z->unk_b4).attackMode[1] = 0;
    zeroAirAtk(z);
    return;
  }

  w = z->forceWeapon;
  if (w != 0xFF) {
    z->usingWeapon = w;
    (z->unk_b4).attackMode[0] = 3;
    (z->unk_b4).attackMode[1] = 0;
    zeroAirAtk(z);
    return;
  }
  z->forceWeapon = 0xFF;
#else
  INCCODE("asm/wip/zero_attack_air1.inc");
#endif
}

static void nop_0802f44c(struct Zero* z) { return; }

static void onBuster(struct Zero* z);
static void onSaber(struct Zero* z);
static void onRod(struct Zero* z);
static void onShield(struct Zero* z);

void zeroAirAtk(struct Zero* z) {
  static ZeroFunc const weapon[] = {
      onBuster,
      onSaber,
      onRod,
      (ZeroFunc)0x0802FEA9,
  };
  (weapon[z->usingWeapon])(z);
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void buster_0(struct Zero* z);
static void buster_1(struct Zero* z);
static void buster_2(struct Zero* z);
static void buster_3(struct Zero* z);

// 0x0802f470
static void onBuster(struct Zero* z) {
  static ZeroFunc const seq[] = {
      buster_0,
      buster_1,
      buster_2,
      buster_3,
  };
  (seq[(z->unk_b4).attackMode[1]])(z);
}

static void buster_0(struct Zero* z) {
  s32 x = -PIXEL(30);
  s32 y = -PIXEL(22);
  bool8 xflip = ((z->s).flags >> 4);
  u8 ok = TRUE;
  struct Weapon* w = CreateBuster(z, x, y, xflip & ok);
  if (w == NULL) {
    (z->unk_b4).attackMode[0] = 0;
  } else {
    SetMotion(&z->s, MOTION(DM011_ZERO_BUSTER_AIR, 1));
    z->atkCooltime = 2;
    (z->unk_b4).attackMode[1] = ok;
    buster_1(z);
  }
}

static void buster_1(struct Zero* z) {
  u8* ct;
  motion_t m, expected;
  struct Zero_b4* b4 = &(z->unk_b4);

  if ((b4->status).mainWeapon == WEAPON_BUSTER) {
    (z->restriction).mainCharge = TRUE;
  } else {
    (z->restriction).subCharge = TRUE;
  }

  m = MOTION_VALUE(z);
  expected = MOTION(DM011_ZERO_BUSTER_AIR, 0x01);
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

  if ((b4->status).mainWeapon == WEAPON_BUSTER) {
    (z->restriction).mainCharge = TRUE;
  } else {
    (z->restriction).subCharge = TRUE;
  }

  m = MOTION_VALUE(z);
  expected = MOTION(DM011_ZERO_BUSTER_AIR, 0x01);
  ct = &z->atkCooltime;
  if (m != expected) {
    GotoMotion(&z->s, expected, 1, *ct);
  }

  *ct = (z->s).motion.duration;
  if ((z->s).motion.duration < 2) {
    GotoMotion(&z->s, expected, 2, 4);
    *ct = 16;
    (z->unk_b4).attackMode[1] = 3;
  }
}

// 0x0802f5e0
static void buster_3(struct Zero* z) {
  bool8 ok;

  motion_t m = MOTION_VALUE(z);
  if (m != MOTION(DM011_ZERO_BUSTER_AIR, 1)) {
    GotoMotion(&z->s, MOTION(DM011_ZERO_BUSTER_AIR, 1), 2, z->atkCooltime);
  }

  z->atkCooltime--;
  if (z->atkCooltime == 0xFF) {
    (z->unk_b4).attackMode[0] = 0;
    if ((z->s).mode[2] == 1) {
      GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 3), 2, 1);
    } else {
      GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 4), 2, 1);
    }
  }

  ok = IsAttackOK(z, &z->usingWeapon);
  if (ok != 0) {
    (z->unk_b4).attackMode[0] = 3;
    (z->unk_b4).attackMode[1] = 0;
    zeroAirAtk(z);
  }
}

// --------------------------------------------

static void handle_saber_input(struct Zero* z);
static void air_saber(struct Zero* z);
void air_saber_hold(struct Zero* z);
static void air_saber_end(struct Zero* z);
static void air_charge_saber(struct Zero* z);
static void split_heavens(struct Zero* z);
static void air_rolling_saber(struct Zero* z);
static void saber_smash(struct Zero* z);

static void onSaber(struct Zero* z) {
  // clang-format off
  static ZeroFunc const seq[] = {
      handle_saber_input,
      air_saber,
      air_saber_hold,
      air_saber_end,
      air_charge_saber,
      split_heavens,
      air_rolling_saber,
      saber_smash,
  };
  // clang-format on

  struct Zero_b4* b4 = &(z->unk_b4);

  if ((z->restriction).b6) {
    (z->unk_b4).attackMode[1] = 4;
  }

  (z->restriction).shield = TRUE;
  if ((b4->status).mainWeapon == WEAPON_SABER) {
    (z->restriction).mainCharge = TRUE;
  } else {
    (z->restriction).subCharge = TRUE;
  }
  (seq[(z->unk_b4).attackMode[1]])(z);
}

// 0x0802f6d4
WIP static void handle_saber_input(struct Zero* z) {
#if MODERN
  u8 c;
  struct Zero_b4* b4 = &(z->unk_b4);

  if ((b4->status).mainWeapon == WEAPON_SABER) {
    c = GetWeaponCharge(z, FALSE);
  } else {
    c = GetWeaponCharge(z, TRUE);
  }

  if (z->ultimateCommand_22c[1] == 3) {
    c = FULL_CHARGE;
  }
  if (c == FULL_CHARGE) {
    (z->unk_b4).attackMode[1] = 4;
    (z->unk_b4).attackMode[2] = 0;
    air_charge_saber(z);

  } else {
    zero_input_t input = z->zeroInput;
    if ((input & DPAD_UP) && (isElfUsed_2(z, ELF_MALTHAS))) {
      (z->unk_b4).attackMode[1] = 6;
      (z->unk_b4).attackMode[2] = 0;
      air_rolling_saber(z);

    } else {
      struct Zero_b4* b4 = &(z->unk_b4);
      if ((input & DPAD_DOWN) && ((b4->status).exSkill & (1 << EXSKILL_ID_SMASH))) {
        (z->unk_b4).attackMode[1] = 7;
        (z->unk_b4).attackMode[2] = 0;
        saber_smash(z);
        return;
      }

      (z->unk_b4).attackMode[1] = 1;
      (z->unk_b4).attackMode[2] = 0;
      air_saber(z);
    }
  }
#else
  INCCODE("asm/wip/handle_saber_input_air.inc");
#endif
}

static void air_saber(struct Zero* z) {
  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM025_ZERO_SABER_AIR, 0x00));
    CreateWeaponSaber(z, 5);
    (z->unk_b4).attackMode[2]++;
    return;
  }

  KeepMotion(z, MOTION(DM025_ZERO_SABER_AIR, 0x00));
  if (((z->s).motion.cmdIdx == 5) && ((z->s).motion.duration < 2)) {
    if (z->zeroInput & DPAD_DOWN) {
      (z->unk_b4).attackMode[1] = 2;
    } else {
      (z->unk_b4).attackMode[1] = 3;  // air_saber_hold
    }
    (z->unk_b4).attackMode[2] = 0;
  }
}

// Ja: ジャンプ下入れセイバー
void air_saber_hold(struct Zero* z) {
  if ((z->unk_b4).attackMode[2] == 0) {
    GotoMotion(&z->s, MOTION(DM025_ZERO_SABER_AIR, 0x00), 7, 1);
    (z->unk_b4).attackMode[2]++;
  }
  KeepMotion(z, MOTION(DM025_ZERO_SABER_AIR, 0x00));
  if ((z->zeroInput & DPAD_DOWN) == 0) {
    (z->unk_b4).attackMode[1] = 3;
    (z->unk_b4).attackMode[2] = 0;
  }
}

static void air_saber_end(struct Zero* z) {
  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM025_ZERO_SABER_AIR, 1));
    (z->unk_b4).attackMode[2]++;
  } else {
    KeepMotion(z, MOTION(DM025_ZERO_SABER_AIR, 0x01));
  }

  if ((z->s).motion.state == MOTION_END) {
    if ((z->s).mode[2] == 1) {
      GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 0x03), 2, 1);
    } else {
      GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 0x04), 2, 1);
    }
    (z->unk_b4).attackMode[0] = 0;
  }
}

NAKED static void air_charge_saber(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	movs r6, #0\n\
	adds r5, r4, #0\n\
	adds r5, #0xee\n\
	ldrb r0, [r5]\n\
	cmp r0, #0\n\
	bne _0802F90C\n\
	ldr r1, _0802F908 @ =0x00001902\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r0, r4, #0\n\
	movs r1, #9\n\
	bl CreateWeaponSaber\n\
	ldrb r0, [r5]\n\
	adds r0, #1\n\
	strb r0, [r5]\n\
	b _0802F94C\n\
	.align 2, 0\n\
_0802F908: .4byte 0x00001902\n\
_0802F90C:\n\
	movs r1, #0x92\n\
	lsls r1, r1, #1\n\
	adds r0, r4, r1\n\
	ldrb r1, [r0]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802F944\n\
	movs r3, #0xa0\n\
	lsls r3, r3, #1\n\
	adds r2, r4, r3\n\
	ldrb r0, [r2]\n\
	cmp r0, #7\n\
	bhi _0802F940\n\
	ldr r1, _0802F93C @ =0x00001902\n\
	adds r2, r0, #0\n\
	adds r3, #1\n\
	adds r0, r4, r3\n\
	ldrb r3, [r0]\n\
	adds r0, r4, #0\n\
	bl GotoMotion\n\
	b _0802F94C\n\
	.align 2, 0\n\
_0802F93C: .4byte 0x00001902\n\
_0802F940:\n\
	movs r6, #1\n\
	b _0802F94C\n\
_0802F944:\n\
	ldr r1, _0802F984 @ =0x00001902\n\
	adds r0, r4, #0\n\
	bl KeepMotion\n\
_0802F94C:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	beq _0802F95A\n\
	cmp r6, #0\n\
	beq _0802F99E\n\
_0802F95A:\n\
	movs r1, #0x86\n\
	lsls r1, r1, #2\n\
	adds r0, r4, r1\n\
	ldr r1, [r0]\n\
	movs r0, #0x80\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _0802F988\n\
	adds r2, r4, #0\n\
	adds r2, #0xed\n\
	movs r1, #0\n\
	movs r0, #2\n\
	strb r0, [r2]\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r1, [r0]\n\
	adds r0, r4, #0\n\
	bl air_saber_hold\n\
	b _0802F9A6\n\
	.align 2, 0\n\
_0802F984: .4byte 0x00001902\n\
_0802F988:\n\
	adds r2, r4, #0\n\
	adds r2, #0xed\n\
	movs r0, #3\n\
	strb r0, [r2]\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r1, [r0]\n\
	adds r0, r4, #0\n\
	bl air_saber_end\n\
	b _0802F9A6\n\
_0802F99E:\n\
	ldr r3, _0802F9AC @ =0x00000125\n\
	adds r1, r4, r3\n\
	movs r0, #2\n\
	strb r0, [r1]\n\
_0802F9A6:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0802F9AC: .4byte 0x00000125\n\
 .syntax divided\n");
}

NAKED static void split_heavens(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	adds r5, r4, #0\n\
	adds r5, #0xb4\n\
	adds r0, #0xee\n\
	ldrb r0, [r0]\n\
	cmp r0, #1\n\
	beq _0802FA02\n\
	cmp r0, #1\n\
	bgt _0802F9CA\n\
	cmp r0, #0\n\
	beq _0802F9D4\n\
	b _0802FA74\n\
_0802F9CA:\n\
	cmp r0, #2\n\
	beq _0802FA1A\n\
	cmp r0, #3\n\
	beq _0802FA2C\n\
	b _0802FA74\n\
_0802F9D4:\n\
	ldr r1, _0802F9EC @ =0x00001201\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r5, #0xe]\n\
	cmp r0, #2\n\
	bne _0802F9F0\n\
	adds r0, r4, #0\n\
	movs r1, #0x11\n\
	bl CreateWeaponSaber\n\
	b _0802F9F8\n\
	.align 2, 0\n\
_0802F9EC: .4byte 0x00001201\n\
_0802F9F0:\n\
	adds r0, r4, #0\n\
	movs r1, #0x10\n\
	bl CreateWeaponSaber\n\
_0802F9F8:\n\
	adds r1, r4, #0\n\
	adds r1, #0xee\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
_0802FA02:\n\
	ldr r1, _0802FA54 @ =0x00001201\n\
	adds r0, r4, #0\n\
	bl KeepMotion\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #2\n\
	bne _0802FA74\n\
	adds r1, r4, #0\n\
	adds r1, #0xee\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
_0802FA1A:\n\
	ldr r1, _0802FA58 @ =0x00001202\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r1, r4, #0\n\
	adds r1, #0xee\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
_0802FA2C:\n\
	ldr r1, _0802FA58 @ =0x00001202\n\
	adds r0, r4, #0\n\
	bl KeepMotion\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0802FA74\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #1\n\
	bne _0802FA60\n\
	ldr r1, _0802FA5C @ =0x00000403\n\
	adds r0, r4, #0\n\
	movs r2, #2\n\
	movs r3, #1\n\
	bl GotoMotion\n\
	b _0802FA6C\n\
	.align 2, 0\n\
_0802FA54: .4byte 0x00001201\n\
_0802FA58: .4byte 0x00001202\n\
_0802FA5C: .4byte 0x00000403\n\
_0802FA60:\n\
	ldr r1, _0802FA7C @ =0x00000404\n\
	adds r0, r4, #0\n\
	movs r2, #2\n\
	movs r3, #1\n\
	bl GotoMotion\n\
_0802FA6C:\n\
	adds r1, r4, #0\n\
	adds r1, #0xec\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
_0802FA74:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0802FA7C: .4byte 0x00000404\n\
 .syntax divided\n");
}

static void air_rolling_saber(struct Zero* z) {
  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM026_ZERO_SABER_AIR_ROLLING, 0x00));
    CreateWeaponSaber(z, SABER_AIR_ROLLING);
    (z->unk_b4).attackMode[2]++;
    return;
  }

  KeepMotion(z, MOTION(DM026_ZERO_SABER_AIR_ROLLING, 0x00));
  if ((z->s).motion.state == MOTION_END) {
    if (z->zeroInput & DPAD_DOWN) {
      (z->unk_b4).attackMode[1] = 2;
      (z->unk_b4).attackMode[2] = 0;
      air_saber_hold(z);
    } else {
      (z->unk_b4).attackMode[1] = 3;
      (z->unk_b4).attackMode[2] = 0;
    }
  }
}

static void saber_smash(struct Zero* z) {
  struct Zero_b4* b4 = &(z->unk_b4);

  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM027_ZERO_SABER_SMASH, 0x00));
    if ((b4->status).element == ELEMENT_THUNDER) {
      CreateWeaponSaber(z, SABER_SMASH_ELEC);
    } else {
      CreateWeaponSaber(z, SABER_SMASH);
    }
    (z->s).mode[2] = 2;
    (z->s).mode[3] = 2;
    if ((z->s).d.y < 0x200) {
      (z->s).d.y = 0x200;
    }
    (z->unk_b4).attackMode[2]++;
    return;
  }

  KeepMotion(z, MOTION(DM027_ZERO_SABER_SMASH, 0x00));
}

// --------------------------------------------

static void handle_rod_input(struct Zero* z);
static void rod_horizontal(struct Zero* z);
static void rod_up(struct Zero* z);
static void rod_down(struct Zero* z);
static void rod_end(struct Zero* z);
static void rod_charge_horizontal(struct Zero* z);
static void rod_charge_up(struct Zero* z);
static void rod_charge_down(struct Zero* z);
static void recoil_jump(struct Zero* z);

// 0x0802fb54
static void onRod(struct Zero* z) {
  // clang-format off
  static ZeroFunc const routine[] = {
    handle_rod_input,
    // --------------------------------------------
    rod_horizontal,
    rod_end,
    // --------------------------------------------
    rod_up,
    rod_end,
    // --------------------------------------------
    rod_down,
    rod_end,
    // --------------------------------------------
    rod_charge_horizontal,
    rod_charge_up,
    rod_charge_down,
    recoil_jump,
  };
  // clang-format on

  struct Zero_b4* b4 = &(z->unk_b4);

  if ((b4->status).mainWeapon == WEAPON_ROD) {
    (z->restriction).mainCharge = TRUE;
  } else {
    (z->restriction).subCharge = TRUE;
  }
  (routine[(z->unk_b4).attackMode[1]])(z);
}

// 0x0802fb98
NAKED static void handle_rod_input(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	adds r0, #0xb4\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #2\n\
	bne _0802FBAA\n\
	adds r0, r4, #0\n\
	movs r1, #0\n\
	b _0802FBAE\n\
_0802FBAA:\n\
	adds r0, r4, #0\n\
	movs r1, #1\n\
_0802FBAE:\n\
	bl GetWeaponCharge\n\
	lsls r0, r0, #0x18\n\
	lsrs r1, r0, #0x18\n\
	ldr r2, _0802FBD8 @ =0x00000133\n\
	adds r0, r4, r2\n\
	movs r2, #0\n\
	strb r2, [r0]\n\
	ldr r3, _0802FBDC @ =0x00000225\n\
	adds r0, r4, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0802FBE0\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #7\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r2, [r0]\n\
	b _0802FC6A\n\
	.align 2, 0\n\
_0802FBD8: .4byte 0x00000133\n\
_0802FBDC: .4byte 0x00000225\n\
_0802FBE0:\n\
	ldr r3, _0802FBFC @ =0x0000022B\n\
	adds r0, r4, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0802FC00\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #8\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r2, [r0]\n\
	b _0802FC42\n\
	.align 2, 0\n\
_0802FBFC: .4byte 0x0000022B\n\
_0802FC00:\n\
	ldr r3, _0802FC1C @ =0x0000022D\n\
	adds r0, r4, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0802FC20\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #9\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r2, [r0]\n\
	b _0802FC5A\n\
	.align 2, 0\n\
_0802FC1C: .4byte 0x0000022D\n\
_0802FC20:\n\
	cmp r1, #2\n\
	bne _0802FC72\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r2, [r0]\n\
	movs r1, #0x86\n\
	lsls r1, r1, #2\n\
	adds r0, r4, r1\n\
	ldr r1, [r0]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802FC4A\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #8\n\
	strb r0, [r1]\n\
_0802FC42:\n\
	adds r0, r4, #0\n\
	bl rod_charge_up\n\
	b _0802FCBE\n\
_0802FC4A:\n\
	movs r0, #0x80\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _0802FC62\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #9\n\
	strb r0, [r1]\n\
_0802FC5A:\n\
	adds r0, r4, #0\n\
	bl rod_charge_down\n\
	b _0802FCBE\n\
_0802FC62:\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #7\n\
	strb r0, [r1]\n\
_0802FC6A:\n\
	adds r0, r4, #0\n\
	bl rod_charge_horizontal\n\
	b _0802FCBE\n\
_0802FC72:\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r2, [r0]\n\
	movs r2, #0x86\n\
	lsls r2, r2, #2\n\
	adds r0, r4, r2\n\
	ldr r1, [r0]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802FC98\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #3\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	bl rod_up\n\
	b _0802FCBE\n\
_0802FC98:\n\
	movs r0, #0x80\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _0802FCB0\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #5\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	bl rod_down\n\
	b _0802FCBE\n\
_0802FCB0:\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	bl rod_horizontal\n\
_0802FCBE:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void rod_horizontal(struct Zero* z) {
  z->rodID = 6;
  FUN_08032504(z, MOTION(DM033_ZERO_ROD_AIR, 0x00));
}

static void rod_up(struct Zero* z) {
  z->rodID = 7;
  FUN_08032504(z, MOTION(DM034_ZERO_ROD_UP_AIR, 0x00));
}

static void rod_down(struct Zero* z) {
  z->rodID = 8;
  FUN_08032504(z, MOTION(DM035_ZERO_ROD_DOWN_AIR, 0x00));
}

static void rod_end(struct Zero* z) {
  if ((z->s).mode[2] == 1) {
    GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 0x03), 2, 1);
  } else {
    GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 0x04), 2, 1);
  }
  (z->unk_b4).attackMode[0] = 0;
}

static void rod_charge_horizontal(struct Zero* z) {
  z->rodID = 14;
  FUN_0803267c(z, MOTION(DM058_ZERO_ROD_CHARGE_AIR, 0x00));
}

static void rod_charge_up(struct Zero* z) {
  z->rodID = 15;
  FUN_0803267c(z, MOTION(DM059_ZERO_ROD_CHARGE_UP_AIR, 0x00));
}

static void rod_charge_down(struct Zero* z) {
  z->rodID = 16;
  FUN_0803267c(z, MOTION(DM060_ZERO_ROD_CHARGE_DOWN_AIR, 0x00));
  z->unk_138 = (s16)(z->s).d.x;
  if (z->unk_135 != 0) {
    (z->s).mode[1] = ZERO_AIR;
    (z->s).mode[2] = 0;
    (z->s).mode[3] = 3;
    (z->unk_b4).attackMode[1] = 10;
    (z->unk_b4).attackMode[2] = 0;
  }
}

// 0x0802fdc8
NAKED static void recoil_jump(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r5, r0, #0\n\
	adds r0, #0xee\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _0802FE38\n\
	movs r1, #0x9f\n\
	lsls r1, r1, #1\n\
	adds r0, r5, r1\n\
	ldrh r1, [r0]\n\
	movs r0, #0xe4\n\
	lsls r0, r0, #6\n\
	cmp r1, r0\n\
	bne _0802FE10\n\
	ldr r1, _0802FE04 @ =0x00003901\n\
	movs r2, #0xa0\n\
	lsls r2, r2, #1\n\
	adds r0, r5, r2\n\
	ldrb r2, [r0]\n\
	ldr r3, _0802FE08 @ =0x00000141\n\
	adds r0, r5, r3\n\
	ldrb r3, [r0]\n\
	adds r0, r5, #0\n\
	bl GotoMotion\n\
	ldr r0, _0802FE0C @ =0x00000135\n\
	adds r1, r5, r0\n\
	movs r0, #2\n\
	b _0802FE2C\n\
	.align 2, 0\n\
_0802FE04: .4byte 0x00003901\n\
_0802FE08: .4byte 0x00000141\n\
_0802FE0C: .4byte 0x00000135\n\
_0802FE10:\n\
	ldr r1, _0802FE58 @ =0x00003C01\n\
	movs r2, #0xa0\n\
	lsls r2, r2, #1\n\
	adds r0, r5, r2\n\
	ldrb r2, [r0]\n\
	ldr r3, _0802FE5C @ =0x00000141\n\
	adds r0, r5, r3\n\
	ldrb r3, [r0]\n\
	adds r0, r5, #0\n\
	bl GotoMotion\n\
	ldr r0, _0802FE60 @ =0x00000135\n\
	adds r1, r5, r0\n\
	movs r0, #3\n\
_0802FE2C:\n\
	strb r0, [r1]\n\
	adds r1, r5, #0\n\
	adds r1, #0xee\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
_0802FE38:\n\
	ldr r1, _0802FE60 @ =0x00000135\n\
	adds r0, r5, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #2\n\
	bne _0802FE68\n\
	movs r2, #0x93\n\
	lsls r2, r2, #1\n\
	adds r4, r5, r2\n\
	movs r0, #0x13\n\
	strb r0, [r4]\n\
	ldr r1, _0802FE64 @ =0x00003901\n\
	adds r0, r5, #0\n\
	bl KeepMotion\n\
	b _0802FE7A\n\
	.align 2, 0\n\
_0802FE58: .4byte 0x00003C01\n\
_0802FE5C: .4byte 0x00000141\n\
_0802FE60: .4byte 0x00000135\n\
_0802FE64: .4byte 0x00003901\n\
_0802FE68:\n\
	movs r3, #0x93\n\
	lsls r3, r3, #1\n\
	adds r4, r5, r3\n\
	movs r0, #0x14\n\
	strb r0, [r4]\n\
	ldr r1, _0802FEA0 @ =0x00003C01\n\
	adds r0, r5, #0\n\
	bl KeepMotion\n\
_0802FE7A:\n\
	ldr r0, [r5, #0x60]\n\
	cmp r0, #0\n\
	blt _0802FE98\n\
	ldr r1, _0802FEA4 @ =0x00000404\n\
	adds r0, r5, #0\n\
	movs r2, #2\n\
	movs r3, #1\n\
	bl GotoMotion\n\
	adds r1, r5, #0\n\
	adds r1, #0xec\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	movs r0, #0xff\n\
	strb r0, [r4]\n\
_0802FE98:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0802FEA0: .4byte 0x00003C01\n\
_0802FEA4: .4byte 0x00000404\n\
 .syntax divided\n");
}

// --------------------------------------------

static void handle_shield_input(struct Zero* z);
static void shield_1(struct Zero* z);
static void shield_2(struct Zero* z);
static void shield_throw_air(struct Zero* z);
static void shield_sweep(struct Zero* z);
static void orbit_shield(struct Zero* z);

static void onShield(struct Zero* z) {
  // clang-format off
  static ZeroFunc const routine[] = {
      handle_shield_input,
      shield_1,
      shield_2,
      shield_throw_air,
      shield_sweep,
      orbit_shield,
  };
  // clang-format on

  struct Zero_b4* b4 = &(z->unk_b4);

  if (((b4->status).mainWeapon != WEAPON_SHIELD) && ((b4->status).subWeapon != WEAPON_SHIELD)) {
    if ((z->s).mode[2] == 1) {
      GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 0x03), 2, 1);
    } else {
      GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 0x04), 2, 1);
    }
    (z->unk_b4).attackMode[0] = 0;
    return;
  }

  (z->restriction).dash = TRUE;
  (routine[(z->unk_b4).attackMode[1]])(z);
}

// 0x0802ff1c
NAKED static void handle_shield_input(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	movs r7, #0\n\
	adds r5, r4, #0\n\
	adds r5, #0xb4\n\
	ldrb r0, [r5, #0xc]\n\
	cmp r0, #3\n\
	bne _0802FF4E\n\
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
	bne _0802FF6E\n\
	b _0802FF72\n\
_0802FF4E:\n\
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
	beq _0802FF72\n\
_0802FF6E:\n\
	movs r3, #0\n\
	b _0802FF98\n\
_0802FF72:\n\
	ldr r1, _0802FFD4 @ =0x00000225\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0802FF7E\n\
	movs r3, #2\n\
_0802FF7E:\n\
	ldrh r1, [r5, #0x12]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802FF98\n\
	ldr r1, _0802FFD8 @ =0x0000022D\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0802FF98\n\
	movs r3, #2\n\
	movs r7, #1\n\
_0802FF98:\n\
	cmp r3, #2\n\
	bne _0803001A\n\
	adds r2, r4, #0\n\
	adds r2, #0xb4\n\
	ldrh r1, [r2, #0x12]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802FFDC\n\
	ldr r0, [r6]\n\
	movs r1, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0802FFBA\n\
	cmp r7, #0\n\
	beq _0802FFDC\n\
_0802FFBA:\n\
	adds r2, r4, #0\n\
	adds r2, #0xed\n\
	movs r1, #0\n\
	movs r0, #5\n\
	strb r0, [r2]\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r1, [r0]\n\
	adds r0, r4, #0\n\
	bl orbit_shield\n\
	b _08030070\n\
	.align 2, 0\n\
_0802FFD4: .4byte 0x00000225\n\
_0802FFD8: .4byte 0x0000022D\n\
_0802FFDC:\n\
	ldrh r1, [r2, #0x12]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #3\n\
	ands r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x1a\n\
	cmp r2, #0\n\
	beq _08030004\n\
	adds r2, r4, #0\n\
	adds r2, #0xed\n\
	movs r1, #0\n\
	movs r0, #4\n\
	strb r0, [r2]\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r1, [r0]\n\
	adds r0, r4, #0\n\
	bl shield_sweep\n\
	b _08030070\n\
_08030004:\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #3\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r2, [r0]\n\
	adds r0, r4, #0\n\
	bl shield_throw_air\n\
	b _08030070\n\
_0803001A:\n\
	adds r0, r4, #0\n\
	movs r1, #0\n\
	bl IsAttackOK\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #2\n\
	bne _08030042\n\
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
	b _08030070\n\
_08030042:\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #1\n\
	bne _0803005C\n\
	ldr r1, _08030058 @ =0x00000403\n\
	adds r0, r4, #0\n\
	movs r2, #2\n\
	movs r3, #1\n\
	bl GotoMotion\n\
	b _08030068\n\
	.align 2, 0\n\
_08030058: .4byte 0x00000403\n\
_0803005C:\n\
	ldr r1, _08030078 @ =0x00000404\n\
	adds r0, r4, #0\n\
	movs r2, #2\n\
	movs r3, #1\n\
	bl GotoMotion\n\
_08030068:\n\
	adds r1, r4, #0\n\
	adds r1, #0xec\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
_08030070:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08030078: .4byte 0x00000404\n\
 .syntax divided\n");
}

// 0x0803007c
static void shield_1(struct Zero* z) {
  motion_t m;
  z->unk_12e = 2;

  m = MOTION_VALUE(z);
  if (m != MOTION(DM043_ZERO_SHIELD_AIR, 0x00)) {
    SetMotion(&z->s, MOTION(DM043_ZERO_SHIELD_AIR, 0x00));
  }

  if ((z->unk_b4).attackMode[2] == 0) {
    CreateWeaponShieldGuard(z, 2);
    (z->unk_b4).attackMode[2]++;
  } else {
    const u8 ok = IsAttackOK(z, &z->usingWeapon);
    if (ok == 1) {
      (z->unk_b4).attackMode[0] = 3;
      (z->unk_b4).attackMode[1] = 0;
      zeroAirAtk(z);
      return;
    }
    if (ok != 2) {
      (z->unk_b4).attackMode[1] = 2;
      (z->unk_b4).attackMode[2] = 0;
      shield_2(z);
    }
  }
}

// 0x08030104
static void shield_2(struct Zero* z) {
  bool8 ok;
  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM043_ZERO_SHIELD_AIR, 0x02));
    (z->unk_b4).attackMode[2]++;
  }

  z->restriction.shield = TRUE;
  ok = IsAttackOK(z, &z->usingWeapon);
  if (ok) {
    (z->unk_b4).attackMode[0] = 3;
    (z->unk_b4).attackMode[1] = 0;
    zeroAirAtk(z);
    return;
  }

  if ((z->s).motion.state == MOTION_END) {
    if ((z->s).mode[2] == 1) {
      GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 0x03), 2, 1);
    } else {
      GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 0x04), 2, 1);
    }
    (z->unk_b4).attackMode[0] = 0;
  }
}

// 0x080301a0
static void shield_throw_air(struct Zero* z) {
  motion_t m;
  z->unk_127 = 1;

  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM044_ZERO_SHIELD_THROW_AIR, 0x00));
    CreateWeaponShieldFly(z, 0);
    (z->unk_b4).attackMode[2]++;
  }
  KeepMotion(z, MOTION(DM044_ZERO_SHIELD_THROW_AIR, 0x00));
  m = MOTION_VALUE(z);
  if (m != MOTION(DM044_ZERO_SHIELD_THROW_AIR, 0x00)) {
    GotoMotion(&z->s, MOTION(DM044_ZERO_SHIELD_THROW_AIR, 0x00), z->motionCmdIdx, z->motionDuration);
  }

  if ((z->s).motion.state == MOTION_END) {
    z->unk_127 = 0xFF;
    if ((z->s).mode[2] == 1) {
      GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 0x03), 2, 1);
    } else {
      GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 0x04), 2, 1);
    }
    (z->unk_b4).attackMode[0] = 0;
  }
}

static void shield_sweep(struct Zero* z) {
  motion_t m;
  z->unk_127 = 1;

  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM044_ZERO_SHIELD_THROW_AIR, 0x01));
    CreateWeaponShieldFly(z, 1);
    (z->unk_b4).attackMode[2]++;
  }
  KeepMotion(z, MOTION(DM044_ZERO_SHIELD_THROW_AIR, 0x01));
  m = MOTION_VALUE(z);
  if (m != MOTION(DM044_ZERO_SHIELD_THROW_AIR, 0x01)) {
    GotoMotion(&z->s, MOTION(DM044_ZERO_SHIELD_THROW_AIR, 0x01), z->motionCmdIdx, z->motionDuration);
  }

  if ((z->s).motion.state == MOTION_END) {
    z->unk_127 = 0xFF;
    if ((z->s).mode[2] == 1) {
      GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 0x03), 2, 1);
    } else {
      GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 0x04), 2, 1);
    }
    (z->unk_b4).attackMode[0] = 0;
  }
}

static void orbit_shield(struct Zero* z) {
  motion_t m;
  z->unk_127 = 1;

  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM044_ZERO_SHIELD_THROW_AIR, 0x01));
    CreateWeaponShieldFly(z, 2);
    (z->unk_b4).attackMode[2]++;
  }
  KeepMotion(z, MOTION(DM044_ZERO_SHIELD_THROW_AIR, 0x01));
  m = MOTION_VALUE(z);
  if (m != MOTION(DM044_ZERO_SHIELD_THROW_AIR, 0x01)) {
    GotoMotion(&z->s, MOTION(DM044_ZERO_SHIELD_THROW_AIR, 0x01), z->motionCmdIdx, z->motionDuration);
  }

  if ((z->s).motion.state == MOTION_END) {
    z->unk_127 = 0xFF;
    if ((z->s).mode[2] == 1) {
      GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 0x03), 2, 1);
    } else {
      GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 0x04), 2, 1);
    }
    (z->unk_b4).attackMode[0] = 0;
  }
}
