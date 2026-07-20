#include "global.h"
#include "motion.h"
#include "overworld.h"
#include "player/zero.h"
#include "sound.h"
#include "weapon.h"
#include "zero.h"

static void dash_saber_0(struct Zero* z);
static void dash_saber_1(struct Zero* z);
static void nop_0802ec78(struct Zero* z);
void FUN_0802ec7c(struct Zero* z);

void ZeroAttackGround_Dash(struct Zero* z) {
  static ZeroFunc const PTR_ARRAY_0835e678[] = {
      dash_saber_0,
      dash_saber_1,
      nop_0802ec78,
      FUN_0802ec7c,
  };
  (PTR_ARRAY_0835e678[(z->unk_b4).attackState8[0]])(z);
}

static void dash_saber_0(struct Zero* z) {
  (z->unk_b4).attackState8[0] = 1;
  dash_saber_1(z);
}

// 0x0802ebbc
NAKED static void dash_saber_1(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	movs r0, #0x94\n\
	lsls r0, r0, #1\n\
	adds r1, r4, r0\n\
	adds r0, r4, #0\n\
	bl IsAttackOK\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _0802EBFC\n\
	adds r2, r4, #0\n\
	adds r2, #0xb4\n\
	ldr r0, _0802EBF4 @ =0x0000012B\n\
	adds r1, r4, r0\n\
	movs r0, #0xff\n\
	strb r0, [r1]\n\
	ldr r1, _0802EBF8 @ =0x00000216\n\
	adds r0, r4, r1\n\
	ldrh r1, [r0]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0802EC48\n\
	ldrb r0, [r2, #0x11]\n\
	b _0802EC26\n\
	.align 2, 0\n\
_0802EBF4: .4byte 0x0000012B\n\
_0802EBF8: .4byte 0x00000216\n\
_0802EBFC:\n\
	adds r3, r4, #0\n\
	adds r3, #0xb4\n\
	ldr r0, _0802EC60 @ =0x0000012B\n\
	adds r2, r4, r0\n\
	ldrb r1, [r2]\n\
	adds r0, r1, #0\n\
	cmp r0, #0xff\n\
	beq _0802EC6C\n\
	movs r2, #0x94\n\
	lsls r2, r2, #1\n\
	adds r0, r4, r2\n\
	strb r1, [r0]\n\
	ldr r1, _0802EC64 @ =0x00000216\n\
	adds r0, r4, r1\n\
	ldrh r1, [r0]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0802EC48\n\
	ldrb r0, [r3, #0x11]\n\
_0802EC26:\n\
	cmp r0, #3\n\
	beq _0802EC2E\n\
	cmp r0, #7\n\
	bne _0802EC48\n\
_0802EC2E:\n\
	adds r0, r4, #0\n\
	bl GetZeroColor\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	adds r0, r4, #0\n\
	bl LoadZeroPalette\n\
	ldr r2, _0802EC68 @ =0x00000147\n\
	adds r1, r4, r2\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
_0802EC48:\n\
	adds r0, r4, #0\n\
	adds r0, #0xec\n\
	movs r2, #0\n\
	movs r1, #3\n\
	strb r1, [r0]\n\
	adds r0, #1\n\
	strb r2, [r0]\n\
	adds r0, r4, #0\n\
	bl FUN_0802ec7c\n\
	b _0802EC72\n\
	.align 2, 0\n\
_0802EC60: .4byte 0x0000012B\n\
_0802EC64: .4byte 0x00000216\n\
_0802EC68: .4byte 0x00000147\n\
_0802EC6C:\n\
	movs r0, #0xff\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
_0802EC72:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void nop_0802ec78(struct Zero* z) { return; }

static void onBuster(struct Zero* z);
static void onSaber(struct Zero* z);
static void onRod(struct Zero* z);
static void onShield(struct Zero* z);

void FUN_0802ec7c(struct Zero* z) {
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
  (seq[(z->unk_b4).attackState8[1]])(z);
}

static void buster_0(struct Zero* z) {
  s32 x = -PIXEL(36);
  s32 y = -PIXEL(16);
  bool8 xflip = ((z->s).flags >> 4);
  u8 ok = TRUE;
  Weapon* w = CreateBuster(z, x, y, xflip & ok);
  if (w == NULL) {
    (z->unk_b4).attackState8[0] = 0;
  } else {
    SetSpriteAnimation(z, MOTION(DM010_ZERO_BUSTER_DASH, 1));
    z->atkCooltime = 2;
    (z->unk_b4).attackState8[1] = ok;
    buster_1(z);
  }
}

static void buster_1(struct Zero* z) {
  u8* ct;
  motion_t m, expected;
  struct Zero_b4* b4 = &(z->unk_b4);

  if ((b4->status).weapons[0] == WEAPON_BUSTER) {
    (z->restriction).mainCharge = TRUE;
  } else {
    (z->restriction).subCharge = TRUE;
  }

  m = MOTION_VALUE(z);
  expected = MOTION(DM010_ZERO_BUSTER_DASH, 0x01);
  ct = &z->atkCooltime;
  if (m != expected) {
    GotoMotion(&z->s, expected, 0, *ct);
  }

  *ct = (z->s).motion.duration;
  if ((z->s).motion.duration < 2) {
    GotoMotion(&z->s, expected, 1, 4);
    *ct = 4;
    (z->unk_b4).attackState8[1] = 2;
  }
}

static void buster_2(struct Zero* z) {
  u8* ct;
  motion_t m, expected;
  struct Zero_b4* b4 = &(z->unk_b4);

  if ((b4->status).weapons[0] == WEAPON_BUSTER) {
    (z->restriction).mainCharge = TRUE;
  } else {
    (z->restriction).subCharge = TRUE;
  }

  m = MOTION_VALUE(z);
  expected = MOTION(DM010_ZERO_BUSTER_DASH, 0x01);
  ct = &z->atkCooltime;
  if (m != expected) {
    GotoMotion(&z->s, expected, 1, *ct);
  }

  *ct = (z->s).motion.duration;
  if ((z->s).motion.duration < 2) {
    GotoMotion(&z->s, expected, 2, 16);
    *ct = 16;
    (z->unk_b4).attackState8[1] = 3;
  }
}

static void buster_3(struct Zero* z) {
  bool8 ok;
  struct Zero_b4* b4;

  motion_t m = MOTION_VALUE(z);
  if (m != MOTION(DM010_ZERO_BUSTER_DASH, 1)) {
    GotoSpriteAnimation(z, MOTION(DM010_ZERO_BUSTER_DASH, 1), 2, z->atkCooltime);
  }

  b4 = &(z->unk_b4);
  z->atkCooltime--;
  if (z->atkCooltime == 0xFF) {
    (z->unk_b4).attackState8[0] = 0;
    SetSpriteAnimation(z, MOTION(DM003_ZERO_DASH, 0x00));
  }

  ok = IsAttackOK(z, &z->usingWeapon);
  if (ok) {
    u8 foot;
    if ((((z->input).raw & INPUT_DISABLED) == 0) && ((foot = (b4->status).foot, (foot == FOOT_CHIP_SHADOW) || (foot == FOOT_CHIP_ULTIMA)))) {
      LoadZeroPalette(&z->s, GetZeroColor(z));
      z->posture = POSTURE_DASH;
    }
    (z->unk_b4).attackState8[0] = 3;
    (z->unk_b4).attackState8[1] = 0;
    FUN_0802ec7c(z);
  }
}

// --------------------------------------------

static void handle_saber_input(struct Zero* z);
static void dash_saber(struct Zero* z);
static void gale_attack(struct Zero* z);
static void dash_rolling_saber(struct Zero* z);

// 0x0802eed0
static void onSaber(struct Zero* z) {
  static ZeroFunc const seq[] = {
      handle_saber_input,
      dash_saber,
      gale_attack,
      dash_rolling_saber,
  };

  struct Zero_b4* b4 = &(z->unk_b4);

  if ((z->restriction).b6) {
    (z->s).mode[2] = 0;
    onSaber_GroundIdle(z);
    return;
  }

  (z->restriction).move = TRUE;
  (z->restriction).shield = TRUE;
  if ((b4->status).weapons[0] == WEAPON_SABER) {
    (z->restriction).mainCharge = TRUE;
  } else {
    (z->restriction).subCharge = TRUE;
  }
  (seq[(z->unk_b4).attackState8[1]])(z);
}

// 0x0802ef2c
static void handle_saber_input(struct Zero* z) {
  u8 c;
  struct Zero_b4* b4 = &(z->unk_b4);

  if ((b4->status).weapons[0] == WEAPON_SABER) {
    c = GetWeaponCharge(z, FALSE);
  } else {
    c = GetWeaponCharge(z, TRUE);
  }

  if ((z->input).ultimateCommand_22c[1] == 3) {
    c = FULL_CHARGE;
  }

  if (c == FULL_CHARGE) {
    (z->restriction).move = TRUE;
    (z->restriction).shield = TRUE;
    (z->s).mode[2] = 0;
    (z->s).mode[3] = 0;
    (z->unk_b4).attackState8[1] = 4;
    (z->unk_b4).attackState8[2] = 0;
    charge_saber_ground(z);
  } else {
    if (((z->input).val & (DPAD_UP | DPAD_DOWN)) && (isElfUsed_2(z, ELF_MALTHAS))) {
      (z->unk_b4).attackState8[1] = 3;
      (z->unk_b4).attackState8[2] = 0;
      dash_rolling_saber(z);
    } else {
      struct Zero_b4* b4 = &(z->unk_b4);
      if (((b4->status).exSkill & (1 << EXSKILL_ID_GALE)) >> EXSKILL_ID_GALE) {
        (z->unk_b4).attackState8[1] = 2;
        (z->unk_b4).attackState8[2] = 0;
        gale_attack(z);
      } else {
        (z->unk_b4).attackState8[1] = 1;
        (z->unk_b4).attackState8[2] = 0;
        dash_saber(z);
      }
    }
  }
}

// 0x0802f008
NON_MATCH static void dash_saber(struct Zero* z) {
#if MODERN
  if ((z->unk_b4).attackState8[2] == 0) {
    SetSpriteAnimation(z, MOTION(DM023_ZERO_SABER_DASH, 0x00));
    z->atkCooltime = 16;
    (z->unk_b4).attackState8[2]++;

  } else {
    KeepMotion(z, MOTION(DM023_ZERO_SABER_DASH, 0x00));
    if ((z->unk_b4).attackState8[2] == 1) {
      if ((z->s).motion.duration < 2) {
        CreateWeaponSaber(z, 4);
        (z->unk_b4).attackState8[2]++;
      }
    } else if (IsSpriteAnimEnd(z)) {
      z->restriction.move = FALSE;
      (z->s).mode[1] = ZERO_GROUND, (z->s).mode[2] = 0, (z->s).mode[3] = 0;
      (z->unk_b4).attackState8[0] = 0;
    }
  }

  if (z->atkCooltime != 0) {
    z->atkCooltime--;
    s32 dx = CalcDx(z);
    s32 speed = (GetDashSpeed(z) - dx) * z->atkCooltime;
    if (speed < 0) {
      speed += 15;
    }
    (z->s).d.x = dx + (speed >> 4);

    if (!((z->s).flags & X_FLIP)) {
      (z->s).d.x = -(z->s).d.x;
    }
  }
#else
  INCCODE("asm/wip/dash_saber.inc");
#endif
}

// 0x0802f134
// atkCooltime へのアクセスがおかしい (それ以外は大丈夫そう)
NON_MATCH static void gale_attack(struct Zero* z) {
#if MODERN
  switch ((z->unk_b4).attackState8[2]) {
    case 0: {
      SetSpriteAnimation(z, MOTION(DM024_ZERO_GALE, 0));
      z->atkCooltime = 24;
      (z->unk_b4).attackState8[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 duration;
      KeepMotion(z, MOTION(DM024_ZERO_GALE, 0));
      duration = (z->s).motion.duration;
      if (duration < 2) {
        CreateWeaponSaber(z, 18);
        (z->unk_b4).attackState8[2]++;
      }
      break;
    }

    case 2: {
      KeepMotion(z, MOTION(DM024_ZERO_GALE, 0));
      if (z->atkCooltime < 9) {
        SetSpriteAnimation(z, MOTION(DM024_ZERO_GALE, 1));
        (z->unk_b4).attackState8[2]++;
      }
      break;
    }
    case 3: {
      if (IsSpriteAnimEnd(z)) {
        z->restriction.move = FALSE;
        (z->s).mode[1] = ZERO_GROUND, (z->s).mode[2] = 0, (z->s).mode[3] = 0;
        (z->unk_b4).attackState8[0] = 0;
      }
      break;
    }
  }
  if (z->atkCooltime > 0) {
    z->atkCooltime--;
    if ((z->s).flags & X_FLIP) {
      (z->s).d.x = CalcDx(z) + ((GetDashSpeed(z) - CalcDx(z)) * (s32)(z->atkCooltime)) / 24;
    } else {
      (z->s).d.x = -CalcDx(z) - ((GetDashSpeed(z) - CalcDx(z)) * (s32)(z->atkCooltime)) / 24;
    }
  }
#else
  INCCODE("asm/wip/gale_attack.inc");
#endif
}

NAKED static void dash_rolling_saber(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #4\n\
	adds r4, r0, #0\n\
	adds r5, r4, #0\n\
	adds r5, #0xee\n\
	ldrb r6, [r5]\n\
	cmp r6, #0\n\
	bne _0802F2DC\n\
	ldr r1, _0802F2D8 @ =0x00001A01\n\
	bl SetMotion\n\
	movs r1, #0x95\n\
	lsls r1, r1, #1\n\
	adds r0, r4, r1\n\
	strb r6, [r0]\n\
	adds r0, r4, #0\n\
	movs r1, #0x15\n\
	bl CreateWeaponSaber\n\
	ldrb r0, [r5]\n\
	adds r0, #1\n\
	strb r0, [r5]\n\
	b _0802F344\n\
	.align 2, 0\n\
_0802F2D8: .4byte 0x00001A01\n\
_0802F2DC:\n\
	adds r0, r4, #0\n\
	mov r1, sp\n\
	bl IsAttackOK\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _0802F2FE\n\
	mov r0, sp\n\
	ldrb r0, [r0]\n\
	cmp r0, #1\n\
	bne _0802F2FE\n\
	movs r0, #0x95\n\
	lsls r0, r0, #1\n\
	adds r1, r4, r0\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
_0802F2FE:\n\
	ldr r1, _0802F330 @ =0x00001A01\n\
	adds r0, r4, #0\n\
	bl KeepMotion\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #4\n\
	bne _0802F344\n\
	movs r1, #0x95\n\
	lsls r1, r1, #1\n\
	adds r5, r4, r1\n\
	ldrb r0, [r5]\n\
	cmp r0, #0\n\
	beq _0802F334\n\
	adds r0, r4, #0\n\
	movs r1, #0x2d\n\
	bl isElfUsed_2\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _0802F334\n\
	movs r0, #0\n\
	strb r0, [r5]\n\
	b _0802F344\n\
	.align 2, 0\n\
_0802F330: .4byte 0x00001A01\n\
_0802F334:\n\
	adds r2, r4, #0\n\
	adds r2, #0xed\n\
	movs r1, #0\n\
	movs r0, #1\n\
	strb r0, [r2]\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r1, [r0]\n\
_0802F344:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802F35A\n\
	adds r0, r4, #0\n\
	bl GetDashSpeed\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	b _0802F366\n\
_0802F35A:\n\
	adds r0, r4, #0\n\
	bl GetDashSpeed\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	rsbs r0, r0, #0\n\
_0802F366:\n\
	str r0, [r4, #0x5c]\n\
	add sp, #4\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

// --------------------------------------------

static void onRod(struct Zero* z) {
  (z->s).mode[2] = 0;
  (z->s).mode[3] = 0;
  recoilAttack(z);
  z->recoilJumpDx = GetDashSpeed(z);
}

// --------------------------------------------

static void onShield(struct Zero* z) {
  (z->s).mode[1] = 0;
  (z->s).mode[2] = 0;
  (z->s).mode[3] = 0;
  shieldAttack(z);
}
