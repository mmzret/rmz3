#ifndef GUARD_RMZ3_ENTITY_ZERO_H
#define GUARD_RMZ3_ENTITY_ZERO_H

#include "entity/entity.h"
#include "input.h"
#include "types.h"

#define STAT_HDR                                              \
  u8 satelites[2]; /* 装備しているサテライトエルフ*/          \
  u16 unused;                                                 \
  u16 fusions; /* フュージョンエルフでどれだけ減点もらうか */ \
  u16 EC;      /* E-Crystal, 0x02037d1a */                    \
  u8 subtankHP[4];

// LoadStageRun(address: 0x08019ea4) での初期化の仕方 や GameSavedata のレイアウト的に　これで1つの構造体として扱うのが正解と思われる
// サイバーエルフや、サブタンクなどの外付けパーツ的な強化要素　をまとめている構造体なので、名前をそれっぽい名前に変更したい
struct ZeroAsset {
  STAT_HDR;
};  // 12 bytes
static_assert(sizeof(struct ZeroAsset) == 12);

struct KeyMap {
  KEY_INPUT jump;
  KEY_INPUT dash;
  KEY_INPUT main;
  KEY_INPUT sub;
};

struct KeyConfig {
  struct KeyMap keys;
  u8 btnMode;     // 0: タイプA, 1: タイプB, 2: カスタム
  u8 attackMode;  // 0: タイプA, 1: タイプB, 2: タイプC
  u8 unk_a;
  u8 _;
};

// ClearZeroStatus(address: 0x0803204c) や StoreZeroStatus (0x08032274) の内容的に、これで1つの構造体として扱うのが正解と思われる
// 名前を変更する予定
struct ZeroStatus {
  STAT_HDR;
  weapon_t weapons[2];  // 0: メイン武器, 1: サブ武器
  u8 element;           // 0x0E
  u8 head;              // 0x0F
  u8 body;              // 0x10
  u8 foot;              // 0x11
  u16 exSkill;          // 0x12
  u16 unlockedExSkill;  // 0x14
  u8 unlockedWeapon;    // 0x16
  u8 unlockedHead;
  u8 unlockedBody;
  u8 unlockedFoot;
  u8 menuZeroColor;
  struct KeyConfig keyMap;  // 0x1C
  u8 charge[2];             // 0x28, 0: メイン武器, 1: サブ武器
  u16 unk_2a;               // 0x2A
  u8 maxHP;                 // 0x2C
  u8 dying;                 // 0x2D, ゼロが肩を抑えてハァハァしているか
  u16 pad_2e;
};  // 48 bytes
static_assert(sizeof(struct ZeroStatus) == 48);

// PlayerState とかに名前変更予定
struct Zero_b4 {
  struct ZeroStatus status;  // 0x00 (-> 0xB4)

  // これ以降は、ゼロと密接に関連するプロパティではない(つまり、ZX, ZXAのように主人公がゼロ以外のキャラでも使いまわせそう)
  // つまり、 これ以降は別の構造体の可能性あり
  weapon_t mainCopy;  // 0x30 (-> 0xE4)
  weapon_t subCopy;   // 0x31 (-> 0xE5)
  u16 unk_e6;         // 0x32 (-> 0xE6)

  u8 prevMode;   // 0x34 (-> 0xE8)
  u8 prevPhase;  // 0x35 (-> 0xE9)

  State32 attackState;         // 0x38 (-> 0xEC), u8[4] だとアラインメントが4にならないので、 ただのu32 か union だと考えられる
  u8 ALIGNED(4) unused_f0[4];  // 0x3C (-> 0xF0), 直近の attackState　を保存する場所だと思うけど使われてないっぽい

  struct Entity* shadow;  // 0x40 (-> 0xF4), afterimage on dash(ダッシュ時の残像)

  u8 wallDustTimer;  // 0x44 (-> 0xF8), 壁ずり中に毎フレーム減っていって0xFFになったら土煙
  s16 sound;         // 0x46 (-> 0xFA)

