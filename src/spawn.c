#include "spawn.h"

#include "boss.h"
#include "cyberelf.h"
#include "enemy.h"
#include "entity.h"
#include "gfx.h"
#include "global.h"
#include "overworld.h"
#include "pickup.h"
#include "projectile.h"
#include "solid.h"
#include "story.h"
#include "vfx.h"
#include "zero.h"

// Entity のスポーン管理
// Entity の生成は
//   1. 手動で作成 (例: プレイヤーがダッシュした際には CreateAfterImages が呼ばれて残像が生成される)
//   2. ゲームスクリプト の spawn コマンド (ハンドラ: Cmd_spawn) で生成
//   3. viewport (≒ プレイヤーの座標) が SpawnPoint に 入ったら 自動で生成 (逆に離れたら消す)
// の3通りある
// SpawnManager は このうち 3. の管理をしている

static void ReleaseAllStageEntities(void);
static struct SpawnedEntity* AllocStageEntity(void);
static void ReleaseStageEntity(struct SpawnedEntity* p);
static void FUN_08018848(u8 stageID, u8 area);
static void FUN_08018c00(u8 stageID, u8 area);
static void FUN_08018d10(u8 stageID, u8 area);
static void RemoveZ3EnemyChildEntityForSwapMMBN4Virus(void);
static void RemoveMMBN4Entities(void);

extern const AreaChecker gAreaCheckers[STAGE_COUNT];

// clang-format off

// --------------------------------------------

extern const struct SpawnTemplate gStage0SpawnEntity[];
extern const struct SpawnTemplate gSpaceCraftEntity[26];
extern const struct SpawnTemplate gVolcanoEntity[51];
extern const struct SpawnTemplate gOceanEntity[31];
extern const struct SpawnTemplate gRepairFactoryEntity[38];
extern const struct SpawnTemplate gOldLifeSpaceEntity[37];
extern const struct SpawnTemplate gMissileFactoryEntity[35];
extern const struct SpawnTemplate gTwilightDesertEntity[31];
extern const struct SpawnTemplate gAnatreForestEntity[34];
extern const struct SpawnTemplate gIceBaseEntity[38];
extern const struct SpawnTemplate gAreaX2Entity[36];
extern const struct SpawnTemplate gEnergyFacilityEntity[51];
extern const struct SpawnTemplate gSnowyPlainsEntity[27];
extern const struct SpawnTemplate gSunkenLibraryEntity[37];
extern const struct SpawnTemplate gGiantElevatorEntity[41];
extern const struct SpawnTemplate gSubArcadiaEntity[36];
extern const struct SpawnTemplate gWeilLaboEntity[50];
extern const struct SpawnTemplate gResistanceBaseEntity[64];

static const struct SpawnTemplate* const sStageEntityTemplate[STAGE_COUNT] = {
  [STAGE_NONE]            = (void*)gStage0SpawnEntity,
  [STAGE_SPACE_CRAFT]     = (void*)gSpaceCraftEntity,
  [STAGE_VOLCANO]         = (void*)gVolcanoEntity,
  [STAGE_OCEAN]           = (void*)gOceanEntity,
  [STAGE_REPAIR_FACTORY]  = (void*)gRepairFactoryEntity,
  [STAGE_OLD_RESIDENTIAL] = (void*)gOldLifeSpaceEntity,
  [STAGE_MISSILE_FACTORY] = (void*)gMissileFactoryEntity,
  [STAGE_TWILIGHT_DESERT] = (void*)gTwilightDesertEntity,
  [STAGE_ANATRE_FOREST]   = (void*)gAnatreForestEntity,
  [STAGE_ICE_BASE]        = (void*)gIceBaseEntity,
  [STAGE_AREA_X2]         = (void*)gAreaX2Entity,
  [STAGE_E_FACILITY]      = (void*)gEnergyFacilityEntity,
  [STAGE_SNOWY_PLAINS]    = (void*)gSnowyPlainsEntity,
  [STAGE_SUNKEN_LIBRARY]  = (void*)gSunkenLibraryEntity,
  [STAGE_GIANT_ELEVATOR]  = (void*)gGiantElevatorEntity,
  [STAGE_SUB_ARCADIA]     = (void*)gSubArcadiaEntity,
  [STAGE_WEILS_LABO]      = (void*)gWeilLaboEntity,
  [STAGE_BASE]            = (void*)gResistanceBaseEntity,
};

// --------------------------------------------

