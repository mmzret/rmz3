#ifndef GUARD_RMZ3_CONST_COLLISION_H
#define GUARD_RMZ3_CONST_COLLISION_H

// body.hardness, drp.hardness
#define METAL (1 << 0)  // 攻撃が当たった時に金属音がなり、バスターが貫通しなくなる(ダメージは通る)

#define NO_DAMAGE (1 << 1)

// Take 2/3 damage
#define LITTLE_HARD (1 << 2)

#define HARDNESS_B3 (1 << 3)

// Take 2x damage
#define HARDNESS_WEAK (1 << 4)

#endif  // GUARD_RMZ3_CONST_COLLISION_H