  u8 unk_fc[4];
  Coords32 prevCoord;
  s32 blownSpeed;  // パンテオンフィストに吹っ飛ばされた時用(ジャンプ時のX速度にふっ飛ばしを加えるため)
  s32 deltaX;      // 前のフレームからゼロがどれだけX方向に移動したか
  u8 dashTimer;
  u8 unk_111;          // 0x5D (-> 0x111), ジャンプ時になにかのカウンタとして利用されている
  bool8 dashable;      // 0x5E (-> 0x112) ダッシュ可能なときにたつフラグ？
  bool8 softPlatform;  // すり抜け床をすり抜け中か(すり抜け中=すり抜け床と重なっているか)
  s32 softPlatformY;   // 下ボタンですり抜け床をすり抜けた際の すり抜け床 のY座標 (すり抜け中かのチェックで利用)
  // プロパティのアクセス方法から考えて、 .softPlatformY まで?
};
static_assert(sizeof(struct Zero_b4) == 100);

struct PlayerInputState {
  KEY_INPUT history[64];  // 直近64フレームのキー入力 idx=0が最新
  KEY_INPUT pressed;      // 新たにOFFからONになったボタン
  KEY_INPUT raw;          // 実際に押されたGBAのボタン Stage.pressedKeys が入る

  // 抽象化した入力(もっとうまい言葉を考えたい)
  // 例えば、ジャンプボタンが押されたかを確認する際は、いちいちジャンプボタンがキーコンでどのGBAのボタンに割り当てられているかを確認したりせずに、ここの ZERO_INPUT_JUMP を見るだけで良い
  zero_input_t val;  // 0x218

  struct KeyMap mapping;
  u8 ultimateCommand_224[3];
  u8 ultimateCommand_227[3];
  u8 ultimateCommand_22a[2];
  u8 ultimateCommand_22c[3];
  u8 commandDashTimer;  // コマンドダッシュ(十字キー2回押し)に関係するタイマー
};  // 156 bytes
static_assert(sizeof(struct PlayerInputState) == 156);

