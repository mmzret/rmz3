#ifndef GUARD_RMZ3_OW_H
#define GUARD_RMZ3_OW_H

#include "camera.h"
#include "common.h"
#include "entity.h"
#include "overworld_terrain.h"
#include "quake.h"
#include "script.h"
#include "stage.h"
#include "stagerun.h"

#define TILESET_ID(n) (W_TERRAIN_V2.tilesets[n] >> 8)
#define TILESET_IDX(n) ((W_TERRAIN_V2.tilesets[n] & 0xFF))

#endif  // GUARD_RMZ3_OW_H
