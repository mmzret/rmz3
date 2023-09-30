#include "global.h"
#include "motion.h"
#include "overworld.h"
#include "sound.h"
#include "weapon.h"
#include "zero.h"

static void zero_wall_080303c0(struct Zero* z);
static void zero_wall_080303d4(struct Zero* z);
static void nop_08030448(struct Zero* z);

void ZeroAttack_Wall(struct Zero* z) {
  static ZeroFunc const sZeroWallAttackRoutine[] = {
      zero_wall_080303c0,
      zero_wall_080303d4,
      nop_08030448,
      zeroWallAtk,
  };
  (sZeroWallAttackRoutine[(z->unk_b4).attackMode[0]])(z);
}

static void zero_wall_080303c0(struct Zero* z) {
  (z->unk_b4).attackMode[0] = 1;
  zero_wall_080303d4(z);
}

NAKED static void zero_wall_080303d4(struct Zero* z) {
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
	beq _0803040C\n\
	ldr r2, _08030408 @ =0x0000012B\n\
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
	b _0803042E\n\
	.align 2, 0\n\
_08030408: .4byte 0x0000012B\n\
_0803040C:\n\
	ldr r0, _08030438 @ =0x0000012B\n\
	adds r2, r4, r0\n\
	ldrb r1, [r2]\n\
	adds r0, r1, #0\n\
	cmp r0, #0xff\n\
	beq _0803043C\n\
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
_0803042E:\n\
	adds r0, r4, #0\n\
	bl zeroWallAtk\n\
	b _08030442\n\
	.align 2, 0\n\
_08030438: .4byte 0x0000012B\n\
_0803043C:\n\
	movs r0, #0xff\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
_08030442:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void nop_08030448(struct Zero* z) { return; }

static void onBuster(struct Zero* z);
static void onSaber(struct Zero* z);
static void onRod(struct Zero* z);
static void onShield(struct Zero* z);

void zeroWallAtk(struct Zero* z) {
  static ZeroFunc const weapon[] = {
      onBuster,
      onSaber,
      onRod,
      onShield,
  };
  (weapon[z->usingWeapon])(z);
}

// ------------------------------------------------------------------------------------------------------------------------------------

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

static void buster_0(struct Zero* z) {
  s32 x = -PIXEL(27);
  s32 y = -PIXEL(18);
  bool8 xflip = (z->s).flags >> 4;
  u8 ok = TRUE;
  struct Weapon* w = CreateBuster(z, x, y, (~xflip & ok));
  if (w == NULL) {
    (z->unk_b4).attackMode[0] = 0;
    return;
  }
  SetMotion(&z->s, MOTION(DM012_ZERO_BUSTER_WALL, 0x01));
  z->atkCooltime = 2;
  (z->unk_b4).attackMode[1] = ok;
  buster_1(z);
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
  expected = MOTION(DM012_ZERO_BUSTER_WALL, 0x01);
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
  expected = MOTION(DM012_ZERO_BUSTER_WALL, 0x01);
  ct = &z->atkCooltime;
  if (m != expected) {
    GotoMotion(&z->s, expected, 1, *ct);
  }

  *ct = (z->s).motion.duration;
  if ((z->s).motion.duration < 2) {
    GotoMotion(&z->s, expected, 2, 16);
    *ct = 16;
    (z->unk_b4).attackMode[1] = 3;
  }
}

// 0x080305e0
static void buster_3(struct Zero* z) {
  bool8 ok;

  motion_t m = MOTION_VALUE(z);
  if (m != MOTION(DM012_ZERO_BUSTER_WALL, 0x01)) {
    GotoMotion(&z->s, MOTION(DM012_ZERO_BUSTER_WALL, 0x01), 2, z->atkCooltime);
  }

  z->atkCooltime--;
  if (z->atkCooltime == 0xFF) {
    (z->unk_b4).attackMode[0] = 0;
    GotoMotion(&z->s, MOTION(DM005_ZERO_WALL, 0x00), 2, 1);
  }

  ok = IsAttackOK(z, &z->usingWeapon);
  if (ok) {
    (z->unk_b4).attackMode[0] = 3;
    (z->unk_b4).attackMode[1] = 0;
    zeroWallAtk(z);
  }
}

// --------------------------------------------

static void handle_saber_input(struct Zero* z);
static void wall_saber(struct Zero* z);
static void charge_saber(struct Zero* z);

static void onSaber(struct Zero* z) {
  static ZeroFunc const routine[] = {
      handle_saber_input,
      wall_saber,
      charge_saber,
  };

  struct Zero_b4* b4 = &(z->unk_b4);

  if ((z->restriction).b6) {
    (z->unk_b4).attackMode[1] = 2;
  }

  (z->restriction).shield = TRUE;
  if ((b4->status).mainWeapon == WEAPON_SABER) {
    (z->restriction).mainCharge = TRUE;
  } else {
    (z->restriction).subCharge = TRUE;
  }
  (routine[(z->unk_b4).attackMode[1]])(z);
}

WIP static void handle_saber_input(struct Zero* z) {
#if MODERN
  u8 charge;
  struct Zero_b4* b4 = &(z->unk_b4);

  if ((b4->status).mainWeapon == WEAPON_SABER) {
    charge = GetWeaponCharge(z, FALSE);
  } else {
    charge = GetWeaponCharge(z, TRUE);
  }
  if (z->ultimateCommand_22c[1] == 3) {
    charge = FULL_CHARGE;
  }

  if (charge == FULL_CHARGE) {
    (z->unk_b4).attackMode[1] = 2;
    (z->unk_b4).attackMode[2] = 0;
    charge_saber(z);
    return;
  }

  (z->unk_b4).attackMode[1] = 1;
  (z->unk_b4).attackMode[2] = 0;
  wall_saber(z);
#else
  INCCODE("asm/wip/handle_saber_input_wall.inc");
#endif
}

// 0x08030720
static void wall_saber(struct Zero* z) {
  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM028_ZERO_SABER_WALL, 0x00));
    (z->unk_b4).attackMode[2]++;
    return;
  }

  KeepMotion(z, MOTION(DM028_ZERO_SABER_WALL, 0x00));
  if ((z->unk_b4).attackMode[2] == 1) {
    if ((z->s).motion.duration > 1) {
      return;
    }
    CreateWeaponSaber(z, SABER_WALL);
    (z->unk_b4).attackMode[2]++;
    return;
  }

  if ((z->s).motion.state == MOTION_END) {
    GotoMotion(&z->s, MOTION(DM005_ZERO_WALL, 0x00), 4, 1);
    (z->unk_b4).attackMode[0] = 0;
  }
}

