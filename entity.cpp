#include "entity.h"

namespace eti {
	uConciliate e_type(const enum class ENTITY_TYPES type) {
		return static_cast<uConciliate>(type);
	}
	uConciliate e_eff(const enum class EFFECTS effect) {
		return static_cast<uConciliate>(effect);
	}
}

namespace Entities {
	namespace Name {
		Ethons Type(const enum class ENTITY_TYPES type) {
			return _entity_types[eti::e_type(type)];
		}
		Ethons Effect(const enum class EFFECTS effect) {
			return _effects[eti::e_eff(effect)];
		}
	}
	// entity.h
	Function SetCodeName(struct Entity& e, Ethons new_name) {
		if (new_name.empty()) std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] Nelze " << Display(TEXTS::TITLE_ENTITY) << "e nastavit žádné jméno!" << std::endl;
		else if (e.name.compare(new_name) == 0) std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] " << Display(TEXTS::TITLE_ENTITY) << " " << e.name << "[" << e.ingame_name << "] uz ma toto jmeno!" << std::endl;
		else {
			std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nastavuji " << Display(TEXTS::TITLE_ENTITY) << "e jmenem " << e.name << "[" << e.ingame_name << "] kodove jmeno na " << new_name << std::endl;
			e.name = new_name;
		}
	}
	// entity.h
	Function SetName(struct Entity& e, Ethons new_name) {
		if (new_name.empty()) std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] Nelze " << Display(TEXTS::TITLE_ENTITY) << "e nastavit žádné jméno!" << std::endl;
		else if (e.ingame_name.compare(new_name) == 0) std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] " << Display(TEXTS::TITLE_ENTITY) << " " << e.name << "[" << e.ingame_name << "] uz ma toto jmeno!" << std::endl;
		else {
			std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nastavuji " << Display(TEXTS::TITLE_ENTITY) << "e jmenem " << e.name << "[" << e.ingame_name << "] herni jmeno na " << new_name << std::endl;
			e.ingame_name = new_name;
		}
	}
	// entity.h
	Function GetPos(struct Entity& e, float& x, float& y, float& z) {
		x = e.x;
		y = e.y;
		z = e.z;
	}
	// entity.h
	Function GetAngle(struct Entity& e, float& a) {
		a = e.a;
	}
	// entity.h
	Function SetPos(struct Entity& e, float x, float y, float z) {
		e.x = x; e.y = y; e.z = z;
		std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nastavuji " << Display(TEXTS::TITLE_ENTITY) << "e jmenem " << e.name << "[" << e.ingame_name << "] pozici na x=" 
			<< x << " y=" << y << " z=" << z << std::endl;
	}
	// entity.h
	Function SetAngle(struct Entity& e, float a) {
		e.a = a;
		std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nastavuji " << Display(TEXTS::TITLE_ENTITY) << "e jmenem " << e.name << "[" << e.ingame_name << "] uhel pohledu na a=" << a << std::endl;
	}
	// entity.h
	Function SetMaxHealth(struct Entity& e, float health) {

	}
	// entity.h
	Function SetHealth(struct Entity& e, float health) {

	}
	// entity.h
	Function SetMaxMana(struct Entity& e, float mana) {

	}
	// entity.h
	Function SetMana(struct Entity& e, float mana) {

	}
	// entity.h
	Function SetStamina(struct Entity& e, float) {

	}
	// entity.h
	Function Print(struct Entity& e) {

	}


	// world.h
	Function World(struct Entity& e, struct World& w) {
		e.world = w;
	}

	// world.h
	Ethons GetWorld(struct Entity& e) {
		return e.world.name;
	}

	// item.h
	Function AddToInv(struct Entity& e, struct Item& i) {
		e.Inventory.push_back(i);
	}
	
	// item.h
	Function RemoveFromInv(struct Entity& e, struct Item& i) {
		auto _itm = std::find_if(e.Inventory.begin(), e.Inventory.end(), [&](const Item& _item) {return i.name == _item.name; });
		if (_itm != e.Inventory.end()) {
			e.Inventory.erase(_itm);
		}
	}
	// item.h
	Function PrintInv(struct Entity& e) {
		for (const auto& index : e.Inventory) {
			std::cout << "<<<<<<<<<>>>>>>>>>>>" << std::endl;
			std::cout << index.ingame_name << "[" << index.name << "] Q: " << Items::Name::Quality(index.quality) << " type=" << Items::Name::Type(index.gettype()) << " price = B:" << index.price[BUYING] << " S:" << index.price[SELLING] << std::endl;
			for (std::size_t j = 0; j < static_cast<uConciliate>(ATTRIBUTES::ATT_SIZE_T); j++) {
				if (index.attributes[j] > 0) {
					std::cout << _item_attribute[j] << " - +" << index.attributes[j] << "%" << std::endl;
				}
			}
			std::cout << "<<<<<<<<<>>>>>>>>>>>" << std::endl;
		}
	}
	// item.h
	Function PrintCatInv(struct Entity& e, const enum class ITEM_TYPES type) {
		for (const auto& index : e.Inventory) {
			if (index.gettype() == type) {
				std::cout << "<<<<<<<<<>>>>>>>>>>>" << std::endl;
				std::cout << index.ingame_name << "[" << index.name << "] Q: " << Items::Name::Quality(index.quality) << " type=" << Items::Name::Type(index.gettype()) << " price = B:" << index.price[BUYING] << " S:" << index.price[SELLING] << std::endl;
				for (std::size_t j = 0; j < static_cast<uConciliate>(ATTRIBUTES::ATT_SIZE_T); j++) {
					if (index.attributes[j] > 0) {
						std::cout << _item_attribute[j] << " - +" << index.attributes[j] << "%" << std::endl;
					}
				}
				std::cout << "<<<<<<<<<>>>>>>>>>>>" << std::endl;
			}
		}
	}
	// effects.h
	Function RemoveEffect(struct Entity& e, const enum class EFFECTS effect) {
		std::cout << "[" << Display(TEXTS::TITLE_EFFECT) << "] Odstranuji " << Display(TEXTS::TITLE_ENTITY) << "e " << _effects[eti::e_eff(effect)] << std::endl;
		e.effects[eti::e_eff(effect)] = e.effects_dur[eti::e_eff(effect)] = 0;
	}

	Function ApplyEffect(struct Entity& e, const enum class EFFECTS effect, uConciliate per_amount, uConciliate duration) {
		if (per_amount < 1 || per_amount > 100) {
			std::cout << "[ " << Display(TEXTS::TITLE_DEBUG) << "] nelze u " << Display(TEXTS::TITLE_EFFECT) << "u per_amount nastavit jinak nez 1-100, nastaveno na 1" << std::endl;
			per_amount = 1;
		}
		if (duration < 1 || duration > 9999) {
			std::cout << "[ " << Display(TEXTS::TITLE_DEBUG) << "] nelze u " << Display(TEXTS::TITLE_EFFECT) << "u duration nastavit jinak nez 1-9999, nastaveno na 10" << std::endl;
			duration = 10;
		}
		e.effects[eti::e_eff(effect)] = per_amount;
		e.effects_dur[eti::e_eff(effect)] = duration;
		switch (effect) {
			// TO DO
		case EFFECTS::EFF_ARMOR: {
			break;
		}
		case EFFECTS::EFF_DEC_ARMOR: {
			break;
		}
		case EFFECTS::EFF_DAMAGE: {
			break;
		}
		case EFFECTS::EFF_DEC_DAMAGE: {
			break;
		}
		case EFFECTS::EFF_REGENERATION_H: {
			break;
		}
		case EFFECTS::EFF_REGENERATION_M: {
			break;
		}
		case EFFECTS::EFF_DEC_REGENERATION_H: {
			break;
		}
		case EFFECTS::EFF_DEC_REGENERATION_M: {
			break;
		}
		case EFFECTS::EFF_BOOST_H: {
			break;
		}
		case EFFECTS::EFF_BOOST_M: {
			break;
		}
		case EFFECTS::EFF_DEC_HEAL: {
			break;
		}
		case EFFECTS::EFF_DEC_HEAL_MANA: {
			break;
		}
		case EFFECTS::EFF_DEC_SPEED: {
			break;
		}
		case EFFECTS::EFF_DEC_CRIT_DMG: {
			break;
		}
		case EFFECTS::EFF_DEC_CRIT_CHANCE: {
			break;
		}
		case EFFECTS::EFF_POISON: {
			break;
		}
		case EFFECTS::EFF_FREEZE: {
			break;
		}
		case EFFECTS::EFF_FIRE: {
			break;
		}
		case EFFECTS::EFF_LIGHTNING: {
			break;
		}
		default: std::cout << "Chyba" << std::endl;
		}
	}

	Function UpdateEffects(struct Entity& e) {
		for (std::size_t index = 0; index < eti::e_eff(EFFECTS::EFF_SIZE_T); index++) {
			if (e.effects_dur[index] > 0) {
				e.effects_dur[index]--;
				if (e.effects_dur[index] == 0) e.effects[index] = 0;
			}
		}
	}

	Function PrintEffects(struct Entity& e) {
		for (std::size_t index = 0; index < eti::e_eff(EFFECTS::EFF_SIZE_T); index++) {
			if (e.effects_dur[index] > 0) {
				std::cout << _effects[index] << " - " << e.effects[index] << "%  >> Doba [" << e.effects_dur[index] << ".0 s]" << std::endl;
			}
		}
	}
}
