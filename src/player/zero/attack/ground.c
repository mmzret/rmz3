#include "global.h"
#include "motion.h"
#include "overworld.h"
#include "sound.h"
#include "weapon.h"
#include "zero.h"

void ZeroAttackGround_Idle(struct Zero* z);
void ZeroAttackGround_Walk(struct Zero* z);
void ZeroAttackGround_Dash(struct Zero* z);

void ZeroAttack_Ground(struct Zero* z) {
  static ZeroFunc const gZeroMode0Actions3[] = {
      ZeroAttackGround_Idle,
      ZeroAttackGround_Walk,
      ZeroAttackGround_Dash,
  };
  (gZeroMode0Actions3[(z->s).mode[2]])(z);
}
