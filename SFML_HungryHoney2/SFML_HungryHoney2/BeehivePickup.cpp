#include "stdafx.h"
#include "BeehivePickup.h"


BeehivePickup::BeehivePickup()
{
	spawnArea = FloatRect(0, 0, 0, 0);
}

BeehivePickup::BeehivePickup(Texture * itemTexture, Texture * InteractTexture, Vector2f position, int pickupRange, FloatRect spawnArea)
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
		Vector2f newPos = Vector2Extender::RandomVectorCoords(spawnArea);
		cout << "New Pos: " << newPos.x << "," << newPos.y << endl;
		SetPosition(newPos);
	}
}
