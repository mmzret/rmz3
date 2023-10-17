#ifndef GUARD_RMZ3_CONST_COLLISION_H
#define GUARD_RMZ3_CONST_COLLISION_H

// body.hardness, processing.hardness
#define METAL (1 << 0)  // 攻撃が当たった時に金属音がなり、バスターが貫通しなくなる(ダメージは通る)

#define NO_DAMAGE (1 << 1)

// Take 2/3 damage
#define LITTLE_HARD (1 << 2)

#define HARDNESS_B3 (1 << 3)

// Take 2x damage
#define HARDNESS_WEAK (1 << 4)

// Collision.element
// Dupulicate
// #define ELEMENT_NONE -1
// #define ELEMENT_THUNDER 1
// #define ELEMENT_FLAME 2
// #define ELEMENT_ICE 3
#define RECOIL_PUSHABLE 0x7800

#endif  // GUARD_RMZ3_CONST_COLLISION_H
