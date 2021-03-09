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
		damage,
		mana, max_mana,
		stamina, max_stamina,
		x, y, z, a,
		speed;
	Conciliate
		effects[static_cast<Conciliate>(EFFECTS::EFF_SIZE_T)], effects_dur[static_cast<Conciliate>(EFFECTS::EFF_SIZE_T)];
	uConciliate
		level, money;
	Collation
		in_combat;
	World world;
	Weapon hands[2];
	std::vector<Item> Inventory;
	ENTITY_TYPES const GetEType() const {
		return this->type;
	}
public: Entity () {
		this->name = (Display(TEXTS::UNDEF_ENTITY) + "_" + std::to_string(_entity));
		this->ingame_name = Display(TEXTS::UNDEF_ENTITY);
		this->type = ENTITY_TYPES::ENTITY_TYPE_ANIMAL;
		this->money = 0x00000000; this->level = 0x00000001;
		this->damage = this->x = this->y = this->z = this->a = this->mana = this->max_mana = 0.0F;
		this->health = this->max_health = this->stamina = this->max_stamina = 1.0F;
		this->speed = 1.0F;
		this->in_combat = false;
		for (uConciliate index = 0; index < static_cast<Conciliate>(EFFECTS::EFF_SIZE_T); index++) this->effects[index] = this->effects_dur[index] = 0;
		Inventory.clear();
		this->world = DefaultWorld;
		this->hands[0] = this->hands[1] = NONE_SWORD; 
		_entity++;
	}
public: Entity(ENTITY_TYPES type, Ethons name, Ethons ingame_name) : Entity() {
		this->type = type;
		this->name = name;
		this->ingame_name = ingame_name;
	}
};

namespace eti {
	uConciliate e_type(const enum class ENTITY_TYPES type);
	uConciliate e_eff(const enum class EFFECTS effect);
}

namespace Entities {
	namespace Name {
		Ethons Type(const enum class ENTITY_TYPES type);
		Ethons Effect(const enum class EFFECTS effect);
	}
	// entity.h
	Function SetCodeName(struct Entity& e, Ethons new_name);
	Function SetName(struct Entity& e, Ethons new_name);
	Function GetPos(struct Entity& e, float& x, float& y, float& z);
	Function GetAngle(struct Entity& e, float& a);
	Function SetPos(struct Entity& e, float x, float y, float z);
	Function SetAngle(struct Entity& e, float a);
	Function SetMaxHealth(struct Entity& e, float health);
	Function SetHealth(struct Entity& e, float health);
	Function SetMaxMana(struct Entity& e, float mana);
	Function SetMana(struct Entity& e, float mana);
	Function SetStamina(struct Entity& e, float);
	Function Print(struct Entity& e);

	// world.h
	Function World(struct Entity& e, struct World& w);
	Ethons GetWorld(struct Entity& e);

	// item.h
	Function PrintInv(struct Entity& e);
	Function PrintCatInv(struct Entity& e, const enum class ITEM_TYPES type);
	Function AddToInv(struct Entity& e, struct Item& i);
	Function RemoveFromInv(struct Entity& e, struct Item& i);

	// attributes.h

	// effects.h
	Function RemoveEffect(struct Entity& e, const enum class EFFECTS effect);
	Function ApplyEffect(struct Entity& e, const enum class EFFECTS effect, uConciliate per_amount, uConciliate duration = 1);
	Function UpdateEffects(struct Entity& e);
	Function PrintEffects(struct Entity& e);
}


#endif