#include "global.h"
#include "motion.h"
#include "overworld.h"
#include "sound.h"
#include "weapon.h"
#include "zero.h"

static void FUN_0802e324(struct Zero* z);
static void FUN_0802e338(struct Zero* z);
static void FUN_0802e3ac(struct Zero* z);
void FUN_0802e3b0(struct Zero* z);

static void onBuster(struct Zero* z);
static void onSaber(struct Zero* z);
static void onRod(struct Zero* z);
static void onShield(struct Zero* z);

void ZeroAttackGround_Walk(struct Zero* z) {
  static ZeroFunc const seq[] = {
      FUN_0802e324,
      FUN_0802e338,
      FUN_0802e3ac,
      FUN_0802e3b0,
  };
  (seq[(z->unk_b4).attackMode[0]])(z);
  return;
}

static void FUN_0802e324(struct Zero* z) {
  (z->unk_b4).attackMode[0] = 1;
  FUN_0802e338(z);
}

NAKED static void FUN_0802e338(struct Zero* z) {
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
	beq _0802E370\n\
	ldr r2, _0802E36C @ =0x0000012B\n\
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
	b _0802E392\n\
	.align 2, 0\n\
_0802E36C: .4byte 0x0000012B\n\
_0802E370:\n\
	ldr r0, _0802E39C @ =0x0000012B\n\
	adds r2, r4, r0\n\
	ldrb r1, [r2]\n\
	adds r0, r1, #0\n\
	cmp r0, #0xff\n\
	beq _0802E3A0\n\
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
_0802E392:\n\
	adds r0, r4, #0\n\
	bl FUN_0802e3b0\n\
	b _0802E3A6\n\
	.align 2, 0\n\
_0802E39C: .4byte 0x0000012B\n\
_0802E3A0:\n\
	movs r0, #0xff\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
_0802E3A6:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void FUN_0802e3ac(struct Zero* z) { return; };

void FUN_0802e3b0(struct Zero* z) {
  static ZeroFunc const weapon[] = {
      onBuster,
      onSaber,
      onRod,
      onShield,
  };
  (weapon[z->usingWeapon])(z);
}

// --------------------------------------------

static void walk_buster_0(struct Zero* z);
static void walk_buster_1(struct Zero* z);
static void walk_buster_2(struct Zero* z);
static void walk_buster_3(struct Zero* z);

static void onBuster(struct Zero* z) {
  static ZeroFunc const seq[] = {
      walk_buster_0,
      walk_buster_1,
      walk_buster_2,
      walk_buster_3,
  };
  (seq[(z->unk_b4).attackMode[1]])(z);
}

static void walk_buster_0(struct Zero* z) {
  struct Weapon* w = CreateBuster(z, -PIXEL(32), -PIXEL(18), ((z->s).flags >> 4) & 1);
  if (w == NULL) {
    (z->unk_b4).attackMode[0] = 0;
  } else {
    struct Zero_b4* b4 = &(z->unk_b4);
    if (*(u16*)&b4->prevMode == 0x100) {
      GotoMotion(&z->s, MOTION(DM009_ZERO_BUSTER_WALK, 0), (z->s).motion.cmdIdx, (z->s).motion.duration);
    } else {
      SetMotion(&z->s, MOTION(DM009_ZERO_BUSTER_WALK, 0));
    }
    z->atkCooltime = 2;
    (z->unk_b4).attackMode[1] = 1;
    walk_buster_1(z);
  }
}

static void walk_buster_1(struct Zero* z) {
  motion_t m;
  struct Zero_b4* b4 = &(z->unk_b4);

  if ((b4->status).mainWeapon == WEAPON_BUSTER) {
    (z->restriction).mainCharge = TRUE;
  } else {
    (z->restriction).subCharge = TRUE;
  }

  m = MOTION_VALUE(z);
  if (m != MOTION(DM009_ZERO_BUSTER_WALK, 0x00)) {
    GotoMotion(&z->s, MOTION(DM009_ZERO_BUSTER_WALK, 0x00), 0, 1);
  }

  z->atkCooltime--;
  if (z->atkCooltime == 0xFF) {
    (z->unk_b4).attackMode[1] = 2;
    GotoMotion(&z->s, MOTION(DM009_ZERO_BUSTER_WALK, 0x01), (z->s).motion.cmdIdx, (z->s).motion.duration);
    z->atkCooltime = 4;
  }
}

static void walk_buster_2(struct Zero* z) {
  motion_t m;
  struct Zero_b4* b4 = &(z->unk_b4);

  if ((b4->status).mainWeapon == WEAPON_BUSTER) {
    (z->restriction).mainCharge = TRUE;
  } else {
    (z->restriction).subCharge = TRUE;
  }

  m = MOTION_VALUE(z);
  if (m != MOTION(DM009_ZERO_BUSTER_WALK, 0x01)) {
    GotoMotion(&z->s, MOTION(DM009_ZERO_BUSTER_WALK, 0x01), 0, 1);
  }

  z->atkCooltime--;
  if (z->atkCooltime == 0xFF) {
    (z->unk_b4).attackMode[1] = 3;
    GotoMotion(&z->s, MOTION(DM009_ZERO_BUSTER_WALK, 0x02), (z->s).motion.cmdIdx, (z->s).motion.duration);
    z->atkCooltime = 16;
  }
}

static void walk_buster_3(struct Zero* z) {
  bool8 ok;

  motion_t m = MOTION_VALUE(z);
  if (m != MOTION(DM009_ZERO_BUSTER_WALK, 0x02)) {
    GotoMotion(&z->s, MOTION(DM009_ZERO_BUSTER_WALK, 0x02), 0, 1);
  }

  z->atkCooltime--;
  if (z->atkCooltime == 0xFF) {
    (z->unk_b4).attackMode[0] = 0;
    GotoMotion(&z->s, MOTION(DM002_ZERO_RUN, 0x00), (z->s).motion.cmdIdx, (z->s).motion.duration);
  }

  ok = IsAttackOK(z, &z->usingWeapon);
  if (ok) {
    (z->unk_b4).attackMode[0] = 3;
    (z->unk_b4).attackMode[1] = 0;
    FUN_0802e3b0(z);
  }
}

// --------------------------------------------

static void walk_saber_0(struct Zero* z);
static void walk_saber_1(struct Zero* z);
static void walk_saber_2(struct Zero* z);

static void onSaber(struct Zero* z) {
  static ZeroFunc const seq[] = {
      walk_saber_0,
      walk_saber_1,
      walk_saber_2,
  };

  struct Zero_b4* b4 = &(z->unk_b4);

  if ((z->restriction).b6) {
    (z->s).mode[2] = 0;
    onSaber_GroundIdle(z);
    return;
  }

  (z->restriction).shield = TRUE;
  if ((b4->status).mainWeapon == WEAPON_SABER) {
    (z->restriction).mainCharge = TRUE;
  } else {
    (z->restriction).subCharge = TRUE;
  }
  (seq[(z->unk_b4).attackMode[1]])(z);
}

static void walk_saber_0(struct Zero* z) {
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
    (z->restriction).move = TRUE;
    (z->restriction).shield = TRUE;
    (z->s).mode[2] = 0;
    (z->s).mode[3] = 0;
    (z->unk_b4).attackMode[1] = 4;
    (z->unk_b4).attackMode[2] = 0;
    charge_saber_ground(z);
  } else {
    (z->unk_b4).attackMode[1] = 1;
    (z->unk_b4).attackMode[2] = 0;
    walk_saber_1(z);
  }
}

