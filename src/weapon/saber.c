#include "collision.h"
#include "entity.h"
#include "vfx.h"
#include "global.h"
#include "mission.h"
#include "motion.h"
#include "overworld.h"
#include "sound.h"
#include "weapon.h"
#include "zero.h"

struct Saber_b4 {
  struct Zero *z;
  u8 props[8];
  u8 element;
  u8 atk;
  u8 nature;
  bool8 unk;
  u8 unk_c4[40];
};

static const bool8 gIlethasables[25];
static const WeaponFunc sSaberActions[SABER_ACTION_COUNT];
static const motion_t gSaberMotions[24];
static const SoundID gSaberSoundIDs[24];
static const u8 gSaberDamages[24];
static const struct Collision *const sChargeSaberHitboxes[7];

static void Saber_Update(struct Weapon *w);

static void onHit(struct Body *body, struct Coord *r1 UNUSED, struct Coord *r2 UNUSED);

void DeleteSaber(struct Weapon *w) {
  if ((w->s).id == WEAPON_MOVE_Z_SABER) {
    (w->s).flags &= ~DISPLAY;
    (w->s).flags &= ~FLIPABLE;
    (w->body).status = 0;
    (w->body).prevStatus = 0;
    (w->body).invincibleTime = 0;
    (w->s).flags &= ~COLLIDABLE;
    SET_WEAPON_ROUTINE(w, ENTITY_DISAPPEAR);
  }
}

