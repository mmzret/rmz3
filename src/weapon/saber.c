#include "collision.h"
#include "global.h"
#include "mission.h"
#include "motion.h"
#include "overworld.h"
#include "sound.h"
#include "vfx.h"
#include "weapon.h"
#include "zero.h"

#define PROP (w->props.saber)

static const bool8 gIlethasables[25];
static const WeaponFunc sSaberActions[SABER_ACTION_COUNT];
static const motion_t sSaberMotions[SABER_ACTION_COUNT];
static const SoundID sSaberSEs[SABER_ACTION_COUNT];
static const u8 sSaberDamages[SABER_ACTION_COUNT];
static const struct Collision *const sSaberAirHitbox[7];

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
    (&PROP)->z = z;
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
  struct Body *body;
  struct Saber_b4 *b4 = &PROP;
  struct Zero *z = b4->z;

  SET_WEAPON_ROUTINE(w, ENTITY_UPDATE);
  InitNonAffineMotion(&w->s);
  ResetDynamicMotion(&w->s);
  (w->s).flags |= DISPLAY;
  (w->s).flags |= FLIPABLE;
  SetMotion(&w->s, sSaberMotions[(w->s).work[0]]);
  collisions = *gSaberCollisions[(w->s).work[0]];
  INIT_BODY(w, collisions, 1, NULL);

  if (sSaberSEs[(w->s).work[0]] != MUS_DUMMY) {
    if ((w->s).work[0] == SABER_ZANEIDAN) {
      if (z->tripleSlashCounter > 0) {
        PlaySound(SE_SLASH_UP);  // Saber wave by Cottus
      } else {
        PlaySound(sSaberSEs[(w->s).work[0]]);  // Saber blade (EXSkill)
      }
    } else {
      PlaySound(sSaberSEs[(w->s).work[0]]);
    }
  }

  if ((w->s).work[0] == SABER_ZANEIDAN) {
    if (z->tripleSlashCounter == 0) {
      if (((&z->unk_b4)->status).element == ELEMENT_ICE) {
        CreateThrowBlade(z, w, TRUE);
      } else {
        CreateThrowBlade(z, w, FALSE);
      }
    } else {
      CreateSaberWave(z, w, FALSE);
    }
  }

  if (((((w->s).work[0] == SABER_TENRETUJIN) || ((w->s).work[0] == SABER_TENRETUJIN_2)) || ((w->s).work[0] == SABER_SMASH)) || !(collisions[0].nature & ELEMENT_ENCHANTABLE)) {
    b4->element = 0;
  } else {
    b4->element = gSaberElements[(w->s).work[1]];
  }
  b4->atk = sSaberDamages[(w->s).work[0]] + CalcSaberBonus(z);
  if (isElfUsed_2(z, ELF_ILETHAS) && gIlethasables[(w->s).work[0]]) {
    b4->nature = collisions[0].nature | BODY_NATURE_ILETHAS;
  } else {
    b4->nature = collisions[0].nature;
  }
  if ((w->s).work[0] == SABER_SMASH_ELEC) {
    b4->element = gSaberElements[(w->s).work[1]];
    b4->nature |= ELEMENT_ENCHANTABLE;
  }
  body = &w->body;
  InitWeaponBody(body, collisions, b4->atk, b4->element, b4->nature, -1);
  (w->s).work[2] = 0;
  b4->unk = TRUE;
  body->fn = onHit;
  Saber_Update(w);
#else
  INCCODE("asm/wip/Saber_Init.inc");
#endif
}

WIP static void Saber_Update(struct Weapon *w) {
#if MODERN
  bool8 xflip;
  struct Saber_b4 *b4 = &PROP;
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
    InitWeaponBody(body, collisions, (&PROP)->atk, (&PROP)->element, (&PROP)->nature, -1);
  }

  if ((w->s).motion.state == MOTION_END) {
    SET_WEAPON_ROUTINE(w, ENTITY_DIE)
  }
}