static void walk_saber_1(struct Zero* z) {
  u8* ct;
  if ((z->unk_b4).attackMode[2] == 0) {
    GotoMotion(&z->s, MOTION(DM021_ZERO_SABER_RUN_1, 0x00), (z->s).motion.cmdIdx, (z->s).motion.duration);
    CreateWeaponSaber(z, SABER_UNK_03);
    ct = &z->atkCooltime;
    *ct = 2;
    (z->unk_b4).attackMode[2]++;
  } else {
    KeepMotion(z, MOTION(DM021_ZERO_SABER_RUN_1, 0x00));
    ct = &z->atkCooltime;
  }

  *ct = *ct - 1;
  if (*ct == 0xFF) {
    u8* p = &(z->unk_b4).attackMode[1];
    *p = 2;
    p++;
    *p = 0;
    walk_saber_2(z);
  }
}

static void walk_saber_2(struct Zero* z) {
  u8* ct;
  if ((z->unk_b4).attackMode[2] == 0) {
    GotoMotion(&z->s, MOTION(DM022_ZERO_SABER_RUN_2, 0x00), (z->s).motion.cmdIdx, (z->s).motion.duration);
    ct = &z->atkCooltime;
    *ct = 14;
    (z->unk_b4).attackMode[2]++;
  } else {
    KeepMotion(z, MOTION(DM022_ZERO_SABER_RUN_2, 0x00));
    ct = &z->atkCooltime;
  }

  *ct = *ct - 1;
  if (*ct == 0xFF) {
    (z->unk_b4).attackMode[0] = 0;
    GotoMotion(&z->s, MOTION(DM002_ZERO_RUN, 0x00), (z->s).motion.cmdIdx, (z->s).motion.duration);
  }
}

