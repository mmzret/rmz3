#include "collision.h"
#include "cyberelf.h"
#include "global.h"
#include "mod.h"
#include "overworld.h"
#include "player/zero.h"
#include "score.h"
#include "weapon.h"
#include "zero.h"

#define PUTITED_DAMAGE 8

void ClearZeroStatus(struct ZeroStatus* p) {
  p->weapons[0] = WEAPON_BUSTER, p->weapons[1] = WEAPON_SABER;
  p->element = 0;
  p->satelites[0] = ELF_NONE, p->satelites[1] = ELF_NONE;
  p->head = HEAD_CHIP_NONE, p->body = BODY_CHIP_NONE, p->foot = FOOT_CHIP_NONE;
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
  p->charge[0] = 0, p->charge[1] = 0;
  p->EC = 0;
  p->subtankHP[0] = 0xFF, p->subtankHP[1] = 0xFF, p->subtankHP[2] = 0xFF, p->subtankHP[3] = 0xFF;
  p->fusions = 0;
  p->maxHP = 64;
  p->dying = FALSE;
  p->menuZeroColor = MZC_NORMAL;
}

void ClearZeroStatusHard(struct ZeroStatus* p) {
  p->weapons[0] = WEAPON_BUSTER, p->weapons[1] = WEAPON_SABER;
  p->element = 0;
  p->satelites[0] = ELF_NONE, p->satelites[1] = ELF_NONE;
  p->head = HEAD_CHIP_NONE, p->body = BODY_CHIP_NONE, p->foot = FOOT_CHIP_NONE;
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
  p->charge[0] = 0, p->charge[1] = 0;
  p->EC = 0;
  p->subtankHP[0] = 0xFF, p->subtankHP[1] = 0xFF, p->subtankHP[2] = 0xFF, p->subtankHP[3] = 0xFF;
  p->fusions = 0;
  p->maxHP = 64;
  p->dying = FALSE;
  p->menuZeroColor = MZC_HARD;
}

void ClearZeroStatusUltimate(struct ZeroStatus* p) {
  p->weapons[0] = WEAPON_BUSTER, p->weapons[1] = WEAPON_SABER;
  p->element = 0;
  p->satelites[0] = ELF_NONE, p->satelites[1] = ELF_NONE;
  p->head = HEAD_CHIP_NONE, p->body = BODY_CHIP_NONE, p->foot = FOOT_CHIP_NONE;
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
  p->charge[0] = 0, p->charge[1] = 0;
  p->EC = 0;
  p->subtankHP[0] = 0xFF, p->subtankHP[1] = 0xFF;
  p->subtankHP[2] = 0, p->subtankHP[3] = 0;
  p->fusions = 0;
  p->maxHP = 64;
  p->dying = FALSE;
  p->menuZeroColor = MZC_ULTIMATE;
}

void FUN_080321d4(struct ZeroStatus* p) {
  u8 i;
  p->weapons[0] = WEAPON_BUSTER, p->weapons[1] = WEAPON_SABER;
  p->element = 0;
  p->satelites[0] = ELF_NONE, p->satelites[1] = ELF_NONE;
  p->head = HEAD_CHIP_NONE, p->body = BODY_CHIP_NONE, p->foot = FOOT_CHIP_NONE;
  p->exSkill = 0;
  p->unlockedWeapon = ((1 << WEAPON_BUSTER) | (1 << WEAPON_SABER));
  (p->keyMap).unk_a = 0;
  p->charge[0] = 0, p->charge[1] = 0;
  for (i = 0; i < 4; i++) {
    if (p->subtankHP[i] != 0xFF) {
      p->subtankHP[i] = 0;
    }
  }
  p->fusions = 0;
  p->maxHP = 64;
  p->dying = FALSE;
}

/**
 * @brief (&z->unk_b4)->status に src の内容をロードする
 * @note 0x08032240
 */
void LoadZeroStatus(struct Zero* z, struct ZeroStatus* src) {
  MemCopy32(src, &(&z->unk_b4)->status, sizeof(struct ZeroStatus));
  (z->body).hp = 64;
}

