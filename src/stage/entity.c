#include "entity.h"

#include "boss.h"
#include "cyberelf.h"
#include "enemy.h"
#include "gfx.h"
#include "global.h"
#include "overworld.h"
#include "pickup.h"
#include "projectile.h"
#include "solid.h"
#include "vfx.h"
#include "zero.h"

static void ReleaseAllStageEntities(void);
static struct StageEntity* AllocStageEntity(void);
static void ReleaseStageEntity(struct StageEntity* p);
static void FUN_08018848(u8 stageID, u8 area);
static void FUN_08018c00(u8 stageID, u8 area);
static void FUN_08018d10(u8 stageID, u8 area);
static void FUN_08018e20(void);
static void FUN_08018fa0(void);

// clang-format off

// --------------------------------------------

static const struct EntityTemplate* const sStageEntityTemplate[STAGE_COUNT] = {
  [STAGE_NONE]            = gStage0Entity,
  [STAGE_SPACE_CRAFT]     = gSpaceCraftEntity,
  [STAGE_VOLCANO]         = gVolcanoEntity,
  [STAGE_OCEAN]           = gOceanEntity,
  [STAGE_REPAIR_FACTORY]  = gRepairFactoryEntity,
  [STAGE_OLD_RESIDENTIAL] = gOldLifeSpaceEntity,
  [STAGE_MISSILE_FACTORY] = gMissileFactoryEntity,
  [STAGE_TWILIGHT_DESERT] = gTwilightDesertEntity,
  [STAGE_ANATRE_FOREST]   = gAnatreForestEntity,
  [STAGE_ICE_BASE]        = gIceBaseEntity,
  [STAGE_AREA_X2]         = gAreaX2Entity,
  [STAGE_E_FACILITY]      = gEnergyFacilityEntity,
  [STAGE_SNOWY_PLAINS]    = gSnowyPlainsEntity,
  [STAGE_SUNKEN_LIBRARY]  = gSunkenLibraryEntity,
  [STAGE_GIANT_ELEVATOR]  = gGiantElevatorEntity,
  [STAGE_SUB_ARCADIA]     = gSubArcadiaEntity,
  [STAGE_WEILS_LABO]      = gWeilLaboEntity,
  [STAGE_BASE]            = gResistanceBaseEntity,
};

// --------------------------------------------

static const struct EntityTemplateCoord* const sStageEntityTemplateCoord[STAGE_COUNT] = {
  [STAGE_NONE]            = gStage0EntityCoord,
  [STAGE_SPACE_CRAFT]     = gSpaceCraftEntityCoord,
  [STAGE_VOLCANO]         = gVolcanoEntityCoord,
  [STAGE_OCEAN]           = gOceanEntityCoord,
  [STAGE_REPAIR_FACTORY]  = gRepairFactoryEntityCoord,
  [STAGE_OLD_RESIDENTIAL] = gOldLifeSpaceEntityCoord,
  [STAGE_MISSILE_FACTORY] = gMissileFactoryEntityCoord,
  [STAGE_TWILIGHT_DESERT] = gTwilightDesertEntityCoord,
  [STAGE_ANATRE_FOREST]   = gAnatreForestEntityCoord,
  [STAGE_ICE_BASE]        = gIceBaseEntityCoord,
  [STAGE_AREA_X2]         = gAreaX2EntityCoord,
  [STAGE_E_FACILITY]      = gEnergyFacilityEntityCoord,
  [STAGE_SNOWY_PLAINS]    = gSnowyPlainsEntityCoord,
  [STAGE_SUNKEN_LIBRARY]  = gSunkenLibraryEntityCoord,
  [STAGE_GIANT_ELEVATOR]  = gGiantElevatorEntityCoord,
  [STAGE_SUB_ARCADIA]     = gSubArcadiaEntityCoord,
  [STAGE_WEILS_LABO]      = gWeilLaboEntityCoord,
  [STAGE_BASE]            = gResistanceBaseEntityCoord,
};

// --------------------------------------------

static const struct PreloadEntity* const sStagePreloadEntities[STAGE_COUNT] = {
  [STAGE_NONE]            = sStage0StaticTemplate,
  [STAGE_SPACE_CRAFT]     = gSpaceCraftStatic,
  [STAGE_VOLCANO]         = gVolcanoStatic,
  [STAGE_OCEAN]           = gOceanStatic,
  [STAGE_REPAIR_FACTORY]  = gRepairFactoryStatic,
  [STAGE_OLD_RESIDENTIAL] = gOldLifeSpaceStatic,
  [STAGE_MISSILE_FACTORY] = gMissileFactoryStatic,
  [STAGE_TWILIGHT_DESERT] = gTwilightDesertStatic,
  [STAGE_ANATRE_FOREST]   = gAnatreForestStatic,
  [STAGE_ICE_BASE]        = gIceBaseStatic,
  [STAGE_AREA_X2]         = gAreaX2Static,
  [STAGE_E_FACILITY]      = gEnergyFacilityStatic,
  [STAGE_SNOWY_PLAINS]    = gSnowyPlainsStatic,
  [STAGE_SUNKEN_LIBRARY]  = gSunkenLibraryStatic,
  [STAGE_GIANT_ELEVATOR]  = gGiantElevatorStatic,
  [STAGE_SUB_ARCADIA]     = gSubArcadiaStatic,
  [STAGE_WEILS_LABO]      = gWeilLaboStatic,
  [STAGE_BASE]            = gResistanceBaseStatic,
};

// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

WIP void InitStageEntityManager(u8 stageID, bool8 missionDone) {
#if MODERN
  s32 i;
  struct StageEntityManager* manager = &gStageEntityManager;
  manager->isMissionDone = missionDone;
  manager->unk_20e = 0;
  manager->stageID = stageID;
  manager->start = 1;
  manager->dynamicEntityRange[0] = -0x7FFFFFFF;
  manager->dynamicEntityRange[1] = 0x7FFFFFFF;
  manager->area = 0xFF;
  manager->unk_226[0] = 0;
  manager->unk_226[1] = 0;
  manager->unk_226[2] = 0;
  manager->unk_22a = 0;
  manager->unk_226[3] = 0;
  ReleaseAllStageEntities();
  for (i = 0; i < 33; i++) {
    manager->entityEnabled[i] = 0xFFFFFFFF;  // All enabled
  }
  manager->template = sStageEntityTemplate[stageID];
  manager->templateCoord = sStageEntityTemplateCoord[stageID];
#else
  INCCODE("asm/wip/InitStageEntityManager.inc");
#endif
}

NAKED void UpdateStageEntities(struct Coord* viewport) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x10\n\
	str r0, [sp]\n\
	ldr r4, _08017D2C @ =gStageEntityManager\n\
	movs r1, #0x84\n\
	lsls r1, r1, #2\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	str r0, [sp, #4]\n\
	ldr r1, _08017D30 @ =gAreaCheckers\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	ldr r0, [sp]\n\
	bl _call_via_r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov sl, r0\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r0, r4, r2\n\
	ldr r0, [r0]\n\
	mov r8, r0\n\
	movs r3, #0x86\n\
	lsls r3, r3, #2\n\
	adds r0, r4, r3\n\
	ldr r0, [r0]\n\
	mov sb, r0\n\
	ldr r2, _08017D34 @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08017CA8\n\
	b _08017DA8\n\