static void charge_saber(struct Zero* z) {
  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM028_ZERO_SABER_WALL, 0x02));
    CreateWeaponSaber(z, SABER_CHARGE_WALL);
    (z->unk_b4).attackMode[2]++;
  } else if (z->restriction.b6) {
    GotoMotion(&z->s, MOTION(DM028_ZERO_SABER_WALL, 0x02), z->motionCmdIdx, z->motionDuration);
  } else {
    KeepMotion(z, MOTION(DM028_ZERO_SABER_WALL, 0x02));
  }

  if ((z->s).motion.state == MOTION_END) {
    GotoMotion(&z->s, MOTION(DM005_ZERO_WALL, 0x00), 4, 1);
    (z->unk_b4).attackMode[0] = 0;
    return;
  }
  z->chargeSaber = 3;
}

// --------------------------------------------

static void handle_rod_input(struct Zero* z);
static void rod_1(struct Zero* z);
static void rod_nop(struct Zero* z);
static void charge_rod(struct Zero* z);

static void onRod(struct Zero* z) {
  // clang-format off
  static ZeroFunc const routine[] = {
      handle_rod_input,
      rod_1,
      rod_nop,
      rod_nop,
      rod_nop,
      rod_nop,
      rod_nop,
      charge_rod,
      rod_nop,
      rod_nop,
      rod_nop,
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

// 0x08030870
static void handle_rod_input(struct Zero* z) {
  u8 charge;
  struct Zero_b4* b4 = &(z->unk_b4);

  if ((b4->status).mainWeapon == WEAPON_ROD) {
    charge = GetWeaponCharge(z, FALSE);
  } else {
    charge = GetWeaponCharge(z, TRUE);
  }
  z->unk_rod_133 = 0;

  if (((z->ultimateCommand_224)[1] == 3) || (charge == FULL_CHARGE)) {
    (z->unk_b4).attackMode[1] = 7;
    (z->unk_b4).attackMode[2] = 0;
    charge_rod(z);
    return;
  }

  (z->unk_b4).attackMode[1] = 1;
  (z->unk_b4).attackMode[2] = 0;
  rod_1(z);
}

// 0x080308e0
static void rod_1(struct Zero* z) {
  motion_t m;
  z->rodID = 9;
  z->rodToggle = 16;
  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM036_ZERO_ROD_WALL, 0x00));
    CreateWeaponRod(z);
    (z->unk_b4).attackMode[2]++;
    return;
  }

  KeepMotion(z, MOTION(DM036_ZERO_ROD_WALL, 0x00));
  m = MOTION_VALUE(z);
  if (m != MOTION(DM036_ZERO_ROD_WALL, 0x00)) {
    GotoMotion(&z->s, MOTION(DM036_ZERO_ROD_WALL, 0x00), z->motionCmdIdx, z->motionDuration);
  }

  if (((z->s).motion.cmdIdx >= 6) && IsAttackOK(z, &z->usingWeapon)) {
    (z->unk_b4).attackMode[0] = 3;
    (z->unk_b4).attackMode[1] = 0;
    zeroWallAtk(z);
    return;
  }
  if ((z->s).motion.state == MOTION_END) {
    GotoMotion(&z->s, MOTION(DM005_ZERO_WALL, 0x00), 4, 1);
    (z->unk_b4).attackMode[0] = 0;
    z->rodID = 0xFF;
  }
}

