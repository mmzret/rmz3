#ifndef GUARD_RMZ3_OW_H
#define GUARD_RMZ3_OW_H

#include "camera.h"
#include "common.h"
#include "entity.h"
#include "overworld_entity.h"
#include "overworld_misc.h"
#include "overworld_quake.h"
#include "overworld_terrain.h"
#include "script.h"
#include "stage.h"
#include "stagerun.h"

#define TILESET_ID(n) (gOverworld.unk_1c8.tilesets[n] >> 8)
#define TILESET_IDX(n) ((gOverworld.unk_1c8.tilesets[n] & 0xFF))

#endif  // GUARD_RMZ3_OW_H
