#include "collision.h"
#include "cyberelf.h"
#include "global.h"
#include "mission.h"
#include "weapon.h"
#include "zero.h"

#define PUTITED_DAMAGE 8

void ClearZeroStatus(struct ZeroStatus *p) {
  p->mainWeapon = WEAPON_BUSTER;
  p->subWeapon = WEAPON_SABER;
  p->element = 0;
  (p->asset).satelites[0] = ELF_NONE;
  (p->asset).satelites[1] = ELF_NONE;
  p->head = HEAD_CHIP_NONE;
  p->body = BODY_CHIP_NONE;
  p->foot = FOOT_CHIP_NONE;
  p->exSkill = 0;
  p->unlockedWeapon = ((1 << WEAPON_BUSTER) | (1 << WEAPON_SABER));
  p->unlockedHead = (1 << HEAD_CHIP_NONE);
  p->unlockedBody = (1 << BODY_CHIP_NONE);
  p->unlockedFoot = (1 << FOOT_CHIP_NONE);
  p->unlockedExSkill = 0;
  (p->keyMap).keys.jump = A_BUTTON;
  (p->keyMap).keys.dash = L_BUTTON;
  (p->keyMap).keys.main = B_BUTTON;
  (p->keyMap).keys.sub = R_BUTTON;
  (p->keyMap).btnMode = 0;
  (p->keyMap).attackMode = 0;
  (p->keyMap).unk_a = 0;
  p->charge[0] = 0;
  p->charge[1] = 0;
  (p->asset).EC = 0;
  (p->asset).subtankHP[0] = 0xFF;
  (p->asset).subtankHP[1] = 0xFF;
  (p->asset).subtankHP[2] = 0xFF;
  (p->asset).subtankHP[3] = 0xFF;
  (p->asset).fusions = 0;
  p->maxHP = 64;
  p->dying = FALSE;
  p->menuZeroColor = MZC_NORMAL;
}

void ClearZeroStatusHard(struct ZeroStatus *p) {
  p->mainWeapon = WEAPON_BUSTER;
  p->subWeapon = WEAPON_SABER;
  p->element = 0;
  (p->asset).satelites[0] = ELF_NONE;
  (p->asset).satelites[1] = ELF_NONE;
  p->head = HEAD_CHIP_NONE;
  p->body = BODY_CHIP_NONE;
  p->foot = FOOT_CHIP_NONE;
  p->exSkill = 0;
  p->unlockedWeapon = ((1 << WEAPON_BUSTER) | (1 << WEAPON_SABER));
  p->unlockedHead = (1 << HEAD_CHIP_NONE);
  p->unlockedBody = (1 << BODY_CHIP_NONE);
  p->unlockedFoot = (1 << FOOT_CHIP_NONE);
  p->unlockedExSkill = 0;
  (p->keyMap).keys.jump = A_BUTTON;
  (p->keyMap).keys.dash = L_BUTTON;
  (p->keyMap).keys.main = B_BUTTON;
  (p->keyMap).keys.sub = R_BUTTON;
  (p->keyMap).btnMode = 0;
  (p->keyMap).attackMode = 0;
  (p->keyMap).unk_a = 0;
  p->charge[0] = 0;
  p->charge[1] = 0;
  (p->asset).EC = 0;
  (p->asset).subtankHP[0] = 0xFF;
  (p->asset).subtankHP[1] = 0xFF;
  (p->asset).subtankHP[2] = 0xFF;
  (p->asset).subtankHP[3] = 0xFF;
  (p->asset).fusions = 0;
  p->maxHP = 64;
  p->dying = FALSE;
  p->menuZeroColor = MZC_HARD;
}