/**
 * @brief dst に (&z->unk_b4)->status の内容を書き込む
 * @param dst 書き込み先の ZeroStatus (だいたい gGameState.save.status)
 * @note 0x08032274
 */
void StoreZeroStatus(struct Zero* z, struct ZeroStatus* dst) { MemCopy32(&(&z->unk_b4)->status, dst, sizeof(struct ZeroStatus)); }

// 0x0803229c
void CopyPlayerMaxHPChargeOnSkipEventScene(Player* p, struct ZeroStatus* dst) {
  dst->maxHP = (p->body).hp;
  dst->charge[0] = (p->unk_b4).status.charge[0];
  dst->charge[1] = (p->unk_b4).status.charge[1];
}

void FUN_080322c4(struct ZeroStatus* status) {
  status->maxHP = 64;
  status->charge[0] = 0;
  status->charge[1] = 0;
}

static const u8 u8_ARRAY_0835e84c[3][2] = {{2, 1}, {4, 3}, {6, 5}};

NON_MATCH void FUN_080322dc(struct Zero* z, motion_t m, u8 r2) {
#if MODERN
  motion_t zm;
  weapon_t w[4];

  if ((z->unk_b4).attackState8[2] == 0) {
    SetSpriteAnimation(z, m);
    CreateWeaponRod(z);
    (z->unk_b4).attackState8[2]++;
    return;
  }

  KeepMotion(z, m);
  zm = MOTION_VALUE(z);
  if (zm != m) {
    GotoMotion(&z->s, m, z->motionCmdIdx, z->motionDuration);
  }

  if ((z->s).motion.cmdIdx > 5) {
    zero_input_t* input;
    if (Is1000Slash(z)) {
      if (r2 == 0) {
        z->rodToggle = 0x10;
      } else {
        z->rodToggle = 0x0;
      }
      (z->unk_b4).attackState8[1] = 11;
      (z->unk_b4).attackState8[2] = 0;
      return;
    }
    if (z->unk_rod_133 != 0) {
      if (r2 == 0) {
        z->rodToggle = 0x10;
      } else {
        z->rodToggle = 0x0;
      }

      input = &(z->input).val;
      if (*input & DPAD_RIGHT) SET_XFLIP(z, TRUE);
      if (*input & DPAD_LEFT) SET_XFLIP(z, FALSE);
      if (*input & DPAD_UP) {
        (z->unk_b4).attackState8[1] = u8_ARRAY_0835e84c[1][r2];
      } else {
        if (*input & DPAD_DOWN) {
          (z->unk_b4).attackState8[1] = u8_ARRAY_0835e84c[2][r2];
        } else {
          (z->unk_b4).attackState8[1] = u8_ARRAY_0835e84c[0][r2];
        }
      }

      (z->unk_b4).attackState8[2] = 0;
      z->unk_rod_133 = 0;
      return;
    }

    if (IsAttackOK(z, &z->usingWeapon)) {
      if (r2 == 0) {
        z->rodToggle = 0x10;
      } else {
        z->rodToggle = 0x0;
      }
      (z->unk_b4).attackState8[0] = 3;
      (z->unk_b4).attackState8[1] = 0;
      zeroAttack(z);
      return;
    }
  }

  if (IsSpriteAnimEnd(z)) {
    if (r2 == 0) {
      z->rodToggle = 0x10;
    } else {
      z->rodToggle = 0x0;
    }
    (z->unk_b4).attackState8[0] = 0;
    SetSpriteAnimation(z, GetDefaultMotion(z));
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

void FUN_08032504(struct Zero* z, motion_t m) {
  motion_t zm;

  z->rodToggle = 0x10;
  if ((z->unk_b4).attackState8[2] == 0) {
    SetSpriteAnimation(z, m);
    CreateWeaponRod(z);
    (z->unk_b4).attackState8[2]++;
    return;
  }

  KeepMotion(z, m);
  zm = MOTION_VALUE(z);
  if (zm != m) {
    GotoMotion(&z->s, m, z->motionCmdIdx, z->motionDuration);
  }

  if (((z->s).motion.cmdIdx > 5) && IsAttackOK(z, &z->usingWeapon)) {
    (z->unk_b4).attackState8[0] = 3;
    (z->unk_b4).attackState8[1] = 0;
    zeroAirAtk(z);
    return;
  }

  if (IsSpriteAnimEnd(z)) {
    if ((z->s).mode[2] == 1) {
      GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 3), 2, 1);
    } else {
      GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 4), 2, 1);
    }
    (z->unk_b4).attackState8[0] = 0;
    z->rodID = 0xFF;
  }
}

