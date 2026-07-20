#ifndef GUARD_RMZ3_ENTITY_MACROS_H
#define GUARD_RMZ3_ENTITY_MACROS_H

// ここにあるMacroを使わないとコンパイル結果が一致しない (遅いので MODERNオプション では書き方を変えてる)

#if MODERN
#define INIT_ENTITY_ROUTINE(functable, entity, entityID)                                                   \
  {                                                                                                        \
    ((struct Entity*)entity)->id = entityID;                                                               \
    ((struct Entity*)entity)->onUpdate = (void*)((*functable[((struct Entity*)entity)->id])[ENTITY_INIT]); \
  }
#else
#define INIT_ENTITY_ROUTINE(functable, entity, entityID)                       \
  {                                                                            \
    u32 tbl;                                                                   \
    EntityFunc** routine_table;                                                \
    tbl = (u32)functable;                                                      \
    ((struct Entity*)entity)->id = entityID;                                   \
                                                                               \
    routine_table = (EntityFunc**)(tbl + (entityID << 2));                     \
    ((struct Entity*)entity)->onUpdate = (void*)(*routine_table)[ENTITY_INIT]; \
  }
#endif

// Weapon 以外の Entity を生成するときに必ずこの書き方がされているので、マクロとして定義されてる可能性が高い
#define INIT_RENDER_ENTITY(render_prio, functable, entity, entityID)            \
  {                                                                             \
    ((struct Entity*)entity)->renderPrio = (render_prio);                       \
    INIT_ENTITY_ROUTINE(functable, entity, entityID);                           \
    ((struct Entity*)entity)->tileNum = 0, ((struct Entity*)entity)->palID = 0; \
  }

#define INIT_OBJECT_ENTITY(render_prio, functable, entity, entityID)             \
  {                                                                              \
    ((struct Entity*)entity)->renderPrio = (render_prio);                        \
    INIT_ENTITY_ROUTINE(functable, entity, entityID);                            \
    ((struct Entity*)entity)->tileNum = 0, ((struct Entity*)entity)->palID = 0;  \
    ((struct Entity*)entity)->flags2 |= WHITE_PAINTABLE;                         \
    ((struct Entity*)entity)->invincibleID = ((struct Entity*)entity)->uniqueID; \
  }

#if MODERN
#define SET_ENTITY_ROUTINE(functable, entity, modeID)                                                 \
  {                                                                                                   \
    *(u32*)(((struct Entity*)entity)->mode) = modeID;                                                 \
    ((struct Entity*)entity)->onUpdate = (void*)((*functable[((struct Entity*)entity)->id])[modeID]); \
  }
#else
#define SET_ENTITY_ROUTINE(functable, entity, modeID)                     \
  {                                                                       \
    u32 tbl, id;                                                          \
    EntityFunc** routine_table;                                           \
    tbl = (u32)(functable);                                               \
    id = (((struct Entity*)entity)->id) << 2;                             \
    routine_table = (EntityFunc**)(tbl + id);                             \
                                                                          \
    *(u32*)(((struct Entity*)entity)->mode) = modeID;                     \
    ((struct Entity*)entity)->onUpdate = (void*)(*routine_table)[modeID]; \
  }
#endif

#define SET_XFLIP(enti, value)                           \
  {                                                      \
    bool8 __xflip__ = (value);                           \
    if (__xflip__) {                                     \
      ((struct Entity*)enti)->flags |= X_FLIP;           \
    } else {                                             \
      ((struct Entity*)enti)->flags &= ~X_FLIP;          \
    }                                                    \
    (((struct Entity*)enti)->spr).xflip = __xflip__ & 1; \
    (((struct Entity*)enti)->spr).oam.xflip = __xflip__; \
  }

#define SET_YFLIP(enti, value)                           \
  {                                                      \
    bool8 __yflip__ = (value);                           \
    if (__yflip__) {                                     \
      ((struct Entity*)enti)->flags |= Y_FLIP;           \
    } else {                                             \
      ((struct Entity*)enti)->flags &= ~Y_FLIP;          \
    }                                                    \
    (((struct Entity*)enti)->spr).yflip = __yflip__ & 1; \
    (((struct Entity*)enti)->spr).oam.yflip = __yflip__; \
  }

// initGyroCannonMainBody のコードを見るに、マクロはこれが正しいと思われる
#define _INIT_BODY(obj, collisions, hp)                       \
  {                                                           \
    struct Body* body;                                        \
    ((Object*)(obj))->flags |= COLLIDABLE;                    \
    body = &(((Object*)(obj))->body);                         \
    InitBody(body, collisions, &((Object*)(obj))->coord, hp); \
    body->parent = (void*)(obj);                              \
    body->fn = NULL;                                          \
  }

#define SET_BODY_INTERSECT_HANDLER(obj, handler)   \
  {                                                \
    struct Body* body = &(((Object*)(obj))->body); \
    body->fn = handler;                            \
  }

#define INIT_BODY(obj, collisions, hp, onCollision) \
  {                                                 \
    _INIT_BODY(obj, collisions, hp);                \
    SET_BODY_INTERSECT_HANDLER(obj, onCollision);   \
  }

// この書き方が非常によく使われるので、マクロとして定義されてる可能性がありそう
#define EXIT_BODY(enti)                       \
  (((Object*)enti)->body).status = 0;         \
  (((Object*)enti)->body).prevStatus = 0;     \
  (((Object*)enti)->body).invincibleTime = 0; \
  ((Object*)enti)->flags &= ~COLLIDABLE;

#endif  // GUARD_RMZ3_ENTITY_MACROS_H