void ClearZeroStatusUltimate(struct ZeroStatus *p) {
  p->mainWeapon = WEAPON_BUSTER;
  p->subWeapon = WEAPON_SABER;
  p->element = 0;
  (p->asset).satelites[0] = ELF_NONE;
  (p->asset).satelites[1] = ELF_NONE;
  p->head = HEAD_CHIP_NONE;
  p->body = BODY_CHIP_NONE;
  p->foot = FOOT_CHIP_NONE;
  p->exSkill = 0;
  p->unlockedWeapon = ((1 << WEAPON_BUSTER) | (1 << WEAPON_SABER));
  p->unlockedHead = (1 << HEAD_CHIP_NONE) | (1 << 1) | (1 << 2) | (1 << HEAD_CHIP_QKCHARGE);
  p->unlockedBody = (1 << BODY_CHIP_NONE);
  p->unlockedFoot = (1 << FOOT_CHIP_NONE) | (1 << FOOT_CHIP_SPLASH) | (1 << FOOT_CHIP_FROG) | (1 << FOOT_CHIP_ULTIMA);
  p->unlockedExSkill = 0;
  (p->keyMap).keys.jump = A_BUTTON;
  (p->keyMap).keys.dash = L_BUTTON;
  (p->keyMap).keys.main = B_BUTTON;
  (p->keyMap).keys.sub = R_BUTTON;
  (p->keyMap).btnMode = 0;
  (p->keyMap).attackMode = 0;
  (p->keyMap).unk_a = 0;
  p->charge[0] = 0;
  p->charge[1] = 0;
  (p->asset).EC = 0;
  (p->asset).subtankHP[0] = 0xFF;
  (p->asset).subtankHP[1] = 0xFF;
  (p->asset).subtankHP[2] = 0;
  (p->asset).subtankHP[3] = 0;
  (p->asset).fusions = 0;
  p->maxHP = 64;
  p->dying = FALSE;
  p->menuZeroColor = MZC_ULTIMATE;
}

void FUN_080321d4(struct ZeroStatus *p) {
  u8 i;
  p->mainWeapon = WEAPON_BUSTER;
  p->subWeapon = WEAPON_SABER;
  p->element = 0;
  (p->asset).satelites[0] = ELF_NONE;
  (p->asset).satelites[1] = ELF_NONE;
  p->head = HEAD_CHIP_NONE;
  p->body = BODY_CHIP_NONE;
  p->foot = FOOT_CHIP_NONE;
  p->exSkill = 0;
  p->unlockedWeapon = ((1 << WEAPON_BUSTER) | (1 << WEAPON_SABER));
  (p->keyMap).unk_a = 0;
  p->charge[0] = 0;
  p->charge[1] = 0;
  for (i = 0; i < 4; i++) {
    if ((p->asset).subtankHP[i] != 0xFF) {
      (p->asset).subtankHP[i] = 0;
    }
  }
  (p->asset).fusions = 0;
  p->maxHP = 64;
  p->dying = FALSE;
}

void SaveZeroStatus(struct Zero *z, struct ZeroStatus *src) {
  CpuFastCopy(src, &(&z->unk_b4)->status, 32);
  CpuCopy32((void *)src + 32, &(z->unk_b4).status.keyMap.keys.main, 16);
  (z->body).hp = 64;
}

void CopyZeroStatus(struct Zero *z, struct ZeroStatus *dst) {
  CpuFastCopy(&(&z->unk_b4)->status, dst, 32);
  CpuCopy32(&(z->unk_b4).status.keyMap.keys.main, (void *)dst + 32, 16);
}

void skipEventScene(struct Zero *z, struct ZeroStatus *status) {
  status->maxHP = (z->body).hp;
  status->charge[0] = (z->unk_b4).status.charge[0];
  status->charge[1] = (z->unk_b4).status.charge[1];
}

void FUN_080322c4(struct ZeroStatus *status) {
  status->maxHP = 64;
  status->charge[0] = 0;
  status->charge[1] = 0;
}

