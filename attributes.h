#ifndef _ATTRIBUTES
#define _ATTRIBUTES
#include "world.h"

const enum class ATTRIBUTES : const short {
	ATT_PROTECTION,
	ATT_DAMAGE,
	ATT_HEALTH,
	ATT_MANA,
	ATT_REGENERATION_H,
	ATT_REGENERATION_M,
	ATT_BOOST_H,
	ATT_BOOST_M,
	ATT_HEAL,
	ATT_HEAL_MANA,
	ATT_SPEED,
	ATT_CRIT_DMG,
	ATT_CRIT_CHANCE,
	ATT_NONE,
	ATT_SIZE_T
};

constexpr uConciliate ATT_MAX = (static_cast<uConciliate>(ATTRIBUTES::ATT_SIZE_T) - 0x00000002);

#endif

