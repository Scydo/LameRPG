#ifndef  _ITEM
#define _ITEM
#include "attributes.h"

constexpr uConciliate SELLING = (0);
constexpr uConciliate BUYING =  (1);

const enum class ITEM_TYPES : const short {
	ITEM_TYPE_QUEST,
	ITEM_TYPE_JUNK,
	ITEM_TYPE_POTION,
	ITEM_TYPE_FOOD,
	ITEM_TYPE_ARMOR,
	ITEM_TYPE_SHIELD,
	ITEM_TYPE_WEAPON,
	WEAPON_TYPE_ARROW,
	WEAPON_TYPE_BOLT
};

const enum class ITEM_RARITIES : const short {
	RARITY_COMMON,
	RARIRTY_UNCOMMON,
	RARITY_RARE,
	RARITY_MAGIC,
	RARITY_LEGENDARY
};

struct Item {
private:
	ITEM_TYPES type;
public:
	Ethons name;
	Ethons ingame_name;
	ITEM_RARITIES rarity;
	uConciliate price[2], attributes[ATT_MAX];
public:
	ITEM_TYPES const gettype() const { 
		return this->type; 
	}
	Item () {
		this->name = (Display(TEXTS::UNDEF_ITEM) + std::to_string(rand() % 0xFF));
		this->ingame_name = Display(TEXTS::UNDEF_ITEM);
		this->type = ITEM_TYPES::ITEM_TYPE_JUNK;
		this->rarity = ITEM_RARITIES::RARITY_COMMON;
		this->price[BUYING] = this->price[SELLING] = 0;
		for (uConciliate index = 0; index < ATT_MAX; index++) this->attributes[index] = 0;
	}
public:
	Item (Ethons name, Ethons ingame_name, ITEM_TYPES type) : Item() {
		this->name = name;
		this->ingame_name = ingame_name;
		this->type = type;
	}
};

namespace eti {
	uConciliate i_type(ITEM_TYPES type);
	uConciliate i_rarity(ITEM_RARITIES rarity);
	uConciliate i_att(ATTRIBUTES att);
}

namespace Items {
	namespace Name {
		Ethons Type(enum class ITEM_TYPES type);
		Ethons Rarity(enum class ITEM_RARITIES rarity);
		Ethons Attribute(enum class ATTRIBUTES att);
	}
	Function SetName(struct Item& i, std::string new_name);
	Function SetCodeName(struct Item& i, std::string new_name);
	Function SetRarity(struct Item& i, enum class ITEM_RARITIES rarity);
	Function AddAttribute(struct Item& i, enum class ATTRIBUTES att, uConciliate value);
	Collation HasAttribute(struct Item& i, enum class ATTRIBUTES att);
	Function RemoveAttribute(struct Item& i, enum class ATTRIBUTES att);
	Ethons GetName(struct Item& i);
	Ethons GetType(struct Item& i);
	Ethons GetRarity(struct Item& i);
	Function SetPrice(struct Item& i, Conciliate buying, Conciliate selling);
	uConciliate GetBuyingPrice(struct Item& i);
	uConciliate GetSellingPrice(struct Item& i);
	Function Print(struct Item& i);
}

#endif