static const u8 u8_ARRAY_0835e84c[2] = {2, 1};
static const u8 u8_ARRAY_0835e84e[2] = {4, 3};
static const u8 u8_ARRAY_0835e850[2] = {6, 5};

WIP void FUN_080322dc(struct Zero *z, motion_t m, u8 r2) {
#if MODERN
  motion_t zm;
  weapon_t w[4];

  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, m);
    CreateWeaponRod(z);
    (z->unk_b4).attackMode[2]++;
    return;
  }

  KeepMotion(z, m);
  zm = MOTION_VALUE(z);
  if (zm != m) {
    GotoMotion(&z->s, m, z->motionCmdIdx, z->motionDuration);
  }

  if ((z->s).motion.cmdIdx > 5) {
    zero_input_t *input;
    if (Is1000Slash(z)) {
      if (r2 == 0) {
        z->rodToggle = 0x10;
      } else {
        z->rodToggle = 0x0;
      }
      (z->unk_b4).attackMode[1] = 11;
      (z->unk_b4).attackMode[2] = 0;
      return;
    }
    if (z->unk_rod_133 != 0) {
      if (r2 == 0) {
        z->rodToggle = 0x10;
      } else {
        z->rodToggle = 0x0;
      }

      input = &z->zeroInput;
      if (*input & DPAD_RIGHT) {
        (z->s).spr.xflip = TRUE;
        (z->s).spr.oam.xflip = TRUE;
        (z->s).flags |= X_FLIP;
      }
      if (*input & DPAD_LEFT) {
        (z->s).spr.xflip = FALSE;
        (z->s).spr.oam.xflip = FALSE;
        (z->s).flags &= ~X_FLIP;
      }
      if (*input & DPAD_UP) {
        (z->unk_b4).attackMode[1] = u8_ARRAY_0835e84e[r2];
      } else if (*input & DPAD_DOWN) {
        (z->unk_b4).attackMode[1] = u8_ARRAY_0835e850[r2];
      } else {
        (z->unk_b4).attackMode[1] = u8_ARRAY_0835e84c[r2];
      }
      (z->unk_b4).attackMode[2] = 0;
      z->unk_rod_133 = 0;
      return;
    }

    if (IsAttackOK(z, &z->usingWeapon)) {
      if (r2 == 0) {
        z->rodToggle = 0x10;
      } else {
        z->rodToggle = 0x0;
      }
      (z->unk_b4).attackMode[0] = 3;
      (z->unk_b4).attackMode[1] = 0;
      zeroAttack(z);
      return;
    }
  }

  if ((z->s).motion.state == MOTION_END) {
    if (r2 == 0) {
      z->rodToggle = 0x10;
    } else {
      z->rodToggle = 0x0;
    }
    (z->unk_b4).attackMode[0] = 0;
    SetMotion(&z->s, GetDefaultMotion(z));
    z->rodID = 0xFF;
    return;
  }

  if (IsAttackOK(z, w)) {
    if (w[0] == WEAPON_ROD) {
      z->unk_rod_133 = 1;
    }
  }
#else
  INCCODE("asm/wip/FUN_080322dc.inc");
#endif
}

void FUN_08032504(struct Zero *z, motion_t m) {
  motion_t zm;

  z->rodToggle = 0x10;
  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, m);
    CreateWeaponRod(z);
    (z->unk_b4).attackMode[2]++;
    return;
  }

  KeepMotion(z, m);
  zm = MOTION_VALUE(z);
  if (zm != m) {
    GotoMotion(&z->s, m, z->motionCmdIdx, z->motionDuration);
  }

  if (((z->s).motion.cmdIdx > 5) && IsAttackOK(z, &z->usingWeapon)) {
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
    z->rodID = 0xFF;
  }
}

