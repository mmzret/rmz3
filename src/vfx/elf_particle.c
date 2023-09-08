#include "global.h"
#include "vfx.h"

// サイバーエルフが出すキラキラ

INCASM("asm/vfx/elf_particle.inc");

void ElfParticle_Init(struct VFX* vfx);
void ElfParticle_Update(struct VFX* vfx);
void ElfParticle_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gElfParticleRoutine = {
    [ENTITY_INIT] =      ElfParticle_Init,
    [ENTITY_MAIN] =      ElfParticle_Update,
    [ENTITY_DIE] =       ElfParticle_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080c0160(struct VFX* vfx);
void FUN_080c019c(struct VFX* vfx);

static const VFXFunc sInitializers[2] = {
    FUN_080c0160,
    FUN_080c019c,
};

// --------------------------------------------

void FUN_080c021c(struct VFX* vfx);
void nop_080c0258(struct VFX* vfx);

static const VFXFunc sUpdates[2] = {
    FUN_080c021c,
    nop_080c0258,
};
