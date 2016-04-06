#include "stdafx.h"
#include "BeehivePickup.h"


BeehivePickup::BeehivePickup()
{
	spawnArea = Vector2i(0, 0);
}

BeehivePickup::BeehivePickup(Texture * itemTexture, Texture * InteractTexture, Vector2f position, int pickupRange, Vector2i spawnArea)
	: Pickup(itemTexture, InteractTexture, position, pickupRange)
{
	BeehivePickup::spawnArea = spawnArea;
}


BeehivePickup::~BeehivePickup()
{
}

void BeehivePickup::Update(PlayerCharacter * player)
{
	Pickup::Update(player);
	if (bInRange && Keyboard::isKeyPressed(player->GetInteractKey())) 
	{
		player->AddScore(iPoints);
		Vector2f newPos = Vector2Extender::RandomVectorCoords(spawnArea, false);
		cout << "New Pos: " << newPos.x << "," << newPos.y << endl;
		SetPosition(newPos);
	}
}