void FUN_080325e8(struct Zero *z, motion_t m) {
  motion_t zm;

  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, m);
    z->unk_135 = 0;
    CreateWeaponRod(z);
    (z->unk_b4).attackMode[2]++;
    return;
  }

  KeepMotion(z, m);
  zm = MOTION_VALUE(z);
  if (zm != m) {
    GotoMotion(&z->s, m, z->motionCmdIdx, z->motionDuration);
  }

  if ((z->s).motion.state == MOTION_END) {
    (z->unk_b4).attackMode[0] = 0;
    SetMotion(&z->s, GetDefaultMotion(z));
    z->rodID = 0xFF;
  }
}

void FUN_0803267c(struct Zero *z, motion_t m) {
  motion_t zm;

  if ((z->unk_b4).attackMode[2] == 0) {
    SetMotion(&z->s, m);
    z->unk_135 = 0;
    CreateWeaponRod(z);
    (z->unk_b4).attackMode[2]++;
    return;
  }

  KeepMotion(z, m);
  zm = MOTION_VALUE(z);
  if (zm != m) {
    GotoMotion(&z->s, m, z->motionCmdIdx, z->motionDuration);
  }

  if ((z->s).motion.state == MOTION_END) {
    if ((z->s).mode[2] == 1) {
      GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 0x03), 2, 1);
    } else {
      GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 0x04), 2, 1);
    }
    (z->unk_b4).attackMode[0] = 0;
    z->rodID = 0xFF;
  }
}

void zero_08032724(struct Zero *z) {
  if ((z->unk_b4).attackMode[0] == 3) {
    if (z->usingWeapon == WEAPON_SABER) {
      if ((z->s).mode[1] == ZERO_AIR) {
        if ((z->unk_b4).attackMode[1] == 2) {
          z->saberAction = 0xFF;
          (z->unk_b4).attackMode[0] = 0;
        }
      }
    }
  }
}

WIP void setStageElfFlags(struct Zero *z) {
#if MODERN
  if (((*gUnlockedElfPtr)[ELF_BYSE] & ELF_AVABILITY_UNLOCKED) && (((*gUnlockedElfPtr)[ELF_BYSE] & ELF_AVABILITY_USED) || z->inCyberSpace || SATELITE_1 == ELF_BYSE || SATELITE_2 == ELF_BYSE)) {
    SET_FLAG(gCurStory.s.gameflags, BYSE_ENABLED);
    SET_FLAG(gGameState.save.story.gameflags, FLAG_7);
    SET_FLAG(gGameState.save.savedStory.gameflags, FLAG_7);
  } else {
    CLEAR_FLAG(gCurStory.s.gameflags, BYSE_ENABLED);
    CLEAR_FLAG(gGameState.save.story.gameflags, FLAG_7);
    CLEAR_FLAG(gGameState.save.savedStory.gameflags, FLAG_7);
  }

  if (((*gUnlockedElfPtr)[ELF_DYLPHINA] & ELF_AVABILITY_UNLOCKED) && (((*gUnlockedElfPtr)[ELF_DYLPHINA] & ELF_AVABILITY_USED) || z->inCyberSpace || SATELITE_1 == ELF_DYLPHINA || SATELITE_2 == ELF_DYLPHINA)) {
    SET_FLAG(gCurStory.s.gameflags, DYLPHINA_ENABLED);
  } else {
    CLEAR_FLAG(gCurStory.s.gameflags, DYLPHINA_ENABLED);
  }

  if (((*gUnlockedElfPtr)[ELF_PUTITE] & ELF_AVABILITY_UNLOCKED) && (((*gUnlockedElfPtr)[ELF_PUTITE] & ELF_AVABILITY_USED) || z->inCyberSpace || SATELITE_1 == ELF_PUTITE || SATELITE_2 == ELF_PUTITE)) {
    SET_FLAG(gCurStory.s.gameflags, PUTITE_ENABLED);
  } else {
    CLEAR_FLAG(gCurStory.s.gameflags, PUTITE_ENABLED);
  }
#else
  INCCODE("asm/wip/setStageElfFlags.inc");
#endif
}

