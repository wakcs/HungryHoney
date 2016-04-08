#pragma once
#include "Pickup.h"
#include <iostream>
class BeehivePickup :
	public Pickup
{
public:
	BeehivePickup();
	BeehivePickup(Texture* itemTexture, Texture* InteractTexture, Vector2f position, int pickupRange, FloatRect spawnArea);
	~BeehivePickup();

	void Update(PlayerCharacter* player);

private:
	FloatRect spawnArea;
	int iPoints = 10;
};