WIP static void saberAirSlash(struct Weapon *w) {
#if MODERN
  struct Saber_b4 *b4 = &PROP;
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
  struct Saber_b4 *b4 = &PROP;
  struct Zero *z = b4->z;
  if ((w->s).mode[2] == 0) {
    if (z->chargeSaber != 0) {
      motion_t m = sSaberMotions[z->chargeSaber + 7];
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
      InitWeaponBody(&w->body, sSaberAirHitbox[(w->s).motion.cmdIdx], b4->atk, b4->element, b4->nature, -1);
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
  const struct Weapon_b4 *b4 = &(w->props.common);
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
  const struct Weapon_b4 *b4 = &(w->props.common);
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
  struct Saber_b4 *b4 = &PROP;
  struct Zero *z = b4->z;

  if ((w->s).mode[2] == 0) {
    const u8 idx = (w->s).motion.cmdIdx;
    const motion_t m = MOTION_VALUE(z);
    if ((m == MOTION(DM026_ZERO_SABER_AIR_ROLLING, 0x00)) || ((z->s).motion.cmdIdx == idx)) {
      UpdateMotionGraphic(&w->s);
      {
        struct Body *body = &w->body;
        const struct Collision *collisions = gSaberCollisions[(w->s).work[0]][idx];
        const struct Saber_b4 *b4 = &PROP;
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
  struct Zero *z = (&PROP)->z;
  UpdateMotionGraphic(&w->s);

  m = MOTION_VALUE(z);
  if ((m != MOTION(DM026_ZERO_SABER_AIR_ROLLING, 1)) || (((z->s).motion.cmdIdx != (w->s).motion.cmdIdx))) {
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
    InitWeaponBody(body, collisions, (&PROP)->atk, (&PROP)->element, (&PROP)->nature, ((w->s).motion.cmdIdx >> 1) + 1);
  }
}

WIP static void saberSmash(struct Weapon *w) {
#if MODERN
  const struct Saber_b4 *b4 = &PROP;
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
    [SABER_WALK] =               saberTripleSlash,
    [SABER_DASH] =               saberTripleSlash,
    [SABER_AIR] =                saberAirSlash,
    [SABER_WALL] =               saberTripleSlash,
    [SABER_LADDER] =             saberTripleSlash,
    [SABER_CHARGE] =             saberChargeAtk,
    [SABER_CHARGE_AIR] =         saberChargeAtk,
    [SABER_CHARGE_WALL] =        saberChargeAtk,
    [SABER_CHARGE_LADDER] =      saberChargeAtk,
    [SABER_SLASH_UP] =           saberTripleSlash,
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
// clang-format on

// clang-format off
static const motion_t sSaberMotions[SABER_ACTION_COUNT] = {
    [SABER_TRIPLE_1] = MOTION(DM088_TRIPLE_SLASH_1, 0),
    [SABER_TRIPLE_2] = MOTION(DM089_TRIPLE_SLASH_2, 0),
    [SABER_TRIPLE_3] = MOTION(DM090_TRIPLE_SLASH_3, 0),
    [SABER_WALK] = MOTION(DM095_SABER_WALK, 0),
    [SABER_DASH] = MOTION(DM096_SABER_DASH, 0),
    [SABER_AIR] = MOTION(DM098_SABER_CHARGE, 0),
    [SABER_WALL] =  MOTION(DM101_SABER_CHARGE_AIR, 0),
    [SABER_LADDER] = MOTION(DM102_SABER, 0),
    [SABER_CHARGE] = MOTION(DM094_SABER_CHARGE, 0),
    [SABER_CHARGE_AIR] = MOTION(DM098_SABER_CHARGE, 2),
    [SABER_CHARGE_WALL] = MOTION(DM101_SABER_CHARGE_AIR, 1),
    [SABER_CHARGE_LADDER] = MOTION(DM102_SABER, 1),
    [SABER_SLASH_UP] = MOTION(DM091_SLUSH_UP, 0),
    [SABER_ZANEIDAN] = MOTION(DM093_ZANEIDAN, 0),
    [SABER_TENRETUJIN] = MOTION(DM092_TENRETSUJIN, 0),
    [SABER_TENRETUJIN_FIRE] = MOTION(DM092_TENRETSUJIN, 3),
    [SABER_TENRETUJIN_2] = MOTION(DM092_TENRETSUJIN, 1),
    [SABER_TENRETUJIN_FIRE_2] = MOTION(DM092_TENRETSUJIN, 4),
    [SABER_REPUGEKI] = MOTION(DM097_GALE_ATTACK, 0),
    [SABER_UNK_19] =  MOTION(DM097_GALE_ATTACK, 2),
    [SABER_AIR_ROLLING] = MOTION(DM099_SABER, 0),
    [SABER_DASH_ROLLING] = MOTION(DM099_SABER, 1),
    [SABER_SMASH] = MOTION(DM100_RAKUSAIGA, 0),
    [SABER_SMASH_ELEC] = MOTION(DM100_RAKUSAIGA, 2),
};
// clang-format on

// clang-format off
static const SoundID sSaberSEs[SABER_ACTION_COUNT] = {
    [SABER_TRIPLE_1] =           SE_SABER,
    [SABER_TRIPLE_2] =           SE_SABER,
    [SABER_TRIPLE_3] =           SE_SABER,
    [SABER_WALK] =               SE_SABER,
    [SABER_DASH] =               SE_SABER,
    [SABER_AIR] =                SE_SABER,
    [SABER_WALL] =               SE_SABER,
    [SABER_LADDER] =             SE_SABER,
    [SABER_CHARGE] =             SE_CHARGE_SAVER_VOICE,
    [SABER_CHARGE_AIR] =         SE_CHARGE_SAVER_VOICE,
    [SABER_CHARGE_WALL] =        SE_CHARGE_SAVER_VOICE,
    [SABER_CHARGE_LADDER] =      SE_CHARGE_SAVER_VOICE,
    [SABER_SLASH_UP] =           SE_SLASH_UP,
    [SABER_ZANEIDAN] =           SE_TENRETSUJIN,
    [SABER_TENRETUJIN] =         MUS_DUMMY,
    [SABER_TENRETUJIN_FIRE] =    MUS_DUMMY,
    [SABER_TENRETUJIN_2] =       SE_TENRETSUJIN,
    [SABER_TENRETUJIN_FIRE_2] =  SE_TENRETSUJIN,
    [SABER_REPUGEKI] =           SE_REPPUGEKI,
    [SABER_UNK_19] =             SE_REPPUGEKI,
    [SABER_AIR_ROLLING] =        SE_SLASH_ROLLING,
    [SABER_DASH_ROLLING] =       SE_SLASH_ROLLING,
    [SABER_SMASH] =              SE_REPPUGEKI,
    [SABER_SMASH_ELEC] =         SE_REPPUGEKI,
};
// clang-format on

// clang-format off
static const u8 sSaberDamages[SABER_ACTION_COUNT] = {
    [SABER_TRIPLE_1] =           8,
    [SABER_TRIPLE_2] =           8,
    [SABER_TRIPLE_3] =           8,
    [SABER_WALK] =               6,
    [SABER_DASH] =               10,
    [SABER_AIR] =                8,
    [SABER_WALL] =               8,
    [SABER_LADDER] =             8,
    [SABER_CHARGE] =             16,
    [SABER_CHARGE_AIR] =         16,
    [SABER_CHARGE_WALL] =        16,
    [SABER_CHARGE_LADDER] =      16,
    [SABER_SLASH_UP] =           10,
    [SABER_ZANEIDAN] =           10,
    [SABER_TENRETUJIN] =         14,
    [SABER_TENRETUJIN_FIRE] =    14,
    [SABER_TENRETUJIN_2] =       14,
    [SABER_TENRETUJIN_FIRE_2] =  14,
    [SABER_REPUGEKI] =           12,
    [SABER_UNK_19] =             12,
    [SABER_AIR_ROLLING] =        4,
    [SABER_DASH_ROLLING] =       6,
    [SABER_SMASH] =              16,
    [SABER_SMASH_ELEC] =         16,
};
// clang-format on

const u8 gSaberElements[4] = {0, 1, 2, 3};

static const struct Collision sTripleSlash1Collisions[3][2] = {
    // 0
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 4,
          atkType : ATK_SABER,
          nature : BODY_NATURE_CUT,
          comboLv : 1,
          remaining : 3,
          layer : 0x20,
          range : {0xE000, 0xEE00, 0x2600, 0x1A00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 2,
          range : {0xE000, 0xEE00, 0x2600, 0x1A00},
        },
    },

    // 1
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 4,
          atkType : ATK_SABER,
          nature : BODY_NATURE_CUT,
          comboLv : 1,
          remaining : 1,
          layer : 0x20,
          range : {0xF800, 0xDE00, 0x3A00, 0x800},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 0,
          range : {0xF800, 0xDE00, 0x3A00, 0x800},
        },
    },

    // 2
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 4,
          atkType : ATK_SABER,
          nature : BODY_NATURE_CUT,
          comboLv : 1,
          remaining : 1,
          layer : 0x20,
          range : {0xD00, 0xDF00, 0x1000, 0xA00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 0,
          range : {0xD00, 0xDF00, 0x1000, 0xA00},
        },
    }};

static const struct Collision sTripleSlash2Collisions[4][2] = {
    // 0
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 6,
          atkType : ATK_SABER,
          element : 0,
          nature : BODY_NATURE_CUT,
          comboLv : 2,
          hitzone : 0,
          remaining : 5,
          layer : 0x20,
          range : {0xF100, 0xDE00, 0x3800, 0xE00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 4,
          range : {0xF100, 0xDE00, 0x3800, 0xE00},
        },
    },

    // 1
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 6,
          atkType : ATK_SABER,
          nature : BODY_NATURE_CUT,
          comboLv : 2,
          remaining : 3,
          layer : 0x20,
          range : {0xD900, 0xEE00, 0x1A00, 0x1600},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 2,
          range : {0xD900, 0xEE00, 0x1A00, 0x1600},
        },
    },

    // 2
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 6,
          atkType : ATK_SABER,
          nature : BODY_NATURE_CUT,
          comboLv : 2,
          remaining : 1,
          layer : 0x20,
          range : {0xEA00, 0x0, 0x2F00, 0xE00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 0,
          range : {0xEA00, 0x0, 0x2F00, 0xE00},
        },
    },

    // 3
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 6,
          atkType : ATK_SABER,
          nature : BODY_NATURE_CUT,
          comboLv : 2,
          remaining : 1,
          layer : 0x20,
          range : {0xF200, 0x100, 0x1E00, 0xE00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 0,
          range : {0xF200, 0x100, 0x1E00, 0xE00},
        },
    },
};