static const cyberelf_t sSatelitableElfIDs[23] = {
    ELF_MARTINA, ELF_MILVY, ELF_ELPHY, ELF_SYLPHY, ELF_RILPHY, ELF_PUTITE, ELF_BALETTE, ELF_MAYA, ELF_KWAPPA, ELF_GAMBUL, ELF_BYSE, ELF_DYLPHINA, ELF_LIZETUS, ELF_COTTUS, ELF_SHUTHAS, ELF_MALTHAS, ELF_ILETHAS, ELF_ENETHAS, ELF_BUSRAS, ELF_SABRAS, ELF_RODERAS, ELF_BOOMERAS, ELF_CLOKKLE,
};

u8 FUN_08032880(struct Zero *z, u8 r1) {
  u8 i;
  u8 *arr;
  u8 ctr = 0;
  if (r1 == 0xFF) {
    for (i = 0; i < ARRAY_COUNT(sSatelitableElfIDs); i++) {
      u8 id = sSatelitableElfIDs[i];
      if ((*gUnlockedElfPtr)[id] & ELF_AVABILITY_UNLOCKED) {
        if (((*gUnlockedElfPtr)[id] & ELF_AVABILITY_USED) == 0) {
          ctr++;
        }
      }
    }
    return ctr;
  }

  for (i = 0; i < ARRAY_COUNT(sSatelitableElfIDs); i++) {
    u8 id = sSatelitableElfIDs[i];
    if (((*gUnlockedElfPtr)[id] & (ELF_AVABILITY_UNLOCKED | ELF_AVABILITY_USED)) == ELF_AVABILITY_UNLOCKED) {
      if (ctr == r1) {
        if (sSatelitableElfIDs[i] <= ELF_SLOPPE) {
          return 0;
        }
        if (sSatelitableElfIDs[i] <= ELF_ARCHIL) {
          return 1;
        }
        return 2;
      }
      ctr++;
    }
  }
  return 0;
}

s16 getFallAcceleration(struct Zero *z) {
  if ((z->s).coord.y - (gZeroRanges[z->posture].h >> 1) > SEA) {
    return 0x20;
  }
  return 0x40;
}

s16 calcMaxFallSpeed(struct Zero *z) {
  if ((z->s).coord.y - (gZeroRanges[z->posture].h >> 1) > SEA) {
    return 0x380;
  }
  return 0x700;
}

s16 getWallFallSpeed(struct Zero *z) {
  s16 dy = 0x180;
  struct Zero_b4 *b4 = &z->unk_b4;

  if (!(z->zeroInput & DPAD_DOWN)) {
    if (((b4->status).foot == FOOT_CHIP_FROG) || ((b4->status).foot == FOOT_CHIP_ULTIMA)) {
      if (IsElfUsed(z, ELF_KWAPPA) && ((b4->status).body == BODY_CHIP_LIGHT)) {
        return 0;
      }
      dy = 0xC0;
    } else if (IsElfUsed(z, ELF_KWAPPA)) {
      dy = 0xC0;
    }
  }

  if ((z->s).coord.y - (gZeroRanges[z->posture].h >> 1) > SEA) {
    if (dy == 0xC0) {
      return 0x60;
    } else {
      return 0xC0;
    }
  }
  return dy;
}

WIP s16 CalcDx(struct Zero *z) {
#if MODERN
  struct Zero_b4 *b4 = &(z->unk_b4);
  s16 dx;

  if (z->last & INPUT_DISABLED) {
    return 0x200;
  }

  dx = 0x200;
  if (((b4->status).foot == FOOT_CHIP_QUICK) || ((b4->status).foot == FOOT_CHIP_ULTIMA) || (IsElfUsed(z, ELF_BALETTE))) {
    dx = 0x280;
  }

  if (z->slow != 0) {
    return (((0x100 - z->slow) * dx) >> 8) >> z->antlion;
  } else {
    return dx >> z->antlion;
  }
#else
  INCCODE("asm/wip/CalcDx.inc");
#endif
}