WIP struct Weapon *CreateWeaponSaber(struct Zero *z, u8 r1) {
#if MODERN
  struct Weapon *w;

  KillAllWeapons(DeleteSaber);
  w = (struct Weapon *)AllocEntityFirst(gWeaponHeaderPtr);
  if (w != NULL) {
    u8 element;

    if ((z->unk_b4).mainCopy == WEAPON_SABER) {
      INIT_WEAPON_ROUTINE(w, WEAPON_MOVE_Z_SABER);
      (w->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (w->s).taskCol = 16;
      (w->s).tileNum = gWeaponTileNum[0];
      (w->s).palID = gWeaponPalIDs[0];
      element = gSaberElements[((&z->unk_b4)->status).element];
      SetWeaponElement(0, element);

    } else {
      INIT_WEAPON_ROUTINE(w, WEAPON_MOVE_Z_SABER);
      (w->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (w->s).taskCol = 16;
      (w->s).tileNum = gWeaponTileNum[1];
      (w->s).palID = gWeaponPalIDs[1];
      element = gSaberElements[((&z->unk_b4)->status).element];
      SetWeaponElement(1, element);
    }

    z->saberAction = r1;
    (&w->unk_b4)->z = z;
    (w->s).work[0] = r1;
    (w->s).work[1] = ((&z->unk_b4)->status).element;
  }
  return w;
#else
  INCCODE("asm/wip/CreateWeaponSaber.inc");
#endif
}

WIP static void Saber_Init(struct Weapon *w) {
#if MODERN
  const struct Collision *collisions;
  struct Saber_b4 *b4 = (struct Saber_b4 *)&(w->unk_b4);
  struct Zero *z = b4->z;

  SET_WEAPON_ROUTINE(w, ENTITY_MAIN);
  InitNonAffineMotion(&w->s);
  ResetDynamicMotion(&w->s);
  (w->s).flags |= DISPLAY;
  (w->s).flags |= FLIPABLE;
  SetMotion(&w->s, gSaberMotions[(w->s).work[0]]);
  collisions = *gSaberCollisions[(w->s).work[0]];
  (w->s).flags |= COLLIDABLE;
  InitBody(&w->body, collisions, &(w->s).coord, 1);
  (w->body).parent = (struct CollidableEntity *)w;
  (w->body).fn = NULL;

  if (gSaberSoundIDs[(w->s).work[0]] != MUS_DUMMY) {
    if ((w->s).work[0] == SABER_ZANEIDAN) {
      if (z->tripleSlashCounter > 0) {
        PlaySound(SE_SLASH_UP);  // Saber wave by Cottus
      } else {
        PlaySound(gSaberSoundIDs[(w->s).work[0]]);  // Saber blade (EXSkill)
      }
    } else {
      PlaySound(gSaberSoundIDs[(w->s).work[0]]);
    }
  }

  if ((w->s).work[0] == SABER_ZANEIDAN) {
    if (z->tripleSlashCounter == 0) {
      if ((z->unk_b4).status.element == ELEMENT_ICE) {
        CreateThrowBlade(z, w, TRUE);
      } else {
        CreateThrowBlade(z, w, FALSE);
      }
    } else {
      CreateSaberWave(z, w, FALSE);
    }
  }

  if (((((w->s).work[0] == SABER_TENRETUJIN) || ((w->s).work[0] == SABER_SMASH)) || ((w->s).work[0] == 0x16)) || !(collisions[0].nature & BODY_NATURE_B1)) {
    b4->element = 0;
  } else {
    b4->element = gSaberElements[(w->s).work[1]];
  }
  b4->atk = gSaberDamages[(w->s).work[0]] + CalcSaberBonus(z);
  if (isElfUsed_2(z, ELF_ILETHAS) && gIlethasables[(w->s).work[0]]) {
    b4->nature = collisions[0].nature | BODY_NATURE_ILETHAS;
  } else {
    b4->nature = collisions[0].nature;
  }
  if ((w->s).work[0] == SABER_SMASH_ELEC) {
    b4->element = gSaberElements[(w->s).work[1]];
    b4->nature |= BODY_NATURE_B1;
  }
  InitWeaponBody(&w->body, collisions, b4->atk, b4->element, b4->nature, -1);
  (w->s).work[2] = 0;
  b4->unk = TRUE;
  (w->body).fn = onHit;
  Saber_Update(w);
#else
  INCCODE("asm/wip/Saber_Init.inc");
#endif
}

WIP static void Saber_Update(struct Weapon *w) {
#if MODERN
  bool8 xflip;
  struct Saber_b4 *b4 = (struct Saber_b4 *)&(w->unk_b4);
  struct Zero *z = b4->z;

  if ((w->s).work[0] != z->saberAction) {
    (w->s).flags &= ~DISPLAY;
    (w->s).flags &= ~FLIPABLE;
    (w->body).status = 0;
    (w->body).prevStatus = 0;
    (w->body).invincibleTime = 0;
    (w->s).flags &= ~COLLIDABLE;
    SET_WEAPON_ROUTINE(w, ENTITY_DISAPPEAR);
    return;
  }

  if (b4->unk && ((w->body).status & BODY_STATUS_BLOCKED)) {
    PlaySound(SE_BLOCKED);
    b4->unk = FALSE;
  }

  if ((w->s).work[0] == SABER_WALL) {
    if ((z->s).mode[1] == ZERO_WALL) {
      xflip = (((z->s).flags & X_FLIP) != 0);
      if (xflip) {
        (w->s).flags |= X_FLIP;
      } else {
        (w->s).flags &= ~X_FLIP;
      }

    } else {
      xflip = (((z->s).flags & X_FLIP) == 0);
      if (xflip) {
        (w->s).flags |= X_FLIP;
      } else {
        (w->s).flags &= ~X_FLIP;
      }
    }
  } else {
    xflip = (((z->s).flags & X_FLIP) != 0);
    if (xflip) {
      (w->s).flags |= X_FLIP;
    } else {
      (w->s).flags &= ~X_FLIP;
    }
  }

  (w->s).spr.xflip = xflip;
  (w->s).spr.oam.xflip = xflip;

  (w->s).coord.x = (z->s).coord.x;
  (w->s).coord.y = (z->s).coord.y;

  (sSaberActions[(w->s).work[0]])(w);
#else
  INCCODE("asm/wip/Saber_Update.inc");
#endif
}

static void Saber_Die(struct Weapon *w) {
  (w->s).flags &= ~DISPLAY;
  SET_WEAPON_ROUTINE(w, ENTITY_EXIT);
}

static void onHit(struct Body *body, struct Coord *r1 UNUSED, struct Coord *r2 UNUSED) {
  if ((body->hitboxFlags & BODY_STATUS_B2) && (gMission.weaponCount[WEAPON_SABER] < 0xFFFF)) {
    gMission.weaponCount[WEAPON_SABER]++;
  }
}

static void saberTripleSlash(struct Weapon *w) {
  UpdateMotionGraphic(&w->s);

  {
    struct Body *body = &w->body;
    const struct Collision *collisions = (gSaberCollisions[(w->s).work[0]])[((w->s).motion.cmdIdx)];
    const struct Saber_b4 *b4 = (struct Saber_b4 *)&(w->unk_b4);
    InitWeaponBody(body, collisions, b4->atk, b4->element, b4->nature, -1);
  }

  if ((w->s).motion.state == MOTION_END) {
    SET_WEAPON_ROUTINE(w, ENTITY_DIE)
  }
}

WIP static void saberAirSlash(struct Weapon *w) {
#if MODERN
  struct Saber_b4 *b4 = (struct Saber_b4 *)&w->unk_b4;
  struct Zero *z = b4->z;
  if ((w->s).mode[1] != 0) {
    motion_t m = MOTION_VALUE(z);
    if ((m == MOTION(DM025_ZERO_SABER_AIR, 0x00)) && ((z->s).motion.cmdIdx == 0)) {
      (w->s).flags &= ~DISPLAY;
      (w->s).flags &= ~FLIPABLE;
      (w->body).status = 0;
      (w->body).prevStatus = 0;
      (w->body).invincibleTime = 0;
      (w->s).flags &= ~COLLIDABLE;
      SET_WEAPON_ROUTINE(w, ENTITY_DISAPPEAR);
      return;
    }

  } else {
    if ((w->s).work[2] < 2) {
      SetDDP(&w->body, gSaberGeneralCollisions);
      (w->s).flags &= ~DISPLAY;
      (w->s).work[2]++;
    } else {
      (w->s).flags |= DISPLAY;
      (w->s).mode[1]++;
    }
  }

  if ((w->s).mode[1] == 1) {
    UpdateMotionGraphic(&w->s);
    if ((w->s).motion.cmdIdx > 3) {
      if (MOTION_VALUE(z) == MOTION(DM025_ZERO_SABER_AIR, 0x00)) {
        b4->atk = 10 + CalcSaberBonus(z);
        b4->element = 0;
      } else {
        (w->s).mode[1]++;
      }
    }
    InitWeaponBody(&w->body, gSaberCollisions[(w->s).work[0]][(w->s).motion.cmdIdx], b4->atk, b4->element, b4->nature, -1);
    return;
  }
  if ((w->s).mode[1] != 2) {
    return;
  }
  if ((w->s).mode[2] == 0) {
    SetMotion(&w->s, MOTION(DM098_SABER_CHARGE, 0x01));
    SetDDP(&w->body, gSaberGeneralCollisions);
    (w->s).mode[2]++;
  }
  UpdateMotionGraphic(&w->s);
  if ((w->s).motion.state != MOTION_END) {
    return;
  }
  SET_WEAPON_ROUTINE(w, ENTITY_DIE);
#else
  INCCODE("asm/wip/saberAirSlash.inc");
#endif
}

WIP static void saberChargeAtk(struct Weapon *w) {
#if MODERN
  struct Saber_b4 *b4 = (struct Saber_b4 *)&w->unk_b4;
  struct Zero *z = b4->z;
  if ((w->s).mode[2] == 0) {
    if (z->chargeSaber != 0) {
      motion_t m = gSaberMotions[z->chargeSaber + 7];
      if (m != MOTION_VALUE(w)) {
        if ((m == MOTION(DM098_SABER_CHARGE, 0x02)) && ((w->s).motion.cmdIdx > 6)) {
          GotoMotion(&w->s, MOTION(DM098_SABER_CHARGE, 0x02), 7, 1);
        } else {
          GotoMotion(&w->s, m, (w->s).motion.cmdIdx, (w->s).motion.duration);
        }
      }
      if ((((w->s).work[0] == 8) && ((w->s).motion.cmdIdx == 3)) && ((w->s).motion.duration < 2)) {
        oz_080b3820(&(w->s).coord, ((w->s).flags >> 4) & 1);
      }
      UpdateMotionGraphic(&w->s);
      InitWeaponBody(&w->body, gSaberCollisions[z->chargeSaber + 7][(w->s).motion.cmdIdx], b4->atk, b4->element, b4->nature, -1);
      if ((w->s).motion.state != MOTION_END) {
        return;
      }
      if (m == MOTION(DM098_SABER_CHARGE, 0x02)) {
        (w->s).mode[2] = 1;
        (w->s).mode[3] = 0;
        b4->atk = 10 + CalcSaberBonus(z);
        b4->element = 0;
        return;
      }
    }
  } else {
    if ((w->s).mode[2] == 1) {
      if ((w->s).mode[3] == 0) {
        GotoMotion(&w->s, MOTION(DM098_SABER_CHARGE, 0x00), 4, 2);
        (w->s).mode[3]++;
      }
      UpdateMotionGraphic(&w->s);
      InitWeaponBody(&w->body, sChargeSaberHitboxes[(w->s).motion.cmdIdx], b4->atk, b4->element, b4->nature, -1);
      motion_t m = MOTION_VALUE(z);
      if (m == MOTION(DM025_ZERO_SABER_AIR, 0x00)) {
        return;
      }
      if (m == MOTION(DM025_ZERO_SABER_AIR, 0x02)) {
        return;
      }
      (w->s).mode[2] = 2;
      (w->s).mode[3] = 0;
      return;
    }
    if ((w->s).mode[3] == 0) {
      SetMotion(&w->s, MOTION(DM098_SABER_CHARGE, 0x01));
      (w->s).mode[3]++;
    }
    UpdateMotionGraphic(&w->s);
    SetDDP(&w->body, gSaberGeneralCollisions);
    if ((w->s).motion.state != MOTION_END) {
      return;
    }
  }
  SET_WEAPON_ROUTINE(w, ENTITY_DIE);
#else
  INCCODE("asm/wip/saberChargeAtk.inc");
#endif
}

// 天裂刃, テンレツジン, Split Heavens
static void saberSplitThrow(struct Weapon *w) {
  const struct Weapon_b4 *b4 = &(w->unk_b4);
  struct Zero *z = b4->z;

  if ((z->s).mode[1] != ZERO_AIR) {
    (w->s).flags &= ~DISPLAY;
    (w->s).flags &= ~FLIPABLE;
    (w->body).status = 0;
    (w->body).prevStatus = 0;
    (w->body).invincibleTime = 0;
    (w->s).flags &= ~COLLIDABLE;
    SET_WEAPON_ROUTINE(w, ENTITY_DISAPPEAR);
    return;
  }

  if ((w->s).mode[2] == 0) {
    if ((z->s).mode[2] != 1) {
      motion_t m = MOTION_VALUE(w);
      if (m == MOTION(DM092_TENRETSUJIN, 0x01)) {
        SetMotion(&w->s, MOTION(DM092_TENRETSUJIN, 0x02));
      } else {
        SetMotion(&w->s, MOTION(DM092_TENRETSUJIN, 0x05));
      }
      UpdateMotionGraphic(&w->s);
      SetDDP(&w->body, gSaberGeneralCollisions);
      (w->s).mode[2]++;
      return;
    }

    UpdateMotionGraphic(&w->s);

    {
      struct Body *body = &w->body;
      const struct Collision *collisions = (gSaberCollisions[(w->s).work[0]])[((w->s).motion.cmdIdx)];
      InitWeaponBody(body, collisions, (b4->props)[1][1], (b4->props)[1][0], (b4->props)[1][2], -1);
    }
    return;
  }

  UpdateMotionGraphic(&w->s);
  if ((w->s).motion.state == MOTION_END) {
    SET_WEAPON_ROUTINE(w, ENTITY_DIE);
  }
}

static void saberGale(struct Weapon *w) {
  const struct Weapon_b4 *b4 = &(w->unk_b4);
  struct Zero *z = b4->z;

  if ((z->s).mode[1] != ZERO_GROUND) {
    (w->s).flags &= ~DISPLAY;
    (w->s).flags &= ~FLIPABLE;
    (w->body).status = 0;
    (w->body).prevStatus = 0;
    (w->body).invincibleTime = 0;
    (w->s).flags &= ~COLLIDABLE;
    SET_WEAPON_ROUTINE(w, ENTITY_DISAPPEAR);
    return;
  }

  (w->s).work[2]++;
  if ((w->s).mode[2] == 0) {
    u8 val;

    motion_t m = MOTION_VALUE(z);
    if (m != MOTION(DM024_ZERO_GALE, 0x00)) {
      motion_t m = MOTION_VALUE(w);
      if (m == MOTION(DM097_GALE_ATTACK, 0x00)) {
        SetMotion(&w->s, MOTION(DM097_GALE_ATTACK, 0x01));
      } else {
        SetMotion(&w->s, MOTION(DM097_GALE_ATTACK, 0x03));
      }
      UpdateMotionGraphic(&w->s);
      SetDDP(&w->body, gSaberGeneralCollisions);
      (w->s).mode[2]++;
      return;
    }

    UpdateMotionGraphic(&w->s);
    val = (w->s).work[2] >> 2;
    if (val > 2) val = 2;

    {
      struct Body *body = &w->body;
      const struct Collision *collisions = (gSaberCollisions[(w->s).work[0]])[0];
      InitWeaponBody(body, collisions, (b4->props)[1][1], (b4->props)[1][0], (b4->props)[1][2], val + 1);
    }
    return;
  }

  UpdateMotionGraphic(&w->s);
  if ((w->s).motion.state == MOTION_END) {
    SET_WEAPON_ROUTINE(w, ENTITY_DIE);
  }
}

WIP static void saberJumpRolling(struct Weapon *w) {
#if MODERN
  struct Saber_b4 *b4 = (struct Saber_b4 *)&(w->unk_b4);
  struct Zero *z = b4->z;

  if ((w->s).mode[2] == 0) {
    const u8 idx = (w->s).motion.cmdIdx;
    const motion_t m = MOTION_VALUE(z);
    if ((m == MOTION(DM026_ZERO_SABER_AIR_ROLLING, 0x00)) || ((z->s).motion.cmdIdx == idx)) {
      UpdateMotionGraphic(&w->s);
      {
        struct Body *body = &w->body;
        const struct Collision *collisions = gSaberCollisions[(w->s).work[0]][idx];
        const struct Saber_b4 *b4 = (struct Saber_b4 *)&(w->unk_b4);
        InitWeaponBody(body, collisions, b4->atk, b4->element, b4->nature, ((s8)idx >> 1) + 1);
      }
      if ((w->s).motion.state == MOTION_END) {
        (w->s).mode[2] = 1;
        (w->s).mode[3] = 0;
        b4->atk = 10 + CalcSaberBonus(z);
        b4->element = gSaberElements[0];
      }
      return;
    }
    (w->s).flags &= ~DISPLAY;
    (w->s).flags &= ~FLIPABLE;
    (w->body).status = 0;
    (w->body).prevStatus = 0;
    (w->body).invincibleTime = 0;
    (w->s).flags &= ~COLLIDABLE;
    SET_WEAPON_ROUTINE(w, ENTITY_DISAPPEAR);
    return;
  }

  if ((w->s).mode[2] == 1) {
    motion_t m;
    if ((w->s).mode[3] == 0) {
      GotoMotion(&w->s, MOTION(DM098_SABER_CHARGE, 0x00), 4, 2);
      (w->s).mode[3]++;
    }
    UpdateMotionGraphic(&w->s);
    {
      struct Body *body = &w->body;
      const struct Collision *collisions = gSaberCollisions[(w->s).work[0]][(w->s).motion.cmdIdx];
      InitWeaponBody(&w->body, collisions, b4->atk, b4->element, b4->nature, -1);
    }

    m = MOTION_VALUE(z);
    if ((m != MOTION(DM025_ZERO_SABER_AIR, 0x00)) && (m != MOTION(DM026_ZERO_SABER_AIR_ROLLING, 0x00))) {
      (w->s).mode[2] = 2;
      (w->s).mode[3] = 0;
    }
    return;
  }

  if ((w->s).mode[3] == 0) {
    SetMotion(&w->s, MOTION(DM098_SABER_CHARGE, 0x01));
    (w->s).mode[3]++;
  }
  UpdateMotionGraphic(&w->s);
  SetDDP(&w->body, gSaberGeneralCollisions);
  if ((w->s).motion.state == MOTION_END) {
    SET_WEAPON_ROUTINE(w, ENTITY_DIE);
  }
#else
  INCCODE("asm/wip/saberJumpRolling.inc");
#endif
}

static void saberDashRolling(struct Weapon *w) {
  motion_t m;
  const struct Saber_b4 *b4 = (struct Saber_b4 *)&(w->unk_b4);
  struct Zero *z = b4->z;
  UpdateMotionGraphic(&w->s);

  m = MOTION_VALUE(z);
  if ((m != MOTION(DM026_ZERO_SABER_AIR_ROLLING, 0x01)) || (((z->s).motion.cmdIdx != (w->s).motion.cmdIdx))) {
    (w->s).flags &= ~DISPLAY;
    (w->s).flags &= ~FLIPABLE;
    (w->body).status = 0;
    (w->body).prevStatus = 0;
    (w->body).invincibleTime = 0;
    (w->s).flags &= ~COLLIDABLE;
    SET_WEAPON_ROUTINE(w, ENTITY_DISAPPEAR);
  } else {
    struct Body *body = &w->body;
    const struct Collision *collisions = (gSaberCollisions[(w->s).work[0]])[(w->s).motion.cmdIdx];
    InitWeaponBody(body, collisions, b4->atk, b4->element, b4->nature, ((w->s).motion.cmdIdx >> 1) + 1);
  }
}

WIP static void saberSmash(struct Weapon *w) {
#if MODERN
  const struct Saber_b4 *b4 = (struct Saber_b4 *)&(w->unk_b4);
  struct Zero *z = b4->z;

  if ((w->s).mode[2] == 0) {
    switch (MOTION_VALUE(z)) {
      case MOTION(DM027_ZERO_SABER_SMASH, 0x00): {
        (w->s).flags &= ~DISPLAY;
        if ((w->s).work[2] > 1) {
          UpdateMotionGraphic(&w->s);
          (w->s).flags |= DISPLAY;
          InitWeaponBody(&w->body, gSaberCollisions[(w->s).work[0]][(w->s).motion.cmdIdx], b4->atk, b4->element, b4->nature, -1);
          (w->s).mode[3]++;
          break;
        }
        (w->s).work[2]++;
        break;
      }

      case MOTION(DM027_ZERO_SABER_SMASH, 0x01): {
        if ((w->s).work[0] == SABER_SMASH) {
          SetMotion(&w->s, MOTION(DM100_RAKUSAIGA, 0x01));
        } else {
          struct Zero_b4 *b4;
          SetMotion(&w->s, MOTION(DM100_RAKUSAIGA, 0x03));
          b4 = &z->unk_b4;
          if (((b4->status).element == ELEMENT_THUNDER) && (z->unk_13a == 0)) {
            CreateSmashElec(z, &(w->s).coord, 0);
            CreateSmashElec(z, &(w->s).coord, 1);
          }
        }
        UpdateMotionGraphic(&w->s);
        (w->s).flags |= DISPLAY;
        (w->s).mode[2]++;
        break;
      }

      default: {
        (w->s).flags &= ~DISPLAY;
        (w->s).flags &= ~FLIPABLE;
        (w->body).status = 0;
        (w->body).prevStatus = 0;
        (w->body).invincibleTime = 0;
        (w->s).flags &= ~COLLIDABLE;
        SET_WEAPON_ROUTINE(w, ENTITY_DISAPPEAR);
        break;
      }
    }

    return;
  }

  UpdateMotionGraphic(&w->s);
  if ((w->s).motion.state == MOTION_END) {
    SET_WEAPON_ROUTINE(w, ENTITY_DIE);
  }
#else
  INCCODE("asm/wip/saberSmash.inc");
#endif
}

// --------------------------------------------

// clang-format off

// idx: (w->s).work[0]
static const WeaponFunc sSaberActions[SABER_ACTION_COUNT] = {
    [SABER_TRIPLE_1] =           saberTripleSlash,
    [SABER_TRIPLE_2] =           saberTripleSlash,
    [SABER_TRIPLE_3] =           saberTripleSlash,
    [SABER_UNK_03] =             saberTripleSlash,
    [SABER_DASH] =               saberTripleSlash,
    [SABER_AIR] =                saberAirSlash,
    [SABER_WALL] =               saberTripleSlash,
    [SABER_LADDER] =             saberTripleSlash,
    [SABER_CHARGE] =             saberChargeAtk,
    [SABER_CHARGE_AIR] =         saberChargeAtk,
    [SABER_CHARGE_WALL] =        saberChargeAtk,
    [SABER_CHARGE_LADDER] =      saberChargeAtk,
    [SABER_UNK_12] =             saberTripleSlash,
    [SABER_ZANEIDAN] =           saberTripleSlash,
    [SABER_TENRETUJIN] =         saberTripleSlash,
    [SABER_TENRETUJIN_FIRE] =    saberTripleSlash,
    [SABER_TENRETUJIN_2] =       saberSplitThrow,
    [SABER_TENRETUJIN_FIRE_2] =  saberSplitThrow,
    [SABER_REPUGEKI] =           saberGale,
    [SABER_UNK_19] =             saberGale,
    [SABER_AIR_ROLLING] =        saberJumpRolling,
    [SABER_DASH_ROLLING] =       saberDashRolling,
    [SABER_SMASH] =              saberSmash,
    [SABER_SMASH_ELEC] =         saberSmash,
};

static const motion_t gSaberMotions[24] = {
    MOTION(0x58, 0x00),
    MOTION(0x59, 0x00),
    MOTION(0x5A, 0x00),
    MOTION(0x5F, 0x00),
    MOTION(0x60, 0x00),
    MOTION(0x62, 0x00),
    MOTION(0x65, 0x00),
    MOTION(0x66, 0x00),
    MOTION(0x5E, 0x00),
    MOTION(0x62, 0x02),
    MOTION(0x65, 0x01),
    MOTION(0x66, 0x01),
    MOTION(0x5B, 0x00),
    MOTION(0x5D, 0x00),
    MOTION(0x5C, 0x00),
    MOTION(0x5C, 0x03),
    MOTION(0x5C, 0x01),
    MOTION(0x5C, 0x04),
    MOTION(0x61, 0x00),
    MOTION(0x61, 0x02),
    MOTION(0x63, 0x00),
    MOTION(0x63, 0x01),
    MOTION(0x64, 0x00),
    MOTION(0x64, 0x02),
};
// clang-format on

static const SoundID gSaberSoundIDs[24] = {
    0x0015, 0x0015, 0x0015, 0x0015, 0x0015, 0x0015, 0x0015, 0x0015, 0x0019, 0x0019, 0x0019, 0x0019, 0x0011, 0x0013, 0x0000, 0x0000, 0x0013, 0x0013, 0x0014, 0x0014, 0x0010, 0x0010, 0x0014, 0x0014,
};

static const u8 gSaberDamages[24] = {
    8, 8, 8, 6, 10, 8, 8, 8, 16, 16, 16, 16, 10, 10, 14, 14, 14, 14, 12, 12, 4, 6, 16, 16,
};

const u8 gSaberElements[4] = {0, 1, 2, 3};

const struct Collision gTripleSlash1Hitboxes_0835f0ec[3][2] = {
    // 0
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 4,
          unk_04 : 1,
          element : 0,
          nature : 0x10,
          comboLv : 1,
          hitzone : 0,
          hardness : 0,
          unk_0a : 0,
          remaining : 3,
          unk_0c : 0x20,
          range : {0xE000, 0xEE00, 0x2600, 0x1A00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 0xFF,
          hardness : 0,
          unk_0a : 0,
          remaining : 2,
          unk_0c : 0,
          range : {0xE000, 0xEE00, 0x2600, 0x1A00},
        },
    },

    // 1
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 4,
          unk_04 : 1,
          element : 0,
          nature : 0x10,
          comboLv : 1,
          hitzone : 0,
          hardness : 0,
          unk_0a : 0,
          remaining : 1,
          unk_0c : 0x20,
          range : {0xF800, 0xDE00, 0x3A00, 0x800},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 0xFF,
          hardness : 0,
          unk_0a : 0,
          remaining : 0,
          unk_0c : 0,
          range : {0xF800, 0xDE00, 0x3A00, 0x800},
        },
    },

    // 2
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 4,
          unk_04 : 1,
          element : 0,
          nature : 0x10,
          comboLv : 1,
          hitzone : 0,
          hardness : 0,
          unk_0a : 0,
          remaining : 1,
          unk_0c : 0x20,
          range : {0xD00, 0xDF00, 0x1000, 0xA00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 0xFF,
          hardness : 0,
          unk_0a : 0,
          remaining : 0,
          unk_0c : 0,
          range : {0xD00, 0xDF00, 0x1000, 0xA00},
        },
    }};