static void rod_nop(struct Zero* z) {
  GotoMotion(&z->s, MOTION(DM005_ZERO_WALL, 0x00), 4, 1);
  (z->unk_b4).attackMode[0] = 0;
}

// 0x080309d4
static void charge_rod(struct Zero* z) {
  motion_t m;

  z->rodID = 17;
  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM061_ZERO_ROD_CHARGE_WALL, 0x00));
    CreateWeaponRod(z);
    (z->unk_b4).attackMode[2]++;
    return;
  }

  KeepMotion(z, MOTION(DM061_ZERO_ROD_CHARGE_WALL, 0x00));
  m = MOTION_VALUE(z);
  if (m != MOTION(DM061_ZERO_ROD_CHARGE_WALL, 0x00)) {
    GotoMotion(&z->s, MOTION(DM061_ZERO_ROD_CHARGE_WALL, 0x00), z->motionCmdIdx, z->motionDuration);
  }

  if ((z->s).motion.state == MOTION_END) {
    GotoMotion(&z->s, MOTION(DM005_ZERO_WALL, 0x00), 4, 1);
    (z->unk_b4).attackMode[0] = 0;
    z->rodID = 0xFF;
  }
}

// --------------------------------------------

static void handle_shield_input(struct Zero* z);
static void FUN_08030bfc(struct Zero* z);
static void FUN_08030c84(struct Zero* z);
static void FUN_08030d00(struct Zero* z);
static void FUN_08030d90(struct Zero* z);
static void FUN_08030e20(struct Zero* z);

// 0x08030a60
static void onShield(struct Zero* z) {
  // clang-format off
  static ZeroFunc const routine[] = {
      handle_shield_input,
      FUN_08030bfc,
      FUN_08030c84,
      FUN_08030d00,
      FUN_08030d90,
      FUN_08030e20,
  };
  // clang-format on

  struct Zero_b4* b4 = &(z->unk_b4);

  if (((b4->status).mainWeapon != WEAPON_SHIELD) && ((b4->status).subWeapon != WEAPON_SHIELD)) {
    GotoMotion(&z->s, MOTION(DM005_ZERO_WALL, 0x0), 4, 1);
    (z->unk_b4).attackMode[0] = 0;
    return;
  }

  (z->restriction).dash = TRUE;
  (routine[(z->unk_b4).attackMode[1]])(z);
}

