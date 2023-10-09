#include "global.h"
#include "vfx.h"

INCASM("asm/vfx/unk_37.inc");

void VFX37_Init(struct VFX* vfx);
void VFX37_Update(struct VFX* vfx);
void VFX37_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX37Routine = {
    [ENTITY_INIT] =      VFX37_Init,
    [ENTITY_UPDATE] =    VFX37_Update,
    [ENTITY_DIE] =       VFX37_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void FUN_080bc8c0(struct VFX* vfx);
void FUN_080bc974(struct VFX* vfx);
void FUN_080bca5c(struct VFX* vfx);
void FUN_080bcb6c(struct VFX* vfx);
void FUN_080bcc94(struct VFX* vfx);
void FUN_080bcd9c(struct VFX* vfx);
void FUN_080bce48(struct VFX* vfx);

// clang-format off
const VFXFunc PTR_ARRAY_0836edd4[7] = {
    FUN_080bc8c0,
    FUN_080bc974,
    FUN_080bca5c,
    FUN_080bcb6c,
    FUN_080bcc94,
    FUN_080bcd9c,
    FUN_080bce48,
};
// clang-format on

static const u8 u8_ARRAY_0836edf0[7] = {0, 1, 2, 3, 4, 5, 6};

const motion_t motion_t_ARRAY_0836edf8[3] = {
    MOTION(SM050_CREA_PREA, 0),
    MOTION(SM050_CREA_PREA, 1),
    MOTION(SM050_CREA_PREA, 2),
};

const s16 s16_ARRAY_0836edfe[6] = {
    0x00C0, 0x0080, 0x0010, -0x0080, -0x00C0, -0x0100,
};

const motion_t motion_t_ARRAY_0836ee0a[3] = {
    MOTION(SM050_CREA_PREA, 0),
    MOTION(SM050_CREA_PREA, 1),
    MOTION(SM050_CREA_PREA, 2),
};
