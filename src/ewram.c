#include "blink.h"
#include "element.h"
#include "entity.h"
#include "game.h"
#include "gfx.h"
#include "global.h"
#include "hud.h"
#include "input.h"
#include "intro.h"
#include "link.h"
#include "mission.h"
#include "mmbn4.h"
#include "motion.h"
#include "overworld.h"
#include "sram.h"
#include "story.h"
#include "syssav.h"
#include "system.h"
#include "text.h"

/*
  Process(s) 中に GameLoop のspを退避しておくためのもの e.g. 03007d58

  sp -> r4
        r5
        r6
        r7
        r8
        r9
        r10
        r11
        lr  // e.g. 08002253
*/
EWRAM_DATA void* StackFramePointer = NULL;

EWRAM_DATA u16 gLinkSavedIme = 0;
EWRAM_DATA u8 sNumVBlanksWithoutSerialIntr = 0;
EWRAM_DATA bool8 sSendBufferEmpty = 0;
EWRAM_DATA u8 u8_02000008 = 0;
EWRAM_DATA u8 sChecksumAvailable = 0;
EWRAM_DATA u16 sSendNonzeroCheck = 0;
EWRAM_DATA u16 sRecvNonzeroCheck = 0;
EWRAM_DATA ALIGNED(4) struct SaveHeader gSaveHeader = {};

EWRAM_DATA SoundID SoundID1 = MUS_DUMMY;
EWRAM_DATA SoundID SoundID2 = MUS_DUMMY;

EWRAM_DATA struct EntityHeader* pCurEntityHeader = NULL;

EWRAM_DATA s32 s32_ARRAY_02000028[2] = {};

EWRAM_DATA struct Solid* gResistanceBaseElevatorPtr = NULL;

// 常に 02037c60 (= Zero )を指している
EWRAM_DATA struct Zero* pZero = NULL;
EWRAM_DATA u16 gLastWeaponElements[4] = {};
EWRAM_DATA u16 gWeaponElements[4] = {};

EWRAM_DATA u16 u16_ARRAY_02000048[64] = {};
EWRAM_DATA u16 CopyFrom_08386130[32] = {};  // 080ee1dc 参照

EWRAM_DATA u8 gUnkSineTableIdx = 0;
EWRAM_DATA ALIGNED(1) u8 _unused_02000109[7] = {};

EWRAM_DATA u8 Unk_02000110[664] = {};  // 0x2000110..0x020003a8
EWRAM_DATA struct SaveSlot SaveState_020003a8 = {};
EWRAM_DATA struct SaveSlotInfo gSaveSlotInfo = {};

EWRAM_DATA struct MusicPlayerTrack gMPlayTracks[21] = {};

EWRAM_DATA u8 Unk_02000cd0[128] = {};
EWRAM_DATA struct Unk_02000d50 gUnk02000d50 = {};
EWRAM_DATA u8 unused_02000da8[8] = {};
EWRAM_DATA u8 Unk_02000db0[1840] = {};  // 0x02000db0..0x020014df

EWRAM_DATA u32 u32_020014e0 = 0;
EWRAM_DATA u8 unused_020014e4[12] = {};

EWRAM_DATA u8 gLastSendQueueCount = 0;
EWRAM_DATA ALIGNED(4) u16 u16_020014f4 = 0;
EWRAM_DATA ALIGNED(4) u8 gLastRecvQueueCount = 0;
EWRAM_DATA ALIGNED(4) u8 u8_ARRAY_020014fc[4] = {};
EWRAM_DATA u8 u8_02001500 = 0;
EWRAM_DATA ALIGNED(1) u8 unused_02001501[15] = {};
EWRAM_DATA struct Link gLink = {};
EWRAM_DATA u8 unused_02001ea8[8] = {};

EWRAM_DATA struct KeyState gJoypad[2] = {};
EWRAM_DATA struct SramState gSramState = {};  // 02001ee0

EWRAM_DATA struct GraphicTransferManager gGraphicTransferManager = {};
EWRAM_DATA u8 Unk_02001fd4[12] = {};  // gGraphicTransferManager の一部？

EWRAM_DATA struct BlinkManager gBlinkManager = {};

EWRAM_DATA struct WramVideoRegister gVideoRegBuffer = {};
EWRAM_DATA u8 Unk_0200215c[36] = {};  // 0x0200215c..0x0200217F
EWRAM_DATA struct WramBlendRegister gBlendRegBuffer = {};
EWRAM_DATA u8 _unused_02002188[8] = {};
EWRAM_DATA struct WramWindowRegister gWindowRegBuffer = {};
EWRAM_DATA u16 wMOSAIC = 0;