const struct Collision gTripleSlash2Hitboxes_0835f17c[4][2] = {
    // 0
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 6,
          unk_04 : 1,
          element : 0,
          nature : 0x10,
          comboLv : 2,
          hitzone : 0,
          hardness : 0,
          unk_0a : 0,
          remaining : 5,
          unk_0c : 0x20,
          range : {0xF100, 0xDE00, 0x3800, 0xE00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 0xFF,
          hardness : 0,
          unk_0a : 0,
          remaining : 4,
          unk_0c : 0,
          range : {0xF100, 0xDE00, 0x3800, 0xE00},
        },
    },

    // 1
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 6,
          unk_04 : 1,
          element : 0,
          nature : 0x10,
          comboLv : 2,
          hitzone : 0,
          hardness : 0,
          unk_0a : 0,
          remaining : 3,
          unk_0c : 0x20,
          range : {0xD900, 0xEE00, 0x1A00, 0x1600},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 0xFF,
          hardness : 0,
          unk_0a : 0,
          remaining : 2,
          unk_0c : 0,
          range : {0xD900, 0xEE00, 0x1A00, 0x1600},
        },
    },

    // 2
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 6,
          unk_04 : 1,
          element : 0,
          nature : 0x10,
          comboLv : 2,
          hitzone : 0,
          hardness : 0,
          unk_0a : 0,
          remaining : 1,
          unk_0c : 0x20,
          range : {0xEA00, 0x0, 0x2F00, 0xE00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 0xFF,
          hardness : 0,
          unk_0a : 0,
          remaining : 0,
          unk_0c : 0,
          range : {0xEA00, 0x0, 0x2F00, 0xE00},
        },
    },

    // 3
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 6,
          unk_04 : 1,
          element : 0,
          nature : 0x10,
          comboLv : 2,
          hitzone : 0,
          hardness : 0,
          unk_0a : 0,
          remaining : 1,
          unk_0c : 0x20,
          range : {0xF200, 0x100, 0x1E00, 0xE00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 0xFF,
          hardness : 0,
          unk_0a : 0,
          remaining : 0,
          unk_0c : 0,
          range : {0xF200, 0x100, 0x1E00, 0xE00},
        },
    },
};

