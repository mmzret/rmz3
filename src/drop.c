#include "enemy.h"
#include "global.h"
#include "pickup.h"
#include "reward.h"
#include "stagerun.h"
#include "story.h"

static const s8 sMiddleBossDiskNo[8];
static const u16 sItemDropRates[ITEM_COUNT][7];
static const ALIGNED(2) struct DiskDrop sEnemyDiskDrops[42];
static const u8 sStageEnemyDiskDrops[STAGE_COUNT];

u32 TryDropItem(u32 table, struct Coord *c) {
  u16 n;
  u8 rng;
  const u16 *tbl;

  RNG_0202f388 = LCG(RNG_0202f388);
  rng = (u8)((RNG_0202f388 >> 16));

  // Secret Disk
  if (table >= ITEM_COUNT) {
    u8 *disks;
    s32 diskID;

    n = table - 9;
    disks = gStageDiskManager.disk;
    diskID = sMiddleBossDiskNo[n] - 1;
    if (((disks[diskID >> 2] & 0x0F) >> (diskID & 3)) & 1) {
      return FALSE;
    }
    CreateMapDisk(sMiddleBossDiskNo[n], c, 1);
    return TRUE;
  }

  if (FLAG(gCurStory.s.gameflags, IN_CYBERSPACE)) {
    table = 8;
  }
  if (FLAG(gCurStory.s.gameflags, DYLPHINA_ENABLED)) {
    table = 5;
  }

  for (n = 0; n < 6; n++) {
    if (rng < sItemDropRates[table][n]) {
      break;
    }
  }
  if (n != 0) {
    CreatePickupItem(n - 1, c, 0);
  }
  return n;
}

NAKED void TryDropZakoDisk(struct Enemy *p, struct Coord *c) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	adds r5, r0, #0\n\
	mov sl, r1\n\
	ldr r0, _08025064 @ =gStageRun\n\
	ldrh r0, [r0]\n\
	str r0, [sp]\n\
	ldr r0, _08025068 @ =sStageEnemyDiskDrops\n\
	ldr r1, [sp]\n\
	adds r0, r1, r0\n\
	ldrb r4, [r0]\n\
	ldr r2, _0802506C @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	mov sb, r2\n\
	cmp r0, #0\n\
	beq _08024F6A\n\
	b _080250A6\n\
_08024F6A:\n\
	ldr r3, _08025070 @ =sEnemyDiskDrops\n\
	lsls r2, r4, #4\n\
	adds r0, r2, r3\n\
	movs r7, #0\n\
	ldrsh r0, [r0, r7]\n\
	mov r8, r3\n\
	ldr r1, [sp]\n\
	cmp r1, r0\n\
	beq _08024F7E\n\
	b _080250A6\n\
_08024F7E:\n\
	mov ip, r3\n\
	adds r0, r2, #0\n\
	adds r0, #0xe\n\
	adds r6, r0, r3\n\
