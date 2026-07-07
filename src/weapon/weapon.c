#include "weapon.h"

#include "collision.h"
#include "entity.h"
#include "gfx.h"
#include "global.h"
#include "renderer.h"
#include "zero.h"

#define SLOT_4BPP 16

static const rgb555 gWeaponPalettes[5][SLOT_4BPP];

void InitWeaponHeader(struct EntityHeader* h, struct Weapon* w, s16 len) {
  s16 i;
  u16 j;

  InitEntityHeader(h, ENTITY_WEAPON, &w->s, sizeof(struct Weapon), len);
  for (i = 0; i < len; i++) {
    w[i].s.uniqueID = gEntityIDGenerator + i;
  }
  gEntityIDGenerator += len;
  gWeaponHeaderPtr = h;
  for (j = 0; j < 4; j++) {
    gLastWeaponElements[j] = gWeaponElements[j] = 0xFFFF;
  }
}

void DrawWeapon(Renderer* r) {
  u16 i;
  for (i = 0; i < 4; i++) {
    if (gLastWeaponElements[i] != gWeaponElements[i]) {
      gLastWeaponElements[i] = gWeaponElements[i];
      CpuFastCopy(gWeaponPalettes[gLastWeaponElements[i]], &gPaletteManager.buf[gWeaponPalIDs[i] * SLOT_4BPP + 256], 32);
    }
  }
  DrawEntity(gWeaponHeaderPtr, r);
}

void DeleteWeapon(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_WEAPON_ROUTINE(p, ENTITY_EXIT);
}

/*
  Buster(0): Element effected
  Saber(1):  Element effected
  Rod(2):    No effected
  Shield(3): No effected
*/
void SetWeaponElement(u16 weaponKind, u16 element) {
  gWeaponElements[weaponKind & 0xFFFE] = element;
  return;
}

// run kill(p) for all weapon entities (mainly clean up all weapons)
void KillAllWeapons(WeaponFunc kill) {
  struct EntityHeader* h = gWeaponHeaderPtr;
  struct Entity* p = GetEntityList(h);
  while (p != (struct Entity*)&h->tail) {
    kill((struct Weapon*)p);
    p = GetNextEntity(h);
  }
}

// ------------------------------------------------------------------------------------------------------------------------------------

const u16 gWeaponTileNum[4] = {
    0,
    48,
    512 + 48,
    512 + 96,
};

const u8 gWeaponPalIDs[4] = {1, 1, 5, 5};

// clang-format off
static const ALIGNED(4) rgb555 gWeaponPalettes[5][SLOT_4BPP] = {
  //                         0          1               2                3                4                 5                6                7                 8                9                 10                11                12                13                14                15
  [WEAPON_COLOR_NORMAL]  = { RGB_BLACK, RGBg(0, 5, 13), RGBg(8, 12, 17), RGB(18, 22, 26), RGBg(30, 30, 30), RGBg(28, 22, 0), RGBg(31, 28, 4), RGBg(31, 31, 20), RGBg(8, 28,  0), RGBg(18, 31, 15), RGBg(21, 31, 30), RGBg( 8, 28,  0),  RGB(18, 31, 16), RGBg(21, 31, 30), RGBg(31, 29, 31), RGBg(31, 31, 31) },
  [WEAPON_COLOR_THUNDER] = { RGB_BLACK, RGBg(0, 5, 13), RGBg(8, 12, 17), RGB(18, 22, 26), RGBg(30, 30, 30), RGBg(28, 22, 0), RGBg(31, 28, 4), RGBg(31, 31, 20), RGBg(8, 28,  0), RGBg(18, 31, 15), RGBg(21, 31, 30), RGBg(18, 31, 22), RGBg(31, 31, 20), RGBg(31, 31, 27), RGBg(31, 31, 22), RGBg(31, 31, 31) },
  [WEAPON_COLOR_FLAME]   = { RGB_BLACK, RGBg(0, 5, 13), RGBg(8, 12, 17), RGB(18, 22, 26), RGBg(30, 30, 30), RGBg(28, 22, 0), RGBg(31, 28, 4), RGBg(31, 31, 20), RGBg(8, 28,  0), RGBg(18, 31, 15), RGBg(21, 31, 30), RGBg(31, 18,  0),  RGB(31, 24,  0), RGBg(31, 31, 11), RGBg(31, 28, 31), RGBg(31, 31, 31) },
  [WEAPON_COLOR_ICE]     = { RGB_BLACK, RGBg(0, 5, 13), RGBg(8, 12, 17), RGB(18, 22, 26), RGBg(30, 30, 30), RGBg(28, 22, 0), RGBg(31, 28, 4), RGBg(31, 31, 20), RGBg(8, 28,  0), RGBg(18, 31, 15), RGBg(21, 31, 30),  RGB( 7, 24, 31), RGBg(16, 28, 31),  RGB(21, 30, 31), RGBg(28, 31, 31), RGBg(31, 31, 31) },
  [WEAPON_COLOR_OMEGA]   = { RGB_BLACK, RGBg(0, 5, 13), RGBg(8, 12, 17), RGB(18, 22, 26), RGBg(30, 30, 30), RGBg(28, 22, 0), RGBg(31, 28, 4), RGBg(31, 31, 20), RGBg(31, 5, 26),  RGB(31, 15, 31),  RGB(31, 22, 31),  RGB(31,  0, 17), RGBg(31,  5, 26),  RGB(31, 15, 31),  RGB(31, 22, 31), RGBg(31, 29, 31) },
}; // 0x0835ed68
// clang-format on

