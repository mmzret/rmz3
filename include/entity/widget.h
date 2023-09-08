#ifndef GUARD_RMZ3_ENTITY_UI_WIDGET_H
#define GUARD_RMZ3_ENTITY_UI_WIDGET_H

#include "entity/entity.h"

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

struct Widget {
  struct Entity s;
  union {
    u8 raw[16];
    struct Widget2Props widget2;
    struct ArmorIconProps armorIcon;
    struct ExSkillProps exskill;
  } props;
};  // 132 bytes

typedef void (*WidgetFunc)(struct Widget*);
typedef WidgetFunc WidgetRoutine[5];

#endif  // GUARD_RMZ3_ENTITY_UI_WIDGET_H
