#include "zero.h"

#include "cyberelf.h"
#include "element.h"
#include "global.h"
#include "mission.h"
#include "motion.h"
#include "overworld.h"
#include "sound.h"
#include "vfx.h"
#include "weapon.h"

static const ZeroFunc sHandlePlayerInputs[12];
static const ZeroFunc sZeroUpdates[12];
static const ZeroFunc sZeroAttacks[4];
static const ZeroRoutine gZeroRoutine;

static void onCollision(struct Body* body, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED);

void InitPlayerKeyMap(struct Zero* z);
void FUN_08033ed4(struct Zero* z);

// clang-format off
const ZeroRoutine* const gZeroFnTable[PLAYER_ENTITY_COUNT] = {
    [PLAYER_ZERO] =               &gZeroRoutine,
    [PLAYER_MINIGAME_FEFNIR] =    &gFefnirRoutine,
    [PLAYER_MINIGAME_PHANTOM] =   &gPhantomMiniRoutine,
    [PLAYER_MINIGAME_HARPUIA] =   &gHarpuiaRoutine,
    [PLAYER_MINIGAME_COPY_X] =    &gCopyXMiniRoutine,
    [PLAYER_MINIGAME_LEVIATHAN] = &gLeviathanRoutine,
    [PLAYER_MINIGAME_ZERO] =      &gZeroMiniRoutine,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

WIP void Zero_Init(struct Zero* z) {
#if MODERN
  s32 i;
  struct Zero_b4* b4;

  SET_PLAYER_ROUTINE(z, ENTITY_UPDATE);
  InitNonAffineMotion(&z->s);
  ResetDynamicMotion(&z->s);
  (z->s).flags |= DISPLAY;
  (z->s).flags |= FLIPABLE;
  SetMotion(&z->s, MOTION(DM000_ZERO_NEUTRAL, 0x00));
  UpdateMotionGraphic(&z->s);
  if ((z->s).work[1] == 0) {
    (z->s).coord.y = FUN_0800a05c((z->s).coord.x, (z->s).coord.y);
  }
  INIT_BODY(z, gZeroCollisions, 16, onCollision);
  InitPlayerKeyMap(z);
  b4 = &z->unk_b4;
  (z->s).d.x = 0;
  (z->s).d.y = 0;
  (z->s).unk_coord.x = 0;
  (z->s).unk_coord.y = 0;
  (z->s).mode[1] = b4->prevMode = 0;
  (z->s).mode[2] = b4->prevPhase = 0;
  (z->s).mode[3] = 0;
  (z->unk_b4).unused_f0[0] = (z->unk_b4).attackMode[0] = 0;
  (z->unk_b4).unused_f0[1] = (z->unk_b4).attackMode[1] = 0;
  (z->unk_b4).unused_f0[2] = (z->unk_b4).attackMode[2] = 0;
  (z->unk_b4).unused_f0[3] = (z->unk_b4).attackMode[3] = 0;
  (z->unk_b4).sound = MUS_NONE;
  (z->unk_b4).mainCopy = (b4->status).mainWeapon;
  (z->unk_b4).subCopy = (b4->status).subWeapon;

  // Unreached?
  if ((b4->status).mainWeapon == (b4->status).subWeapon) {
    u8 i;
    u16 unlocked;
    (b4->status).asset.satelites[0] = ELF_NONE;
    (b4->status).asset.satelites[1] = ELF_NONE;

    for (i = 0; i < 12; i++) {
      u32 n = 1 << i;
      if (((b4->status).unlockedExSkill & n) && ((b4->status).exSkill & n)) {
        (b4->status).exSkill &= ~n;
      }
    }
  }

  (z->unk_b4).shadow = NULL;
  (z->unk_b4).deltaX = 0;
  (z->unk_b4).softPlatform = FALSE;
  (z->unk_b4).softPlatformY = 0;
  z->isAreaChange = FALSE;
  z->airJumpped = 0;
  z->ripple = FALSE;
  z->canSplashJump = FALSE;
  z->slow = 0;
  z->idleFrame = 0;
  z->unk_121 = ELF_NONE;
  z->blown = FALSE;
  FUN_08033ed4(z);

  for (i = 0; i < 16; i++) {
    z->hazardIDs[i] = 0xFFFF;
  }
  z->isGround = FALSE;
  *((u32*)&z->horizontalSlide) = 0;
  z->globbed = FALSE;
  if (FLAG(gCurStory.s.gameflags, IN_CYBERSPACE)) {
    z->inCyberSpace = TRUE;
  } else {
    z->inCyberSpace = FALSE;
  }
  z->elfMotion = 0;
  z->subtankFilledFrame = 0;
  z->unk_234 = 0;
  z->unk_149 = 0;

  if (((b4->status).maxHP == 0) || (GetMaxHP(z) < (b4->status).maxHP)) {
    (b4->status).maxHP = GetMaxHP(z);
  }
  (z->body).hp = (b4->status).maxHP;
  CreateChargeEffect(z, CreateChargeEffect(z, NULL, 0), 1);
  CreateSateliteElf(z, SATELITE_1, 0);
  CreateSateliteElf(z, SATELITE_2, 1);
  LoadZeroPalette(&z->s, GetZeroColor(z));
  setWramElement((b4->status).element);
  Zero_Update(z);
#else
  INCCODE("asm/wip/Zero_Init.inc");
#endif
}

WIP void Zero_Update(struct Zero* z) {
#if MODERN
  s32 x = (z->s).coord.x;
  s32 y = (z->s).coord.y;

  if (!((z->s).flags & DISPLAY)) {
    resetSateliteElfPosition(z);
  }
  if (z->subtankFilledFrame > 0) {
    z->subtankFilledFrame--;
    if (z->subtankFilledFrame == 0) {
      PlaySound(SE_SUBTANK_FILLED);
    }
    return;
  }

  if ((z->unk_b4).sound == MUS_NONE) {
    if (((z->s).mode[1] != ZERO_CYBER) && (SEA < (z->s).coord.y - PIXEL(30))) {
      (z->unk_b4).sound = PlaySound(SE_IN_SEA);
    }
  } else if ((z->s).coord.y < SEA) {
    stopSound((z->unk_b4).sound);
    (z->unk_b4).sound = MUS_NONE;
  }

  (z->unk_b4).prevMode = (z->s).mode[1];
  (z->unk_b4).prevPhase = (z->s).mode[2];
  HandlePlayerInput(z);
  if ((z->body).hp != 0) {
    switch (RecoilFromFloor(z, &gZeroRanges[z->posture])) {
      case 1: {
        InstantlyKilling(z);
        break;
      }
      case 2: {
        z->isRightDir = ((z->s).flags >> 4) & 1;
        (z->body).hp = 0;
        (z->s).mode[1] = ZERO_DAMAGED;
        (z->s).mode[2] = 0;
        break;
      }
    }

    if ((z->body).hp != 0) {
      switch (RecoilFromHazards(z, &gZeroRanges[z->posture])) {
        case 1: {
          z->isRightDir = ((z->s).flags >> 4) & 1;
          (z->body).hp = 0;
          (z->s).mode[1] = ZERO_DAMAGED;
          (z->s).mode[2] = 0;
          break;
        }
        case 2: {
          InstantlyKilling(z);
          break;
        }
      }
      CheckZeroHazard(z);
    }
  }

  if (((z->s).mode[1] != ZERO_AIR) && ((z->s).mode[1] != ZERO_DAMAGED)) {
    (z->unk_b4).blownSpeed = 0;
  }

  if (z->unk_234 == 0) {
    if (((gOverworld.unk_1c8.id & 0x7F) == STAGE_TWILIGHT_DESERT) && (FUN_080101a8() != 0)) {
      z->unk_234 = 16;
    }
  } else {
    z->unk_234--;
  }

  (z->unk_b4).prevCoord = (z->s).coord;
  z->prevMotion = MOTION_VALUE(z);
  z->motionCmdIdx = (z->s).motion.cmdIdx;
  z->motionDuration = (z->s).motion.duration;
  z->prevPosture = z->posture;
  z->posture = POSTURE_IDLE;
  if (((z->s).mode[1] != ZERO_DAMAGED) || ((z->s).mode[2] != 0)) {
    z->isGround = FALSE;
  }
  z->poseFixed = FALSE;

  // 落下死
  if ((z->body).hp != 0) {
    u8 action = (z->s).mode[1];
    if ((action != ZERO_DOOR_2D) && (action != ZERO_DOOR_3D) && (action != ZERO_TELEPORT)) {
      s32 y1 = (z->s).coord.y;
      s32 y2 = y1 - gZeroRanges[z->posture].h - PIXEL(8);
      if (((z->border).bottom < y2) || (IsVoidSpace((z->s).coord.x, y1) && IsVoidSpace((z->s).coord.x, y2))) {
        metatile_attr_t attr = GetGroundMetatileAttr((z->s).coord.x, (z->s).coord.y - PIXEL(30));
        // Bird elf doesn't work for antlion
        if ((!(attr & METATILE_ANTTRAP)) && ((SATELITE_1 == ELF_BIRAID) || (SATELITE_1 == ELF_BIRLEAF) || (SATELITE_2 == ELF_BIRAID) || (SATELITE_2 == ELF_BIRLEAF))) {
          (z->s).mode[1] = ZERO_FLOAT;
          (z->s).mode[2] = 0;
        } else {
          z->isRightDir = ((z->s).flags >> 4) & 1;
          (z->body).hp = 0;
          (z->s).mode[1] = ZERO_DAMAGED;
          (z->s).mode[2] = 0;
        }
      }
    }
  }

  if (z->unk_136 != 0) {
    // z->unk_136 の bit7が立っていたら、bit7のみクリア(bit0..6はそのまま), そうでないなら z->unk_136 を 0にする
    u8 val = z->unk_136 & (1 << 7);
    if (z->unk_136 & (1 << 7)) {
      val = z->unk_136 ^ (1 << 7);
    }
    z->unk_136 = val;
  }

  (sHandlePlayerInputs[(z->s).mode[1]])(z);

  if ((z->unk_b4).softPlatform) {
    if ((z->unk_b4).softPlatformY < (z->s).coord.y) {
      metatile_attr_t attr = GetGroundMetatileAttr((z->s).coord.x, (z->s).coord.y);
      if (((attr & 0x8000) == 0) || ((attr & 0x0F) == 0) || ((attr & 0x0F) == 0x0F)) {
        (z->unk_b4).softPlatform = FALSE;
      }
    }
    if ((z->s).coord.y < (u32)((z->unk_b4).softPlatformY - PIXEL(32))) {
      (z->unk_b4).softPlatform = FALSE;
    }
  }

  if ((z->s).mode[1] != ZERO_BINDED) {
    z->unk_143.raw = 0;
  }
  if (((z->s).mode[1] != ZERO_DAMAGED) && ((z->body).hp == 0)) {
    (z->s).mode[1] = ZERO_DAMAGED;
    (z->s).mode[2] = 0;
  }

  (sZeroUpdates[(z->s).mode[1]])(z);
  z->unk_12e = 0xFF;

  bool8 tmp = FALSE;
  if ((z->restriction).shield) {
    if ((z->s).mode[1] == (z->unk_b4).prevMode) {
      if (((z->s).mode[1] != ZERO_GROUND) || ((z->s).mode[2] == (z->unk_b4).prevPhase)) goto LAB_080296fe;
    }
    if (z->chargeSaber != 0) {
      tmp = TRUE;
    } else {
      (z->unk_b4).attackMode[0] = 0;
    }
  }
LAB_080296fe:
  (z->restriction).move = FALSE;
  (z->restriction).dash = FALSE;
  (z->restriction).shield = FALSE;
  (z->restriction).b3 = FALSE;
  z->chargeSaber = 0;
  (z->restriction).b6 = tmp;
  z->rodID = 0xFF;
  z->unk_127 = 0xFF;
  if (z->rodToggle != 0) {
    z->rodToggle--;
  }

  if ((((z->posture == POSTURE_DASH) && (!(z->last & INPUT_DISABLED))) && (((FOOT == FOOT_CHIP_SHADOW) || (FOOT == FOOT_CHIP_ULTIMA)))) && (z->prevPosture == POSTURE_SHADOW)) {
    z->posture = POSTURE_SHADOW;
  }

  if ((z->s).mode[1] < 4) {
    (sZeroAttacks[(z->s).mode[1]])(z);
    if (z->elfMotion != 0) {
      z->elfMotion--;
      if (z->elfMotion == 0) {
        CreateSateliteElf(z, SATELITE_1, 0);
        CreateSateliteElf(z, SATELITE_2, 1);
      }
    }
  } else {
    (z->unk_b4).attackMode[0] = 0;
  }
  (z->restriction).mainCharge = (z->restriction).subCharge = FALSE;

  if (z->prevPosture != z->posture) {
    SetDDP(&z->body, &gZeroCollisions[z->posture]);
    if (z->posture == POSTURE_SHADOW) {
      LoadShadowDashPalette(z, GetZeroColor(z));
    } else {
      LoadZeroPalette(&z->s, GetZeroColor(z));
    }
  }

  if (((z->s).mode[1] != ZERO_DOOR_2D) && ((z->s).mode[1] != ZERO_DOOR_3D) && ((z->s).mode[1] != ZERO_TELEPORT)) {
    if (PushoutByBorder(z, &gZeroRanges[z->posture], TRUE)) {
      z->isRightDir = ((z->s).flags >> 4) & 1;
      (z->body).hp = 0;
      (z->s).mode[1] = ZERO_DAMAGED;
      (z->s).mode[2] = 0;
      (z->s).coord.x = x;
      (z->s).coord.y = y;
    }
  }

  if (!z->ripple) {
    if (SEA < (z->s).coord.y - (gZeroRanges[z->posture].h / 2)) {
      if ((z->s).coord.y - gZeroRanges[z->posture].h < SEA) {
        CreateRipple(z, 1);
      }
    } else if (SEA < (z->s).coord.y) {
      CreateRipple(z, 0);
    }
  }
  z->canSplashJump = FALSE;
  if (((z->last & INPUT_DISABLED) == 0) && ((z->body).hp != 0)) {
    s32 dx = abs(x - (z->s).coord.x);
    if (dx > PIXEL(16)) {
      z->isRightDir = ((z->s).flags >> 4) & 1;
      (z->body).hp = 0;
      (z->s).mode[1] = ZERO_DAMAGED;
      (z->s).mode[2] = 0;
      (z->s).coord.x = x;
      (z->s).coord.y = y;
    }
  }
  if (z->pushedOut && ((z->body).hp != 0)) {
    s32 dy = abs(y - (z->s).coord.y);
    if (dy > PIXEL(16)) {
      z->isRightDir = ((z->s).flags >> 4) & 1;
      (z->body).hp = 0;
      (z->s).mode[1] = ZERO_DAMAGED;
      (z->s).mode[2] = 0;
      (z->s).coord.x = x;
      (z->s).coord.y = y;
    }
  }

  if (!z->poseFixed) {
    UpdateMotionGraphic(&z->s);
  }
  setStageElfFlags(z);
  z->unk_149 = 0;
  (z->unk_b4).deltaX = (z->s).coord.x - x;
#else
  INCCODE("asm/wip/Zero_Update.inc");
#endif
};

void Zero_Die(struct Zero* z) {
  // nop
  return;
}

void Zero_Disappear(struct Zero* z) {
  s16 n = (s16)z->unk_b4.sound;
  if (n != MUS_NONE) {
    stopSound(n);
    z->unk_b4.sound = MUS_NONE;
  }
  RemovePlayer(z);
}

// Zero take damages
static void onCollision(struct Body* body, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) {
  u8 mode;

  struct Zero* z = (struct Zero*)body->parent;
  struct Entity* enemy = (struct Entity*)body->enemy->parent;
  if (body->hitboxFlags & BODY_STATUS_WHITE) {
    const u16 damage = CalcDamage(body->enemy, body);
    AddMissionDamage(damage);
    z->unk_149 = 1;
  }

  if ((body->hitboxFlags & BODY_STATUS_DEAD) == 0) {
    if ((z->s).mode[1] == ZERO_BINDED) {
      return;
    }
    if (body->hitboxFlags & BODY_STATUS_BINDED) {
      z->isRightDir = (enemy->coord).x > (z->s).coord.x;
      (z->s).mode[1] = ZERO_BINDED;
      (z->s).mode[2] = 0;
      return;
    }
  }
  if (((body->hitboxFlags & BODY_STATUS_WHITE) && (mode = (z->s).mode[1], mode != ZERO_DOOR_2D)) && (mode != ZERO_CYBER)) {
    z->isRightDir = (enemy->coord).x > (z->s).coord.x;
    (z->s).mode[1] = ZERO_DAMAGED;
    (z->s).mode[2] = 0;
  }
}

// ------------------------------------------------------------------------------------------------------------------------------------

// clang-format off
// 01 xx nn nn
static const ZeroFunc sHandlePlayerInputs[12] = {
    [ZERO_GROUND] =    HandlePlayerInput_Ground,
    [ZERO_AIR] =       HandlePlayerInput_Air,
    [ZERO_WALL] =      HandlePlayerInput_Wall,
    [ZERO_LADDER] =    HandlePlayerInput_Ladder, 
    [ZERO_DAMAGED] =   HandlePlayerInput_Damaged,
    [ZERO_DOOR_2D] =   HandlePlayerInput_Door2D,
    [ZERO_DOOR_3D] =   HandlePlayerInput_Door3D,
    [ZERO_BINDED] =    HandlePlayerInput_Mode7,
    [ZERO_FLOAT] =     HandlePlayerInput_Float,
    [ZERO_TALK] =      HandlePlayerInput_Talk,
    [ZERO_TELEPORT] =  HandlePlayerInput_Teleport,
    [ZERO_CYBER] =     HandlePlayerInput_Cyber,
};
// clang-format on

// clang-format off
// 01 xx nn nn
static const ZeroFunc sZeroUpdates[12] = {
    [ZERO_GROUND] =    zeroNeutral2,
    [ZERO_AIR] =       zeroAir2,
    [ZERO_WALL] =      zeroWall2,
    [ZERO_LADDER] =    zeroLadder2,
    [ZERO_DAMAGED] =   zeroDamaged,
    [ZERO_DOOR_2D] =   zeroDoor2D,
    [ZERO_DOOR_3D] =   zeroDoor3D,
    [ZERO_BINDED] =    zeroMode7,
    [ZERO_FLOAT] =     zeroFloat,
    [ZERO_TALK] =      zeroTalk,
    [ZERO_TELEPORT] =  zeroTeleport,
    [ZERO_CYBER] =     zeroCyberDoor,
};
// clang-format on

// clang-format off
// 01 xx nn nn
static const ZeroFunc sZeroAttacks[4] = {
    [ZERO_GROUND] =    ZeroAttack_Ground,
    [ZERO_AIR] =       ZeroAttack_Air,
    [ZERO_WALL] =      ZeroAttack_Wall,
    [ZERO_LADDER] =    ZeroAttack_Ladder,
};
// clang-format on

// clang-format off
static const ZeroRoutine gZeroRoutine = {
  [ENTITY_INIT] =       Zero_Init,
  [ENTITY_UPDATE] =     Zero_Update,
  [ENTITY_DIE]  =       Zero_Die,
  [ENTITY_DISAPPEAR] =  Zero_Disappear,
  [ENTITY_EXIT] =       (ZeroFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------
