#ifndef GUARD_RMZ3_ENTITY_ZERO_H
#define GUARD_RMZ3_ENTITY_ZERO_H

#include "entity/entity.h"
#include "input.h"
#include "types.h"

enum MenuZeroColor {
  MZC_NORMAL,
  MZC_HARD,
  MZC_ULTIMATE,
};

// Zero.mode[1]
enum {
  ZERO_GROUND = 0,     // 地上(棒立ち、歩き、ダッシュ、Zセイバー、etc...)
  ZERO_AIR = 1,        // 空中
  ZERO_WALL = 2,       // 壁ずり
  ZERO_LADDER = 3,     // はしご
  ZERO_DAMAGED = 4,    // 被ダメ
  ZERO_DOOR_2D = 5,    // ドア(2D, ボス部屋とか)
  ZERO_DOOR_3D = 6,    // ドア(3D, ベースのドアとか)
  ZERO_BINDED = 7,     // (レバガチャが必要な)拘束状態
  ZERO_FLOAT = 8,      // floated by Birleaf or Biraid
  ZERO_TALK = 9,       // 仁王立ち(会話時)
  ZERO_TELEPORT = 10,  // 転送
  ZERO_CYBER = 11,     // サイバー空間のドア
};

struct ZeroAsset {
  u8 satelites[2];  // 装備しているサテライトエルフ
  u16 unused;
  u16 fusions;  // フュージョンエルフでどれだけ減点もらうか
  u16 EC;       // E-Crystal
  u8 subtankHP[4];
};  // 12 bytes

struct KeyMap {
  KEY_INPUT jump;
  KEY_INPUT dash;
  KEY_INPUT main;
  KEY_INPUT sub;
};

struct KeyConfig {
  struct KeyMap keys;
  // 0: タイプA
  // 1: タイプB
  // 2: カスタム
  u8 btnMode;
  // 0: タイプA
  // 1: タイプB
  // 2: タイプC
  u8 attackMode;
  u8 unk_a;
  u8 _;
};

struct ZeroStatus {
  struct ZeroAsset asset;
  weapon_t mainWeapon;
  weapon_t subWeapon;
  u8 element;
  u8 head;
  u8 body;
  u8 foot;
  u16 exSkill;
  u16 unlockedExSkill;
  u8 unlockedWeapon;
  u8 unlockedHead;
  u8 unlockedBody;
  u8 unlockedFoot;
  u8 menuZeroColor;
  u8 unk_1b;
  struct KeyConfig keyMap;
  u8 charge[2];  // 0: メイン武器, 1: サブ武器
  u16 unk_2a;
  u8 maxHP;
  u8 dying;  // ゼロが肩を抑えてハァハァしているか
  u16 pad_2e;
};  // 48 bytes

struct Zero_b4 {
  struct ZeroStatus status;
  weapon_t mainCopy;
  weapon_t subCopy;
  u16 unk_e6;

  u8 prevMode;
  u8 prevPhase;

  u8 ALIGNED(4) attackMode[4];
  u8 ALIGNED(4) unused_f0[4];

  struct Entity* shadow;  // afterimage on dash(ダッシュ時の残像)

  u8 wallDustTimer;  // 壁ずり中に毎フレーム減っていって0xFFになったら土煙
  SoundID ALIGNED(2) sound;

  u8 unk_fc[4];
  struct Coord prevCoord;
  s32 blownSpeed;  // パンテオンフィストに吹っ飛ばされた時用(ジャンプ時のX速度にふっ飛ばしを加えるため)
  s32 deltaX;      // 前のフレームからゼロがどれだけX方向に移動したか
  u8 dashTimer;
  u8 unk_111;
  bool8 dashable;      // ダッシュ可能なときにたつフラグ？
  bool8 softPlatform;  // すり抜け床をすり抜け中か(すり抜け中=すり抜け床と重なっているか)
  s32 softPlatformY;   // 下ボタンですり抜け床をすり抜けた際の すり抜け床 のY座標 (すり抜け中かのチェックで利用)
  // プロパティのアクセス方法から考えて、unk_114まで
};

struct Zero {
  struct Entity s;
  struct Body body;
  struct Zero_b4 unk_b4;

  bool8 isRightDir;     // ゼロが横を向いているか
  bool8 isAreaChange;   // 横方向のエリア移動(ドアとか)中に立ってる
  bool8 airJumpped;     // ゼロが空中ジャンプをしたかどうか
  bool8 ripple;         // 海面を行き来している最中にTRUE(水飛沫をゼロが出している)
  bool8 canSplashJump;  // 水面に近いときにセットされる
  u8 slow;              // 0xffに近づくほどゼロの動きが鈍くなる
  u8 idleFrame;         // For auto recover
  bool8 slip;           // 1にするとゼロが滑る
  u8 floatTimer;        // Timer for Birleaf(or Biraid) floating. バーリーフ(バーエイド)によって浮いていられる残り時間
  cyberelf_t unk_121;   // エルフIDなのは確定
  bool8 blown;          // Is Zero blown away by Panthon Fist?
  u8 dashDustTimer;     // ダッシュ時に3フレームごとに土煙を発生させるためのフレームカウンタ

