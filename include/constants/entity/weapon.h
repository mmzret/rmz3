#ifndef GUARD_RMZ3_CONST_ENT_WEAPON_H
#define GUARD_RMZ3_CONST_ENT_WEAPON_H

// Weapon.id
#define WEAPON_MOVE_Z_BUSTER 0
#define WEAPON_MOVE_Z_SABER 1
#define WEAPON_MOVE_SHIELD_GUARD 2  // シールドブーメラン構え時
#define WEAPON_MOVE_RECOIL_ROD 3
#define WEAPON_MOVE_SHIELD_FLY 4  // 投げてる時のシールドブーメラン
#define WEAPON_MOVE_SABER_WAVE 5
#define WEAPON_MOVE_06 6
#define WEAPON_MOVE_REFLECT_LASER 7
#define WEAPON_MOVE_SOUL_LANCHER 8
#define WEAPON_MOVE_BURST_SHOT 9
#define WEAPON_MOVE_BLIZZARD_ARROW 10
#define WEAPON_MOVE_ZANEIDAN 11
#define WEAPON_MOVE_SHIELD_SWEEP 12
#define WEAPON_MOVE_13 13
#define WEAPON_MOVE_RAKUSAIGA 14
#define WEAPON_MOVE_SHIELD_SWEEP_ELEC 15
#define WEAPON_MOVE_MINIGAME_ROD 16

#define WEAPON_MOVE_COUNT WEAPON_MOVE_MINIGAME_ROD + 1

// ------------------------------------------------------------------------------------------------------------------------------------

// sSaberActions(0835f010)'s idx
#define SABER_TRIPLE_1 0
#define SABER_TRIPLE_2 1
#define SABER_TRIPLE_3 2
#define SABER_WALK 3
#define SABER_DASH 4
#define SABER_AIR 5
#define SABER_WALL 6
#define SABER_LADDER 7
#define SABER_CHARGE 8
#define SABER_CHARGE_AIR 9
#define SABER_CHARGE_WALL 10
#define SABER_CHARGE_LADDER 11
#define SABER_SLASH_UP 12
#define SABER_ZANEIDAN 13    // Throw Blade
#define SABER_TENRETUJIN 14  // Split heavens
#define SABER_TENRETUJIN_FIRE 15
#define SABER_TENRETUJIN_2 16
#define SABER_TENRETUJIN_FIRE_2 17
#define SABER_REPUGEKI 18  // Gale Attack
#define SABER_UNK_19 19
#define SABER_AIR_ROLLING 20
#define SABER_DASH_ROLLING 21
#define SABER_SMASH 22  // ラクサイガ
#define SABER_SMASH_ELEC 23

#define SABER_ACTION_COUNT SABER_SMASH_ELEC + 1

// ------------------------------------------------------------------------------------------------------------------------------------

#endif  // GUARD_RMZ3_CONST_ENT_WEAPON_H
