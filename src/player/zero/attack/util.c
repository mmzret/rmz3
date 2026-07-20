#include "global.h"
#include "mod.h"
#include "player/zero.h"
#include "weapon.h"
#include "zero.h"

typedef bool8 (*WeaponOKFunc)(struct Zero*);

static bool8 isBusterOK(struct Zero* z);
static bool8 isSaberOK(void* _ UNUSED);
static bool8 isRodOK(void* _ UNUSED);
static bool8 isShieldOK(struct Zero* z);

static const WeaponOKFunc sWeaponOKTable[4] = {
    (void*)isBusterOK,  // 4連射未満か
    (void*)isSaberOK,   // 常にOK
    (void*)isRodOK,     // 常にOK
    (void*)isShieldOK,  // シールドブーメランを構えているか
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
  z->saberSmashElecCount = 0;
  z->rodToggle = 0;
}

NON_MATCH bool8 IsAttackOK(struct Zero* z, weapon_t* w) {
#if MODERN
  weapon_t mw, sw;
  struct Zero_b4* b4;
  u8 result = 0;
  weapon_t weapon = WEAPON_BUSTER;
  if (w != NULL) {
    weapon = w[0];
  }

  b4 = &z->unk_b4;
  mw = (b4->status).weapons[0];
  if (mw == WEAPON_SHIELD) {
    if ((z->input).val & ZERO_INPUT_PRESS_MAIN_WEAPON) {
      if (w != NULL) {
        w[0] = WEAPON_SHIELD;
      }
      result = 1;

    } else if (((z->input).val & ZERO_INPUT_MAIN_WEAPON) && (b4->status).charge[0]) {
      if (w != NULL) {
        w[0] = WEAPON_SHIELD;
      }
      result = 2;
    }

  } else if ((z->input).val & ZERO_INPUT_PRESS_MAIN_WEAPON) {
    if (w != NULL) {
      w[0] = mw;
    }
    if ((sWeaponOKTable[mw])(z)) {
      return 1;
    }
  }

  sw = (b4->status).weapons[1];
  if (mw != sw) {
    if (sw == WEAPON_SHIELD) {
      if ((z->input).val & ZERO_INPUT_PRESS_SUB_WEAPON) {
        if (w != NULL) {
          w[0] = WEAPON_SHIELD;
        }
        if ((sWeaponOKTable[WEAPON_SHIELD])(z)) {
          return 1;
        }
      } else if (((z->input).val & ZERO_INPUT_SUB_WEAPON) && (b4->status).charge[1]) {
        if (w != NULL) {
          w[0] = WEAPON_SHIELD;
        }
        if ((sWeaponOKTable[WEAPON_SHIELD])(z)) {
          return 2;
        }
      }

    } else if ((z->input).val & ZERO_INPUT_PRESS_SUB_WEAPON) {
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
    if (z->bulletCount > 3) return FALSE;
  } else {
    if (z->bulletCount > 2) return FALSE;
  }
  return TRUE;
}

static bool8 isSaberOK(void* _) { return TRUE; }
static bool8 isRodOK(void* _) { return TRUE; }

static bool8 isShieldOK(struct Zero* z) {
  if (((&z->unk_b4)->status).weapons[0] == WEAPON_SHIELD) {
    if ((z->restriction).mainCharge) {
      return FALSE;
    }
  } else if ((z->restriction).subCharge) {
    return FALSE;
  }

  if ((z->input).raw & INPUT_DISABLED) {
    return FALSE;
  }
  return TRUE;
}

// 0x0803413c
NON_MATCH Weapon* CreateBuster(struct Zero* z, s32 x, s32 y, bool8 isDirRight) {
#if MODERN
  u8 kind;
  Coords32 c;
  Weapon* w;
  u8* tmp;
  if (((&z->unk_b4)->status).weapons[0] == WEAPON_BUSTER) {
    kind = GetWeaponCharge(z, FALSE);
  } else {
    kind = GetWeaponCharge(z, TRUE);
  }

  if ((kind != FULL_CHARGE) && (((z->input).ultimateCommand_224)[1] == 3)) {
    if ((z->s).mode[1] == ZERO_LADDER) {
      SET_PLAYER_XFLIP(z, (z->input).ultimateCommand_224[2]);
      isDirRight = (z->input).ultimateCommand_224[2];
    }
    kind = SEMI_CHARGE;
    ((z->input).ultimateCommand_224)[1] = 0;
  }
  if (((z->input).ultimateCommand_227)[1] == 6) {
    if ((z->s).mode[1] == ZERO_LADDER) {
      SET_PLAYER_XFLIP(z, (z->input).ultimateCommand_227[2]);
      isDirRight = (z->input).ultimateCommand_227[2];
    }
    kind = FULL_CHARGE;
    ((z->input).ultimateCommand_227)[1] = 0;
  }

  if (isDirRight) x = -x;
  if (kind == FULL_CHARGE) {
    u8 elem = ((&z->unk_b4)->status).element;
    switch (elem) {
      case ELEMENT_NONE: {
        if (((&z->unk_b4)->status).exSkill & (1 << EXSKILL_ID_LASER)) kind = 3;
        break;
      }
      case ELEMENT_FLAME: {
        if (((&z->unk_b4)->status).exSkill & (1 << EXSKILL_ID_BURST)) kind = 4;
        break;
      }
      case ELEMENT_ICE: {
        if (((&z->unk_b4)->status).exSkill & (1 << EXSKILL_ID_BLIZZ)) kind = 5;
        break;
      }
      case ELEMENT_THUNDER:
      default: {
        break;
      }
    }
  }

  c.x = x, c.y = y;
  w = CreateWeaponBuster(z, &c, kind, isDirRight, FALSE);
  if (((&z->unk_b4)->status).element == ELEMENT_THUNDER) {
    if (((&z->unk_b4)->status).exSkill & (1 << EXSKILL_ID_VSHOT)) {
      CreateWeaponBuster(z, &c, kind, isDirRight, TRUE);
    }
  }
  return w;
#else
  INCCODE("asm/wip/CreateBuster.inc");
#endif
}

void KeepMotion(struct Zero* z, motion_t m) {
  motion_t cur = MOTION_VALUE(z);
  if ((cur != m) && (z->prevMotion == m)) {
    GotoMotion(&z->s, m, z->motionCmdIdx, z->motionDuration);
  }
}

static const u8 sFullChargeBorder[3] = {2 * SECOND, SECOND + 30, SECOND};  // idx is ChargeSpeed
static const u8 sSemiChargeBorder[3] = {40, 30, 20};                       // idx is ChargeSpeed

NON_MATCH u8 GetWeaponCharge(struct Zero* z, bool8 isSubWeapon) {
#if MODERN
  u8 frame, speed;
  bool32 isNotShield;
  struct Zero_b4* b4;

  if (!isSubWeapon) {
    b4 = (&z->unk_b4);
    frame = z->mainChargeFrame;
    isNotShield = (b4->status).weapons[0] != WEAPON_SHIELD;
  } else {
    b4 = (&z->unk_b4);
    frame = z->subChargeFrame;
    isNotShield = (b4->status).weapons[1] != WEAPON_SHIELD;
  }

  speed = 0;
  if (isNotShield) {
    if ((b4->status).head == HEAD_CHIP_QKCHARGE) speed = 1;
    if (isElfUsed_2(z, ELF_CLOKKLE)) speed++;
    if (((b4->status).body != BODY_CHIP_NONE) && (speed == 2)) speed = 1;
  }

  if (frame >= sFullChargeBorder[speed]) return FULL_CHARGE;
  if (frame >= sSemiChargeBorder[speed]) return SEMI_CHARGE;
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
  if ((b4->status).weapons[0] == WEAPON_ROD) {
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
  if (FLAG(gSystemSavedata.flags, MOD_BUSTER_ATK3)) return bonus + 3;
  if (FLAG(gSystemSavedata.flags, MOD_BUSTER_ATK2)) return bonus + 2;
  if (FLAG(gSystemSavedata.flags, MOD_BUSTER_ATK1)) return bonus + 1;
  return bonus;
}

u8 CalcSaberBonus(struct Zero* z) {
  u8 bonus = isElfUsed_2(z, ELF_SABRAS) != 0;
  if (FLAG(gSystemSavedata.flags, MOD_SABER_ATK3)) return bonus + 3;
  if (FLAG(gSystemSavedata.flags, MOD_SABER_ATK2)) return bonus + 2;
  if (FLAG(gSystemSavedata.flags, MOD_SABER_ATK1)) return bonus + 1;
  return bonus;
}

// エルフや改造カードなどでリコイルロッドの攻撃力がどれだけ上がっているかを求める
u8 CalcRodBonus(struct Zero* z) {
  u8 bonus = isElfUsed_2(z, ELF_RODERAS) != 0;
  if (FLAG(gSystemSavedata.flags, MOD_ROD_ATK3)) return bonus + 3;
  if (FLAG(gSystemSavedata.flags, MOD_ROD_ATK2)) return bonus + 2;
  if (FLAG(gSystemSavedata.flags, MOD_ROD_ATK1)) return bonus + 1;
  return bonus;
}

u8 CalcShieldBonus(struct Zero* z) {
  u8 bonus = isElfUsed_2(z, ELF_BOOMERAS) != 0;
  if (FLAG(gSystemSavedata.flags, MOD_SHIELD_ATK3)) return bonus + 3;
  if (FLAG(gSystemSavedata.flags, MOD_SHIELD_ATK2)) return bonus + 2;
  if (FLAG(gSystemSavedata.flags, MOD_SHIELD_ATK1)) return bonus + 1;
  return bonus;
}

// 0x08034520
u8 GetBeeAtkBoost(void) {
  if (FLAG(gSystemSavedata.flags, MOD_BEE_ATK3)) return 3;
  if (FLAG(gSystemSavedata.flags, MOD_BEE_ATK2)) return 2;
  if (FLAG(gSystemSavedata.flags, MOD_BEE_ATK1)) return 1;
  return 0;
}

// 0x0803455c
u8 GetArchimAtkBoost(void) {
  if (FLAG(gSystemSavedata.flags, MOD_ARCHIM_ATK4)) return 4;
  if (FLAG(gSystemSavedata.flags, MOD_ARCHIM_ATK3)) return 3;
  if (FLAG(gSystemSavedata.flags, MOD_ARCHIM_ATK2)) return 2;
  if (FLAG(gSystemSavedata.flags, MOD_ARCHIM_ATK1)) return 1;
  return 0;
}

// ElfIDで指定したエルフの効力を受けているか IsElfUsed と同じ関数に見える
NON_MATCH bool8 isElfUsed_2(struct Zero* z, cyberelf_t elfID) {
#if MODERN
  return IsElfUsed(z, elfID);
#else
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r3, r0, #0\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	ldr r0, _080345E4 @ =gElfAvailability\n\
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
_080345E4: .4byte gElfAvailability\n\
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
