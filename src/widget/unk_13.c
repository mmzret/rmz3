#include "game.h"
#include "global.h"
#include "widget.h"

void MenuComp13_Init(struct Widget *w);
void MenuComp13_Update(struct Widget *w);
void MenuComp13_Die(struct Widget *w);

// clang-format off
const WidgetRoutine gMenuComp13Routine = {
    [ENTITY_INIT] =      MenuComp13_Init,
    [ENTITY_MAIN] =      MenuComp13_Update,
    [ENTITY_DIE] =       MenuComp13_Die,
    [ENTITY_DISAPPEAR] = DeleteWidget,
    [ENTITY_EXIT] =      (WidgetFunc)DeleteEntity,
};
// clang-format on