_08024F86:\n\
	ldr r0, _08025074 @ =gOverworld\n\
	movs r7, #0xe8\n\
	lsls r7, r7, #1\n\
	adds r0, r0, r7\n\
	ldrh r0, [r0]\n\
	movs r1, #0x7f\n\
	ands r1, r0\n\
	mov r0, ip\n\
	adds r0, #2\n\
	adds r0, r2, r0\n\
	movs r7, #0\n\
	ldrsh r0, [r0, r7]\n\
	cmp r1, r0\n\
	bne _08025090\n\
	ldrb r0, [r5, #9]\n\
	adds r1, r3, #0\n\
	adds r1, #8\n\
	adds r1, r2, r1\n\
	movs r3, #0\n\
	ldrsh r1, [r1, r3]\n\
	cmp r0, r1\n\
	bne _08025090\n\
	mov r0, ip\n\
	adds r0, #6\n\
	adds r0, r2, r0\n\
	movs r1, #8\n\
	ldrsb r1, [r5, r1]\n\
	movs r7, #0\n\
	ldrsh r0, [r0, r7]\n\
	cmp r1, r0\n\
	bne _08025090\n\
	mov r0, ip\n\
	adds r0, #0xa\n\
	adds r3, r2, r0\n\
	movs r0, #0\n\
	ldrsh r1, [r3, r0]\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	cmp r1, r0\n\
	beq _08024FE0\n\
	ldrb r1, [r5, #0x10]\n\
	movs r7, #0\n\
	ldrsh r0, [r3, r7]\n\
	cmp r1, r0\n\
	bne _08025090\n\
_08024FE0:\n\
	mov r0, ip\n\
	adds r0, #4\n\
	adds r5, r2, r0\n\
	movs r1, #0\n\
	ldrsh r0, [r5, r1]\n\
	mov r7, sb\n\
	adds r7, #0xc\n\
	adds r1, r0, r7\n\
	ldrb r0, [r1]\n\
	cmp r0, #0xfe\n\
	bhi _08024FFA\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
_08024FFA:\n\
	movs r3, #0\n\
	ldrsh r0, [r5, r3]\n\
	adds r0, r0, r7\n\
	ldrb r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0xc\n\
	adds r0, r2, r0\n\
	movs r2, #0\n\
	ldrsh r0, [r0, r2]\n\
	cmp r1, r0\n\
	bne _080250A6\n\
	ldr r0, _08025078 @ =gStageDiskManager\n\
	ldr r1, [r0]\n\
	movs r3, #0\n\
	ldrsh r2, [r6, r3]\n\
	subs r2, #1\n\
	asrs r0, r2, #2\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1]\n\
	movs r4, #0xf\n\
	ands r4, r0\n\
	movs r0, #3\n\
	ands r2, r0\n\
	asrs r4, r2\n\
	movs r0, #1\n\
	ands r4, r0\n\
	cmp r4, #0\n\
	bne _080250A6\n\
	ldr r0, _0802507C @ =gPickupHeaderPtr\n\
	ldr r0, [r0]\n\
	ldrb r2, [r6]\n\
	movs r1, #1\n\
	movs r3, #0\n\
	bl countSpecificEntities2\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _08025086\n\
	ldrb r0, [r6]\n\
	mov r1, sl\n\
	movs r2, #0\n\
	bl CreateMapDisk\n\
	cmp r0, #0\n\
	bne _08025080\n\
	movs r0, #0\n\
	ldrsh r1, [r5, r0]\n\
	adds r1, r1, r7\n\
	ldrb r0, [r1]\n\
	subs r0, #1\n\
	strb r0, [r1]\n\
	b _080250A6\n\
	.align 2, 0\n\
_08025064: .4byte gStageRun\n\
_08025068: .4byte sStageEnemyDiskDrops\n\
_0802506C: .4byte gCurStory\n\
_08025070: .4byte sEnemyDiskDrops\n\
_08025074: .4byte gOverworld\n\
_08025078: .4byte gStageDiskManager\n\
_0802507C: .4byte gPickupHeaderPtr\n\
_08025080:\n\
	movs r1, #0\n\
	ldrsh r0, [r5, r1]\n\
	b _0802508A\n\
_08025086:\n\
	movs r2, #0\n\
	ldrsh r0, [r5, r2]\n\
_0802508A:\n\
	adds r0, r0, r7\n\
	strb r4, [r0]\n\
	b _080250A6\n\
_08025090:\n\
	adds r6, #0x10\n\
	adds r4, #1\n\
	mov r3, r8\n\
	lsls r2, r4, #4\n\
	adds r0, r2, r3\n\
	movs r7, #0\n\
	ldrsh r0, [r0, r7]\n\
	ldr r1, [sp]\n\
	cmp r1, r0\n\
	bne _080250A6\n\
	b _08024F86\n\
_080250A6:\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

// clang-format off
static const u16 sItemDropRates[ITEM_COUNT][7] = {
     // sItemDropRates[確率テーブル][itemID]
    { 0x0100, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
    { 0x00A0, 0x00E0, 0x0100, 0x0000, 0x0000, 0x0000, 0x0000 },
    { 0x0080, 0x0000, 0x0000, 0x0000, 0x00E0, 0x0100, 0x0000 },
    { 0x0060, 0x00A0, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000 },
    { 0x006B, 0x009F, 0x00AF, 0x0000, 0x00EF, 0x00FF, 0x0100 },
    { 0x0000, 0x0060, 0x007F, 0x0000, 0x00DF, 0x00FF, 0x0100 },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000 },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100 },
    { 0x0000, 0x00E0, 0x0100, 0x0000, 0x0000, 0x0000, 0x0000 },
};
// clang-format on

static const s8 sMiddleBossDiskNo[8] = {
    DISK_ELF_ILETHAS, DISK_ELF_HANMARBO, DISK_ELF_ARCHIL, DISK_ELF_ANATER, DISK_ELF_KYNITE, DISK_TOP_GABYOALL, DISK_ULTIMA_FOOT, DISK_ELF_HANMARJI,
};

static const ALIGNED(2) struct DiskDrop sEnemyDiskDrops[42] = {
    // Space Craft
    {
      stageID : STAGE_SPACE_CRAFT,
      stageID2 : STAGE_SPACE_CRAFT,
      zakoOfs : 29,
      type : ENTITY_ENEMY,
      id : ENEMY_GRAND_CANNON,
      kind : 0xFFFF,
      count : 5,
      diskNo : DISK_GRAND_CANNON,
    },
    {
      stageID : STAGE_SPACE_CRAFT,
      stageID2 : STAGE_SPACE_CRAFT,
      zakoOfs : 30,
      type : ENTITY_ENEMY,
      id : ENEMY_SHRIMPORIN,
      kind : 0xFFFF,
      count : 3,
      diskNo : DISK_SHRIMPOLIN,
    },
    {
      stageID : STAGE_SPACE_CRAFT,
      stageID2 : STAGE_SPACE_CRAFT,
      zakoOfs : 31,
      type : ENTITY_ENEMY,
      id : ENEMY_BATRING,
      kind : 0xFFFF,
      count : 4,
      diskNo : DISK_BATRING,
    },
    {
      stageID : STAGE_SPACE_CRAFT,
      stageID2 : STAGE_SPACE_CRAFT,
      zakoOfs : 32,
      type : ENTITY_ENEMY,
      id : ENEMY_SHOTCOUNTER,
      kind : 0xFFFF,
      count : 4,
      diskNo : DISK_SHOTCOUNTER,
    },

    // Volcano
    {
      stageID : STAGE_VOLCANO,
      stageID2 : STAGE_VOLCANO,
      zakoOfs : 33,
      type : ENTITY_ENEMY,
      id : ENEMY_VOLCAIRE,
      kind : 0xFFFF,
      count : 3,
      diskNo : DISK_VOLCAIRE,
    },
    {
      stageID : STAGE_VOLCANO,
      stageID2 : STAGE_VOLCANO,
      zakoOfs : 34,
      type : ENTITY_ENEMY,
      id : ENEMY_LAMPLORT,
      kind : 0xFFFF,
      count : 4,
      diskNo : DISK_LAMPLORT,
    },
    {
      stageID : STAGE_VOLCANO,
      stageID2 : STAGE_VOLCANO,
      zakoOfs : 35,
      type : ENTITY_ENEMY,
      id : ENEMY_CROSSBYNE,
      kind : 0xFFFF,
      count : 10,
      diskNo : DISK_CROSSBYNE,
    },

    // Ocean
    {
      stageID : STAGE_OCEAN,
      stageID2 : STAGE_OCEAN,
      zakoOfs : 36,
      type : ENTITY_ENEMY,
      id : ENEMY_SHELLUNO,
      kind : 0xFFFF,
      count : 4,
      diskNo : DISK_SHELLUNO,
    },
    {
      stageID : STAGE_OCEAN,
      stageID2 : STAGE_OCEAN,
      zakoOfs : 37,
      type : ENTITY_SOLID,
      id : SOLID_ICEBON,
      kind : 0xFFFF,
      count : 3,
      diskNo : DISK_ICEBON,
    },
    {
      stageID : STAGE_OCEAN,
      stageID2 : STAGE_OCEAN,
      zakoOfs : 38,
      type : ENTITY_ENEMY,
      id : ENEMY_SHARKSEAL_X,
      kind : 0xFFFF,
      count : 4,
      diskNo : DISK_SHARKSEAL_X,
    },

    // Repair Factory
    {
      stageID : STAGE_REPAIR_FACTORY,
      stageID2 : STAGE_REPAIR_FACTORY,
      zakoOfs : 39,
      type : ENTITY_ENEMY,
      id : ENEMY_LEMMINGLES_NEST,
      kind : 0xFFFF,
      count : 3,
      diskNo : DISK_ELF_GAMBUL,
    },
    {
      stageID : STAGE_REPAIR_FACTORY,
      stageID2 : STAGE_REPAIR_FACTORY,
      zakoOfs : 40,
      type : ENTITY_ENEMY,
      id : 55,
      kind : 0xFFFF,
      count : 5,
      diskNo : DISK_DEATHLOCK,
    },
    {
      stageID : STAGE_REPAIR_FACTORY,
      stageID2 : STAGE_REPAIR_FACTORY,
      zakoOfs : 41,
      type : ENTITY_ENEMY,
      id : ENEMY_LEMMINGLES,
      kind : 0xFFFF,
      count : 5,
      diskNo : DISK_LEMMINGLES,
    },

    // Old residential
    {
      stageID : STAGE_OLD_RESIDENTIAL,
      stageID2 : STAGE_OLD_RESIDENTIAL,
      zakoOfs : 42,
      type : ENTITY_ENEMY,
      id : ENEMY_PILLER_CANNON,
      kind : 0xFFFF,
      count : 3,
      diskNo : DISK_PILLAR_CANNON,
    },
    {
      stageID : STAGE_OLD_RESIDENTIAL,
      stageID2 : STAGE_OLD_RESIDENTIAL,
      zakoOfs : 43,
      type : ENTITY_ENEMY,
      id : ENEMY_SEIMERAN,
      kind : 0,  // 本体のみカウント
      count : 5,
      diskNo : DISK_SEIMERAN,
    },

    // Missile factory
    {
      stageID : STAGE_MISSILE_FACTORY,
      stageID2 : STAGE_MISSILE_FACTORY,
      zakoOfs : 44,
      type : ENTITY_ENEMY,
      id : ENEMY_GENERATOR_CANNON,
      kind : 0x0001,
      count : 6,
      diskNo : DISK_098_150EC,
    },
    {
      stageID : STAGE_MISSILE_FACTORY,
      stageID2 : STAGE_MISSILE_FACTORY,
      zakoOfs : 45,
      type : ENTITY_ENEMY,
      id : ENEMY_P_GUARDIAN,
      kind : 0xFFFF,
      count : 4,
      diskNo : DISK_PANTHEON_GUARDIAN,
    },
    {0x0006, 0x0006, 0x002E, 0x0003, 0x0036, 0x0000, 0x0003, 0x008A},
    {0x0006, 0x0006, 0x002F, 0x0003, 0x0029, 0xFFFF, 0x0004, 0x008B},
    {0x0007, 0x0007, 0x0030, 0x0003, 0x0033, 0xFFFF, 0x0002, 0x0041},
    {0x0007, 0x0007, 0x0031, 0x0003, 0x0007, 0xFFFF, 0x0005, 0x005B},
    {0x0007, 0x0007, 0x0032, 0x0003, 0x0009, 0xFFFF, 0x0005, 0x0099},
    {0x0007, 0x0007, 0x0033, 0x0003, 0x0016, 0xFFFF, 0x0005, 0x009A},
    {0x0008, 0x0008, 0x0034, 0x0003, 0x0019, 0xFFFF, 0x0007, 0x0086},
    {0x0008, 0x0008, 0x0035, 0x0003, 0x0023, 0xFFFF, 0x0005, 0x009D},
    {0x0009, 0x0009, 0x0036, 0x0003, 0x0012, 0xFFFF, 0x0003, 0x0080},
    {0x0009, 0x0009, 0x0037, 0x0003, 0x000B, 0xFFFF, 0x0003, 0x0084},
    {0x0009, 0x0009, 0x0038, 0x0006, 0x0005, 0xFFFF, 0x0004, 0x0088},
    {0x000A, 0x000A, 0x0039, 0x0003, 0x002B, 0xFFFF, 0x0004, 0x0089},
    {0x000B, 0x000B, 0x003A, 0x0003, 0x0014, 0xFFFF, 0x0004, 0x0096},
    {0x000B, 0x000B, 0x003B, 0x0003, 0x002F, 0xFFFF, 0x0009, 0x009B},
    {0x000C, 0x000C, 0x003C, 0x0003, 0x001D, 0xFFFF, 0x0005, 0x002E},
    {0x000C, 0x000C, 0x003D, 0x0003, 0x0031, 0xFFFF, 0x0004, 0x0082},
    {0x000C, 0x000C, 0x003E, 0x0003, 0x0041, 0xFFFF, 0x0004, 0x00A2},
    {0x000E, 0x000E, 0x003F, 0x0003, 0x0040, 0xFFFF, 0x0005, 0x0081},
    {0x000E, 0x000E, 0x0040, 0x0003, 0x003E, 0xFFFF, 0x0006, 0x0090},
    {0x000E, 0x000E, 0x0041, 0x0003, 0x0043, 0xFFFF, 0x0005, 0x0094},
    {0x000F, 0x000F, 0x0042, 0x0003, 0x0038, 0xFFFF, 0x0005, 0x008E},
    {0x000F, 0x000F, 0x0043, 0x0003, 0x003A, 0xFFFF, 0x0003, 0x008F},
    {0x000F, 0x000F, 0x0044, 0x0003, 0x0042, 0xFFFF, 0x0005, 0x00A3},
    {0x0010, 0x0010, 0x0045, 0x0003, 0x0001, 0xFFFF, 0x0005, 0x007E},
    {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000},
};

static const u8 sStageEnemyDiskDrops[STAGE_COUNT] = {
    0, 0, 4, 7, 10, 13, 15, 19, 23, 25, 28, 29, 31, 34, 34, 37, 40, 0,
};