const struct Collision gTripleSlash3Hitboxes_0835f23c[7][2] = {
    // 0
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 8,
          unk_04 : 1,
          element : 0,
          nature : 0x10,
          comboLv : 3,
          hitzone : 0,
          hardness : 0,
          unk_0a : 0,
          remaining : 1,
          unk_0c : 0x20,
          range : {0x600, 0xFE00, 0x800, 0x1000},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 0xFF,
          hardness : 0,
          unk_0a : 0,
          remaining : 0,
          unk_0c : 0,
          range : {0x600, 0xFE00, 0x800, 0x1000},
        },
    },

    // 1
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 8,
          unk_04 : 1,
          element : 0,
          nature : 0x10,
          comboLv : 3,
          hitzone : 0,
          hardness : 0,
          unk_0a : 0,
          remaining : 1,
          unk_0c : 0x20,
          range : {0x1300, 0xEF00, 0x900, 0x1200},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 0xFF,
          hardness : 0,
          unk_0a : 0,
          remaining : 0,
          unk_0c : 0,
          range : {0x1300, 0xEF00, 0x900, 0x1200},
        },
    },

    // 2
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 8,
          unk_04 : 1,
          element : 0,
          nature : 0x10,
          comboLv : 3,
          hitzone : 0,
          hardness : 0,
          unk_0a : 0,
          remaining : 9,
          unk_0c : 0x20,
          range : {0x1400, 0xE400, 0xE00, 0x2400},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 0xFF,
          hardness : 0,
          unk_0a : 0,
          remaining : 8,
          unk_0c : 0,
          range : {0x1400, 0xE400, 0xE00, 0x2400},
        },
    },

    // 3
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 8,
          unk_04 : 1,
          element : 0,
          nature : 0x10,
          comboLv : 3,
          hitzone : 0,
          hardness : 0,
          unk_0a : 0,
          remaining : 7,
          unk_0c : 0x20,
          range : {0x0, 0xCF00, 0x2200, 0xC00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 0xFF,
          hardness : 0,
          unk_0a : 0,
          remaining : 6,
          unk_0c : 0,
          range : {0x0, 0xCF00, 0x2200, 0xC00},
        },
    },

    // 4
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 8,
          unk_04 : 1,
          element : 0,
          nature : 0x10,
          comboLv : 3,
          hitzone : 0,
          hardness : 0,
          unk_0a : 0,
          remaining : 5,
          unk_0c : 0x20,
          range : {0xE200, 0xCF00, 0x1C00, 0xC00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 0xFF,
          hardness : 0,
          unk_0a : 0,
          remaining : 4,
          unk_0c : 0,
          range : {0xE200, 0xCF00, 0x1C00, 0xC00},
        },
    },

    // 5
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 8,
          unk_04 : 1,
          element : 0,
          nature : 0x10,
          comboLv : 3,
          hitzone : 0,
          hardness : 0,
          unk_0a : 0,
          remaining : 3,
          unk_0c : 0x20,
          range : {0xD600, 0xE700, 0x1700, 0x2200},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 0xFF,
          hardness : 0,
          unk_0a : 0,
          remaining : 2,
          unk_0c : 0,
          range : {0xD600, 0xE700, 0x1700, 0x2200},
        },
    },

    // 6
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 8,
          unk_04 : 1,
          element : 0,
          nature : 0x10,
          comboLv : 3,
          hitzone : 0,
          hardness : 0,
          unk_0a : 0,
          remaining : 1,
          unk_0c : 0x20,
          range : {0xDF00, 0xFD00, 0x1D00, 0xA00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 0xFF,
          hardness : 0,
          unk_0a : 0,
          remaining : 0,
          unk_0c : 0,
          range : {0xDF00, 0xFD00, 0x1D00, 0xA00},
        },
    },
};

