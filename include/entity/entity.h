#ifndef GUARD_RMZ3_ENTITY_ENTITY_H
#define GUARD_RMZ3_ENTITY_ENTITY_H

#include "entity/body.h"
#include "entity/sprite.h"
#include "gba/gba.h"
#include "global.h"
#include "metatile.h"
#include "motion.h"

struct ScriptEntity;
struct Zero;

#define ENTITY_HDR                                                                                                                                                                                                     \
  struct Entity* prev;               /* 0x00 */                                                                                                                                                                        \
  struct Entity* next;               /* 0x04 */                                                                                                                                                                        \
  s8 kind;                           /* 0x08, ENTITY_PLAYER or ENTITY_WEAPON, .. */                                                                                                                                    \
  u8 id;                             /* 0x09 */                                                                                                                                                                        \
  u8 flags;                          /* 0x0A, "include/constants/entity.h" 参照 */                                                                                                                                     \
  u8 flags2;                         /* 0x0B, "include/constants/entity.h" 参照 */                                                                                                                                     \
  u8 mode[4];                        /* 0x0C, u32として1つのモードとして扱うときもある (場合によっては次の処理時のmode[0]をmode[3]に格納しておくなど汎用のバッファとしても使われる)*/                                  \
  u8 work[4];                        /* 0x10, general purpose, work[0] と work[1] は Entity の詳細なIDとして使われる(確定?), work[2] は何らかの timer用途　として使われることが多いが、それ以外の用途でも使っている */ \
  void* onUpdate;                    /* 0x14, EntityFunc */                                                                                                                                                            \
  struct ScriptEntity* scriptEntity; /* 0x18  spawnコマンドで生成された Entity が持つ */                                                                                                                               \
  u8 uniqueID;                       /* 0x1C, Entity生成時に割り当てられる、すべてのEntityを区別するためのID */                                                                                                        \
  u8 invincibleID;                   /* 0x1D, 被ダメ時の無敵を表す白塗りをEntityに適用する際にEntityの区別に用いるID */                                                                                                \
  motion_id_t motionID;              /* 0x1E, upper byte for motion_t, gDynamicMotionCmdTable または gStaticMotionCmdTable の idx (Dynamic: 0..162, Static: 0..252) */                                                 \
  u8 texture;                        /* 0x1F, sheet/{texture}.png */                                                                                                                                                   \
  u16 tileNum;                       /* 0x20 */                                                                                                                                                                        \
  u8 palID;                          /* 0x22, これを変えると色が変わる */                                                                                                                                              \
  u8 savedPalID;                     /* 0x23 */                                                                                                                                                                        \
  u8 angle;                          /* 0x24, Entityの回転度合い (描画、AABBで使う) */                                                                                                                                 \
  u8 renderPrio;                     /* 0x25, Renderer priority (0..31), lower is rendered first, so higher is rendered above lower */                                                                                 \
  metatile_attr_t physicsAttr;       /* 0x26, ENTI_PHYSICS のときの attr */

// ここからは Entity によってはこれに従わない使い方をしてるものがあったので分けた (通常のGBAスプライトとして描画するEntityがこのレイアウトと思われる, ほとんどのEntityはこのレイアウト)
#define ENTITY_SPRITE                                                                                                                                               \
  struct Entity* unk_28;   /* 0x28, CreateEmotionBubble では　ここに Coords32 のポインタ　を、 Widget ではここに GameState のポインタ　を入れている */              \
  struct Entity* unk_2c;   /* 0x2C */                                                                                                                               \
  const struct Rect* size; /* 0x30 */                                                                                                                               \
  struct Sprite spr;       /* 0x34 USE_COMMON_OAM_RENDERER が　立っていない Entity は　別の構造体としてこの部分のメモリを使っている */                              \
  Coords32 coord;          /* 0x54, 座標 */                                                                                                                         \
  Coords32 d;              /* 0x5C, 移動速度 (ただし他の用途でも使われることがある, e.g. AfterImage_Init) */                                                        \
  Coords32 unk_coord;      /* 0x64, 何かしらの座標を格納することが多いが、フレームカウンタとして使うことも多い (Coords32 ではなくただの汎用バッファかもしれない) */ \
  AnimState motion;