extern const struct SpawnPoint gStage0EntityCoord[2];
extern const struct SpawnPoint gSpaceCraftSpawnPoints[68];
extern const struct SpawnPoint gVolcanoSpawnPoints[69];
extern const struct SpawnPoint gOceanEntityCoord[86];
extern const struct SpawnPoint gRepairFactoryEntityCoord[73];
extern const struct SpawnPoint gOldLifeSpaceEntityCoord[159];
extern const struct SpawnPoint gMissileFactoryEntityCoord[82];
extern const struct SpawnPoint gTwilightDesertEntityCoord[59];
extern const struct SpawnPoint gAnatreForestEntityCoord[56];
extern const struct SpawnPoint gIceBaseEntityCoord[107];
extern const struct SpawnPoint gAreaX2EntityCoord[88];
extern const struct SpawnPoint gEnergyFacilityEntityCoord[118];
extern const struct SpawnPoint gSnowyPlainsEntityCoord[78];
extern const struct SpawnPoint gSunkenLibraryEntityCoord[99];
extern const struct SpawnPoint gGiantElevatorEntityCoord[65];
extern const struct SpawnPoint gSubArcadiaEntityCoord[62];
extern const struct SpawnPoint gWeilLaboEntityCoord[68];
extern const struct SpawnPoint gResistanceBaseEntityCoord[241];

static const struct SpawnPoint* const sStageSpawnPointTable[STAGE_COUNT] = {
  [STAGE_NONE]            = gStage0EntityCoord,
  [STAGE_SPACE_CRAFT]     = gSpaceCraftSpawnPoints,
  [STAGE_VOLCANO]         = gVolcanoSpawnPoints,
  [STAGE_OCEAN]           = gOceanEntityCoord,
  [STAGE_REPAIR_FACTORY]  = gRepairFactoryEntityCoord,
  [STAGE_OLD_RESIDENTIAL] = gOldLifeSpaceEntityCoord,
  [STAGE_MISSILE_FACTORY] = gMissileFactoryEntityCoord,
  [STAGE_TWILIGHT_DESERT] = gTwilightDesertEntityCoord,
  [STAGE_ANATRE_FOREST]   = gAnatreForestEntityCoord,
  [STAGE_ICE_BASE]        = gIceBaseEntityCoord,
  [STAGE_AREA_X2]         = gAreaX2EntityCoord,
  [STAGE_E_FACILITY]      = gEnergyFacilityEntityCoord,
  [STAGE_SNOWY_PLAINS]    = gSnowyPlainsEntityCoord,
  [STAGE_SUNKEN_LIBRARY]  = gSunkenLibraryEntityCoord,
  [STAGE_GIANT_ELEVATOR]  = gGiantElevatorEntityCoord,
  [STAGE_SUB_ARCADIA]     = gSubArcadiaEntityCoord,
  [STAGE_WEILS_LABO]      = gWeilLaboEntityCoord,
  [STAGE_BASE]            = gResistanceBaseEntityCoord,
};

// --------------------------------------------

extern const struct PreloadEntity sStage0StaticTemplate[1];
extern const struct PreloadEntity gSpaceCraftStatic[8];
extern const struct PreloadEntity gVolcanoStatic[20];
extern const struct PreloadEntity gOceanStatic[17];
extern const struct PreloadEntity gRepairFactoryStatic[13];
extern const struct PreloadEntity gOldLifeSpaceStatic[15];
extern const struct PreloadEntity gMissileFactoryStatic[14];
extern const struct PreloadEntity gTwilightDesertStatic[13];
extern const struct PreloadEntity gAnatreForestStatic[16];
extern const struct PreloadEntity gIceBaseStatic[18];
extern const struct PreloadEntity gAreaX2Static[13];
extern const struct PreloadEntity gEnergyFacilityStatic[16];
extern const struct PreloadEntity gSnowyPlainsStatic[13];
extern const struct PreloadEntity gSunkenLibraryStatic[12];
extern const struct PreloadEntity gGiantElevatorStatic[19];
extern const struct PreloadEntity gSubArcadiaStatic[14];
extern const struct PreloadEntity gWeilLaboStatic[13];
extern const struct PreloadEntity gResistanceBaseStatic[41];

// 0x083479E4
static const struct PreloadEntity* const sStagePreloadEntities[STAGE_COUNT] = {
  [STAGE_NONE]            = sStage0StaticTemplate,
  [STAGE_SPACE_CRAFT]     = gSpaceCraftStatic,
  [STAGE_VOLCANO]         = gVolcanoStatic,
  [STAGE_OCEAN]           = gOceanStatic,
  [STAGE_REPAIR_FACTORY]  = gRepairFactoryStatic,
  [STAGE_OLD_RESIDENTIAL] = gOldLifeSpaceStatic,
  [STAGE_MISSILE_FACTORY] = gMissileFactoryStatic,
  [STAGE_TWILIGHT_DESERT] = gTwilightDesertStatic,
  [STAGE_ANATRE_FOREST]   = gAnatreForestStatic,
  [STAGE_ICE_BASE]        = gIceBaseStatic,
  [STAGE_AREA_X2]         = gAreaX2Static,
  [STAGE_E_FACILITY]      = gEnergyFacilityStatic,
  [STAGE_SNOWY_PLAINS]    = gSnowyPlainsStatic,
  [STAGE_SUNKEN_LIBRARY]  = gSunkenLibraryStatic,
  [STAGE_GIANT_ELEVATOR]  = gGiantElevatorStatic,
  [STAGE_SUB_ARCADIA]     = gSubArcadiaStatic,
  [STAGE_WEILS_LABO]      = gWeilLaboStatic,
  [STAGE_BASE]            = gResistanceBaseStatic,
};

// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

void InitSpawnManager(u8 stageID, bool8 missionDone) {
  s32 i;
  gSpawnManager.isMissionDone = missionDone;
  gSpawnManager.spawnDisabled = 0;
  gSpawnManager.stageID = stageID;
  gSpawnManager.start = 1;
  gSpawnManager.borderY[0] = -0x7FFFFFFF;
  gSpawnManager.borderY[1] = 0x7FFFFFFF;
  gSpawnManager.area = 0xFF;
  gSpawnManager.enemiesDeleted = FALSE, gSpawnManager.mettaursEnabled = FALSE, gSpawnManager.inCyberSpace = FALSE;
  gSpawnManager.cyberOBPs = 0;
  gSpawnManager.mmbn4EnemiesEnabled = FALSE;
  ReleaseAllStageEntities();
  for (i = 0; i < 33; i++) gSpawnManager.spawnable[i] = -1;
  gSpawnManager.template = sStageEntityTemplate[stageID];
  gSpawnManager.points = sStageSpawnPointTable[stageID];
}

// DEKASUGI!!!
WIP void UpdateSpawnManager(Coords32* viewport) {
#ifdef ALWAYS_FALSE
  s32 mx, my;
  s32 left;
  s32 idx;

  u8 stageID = gSpawnManager.stageID;
  u8 area = gAreaCheckers[stageID](viewport);
  const struct SpawnPoint* points = gSpawnManager.points;

  if ((!FLAG(gCurStory.s.gameflags, IN_CYBERSPACE)) || IS_METTAUR) {
    // サイバー空間から出た or メットール化が有効(MMBN4のウィルスよりこちらの方に優先して置き換えられる)　際に、MMBN4のウィルスを元の敵(or メットール)に戻す
    if (gSpawnManager.inCyberSpace) {
      struct SpawnedEntity* cur;
      gSpawnManager.inCyberSpace = FALSE;
      cur = gSpawnManager.list;
      // MMBN4のウィルスを元の敵に戻す
      while (gSpawnManager.mmbn4EnemiesEnabled) {
        if (cur == NULL) {
          if (gSpawnManager.mmbn4EnemiesEnabled) {
            RemoveMMBN4Entities();
            gSpawnManager.mmbn4EnemiesEnabled = FALSE;
            FUN_08018848(stageID, area);
          }
          break;
        }
        if (cur->e != NULL) {
          if (gSpawnManager.template[points[cur->sid].idx].virusID) {
            if ((cur->e)->mode[0] < ENTITY_DIE) {
              struct Entity* p;
              DeleteStageEntity(cur->e);
              p = CreateStageEntity(gSpawnManager.template[points[cur->sid].idx].kind, gSpawnManager.template[points[cur->sid].idx].id);
              if (p != NULL) {
                p->work[0] = gSpawnManager.template[points[cur->sid].idx].work0;
                p->work[1] = gSpawnManager.template[points[cur->sid].idx].work1;
                if (FLAG(gCurStory.s.gameflags, METTAUR_ENABLED)) {
                  (p->coord).x = (cur->e)->coord.x;
                  (p->coord).y = (cur->e)->coord.y;
                } else {
                  (p->coord).x = (points[cur->sid].x * PIXEL(16)) + PIXEL(8);
                  (p->coord).y = (points[cur->sid].y * PIXEL(16)) + (PIXEL(8) - 1);
                }
                cur->e = p;
              } else {
                ReleaseStageEntity(cur);
              }
            } else {
              DeleteStageEntity((void*)cur->e);
              cur->e = NULL;
            }
          }
        }
      }
    }
  } else if (!gSpawnManager.inCyberSpace) {
    // 雑魚敵を MMBN4のウィルス に置き換える
    struct SpawnedEntity* cur;
    bool32 val;
    gSpawnManager.inCyberSpace = TRUE;
    val = 0;
    if (gSystemSavedata.mmbn4 != 0x32DA) {
      val = gSystemSavedata.mmbn4 != 0;  // val = (-gSystemSavedata.mmbn4 | gSystemSavedata.mmbn4) >> 0x1F;
    }
    gSpawnManager.mmbn4EnemiesEnabled = val;
    if (val) FUN_08018d10(stageID, area);
    cur = gSpawnManager.list;
    while (gSpawnManager.mmbn4EnemiesEnabled) {
      if (cur == NULL) {
        if (gSpawnManager.mmbn4EnemiesEnabled) RemoveZ3EnemyChildEntityForSwapMMBN4Virus();
        break;
      }
      if (cur->e != NULL) {
        if (gSpawnManager.template[points[cur->sid].idx].virusID) {
          if (cur->e->mode[0] < ENTITY_DIE) {
            struct Entity* p;
            DeleteStageEntity((void*)cur->e);
            p = CreateStageEntity(ENTITY_ENEMY, (ENEMY_BEETANK - 1) + gSpawnManager.template[points[cur->sid].idx].virusID);
            if (p != NULL) {
              p->work[0] = 0, p->work[1] = 0;
              (p->coord).x = (cur->e)->coord.x;
              (p->coord).y = (cur->e)->coord.y;
            }
            cur->e = p;
          } else {
            DeleteStageEntity((void*)cur->e);
            cur->e = NULL;
          }
        }
      }
    }
  }

  // キーナイト系 (ステージの雑魚敵を消す)
  if (FLAG(gCurStory.s.gameflags, ARMOR_ELF_ENABLED) && (!gSpawnManager.enemiesDeleted)) {
    gSpawnManager.enemiesDeleted = FALSE;
    // 0x08017eda
    {
      struct SpawnedEntity* p = gSpawnManager.list;
      while (p != NULL) {
        if (p->e != NULL) {
          if (gSpawnManager.template[points[p->sid].idx].attr & SA_KNIGHT) {
            if (p->flag & SF_RESPAWN) SET_FLAG32(gSpawnManager.spawnable, p->sid);
            DeleteStageEntity((void*)p->e);
            ReleaseStageEntity(p);
          }
        }
        p = p->next;
      }
    }
    gSpawnManager.enemiesDeleted = TRUE;
  }

  // メットール化
  if (IS_METTAUR && (!gSpawnManager.mettaursEnabled)) {
    FUN_08018c00(stageID, area);
    // TODO: 0x08017f62
    gSpawnManager.mettaursEnabled = TRUE;
  }

  if (gSpawnManager.area != area) FUN_08018848(stageID, area);

  mx = METACOORD(viewport->x);
  my = METACOORD(viewport->y);

  // (mx - 12)  = viewport->x - 192px が左端
  // gSpawnManager.start を更新する (1フレームで大きくステートが変わることはないため、前回のstartから近いところにいるはず)
  idx = gSpawnManager.start;
  while ((mx - 12) < points[idx].x) idx--;
  while (points[idx].x <= (mx - 12)) idx++;
  gSpawnManager.start = idx;

  // 有効範囲に入った (まだスポーンしていない)Entity をスポーン
  if (!(gSpawnManager.spawnDisabled & 1)) {  // 0x0801807c
    struct SpawnPoint* e;
    while (e = &points[idx], e->x < (mx + 12)) {  // (mx - 12)  = viewport->x + 192px が右端
      if (e->y >= (my - 10) && e->y <= (my + 10)) {
        // 現在、有効範囲にいる
        if (FLAG32(gSpawnManager.spawnable, idx)) {  // まだ生成されていない
          s32 ey = e->y * PIXEL(16);
          bool32 cond1 = (ey >= gSpawnManager.borderY[0]) && (ey <= gSpawnManager.borderY[1]);
          bool32 cond2 = (!gSpawnManager.enemiesDeleted) || (!(gSpawnManager.template[e->idx].attr & SA_KNIGHT));         // キーナイト系(雑魚敵消去エルフ)が無効 or そもそもキーナイト系(雑魚敵消去エルフ)の対象外
          bool32 cond3 = (gSpawnManager.isMissionDone != 1) || (!(gSpawnManager.template[e->idx].attr & SA_STORY_ONLY));  // ストーリー中 or (attr.1 == 0)
          if (cond1 && cond2 && cond3) {
            struct SpawnedEntity* next = AllocStageEntity();
            if (next != NULL) {
              if (gSpawnManager.mettaursEnabled && (gSpawnManager.template[e->idx].mettaurID != 0)) {
                struct Entity* p = CreateStageEntity(ENTITY_ENEMY, ENEMY_METTAUR);
                if (p != NULL) {
                  p->work[0] = gSpawnManager.template[e->idx].mettaurID - 1;
                  p->work[1] = 0;
                  (p->coord).x = e->x * PIXEL(16) + PIXEL(8);
                  (p->coord).y = e->y * PIXEL(16) + PIXEL(8) - 1;
                  next->e = p;
                  next->sid = idx;
                  next->flag = gSpawnManager.template[e->idx].flag;
                  CLEAR_FLAG32(gSpawnManager.spawnable, idx);  // 未生成フラグをクリア
                } else {
                  ReleaseStageEntity(next);
                }
              } else {
                if ((gSpawnManager.mmbn4EnemiesEnabled) && (gSpawnManager.template[e->idx].virusID != 0)) {
                  struct Entity* p = CreateStageEntity(ENTITY_ENEMY, 29 + gSpawnManager.template[e->idx].virusID);
                  if (p != NULL) {
                    p->work[0] = 0, p->work[1] = 0;
                    (p->coord).x = e->x * PIXEL(16) + PIXEL(8);
                    (p->coord).y = e->y * PIXEL(16) + PIXEL(8) - 1;
                    next->e = p;
                    next->sid = idx;
                    next->flag = gSpawnManager.template[e->idx].flag;
                    CLEAR_FLAG32(gSpawnManager.spawnable, idx);  // 未生成フラグをクリア
                  } else {
                    ReleaseStageEntity(next);
                  }
                } else {
                  struct Entity* p = CreateStageEntity(gSpawnManager.template[e->idx].kind, gSpawnManager.template[e->idx].id);
                  if (p != NULL) {
                    p->work[0] = gSpawnManager.template[e->idx].work0;
                    p->work[1] = gSpawnManager.template[e->idx].work1;
                    (p->coord).x = e->x * PIXEL(16) + PIXEL(8);
                    (p->coord).y = e->y * PIXEL(16) + PIXEL(8) - 1;
                    next->e = p;
                    next->sid = idx;
                    next->flag = gSpawnManager.template[e->idx].flag;
                    CLEAR_FLAG32(gSpawnManager.spawnable, idx);  // 未生成フラグをクリア
                  } else {
                    ReleaseStageEntity(next);
                  }
                }
              }
            }
          }
        }
      }
      idx++;
    }

    // 範囲外に出た or もう不要なEntity のカリング
    {
      // 0x0801821a
      struct SpawnedEntity* p = gSpawnManager.list;
      while (p != NULL) {
        if (p->e != NULL) {
          if (p->flag & SF_ZOMBIE) {  // 0x08018254
            if ((p->e)->mode[0] > ENTITY_DIE) p->e = NULL;
            goto _LAB_08018260;
          }
          if ((p->e)->mode[0] <= ENTITY_DIE) {
            if ((p->e)->mode[0] <= ENTITY_UPDATE) {
              // ENTITY_INIT or ENTITY_UPDATE
              if (!(p->flag & (SF_FLAG_3 | SF_NO_CULLING))) {  // 0x080182f0
                s32 deltax = ((p->e)->coord).x - viewport->x;
                bool32 condX = (deltax < -PIXEL(208)) || (deltax >= PIXEL(208));
                s32 deltay = ((p->e)->coord).y - viewport->y;
                bool32 condY = (deltay < -PIXEL(192)) || (deltay >= PIXEL(192));
                if (condX || condY) {
                  if ((p->sid < gSpawnManager.start) || (p->sid >= idx) || ((points[p->sid].y < (my - 10)) || (points[p->sid].y > (my + 10)))) {
                    DeleteStageEntity((void*)p->e);
                    p->flag |= SF_ZOMBIE | SF_RESPAWN;  // カリングの場合は、画面内に入ったらリスポーン
                    p->e = NULL;
                  }
                }
              }
            } else {
              // 0x080182da
              // ENTITY_DIE
              if (p->flag & SF_NO_CULLING) p->flag |= SF_RESPAWN;
              p->flag |= SF_ZOMBIE;
            }
          } else {
            // 0x080182be
            // ENTITY_DISAPPEAR or ENTITY_EXIT
            if (p->flag & SF_NO_CULLING) p->flag |= SF_RESPAWN;
            p->flag |= SF_ZOMBIE;
            p->e = NULL;
          }
        } else {
        _LAB_08018260:
          if ((gSpawnManager.start > p->sid) || (p->sid <= idx) || ((points[p->sid].y >= (my - 10)) && (points[p->sid].y <= (my + 10)))) {
            if (p->flag & SF_RESPAWN) {
              SET_FLAG32(gSpawnManager.spawnable, p->sid);
            }
            ReleaseStageEntity(p);
          }
        }
        p = p->next;
      }
    }
  }
#else
  INCCODE("asm/wip/UpdateSpawnManager.inc");
#endif
}

