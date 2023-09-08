#include "collision.h"
#include "entity.h"
#include "gfx.h"
#include "global.h"
#include "system.h"

IWRAM_DATA struct SystemBuffer gSystemBuffer = {};

IWRAM_DATA u8 Unk_03001584[12] = {};  // 0x03001584..0x0300158f

IWRAM_DATA struct InterruptManager gIntrManager = {};
IWRAM_DATA u8 Unk_03001758[8] = {};
IWRAM_DATA struct ProcessManager gProcessManager = {};
IWRAM_DATA struct PaletteManager gPaletteManager = {};
IWRAM_DATA struct OamManager gOamManager = {};
IWRAM_DATA struct CollisionManager gCollisionManager = {};
IWRAM_DATA struct Projectile gProjectiles[24] = {};
IWRAM_DATA struct Enemy gEnemies[18] = {};
IWRAM_DATA u8 unused_03005948[8] = {};
IWRAM_DATA struct VFX gVFXs[64] = {};
IWRAM_DATA u8 StackUsr[1200] = {};
IWRAM_DATA u8 StackIrq[160] = {};
IWRAM_DATA u8 StackSvc[64] = {};
IWRAM_DATA u8 Unk_03007fe0[16] = {};
IWRAM_DATA struct SoundInfo* SOUND_INFO_PTR = NULL;
IWRAM_DATA u8 AllocatedArea_03007ff4[4] = {};
IWRAM_DATA u16 INTR_CHECK = 0;
IWRAM_DATA u16 unused_03007ffa = 0;
IWRAM_DATA void* INTR_VECTOR = NULL;