s16 CalcMaxWalkSpeed(struct Zero *z) {
  if (z->last & INPUT_DISABLED) {
    return 0x200;
  }

  if (z->slow != 0) {
    return ((0x100 - z->slow) >> 1) >> z->antlion;
  } else {
    return 0x80 >> z->antlion;
  }
}

s16 GetDashSpeed(struct Zero *z) {
  if (z->last & INPUT_DISABLED) {
    return 0x380;
  }

  if (z->slow != 0) {
    return (((0x100 - z->slow) * 7) >> 1) >> z->antlion;
  } else {
    return 0x380 >> z->antlion;
  }
}

// ジャンプ始めの上昇速度を取得
s16 getZeroJumpingPower(struct Zero *z) {
  if (z->slow != 0) return (0x100 - z->slow) * 5;
  return 0x500;
}

s16 getZeroRisingDy(struct Zero *z) {
  if (z->slow != 0) return (0x100 - z->slow) * 4;
  return 0x400;
}

s16 FUN_08032bac(struct Zero *z) {
  if (z->slow != 0) return ((0x100 - z->slow) * 19) >> 2;
  return 0x4c0;
}

s16 GetRodJumpPower(struct Zero *z) {
  if (z->slow != 0) return (0x100 - z->slow) * 7;
  return 0x700;
}

s16 FUN_08032c04(struct Zero *z) {
  if (z->slow != 0) return ((0x100 - z->slow) * 9) >> 1;
  return 0x480;
}

s16 FUN_08032c30(struct Zero *z) {
  if (z->slow != 0) return ((0x100 - z->slow) * 21) >> 2;
  return 0x540;
}

WIP s16 GetSplitHeavenSpeed(struct Zero *z) {
#if MODERN
  if (z->slow != 0) {
    return 0x100 - z->slow;
  }
  return 0x100;
#else
  INCCODE("asm/wip/FUN_08032c60.inc");
#endif
}

WIP bool8 IsElfUsed(struct Zero *z, cyberelf_t elfID) {
#if MODERN
  const u8 availability = (*gUnlockedElfPtr)[elfID];
  if (availability & ELF_AVABILITY_UNLOCKED) {
    struct Zero_b4 *b4;
    cyberelf_t *satelites;

    if (availability & ELF_AVABILITY_USED) {
      return TRUE;
    }
    if (z->inCyberSpace) {
      return TRUE;
    }

    b4 = &z->unk_b4;
    satelites = (b4->status).asset.satelites;
    if ((satelites[0] == elfID) || (satelites[1] == elfID)) {
      return TRUE;
    }
  }
  return FALSE;
#else
  INCCODE("asm/wip/IsElfUsed.inc");
#endif
}

u8 GetZeroColor(struct Zero *z) {
  struct Zero_b4 *b4 = &(z->unk_b4);
  u8 c = (b4->status).menuZeroColor;
  if (c == MZC_ULTIMATE) {
    return BODY_CHIP_ULTIMA;
  }
  if (c == MZC_HARD) {
    return BODY_CHIP_PROTO;
  }
  return (b4->status).body;
}

void InstantlyKilling(struct Zero *z) {
  if ((z->body).hp != 0) {
    if (((z->body).invincibleTime == 0) || (z->unk_149 != 0)) {
      if (IsElfUsed(z, ELF_PUTITE)) {
        if (gSystemSavedataManager.mods[2] & (1 << 3)) {
          AddMissionDamage(PUTITED_DAMAGE / 2);
          CalcPutitedSpikeDamage(&z->body, PUTITED_DAMAGE / 2);
        } else {
          AddMissionDamage(PUTITED_DAMAGE);
          CalcPutitedSpikeDamage(&z->body, PUTITED_DAMAGE);
        }
      } else {
        (z->body).hp = 0;
      }
      z->isRightDir = ((z->s).flags >> 4) & 1;
      (z->s).mode[1] = ZERO_DAMAGED;
      (z->s).mode[2] = 0;
    }
  }
}