// Create SpawnedEntity or ScriptEntity
struct Entity* CreateStageEntity(u8 kind, u8 id) {
  struct Entity* p;

  switch (kind) {
    case ENTITY_PLAYER: {
      p = AllocPlayer();
      if (p != NULL) {
        p->renderPrio = 16;
        INIT_PLAYER_ROUTINE((struct Zero*)p, id);
      }
      break;
    }
    case ENTITY_BOSS: {
      p = AllocEntityLast(gBossHeaderPtr);
      if (p != NULL) {
        INIT_BOSS_ROUTINE((struct Boss*)p, id);
      }
      break;
    }
    case ENTITY_ENEMY: {
      p = AllocEntityLast(gEnemyHeaderPtr);
      if (p != NULL) {
        INIT_ENEMY_ROUTINE(p, id);
      }
      break;
    }
    case ENTITY_PROJECTILE: {
      p = AllocEntityLast(gProjectileHeaderPtr);
      if (p != NULL) {
        INIT_PROJECTILE_ROUTINE(p, id);
      }
      break;
    }
    case ENTITY_VFX: {
      p = AllocEntityLast(gVFXHeaderPtr);
      if (p != NULL) {
        INIT_VFX_ROUTINE(p, id);
      }
      break;
    }
    case ENTITY_SOLID: {
      p = AllocEntityFirst(gSolidHeaderPtr);
      if (p != NULL) {
        INIT_SOLID_ROUTINE(p, id);
      }
      break;
    }
    case ENTITY_ITEM: {
      p = AllocEntityLast(gPickupHeaderPtr);
      if (p != NULL) {
        INIT_ITEM_ROUTINE(p, id);
      }
      break;
    }
    case ENTITY_ELF: {
      p = AllocEntityLast(gElfHeaderPtr);
      if (p != NULL) {
        INIT_ELF_ROUTINE(p, id);
      }
      break;
    }
    case ENTITY_WEAPON:
    default: {
      p = NULL;
      break;
    }
  }

