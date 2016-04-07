#include "stdafx.h"
#include "WeaponPickup.h"


WeaponPickup::WeaponPickup()
{
	bPickedUp = false;
}

WeaponPickup::WeaponPickup(Texture * itemTexture, Texture * InteractTexture, Vector2f position, int pickupRange, float damagePoints, float attackRange)
	:Pickup(itemTexture, InteractTexture, position, pickupRange)
{
	WeaponPickup::damagePoints = damagePoints;
	WeaponPickup::attackRange = attackRange;
	bPickedUp = false;
}


WeaponPickup::~WeaponPickup()
{
}

void WeaponPickup::Update(PlayerCharacter * player)
{
	if (!bPickedUp) 
	{
		Pickup::Update(player);
		if (bInRange && Keyboard::isKeyPressed(player->GetInteractKey())) 
		{
			player->SetWeapon(sprtItem);
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
