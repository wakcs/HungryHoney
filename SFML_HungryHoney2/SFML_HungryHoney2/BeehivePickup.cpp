#include "stdafx.h"
#include "BeehivePickup.h"


BeehivePickup::BeehivePickup()
{
	spawnArea = Vector2f(0, 0);
}

BeehivePickup::BeehivePickup(Texture * itemTexture, Texture * InteractTexture, Vector2f position, int pickupRange, Vector2f spawnArea)
	: Pickup(itemTexture, InteractTexture, position, pickupRange)
{
	BeehivePickup::spawnArea = spawnArea;
}


BeehivePickup::~BeehivePickup()
{
}

void BeehivePickup::Update()
{
	Pickup::Update();
	if (bInRange) 
	{
		//add points
		//set random position
	}
}