static const struct Collision sTripleSlash3Collisions[7][2] = {
    // 0
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 8,
          atkType : ATK_SABER,
          nature : BODY_NATURE_CUT,
          comboLv : 3,
          remaining : 1,
          layer : 0x20,
          range : {0x600, 0xFE00, 0x800, 0x1000},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 0,
          range : {0x600, 0xFE00, 0x800, 0x1000},
        },
    },

    // 1
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 8,
          atkType : ATK_SABER,
          nature : BODY_NATURE_CUT,
          comboLv : 3,
          remaining : 1,
          layer : 0x20,
          range : {0x1300, 0xEF00, 0x900, 0x1200},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 0,
          range : {0x1300, 0xEF00, 0x900, 0x1200},
        },
    },

    // 2
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 8,
          atkType : ATK_SABER,
          nature : BODY_NATURE_CUT,
          comboLv : 3,
          remaining : 9,
          layer : 0x20,
          range : {0x1400, 0xE400, 0xE00, 0x2400},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 8,
          range : {0x1400, 0xE400, 0xE00, 0x2400},
        },
    },

    // 3
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 8,
          atkType : ATK_SABER,
          nature : BODY_NATURE_CUT,
          comboLv : 3,
          remaining : 7,
          layer : 0x20,
          range : {0x0, 0xCF00, 0x2200, 0xC00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 6,
          range : {0x0, 0xCF00, 0x2200, 0xC00},
        },
    },

    // 4
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 8,
          atkType : ATK_SABER,
          nature : BODY_NATURE_CUT,
          comboLv : 3,
          remaining : 5,
          layer : 0x20,
          range : {0xE200, 0xCF00, 0x1C00, 0xC00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 4,
          range : {0xE200, 0xCF00, 0x1C00, 0xC00},
        },
    },

    // 5
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 8,
          atkType : ATK_SABER,
          nature : BODY_NATURE_CUT,
          comboLv : 3,
          remaining : 3,
          layer : 0x20,
          range : {0xD600, 0xE700, 0x1700, 0x2200},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 2,
          range : {0xD600, 0xE700, 0x1700, 0x2200},
        },
    },

    // 6
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 8,
          atkType : ATK_SABER,
          nature : BODY_NATURE_CUT,
          comboLv : 3,
          remaining : 1,
          layer : 0x20,
          range : {0xDF00, 0xFD00, 0x1D00, 0xA00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 0,
          range : {0xDF00, 0xFD00, 0x1D00, 0xA00},
        },
    },
};

