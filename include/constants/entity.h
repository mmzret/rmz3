#ifndef GUARD_RMZ3_CONST_ENTITY_H
#define GUARD_RMZ3_CONST_ENTITY_H

// Entity.type
#define ENTITY_PLAYER 0
#define ENTITY_WEAPON 1
#define ENTITY_BOSS 2
#define ENTITY_ENEMY 3
#define ENTITY_PROJECTILE 4
#define ENTITY_VFX 5
#define ENTITY_SOLID 6
#define ENTITY_ITEM 7
#define ENTITY_ELF 8
#define ENTITY_WIDGET 9

// Player.id
#include "constants/entity/player.h"

// Enemy.id
#include "constants/entity/enemy.h"

// Solid.id
#include "constants/entity/solid.h"

// Weapon.id
#include "constants/entity/weapon.h"

// Boss.id
#include "constants/entity/boss.h"

// Projectile.id
#define PROJECTILE_LEMON 0
#define PROJECTILE_SHOTCOUNTER_BULLET 1
// ...
#define PROJECTILE_OMEGA_ZERO 38
// ...
#define PROJECTILE_ENTITY_COUNT 48

// VFX.id
#include "constants/entity/vfx.h"

// Pickup.id
#include "constants/entity/item.h"

#endif  // GUARD_RMZ3_CONST_ENTITY_H
