#pragma once
#include "Pickup.h"
class BeehivePickup :
	public Pickup
{
public:
	BeehivePickup();
	BeehivePickup(Texture* itemTexture, Texture* InteractTexture, Vector2f position, int pickupRange, Vector2i spawnArea);
	~BeehivePickup();

	void Update(PlayerCharacter* player);

private:
	Vector2i spawnArea;
	int iPoints = 10;
};