void FUN_080325e8(struct Zero* z, motion_t m) {
  motion_t zm;

  if ((z->unk_b4).attackState8[2] == 0) {
    SetSpriteAnimation(z, m);
    z->unk_135 = 0;
    CreateWeaponRod(z);
    (z->unk_b4).attackState8[2]++;
    return;
  }

  KeepMotion(z, m);
  zm = MOTION_VALUE(z);
  if (zm != m) {
    GotoMotion(&z->s, m, z->motionCmdIdx, z->motionDuration);
  }

  if (IsSpriteAnimEnd(z)) {
    (z->unk_b4).attackState8[0] = 0;
    SetSpriteAnimation(z, GetDefaultMotion(z));
    z->rodID = 0xFF;
  }
}

void FUN_0803267c(struct Zero* z, motion_t m) {
  motion_t zm;

  if ((z->unk_b4).attackState8[2] == 0) {
    SetSpriteAnimation(z, m);
    z->unk_135 = 0;
    CreateWeaponRod(z);
    (z->unk_b4).attackState8[2]++;
    return;
  }

  KeepMotion(z, m);
  zm = MOTION_VALUE(z);
  if (zm != m) {
    GotoMotion(&z->s, m, z->motionCmdIdx, z->motionDuration);
  }

  if (IsSpriteAnimEnd(z)) {
    if ((z->s).mode[2] == 1) {
      GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 3), 2, 1);
    } else {
      GotoMotion(&z->s, MOTION(DM004_ZERO_AIR, 4), 2, 1);
    }
    (z->unk_b4).attackState8[0] = 0;
    z->rodID = 0xFF;
  }
}

void zero_08032724(struct Zero* z) {
  if ((z->unk_b4).attackState8[0] == 3) {
    if (z->usingWeapon == WEAPON_SABER) {
      if ((z->s).mode[1] == ZERO_AIR) {
        if ((z->unk_b4).attackState8[1] == 2) {
          z->saberAction = 0xFF;
          (z->unk_b4).attackState8[0] = 0;
        }
      }
    }
  }
}

static inline bool32 IsCyberElfUsed(Player* p, cyberelf_t id) {
  struct Zero_b4* b4;
  cyberelf_t* satelites;
  if (gElfAvailability[id] & ELF_AVABILITY_UNLOCKED) {
    if (gElfAvailability[id] & ELF_AVABILITY_USED) {
      return TRUE;
    }
    b4 = &p->unk_b4;
    satelites = (b4->status).satelites;
    if ((p->inCyberSpace) || ((satelites[0] == id) || (satelites[1] == id))) {
      return TRUE;
    }
  }
  return FALSE;
}

void setStageElfFlags(Player* p) {
  if (IsCyberElfUsed(p, ELF_BYSE)) {
    SET_FLAG(gCurStory.s.gameflags, BYSE_ENABLED);
    SET_FLAG((&gGameState.save.story)->gameflags, BYSE_ENABLED);
    SET_FLAG((&gGameState.save.savedStory)->gameflags, BYSE_ENABLED);
  } else {
    CLEAR_FLAG(gCurStory.s.gameflags, BYSE_ENABLED);
    CLEAR_FLAG((&gGameState.save.story)->gameflags, BYSE_ENABLED);
    CLEAR_FLAG((&gGameState.save.savedStory)->gameflags, BYSE_ENABLED);
  }
  if (IsCyberElfUsed(p, ELF_DYLPHINA)) {
    SET_FLAG(gCurStory.s.gameflags, DYLPHINA_ENABLED);
  } else {
    CLEAR_FLAG(gCurStory.s.gameflags, DYLPHINA_ENABLED);
  }
  if (IsCyberElfUsed(p, ELF_PUTITE)) {
    SET_FLAG(gCurStory.s.gameflags, PUTITE_ENABLED);
  } else {
    CLEAR_FLAG(gCurStory.s.gameflags, PUTITE_ENABLED);
  }
}

