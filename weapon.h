#include "armor.h"

static uConciliate _weapons;

const enum class WEAPON_HANDY : const short {
	WEAPON_1H, WEAPON_2H, SHIELD_1H
};

const enum class WEAPON_TYPES : const short {
	WEAPON_SWORD,
	WEAPON_AXE,
	WEAPON_HAMMER,
	WEAPON_BOW,
	WEAPON_CROSSBOW,
	WEAPON_SHIELD //protože ho bereme do ruky!
};

struct Weapon : public Item {
protected:
	WEAPON_TYPES wtype;
	WEAPON_HANDY handy;
public:
	WEAPON_TYPES const GetWType() const {
		return this->wtype;
	}
	WEAPON_HANDY const GetWHandy() const {
		return this->handy;
	}
protected:
	Weapon() : Item() {
		this->name = Display(TEXTS::UNDEF_WEAPON) + "_" + std::to_string(_weapons);
		this->ingame_name = Display(TEXTS::UNDEF_WEAPON);
		this->type = ITEM_TYPES::ITEM_TYPE_WEAPON;
		this->wtype = WEAPON_TYPES::WEAPON_SWORD;
		this->handy = WEAPON_HANDY::WEAPON_1H;
		this->attributes[eti::i_att(ATTRIBUTES::ATT_DAMAGE)] = 1;
		_weapons++;
	}
public:
	Weapon (Ethons name, Ethons ingame_name, WEAPON_TYPES wtype, WEAPON_HANDY handy) : Item(name, ingame_name, ITEM_TYPES::ITEM_TYPE_WEAPON) {
		this->wtype = wtype;
		this->handy = handy;
		if (wtype != WEAPON_TYPES::WEAPON_SHIELD) this->attributes[eti::i_att(ATTRIBUTES::ATT_DAMAGE)] = 1;
		else this->attributes[eti::i_att(ATTRIBUTES::ATT_PROTECTION)] = 1;
	}
};

namespace eti {
	uConciliate w_handy(enum class WEAPON_HANDY handy);
	uConciliate w_type(enum class WEAPON_TYPES wtype);
}


namespace Weapons {
	namespace Name {
		Ethons Handle(enum class WEAPON_HANDY handy);
		Ethons Types(enum class WEAPON_TYPES type);
	}
	Function SetCodeName(struct Weapon& w, Ethons new_name);
	Function SetName(struct Weapon& w, Ethons new_name);
	Function SetDamage(struct Weapon& w, uConciliate pre_value);
	WEAPON_HANDY GetHandy(struct Weapon& w);
	WEAPON_TYPES GetType(struct Weapon& w);
}