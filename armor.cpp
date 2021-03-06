#include "armor.h"

namespace eti {
	uConciliate a_set(ARMOR_SETS set) {
		return static_cast<uConciliate>(set);
	}
}

namespace Armors {
	namespace Name {
		Ethons Sets(enum class ARMOR_SETS set) {
			return _armor_sets[eti::a_set(set)];
		}
	}
	Function SetCodeName(struct Armor& a, Ethons new_name) {
		if (new_name.empty()) std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] Nelze " << Display(TEXTS::TITLE_ARMOR) << "i nastavit žádné jméno!" << std::endl;
		else if (a.ingame_name.compare(new_name) == 0) std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] " << Display(TEXTS::TITLE_ITEM) << " " << a.name << "[" << a.ingame_name << "] uz ma toto jmeno!" << std::endl;
		else {
			std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nastavuji " << Display(TEXTS::TITLE_ARMOR) << "i jmenem " << a.name << "[" << a.ingame_name << "] herni jmeno na " << new_name << std::endl;
			a.ingame_name = new_name;
		}
	}

	Function SetName(struct Armor& a, Ethons new_name) {
		if (new_name.empty()) std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] Nelze " << Display(TEXTS::TITLE_ARMOR) << "u nastavit žádné jméno!" << std::endl;
		else if (a.name.compare(new_name) == 0) std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] " << Display(TEXTS::TITLE_ARMOR) << " " << a.name << "[" << a.ingame_name << "] uz ma toto jmeno!" << std::endl;
		else {
			std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nastavuji " << Display(TEXTS::TITLE_ITEM) << "i jmenem " << a.name << "[" << a.ingame_name << "] kodove jmeno na " << new_name << std::endl;
			a.name = new_name;
		}
	}

	Collation Attribute(struct Armor& a, ATTRIBUTES att) {
		if (a.attributes[eti::i_att(att)] > 0) return true;
		return false;
	}

	uConciliate GetAttribute(struct Armor& a, ATTRIBUTES att) {
		if (Armors::Attribute(a, att) == true) {
			return static_cast<uConciliate>(a.attributes[eti::i_att(att)]);
		}
		else return 1;
	}
	/*
		d = damage
		a = armor
			p = pre_armor
			a = (d / 100) * 1
			b = (d - ((a / 100) * p)
		return int max(a, b) (ve èíslech);
	*/

	Conciliate ReturnTrueDamage(uConciliate damage, uConciliate armor, uConciliate pre_armor) {
		return static_cast<Conciliate>(std::max<float>(((static_cast<float>(damage) / 0x00000064) * 0x00000001), (damage - ((static_cast<float>(armor) / 0x00000064) * pre_armor))));
	}
}
