#ifndef GUARD_RMZ3_CONST_SONG_H
#define GUARD_RMZ3_CONST_SONG_H

#define MUS_DUMMY 0      /* 無音 */
#define SE_CURSOR 1      /* 選択肢とかでカーソル移動時の音 */
#define SE_YES 2         /* 決定音 */
#define SE_NO 3          /* キャンセル音 */
#define SE_NOT_ALLOWED 4 /* エスケープとかできない時になるような禁止を意味するビープ音 */
#define SE_UNK_05 5
#define SE_NOTIFICATION 6 /* EXスキル取得とかの通知音 */
#define SE_WALK 7         /* 歩行音 */
#define SE_DASH_1 8
#define SE_DASH_2 9         /* 壁ずりずりかも？ */
#define SE_ZERO_STUN 10     /* ゼロの被ダメ音 */
#define SE_ZERO_DEATH 11    /* ﾃｨｳﾝﾃｨｳﾝ */
#define SE_WALLJUMP 12      /* 壁蹴り */
#define SE_LADDER 13        /* はしご(歩行音でも使われてる？) */
#define SE_ANALYSIS 14      /* シークレットディスク解析 */
#define SE_WATER_SURFACE 15 /* 着水音？ */
#define SE_SLASH_ROLLING 16
#define SE_SLASH_UP 17 /* 3段切り変化(切り上げ、衝撃波) */
#define SE_REFLECT_LASER 18
#define SE_TENRETSUJIN 19 /* ザンエイダンも ﾃﾞｲﾔｰ */
#define SE_REPPUGEKI 20   /* ﾚｯﾌﾟｳｹﾞｷ  */
#define SE_SABER 21
#define SE_Z_BUSTER 22
#define SE_CHARGE_1 23
#define SE_CHARGE_2 24
#define SE_CHARGE_SAVER_VOICE 25
#define SE_CHARGE_BUSTER 26
#define SE_CHARGE_SHIELD_VOICE 27 /* シールドブーメラン？歯切れが良い */
#define SE_UNK_1c 28              /* シークレットディスク解析音に似ているが高い */
#define SE_CUTSCENE 29            /* リザルト画面でプレイヤーのランク描画時のSE */
#define SE_MISSION_VOICE 30       /* ﾐｯｼｮﾝ! */
#define SE_HP_RECOVER 31
#define SE_SUBTANK_RECOVER 32
#define SE_SUBTANK_FILLED 33 /* サブタンクが満タンになったときのSE */
#define SE_GAIN_ECRYSTAL 34
#define SE_USE_ELF 35
#define SE_GAIN_DISK 36      /* シークレットディスク取得 */
#define SE_TIME_ELF 37       /* ストパーラ系 */
#define SE_TIME_ELF_HURRY 38 /* ストパーラ系が残り時間少なくなった時 */
#define SE_UNK_27 39         /* バーストショット候補1 */
#define SE_ELF_UPGRADE 40    /* エルフを成長させたときの音 */
#define SE_ZAKO_STUN 41      /* 雑魚的にバスター(豆)を当てた時の音 */
#define SE_ZAKO_EXPLODE 42   /* 雑魚敵が爆発する音 */
#define SE_BLOCKED 43        /* ガード判定のあるところとかに攻撃した時の音 */
#define SE_ENEMY_SHOT 44     /* 雑魚敵が豆打ってくる時の音 */
#define SE_ENEMY_BOMB 45     /* プロペラキャノンが爆弾落とす時とか */
#define SE_CAUTION 46
#define SE_LIGHT 47        /* ゼロ4だとトリアフォルマのSE */
#define SE_BOSS_EXPLODE 48 /* ボスが爆発するときの音 */
#define SE_UNK_31 49
#define SE_IN_SEA 50     /* 泡の音がなってた */
#define SE_MENU_SLIDE 51 /* STARTメニューでLR押した時 */
#define SE_RESULT 52     /* リザルト画面で各スコアを表示するときのカシャカシャ音 */
#define SE_UNK_35 53     /* バーストショット候補2 */
#define SE_RECOIL_ROD 54 /* 普通のリコイルロッド攻撃 */
#define SE_CHARGE_RECOIL 55
#define SE_THOUSAND 56            /* サウザンドスラッシュ */
#define SE_COPYX_EXPLODE 57       /* コピーXMk2の爆発音(の前) */
#define SE_ELECTRIC_PANTHEON 58   /* パンテオンガーディアンの攻撃音 */
#define SE_ELECTRIC_SNAKECORD 59  /* スネーケーブルのびりびり音 */
#define SE_ELECTRIC 60            /* 図書館の電気びりびり音 */
#define SE_FLAME 61               /* 炎やられ？ */
#define SE_FREEZE 62              /* ブリザードアローでなる */
#define SE_ICE_BREAK 63           /* ブリザックのつらら攻撃とかが割れる音 */
#define SE_ICE_40 64              /* 氷やられ？ */
#define SE_UNK_41 65              /* 落石？ */
#define SE_BLIZZACK_VOICE 66      /* wooo!! こいつこれしか喋らない */
#define SE_BLIZZACK_BOMB 67       /* ツインフローズンボム */
#define SE_BLIZZACK_BLIZARD 68    /* ブリザード */
#define SE_COPYX_MODE_CHANGE 69   /* コピーXがアーマー装着完了 ゼロ4だとトリアフォルマのSE */
#define SE_COPYX_YA 70            /* ﾔｯ! */
#define SE_COPYX_STUN 71          /* コピーXがひるんだ時の声 */
#define SE_COPYX_FIRESHOT 72      /* 非チャージ */
#define SE_COPYX_ELECSHOT 73      /* 電気バスター 非チャージ */
#define SE_COPYX_RECOVER_VOICE 74 /* ﾓｳﾕﾙｻﾝ! */
#define SE_COPYX_RECOVER 75       /* コピーXの回復音 */
#define SE_COPYX_SLIDING 76       /* スライディング音 */
#define SE_COPYX_EX 77            /* リフレクトレーザー EX技 */
#define SE_HANU_VOICE_1 78        /* ｳｷｯ! */
#define SE_HANU_VOICE_2 79        /* 如意棒伸ばす時 ｳｷｷ! */
#define SE_HANU_VOICE_3 80        /* 突進してくるときの音 ﾑｯｷｰ! */
#define SE_HANU_TAILFIRE_SE 81    /* テイルファイア */
#define SE_HANU_REFLECT 82        /* 突進が反射する時の音 */
#define SE_ANUBIS_MAGIC 83        /* アヌビステップが地形変える時？ */
#define SE_ANUBIS_BOOMERANG 84    /* ステッキのブーメラン */
#define SE_UNK_55 85
#define SE_UNK_56 86
#define SE_SILENCE_57 87 /* 無音になる */
#define SE_UNK_58 88
#define SE_UNK_59 89
#define SE_CIEL_SCREAM 90           /* ｷｬｰ! */
#define SE_DEATHTANZ_KIZANDEYARU 91 /* ｷｻﾞﾝﾃﾞﾔﾙ */
#define SE_DEATHTANZ_JUMP 92        /* ジャンプ時 ﾎｫw */
#define SE_DEATHTANZ_WALL_ATK 93    /* 壁ずり状態からの攻撃 ギロチンドロップ、ダンシングサイズ */
#define SE_DEATHTANZ_BACK_STAB 94   /* ｿｺﾀﾞｯw 後ろ付き */
#define SE_DEATHTANZ_EX 95          /* ﾖｹﾝﾅﾖ! */
#define SE_DEATHTANZ_STUN 96        /* ｷﾞｪw */
#define SE_DEATHTANZ_DEATH 97       /* ﾃﾞｭﾊw */
#define SE_UNK_62 98
#define SE_UNK_63 99
#define SE_UNK_64 100
#define SE_CHILDRE_VOICE_1 101 /* ｯﾊﾊ! */
#define SE_UNK_66 102
#define SE_UNK_67 103
#define SE_CHILDRE_NOROMA 104 /* ﾉﾛﾏ~w */
#define SE_CHILDRE_ORAORA 105 /* ｵﾗｵﾗ~w ミサイル打つ時 */
#define SE_CHILDRE_YAHHH 106  /* ﾔｰ!! */
#define SE_UNK_6b 107
#define SE_CHILDRE_KURAE 108     /* ｸﾗｴｰ! */
#define SE_CHILDRE_STUN 109      /* ｳﾜｯ! */
#define SE_CHILDRE_DEATH 110     /* ﾋｬｱｯ! */
#define SE_BLAZIN_TAIL_FLAME 111 /* ﾌﾝｯ! */
#define SE_BLAZIN_FRILL_BOOM 112 /* ﾇｱｧｯ! フリルブーメラン */
#define SE_UNK_71 113            /* 無音になる */
#define SE_BLAZIN_EX 114         /* ﾓｴﾃｷｴｻﾚ! EX技 */
#define SE_BLAZIN_PREBATTLE 115  /* うらぁっ！ */
#define SE_BLAZIN_STUN 116
#define SE_BLAZIN_DEATH 117
#define SE_UNK_76 118 /* 無音 */
#define SE_UNK_77 119
#define SE_ERUPTION 120          /* 火山の噴火 */
#define SE_VOLTEEL_PREBATTLE 121 /* ｶｸｺﾞｼﾛ! */
#define SE_VOLTEEL_SWIMMING 122  /* ﾋﾋﾋﾋﾋﾋw */
#define SE_VOLTEEL_VOICE_7b 123
#define SE_VOLTEEL_SPARK_CHASER_1 124 /* ﾊｧ?w 穴から出てくる時 */
#define SE_VOLTEEL_ELECTRIC_CAGE 125  /* ｺﾜﾚﾛ-w */
#define SE_VOLTEEL_SPARK_CHASER_2 126 /* ｺｲﾂﾒw */
#define SE_VOLTEEL_EX 127             /* Vレーザー ﾄﾞｳﾀﾞｰw */
#define SE_UNK_80 128
#define SE_VOLTEEL_STUN 129           /* 弱点属性で攻撃された時 */
#define SE_VOLTEEL_DEATH 130          /* ﾇｷﾞｬw */
#define SE_HELLBAT_PREBATTLE 131      /* ﾒｻﾞﾜﾘﾀﾞ! */
#define SE_HELLBAT_DISAPPEAR 132      /* ﾌｯﾌﾌﾌﾌﾌﾌw */
#define SE_HELLBAT_BAT_SHOWER 133     /* ｼﾓﾍﾞﾖ! コウモリ攻撃 */
#define SE_HELLBAT_ECHO_WAVE 134      /* ｼﾌｸﾉﾈﾖ! */
#define SE_HELLBAT_THUNDER_REVERB 135 /* ﾊｯ 床に降りて電撃4連続 */
#define SE_HELLBAT_EX_VOICE 136       /* ﾕﾙｼｦｺｳﾉﾃﾞｽ... */
#define SE_HELLBAT_EX 137             /* EX技の発射音 */
#define SE_HELLBAT_STUN 138           /* 弱点属性で攻撃 */
#define SE_HELLBAT_DEATH 139
#define SE_GLACIERLE_METAL 140        /* 着地時や歩行時になるｶﾞﾝッって音 */
#define SE_GLACIERLE_PREBATTLE 141    /* 砂漠でR */
#define SE_GLACIERLE_HAMMER_PUNCH 142 /* ﾌﾝｯ */
#define SE_UNK_8f 143
#define SE_GLACIERLE_JUMP 144    /* ﾇﾝ! ジャンプ、カクタスプレス */
#define SE_UNK_91 145            /* ブリザックの着地音 */
#define SE_GLACIERLE_ICERAIN 146 /* ﾊﾞﾂｦｳｹﾖ! */
#define SE_UNK_93 147
#define SE_SILENCE_94 148         /* 無音 */
#define SE_GLACIERLE_EX_VOICE 149 /* 死刑であーる */
#define SE_GLACIERLE_EX 150       /* 腕を振り回してる時のSE */
#define SE_GLACIERLE_STUN 151
#define SE_GLACIERLE_DEATH 152
#define SE_TENSOU_VOICE 153 /* ﾃﾝｿｳ! */
#define SE_TENSOU 154       /* レジスタンスベースの転送 */
#define SE_TENSOU_BACK 155  /* 帰還の転送や、他キャラのテレポート */
#define SE_STAGE_DOOR 156   /* ベース内の扉の開く音 */
#define SE_UNK_9d 157       /* ベース内の扉の閉まる音 */
#define SE_UNK_9e 158
#define SE_UNK_9f 159
#define SE_ELEVATOR 160 /* エレベータの移動音 */

