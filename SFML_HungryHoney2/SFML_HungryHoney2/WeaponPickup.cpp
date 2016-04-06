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

void WeaponPickup::Update()
{
	if (!bPickedUp) 
	{
		Pickup::Update();
		if (bInRange) 
		{
			//set weapon texture
			//set damagepoints
			//set attackrange
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
