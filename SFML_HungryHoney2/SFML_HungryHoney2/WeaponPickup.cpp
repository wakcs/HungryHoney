#include "stdafx.h"
#include "WeaponPickup.h"


WeaponPickup::WeaponPickup()
{
}

WeaponPickup::WeaponPickup(Texture * itemTexture, Texture * InteractTexture, Vector2f position, int pickupRange, int damagePoints, int attackRange)
	:Pickup(itemTexture, InteractTexture, position, pickupRange)
{
	WeaponPickup::damagePoints = damagePoints;
	WeaponPickup::attackRange = attackRange;
}


WeaponPickup::~WeaponPickup()
{
}

void WeaponPickup::Update(PlayerCharacter * player)
{
	if (!bPickedUp) 
	{
		Pickup::Update(player);
		if (bInRange) 
		{
			player->SetWeaponTexture(sprtItem.getTexture());
			player->SetDamagePoints(damagePoints);
			player->SetAttackRange(attackRange);
			bPickedUp = true;
		}
	}
}

void WeaponPickup::Draw(RenderWindow & window)
{
	if (!bPickedUp) 
	{
		Pickup::Draw(window);
	}
}
