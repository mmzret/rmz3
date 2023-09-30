#include "zero.h"

#include "cyberelf.h"
#include "entity.h"
#include "gba/gba.h"
#include "gfx.h"
#include "overworld.h"
#include "sound.h"

static void appendHazardID(struct Zero *z, u16 target);
static s32 hazard_08028114(struct Zero *z, s32 x, s32 y);
static metatile_attr_t AppendHazardID(struct Zero *z, s32 x, s32 y);
static u16 AppendHazardID_2(struct Zero *z, s32 x, s32 y);
static bool8 IsAgainstHazard(struct Zero *z, s32 x, s32 y);
static u8 hazard_0802855c(struct Zero *z, s32 x, s32 y);
static metatile_attr_t IsInHazard(struct Zero *z, s32 x, s32 y);
static bool16 hazard_08028338(struct Zero *z, s32 x, s32 y);

static metatile_attr_t _pushoutHazardX1(struct Zero *z, s32 x, s32 y, struct Coord *c);
static metatile_attr_t _pushoutHazardX2(struct Zero *z, s32 x, s32 y, struct Coord *c);

// 0x08025628
void InitPlayerHeader(struct EntityHeader *h, struct Zero *p, s16 len) {
  s16 i;

  InitEntityHeader(h, ENTITY_PLAYER, &p->s, sizeof(struct Zero), len);
  for (i = 0; i < len; i++) {
    p[i].s.uniqueID = gEntityIDGenerator + i;
  }
  gEntityIDGenerator += len;
  gZeroHeaderPtr = h;
  pZero = p;
}

struct Zero *AllocPlayer(void) {
  struct Zero *tmp;
  struct Zero *z;

  z = (struct Zero *)AllocEntityLast(gZeroHeaderPtr);
  if ((z != NULL) && (z != pZero)) {  // not equal
    tmp = AllocPlayer();
    DeletePlayer(gZeroHeaderPtr, z);
    z = tmp;
  }
  ENTITY(z).work[0] = 0;
  (z->s).tileNum = 0;
  (z->s).palID = 0;
  ENTITY(z).flags2 |= ENTITY_FLAGS2_B4;
  ENTITY(z).invincibleID = ENTITY(z).uniqueID;
  return z;
}

struct Zero *AllocPlayer2(void) {
  struct Zero *tmp;
  struct Zero *z;

  z = (struct Zero *)AllocEntityFirst(gZeroHeaderPtr);
  if ((z != NULL) && (z == pZero)) {  // equal
    tmp = AllocPlayer2();
    DeletePlayer(gZeroHeaderPtr, z);
    z = tmp;
  }
  ENTITY(z).work[0] = 1;
  (z->s).tileNum = 512;
  (z->s).palID = 4;
  ENTITY(z).flags2 |= ENTITY_FLAGS2_B4;
  ENTITY(z).invincibleID = ENTITY(z).uniqueID;
  return z;
}

void RemovePlayer(struct Zero *z) {
  SET_PLAYER_ROUTINE(z, ENTITY_EXIT);
  return;
}

void LoadZeroPalette(struct Entity *_, u32 c) {
  if (c == ZERO_COLOR_OMEGA) {
    CpuFastCopy(gZeroPalettes[c], &gPaletteManager.buf[256 + 64], 32);
    CpuFastCopy(gZeroShadowPalettes[c], &gPaletteManager.buf[256 + 128], 32);
    return;
  }

  CpuFastCopy(gZeroPalettes[c], &gPaletteManager.buf[256 + 0], 32);
  CpuFastCopy(gZeroShadowPalettes[c], &gPaletteManager.buf[256 + 192], 32);
  return;
}

void LoadShadowDashPalette(struct Zero *_, u32 c) {
  CpuFastCopy(gZeroShadowDashPalette[c], &gPaletteManager.buf[256 + 0], 32);
  return;
}

/**
 * @retval TRUE: recovered
 * @retval FALSE: not recovered
 */
bool8 UseSubtank(struct Zero *z) {
  s16 *hp = &(z->body).hp;
  if (*hp >= (u8)GetMaxHP(z)) {
    return FALSE;
  }

  *hp = *hp + 1;
  PlaySound(SE_HP_RECOVER);
  if (*hp == (u8)GetMaxHP(z)) {
    return FALSE;
  }
  return TRUE;
}

/**
 * @brief Is Martina activated?
 */
bool8 IsDoubleHP(struct Zero *z) {
  const u8 *satelites;
  if ((*gUnlockedElfPtr)[0] & ELF_AVABILITY_UNLOCKED) {
    if ((*gUnlockedElfPtr)[0] & ELF_AVABILITY_USED) return TRUE;

    satelites = (z->unk_b4).status.asset.satelites;
    if (z->inCyberSpace) return TRUE;

    if ((satelites[0] == ELF_MARTINA) || (satelites[1] == ELF_MARTINA)) {
      return TRUE;
    }
  }
  return FALSE;
}

/**
 * @return Zero Max HP (affected by Nurse(+4) and Martina(x2))
 */
NON_MATCH u8 GetMaxHP(struct Zero *z) {
#if MODERN
  const u8 *satelites;
  s32 i;
  u8 hp = 16;

  for (i = 0; i < 4; i++) {
    const cyberelf_t e = i + 1;
    if ((*gUnlockedElfPtr)[e] & ELF_AVABILITY_UNLOCKED) {
      if (((*gUnlockedElfPtr)[e] & ELF_AVABILITY_USED)) {
        hp += 4;
        continue;
      }

      satelites = ((&z->unk_b4)->status).asset.satelites;
      if (z->inCyberSpace) {
        hp += 4;
        continue;
      }

      if ((satelites[0] == e) || (satelites[1] == e)) {
        hp += 4;
      }
    }
  }

  if (IsDoubleHP(z)) {
    return (hp * 2);
  }
  return hp;
#else
  INCCODE("asm/wip/GetMaxHP.inc");
#endif
}

/**
 * @return Zero Max HP (affected by Nurse(+4))
 */
u8 getMaxHP1x(struct Zero *z) {
  bool8 martina;
  u8 maxHP;

  martina = IsDoubleHP(z);
  if (!martina) {
    maxHP = GetMaxHP(z);
  } else {
    maxHP = GetMaxHP(z);
    maxHP /= 2;
  }
  return maxHP;
}

/**
 * @brief Gain E-Crystal
 * @return TRUE: success, FALSE: fail
 */
bool8 AddECrystal(struct Zero *z, u16 amount) {
  struct ZeroAsset *a = &((z->unk_b4).status.asset);

  u16 ec = a->EC;
  if (ec < 10000) {
    a->EC = a->EC + amount;
    PlaySound(SE_GAIN_ECRYSTAL);
    if (a->EC < 10000) {
      return TRUE;
    }
    a->EC = 9999;
  }

  return FALSE;
}

/**
 * @brief increment Subtank HP
 * @return TRUE: success, FALSE: fail (No Subtank, or All Subtanks are filled)
 */
bool8 incrementSubtankHP(struct Zero *z) {
  u8 *tanks;
  u8 *tank;
  u8 hp;

  u32 i;
  for (i = 0; i < 4; i++) {
    tanks = (z->unk_b4.status).asset.subtankHP;
    tank = &tanks[i];
    hp = *tank;
    if (hp < 32) {
      *tank = hp + 1;
      if (*tank == 32) {
        PlaySound(SE_SUBTANK_FILLED);
        return FALSE;
      }
      PlaySound(SE_SUBTANK_RECOVER);
      return TRUE;
    }
  }

  return FALSE;
}

u8 makeZeroSlower(struct Zero *z, u8 val) {
  if (0xff < z->slow + val) {
    z->slow = 0xff;
  } else {
    z->slow = z->slow + val;
  }
  return z->slow;
}

u8 makeZeroFaster(struct Zero *z, u8 val) {
  if (z->slow - val < 0) {
    z->slow = 0;
  } else {
    z->slow = z->slow - val;
  }
  return z->slow;
}

u8 CountButtonMashing(struct Zero *z) {
  u8 result = 0;
  if (z->pressed & DPAD_UP) result++;
  if (z->pressed & DPAD_DOWN) result++;
  if (z->pressed & DPAD_LEFT) result++;
  if (z->pressed & DPAD_RIGHT) result++;
  if (z->pressed & B_BUTTON) result++;
  if (z->pressed & A_BUTTON) result++;
  return result;
}

void ResetZeroInput(struct Zero *z) {
  z->zeroInput = 0;
  (z->unk_b4).status.charge[0] = 0;
  (z->unk_b4).status.charge[1] = 0;
}

void resetSateliteElfPosition(struct Zero *z) {
  z->elfMotion = 2;
  return;
}

// u16 = struct Action
motion_t GetDefaultMotion(struct Zero *z) {
  if ((z->unk_b4).status.dying != 0) {
    return MOTION(DM001_ZERO_DYING, 0);
  }
  return MOTION(DM000_ZERO_NEUTRAL, 0);
}

// ゼロが壁にめり込んだときに横に押し出す処理(= ゼロが壁にぶつかったときにX方向にめり込まないようにする処理)
WIP metatile_attr_t PushoutWallX(struct Zero *z, const struct Rect *p, u8 r2) {
#if MODERN
  metatile_attr_t attr;
  s32 x;
  s32 y[3];
  s16 i, len;
  metatile_attr_t retval = 0;
  PushoutByBorder(z, p, FALSE);
  if ((z->s).flags & X_FLIP) {
    x = (z->s).coord.x - p->x;
    if (r2) {
      x -= (p->w / 2);
    } else {
      x += (p->w / 2);
    }
  } else {
    x = (z->s).coord.x + p->x;
    if (r2) {
      x += (p->w / 2);
    } else {
      x -= (p->w / 2);
    }
  }
  y[0] = (z->s).coord.y + p->y;
  y[1] = (z->s).coord.y + p->y - (p->h / 2);
  y[2] = (z->s).coord.y + p->y + (p->h / 2);

  if (z->hazardCount != 0) {
    u16 i;
    for (i = 0; i < (3 - r2); i++) {
      attr = AppendHazardID(z, x, y[i]);
      if ((!(attr & METATILE_SOFT_PLATFORM)) || (((attr & 0xF) == 0) || ((attr & 0xF) == 0xF))) {
        if (attr != 0) {
          struct Coord c;
          if ((z->s).mode[1] == ZERO_WALL) {
            retval = _pushoutHazardX1(z, x, y[i], &c);
          } else if (i == 0) {
            retval = _pushoutHazardX1(z, x, y[i], &c);
          } else {
            retval = _pushoutHazardX2(z, x, y[i], &c);
          }
          if (retval != 0) {
            x += c.x;
            y[0] += c.y;
            y[1] += c.y;
            y[2] += c.y;
          }
        }
      }
    }
  }

  attr = GetMetatileAttr((z->unk_b4).prevCoord.x, y[2]);
  if ((attr & 0xF) == METATILE_GROUND) {
    u32 shape;
    attr = GetMetatileAttr((z->s).coord.x, y[2] - PIXEL(4));
    shape = attr & 0xF;
    if ((((shape != METATILE_WALL) && (shape != SHAPE_4)) && (shape != SHAPE_9)) && (shape != 0xd)) {
      attr = METATILE_GROUND;
    }
  }

  len = 3;
  attr = attr & 0xf;
  if (METATILE_GROUND < attr) {
    if (attr < 8) {
      len = 3;
      if (((~((z->s).flags >> 4)) & 1) == r2) {
        len = 2;
      }
    } else if (attr < 14) {
      len = 2;
      if (((~((z->s).flags >> 4)) & 1) == r2) {
        len = 3;
      }
    }
  }

  for (i = 0; i < len; i++) {
    metatile_attr_t attr = GetGroundMetatileAttr(x, y[i]);
    if ((attr & 0x0F) == METATILE_GROUND) {
      if (!(attr & METATILE_SOFT_PLATFORM) && !(attr & METATILE_ANTTRAP)) {
        s32 dx;
        if ((z->s).flags & X_FLIP) {
          if (r2) {
            dx = PushoutToRight2(x, y[i]);
          } else {
            dx = PushoutToLeft2(x, y[i]);
          }
        } else {
          if (r2) {
            dx = PushoutToLeft2(x, y[i]);
          } else {
            dx = PushoutToRight2(x, y[i]);
          }
        }
        (z->s).coord.x += dx;
        x += dx;
        retval = attr;
      }

    } else if (((attr & 0x0F) != 0) && ((attr & 0x0F) < 14)) {
      if ((attr & 0x0F) < 8) {
        if (((z->s).coord.x > x) && (GetMetatileAttr(x + PIXEL(16), y[i]) == 0)) {
          const s32 dx = PushoutToRight2(x, y[i]);
          (z->s).coord.x += dx;
          x += dx;
          retval = attr;
        }
      } else {
        if (((z->s).coord.x < x) && (GetMetatileAttr(x - PIXEL(16), y[i]) == 0)) {
          const s32 dx = PushoutToLeft2(x, y[i]);
          (z->s).coord.x += dx;
          x += dx;
          retval = attr;
        }
      }
    }
  }
  return retval;
#else
  INCCODE("asm/wip/PushoutWallX.inc");
#endif
}