  return p;
}

void DeleteStageEntity(struct Entity* p) {
  switch (p->kind) {
    case ENTITY_PLAYER: {
      p->flags &= ~DISPLAY;
      p->flags &= ~FLIPABLE;
      EXIT_BODY(p);
      SET_PLAYER_ROUTINE(p, ENTITY_DISAPPEAR);
      break;
    }
    case ENTITY_WEAPON: {
      break;
    }
    case ENTITY_BOSS: {
      p->flags &= ~DISPLAY;
      p->flags &= ~FLIPABLE;
      EXIT_BODY(p);
      SET_BOSS_ROUTINE(p, ENTITY_DISAPPEAR);
      break;
    }
    case ENTITY_ENEMY: {
      p->flags &= ~DISPLAY;
      p->flags &= ~FLIPABLE;
      EXIT_BODY(p);
      SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
      break;
    }
    case ENTITY_PROJECTILE: {
      p->flags &= ~DISPLAY;
      p->flags &= ~FLIPABLE;
      EXIT_BODY(p);
      SET_PROJECTILE_ROUTINE(p, ENTITY_DISAPPEAR);
      break;
    }
    case ENTITY_VFX: {
      p->flags &= ~DISPLAY;
      p->flags &= ~FLIPABLE;
      SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
      break;
    }
    case ENTITY_SOLID: {
      p->flags &= ~DISPLAY;
      p->flags &= ~FLIPABLE;
      EXIT_BODY(p);
      SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
      break;
    }
    case ENTITY_ITEM: {
      p->flags &= ~DISPLAY;
      p->flags &= ~FLIPABLE;
      EXIT_BODY(p);
      SET_ITEM_ROUTINE(p, ENTITY_DISAPPEAR);
      break;
    }
    case ENTITY_ELF: {
      p->flags &= ~DISPLAY;
      p->flags &= ~FLIPABLE;
      EXIT_BODY(p);
      SET_ELF_ROUTINE(p, ENTITY_DISAPPEAR);
      break;
    }
  }
}

