#include "motion.h"

#include "entity.h"
#include "gba/gba.h"
#include "global.h"
#include "overworld.h"
#include "story.h"

// clear Motion struct
void ResetMotion(struct Motion *p, const struct MotionCmd *const *const cmds) {
  p->cmds = (const struct MotionCmd **)cmds;  // cmds is overwritten later
  p->step = 0;
  p->cmdIdx = 0;
  p->duration = (*cmds)->frame + 1;
  p->state = MOTION_STATE_0;
}

// step: モーションのstep(剣を振るモーションなら今のstepでは剣を振りかぶったみたいな)
void setMotionStep(struct Motion *p, u8 step) {
  s8 frame;

  p->step = step;
  p->cmdIdx = 0;

  p->duration = p->cmds[step]->frame + 1;

  frame = p->cmds[p->step][1].frame;
  if (frame < 0) {
    if (p->duration == 2) {
      p->state = MOTION_STATE_2;

    } else if (p->duration == 1) {
      if (frame == -1) {
        p->state = MOTION_END;
      } else {
        p->state = MOTION_NEXT;
      }

    } else {
      p->state = MOTION_STATE_1;
    }
    return;
  }

  p->state = MOTION_STATE_0;
}

WIP void UpdateMotionState(struct Motion *m) {
#if MODERN
  u8 p;
  m->duration--;
  if (m->duration == 0) {
    m->cmdIdx++;

    p = m->cmds[m->step][m->cmdIdx].frame;

    // Terminate
    if (p == 0xFF) {
      m->cmdIdx--;
      m->duration = 1;
      m->state = MOTION_END;
      return;
    }

    // Goto
    if (p == 0xFE) {
      m->cmdIdx = m->cmds[m->step][m->cmdIdx].spriteIdx;
      m->state = MOTION_STATE_0;
      p = m->cmds[m->step][m->cmdIdx].frame;
    }

    m->duration = p;

    m->cmdIdx++;
    p = m->cmds[m->step][m->cmdIdx].frame;
    if ((s8)p < 0) {
      switch (m->duration) {
        case 1: {
          m->state = (p == 0xFF) ? MOTION_END : MOTION_NEXT;
          break;
        }
        case 2: {
          m->state = MOTION_STATE_2;
          break;
        }
        default: {
          m->state = MOTION_STATE_1;
          break;
        }
      }
    }
    m->cmdIdx--;
    return;
  }

  if (m->state == MOTION_STATE_0) {
    return;
  }

  if (m->duration == 2) {
    m->state = MOTION_STATE_2;
    return;
  }

  if (m->duration == 1) {
    if (m->cmds[m->step][m->cmdIdx + 1].frame == 0xFF) {
      m->state = MOTION_END;
      return;
    }
    m->state = MOTION_NEXT;
  }
#else
  INCCODE("asm/wip/UpdateMotionState.inc");
#endif
}

// TODO: 後で src/overworld_layer.c に
void ResetLayerGraphic(struct LayerGraphic *l, struct Coord *c, u16 *_, Metatile *tiledata, Screen *screens, const struct ScreenLayout *layout) {
  (l->c).x = c->x;
  (l->c).y = c->y;
  l->tiledata = tiledata;
  l->screens = screens;
  l->map = layout;
  l->bgofs[0] = c->x & 0x1FF;
  l->bgofs[1] = c->y & 0x1FF;
}
