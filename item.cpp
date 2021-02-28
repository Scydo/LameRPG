#include "item.h"

namespace eti {
	uConciliate i_type(enum class ITEM_TYPES type) {
		return static_cast<uConciliate>(type);
	}
	uConciliate i_quality(enum class ITEM_QUALITY quality) {
		return static_cast<uConciliate>(quality);
	}
	uConciliate i_att(enum class ATTRIBUTES att) {
		return static_cast<uConciliate>(att);
	}
}

namespace Items {
	namespace Name {
		Ethons Type(enum class ITEM_TYPES type) {
			return _item_types[eti::i_type(type)];
		}
		Ethons Quality(enum class ITEM_QUALITY quality) {
			return _item_quality[eti::i_quality(quality)];
		}
		Ethons Attribute(enum class ATTRIBUTES att) {
			return _item_attribute[eti::i_att(att)];
		}
	}
	Function SetName(struct Item& i, std::string new_name) {
		if (new_name.empty()) std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] Nelze " << Display(TEXTS::TITLE_ITEM) << "u nastavit žádné jméno!" << std::endl;
		else if (i.ingame_name.compare(new_name) == 0) std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] " << Display(TEXTS::TITLE_ITEM) << " " << i.name << "[" << i.ingame_name << "] uz ma toto jmeno!" << std::endl;
		else {
			std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nastavuji " << Display(TEXTS::TITLE_ITEM) << "u jmenem " << i.name << "[" << i.ingame_name << "] herni jmeno na " << new_name << std::endl;
			i.ingame_name = new_name;
		}
	}

	Function SetCodeName(struct Item& i, std::string new_name) {
		if (new_name.empty()) std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] Nelze " << Display(TEXTS::TITLE_ITEM) << "u nastavit žádné jméno!" << std::endl;
		else if (i.name.compare(new_name) == 0) std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] " << Display(TEXTS::TITLE_ITEM) << " " << i.name << "[" << i.ingame_name << "] uz ma toto jmeno!" << std::endl;
		else {
			std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nastavuji " << Display(TEXTS::TITLE_ITEM) << "u jmenem " << i.name << "[" << i.ingame_name << "] kodove jmeno na " << new_name << std::endl;
			i.name = new_name;
		}
	}

	Function SetQuality(struct Item& i, enum class ITEM_QUALITY quality) {
		std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nastavuji " << Display(TEXTS::TITLE_ITEM) << "u jmenem " << i.name << "[" << i.ingame_name << "] raritu " << Items::Name::Quality(quality) << std::endl;
		i.quality = quality;
	}

	Function AddAttribute(struct Item& i, enum class ATTRIBUTES att, uConciliate value) {
		if (value == 0) {
			value = 1;
			std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nelze " << Display(TEXTS::TITLE_ITEM) << "u priradit attribute s hodnotou 0.\nNastaveno na 1." << std::endl;
		}
		if (value < 1 || value > 100) {
			value = 1;
			std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nelze " << Display(TEXTS::TITLE_ITEM) << "u priradit attribute mimo 1-100.\nNastaveno na 1." << std::endl;
		}
		if (att == ATTRIBUTES::ATT_SIZE_T || att == ATTRIBUTES::ATT_NONE) {
			std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] Nelze " << Display(TEXTS::TITLE_ITEM) << "u priradit tyto attributy." << std::endl;
		}
		else {
			std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nastavuji " << Display(TEXTS::TITLE_ITEM) << "u jmenem " << i.name << "[" << i.ingame_name << "] attribut "
				<< Items::Name::Attribute(att) << " na +" << value << "%" << std::endl;
			i.attributes[eti::i_att(att)] = value;
		}
	}
	Collation HasAttribute(struct Item& i, enum class ATTRIBUTES att) {
		return i.attributes[eti::i_att(att)] > 0 ? true : false;
	}

	Function RemoveAttribute(struct Item& i, enum class ATTRIBUTES att) {
		if (i.attributes[eti::i_att(att)] == 0) std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] " << Display(TEXTS::TITLE_ITEM) << " nema tento attribut " << Items::Name::Attribute(att) << std::endl;
		else {
			i.attributes[eti::i_att(att)] = 0;
			std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Odstranuji " << Display(TEXTS::TITLE_ITEM) << "u jmenem " << i.name << "[" << i.ingame_name << "] attribut "
				<< Items::Name::Attribute(att) << std::endl;
		}
	}

	Ethons GetRarity(struct Item& i) {
		return Items::Name::Quality(i.quality);
	}

	Ethons GetCodeName(struct Item& i) {
		return i.name;
	}

	Ethons GetName(struct Item& i) {
		return i.ingame_name;
	}

	Ethons GetType(struct Item& i) {
		return Items::Name::Type(i.gettype());
	}
	Function SetPrice(struct Item& i, Conciliate buying, Conciliate selling) {
		std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nastavuji " << Display(TEXTS::TITLE_ITEM) << "u jmenem " << i.name << "[" << i.ingame_name << "] kupni/prodejni cenu na: "
			<< buying << "/" << selling << std::endl;
		i.price[BUYING] = buying;
		i.price[SELLING] = selling;
	}

	uConciliate GetBuyingPrice(struct Item& i) {
		return i.price[BUYING];
	}

	uConciliate GetSellingPrice(struct Item& i) {
		return i.price[SELLING];
	}

	Function Print(struct Item& i) {
		std::cout << "-------- " << Display(TEXTS::TITLE_ITEM) << " --------" << std::endl;
		std::cout << "Codename: " << Items::GetCodeName(i) << std::endl;
		std::cout << "Ingame name: " << Items::GetName(i) << std::endl;
		std::cout << Items::Name::Quality(i.quality) << std::endl;
		std::cout << Display(TEXTS::TITLE_TYPE) << ": " << Items::GetType(i) << std::endl;
		std::cout << "Price B:" << Items::GetBuyingPrice(i) << " S:" << Items::GetSellingPrice(i) << std::endl;
		for (std::size_t index = 0; index < ATT_MAX; index++) {
			if (i.attributes[index] > 0) {
				std::cout << _item_attribute[index] << " - +" << i.attributes[index] << " %" << std::endl;
			}
		}
		std::cout << "-------- " << Display(TEXTS::TITLE_ITEM) << " --------" << std::endl;
	}
}