  // ゼロが武器モーション中で行動に制約がかかっていることを示すためのフラグ
  struct __attribute__((packed, aligned(1))) {
    u8 move : 1;    // Disallow Movement (移動不可能か(セイバーの三段切り中などにセットされるが、地上でのバスターは動きながら打てるのでセットされない))
    u8 dash : 1;    // Disallow Dash (ダッシュ不可能(シールドブーメラン構え中))
    u8 shield : 1;  // Dissable guard by Shield?
    u8 b3 : 1;
    u8 mainCharge : 1;  // Disallow MainWeapon charge (メインウェポンのチャージが可能か)
    u8 subCharge : 1;   // Disallow SubWeapon charge (サブウェポンのチャージが可能か)
    u8 b6 : 1;          // チャージセイバーに関する何か？
    u8 b7 : 1;
  } restriction;

  /*
    チャージセイバーによる攻撃中にセットされる(攻撃終わったらクリア)
    1: 地上チャージセイバー
    2: 空中チャージセイバー
    3: 壁チャージセイバー
    4: ハシゴチャージセイバー
  */
  u8 chargeSaber;

  u8 rodID;  // リコイルロッドのアクションを区別するため
  u8 unk_127;
  u8 usingWeapon;         // ゼロが現在攻撃中の場合、その武器を示す
  u8 atkCooltime;         // フレーム単位(短くするほどバスターの連射速度が上がる)
  u8 tripleSlashCounter;  // 三段切りで何段目かを記録しておく(コータスの衝撃波やﾋｯﾌｯﾊﾃﾞｲﾔｰとかで利用)
  u8 forceWeapon;         // 武器を装備していなくてもその武器の攻撃を強制する FFで何もしない
  u8 bulletCount;         // バスターを今どれだけ連射したか
  u8 saberAction;         // (Weapon.s).work[0] の値と saberAction が一致しないとダメ
  u8 unk_12e;
  u8 ALIGNED(1) unk_12f[2];
  u8 mainChargeFrame;  // メインウェポンをチャージしているフレーム
  u8 subChargeFrame;
  u8 unk_rod_133;       // リコイルロッド関連のなにか
  u8 splitHeavensWait;  // テンレツジンの発生8フレームを待つためのフレームカウンタ
  u8 unk_135;
  u8 unk_136;
  u8 unk_137;
  s16 unk_138;
  u8 unk_13a;
  u8 rodToggle;  // リコイルロッドで通常攻撃を連続で打つ場合に、奇数発目の振り向きモーションを管理するためのToggle (0x00 or 0x10)
  u8 ALIGNED(1) unk_13c[2];
  motion_t prevMotion;

  u8 motionCmdIdx;
  u8 motionDuration;

  bool8 poseFixed;  // ゼロの見た目が固定される
  union {
    u8 raw;
    u8 lo : 4;
    u8 hi : 4;
  } ALIGNED(1) PACKED unk_143;
  u8 ALIGNED(1) unk_144[3];
  u8 posture;
  /*
    bit0: dash now?
    bit1: is shadow dash?
  */
  u8 prevPosture;
  u8 unk_149;
  u8 ALIGNED(1) unk_14a[2];
  struct Border border;  // ゼロが侵入不可能な境界座標を表す
  u8 hazard[16];         // ゼロと干渉するHazardのidx(Overworld_1c8.blockingsのidx)が入る
  u16 hazardIDs[16];     // ゼロと干渉するHazardのEntityIDが入る
  u8 hazardCount;        // .hazard の長さ
  bool8 isGround;
  bool8 antlion;
  bool8 pushedOut;  // 壁にめり込んで押し出されたときにTRUE
  u8 horizontalSlide;
  u8 ALIGNED(1) unk_190[3];

  KEY_INPUT inputHistory[64];  // 直近64フレームのキー入力 idx=0が最新
  KEY_INPUT pressed;           // 新たにOFFからONになったボタン
  KEY_INPUT last;              // 実際に押されたGBAのボタン Stage.pressedKeys が入る
  zero_input_t zeroInput;
  struct KeyMap keyMap;
  u8 ultimateCommand_224[3];
  u8 ultimateCommand_227[3];
  u8 ultimateCommand_22a[2];
  u8 ultimateCommand_22c[3];
  u8 commandDashTimer;  // コマンドによるダッシュのダッシュ継続時間を表すタイマー
  bool8 globbed;        // ビーサーバーのはちみつを食らっている状態
  bool8 inCyberSpace;
  u8 elfMotion;           // ゼロの周りを飛ぶサイバーエルフの動き
  u8 subtankFilledFrame;  // 毎フレーム減っていき、0になるとサブタンクが満タンになった音がなる
  u8 unk_234;             // 夕闇の砂漠で流砂に沈むことと関係あり
  u8 ALIGNED(1) unk_235[3];
  s32 unk_238;
  u8 unk_23c[64];

  // For minigame
  union {
    u8 raw[16];
    struct {
      u8 unk_27c;
      u8 unk_27d;
      u8 unk_27e;
      u8 unk_27f;
      struct Entity* unk_280[3];
    } copyx;
    struct {
      s32 x;
      struct Enemy* enemy;
      u8 unk_8;
      u8 unk_9;
      u8 unk_a;
      u8 unk_b;
      s32 y;
    } harpuia;
    struct {
      s32 x;
      u8 unk_4[12];
    } leviathan;
  } mg;
};  // 652 bytes

typedef void (*ZeroFunc)(struct Zero*);
typedef ZeroFunc ZeroRoutine[5];

#endif  // GUARD_RMZ3_ENTITY_ZERO_H
