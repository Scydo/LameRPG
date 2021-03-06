#ifndef  _ITEM
#define _ITEM
#include "effects.h"

constexpr uConciliate SELLING = (0);
constexpr uConciliate BUYING =  (1);

static uConciliate _items;

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

const enum class ITEM_QUALITY : const short {
	QUALITY_COMMON,
	QUALITY_UNCOMMON,
	QUALITY_RARE,
	QUALITY_EPIC,
	QUALITY_MAGIC,
	QUALITY_MASTER,
	QUALITY_LEGENDARY
};

struct Item {
protected:
	ITEM_TYPES type;
public:
	Ethons name;
	Ethons ingame_name;
	ITEM_QUALITY quality;
	uConciliate price[2], attributes[static_cast<uConciliate>(ATTRIBUTES::ATT_SIZE_T)];
public:
	ITEM_TYPES const gettype() const { 
		return this->type; 
	}
	Item () {
		this->name = (Display(TEXTS::UNDEF_ITEM) + "_" + std::to_string(_items));
		this->ingame_name = Display(TEXTS::UNDEF_ITEM);
		this->type = ITEM_TYPES::ITEM_TYPE_JUNK;
		this->quality = ITEM_QUALITY::QUALITY_COMMON;
		this->price[BUYING] = this->price[SELLING] = 0;
		for (uConciliate index = 0; index < ATT_MAX; index++) this->attributes[index] = 0;
		_items++;
	}
public:
	Item (Ethons name, Ethons ingame_name, ITEM_TYPES type) : Item() {
		this->name = name;
		this->ingame_name = ingame_name;
		this->type = type;
	}
};

namespace eti {
	uConciliate i_type(enum class ITEM_TYPES type);
	uConciliate i_quality(enum class ITEM_QUALITY quality);
	uConciliate i_att(enum class ATTRIBUTES att);
}

namespace Items {
	namespace Name {
		Ethons Type(enum class ITEM_TYPES type);
		Ethons Quality(enum class ITEM_QUALITY quality);
		Ethons Attribute(enum class ATTRIBUTES att);
	}
	Function SetName(struct Item& i, std::string new_name);
	Function SetCodeName(struct Item& i, std::string new_name);
	Function SetQuality(struct Item& i, enum class ITEM_QUALITY quality);
	Function AddAttribute(struct Item& i, enum class ATTRIBUTES att, uConciliate value);
	Collation HasAttribute(struct Item& i, enum class ATTRIBUTES att);
	Function RemoveAttribute(struct Item& i, enum class ATTRIBUTES att);
	Ethons GetName(struct Item& i);
	Ethons GetType(struct Item& i);
	Ethons GetQuality(struct Item& i);
	Function SetPrice(struct Item& i, Conciliate buying, Conciliate selling);
	uConciliate GetBuyingPrice(struct Item& i);
	uConciliate GetSellingPrice(struct Item& i);
	Function Print(struct Item& i);
}

#endif