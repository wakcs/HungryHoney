#pragma once
#include "Pickup.h"
class SuitPickup :
	public Pickup
{
public:
	SuitPickup();
	SuitPickup(Texture* itemTexture, Texture* InteractTexture, Vector2f position, int pickupRange, int defencePoints);
	~SuitPickup();

	void Update(PlayerCharacter * player);
	void Draw(RenderWindow &window);

private:
	bool bPickedUp;
	int defencePoints;
};