u8 FUN_08032880(void* _, u8 r1) {
  static const cyberelf_t sSatelitableElfIDs[23] = {
      ELF_MARTINA, ELF_MILVY, ELF_ELPHY, ELF_SYLPHY, ELF_RILPHY, ELF_PUTITE, ELF_BALETTE, ELF_MAYA, ELF_KWAPPA, ELF_GAMBUL, ELF_BYSE, ELF_DYLPHINA, ELF_LIZETUS, ELF_COTTUS, ELF_SHUTHAS, ELF_MALTHAS, ELF_ILETHAS, ELF_ENETHAS, ELF_BUSRAS, ELF_SABRAS, ELF_RODERAS, ELF_BOOMERAS, ELF_CLOKKLE,
  };

  u8 i;
  u8* arr;
  u8 ctr = 0;
  if (r1 == 0xFF) {
    for (i = 0; i < ARRAY_COUNT(sSatelitableElfIDs); i++) {
      u8 id = sSatelitableElfIDs[i];
      if (gElfAvailability[id] & ELF_AVABILITY_UNLOCKED) {
        if (!(gElfAvailability[id] & ELF_AVABILITY_USED)) {
          ctr++;
        }
      }
    }
    return ctr;
  }

  for (i = 0; i < ARRAY_COUNT(sSatelitableElfIDs); i++) {
    u8 id = sSatelitableElfIDs[i];
    if ((gElfAvailability[id] & (ELF_AVABILITY_UNLOCKED | ELF_AVABILITY_USED)) == ELF_AVABILITY_UNLOCKED) {
      if (ctr == r1) {
        if (sSatelitableElfIDs[i] <= ELF_SLOPPE) return 0;
        if (sSatelitableElfIDs[i] <= ELF_ARCHIL) return 1;
        return 2;
      }
      ctr++;
    }
  }
  return 0;
}

s16 getFallAcceleration(struct Zero* z) {
  if ((z->s).coord.y - (gZeroRanges[z->posture].h >> 1) > gOverworld.sea) {
    return 0x20;
  }
  return 0x40;
}

s16 calcMaxFallSpeed(struct Zero* z) {
  if ((z->s).coord.y - (gZeroRanges[z->posture].h >> 1) > gOverworld.sea) {
    return PIXEL(7) / 2;
  }
  return PIXEL(7);
}

s16 getWallFallSpeed(struct Zero* z) {
  s16 dy = 0x180;
  struct Zero_b4* b4 = &z->unk_b4;

  if (!((z->input).val & DPAD_DOWN)) {
    if (((b4->status).foot == FOOT_CHIP_FROG) || ((b4->status).foot == FOOT_CHIP_ULTIMA)) {
      if (IsElfUsed(z, ELF_KWAPPA) && ((b4->status).body == BODY_CHIP_LIGHT)) {
        return 0;
      }
      dy = 0xC0;
    } else if (IsElfUsed(z, ELF_KWAPPA)) {
      dy = 0xC0;
    }
  }

  if ((z->s).coord.y - (gZeroRanges[z->posture].h >> 1) > gOverworld.sea) {
    if (dy == 0xC0) {
      return 0x60;
    } else {
      return 0xC0;
    }
  }
  return dy;
}

s16 CalcDx(struct Zero* z) {
  struct Zero_b4* b4 = &(z->unk_b4);
  s16 dx;

  if ((z->input).raw & INPUT_DISABLED) {
    return PIXEL(2);
  }

  dx = PIXEL(2);
  if (((b4->status).foot == FOOT_CHIP_QUICK) || ((b4->status).foot == FOOT_CHIP_ULTIMA) || (IsElfUsed(z, ELF_BALETTE))) {
    dx = PIXEL(2) + (PIXEL(1) / 2);
  }

  if (z->slow != 0) {
    return ((dx * (s32)(0x100 - z->slow)) >> 8) >> z->antlion;
  } else {
    return dx >> z->antlion;
  }
}