union MinigamePlayerState {
  u8 raw[16];
  struct {
    u8 unk_27c;
    u8 unk_27d;
    u16 unk_27e;
    u8 unk_280[4];
    u8 unk_284;
    u8 unk_285;
    u8 unk_286;
    u8 unk_287;
    u8 unk_288[4];
  } zero;
  struct {
    u8 element;  // 現在のXの属性(0: 炎 1: 雷, 2: 氷)
    u8 life;     // 残機 = あと何回ミスできるか
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
};

// 0x02037c60
// プレイヤー(ゼロ、ミニゲームの操作キャラ)
typedef struct Zero {
  OBJECT_HDR;

  // ここから最後まで全て同じ構造体にまとめられている可能性あり
  struct Zero_b4 unk_b4;  // 0xB4 (addr = 0x2037d14)

  // 0x118..
  bool8 isRightDir;     // 0x118, ゼロが横を向いているか
  bool8 isAreaChange;   // 0x119, 横方向のエリア移動(ドアとか)中に立ってる
  bool8 airJumpped;     // 0x11A, ゼロが空中ジャンプをしたかどうか
  bool8 ripple;         // 0x11B, 海面を行き来している最中にTRUE(水飛沫をゼロが出している)
  bool8 canSplashJump;  // 0x11C, 水面に近いときにセットされる
  u8 slow;              // 0xffに近づくほどゼロの動きが鈍くなる
  u8 idleFrame;         // For auto recover
  bool8 slip;           // 1にするとゼロが滑る
  u8 floatTimer;        // Timer for Birleaf(or Biraid) floating. バーリーフ(バーエイド)によって浮いていられる残り時間
  cyberelf_t unk_121;   // エルフIDなのは確定
  bool8 blown;          // Is Zero blown away by Panthon Fist?
  u8 dashDustTimer;     // ダッシュ時に3フレームごとに土煙を発生させるためのフレームカウンタ

  // ゼロが武器モーション中で行動に制約がかかっていることを示すためのフラグ
  // 0x0803152c のコンパイル結果が合わないので、型間違ってるかも？
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
  u8 atkCooltime;         // フレーム単位(短くするほどバスターの連射速度が上がる), このプロパティへのアクセス周りのアセンブリがなんかおかしい
  u8 tripleSlashCounter;  // 0x12A, 三段切りで何段目かを記録しておく(コータスの衝撃波やﾋｯﾌｯﾊﾃﾞｲﾔｰとかで利用)
  u8 forceWeapon;         // 武器を装備していなくてもその武器の攻撃を強制する FFで何もしない
  u8 bulletCount;         // バスターを今どれだけ連射したか
  u8 saberAction;         // (Weapon.s).work[0] の値と saberAction が一致しないとダメ
  u8 unk_12e;
  u8 ALIGNED(1) unk_12f[2];
  u8 mainChargeFrame;  // メインウェポンをチャージしているフレーム
  u8 subChargeFrame;
  u8 unk_rod_133;       // リコイルロッド関連のなにか
  u8 splitHeavensWait;  // テンレツジンの発生8フレームを待つためのフレームカウンタ
  u8 unk_135;           // リコイルロッド関連のなにか
  u8 unk_136;
  u8 unk_137;
  s16 recoilJumpDx;        // リコイルジャンプのX速度を記録しておく
  u8 saberSmashElecCount;  // ラクサイガで出る電気玉の現在の個数をカウントしている(その他の用途はない?)
  u8 rodToggle;            // リコイルロッドで通常攻撃を連続で打つ場合に、奇数発目の振り向きモーションを管理するためのToggle (0x00 or 0x10)
  u8 ALIGNED(1) unk_13c[2];

  // スプライトアニメーション関連
  motion_t prevMotion;
  u8 motionCmdIdx;
  u8 motionDuration;
  bool8 animDisabled;  // ゼロの見た目が固定される
  u8 unk_143_lo : 4;
  u8 unk_143_hi : 4;
  u8 ALIGNED(1) unk_144[3];
  u8 posture;      // 0x147
  u8 prevPosture;  // 0x148, bit0: dash now?, bit1: is shadow dash?
  u8 unk_149;

  struct {
    s32 left;
    s32 right;
    s32 top;
    s32 bottom;
  } border;           // 0x14C, ゼロが侵入不可能な境界座標を表す
  u8 hazard[16];      // ゼロと干渉するHazardのidx(Overworld.hazard.dataのidx)が入る
  u16 hazardIDs[16];  // ゼロと干渉するHazardのEntityIDが入る
  u8 hazardCount;     // .hazard の長さ
  bool8 isGround;
  bool8 antlion;
  bool8 pushedOut;                // 0x18F, 壁にめり込んで押し出されたときにTRUE
  u8 horizontalSlide;             // 0x190, 1以上にすると右方向にプレイヤーが徐々に移動していく (コンベアとは無関係っぽい?)
  struct PlayerInputState input;  // 0x194, 0x191..0x193 に 3バイトのパディング があるため、ここは構造体の可能性が高い

  // 0x230..
  bool8 globbed;                 // 0x230, ビーサーバーのはちみつを食らっている状態
  bool8 inCyberSpace;            // 0x231
  u8 elfMotion;                  // 0x232, ゼロの周りを飛ぶサイバーエルフの動き
  u8 subtankFilledFrame;         // 0x233, 毎フレーム減っていき、0になるとサブタンクが満タンになった音がなる
  u8 unk_234;                    // 0x234, 夕闇の砂漠で流砂に沈むことと関係あり
  s32 door3d_x;                  // 0x238, Door3D で x座標を保存するのに使われているが、その関数が使われていなさそうに見えるので、この変数も使われていない可能性がある
  u8 unk_23c[64];                // 0x23C (addr = 0x2037e9c), 使われているか不明
  union MinigamePlayerState mg;  // 0x27C (ミニゲーム以外では使わない)
} Player;                        // 652 bytes
static_assert(sizeof(struct Zero) == 652);

typedef void (*ZeroFunc)(struct Zero*);

#endif  // GUARD_RMZ3_ENTITY_ZERO_H