// --------------------------------------------

static void onRod(struct Zero* z) {
  (z->s).mode[2] = 0;
  (z->s).mode[3] = 0;
  recoilAttack(z);
}

// --------------------------------------------

static void walk_shield_0(struct Zero* z);
static void walk_shield_1(struct Zero* z);
static void walk_shield_2(struct Zero* z);
static void walk_shield_3(struct Zero* z);
static void walk_shield_4(struct Zero* z);
static void walk_shield_5(struct Zero* z);

static void onShield(struct Zero* z) {
  // clang-format off
  static ZeroFunc const seq[] = {
    walk_shield_0,
    walk_shield_1,
    walk_shield_2,
    walk_shield_3,
    walk_shield_4,
    walk_shield_5,
  };
  // clang-format on

  struct Zero_b4* b4 = &(z->unk_b4);

  if (((b4->status).mainWeapon != WEAPON_SHIELD) && ((b4->status).subWeapon != WEAPON_SHIELD)) {
    (z->unk_b4).attackMode[0] = 0;
    GotoMotion(&z->s, MOTION(DM002_ZERO_RUN, 0x00), (z->s).motion.cmdIdx, (z->s).motion.duration);
    return;
  }

  (z->restriction).dash = TRUE;
  (seq[(z->unk_b4).attackMode[1]])(z);
}

