#ifndef GUARD_RMZ3_ENTITY_UI_WIDGET_H
#define GUARD_RMZ3_ENTITY_UI_WIDGET_H

#include "entity/entity.h"
#include "types.h"

struct Widget;

struct Widget2Props {
  u16 px;
  u16 py;
  u8 unk_78[12];
};

struct ArmorIconProps {
  struct Widget* w;
  u8 unk_78[12];
};

struct ExSkillProps {
  u8 unk_000[4];
  u8 unk_004[12];
};

struct Widget13Props {
  u8 unk_0[4];
  motion_t unk_4;  // unk_78
  u16 tileNum;
  u8 unk_8;
  u8 unk_9;
  u8 palID;
  u8 unk_b;
  u8 unk_c;
};

struct Widget {
  struct Entity s;
  union {
    u8 raw[16];
    struct Widget2Props widget2;
    struct ArmorIconProps armorIcon;
    struct ExSkillProps exskill;
    struct Widget13Props w13;
  } props;
};  // 132 bytes

typedef void (*WidgetFunc)(struct Widget*);
typedef WidgetFunc WidgetRoutine[5];

#endif  // GUARD_RMZ3_ENTITY_UI_WIDGET_H
