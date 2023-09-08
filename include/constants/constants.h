#ifndef GUARD_RMZ3_CONST_CONST_H
#define GUARD_RMZ3_CONST_CONST_H

#include "constants/boss.h"
#include "constants/charcode.h"
#include "constants/codename.h"
#include "constants/collision.h"
#include "constants/cyberelf.h"
#include "constants/diskno.h"
#include "constants/enemy.h"
#include "constants/entity.h"
#include "constants/exskill.h"
#include "constants/game.h"
#include "constants/item.h"
#include "constants/metatile.h"
#include "constants/minigame.h"
#include "constants/mod.h"
#include "constants/motion.h"
#include "constants/size.h"
#include "constants/solid.h"
#include "constants/song.h"
#include "constants/sound.h"
#include "constants/stage_id.h"
#include "constants/weapon.h"
#include "constants/zero.h"

#define HOUR (60 * MINUTE)
#define MINUTE (60 * SECOND)
#define SECOND 60

// Element ID
#define ELEMENT_NONE -1
#define ELEMENT_THUNDER 1
#define ELEMENT_FLAME 2
#define ELEMENT_ICE 3

// Entity Routine
#define ENTITY_INIT 0
#define ENTITY_MAIN 1
#define ENTITY_DIE 2
#define ENTITY_DISAPPEAR 3
#define ENTITY_EXIT 4

// KEY_INPUT(gStageRun.input, z->last)
#define INPUT_DISABLED 0x8000

// Rank
#define RANK_F 0
#define RANK_E 1
#define RANK_D 2
#define RANK_C 3
#define RANK_B 4
#define RANK_A 5
#define RANK_S 6

#endif  // GUARD_RMZ3_CONST_CONST_H