// clang-format off
const struct Rect gZeroRanges[POSTURE_COUNT] = {
    [POSTURE_IDLE]    = {-PIXEL(1), -PIXEL(15), PIXEL(15), PIXEL(30)},
    [POSTURE_DASH]    = {-PIXEL(2), -PIXEL(11), PIXEL(26), PIXEL(22)},
    [POSTURE_WALL]    = {-PIXEL(7), -PIXEL(15), PIXEL(14), PIXEL(30)},
    [POSTURE_SHADOW]  = {-PIXEL(2), -PIXEL(11), PIXEL(26), PIXEL(22)},
    [POSTURE_DOOR_2D] = {-PIXEL(1), -PIXEL(15), PIXEL(15), PIXEL(30)},
    [POSTURE_DOOR_3D] = {-PIXEL(2), -PIXEL(15), PIXEL(26), PIXEL(30)},
};
// clang-format on

const struct Collision gZeroCollisions[POSTURE_COUNT] = {
    [POSTURE_IDLE] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : HARDNESS_B3,
      unk_0a : 0x04,
      remaining : 0,
      range : {-PIXEL(1), -PIXEL(14), PIXEL(16), PIXEL(30)},
    },
    [POSTURE_DASH] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : HARDNESS_B3,
      unk_0a : 0x04,
      remaining : 0,
      range : {-PIXEL(2), -PIXEL(10), PIXEL(26), PIXEL(22)},
    },
    [POSTURE_WALL] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : HARDNESS_B3,
      unk_0a : 0x04,
      remaining : 0,
      range : {-PIXEL(7), -PIXEL(15), PIXEL(16), PIXEL(30)},
    },
    [POSTURE_SHADOW] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {-PIXEL(2), -PIXEL(10), PIXEL(26), PIXEL(22)},
    },
    [POSTURE_DOOR_2D] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {-PIXEL(1), -PIXEL(14), PIXEL(16), PIXEL(30)},
    },
    [POSTURE_DOOR_3D] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : HARDNESS_B3,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {-PIXEL(2), -PIXEL(14), PIXEL(26), PIXEL(30)},
    },
};

// Unused (For Z2 Proto Form?)
const struct Collision gZeroProtoCollisions[POSTURE_COUNT] = {
    [POSTURE_IDLE] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : HARDNESS_B3 | HARDNESS_WEAK,
      unk_0a : 0x04,
      remaining : 0,
      range : {-PIXEL(1), -PIXEL(14), PIXEL(16), PIXEL(30)},
    },
    [POSTURE_DASH] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : HARDNESS_B3 | HARDNESS_WEAK,
      unk_0a : 0x04,
      remaining : 0,
      range : {-PIXEL(2), -PIXEL(10), PIXEL(26), PIXEL(22)},
    },
    [POSTURE_WALL] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : HARDNESS_B3 | HARDNESS_WEAK,
      unk_0a : 0x04,
      remaining : 0,
      range : {-PIXEL(7), -PIXEL(15), PIXEL(16), PIXEL(30)},
    },
    [POSTURE_SHADOW] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : HARDNESS_B3 | HARDNESS_WEAK,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {-PIXEL(2), -PIXEL(10), PIXEL(26), PIXEL(22)},
    },
    [POSTURE_DOOR_2D] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : HARDNESS_B3 | HARDNESS_WEAK,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {-PIXEL(1), -PIXEL(14), PIXEL(16), PIXEL(30)},
    },
    [POSTURE_DOOR_3D] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : HARDNESS_B3 | HARDNESS_WEAK,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {-PIXEL(2), -PIXEL(14), PIXEL(26), PIXEL(30)},
    },
};