// 0x080186c8
// SpawnManager のY方向の有効範囲を設定する。 範囲外 (y < top || y > bottom) のEntity は (viewport の場所に関係なく) スポーンさせない & 既にスポーンしているEntityは削除する
void ClipSpawnRange(s32 top, s32 bottom) {
  struct SpawnedEntity* p;
  const struct SpawnPoint* c;
  gSpawnManager.borderY[0] = top;
  gSpawnManager.borderY[1] = bottom;
  c = gSpawnManager.points;

  p = gSpawnManager.list;
  while (p != NULL) {
    struct SpawnedEntity* next = p->next;
    struct Entity* e = p->e;

    if (e != NULL && !(p->flag & SF_ZOMBIE)) {
      const s32 y = c[p->sid].y * PIXEL(16);
      if (y < gSpawnManager.borderY[0] || y > gSpawnManager.borderY[1]) {
        if (p->flag & (SF_NO_CULLING | SF_RESPAWN)) {
          SET_FLAG32(gSpawnManager.spawnable, p->sid);
        }
        DeleteStageEntity((void*)e);
        ReleaseStageEntity(p);
      }
    }

    p = next;
  }
}

static void ReleaseAllStageEntities(void) {
  s32 i;
  gSpawnManager.free = NULL;
  for (i = 0; i < 32; i++) {
    gSpawnManager.buffer[i].next = gSpawnManager.free;
    gSpawnManager.free = &gSpawnManager.buffer[i];
  }
  gSpawnManager.list = NULL;
  gSpawnManager.remaining = 32;
}

// SpawnManager.buffer から SpawnedEntity を1つ割り当てる。 (この関数では 対応する Entity は生成されない点に注意)
static struct SpawnedEntity* AllocStageEntity(void) {
  struct SpawnedEntity* newObj;
  struct SpawnedEntity** next;
  if (gSpawnManager.remaining == 0) {
    return NULL;
  }
  gSpawnManager.remaining--;
  newObj = gSpawnManager.free;
  next = &newObj->next;
  gSpawnManager.free = (gSpawnManager.free)->next;
  *next = gSpawnManager.list;
  gSpawnManager.list = newObj;
  return newObj;
}

