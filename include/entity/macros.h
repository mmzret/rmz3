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

#define INIT_BODY(p, collisions, hp, onCollision)  \
  {                                                \
    struct Body* body;                             \
    (p->s).flags |= COLLIDABLE;                    \
    body = &p->body;                               \
    InitBody(body, collisions, &(p->s).coord, hp); \
    body->parent = (struct CollidableEntity*)p;    \
    body->fn = onCollision;                        \
  }

#endif  // GUARD_RMZ3_ENTITY_MACROS_H