EWRAM_DATA u32 gSongCount = 0;
EWRAM_DATA u8 Unk_020021a8[8] = {};

EWRAM_DATA struct SystemSavedataManager gSystemSavedataManager = {};
EWRAM_DATA struct Overworld gOverworld = {};
EWRAM_DATA bool8 gIsPlayDamageSE = FALSE;
EWRAM_DATA s32 s32_0202f334 = 0;
EWRAM_DATA bool8 gInTransport = FALSE;        // オペレータによる転送 or ファントムトランスポータルによる転送中
EWRAM_DATA ALIGNED(4) u16 gTimeElfTimer = 0;  // ストパーラ系の効果持続時間の残り
EWRAM_DATA struct Zero* pZero2 = NULL;
EWRAM_DATA u8 wPauseFrame = 0;  // 030032e2 のコピー

/*
  NPCと会話中に立つフラグ
  会話中にここを0にするとメッセージウィンドウは消えないがゼロを自由に動かせるようになる
  080232c8 と関連
*/
EWRAM_DATA ALIGNED(4) u8 gInChat = 0;
EWRAM_DATA ALIGNED(4) u8 gEntityIDGenerator = 0;
EWRAM_DATA ALIGNED(4) bool8 gPause = 0;          // これがtrueのとき画面がpause状態(回復中のような状態)になる
EWRAM_DATA ALIGNED(4) u8 gMatrixCount = 0;       // Affine変換を行うオブジェクトの数
EWRAM_DATA ALIGNED(4) bool8 gIsUsingDoor3D = 0;  // 画面が暗転してる時にtrue?
EWRAM_DATA u32 gECrystalGainAmount = 0;
EWRAM_DATA u32 gWhitePaintFlags[8] = {};
EWRAM_DATA u32 gLifeRecoverAmount = 0;  // n > 0のときゼロの体力がn回復する
EWRAM_DATA void* PTR_0202f384 = NULL;   // n > 0のときゼロの体力がn回復する
EWRAM_DATA u32 RNG_0202f388 = 0;
EWRAM_DATA u32 gSubtankRecoverAmount = 0;  // n > 0 のときサブタンクが n/4だけ回復

EWRAM_DATA u16 wDynamicMotionPalIDs[DYNAMIC_MOTION_COUNT + 56] = {};  // 085d78f8 からの Graphic のpal.dstが入っている (08017aa8 参照)
EWRAM_DATA u16 wStaticMotionPalIDs[STATIC_MOTION_COUNT + 2] = {};     // 085d78f8 からの Graphic のpal.dstが入っている (08017aa8 参照)
EWRAM_DATA u16 wStaticGraphicTilenums[STATIC_MOTION_COUNT + 2] = {};  // 085d78f8 からの Graphic (.ofs / 64) が入っている (08017aa8 参照)
EWRAM_DATA u16 wDynamicGraphicTilenums[DYNAMIC_MOTION_COUNT + 56] = {};

EWRAM_DATA struct StageEntityManager gStageEntityManager = {};
EWRAM_DATA struct Story96 gCurStory = {};
EWRAM_DATA struct Mission gMission = {};
EWRAM_DATA struct Unused_0202fe50 gUnk_0202fe50 = {};
EWRAM_DATA struct StageRun gStageRun = {};
EWRAM_DATA u8 SunkenLibDiskRoomIdxs[8] = {};  // 0834cdb8 のidx
EWRAM_DATA u8 sunken_0202fffc[16] = {};
EWRAM_DATA u8 Unk_0203000c[228] = {};
EWRAM_DATA struct QuakeManager gQuakeManager = {};
EWRAM_DATA struct UnkElement wElement = {};  // 02030299のコピー？

EWRAM_DATA struct EntityHeader* gZeroHeaderPtr = NULL;
EWRAM_DATA struct EntityHeader* gWeaponHeaderPtr = NULL;
EWRAM_DATA struct EntityHeader* gBossHeaderPtr = NULL;

EWRAM_DATA struct EntityHeader* gZakoHeaderPtr = NULL;
EWRAM_DATA u32 u32_020302ac = 0;
EWRAM_DATA u32 u32_020302b0 = 0;
EWRAM_DATA u32 u32_020302b4 = 0;