static void ReleaseStageEntity(struct SpawnedEntity* p) {
  struct SpawnedEntity* p1 = gSpawnManager.list;
  struct SpawnedEntity* p2 = gSpawnManager.list;
  while (p1 != p) {
    p2 = p1;
    p1 = p2->next;
  }

  if (p1 == p2) {
    gSpawnManager.list = p->next;
  } else {
    p2->next = p->next;
  }

  p->next = gSpawnManager.free;
  gSpawnManager.free = p;
  gSpawnManager.remaining++;
}

// MMBN4のウィルスを元の敵に置き換えるとき or ステージエリアが変わったとき に呼ばれる
NON_MATCH static void FUN_08018848(u8 stageID, u8 area) {
#if MODERN
  struct SpawnManager* sman;

  const struct PreloadEntity* preload = sStagePreloadEntities[stageID];
  if (gSpawnManager.area == 0xFF) {
    LOAD_STATIC_GRAPHIC(SM000_BATTLE_EFFECT);
    LOAD_STATIC_GRAPHIC(SM002_LEMON);
    LOAD_STATIC_GRAPHIC(SM003_EMOTION_BUBBLE);
    LOAD_STATIC_GRAPHIC(SM209_NUMBER);
    LOAD_STATIC_GRAPHIC(SM167_LIFE_ENERGY + gSystemSavedata.lifeEnergy);
    LOAD_STATIC_GRAPHIC(SM170_ECRYSTAL + gSystemSavedata.crystal);
    LOAD_STATIC_GRAPHIC(SM173_EXLIFE + gSystemSavedata.extraLife);
    LOAD_STATIC_GRAPHIC(SM176_RESULT_DISK + gSystemSavedata.disk);
    CpuFastFill(0xFFFFFFFF, (void*)&gPaletteManager.buf[(16 + 13) * 16], 32);  // fill OBP13 with white
    gSpawnManager.area = 0xFE;
  }
  sman = &gSpawnManager;
  if (!(sman->spawnDisabled & 1)) {
    if (gSpawnManager.area == 0xFE) {
      while (preload->id != 0xFF) {
        wStaticGraphicTilenums[preload->id] = preload->tileBase;
        wStaticMotionPalIDs[preload->id] = preload->palID;
        preload = &preload[1];
      }
    }
    sman->cyberOBPs = 0;
    preload = sStagePreloadEntities[stageID];  // 先頭を指し直す
    while (preload->id != 0xFF) {
      if (preload->areas & (1 << area)) {
        u32 val, mask;
        if (sman->mettaursEnabled) {
          val = preload->unk_05, mask = (1 << 1);
        } else {
          val = preload->unk_05, mask = (1 << 0);
        }
        if (val & mask) {
          if (sman->mmbn4EnemiesEnabled) {
            val = preload->unk_06, mask = (1 << 1);
          } else {
            val = preload->unk_06, mask = (1 << 0);
          }
          if (val & mask) {
            if (preload->cyberColor) {
              sman->cyberOBPs |= (1 << preload->palID);
            } else {
              sman->cyberOBPs &= ~(1 << preload->palID);
            }
            wStaticGraphicTilenums[preload->id] = preload->tileBase;
            wStaticMotionPalIDs[preload->id] = preload->palID;
            LOAD_STATIC_GRAPHIC(preload->id);
          }
        }
      }
      preload = &preload[1];
    }
    sman->area = area;
  }
#else
  INCCODE("asm/wip/FUN_08018848.inc");
#endif
}

// メットール化 を実行する直前に呼ばれる
NON_MATCH static void FUN_08018c00(u8 stageID, u8 area) {
#if MODERN
  const struct PreloadEntity* preload;

  for (preload = sStagePreloadEntities[stageID]; preload->id != 0xFF; preload = &preload[1]) {
    if (((preload->areas >> area) & 1) && (preload->unk_05 & (1 << 1))) {
      u32 val, mask;
      if (gSpawnManager.mmbn4EnemiesEnabled) {
        val = preload->unk_06;
        mask = (1 << 1);
      } else {
        val = preload->unk_06;
        mask = (1 << 0);
      }
      if (val & mask) {
        if (preload->cyberColor) {
          gSpawnManager.cyberOBPs |= (1 << preload->palID);
        } else {
          gSpawnManager.cyberOBPs &= ~(1 << preload->palID);
        }
        wStaticGraphicTilenums[preload->id] = preload->tileBase;
        wStaticMotionPalIDs[preload->id] = preload->palID;
        LOAD_STATIC_GRAPHIC(preload->id);
      }
    }
  }
#else
  INCCODE("asm/wip/FUN_08018c00.inc");
#endif
}