NAKED metatile_attr_t PushoutByFloor1(struct Zero *z, const struct Rect *p, bool8 r2) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x28\n\
	adds r6, r0, #0\n\
	mov sl, r1\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	str r2, [sp, #0x14]\n\
	movs r0, #0\n\
	str r0, [sp, #0x1c]\n\
	ldr r2, [r6, #0x54]\n\
	str r2, [sp]\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08025D82\n\
	mov r1, sl\n\
	movs r3, #0\n\
	ldrsh r0, [r1, r3]\n\
	subs r0, r2, r0\n\
	ldrh r1, [r1, #4]\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x11\n\
	adds r0, r0, r1\n\
	str r0, [sp, #4]\n\
	mov r4, sl\n\
	movs r3, #0\n\
	ldrsh r0, [r4, r3]\n\
	subs r0, r2, r0\n\
	subs r0, r0, r1\n\
	b _08025D9C\n\
_08025D82:\n\
	mov r4, sl\n\
	movs r1, #0\n\
	ldrsh r0, [r4, r1]\n\
	adds r0, r2, r0\n\
	ldrh r1, [r4, #4]\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x11\n\
	subs r0, r0, r1\n\
	str r0, [sp, #4]\n\
	movs r3, #0\n\
	ldrsh r0, [r4, r3]\n\
	adds r0, r2, r0\n\
	adds r0, r0, r1\n\
_08025D9C:\n\
	str r0, [sp, #8]\n\
	mov r4, sl\n\
	movs r1, #2\n\
	ldrsh r0, [r4, r1]\n\
	ldr r1, [r6, #0x58]\n\
	adds r1, r1, r0\n\
	ldrh r0, [r4, #6]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x11\n\
	adds r1, r1, r0\n\
	mov r8, r1\n\
	movs r2, #0xc6\n\
	lsls r2, r2, #1\n\
	adds r0, r6, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _08025E9E\n\
	movs r3, #0\n\
	str r3, [sp, #0x18]\n\
_08025DC2:\n\
	ldr r0, [sp, #0x18]\n\
	lsls r4, r0, #2\n\
	mov r1, sp\n\
	adds r5, r1, r4\n\
	ldr r1, [r5]\n\
	adds r0, r6, #0\n\
	mov r2, r8\n\
	bl AppendHazardID\n\
	lsls r0, r0, #0x10\n\
	lsrs r7, r0, #0x10\n\
	adds r0, r7, #0\n\
	movs r2, #0x80\n\
	lsls r2, r2, #8\n\
	ands r0, r2\n\
	mov sb, r4\n\
	cmp r0, #0\n\
	beq _08025E48\n\
	movs r4, #0xf\n\
	adds r0, r7, #0\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	beq _08025E48\n\
	cmp r0, #0xe\n\
	bhi _08025E48\n\
	ldr r3, [sp, #0x14]\n\
	cmp r3, #0\n\
	beq _08025E90\n\
	cmp r0, #0\n\
	beq _08025E48\n\
	cmp r0, #0xe\n\
	bhi _08025E48\n\
	ldr r1, _08025EE0 @ =0x00000113\n\
	adds r0, r6, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _08025E90\n\
	movs r2, #0x80\n\
	lsls r2, r2, #1\n\
	adds r3, r6, r2\n\
	ldr r2, [r3]\n\
	ldr r0, [r6, #0x54]\n\
	subs r2, r2, r0\n\
	ldr r1, [r5]\n\
	adds r1, r1, r2\n\
	ldr r2, [r3, #4]\n\
	ldr r0, [r6, #0x58]\n\
	subs r2, r2, r0\n\
	add r2, r8\n\
	adds r2, #1\n\
	adds r0, r6, #0\n\
	bl AppendHazardID_2\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	adds r0, r1, #0\n\
	movs r3, #0x80\n\
	lsls r3, r3, #8\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	beq _08025E48\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08025E48\n\
	cmp r0, #0xe\n\
	bls _08025E90\n\
_08025E48:\n\
	cmp r7, #0\n\
	beq _08025E90\n\
	mov r0, sp\n\
	add r0, sb\n\
	ldr r1, [r0]\n\
	adds r0, r6, #0\n\
	mov r2, r8\n\
	add r3, sp, #0xc\n\
	bl _pushoutHazardY\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #0x1c]\n\
	add r5, sp, #0xc\n\
	cmp r0, #0\n\
	beq _08025E90\n\
	ldr r0, [sp, #4]\n\
	mov r1, r8\n\
	bl GetMetatileAttr\n\
	movs r4, #0xf\n\
	adds r1, r4, #0\n\
	ands r1, r0\n\
	cmp r1, #1\n\
	beq _08025E8C\n\
	ldr r0, [sp, #8]\n\
	mov r1, r8\n\
	bl GetMetatileAttr\n\
	adds r1, r4, #0\n\
	ands r1, r0\n\
	cmp r1, #1\n\
	beq _08025E8C\n\
	b _08026202\n\
_08025E8C:\n\
	ldr r0, [r5, #4]\n\
	add r8, r0\n\
_08025E90:\n\
	ldr r0, [sp, #0x18]\n\
	adds r0, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #0x18]\n\
	cmp r0, #2\n\
	bls _08025DC2\n\
_08025E9E:\n\
	ldr r0, [sp]\n\
	mov r1, r8\n\
	bl GetGroundMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	lsrs r7, r0, #0x10\n\
	movs r4, #0x80\n\
	lsls r4, r4, #3\n\
	adds r0, r7, #0\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	beq _08025EE4\n\
	ldr r0, [sp, #0x14]\n\
	cmp r0, #0\n\
	beq _08025EDC\n\
	adds r0, r6, #0\n\
	adds r0, #0xb4\n\
	ldrb r0, [r0, #0x10]\n\
	cmp r0, #1\n\
	bne _08025EDC\n\
	movs r2, #0x80\n\
	lsls r2, r2, #1\n\
	adds r1, r6, r2\n\
	ldr r0, [r1]\n\
	ldr r1, [r1, #4]\n\
	bl GetGroundMetatileAttr\n\
	adds r1, r4, #0\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _08025EE4\n\
_08025EDC:\n\
	adds r0, r7, #0\n\
	b _08026204\n\
	.align 2, 0\n\
_08025EE0: .4byte 0x00000113\n\
_08025EE4:\n\
	ldr r3, [sp, #0x14]\n\
	cmp r3, #0\n\
	beq _08025F96\n\
	ldr r0, [r6, #0x54]\n\
	mov r1, r8\n\
	bl GetGroundMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	lsrs r7, r0, #0x10\n\
	ldr r0, [r6, #0x54]\n\
	mov r1, r8\n\
	bl PushoutToUp2\n\
	adds r4, r0, #0\n\
	movs r0, #0x80\n\
	lsls r0, r0, #8\n\
	mov sb, r0\n\
	adds r0, r7, #0\n\
	mov r1, sb\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08025F74\n\
	movs r5, #0xf\n\
	adds r0, r7, #0\n\
	ands r0, r5\n\
	cmp r0, #0\n\
	beq _08025F74\n\
	cmp r0, #0xe\n\
	bhi _08025F74\n\
	movs r2, #0x80\n\
	lsls r2, r2, #1\n\
	adds r1, r6, r2\n\
	ldr r0, [r1]\n\
	mov r3, sl\n\
	movs r2, #2\n\
	ldrsh r3, [r3, r2]\n\
	mov ip, r3\n\
	ldr r1, [r1, #4]\n\
	add r1, ip\n\
	mov r3, sl\n\
	ldrh r2, [r3, #6]\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x11\n\
	adds r1, r1, r2\n\
	bl GetGroundMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	adds r0, r1, #0\n\
	mov r2, sb\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _08025F5A\n\
	adds r0, r5, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08025F5A\n\
	cmp r0, #0xe\n\
	bls _08025F70\n\
_08025F5A:\n\
	movs r3, #0x80\n\
	lsls r3, r3, #1\n\
	adds r0, r6, r3\n\
	ldr r1, [r6, #0x58]\n\
	adds r1, r1, r4\n\
	movs r2, #0xe0\n\
	lsls r2, r2, #3\n\
	adds r1, r1, r2\n\
	ldr r0, [r0, #4]\n\
	cmp r0, r1\n\
	ble _08025F74\n\
_08025F70:\n\
	movs r0, #0\n\
	b _08026204\n\
_08025F74:\n\
	ldr r0, _08025F80 @ =0x0000800E\n\
	cmp r7, r0\n\
	bne _08025F84\n\
	ldr r0, [r6, #0x58]\n\
	b _080261C0\n\
	.align 2, 0\n\
_08025F80: .4byte 0x0000800E\n\
_08025F84:\n\
	movs r0, #0xf\n\
	ands r0, r7\n\
	subs r0, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0xc\n\
	bhi _0802603A\n\
	ldr r0, [r6, #0x58]\n\
	b _080261C0\n\
_08025F96:\n\
	ldr r0, [r6, #0x54]\n\
	mov r1, r8\n\
	bl GetGroundMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	lsrs r7, r0, #0x10\n\
	movs r0, #0x80\n\
	lsls r0, r0, #8\n\
	ands r0, r7\n\
	cmp r0, #0\n\
	beq _08025FC2\n\
	movs r0, #0xf\n\
	ands r0, r7\n\
	cmp r0, #0\n\
	beq _08025FC2\n\
	cmp r0, #0xe\n\
	bhi _08025FC2\n\
	ldr r3, _08026028 @ =0x0000018D\n\
	adds r0, r6, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0802603A\n\
_08025FC2:\n\
	ldr r0, [r6, #0x54]\n\
	movs r5, #0xa0\n\
	lsls r5, r5, #3\n\
	mov r4, r8\n\
	adds r1, r4, r5\n\
	bl PushoutToUp2\n\
	adds r4, r0, #0\n\
	cmp r4, #0\n\
	bge _0802603A\n\
	ldr r1, _0802602C @ =0x0000018F\n\
	adds r0, r6, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _08026030\n\
	movs r0, #0x80\n\
	lsls r0, r0, #8\n\
	ands r0, r7\n\
	cmp r0, #0\n\
	beq _08025FF6\n\
	movs r0, #0xf\n\
	ands r0, r7\n\
	cmp r0, #0\n\
	beq _08025FF6\n\
	cmp r0, #0xe\n\
	bls _0802603A\n\
_08025FF6:\n\
	ldr r1, [sp, #4]\n\
	mov r2, r8\n\
	adds r0, r2, r4\n\
	movs r3, #0xa0\n\
	lsls r3, r3, #3\n\
	mov sb, r3\n\
	adds r5, r0, r3\n\
	adds r0, r6, #0\n\
	adds r2, r5, #0\n\
	bl IsInHazard\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _0802603A\n\
	ldr r1, [sp, #8]\n\
	adds r0, r6, #0\n\
	adds r2, r5, #0\n\
	bl IsInHazard\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _0802603A\n\
	ldr r0, [r6, #0x58]\n\
	add r0, sb\n\
	b _080261C0\n\
	.align 2, 0\n\
_08026028: .4byte 0x0000018D\n\
_0802602C: .4byte 0x0000018F\n\
_08026030:\n\
	ldr r0, [r6, #0x58]\n\
	adds r0, r0, r5\n\
	b _080261C0\n\
_08026036:\n\
	ldr r0, [r6, #0x58]\n\
	b _080261C0\n\
_0802603A:\n\
	movs r4, #1\n\
	str r4, [sp, #0x18]\n\
	movs r0, #0xf\n\
	mov sl, r0\n\
	movs r1, #0x80\n\
	lsls r1, r1, #1\n\
	adds r1, r6, r1\n\
	str r1, [sp, #0x20]\n\
_0802604A:\n\
	ldr r2, [sp, #0x18]\n\
	lsls r4, r2, #2\n\
	mov r3, sp\n\
	adds r5, r3, r4\n\
	ldr r0, [r5]\n\
	mov r1, r8\n\
	bl GetGroundMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	lsrs r7, r0, #0x10\n\
	adds r1, r7, #0\n\
	mov r0, sl\n\
	ands r1, r0\n\
	mov sb, r4\n\
	cmp r1, #0\n\
	bne _0802606C\n\
	b _080261F2\n\
_0802606C:\n\
	cmp r1, #0xd\n\
	bls _08026072\n\
	b _080261F2\n\
_08026072:\n\
	cmp r1, #1\n\
	bne _080260F4\n\
	movs r4, #0x80\n\
	lsls r4, r4, #8\n\
	adds r0, r7, #0\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	beq _080260D0\n\
	ldr r1, [sp, #0x14]\n\
	cmp r1, #0\n\
	bne _0802608A\n\
	b _080261F2\n\
_0802608A:\n\
	ldr r2, [sp, #0x20]\n\
	ldr r1, [r2]\n\
	ldr r0, [r6, #0x54]\n\
	subs r1, r1, r0\n\
	ldr r0, [r5]\n\
	adds r0, r0, r1\n\
	ldr r1, [r2, #4]\n\
	ldr r2, [r6, #0x58]\n\
	subs r1, r1, r2\n\
	add r1, r8\n\
	bl GetGroundMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	adds r0, r1, #0\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	beq _080260BC\n\
	mov r0, sl\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080260BC\n\
	cmp r0, #0xe\n\
	bhi _080260BC\n\
	b _080261F2\n\
_080260BC:\n\
	mov r0, r8\n\
	adds r0, #1\n\
	ldr r1, _080260F0 @ =0xFFFFF000\n\
	ands r0, r1\n\
	subs r0, #1\n\
	ldr r3, [sp, #0x20]\n\
	ldr r1, [r3, #4]\n\
	cmp r1, r0\n\
	bls _080260D0\n\
	b _080261F2\n\
_080260D0:\n\
	mov r0, sp\n\
	add r0, sb\n\
	ldr r0, [r0]\n\
	mov r1, r8\n\
	bl PushoutToUp2\n\
	adds r4, r0, #0\n\
	cmp r4, #0\n\
	blt _080260E4\n\
	b _080261F2\n\
_080260E4:\n\
	ldr r0, [r6, #0x58]\n\
	adds r0, r0, r4\n\
	str r0, [r6, #0x58]\n\
	add r8, r4\n\
	str r7, [sp, #0x1c]\n\
	b _080261F2\n\
	.align 2, 0\n\
_080260F0: .4byte 0xFFFFF000\n\
_080260F4:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #8\n\
	adds r0, r7, #0\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _08026140\n\
	cmp r1, #0\n\
	beq _08026140\n\
	cmp r1, #0xe\n\
	bhi _08026140\n\
	ldr r0, [r5]\n\
	ldr r4, _08026178 @ =0xFFFFF000\n\
	add r4, r8\n\
	adds r1, r4, #0\n\
	str r2, [sp, #0x24]\n\
	bl GetMetatileAttr\n\
	ldr r2, [sp, #0x24]\n\
	adds r1, r2, #0\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _08026140\n\
	ldr r0, [r5]\n\
	adds r1, r4, #0\n\
	bl GetMetatileAttr\n\
	mov r1, sl\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _08026140\n\
	ldr r0, [r5]\n\
	adds r1, r4, #0\n\
	bl GetMetatileAttr\n\
	mov r1, sl\n\
	ands r1, r0\n\
	cmp r1, #0xe\n\
	bls _080261F2\n\
_08026140:\n\
	mov r4, sp\n\
	add r4, sb\n\
	ldr r2, [r4]\n\
	ldr r0, [r6, #0x54]\n\
	cmp r2, r0\n\
	ble _08026198\n\
	adds r0, r7, #0\n\
	mov r1, sl\n\
	ands r0, r1\n\
	cmp r0, #7\n\
	bhi _0802617C\n\
	ldr r0, _08026178 @ =0xFFFFF000\n\
	ands r2, r0\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #3\n\
	add r1, r8\n\
	adds r0, r2, #0\n\
	bl PushoutToUp2\n\
	adds r4, r0, #0\n\
	cmp r4, #0\n\
	bge _080261F2\n\
	ldr r0, [r6, #0x58]\n\
	movs r2, #0xa0\n\
	lsls r2, r2, #3\n\
	adds r0, r0, r2\n\
	b _080261C0\n\
	.align 2, 0\n\
_08026178: .4byte 0xFFFFF000\n\
_0802617C:\n\
	ldr r5, _08026194 @ =0xFFFFF000\n\
	adds r0, r2, r5\n\
	mov r1, r8\n\
	bl GetMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080261F2\n\
	ldr r0, [r4]\n\
	ands r0, r5\n\
	b _080261E4\n\
	.align 2, 0\n\
_08026194: .4byte 0xFFFFF000\n\
_08026198:\n\
	adds r0, r7, #0\n\
	mov r3, sl\n\
	ands r0, r3\n\
	cmp r0, #7\n\
	bls _080261CC\n\
	ldr r0, _080261C8 @ =0x00000FFF\n\
	orrs r2, r0\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #3\n\
	add r1, r8\n\
	adds r0, r2, #0\n\
	bl PushoutToUp2\n\
	adds r4, r0, #0\n\
	cmp r4, #0\n\
	bge _080261F2\n\
	ldr r0, [r6, #0x58]\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #3\n\
	adds r0, r0, r1\n\
_080261C0:\n\
	adds r0, r0, r4\n\
	str r0, [r6, #0x58]\n\
	b _08025EDC\n\
	.align 2, 0\n\
_080261C8: .4byte 0x00000FFF\n\
_080261CC:\n\
	movs r3, #0x80\n\
	lsls r3, r3, #5\n\
	adds r0, r2, r3\n\
	mov r1, r8\n\
	bl GetMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080261F2\n\
	ldr r0, [r4]\n\
	ldr r1, _08026214 @ =0x00000FFF\n\
	orrs r0, r1\n\
_080261E4:\n\
	mov r1, r8\n\
	bl PushoutToUp2\n\
	adds r4, r0, #0\n\
	cmp r4, #0\n\
	bgt _080261F2\n\
	b _08026036\n\
_080261F2:\n\
	ldr r0, [sp, #0x18]\n\
	adds r0, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #0x18]\n\
	cmp r0, #2\n\
	bhi _08026202\n\
	b _0802604A\n\
_08026202:\n\
	ldr r0, [sp, #0x1c]\n\
_08026204:\n\
	add sp, #0x28\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_08026214: .4byte 0x00000FFF\n\
 .syntax divided\n");
}

NAKED metatile_attr_t PushoutByCeiling(struct Zero *z, const struct Rect *p, bool8 r2) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	sub sp, #0x10\n\
	mov r8, r0\n\
	adds r3, r1, #0\n\
	movs r0, #0\n\
	mov sb, r0\n\
	movs r1, #2\n\
	ldrsh r0, [r3, r1]\n\
	mov r2, r8\n\
	ldr r1, [r2, #0x58]\n\
	adds r1, r1, r0\n\
	ldrh r0, [r3, #6]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x11\n\
	subs r6, r1, r0\n\
	ldrb r1, [r2, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08026262\n\
	movs r4, #0\n\
	ldrsh r1, [r3, r4]\n\
	ldr r2, [r2, #0x54]\n\
	subs r1, r2, r1\n\
	ldrh r0, [r3, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x11\n\
	adds r1, r1, r0\n\
	str r1, [sp]\n\
	movs r4, #0\n\
	ldrsh r1, [r3, r4]\n\
	subs r2, r2, r1\n\
	subs r2, r2, r0\n\
	b _0802627E\n\
_08026262:\n\
	movs r0, #0\n\
	ldrsh r1, [r3, r0]\n\
	mov r4, r8\n\
	ldr r2, [r4, #0x54]\n\
	adds r1, r2, r1\n\
	ldrh r0, [r3, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x11\n\
	subs r1, r1, r0\n\
	str r1, [sp]\n\
	movs r4, #0\n\
	ldrsh r1, [r3, r4]\n\
	adds r2, r2, r1\n\
	adds r2, r2, r0\n\
_0802627E:\n\
	str r2, [sp, #4]\n\
	movs r0, #0xc6\n\
	lsls r0, r0, #1\n\
	add r0, r8\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _080262F2\n\
	movs r7, #0\n\
_0802628E:\n\
	lsls r0, r7, #2\n\
	add r0, sp\n\
	ldr r1, [r0]\n\
	mov r0, r8\n\
	adds r2, r6, #0\n\
	bl AppendHazardID\n\
	lsls r0, r0, #0x10\n\
	lsrs r4, r0, #0x10\n\
	movs r0, #0x80\n\
	lsls r0, r0, #8\n\
	adds r1, r0, #0\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080262BA\n\
	movs r0, #0xf\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	beq _080262BA\n\
	cmp r0, #0xe\n\
	bls _080262E8\n\
_080262BA:\n\
	lsls r0, r7, #2\n\
	add r0, sp\n\
	ldr r1, [r0]\n\
	add r5, sp, #8\n\
	mov r0, r8\n\
	adds r2, r6, #0\n\
	adds r3, r5, #0\n\
	bl _pushoutHazardY\n\
	lsls r0, r0, #0x10\n\
	lsrs r4, r0, #0x10\n\
	cmp r4, #0\n\
	beq _080262E8\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #8]\n\
	adds r0, r0, r1\n\
	str r0, [sp]\n\
	ldr r0, [sp, #4]\n\
	adds r0, r0, r1\n\
	str r0, [sp, #4]\n\
	ldr r0, [r5, #4]\n\
	adds r6, r6, r0\n\
	mov sb, r4\n\
_080262E8:\n\
	adds r0, r7, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r7, r0, #0x10\n\
	cmp r7, #1\n\
	bls _0802628E\n\
_080262F2:\n\
	movs r7, #0\n\
_080262F4:\n\
	lsls r0, r7, #2\n\
	mov r1, sp\n\
	adds r5, r0, r1\n\
	ldr r0, [r5]\n\
	adds r1, r6, #0\n\
	bl GetMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	lsrs r4, r0, #0x10\n\
	movs r2, #0x80\n\
	lsls r2, r2, #3\n\
	adds r1, r2, #0\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0802633E\n\
	movs r0, #0xf\n\
	ands r0, r4\n\
	cmp r0, #1\n\
	bne _0802633E\n\
	movs r0, #0x80\n\
	lsls r0, r0, #8\n\
	adds r1, r0, #0\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0802633E\n\
	ldr r0, [r5]\n\
	adds r1, r6, #0\n\
	bl PushoutToDown2\n\
	mov r2, r8\n\
	ldr r1, [r2, #0x58]\n\
	adds r1, r1, r0\n\
	str r1, [r2, #0x58]\n\
	adds r6, r6, r0\n\
	mov sb, r4\n\
_0802633E:\n\
	adds r0, r7, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r7, r0, #0x10\n\
	cmp r7, #1\n\
	bls _080262F4\n\
	mov r0, sb\n\
	add sp, #0x10\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED metatile_attr_t PushoutByCeilingOnLadder(struct Zero *z, const struct Rect *p, bool8 r2) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #8\n\
	adds r6, r0, #0\n\
	adds r3, r1, #0\n\
	movs r1, #2\n\
	ldrsh r0, [r3, r1]\n\
	ldr r1, [r6, #0x58]\n\
	adds r1, r1, r0\n\
	ldrh r0, [r3, #6]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x11\n\
	subs r7, r1, r0\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080263A2\n\
	movs r4, #0\n\
	ldrsh r1, [r3, r4]\n\
	ldr r2, [r6, #0x54]\n\
	subs r1, r2, r1\n\
	ldrh r0, [r3, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x11\n\
	adds r1, r1, r0\n\
	str r1, [sp]\n\
	movs r4, #0\n\
	ldrsh r1, [r3, r4]\n\
	subs r2, r2, r1\n\
	subs r2, r2, r0\n\
	b _080263BC\n\
_08026396:\n\
	ldr r0, [r6]\n\
	adds r1, r7, #0\n\
	bl PushoutToDown2\n\
_0802639E:\n\
	adds r0, r4, #0\n\
	b _0802644A\n\
_080263A2:\n\
	movs r0, #0\n\
	ldrsh r1, [r3, r0]\n\
	ldr r2, [r6, #0x54]\n\
	adds r1, r2, r1\n\
	ldrh r0, [r3, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x11\n\
	subs r1, r1, r0\n\
	str r1, [sp]\n\
	movs r4, #0\n\
	ldrsh r1, [r3, r4]\n\
	adds r2, r2, r1\n\
	adds r2, r2, r0\n\
_080263BC:\n\
	str r2, [sp, #4]\n\
	movs r1, #0xc6\n\
	lsls r1, r1, #1\n\
	adds r0, r6, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _08026406\n\
	movs r5, #0\n\
_080263CC:\n\
	lsls r0, r5, #2\n\
	add r0, sp\n\
	ldr r1, [r0]\n\
	adds r0, r6, #0\n\
	adds r2, r7, #0\n\
	bl AppendHazardID\n\
	lsls r0, r0, #0x10\n\
	lsrs r4, r0, #0x10\n\
	movs r0, #0x80\n\
	lsls r0, r0, #8\n\
	adds r1, r0, #0\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080263F8\n\
	movs r0, #0xf\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	beq _080263F8\n\
	cmp r0, #0xe\n\
	bls _080263FC\n\
_080263F8:\n\
	cmp r4, #0\n\
	bne _0802639E\n\
_080263FC:\n\
	adds r0, r5, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	cmp r5, #1\n\
	bls _080263CC\n\
_08026406:\n\
	movs r5, #0\n\
_08026408:\n\
	lsls r0, r5, #2\n\
	mov r1, sp\n\
	adds r6, r0, r1\n\
	ldr r0, [r6]\n\
	adds r1, r7, #0\n\
	bl GetMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	lsrs r4, r0, #0x10\n\
	movs r0, #0x80\n\
	lsls r0, r0, #3\n\
	adds r1, r0, #0\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0802643E\n\
	movs r0, #0xf\n\
	ands r0, r4\n\
	cmp r0, #1\n\
	bne _0802643E\n\
	movs r0, #0x80\n\
	lsls r0, r0, #8\n\
	adds r1, r0, #0\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08026396\n\
_0802643E:\n\
	adds r0, r5, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	cmp r5, #1\n\
	bls _08026408\n\
	movs r0, #0\n\
_0802644A:\n\
	add sp, #8\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

/*
  壁ずり中の壁というよりはゼロのいる座標のMetatile Attr
  Reg swapだけ解決できなかっただけでロジックはあってる
*/
NON_MATCH metatile_attr_t GetWallMetatileAttr(struct Zero *z, const struct Rect *p, bool8 _ UNUSED) {
#if MODERN
  metatile_attr_t attr;
  struct Coord c;

  const s32 y = (z->s).coord.y + p->y - (p->h >> 1);  // Zero's center Y
  if (z->hazardCount != 0) {
    metatile_attr_t attr = AppendHazardID(z, (z->s).coord.x, y);
    if (((attr & METATILE_SOFT_PLATFORM) == 0) || ((attr & 0xF) == 0) || ((attr & 0xF) == 0xF)) {
      _pushoutHazardY(z, (z->s).coord.x, y, &c);
    }
  }

  attr = GetMetatileAttr((z->s).coord.x, y);

  // めり込んでる?(すり抜け床と重なってる場合は除く)
  if (((attr & 0xF) == METATILE_GROUND) && !(attr & METATILE_SOFT_PLATFORM)) {
    (z->s).coord.y += PushoutToDown2((z->s).coord.x, y);
  }
  return attr;
#else
  INCCODE("asm/wip/GetWallMetatileAttr.inc");
#endif
}

/*
  r2 が TRUE の場合は、今のゼロが立っているところ(床)のMettaileAttrを返す(ただしすり抜け床のときは0)
  r2 が FALSE の場合は、　床からの押し出し処理を行う
*/
NAKED metatile_attr_t PushoutByFloor2(struct Zero *z, const struct Rect *p, bool8 checkOnly) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, #0xc\n\
	adds r6, r0, #0\n\
	adds r3, r1, #0\n\
	lsls r2, r2, #0x18\n\
	movs r1, #2\n\
	ldrsh r0, [r3, r1]\n\
	ldr r1, [r6, #0x58]\n\
	adds r1, r1, r0\n\
	ldrh r0, [r3, #6]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x11\n\
	adds r1, r1, r0\n\
	adds r7, r1, #1\n\
	cmp r2, #0\n\
	beq _0802651A\n\
	ldr r0, [r6, #0x54]\n\
	adds r1, r7, #0\n\
	bl GetGroundMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	movs r0, #0x80\n\
	lsls r0, r0, #8\n\
	ands r0, r5\n\
	cmp r0, #0\n\
	beq _08026518\n\
	b _080266E2\n\
_08026518:\n\
	b _08026638\n\
_0802651A:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802653E\n\
	movs r2, #0\n\
	ldrsh r0, [r3, r2]\n\
	ldr r2, [r6, #0x54]\n\
	subs r0, r2, r0\n\
	ldrh r1, [r3, #4]\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x11\n\
	subs r0, r0, r1\n\
	str r0, [sp]\n\
	movs r4, #0\n\
	ldrsh r0, [r3, r4]\n\
	subs r0, r2, r0\n\
	b _08026556\n\
_0802653E:\n\
	movs r1, #0\n\
	ldrsh r0, [r3, r1]\n\
	ldr r2, [r6, #0x54]\n\
	adds r0, r2, r0\n\
	ldrh r1, [r3, #4]\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x11\n\
	subs r0, r0, r1\n\
	str r0, [sp]\n\
	movs r4, #0\n\
	ldrsh r0, [r3, r4]\n\
	adds r0, r2, r0\n\
_08026556:\n\
	adds r0, r0, r1\n\
	str r0, [sp, #4]\n\
	str r2, [sp, #8]\n\
	movs r1, #0xc6\n\
	lsls r1, r1, #1\n\
	adds r0, r6, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0802658A\n\
	movs r4, #0\n\
_0802656A:\n\
	lsls r0, r4, #2\n\
	add r0, sp\n\
	ldr r1, [r0]\n\
	adds r0, r6, #0\n\
	adds r2, r7, #0\n\
	bl AppendHazardID\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	cmp r5, #0\n\
	bne _08026638\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #2\n\
	bls _0802656A\n\
_0802658A:\n\
	movs r4, #0\n\
	subs r6, r7, #1\n\
	movs r2, #0x80\n\
	lsls r2, r2, #3\n\
	mov r8, r2\n\
_08026594:\n\
	lsls r0, r4, #2\n\
	add r0, sp\n\
	ldr r0, [r0]\n\
	adds r1, r6, #0\n\
	bl GetGroundMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	adds r0, r5, #0\n\
	mov r1, r8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08026638\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #1\n\
	bls _08026594\n\
	ldr r0, [sp, #8]\n\
	adds r1, r7, #0\n\
	bl PushoutToUp2\n\
	cmp r0, #0\n\
	bge _080265E0\n\
	ldr r0, [sp, #8]\n\
	adds r1, r7, #0\n\
	bl GetGroundMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	ldr r0, _080265DC @ =0x0000800F\n\
	cmp r5, r0\n\
	bne _080265D8\n\
	b _080266E2\n\
_080265D8:\n\
	b _08026638\n\
	.align 2, 0\n\
_080265DC: .4byte 0x0000800F\n\
_080265E0:\n\
	ldr r0, [sp]\n\
	adds r1, r7, #0\n\
	bl GetMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	cmp r5, #0\n\
	beq _08026668\n\
	movs r4, #0xf\n\
	ands r4, r5\n\
	cmp r4, #1\n\
	beq _08026638\n\
	ldr r0, [sp, #8]\n\
	adds r1, r7, #0\n\
	bl GetGroundMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _08026668\n\
	subs r0, r4, #2\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #5\n\
	bhi _08026644\n\
	ldr r0, [sp]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #5\n\
	adds r0, r0, r2\n\
	adds r1, r7, #0\n\
	bl GetMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _08026668\n\
	ldr r0, [sp]\n\
	ldr r1, _0802663C @ =0xFFFFF000\n\
	ands r0, r1\n\
	ldr r1, _08026640 @ =0x00000FFF\n\
	adds r0, r0, r1\n\
	adds r1, r7, #0\n\
	bl PushoutToUp2\n\
	cmp r0, #0\n\
	bgt _08026668\n\
_08026638:\n\
	adds r0, r5, #0\n\
	b _080266E4\n\
	.align 2, 0\n\
_0802663C: .4byte 0xFFFFF000\n\
_08026640: .4byte 0x00000FFF\n\
_08026644:\n\
	adds r0, r4, #0\n\
	subs r0, #8\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #5\n\
	bhi _08026668\n\
	ldr r0, [sp]\n\
	ldr r1, _080266BC @ =0xFFFFF000\n\
	ands r0, r1\n\
	ldr r1, _080266C0 @ =0x00000FFF\n\
	adds r0, r0, r1\n\
	movs r4, #0xa0\n\
	lsls r4, r4, #3\n\
	adds r1, r7, r4\n\
	bl PushoutToUp2\n\
	cmp r0, #0\n\
	blt _08026638\n\
_08026668:\n\
	ldr r0, [sp, #4]\n\
	adds r1, r7, #0\n\
	bl GetMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	cmp r5, #0\n\
	beq _080266E2\n\
	movs r4, #0xf\n\
	ands r4, r5\n\
	cmp r4, #1\n\
	beq _08026638\n\
	ldr r0, [sp, #8]\n\
	adds r1, r7, #0\n\
	bl GetGroundMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080266E2\n\
	adds r0, r4, #0\n\
	subs r0, #8\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #5\n\
	bhi _080266C4\n\
	ldr r0, [sp, #4]\n\
	ldr r4, _080266BC @ =0xFFFFF000\n\
	adds r0, r0, r4\n\
	adds r1, r7, #0\n\
	bl GetMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080266E2\n\
	ldr r0, [sp, #4]\n\
	ands r0, r4\n\
	adds r1, r7, #0\n\
	bl PushoutToUp2\n\
	cmp r0, #0\n\
	bgt _080266E2\n\
	b _08026638\n\
	.align 2, 0\n\
_080266BC: .4byte 0xFFFFF000\n\
_080266C0: .4byte 0x00000FFF\n\
_080266C4:\n\
	subs r0, r4, #2\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #5\n\
	bhi _080266E2\n\
	ldr r0, [sp, #4]\n\
	ldr r1, _080266F0 @ =0xFFFFF000\n\
	ands r0, r1\n\
	movs r2, #0xa0\n\
	lsls r2, r2, #3\n\
	adds r1, r7, r2\n\
	bl PushoutToUp2\n\
	cmp r0, #0\n\
	blt _08026638\n\
_080266E2:\n\
	movs r0, #0\n\
_080266E4:\n\
	add sp, #0xc\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_080266F0: .4byte 0xFFFFF000\n\
 .syntax divided\n");
}

WIP metatile_attr_t IsOnSoftPlatform(struct Zero *z, const struct Rect *p, bool8 r2) {
#if MODERN
  s32 i;
  s32 x[3];
  s32 y;
  metatile_attr_t result = 0;

  if ((z->s).flags & X_FLIP) {
    x[2] = (z->s).coord.x;
    x[0] = ((z->s).coord.x - p->x) + (p->w >> 1);
    x[1] = ((z->s).coord.x - p->x) - (p->w >> 1);
  } else {
    x[2] = (z->s).coord.x;
    x[0] = ((z->s).coord.x + p->x) - (p->w >> 1);
    x[1] = ((z->s).coord.x + p->x) + (p->w >> 1);
  }
  y = (z->s).coord.y + p->y + (p->h >> 1) + 1;

  for (i = 0; i < 3; i++) {
    metatile_attr_t attr = AppendHazardID(z, x[i], y);
    if (attr & METATILE_SOFT_PLATFORM) {
      if ((attr & 0xF) != 0) {
        if ((attr & 0xF) == 0xF) {
          return 0;
        }
        return METATILE_WALL;
      }
    } else if ((attr & 0xF) != 0) {
      return 0;
    }
  }
  for (i = 0; i < 3; i++) {
    metatile_attr_t attr = GetMetatileAttr(x[i], y);
    if (attr != 0) {
      if ((attr & METATILE_SOFT_PLATFORM) == 0 || (attr & 0xF) == 0 || (attr & 0xF) == 0xF) {
        return 0;
      }
      result = METATILE_GROUND;
    }
  }
  return result;
#else
  INCCODE("asm/wip/IsOnSoftPlatform.inc");
#endif
}

bool8 CanWallSlide(struct Zero *z, const struct Rect *p, bool8 r2) {
  bool8 ok = IsForwardPressed(z, p, r2);
  if (ok && IsZeroAgainstWall(z, p, r2)) {
    return TRUE;
  }
  return FALSE;
}

bool8 IsForwardPressed(struct Zero *z, const struct Rect *p UNUSED, bool8 _ UNUSED) {
  if ((z->s).flags & X_FLIP) {
    if (!(z->zeroInput & DPAD_RIGHT)) {
      return FALSE;
    }
  } else {
    if (!(z->zeroInput & DPAD_LEFT)) {
      return FALSE;
    }
  }
  if (z->globbed) {
    return FALSE;
  }
  return TRUE;
}

NON_MATCH bool8 IsZeroAgainstWall(struct Zero *z, const struct Rect *p, bool8 _) {
#if MODERN
  s32 x, y;
  metatile_attr_t attr;
  metatile_attr_t mask = 0x881F;
  if ((z->body).invincibleTime != 0) {
    mask = 0x880F;
  }
  if ((z->s).flags & X_FLIP) {
    x = (z->s).coord.x - p->x + (p->w >> 1) + 1;
  } else {
    x = (z->s).coord.x + p->x - (p->w >> 1) - 1;
  }

  y = (z->s).coord.y + p->y + (p->h >> 1) - PIXEL(2);
  if (IsAgainstHazard(z, x, y)) {
    return 1;
  }

  attr = GetMetatileAttr(x, y);
  if ((attr & mask) != 1 || attr != 0) {
    y = (z->s).coord.y + p->y;
    if (IsAgainstHazard(z, x, y)) {
      return 1;
    }

    attr = GetMetatileAttr(x, y);
    if ((attr & mask) != 1) {
      y = (z->s).coord.y + p->y - (p->h >> 1);
      if (IsAgainstHazard(z, x, y)) {
        return 1;
      }

      attr = GetMetatileAttr(x, y);
      if ((attr & mask) != 1) {
        return 0;
      }
    }
  }
  return 1;
#else
  INCCODE("asm/wip/IsZeroAgainstWall.inc");
#endif
}

NAKED u8 zero_08026970(struct Zero *z, const struct Rect *p, bool8 _) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	adds r7, r0, #0\n\
	mov r8, r1\n\
	movs r1, #0x8c\n\
	lsls r1, r1, #2\n\
	adds r0, r7, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0802698A\n\
	b _08026BA0\n\
_0802698A:\n\
	adds r0, r7, #0\n\
	adds r0, #0x94\n\
	ldrb r0, [r0]\n\
	ldr r2, _080269C4 @ =0x0000881F\n\
	mov sb, r2\n\
	cmp r0, #0\n\
	beq _0802699C\n\
	ldr r3, _080269C8 @ =0x0000880F\n\
	mov sb, r3\n\
_0802699C:\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080269D0\n\
	mov r1, r8\n\
	movs r2, #0\n\
	ldrsh r0, [r1, r2]\n\
	ldr r2, [r7, #0x54]\n\
	subs r2, r2, r0\n\
	ldrh r0, [r1, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x11\n\
	adds r1, r2, r0\n\
	movs r3, #0x80\n\
	lsls r3, r3, #4\n\
	adds r4, r1, r3\n\
	subs r2, r2, r0\n\
	ldr r0, _080269CC @ =0xFFFFF800\n\
	b _080269EC\n\
	.align 2, 0\n\
_080269C4: .4byte 0x0000881F\n\
_080269C8: .4byte 0x0000880F\n\
_080269CC: .4byte 0xFFFFF800\n\
_080269D0:\n\
	mov r1, r8\n\
	movs r2, #0\n\
	ldrsh r0, [r1, r2]\n\
	ldr r2, [r7, #0x54]\n\
	adds r2, r2, r0\n\
	ldrh r0, [r1, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x11\n\
	subs r1, r2, r0\n\
	ldr r3, _08026A48 @ =0xFFFFF800\n\
	adds r4, r1, r3\n\
	adds r2, r2, r0\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
_080269EC:\n\
	adds r5, r2, r0\n\
	mov r1, r8\n\
	movs r2, #2\n\
	ldrsh r0, [r1, r2]\n\
	ldr r1, [r7, #0x58]\n\
	adds r1, r1, r0\n\
	mov r3, r8\n\
	ldrh r0, [r3, #6]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x11\n\
	adds r1, r1, r0\n\
	ldr r0, _08026A4C @ =0xFFFFFE00\n\
	adds r6, r1, r0\n\
	adds r0, r7, #0\n\
	adds r1, r4, #0\n\
	adds r2, r6, #0\n\
	bl hazard_0802855c\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _08026A1A\n\
	b _08026BA2\n\
_08026A1A:\n\
	adds r0, r4, #0\n\
	adds r1, r6, #0\n\
	bl GetMetatileAttr\n\
	mov r1, sb\n\
	ands r1, r0\n\
	cmp r1, #1\n\
	bne _08026A66\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08026A54\n\
	ldr r1, _08026A50 @ =0xFFFFF000\n\
	adds r0, r4, r1\n\
	adds r1, r6, #0\n\
	bl GetMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _08026A66\n\
_08026A44:\n\
	movs r0, #2\n\
	b _08026BA2\n\
	.align 2, 0\n\
_08026A48: .4byte 0xFFFFF800\n\
_08026A4C: .4byte 0xFFFFFE00\n\
_08026A50: .4byte 0xFFFFF000\n\
_08026A54:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #5\n\
	adds r0, r4, r2\n\
	adds r1, r6, #0\n\
	bl GetMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _08026AA6\n\
_08026A66:\n\
	adds r0, r7, #0\n\
	adds r1, r5, #0\n\
	adds r2, r6, #0\n\
	bl hazard_0802855c\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _08026A7A\n\
	b _08026BA2\n\
_08026A7A:\n\
	adds r0, r5, #0\n\
	adds r1, r6, #0\n\
	bl GetMetatileAttr\n\
	mov r1, sb\n\
	ands r1, r0\n\
	cmp r1, #1\n\
	bne _08026ABA\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08026AAA\n\
	movs r3, #0x80\n\
	lsls r3, r3, #5\n\
	adds r0, r5, r3\n\
	adds r1, r6, #0\n\
	bl GetMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _08026ABA\n\
_08026AA6:\n\
	movs r0, #1\n\
	b _08026BA2\n\
_08026AAA:\n\
	ldr r1, _08026AF4 @ =0xFFFFF000\n\
	adds r0, r5, r1\n\
	adds r1, r6, #0\n\
	bl GetMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _08026A44\n\
_08026ABA:\n\
	mov r2, r8\n\
	movs r3, #2\n\
	ldrsh r1, [r2, r3]\n\
	ldr r0, [r7, #0x58]\n\
	adds r6, r0, r1\n\
	adds r0, r7, #0\n\
	adds r1, r4, #0\n\
	adds r2, r6, #0\n\
	bl hazard_0802855c\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _08026BA2\n\
	adds r0, r4, #0\n\
	adds r1, r6, #0\n\
	bl GetMetatileAttr\n\
	mov r1, sb\n\
	ands r1, r0\n\
	cmp r1, #1\n\
	bne _08026AF8\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08026A44\n\
	b _08026AA6\n\
	.align 2, 0\n\
_08026AF4: .4byte 0xFFFFF000\n\
_08026AF8:\n\
	adds r0, r7, #0\n\
	adds r1, r5, #0\n\
	adds r2, r6, #0\n\
	bl hazard_0802855c\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _08026BA2\n\
	adds r0, r5, #0\n\
	adds r1, r6, #0\n\
	bl GetMetatileAttr\n\
	mov r1, sb\n\
	ands r1, r0\n\
	cmp r1, #1\n\
	bne _08026B26\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08026AA6\n\
	b _08026A44\n\
_08026B26:\n\
	mov r1, r8\n\
	movs r2, #2\n\
	ldrsh r0, [r1, r2]\n\
	ldr r1, [r7, #0x58]\n\
	adds r1, r1, r0\n\
	mov r3, r8\n\
	ldrh r0, [r3, #6]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x11\n\
	subs r6, r1, r0\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r6\n\
	mov r8, r0\n\
	adds r0, r7, #0\n\
	adds r1, r4, #0\n\
	mov r2, r8\n\
	bl hazard_0802855c\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _08026BA2\n\
	adds r0, r4, #0\n\
	adds r1, r6, #0\n\
	bl GetMetatileAttr\n\
	mov r1, sb\n\
	ands r1, r0\n\
	cmp r1, #1\n\
	bne _08026B72\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08026B70\n\
	b _08026A44\n\
_08026B70:\n\
	b _08026AA6\n\
_08026B72:\n\
	adds r0, r7, #0\n\
	adds r1, r5, #0\n\
	mov r2, r8\n\
	bl hazard_0802855c\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _08026BA2\n\
	adds r0, r5, #0\n\
	adds r1, r6, #0\n\
	bl GetMetatileAttr\n\
	mov r1, sb\n\
	ands r1, r0\n\
	cmp r1, #1\n\
	bne _08026BA0\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08026AA6\n\
	b _08026A44\n\
_08026BA0:\n\
	movs r0, #0\n\
_08026BA2:\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NON_MATCH u8 ladder_08026bb0(struct Zero *z, const struct Rect *range, bool8 _) {
#if MODERN
  u8 val;
  metatile_attr_t attr;
  attr = GetMetatileAttr((z->s).coord.x, (z->s).coord.y + range->y);
  if (attr == (METATILE_SOFT_PLATFORM | 0x0F)) {
    val = 1;
  } else if (attr == (METATILE_SOFT_PLATFORM | 0x0E)) {
    val = 2;
  } else {
    attr = GetMetatileAttr((&(z->unk_b4).prevCoord)->x, (&(z->unk_b4).prevCoord)->y + range->y);
    val = 3;
  }
  return val;
#else
  INCCODE("asm/wip/ladder_08026bb0.inc");
#endif
}

/**
 * @return 0: fail, 1: success(continue) 2: success(end)
 */
u8 TryLadderUp(struct Zero *z, const struct Rect *range, bool8 _) {
  metatile_attr_t attr;
  s32 x;
  const s32 y = (z->s).coord.y + (int)range->y;

  // Check 1
  attr = GetMetatileAttr((z->s).coord.x, y);
  if (attr == METTAILE_LADDER) {
    return 1;
  }
  if (attr == METTAILE_LADDER_FLOOR) {
    return 2;
  }

  // Check 2
  if ((z->s).flags & X_FLIP) {
    x = (z->s).coord.x + PIXEL(5);
  } else {
    x = (z->s).coord.x - PIXEL(5);
  }
  attr = GetMetatileAttr(x, y);
  if (attr == METTAILE_LADDER) {
    (z->s).coord.x = x;
    return 1;
  }
  if (attr == METTAILE_LADDER_FLOOR) {
    (z->s).coord.x = x;
    return 2;
  }

  // Check 3
  if ((z->s).flags & X_FLIP) {
    x = (z->s).coord.x - PIXEL(2);
  } else {
    x = (z->s).coord.x + PIXEL(2);
  }
  attr = GetMetatileAttr(x, y);
  if (attr == METTAILE_LADDER) {
    (z->s).coord.x = x;
    return 1;
  }
  if (attr == METTAILE_LADDER_FLOOR) {
    (z->s).coord.x = x;
    return 2;
  }

  return 0;
}

// 現在ハシゴ状態で、さらに下に梯子を降りれるか
WIP u8 TryContinueLadderDown(struct Zero *z, const struct Rect *range, bool8 _) {
#if MODERN
  metatile_attr_t attr = GetGroundMetatileAttr((z->s).coord.x, (z->s).coord.y + range->y + (range->h / 2) + 1);
  if (attr != METTAILE_LADDER_FLOOR) {
    if (((z->s).mode[1] == ZERO_LADDER) && (((attr & 0xF) - 1) < 0xD)) {
      return 3;
    }

    attr = GetMetatileAttr((z->s).coord.x, (z->s).coord.y + range->y);
    if (attr == METTAILE_LADDER) {
      return 1;
    }
    if (attr != METTAILE_LADDER_FLOOR) {
      return 0;
    }
  }
  return 2;
#else
  INCCODE("asm/wip/zero_08026ccc.inc");
#endif
}

/**
 *  現在idle状態で、梯子下降状態に移行できるか
 * @return 0: fail, 2: success
 */
WIP u8 TryLadderDown(struct Zero *z, const struct Rect *range, bool8 _) {
#if MODERN
  s32 x;
  s32 y = (z->s).coord.y + range->y + (range->h / 2) + 1;
  metatile_attr_t attr = AppendHazardID(z, (z->s).coord.x, y);
  if ((attr & 0x0F) != 0) {
    return 0;
  }

  attr = GetMetatileAttr((z->s).coord.x, y);
  if (attr != METTAILE_LADDER_FLOOR) {
    if ((z->s).flags & X_FLIP) {
      x = (z->s).coord.x + PIXEL(5);
    } else {
      x = (z->s).coord.x - PIXEL(5);
    }
    attr = GetMetatileAttr(x, y);

    if (attr != METTAILE_LADDER_FLOOR) {
      if ((z->s).flags & X_FLIP) {
        x = (z->s).coord.x - PIXEL(2);
      } else {
        x = (z->s).coord.x + PIXEL(2);
      }
      attr = GetMetatileAttr(x, y);

      if (attr != METTAILE_LADDER_FLOOR) {
        return 0;
      }
    }
    (z->s).coord.x = x;
  }
  return 2;
#else
  INCCODE("asm/wip/TryLadderDown.inc");
#endif
}

void SetDisableArea(struct Zero *z, s32 left, s32 top, s32 right, s32 bottom) {
  (z->border).left = left;
  (z->border).right = right;
  (z->border).top = top;
  (z->border).bottom = bottom;
}

// ゼロが border の外に行かないようにする
WIP bool8 PushoutByBorder(struct Zero *z, const struct Rect *range, bool8 checkHazard) {
#if MODERN
  if ((z->border).left < (z->border).right) {
    s32 x1, x2;
    s32 tmp;
    if ((z->s).flags & X_FLIP) {
      tmp = -range->x;
    } else {
      tmp = range->x;
    }
    x1 = tmp - (range->w >> 1);
    x2 = tmp + (range->w >> 1);

    // ゼロが border の左端より左に行かないようにする
    if ((z->s).coord.x < (z->border).left - x1) {
      (z->s).coord.x = ((z->border).left - x1) + 1;
    }

    if (checkHazard) {
      if ((z->s).coord.x < (z->border).left - x1 + 1) {
        if ((AppendHazardID(z, (z->s).coord.x + x2, (z->s).coord.y + range->y + (range->h >> 1))) != 0) {
          return TRUE;
        }
        if ((AppendHazardID(z, (z->s).coord.x + x2, (z->s).coord.y + range->y - (range->h >> 1))) != 0) {
          return TRUE;
        }
      }
    }

    // ゼロが border の右端より右に行かないようにする
    if ((z->border).right < (z->s).coord.x + x2) {
      (z->s).coord.x = ((z->border).right - x2) - 1;
    }

    if (checkHazard) {
      if ((z->s).coord.x > (z->border).right - x2 - 1) {
        if ((AppendHazardID(z, (z->s).coord.x + x1, (z->s).coord.y + range->y + (range->h >> 1))) != 0) {
          return TRUE;
        }
        if ((AppendHazardID(z, (z->s).coord.x + x1, (z->s).coord.y + range->y - (range->h >> 1))) != 0) {
          return TRUE;
        }
      }
    }
  }

  // ゼロが border の上端より上に行かないようにする
  if (((z->border).top < (z->border).bottom) && ((z->s).coord.y - range->h < (z->border).top)) {
    (z->s).coord.y = (z->border).top + range->h;
    if ((z->s).mode[1] == ZERO_AIR && (z->s).mode[2] == 1) {
      (z->s).mode[2] = 2;
      (z->s).mode[3] = 0;
    }
  }
  return FALSE;
#else
  INCCODE("asm/wip/PushoutByBorder.inc");
#endif
}

// 夕闇の砂漠の流砂に沈んでいく処理関連
u8 zero_08026f90(struct Zero *z, const struct Rect *range) {
  metatile_attr_t attr;
  s32 x;
  s32 dy = PushoutToUp2((z->s).coord.x, (z->s).coord.y);
  if (dy < 0) {
    (z->s).coord.y += dy;
    z->unk_234 = 0x10;
  }

  if ((z->s).flags & X_FLIP) {
    x = ((z->s).coord.x - range->x) + (range->w >> 1);
  } else {
    x = ((z->s).coord.x + range->x) - (range->w >> 1);
  }
  attr = GetGroundMetatileAttr(x, (z->s).coord.y);
  if ((attr & 0xF) < 2) {
    dy = PushoutToUp2(x, (z->s).coord.y);
    if (dy < 0) {
      (z->s).coord.y += dy;
      z->unk_234 = 0x10;
    }
  }

  if ((z->s).flags & X_FLIP) {
    x = ((z->s).coord.x - range->x) - (range->w >> 1);
  } else {
    x = ((z->s).coord.x + range->x) + (range->w >> 1);
  }
  attr = GetGroundMetatileAttr(x, (z->s).coord.y);
  if ((attr & 0xF) < 2) {
    dy = PushoutToUp2(x, (z->s).coord.y);
    if (dy < 0) {
      (z->s).coord.y += dy;
      z->unk_234 = 0x10;
    }
  }
  return 0;
}

// ------------------------------------------------------------------------------------------------------------------------------------

// ゼロと干渉するhazardオブジェクトのインデックスと個数をチェックする
WIP void CheckZeroHazard(struct Zero *z) {
#if MODERN
  u8 i;
  s32 x = (z->s).coord.x;
  s32 y = (z->s).coord.y;
  z->hazardCount = 0;
  for (i = 0; i < HAZARD_LENGTH; i++) {
    struct Hazard *hz = HAZARD(i);
    const u32 w = (u32)((u16)hz->w) + PIXEL(31);
    const u32 h = (u32)((u16)hz->h) + PIXEL(31);
    if ((u32)(x - hz->start.x) + w < (u32)(w * 2)) {
      if ((u32)(y - PIXEL(15) - hz->start.y) + h < (u32)(h * 2)) {
        z->hazard[z->hazardCount] = i;
        z->hazardCount++;
      }
    }
  }
#else
  INCCODE("asm/wip/CheckZeroHazard.inc");
#endif
}

// Hazard となるEntity と プレイヤーが重なった時に、プレイヤーを弾き出す
NAKED u8 RecoilFromHazards(struct Zero *z, const struct Rect *range) {
  // TODO
  INCCODE("asm/wip/RecoilFromHazards.inc");
}

// Hazardによる横方向への押し出し処理っぽい
NAKED static metatile_attr_t _pushoutHazardX2(struct Zero *z, s32 x, s32 y, struct Coord *c) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x18\n\
	adds r6, r0, #0\n\
	mov sl, r1\n\
	mov sb, r2\n\
	adds r5, r3, #0\n\
	movs r0, #0\n\
	str r0, [r5, #4]\n\
	str r0, [r5]\n\
	str r0, [sp]\n\
	movs r1, #0\n\
	str r1, [sp, #4]\n\
	movs r2, #0xc6\n\
	lsls r2, r2, #1\n\
	adds r0, r6, r2\n\
	ldr r3, [sp]\n\
	ldrb r0, [r0]\n\
	cmp r3, r0\n\
	blo _080279B4\n\
	b _08027DE0\n\
_080279B4:\n\
	movs r4, #0xae\n\
	lsls r4, r4, #1\n\
	adds r0, r6, r4\n\
	ldr r7, [sp, #4]\n\
	adds r0, r0, r7\n\
	ldrb r0, [r0]\n\
	str r0, [sp, #8]\n\
	lsls r0, r0, #1\n\
	ldr r1, [sp, #8]\n\
	adds r0, r0, r1\n\
	lsls r4, r0, #3\n\
	ldr r2, _08027A58 @ =gOverworld\n\
	movs r3, #0xee\n\
	lsls r3, r3, #1\n\
	adds r0, r2, r3\n\
	adds r0, r0, r4\n\
	mov r8, r0\n\
	ldr r1, [r0]\n\
	mov r7, sl\n\
	subs r1, r7, r1\n\
	adds r2, r4, r2\n\
	movs r0, #0xec\n\
	lsls r0, r0, #1\n\
	adds r0, r2, r0\n\
	str r0, [sp, #0x14]\n\
	ldrh r0, [r0]\n\
	adds r1, r1, r0\n\
	lsls r0, r0, #1\n\
	cmp r1, r0\n\
	blo _080279F2\n\
	b _08027DC6\n\
_080279F2:\n\
	ldr r1, _08027A58 @ =gOverworld\n\
	adds r3, #4\n\
	adds r0, r1, r3\n\
	adds r3, r4, r0\n\
	ldr r1, [r3]\n\
	mov r7, sb\n\
	subs r1, r7, r1\n\
	movs r7, #0xed\n\
	lsls r7, r7, #1\n\
	adds r0, r2, r7\n\
	ldrh r0, [r0]\n\
	adds r1, r1, r0\n\
	lsls r0, r0, #1\n\
	cmp r1, r0\n\
	blo _08027A12\n\
	b _08027DC6\n\
_08027A12:\n\
	movs r1, #0xea\n\
	lsls r1, r1, #1\n\
	adds r0, r2, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r6, #0\n\
	str r3, [sp, #0x10]\n\
	bl appendHazardID\n\
	ldr r2, _08027A58 @ =gOverworld\n\
	adds r7, #0xa\n\
	adds r0, r2, r7\n\
	adds r0, r4, r0\n\
	mov r1, r8\n\
	ldr r2, [r1]\n\
	ldr r0, [r0]\n\
	ldr r3, [sp, #0x10]\n\
	cmp r2, r0\n\
	beq _08027A38\n\
	b _08027B50\n\
_08027A38:\n\
	ldr r7, _08027A5C @ =gOverworld+488\n\
	adds r0, r4, r7\n\
	ldr r1, [r3]\n\
	ldr r0, [r0]\n\
	cmp r1, r0\n\
	beq _08027A46\n\
	b _08027B50\n\
_08027A46:\n\
	ldr r3, [r6, #0x54]\n\
	cmp r2, r3\n\
	bge _08027A60\n\
	ldr r1, [sp, #0x14]\n\
	ldrh r0, [r1]\n\
	adds r0, r2, r0\n\
	mov r2, sl\n\
	subs r0, r0, r2\n\
	b _08027A6C\n\
	.align 2, 0\n\
_08027A58: .4byte gOverworld\n\
_08027A5C: .4byte gOverworld+488\n\
_08027A60:\n\
	ldr r4, [sp, #0x14]\n\
	ldrh r0, [r4]\n\
	subs r0, r2, r0\n\
	mov r7, sl\n\
	subs r0, r0, r7\n\
	subs r0, #1\n\
_08027A6C:\n\
	str r0, [r5]\n\
	ldr r1, [r5]\n\
	cmp r1, #0\n\
	beq _08027AB0\n\
	adds r2, r1, #0\n\
	cmp r1, #0\n\
	bge _08027A7C\n\
	rsbs r2, r1, #0\n\
_08027A7C:\n\
	ldr r0, _08027AA4 @ =0x00000FFF\n\
	cmp r2, r0\n\
	bgt _08027AB0\n\
	ldr r2, [sp, #8]\n\
	lsls r0, r2, #1\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #3\n\
	ldr r4, _08027AA8 @ =gOverworld\n\
	adds r0, r0, r4\n\
	movs r7, #0xeb\n\
	lsls r7, r7, #1\n\
	adds r0, r0, r7\n\
	ldrh r0, [r0]\n\
	str r0, [sp]\n\
	adds r0, r3, r1\n\
	str r0, [r6, #0x54]\n\
	add sl, r1\n\
	ldr r0, _08027AAC @ =0x0000018F\n\
	adds r1, r6, r0\n\
	b _08027DC2\n\
	.align 2, 0\n\
_08027AA4: .4byte 0x00000FFF\n\
_08027AA8: .4byte gOverworld\n\
_08027AAC: .4byte 0x0000018F\n\
_08027AB0:\n\
	movs r1, #0\n\
	str r1, [r5]\n\
	ldr r0, [r6, #0x58]\n\
	ldr r2, _08027AF0 @ =0xFFFFF000\n\
	adds r1, r0, r2\n\
	adds r7, r0, #0\n\
	cmp sb, r1\n\
	ble _08027AFC\n\
	ldr r3, [sp, #8]\n\
	lsls r4, r3, #1\n\
	adds r0, r4, r3\n\
	lsls r0, r0, #3\n\
	ldr r1, _08027AF4 @ =gOverworld\n\
	movs r2, #0xf0\n\
	lsls r2, r2, #1\n\
	adds r3, r1, r2\n\
	adds r2, r0, r3\n\
	adds r0, r0, r1\n\
	movs r1, #0xed\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	ldr r0, [r2]\n\
	subs r0, r0, r1\n\
	mov r2, sb\n\
	subs r0, r0, r2\n\
	subs r0, #1\n\
	str r0, [r5, #4]\n\
	ldr r0, _08027AF8 @ =0xFFFFFE20\n\
	adds r1, r3, r0\n\
	str r4, [sp, #0xc]\n\
	b _08027B26\n\
	.align 2, 0\n\
_08027AF0: .4byte 0xFFFFF000\n\
_08027AF4: .4byte gOverworld\n\
_08027AF8: .4byte 0xFFFFFE20\n\
_08027AFC:\n\
	ldr r1, [sp, #8]\n\
	lsls r3, r1, #1\n\
	adds r0, r3, r1\n\
	lsls r0, r0, #3\n\
	ldr r2, _08027B4C @ =gOverworld\n\
	movs r4, #0xf0\n\
	lsls r4, r4, #1\n\
	adds r1, r2, r4\n\
	adds r1, r0, r1\n\
	adds r0, r0, r2\n\
	movs r2, #0xed\n\
	lsls r2, r2, #1\n\
	adds r0, r0, r2\n\
	ldrh r2, [r0]\n\
	ldr r0, [r1]\n\
	adds r0, r0, r2\n\
	mov r4, sb\n\
	subs r0, r0, r4\n\
	str r0, [r5, #4]\n\
	ldr r1, _08027B4C @ =gOverworld\n\
	str r3, [sp, #0xc]\n\
_08027B26:\n\
	ldr r2, [r5, #4]\n\
	cmp r2, #0\n\
	bne _08027B2E\n\
	b _08027DC6\n\
_08027B2E:\n\
	ldr r3, [sp, #0xc]\n\
	ldr r4, [sp, #8]\n\
	adds r0, r3, r4\n\
	lsls r0, r0, #3\n\
	adds r0, r0, r1\n\
	movs r1, #0xeb\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	str r0, [sp]\n\
	adds r0, r7, r2\n\
	str r0, [r6, #0x58]\n\
	add sb, r2\n\
	b _08027DBE\n\
	.align 2, 0\n\
_08027B4C: .4byte gOverworld\n\
_08027B50:\n\
	ldr r7, _08027BA4 @ =gOverworld\n\
	ldr r3, [sp, #8]\n\
	lsls r1, r3, #1\n\
	adds r0, r1, r3\n\
	lsls r3, r0, #3\n\
	movs r4, #0xee\n\
	lsls r4, r4, #1\n\
	adds r0, r7, r4\n\
	adds r0, r3, r0\n\
	ldr r2, [r0]\n\
	ldr r0, [r6, #0x54]\n\
	mov r8, r0\n\
	str r1, [sp, #0xc]\n\
	cmp r2, r8\n\
	blt _08027B70\n\
	b _08027C80\n\
_08027B70:\n\
	adds r1, r3, r7\n\
	mov ip, r1\n\
	movs r0, #0xec\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r0, [r0]\n\
	adds r0, r2, r0\n\
	mov r4, sl\n\
	subs r2, r0, r4\n\
	str r2, [r5]\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #1\n\
	adds r0, r7, r1\n\
	adds r0, r3, r0\n\
	ldr r1, [r0]\n\
	cmp r1, sb\n\
	bge _08027BF4\n\
	ldr r3, _08027BA8 @ =0x0000018D\n\
	adds r0, r6, r3\n\
	ldrb r7, [r0]\n\
	cmp r7, #0\n\
	beq _08027BAC\n\
	movs r4, #0\n\
	str r4, [r5, #4]\n\
	b _08027D8A\n\
	.align 2, 0\n\
_08027BA4: .4byte gOverworld\n\
_08027BA8: .4byte 0x0000018D\n\
_08027BAC:\n\
	movs r0, #0xed\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r0, [r0]\n\
	adds r0, r1, r0\n\
	mov r1, sb\n\
	subs r0, r0, r1\n\
	str r0, [r5, #4]\n\
	cmp r2, r0\n\
	bge _08027BC2\n\
	b _08027CF8\n\
_08027BC2:\n\
	ldr r1, [r6, #0x58]\n\
	cmp r1, sb\n\
	bne _08027BCA\n\
	b _08027CF8\n\
_08027BCA:\n\
	adds r1, r1, r0\n\
	mov r0, sl\n\
	bl GetGroundMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _08027BDA\n\
	b _08027CF8\n\
_08027BDA:\n\
	ldr r2, [r6, #0x58]\n\
	ldr r0, [r5, #4]\n\
	adds r2, r2, r0\n\
	adds r0, r6, #0\n\
	mov r1, sl\n\
	bl IsInHazard\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _08027BF2\n\
	b _08027CF8\n\
_08027BF2:\n\
	b _08027D88\n\
_08027BF4:\n\
	movs r0, #0xed\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r0, [r0]\n\
	subs r0, r1, r0\n\
	mov r3, sb\n\
	subs r1, r0, r3\n\
	subs r0, r1, #1\n\
	str r0, [r5, #4]\n\
	cmn r2, r0\n\
	bge _08027C36\n\
	mov r4, r8\n\
	adds r0, r4, r2\n\
	ldr r1, [r6, #0x58]\n\
	bl GetGroundMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _08027C30\n\
	ldr r1, [r6, #0x54]\n\
	ldr r0, [r5]\n\
	adds r1, r1, r0\n\
	ldr r2, [r6, #0x58]\n\
	adds r0, r6, #0\n\
	bl IsInHazard\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _08027C70\n\
_08027C30:\n\
	movs r7, #0\n\
	str r7, [r5]\n\
	b _08027D8A\n\
_08027C36:\n\
	ldr r2, [r6, #0x58]\n\
	ldr r3, _08027C74 @ =0xFFFFF600\n\
	adds r0, r2, r3\n\
	cmp r0, sb\n\
	bgt _08027C6E\n\
	ldr r4, _08027C78 @ =0xFFFFE1FF\n\
	adds r1, r1, r4\n\
	adds r1, r2, r1\n\
	mov r0, sl\n\
	bl GetGroundMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _08027C6E\n\
	ldr r0, [r5, #4]\n\
	ldr r7, _08027C7C @ =0xFFFFE200\n\
	adds r0, r0, r7\n\
	ldr r2, [r6, #0x58]\n\
	adds r2, r2, r0\n\
	adds r0, r6, #0\n\
	mov r1, sl\n\
	bl IsInHazard\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _08027C6E\n\
	b _08027D88\n\
_08027C6E:\n\
	movs r0, #0\n\
_08027C70:\n\
	str r0, [r5, #4]\n\
	b _08027D8A\n\
	.align 2, 0\n\
_08027C74: .4byte 0xFFFFF600\n\
_08027C78: .4byte 0xFFFFE1FF\n\
_08027C7C: .4byte 0xFFFFE200\n\
_08027C80:\n\
	adds r1, r3, r7\n\
	mov ip, r1\n\
	movs r0, #0xec\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r0, [r0]\n\
	subs r0, r2, r0\n\
	mov r2, sl\n\
	subs r0, r0, r2\n\
	subs r4, r0, #1\n\
	str r4, [r5]\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #1\n\
	adds r0, r7, r1\n\
	adds r0, r3, r0\n\
	ldr r1, [r0]\n\
	cmp r1, sb\n\
	bge _08027CFC\n\
	ldr r2, _08027CB4 @ =0x0000018D\n\
	adds r0, r6, r2\n\
	ldrb r7, [r0]\n\
	cmp r7, #0\n\
	beq _08027CB8\n\
	movs r3, #0\n\
	str r3, [r5, #4]\n\
	b _08027D8A\n\
	.align 2, 0\n\
_08027CB4: .4byte 0x0000018D\n\
_08027CB8:\n\
	movs r0, #0xed\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r0, [r0]\n\
	adds r0, r1, r0\n\
	mov r1, sb\n\
	subs r2, r0, r1\n\
	str r2, [r5, #4]\n\
	rsbs r0, r4, #0\n\
	cmp r0, r2\n\
	blt _08027CF8\n\
	ldr r1, [r6, #0x58]\n\
	cmp r1, sb\n\
	beq _08027CF8\n\
	adds r1, r1, r2\n\
	mov r0, sl\n\
	bl GetGroundMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _08027CF8\n\
	ldr r2, [r6, #0x58]\n\
	ldr r0, [r5, #4]\n\
	adds r2, r2, r0\n\
	adds r0, r6, #0\n\
	mov r1, sl\n\
	bl IsInHazard\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _08027D88\n\
_08027CF8:\n\
	str r7, [r5, #4]\n\
	b _08027D8A\n\
_08027CFC:\n\
	movs r0, #0xed\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r0, [r0]\n\
	subs r0, r1, r0\n\
	mov r2, sb\n\
	subs r3, r0, r2\n\
	subs r1, r3, #1\n\
	str r1, [r5, #4]\n\
	rsbs r0, r4, #0\n\
	cmn r0, r1\n\
	bge _08027D40\n\
	mov r3, r8\n\
	adds r0, r3, r4\n\
	ldr r1, [r6, #0x58]\n\
	bl GetGroundMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _08027D3A\n\
	ldr r1, [r6, #0x54]\n\
	ldr r0, [r5]\n\
	adds r1, r1, r0\n\
	ldr r2, [r6, #0x58]\n\
	adds r0, r6, #0\n\
	bl IsInHazard\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _08027C70\n\
_08027D3A:\n\
	movs r4, #0\n\
	str r4, [r5]\n\
	b _08027D8A\n\
_08027D40:\n\
	ldr r2, [r6, #0x58]\n\
	ldr r7, _08027D7C @ =0xFFFFF600\n\
	adds r0, r2, r7\n\
	cmp r0, sb\n\
	bgt _08027D76\n\
	ldr r0, _08027D80 @ =0xFFFFE1FF\n\
	adds r1, r3, r0\n\
	adds r1, r2, r1\n\
	mov r0, sl\n\
	bl GetGroundMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _08027D76\n\
	ldr r0, [r5, #4]\n\
	ldr r1, _08027D84 @ =0xFFFFE200\n\
	adds r0, r0, r1\n\
	ldr r2, [r6, #0x58]\n\
	adds r2, r2, r0\n\
	adds r0, r6, #0\n\
	mov r1, sl\n\
	bl IsInHazard\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _08027D88\n\
_08027D76:\n\
	movs r2, #0\n\
	str r2, [r5, #4]\n\
	b _08027D8A\n\
	.align 2, 0\n\
_08027D7C: .4byte 0xFFFFF600\n\
_08027D80: .4byte 0xFFFFE1FF\n\
_08027D84: .4byte 0xFFFFE200\n\
_08027D88:\n\
	str r0, [r5]\n\
_08027D8A:\n\
	ldr r1, [r5]\n\
	cmp r1, #0\n\
	bne _08027DA0\n\
	ldr r1, [r5, #4]\n\
	cmp r1, #0\n\
	beq _08027DC6\n\
	ldr r0, [r6, #0x58]\n\
	adds r0, r0, r1\n\
	str r0, [r6, #0x58]\n\
	add sb, r1\n\
	b _08027DA8\n\
_08027DA0:\n\
	ldr r0, [r6, #0x54]\n\
	adds r0, r0, r1\n\
	str r0, [r6, #0x54]\n\
	add sl, r1\n\
_08027DA8:\n\
	ldr r3, [sp, #0xc]\n\
	ldr r4, [sp, #8]\n\
	adds r0, r3, r4\n\
	lsls r0, r0, #3\n\
	ldr r7, _08027DF4 @ =gOverworld\n\
	adds r0, r0, r7\n\
	movs r1, #0xeb\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	str r0, [sp]\n\
_08027DBE:\n\
	ldr r2, _08027DF8 @ =0x0000018F\n\
	adds r1, r6, r2\n\
_08027DC2:\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
_08027DC6:\n\
	ldr r0, [sp, #4]\n\
	adds r0, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	str r0, [sp, #4]\n\
	movs r3, #0xc6\n\
	lsls r3, r3, #1\n\
	adds r0, r6, r3\n\
	ldr r4, [sp, #4]\n\
	ldrb r0, [r0]\n\
	cmp r4, r0\n\
	bhs _08027DE0\n\
	b _080279B4\n\
_08027DE0:\n\
	ldr r0, [sp]\n\
	add sp, #0x18\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_08027DF4: .4byte gOverworld\n\
_08027DF8: .4byte 0x0000018F\n\
 .syntax divided\n");
};

// ------------------------------------------------------------------------------------------------------------------------------------

// Hazardによる横方向への押し出し処理っぽい
WIP static metatile_attr_t _pushoutHazardX1(struct Zero *z, s32 x, s32 y, struct Coord *c) {
#if MODERN
  u8 i;
  metatile_attr_t attr = 0;
  c->x = c->y = 0;
  for (i = 0; i < z->hazardCount; i++) {
    struct Hazard *hz = HAZARD(z->hazard[i]);
    const u32 w = (u32)((u16)hz->w);
    const u32 h = (u32)((u16)hz->h);
    if (((u32)(x - (hz->start).x) + w < (w << 1)) && ((u32)(y - (hz->start).y) + h < (h << 1))) {
      appendHazardID(z, hz->id);
      if ((hz->start).x < (z->s).coord.x) {
        c->x = ((hz->start).x + w) - x;
      } else {
        c->x = ((hz->start).x - w) - x - 1;
      }
      if (c->x != 0) {
        attr = hz->attr;
        (z->s).coord.x += c->x;
        x += c->x;
        z->pushedOut = TRUE;
      }
    }
  }
  return attr;
#else
  INCCODE("asm/wip/_pushoutHazardX1.inc");
#endif
}

// Hazardによる縦方向への押し出し処理っぽい
WIP metatile_attr_t _pushoutHazardY(struct Zero *z, s32 x, s32 y, struct Coord *c) {
#if MODERN
  u8 i;
  metatile_attr_t attr = 0;
  c->x = c->y = 0;
  for (i = 0; i < z->hazardCount; i++) {
    const u8 n = z->hazard[i];
    struct Hazard *b = HAZARD(n);
    const u32 w = (u32)((u16)b->w);

    if (((u32)(x - (b->start).x) + w) < (w << 1)) {
      const u32 h = (u32)((u16)b->h);

      if (((u32)(y - (b->start).y) + h) < (h << 1)) {
        appendHazardID(z, b->id);
        if ((b->start).y < y) {
          if (y == (z->s).coord.y) {
            c->y = (b->start).y - h - y - 1;
          } else {
            c->y = ((b->start).y + h) - y;
          }
        } else {
          c->y = (b->start).y - h - y - 1;
        }

        if (c->y != 0) {
          attr = b->attr;
          (z->s).coord.y += c->y;
          y += c->y;
          z->pushedOut = TRUE;
        }
      }
    }
  }
  return attr;
#else
  INCCODE("asm/wip/_pushoutHazardY.inc");
#endif
}

NAKED static s32 hazard_0802802c(struct Zero *z, s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	adds r6, r0, #0\n\
	mov sb, r1\n\
	str r2, [sp]\n\
	movs r7, #0\n\
	movs r0, #0\n\
	mov r8, r0\n\
	movs r1, #0xc6\n\
	lsls r1, r1, #1\n\
	adds r0, r6, r1\n\
	ldrb r0, [r0]\n\
	cmp r7, r0\n\
	bhs _08028102\n\
	ldr r2, _080280C0 @ =gOverworld\n\
	mov sl, r2\n\
_08028054:\n\
	movs r1, #0xae\n\
	lsls r1, r1, #1\n\
	adds r0, r6, r1\n\
	add r0, r8\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r2, r0, #3\n\
	movs r0, #0xee\n\
	lsls r0, r0, #1\n\
	add r0, sl\n\
	adds r5, r2, r0\n\
	ldr r1, [r5]\n\
	mov r0, sb\n\
	subs r1, r0, r1\n\
	mov r0, sl\n\
	adds r3, r2, r0\n\
	movs r0, #0xec\n\
	lsls r0, r0, #1\n\
	adds r4, r3, r0\n\
	ldrh r0, [r4]\n\
	adds r1, r1, r0\n\
	lsls r0, r0, #1\n\
	cmp r1, r0\n\
	bhs _080280EC\n\
	ldr r1, _080280C4 @ =0x020023E0\n\
	adds r0, r2, r1\n\
	ldr r1, [r0]\n\
	ldr r2, [sp]\n\
	subs r1, r2, r1\n\
	movs r2, #0xed\n\
	lsls r2, r2, #1\n\
	adds r0, r3, r2\n\
	ldrh r0, [r0]\n\
	adds r1, r1, r0\n\
	lsls r0, r0, #1\n\
	cmp r1, r0\n\
	bhs _080280EC\n\
	movs r1, #0xea\n\
	lsls r1, r1, #1\n\
	adds r0, r3, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r6, #0\n\
	bl appendHazardID\n\
	ldr r1, [r5]\n\
	ldr r0, [r6, #0x54]\n\
	cmp r1, r0\n\
	bge _080280C8\n\
	ldrh r0, [r4]\n\
	adds r0, r1, r0\n\
	mov r2, sb\n\
	subs r0, r0, r2\n\
	b _080280D2\n\
	.align 2, 0\n\
_080280C0: .4byte gOverworld\n\
_080280C4: .4byte 0x020023E0\n\
_080280C8:\n\
	ldrh r0, [r4]\n\
	subs r0, r1, r0\n\
	mov r1, sb\n\
	subs r0, r0, r1\n\
	subs r0, #1\n\
_080280D2:\n\
	cmp r7, #0\n\
	beq _080280EA\n\
	adds r2, r0, #0\n\
	cmp r0, #0\n\
	bge _080280DE\n\
	rsbs r2, r0, #0\n\
_080280DE:\n\
	adds r1, r7, #0\n\
	cmp r7, #0\n\
	bge _080280E6\n\
	rsbs r1, r7, #0\n\
_080280E6:\n\
	cmp r2, r1\n\
	bge _080280EC\n\
_080280EA:\n\
	adds r7, r0, #0\n\
_080280EC:\n\
	mov r0, r8\n\
	adds r0, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov r8, r0\n\
	movs r2, #0xc6\n\
	lsls r2, r2, #1\n\
	adds r0, r6, r2\n\
	ldrb r0, [r0]\n\
	cmp r8, r0\n\
	blo _08028054\n\
_08028102:\n\
	adds r0, r7, #0\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED static s32 hazard_08028114(struct Zero *z, s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	adds r7, r0, #0\n\
	str r1, [sp]\n\
	adds r6, r2, #0\n\
	movs r0, #0\n\
	mov r8, r0\n\
	mov sb, r0\n\
	movs r1, #0xc6\n\
	lsls r1, r1, #1\n\
	adds r0, r7, r1\n\
	ldrb r0, [r0]\n\
	cmp r8, r0\n\
	bhs _080281D6\n\
	ldr r4, _080281A4 @ =gOverworld\n\
	mov sl, r4\n\
_0802813C:\n\
	movs r1, #0xae\n\
	lsls r1, r1, #1\n\
	adds r0, r7, r1\n\
	add r0, sb\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r2, r0, #3\n\
	movs r0, #0xee\n\
	lsls r0, r0, #1\n\
	add r0, sl\n\
	adds r0, r2, r0\n\
	ldr r1, [r0]\n\
	ldr r4, [sp]\n\
	subs r1, r4, r1\n\
	mov r0, sl\n\
	adds r3, r2, r0\n\
	movs r4, #0xec\n\
	lsls r4, r4, #1\n\
	adds r0, r3, r4\n\
	ldrh r0, [r0]\n\
	adds r1, r1, r0\n\
	lsls r0, r0, #1\n\
	cmp r1, r0\n\
	bhs _080281C0\n\
	ldr r0, _080281A8 @ =0x020023E0\n\
	adds r5, r2, r0\n\
	ldr r1, [r5]\n\
	subs r1, r6, r1\n\
	movs r0, #0xed\n\
	lsls r0, r0, #1\n\
	adds r4, r3, r0\n\
	ldrh r0, [r4]\n\
	adds r1, r1, r0\n\
	lsls r0, r0, #1\n\
	cmp r1, r0\n\
	bhs _080281C0\n\
	movs r1, #0xea\n\
	lsls r1, r1, #1\n\
	adds r0, r3, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r7, #0\n\
	bl appendHazardID\n\
	ldr r1, [r5]\n\
	cmp r1, r6\n\
	bge _080281AC\n\
	ldrh r0, [r4]\n\
	adds r0, r1, r0\n\
	subs r0, r0, r6\n\
	b _080281B4\n\
	.align 2, 0\n\
_080281A4: .4byte gOverworld\n\
_080281A8: .4byte 0x020023E0\n\
_080281AC:\n\
	ldrh r0, [r4]\n\
	subs r0, r1, r0\n\
	subs r0, r0, r6\n\
	subs r0, #1\n\
_080281B4:\n\
	mov r4, r8\n\
	cmp r4, #0\n\
	beq _080281BE\n\
	cmp r0, r8\n\
	ble _080281C0\n\
_080281BE:\n\
	mov r8, r0\n\
_080281C0:\n\
	mov r0, sb\n\
	adds r0, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov sb, r0\n\
	movs r1, #0xc6\n\
	lsls r1, r1, #1\n\
	adds r0, r7, r1\n\
	ldrb r0, [r0]\n\
	cmp sb, r0\n\
	blo _0802813C\n\
_080281D6:\n\
	mov r0, r8\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

WIP static metatile_attr_t AppendHazardID(struct Zero *z, s32 x, s32 y) {
#if MODERN
  u8 i;
  for (i = 0; i < z->hazardCount; i++) {
    u8 n = z->hazard[i];
    struct Hazard *h = HAZARD(n);
    if ((u32)(x - (h->start.x)) + h->w < (u32)(h->w << 1)) {
      if ((u32)(y - (h->start.y)) + h->h < (u32)(h->h << 1)) {
        appendHazardID(z, h->id);
        return h->attr;
      }
    }
  }
  return 0;
#else
  INCCODE("asm/wip/AppendHazardID.inc");
#endif
}

NAKED static u16 AppendHazardID_2(struct Zero *z, s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	mov ip, r0\n\
	mov sb, r1\n\
	adds r6, r2, #0\n\
	movs r2, #0\n\
	movs r0, #0xc6\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrb r0, [r0]\n\
	cmp r2, r0\n\
	bhs _0802832A\n\
	ldr r5, _08028314 @ =gOverworld\n\
	movs r0, #0xf4\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r5\n\
	mov r8, r0\n\
_080282B6:\n\
	movs r0, #0xae\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	adds r0, r0, r2\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r3, r0, #3\n\
	movs r1, #0xf2\n\
	lsls r1, r1, #1\n\
	adds r0, r5, r1\n\
	adds r0, r3, r0\n\
	ldr r1, [r0]\n\
	mov r7, sb\n\
	subs r1, r7, r1\n\
	adds r4, r3, r5\n\
	movs r7, #0xec\n\
	lsls r7, r7, #1\n\
	adds r0, r4, r7\n\
	ldrh r0, [r0]\n\
	adds r1, r1, r0\n\
	lsls r0, r0, #1\n\
	cmp r1, r0\n\
	bhs _08028318\n\
	mov r1, r8\n\
	adds r0, r3, r1\n\
	ldr r1, [r0]\n\
	subs r1, r6, r1\n\
	movs r3, #0xed\n\
	lsls r3, r3, #1\n\
	adds r0, r4, r3\n\
	ldrh r0, [r0]\n\
	adds r1, r1, r0\n\
	lsls r0, r0, #1\n\
	cmp r1, r0\n\
	bhs _08028318\n\
	subs r7, #4\n\
	adds r0, r4, r7\n\
	ldrh r1, [r0]\n\
	mov r0, ip\n\
	bl appendHazardID\n\
	movs r1, #0xeb\n\
	lsls r1, r1, #1\n\
	adds r0, r4, r1\n\
	ldrh r0, [r0]\n\
	b _0802832C\n\
	.align 2, 0\n\
_08028314: .4byte gOverworld\n\
_08028318:\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
	movs r0, #0xc6\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrb r0, [r0]\n\
	cmp r2, r0\n\
	blo _080282B6\n\
_0802832A:\n\
	movs r0, #0\n\
_0802832C:\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED static bool16 hazard_08028338(struct Zero *z, s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	adds r7, r0, #0\n\
	mov sl, r1\n\
	mov sb, r2\n\
	movs r5, #0\n\
	movs r1, #0xc6\n\
	lsls r1, r1, #1\n\
	adds r0, r7, r1\n\
	ldrb r0, [r0]\n\
	cmp r5, r0\n\
	bhs _080283DA\n\
	ldr r6, _080283BC @ =gOverworld\n\
	mov r8, r0\n\
_0802835A:\n\
	movs r1, #0xae\n\
	lsls r1, r1, #1\n\
	adds r0, r7, r1\n\
	adds r0, r0, r5\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r3, r0, #3\n\
	ldr r1, _080283C0 @ =0x020023DC\n\
	adds r0, r3, r1\n\
	ldr r4, [r0]\n\
	mov r0, sl\n\
	subs r1, r0, r4\n\
	adds r0, r3, r6\n\
	mov ip, r0\n\
	movs r0, #0xec\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r0, [r0]\n\
	adds r1, r1, r0\n\
	lsls r0, r0, #1\n\
	cmp r1, r0\n\
	bhs _080283D0\n\
	ldr r1, _080283C4 @ =0x020023E0\n\
	adds r0, r3, r1\n\
	ldr r2, [r0]\n\
	mov r0, sb\n\
	subs r1, r0, r2\n\
	movs r0, #0xed\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r0, [r0]\n\
	adds r1, r1, r0\n\
	lsls r0, r0, #1\n\
	cmp r1, r0\n\
	bhs _080283D0\n\
	ldr r1, _080283C8 @ =gOverworld+484\n\
	adds r0, r3, r1\n\
	ldr r0, [r0]\n\
	cmp r4, r0\n\
	bne _080283D0\n\
	ldr r1, _080283CC @ =gOverworld+488\n\
	adds r0, r3, r1\n\
	ldr r0, [r0]\n\
	cmp r2, r0\n\
	beq _080283D0\n\
	movs r0, #1\n\
	b _080283DC\n\
	.align 2, 0\n\
_080283BC: .4byte gOverworld\n\
_080283C0: .4byte 0x020023DC\n\
_080283C4: .4byte 0x020023E0\n\
_080283C8: .4byte gOverworld+484\n\
_080283CC: .4byte gOverworld+488\n\
_080283D0:\n\
	adds r0, r5, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	cmp r5, r8\n\
	blo _0802835A\n\
_080283DA:\n\
	movs r0, #0\n\
_080283DC:\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

// ゼロが Hazard の中にいる(めり込んでいる)場合は、そのMetatileAttr、そうでないなら0を返す
WIP static metatile_attr_t IsInHazard(struct Zero *z, s32 x, s32 y) {
#if MODERN
  u8 i;
  for (i = 0; i < z->hazardCount; i++) {
    struct Hazard *b = HAZARD(z->hazard[i]);
    const u32 w = (u32)((u16)b->w);
    if ((u32)(x - (b->start).x) + w < (w << 1)) {
      const u32 h = (u32)((u16)b->h);
      if ((u32)(y - (b->start).y) + h < (h << 1)) {
        return b->attr;
      }
    }
  }
  return 0;
#else
  INCCODE("asm/wip/IsInHazard.inc");
#endif
}

// Hazardに張り付いている判定か(地上の場合も)
WIP static bool8 IsAgainstHazard(struct Zero *z, s32 x, s32 y) {
#if MODERN
  u8 i;
  for (i = 0; i < z->hazardCount; i++) {
    struct Hazard *b = HAZARD(z->hazard[i]);
    const u32 w = (u32)((u16)b->w);
    if ((u32)(x - (b->start).x) + w < (w << 1)) {
      const u32 h = (u32)((u16)b->h);
      if ((u32)(y - b->start.y) + h < (h << 1)) {
        if ((b->attr & 0x880F) == 1) {
          if ((z->s).flags & X_FLIP) {
            if ((s32)((b->start).x + (w >> 1) - x) < PIXEL(1)) {
              return TRUE;
            }
          } else {
            if ((s32)((b->start).x - (w >> 1) - x) > -PIXEL(1)) {
              return TRUE;
            }
          }
        }
      }
    }
  }
  return FALSE;
#else
  INCCODE("asm/wip/IsAgainstHazard.inc");
#endif
}

NAKED static u8 hazard_0802855c(struct Zero *z, s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	adds r7, r0, #0\n\
	adds r6, r1, #0\n\
	mov sl, r2\n\
	movs r5, #0\n\
	movs r1, #0xc6\n\
	lsls r1, r1, #1\n\
	adds r0, r7, r1\n\
	ldrb r0, [r0]\n\
	cmp r5, r0\n\
	bhs _0802861A\n\
	ldr r1, _080285EC @ =gOverworld\n\
	mov r8, r1\n\
	mov sb, r0\n\
_08028580:\n\
	movs r1, #0xae\n\
	lsls r1, r1, #1\n\
	adds r0, r7, r1\n\
	adds r0, r0, r5\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r3, r0, #3\n\
	ldr r1, _080285F0 @ =0x020023DC\n\
	adds r0, r3, r1\n\
	ldr r4, [r0]\n\
	subs r1, r6, r4\n\
	adds r0, r3, #0\n\
	add r0, r8\n\
	mov ip, r0\n\
	movs r0, #0xec\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r2, [r0]\n\
	adds r1, r1, r2\n\
	lsls r0, r2, #1\n\
	cmp r1, r0\n\
	bhs _08028610\n\
	ldr r1, _080285F4 @ =0x020023E0\n\
	adds r0, r3, r1\n\
	ldr r1, [r0]\n\
	mov r0, sl\n\
	subs r1, r0, r1\n\
	movs r0, #0xed\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r0, [r0]\n\
	adds r1, r1, r0\n\
	lsls r0, r0, #1\n\
	cmp r1, r0\n\
	bhs _08028610\n\
	movs r0, #0xeb\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r0, [r0]\n\
	ldr r1, _080285F8 @ =0x0000880F\n\
	ands r0, r1\n\
	cmp r0, #1\n\
	bne _08028610\n\
	lsrs r0, r2, #1\n\
	adds r0, r4, r0\n\
	subs r1, r0, r6\n\
	cmp r6, r4\n\
	ble _08028600\n\
	ldr r0, _080285FC @ =0x000003FF\n\
	cmp r1, r0\n\
	bgt _08028610\n\
	movs r0, #1\n\
	b _0802861C\n\
	.align 2, 0\n\
_080285EC: .4byte gOverworld\n\
_080285F0: .4byte 0x020023DC\n\
_080285F4: .4byte 0x020023E0\n\
_080285F8: .4byte 0x0000880F\n\
_080285FC: .4byte 0x000003FF\n\
_08028600:\n\
	ldr r0, _0802860C @ =0xFFFFFC00\n\
	cmp r1, r0\n\
	ble _08028610\n\
	movs r0, #2\n\
	b _0802861C\n\
	.align 2, 0\n\
_0802860C: .4byte 0xFFFFFC00\n\
_08028610:\n\
	adds r0, r5, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	cmp r5, sb\n\
	blo _08028580\n\
_0802861A:\n\
	movs r0, #0\n\
_0802861C:\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

static void appendHazardID(struct Zero *z, u16 id) {
  s32 i;
  for (i = 0; i < ARRAY_COUNT(z->hazardIDs); i++) {
    if (z->hazardIDs[i] == 0xFFFF) {
      z->hazardIDs[i] = id;
      return;
    }
    if (z->hazardIDs[i] == id) {
      break;
    }
  }
}

NAKED u8 RecoilFromFloor(struct Zero *z, const struct Rect *range) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x20\n\
	adds r5, r0, #0\n\
	mov r8, r1\n\
	movs r0, #0xc7\n\
	lsls r0, r0, #1\n\
	adds r1, r5, r0\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	ldr r2, _080286AC @ =0x0000011F\n\
	adds r1, r5, r2\n\
	strb r0, [r1]\n\
	ldr r2, [r5, #0x54]\n\
	str r2, [sp]\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080286B0\n\
	mov r3, r8\n\
	movs r4, #0\n\
	ldrsh r0, [r3, r4]\n\
	subs r0, r2, r0\n\
	ldrh r1, [r3, #4]\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x11\n\
	adds r0, r0, r1\n\
	adds r0, #1\n\
	str r0, [sp, #4]\n\
	movs r6, #0\n\
	ldrsh r0, [r3, r6]\n\
	subs r0, r2, r0\n\
	b _080286CC\n\
	.align 2, 0\n\
_080286AC: .4byte 0x0000011F\n\
_080286B0:\n\
	mov r1, r8\n\
	movs r3, #0\n\
	ldrsh r0, [r1, r3]\n\
	adds r0, r2, r0\n\
	ldrh r1, [r1, #4]\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x11\n\
	adds r0, r0, r1\n\
	adds r0, #1\n\
	str r0, [sp, #4]\n\
	mov r4, r8\n\
	movs r6, #0\n\
	ldrsh r0, [r4, r6]\n\
	adds r0, r2, r0\n\
_080286CC:\n\
	subs r0, r0, r1\n\
	subs r0, #1\n\
	str r0, [sp, #8]\n\
	add r2, sp, #0xc\n\
	mov r1, r8\n\
	movs r3, #2\n\
	ldrsh r0, [r1, r3]\n\
	ldr r3, [r5, #0x58]\n\
	adds r0, r3, r0\n\
	ldrh r1, [r1, #6]\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x11\n\
	adds r0, r0, r1\n\
	str r0, [sp, #0xc]\n\
	mov r4, r8\n\
	movs r6, #2\n\
	ldrsh r0, [r4, r6]\n\
	adds r0, r3, r0\n\
	str r0, [r2, #4]\n\
	movs r6, #2\n\
	ldrsh r0, [r4, r6]\n\
	adds r0, r3, r0\n\
	subs r0, r0, r1\n\
	str r0, [r2, #8]\n\
	movs r1, #0xc8\n\
	lsls r1, r1, #1\n\
	adds r0, r5, r1\n\
	ldr r1, [r0]\n\
	mov sl, r2\n\
	adds r4, r0, #0\n\
	cmp r1, #0\n\
	beq _08028740\n\
	ldr r0, [r5, #0x54]\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x54]\n\
	ldr r0, [r4]\n\
	cmp r0, #0\n\
	ble _08028728\n\
	ldr r0, [sp, #4]\n\
	adds r1, r3, #0\n\
	bl PushoutToLeft2\n\
	adds r1, r0, #0\n\
	cmp r1, #0\n\
	bge _0802873C\n\
	b _08028736\n\
_08028728:\n\
	ldr r0, [sp, #8]\n\
	adds r1, r3, #0\n\
	bl PushoutToRight2\n\
	adds r1, r0, #0\n\
	cmp r1, #0\n\
	ble _0802873C\n\
_08028736:\n\
	ldr r0, [r5, #0x54]\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x54]\n\
_0802873C:\n\
	movs r0, #0\n\
	str r0, [r4]\n\
_08028740:\n\
	adds r0, r5, #0\n\
	adds r0, #0xb4\n\
	ldr r1, [r0, #0x58]\n\
	str r0, [sp, #0x18]\n\
	cmp r1, #0\n\
	bgt _08028770\n\
	movs r2, #0x86\n\
	lsls r2, r2, #2\n\
	adds r0, r5, r2\n\
	ldr r0, [r0]\n\
	movs r2, #0x10\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _08028770\n\
	ldrb r1, [r5, #0xa]\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08028804\n\
	ldr r3, _0802877C @ =0x00000147\n\
	adds r0, r5, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _08028804\n\
_08028770:\n\
	movs r4, #0\n\
	mov sb, r4\n\
	movs r3, #0\n\
	movs r6, #0\n\
	b _080287BE\n\
	.align 2, 0\n\
_0802877C: .4byte 0x00000147\n\
_08028780:\n\
	ldr r0, [sp, #4]\n\
	ldr r1, [r4]\n\
	str r3, [sp, #0x1c]\n\
	bl GetGroundMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	movs r0, #0x10\n\
	ands r0, r2\n\
	ldr r3, [sp, #0x1c]\n\
	cmp r0, #0\n\
	beq _080287A0\n\
	adds r0, r3, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
	b _080287B8\n\
_080287A0:\n\
	adds r0, r2, #0\n\
	ands r0, r7\n\
	cmp r0, #0\n\
	bne _080287B4\n\
	mov r0, sb\n\
	adds r0, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov sb, r0\n\
	b _080287B8\n\
_080287B4:\n\
	cmp r0, #1\n\
	beq _080287E0\n\
_080287B8:\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
_080287BE:\n\
	cmp r6, #2\n\
	bhi _080287E0\n\
	ldr r1, [sp, #4]\n\
	lsls r0, r6, #2\n\
	mov r2, sl\n\
	adds r4, r2, r0\n\
	ldr r2, [r4]\n\
	adds r0, r5, #0\n\
	str r3, [sp, #0x1c]\n\
	bl IsInHazard\n\
	movs r7, #0xf\n\
	adds r1, r7, #0\n\
	ands r1, r0\n\
	ldr r3, [sp, #0x1c]\n\
	cmp r1, #1\n\
	bne _08028780\n\
_080287E0:\n\
	cmp r3, #0\n\
	beq _08028804\n\
	mov r4, sb\n\
	adds r0, r3, r4\n\
	cmp r0, #3\n\
	bne _08028804\n\
	adds r0, r5, #0\n\
	adds r0, #0x94\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _080287F8\n\
	b _08028A8A\n\
_080287F8:\n\
	ldr r6, _0802883C @ =0x00000149\n\
	adds r0, r5, r6\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _08028804\n\
	b _08028A8A\n\
_08028804:\n\
	ldr r1, [sp, #0x18]\n\
	ldr r0, [r1, #0x58]\n\
	cmp r0, #0\n\
	blt _08028830\n\
	movs r2, #0x86\n\
	lsls r2, r2, #2\n\
	adds r0, r5, r2\n\
	ldr r0, [r0]\n\
	movs r1, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08028830\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080288C8\n\
	ldr r3, _08028840 @ =0x00000147\n\
	adds r0, r5, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _080288C8\n\
_08028830:\n\
	movs r4, #0\n\
	mov sb, r4\n\
	movs r3, #0\n\
	movs r6, #0\n\
	b _08028882\n\
	.align 2, 0\n\
_0802883C: .4byte 0x00000149\n\
_08028840: .4byte 0x00000147\n\
_08028844:\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [r4]\n\
	str r3, [sp, #0x1c]\n\
	bl GetGroundMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	movs r0, #0x10\n\
	ands r0, r2\n\
	ldr r3, [sp, #0x1c]\n\
	cmp r0, #0\n\
	beq _08028864\n\
	adds r0, r3, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
	b _0802887C\n\
_08028864:\n\
	adds r0, r2, #0\n\
	ands r0, r7\n\
	cmp r0, #0\n\
	bne _08028878\n\
	mov r0, sb\n\
	adds r0, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov sb, r0\n\
	b _0802887C\n\
_08028878:\n\
	cmp r0, #1\n\
	beq _080288A4\n\
_0802887C:\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
_08028882:\n\
	cmp r6, #2\n\
	bhi _080288A4\n\
	ldr r1, [sp, #8]\n\
	lsls r0, r6, #2\n\
	mov r2, sl\n\
	adds r4, r2, r0\n\
	ldr r2, [r4]\n\
	adds r0, r5, #0\n\
	str r3, [sp, #0x1c]\n\
	bl IsInHazard\n\
	movs r7, #0xf\n\
	adds r1, r7, #0\n\
	ands r1, r0\n\
	ldr r3, [sp, #0x1c]\n\
	cmp r1, #1\n\
	bne _08028844\n\
_080288A4:\n\
	cmp r3, #0\n\
	beq _080288C8\n\
	mov r4, sb\n\
	adds r0, r3, r4\n\
	cmp r0, #3\n\
	bne _080288C8\n\
	adds r0, r5, #0\n\
	adds r0, #0x94\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _080288BC\n\
	b _08028A8A\n\
_080288BC:\n\
	ldr r6, _08028914 @ =0x00000149\n\
	adds r0, r5, r6\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _080288C8\n\
	b _08028A8A\n\
_080288C8:\n\
	mov r1, r8\n\
	movs r2, #2\n\
	ldrsh r0, [r1, r2]\n\
	ldr r1, [r5, #0x58]\n\
	adds r0, r1, r0\n\
	mov r3, r8\n\
	ldrh r2, [r3, #6]\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x11\n\
	adds r0, r0, r2\n\
	adds r0, #1\n\
	str r0, [sp, #0xc]\n\
	movs r4, #2\n\
	ldrsh r0, [r3, r4]\n\
	adds r1, r1, r0\n\
	subs r1, r1, r2\n\
	subs r1, #1\n\
	mov r6, sl\n\
	str r1, [r6, #8]\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08028918\n\
	movs r0, #0\n\
	ldrsh r1, [r3, r0]\n\
	ldr r2, [r5, #0x54]\n\
	subs r1, r2, r1\n\
	ldrh r0, [r3, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x11\n\
	adds r1, r1, r0\n\
	str r1, [sp, #4]\n\
	movs r4, #0\n\
	ldrsh r1, [r3, r4]\n\
	subs r2, r2, r1\n\
	subs r2, r2, r0\n\
	b _08028934\n\
	.align 2, 0\n\
_08028914: .4byte 0x00000149\n\
_08028918:\n\
	mov r6, r8\n\
	movs r0, #0\n\
	ldrsh r1, [r6, r0]\n\
	ldr r2, [r5, #0x54]\n\
	adds r1, r2, r1\n\
	ldrh r0, [r6, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x11\n\
	subs r1, r1, r0\n\
	str r1, [sp, #4]\n\
	movs r3, #0\n\
	ldrsh r1, [r6, r3]\n\
	adds r2, r2, r1\n\
	adds r2, r2, r0\n\
_08028934:\n\
	str r2, [sp, #8]\n\
	movs r4, #0\n\
	mov sb, r4\n\
	movs r3, #0\n\
	movs r6, #0\n\
_0802893E:\n\
	lsls r0, r6, #2\n\
	add r0, sp\n\
	ldr r0, [r0]\n\
	mov r2, sl\n\
	ldr r1, [r2, #8]\n\
	str r3, [sp, #0x1c]\n\
	bl GetGroundMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	movs r0, #0x10\n\
	ands r0, r2\n\
	ldr r3, [sp, #0x1c]\n\
	cmp r0, #0\n\
	beq _08028962\n\
	adds r0, r3, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
_08028962:\n\
	movs r0, #0xf\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	bne _08028974\n\
	mov r0, sb\n\
	adds r0, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov sb, r0\n\
_08028974:\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	cmp r6, #2\n\
	bls _0802893E\n\
	cmp r3, #0\n\
	beq _0802899E\n\
	mov r4, sb\n\
	adds r0, r3, r4\n\
	cmp r0, #3\n\
	bne _0802899E\n\
	adds r0, r5, #0\n\
	adds r0, #0x94\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _08028A8A\n\
	ldr r6, _080289F4 @ =0x00000149\n\
	adds r0, r5, r6\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _08028A8A\n\
_0802899E:\n\
	ldr r1, _080289F8 @ =0x0000018D\n\
	adds r0, r5, r1\n\
	ldrb r1, [r0]\n\
	mov r8, r0\n\
	cmp r1, #0\n\
	beq _080289FC\n\
	ldr r0, [sp, #4]\n\
	mov r6, sl\n\
	ldr r1, [sp, #0xc]\n\
	bl PushoutToUp2\n\
	movs r4, #1\n\
	rsbs r4, r4, #0\n\
	cmp r0, r4\n\
	beq _080289C8\n\
	ldr r0, [sp, #8]\n\
	ldr r1, [sp, #0xc]\n\
	bl PushoutToUp2\n\
	cmp r0, r4\n\
	bne _080289FC\n\
_080289C8:\n\
	ldr r1, [sp, #4]\n\
	ldr r2, [r6, #8]\n\
	adds r2, #1\n\
	adds r0, r5, #0\n\
	bl hazard_08028338\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080289EE\n\
	ldr r1, [sp, #8]\n\
	mov r3, sl\n\
	ldr r2, [r3, #8]\n\
	adds r2, #1\n\
	adds r0, r5, #0\n\
	bl hazard_08028338\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080289FC\n\
_080289EE:\n\
	movs r0, #2\n\
	b _08028BBC\n\
	.align 2, 0\n\
_080289F4: .4byte 0x00000149\n\
_080289F8: .4byte 0x0000018D\n\
_080289FC:\n\
	movs r4, #0\n\
	movs r3, #0\n\
	mov sb, r3\n\
	movs r7, #0\n\
	movs r6, #0\n\
_08028A06:\n\
	lsls r0, r6, #2\n\
	add r0, sp\n\
	ldr r0, [r0]\n\
	ldr r1, [sp, #0xc]\n\
	str r3, [sp, #0x1c]\n\
	bl GetGroundMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	movs r0, #0x80\n\
	lsls r0, r0, #3\n\
	adds r1, r0, #0\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	ldr r3, [sp, #0x1c]\n\
	cmp r0, #0\n\
	beq _08028A2E\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
_08028A2E:\n\
	movs r0, #0x10\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _08028A3C\n\
	adds r0, r3, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
_08028A3C:\n\
	movs r0, #0xf\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _08028A4E\n\
	mov r0, sb\n\
	adds r0, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov sb, r0\n\
_08028A4E:\n\
	movs r1, #0x80\n\
	lsls r1, r1, #5\n\
	adds r0, r1, #0\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	beq _08028A60\n\
	adds r0, r7, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r7, r0, #0x18\n\
_08028A60:\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	cmp r6, #2\n\
	bls _08028A06\n\
	cmp r3, #0\n\
	beq _08028A94\n\
	mov r2, sb\n\
	adds r0, r3, r2\n\
	cmp r0, #3\n\
	bne _08028A94\n\
	adds r0, r5, #0\n\
	adds r0, #0x94\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _08028A8A\n\
	ldr r3, _08028A90 @ =0x00000149\n\
	adds r0, r5, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _08028A94\n\
_08028A8A:\n\
	movs r0, #1\n\
	b _08028BBC\n\
	.align 2, 0\n\
_08028A90: .4byte 0x00000149\n\
_08028A94:\n\
	cmp r4, #0\n\
	beq _08028AD6\n\
	mov r6, sb\n\
	adds r0, r4, r6\n\
	cmp r0, #3\n\
	bne _08028AD6\n\
	ldr r0, [sp, #0x18]\n\
	ldrb r4, [r0, #0x10]\n\
	cmp r4, #1\n\
	bne _08028AC6\n\
	ldr r0, [sp]\n\
	ldr r1, [sp, #0xc]\n\
	subs r1, #1\n\
	bl GetGroundMetatileAttr\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _08028AD6\n\
	movs r1, #0xc7\n\
	lsls r1, r1, #1\n\
	adds r0, r5, r1\n\
	strb r4, [r0]\n\
	b _08028AD6\n\
_08028AC6:\n\
	ldr r0, [r5, #0x58]\n\
	adds r0, #0x20\n\
	str r0, [r5, #0x58]\n\
	movs r2, #0xc7\n\
	lsls r2, r2, #1\n\
	adds r1, r5, r2\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
_08028AD6:\n\
	ldr r3, [sp, #0x18]\n\
	ldrb r0, [r3, #0x11]\n\
	cmp r0, #5\n\
	beq _08028B44\n\
	cmp r0, #7\n\
	beq _08028B44\n\
	cmp r7, #0\n\
	beq _08028AF8\n\
	mov r4, sb\n\
	adds r0, r7, r4\n\
	cmp r0, #3\n\
	bne _08028AF8\n\
	ldr r6, _08028AF4 @ =0x0000011F\n\
	adds r1, r5, r6\n\
	b _08028B08\n\
	.align 2, 0\n\
_08028AF4: .4byte 0x0000011F\n\
_08028AF8:\n\
	movs r1, #0x8c\n\
	lsls r1, r1, #2\n\
	adds r0, r5, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _08028B0C\n\
	ldr r2, _08028BA4 @ =0x0000011F\n\
	adds r1, r5, r2\n\
_08028B08:\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
_08028B0C:\n\
	ldr r1, [sp, #4]\n\
	ldr r2, [sp, #0xc]\n\
	adds r0, r5, #0\n\
	bl IsInHazard\n\
	movs r4, #0x80\n\
	lsls r4, r4, #5\n\
	adds r1, r4, #0\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _08028B2A\n\
	ldr r3, _08028BA4 @ =0x0000011F\n\
	adds r1, r5, r3\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
_08028B2A:\n\
	ldr r1, [sp, #8]\n\
	ldr r2, [sp, #0xc]\n\
	adds r0, r5, #0\n\
	bl IsInHazard\n\
	adds r1, r4, #0\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _08028B44\n\
	ldr r4, _08028BA4 @ =0x0000011F\n\
	adds r1, r5, r4\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
_08028B44:\n\
	mov r6, r8\n\
	ldrb r0, [r6]\n\
	cmp r0, #0\n\
	beq _08028BBA\n\
	movs r6, #0\n\
	ldr r7, _08028BA8 @ =0xFFFFF000\n\
_08028B50:\n\
	lsls r0, r6, #2\n\
	mov r1, sp\n\
	adds r4, r1, r0\n\
	ldr r0, [r4]\n\
	ldr r1, [sp, #0xc]\n\
	bl GetMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #0x17\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _08028BB0\n\
	ldr r0, [r4]\n\
	ands r0, r7\n\
	movs r2, #0x80\n\
	lsls r2, r2, #4\n\
	adds r0, r0, r2\n\
	ldr r1, [sp, #0xc]\n\
	ands r1, r7\n\
	ldr r3, _08028BAC @ =0x00000FFF\n\
	adds r1, r1, r3\n\
	bl FUN_0800a4bc\n\
	ldr r1, [r5, #0x54]\n\
	adds r0, r1, r0\n\
	str r0, [r5, #0x54]\n\
	cmp r6, #0\n\
	bne _08028BBA\n\
	ldr r1, [r5, #0x58]\n\
	bl PushoutToUp2\n\
	cmp r0, #0\n\
	bge _08028BBA\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	bl PushoutToUp2\n\
	ldr r1, [r5, #0x58]\n\
	adds r1, r1, r0\n\
	str r1, [r5, #0x58]\n\
	b _08028BBA\n\
	.align 2, 0\n\
_08028BA4: .4byte 0x0000011F\n\
_08028BA8: .4byte 0xFFFFF000\n\
_08028BAC: .4byte 0x00000FFF\n\
_08028BB0:\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	cmp r6, #2\n\
	bls _08028B50\n\
_08028BBA:\n\
	movs r0, #0\n\
_08028BBC:\n\
	add sp, #0x20\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED bool8 unused_08028bcc(struct Zero *z, const struct Rect *range) { INCCODE("asm/unused/unused_08028bcc.inc"); }

NAKED bool8 TryGroundDash(struct Zero *z, const struct Rect *range, bool8 r2) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	adds r7, r0, #0\n\
	mov r8, r1\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08028DD8\n\
	mov r1, r8\n\
	movs r2, #0\n\
	ldrsh r0, [r1, r2]\n\
	ldr r2, [r7, #0x54]\n\
	subs r0, r2, r0\n\
	ldrh r1, [r1, #4]\n\
	b _08028DE4\n\
_08028DD8:\n\
	mov r3, r8\n\
	movs r1, #0\n\
	ldrsh r0, [r3, r1]\n\
	ldr r2, [r7, #0x54]\n\
	adds r0, r2, r0\n\
	ldrh r1, [r3, #4]\n\
_08028DE4:\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x11\n\
	adds r4, r0, r1\n\
	subs r5, r0, r1\n\
	adds r0, r2, #0\n\
	ldr r1, [r7, #0x58]\n\
	adds r1, #1\n\
	bl GetGroundMetatileAttr\n\
	movs r1, #0xf\n\
	ands r1, r0\n\
	cmp r1, #1\n\
	bne _08028E12\n\
	mov r2, r8\n\
	movs r3, #2\n\
	ldrsh r0, [r2, r3]\n\
	ldr r1, [r7, #0x58]\n\
	adds r1, r1, r0\n\
	ldrh r0, [r2, #6]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x11\n\
	adds r6, r1, r0\n\
	b _08028E1C\n\
_08028E12:\n\
	mov r0, r8\n\
	movs r2, #2\n\
	ldrsh r1, [r0, r2]\n\
	ldr r0, [r7, #0x58]\n\
	adds r6, r0, r1\n\
_08028E1C:\n\
	adds r0, r4, #0\n\
	adds r1, r6, #0\n\
	bl PushoutToLeft2\n\
	cmp r0, #0\n\
	blt _08028E36\n\
	adds r0, r7, #0\n\
	adds r1, r4, #0\n\
	adds r2, r6, #0\n\
	bl hazard_0802802c\n\
	cmp r0, #0\n\
	bge _08028E68\n\
_08028E36:\n\
	adds r0, r0, r5\n\
	mov sb, r0\n\
	adds r1, r6, #0\n\
	bl GetGroundMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	movs r0, #0x84\n\
	lsls r0, r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08028E68\n\
	movs r0, #0xf\n\
	ands r1, r0\n\
	cmp r1, #1\n\
	bne _08028E58\n\
	b _08028F58\n\
_08028E58:\n\
	adds r0, r7, #0\n\
	mov r1, sb\n\
	adds r2, r6, #0\n\
	bl IsInHazard\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _08028F58\n\
_08028E68:\n\
	adds r0, r5, #0\n\
	adds r1, r6, #0\n\
	bl PushoutToRight2\n\
	cmp r0, #0\n\
	bgt _08028E82\n\
	adds r0, r7, #0\n\
	adds r1, r5, #0\n\
	adds r2, r6, #0\n\
	bl hazard_0802802c\n\
	cmp r0, #0\n\
	ble _08028EB2\n\
_08028E82:\n\
	adds r0, r0, r4\n\
	mov sb, r0\n\
	adds r1, r6, #0\n\
	bl GetGroundMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	movs r0, #0x84\n\
	lsls r0, r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08028EB2\n\
	movs r0, #0xf\n\
	ands r1, r0\n\
	cmp r1, #1\n\
	beq _08028F58\n\
	adds r0, r7, #0\n\
	mov r1, sb\n\
	adds r2, r6, #0\n\
	bl IsInHazard\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _08028F58\n\
_08028EB2:\n\
	mov r3, r8\n\
	movs r1, #2\n\
	ldrsh r0, [r3, r1]\n\
	ldr r1, [r7, #0x58]\n\
	adds r1, r1, r0\n\
	ldrh r0, [r3, #6]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x11\n\
	subs r6, r1, r0\n\
	adds r0, r4, #0\n\
	adds r1, r6, #0\n\
	bl PushoutToLeft2\n\
	cmp r0, #0\n\
	blt _08028EDE\n\
	adds r0, r7, #0\n\
	adds r1, r4, #0\n\
	adds r2, r6, #0\n\
	bl hazard_0802802c\n\
	cmp r0, #0\n\
	bge _08028F0E\n\
_08028EDE:\n\
	adds r0, r0, r5\n\
	mov r8, r0\n\
	adds r1, r6, #0\n\
	bl GetGroundMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	movs r0, #0x84\n\
	lsls r0, r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08028F0E\n\
	movs r0, #0xf\n\
	ands r1, r0\n\
	cmp r1, #1\n\
	beq _08028F58\n\
	adds r0, r7, #0\n\
	mov r1, r8\n\
	adds r2, r6, #0\n\
	bl IsInHazard\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _08028F58\n\
_08028F0E:\n\
	adds r0, r5, #0\n\
	adds r1, r6, #0\n\
	bl PushoutToRight2\n\
	cmp r0, #0\n\
	bgt _08028F28\n\
	adds r0, r7, #0\n\
	adds r1, r5, #0\n\
	adds r2, r6, #0\n\
	bl hazard_0802802c\n\
	cmp r0, #0\n\
	ble _08028F5C\n\
_08028F28:\n\
	adds r4, r0, r4\n\
	adds r0, r4, #0\n\
	adds r1, r6, #0\n\
	bl GetGroundMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	movs r0, #0x84\n\
	lsls r0, r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08028F5C\n\
	movs r0, #0xf\n\
	ands r1, r0\n\
	cmp r1, #1\n\
	beq _08028F58\n\
	adds r0, r7, #0\n\
	adds r1, r4, #0\n\
	adds r2, r6, #0\n\
	bl IsInHazard\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _08028F5C\n\
_08028F58:\n\
	movs r0, #0\n\
	b _08028F5E\n\
_08028F5C:\n\
	movs r0, #1\n\
_08028F5E:\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
   .syntax divided\n");
}

// clang-format off
const ALIGNED(4) struct PlttData gZeroPalettes[9][SLOT_4BPP] = {
  { PLTTDATA(0xCA49), PLTTDATA(0x2128), PLTTDATA(0xB4A0), PLTTDATA(0xC588), PLTTDATA(0x6AD2), PLTTDATA(0xFFFF), PLTTDATA(0x8A1B), PLTTDATA(0x82FF), PLTTDATA(0x43BF), PLTTDATA(0x575F), PLTTDATA(0xA053), PLTTDATA(0xAC9A), PLTTDATA(0xB15F), PLTTDATA(0x469F), PLTTDATA(0x95AB), PLTTDATA(0x9EB1) },
  { PLTTDATA(0xCA49), PLTTDATA(0x2128), PLTTDATA(0xB4A0), PLTTDATA(0xC588), PLTTDATA(0x6AD2), PLTTDATA(0xFFFF), PLTTDATA(0x8A1B), PLTTDATA(0x82FF), PLTTDATA(0x43BF), PLTTDATA(0x575F), PLTTDATA(0xA9A0), PLTTDATA(0xAE26), PLTTDATA(0xAB8E), PLTTDATA(0xCBF8), PLTTDATA(0x95AB), PLTTDATA(0x9EB1) },
  { PLTTDATA(0xCA49), PLTTDATA(0x2128), PLTTDATA(0xB4A0), PLTTDATA(0xC588), PLTTDATA(0x6AD2), PLTTDATA(0xFFFF), PLTTDATA(0x8A1B), PLTTDATA(0x82FF), PLTTDATA(0x43BF), PLTTDATA(0x575F), PLTTDATA(0xB189), PLTTDATA(0xC62C), PLTTDATA(0x6713), PLTTDATA(0xFFFC), PLTTDATA(0x95AB), PLTTDATA(0x9EB1) },
  { PLTTDATA(0xCA49), PLTTDATA(0x2128), PLTTDATA(0xB4A0), PLTTDATA(0xC588), PLTTDATA(0x6AD2), PLTTDATA(0xFFFF), PLTTDATA(0x8A1B), PLTTDATA(0x82FF), PLTTDATA(0x43BF), PLTTDATA(0x575F), PLTTDATA(0x914D), PLTTDATA(0x0612), PLTTDATA(0x033F), PLTTDATA(0xD3DF), PLTTDATA(0x95AB), PLTTDATA(0x9EB1) },
  { PLTTDATA(0xCA49), PLTTDATA(0x2128), PLTTDATA(0xB4A0), PLTTDATA(0xC588), PLTTDATA(0x6AD2), PLTTDATA(0xFFFF), PLTTDATA(0x8A1B), PLTTDATA(0x82FF), PLTTDATA(0x43BF), PLTTDATA(0x575F), PLTTDATA(0x1534), PLTTDATA(0x097F), PLTTDATA(0x0A9F), PLTTDATA(0xA37F), PLTTDATA(0x95AB), PLTTDATA(0x9EB1) },
  { PLTTDATA(0xCA49), PLTTDATA(0x2128), PLTTDATA(0xB4A0), PLTTDATA(0xC588), PLTTDATA(0x6AD2), PLTTDATA(0xFFFF), PLTTDATA(0x8A1B), PLTTDATA(0x82FF), PLTTDATA(0x43BF), PLTTDATA(0x575F), PLTTDATA(0xBD09), PLTTDATA(0x5200), PLTTDATA(0x6EC7), PLTTDATA(0xFBEF), PLTTDATA(0x95AB), PLTTDATA(0x9EB1) },
  { PLTTDATA(0xCA49), PLTTDATA(0x2128), PLTTDATA(0xB4A0), PLTTDATA(0xC508), PLTTDATA(0xEA52), PLTTDATA(0xFFFF), PLTTDATA(0x8A1B), PLTTDATA(0x82FF), PLTTDATA(0x43BF), PLTTDATA(0x575F), PLTTDATA(0x2D25), PLTTDATA(0x3987), PLTTDATA(0x39EB), PLTTDATA(0x5AF0), PLTTDATA(0x95AB), PLTTDATA(0x9EB1) },
  { PLTTDATA(0xCA49), PLTTDATA(0x2128), PLTTDATA(0x246A), PLTTDATA(0x38EF), PLTTDATA(0xDE3B), PLTTDATA(0xFFFF), PLTTDATA(0x8A1B), PLTTDATA(0x82FF), PLTTDATA(0x43BF), PLTTDATA(0x575F), PLTTDATA(0x1C4E), PLTTDATA(0xA053), PLTTDATA(0xAC9A), PLTTDATA(0xB15F), PLTTDATA(0x95AB), PLTTDATA(0x9EB1) },
  { PLTTDATA(0xCA49), PLTTDATA(0x2128), PLTTDATA(0x30C0), PLTTDATA(0x3988), PLTTDATA(0xDEF2), PLTTDATA(0xF7FD), PLTTDATA(0xAA74), PLTTDATA(0xB73B), PLTTDATA(0x5BDF), PLTTDATA(0xE35F), PLTTDATA(0x106D), PLTTDATA(0xA092), PLTTDATA(0xA4B9), PLTTDATA(0x24BF), PLTTDATA(0xB985), PLTTDATA(0xBE0A) },
};
// clang-format on

// clang-format off
const ALIGNED(4) struct PlttData gZeroShadowPalettes[9][SLOT_4BPP] = {
  { PLTTDATA(0xCA49), PLTTDATA(0x180C), PLTTDATA(0x1C91), PLTTDATA(0x2116), PLTTDATA(0x299B), PLTTDATA(0x565E), PLTTDATA(0x1813), PLTTDATA(0x20D7), PLTTDATA(0x299B), PLTTDATA(0xCE1E), PLTTDATA(0x180E), PLTTDATA(0x1C92), PLTTDATA(0x2117), PLTTDATA(0x299B), PLTTDATA(0x1C92), PLTTDATA(0x2117) },
  { PLTTDATA(0xCA49), PLTTDATA(0xA167), PLTTDATA(0x8D87), PLTTDATA(0x95EB), PLTTDATA(0x1E6F), PLTTDATA(0xAF34), PLTTDATA(0x8D87), PLTTDATA(0x122B), PLTTDATA(0x12B0), PLTTDATA(0x92F1), PLTTDATA(0x8D87), PLTTDATA(0x920B), PLTTDATA(0x12AE), PLTTDATA(0x92F1), PLTTDATA(0x920B), PLTTDATA(0x12AE) },
  { PLTTDATA(0xCA49), PLTTDATA(0x2128), PLTTDATA(0xB189), PLTTDATA(0xC62C), PLTTDATA(0xD690), PLTTDATA(0x6713), PLTTDATA(0xB1C9), PLTTDATA(0x422C), PLTTDATA(0x4AAE), PLTTDATA(0x56F0), PLTTDATA(0xB189), PLTTDATA(0x39EB), PLTTDATA(0x4A6D), PLTTDATA(0x56F0), PLTTDATA(0xC62C), PLTTDATA(0xD690) },
  { PLTTDATA(0xCA49), PLTTDATA(0x04ED), PLTTDATA(0x814E), PLTTDATA(0x05B2), PLTTDATA(0x0A77), PLTTDATA(0xA2FB), PLTTDATA(0x99AE), PLTTDATA(0x1233), PLTTDATA(0x9656), PLTTDATA(0xA2B8), PLTTDATA(0x998E), PLTTDATA(0x15B2), PLTTDATA(0x1257), PLTTDATA(0x8AFB), PLTTDATA(0x9573), PLTTDATA(0x0DD7) },
  { PLTTDATA(0xCA49), PLTTDATA(0x1D2E), PLTTDATA(0x1534), PLTTDATA(0x11B9), PLTTDATA(0x8E3E), PLTTDATA(0x8ABF), PLTTDATA(0x21D9), PLTTDATA(0x961E), PLTTDATA(0x0A9F), PLTTDATA(0x22DC), PLTTDATA(0x1534), PLTTDATA(0x11B9), PLTTDATA(0x95FA), PLTTDATA(0x9A3C), PLTTDATA(0x8DDB), PLTTDATA(0x0A9F) },
  { PLTTDATA(0xCA49), PLTTDATA(0x2128), PLTTDATA(0xBCAB), PLTTDATA(0xD56B), PLTTDATA(0x6E47), PLTTDATA(0xE6CD), PLTTDATA(0xD56B), PLTTDATA(0x6E47), PLTTDATA(0xEA8A), PLTTDATA(0xE6CD), PLTTDATA(0xBCAB), PLTTDATA(0xD56B), PLTTDATA(0x61E9), PLTTDATA(0x6E47), PLTTDATA(0xD56B), PLTTDATA(0x61E9) },
  { PLTTDATA(0xCA49), PLTTDATA(0xB128), PLTTDATA(0xB4A0), PLTTDATA(0x3949), PLTTDATA(0xCA0D), PLTTDATA(0xDAD1), PLTTDATA(0x3949), PLTTDATA(0xCA0D), PLTTDATA(0x528F), PLTTDATA(0xD28F), PLTTDATA(0x2D25), PLTTDATA(0x3949), PLTTDATA(0xBD8A), PLTTDATA(0x45EB), PLTTDATA(0x3949), PLTTDATA(0xBD8A) },
  { PLTTDATA(0xCA49), PLTTDATA(0x192C), PLTTDATA(0x1C4E), PLTTDATA(0xA053), PLTTDATA(0xA8D6), PLTTDATA(0xB99B), PLTTDATA(0xA053), PLTTDATA(0xA8D6), PLTTDATA(0xB159), PLTTDATA(0x399B), PLTTDATA(0x1C4E), PLTTDATA(0xA053), PLTTDATA(0xA876), PLTTDATA(0xAC9A), PLTTDATA(0xA053), PLTTDATA(0xA876) },
  { PLTTDATA(0xCA49), PLTTDATA(0xB128), PLTTDATA(0xB4A0), PLTTDATA(0x3949), PLTTDATA(0xCA0D), PLTTDATA(0xDAD1), PLTTDATA(0x3949), PLTTDATA(0xCA0D), PLTTDATA(0x528F), PLTTDATA(0xD28F), PLTTDATA(0x2D25), PLTTDATA(0x3949), PLTTDATA(0xBD8A), PLTTDATA(0x45EB), PLTTDATA(0x3949), PLTTDATA(0xBD8A) },
};
// clang-format on

// clang-format off
const ALIGNED(4) struct PlttData gZeroShadowDashPalette[9][SLOT_4BPP] = {
  { PLTTDATA(0xCA49), PLTTDATA(0x180C), PLTTDATA(0x20B0), PLTTDATA(0x2958), PLTTDATA(0xBA3F), PLTTDATA(0xF39F), PLTTDATA(0xA8B8), PLTTDATA(0x3E1F), PLTTDATA(0x52BF), PLTTDATA(0xDF7F), PLTTDATA(0x9850), PLTTDATA(0x80F8), PLTTDATA(0x297C), PLTTDATA(0xAA3E), PLTTDATA(0x1C92), PLTTDATA(0x2117) },
  { PLTTDATA(0xCA49), PLTTDATA(0xA167), PLTTDATA(0x0DE7), PLTTDATA(0x964B), PLTTDATA(0x2332), PLTTDATA(0x47B7), PLTTDATA(0x8D87), PLTTDATA(0x928B), PLTTDATA(0x0F0E), PLTTDATA(0x3F96), PLTTDATA(0x8D87), PLTTDATA(0x920B), PLTTDATA(0x12CE), PLTTDATA(0x1371), PLTTDATA(0x920B), PLTTDATA(0x12AE) },
  { PLTTDATA(0xCA49), PLTTDATA(0x2128), PLTTDATA(0x2D46), PLTTDATA(0xC62C), PLTTDATA(0x56F1), PLTTDATA(0xF3D8), PLTTDATA(0xB1C9), PLTTDATA(0x422C), PLTTDATA(0x4AAE), PLTTDATA(0x63DE), PLTTDATA(0xB189), PLTTDATA(0x39EB), PLTTDATA(0xCE8E), PLTTDATA(0x5F51), PLTTDATA(0xC62C), PLTTDATA(0xD690) },
  { PLTTDATA(0xCA49), PLTTDATA(0x04ED), PLTTDATA(0x814E), PLTTDATA(0x8614), PLTTDATA(0xA31F), PLTTDATA(0x6FFE), PLTTDATA(0x0170), PLTTDATA(0x8614), PLTTDATA(0xA31F), PLTTDATA(0x5FBF), PLTTDATA(0x998E), PLTTDATA(0x9A13), PLTTDATA(0x9E99), PLTTDATA(0xA31F), PLTTDATA(0x9573), PLTTDATA(0x0DD7) },
  { PLTTDATA(0xCA49), PLTTDATA(0x1D2E), PLTTDATA(0x1532), PLTTDATA(0x161A), PLTTDATA(0x92BF), PLTTDATA(0xC35F), PLTTDATA(0x1534), PLTTDATA(0x11DA), PLTTDATA(0x0E7F), PLTTDATA(0x57BF), PLTTDATA(0x1534), PLTTDATA(0x11B9), PLTTDATA(0x963C), PLTTDATA(0x9ABF), PLTTDATA(0x8DDB), PLTTDATA(0x0A9F) },
  { PLTTDATA(0xCA49), PLTTDATA(0x2128), PLTTDATA(0xBCAB), PLTTDATA(0xD56B), PLTTDATA(0xF267), PLTTDATA(0xFFB8), PLTTDATA(0xD56B), PLTTDATA(0x6E47), PLTTDATA(0xF267), PLTTDATA(0xEF7C), PLTTDATA(0xBCAB), PLTTDATA(0xD56B), PLTTDATA(0xE609), PLTTDATA(0x76A7), PLTTDATA(0xD56B), PLTTDATA(0x61E9) },
  { PLTTDATA(0xCA49), PLTTDATA(0xB128), PLTTDATA(0xB4A0), PLTTDATA(0x4166), PLTTDATA(0x5A4D), PLTTDATA(0xF397), PLTTDATA(0x3949), PLTTDATA(0xCA0D), PLTTDATA(0x528F), PLTTDATA(0xE79C), PLTTDATA(0x2D25), PLTTDATA(0x3589), PLTTDATA(0x49EA), PLTTDATA(0xD66B), PLTTDATA(0x3949), PLTTDATA(0xBD8A) },
  { PLTTDATA(0xCA49), PLTTDATA(0x192C), PLTTDATA(0x1C4E), PLTTDATA(0x2CB2), PLTTDATA(0xB916), PLTTDATA(0xDEBF), PLTTDATA(0xA095), PLTTDATA(0x2D5C), PLTTDATA(0x45FF), PLTTDATA(0xE75F), PLTTDATA(0x1C4E), PLTTDATA(0xA053), PLTTDATA(0xAC9B), PLTTDATA(0xB8DF), PLTTDATA(0xA053), PLTTDATA(0xA876) },
  { PLTTDATA(0xCA49), PLTTDATA(0xB128), PLTTDATA(0xB4A0), PLTTDATA(0x4166), PLTTDATA(0x5A4D), PLTTDATA(0xF397), PLTTDATA(0x3949), PLTTDATA(0xCA0D), PLTTDATA(0x528F), PLTTDATA(0xE79C), PLTTDATA(0x2D25), PLTTDATA(0x3589), PLTTDATA(0x49EA), PLTTDATA(0xD66B), PLTTDATA(0x3949), PLTTDATA(0xBD8A) },
};
// clang-format on