EWRAM_DATA struct EntityHeader* gProjectileHeaderPtr = NULL;
EWRAM_DATA bool8 gIsLemonCollisionRemoved = FALSE;  // 敵が撃った豆の当たり判定を消して見かけだけ残しておく(エリア移動時用)
EWRAM_DATA u8* PTR_020302c0 = NULL;
EWRAM_DATA void* PTR_020302c4 = NULL;
EWRAM_DATA s32 s32_020302c8 = 0;
EWRAM_DATA u32 u32_020302cc = 0;
EWRAM_DATA u32 u32_020302d0 = 0;
EWRAM_DATA void* u32_020302d4 = NULL;
EWRAM_DATA u32 u32_020302d8 = 0;
EWRAM_DATA void* u32_020302dc = NULL;
EWRAM_DATA u32 u32_020302e0 = 0;
EWRAM_DATA s32 s32_020302e4 = 0;
EWRAM_DATA s32 s32_020302e8 = 0;

EWRAM_DATA struct EntityHeader* gVFXHeaderPtr = NULL;
EWRAM_DATA struct EntityHeader* gSolidHeaderPtr = NULL;  // 0x02031460 -> 0x0203A5F0
EWRAM_DATA struct EntityHeader* gMapItemHeaderPtr = NULL;

EWRAM_DATA struct EntityHeader* gElfHeaderPtr = NULL;
EWRAM_DATA u8 (*gUnlockedElfPtr)[CYBERELF_LENGTH] = NULL;  // 0x02036ed8 を指す

EWRAM_DATA struct EntityHeader* gWidgetHeaderPtr = NULL;
EWRAM_DATA u8 Unk_02030304[12] = {};

EWRAM_DATA struct TextPrinter gTextPrinter = {};
EWRAM_DATA struct HUD gHUD = {};
EWRAM_DATA struct TextWindow gTextWindow = {};

EWRAM_DATA struct Intro gIntro = {};
EWRAM_DATA struct UnkMmbn4 gUnkMmbn4 = {};
EWRAM_DATA struct GameState gGameState = {};
EWRAM_DATA struct Elf gElfEntities[16] = {};
EWRAM_DATA struct Zero gZero = {};
EWRAM_DATA u32 _padding_02037eec = 0;
EWRAM_DATA struct MapItem gMapItems[10] = {};
EWRAM_DATA u8 _unused_02038698[2360] = {};
EWRAM_DATA struct Weapon gWeapons[24] = {};  // 武器というよりはゼロの武器による攻撃
EWRAM_DATA struct Solid gSolids[22] = {};
EWRAM_DATA u8 _unused_0203b6c8[8] = {};
EWRAM_DATA struct Boss gBosses[5] = {};
EWRAM_DATA u8 _unused_0203bb44[12] = {};
EWRAM_DATA struct Widget gWidgets[64] = {};
EWRAM_DATA struct StageDiskManager gStageDiskManager = {};
EWRAM_DATA struct SoundInfo gSoundInfo = {};
EWRAM_DATA MPlayFunc gMPlayJumpTable[36] = {};
EWRAM_DATA struct CgbChannel gCgbChans[4] = {};

EWRAM_DATA struct MusicPlayerInfo gMPlayInfo_00 = {};
EWRAM_DATA struct MusicPlayerInfo gMPlayInfo_01 = {};
EWRAM_DATA struct MusicPlayerInfo gMPlayInfo_02 = {};
EWRAM_DATA struct MusicPlayerInfo gMPlayInfo_03 = {};
EWRAM_DATA struct MusicPlayerInfo gMPlayInfo_04 = {};
EWRAM_DATA struct MusicPlayerInfo gMPlayInfo_05 = {};
EWRAM_DATA struct MusicPlayerInfo gMPlayInfo_06 = {};
EWRAM_DATA struct MusicPlayerInfo gMPlayInfo_07 = {};
EWRAM_DATA struct MusicPlayerInfo gMPlayInfo_08 = {};
EWRAM_DATA struct MusicPlayerInfo gMPlayInfo_09 = {};
EWRAM_DATA struct MusicPlayerInfo gMPlayInfo_10 = {};
EWRAM_DATA struct MusicPlayerInfo gMPlayInfo_11 = {};

EWRAM_DATA u8 gMPlayMemAccArea[16] = {};

EWRAM_DATA struct MusicPlayerInfo gMPlayInfo_12 = {};
EWRAM_DATA struct MusicPlayerInfo gMPlayInfo_13 = {};
EWRAM_DATA struct MusicPlayerInfo gMPlayInfo_14 = {};
