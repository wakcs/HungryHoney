#include "stdafx.h"
#include "SuitPickup.h"


SuitPickup::SuitPickup()
{
	defencePoints = 0;
}

SuitPickup::SuitPickup(Texture * itemTexture, Texture * InteractTexture, Vector2f position, int pickupRange, int defencePoints)
	:Pickup(itemTexture,InteractTexture,position,pickupRange)
{
	SuitPickup::defencePoints = defencePoints;
}


SuitPickup::~SuitPickup()
{
}

void SuitPickup::Update(PlayerCharacter * player)
{
	if (!bPickedUp) 
	{
		Pickup::Update(player);
		if (bInRange)
		{
			player->SetSuitTexture(sprtItem.getTexture());
			player->SetDefencePoints(defencePoints);
			bPickedUp = true;
		}
	}
}

void SuitPickup::Draw(RenderWindow & window)
{
	if (!bPickedUp) {
		Pickup::Draw(window);
	}
}