const struct Collision gTripleSlash4Hitboxes_0835f38c[5][2] = {
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 4,
          unk_04 : 0x01,
          element : 0x00,
          nature : 0x10,
          comboLv : 0x01,
          hitzone : 0x00,
          hardness : 0x00,
          unk_0a : 0x00,
          remaining : 3,
          unk_0c : 0x00000020,
          range : {-0x2100, -0x1500, 0x1200, 0x1500},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 0xFF,
          hardness : 0x00,
          unk_0a : 0x00,
          remaining : 2,
          unk_0c : 0x00000000,
          range : {-0x2100, -0x1500, 0x1200, 0x1500},
        },
    },
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 4,
          unk_04 : 0x01,
          element : 0x00,
          nature : 0x10,
          comboLv : 0x01,
          hitzone : 0x00,
          hardness : 0x00,
          unk_0a : 0x00,
          remaining : 1,
          unk_0c : 0x00000020,
          range : {0x0500, -0x2100, 0x3900, 0x0B00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 0xFF,
          hardness : 0x00,
          unk_0a : 0x00,
          remaining : 0,
          unk_0c : 0x00000000,
          range : {0x0500, -0x2100, 0x3900, 0x0B00},
        },
    },
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 4,
          unk_04 : 0x01,
          element : 0x00,
          nature : 0x10,
          comboLv : 0x01,
          hitzone : 0x00,
          hardness : 0x00,
          unk_0a : 0x00,
          remaining : 3,
          unk_0c : 0x00000020,
          range : {-0x2100, -0x1500, 0x1200, 0x1500},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 0xFF,
          hardness : 0x00,
          unk_0a : 0x00,
          remaining : 2,
          unk_0c : 0x00000000,
          range : {-0x2100, -0x1500, 0x1200, 0x1500},
        },
    },
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 4,
          unk_04 : 0x01,
          element : 0x00,
          nature : 0x10,
          comboLv : 0x01,
          hitzone : 0x00,
          hardness : 0x00,
          unk_0a : 0x00,
          remaining : 1,
          unk_0c : 0x00000020,
          range : {0x0500, -0x2100, 0x3900, 0x0B00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 0xFF,
          hardness : 0x00,
          unk_0a : 0x00,
          remaining : 0,
          unk_0c : 0x00000000,
          range : {0x0500, -0x2100, 0x3900, 0x0B00},
        },
    },
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 4,
          unk_04 : 0x01,
          element : 0x00,
          nature : 0x10,
          comboLv : 0x01,
          hitzone : 0x00,
          hardness : 0x00,
          unk_0a : 0x00,
          remaining : 1,
          unk_0c : 0x00000020,
          range : {0x1600, -0x2100, 0x1600, 0x0B00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 0xFF,
          hardness : 0x00,
          unk_0a : 0x00,
          remaining : 0,
          unk_0c : 0x00000000,
          range : {0x1600, -0x2100, 0x1600, 0x0B00},
        },
    },
};

