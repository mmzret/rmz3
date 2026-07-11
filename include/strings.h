#ifndef __INCLUDE_RMZ3_STRINGS_H__
#define __INCLUDE_RMZ3_STRINGS_H__

#include "gba/gba.h"
#include "types.h"

extern const char_t gStringData[];
extern const u16 StringOfsTable[1096];

typedef u16 StringID;  // StringOfsTable のidx

// StringID
#define STR_CURSOR 0           // "▷"
#define STR_COLON 7            // ":"
#define STR_NUMBER 30          // sNumber, 30..39
#define STR_DISK_NO 800        // sDiskNumbers, 800..980
#define STR_MGRULES 1088       // sMinigameRules, "ルール"
#define STR_MGRULES_ZERO 1089  // Text_MinigameDesc_Zero

#define STRING(string_id) (&gStringData[StringOfsTable[(string_id)]])
#define gStrNumber(num) STRING(STR_NUMBER + (num))

#endif  // __INCLUDE_RMZ3_STRINGS_H__
