#ifndef GUARD_RMZ3_STAGE_H
#define GUARD_RMZ3_STAGE_H

#include "common.h"
#include "entity.h"
#include "overworld_entity.h"
#include "types.h"

typedef u32 (*AreaChecker)(struct Coord*);

extern const struct EntityTemplate gStage0Entity[2];
extern const struct EntityTemplate gSpaceCraftEntity[26];
extern const struct EntityTemplate gVolcanoEntity[51];
extern const struct EntityTemplate gOceanEntity[31];
extern const struct EntityTemplate gRepairFactoryEntity[38];
extern const struct EntityTemplate gOldLifeSpaceEntity[37];
extern const struct EntityTemplate gMissileFactoryEntity[35];
extern const struct EntityTemplate gTwilightDesertEntity[31];
extern const struct EntityTemplate gAnatreForestEntity[34];
extern const struct EntityTemplate gIceBaseEntity[38];
extern const struct EntityTemplate gAreaX2Entity[36];
extern const struct EntityTemplate gEnergyFacilityEntity[51];
extern const struct EntityTemplate gSnowyPlainsEntity[27];
extern const struct EntityTemplate gSunkenLibraryEntity[37];
extern const struct EntityTemplate gGiantElevatorEntity[41];
extern const struct EntityTemplate gSubArcadiaEntity[36];
extern const struct EntityTemplate gWeilLaboEntity[50];
extern const struct EntityTemplate gResistanceBaseEntity[64];

// --------------------------------------------

extern const struct PreloadEntity sStage0StaticTemplate[1];
extern const struct PreloadEntity gSpaceCraftStatic[8];
extern const struct PreloadEntity gVolcanoStatic[20];
extern const struct PreloadEntity gOceanStatic[17];
extern const struct PreloadEntity gRepairFactoryStatic[13];
extern const struct PreloadEntity gOldLifeSpaceStatic[15];
extern const struct PreloadEntity gMissileFactoryStatic[14];
extern const struct PreloadEntity gTwilightDesertStatic[13];
extern const struct PreloadEntity gAnatreForestStatic[16];
extern const struct PreloadEntity gIceBaseStatic[18];
extern const struct PreloadEntity gAreaX2Static[13];
extern const struct PreloadEntity gEnergyFacilityStatic[16];
extern const struct PreloadEntity gSnowyPlainsStatic[13];
extern const struct PreloadEntity gSunkenLibraryStatic[12];
extern const struct PreloadEntity gGiantElevatorStatic[19];
extern const struct PreloadEntity gSubArcadiaStatic[14];
extern const struct PreloadEntity gWeilLaboStatic[13];
extern const struct PreloadEntity gResistanceBaseStatic[41];

// --------------------------------------------

extern const struct EntityTemplateCoord gStage0EntityCoord[2];
extern const struct EntityTemplateCoord gSpaceCraftEntityCoord[68];
extern const struct EntityTemplateCoord gVolcanoEntityCoord[69];
extern const struct EntityTemplateCoord gOceanEntityCoord[86];
extern const struct EntityTemplateCoord gRepairFactoryEntityCoord[73];
extern const struct EntityTemplateCoord gOldLifeSpaceEntityCoord[159];
extern const struct EntityTemplateCoord gMissileFactoryEntityCoord[82];
extern const struct EntityTemplateCoord gTwilightDesertEntityCoord[59];
extern const struct EntityTemplateCoord gAnatreForestEntityCoord[56];
extern const struct EntityTemplateCoord gIceBaseEntityCoord[107];
extern const struct EntityTemplateCoord gAreaX2EntityCoord[88];
extern const struct EntityTemplateCoord gEnergyFacilityEntityCoord[118];
extern const struct EntityTemplateCoord gSnowyPlainsEntityCoord[78];
extern const struct EntityTemplateCoord gSunkenLibraryEntityCoord[99];
extern const struct EntityTemplateCoord gGiantElevatorEntityCoord[65];
extern const struct EntityTemplateCoord gSubArcadiaEntityCoord[62];
extern const struct EntityTemplateCoord gWeilLaboEntityCoord[68];
extern const struct EntityTemplateCoord gResistanceBaseEntityCoord[241];

struct Entity* CreateStageEntity(u8 kind, u8 id);
void DeleteStageEntity(struct CollidableEntity* e);

// clang-format off
extern const AreaChecker gAreaCheckers[STAGE_COUNT];

#endif  // GUARD_RMZ3_STAGE_H
