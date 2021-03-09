#ifndef _TEXT
#define _TEXT
#include "main_data.h"
#include "texts.txt"

const enum class TEXTS : const short {
	TITLE_ENTITY,
	TITLE_HUMAN,
	TITLE_PLAYER,
	TITLE_ITEM,
	TITLE_ARMOR,
	TITLE_WEAPON,
	TITLE_DEBUG,
	TITLE_ERROR,
	TITLE_WORLD,
	TITLE_TIME,
	TITLE_WEATHER,
	TITLE_TYPE,
	TITLE_EFFECT,
	UNDEF_ENTITY,
	UNDEF_HUMAN,
	UNDEF_WORLD,
	UNDEF_ITEM,
	UNDEF_ARMOR,
	UNDEF_WEAPON,
	UNDEF_SCROLL,
	UNDEF_POTION,
	UNDEF_QITEM,
	TEXT_SIZE_T
};

Ethons Display(TEXTS textid);

#endif