// 0x08030ab8
NAKED static void handle_shield_input(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	movs r7, #0\n\
	adds r5, r4, #0\n\
	adds r5, #0xb4\n\
	ldrb r0, [r5, #0xc]\n\
	cmp r0, #3\n\
	bne _08030AEA\n\
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
	bne _08030B0A\n\
	b _08030B0E\n\
_08030AEA:\n\
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
	beq _08030B0E\n\
_08030B0A:\n\
	movs r3, #0\n\
	b _08030B34\n\
_08030B0E:\n\
	ldr r1, _08030B70 @ =0x00000225\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _08030B1A\n\
	movs r3, #2\n\
_08030B1A:\n\
	ldrh r1, [r5, #0x12]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08030B34\n\
	ldr r1, _08030B74 @ =0x0000022D\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _08030B34\n\
	movs r3, #2\n\
	movs r7, #1\n\
_08030B34:\n\
	cmp r3, #2\n\
	bne _08030BB6\n\
	adds r2, r4, #0\n\
	adds r2, #0xb4\n\
	ldrh r1, [r2, #0x12]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08030B78\n\
	ldr r0, [r6]\n\
	movs r1, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08030B56\n\
	cmp r7, #0\n\
	beq _08030B78\n\
_08030B56:\n\
	adds r2, r4, #0\n\
	adds r2, #0xed\n\
	movs r1, #0\n\
	movs r0, #5\n\
	strb r0, [r2]\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r1, [r0]\n\
	adds r0, r4, #0\n\
	bl FUN_08030e20\n\
	b _08030BF4\n\
	.align 2, 0\n\
_08030B70: .4byte 0x00000225\n\
_08030B74: .4byte 0x0000022D\n\
_08030B78:\n\
	ldrh r1, [r2, #0x12]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #3\n\
	ands r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x1a\n\
	cmp r2, #0\n\
	beq _08030BA0\n\
	adds r2, r4, #0\n\
	adds r2, #0xed\n\
	movs r1, #0\n\
	movs r0, #4\n\
	strb r0, [r2]\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r1, [r0]\n\
	adds r0, r4, #0\n\
	bl FUN_08030d90\n\
	b _08030BF4\n\
_08030BA0:\n\
	adds r1, r4, #0\n\
	adds r1, #0xed\n\
	movs r0, #3\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r2, [r0]\n\
	adds r0, r4, #0\n\
	bl FUN_08030d00\n\
	b _08030BF4\n\
_08030BB6:\n\
	adds r0, r4, #0\n\
	movs r1, #0\n\
	bl IsAttackOK\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #2\n\
	bne _08030BDE\n\
	adds r2, r4, #0\n\
	adds r2, #0xed\n\
	movs r1, #0\n\
	movs r0, #1\n\
	strb r0, [r2]\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r1, [r0]\n\
	adds r0, r4, #0\n\
	bl FUN_08030bfc\n\
	b _08030BF4\n\
_08030BDE:\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #3\n\
	adds r0, r4, #0\n\
	movs r2, #4\n\
	movs r3, #1\n\
	bl GotoMotion\n\
	adds r1, r4, #0\n\
	adds r1, #0xec\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
_08030BF4:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void FUN_08030bfc(struct Zero* z) {
  u8 ok;
  motion_t m;

  z->unk_12e = 3;
  m = MOTION_VALUE(z);
  if (m != MOTION(DM045_ZERO_SHIELD_WALL, 0)) {
    SetMotion(&z->s, MOTION(DM045_ZERO_SHIELD_WALL, 0));
  }

  if ((z->unk_b4).attackMode[2] == 0) {
    CreateWeaponShieldGuard(z, 3);
    (z->unk_b4).attackMode[2]++;
    return;
  }

  ok = IsAttackOK(z, &z->usingWeapon);
  if (ok == 1) {
    (z->unk_b4).attackMode[0] = 3;
    (z->unk_b4).attackMode[1] = 0;
    zeroWallAtk(z);
  } else if (ok != 2) {
    (z->unk_b4).attackMode[1] = 2;
    (z->unk_b4).attackMode[2] = 0;
    FUN_08030c84(z);
  }
}

static void FUN_08030c84(struct Zero* z) {
  bool8 ok;
  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM045_ZERO_SHIELD_WALL, 2));
    (z->unk_b4).attackMode[2]++;
  }
  z->restriction.shield = TRUE;

  ok = IsAttackOK(z, &z->usingWeapon);
  if (ok) {
    (z->unk_b4).attackMode[0] = 3;
    (z->unk_b4).attackMode[1] = 0;
    zeroWallAtk(z);
  } else {
    if ((z->s).motion.state == MOTION_END) {
      GotoMotion(&z->s, MOTION(DM005_ZERO_WALL, 0), 4, 1);
      (z->unk_b4).attackMode[0] = 0;
    }
  }
}

static void FUN_08030d00(struct Zero* z) {
  motion_t m;

  z->unk_127 = 2;
  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM046_ZERO_SHIELD_THROW_WALL, 0));
    CreateWeaponShieldFly(z, 0);
    (z->unk_b4).attackMode[2]++;
  }

  KeepMotion(z, MOTION(DM046_ZERO_SHIELD_THROW_WALL, 0));
  m = MOTION_VALUE(z);
  if (m != MOTION(DM046_ZERO_SHIELD_THROW_WALL, 0)) {
    GotoMotion(&z->s, MOTION(DM046_ZERO_SHIELD_THROW_WALL, 0), z->motionCmdIdx, z->motionDuration);
  }

  if ((z->s).motion.state == MOTION_END) {
    z->unk_127 = 0xFF;
    GotoMotion(&z->s, MOTION(DM005_ZERO_WALL, 0), 4, 1);
    (z->unk_b4).attackMode[0] = 0;
  }
}

