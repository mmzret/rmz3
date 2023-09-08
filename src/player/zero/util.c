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
  p->menuZeroColor = BODY_CHIP_NONE;
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
  p->menuZeroColor = 1;
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
  p->menuZeroColor = 2;
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

NAKED void setStageElfFlags(struct Zero *z) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r5, r0, #0\n\
	ldr r0, _080327B8 @ =gUnlockedElfPtr\n\
	ldr r1, [r0]\n\
	adds r1, #0x28\n\
	ldrb r2, [r1]\n\
	movs r1, #1\n\
	ands r1, r2\n\
	adds r6, r0, #0\n\
	cmp r1, #0\n\
	beq _080327C8\n\
	movs r0, #2\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _0803279C\n\
	adds r1, r5, #0\n\
	adds r1, #0xb4\n\
	ldr r2, _080327BC @ =0x00000231\n\
	adds r0, r5, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _0803279C\n\
	ldrb r0, [r1]\n\
	cmp r0, #0x28\n\
	beq _0803279C\n\
	ldrb r0, [r1, #1]\n\
	cmp r0, #0x28\n\
	bne _080327C8\n\
_0803279C:\n\
	ldr r3, _080327C0 @ =gCurStory\n\
	ldrb r0, [r3, #8]\n\
	movs r2, #0x80\n\
	orrs r0, r2\n\
	strb r0, [r3, #8]\n\
	ldr r1, _080327C4 @ =gGameState+25200\n\
	ldrb r0, [r1, #4]\n\
	orrs r0, r2\n\
	strb r0, [r1, #4]\n\
	adds r1, #0x54\n\
	ldrb r0, [r1, #4]\n\
	orrs r2, r0\n\
	strb r2, [r1, #4]\n\
	b _080327E8\n\
	.align 2, 0\n\
_080327B8: .4byte gUnlockedElfPtr\n\
_080327BC: .4byte 0x00000231\n\
_080327C0: .4byte gCurStory\n\
_080327C4: .4byte gGameState+25200\n\
_080327C8:\n\
	ldr r4, _08032820 @ =gCurStory\n\
	ldrb r2, [r4, #8]\n\
	movs r1, #0x7f\n\
	adds r0, r1, #0\n\
	ands r0, r2\n\
	strb r0, [r4, #8]\n\
	ldr r2, _08032824 @ =gGameState+25200\n\
	ldrb r3, [r2, #4]\n\
	adds r0, r1, #0\n\
	ands r0, r3\n\
	strb r0, [r2, #4]\n\
	adds r2, #0x54\n\
	ldrb r0, [r2, #4]\n\
	ands r1, r0\n\
	strb r1, [r2, #4]\n\
	adds r3, r4, #0\n\
_080327E8:\n\
	ldr r0, [r6]\n\
	adds r0, #0x29\n\
	ldrb r1, [r0]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0803282C\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08032818\n\
	adds r1, r5, #0\n\
	adds r1, #0xb4\n\
	ldr r2, _08032828 @ =0x00000231\n\
	adds r0, r5, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _08032818\n\
	ldrb r0, [r1]\n\
	cmp r0, #0x29\n\
	beq _08032818\n\
	ldrb r0, [r1, #1]\n\
	cmp r0, #0x29\n\
	bne _0803282C\n\
_08032818:\n\
	ldrb r1, [r3, #8]\n\
	movs r0, #0x20\n\
	orrs r0, r1\n\
	b _08032832\n\
	.align 2, 0\n\
_08032820: .4byte gCurStory\n\
_08032824: .4byte gGameState+25200\n\
_08032828: .4byte 0x00000231\n\
_0803282C:\n\
	ldrb r1, [r3, #8]\n\
	movs r0, #0xdf\n\
	ands r0, r1\n\
_08032832:\n\
	strb r0, [r3, #8]\n\
	ldr r0, [r6]\n\
	ldrb r1, [r0, #0x1b]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08032870\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08032862\n\
	adds r1, r5, #0\n\
	adds r1, #0xb4\n\
	ldr r2, _0803286C @ =0x00000231\n\
	adds r0, r5, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _08032862\n\
	ldrb r0, [r1]\n\
	cmp r0, #0x1b\n\
	beq _08032862\n\
	ldrb r0, [r1, #1]\n\
	cmp r0, #0x1b\n\
	bne _08032870\n\
_08032862:\n\
	ldrb r1, [r3, #8]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	b _08032876\n\
	.align 2, 0\n\
_0803286C: .4byte 0x00000231\n\
_08032870:\n\
	ldrb r1, [r3, #8]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
_08032876:\n\
	strb r0, [r3, #8]\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static const cyberelf_t gSatelitableElfIDs[23] = {
    ELF_MARTINA, ELF_MILVY, ELF_ELPHY, ELF_SYLPHY, ELF_RILPHY, ELF_PUTITE, ELF_BALETTE, ELF_MAYA, ELF_KWAPPA, ELF_GAMBUL, ELF_BYSE, ELF_DYLPHINA, ELF_LIZETUS, ELF_COTTUS, ELF_SHUTHAS, ELF_MALTHAS, ELF_ILETHAS, ELF_ENETHAS, ELF_BUSRAS, ELF_SABRAS, ELF_RODERAS, ELF_BOOMERAS, ELF_CLOKKLE,
};

NAKED u8 FUN_08032880(struct Zero *z, u8 r1) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	lsls r1, r1, #0x18\n\
	lsrs r5, r1, #0x18\n\
	movs r4, #0\n\
	cmp r5, #0xff\n\
	bne _080328CC\n\
	movs r3, #0\n\
	ldr r0, _080328C0 @ =gUnlockedElfPtr\n\
	ldr r2, [r0]\n\
	ldr r5, _080328C4 @ =gSatelitableElfIDs\n\
_08032894:\n\
	adds r0, r3, r5\n\
	ldrb r0, [r0]\n\
	adds r0, r2, r0\n\
	ldrb r1, [r0]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080328B2\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080328B2\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
_080328B2:\n\
	adds r0, r3, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
	cmp r3, #0x16\n\
	bls _08032894\n\
	adds r0, r4, #0\n\
	b _08032912\n\
	.align 2, 0\n\
_080328C0: .4byte gUnlockedElfPtr\n\
_080328C4: .4byte gSatelitableElfIDs\n\
_080328C8:\n\
	movs r0, #1\n\
	b _08032912\n\
_080328CC:\n\
	movs r3, #0\n\
	ldr r7, _080328F8 @ =gSatelitableElfIDs\n\
	ldr r0, _080328FC @ =gUnlockedElfPtr\n\
	ldr r6, [r0]\n\
_080328D4:\n\
	adds r0, r3, r7\n\
	ldrb r2, [r0]\n\
	adds r0, r6, r2\n\
	ldrb r1, [r0]\n\
	movs r0, #3\n\
	ands r0, r1\n\
	cmp r0, #1\n\
	bne _08032906\n\
	cmp r4, r5\n\
	bne _08032900\n\
	adds r0, r2, #0\n\
	cmp r0, #0x1a\n\
	bls _08032910\n\
	cmp r0, #0x27\n\
	bls _080328C8\n\
	movs r0, #2\n\
	b _08032912\n\
	.align 2, 0\n\
_080328F8: .4byte gSatelitableElfIDs\n\
_080328FC: .4byte gUnlockedElfPtr\n\
_08032900:\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
_08032906:\n\
	adds r0, r3, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
	cmp r3, #0x16\n\
	bls _080328D4\n\
_08032910:\n\
	movs r0, #0\n\
_08032912:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
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

WIP s16 getWallFallSpeed(struct Zero *z) {
#if MODERN
  s16 dy = 0x180;
  struct Zero_b4 *b4 = &z->unk_b4;

  if (!(z->zeroInput & DPAD_DOWN)) {
    const bool8 isKwappa = IsElfUsed(z, ELF_KWAPPA);
    if (((b4->status).foot == FOOT_CHIP_FROG) || ((b4->status).foot == FOOT_CHIP_ULTIMA)) {
      if (isKwappa && ((b4->status).body == BODY_CHIP_LIGHT)) {
        return 0;
      }
      dy = 0xC0;
    } else if (isKwappa) {
      dy = 0xC0;
    }
  }

  if (SEA < (z->s).coord.y - (gZeroRanges[z->posture].h >> 1)) {
    return dy / 2;
  }
  return dy;
#else
  INCCODE("asm/wip/getWallFallSpeed.inc");
#endif
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
  if (c == 2) {
    return BODY_CHIP_ULTIMA;
  }
  if (c == 1) {
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
const struct Rect gZeroRanges[6] = {
    [0] = {-0x0100, -0x0F00, 0x0F00, 0x1E00},
    [1] = {-0x0200, -0x0B00, 0x1A00, 0x1600},
    [2] = {-0x0700, -0x0F00, 0x0E00, 0x1E00},
    [3] = {-0x0200, -0x0B00, 0x1A00, 0x1600},
    [4] = {-0x0100, -0x0F00, 0x0F00, 0x1E00},
    [5] = {-0x0200, -0x0F00, 0x1A00, 0x1E00},
};
// clang-format on

const struct Collision gZeroCollisions[12] = {
    [0] = {
      kind : DRP,
      layer : LAYER_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : HARDNESS_B3,
      unk_0a : 0x04,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-PIXEL(1), -PIXEL(14), PIXEL(16), PIXEL(30)},
    },
    [1] = {
      kind : DRP,
      layer : LAYER_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : HARDNESS_B3,
      unk_0a : 0x04,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-PIXEL(2), -PIXEL(10), PIXEL(26), PIXEL(22)},
    },
    [2] = {
      kind : DRP,
      layer : LAYER_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : HARDNESS_B3,
      unk_0a : 0x04,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-PIXEL(7), -PIXEL(15), PIXEL(16), PIXEL(30)},
    },
    [3] = {
      kind : DRP,
      layer : LAYER_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : HARDNESS_B3,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {-PIXEL(2), -PIXEL(10), PIXEL(26), PIXEL(22)},
    },
    [4] = {
      kind : DRP,
      layer : LAYER_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : HARDNESS_B3,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {-PIXEL(1), -PIXEL(14), PIXEL(16), PIXEL(30)},
    },
    [5] = {
      kind : DRP,
      layer : LAYER_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : HARDNESS_B3,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {-PIXEL(2), -PIXEL(14), PIXEL(26), PIXEL(30)},
    },
    [6] = {
      kind : DRP,
      layer : LAYER_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : HARDNESS_B3 | HARDNESS_WEAK,
      unk_0a : 0x04,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-PIXEL(1), -PIXEL(14), PIXEL(16), PIXEL(30)},
    },
    [7] = {
      kind : DRP,
      layer : LAYER_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : HARDNESS_B3 | HARDNESS_WEAK,
      unk_0a : 0x04,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-PIXEL(2), -PIXEL(10), PIXEL(26), PIXEL(22)},
    },
    [8] = {
      kind : DRP,
      layer : LAYER_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : HARDNESS_B3 | HARDNESS_WEAK,
      unk_0a : 0x04,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-PIXEL(7), -PIXEL(15), PIXEL(16), PIXEL(30)},
    },
    [9] = {
      kind : DRP,
      layer : LAYER_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : HARDNESS_B3 | HARDNESS_WEAK,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {-PIXEL(2), -PIXEL(10), PIXEL(26), PIXEL(22)},
    },
    [10] = {
      kind : DRP,
      layer : LAYER_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : HARDNESS_B3 | HARDNESS_WEAK,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {-PIXEL(1), -PIXEL(14), PIXEL(16), PIXEL(30)},
    },
    [11] = {
      kind : DRP,
      layer : LAYER_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 1,
      hardness : HARDNESS_B3 | HARDNESS_WEAK,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {-PIXEL(2), -PIXEL(14), PIXEL(26), PIXEL(30)},
    },
};
