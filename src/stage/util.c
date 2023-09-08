#include "entity.h"
#include "global.h"
#include "motion.h"

void resetData_08016db4(void) {
  InitMotionLocation();
  gEntityIDGenerator = 0;
  wPauseFrame = 0;
  gIsPlayDamageSE = 0;
  gLifeRecoverAmount = 0;
  gSubtankRecoverAmount = 0;
  gECrystalGainAmount = 0;
  gInChat = 0;
  gIsUsingDoor3D = 0;
  gInTransport = FALSE;
  gPause = 0;
  gTimeElfTimer = 0;
}