static void FUN_08030d90(struct Zero* z) {
  motion_t m;

  z->unk_127 = 2;
  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM046_ZERO_SHIELD_THROW_WALL, 0));
    CreateWeaponShieldFly(z, 1);
    (z->unk_b4).attackMode[2]++;
  }

  KeepMotion(z, MOTION(DM046_ZERO_SHIELD_THROW_WALL, 0));
  m = MOTION_VALUE(z);
  if (m != MOTION(DM046_ZERO_SHIELD_THROW_WALL, 0)) {
    GotoMotion(&z->s, MOTION(DM046_ZERO_SHIELD_THROW_WALL, 0), z->motionCmdIdx, z->motionDuration);
  }

  if ((z->s).motion.state == MOTION_END) {
    z->unk_127 = 0xFF;
    GotoMotion(&z->s, MOTION(DM005_ZERO_WALL, 0), 4, 1);
    (z->unk_b4).attackMode[0] = 0;
  }
}

static void FUN_08030e20(struct Zero* z) {
  motion_t m;

  z->unk_127 = 2;
  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, MOTION(DM046_ZERO_SHIELD_THROW_WALL, 0));
    CreateWeaponShieldFly(z, 2);
    (z->unk_b4).attackMode[2]++;
  }

  KeepMotion(z, MOTION(DM046_ZERO_SHIELD_THROW_WALL, 0));
  m = MOTION_VALUE(z);
  if (m != MOTION(DM046_ZERO_SHIELD_THROW_WALL, 0)) {
    GotoMotion(&z->s, MOTION(DM046_ZERO_SHIELD_THROW_WALL, 0), z->motionCmdIdx, z->motionDuration);
  }

  if ((z->s).motion.state == MOTION_END) {
    z->unk_127 = 0xFF;
    GotoMotion(&z->s, MOTION(DM005_ZERO_WALL, 0), 4, 1);
    (z->unk_b4).attackMode[0] = 0;
  }
}
