#include "cyberelf.h"

#include "entity.h"
#include "global.h"
#include "overworld.h"

extern const motion_t ElfActions[3];

// clang-format off
const ElfRoutine *const gElfFnTable[13] = {
  [0] =  &gElf0Routine,
  [1] =  &gElf1Routine,
  [2] =  &gNurseBRoutine,
  [3] =  &gElf3Routine,
  [4] =  &gNurseERoutine,
  [5] =  &gElf5Routine,
  [6] =  &gElf6Routine,
  [7] =  &gElf7Routine,
  [8] =  &gFollowerElfRoutine,
  [9] =  &gSeaOtterElfRoutine,
  [10] = &gElf10Routine,
  [11] = &gElf11Routine,
  [12] = &gBirdElfRoutine,
};
// clang-format on

void InitElfHeader(struct EntityHeader *h, struct Elf *p, s16 len) {
  s16 i;

  InitEntityHeader(h, ENTITY_ELF, &p->s, sizeof(struct Elf), len);
  for (i = 0; i < len; i++) {
    p[i].s.uniqueID = gEntityIDGenerator + i;
  }
  gEntityIDGenerator += len;
  gElfHeaderPtr = h;
}

void DeleteElf(struct Elf *p) {
  (p->s).flags &= ~DISPLAY;
  SET_ELF_ROUTINE(p, ENTITY_EXIT);
}

#if MODERN == 0
NAKED static struct Elf *unused_080e14d4(u8 r0, struct Entity *e) { INCCODE("asm/unused/unused_080e14d4.inc"); }
#endif

static struct Enemy *getNearestEnemy(struct Coord *c) {
  struct Enemy *p = (struct Enemy *)GetNearestEntity(gZakoHeaderPtr, c);
  if (p == NULL) {
    return NULL;
  }
  return p;
}

#if MODERN == 0
static struct Boss *getNearestBoss(struct Coord *c) {
  struct Boss *p = (struct Boss *)GetNearestEntity(gBossHeaderPtr, c);
  if (p == NULL) {
    return NULL;
  }
  return p;
}
#endif

void close_menu_080e1540(ElfFunc fn) {
  struct Entity *p;
  struct EntityHeader *h = gElfHeaderPtr;
  ignoreEntityFn(h);

  h->last = h->last->prev;
  p = h->last;
  while (p != (struct Entity *)&h->next) {
    fn((struct Elf *)p);
    p = h->last->prev;
    h->last = p;
  }
}

