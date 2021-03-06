#ifndef  _ENTITY
#define _ENTITY
#include "weapon.h"

static uConciliate _entity;

const enum class ENTITY_TYPES : const short {
	ENTITY_TYPE_MONSTER,
	ENTITY_TYPE_ANIMAL,
	ENTITY_TYPE_HUMAN,
	ENTITY_TYPE_GHOST,
	ENTITY_TYPE_UNDEAD
};

struct Entity {
protected:
	ENTITY_TYPES type;
public:
	Ethons name;
	Ethons ingame_name;
	float
		health, max_health,
		mana, max_mana,
		stamina, max_stamina,
		x, y, z, a,
		speed;
	uConciliate
		level, money;
	Collation
		in_combat;
	ENTITY_TYPES const GetEType() const {
		return this->type;
	}
public:
	Entity () {
		this->name = (Display(TEXTS::UNDEF_ENTITY) + "_" + std::to_string(_entity));
		this->ingame_name = Display(TEXTS::UNDEF_ENTITY);
		this->type = ENTITY_TYPES::ENTITY_TYPE_ANIMAL;
		this->money = 0x00000000; this->level = 0x00000001;
		this->x = this->y = this->z = this->a = this->mana = this->max_mana = 0.0F;
		this->health = this->max_health = this->stamina = this->max_stamina = 1.0F;
		this->speed = 1.0F;
		this->in_combat = false;
		_entity++;
	}
public: 
	Entity(ENTITY_TYPES type, Ethons name, Ethons ingame_name) : Entity() {
		this->type = type;
		this->name = name;
		this->ingame_name = ingame_name;
	}
};

namespace eti {
	uConciliate e_type(const enum class ENTITY_TYPES type);
}

namespace Entities {
	namespace Name {
		Ethons Type(const enum class ENTITY_TYPES type);
	}
	Function SetCodeName(struct Entity& e, Ethons new_name);
	Function SetName(struct Entity& e, Ethons new_name);
	Function GetPos(struct Entity& e, float& x, float& y, float& z);
	Function GetAngle(struct Entity& e, float& a);
	Function SetPos(struct Entity& e, float x, float y, float z);
	Function SetAngle(struct Entity& e, float a);
	Function SetHealth(struct Entity& e, float health);
	Function SetMana(struct Entity& e, float mana);
	Function SetStamina(struct Entity& e, float);
}


#endif