const struct Collision gSaberDashHitboxes_0835f47c[4][2] = {
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 4,
          unk_04 : 0x01,
          element : 0x00,
          nature : 0x10,
          comboLv : 0x01,
          hitzone : 0x00,
          hardness : 0x00,
          unk_0a : 0x00,
          remaining : 5,
          unk_0c : 0x00000020,
          range : {-0x1600, -0x1800, 0x3400, 0x1400},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 0xFF,
          hardness : 0x00,
          unk_0a : 0x00,
          remaining : 4,
          unk_0c : 0x00000000,
          range : {-0x1600, -0x1800, 0x3400, 0x1400},
        },
    },
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 4,
          unk_04 : 0x01,
          element : 0x00,
          nature : 0x10,
          comboLv : 0x01,
          hitzone : 0x00,
          hardness : 0x00,
          unk_0a : 0x00,
          remaining : 3,
          unk_0c : 0x00000020,
          range : {-0x2600, -0x0700, 0x1300, 0x1000},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 0xFF,
          hardness : 0x00,
          unk_0a : 0x00,
          remaining : 2,
          unk_0c : 0x00000000,
          range : {-0x2600, -0x0700, 0x1300, 0x1000},
        },
    },
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 4,
          unk_04 : 0x01,
          element : 0x00,
          nature : 0x10,
          comboLv : 0x01,
          hitzone : 0x00,
          hardness : 0x00,
          unk_0a : 0x00,
          remaining : 1,
          unk_0c : 0x00000020,
          range : {-0x0900, 0x0200, 0x2A00, 0x0A00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 0xFF,
          hardness : 0x00,
          unk_0a : 0x00,
          remaining : 0,
          unk_0c : 0x00000000,
          range : {-0x0900, 0x0200, 0x2A00, 0x0A00},
        },
    },
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 4,
          unk_04 : 0x01,
          element : 0x00,
          nature : 0x10,
          comboLv : 0x01,
          hitzone : 0x00,
          hardness : 0x00,
          unk_0a : 0x00,
          remaining : 1,
          unk_0c : 0x00000020,
          range : {0x0700, 0x0200, 0x0C00, 0x0A00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : 1,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 0xFF,
          hardness : 0x00,
          unk_0a : 0x00,
          remaining : 0,
          unk_0c : 0x00000000,
          range : {0x0700, 0x0200, 0x0C00, 0x0A00},
        },
    },
};

const struct Collision Collision_ARRAY_0835f53c[108] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 4,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 5,
      unk_0c : 0x00000020,
      range : {-0x0200, -0x2200, 0x2A00, 0x1600},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 4,
      unk_0c : 0x00000000,
      range : {-0x0200, -0x2200, 0x2A00, 0x1600},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 4,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000020,
      range : {-0x2000, -0x1E00, 0x1200, 0x1400},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000000,
      range : {-0x2000, -0x1E00, 0x1200, 0x1400},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 4,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {-0x1900, -0x0800, 0x1F00, 0x1800},
    },
    [5] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x1900, -0x0800, 0x1F00, 0x1800},
    },
    [6] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 4,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {-0x1300, -0x0100, 0x1500, 0x0A00},
    },
    [7] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x1300, -0x0100, 0x1500, 0x0A00},
    },
    [8] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 4,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 5,
      unk_0c : 0x00000020,
      range : {0x1000, -0x2000, 0x2E00, 0x0C00},
    },
    [9] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 4,
      unk_0c : 0x00000000,
      range : {0x1000, -0x2000, 0x2E00, 0x0C00},
    },
    [10] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 4,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000020,
      range : {0x2400, -0x1000, 0x1200, 0x1500},
    },
    [11] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000000,
      range : {0x2400, -0x1000, 0x1200, 0x1500},
    },
    [12] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 4,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {0x1700, 0x0000, 0x2400, 0x0C00},
    },
    [13] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x1700, 0x0000, 0x2400, 0x0C00},
    },
    [14] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 4,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {0x0F00, 0x0000, 0x1300, 0x0900},
    },
    [15] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0F00, 0x0000, 0x1300, 0x0900},
    },
    [16] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 4,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000020,
      range : {-0x1C00, -0x0E00, 0x1E00, 0x1A00},
    },
    [17] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000000,
      range : {-0x1C00, -0x0E00, 0x1E00, 0x1A00},
    },
    [18] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 4,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {-0x2E00, -0x0D00, 0x0A00, 0x1100},
    },
    [19] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x2E00, -0x0D00, 0x0A00, 0x1100},
    },
    [20] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 4,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000020,
      range : {-0x2E00, -0x0D00, 0x0A00, 0x1100},
    },
    [21] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000000,
      range : {-0x2E00, -0x0D00, 0x0A00, 0x1100},
    },
    [22] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 4,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {-0x1C00, -0x0500, 0x1E00, 0x0900},
    },
    [23] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x1C00, -0x0500, 0x1E00, 0x0900},
    },
    [24] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 10,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x02,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000040,
      range : {0x1200, -0x1800, 0x0800, 0x0800},
    },
    [25] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x1200, -0x1800, 0x0800, 0x0800},
    },
    [26] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 10,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x02,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 5,
      unk_0c : 0x00000040,
      range : {-0x0900, -0x1900, 0x3200, 0x1800},
    },
    [27] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 4,
      unk_0c : 0x00000000,
      range : {-0x0900, -0x1900, 0x3200, 0x1800},
    },
    [28] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 10,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x02,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000040,
      range : {-0x1E00, -0x0E00, 0x1600, 0x2400},
    },
    [29] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000000,
      range : {-0x1E00, -0x0E00, 0x1600, 0x2400},
    },
    [30] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 10,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x02,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000040,
      range : {-0x3700, -0x1E00, 0x1E00, 0x3C00},
    },
    [31] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x3700, -0x1E00, 0x1E00, 0x3C00},
    },
    [32] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 10,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x02,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000040,
      range : {0x0500, -0x0F00, 0x0800, 0x0800},
    },
    [33] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0500, -0x0F00, 0x0800, 0x0800},
    },
    [34] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 10,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x02,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 5,
      unk_0c : 0x00000040,
      range : {-0x0500, -0x2600, 0x1E00, 0x0E00},
    },
    [35] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 4,
      unk_0c : 0x00000000,
      range : {-0x0500, -0x2600, 0x1E00, 0x0E00},
    },
    [36] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 10,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x02,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000040,
      range : {-0x1E00, -0x1E00, 0x1600, 0x4600},
    },
    [37] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000000,
      range : {-0x1E00, -0x1E00, 0x1600, 0x4600},
    },
    [38] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 10,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x02,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000040,
      range : {-0x3100, -0x1B00, 0x1400, 0x2A00},
    },
    [39] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x3100, -0x1B00, 0x1400, 0x2A00},
    },
    [40] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 10,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x02,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000040,
      range : {0x1600, -0x2000, 0x2200, 0x4A00},
    },
    [41] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000000,
      range : {0x1600, -0x2000, 0x2200, 0x4A00},
    },
    [42] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 10,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x02,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000040,
      range : {0x3100, -0x1F00, 0x1400, 0x2C00},
    },
    [43] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x3100, -0x1F00, 0x1400, 0x2C00},
    },
    [44] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 10,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x02,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000040,
      range : {-0x1E00, -0x2000, 0x1E00, 0x4A00},
    },
    [45] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000000,
      range : {-0x1E00, -0x2000, 0x1E00, 0x4A00},
    },
    [46] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 10,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x02,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000040,
      range : {-0x3600, -0x1D00, 0x1400, 0x2C00},
    },
    [47] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x3600, -0x1D00, 0x1400, 0x2C00},
    },
    [48] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x03,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {0x0F00, -0x0C00, 0x0E00, 0x0800},
    },
    [49] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0F00, -0x0C00, 0x0E00, 0x0800},
    },
    [50] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x03,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000020,
      range : {-0x0F00, -0x0D00, 0x3A00, 0x2400},
    },
    [51] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000000,
      range : {-0x0F00, -0x0D00, 0x3A00, 0x2400},
    },
    [52] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x03,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {-0x1A00, -0x3000, 0x2100, 0x2200},
    },
    [53] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x1A00, -0x3000, 0x2100, 0x2200},
    },
    [54] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x03,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {-0x1000, -0x3200, 0x0D00, 0x1C00},
    },
    [55] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x1000, -0x3200, 0x0D00, 0x1C00},
    },
    [56] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x03,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000020,
      range : {-0x1300, -0x1200, 0x2C00, 0x1F00},
    },
    [57] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000000,
      range : {-0x1300, -0x1200, 0x2C00, 0x1F00},
    },
    [58] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x03,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {0x0F00, -0x0C00, 0x1A00, 0x0F00},
    },
    [59] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0F00, -0x0C00, 0x1A00, 0x0F00},
    },
    [60] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x12,
      comboLv : 0x04,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000040,
      range : {-0x1B00, -0x0600, 0x1C00, 0x1000},
    },
    [61] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000000,
      range : {-0x1B00, -0x0600, 0x1C00, 0x1000},
    },
    [62] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x12,
      comboLv : 0x04,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000040,
      range : {0x0100, -0x0E00, 0x1C00, 0x0D00},
    },
    [63] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0100, -0x0E00, 0x1C00, 0x0D00},
    },
    [64] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x12,
      comboLv : 0x04,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000040,
      range : {-0x1800, -0x1000, 0x1D00, 0x3900},
    },
    [65] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000000,
      range : {-0x1800, -0x1000, 0x1D00, 0x3900},
    },
    [66] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x12,
      comboLv : 0x04,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000040,
      range : {-0x1100, -0x2900, 0x2000, 0x1500},
    },
    [67] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x1100, -0x2900, 0x2000, 0x1500},
    },
    [68] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x12,
      comboLv : 0x04,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000040,
      range : {-0x0D00, -0x2B00, 0x1A00, 0x1100},
    },
    [69] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x0D00, -0x2B00, 0x1A00, 0x1100},
    },
    [70] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x04,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {-0x2500, -0x0A00, 0x1D00, 0x0D00},
    },
    [71] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x2500, -0x0A00, 0x1D00, 0x0D00},
    },
    [72] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x01,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {-0x2E00, -0x0A00, 0x2300, 0x0800},
    },
    [73] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x2E00, -0x0A00, 0x2300, 0x0800},
    },
    [74] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {0x0300, -0x1A00, 0x2400, 0x2C00},
    },
    [75] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0300, -0x1A00, 0x2400, 0x2C00},
    },
    [76] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {-0x0500, -0x2600, 0x2A00, 0x1D00},
    },
    [77] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x0500, -0x2600, 0x2A00, 0x1D00},
    },
    [78] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {-0x1A00, -0x1F00, 0x1F00, 0x2800},
    },
    [79] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x1A00, -0x1F00, 0x1F00, 0x2800},
    },
    [80] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {-0x1C00, -0x0D00, 0x1E00, 0x2C00},
    },
    [81] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x1C00, -0x0D00, 0x1E00, 0x2C00},
    },
    [82] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {-0x1400, 0x0A00, 0x2800, 0x1F00},
    },
    [83] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x1400, 0x0A00, 0x2800, 0x1F00},
    },
    [84] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {0x0000, 0x0C00, 0x2A00, 0x1D00},
    },
    [85] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0C00, 0x2A00, 0x1D00},
    },
    [86] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {0x1300, 0x0300, 0x1F00, 0x2800},
    },
    [87] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x1300, 0x0300, 0x1F00, 0x2800},
    },
    [88] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {0x1600, -0x0E00, 0x1E00, 0x2C00},
    },
    [89] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x1600, -0x0E00, 0x1E00, 0x2C00},
    },
    [90] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {0x0D00, -0x2300, 0x2800, 0x1F00},
    },
    [91] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0D00, -0x2300, 0x2800, 0x1F00},
    },
    [92] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {-0x1900, -0x1300, 0x2000, 0x3200},
    },
    [93] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x1900, -0x1300, 0x2000, 0x3200},
    },
    [94] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {-0x1700, -0x0700, 0x1C00, 0x1800},
    },
    [95] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x1700, -0x0700, 0x1C00, 0x1800},
    },
    [96] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x05,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {0x0400, -0x2800, 0x0800, 0x0800},
    },
    [97] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0400, -0x2800, 0x0800, 0x0800},
    },
    [98] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x05,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000020,
      range : {-0x0E00, -0x1E00, 0x1400, 0x1600},
    },
    [99] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000000,
      range : {-0x0E00, -0x1E00, 0x1400, 0x1600},
    },
    [100] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x05,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000020,
      range : {-0x1000, -0x0100, 0x1D00, 0x2400},
    },
    [101] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x1000, -0x0100, 0x1D00, 0x2400},
    },
    [102] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x12,
      comboLv : 0x05,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000040,
      range : {0x0400, -0x2800, 0x0800, 0x0800},
    },
    [103] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0400, -0x2800, 0x0800, 0x0800},
    },
    [104] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x12,
      comboLv : 0x05,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000040,
      range : {-0x0E00, -0x1E00, 0x1400, 0x1600},
    },
    [105] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000000,
      range : {-0x0E00, -0x1E00, 0x1400, 0x1600},
    },
    [106] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x12,
      comboLv : 0x05,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000040,
      range : {-0x1000, -0x0100, 0x1500, 0x2800},
    },
    [107] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x1000, -0x0100, 0x1500, 0x2800},
    },
};