NAKED bool8 FUN_080e1578(struct Coord *c1, struct Coord *c2, struct Coord *c3, u8 *param_4, s16 param_5) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r5, r0, #0\n\
	adds r7, r3, #0\n\
	ldr r4, [sp, #0x14]\n\
	lsls r4, r4, #0x10\n\
	ldr r3, [r1]\n\
	ldr r0, [r5]\n\
	adds r3, r3, r0\n\
	ldr r1, [r1, #4]\n\
	ldr r0, [r5, #4]\n\
	adds r1, r1, r0\n\
	ldr r0, [r2]\n\
	subs r3, r0, r3\n\
	ldr r0, [r2, #4]\n\
	subs r2, r0, r1\n\
	lsrs r6, r4, #0x10\n\
	asrs r4, r4, #0x10\n\
	adds r0, r3, r4\n\
	lsls r1, r4, #1\n\
	cmp r0, r1\n\
	bhi _080E15BE\n\
	adds r0, r2, r4\n\
	cmp r0, r1\n\
	bhi _080E15BE\n\
	adds r0, r3, #0\n\
	muls r0, r3, r0\n\
	adds r1, r2, #0\n\
	muls r1, r2, r1\n\
	adds r0, r0, r1\n\
	adds r1, r4, #0\n\
	muls r1, r4, r1\n\
	cmp r0, r1\n\
	bgt _080E15BE\n\
	movs r0, #1\n\
	b _080E15FE\n\
_080E15BE:\n\
	adds r0, r3, #0\n\
	adds r1, r2, #0\n\
	bl CalcAngle\n\
	strb r0, [r7]\n\
	lsls r2, r6, #0x10\n\
	asrs r2, r2, #0x10\n\
	ldr r3, _080E1604 @ =gSineTable\n\
	adds r0, #0x40\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r3\n\
	movs r1, #0\n\
	ldrsh r0, [r0, r1]\n\
	adds r1, r2, #0\n\
	muls r1, r0, r1\n\
	asrs r1, r1, #8\n\
	ldr r0, [r5]\n\
	adds r0, r0, r1\n\
	str r0, [r5]\n\
	ldrb r0, [r7]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r3\n\
	movs r1, #0\n\
	ldrsh r0, [r0, r1]\n\
	adds r1, r2, #0\n\
	muls r1, r0, r1\n\
	asrs r1, r1, #8\n\
	ldr r0, [r5, #4]\n\
	adds r0, r0, r1\n\
	str r0, [r5, #4]\n\
	movs r0, #0\n\
_080E15FE:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_080E1604: .4byte gSineTable\n\
 .syntax divided\n");
}

NAKED struct Enemy *FUN_080e1608(struct Coord *c) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #8\n\
	adds r7, r0, #0\n\
	movs r6, #0\n\
_080E1610:\n\
	cmp r6, #0\n\
	bne _080E161E\n\
	ldr r0, [r7]\n\
	ldr r1, [r7, #4]\n\
	str r0, [sp]\n\
	str r1, [sp, #4]\n\
	b _080E1632\n\
_080E161E:\n\
	cmp r6, #1\n\
	bne _080E162A\n\
	ldr r0, [r7]\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #7\n\
	b _080E162E\n\
_080E162A:\n\
	ldr r0, [r7]\n\
	ldr r1, _080E1674 @ =0xFFFF8800\n\
_080E162E:\n\
	adds r0, r0, r1\n\
	str r0, [sp]\n\
_080E1632:\n\
	mov r0, sp\n\
	bl getNearestEnemy\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #9]\n\
	cmp r0, #0x43\n\
	bhi _080E16A8\n\
	ldr r5, _080E1678 @ =u8_ARRAY_08371ab8\n\
	adds r0, r0, r5\n\
	ldrb r0, [r0]\n\
	cmp r0, #0xff\n\
	beq _080E1690\n\
	adds r1, r4, #0\n\
	adds r1, #0x54\n\
	ldr r0, _080E167C @ =gStageRun+232\n\
	bl CalcFromCamera\n\
	cmp r0, #0\n\
	bne _080E1690\n\
	ldrb r1, [r4, #9]\n\
	adds r0, r1, r5\n\
	ldrb r2, [r0]\n\
	cmp r2, #0xfd\n\
	bhi _080E16AA\n\
	adds r0, r1, #0\n\
	cmp r0, #7\n\
	bne _080E1680\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #2\n\
	beq _080E1690\n\
	cmp r0, #4\n\
	bls _080E16AA\n\
	b _080E1690\n\
	.align 2, 0\n\
_080E1674: .4byte 0xFFFF8800\n\
_080E1678: .4byte u8_ARRAY_08371ab8\n\
_080E167C: .4byte gStageRun+232\n\
_080E1680:\n\
	cmp r0, #0x16\n\
	bne _080E1694\n\
	ldrb r0, [r4, #0x10]\n\
	subs r0, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bhi _080E16AA\n\
_080E1690:\n\
	movs r4, #0\n\
	b _080E16AE\n\
_080E1694:\n\
	cmp r0, #0x39\n\
	bne _080E16A0\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #1\n\
	bls _080E16AA\n\
	b _080E1690\n\
_080E16A0:\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r2, r0\n\
	beq _080E16AA\n\
	b _080E1690\n\
_080E16A8:\n\
	movs r4, #0\n\
_080E16AA:\n\
	cmp r4, #0\n\
	bne _080E16B8\n\
_080E16AE:\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	cmp r6, #2\n\
	bls _080E1610\n\
_080E16B8:\n\
	adds r0, r4, #0\n\
	add sp, #8\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED void FUN_080e16c4(struct Coord *c, struct CollidableEntity *p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov ip, r0\n\
	adds r6, r1, #0\n\
	ldr r0, [r6, #0x74]\n\
	ldr r2, [r0, #0x10]\n\
	ldr r3, [r0, #0x14]\n\
	ldrb r0, [r6, #9]\n\
	cmp r0, #0xe\n\
	bne _080E1704\n\
	ldrb r0, [r6, #0x10]\n\
	cmp r0, #0\n\
	blt _080E1716\n\
	cmp r0, #1\n\
	bgt _080E16E6\n\
	movs r2, #0xf8\n\
	lsls r2, r2, #0x18\n\
	b _080E1716\n\
_080E16E6:\n\
	cmp r0, #3\n\
	bgt _080E1716\n\
	ldr r0, _080E16FC @ =0xFFFF0000\n\
	ands r0, r2\n\
	movs r1, #0x80\n\
	lsls r1, r1, #4\n\
	orrs r0, r1\n\
	ldr r1, _080E1700 @ =0x0000FFFF\n\
	adds r2, r0, #0\n\
	ands r2, r1\n\
	b _080E1716\n\
	.align 2, 0\n\
_080E16FC: .4byte 0xFFFF0000\n\
_080E1700: .4byte 0x0000FFFF\n\
_080E1704:\n\
	cmp r0, #0xa\n\
	bne _080E170E\n\
	movs r2, #0xf3\n\
	lsls r2, r2, #0x18\n\
	b _080E1716\n\
_080E170E:\n\
	cmp r0, #0x31\n\
	bne _080E1716\n\
	movs r2, #0xec\n\
	lsls r2, r2, #0x18\n\
_080E1716:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	adds r7, r1, #0\n\
	cmp r0, #0\n\
	beq _080E172C\n\
	lsls r0, r2, #0x10\n\
	asrs r0, r0, #0x10\n\
	ldr r1, [r6, #0x54]\n\
	subs r4, r1, r0\n\
	b _080E1734\n\
_080E172C:\n\
	lsls r0, r2, #0x10\n\
	asrs r0, r0, #0x10\n\
	ldr r1, [r6, #0x54]\n\
	adds r4, r1, r0\n\
_080E1734:\n\
	movs r0, #0x20\n\
	ands r0, r7\n\
	cmp r0, #0\n\
	beq _080E1744\n\
	asrs r1, r2, #0x10\n\
	ldr r0, [r6, #0x58]\n\
	subs r5, r0, r1\n\
	b _080E174A\n\
_080E1744:\n\
	asrs r1, r2, #0x10\n\
	ldr r0, [r6, #0x58]\n\
	adds r5, r0, r1\n\
_080E174A:\n\
	mov r0, ip\n\
	str r4, [r0]\n\
	str r5, [r0, #4]\n\
	pop {r4, r5, r6, r7}\n\
	pop {r2}\n\
	bx r2\n\
 .syntax divided\n");
}

NAKED void CreateSateliteElf(struct Zero *z, cyberelf_t e, bool8 isSatelite2) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r3, r0, #0\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	adds r6, r1, #0\n\
	lsls r2, r2, #0x18\n\
	lsrs r4, r2, #0x18\n\
	adds r5, r4, #0\n\
	cmp r1, #0xff\n\
	beq _080E1822\n\
	cmp r1, #0x1a\n\
	bhi _080E17B4\n\
	cmp r1, #0x16\n\
	bhi _080E1778\n\
	movs r1, #0\n\
	b _080E17C0\n\
_080E1778:\n\
	cmp r1, #0x18\n\
	bhi _080E1798\n\
	ldr r0, _080E1794 @ =gUnlockedElfPtr\n\
	ldr r0, [r0]\n\
	adds r0, r0, r1\n\
	ldr r2, [r0]\n\
	lsls r2, r2, #0x1d\n\
	lsrs r2, r2, #0x1f\n\
	adds r0, r3, #0\n\
	movs r1, #0\n\
	adds r3, r4, #0\n\
	bl CreateNurseBElf\n\
	b _080E1822\n\
	.align 2, 0\n\
_080E1794: .4byte gUnlockedElfPtr\n\
_080E1798:\n\
	ldr r0, _080E17B0 @ =gUnlockedElfPtr\n\
	ldr r0, [r0]\n\
	adds r0, r0, r1\n\
	ldr r2, [r0]\n\
	lsls r2, r2, #0x1d\n\
	lsrs r2, r2, #0x1f\n\
	adds r0, r3, #0\n\
	movs r1, #0\n\
	adds r3, r4, #0\n\
	bl CreateNurseEElf\n\
	b _080E1822\n\
	.align 2, 0\n\
_080E17B0: .4byte gUnlockedElfPtr\n\
_080E17B4:\n\
	cmp r1, #0x27\n\
	bhi _080E1816\n\
	cmp r1, #0x1f\n\
	bhi _080E17CA\n\
	adds r0, r3, #0\n\
	movs r1, #1\n\
_080E17C0:\n\
	movs r2, #0\n\
	adds r3, r4, #0\n\
	bl CreateFollowerElf\n\
	b _080E1822\n\
_080E17CA:\n\
	cmp r1, #0x21\n\
	bhi _080E17DC\n\
	adds r0, r3, #0\n\
	movs r1, #0\n\
	movs r2, #0\n\
	adds r3, r4, #0\n\
	bl CreateBirdElf\n\
	b _080E1822\n\
_080E17DC:\n\
	cmp r1, #0x23\n\
	bhi _080E17EE\n\
	adds r0, r3, #0\n\
	movs r1, #0\n\
	movs r2, #0\n\
	adds r3, r4, #0\n\
	bl CreateSeaotterElf\n\
	b _080E1822\n\
_080E17EE:\n\
	cmp r6, #0x25\n\
	bhi _080E1808\n\
	ldr r0, _080E1804 @ =gUnlockedElfPtr\n\
	ldr r0, [r0]\n\
	adds r0, r0, r6\n\
	ldr r2, [r0]\n\
	lsls r2, r2, #0x1d\n\
	lsrs r2, r2, #0x1f\n\
	adds r0, r3, #0\n\
	movs r1, #0\n\
	b _080E180E\n\
	.align 2, 0\n\
_080E1804: .4byte gUnlockedElfPtr\n\
_080E1808:\n\
	adds r0, r3, #0\n\
	movs r1, #2\n\
	movs r2, #0\n\
_080E180E:\n\
	adds r3, r4, #0\n\
	bl elf_080e4bf4\n\
	b _080E1822\n\
_080E1816:\n\
	adds r0, r3, #0\n\
	movs r1, #2\n\
	movs r2, #0\n\
	adds r3, r5, #0\n\
	bl CreateFollowerElf\n\
_080E1822:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

bool8 IsAllElfUnlocked(void) {
  u8 i;
  for (i = 0; i < CYBERELF_LENGTH; i++) {
    if ((((*gUnlockedElfPtr)[i]) & ELF_AVABILITY_UNLOCKED) == 0) {
      return FALSE;
    }
  }
  return TRUE;
}

// 全部のエルフを育てきってるか(称号エルフブリーダーの条件を満たしているか)
NAKED bool8 IsElfBreeder(void) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	movs r4, #0\n\
	ldr r6, _080E1894 @ =gElfBreedInfo\n\
	ldr r0, _080E1898 @ =gUnlockedElfPtr\n\
	ldr r5, [r0]\n\
_080E1866:\n\
	lsls r0, r4, #2\n\
	adds r0, r0, r6\n\
	ldrb r2, [r0]\n\
	lsls r1, r2, #0x1d\n\
	adds r3, r5, r4\n\
	ldr r0, [r3]\n\
	lsls r0, r0, #0x1b\n\
	lsrs r1, r1, #0x1d\n\
	lsrs r0, r0, #0x1e\n\
	cmp r1, r0\n\
	bne _080E188E\n\
	lsls r0, r2, #0x1a\n\
	lsrs r0, r0, #0x1d\n\
	cmp r0, #2\n\
	bne _080E189C\n\
	ldrb r1, [r3]\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080E189C\n\
_080E188E:\n\
	movs r0, #0\n\
	b _080E18A8\n\
	.align 2, 0\n\
_080E1894: .4byte gElfBreedInfo\n\
_080E1898: .4byte gUnlockedElfPtr\n\
_080E189C:\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #0x49\n\
	bls _080E1866\n\
	movs r0, #1\n\
_080E18A8:\n\
	pop {r4, r5, r6}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

// リザルトでのエルフ減点を計算
u8 CalcElfPenalty(struct Zero *z) {
  u16 penalty = 0;

  if (((&z->unk_b4)->status).menuZeroColor == MZC_ULTIMATE) {
    penalty = ((&z->unk_b4)->status).asset.fusions;
    ((&z->unk_b4)->status).asset.fusions = 0;
  } else {
    if ((*gUnlockedElfPtr)[0] & ELF_AVABILITY_USED) penalty = 5;
    if ((*gUnlockedElfPtr)[1] & ELF_AVABILITY_USED) penalty += 2;
    if ((*gUnlockedElfPtr)[2] & ELF_AVABILITY_USED) penalty += 2;
    if ((*gUnlockedElfPtr)[3] & ELF_AVABILITY_USED) penalty += 2;
    if ((*gUnlockedElfPtr)[4] & ELF_AVABILITY_USED) penalty += 2;
    if ((*gUnlockedElfPtr)[5] & ELF_AVABILITY_USED) penalty += 2;
    if ((*gUnlockedElfPtr)[6] & ELF_AVABILITY_USED) penalty += 2;
    if ((*gUnlockedElfPtr)[27] & ELF_AVABILITY_USED) penalty += 5;
    if ((*gUnlockedElfPtr)[28] & ELF_AVABILITY_USED) penalty += 2;
    if ((*gUnlockedElfPtr)[29] & ELF_AVABILITY_USED) penalty += 2;
    if ((*gUnlockedElfPtr)[30] & ELF_AVABILITY_USED) penalty += 2;
    if ((*gUnlockedElfPtr)[31] & ELF_AVABILITY_USED) penalty += 2;
    if ((*gUnlockedElfPtr)[40] & ELF_AVABILITY_USED) penalty += 5;
    if ((*gUnlockedElfPtr)[41] & ELF_AVABILITY_USED) penalty += 1;
    if ((*gUnlockedElfPtr)[42] & ELF_AVABILITY_USED) penalty += 1;
    if ((*gUnlockedElfPtr)[43] & ELF_AVABILITY_USED) penalty += 2;
    if ((*gUnlockedElfPtr)[44] & ELF_AVABILITY_USED) penalty += 1;
    if ((*gUnlockedElfPtr)[45] & ELF_AVABILITY_USED) penalty += 2;
    if ((*gUnlockedElfPtr)[46] & ELF_AVABILITY_USED) penalty += 1;
    if ((*gUnlockedElfPtr)[47] & ELF_AVABILITY_USED) penalty += 1;
    if ((*gUnlockedElfPtr)[48] & ELF_AVABILITY_USED) penalty += 1;
    if ((*gUnlockedElfPtr)[49] & ELF_AVABILITY_USED) penalty += 1;
    if ((*gUnlockedElfPtr)[50] & ELF_AVABILITY_USED) penalty += 1;
    if ((*gUnlockedElfPtr)[51] & ELF_AVABILITY_USED) penalty += 1;
    if ((*gUnlockedElfPtr)[52] & ELF_AVABILITY_USED) penalty += 1;
    penalty += ((&z->unk_b4)->status).asset.fusions;
    ((&z->unk_b4)->status).asset.fusions = 0;
  }

  if (penalty > 115) {
    penalty = 115;
  }
  return penalty;
}

/*
  category:
    00: Nurse
    01: Animal
    02: Hacker
*/
motion_t GetElfMotion(u8 category) {
  u16 buf[4];
  u8 *flags;

  memcpy(buf, ElfActions, 6);
  flags = gSystemSavedataManager.flags;
  if ((flags[buf[category] >> 3] >> (buf[category] & 7)) & 1) {
    return ((u16)category << 8) + 0x9001;
  } else {
    return ((u16)category << 8) + 0x9000;
  }
}

// 立ち止まっていると回復するエルフのためのチェック関数
bool8 CheckPlayerStandStill(struct Zero *z) {
  if (!(z->last & 0x8000) && ((gOverworld.id & 0x7F) != STAGE_BASE)) {
    return TRUE;
  }
  return FALSE;
}

void clearUnlockedCyberElfData(u8 *p) {
  gUnlockedElfPtr = (void *)p;
  CpuFastFill16(0, p, 64);
  CpuFill32(0, &p[64], 12);
}

void clearUnlockedCyberElfDataHard(u8 *p) {
  gUnlockedElfPtr = (void *)p;
  CpuFastFill16(0, p, 64);
  CpuFill32(0, &p[64], 12);
}

NAKED void unlockAllElvesForUltimate(u8 *p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	sub sp, #8\n\
	adds r4, r0, #0\n\
	ldr r6, _080E1C9C @ =gUnlockedElfPtr\n\
	str r4, [r6]\n\
	movs r5, #0\n\
	str r5, [sp]\n\
	ldr r2, _080E1CA0 @ =0x01000010\n\
	mov r0, sp\n\
	adds r1, r4, #0\n\
	bl CpuFastSet\n\
	str r5, [sp, #4]\n\
	add r0, sp, #4\n\
	adds r4, #0x40\n\
	ldr r2, _080E1CA4 @ =0x05000003\n\
	adds r1, r4, #0\n\
	bl CpuSet\n\
	movs r4, #0\n\
	movs r5, #3\n\
	movs r0, #0x19\n\
	rsbs r0, r0, #0\n\
	mov r8, r0\n\
	mov sb, r0\n\
_080E1BF8:\n\
	ldr r2, [r6]\n\
	adds r2, r2, r4\n\
	ldrb r0, [r2]\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	adds r0, r4, #0\n\
	bl FUN_080e1cac\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _080E1C84\n\
	ldr r2, [r6]\n\
	adds r2, r2, r4\n\
	ldrb r0, [r2]\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	ldr r1, _080E1CA8 @ =gElfBreedInfo\n\
	lsls r0, r4, #2\n\
	adds r3, r0, r1\n\
	ldrb r0, [r3]\n\
	lsls r0, r0, #0x1d\n\
	lsrs r0, r0, #0x1d\n\
	cmp r0, #1\n\
	bne _080E1C46\n\
	ldr r0, [r6]\n\
	adds r0, r0, r4\n\
	ldr r1, [r0]\n\
	lsls r1, r1, #0x1b\n\
	lsrs r1, r1, #0x1e\n\
	adds r1, #1\n\
	ands r1, r5\n\
	lsls r1, r1, #3\n\
	ldrb r2, [r0]\n\
	mov r7, r8\n\
	ands r2, r7\n\
	orrs r2, r1\n\
	strb r2, [r0]\n\
_080E1C46:\n\
	ldrb r0, [r3]\n\
	lsls r0, r0, #0x1d\n\
	lsrs r0, r0, #0x1d\n\
	cmp r0, #2\n\
	bne _080E1C84\n\
	ldr r3, [r6]\n\
	adds r3, r3, r4\n\
	ldr r1, [r3]\n\
	lsls r1, r1, #0x1b\n\
	lsrs r1, r1, #0x1e\n\
	adds r1, #1\n\
	ands r1, r5\n\
	lsls r1, r1, #3\n\
	ldrb r2, [r3]\n\
	mov r0, sb\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	ldr r3, [r6]\n\
	adds r3, r3, r4\n\
	ldr r1, [r3]\n\
	lsls r1, r1, #0x1b\n\
	lsrs r1, r1, #0x1e\n\
	adds r1, #1\n\
	ands r1, r5\n\
	lsls r1, r1, #3\n\
	ldrb r2, [r3]\n\
	mov r0, sb\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
_080E1C84:\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #0x49\n\
	bls _080E1BF8\n\
	add sp, #8\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E1C9C: .4byte gUnlockedElfPtr\n\
_080E1CA0: .4byte 0x01000010\n\
_080E1CA4: .4byte 0x05000003\n\
_080E1CA8: .4byte gElfBreedInfo\n\
 .syntax divided\n");
}

bool8 FUN_080e1cac(cyberelf_t n) {
  register u8 m asm("r3") = n;  // m = n;
  const struct ElfBreedInfo *infos = gElfBreedInfo;
  if (((infos[n].unk_0 >> 7) == 0) && (n != ELF_ARTAN) && (m != ELF_ZICTAN)) {
    return FALSE;
  }
  return TRUE;
}

// ------------------------------------------------------------------------------------------------------------------------------------

const u8 u8_ARRAY_08371ab8[68] = {
    0xFE, 0xFE, 0xFF, 0xFE, 0xFE, 0xFF, 0xFE, 0x00, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFE, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0xFE, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFE, 0xFE, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFE, 0xFF, 0xFF, 0xFE, 0xFF, 0xFE, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFE, 0xFE, 0xFE, 0xFE,
};

const u16 u16_ARRAY_08371afc[36] = {
    0x0000, 0x012C, 0x0000, 0x0000, 0x0190, 0x0000, 0x0064, 0x0046, 0x0000, 0x0064, 0x0096, 0x0000, 0x0064, 0x00C8, 0x0000, 0x0064, 0x00FA, 0x0000, 0x0064, 0x012C, 0x0000, 0x00C8, 0x0096, 0x0000, 0x00C8, 0x00C8, 0x0000, 0x00C8, 0x00FA, 0x0000, 0x012C, 0x00C8, 0x01F4, 0x012C, 0x012C, 0x02BC,
};

const struct ElfBreedInfo gElfBreedInfo[CYBERELF_LENGTH] = {
    {0x8A, 0x00, 0x01, 0x0B}, {0x89, 0x00, 0x00, 0x09}, {0x89, 0x00, 0x00, 0x09}, {0x89, 0x00, 0x00, 0x09}, {0x89, 0x00, 0x00, 0x09}, {0x01, 0x07, 0x00, 0x01}, {0x01, 0x07, 0x00, 0x01}, {0x11, 0x07, 0x02, 0x04}, {0x11, 0x07, 0x02, 0x04}, {0x10, 0x01, 0x00, 0x02}, {0x10, 0x01, 0x00, 0x02}, {0x10, 0x01, 0x00, 0x02}, {0x10, 0x01, 0x00, 0x02}, {0x10, 0x01, 0x00, 0x02}, {0x10, 0x01, 0x00, 0x02}, {0x10, 0x01, 0x00, 0x02}, {0x10, 0x01, 0x00, 0x02}, {0x10, 0x01, 0x02, 0x02}, {0x10, 0x01, 0x02, 0x02}, {0x10, 0x01, 0x02, 0x02}, {0x10, 0x01, 0x02, 0x02}, {0x10, 0x01, 0x02, 0x02}, {0x10, 0x01, 0x02, 0x02}, {0x50, 0x02, 0x00, 0x02}, {0x50, 0x02, 0x00, 0x02}, {0x50, 0x04, 0x00, 0x02}, {0x50, 0x04, 0x00, 0x02}, {0x8A, 0x07, 0x00, 0x0A}, {0x89, 0x07, 0x00, 0x06}, {0x89, 0x07, 0x00, 0x02}, {0x89, 0x07, 0x00, 0x08}, {0x89, 0x07, 0x00, 0x05}, {0x40, 0x0C, 0x00, 0x00}, {0x40, 0x0C, 0x00, 0x00}, {0x40, 0x09, 0x00, 0x00}, {0x40, 0x09, 0x00, 0x00}, {0x50, 0x0A, 0x00, 0x02},
    {0x50, 0x0A, 0x00, 0x02}, {0x40, 0x0A, 0x00, 0x00}, {0x40, 0x0A, 0x00, 0x00}, {0x8A, 0x06, 0x00, 0x0A}, {0x88, 0x06, 0x01, 0x0A}, {0x88, 0x07, 0x00, 0x02}, {0x89, 0x07, 0x00, 0x03}, {0x88, 0x07, 0x00, 0x02}, {0x89, 0x07, 0x00, 0x07}, {0x88, 0x07, 0x00, 0x02}, {0x88, 0x07, 0x00, 0x02}, {0x88, 0x07, 0x00, 0x02}, {0x88, 0x07, 0x00, 0x02}, {0x88, 0x07, 0x00, 0x02}, {0x88, 0x07, 0x00, 0x02}, {0x88, 0x07, 0x00, 0x07}, {0x00, 0x06, 0x02, 0x00}, {0x00, 0x06, 0x02, 0x00}, {0x00, 0x06, 0x02, 0x00}, {0x00, 0x06, 0x02, 0x00}, {0x00, 0x06, 0x02, 0x00}, {0x01, 0x06, 0x03, 0x00}, {0x01, 0x06, 0x03, 0x00}, {0x01, 0x06, 0x03, 0x00}, {0x00, 0x06, 0x04, 0x00}, {0x00, 0x06, 0x04, 0x00}, {0x00, 0x06, 0x04, 0x00}, {0x00, 0x06, 0x04, 0x00}, {0x00, 0x06, 0x04, 0x00}, {0x01, 0x06, 0x05, 0x00}, {0x01, 0x06, 0x05, 0x00}, {0x01, 0x06, 0x05, 0x00}, {0x00, 0x06, 0x06, 0x00}, {0x00, 0x06, 0x06, 0x00}, {0x00, 0x06, 0x06, 0x00}, {0x00, 0x06, 0x06, 0x00}, {0x00, 0x06, 0x06, 0x00},
};
