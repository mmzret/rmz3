#include "global.h"
#include "weapon.h"
#include "zero.h"

static bool8 isBusterOK(struct Zero* z);
static bool8 isSaberOK(struct Zero* z);
static bool8 isRodOK(struct Zero* z);
static bool8 isShieldOK(struct Zero* z);

static const WeaponOKFunc sWeaponOKTable[4] = {
    isBusterOK,  // 4連射未満か
    isSaberOK,   // 常にOK
    isRodOK,     // 常にOK
    isShieldOK,  // シールドブーメランを構えているか
};

void FUN_08033ed4(struct Zero* z) {
  z->usingWeapon = WEAPON_BUSTER;
  z->restriction.move = FALSE;
  z->restriction.dash = FALSE;
  z->restriction.shield = FALSE;
  z->restriction.b3 = FALSE;
  z->forceWeapon = 0xFF;
  z->bulletCount = 0;
  z->unk_137 = 0;
  z->unk_13a = 0;
  z->rodToggle = 0;
}

WIP bool8 IsAttackOK(struct Zero* z, weapon_t* w) {
#if MODERN
  weapon_t mw, sw;
  struct Zero_b4* b4;
  u8 result = 0;
  weapon_t weapon = WEAPON_BUSTER;
  if (w != NULL) {
    weapon = w[0];
  }

  b4 = &z->unk_b4;
  mw = (b4->status).mainWeapon;
  if (mw == WEAPON_SHIELD) {
    if (z->zeroInput & ZERO_INPUT_PRESS_MAIN_WEAPON) {
      if (w != NULL) {
        w[0] = WEAPON_SHIELD;
      }
      result = 1;

    } else if ((z->zeroInput & ZERO_INPUT_MAIN_WEAPON) && (b4->status).charge[0]) {
      if (w != NULL) {
        w[0] = WEAPON_SHIELD;
      }
      result = 2;
    }

  } else if (z->zeroInput & ZERO_INPUT_PRESS_MAIN_WEAPON) {
    if (w != NULL) {
      w[0] = mw;
    }
    if ((sWeaponOKTable[mw])(z)) {
      return 1;
    }
  }

  sw = (b4->status).subWeapon;
  if (mw != sw) {
    if (sw == WEAPON_SHIELD) {
      if (z->zeroInput & ZERO_INPUT_PRESS_SUB_WEAPON) {
        if (w != NULL) {
          w[0] = WEAPON_SHIELD;
        }
        if ((sWeaponOKTable[WEAPON_SHIELD])(z)) {
          return 1;
        }
      } else if ((z->zeroInput & ZERO_INPUT_SUB_WEAPON) && (b4->status).charge[1]) {
        if (w != NULL) {
          w[0] = WEAPON_SHIELD;
        }
        if ((sWeaponOKTable[WEAPON_SHIELD])(z)) {
          return 2;
        }
      }

    } else if (z->zeroInput & ZERO_INPUT_PRESS_SUB_WEAPON) {
      if (w != NULL) {
        w[0] = sw;
      }
      if ((sWeaponOKTable[sw])(z)) {
        return 1;
      }
    }
  }

  if (result) {
    if (w != NULL) {
      if ((sWeaponOKTable[w[0]])(z)) {
        return result;
      }
      result = 0;
    }
    if (result) {
      return result;
    }
  }
  if (w != NULL) {
    w[0] = weapon;
  }
  return 0;
#else
  INCCODE("asm/wip/IsAttackOK.inc");
#endif
}

static bool8 isBusterOK(struct Zero* z) {
  if (isElfUsed_2(z, ELF_SHUTHAS)) {
    if (z->bulletCount > 3) {
      return FALSE;
    }
  } else {
    if (z->bulletCount > 2) {
      return FALSE;
    }
  }
  return TRUE;
}

static bool8 isSaberOK(struct Zero* z) { return TRUE; }

static bool8 isRodOK(struct Zero* z) { return TRUE; }

static bool8 isShieldOK(struct Zero* z) {
  if (((&z->unk_b4)->status).mainWeapon == WEAPON_SHIELD) {
    if ((z->restriction).mainCharge) {
      return FALSE;
    }
  } else if ((z->restriction).subCharge) {
    return FALSE;
  }

  if (z->last & INPUT_DISABLED) {
    return FALSE;
  }
  return TRUE;
}

NAKED struct Weapon* CreateBuster(struct Zero* z, s32 x, s32 y, bool8 isDirRight) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	sub sp, #0xc\n\
	adds r5, r0, #0\n\
	mov r8, r1\n\
	mov sb, r2\n\
	lsls r3, r3, #0x18\n\
	lsrs r6, r3, #0x18\n\
	adds r0, #0xb4\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #0\n\
	bne _0803415E\n\
	adds r0, r5, #0\n\
	movs r1, #0\n\
	b _08034162\n\
_0803415E:\n\
	adds r0, r5, #0\n\
	movs r1, #1\n\