const struct Collision gSaberGeneralCollisions[2] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x10,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000020,
      range : {0x0000, 0x0000, 0x0000, 0x0000},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0x01,
      element : 0x00,
      nature : 0x12,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000040,
      range : {0x0000, 0x0000, 0x0000, 0x0000},
    },
};

// clang-format off
const struct Collision* const gTripleSlash1Hitboxes[8] = {
    gTripleSlash1Hitboxes_0835f0ec[0],
    gTripleSlash1Hitboxes_0835f0ec[0],
    gTripleSlash1Hitboxes_0835f0ec[1],
    gTripleSlash1Hitboxes_0835f0ec[2],
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
};
// clang-format on

// clang-format off
const struct Collision* const gTripleSlash2Hitboxes[7] = {
    gTripleSlash2Hitboxes_0835f17c[0],
    gTripleSlash2Hitboxes_0835f17c[0],
    gTripleSlash2Hitboxes_0835f17c[2],
    gTripleSlash2Hitboxes_0835f17c[3],
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
};
// clang-format on

// clang-format off
const struct Collision* const gTripleSlash3Hitboxes[11] = {
    gTripleSlash3Hitboxes_0835f23c[0],
    gTripleSlash3Hitboxes_0835f23c[1],
    gTripleSlash3Hitboxes_0835f23c[1],
    gTripleSlash3Hitboxes_0835f23c[1],
    gTripleSlash3Hitboxes_0835f23c[2],
    gTripleSlash3Hitboxes_0835f23c[2],
    gTripleSlash3Hitboxes_0835f23c[4],
    gTripleSlash3Hitboxes_0835f23c[6],
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
};
// clang-format on

// clang-format off
const struct Collision* const gTripleSlash4Hitboxes[7] = {
    gTripleSlash4Hitboxes_0835f38c[0],
    gTripleSlash4Hitboxes_0835f38c[0],
    gTripleSlash4Hitboxes_0835f38c[2],
    gTripleSlash4Hitboxes_0835f38c[3],
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
};
// clang-format on

// clang-format off
const struct Collision* const gSaberDashHitboxes[7] = {
    gSaberDashHitboxes_0835f47c[0],
    gSaberDashHitboxes_0835f47c[0],
    gSaberDashHitboxes_0835f47c[1],
    gSaberDashHitboxes_0835f47c[2],
    gSaberDashHitboxes_0835f47c[3],
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
};
// clang-format on

