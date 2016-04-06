#pragma once
#include "Pickup.h"
class BeehivePickup :
	public Pickup
{
public:
	BeehivePickup();
	BeehivePickup(Texture* itemTexture, Texture* InteractTexture, Vector2f position, int pickupRange, Vector2f spawnArea);
	~BeehivePickup();

	void Update();

private:
	Vector2f spawnArea;
};

