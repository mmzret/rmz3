#include "entity.h"
#include "global.h"
#include "solid.h"

void ModElf_Die(struct Solid* p);

/*
various:
  00: エルピス
  01: ファントム
*/

static const struct Collision sCollision;

INCASM("asm/solid/mod_elf_a.inc");

void ModElf_Die(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

void ModElf_Init(struct Solid* p);
void ModElf_Update(struct Solid* p);
void ModElf_Die(struct Solid* p);

// clang-format off
const SolidRoutine gModElfRoutine = {
    [ENTITY_INIT] =      (void*)ModElf_Init,
    [ENTITY_UPDATE] =    (void*)ModElf_Update,
    [ENTITY_DIE] =       (void*)ModElf_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static const struct Collision sCollision = {
  kind : DDP,
  faction : FACTION_ENEMY,
  special : CHATABLE,
  damage : 255,
  remaining : 0,
  layer : 0x00000001,
  range : {PIXEL(0), PIXEL(0), PIXEL(36), PIXEL(1)},
};