extern const WeaponRoutine gBusterRoutine;
extern const WeaponRoutine gSaberRoutine;
extern const WeaponRoutine gShieldGuardRoutine;
extern const WeaponRoutine gRodRoutine;
extern const WeaponRoutine gShieldFlyRoutine;
extern const WeaponRoutine gSaberWaveRoutine;
extern const WeaponRoutine gWeapon6Routine;
extern const WeaponRoutine gReflectLaserRoutine;
extern const WeaponRoutine gSoulLauncherRoutine;
extern const WeaponRoutine gBurstShotRoutine;
extern const WeaponRoutine gBlizzardArrowRoutine;
extern const WeaponRoutine gThrowBladeRoutine;
extern const WeaponRoutine gShieldSweepRoutine;
extern const WeaponRoutine gWeapon13Routine;
extern const WeaponRoutine gSmashElecRoutine;
extern const WeaponRoutine gElecShieldSweepRoutine;
extern const WeaponRoutine gMinigameRodRoutine;

// clang-format off
const WeaponRoutine* const gWeaponFnTable[WEAPON_MOVE_COUNT] = {
    [WEAPON_MOVE_Z_BUSTER] =          &gBusterRoutine,
    [WEAPON_MOVE_Z_SABER] =           &gSaberRoutine,
    [WEAPON_MOVE_SHIELD_GUARD] =      &gShieldGuardRoutine,
    [WEAPON_MOVE_RECOIL_ROD] =        &gRodRoutine,
    [WEAPON_MOVE_SHIELD_FLY] =        &gShieldFlyRoutine,
    [WEAPON_MOVE_SABER_WAVE] =        &gSaberWaveRoutine,
    [WEAPON_MOVE_06] =                &gWeapon6Routine,
    [WEAPON_MOVE_REFLECT_LASER] =     &gReflectLaserRoutine,
    [WEAPON_MOVE_SOUL_LANCHER] =      &gSoulLauncherRoutine,
    [WEAPON_MOVE_BURST_SHOT] =        &gBurstShotRoutine,
    [WEAPON_MOVE_BLIZZARD_ARROW] =    &gBlizzardArrowRoutine,
    [WEAPON_MOVE_ZANEIDAN] =          &gThrowBladeRoutine,
    [WEAPON_MOVE_SHIELD_SWEEP] =      &gShieldSweepRoutine,
    [WEAPON_MOVE_13] =                &gWeapon13Routine,
    [WEAPON_MOVE_RAKUSAIGA] =         &gSmashElecRoutine,
    [WEAPON_MOVE_SHIELD_SWEEP_ELEC] = &gElecShieldSweepRoutine,
    [WEAPON_MOVE_MINIGAME_ROD] =      &gMinigameRodRoutine,
};
// clang-format on
