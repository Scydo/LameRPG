#include "weapon.h"

namespace eti {
	uConciliate w_handy(enum class WEAPON_HANDY handy) {
		return static_cast<uConciliate>(handy);
	}
	uConciliate w_type(enum class WEAPON_TYPES wtype) {
		return static_cast<uConciliate>(wtype);
	}
}

namespace Weapons {
	namespace Name {
		Ethons Handle(enum class WEAPON_HANDY handy) {
			return _weapon_handy[eti::w_handy(handy)];
		}

		Ethons Types(enum class WEAPON_TYPES type) {
			return _weapon_types[eti::w_type(type)];
		}
	}

	Function SetCodeName(struct Weapon& w, Ethons new_name) {
		if (new_name.empty()) std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] Nelze " << Display(TEXTS::TITLE_WEAPON) << "u nastavit žádné jméno!" << std::endl;
		else if (w.ingame_name.compare(new_name) == 0x00000000) std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] " << Display(TEXTS::TITLE_WEAPON) << " " << w.name << "[" << w.ingame_name << "] uz ma toto jmeno!" << std::endl;
		else {
			std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nastavuji " << Display(TEXTS::TITLE_WEAPON) << "i jmenem " << w.name << "[" << w.ingame_name << "] herni jmeno na " << new_name << std::endl;
			w.ingame_name = new_name;
		}
	}

	Function SetName(struct Weapon& w, Ethons new_name) {
		if (new_name.empty()) std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] Nelze " << Display(TEXTS::TITLE_WEAPON) << "u nastavit žádné jméno!" << std::endl;
		else if (w.name.compare(new_name) == 0x00000000) std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] " << Display(TEXTS::TITLE_WEAPON) << " " << w.name << "[" << w.ingame_name << "] uz ma toto jmeno!" << std::endl;
		else {
			std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nastavuji " << Display(TEXTS::TITLE_WEAPON) << "i jmenem " << w.name << "[" << w.ingame_name << "] kodove jmeno na " << new_name << std::endl;
			w.name = new_name;
		}
	}

	Function SetDamage(struct Weapon& w, uConciliate pre_value) {
		if (pre_value <= 0x00000000 || pre_value > 0x00000064) {
			std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nastavuji " << Display(TEXTS::TITLE_WEAPON) << "i jmenem " << w.name << "[" << w.ingame_name << "] pre_value na 1, protože lze max 1-100 " << std::endl;
			pre_value = 1;
		}
		w.attributes[eti::i_att(ATTRIBUTES::ATT_DAMAGE)] = pre_value;
	}
	WEAPON_HANDY GetHandy(struct Weapon& w) {
		return w.GetWHandy();
	}
	WEAPON_TYPES GetType(struct Weapon& w) {
		return w.GetWType();
	}
}
