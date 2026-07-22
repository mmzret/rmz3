#ifndef GUARD_RMZ3_STRING_IDS_H
#define GUARD_RMZ3_STRING_IDS_H

// Named indices for the STRING(n) macro (text.h): STRING(n) resolves to &gStringData[StringOfsTable[n]].
// e.g. PrintString(STRING(STR_MINIGAME_RULES), x, y); or STRING(STR_RANK + rank) for the "Lv.<rank>" label.

#define STR_CURSOR 0                   // "▷" selection cursor drawn before the active menu item
#define STR_HUD_H 3                    // "H" shown on the save screen in Hard Mode (PrintSaveDataRowText)
#define STR_HUD_U 4                    // "U" shown on the save screen in Ultimate Mode
#define STR_COLON 7                    // ":" hours:minutes separator in the save-data play-time
#define STR_APOSTROPHE 8               // "'" minutes'seconds separator in the save-data play-time
#define STR_DIGIT 30                   // digits "0".."9"; STRING(STR_DIGIT + n) prints digit n (time, laps, counters)
#define STR_DIGIT_1 31                 // "1" (= STR_DIGIT + 1); STRING(STR_DIGIT_1 + idx) prints the 1-based save-sector number
#define STR_RANK 40                    // "Lv.F".."Lv.S"; STRING(STR_RANK + rank)
#define STR_CYBERELF_NAME 100          // cyber-elf names; STRING(STR_CYBERELF_NAME + elfId)
#define STR_CYBERELF_NONE 174          // "None", shown for an empty cyber-elf slot
#define STR_EXSKILL_NAME 450           // EX-skill names; STRING(STR_EXSKILL_NAME + selected)
#define STR_EXSKILL_DESC_NONE 462      // "None learned" description, shown when no EX-skill is equipped
#define STR_EXSKILL_DESC 463           // EX-skill descriptions; STRING(STR_EXSKILL_DESC + selected)
#define STR_EXSKILL_DESC_NONE2 475     // "None learned" description (second/right pane, slot 13)
#define STR_GAMEOVER_CONTINUE_SEL 520  // game-over "Continue", highlighted variant (drawn when this item is selected)
#define STR_GAMEOVER_CONTINUE 521      // game-over "Continue", normal variant
#define STR_GAMEOVER_RESTART_SEL 522   // game-over "Restart from save", highlighted
#define STR_GAMEOVER_RESTART 523       // game-over "Restart from save", normal
#define STR_GAMEOVER_QUIT_SEL 524      // game-over "Quit the game", highlighted
#define STR_GAMEOVER_QUIT 525          // game-over "Quit the game", normal
#define STR_DISK_092 892               // disk "092" — the Secret Disk Cerveau gives you (inserted as a text variable)
#define STR_MINIGAME_RULES 1088        // "RULES" header on the minigame rules screen

#endif  // GUARD_RMZ3_STRING_IDS_H
