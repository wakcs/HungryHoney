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

void SuitPickup::Update()
{
	if (!bPickedUp) 
	{
		Pickup::Update();
		if (bInRange)
		{
			//set suit texture
			//set defence points
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
