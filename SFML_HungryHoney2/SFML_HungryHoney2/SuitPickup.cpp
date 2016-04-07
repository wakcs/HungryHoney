#include "stdafx.h"
#include "SuitPickup.h"


SuitPickup::SuitPickup()
{
	defencePoints = 0;
	bPickedUp = false;
}

SuitPickup::SuitPickup(Texture * itemTexture, Texture * InteractTexture, Vector2f position, int pickupRange, float defencePoints)
	:Pickup(itemTexture,InteractTexture,position,pickupRange)
{
	SuitPickup::defencePoints = defencePoints;
	bPickedUp = false;
}


SuitPickup::~SuitPickup()
{
}

void SuitPickup::Update(PlayerCharacter * player)
{
	if (!bPickedUp) 
	{
		Pickup::Update(player);
		if (bInRange && Keyboard::isKeyPressed(player->GetInteractKey()))
		{
			player->SetSuit(sprtItem);
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