static const struct Collision sSaberWalkCollisions[5][2] = {
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 4,
          atkType : ATK_SABER,
          nature : BODY_NATURE_CUT,
          comboLv : 1,
          remaining : 3,
          layer : 0x00000020,
          range : {-0x2100, -0x1500, 0x1200, 0x1500},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 2,
          range : {-0x2100, -0x1500, 0x1200, 0x1500},
        },
    },
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 4,
          atkType : ATK_SABER,
          nature : BODY_NATURE_CUT,
          comboLv : 1,
          remaining : 1,
          layer : 0x00000020,
          range : {0x0500, -0x2100, 0x3900, 0x0B00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 0,
          range : {0x0500, -0x2100, 0x3900, 0x0B00},
        },
    },
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 4,
          atkType : ATK_SABER,
          nature : BODY_NATURE_CUT,
          comboLv : 1,
          remaining : 3,
          layer : 0x00000020,
          range : {-0x2100, -0x1500, 0x1200, 0x1500},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 2,
          range : {-0x2100, -0x1500, 0x1200, 0x1500},
        },
    },
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 4,
          atkType : ATK_SABER,
          nature : BODY_NATURE_CUT,
          comboLv : 1,
          remaining : 1,
          layer : 0x00000020,
          range : {0x0500, -0x2100, 0x3900, 0x0B00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 0,
          range : {0x0500, -0x2100, 0x3900, 0x0B00},
        },
    },
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 4,
          atkType : ATK_SABER,
          nature : BODY_NATURE_CUT,
          comboLv : 1,
          remaining : 1,
          layer : 0x00000020,
          range : {0x1600, -0x2100, 0x1600, 0x0B00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 0,
          range : {0x1600, -0x2100, 0x1600, 0x0B00},
        },
    },
};

static const struct Collision sSaberDashCollisions[4][2] = {
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 4,
          atkType : ATK_SABER,
          nature : BODY_NATURE_CUT,
          comboLv : 1,
          remaining : 5,
          layer : 0x00000020,
          range : {-0x1600, -0x1800, 0x3400, 0x1400},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 4,
          range : {-0x1600, -0x1800, 0x3400, 0x1400},
        },
    },
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 4,
          atkType : ATK_SABER,
          nature : BODY_NATURE_CUT,
          comboLv : 1,
          remaining : 3,
          layer : 0x00000020,
          range : {-0x2600, -0x0700, 0x1300, 0x1000},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 2,
          range : {-0x2600, -0x0700, 0x1300, 0x1000},
        },
    },
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 4,
          atkType : ATK_SABER,
          nature : BODY_NATURE_CUT,
          comboLv : 1,
          remaining : 1,
          layer : 0x00000020,
          range : {-0x0900, 0x0200, 0x2A00, 0x0A00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 0,
          range : {-0x0900, 0x0200, 0x2A00, 0x0A00},
        },
    },
    {
        {
          kind : DDP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 4,
          atkType : ATK_SABER,
          nature : BODY_NATURE_CUT,
          comboLv : 1,
          remaining : 1,
          layer : 0x00000020,
          range : {0x0700, 0x0200, 0x0C00, 0x0A00},
        },
        {
          kind : DRP,
          faction : FACTION_ALLY,
          special : HALFABLE,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 0,
          range : {0x0700, 0x0200, 0x0C00, 0x0A00},
        },
    },
};