_08017CA8:\n\
	ldrb r1, [r2, #8]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08017DA8\n\
	movs r0, #0x8a\n\
	lsls r0, r0, #2\n\
	adds r1, r4, r0\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	beq _08017CC0\n\
	b _08017EC2\n\
_08017CC0:\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	movs r2, #0\n\
	ldr r0, _08017D38 @ =gSystemSavedataManager\n\
	ldr r1, [r0, #0x40]\n\
	ldr r0, _08017D3C @ =0x000032DA\n\
	cmp r1, r0\n\
	beq _08017CD6\n\
	rsbs r0, r1, #0\n\
	orrs r0, r1\n\
	lsrs r2, r0, #0x1f\n\
_08017CD6:\n\
	ldr r1, _08017D40 @ =0x00000229\n\
	adds r5, r4, r1\n\
	strb r2, [r5]\n\
	cmp r2, #0\n\
	beq _08017CE8\n\
	ldr r0, [sp, #4]\n\
	mov r1, sl\n\
	bl FUN_08018d10\n\
_08017CE8:\n\
	movs r2, #0x81\n\
	lsls r2, r2, #2\n\
	adds r0, r4, r2\n\
	ldr r4, [r0]\n\
	ldrb r0, [r5]\n\
	cmp r0, #0\n\
	bne _08017CF8\n\
	b _08017EC2\n\
_08017CF8:\n\
	cmp r4, #0\n\
	beq _08017D8A\n\
	movs r7, #0\n\
_08017CFE:\n\
	ldr r6, [r4]\n\
	ldr r1, [r4, #4]\n\
	cmp r1, #0\n\
	beq _08017D7C\n\
	movs r3, #8\n\
	ldrsh r0, [r4, r3]\n\
	lsls r0, r0, #3\n\
	add r0, sb\n\
	ldrh r0, [r0, #6]\n\
	lsls r0, r0, #3\n\
	add r0, r8\n\
	ldrb r0, [r0, #7]\n\
	cmp r0, #0\n\
	beq _08017D7C\n\
	ldrb r0, [r1, #0xc]\n\
	cmp r0, #1\n\
	bls _08017D44\n\
	adds r0, r1, #0\n\
	bl DeleteStageEntity\n\
	str r7, [r4, #4]\n\
	b _08017D7C\n\
	.align 2, 0\n\
_08017D2C: .4byte gStageEntityManager\n\
_08017D30: .4byte gAreaCheckers\n\
_08017D34: .4byte gCurStory\n\
_08017D38: .4byte gSystemSavedataManager\n\
_08017D3C: .4byte 0x000032DA\n\
_08017D40: .4byte 0x00000229\n\
_08017D44:\n\
	adds r0, r1, #0\n\
	bl DeleteStageEntity\n\
	movs r1, #8\n\
	ldrsh r0, [r4, r1]\n\
	lsls r0, r0, #3\n\
	add r0, sb\n\
	ldrh r0, [r0, #6]\n\
	lsls r0, r0, #3\n\
	add r0, r8\n\
	ldrb r1, [r0, #7]\n\
	adds r1, #0x1d\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	movs r0, #3\n\
	bl CreateStageEntity\n\
	adds r2, r0, #0\n\
	cmp r2, #0\n\
	beq _08017D7A\n\
	strb r7, [r2, #0x10]\n\
	strb r7, [r2, #0x11]\n\
	ldr r0, [r4, #4]\n\
	ldr r1, [r0, #0x54]\n\
	str r1, [r2, #0x54]\n\
	ldr r0, [r0, #0x58]\n\
	str r0, [r2, #0x58]\n\
_08017D7A:\n\
	str r2, [r4, #4]\n\
_08017D7C:\n\
	adds r4, r6, #0\n\
	ldrb r0, [r5]\n\
	cmp r0, #0\n\
	bne _08017D86\n\
	b _08017EC2\n\
_08017D86:\n\
	cmp r4, #0\n\
	bne _08017CFE\n\
_08017D8A:\n\
	ldr r0, _08017DA0 @ =gStageEntityManager\n\
	ldr r2, _08017DA4 @ =0x00000229\n\
	adds r0, r0, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _08017D98\n\
	b _08017EC2\n\
_08017D98:\n\
	bl FUN_08018e20\n\
	b _08017EC2\n\
	.align 2, 0\n\
_08017DA0: .4byte gStageEntityManager\n\
_08017DA4: .4byte 0x00000229\n\
_08017DA8:\n\
	ldr r0, _08017DCC @ =gStageEntityManager\n\
	movs r3, #0x8a\n\
	lsls r3, r3, #2\n\
	adds r2, r0, r3\n\
	ldrb r1, [r2]\n\
	cmp r1, #0\n\
	bne _08017DB8\n\
	b _08017EC2\n\
_08017DB8:\n\
	movs r0, #0\n\
	strb r0, [r2]\n\
	ldr r1, _08017DCC @ =gStageEntityManager\n\
	movs r2, #0x81\n\
	lsls r2, r2, #2\n\
	adds r0, r1, r2\n\
	ldr r4, [r0]\n\
	adds r3, #1\n\
	adds r0, r1, r3\n\
	b _08017E9C\n\
	.align 2, 0\n\
_08017DCC: .4byte gStageEntityManager\n\
_08017DD0:\n\
	ldr r6, [r4]\n\
	ldr r1, [r4, #4]\n\
	cmp r1, #0\n\
	beq _08017E94\n\
	movs r2, #8\n\
	ldrsh r0, [r4, r2]\n\
	lsls r0, r0, #3\n\
	add r0, sb\n\
	ldrh r0, [r0, #6]\n\
	lsls r0, r0, #3\n\
	add r0, r8\n\
	ldrb r0, [r0, #7]\n\
	cmp r0, #0\n\
	beq _08017E94\n\
	ldrb r0, [r1, #0xc]\n\
	cmp r0, #1\n\
	bls _08017DFE\n\
	adds r0, r1, #0\n\
	bl DeleteStageEntity\n\
	movs r0, #0\n\
	str r0, [r4, #4]\n\
	b _08017E94\n\
_08017DFE:\n\
	adds r0, r1, #0\n\
	bl DeleteStageEntity\n\
	movs r3, #8\n\
	ldrsh r0, [r4, r3]\n\
	lsls r0, r0, #3\n\
	add r0, sb\n\
	ldrh r1, [r0, #6]\n\
	lsls r1, r1, #3\n\
	add r1, r8\n\
	ldrb r0, [r1, #1]\n\
	ldrb r1, [r1, #2]\n\
	bl CreateStageEntity\n\
	adds r2, r0, #0\n\
	cmp r2, #0\n\
	bne _08017E28\n\
	adds r0, r4, #0\n\
	bl ReleaseStageEntity\n\
	b _08017E94\n\
_08017E28:\n\
	movs r1, #8\n\
	ldrsh r0, [r4, r1]\n\
	lsls r0, r0, #3\n\
	add r0, sb\n\
	ldrh r0, [r0, #6]\n\
	lsls r0, r0, #3\n\
	add r0, r8\n\
	ldrb r0, [r0, #3]\n\
	strb r0, [r2, #0x10]\n\
	movs r3, #8\n\
	ldrsh r0, [r4, r3]\n\
	lsls r0, r0, #3\n\
	add r0, sb\n\
	ldrh r0, [r0, #6]\n\
	lsls r0, r0, #3\n\
	add r0, r8\n\
	ldrb r0, [r0, #4]\n\
	strb r0, [r2, #0x11]\n\
	ldr r0, _08017E80 @ =gCurStory\n\
	ldrb r1, [r0, #8]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08017E88\n\
	movs r1, #8\n\
	ldrsh r0, [r4, r1]\n\
	lsls r0, r0, #3\n\
	add r0, sb\n\
	ldr r0, [r0]\n\
	lsls r0, r0, #0xc\n\
	movs r3, #0x80\n\
	lsls r3, r3, #4\n\
	adds r0, r0, r3\n\
	str r0, [r2, #0x54]\n\
	movs r1, #8\n\
	ldrsh r0, [r4, r1]\n\
	lsls r0, r0, #3\n\
	add r0, sb\n\
	movs r3, #4\n\
	ldrsh r0, [r0, r3]\n\
	lsls r0, r0, #0xc\n\
	ldr r1, _08017E84 @ =0x000007FF\n\
	adds r0, r0, r1\n\
	b _08017E90\n\
	.align 2, 0\n\
_08017E80: .4byte gCurStory\n\
_08017E84: .4byte 0x000007FF\n\
_08017E88:\n\
	ldr r0, [r4, #4]\n\
	ldr r1, [r0, #0x54]\n\
	str r1, [r2, #0x54]\n\
	ldr r0, [r0, #0x58]\n\
_08017E90:\n\
	str r0, [r2, #0x58]\n\
	str r2, [r4, #4]\n\
_08017E94:\n\
	adds r4, r6, #0\n\
	ldr r0, _08017FA8 @ =gStageEntityManager\n\
	ldr r2, _08017FAC @ =0x00000229\n\
	adds r0, r0, r2\n\
_08017E9C:\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _08017EC2\n\
	cmp r4, #0\n\
	bne _08017DD0\n\
	ldr r0, _08017FA8 @ =gStageEntityManager\n\
	ldr r3, _08017FAC @ =0x00000229\n\
	adds r4, r0, r3\n\
	ldrb r0, [r4]\n\
	cmp r0, #0\n\
	beq _08017EC2\n\
	bl FUN_08018fa0\n\
	movs r0, #0\n\
	strb r0, [r4]\n\
	ldr r0, [sp, #4]\n\
	mov r1, sl\n\
	bl FUN_08018848\n\
_08017EC2:\n\
	ldr r2, _08017FB0 @ =gCurStory\n\
	ldrb r1, [r2, #8]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08017F4C\n\
	ldr r1, _08017FA8 @ =gStageEntityManager\n\
	ldr r3, _08017FB4 @ =0x00000226\n\
	adds r0, r1, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _08017F4C\n\
	movs r2, #0x81\n\
	lsls r2, r2, #2\n\
	adds r0, r1, r2\n\
	ldr r4, [r0]\n\
	cmp r4, #0\n\
	beq _08017F40\n\
	adds r7, r1, #0\n\
_08017EE8:\n\
	ldr r6, [r4]\n\
	ldr r0, [r4, #4]\n\
	adds r5, r0, #0\n\
	cmp r5, #0\n\
	beq _08017F3A\n\
	movs r3, #8\n\
	ldrsh r0, [r4, r3]\n\
	lsls r0, r0, #3\n\
	add r0, sb\n\
	ldrh r0, [r0, #6]\n\
	lsls r0, r0, #3\n\
	add r0, r8\n\
	ldrb r1, [r0, #5]\n\
	movs r3, #1\n\
	adds r0, r3, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08017F3A\n\
	ldrh r1, [r4, #0xa]\n\
	adds r0, r3, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08017F2E\n\
	ldrh r1, [r4, #8]\n\
	lsls r2, r1, #0x10\n\
	asrs r2, r2, #0x15\n\
	lsls r2, r2, #2\n\
	adds r2, r2, r7\n\
	movs r0, #0x1f\n\
	ands r0, r1\n\
	adds r1, r3, #0\n\
	lsls r1, r0\n\
	ldr r0, [r2]\n\
	orrs r0, r1\n\
	str r0, [r2]\n\
_08017F2E:\n\
	adds r0, r5, #0\n\
	bl DeleteStageEntity\n\
	adds r0, r4, #0\n\
	bl ReleaseStageEntity\n\
_08017F3A:\n\
	adds r4, r6, #0\n\
	cmp r4, #0\n\
	bne _08017EE8\n\
_08017F40:\n\
	ldr r2, _08017FA8 @ =gStageEntityManager\n\
	ldr r0, _08017FB4 @ =0x00000226\n\
	adds r1, r2, r0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldr r2, _08017FB0 @ =gCurStory\n\
_08017F4C:\n\
	ldrb r1, [r2, #8]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08018002\n\
	ldr r1, _08017FA8 @ =gStageEntityManager\n\
	ldr r2, _08017FB8 @ =0x00000227\n\
	adds r0, r1, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _08018002\n\
	ldr r0, [sp, #4]\n\
	mov r1, sl\n\
	bl FUN_08018c00\n\
	ldr r3, _08017FA8 @ =gStageEntityManager\n\
	movs r1, #0x81\n\
	lsls r1, r1, #2\n\
	adds r0, r3, r1\n\
	ldr r4, [r0]\n\
	cmp r4, #0\n\
	beq _08017FF8\n\
	movs r5, #0\n\
_08017F7A:\n\
	ldr r6, [r4]\n\
	ldr r1, [r4, #4]\n\
	cmp r1, #0\n\
	beq _08017FF2\n\
	movs r2, #8\n\
	ldrsh r0, [r4, r2]\n\
	lsls r0, r0, #3\n\
	add r0, sb\n\
	ldrh r0, [r0, #6]\n\
	lsls r0, r0, #3\n\
	add r0, r8\n\
	ldrb r0, [r0, #6]\n\
	cmp r0, #0\n\
	beq _08017FF2\n\
	ldrb r0, [r1, #0xc]\n\
	cmp r0, #1\n\
	bls _08017FBC\n\
	adds r0, r1, #0\n\
	bl DeleteStageEntity\n\
	str r5, [r4, #4]\n\
	b _08017FF2\n\
	.align 2, 0\n\
_08017FA8: .4byte gStageEntityManager\n\
_08017FAC: .4byte 0x00000229\n\
_08017FB0: .4byte gCurStory\n\
_08017FB4: .4byte 0x00000226\n\
_08017FB8: .4byte 0x00000227\n\
_08017FBC:\n\
	adds r0, r1, #0\n\
	bl DeleteStageEntity\n\
	movs r0, #3\n\
	movs r1, #0x30\n\
	bl CreateStageEntity\n\
	adds r2, r0, #0\n\
	cmp r2, #0\n\
	beq _08017FF0\n\
	movs r3, #8\n\
	ldrsh r0, [r4, r3]\n\
	lsls r0, r0, #3\n\
	add r0, sb\n\
	ldrh r0, [r0, #6]\n\
	lsls r0, r0, #3\n\
	add r0, r8\n\
	ldrb r0, [r0, #6]\n\
	subs r0, #1\n\
	strb r0, [r2, #0x10]\n\
	strb r5, [r2, #0x11]\n\
	ldr r1, [r4, #4]\n\
	ldr r0, [r1, #0x54]\n\
	str r0, [r2, #0x54]\n\
	ldr r0, [r1, #0x58]\n\
	str r0, [r2, #0x58]\n\
_08017FF0:\n\
	str r2, [r4, #4]\n\
_08017FF2:\n\
	adds r4, r6, #0\n\
	cmp r4, #0\n\
	bne _08017F7A\n\
_08017FF8:\n\
	ldr r0, _0801815C @ =gStageEntityManager\n\
	ldr r1, _08018160 @ =0x00000227\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	strb r1, [r0]\n\
_08018002:\n\
	ldr r4, _0801815C @ =gStageEntityManager\n\
	ldr r2, _08018164 @ =0x00000211\n\
	adds r0, r4, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, sl\n\
	beq _08018016\n\
	ldr r0, [sp, #4]\n\
	mov r1, sl\n\
	bl FUN_08018848\n\
_08018016:\n\
	ldr r3, [sp]\n\
	ldr r0, [r3]\n\
	asrs r0, r0, #0xc\n\
	mov sl, r0\n\
	ldr r0, [r3, #4]\n\
	asrs r0, r0, #0xc\n\
	str r0, [sp, #8]\n\
	movs r1, #0x89\n\
	lsls r1, r1, #2\n\
	adds r0, r4, r1\n\
	ldrh r7, [r0]\n\
	mov r1, sl\n\
	subs r1, #0xc\n\
	lsls r0, r7, #3\n\
	mov r2, sb\n\
	adds r3, r0, r2\n\
	ldr r0, [r3]\n\
	cmp r1, r0\n\
	bge _08018056\n\
	adds r4, r1, #0\n\
	adds r2, r4, #0\n\
	adds r1, r3, #0\n\
_08018042:\n\
	subs r1, #8\n\
	subs r7, #1\n\
	ldr r0, [r1]\n\
	cmp r2, r0\n\
	blt _08018042\n\
	lsls r0, r7, #3\n\
	add r0, sb\n\
	ldr r0, [r0]\n\
	cmp r4, r0\n\
	blt _08018066\n\
_08018056:\n\
	adds r7, #1\n\
	mov r0, sl\n\
	subs r0, #0xc\n\
	lsls r1, r7, #3\n\
	add r1, sb\n\
	ldr r1, [r1]\n\
	cmp r0, r1\n\
	bge _08018056\n\
_08018066:\n\
	ldr r3, _0801815C @ =gStageEntityManager\n\
	movs r1, #0x89\n\
	lsls r1, r1, #2\n\
	adds r0, r3, r1\n\
	strh r7, [r0]\n\
	ldr r2, _08018168 @ =0x0000020E\n\
	adds r0, r3, r2\n\
	ldrh r1, [r0]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08018080\n\
	b _0801835A\n\
_08018080:\n\
	lsls r0, r7, #3\n\
	mov r3, sb\n\
	adds r1, r0, r3\n\
	ldr r0, [r1]\n\
	mov r2, sl\n\
	adds r2, #0xc\n\
	str r2, [sp, #0xc]\n\
	cmp r2, r0\n\
	bgt _08018094\n\
	b _0801821A\n\
_08018094:\n\
	adds r5, r1, #0\n\
_08018096:\n\
	movs r3, #4\n\
	ldrsh r4, [r5, r3]\n\
	ldr r1, [sp, #8]\n\
	subs r0, r4, r1\n\
	adds r0, #0xa\n\
	cmp r0, #0x13\n\
	bls _080180A6\n\
	b _0801820C\n\
_080180A6:\n\
	ldr r6, _0801815C @ =gStageEntityManager\n\
	asrs r3, r7, #5\n\
	lsls r2, r3, #2\n\
	adds r2, r2, r6\n\
	movs r1, #0x1f\n\
	ands r1, r7\n\
	movs r0, #1\n\
	mov ip, r0\n\
	lsls r0, r1\n\
	ldr r1, [r2]\n\
	ands r1, r0\n\
	mov sl, r3\n\
	cmp r1, #0\n\
	bne _080180C4\n\
	b _0801820C\n\
_080180C4:\n\
	lsls r1, r4, #0xc\n\
	movs r2, #0x87\n\
	lsls r2, r2, #2\n\
	adds r0, r6, r2\n\
	ldr r0, [r0]\n\
	cmp r1, r0\n\
	bge _080180D4\n\
	b _0801820C\n\
_080180D4:\n\
	movs r3, #0x88\n\
	lsls r3, r3, #2\n\
	adds r0, r6, r3\n\
	ldr r0, [r0]\n\
	cmp r1, r0\n\
	ble _080180E2\n\
	b _0801820C\n\
_080180E2:\n\
	ldr r1, _0801816C @ =0x00000226\n\
	adds r0, r6, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _080180FE\n\
	ldrh r0, [r5, #6]\n\
	lsls r0, r0, #3\n\
	add r0, r8\n\
	ldrb r1, [r0, #5]\n\
	mov r0, ip\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080180FE\n\
	b _0801820C\n\
_080180FE:\n\
	movs r2, #0x83\n\
	lsls r2, r2, #2\n\
	adds r0, r6, r2\n\
	ldrh r0, [r0]\n\
	cmp r0, #1\n\
	bne _0801811A\n\
	ldrh r0, [r5, #6]\n\
	lsls r0, r0, #3\n\
	add r0, r8\n\
	ldrb r1, [r0, #5]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0801820C\n\
_0801811A:\n\
	bl AllocStageEntity\n\
	adds r4, r0, #0\n\
	cmp r4, #0\n\
	beq _0801820C\n\
	ldr r3, _08018160 @ =0x00000227\n\
	adds r0, r6, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _08018170\n\
	ldrh r0, [r5, #6]\n\
	lsls r0, r0, #3\n\
	add r0, r8\n\
	ldrb r0, [r0, #6]\n\
	cmp r0, #0\n\
	beq _08018170\n\
	movs r0, #3\n\
	movs r1, #0x30\n\
	bl CreateStageEntity\n\
	adds r2, r0, #0\n\
	cmp r2, #0\n\
	beq _080181B4\n\
	ldrh r0, [r5, #6]\n\
	lsls r0, r0, #3\n\
	add r0, r8\n\
	ldrb r0, [r0, #6]\n\
	subs r0, #1\n\
	movs r1, #0\n\
	strb r0, [r2, #0x10]\n\
	strb r1, [r2, #0x11]\n\
	b _080181D0\n\
	.align 2, 0\n\
_0801815C: .4byte gStageEntityManager\n\
_08018160: .4byte 0x00000227\n\
_08018164: .4byte 0x00000211\n\
_08018168: .4byte 0x0000020E\n\
_0801816C: .4byte 0x00000226\n\
_08018170:\n\
	ldr r1, _0801819C @ =0x0202FDB9\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	beq _080181A0\n\
	ldrh r0, [r5, #6]\n\
	lsls r0, r0, #3\n\
	add r0, r8\n\
	ldrb r1, [r0, #7]\n\
	cmp r1, #0\n\
	beq _080181A0\n\
	adds r1, #0x1d\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	movs r0, #3\n\
	bl CreateStageEntity\n\
	adds r2, r0, #0\n\
	cmp r2, #0\n\
	beq _080181B4\n\
	movs r0, #0\n\
	strb r0, [r2, #0x10]\n\
	b _080181CE\n\
	.align 2, 0\n\
_0801819C: .4byte 0x0202FDB9\n\
_080181A0:\n\
	ldrh r1, [r5, #6]\n\
	lsls r1, r1, #3\n\
	add r1, r8\n\
	ldrb r0, [r1, #1]\n\
	ldrb r1, [r1, #2]\n\
	bl CreateStageEntity\n\
	adds r2, r0, #0\n\
	cmp r2, #0\n\
	bne _080181BC\n\
_080181B4:\n\
	adds r0, r4, #0\n\
	bl ReleaseStageEntity\n\
	b _0801820C\n\
_080181BC:\n\
	ldrh r0, [r5, #6]\n\
	lsls r0, r0, #3\n\
	add r0, r8\n\
	ldrb r0, [r0, #3]\n\
	strb r0, [r2, #0x10]\n\
	ldrh r0, [r5, #6]\n\
	lsls r0, r0, #3\n\
	add r0, r8\n\
	ldrb r0, [r0, #4]\n\
_080181CE:\n\
	strb r0, [r2, #0x11]\n\
_080181D0:\n\
	ldr r0, [r5]\n\
	lsls r0, r0, #0xc\n\
	movs r3, #0x80\n\
	lsls r3, r3, #4\n\
	adds r0, r0, r3\n\
	str r0, [r2, #0x54]\n\
	movs r1, #4\n\
	ldrsh r0, [r5, r1]\n\
	lsls r0, r0, #0xc\n\
	subs r3, #1\n\
	adds r0, r0, r3\n\
	str r0, [r2, #0x58]\n\
	str r2, [r4, #4]\n\
	strh r7, [r4, #8]\n\
	ldrh r0, [r5, #6]\n\
	lsls r0, r0, #3\n\
	add r0, r8\n\
	ldrb r0, [r0]\n\
	strh r0, [r4, #0xa]\n\
	mov r0, sl\n\
	lsls r2, r0, #2\n\
	ldr r1, _080182B4 @ =gStageEntityManager\n\
	adds r2, r2, r1\n\
	movs r0, #0x1f\n\
	ands r0, r7\n\
	movs r1, #1\n\
	lsls r1, r0\n\
	ldr r0, [r2]\n\
	bics r0, r1\n\
	str r0, [r2]\n\
_0801820C:\n\
	adds r5, #8\n\
	adds r7, #1\n\
	ldr r0, [r5]\n\
	ldr r2, [sp, #0xc]\n\
	cmp r2, r0\n\
	ble _0801821A\n\
	b _08018096\n\
_0801821A:\n\
	ldr r3, [sp]\n\
	ldr r3, [r3]\n\
	mov sl, r3\n\
	ldr r0, [sp]\n\
	ldr r0, [r0, #4]\n\
	str r0, [sp, #8]\n\
	ldr r1, _080182B4 @ =gStageEntityManager\n\
	movs r2, #0x81\n\
	lsls r2, r2, #2\n\
	adds r0, r1, r2\n\
	ldr r4, [r0]\n\
	cmp r4, #0\n\
	bne _08018236\n\
	b _0801835A\n\
_08018236:\n\
	movs r3, #0x89\n\
	lsls r3, r3, #2\n\
	adds r1, r1, r3\n\
	mov r8, r1\n\
_0801823E:\n\
	ldr r6, [r4]\n\
	ldr r2, [r4, #4]\n\
	cmp r2, #0\n\
	beq _08018260\n\
	ldrh r1, [r4, #0xa]\n\
	movs r5, #0x10\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	lsls r0, r0, #0x10\n\
	asrs r3, r0, #0x10\n\
	cmp r3, #0\n\
	beq _080182B8\n\
	ldrb r0, [r2, #0xc]\n\
	cmp r0, #2\n\
	bls _08018260\n\
	movs r0, #0\n\
	str r0, [r4, #4]\n\
_08018260:\n\
	movs r1, #8\n\
	ldrsh r0, [r4, r1]\n\
	mov r2, r8\n\
	ldrh r2, [r2]\n\
	cmp r0, r2\n\
	blt _08018284\n\
	cmp r0, r7\n\
	bge _08018284\n\
	lsls r0, r0, #3\n\
	add r0, sb\n\
	movs r3, #4\n\
	ldrsh r0, [r0, r3]\n\
	ldr r2, [sp, #8]\n\
	asrs r1, r2, #0xc\n\
	subs r0, r0, r1\n\
	adds r0, #0xa\n\
	cmp r0, #0x13\n\
	bls _08018352\n\
_08018284:\n\
	ldrh r1, [r4, #0xa]\n\
	movs r3, #1\n\
	adds r0, r3, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080182AA\n\
	ldrh r1, [r4, #8]\n\
	lsls r2, r1, #0x10\n\
	asrs r2, r2, #0x15\n\
	lsls r2, r2, #2\n\
	ldr r0, _080182B4 @ =gStageEntityManager\n\
	adds r2, r2, r0\n\
	movs r0, #0x1f\n\
	ands r0, r1\n\
	adds r1, r3, #0\n\
	lsls r1, r0\n\
	ldr r0, [r2]\n\
	orrs r0, r1\n\
	str r0, [r2]\n\
_080182AA:\n\
	adds r0, r4, #0\n\
	bl ReleaseStageEntity\n\
	b _08018352\n\
	.align 2, 0\n\
_080182B4: .4byte gStageEntityManager\n\
_080182B8:\n\
	ldrb r0, [r2, #0xc]\n\
	cmp r0, #2\n\
	bls _080182D6\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080182CC\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	strh r0, [r4, #0xa]\n\
_080182CC:\n\
	ldrh r0, [r4, #0xa]\n\
	orrs r0, r5\n\
	strh r0, [r4, #0xa]\n\
	str r3, [r4, #4]\n\
	b _08018352\n\
_080182D6:\n\
	cmp r0, #1\n\
	bls _080182F0\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080182E8\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	strh r0, [r4, #0xa]\n\
_080182E8:\n\
	ldrh r0, [r4, #0xa]\n\
	orrs r0, r5\n\
	strh r0, [r4, #0xa]\n\
	b _08018352\n\
_080182F0:\n\
	movs r0, #0xc\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08018352\n\
	ldr r0, [r2, #0x54]\n\
	mov r1, sl\n\
	subs r0, r0, r1\n\
	movs r3, #0xd0\n\
	lsls r3, r3, #8\n\
	adds r0, r0, r3\n\
	ldr r1, _0801836C @ =0x00019FFF\n\
	cmp r0, r1\n\
	bhi _0801831C\n\
	ldr r0, [r2, #0x58]\n\
	ldr r1, [sp, #8]\n\
	subs r0, r0, r1\n\
	movs r3, #0xc0\n\
	lsls r3, r3, #8\n\
	adds r0, r0, r3\n\
	ldr r1, _08018370 @ =0x00017FFF\n\
	cmp r0, r1\n\
	bls _08018352\n\
_0801831C:\n\
	movs r1, #8\n\
	ldrsh r0, [r4, r1]\n\
	mov r3, r8\n\
	ldrh r3, [r3]\n\
	cmp r0, r3\n\
	blt _08018340\n\
	cmp r0, r7\n\
	bge _08018340\n\
	lsls r0, r0, #3\n\
	add r0, sb\n\
	movs r1, #4\n\
	ldrsh r0, [r0, r1]\n\
	ldr r3, [sp, #8]\n\
	asrs r1, r3, #0xc\n\
	subs r0, r0, r1\n\
	adds r0, #0xa\n\
	cmp r0, #0x13\n\
	bls _08018352\n\
_08018340:\n\
	adds r0, r2, #0\n\
	bl DeleteStageEntity\n\
	ldrh r0, [r4, #0xa]\n\
	movs r1, #0x11\n\
	orrs r0, r1\n\
	strh r0, [r4, #0xa]\n\
	movs r0, #0\n\
	str r0, [r4, #4]\n\
_08018352:\n\
	adds r4, r6, #0\n\
	cmp r4, #0\n\
	beq _0801835A\n\
	b _0801823E\n\
_0801835A:\n\
	add sp, #0x10\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0801836C: .4byte 0x00019FFF\n\
_08018370: .4byte 0x00017FFF\n\
 .syntax divided\n");
}

// Create VolatileEntity or ScriptEntity
struct Entity* CreateStageEntity(u8 kind, u8 id) {
  struct Entity* p;

  switch (kind) {
    case ENTITY_PLAYER: {
      p = (struct Entity*)AllocPlayer();
      if (p != NULL) {
        p->taskCol = 16;
        INIT_PLAYER_ROUTINE((struct Zero*)p, id);
      }
      break;
    }

    case ENTITY_BOSS: {
      p = AllocEntityFirst(gBossHeaderPtr);
      if (p != NULL) {
        p->taskCol = 24;
        INIT_BOSS_ROUTINE((struct Boss*)p, id);
        p->tileNum = 0;
        p->palID = 0;
        p->flags2 |= WHITE_PAINTABLE;
        p->invincibleID = p->uniqueID;
      }
      break;
    }

    case ENTITY_ENEMY: {
      p = AllocEntityFirst(gZakoHeaderPtr);
      if (p != NULL) {
        p->taskCol = 24;
        INIT_ZAKO_ROUTINE((struct Enemy*)p, id);
        p->tileNum = 0;
        p->palID = 0;
        p->flags2 |= WHITE_PAINTABLE;
        p->invincibleID = p->uniqueID;
      }
      break;
    }

    case ENTITY_PROJECTILE: {
      p = AllocEntityFirst(gProjectileHeaderPtr);
      if (p != NULL) {
        p->taskCol = 8;
        INIT_PROJECTILE_ROUTINE((struct Projectile*)p, id);
        p->tileNum = 0;
        p->palID = 0;
      }
      break;
    }

    case ENTITY_VFX: {
      p = AllocEntityFirst(gVFXHeaderPtr);
      if (p != NULL) {
        p->taskCol = 1;
        INIT_VFX_ROUTINE((struct VFX*)p, id);
        p->tileNum = 0;
        p->palID = 0;
      }
      break;
    }

    case ENTITY_SOLID: {
      p = AllocEntityLast(gSolidHeaderPtr);
      if (p != NULL) {
        p->taskCol = 30;
        INIT_SOLID_ROUTINE((struct Solid*)p, id);
        p->tileNum = 0;
        p->palID = 0;
        p->flags2 |= WHITE_PAINTABLE;
        p->invincibleID = p->uniqueID;
      }
      break;
    }

    case ENTITY_ITEM: {
      p = AllocEntityFirst(gPickupHeaderPtr);
      if (p != NULL) {
        p->taskCol = 1;
        INIT_ITEM_ROUTINE((struct Pickup*)p, id);
        p->tileNum = 0;
        p->palID = 0;
        p->flags2 |= WHITE_PAINTABLE;
        p->invincibleID = p->uniqueID;
      }
      break;
    }

    case ENTITY_ELF: {
      p = AllocEntityFirst(gElfHeaderPtr);
      if (p != NULL) {
        p->taskCol = 16;
        INIT_ELF_ROUTINE((struct Elf*)p, id);
        p->tileNum = 0;
        p->palID = 0;
      }
      break;
    }

    case ENTITY_WEAPON:
    default: {
      p = NULL;
      break;
    }
  }

  return p;
}

void DeleteStageEntity(struct CollidableEntity* p) {
  switch ((p->s).kind) {
    case ENTITY_PLAYER: {
      (p->s).flags &= ~DISPLAY;
      (p->s).flags &= ~FLIPABLE;
      (p->body).status = 0;
      (p->body).prevStatus = 0;
      (p->body).invincibleTime = 0;
      (p->s).flags &= ~COLLIDABLE;
      SET_PLAYER_ROUTINE((struct Zero*)p, ENTITY_DISAPPEAR);
      break;
    }

    case ENTITY_WEAPON: {
      break;
    }

    case ENTITY_BOSS: {
      (p->s).flags &= ~DISPLAY;
      (p->s).flags &= ~FLIPABLE;
      (p->body).status = 0;
      (p->body).prevStatus = 0;
      (p->body).invincibleTime = 0;
      (p->s).flags &= ~COLLIDABLE;
      SET_BOSS_ROUTINE((struct Boss*)p, ENTITY_DISAPPEAR);
      break;
    }

    case ENTITY_ENEMY: {
      (p->s).flags &= ~DISPLAY;
      (p->s).flags &= ~FLIPABLE;
      (p->body).status = 0;
      (p->body).prevStatus = 0;
      (p->body).invincibleTime = 0;
      (p->s).flags &= ~COLLIDABLE;
      SET_ZAKO_ROUTINE((struct Enemy*)p, ENTITY_DISAPPEAR);
      break;
    }

    case ENTITY_PROJECTILE: {
      (p->s).flags &= ~DISPLAY;
      (p->s).flags &= ~FLIPABLE;
      (p->body).status = 0;
      (p->body).prevStatus = 0;
      (p->body).invincibleTime = 0;
      (p->s).flags &= ~COLLIDABLE;
      SET_PROJECTILE_ROUTINE((struct Projectile*)p, ENTITY_DISAPPEAR);
      break;
    }

    case ENTITY_VFX: {
      (p->s).flags &= ~DISPLAY;
      (p->s).flags &= ~FLIPABLE;
      SET_VFX_ROUTINE((struct VFX*)p, ENTITY_DISAPPEAR);
      break;
    }

    case ENTITY_SOLID: {
      (p->s).flags &= ~DISPLAY;
      (p->s).flags &= ~FLIPABLE;
      (p->body).status = 0;
      (p->body).prevStatus = 0;
      (p->body).invincibleTime = 0;
      (p->s).flags &= ~COLLIDABLE;
      SET_SOLID_ROUTINE((struct Solid*)p, ENTITY_DISAPPEAR);
      break;
    }

    case ENTITY_ITEM: {
      (p->s).flags &= ~DISPLAY;
      (p->s).flags &= ~FLIPABLE;
      (p->body).status = 0;
      (p->body).prevStatus = 0;
      (p->body).invincibleTime = 0;
      (p->s).flags &= ~COLLIDABLE;
      SET_ITEM_ROUTINE((struct Pickup*)p, ENTITY_DISAPPEAR);
      break;
    }

    case ENTITY_ELF: {
      (p->s).flags &= ~DISPLAY;
      (p->s).flags &= ~FLIPABLE;
      (p->body).status = 0;
      (p->body).prevStatus = 0;
      (p->body).invincibleTime = 0;
      (p->s).flags &= ~COLLIDABLE;
      SET_ELF_ROUTINE((struct Elf*)p, ENTITY_DISAPPEAR);
      break;
    }
  }
}

void FUN_080186c8(u32 top, u32 bottom) {
  struct StageEntity* p;
  const struct EntityTemplateCoord* c;
  gStageEntityManager.dynamicEntityRange[0] = top;
  gStageEntityManager.dynamicEntityRange[1] = bottom;
  c = gStageEntityManager.templateCoord;

  p = gStageEntityManager.list;
  while (p != NULL) {
    struct StageEntity* next = p->next;
    struct CollidableEntity* e = (struct CollidableEntity*)p->e;

    if (e != NULL && !(p->flag & (1 << 4))) {
      const s32 y = c[p->idx].y * 0x1000;
      if (y < gStageEntityManager.dynamicEntityRange[0] || y > gStageEntityManager.dynamicEntityRange[1]) {
        if (p->flag & 0x05) {
          gStageEntityManager.entityEnabled[p->idx >> 5] |= 1 << (p->idx & 0x1F);
        }
        DeleteStageEntity(e);
        ReleaseStageEntity(p);
      }
    }

    p = next;
  }
}

static void ReleaseAllStageEntities(void) {
  s32 i;
  gStageEntityManager.free = NULL;
  for (i = 0; i < 32; i++) {
    gStageEntityManager.unk_084[i].next = gStageEntityManager.free;
    gStageEntityManager.free = &gStageEntityManager.unk_084[i];
  }
  gStageEntityManager.list = NULL;
  gStageEntityManager.remaining = 32;
}

static struct StageEntity* AllocStageEntity(void) {
  struct StageEntity* newObj;
  struct StageEntity** next;
  if (gStageEntityManager.remaining == 0) {
    return NULL;
  }
  gStageEntityManager.remaining--;
  newObj = gStageEntityManager.free;
  next = &newObj->next;
  gStageEntityManager.free = (gStageEntityManager.free)->next;
  *next = gStageEntityManager.list;
  gStageEntityManager.list = newObj;
  return newObj;
}

static void ReleaseStageEntity(struct StageEntity* p) {
  struct StageEntity* p1 = gStageEntityManager.list;
  struct StageEntity* p2 = gStageEntityManager.list;
  while (p1 != p) {
    p2 = p1;
    p1 = p2->next;
  }

  if (p1 == p2) {
    gStageEntityManager.list = p->next;
  } else {
    p2->next = p->next;
  }

  p->next = gStageEntityManager.free;
  gStageEntityManager.free = p;
  gStageEntityManager.remaining++;
}

NAKED static void FUN_08018848(u8 stageID, u8 area) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x14\n\
	lsls r0, r0, #0x18\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	str r1, [sp, #8]\n\
	ldr r1, _08018AF0 @ =sStagePreloadEntities\n\
	lsrs r0, r0, #0x16\n\
	str r0, [sp, #0xc]\n\
	adds r0, r0, r1\n\
	ldr r7, [r0]\n\
	ldr r2, _08018AF4 @ =0x0202FDA1\n\
	ldrb r0, [r2]\n\
	cmp r0, #0xff\n\
	beq _08018870\n\
	b _08018A6E\n\
_08018870:\n\
	ldr r6, _08018AF8 @ =gStaticMotionGraphics\n\
	ldr r0, _08018AFC @ =wStaticGraphicTilenums\n\
	mov r8, r0\n\
	ldrh r1, [r0]\n\
	ldrh r0, [r6, #6]\n\
	lsrs r0, r0, #6\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	adds r0, r6, #0\n\
	bl LoadGraphic\n\
	ldr r0, _08018B00 @ =gStaticMotionGraphics+12\n\
	mov sb, r0\n\
	ldr r2, _08018B04 @ =wStaticMotionPalIDs\n\
	ldrh r1, [r2]\n\
	ldrb r0, [r0, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	mov r0, sb\n\
	bl LoadPalette\n\
	adds r0, r6, #0\n\
	adds r0, #0x28\n\
	mov r2, r8\n\
	ldrh r1, [r2, #4]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	mov r0, sb\n\
	adds r0, #0x28\n\
	ldr r2, _08018B04 @ =wStaticMotionPalIDs\n\
	ldrh r1, [r2, #4]\n\
	ldrb r2, [r0, #7]\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	bl LoadPalette\n\
	adds r0, r6, #0\n\
	adds r0, #0x3c\n\
	mov r2, r8\n\
	ldrh r1, [r2, #6]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	mov r0, sb\n\
	adds r0, #0x3c\n\
	ldr r2, _08018B04 @ =wStaticMotionPalIDs\n\
	ldrh r1, [r2, #6]\n\
	ldrb r2, [r0, #7]\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	bl LoadPalette\n\
	ldr r5, _08018B08 @ =0x00001054\n\
	adds r0, r5, r6\n\
	movs r4, #0xd1\n\
	lsls r4, r4, #1\n\
	mov r2, r8\n\
	adds r1, r2, r4\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	add r5, sb\n\
	ldr r0, _08018B04 @ =wStaticMotionPalIDs\n\
	adds r4, r0, r4\n\
	ldrh r1, [r4]\n\
	ldrb r0, [r5, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r5, #0\n\
	bl LoadPalette\n\
	ldr r0, _08018B0C @ =gSystemSavedataManager\n\
	mov sl, r0\n\
	adds r0, #0x49\n\
	ldrb r4, [r0]\n\
	adds r4, #0xa7\n\
	lsls r5, r4, #2\n\
	adds r5, r5, r4\n\
	lsls r5, r5, #2\n\
	adds r0, r5, r6\n\
	lsls r4, r4, #1\n\
	mov r2, r8\n\
	adds r1, r4, r2\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	add r5, sb\n\
	ldr r0, _08018B04 @ =wStaticMotionPalIDs\n\
	adds r4, r4, r0\n\
	ldrh r1, [r4]\n\
	ldrb r0, [r5, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r5, #0\n\
	bl LoadPalette\n\
	mov r0, sl\n\
	adds r0, #0x4a\n\
	ldrb r4, [r0]\n\
	adds r4, #0xaa\n\
	lsls r5, r4, #2\n\
	adds r5, r5, r4\n\
	lsls r5, r5, #2\n\
	adds r0, r5, r6\n\
	lsls r4, r4, #1\n\
	mov r2, r8\n\
	adds r1, r4, r2\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	add r5, sb\n\
	ldr r0, _08018B04 @ =wStaticMotionPalIDs\n\
	adds r4, r4, r0\n\
	ldrh r1, [r4]\n\
	ldrb r0, [r5, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r5, #0\n\
	bl LoadPalette\n\
	mov r0, sl\n\
	adds r0, #0x4c\n\
	ldrb r4, [r0]\n\
	adds r4, #0xad\n\
	lsls r5, r4, #2\n\
	adds r5, r5, r4\n\
	lsls r5, r5, #2\n\
	adds r0, r5, r6\n\
	lsls r4, r4, #1\n\
	mov r2, r8\n\
	adds r1, r4, r2\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	add r5, sb\n\
	ldr r0, _08018B04 @ =wStaticMotionPalIDs\n\
	adds r4, r4, r0\n\
	ldrh r1, [r4]\n\
	ldrb r0, [r5, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r5, #0\n\
	bl LoadPalette\n\
	mov r0, sl\n\
	adds r0, #0x4b\n\
	ldrb r4, [r0]\n\
	adds r4, #0xb0\n\
	lsls r5, r4, #2\n\
	adds r5, r5, r4\n\
	lsls r5, r5, #2\n\
	adds r6, r5, r6\n\
	lsls r4, r4, #1\n\
	add r8, r4\n\
	mov r0, r8\n\
	ldrh r1, [r0]\n\
	ldrh r0, [r6, #6]\n\
	lsrs r0, r0, #6\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	adds r0, r6, #0\n\
	bl LoadGraphic\n\
	add r5, sb\n\
	ldr r0, _08018B04 @ =wStaticMotionPalIDs\n\
	adds r4, r4, r0\n\
	ldrh r1, [r4]\n\
	ldrb r0, [r5, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r5, #0\n\
	bl LoadPalette\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	ldr r1, _08018B10 @ =0x03002E60\n\
	str r0, [sp]\n\
	ldr r2, _08018B14 @ =0x01000008\n\
	mov r0, sp\n\
	bl CpuFastSet\n\
	movs r0, #0xfe\n\
	ldr r1, _08018AF4 @ =0x0202FDA1\n\
	strb r0, [r1]\n\
_08018A6E:\n\
	ldr r2, _08018B18 @ =gStageEntityManager\n\
	ldr r1, _08018B1C @ =0x0000020E\n\
	adds r0, r2, r1\n\
	ldrh r1, [r0]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	adds r4, r2, #0\n\
	cmp r0, #0\n\
	beq _08018A82\n\
	b _08018BDE\n\
_08018A82:\n\
	ldr r2, _08018AF4 @ =0x0202FDA1\n\
	ldrb r0, [r2]\n\
	ldr r5, [sp, #0xc]\n\
	cmp r0, #0xfe\n\
	bne _08018AB2\n\
	ldrb r0, [r7]\n\
	cmp r0, #0xff\n\
	beq _08018AB2\n\
	ldr r3, _08018AFC @ =wStaticGraphicTilenums\n\
	ldr r2, _08018B04 @ =wStaticMotionPalIDs\n\
_08018A96:\n\
	ldrb r0, [r7]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r3\n\
	ldrh r1, [r7, #2]\n\
	strh r1, [r0]\n\
	ldrb r0, [r7]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	ldrb r1, [r7, #4]\n\
	strh r1, [r0]\n\
	adds r7, #8\n\
	ldrb r0, [r7]\n\
	cmp r0, #0xff\n\
	bne _08018A96\n\
_08018AB2:\n\
	ldr r0, _08018B20 @ =0x0000022A\n\
	adds r1, r4, r0\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	ldr r2, _08018AF0 @ =sStagePreloadEntities\n\
	adds r0, r5, r2\n\
	ldr r7, [r0]\n\
	ldrb r0, [r7]\n\
	cmp r0, #0xff\n\
	bne _08018AC8\n\
	b _08018BD4\n\
_08018AC8:\n\
	movs r6, #1\n\
	adds r3, r1, #0\n\
	ldr r0, _08018AFC @ =wStaticGraphicTilenums\n\
	mov sb, r0\n\
	ldr r1, _08018B04 @ =wStaticMotionPalIDs\n\
	mov r8, r1\n\
_08018AD4:\n\
	ldrb r0, [r7, #1]\n\
	ldr r2, [sp, #8]\n\
	asrs r0, r2\n\
	ands r0, r6\n\
	cmp r0, #0\n\
	beq _08018BC8\n\
	ldr r1, _08018B24 @ =0x00000227\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _08018B28\n\
	ldrb r1, [r7, #5]\n\
	movs r0, #2\n\
	b _08018B2C\n\
	.align 2, 0\n\
_08018AF0: .4byte sStagePreloadEntities\n\
_08018AF4: .4byte 0x0202FDA1\n\
_08018AF8: .4byte gStaticMotionGraphics\n\
_08018AFC: .4byte wStaticGraphicTilenums\n\
_08018B00: .4byte gStaticMotionGraphics+12\n\
_08018B04: .4byte wStaticMotionPalIDs\n\
_08018B08: .4byte 0x00001054\n\
_08018B0C: .4byte gSystemSavedataManager\n\
_08018B10: .4byte 0x03002E60\n\
_08018B14: .4byte 0x01000008\n\
_08018B18: .4byte gStageEntityManager\n\
_08018B1C: .4byte 0x0000020E\n\
_08018B20: .4byte 0x0000022A\n\
_08018B24: .4byte 0x00000227\n\
_08018B28:\n\
	ldrb r1, [r7, #5]\n\
	adds r0, r6, #0\n\
_08018B2C:\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08018BC8\n\
	ldr r2, _08018B44 @ =0x00000229\n\
	adds r0, r4, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _08018B48\n\
	ldrb r1, [r7, #6]\n\
	movs r0, #2\n\
	b _08018B4C\n\
	.align 2, 0\n\
_08018B44: .4byte 0x00000229\n\
_08018B48:\n\
	ldrb r1, [r7, #6]\n\
	adds r0, r6, #0\n\
_08018B4C:\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08018BC8\n\
	ldrb r0, [r7, #7]\n\
	cmp r0, #0\n\
	beq _08018B64\n\
	adds r0, r6, #0\n\
	ldrb r1, [r7, #4]\n\
	lsls r0, r1\n\
	ldrh r1, [r3]\n\
	orrs r0, r1\n\
	b _08018B6E\n\
_08018B64:\n\
	adds r1, r6, #0\n\
	ldrb r2, [r7, #4]\n\
	lsls r1, r2\n\
	ldrh r0, [r3]\n\
	bics r0, r1\n\
_08018B6E:\n\
	strh r0, [r3]\n\
	ldrb r0, [r7]\n\
	lsls r0, r0, #1\n\
	add r0, sb\n\
	ldrh r1, [r7, #2]\n\
	strh r1, [r0]\n\
	ldrb r0, [r7]\n\
	lsls r0, r0, #1\n\
	add r0, r8\n\
	ldrb r1, [r7, #4]\n\
	strh r1, [r0]\n\
	ldrb r4, [r7]\n\
	lsls r5, r4, #2\n\
	adds r5, r5, r4\n\
	lsls r5, r5, #2\n\
	ldr r1, _08018BF0 @ =gStaticMotionGraphics\n\
	adds r0, r5, r1\n\
	lsls r4, r4, #1\n\
	mov r2, sb\n\
	adds r1, r4, r2\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	str r3, [sp, #0x10]\n\
	bl LoadGraphic\n\
	ldr r0, _08018BF4 @ =gStaticMotionGraphics+12\n\
	adds r5, r5, r0\n\
	add r4, r8\n\
	ldrh r1, [r4]\n\
	ldrb r0, [r5, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r5, #0\n\
	bl LoadPalette\n\
	ldr r3, [sp, #0x10]\n\
_08018BC8:\n\
	adds r7, #8\n\
	ldrb r0, [r7]\n\
	ldr r4, _08018BF8 @ =gStageEntityManager\n\
	cmp r0, #0xff\n\
	beq _08018BD4\n\
	b _08018AD4\n\
_08018BD4:\n\
	ldr r1, _08018BFC @ =0x00000211\n\
	adds r0, r4, r1\n\
	mov r2, sp\n\
	ldrb r2, [r2, #8]\n\
	strb r2, [r0]\n\
_08018BDE:\n\
	add sp, #0x14\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08018BF0: .4byte gStaticMotionGraphics\n\
_08018BF4: .4byte gStaticMotionGraphics+12\n\
_08018BF8: .4byte gStageEntityManager\n\
_08018BFC: .4byte 0x00000211\n\
 .syntax divided\n");
}

WIP static void FUN_08018c00(u8 stageID, u8 area) {
#if MODERN
  const struct PreloadEntity* preload;

  for (preload = sStagePreloadEntities[stageID]; preload->id != 0xFF; preload = &preload[1]) {
    if (((preload->habitat >> area) & 1) && (preload->unk_05 & (1 << 1))) {
      u32 val, mask;
      if (gStageEntityManager.unk_226[3] != 0) {
        val = preload->unk_06;
        mask = (1 << 1);
      } else {
        val = preload->unk_06;
        mask = (1 << 0);
      }
      if (val & mask) {
        if (preload->unk_07 != 0) {
          gStageEntityManager.unk_22a |= (1 << preload->palID);
        } else {
          gStageEntityManager.unk_22a &= ~(1 << preload->palID);
        }
        wStaticGraphicTilenums[preload->id] = preload->tileBase;
        wStaticMotionPalIDs[preload->id] = preload->palID;
        LOAD_STATIC_GRAPHIC(preload->id);
      }
    }
  }
#else
  INCCODE("asm/wip/FUN_08018c00.inc");
#endif
}

WIP static void FUN_08018d10(u8 stageID, u8 area) {
#if MODERN
  const struct PreloadEntity* preload;

  for (preload = sStagePreloadEntities[stageID]; preload->id != 0xFF; preload = &preload[1]) {
    if ((preload->habitat >> area) & 1) {
      u32 val, mask;
      if (gStageEntityManager.unk_226[1] != 0) {
        val = preload->unk_05;
        mask = (1 << 1);
      } else {
        val = preload->unk_05;
        mask = (1 << 0);
      }
      if (val & mask) {
        if (preload->unk_06 & (1 << 1)) {
          if (preload->unk_07 != 0) {
            gStageEntityManager.unk_22a |= (1 << preload->palID);
          } else {
            gStageEntityManager.unk_22a &= ~(1 << preload->palID);
          }
          wStaticGraphicTilenums[preload->id] = preload->tileBase;
          wStaticMotionPalIDs[preload->id] = preload->palID;
          LOAD_STATIC_GRAPHIC(preload->id);
        }
      }
    }
  }
#else
  INCCODE("asm/wip/FUN_08018d10.inc");
#endif
}

NAKED static void FUN_08018e20(void) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	ldr r0, _08018F88 @ =gVFXHeaderPtr\n\
	ldr r4, [r0]\n\
	adds r0, r4, #0\n\
	bl ignoreEntityFn\n\
	ldr r0, [r4, #0xc]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0xc]\n\
	adds r2, r0, #0\n\
	adds r0, r4, #0\n\
	adds r0, #0x14\n\
	cmp r2, r0\n\
	beq _08018E76\n\
	ldr r3, _08018F8C @ =gVFXFnTable\n\
_08018E3E:\n\
	ldrb r0, [r2, #0xc]\n\
	cmp r0, #2\n\
	bhi _08018E66\n\
	ldrb r0, [r2, #9]\n\
	cmp r0, #0x20\n\
	bne _08018E66\n\
	ldrb r1, [r2, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r2, #0xa]\n\
	ldrb r1, [r2, #9]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r3\n\
	movs r0, #3\n\
	str r0, [r2, #0xc]\n\
	ldr r0, [r1]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r2, #0x14]\n\
_08018E66:\n\
	ldr r0, [r4, #0xc]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0xc]\n\
	adds r2, r0, #0\n\
	adds r0, r4, #0\n\
	adds r0, #0x14\n\
	cmp r2, r0\n\
	bne _08018E3E\n\
_08018E76:\n\
	ldr r0, _08018F90 @ =gProjectileHeaderPtr\n\
	ldr r4, [r0]\n\
	adds r0, r4, #0\n\
	bl ignoreEntityFn\n\
	ldr r0, [r4, #0xc]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0xc]\n\
	adds r2, r0, #0\n\
	adds r0, r4, #0\n\
	adds r0, #0x14\n\
	cmp r2, r0\n\
	beq _08018EF2\n\
	movs r3, #0\n\
	ldr r5, _08018F94 @ =gProjectileFnTable\n\
_08018E94:\n\
	ldrb r0, [r2, #0xc]\n\
	cmp r0, #2\n\
	bhi _08018EE2\n\
	ldrb r1, [r2, #9]\n\
	subs r0, r1, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #2\n\
	bls _08018EB0\n\
	adds r0, r1, #0\n\
	cmp r0, #6\n\
	beq _08018EB0\n\
	cmp r0, #8\n\
	bne _08018EE2\n\
_08018EB0:\n\
	ldrb r1, [r2, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r2, #0xa]\n\
	adds r0, r2, #0\n\
	adds r0, #0x8c\n\
	str r3, [r0]\n\
	adds r0, #4\n\
	str r3, [r0]\n\
	adds r0, #4\n\
	strb r3, [r0]\n\
	ldrb r1, [r2, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r2, #0xa]\n\
	ldrb r1, [r2, #9]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r5\n\
	movs r0, #3\n\
	str r0, [r2, #0xc]\n\
	ldr r0, [r1]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r2, #0x14]\n\
_08018EE2:\n\
	ldr r0, [r4, #0xc]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0xc]\n\
	adds r2, r0, #0\n\
	adds r0, r4, #0\n\
	adds r0, #0x14\n\
	cmp r2, r0\n\
	bne _08018E94\n\
_08018EF2:\n\
	ldr r0, _08018F98 @ =gZakoHeaderPtr\n\
	ldr r4, [r0]\n\
	adds r0, r4, #0\n\
	bl ignoreEntityFn\n\
	ldr r0, [r4, #0xc]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0xc]\n\
	adds r2, r0, #0\n\
	adds r0, r4, #0\n\
	adds r0, #0x14\n\
	cmp r2, r0\n\
	beq _08018F80\n\
	movs r3, #0\n\
	ldr r5, _08018F9C @ =gEnemyFnTable\n\
_08018F10:\n\
	ldrb r0, [r2, #0xc]\n\
	cmp r0, #2\n\
	bhi _08018F70\n\
	ldrb r0, [r2, #9]\n\
	cmp r0, #0xb\n\
	beq _08018F20\n\
	cmp r0, #0x16\n\
	bne _08018F2E\n\
_08018F20:\n\
	ldrb r1, [r2, #0x10]\n\
	cmp r1, #1\n\
	beq _08018F3E\n\
	cmp r0, #0x16\n\
	bne _08018F2E\n\
	cmp r1, #2\n\
	beq _08018F3E\n\
_08018F2E:\n\
	ldrb r1, [r2, #9]\n\
	cmp r1, #0x36\n\
	bne _08018F3A\n\
	ldrb r0, [r2, #0x10]\n\
	cmp r0, #1\n\
	beq _08018F3E\n\
_08018F3A:\n\
	cmp r1, #0x1c\n\
	bne _08018F70\n\
_08018F3E:\n\
	ldrb r1, [r2, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r2, #0xa]\n\
	adds r0, r2, #0\n\
	adds r0, #0x8c\n\
	str r3, [r0]\n\
	adds r0, #4\n\
	str r3, [r0]\n\
	adds r0, #4\n\
	strb r3, [r0]\n\
	ldrb r1, [r2, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r2, #0xa]\n\
	ldrb r1, [r2, #9]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r5\n\
	movs r0, #3\n\
	str r0, [r2, #0xc]\n\
	ldr r0, [r1]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r2, #0x14]\n\
_08018F70:\n\
	ldr r0, [r4, #0xc]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0xc]\n\
	adds r2, r0, #0\n\
	adds r0, r4, #0\n\
	adds r0, #0x14\n\
	cmp r2, r0\n\
	bne _08018F10\n\
_08018F80:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08018F88: .4byte gVFXHeaderPtr\n\
_08018F8C: .4byte gVFXFnTable\n\
_08018F90: .4byte gProjectileHeaderPtr\n\
_08018F94: .4byte gProjectileFnTable\n\
_08018F98: .4byte gZakoHeaderPtr\n\
_08018F9C: .4byte gEnemyFnTable\n\
 .syntax divided\n");
}

NAKED static void FUN_08018fa0(void) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	ldr r0, _080190E0 @ =gVFXHeaderPtr\n\
	ldr r4, [r0]\n\
	adds r0, r4, #0\n\
	bl ignoreEntityFn\n\
	ldr r0, [r4, #0xc]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0xc]\n\
	adds r2, r0, #0\n\
	adds r0, r4, #0\n\
	adds r0, #0x14\n\
	cmp r2, r0\n\
	beq _08018FF6\n\
	ldr r3, _080190E4 @ =gVFXFnTable\n\
_08018FBE:\n\
	ldrb r0, [r2, #0xc]\n\
	cmp r0, #2\n\
	bhi _08018FE6\n\
	ldrb r0, [r2, #9]\n\
	cmp r0, #0x2c\n\
	bne _08018FE6\n\
	ldrb r1, [r2, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r2, #0xa]\n\
	ldrb r1, [r2, #9]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r3\n\
	movs r0, #3\n\
	str r0, [r2, #0xc]\n\
	ldr r0, [r1]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r2, #0x14]\n\
_08018FE6:\n\
	ldr r0, [r4, #0xc]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0xc]\n\
	adds r2, r0, #0\n\
	adds r0, r4, #0\n\
	adds r0, #0x14\n\
	cmp r2, r0\n\
	bne _08018FBE\n\
_08018FF6:\n\
	ldr r0, _080190E8 @ =gProjectileHeaderPtr\n\
	ldr r4, [r0]\n\
	adds r0, r4, #0\n\
	bl ignoreEntityFn\n\
	ldr r0, [r4, #0xc]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0xc]\n\
	adds r2, r0, #0\n\
	adds r0, r4, #0\n\
	adds r0, #0x14\n\
	cmp r2, r0\n\
	beq _08019068\n\
	movs r3, #0\n\
	ldr r5, _080190EC @ =gProjectileFnTable\n\
_08019014:\n\
	ldrb r0, [r2, #0xc]\n\
	cmp r0, #2\n\
	bhi _08019058\n\
	ldrb r0, [r2, #9]\n\
	subs r0, #0x10\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bhi _08019058\n\
	ldrb r1, [r2, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r2, #0xa]\n\
	adds r0, r2, #0\n\
	adds r0, #0x8c\n\
	str r3, [r0]\n\
	adds r0, #4\n\
	str r3, [r0]\n\
	adds r0, #4\n\
	strb r3, [r0]\n\
	ldrb r1, [r2, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r2, #0xa]\n\
	ldrb r1, [r2, #9]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r5\n\
	movs r0, #3\n\
	str r0, [r2, #0xc]\n\
	ldr r0, [r1]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r2, #0x14]\n\
_08019058:\n\
	ldr r0, [r4, #0xc]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0xc]\n\
	adds r2, r0, #0\n\
	adds r0, r4, #0\n\
	adds r0, #0x14\n\
	cmp r2, r0\n\
	bne _08019014\n\
_08019068:\n\
	ldr r0, _080190F0 @ =gZakoHeaderPtr\n\
	ldr r4, [r0]\n\
	adds r0, r4, #0\n\
	bl ignoreEntityFn\n\
	ldr r0, [r4, #0xc]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0xc]\n\
	adds r2, r0, #0\n\
	adds r0, r4, #0\n\
	adds r0, #0x14\n\
	cmp r2, r0\n\
	beq _080190DA\n\
	movs r3, #0\n\
	ldr r5, _080190F4 @ =gEnemyFnTable\n\
_08019086:\n\
	ldrb r0, [r2, #0xc]\n\
	cmp r0, #2\n\
	bhi _080190CA\n\
	ldrb r0, [r2, #9]\n\
	subs r0, #0x1e\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #2\n\
	bhi _080190CA\n\
	ldrb r1, [r2, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r2, #0xa]\n\
	adds r0, r2, #0\n\
	adds r0, #0x8c\n\
	str r3, [r0]\n\
	adds r0, #4\n\
	str r3, [r0]\n\
	adds r0, #4\n\
	strb r3, [r0]\n\
	ldrb r1, [r2, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r2, #0xa]\n\
	ldrb r1, [r2, #9]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r5\n\
	movs r0, #3\n\
	str r0, [r2, #0xc]\n\
	ldr r0, [r1]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r2, #0x14]\n\
_080190CA:\n\
	ldr r0, [r4, #0xc]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0xc]\n\
	adds r2, r0, #0\n\
	adds r0, r4, #0\n\
	adds r0, #0x14\n\
	cmp r2, r0\n\
	bne _08019086\n\
_080190DA:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080190E0: .4byte gVFXHeaderPtr\n\
_080190E4: .4byte gVFXFnTable\n\
_080190E8: .4byte gProjectileHeaderPtr\n\
_080190EC: .4byte gProjectileFnTable\n\
_080190F0: .4byte gZakoHeaderPtr\n\
_080190F4: .4byte gEnemyFnTable\n\
 .syntax divided\n");
}
