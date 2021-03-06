#include "entity.h"

namespace eti {
	uConciliate e_type(const enum class ENTITY_TYPES type) {
		return static_cast<uConciliate>(type);
	}
}

namespace Entities {
	namespace Name {
		Ethons Type(const enum class ENTITY_TYPES type) {
			return _entity_types[eti::e_type(type)];
		}
	}
	Function SetCodeName(struct Entity& e, Ethons new_name) {
		if (new_name.empty()) std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] Nelze " << Display(TEXTS::TITLE_ENTITY) << "e nastavit žádné jméno!" << std::endl;
		else if (e.name.compare(new_name) == 0) std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] " << Display(TEXTS::TITLE_ENTITY) << " " << e.name << "[" << e.ingame_name << "] uz ma toto jmeno!" << std::endl;
		else {
			std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nastavuji " << Display(TEXTS::TITLE_ENTITY) << "e jmenem " << e.name << "[" << e.ingame_name << "] kodove jmeno na " << new_name << std::endl;
			e.name = new_name;
		}
	}
	Function SetName(struct Entity& e, Ethons new_name) {
		if (new_name.empty()) std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] Nelze " << Display(TEXTS::TITLE_ENTITY) << "e nastavit žádné jméno!" << std::endl;
		else if (e.ingame_name.compare(new_name) == 0) std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] " << Display(TEXTS::TITLE_ENTITY) << " " << e.name << "[" << e.ingame_name << "] uz ma toto jmeno!" << std::endl;
		else {
			std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nastavuji " << Display(TEXTS::TITLE_ENTITY) << "e jmenem " << e.name << "[" << e.ingame_name << "] herni jmeno na " << new_name << std::endl;
			e.ingame_name = new_name;
		}
	}
}