#define BGM_GUARDER_ROOM 161     /*  ガーダールーム */
#define BGM_PROLOGUE 162         /* ネオ・アルカディアマーチ */
#define BGM_INTRO_STARSHIP 163   /* 忌まわしき箱舟 */
#define BGM_X 164                /* エックスのテーマ */
#define BGM_OMEGA 165            /* 追放されしもの-オメガ */
#define BGM_WEIL 166             /* 怨讐の科学者 */
#define BGM_ANTAN 167            /* 暗澹 */
#define BGM_OMEGA_MISSILE 168    /* オメガミサイル */
#define BGM_BABY_ELF 169         /* クリエとプリエ */
#define BGM_BREAKOUT 170         /* ブレークアウト */
#define BGM_VOLCANO 171          /* ボルケノ */
#define BGM_WATERCITY 172        /* ウォーター・シティ */
#define BGM_REBORN_FACTORY 173   /* リボーン・メカニクス */
#define BGM_OLD_LIFE_SPACE 174   /* オールド・ライフ・スペース */
#define BGM_FINALCOUNTDOWN 175   /* ファイナルカウントダウン */
#define BGM_ENDLESS_BATTLE3 176  /* 果てしなき戦いへ3 */
#define BGM_FOREST 177           /* サンド・トライアングル2 */
#define BGM_SENNYU 178           /* 潜入2 */
#define BGM_NEOARCADIA3 179      /* ネオアルカディア3 */
#define BGM_ENERGY_FACTORY 180   /* 冷めた微笑 */
#define BGM_SETSUGEN 181         /* パウダートレイル */
#define BGM_LIBRARY 182          /* 水没した図書館 */
#define BGM_HIGHSPEED_LIFT 183   /* ハイスピードリフト */
#define BGM_UNDER_ARCADIA 184    /* ヘイルズゲイト */
#define BGM_LAST_STAGE 185       /* 怨讐の科学者- Stage Version - */
#define BGM_RBASE 186            /* プリズマテック */
#define BGM_OMEGA_BATTLE 187     /* オメガバトル */
#define BGM_BOSS_BATTLE 188      /* スクラップ・ビート */
#define BGM_MIDDLE_BOSS 189      /* クラッシュ3 */
#define BGM_RESULT 190           /* リザルト3 */
#define BGM_TITLE 191            /* タイトル3 */
#define BGM_OMEGA2_BATTLE 192    /* ジャッジメントデイ */
#define BGM_ZERO_RETURN 193      /* ゼロ・リターン */
#define BGM_OMEGAZERO_APPEAR 194 /* 魔神降臨 */
#define BGM_CANNON_BALL 195      /* キャノンボール */
#define BGM_EPILOGUE 196         /* あなたはゼロ */
#define BGM_ENDING 197           /* 紅き伝説 */

