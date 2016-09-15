#pragma once
#include "game/state/rules/aequipment_type.h"
#include "library/sp.h"
#include "library/vec.h"

namespace OpenApoc
{

class Agent;
class BattleItem;
// class Projectile;

class AEquipment
{
  public:
	AEquipment();
	~AEquipment() = default;

	StateRef<AEquipmentType> type;

	Vec2<int> equippedPosition;
	StateRef<Agent> ownerAgent;
	wp<BattleItem> ownerItem;
	int ammo = 0;
	
	bool aiming = false;
	int weapon_fire_ticks_remaining = 0;

	void update(int ticks);
	/*
	float getRange() const;
	bool canFire() const;
	void setReloadTime(int ticks);
	// Reload uses up to 'ammoAvailable' to reload the weapon. It returns the amount
	// actually used.
	int reload(int ammoAvailable);
	sp<Projectile> fire(Vec3<float> target);
	*/
};
} // namespace OpenApoc