_08034162:\n\
	bl GetWeaponCharge\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #2\n\
	beq _080341D8\n\
	ldr r1, _080341C0 @ =0x00000225\n\
	adds r0, r5, r1\n\
	ldrb r1, [r0]\n\
	adds r7, r0, #0\n\
	cmp r1, #3\n\
	bne _080341D8\n\
	ldrb r0, [r5, #0xd]\n\
	cmp r0, #3\n\
	bne _080341D2\n\
	ldr r0, _080341C4 @ =0x00000226\n\
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
	beq _080341C8\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _080341CE\n\
	.align 2, 0\n\
_080341C0: .4byte 0x00000225\n\
_080341C4: .4byte 0x00000226\n\
_080341C8:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080341CE:\n\
	strb r0, [r5, #0xa]\n\
	ldrb r6, [r4]\n\
_080341D2:\n\
	movs r4, #1\n\
	movs r0, #0\n\
	strb r0, [r7]\n\
_080341D8:\n\
	movs r1, #0x8a\n\
	lsls r1, r1, #2\n\
	adds r0, r5, r1\n\
	ldrb r1, [r0]\n\
	adds r7, r0, #0\n\
	cmp r1, #6\n\
	bne _08034240\n\
	ldrb r0, [r5, #0xd]\n\
	cmp r0, #3\n\
	bne _0803423A\n\
	ldr r0, _0803422C @ =0x00000229\n\
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
	beq _08034230\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _08034236\n\
	.align 2, 0\n\
_0803422C: .4byte 0x00000229\n\
_08034230:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_08034236:\n\
	strb r0, [r5, #0xa]\n\
	ldrb r6, [r4]\n\
_0803423A:\n\
	movs r4, #2\n\
	movs r0, #0\n\
	strb r0, [r7]\n\
_08034240:\n\
	lsls r0, r6, #0x18\n\
	adds r3, r0, #0\n\
	cmp r3, #0\n\
	beq _0803424E\n\
	mov r1, r8\n\
	rsbs r0, r1, #0\n\
	b _08034250\n\
_0803424E:\n\
	mov r0, r8\n\
_08034250:\n\
	str r0, [sp, #4]\n\
	mov r1, sb\n\
	str r1, [sp, #8]\n\
	adds r6, r5, #0\n\
	adds r6, #0xb4\n\
	cmp r4, #2\n\
	bne _080342A0\n\
	ldrb r0, [r6, #0xe]\n\
	cmp r0, #1\n\
	beq _080342A0\n\
	cmp r0, #1\n\
	bgt _0803426E\n\
	cmp r0, #0\n\
	beq _08034278\n\
	b _080342A0\n\
_0803426E:\n\
	cmp r0, #2\n\
	beq _08034286\n\
	cmp r0, #3\n\
	beq _08034294\n\
	b _080342A0\n\
_08034278:\n\
	ldrh r1, [r6, #0x12]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080342A0\n\
	movs r4, #3\n\
	b _080342A0\n\
_08034286:\n\
	ldrh r1, [r6, #0x12]\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080342A0\n\
	movs r4, #4\n\
	b _080342A0\n\
_08034294:\n\
	ldrh r1, [r6, #0x12]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080342A0\n\
	movs r4, #5\n\
_080342A0:\n\
	lsrs r7, r3, #0x18\n\
	movs r0, #0\n\
	str r0, [sp]\n\
	adds r0, r5, #0\n\
	add r1, sp, #4\n\
	adds r2, r4, #0\n\
	adds r3, r7, #0\n\
	bl CreateWeaponBuster\n\
	mov r8, r0\n\
	ldrb r2, [r6, #0xe]\n\
	cmp r2, #1\n\
	bne _080342D2\n\
	ldrh r1, [r6, #0x12]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080342D2\n\
	str r2, [sp]\n\
	adds r0, r5, #0\n\
	add r1, sp, #4\n\
	adds r2, r4, #0\n\
	adds r3, r7, #0\n\
	bl CreateWeaponBuster\n\
_080342D2:\n\
	mov r0, r8\n\
	add sp, #0xc\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

void KeepMotion(struct Zero* z, motion_t m) {
  motion_t cur = MOTION_VALUE(z);
  if ((cur != m) && (z->prevMotion == m)) {
    GotoMotion(&z->s, m, z->motionCmdIdx, z->motionDuration);
  }
}

static const u8 sFullChargeBorder[3] = {2 * SECOND, SECOND + 30, SECOND};  // idx is ChargeSpeed
static const u8 sSemiChargeBorder[3] = {40, 30, 20};                       // idx is ChargeSpeed

WIP u8 GetWeaponCharge(struct Zero* z, bool8 isSubWeapon) {
#if MODERN
  u8 frame, speed;
  weapon_t w;
  struct Zero_b4* b4 = &(z->unk_b4);

  if (!isSubWeapon) {
    frame = z->mainChargeFrame;
    w = (b4->status).mainWeapon;
  } else {
    frame = z->subChargeFrame;
    w = (b4->status).subWeapon;
  }

  speed = 0;
  if (w != WEAPON_SHIELD) {
    if ((b4->status).head == HEAD_CHIP_QKCHARGE) {
      speed++;
    }
    if (isElfUsed_2(z, ELF_CLOKKLE)) {
      speed++;
    }
    if (((b4->status).body != BODY_CHIP_NONE) && (speed == 2)) {
      speed = 1;
    }
  }

  if (frame >= sFullChargeBorder[speed]) {
    return FULL_CHARGE;
  }
  if (frame >= sSemiChargeBorder[speed]) {
    return SEMI_CHARGE;
  }
  return NO_CHARGE;
#else
  INCCODE("asm/wip/GetWeaponCharge.inc");
#endif
}

bool8 Is1000Slash(struct Zero* z) {
  u8 val;
  struct Zero_b4* b4 = &(z->unk_b4);
  if (((b4->status).exSkill & (1 << EXSKILL_ID_THOUSAND)) == 0) {
    return FALSE;
  }

  if ((b4->status).mainWeapon == WEAPON_ROD) {
    val = CountRodButton(z, FALSE);
  } else {
    val = CountRodButton(z, TRUE);
  }
  if (val < 3) {
    return FALSE;
  }

  return TRUE;
}

u8 CalcBusterBonus(struct Zero* z) {
  u8 bonus = isElfUsed_2(z, ELF_BUSRAS) != 0;
  if (gSystemSavedataManager.mods[9] & (1 << 4)) {
    return bonus + 3;
  }
  if (gSystemSavedataManager.mods[4] & (1 << 5)) {
    return bonus + 2;
  }
  if (gSystemSavedataManager.mods[4] & (1 << 2)) {
    return bonus + 1;
  }
  return bonus;
}

u8 CalcSaberBonus(struct Zero* z) {
  u8 bonus = isElfUsed_2(z, ELF_SABRAS) != 0;
  if (gSystemSavedataManager.mods[12] & (1 << 1)) {
    return bonus + 3;
  }
  if (gSystemSavedataManager.mods[11] & (1 << 1)) {
    return bonus + 2;
  }
  if (gSystemSavedataManager.mods[1] & (1 << 2)) {
    return bonus + 1;
  }
  return bonus;
}

// エルフや改造カードなどでリコイルロッドの攻撃力がどれだけ上がっているかを求める
u8 CalcRodBonus(struct Zero* z) {
  u8 bonus = isElfUsed_2(z, ELF_RODERAS) != 0;
  if (gSystemSavedataManager.mods[10] & (1 << 5)) {
    return bonus + 3;
  }
  if (gSystemSavedataManager.mods[6] & (1 << 7)) {
    return bonus + 2;
  }
  if (gSystemSavedataManager.mods[3] & (1 << 1)) {
    return bonus + 1;
  }
  return bonus;
}

u8 CalcShieldBonus(struct Zero* z) {
  u8 bonus = isElfUsed_2(z, ELF_BOOMERAS) != 0;
  if (gSystemSavedataManager.mods[8] & (1 << 3)) {
    return bonus + 3;
  }
  if (gSystemSavedataManager.mods[6] & (1 << 2)) {
    return bonus + 2;
  }
  if (gSystemSavedataManager.mods[3] & (1 << 6)) {
    return bonus + 1;
  }
  return bonus;
}

u8 FUN_08034520(void) {
  if (gSystemSavedataManager.mods[8] & (1 << 7)) {
    return 3;
  }
  if (gSystemSavedataManager.mods[6] & (1 << 0)) {
    return 2;
  }
  if (gSystemSavedataManager.mods[3] & (1 << 7)) {
    return 1;
  }
  return 0;
}

u8 FUN_0803455c(void) {
  if (gSystemSavedataManager.mods[11] & (1 << 0)) {
    return 4;
  }
  if (gSystemSavedataManager.mods[9] & (1 << 0)) {
    return 3;
  }
  if (gSystemSavedataManager.mods[5] & (1 << 5)) {
    return 2;
  }
  if (gSystemSavedataManager.mods[2] & (1 << 2)) {
    return 1;
  }
  return 0;
}

// ElfIDで指定したエルフの効力を受けているか IsElfUsed と同じ関数に見える
WIP bool8 isElfUsed_2(struct Zero* z, cyberelf_t elfID) {
#if MODERN
  return IsElfUsed(z, elfID);
#else
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r3, r0, #0\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	ldr r0, _080345E4 @ =gUnlockedElfPtr\n\
	ldr r0, [r0]\n\
	adds r0, r0, r1\n\
	ldrb r2, [r0]\n\
	movs r0, #1\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _080345EC\n\
	adds r4, r3, #0\n\
	adds r4, #0xb4\n\
	ldr r5, _080345E8 @ =0x00000231\n\
	adds r0, r3, r5\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _080345DE\n\
	movs r0, #2\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _080345DE\n\
	ldrb r0, [r4]\n\
	cmp r0, r1\n\
	beq _080345DE\n\
	ldrb r0, [r4, #1]\n\
	cmp r0, r1\n\
	bne _080345EC\n\
_080345DE:\n\
	movs r0, #1\n\
	b _080345EE\n\
	.align 2, 0\n\
_080345E4: .4byte gUnlockedElfPtr\n\
_080345E8: .4byte 0x00000231\n\
_080345EC:\n\
	movs r0, #0\n\
_080345EE:\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
#endif
}
