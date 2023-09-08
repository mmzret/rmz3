#include "global.h"
#include "overworld.h"

const struct EntityTemplate gStage0Entity[2] = {
    {},
    {0xF, 0xF, 0xFF, 0xFF, 0xFF, 0, 0, 0},
};

const struct PreloadEntity sStage0StaticTemplate[1] = {
    {0xFF, 0xFF, 0xFFF, 15, 1, 3, 1},
};

const struct EntityTemplateCoord gStage0EntityCoord[2] = {
    {0x80000000, 0x8000, 0},
    {0x7FFFFFFF, 0x7FFF, 0},
};