NAKED static void walk_shield_0(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	movs r7, #0\n\
	adds r5, r4, #0\n\
	adds r5, #0xb4\n\
	ldrb r0, [r5, #0xc]\n\
	cmp r0, #3\n\
	bne _0802E8C2\n\
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
	bne _0802E8E2\n\
	b _0802E8E6\n\
_0802E8C2:\n\
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
	beq _0802E8E6\n\
_0802E8E2:\n\
	movs r3, #0\n\
	b _0802E90C\n\
_0802E8E6:\n\
	ldr r1, _0802E948 @ =0x00000225\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0802E8F2\n\
	movs r3, #2\n\
_0802E8F2:\n\
	ldrh r1, [r5, #0x12]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802E90C\n\
	ldr r1, _0802E94C @ =0x0000022D\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0802E90C\n\
	movs r3, #2\n\
	movs r7, #1\n\
_0802E90C:\n\
	cmp r3, #2\n\
	bne _0802E992\n\
	adds r2, r4, #0\n\
	adds r2, #0xb4\n\
	ldrh r1, [r2, #0x12]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802E950\n\
	ldr r0, [r6]\n\
	movs r1, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0802E92E\n\
	cmp r7, #0\n\
	beq _0802E950\n\
_0802E92E:\n\
	adds r2, r4, #0\n\
	adds r2, #0xed\n\
	movs r1, #0\n\
	movs r0, #5\n\
	strb r0, [r2]\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r1, [r0]\n\
	adds r0, r4, #0\n\
	bl walk_shield_5\n\
	b _0802E9E2\n\
	.align 2, 0\n\
_0802E948: .4byte 0x00000225\n\
_0802E94C: .4byte 0x0000022D\n\
_0802E950:\n\
	ldrh r1, [r2, #0x12]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #3\n\
	ands r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x1a\n\
	cmp r1, #0\n\
	beq _0802E978\n\
	adds r2, r4, #0\n\
	adds r2, #0xed\n\
	movs r1, #0\n\
	movs r0, #4\n\
	strb r0, [r2]\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r1, [r0]\n\
	adds r0, r4, #0\n\
	bl walk_shield_4\n\
	b _0802E9E2\n\
_0802E978:\n\
	strb r1, [r4, #0xe]\n\
	strb r1, [r4, #0xf]\n\
	adds r2, r4, #0\n\
	adds r2, #0xed\n\
	movs r0, #3\n\
	strb r0, [r2]\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r1, [r0]\n\
	adds r0, r4, #0\n\
	bl shield_throw\n\
	b _0802E9E2\n\
_0802E992:\n\
	adds r0, r4, #0\n\
	movs r1, #0\n\
	bl IsAttackOK\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #2\n\
	bne _0802E9BA\n\
	adds r2, r4, #0\n\
	adds r2, #0xed\n\
	movs r1, #0\n\
	movs r0, #1\n\
	strb r0, [r2]\n\
	adds r0, r4, #0\n\
	adds r0, #0xee\n\
	strb r1, [r0]\n\
	adds r0, r4, #0\n\
	bl walk_shield_1\n\
	b _0802E9E2\n\
_0802E9BA:\n\
	adds r1, r4, #0\n\
	adds r1, #0xec\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	adds r0, r4, #0\n\
	adds r0, #0x71\n\
	movs r2, #0\n\
	ldrsb r2, [r0, r2]\n\
	lsls r2, r2, #0x10\n\
	lsrs r2, r2, #0x10\n\
	adds r0, #1\n\
	movs r3, #0\n\
	ldrsb r3, [r0, r3]\n\
	lsls r3, r3, #0x10\n\
	lsrs r3, r3, #0x10\n\
	adds r0, r4, #0\n\
	bl GotoMotion\n\
_0802E9E2:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

NAKED static void walk_shield_1(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	adds r2, r4, #0\n\
	adds r2, #0xb4\n\
	movs r0, #0x97\n\
	lsls r0, r0, #1\n\
	adds r1, r4, r0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldrb r1, [r4, #0x1e]\n\
	lsls r1, r1, #8\n\
	adds r0, r4, #0\n\
	adds r0, #0x70\n\
	ldrb r0, [r0]\n\
	orrs r0, r1\n\
	movs r5, #0xa8\n\
	lsls r5, r5, #6\n\
	cmp r0, r5\n\
	beq _0802EA40\n\
	ldrh r1, [r2, #0x34]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	cmp r1, r0\n\
	bne _0802EA38\n\
	adds r0, r4, #0\n\
	adds r0, #0x71\n\
	movs r2, #0\n\
	ldrsb r2, [r0, r2]\n\
	lsls r2, r2, #0x10\n\
	lsrs r2, r2, #0x10\n\
	adds r0, #1\n\
	movs r3, #0\n\
	ldrsb r3, [r0, r3]\n\
	lsls r3, r3, #0x10\n\
	lsrs r3, r3, #0x10\n\
	adds r0, r4, #0\n\
	adds r1, r5, #0\n\
	bl GotoMotion\n\
	b _0802EA40\n\
_0802EA38:\n\
	adds r0, r4, #0\n\
	adds r1, r5, #0\n\
	bl SetMotion\n\
_0802EA40:\n\
	adds r5, r4, #0\n\
	adds r5, #0xee\n\
	ldrb r0, [r5]\n\
	cmp r0, #0\n\
	bne _0802EA5A\n\
	adds r0, r4, #0\n\
	movs r1, #1\n\
	bl CreateWeaponShieldGuard\n\
	ldrb r0, [r5]\n\
	adds r0, #1\n\
	strb r0, [r5]\n\
	b _0802EA9A\n\
_0802EA5A:\n\
	movs r0, #0x94\n\
	lsls r0, r0, #1\n\
	adds r1, r4, r0\n\
	adds r0, r4, #0\n\
	bl IsAttackOK\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bne _0802EA84\n\
	adds r0, r4, #0\n\
	adds r0, #0xec\n\
	movs r2, #0\n\
	movs r1, #3\n\
	strb r1, [r0]\n\
	adds r0, #1\n\
	strb r2, [r0]\n\
	adds r0, r4, #0\n\
	bl FUN_0802e3b0\n\
	b _0802EA9A\n\
_0802EA84:\n\
	cmp r0, #2\n\
	beq _0802EA9A\n\
	adds r2, r4, #0\n\
	adds r2, #0xed\n\
	movs r1, #0\n\
	movs r0, #2\n\
	strb r0, [r2]\n\
	strb r1, [r5]\n\
	adds r0, r4, #0\n\
	bl walk_shield_2\n\
_0802EA9A:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

NAKED static void walk_shield_2(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	adds r5, r4, #0\n\
	adds r5, #0xee\n\
	ldrb r0, [r5]\n\
	cmp r0, #0\n\
	bne _0802EADA\n\
	ldr r1, _0802EB14 @ =0x00002A01\n\
	adds r0, r4, #0\n\
	adds r0, #0x71\n\
	movs r2, #0\n\
	ldrsb r2, [r0, r2]\n\
	lsls r2, r2, #0x10\n\
	lsrs r2, r2, #0x10\n\
	adds r0, #1\n\
	movs r3, #0\n\
	ldrsb r3, [r0, r3]\n\
	lsls r3, r3, #0x10\n\
	lsrs r3, r3, #0x10\n\
	adds r0, r4, #0\n\
	bl GotoMotion\n\
	ldr r0, _0802EB18 @ =0x00000129\n\
	adds r1, r4, r0\n\
	movs r0, #5\n\
	strb r0, [r1]\n\
	ldrb r0, [r5]\n\
	adds r0, #1\n\
	strb r0, [r5]\n\
_0802EADA:\n\
	movs r0, #0x92\n\
	lsls r0, r0, #1\n\
	adds r2, r4, r0\n\
	ldrb r0, [r2]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	movs r0, #0x94\n\
	lsls r0, r0, #1\n\
	adds r1, r4, r0\n\
	adds r0, r4, #0\n\
	bl IsAttackOK\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
	cmp r2, #0\n\
	beq _0802EB1C\n\
	adds r0, r4, #0\n\
	adds r0, #0xec\n\
	movs r2, #0\n\
	movs r1, #3\n\
	strb r1, [r0]\n\
	adds r0, #1\n\
	strb r2, [r0]\n\
	adds r0, r4, #0\n\
	bl FUN_0802e3b0\n\
	b _0802EB52\n\
	.align 2, 0\n\
_0802EB14: .4byte 0x00002A01\n\
_0802EB18: .4byte 0x00000129\n\
_0802EB1C:\n\
	ldr r0, _0802EB58 @ =0x00000129\n\
	adds r1, r4, r0\n\
	ldrb r0, [r1]\n\
	subs r0, #1\n\
	strb r0, [r1]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _0802EB52\n\
	adds r0, r4, #0\n\
	adds r0, #0xec\n\
	strb r2, [r0]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	subs r0, #0x7b\n\
	movs r2, #0\n\
	ldrsb r2, [r0, r2]\n\
	lsls r2, r2, #0x10\n\
	lsrs r2, r2, #0x10\n\
	adds r0, #1\n\
	movs r3, #0\n\
	ldrsb r3, [r0, r3]\n\
	lsls r3, r3, #0x10\n\
	lsrs r3, r3, #0x10\n\
	adds r0, r4, #0\n\
	bl GotoMotion\n\
_0802EB52:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0802EB58: .4byte 0x00000129\n\
 .syntax divided\n");
}

static void walk_shield_3(struct Zero* z) {
  (z->s).mode[2] = 0;
  (z->s).mode[3] = 0;
  shield_throw(z);
}

static void walk_shield_4(struct Zero* z) {
  (z->s).mode[2] = 0;
  (z->s).mode[3] = 0;
  shield_0802e1c8(z);
}

static void walk_shield_5(struct Zero* z) {
  (z->s).mode[2] = 0;
  (z->s).mode[3] = 0;
  zero_shield_0802e268(z);
}