typedef struct Entity {
  ENTITY_HDR;     // 0x00
  ENTITY_SPRITE;  // 0x28
} Entity;         // 116 bytes
static_assert(sizeof(Entity) == 116);

// Entity + Sprite + Body
#define COLLISION_OBJECT_HDR   \
  ENTITY_HDR;       /* 0x00 */ \
  ENTITY_SPRITE;    /* 0x28 */ \
  struct Body body; /* 0x74 */

typedef struct CollisionObject {
  COLLISION_OBJECT_HDR;  // 0x00
} Object;                // 180 bytes (0xB4..)
static_assert(sizeof(struct CollisionObject) == 180);

// --------------------------------------------

// NOTE:
// buffer のレイアウトが Entity によって違うため、基本的に、各Entityの実装ではこの構造体は使わず各自で定義する(e.g. src/boss/childre.c の Childre)
// buffer を使わないものは普通にここの構造体でいい

// Entity.kind = 0(ENTITY_PLAYER), プレイヤー
// -> include/entity/player.h

// Entity.kind = 1(ENTITY_WEAPON), ゼロの武器
typedef struct Weapon {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 buffer[56];         // 0xB4
} Weapon;                // 236 bytes

// Entity.kind = 2(ENTITY_BOSS), ボス(中ボス含む)
typedef struct Boss {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 buffer[48];         // 0xB4
} Boss;                  // 228 bytes

// Entity.kind = 3(ENTITY_ENEMY)
struct Enemy {
  Entity s;          // 0x00
  struct Body body;  // 0x74
  u8 buffer[16];     // 0xB4
};  // 196 bytes

// Entity.kind = 4(ENTITY_PROJECTILE)
// 敵側の ENTITY_WEAPON に相当?
typedef struct Projectile {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 buffer[16];         // 0xB4
} Projectile;            // 196 bytes

// Entity.kind = 5(ENTITY_VFX), VFX: プレイヤーと干渉しない、グラフィックエフェクト的な存在 (Visual Effect -> VFX)
//   例: ダッシュの残像, パーティクル, ミッションアラート, ハンマー振り子のボールチェーン, エネミーが死んで飛び散った残骸, etc...
//   NOTE: Ghost から VFX にリネームしたけど、まだ変数名や関数名に Ghost が残っているものがある
struct VFX {
  Entity s;       // 0x00
  u8 buffer[16];  // 0x74
};  // 132 bytes

// Entity.kind = 6(ENTITY_SOLID)
struct Solid {
  Entity s;          // 0x00
  struct Body body;  // 0x74
  u8 buffer[16];     // 0xB4
};  // 196 bytes

// Entity.kind = 7(ENTITY_ITEM), アイテム
typedef struct Pickup {
  COLLISION_OBJECT_HDR;  // 0x00
  s32 y;                 // 0xB4
  struct Zero* z;        // 0xB8, ゼロがアイテム拾うとセットされる
  u8 _[8];               // 0xBC, unused?
} Pickup;                // 196 bytes

// Entity.kind = 8(ENTITY_ELF), サイバーエルフ
typedef struct CyberElf {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 buffer[16];         // 0xB4
} CyberElf;              // 196 bytes

// Entity.kind = 9(ENTITY_WIDGET), ウィジェット(メニュー画面のUIパーツ)
struct Widget {
  Entity s;      // 0x00
  u8 props[16];  // 0x74
};  // 132 bytes

// --------------------------------------------

typedef void (*EntityFunc)(Entity*);
typedef void (*ObjectFunc)(Object*);

#endif  // GUARD_RMZ3_ENTITY_ENTITY_H
