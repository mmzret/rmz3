#include "entity.h"
#include "vfx.h"
#include "global.h"

// アイスボンの氷のキラキラ

INCASM("asm/vfx/icebon_icedust.inc");

static const u8 sInitModes[4];

void IcebonIcedust_Init(struct VFX *p);
void IcebonIcedust_Update(struct VFX *p);
void IcebonIcedust_Die(struct VFX *p);

// clang-format off
const VFXRoutine gIcebonIcedustRoutine = {
    [ENTITY_INIT] =      IcebonIcedust_Init,
    [ENTITY_UPDATE] =    IcebonIcedust_Update,
    [ENTITY_DIE] =       IcebonIcedust_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void ice_080b996c(struct VFX *p);
void ice_080b9a0c(struct VFX *p);

static const VFXFunc sUpdates[2] = {
    ice_080b996c,
    ice_080b9a0c,
};

static const u8 sInitModes[4] = {0, 1, 0, 0};
