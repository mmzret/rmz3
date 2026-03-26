#include "game.h"
#include "global.h"
#include "story.h"
#include "text.h"

void getDiskInStageRun(u8 n);
void SaveGraphicState(struct GameState* g);
void RestoreGraphicState(struct GameState* g);

#define IS_DISK_UNLOCKED(flags, diskid) ((flags[diskid >> 2] & 0x0F) >> (diskid & 3))

void OverworldLoop_CerveauTalk(struct GameState* g) {
  switch (g->mode[3]) {
    default: {
      if (((&gTextWindow.text)->mode != 0) && ((&gTextWindow.text)->mode != TEXT_MODE_OPTION)) {
        return;
      }
      if ((&gTextWindow.text)->unk_16 == 9) {
        if ((&gTextWindow.text)->mode != 0) {
          (&gTextWindow.text)->flag |= TEXT_FLAG_TERMINATE;
          break;
        }
        gTextPrinter.inserted = (char_t*)STRING(892);
        PrintTextWindow(0x100, 0x5A);
        getDiskInStageRun(0x5b);
        break;
      }

      g->mode[3] = 0x0;
      FALLTHROUGH;
    }
    case 0: {
      PrintOptionMessage1(0x66);  // なんのようかな？ シークレットディスクのカイセキ or 話をする
      g->unk_008[1] = 0;
      g->mode[3]++;
      FALLTHROUGH;
    }
    case 1: {
      s16 ans;
      if (((&gTextWindow.text)->mode != 0) && ((&gTextWindow.text)->mode != TEXT_MODE_OPTION)) {
        return;
      }
      if ((ans = handleWrapTwoChoice(g)) != 0) {
        if (ans > 0) {
          g->mode[3] = 3;
          break;
        }
        if (ans == -1) {
          if (!FLAG(gCurStory.s.gameflags, FLAG_10)) {
            PrintOptionMessage2(0x207);  // おや？ シエルのところへ行かなくていいのかい？ ...
          } else {
            if (!FLAG(gCurStory.s.gameflags, FLAG_11)) {
              if (gCurStory.s.counts[1] == 0) {
                u8* disks;
                PrintOptionMessage2(0x208);
                disks = gStageDiskManager.disk;
                if (IS_DISK_UNLOCKED(disks, 91) & 1) {
                  gCurStory.s.counts[1] = 2;
                } else {
                  gCurStory.s.counts[1] = 1;
                }
              } else {
                if (gCurStory.s.counts[1] == 1) {
                  PrintOptionMessage2(0x209);
                  gCurStory.s.counts[1] = 2;
                } else {
                  PrintOptionMessage2(0x20E);
                }
              }
            } else {
              if (!FLAG(gCurStory.s.gameflags, NO_HARPUIA)) {
                if (gCurStory.s.counts[1] < 3) {
                  PrintOptionMessage2(0x20A);
                  gCurStory.s.counts[1] = 3;
                } else {
                  PrintOptionMessage2(0x20B);
                }
              } else {
                if (gCurStory.s.counts[1] < 4) {
                  PrintOptionMessage2(0x20C);  // おお、ゼロか.. ドクターバイルはとてもおそろしいヤツだ ...
                  gCurStory.s.counts[1] = 4;
                } else {
                  PrintOptionMessage2(0x20D);  // ゼロ.. ここからさきの戦いは ...
                }
              }
            }
          }
          g->mode[3] = 0xFF;
          break;
        }
        PlaySound(SE_NO);
        g->mode[3] = 2;
      }
      break;
    }
    case 2: {
      if ((&gTextWindow.text)->mode != 0) {
        (&gTextWindow.text)->flag |= TEXT_FLAG_TERMINATE;
      } else {
        SetGameMode(g, GAMEMODE(MAINGAME, OVERWORLD, 0, 0));
      }
      break;
    }
    case 3: {
      if ((&gTextWindow.text)->mode != 0) {
        (&gTextWindow.text)->flag |= TEXT_FLAG_TERMINATE;
        break;
      }
      gStageRun.vm.transition = TRANSITION_BLACKOUT;
      g->mode[3]++;
      FALLTHROUGH;
    }
    case 4: {
      if (gStageRun.vm.transition == 0) {
        SaveGraphicState(g);
        SetGameMode(g, GAMEMODE(DISK_ANALYSIS, 0, 0, 0));
      }
      break;
    }
    case 5: {
      RestoreGraphicState(g);
      gStageRun.vm.transition = TRANSITION_REVERSE;
      g->mode[3]++;
      FALLTHROUGH;
    }
    case 6: {
      if (gStageRun.vm.transition == 0) {
        g->mode[3] = 0xFF;
      }
      break;
    }
  }
}