#define SE_UNK_c6 198
#define SE_UNK_c7 199 /* カットシーン？ コードネームを描画するときの音 */
#define SE_UNK_c8 200
#define SE_CUBIT_TRANSFORM 201 /* ﾎｰﾎｯﾎｯﾎ! */
#define SE_CUBIT_JUMP 202      /* ﾊｯ! */
#define SE_UNK_cb 203
#define SE_CUBIT_WARP 204         /* ﾐｷﾚﾙ? */
#define SE_CUBIT_ONIBI_CHARGE 205 /* ﾊｧｰ! */
#define SE_CUBIT_ONIBI 206        /* ｲﾔｯ */
#define SE_CUBIT_KAEN_GURUMA 207  /* ｶｴﾝｸﾞﾙﾏ! */
#define SE_CUBIT_FLAME_RAIN 208   /* ﾁﾘﾅｻｲ! */
#define SE_CUBIT_DAMAGE 209
#define SE_CUBIT_DEATH 210
#define SE_TRETISTA_VOICE_d3 211
#define SE_TRETISTA_GRAWL 212          /* ｺﾞﾙﾙｧ! ジャンプ時も */
#define SE_TRETISTA_THROW 213          /* ｺﾞﾌｧ! コンテナ投げ/パイプ投げ */
#define SE_TRETISTA_HELL_BOUNCERS 214  /* ﾔｯﾁﾏｴｨ! */
#define SE_TRETISTA_ASSEMBLE_PUPPY 215 /* 戻ってきた子犬が肩にくっつく音 */
#define SE_TRETISTA_FOLD_PIPE 216      /* パイプへし折る時のボイス */
#define SE_TRETISTA_GAS_VOICE 217      /* ｸﾗｴｨ! */
#define SE_TRETISTA_GAS 218            /* ブレスガスのSE */
#define SE_TRETISTA_LASER_CROW 219     /* ﾁｪｽﾄｰ */
#define SE_TRETISTA_DAMAGE 220
#define SE_TRETISTA_DEATH 221
#define SE_TRETISTA_LANDING 222 /* 垂直ジャンプの着地音 */
#define BGM_DARKELF 223         /* ダークエルフ */
#define SE_UNK_e0 224
#define SE_UNK_e1 225
#define SE_UNK_e2 226
#define SE_PAQUA_MOD_VOICE_e3 227
#define SE_PAQUA_MOD_VOICE_e4 228
#define SE_PAQUA_MOD_VOICE_e5 229
#define SE_PAQUA_MOD_LASER 230 /* スィープレーザー */
#define SE_OMEGA1_GROWL 231    /* オメガ第一形態の唸り声 */
#define SE_OMEGA1_DEATH 232
#define SE_OMEGAZERO_VOICE_e9 233
#define SE_OMEGAZERO_VOICE_ea 234
#define SE_OMEGAZERO_VOICE_eb 235
#define SE_OMEGAZERO_VOICE_ec 236
#define SE_OMEGAZERO_VOICE_ed 237
#define SE_OMEGAZERO_CHARGE_SABER 238 /* ﾄﾞﾘｬｰ! */
#define SE_OMEGAZERO_RYUENJIN 239     /* ﾊｧｯ! */
#define SE_OMEGAZERO_REKKOHA 240      /* ｷｴｻﾚ! */
#define SE_OMEGAZERO_MESSENKOU 241    /* ﾎﾛﾋﾞﾖ! */
#define SE_OMEGAZERO_DAMAGE_f2 242
#define SE_OMEGAZERO_MESHIA 243 /* 我はメシアなり！ハーハッハッハ！ */
#define SE_FEFNIR_DAMAGE 244
#define SE_FEFNIR_ATK 245 /* ｵﾘｬ! */
#define SE_LEVIATHAN_DAMAGE 246
#define SE_LEVIATHAN_ATK 247
#define SE_HARPUIA_DAMAGE 248
#define SE_HARPUIA_ATK 249
#define SE_PHANTOM_START 250    /* 今一度、勝負！ */
#define SE_PHANTOM_ZAN 251      /* 斬！ 闇駆け */
#define SE_PHANTOM_SHURIKEN 252 /* 投！ 螺旋凶車 */
#define SE_PHANTOM_RETSU 253    /* 列！ 朧舞・空蝉 */
#define SE_PHANTOM_UTSUSEMI 254 /* 空蝉！ 刃二重 */
#define SE_PHANTOM_DAMAGE 255
#define SE_PHANTOM_SE 256 /* マキビシ？が地面に当たる音 */
#define SE_UNK_101 257
#define SE_UNK_102 258 /* ヘリコプター？ */
#define SE_UNK_103 259
#define SE_UNK_104 260
#define SE_UNK_105 261 /* 火山の砲弾の弾が地面に落ちる音？ */
#define SE_UNK_106 262
#define SE_SHELL_CRAWLER 263 /* シェルクローラーの弾 */
#define SE_UNK_108 264
#define SE_UNK_109 265
#define SE_UNK_10a 266
#define SE_UNK_10b 267 /* ベルトコンベアみたい */
#define SE_UNK_10c 268
#define SE_UNK_10d 269
#define SE_RBASE_TYPING 270   /* オペレータの出す音 */
#define SE_RBASE_PRE_DOOR 271 /* ドアが開く前の音 */
#define SE_UNK_110 272
#define SE_UNK_111 273 /* ドアが開く？ */
#define SE_UNK_112 274
#define SE_UNK_113 275
#define SE_BABY_ELF_LAUGH 276   /* ｱﾊｯ */
#define SE_BABY_ELF_LAUGH_2 277 /* ｱﾊﾊｯ */
#define SE_BABY_ELF_116 278
#define SE_BABY_ELF_117 279
#define SE_BABY_ELF_118 280
#define SE_BABY_ELF_DEATH 281
#define SE_UNK_11a 282
#define SE_RELEASE_SEAL 283 /* 封印が解かれる音 例:オメガゼロが姿を表す際 */
#define SE_UNK_11c 284
#define SE_UNK_11d 285
#define SE_CAMERA_BEEP 286 /* 監視カメラとかに発見された時の音 */
#define SE_UNK_11f 287
#define SE_UNK_120 288
#define SE_UNK_121 289
#define SE_UNK_122 290
#define SE_SEA_LEVEL 291   /* 海面 */
#define SE_UNK_124 292     /* 電気？ */
#define SE_TENSOU_BEEP 293 /* 転送時のアラート */
#define SE_UNK_126 294
#define SE_UNK_127 295
#define SE_BLAZIN_FIRE_SHOWER 296
#define SE_UNK_129 297
#define SE_ARCADIA_RINGTONE 298 /* ネオアルカディアから通信があったときの音 */
#define SE_UNK_12b 299
#define SE_OMEGA1_LASER 300    /* オメガレーザー 第一形態が3回弾打つやつ */
#define SE_OMEGA1_HOOP 301     /* フープショット */
#define SE_OMEGA1_TELEPORT 302 /* オメガ第一形態の転送音 */
#define SE_UNK_12f 303
#define SE_OMEGA_ZX_BUSTER_1 304 /* エクシードバスター(チャージ) */
#define SE_OMEGA_ZX_131 305
#define SE_OMEGA_ZX_BINDING_BALL 306 /* バインディングボール */
#define SE_OMEGA_ZX_SPARK_CHASER 307 /* スパークチェイサー */
#define SE_OMEGA_ZX_LASER 308        /* トリプルレーザー */
#define SE_OMEGA_ZX_BUSTER_2 309     /* エクシードバスター(発射中) */
#define BGM_EXTRA 310                /* ラボ-システマ・シエル */
#define SE_UNK_137 311
#define SE_UNK_138 312
#define SE_UNK_139 313 /* コンピューター？ */
#define SE_UNK_13a 314
#define SE_OMEGAZERO_DAMAGE_13b 315 /* 0xf2と同じボイス？ */
#define SE_CIEL_ZERO_CALL 316       /* ｾﾞﾛ...ｾﾞﾛ... */
#define SE_ORIGINAL_X_APPEAR 317    /* エックスがホログラムになるときの音 */
#define SE_UNK_13e 318
#define SE_UNK_13f 319
#define SE_ROCK_FALL 320 /* 落石音 */
#define SE_UNK_141 321
#define SE_UNK_142 322
#define SE_UNK_143 323
#define SE_UNK_144 324
#define SE_CLAVEKER_ATK 325 /* 蜘蛛の出す弾SE */
#define SE_GALLISNI_ATK 326 /* ガリスニー(センサーに引っかかると四方からくる奴) */
#define SE_UNK_147 327
#define SE_RBASE_DOOR_OPEN 328
#define SE_RBASE_DOOR_CLOSE 329
#define SE_TELEPORT 330             /* ファントムとかと戦う時に入るテレポーター */
#define BGM_MISSION_INSTRUCTION 331 /* ステージ来た時にオペレータからの指示を受けるときの */
#define SE_UNK_14c 332
#define SE_UNK_14d 333
#define SE_FLOPPER_EXPLODE 334
#define SE_UNK_14f 335

#define MUS_NONE (~0)

#define SONG_COUNT SOUND_UNK_14f + 1

#endif  // GUARD_RMZ3_CONST_SONG_H