// clang-format off
static const struct Collision* const sChargeSaberHitboxes[7] = {
    &Collision_ARRAY_0835f53c[0],
    &Collision_ARRAY_0835f53c[0],
    &Collision_ARRAY_0835f53c[2],
    &Collision_ARRAY_0835f53c[4],
    &Collision_ARRAY_0835f53c[6],
    &Collision_ARRAY_0835f53c[6],
    &Collision_ARRAY_0835f53c[6],
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_08360048[6] = {
    &Collision_ARRAY_0835f53c[8],
    &Collision_ARRAY_0835f53c[8],
    &Collision_ARRAY_0835f53c[10],
    &Collision_ARRAY_0835f53c[12],
    &Collision_ARRAY_0835f53c[14],
    gSaberGeneralCollisions,
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_08360060[6] = {
    &Collision_ARRAY_0835f53c[16],
    &Collision_ARRAY_0835f53c[16],
    &Collision_ARRAY_0835f53c[20],
    &Collision_ARRAY_0835f53c[22],
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_08360078[9] = {
    &Collision_ARRAY_0835f53c[24],
    &Collision_ARRAY_0835f53c[24],
    &Collision_ARRAY_0835f53c[26],
    &Collision_ARRAY_0835f53c[28],
    &Collision_ARRAY_0835f53c[28],
    &Collision_ARRAY_0835f53c[28],
    &Collision_ARRAY_0835f53c[28],
    &Collision_ARRAY_0835f53c[28],
    gSaberGeneralCollisions,
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_0836009c[8] = {
    &Collision_ARRAY_0835f53c[32],
    &Collision_ARRAY_0835f53c[32],
    &Collision_ARRAY_0835f53c[34],
    &Collision_ARRAY_0835f53c[36],
    &Collision_ARRAY_0835f53c[36],
    &Collision_ARRAY_0835f53c[36],
    &Collision_ARRAY_0835f53c[36],
    &Collision_ARRAY_0835f53c[36],
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_083600bc[9] = {
    &gSaberGeneralCollisions[1],
    &gSaberGeneralCollisions[1],
    &Collision_ARRAY_0835f53c[40],
    &Collision_ARRAY_0835f53c[40],
    &Collision_ARRAY_0835f53c[40],
    &Collision_ARRAY_0835f53c[40],
    &Collision_ARRAY_0835f53c[40],
    &Collision_ARRAY_0835f53c[40],
    &gSaberGeneralCollisions[1],
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_083600e0[9] = {
    &gSaberGeneralCollisions[1],
    &gSaberGeneralCollisions[1],
    &Collision_ARRAY_0835f53c[44],
    &Collision_ARRAY_0835f53c[44],
    &Collision_ARRAY_0835f53c[44],
    &Collision_ARRAY_0835f53c[44],
    &Collision_ARRAY_0835f53c[44],
    &Collision_ARRAY_0835f53c[44],
    &gSaberGeneralCollisions[1],
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_08360104[8] = {
    &Collision_ARRAY_0835f53c[48],
    &Collision_ARRAY_0835f53c[50],
    &Collision_ARRAY_0835f53c[50],
    &Collision_ARRAY_0835f53c[52],
    &Collision_ARRAY_0835f53c[54],
    &Collision_ARRAY_0835f53c[54],
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_08360124[8] = {
    gSaberGeneralCollisions,
    &Collision_ARRAY_0835f53c[56],
    &Collision_ARRAY_0835f53c[56],
    &Collision_ARRAY_0835f53c[58],
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
};
// clang-format on

const struct Collision *const PTR_ARRAY_08360144[2] = {
    &Collision_ARRAY_0835f53c[62],
    &Collision_ARRAY_0835f53c[60],
};

// clang-format off
const struct Collision* const PTR_ARRAY_0836014c[7] = {
    &Collision_ARRAY_0835f53c[64],
    &Collision_ARRAY_0835f53c[64],
    &Collision_ARRAY_0835f53c[66],
    &Collision_ARRAY_0835f53c[68],
    &Collision_ARRAY_0835f53c[68],
    &Collision_ARRAY_0835f53c[68],
    &Collision_ARRAY_0835f53c[68],
};
// clang-format on

const struct Collision *const PTR_ARRAY_08360168[1] = {
    &Collision_ARRAY_0835f53c[70],
};

const struct Collision *const PTR_ARRAY_0836016c[1] = {
    &Collision_ARRAY_0835f53c[72],
};

// clang-format off
const struct Collision* const PTR_ARRAY_08360170[12] = {
    &Collision_ARRAY_0835f53c[74],
    &Collision_ARRAY_0835f53c[76],
    &Collision_ARRAY_0835f53c[78],
    &Collision_ARRAY_0835f53c[80],
    &Collision_ARRAY_0835f53c[82],
    &Collision_ARRAY_0835f53c[84],
    &Collision_ARRAY_0835f53c[86],
    &Collision_ARRAY_0835f53c[88],
    &Collision_ARRAY_0835f53c[90],
    &Collision_ARRAY_0835f53c[76],
    &Collision_ARRAY_0835f53c[92],
    &Collision_ARRAY_0835f53c[94],
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_083601a0[8] = {
    &Collision_ARRAY_0835f53c[80],
    &Collision_ARRAY_0835f53c[82],
    &Collision_ARRAY_0835f53c[84],
    &Collision_ARRAY_0835f53c[86],
    &Collision_ARRAY_0835f53c[88],
    &Collision_ARRAY_0835f53c[90],
    &Collision_ARRAY_0835f53c[76],
    &Collision_ARRAY_0835f53c[78],
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_083601c0[8] = {
    &Collision_ARRAY_0835f53c[96],
    &Collision_ARRAY_0835f53c[98],
    &Collision_ARRAY_0835f53c[98],
    &Collision_ARRAY_0835f53c[100],
    &Collision_ARRAY_0835f53c[100],
    &Collision_ARRAY_0835f53c[100],
    &Collision_ARRAY_0835f53c[100],
    &Collision_ARRAY_0835f53c[100],
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_083601e0[8] = {
    &Collision_ARRAY_0835f53c[102],
    &Collision_ARRAY_0835f53c[104],
    &Collision_ARRAY_0835f53c[104],
    &Collision_ARRAY_0835f53c[106],
    &Collision_ARRAY_0835f53c[106],
    &Collision_ARRAY_0835f53c[106],
    &Collision_ARRAY_0835f53c[106],
    &Collision_ARRAY_0835f53c[106],
};
// clang-format on

// clang-format off
const struct Collision* const PTR_ARRAY_08360200[18] = {
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
};
// clang-format on

// clang-format off
const struct Collision *const *const gSaberCollisions[25] = {
    gTripleSlash1Hitboxes,
    gTripleSlash2Hitboxes,
    gTripleSlash3Hitboxes,
    gTripleSlash4Hitboxes,
    gSaberDashHitboxes,
    sChargeSaberHitboxes,
    PTR_ARRAY_08360048,
    PTR_ARRAY_08360060,
    PTR_ARRAY_08360078,
    PTR_ARRAY_0836009c,
    PTR_ARRAY_083600bc,
    PTR_ARRAY_083600e0,
    PTR_ARRAY_08360104,
    PTR_ARRAY_08360124,
    PTR_ARRAY_08360144,
    PTR_ARRAY_08360144,
    PTR_ARRAY_0836014c,
    PTR_ARRAY_0836014c,
    PTR_ARRAY_08360168,
    PTR_ARRAY_0836016c,
    PTR_ARRAY_08360170,
    PTR_ARRAY_083601a0,
    PTR_ARRAY_083601c0,
    PTR_ARRAY_083601e0,
    PTR_ARRAY_08360200,
};
// clang-format on

static const bool8 gIlethasables[25] = {
    1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0,
};

// clang-format off
const WeaponRoutine gSaberRoutine = {
    [ENTITY_INIT] =      Saber_Init,
    [ENTITY_MAIN] =      Saber_Update,
    [ENTITY_DIE] =       Saber_Die,
    [ENTITY_DISAPPEAR] = DeleteWeapon,
    [ENTITY_EXIT] =      (WeaponFunc)DeleteEntity,    
};
// clang-format on
