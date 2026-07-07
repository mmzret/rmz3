#include "element.h"
#include "entity.h"
#include "game.h"
#include "gba/m4a.h"
#include "gfx.h"
#include "global.h"
#include "hud.h"
#include "input.h"
#include "intro.h"
#include "link.h"
#include "mmbn4.h"
#include "motion.h"
#include "overworld.h"
#include "palette_animation.h"
#include "pickup.h"
#include "score.h"
#include "sound.h"
#include "spawn.h"
#include "sram.h"
#include "story.h"
#include "syssav.h"
#include "system.h"
#include "text.h"
#include "unk0202fe50.h"
#include "widget.h"

// TODO: ewram.c ではなく、それぞれのファイルで定義して後で リンカでまとめたほうがいい (構造体の定義が面倒くさい)

/*
  Process(s) 中に RunScheduler のspを退避しておくためのもの e.g. 03007d58

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
EWRAM_DATA u8 sHandshakePlayerCount = 0;
EWRAM_DATA u8 sChecksumAvailable = 0;
EWRAM_DATA u16 sSendNonzeroCheck = 0;
EWRAM_DATA u16 sRecvNonzeroCheck = 0;

EWRAM_DATA ALIGNED(16) SectorHeader gSaveHeader = {};  // 0x02000010

EWRAM_DATA SoundID SoundID1 = MUS_DUMMY;
EWRAM_DATA SoundID SoundID2 = MUS_DUMMY;

EWRAM_DATA struct EntityHeader* pCurEntityHeader = NULL;

EWRAM_DATA s32 gConveyor = PIXEL(0);

EWRAM_DATA ALIGNED(16) struct Solid* gResistanceBaseElevatorPtr = NULL;

EWRAM_DATA struct Entity* pZero = NULL;  // 常に 02037c60 (= Zero )を指している
EWRAM_DATA u16 gLastWeaponElements[4] = {};
EWRAM_DATA u16 gWeaponElements[4] = {};

EWRAM_DATA u16 gCyberSpaceColorHashtable[96] = {};  // 0x02000048, 元のRGB555 の各色　を足した値をインデックスにして、変換後のRGB555の色を返すテーブル
EWRAM_DATA u8 gUnkSineTableIdx = 0;

// ストーリーの途中で真っ暗な画面でセーブするときに使う用？
EWRAM_DATA ALIGNED(16) GameSavedata SaveState_02000110 = {};
EWRAM_DATA struct SaveSlotMetadata gSaveSlotMetadata_02000360 = {};

// シエルと会話してセーブするときに使う用？
EWRAM_DATA GameSavedata SaveState_020003a8 = {};  // OverworldLoop_ManageSaveData で使う
EWRAM_DATA struct SaveSlotMetadata gSaveSlotMetadata = {};

EWRAM_DATA ALIGNED(16) struct MusicPlayerTrack gMPlayTracks[21] = {};

EWRAM_DATA u16 gLinkRecvCmds[MAX_LINK_PLAYERS][CMD_LENGTH] = {};  // 0x02000cd0 (LinkMain1 の第3引数であることから) pret/pokefirered の gRecvCmds に相当
EWRAM_DATA u16 gLinkSendCmds[MAX_LINK_PLAYERS][CMD_LENGTH] = {};  // 0x02000d10
EWRAM_DATA ALIGNED(16) struct Unk_02000d50 gUnk02000d50 = {};
EWRAM_DATA ALIGNED(16) struct Unk_02000db0 Unk02000db0 = {};
EWRAM_DATA ALIGNED(16) struct Unk_02000db0 Unk02000dc0 = {};

EWRAM_DATA ALIGNED(16) u8 Unk_02000db0[1808] = {};  // 0x02000dd0..0x020014df

EWRAM_DATA u32 u32_020014e0 = 0;
EWRAM_DATA u8 unused_020014e4[12] = {};

EWRAM_DATA u8 gLastSendQueueCount = 0;
EWRAM_DATA ALIGNED(4) u16 gLinkHandshake = 0;  // 0x020014f4
EWRAM_DATA ALIGNED(4) u8 gLastRecvQueueCount = 0;
EWRAM_DATA ALIGNED(4) u8 u8_ARRAY_020014fc[4] = {};
EWRAM_DATA u8 u8_02001500 = 0;
EWRAM_DATA ALIGNED(16) struct Link gLink = {};  // 0x02001510

EWRAM_DATA ALIGNED(16) struct KeyState gJoypad[2] = {};
EWRAM_DATA ALIGNED(16) struct SramState gSramState = {};  // 02001ee0

EWRAM_DATA ALIGNED(16) struct GraphicTransferManager gGraphicTransferManager = {};

EWRAM_DATA ALIGNED(16) struct PaletteAnimationManager gPaletteAnimationManager = {};

EWRAM_DATA ALIGNED(16) struct WramVideoRegister gVideoRegBuffer = {};  // 0x02002140
EWRAM_DATA ALIGNED(16) struct WramBlendRegister gBlendRegBuffer = {};
EWRAM_DATA ALIGNED(16) struct WramWindowRegister gWindowRegBuffer = {};
EWRAM_DATA u16 wMOSAIC = 0;

EWRAM_DATA u32 gSongCount = 0;

EWRAM_DATA ALIGNED(16) SystemSavedata gSystemSavedata = {};  // 0x020021b0
EWRAM_DATA ALIGNED(16) struct Overworld gOverworld = {};

// ResetEntityEnvironment でリセットしてるので塊？ (オフセットではなく、個別のアドレスでそれぞれアクセスしているので構造体ではなさそうだ)
EWRAM_DATA bool8 gIsPlayDamageSE = FALSE;
EWRAM_DATA s32 s32_0202f334 = 0;
EWRAM_DATA bool8 gInTransport = FALSE;        // オペレータによる転送 or ファントムトランスポータルによる転送中
EWRAM_DATA ALIGNED(4) u16 gTimeElfTimer = 0;  // ストパーラ系の効果持続時間の残り
EWRAM_DATA struct Zero* pZero2 = NULL;
EWRAM_DATA bool8 gInHitStopFrames = FALSE;  // 030032e2 のコピー
EWRAM_DATA ALIGNED(4) u8 gInChat = 0;       // NPCと会話中に立つフラグ? (会話中にここを0にするとメッセージウィンドウは消えないがゼロを自由に動かせるようになった, 080232c8 と関連)
EWRAM_DATA ALIGNED(4) u8 gEntityIDGenerator = 0;
EWRAM_DATA ALIGNED(4) bool8 gPause = 0;          // これがtrueのとき画面がpause状態(回復中のような状態)になる
EWRAM_DATA ALIGNED(4) u8 gMatrixCount = 0;       // Affine変換を行うオブジェクトの数
EWRAM_DATA ALIGNED(4) bool8 gIsUsingDoor3D = 0;  // 画面が暗転してる時にtrue?
EWRAM_DATA u32 gECrystalGainAmount = 0;
EWRAM_DATA u32 gWhitePaintFlags[8] = {};
EWRAM_DATA u32 gLifeRecoverAmount = 0;  // n > 0のときゼロの体力がn回復する
EWRAM_DATA u32* PTR_0202f384 = NULL;    // -> &g->unk_1ed8;
EWRAM_DATA u32 RNG_0202f388 = 0;
EWRAM_DATA u32 gSubtankRecoverAmount = 0;  // n > 0 のときサブタンクが n/4だけ回復

EWRAM_DATA u16 wDynamicMotionPalIDs[DYNAMIC_MOTION_COUNT + 56] = {};  // 085d78f8 からの Graphic のpal.dstが入っている (08017aa8 参照)
EWRAM_DATA u16 wStaticMotionPalIDs[STATIC_MOTION_COUNT + 2] = {};     // 085d78f8 からの Graphic のpal.dstが入っている (08017aa8 参照)
EWRAM_DATA u16 wStaticGraphicTilenums[STATIC_MOTION_COUNT + 2] = {};  // 085d78f8 からの Graphic (.ofs / 64) が入っている (08017aa8 参照)
EWRAM_DATA u16 wDynamicGraphicTilenums[DYNAMIC_MOTION_COUNT + 56] = {};

EWRAM_DATA ALIGNED(16) struct SpawnManager gSpawnManager = {};
EWRAM_DATA ALIGNED(16) struct Story88 gCurStory = {};
EWRAM_DATA ALIGNED(16) struct MissionScore gScore = {};
EWRAM_DATA ALIGNED(16) struct Unused_0202fe50 gUnk_0202fe50 = {};
EWRAM_DATA ALIGNED(16) struct StageRun gStageRun = {};
EWRAM_DATA u8 gSunkenLibDiskRoomIdxs[8] = {};  // 0834cdb8 のidx
EWRAM_DATA u8 sunken_0202fffc[16] = {};
EWRAM_DATA u8 Unk_0203000c[228] = {};
EWRAM_DATA ALIGNED(16) struct QuakeManager gQuakeManager = {};

EWRAM_DATA struct ElFxManager gElFxManager = {};  // 16バイトでアラインメントされていない

EWRAM_DATA struct EntityHeader* gZeroHeaderPtr = NULL;
EWRAM_DATA struct EntityHeader* gWeaponHeaderPtr = NULL;
EWRAM_DATA struct EntityHeader* gBossHeaderPtr = NULL;

EWRAM_DATA struct EntityHeader* gEnemyHeaderPtr = NULL;
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
EWRAM_DATA struct EntityHeader* gPickupHeaderPtr = NULL;

EWRAM_DATA struct EntityHeader* gElfHeaderPtr = NULL;
EWRAM_DATA u8* gElfAvailability = NULL;  // 多分常に GameState.save.elf (= 0x02036ed8) を指す

EWRAM_DATA struct EntityHeader* gWidgetHeaderPtr = NULL;

EWRAM_DATA ALIGNED(16) TextPrinter gTextPrinter = {};
EWRAM_DATA ALIGNED(16) struct HUD gHUD = {};
EWRAM_DATA ALIGNED(16) struct TextWindow gTextWindow = {};

EWRAM_DATA ALIGNED(16) struct Intro gIntro = {};
EWRAM_DATA u32 gUnkMmbn4 = 0;  // 0x02030b54
EWRAM_DATA ALIGNED(16) struct GameState gGameState = {};
EWRAM_DATA ALIGNED(16) struct Elf gElfEntities[16] = {};
EWRAM_DATA ALIGNED(16) Player gPlayers[1] = {};  // 02037c60
EWRAM_DATA ALIGNED(16) Pickup gPickups[10] = {};

EWRAM_DATA ALIGNED(16) u8 _unused_020386a0[2352] = {};  // もともともう1種類Entityがあったのかも

EWRAM_DATA ALIGNED(16) struct Weapon gWeapons[24] = {};  // 武器というよりはゼロの武器による攻撃
EWRAM_DATA ALIGNED(16) struct Solid gSolids[22] = {};
EWRAM_DATA ALIGNED(16) struct Boss gBosses[5] = {};
EWRAM_DATA ALIGNED(16) struct Widget gWidgets[64] = {};

EWRAM_DATA ALIGNED(16) struct StageDiskManager gStageDiskManager = {};