static const struct Collision sSaberAirCollisions[8] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 4,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x10,
      comboLv : 1,
      remaining : 5,
      layer : 0x00000020,
      range : {-PIXEL(2), -PIXEL(34), PIXEL(42), PIXEL(22)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 4,
      range : {-PIXEL(2), -PIXEL(34), PIXEL(42), PIXEL(22)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 4,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x10,
      comboLv : 1,
      remaining : 3,
      layer : 0x00000020,
      range : {-PIXEL(32), -PIXEL(30), PIXEL(18), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 2,
      range : {-PIXEL(32), -PIXEL(30), PIXEL(18), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 4,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x10,
      comboLv : 1,
      remaining : 1,
      layer : 0x00000020,
      range : {-PIXEL(25), -PIXEL(8), PIXEL(31), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {-PIXEL(25), -PIXEL(8), PIXEL(31), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 4,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x10,
      comboLv : 1,
      remaining : 1,
      layer : 0x00000020,
      range : {-PIXEL(19), -PIXEL(1), PIXEL(21), PIXEL(10)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {-PIXEL(19), -PIXEL(1), PIXEL(21), PIXEL(10)},
    },
};

static const struct Collision sSaberWallCollisions[8] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 4,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x10,
      comboLv : 1,
      hitzone : 0,
      remaining : 5,
      layer : 0x00000020,
      range : {PIXEL(16), -PIXEL(32), PIXEL(46), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 4,
      range : {PIXEL(16), -PIXEL(32), PIXEL(46), PIXEL(12)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 4,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x10,
      comboLv : 1,
      hitzone : 0,
      remaining : 3,
      layer : 0x00000020,
      range : {PIXEL(36), -PIXEL(16), PIXEL(18), PIXEL(21)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 2,
      range : {PIXEL(36), -PIXEL(16), PIXEL(18), PIXEL(21)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 4,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x10,
      comboLv : 1,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000020,
      range : {PIXEL(23), PIXEL(0), PIXEL(36), PIXEL(12)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {PIXEL(23), PIXEL(0), PIXEL(36), PIXEL(12)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 4,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x10,
      comboLv : 1,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000020,
      range : {PIXEL(15), PIXEL(0), PIXEL(19), PIXEL(9)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {PIXEL(15), PIXEL(0), PIXEL(19), PIXEL(9)},
    },
};

static const struct Collision sSaberLadderCollisions[8] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 4,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x10,
      comboLv : 1,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000020,
      range : {-PIXEL(28), -PIXEL(14), PIXEL(30), PIXEL(26)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 1,
      range : {-PIXEL(28), -PIXEL(14), PIXEL(30), PIXEL(26)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 4,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x10,
      comboLv : 1,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000020,
      range : {-PIXEL(46), -PIXEL(13), PIXEL(10), PIXEL(17)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {-PIXEL(46), -PIXEL(13), PIXEL(10), PIXEL(17)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 4,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x10,
      comboLv : 1,
      hitzone : 0,
      remaining : 3,
      layer : 0x00000020,
      range : {-PIXEL(46), -PIXEL(13), PIXEL(10), PIXEL(17)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 2,
      range : {-PIXEL(46), -PIXEL(13), PIXEL(10), PIXEL(17)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 4,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x10,
      comboLv : 1,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000020,
      range : {-PIXEL(28), -PIXEL(5), PIXEL(30), PIXEL(9)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {-PIXEL(28), -PIXEL(5), PIXEL(30), PIXEL(9)},
    },
};

static const struct Collision sChargeGroundCollisions[8] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 10,
      atkType : ATK_SABER,
      element : 0x00,
      nature : ELEMENT_ENCHANTABLE,
      comboLv : 1,
      remaining : 1,
      layer : 0x00000040,
      range : {PIXEL(18), -PIXEL(24), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {PIXEL(18), -PIXEL(24), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 10,
      atkType : ATK_SABER,
      element : 0x00,
      nature : ELEMENT_ENCHANTABLE,
      comboLv : 1,
      remaining : 5,
      layer : 0x00000040,
      range : {-PIXEL(9), -PIXEL(25), PIXEL(50), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 4,
      range : {-PIXEL(9), -PIXEL(25), PIXEL(50), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 10,
      atkType : ATK_SABER,
      element : 0x00,
      nature : ELEMENT_ENCHANTABLE,
      comboLv : 1,
      remaining : 3,
      layer : 0x00000040,
      range : {-PIXEL(30), -PIXEL(14), PIXEL(22), PIXEL(36)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 2,
      range : {-PIXEL(30), -PIXEL(14), PIXEL(22), PIXEL(36)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 10,
      atkType : ATK_SABER,
      element : 0x00,
      nature : ELEMENT_ENCHANTABLE,
      comboLv : 1,
      remaining : 1,
      layer : 0x00000040,
      range : {-PIXEL(55), -PIXEL(30), PIXEL(30), PIXEL(60)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {-PIXEL(55), -PIXEL(30), PIXEL(30), PIXEL(60)},
    },
};

static const struct Collision sChargeAirCollisions[8] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 10,
      atkType : ATK_SABER,
      element : 0x00,
      nature : ELEMENT_ENCHANTABLE,
      comboLv : 1,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000040,
      range : {PIXEL(5), -PIXEL(15), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {PIXEL(5), -PIXEL(15), PIXEL(8), PIXEL(8)},
    },

    // --------------------------------------------

    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 10,
      atkType : ATK_SABER,
      element : 0x00,
      nature : ELEMENT_ENCHANTABLE,
      comboLv : 1,
      hitzone : 0,
      remaining : 5,
      layer : 0x00000040,
      range : {-PIXEL(5), -PIXEL(38), PIXEL(30), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 4,
      range : {-PIXEL(5), -PIXEL(38), PIXEL(30), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 10,
      atkType : ATK_SABER,
      element : 0x00,
      nature : ELEMENT_ENCHANTABLE,
      comboLv : 1,
      hitzone : 0,
      remaining : 3,
      layer : 0x00000040,
      range : {-PIXEL(30), -PIXEL(30), PIXEL(22), PIXEL(70)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 2,
      range : {-PIXEL(30), -PIXEL(30), PIXEL(22), PIXEL(70)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 10,
      atkType : ATK_SABER,
      element : 0x00,
      nature : ELEMENT_ENCHANTABLE,
      comboLv : 1,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000040,
      range : {-PIXEL(49), -PIXEL(27), PIXEL(20), PIXEL(42)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {-PIXEL(49), -PIXEL(27), PIXEL(20), PIXEL(42)},
    },
};

static const struct Collision sChargeWallCollisions[4] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 10,
      atkType : ATK_SABER,
      element : 0x00,
      nature : ELEMENT_ENCHANTABLE,
      comboLv : 1,
      hitzone : 0,
      remaining : 3,
      layer : 0x00000040,
      range : {PIXEL(22), -PIXEL(32), PIXEL(34), PIXEL(74)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 2,
      range : {PIXEL(22), -PIXEL(32), PIXEL(34), PIXEL(74)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 10,
      atkType : ATK_SABER,
      element : 0x00,
      nature : ELEMENT_ENCHANTABLE,
      comboLv : 1,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000040,
      range : {PIXEL(49), -PIXEL(31), PIXEL(20), PIXEL(44)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {PIXEL(49), -PIXEL(31), PIXEL(20), PIXEL(44)},
    },
};

static const struct Collision sChargeLadderCollisions[4] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 10,
      atkType : ATK_SABER,
      element : 0x00,
      nature : ELEMENT_ENCHANTABLE,
      comboLv : 1,
      hitzone : 0,
      remaining : 3,
      layer : 0x00000040,
      range : {-PIXEL(30), -PIXEL(32), PIXEL(30), PIXEL(74)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 2,
      range : {-PIXEL(30), -PIXEL(32), PIXEL(30), PIXEL(74)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 10,
      atkType : ATK_SABER,
      element : 0x00,
      nature : ELEMENT_ENCHANTABLE,
      comboLv : 1,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000040,
      range : {-PIXEL(54), -PIXEL(29), PIXEL(20), PIXEL(44)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {-PIXEL(54), -PIXEL(29), PIXEL(20), PIXEL(44)},
    },
};

static const struct Collision sSlashUpCollisions[8] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x10,
      comboLv : 3,
      remaining : 1,
      layer : 0x00000020,
      range : {PIXEL(15), -PIXEL(12), PIXEL(14), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {PIXEL(15), -PIXEL(12), PIXEL(14), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x10,
      comboLv : 3,
      remaining : 3,
      layer : 0x00000020,
      range : {-PIXEL(15), -PIXEL(13), PIXEL(58), PIXEL(36)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 2,
      range : {-PIXEL(15), -PIXEL(13), PIXEL(58), PIXEL(36)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x10,
      comboLv : 3,
      remaining : 1,
      layer : 0x00000020,
      range : {-PIXEL(26), -PIXEL(48), PIXEL(33), PIXEL(34)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {-PIXEL(26), -PIXEL(48), PIXEL(33), PIXEL(34)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x10,
      comboLv : 3,
      remaining : 1,
      layer : 0x00000020,
      range : {-PIXEL(16), -PIXEL(50), PIXEL(13), PIXEL(28)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {-PIXEL(16), -PIXEL(50), PIXEL(13), PIXEL(28)},
    },
};

static const struct Collision sThrowBladeCollisions[4] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x10,
      comboLv : 3,
      remaining : 3,
      layer : 0x00000020,
      range : {-PIXEL(19), -PIXEL(18), PIXEL(44), PIXEL(31)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 2,
      range : {-PIXEL(19), -PIXEL(18), PIXEL(44), PIXEL(31)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x10,
      comboLv : 3,
      remaining : 1,
      layer : 0x00000020,
      range : {PIXEL(15), -PIXEL(12), PIXEL(26), PIXEL(15)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {PIXEL(15), -PIXEL(12), PIXEL(26), PIXEL(15)},
    },
};

static const struct Collision sSplitHeavensCollisions[10] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      element : 0x00,
      nature : (BODY_NATURE_CUT | ELEMENT_ENCHANTABLE),
      comboLv : 4,
      hitzone : 0,
      remaining : 3,
      layer : 0x00000040,
      range : {-PIXEL(27), -PIXEL(6), PIXEL(28), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 2,
      range : {-PIXEL(27), -PIXEL(6), PIXEL(28), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x12,
      comboLv : 4,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000040,
      range : {PIXEL(1), -PIXEL(14), PIXEL(28), PIXEL(13)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {PIXEL(1), -PIXEL(14), PIXEL(28), PIXEL(13)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x12,
      comboLv : 4,
      hitzone : 0,
      remaining : 3,
      layer : 0x00000040,
      range : {-PIXEL(24), -PIXEL(16), PIXEL(29), PIXEL(57)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 2,
      range : {-PIXEL(24), -PIXEL(16), PIXEL(29), PIXEL(57)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x12,
      comboLv : 4,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000040,
      range : {-PIXEL(17), -PIXEL(41), PIXEL(32), PIXEL(21)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {-PIXEL(17), -PIXEL(41), PIXEL(32), PIXEL(21)},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x12,
      comboLv : 4,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000040,
      range : {-PIXEL(13), -PIXEL(43), PIXEL(26), PIXEL(17)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {-PIXEL(13), -PIXEL(43), PIXEL(26), PIXEL(17)},
    },
};

static const struct Collision sGaleAttackCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x10,
      comboLv : 4,
      remaining : 1,
      layer : 0x00000020,
      range : {-PIXEL(37), -PIXEL(10), PIXEL(29), PIXEL(13)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {-PIXEL(37), -PIXEL(10), PIXEL(29), PIXEL(13)},
    },
};

static const struct Collision sAction19Collisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      element : 0x00,
      nature : 0x10,
      comboLv : 1,
      remaining : 1,
      layer : 0x00000020,
      range : {-PIXEL(46), -PIXEL(10), PIXEL(35), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {-PIXEL(46), -PIXEL(10), PIXEL(35), PIXEL(8)},
    },
};

static const struct Collision sRollingCollisions[22] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000020,
      range : {PIXEL(3), -PIXEL(26), PIXEL(36), PIXEL(44)},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {PIXEL(3), -PIXEL(26), PIXEL(36), PIXEL(44)},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000020,
      range : {-PIXEL(5), -PIXEL(38), PIXEL(42), PIXEL(29)},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {-PIXEL(5), -PIXEL(38), PIXEL(42), PIXEL(29)},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000020,
      range : {-PIXEL(26), -PIXEL(31), PIXEL(31), PIXEL(40)},
    },
    [5] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {-PIXEL(26), -PIXEL(31), PIXEL(31), PIXEL(40)},
    },
    [6] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000020,
      range : {-PIXEL(28), -PIXEL(13), PIXEL(30), PIXEL(44)},
    },
    [7] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {-PIXEL(28), -PIXEL(13), PIXEL(30), PIXEL(44)},
    },
    [8] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000020,
      range : {-PIXEL(20), PIXEL(10), PIXEL(40), PIXEL(31)},
    },
    [9] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {-PIXEL(20), PIXEL(10), PIXEL(40), PIXEL(31)},
    },
    [10] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000020,
      range : {PIXEL(0), PIXEL(12), PIXEL(42), PIXEL(29)},
    },
    [11] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {PIXEL(0), PIXEL(12), PIXEL(42), PIXEL(29)},
    },
    [12] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000020,
      range : {PIXEL(19), PIXEL(3), PIXEL(31), PIXEL(40)},
    },
    [13] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {PIXEL(19), PIXEL(3), PIXEL(31), PIXEL(40)},
    },
    [14] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000020,
      range : {PIXEL(22), -PIXEL(14), PIXEL(30), PIXEL(44)},
    },
    [15] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {PIXEL(22), -PIXEL(14), PIXEL(30), PIXEL(44)},
    },
    [16] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000020,
      range : {PIXEL(13), -PIXEL(35), PIXEL(40), PIXEL(31)},
    },
    [17] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {PIXEL(13), -PIXEL(35), PIXEL(40), PIXEL(31)},
    },
    [18] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000020,
      range : {-PIXEL(25), -PIXEL(19), PIXEL(32), PIXEL(50)},
    },
    [19] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {-PIXEL(25), -PIXEL(19), PIXEL(32), PIXEL(50)},
    },
    [20] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000020,
      range : {-PIXEL(23), -PIXEL(7), PIXEL(28), PIXEL(24)},
    },
    [21] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {-PIXEL(23), -PIXEL(7), PIXEL(28), PIXEL(24)},
    },
};

static const struct Collision sSmashCollisions[6] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 5,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000020,
      range : {PIXEL(4), -PIXEL(40), PIXEL(8), PIXEL(8)},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {PIXEL(4), -PIXEL(40), PIXEL(8), PIXEL(8)},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 5,
      remaining : 3,
      layer : 0x00000020,
      range : {-PIXEL(14), -PIXEL(30), PIXEL(20), PIXEL(22)},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 2,
      range : {-PIXEL(14), -PIXEL(30), PIXEL(20), PIXEL(22)},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 5,
      remaining : 1,
      layer : 0x00000020,
      range : {-PIXEL(16), -PIXEL(1), PIXEL(29), PIXEL(36)},
    },
    [5] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 255,
      remaining : 0,
      range : {-PIXEL(16), -PIXEL(1), PIXEL(29), PIXEL(36)},
    },
};

static const struct Collision sSmashElecCollisions[6] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : (BODY_NATURE_CUT | ELEMENT_ENCHANTABLE),
      comboLv : 5,
      remaining : 1,
      layer : 0x00000040,
      range : {PIXEL(4), -PIXEL(40), PIXEL(8), PIXEL(8)},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 255,
      remaining : 0,
      range : {PIXEL(4), -PIXEL(40), PIXEL(8), PIXEL(8)},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : (BODY_NATURE_CUT | ELEMENT_ENCHANTABLE),
      comboLv : 5,
      remaining : 3,
      layer : 0x00000040,
      range : {-PIXEL(14), -PIXEL(30), PIXEL(20), PIXEL(22)},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 255,
      remaining : 2,
      range : {-PIXEL(14), -PIXEL(30), PIXEL(20), PIXEL(22)},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : (BODY_NATURE_CUT | ELEMENT_ENCHANTABLE),
      comboLv : 5,
      remaining : 1,
      layer : 0x00000040,
      range : {-PIXEL(16), -PIXEL(1), PIXEL(21), PIXEL(40)},
    },
    [5] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 255,
      remaining : 0,
      range : {-PIXEL(16), -PIXEL(1), PIXEL(21), PIXEL(40)},
    },
};

const struct Collision gSaberGeneralCollisions[2] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 0,
      remaining : 0,
      layer : 0x00000020,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      atkType : ATK_SABER,
      nature : (BODY_NATURE_CUT | ELEMENT_ENCHANTABLE),
      comboLv : 0x00,
      remaining : 0,
      layer : 0x00000040,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
};

// clang-format off
static const struct Collision* const sTripleSlash1Hitbox[8] = {
    sTripleSlash1Collisions[0],
    sTripleSlash1Collisions[0],
    sTripleSlash1Collisions[1],
    sTripleSlash1Collisions[2],
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
};
// clang-format on

// clang-format off
const struct Collision* const sTripleSlash2Hitbox[7] = {
    sTripleSlash2Collisions[0],
    sTripleSlash2Collisions[0],
    sTripleSlash2Collisions[2],
    sTripleSlash2Collisions[3],
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
};
// clang-format on

// clang-format off
const struct Collision* const sTripleSlash3Hitbox[11] = {
    sTripleSlash3Collisions[0],
    sTripleSlash3Collisions[1],
    sTripleSlash3Collisions[1],
    sTripleSlash3Collisions[1],
    sTripleSlash3Collisions[2],
    sTripleSlash3Collisions[2],
    sTripleSlash3Collisions[4],
    sTripleSlash3Collisions[6],
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
};
// clang-format on

// clang-format off
static const struct Collision* const sSaberWalkHitbox[7] = {
    sSaberWalkCollisions[0],
    sSaberWalkCollisions[0],
    sSaberWalkCollisions[2],
    sSaberWalkCollisions[3],
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
};
// clang-format on

// clang-format off
static const struct Collision* const sSaberDashHitbox[7] = {
    sSaberDashCollisions[0],
    sSaberDashCollisions[0],
    sSaberDashCollisions[1],
    sSaberDashCollisions[2],
    sSaberDashCollisions[3],
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
};
// clang-format on

// clang-format off
static const struct Collision* const sSaberAirHitbox[7] = {
    &sSaberAirCollisions[0],
    &sSaberAirCollisions[0],
    &sSaberAirCollisions[2],
    &sSaberAirCollisions[4],
    &sSaberAirCollisions[6],
    &sSaberAirCollisions[6],
    &sSaberAirCollisions[6],
};
// clang-format on

// clang-format off
static const struct Collision* const sSaberWallHitbox[6] = {
    &sSaberWallCollisions[0],
    &sSaberWallCollisions[0],
    &sSaberWallCollisions[2],
    &sSaberWallCollisions[4],
    &sSaberWallCollisions[6],
    gSaberGeneralCollisions,
};
// clang-format on

// clang-format off
static const struct Collision* const sSaberLadderHitbox[6] = {
    &sSaberLadderCollisions[0],
    &sSaberLadderCollisions[0],
    &sSaberLadderCollisions[4],
    &sSaberLadderCollisions[6],
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
};
// clang-format on

// clang-format off
static const struct Collision* const sChargeGroundHitbox[9] = {
    &sChargeGroundCollisions[0],
    &sChargeGroundCollisions[0],
    &sChargeGroundCollisions[2],
    &sChargeGroundCollisions[4],
    &sChargeGroundCollisions[4],
    &sChargeGroundCollisions[4],
    &sChargeGroundCollisions[4],
    &sChargeGroundCollisions[4],
    gSaberGeneralCollisions,
};
// clang-format on

// clang-format off
static const struct Collision* const sChargeAirHitbox[8] = {
    &sChargeAirCollisions[0],
    &sChargeAirCollisions[0],
    &sChargeAirCollisions[2],
    &sChargeAirCollisions[4],
    &sChargeAirCollisions[4],
    &sChargeAirCollisions[4],
    &sChargeAirCollisions[4],
    &sChargeAirCollisions[4],
};
// clang-format on

// clang-format off
static const struct Collision* const sChargeWallHitbox[9] = {
    &gSaberGeneralCollisions[1],
    &gSaberGeneralCollisions[1],
    &sChargeWallCollisions[0],
    &sChargeWallCollisions[0],
    &sChargeWallCollisions[0],
    &sChargeWallCollisions[0],
    &sChargeWallCollisions[0],
    &sChargeWallCollisions[0],
    &gSaberGeneralCollisions[1],
};
// clang-format on

// clang-format off
static const struct Collision* const sChargeLadderHitbox[9] = {
    &gSaberGeneralCollisions[1],
    &gSaberGeneralCollisions[1],
    &sChargeLadderCollisions[0],
    &sChargeLadderCollisions[0],
    &sChargeLadderCollisions[0],
    &sChargeLadderCollisions[0],
    &sChargeLadderCollisions[0],
    &sChargeLadderCollisions[0],
    &gSaberGeneralCollisions[1],
};
// clang-format on

// clang-format off
static const struct Collision* const sSlashUpHitbox[8] = {
    &sSlashUpCollisions[0],
    &sSlashUpCollisions[2],
    &sSlashUpCollisions[2],
    &sSlashUpCollisions[4],
    &sSlashUpCollisions[6],
    &sSlashUpCollisions[6],
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
};
// clang-format on

// clang-format off
static const struct Collision* const sThrowBladeHitbox[8] = {
    gSaberGeneralCollisions,
    &sThrowBladeCollisions[0],
    &sThrowBladeCollisions[0],
    &sThrowBladeCollisions[2],
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
    gSaberGeneralCollisions,
};
// clang-format on

static const struct Collision *const sSplitHeavens1Hitbox[2] = {
    &sSplitHeavensCollisions[2],
    &sSplitHeavensCollisions[0],
};

// clang-format off
static const struct Collision* const sSplitHeavens2Hitbox[7] = {
    &sSplitHeavensCollisions[4],
    &sSplitHeavensCollisions[4],
    &sSplitHeavensCollisions[6],
    &sSplitHeavensCollisions[8],
    &sSplitHeavensCollisions[8],
    &sSplitHeavensCollisions[8],
    &sSplitHeavensCollisions[8],
};
// clang-format on

static const struct Collision *const sGaleAttackHitbox[1] = {
    &sGaleAttackCollisions[0],
};

static const struct Collision *const sAction19Hitbox[1] = {
    &sAction19Collisions[0],
};

// clang-format off
static const struct Collision* const sAirRollingHitbox[12] = {
    &sRollingCollisions[0],
    &sRollingCollisions[2],
    &sRollingCollisions[4],
    &sRollingCollisions[6],
    &sRollingCollisions[8],
    &sRollingCollisions[10],
    &sRollingCollisions[12],
    &sRollingCollisions[14],
    &sRollingCollisions[16],
    &sRollingCollisions[2],
    &sRollingCollisions[18],
    &sRollingCollisions[20],
};
// clang-format on

// clang-format off
static const struct Collision* const sDashRollingHitbox[8] = {
    &sRollingCollisions[6],
    &sRollingCollisions[8],
    &sRollingCollisions[10],
    &sRollingCollisions[12],
    &sRollingCollisions[14],
    &sRollingCollisions[16],
    &sRollingCollisions[2],
    &sRollingCollisions[4],
};
// clang-format on

// clang-format off
static const struct Collision* const sSmashHitbox[8] = {
    &sSmashCollisions[0],
    &sSmashCollisions[2],
    &sSmashCollisions[2],
    &sSmashCollisions[4],
    &sSmashCollisions[4],
    &sSmashCollisions[4],
    &sSmashCollisions[4],
    &sSmashCollisions[4],
};
// clang-format on

// clang-format off
static const struct Collision* const sSmashElecHitbox[8] = {
    &sSmashElecCollisions[0],
    &sSmashElecCollisions[2],
    &sSmashElecCollisions[2],
    &sSmashElecCollisions[4],
    &sSmashElecCollisions[4],
    &sSmashElecCollisions[4],
    &sSmashElecCollisions[4],
    &sSmashElecCollisions[4],
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
const struct Collision *const *const gSaberCollisions[SABER_ACTION_COUNT+1] = {
    [SABER_TRIPLE_1] = sTripleSlash1Hitbox,
    [SABER_TRIPLE_2] = sTripleSlash2Hitbox,
    [SABER_TRIPLE_3] = sTripleSlash3Hitbox,
    [SABER_WALK] = sSaberWalkHitbox,
    [SABER_DASH] = sSaberDashHitbox,
    [SABER_AIR] = sSaberAirHitbox,
    [SABER_WALL] = sSaberWallHitbox,
    [SABER_LADDER] = sSaberLadderHitbox,
    [SABER_CHARGE] = sChargeGroundHitbox,
    [SABER_CHARGE_AIR] = sChargeAirHitbox,
    [SABER_CHARGE_WALL] = sChargeWallHitbox,
    [SABER_CHARGE_LADDER] = sChargeLadderHitbox,
    [SABER_SLASH_UP] = sSlashUpHitbox,
    [SABER_ZANEIDAN] = sThrowBladeHitbox,
    [SABER_TENRETUJIN] = sSplitHeavens1Hitbox,
    [SABER_TENRETUJIN_FIRE] = sSplitHeavens1Hitbox,
    [SABER_TENRETUJIN_2] = sSplitHeavens2Hitbox,
    [SABER_TENRETUJIN_FIRE_2] = sSplitHeavens2Hitbox,
    [SABER_REPUGEKI] = sGaleAttackHitbox,
    [SABER_UNK_19] = sAction19Hitbox,
    [SABER_AIR_ROLLING] = sAirRollingHitbox,
    [SABER_DASH_ROLLING] = sDashRollingHitbox,
    [SABER_SMASH] = sSmashHitbox,
    [SABER_SMASH_ELEC] = sSmashElecHitbox,
    [24] = PTR_ARRAY_08360200,
};
// clang-format on

static const bool8 gIlethasables[25] = {
    1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0,
};

// clang-format off
const WeaponRoutine gSaberRoutine = {
    [ENTITY_INIT] =      Saber_Init,
    [ENTITY_UPDATE] =    Saber_Update,
    [ENTITY_DIE] =       Saber_Die,
    [ENTITY_DISAPPEAR] = DeleteWeapon,
    [ENTITY_EXIT] =      (WeaponFunc)DeleteEntity,    
};
// clang-format on

#undef PROP
