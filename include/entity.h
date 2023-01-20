#ifndef GUARD_RMZ3_ENTITY_H
#define GUARD_RMZ3_ENTITY_H

#include "entity/entity.h"
#include "entity/weapon.h"
#include "entity/zero.h"

// size is 40 bytes
struct EntityHeader {
  struct Entity *arr;    // Entityの配列の先頭(固定)
  s16 type;              // Entityの種類
  s16 size;              // .arrの各要素(Entity)のサイズ
  u16 length;            // .arrの要素数(固定)
  s16 remaining;         // .lengthを初期値として徐々に減る
  struct Entity **done;  // fnを .arr のどのEntityまで処理したか だいたいnextを指す
  struct Entity *cur;    // .arr の現在処理中の要素で処理と共に変わる
  struct Entity *next;   // .curの次
  struct Entity *prev;   // .curの1つ前
  u32 unk[3];
};

// 0x02031370
struct EntityHeaders {
  struct EntityHeader zero;           // 02037c60
  struct EntityHeader weapon;         // 02038fd0
  struct EntityHeader boss;           // 0203b6d0
  struct EntityHeader zako;           // 03004b80
  struct EntityHeader atk;            // 03003920
  struct EntityHeader ghost;          // 03005950
  struct EntityHeader solid;          // 0203a5f0
  struct EntityHeader item;           // 02037ef0
  struct EntityHeader elf;            // 02037020
  struct EntityHeader menuComponent;  // 0203bb50
};

#endif  // GUARD_RMZ3_ENTITY_H
