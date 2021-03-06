#ifndef _ARMOR
#define _ARMOR
#include "item.h"

static uConciliate _armors;

const enum class ARMOR_SETS : const short {
	ARMOR_SET_HELMET,
	ARMOR_SET_CHEST,
	ARMOR_SET_ARMS,
	ARMOR_SET_LEGS,
	ARMOR_SET_BOOTS,
	ARMOR_SET_AMULET,
	ARMOR_SET_RING
};

struct Armor : public Item {
private:
	ARMOR_SETS set;
public:
	uConciliate req_level;
	Conciliate pre_armor;
	ARMOR_SETS const getset() const {
		return this->set;
	}
public:
	Armor () : Item () {
		this->name = (Display(TEXTS::UNDEF_ARMOR) + "_" + std::to_string(_armors));
		this->type = ITEM_TYPES::ITEM_TYPE_ARMOR;
		this->ingame_name = Display(TEXTS::UNDEF_ARMOR);
		this->req_level = 1;
		this->set = ARMOR_SETS::ARMOR_SET_HELMET;
		_armors++;
	}
public:
	Armor(Ethons name, Ethons ingame_name, ARMOR_SETS set, uConciliate pre_armor = 0x00000001) : Armor () {
		this->name = name;
		this->ingame_name = ingame_name;
		this->set = set;
		if (pre_armor <= 0) {
			pre_armor = 1;
			this->pre_armor = 1;
		}
		this->attributes[eti::i_att(ATTRIBUTES::ATT_PROTECTION)] = pre_armor;
	}
};

namespace eti {
	uConciliate a_set(enum class ARMOR_SETS set);
}

namespace Armors {
	namespace Name {
		Ethons Sets(enum class ARMOR_SETS set);
	}
	Function SetCodeName(struct Armor& a, Ethons new_name);
	Function SetName(struct Armor& a, Ethons new_name);
	Collation Attribute(struct Armor& a, ATTRIBUTES att);
	uConciliate GetAttribute(struct Armor& a, ATTRIBUTES att);
	Conciliate ReturnTrueDamage(uConciliate damage, uConciliate armor, uConciliate pre_armor);
}

#endif