s16 CalcMaxWalkSpeed(struct Zero* z) {
  if ((z->input).raw & INPUT_DISABLED) {
    return 0x200;
  }

  if (z->slow != 0) {
    return ((0x100 - z->slow) >> 1) >> z->antlion;
  } else {
    return 0x80 >> z->antlion;
  }
}

s16 GetDashSpeed(struct Zero* z) {
  if ((z->input).raw & INPUT_DISABLED) {
    return 0x380;
  }

  if (z->slow != 0) {
    return (((0x100 - z->slow) * 7) >> 1) >> z->antlion;
  } else {
    return 0x380 >> z->antlion;
  }
}

// ジャンプ始めの上昇速度を取得
s16 getZeroJumpingPower(struct Zero* z) {
  if (z->slow != 0) return (0x100 - z->slow) * 5;
  return 0x500;
}

s16 getZeroRisingDy(struct Zero* z) {
  if (z->slow != 0) return (0x100 - z->slow) * 4;
  return 0x400;
}

s16 FUN_08032bac(struct Zero* z) {
  if (z->slow != 0) return ((0x100 - z->slow) * 19) >> 2;
  return 0x4c0;
}

s16 GetRodJumpPower(struct Zero* z) {
  if (z->slow != 0) return (0x100 - z->slow) * 7;
  return 0x700;
}

s16 FUN_08032c04(struct Zero* z) {
  if (z->slow != 0) return ((0x100 - z->slow) * 9) >> 1;
  return 0x480;
}

s16 FUN_08032c30(struct Zero* z) {
  if (z->slow != 0) return ((0x100 - z->slow) * 21) >> 2;
  return 0x540;
}

// くっそ単純なコードなのにどうしてもコンパイル結果合わない なんでえ？
s16 GetSplitHeavenSpeed(struct Zero* z) {
  s32 v;
  if (z->slow != 0) {
    v = z->slow;
    v = 0x100 - v;
    return v;
  }
  return 0x100;
}

// 0x08032c84
bool8 IsElfUsed(struct Zero* z, cyberelf_t id) { return IsCyberElfUsed(z, id); }

u8 GetZeroColor(struct Zero* z) {
  struct Zero_b4* b4 = &(z->unk_b4);
  u8 c = (b4->status).menuZeroColor;
  if (c == MZC_ULTIMATE) return BODY_CHIP_ULTIMA;
  if (c == MZC_HARD) return BODY_CHIP_PROTO;
  return (b4->status).body;
}

void InstantlyKilling(struct Zero* z) {
  if ((z->body).hp != 0) {
    if (((z->body).invincibleTime == 0) || (z->unk_149 != 0)) {
      if (IsElfUsed(z, ELF_PUTITE)) {
        if (FLAG(gSystemSavedata.flags, MOD_DAMAGE_50P)) {
          AddMissionDamage(PUTITED_DAMAGE / 2);
          CalcPutitedSpikeDamage(&z->body, PUTITED_DAMAGE / 2);
        } else {
          AddMissionDamage(PUTITED_DAMAGE);
          CalcPutitedSpikeDamage(&z->body, PUTITED_DAMAGE);
        }
      } else {
        (z->body).hp = 0;
      }
      z->isRightDir = ((z->s).flags & X_FLIP) != 0;
      (z->s).mode[1] = ZERO_DAMAGED, (z->s).mode[2] = 0;
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
      LAYER(0xFFFFFFFF),
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
      LAYER(0xFFFFFFFF),
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
      LAYER(0xFFFFFFFF),
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
      LAYER(0xFFFFFFFF),
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
      LAYER(0xFFFFFFFF),
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
      LAYER(0xFFFFFFFF),
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
      LAYER(0xFFFFFFFF),
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
      LAYER(0xFFFFFFFF),
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
      LAYER(0xFFFFFFFF),
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
      LAYER(0xFFFFFFFF),
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
      LAYER(0xFFFFFFFF),
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
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : HARDNESS_B3 | HARDNESS_WEAK,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {-PIXEL(2), -PIXEL(14), PIXEL(26), PIXEL(30)},
    },
};