// MMBN4のウィルス に置き換える直前に呼ばれる
NON_MATCH static void FUN_08018d10(u8 stageID, u8 area) {
#if MODERN
  const struct PreloadEntity* preload;

  for (preload = sStagePreloadEntities[stageID]; preload->id != 0xFF; preload++) {
    if (preload->areas & (1 << area)) {
      if (gSpawnManager.mettaursEnabled) {
        if (!(preload->unk_05 & (1 << 1))) continue;
      } else {
        if (!(preload->unk_05 & (1 << 0))) continue;
      }
      if (preload->unk_06 & (1 << 1)) {
        {
          // inline関数として切り出してもいいかも?
          if (preload->cyberColor) {
            gSpawnManager.cyberOBPs |= (1 << preload->palID);
          } else {
            gSpawnManager.cyberOBPs &= ~(1 << preload->palID);
          }
          wStaticGraphicTilenums[preload->id] = preload->tileBase;
          wStaticMotionPalIDs[preload->id] = preload->palID;
          LOAD_STATIC_GRAPHIC(preload->id);
        }
      }
    }
  }
#else
  INCCODE("asm/wip/FUN_08018d10.inc");
#endif
}

// 敵 を MMBN4のウィルスに置き換える前に、元の敵が生成した 子Entity (例: ジャイロキャノンのプロペラ) などを削除する
// 0x08018e20
// TODO: もっとわかりやすい名前にする
static void RemoveZ3EnemyChildEntityForSwapMMBN4Virus(void) {
  struct Entity* p;
  {
    struct EntityHeader* h = gVFXHeaderPtr;
    p = GetEntityList(h);

    while (p != ((void*)&h->tail)) {
      if ((p->mode[0] < ENTITY_DISAPPEAR) && (p->id == VFX_P_AQUA)) {
        p->flags &= ~DISPLAY;
        p->flags &= ~FLIPABLE;
        SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
      }
      p = GetNextEntity(h);
    }
  }

  {
    struct EntityHeader* h = gProjectileHeaderPtr;
    p = GetEntityList(h);

    while (p != ((void*)&h->tail)) {
      if ((p->mode[0] < ENTITY_DISAPPEAR) && ((p->id >= 1 && p->id <= 3) || (p->id == 6) || (p->id == 8))) {
        p->flags &= ~DISPLAY;
        p->flags &= ~FLIPABLE;
        EXIT_BODY(((Object*)p));
        SET_PROJECTILE_ROUTINE(p, ENTITY_DISAPPEAR);
      }
      p = GetNextEntity(h);
    }
  }

  {
    struct EntityHeader* h = gEnemyHeaderPtr;
    p = GetEntityList(h);

    // 敵によっては1体で複数のEntityを生成する場合があるので、それらを削除
    // 例: ジャイロキャノン は 本体+プロペラ で 2Entity (置き換えるのは本体なので、プロペラは削除)
    while (p != ((void*)&h->tail)) {
      if (p->mode[0] < ENTITY_DISAPPEAR) {
        u32 id;
        if (
            // clang-format off
          (id = p->id, ((id == ENEMY_GYRO_CANNON) || (id == ENEMY_PURPLE_NERPLE)) && ((p->work[0] == 1) || ((id == ENEMY_PURPLE_NERPLE) && (p->work[0] == 2))))
            ||
          ((p->id == ENEMY_GENERATOR_CANNON) && (p->work[0] == 1))
            ||
          (p->id == ENEMY_HEAVY_CANNON_BALL)
            // clang-format on
        ) {
          p->flags &= ~DISPLAY;
          p->flags &= ~FLIPABLE;
          EXIT_BODY(((Object*)p));
          SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
        }
      }
      p = GetNextEntity(h);
    }
  }
}

// 0x08018fa0
static void RemoveMMBN4Entities(void) {
  struct Entity* p;
  {
    struct EntityHeader* h = gVFXHeaderPtr;
    p = GetEntityList(h);

    while (p != ((void*)&h->tail)) {
      if ((p->mode[0] < ENTITY_DISAPPEAR) && (p->id == VFX_UNK_MMBN4_044)) {
        p->flags &= ~DISPLAY;
        p->flags &= ~FLIPABLE;
        SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
      }
      p = GetNextEntity(h);
    }
  }

  {
    struct EntityHeader* h = gProjectileHeaderPtr;
    p = GetEntityList(h);

    while (p != ((void*)&h->tail)) {
      if ((p->mode[0] < ENTITY_DISAPPEAR) && (p->id >= 16 && p->id <= 17)) {
        p->flags &= ~DISPLAY;
        p->flags &= ~FLIPABLE;
        EXIT_BODY(((Object*)p));
        SET_PROJECTILE_ROUTINE(p, ENTITY_DISAPPEAR);
      }
      p = GetNextEntity(h);
    }
  }

  {
    struct EntityHeader* h = gEnemyHeaderPtr;
    p = GetEntityList(h);

    while (p != ((void*)&h->tail)) {
      if ((p->mode[0] < ENTITY_DISAPPEAR) && (p->id >= ENEMY_BEETANK && p->id <= ENEMY_PUFFY)) {
        p->flags &= ~DISPLAY;
        p->flags &= ~FLIPABLE;
        EXIT_BODY(((Object*)p));
        SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
      }
      p = GetNextEntity(h);
    }
  }
}
